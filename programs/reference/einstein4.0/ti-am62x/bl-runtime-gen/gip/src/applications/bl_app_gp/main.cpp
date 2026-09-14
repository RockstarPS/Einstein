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
// Date: Fri May 15 11:55:46 IST 2026
// User: GSOUNDAR
// System: GIP
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "bl_app_gp.h"
#include "bl_einstein_uds_app_component.h"
#include "bl_upd_doip_adapter_component.h"
#include "bl_upd_ucl_adapter_component.h"
#include "uds_core_component.h"
#include "doip_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;
using namespace dk::srvc::udscore;
using namespace dk::app::udsblservices;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oBlEinsteinUdsAppComponentMessageMap;
extern std::map<mid_t, func_t> oBlUpdDoipAdapterComponentMessageMap;
extern std::map<mid_t, func_t> oBlUpdUclAdapterComponentMessageMap;
extern std::map<mid_t, func_t> oUdsCoreComponentMessageMap;
extern std::map<mid_t, func_t> oDoipComponentMessageMap;

//Instantiate Software Components
BlEinsteinUdsAppComponent oBlEinsteinUdsAppComponent(&oBlEinsteinUdsAppComponentMessageMap, COMPID_OBLEINSTEINUDSAPPCOMPONENT_STR);
BlUpdDoipAdapterComponent oBlUpdDoipAdapterComponent(&oBlUpdDoipAdapterComponentMessageMap, COMPID_OBLUPDDOIPADAPTERCOMPONENT_STR);
BlUpdUclAdapterComponent oBlUpdUclAdapterComponent(&oBlUpdUclAdapterComponentMessageMap, COMPID_OBLUPDUCLADAPTERCOMPONENT_STR);
UdsCoreComponent oUdsCoreComponent(&oUdsCoreComponentMessageMap, COMPID_OUDSCORECOMPONENT_STR);
DoipComponent oDoipComponent(&oDoipComponentMessageMap, COMPID_ODOIPCOMPONENT_STR);

//Define Messages
static const uint16_t oBlEinsteinUdsAppComponentMessageArraySize = 4U;
const MsgCmn oBlEinsteinUdsAppComponentMessageArray[oBlEinsteinUdsAppComponentMessageArraySize] =
{
    {
        DK_MSG_DOIPDOWNLOADRESPONSE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoIPDownloadResponse msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            ( void ) msgDes.deserialize(msg.result);
            oBlEinsteinUdsAppComponent.onReceiveDoIPDownloadResponse(msg);
        }
    },
    {
        DK_MSG_UDSSERVICERESPONSETRANSMITCONFIRMATION,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsServiceResponseTransmitConfirmation msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.responseType);
            ( void ) msgDes.deserialize(msg.clientAddress);
            oBlEinsteinUdsAppComponent.onReceiveUdsServiceResponseTransmitConfirmation(msg);
        }
    },
    {
        DK_MSG_UDSSERVICEREQINDICATION,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsServiceReqIndication msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.requestType);
            ( void ) msgDes.deserialize(msg.clientAddress);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oBlEinsteinUdsAppComponent.onReceiveUdsServiceReqIndication(msg);
        }
    },
    {
        DK_MSG_UDSTIMEOUT,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsTimeout msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.timeoutType);
            ( void ) msgDes.deserialize(msg.clientAddress);
            oBlEinsteinUdsAppComponent.onReceiveUdsTimeout(msg);
        }
    }
};

static const uint16_t oBlUpdDoipAdapterComponentMessageArraySize = 1U;
const MsgCmn oBlUpdDoipAdapterComponentMessageArray[oBlUpdDoipAdapterComponentMessageArraySize] =
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
            oBlUpdDoipAdapterComponent.onReceiveDoIPDownloadRequest(msg);
        }
    }
};

static const uint16_t oBlUpdUclAdapterComponentMessageArraySize = 2U;
const MsgCmn oBlUpdUclAdapterComponentMessageArray[oBlUpdUclAdapterComponentMessageArraySize] =
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
            oBlUpdUclAdapterComponent.onReceiveUpdateShortServiceReq(msg);
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
            oBlUpdUclAdapterComponent.onReceiveUpdateLongServiceReq(msg);
        }
    }
};

static const uint16_t oUdsCoreComponentMessageArraySize = 4U;
const MsgCmn oUdsCoreComponentMessageArray[oUdsCoreComponentMessageArraySize] =
{
    {
        DK_MSG_DOIPDIAGDATAINDICATION,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoipDiagDataIndication msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.sourceAddress);
            ( void ) msgDes.deserialize(msg.targetAddress);
            ( void ) msgDes.deserialize(msg.targetAddressType);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            ( void ) msgDes.deserialize(msg.result);
            oUdsCoreComponent.onReceiveDoipDiagDataIndication(msg);
        }
    },
    {
        DK_MSG_UDSSERVICERESPONSETRANSMITREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsServiceResponseTransmitRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.responseType);
            ( void ) msgDes.deserialize(msg.clientAddress);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oUdsCoreComponent.onReceiveUdsServiceResponseTransmitRequest(msg);
        }
    },
    {
        DK_MSG_DOIPDIAGDATACONFIRMATION,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoipDiagDataConfirmation msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.targetAddress);
            ( void ) msgDes.deserialize(msg.sourceAddress);
            ( void ) msgDes.deserialize(msg.targetAddressType);
            ( void ) msgDes.deserialize(msg.result);
            oUdsCoreComponent.onReceiveDoipDiagDataConfirmation(msg);
        }
    },
    {
        DK_MSG_UDSSERVICESETTIMINGS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsServiceSetTimings msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.p2TimeMs);
            ( void ) msgDes.deserialize(msg.p2StarTimeMs);
            ( void ) msgDes.deserialize(msg.p4TimeMs);
            oUdsCoreComponent.onReceiveUdsServiceSetTimings(msg);
        }
    }
};

static const uint16_t oDoipComponentMessageArraySize = 3U;
const MsgCmn oDoipComponentMessageArray[oDoipComponentMessageArraySize] =
{
    {
        DK_MSG_DOIPSETPARAMS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoipSetParams msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.isVinNumValid);
            ( void ) msgDes.deserialize(msg.isGidNumValid);
            ( void ) msgDes.deserialize(msg.isEidNumValid);
            for (uint16_t i0 = 0U; i0 < 17U; i0++)
            {
                ( void ) msgDes.deserialize(msg.vinNumber[i0]);
            }
            for (uint16_t i0 = 0U; i0 < 6U; i0++)
            {
                ( void ) msgDes.deserialize(msg.eidNumber[i0]);
            }
            for (uint16_t i0 = 0U; i0 < 6U; i0++)
            {
                ( void ) msgDes.deserialize(msg.gidNumber[i0]);
            }
            ( void ) msgDes.deserialize(msg.ipConfig.ipAddressNetwork1);
            ( void ) msgDes.deserialize(msg.ipConfig.ipAddressNetwork2);
            ( void ) msgDes.deserialize(msg.ipConfig.ipAddressHost1);
            ( void ) msgDes.deserialize(msg.ipConfig.ipAddressHost2);
            ( void ) msgDes.deserialize(msg.ipConfig.portNum);
            ( void ) msgDes.deserialize(msg.isNetWorkConfigValid);
            ( void ) msgDes.deserialize(msg.gidSyncStatus);
            ( void ) msgDes.deserialize(msg.isGidSyncStatusValid);
            oDoipComponent.onReceiveDoipSetParams(msg);
        }
    },
    {
        DK_MSG_DOIPDIAGDATATRANSFERREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoipDiagDataTransferRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.sourceAddress);
            ( void ) msgDes.deserialize(msg.targetAddress);
            ( void ) msgDes.deserialize(msg.targetAddressType);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 7168U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            ( void ) msgDes.deserialize(msg.result);
            oDoipComponent.onReceiveDoipDiagDataTransferRequest(msg);
        }
    },
    {
        DK_MSG_DOIPDIAGPOWERMODESTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DoipDiagPowerModeStatus msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.powerMode);
            oDoipComponent.onReceiveDoipDiagPowerModeStatus(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oBlEinsteinUdsAppComponentMessageMap = createMap(oBlEinsteinUdsAppComponentMessageArraySize, oBlEinsteinUdsAppComponentMessageArray);
std::map<mid_t, func_t> oBlUpdDoipAdapterComponentMessageMap = createMap(oBlUpdDoipAdapterComponentMessageArraySize, oBlUpdDoipAdapterComponentMessageArray);
std::map<mid_t, func_t> oBlUpdUclAdapterComponentMessageMap = createMap(oBlUpdUclAdapterComponentMessageArraySize, oBlUpdUclAdapterComponentMessageArray);
std::map<mid_t, func_t> oUdsCoreComponentMessageMap = createMap(oUdsCoreComponentMessageArraySize, oUdsCoreComponentMessageArray);
std::map<mid_t, func_t> oDoipComponentMessageMap = createMap(oDoipComponentMessageArraySize, oDoipComponentMessageArray);

//Instantiate Containter
Container BlAppGpCon(&oBlEinsteinUdsAppComponent, &oBlUpdDoipAdapterComponent, &oBlUpdUclAdapterComponent, &oUdsCoreComponent, &oDoipComponent);

//Instantiate Application
bl_app_gp gApp("bl_app_gp", &BlAppGpCon);

//Instantiate Threads
#define PTH_BODY
#include "bl_app_gp_threads.h"
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

        /// End of user code

        // Register Threads
#define PTH_REG
#include "bl_app_gp_threads.h"
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
