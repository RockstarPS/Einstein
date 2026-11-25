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
// Date: Wed Apr 29 16:50:49 IST 2026
// User: SRAI3
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef UPD_DOIP_ADAPTER_COMPONENT_H
#define UPD_DOIP_ADAPTER_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_upd_doip_adapter_component.h"

typedef enum{
	DoIP_ProgSession = 0x10,
	DoIP_Reset = 0x11,
	DoIP_eraseRoutine = 0xFF00,
    DoIP_downloadService = 0x34,
    DoIP_TransferService = 0x36,
    DoIP_TransferExitService = 0x37,
    DoIP_TesterPresent = 0x3E,
	DoIP_SelfCheck = 0xFF01,
	DoIP_Activation = 0xFE00,
	DoIP_Rollback = 0xFE01,
	DoIP_Partitionsync = 0xFE02
}e_DoIPServiceList;

using namespace dk::runtime;

class UpdDoipAdapterComponent : public dk::runtime::core::Component
{
public:
    explicit UpdDoipAdapterComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~UpdDoipAdapterComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveDoIPDownloadRequest(DoIPDownloadRequest const & msg);

private:
/// Start of user code : User code for file upd_doip_adapter_component.h
	void periodicTask();
	void DoIPTransferHandlingTask(void);
	void DoIP_sendResponse(uint32 Sid, uint8 ErrorCode, uint32 RespLength, uint8* data );
/// End of user code
};



#endif //UPD_DOIP_ADAPTER_COMPONENT_H

