-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : MESSAGE_CORE
-- Unit(s) Under Test: hmi_msgArbitrator hmi_msgDefinition hmi_msgSequencer hmi_msgStore hmi_msgTask hmi_msgTest
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: hmi_msgArbitrator

-- Subprogram: msg_ArbitratorInitialise

-- Test Case: msg_ArbitratorInitialise.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorInitialise
TEST.NEW
TEST.NAME:msg_ArbitratorInitialise.001
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[1]:0
TEST.END

-- Subprogram: msg_ArbitratorUpdate

-- Test Case: msg_ArbitratorUpdate..Active_Multi
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Active_Multi
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:1
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Active_Multi.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Active_Multi.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:1
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..DeActive_Multi_Compound
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..DeActive_Multi_Compound
TEST.COMPOUND_ONLY
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:0
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:0
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate..DeActive_Multi_Compound.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..DeActive_Multi_Compound.001
TEST.COMPOUND_ONLY
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:0
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:0
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate..Forced_Multi
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Forced_Multi
TEST.STUB:hmi_msgSequencer.msg_SequencerUpdate
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Forced_Multi.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Forced_Multi.001
TEST.STUB:hmi_msgSequencer.msg_SequencerUpdate
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Multi
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Multi
TEST.STUB:hmi_msgSequencer.msg_SequencerUpdate
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Multi.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Multi.001
TEST.STUB:hmi_msgSequencer.msg_SequencerUpdate
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[11]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.inst:0,1
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Single
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Single
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[1]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.END

-- Test Case: msg_ArbitratorUpdate..Retrigger_Single.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate..Retrigger_Single.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[1]:3
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:3
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].ConditionQualifier:256
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:5
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,256,(8)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.002
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.002
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.002.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.002.001
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:0
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.003
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.003
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.004
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.004
TEST.STUB:hmi_msgSequencer.msg_SequencerAdd
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:<<MIN>>
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:OF_WARN_1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.004.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.004.001
TEST.STUB:hmi_msgSequencer.msg_SequencerAdd
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:<<MIN>>
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:OF_WARN_1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.005
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.005
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(5)0,270,(8)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(5)0,270,(8)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.Invalid.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 31>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].SeqQTimeout:0xFF
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.Forced_Single.NoStore.SeqTimeoutFail.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].SeqQTimeout:0xFF
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:<<malloc 32>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue:"MSG_NOT_ADDED_FROM_STORE_QUEUE)"
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.StatusFlag
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.StatusFlag
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:<<malloc 2>>
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:"0"
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(5)0,270,(8)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Active.StatusFlag.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Active.StatusFlag.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:<<malloc 2>>
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:"0"
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(5)0,270,(8)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Forced_Single.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Forced_Single.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRetrigger
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[0]:2
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.msgData[10]:2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ConditionQualifier:255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:255,(9)0,270,(4)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_ArbitratorUpdate.Invalid_ActiveState_Compound
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Invalid_ActiveState_Compound
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate.Invalid_ActiveState_Compound.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Invalid_ActiveState_Compound.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_2].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ActiveStates:0
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate.Invalid_Compound
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Invalid_Compound
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.EXPECTED:uut_prototype_stubs.test_GetWarningState.Qualifier:(15)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate.Invalid_IgnMode_Compound
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Invalid_IgnMode_Compound
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ActiveStates:0xFF
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:0x1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate.Invalid_IgnMode_Compound.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Invalid_IgnMode_Compound.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].ActiveStates:0xFF
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:0x1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.NoRemove.002
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.NoRemove.002
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:1
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:TIMER_RUNNING
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Test Case: msg_ArbitratorUpdate.Remove.001
TEST.UNIT:hmi_msgArbitrator
TEST.SUBPROGRAM:msg_ArbitratorUpdate
TEST.NEW
TEST.NAME:msg_ArbitratorUpdate.Remove.001
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:uut_prototype_stubs.test_GetWarningState.return:1
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus[0]:5
TEST.VALUE:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.EXPECTED:uut_prototype_stubs.test_Mark.Value:0..14
TEST.END

-- Unit: hmi_msgDefinition

-- Subprogram: msg_DefinitionGetDisplayTimeout

-- Test Case: msg_DefinitionGetDisplayTimeout.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:OF_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1050
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.001.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.001.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:OF_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1050
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.002
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.002
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:HW_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1010
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.002.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.002.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:HW_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1010
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.003
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.003
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:SW_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1020
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.003.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.003.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:SW_WARN_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1020
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.004
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.004
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:INF_MSG_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1030
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.004.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.004.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:INF_MSG_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1030
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.005
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.005
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:OK_COND_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1040
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.005.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.005.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:OK_COND_1
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1040
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.006
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.006
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:HW_WARN_2
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1011
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.006.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.006.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:HW_WARN_2
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:1011
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.007
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.007
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miMaximum
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.007.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.007.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miMaximum
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.008
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.008
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miUndefined
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Test Case: msg_DefinitionGetDisplayTimeout.008.001
TEST.UNIT:hmi_msgDefinition
TEST.SUBPROGRAM:msg_DefinitionGetDisplayTimeout
TEST.NEW
TEST.NAME:msg_DefinitionGetDisplayTimeout.008.001
TEST.VALUE:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.aMessage:miUndefined
TEST.EXPECTED:hmi_msgDefinition.msg_DefinitionGetDisplayTimeout.return:0
TEST.END

-- Unit: hmi_msgSequencer

-- Subprogram: msg_ClearNewMessageFlag

-- Test Case: msg_ClearNewMessageFlag.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_ClearNewMessageFlag
TEST.NEW
TEST.NAME:msg_ClearNewMessageFlag.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 5>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0xFF"
TEST.VALUE:hmi_msgSequencer.msg_ClearNewMessageFlag.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"0"
TEST.END

-- Subprogram: msg_SequencerAction

-- Test Case: ACK_ALL_BTN_EV
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV.001
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[7].Options:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[8].Options:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.MULTI
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_ALL_BTN_EV_MSG_BTN_NOACTION.MULTI
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:18
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.001
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV.MULTI.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV.MULTI.001
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:(2)1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:(2)20
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x14
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:(2)50
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:(2)100
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:(2)4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:(2)53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:(2)20
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:(2)21
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:(2)OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:(2)OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:(2)INF_MSG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:(2)AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:(2)AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:(2)AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_ACKAFTMINTOUT_TMR_RUNNING.MULTI
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x14
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:(2)50
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:(2)100
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:(2)4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:(2)53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:(2)20
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:(2)21
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:(2)OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:(2)OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:(2)INF_MSG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:(2)6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:(2)AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:(2)AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:(2)AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:(2)miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:(2)6
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:(2)17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.p_inst:0,1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0,10
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_CURR_MSG_ID_IS_UNDEFINED.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:1
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[7].Options:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[8].Options:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[10].Options:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[11].Options:INPUT_BASE=16
TEST.END

-- Test Case: ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_HOLD_MSG_IS_UNDEFINED.MULTI
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:6
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACK.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACK.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:21
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.001
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:10
TEST.END

-- Test Case: ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_ACKAFTMINTOUT.INVALIDINST
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:50
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[5]:100
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:21
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_BTN_EV_NO_CLEARABLE
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_BTN_EV_NO_CLEARABLE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x35
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x15
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:53
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:21
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:17
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:0
TEST.END

-- Test Case: ACK_GROUP
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_2
TEST.END

-- Test Case: ACK_GROUP_CURR_MSG_GROUP_UNDEF
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_CURR_MSG_GROUP_UNDEF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.END

-- Test Case: ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_NON_CLEARABLE_MSG_IN_SEQ
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..6]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:4
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_2
TEST.END

-- Test Case: ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_OTHER_GROUP_WARN_IS_NOT_REMOVED
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5..6]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:INF_MSG_2
TEST.END

-- Test Case: ACK_GROUP_UNDEF_MSG_IN_SEQ
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAction
TEST.NEW
TEST.NAME:ACK_GROUP_UNDEF_MSG_IN_SEQ
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].AckGroup:mgUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_2].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].AckGroup:mgAckGroupA
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcOpFeedback
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0x7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].AckGroup:mgAckGroupB
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6..7]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:7
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.VALUE:hmi_msgSequencer.msg_SequencerAction.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4..7]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.Button:0x11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAction.return:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_2
TEST.END

-- Subprogram: msg_SequencerAdd

-- Test Case: msg_SequencerAdd.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.001.001
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_SequencerAdd.002.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.002.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_SequencerAdd.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_2].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.END

-- Test Case: msg_SequencerAdd.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_2].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.END

-- Test Case: msg_SequencerAdd.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:40
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.009
TEST.STUB:hmi_msgSequencer.seq_InsertMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.return:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerAdd.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerAdd
TEST.NEW
TEST.NAME:msg_SequencerAdd.010
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:MSG_ADDED_FROM_STORE_QUEUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:7
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].SeqQTimeout:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_MsgAddedFromStoreQueue[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[6]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[7]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.Seq_NewMsgQTimeout_U8[8]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerAdd.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:INF_MSG_1
TEST.ATTRIBUTES:hmi_msgSequencer.seq_InsertMessage.return:INPUT_BASE=16
TEST.END

-- Subprogram: msg_SequencerForcedActive

-- Test Case: msg_SequencerForcedActive.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OF_WARN_1
TEST.END

-- Test Case: msg_SequencerForcedActive.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OK_COND_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OK_COND_2
TEST.END

-- Test Case: msg_SequencerForcedActive.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OK_COND_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OK_COND_2
TEST.END

-- Test Case: msg_SequencerForcedActive.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerForcedActive
TEST.NEW
TEST.NAME:msg_SequencerForcedActive.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_2].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerForcedActive.MessageID:OK_COND_2
TEST.END

-- Subprogram: msg_SequencerGetAlertInfo

-- Test Case: msg_SequencerGetAlertInfo.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.001.001
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.002.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.002.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x7
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.VALUE_USER_CODE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData
<<hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData>> = (void*)(&l_msg_viewinfo_S);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.END

-- Test Case: msg_SequencerGetAlertInfo.003.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetAlertInfo
TEST.NEW
TEST.NAME:msg_SequencerGetAlertInfo.003.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetAlertInfo.msgData:<<null>>
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_viewinfo_S.Status:0x0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetAlertInfo.return:0
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:INPUT_BASE=16
TEST.END

-- Subprogram: msg_SequencerGetCurrent

-- Test Case: msg_SequencerGetCurrent.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.001
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Test Case: msg_SequencerGetCurrent.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.001.001
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Test Case: msg_SequencerGetCurrent.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.002
TEST.STUB:hmi_msgSequencer.seq_GetViewMessage
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:10
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Test Case: msg_SequencerGetCurrent.002.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetCurrent
TEST.NEW
TEST.NAME:msg_SequencerGetCurrent.002.001
TEST.STUB:hmi_msgSequencer.seq_GetViewMessage
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:10
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetCurrent.return:0
TEST.END

-- Subprogram: msg_SequencerGetMessage

-- Test Case: msg_SequencerGetMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.001
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetMessage.return:8
TEST.ATTRIBUTES:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.ATTRIBUTES:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: msg_SequencerGetMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerGetMessage
TEST.NEW
TEST.NAME:msg_SequencerGetMessage.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.VALUE:hmi_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetMessage.Qualifier:2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerGetMessage.p_inst:5
TEST.ATTRIBUTES:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: msg_SequencerHide

-- Test Case: msg_SequencerHide.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.001
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.END

-- Test Case: msg_SequencerHide.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.002
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.END

-- Test Case: msg_SequencerHide.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.003
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerHide.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerHide
TEST.NEW
TEST.NAME:msg_SequencerHide.004
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerHide.p_inst:5
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.END

-- Subprogram: msg_SequencerInitialise

-- Test Case: msg_SequencerInitialise.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerInitialise.inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.001.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ForcedActiveMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..6]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.002.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.002.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerInitialise.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..5]:miUndefined
TEST.END

-- Test Case: msg_SequencerInitialise.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerInitialise
TEST.NEW
TEST.NAME:msg_SequencerInitialise.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.msg_SequencerInitialise.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerInitialise.inst:5
TEST.END

-- Subprogram: msg_SequencerNewMsgQTimeoutUpdate

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.001
TEST.VALUE:hmi_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:5
TEST.END

-- Test Case: msg_SequencerNewMsgQTimeoutUpdate.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerNewMsgQTimeoutUpdate
TEST.NEW
TEST.NAME:msg_SequencerNewMsgQTimeoutUpdate.002
TEST.STUB:hmi_msgSequencer.msg_SequencerRemove
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:OK_COND_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.VALUE:hmi_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerNewMsgQTimeoutUpdate.p_inst:1
TEST.END

-- Subprogram: msg_SequencerOldWrngRepUpdate

-- Test Case: msg_SequencerOldWrngRepUpdate.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.001
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:5
TEST.END

-- Test Case: msg_SequencerOldWrngRepUpdate.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.002
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:21
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:1
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[1].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerOldWrngRepUpdate.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.003
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:21
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerOldWrngRepUpdate.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.004
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:21
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerOldWrngRepUpdate.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.005
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:21
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:20
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_SequencerOldWrngRepUpdate.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerOldWrngRepUpdate
TEST.NEW
TEST.NAME:msg_SequencerOldWrngRepUpdate.006
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:21
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0x0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:20
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0x3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerOldWrngRepUpdate.p_inst:1
TEST.END

-- Subprogram: msg_SequencerRemove

-- Test Case: msg_SequencerRemove.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.001
TEST.STUB:hmi_msgStore.msg_StoreRemove
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.002
TEST.STUB:hmi_msgStore.msg_StoreRemove
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.END

-- Test Case: msg_SequencerRemove.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.003
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgStore.msg_StoreRemove
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.MessageID:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: msg_SequencerRemove.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.004
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgStore.msg_StoreRemove
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0x2000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.END

-- Test Case: msg_SequencerRemove.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.005
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.END

-- Test Case: msg_SequencerRemove.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.006
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRemove.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.007
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:7
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.END

-- Test Case: msg_SequencerRemove.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.008
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:1
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:TIMER_RUNNING
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0x2000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:8192
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.END

-- Test Case: msg_SequencerRemove.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.009
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.010
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.011
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.011
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Test Case: msg_SequencerRemove.012
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.012
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.inst:1
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:1
TEST.END

-- Test Case: msg_SequencerRemove.013
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRemove
TEST.NEW
TEST.NAME:msg_SequencerRemove.013
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ActiveStates:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRemove.Ignition:5
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.inst:1
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:205
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[1]:200
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].ActiveStates:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].ActiveStates:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.MessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.Ignition:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRemove.return:0
TEST.END

-- Subprogram: msg_SequencerRetrigger

-- Test Case: Retrigger_Invalid
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_Invalid
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgTest.hmi_stub_timer_stop
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_stop.timer_id:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.END

-- Test Case: Retrigger_and_then_timer_Expires.Invalid
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:Retrigger_and_then_timer_Expires.Invalid
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerRetrigger.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:SW_WARN_2
TEST.END

-- Test Case: msg_SequencerRetrigger.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:miUndefined
TEST.END

-- Test Case: msg_SequencerRetrigger.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerRetrigger
TEST.NEW
TEST.NAME:msg_SequencerRetrigger.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerRetrigger.MessageID:INF_MSG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:INF_MSG_2
TEST.END

-- Subprogram: msg_SequencerSelectFirst

-- Test Case: msg_SequencerSelectFirst.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.004
TEST.STUB:hmi_msgSequencer.seq_GetViewCount
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.return:6
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.005
TEST.STUB:hmi_msgSequencer.seq_GetViewCount
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.return:1
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Test Case: msg_SequencerSelectFirst.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectFirst
TEST.NEW
TEST.NAME:msg_SequencerSelectFirst.006
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:11
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectFirst.return:0
TEST.END

-- Subprogram: msg_SequencerSelectNext

-- Test Case: msg_SequencerSelectNext.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.001
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:4
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectNext.return:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:INF_MSG_1
TEST.END

-- Test Case: msg_SequencerSelectNext.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectNext
TEST.NEW
TEST.NAME:msg_SequencerSelectNext.002
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:3
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectNext.return:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_1
TEST.END

-- Subprogram: msg_SequencerSelectPrevious

-- Test Case: msg_SequencerSelectPrevious.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.001
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerSelectPrevious.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.002
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerSelectPrevious.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.003
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:INF_MSG_2
TEST.END

-- Test Case: msg_SequencerSelectPrevious.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerSelectPrevious
TEST.NEW
TEST.NAME:msg_SequencerSelectPrevious.004
TEST.STUB:hmi_msgSequencer.seq_FindPreviousIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.VALUE:hmi_msgSequencer.msg_SequencerSelectPrevious.p_inst:5
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectPrevious.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerSelectPrevious.return:0
TEST.ATTRIBUTES:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: msg_SequencerShow

-- Test Case: msg_SequencerShow.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.007
TEST.STUB:hmi_msgTest.hmi_stub_timer_start
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0x28
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DispIndTimeout:1500
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timeout:3,1500,(2)1000
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timer_id:6,3,2,8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:40
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DispIndTimeout:1500
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.008
TEST.STUB:hmi_msgTest.hmi_stub_timer_start
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0x28
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DispIndTimeout:1500
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timeout:1500,(2)1000,2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timer_id:3,2,8,1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:40
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DispIndTimeout:1500
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.009
TEST.STUB:hmi_msgTest.hmi_stub_timer_start
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:0x8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timeout:3,(2)1000,2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timer_id:6,2,8,1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].DisplayTimeout:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].HoldTimeout:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[SW_WARN_2].Options:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:32
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.010
TEST.STUB:hmi_msgTest.hmi_stub_timer_start
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].HoldTimeout:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0x20
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].DispIndTimeout:1500
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timeout:4,1500,1000
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_start.timer_id:6,3,8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].HoldTimeout:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:32
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].DispIndTimeout:1500
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_SequencerShow.011
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.011
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.012
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.012
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:8
TEST.END

-- Test Case: msg_SequencerShow.013
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.013
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OK_COND_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerShow.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerShow.p_inst:5
TEST.END

-- Test Case: msg_SequencerShow.014
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerShow
TEST.NEW
TEST.NAME:msg_SequencerShow.014
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.msg_SequencerShow.p_inst:0
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerShow.p_inst:0
TEST.END

-- Subprogram: msg_SequencerUpdate

-- Test Case: No_Retrigger_after_timeout
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:No_Retrigger_after_timeout
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:HMI_TIMER_EXPIRED
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:OF_WARN_1
TEST.EXPECTED:uut_prototype_stubs.msgtest_ShowMessage.Message:0
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1,OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:MSG_EVENT_TIMEOUT,MSG_EVENT_ACTIVE,MSG_EVENT_SHOW
TEST.END

-- Test Case: Retrigger_after_timeout
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_after_timeout
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:150
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:HMI_TIMER_EXPIRED
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_1
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(3)HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,16,8
TEST.END

-- Test Case: Retrigger_after_timeout_clear
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_after_timeout_clear
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:50
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:HMI_TIMER_CLEAR
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:6,1,3,2,8
TEST.EXPECTED:uut_prototype_stubs.msgtest_ShowMessage.Message:0
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[OF_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.msg_SequencerUpdate.Ignition:0
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:16,8
TEST.END

-- Test Case: Retrigger_before_timeout
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_before_timeout
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:150
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:HMI_TIMER_RUNNING
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:HW_WARN_1
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:MSG_EVENT_ACTIVE,MSG_EVENT_SHOW
TEST.END

-- Test Case: Retrigger_not_current_msg
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:Retrigger_not_current_msg
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:150
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:HMI_TIMER_RUNNING
TEST.VALUE:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:HW_WARN_1
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgDefinition.<<GLOBAL>>.messageList[HW_WARN_1].DisplayTimeout:6000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.001
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.004
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:600
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:600
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.005
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:610
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:610
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.006
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:500
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:500
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.007
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.008
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.009
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.010
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.011
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.011
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_FindActiveMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.012
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.012
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.013
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.013
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.015
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.015
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.END

-- Test Case: msg_SequencerUpdate.016
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.016
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[3]:601
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miMaximum
TEST.END

-- Test Case: msg_SequencerUpdate.018
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.018
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:3
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:6,1,3,2,8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(5)HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:64,2,32,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.019
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.019
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:3
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[0..15]:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:6,1,3,2,8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:251
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[0..1]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[2]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[3..15]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:64,2,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_SequencerUpdate.020
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SequencerUpdate
TEST.NEW
TEST.NAME:msg_SequencerUpdate.020
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.STUB:hmi_msgSequencer.seq_GetLowerCategoryMessage
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.STUB:hmi_msgSequencer.seq_GetNextMessage
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.STUB:hmi_msgSequencer.seq_Callback
TEST.STUB:hmi_msgStore.msg_StoreAdd
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:3,6
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:1,2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[0..15]:0xFFFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.return:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:6,1,3,2,8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[HW_WARN_2].Options:0xFFFF
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:251
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[2..3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[0..1]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[2]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[3..15]:65535
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_RetriggerMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:(2)2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:(2)HW_WARN_1,(2)HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:64,2,16,8
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Subprogram: msg_SetOldWrngRepDur

-- Test Case: msg_SetOldWrngRepDur.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SetOldWrngRepDur
TEST.NEW
TEST.NAME:msg_SetOldWrngRepDur.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0xFFFF
TEST.VALUE:hmi_msgSequencer.msg_SetOldWrngRepDur.MessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:6
TEST.END

-- Test Case: msg_SetOldWrngRepDur.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:msg_SetOldWrngRepDur
TEST.NEW
TEST.NAME:msg_SetOldWrngRepDur.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Options:0x0
TEST.VALUE:hmi_msgSequencer.msg_SetOldWrngRepDur.MessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_Old_Wrng_RepDuration[1]:0
TEST.END

-- Subprogram: seq_Callback

-- Test Case: seq_Callback.Qualifier<255
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:200
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.msgData[0]:1
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.Qualifier:200
TEST.END

-- Test Case: seq_Callback.Qualifier<255.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier<255.001
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:0xC8
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:1
TEST.END

-- Test Case: seq_Callback.Qualifier>255
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.Qualifier>255
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:270
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.msgData[0]:1
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.Qualifier:270
TEST.END

-- Test Case: seq_Callback.QualifierMax
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:0xFFFFFFFF
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:2
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.msgData[0]:2
TEST.EXPECTED:uut_prototype_stubs.test_EventCallback.Qualifier:0xFFFFFFFF
TEST.END

-- Test Case: seq_Callback.QualifierMax.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.QualifierMax.001
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:0xFFFFFFFF
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:2
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:4294967295
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.Action:2
TEST.END

-- Test Case: seq_Callback.invalidAction
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidAction
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:0x2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:2
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.END

-- Test Case: seq_Callback.invalidEventCallback
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidEventCallback
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].ConditionQualifier:0x2
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:INF_MSG_1
TEST.END

-- Test Case: seq_Callback.invalidMessageID
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Callback
TEST.NEW
TEST.NAME:seq_Callback.invalidMessageID
TEST.VALUE:hmi_msgArbitrator.<<GLOBAL>>.messageList[INF_MSG_1].EventQualifier:1
TEST.VALUE:hmi_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.VALUE:hmi_msgSequencer.seq_Callback.Action:1
TEST.EXPECTED:hmi_msgSequencer.seq_Callback.MessageID:miMaximum
TEST.END

-- Subprogram: seq_Delete

-- Test Case: DELETE_MSG_FROM_SEQ_Q
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:hmi_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:miUndefined
TEST.END

-- Test Case: DELETE_MSG_FROM_SEQ_Q.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Delete
TEST.NEW
TEST.NAME:DELETE_MSG_FROM_SEQ_Q.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.VALUE:hmi_msgSequencer.seq_Delete.Index:5
TEST.VALUE:hmi_msgSequencer.seq_Delete.inst:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:8
TEST.EXPECTED:hmi_msgSequencer.seq_Delete.Index:5
TEST.EXPECTED:hmi_msgSequencer.seq_Delete.inst:6
TEST.END

-- Subprogram: seq_FindActiveMessage

-- Test Case: seq_FindActiveMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..4]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:7
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Message:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:OF_WARN_1
TEST.END

-- Test Case: seq_FindActiveMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[1]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[OF_WARN_2].Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:12
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Message:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[1]:10
TEST.END

-- Test Case: seq_FindActiveMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:7
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:OF_WARN_2
TEST.END

-- Test Case: seq_FindActiveMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:INF_MSG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:INF_MSG_2
TEST.END

-- Test Case: seq_FindActiveMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:4294967295
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Category:mcOpFeedback
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Message:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Test Case: seq_FindActiveMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:OK_COND_1
TEST.END

-- Test Case: seq_FindActiveMessage.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindActiveMessage
TEST.NEW
TEST.NAME:seq_FindActiveMessage.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.Message:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Category:mcSoftWarning
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindActiveMessage.return:miUndefined
TEST.END

-- Subprogram: seq_FindFirstIndex

-- Test Case: seq_FindFirstIndex.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.001
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.CategoryMask:1
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindFirstIndex.return:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:1
TEST.END

-- Test Case: seq_FindFirstIndex.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.002
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:7
TEST.EXPECTED:hmi_msgSequencer.seq_FindFirstIndex.return:7
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: seq_FindFirstIndex.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindFirstIndex
TEST.NEW
TEST.NAME:seq_FindFirstIndex.003
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Subprogram: seq_FindNextIndex

-- Test Case: Index_not_found
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:Index_not_found
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:<<MAX>>
TEST.END

-- Test Case: seq_FindNextIndex.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:2
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Test Case: seq_FindNextIndex.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:3
TEST.END

-- Test Case: seq_FindNextIndex.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:1
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.Start:1
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:8
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:0
TEST.END

-- Test Case: seq_FindNextIndex.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindNextIndex
TEST.NEW
TEST.NAME:seq_FindNextIndex.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.Start:0
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgSequencer.seq_FindNextIndex.return:5
TEST.END

-- Subprogram: seq_FindPreviousIndex

-- Test Case: Index_not_found
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:Index_not_found
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:7
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:0
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:7
TEST.END

-- Test Case: seq_FindPreviousIndex.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:4
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:2
TEST.END

-- Test Case: seq_FindPreviousIndex.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.002
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.003
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:4294967294
TEST.END

-- Test Case: seq_FindPreviousIndex.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:1
TEST.END

-- Test Case: seq_FindPreviousIndex.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:0
TEST.END

-- Test Case: seq_FindPreviousIndex.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_FindPreviousIndex
TEST.NEW
TEST.NAME:seq_FindPreviousIndex.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.VALUE:hmi_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.Start:5
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.CategoryMask:8
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.inst:0
TEST.EXPECTED:hmi_msgSequencer.seq_FindPreviousIndex.return:5
TEST.END

-- Subprogram: seq_GetCategories

-- Test Case: seq_GetCategories.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:5
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:10
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:<<MIN>>
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:2
TEST.END

-- Test Case: seq_GetCategories.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:10
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:4
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:4
TEST.END

-- Test Case: seq_GetCategories.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:7
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:3
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Test Case: seq_GetCategories.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetCategories
TEST.NEW
TEST.NAME:seq_GetCategories.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:2
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.Threshold:3
TEST.VALUE:hmi_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.p_inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetCategories.return:0
TEST.END

-- Subprogram: seq_GetLowerCategoryMessage

-- Test Case: seq_GetLowerCategoryMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.001
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.002
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcMaximum
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.003
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.004
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.005
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetLowerCategoryMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetLowerCategoryMessage
TEST.NEW
TEST.NAME:seq_GetLowerCategoryMessage.006
TEST.STUB:hmi_msgSequencer.seq_GetNewMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetLowerCategoryMessage.inst:6
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_GetLowerCategoryMessage.return:miUndefined
TEST.END

-- Subprogram: seq_GetNewMessage

-- Test Case: seq_GetNewMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.001
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:HW_WARN_1
TEST.END

-- Test Case: seq_GetNewMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:<<MIN>>
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:254
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNewMessage.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNewMessage
TEST.NEW
TEST.NAME:seq_GetNewMessage.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.VALUE:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.Category:mcHardWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNewMessage.return:miUndefined
TEST.END

-- Subprogram: seq_GetNextMessage

-- Test Case: seq_GetNextMessage.AC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetNextMessage.AC.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.AC.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetNextMessage.ACAll
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACAll.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACAll.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWONAC.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWONAC.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1..3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:NON_AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNAC.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNAC.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2..3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:NON_AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.ACWithNACNoCycle.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.ACWithNACNoCycle.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:SW_WARN_1
TEST.END

-- Test Case: seq_GetNextMessage.NAC.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:SW_WARN_1
TEST.END

-- Test Case: seq_GetNextMessage.NAC.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.inst:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetNextMessage.NAC.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetNextMessage
TEST.NEW
TEST.NAME:seq_GetNextMessage.NAC.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[8]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[9]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:10
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Category:mcSoftWarning
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.Message:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.inst:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetNextMessage.return:miUndefined
TEST.END

-- Subprogram: seq_GetTopMostMessage

-- Test Case: seq_GetTopMostMessage.ACNew
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetTopMostMessage.ACNew.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.ACNew.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:AUTO_CANCEL_WRNG_2
TEST.END

-- Test Case: seq_GetTopMostMessage.NACInCurCat
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACInCurCat
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:3
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: seq_GetTopMostMessage.NACTop
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACTop
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:OF_WARN_1
TEST.END

-- Test Case: seq_GetTopMostMessage.NACWOCycle
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NACWOCycle
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NewTop
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NewTop
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:OF_WARN_1
TEST.END

-- Test Case: seq_GetTopMostMessage.NoAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1..6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:OF_WARN_2
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoActiveMsg.InvalidInst
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoActiveMsg.InvalidInst
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..6]:0
TEST.VALUE:hmi_msgSequencer.seq_GetTopMostMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.NoNAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.NoNAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:<<malloc 2>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags:"1"
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:miUndefined
TEST.END

-- Test Case: seq_GetTopMostMessage.OldNAC
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetTopMostMessage
TEST.NEW
TEST.NAME:seq_GetTopMostMessage.OldNAC
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2..5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetTopMostMessage.return:OF_WARN_1
TEST.END

-- Subprogram: seq_GetViewCount

-- Test Case: seq_GetViewCount.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.inst:0
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Test Case: seq_GetViewCount.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:1
TEST.END

-- Test Case: seq_GetViewCount.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewCount
TEST.NEW
TEST.NAME:seq_GetViewCount.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.CategoryMask:0xFF
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..4]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.CategoryMask:255
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.inst:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewCount.return:0
TEST.END

-- Subprogram: seq_GetViewIndex

-- Test Case: seq_GetViewIndex.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..2]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:1
TEST.END

-- Test Case: seq_GetViewIndex.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:2
TEST.END

-- Test Case: seq_GetViewIndex.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:3
TEST.END

-- Test Case: seq_GetViewIndex.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:3
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:3
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:12
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.009
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:OK_COND_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:4
TEST.END

-- Test Case: seq_GetViewIndex.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.010
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:OK_COND_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.MessageID:OK_COND_2
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.inst:5
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Test Case: seq_GetViewIndex.011
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewIndex
TEST.NEW
TEST.NAME:seq_GetViewIndex.011
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.MessageID:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[2]:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[3]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:4
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.return:0
TEST.END

-- Subprogram: seq_GetViewMessage

-- Test Case: seq_GetViewMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.003
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.END

-- Test Case: seq_GetViewMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_GetViewMessage
TEST.NEW
TEST.NAME:seq_GetViewMessage.004
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Id:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Position:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Count:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.ViewInfo[0].Status:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_GetViewMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewMessage.inst:5
TEST.END

-- Subprogram: seq_IndexDown

-- Test Case: seq_IndexDown.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.VALUE:hmi_msgSequencer.seq_IndexDown.BaseCategory:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:8
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:12
TEST.END

-- Test Case: seq_IndexDown.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:hmi_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:49
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:99
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:149
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:199
TEST.END

-- Test Case: seq_IndexDown.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexDown
TEST.NEW
TEST.NAME:seq_IndexDown.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.VALUE:hmi_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.VALUE:hmi_msgSequencer.seq_IndexDown.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:50
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:100
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:150
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:200
TEST.EXPECTED:hmi_msgSequencer.seq_IndexDown.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.seq_IndexDown.inst:5
TEST.END

-- Subprogram: seq_IndexUp

-- Test Case: seq_IndexUp.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:100
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:200
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:300
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:400
TEST.VALUE:hmi_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:101
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:201
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:301
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:401
TEST.END

-- Test Case: seq_IndexUp.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.VALUE:hmi_msgSequencer.seq_IndexUp.BaseCategory:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:6
TEST.END

-- Test Case: seq_IndexUp.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_IndexUp
TEST.NEW
TEST.NAME:seq_IndexUp.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.VALUE:hmi_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.VALUE:hmi_msgSequencer.seq_IndexUp.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:3
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5]:5
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.inst:5
TEST.END

-- Subprogram: seq_InitIndex

-- Test Case: seq_InitIndex.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Test Case: seq_InitIndex.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitIndex
TEST.NEW
TEST.NAME:seq_InitIndex.001.001
TEST.VALUE:hmi_msgSequencer.seq_InitIndex.inst:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[0..5]:0
TEST.END

-- Subprogram: seq_InitList

-- Test Case: seq_InitList.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[0..10]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..10]:miUndefined
TEST.END

-- Test Case: seq_InitList.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitList
TEST.NEW
TEST.NAME:seq_InitList.001.001
TEST.VALUE:hmi_msgSequencer.seq_InitList.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[0..10]:0
TEST.END

-- Subprogram: seq_InitView

-- Test Case: seq_InitView.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_InitView.001.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InitView
TEST.NEW
TEST.NAME:seq_InitView.001.001
TEST.VALUE:hmi_msgSequencer.seq_InitView.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MAX>>
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Subprogram: seq_Insert

-- Test Case: INSERT_MSG_INTO_SEQ_Q
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:hmi_msgSequencer.seq_Insert.Index:5
TEST.VALUE:hmi_msgSequencer.seq_Insert.MessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:HW_WARN_1
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[5..6]:6
TEST.VALUE:hmi_msgSequencer.seq_Insert.Index:5
TEST.VALUE:hmi_msgSequencer.seq_Insert.MessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[6]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[7]:HW_WARN_1
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.seq_Insert.Index:0
TEST.VALUE:hmi_msgSequencer.seq_Insert.MessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.seq_Insert.Index:0
TEST.VALUE:hmi_msgSequencer.seq_Insert.MessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:0
TEST.END

-- Test Case: INSERT_MSG_INTO_SEQ_Q.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_Insert
TEST.NEW
TEST.NAME:INSERT_MSG_INTO_SEQ_Q.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.VALUE:hmi_msgSequencer.seq_Insert.Index:0
TEST.VALUE:hmi_msgSequencer.seq_Insert.MessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:0
TEST.END

-- Subprogram: seq_InsertMessage

-- Test Case: seq_InsertMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.003
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:128
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:2
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:2
TEST.END

-- Test Case: seq_InsertMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.004
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Priority:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:3
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:4
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:4
TEST.END

-- Test Case: seq_InsertMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.005
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:3
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.006
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Priority:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:3
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.007
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Priority:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.008
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Priority:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:OK_COND_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:4
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:4
TEST.END

-- Test Case: seq_InsertMessage.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.009
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[OK_COND_1].Priority:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:4
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcInformation
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x100
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:5
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:5
TEST.END

-- Test Case: seq_InsertMessage.Multi
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:MSG_OPTION_INS_AFT_CUR
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:HW_WARN_1,AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:1
TEST.ATTRIBUTES:hmi_msgSequencer.<<GLOBAL>>.messageList[10].Options:INPUT_BASE=16
TEST.END

-- Test Case: seq_InsertMessage.Multi.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.001
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcHardWarning
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:256
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:HW_WARN_1,AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.002
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:5
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:5
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:0xFFFFFFFF
TEST.END

-- Test Case: seq_InsertMessage.Multi.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.004
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:1
TEST.END

-- Test Case: seq_InsertMessage.Multi.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_InsertMessage
TEST.NEW
TEST.NAME:seq_InsertMessage.Multi.005
TEST.STUB:hmi_msgSequencer.seq_IndexUp
TEST.STUB:hmi_msgSequencer.seq_Insert
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage:<<malloc 1>>
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:0x5000
TEST.VALUE:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[1]:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[2]:2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:miMaximum
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[5]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_Categories[6]:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Priority:1
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.theMessage[0].Options:20480
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_InsertMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexUp.BaseCategory:6
TEST.EXPECTED:hmi_msgSequencer.seq_Insert.Index:1
TEST.END

-- Subprogram: seq_MsgDisplayTime

-- Test Case: seq_MsgDisplayTime.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.001
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:miMaximum
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:0
TEST.END

-- Test Case: seq_MsgDisplayTime.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.002
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:0
TEST.END

-- Test Case: seq_MsgDisplayTime.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.003
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1050
TEST.END

-- Test Case: seq_MsgDisplayTime.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.004
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1010
TEST.END

-- Test Case: seq_MsgDisplayTime.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.005
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1020
TEST.END

-- Test Case: seq_MsgDisplayTime.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.006
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1030
TEST.END

-- Test Case: seq_MsgDisplayTime.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.007
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:OK_COND_1
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1040
TEST.END

-- Test Case: seq_MsgDisplayTime.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_MsgDisplayTime
TEST.NEW
TEST.NAME:seq_MsgDisplayTime.008
TEST.VALUE:hmi_msgSequencer.seq_MsgDisplayTime.MessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_MsgDisplayTime.return:1011
TEST.END

-- Subprogram: seq_RemoveHoldMessage

-- Test Case: Hold_msg_is_undefined
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:Hold_msg_is_undefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveHoldMessage.inst:0,1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:(2)miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_1,miUndefined
TEST.END

-- Test Case: seq_RemoveHoldMessage.002.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.002.001
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.inst:0
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.003.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.003.001
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1
TEST.STUB:hmi_msgSequencer.seq_UpdateViewer
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveHoldMessage.inst:1
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.inst:0,1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:15
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.inst:0,1
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:4,0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:4
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.inst:1
TEST.EXPECTED:hmi_msgSequencer.seq_GetViewIndex.inst:1
TEST.END

-- Test Case: seq_RemoveHoldMessage.Inst1.Invalid
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveHoldMessage
TEST.NEW
TEST.NAME:seq_RemoveHoldMessage.Inst1.Invalid
TEST.STUB:hmi_msgSequencer.seq_RemoveMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveHoldMessage.inst:5
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.return:15
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_HoldMessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_HoldMessageID:AUTO_CANCEL_WRNG_2
TEST.END

-- Subprogram: seq_RemoveMessage

-- Test Case: seq_RemoveMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.001
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.002
TEST.STUB:hmi_msgSequencer.seq_IndexDown
TEST.STUB:hmi_msgSequencer.seq_Delete
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.004
TEST.STUB:hmi_msgSequencer.seq_IndexDown
TEST.STUB:hmi_msgSequencer.seq_Delete
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.005
TEST.STUB:hmi_msgSequencer.seq_IndexDown
TEST.STUB:hmi_msgSequencer.seq_Delete
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:1
TEST.EXPECTED:hmi_msgSequencer.seq_IndexDown.BaseCategory:4
TEST.EXPECTED:hmi_msgSequencer.seq_Delete.Index:5
TEST.END

-- Test Case: seq_RemoveMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:7
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:7
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0..1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.009
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.009
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.messageList[INF_MSG_1].InstanceID:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DsplyTimeList[6]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Test Case: seq_RemoveMessage.010
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_RemoveMessage
TEST.NEW
TEST.NAME:seq_RemoveMessage.010
TEST.STUB:hmi_msgTest.hmi_stub_timer_stop
TEST.VALUE:hmi_msgTest.hmi_stub_timer_stop.timer_id:13,19
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgSequencer.seq_RemoveMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_stop.timer_id:(2)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_CurrentMessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[3]:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_Categories[4]:6
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.MessageID:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.seq_RemoveMessage.return:0
TEST.END

-- Subprogram: seq_SetViewMessage

-- Test Case: seq_SetViewMessage.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.001
TEST.STUB:hmi_msgSequencer.seq_GetViewCount
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:3
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.return:4
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:10
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.002
TEST.STUB:hmi_msgSequencer.seq_GetViewCount
TEST.STUB:hmi_msgSequencer.seq_GetViewIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:9
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_GetViewCount.return:1000
TEST.VALUE:hmi_msgSequencer.seq_GetViewIndex.return:46
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:46
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:1000
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MIN>>
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.005
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.005
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:SW_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.END

-- Test Case: seq_SetViewMessage.006
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.006
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:1
TEST.END

-- Test Case: seq_SetViewMessage.007
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.inst:5
TEST.END

-- Test Case: seq_SetViewMessage.008
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_SetViewMessage
TEST.NEW
TEST.NAME:seq_SetViewMessage.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:0xFF
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:<<MAX>>
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_SetViewMessage.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_NewMessageFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_DisplayedOnceFlags[1]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[0]:255
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_MsgRecycleFlags[1]:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Status:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_CurrentMessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Id:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Position:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Count:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.Status:7
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_ViewMessage.InstanceID:1
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.inst:1
TEST.END

-- Subprogram: seq_UpdateViewer

-- Test Case: seq_UpdateViewer.001
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.001
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:4
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:2
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:INF_MSG_1
TEST.END

-- Test Case: seq_UpdateViewer.002
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.002
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:OK_COND_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MessageID:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:2
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:OK_COND_2
TEST.END

-- Test Case: seq_UpdateViewer.003
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.003
TEST.STUB:hmi_msgSequencer.seq_SetViewMessage
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MessageID:miUndefined
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:<<MAX>>
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:11
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:2
TEST.EXPECTED:hmi_msgSequencer.seq_SetViewMessage.MessageID:miUndefined
TEST.END

-- Test Case: seq_UpdateViewer.004
TEST.UNIT:hmi_msgSequencer
TEST.SUBPROGRAM:seq_UpdateViewer
TEST.NEW
TEST.NAME:seq_UpdateViewer.004
TEST.STUB:hmi_msgSequencer.seq_FindFirstIndex
TEST.STUB:hmi_msgSequencer.seq_FindNextIndex
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MessageID:HW_WARN_2
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.VALUE:hmi_msgSequencer.seq_UpdateViewer.inst:0xFF
TEST.VALUE:hmi_msgSequencer.seq_FindFirstIndex.return:5
TEST.VALUE:hmi_msgSequencer.seq_FindNextIndex.return:4
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.seq_ViewMask:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[4]:miUndefined
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[5]:INF_MSG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_ViewMessage.Id:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MessageID:HW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.MsgIndex:3
TEST.EXPECTED:hmi_msgSequencer.seq_UpdateViewer.inst:255
TEST.END

-- Unit: hmi_msgStore

-- Subprogram: msg_StorAckWrngRepTimerControl

-- Test Case: msg_StorAckWrngRepTimerControl.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.001
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:5
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.002
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.003
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_PAUSE
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.004
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESUME
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESUME
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.005
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESTART
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.006
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:ACK_WRNG_REP_TIMER_RESTART
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_RESTART
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepTimerControl.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepTimerControl
TEST.NEW
TEST.NAME:msg_StorAckWrngRepTimerControl.008
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_AckWrngRepTimerAction:10
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepTimerControl.p_inst:1
TEST.END

-- Subprogram: msg_StorAckWrngRepUpdate

-- Test Case: msg_StorAckWrngRepUpdate.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.001
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:5
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.002
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:22
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.003
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:22
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 88>>
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:(22)"0"
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:(22)0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:(22)OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:(22)65535
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:(22)AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:(22)AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:(22)NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:(22)NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:(22)NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:(22)"0"
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:(22)1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.004
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:22
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 2>>
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"0"
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:65535
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_AckWrng_Rep_TimerStatus[1]:ACK_WRNG_REP_TIMER_PAUSE
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"0"
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.005
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:22
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:65535
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Test Case: msg_StorAckWrngRepUpdate.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorAckWrngRepUpdate
TEST.NEW
TEST.NAME:msg_StorAckWrngRepUpdate.006
TEST.STUB:hmi_msgTest.hmi_stub_timer_check
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:22
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.return:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:<<malloc 5>>
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.VALUE:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:65535
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:"1000"
TEST.EXPECTED:hmi_msgStore.msg_StorAckWrngRepUpdate.p_inst:1
TEST.END

-- Subprogram: msg_StoreAdd

-- Test Case: msg_StoreAdd.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.001
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexUp
TEST.STUB:hmi_msgStore.stor_Insert
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].ConditionQualifier:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].EventQualifier:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0x4
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:6
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:HW_WARN_1
TEST.ATTRIBUTES:uut_prototype_stubs.test_EventCallback.msgData[0]:EXPECTED_BASE=16
TEST.END

-- Test Case: msg_StoreAdd.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.002
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0x8
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0xC
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Options::INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreAdd.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.003
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexUp
TEST.STUB:hmi_msgStore.stor_Insert
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OF_WARN_1].InstanceID:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:6
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:HW_WARN_1
TEST.END

-- Test Case: msg_StoreAdd.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:miUndefined
TEST.END

-- Test Case: msg_StoreAdd.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0..1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_StoreAdd.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.006
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexUp
TEST.STUB:hmi_msgStore.stor_Insert
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:6
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:HW_WARN_1
TEST.END

-- Test Case: msg_StoreAdd.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.007
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexUp
TEST.STUB:hmi_msgStore.stor_Insert
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OF_WARN_1].Priority:4
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Priority:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[OF_WARN_1].Priority:4
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Priority:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:5
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:HW_WARN_1
TEST.END

-- Test Case: msg_StoreAdd.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.008
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OF_WARN_1].Priority:4
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Priority:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Options:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[OF_WARN_1].Priority:4
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Priority:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.END

-- Test Case: msg_StoreAdd.009
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreAdd
TEST.NEW
TEST.NAME:msg_StoreAdd.009
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexUp
TEST.STUB:hmi_msgStore.stor_Insert
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Options:0xFFFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.VALUE:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Options:65535
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:""
TEST.EXPECTED:hmi_msgStore.msg_StoreAdd.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:6
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:HW_WARN_1
TEST.END

-- Subprogram: msg_StoreGetCurrent

-- Test Case: msg_StoreGetCurrent.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.001
TEST.VALUE:hmi_msgStore.msg_StoreGetCurrent.p_inst:0
TEST.EXPECTED:hmi_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Test Case: msg_StoreGetCurrent.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreGetCurrent
TEST.NEW
TEST.NAME:msg_StoreGetCurrent.002
TEST.VALUE:hmi_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Id:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.EXPECTED:hmi_msgStore.msg_StoreGetCurrent.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StoreGetCurrent.return:0
TEST.END

-- Subprogram: msg_StoreInitialise

-- Test Case: msg_StoreInitialise.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.001
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMask:0xFFFFFFFF
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[1]:0
TEST.END

-- Test Case: msg_StoreInitialise.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreInitialise
TEST.NEW
TEST.NAME:msg_StoreInitialise.002
TEST.VALUE:hmi_msgStore.msg_StoreInitialise.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[1]:0
TEST.EXPECTED:hmi_msgStore.msg_StoreInitialise.inst:5
TEST.END

-- Subprogram: msg_StoreIsMsgPresentInStoreQueue

-- Test Case: Warning_Absent
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:Warning_Absent
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.return:0
TEST.ATTRIBUTES:uut_prototype_stubs.test_EventCallback.msgData[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[2].EventQualifier:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options::INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]::EXPECTED_BASE=16
TEST.END

-- Test Case: Warning_Invalid
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:Warning_Invalid
TEST.VALUE:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:miUndefined
TEST.EXPECTED:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.return:0
TEST.END

-- Test Case: Warning_Present
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreIsMsgPresentInStoreQueue
TEST.NEW
TEST.NAME:Warning_Present
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.msg_StoreIsMsgPresentInStoreQueue.return:1
TEST.ATTRIBUTES:uut_prototype_stubs.test_EventCallback.msgData[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]::EXPECTED_BASE=16
TEST.END

-- Subprogram: msg_StorePurgeFromList

-- Test Case: msg_StorePurgeFromList.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.001
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[2]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[3]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:3
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.002
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:0x0
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0]:OF_WARN_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[1]:OF_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[1..3]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:0
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.003
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.inst:1
TEST.END

-- Test Case: msg_StorePurgeFromList.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StorePurgeFromList
TEST.NEW
TEST.NAME:msg_StorePurgeFromList.004
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:0xFF
TEST.VALUE:hmi_msgStore.msg_StorePurgeFromList.inst:5
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[1].seq_MessageList[0]:NAC_NO_CYCLE_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].InstanceID:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.FilterOptions:255
TEST.EXPECTED:hmi_msgStore.msg_StorePurgeFromList.inst:5
TEST.END

-- Subprogram: msg_StoreRemove

-- Test Case: msg_StoreRemove.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.001
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:miMaximum
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.002
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:miUndefined
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.return:0
TEST.END

-- Test Case: msg_StoreRemove.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].ConditionQualifier:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].EventQualifier:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0x0
TEST.ATTRIBUTES:uut_prototype_stubs.test_EventCallback.msgData[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[2].EventQualifier:INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreRemove.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.004
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.STUB:hmi_msgStore.stor_IndexDown
TEST.STUB:hmi_msgStore.stor_Delete
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:4
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0x0
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.return:1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_Delete.Index:3
TEST.ATTRIBUTES:uut_prototype_stubs.test_EventCallback.msgData[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[2].EventQualifier:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[5].EventQualifier:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgStore.<<GLOBAL>>.messageList[5].Options:INPUT_BASE=16
TEST.END

-- Test Case: msg_StoreRemove.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.END

-- Test Case: msg_StoreRemove.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.006
TEST.STUB:hmi_msgStore.stor_UpdateViewer
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:1
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_StoredFlags[0]:0
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.return:1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:0
TEST.END

-- Test Case: msg_StoreRemove.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.007
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.END

-- Test Case: msg_StoreRemove.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreRemove
TEST.NEW
TEST.NAME:msg_StoreRemove.008
TEST.VALUE:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:4098
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.hmi_msg_inst_config_count[0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].InstanceID:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_2].Options:4098
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Ack_Wrng_RepDuration:""
TEST.EXPECTED:hmi_msgStore.msg_StoreRemove.MessageID:SW_WARN_2
TEST.END

-- Subprogram: msg_StoreSelectFirst

-- Test Case: msg_StoreSelectFirst.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.001
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMask:2
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:50
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.002
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMask:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:11
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.003
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_1
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:15
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Test Case: msg_StoreSelectFirst.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectFirst
TEST.NEW
TEST.NAME:msg_StoreSelectFirst.004
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_1
TEST.VALUE:hmi_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:15
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectFirst.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectFirst.return:0
TEST.END

-- Subprogram: msg_StoreSelectNext

-- Test Case: msg_StoreSelectNext.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.001
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.002
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.003
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OK_COND_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Test Case: msg_StoreSelectNext.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectNext
TEST.NEW
TEST.NAME:msg_StoreSelectNext.004
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindFirstIndex
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OK_COND_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.msg_StoreSelectNext.p_inst:5
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:25
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.return:3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:6
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectNext.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectNext.return:0
TEST.END

-- Subprogram: msg_StoreSelectPrevious

-- Test Case: msg_StoreSelectPrevious.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.001
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.002
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.003
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Test Case: msg_StoreSelectPrevious.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:msg_StoreSelectPrevious
TEST.NEW
TEST.NAME:msg_StoreSelectPrevious.004
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:6
TEST.VALUE:hmi_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:15
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectPrevious.p_inst:5
TEST.EXPECTED:hmi_msgStore.msg_StoreSelectPrevious.return:0
TEST.END

-- Subprogram: stor_Delete

-- Test Case: stor_Delete.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_Delete.Index:3
TEST.VALUE:hmi_msgStore.stor_Delete.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_Delete.Index:2
TEST.VALUE:hmi_msgStore.stor_Delete.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.END

-- Test Case: stor_Delete.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_Delete.Index:1
TEST.VALUE:hmi_msgStore.stor_Delete.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_Delete.Index:1
TEST.VALUE:hmi_msgStore.stor_Delete.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.END

-- Test Case: stor_Delete.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Delete
TEST.NEW
TEST.NAME:stor_Delete.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_Delete.Index:1
TEST.VALUE:hmi_msgStore.stor_Delete.inst:5
TEST.EXPECTED:hmi_msgStore.stor_Delete.inst:5
TEST.END

-- Subprogram: stor_FindFirstIndex

-- Test Case: stor_FindFirstIndex.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.001
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.CategoryMask:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:5
TEST.EXPECTED:hmi_msgStore.stor_FindFirstIndex.return:5
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.END

-- Test Case: stor_FindFirstIndex.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.002
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.CategoryMask:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:<<MAX>>
TEST.EXPECTED:hmi_msgStore.stor_FindFirstIndex.return:<<MAX>>
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:<<MIN>>
TEST.END

-- Test Case: stor_FindFirstIndex.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindFirstIndex
TEST.NEW
TEST.NAME:stor_FindFirstIndex.003
TEST.STUB:hmi_msgStore.stor_FindNextIndex
TEST.VALUE:hmi_msgStore.stor_FindFirstIndex.CategoryMask:12
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.return:500
TEST.EXPECTED:hmi_msgStore.stor_FindFirstIndex.return:500
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:0
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:12
TEST.END

-- Subprogram: stor_FindNextIndex

-- Test Case: stor_FindNextIndex.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Category:mcHardWarning
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_2].Category:mcInformation
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:OK_COND_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:1
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:0x3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Category:mcHardWarning
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_2].Category:mcInformation
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:INF_MSG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:OK_COND_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:1
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:1
TEST.END

-- Test Case: stor_FindNextIndex.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:NON_AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:NON_AUTO_CANCEL_WRNG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.006
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.inst:5
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.008
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[NON_AUTO_CANCEL_WRNG_2].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.inst:1
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:0
TEST.END

-- Test Case: stor_FindNextIndex.009
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindNextIndex
TEST.NEW
TEST.NAME:stor_FindNextIndex.009
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Category:mcHardWarning
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_2].Category:mcInformation
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.Start:1
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.CategoryMask:0x3
TEST.VALUE:hmi_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].InstanceID:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_1].Category:mcHardWarning
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[HW_WARN_2].Category:mcInformation
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.Start:1
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.inst:0
TEST.EXPECTED:hmi_msgStore.stor_FindNextIndex.return:5
TEST.END

-- Subprogram: stor_FindPreviousIndex

-- Test Case: stor_FindPreviousIndex.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.Start:0
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.return:0
TEST.END

-- Test Case: stor_FindPreviousIndex.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:7
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.Start:4
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.CategoryMask:3
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.return:1
TEST.END

-- Test Case: stor_FindPreviousIndex.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:OF_WARN_1
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Test Case: stor_FindPreviousIndex.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:OF_WARN_1
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.Start:5
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.inst:5
TEST.END

-- Test Case: stor_FindPreviousIndex.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_FindPreviousIndex
TEST.NEW
TEST.NAME:stor_FindPreviousIndex.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:4
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.Start:32
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.CategoryMask:4
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.inst:0
TEST.EXPECTED:hmi_msgStore.stor_FindPreviousIndex.return:2
TEST.END

-- Subprogram: stor_GetCategories

-- Test Case: stor_GetCategories.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][0]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:8
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:5
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:1
TEST.END

-- Test Case: stor_GetCategories.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:6
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:2
TEST.END

-- Test Case: stor_GetCategories.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:50
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:10
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:4
TEST.END

-- Test Case: stor_GetCategories.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:15
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:100
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:15
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:8
TEST.END

-- Test Case: stor_GetCategories.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:10
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:50
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:20
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:16
TEST.END

-- Test Case: stor_GetCategories.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.006
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:0
TEST.END

-- Test Case: stor_GetCategories.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetCategories
TEST.NEW
TEST.NAME:stor_GetCategories.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:10
TEST.VALUE:hmi_msgStore.stor_GetCategories.Threshold:<<MAX>>
TEST.VALUE:hmi_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.inst:5
TEST.EXPECTED:hmi_msgStore.stor_GetCategories.return:0
TEST.END

-- Subprogram: stor_GetViewCount

-- Test Case: stor_GetViewCount.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:2
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:1
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:<<MAX>>
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.006
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.VALUE:hmi_msgStore.stor_GetViewCount.inst:0,1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Test Case: stor_GetViewCount.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.008
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:hmi_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.inst:1
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:1
TEST.END

-- Test Case: stor_GetViewCount.009
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewCount
TEST.NEW
TEST.NAME:stor_GetViewCount.009
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].Options:0xFF
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.VALUE:hmi_msgStore.stor_GetViewCount.CategaoryMask:0xFF
TEST.VALUE:hmi_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[SW_WARN_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].Options:255
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miMaximum
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.CategaoryMask:255
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.inst:5
TEST.EXPECTED:hmi_msgStore.stor_GetViewCount.return:0
TEST.END

-- Subprogram: stor_GetViewIndex

-- Test Case: stor_GetViewIndex.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:<<MIN>>
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:OK_COND_2
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:OK_COND_2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:HW_WARN_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.005
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:OF_WARN_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:3
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.006
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:HW_WARN_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.008
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:15
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Test Case: stor_GetViewIndex.009
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.009
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Category:15
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:0xFF
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:3
TEST.END

-- Test Case: stor_GetViewIndex.010
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_GetViewIndex
TEST.NEW
TEST.NAME:stor_GetViewIndex.010
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[INF_MSG_1].Category:15
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:6
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.MessageID:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.CategoryMask:0x0
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.inst:0
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.return:0
TEST.END

-- Subprogram: stor_IndexDown

-- Test Case: stor_IndexDown.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:hmi_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:9
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:19
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:29
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:39
TEST.END

-- Test Case: stor_IndexDown.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_IndexDown
TEST.NEW
TEST.NAME:stor_IndexDown.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:hmi_msgStore.stor_IndexDown.BaseCategory:2
TEST.VALUE:hmi_msgStore.stor_IndexDown.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.EXPECTED:hmi_msgStore.stor_IndexDown.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.stor_IndexDown.inst:5
TEST.END

-- Subprogram: stor_IndexUp

-- Test Case: stor_IndexUp.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:11
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:21
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:31
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:41
TEST.END

-- Test Case: stor_IndexUp.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_IndexUp
TEST.NEW
TEST.NAME:stor_IndexUp.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:10
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][3]:20
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][4]:30
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:40
TEST.VALUE:hmi_msgStore.stor_IndexUp.BaseCategory:2
TEST.VALUE:hmi_msgStore.stor_IndexUp.inst:5
TEST.EXPECTED:hmi_msgStore.stor_IndexUp.inst:5
TEST.END

-- Subprogram: stor_InitIndex

-- Test Case: stor_InitIndex.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.001
TEST.VALUE:hmi_msgStore.stor_InitIndex.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Test Case: stor_InitIndex.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_InitIndex
TEST.NEW
TEST.NAME:stor_InitIndex.002
TEST.VALUE:hmi_msgStore.stor_InitIndex.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][1]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][2]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][3]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][4]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][6]:0
TEST.END

-- Subprogram: stor_InitList

-- Test Case: stor_InitList.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.001
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][9]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][10]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][11]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][12]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][13]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][14]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.002
TEST.VALUE:hmi_msgStore.stor_InitList.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][2]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][6]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][7]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][8]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][9]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][10]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][11]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][12]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][13]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][14]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][15]:miUndefined
TEST.END

-- Test Case: stor_InitList.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_InitList
TEST.NEW
TEST.NAME:stor_InitList.003
TEST.VALUE:hmi_msgStore.stor_InitList.inst:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:OF_WARN_1
TEST.END

-- Subprogram: stor_Insert

-- Test Case: stor_Insert.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.001
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.VALUE:hmi_msgStore.stor_Insert.Index:0
TEST.VALUE:hmi_msgStore.stor_Insert.Value:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.messageList[AUTO_CANCEL_WRNG_1].Category:mcAutoCancel
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][6]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][7]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][8]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:AUTO_CANCEL_WRNG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][6]:8
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][4]:3
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[1][5]:7
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:0
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:AUTO_CANCEL_WRNG_1
TEST.END

-- Test Case: stor_Insert.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.002
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_Insert.Index:4
TEST.VALUE:hmi_msgStore.stor_Insert.Value:OK_COND_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:OK_COND_1
TEST.END

-- Test Case: stor_Insert.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.003
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_Insert.Index:4
TEST.VALUE:hmi_msgStore.stor_Insert.Value:OK_COND_1
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:4
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:OK_COND_1
TEST.END

-- Test Case: stor_Insert.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_Insert
TEST.NEW
TEST.NAME:stor_Insert.004
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.messageList[OK_COND_1].InstanceID:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][5]:4
TEST.VALUE:hmi_msgStore.stor_Insert.Index:4
TEST.VALUE:hmi_msgStore.stor_Insert.Value:miMaximum
TEST.EXPECTED:hmi_msgStore.stor_Insert.Index:4
TEST.EXPECTED:hmi_msgStore.stor_Insert.Value:miMaximum
TEST.END

-- Subprogram: stor_UpdateViewer

-- Test Case: stor_UpdateViewer.001
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.001
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:1
TEST.END

-- Test Case: stor_UpdateViewer.002
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.002
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_2
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:50
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:1
TEST.END

-- Test Case: stor_UpdateViewer.003
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.003
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:INF_MSG_2
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:55
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:4
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:1
TEST.END

-- Test Case: stor_UpdateViewer.004
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.004
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.return:5
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:1
TEST.END

-- Test Case: stor_UpdateViewer.005
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.005
TEST.STUB:hmi_msgStore.stor_GetViewCount
TEST.STUB:hmi_msgStore.stor_GetViewIndex
TEST.VALUE:hmi_msgStore.stor_GetViewCount.return:4000
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_GetViewIndex.inst:5
TEST.EXPECTED:uut_prototype_stubs.test_Notification.msgSource:1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_GetViewIndex.inst:0
TEST.END

-- Test Case: stor_UpdateViewer.006
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.006
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.inst:5
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:5
TEST.END

-- Test Case: stor_UpdateViewer.007
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.007
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:OF_WARN_1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.008
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.008
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:miUndefined
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:6
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.009
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.009
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Test Case: stor_UpdateViewer.010
TEST.UNIT:hmi_msgStore
TEST.SUBPROGRAM:stor_UpdateViewer
TEST.NEW
TEST.NAME:stor_UpdateViewer.010
TEST.STUB:hmi_msgStore.stor_FindPreviousIndex
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:SW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:SW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.VALUE:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.VALUE:hmi_msgStore.stor_FindPreviousIndex.return:7
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.hmi_msg_inst_config_count[0]:5
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][0]:SW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[1][1]:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Id:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[1].Position:5
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.MessageID:SW_WARN_2
TEST.EXPECTED:hmi_msgStore.stor_UpdateViewer.inst:1
TEST.END

-- Unit: hmi_msgTask

-- Subprogram: hm_msg_GetStatus

-- Test Case: hm_msg_GetStatus.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.001
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x100
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x100
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.002
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.002
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x1
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.p_inst:0
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:1
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.003
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.003
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x2
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x2
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x2
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:2
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.004
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.004
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MAX>>
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:<<MAX>>
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0xFFFFFEFF
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:4294967295
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.ATTRIBUTES:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:INPUT_BASE=16
TEST.ATTRIBUTES:hmi_msgTask.hm_msg_GetStatus.Qualifier:INPUT_BASE=16
TEST.END

-- Test Case: hm_msg_GetStatus.005
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.005
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x1
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:1
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.006
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.006
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x3
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x3
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x3
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:3
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Test Case: hm_msg_GetStatus.007
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_GetStatus
TEST.NEW
TEST.NAME:hm_msg_GetStatus.007
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.VALUE:hmi_msgTask.hm_msg_GetStatus.Qualifier:0x3
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0x1
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.Qualifier:3
TEST.EXPECTED:hmi_msgTask.hm_msg_GetStatus.return:0
TEST.END

-- Subprogram: hm_msg_KSColdInit

-- Test Case: hm_msg_KSColdInit.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSColdInit
TEST.NEW
TEST.NAME:hm_msg_KSColdInit.001
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorInitialise
TEST.STUB:hmi_msgSequencer.msg_SequencerInitialise
TEST.STUB:hmi_msgStore.msg_StoreInitialise
TEST.STUB:hmi_msgTask.msg_TaskInitialise
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0
TEST.END

-- Test Case: hm_msg_KSColdInit.001.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSColdInit
TEST.NEW
TEST.NAME:hm_msg_KSColdInit.001.001
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorInitialise
TEST.STUB:hmi_msgSequencer.msg_SequencerInitialise
TEST.STUB:hmi_msgStore.msg_StoreInitialise
TEST.STUB:hmi_msgTask.msg_TaskInitialise
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0
TEST.END

-- Subprogram: hm_msg_KSNvRamCheck

-- Test Case: hm_msg_KSNvRamCheck.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSNvRamCheck
TEST.NEW
TEST.NAME:hm_msg_KSNvRamCheck.001
TEST.EXPECTED:hmi_msgTask.hm_msg_KSNvRamCheck.return:1
TEST.END

-- Test Case: hm_msg_KSNvRamCheck.001.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSNvRamCheck
TEST.NEW
TEST.NAME:hm_msg_KSNvRamCheck.001.001
TEST.EXPECTED:hmi_msgTask.hm_msg_KSNvRamCheck.return:1
TEST.END

-- Subprogram: hm_msg_KSRRobin

-- Test Case: hm_msg_KSRRobin.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.001
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:<<MIN>>
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MIN>>
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Test Case: hm_msg_KSRRobin.002
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.002
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:2
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:255
TEST.END

-- Test Case: hm_msg_KSRRobin.003
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.003
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:0
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Test Case: hm_msg_KSRRobin.004
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.004
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:<<MAX>>
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:1
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Test Case: hm_msg_KSRRobin.005
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.005
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:<<MAX>>
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MAX>>
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Test Case: hm_msg_KSRRobin.006
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSRRobin
TEST.NEW
TEST.NAME:hm_msg_KSRRobin.006
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorUpdate
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:<<MID>>
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:<<MID>>
TEST.EXPECTED:hmi_msgArbitrator.msg_ArbitratorUpdate.Ignition:<<MAX>>
TEST.END

-- Subprogram: hm_msg_KSSleep

-- Test Case: hm_msg_KSSleep.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSSleep
TEST.NEW
TEST.NAME:hm_msg_KSSleep.001
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:""
TEST.END

-- Subprogram: hm_msg_KSWakeup

-- Test Case: hm_msg_KSWakeup.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSWakeup
TEST.NEW
TEST.NAME:hm_msg_KSWakeup.001
TEST.STUB:hmi_msgSequencer.msg_SequencerInitialise
TEST.STUB:hmi_msgStore.msg_StoreInitialise
TEST.STUB:hmi_msgTask.msg_TaskInitialise
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:0
TEST.END

-- Subprogram: hm_msg_KSWarmInit

-- Test Case: hm_msg_KSWarmInit.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:hm_msg_KSWarmInit
TEST.NEW
TEST.NAME:hm_msg_KSWarmInit.001
TEST.STUB:hmi_msgArbitrator.msg_ArbitratorInitialise
TEST.EXPECTED:hmi_msgArbitrator.<<GLOBAL>>.arb_MessageStatus:""
TEST.EXPECTED:hmi_msgSequencer.<<GLOBAL>>.l_msg_instance_array[0].seq_MessageList[0..5]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][4]:miUndefined
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][5]:miUndefined
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:3
TEST.END

-- Subprogram: msg_TaskInitialise

-- Test Case: msg_TaskInitialise.001
TEST.UNIT:hmi_msgTask
TEST.SUBPROGRAM:msg_TaskInitialise
TEST.NEW
TEST.NAME:msg_TaskInitialise.001
TEST.VALUE:hmi_msgTask.<<GLOBAL>>.msgStatus:0
TEST.EXPECTED:hmi_msgTask.<<GLOBAL>>.msgStatusQualifier:3
TEST.END

-- Unit: hmi_msgTest

-- Subprogram: hmi_stub_msg_get_current

-- Test Case: hmi_stub_msg_get_current.001
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_msg_get_current
TEST.NEW
TEST.NAME:hmi_stub_msg_get_current.001
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Id:INF_MSG_1
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Position:2
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Count:1
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Status:0
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.InstanceID:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:INF_MSG_1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Id:HW_WARN_2
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:1
TEST.VALUE:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_msg_data.Id:HW_WARN_2
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_msg_data.Position:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_msg_data.Count:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_msg_data.Status:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_msg_data.InstanceID:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_prev_msg_data.Id:OF_WARN_1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_prev_msg_data.Position:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_prev_msg_data.Count:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_prev_msg_data.Status:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_prev_msg_data.InstanceID:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Id:HW_WARN_1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Position:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Count:1
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.Status:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.fl_next_msg_data.InstanceID:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][0]:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][1]:HW_WARN_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][2]:INF_MSG_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_MessageList[0][3]:INF_MSG_2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][0]:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][1]:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_Categories[0][2]:2
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Id:HW_WARN_1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Position:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Count:0
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].Status:1
TEST.EXPECTED:hmi_msgStore.<<GLOBAL>>.stor_ViewMessage[0].InstanceID:0
TEST.END

-- Subprogram: hmi_stub_timer_check

-- Test Case: TIMER_ELAPSED
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_check
TEST.NEW
TEST.NAME:TIMER_ELAPSED
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:300
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.return:0x2
TEST.END

-- Test Case: TIMER_ID_INVALID
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_check
TEST.NEW
TEST.NAME:TIMER_ID_INVALID
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:255
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.return:0
TEST.END

-- Test Case: TIMER_NOT_RUNNING
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_check
TEST.NEW
TEST.NAME:TIMER_NOT_RUNNING
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:0
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.return:0x0
TEST.END

-- Test Case: TIMER_RUNNING
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_check
TEST.NEW
TEST.NAME:TIMER_RUNNING
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeElapsed:100
TEST.VALUE:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.VALUE:hmi_msgTest.hmi_stub_timer_check.timer_id:0
TEST.EXPECTED:hmi_msgTest.hmi_stub_timer_check.return:0x1
TEST.END

-- Subprogram: hmi_stub_timer_start

-- Test Case: TIMER_ID_INVALID
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_start
TEST.NEW
TEST.NAME:TIMER_ID_INVALID
TEST.VALUE:hmi_msgTest.hmi_stub_timer_start.timer_id:255
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:0
TEST.END

-- Test Case: TIMER_STARTED
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_start
TEST.NEW
TEST.NAME:TIMER_STARTED
TEST.VALUE:hmi_msgTest.hmi_stub_timer_start.timeout:200
TEST.VALUE:hmi_msgTest.hmi_stub_timer_start.timer_id:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:200
TEST.END

-- Subprogram: hmi_stub_timer_stop

-- Test Case: TIMER_ID_INVALID
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_stop
TEST.NEW
TEST.NAME:TIMER_ID_INVALID
TEST.VALUE:hmi_msgTest.hmi_stub_timer_stop.timer_id:255
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:0
TEST.END

-- Test Case: TIMER_STOPPED
TEST.UNIT:hmi_msgTest
TEST.SUBPROGRAM:hmi_stub_timer_stop
TEST.NEW
TEST.NAME:TIMER_STOPPED
TEST.VALUE:hmi_msgTest.hmi_stub_timer_stop.timer_id:0
TEST.EXPECTED:hmi_msgTest.<<GLOBAL>>.StubTimeOut[0]:0
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_ABSENT
TEST.SLOT: "1", "hmi_msgStore", "msg_StoreRemove", "1", "msg_StoreRemove.003"
TEST.SLOT: "2", "hmi_msgStore", "msg_StoreIsMsgPresentInStoreQueue", "1", "Warning_Absent"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_WARNING_PRESENT
TEST.SLOT: "1", "hmi_msgStore", "msg_StoreAdd", "1", "msg_StoreAdd.001"
TEST.SLOT: "2", "hmi_msgStore", "msg_StoreIsMsgPresentInStoreQueue", "1", "Warning_Present"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionInvalid
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate.Invalid_Compound"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_ConditionOFF
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate..DeActive_Multi_Compound"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate.Invalid_ActiveState_Compound"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidActiveState.001
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate.Invalid_ActiveState_Compound.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate.Invalid_IgnMode_Compound"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_InvalidIGN.Inst_1
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "3", "hmi_msgArbitrator", "msg_ArbitratorUpdate", "1", "msg_ArbitratorUpdate.Invalid_IgnMode_Compound.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:Multi_SeqAdd
TEST.SLOT: "1", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.001"
TEST.SLOT: "2", "hmi_msgSequencer", "msg_SequencerInitialise", "1", "msg_SequencerInitialise.002"
TEST.SLOT: "3", "hmi_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.001"
TEST.SLOT: "4", "hmi_msgSequencer", "msg_SequencerAdd", "1", "msg_SequencerAdd.002"
TEST.END
--
