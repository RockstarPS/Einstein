-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SAFENVM_VCAST_UT
-- Unit(s) Under Test: SafeNvM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: SafeNvM

-- Subprogram: SafeNvM_Init

-- Test Case: SafeNvM_Init.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.END

-- Test Case: SafeNvM_Init.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:<<null>>
TEST.END

-- Test Case: SafeNvM_Init.003
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.END

-- Test Case: SafeNvM_Init.004
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:<<null>>
TEST.END

-- Test Case: SafeNvM_Init.005
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_STR1
TEST.END

-- Test Case: SafeNvM_Init.006
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr[0]:0
TEST.END

-- Test Case: SafeNvM_Init.007
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT2
TEST.END

-- Test Case: SafeNvM_Init.008
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:<<null>>
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:<<null>>
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.SafeNvM_Det_ReportError.ApiId:5
TEST.VALUE:uut_prototype_stubs.SafeNvM_Det_ReportError.ErrorId:6
TEST.EXPECTED:uut_prototype_stubs.SafeNvM_Det_ReportError.ApiId:1
TEST.EXPECTED:uut_prototype_stubs.SafeNvM_Det_ReportError.ErrorId:2
TEST.END

-- Test Case: SafeNvM_Init.009
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT2
TEST.END

-- Test Case: SafeNvM_Init.010
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_Init
TEST.NEW
TEST.NAME:SafeNvM_Init.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:5
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:6
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:7
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr:<<malloc 1>>
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:0
TEST.END

-- Subprogram: SafeNvM_MainFunction

-- Test Case: SafeNvM_MainFunction.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_MainFunction
TEST.NEW
TEST.NAME:SafeNvM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.END

-- Test Case: SafeNvM_MainFunction.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_MainFunction
TEST.NEW
TEST.NAME:SafeNvM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:2
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:2
TEST.END

-- Test Case: SafeNvM_MainFunction.003
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_MainFunction
TEST.NEW
TEST.NAME:SafeNvM_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.END

-- Subprogram: SafeNvM_NvM_WriteCallback_Copy1

-- Test Case: SafeNvM_NvM_WriteCallback_Copy1.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy1
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy1.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:0
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:0
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Copy1.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy1
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy1.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.buffer1[1]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.SafeBlockIndex:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Original:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Copy1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Copy2:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Copy1.003
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy1
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy1.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:7
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:7
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Copy1.004
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy1
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy1.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.JobResult:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Copy1.005
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy1
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy1.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.JobResult:2
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy1.JobResult:2
TEST.END

-- Subprogram: SafeNvM_NvM_WriteCallback_Copy2

-- Test Case: BASIS-PATH-001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ServiceId == 7U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:<<MIN>>
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:<<MIN>>
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.JobResult:<<MIN>>
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:0
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy2
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ServiceId == 7U) ==> TRUE
      (2) if (0U == JobResult) ==> FALSE
      (3) if (0x2U != JobResult) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:<<MIN>>
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.JobResult:2
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:0
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy2
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ServiceId == 7U) ==> TRUE
      (2) if (0U == JobResult) ==> FALSE
      (3) if (0x2U != JobResult) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest1:0
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr:<<malloc 1>>
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr[0]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_BUFFER
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].AsilCopyPtr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_MemAbstract_JobEnd_Notify:MemAbstractMdl_NotifyJobEnd_BsConst_Illumination
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:0
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.JobResult:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest1:1
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:0
TEST.END

-- Test Case: BASIS-PATH-002.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy2
TEST.NEW
TEST.NAME:BASIS-PATH-002.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ServiceId == 7U) ==> TRUE
      (2) if (0U == JobResult) ==> FALSE
      (3) if (0x2U != JobResult) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest1:0
TEST.VALUE:SafeNvM.<<GLOBAL>>.SafeNvM_Write_Success_Count:2
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Original:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Copy1:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockId_Copy2:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr:<<malloc 1>>
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].DefaultRomPtr[0]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_MemAbstract_JobEnd_Notify:MemAbstractMdl_NotifyJobEnd_BsConst_Illumination
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:<<MIN>>
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.JobResult:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest1:1
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.SafeBlockIndex:0
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Copy2.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Copy2
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Copy2.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.SafeNvM_Write_Success_Count:0
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:0
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Copy2.ServiceId:0
TEST.END

-- Subprogram: SafeNvM_NvM_WriteCallback_Original

-- Test Case: SafeNvM_NvM_WriteCallback_Original.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Original
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Original.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:0
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Original.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Original
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Original.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Original.003
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Original
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Original.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Original.ServiceId:7
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Original.ServiceId:7
TEST.END

-- Test Case: SafeNvM_NvM_WriteCallback_Original.004
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_NvM_WriteCallback_Original
TEST.NEW
TEST.NAME:SafeNvM_NvM_WriteCallback_Original.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Original.ServiceId:7
TEST.VALUE:SafeNvM.SafeNvM_NvM_WriteCallback_Original.JobResult:2
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Original.ServiceId:7
TEST.EXPECTED:SafeNvM.SafeNvM_NvM_WriteCallback_Original.JobResult:2
TEST.END

-- Subprogram: SafeNvM_SetWriteBlockReq

-- Test Case: SafeNvM_SetWriteBlockReq.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_SetWriteBlockReq
TEST.NEW
TEST.NAME:SafeNvM_SetWriteBlockReq.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.EXPECTED:SafeNvM.SafeNvM_SetWriteBlockReq.SafeBlockIndex:0
TEST.END

-- Test Case: SafeNvM_SetWriteBlockReq.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_SetWriteBlockReq
TEST.NEW
TEST.NAME:SafeNvM_SetWriteBlockReq.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.SafeNvM_SetWriteBlockReq.SafeBlockIndex:2
TEST.EXPECTED:SafeNvM.SafeNvM_SetWriteBlockReq.SafeBlockIndex:2
TEST.END

-- Subprogram: SafeNvM_TriggerDataCompare

-- Test Case: SafeNvM_TriggerDataCompare.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.002
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.003
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMDataCompare:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMDataCompare:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.004
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.005
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.006
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:2
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:<<null>>
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.007
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].AsilCopyPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.008
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].AsilCopyPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.009
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].AsilCopyPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.010
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:1
TEST.END

-- Test Case: SafeNvM_TriggerDataCompare.011
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvM_TriggerDataCompare
TEST.NEW
TEST.NAME:SafeNvM_TriggerDataCompare.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.nvmtest:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvM_BlockSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_OriginalPtr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy1Ptr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].NvmRamMirrorBuf_Copy2Ptr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].AsilCopyPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.NvMSafe_Blockconfig[0].SafeNvM_Write_Asil_ElementsPtr:SafeNvM_AsilRam_CopyTo_RteSafeRam
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.nvmtest:1
TEST.END

-- Subprogram: SafeNvmWriteData

-- Test Case: SafeNvmWriteData.001
TEST.UNIT:SafeNvM
TEST.SUBPROGRAM:SafeNvmWriteData
TEST.NEW
TEST.NAME:SafeNvmWriteData.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::SafeNvM::SafeNvM_Detailed_Design::SafeNvM_Class_Diagram
Requirement_PE4TI29141-9024
TEST.END_NOTES:
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:1
TEST.VALUE:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.VALUE:SafeNvM.SafeNvmWriteData.SafeBlkIndex:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteBlkReq:0
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteInProgress:1
TEST.EXPECTED:SafeNvM.<<GLOBAL>>.NvMSafe_Internal[0].lNvMWriteChain:1
TEST.EXPECTED:SafeNvM.SafeNvmWriteData.SafeBlkIndex:0
TEST.END
