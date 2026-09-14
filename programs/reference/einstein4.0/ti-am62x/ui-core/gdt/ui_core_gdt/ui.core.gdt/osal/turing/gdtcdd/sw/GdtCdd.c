/***************************************************************************************
**
** VISTEON CORPORATION CONFIDENTIAL
** ________________________________
**
** [2015] Visteon Corporation
** All Rights Reserved.
**
** NOTICE: This is an unpublished work of authorship, which contains trade secrets.
** Visteon Corporation owns all rights to this work and intends to maintain it in 
** confidence to preserve its trade secret status. Visteon Corporation reserves the 
** right, under the copyright laws of the United States or those of any other country 
** that may have jurisdiction, to protect this work as an unpublished work, in the 
** event of an inadvertent or deliberate unauthorized publication. Visteon Corporation 
** also reserves its rights under all copyright laws to protect this work as a published 
** work, when appropriate. Those having access to this work may not copy it, use it, 
** modify it, or disclose the information contained in itwithout the written authorization 
** of Visteon Corporation.
*******************************************************************************************/

#include "Rte_GdtCdd.h"
#include "CmpLib.h"
#include "GdtCDD_Cfg.h"
#ifdef GDTCDD_SEGMENTED_ENABLED
#include "hmi_gfx_manager.h"
#endif
#ifndef GDTCDD_MGR02_DISABLED
#include "hmi_gfx_mgr02_layout.h"
#if GFX_NUM_ANIMATIONS > 0
#include "hmi_gfx_anim_engine.h"
#endif
#endif
#include <Os.h>
#include "UI_Rte_Interfaces_Cfg.h"


#include "HmiSpecific.h"

/* Instance of life-cycle state-machine */
CMPLIB_INSTANCE(GdtCdd)

//=====================================================================================================================
//                          MACRO & TYPE DEFINITION
//=====================================================================================================================

#define CMPLIB_STATE_MASK	((uint8)0x7f)

//=====================================================================================================================
//                          FORWARD DECLARATIONS
//=====================================================================================================================

static void Draw(void);
void framecomplete_cb(void);

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

#if defined(GFX_PERFORMANCE_MEASUREMENT)
static void DispFrameRate(void);
static GFX_FLOAT ConvertDurationSec(uint64 *pStart,uint64 *pStop);
static GFX_FLOAT frame_rate[100];
static uint8 counter = 0;
static uint64        s_time;
static UINT32        s_frame;
static const UINT32  s_measure_frames = 60;
#endif

static boolean IsRenderBlocked  = (boolean)TRUE;
static boolean IsEarlyWakeup    = (boolean)FALSE;

//---------------------------------------------------------------------------------------------------------------------
// brief  Calls presentation and perform draw if needed
// return void
//---------------------------------------------------------------------------------------------------------------------

static void Draw(void)
{
    HmiSpecific_Active();

    hmi_lsh_task();
    
    (void)SetEvent(OsTaskRender, Gfx_Ev_RdrStart);
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional initialization state
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpInit( void )
{
    #if defined(GFX_PERFORMANCE_MEASUREMENT)
    UI_RTE_TIMER_START(eTimerHandleGdtCdd);
    #endif

    #ifdef GDTCDD_LANGUAGECORE_ENABLED
    hmi_language_initialize();
    #endif

    #ifdef GDTCDD_POPUPCORE_ENABLED
    hmi_popup_core_initialize();
    #endif

    #ifdef GDTCDD_MENUCORE_ENABLED
    hmi_menu_initialize();
    #endif

    hmi_lsh_initialize((uint8)0);
    
    HmiSpecific_Init();
    
    IsRenderBlocked = (boolean)TRUE;
    IsEarlyWakeup   = (boolean)FALSE;

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-initialization state
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpDeInit( void )
{
    #if defined(GFX_PERFORMANCE_MEASUREMENT)
    UI_RTE_TIMER_STOP(eTimerHandleGdtCdd);
    #endif
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  State for normal Wakeup operations
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------

#if (defined(CMPLIB_WAKEUP_STATE_SUPPORT) && (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01))
static Std_ReturnType CmpWakeUp(void)
{
    #ifdef GDTCDD_LANGUAGECORE_ENABLED
    hmi_language_initialize();
    #endif

    #ifdef GDTCDD_POPUPCORE_ENABLED
    hmi_popup_core_initialize();
    #endif

    #ifdef GDTCDD_MENUCORE_ENABLED
    hmi_menu_initialize();
    #endif

    hmi_lsh_initialize((uint8)0);

    IsRenderBlocked = (boolean)TRUE;
    IsEarlyWakeup = (boolean)FALSE;

    return E_OK;
}
#endif

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional activation state
/// return  E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpActivation( void )
{
    Std_ReturnType Result = E_NOT_READY;
    EventMaskType EventMask;

    (void)GetEvent(OsTaskRender, &EventMask);
    if(((EventMaskType)0 == (EventMask & Gfx_Ev_RdrInit)) &&
       ((EventMaskType)0 == (EventMask & Gfx_Ev_RdrInitDone)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInit);
    }
    else 
    {
        if((EventMaskType)0 !=(EventMask &  Gfx_Ev_RdrInitDone))
        {   
            if(IsEarlyWakeup == (boolean)TRUE)
            {
                HmiSpecific_Init();
            }
            Result = HmiSpecific_Activate();
        }
    }
    
    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief   Transitional de-activation state
/// return  E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpDeActivation( void )
{
    Std_ReturnType Result = E_NOT_READY;
    EventMaskType EventMask;

    (void)GetEvent(OsTaskRender, &EventMask);
    if(((EventMaskType)0 == (EventMask & Gfx_Ev_RdrDeinit)) &&
       ((EventMaskType)0 == (EventMask & Gfx_Ev_RdrDeinitDone)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrDeinit);
    }
    else 
    {
        if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrDeinitDone))
        {
            IsEarlyWakeup = (boolean)TRUE;
            Result = HmiSpecific_Deactivate();
        }
    }

    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief                  State for normal operations
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpActive( void )
{
    IsRenderBlocked = (boolean)FALSE;
    
    #ifndef GDTCDD_MGR02_DISABLED
    #ifndef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
    #if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine_tick();
    #endif
    #endif
    #endif
#ifdef GDTCDD_SEGMENTED_ENABLED
    framecomplete_cb();
#endif
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief                   Diagnostic state
/// return E_OK:           Diagnostic has completed. Go to DiagReturn state.
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpDiag( void )
{
    /* No special behavior is defined for Diag mode yet */
    IsRenderBlocked = (boolean)FALSE;
    
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief                   Transitional state to clean up after diagnostic state. Component behaviour to be restored.
/// return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  below function is called from display controller's (DSS) interrupt service routine 
//---------------------------------------------------------------------------------------------------------------------

void framecomplete_cb(void)
{
    EventMaskType EventMask;
    if((CmpStateType)eCmpState_Active == (CmpStateType)(CmpState & CMPLIB_STATE_MASK))
    {
        (void)GetEvent(OsTaskRender, &EventMask);
        if((EventMaskType)0 == (EventMask & Gfx_Ev_VSync))
        {
            (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Render Task Definition.
/// return void
//---------------------------------------------------------------------------------------------------------------------

TASK(OsTaskRender)
{
    EventMaskType EventMask;

    while(1)
    {
        (void)WaitEvent(Gfx_Ev_RdrStart|Gfx_Ev_VSync|Gfx_Ev_RdrInit|Gfx_Ev_RdrDeinit);
        (void)GetEvent(OsTaskRender, &EventMask);
        if((EventMaskType)0 != (EventMask & Gfx_Ev_VSync))
        {
            #ifndef GDTCDD_MGR02_DISABLED
            #ifdef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
            #if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine_tick();
            #endif
            #endif
            #endif
            
            if((boolean)FALSE == IsRenderBlocked)
            {
                Draw(); /* Called when GfxMgr has completed rendering the last frame and is ready to render next frame */
            }
            
            (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
        }
        else if ((EventMaskType)0 != (EventMask & Gfx_Ev_RdrStart))
        {
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrInitDone));
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
#ifndef GDTCDD_MGR02_DISABLED
#if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine();
#endif
#endif
#ifdef GDTCDD_SEGMENTED_ENABLED
            (void)GfxManagerBuildScreen();
#endif
#ifndef GDTCDD_MGR02_DISABLED
            hmi_gfx_mgr02_layout_build_screen();
#endif
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrStart));

#if defined(GFX_PERFORMANCE_MEASUREMENT)
            DispFrameRate();
#endif
        }
        else if ((EventMaskType)0 != (EventMask & Gfx_Ev_RdrInit))
        {
            UI_RTE_GDTCDD_WATCHDOG_ENABLE_CALL();
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
            (void)ClearEvent(EventMask & Gfx_Ev_RdrDeinitDone);
#ifdef GDTCDD_SEGMENTED_ENABLED
            GfxManagerInitialize();
#endif
#ifdef GDTCDD_MGR02_DISABLED

            (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
            (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInitDone);
#else
#ifdef GFX_MGR02_CHECKSUM_ENABLED
            if (GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
            {
              (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
              (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInitDone);
            }
#else
            hmi_gfx_mgr02_layout_initialize();
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
            (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInitDone);
#endif
#endif
        }
        else if ((EventMaskType)0 != (EventMask & Gfx_Ev_RdrDeinit))
        {
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
#ifdef GDTCDD_SEGMENTED_ENABLED
            GfxManagerExit();
#endif
#ifndef GDTCDD_MGR02_DISABLED
            hmi_gfx_mgr02_layout_shutdown();
#endif
            UI_RTE_GDTCDD_WATCHDOG_DISABLE_CALL();
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrDeinit));
            (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrStart));
            (void)SetEvent(OsTaskRender, Gfx_Ev_RdrDeinitDone);
        }
        else
        {
        	/* To fix MISRA warning */
        }
    }
}

#if defined(GFX_PERFORMANCE_MEASUREMENT)
GFX_FLOAT ConvertDurationSec(uint64 *pStart,uint64 *pStop)
{
    return (((*pStop) - (*pStart))/1000000.0f);
}

uint64 Timer_GetTickCountUs(void)
{
    uint32 fl_elapsedtimevalue = (uint32)0;
    UI_RTE_TIMER_GET_ELAPSED_TIME(eTimerHandleGdtCdd, &fl_elapsedtimevalue );
    return ((uint64)fl_elapsedtimevalue * 1000UL );
}

void DispFrameRate(void)
{
    uint64 curTime;
    HMI_CHAR fl_fps[15];
    if ((s_frame % s_measure_frames) == 0)
    {
        curTime = Timer_GetTickCountUs();
/*        HMI_SNPRINTF(fl_fps,15,HMI_TEXT("FPS: %.1f%c"), (s_measure_frames / ConvertDurationSec(&s_time, &curTime)));*/
        frame_rate[counter++]= (s_measure_frames / ConvertDurationSec(&s_time, &curTime));
        if(counter==100)
        {
            counter=0;
        }
        s_time = curTime;
    }
    s_frame++;
}
#endif


//---------------------------------------------------------------------------------------------------------------------
// C M S    R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
//
// For each change to this file, be sure to record:
// 1.  Who made the change and when the change was made.
// 2.  Why the change was made and the intended result.
//
// CMS Rev #        Date            By
// CMS Rev X.X      dd-mmm-yyyy     CDSID
//
//---------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

