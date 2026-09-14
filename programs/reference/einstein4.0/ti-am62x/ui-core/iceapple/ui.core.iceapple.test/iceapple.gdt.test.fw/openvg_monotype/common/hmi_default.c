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
#include <windows.h>
#include <conio.h>
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_dcu_sim_w32.h"
#include "dm_swch.h"

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
 ** E N T R Y   P O I N T pS  /  D A T A   A C C E S S   S E R V I C E S
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
   if(p_btn_command_id->button_command == LSH_GET_COMMAND(BTN_ID_POWER, BTN_EV_PRESS)){
   	  LSH_ADD_STATE(GFX_SCR_MAIN, ANIM_MAX_ID);
   } 
   return(LSH_STATUS_NONE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_app_anim_done_cb
Description          : Default animation done callback
Invocation           : invoked by view manager
Return Value         : button consumed status
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_app_anim_done_cb(UINT32 p_anim_id, UINT32 p_client_id){
   switch(p_anim_id){
		default:break;
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
