-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_LZMADECODER
-- Unit(s) Under Test: UPDi_LzmaDecoder
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: LzmaDecoder_Alloc

-- Test Case: LzmaDecoder_Alloc.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:LzmaDecoder_Alloc
TEST.NEW
TEST.NAME:LzmaDecoder_Alloc.001
TEST.VALUE:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.EXPECTED:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.END

-- Test Case: LzmaDecoder_Alloc.002
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:LzmaDecoder_Alloc
TEST.NEW
TEST.NAME:LzmaDecoder_Alloc.002
TEST.VALUE:UPDi_LzmaDecoder.<<GLOBAL>>.pMemoryPool:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.LzmaDecoder_Alloc.p:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.EXPECTED:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.END

-- Test Case: LzmaDecoder_Alloc.003
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:LzmaDecoder_Alloc
TEST.NEW
TEST.NAME:LzmaDecoder_Alloc.003
TEST.VALUE:UPDi_LzmaDecoder.<<GLOBAL>>.pMemoryPool:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.LzmaDecoder_Alloc.p:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.EXPECTED:UPDi_LzmaDecoder.LzmaDecoder_Alloc.size:0
TEST.END

-- Subprogram: LzmaDecoder_Free

-- Test Case: LzmaDecoder_Free.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:LzmaDecoder_Free
TEST.NEW
TEST.NAME:LzmaDecoder_Free.001
TEST.VALUE:UPDi_LzmaDecoder.<<GLOBAL>>.u16Used1:1
TEST.EXPECTED:UPDi_LzmaDecoder.<<GLOBAL>>.u16Used1:1
TEST.END

-- Subprogram: UPDiLzmaDecoder_DeSerialize

-- Test Case: UPDiLzmaDecoder_DeSerialize.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_DeSerialize
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_DeSerialize.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_DeSerialize.return:1
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_DeSerialize.return:1
TEST.END

-- Subprogram: UPDiLzmaDecoder_GetDataFormat

-- Test Case: UPDiLzmaDecoder_GetDataFormat.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_GetDataFormat
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_GetDataFormat.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_GetDataFormat.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_GetDataFormat.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_GetDataFormat.pDataFormat:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_GetDataFormat.return:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_GetDataFormat.return:0
TEST.END

-- Subprogram: UPDiLzmaDecoder_Init

-- Test Case: UPDiLzmaDecoder_Init.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_Init
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_Init.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_Init.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_Init.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_Init.This[0].pRam[0].UncompressedSize:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_Init.This[0].pRam[0].UncompressedSize:0
TEST.END

-- Subprogram: UPDiLzmaDecoder_InstallData

-- Test Case: UPDiLzmaDecoder_InstallData.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.return:2
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.002
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.002
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.return:2
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.003
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.003
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.004
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.004
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:10
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.005
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.005
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:3
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.006
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.006
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaDecompressingData
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.007
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.007
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:3
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.008
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.008
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:3
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize_HIGH:0
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:60
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.009
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.009
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaIdle
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.return:1
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaIdle
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.010
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.010
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaDecompressingData
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:20
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].UncompressedSize:20
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallData.011
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallData.011
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].SizeProcessed:0
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:3
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].State:eLzmaProcessingHeader
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.This[0].pRam[0].SizeProcessed:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallData.Size:3
TEST.END

-- Subprogram: UPDiLzmaDecoder_InstallExit

-- Test Case: UPDiLzmaDecoder_InstallExit.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallExit.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.return:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.return:0
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallExit.002
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallExit.002
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.return:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.return:0
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallExit.003
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallExit.003
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This[0].pRam[0].State:eLzmaProcessingCompleted
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallExit.This[0].pRam[0].State:eLzmaIdle
TEST.END

-- Subprogram: UPDiLzmaDecoder_InstallStart

-- Test Case: UPDiLzmaDecoder_InstallStart.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallStart.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.return:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.return:0
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallStart.002
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallStart.002
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.return:0
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.return:0
TEST.END

-- Test Case: UPDiLzmaDecoder_InstallStart.003
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_InstallStart.003
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This[0].pRam[0].State:eLzmaProcessing
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_InstallStart.This[0].pRam[0].State:eLzmaProcessing
TEST.END

-- Subprogram: UPDiLzmaDecoder_Serialize

-- Test Case: UPDiLzmaDecoder_Serialize.001
TEST.UNIT:UPDi_LzmaDecoder
TEST.SUBPROGRAM:UPDiLzmaDecoder_Serialize
TEST.NEW
TEST.NAME:UPDiLzmaDecoder_Serialize.001
TEST.VALUE:UPDi_LzmaDecoder.UPDiLzmaDecoder_Serialize.return:1
TEST.EXPECTED:UPDi_LzmaDecoder.UPDiLzmaDecoder_Serialize.return:1
TEST.END
