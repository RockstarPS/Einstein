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
 ** Name:          hmi_warning_screen.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_WARNING_SCREEN_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/

#include "localSemaphores.h"
#include "hmi_popup_core_if.h"
#include "hmi_msgDefinition.h"
#include "hmi_msgSequencer.h"
#include "hmi_msgSequencer.cfg"
#include "hmi_language_identifiers.h"
#include "hmi_opening_screen.h"



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

const MSG_CONFIG_TABLE_T msg_config_table[] = {PRESENTATION_MSG_CONFIG_TABLE_LEVEL};

/****************************************************************************
Function Name        : hmi_msg_warn_get_status
Description          : Status function
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
SIF_STATUS hmi_msg_warn_get_status(UINT8 *Data, UINT8 Qualifier)
{
	*Data = WarningStatus[Qualifier];
	return sif_OK;
}

/****************************************************************************
Function Name        : hmi_msg_app_wrn_notify_status_cb
Description          : Individual callback function to notify
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
SIF_STATUS hmi_msg_app_wrn_notify_status_cb(UINT8 *Data, UINT8 Qualifier)
{
	return sif_OK;
}

/****************************************************************************
Function Name        : hmi_warning_show_notification
Description          : Show nofication
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_warning_show_notification(MSG_VIEWINFO_T * alertInfo)
{
  //hmi_gfx_mgr02_if_select_dwidget(GFX_DWDG_WRNG,alertInfo->Id);
  //hmi_gfx_mgr02_if_set_sid(msg_config_table[alertInfo->Id].Line1_Text_ID, msg_config_table[alertInfo->Id].Line_1_SID);
  hmi_popup_core_activate_popup(msg_config_table[alertInfo->Id].Pop_ID, ANIM_MAX_ID);
}

/****************************************************************************
Function Name        : hmi_warning_hide_notification
Description          : Hide nofication
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_warning_hide_notification(eMessageIdentity MessageID)
{
  hmi_popup_core_deactivate_popup(msg_config_table[MessageID].Pop_ID, ANIM_MAX_ID);
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
