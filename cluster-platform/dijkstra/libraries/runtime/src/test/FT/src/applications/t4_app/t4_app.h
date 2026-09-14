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
// Date: Sun Nov 01 21:09:51 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef T4_APP_H
#define T4_APP_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_types.h"
#include "t4_app_thread_ids.h"

using namespace dk::runtime;

class T4App : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    T4App(const char *pAppName, T1 c, T2... cList) : Application(pAppName)
    {
        addContainer(c, cList...);
    }

    ~T4App()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendDkMsgT4Con1Comp1P(DkMsg1byte_t & msg);
    void sendDkMsgT4Con1comp1Tx(DkMsg1byte_t & msg);
    void sendDkMsgT4Con1Comp2P(DkMsg1byte_t & msg);
    void sendDkMsgT4Con1Comp2Tx(DkMsg1byte_t & msg);
    void sendDkMsgT4Con2Comp1P(DkMsg1byte_t & msg);
    void sendDkMsgT4Con2Comp2P(DkMsg1byte_t & msg);
};

extern T4App gApp;
#endif //T4_APP_H

