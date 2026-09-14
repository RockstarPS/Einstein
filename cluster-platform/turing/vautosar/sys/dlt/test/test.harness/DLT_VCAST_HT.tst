-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DLT_VCAST_HT
-- Unit(s) Under Test: Dlt Dlt_Cfg Dlt_Comm_Com
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Dlt

-- Subprogram: Dlt_ApplyLogLevelThreshold

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_ApplyLogLevelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (idx < DltLogMsg.channelCount) ==> FALSE
      (3) if (atleastOneChannelPass == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable atleastOneChannelPass in branch 3
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_ApplyLogLevelThreshold.logLevel:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_ApplyLogLevelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (idx < DltLogMsg.channelCount) ==> FALSE
      (3) if (atleastOneChannelPass == 1) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable atleastOneChannelPass in branch 3
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_ApplyLogLevelThreshold.logLevel:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_ApplyLogLevelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (logLevel < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelThreshold) ==> FALSE
      (3) if (atleastOneChannelPass == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set atleastOneChannelPass due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelThreshold:<<MIN>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_ApplyLogLevelThreshold.logLevel:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_ApplyLogLevelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (logLevel < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelThreshold) ==> TRUE
      (3) if (atleastOneChannelPass == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set local variable atleastOneChannelPass in branch 3
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelThreshold:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_ApplyLogLevelThreshold.logLevel:<<MIN>>
TEST.END

-- Subprogram: Dlt_CheckMessageLength

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (idy < DltLogMsg.channelCount) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable atleastOneChannelPass in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltDefaultLogChannelRef.DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (idy < DltLogMsg.channelCount) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable atleastOneChannelPass in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltDefaultLogChannelRef.DltLogChannelMaxMessageLength:<<MIN>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (idy < DltLogMsg.channelCount) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable atleastOneChannelPass in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (idy < DltLogMsg.channelCount) ==> TRUE
      (2) for (idx < 2U) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set local variable atleastOneChannelPass in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltDefaultLogChannelRef.DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (idy < DltLogMsg.channelCount) ==> TRUE
      (2) for (idx < 2U) ==> TRUE
      (3) if ((DltLogMsg.LogChannelPtr)[idy] == &((DltLogChannelRef)[idx])) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set local variable atleastOneChannelPass in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltDefaultLogChannelRef.DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (idy < DltLogMsg.channelCount) ==> TRUE
      (2) for (idx < 2U) ==> TRUE
      (3) if ((DltLogMsg.LogChannelPtr)[idy] == &((DltLogChannelRef)[idx])) ==> TRUE
      (4) if (length > (DltLogMsg.LogChannelPtr)[idy]->DltLogChannelMaxMessageLength) ==> FALSE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set variable to unknown value in branch 3
      Cannot set local variable idy in branch 4
      Cannot set atleastOneChannelPass due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CheckMessageLength
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (idy < DltLogMsg.channelCount) ==> TRUE
      (2) for (idx < 2U) ==> TRUE
      (3) if ((DltLogMsg.LogChannelPtr)[idy] == &((DltLogChannelRef)[idx])) ==> TRUE
      (4) if (length > (DltLogMsg.LogChannelPtr)[idy]->DltLogChannelMaxMessageLength) ==> TRUE
      (5) if (atleastOneChannelPass == 1) ==> FALSE
      (6) if (length > DltDefaultLogChannelRef.DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 2
      Cannot set variable to unknown value in branch 3
      Cannot set local variable idy in branch 4
      Cannot set local variable atleastOneChannelPass in branch 5
      Conflict: Cannot resolve multiple comparisons ( Dlt.Dlt_CheckMessageLength.length ) in branches 4/6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MIN>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CheckMessageLength.length:<<MAX>>
TEST.END

-- Subprogram: Dlt_CopyMessageToBuffers

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (idx < DltLogMsg.channelCount) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> FALSE
      (3) if (messagaLengthAct < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelMaxMessageLength) ==> FALSE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
      Cannot set local variable idx in branch 3
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MIN>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> FALSE
      (3) if (messagaLengthAct < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelMaxMessageLength) ==> TRUE
      (4) if (1024U - channel->count <= messagaLengthAct) ==> FALSE
      (6) for (idy < messagaLengthAct) ==> FALSE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
      Cannot set local variable idx in branch 3
      Cannot set messagaLengthAct due to assignment
      Cannot set local variable idy in branch 6
      Cannot set local variable channel in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltTxPdu:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> FALSE
      (3) if (messagaLengthAct < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelMaxMessageLength) ==> TRUE
      (4) if (1024U - channel->count <= messagaLengthAct) ==> FALSE
      (6) for (idy < messagaLengthAct) ==> TRUE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
      Cannot set local variable idx in branch 3
      Cannot set messagaLengthAct due to assignment
      Cannot set local variable idy in branch 6
      Cannot set local variable channel in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltTxPdu:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> FALSE
      (3) if (messagaLengthAct < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelMaxMessageLength) ==> TRUE
      (4) if (1024U - channel->count <= messagaLengthAct) ==> TRUE
      (5) if (channel->overflowFlag == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
      Cannot set local variable idx in branch 3
      Cannot set messagaLengthAct due to assignment
      Cannot set local variable channel in branch 5
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> FALSE
      (3) if (messagaLengthAct < (DltLogMsg.LogChannelPtr)[idx]->DltLogChannelMaxMessageLength) ==> TRUE
      (4) if (1024U - channel->count <= messagaLengthAct) ==> TRUE
      (5) if (channel->overflowFlag == 0) ==> TRUE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
      Cannot set local variable idx in branch 3
      Cannot set messagaLengthAct due to assignment
      Cannot set local variable channel in branch 5
      Cannot set local variable channel in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0]:<<malloc 1>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.LogChannelPtr[0][0].DltLogChannelMaxMessageLength:<<MAX>>
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyMessageToBuffers
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (idx < DltLogMsg.channelCount) ==> TRUE
      (2) if (locLogChannelId == (0x444c5458U)) ==> TRUE
   Test Case Generation Notes:
      Cannot set locLogChannelId due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogMsg.channelCount:<<MAX>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyMessageToBuffers.logDataLength:<<MIN>>
TEST.END

-- Subprogram: Dlt_CopyRxData

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyRxData
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CopyRxData.info:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyRxData.bufferSizePtr:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_CopyTxData

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CopyTxData
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CopyTxData.id:<<MIN>>
TEST.VALUE:Dlt.Dlt_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyTxData.retry:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_CreateDltLogHeader

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> TRUE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
      Only one possible value for condition in branch 7
      Only one possible value for condition in branch 8
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:0
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> TRUE
      (8) if 0 ==> TRUE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
      Only one possible value for condition in branch 7
      Only one possible value for condition in branch 8
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:0
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> TRUE
      (7) if 0 ==> TRUE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
      Only one possible value for condition in branch 7
      Only one possible value for condition in branch 8
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:0
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (5) if 0x1 ==> TRUE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (4) if 0 ==> TRUE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> TRUE
      (4) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> TRUE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltLogHeader
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if 0x1 ==> TRUE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (5) if 0x1 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (logInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltLogHeader.logDataLength:<<MIN>>
TEST.END

-- Subprogram: Dlt_CreateDltTraceHeader

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> TRUE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
      Only one possible value for condition in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:0
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> TRUE
      (7) if 0 ==> TRUE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
      Only one possible value for condition in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:0
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (5) if 0x1 ==> TRUE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (4) if 0 ==> TRUE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> FALSE
      (3) if 0 ==> TRUE
      (4) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if 0x1 ==> FALSE
      (2) if 1U ==> TRUE
      (3) if 0 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_CreateDltTraceHeader
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if 0x1 ==> TRUE
      (2) if 1U ==> FALSE
      (3) if 0 ==> FALSE
      (5) if 0x1 ==> FALSE
      (6) if ((0x1 == 0x1 || 0 == 0x1) || (traceInfo->options & 1U) == (0)) ==> FALSE
   Test Case Generation Notes:
      Only one possible value for condition in branch 1
      Only one possible value for condition in branch 2
      Only one possible value for condition in branch 3
      Only one possible value for condition in branch 4
      Only one possible value for condition in branch 5
      Conflict: A condition in this branch uses an operand that cannot be set (0x1 == 0x1 || 0 == 0x1) in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.timeStamp:<<MIN>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.traceInfo[0].options:1
TEST.VALUE:Dlt.Dlt_CreateDltTraceHeader.logDataLength:<<MIN>>
TEST.END

-- Subprogram: Dlt_DemTriggerOnEventData

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_DemTriggerOnEventData
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_DemTriggerOnEventData.EventId:<<MIN>>
TEST.END

-- Subprogram: Dlt_DetForwardErrorTrace

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_DetForwardErrorTrace
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_FilterMessage

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Cannot set matchFound due to assignment
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:<<MIN>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> TRUE
      (7) if ((logInfo->options & 1U) != (0)) ==> FALSE
   Test Case Generation Notes:
      Cannot set matchFound due to assignment
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:<<MIN>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo[0].options:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> TRUE
      (7) if ((logInfo->options & 1U) != (0)) ==> TRUE
   Test Case Generation Notes:
      Cannot set matchFound due to assignment
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:<<MIN>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo[0].options:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> TRUE
      (2) for (idx < 128U) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set local variable matchFound in branch 6
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:1
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> TRUE
      (2) for (idx < 128U) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> TRUE
      (4) if (swcContextId == contextId || swcContextId == (0U)) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set swcContextId due to assignment
      Cannot set local variable contextId in branch 4
      Cannot set local variable matchFound in branch 6
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:1
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> TRUE
      (2) for (idx < 128U) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> TRUE
      (4) if (swcContextId == contextId || swcContextId == (0U)) ==> TRUE
      (5) if (logLevel <= ((DltSwcContextInternal)[idx]).DltLogLevelThreshold) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set swcContextId due to assignment
      Cannot set local variable contextId in branch 4
      Cannot set idx due to assignment
      Cannot set matchFound due to assignment
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:1
TEST.VALUE:Dlt.<<GLOBAL>>.DltSwcContextInternal[0].DltLogLevelThreshold:<<MIN>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo[0].logLevel:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> TRUE
      (2) for (idx < 128U) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> TRUE
      (4) if (swcContextId == contextId || swcContextId == (0U)) ==> TRUE
      (5) if (logLevel <= ((DltSwcContextInternal)[idx]).DltLogLevelThreshold) ==> TRUE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set swcContextId due to assignment
      Cannot set local variable contextId in branch 4
      Cannot set idx due to assignment
      Cannot set matchFound due to assignment
      Cannot set logLevelFilter due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:1
TEST.VALUE:Dlt.<<GLOBAL>>.DltSwcContextInternal[0].DltLogLevelThreshold:<<MAX>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo[0].logLevel:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_FilterMessage
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (Dlt_LocalConfigData.filterEnabled == 1) ==> TRUE
      (2) for (idx < 128U) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> FALSE
      (6) if (matchFound == 1 && logLevelFilter == 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set local variable matchFound in branch 6
      Cannot set local variable logLevelFilter in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.Dlt_LocalConfigData.filterEnabled:1
TEST.VALUE:Dlt.Dlt_FilterMessage.logInfo:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GenerateTimestamp

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GenerateTimestamp
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_GetDefaultLogLevel

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetDefaultLogLevel
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetDefaultLogLevel.defaultLogLevel:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GetDefaultTraceStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetDefaultTraceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetDefaultTraceStatus.traceStatus:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GetLogChannelNames

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetLogChannelNames
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetLogChannelNames.numberOfLogChannels:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_GetLogChannelNames.logChannelNames:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GetLogChannelThreshold

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetLogChannelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetLogChannelThreshold.logChannelThreshold:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_GetLogChannelThreshold.traceStatus:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GetLogInfo

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetLogInfo
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetLogInfo.options:<<MIN>>
TEST.VALUE:Dlt.Dlt_GetLogInfo.status:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_GetLogInfo.logInfo:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_GetTraceStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_GetTraceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_GetTraceStatus.traceStatus:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_InitMemory

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_InitMemory
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_InitMemory
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_InjectCall_SESSION

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_InjectCall_SESSION
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_MessageCounter

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MessageCounter
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (LogMessageCount == 255U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.LogMessageCount:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MessageCounter
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (message_count == 255U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MessageCounter
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (LogMessageCount == 255U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.LogMessageCount:255
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_MessageCounter
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (message_count == 255U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_RegisterContext

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:1
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 9>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<null>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 9>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<null>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.BASIS_PATH:2 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (5) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (7) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (6) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 6
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (5) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (7) if (RegisterStatus != 0x3U) ==> TRUE
      (8) if (Dlt_LocalConfigData.reg_app_id_cnt < 126U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 7
      Conflict: Cannot resolve multiple comparisons ( Dlt.<<GLOBAL>>.Dlt_LocalConfigData.reg_app_id_cnt ) in branches 5/8
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (6) if (RegisterStatus != 0x3U) ==> TRUE
      (7) if (Dlt_LocalConfigData.reg_app_id_cnt < 126U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 6
      Conflict: Cannot resolve multiple comparisons ( Dlt.<<GLOBAL>>.Dlt_LocalConfigData.reg_app_id_cnt ) in branches 4/7
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (5) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (7) if (RegisterStatus != 0x3U) ==> TRUE
      (8) if (Dlt_LocalConfigData.reg_app_id_cnt < 126U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
      (6) if (RegisterStatus != 0x3U) ==> TRUE
      (7) if (Dlt_LocalConfigData.reg_app_id_cnt < 126U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable RegisterStatus in branch 6
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (5) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (6) if (logmsg_app_id == (RegContextArr)[idx]) ==> TRUE
      (7) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
      Cannot set RegisterStatus due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (app_id == (RegContextArr)[idx]) ==> TRUE
      (6) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
      Cannot set RegisterStatus due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (5) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (6) if (logmsg_app_id == (RegContextArr)[idx]) ==> FALSE
      (7) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
      Cannot set local variable RegisterStatus in branch 7
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> FALSE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (app_id == (RegContextArr)[idx]) ==> FALSE
      (6) if (RegisterStatus != 0x3U) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
      Cannot set local variable RegisterStatus in branch 6
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (logmsg_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-008.001
TEST.BASIS_PATH:8 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) if (Dlt_LocalConfigData.reg_app_id_cnt == 0U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-009
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RegisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-009
TEST.BASIS_PATH:9 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((((logmsg_context_id == 1U || logmsg_app_description == (void *)0) || logmsg_len_app_description == 1U) || logmsg_context_description == (void *)0) || logmsg_len_context_description == 1U) ==> TRUE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_id:"1"
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<malloc 9>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_app_description:<<null>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_app_description:1
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<malloc 9>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_context_description:<<null>>
TEST.VALUE:Dlt.Dlt_RegisterContext.logmsg_len_context_description:1
TEST.END

-- Subprogram: Dlt_ResetToFactoryDefault

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_ResetToFactoryDefault
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_RxIndication

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_RxIndication
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_SelectTargetLogChannels

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (idx < 128U + 2U) ==> FALSE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (idx < 128U + 2U) ==> FALSE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (idx < 128U + 2U) ==> FALSE
      (5) if (matchFound == 0) ==> TRUE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (idx < 128U + 2U) ==> TRUE
      (2) if (((DltLogChannelAssignmentInternal)[idx]).DltLogChannelAssignmentSwcContextRef != (void *)0) ==> FALSE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set idx due to assignment
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogChannelAssignmentInternal[0].DltLogChannelAssignmentSwcContextRef:<<null>>
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (idx < 128U + 2U) ==> TRUE
      (2) if (((DltLogChannelAssignmentInternal)[idx]).DltLogChannelAssignmentSwcContextRef != (void *)0) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> FALSE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set idx due to assignment
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogChannelAssignmentInternal[0].DltLogChannelAssignmentSwcContextRef:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (idx < 128U + 2U) ==> TRUE
      (2) if (((DltLogChannelAssignmentInternal)[idx]).DltLogChannelAssignmentSwcContextRef != (void *)0) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> TRUE
      (4) if (swcContextId == contextId || swcContextId == (0U)) ==> FALSE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set idx due to assignment
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set swcContextId due to assignment
      Cannot set local variable contextId in branch 4
      Cannot set local variable matchFound in branch 5
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogChannelAssignmentInternal[0].DltLogChannelAssignmentSwcContextRef:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SelectTargetLogChannels
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (idx < 128U + 2U) ==> TRUE
      (2) if (((DltLogChannelAssignmentInternal)[idx]).DltLogChannelAssignmentSwcContextRef != (void *)0) ==> TRUE
      (3) if (swcApplicationId == applicationId) ==> TRUE
      (4) if (swcContextId == contextId || swcContextId == (0U)) ==> TRUE
      (5) if (matchFound == 0) ==> FALSE
      (6) for (idx < channelCount) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set idx due to assignment
      Cannot set swcApplicationId due to assignment
      Cannot set local variable applicationId in branch 3
      Cannot set swcContextId due to assignment
      Cannot set local variable contextId in branch 4
      Cannot set matchFound due to assignment
      Cannot set local variable channelCount in branch 6
TEST.END_NOTES:
TEST.VALUE:Dlt.<<GLOBAL>>.DltLogChannelAssignmentInternal[0].DltLogChannelAssignmentSwcContextRef:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_SelectTargetLogChannels.logInfo:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_SendLogMessage

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (2) if (0U == Dlt_MessageFiltering(appid_swc, msg_session_id)) ==> FALSE
      (4) if ((uint8)0U == ReturnStatus_DltMsg) ==> FALSE
   Test Case Generation Notes:
      Cannot set ReturnStatus_DltMsg due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (2) if (0U == Dlt_MessageFiltering(appid_swc, msg_session_id)) ==> FALSE
      (4) if ((uint8)0U == ReturnStatus_DltMsg) ==> TRUE
   Test Case Generation Notes:
      Cannot set ReturnStatus_DltMsg due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (2) if (0U == Dlt_MessageFiltering(appid_swc, msg_session_id)) ==> TRUE
      (3) if (2U <= MessageLogDataLength && 8U >= MessageLogDataLength) ==> FALSE
      (4) if ((uint8)0U == ReturnStatus_DltMsg) ==> FALSE
   Test Case Generation Notes:
      Cannot set ReturnStatus_DltMsg due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (2) if (0U == Dlt_MessageFiltering(appid_swc, msg_session_id)) ==> TRUE
      (3) if (2U <= MessageLogDataLength && 8U >= MessageLogDataLength) ==> TRUE
      (4) if ((uint8)0U == ReturnStatus_DltMsg) ==> FALSE
   Test Case Generation Notes:
      Cannot set ReturnStatus_DltMsg due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.002
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendLogMessage
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (2) if (0U == Dlt_MessageFiltering(appid_swc, msg_session_id)) ==> TRUE
      (3) if (2U <= MessageLogDataLength && 8U >= MessageLogDataLength) ==> TRUE
      (4) if ((uint8)0U == ReturnStatus_DltMsg) ==> FALSE
   Test Case Generation Notes:
      Cannot set ReturnStatus_DltMsg due to assignment
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_SendTraceMessage

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SendTraceMessage
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SendTraceMessage.sessionId:<<MIN>>
TEST.VALUE:Dlt.Dlt_SendTraceMessage.traceInfo:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_SendTraceMessage.traceData:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_SendTraceMessage.traceDataLength:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetDefaultLogLevel

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetDefaultLogLevel
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetDefaultLogLevel.newLogLevel:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetDefaultTraceStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetDefaultTraceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetDefaultTraceStatus.newTraceStatus:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetLogChannelAssignment

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetLogChannelAssignment
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetLogChannelAssignment.addRemoveOp:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetLogChannelThreshold

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetLogChannelThreshold
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetLogChannelThreshold.newThreshold:<<MIN>>
TEST.VALUE:Dlt.Dlt_SetLogChannelThreshold.newTraceStatus:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetLogLevel

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetLogLevel
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetLogLevel.newLogLevel:<<MIN>>
TEST.END

-- Subprogram: Dlt_SetMessageFiltering

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetMessageFiltering
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (MessageFilteringStatus != 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetMessageFiltering.MessageFilteringStatus:0
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetMessageFiltering
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (status != 0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetMessageFiltering
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (MessageFilteringStatus != 0) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetMessageFiltering.MessageFilteringStatus:1
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetMessageFiltering
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (status != 0) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_SetTraceStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_SetTraceStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_SetTraceStatus.newTraceStatus:<<MIN>>
TEST.END

-- Subprogram: Dlt_StartOfReception

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_StartOfReception
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_StartOfReception.info:<<malloc 1>>
TEST.VALUE:Dlt.Dlt_StartOfReception.TpSduLength:<<MIN>>
TEST.VALUE:Dlt.Dlt_StartOfReception.bufferSizePtr:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_StoreConfiguration

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_StoreConfiguration
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_TpRxIndication

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TpRxIndication
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_TpTxConfirmation

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TpTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_TriggerTransmit

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TriggerTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_TriggerTransmit.TxPduId:<<MIN>>
TEST.VALUE:Dlt.Dlt_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.END

-- Subprogram: Dlt_TxConfirmation

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_TxFunction

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TxFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 4 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (idx < 2U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 1
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TxFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 4 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (idx < 2U) ==> TRUE
      (2) if (channel->count != 0U && channelTX->TxStatus == (eDlt_Transmit_Idle)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 1
      Cannot set local variable channel in branch 2
      Cannot set local variable channelTX in branch 2
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TxFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 4 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (idx < 2U) ==> TRUE
      (2) if (channel->count != 0U && channelTX->TxStatus == (eDlt_Transmit_Idle)) ==> TRUE
      (3) if (channelTX->TransmitCounter > channelTX->MaxNumOfRetries) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 1
      Cannot set local variable channel in branch 2
      Cannot set local variable channelTX in branch 2
      Cannot set local variable channelTX in branch 3
      Cannot set local variable channel in branch 3
      Cannot set channelTX->TransmitCounter due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-TEMPLATE
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_TxFunction
TEST.NEW
TEST.NAME:BASIS-PATH-004-TEMPLATE
TEST.BASIS_PATH:4 of 4 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (idx < 2U) ==> TRUE
      (2) if (channel->count != 0U && channelTX->TxStatus == (eDlt_Transmit_Idle)) ==> TRUE
      (3) if (channelTX->TransmitCounter > channelTX->MaxNumOfRetries) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable idx in branch 1
      Cannot set local variable channel in branch 2
      Cannot set local variable channelTX in branch 2
      Cannot set local variable channelTX in branch 3
      Cannot set local variable channel in branch 3
      Cannot set channelTX->TransmitCounter due to assignment
      Cannot set local variable channelTX in branch 4
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_UnregisterContext

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.BASIS_PATH:3 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && message_app_id == (RegContextArr)[idx]) ==> TRUE
      (6) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_app_id:"1"
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && app_id == (RegContextArr)[idx]) ==> TRUE
      (5) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && message_app_id == (RegContextArr)[idx]) ==> TRUE
      (6) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (7) if (126U - 1U > jdx) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && app_id == (RegContextArr)[idx]) ==> TRUE
      (5) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (6) if (126U - 1U > jdx) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && message_app_id == (RegContextArr)[idx]) ==> TRUE
      (6) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (7) if (126U - 1U > jdx) ==> TRUE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && app_id == (RegContextArr)[idx]) ==> TRUE
      (5) for (jdx <= Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (6) if (126U - 1U > jdx) ==> TRUE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (message_context_id == 1U) ==> FALSE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> TRUE
      (3) if (message_session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (4) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (5) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && message_app_id == (RegContextArr)[idx]) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (Dlt_LocalConfigData.InitStatus == 1U) ==> TRUE
      (2) if (session_id == Dlt_LocalConfigData.session_id) ==> TRUE
      (3) for (idx < Dlt_LocalConfigData.reg_app_id_cnt) ==> TRUE
      (4) if (Dlt_LocalConfigData.reg_app_id_cnt <= 126U && app_id == (RegContextArr)[idx]) ==> FALSE
   Test Case Generation Notes:
      Cannot set idx due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:Dlt
TEST.SUBPROGRAM:Dlt_UnregisterContext
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (message_context_id == 1U) ==> TRUE
      (2) if (Dlt_LocalConfigData.InitStatus == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_session_id:<<MIN>>
TEST.VALUE:Dlt.Dlt_UnregisterContext.message_context_id:"1"
TEST.END

-- Unit: Dlt_Cfg

-- Subprogram: PduR_DltTransmit

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt_Cfg
TEST.SUBPROGRAM:PduR_DltTransmit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt_Cfg.PduR_DltTransmit.TxPduId:<<MIN>>
TEST.END

-- Unit: Dlt_Comm_Com

-- Subprogram: Dlt_SendData_Cantp

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt_Comm_Com
TEST.SUBPROGRAM:Dlt_SendData_Cantp
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Dlt_Comm_Com.Dlt_SendData_Cantp.data:<<MIN>>
TEST.END

-- Subprogram: Dlt_StartCommunicationHook_Cantp

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Dlt_Comm_Com
TEST.SUBPROGRAM:Dlt_StartCommunicationHook_Cantp
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 2 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (i < (1024U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Dlt_Comm_Com
TEST.SUBPROGRAM:Dlt_StartCommunicationHook_Cantp
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 2 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (i < (1024U)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Subprogram: Dlt_StopCommunicationHook_Cantp

-- Test Case: BASIS-PATH-001
TEST.UNIT:Dlt_Comm_Com
TEST.SUBPROGRAM:Dlt_StopCommunicationHook_Cantp
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END
