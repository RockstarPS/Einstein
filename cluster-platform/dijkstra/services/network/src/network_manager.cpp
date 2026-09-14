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

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <net/route.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cstdio>
#ifdef __linux__
#include <linux/if_vlan.h>
#include <linux/sockios.h>
#include "network_packet_filter_linux.h"
#else
#include <sys/iofunc.h>
#include <net/if_vlanvar.h>
#include <net/if_media.h>
#include "network_packet_filter_qnx.h"
#include "network_manager_tja1101.h"
#endif
#include "dk_runtime_parserif.h"
#include "dk_runtime_network_manager_component.h"
#include "network_manager.h"
#include "network_manager_component.h"

namespace dk
{
namespace srvc
{
namespace platform
{

LOG_IMPORT_CONTEXT(gNMLogContext);

static int set_route(const std::string ipAddr);

void CNetworkManager::init(void)
{
    iniHandler();
    configureInterfaces();

#ifdef ENET_PHY_TJA1101
    mpNetworkPhyEnetTja1101.reset (new CNetworkPhyEnetTja1101 ( ));
#endif

#ifdef ENET_PHY_TC812
    mpNetworkPhyEnet.reset ( new CNetworkPhyEnet (  ) );
#endif
}

void CNetworkManager::stop(void)
{
#ifdef ENET_PHY_TJA1101
    mpNetworkPhyEnetTja1101.reset();
#endif

#ifdef ENET_PHY_TC812
    mpNetworkPhyEnet.reset ();
#endif
}

void CNetworkManager::iniHandler(void)
{
    uint8_t noOfPhyInterfaces;
    uint8_t noOfVirtualInterfaces;
    bool parserStatus = false;
    const std::string defaultAddress = "0.0.0.0";
    const std::string defaultnetMask = "255.255.255.255";
    const uint8_t defaultVlanPriority = 7U;
    const uint16_t defaultVlanTagValue = 1U;

    /// Clear all interfaces
    noOfPhyInterfaces = 0U;
    noOfVirtualInterfaces = 0U;

    /// Get the configuration values.
    if(mParserObj.loadConfiguration(mIniFilePath1))
    {
        parserStatus = true;
        LOGD(&gNMLogContext, "CNetworkManager ini file found in  ", mIniFilePath1);
    }
    else if (mParserObj.loadConfiguration(mIniFilePath2))
    {
        parserStatus = true;
        LOGD(&gNMLogContext, "CNetworkManager ini file found in  ",mIniFilePath2);
    }
    else
    {
        LOGD(&gNMLogContext, "CNetworkManager ini file not found in  ",mIniFilePath1); 
        LOGD(&gNMLogContext, "CNetworkManager ini file not found in  ",mIniFilePath2);
    }
    
    if(parserStatus == true)
    {
        std::vector<std::string> sectionsList;
        std::vector<std::string> stringValues;

#ifdef __linux__
        const std::string ifNameR="eth0";
#else
        const std::string ifNameR="fec0";
#endif
        currentInterfaceConfig[ifNameR].mIpAddress="192.168.0.10";
        currentInterfaceConfig[ifNameR].mLinkStatus=ELinkStatus_Up;

        if (mParserObj.getAllSections(sectionsList))
        {
            noOfPhyInterfaces = static_cast<uint8_t>(mParserObj.getInt32Value("network", "NumPhyInterface", static_cast<int32_t>(mPhysicalInterface.size())));
            noOfVirtualInterfaces = static_cast<uint8_t>(mParserObj.getInt32Value("network", "NumVirtualInterface", 0));
            mFireWallConfigEnable = mParserObj.getBoolValue("Firewall","EnableFirewall",false);
            mNICType = mParserObj.getStringValue("NIC", "NICType");
            mNoARP = mParserObj.getBoolValue("ARP", "NoARP", false);

            LOGI(&gNMLogContext, "Firewall configuration status: ",mFireWallConfigEnable);
            LOGI(&gNMLogContext, "NoARP configuration status: ", mNoARP);
            LOGI(&gNMLogContext, "NICType ",mNICType);

            #ifdef __linux__
                mNetworkPacketFilterInst.reset(new CNetworkPacketFilterLinux());
            #else
                mNetworkPacketFilterInst.reset(new CNetworkPacketFilterQnx());
            #endif

            if (mNetworkPacketFilterInst != nullptr)
            {
                stringValues.clear();
                /// Get firewall config file path
                if (mParserObj.getAllValuesForKey("Firewall","FirewallConfig",stringValues) != false)
                {
                    /// If valid file path exist update the file path
                    mNetworkPacketFilterInst->setFilterConfiguration(stringValues[0]);
                    LOGI(&gNMLogContext, "filter config file path ",stringValues[0]);
                }

                if (mFireWallConfigEnable == true)
                {  
                    mNetworkPacketFilterInst->enableFilter();
                    LOGI(&gNMLogContext, "Firewall enabled config true");
                }
                else
                {
                    LOGI(&gNMLogContext, "Firewall not enabled in the ini file");
                }
            }
            else
            {
                LOGI(&gNMLogContext, "Firewall Instance not created");
            }

            /// Update physical Interfaces.
            for (auto index = 0U; index < noOfPhyInterfaces ; index ++)
            {
                std::stringstream ss;
                ss.str(std::string());
                ss<<index;
                /// Search for physical interface section . physical interface section should be as phy0,phy1..
                const std::string phyInterfaceIndex = "phy"+ss.str();
                const std::vector<std::string>::iterator searchIndex = \
                        std::find(sectionsList.begin(),sectionsList.end(),phyInterfaceIndex);
                if (searchIndex != sectionsList.end())
                {
                    std::string ifName;
                    stringValues.clear();
                    /// Get string values for the interface name
                    if (mParserObj.getAllValuesForKey(phyInterfaceIndex,"Name",stringValues))
                    {
                        ifName =  stringValues[0];
                        LOGI(&gNMLogContext, " interfaceName  ",ifName);
                        /// valid name check
                        if (ifName.size() > 0U)
                        {
                            /// check if the interface already exists in the configuration ,then discard the current
                            /// configuration
                            if (mPhysicalInterface.find(ifName) == mPhysicalInterface.end())
                            {
                                mPhysicalInterface[ifName].mInterfaceName =  ifName;
                                stringValues.clear();
                                /// Get Ip address
                                LOGI(&gNMLogContext, " InterfaceName ",mPhysicalInterface[ifName].mInterfaceName);
                                if (mParserObj.getAllValuesForKey(phyInterfaceIndex,"Ip",stringValues))
                                {
                                    mPhysicalInterface[ifName].mIpAddress =  stringValues[0];
                                }
                                else
                                {
                                    mPhysicalInterface[ifName].mIpAddress =  defaultAddress;
                                }
                                LOGI(&gNMLogContext, " IpAddress value  ",mPhysicalInterface[ifName].mIpAddress);
                                /// Get netmask
                                stringValues.clear();
                                if (mParserObj.getAllValuesForKey(phyInterfaceIndex,"NetMask",stringValues))
                                {
                                    mPhysicalInterface[ifName].mNetmask = stringValues[0];
                                }
                                else
                                {
                                    mPhysicalInterface[ifName].mNetmask =  defaultnetMask;
                                }
                                LOGI(&gNMLogContext, " Netmask value  ",mPhysicalInterface[ifName].mNetmask);
                                stringValues.clear();
                                /// Get BroadCast address
                                if (mParserObj.getAllValuesForKey(phyInterfaceIndex,"BroadCast",stringValues))
                                {
                                    mPhysicalInterface[ifName].mbroadcastAddress = stringValues[0];
                                }
                                else
                                {
                                    mPhysicalInterface[ifName].mbroadcastAddress = defaultAddress;
                                }
                                LOGI(&gNMLogContext,"broadcast Address ",mPhysicalInterface[ifName].mbroadcastAddress);
                                stringValues.clear();

                                /// Get Link status
                                if (mParserObj.getAllValuesForKey(phyInterfaceIndex,"LinkStatus",stringValues))
                                {
                                    if (stringValues[0] == "Up")  /// TODO: convert to caps before check
                                    {
                                        mPhysicalInterface[ifName].mRequetsedLinkStatus = ELinkStatus_Up;
                                        LOGI(&gNMLogContext, " mRequetsedLinkStatus  ELinkStatus_Up");
                                    }
                                    else
                                    {
                                        mPhysicalInterface[ifName].mRequetsedLinkStatus = ELinkStatus_Down;
                                        LOGI(&gNMLogContext, " mRequetsedLinkStatus  ELinkStatus_Down");
                                    }
                                }
                            }
                            else
                            {
                                LOGD(&gNMLogContext, " interfaceName configuration already present ",ifName);
                            }
                        }
                    }
                    else
                    {
                        LOGD(&gNMLogContext, " interfaceName not found for physical interface ",phyInterfaceIndex);
                    }
                }
            }

            ///< get Vlan interface configurations
            for (auto index = 0U; index < noOfVirtualInterfaces ; index ++)
            {
                std::stringstream ss;
                ss.str(std::string());
                ss<<index;
                const std::string virtualInterface = "virtual"+ss.str();
                const std::vector<std::string>::iterator searchIndex = \
                        std::find(sectionsList.begin(),sectionsList.end(),virtualInterface);
                if (searchIndex != sectionsList.end())
                {
                    std::string ifName;
                    stringValues.clear();
                    ///< get Vlan interface name
                    if (mParserObj.getAllValuesForKey(virtualInterface,"Name",stringValues))
                    {
                        ifName =  stringValues[0];
                        LOGI(&gNMLogContext, " interfaceName  ",ifName);
                        if (ifName.size() > 0U)
                        {
                            mVirtualInterface[ifName].mVlanName = ifName;
                            ///< get Vlan interface tag , vlan priority
                            mVirtualInterface[ifName].mVlanTag = \
                                static_cast<uint16_t>(mParserObj.getInt32Value(virtualInterface, "VlanId", static_cast<int32_t>(defaultVlanPriority)));
                            mVirtualInterface[ifName].mVlanPriority = \
                                static_cast<uint8_t>(mParserObj.getInt32Value(virtualInterface, "Priority", static_cast<int32_t>(defaultVlanTagValue)));
                            LOGI(&gNMLogContext, " Vlan interface name ",mVirtualInterface[ifName].mVlanName);
                            LOGI(&gNMLogContext, " VlanTag value ",mVirtualInterface[ifName].mVlanTag);
                            LOGI(&gNMLogContext, " VlanPriority value ",mVirtualInterface[ifName].mVlanPriority);
                            ///< get Vlan physical interface
                            stringValues.clear();
                            if (mParserObj.getAllValuesForKey(virtualInterface,"PhyInterface",stringValues))
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mInterfaceName =  stringValues[0];
                            }
                            else
                            {
                                LOGE(&gNMLogContext, " PhyInterface value not found ");
                            }
                            LOGI(&gNMLogContext, " PhyInterface value ",
                                 mVirtualInterface[ifName].mPhysicalInterfaceInfo.mInterfaceName);
                            ///< get Vlan Ip address
                            stringValues.clear();
                            if (mParserObj.getAllValuesForKey(virtualInterface,"Ip",stringValues))
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mIpAddress =  stringValues[0];
                            }
                            else
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mIpAddress =  defaultAddress;
                            }
                            LOGI(&gNMLogContext, " IpAddress value ",
                                 mVirtualInterface[ifName].mPhysicalInterfaceInfo.mIpAddress);
                            ///< get Vlan IP Netmask
                            stringValues.clear();
                            if (mParserObj.getAllValuesForKey(virtualInterface,"NetMask",stringValues))
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mNetmask = stringValues[0];
                            }
                            else
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mNetmask =  defaultnetMask;
                            }
                            LOGI(&gNMLogContext, " Netmask value ",
                                 mVirtualInterface[ifName].mPhysicalInterfaceInfo.mNetmask);
                            ///< get Vlan IP BroadCast
                            stringValues.clear();
                            if (mParserObj.getAllValuesForKey(virtualInterface,"BroadCast",stringValues))
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mbroadcastAddress = stringValues[0];
                            }
                            else
                            {
                                mVirtualInterface[ifName].mPhysicalInterfaceInfo.mbroadcastAddress =  defaultAddress;
                            }
                            LOGI(&gNMLogContext, " broadcastAddress value ",
                                 mVirtualInterface[ifName].mPhysicalInterfaceInfo.mbroadcastAddress);
                            ///< get Vlan LinkStatus
                            stringValues.clear();
                            if (mParserObj.getAllValuesForKey(virtualInterface,"LinkStatus",stringValues))
                            {
                                if (stringValues[0] == "Up")  /// TODO: convert to caps before check
                                {
                                    mVirtualInterface[ifName].mPhysicalInterfaceInfo.mRequetsedLinkStatus = \
                                            ELinkStatus_Up;
                                    LOGI(&gNMLogContext, " mRequetsedLinkStatus  ELinkStatus_Up");
                                }
                                else
                                {
                                    mVirtualInterface[ifName].mPhysicalInterfaceInfo.mRequetsedLinkStatus = \
                                            ELinkStatus_Down;
                                    LOGI(&gNMLogContext, " mRequetsedLinkStatus  ELinkStatus_Down");
                                }
                            }
                        }
                    }
                    else
                    {
                        LOGD(&gNMLogContext, " interfaceName not found for physical interface ",virtualInterface);
                    }
                }
            }
        }
    }

}

void CNetworkManager::periodicTaskInMs(void)
{
    monitorInterfaces();

#ifdef ENET_PHY_TC812
    if(mpNetworkPhyEnet)
    {
        mpNetworkPhyEnet->pollPhyEnetStatusInMs();
    }
#endif

#ifdef ENET_PHY_TJA1101
    if(mpNetworkPhyEnetTja1101)
    {
        mpNetworkPhyEnetTja1101->pollPhyEnetStatusInMs();
    }
#endif
}

void CNetworkManager::modifyLinkStatus(const std::string interfaceName, const CNetworkManager::EInterfaceRequestType_t linkType)
{

    if (linkType == CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkUp)
    {
        if(setInterfaceUp(interfaceName) != false)
        {
            LOGI(&gNMLogContext, " interfaceName link Up setting success for ",interfaceName);
        }
        else
        {
            LOGE(&gNMLogContext, " interfaceName link Up setting failure for ",interfaceName);
        }
    }
    else
    {
        if (setInterfaceDown(interfaceName) != false)
        {
            LOGI(&gNMLogContext, " interfaceName link Down setting success for ",interfaceName);
        }
        else
        {
            LOGE(&gNMLogContext, " interfaceName link Down setting failure for ",interfaceName);
        }
    }
}


void CNetworkManager::modifyInterface
(
    const CNetworkManager::EIpInterfaceRequestType_t requestType,
    const std::string interfaceName,
    const std::string ipAddress,
    const std::string netMask,
    const std::string broadcastAddress,
    const CNetworkManager::EInterfaceRequestType_t interfaceRequestType
)
{
    bool status;
    if (requestType == CNetworkManager::EIpInterfaceRequestType_t::EIpRequestType_Set)
    {
        /// set requested IPV4 address.
        LOGI(&gNMLogContext,"modifyInterface interfaceName ",interfaceName," len ",interfaceName.length());

        status = setIpv4Address(interfaceName,ipAddress,interfaceRequestType);
        if (status != false)
        {
            /// set requested netmask
            LOGI(&gNMLogContext, " IPV4 address setting successful interfaceName ",interfaceName,
                 "ipAddress ",ipAddress);
            status = setIpv4NetMask(interfaceName,netMask);
        }

        if (status != false)
        {
            /// set requested broadcast .
            LOGI(&gNMLogContext, " IPV4 netmask setting successful interfaceName ",interfaceName,
                 "netMask ",netMask);
            status = setIpv4BroadcastAddress(interfaceName,broadcastAddress);
        }

        if((status != false) && (mNoARP == true))
        {
            /// set noArp.
            status = disableARP(interfaceName);
        }

        if( status != false)
        {
            LOGI(&gNMLogContext, " IPV4 broadcastAddress setting successful interfaceName ",interfaceName,
                 "broadcastAddress ",broadcastAddress);
            LOGI(&gNMLogContext, " IP address configuration successful for interfaceName",interfaceName);
            if (interfaceRequestType == EInterfaceRequestType_SetLinkUp)
            {
                notifyInterfaceChanges(interfaceName,ipAddress,ELinkStatus_Up);
            }
            else
            {
                notifyInterfaceChanges(interfaceName,ipAddress,ELinkStatus_Down);
            }
        }
        else
        {
            LOGE(&gNMLogContext, "IP address configuration failed for interfaceName ",interfaceName);
        }

    }
    else
    {
        (void)removeIpv4Address(interfaceName);
    }

}

void CNetworkManager::modifyVlanInterface
(
    const EVlanRequestType_t requestType,
    const std::string vlanName,
    const uint16_t vlanTag,
    const std::string ifName,
    const uint8_t vlanPriority
)
{
    const std::string ipAddr = "0.0.0.0";
    LOGI(&gNMLogContext,"\nagain checking request type : ", requestType);
    if (requestType == EVlanRequestType_Create)
    {
        /// create vlan interface
        if( createVlan(vlanName,vlanTag,ifName,vlanPriority) != false)
        {
            notifyInterfaceChanges(vlanName,ipAddr,ELinkStatus_Down);
            LOGI(&gNMLogContext, "vlanName Interface successfully created .vlanName ",vlanName);
        }
        else
        {
            LOGE(&gNMLogContext, "vlanName Interface creation failed .vlanName ",vlanName);
        }
    }
    else
    {
        /// destroy vlan interface
        if (destroyVlan(vlanName) != false)
        {
            LOGI(&gNMLogContext, "vlanName Interface successfully removed .vlanName ",vlanName);
        }
        else
        {
            LOGE(&gNMLogContext, "vlanName Interface remove failure .vlanName ",vlanName);
        }
    }
}

void CNetworkManager::modifyFirewall(const EFirewallRequestType_t requestType)
{
    if (mNetworkPacketFilterInst != nullptr)
    {
        if (requestType == EFirewallRequestType_t::EFirewallRequest_Enable)
        {
            /// Enable the packet filter
            mNetworkPacketFilterInst->enableFilter();
        }
        else
        {
            /// Disable the packet filter
            mNetworkPacketFilterInst->disableFilter();
        }
    }
    else
    {
        LOGD(&gNMLogContext, "mNetworkPacketFilterInst not created. ");
    }
}

// Private Interface Implementation
void CNetworkManager::configureInterfaces(void)
{
    std::string ifName;
    std::string ipAddress;
    std::string netmask;
    std::string broadcastAddress;
    CNetworkManager::EInterfaceRequestType_t interfaceRequest;

    /// Configure physical Interfaces
    for (const auto &mypair : mPhysicalInterface)
    {
        ifName = (mypair.second).mInterfaceName;
        ipAddress = (mypair.second).mIpAddress;
        netmask = (mypair.second).mNetmask;
        broadcastAddress = (mypair.second).mbroadcastAddress;
        /// set IP configuration to the interfaces.
        if((mypair.second).mRequetsedLinkStatus != ELinkStatus_Up)
        {
            interfaceRequest = CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkDown;
        }
        else
        {
            interfaceRequest = CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkUp;
        }
        (void)setIpv4Address(ifName,ipAddress,interfaceRequest);
        (void)setIpv4NetMask(ifName,netmask);
        (void)setIpv4BroadcastAddress(ifName,broadcastAddress);

        if(mNoARP == true)
        {
            (void)disableARP(ifName);
        }
    }

    /// configure virtual interfaces.
    for (const auto &mypair : mVirtualInterface)
    {
        const std::string vlanName = (mypair.second).mVlanName;
       
        ifName = ((mypair.second).mPhysicalInterfaceInfo).mInterfaceName;
        ipAddress = ((mypair.second).mPhysicalInterfaceInfo).mIpAddress;
        netmask = ((mypair.second).mPhysicalInterfaceInfo).mNetmask;
        broadcastAddress = ((mypair.second).mPhysicalInterfaceInfo).mbroadcastAddress;
        /// Create VLAN and set IP configurations.
        (void)createVlan(vlanName,(mypair.second).mVlanTag,ifName,(mypair.second).mVlanPriority);
        std::this_thread::sleep_for(std::chrono::milliseconds(10U));
        /// set IP configuration to the interfaces.
        if(((mypair.second).mPhysicalInterfaceInfo).mRequetsedLinkStatus != ELinkStatus_Up)
        {
            interfaceRequest = CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkDown;
        }
        else
        {
            interfaceRequest = CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkUp;
        }

        (void)setIpv4Address(vlanName,ipAddress,interfaceRequest);
        (void)setIpv4NetMask(vlanName,netmask);
        (void)setIpv4BroadcastAddress(vlanName,broadcastAddress);

        if(mNoARP == true)
        {
            (void)disableARP(ifName);
        }
    }
}

void CNetworkManager::monitorInterfaces(void)
{
    for (const auto &mypair : currentInterfaceConfig)
    {
        const std::string ifName = (mypair.first);
        ELinkStatus_t linkStatus;
        struct sockaddr_in* sockAddr;
        int sockFd;
        std::string ipAddr;
        struct ifreq ifr;
        bool notifyStatus = false;
        static int no_interface_flag = 0;

        (void)memset(&ifr, 0x00, sizeof(ifr));

        linkStatus =  ELinkStatus_Down;
        /// Get the Interface Name .
        sockFd = socket(AF_INET, SOCK_DGRAM, 0);
        /// Get the Interface Name .
        if (sockFd != -1)
        {
            if (isInterfaceValid(ifName) == true)
            {
                no_interface_flag=0;
#ifdef __linux__
                (void)strlcpy(ifr.ifr_name, ifName.c_str(), sizeof(ifr.ifr_name)/sizeof(ifr.ifr_name[0]));
                (void)ioctl(sockFd, SIOCGIFFLAGS, &ifr);
                /// Read interface status , if current status different from requested status send message.
                if ((ifr.ifr_flags & IFF_UP))
                {
                    /*Do nothing*/
                }
#else
                struct ifmediareq ifmr;
                (void)strlcpy(ifmr.ifm_name, ifName.c_str(), sizeof(ifmr.ifm_name));
                (void)ioctl(sockFd,SIOCGIFMEDIA,&ifmr);
                (void)strlcpy(ifr.ifr_name, ifName.c_str(), sizeof(ifr.ifr_name));
                (void)ioctl(sockFd, SIOCGIFFLAGS, &ifr);
                /// Read interface status , if current status different from requested status send message.
                if (((ifr.ifr_flags & IFF_UP) == IFF_UP) && ((ifmr.ifm_status & IFM_ACTIVE) == IFM_ACTIVE) )
                {
                    /*Do nothing*/
                }
#endif
                if (((ifr.ifr_flags & IFF_UP) == IFF_UP) && ((ifr.ifr_flags & IFF_RUNNING) == IFF_RUNNING) )
                {
                    linkStatus = ELinkStatus_Up;
                }
                else
                {
                    LOGV(&gNMLogContext, "NetworkInterface down : ",+( ifr.ifr_flags & IFF_RUNNING));
                }

                if((mypair.second).mLinkStatus != linkStatus)
                {
                    ///< Notify Application
                    LOGV(&gNMLogContext, "Link status changed for interface and LinkSts",ifName, linkStatus);

                    ///< TODO: Retry mechanism option check.
                }

                /// compare IP
                (void)memset(&ifr, 0x00, sizeof(ifr));
                (void)strlcpy(ifr.ifr_name, ifName.c_str(), sizeof(ifr.ifr_name));
                (void)ioctl(sockFd, SIOCGIFADDR, &ifr);
                sockAddr = reinterpret_cast<struct sockaddr_in *>(&ifr.ifr_addr);
                ipAddr = std::string(inet_ntoa(sockAddr->sin_addr));
                /// -# Read Ip Address , if the IP configured is different ,then notify the changes
                if(((mypair.second).mIpAddress).compare(ipAddr) != 0)
                {
                    ///< Ip address changed
                    LOGD(&gNMLogContext, "IP changed for interface ",ifName);
                    currentInterfaceConfig[ifName].mIpAddress = ipAddr;
                    notifyStatus = true;
                }
            }
            else
            {
                if(no_interface_flag == 0)
                {
                    no_interface_flag=1;
                    notifyStatus = true;
                }
            }

            if(notifyStatus != false)
            {
                notifyInterfaceChanges(ifName,ipAddr,linkStatus);
            }

            (void)close(sockFd);
        }
    }

}

bool CNetworkManager::setInterfaceUp(std::string interfaceName)
{
    struct ifreq ifr;
    int sockFd;
    bool retStatus = true;
    const std::string ipAddr = "0.0.0.0";

    (void)memset(&ifr, 0x00, sizeof ifr);

    /// Check if the interface is valid.
    retStatus = isInterfaceValid(interfaceName);

    if (retStatus != false)
    {
        sockFd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sockFd != -1)
        {
            (void)strlcpy(ifr.ifr_name, &interfaceName[0], sizeof(ifr.ifr_name));
            /// get existing ifreq flag values
            if (ioctl(sockFd, SIOCGIFFLAGS, &ifr) != -1)
            {
                /// set the IFF_UP and IFF_RUNNING bit .
                ifr.ifr_flags |= (IFF_UP| IFF_RUNNING);
                /// update the ifreq flag values
                if (ioctl(sockFd, SIOCSIFFLAGS, &ifr) == -1)
                {
                    LOGD(&gNMLogContext, "SIOCSIFFLAGS request failed ");
                    retStatus = false;
                }
                else
                {
                    currentInterfaceConfig[interfaceName].mLinkStatus = ELinkStatus_Up;
                    notifyInterfaceChanges(interfaceName,ipAddr,ELinkStatus_Up);
                }
            }
            else
            {
                LOGD(&gNMLogContext, "SIOCGIFFLAGS request failed ");
                retStatus = false;
            }
            (void)close(sockFd);

        }
        else
        {
            LOGD(&gNMLogContext, "Socket creation failed ");
            retStatus = false;
        }
    }
    else
    {
        LOGD(&gNMLogContext, "Interface not valid ");
    }
    return retStatus;
}

bool CNetworkManager::setInterfaceDown(std::string interfaceName)
{
    struct ifreq ifr;
    int sockFd;
    bool retStatus = true;
    const std::string ipAddr;

    (void)memset(&ifr, 0x00, sizeof ifr);

    /// Check if the interface is valid.
    retStatus = isInterfaceValid(interfaceName);

    if (retStatus != false)
    {
        sockFd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sockFd != -1)
        {
            (void)strlcpy(ifr.ifr_name, &interfaceName[0], sizeof(ifr.ifr_name));
            /// get existing ifreq flag values
            if (ioctl(sockFd, SIOCGIFFLAGS, &ifr) != -1)
            {
                /// clear the IFF_UP bit .
                ifr.ifr_flags &= ~IFF_UP;
                /// update the ifreq flag values.
                if (ioctl(sockFd, SIOCSIFFLAGS, &ifr) == -1)
                {
                    LOGD(&gNMLogContext, "SIOCSIFFLAGS request failed ");
                    retStatus = false;
                }
                else
                {
                    currentInterfaceConfig[interfaceName].mLinkStatus = ELinkStatus_Down;
                    notifyInterfaceChanges(interfaceName,ipAddr,ELinkStatus_Down);
                }
            }
            else
            {
                LOGD(&gNMLogContext, "SIOCGIFFLAGS request failed ");
                retStatus = false;
            }
            (void)close(sockFd);
        }
        else
        {
            LOGD(&gNMLogContext, "Socket creation failed ");
            retStatus = false;
        }
    }
    else
    {
        LOGD(&gNMLogContext, "Interface not valid ");
    }

    return retStatus;
}

bool CNetworkManager::setIpv4Address(
    std::string interfaceName,
    std::string ipAddr,
    const CNetworkManager::EInterfaceRequestType_t interfaceRequest
)
{
    struct sockaddr_in sin;
    int sockFd;
    struct ifreq ifr;
    bool retStatus = true ;
    ELinkStatus_t linkStatus;

    (void)memset(&ifr, 0x00, sizeof(ifr));
    (void)memset(&sin, 0x00, sizeof(sin));

    /// Check if the interface is valid.
    LOGD(&gNMLogContext,"setIpv4Address interfaceName ",interfaceName," len ",interfaceName.size());
    retStatus = isInterfaceValid(interfaceName);
    if(retStatus == true)
    {
        /// If valid ,check valid IP.
        sin.sin_family = static_cast<uint8_t>(AF_INET);
#ifdef __QNX__
        sin.sin_len = sizeof(sin);
#endif
        if (inet_aton(&ipAddr[0], &sin.sin_addr) != 0)
        { 
            //delete the ip address
            /// Create socket for INET and update the address information.
            (void)memset(&ifr, 0x00, sizeof(ifr));
            (void)strlcpy(ifr.ifr_name, &interfaceName[0], sizeof(ifr.ifr_name));
            (void)memcpy(&ifr.ifr_addr, &sin, sizeof(ifr.ifr_addr));

            /// create socket.
            sockFd = socket(AF_INET, SOCK_DGRAM, 0);
            if (sockFd != -1)
            {
                /// Set IP address using  SIOCSIFADDR ioctl flag.
                if (ioctl(sockFd, SIOCSIFADDR, &ifr) != -1)
                {
                    currentInterfaceConfig[interfaceName].mIpAddress = ipAddr;
                    /// Set Interface Up/Down as per the request.
                    /// Get ifreq.flags
                    (void)ioctl(sockFd, SIOCGIFFLAGS, &ifr);

                    if(interfaceRequest == CNetworkManager::EInterfaceRequestType_t::EInterfaceRequestType_SetLinkUp)
                    {
                        ifr.ifr_flags |= (IFF_UP| IFF_RUNNING);
                        linkStatus = ELinkStatus_Up;
                    }
                    else
                    {
                        ifr.ifr_flags &= ~IFF_UP;
                        linkStatus = ELinkStatus_Down;
                    }

                    if(ioctl(sockFd, SIOCSIFFLAGS, &ifr) == -1)
                    {
                        LOGD(&gNMLogContext, "Interface link status change failed");
                        retStatus = false;
                    }
                    else
                    {
                        currentInterfaceConfig[interfaceName].mLinkStatus = linkStatus;
                    }
                }
                else
                {
                    LOGD(&gNMLogContext, "Setting IPV4 address failed ");
                    retStatus = false;
                }
                (void)close (sockFd);  
            }
            else
            {
                LOGD(&gNMLogContext, "Socket creation failed ");
                retStatus = false;
            }  
        }
        else 
        {
           LOGD(&gNMLogContext, " Requested IPV4 address conversion to in_addr format failed "); 
           retStatus = false;
        }
    }
    else
    {
        LOGD(&gNMLogContext, "Invalid interface ",interfaceName);
        retStatus = false;
    }
    return retStatus;
}

bool CNetworkManager::setIpv4NetMask(std::string ifName,std::string netMask)
{
    struct sockaddr_in sin;
    int sockFd;
    struct ifreq ifr;
    bool retStatus = true;

    (void)memset(&ifr, 0x00, sizeof(ifr));
    (void)memset(&sin, 0x00, sizeof(sin));

    /// Check if the interface is valid.
    retStatus = isInterfaceValid(ifName);
    if(retStatus == true)
    {
        /// If valid ,check valid IP.
        sin.sin_family = static_cast<uint8_t>(AF_INET);
#ifdef __QNX__
        sin.sin_len = sizeof(sin);
#endif
        if (inet_aton(&netMask[0], &sin.sin_addr) != 0)
        {
            /// create socket for IPV4 and update the address information.
            (void)strlcpy(ifr.ifr_name, &ifName[0], sizeof(ifr.ifr_name));
            (void)memcpy(&ifr.ifr_addr, &sin, sizeof(ifr.ifr_addr));
            sockFd = socket(AF_INET, SOCK_DGRAM, 0);
            if (sockFd != -1)
            {
                /// Set IP address using  SIOCSIFADDR ioctl flag.
                if (ioctl(sockFd, SIOCSIFNETMASK, &ifr) ==-1)
                {
                    LOGD(&gNMLogContext, "Setting IPV4 netmask failed ");
                    retStatus = false;
                }
                (void)close (sockFd);
            }
            else
            {
                LOGD(&gNMLogContext, "Socket creation failed ");
                retStatus = false;
            }   
        }
        else
        {
            LOGD(&gNMLogContext, " Requested IPV4 netmask conversion to in_addr format failed ");
            retStatus = false;
        }
    }
    else
    {
        LOGD(&gNMLogContext, "Invalid interface ",ifName);
        retStatus = false;
    }
    return retStatus;
}

bool CNetworkManager::setIpv4BroadcastAddress(std::string ifName,std::string broadCastAddress)
{
    struct sockaddr_in sin;
    int sockFd;
    struct ifreq ifr;
    bool retStatus = true;

    (void)memset(&ifr, 0x00, sizeof(ifr));
    (void)memset(&sin, 0x00, sizeof(sin));

    ///  Check if the interface is valid.
    retStatus = isInterfaceValid(ifName);
    if(retStatus == true)
    {
        /// If valid ,check valid IP.
        sin.sin_family = static_cast<uint8_t>(AF_INET);
#ifdef __QNX__
        sin.sin_len = sizeof(sin);
#endif

        /// convert the IPV4 address string to in_addr format
        if (inet_aton(&broadCastAddress[0], &sin.sin_addr) != 0)
        {
            /// create socket for IPV4 and update the address information.
            (void)strlcpy(ifr.ifr_name, &ifName[0], sizeof(ifr.ifr_name));
            (void)memcpy(&ifr.ifr_broadaddr, &sin, sizeof(ifr.ifr_broadaddr));

            sockFd = socket(AF_INET, SOCK_DGRAM, 0);
            if (sockFd != -1)
            {
                /// Set IP address using  SIOCSIFADDR ioctl flag.
                if (ioctl(sockFd, SIOCSIFBRDADDR, &ifr) ==-1)
                {
                    LOGD(&gNMLogContext, "Setting IPV4 broadcast address failed ");
                    retStatus = false;
                }
                (void)close (sockFd);
            }
            else
            {
                LOGD(&gNMLogContext, "Socket creation failed "); 
                retStatus = false;
            }    
        }
        else 
        {
            LOGD(&gNMLogContext, " Requested IPV4 broadcast address conversion to in_addr format failed ");
            retStatus = false;
        }
    }
    else
    {
        LOGD(&gNMLogContext, "Invalid interface ",ifName);
        retStatus = false;
    }

    return retStatus;
}

bool CNetworkManager::removeIpv4Address(const std::string ifName)
{

    int sockFd;
    struct ifreq ifs;
    std::string ipAddr;
    bool ret = true;

    (void)memset(&ifs, 0, sizeof(ifs));
    ifs.ifr_addr.sa_family = static_cast<uint8_t>(AF_INET);
    sockFd = socket(static_cast<int>(ifs.ifr_addr.sa_family), SOCK_DGRAM, 0);
    if( sockFd != -1)
    {
        (void)strlcpy(ifs.ifr_name, ifName.c_str(), sizeof(ifs.ifr_name));
        if( ioctl(sockFd, SIOCGIFADDR, &ifs) == -1 ) {
            LOGD(&gNMLogContext,"get_ifaddr(): ioctl()");
            ret = false;
        }

        ipAddr = static_cast<std::string>(inet_ntoa((reinterpret_cast<struct sockaddr_in *>(&(ifs.ifr_addr)))->sin_addr));
        (void)set_route(ipAddr);

        (void)close(sockFd);
    }
    else
    {
        LOGD(&gNMLogContext,"get_ifaddr(): socket()");
        ret = false;
    }
    return ret;
}

#ifdef __linux__
bool CNetworkManager::createVlan(const std::string vlanName, const uint16_t vlanTag, const std::string ifName, const uint8_t vlanPriority)
{
    bool retStatus = true;
    int sockFd;
    struct vlan_ioctl_args vlan_data;
    std::string vlanNameIf; 

    /// Create socket for IPV4
    sockFd = socket( AF_INET, SOCK_DGRAM, 0 );
    if(sockFd != -1)
    {
        /// Check if the interface already exists. If interface doesn't exists create new interface.
        if (isInterfaceValid(vlanName) == false)
        {
            (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
            vlan_data.cmd = GET_VLAN_REALDEV_NAME_CMD ;
            (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));

            if (ioctl(sockFd, SIOCGIFVLAN, &vlan_data) == -1)
            {
                // If requested interface not exists, create the interface.
                (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
                vlan_data.cmd = ADD_VLAN_CMD ;
                vlan_data.u.VID = vlanTag ;
                (void)strlcpy(vlan_data.device1, ifName.c_str(), sizeof(vlan_data.device1));

                if(ioctl(sockFd, SIOCSIFVLAN, &vlan_data) != -1)
                {
                    // to get the target created vlan name.
                    vlanNameIf = ifName + "." + std::to_string(vlanTag);
                    (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
                    (void)strlcpy(vlan_data.device1, vlanNameIf.c_str(), sizeof(vlan_data.device1));
                    vlan_data.cmd = GET_VLAN_VID_CMD ;

                    if (ioctl(sockFd, SIOCGIFVLAN, &vlan_data) != -1)
                    {
                        // to ensure the vlan name interface with that id.
                        if(vlan_data.u.VID == vlanTag)
                        {
                            struct ifreq ifr;
                            (void)memset(&ifr, 0, sizeof(struct ifreq));

                            // Rename the vlan interface with the provided name
                            (void)strlcpy(ifr.ifr_name, vlanNameIf.c_str(), sizeof(ifr.ifr_name));
                            (void)strlcpy(ifr.ifr_newname, vlanName.c_str(), sizeof(ifr.ifr_newname));
                            if(ioctl(sockFd, SIOCSIFNAME, &ifr) == -1)
                            {
                                retStatus = false;
                                LOGE(&gNMLogContext, "VLAN interface name set Failed");
                            }
                        }  
                        else 
                        {
                            retStatus = false;
                            LOGE(&gNMLogContext, "VLAN ID is not matching with the provided ID");
                        }
                    }
                    else 
                    {
                        retStatus = false ;
                        LOGE(&gNMLogContext, "VLAN interface tag read Failed");
                    }

                    if(retStatus != false)
                    {
                        // to check the parent interface
                        (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
                        vlan_data.cmd = GET_VLAN_REALDEV_NAME_CMD ;
                        (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));

                        if (ioctl(sockFd, SIOCGIFVLAN, &vlan_data) == -1)
                        {
                            retStatus = false;
                            LOGE(&gNMLogContext, "VLAN interface creation Failed ");
                        }
                    }
                }
                else
                {
                    retStatus = false ;
                    LOGE(&gNMLogContext, "VLAN interface tag creation Failed");
                }
            }
            else
            {
                retStatus = true;
                LOGI(&gNMLogContext, "VLAN Interface already exists");
            }
        }
        else
        {
            retStatus = true;
            LOGI(&gNMLogContext, "VLAN Interface already exists");
        }

        if(retStatus != false)
        {
            // If a vlan interface is successfully created ,then update the priority value.
            // Vlan priority can be set between 0 to 7.
            if (vlanPriority <= 7U )
            {
                // Set ingress priority
                (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
                vlan_data.cmd = SET_VLAN_INGRESS_PRIORITY_CMD ;
                vlan_data.u.skb_priority = vlanPriority ;
                (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));

                if (ioctl(sockFd, SIOCSIFVLAN, &vlan_data) == -1)
                {
                    retStatus = false;
                    LOGE(&gNMLogContext, "VLAN Interface get config failed for setting priority." );
                }

                // Set egress priority
                (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));
                vlan_data.cmd = SET_VLAN_EGRESS_PRIORITY_CMD ;
                vlan_data.u.VID = vlanTag ;
                vlan_data.u.skb_priority = vlanPriority ;
                (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));

                if (ioctl(sockFd, SIOCSIFVLAN, &vlan_data) == -1)
                {
                    retStatus = false;
                    LOGE(&gNMLogContext, "VLAN Interface priority set failed" );
                }
            }
            else
            {
                retStatus = false;
                LOGE(&gNMLogContext, "Invalid Priority value ",static_cast<uint32_t>(vlanPriority));
            }
        }
        (void)close(sockFd);
    }
    else
    {
        retStatus = false;
        LOGE(&gNMLogContext, "Socket creation failed");
    }

    if (retStatus == true)
    {
        LOGI(&gNMLogContext,"Vlan Successfully created");
    }

    return retStatus;
}
#else
bool CNetworkManager::createVlan(const std::string vlanName, const uint16_t vlanTag, const std::string ifName, const uint8_t vlanPriority)
{
    struct vlanreq vlan_data;
    struct ifreq ifr;
    bool  retStatus = true;
    int sockFd;

    /// Create socket for IPV4
    sockFd = socket( AF_INET, SOCK_DGRAM, 0 );
    if(sockFd != -1)
    {
        (void)memset(&ifr,0,sizeof(struct ifreq));
        (void)strlcpy(ifr.ifr_name, vlanName.c_str(), sizeof(ifr.ifr_name));
        /// Check if the interface already exists. If interface doesn't exists create new interface.
        if (isInterfaceValid(vlanName) == false)
        {
            /// If requested interface not exists, create the interface.
            if(ioctl(sockFd, SIOCIFCREATE, &ifr) != -1)
            {
                LOGD(&gNMLogContext, "Interface creation success ");
                (void)memset( &vlan_data, 0, sizeof( struct vlanreq ) );
                (void)strlcpy(ifr.ifr_name, vlanName.c_str(), sizeof(ifr.ifr_name));
                ifr.ifr_ifru.ifru_addr.sa_family = static_cast<uint8_t>(AF_INET);
                ifr.ifr_ifru.ifru_data= reinterpret_cast<vlanreq *>(&vlan_data);
                /// Get the vlan data for the requested interface

#ifndef QNX_710_IOCTL_SOCKET_DEPRECATION
                if (ioctl_socket(sockFd, SIOCGETVLAN, &ifr) != -1)
                {
                    LOGD(&gNMLogContext, "VLAN data get for VLAN Tag/Id value setting success ");
                    vlan_data.vlr_tag = vlanTag;
                    /// set vlan tag/ Id value
                    if (ioctl_socket(sockFd,SIOCSETVLAN,&ifr) == -1)
                    {
                        LOGD(&gNMLogContext, "VLAN Tag/Id value setting failure");
                        retStatus = false;
                    }

                    if(retStatus != false)
                    {
                        LOGD(&gNMLogContext, "VLAN Tag/Id setting successful ");
                        /// Get Vlan config and set physical interface to vlan.
                        (void)memset( &vlan_data, 0, sizeof( struct vlanreq ) );
                        ifr.ifr_ifru.ifru_data= reinterpret_cast<vlanreq *>(&vlan_data);
                        if (ioctl_socket(sockFd, SIOCGETVLAN, &ifr) == -1)
                        {
                            LOGD(&gNMLogContext, "VLAN get data for physical interface mapping failed ");
                            retStatus = false;
                        }

                        if(retStatus != false)
                        {
                            LOGD(&gNMLogContext, "VLAN get data for physical interface mapping success ");
                            (void)strlcpy(vlan_data.vlr_parent, ifName.c_str(), sizeof(vlan_data.vlr_parent));
                            vlan_data.vlr_tag = vlanTag;
                            /// Set VLAN tag and physical interface to the vlan interface.
                            if (ioctl_socket(sockFd, SIOCSETVLAN, &ifr) == -1)
                            {
                                LOGD(&gNMLogContext, "VLAN set data for physical interface mapping success ");
                                retStatus = false;
                            }
                        }
                    }
                }
                else
                {
                    LOGD(&gNMLogContext, "Failure in getting vlan data from the interface");
                    retStatus = false;
                }
#endif

                /// If vlan creation failed , delete the created interfaces.
                if(retStatus == false)
                {
                    (void)ioctl(sockFd, SIOCIFDESTROY, &ifr);
                    LOGD(&gNMLogContext, "Vlan Interface creation Failed ");
                }
            }
            else
            {
                LOGD(&gNMLogContext, "Interface creation Failed ");
                retStatus = false;
            }
        }
        else
        {
            LOGD(&gNMLogContext, "Interface already exists");
            /// If interface already exists check if its a vlan interface.
            /// TODO : Need to add vlan interface check
            retStatus = true;
        }

        if(retStatus != false)
        {
            /// If a vlan interface is successfully created ,then update the priority value.
            /// Vlan priority can be set between 0 to 7.
            if (vlanPriority <= 7U )
            {
                /// Get Vlan config data.
                (void)memset( &vlan_data, 0, sizeof( struct vlanreq ) );
                ifr.ifr_data = reinterpret_cast<vlanreq *>(&vlan_data);
                if (ioctl(sockFd, SIOCGETVLANPRIO, reinterpret_cast<ifreq*>(&ifr)) == -1)
                {
                    LOGD(&gNMLogContext, "VLAN Interface get config failed for setting priority." );
                    retStatus = false;
                }
                if(retStatus != false)
                {
                    /// update vlan priority and set the priority to the interface .
                    vlan_data.vlr_tag = vlanPriority;
                    if (ioctl(sockFd, SIOCSETVLANPRIO, reinterpret_cast<ifreq*>(&ifr)) == -1)
                    {
                        retStatus = false;
                        LOGD(&gNMLogContext, "VLAN Interface priority set failed" );
                    }
                }
            }
            else
            {
                LOGD(&gNMLogContext, "Invalid Priority value ",static_cast<uint32_t>(vlanPriority));
                retStatus = false;
            }
        }
        (void)close(sockFd);
    }
    else
    {
        LOGD(&gNMLogContext, "Socked creation failed");
        retStatus = false;
    }

    if (retStatus == true)
    {
        LOGD(&gNMLogContext,"Vlan Successfully created \n");
    }

    return retStatus;
}
#endif

#ifdef __linux__
bool CNetworkManager::destroyVlan(const std::string vlanName)
{
    struct vlan_ioctl_args vlan_data;
    bool retStatus = true;
    int sockFd;
    std::map<std::string,currentInterfaceConfig_t>::iterator configIt;

    /// Create socket for IPV4
    sockFd = socket( AF_INET, SOCK_DGRAM, 0 );
    if(sockFd != -1)
    {
        /// Check if the interface already exists. If interface doesn't exists return false.
        if (isInterfaceValid(vlanName) == true)
        {
            /// to check the vlan interface is available /not
            (void)memset(&vlan_data, 0, sizeof(struct vlan_ioctl_args));

            (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));
            vlan_data.cmd = GET_VLAN_REALDEV_NAME_CMD ;

            if (ioctl(sockFd, SIOCGIFVLAN, &vlan_data) == -1)
            {
                LOGE(&gNMLogContext, "Socket VLAN get data for the Vlan interface failed ",vlanName);
                retStatus = false;
            }

            if(retStatus != false)
            {
                vlan_data.cmd = DEL_VLAN_CMD ;
                // Parent interface name required
                (void)strlcpy(vlan_data.device1, vlanName.c_str(), sizeof(vlan_data.device1));

                /// Set the vlan data to the interface using ioctl_socket command.
                if (ioctl(sockFd, SIOCSIFVLAN, &vlan_data) == -1)
                {
                    LOGE(&gNMLogContext, "Socket VLAN set data to clear the vlan data failed ",vlanName);
                    retStatus = false;
                }
                if(retStatus != false)
                {
                    LOGI(&gNMLogContext, " VLAN interface successfully destroyed ",vlanName);
                    configIt = currentInterfaceConfig.find(vlanName);
                    if (configIt != currentInterfaceConfig.end())
                    {
                        currentInterfaceConfig.erase(configIt);
                    }
                }
            }
        }
        else
        {
            retStatus = false;
            LOGE(&gNMLogContext, "VLAN Interface doesn't exists");
        }
        (void)close(sockFd);
    }
    else
    {
        retStatus = false;
        LOGE(&gNMLogContext, "Socked creation failed");
    }
    return retStatus;
}
#else
bool CNetworkManager::destroyVlan(const std::string vlanName)
{
    struct vlanreq vlan_data;
    struct ifreq ifr;
    bool retStatus = true;
    int sockFd;
    std::map<std::string,currentInterfaceConfig_t>::iterator configIt;

    /// Create socket for IPV4
    sockFd = socket( AF_INET, SOCK_DGRAM, 0 );
    if(sockFd != -1)
    {
        /// Initialize the ifreq  and vlanreq structures to zero.
        (void)memset(&ifr,0,sizeof(struct ifreq));
        (void)memset( &vlan_data, 0, sizeof( struct vlanreq ) );
        /// set the vlan name , family and vlan data reference to the ifreq.
        (void)strlcpy(ifr.ifr_name, vlanName.c_str(), sizeof(ifr.ifr_name));
        ifr.ifr_addr.sa_family = static_cast<uint8_t>(AF_INET);
        ifr.ifr_data=(caddr_t)&vlan_data;

        /// Get then vlan data for the requested interface using the ioctl_socket command.
#ifndef QNX_710_IOCTL_SOCKET_DEPRECATION
        if(ioctl_socket( sockFd, SIOCGETVLAN, &ifr ) == -1)
        {
            LOGE(&gNMLogContext, "Socket VLAN get data for the Vlan interface failed ",vlanName);
            retStatus = false;
        }

        if(retStatus != false)
        {
            /// If the requested vlan exists. clear the vlan data of the interface.
            (void)memset(&vlan_data, 0, sizeof( struct vlanreq));
            ifr.ifr_data=(caddr_t)&vlan_data;
            vlan_data.vlr_parent[0]='\0';

            /// Set the vlan data to the interface using ioctl_socket command.
            if (ioctl_socket( sockFd, SIOCSETVLAN, &ifr) == -1)
            {
                LOGE(&gNMLogContext, "Socket VLAN set data to clear the vlan data failed ",vlanName);
                retStatus = false;
            }

            if(retStatus != false)
            {
                /// Clear vlan config data
                ifr.ifr_data=nullptr;
                /// Destroy the vlan interface using ioctl command.
                if(ioctl(sockFd, SIOCIFDESTROY, &ifr) == -1)
                {
                    LOGE(&gNMLogContext, "Destroy VLAN interface failed ",vlanName);
                    retStatus = false;
                }
                else
                {
                    LOGI(&gNMLogContext, " VLAN interface successfully destroyed ",vlanName);
                    configIt = currentInterfaceConfig.find(vlanName);
                    if (configIt != currentInterfaceConfig.end())
                    {
                        (void)currentInterfaceConfig.erase(configIt);
                    }
                }
            }
        }
        (void)close(sockFd);
#endif

    }
    else
    {
        LOGD(&gNMLogContext, "Socked creation failed");
        retStatus = false;
    }
    return retStatus;
}
#endif

///
/// @brief This method is used to disable ARP support for the interface.
///
/// @param[in] interfaceName name of the requested interface. e.g. "vlan20" , "eth0.300" ..
///
/// @return bool It returns the status of the request.
///              -# true - If the vlan interface is removed.
///              -# false - Error in vlan removal.
///
bool CNetworkManager::disableARP(const std::string interfaceName)
{
    bool retStatus = true;
    int sockFd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockFd != -1)
    {
        struct ifreq ifr;
        (void)memset(&ifr, 0, sizeof(ifr));

        /// Set the interface name
        (void)strlcpy(ifr.ifr_name, interfaceName.c_str(), sizeof(ifr.ifr_name));

        /// Get the current interface flags
        if (ioctl(sockFd, SIOCGIFFLAGS, &ifr) == -1)
        {
            LOGE(&gNMLogContext, "Failed to get interface flags: ", interfaceName);
            retStatus = false;
        }

        if(retStatus != false)
        {
            /// Disable ARP by setting the NOARP flag
            ifr.ifr_flags |= IFF_NOARP;

            /// Set the modified flags back to the interface
            if (ioctl(sockFd, SIOCSIFFLAGS, &ifr) == -1)
            {
                LOGE(&gNMLogContext, "Failed to disable ARP: ", interfaceName);
                retStatus = false;
            }
            LOGE(&gNMLogContext, "ARP disabled successfully for interface: ", interfaceName);
        }
        close(sockFd);
    }
    else
    {
        LOGE(&gNMLogContext, "Socked creation failed");
        retStatus = false;
    }

    return retStatus;
}

bool CNetworkManager::isInterfaceValid(const std::string ifName)
{
    bool retStatus = false;
    struct ifaddrs *pIfAddrs= NULL;
    struct ifaddrs *pIfAddrsIter= NULL;
    std::string tempIfName;

    /// get available network interfaces.
    LOGV(&gNMLogContext,"isInterfaceValid interfaceName ",ifName," len ",ifName.length());
    if(0 == getifaddrs(&pIfAddrs))
    {
        /// pIfAddrs is a linked list of structures of the network interfaces.
        pIfAddrsIter = pIfAddrs;
        do
        {
            tempIfName = std::string(pIfAddrsIter->ifa_name);
            LOGV(&gNMLogContext, "Interface name ",tempIfName," len ",tempIfName.length(),\
                 " Requseted Interface name ",ifName," length ",ifName.length());
            if(0 == ifName.compare(std::string(pIfAddrsIter->ifa_name)))
            {
                /// If the requested interface is same as the current interface name , then return true.
                retStatus = true;
                LOGV(&gNMLogContext, "Available Interface name ",std::string(pIfAddrsIter->ifa_name));
                break;
            }
            pIfAddrsIter = pIfAddrsIter->ifa_next;
        }
        while ((pIfAddrsIter) != nullptr);
        /// free the allocated memory for pIfAddrs
        freeifaddrs(pIfAddrs);
    }
    LOGV(&gNMLogContext, "Interface ",ifName," valid ",static_cast<uint32_t>(retStatus));
    return retStatus;
}

void CNetworkManager::notifyInterfaceChanges(
    const std::string interface,
    const std::string ipAddress,
    const ELinkStatus_t linkStatus
)
{
    NetworkInterfaceStatus netwkInterfaceStatus;

    /// Update the Dk message for Interface status changes
    netwkInterfaceStatus.interfaceNameLength= static_cast<uint8_t>(interface.length());
    (void)std::copy(interface.begin(),interface.end(),netwkInterfaceStatus.interfaceName);
    netwkInterfaceStatus.linkStatus= linkStatus;
    netwkInterfaceStatus.ipAddressLength= static_cast<uint8_t>(ipAddress.length());
    (void)std::copy(ipAddress.begin(),ipAddress.end(),netwkInterfaceStatus.ipAddress);

    LOGD(&gNMLogContext, "Dk message DkMsgNetworkInterfaceStatus send for interface changes");

    /// send dk message.
    DK_RTE_Send_NetworkInterfaceStatus(netwkInterfaceStatus);
}


#define RODST "172.16.4.109"
#define RTGATEWAY "192.168.2.246"
#define RTGENMASK "255.255.0.0"
static int set_route(const std::string ipAddr) {
    (void)ipAddr;
#ifdef __linux__
    struct rtentry rt;
#else
    struct ortentry rt;
#endif
    int sock = -1;
    int rc;
    struct sockaddr_in *rout_dst;
    struct sockaddr_in *rt_gate;
    struct sockaddr_in *rt_netmask;

    (void)memset(&rt,0,sizeof(rt));

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock != -1 )
    {   
        rout_dst = reinterpret_cast<struct sockaddr_in *>(&rt.rt_dst);
        rt_gate = reinterpret_cast<struct sockaddr_in *>(&rt.rt_gateway);
#ifdef __linux__
        rt_netmask = reinterpret_cast<struct sockaddr_in *>(&rt.rt_genmask);
#else
        rt_netmask = reinterpret_cast<struct sockaddr_in *>(&rt.rt_netmask);
#endif

        rout_dst->sin_family = static_cast<uint8_t>(AF_INET);
        rt_gate->sin_family = static_cast<uint8_t>(AF_INET);
        rt_netmask->sin_family = static_cast<uint8_t>(AF_INET);

        rout_dst->sin_addr.s_addr=inet_addr(RODST);
        rt_gate->sin_addr.s_addr=inet_addr("0.0.0.0");
        rt_netmask->sin_addr.s_addr=inet_addr(RTGENMASK);
#ifdef __QNX__
        rt_gate->sin_len=sizeof(*rt_gate);
        rout_dst->sin_len=sizeof(*rout_dst);
        rt_netmask->sin_len=sizeof(*rt_netmask);
#endif
        
        rt.rt_flags=0;

        rc = ioctl(sock, SIOCDELRT, &rt); // SIOCADDRT or SIOCDELRT
        if (rc == -1)
        {
            LOGD(&gNMLogContext,"Delete route failed");
        }
        (void)close(sock);
    }
    return sock;

}

} // platform
} // srvc
} // dk
