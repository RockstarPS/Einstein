//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
///
/// @file network_manager.h
/// @defgroup NetworkManager
///
/// @brief Network Manager performs the network tasks such as detecting an interface, setting the IP address, creating
///        and destroying VLANs etc.
///
/// @ingroup NetworkManager
///
/// @brief  CNetworkManager class. The Network manager is provides the interface for configuration of the network
///         interfaces. It is responsible for
///     -# Enable / Disable an Ethernet interface
///     -# IP configuration for the interface link.
///     -# Enable /disable the IP connections.
///     -# Network monitoring and failure detection
///     -# Create and destroy VLAN connections.
///     -# Set-up firewall policy.
///
//---------------------------------------------------------------------------------------------------------------------

#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <cstdint>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <map>
#include <network_packet_filter_if.h>
#include "dk_runtime_types.h"
#include "dk_runtime_parserif.h"

#ifdef ENET_PHY_TJA1101
#include "network_manager_tja1101.h"
#endif

#ifdef ENET_PHY_TC812
#include "network_manager_enet_register.h"
#endif


namespace dk
{
namespace srvc
{
namespace platform
{
using namespace dk::runtime;


class CNetworkManager
{
public:
    ///
    /// @brief It defines the link status of the interface.
    ///
    /*typedef enum : uint8_t
    {
    	ELinkStatus_Down=0, ///< Interface link status down.
    	ELinkStatus_Up,     ///< Interface link status Up.
    	ELinkStatus_Last    ///< Guard
    } ELinkStatus_t;*/

    ///
    /// @brief It defines the request type of the firewall operation.
    ///
    typedef enum : uint8_t
    {
        EFirewallRequest_Enable = 0,    ///< Enable firewall.
        EFirewallRequest_Disable,       ///< Disable firewall.
        EFirewallRequest_Last           ///< Guard
    } EFirewallRequestType_t;

    ///
    /// @brief It defines the type of Interface.
    ///
    typedef enum : uint8_t
    {
        EIpRequestType_Set = 0, ///< Set the IP configuration for the interface.
        EIpRequestType_Clear,   ///< Remove the IP configuration for the interface.
        EIpRequestType_Last     ///< Guard.
    } EIpInterfaceRequestType_t;

    ///
    /// @brief It defines the request type of the interface link status change.
    ///
    typedef enum : uint8_t
    {
        EInterfaceRequestType_SetLinkUp = 0,    ///< Set the interface link status up.
        EInterfaceRequestType_SetLinkDown,      ///< Set the interface link status down.
        EInterfaceRequestType_Last              ///< Guard.
    } EInterfaceRequestType_t;

    ///
    /// @brief Constructor of CNetworkManager class.
    ///
    CNetworkManager() {}

    ///
    /// @brief Destructor of CNetworkManager class.
    ///
    ~CNetworkManager() {}

    ///
    /// @brief CNetworkManager Init method. This method is used to get the Interface configuration values from the
    ///        ini file and configure the interfaces.This method is also used to get the firewall configuration and
    ///        enable /disable based on the configuration.
    ///
    void init(void);

    ///
    /// @brief CNetworkManager periodic task .This method shall be scheduled periodically with the configured value.
    /// This method handles the periodic monitoring of interface status changes.
    ///
    void periodicTaskInMs(void);

    ///
    /// @brief This method is used to modify the link status of the requested interface.
    ///
    /// @param[in] interfaceName name of the requested interface. e.g. "eth0" , "dm0" ..
    /// @param[in] linkType request type of the interface link status change.Value should be as below,
    ///                     -# EInterfaceRequestType_SetLinkUp  - Set the interface link status up.
    ///                     -# EInterfaceRequestType_SetLinkDown - Set the interface link status down.
    ///
    void modifyLinkStatus(const std::string interfaceName, const CNetworkManager::EInterfaceRequestType_t linkType);

    ///
    /// @brief This method is used to create/destroy the requested vlan interface.
    ///
    /// @param[in] requestType vlan interface operation request type.Value should be as below,
    ///                        -# EVlanRequestType_Create - Create the vlan interface.
    ///                        -# EVlanRequestType_Destroy - Destroy the vlan interface.
    /// @param[in] vlanName name of the requested vlan interface. e.g. "vlan20" , "eth0.300" ..
    /// @param[in] vlanTag vlan Id value of the requested vlan interface. It is the 12bit value.
    ///            Range - 0 to 4095 . The value 0 and 4095 reserved.
    /// @param[in] ifName name of the physical interface to be linked to the requested interface. e.g. "eth0","dm0" ..
    /// @param[in] vlanPriority defines the priority level.It is 3bit value .
    ///            Value Range 0-7  ; 0-Highest , 7-lowest
    /// @param[in] linkType request type of the interface link status change.Value should be as below,
    ///                     -# EInterfaceRequestType_SetLinkUp  - Set the interface link status up.
    ///                     -# EInterfaceRequestType_SetLinkDown - Set the interface link status down.
    ///
    void modifyVlanInterface(
        const EVlanRequestType_t requestType,
        const std::string vlanName,
        const uint16_t vlanTag,
        const std::string ifName,
        const uint8_t vlanPriority
    );

    ///
    /// @brief This method is used to enable/disable the firewall.
    ///
    /// @param[in] requestType It defines the request type of the firewall operation.Value should be as below,
    ///                     -# EFirewallRequest_Enable  - Enable the firewall configuration.
    ///                     -# EFirewallRequest_Disable - Disable the firewall configuration.
    ///
    void modifyFirewall(const EFirewallRequestType_t requestType);

    ///
    /// @brief This method is used to set/clear the IP configuration of the requested interface.
    ///
    /// @param[in] requestType It defines the request type of Interface configuration.
    ///                        -# EIpRequestType_Set - Set the IP configuration for the interface.
    ///                        -# EIpRequestType_Clear - Remove the IP configuration for the interface.
    /// @param[in] interfaceName name of the requested interface. e.g. "eth0" , "dm0" ..
    /// @param[in] ipAddress ipv4 address of the requested interface . value should be string as 192.168.0.11
    /// @param[in] netMask ipv4 net mask address of the requested interface . value should be string as 192.168.0.11
    /// @param[in] broadcastAddress ipv4 broadcast address of the requested interface . value should be string as
    ///            192.168.0.11
    /// @param[in] interfaceRequestType request type of the interface link status change.Value should be as below,
    ///                     -# EInterfaceRequestType_SetLinkUp  - Set the interface link status up.
    ///                     -# EInterfaceRequestType_SetLinkDown - Set the interface link status down.
    ///
    void modifyInterface(
        const CNetworkManager::EIpInterfaceRequestType_t requestType,
        const std::string interfaceName,
        const std::string ipAddress,
        const std::string netMask,
        const std::string broadcastAddress,
        const CNetworkManager::EInterfaceRequestType_t interfaceRequestType
    );


    void stop(void);

#ifdef ENET_PHY_TC812
    std::unique_ptr< CNetworkPhyEnet> mpNetworkPhyEnet;
#endif

#ifdef ENET_PHY_TJA1101
    std::unique_ptr< CNetworkPhyEnetTja1101> mpNetworkPhyEnetTja1101;
#endif

    std::string mNICType = "invalid";

private:

	dk::runtime::core::ParserIf  mParserObj;

    bool mFireWallConfigEnable = false;

    ///
    /// @brief By default No ARP is not enabled.
    ///
    bool mNoARP = false;

    ///
    /// @brief It defines the physical interface configuration structure.
    ///
    typedef struct
    {
        std::string     mInterfaceName;         ///< Interface name value.
        ELinkStatus_t   mRequetsedLinkStatus = ELinkStatus_Down;   ///< requested link status value.
        std::string     mIpAddress;             ///< IPV4 address for the interface.
        std::string     mNetmask;               ///< IPV4 net mask address for the interface.
        std::string     mbroadcastAddress;      ///< IPV4 broadcast address for the interface.
    } physicalInterfaceInfo_t;

    ///
    /// @brief It defines the interface current configuration.
    ///
    typedef struct
    {
        ELinkStatus_t   mLinkStatus = ELinkStatus_Down;     ///< current link status value.
        std::string     mIpAddress;             ///< IPV4 address for the interface.
    } currentInterfaceConfig_t;

    std::map<std::string,currentInterfaceConfig_t> currentInterfaceConfig;

    ///
    /// @brief It defines the vlan virtual interface configuration structure.
    ///
    typedef struct
    {
        std::string mVlanName;          ///< VLAN interface Name.
        uint16_t    mVlanTag = 1U;           ///< VLAN ID value for the vlan interface.
        uint8_t     mVlanPriority = 7U;      ///< VLAN priority value for the interface.
        physicalInterfaceInfo_t mPhysicalInterfaceInfo; ///< physical interface config value.
    } virtualInterfaceInfo_t;

    ///
    /// @brief It holds the configuration of the requested physical interfaces.
    ///
    std::map<std::string,physicalInterfaceInfo_t> mPhysicalInterface;

    ///
    /// @brief It holds the configuration of the requested vlan interfaces.
    ///
    std::map<std::string,virtualInterfaceInfo_t> mVirtualInterface;

    ///
    /// @brief It defines the reference to the supported firewall object type.
    ///
    std::unique_ptr<CNetworkPacketFilterIf> mNetworkPacketFilterInst = nullptr;

    ///
    /// @brief It is the path location of INI file. This path will be searched first for INI file.
    ///
    ///const std::string mIniFilePath1 = "/tmp/network_manager.ini";
    const std::string mIniFilePath1 = "/system/etc/network_manager.ini";

    ///
    /// @brief It is the path location of INI file. This path will be searched for INI file if the file not found in
    ///        mIniFilePath1.
    ///
    const std::string mIniFilePath2 = "/etc/network_manager.ini";

    ///
    /// @brief This method is used to parse and validate the ini configuration file. If the configuration values are
    ///        valid ,if loads the value from the ini file else default value will be used.
    ///
    void iniHandler(void);

    ///
    /// @brief This method is used to change the interface link status to Up.
    ///
    /// @param[in] interfaceName Interface name to which the status should be changed.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface link status changed to Up .
    ///              -# false - Error in setting the interface link status to Up.
    ///
    bool setInterfaceUp(std::string interfaceName);

    ///
    /// @brief This method is used to change the interface link status to Down.
    ///
    /// @param[in] interfaceName Interface name to which the status should be changed.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface link status changed to Down .
    ///              -# false - Error in setting the interface link status to Down.
    ///
    bool setInterfaceDown(std::string interfaceName);

    ///
    /// @brief This method is used to set the interface ipv4 address.
    ///
    /// @param[in] interfaceName Interface name to which the IPv4 should be changed.
    /// @param[in] ipAddr IP address value to be set for the interface.
    /// @param[in] interfaceRequest link status request type for the interface.
    ///                     -# EInterfaceRequestType_SetLinkUp  - Set the interface link status up.
    ///                     -# EInterfaceRequestType_SetLinkDown - Set the interface link status down.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface address is set.
    ///              -# false - Error in setting the interface address.
    ///
    bool setIpv4Address(
        std::string interfaceName,
        std::string ipAddr,
        const CNetworkManager::EInterfaceRequestType_t interfaceRequest
    );

    ///
    /// @brief This method is used to set the interface ipv4 broadcast address.
    ///
    /// @param[in] ifName Interface name to which the ipv4 broadcast address should be changed.
    /// @param[in] broadCastAddress IPV4 broadcast address value to be set for the interface.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface address is set.
    ///              -# false - Error in setting the interface address.
    ///
    static bool setIpv4BroadcastAddress(std::string ifName,std::string broadCastAddress);

    ///
    /// @brief This method is used to check if the given interface is valid.
    ///
    /// @return bool - true  if the interface is valid.
    ///                false if the interface is invalid.
    ///
    static bool isInterfaceValid(const std::string ifName);

    ///
    /// @brief This method is used to set the interface ipv4 netmask address.
    ///
    /// @param[in] ifName Interface name to which the ipv4 netmask address should be changed.
    /// @param[in] netMask IPV4 netmask address value to be set for the interface.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface address is set.
    ///              -# false - Error in setting the interface address.
    ///
    static bool setIpv4NetMask(std::string ifName,std::string netMask);

    ///
    /// @brief This method is used to clear the interface ipv4 address.
    ///
    /// @param[in] ifName Interface name to which the ipv4 address should be changed.
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the interface address is removed.
    ///              -# false - Error in removing the interface address.
    ///
    static bool removeIpv4Address(const std::string ifName);

    ///
    /// @brief This method is used to create the vlan interface and configure the vlan interface.
    ///
    /// @param[in] vlanName name of the requested vlan interface. e.g. "vlan20" , "eth0.300" ..
    /// @param[in] vlanTag vlan Id value of the requested vlan interface. It is the 12bit value.
    ///            Range - 0 to 4095 . The value 0 and 4095 reserved.
    /// @param[in] ifName name of the physical interface to be linked to the requested interface. e.g. "eth0","dm0" ..
    /// @param[in] vlanPriority defines the priority level.It is 3bit value .
    ///            Value Range 0-7  ; 0-Highest , 7-lowest
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the vlan interface is created.
    ///              -# false - Error in vlan creation.
    static bool createVlan(const std::string vlanName,const uint16_t vlanTag,const std::string ifName,const uint8_t vlanPriority);

    ///
    /// @brief This method is used to remove the vlan interface.
    ///
    /// @param[in] vlanName name of the requested vlan interface. e.g. "vlan20" , "eth0.300" ..
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the vlan interface is removed.
    ///              -# false - Error in vlan removal.
    ///
    bool destroyVlan(const std::string vlanName);

    ///
    /// @brief This method is used to notify the interface status changes to other components using Dk message.
    ///
    /// @param[in] interface  Interface name.
    /// @param[in] ipAddress  Interface IP address.
    /// @param[in] linkStatus Interface link status.
    ///                       -# ELinkStatus_Down - Interface link status down.
    ///                       -# ELinkStatus_Up   - Interface link status Up.
    ///
    static void notifyInterfaceChanges(
        const std::string interface,
        const std::string ipAddress,
        const ELinkStatus_t linkStatus
    );

    ///
    /// @brief This method is used to periodically monitor the current status of the physical and virtual interface.
    ///
    void monitorInterfaces(void);

    ///
    /// @brief This method is used to configure the physical and virtual interfaces from the configuration lists.
    ///
    void configureInterfaces(void);

    ///
    /// @brief This method is used to disable ARP support for the interface.
    ///
    /// @param[in] interfaceName name of the requested interface. e.g. "vlan20" , "eth0.300" ..
    ///
    /// @return bool It returns the status of the request.
    ///              -# true - If the vlan interface is removed.
    ///              -# false - Error in vlan removal.
    ///
    bool disableARP(const std::string interfaceName);

};

} // platform
} // srvc
} // dk

#endif // NETWORK_MANAGER_H
