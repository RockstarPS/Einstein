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
// Date: Fri Oct 01 07:04:51 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <chrono>
#include "display_manager_component.h"
#include "dk_bspal_display.h"

/// Start of user code : Header user code for file display_manager_component.cpp

LOG_DECLARE_CONTEXT(gDMLogContext);

#define STRINGIFY(v)    [v] = #v

const char *const DisplayManagerComponent::mSeqncrStatesEnum2Str[] = {
        STRINGIFY(STATE_INIT),
        STRINGIFY(STATE_WAIT_FOR_UCL),
        STRINGIFY(STATE_DISP_ON),
        STRINGIFY(STATE_DISP_ERROR),
        STRINGIFY(STATE_DISP_OFF),
};

const char *const DisplayManagerComponent::mSeqncrEventsEnum2Str[] = {
        STRINGIFY(EVT_START),
        STRINGIFY(EVT_SYS_STATE_UP),
        STRINGIFY(EVT_TFT_ERROR_POLL),
        STRINGIFY(EVT_DISP_PWR_DOWN_REQ),
        STRINGIFY(EVT_DISP_PWR_UP_REQ),
};

/// End of user code



bool DisplayManagerComponent::onInit()
{
    bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file display_manager_component.cpp

    LOG_REGISTER_CONTEXT(gDMLogContext, "DM ", "Display Manager Component", DLT_LOG_VERBOSE);
    LOGI(&gDMLogContext, "Enter");
    if(loadConfig())
    {
        std::string sectionName = "DisplayStateConfiguration";
        mDisplayStatePeriodicTimerMs = mParserObj.getInt32Value(sectionName, "DisplayStateMessagePeriodicityMs", mcDisplayStatePeriodicTimerMs);
    }
    else
    {
        mDisplayStatePeriodicTimerMs = mcDisplayStatePeriodicTimerMs;
    }
    LOGI(&gDMLogContext, "DisplayStateMessagePeriodicityMs: ", mDisplayStatePeriodicTimerMs);

/// End of user code

    return ret;
}

bool DisplayManagerComponent::onExit()
{
    bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file display_manager_component.cpp

    LOGI(&gDMLogContext, "Enter");

/// End of user code

    return ret;
}

bool DisplayManagerComponent::onStart()
{
    bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file display_manager_component.cpp

    LOGI(&gDMLogContext, "Enter");
    seqncrFsm(EVT_START);

/// End of user code

    return ret;
}

bool DisplayManagerComponent::onStop()
{
    bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file display_manager_component.cpp

    LOGI(&gDMLogContext, "Enter");

/// End of user code

    return ret;
}

void DisplayManagerComponent::worker()
{
/// Start of user code : User code for function worker in file display_manager_component.cpp

/// End of user code
}

void DisplayManagerComponent::onReceiveDisplaySetPower(DisplaySetPower const  & msg)
{
/// Start of user code : User code for function onReceiveDisplaySetPower in file display_manager_component.cpp
    switch(msg.state)
    {
        case EDisplayPower_On:
        {
            seqncrFsm(EVT_DISP_PWR_UP_REQ);

            break;
        }
        case EDisplayPower_Off:
        {
            seqncrFsm(EVT_DISP_PWR_DOWN_REQ);

            break;
        }
        default:
        {
            LOGE(&gDMLogContext, "Illegal request");

            break;
        }
    }

/// End of user code
}

void DisplayManagerComponent::onReceiveDisplayGetState(DisplayGetState const  & msg)
{
/// Start of user code : User code for function onReceiveDisplayGetState in file display_manager_component.cpp

    int32_t l_ret_S32 = -1;
    EBspalDisplayStatus_t l_disp_status_E;

    l_ret_S32 = dk_bspal_display_get_state ( (uint8_t)msg.displayId, &l_disp_status_E );
    if (0 == l_ret_S32)
    {
        sendDisplayCurrentState(msg.displayId, l_disp_status_E);
    }
    else
    {
        LOGE(&gDMLogContext, "dk_bspal_display_get_state() failed");
    }

/// End of user code
}

void DisplayManagerComponent::onReceivePowerSystemState(PowerSystemState const  & msg)
{
/// Start of user code : User code for function onReceivePowerSystemState in file display_manager_component.cpp

    if (ESystemState_Up == msg.state)
    {
        seqncrFsm(EVT_SYS_STATE_UP);
    }
    else
    {
        ;
    }

/// End of user code
}
#ifdef DISPLAY_GAMMA_RGB
void DisplayManagerComponent::onReceiveDisplaySetGammaRGB(DisplaySetGammaRGB const  & msg)
{
/// Start of user code : User code for function onReceiveDisplaySetGammaRGB in file display_manager_component.cpp
    int32_t l_ret_S32 = -1;
    uint8_t p_id_U8 = 0;
    l_ret_S32 = dk_bspal_display_set_gamma_rgb(p_id_U8,msg.redGamma,msg.greenGamma,msg.blueGamma);
    if (0 == l_ret_S32)
    {
        LOGI(&gDMLogContext, "dk_bspal_display_set_gamma_rgb() Passed");
    }
    else
    {
        LOGE(&gDMLogContext, "dk_bspal_display_set_gamma_rgb() failed");
    }
/// End of user code
}

void DisplayManagerComponent::onReceiveDisplayGetGammaRGB(DisplayGetGammaRGB const  & msg)
{
/// Start of user code : User code for function onReceiveDisplayGetGammaRGB in file display_manager_component.cpp
    int32_t l_ret_S32 = -1;
    uint8_t p_id_U8 = 0;
    int32_t red_gamma = 0;
    int32_t green_gamma = 0;
    int32_t blue_gamma = 0;
    DisplayCurrentGammaRGB l_dk_rgb;
    l_ret_S32 = dk_bspal_display_get_gamma_rgb(p_id_U8,&red_gamma,&green_gamma,&blue_gamma);
    l_dk_rgb.redGamma = red_gamma;
    l_dk_rgb.greenGamma = green_gamma;
    l_dk_rgb.blueGamma = blue_gamma;
    if (0 == l_ret_S32)
    {
        DK_RTE_Send_DisplayCurrentGammaRGB(l_dk_rgb);
        LOGI(&gDMLogContext, "Send_DisplayCurrentGamma Passed");
    }
    else
    {
        LOGE(&gDMLogContext, "dk_bspal_display_set_gamma_rgb() failed");
    }

/// End of user code
}
#endif

/// Start of user code : Footer user code for file display_manager_component.cpp

bool DisplayManagerComponent::loadConfig()
{
    bool configFound = false;

    if (mParserObj.loadConfiguration(std::string("./display_mgr.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/etc/display_mgr/display_mgr.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/system/etc/display_mgr/display_mgr.ini")))
    {
        configFound = true;
    }
    else
    {
        LOGE(&gDMLogContext, "No Config file found");
    }

    return configFound;
}

void DisplayManagerComponent::sendDisplayCurrentState ( const uint32_t p_disp_id_U32, const EBspalDisplayStatus_t p_stat_E )
{
    DisplayCurrentState l_dk_stat_S;
    l_dk_stat_S.displayId = p_disp_id_U32;
    bool l_found_B = true;

    switch (p_stat_E)
    {
        case EBspaDisplayState_On:
        {
            l_dk_stat_S.state = EDisplayState_On;
            break;
        }
        case EBspalDisplayState_Off:
        {
            l_dk_stat_S.state = EDisplayState_Off;
            break;
        }
        case EBspaDisplayState_Error:
        {
            l_dk_stat_S.state = EDisplayState_Error;
            break;
        }
        case EBspalDisplayState_Disconnected:
        {
            l_dk_stat_S.state = EDisplayState_Disconnected;
            break;
        }
        default:
        {
          l_found_B = false;
            LOGE(&gDMLogContext, "Invalid state request");
            break;
        }
    }

    if (true == l_found_B)
    {
        LOGI(&gDMLogContext, "displayId: ", l_dk_stat_S.displayId);
        LOGI(&gDMLogContext, "state: ", l_dk_stat_S.state);
        DK_RTE_Send_DisplayCurrentState(l_dk_stat_S);
    }
    else
    {
        ;
    }
}

void DisplayManagerComponent::seqncrFsm(const SeqncrEvents_t p_evt_E)
{
    dk::osal::MutexLock l_scoped_lock_C(mSeqncrMutex);

    LOGV(&gDMLogContext, "E: ", mSeqncrStatesEnum2Str[mSeqncrState], " - " , mSeqncrEventsEnum2Str[p_evt_E]);

    switch (mSeqncrState)
    {
        /*********************************************************************/
        case STATE_INIT:
        {
            switch (p_evt_E)
            {
                case EVT_START:
                {
                    int32_t l_ret_S32 = -1;

                    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // a 10 ms buffer to let the vGPIO schedule
                    l_ret_S32 = dk_bspal_display_set_power(0, EBspalDisplayPower_On);
                    if (0 == l_ret_S32)
                    {
                        mSeqncrState = STATE_WAIT_FOR_UCL;
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_set_power() failed");
                    }

                    break;
                }
                default:
                {
                    LOGE(&gDMLogContext, "unhandled event");

                    break;
                }
            }

            break;
        }
        /*********************************************************************/
        case STATE_WAIT_FOR_UCL:
        {
            switch (p_evt_E)
            {
                case EVT_SYS_STATE_UP:
                {
                    int32_t l_ret_S32 = -1;
                    EBspalDisplayStatus_t l_disp_state_E = EBspalDisplayState_Off;

                    l_ret_S32 = dk_bspal_display_get_state(0, &l_disp_state_E);
                    if (0 == l_ret_S32)
                    {
                        if (EBspaDisplayState_Error == l_disp_state_E)
                        {
                            sendDisplayCurrentState(0, EBspaDisplayState_Error);
                            mSeqncrState = STATE_DISP_ERROR;
                        }
                        else if (EBspaDisplayState_On == l_disp_state_E)
                        {
                            sendDisplayCurrentState(0, EBspaDisplayState_On);
                            mTftErrPollTmr.start(mDisplayStatePeriodicTimerMs,
                                                 mDisplayStatePeriodicTimerMs);
                            mSeqncrState = STATE_DISP_ON;
                        }
                        else
                        {
                            LOGE(&gDMLogContext, "dk_bspal_display_get_state() returned ", l_disp_state_E);
                        }
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_get_state() failed");
                    }

                    break;
                }
                default:
                {
                    LOGE(&gDMLogContext, "unhandled event");

                    break;
                }
            }

            break;
        }
        /*********************************************************************/
        case STATE_DISP_ON:
        {
            switch (p_evt_E)
            {
                case EVT_TFT_ERROR_POLL:
                {
                    int32_t l_ret_S32 = -1;
                    EBspalDisplayStatus_t l_disp_state_E = EBspalDisplayState_Off;

                    l_ret_S32 = dk_bspal_display_get_state(0, &l_disp_state_E);
                    if (0 == l_ret_S32)
                    {
                        if (EBspaDisplayState_Error == l_disp_state_E)
                        {
                            mTftErrPollTmr.stop();
                            sendDisplayCurrentState(0, EBspaDisplayState_Error);
                            mSeqncrState = STATE_DISP_ERROR;
                        }
                        else if (EBspaDisplayState_On == l_disp_state_E)
                        {
                           ;
                        }
                        else if (EBspalDisplayState_Off == l_disp_state_E)
                        {
                            mTftErrPollTmr.stop();
                            sendDisplayCurrentState(0, EBspalDisplayState_Off);
                            mSeqncrState = STATE_DISP_OFF;
                        }
                        else
                        {
                            LOGE(&gDMLogContext, "dk_bspal_display_get_state() returned ", l_disp_state_E);
                        }
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_get_state() failed");
                    }

                    break;
                }
                case EVT_DISP_PWR_DOWN_REQ:
                {
                    int32_t l_ret_S32 = -1;

                    mTftErrPollTmr.stop();
                    l_ret_S32 = dk_bspal_display_set_power(0, EBspalDisplayPower_Off);
                    if (0 == l_ret_S32)
                    {
                        sendDisplayCurrentState(0, EBspalDisplayState_Off);
                        mSeqncrState = STATE_DISP_OFF;
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_set_power() failed");
                    }

                    break;
                }
                default:
                {
                    LOGE(&gDMLogContext, "unhandled event");

                    break;
                }
            }

            break;
        }
        /*********************************************************************/
        case STATE_DISP_ERROR:
        {
            switch (p_evt_E)
            {
                case EVT_DISP_PWR_DOWN_REQ:
                {
                    int32_t l_ret_S32 = -1;

                    l_ret_S32 = dk_bspal_display_set_power(0, EBspalDisplayPower_Off);
                    if (0 == l_ret_S32)
                    {
                        sendDisplayCurrentState(0, EBspalDisplayState_Off);
                        mSeqncrState = STATE_DISP_OFF;
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_set_power() failed");
                    }

                    break;
                }
                default:
                {
                    LOGE(&gDMLogContext, "unhandled event");

                    break;
                }
            }

            break;
        }
        /*********************************************************************/
        case STATE_DISP_OFF:
        {
            switch (p_evt_E)
            {
                case EVT_DISP_PWR_UP_REQ:
                {
                    int32_t l_ret_S32 = -1;

                    l_ret_S32 = dk_bspal_display_set_power(0, EBspalDisplayPower_On);
                    if (0 == l_ret_S32)
                    {
                        EBspalDisplayStatus_t l_disp_state_E = EBspalDisplayState_Off;

                        l_ret_S32 = dk_bspal_display_get_state(0, &l_disp_state_E);
                        if (0 == l_ret_S32)
                        {
                            if (EBspaDisplayState_Error == l_disp_state_E)
                            {
                                sendDisplayCurrentState(0, EBspaDisplayState_Error);
                                mSeqncrState = STATE_DISP_ERROR;
                            }
                            else if (EBspaDisplayState_On == l_disp_state_E)
                            {
                                sendDisplayCurrentState(0, EBspaDisplayState_On);
                                mTftErrPollTmr.start(mDisplayStatePeriodicTimerMs,
                                                     mDisplayStatePeriodicTimerMs);
                                mSeqncrState = STATE_DISP_ON;
                            }
                            else
                            {
                                LOGE(&gDMLogContext, "dk_bspal_display_get_state() returned ", l_disp_state_E);
                            }
                        }
                        else
                        {
                            LOGE(&gDMLogContext, "dk_bspal_display_get_state() failed");
                        }
                    }
                    else
                    {
                        LOGE(&gDMLogContext, "dk_bspal_display_set_power() failed");
                    }

                    break;
                }
                default:
                {
                    LOGE(&gDMLogContext, "unhandled event");

                    break;
                }
            }

            break;
        }
        /*********************************************************************/
        default:
        {
            LOGE(&gDMLogContext, "invalid state");
            mSeqncrState = STATE_INIT;

            break;
        }
    }

    LOGV(&gDMLogContext, "X: ", mSeqncrStatesEnum2Str[mSeqncrState], " - " , mSeqncrEventsEnum2Str[p_evt_E]);
    LOGV(&gDMLogContext, "----------");
}

void DisplayManagerComponent::TftErrPollTimerListener::onTimeout ( const dk::osal::Timer &timer )
{
    mParent.seqncrFsm(EVT_TFT_ERROR_POLL);
}


/// End of user code

