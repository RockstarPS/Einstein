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
/// @file network_packet_filter_qnx.h
/// @ingroup NetworkManager
///
/// @brief  CNetworkPacketFilterQnx Class. This class implements the pf(packet filter) control.
///         A pseudo-device, /dev/pf, lets user processes control the behaviour of the packet filter .
///         The pf device is controlled by pfctl binary.Using pfctl enable and disable the filter, load rule sets,
///         add and remove individual rules or state table entries, and retrieve statistics.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef NETWORK_PACKET_FILTER_QNX_H
#define NETWORK_PACKET_FILTER_QNX_H

#include "network_packet_filter_if.h"
#include <cstdint>
#include <string>

namespace dk
{
namespace srvc
{
namespace platform
{

class CNetworkPacketFilterQnx : public CNetworkPacketFilterIf
{
public:
    ///
    /// @brief This method is used to enable the filter.
    ///
    virtual void enableFilter(void);

    ///
    /// @brief This method is used to disable the filter.
    ///
    virtual void disableFilter(void);

    ///
    /// @brief This method is used to enable the filter.
    ///
    /// @param configFile file path of the filter configuration file eg: /tmp/pf.conf
    ///
    virtual void setFilterConfiguration(const std::string &configFile);

    ///
    /// @brief This method is used to current status the filter.
    ///
    /// @return EfilterStatus_t It defines the filter status .
    ///                         EFilterStatus_Disabled  - filter is disabled.
    ///                         EFilterStatus_Enabled   - filter is enabled.
    ///
    virtual CNetworkPacketFilterIf::EfilterStatus_t getFilterStatus(void) const;

    ///
    /// @brief Constructor of CNetworkManager class.
    ///
    CNetworkPacketFilterQnx()
    {
        mfilterStatus = CNetworkPacketFilterIf::EfilterStatus_t::EFilterStatus_Disabled;
    }

    ///
    /// @brief Destructor of CNetworkManager class.
    ///
    ~CNetworkPacketFilterQnx() {}

private:
    ///
    /// @brief
    ///
    CNetworkPacketFilterIf::EfilterStatus_t mfilterStatus;

    ///
    /// @brief
    ///
    std::string mConfigfilePath = "/tmp/pf.conf";

    ///
    /// @brief This method is used to call the pfctl binary to control the pf device.
    ///
    /// @param[in] arglist It is array of argument list to be passed for the pfctl binary.The array should be a null
    ///                    terminated
    ///
    static bool invokePfctl(char *const *const arglist);
};


} // platform
} // srvc
} // dk

#endif  //NETWORK_PACKET_FILTER_QNX_H
