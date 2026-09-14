-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_SCHEDULE_TABLE_VCAST_HT
-- Unit(s) Under Test: OsScheduleTable
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsScheduleTable

-- Subprogram: OsGetScheduleTableStatus

-- Test Case: OsGetScheduleTableStatus.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsGetScheduleTableStatus
TEST.NEW
TEST.NAME:OsGetScheduleTableStatus.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.OsGetScheduleTableStatus.ScheduleTableID:0
TEST.VALUE:OsScheduleTable.OsGetScheduleTableStatus.ScheduleStatus:<<malloc 1>>
TEST.END

-- Test Case: OsGetScheduleTableStatus.002.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsGetScheduleTableStatus
TEST.NEW
TEST.NAME:OsGetScheduleTableStatus.002.001
TEST.VALUE:OsScheduleTable.OsGetScheduleTableStatus.ScheduleTableID:4
TEST.VALUE:OsScheduleTable.OsGetScheduleTableStatus.ScheduleStatus:<<malloc 1>>
TEST.END

-- Subprogram: OsNextScheduleTable

-- Test Case: OsNextScheduleTable.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001
TEST.END

-- Test Case: OsNextScheduleTable.001.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001.001
TEST.END

-- Test Case: OsNextScheduleTable.001.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001.002
TEST.END

-- Test Case: OsNextScheduleTable.001.003
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001.003
TEST.END

-- Test Case: OsNextScheduleTable.001.004
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001.004
TEST.END

-- Test Case: OsNextScheduleTable.001.005
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsNextScheduleTable
TEST.NEW
TEST.NAME:OsNextScheduleTable.001.005
TEST.END

-- Subprogram: OsProcessScheduleTable

-- Test Case: OsProcessScheduleTable.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.END

-- Test Case: OsProcessScheduleTable.001.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].CounterId:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0x1
TEST.END

-- Test Case: OsProcessScheduleTable.001.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_WAITING
TEST.END

-- Test Case: OsProcessScheduleTable.001.003
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.003
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.004
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.004
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:2
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.005
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.005
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:2
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.006
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.006
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:2
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.007
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.007
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:2
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.008
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.008
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:TRUE
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:1
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.009
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.009
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_IMPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.010
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.010
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_EXPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.011
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.011
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_EXPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.012
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.012
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_EXPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0xFFFFFFFF
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.013
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.013
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_EXPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0xFFFFFFFF
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.014
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.014
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_EXPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0xFFFFFFFF
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.001.015
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.001.015
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:5
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].EventSetListRef[0].EventTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].TaskActivateListRef[0].ActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_IMPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 2>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[1].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:2
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.003
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.003
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 2>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[1].ExpPointOffset:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:2
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.004
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.004
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchedTblDuration:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_IMPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Test Case: OsProcessScheduleTable.005
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsProcessScheduleTable
TEST.NEW
TEST.NAME:OsProcessScheduleTable.005
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchedTblDuration:0xFFFFFFFF
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].OsSchedTblRepeating:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam[0].TickCount:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].ExpPointOffset:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfEventSet:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].ExpiryPointListRef[0].NoOfTaskActivate:0
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].NoOfExpiryPoint:1
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SyncConfigRef[0].SchTblSyncType:SCHEDULETABLE_SYNC_IMPLICIT
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].NextTimestamp:10
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].CurrentExpiryPoint:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.CounterID:0
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.Value[0]:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0
TEST.END

-- Subprogram: OsStartScheduleTableAbs

-- Test Case: OsStartScheduleTableAbs.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableAbs
TEST.NEW
TEST.NAME:OsStartScheduleTableAbs.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.END

-- Test Case: OsStartScheduleTableAbs.001.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableAbs
TEST.NEW
TEST.NAME:OsStartScheduleTableAbs.001.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.END

-- Test Case: OsStartScheduleTableAbs.001.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableAbs
TEST.NEW
TEST.NAME:OsStartScheduleTableAbs.001.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_STOPPED
TEST.END

-- Test Case: OsStartScheduleTableAbs.001.003
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableAbs
TEST.NEW
TEST.NAME:OsStartScheduleTableAbs.001.003
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_STOPPED
TEST.VALUE:OsScheduleTable.OsStartScheduleTableAbs.Start:10
TEST.END

-- Test Case: OsStartScheduleTableAbs.001.004
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableAbs
TEST.NEW
TEST.NAME:OsStartScheduleTableAbs.001.004
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.OsStartScheduleTableAbs.ScheduleTableID:2
TEST.END

-- Subprogram: OsStartScheduleTableRel

-- Test Case: OsStartScheduleTableRel.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.END

-- Test Case: OsStartScheduleTableRel.001.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.END

-- Test Case: OsStartScheduleTableRel.001.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.ScheduleTableID:0
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.Start:0
TEST.END

-- Test Case: OsStartScheduleTableRel.001.003
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001.003
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef[0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_STOPPED
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.ScheduleTableID:0
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.Start:10
TEST.END

-- Test Case: OsStartScheduleTableRel.001.004
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001.004
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].CounterRef:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_STOPPED
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.ScheduleTableID:0
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.Start:10
TEST.VALUE:uut_prototype_stubs.OsGetCounterValue.return:0x1
TEST.END

-- Test Case: OsStartScheduleTableRel.001.005
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStartScheduleTableRel
TEST.NEW
TEST.NAME:OsStartScheduleTableRel.001.005
TEST.VALUE:OsScheduleTable.OsStartScheduleTableRel.ScheduleTableID:2
TEST.END

-- Subprogram: OsStopScheduleTable

-- Test Case: OsStopScheduleTable.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStopScheduleTable
TEST.NEW
TEST.NAME:OsStopScheduleTable.002
TEST.VALUE:OsScheduleTable.OsStopScheduleTable.ScheduleTableID:4
TEST.END

-- Test Case: OsStopScheduleTable.002.001
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStopScheduleTable
TEST.NEW
TEST.NAME:OsStopScheduleTable.002.001
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.OsStopScheduleTable.ScheduleTableID:0
TEST.END

-- Test Case: OsStopScheduleTable.002.002
TEST.UNIT:OsScheduleTable
TEST.SUBPROGRAM:OsStopScheduleTable
TEST.NEW
TEST.NAME:OsStopScheduleTable.002.002
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam:<<malloc 1>>
TEST.VALUE:OsScheduleTable.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].SchTblParam[0].Status:SCHEDULETABLE_RUNNING
TEST.VALUE:OsScheduleTable.OsStopScheduleTable.ScheduleTableID:0
TEST.END
