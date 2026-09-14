-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALPHYMAILBOXTILINUX
-- Unit(s) Under Test: UclALPhyMailboxLinux_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhyMailboxLinux_Impl

-- Subprogram: UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask

-- Test Case: UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.DriveNotReadyState
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.DriveNotReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_ERROR_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.ReadyState
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.ReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.RemoteDriveNotReadyState
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.RemoteDriveNotReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_Close

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Close.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Close
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Close.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Close.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Close.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Close.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Close.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.001
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData[0]:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:1
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_MsgStatus

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_MsgStatus.001
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_MsgStatus.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].msgStatus[0]:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:1
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_Open

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_OpenFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_OpenFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pMailboxReg_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pMailboxReg_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = MAP_FAILED;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pRxShMemBuffer_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pRxShMemBuffer_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 2;
   <<uut_prototype_stubs.mmap.return>> = <<UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyCfg_0>>.mailboxBaseAddress;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 2)
{
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 3;
    <<uut_prototype_stubs.mmap.return>> = <<UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyCfg_0>>.txShmMemPhyAddr;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 3)
{
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 4;
    <<uut_prototype_stubs.mmap.return>> = MAP_FAILED;
}
else
{
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pTxShMemBuffer_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_NOK_pTxShMemBuffer_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 2;
   <<uut_prototype_stubs.mmap.return>> = <<UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyCfg_0>>.mailboxBaseAddress;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 2)
{
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 3;
    <<uut_prototype_stubs.mmap.return>> = MAP_FAILED;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 3)
{
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 4;
}
else
{
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Open.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_Read

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_NOK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].msgStatus[0]:MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_NOK_pData_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_NOK_pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].msgStatus[0]:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Read.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].msgStatus[0]:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_SetDriverState

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_SetDriverState.UCL_E_NOK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_SetDriverState.UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_SetDriverState.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_SetDriverState.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Hw_Write

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Write.UCL_E_NOK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Write.UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].fifoStatus[0]:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Hw_Write.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Hw_Write.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMailboxReg[0].fifoStatus[0]:MAILBOX_FIFO_STATUS_EMPTY
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.queueId:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.UCL_E_NOK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Open.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Read.MutexFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Read.MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_*pSize_0
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_*pSize_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize[0]:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pData_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pSize_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_INVALID_ARGS_pSize_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Read.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_Size_0
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_Size_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.Size:0
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_pData_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_INVALID_ARGS_pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK.MutexFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK.MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK.UCL_E_BUFFER_FULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_IUclALPhy_Write.UCL_E_OK.UCL_E_BUFFER_FULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_BUFFER_FULL
TEST.EXPECTED:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_TimerTask

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateError
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateError
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_ERROR_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInit_RemoteStateInit
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInit_RemoteStateInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INIT_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInit_RemoteStateSetup
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInit_RemoteStateSetup
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INIT_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_SETUP_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInvalid
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateInvalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_INVALID_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateReady_RemoteStateInit
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateReady_RemoteStateInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateReady_RemoteStateReady
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateReady_RemoteStateReady
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_READY_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateInit
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_SETUP_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_INIT_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateReady
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateReady
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_SETUP_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateReady_UCL_E_NOK
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.DriveStateSetup_RemoteStateReady_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.VALUE:UclALPhyMailboxLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.driverState:MAILBOX_SETUP_ST
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_SetDriverState.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState.return:MAILBOX_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_TimerTask.pData_NULL
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_TimerTask.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.pData:<<null>>
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_TimerTask.return:<<null>>
TEST.END

-- Subprogram: UclALPhyMailboxLinux_Impl_Transfer

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteMsgStatusEmpty_MutexFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteMsgStatusEmpty_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteMsgStatusEmpty_TxSize_0
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteMsgStatusEmpty_TxSize_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusEmpty
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusEmpty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)MAILBOX_MESSAGE_STATUS_EMPTY
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Write
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_MutexFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_ReceiveFailed
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_ReceiveFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_RxSize_not_0
TEST.UNIT:UclALPhyMailboxLinux_Impl
TEST.SUBPROGRAM:UclALPhyMailboxLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMailboxLinux_Impl_Transfer.WriteReadMsgStatusNotEmpty_RxSize_not_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read
TEST.STUB:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Hw_MsgStatus.return:(2)1
TEST.VALUE_USER_CODE:UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst
<<UclALPhyMailboxLinux_Impl.UclALPhyMailboxLinux_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
