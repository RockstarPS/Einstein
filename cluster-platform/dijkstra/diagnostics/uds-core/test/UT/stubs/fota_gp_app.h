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
// Date: Mon Nov 22 09:41:40 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef FOTA_GP_APP_H
#define FOTA_GP_APP_H

#include "dk_logger.h"
#include "dk_runtime_application.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_types.h"
#include "fota_gp_app_thread_ids.h"

using namespace dk::runtime;

class FotaGpApp : public dk::runtime::core::Application
{
public:
    template <typename T1 = dk::runtime::core::Container *, typename... T2>
    FotaGpApp(const char * const pAppName, const T1 c, T2... cList) : Application(pAppName)
    {
        //addContainer(c, cList...);
    }

    virtual ~FotaGpApp()
    {
    }

    virtual bool onInit() override;
    virtual bool onExit() override;
    virtual bool onStart() override;
    virtual bool onStop() override;
    virtual int32_t onRun() override;

    //Send APIs
    void sendUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest const & msg);
    void sendUdsServiceSetTimings(UdsServiceSetTimings const & msg);
    void sendDoipDiagPowerModeStatus(DoipDiagPowerModeStatus const & msg);
    void sendUdsCurrentMode(UdsCurrentMode const & msg);
    void sendUdsCurrentSession(UdsCurrentSession const & msg);
    void sendUdsInstallerFileDownloadStatus(UdsInstallerFileDownloadStatus const & msg);
    void sendUdsInstallerDidRequest(UdsInstallerDidRequest const & msg);
    void sendUdsDidPostResponseIndication(UdsDidPostResponseIndication const & msg);
    void sendSwUpdateResponse(SwUpdateResponse const & msg);
    void sendFotaChangeResponse(FotaChangeResponse const & msg);
    void sendFotaVersionNotify(FotaVersionNotify const & msg);
    void sendFotaCommandResponse(FotaCommandResponse const & msg);
    void sendFotaVinRequest(FotaVinRequest const & msg);
    void sendFotaStateRequest(FotaStateRequest const & msg);
    void sendFotaStateNotify(FotaStateNotify const & msg);
    void sendNetworkModifyVlanInterface(NetworkModifyVlanInterface const & msg);
    void sendNetworkModifyInterface(NetworkModifyInterface const & msg);
    void sendDoipSetParams(DoipSetParams const & msg);
    void sendUdsInstallerDidResponse(UdsInstallerDidResponse const & msg);
    void sendUdsFotaState(UdsFotaState const & msg);
    void sendFotaCorrelationID(FotaCorrelationID const & msg);
    void sendFotaMemCtrlRespData(FotaMemCtrlRespData const & msg);
    void sendMemDiagRespData(MemDiagRespData const & msg);
    void sendDoipDiagDataIndication(DoipDiagDataIndication const & msg);
    void sendDoipDiagDataConfirmation(DoipDiagDataConfirmation const & msg);
    void sendUdsTimeout(UdsTimeout const & msg);
    void sendUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation const & msg);
    void sendDoipDiagDataTransferRequest(DoipDiagDataTransferRequest const & msg);
    void sendUdsServiceReqIndication(UdsServiceReqIndication const & msg);
    void sendUdsTimeout_DTool(UdsTimeout const & msg);
    void sendUdsServiceResponseTransmitConfirmation_DTool(UdsServiceResponseTransmitConfirmation const & msg);
    void sendDoipDiagDataTransferRequest_DTool(DoipDiagDataTransferRequest const & msg);
    void sendUdsServiceReqIndication_DTool(UdsServiceReqIndication const & msg);
    void sendGipDiagDIDRequest(GipDiagDIDRequest const & msg);
    void sendGipDiagRoutineRequest(GipDiagRoutineRequest const & msg);
    void sendGipDiagIOCtrlRequest(GipDiagIOCtrlRequest const & msg);
    void sendTrngReq(TrngReq const & msg);
    void sendGIPUdsDiagMode(GIPUdsDiagMode const & msg);
};

extern FotaGpApp gApp;
#endif //FOTA_GP_APP_H

