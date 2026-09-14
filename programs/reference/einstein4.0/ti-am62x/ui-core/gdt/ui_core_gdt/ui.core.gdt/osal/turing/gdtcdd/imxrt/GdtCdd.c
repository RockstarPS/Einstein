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
#include "hmi_gfx_mgr02_imxrt_lcdif.h"
#include "panel_definition_imxrt.h"
#include <Os.h>
#include "UI_Rte_Interfaces_Cfg.h"
#if defined(__GNUC__)
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "stub_legacy.h"
#endif
// brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCdd)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define CMPLIB_STATE_MASK	((UINT8)0x7f)


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static void framecomplete_cb(void);
static Std_ReturnType gdtcdd_deactivate(void);
#if defined(__GNUC__)	
extern volatile EventGroupHandle_t xHMIEventGroup ;
extern volatile EventBits_t xHMIGroupValue ;
#endif

#if defined(GFX_PERFORMANCE_MEASUREMENT)
static void DispFrameRate(void);
static GFX_FLOAT ConvertDurationSec(UINT64 *pStart,UINT64 *pStop);
static GFX_FLOAT frame_rate[100];
static UINT8 counter = 0;

static UINT64        s_time;
static UINT32        s_frame;
static const UINT32  s_measure_frames = 60;
static UINT64 Timer_GetTickCountUs(void);
#endif
void LCDIFv2_IRQHandler(void);
//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional initialization state
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
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

#if defined(__GNUC__)
  EventBits_t  EventMask = 0UL;
  EventMask = xEventGroupGetBits( xHMIEventGroup );
  
  if((0UL == (EventMask & Gfx_Ev_RdrInit)) && (0UL == (EventMask & Gfx_Ev_RdrInitDone)))
  {
	(void)xEventGroupSetBits(xHMIEventGroup, Gfx_Ev_RdrInit);
  }
  else
  {
    if(0UL != (EventMask & Gfx_Ev_RdrInitDone))
    {
      Result = E_OK;
    }
  }
#elif defined(__ghs__)
  EventMaskType EventMask;

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

#ifndef GFX_MGR02_INITIATE_SHUTDOWN_SEQUENCE_BEFORE_SLEEP
    Result = gdtcdd_deactivate();
#else
    Result = E_OK;
#endif

    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  State for normal operations
///
/// return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    Std_ReturnType Result;
#ifdef GFX_MGR02_INITIATE_SHUTDOWN_SEQUENCE_BEFORE_SLEEP
    UINT32 fl_current_context_U32T = UI_RTE_GET_CURRENT_CONTEXT(fl_current_context_U32T);
#else
    Result = E_OK;
#endif
    
#ifndef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
#if GFX_NUM_ANIMATIONS > 0
  hmi_gfx_anim_engine_tick();
#endif
#endif

#ifdef GFX_MGR02_INITIATE_SHUTDOWN_SEQUENCE_BEFORE_SLEEP
    if (fl_current_context_U32T == eSLEEP)
    {
      Result = gdtcdd_deactivate();
    }
    else
    {
      Result = E_OK;
    }
#endif
    return Result;
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


/*============================================================================
** Function Name:    LCDIF_IRQHandler
** Visibility:       Global
** Description:      
**                   
** Invocation:       
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void LCDIFv2_IRQHandler(void)
{
    uint32_t intStatus;
    #if defined(APM_ENABLED) && defined(APM_ISR_CHECK_POINT_ENABLED)
    /* Following change has been added by the platform team to measure ISR cpu load in freertos */
    Apm_PreCheckpointProcess(2);
    #endif
    intStatus = LCDIFV2_GetInterruptStatus(DEMO_LCDIF, DEMO_CORE_ID);
    LCDIFV2_ClearInterruptStatus(DEMO_LCDIF, DEMO_CORE_ID, intStatus);

    if ((uint32_t)0 != (intStatus & (uint32_t)kLCDIFV2_VerticalBlankingInterrupt))
    {
        hmi_gfx_mgr02_imxrt_lcdif_vblank_interrupt();
        framecomplete_cb();
    }
    #if defined(APM_ENABLED) && defined(APM_ISR_CHECK_POINT_ENABLED)
    Apm_PostCheckpointProcess(2);
    #endif
    /*SDK_ISR_EXIT_BARRIER is added for Errata ERR009005 fix, Ref - IMXRT1170CE 2024.pdf */
    SDK_ISR_EXIT_BARRIER;
}


//---------------------------------------------------------------------------------------------------------------------
/// brief  Render Task Definition.
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
#if defined(__GNUC__)
void Task_OsTaskRender(void *pvParameters);

void Task_OsTaskRender(void *pvParameters)
{
    EventBits_t EventMask = 0UL;
    xHMIEventGroup = xEventGroupCreate();
    for(;;)
    {
        xHMIGroupValue = xEventGroupWaitBits(xHMIEventGroup,
                                        Gfx_Ev_RdrStart|Gfx_Ev_VSync| \
                                        Gfx_Ev_RdrInit| Gfx_Ev_RdrDeinit,
                                        pdTRUE,
                                        pdTRUE,
                                        1); // portMAX_DELAY pdMS_TO_TICKS(1)
        EventMask = xHMIGroupValue;
    
        if(0UL != (EventMask & Gfx_Ev_RdrStart))
        {
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrInitDone));
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
    #if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine();
    #endif
            hmi_gfx_mgr02_layout_build_screen();
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrStart));
    #if defined(GFX_PERFORMANCE_MEASUREMENT)
            DispFrameRate();
    #endif
        }
        else if(0UL != (EventMask & Gfx_Ev_VSync))
        {
    #ifdef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
    #if GFX_NUM_ANIMATIONS > 0
            hmi_gfx_anim_engine_tick();
    #endif
    #endif
            if(hmi_gfx_mgr02_layout_is_render_done())
            {
               UI_RTE_GDT_CDD_RENDER_DONE();
            }
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_VSync));
        }
        else if(0UL != (EventMask & Gfx_Ev_RdrInit))
        {
            UI_RTE_GDTCDD_WATCHDOG_ENABLE_CALL();
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrDeinitDone));
    #ifdef GFX_MGR02_CHECKSUM_ENABLED
            if(GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
            {
              (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
              (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
            }
    #else
            hmi_gfx_mgr02_layout_initialize();
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrInit));
            (void)xEventGroupSetBits(xHMIEventGroup, Gfx_Ev_RdrInitDone);
    #endif
        }
        else if(0UL != (EventMask & Gfx_Ev_RdrDeinit))
        {
            UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
            hmi_gfx_mgr02_layout_shutdown();
            UI_RTE_GDTCDD_WATCHDOG_DISABLE_CALL();
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrDeinit));
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_VSync));
            (void)xEventGroupClearBits(xHMIEventGroup,EventMask & (Gfx_Ev_RdrStart));
            (void)xEventGroupSetBits(xHMIEventGroup, Gfx_Ev_RdrDeinitDone);
        }
        else
        {
            /*To fix MISRA warning.*/
        }
    }
    (void)pvParameters;
}
#elif defined(__ghs__)
TASK(OsTaskRender)
{
  EventMaskType EventMask;

  while(1)
  {
    (void)WaitEvent(Gfx_Ev_RdrStart|Gfx_Ev_VSync|Gfx_Ev_RdrInit|Gfx_Ev_RdrDeinit);
    (void)GetEvent(OsTaskRender, &EventMask);
    if((EventMaskType)0 != (EventMask & Gfx_Ev_VSync))
    {
#ifdef GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC
#if GFX_NUM_ANIMATIONS > 0
      hmi_gfx_anim_engine_tick();
#endif
#endif
      if(0U!=hmi_gfx_mgr02_layout_is_render_done())
      {
        UI_RTE_GDT_CDD_RENDER_DONE();
      }
      (void)ClearEvent(EventMask & (Gfx_Ev_VSync));
    }
    else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrStart))
    {
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

#ifdef GFX_MGR02_CHECKSUM_ENABLED
      if(GFX_MGR02_CHECKSUM_FAILED != hmi_gfx_mgr02_layout_initialize())
      {
        (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
        (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
      }
#else
      hmi_gfx_mgr02_layout_initialize();
      (void)ClearEvent(EventMask & (Gfx_Ev_RdrInit));
      (void)SetEvent(OsTaskRender,Gfx_Ev_RdrInitDone);
#endif

    }
    else if((EventMaskType)0 != (EventMask &  Gfx_Ev_RdrDeinit))
    {
      UI_RTE_GDTCDD_WATCHDOG_SERVICE_CALL();
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
#endif

static void framecomplete_cb(void)
{
    if((CmpStateType)eCmpState_Active == ((CmpStateType)(CmpState & CMPLIB_STATE_MASK)))
    {  
#if defined(__GNUC__)
        portBASE_TYPE taskToWake = pdFALSE, xResult = pdFAIL;
        
        xResult = xEventGroupSetBitsFromISR(xHMIEventGroup, Gfx_Ev_VSync,&taskToWake);
        
        if( xResult != pdFAIL )
        {
            portYIELD_FROM_ISR( taskToWake );
        }
#elif defined(__ghs__)
        (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);	
#endif
    }
}


#if defined(GFX_MGR02_IMXRT)
FUNC(void, GdtCdd_CODE) CGdtCdd_DispRdyStatus(P2VAR(UInt32, AUTOMATIC, RTE_GDTCDD_APPL_VAR) StatusPtr)
{
  *StatusPtr = hmi_gfx_mgr02_layout_get_disp_content_status();
}
#endif

#if defined(GFX_PERFORMANCE_MEASUREMENT)
static GFX_FLOAT ConvertDurationSec(UINT64 *pStart,UINT64 *pStop)
{
  return (((*pStop) - (*pStart))/1000000.0f);
}
static UINT64 Timer_GetTickCountUs(void)
{
  uint32 fl_elapsedtimevalue = (uint32)0;
  UI_RTE_TIMER_GET_ELAPSED_TIME(eTimerHandleGdtCdd, &fl_elapsedtimevalue );
  return ((UINT64)fl_elapsedtimevalue * 1000UL );
}

static void DispFrameRate(void)
{
  UINT64 curTime;
  /* HMI_CHAR fl_fps[15]; */
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
/*============================================================================
** Function Name:    gdtcdd_deactivate
** Description:      performs deactivation sewquence for gdtcdd
**                   
** Invocation:       
** Inputs/Outputs:   returns result
** Critical Section: None.
**==========================================================================*/
static Std_ReturnType gdtcdd_deactivate(void)
{
  Std_ReturnType Result = E_NOT_READY;
#if defined(__GNUC__)
  EventBits_t EventMask = 0UL;
  EventMask = xEventGroupGetBits(xHMIEventGroup);

    if ((0UL == (EventMask & Gfx_Ev_RdrDeinit)) && (0UL == (EventMask & Gfx_Ev_RdrDeinitDone)))
    {
        (void)xEventGroupSetBits(xHMIEventGroup, Gfx_Ev_RdrDeinit);
    }
    else
    {
      if (0UL != (EventMask & Gfx_Ev_RdrDeinitDone))
      {
          Result = E_OK;
      }
    }
#elif defined(__ghs__)
  EventMaskType EventMask;
  (void)GetEvent(OsTaskRender, &EventMask);
  
    if (((EventMaskType)0 == (EventMask & Gfx_Ev_RdrDeinit)) &&
        ((EventMaskType)0 == (EventMask & Gfx_Ev_RdrDeinitDone)))
    {
        (void)SetEvent(OsTaskRender, Gfx_Ev_RdrDeinit);
    }
    else
    {
      if ((EventMaskType)0 != (EventMask & Gfx_Ev_RdrDeinitDone))
      {
          Result = E_OK;
      }
    }
#endif
  return Result;
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
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

