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
// Date: Thu Apr 17 12:47:36 IST 2025
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.4
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef MHMI_COMPONENT_H
#define MHMI_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_mhmi_component.h"



using namespace dk::runtime;

class MHMIComponent : public dk::runtime::core::Component
{
public:
    explicit MHMIComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~MHMIComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveTT_Status(TT_Status const & msg);

    void onReceiveRTT_Status(RTT_Status const & msg);

    void onReceiveFRTT_Status(FRTT_Status const & msg);

    void onReceiveRTT_Toggle(RTT_Toggle const & msg);

    void onReceiveRTT_Icon(RTT_Icon const & msg);

    void onReceiveWarningDisplay(WarningDisplay const & msg);

    void onReceiveWarningExtDisplay(WarningExtDisplay const & msg);

    void onReceiveSlowGaugeInfo(SlowGaugeInfo const & msg);

    void onReceiveShiftPosIndStatus(ShiftPosIndStatus const & msg);

    void onReceiveIlluminationData(IlluminationData const & msg);

private:
/// Start of user code : User code for file mhmi_component.h

/// End of user code
};



#endif //MHMI_COMPONENT_H

