-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLADVMF
-- Unit(s) Under Test: UclVmfInterface UclVmfProxy main
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclVmfInterface

-- Subprogram: (cl)CUclVmfInterface::CUclVmfInterface

-- Test Case: (cl)CUclVmfInterface::CUclVmfInterface.true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::CUclVmfInterface
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::CUclVmfInterface.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.END

-- Subprogram: (cl)CUclVmfInterface::connectToVmf

-- Test Case: (cl)CUclVmfInterface::connectToVmf.false
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::connectToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::connectToVmf.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:<<malloc 4>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:"abc"
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::connectToVmf.groupList_nul
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::connectToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::connectToVmf.groupList_nul
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::connectToVmf.nw_vmf_reg_msg_group
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::connectToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::connectToVmf.nw_vmf_reg_msg_group
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:<<malloc 4>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:"abc"
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:-1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.return:-1
TEST.END

-- Test Case: (cl)CUclVmfInterface::connectToVmf.true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::connectToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::connectToVmf.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:<<malloc 3>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.groupsListPtr:"ab"
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::connectToVmf.return:-1
TEST.END

-- Subprogram: (cl)CUclVmfInterface::disConnectFromVmf

-- Test Case: (cl)CUclVmfInterface::disConnectFromVmf.vmf_disconnect_ok
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::disConnectFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::disConnectFromVmf.vmf_disconnect_ok
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:<<malloc 4>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:"dfl"
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.numGroups:45
TEST.VALUE:uut_prototype_stubs.nw_vmf_disconnect.return:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_de_register_msg_group.return:2
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::disConnectFromVmf.vmf_ret_false
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::disConnectFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::disConnectFromVmf.vmf_ret_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:<<malloc 4>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:"dfl"
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.numGroups:45
TEST.VALUE:uut_prototype_stubs.nw_vmf_disconnect.return:-1
TEST.VALUE:uut_prototype_stubs.nw_vmf_de_register_msg_group.return:2
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.return:-1
TEST.END

-- Test Case: (cl)CUclVmfInterface::disConnectFromVmf.vmf_ret_true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::disConnectFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::disConnectFromVmf.vmf_ret_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:<<malloc 4>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.groupsListPtr:"dfl"
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.numGroups:45
TEST.VALUE:uut_prototype_stubs.nw_vmf_disconnect.return:-1
TEST.VALUE:uut_prototype_stubs.nw_vmf_de_register_msg_group.return:-1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::disConnectFromVmf.return:-1
TEST.END

-- Subprogram: (cl)CUclVmfInterface::receiveFromVmf

-- Test Case: (cl)CUclVmfInterface::receiveFromVmf.initialize
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::receiveFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::receiveFromVmf.initialize
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:-1
TEST.END

-- Test Case: (cl)CUclVmfInterface::receiveFromVmf.initialize.PayloadSize_false
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::receiveFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::receiveFromVmf.initialize.PayloadSize_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.vmfMsgPtr:<<malloc 2>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.vmfMsgPtr[0].PayloadSize:8300
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_most_msg.data.length:8200
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_basic_msg.data.length:8200
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::receiveFromVmf.initialize.RxLen>0
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::receiveFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::receiveFromVmf.initialize.RxLen>0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.vmfMsgPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::receiveFromVmf.initialize.msg_data_length_true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::receiveFromVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::receiveFromVmf.initialize.msg_data_length_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.vmfMsgPtr:<<malloc 2>>
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.vmfMsgPtr[0].PayloadSize:8200
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_most_msg.data.length:1
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].VCAST_ANONYMOUS_FIELD_1.vmf_basic_msg.data.length:1
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.return:1
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:0
TEST.END

-- Subprogram: (cl)CUclVmfInterface::sendToVmf

-- Test Case: (cl)CUclVmfInterface::sendToVmf.true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::sendToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::sendToVmf.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.vmfMsgPtr:<<malloc 2>>
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:0
TEST.END

-- Test Case: (cl)CUclVmfInterface::sendToVmf.true.nw_vmf_send_basic_notok
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::sendToVmf
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::sendToVmf.true.nw_vmf_send_basic_notok
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.vmfMsgPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:2
TEST.EXPECTED:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:-1
TEST.END

-- Subprogram: (cl)CUclVmfInterface::~CUclVmfInterface

-- Test Case: (cl)CUclVmfInterface::~CUclVmfInterface.true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)CUclVmfInterface::~CUclVmfInterface
TEST.NEW
TEST.NAME:(cl)CUclVmfInterface::~CUclVmfInterface.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.END

-- Subprogram: (cl)std::this_thread::sleep_for

-- Test Case: (cl)std::this_thread::sleep_for.true
TEST.UNIT:UclVmfInterface
TEST.SUBPROGRAM:(cl)std::this_thread::sleep_for
TEST.NEW
TEST.NAME:(cl)std::this_thread::sleep_for.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.END

-- Unit: UclVmfProxy

-- Subprogram: (cl)CUclVmfProxy::start

-- Test Case: (cl)CUclVmfProxy::start.GroupList_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::start
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::start.GroupList_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::start.return:-1
TEST.END

-- Test Case: (cl)CUclVmfProxy::start.GroupList_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::start
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::start.GroupList_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.NumGroups:6
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.return:4
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::start.return:0
TEST.END

-- Test Case: (cl)CUclVmfProxy::start.GroupList_true.NumGroup_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::start
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::start.GroupList_true.NumGroup_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.NumGroups:0
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.return:4
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::start.return:-1
TEST.END

-- Test Case: (cl)CUclVmfProxy::start.GroupList_true.Sys_Initialize_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::start
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::start.GroupList_true.Sys_Initialize_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.NumGroups:6
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.return:4
TEST.VALUE:uut_prototype_stubs.UclSys_Initialize.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::start.return:1
TEST.END

-- Test Case: (cl)CUclVmfProxy::start.GroupList_true.Sys_Initialize_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::start
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::start.GroupList_true.Sys_Initialize_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.NumGroups:6
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.return:4
TEST.VALUE:uut_prototype_stubs.UclSys_Initialize.return:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::start.return:0
TEST.END

-- Subprogram: (cl)CUclVmfProxy::stop

-- Test Case: (cl)CUclVmfProxy::stop.GroupList_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::stop
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::stop.GroupList_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::stop.return:0
TEST.END

-- Test Case: (cl)CUclVmfProxy::stop.GroupList_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::stop
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::stop.GroupList_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::stop.return:0
TEST.END

-- Test Case: (cl)CUclVmfProxy::stop.GroupList_true.NumGroups_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::stop
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::stop.GroupList_true.NumGroups_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfInterface.<<GLOBAL>>.(cl).CUclVmfInterface.CUclVmfInterface.<<constructor>>.CUclVmfInterface().<<call>>:0
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.GxList[0]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::getVmfGroupList.NumGroups:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.EXPECTED:UclVmfProxy.(cl)CUclVmfProxy::stop.return:0
TEST.END

-- Subprogram: (cl)CUclVmfProxy::uclDispatchThread

-- Test Case: (cl)CUclVmfProxy::uclDispatchThread.bRequestExit_flase
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::uclDispatchThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::uclDispatchThread.bRequestExit_flase
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:true
TEST.END

-- Test Case: (cl)CUclVmfProxy::uclDispatchThread.bRequestExit_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::uclDispatchThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::uclDispatchThread.bRequestExit_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.END

-- Test Case: (cl)CUclVmfProxy::uclDispatchThread.bRequestExit_true_lookup_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::uclDispatchThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::uclDispatchThread.bRequestExit_true_lookup_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:1
TEST.VALUE:uut_prototype_stubs.CUclVmfConfig::lookup.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.END

-- Subprogram: (cl)CUclVmfProxy::vmfRxThread

-- Test Case: (cl)CUclVmfProxy::vmfRxThread.bRequestExit_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfRxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfRxThread.bRequestExit_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:true
TEST.END

-- Test Case: (cl)CUclVmfProxy::vmfRxThread.bRequestExit_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfRxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfRxThread.bRequestExit_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.vmfIf.CUclVmfInterface.vmfConnId:0
TEST.END

-- Test Case: (cl)CUclVmfProxy::vmfRxThread.bRequestExit_true.recieveFromVmf_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfRxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfRxThread.bRequestExit_true.recieveFromVmf_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::receiveFromVmf.return:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.END

-- Subprogram: (cl)CUclVmfProxy::vmfTxThread

-- Test Case: (cl)CUclVmfProxy::vmfTxThread.bRequestExit_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfTxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfTxThread.bRequestExit_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:true
TEST.END

-- Test Case: (cl)CUclVmfProxy::vmfTxThread.bRequestExit_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfTxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfTxThread.bRequestExit_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 3>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<function 1>>
TEST.END

-- Test Case: (cl)CUclVmfProxy::vmfTxThread.bRequestExit_true.VmfMsg_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfTxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfTxThread.bRequestExit_true.VmfMsg_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 3>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<null>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<function 1>>
TEST.END

-- Test Case: (cl)CUclVmfProxy::vmfTxThread.bRequestExit_true.sendToVmf_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:(cl)CUclVmfProxy::vmfTxThread
TEST.NEW
TEST.NAME:(cl)CUclVmfProxy::vmfTxThread.bRequestExit_true.sendToVmf_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf
TEST.VALUE:UclVmfInterface.(cl)CUclVmfInterface::sendToVmf.return:1
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.bRequestExit:false
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 3>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[2]:<<function 1>>
TEST.END

-- Subprogram: UclVmfProxy_AddVmfMsgToTxQueue

-- Test Case: UclVmfProxy_AddVmfMsgToTxQueue.size_false
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:UclVmfProxy_AddVmfMsgToTxQueue
TEST.NEW
TEST.NAME:UclVmfProxy_AddVmfMsgToTxQueue.size_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.pPayload:<<malloc 7>>
TEST.VALUE:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.pPayload:"absldf"
TEST.VALUE:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.Size:820
TEST.EXPECTED:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.return:1
TEST.END

-- Test Case: UclVmfProxy_AddVmfMsgToTxQueue.size_true
TEST.UNIT:UclVmfProxy
TEST.SUBPROGRAM:UclVmfProxy_AddVmfMsgToTxQueue
TEST.NEW
TEST.NAME:UclVmfProxy_AddVmfMsgToTxQueue.size_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.<<constructor>>.CUclVmfProxy().<<call>>:0
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.txQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue:<<malloc 2>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[0]:<<function 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<malloc 1>>
TEST.VALUE:UclVmfProxy.<<GLOBAL>>.(cl).CUclVmfProxy.CUclVmfProxy.rxQueue.CUclBlockingQueue<CUclVmfInterface::SVmfMsg*>.queue[1]:<<function 1>>
TEST.VALUE:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.Size:8200
TEST.EXPECTED:UclVmfProxy.UclVmfProxy_AddVmfMsgToTxQueue.return:0
TEST.END

-- Unit: main

-- Subprogram: (cl)std::this_thread::sleep_for

-- Test Case: (cl)std::this_thread::sleep_for.true
TEST.UNIT:main
TEST.SUBPROGRAM:(cl)std::this_thread::sleep_for
TEST.NEW
TEST.NAME:(cl)std::this_thread::sleep_for.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: VCAST_main

-- Test Case: VCAST_main.acquire_ability
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.acquire_ability
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:main.acquire_ability
TEST.STUB:main.get_options
TEST.VALUE:uut_prototype_stubs.getopt.VCAST_PARAM_3:"2"
TEST.VALUE:uut_prototype_stubs.getopt.return:1
TEST.VALUE:uut_prototype_stubs.strdup.return:<<malloc 1>>
TEST.VALUE:main.<<GLOBAL>>.bRequestUclVmfExit:true
TEST.VALUE:main.<<GLOBAL>>.optind:1
TEST.VALUE:main.acquire_ability.return:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.STUB_VAL_USER_CODE:main.get_options.userParm
char* test = (char*)malloc(3* sizeof(char)); 
<<main.get_options.userParm>> = ( &test );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: VCAST_main.false
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Subprogram: acquire_ability

-- Test Case: acquire_ability.true
TEST.UNIT:main
TEST.SUBPROGRAM:acquire_ability
TEST.NEW
TEST.NAME:acquire_ability.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:main.acquire_ability.return:0
TEST.END

-- Test Case: acquire_ability.true.procmgr_true
TEST.UNIT:main
TEST.SUBPROGRAM:acquire_ability
TEST.NEW
TEST.NAME:acquire_ability.true.procmgr_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:1
TEST.EXPECTED:main.acquire_ability.return:-1
TEST.END

-- Subprogram: drop_ability

-- Test Case: drop_ability.true
TEST.UNIT:main
TEST.SUBPROGRAM:drop_ability
TEST.NEW
TEST.NAME:drop_ability.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:main.drop_ability.return:0
TEST.END

-- Test Case: drop_ability.true.procmgr_true
TEST.UNIT:main
TEST.SUBPROGRAM:drop_ability
TEST.NEW
TEST.NAME:drop_ability.true.procmgr_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:1
TEST.EXPECTED:main.drop_ability.return:-1
TEST.END

-- Subprogram: exit_handler

-- Test Case: exit_handler.true
TEST.UNIT:main
TEST.SUBPROGRAM:exit_handler
TEST.NEW
TEST.NAME:exit_handler.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:main.exit_handler.s:0
TEST.END

-- Subprogram: get_options

-- Test Case: get_options.true
TEST.UNIT:main
TEST.SUBPROGRAM:get_options
TEST.NEW
TEST.NAME:get_options.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.getopt.return:85
TEST.VALUE:main.get_options.argc:2
TEST.VALUE:main.get_options.argv:<<malloc 1>>
TEST.VALUE:main.get_options.argv[0]:<<malloc 6>>
TEST.VALUE:main.get_options.argv[0]:"abxkd"
TEST.VALUE:main.get_options.userParm:<<malloc 1>>
TEST.VALUE:main.get_options.userParm[0]:<<malloc 5>>
TEST.VALUE:main.get_options.userParm[0]:"abcd"
TEST.END

-- Test Case: get_options.true.Option_ascii_63
TEST.UNIT:main
TEST.SUBPROGRAM:get_options
TEST.NEW
TEST.NAME:get_options.true.Option_ascii_63
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.getopt.return:63
TEST.VALUE:main.get_options.argc:2
TEST.VALUE:main.get_options.argv:<<malloc 1>>
TEST.VALUE:main.get_options.argv[0]:<<malloc 6>>
TEST.VALUE:main.get_options.argv[0]:"abxkd"
TEST.VALUE:main.get_options.userParm:<<malloc 1>>
TEST.VALUE:main.get_options.userParm[0]:<<malloc 5>>
TEST.VALUE:main.get_options.userParm[0]:"abcd"
TEST.END

-- Test Case: get_options.true.Option_default
TEST.UNIT:main
TEST.SUBPROGRAM:get_options
TEST.NEW
TEST.NAME:get_options.true.Option_default
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.getopt.return:3
TEST.VALUE:main.get_options.argc:2
TEST.VALUE:main.get_options.argv:<<malloc 1>>
TEST.VALUE:main.get_options.argv[0]:<<malloc 6>>
TEST.VALUE:main.get_options.argv[0]:"abxkd"
TEST.VALUE:main.get_options.userParm:<<malloc 1>>
TEST.VALUE:main.get_options.userParm[0]:<<malloc 5>>
TEST.VALUE:main.get_options.userParm[0]:"abcd"
TEST.END

-- Test Case: get_options.true.while_false
TEST.UNIT:main
TEST.SUBPROGRAM:get_options
TEST.NEW
TEST.NAME:get_options.true.while_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.optind:1
TEST.VALUE:uut_prototype_stubs.getopt.return:3
TEST.VALUE:main.get_options.argc:1
TEST.VALUE:main.get_options.argv:<<malloc 1>>
TEST.VALUE:main.get_options.argv[0]:<<malloc 6>>
TEST.VALUE:main.get_options.argv[0]:"abxkd"
TEST.VALUE:main.get_options.userParm:<<malloc 1>>
TEST.VALUE:main.get_options.userParm[0]:<<malloc 5>>
TEST.VALUE:main.get_options.userParm[0]:"abcd"
TEST.END

-- Test Case: get_options.true.while_false_2
TEST.UNIT:main
TEST.SUBPROGRAM:get_options
TEST.NEW
TEST.NAME:get_options.true.while_false_2
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.getopt.return:-1
TEST.VALUE:main.get_options.argc:1
TEST.VALUE:main.get_options.argv:<<malloc 1>>
TEST.VALUE:main.get_options.argv[0]:<<malloc 6>>
TEST.VALUE:main.get_options.argv[0]:"abxkd"
TEST.VALUE:main.get_options.userParm:<<malloc 1>>
TEST.VALUE:main.get_options.userParm[0]:<<malloc 5>>
TEST.VALUE:main.get_options.userParm[0]:"abcd"
TEST.END

-- Subprogram: switch_to_user_mode

-- Test Case: switch_to_user_mode.get_errno_ptr_false
TEST.UNIT:main
TEST.SUBPROGRAM:switch_to_user_mode
TEST.NEW
TEST.NAME:switch_to_user_mode.get_errno_ptr_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:1
TEST.EXPECTED:main.switch_to_user_mode.return:-1
TEST.END

-- Test Case: switch_to_user_mode.set_ids_from_arg_true
TEST.UNIT:main
TEST.SUBPROGRAM:switch_to_user_mode
TEST.NEW
TEST.NAME:switch_to_user_mode.set_ids_from_arg_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:1
TEST.EXPECTED:main.switch_to_user_mode.return:-1
TEST.END

-- Test Case: switch_to_user_mode.true
TEST.UNIT:main
TEST.SUBPROGRAM:switch_to_user_mode
TEST.NEW
TEST.NAME:switch_to_user_mode.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:main.switch_to_user_mode.return:0
TEST.END
