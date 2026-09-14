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

int sids_updated;

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
UINT32 l_compass_anim_complete = (UINT32)1;


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
	int index_incr=0;
	if(NULL != p_btn_command_id)
	{
		UINT16 BtnStatus =  LSH_GET_STATUS(p_btn_command_id->button_command);
		UINT16 BtnId     =  LSH_GET_ID(p_btn_command_id->button_command);

		if(BtnId == WELCOME_EV)
		{
		    if (BtnStatus == BTN_EV_PRESS)
		    {
                ScrMainInit();

                //(void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_WELCOME, (UINT32)0);

				(void)LSH_ADD_STATE((UINT8)GFX_SCR_MAIN, (UINT8)ANIM_MAX_ID);

				//int retTime = time(0) + 10;   // Get finishing time.
				//while (time(0) < retTime);
				/*(void)hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_1, HMI_TEXT((void*)"ABCDEFGHIJKLMNO"));
				(void)hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_2, HMI_TEXT((void*)"PQRSTUVWXYZabcdefg"));
				(void)hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_3, HMI_TEXT((void*)"hijklmnopqrstuvwxyz"));*/
				//(void)hmi_gfx_anim_play_fwd((UINT32)GFX_SCR_MAIN, (UINT32)GFX_CLUTCHANIMATION);
				//(void)hmi_gfx_anim_play_fwd((UINT32)GFX_SCR_MAIN, (UINT32)GFX_WARNINGBLINKANIMATION);
				//(void)hmi_gfx_anim_play_fwd((UINT32)GFX_SCR_MAIN, (UINT32)GFX_MINIPOPUPSLIDEUPSLIDEDOWN);

				//(void)LSH_ADD_STATE((UINT8)GFX_SCR_2, (UINT8)GFX_WELCOME_ANIMATION);
		    }
		    else if (BtnStatus == BTN_EV_RELEASE)
		    {
		        (void)LSH_REM_STATE((UINT8)GFX_SCR_MAIN, (UINT8)GFX_NUM_ANIMATIONS);
                
                ScrMainDeinit();
		    }
		    else
		    {

		    }
		}
	}

	return ((UINT8)LSH_STATUS_NONE);
}
/*
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

void HMI_MiniPopupSlideUpSlideDown_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
	if (p_cur_frame == (UINT32)GFX_WARNINGBLINKANIMATION_FRAME_1)
	{
		(void)hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_MINIPOPUP_ANIM, 480);
	}
}*/
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
