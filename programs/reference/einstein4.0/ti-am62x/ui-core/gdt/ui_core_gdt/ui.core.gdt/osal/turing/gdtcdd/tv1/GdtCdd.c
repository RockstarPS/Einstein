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
#include "TftDrvCfg.h"
#include "TftDrv.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_mgr02_layout.h"

#include "GfxDrv2D_S6J3200Drv.h"
#include <Os.h>
#include "UI_Rte_Interfaces_Cfg.h"
// brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCdd)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define CMPLIB_STATE_MASK	((uint8)0x7f)
#if !defined(GFX_MGR02_MONOTFT)
typedef enum
{
    ePreGfxMgrInit,
    eGfxMgrInit,
    ePostGfxMgrInit,
    eGfxMgrInitialized,
    eDeInitDelay_Prep,
    eDeInitDelay,
    eDeInit
}teState;
#endif
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
#if defined(GDTCDD_RENDERTASK_ALIGN_VSYNC) && !defined(GFX_MGR02_MONOTFT)
static void framecomplete_cb(MM_U64 p_interrupt );
#endif
static void ValidateActivationStage(void);
static void ValidateDeActivationStage(void);
#if !defined(GFX_MGR02_MONOTFT)
static teState eState;
#endif
#if defined(GFX_PERFORMANCE_MEASUREMENT)
static void DispFrameRate(void);
static GFX_FLOAT ConvertDurationSec(uint64 *pStart,uint64 *pStop);

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
#if !defined(GFX_MGR02_MONOTFT)
    eState = ePreGfxMgrInit;
#endif
    TftDrv_Init();
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
    l_amber_driver_reset_counter_u16 = (UINT16)0;
#endif
    GfxDrv2D_S6J3200Drv_Init();
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-initialization state
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    TftDrv_Deinit();

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
#if !defined(GFX_MGR02_MONOTFT)
    eState = ePreGfxMgrInit;
#endif
    TftDrv_Init();
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
    l_amber_driver_reset_counter_u16 = (UINT16)0;
#endif
    GfxDrv2D_S6J3200Drv_Init();

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
    #ifdef GDTCDD_RENDERTASK_ALIGN_VSYNC
    EventMaskType EventMask;
    #endif
#if !defined(GFX_MGR02_MONOTFT)

    boolean fl_TmElapsedSt;
    boolean fl_TmStartedSt;
    fl_TmStartedSt = (boolean)FALSE;
    fl_TmElapsedSt = (boolean)FALSE;
    ValidateActivationStage();
    switch(eState)
    {
        case ePreGfxMgrInit:
            UI_RTE_TIMER_IS_STARTED(eTimerHandleTftDrv,&fl_TmStartedSt);
            if(fl_TmStartedSt ==FALSE)
            {
                UI_RTE_TIMER_START(eTimerHandleTftDrv);
            }

            UI_RTE_TIMER_IS_ELAPSED(eTimerHandleTftDrv,ct1,&fl_TmElapsedSt);
            if (fl_TmElapsedSt ==TRUE)
            {
                UI_RTE_TIMER_START(eTimerHandleTftDrv);
                if(TftDrv_preActivate()==cFinished)
                {
                    eState =eGfxMgrInit;
                }
            }
        break;
        case eGfxMgrInit:
            UI_RTE_TIMER_IS_ELAPSED(eTimerHandleTftDrv,ct2,&fl_TmElapsedSt);
            if (fl_TmElapsedSt==TRUE)
            {
                #ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC 
                    #ifdef GFX_MGR02_CHECKSUM_ENABLED
                        if(GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
                        {
                            eState=ePostGfxMgrInit;
                            UI_RTE_TIMER_START(eTimerHandleTftDrv);
                        }
                    #else
                        hmi_gfx_mgr02_layout_initialize();
                        eState =ePostGfxMgrInit;
                        UI_RTE_TIMER_START(eTimerHandleTftDrv);
                    #endif
                #else
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
                        eState=ePostGfxMgrInit;
                        UI_RTE_TIMER_START(eTimerHandleTftDrv);
                    }
                }
                #endif
            }
        break;
        case ePostGfxMgrInit:
            UI_RTE_TIMER_IS_ELAPSED(eTimerHandleTftDrv,ct3,&fl_TmElapsedSt);
            if (fl_TmElapsedSt ==TRUE)
            {
                UI_RTE_TIMER_STOP(eTimerHandleTftDrv);  
                if(TftDrv_postActivate() == cFinished)
                {
                    Result = E_OK;
                    eState=eGfxMgrInitialized;
                }
            }
        break;
        default:
        /*It is not expected to reach here.*/
            eState=ePreGfxMgrInit;
        break;

    }
#else
    (void)GetEvent(OsTaskRender, &EventMask);
    if((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrInit) &&
       (EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrInitDone))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrInit);
    }
    else 
    {
        if((EventMaskType)0 !=(EventMask &  Gfx_Ev_RdrInitDone))
        {   
            (void)SetEvent(OsTaskRender, Gfx_Ev_RendererReady);
    		Result = E_OK;
        }
    }

#endif	
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
    #ifdef GDTCDD_RENDERTASK_ALIGN_VSYNC
    EventMaskType EventMask;
    #endif
#if !defined(GFX_MGR02_MONOTFT)	

	boolean fl_TmElapsedSt;
    fl_TmElapsedSt = (boolean)FALSE;
    ValidateDeActivationStage();
    switch(eState)
    {
        case eGfxMgrInitialized:
        #ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC 
            hmi_gfx_mgr02_layout_shutdown();
            UI_RTE_TIMER_START(eTimerHandleTftDrv);
            eState =eDeInitDelay_Prep;

        #else
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
                eState =eDeInitDelay_Prep;
                UI_RTE_TIMER_START(eTimerHandleTftDrv);
            }
        }
        #endif
        break;
        case eDeInitDelay_Prep:
            UI_RTE_TIMER_IS_ELAPSED(eTimerHandleTftDrv,cRdrTimeout,&fl_TmElapsedSt);
            if((hmi_gfx_mgr02_layout_is_render_done()!= 0U)||(fl_TmElapsedSt==TRUE))
            {
                if(TftDrv_DeActivate_Step1() ==cFinished)
                {
                    UI_RTE_TIMER_START(eTimerHandleTftDrv);
                    eState= eDeInitDelay;
                }
            }
        break;
        case eDeInitDelay:
            UI_RTE_TIMER_IS_ELAPSED(eTimerHandleTftDrv,ct8,&fl_TmElapsedSt);
            if (fl_TmElapsedSt==TRUE)
            {
                UI_RTE_TIMER_STOP(eTimerHandleTftDrv);
                if(TftDrv_DeActivate_Step2() == cFinished)
                {
                    Result = E_OK;
                    eState = ePreGfxMgrInit;
                }
            }
        break;
        default:
        /*It is not expected to reach here.*/
            eState = eGfxMgrInitialized;
        break;
    }
#else
    (void)GetEvent(OsTaskRender, &EventMask);
    if((EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrDeinit)) &&
       (EventMaskType)0 ==(EventMask &  Gfx_Ev_RdrDeinitDone))
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

#endif	
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
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    #ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
        GdtCdd_EvaluateAmberDriverStatusAndRecover();
    #endif
#endif
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
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
//---------------------------------------------------------------------------------------------------------------------
/// brief  Renders next frame
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
FUNC(void, GdtCdd_CODE) GdtCdd_StartRender(void)
{
    if((CmpStateType)eCmpState_Active == ((CmpStateType)(CmpState & CMPLIB_STATE_MASK)))
    {

#if GFX_NUM_ANIMATIONS > 0
        hmi_gfx_anim_engine();
#endif
        hmi_gfx_mgr02_layout_build_screen();
        GfxDrv2D_S6J3200Drv_OnStartRender();
    }
}
#endif

#ifdef GDTCDD_RENDERTASK_ALIGN_VSYNC
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
            #ifdef GFX_MGR02_CHECKSUM_ENABLED
                if(GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
                {
                    #ifndef GFX_MGR02_MONOTFT
                    (void)mmdGdcInterruptRegisterHandler(MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE0_IRQ |MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE1_IRQ,framecomplete_cb);
                    #endif
                    (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
                    (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
                }
            #else
                hmi_gfx_mgr02_layout_initialize();
                #ifndef GFX_MGR02_MONOTFT
                (void)mmdGdcInterruptRegisterHandler(MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE0_IRQ |MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE1_IRQ,framecomplete_cb);
                #endif
                (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
                (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
            #endif

        }
        else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrDeinit))
        {
             UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
             #ifndef GFX_MGR02_MONOTFT
                (void)mmdGdcInterruptRegisterHandler(MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE0_IRQ |MM_GDC_IRIS_DISENGCFG_FRAMECOMPLETE1_IRQ,(void *)0);
             #endif
             hmi_gfx_mgr02_layout_shutdown();
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
static void framecomplete_cb(MM_U64 p_interrupt )
{
    if((CmpStateType)eCmpState_Active == ((CmpStateType)(CmpState & CMPLIB_STATE_MASK)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);
    }
}


#if defined(GFX_MGR02_AMBER)
FUNC(void, GdtCdd_CODE) CGdtCdd_DispRdyStatus(P2VAR(UInt32, AUTOMATIC, RTE_GDTCDD_APPL_VAR) StatusPtr)
{
    *StatusPtr = hmi_gfx_mgr02_layout_get_disp_content_status();
}
#endif
#endif
#endif /*GDTCDD_RENDERTASK_ALIGN_VSYNC*/
#if defined(GFX_PERFORMANCE_MEASUREMENT)
GFX_FLOAT ConvertDurationSec(uint64 *pStart,uint64 *pStop)
{
    return (((*pStop) - (*pStart))/1000000.0f);
}
static GFX_FLOAT frame_rate[100];
static uint8 counter=0;
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
static void ValidateActivationStage(void)
{
    if(eState>(teState)eGfxMgrInitialized)
    {
        #ifdef GDTCDD_RENDERTASK_ALIGN_VSYNC
        EventMaskType EventMask=(EventMaskType)0;
        (void)GetEvent(OsTaskRender, &EventMask);
        if(((EventMaskType)0 ==(EventMask & Gfx_Ev_RdrInit))&&
           ((EventMaskType)0 ==(EventMask & Gfx_Ev_RdrInitDone)))
        {
            eState = ePreGfxMgrInit;        
        }
        else if(((EventMaskType)0 !=(EventMask & Gfx_Ev_RdrInit))&&
                ((EventMaskType)0 ==(EventMask & Gfx_Ev_RdrInitDone)))
        {
            /*Layout initialize is in progress*/
            eState = eGfxMgrInit;
        }

        else if((EventMaskType)0 !=(EventMask & Gfx_Ev_RdrInitDone))
        {
            /*Layout initialize completed already*/
            eState = ePostGfxMgrInit;
        }
        else
        {
        	/*To fix MISRA warning.*/

        }
        #else
        /*Current programs all are defining the macro GDTCDD_RENDERTASK_ALIGN_VSYNC.
        So, the else part can be decided later if needed.*/
        #endif
    }
}
static void ValidateDeActivationStage(void)
{
    if((eState<(teState)eGfxMgrInitialized)||(eState>(teState)eDeInitDelay))
    {
        eState = eGfxMgrInitialized;
    }
}
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
// CMS Rev 1.0      27-Sep-2017    SSIGAMAN
// 912790: FPS performance is very low when used bigger Speedo pointer. 
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

