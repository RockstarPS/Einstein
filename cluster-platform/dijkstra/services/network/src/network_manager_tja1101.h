//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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

#include <utility>
#include <vector>
#include <map>
#include <ethernet_register_read_write.h>
#include "dk_runtime_network_manager_component.h"

#ifndef CLUSTER_PLATFORM_DIJKSTRA_SERVICES_NETWORK_SRC_NETWORK_MANAGER_TJA1101_H_
#define CLUSTER_PLATFORM_DIJKSTRA_SERVICES_NETWORK_SRC_NETWORK_MANAGER_TJA1101_H_

namespace dk
{
namespace srvc
{
namespace platform
{
class CNetworkPhyEnetTja1101
{
public:

    ///
    /// @brief Constructor of CNetworkPhyEnetTja1101 class.
    ///
    CNetworkPhyEnetTja1101() {}

    ///
    /// @brief Destructor of CNetworkPhyEnetTja1101 class.
    ///
    ~CNetworkPhyEnetTja1101() {}

    ENETregisterClass mENETregisterTJA1101Class;

    void pollPhyEnetStatusInMs(void);

    void enetReqHandler(EnetRegReq const  & msg);

private:
    void readPhyLinkStatus(void);
    void readCableQuality(void);
    void readSQIvalue(void);
    bool runTDRprocedure(const bool enable);
    void getLinkStatus(void);
    void getSqiCurrentValue(void);
    void getSqiWorstValue(void);
    void getSqiBestValue(void);
    void getResetStatus(void);
    void getFaultStatus(void);
    static void writeResetStatus(void);
    void getMasterSlaveStatus(void);

    uint8_t mLinkStatus = ELinkStatus_Down;
    uint8_t mFault = 0U;
    uint8_t mFaultStatus = 0U;
    uint8_t mCurrentSQI = 0U;
    uint8_t mBestSQI = 0U;
    uint8_t mWorstSQI = 7U;
};

}
}
}




#endif /* CLUSTER_PLATFORM_DIJKSTRA_SERVICES_NETWORK_SRC_NETWORK_MANAGER_TJA1101_H_ */
