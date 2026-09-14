-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_LZBWDECODER
-- Unit(s) Under Test: UPDi_LzbwDecoder
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: LzbwDecoder_Alloc

-- Test Case: LzbwDecoder_Alloc.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:LzbwDecoder_Alloc
TEST.NEW
TEST.NAME:LzbwDecoder_Alloc.001
TEST.VALUE:UPDi_LzbwDecoder.LzbwDecoder_Alloc.size:1
TEST.EXPECTED:UPDi_LzbwDecoder.LzbwDecoder_Alloc.size:1
TEST.END

-- Test Case: LzbwDecoder_Alloc.002
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:LzbwDecoder_Alloc
TEST.NEW
TEST.NAME:LzbwDecoder_Alloc.002
TEST.VALUE:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.LzbwDecoder_Alloc.size:1
TEST.EXPECTED:UPDi_LzbwDecoder.LzbwDecoder_Alloc.size:1
TEST.END

-- Test Case: LzbwDecoder_Alloc.003
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:LzbwDecoder_Alloc
TEST.NEW
TEST.NAME:LzbwDecoder_Alloc.003
TEST.VALUE:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool[0].Size:30
TEST.VALUE:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool[0].Used:50
TEST.EXPECTED:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool[0].Size:30
TEST.EXPECTED:UPDi_LzbwDecoder.<<GLOBAL>>.pMemoryPool[0].Used:50
TEST.END

-- Subprogram: LzbwDecoder_Free

-- Test Case: LzbwDecoder_Free.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:LzbwDecoder_Free
TEST.NEW
TEST.NAME:LzbwDecoder_Free.001
TEST.VALUE:UPDi_LzbwDecoder.<<GLOBAL>>.u16Used1:1
TEST.EXPECTED:UPDi_LzbwDecoder.<<GLOBAL>>.u16Used1:1
TEST.END

-- Subprogram: UPDiLzbwDecoder_DeSerialize

-- Test Case: UPDiLzbwDecoder_DeSerialize.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_DeSerialize
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_DeSerialize.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_DeSerialize.return:1
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_DeSerialize.return:1
TEST.END

-- Subprogram: UPDiLzbwDecoder_GetDataFormat

-- Test Case: UPDiLzbwDecoder_GetDataFormat.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_GetDataFormat
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_GetDataFormat.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_GetDataFormat.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_GetDataFormat.pDataFormat:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Cmp
TEST.END

-- Subprogram: UPDiLzbwDecoder_Init

-- Test Case: UPDiLzbwDecoder_Init.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_Init
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_Init.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_Init.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_Init.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_Init.This[0].pRam[0].UncompressedSize_HIGH:1
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_Init.This[0].pRam[0].UncompressedSize_HIGH:0
TEST.END

-- Subprogram: UPDiLzbwDecoder_InstallData

-- Test Case: UPDiLzbwDecoder_InstallData.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.return:2
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.002
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.002
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.return:2
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.003
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.003
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwProcessingHeader
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].UncompressedSize:10
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:20
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].UncompressedSize:20
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:20
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.004
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.004
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.005
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.005
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.006
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.006
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwProcessingHeader
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.007
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.007
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwProcessingHeader
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.VALUE:uut_prototype_stubs.LIBLzbwDecode.var_04[0]:10
TEST.VALUE:uut_prototype_stubs.LIBLzbwDecode.return:131072
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwIdle
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.EXPECTED:uut_prototype_stubs.LIBLzbwDecode.var_04[0]:0,10
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.008
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.008
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwProcessingHeader
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.VALUE:uut_prototype_stubs.LIBLzbwDecode.var_04[0]:10
TEST.VALUE:uut_prototype_stubs.LIBLzbwDecode.return:1310
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwIdle
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.pSession[0].PackageSize:2
TEST.EXPECTED:uut_prototype_stubs.LIBLzbwDecode.var_04[0]:0,(100)10
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallData.009
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallData
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallData.009
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwDecompressingData
TEST.VALUE:uut_prototype_stubs.LIBLzbwDecode.return:600
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallData.This[0].pRam[0].State:eLzbwProcessingCompleted
TEST.END

-- Subprogram: UPDiLzbwDecoder_InstallExit

-- Test Case: UPDiLzbwDecoder_InstallExit.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallExit.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwIdle
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwIdle
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallExit.002
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallExit.002
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.return:0
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.return:0
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallExit.003
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallExit.003
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwProcessingCompleted
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwIdle
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallExit.004
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallExit.004
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwProcessingCompleted
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallExit.return:2
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallExit.This[0].pRam[0].State:eLzbwProcessingCompleted
TEST.END

-- Subprogram: UPDiLzbwDecoder_InstallStart

-- Test Case: UPDiLzbwDecoder_InstallStart.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallStart.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:0
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:0
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallStart.002
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallStart.002
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:0
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:0
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallStart.003
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallStart.003
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam[0].State:eLzbwProcessing
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam[0].State:eLzbwProcessing
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallStart.004
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallStart.004
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam[0].State:eLzbwProcessing
TEST.VALUE:uut_prototype_stubs.UPDInstallMan_AllocBuffer.return:1
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam[0].State:eLzbwProcessing
TEST.END

-- Test Case: UPDiLzbwDecoder_InstallStart.005
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_InstallStart.005
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.This[0].pRam:<<malloc 1>>
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:1
TEST.VALUE:uut_prototype_stubs.UPDInstallMan_AllocBuffer.return:1
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_InstallStart.return:1
TEST.END

-- Subprogram: UPDiLzbwDecoder_Serialize

-- Test Case: UPDiLzbwDecoder_Serialize.001
TEST.UNIT:UPDi_LzbwDecoder
TEST.SUBPROGRAM:UPDiLzbwDecoder_Serialize
TEST.NEW
TEST.NAME:UPDiLzbwDecoder_Serialize.001
TEST.VALUE:UPDi_LzbwDecoder.UPDiLzbwDecoder_Serialize.return:1
TEST.EXPECTED:UPDi_LzbwDecoder.UPDiLzbwDecoder_Serialize.return:1
TEST.END
