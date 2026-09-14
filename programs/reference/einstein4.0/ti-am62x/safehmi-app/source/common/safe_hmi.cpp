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
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "safe_hmi.h"
#include "shmi_component.h"

#ifdef __LINUX__
#if defined BOOT_KPI_LOG_EN
#include "boot_kpi_a53_linux.h"
#endif
#include <stdlib.h>
#include <cstdlib>
#include <sys/mman.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "ux_shmi_uimain.h"
#include "ux_safehmi_player.h"
#include "ux_safehmi_drm_render.h"

#else
#include <windows.h>
#include "stdafx.h"
#include "ux_shmi_uimain.h"
#include "ux_safehmi_player.h"
#include "ux_safehmi_image.h"
#include "ux_safehmi_gl20_render.h"
#include <time.h>
#endif

using namespace UX_SHMI_PLAYER;
using namespace dk::runtime::core;

extern SHMIComponent oSHMIComponent;

bool SafeHMI::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "SafeHMI::onInit");
    return true;
}

bool SafeHMI::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "SafeHMI::onExit");
    return true;
}

bool SafeHMI::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "SafeHMI::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_SafeHMICon_runMessagePump);
    return true;
}

bool SafeHMI::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "SafeHMI::onStop");
    threads.stop(TID_SafeHMICon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t SafeHMI::onRun()
{
    shmi_qnx_disp_info disp_info;
#if defined(__linux__) && defined (__aarch64__)
  disp_info.display_type = 0;
  disp_info.display_id = 11;
  disp_info.zorder = 255;
  disp_info.pipeline = 42;
  UX_SHMI_PLAYER::ux_safehmi_drm_render gr;  
#else
  disp_info.display_type = -1;  
  disp_info.display_id = display;
  disp_info.zorder = zorder;
  disp_info.pipeline = pipeline;
  UX_SHMI_PLAYER::ux_safehmi_gl20_render gr;
#endif    
    SafeHMIInterface *obj_SafeHMIInterface = SafeHMIInterface::getInstance();
	uint8_t fl_power_state = obj_SafeHMIInterface->GetPowerState();
    printf("Safe hmi: setting display:%d pipeline=%d zorder =%d\n",disp_info.display_id, disp_info.pipeline, disp_info.zorder);
    UX_SHMI_PLAYER::ux_safehmi_player safehmi_player(&ui_main, static_cast<UX_SHMI_PLAYER::ux_safehmi_renderer*>(&gr), disp_info);

    ( void ) Application::onRun();
    LOGV(nullptr, "SafeHMI::onRun");
    ( void ) mWdgIf.start(1000U);
    sendSHmiReady(SHMI_READY);
    while (getIsRunning())
    {
        #if defined BOOT_KPI_LOG_EN
        static bool firstRender = true;
        #endif
        fl_power_state = obj_SafeHMIInterface->GetPowerState();
        printf("safeHMI power state: %d \n",fl_power_state);
        oSHMIComponent.worker();
        if(fl_power_state == ESystemState_FullRun)
        {   
            #if defined BOOT_KPI_LOG_EN
            if(firstRender)
            {
                #if defined(__linux__) && defined (__aarch64__)
                BOOT_KPI_LOG(KPI_ID_GIP_SAFEHMI_BEFORE_FIRST_RENDER, "SafeHmiBeforeFR");
                #endif
            }
            #endif
            safehmi_player.Render(true);
            #if defined BOOT_KPI_LOG_EN
            if(firstRender)
            {
                #if defined(__linux__) && defined (__aarch64__)
                BOOT_KPI_LOG(KPI_ID_GIP_SAFEHMI_AFTER_FIRST_RENDER, "SafeHmiAfterFR");
                #endif
                firstRender = false;
            }
            #endif
        }
        //TODO: Make this configurable---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}

void sendSHmiReady(const SHmiReadyStateType shmiReadyState)
{
	SafeHMIReadyStatus SHmiReadyStatus;
	SHmiReadyStatus.status = shmiReadyState;
	gApp.sendSafeHMIReadyStatus(SHmiReadyStatus);
}

void SafeHMI::sendSafeHMIReadyStatus(SafeHMIReadyStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_SAFEHMIREADYSTATUS, COMPID_OSHMICOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.status);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


/*---------------------------------------------------------------------------
Date              : 22-OCT-2025
CDSID             : braj
Traceability      : PE4TI29141-10660: NO HMI observed on target
Change Description: Plane ID was not updated after sdk update. so Plane ID is updated
----------------------------------------------------------------------------*/
