/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** Name:          hmi_default.c
 **
 ** Description:   Implements the default init and schedular functionality
 **                for the simulation. Also  implements the default button 
 **                handler 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_DEFAULT_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_mgr02_cfg.h"

extern void ScrMainInit(void);
extern void ScrMainDeinit(void);

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : hmi_lsh_default_button_event_handler
Description          : Default button event handler for the application
Invocation           : invoked by view manager
Return Value         : button consumed status
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T * p_btn_command_id)
{
	return ((UINT8)LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
UINT8 scr_main_evt_hndlr(LSH_EVENT_HANDLER_STATUS_T* p_event_hndl_status_SP)
{
    return ((UINT8)LSH_STATUS_ABSORBED);
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
#ifndef GFX_MGR02_MMC_TEXT_AUTOMATION
void scr_main_present_hndlr(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
    switch (p_presen_hndl_status_SP->presentation_status)
    {
    case LSH_ACTIVATED_STATUS:
        (void)hmi_gfx_mgr02_if_set_screen(GFX_SCR_MAIN, TRUE);
        break;
    case LSH_REFRESH_STATUS:
        (void)hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_0, L"Dynamic Text Rendering");
        break;
    case LSH_DEACTIVATED_STATUS:
        break;
    default:
        break;
    }
}
#endif

void sct_txt_automation_pres_handler(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
    switch (p_presen_hndl_status_SP->presentation_status)
    {
    case LSH_ACTIVATED_STATUS:
        (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, TRUE);
        break;
    case LSH_REFRESH_STATUS:
#ifdef TEXT_AUTOMATION
        ChangeSID();
#else
        //(void)hmi_gfx_mgr02_if_set_text(GFX_TXT_TOYOTA, L"בחירת לחץ בצמיג קדמי");
        //(void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_NAME, L"ใช้ EPB โดยอัตโนมัติ ---- ใช้ EPB โดยอัตโนมัติ   --- ใช้ EPB โดยอัตโนมัติ");
        //hmi_gfx_mgr02_layout_set_text_scroll_parameter(GFX_TXT_SID_NAME_ANIM, 10);
#endif
        break;
    case LSH_DEACTIVATED_STATUS:
        (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, false);
        break;
    default:
        break;
    }
}


void scr_presentation_handler(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
  if (p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
  {
    hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 0);
  }
  else
  {
    hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 1);
    (void)hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_0, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    //hmi_gfx_mgr02_layout_set_text_scroll_parameter(GFX_TXT_SID_NAME_ANIM, 10);
  }
}
static int scrollOffset = 0;
void scr_scroll_present_handler(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
  if (p_presen_hndl_status_SP->presentation_status == LSH_DEACTIVATED_STATUS)
  {
    hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 0);
  }
  else
  {
    hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, 1);
    (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SCROLL_TEST, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    hmi_gfx_mgr02_layout_set_text_scroll_parameter(GFX_TXT_SCROLL_TEST_ANIM, scrollOffset++);
    if (scrollOffset > 100)
      scrollOffset = 0;

  }
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void hmi_welcome_animation_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

UINT32 hmi_clutchanimaton_goto_cb(UINT32 p_cur_step)
{
	return GFX_CLUTCHANIMATION_FRAME_1;
}

UINT32 hmi_warnblinkanimaton_goto_cb(UINT32 p_cur_step)
{
	return GFX_MINIPOPUPSLIDEUPSLIDEDOWN_FRAME_1;
}

UINT32 minipopupslideupslidedown_goto_cb(UINT32 p_cur_step)
{
	return GFX_WARNINGBLINKANIMATION_FRAME_1;
}

void hmi_spanner_anim_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

UINT32 hmi_spanner_goto_cb(UINT32 p_cur_step)
{
	return GFX_WARNINGBLINKANIMATION_FRAME_1;
}

UINT32 ICE_TT_blinkanimaton_goto_cb(UINT32 p_cur_step)
{
	return GFX_ICE_ANIM_FRAME_1;
}

void HMI_MiniPopupSlideUpSlideDown_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
	if (p_cur_frame == (UINT32)GFX_WARNINGBLINKANIMATION_FRAME_1)
	{
		(void)hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_MINIPOPUP_ANIM, 480);
	}
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_app_anim_done_cb
Description          : Default animation done callback
Invocation           : invoked by view manager
Return Value         : button consumed status
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id)
{

}

/*============================================================================
 **
 **============================================================================
 ** C M S    R E V I S I O N    N O T E S
 **============================================================================
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.
 ** 2.  Why the change was made and the intended result.
 **
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 **
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
