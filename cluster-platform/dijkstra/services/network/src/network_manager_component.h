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
#ifndef NETWORK_MANAGER_COMPONENT_H
#define NETWORK_MANAGER_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_network_manager_component.h"
#ifdef ENET_PHY_TC812
#include "network_manager_enet_register.h"
#endif
#include "network_manager.h"
#ifdef ENET_PHY_TJA1101
#include "network_manager_tja1101.h"
#endif


namespace dk
{
namespace srvc
{
namespace platform
{


using namespace dk::runtime;

class NetworkManagerComponent : public dk::runtime::core::Component
{
public:
    explicit NetworkManagerComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~NetworkManagerComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    static void worker(void);



    void onReceiveNetworkModifyLinkStatus(NetworkModifyLinkStatus const & msg);


    void onReceiveNetworkModifyVlanInterface(NetworkModifyVlanInterface const & msg);

    void onReceiveNetworkModifyInterface(NetworkModifyInterface const & msg);
#ifdef ENET_PHY_TC812
    void onReceiveNetworkRequestLinkState(NetworkRequestLinkState const & msg);
#endif

    void onReceiveEnetRegReq(EnetRegReq const  & msg);

    void onReceiveNetworkModifyFirewallStatus(NetworkModifyFirewallStatus const & msg);

private:

    ///
    /// @brief This is the period of  Network Manager's periodic function in milliseconds.
    ///
    uint32_t mPeriodicTaskTimeInMs = 300U;

    ///
    /// @brief Instance of network manager.
    ///
    CNetworkManager mNetworkManagerInst;

    ///
    /// @brief This method is used to invoke the CNetworkManager periodic task.This method is registered in onInit
    ///        method the configurable time.
    ///
    void networkManagerPeriodicTask();


/// End of user code
};


}
}
}

#endif //NETWORK_MANAGER_COMPONENT_H

