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
/// @file network_packet_filter_if.h
/// @ingroup NetworkManager
///
/// @brief  CNetworkPacketFilterIf Class. CNetworkPacketFilterIf is an interface class. It defines the common interface
///         which should be implemented by the packet filter types(firewall). It is used by the Network Manager to
///         configure and control the firewall.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef NETWORK_PACKET_FILTER_IF_H
#define NETWORK_PACKET_FILTER_IF_H
#include <cstdint>
#include <string>

namespace dk
{
namespace srvc
{
namespace platform
{

class CNetworkPacketFilterIf
{
public:
    ///
    /// @brief It defines the filter status .
    ///
    typedef enum
    {
        EFilterStatus_Disabled = 0, ///< filter is disabled.
        EFilterStatus_Enabled,      ///< filter is enabled.
        EFilterStatus_Last,         ///< Guard.
    } EfilterStatus_t;

    ///
    /// @brief This method is used to enable the filter.
    ///
    virtual void enableFilter(void)=0;

    ///
    /// @brief This method is used to disable the filter.
    ///
    virtual void disableFilter(void)=0;

    ///
    /// @brief This method is used to enable the filter.
    ///
    /// @param configFile file path of the filter configuration file eg: /tmp/pf.conf
    ///
    virtual void setFilterConfiguration(const std::string &configFile) = 0;

    ///
    /// @brief This method is used to current status the filter.
    ///
    /// @return EfilterStatus_t It defines the filter status .
    ///                         EFilterStatus_Disabled  - filter is disabled.
    ///                         EFilterStatus_Enabled   - filter is enabled.
    ///
    virtual CNetworkPacketFilterIf::EfilterStatus_t getFilterStatus(void) const = 0;
};


} // platform
} // srvc
} // dk
#endif  //NETWORK_PACKET_FILTER_IF_H
