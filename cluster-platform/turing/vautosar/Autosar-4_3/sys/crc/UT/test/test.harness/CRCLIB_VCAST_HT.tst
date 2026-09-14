-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CRCLIB_VCAST_HT
-- Unit(s) Under Test: Crc
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Crc

-- Subprogram: Crc_CalculateCRC16

-- Test Case: Crc_CalculateCRC16_IsFirstCallFasle
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC16
TEST.NEW
TEST.NAME:Crc_CalculateCRC16_IsFirstCallFasle
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr[0]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_Length:1
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_StartValue16:0xBE4B
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_IsFirstCall:FALSE
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC16.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC16.Crc_DataPtr[2]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC16_IsFirstCallFasle_NullPtr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC16
TEST.NEW
TEST.NAME:Crc_CalculateCRC16_IsFirstCallFasle_NullPtr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr:<<malloc 9>>
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr:<<null>>
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_Length:1
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_StartValue16:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC16.return:0xC2
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC16.Crc_DataPtr[0]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC16.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC16.Crc_DataPtr[2]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC16_ValidInput
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC16
TEST.NEW
TEST.NAME:Crc_CalculateCRC16_ValidInput
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr:<<malloc 3>>
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr[0]:0x92
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr[1]:0x6B
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_DataPtr[2]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_Length:3
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_StartValue16:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC16.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC16.return:0x745
TEST.END

-- Subprogram: Crc_CalculateCRC32

-- Test Case: Crc_CalculateCRC32_IsFirstCallFasle
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32
TEST.NEW
TEST.NAME:Crc_CalculateCRC32_IsFirstCallFasle
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr:<<malloc 3>>
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[0]:0x92
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[1]:0x6B
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[2]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_Length:3
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_StartValue32:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC32.return:0x9CDEA29B
TEST.END

-- Test Case: Crc_CalculateCRC32_IsFirstCallFasle_NullPtr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32
TEST.NEW
TEST.NAME:Crc_CalculateCRC32_IsFirstCallFasle_NullPtr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr:<<malloc 9>>
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr:<<null>>
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_Length:2
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_StartValue32:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC32.return:0xC2
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32.Crc_DataPtr[0]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32.Crc_DataPtr[2]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC32_ValidInput
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32
TEST.NEW
TEST.NAME:Crc_CalculateCRC32_ValidInput
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr:<<malloc 3>>
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[0]:0x92
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[1]:0x6B
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_DataPtr[2]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_Length:3
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_StartValue32:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC32.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC32.return:0x9CDEA29B
TEST.END

-- Subprogram: Crc_CalculateCRC32P4

-- Test Case: Crc_CalculateCRC32P4_IsFirstCallFasle
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32P4
TEST.NEW
TEST.NAME:Crc_CalculateCRC32P4_IsFirstCallFasle
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[0]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_Length:1
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_StartValue32:0xAA4983F
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC32P4.return:0xEE688A78
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[2]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:EXPECTED_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC32P4_IsFirstCallFasle_NullPtr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32P4
TEST.NEW
TEST.NAME:Crc_CalculateCRC32P4_IsFirstCallFasle_NullPtr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_Length:2
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_StartValue32:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC32P4.return:0xC2
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[0]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[2]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:EXPECTED_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC32P4_ValidInput
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC32P4
TEST.NEW
TEST.NAME:Crc_CalculateCRC32P4_ValidInput
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr:<<malloc 3>>
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[0]:0x92
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[1]:0x6B
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_DataPtr[2]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_Length:3
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_StartValue32:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC32P4.return:0xEE688A78
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC32P4.Crc_IsFirstCall:EXPECTED_BASE=16
TEST.END

-- Subprogram: Crc_CalculateCRC64

-- Test Case: BASIS-PATH-001
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC64
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != Crc_IsFirstCall) ==> FALSE
      (2) if ((void *)0 != Crc_DataPtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<malloc 9>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<null>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_Length:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_StartValue64:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_IsFirstCall:0
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC64
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U != Crc_IsFirstCall) ==> FALSE
      (2) if ((void *)0 != Crc_DataPtr) ==> TRUE
      (3) for (Crc_DataCount < Crc_Length) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_Length:0
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_StartValue64:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_IsFirstCall:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC64
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U != Crc_IsFirstCall) ==> FALSE
      (2) if ((void *)0 != Crc_DataPtr) ==> TRUE
      (3) for (Crc_DataCount < Crc_Length) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_Length:1
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_StartValue64:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_IsFirstCall:0
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC64
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (0U != Crc_IsFirstCall) ==> TRUE
      (2) if ((void *)0 != Crc_DataPtr) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<malloc 9>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_DataPtr:<<null>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_Length:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_StartValue64:<<MIN>>
TEST.VALUE:Crc.Crc_CalculateCRC64.Crc_IsFirstCall:1
TEST.END

-- Subprogram: Crc_CalculateCRC8

-- Test Case: Crc_CalculateCRC8_IsFirstCallFalse
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8
TEST.NEW
TEST.NAME:Crc_CalculateCRC8_IsFirstCallFalse
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr:<<malloc 2>>
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[0]:0xFF
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[1]:0xFF
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_Length:2
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_StartValue8:0x3B
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC8.return:0x74
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[2]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[3]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC8_IsFirstCallFalse_NullPtr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8
TEST.NEW
TEST.NAME:Crc_CalculateCRC8_IsFirstCallFalse_NullPtr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr:<<malloc 9>>
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr:<<null>>
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_Length:2
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_StartValue8:0x3B
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC8.return:0x3B
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[0]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[2]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8.Crc_DataPtr[3]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC8_ValidInput
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8
TEST.NEW
TEST.NAME:Crc_CalculateCRC8_ValidInput
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr:<<malloc 4>>
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[0]:0x0
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[1]:0x0
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[2]:0x0
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_DataPtr[3]:0x0
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_Length:4
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_StartValue8:0x10
TEST.VALUE:Crc.Crc_CalculateCRC8.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC8.return:0x59
TEST.END

-- Subprogram: Crc_CalculateCRC8H2F

-- Test Case: Crc_CalculateCRC8H2F_IsFirstCallFasle
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:Crc_CalculateCRC8H2F_IsFirstCallFasle
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[0]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_Length:1
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_StartValue8:0x2B
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_IsFirstCall:FALSE
TEST.EXPECTED:Crc.Crc_CalculateCRC8H2F.return:0x33
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[1]:INPUT_BASE=16
TEST.ATTRIBUTES:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[2]:INPUT_BASE=16
TEST.END

-- Test Case: Crc_CalculateCRC8H2F_ValidInput
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:Crc_CalculateCRC8H2F_ValidInput
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr:<<malloc 3>>
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[0]:0x92
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[1]:0x6B
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr[2]:0x55
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_Length:3
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_StartValue8:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_IsFirstCall:TRUE
TEST.EXPECTED:Crc.Crc_CalculateCRC8H2F.return:0x33
TEST.END

-- Test Case: Crc_CalculateCRC8H2_IsFirstCallFasle_NullPtr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:Crc_CalculateCRC8H2_IsFirstCallFasle_NullPtr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_DataPtr:<<malloc 1>>
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_Length:2
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_StartValue8:0xC2
TEST.VALUE:Crc.Crc_CalculateCRC8H2F.Crc_IsFirstCall:FALSE
TEST.END

-- Subprogram: Crc_GetVersionInfo

-- Test Case: Crc_GetVersionInfo_Nullptr
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_GetVersionInfo
TEST.NEW
TEST.NAME:Crc_GetVersionInfo_Nullptr
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_GetVersionInfo.Versioninfo:<<null>>
TEST.EXPECTED:Crc.Crc_GetVersionInfo.Versioninfo:<<null>>
TEST.END

-- Test Case: Crc_GetVersionInfo_Nullptr.001
TEST.UNIT:Crc
TEST.SUBPROGRAM:Crc_GetVersionInfo
TEST.NEW
TEST.NAME:Crc_GetVersionInfo_Nullptr.001
TEST.NOTES:
SoftwareArchitecture::SYS::Crc::Crc_Detailed_Design::Crc Class Diagram
Requirement_DICVA-7443
TEST.END_NOTES:
TEST.VALUE:Crc.Crc_GetVersionInfo.Versioninfo:<<malloc 1>>
TEST.END
