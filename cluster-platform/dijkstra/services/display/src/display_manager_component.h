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
#ifndef DISPLAY_MANAGER_COMPONENT_H
#define DISPLAY_MANAGER_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_display_manager_component.h"
#include "dk_runtime_types.h"
#include "dk_runtime_parserif.h"
#include "dk_bspal_display.h"
#include "DKOsalMutex.h"
#include "DKOsalMutexLock.h"
#include "DKOsalTimer.h"

using namespace dk::runtime;

class DisplayManagerComponent : public dk::runtime::core::Component
{
public:
    explicit DisplayManagerComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId),
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  mTftErrPollTmrCbk(*this),
																																  mTftErrPollTmr(mTftErrPollTmrCbk)
    {
    }

	    virtual ~DisplayManagerComponent()
        {
        }

	    virtual bool onInit();
	    virtual bool onExit();
	    virtual bool onStart();
	    virtual bool onStop();
        void worker ( void );

	    void onReceiveDisplaySetPower(DisplaySetPower const & msg);

	    void onReceiveDisplayGetState(DisplayGetState const & msg);

	    void onReceivePowerSystemState(PowerSystemState const & msg);
#ifdef DISPLAY_GAMMA_RGB

		void onReceiveDisplaySetGammaRGB(DisplaySetGammaRGB const & msg);

		void onReceiveDisplayGetGammaRGB(DisplayGetGammaRGB const & msg);
#endif  

    private:
        /// Start of user code : User code for file display_manager_component.h

        typedef enum
        {
            STATE_INIT,
            STATE_WAIT_FOR_UCL,
            STATE_DISP_ON,
            STATE_DISP_ERROR,
            STATE_DISP_OFF,
        } SeqncrStates_t;

        typedef enum
        {
            EVT_START,
            EVT_SYS_STATE_UP,
            EVT_TFT_ERROR_POLL,
            EVT_DISP_PWR_DOWN_REQ,
            EVT_DISP_PWR_UP_REQ,
        } SeqncrEvents_t;

        class TftErrPollTimerListener : public dk::osal::ITimerListener
        {
            private:
                DisplayManagerComponent &mParent;
            public:
                TftErrPollTimerListener(DisplayManagerComponent& parent) : mParent(parent)
                {

                }
                void onTimeout ( const dk::osal::Timer &timer );
        };

        dk::runtime::core::ParserIf mParserObj;
        uint32_t mDisplayStatePeriodicTimerMs = 0u;
        const uint32_t mcDisplayStatePeriodicTimerMs = 100u;
        SeqncrStates_t mSeqncrState = STATE_INIT;
        static const char *const mSeqncrStatesEnum2Str[];
        static const char *const mSeqncrEventsEnum2Str[];
        dk::osal::Mutex mSeqncrMutex;
        TftErrPollTimerListener mTftErrPollTmrCbk;
        dk::osal::Timer mTftErrPollTmr;

        bool loadConfig ( void );
        void sendDisplayCurrentState ( const uint32_t p_disp_id_U32, const EBspalDisplayStatus_t p_stat_E );
        void seqncrFsm(const SeqncrEvents_t p_evt_E);

        /// End of user code
};



#endif //DISPLAY_MANAGER_COMPONENT_H

