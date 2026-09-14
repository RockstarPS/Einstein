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
 ** Name:          hmiapp_stub.c
 **
 ** Description:   Implements the screen logic and presentation for opening
 **                screen
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
 /*============================================================================
  ** I N C L U D E   F I L E S
  **==========================================================================*/
#include "Rte_Type.h"
#include "hmiapp_stub.h"
#include "hmi_timer_support.h"
#include "hmi_menu_def_1.inc"
#include "hmi_menu_core_01_logic.h"
#include "hmi_gfx_mgr02_cfg.h"
#include "di_warnings_constants.inc"

#define MAX_WARNING (UI_NULL_WARNING_ID+(UI_WARNING_ID_T)1)
#define MODE_GAUGE_SPEEDO 0
#define MODE_GAUGE_REGEN 1

static void WarnView_master_warn_lamp_update(UINT8 p_warning_id, BOOLEAN p_warn_lamp_status);
static void WrnView_clear_warning_status(UI_WARNING_ID_T warning_id);
void ui_get_warning_status(UI_WARNING_ID_T  warning_id, UI_PTR_WARNING_DATA_T ptr_warning_data);

static boolean l_mode_tick = MODE_GAUGE_SPEEDO;
static boolean l_ui_warning_display_status_array[MAX_WARNING];
static UI_WARNING_DATA_T l_ui_warnings_status_array[MAX_WARNING];

/****************************************************************************
Function Name        : hmi_timer_support_start_timer
Description          : Start timer interface
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_timer_support_start_timer(TIMER_ID_TYPE timer_id, UINT16 timeout_count, UINT16 p_evt_U16)
{}

/****************************************************************************
Function Name        : hmi_timer_support_clear_timer
Description          : Stop timer interface
Invocation           : invoked by popup core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_timer_support_clear_timer(TIMER_ID_TYPE timer_id)
{}

/****************************************************************************
Function Name        : hmi_timer_support_check_timer
Description          : Check timer interface
Invocation           : invoked by popup core
Return Value         : TIMER_CLEAR
          HMI_TIMER_EXPIRED
          HMI_TIMER_RUNNING
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_timer_support_check_timer(TIMER_ID_TYPE timer_id)
{}

/****************************************************************************
Function Name        : hmi_wrn_ctrl_start_timer
Description          : Start timer interface
Invocation           : invoked by warning control
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_wrn_ctrl_start_timer(WARNING_TIMER_ID_TYPE timer_id, UINT32 timeout_count)
{}

/****************************************************************************
Function Name        : hmi_menu_core_stop_timer
Description          : Stop timer interface
Invocation           : invoked by menu core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_wrn_ctrl_stop_timer(UINT8 menu_id, UINT8 timer_id)
{}

/****************************************************************************
Function Name        : hmi_wrn_ctrl_check_timer
Description          : Check timer interface
Invocation           : invoked by wrn control
Return Value         : TIMER_CLEAR
          HMI_TIMER_EXPIRED
          HMI_TIMER_RUNNING
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_wrn_ctrl_check_timer(WARNING_TIMER_ID_TYPE timer_id)
{
  return 0;
}

/****************************************************************************
Function Name     : ui_msg_get_current_ign_status
Description       : Function used to get the current IGN status.
Invocation        : MSG application
Parameters        : None
Return Value      : IGN Status
            - UI_MSG_IGN_ON / UI_MSG_IGN_OFF
Critical Section  : None
 ******************************************************************************/
UINT8 ui_msg_get_current_ign_status(void)
{
  return UI_MSG_IGN_ON;
}

static void WarnView_master_warn_lamp_update(UINT8 p_warning_id, BOOLEAN p_warn_lamp_status)
{}

/*****************************************************************************
Function Name    : ui_msg_get_status
Description      : Used to get the msg status from App's
Invocation       : MSG core
Parameters       : UINT8 *Data
              - Poniter to varibale, Holds msg status
          UINT8 Qualifier
              - msg identifier
Return Value     : SIF_STATUS
Critical Section : None
*****************************************************************************/
SIF_STATUS ui_msg_get_status(UINT8* Data, UINT8 Qualifier)
{
  UINT8 fl_msg_status_U8;
  UI_WARNING_DATA_T  fl_warning_info_S;

  /* Allocate memory for the warning structure */
  (void)memset(&fl_warning_info_S, 0, sizeof(UI_WARNING_DATA_T));
  fl_msg_status_U8 = (UINT8)MSG_CONDITION_OFF;
  /* Get the Warning information from App's */
  ui_get_warning_status((UI_WARNING_ID_T)Qualifier, &fl_warning_info_S);

  fl_msg_status_U8 = (UINT8)fl_warning_info_S.status;

  /* Update warning status */
  *Data = fl_msg_status_U8;

  return (sif_OK);
}

/****************************************************************************
Function Name     : ui_get_warning_status

Description       : This function will get the warning data from buffer

Invocation        : Invoked by HMI application.

Parameters        : None.

Return Type       : None.

Critical Section  : None.

******************************************************************************/
void ui_get_warning_status(UI_WARNING_ID_T  warning_id, UI_PTR_WARNING_DATA_T ptr_warning_data)
{
  if (warning_id < UI_NULL_WARNING_ID)
  {
    if (c_warning_detail_U16A[warning_id].warndetailptr != NULL)
    {
      c_warning_detail_U16A[warning_id].warndetailptr(&(l_ui_warnings_status_array[warning_id].payload));
    }
    else
    {

    }
    *ptr_warning_data = l_ui_warnings_status_array[warning_id];
  }
  else
  {
    (void)memset(ptr_warning_data, 0, sizeof(UI_WARNING_DATA_T));
  }

}

/****************************************************************************
Function Name     : ui_msg_notify_status_cb
Description       : This fucntions used to get the msg status from App's.
          UI_MSG_UNIT_TESTING macro shall be used to bypass application
          So that we can perform unit testing of warning by changing
          the warning status
Invocation        : MSG core
Parameters        : None
Return Value      : True/False
Critical Section  : None
******************************************************************************/
SIF_STATUS ui_msg_notify_status_cb(UINT8* Data, UINT8 Qualifier)
{
  return (sif_OK);
}

/****************************************************************************
Function Name     : ui_msg_show_new_msg_notification
Description       : This function shall be called whenever a new Msg needs to
          be displayed. This receives a High priority Alert info
          from Msg Core and Activates respective Pop-up.
Invocation        : MSG core
Parameters        : MSG_VIEWINFO_T * p_msg_info_S
            - Holds current active msg information
Return Value      : None
Critical Section  : None
 ******************************************************************************/
void ui_msg_show_new_msg_notification(const MSG_VIEWINFO_T* p_msg_info_S)
{
  (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, \
    GFX_DWDG_CENTERSCRN_SEL_IDX_WARNINGAREA);

}

/****************************************************************************
Function Name     : ui_msg_hide_msg_notification
Description       : To process the Message core request to remove/hide message
Invocation        : MSG core
Parameters        : eMessageIdentity p_MsgId_E
            - Current active msg
Return Value      : None
Critical Section  : None
 ******************************************************************************/
void ui_msg_hide_msg_notification(eMessageIdentity p_MsgId_E)
{
  (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, 255);
}

/****************************************************************************
Function Name     : WrnView_Set_Warning

Description       : This function will make warning status to "ON"
          Assigns corresponding payloads and event status as "NONE"

Invocation        : Invoked by warning application.

Parameters        : uint8.

Return Type       : None.

Critical Section  : None.

******************************************************************************/
FUNC(void, WrnView_CODE) CWrnView_Set_Warning(UInt8 WarningID)
{
  MSG_MESSAGE_STRUCT Group = messageList[(UI_WARNING_ID_T)WarningID];
  if (l_ui_warning_display_status_array[WarningID] == (uint8)FALSE)
  {
    if (WarningID < (uint8)UI_NULL_WARNING_ID)
    {
      l_ui_warnings_status_array[WarningID].status = UI_WARNING_STATUS_ON;
      l_ui_warnings_status_array[WarningID].event = UI_WARNING_EVENT_NONE;

      if (c_warning_detail_U16A[WarningID].warndetailptr != NULL)
      {
        /* Calling corresponding payload funcion and updates payload */
        c_warning_detail_U16A[WarningID].warndetailptr(&(l_ui_warnings_status_array[WarningID].payload));
      }
      else
      {
        /* Assigns default value (UI_U16_INVALID_VALUE) to the payload */
        l_ui_warnings_status_array[WarningID].payload = UI_U16_INVALID_VALUE;
      }
      /* To Update master warning lamp status */
      WarnView_master_warn_lamp_update(WarningID, TRUE);
    }
  }
  else
  {
    /* Do nothing */
  }
  /*	di_warn_hold_popup_check_if_set_before_clear(WarningID);*/
}

/****************************************************************************
Function Name     : WrnView_Clear_Warning

Description       : This fucntion will TURN OFF the warning status
          assigns Payload and Trigger Event to NONE of the
          corresponding warning ID.

Invocation        : Invoked by warning application.

Parameters        : None.

Return Type       : None.

Critical Section  : None.

******************************************************************************/
FUNC(void, WrnView_CODE) CWrnView_Clear_Warning(UInt8 WarningID)
{
  if (WarningID < (UINT8)UI_NULL_WARNING_ID)
  {
    WrnView_clear_warning_status((UI_WARNING_ID_T)WarningID);
  }
}

/****************************************************************************
Function Name     : WrnView_clear_warning_status

Description       : This fucntion will TURN OFF the warning status
          assigns Payload and Trigger Event to NONE of the
          corresponding warning ID.

Invocation        : Local.

Parameters        : None.

Return Type       : None.

Critical Section  : None.

******************************************************************************/
static void WrnView_clear_warning_status(UI_WARNING_ID_T warning_id)
{
  if (warning_id < UI_NULL_WARNING_ID)
  {
    l_ui_warnings_status_array[warning_id].status = UI_WARNING_STATUS_OFF;
    l_ui_warnings_status_array[warning_id].event = UI_WARNING_EVENT_NONE;
    l_ui_warnings_status_array[warning_id].payload = UI_U16_INVALID_VALUE;
  }
}

void hmi_menu_app_store_MenuID(MENU_LIST_ID_T p_menuID_e)
{}

void hmi_menu_app_stop_timer(MENU_LIST_ID_T fl_menu_id_U8, UINT8 fl_timerid)
{}

void hmi_menu_app_store_menu_item(MENU_LIST_ID_T p_menuID_e, UINT16 p_item_val_U16)
{}

UINT16 hmi_menu_app_get_stored_menu_item(MENU_LIST_ID_T p_menuID_e)
{}

void hmi_menu_app_start_timer(MENU_LIST_ID_T fl_menu_id_U8, UINT8 fl_timerid)
{}

UINT8 hmi_menu_root_items_config_callback(UINT16 p_entry_val_U16, MENU_LIST_ID_T p_menu_ID_e)
{
  UINT8 Return_item_status = MENU_ITEM_CONFIG_INACTIVE;
  switch (p_entry_val_U16)
  {
  case ROOT_MENU_ITEM_ROOT_TRIPCOMP_ECO_GROUP:
    Return_item_status = MENU_ITEM_CONFIG_ACTIVE;
    break;
  default:
    Return_item_status = MENU_ITEM_CONFIG_INACTIVE;
    break;
  }
  return(Return_item_status);
}

MENU_CB_RESULT_T hmi_menu_root_callback(MENU_ACTION_T p_menu_action, MENU_CONTROL_T* hmi_menu_app, UINT16_T p_button_command_U16)
{
  MENU_CB_RESULT_T		fl_cb_return = MENU_BTN_NONE;

  hmi_menu_logic_Menu_Open(TRIPCOMP_ECO_GROUP_MENU_ID, ANIM_MAX_ID);
  fl_cb_return = MENU_CB_ACTION_COMPLETED;

  return(fl_cb_return);
}

UINT8 hmi_menu_tc_group_items_config_callback(UINT16 p_entry_val_U16, MENU_LIST_ID_T p_menu_ID_e)
{
  UINT8 Return_item_status = MENU_ITEM_CONFIG_INACTIVE;

  if (p_entry_val_U16 == TRIPCOMP_ECO_GROUP_MENU_ITEM_DC_STANDARD_TRIP)
  {
    Return_item_status = MENU_ITEM_CONFIG_ACTIVE;
  }

  return(Return_item_status);
}

MENU_CB_RESULT_T hmi_menu_tc_group_callback(MENU_ACTION_T p_menu_action, MENU_CONTROL_T* hmi_menu_app, UINT16_T p_button_command_U16)
{
  MENU_CB_RESULT_T		fl_cb_return = MENU_BTN_NONE;
}

void hmi_menu_root_presentation_handler(MENU_CONTROL_T* p_menu_control_SP, UINT8_T p_lsh_status_U8)
{
  switch (p_lsh_status_U8)
  {
  case LSH_ACTIVATED_STATUS:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, \
      GFX_DWDG_CENTERSCRN_SEL_IDX_MAINMENU);
    break;
  case LSH_REFRESH_STATUS:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, \
      GFX_DWDG_CENTERSCRN_SEL_IDX_MAINMENU);
    break;
  case LSH_DEACTIVATED_STATUS:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, 255);
    break;
  }
}

void hmi_menu_tc_group_presentation_handler(MENU_CONTROL_T* p_menu_control_SP, UINT8_T p_lsh_status_U8)
{
  MENU_CB_RESULT_T		fl_cb_return = MENU_BTN_NONE;
}

void hmi_set_warning(void)
{
  CWrnView_Set_Warning(UI_WARNING_DOOR_OPEN_WITH_SPEED);
}

void hmi_clear_warning(void)
{
  CWrnView_Clear_Warning(UI_WARNING_DOOR_OPEN_WITH_SPEED);
  //(void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_CENTERSCRN_SEL, 255);
}

void hmi_add_menu(void)
{
  (void)hmi_menu_logic_Menu_Open(ROOT_MENU_ID, ANIM_MAX_ID);
}

void hmi_close_menu(void)
{
  (void)hmi_menu_logic_Menu_Close(ROOT_MENU_ID, ANIM_MAX_ID);
}

void hmi_toggle_mode(void)
{
  if (MODE_GAUGE_SPEEDO == l_mode_tick)
  {
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDGT_GAUGE, GFX_DWDGT_GAUGE_IDX_SPEEDO);
    l_mode_tick = MODE_GAUGE_REGEN;
  }
  else
  {
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDGT_GAUGE, GFX_DWDGT_GAUGE_IDX_REGEN);
    l_mode_tick = MODE_GAUGE_SPEEDO;
  }
}