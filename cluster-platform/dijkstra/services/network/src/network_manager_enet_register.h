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

#include <utility>
#include <vector>
#include <map>
#include <cstdint>
#include <ethernet_register_read_write.h>
#include "dk_runtime_network_manager_component.h"
#ifndef NETWORK_MANAGER_ENET_REGISTER_H_
#define NETWORK_MANAGER_ENET_REGISTER_H_


namespace dk
{
namespace srvc
{
namespace platform
{


class CNetworkPhyEnet
{
public:
    ///
    /// @brief It defines the link status of the interface.
    ///


    ///
    /// @brief Constructor of CNetworkPhyEnet class.
    ///
    CNetworkPhyEnet() {}

    ///
    /// @brief Destructor of CNetworkPhyEnet class.
    ///
    ~CNetworkPhyEnet() {}

    ///
    /// @brief CNetworkPhyEnet polls the UCL task
    ///
    void pollPhyEnetStatusInMs(void);

    ENETregisterClass mENETregisterClass;
    uint8_t mlinkStatus = ELinkStatus_Down;

    ///
    /// @brief   Read UCL link status
    ///
    void readPhyLinkStatus(void);

    ///
    /// @brief   Request handler to  compute Enet based requests.
    ///
    static uint16_t enetReqHandler(EnetRegReq const  & msg);

    //Tdr
    static void TdrProcedure(void);
private:

    bool bTDRProcedRunStatus = false;

    ///
    /// @brief   Read Cable quality
    ///
    void readCableQuality(void);

    ///
    /// @brief   Read Signal quality
    ///
    static uint16_t createMask(const uint16_t left, const uint16_t right );
    ///
    /// @brief  Enable ethernet test modes
    ///
    static void enableEthTestModes(EnetRegReq const  & msg );
    ///
    /// @brief  Enable ethernet
    ///
    static void enableEthernet(void );
    ///
    /// @brief  disable ethernet
    ///
    static void disableEthernet(void );
};

}
}
}

#endif
