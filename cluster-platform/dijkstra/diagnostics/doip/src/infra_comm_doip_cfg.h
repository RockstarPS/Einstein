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
#ifndef INFRA_COMM_DOIP_CFG_H
#define INFRA_COMM_DOIP_CFG_H

#include <stdint.h>
#include<vector>
//---------------------------------------------------------------------------------------------------------------------
//   Public Macro definitions
//---------------------------------------------------------------------------------------------------------------------

/// @brief DoIP Alive Check timer timeout value (Configurable).
#define  DOIP_ALIVECHECK_RESPONSE_TIMEOUT           1000UL
/// @brief DoIP General Activity timer timeout value (Configurable).
#define  DOIP_GENERAL_INACTIVITY_TIMEOUT            50000UL
/// @brief DoIP Initial Inactivity timer timeout value (Configurable).
#define  DOIP_INITIAL_ACTIVITY_TIMEOUT              50000UL
#define  DOIP_VEHICLE_ANNOUNCE_WAIT_TIMEOUT         50UL
#define  DOIP_VEHICLE_ANNOUNCE_INTERVAL_TIMEOUT     50UL
#define  DOIP_CONTROL_UDP_TIMEOUT                   2000UL
/// @brief DoIP Routing activation type Default (Configurable).
/// @param 0 Default Type
#define  DOIP_ROUTING_ACTIVATION_TYPE               0U
/// @brief DoIP Authentication required for Routing Activation (Configurable).
/// @param 0 Authentication Not required
/// @param 1 Authentication required
#define  DOIP_AUTHENTICATION_REQUIRED               0U
/// @brief DoIP Confirmation required for Routing Activation (Configurable).
/// @param 0 Confirmation Not required
/// @param 1 Confirmation required
#define  DOIP_CONFIRMATION_REQUIRED                 0U
#define  DOIP_NO_OF_CONCUR_SRCADDR_TOBE_SUPPORTED   0U
/// @brief DoIP Routing Activation required or not (Configurable).
/// @param 0 Routing Activation Not required
/// @param 1 Routing Activation required
#define  DOIP_ROUTING_ACTIVATION_REQUIRED           0U
/// @brief DoIP Alive Check required (Configurable).
/// @param 0 Alive Check Not required.
/// @param 1 Alive Check required if more than one tester.
#define  DOIP_ALIVE_CHECK_REQUIRED                  1U
/// @brief DoIP Target Address type physical
#define  DOIP_TATYPE_PHYSICAL                       0U
/// @brief DoIP Target Address type Functional
#define  DOIP_TATYPE_FUNCTIONAL                     1U
/// @brief DoIP Periodic Task timer
#define  DOIP_COMPONENT_PERIODIC_TIMER_IN_MS        10UL
/// @brief DoIP Periodic Task timer
#define  DOIP_PERIODIC_TIMER_IN_MS                  10UL
/// @brief DoIP Number of Target Address (Including Functional Logical And Physical logical address)
#define  DOIP_NUM_TARGET_ADDRESS                    4U
/// @brief DoIP Number of source addresses(Configurable).
///        (which denotes number of Tester can connect with the Node)
#define  DOIP_NUM_SOURCE_ADDRESS                    1U
#define  DOIP_NUM_VLAN                              1U
/// @brief DoIP Target Physical Logical address (Configurable).
#define  DOIP_TARGET_ADDRESS_PHYSICAL               0xE000U
/// @brief DoIP Target Physical Functional address (Configurable).
#define  DOIP_TARGET_ADDRESS_FUNCTIONAL             0xE401U
/// @brief DoIP Source address (Configurable).
#define  DOIP_SOURCE_ADDRESS                        0xE001U
/// @brief DOIP Port Number
#define  PORT_NUM                                    13400
/// @brief IP addres network
#define  IP_ADDRESS_NETWORK_1                        0
#define  IP_ADDRESS_NETWORK_2                        0
/// @brief IP addres host
#define  IP_ADDRESS_HOST_1                           0
#define  IP_ADDRESS_HOST_2                           0
/// @brief Protocol whicn needed for Dignostic Message over IP
/// @param 0  DOIP - Routing Activation, Alive check Response, should be required
/// @param 1  UDSOnIP Routing Activation, Alive check Response, not required. But DOIP header format should be supported.
/// @param 2  Custom Protocol - DOIP Header format Not required. The data Format over IP willbe differe based on OEM's Requirements.
#define    DIAG_OVER_IP_PROTOCOL              2U


struct SDoIPConfig_t
{
    uint32_t        doIpAliveCheckresponseTimeMs;                   ///< DoIP Alive Check response Timer
    uint32_t        doIpGenericInactiveTimeMs;                      ///< DoIP Generic Inactivity Timer
    uint32_t        doIpInitialInactiveTimeMs;                      ///< DoIP Initial Inactivity Timer
    uint32_t        doIpVehicleAnnounceWaitTimeMs;
    uint32_t        doIpVehicleAnnounceIntervalTimeMs;
    std::vector<uint16_t> doIpSourceAddress;                        ///< Source Address
    uint16_t        doIpTargetAddressePhysical;                     ///< DoIP Target Address Physical
    std::vector<uint16_t> doIpTargetAddressesFunctional;            ///< Target Address Functional
    uint8_t         doIpVlanCount;                                  ///< Number of Vlans to be supported
    uint8_t         doIpConcurrentSrcAddrSupportCnt;                     ///< No.of concurrent source address need to be supported
    uint8_t         doIpSourceAddressCount;                         ///< DoIP source Address    count
    uint8_t         doIpTargetAddressCount;                         ///< DoIP Target Address    count
    uint8_t         doIpActivationNumber;                           ///< DoIP Routing Activation Numbers
    uint8_t         diagOverIPProtocol;                             ///< Ethernet data header format
    bool            doIpRoutingActivationRequired;                  ///< DoIP Routing activation required
    bool            doIpAliveCheckRequired;                         ///< DoIP Alive Check  required
    bool            doIpAuthenticationRequired;                     ///< DoIP Authentication required
    bool            doIpConfirmationRequired;                       ///< DoIP Confirmation required
};

struct SNetworkInfo_t
{
    uint16_t        portNum ;                                       ///<    port Number
    uint8_t         ipAddressNetwork1   ;                           ///<    IP address Network part 1
    uint8_t         ipAddressNetwork2   ;                           ///<    IP address Network part 2
    uint8_t         ipAddressHost1  ;                               ///<    IP address Host part 1
    uint8_t         ipAddressHost2  ;                               ///<    IP address Host part 2
};

struct SVehicleInfo_t
{
    std::vector<uint8_t> vin    ;                                       ///<    VehicleIdentification number
    std::vector<uint8_t> gid    ;                                       ///<    GroupId
    std::vector<uint8_t> eid    ;                                       ///<    DOIP Entity ID
};

#endif // end of INFRA_COMM_DOIP_MAIN_CFG_H

