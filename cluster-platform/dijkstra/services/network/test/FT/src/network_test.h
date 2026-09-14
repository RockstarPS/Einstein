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
#ifndef NETWORKIF_H
#define NETWORKIF_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_types.h"
#include "network_test_thread_ids.h"

#define COMPID_ONETWORKIFAPPCOMPONENTTEST_STR ("OTEST_NET")

#define COMPID_ONETWORKIFAPPCOMPONENTTEST         ((uint8_t)0x24U)

#define COMPID_ONETWORKIFAPPCOMPONENTTEST_DESC    ("")


using namespace dk::runtime;

class networkif : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    networkif(const char * const pAppName, const T1 c, T2... cList) : Application(pAppName)
    {
        addContainer(c, cList...);
    }

    virtual ~networkif()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendNetworkModifyInterface(NetworkModifyInterface const &msg);

    void sendNetworkModifyVlanInterface(NetworkModifyVlanInterface const &msg);

    void sendNetworkModifyLinkStatus(NetworkModifyLinkStatus const &msg);

    void sendEnetRegReq(EnetRegReq const &msg);

    //test case variable
    uint8_t test_case = 0;

};

extern networkif gApp;
#endif //NETWORKIF_H

