-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLVMFMSGQUEUE
-- Unit(s) Under Test: UclVmfMsgQueue
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclVmfMsgQueue

-- Subprogram: UclVmfMsgQueue_Get

-- Test Case: UclVmfMsgQueue_Get.Success
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Get
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Get.Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:2
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:1
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:1
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Get.return:UCL_E_OK
TEST.END

-- Test Case: UclVmfMsgQueue_Get.Success.InvalidBufferLength
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Get
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Get.Success.InvalidBufferLength
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.Size:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Get.return:UCL_E_NOK
TEST.END

-- Test Case: UclVmfMsgQueue_Get.Success.MutexLockFail
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Get
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Get.Success.MutexLockFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Get.return:UCL_E_NOK
TEST.END

-- Test Case: UclVmfMsgQueue_Get.Success.QRollOver
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Get
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Get.Success.QRollOver
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:250
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:2
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:1
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Get.return:UCL_E_OK
TEST.END

-- Test Case: UclVmfMsgQueue_Get.Success.QueueIsEmpty
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Get
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Get.Success.QueueIsEmpty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Get.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Get.return:UCL_E_NOK
TEST.END

-- Subprogram: UclVmfMsgQueue_Put

-- Test Case: UclVmfMsgQueue_Put.InvalidPayloadLength
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.InvalidPayloadLength
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Put.return:UCL_E_NOK
TEST.END

-- Test Case: UclVmfMsgQueue_Put.MutexLockFail
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.MutexLockFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Put.return:UCL_E_NOK
TEST.END

-- Test Case: UclVmfMsgQueue_Put.QMaxLimitReached
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.QMaxLimitReached
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:250
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Put.return:UCL_E_NOK
TEST.END

-- Test Case: UclVmfMsgQueue_Put.Success
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:1
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:1
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Put.return:UCL_E_OK
TEST.END

-- Test Case: UclVmfMsgQueue_Put.Success.QRollOver
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.Success.QRollOver
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:250
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:0
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:1
TEST.EXPECTED:UclVmfMsgQueue.UclVmfMsgQueue_Put.return:UCL_E_OK
TEST.END

-- Test Case: UclVmfMsgQueue_Put.Success.QRollOver.001
TEST.UNIT:UclVmfMsgQueue
TEST.SUBPROGRAM:UclVmfMsgQueue_Put
TEST.NEW
TEST.NAME:UclVmfMsgQueue_Put.Success.QRollOver.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].readMsgIdx:0
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:250
TEST.VALUE:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].msgCnt:200
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.qIndex:0
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.pData:<<malloc 10>>
TEST.VALUE:UclVmfMsgQueue.UclVmfMsgQueue_Put.Size:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclVmfMsgQueue.<<GLOBAL>>.UclVmfMsgQueueRuntime[0].writeMsgIdx:0
TEST.END
