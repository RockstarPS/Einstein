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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Fri Jul 16 13:23:11 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "network_manager_component.h"
/// Start of user code : Header user code for file network_manager_component.cpp
#ifdef __linux__
#include "network_packet_filter_linux.h"
#else
#include "network_packet_filter_qnx.h"
#endif

/// End of user code


namespace dk
{
namespace srvc
{
namespace platform
{
LOG_DECLARE_CONTEXT(gNMLogContext);
bool NetworkManagerComponent::onInit()
{
    bool ret = true;

    ret = Component::onInit();

/// Start of user code : User code for function onInit in file network_manager_component.cpp
    LOG_REGISTER_CONTEXT(gNMLogContext, "NM", "Network Manager Component", DLT_LOG_INFO);
    LOGV(&gNMLogContext, "Network Manager Component onInit Invoked");
    ///< Invoking  CNetworkManager Initialization method.
    mNetworkManagerInst.init();
    ///< Register network manager periodic task
    (void)registerTask([=]() {
        networkManagerPeriodicTask();
    }, mPeriodicTaskTimeInMs);

/// End of user code

    return ret;
}

bool NetworkManagerComponent::onExit()
{
    bool ret = true;

    ret = Component::onExit();

/// Start of user code : User code for function onExit in file network_manager_component.cpp
    LOGV(&gNMLogContext, "Network Manager Component onExit Invoked");
    LOG_UNREGISTER_CONTEXT(gNMLogContext);
/// End of user code

    return ret;
}

bool NetworkManagerComponent::onStart()
{
    bool ret = true;

    ret = Component::onStart();
/// Start of user code : User code for function onStart in file network_manager_component.cpp
    LOGV(&gNMLogContext, "Network Manager Component onStart Invoked");
/// End of user code

    return ret;
}

bool NetworkManagerComponent::onStop()
{
    bool ret = true;
    ret = Component::onStop();
    mNetworkManagerInst.stop();

/// Start of user code : User code for function onStop in file network_manager_component.cpp
    LOGV(&gNMLogContext, "Network Manager Component onStop Invoked");
/// End of user code

    return ret;
}

void NetworkManagerComponent::worker()
{
/// Start of user code : User code for function worker in file network_manager_component.cpp

/// End of user code
}


void NetworkManagerComponent::onReceiveNetworkModifyLinkStatus(NetworkModifyLinkStatus const  & msg)
{
/// Start of user code : User code for function onReceiveNetworkModifyLinkStatus in file network_manager_component.cpp
    std::string interfaceName;

    (void)interfaceName.assign(&msg.interfaceName[0],&msg.interfaceName[0]+msg.interfaceNameLength);
    

    LOGI(&gNMLogContext, "Network Modify Link Status - Interface name ", interfaceName, "Request type ", msg.interfaceRequestType);
    mNetworkManagerInst.modifyLinkStatus(interfaceName, static_cast<CNetworkManager::EInterfaceRequestType_t>(msg.interfaceRequestType));
/// End of user code
}


void NetworkManagerComponent::onReceiveEnetRegReq(EnetRegReq const  & msg)
{
    LOGI(&gNMLogContext, "Received onReceiveEnetRegReq");
#ifdef ENET_PHY_TJA1101
    mNetworkManagerInst.mpNetworkPhyEnetTja1101->enetReqHandler(msg);
#endif

#ifdef ENET_PHY_TC812
    mNetworkManagerInst.mpNetworkPhyEnet->enetReqHandler(msg);
#endif
}

void NetworkManagerComponent::onReceiveNetworkModifyVlanInterface(NetworkModifyVlanInterface const  & msg)
{
    /// Start of user code : User code for function onReceiveNetworkModifyVlanInterface in file network_manager_component.cpp
    /// Start of user code : User code for function onReceiveNetworkModifyVlanInterface in file network_manager_component.cpp
    std::string vlanName;
    std::string interfaceName;
    EVlanRequestType_t requestType = EVlanRequestType_Create;

    LOGI(&gNMLogContext, "RequestType ", msg.requestType);
    LOGI(&gNMLogContext, "VLAN name length: ", msg.vlanNameLength, "Interface Length: ", msg.interfaceNameLength);

    ///< copy interface and vlan name from the received message.
    (void)interfaceName.assign(&msg.interfaceName[0],&msg.interfaceName[0]+msg.interfaceNameLength);
    (void)vlanName.assign(&msg.vlanName[0],&msg.vlanName[0]+msg.vlanNameLength);
    ///< Get the Vlan request type from the message , if the request type is not EVlanRequestType_Create set the type
    ///< to EVlanRequestType_Destroy.
    if(static_cast<EVlanRequestType_t>(msg.requestType) != \
            EVlanRequestType_Create)
    {
        requestType = EVlanRequestType_Destroy;
        LOGI(&gNMLogContext, "RequestType is not create. Changed type ", msg.requestType);
    }

    LOGI(&gNMLogContext, "Network Manager modify Vlan interface vlanName = ",vlanName," ifName = ",interfaceName,
         "vlanTag ",msg.vlanTag," vlanPriority = ",msg.vlanPriority);

    mNetworkManagerInst.modifyVlanInterface(requestType,vlanName,msg.vlanTag,interfaceName,msg.vlanPriority);
    /// End of user code
/// End of user code
}

void NetworkManagerComponent::onReceiveNetworkModifyInterface(NetworkModifyInterface const  & msg)
{
/// Start of user code : User code for function onReceiveNetworkModifyInterface in file network_manager_component.cpp
    /// Start of user code : User code for function onReceiveNetworkModifyInterface in file network_manager_component.cpp
    std::string ifName;
    std::string ipAddr;
    std::string netMask;
    std::string broadcastAddr;
    CNetworkManager::EInterfaceRequestType_t requestType;
    CNetworkManager::EIpInterfaceRequestType_t ipRequest;
    ///< copy the interface name , IP address ,netmask and  broadcast address from the requested message.
    (void)ifName.assign(&msg.interfaceName[0],&msg.interfaceName[0]+msg.interfaceNameLength);
    (void)ipAddr.assign(&msg.ipAddress[0],&msg.ipAddress[0]+msg.ipAddressLength);
    (void)netMask.assign(&msg.netMask[0],&msg.netMask[0]+msg.netMaskLength);
    (void)broadcastAddr.assign(&msg.broadcastAddress[0],&msg.broadcastAddress[0]+msg.broadcastAddressLength);
    ///< Get the requested link status from the message . If the link status is not EInterfaceRequestType_SetLinkUp,
    ///< set the status to EInterfaceRequestType_SetLinkDown.
    requestType = static_cast<CNetworkManager::EInterfaceRequestType_t>(msg.requestType);
    if(requestType != CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkUp)
    {
        requestType = CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkDown;
    }

    ///< Get the requested operation type . If the operation type is not EIpRequestType_Set , then set the
    ///< request to EIpRequestType_Clear.
    ipRequest = static_cast<CNetworkManager::EIpInterfaceRequestType_t>(msg.requestType);
    if(ipRequest != CNetworkManager::EIpInterfaceRequestType_t::EIpRequestType_Set)
    {
        ipRequest = CNetworkManager::EIpInterfaceRequestType_t::EIpRequestType_Clear;
    }

    LOGI(&gNMLogContext, "Network Manager modify interface ipRequest = ",ipRequest," ifName = ",ifName," len ",
         static_cast<uint32_t>(ifName.length()),
         "ipAddr ",ipAddr," netMask = ",netMask," broadcastAddr = ",broadcastAddr," requestType = ",requestType);

    mNetworkManagerInst.modifyInterface(ipRequest,ifName,ipAddr,netMask,broadcastAddr,requestType);
    /// End of user code
}


#ifdef ENET_PHY_TC812
void NetworkManagerComponent::onReceiveNetworkRequestLinkState(NetworkRequestLinkState const  & msg)
{
/// Start of user code : User code for function onReceiveNetworkRequestLinkState in file network_manager_component.cpp
    EthlinkDownStatus lEthLinkDownStatus = {0U};

    if(mNetworkManagerInst.mpNetworkPhyEnet)
    {

       lEthLinkDownStatus.ethernetLinkStatus = mNetworkManagerInst.mpNetworkPhyEnet->mlinkStatus;
       DK_RTE_Send_EthlinkDownStatus(lEthLinkDownStatus);
    }
/// End of user code

}
#endif

void NetworkManagerComponent::onReceiveNetworkModifyFirewallStatus(NetworkModifyFirewallStatus const  & msg)
{
/// Start of user code : User code for function onReceiveNetworkModifyFirewallStatus in file network_manager_component.cpp
    CNetworkManager::EFirewallRequestType_t firewallRequestType;

    if(msg.networkFirewallStatus == true)
    {
        firewallRequestType = CNetworkManager::EFirewallRequestType_t::EFirewallRequest_Enable;
    }
    else
    {
        firewallRequestType = CNetworkManager::EFirewallRequestType_t::EFirewallRequest_Disable;
    }
    mNetworkManagerInst.modifyFirewall(firewallRequestType);

/// End of user code
}

/// Start of user code : Footer user code for file network_manager_component.cpp
void NetworkManagerComponent::networkManagerPeriodicTask(void)
{
    ///< Invoke network Manager CNetworkManager periodic task.
    mNetworkManagerInst.periodicTaskInMs();

}




}
}
}
