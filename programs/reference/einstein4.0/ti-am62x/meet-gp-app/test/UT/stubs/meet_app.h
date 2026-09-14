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
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Tue Mar 04 16:20:30 IST 2025
// User: AANITHA
// System: GIP
// Configuration: Platform
// Project: EU_BMW_MIC
// Message Catalogue version : 1.0.20
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef MEET_APP_H
#define MEET_APP_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_types.h"
#include "meet_app_thread_ids.h"

using namespace dk::runtime;

class MeetApp : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    MeetApp(const char * const pAppName, const T1 c, T2... cList) : Application(pAppName)
    {
        //addContainer(c, cList...);
    }

    virtual ~MeetApp()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendDiagResponse(DiagResponse const & msg);
    void sendMeetGNSSRequest(MeetGNSSRequest const & msg);
};

extern MeetApp gApp;
#endif //MEET_APP_H

