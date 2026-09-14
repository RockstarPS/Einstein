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
#include <TmExt_Cfg.h>
#include "hmi_logic_state_handler.h"
#include "hmi_view_manager_02_autocode.h"
#include "hmi_language_interface.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_menu_def_1.inc"
#include "hmi_menu_config_1.inc"

/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE(GdtCtrl)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit( void )
{
    // Place invocation to "hmi_gdt_ctrl_app_init()" and "hmi_lsh_initialize(0)" here !!
    hmi_language_initialize();
    hm_msg_KSColdInit();
    
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit( void )
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation( void )
{
    hmi_lsh_initialize((UINT8)0);
#ifdef TEXT_AUTOMATION
    (void)LSH_ADD_STATE((UINT8)GFX_SCR_TXT_AUTOMATION, (UINT8)ANIM_MAX_ID);
#elif defined GFX_MGR02_TV2_MONOTYPE
    (void)LSH_ADD_STATE((UINT8)GFX_SCR_TXT_AUTOMATION, (UINT8)ANIM_MAX_ID);
#elif defined GFX_MGR02_TV2_WINDOWS
    (void)LSH_ADD_STATE((UINT8)GFX_SCR_MAIN_MENU, (UINT8)ANIM_MAX_ID);
#endif
#if 0//text scrolling
    (void)LSH_ADD_STATE((UINT8)GFX_SCR_SCROLL, (UINT8)ANIM_MAX_ID);
#endif
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
    // Place invocation to "hmi_lsh_post_button_event(HMI_GOODBYE_EV)" here !!
    return  E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return The return value is disregarded. Say E_OK
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive( void )
{
    // This function is invoked on 8 ms when the Component (GdtCtrl) is in state "Active" ! (It is periodic "Task" function !)
    // Do periodic tasks/processing here !
	// In the SWA this is named as HmiViewManagerTask

    //Example how to activate the render task, which is in GdtCdd
    //It is not active until it receives event from GdtCtrl
    //GdtCtrl waits for corresponding event from the render task
    hm_msg_KSRRobin();
    (void)hmi_menu_logic_Menu_Reload(ROOT_MENU_ID);

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_NOT_OK;    // No Diagnostics Support, Currently !!
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_OK;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initiate a request to prepare for issue of a Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return Std_ReturnType:   E_OK  - Succeed, The requested Warning is ready to be issued (shown, played).
///<br>     E_NOT_READY:    The requested Warning is NOT ready to be issued.
///<br>     E_NOT_OK:       The request has Failed !
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GdtCtrl_Prepare(EWrnReason Reason, TWrnId Id)
{
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Cancel previous request for a Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Cancel(EWrnReason Reason, TWrnId Id)
{
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start (issue) previously prepared Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Latch(EWrnReason Reason, TWrnId Id)
{

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start (issue) previously prepared Warning with given Id.
///
/// @param  Id:  Id (Handle) of the Warning that is concerned
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_ListChange(TWrnListMask ListMask)
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "SpeedData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrlRef_SpeedDataRx ( void )
{
    // Do Some Processing HeRe !!
    // This notification function is invoked when SpdMdl component writes filtered value for "Vehicle Speed" to RTE (DataPool).
    // Read from DataPool the (eventually) changed value of SpeedData DataPool element and pass it to Gdt entity for processing !
    // Reading from RTE is accomplished with macro "Rte_Read_rpSR_rSpd_TISpdMdl_Out_Speed( &SpdF );"

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when "TachoData" DataPool element is written.
///
/// @param  None:  Function has no parameters.
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrlRef_TachoDataRx ( void )
{
    // Do Some Processing HeRe !!
    // This notification function is invoked when EngMdl component writes filtered value for "Engine RPM" to RTE (DataPool).
    // Read from DataPool the (eventually) changed value of TachoData DataPool element and pass it to Gdt entity for processing !
    // Reading from RTE is accomplished with macro "Rte_Read_rpSR_rEng_TIEngMdl_Out_Tacho( &TachoF );"

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function from TmExt component when Pulse channel changes its phase (Low->High and High->Low).
///
/// @param  Notification:  A pointer to structure "SPulseNotification"
///
/// @return None:  Function is of type void.
//---------------------------------------------------------------------------------------------------------------------
void CGdtCtrl_Impl_Notification ( const SPulseNotification *Notification )
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Called from HmiCtrl so GUI to be prepared for "Welcome".
///
/// @param  Id:  Id of HMI sub
///
/// @return E_OK:  GUI is ready for "Welcome"
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType CGdtCtrl_Impl_PrepareSub ( EHmiSubId Id )
{
	Std_ReturnType retval = E_OK;
    return retval;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Start GUI. Called from HmiCtrl.
///
/// @param  Id:  Id of HMI sub
//---------------------------------------------------------------------------------------------------------------------
void CGdtCtrl_Impl_Start ( EHmiSubId Id )
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notifies GdtCtrl about change in warning list
///
/// @param  ListMask: Indicates what types of warnings have changed
//---------------------------------------------------------------------------------------------------------------------
void GdtCtrl_Stop ( EHmiSubId Id )
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  GdtCtrl Diagnostic Port Runable 
///
/// @param  ListMask: Handle Diagnostic Service Requests processed by the component GdtCtrl
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType GdtCtrl_DiagAction(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Lenght, uint32 Id)
{
    return E_OK;
}

