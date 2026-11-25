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
#ifndef UPD_UCL_ADAPTER_COMPONENT_H
#define UPD_UCL_ADAPTER_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_upd_ucl_adapter_component.h"
#include "Std_Types.h"

using namespace dk::runtime;

typedef enum{
	Ucl_ProgSession = 0x10,
	Ucl_Reset = 0x11,
	Ucl_eraseRoutine = 0x31,
    Ucl_downloadService = 0x34,
    Ucl_TransferService = 0x36,
    ucl_TransferExitService = 0x37,
    ucl_TesterPresent = 0x3E,
	ucl_SelfCheck = 0xFF,
	ucl_Activation = 0xFE,
	ucl_Partitionsync = 0xFD
}e_UclServiceList;

class UpdUclAdapterComponent : public dk::runtime::core::Component
{
public:
    explicit UpdUclAdapterComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~UpdUclAdapterComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveUpdateShortServiceReq(UpdateShortServiceReq const & msg);

    void onReceiveUpdateLongServiceReq(UpdateLongServiceReq const & msg);

private:
/// Start of user code : User code for file upd_ucl_adapter_component.h
        void periodicTask();

        void UclTransferHandlingTask(void);
        void ucl_sendResponse(uint8 Sid, uint8 ErrorCode, uint16 RespLength, uint8* data );
        uint8 arrayTo32BitValue(const uint8* arr, uint32 &value);
		uint8 CreateSharedMemoryInstance(void);
		uint8 UpdatePartitionStatus(uint8 swPartId, uint8 SwPartStatus);
		uint8 UpdatePartitionVersion(uint8 swPartId);
/// End of user code
};



#endif //UPD_UCL_ADAPTER_COMPONENT_H

