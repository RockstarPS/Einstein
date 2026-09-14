-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLCMN_UCLCRC
-- Unit(s) Under Test: UclCrc
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclCrc

-- Subprogram: UclCrc_CalculateCRC16

-- Test Case: UclCrc_CalculateCRC16_IsFirstCallFasle
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC16
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC16_IsFirstCallFasle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8:<<malloc 1>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[0]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_Length_U32:1
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_StartValue_U16:0xBE4B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC16.return:0x745
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC16_IsFirstCallFasle_NullPtr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC16
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC16_IsFirstCallFasle_NullPtr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8:<<malloc 9>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8:<<null>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_Length_U32:1
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_StartValue_U16:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC16.return:0xC2
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC16_ValidInput
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC16
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC16_ValidInput
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8:<<malloc 3>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[0]:0x92
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[1]:0x6B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_DataPtr_U8[2]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_Length_U32:3
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_StartValue_U16:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC16.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC16.return:0x745
TEST.END

-- Subprogram: UclCrc_CalculateCRC32

-- Test Case: UclCrc_CalculateCRC32_IsFirstCallFasle
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32_IsFirstCallFasle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8:<<malloc 3>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[0]:0x92
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[1]:0x6B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[2]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_Length_U32:3
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_StartValue_U32:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32.return:0x9CDEA29B
TEST.END

-- Test Case: UclCrc_CalculateCRC32_IsFirstCallFasle_NullPtr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32_IsFirstCallFasle_NullPtr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8:<<malloc 9>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8:<<null>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_Length_U32:2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_StartValue_U32:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32.return:0xC2
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC32_ValidInput
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32_ValidInput
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8:<<malloc 3>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[0]:0x92
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[1]:0x6B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_DataPtr_U8[2]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_Length_U32:3
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_StartValue_U32:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32.return:0x9CDEA29B
TEST.END

-- Subprogram: UclCrc_CalculateCRC32P4

-- Test Case: UclCrc_CalculateCRC32P4_IsFirstCallFasle
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32P4
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32P4_IsFirstCallFasle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8:<<malloc 1>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[0]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_Length_U32:1
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_StartValue_U32:0xAA4983F
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32P4.return:0xEE688A78
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:EXPECTED_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC32P4_IsFirstCallFasle_NullPtr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32P4
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32P4_IsFirstCallFasle_NullPtr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_Length_U32:2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_StartValue_U32:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32P4.return:0xC2
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:EXPECTED_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC32P4_ValidInput
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC32P4
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC32P4_ValidInput
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8:<<malloc 3>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[0]:0x92
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[1]:0x6B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_DataPtr_U8[2]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_Length_U32:3
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_StartValue_U32:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC32P4.return:0xEE688A78
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC32P4.p_Crc_IsFirstCall_BOOL:EXPECTED_BASE=16
TEST.END

-- Subprogram: UclCrc_CalculateCRC8

-- Test Case: UclCrc_CalculateCRC8_IsFirstCallFalse
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8_IsFirstCallFalse
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8:<<malloc 2>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[0]:0xFF
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[1]:0xFF
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_Length_U32:2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_StartValue_U8:0x3B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8.return:0x74
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[3]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC8_IsFirstCallFalse_NullPtr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8_IsFirstCallFalse_NullPtr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8:<<malloc 9>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8:<<null>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_Length_U32:2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_StartValue_U8:0x3B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8.return:0x3B
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[3]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC8_ValidInput
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8_ValidInput
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8:<<malloc 4>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[0]:0x0
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[1]:0x0
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[2]:0x0
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_DataPtr_U8[3]:0x0
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_Length_U32:4
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_StartValue_U8:0x10
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8.return:0x59
TEST.END

-- Subprogram: UclCrc_CalculateCRC8H2F

-- Test Case: UclCrc_CalculateCRC8H2F_IsFirstCallFasle
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8H2F_IsFirstCallFasle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8:<<malloc 1>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[0]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_Length_U32:1
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_StartValue_U8:0x2B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8H2F.return:0x33
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.END

-- Test Case: UclCrc_CalculateCRC8H2F_ValidInput
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8H2F_ValidInput
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8:<<malloc 3>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[0]:0x92
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[1]:0x6B
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[2]:0x55
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_Length_U32:3
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_StartValue_U8:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_IsFirstCall_BOOL:true
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8H2F.return:0x33
TEST.END

-- Test Case: UclCrc_CalculateCRC8H2_IsFirstCallFasle_NullPtr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_CalculateCRC8H2F
TEST.NEW
TEST.NAME:UclCrc_CalculateCRC8H2_IsFirstCallFasle_NullPtr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8:<<malloc 9>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8:<<null>>
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_Length_U32:2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_StartValue_U8:0xC2
TEST.VALUE:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_IsFirstCall_BOOL:false
TEST.EXPECTED:UclCrc.UclCrc_CalculateCRC8H2F.return:0xC2
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclCrc.UclCrc_CalculateCRC8H2F.p_Crc_DataPtr_U8[2]:INPUT_BASE=16
TEST.END

-- Subprogram: UclCrc_GetVersionInfo

-- Test Case: UclCrc_GetVersionInfo_Nullptr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_GetVersionInfo
TEST.NEW
TEST.NAME:UclCrc_GetVersionInfo_Nullptr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo:<<null>>
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo:<<null>>
TEST.END

-- Test Case: UclCrc_GetVersionInfo_Validptr
TEST.UNIT:UclCrc
TEST.SUBPROGRAM:UclCrc_GetVersionInfo
TEST.NEW
TEST.NAME:UclCrc_GetVersionInfo_Validptr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo:<<malloc 1>>
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].vendorID:170
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].moduleID:170
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_major_version:170
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_minor_version:170
TEST.VALUE:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_patch_version:170
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].vendorID:255
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].moduleID:201
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_major_version:1
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_minor_version:0
TEST.EXPECTED:UclCrc.UclCrc_GetVersionInfo.p_Versioninfo[0].sw_patch_version:0
TEST.END
