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
// Date: Wed Sep 17 12:31:02 IST 2025
// User: SSRINI28
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.6
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "hmi_app.h"
#include "hmi_gauges_component.h"
#include "hmi_warnings_component.h"
#include "hmi_gear_component.h"
#include "hmi_illumination_component.h"
#include "hmi_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oHMIGaugesComponentMessageMap;
extern std::map<mid_t, func_t> oHMIWarningsComponentMessageMap;
extern std::map<mid_t, func_t> oHMIGearComponentMessageMap;
extern std::map<mid_t, func_t> oHMIIlluminationComponentMessageMap;
extern std::map<mid_t, func_t> oHMIComponentMessageMap;

//Instantiate Software Components
HMIGaugesComponent oHMIGaugesComponent(&oHMIGaugesComponentMessageMap, COMPID_OHMIGAUGESCOMPONENT_STR);
HMIWarningsComponent oHMIWarningsComponent(&oHMIWarningsComponentMessageMap, COMPID_OHMIWARNINGSCOMPONENT_STR);
HMIGearComponent oHMIGearComponent(&oHMIGearComponentMessageMap, COMPID_OHMIGEARCOMPONENT_STR);
HMIIlluminationComponent oHMIIlluminationComponent(&oHMIIlluminationComponentMessageMap, COMPID_OHMIILLUMINATIONCOMPONENT_STR);
HMIComponent oHMIComponent(&oHMIComponentMessageMap, COMPID_OHMICOMPONENT_STR);

//Define Messages
static const uint16_t oHMIGaugesComponentMessageArraySize = 2U;
const MsgCmn oHMIGaugesComponentMessageArray[oHMIGaugesComponentMessageArraySize] =
{
    {
        DK_MSG_SLOWGAUGEINFO,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            SlowGaugeInfo msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 2U; i0++)
            {
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].id);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].position);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].digitalData);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].unit);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].dynData);
            }
            oHMIGaugesComponent.onReceiveSlowGaugeInfo(msg);
        }
    },
    {
        DK_MSG_FASTGAUGEINFO,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            FastGaugeInfo msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 3U; i0++)
            {
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].id);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].position);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].digitalData);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].unit);
                ( void ) msgDes.deserialize(msg.gaugeInfo[i0].dynData);
            }
            oHMIGaugesComponent.onReceiveFastGaugeInfo(msg);
        }
    }
};

static const uint16_t oHMIWarningsComponentMessageArraySize = 2U;
const MsgCmn oHMIWarningsComponentMessageArray[oHMIWarningsComponentMessageArraySize] =
{
    {
        DK_MSG_WARNINGDISPLAY,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            WarningDisplay msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.show);
            ( void ) msgDes.deserialize(msg.warningId);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.dynData[i0]);
            }
            oHMIWarningsComponent.onReceiveWarningDisplay(msg);
        }
    },
    {
        DK_MSG_WARNINGEXTDISPLAY,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            WarningExtDisplay msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.show);
            ( void ) msgDes.deserialize(msg.warningId);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.dynData[i0]);
            }
            oHMIWarningsComponent.onReceiveWarningExtDisplay(msg);
        }
    }
};

static const uint16_t oHMIGearComponentMessageArraySize = 1U;
const MsgCmn oHMIGearComponentMessageArray[oHMIGearComponentMessageArraySize] =
{
    {
        DK_MSG_SHIFTPOSINDSTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            ShiftPosIndStatus msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.status.Shift_Ind_Pos);
            ( void ) msgDes.deserialize(msg.status.Shift_Ind_BlinkReq);
            ( void ) msgDes.deserialize(msg.status.Shift_Ind_Up);
            ( void ) msgDes.deserialize(msg.status.Shift_Ind_Down);
            ( void ) msgDes.deserialize(msg.status.Shift_Ind_DisplayDecState);
            ( void ) msgDes.deserialize(msg.status.Shift_Ind_Screen_ShiftType);
            oHMIGearComponent.onReceiveShiftPosIndStatus(msg);
        }
    }
};

static const uint16_t oHMIIlluminationComponentMessageArraySize = 1U;
const MsgCmn oHMIIlluminationComponentMessageArray[oHMIIlluminationComponentMessageArraySize] =
{
    {
        DK_MSG_ILLUMINATIONDATA,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            IlluminationData msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.data);
            ( void ) msgDes.deserialize(msg.dayStep);
            ( void ) msgDes.deserialize(msg.nightStep);
            ( void ) msgDes.deserialize(msg.daynightStatus);
            oHMIIlluminationComponent.onReceiveIlluminationData(msg);
        }
    }
};

static const uint16_t oHMIComponentMessageArraySize = 1U;
const MsgCmn oHMIComponentMessageArray[oHMIComponentMessageArraySize] =
{
    {
        DK_MSG_DISPLAYCURRENTSTATE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DisplayCurrentState msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.displayId);
            ( void ) msgDes.deserialize(msg.state);
            oHMIComponent.onReceiveDisplayCurrentState(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oHMIGaugesComponentMessageMap = createMap(oHMIGaugesComponentMessageArraySize, oHMIGaugesComponentMessageArray);
std::map<mid_t, func_t> oHMIWarningsComponentMessageMap = createMap(oHMIWarningsComponentMessageArraySize, oHMIWarningsComponentMessageArray);
std::map<mid_t, func_t> oHMIGearComponentMessageMap = createMap(oHMIGearComponentMessageArraySize, oHMIGearComponentMessageArray);
std::map<mid_t, func_t> oHMIIlluminationComponentMessageMap = createMap(oHMIIlluminationComponentMessageArraySize, oHMIIlluminationComponentMessageArray);
std::map<mid_t, func_t> oHMIComponentMessageMap = createMap(oHMIComponentMessageArraySize, oHMIComponentMessageArray);

//Instantiate Containter
Container HmiAppCon(&oHMIGaugesComponent, &oHMIWarningsComponent, &oHMIGearComponent, &oHMIIlluminationComponent, &oHMIComponent);

//Instantiate Application
HMIApp gApp("HMIApp", &HmiAppCon);

//Instantiate Threads
#define PTH_BODY
#include "hmi_app_threads.h"
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
         LOG_REGISTER_APP_SLOG2("HMIA", "HMI Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("HMIA", "HMI Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif
        /// End of user code

        // Register Threads
#define PTH_REG
#include "hmi_app_threads.h"
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
