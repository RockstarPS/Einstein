-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : COMXF_VCAST_HT
-- Unit(s) Under Test: ComXf
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: ComXf_DeInit

-- Test Case: ComXf_DeInit.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_DeInit
TEST.NEW
TEST.NAME:ComXf_DeInit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_InitStatus:COMXF_STATUS_INIT
TEST.EXPECTED:ComXf.<<GLOBAL>>.ComXf_InitStatus:COMXF_STATUS_UNINIT
TEST.END

-- Subprogram: ComXf_GetVersionInfo

-- Test Case: ComXf_GetVersionInfo.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_GetVersionInfo
TEST.NEW
TEST.NAME:ComXf_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_GetVersionInfo.VersionInfo[0].vendorID:0x33
TEST.EXPECTED:ComXf.ComXf_GetVersionInfo.VersionInfo[0].moduleID:175
TEST.EXPECTED:ComXf.ComXf_GetVersionInfo.VersionInfo[0].sw_major_version:1
TEST.EXPECTED:ComXf.ComXf_GetVersionInfo.VersionInfo[0].sw_minor_version:0
TEST.EXPECTED:ComXf.ComXf_GetVersionInfo.VersionInfo[0].sw_patch_version:0
TEST.END

-- Test Case: ComXf_GetVersionInfo.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_GetVersionInfo
TEST.NEW
TEST.NAME:ComXf_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:175
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.ATTRIBUTES:ComXf.ComXf_GetVersionInfo.VersionInfo[0].vendorID:EXPECTED_BASE=16
TEST.END

-- Subprogram: ComXf_Init

-- Test Case: ComXf_Init.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_Init
TEST.NEW
TEST.NAME:ComXf_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_InitStatus:COMXF_STATUS_UNINIT
TEST.VALUE:ComXf.ComXf_Init.config:<<malloc 1>>
TEST.EXPECTED:ComXf.<<GLOBAL>>.ComXf_InitStatus:COMXF_STATUS_INIT
TEST.END

-- Subprogram: ComXf_ReadSignalFromBuffer

-- Test Case: ComXf_ReadSignalFromBuffer.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.003
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.004
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT16
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.005
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT32
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.006
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT64
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.007
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT64
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:7
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.008
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_SINT64
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:0xAA
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:10
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:9
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:10
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.009
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 9>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<null>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0x0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_INV_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[1]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[2]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[3]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[4]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[5]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[6]:INPUT_BASE=16
TEST.ATTRIBUTES:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer[7]:INPUT_BASE=16
TEST.VALUE_USER_CODE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData
<<ComXf.ComXf_ReadSignalFromBuffer.pSignalData>> = ( (uint8 *)&<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.010
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData:<<null>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0x0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.SignalId:0
TEST.EXPECTED:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_INV_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.END

-- Test Case: ComXf_ReadSignalFromBuffer.011
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_ReadSignalFromBuffer
TEST.NEW
TEST.NAME:ComXf_ReadSignalFromBuffer.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:1
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.SignalId:ComXf_Num_Of_Signals
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSignalData:<<null>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.pSrcBuffer:<<malloc 8>>
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferLength:7
TEST.VALUE:ComXf.ComXf_ReadSignalFromBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0x0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_INV_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM
TEST.END

-- Subprogram: ComXf_UtilBitCopy

-- Test Case: ComXf_UtilBitCopy.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.DestBufferPtr[0]:0
TEST.END

-- Test Case: ComXf_UtilBitCopy.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:8
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:8
TEST.END

-- Test Case: ComXf_UtilBitCopy.003
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.004
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.005
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.006
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:10
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:10
TEST.END

-- Test Case: ComXf_UtilBitCopy.007
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.008
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestBufferEndianess:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestBufferEndianess:1
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.009
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:3
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.010
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:3
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: ComXf_UtilBitCopy.011
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilBitCopy
TEST.NEW
TEST.NAME:ComXf_UtilBitCopy.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:9
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:3
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.VALUE:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:ComXf.ComXf_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:2
TEST.EXPECTED:ComXf.ComXf_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Subprogram: ComXf_UtilGetSignExtended16BitData

-- Test Case: ComXf_UtilGetSignExtended16BitData.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended16BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended16BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.pData[0]:4
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.BitSize:4
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended16BitData.pData[0]:4
TEST.END

-- Test Case: ComXf_UtilGetSignExtended16BitData.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended16BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended16BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.pData[0]:4
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended16BitData.BitSize:22
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended16BitData.pData[0]:4
TEST.END

-- Subprogram: ComXf_UtilGetSignExtended32BitData

-- Test Case: ComXf_UtilGetSignExtended32BitData.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended32BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended32BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended32BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended32BitData.BitSize:33
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended32BitData.BitSize:33
TEST.END

-- Test Case: ComXf_UtilGetSignExtended32BitData.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended32BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended32BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended32BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended32BitData.pData[0]:0x0
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended32BitData.BitSize:28
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended32BitData.BitSize:28
TEST.END

-- Subprogram: ComXf_UtilGetSignExtended64BitData

-- Test Case: ComXf_UtilGetSignExtended64BitData.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended64BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended64BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended64BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended64BitData.BitSize:64
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended64BitData.BitSize:64
TEST.END

-- Test Case: ComXf_UtilGetSignExtended64BitData.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended64BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended64BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended64BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended64BitData.pData[0]:0
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended64BitData.BitSize:63
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended64BitData.BitSize:63
TEST.END

-- Subprogram: ComXf_UtilGetSignExtended8BitData

-- Test Case: ComXf_UtilGetSignExtended8BitData.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended8BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:8
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:8
TEST.END

-- Test Case: ComXf_UtilGetSignExtended8BitData.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended8BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.pData[0]:0
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:6
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:6
TEST.END

-- Test Case: ComXf_UtilGetSignExtended8BitData.003
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:ComXf_UtilGetSignExtended8BitData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.pData:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.pData[0]:0x3F
TEST.VALUE:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:6
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended8BitData.pData[0]:0xFF
TEST.EXPECTED:ComXf.ComXf_UtilGetSignExtended8BitData.BitSize:6
TEST.END

-- Subprogram: ComXf_UtilMemSet

-- Test Case: ComXf_UtilMemSet.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilMemSet
TEST.NEW
TEST.NAME:ComXf_UtilMemSet.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.ComXf_UtilMemSet.Value:0xAA
TEST.VALUE:ComXf.ComXf_UtilMemSet.Length:1
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xAA
TEST.VALUE_USER_CODE:ComXf.ComXf_UtilMemSet.pDest.pDest
<<ComXf.ComXf_UtilMemSet.pDest>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ComXf_UtilSetClearBitMask

-- Test Case: ComXf_UtilSetClearBitMask.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilSetClearBitMask
TEST.NEW
TEST.NAME:ComXf_UtilSetClearBitMask.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0
TEST.VALUE:ComXf.ComXf_UtilSetClearBitMask.BitMask:0xF
TEST.VALUE:ComXf.ComXf_UtilSetClearBitMask.SetMode:TRUE
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xF
TEST.VALUE_USER_CODE:ComXf.ComXf_UtilSetClearBitMask.pData
<<ComXf.ComXf_UtilSetClearBitMask.pData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_UtilSetClearBitMask.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_UtilSetClearBitMask
TEST.NEW
TEST.NAME:ComXf_UtilSetClearBitMask.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xFF
TEST.VALUE:ComXf.ComXf_UtilSetClearBitMask.BitMask:0xF
TEST.VALUE:ComXf.ComXf_UtilSetClearBitMask.SetMode:FALSE
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8:0xF0
TEST.VALUE_USER_CODE:ComXf.ComXf_UtilSetClearBitMask.pData
<<ComXf.ComXf_UtilSetClearBitMask.pData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ComXf_WriteSignalToBuffer

-- Test Case: ComXf_WriteSignalToBuffer.001
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength[0]:8
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0xBB
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer
<<ComXf.ComXf_WriteSignalToBuffer.pDestBuffer>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8arr>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.002
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength[0]:8
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:0
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0xBB
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer
<<ComXf.ComXf_WriteSignalToBuffer.pDestBuffer>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8arr>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.003
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength[0]:9
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:9
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer
<<ComXf.ComXf_WriteSignalToBuffer.pDestBuffer>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8arr>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.004
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:9
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength[0]:11
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:10
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer
<<ComXf.ComXf_WriteSignalToBuffer.pDestBuffer>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8arr>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.005
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:9
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<null>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:10
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer
<<ComXf.ComXf_WriteSignalToBuffer.pDestBuffer>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8arr>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.006
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:9
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer:<<malloc 9>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer:<<null>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:10
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.VALUE_USER_CODE:ComXf.ComXf_WriteSignalToBuffer.pSignalData
<<ComXf.ComXf_WriteSignalToBuffer.pSignalData>> = ( &<<ComXf.<<GLOBAL>>.test_buffu8>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.007
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:9
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:0
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pSignalData:<<null>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:10
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM_POINTER
TEST.END

-- Test Case: ComXf_WriteSignalToBuffer.008
TEST.UNIT:ComXf
TEST.SUBPROGRAM:ComXf_WriteSignalToBuffer
TEST.NEW
TEST.NAME:ComXf_WriteSignalToBuffer.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComXf::ComXf_Detailed_Design::ComXf_Class_Diagram
Requirement_DICVA-20230
TEST.END_NOTES:
TEST.VALUE:ComXf.<<GLOBAL>>.test_buffu8:0xBB
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalType:COMXF_SIGNALTYPE_UINT8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].SignalEndiannessType:COMXF_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBitPosition:7
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBitPosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].MsBytePosition:0
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].LsBytePosition:9
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].BitSize:8
TEST.VALUE:ComXf.<<GLOBAL>>.ComXf_SignalConfig[0].ByteLength:1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.SignalId:ComXf_Num_Of_Signals
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pSignalData:VECTORCAST_INT1
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBuffer:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.pDestBufferLength:<<malloc 1>>
TEST.VALUE:ComXf.ComXf_WriteSignalToBuffer.BufferOffset:10
TEST.EXPECTED:ComXf.<<GLOBAL>>.test_buffu8arr[0]:0x0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMXF_TRANSFORMER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMXF_E_PARAM
TEST.END
