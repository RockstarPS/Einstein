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
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "fota_app_gp.h"
#include "upd_ucl_adapter_component.h"
#include "upd_doip_adapter_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oUpdUclAdapterComponentMessageMap;
extern std::map<mid_t, func_t> oUpdDoipAdapterComponentMessageMap;

//Instantiate Software Components
UpdUclAdapterComponent oUpdUclAdapterComponent(&oUpdUclAdapterComponentMessageMap, COMPID_OUPDUCLADAPTERCOMPONENT_STR);
UpdDoipAdapterComponent oUpdDoipAdapterComponent(&oUpdDoipAdapterComponentMessageMap, COMPID_OUPDDOIPADAPTERCOMPONENT_STR);

//Define Messages
static const uint16_t oUpdUclAdapterComponentMessageArraySize = 2U;
const MsgCmn oUpdUclAdapterComponentMessageArray[oUpdUclAdapterComponentMessageArraySize] =
{
    {
        DK_MSG_UPDATESHORTSERVICEREQ,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UpdateShortServiceReq msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.msgId);
            ( void ) msgDes.deserialize(msg.msgSize);
            ( void ) msgDes.deserialize(msg.memoryType);
            ( void ) msgDes.deserialize(msg.memoryCmd);
            ( void ) msgDes.deserialize(msg.sid);
            ( void ) msgDes.deserialize(msg.length);
            for (uint16_t i0 = 0U; i0 < 64U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oUpdUclAdapterComponent.onReceiveUpdateShortServiceReq(msg);
        }
    },
    {
        DK_MSG_UPDATELONGSERVICEREQ,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UpdateLongServiceReq msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.msgId);
            ( void ) msgDes.deserialize(msg.msgSize);
            ( void ) msgDes.deserialize(msg.memoryType);
            ( void ) msgDes.deserialize(msg.memoryCmd);
            ( void ) msgDes.deserialize(msg.sid);
            ( void ) msgDes.deserialize(msg.length);
            for (uint16_t i0 = 0U; i0 < 2048U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oUpdUclAdapterComponent.onReceiveUpdateLongServiceReq(msg);
        }
    }
};

static const uint16_t oUpdDoipAdapterComponentMessageArraySize = 1U;
const MsgCmn oUpdDoipAdapterComponentMessageArray[oUpdDoipAdapterComponentMessageArraySize] =
{
    {
        DK_MSG_DOIPDOWNLOADREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoIPDownloadRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.blkaddress);
            ( void ) msgDes.deserialize(msg.blklength);
            ( void ) msgDes.deserialize(msg.formatId);
            ( void ) msgDes.deserialize(msg.CompEncId);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oUpdDoipAdapterComponent.onReceiveDoIPDownloadRequest(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oUpdUclAdapterComponentMessageMap = createMap(oUpdUclAdapterComponentMessageArraySize, oUpdUclAdapterComponentMessageArray);
std::map<mid_t, func_t> oUpdDoipAdapterComponentMessageMap = createMap(oUpdDoipAdapterComponentMessageArraySize, oUpdDoipAdapterComponentMessageArray);

//Instantiate Containter
Container FotaAppGpCon(&oUpdUclAdapterComponent, &oUpdDoipAdapterComponent);

//Instantiate Application
fota_app_gp gApp("fota_app_gp", &FotaAppGpCon);

//Instantiate Threads
#define PTH_BODY
#include "fota_app_gp_threads.h"
#undef PTH_BODY

void signalHandler(const int32_t signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program
    ( void ) gApp.stop();

    std::exit(signum);
}

/// Start of user code : User code for file main.cpp

/// End of user code

int main()
{
    int32_t l_gApp_ret_S32;
    try
    {
        if (SIG_ERR == std::signal(SIGINT, &signalHandler))
        {
            std::cout << "Failed to create signal handler";
        }

        /// Start of user code : User code for function main in file main.cpp
	       #ifdef __QNX__
         gApp.setWatchdogEnabled(true);
         LOG_REGISTER_APP_SLOG2("FOTA", "FOTA APP");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("FOTA", "FOTA APP");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif

        /// End of user code

        // Register Threads
#define PTH_REG
#include "fota_app_gp_threads.h"
#undef PTH_REG

        l_gApp_ret_S32 = gApp.run();
        LOG_UNREGISTER_CONTEXT ( gRTELogContext );
    }
    catch (...)
    {
        l_gApp_ret_S32 = -1;
        // Handle the exceptions.
    }

    return l_gApp_ret_S32;
}
