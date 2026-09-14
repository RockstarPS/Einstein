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
// Date: Thu Mar 12 18:15:54 IST 2026
// User: KRAMESH5
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DIAG_APP_GP_H
#define DIAG_APP_GP_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_types.h"
#include "diag_app_gp_thread_ids.h"

using namespace dk::runtime;

class diag_app_gp : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    diag_app_gp(const char * const pAppName, const T1 c, T2... cList) : Application(pAppName)
    {
        addContainer(c, cList...);
    }

    virtual ~diag_app_gp()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendDoipDiagDataTransferRequest(DoipDiagDataTransferRequest const & msg);
    void sendUdsTimeout(UdsTimeout const & msg);
    void sendUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation const & msg);
    void sendUdsServiceReqIndication(UdsServiceReqIndication const & msg);
    void sendDoipSetParams(DoipSetParams const & msg);
    void sendDoipDiagPowerModeStatus(DoipDiagPowerModeStatus const & msg);
    void sendUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest const & msg);
    void sendUdsServiceSetTimings(UdsServiceSetTimings const & msg);
    void sendGipDiagRequest(GipDiagRequest const & msg);
    void sendDoIPDownloadRequest(DoIPDownloadRequest const & msg);
    void sendDoipDiagDataIndication(DoipDiagDataIndication const & msg);
    void sendDoipDiagDataConfirmation(DoipDiagDataConfirmation const & msg);
    void sendUpdateShortServiceResp(UpdateShortServiceResp const & msg);
    void sendDoIPDownloadResponse(DoIPDownloadResponse const & msg);
};

extern diag_app_gp gApp;
#endif //DIAG_APP_GP_H

