-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_MESSAGES_VCAST_HT
-- Unit(s) Under Test: OsMessage
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: osGetMessageStatus

-- Test Case: osGetMessageStatus.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osGetMessageStatus
TEST.NEW
TEST.NAME:osGetMessageStatus.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osGetMessageStatus.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osGetMessageStatus
TEST.NEW
TEST.NAME:osGetMessageStatus.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osGetMessageStatus.MessageID:2
TEST.EXPECTED:OsMessage.osGetMessageStatus.MessageID:2
TEST.END

-- Test Case: osGetMessageStatus.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osGetMessageStatus
TEST.NEW
TEST.NAME:osGetMessageStatus.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[1]:1
TEST.VALUE:OsMessage.osGetMessageStatus.MessageID:1
TEST.EXPECTED:OsMessage.osGetMessageStatus.MessageID:1
TEST.END

-- Subprogram: osInitMessage

-- Test Case: osInitMessage.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osInitMessage.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osInitMessage.MessageID:2
TEST.END

-- Test Case: osInitMessage.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.osInitMessage.MessageID:0
TEST.END

-- Test Case: osInitMessage.004
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.osInitMessage.MessageID:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.END

-- Test Case: osInitMessage.005
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osInitMessage.MessageID:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:2
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.END

-- Test Case: osInitMessage.006
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osInitMessage
TEST.NEW
TEST.NAME:osInitMessage.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueWriteIndex:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:<<MAX>>
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osInitMessage.MessageID:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.END

-- Subprogram: osMemCpy

-- Test Case: osMemCpy.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMemCpy
TEST.NEW
TEST.NAME:osMemCpy.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osMemCpy.dest:<<malloc 1>>
TEST.VALUE:OsMessage.osMemCpy.src:<<malloc 1>>
TEST.END

-- Test Case: osMemCpy.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMemCpy
TEST.NEW
TEST.NAME:osMemCpy.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osMemCpy.dest:<<malloc 1>>
TEST.VALUE:OsMessage.osMemCpy.src:<<malloc 1>>
TEST.VALUE:OsMessage.osMemCpy.bytes:1
TEST.END

-- Subprogram: osMessageProcessNotification

-- Test Case: osMessageProcessNotification.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osMessageProcessNotification.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:1
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.END

-- Test Case: osMessageProcessNotification.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifyTask[0]:1
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.VALUE:uut_prototype_stubs.osActivateTask.return:0
TEST.END

-- Test Case: osMessageProcessNotification.004
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:2
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.END

-- Test Case: osMessageProcessNotification.005
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifyTask[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifyEvent[0]:1
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.VALUE:uut_prototype_stubs.osSetEvent.return:0
TEST.END

-- Test Case: osMessageProcessNotification.006
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:3
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.END

-- Test Case: osMessageProcessNotification.007
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:3
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifyCallBack[0]:OsPrvEnterCriticalSection
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.END

-- Test Case: osMessageProcessNotification.008
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osMessageProcessNotification
TEST.NEW
TEST.NAME:osMessageProcessNotification.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:4
TEST.VALUE:OsMessage.osMessageProcessNotification.MessageID:0
TEST.EXPECTED:OsMessage.<<GLOBAL>>.OsMsgNotifications[0]:4
TEST.END

-- Subprogram: osReceiveMessage

-- Test Case: osReceiveMessage.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osReceiveMessage.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:2
TEST.END

-- Test Case: osReceiveMessage.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:0
TEST.END

-- Test Case: osReceiveMessage.004
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:0
TEST.END

-- Test Case: osReceiveMessage.005
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:1
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReadIndex:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:<<MAX>>
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:0
TEST.END

-- Test Case: osReceiveMessage.006
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:1
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueStatus:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:0
TEST.END

-- Test Case: osReceiveMessage.007
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osReceiveMessage
TEST.NEW
TEST.NAME:osReceiveMessage.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:<<MAX>>
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueStatus:2
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[1].osMsgQueueReceivedMessages:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osReceiveMessage.MessageID:0
TEST.END

-- Subprogram: osSendMessage

-- Test Case: osSendMessage.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osSendMessage.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osSendMessage.MessageID:2
TEST.END

-- Test Case: osSendMessage.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.osSendMessage.MessageID:0
TEST.END

-- Test Case: osSendMessage.004
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.osSendMessage.MessageID:0
TEST.END

-- Test Case: osSendMessage.005
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueReceivedMessages:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgIndexToQueueIndex[0]:0
TEST.VALUE:OsMessage.osSendMessage.MessageID:0
TEST.END

-- Test Case: osSendMessage.006
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendMessage
TEST.NEW
TEST.NAME:osSendMessage.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.osQueuedMessages[0].osMsgQueueWriteIndex:1
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgQueueSize[0]:<<MAX>>
TEST.VALUE:OsMessage.osSendMessage.MessageID:0
TEST.END

-- Subprogram: osSendZeroMessage

-- Test Case: osSendZeroMessage.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendZeroMessage
TEST.NEW
TEST.NAME:osSendZeroMessage.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Test Case: osSendZeroMessage.002
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendZeroMessage
TEST.NEW
TEST.NAME:osSendZeroMessage.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.osSendZeroMessage.MessageID:2
TEST.END

-- Test Case: osSendZeroMessage.003
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osSendZeroMessage
TEST.NEW
TEST.NAME:osSendZeroMessage.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgTxToRxIndex[0]:0
TEST.VALUE:OsMessage.<<GLOBAL>>.OsMsgNumberOfMsgReceivers[0]:2
TEST.END

-- Subprogram: osStartCOM

-- Test Case: osStartCOM.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osStartCOM
TEST.NEW
TEST.NAME:osStartCOM.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END

-- Subprogram: osStopCOM

-- Test Case: osStopCOM.001
TEST.UNIT:OsMessage
TEST.SUBPROGRAM:osStopCOM
TEST.NEW
TEST.NAME:osStopCOM.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DIVCA-7595
TEST.END_NOTES:
TEST.END
