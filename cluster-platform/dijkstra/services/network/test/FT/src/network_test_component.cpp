//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.4
// Date: Tue Oct 05 14:20:19 IST 2021
// User: SSHANKA8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "network_test_component.h"

/// Start of user code : Header user code for file networkif_app_component.cpp

/// End of user code



bool NetworkifAppComponent::onInit()
{
	bool ret = Component::onInit();

/// Start of user code : User code for function onInit in file networkif_app_component.cpp
    (void)parseConfiguration();
/// End of user code

	return ret;
}

bool NetworkifAppComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file networkif_app_component.cpp

/// End of user code

	return ret;
}

bool NetworkifAppComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file networkif_app_component.cpp

/// End of user code

	return ret;
}

bool NetworkifAppComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file networkif_app_component.cpp

/// End of user code

	return ret;
}
void NetworkifAppComponent::worker()
{
	static bool msg_sent = false;
/// Start of user code : User code for function worker in file networkif_app_component.cpp

    if(((gApp.test_case == 1) || (gApp.test_case == 6)) && (msg_sent == false))
	{
        send_network_modify_interface_phy(0); /*Set - Link UP*/
		msg_sent = true;
	}
	else if(((gApp.test_case == 2) || (gApp.test_case == 7)) && (msg_sent == false))
	{
        send_network_modify_interface_phy(1); /*Set - Link Down*/
		msg_sent = true;
	}
	else if((gApp.test_case == 3) && (msg_sent == false))
	{
        send_network_modify_interface_phy(2); /*Clear */
		msg_sent = true;
	}
	else if(((gApp.test_case == 4) ||(gApp.test_case == 8) ||(gApp.test_case == 9)) && (msg_sent == false))
	{
        send_network_modify_vlan_interface(0); /*VLAN Create*/
		msg_sent = true;
	}
	else if((gApp.test_case == 5) && (msg_sent == false))
	{
        send_network_modify_vlan_interface(1); /*VLAN Destroy*/
		msg_sent = true;
	}
	else if((gApp.test_case == 6) && (resp_recved == true) )
	{
        send_network_modify_link_status(1, interfaceName); /*FEC0 Down*/
		resp_recved = false;
		gApp.test_case = 0;
	}
	else if((gApp.test_case == 7) && (resp_recved == true) )
	{
        send_network_modify_link_status(0, interfaceName); /*FEC0 UP*/
		resp_recved = false;
		gApp.test_case = 0;
	}
    else if((gApp.test_case == 8) && (resp_recved == true) )
	{
        send_network_modify_link_status(1, vlanName); /*VLAN Down*/
		resp_recved = false;
		gApp.test_case = 0;
	}
	else if((gApp.test_case == 9) && (resp_recved == true) )
	{
        send_network_modify_interface_vlan(0); /*VLAN Up*/
		resp_recved = false;
		gApp.test_case = 0;
	}
	else
	{

	}

    
/// End of user code
}

bool NetworkifAppComponent::parseConfiguration(void)
{
	bool ret = false;
	bool parserStatus = false;
	
	/// Get the configuration values.
    if(mParserObj.loadConfiguration(mIniFilePath1))
    {
        parserStatus = true;
        LOGI(&gRTELogContext, "CNetworkManager ini file found in  ", mIniFilePath1);
    }
    else if (mParserObj.loadConfiguration(mIniFilePath2))
    {
        parserStatus = true;
        LOGI(&gRTELogContext, "CNetworkManager ini file found in  ",mIniFilePath2);
    }
    else
    {
        LOGI(&gRTELogContext, "CNetworkManager ini file not found in  ",mIniFilePath1); 
        LOGI(&gRTELogContext, "CNetworkManager ini file not found in  ",mIniFilePath2);
    }
    
    if(parserStatus == true)
    {
		/* Physical interface configuration */
		interfaceName = mParserObj.getStringValue("phy0", "Name");
		ipAddress = mParserObj.getStringValue("phy0", "Ip");
		netMask = mParserObj.getStringValue("phy0", "NetMask");
		broadCastAddress = mParserObj.getStringValue("phy0", "BroadCast");
		linkStatus = mParserObj.getStringValue("phy0", "LinkStatus");
		
		LOGI(&gRTELogContext, "Physical Interface name ", interfaceName);
		LOGI(&gRTELogContext, "Physical Interface IP address ", ipAddress);
		LOGI(&gRTELogContext, "Physical Interface Net Mask ", netMask);
		LOGI(&gRTELogContext, "Physical Interface Broadcast address ", broadCastAddress);
		LOGI(&gRTELogContext, "Physical Interface Link Status ", linkStatus);
		
		vlanName = mParserObj.getStringValue("virtual0", "Name");
		vlanTag = mParserObj.getInt32Value("virtual0", "VlanId",0);
		vlanPriority = mParserObj.getInt32Value("virtual0", "Priority",0);
		phyInterfaceName = mParserObj.getStringValue("virtual0", "PhyInterface");
		vlanIpAddress = mParserObj.getStringValue("virtual0", "Ip");
		vlanNetMask = mParserObj.getStringValue("virtual0", "NetMask");
		vlanBroadCastAddress = mParserObj.getStringValue("virtual0", "BroadCast");
		vlanLinkStatus = mParserObj.getStringValue("virtual0", "LinkStatus");
		
		LOGI(&gRTELogContext, "Virtual Interface name ", vlanName);
		LOGI(&gRTELogContext, "Virtual Interface Tag ", vlanTag);
		LOGI(&gRTELogContext, "Virtual Interface Priority ", vlanPriority);
		LOGI(&gRTELogContext, "Virtual Interface PHY name ", phyInterfaceName);
		LOGI(&gRTELogContext, "Virtual Interface IP address ", vlanIpAddress);
		LOGI(&gRTELogContext, "Virtual Interface Net Mask ", vlanNetMask);
		LOGI(&gRTELogContext, "Virtual Interface Broadcast address ", vlanBroadCastAddress);
		LOGI(&gRTELogContext, "Virtual Interface Link Status ", vlanLinkStatus);
		ret = true;
	}
	
	return ret; 
}


void NetworkifAppComponent::send_network_modify_interface_phy(uint8_t req_type)
{
    NetworkModifyInterface interface_obj;

	interface_obj.interfaceNameLength = interfaceName.length();

	std::strcpy((char *)interface_obj.interfaceName, interfaceName.c_str());
    
    if(req_type == 1)
	{
		interface_obj.linkStatus = ELinkStatus_Down;
		LOGI(&gRTELogContext, "reqType: ", req_type);
	}
	else
	{
	    interface_obj.linkStatus = ELinkStatus_Up;
		LOGI(&gRTELogContext, "reqType: ", req_type);
	}

	interface_obj.ipAddressLength = ipAddress.length();

	std::strcpy((char *)interface_obj.ipAddress, ipAddress.c_str());

	interface_obj.netMaskLength = netMask.length();

	std::strcpy((char *)interface_obj.netMask, netMask.c_str());

	interface_obj.broadcastAddressLength = broadCastAddress.length();

	std::strcpy((char *)interface_obj.broadcastAddress, broadCastAddress.c_str());

    if(req_type == 2)
	{
	    interface_obj.requestType = EModifyInterfaceReqType_Clear;
	}
	else
	{
	    interface_obj.requestType = EModifyInterfaceReqType_Set;
	}

    /*Send request*/
	gApp.sendNetworkModifyInterface(interface_obj);

	LOGI(&gRTELogContext, "Network modify interface is sent");
}


void NetworkifAppComponent::send_network_modify_interface_vlan(uint8_t req_type)
{
    NetworkModifyInterface interface_obj;

	interface_obj.interfaceNameLength = vlanName.length();

	std::strcpy((char *)interface_obj.interfaceName, vlanName.c_str());
    
    if(req_type == 1)
	{
		interface_obj.linkStatus = ELinkStatus_Down;
		LOGI(&gRTELogContext, "reqType: ", req_type);
	}
	else
	{
	    interface_obj.linkStatus = ELinkStatus_Up;
		LOGI(&gRTELogContext, "reqType: ", req_type);
	}

	interface_obj.ipAddressLength = vlanIpAddress.length();

	std::strcpy((char *)interface_obj.ipAddress, vlanIpAddress.c_str());

	interface_obj.netMaskLength = vlanNetMask.length();

	std::strcpy((char *)interface_obj.netMask, vlanNetMask.c_str());

	interface_obj.broadcastAddressLength = vlanBroadCastAddress.length();

	std::strcpy((char *)interface_obj.broadcastAddress, vlanBroadCastAddress.c_str());

    if(req_type == 2)
	{
	    interface_obj.requestType = EModifyInterfaceReqType_Clear;
	}
	else
	{
	    interface_obj.requestType = EModifyInterfaceReqType_Set;
	}

    /*Send request*/
	gApp.sendNetworkModifyInterface(interface_obj);

	LOGI(&gRTELogContext, "Network modify interface is sent");
}


/// Start of user code : Footer user code for file networkif_app_component.cpp
void NetworkifAppComponent::send_network_modify_vlan_interface(uint8_t req_type)
{
    NetworkModifyVlanInterface vlaninterface_obj;

	vlaninterface_obj.vlanNameLength = vlanName.length();

	std::strcpy((char*)vlaninterface_obj.vlanName, vlanName.c_str());

	vlaninterface_obj.vlanTag = vlanTag;

	vlaninterface_obj.interfaceNameLength = phyInterfaceName.length();

	std::strcpy((char*)vlaninterface_obj.interfaceName, phyInterfaceName.c_str());

    vlaninterface_obj.vlanPriority = vlanPriority;

	if(req_type == 0)
	{
	    vlaninterface_obj.requestType = EVlanRequestType_Create;
	}
	else
	{
	    vlaninterface_obj.requestType = EVlanRequestType_Destroy;
	}

	gApp.sendNetworkModifyVlanInterface(vlaninterface_obj);

	LOGI(&gRTELogContext, "Network modify vlan interface is sent");
}

void NetworkifAppComponent::send_network_modify_link_status(uint8_t req_type, std::string interfaceName)
{
    NetworkModifyLinkStatus linkstatus_obj;
  
    linkstatus_obj.interfaceNameLength = interfaceName.length();

    std::strcpy((char *)linkstatus_obj.interfaceName, interfaceName.c_str());

	if(req_type == 0)
	{
		linkstatus_obj.interfaceRequestType = ELinkStatus_Up;
	}
	else
	{
	    linkstatus_obj.interfaceRequestType = ELinkStatus_Down;
	}
    
	gApp.sendNetworkModifyLinkStatus(linkstatus_obj);

	LOGI(&gRTELogContext, "Network status modify request is sent");
}

void NetworkifAppComponent::onReceiveNetworkInterfaceStatus(NetworkInterfaceStatus & msg)
{
	std::string interfaceName;

    std::string ipAddress;

    (void)interfaceName.assign(&msg.interfaceName[0],&msg.interfaceName[0]+msg.interfaceNameLength);

    (void)ipAddress.assign(&msg.ipAddress[0],&msg.ipAddress[0]+msg.ipAddressLength);

    LOGI(&gRTELogContext, "Received a response");

    LOGI(&gRTELogContext, "interfaceNameLength: ", msg.interfaceNameLength);

    LOGI(&gRTELogContext, "interfaceName: ", interfaceName);

    LOGI(&gRTELogContext, "linkStatus: ", msg.linkStatus);

    LOGI(&gRTELogContext, "ipAddressLength: ", msg.ipAddressLength);

    LOGI(&gRTELogContext, "ipAddress: ", ipAddress); 

	resp_recved = true;
}
/// End of user code

