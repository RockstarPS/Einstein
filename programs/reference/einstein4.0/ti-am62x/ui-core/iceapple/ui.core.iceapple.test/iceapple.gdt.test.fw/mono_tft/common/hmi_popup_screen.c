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
 ** Name:          hmi_popup_screen.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_POPUP_SCREEN_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_popup_screen.h"
#include "hmi_language_identifiers.h"
#include "hmi_msgSequencer.h"


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
Function Name        : scr_info_popup_event_handler
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_info_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
	{
		hmi_popup_core_deactivate_popup(L1_INFO_POPUP_ID, ANIM_MAX_ID);
	}	
	return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : scr_info_popup_focus_handler
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_info_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
   if(p_focus_hndl_status_SP->focus_status & LSH_GOT_FOCUS_STATUS){
	  printf("Got Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
   if(p_focus_hndl_status_SP->focus_status & LSH_LOST_FOCUS_STATUS){
	  printf("Lost Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
   if(p_focus_hndl_status_SP->focus_status & LSH_DEACTIVATED_STATUS){
	  printf("Deactivated Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_DEACT_PENDING_STATUS) == LSH_DEACT_PENDING_STATUS){
	  printf("Deactivation pending Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
}

/****************************************************************************
Function Name        : scr_info_popup_presentation_handler
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_info_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	{
		hmi_gfx_mgr02_layout_set_sid(GFX_TXT_INFO_POPUP,SID_INFO_POPUP);
		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS){
	}
	else{ /* LSH_DEACTIVATED_STATUS */
	   hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
	}
}

/****************************************************************************
Function Name        : scr_progress_popup_event_handler
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_progress_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
	{
		hmi_popup_core_deactivate_popup(L1_PROGRESS_POPUP_ID, ANIM_MAX_ID);
	}		
	return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : scr_progress_popup_focus_handler
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_progress_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{

}

/****************************************************************************
Function Name        : scr_progress_popup_presentation_handler
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_progress_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	UINT8 fl_prog_bar_cnt_U8        = 0xFF;  
	POPUP_PROGRESS_COUNT_TYPE fl_progressbar_count_S;
	
	if(p_presen_hndl_status_SP->presentation_status != LSH_DEACTIVATED_STATUS)
	{
		 fl_progressbar_count_S.popup_id   = L1_PROGRESS_POPUP_ID;
		 fl_progressbar_count_S.cnt_ptr_U8 = &fl_prog_bar_cnt_U8;
		 (void)hmi_popup_core_get_progress_bar_counter(&fl_progressbar_count_S);
		 hmi_gfx_mgr02_layout_set_sid(GFX_TXT_PROGRESS,SID_PROGRESS_POPUP);
		 hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_PROGRESS,fl_prog_bar_cnt_U8);
		 hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else{
	   hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
	}
}

/****************************************************************************
Function Name        : hmi_progress_popup_status_handler
Description          : Status handler
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_progress_popup_status_handler(POPUP_EVENTS p_event_e)
{
	UINT8 fl_prog_bar_cnt_U8        = 0xFF;  
	POPUP_PROGRESS_COUNT_TYPE fl_progressbar_count_S;
  
	fl_progressbar_count_S.popup_id   = L1_PROGRESS_POPUP_ID;
  fl_progressbar_count_S.cnt_ptr_U8 = &fl_prog_bar_cnt_U8;
 
  switch(p_event_e)
  {
  case POPUP_PROGRESS_BAR_INC_EVT:
		(void)hmi_popup_core_get_progress_bar_counter(&fl_progressbar_count_S);
    if(fl_prog_bar_cnt_U8 == 22 + 1)
		{
			   hmi_popup_core_deactivate_popup(L1_PROGRESS_POPUP_ID, ANIM_MAX_ID);
				(void)hmi_popup_core_stop_timer(L1_PROGRESS_POPUP_ID);
			}
			break;
  default:
    break;
  }
}

/****************************************************************************
Function Name        : scr_ack_popup_event_handler
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_ack_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
	{
		hmi_popup_core_deactivate_popup(L1_ACK_POPUP_ID, ANIM_MAX_ID);
	}		
	return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : scr_ack_popup_focus_handler
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_ack_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{

}

/****************************************************************************
Function Name        : scr_ack_popup_presentation_handler
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_ack_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	if(p_presen_hndl_status_SP->presentation_status != LSH_DEACTIVATED_STATUS)
	{
		 hmi_gfx_mgr02_layout_set_sid(GFX_TXT_ACK_POPUP,SID_ACK_POPUP); 
		 hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else
	{
	   hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
	}
}

/****************************************************************************
Function Name        : scr_keypad_popup_event_handler
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_keypad_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	POPUP_KEYPAD_SET_TYPE fl_keypad_set;

	fl_keypad_set.popup_id = L1_KEYPAD_POPUP_ID;
	fl_keypad_set.btn_state = BTN_EV_PRESS;
	
	if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
	{
		/* Delete event is now configured with BTN_ID_MAX so the button id is given */
		fl_keypad_set.btn_id = BTN_ID_MAX;
		hmi_popup_core_set_keypad_entry(&fl_keypad_set);
		hmi_popup_core_deactivate_popup(L1_KEYPAD_POPUP_ID, ANIM_MAX_ID);
		return (LSH_STATUS_ABSORBED);
	}
	return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : scr_keypad_popup_focus_handler
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_keypad_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{

}

/****************************************************************************
Function Name        : scr_keypad_popup_presentation_handler
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_keypad_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	UINT8 keypadcounter;
  HMI_CHAR keypad_data[10+1];

	POPUP_KEYPAD_CONTENT_TYPE fl_keypad_content;
	fl_keypad_content.popup_id = L1_KEYPAD_POPUP_ID;
	fl_keypad_content.entry = keypad_data;
	/* The lenght of the keypad entry is 10 */
	fl_keypad_content.len_U8 = 10;
	
	keypadcounter =  hmi_popup_core_get_keypad_content(&fl_keypad_content);

	if(p_presen_hndl_status_SP->presentation_status != LSH_DEACTIVATED_STATUS)
	{
		 hmi_gfx_mgr02_layout_set_sid(GFX_TXT_KEYPAD_TEXT,SID_KEYPAD_POPUP); 
		 hmi_gfx_mgr02_layout_set_text(GFX_TXT_KEYPAD_ENTRY,fl_keypad_content.entry); 		 
		 hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else{
	   hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
	}
}

/****************************************************************************
Function Name        : scr_warning_popup_event_handler
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_warning_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
	{
		(void)msg_SequencerAction(BTN_ID_ENTER);
	}
	return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : scr_warning_popup_focus_handler
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_warning_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
    if(p_focus_hndl_status_SP->focus_status & LSH_GOT_FOCUS_STATUS){
	  printf("Got Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
		msg_SequencerShow(); 
   }
   if(p_focus_hndl_status_SP->focus_status & LSH_LOST_FOCUS_STATUS){
	  printf("Lost Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
   if(p_focus_hndl_status_SP->focus_status & LSH_DEACTIVATED_STATUS){
	  printf("Deactivated Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
		msg_SequencerHide();
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_DEACT_PENDING_STATUS) == LSH_DEACT_PENDING_STATUS){
	  printf("Deactivation pending Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }

}

/****************************************************************************
Function Name        : scr_warning_popup_presentation_handler
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_warning_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	MSG_VIEWINFO_T retData = {0};

	if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
	{
        msg_SequencerGetAlertInfo(&retData);
		hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_WRNG,retData.Id);
        hmi_gfx_mgr02_layout_set_sid(msg_config_table[retData.Id].Line1_Text_ID, msg_config_table[retData.Id].Line_1_SID);
		hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
	}
	else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS){
	}
	else{ /* LSH_DEACTIVATED_STATUS */
	   hmi_gfx_mgr02_layout_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
	}
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
 ** CMS Rev 1.0      19-Mar-2015    ADEVI
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif