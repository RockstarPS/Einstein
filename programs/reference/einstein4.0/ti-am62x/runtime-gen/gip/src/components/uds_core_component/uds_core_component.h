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
// Date: Fri Oct 31 17:48:26 IST 2025
// User: PSIVAKU7
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform_imported
// Message Catalogue version : 1.0.7
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef UDS_CORE_COMPONENT_H
#define UDS_CORE_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_uds_core_component.h"

namespace dk
{
namespace srvc
{
namespace udscore
{

using namespace dk::runtime;

class UdsCoreComponent : public dk::runtime::core::Component
{
public:
    explicit UdsCoreComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~UdsCoreComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveDoipDiagDataIndication(DoipDiagDataIndication const & msg);

    void onReceiveUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest const & msg);

    void onReceiveDoipDiagDataConfirmation(DoipDiagDataConfirmation const & msg);

    void onReceiveUdsServiceSetTimings(UdsServiceSetTimings const & msg);

private:
/// Start of user code : User code for file uds_core_component.h

/// End of user code
};

} // udscore
} // srvc
} // dk

#endif //UDS_CORE_COMPONENT_H

