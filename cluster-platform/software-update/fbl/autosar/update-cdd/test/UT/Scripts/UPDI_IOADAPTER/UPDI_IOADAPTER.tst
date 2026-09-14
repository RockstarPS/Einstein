-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_IOADAPTER
-- Unit(s) Under Test: UPDi_IoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: InstallErase

-- Test Case: InstallErase.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:InstallErase
TEST.NEW
TEST.NAME:InstallErase.001
TEST.END

-- Subprogram: UPDIoAdapter_Erase

-- Test Case: UPDIoAdapter_Erase.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Erase
TEST.NEW
TEST.NAME:UPDIoAdapter_Erase.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Erase.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Erase.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDIoAdapter_Erase.002
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Erase
TEST.NEW
TEST.NAME:UPDIoAdapter_Erase.002
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Erase.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Erase.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDIoAdapter_Erase.003
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Erase
TEST.NEW
TEST.NAME:UPDIoAdapter_Erase.003
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Erase.return:0
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Erase.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Erase.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDIoAdapter_Hash

-- Test Case: UPDIoAdapter_Hash.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Hash
TEST.NEW
TEST.NAME:UPDIoAdapter_Hash.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Hash.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Hash.return:0
TEST.END

-- Subprogram: UPDIoAdapter_Idle

-- Test Case: UPDIoAdapter_Idle.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Idle
TEST.NEW
TEST.NAME:UPDIoAdapter_Idle.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Idle.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Idle.return:0
TEST.END

-- Subprogram: UPDIoAdapter_Init

-- Test Case: UPDIoAdapter_Init.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Init
TEST.NEW
TEST.NAME:UPDIoAdapter_Init.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Init.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Init.return:0
TEST.END

-- Subprogram: UPDIoAdapter_IsBusy

-- Test Case: UPDIoAdapter_IsBusy.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_IsBusy
TEST.NEW
TEST.NAME:UPDIoAdapter_IsBusy.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_IsBusy.return:0
TEST.END

-- Test Case: UPDIoAdapter_IsBusy.002
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_IsBusy
TEST.NEW
TEST.NAME:UPDIoAdapter_IsBusy.002
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram[0].PendingCalls:2
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram[0].PendingCalls:2
TEST.END

-- Test Case: UPDIoAdapter_IsBusy.003
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_IsBusy
TEST.NEW
TEST.NAME:UPDIoAdapter_IsBusy.003
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram[0].PendingCalls:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_IsBusy.this[0].Ram[0].PendingCalls:0
TEST.END

-- Subprogram: UPDIoAdapter_Read

-- Test Case: UPDIoAdapter_Read.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Read
TEST.NEW
TEST.NAME:UPDIoAdapter_Read.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.pTarget:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Read.return:0
TEST.VALUE_USER_CODE:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoAdapterre.Vtbl
<<UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoAdapterre>>.Vtbl = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Read.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Read.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDIoAdapter_Read.002
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Read
TEST.NEW
TEST.NAME:UPDIoAdapter_Read.002
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Read.return:0
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Read.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Read.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDIoAdapter_Read.003
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Read
TEST.NEW
TEST.NAME:UPDIoAdapter_Read.003
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.Offset:1
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Read.Size:2
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Read.Offset:1
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Read.Size:2
TEST.VALUE_USER_CODE:UPDi_IoAdapter.UPDIoAdapter_Read.this.this[0].Vtbl
<<UPDi_IoAdapter.UPDIoAdapter_Read.this>>[0].Vtbl = ( &sUPDiIoAda );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDIoAdapter_SetIdle

-- Test Case: UPDIoAdapter_SetIdle.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_SetIdle
TEST.NEW
TEST.NAME:UPDIoAdapter_SetIdle.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_SetIdle.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_SetIdle.return:0
TEST.END

-- Subprogram: UPDIoAdapter_Task

-- Test Case: UPDIoAdapter_Task.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Task.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Task.return:0
TEST.END

-- Test Case: UPDIoAdapter_Task.002
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.002
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Read
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Read
TEST.END

-- Test Case: UPDIoAdapter_Task.003
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.003
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Read
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Read
TEST.END

-- Test Case: UPDIoAdapter_Task.004
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.004
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.sUPDiIoReq_01.ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDIoAdapter_Task.005
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.005
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Write
TEST.END

-- Test Case: UPDIoAdapter_Task.006
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.006
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Hash
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Hash
TEST.END

-- Test Case: UPDIoAdapter_Task.007
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.007
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Idle
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Idle
TEST.END

-- Test Case: UPDIoAdapter_Task.008
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.008
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Decrypt
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Decrypt
TEST.END

-- Test Case: UPDIoAdapter_Task.009
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.009
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_SignVerify
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_SignVerify
TEST.END

-- Test Case: UPDIoAdapter_Task.010
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.010
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDIoAdapter_Task.011
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Task
TEST.NEW
TEST.NAME:UPDIoAdapter_Task.011
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_IoAdapter.<<GLOBAL>>.IoReqInfo.ReqType:eUPDiIoReq_Write
TEST.END

-- Subprogram: UPDIoAdapter_Write

-- Test Case: UPDIoAdapter_Write.001
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Write
TEST.NEW
TEST.NAME:UPDIoAdapter_Write.001
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.END

-- Test Case: UPDIoAdapter_Write.002
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Write
TEST.NEW
TEST.NAME:UPDIoAdapter_Write.002
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.END

-- Test Case: UPDIoAdapter_Write.003
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Write
TEST.NEW
TEST.NAME:UPDIoAdapter_Write.003
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.END

-- Test Case: UPDIoAdapter_Write.004
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Write
TEST.NEW
TEST.NAME:UPDIoAdapter_Write.004
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Write.return:0
TEST.END

-- Test Case: UPDIoAdapter_Write.005
TEST.UNIT:UPDi_IoAdapter
TEST.SUBPROGRAM:UPDIoAdapter_Write
TEST.NEW
TEST.NAME:UPDIoAdapter_Write.005
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram[0].AdapterBuffer:<<malloc 4>>
TEST.EXPECTED:UPDi_IoAdapter.UPDIoAdapter_Write.this[0].Ram[0].AdapterBuffer:<<null>>
TEST.END
