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

#include <Rte_GdtCtrl.h>
#include "Rte_GdtCtrl_Type.h"
#include <CmpLib.h>
#include <Os.h>
#include "GdtCtrl_Cfg.h"
#include "HmiSpecific.h"
#if defined(__GNUC__)
#include "event_groups.h"
#include "stub_legacy.h"
#endif
//brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCtrl)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static void Draw(void);
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
static boolean IsRenderReady    = (boolean)FALSE;
#endif
static boolean IsRenderBlocked  = (boolean)TRUE;
static boolean IsEarlyWakeup    = (boolean)FALSE;
#if defined(__GNUC__)
extern volatile EventGroupHandle_t xHMIEventGroup ;
#endif

//---------------------------------------------------------------------------------------------------------------------
/// brief  Calls presentation and perform draw if needed
///
/// return void
//---------------------------------------------------------------------------------------------------------------------
static void Draw(void)
{
    HmiSpecific_Active();

    hmi_lsh_task();
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    IsRenderBlocked = TRUE;
    IsRenderReady = FALSE;

    (void)Rte_Result_GdtCtrl_TIGdtCdd_StartRender();
    (void)Rte_Call_GdtCtrl_TIGdtCdd_StartRender();
#else
  #if defined(__GNUC__)
    (void)xEventGroupSetBits(xHMIEventGroup, Gfx_Ev_RdrStart);
  #elif defined(__ghs__)
    (void)SetEvent(OsTaskRender, Gfx_Ev_RdrStart);
  #endif
#endif
}

//---------------------------------------------------------------------------------------------------------------------
///brief  Transitional initialization state
///
///return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
#ifdef GDTCTRL_LANGUAGECORE_ENABLED
    hmi_language_initialize();
#endif

#ifdef GDTCTRL_POPUPCORE_ENABLED
    hmi_popup_core_initialize();
#endif

#ifdef GDTCTRL_MENUCORE_ENABLED
    hmi_menu_initialize();
#endif

    hmi_lsh_initialize((uint8)0);

    IsRenderBlocked = (boolean)TRUE;
    IsEarlyWakeup = (boolean)FALSE;

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  State for normal Wakeup operations
///
///return E_OK:           Succeed
//---------------------------------------------------------------------------------------------------------------------
#ifdef CMPLIB_WAKEUP_STATE_SUPPORT
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
static Std_ReturnType CmpWakeUp(void)
{
#ifdef GDTCTRL_LANGUAGECORE_ENABLED
    hmi_language_initialize();
#endif

#ifdef GDTCTRL_POPUPCORE_ENABLED
    hmi_popup_core_initialize();
#endif

#ifdef GDTCTRL_MENUCORE_ENABLED
    hmi_menu_initialize();
#endif

    hmi_lsh_initialize((uint8)0);

    IsRenderBlocked = (boolean)TRUE;
    IsEarlyWakeup = (boolean)FALSE;

    return E_OK;
}
#endif
#endif
//---------------------------------------------------------------------------------------------------------------------
///brief  Transitional de-initialization state
///
///return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    Std_ReturnType Result=E_NOT_READY;
#ifdef GFX_MGR02_MONOTFT    
    #ifdef GDTCDD_RENDERTASK_ALIGN_VSYNC
    EventMaskType EventMask;
    #endif
#endif	
    if(IsEarlyWakeup==(boolean)TRUE)
    {
        HmiSpecific_Init();
    }
#ifdef GFX_MGR02_MONOTFT
	(void)GetEvent(OsTaskRender, &EventMask);
	if((EventMaskType)0 !=(EventMask &  Gfx_Ev_RendererReady))
	{
		Result = HmiSpecific_Activate();
	}
    if(Result == E_OK)
	{
    	/*To initiate the lsh  task; we need to set this event once for Mono TFT.*/
        (void)SetEvent(OsTaskRender, Gfx_Ev_VSync);
		IsRenderBlocked= (boolean)FALSE;
	}
#else
    Result = HmiSpecific_Activate();
#endif	
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    if(Result == E_OK)
    {
        IsRenderBlocked = (boolean)FALSE;
        IsRenderReady   = (boolean)TRUE;
    }
#endif
    return Result;
}

//---------------------------------------------------------------------------------------------------------------------
///brief  Transitional de-activation state
///
/// return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
    IsEarlyWakeup=(boolean)TRUE;
    return HmiSpecific_Deactivate();
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  State for normal operations
///
/// return E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    IsRenderBlocked =(boolean)FALSE;
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    if((boolean)TRUE == IsRenderReady)
    {
        Draw();
    }
#endif
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Diagnostic state
///
/// return E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return CmpActive(); // No special behavior is defined for Diag mode yet
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
///return E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
#if (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS))
//---------------------------------------------------------------------------------------------------------------------
/// brief  Notification function from TmExt component when Pulse channel changes its phase (Low->High and High->Low).
///
/// param  Notification:  A pointer to structure "SPulseNotification"
///
/// return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Notification(const SPulseNotification *Notification)
{
    HmiSpecific_Notification(Notification);
}

//---------------------------------------------------------------------------------------------------------------------
/// brief  GdtCtrl Diagnostic Port Runable
///
/// param  ListMask: Handle Diagnostic Service Requests processed by the component GdtCtrl
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GdtCtrl_DiagAction(EDcmExtAction Action, uint8* Data, uint8* Lenght, uint32 Id)
{
    return HmiSpecific_DiagAction(Action, Data, Lenght, Id);
}
#endif
//---------------------------------------------------------------------------------------------------------------------
/// brief  Called when GfxMgr has completed the rendered the last frame and is ready to render next frame
///
/// param  ListMask: Handle Diagnostic Service Requests processed by the component GdtCtrl
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_RenderDone(void)
{
#ifndef GDTCDD_RENDERTASK_ALIGN_VSYNC
    if(TRUE == IsRenderBlocked)
    {
        IsRenderReady = TRUE;
    }
    else
    {
        Draw();
    }
#else
    if((boolean)FALSE == IsRenderBlocked)
    {
        Draw();
    }
#endif
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

