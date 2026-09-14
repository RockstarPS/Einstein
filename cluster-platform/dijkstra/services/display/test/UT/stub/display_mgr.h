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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.0
// Date: Fri Jul 22 12:36:18 IST 2022
// User: SSHANKA8
// System: GIP
// Configuration: Platform
// Project: NISSAN_J32V_IC
// Message Catalogue version : 1.0.33
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DISPLAY_MGR_H
#define DISPLAY_MGR_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
//#include "dk_runtime_types.h"
//#include "display_mgr_thread_ids.h"

using namespace dk::runtime;

class DisplayMgr : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    DisplayMgr(const char * const pAppName, const T1 c, T2... cList) : Application(pAppName)
    {
        addContainer(c, cList...);
    }

    virtual ~DisplayMgr()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendDisplayCurrentState(DisplayCurrentState const & msg);
    void sendPowerReportCompState(PowerReportCompState const & msg);
};

extern DisplayMgr gApp;
#endif //DISPLAY_MGR_H

