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
#include "diag_app_gp.h"
#include "uds_core_component.h"
#include "eins_uds_appl_component.h"
#include "doip_component.h"
#include "upd_ucl_adapter_component.h"
#include "upd_doip_adapter_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;
using namespace dk::srvc::udscore;
using namespace dk::app::udsblservices;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oUdsCoreComponentMessageMap;
extern std::map<mid_t, func_t> oEinsUdsApplComponentMessageMap;
extern std::map<mid_t, func_t> oDoipComponentMessageMap;
extern std::map<mid_t, func_t> oUpdUclAdapterComponentMessageMap;
extern std::map<mid_t, func_t> oUpdDoipAdapterComponentMessageMap;

//Instantiate Software Components
UdsCoreComponent oUdsCoreComponent(&oUdsCoreComponentMessageMap, COMPID_OUDSCORECOMPONENT_STR);
EinsUdsApplComponent oEinsUdsApplComponent(&oEinsUdsApplComponentMessageMap, COMPID_OEINSUDSAPPLCOMPONENT_STR);
DoipComponent oDoipComponent(&oDoipComponentMessageMap, COMPID_ODOIPCOMPONENT_STR);
UpdUclAdapterComponent oUpdUclAdapterComponent(&oUpdUclAdapterComponentMessageMap, COMPID_OUPDUCLADAPTERCOMPONENT_STR);
UpdDoipAdapterComponent oUpdDoipAdapterComponent(&oUpdDoipAdapterComponentMessageMap, COMPID_OUPDDOIPADAPTERCOMPONENT_STR);

//Define Messages
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

static const uint16_t oEinsUdsApplComponentMessageArraySize = 5U;
const MsgCmn oEinsUdsApplComponentMessageArray[oEinsUdsApplComponentMessageArraySize] =
{
    {
        DK_MSG_UDSTIMEOUT,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UdsTimeout msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.timeoutType);
            ( void ) msgDes.deserialize(msg.clientAddress);
            oEinsUdsApplComponent.onReceiveUdsTimeout(msg);
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
            oEinsUdsApplComponent.onReceiveUdsServiceResponseTransmitConfirmation(msg);
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
            oEinsUdsApplComponent.onReceiveUdsServiceReqIndication(msg);
        }
    },
    {
        DK_MSG_GIPDIAGRESPONSE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            GipDiagResponse msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.sid);
            ( void ) msgDes.deserialize(msg.didId);
            ( void ) msgDes.deserialize(msg.responseCode);
            ( void ) msgDes.deserialize(msg.controlOpLen);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.controlOp[i0]);
            }
            ( void ) msgDes.deserialize(msg.responseLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.response[i0]);
            }
            oEinsUdsApplComponent.onReceiveGipDiagResponse(msg);
        }
    },
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
            oEinsUdsApplComponent.onReceiveDoIPDownloadResponse(msg);
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
std::map<mid_t, func_t> oUdsCoreComponentMessageMap = createMap(oUdsCoreComponentMessageArraySize, oUdsCoreComponentMessageArray);
std::map<mid_t, func_t> oEinsUdsApplComponentMessageMap = createMap(oEinsUdsApplComponentMessageArraySize, oEinsUdsApplComponentMessageArray);
std::map<mid_t, func_t> oDoipComponentMessageMap = createMap(oDoipComponentMessageArraySize, oDoipComponentMessageArray);
std::map<mid_t, func_t> oUpdUclAdapterComponentMessageMap = createMap(oUpdUclAdapterComponentMessageArraySize, oUpdUclAdapterComponentMessageArray);
std::map<mid_t, func_t> oUpdDoipAdapterComponentMessageMap = createMap(oUpdDoipAdapterComponentMessageArraySize, oUpdDoipAdapterComponentMessageArray);

//Instantiate Containter
Container DiagAppGpCon(&oUdsCoreComponent, &oEinsUdsApplComponent, &oDoipComponent, &oUpdUclAdapterComponent, &oUpdDoipAdapterComponent);

//Instantiate Application
diag_app_gp gApp("diag_app_gp", &DiagAppGpCon);

//Instantiate Threads
#define PTH_BODY
#include "diag_app_gp_threads.h"
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
         LOG_REGISTER_APP_SLOG2("DIAG", "DIAG APP");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("DIAG", "DIAG APP");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif

        /// End of user code

        // Register Threads
#define PTH_REG
#include "diag_app_gp_threads.h"
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
