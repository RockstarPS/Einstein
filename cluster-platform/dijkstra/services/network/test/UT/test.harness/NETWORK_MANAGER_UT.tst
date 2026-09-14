-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : NETWORK_MANAGER_UT
-- Unit(s) Under Test: network_manager network_manager_component network_manager_enet_register network_manager_tja1101 network_packet_filter_qnx
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

-- Unit: network_manager

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::configureInterfaces

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::configureInterfaces.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.mPhysicalInterface
<<dk::srvc::platform::CNetworkManager instance>>->mPhysicalInterface["phy0"] = {"fec0",0,"192.168.1.10","255.255.255.0","192.168.1.255"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::configureInterfaces.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.mPhysicalInterface
<<dk::srvc::platform::CNetworkManager instance>>->mPhysicalInterface["phy0"] = {"fec0",1,"192.168.1.10","255.255.255.0","192.168.1.255"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::configureInterfaces.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.mVirtualInterface
<<dk::srvc::platform::CNetworkManager instance>>->mVirtualInterface["virtual0"] = {"vlan0",0,6,{"fec0",0,"192.168.1.10","255.255.255.0","192.168.1.255"}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::configureInterfaces.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::configureInterfaces.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.mVirtualInterface
<<dk::srvc::platform::CNetworkManager instance>>->mVirtualInterface["virtual0"] = {"vlan0",0,6,{"fec0",1,"192.168.1.10","255.255.255.0","192.168.1.255"}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::createVlan

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl_socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl_socket.VCAST_PARAM_2:2
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl_socket.return
if(<<uut_prototype_stubs.ioctl_socket.VCAST_PARAM_2>> == 2)
{
   if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
   {
<<uut_prototype_stubs.ioctl_socket.return>> = -1;
   }
   else
   {
<<uut_prototype_stubs.ioctl.return>> = 0;
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   }
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl_socket.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 2)
{
<<uut_prototype_stubs.ioctl_socket.return>> = -1;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 2;
<<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
else
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
<<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl_socket.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 3)
{
<<uut_prototype_stubs.ioctl_socket.return>> = -1;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 2)
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 3;
<<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 2;
<<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
else
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
<<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.005
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl_socket.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.006
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.006
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.007
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.007
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.vlanPriority:6
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.__cmd:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
<<uut_prototype_stubs.ioctl.return>> = -1;
}
else
{
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
<<uut_prototype_stubs.ioctl.return>> = 0;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.008
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.008
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.009
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.009
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.vlanPriority:6
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::createVlan.010
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::createVlan.010
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.vlanPriority:8
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::destroyVlan

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::destroyVlan.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::destroyVlan.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl_socket.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
    <<uut_prototype_stubs.ioctl_socket.return>> = -1;
}
else
{
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>=1;
    <<uut_prototype_stubs.ioctl_socket.return>> = 0;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::destroyVlan.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::destroyVlan.002
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::destroyVlan.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::destroyVlan.003
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.vlanName:<<malloc 6>>
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.vlanName:"vlan0"
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:true
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::destroyVlan.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::destroyVlan.004
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl_socket.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::destroyVlan.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::destroyVlan.005
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::iniHandler

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.003
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.004
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"firewall"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::srvc::platform::CNetworkPacketFilterIf::setFilterConfiguration.configFile:"config_file"
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
    <<uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return>> = false;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   <<uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return>> = true;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.005
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.006
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.006
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
   <<uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return>> = false;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   <<uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return>> = true;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.007
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.007
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.008
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.008
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mPhysicalInterface:<<malloc 1>>
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mPhysicalInterface[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"Up"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.VALUE:uut_prototype_stubs.dk::srvc::platform::CNetworkPacketFilterIf::setFilterConfiguration.configFile:"config_file"
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.009
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.009
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mPhysicalInterface:<<malloc 1>>
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mPhysicalInterface[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"firewall"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.VALUE:uut_prototype_stubs.dk::srvc::platform::CNetworkPacketFilterIf::setFilterConfiguration.configFile:"config_file"
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.010
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.010
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"virtual0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"firewall"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumVirtualInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:8#0#
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.011
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.011
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"virtual0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"firewall"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumVirtualInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:8#0#
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
    <<uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return>> = false;
}
else
{   
    <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>=1;
    <<uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return>> = true;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.012
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.012
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"virtual0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"Up"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumVirtualInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:8#0#
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.013
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.013
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"virtual0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumVirtualInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:8#0#
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.014
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.014
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"virtual0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"firewall"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumVirtualInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:8#0#
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.015
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.015
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"/system/etc/network_manager.ini"
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return
std::string s1("/system/etc/network_manager.ini");
if((<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str>>.compare(s1)) == 0)
{
<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = false;
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = true;
}
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.016
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.016
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.sectionList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"phy0"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.section:"network"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.key:"NumPhyInterface"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.defValue:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:5
TEST.VALUE:uut_prototype_stubs.dk::srvc::platform::CNetworkPacketFilterIf::setFilterConfiguration.configFile:"config_file"
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.mPhysicalInterface
<<dk::srvc::platform::CNetworkManager instance>>->mPhysicalInterface["phy0"] = {"fec0",1,"192.168.1.10","255.255.255.0","192.168.1.255"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::iniHandler.017
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::iniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::iniHandler.017
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.<<constructor>>.ParserIf().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.parser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst:<<null>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"mIniFilePath2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllSections.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.section:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.key:"NICTYPE"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"NIC"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:true
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::init

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::init.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::init
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::init.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::isInterfaceValid

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:<<malloc 6>>
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:"vlan0"
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getifaddrs.return
struct ifaddrs *ifaddr = (struct ifaddrs*)malloc(sizeof(struct ifaddrs) * 1);;
 
ifaddr->ifa_name = "vlan0";
 
*<<uut_prototype_stubs.getifaddrs.VCAST_PARAM_1>> = ifaddr;
 
<<uut_prototype_stubs.getifaddrs.return>> = 0; 
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.002
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:<<malloc 6>>
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:"vlan0"
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getifaddrs.return
struct ifaddrs *ifaddr = (struct ifaddrs*)malloc(sizeof(struct ifaddrs) * 1);;
 
ifaddr->ifa_name = "vlan1";
 
*<<uut_prototype_stubs.getifaddrs.VCAST_PARAM_1>> = ifaddr;
 
<<uut_prototype_stubs.getifaddrs.return>> = 0; 
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.003
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:uut_prototype_stubs.getifaddrs.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.004
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:<<malloc 6>>
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:"vlan1"
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getifaddrs.return
struct ifaddrs *ifaddr = (struct ifaddrs*)malloc(sizeof(struct ifaddrs) * 1);
 
ifaddr->ifa_name = "vlan0";
ifaddr->ifa_next = NULL;
 
*<<uut_prototype_stubs.getifaddrs.VCAST_PARAM_1>> = ifaddr;
 
<<uut_prototype_stubs.getifaddrs.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::modifyFirewall

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyFirewall.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst.dk::srvc::platform::vcast_concrete_CNetworkPacketFilterIf.<<constructor>>.vcast_concrete_CNetworkPacketFilterIf().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyFirewall.requestType:EFirewallRequest_Enable
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyFirewall.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall.002
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst.dk::srvc::platform::vcast_concrete_CNetworkPacketFilterIf.<<constructor>>.vcast_concrete_CNetworkPacketFilterIf().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyFirewall.requestType:EFirewallRequest_Disable
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyFirewall.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyFirewall.003
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.mNetworkPacketFilterInst:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::modifyInterface

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyInterface.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyInterface.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.requestType:EIpRequestType_Set
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.interfaceRequestType:EInterfaceRequestType_SetLinkUp
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyInterface.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyInterface.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.requestType:EIpRequestType_Set
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.interfaceRequestType:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyInterface.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyInterface.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.requestType:EIpRequestType_Set
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyInterface.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyInterface.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface.requestType:EIpRequestType_Clear
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.linkType:EInterfaceRequestType_SetLinkUp
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.linkType:EInterfaceRequestType_SetLinkUp
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.linkType:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyLinkStatus.linkType:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.requestType:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.requestType:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.requestType:1
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::createVlan
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface.requestType:1
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::destroyVlan.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 12>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.1"
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.005
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.ifName:"vlan0"
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
ifr->ifr_ifru.ifru_flags = IFF_UP | IFF_RUNNING;
}
else
{
ifmr->ifm_status = IFM_ACTIVE;
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.006
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::monitorInterfaces.006
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.VALUE_USER_CODE:<<dk::srvc::platform::CNetworkManager instance>>.dk::srvc::platform::CNetworkManager.currentInterfaceConfig
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan0"] = {0,"192.168.1.10"};
<<dk::srvc::platform::CNetworkManager instance>>->currentInterfaceConfig["vlan1"] = {0,"192.168.1.11"};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::notifyInterfaceChanges

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::notifyInterfaceChanges.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::notifyInterfaceChanges
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::notifyInterfaceChanges.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::periodicTaskInMs

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::periodicTaskInMs.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::periodicTaskInMs
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::periodicTaskInMs.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::removeIpv4Address

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.002
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.003
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:<<malloc 13>>
TEST.VALUE:uut_prototype_stubs.inet_ntoa.return:"192.168.1.10"
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::removeIpv4Address.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::setInterfaceDown

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::notifyInterfaceChanges
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.__cmd:16#8913#
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl.return
if(<<uut_prototype_stubs.ioctl.__cmd>>==0X8913)
{
<<uut_prototype_stubs.ioctl.return>>=0;
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
<<uut_prototype_stubs.ioctl.return>>=-1;
}
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>=1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceDown.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::setInterfaceUp

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.__cmd:16#8913#
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl.return
if(<<uut_prototype_stubs.ioctl.__cmd>>==0X8913)
{
<<uut_prototype_stubs.ioctl.return>>=0;
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
<<uut_prototype_stubs.ioctl.return>>=-1;
}
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>=1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setInterfaceUp.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.inet_aton.return:0
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.interfaceRequest:EInterfaceRequestType_SetLinkUp
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.interfaceRequest:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.interfaceRequest:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.__cmd:16#8913#
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ioctl.return
if(<<uut_prototype_stubs.ioctl.__cmd>>==0X8913)
{
<<uut_prototype_stubs.ioctl.return>>=0;
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>==1)
{
<<uut_prototype_stubs.ioctl.return>>=-1;
}
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>=1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.005
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.interfaceRequest:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.006
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.006
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4Address.007
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.007
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.interfaceRequest:EInterfaceRequestType_SetLinkDown
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4Address.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.inet_aton.return:0
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.005
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4BroadcastAddress.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.VALUE:uut_prototype_stubs.inet_aton.return:0
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.003
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.003
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:true
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.004
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.004
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:true
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.inet_aton.return:1
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.005
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.005
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::isInterfaceValid.return:false
TEST.VALUE:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.EXPECTED:network_manager.(cl)dk::srvc::platform::CNetworkManager::setIpv4NetMask.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkManager::stop

-- Test Case: (cl)dk::srvc::platform::CNetworkManager::stop.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkManager::stop
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkManager::stop.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::set_route

-- Test Case: (cl)dk::srvc::platform::set_route.001
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::set_route
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::set_route.001
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.socket.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.END

-- Test Case: (cl)dk::srvc::platform::set_route.002
TEST.UNIT:network_manager
TEST.SUBPROGRAM:(cl)dk::srvc::platform::set_route
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::set_route.002
TEST.VALUE:network_manager.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkManager.dk::srvc::platform::CNetworkManager.<<constructor>>.CNetworkManager().<<call>>:0
TEST.VALUE:uut_prototype_stubs.socket.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.END

-- Unit: network_manager_component

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::networkManagerPeriodicTask

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::networkManagerPeriodicTask.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::networkManagerPeriodicTask
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::networkManagerPeriodicTask.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onExit

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onExit.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onExit
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onExit.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onExit.return:true
TEST.EXPECTED:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onExit.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onInit

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onInit.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onInit
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onInit.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).pMsgMap:<<null>>
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveEnetRegReq

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveEnetRegReq.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveEnetRegReq
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveEnetRegReq.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.001
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.msg.requestType:1
TEST.END

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.002
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyInterface
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyInterface.msg.requestType:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyLinkStatus

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyLinkStatus.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyLinkStatus.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.msg.requestType:1
TEST.END

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.002
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.002
TEST.STUB:network_manager.(cl)dk::srvc::platform::CNetworkManager::modifyVlanInterface
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onReceiveNetworkModifyVlanInterface.msg.requestType:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onStart

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onStart.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onStart
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onStart.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onStart.return:true
TEST.EXPECTED:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onStart.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::onStop

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::onStop.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::onStop
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::onStop.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onStop.return:true
TEST.EXPECTED:network_manager_component.(cl)dk::srvc::platform::NetworkManagerComponent::onStop.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::platform::NetworkManagerComponent::worker

-- Test Case: (cl)dk::srvc::platform::NetworkManagerComponent::worker.001
TEST.UNIT:network_manager_component
TEST.SUBPROGRAM:(cl)dk::srvc::platform::NetworkManagerComponent::worker
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::NetworkManagerComponent::worker.001
TEST.VALUE:network_manager_component.<<GLOBAL>>.(cl).dk::srvc::platform::NetworkManagerComponent.dk::srvc::platform::NetworkManagerComponent.<<constructor>>.NetworkManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Unit: network_manager_enet_register

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::disableEthernet

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::disableEthernet.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::disableEthernet
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::disableEthernet.001
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:-1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.001
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.mode:1
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.data[0]:1
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.002
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.002
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.mode:1
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.data[0]:2
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.003
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.003
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.mode:1
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.data[0]:4
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.004
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.004
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.mode:1
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.data[0]:5
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.005
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.005
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.mode:1
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthTestModes.msg.data[0]:3
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthernet

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enableEthernet.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthernet
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enableEthernet.001
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:-1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.001
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.msg.cmd:16#A#
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.EXPECTED:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.002
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.002
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.msg.cmd:16#B#
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.EXPECTED:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.003
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.003
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.msg.cmd:16#C#
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.EXPECTED:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.004
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.004
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.msg.cmd:16#D#
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.EXPECTED:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.005
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.005
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.msg.cmd:16#E#
TEST.VALUE:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.EXPECTED:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::enetReqHandler.return:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::pollPhyEnetStatusInMs

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::pollPhyEnetStatusInMs.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::pollPhyEnetStatusInMs
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::pollPhyEnetStatusInMs.001
TEST.STUB:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus
TEST.STUB:network_manager_enet_register.(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.001
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.002
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.002
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.003
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.003
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 192;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.004
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.004
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 128;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.005
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.005
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.006
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.006
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 192;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.007
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.007
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 128;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.008
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readCableQuality.008
TEST.VALUE:uut_prototype_stubs.MMD1F_read_register.return:WRITE_STATUS_OK
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.mlinkStatus:1
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1F_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1F_read_register.p_data>>[0] = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.001
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.001
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1_read_register.p_data>>[0] = 4;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.return
<<uut_prototype_stubs.MMD1_read_register.return>> = WRITE_STATUS_OK;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.002
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.002
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1_read_register.p_data>>[0] = 4;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.return
<<uut_prototype_stubs.MMD1_read_register.return>> = WRITE_STATUS_NOK;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.003
TEST.UNIT:network_manager_enet_register
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnet::readPhyLinkStatus.003
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.<<constructor>>.CNetworkPhyEnet().<<call>>:0
TEST.VALUE:network_manager_enet_register.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnet.dk::srvc::platform::CNetworkPhyEnet.bTDRProcedRunStatus:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.p_data.p_data[0]
<<uut_prototype_stubs.MMD1_read_register.p_data>>[0] = 2;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.MMD1_read_register.return
<<uut_prototype_stubs.MMD1_read_register.return>> = WRITE_STATUS_OK;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Unit: network_manager_tja1101

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler

-- Test Case: else_if_false_case
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:else_if_false_case
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Write
TEST.END

-- Test Case: else_if_false_case.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:else_if_false_case.001
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Last
TEST.END

-- Test Case: else_if_true_case
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:else_if_true_case
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_Reset
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Write
TEST.END

-- Test Case: if_case_1
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_1
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_Reset
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_2
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_2
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:2
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_3
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_3
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:3
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_4
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_4
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_WorstSqiVal
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_5
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_5
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_BestSqiVal
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_6
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_6
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_FaultStatus
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_7
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_7
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_CableStatus
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_case_8
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_case_8
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.cmd:EnetReqType_masterSlaveStatus
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Test Case: if_default
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler
TEST.NEW
TEST.NAME:if_default
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::enetReqHandler.msg.mode:EnetReqMode_Read
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:128
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:256
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:1
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.004
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getFaultStatus.004
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:4
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getLinkStatus.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getMasterSlaveStatus.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:32768
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getResetStatus.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:32768
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiBestValue

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiBestValue.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiBestValue
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiBestValue.001
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiCurrentValue

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiCurrentValue.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiCurrentValue
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiCurrentValue.001
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiWorstValue

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiWorstValue.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiWorstValue
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::getSqiWorstValue.001
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::pollPhyEnetStatusInMs

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::pollPhyEnetStatusInMs.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::pollPhyEnetStatusInMs
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::pollPhyEnetStatusInMs.001
TEST.STUB:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus
TEST.STUB:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:224
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.004
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.004
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:256
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.005
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.005
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:386
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.006
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.006
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.mLinkStatus:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.007
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readCableQuality.007
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:32640
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:1
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:0
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.003
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::readPhyLinkStatus.003
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:100
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.001
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::write_register.return:1
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.enable:true
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.return:false
TEST.EXPECTED:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.002
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.002
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::write_register.return:1
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.l_outdata[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.ENETregisterClass::read_register.return:0
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.enable:false
TEST.VALUE:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.return:false
TEST.EXPECTED:network_manager_tja1101.(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::runTDRprocedure.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::writeResetStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPhyEnetTja1101::writeResetStatus.001
TEST.UNIT:network_manager_tja1101
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::writeResetStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPhyEnetTja1101::writeResetStatus.001
TEST.VALUE:network_manager_tja1101.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPhyEnetTja1101.dk::srvc::platform::CNetworkPhyEnetTja1101.<<constructor>>.CNetworkPhyEnetTja1101().<<call>>:0
TEST.END

-- Unit: network_packet_filter_qnx

-- Subprogram: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter.001
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter.001
TEST.STUB:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter.002
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::disableFilter.002
TEST.STUB:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter.001
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter.001
TEST.STUB:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter.002
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::enableFilter.002
TEST.STUB:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::getFilterStatus

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::getFilterStatus.001
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::getFilterStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::getFilterStatus.001
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.001
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.001
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.VALUE:uut_prototype_stubs.access.return:0
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.EXPECTED:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.002
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.002
TEST.VALUE:uut_prototype_stubs.waitpid.__stat_loc[0]:0
TEST.VALUE:uut_prototype_stubs.waitpid.return:0
TEST.VALUE:uut_prototype_stubs.access.return:0
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.EXPECTED:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.003
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.003
TEST.VALUE:uut_prototype_stubs.waitpid.__stat_loc[0]:1
TEST.VALUE:uut_prototype_stubs.waitpid.return:0
TEST.VALUE:uut_prototype_stubs.access.return:0
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:true
TEST.EXPECTED:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:true
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.004
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.004
TEST.VALUE:uut_prototype_stubs.access.return:1
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.EXPECTED:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.001
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.001
TEST.STUB:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.configFile:<<malloc 12>>
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.configFile:"config_File"
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.arglist[0]:<<malloc 2>>
TEST.VALUE:network_packet_filter_qnx.(cl)dk::srvc::platform::CNetworkPacketFilterQnx::invokePfctl.arglist[0]:"1"
TEST.END

-- Test Case: (cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.002
TEST.UNIT:network_packet_filter_qnx
TEST.SUBPROGRAM:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration
TEST.NEW
TEST.NAME:(cl)dk::srvc::platform::CNetworkPacketFilterQnx::setFilterConfiguration.002
TEST.VALUE:network_packet_filter_qnx.<<GLOBAL>>.(cl).dk::srvc::platform::CNetworkPacketFilterQnx.dk::srvc::platform::CNetworkPacketFilterQnx.<<constructor>>.CNetworkPacketFilterQnx().<<call>>:0
TEST.END
