-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALPHYMAILBOXTIASR
-- Unit(s) Under Test: UclALPhyMailboxASR_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhyMailboxASR_Impl

-- Subprogram: UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask

-- Test Case: UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.Drive_ErrorState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.Drive_ErrorState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_ERROR_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.remoteDriverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.ReadyState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.ReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.RemoteDrive_ErrorState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.RemoteDrive_ErrorState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_Close

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Close.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Close
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Close.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Close.return:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState

-- Test Case: UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_MsgStatus

-- Test Case: UclALPhyMailboxASR_Impl_Hw_MsgStatus.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_MsgStatus.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[195]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[196]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.queueId:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:0
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:0
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_Open

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Open.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Open.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Open.return:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_Read

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Read.MsgLen_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Read.MsgLen_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.queueId:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Read.MsgLen_Not_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Read.MsgLen_Not_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[194]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[195]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[196]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[197]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.queueId:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Read.pData_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Read.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_SetDriverState

-- Test Case: UclALPhyMailboxASR_Impl_Hw_SetDriverState.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_SetDriverState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Hw_Write

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Write.FifoStatus_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Write.FifoStatus_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.data:12
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.queueId:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Hw_Write.FifoStatus_Not_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Hw_Write.FifoStatus_Not_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[131]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.MailboxRegister[132]:1
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.queueId:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged

-- Test Case: UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete

-- Test Case: UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete

-- Test Case: UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_NOK
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Open
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.pRxRingBuffer[0]:INPUT_BASE=8
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst>> = &( <<UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_NOK_0_TaskPeriod
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_NOK_0_TaskPeriod
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Open
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.periodicityMs:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.ATTRIBUTES:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.pRxRingBuffer[0]:INPUT_BASE=8
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst>> = &( <<UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_OK
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Open
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.ATTRIBUTES:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.pRxRingBuffer[0]:INPUT_BASE=8
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize.pInst>> = &( <<UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_*pSize_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_*pSize_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pData_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<null>>
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pSize_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pSize_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_NOK_MutexFailed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_NOK_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_OK
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Read.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.pSize[0]:10
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown.UCL_E_OK
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Initialize
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Close
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.timerTaskId:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverStateChkTimerTaskId:2
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.txRingBufferMutexId:1
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.rxRingBufferMutexId:2
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_Size_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_Size_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.Size:0
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_pData_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<null>>
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_NOK_MutexFailed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_NOK_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_NOK_RingWriteFailed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_NOK_RingWriteFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_OK
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_IUclALPhy_Write.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.Size:10
TEST.EXPECTED:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_TimerTask

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.ErrorState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.ErrorState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_ERROR_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.InitState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.InitState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INIT_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.InvalidState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.InvalidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INVALID_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.ReadyState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.ReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotInitState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotInitState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INIT_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INVALID_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotReadyState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotSetupState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.RemoteDrive_NotSetupState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_SETUP_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.SetupState
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.SetupState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxASR_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_SETUP_ST
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState.return:MAILBOX_SETUP_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.pData>> = &UclALPhyInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_TimerTask.pData_NULL
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_TimerTask.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_TimerTask.return:<<null>>
TEST.END

-- Subprogram: UclALPhyMailboxASR_Impl_Transfer

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.ReadMsgStatusNotEmpty_Read_Failed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.ReadMsgStatusNotEmpty_Read_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusEmpty
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusEmpty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty_MutexFailed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty_ReadSize_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.ReadWriteMsgStatusNotEmpty_ReadSize_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.pData[0]:0
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.WriteMsgStatusEmpty_MutexFailed
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.WriteMsgStatusEmpty_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxASR_Impl_Transfer.WriteMsgStatusEmpty_TxSize_0
TEST.UNIT:UclALPhyMailboxASR_Impl
TEST.SUBPROGRAM:UclALPhyMailboxASR_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxASR_Impl_Transfer.WriteMsgStatusEmpty_TxSize_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_IUclALPhy_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:0
TEST.VALUE_USER_CODE:UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst
<<UclALPhyMailboxASR_Impl.UclALPhyMailboxASR_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
