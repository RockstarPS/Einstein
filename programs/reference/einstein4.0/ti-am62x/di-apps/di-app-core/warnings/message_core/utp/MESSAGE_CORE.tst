-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : MESSAGE_CORE
-- Unit(s) Under Test: warn_msgArbitrator warn_msgDefinition warn_msgSequencer warn_msgStore warn_msgTask
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: warn_msgArbitrator

-- Subprogram: msg_ArbitratorInitialise

-- Test Case: msg_ArbitratorInitialise.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorInitialise
TEST.NEW
TEST.NAME:msg_ArbitratorInitialise.001
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[1]:0
TEST.END

-- Test Case: msg_ArbitratorInitialise.001.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorInitialise
TEST.NEW
TEST.NAME:msg_ArbitratorInitialise.001.001
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[1]:0
TEST.END

-- Subprogram: msg_ArbitratorUpdate

-- Test Case: msg_ArbitratorUpdate..Active_Multi
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Active_Multi
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate..Forced_Multi
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Forced_Multi
TEST.STUB:warn_msgSequencer.msg_SequencerUpdate
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Multi
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Multi
TEST.STUB:warn_msgSequencer.msg_SequencerUpdate
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Single
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Single
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.001
TEST.END

-- Test Case: msg_ArbitratorUpdate.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.002
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.003
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.004
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.004
TEST.STUB:warn_msgSequencer.msg_SequencerAdd
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:<<MIN>>
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.005
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.005
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.006
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.006
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:1
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.007
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.007
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:1
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.008
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.008
TEST.STUB:warn_msgArbitrator.msg_ArbitratorInitialise
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.003
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001.001
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.003
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001.001
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.003
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.StatusFlag
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.StatusFlag
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:<<malloc 2>>
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:"0"
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single.001
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single.002
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single.003
TEST.STUB:warn_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.001
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.002
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.003
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.004
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.004
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove.001
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove.001
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove.002
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove.002
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove.003
TEST.UNIT:warn_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove.003
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Unit: warn_msgDefinition

-- Subprogram: msg_DefinitionGetDisplayTimeout

-- Test Case: msg_DefinitionGetDisplayTimeout.001
TEST.UNIT:warn_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.001
TEST.VALUE:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.007
TEST.UNIT:warn_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.007
TEST.VALUE:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miMaximum
TEST.EXPECTED:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.008
TEST.UNIT:warn_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.008
TEST.VALUE:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miUndefined
TEST.EXPECTED:warn_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Unit: warn_msgSequencer

-- Subprogram: msg_ClearNewMessageFlag

-- Test Case: msg_ClearNewMessageFlag.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_ClearNewMessageFlag
TEST.NEW
TEST.NAME:msg_ClearNewMessageFlag.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 5>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0xFF"
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0"
TEST.END

-- Test Case: msg_ClearNewMessageFlag.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_ClearNewMessageFlag
TEST.NEW
TEST.NAME:msg_ClearNewMessageFlag.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 5>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0xFF"
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0"
TEST.END

-- Test Case: msg_ClearNewMessageFlag.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_ClearNewMessageFlag
TEST.NEW
TEST.NAME:msg_ClearNewMessageFlag.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 5>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0xFF"
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0"
TEST.END

-- Subprogram: msg_SequencerAction

-- Test Case: ACK_ALL_BTN_EV
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.001.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.001.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.003
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.001.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.001.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.003
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.001.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.001.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.003
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACK.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACK.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACK.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACK.001.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACK.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACK.001.002
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.001.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.001.002
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST.002
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_CLEARABLE
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_CLEARABLE
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_CLEARABLE.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_CLEARABLE.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_CLEARABLE.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_CLEARABLE.002
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_GROUP
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_CURR_MSG_GROUP_UNDEF
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_CURR_MSG_GROUP_UNDEF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_CURR_MSG_GROUP_UNDEF.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_CURR_MSG_GROUP_UNDEF.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_CURR_MSG_GROUP_UNDEF.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_CURR_MSG_GROUP_UNDEF.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_UNDEF_MSG_IN_SEQ
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_UNDEF_MSG_IN_SEQ
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6..7]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:7
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..7]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_UNDEF_MSG_IN_SEQ.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_UNDEF_MSG_IN_SEQ.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6..7]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:7
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..7]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_GROUP_UNDEF_MSG_IN_SEQ.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_UNDEF_MSG_IN_SEQ.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6..7]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:7
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..7]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: msg_SequencerAction.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.006
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.007
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_FUNCTIONAL_SAFETY_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.008
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.009
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.010
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_TYRE_FILL_ASSIST_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:MSG_WARNING_DOOR_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.011
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:2
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.012
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:2
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:1
TEST.END

-- Test Case: msg_SequencerAction.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.013
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.014
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:2
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.015
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:2
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: msg_SequencerAction.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:msg_SequencerAction.016
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_FRONT_FINAL_SEAT_BELT_REMINDER_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_FRONT_FINAL_SEAT_BELT_REMINDER_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.Button:2
TEST.VALUE:warn_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Subprogram: msg_SequencerAdd

-- Test Case: msg_SequencerAdd.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001
TEST.END

-- Test Case: msg_SequencerAdd.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.001
TEST.END

-- Test Case: msg_SequencerAdd.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.001.001
TEST.END

-- Test Case: msg_SequencerAdd.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.001.002
TEST.END

-- Test Case: msg_SequencerAdd.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.002
TEST.END

-- Test Case: msg_SequencerAdd.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.003
TEST.END

-- Test Case: msg_SequencerAdd.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.001
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.002.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.001.001
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.002.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.001.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.002.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.003
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.END

-- Test Case: msg_SequencerAdd.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.003
TEST.END

-- Test Case: msg_SequencerAdd.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.003.001
TEST.END

-- Test Case: msg_SequencerAdd.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.003.002
TEST.END

-- Test Case: msg_SequencerAdd.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.004
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.004.001
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.004.002
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.005
TEST.END

-- Test Case: msg_SequencerAdd.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.005.001
TEST.END

-- Test Case: msg_SequencerAdd.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.005.002
TEST.END

-- Test Case: msg_SequencerAdd.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.006
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.006.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.006.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.007
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:40
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.007.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:40
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.007.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:40
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.008
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.008.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.008.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.009
TEST.STUB:warn_msgSequencer.seq_InsertMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.return:0xFF
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.009.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.009.001
TEST.STUB:warn_msgSequencer.seq_InsertMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.return:0xFF
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.009.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.009.002
TEST.STUB:warn_msgSequencer.seq_InsertMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.return:0xFF
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerAdd.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.010
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.ATTRIBUTES:warn_msgSequencer.seq_InsertMessage.return:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerAdd.010.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.010.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.ATTRIBUTES:warn_msgSequencer.seq_InsertMessage.return:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerAdd.010.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.010.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.ATTRIBUTES:warn_msgSequencer.seq_InsertMessage.return:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerAdd.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.011
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.012
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.013
TEST.END

-- Test Case: msg_SequencerAdd.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.014
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:1
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.015
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.016
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_TURN_FRONT_RIGHT_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_TURN_FRONT_RIGHT_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.017
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.017
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_FRONT_FOG_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_FRONT_FOG_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.018
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.018
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[2].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_FOG_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_FOG_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.019
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.019
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[2].seq_CurrentMessageID:MSG_WARNING_REAR_FOG_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_FOG_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_REAR_FOG_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.020
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.020
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[2].seq_CurrentMessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_SequencerAdd.021
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.021
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[2].seq_CurrentMessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:18
TEST.EXPECTED:warn_msgSequencer.msg_SequencerAdd.MessageID:MSG_WARNING_LEFT_DRL_LAMP_FAILURE_ID_INDEX
TEST.END

-- Subprogram: msg_SequencerForcedActive

-- Test Case: msg_SequencerForcedActive.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.001
TEST.END

-- Test Case: msg_SequencerForcedActive.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.001.001
TEST.END

-- Test Case: msg_SequencerForcedActive.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.001.002
TEST.END

-- Test Case: msg_SequencerForcedActive.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.002
TEST.VALUE:warn_msgSequencer.msg_SequencerForcedActive.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerForcedActive.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.002.001
TEST.VALUE:warn_msgSequencer.msg_SequencerForcedActive.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerForcedActive.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.002.002
TEST.VALUE:warn_msgSequencer.msg_SequencerForcedActive.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerForcedActive.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.003
TEST.END

-- Test Case: msg_SequencerForcedActive.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.003.001
TEST.END

-- Test Case: msg_SequencerForcedActive.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.003.002
TEST.END

-- Test Case: msg_SequencerForcedActive.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.004
TEST.END

-- Test Case: msg_SequencerForcedActive.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.004.001
TEST.END

-- Test Case: msg_SequencerForcedActive.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.004.002
TEST.END

-- Test Case: msg_SequencerForcedActive.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.005
TEST.VALUE:warn_msgSequencer.msg_SequencerForcedActive.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerForcedActive.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Test Case: msg_SequencerForcedActive.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerForcedActive.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerForcedActive.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Subprogram: msg_SequencerGetAlertInfo

-- Test Case: msg_SequencerGetAlertInfo.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.001
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.001.001
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.001.002
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.002
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.003
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:INPUT_BASE=16
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:INPUT_BASE=16
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:INPUT_BASE=16
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:warn_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<warn_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: msg_SequencerGetCurrent

-- Test Case: msg_SequencerGetCurrent.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.001
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Test Case: msg_SequencerGetCurrent.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.002
TEST.STUB:warn_msgSequencer.seq_GetViewMessage
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:4
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:10
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Subprogram: msg_SequencerGetMessage

-- Test Case: msg_SequencerGetMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.001
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.return:8
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.001.001
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.return:8
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.001.002
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.return:8
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.VALUE:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: msg_SequencerHide

-- Test Case: msg_SequencerHide.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerHide.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerHide.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerHide.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.END

-- Test Case: msg_SequencerHide.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.END

-- Test Case: msg_SequencerHide.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.END

-- Test Case: msg_SequencerHide.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.003
TEST.END

-- Test Case: msg_SequencerHide.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.003.001
TEST.END

-- Test Case: msg_SequencerHide.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.003.002
TEST.END

-- Test Case: msg_SequencerHide.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.004
TEST.VALUE:warn_msgSequencer.msg_SequencerHide.p_inst:5
TEST.END

-- Test Case: msg_SequencerHide.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.004.001
TEST.VALUE:warn_msgSequencer.msg_SequencerHide.p_inst:5
TEST.END

-- Test Case: msg_SequencerHide.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.004.002
TEST.VALUE:warn_msgSequencer.msg_SequencerHide.p_inst:5
TEST.END

-- Subprogram: msg_SequencerInitialise

-- Test Case: msg_SequencerInitialise.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..6]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..6]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..6]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.001
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.001.001
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.001.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.002
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.003
TEST.COMPOUND_ONLY
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.END

-- Test Case: msg_SequencerInitialise.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.END

-- Test Case: msg_SequencerInitialise.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.msg_SequencerInitialise.inst:5
TEST.END

-- Subprogram: msg_SequencerNewMsgQTimeoutUpdate

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.001
TEST.VALUE:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:5
TEST.END

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.002
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.VALUE:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.003
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.VALUE:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.004
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.VALUE:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.005
TEST.STUB:warn_msgSequencer.msg_SequencerRemove
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:0x80
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.VALUE:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.END

-- Subprogram: msg_SequencerRemove

-- Test Case: msg_SequencerRemove.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.001
TEST.STUB:warn_msgStore.msg_StoreRemove
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.002
TEST.STUB:warn_msgStore.msg_StoreRemove
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.003
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgStore.msg_StoreRemove
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.004
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgStore.msg_StoreRemove
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: msg_SequencerRemove.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.005
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: msg_SequencerRemove.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.006
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRemove.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.007
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: msg_SequencerRemove.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.008
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.009
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.010
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.011
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.012
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.013
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:5
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.014
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.015
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.016
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_FRONT_RIGHT_CORNER_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.017
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.017
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_RIGHT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.018
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.018
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_RIGHT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.return:MSG_WARNING_RIGHT_DRL_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.019
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.019
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_RIGHT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.020
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.020
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:2
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.021
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.021
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.022
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.022
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.023
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.023
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.024
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.024
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.025
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.025
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:128
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.026
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.026
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.END

-- Test Case: msg_SequencerRemove.027
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.027
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.END

-- Test Case: msg_SequencerRemove.028
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.028
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:128
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.END

-- Test Case: msg_SequencerRemove.029
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.029
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:0
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.030
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.030
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.MessageID:MSG_WARNING_RIGHT_DRL_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.return:MSG_WARNING_SUNROOF_NOT_LEARNED_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.031
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.031
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[2].seq_CurrentMessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_TURN_FRONT_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Subprogram: msg_SequencerRetrigger

-- Test Case: Retrigger_Invalid
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_Invalid
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: Retrigger_Invalid.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_Invalid.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: Retrigger_Invalid.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_Invalid.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.001
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.002
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.Invalid
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.Invalid
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.Invalid.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.Invalid.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.Invalid.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.Invalid.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRetrigger.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.001
TEST.VALUE:warn_msgSequencer.msg_SequencerRetrigger.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRetrigger.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Test Case: msg_SequencerRetrigger.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.003
TEST.END

-- Test Case: msg_SequencerRetrigger.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.003.001
TEST.END

-- Test Case: msg_SequencerRetrigger.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.003.002
TEST.END

-- Test Case: msg_SequencerRetrigger.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerRetrigger.MessageID:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRetrigger.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRetrigger.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerRetrigger.MessageID:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRetrigger.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRetrigger.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerRetrigger.MessageID:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.msg_SequencerRetrigger.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRetrigger.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.005
TEST.END

-- Test Case: msg_SequencerRetrigger.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.005.001
TEST.END

-- Test Case: msg_SequencerRetrigger.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.005.002
TEST.END

-- Subprogram: msg_SequencerSelectFirst

-- Test Case: msg_SequencerSelectFirst.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.001
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectFirst.p_inst:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.002
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectFirst.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.003
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectFirst.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.004
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:4
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:6
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.005
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:1
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.006
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:11
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Subprogram: msg_SequencerSelectNext

-- Test Case: msg_SequencerSelectNext.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:4
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectNext.return:0
TEST.END

-- Test Case: msg_SequencerSelectNext.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectNext.return:0
TEST.END

-- Test Case: msg_SequencerSelectNext.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.003
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectNext.p_inst:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectNext.return:0
TEST.END

-- Test Case: msg_SequencerSelectNext.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.004
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectNext.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectNext.return:0
TEST.END

-- Subprogram: msg_SequencerSelectPrevious

-- Test Case: msg_SequencerSelectPrevious.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.END

-- Test Case: msg_SequencerSelectPrevious.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.END

-- Test Case: msg_SequencerSelectPrevious.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.003
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.END

-- Test Case: msg_SequencerSelectPrevious.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.004
TEST.STUB:warn_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectPrevious.p_inst:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.ATTRIBUTES:warn_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerSelectPrevious.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.005
TEST.STUB:warn_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:5
TEST.VALUE:warn_msgSequencer.msg_SequencerSelectPrevious.p_inst:1
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.return:3
TEST.EXPECTED:warn_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.END

-- Subprogram: msg_SequencerShow

-- Test Case: msg_SequencerShow.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.END

-- Test Case: msg_SequencerShow.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_FRONT_LEFT_HIGH_BEAM_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.END

-- Test Case: msg_SequencerShow.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.007
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.007.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.007.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.008
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.008.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.008.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.009
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.009.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.009.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.009.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.009.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.010
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.010.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.010.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.010.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.010.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.011
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.011.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.011.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.011.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.011.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.012
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.012.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.012.001
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.012.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.012.002
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.013
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.END

-- Test Case: msg_SequencerShow.013.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.013.001
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.END

-- Test Case: msg_SequencerShow.013.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.013.002
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:5
TEST.END

-- Test Case: msg_SequencerShow.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.014
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.END

-- Test Case: msg_SequencerShow.014.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.014.001
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.END

-- Test Case: msg_SequencerShow.014.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.014.002
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:warn_msgSequencer.msg_SequencerShow.p_inst:0
TEST.END

-- Test Case: msg_SequencerShow.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.015
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_TURN_REAR_LEFT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.016
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_GP_CLOSE_ON_RAIN_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.017
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.017
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_GP_CLOSE_ON_AC_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.018
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.018
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_ELECTRONIC_HORN_FAIL_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerShow.p_inst:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:8
TEST.END

-- Subprogram: msg_SequencerUpdate

-- Test Case: No_Retrigger_after_timeout
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:No_Retrigger_after_timeout
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:MSG_EVENT_TIMEOUT,MSG_EVENT_ACTIVE,MSG_EVENT_SHOW
TEST.END

-- Test Case: Retrigger_after_timeout
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_after_timeout
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,16,8
TEST.END

-- Test Case: Retrigger_after_timeout_clear
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_after_timeout_clear
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:16,8
TEST.END

-- Test Case: Retrigger_before_timeout
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_before_timeout
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:MSG_EVENT_ACTIVE,MSG_EVENT_SHOW
TEST.END

-- Test Case: Retrigger_not_current_msg
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_not_current_msg
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerUpdate.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.001
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.002
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.inst:5
TEST.EXPECTED:warn_msgSequencer.msg_SequencerUpdate.inst:5
TEST.END

-- Test Case: msg_SequencerUpdate.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.003
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:128
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.Ignition:1
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerUpdate.inst:1
TEST.END

-- Test Case: msg_SequencerUpdate.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.004
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.005
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.006
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.007
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.008
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.009
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.010
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.011
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_FindActiveMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.012
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.013
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.014
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.Ignition:1
TEST.VALUE:warn_msgSequencer.msg_SequencerUpdate.inst:1
TEST.EXPECTED:warn_msgSequencer.msg_SequencerUpdate.Ignition:1
TEST.END

-- Test Case: msg_SequencerUpdate.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.015
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.END

-- Test Case: msg_SequencerUpdate.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.016
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.END

-- Test Case: msg_SequencerUpdate.017
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.017
TEST.END

-- Test Case: msg_SequencerUpdate.018
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.018
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:64,2,32,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.019
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.019
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:251
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:64,2,16,8
TEST.END

-- Test Case: msg_SequencerUpdate.020
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.020
TEST.STUB:warn_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.STUB:warn_msgSequencer.seq_GetNextMessage
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.STUB:warn_msgSequencer.seq_Callback
TEST.STUB:warn_msgStore.msg_StoreAdd
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:251
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:64,2,16,8
TEST.END

-- Subprogram: seq_Callback

-- Test Case: seq_Callback.Qualifier<255
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier<255.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier<255.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.001.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier<255.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.001.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier<255.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier<255.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.003
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier>255
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier>255
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier>255.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier>255.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier>255.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier>255.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.QualifierMax
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.QualifierMax.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.QualifierMax.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.001.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.QualifierMax.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.001.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.QualifierMax.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.QualifierMax.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.003
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.invalidAction
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidAction
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.invalidAction.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidAction.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.invalidAction.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidAction.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.invalidEventCallback
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidEventCallback
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.invalidEventCallback.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidEventCallback.001
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.invalidEventCallback.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidEventCallback.002
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.invalidMessageID
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidMessageID
TEST.VALUE:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.END

-- Test Case: seq_Callback.invalidMessageID.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidMessageID.001
TEST.VALUE:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.END

-- Test Case: seq_Callback.invalidMessageID.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidMessageID.002
TEST.VALUE:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.VALUE:warn_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:warn_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.END

-- Subprogram: seq_Delete

-- Test Case: DELETE_MSG_FROM_SEQ_Q
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:miUndefined
TEST.END

-- Test Case: DELETE_MSG_FROM_SEQ_Q.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.seq_Delete.Index:5
TEST.VALUE:warn_msgSequencer.seq_Delete.inst:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:warn_msgSequencer.seq_Delete.inst:6
TEST.END

-- Test Case: DELETE_MSG_FROM_SEQ_Q.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:miUndefined
TEST.END

-- Test Case: DELETE_MSG_FROM_SEQ_Q.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:warn_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:miUndefined
TEST.END

-- Test Case: seq_Delete.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:seq_Delete.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.seq_Delete.Index:1
TEST.VALUE:warn_msgSequencer.seq_Delete.inst:1
TEST.END

-- Subprogram: seq_FindActiveMessage

-- Test Case: seq_FindActiveMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.END

-- Test Case: seq_FindActiveMessage.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.END

-- Test Case: seq_FindActiveMessage.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.END

-- Test Case: seq_FindActiveMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.END

-- Test Case: seq_FindActiveMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.END

-- Test Case: seq_FindActiveMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.END

-- Test Case: seq_FindActiveMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:7
TEST.END

-- Test Case: seq_FindActiveMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:7
TEST.END

-- Test Case: seq_FindActiveMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:7
TEST.END

-- Test Case: seq_FindActiveMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.END

-- Test Case: seq_FindActiveMessage.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.END

-- Test Case: seq_FindActiveMessage.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.END

-- Test Case: seq_FindActiveMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[7]:4
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Category:ePriority6
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.Message:MSG_WARNING_DRIVE_SUMMARY_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_FindActiveMessage.inst:1
TEST.END

-- Subprogram: seq_FindFirstIndex

-- Test Case: seq_FindFirstIndex.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.001
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:1
TEST.END

-- Test Case: seq_FindFirstIndex.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.001.001
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:1
TEST.END

-- Test Case: seq_FindFirstIndex.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.001.002
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:1
TEST.END

-- Test Case: seq_FindFirstIndex.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.002
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: seq_FindFirstIndex.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.002.001
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: seq_FindFirstIndex.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.002.002
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: seq_FindFirstIndex.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.003
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: seq_FindFirstIndex.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.003.001
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: seq_FindFirstIndex.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.003.002
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Subprogram: seq_FindNextIndex

-- Test Case: Index_not_found
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:Index_not_found
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.END

-- Test Case: Index_not_found.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:Index_not_found.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.END

-- Test Case: Index_not_found.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:Index_not_found.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.END

-- Test Case: seq_FindNextIndex.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:2
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:2
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:2
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:0
TEST.END

-- Test Case: seq_FindNextIndex.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:0
TEST.END

-- Test Case: seq_FindNextIndex.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:0
TEST.END

-- Test Case: seq_FindNextIndex.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..3]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:4
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.END

-- Test Case: seq_FindNextIndex.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:45
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:43
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_FindNextIndex.return:45
TEST.END

-- Test Case: seq_FindNextIndex.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.CategoryMask:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.inst:1
TEST.END

-- Subprogram: seq_FindPreviousIndex

-- Test Case: Index_not_found
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:Index_not_found
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:7
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:7
TEST.END

-- Test Case: Index_not_found.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:Index_not_found.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:7
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:7
TEST.END

-- Test Case: Index_not_found.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:Index_not_found.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:7
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:0
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:7
TEST.END

-- Test Case: seq_FindPreviousIndex.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.001
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:2
TEST.END

-- Test Case: seq_FindPreviousIndex.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.001.001
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:2
TEST.END

-- Test Case: seq_FindPreviousIndex.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.001.002
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:2
TEST.END

-- Test Case: seq_FindPreviousIndex.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.002
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.002.001
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.002.002
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.003
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.003.001
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.003.002
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:0
TEST.END

-- Test Case: seq_FindPreviousIndex.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:0
TEST.END

-- Test Case: seq_FindPreviousIndex.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:0
TEST.END

-- Test Case: seq_FindPreviousIndex.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:5
TEST.END

-- Test Case: seq_FindPreviousIndex.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:5
TEST.END

-- Test Case: seq_FindPreviousIndex.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.VALUE:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_FindPreviousIndex.return:5
TEST.END

-- Subprogram: seq_GetCategories

-- Test Case: seq_GetCategories.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:2
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:2
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:2
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:10
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:4
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:4
TEST.END

-- Test Case: seq_GetCategories.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:10
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:4
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:4
TEST.END

-- Test Case: seq_GetCategories.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:10
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:4
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:4
TEST.END

-- Test Case: seq_GetCategories.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:7
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:7
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:7
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.VALUE:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.008.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.VALUE:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.008.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:warn_msgSequencer.seq_GetCategories.Threshold:3
TEST.VALUE:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Subprogram: seq_GetLowerCategoryMessage

-- Test Case: seq_GetLowerCategoryMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.001
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.001.001
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.001.002
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.002
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.002.001
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.002.002
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.003
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.003.001
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.003.002
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.004
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.004.001
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.004.002
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.005
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.005.001
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.005.002
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.006
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:6
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.006.001
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:6
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.006.002
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:6
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:0
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:0
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.010
TEST.STUB:warn_msgSequencer.seq_GetNewMessage
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_TURN_REAR_RIGHT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:ePriority0
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.return:MSG_WARNING_TYRE_FILL_ASSIST_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:MSG_WARNING_TYRE_FILL_ASSIST_ID_INDEX
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.011
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_TURN_REAR_RIGHT_LAMP_FAILURE_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.Category:ePriority0
TEST.VALUE:warn_msgSequencer.seq_GetLowerCategoryMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Subprogram: seq_GetNewMessage

-- Test Case: seq_GetNewMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.001
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.Category:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.END

-- Test Case: seq_GetNewMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.Category:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:8
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.Category:ePriority0
TEST.VALUE:warn_msgSequencer.seq_GetNewMessage.inst:1
TEST.END

-- Subprogram: seq_GetNextMessage

-- Test Case: seq_GetNextMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:20
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[7..8]:20
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.return:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[7]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:4
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:ePriority7
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Message:MSG_WARNING_DRIVE_SUMMARY_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.return:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:MSG_WARNING_WELCOME_ID_INDEX
TEST.END

-- Test Case: seq_GetNextMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1..3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[7]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:4
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:ePriority7
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Message:MSG_WARNING_DRIVE_SUMMARY_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.return:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:MSG_WARNING_WELCOME_ID_INDEX
TEST.END

-- Test Case: seq_GetNextMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[7]:25
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:ePriority7
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.AC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.AC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.AC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.AC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.AC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.AC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetNextMessage.ACAll
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Test Case: seq_GetNextMessage.NAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Test Case: seq_GetNextMessage.NAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Test Case: seq_GetNextMessage.NAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Test Case: seq_GetNextMessage.NAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Test Case: seq_GetNextMessage.NAC.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.END

-- Subprogram: seq_GetTopMostMessage

-- Test Case: seq_GetTopMostMessage.ACNew
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.END

-- Test Case: seq_GetTopMostMessage.NACInCurCat
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACInCurCat
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetTopMostMessage.NACInCurCat.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACInCurCat.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetTopMostMessage.NACInCurCat.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACInCurCat.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.END

-- Test Case: seq_GetTopMostMessage.NACTop
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACTop
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NACTop.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACTop.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NACTop.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACTop.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NACWOCycle
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACWOCycle
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NACWOCycle.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACWOCycle.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NACWOCycle.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACWOCycle.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NewTop
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NewTop
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NewTop.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NewTop.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NewTop.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NewTop.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.END

-- Test Case: seq_GetTopMostMessage.NoAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.NoAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.NoAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.InvalidInst
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.InvalidInst
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.InvalidInst.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.InvalidInst.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.InvalidInst.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.InvalidInst.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetTopMostMessage.inst:0
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.END

-- Subprogram: seq_GetViewCount

-- Test Case: seq_GetViewCount.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:1
TEST.END

-- Test Case: seq_GetViewCount.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:1
TEST.END

-- Test Case: seq_GetViewCount.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:1
TEST.END

-- Test Case: seq_GetViewCount.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:255
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:255
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.CategoryMask:255
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.CategoryMask:1
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewCount.return:3
TEST.END

-- Subprogram: seq_GetViewIndex

-- Test Case: seq_GetViewIndex.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:1
TEST.END

-- Test Case: seq_GetViewIndex.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:1
TEST.END

-- Test Case: seq_GetViewIndex.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:1
TEST.END

-- Test Case: seq_GetViewIndex.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:3
TEST.END

-- Test Case: seq_GetViewIndex.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:3
TEST.END

-- Test Case: seq_GetViewIndex.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:3
TEST.END

-- Test Case: seq_GetViewIndex.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.008.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.008.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.END

-- Test Case: seq_GetViewIndex.009.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.009.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.END

-- Test Case: seq_GetViewIndex.009.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.009.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.END

-- Test Case: seq_GetViewIndex.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.010
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.010.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.010.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.010.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.010.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.011
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.011.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.011.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.011.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.011.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.012
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.013
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[8]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.CategoryMask:3
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.return:3
TEST.END

-- Subprogram: seq_GetViewMessage

-- Test Case: seq_GetViewMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.003
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.END

-- Test Case: seq_GetViewMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.003.001
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.END

-- Test Case: seq_GetViewMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.003.002
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.END

-- Test Case: seq_GetViewMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.004
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.END

-- Test Case: seq_GetViewMessage.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.004.001
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.END

-- Test Case: seq_GetViewMessage.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.004.002
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.seq_GetViewMessage.inst:5
TEST.END

-- Subprogram: seq_IndexDown

-- Test Case: seq_IndexDown.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.END

-- Test Case: seq_IndexDown.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.END

-- Test Case: seq_IndexDown.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.END

-- Test Case: seq_IndexDown.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:49
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:99
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:149
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:199
TEST.END

-- Test Case: seq_IndexDown.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:49
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:99
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:149
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:199
TEST.END

-- Test Case: seq_IndexDown.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:49
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:99
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:149
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:199
TEST.END

-- Test Case: seq_IndexDown.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgSequencer.seq_IndexDown.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.inst:5
TEST.END

-- Test Case: seq_IndexDown.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgSequencer.seq_IndexDown.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.inst:5
TEST.END

-- Test Case: seq_IndexDown.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgSequencer.seq_IndexDown.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.inst:5
TEST.END

-- Subprogram: seq_IndexUp

-- Test Case: seq_IndexUp.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:200
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:300
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:400
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:101
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:201
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:301
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:401
TEST.END

-- Test Case: seq_IndexUp.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:200
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:300
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:400
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:101
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:201
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:301
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:401
TEST.END

-- Test Case: seq_IndexUp.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:100
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:200
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:300
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:400
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:101
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:201
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:301
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:401
TEST.END

-- Test Case: seq_IndexUp.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.VALUE:warn_msgSequencer.seq_IndexUp.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.inst:5
TEST.END

-- Test Case: seq_IndexUp.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.VALUE:warn_msgSequencer.seq_IndexUp.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.inst:5
TEST.END

-- Test Case: seq_IndexUp.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.VALUE:warn_msgSequencer.seq_IndexUp.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.inst:5
TEST.END

-- Subprogram: seq_InitIndex

-- Test Case: seq_InitIndex.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.001
TEST.VALUE:warn_msgSequencer.seq_InitIndex.inst:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.001.001
TEST.VALUE:warn_msgSequencer.seq_InitIndex.inst:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.001.002
TEST.VALUE:warn_msgSequencer.seq_InitIndex.inst:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.003
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Subprogram: seq_InitList

-- Test Case: seq_InitList.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..10]:miUndefined
TEST.END

-- Test Case: seq_InitList.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.001
TEST.VALUE:warn_msgSequencer.seq_InitList.inst:5
TEST.END

-- Test Case: seq_InitList.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.001.001
TEST.VALUE:warn_msgSequencer.seq_InitList.inst:5
TEST.END

-- Test Case: seq_InitList.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.001.002
TEST.VALUE:warn_msgSequencer.seq_InitList.inst:5
TEST.END

-- Test Case: seq_InitList.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..10]:miUndefined
TEST.END

-- Test Case: seq_InitList.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.003
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..10]:miUndefined
TEST.END

-- Subprogram: seq_InitView

-- Test Case: seq_InitView.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.001
TEST.VALUE:warn_msgSequencer.seq_InitView.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.001.001
TEST.VALUE:warn_msgSequencer.seq_InitView.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.001.002
TEST.VALUE:warn_msgSequencer.seq_InitView.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.002
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.003
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Subprogram: seq_Insert

-- Test Case: INSERT_MSG_INTO_SEQ_Q
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.001.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.001.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.002.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.002.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_Insert.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:seq_Insert.001
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:1
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_Insert.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Test Case: seq_Insert.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:seq_Insert.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[8]:42
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:1
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_Insert.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:seq_Insert.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[8]:5
TEST.VALUE:warn_msgSequencer.seq_Insert.Index:43
TEST.VALUE:warn_msgSequencer.seq_Insert.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:43
TEST.END

-- Subprogram: seq_InsertMessage

-- Test Case: seq_InsertMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.END

-- Test Case: seq_InsertMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_DOOR_OPEN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.END

-- Test Case: seq_InsertMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.003
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:128
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:2
TEST.END

-- Test Case: seq_InsertMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.004
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:3
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:4
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:4
TEST.END

-- Test Case: seq_InsertMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.005
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:3
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.006
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:3
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.007
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.008
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:4
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:4
TEST.END

-- Test Case: seq_InsertMessage.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.009
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.010
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.END

-- Test Case: seq_InsertMessage.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.011
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.END

-- Test Case: seq_InsertMessage.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.012
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.END

-- Test Case: seq_InsertMessage.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.013
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[2]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[3]:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:4
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x4000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.END

-- Test Case: seq_InsertMessage.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.014
TEST.END

-- Test Case: seq_InsertMessage.Multi
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[10].Options:INPUT_BASE=16
TEST.END

-- Test Case: seq_InsertMessage.Multi.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.002
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:5
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:0xFFFFFFFF
TEST.END

-- Test Case: seq_InsertMessage.Multi.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.004
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.005
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:0xFFFFFFFF
TEST.END

-- Test Case: seq_InsertMessage.Multi.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.006
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.007
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[10].Options:INPUT_BASE=16
TEST.END

-- Test Case: seq_InsertMessage.Multi.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.008
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.ATTRIBUTES:warn_msgSequencer.<<GLOBAL>>.messageList[10].Options:INPUT_BASE=16
TEST.END

-- Test Case: seq_InsertMessage.Multi.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.009
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcMaximum
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcMaximum
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:0xFFFFFFFF
TEST.END

-- Test Case: seq_InsertMessage.Multi.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.010
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:5
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.011
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority0
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.END

-- Test Case: seq_InsertMessage.Multi.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.012
TEST.STUB:warn_msgSequencer.seq_IndexUp
TEST.STUB:warn_msgSequencer.seq_Insert
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:MSG_WARNING_REAR_INITIAL_SEAT_BELT_REMINDER_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:3
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Category:ePriority0
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:warn_msgSequencer.seq_InsertMessage.return:2
TEST.END

-- Subprogram: seq_RemoveHoldMessage

-- Test Case: Hold_msg_is_undefined
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:Hold_msg_is_undefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: Hold_msg_is_undefined.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:Hold_msg_is_undefined.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: Hold_msg_is_undefined.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:Hold_msg_is_undefined.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:(2)miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.001
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.001.001
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.001.002
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:(2)miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.003
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:(2)miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.003.001
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.003.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.003.001.001
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.003.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.003.001.002
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4,0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:1
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.001
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4,0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:1
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.002
TEST.STUB:warn_msgSequencer.seq_UpdateViewer
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:1
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:4,0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_GetViewIndex.inst:1
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.Invalid
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.Invalid
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:5
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.Invalid.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.Invalid.001
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:5
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.Invalid.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.Invalid.002
TEST.STUB:warn_msgSequencer.seq_RemoveMessage
TEST.VALUE:warn_msgSequencer.seq_RemoveHoldMessage.inst:5
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.return:15
TEST.END

-- Subprogram: seq_RemoveMessage

-- Test Case: seq_RemoveMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.001
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.001.001
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.001.002
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.002
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.002.001
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.002.002
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.003
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.003.001
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.003.002
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.004
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.004.001
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.004.002
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.005
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.005.001
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.005.002
TEST.STUB:warn_msgSequencer.seq_IndexDown
TEST.STUB:warn_msgSequencer.seq_Delete
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:warn_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:warn_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:7
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.008
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.008.001
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.008.002
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.009
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.009
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.009.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.009.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.009.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.009.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.010
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.010
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.010.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.010.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.010.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.010.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.011
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.011
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.011.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.011.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.011.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.011.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.012
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.012
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.013
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.013
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.014
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.014
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_TURN_FRONT_RIGHT_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.015
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.015
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_SYSTEM_CHECK_WARN_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.016
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.016
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:warn_msgSequencer.seq_RemoveMessage.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.EXPECTED:warn_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Subprogram: seq_SetViewMessage

-- Test Case: seq_SetViewMessage.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.001
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.001.001
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.001.002
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:3
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:4
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:10
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.002
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:9
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:1000
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.002.001
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:9
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:1000
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.002.002
TEST.STUB:warn_msgSequencer.seq_GetViewCount
TEST.STUB:warn_msgSequencer.seq_GetViewIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:9
TEST.VALUE:warn_msgSequencer.seq_GetViewCount.return:1000
TEST.VALUE:warn_msgSequencer.seq_GetViewIndex.return:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:46
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1000
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.003
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.003.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.003.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.004
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.004.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.004.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.005.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.005.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.005.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.005.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:2
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.006
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.006.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.006.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.006.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.006.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.007
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.007
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.END

-- Test Case: seq_SetViewMessage.007.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.007.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.END

-- Test Case: seq_SetViewMessage.007.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.007.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:5
TEST.END

-- Test Case: seq_SetViewMessage.008
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.008
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Status:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.END

-- Test Case: seq_SetViewMessage.008.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.008.001
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Status:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.END

-- Test Case: seq_SetViewMessage.008.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.008.002
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Position:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Count:0
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Status:7
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.InstanceID:1
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.inst:1
TEST.END

-- Subprogram: seq_UpdateViewer

-- Test Case: seq_UpdateViewer.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.END

-- Test Case: seq_UpdateViewer.001.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.001.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.END

-- Test Case: seq_UpdateViewer.001.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.001.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.END

-- Test Case: seq_UpdateViewer.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.END

-- Test Case: seq_UpdateViewer.002.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.002.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.END

-- Test Case: seq_UpdateViewer.002.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.002.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.END

-- Test Case: seq_UpdateViewer.003
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.003
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:11
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.END

-- Test Case: seq_UpdateViewer.003.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.003.001
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:11
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.END

-- Test Case: seq_UpdateViewer.003.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.003.002
TEST.STUB:warn_msgSequencer.seq_SetViewMessage
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MessageID:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:<<MAX>>
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:11
TEST.EXPECTED:warn_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.END

-- Test Case: seq_UpdateViewer.004
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.004
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0xFF
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:255
TEST.END

-- Test Case: seq_UpdateViewer.004.001
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.004.001
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0xFF
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:255
TEST.END

-- Test Case: seq_UpdateViewer.004.002
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.004.002
TEST.STUB:warn_msgSequencer.seq_FindFirstIndex
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:0xFF
TEST.VALUE:warn_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:4
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:255
TEST.END

-- Test Case: seq_UpdateViewer.005
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.005
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Id:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MessageID:miMaximum
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.END

-- Test Case: seq_UpdateViewer.006
TEST.UNIT:warn_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.006
TEST.STUB:warn_msgSequencer.seq_FindNextIndex
TEST.VALUE:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Id:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.VALUE:warn_msgSequencer.seq_FindNextIndex.return:20
TEST.EXPECTED:warn_msgSequencer.seq_UpdateViewer.inst:1
TEST.END

-- Unit: warn_msgStore

-- Subprogram: msg_StorAckWrngRepTimerControl

-- Test Case: msg_StorAckWrngRepTimerControl.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.001
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:5
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.002
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.003
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_PAUSE
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.004
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESUME
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESUME
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.005
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESTART
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESTART
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.007
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.008
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:10
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.009
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESTART
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.END

-- Subprogram: msg_StorAckWrngRepUpdate

-- Test Case: msg_StorAckWrngRepUpdate.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.001
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:5
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 88>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:(22)"0"
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:(22)"0"
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:(22)1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 2>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"0"
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"0"
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.007
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:128
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.008
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.009
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_TmrSupport_Check_Timer.return:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.010
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration[1]:255
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration[1]:255
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.011
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration[1]:254
TEST.VALUE:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Subprogram: msg_StoreAdd

-- Test Case: msg_StoreAdd.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.001
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:6
TEST.END

-- Test Case: msg_StoreAdd.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.002
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:2
TEST.ATTRIBUTES:warn_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreAdd.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.003
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:6
TEST.END

-- Test Case: msg_StoreAdd.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:miUndefined
TEST.END

-- Test Case: msg_StoreAdd.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.END

-- Test Case: msg_StoreAdd.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.006
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:6
TEST.END

-- Test Case: msg_StoreAdd.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.007
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:5
TEST.END

-- Test Case: msg_StoreAdd.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.END

-- Test Case: msg_StoreAdd.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.009
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:""
TEST.EXPECTED:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:6
TEST.END

-- Test Case: msg_StoreAdd.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.010
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexUp
TEST.STUB:warn_msgStore.stor_Insert
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.END

-- Test Case: msg_StoreAdd.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.011
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.012
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.012
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.013
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.013
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[3][0]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[3][1]:1
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.014
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.014
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.015
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.015
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:8
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.016
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.016
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.017
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.017
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.018
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.018
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.019
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.019
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FRONT_LEFT_HIGH_BEAM_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_FRONT_LEFT_HIGH_BEAM_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_StoreAdd.020
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.020
TEST.VALUE:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreAdd.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.END

-- Subprogram: msg_StoreGetCurrent

-- Test Case: msg_StoreGetCurrent.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.001
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.001.001
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.001.002
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.002
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.002.001
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.002.002
TEST.VALUE:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Subprogram: msg_StoreInitialise

-- Test Case: msg_StoreInitialise.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.001
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMask:0xFFFFFFFF
TEST.END

-- Test Case: msg_StoreInitialise.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.001.001
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMask:0xFFFFFFFF
TEST.END

-- Test Case: msg_StoreInitialise.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.001.002
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMask:0xFFFFFFFF
TEST.END

-- Test Case: msg_StoreInitialise.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.002
TEST.VALUE:warn_msgStore.msg_StoreInitialise.inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreInitialise.inst:5
TEST.END

-- Test Case: msg_StoreInitialise.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.002.001
TEST.VALUE:warn_msgStore.msg_StoreInitialise.inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreInitialise.inst:5
TEST.END

-- Test Case: msg_StoreInitialise.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.002.002
TEST.VALUE:warn_msgStore.msg_StoreInitialise.inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreInitialise.inst:5
TEST.END

-- Subprogram: msg_StoreIsMsgPresentInStoreQueue

-- Test Case: msg_StoreIsMsgPresentInStoreQueue.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:msg_StoreIsMsgPresentInStoreQueue.001
TEST.VALUE:warn_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:MSG_WARNING_WELCOME_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreIsMsgPresentInStoreQueue.return:0
TEST.END

-- Test Case: msg_StoreIsMsgPresentInStoreQueue.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:msg_StoreIsMsgPresentInStoreQueue.002
TEST.VALUE:warn_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:miMaximum
TEST.EXPECTED:warn_msgStore.msg_StoreIsMsgPresentInStoreQueue.return:0
TEST.END

-- Test Case: msg_StoreIsMsgPresentInStoreQueue.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:msg_StoreIsMsgPresentInStoreQueue.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_StoredFlags:<<malloc 5>>
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_StoredFlags:"0x00"
TEST.VALUE:warn_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:MSG_WARNING_BRAKE_LAMP_FAILURE_ID_INDEX
TEST.END

-- Subprogram: msg_StorePurgeFromList

-- Test Case: msg_StorePurgeFromList.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:3
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:3
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:3
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0x0
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0x0
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0x0
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.END

-- Test Case: msg_StorePurgeFromList.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.END

-- Test Case: msg_StorePurgeFromList.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:5
TEST.END

-- Test Case: msg_StorePurgeFromList.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:3
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:3
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:3
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.FilterOptions:5
TEST.VALUE:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:warn_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Subprogram: msg_StoreRemove

-- Test Case: msg_StoreRemove.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.001
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:miMaximum
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.002
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:miUndefined
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.ATTRIBUTES:warn_msgStore.<<GLOBAL>>.messageList[2].EventQualifier:INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreRemove.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.004
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.STUB:warn_msgStore.stor_IndexDown
TEST.STUB:warn_msgStore.stor_Delete
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:4
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:1
TEST.EXPECTED:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_Delete.Index:3
TEST.ATTRIBUTES:warn_msgStore.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreRemove.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.END

-- Test Case: msg_StoreRemove.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.006
TEST.STUB:warn_msgStore.stor_UpdateViewer
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:0
TEST.END

-- Test Case: msg_StoreRemove.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.END

-- Test Case: msg_StoreRemove.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:""
TEST.END

-- Test Case: msg_StoreRemove.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.009
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.010
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.011
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.012
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.012
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.013
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.013
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:5
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.014
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.014
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:8
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.015
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.015
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:8
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FUEL_LID_OPEN_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.016
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.016
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FRONT_LEFT_HIGH_BEAM_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_FRONT_LEFT_HIGH_BEAM_FAILURE_ID_INDEX
TEST.END

-- Test Case: msg_StoreRemove.017
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.017
TEST.VALUE:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.MessageID:MSG_WARNING_REAR_PARK_LAMP_FAILURE_ID_INDEX
TEST.EXPECTED:warn_msgStore.msg_StoreRemove.return:0
TEST.END

-- Subprogram: msg_StoreSelectFirst

-- Test Case: msg_StoreSelectFirst.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.001.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.001.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.002
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:11
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.002.001
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:11
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.002.002
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:11
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.003
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.003.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.003.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.004
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.004.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.004.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:15
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.005
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.msg_StoreSelectFirst.p_inst:1
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.006
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.VALUE:warn_msgStore.msg_StoreSelectFirst.p_inst:1
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Subprogram: msg_StoreSelectNext

-- Test Case: msg_StoreSelectNext.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.001.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.001.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.002.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.002.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.003
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.003.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.003.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.004
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.004.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.004.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindFirstIndex
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.005
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:7
TEST.VALUE:warn_msgStore.msg_StoreSelectNext.p_inst:1
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Subprogram: msg_StoreSelectPrevious

-- Test Case: msg_StoreSelectPrevious.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.001.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.001.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.002.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.002.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.003
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.003.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.003.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.004
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.004.001
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.004.002
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.005
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:7
TEST.VALUE:warn_msgStore.msg_StoreSelectPrevious.p_inst:1
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Subprogram: stor_Delete

-- Test Case: stor_Delete.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:3
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:3
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:3
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:2
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:2
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:2
TEST.VALUE:warn_msgStore.stor_Delete.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:5
TEST.EXPECTED:warn_msgStore.stor_Delete.inst:5
TEST.END

-- Test Case: stor_Delete.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.005.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:5
TEST.EXPECTED:warn_msgStore.stor_Delete.inst:5
TEST.END

-- Test Case: stor_Delete.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.005.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_Delete.Index:1
TEST.VALUE:warn_msgStore.stor_Delete.inst:5
TEST.EXPECTED:warn_msgStore.stor_Delete.inst:5
TEST.END

-- Test Case: stor_Delete.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:3
TEST.VALUE:warn_msgStore.stor_Delete.Index:0
TEST.VALUE:warn_msgStore.stor_Delete.inst:1
TEST.EXPECTED:warn_msgStore.stor_Delete.inst:1
TEST.END

-- Subprogram: stor_FindFirstIndex

-- Test Case: stor_FindFirstIndex.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.001
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: stor_FindFirstIndex.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.001.001
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: stor_FindFirstIndex.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.001.002
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: stor_FindFirstIndex.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.002
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: stor_FindFirstIndex.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.002.001
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: stor_FindFirstIndex.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.002.002
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: stor_FindFirstIndex.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.003
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:12
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:12
TEST.END

-- Test Case: stor_FindFirstIndex.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.003.001
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:12
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:12
TEST.END

-- Test Case: stor_FindFirstIndex.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.003.002
TEST.STUB:warn_msgStore.stor_FindNextIndex
TEST.VALUE:warn_msgStore.stor_FindFirstIndex.CategoryMask:12
TEST.VALUE:warn_msgStore.stor_FindNextIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindFirstIndex.return:500
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:12
TEST.END

-- Subprogram: stor_FindNextIndex

-- Test Case: stor_FindNextIndex.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:1
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:0x3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:1
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:1
TEST.END

-- Test Case: stor_FindNextIndex.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.009
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:7
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:1
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:0x3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:1
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:5
TEST.END

-- Test Case: stor_FindNextIndex.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.010
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][7]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][8]:7
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:0
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:0x3
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][7]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][8]:7
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:5
TEST.END

-- Test Case: stor_FindNextIndex.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.011
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:7
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][7]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][8]:9
TEST.VALUE:warn_msgStore.stor_FindNextIndex.Start:0
TEST.VALUE:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][7]:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][8]:9
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.ATTRIBUTES:warn_msgStore.stor_FindNextIndex.CategoryMask:INPUT_BASE=16
TEST.END

-- Test Case: stor_FindNextIndex.012
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.012
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:43
TEST.VALUE:warn_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Subprogram: stor_FindPreviousIndex

-- Test Case: stor_FindPreviousIndex.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:0
TEST.END

-- Test Case: stor_FindPreviousIndex.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:0
TEST.END

-- Test Case: stor_FindPreviousIndex.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:0
TEST.END

-- Test Case: stor_FindPreviousIndex.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:1
TEST.END

-- Test Case: stor_FindPreviousIndex.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:1
TEST.END

-- Test Case: stor_FindPreviousIndex.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:1
TEST.END

-- Test Case: stor_FindPreviousIndex.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.003
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.003.001
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.003.002
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.004
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.END

-- Test Case: stor_FindPreviousIndex.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.004.001
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.END

-- Test Case: stor_FindPreviousIndex.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.004.002
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.inst:5
TEST.END

-- Test Case: stor_FindPreviousIndex.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:32
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.005.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:32
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.005.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.Start:32
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Subprogram: stor_GetCategories

-- Test Case: stor_GetCategories.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:8
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:1
TEST.END

-- Test Case: stor_GetCategories.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:8
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:1
TEST.END

-- Test Case: stor_GetCategories.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:8
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:1
TEST.END

-- Test Case: stor_GetCategories.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:6
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:2
TEST.END

-- Test Case: stor_GetCategories.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:6
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:2
TEST.END

-- Test Case: stor_GetCategories.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:6
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:2
TEST.END

-- Test Case: stor_GetCategories.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:4
TEST.END

-- Test Case: stor_GetCategories.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:4
TEST.END

-- Test Case: stor_GetCategories.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:5
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:10
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:4
TEST.END

-- Test Case: stor_GetCategories.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:15
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:100
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:15
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:8
TEST.END

-- Test Case: stor_GetCategories.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:15
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:100
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:15
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:8
TEST.END

-- Test Case: stor_GetCategories.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:15
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:100
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:15
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:8
TEST.END

-- Test Case: stor_GetCategories.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:20
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:16
TEST.END

-- Test Case: stor_GetCategories.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.005.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:20
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:16
TEST.END

-- Test Case: stor_GetCategories.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.005.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:50
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:20
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:16
TEST.END

-- Test Case: stor_GetCategories.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.006.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.006.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.006.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.006.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.VALUE:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.007.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.007.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.VALUE:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.007.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.007.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:warn_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.VALUE:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetCategories.return:0
TEST.END

-- Subprogram: stor_GetViewCount

-- Test Case: stor_GetViewCount.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:<<MAX>>
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.005.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.005.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.006.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.006.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.006.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.006.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:0,1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.007.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.007.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:0,1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.007.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.007.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:0,1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:1
TEST.END

-- Test Case: stor_GetViewCount.008.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.008.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:1
TEST.END

-- Test Case: stor_GetViewCount.008.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.008.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:1
TEST.END

-- Test Case: stor_GetViewCount.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.009
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.009.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.009.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.009.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.009.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.010
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:7
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.011
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:7
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:5
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:7
TEST.END

-- Test Case: stor_GetViewCount.012
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.012
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:7
TEST.VALUE:warn_msgStore.stor_GetViewCount.CategaoryMask:5
TEST.VALUE:warn_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewCount.return:6
TEST.END

-- Subprogram: stor_GetViewIndex

-- Test Case: stor_GetViewIndex.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:1
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:1
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:1
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.005
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.005.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.005.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.006
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.006.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.006.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.006.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.006.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.007.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.007.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.007.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.007.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.008.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.008.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.008.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.008.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.009
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:3
TEST.END

-- Test Case: stor_GetViewIndex.009.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.009.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:3
TEST.END

-- Test Case: stor_GetViewIndex.009.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.009.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:3
TEST.END

-- Test Case: stor_GetViewIndex.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.010
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.010.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.010.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.010.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.010.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.011
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.011.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.011.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.011.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.011.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.012
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.012
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:8
TEST.VALUE:warn_msgStore.stor_GetViewIndex.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.013
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.013
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:8
TEST.VALUE:warn_msgStore.stor_GetViewIndex.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:3
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:8
TEST.END

-- Test Case: stor_GetViewIndex.014
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.014
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.015
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.015
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][8]:8
TEST.VALUE:warn_msgStore.stor_GetViewIndex.MessageID:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.VALUE:warn_msgStore.stor_GetViewIndex.CategoryMask:3
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:1
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.return:7
TEST.END

-- Subprogram: stor_IndexDown

-- Test Case: stor_IndexDown.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:9
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:19
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:29
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:39
TEST.END

-- Test Case: stor_IndexDown.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:9
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:19
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:29
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:39
TEST.END

-- Test Case: stor_IndexDown.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:9
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:19
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:29
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:39
TEST.END

-- Test Case: stor_IndexDown.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexDown.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.EXPECTED:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_IndexDown.inst:5
TEST.END

-- Test Case: stor_IndexDown.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexDown.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.EXPECTED:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_IndexDown.inst:5
TEST.END

-- Test Case: stor_IndexDown.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexDown.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.EXPECTED:warn_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:warn_msgStore.stor_IndexDown.inst:5
TEST.END

-- Subprogram: stor_IndexUp

-- Test Case: stor_IndexUp.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:11
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:21
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:31
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:41
TEST.END

-- Test Case: stor_IndexUp.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:11
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:21
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:31
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:41
TEST.END

-- Test Case: stor_IndexUp.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:11
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:21
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:31
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:41
TEST.END

-- Test Case: stor_IndexUp.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexUp.inst:5
TEST.EXPECTED:warn_msgStore.stor_IndexUp.inst:5
TEST.END

-- Test Case: stor_IndexUp.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexUp.inst:5
TEST.EXPECTED:warn_msgStore.stor_IndexUp.inst:5
TEST.END

-- Test Case: stor_IndexUp.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:warn_msgStore.stor_IndexUp.BaseCategory:2
TEST.VALUE:warn_msgStore.stor_IndexUp.inst:5
TEST.EXPECTED:warn_msgStore.stor_IndexUp.inst:5
TEST.END

-- Subprogram: stor_InitIndex

-- Test Case: stor_InitIndex.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.001
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.001.001
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.001.002
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.002
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.002.001
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.002.002
TEST.VALUE:warn_msgStore.stor_InitIndex.inst:5
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Subprogram: stor_InitList

-- Test Case: stor_InitList.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.001
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.001.001
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.001.002
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.002
TEST.VALUE:warn_msgStore.stor_InitList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.002.001
TEST.VALUE:warn_msgStore.stor_InitList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.002.002
TEST.VALUE:warn_msgStore.stor_InitList.inst:1
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][8]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][9]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][10]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][11]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][12]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][13]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][14]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[1][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.003
TEST.VALUE:warn_msgStore.stor_InitList.inst:5
TEST.END

-- Test Case: stor_InitList.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.003.001
TEST.VALUE:warn_msgStore.stor_InitList.inst:5
TEST.END

-- Test Case: stor_InitList.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.003.002
TEST.VALUE:warn_msgStore.stor_InitList.inst:5
TEST.END

-- Subprogram: stor_Insert

-- Test Case: stor_Insert.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.VALUE:warn_msgStore.stor_Insert.Index:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:0
TEST.END

-- Test Case: stor_Insert.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.001.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.VALUE:warn_msgStore.stor_Insert.Index:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:0
TEST.END

-- Test Case: stor_Insert.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.001.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.VALUE:warn_msgStore.stor_Insert.Index:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:0
TEST.END

-- Test Case: stor_Insert.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.002.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.002.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.003
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.003.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.003.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.END

-- Test Case: stor_Insert.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.004
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.VALUE:warn_msgStore.stor_Insert.Value:miMaximum
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Value:miMaximum
TEST.END

-- Test Case: stor_Insert.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.004.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.VALUE:warn_msgStore.stor_Insert.Value:miMaximum
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Value:miMaximum
TEST.END

-- Test Case: stor_Insert.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.004.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:warn_msgStore.stor_Insert.Index:4
TEST.VALUE:warn_msgStore.stor_Insert.Value:miMaximum
TEST.EXPECTED:warn_msgStore.stor_Insert.Index:4
TEST.EXPECTED:warn_msgStore.stor_Insert.Value:miMaximum
TEST.END

-- Test Case: stor_Insert.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.005
TEST.VALUE:warn_msgStore.stor_Insert.Value:MSG_WARNING_SWITCH_CONTROL_ID_INDEX
TEST.END

-- Subprogram: stor_UpdateViewer

-- Test Case: stor_UpdateViewer.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.001
TEST.END

-- Test Case: stor_UpdateViewer.001.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.001.001
TEST.END

-- Test Case: stor_UpdateViewer.001.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.001.002
TEST.END

-- Test Case: stor_UpdateViewer.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.END

-- Test Case: stor_UpdateViewer.002.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.002.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.END

-- Test Case: stor_UpdateViewer.002.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.002.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:50
TEST.END

-- Test Case: stor_UpdateViewer.003
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.003
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:55
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:4
TEST.END

-- Test Case: stor_UpdateViewer.003.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.003.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:55
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:4
TEST.END

-- Test Case: stor_UpdateViewer.003.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.003.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:55
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:4
TEST.END

-- Test Case: stor_UpdateViewer.004
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.004
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:5
TEST.END

-- Test Case: stor_UpdateViewer.004.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.004.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:5
TEST.END

-- Test Case: stor_UpdateViewer.004.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.004.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.return:5
TEST.END

-- Test Case: stor_UpdateViewer.005
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.005
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.END

-- Test Case: stor_UpdateViewer.005.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.005.001
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.END

-- Test Case: stor_UpdateViewer.005.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.005.002
TEST.STUB:warn_msgStore.stor_GetViewCount
TEST.STUB:warn_msgStore.stor_GetViewIndex
TEST.VALUE:warn_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:warn_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:warn_msgStore.stor_GetViewIndex.inst:0
TEST.END

-- Test Case: stor_UpdateViewer.006
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.006
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:5
TEST.END

-- Test Case: stor_UpdateViewer.006.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.006.001
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:5
TEST.END

-- Test Case: stor_UpdateViewer.006.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.006.002
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:5
TEST.END

-- Test Case: stor_UpdateViewer.007
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.007
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.007.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.007.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.007.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.007.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.008
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.008
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:6
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.008.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.008.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:6
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.008.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.008.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:6
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.009
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.009
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.009.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.009.001
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.009.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.009.002
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.010
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.010
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.010.001
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.010.001
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.010.002
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.010.002
TEST.STUB:warn_msgStore.stor_FindPreviousIndex
TEST.VALUE:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.VALUE:warn_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.011
TEST.UNIT:warn_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.011
TEST.VALUE:warn_msgStore.stor_UpdateViewer.MessageID:MSG_WARNING_DRIVE_SUMMARY_WARN_ID_INDEX
TEST.VALUE:warn_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:warn_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Unit: warn_msgTask

-- Subprogram: hm_msg_GetStatus

-- Test Case: hm_msg_GetStatus.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.001
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x100
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x100
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.002
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.002
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x1
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.p_inst:0
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:1
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.003
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.003
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x2
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x2
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x2
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:2
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.004
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.004
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MAX>>
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:<<MAX>>
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0xFFFFFEFF
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:4294967295
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.ATTRIBUTES:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:INPUT_BASE=16
TEST.ATTRIBUTES:warn_msgTask.hm_msg_GetStatus.Qualifier:INPUT_BASE=16
TEST.END

-- Test Case: hm_msg_GetStatus.005
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.005
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x1
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:1
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.006
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.006
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x3
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x3
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x3
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:3
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.007
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.007
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x3
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.Qualifier:3
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.008
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.008
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.msgData:<<malloc 1>>
TEST.VALUE:warn_msgTask.hm_msg_GetStatus.Qualifier:0x2
TEST.EXPECTED:warn_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Subprogram: hm_msg_KSColdInit

-- Test Case: hm_msg_KSColdInit.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSColdInit
TEST.NEW
TEST.NAME:hm_msg_KSColdInit.001
TEST.STUB:warn_msgArbitrator.msg_ArbitratorInitialise
TEST.STUB:warn_msgSequencer.msg_SequencerInitialise
TEST.STUB:warn_msgStore.msg_StoreInitialise
TEST.STUB:warn_msgTask.msg_TaskInitialise
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0
TEST.END

-- Subprogram: hm_msg_KSNvRamCheck

-- Test Case: hm_msg_KSNvRamCheck.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSNvRamCheck
TEST.NEW
TEST.NAME:hm_msg_KSNvRamCheck.001
TEST.EXPECTED:warn_msgTask.hm_msg_KSNvRamCheck.return:1
TEST.END

-- Subprogram: hm_msg_KSRRobin

-- Test Case: hm_msg_KSRRobin.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.001
TEST.STUB:warn_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_Observer_GetCurrIgnSts.return:0
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatus:<<MIN>>
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MIN>>
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:0
TEST.END

-- Test Case: hm_msg_KSRRobin.002
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.002
TEST.STUB:warn_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_Observer_GetCurrIgnSts.return:1
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatus:2
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:1
TEST.END

-- Test Case: hm_msg_KSRRobin.003
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.003
TEST.STUB:warn_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_Observer_GetCurrIgnSts.return:<<MAX>>
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatus:0
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Test Case: hm_msg_KSRRobin.004
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.004
TEST.STUB:warn_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:uut_prototype_stubs.WarnMsg_Core_Observer_GetCurrIgnSts.return:<<MIN>>
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatus:<<MAX>>
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:warn_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MIN>>
TEST.END

-- Subprogram: hm_msg_KSSleep

-- Test Case: hm_msg_KSSleep.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSSleep
TEST.NEW
TEST.NAME:hm_msg_KSSleep.001
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:""
TEST.END

-- Subprogram: hm_msg_KSWakeup

-- Test Case: hm_msg_KSWakeup.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSWakeup
TEST.NEW
TEST.NAME:hm_msg_KSWakeup.001
TEST.STUB:warn_msgSequencer.msg_SequencerInitialise
TEST.STUB:warn_msgStore.msg_StoreInitialise
TEST.STUB:warn_msgTask.msg_TaskInitialise
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:0
TEST.END

-- Subprogram: hm_msg_KSWarmInit

-- Test Case: hm_msg_KSWarmInit.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:hm_msg_KSWarmInit
TEST.NEW
TEST.NAME:hm_msg_KSWarmInit.001
TEST.STUB:warn_msgArbitrator.msg_ArbitratorInitialise
TEST.EXPECTED:warn_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:""
TEST.EXPECTED:warn_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:warn_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:3
TEST.END

-- Subprogram: msg_TaskInitialise

-- Test Case: msg_TaskInitialise.001
TEST.UNIT:warn_msgTask
TEST.SUBPROGRAM:msg_TaskInitialise
TEST.NEW
TEST.NAME:msg_TaskInitialise.001
TEST.VALUE:warn_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:warn_msgTask.<<GLOBAL>>.msgStatusQualifier:3
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_ABSENT
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_ABSENT.001
TEST.SLOT: "1", "warn_msgStore", "msg_StoreRemove", "1", "msg_StoreRemove.003"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_ABSENT.002
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_ABSENT.003
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_PRESENT
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_PRESENT.001
TEST.SLOT: "1", "warn_msgStore", "msg_StoreAdd", "1", "msg_StoreAdd.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_PRESENT.002
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_PRESENT.003
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionInvalid
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionInvalid.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionInvalid.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionInvalid.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionOFF
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionOFF.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionOFF.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionOFF.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.001
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.001.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.001.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.001.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.004
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.Inst_1
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.Inst_1.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.Inst_1.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.Inst_1.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_SeqAdd
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_SeqAdd.001
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.002"
TEST.SLOT: "3", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.001"
TEST.SLOT: "4", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_SeqAdd.002
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.002"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.002.002"
TEST.SLOT: "3", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.001.002"
TEST.SLOT: "4", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.002.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_SeqAdd.003
TEST.SLOT: "1", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.003"
TEST.SLOT: "2", "warn_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.002.003"
TEST.SLOT: "3", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.001.003"
TEST.SLOT: "4", "warn_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.002.003"
TEST.END
--
