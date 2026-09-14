/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_logic.c
**
** Description:    This modules implements sample logic
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define HMI_PRESENTATION_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_logic_state_handler.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define BTN_OK_COMMAND       (LSH_GET_COMMAND(ButtonID_OK,    ButtonState_Pressed))
#define BTN_RIGHT_COMMAND    (LSH_GET_COMMAND(ButtonID_RIGHT, ButtonState_Pressed))
#define BTN_DOWN_COMMAND     (LSH_GET_COMMAND(ButtonID_DOWN,  ButtonState_Pressed))

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
UINT8 scn_8bpp_alpha_map_ev_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
   switch(p_event_hndl_status_SP->button_command)
   {
      case BTN_OK_COMMAND:     printf("GFX_SCN_8BPP_ALPHA_MAP - BTN_OK_COMMAND - (ButtonID_OK,    ButtonState_Pressed)\n");
							       return(LSH_STATUS_ABSORBED);
      case BTN_RIGHT_COMMAND :     printf("GFX_SCN_8BPP_ALPHA_MAP - BTN_RIGHT_COMMAND - (ButtonID_RIGHT,    ButtonState_Pressed)\n");
							       return(LSH_STATUS_ABSORBED);
      case BTN_DOWN_COMMAND: printf("GFX_SCN_8BPP_ALPHA_MAP - BTN_DOWN_COMMAND - (ButtonID_DOWN,    ButtonState_Pressed)\n");
							       return(LSH_STATUS_ABSORBED);
      default                    : printf("GFX_SCN_8BPP_ALPHA_MAP - bypassing events to next level\n");
							       return(LSH_STATUS_NONE);
   }
}

/*============================================================================
 ** Function Name:    
 ** Visibility:       Global
 ** Description:      
 ** Invocation:       
 ** Inputs:           
 ** Outputs:          
 ** Critical Section: None
 ** Created:          
 ** Updated:          
 **==========================================================================*/
void scn_8bpp_alpha_map_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
   if((p_focus_hndl_status_SP->focus_status & LSH_LOST_FOCUS_STATUS))
   {
      printf("GFX_SCN_8BPP_ALPHA_MAP - scn_8bpp_alpha_map_focus_handler - LSH_LOST_FOCUS_STATUS\n");
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_GOT_FOCUS_STATUS))
   {
      printf("GFX_SCN_8BPP_ALPHA_MAP - scn_8bpp_alpha_map_focus_handler - LSH_GOT_FOCUS_STATUS\n");
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_DEACTIVATED_STATUS))
   {
      printf("GFX_SCN_8BPP_ALPHA_MAP - scn_8bpp_alpha_map_focus_handler - LSH_DEACTIVATED_STATUS\n");
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_ANIM_COMPLETE_STATUS))
   {
      printf("GFX_SCN_8BPP_ALPHA_MAP - scn_8bpp_alpha_map_focus_handler - LSH_ANIM_COMPLETE_STATUS\n");
   }
   if((p_focus_hndl_status_SP->focus_status & LSH_ANIM_STARTED_STATUS))
   {
      printf("GFX_SCN_8BPP_ALPHA_MAP - scn_8bpp_alpha_map_focus_handler - LSH_ANIM_STARTED_STATUS\n");
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
** CMS Rev 01       11-JUNE-2012  ASHEKHAR
** Tracebility :    Initial Version
** Description :
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/

