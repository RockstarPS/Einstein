-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DLT_M4
-- Unit(s) Under Test: vDLT
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: vDLT_BufferClearNotify

-- Test Case: vDLT_BufferClearNotify.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_BufferClearNotify
TEST.NEW
TEST.NAME:vDLT_BufferClearNotify.001
TEST.STUB:vDLT.vDLT_ClearBuffer
TEST.VALUE:vDLT.vDLT_ClearBuffer.bufferID:1
TEST.VALUE:vDLT.vDLT_BufferClearNotify.commanddata_addr:<<malloc 1>>
TEST.END

-- Test Case: vDLT_BufferClearNotify.002
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_BufferClearNotify
TEST.NEW
TEST.NAME:vDLT_BufferClearNotify.002
TEST.STUB:vDLT.vDLT_ClearBuffer
TEST.VALUE:vDLT.vDLT_ClearBuffer.bufferID:1
TEST.VALUE:vDLT.vDLT_BufferClearNotify.commanddata_addr:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_BufferClearNotify.commanddata_addr[0]:6
TEST.VALUE:vDLT.vDLT_BufferClearNotify.payload_size:6
TEST.END

-- Subprogram: vDLT_BufferFullNotify

-- Test Case: vDLT_BufferFullNotify.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_BufferFullNotify
TEST.NEW
TEST.NAME:vDLT_BufferFullNotify.001
TEST.END

-- Test Case: vDLT_BufferFullNotify.002
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_BufferFullNotify
TEST.NEW
TEST.NAME:vDLT_BufferFullNotify.002
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:1
TEST.END

-- Subprogram: vDLT_ClearBuffer

-- Test Case: vDLT_ClearBuffer.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_ClearBuffer
TEST.NEW
TEST.NAME:vDLT_ClearBuffer.001
TEST.VALUE:vDLT.vDLT_ClearBuffer.bufferID:3
TEST.END

-- Subprogram: vDLT_Init

-- Test Case: vDLT_Init.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_Init
TEST.NEW
TEST.NAME:vDLT_Init.001
TEST.END

-- Subprogram: vDLT_LogMsg

-- Test Case: vDLT_LogMsg.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.001
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 9>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<null>>
TEST.END

-- Test Case: vDLT_LogMsg.002
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.002
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:0
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.ContextId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.END

-- Test Case: vDLT_LogMsg.003
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.003
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Uninit
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:0
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Uninit
TEST.END

-- Test Case: vDLT_LogMsg.004
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.004
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BufferFull:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:20
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:1
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.ContextId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.END

-- Test Case: vDLT_LogMsg.005
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.005
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BufferFull:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:20
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:1
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.ContextId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.END

-- Test Case: vDLT_LogMsg.006
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.006
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_MessageCounter_U8:35
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BufferFull:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:20
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:1
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.ContextId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.END

-- Test Case: vDLT_LogMsg.007
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_LogMsg
TEST.NEW
TEST.NAME:vDLT_LogMsg.007
TEST.STUB:vDLT.HW_RD_REG32_RAW
TEST.STUB:vDLT.vDLT_BufferFullNotify
TEST.VALUE:vDLT.<<GLOBAL>>.l_MessageCounter_U8:255
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BufferIndex:35
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[0].BufferFull:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps:<<malloc 1>>
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.HTYP_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.MsgCounter_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.Length_U16:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.EcuId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].StdHeader.TimeStamp_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.MsgType_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.Arguments_U8:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.AppId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].ExtHeader.ContextId_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.TypeInfo_U32:1
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BuffAdd_ps[0].Payload.data_U8A[1]:0
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferIndex:20
TEST.VALUE:vDLT.<<GLOBAL>>.Dlt_Buffers_st[1].BufferFull:1
TEST.VALUE:vDLT.<<GLOBAL>>.l_ActivaBuffer_U8:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.addr:1
TEST.VALUE:vDLT.HW_RD_REG32_RAW.return:1
TEST.VALUE:vDLT.vDLT_BufferFullNotify.bufferID:0
TEST.VALUE:vDLT.vDLT_LogMsg.typeInfo_pU8:1
TEST.VALUE:vDLT.vDLT_LogMsg.appId:1
TEST.VALUE:vDLT.vDLT_LogMsg.ContextId:1
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8:<<malloc 1>>
TEST.VALUE:vDLT.vDLT_LogMsg.data_pU8[0]:1
TEST.EXPECTED:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Idle
TEST.END

-- Subprogram: vDLT_deInit

-- Test Case: vDLT_deInit.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_deInit
TEST.NEW
TEST.NAME:vDLT_deInit.001
TEST.END

-- Subprogram: vDLT_mainFunction

-- Test Case: vDLT_mainFunction.001
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_mainFunction
TEST.NEW
TEST.NAME:vDLT_mainFunction.001
TEST.END

-- Test Case: vDLT_mainFunction.002
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_mainFunction
TEST.NEW
TEST.NAME:vDLT_mainFunction.002
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Buffull
TEST.END

-- Test Case: vDLT_mainFunction.003
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_mainFunction
TEST.NEW
TEST.NAME:vDLT_mainFunction.003
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_Buffull
TEST.VALUE:uut_prototype_stubs.vHsmCrypto_Command_SendData.return:1
TEST.END

-- Test Case: vDLT_mainFunction.004
TEST.UNIT:vDLT
TEST.SUBPROGRAM:vDLT_mainFunction
TEST.NEW
TEST.NAME:vDLT_mainFunction.004
TEST.VALUE:vDLT.<<GLOBAL>>.l_DLTstate_e:e_DLT_WaitAck
TEST.END
