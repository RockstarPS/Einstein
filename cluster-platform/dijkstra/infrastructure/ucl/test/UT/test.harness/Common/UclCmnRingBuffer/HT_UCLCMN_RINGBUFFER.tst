-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLCMN_RINGBUFFER
-- Unit(s) Under Test: UclCmnRingBuffer
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclCmnRingBuffer

-- Subprogram: UclCmnRingBuffer_GetFillCnt

-- Test Case: UclCmnRingBuffer_GetFillCnt.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_GetFillCnt
TEST.NEW
TEST.NAME:UclCmnRingBuffer_GetFillCnt.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_GetFillCnt.pSize:<<malloc 4>>
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_GetFillCnt.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_GetFillCnt.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_GetFillCnt.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclCmnRingBuffer_IndexedRead

-- Test Case: UclCmnRingBuffer_IndexedRead.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_IndexedRead
TEST.NEW
TEST.NAME:UclCmnRingBuffer_IndexedRead.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:50
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:20
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.Index:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_IndexedRead.002
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_IndexedRead
TEST.NEW
TEST.NAME:UclCmnRingBuffer_IndexedRead.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:50
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.Index:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_IndexedRead.003
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_IndexedRead
TEST.NEW
TEST.NAME:UclCmnRingBuffer_IndexedRead.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:50
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.Index:10
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_IndexedRead.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclCmnRingBuffer_Initialize

-- Test Case: UclCmnRingBuffer_Initialize.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Initialize
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.size:100
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pBuffer>> = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Initialize_Buffer_Null
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Initialize
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Initialize_Buffer_Null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pRB:<<malloc 1>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.size:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.return:UCL_E_NOK
TEST.END

-- Test Case: UclCmnRingBuffer_Initialize_Buffer_SizeZero
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Initialize
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Initialize_Buffer_SizeZero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pRB:<<malloc 1>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.size:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Initialize.pBuffer>> = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Initialize_RB_NULL
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Initialize
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Initialize_RB_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Initialize.return:UCL_E_NOK
TEST.END

-- Subprogram: UclCmnRingBuffer_Poll

-- Test Case: UclCmnRingBuffer_Poll.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Poll
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Poll.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Poll.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Poll.002
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Poll
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Poll.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Poll.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Poll.003
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Poll
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Poll.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Poll.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Poll.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclCmnRingBuffer_Read

-- Test Case: UclCmnRingBuffer_Read.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Read
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Read.002
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Read
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Read.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:5
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:5
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Read.003
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Read
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Read.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:5
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_Read.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclCmnRingBuffer_ReadFrame

-- Test Case: UclCmnRingBuffer_ReadFrame.FillCountZero
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_ReadFrame
TEST.NEW
TEST.NAME:UclCmnRingBuffer_ReadFrame.FillCountZero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclCmnRingBuffer.UclCmnRingBuffer_Reset
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.return:UCL_E_OK
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.delim:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0xFF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB>> = ( &UclRB );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.pBuffer
<<uut_prototype_stubs.UclALOs_Memset.pBuffer>> = ( &UclRB.pBuffer );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.Size
<<uut_prototype_stubs.UclALOs_Memset.Size>> = ( &UclRB.BufferSize );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_ReadFrame.IPBufferLessThanFrameLength
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_ReadFrame
TEST.NEW
TEST.NAME:UclCmnRingBuffer_ReadFrame.IPBufferLessThanFrameLength
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:15
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:15
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.delim:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0xFF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.pBuffer
<<uut_prototype_stubs.UclALOs_Memset.pBuffer>> = ( &UclRB.pBuffer );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.Size
<<uut_prototype_stubs.UclALOs_Memset.Size>> = ( &UclRB.BufferSize );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize>> = ( &size1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_ReadFrame.InValidDelim
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_ReadFrame
TEST.NEW
TEST.NAME:UclCmnRingBuffer_ReadFrame.InValidDelim
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.delim:0xF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0xFF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.pBuffer
<<uut_prototype_stubs.UclALOs_Memset.pBuffer>> = ( &UclRB.pBuffer );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.Size
<<uut_prototype_stubs.UclALOs_Memset.Size>> = ( &UclRB.BufferSize );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_ReadFrame.IncompleteFrame
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_ReadFrame
TEST.NEW
TEST.NAME:UclCmnRingBuffer_ReadFrame.IncompleteFrame
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:5
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:5
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.delim:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0xFF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.pBuffer
<<uut_prototype_stubs.UclALOs_Memset.pBuffer>> = ( &UclRB.pBuffer );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.Size
<<uut_prototype_stubs.UclALOs_Memset.Size>> = ( &UclRB.BufferSize );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_ReadFrame.ValidFillCount
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_ReadFrame
TEST.NEW
TEST.NAME:UclCmnRingBuffer_ReadFrame.ValidFillCount
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.size:10
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.delim:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0xFF
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.return:UCL_E_OK
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.return:UCL_E_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.pBuffer
<<uut_prototype_stubs.UclALOs_Memset.pBuffer>> = ( &UclRB.pBuffer );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_Memset.Size
<<uut_prototype_stubs.UclALOs_Memset.Size>> = ( &UclRB.BufferSize );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer
<<UclCmnRingBuffer.<<GLOBAL>>.UclRB>>.pBuffer = ( &UclRingBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pBuffer>> = ( &UclReadBuffer );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize
<<UclCmnRingBuffer.UclCmnRingBuffer_ReadFrame.pSize>> = ( &size );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclCmnRingBuffer_Reset

-- Test Case: UclCmnRingBuffer_Reset.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Reset
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Reset.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB:<<malloc 1>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB[0].pBuffer:<<malloc 15>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB[0].pBuffer:"&UclRingBuffer"
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB[0].BufferSize:100
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Reset.return:UCL_E_OK
TEST.END

-- Test Case: UclCmnRingBuffer_Reset.RB_Null
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Reset
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Reset.RB_Null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB:<<null>>
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Reset.return:UCL_E_NOK
TEST.END

-- Test Case: UclCmnRingBuffer_Reset_Buffer_Null
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Reset
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Reset_Buffer_Null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Reset.pRB:<<malloc 1>>
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Reset.return:UCL_E_NOK
TEST.END

-- Subprogram: UclCmnRingBuffer_Write

-- Test Case: UclCmnRingBuffer_Write.001
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Write
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer:<<malloc 16>>
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer:"&UclWriteBuffer"
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pBuffer:<<malloc 16>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pBuffer:"&UclWriteBuffer"
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.size:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.ReadIndex:0
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.WriteIndex:10
TEST.EXPECTED:UclCmnRingBuffer.<<GLOBAL>>.UclRB.FillCount:10
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Write.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclCmnRingBuffer_Write.002
TEST.UNIT:UclCmnRingBuffer
TEST.SUBPROGRAM:UclCmnRingBuffer_Write
TEST.NEW
TEST.NAME:UclCmnRingBuffer_Write.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer:<<malloc 16>>
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.pBuffer:"&UclWriteBuffer"
TEST.VALUE:UclCmnRingBuffer.<<GLOBAL>>.UclRB.BufferSize:100
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pBuffer:<<malloc 16>>
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pBuffer:"&UclWriteBuffer"
TEST.VALUE:UclCmnRingBuffer.UclCmnRingBuffer_Write.size:200
TEST.EXPECTED:UclCmnRingBuffer.UclCmnRingBuffer_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE_USER_CODE:UclCmnRingBuffer.UclCmnRingBuffer_Write.pRB
<<UclCmnRingBuffer.UclCmnRingBuffer_Write.pRB>> = ( &UclRB );
TEST.END_VALUE_USER_CODE:
TEST.END
