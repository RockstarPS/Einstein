//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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

#ifndef DK_RUNTIME_IPCMSGIF_H
#define DK_RUNTIME_IPCMSGIF_H

#include <iostream>
#include "dk_runtime_version.h"

#ifdef DK_VMF_ENABLED
#include "nw_vmf.h"
#include "os_types.h"
    #define DK_MSG_MAX_PAYLOAD_LEN  MAX_VMF_DATA_LEN
#else

    #define DK_MSG_MAX_PAYLOAD_LEN  4096U
    #define MAX_GROUP_NUM 255U
#endif

namespace dk
{
namespace runtime
{
namespace core
{
class IpcMsgIf
{
    public:
        IpcMsgIf();
        ~IpcMsgIf();
        bool connect ( const char *pProcessName, int32_t taskId );
        void disconnect();
        bool subscribe ( uint8_t *groupIdArray, uint8_t numGroups );
        bool send ( uint8_t groupId, uint8_t eventId, uint8_t *pPayload, uint16_t size );
        bool receive ( uint8_t &groupId, uint8_t &eventId, uint8_t *pPayload, uint16_t &size );
        uint16_t getMaxPayloadSize()
        {
            return DK_MSG_MAX_PAYLOAD_LEN;
        }

    protected:
    private:
#ifdef DK_VMF_ENABLED
        vmf_client_id_t mVmfClientId = 0;
#endif
};
}
}
}

#endif //DK_RUNTIME_IPCMSGIF_H
