//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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

#include "Rte_GdtCdd.h"
#include "CmpLib.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_mgr02_layout.h"

#include <Os.h>
#include "UI_Rte_Interfaces_Cfg.h"
#if defined(GFX_MGR02_TV2_WITH_SEGMENTED)
#include "hmi_gfx_manager.h"
#endif

// brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCdd)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define CMPLIB_STATE_MASK	((uint8)0x7f)
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
#define AMBER_DRIVER_RESET_DURATION_COUNTER   ((AMBER_DRIVER_BUSY_STATUS_DURATION_IN_SECS * 1000)/AMBER_DRIVER_STATUS_EVALUATION_FREQ_IN_MILLISECS )
#define AMBER_RESET_COUNTER_MAX_LIMIT      (0xFFFFU)
#if (AMBER_DRIVER_RESET_DURATION_COUNTER > AMBER_RESET_COUNTER_MAX_LIMIT)
#error "Check the configuration of AMBER_DRIVER_BUSY_STATUS_DURATION_IN_SECS"
#endif
UINT16 l_amber_driver_reset_counter_u16 = (UINT16)0;
static void GdtCdd_EvaluateAmberDriverStatusAndRecover(void);
#endif

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
#if !defined(GFX_MGR02_MONOTFT)
static void framecomplete_cb(CYGFX_INT_BANK p_bank, CYGFX_U32 p_interrupt );
#ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
static void hmi_gfx_mgr02_capture_video_mipi_cs2_frame_complete_monitor_cb(CYGFX_INT_BANK p_bank, CYGFX_U32 p_interrupt); 
#endif
#endif

#if defined(GFX_PERFORMANCE_MEASUREMENT)
static void DispFrameRate(void);
static GFX_FLOAT ConvertDurationSec(uint64 *pStart,uint64 *pStop);
static GFX_FLOAT frame_rate[100];
static uint8 counter=0;

static uint64        s_time;
static UINT32        s_frame;
static const UINT32  s_measure_frames = 60;
#endif
//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional initialization state
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{

#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
    l_amber_driver_reset_counter_u16 = (UINT16)0;
#endif
#if defined(GFX_PERFORMANCE_MEASUREMENT)
    UI_RTE_TIMER_START(eTimerHandleGdtCdd);
#endif
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-initialization state
///
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
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
#ifdef CMPLIB_WAKEUP_STATE_SUPPORT
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
static Std_ReturnType CmpWakeUp(void)
{

    TftDrv_Init();
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
    l_amber_driver_reset_counter_u16 = (UINT16)0;
#endif

    return E_OK;
}
#endif
#endif

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    Std_ReturnType Result = E_NOT_READY;

    EventMaskType EventMask;

    (void)GetEvent(OsTaskRender, &EventMask);
    if(((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrInit)) &&
       ((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrInitDone)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInit);
    }
    else 
    {
        if((EventMaskType)0 !=(EventMask &  Gfx_Ev_RdrInitDone))
        {   
			#if defined(GFX_MGR02_MONOTFT)
            (void)SetEvent(OsTaskRender, Gfx_Ev_RendererReady);
			#endif
    		Result = E_OK;
        }
    }
    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
    
    Std_ReturnType Result = E_NOT_READY;
    EventMaskType EventMask;

    (void)GetEvent(OsTaskRender, &EventMask);
    if(((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrDeinit)) &&
       ((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrDeinitDone)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrDeinit);
    }
    else 
    {
        if((EventMaskType)0 !=(EventMask &  Gfx_Ev_RdrDeinitDone))
        {
            Result = E_OK;
        }
    }

    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  : Restarts Amber Driver when status is Busy for prolonged duration
///
/// return : None
//---------------------------------------------------------------------------------------------------------------------
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
void GdtCdd_EvaluateAmberDriverStatusAndRecover(void)
{
    UINT32 fl_amber_driver_status_u32;

    fl_amber_driver_status_u32 = hmi_gfx_mgr02_layout_get_amber_driver_status();
    if(fl_amber_driver_status_u32 != (UINT32)FALSE)
    {
        l_amber_driver_reset_counter_u16++;
        if(l_amber_driver_reset_counter_u16 >= (UINT16)AMBER_DRIVER_RESET_DURATION_COUNTER)
        {
            hmi_gfx_mgr02_layout_restart_AmberDriver();
            l_amber_driver_reset_counter_u16 = 0U;
        }
        else
        {
        }
    }
    else
    {
        l_amber_driver_reset_counter_u16 = 0U;
    }	
}
#endif

//---------------------------------------------------------------------------------------------------------------------
/// brief  State for normal operations
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{

#ifndef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
    #if GFX_NUM_ANIMATIONS > 0
        hmi_gfx_anim_engine_tick();
    #endif
#endif
#ifdef GFX_MGR02_MONOTFT
{
    EventMaskType EventMask;
    (void)GetEvent(OsTaskRender, &EventMask);
    if((EventMaskType)0 == (EventMask & Gfx_Ev_VSync))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);
    }
}
#endif

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Diagnostic state
///
/// return E_OK:           Diagnostic has completed. Go to DiagReturn state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Render Task Definition.
///
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
            
            #if defined(GFX_MGR02_MONOTFT)
            boolean  fb_trans_complete;
            fb_trans_complete =UI_LCDBUS_IF_FB_TRANS();
            #endif
            #ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
                GdtCdd_EvaluateAmberDriverStatusAndRecover();
            #endif
            #ifdef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
            #if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine_tick();
            #endif
            #endif
            #if !defined(GFX_MGR02_MONOTFT)
            #if  !(defined(GFX_MGR02_AMBER_SKIP_BUSY_CHK))
            if(0U!=hmi_gfx_mgr02_layout_is_render_done())
            #endif
            {
                 UI_RTE_GDT_CDD_RENDER_DONE();
            }
            (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
            #else
            if(fb_trans_complete!=FALSE)
            {
                 UI_RTE_GDT_CDD_RENDER_DONE();
                 (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
            }
            #endif          
        }
        else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrStart))
        {
            #if defined(GFX_MGR02_MONOTFT)
            (void)ClearEvent(EventMask & (Gfx_Ev_RendererReady));
            #endif
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrInitDone));
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
            #if defined(GFX_MGR02_TV2_WITH_SEGMENTED)
            (void)GfxManagerBuildScreen();
            #endif
            #if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine();
            #endif
            hmi_gfx_mgr02_layout_build_screen();
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrStart));
            #if defined(GFX_PERFORMANCE_MEASUREMENT)
            DispFrameRate();
            #endif
        }
        else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrInit))
        {
            UI_RTE_GDTCDD_WATCHDOG_ENABLE_CALL();
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
           (void)ClearEvent(EventMask & Gfx_Ev_RdrDeinitDone);
            #if defined(GFX_MGR02_MONOTFT)
            /*Init the LCD Bus I/F or TFT if need in the preemptive task.*/
            UI_LCDBUS_IF_INIT();
            #endif
            #if defined(GFX_MGR02_TV2_WITH_SEGMENTED)
            GfxManagerInitialize();
            #endif
            #ifdef GFX_MGR02_CHECKSUM_ENABLED
                if(GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
                {
                    #ifndef GFX_MGR02_MONOTFT
                    (void)CyGfx_kInterruptRegisterHandler(CYGFX_INT_BANK_VIDEOIO1,CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE0 |CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE1,framecomplete_cb);
                    #endif
                    (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
                    (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
                }
            #else

                hmi_gfx_mgr02_layout_initialize();
                #ifndef GFX_MGR02_MONOTFT
                #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
                (void)CyGfx_kInterruptRegisterHandler(CYGFX_INT_BANK_VIDEOIO0,CYGFX_INT_BANK0_VIDEOIO0_STORE4_FRAMECOMPLETE |
				CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_ON | CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_OFF,
				hmi_gfx_mgr02_capture_video_mipi_cs2_frame_complete_monitor_cb);
                #endif
                (void)CyGfx_kInterruptRegisterHandler(CYGFX_INT_BANK_VIDEOIO1,CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE0 |CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE1,framecomplete_cb);
                #endif
                (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
                (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
            #endif
        }
        else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrDeinit))
        {
             UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
             #ifndef GFX_MGR02_MONOTFT
             #ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
              (void)CyGfx_kInterruptRegisterHandler(CYGFX_INT_BANK_VIDEOIO0,CYGFX_INT_BANK0_VIDEOIO0_STORE4_FRAMECOMPLETE | CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_ON | CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_OFF,(void*)0);
             #endif
              (void)CyGfx_kInterruptRegisterHandler(CYGFX_INT_BANK_VIDEOIO1,CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE0 |CYGFX_INT_BANK1_VIDEOIO1_DISENGCFG_FRAMECOMPLETE1,(void *)0);
             #endif
             #if defined(GFX_MGR02_TV2_WITH_SEGMENTED)
             GfxManagerExit();
             #endif
             /*
             GFX_MGR02_DISABLE_SHUTDOWN_IN_GDTCDD - Define this macro if you want to call layout shutdown from outside of GdtCdd
             Kindly note the below points before enabling this macro
             1. MCAL team need to take care of activating GdtCdd(CmpActivation) after hmi_gfx_mgr02_layout_shutdown during sleep/wakeup
             2. hmi_gfx_mgr02_layout_shutdown API must be called after GdtCdd CmpDeActivation
             3. This change added to resolve the timing mismatch issue with power down sequence in Honda, Its not applicable for other programs
             */
             #ifndef GFX_MGR02_DISABLE_SHUTDOWN_IN_GDTCDD             
             hmi_gfx_mgr02_layout_shutdown();
             #endif
             UI_RTE_GDTCDD_WATCHDOG_DISABLE_CALL();
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrDeinit));
            (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
            (void)ClearEvent(EventMask & (Gfx_Ev_RdrStart));
            (void)SetEvent(OsTaskRender,Gfx_Ev_RdrDeinitDone);

        }
        else
        {
        	/*To fix MISRA warning.*/
        }
    }
}
#ifndef GFX_MGR02_MONOTFT
static void framecomplete_cb(CYGFX_INT_BANK p_bank, CYGFX_U32 p_interrupt )
{
    if((CmpStateType)eCmpState_Active == ((CmpStateType)(CmpState & CMPLIB_STATE_MASK)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);
    }
    GFX_MGR02_UNUSED_VAR(p_bank);
    GFX_MGR02_UNUSED_VAR(p_interrupt);
}
#ifdef GFX_MGR02_CAPTURE_VIDEO_USING_TRAVEO2_MIPI_CS2
static void hmi_gfx_mgr02_capture_video_mipi_cs2_frame_complete_monitor_cb(CYGFX_INT_BANK p_bank, CYGFX_U32 p_interrupt)
{
#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
    if ((p_interrupt & CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_ON) == CYGFX_INT_BANK0_VIDEOIO0_FRAMECAP0_SYNC_ON)
    {
      hmi_gfx_mgr02_layout_set_frame_capture_done_status(GFX_MGR02_VIDEO_CAPTURE_DONE);
      hmi_gfx_mgr02_layout_set_display_property(CYGFX_DISP_ATTR_IN_CTRL, CYGFX_DISP_INPUT_CONTROL_BLEND);
    }
#else
    if ((p_interrupt & CYGFX_INT_BANK0_VIDEOIO0_STORE4_FRAMECOMPLETE) == CYGFX_INT_BANK0_VIDEOIO0_STORE4_FRAMECOMPLETE)
    {
      hmi_gfx_mgr02_layout_set_frame_capture_done_status(GFX_MGR02_VIDEO_CAPTURE_DONE);
    }
#endif
}
#endif

FUNC(void, GdtCdd_CODE) CGdtCdd_DispRdyStatus(P2VAR(UInt32, AUTOMATIC, RTE_GDTCDD_APPL_VAR) StatusPtr)
{
    *StatusPtr = hmi_gfx_mgr02_layout_get_disp_content_status();
}
#endif

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

