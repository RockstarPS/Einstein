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
 ** Name:          hmi_opening_screen.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_OPENING_SCREEN_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"

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
Function Name        : scr_opening_anim_event
Description          : Event handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 scr_opening_anim_event(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP){
   if(LSH_IS_ANIM(p_event_hndl_status_SP->button_command)){
      /*
      ** Button event is received during an animation for this screen 
      */
      printf("Animation in progress, ignored request\n");
   }
   else
   {
   }
   /*
   ** Possible return values for a button event handler
   ** LSH_STATUS_ABSORBED - indicates that the button is absorbed by the button 
   **                       processing function and no further actions need to be performed.
   ** LSH_STATUS_ACTION   - indicates that the button event handler has performed 
   **                       some actions for the event.
   ** LSH_STATUS_NONE     - Button is not absorbed and no action also taken.
   ** Combinations are also possible
   ** (LSH_STATUS_ABSORBED|LSH_STATUS_ACTION) or (LSH_STATUS_NONE|LSH_STATUS_ACTION)
   */
   return(LSH_STATUS_ABSORBED);
}

/****************************************************************************
Function Name        : scr_opening_anim_focus
Description          : Focus handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_opening_anim_focus(LSH_FOCUS_HANDLER_STATUS_T * p_focus_hndl_status_SP){

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
   if(p_focus_hndl_status_SP->focus_status & LSH_ANIM_STARTED_STATUS){
      printf("Anim started Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
   if(p_focus_hndl_status_SP->focus_status & LSH_ANIM_COMPLETE_STATUS){
      printf("Anim complete Focus Status : %d\n", p_focus_hndl_status_SP->logic_state_id);
   }
}

/****************************************************************************
Function Name        : scr_opening_anim_pres
Description          : Presentation handler
Invocation           : invoked by view manager
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void scr_opening_anim_pres(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP){
    if(p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS){
       hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 1);
    }
    else if(p_presen_hndl_status_SP->presentation_status == LSH_REFRESH_STATUS){
    }
    else{ /* LSH_DEACTIVATED_STATUS */
       hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, 0);
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
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
