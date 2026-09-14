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
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
#include "hmi_gfx_mgr02_layout.h"
#endif
#include "GfxDrv2D_S6J3200Drv.h"
#ifndef GFX_MGR02_MONOTFT
#include "mmd_gdc_interrupthandler.h"
#endif
#include "UI_Rte_Interfaces_Cfg.h"
#include "os.h"


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
#ifndef GFX_MGR02_MONOTFT
static void OnIrisInterrupt(void);
#endif
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
static boolean IsRenderingStarted = FALSE;
#endif
#ifndef GFX_MGR02_MONOTFT
//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for all IRIS interrupts
///
///return void
//---------------------------------------------------------------------------------------------------------------------
static void OnIrisInterrupt(void)
{
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    BOOLEAN GfxMgrRes;
#endif
    // Allow 2D graphics driver to handle the interrupt first
    mmdGdcInterruptHandler();
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
        if(TRUE == IsRenderingStarted)
        {
            // Check via GfxMgr, if the latest scene has been send to TFT
            GfxMgrRes = hmi_gfx_mgr02_layout_is_render_done();
            if(GfxMgrRes == (BOOLEAN)TRUE)
            { // Notify all listeners that they can start preparation for next frame
                IsRenderingStarted = FALSE;
                UI_RTE_GDT_CDD_RENDER_DONE();
            }
        }
#endif
}
#endif
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional initialization state
//---------------------------------------------------------------------------------------------------------------------
void GfxDrv2D_S6J3200Drv_Init(void)
{
    UI_RTE_TIMER_START(eTimerHandleGdtCdd);
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-initialization state
//---------------------------------------------------------------------------------------------------------------------
void GfxDrv2D_S6J3200Drv_Deinit(void)
{
    UI_RTE_TIMER_STOP(eTimerHandleGdtCdd);
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GfxDrv2D_S6J3200Drv_Activate( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional de-activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GfxDrv2D_S6J3200Drv_Deactivate( void )
{
    return E_OK;
}
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
//---------------------------------------------------------------------------------------------------------------------
/// brief  Notify that the rendering is started
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
void GfxDrv2D_S6J3200Drv_OnStartRender(void)
{
    IsRenderingStarted = TRUE;
}
#endif
#ifndef GFX_MGR02_MONOTFT
//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 401 - 2D Graphics Core Command Sequencer
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler401)
{
    mmdGdcInterruptHandler();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 403 - 2D Graphics Core Drawing Engine
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler403)
{
    mmdGdcInterruptHandler();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 404 - 2D Graphics Content Stream0
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler404)
{
    mmdGdcInterruptHandler();

}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 405 - 2D Graphics Safety Stream0
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler405)
{
    OnIrisInterrupt();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 410 - 2D Graphics Content Stream1
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler410)
{
    mmdGdcInterruptHandler();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 411 - 2D Graphics Safety Stream1
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler411)
{
    OnIrisInterrupt();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Interrupt handler for IRQ 418 - 2D Graphics Storage Stream0
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
ISR(GFXInterruptHandler418)
{
    mmdGdcInterruptHandler();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Default Interrupt handler for Iris
///
/// return void
//---------------------------------------------------------------------------------------------------------------------

ISR(INTERRUPTS_IRQ_DEFAULT_HANDLER)
{

}
#endif
//---------------------------------------------------------------------------------------------------------------------
/// brief  Timer tick. Used by Iris library function
///
/// return Time in US from the initialization of the driver
//---------------------------------------------------------------------------------------------------------------------
uint64 Timer_GetTickCountUs(void)
{
    uint32 fl_elapsedtimevalue = (uint32)0;
    UI_RTE_TIMER_GET_ELAPSED_TIME(eTimerHandleGdtCdd, &fl_elapsedtimevalue );
    return ((uint64)fl_elapsedtimevalue * 1000UL );
}


//---------------------------------------------------------------------------------------------------------------------
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



