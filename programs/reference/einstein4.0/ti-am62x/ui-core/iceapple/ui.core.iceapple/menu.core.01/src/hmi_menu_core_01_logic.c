/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2010. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_menu_core_01_logic.c
**
** Description:
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_MENU_CORE_01_LOGIC_C
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_menu_core_01_logic.h"
#ifndef MATLAB_MEX_FILE
#include "hmi_menu_core_01_model_autocode.h"
#include "hmi_menu_core_01_chart.h"
#endif
#ifdef HMI_MENU_CORE_UINT_TEST_ENABLE
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
/* Version check for menu core and menu core tool */
#define HMI_MENU_CORE_LABEL       "MENU_CORE_LABEL::ss-UI-FRAMEWORKS-ICEAPPLE-4.30"
#define HMI_MENU_CORE_MAJOR_VERSION     4
#define HMI_MENU_CORE_MINOR_VERSION     30

#define HMI_MENU_CORE_VERSION  ((HMI_MENU_CORE_MAJOR_VERSION * 100) + HMI_MENU_CORE_MINOR_VERSION)   

#if HMI_MENU_CORE_VERSION != HMI_MENU_CORE_TOOL_VERSION
#pragma message (HMI_MENU_CORE_TOOL_LABEL)
#pragma message (HMI_MENU_CORE_LABEL)
#error  The above Menu core and its tool version are mismatched. Please verify
#endif

#if defined(HMI_MENU_ITEM_CONFIG_FEATURE_FOR_DYN_MENU) && !defined(HMI_MENU_ITEM_CONFIG_FEATURE)
#error  The item config feature should be used if HMI_MENU_ITEM_CONFIG_FEATURE_FOR_DYN_MENU is enabled
#endif

#define MENU_INVALID_ENTRY           (0xFFFFU)
#define MENU_INVALID_MENU_ID             (-1)
#define MENU_GET_SCREEN_ID                 1
#define MENU_GET_MENU_ID                   0

#define HMI_MENU_LEVEL_0               (0x00U)
#define HMI_MENU_LEVEL_1               (0x01U)
#define HMI_MENU_LEVEL_2               (0x02U)
#define HMI_MENU_CB_CLOSE_ANIM_MASK    (0x00FFU)
#define FNULL                            NULL

#define HMI_MENU_INST_INVALID          (0xFF)
#define HMI_MENU_LOGIC_INST_QUEUE_FREE (0xFF)


#ifndef HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT
#define HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT               HMI_MENU_FOCUS_ENTRY_REBUILD_DEFUALT
#endif 
#ifndef HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT
#define HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT				   HMI_MENU_FOCUS_ENTRY_RELOAD_DEFUALT
#endif 

/*****************************************************************************
*                                Manifest Constants                          *
*----------------------------------------------------------------------------*
* Definition of    constant shall be followed by a comment that explains the *
* purpose of the constant.                                                   *
******************************************************************************/
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/* Points to the current Menu which is align with the LSH focus*/
static MENU_CONTROL_T *Current_focus_menu_ptr;
static UINT8           Current_focus_menu_inst_no_U8;
/* Array having the Menu Instances */
static MENU_CONTROL_T  l_menu_instance_array[NB_OF_MENU_INSTANCE];
/* Holds the Number of Instance value currently */
static SINT8           l_nb_of_active_instance_S8;
/* Hold the status of the fast scroll end of list*/
static BOOLEAN         l_end_of_fast_scroll_BOOL;
/* Array having the menu action chart instances */
static SFhmi_menu_core_01_chartInstanceStruct l_menu_core_chart_inst_array[NB_OF_MENU_INSTANCE];
#if defined(LSH_ANIMATION_SUPPORT_ENABLED) && defined(HMI_MENU_SMOOTH_FAST_ANIMATION)
/* Hold the recent screen id during fast button action*/
static LSH_STATE_ID_T  l_screen_id_in_queue;
#endif

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
static void hmi_menu_logic_create_menu(MENU_LIST_ID_T p_menu_id_e, UINT8 p_menu_inst_val_U8);

static void hmi_menu_logic_Set_ParentFocus(MENU_CONTROL_T *p_menu_cntrl_ptr, const MENU_DEF_T *p_sub_menu_ptr);

static MENU_CB_RESULT_T hmi_menu_logic_SubMenu_Open(const MENU_DEF_T *p_open_submenu_ptr, const MENU_DEF_T *p_current_menu_ptr, UINT8 p_menu_inst_U8, MENU_ACTION_T p_menu_action_e);

static void hmi_menu_logic_View_Mngr_Rq(MENU_LIST_ID_T fl_menu_id_E, LSH_STATE_ID_T fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	, UINT8 fl_anim_id_U8
#endif
	, UINT8 fl_screen_action_U8);

static MENU_LIST_ID_T hmi_menu_logic_get_menu_index(const MENU_DEF_T *fl_menu_ID_ptr);

static MENU_CB_RESULT_T hmi_menu_logic_button_processing(MENU_CONTROL_T *fl_current_active_menu_SP,UINT16 p_button_command_U16);
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
static BOOLEAN hmi_menu_logic_FS_process_valid_Btn(UINT16 p_button_command_U16);
#endif

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
static UINT8 hmi_menu_logic_get_animation_ID(MENU_ANIM_DATA_T * fl_menu_anim_data_ptr, MENU_CB_RESULT_T p_menu_cb_action_e);
static MENU_CB_RESULT_T hmi_menu_logic_CB_result_anim(MENU_ANIM_DATA_T  *fl_menu_anim_data, MENU_CB_RESULT_T p_CB_result_e);
static MENU_CB_RESULT_T hmi_menu_logic_get_down_animation(UINT16 fl_start_focus_entry_U16,UINT16 fl_start_focus_line_U16, MENU_CONTROL_T const *p_menu_cntrl_SP);
static MENU_CB_RESULT_T hmi_menu_logic_get_up_animation(UINT16 fl_start_focus_entry_U16,UINT16 fl_start_focus_line_U16, MENU_CONTROL_T const *p_menu_cntrl_SP);
#endif

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
static void hmi_menu_logic_load_absl_index(MENU_CONTROL_T *p_menu_cntrl_ptr);
static void hmi_menu_logic_set_valid_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP, UINT16 p_store_focused_entry_U16);
static void hmi_menu_logic_intialize_load_absl_index(MENU_CONTROL_T *p_menu_cntrl_ptr);
static UINT16 hmi_menu_logic_get_next_free_absl_index(MENU_CONTROL_T const *p_menu_cntrl_ptr);
static UINT16 hmi_menu_logic_arrange_absl_index(MENU_CONTROL_T *p_menu_cntrl_ptr);
#endif
static UINT16 hmi_menu_logic_get_item_indx_frm_prnt_submenu(const MENU_DEF_T *p_parent_menu_def_ptr, const MENU_DEF_T *p_submenu_menu_def_ptr);

static UINT8 hmi_menu_logic_get_Menu_level(MENU_LIST_ID_T p_menu_ID_e);
static MENU_CB_RESULT_T hmi_menu_logic_left_menu_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8);
static UINT8 hmi_menu_logic_create_menu_instance(MENU_LIST_ID_T p_open_menu_id_e);
static void hmi_menu_logic_destroy_menu_instance(MENU_LIST_ID_T  fl_close_menu_id_e);
static void hmi_menu_logic_update_current_focus_menu_ptr(void);
static MENU_CB_RESULT_T hmi_menu_logic_UP_action(MENU_CONTROL_T *p_menu_cntrl_SP);
static MENU_CB_RESULT_T hmi_menu_logic_DOWN_action(MENU_CONTROL_T *p_menu_cntrl_SP);
static MENU_CB_RESULT_T hmi_menu_logic_LEFT_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8);
static MENU_CB_RESULT_T hmi_menu_logic_RIGHT_action(MENU_CONTROL_T *p_menu_cntrl_SP);
static MENU_CB_RESULT_T hmi_menu_logic_OK_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8);
static MENU_CB_RESULT_T hmi_menu_logic_Other_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8);
static void hmi_menu_logic_enable_open_timer_status(MENU_LIST_ID_T fl_menu_id_U8);
static void hmi_menu_logic_disable_open_timer_status(MENU_LIST_ID_T fl_menu_id_U8);
static BOOLEAN hmi_menu_logic_is_open_timer_enabled(MENU_LIST_ID_T fl_menu_id_U8);
static void hmi_menu_logic_process_menu_close(UINT8 fl_menu_close_action_U8, MENU_LIST_ID_T p_close_menu_id_e
                                                   #ifdef LSH_ANIMATION_SUPPORT_ENABLED
						                      	   ,UINT8 p_menu_anim_ID_U8
						                           #endif
							                       );
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
static void hmi_menu_logic_update_history_info(MENU_CONTROL_T const *p_menu_cntrl_SP);
#endif
static void hmi_menu_logic_down_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP);
static void hmi_menu_logic_up_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP);
static void hmi_menu_logic_incr_till_valid_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
	, UINT16 fl_end_focus_entry_U16
#endif
	);
static void hmi_menu_logic_decr_till_valid_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
	,UINT16 fl_end_focus_entry_U16
#endif
);
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
static BOOLEAN hmi_menu_logic_handle_greyout_for_decr(MENU_CONTROL_T *p_menu_cntrl_SP,UINT16 *p_start_focus_line_U16);
static BOOLEAN hmi_menu_logic_handle_greyout_for_incr(MENU_CONTROL_T *p_menu_cntrl_SP, UINT16 *p_start_focus_line_U16);
#endif
static BOOLEAN hmi_menu_logic_incr_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP);
static BOOLEAN hmi_menu_logic_decr_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP);
static void hmi_menu_logic_decr_focus_line(MENU_CONTROL_T *p_menu_cntrl_SP);
static BOOLEAN hmi_menu_logic_is_focus_entry_valid(MENU_CONTROL_T const * p_menu_cntrl_SP);
static MENU_CB_RESULT_T hmi_menu_logic_down_application_cb(MENU_CONTROL_T *p_menu_cntrl_SP, BOOLEAN fl_menu_fs_end_of_list_BOOL);
static MENU_CB_RESULT_T hmi_menu_logic_up_application_cb(MENU_CONTROL_T *p_menu_cntrl_SP, BOOLEAN fl_menu_fs_end_of_list_BOOL);
static void hmi_menu_logic_clock_application_cb(MENU_CB_RESULT_T fl_cb_result_e, MENU_CONTROL_T *p_menu_cntrl_SP);
static BOOLEAN hmi_menu_logic_is_it_end_of_list(MENU_CONTROL_T const *p_menu_cntrl_SP);
static BOOLEAN hmi_menu_logic_is_it_start_of_list(MENU_CONTROL_T const *p_menu_cntrl_SP);
static void hmi_menu_logic_incr_focus_line(MENU_CONTROL_T *p_menu_cntrl_SP);
static BOOLEAN hmi_menu_logic_dynamic_menu_cb_condition(MENU_CB_RESULT_T fl_cb_result_e, MENU_CONTROL_T const * p_menu_cntrl_SP);
static void hmi_menu_logic_load_dynamic_const_data(MENU_CONTROL_T const * p_menu_cntrl_SP);
static UINT8 hmi_menu_logic_get_menu_inst_no(MENU_LIST_ID_T fl_menu_id_U8);
#if ((defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT))|| defined(LSH_ANIMATION_SUPPORT_ENABLED))
static UINT16 hmi_menu_logic_get_page_number(UINT16 fl_focus_entry_U16, UINT16 fl_displayed_lines_U16);
#endif
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:    hmi_menu_core_initialize
** Visibility:       Menu core
** Description:      This is the initialization function for the Menu Core This
**                   function initializes all status variable maintained by
**                   Menu core - chart and interface.
** Invocation:       Invoked by application.
** Inputs/Outputs:   p_init_type_U8 indicates the init type as Cold or Warm.
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_initialize(void)
{
	UINT8 fl_menu_index;
#ifndef MATLAB_MEX_FILE
  hmi_menu_core_01_model_initializer();
#endif
	for (fl_menu_index = 0; fl_menu_index < NB_OF_MENU_INSTANCE; fl_menu_index++)
  {
#ifndef MATLAB_MEX_FILE
		(void)initialize_hmi_menu_core_01_chart(&l_menu_core_chart_inst_array[fl_menu_index]);
#endif
		l_menu_instance_array[fl_menu_index].inst_status_BOOL = HMI_MENU_LOGIC_INST_INACTIVE;
		l_menu_instance_array[fl_menu_index].timer_status_BOOL = FALSE;
  }

  Current_focus_menu_ptr = FNULL;
  Current_focus_menu_inst_no_U8 = NB_OF_MENU_INSTANCE;
  l_nb_of_active_instance_S8          = -1;
  l_end_of_fast_scroll_BOOL    = FALSE;

#if defined(LSH_ANIMATION_SUPPORT_ENABLED) && defined(HMI_MENU_SMOOTH_FAST_ANIMATION)
	l_screen_id_in_queue =  LSH_NUMBER_OF_LOGIC_STATES;/* Invalid screen id*/
#endif
}
/*============================================================================
** Function Name:    hmi_menu_rx_button_handler
** Visibility:       global
** Description:      The function handles the buttons posted on Menu.
**                   It does four functionalities
**                   1.Checks the Button Input Nature.
**                   2.Informs the specific component whether to process the
**                     Button in the Menu or not.
**                   3.If to be processed then informs the specific action
**                     to the logic (menu_chart)function.
**                   4.Returns the status of the Button Action.
** Invocation:       By the LSH
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     UINT8 fl_hmi_menu_core_btn_hndlr_ret - LSH_STATUS_ABSORBED
                                                            LSH_STATUS_ACTION
                                                            LSH_STATUS_NONE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
UINT8 hmi_menu_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  UINT8                 fl_lsh_status;
  MENU_CONTROL_T       *fl_current_active_menu_SP;
  UINT8                 fl_active_menu_inst_idx_U8;
  MENU_LIST_ID_T        fl_menu_id_E;

#ifdef HMI_MENU_FAST_SCROLL_ENABLE
  BOOLEAN             fl_get_btn_process_BOOL;
#endif

  UINT16					p_button_command_U16;
  fl_lsh_status				= MENU_BTN_NONE;
  p_button_command_U16		= p_event_hndl_status_SP->button_command & LSH_ANIM_MASK_CLEAR;
  fl_menu_id_E				= (MENU_LIST_ID_T)p_event_hndl_status_SP->client_id;
  fl_current_active_menu_SP = hmi_menu_logic_get_menu_instance(fl_menu_id_E);

  if(fl_current_active_menu_SP != FNULL)
  {
    fl_active_menu_inst_idx_U8 = hmi_menu_logic_get_menu_inst_no(fl_current_active_menu_SP->menu_id);
	  if(fl_active_menu_inst_idx_U8 < NB_OF_MENU_INSTANCE)
    {
		  #ifdef HMI_MENU_FAST_SCROLL_ENABLE
		    fl_get_btn_process_BOOL = hmi_menu_logic_FS_process_valid_Btn(p_button_command_U16);
		    if(fl_get_btn_process_BOOL == FALSE)
		    {
		  #endif
		      fl_lsh_status = (UINT8)hmi_menu_logic_button_processing(fl_current_active_menu_SP,p_button_command_U16);
		  #ifdef HMI_MENU_FAST_SCROLL_ENABLE
	    	}
	    	else
		    {
		      hmi_menu_chart_FS_Btn_process(&l_menu_core_chart_inst_array[fl_active_menu_inst_idx_U8], fl_current_active_menu_SP->menu_id, p_button_command_U16);
		      fl_lsh_status = hmi_menu_chart_FS_btn_result(&l_menu_core_chart_inst_array[fl_active_menu_inst_idx_U8]);
		    }
		  #endif
	  }
  }
  return(fl_lsh_status);
}
/*============================================================================
** Function Name:    hmi_menu_logic_is_menu_action_allowed_in_anim_state
** Visibility:       global
** Description:      This function return whether menu action is allowed in anim stae
** Invocation:       By Menu core chart
** Inputs/Outputs:   fl_menu_action_U8
** Critical Section: None.
** Created:          27-June-2013 by csakthiv
** Updated:          27-June-2013 by csakthiv
**==========================================================================*/
BOOLEAN hmi_menu_logic_is_menu_action_allowed_in_anim_state(UINT8 fl_menu_action_U8)
{
	UINT8 fl_menu_action;
	BOOLEAN fl_menu_action_allowed_Bool = FALSE;
	for (fl_menu_action = 0; fl_menu_action < HMI_MENU_ACTION_IN_ANIM_COUNT; fl_menu_action++)
	{
		if (hmi_menu_actions_allowed_in_anim[fl_menu_action] == fl_menu_action_U8)
		{
			fl_menu_action_allowed_Bool = TRUE;
			break;
		}
	}
	return fl_menu_action_allowed_Bool;
}
/*============================================================================
** Function Name:    hmi_menu_logic_button_processing
** Visibility:       global
** Description:      This function is used to process the Presentation.
**                   It does below functionalities
**                   1.Maps the Screen ID to the Menu ID.
**                   2.Checks the Menu instance w.r.t Menu ID and finds the
**                     Instance.
**                   3.Routes to the corresponding presentation Call backs.
** Invocation:       By the LSH
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     UINT8 fl_hmi_menu_core_btn_hndlr_ret - LSH_STATUS_ABSORBED
                                                            LSH_STATUS_ACTION
                                                            LSH_STATUS_NONE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          16-Apr-2010 by jpradeep
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_button_processing(MENU_CONTROL_T *fl_current_active_menu_SP,UINT16 p_button_command_U16)
{
	MENU_CB_RESULT_T                 fl_cb_result_e;
	UINT8                            fl_menu_btn_action_U8;
	BOOLEAN                          fl_timer_status_BOOL;
	UINT8                            fl_btn_actn_index;
	UINT8                            fl_table_index;
	UINT8                            fl_total_btn_acns_mapped;
	UINT8                            fl_menu_inst_idx_U8;
	MENU_BTN_TO_ACTIONS_MAP_T const *fl_btn_action_map_SP;

	fl_cb_result_e        = MENU_BTN_PROCESS_MENU;

	if(fl_current_active_menu_SP != FNULL)
	{
		fl_menu_inst_idx_U8 = hmi_menu_logic_get_menu_inst_no(fl_current_active_menu_SP->menu_id);

		if(fl_menu_inst_idx_U8 < NB_OF_MENU_INSTANCE)
		{
			fl_timer_status_BOOL = hmi_menu_logic_is_open_timer_enabled(fl_current_active_menu_SP->menu_id);
			/* Button Callback called to either process the button by Menu or not*/
			if(hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].cb != FNULL)
			{
				fl_cb_result_e = hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].cb(MENU_ACTION_VALIDATE_BUTTON, fl_current_active_menu_SP, p_button_command_U16);
			}
			/* Do not restart the timer when cb result is MENU_BTN_NONE or MENU_BTN_ABSORBED - UP375 CR*/
#ifdef HMI_MENU_NOT_RESTART_TIMER_ON_NONE_ABSORBED
			if((fl_timer_status_BOOL == TRUE) && ((fl_cb_result_e != MENU_BTN_NONE) && (fl_cb_result_e != MENU_BTN_ABSORBED)))
			{
				/* Restart the menu open timer for any button press and also internal fast scroll button event */
				/* Restart the timer only it is already running. If it is stopped it should not be restarted again*/
				hmi_menu_logic_start_timer(MENU_CORE_OPEN_TIMER,fl_current_active_menu_SP->menu_id);
			}
#else
      if(fl_timer_status_BOOL == TRUE)
			{
				/* Restart the menu open timer for any button press and also internal fast scroll button event */
				/* Restart the timer only it is already running. If it is stopped it should not be restarted again*/
				hmi_menu_logic_start_timer(MENU_CORE_OPEN_TIMER,fl_current_active_menu_SP->menu_id);
			}
#endif
			if((fl_cb_result_e == MENU_BTN_PROCESS_MENU) || (fl_cb_result_e == MENU_BTN_CASCADED))
			{
				/* The value is force to MENU_BTN_NONE if none of the btn action is mapped
				In case if it matches then the return value will be updated by hmi_menu_chart_Btn_trigger() */
				fl_cb_result_e = MENU_BTN_NONE;

#ifdef HMI_MENU_FAST_SCROLL_ENABLE
				/* check made for processing the button if not in the Scrolling state 
				It is useful to not process the buttons when in the Fast scroll state
				Until the Fast scroll state is not complete, the other buttons should 
				not be processed. Supppose it is processed then the behaviour seems
				to be affected as the Menu chart logic works based on the btn events.   
				 Note:
				 The buttons blocked are sent by application for Menu core processing 
				 i.e MENU_BTN_PROCESS_MENU
				*/
				if((FALSE != hmi_menu_chart_is_FS_st(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8])) && (FALSE == hmi_menu_logic_FS_process_valid_Btn(p_button_command_U16)))
				{
					fl_cb_result_e = MENU_BTN_ABSORBED;
				}
				else
#endif
					{
					/* Map the Button Actions to Menu Actions w.r.to menu mapped table */
					fl_table_index = hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].table_index;
					if(fl_table_index < HMI_MENU_TABLE_COUNT)
					{
						fl_btn_action_map_SP = hmi_menu_map_actions_table_ptr[fl_table_index].hmi_menu_map_actions_table;
						fl_total_btn_acns_mapped = hmi_menu_map_actions_table_ptr[fl_table_index].hmi_menu_total_btn_acns_mapped;
						
						for (fl_btn_actn_index = 0; fl_btn_actn_index < fl_total_btn_acns_mapped; fl_btn_actn_index++)
						{
							if (fl_btn_action_map_SP[fl_btn_actn_index].button_action == p_button_command_U16)
							{
								fl_menu_btn_action_U8 = (UINT8)(fl_btn_action_map_SP[fl_btn_actn_index].menu_action);
								if(fl_menu_btn_action_U8 != MENU_ACTION_NONE)
								{
									fl_cb_result_e = (MENU_CB_RESULT_T)hmi_menu_chart_Btn_trigger(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8], fl_current_active_menu_SP->menu_id, fl_menu_btn_action_U8, fl_current_active_menu_SP->menu_state);
								}
								else
								{
									fl_cb_result_e = MENU_BTN_ABSORBED;
								}
								break;
							}
						}
					}
				}
			}
			else if((fl_cb_result_e == MENU_BTN_RESTART_TIMER_ABSORBED) || (fl_cb_result_e == MENU_BTN_RESTART_TIMER_NONE))
			{
				hmi_menu_logic_start_timer(MENU_CORE_OPEN_TIMER,fl_current_active_menu_SP->menu_id);
				if(fl_cb_result_e == MENU_BTN_RESTART_TIMER_ABSORBED)
				{
					fl_cb_result_e = MENU_BTN_ABSORBED;
				}
				else
				{
					fl_cb_result_e = MENU_BTN_NONE;
				}
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			fl_cb_result_e = MENU_BTN_NONE;
		}
	}
	else
	{
		fl_cb_result_e = MENU_BTN_NONE;
	}

	return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_FS_process_valid_Btn
** Visibility:       global
** Description:      This function shall check the valid buttons for the fast
**                   scroll processing .
** Invocation:       By the logic
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     BOOLEAN - TRUE/FALSE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          15-Oct-2013 by csakthiv
**==========================================================================*/
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
static BOOLEAN hmi_menu_logic_FS_process_valid_Btn(UINT16 p_button_command_U16)
{
  BOOLEAN fl_ret_status_BOOL;
  UINT16  fl_get_button_ID_U16;
  fl_ret_status_BOOL   = FALSE;
  fl_get_button_ID_U16 = HMI_MENU_GET_BTN_ID(p_button_command_U16);
  if((fl_get_button_ID_U16 == HMI_MENU_UP_BUTTON)||
    (fl_get_button_ID_U16 == HMI_MENU_DOWN_BUTTON))
  {
    fl_ret_status_BOOL = TRUE;
  }
  return(fl_ret_status_BOOL);
}

/*============================================================================
** Function Name:    hmi_menu_logic_FS_check_is_Btn_rel
** Visibility:       global
** Description:      This function is used to check the button release
** Invocation:       By the logic
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     BOOLEAN - TRUE/FALSE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          15-Oct-2013 by csakthiv
**==========================================================================*/
BOOLEAN hmi_menu_logic_FS_check_is_Btn_rel(UINT16 p_button_command_U16)
{
  BOOLEAN fl_ret_status_BOOL;
  
  fl_ret_status_BOOL   = FALSE;
  if((HMI_MENU_UP_BTN_REL   == p_button_command_U16)||
	 (HMI_MENU_DOWN_BTN_REL == p_button_command_U16))
  {
    fl_ret_status_BOOL   = TRUE;
  }
  return(fl_ret_status_BOOL);
}
/*============================================================================
** Function Name:    hmi_menu_logic_FS_convert_Btn_status
** Visibility:       global
** Description:      This function shall convert the Btn status
** Invocation:       By the logic
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     fl_send_new_btn_cmd_U16 - button command
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          07-Sept-2010 by jpradeep
**==========================================================================*/
UINT16 hmi_menu_logic_FS_convert_Btn_status(BOOLEAN p_status_BOOL, UINT16 p_btn_cmd_U16)
{
  UINT16 fl_get_btn_ID;
  UINT16 fl_send_new_btn_cmd_U16;

  fl_send_new_btn_cmd_U16 = MENU_BTN_INVALID;
  fl_get_btn_ID = HMI_MENU_GET_BTN_ID(p_btn_cmd_U16);

  if(HMI_MENU_BTN_STATUS_LONG == p_status_BOOL)
  {
    fl_send_new_btn_cmd_U16 = HMI_MENU_GET_BTN_CMD(fl_get_btn_ID, HMI_MENU_MC_BTN_LONG);
  }
  return(fl_send_new_btn_cmd_U16);
}

/*============================================================================
** Function Name:    hmi_menu_button_handler
** Visibility:       static
** Description:      This function shall process the buttons for the fast scroll
**                   conditions and returns the appropriate value.
** Invocation:       By the Logic
** Inputs/Outputs:   p_button_command_U16 - Button ID and State
                     p_logic_state_id_U8  - screen ID
                     p_menu_state_U8      - FAST/ NORMAL
                     UINT8 fl_ret_cb_result_e - LSH_STATUS_ABSORBED
                                                LSH_STATUS_ACTION
                                                LSH_STATUS_NONE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          07-Sept-2010 by jpradeep
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_button_handler(MENU_LIST_ID_T p_menu_id_U8, UINT16 p_btn_cmd_U16, UINT8 p_menu_state_U8)
{
  MENU_CB_RESULT_T    fl_ret_cb_result_e;
  MENU_CONTROL_T      *fl_current_active_menu_SP;
  fl_current_active_menu_SP = hmi_menu_logic_get_menu_instance(p_menu_id_U8);

  if(fl_current_active_menu_SP != FNULL)
  {
    fl_current_active_menu_SP->menu_state = p_menu_state_U8;
  }
  fl_ret_cb_result_e = hmi_menu_logic_button_processing(fl_current_active_menu_SP,p_btn_cmd_U16);
  return(fl_ret_cb_result_e);
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_is_FS_Enabled
** Visibility:       static
** Description:      This function shall shall check whether Fast scroll is
**                   enabled or not.
** Invocation:       By the logic
** Inputs/Outputs:   BOOLEAN - TRUE/ FALSE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          07-Sept-2010 by jpradeep
**==========================================================================*/
BOOLEAN hmi_menu_logic_is_FS_Enabled(MENU_LIST_ID_T p_menu_id_U8)
{
  BOOLEAN        fl_ret_st_BOOL;
  MENU_CONTROL_T const *fl_menu_cntrl_ptr;

  fl_menu_cntrl_ptr    = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
  if(!((fl_menu_cntrl_ptr != NULL) && ((fl_menu_cntrl_ptr->menu_properties & MENU_PRO_NO_FAST_SCROLL)!= (BOOLEAN)FALSE)))
  {
    fl_ret_st_BOOL = TRUE;
  }
  else
  {
    fl_ret_st_BOOL = FALSE;
  }
  return(fl_ret_st_BOOL);
}
/*============================================================================
** Function Name:    hmi_menu_presentation_handler
** Visibility:       global
** Description:      This function is used to process the Presentation.
**                   It does below functionalities
**                   1.Maps the Screen ID to the Menu ID.
**                   2.Checks the Menu instance w.r.t Menu ID and finds the
**                     Instance.
**                   3.Routes to the corresponding presentation Call backs.
** Invocation:       By the Logic
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          10-July-2013 by csakthiv
**==========================================================================*/
void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
	MENU_LIST_ID_T fl_menu_client_id_U8;
	MENU_CONTROL_T *fl_pre_menu_ptr;
	MENU_CONTROL_T  fl_pre_deact_menu_t;
	UINT8 fl_menu_instance_no_U8;
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
	MENU_ITEM_ENTRY_T  const  *fl_menu_item_entry_sp =FNULL;
	UINT16 fl_menu_entry;
	LSH_STATE_ID_T  fl_screen_id_U8;
#endif

	LSH_STATE_ID_T p_logic_state_id_U8 = p_presen_hndl_status_SP->logic_state_id;
	UINT8 p_lsh_status_U8 = p_presen_hndl_status_SP->presentation_status;
	fl_menu_client_id_U8  = (MENU_LIST_ID_T)p_presen_hndl_status_SP->client_id;
    if(fl_menu_client_id_U8 < TOTAL_MENU_ID)
	{
		fl_menu_instance_no_U8 = NB_OF_MENU_INSTANCE;
		/* Points the Appropriate Menu instance w.r.t Menu ID*/
		fl_pre_menu_ptr = hmi_menu_logic_get_menu_instance(fl_menu_client_id_U8);

		if(fl_pre_menu_ptr != NULL)
		{
			fl_menu_instance_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_pre_menu_ptr->menu_id);
			/* copied LSH screen id to MENU_CONTROL_T for content menu */
			fl_pre_menu_ptr->prsnt_screen_id = p_logic_state_id_U8;
		}

		if(LSH_ACTIVATED_STATUS == p_lsh_status_U8)
		{
			if((fl_pre_menu_ptr != NULL) && (fl_menu_instance_no_U8 < NB_OF_MENU_INSTANCE))
			{
				#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
					/* Dynamic menu should not be configured as content menu .i.e., total display line as 1*/
					fl_menu_item_entry_sp = hmi_menu_logic_Get_item_entry_array(fl_pre_menu_ptr, fl_pre_menu_ptr->focus_entry_U16);
					if((fl_menu_item_entry_sp != NULL) && (fl_menu_item_entry_sp->presentation_cb != FNULL))
					{
						fl_menu_item_entry_sp->presentation_cb(fl_pre_menu_ptr, LSH_ACTIVATED_STATUS);
					}
					else
					{
						/* do nothing */
					}
				#else
					if(hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb != FNULL)
					{
						hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb(fl_pre_menu_ptr, LSH_ACTIVATED_STATUS);
					}
				#endif
				/* Reset to invalid screen id, so that application cannot use it further*/
				fl_pre_menu_ptr->prsnt_screen_id = LSH_NUMBER_OF_LOGIC_STATES;
			}
		}
		else if(LSH_DEACTIVATED_STATUS == p_lsh_status_U8)
		{
			/* Since instance array has been written with NULL for the closed menu, we shall diretly
			** assign the value as NULL */
			/* No need to assign , if menu is not active then hmi_menu_logic_get_menu_instance() will return null*/
			/*fl_pre_menu_ptr = NULL;*/
			if((fl_pre_menu_ptr != NULL) && (fl_menu_instance_no_U8 < NB_OF_MENU_INSTANCE))
			{
				#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
					fl_menu_item_entry_sp = hmi_menu_logic_Get_item_entry_array(fl_pre_menu_ptr,fl_pre_menu_ptr->focus_entry_U16);
					if((fl_menu_item_entry_sp != NULL) && (fl_menu_item_entry_sp->presentation_cb != FNULL))
					{
						fl_menu_item_entry_sp->presentation_cb(fl_pre_menu_ptr, p_lsh_status_U8);
					}
					else
					{
					}
				#else
					if(hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb != FNULL)
					{
						hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb(fl_pre_menu_ptr, p_lsh_status_U8);
					}
				#endif
				/* Reset to invalid screen id, so that application cannot use it further*/
				fl_pre_menu_ptr->prsnt_screen_id = LSH_NUMBER_OF_LOGIC_STATES;
			}
			else
			{
			    UINT8 menu_index;
				/* intialize to defualt value as menu is already closed/not active in the instance.*/
				fl_pre_deact_menu_t.focus_entry_U16 = 0;
				fl_pre_deact_menu_t.focus_line_U16 = 0;
				fl_pre_deact_menu_t.menu_entry_nbr = 0;
				fl_pre_deact_menu_t.menu_id = fl_menu_client_id_U8;
				fl_pre_deact_menu_t.prsnt_screen_id = p_logic_state_id_U8;
			    fl_pre_deact_menu_t.inst_status_BOOL = HMI_MENU_LOGIC_INST_INACTIVE;
			    fl_pre_deact_menu_t.timer_status_BOOL = FALSE;
		        fl_pre_deact_menu_t.menu_state = MENU_STATE_NORMAL;
			    fl_pre_deact_menu_t.displayed_lines = 0;
			    fl_pre_deact_menu_t.line_fast_inc = 1;
			    fl_pre_deact_menu_t.menu_level_U8 = 0;
			    fl_pre_deact_menu_t.selected_entry_U16 = 0;
		        fl_pre_deact_menu_t.menu_properties	= 0;
			    for (menu_index = 0; menu_index < HMI_MAX_MENU_ITEMS; menu_index++)
			    {
				    fl_pre_deact_menu_t.menu_itm_absl_indx[menu_index] = 0;
			    }
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
			/* fill focus entry based on the screen id received from LSH */
			/* fill focus entry based on the screen id received from LSH */

				for (fl_menu_entry = 0; fl_menu_entry < hmi_menu_const_struct_array_table[fl_menu_client_id_U8].total_entry_nbr; fl_menu_entry++)
				{
					fl_screen_id_U8 = hmi_menu_const_struct_array_table[fl_menu_client_id_U8].entry_array.static_array[fl_menu_entry].item_screen_id_U8;
					if (fl_screen_id_U8 == p_logic_state_id_U8)
					{
						fl_pre_deact_menu_t.focus_entry_U16 = fl_menu_entry;
						break;
					}
				}
				if((fl_pre_deact_menu_t.menu_id < TOTAL_MENU_ID) && (fl_pre_deact_menu_t.focus_entry_U16 < hmi_menu_const_struct_array_table[fl_pre_deact_menu_t.menu_id].total_entry_nbr))
				{

					fl_menu_item_entry_sp = &hmi_menu_const_struct_array_table[fl_pre_deact_menu_t.menu_id].entry_array.static_array[fl_pre_deact_menu_t.focus_entry_U16];

					if (fl_menu_item_entry_sp->presentation_cb != FNULL)
					{
						fl_menu_item_entry_sp->presentation_cb(&fl_pre_deact_menu_t, p_lsh_status_U8);
					}
				}
#else
				if(hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb != FNULL)
				{
					hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb(&fl_pre_deact_menu_t, p_lsh_status_U8);
				}
	#endif
			}
		}
		else if(LSH_REFRESH_STATUS == p_lsh_status_U8)
		{
			if((fl_pre_menu_ptr != NULL) && (fl_menu_instance_no_U8 < NB_OF_MENU_INSTANCE))
			{
				#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
					fl_menu_item_entry_sp = hmi_menu_logic_Get_item_entry_array(fl_pre_menu_ptr,fl_pre_menu_ptr->focus_entry_U16);
					if((fl_menu_item_entry_sp != NULL) && (fl_menu_item_entry_sp->presentation_cb != FNULL))
					{
						fl_menu_item_entry_sp->presentation_cb(fl_pre_menu_ptr, LSH_REFRESH_STATUS);
					}
					else
					{
						/* do nothing */
					}
				#else
					if(hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb != FNULL)
					{
						hmi_menu_const_struct_array_table[fl_menu_client_id_U8].presentation_cb(fl_pre_menu_ptr, LSH_REFRESH_STATUS);
					}
				#endif
				/* Reset to invalid screen id, so that application cannot use it further*/
				fl_pre_menu_ptr->prsnt_screen_id = LSH_NUMBER_OF_LOGIC_STATES;
			}
		}
		else
		{
			/* do nothing */
		}
	}
}
/*============================================================================
** Function Name:    hmi_menu_set_focus_handler
** Visibility:       global
** Description:      This function is used to find the Menu Instance with
**                   respect to Menu ID. It validtes the current available
**                   Menu instance and returns the Instance.
** Invocation:       By LSH
** Inputs:           p_logic_state_U8, p_focus_U8
** Outputs:          None
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          24-July-2013 by csakthiv
**==========================================================================*/
void hmi_menu_set_focus_handler(LSH_FOCUS_HANDLER_STATUS_T *p_focus_hndl_status_SP)
{
	MENU_CONTROL_T   * fl_focus_menu_cntrl_SP;
	MENU_DEF_T const * fl_menu_def_SP;
	UINT8              fl_menu_inst_idx_U8;
	MENU_LIST_ID_T     fl_menu_id_U8;
	UINT8              fl_focus_U8;

	fl_focus_U8        = p_focus_hndl_status_SP->focus_status;
	fl_menu_id_U8      = (MENU_LIST_ID_T)p_focus_hndl_status_SP->client_id;

	#ifdef HMI_MENU_CORE_NOTIFY_MENU_FOCUS
		/*applicable only for TVM Sync*/
		HMI_MENU_LOGIC_NOTIFY_MENU_FOCUS(fl_menu_id_U8,fl_focus_U8);
	#endif

	fl_focus_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(fl_menu_id_U8);
	fl_menu_inst_idx_U8 = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);

	if((fl_focus_menu_cntrl_SP != FNULL)&&(fl_menu_inst_idx_U8 < NB_OF_MENU_INSTANCE))
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_menu_id_U8];
		if(LSH_GOT_FOCUS_STATUS == (fl_focus_U8 & LSH_GOT_FOCUS_STATUS))
		{
			if(fl_menu_def_SP->cb != FNULL)
			{
				(void)fl_menu_def_SP->cb(MENU_ACTION_GOT_FOCUS, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
			}
		}
		else if(LSH_LOST_FOCUS_STATUS == (fl_focus_U8 & LSH_LOST_FOCUS_STATUS))
		{
			if(fl_menu_def_SP->cb != FNULL)
			{
				(void)fl_menu_def_SP->cb(MENU_ACTION_LOST_FOCUS, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
			}
		}
		else
		{
		}
		if(LSH_DEACTIVATED_STATUS == (fl_focus_U8 & LSH_DEACTIVATED_STATUS))
		{
			/* within same priority if screen id changes, then view manager post deactivate|lost focus for old screen id             */
			/* Screen removed by presentation deactivate posted by vm first, menu instance queue cleared below                       */
			/* For submenu,it wont come here eventhough VM post deactivate, as the menu id in the instance will be changed already in create_submenu interface      */
			/* Closing the menu here will create issue in the case of content menu. So posted deactivated status to application */
			if(fl_menu_def_SP->cb != FNULL)
			{
				(void)fl_menu_def_SP->cb(MENU_ACTION_DEACTIVATED, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
			}
		}
		#ifdef LSH_ANIMATION_SUPPORT_ENABLED
        if(LSH_ANIM_COMPLETE_STATUS == (fl_focus_U8 & LSH_ANIM_COMPLETE_STATUS))
        {
				hmi_menu_chart_anim_exit(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8]);
				#ifdef HMI_MENU_SMOOTH_FAST_ANIMATION
					/* If smooth animaition support is enabled, Then check is there any screen in the queue.
					If screen id available in the queue, then remove the current screen and add the screen which
					is in queue*/
					if(l_screen_id_in_queue != LSH_NUMBER_OF_LOGIC_STATES)
					{
						#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
							/* Remove the current screen id*/
							hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, p_focus_hndl_status_SP->logic_state_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, HMI_MENU_SCREEN_REMOVE);
						#endif
						/* Add new screen id*/
						hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, l_screen_id_in_queue
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, HMI_MENU_SCREEN_ADD);
						l_screen_id_in_queue = LSH_NUMBER_OF_LOGIC_STATES;/*Invalid Screen ID*/
					}
				#endif
        }
        if(LSH_ANIM_STARTED_STATUS == (fl_focus_U8 & LSH_ANIM_STARTED_STATUS))
        {
               hmi_menu_chart_anim_started(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8]);
        }
		#endif
	}
	else
	{
		#if 0
			/* Below sequence has to be taken care in future along with view manager change*/
			/*Menu id received is not active in any instance but focus received is either LOST or GOT then that 
			menu id should be opened again by menu core focus handler. Menu1 is active, Close M1 and Open M1 again done continously
			First deactivate for M1 will be received M1 instance will be closed then M1 got focus and activate presentation will be 
			received*/
			if(0==(LSH_DEACTIVATED_STATUS & p_focus_hndl_status_SP->focus_status))
			{
				/*Menu opened eventhough screen is already active in display.Since same screen id is added again no action in LSH.*/
				MENU_CORE_MENU_OPEN(fl_menu_id_U8,ANIM_MAX_ID);
			}
		#endif
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_Get_Focus_MenuInstance
** Visibility:       global
** Description:      Lsh current focussed menu id is returned by this function
** Invocation:       By the Menu_chart and the Application
** Inputs:           None
** Outputs:          Menu ID
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CONTROL_T *hmi_menu_logic_Get_Focus_MenuInstance(void)
{
  return(Current_focus_menu_ptr);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Menu_Open
** Visibility:       global
** Description:      This function shall open the function after checking
**                   for the valid conditions.
** Invocation:       By the Application
** Inputs:           p_menu_id_U8 - Menu ID
** Outputs:          Points to the Menu Instance.
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_Menu_Open(MENU_LIST_ID_T p_open_menu_id_e
                              #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                              ,UINT8 p_open_anim_ID_U8
                              #endif
                              )
{
  MENU_CB_RESULT_T     fl_cb_result_e;
  UINT8                fl_find_menu_inst_val_U8;
  UINT8                fl_focus_menu_inst_val_U8 = NB_OF_MENU_INSTANCE;
  LSH_STATE_ID_T       fl_get_logic_st_id_U8 = LSH_NUMBER_OF_LOGIC_STATES;/* Invalid screen id*/
  MENU_LIST_ID_T       fl_get_focus_menu_id_U8 = TOTAL_MENU_ID;
  MENU_CONTROL_T      * fl_focus_menu_cntrl_SP;
  #ifdef HMI_MENU_LSH_FREEZE_CONFIG
  MENU_LSH_FREEZE_T    fl_menu_lsh_freeze_t;
  #endif

  fl_cb_result_e = MENU_CB_ACTION_COMPLETED;

  /* Array Access Boundary check */
  if(p_open_menu_id_e < TOTAL_MENU_ID)
  {
    if(FALSE == hmi_menu_logic_MenuIsOpen(p_open_menu_id_e))
    {
      (void)hmi_menu_logic_create_menu_instance(p_open_menu_id_e);
      fl_find_menu_inst_val_U8 = hmi_menu_logic_get_menu_inst_no(p_open_menu_id_e);
      if(fl_find_menu_inst_val_U8 != NB_OF_MENU_INSTANCE)
      {
        if(Current_focus_menu_ptr != NULL)
        {
          /* if there is any menu active in focus, then save its menu id and screen id*/
          fl_get_logic_st_id_U8   = hmi_menu_logic_get_screen_id(Current_focus_menu_ptr);
          fl_get_focus_menu_id_U8 = Current_focus_menu_ptr->menu_id;
          fl_focus_menu_inst_val_U8 = hmi_menu_logic_get_menu_inst_no(fl_get_focus_menu_id_U8);
        }
        hmi_menu_logic_create_menu(p_open_menu_id_e, fl_find_menu_inst_val_U8);
        /*update current menu focus ptr and start menu open timer*/
        hmi_menu_logic_update_current_focus_menu_ptr();
        /* if the currently opened menu id got the focus(ie, high priority), then stop the timer of previously opened menu*/
        if((Current_focus_menu_ptr != NULL) && (Current_focus_menu_ptr->menu_id == p_open_menu_id_e)
                                            && (l_nb_of_active_instance_S8 > 0))
        {
          #ifndef HMI_MENU_LSH_FREEZE_CONFIG
          hmi_lsh_freeze_button_events_ext(fl_get_logic_st_id_U8,(UINT8)fl_get_focus_menu_id_U8);
          #else
          fl_menu_lsh_freeze_t.freeze_disp_screen_id = fl_get_logic_st_id_U8;
          fl_menu_lsh_freeze_t.freeze_menu_id = fl_get_focus_menu_id_U8;
          HMI_MENU_LOGIC_NOTIFY_LSH_BUTTON_FREEZE(&fl_menu_lsh_freeze_t);
          #endif
          /* We should not stop the timer when we open the menu with the same instance as previous
          menu. This is to fix issue with restarting the timer when we do button processing in the
          above case.*/
          if(fl_focus_menu_inst_val_U8 != fl_find_menu_inst_val_U8)
          {
            hmi_menu_logic_stop_timer(MENU_CORE_OPEN_TIMER, fl_get_focus_menu_id_U8);
            hmi_menu_logic_disable_open_timer_status(fl_get_focus_menu_id_U8);
          }
        }
        fl_focus_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(p_open_menu_id_e);

        if(fl_focus_menu_cntrl_SP != NULL)
        {
          if (hmi_menu_logic_is_focus_entry_valid(fl_focus_menu_cntrl_SP) == FALSE)
          {
            /* if focus entry= 0, is greyout or focus disabled, then focus entry will incremented till valid FE*/
            /* if none of the item is valid, then focus entry will be zero*/
            hmi_menu_logic_down_focus_entry(fl_focus_menu_cntrl_SP);
          }
          /*for dynamic menu, application will set the menu level on action_open, so core should set the 
          default values before calling application callback*/
          fl_focus_menu_cntrl_SP->menu_level_U8 = hmi_menu_logic_get_Menu_level(fl_focus_menu_cntrl_SP->menu_id);
		  if(fl_focus_menu_cntrl_SP->menu_id < TOTAL_MENU_ID)
		  {
			if (hmi_menu_const_struct_array_table[fl_focus_menu_cntrl_SP->menu_id].cb != FNULL)
			{
			  fl_cb_result_e = hmi_menu_const_struct_array_table[fl_focus_menu_cntrl_SP->menu_id].cb(MENU_ACTION_OPEN, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
              #ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
			  if ((fl_focus_menu_cntrl_SP->menu_properties & MENU_PRO_HISTORY_MENU) != 0U)
			  {
			  	HMI_MENU_HISTORY_STORE_MENU_ID(fl_focus_menu_cntrl_SP->menu_id);
              	#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
			  	hmi_menu_logic_update_history_info(fl_focus_menu_cntrl_SP);
              	#endif
			  }
              #endif
			}
		  }

          if((fl_cb_result_e != MENU_CB_ACTION_EXIT)&&
            (fl_cb_result_e != MENU_CB_ACTION_NONE))
          {
            fl_get_logic_st_id_U8 = hmi_menu_logic_get_screen_id(fl_focus_menu_cntrl_SP);
            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
            (void)LSH_ADD_STATE_EXT(fl_get_logic_st_id_U8, p_open_anim_ID_U8,p_open_menu_id_e);
            if(p_open_anim_ID_U8 != (UINT8)(ANIM_MAX_ID))
            {
              if(fl_cb_result_e == MENU_CB_ACTION_WAIT)
              {
                /* Start the wait temp timer */
                hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,p_open_menu_id_e);
                fl_cb_result_e = MENU_CB_ACTION_WAIT;
              }
              else
              {
                #ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
                MENU_DO_FRAME_EXPAND_ANIMATION;
                #endif
                fl_cb_result_e = MENU_CB_ACTION_ANIMATION;
              }
            }
            #else
            hmi_menu_logic_View_Mngr_Rq(p_open_menu_id_e, fl_get_logic_st_id_U8
              #ifdef LSH_ANIMATION_SUPPORT_ENABLED
              , ANIM_MAX_ID
              #endif
              , HMI_MENU_SCREEN_ADD);
            #endif
          }
          hmi_menu_chart_Menu_open(&l_menu_core_chart_inst_array[fl_find_menu_inst_val_U8],fl_focus_menu_cntrl_SP->menu_id,fl_cb_result_e);
        }
      }
    }
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_update_current_focus_menu_inst
** Visibility:       global
** Description:      Interface to update current menu focus ptr based on active instance
** Invocation:       Menu core logic
** Inputs:           None
** Outputs:          Available menu instance.
** Critical Section: None.
** Created:          05-July-2013 by csakthiv
** Updated:          
**==========================================================================*/
static void hmi_menu_logic_update_current_focus_menu_ptr(void)
{
	UINT8 fl_inst_U8;
	UINT8 fl_current_focus_inst_U8 = 0;
	UINT8 fl_menu_inst;

	if (l_nb_of_active_instance_S8 != -1)
	{
		for (fl_menu_inst = 0; fl_menu_inst < NB_OF_MENU_INSTANCE; fl_menu_inst++)
		{
			if (l_menu_instance_array[fl_menu_inst].inst_status_BOOL == HMI_MENU_LOGIC_INST_ACTIVE)
			{
				fl_inst_U8 = hmi_menu_logic_get_menu_inst_no(l_menu_instance_array[fl_menu_inst].menu_id);
				if (fl_inst_U8 >= fl_current_focus_inst_U8)
				{
					fl_current_focus_inst_U8 = fl_inst_U8;
				}
			}
		}
		Current_focus_menu_inst_no_U8 = fl_current_focus_inst_U8;
		if (Current_focus_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
		{
			Current_focus_menu_ptr = &l_menu_instance_array[Current_focus_menu_inst_no_U8];
		}
		else
		{
			Current_focus_menu_ptr = FNULL;
		}
	}
	else
	{
		Current_focus_menu_inst_no_U8 = NB_OF_MENU_INSTANCE;
		Current_focus_menu_ptr = FNULL;
	}
	if (Current_focus_menu_ptr != FNULL)
	{
		hmi_menu_logic_start_timer(MENU_CORE_OPEN_TIMER, Current_focus_menu_ptr->menu_id);
		hmi_menu_logic_enable_open_timer_status(Current_focus_menu_ptr->menu_id);
	}

}
/*============================================================================
** Function Name:    hmi_menu_logic_Menu_Close
** Visibility:       global
** Description:      This function is used shall take the close action when
**                   the Menu needs to be closed.
** Invocation:       By the Application
** Inputs:           p_close_menu_id_e - Menu ID
** Outputs:          None
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
void hmi_menu_logic_Menu_Close(MENU_LIST_ID_T p_close_menu_id_e
                             #ifdef LSH_ANIMATION_SUPPORT_ENABLED
							   ,UINT8 p_menu_anim_ID_U8
						     #endif
							  )
{
   hmi_menu_logic_process_menu_close(MENU_ACTION_FORCED_CLOSE,p_close_menu_id_e
                                #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                     ,p_menu_anim_ID_U8
						        #endif
							    );

}
/*============================================================================
** Function Name:    hmi_menu_logic_create_menu_instance
** Visibility:       global
** Description:      This function is used shall take the close action when
**                   the Menu needs to be closed.
** Invocation:       By the Application
** Inputs:           p_close_menu_id_e - Menu ID
** Outputs:          None
** Critical Section: None.
** Created:          6-Aug-2013 by csakthiv
** Updated:          
**==========================================================================*/
static UINT8 hmi_menu_logic_create_menu_instance(MENU_LIST_ID_T p_open_menu_id_e)
{
    UINT8 fl_menu_inst_no_U8 = HMI_MENU_INST_INVALID;
    MENU_CONTROL_T        *fl_menu_open_ptr;

    /* Assumption: As of now number of instances will not go more that 127.
    If it goes beyond that value we need to update the below line of code*/
    if(l_nb_of_active_instance_S8 < ((SINT8)NB_OF_MENU_INSTANCE-1))
    {
        fl_menu_inst_no_U8  = hmi_menu_logic_get_menu_inst_no(p_open_menu_id_e);
        if(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
        {
            fl_menu_open_ptr         			 = hmi_menu_logic_get_required_menu_instance(fl_menu_inst_no_U8);
            /* If the current instance is in active state close the menu and the create it
            again with the new menu id. This is to do proper closing of current instance
            timer and chart*/
            if(fl_menu_open_ptr->inst_status_BOOL == HMI_MENU_LOGIC_INST_ACTIVE)
            {
              hmi_menu_logic_destroy_menu_instance(fl_menu_open_ptr->menu_id);
            }
            fl_menu_open_ptr->inst_status_BOOL = HMI_MENU_LOGIC_INST_ACTIVE;
            l_nb_of_active_instance_S8++;
         }
    }
    return fl_menu_inst_no_U8;
}
/*============================================================================
** Function Name:    hmi_menu_logic_destroy_menu_instance
** Visibility:       global
** Description:      This function is used shall take the close action when
**                   the Menu needs to be closed.
** Invocation:       By the Application
** Inputs:           p_close_menu_id_e - Menu ID
** Outputs:          None
** Critical Section: None.
** Created:          6-Aug-2013 by csakthiv
** Updated:          30-Jan-2014 by csakthiv
**==========================================================================*/
static void hmi_menu_logic_destroy_menu_instance(MENU_LIST_ID_T  fl_close_menu_id_e)
{
	MENU_CONTROL_T        *fl_menu_close_ptr;
	UINT8                  fl_menu_inst_no_U8;

	fl_menu_close_ptr = hmi_menu_logic_get_menu_instance(fl_close_menu_id_e);

	if(fl_menu_close_ptr != FNULL)
	{
		fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_close_menu_id_e);
		if(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
		{
			HMI_MENU_STOP_TIMER(fl_close_menu_id_e, hmi_menu_inst_config_table[fl_menu_inst_no_U8].menu_open_timer_id);
			#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			HMI_MENU_STOP_WAIT_TEMP_TIMER(fl_close_menu_id_e, hmi_menu_inst_config_table[fl_menu_inst_no_U8].menu_wait_timer_id);
			#endif
			#ifdef HMI_MENU_FAST_SCROLL_ENABLE
 			HMI_MENU_FS_STOP_TIMER(fl_close_menu_id_e, hmi_menu_inst_config_table[fl_menu_inst_no_U8].menu_fastscroll_timer_id);
      #endif
			hmi_menu_chart_close(&l_menu_core_chart_inst_array[fl_menu_inst_no_U8]);
			fl_menu_close_ptr->inst_status_BOOL = HMI_MENU_LOGIC_INST_INACTIVE;
			l_nb_of_active_instance_S8--;
		}
	}
}


/*============================================================================
** Function Name:    hmi_menu_logic_SubMenu_Open
** Visibility:       global
** Description:      This function shall open the SubMenu.
** Invocation:       By the Menu_logic.c
** Inputs:           MENU_DEF_T   *p_open_submenu_ptr
**                   UINT8       p_menu_inst_U8
**                   MENU_ACTION_T p_menu_action_e
** Outputs:          MENU_CB_RESULT_T
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_SubMenu_Open(const MENU_DEF_T *p_open_submenu_ptr, const MENU_DEF_T *p_current_menu_ptr, UINT8 p_menu_inst_U8, MENU_ACTION_T p_menu_action_e)
{
  MENU_CB_RESULT_T        fl_cb_result_e;
  MENU_CONTROL_T         *fl_cur_menu_ptr;
  MENU_LIST_ID_T          fl_get_menu_index_e;

  fl_cb_result_e         = MENU_CB_ACTION_COMPLETED;

  fl_get_menu_index_e    = hmi_menu_logic_get_menu_index(p_open_submenu_ptr);
  if(TOTAL_MENU_ID != fl_get_menu_index_e)
  {
    fl_cur_menu_ptr        = hmi_menu_logic_get_required_menu_instance(p_menu_inst_U8);
    if(fl_cur_menu_ptr != FNULL)
    {
      /* Always submenu will be opened in the same menu instance 
      and the parent menu and submenu screens should have the same priority*/
      hmi_menu_fast_scroll_inactive(&l_menu_core_chart_inst_array[p_menu_inst_U8]);
      hmi_menu_logic_create_menu(fl_get_menu_index_e, p_menu_inst_U8);
      if (hmi_menu_logic_is_focus_entry_valid(fl_cur_menu_ptr) == FALSE)
      {
        /* if focus entry= 0, is greyout or focus disabled, then focus entry will incremented till valid FE*/
        /* if none of the item is valid, then focus entry will be zero*/
        hmi_menu_logic_down_focus_entry(fl_cur_menu_ptr);
      }
      /* when submenu can have different timeout than the parent menu,so restart the timer with submenus timeout value
      * eventhough timer restarted on parenet timeout value on pressing right button.*/
      hmi_menu_logic_start_timer(MENU_CORE_OPEN_TIMER,fl_cur_menu_ptr->menu_id);

      if(((fl_cur_menu_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U) &&
        (p_menu_action_e != MENU_ACTION_OPEN_FROM_CHILD))
      {
        fl_cur_menu_ptr->menu_level_U8 = hmi_menu_logic_get_Menu_level(fl_cur_menu_ptr->menu_id);
      }
      if(((fl_cur_menu_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U) &&
        (p_menu_action_e == MENU_ACTION_OPEN_FROM_CHILD))
      {
        hmi_menu_logic_Set_ParentFocus(fl_cur_menu_ptr, p_current_menu_ptr);
      }

	  if ((fl_cur_menu_ptr->menu_id < TOTAL_MENU_ID) && (hmi_menu_const_struct_array_table[fl_cur_menu_ptr->menu_id].cb != FNULL))
	  {
		fl_cb_result_e = hmi_menu_const_struct_array_table[fl_cur_menu_ptr->menu_id].cb(p_menu_action_e, fl_cur_menu_ptr, MENU_BTN_INVALID);
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
		if ((fl_cur_menu_ptr->menu_properties & MENU_PRO_HISTORY_MENU) != 0U)
		{
					HMI_MENU_HISTORY_STORE_MENU_ID(fl_cur_menu_ptr->menu_id);
		}
#endif
	  }
	}
  }
  return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_get_menu_index
** Visibility:       global
** Description:      This function is used to find the menu ID(index) in the
**                   hmi_menu_const_struct_array_table to get loaded.
** Invocation:       By the menu logic.c
** Inputs:           MENU_CONTROL_T *fl_menu_ID_ptr
**                   MENU_LIST_ID_T  menu_ID_index
** Outputs:          Gives the  menu_ID_index.
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
static MENU_LIST_ID_T hmi_menu_logic_get_menu_index(const MENU_DEF_T *fl_menu_ID_ptr)
{
  UINT8  fl_menu_id;
  MENU_LIST_ID_T  fl_ret_menu_def_index_e;

  fl_ret_menu_def_index_e = TOTAL_MENU_ID;
  for (fl_menu_id = 0U; fl_menu_id<TOTAL_MENU_ID; fl_menu_id++)
  {
    if (fl_menu_ID_ptr == &hmi_menu_const_struct_array_table[fl_menu_id])
    {
      fl_ret_menu_def_index_e = (MENU_LIST_ID_T)fl_menu_id;
      break;
    }
  }
  return(fl_ret_menu_def_index_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_create_menu
** Visibility:       global
** Description:      This function is used to load and create the Menu parameter
**                   while opening the Menu.
** Invocation:       By the Menu_interface.c
** Inputs:           MENU_LIST_ID_T  p_menu_id_e
**                   SINT8           p_menu_inst_val_S8
** Outputs:          Points to the Menu Instance.
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          03-Mar-2014 by csakthiv
**==========================================================================*/
static void hmi_menu_logic_create_menu(MENU_LIST_ID_T p_menu_id_e, UINT8 p_menu_inst_val_U8)
{
  MENU_CONTROL_T *fl_load_menu_ptr;

  fl_load_menu_ptr = hmi_menu_logic_get_required_menu_instance(p_menu_inst_val_U8);
  if ((fl_load_menu_ptr != FNULL) && (p_menu_id_e < TOTAL_MENU_ID))
  {
	fl_load_menu_ptr->menu_id = p_menu_id_e;
	fl_load_menu_ptr->focus_entry_U16 = 0;
	fl_load_menu_ptr->focus_line_U16 = 0;
	fl_load_menu_ptr->line_fast_inc = 1;
	fl_load_menu_ptr->displayed_lines = hmi_menu_const_struct_array_table[p_menu_id_e].total_display_lines;
	fl_load_menu_ptr->menu_entry_nbr = hmi_menu_const_struct_array_table[p_menu_id_e].total_entry_nbr;
	fl_load_menu_ptr->menu_properties = hmi_menu_const_struct_array_table[p_menu_id_e].properties;
	fl_load_menu_ptr->menu_state = MENU_STATE_NORMAL;
	fl_load_menu_ptr->selected_entry_U16 = MENU_INVALID_ENTRY;
	l_menu_core_chart_inst_array[p_menu_inst_val_U8].l_menu_id_U8 = p_menu_id_e;
	if ((fl_load_menu_ptr->menu_properties & MENU_PRO_DYNAMIC) != 0U)
	{
	  hmi_menu_logic_load_dynamic_const_data(fl_load_menu_ptr);
	}
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	hmi_menu_logic_load_absl_index(fl_load_menu_ptr);
#endif
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_load_dynamic_const_data
** Visibility:       static
** Description:      This function load the const dynamic data from config.inc to dynamic ram of menu
** Invocation:       By the Menu core
** Inputs:           MENU_CONTROL_T
** Outputs:          
** Critical Section: None.
** Created:          05-Feb-2011 by csakthiv
** Updated:          
**==========================================================================*/
static void hmi_menu_logic_load_dynamic_const_data(MENU_CONTROL_T const * p_menu_cntrl_SP)
{
	UINT16 fl_menu_index,j;
	MENU_DEF_T  const    * fl_menu_def_SP;
	for (fl_menu_index = 0; fl_menu_index < TOTAL_DYNAMIC_MENU_ITEMS; fl_menu_index++)
	{
		if ((p_menu_cntrl_SP->menu_id == hmi_menu_const_dynamic_menu_table[fl_menu_index].menu_id) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
		{
			fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];

			for(j = 0; j < p_menu_cntrl_SP->menu_entry_nbr; j++)
			{
				#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
				fl_menu_def_SP->entry_array.dynamic_array[j].item_screen_id_U8 = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].item_screen_id_U8;
				fl_menu_def_SP->entry_array.dynamic_array[j].presentation_cb = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].presentation_cb;
				#endif
				fl_menu_def_SP->entry_array.dynamic_array[j].item_entry_type = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].item_entry_type;
				fl_menu_def_SP->entry_array.dynamic_array[j].item_properties = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].item_properties;
				fl_menu_def_SP->entry_array.dynamic_array[j].item_symbol = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].item_symbol;
				#ifdef HMI_MENU_ITEMS_WITH_TWO_ICONS
				fl_menu_def_SP->entry_array.dynamic_array[j].item_symbol2 = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].item_symbol2;
				#endif
				fl_menu_def_SP->entry_array.dynamic_array[j].label = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].label;
				fl_menu_def_SP->entry_array.dynamic_array[j].utype = hmi_menu_const_dynamic_menu_table[fl_menu_index].entry_array[j].utype;
			}
		}
	}
}				
/*============================================================================
** Function Name:    hmi_menu_logic_get_menu_instance
** Visibility:       global
** Description:      This function is used to find the Menu Instance with
**                   respect to Menu ID. It validtes the current available
**                   Menu instance and returns the Instance.
** Invocation:       By the Menu_interface.c
** Inputs:           p_menu_id_U8 - Menu ID
** Outputs:          Points to the Menu Instance.
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CONTROL_T  *hmi_menu_logic_get_menu_instance(MENU_LIST_ID_T p_menu_id_U8)
{
	UINT8 fl_menu_inst_no_U8;
	MENU_CONTROL_T *fl_menu_inst_ID_ptr;

	fl_menu_inst_ID_ptr = FNULL;
	fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(p_menu_id_U8);
	if(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
	{
		if(l_menu_instance_array[fl_menu_inst_no_U8].inst_status_BOOL != HMI_MENU_LOGIC_INST_INACTIVE)
		{
			if(l_menu_instance_array[fl_menu_inst_no_U8].menu_id == p_menu_id_U8)
			{
				fl_menu_inst_ID_ptr = &l_menu_instance_array[fl_menu_inst_no_U8];
			}
		}
	}
	return(fl_menu_inst_ID_ptr);
}
/*============================================================================
** Function Name:    hmi_menu_logic_get_required_menu_instance
** Visibility:       global
** Description:      This function is used to get the required menu instance
**                   from the available menu instance array
** Invocation:       By the hmi application
** Inputs/Outputs:   p_menu_inst_num_U8 - menu instance number
** Outputs           MENU_CONTROL_T
** Critical Section: None.
** Created:          16-Dec-2010 by jpradeep
** Updated:          16-Dec-2010 by jpradeep
**==========================================================================*/
MENU_CONTROL_T  *hmi_menu_logic_get_required_menu_instance(UINT8 p_menu_inst_num_U8)
{
  MENU_CONTROL_T *fl_ret_menu_inst_ptr;
  fl_ret_menu_inst_ptr = FNULL;

  if(p_menu_inst_num_U8 < NB_OF_MENU_INSTANCE)
  {
    fl_ret_menu_inst_ptr = &l_menu_instance_array[p_menu_inst_num_U8];
  }
  return(fl_ret_menu_inst_ptr);
}
/*============================================================================
** Function Name:    hmi_menu_logic_get_active_menu_instance_ptr
** Visibility:       global
** Description:      This function is used to get the active menu instance
**                   from the available menu instance array
** Invocation:       By the hmi application
** Inputs/Outputs:   p_menu_inst_num_U8 - menu instance number
** Outputs           MENU_CONTROL_T
** Critical Section: None.
** Created:          17-Oct-2016 by aperumal
** Updated:          17-Oct-2016 by aperumal
**==========================================================================*/
MENU_CONTROL_T  *hmi_menu_logic_get_active_menu_instance_ptr(UINT8 p_menu_inst_num_U8)
{
  MENU_CONTROL_T *fl_ret_menu_inst_ptr;
  fl_ret_menu_inst_ptr = FNULL;

  if(p_menu_inst_num_U8 < NB_OF_MENU_INSTANCE)
  {
	  if(l_menu_instance_array[p_menu_inst_num_U8].inst_status_BOOL != HMI_MENU_LOGIC_INST_INACTIVE)
      {
        fl_ret_menu_inst_ptr = &l_menu_instance_array[p_menu_inst_num_U8];
	  }
  }
  return(fl_ret_menu_inst_ptr);
}
/*============================================================================
** Function Name:    hmi_menu_logic_generic_focus_line_incr
** Visibility:       global
** Description:      This function process the Menu Down Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:
**==========================================================================*/
static void hmi_menu_logic_incr_focus_line(MENU_CONTROL_T *p_menu_cntrl_SP)
{
	if ((p_menu_cntrl_SP->focus_line_U16 + HMI_MENU_LINE_INCREMENT)
			>= p_menu_cntrl_SP->displayed_lines)
	{
		if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
		{
			p_menu_cntrl_SP->focus_line_U16 = 0;
		}
		else
		{
			p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->displayed_lines
					- HMI_MENU_LINE_INCREMENT;
		}
	}
	else if((p_menu_cntrl_SP->menu_properties & MENU_PRO_LTD_WND_FOCUS_ENTRY) != 0U)
	{
	   p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_line_U16 + 1U; 
	   if(p_menu_cntrl_SP->focus_entry_U16 != (p_menu_cntrl_SP->menu_entry_nbr-1U))
	   {
   	      /* if not last entry in the menu, then decrement the focus line to the previous line */
	      /* if last entry, keep the focus line in the last entry itself */
	      if(p_menu_cntrl_SP->focus_line_U16 ==  (p_menu_cntrl_SP->displayed_lines -1U))
	      {
	         /* after increment if focus line comes to last line, then decrement it by 1*/
	         p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_line_U16 - 1U; 
          }   
       }
    }
	else
	{
		p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_line_U16 + 1U;
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_decr_focus_line
** Visibility:       global
** Description:      This function process the Menu Down Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:
** Updated:
**==========================================================================*/

static void hmi_menu_logic_decr_focus_line(MENU_CONTROL_T *p_menu_cntrl_SP)
{
	if (p_menu_cntrl_SP->focus_line_U16 == 0U)
	{
		if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
		{
			p_menu_cntrl_SP->focus_line_U16 = (MIN_VALUE((p_menu_cntrl_SP->menu_entry_nbr),(p_menu_cntrl_SP->displayed_lines)) - 1U);
		}
		else
		{
			p_menu_cntrl_SP->focus_line_U16 = 0;
		}
	}
	else if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_LTD_WND_FOCUS_ENTRY) != 0U)
	{
		p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_line_U16 - 1U;
		if (p_menu_cntrl_SP->focus_entry_U16 != 0U)
		{
			/* if not first entry in the menu, then increment the focus line to the next line */
			/* if first entry, keep the focus line in the first entry itself */
			if (p_menu_cntrl_SP->focus_line_U16 == 0U)
			{
				/* after decrement if focus line comes to first line, then increment it by 1*/
				p_menu_cntrl_SP->focus_line_U16 = 1;
			}
		}
	}
	else
	{
		p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_line_U16 - 1U;
	}
}

/*============================================================================
** Function Name:    hmi_menu_logic_DOWN_action
** Visibility:       global
** Description:      This function process the Menu Down Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          24-Nov-2013 by csakthiv
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_DOWN_action(MENU_CONTROL_T* p_menu_cntrl_SP)
{
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  UINT16                    fl_start_focus_entry_U16;
  UINT16                    fl_start_focus_line_U16;
#endif
  MENU_CB_RESULT_T          fl_cb_result_e;
  MENU_ANIM_DATA_T          fl_menu_anim_data;
  BOOLEAN                   fl_menu_fs_end_of_list_BOOL;

  fl_cb_result_e = MENU_CB_ACTION_COMPLETED;

  if (p_menu_cntrl_SP != FNULL)
  {
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
    fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
#endif

    fl_menu_anim_data.menu_anim_prev_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    fl_menu_anim_data.menu_anim_prev_menu_id_E = p_menu_cntrl_SP->menu_id;
    fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);

    if (p_menu_cntrl_SP->menu_entry_nbr > 0U)
    {
      if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) == 0U)
      {
        if (((p_menu_cntrl_SP->focus_entry_U16 + 1U) >= p_menu_cntrl_SP->menu_entry_nbr) &&
          ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) == 0U) &&
          (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL))
        {

          /* do nothing*/
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
                    /* if the focus entry is at end and rest of the elements are disabled the
                    moving through greyed out elements is blocked by the above, So for moving through the focus line, thus statement is added*/
          if (p_menu_cntrl_SP->focus_line_U16 >= p_menu_cntrl_SP->displayed_lines)
          {
            p_menu_cntrl_SP->focus_line_U16--;
          }
#endif
        }
        else
        {
          if (hmi_menu_logic_dynamic_menu_cb_condition(MENU_CB_ACTION_DOWN, p_menu_cntrl_SP) != FALSE)
          {
            /* end of list is calculated before incr/decr focus entry. otherwise last line will  not displayed */
            /* Menu_completion will be posted before last line. MCA Issue*/
            fl_menu_fs_end_of_list_BOOL = hmi_menu_logic_is_it_end_of_list(p_menu_cntrl_SP);
            hmi_menu_logic_down_focus_entry(p_menu_cntrl_SP);
            fl_cb_result_e = hmi_menu_logic_down_application_cb(p_menu_cntrl_SP, fl_menu_fs_end_of_list_BOOL);
          }
          else
          {
            hmi_menu_logic_down_focus_entry(p_menu_cntrl_SP);
          }
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
          hmi_menu_logic_update_history_info(p_menu_cntrl_SP);
#endif
        }
      }
      else
      {
        hmi_menu_logic_clock_application_cb(MENU_CB_ACTION_DOWN, p_menu_cntrl_SP);
      }
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
      if ((fl_cb_result_e != MENU_CB_ACTION_WAIT) && (p_menu_cntrl_SP->menu_state != MENU_STATE_FAST))
      {
        /* For wait and fast scrool animation is run from menu core chart. if below funct. is called
        then animation will be changed to focus move up/down*/
        fl_cb_result_e = hmi_menu_logic_get_down_animation(fl_start_focus_entry_U16, fl_start_focus_line_U16, p_menu_cntrl_SP);
      }
#endif
    }

    fl_menu_anim_data.menu_anim_curr_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    fl_menu_anim_data.menu_anim_curr_menu_id_E = p_menu_cntrl_SP->menu_id;
    fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
    if (p_menu_cntrl_SP->displayed_lines == NO_DISP_LINES_1)
    {
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
      (void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
      fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);

    }
    else
#endif
    {
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
      fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
    }
#else
    if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
    {
      hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
    }
    else
    {
      hmi_menu_logic_View_Mngr_Rq(p_menu_cntrl_SP->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
        , ANIM_MAX_ID
#endif
        , HMI_MENU_SCREEN_ADD);
    }
#endif
  }
  return (fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_UP_action
** Visibility:       global
** Description:      This function process the Menu Up Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          24-Nov-2013 by csakthiv
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_UP_action(MENU_CONTROL_T* p_menu_cntrl_SP)
{
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  UINT16                    fl_start_focus_entry_U16;
  UINT16                    fl_start_focus_line_U16;
#endif
  MENU_CB_RESULT_T          fl_cb_result_e;
  MENU_ANIM_DATA_T          fl_menu_anim_data;
  BOOLEAN                   fl_menu_fs_end_of_list_BOOL;

  fl_cb_result_e = MENU_CB_ACTION_COMPLETED;

  if (p_menu_cntrl_SP != FNULL)
  {
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
    fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
#endif
    fl_menu_anim_data.menu_anim_prev_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    fl_menu_anim_data.menu_anim_prev_menu_id_E = p_menu_cntrl_SP->menu_id;
    fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);

    if (p_menu_cntrl_SP->menu_entry_nbr > 0U)
    {
      if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) == 0U)
      {
        if ((p_menu_cntrl_SP->focus_entry_U16 == 0U) &&
          ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) == 0U) &&
          (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL))
        {
          /* do nothing*/
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
                    /*If the focus entry is at start and rest of the elements are disabled the
                    moving through greyed out elements is blocked by the above, So for moving through the focus line, thus statement is added*/
          if (p_menu_cntrl_SP->focus_line_U16 > p_menu_cntrl_SP->menu_entry_nbr)
          {
            p_menu_cntrl_SP->focus_line_U16++;
          }
#endif
        }
        else
        {
          if (hmi_menu_logic_dynamic_menu_cb_condition(MENU_CB_ACTION_UP, p_menu_cntrl_SP) != FALSE)
          {
            /* this was done like this because applicaiton handles preset and cd track list menu differently
            * For cd tracklist menu,application handles incrementing focus entry,but for preset list menu
            * application does not increment focus entry after window move
            */
            /* start of list is calculated before incr/decr focus entry. otherwise last line will  not displayed */
            /* Menu_completion will be posted before last line. MCA Issue*/
            fl_menu_fs_end_of_list_BOOL = hmi_menu_logic_is_it_start_of_list(p_menu_cntrl_SP);
            hmi_menu_logic_up_focus_entry(p_menu_cntrl_SP);
            fl_cb_result_e = hmi_menu_logic_up_application_cb(p_menu_cntrl_SP, fl_menu_fs_end_of_list_BOOL);
          }
          else
          {
            hmi_menu_logic_up_focus_entry(p_menu_cntrl_SP);
          }
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
          hmi_menu_logic_update_history_info(p_menu_cntrl_SP);
#endif
        }
      }
      else
      {
        hmi_menu_logic_clock_application_cb(MENU_CB_ACTION_UP, p_menu_cntrl_SP);
      }
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
      if ((fl_cb_result_e != MENU_CB_ACTION_WAIT) && (p_menu_cntrl_SP->menu_state != MENU_STATE_FAST))
      {
        /* For wait and fast scrool animation is run from menu core chart. if below funct. is called
        then animation will be changed to focus move up/down*/
        fl_cb_result_e = hmi_menu_logic_get_up_animation(fl_start_focus_entry_U16, fl_start_focus_line_U16, p_menu_cntrl_SP);
      }
#endif
    }
    fl_menu_anim_data.menu_anim_curr_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    fl_menu_anim_data.menu_anim_curr_menu_id_E = p_menu_cntrl_SP->menu_id;
    fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
    fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
    if (p_menu_cntrl_SP->displayed_lines == NO_DISP_LINES_1)
    {
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
      (void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
      fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
    }
    else
#endif
    {
      fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
      fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
    }
#else
    if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
    {
      hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
    }
    else
    {
      hmi_menu_logic_View_Mngr_Rq(p_menu_cntrl_SP->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
        , ANIM_MAX_ID
#endif
        , HMI_MENU_SCREEN_ADD);
    }
#endif
  }
  return (fl_cb_result_e);
}
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/*============================================================================
** Function Name:    hmi_menu_logic_get_down_animation
** Visibility:       menu core
** Description:      This function decides the type of animation to be triggered for down button press
**                   based on focus entry and focus line.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:	         24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_get_down_animation(UINT16 fl_start_focus_entry_U16,UINT16 fl_start_focus_line_U16, MENU_CONTROL_T const *p_menu_cntrl_SP)
{
	UINT16 fl_start_page_no_U16;
	UINT16 fl_new_page_no_U16;
	MENU_CB_RESULT_T fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
	{
		fl_start_page_no_U16 = hmi_menu_logic_get_page_number(fl_start_focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
		fl_new_page_no_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);

		if((p_menu_cntrl_SP->focus_entry_U16 > fl_start_focus_entry_U16 )&&
			(fl_start_page_no_U16 == fl_new_page_no_U16))
		{

			fl_cb_result_e = MENU_CB_ACTION_FOCUS_MOVE_DOWN_ANM;
			#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
				MENU_DO_FRAME_EXPAND_ANIMATION;
			#endif
		}
		if((p_menu_cntrl_SP->focus_entry_U16 > fl_start_focus_entry_U16 )&&
			(fl_start_page_no_U16 != fl_new_page_no_U16))
		{
			/* For static menu window move down*/
			fl_cb_result_e = MENU_CB_ACTION_WNDW_MOVE_DOWN_ANM;
		}
	}
	else
	{
		if(p_menu_cntrl_SP->focus_entry_U16 > fl_start_focus_entry_U16 )
		{
			fl_cb_result_e = MENU_CB_ACTION_FOCUS_MOVE_DOWN_ANM;
			#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
				MENU_DO_FRAME_EXPAND_ANIMATION;
			#endif
		}
		/* below lines wont work if HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT is enabled */
		/* current there is no requirment for HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT in non MENU_PRO_FAST_WINDOW_CHANGE menu */
		/* e.g, MFD TVM MCA */
		if(((fl_start_focus_line_U16  > p_menu_cntrl_SP->focus_line_U16)||((fl_start_focus_line_U16 + 1U)  >= (UINT16)(p_menu_cntrl_SP->displayed_lines)))&&
			(p_menu_cntrl_SP->focus_entry_U16 > fl_start_focus_entry_U16 ))
		{
			/* For static menu window move down*/
			fl_cb_result_e = MENU_CB_ACTION_WNDW_MOVE_DOWN_ANM;
		}
	}
	/* page comparison is not required as wrap around can happen within single page also fe = 4 disp.line =4.*/
	if(p_menu_cntrl_SP->focus_entry_U16 < fl_start_focus_entry_U16)
	{
		if(p_menu_cntrl_SP->menu_entry_nbr != 1U)
		{
			fl_cb_result_e = MENU_CB_ACTION_WRAP_RND_DOWN_ANM;
		}
		else
		{
			fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
		}
	}
	return fl_cb_result_e;
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_up_animation
** Visibility:       menu core
** Description:      This function decides the type of animation to be triggered for up button press
**                   based on focus entry and focus line.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          fl_start_focus_entry_U16, fl_start_focus_line_U16,p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_get_up_animation(UINT16 fl_start_focus_entry_U16,UINT16 fl_start_focus_line_U16, MENU_CONTROL_T const *p_menu_cntrl_SP)
{

	UINT16 fl_start_page_no_U16;
	UINT16 fl_new_page_no_U16;
	MENU_CB_RESULT_T fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
	{
		fl_start_page_no_U16 = hmi_menu_logic_get_page_number(fl_start_focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
		fl_new_page_no_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);

		if((p_menu_cntrl_SP->focus_entry_U16 < fl_start_focus_entry_U16 )&&
			(fl_start_page_no_U16 == fl_new_page_no_U16))
		{
			fl_cb_result_e = MENU_CB_ACTION_FOCUS_MOVE_UP_ANM;
			#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
				MENU_DO_FRAME_EXPAND_ANIMATION;
			#endif
		}

		if((fl_start_page_no_U16 != fl_new_page_no_U16)&&
			(p_menu_cntrl_SP->focus_entry_U16 < fl_start_focus_entry_U16))
		{
			/* For static menu window move down*/
			fl_cb_result_e = MENU_CB_ACTION_WNDW_MOVE_UP_ANM;
		}
	}
	else
	{
		if(p_menu_cntrl_SP->focus_entry_U16 < fl_start_focus_entry_U16 )
		{
			fl_cb_result_e = MENU_CB_ACTION_FOCUS_MOVE_UP_ANM;
			#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
				MENU_DO_FRAME_EXPAND_ANIMATION;
			#endif
		}
		/* below lines wont work if HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT is enabled */
		/* current there is no requirment for HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT in non MENU_PRO_FAST_WINDOW_CHANGE menu */
		/* e.g, MFD TVM MCA */
		if((fl_start_focus_line_U16 == 0U)&&
			(p_menu_cntrl_SP->focus_entry_U16 < fl_start_focus_entry_U16 ))
		{
			/* For static menu window move down*/
			fl_cb_result_e = MENU_CB_ACTION_WNDW_MOVE_UP_ANM;
		}
	}
	/* page comparison is not required as wrap around can happen within single page also fe = 4 disp.line =4.*/
	if(p_menu_cntrl_SP->focus_entry_U16 > fl_start_focus_entry_U16)
	{
		if(p_menu_cntrl_SP->menu_entry_nbr != 1U)
		{
			fl_cb_result_e = MENU_CB_ACTION_WRAP_RND_UP_ANM;
		}
		else
		{
			fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
		}
	}
	return fl_cb_result_e;
}
#endif

#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
/*============================================================================
** Function Name:    hmi_menu_logic_updated_history_info
** Visibility:       global
** Description:      This function calls application interface to update history info(menu id and focus entry)
** Invocation:       Invoked by hmi_menu_core_logic
** Inputs/:          p_menu_cntrl_SP
** Outputs
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static void hmi_menu_logic_update_history_info(MENU_CONTROL_T const *p_menu_cntrl_SP)
{
	if((p_menu_cntrl_SP->menu_properties & MENU_PRO_HISTORY_MENU) != 0U)
	{
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
		HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_SP->menu_id, hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP));
#else
		HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_SP->menu_id, p_menu_cntrl_SP->focus_entry_U16);
#endif
	}
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_down_focus_entry
** Visibility:       global
** Description:      This function do changes in focus entry for down button press
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-csakthiv
** Updated:
**==========================================================================*/

static void hmi_menu_logic_down_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP)
{
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
	UINT16 fl_end_focus_entry_U16;
	if((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
	{
		/*search for the complete menu item*/
		fl_end_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
	}
	else
	{
		fl_end_focus_entry_U16 = p_menu_cntrl_SP->menu_entry_nbr;
	}
#endif
	hmi_menu_logic_incr_till_valid_focus_entry(p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
		, fl_end_focus_entry_U16
#endif
		);
}
/*============================================================================
** Function Name:    hmi_menu_logic_up_focus_entry
** Visibility:       global
** Description:      This function do changes in focus entry for up button press
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static void hmi_menu_logic_up_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP)
{
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
	UINT16 fl_end_focus_entry_U16;
	if((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
	{
		/*search for the complete menu item*/
		fl_end_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
	}
	else
	{
		fl_end_focus_entry_U16 = 0;
	}
#endif
	hmi_menu_logic_decr_till_valid_focus_entry(p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
		,fl_end_focus_entry_U16
#endif
		);
}
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
/*============================================================================
** Function Name:    hmi_menu_logic_handle_greyout_for_incr
** Visibility:       global
** Description:      for increasing till valid focus entry if there exist one or more greyedout element
**                   This function adjusts the focusline to view the greyed out element before moving to next valid element
** Invocation:       Invoked by hmi_menu_logic_incr_till_valid_focus_entry
** Inputs:           p_menu_cntrl_SP,fl_start_focus_line_U16
** Outputs           fl_menu_end_of_list_BOOLL
** Critical Section: None.
** Created:          7-Mar-2024 by ssures15
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_handle_greyout_for_incr(MENU_CONTROL_T* p_menu_cntrl_SP, UINT16* p_start_focus_line_U16)
{
  BOOLEAN fl_menu_end_of_list_BOOL = FALSE;
  UINT16 fl_greyout_count = 0U;
  UINT16 fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
  UINT16 fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
  while (p_menu_cntrl_SP->focus_entry_U16 < p_menu_cntrl_SP->menu_entry_nbr)
  {
    p_menu_cntrl_SP->focus_entry_U16++;

    if (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE)
    {
      fl_greyout_count++;
    }
    else
    {
      break;
    }
  }
  /*resetting the focus entry*/
  /*checks if focus_line is in a valid range */
  if ((p_menu_cntrl_SP->focus_line_U16 > p_menu_cntrl_SP->menu_entry_nbr) || (p_menu_cntrl_SP->focus_line_U16 < p_menu_cntrl_SP->displayed_lines))
  {
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16 + (p_menu_cntrl_SP->displayed_lines - p_menu_cntrl_SP->focus_line_U16);
  }
  /*the visibility of the greyed out element and focus entry is validated here*/
  if ((fl_greyout_count > 0U) && (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE) /*checks if the count is greater than zero and current focus entry is valid*/
    && ((p_menu_cntrl_SP->focus_entry_U16 >= (p_menu_cntrl_SP->menu_entry_nbr - fl_greyout_count)) || /*this is to check if the greyed out elements are in end of list*/
      (fl_greyout_count >= p_menu_cntrl_SP->displayed_lines)))/*this is to check if greyed out element count is greater than the visible elements size*/
  {
    /*if the above conditions are satisfied then the focus line is to be decreased one by one to view the greyed out element one by one*/
    p_menu_cntrl_SP->focus_line_U16--;
    fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
  }
  else
  {	/*if count is zero or the above if statement is false*/
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
    /*the below if is to check if all visible elements are greyed out
    if that was the case then the focus line is changed such that the next valid element is made visible*/
    if ((fl_start_focus_line_U16 >= p_menu_cntrl_SP->displayed_lines) && (fl_start_focus_line_U16 < p_menu_cntrl_SP->menu_entry_nbr))
    {
      p_menu_cntrl_SP->focus_line_U16--;
      fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    }
    else
    {
      /*if none of the condition is met then the focus entry is incremented normally*/
      fl_menu_end_of_list_BOOL = hmi_menu_logic_incr_focus_entry(p_menu_cntrl_SP);
    }
  }
  *p_start_focus_line_U16 = fl_start_focus_line_U16;
  return(fl_menu_end_of_list_BOOL);
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_incr_till_valid_focus_entry
** Visibility:       global
** Description:      This function decrement the focus entry till valid focus entry or fl_end_focus_entry_U16 is reached.
**                   Wrap around property is considered for decrement.
** Invocation:       Invoked by hmi_menu_core_logic
** Inputs:           p_menu_cntrl_SP,fl_end_focus_entry_U16
** Outputs           void
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/

static void hmi_menu_logic_incr_till_valid_focus_entry(MENU_CONTROL_T* p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
  , UINT16 fl_end_focus_entry_U16
#endif
)
{
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
  BOOLEAN fl_menu_end_of_list_BOOL;
  BOOLEAN fl_menu_found_valid_focus_entry_BOOL;
  UINT16 fl_start_focus_entry_U16;
  UINT16 fl_start_focus_line_U16;
#if defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
  BOOLEAN fl_wrap_started = FALSE;
  UINT16 fl_greyout_count = 0U;
#endif
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
  UINT16  fl_page_start_focus_entry_U16 = 0;
  BOOLEAN fl_page_number_changed_BOOL = FALSE;
  UINT8 fl_no_of_pages_changed_U8 = 0;
  UINT16 fl_prev_page_number_U16;
  UINT16 fl_start_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
  UINT16 fl_new_page_number_U16;
  fl_prev_page_number_U16 = fl_start_page_number_U16;
#endif
  fl_menu_found_valid_focus_entry_BOOL = FALSE;
  fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
  fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
  fl_menu_end_of_list_BOOL = hmi_menu_logic_handle_greyout_for_incr(p_menu_cntrl_SP, &fl_start_focus_line_U16);

#else
  fl_menu_end_of_list_BOOL = hmi_menu_logic_incr_focus_entry(p_menu_cntrl_SP);
#endif
  while ((p_menu_cntrl_SP->focus_entry_U16 != fl_end_focus_entry_U16) && (fl_menu_end_of_list_BOOL == FALSE))
  {
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
    if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
    {
      fl_new_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
      if (fl_prev_page_number_U16 != fl_new_page_number_U16)
      {
        /*focus entry is valid even when element inside it are greyed out as we need to show the item to user*/
        /*otherwise greyed out item will never be visible */
        if (fl_page_number_changed_BOOL != TRUE)
        {
          fl_page_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
        }
        fl_page_number_changed_BOOL = TRUE;
        fl_no_of_pages_changed_U8++;
        /* if more than one page is changed then replace focus entry with start focus entry */
        if (fl_no_of_pages_changed_U8 > 1)
        {
          p_menu_cntrl_SP->focus_entry_U16 = fl_page_start_focus_entry_U16;
          hmi_menu_logic_Focusline_Center(p_menu_cntrl_SP);
          fl_menu_found_valid_focus_entry_BOOL = TRUE;
          break;
        }
      }
    }
#endif
    if (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE)
    {
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
      /* here also check for MENU_PRO_FAST_WINDOW_CHANGE is required. But not done to avoid complex in reading*/
      /* there wont be any impact even it was not added */
      fl_prev_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
#endif		
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
      /*the below code is only for wraparound condition*/
      /*when a wrap around occurs the greyed out element count is set to zero and a wrap around flag is set true*/
      if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
      {
        if (p_menu_cntrl_SP->focus_entry_U16 == 0U)
        {
          /*wrap around flag set true*/
          fl_wrap_started = TRUE;
        }
        fl_menu_found_valid_focus_entry_BOOL = TRUE;
        //In case of greyedout element greater than displayed_lines+1 here for example:4 and displayed lines equal to 3
        //breaking after this will abruptly stop the loop at 3 instead of 4 therefore breaking is not necessary 
        //Inorder to make loop go till next valid element
      }
      fl_menu_end_of_list_BOOL = hmi_menu_logic_incr_focus_entry(p_menu_cntrl_SP);
      /*above mentioned wrap around flag is called here to set the focusline below the greyed out element*/
      if (fl_wrap_started == TRUE)
      {
        fl_greyout_count++;
        if (fl_greyout_count >= p_menu_cntrl_SP->displayed_lines)
        {
          p_menu_cntrl_SP->focus_line_U16 = fl_greyout_count;
        }
      }
#else
      fl_menu_end_of_list_BOOL = hmi_menu_logic_incr_focus_entry(p_menu_cntrl_SP);
#endif
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
      if (((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U) &&
        ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U))
      {
        /* If wrap around is enabled, then dont exit for loop until the same focus entry is reached */
        /* if page based focus greyout is required then that menu should defintely be wrap around menu */
        fl_menu_end_of_list_BOOL = FALSE;
      }
#endif
    }
    else
    {
      /* if focus entry is valid then exist the for loop*/
      fl_menu_found_valid_focus_entry_BOOL = TRUE;
      break;
    }
  }
  if (((fl_menu_end_of_list_BOOL == TRUE) && ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) == 0U))
    || (fl_menu_found_valid_focus_entry_BOOL == FALSE))
  {
    /* since no wrap around revert back to last valid focus entry */
    /* it entered here since the focus entry is not valid */
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
    p_menu_cntrl_SP->focus_line_U16 = fl_start_focus_line_U16;
  }
#else
  (void)hmi_menu_logic_incr_focus_entry(p_menu_cntrl_SP);
#endif

}
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
/*============================================================================
** Function Name:    hmi_menu_logic_handle_greyout_for_decr
** Visibility:       global
** Description:      for decreasing till valid focus entry if there exist one or more greyedout element
**                   This function adjusts the focusline to view the greyed out element before moving to next valid element
** Invocation:       Invoked by  hmi_menu_logic_decr_till_valid_focus_entry()
** Inputs:           p_menu_cntrl_SP,start_focus_line_U16
** Outputs           fl_menu_start_of_list_BOOL
** Critical Section: None.
** Created:          7-Mar-2024 by ssures15
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_handle_greyout_for_decr(MENU_CONTROL_T* p_menu_cntrl_SP, UINT16* p_start_focus_line_U16)
{
  UINT16 fl_greyout_count = 0U;
  UINT16 fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
  UINT16 fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
  BOOLEAN fl_menu_start_of_list_BOOL = FALSE;
  //greyout element check: checks how many greyed out elements are present above current focus-entry
  while (p_menu_cntrl_SP->focus_entry_U16 > 0U)
  {
    p_menu_cntrl_SP->focus_entry_U16--;
    if (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE)
    {
      fl_greyout_count++;
    }
    else
    {
      break;
    }
  }
  //reset focus-entry 
  // checks if the focusline is valid for increment
  if (fl_start_focus_line_U16 < p_menu_cntrl_SP->menu_entry_nbr)
  {
    //below is to check the value of focus entry for fl_greyout_count greater than 1, Here the decrement is done with focus line in order to check all the greyed out elements
    //reset focus-entry 
    p_menu_cntrl_SP->focus_entry_U16 = (fl_start_focus_entry_U16 - p_menu_cntrl_SP->focus_line_U16) - 1U;
  }
  if ((fl_greyout_count > 0U) && ((hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE) && /*checks if the count is greater than zero and current focus entry is valid*/
    ((fl_start_focus_entry_U16 <= fl_greyout_count) || (fl_greyout_count >= p_menu_cntrl_SP->displayed_lines))))/*checks if the number of grade out element is at start position or the greyed out elements is greater than the displayed element*/
  {
    p_menu_cntrl_SP->focus_line_U16++;
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
  }
  else
  {
    /*if count 0 or the above cases are not passed*/
    p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
    /*checks if all visible elements are greyed out,if thats the case then focus line is adjusted such that the valid focus entry is made visible*/
    if (fl_start_focus_line_U16 > p_menu_cntrl_SP->menu_entry_nbr)
    {
      p_menu_cntrl_SP->focus_line_U16++;
      fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
    }
    else
    {
      /*if none of the above case is true then the focus entry is incremented normally*/
      fl_menu_start_of_list_BOOL = hmi_menu_logic_decr_focus_entry(p_menu_cntrl_SP);
    }

  }
  *p_start_focus_line_U16 = fl_start_focus_line_U16;
  return fl_menu_start_of_list_BOOL;
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_decr_till_valid_focus_entry
** Visibility:       global
** Description:      This function decrement the focus entry till valid focus entry or fl_end_focus_entry_U16 is reached.
**                   Wrap around property is considered for decrement.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs:           p_menu_cntrl_SP,fl_end_focus_entry_U16
** Outputs           void
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static void hmi_menu_logic_decr_till_valid_focus_entry(MENU_CONTROL_T* p_menu_cntrl_SP
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
  , UINT16 fl_end_focus_entry_U16
#endif
)
{
#if defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
  BOOLEAN fl_menu_found_valid_focus_entry_BOOL = FALSE;
  UINT16 fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
  UINT16 fl_start_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
  BOOLEAN fl_menu_start_of_list_BOOL;
#if defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
  BOOLEAN fl_wrap_started = FALSE;
  UINT16 fl_greyout_count = 0U;
#endif
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
  UINT16 fl_new_page_number_U16;
  BOOLEAN fl_page_number_changed_BOOL = FALSE;
  UINT8   fl_no_of_pages_changed_U8 = 0;
  UINT16  fl_page_start_focus_entry_U16 = 0;
  UINT16 fl_start_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
#endif
  /*NOTE: Changing of the datatype of focus_line_U16 or fl_start_focus_line_U16 may cause issue in code within
  the condition #if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT),
  Since, the focus_line increment or decrement's boundary conditions are coded based on the UINT16 datatype
  Therefore,It is not recommended to change the datatype of focus_line_U16 or fl_start_focus_line_U16 */

#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
  fl_menu_start_of_list_BOOL = hmi_menu_logic_handle_greyout_for_decr(p_menu_cntrl_SP, &fl_start_focus_line_U16);
#else
  fl_menu_start_of_list_BOOL = hmi_menu_logic_decr_focus_entry(p_menu_cntrl_SP);
#endif
  while ((p_menu_cntrl_SP->focus_entry_U16 != fl_end_focus_entry_U16) && (fl_menu_start_of_list_BOOL == FALSE))
  {
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
    if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U)
    {
      fl_new_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
      if (fl_start_page_number_U16 != fl_new_page_number_U16)
      {
        /*focus entry is valid even when element inside it are greyed out as we need to show the item to user*/
        /*otherwise greyed out item will never be visible */
        if (fl_page_number_changed_BOOL != TRUE)
        {
          fl_page_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
        }
        fl_page_number_changed_BOOL = TRUE;
        fl_no_of_pages_changed_U8++;
        /* if more than one page is changed then replace focus entry with start focus entry */
        if (fl_no_of_pages_changed_U8 > 1)
        {
          p_menu_cntrl_SP->focus_entry_U16 = fl_page_start_focus_entry_U16;
          hmi_menu_logic_Focusline_Center(p_menu_cntrl_SP);
          fl_menu_found_valid_focus_entry_BOOL = TRUE;
          break;
        }
      }
    }
#endif

    if (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE)
    {
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
      /* here also check for MENU_PRO_FAST_WINDOW_CHANGE is required. But not done to avoid complex in reading*/
      /* there wont be any impact even it was not added */
      fl_start_page_number_U16 = hmi_menu_logic_get_page_number(p_menu_cntrl_SP->focus_entry_U16, p_menu_cntrl_SP->displayed_lines);
#endif		
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE) && defined(HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE)
      if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
      {
        /*below check is only for wrap around case and will work only when wrap around is visible*/
        if (p_menu_cntrl_SP->focus_entry_U16 == (p_menu_cntrl_SP->menu_entry_nbr - 1U))
        {
          /*wrap around flag set true*/
          fl_wrap_started = TRUE;
        }
        fl_menu_found_valid_focus_entry_BOOL = TRUE;
      }
      fl_menu_start_of_list_BOOL = hmi_menu_logic_decr_focus_entry(p_menu_cntrl_SP);
      if (fl_wrap_started == TRUE)
      {
        fl_greyout_count++;
        if (fl_greyout_count >= p_menu_cntrl_SP->displayed_lines)
        {
          p_menu_cntrl_SP->focus_line_U16 = 0U;
          p_menu_cntrl_SP->focus_line_U16 -= fl_greyout_count - (p_menu_cntrl_SP->displayed_lines - 1U);
        }
      }
#else
      fl_menu_start_of_list_BOOL = hmi_menu_logic_decr_focus_entry(p_menu_cntrl_SP);
#endif
#if defined (HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)
      if (((p_menu_cntrl_SP->menu_properties & MENU_PRO_FAST_WINDOW_CHANGE) != 0U) &&
        ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U))
      {
        /* If wrap around is enabled, then dont exit for loop until the same focus entry is reached */
        /* if page based focus greyout is required then that menu should defintely be wrap around menu */
        fl_menu_start_of_list_BOOL = FALSE;
      }
#endif
    }
    else
    {
      /* valid entry found*/
      fl_menu_found_valid_focus_entry_BOOL = TRUE;
      break;
    }
  }
  /* since it is difficult to compare signed and unsigned int in c , below code is added. otherwise in Up_focus_entry()*/
  /* fl_end_focus_entry_U16 should be set to -1 instead of 0*/
  if ((fl_menu_found_valid_focus_entry_BOOL == FALSE) && (p_menu_cntrl_SP->focus_entry_U16 == fl_end_focus_entry_U16))
  {
    if (hmi_menu_logic_is_focus_entry_valid(p_menu_cntrl_SP) == FALSE)
    {
      /* if no valid focus entry is found untill the end of focus entry, then keep the focus entry and focus line as start*/
      /* since no wrap around revert back to last valid focus entry */
      /* it entered here since the focus entry is not valid */
      p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
      p_menu_cntrl_SP->focus_line_U16 = fl_start_focus_line_U16;
    }
    else
    {
      /* do nothing keep the focus entry same since it is valid. FE = 0 without wrap around */
    }
  }
#else
  (void)hmi_menu_logic_decr_focus_entry(p_menu_cntrl_SP);
#endif
}

/*============================================================================
** Function Name:    hmi_menu_logic_incr_focus_entry
** Visibility:       global
** Description:      This function increment the focus entry and return true if end of list is reached.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_cntrl_SP
** Outputs           TRUE end of list,false not end of list
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_incr_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP)
{
	BOOLEAN fl_end_of_list_BOOL;

	UINT16 fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;

	fl_end_of_list_BOOL = FALSE;

	if ((p_menu_cntrl_SP->focus_entry_U16 + 1U) >= p_menu_cntrl_SP->menu_entry_nbr)
	{
		if((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
		{
			p_menu_cntrl_SP->focus_entry_U16 = 0;
			p_menu_cntrl_SP->focus_line_U16 = 0;
		}
		else
		{
			/* no wrap around . also reached the end of the list. so do nothing */
			p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
			fl_end_of_list_BOOL = TRUE;
		}
	}
	else
	{
		p_menu_cntrl_SP->focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16 + 1U;
		hmi_menu_logic_incr_focus_line(p_menu_cntrl_SP);
	}
	return fl_end_of_list_BOOL;
}
/*============================================================================
** Function Name:    hmi_menu_logic_decr_focus_entry
** Visibility:       global
** Description:      This function decrement the focus entry and return true if start of list is reached.
** Invocation:       Invoked by hmi_menu_core_logic
** Inputs:           p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_decr_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP)
{
	BOOLEAN fl_start_of_list_BOOL;

	UINT16 fl_start_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;

	fl_start_of_list_BOOL = FALSE;

	
	if (p_menu_cntrl_SP->focus_entry_U16 == 0U)
	{
		if((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
		{
			p_menu_cntrl_SP->focus_entry_U16 = (p_menu_cntrl_SP->menu_entry_nbr - 1U);
			#ifdef HMI_MENU_CORE_CENTRE_FOCUS_LINE
			/* Used in L538,TVM and P552 */
			p_menu_cntrl_SP->focus_line_U16 = (MIN_VALUE((p_menu_cntrl_SP->menu_entry_nbr),(p_menu_cntrl_SP->displayed_lines)) - 1U);
			#else
			/* Used in P42 */
			p_menu_cntrl_SP->focus_line_U16 = (p_menu_cntrl_SP->focus_entry_U16 % p_menu_cntrl_SP->displayed_lines);
			#endif
		}
		else
		{
			/* no wrap around . also reached the start of the list. so do nothing */
			p_menu_cntrl_SP->focus_entry_U16 = fl_start_focus_entry_U16;
			fl_start_of_list_BOOL = TRUE;
		}
	}
	else
	{
		p_menu_cntrl_SP->focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16 - 1U;
		hmi_menu_logic_decr_focus_line(p_menu_cntrl_SP);
	}
	return fl_start_of_list_BOOL;
}
/*============================================================================
** Function Name:    hmi_menu_logic_is_focus_entry_valid
** Visibility:       global
** Description:      This function process the Menu Down Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_is_focus_entry_valid(MENU_CONTROL_T const * p_menu_cntrl_SP)
{
	/* skipping the greyed out item is not applicable for dynamic menu as the size of dynamic menu is not equal to entry array ram(normally 10) */
	/* but in c346 mca it is required for media device list menu. but they are configuring both the ram entry array size(16) and number of entry(16) as same*/
	BOOLEAN fl_focus_entry_valid_BOOL = TRUE;
	if(p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID)
	{
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
		UINT16 fl_item_absl_focus_entry_U16;
		MENU_DEF_T const *fl_menu_def_SP;
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
#endif
		if (p_menu_cntrl_SP->focus_entry_U16 < p_menu_cntrl_SP->menu_entry_nbr)
		{
#if defined(HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT) && defined(HMI_MENU_ITEM_CONFIG_FEATURE)
			/* if it is dynamic CD menu where RAM of entry array is less than actual number of entry,then item cb should be configured by*/
			/* application.*/
			if (fl_menu_def_SP->is_menu_item_enable_cb != FNULL)
			{
				fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
				if (TESTBIT(fl_item_absl_focus_entry_U16, BIT7))
				{
					/* if greyed out then entry is invalid ie. skip the entry*/
					fl_focus_entry_valid_BOOL = FALSE;
				}
			}
#endif
		}
	}
	return fl_focus_entry_valid_BOOL;
}
/*============================================================================
** Function Name:    hmi_menu_logic_clock_application_cb
** Visibility:       global
** Description:      This function is to call the application callback for clock property.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          fl_cb_result_e, p_menu_cntrl_SP
** Outputs           void
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:			 15-Feb-2014 by csakthiv
**==========================================================================*/
static void hmi_menu_logic_clock_application_cb(MENU_CB_RESULT_T fl_cb_result_e,
		MENU_CONTROL_T *p_menu_cntrl_SP)
{
	MENU_DEF_T const * fl_menu_def_SP;

	if ((p_menu_cntrl_SP != FNULL) && (p_menu_cntrl_SP->menu_entry_nbr > 0U) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
		if (fl_menu_def_SP->cb != FNULL)
		{
			if (fl_cb_result_e == MENU_CB_ACTION_DOWN)
			{
				if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_INCREMENT,
					p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
				else
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_INCREMENT_FAST,
					p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
			}
			else if (fl_cb_result_e == MENU_CB_ACTION_UP)
			{
				if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_DECREMENT,
					p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
				else
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_DECREMENT_FAST,
					p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
			}
			else
			{
				/* do nothing */
			}
		}
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_dynamic_menu_cb_condition
** Visibility:       global
** Description:      This funciton calls the application callback for dynamic menu .
** Invocation:       hmi_menu_core
** Inputs/:          fl_cb_result_e, p_menu_cntrl_SP
** Outputs           TRUE/FALSE
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_dynamic_menu_cb_condition(MENU_CB_RESULT_T fl_cb_result_e, MENU_CONTROL_T const * p_menu_cntrl_SP)
{
	BOOLEAN fl_menu_dynamic_cb_BOOL = FALSE;
	if(MENU_CB_ACTION_DOWN == fl_cb_result_e)
	{
		if (((p_menu_cntrl_SP->focus_line_U16 + (UINT16)1) >= MIN_VALUE((p_menu_cntrl_SP->menu_entry_nbr),(p_menu_cntrl_SP->displayed_lines)))
				|| ((p_menu_cntrl_SP->focus_entry_U16 + 1U)>= p_menu_cntrl_SP->menu_entry_nbr)
				|| (p_menu_cntrl_SP->menu_state == MENU_STATE_FAST))
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
			{
				/* if all the above conditions are satisfied, then dynamic menu callback has to be called*/
				/* in that case menu core ideally should not increment/decrement focus entry/line*/
				/* for CD dyanmic menu application increment/decrement focus entry, but for preset list menu*/
				/* application does not increment/decrement focus entry. so called the incr/decr always and*/
				/* then application callback is called and app will incre/decr the focus entry if required*/
				fl_menu_dynamic_cb_BOOL =  TRUE;
			}
		}
	}
	else if (MENU_CB_ACTION_UP == fl_cb_result_e)
	{
		if (((p_menu_cntrl_SP->focus_line_U16 == 0U))
			|| (p_menu_cntrl_SP->menu_state == MENU_STATE_FAST))
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
			{
				/* if all the above conditions are satisfied, then dynamic menu callback has to be called*/
				/* in that case menu core ideally should not increment/decrement focus entry/line*/
				/* for CD dyanmic menu application increment/decrement focus entry, but for preset list menu*/
				/* application does not increment/decrement focus entry. so called the incr/decr always and*/
				/* then application callback is called and app will incre/decr the focus entry if required*/
				fl_menu_dynamic_cb_BOOL =  TRUE;
			}
		}
	}
	else
	{
	}
	return fl_menu_dynamic_cb_BOOL;
}
/*============================================================================
** Function Name:    hmi_menu_logic_down_application_cb
** Visibility:       global
** Description:      This function calls the callback of application with menu actions based on focus entry/line
** Invocation:       Invoked by hmi_menu_core_logic
** Inputs/:          p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_down_application_cb(MENU_CONTROL_T *p_menu_cntrl_SP, BOOLEAN fl_menu_fs_end_of_list_BOOL)
{
	MENU_DEF_T const * fl_menu_def_SP;
	MENU_CB_RESULT_T fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	if(p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID)
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
		/* callback only for dynamic menu in both normal and fast scroll mode*/
		if (fl_menu_def_SP->cb != NULL)
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
			{
				if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
				{
					fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_DOWN, p_menu_cntrl_SP, MENU_BTN_INVALID);
					l_end_of_fast_scroll_BOOL = FALSE;
				}
				else
				{
					if (fl_menu_fs_end_of_list_BOOL != FALSE)
					{
						/* End of the list */
						fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_COMPLETION, p_menu_cntrl_SP, MENU_BTN_INVALID);
						/*End of animation reached, Action completed provided to application
							 to build full display and set the flag as true*/
						l_end_of_fast_scroll_BOOL = TRUE;
					}
					else
					{
						p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->displayed_lines - 1U;
						fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_DOWN_FAST, p_menu_cntrl_SP, MENU_BTN_INVALID);
					}
				}
			}
		}
	}
	return fl_cb_result_e;
}
/*============================================================================
** Function Name:    hmi_menu_logic_up_application_cb
** Visibility:       menu core
** Description:      This function calls the callback of application with menu actions based on focus entry/line
** Invocation:       hmi_menu_core
** Inputs/:          p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/

static MENU_CB_RESULT_T hmi_menu_logic_up_application_cb(MENU_CONTROL_T *p_menu_cntrl_SP, BOOLEAN fl_menu_fs_end_of_list_BOOL)
{
	MENU_DEF_T const * fl_menu_def_SP;
	MENU_CB_RESULT_T fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	if(p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID)
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
		/* callback only for dynamic menu in both normal and fast scroll mode*/
		if (fl_menu_def_SP->cb != NULL)
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
			{

				if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
				{
					fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_UP, p_menu_cntrl_SP, MENU_BTN_INVALID);
					l_end_of_fast_scroll_BOOL = FALSE;
				}
				else
				{
					if (fl_menu_fs_end_of_list_BOOL != FALSE)
					{
						/* End of the list */
						fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_COMPLETION, p_menu_cntrl_SP, MENU_BTN_INVALID);
						/*End of animation reached, Action completed provided to application
							 to build full display and set the flag as true*/
						l_end_of_fast_scroll_BOOL = TRUE;
					}
					else
					{
						p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->displayed_lines - 1U;
						fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_UP_FAST, p_menu_cntrl_SP, MENU_BTN_INVALID);
					}
				}
			}
		}
	}
	return fl_cb_result_e;
}
/*============================================================================
** Function Name:    hmi_menu_logic_is_it_end_of_list
** Visibility:       Local
** Description:      Interface to identity whether current focus entry/focus line is in end of list
** Invocation:       Invoked by hmi_menu_logic_DOWN_action ()
** Inputs/:          p_menu_cntrl_SP
** Outputs           TRUE/FALSE
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:          
**==========================================================================*/
static BOOLEAN hmi_menu_logic_is_it_end_of_list(MENU_CONTROL_T const *p_menu_cntrl_SP)
{
	BOOLEAN fl_menu_end_of_list_BOOL;
	UINT16 fl_menu_focus_entryU16;

	fl_menu_end_of_list_BOOL = FALSE;

	fl_menu_focus_entryU16 = p_menu_cntrl_SP->menu_entry_nbr - 1U - p_menu_cntrl_SP->focus_entry_U16;
	if(fl_menu_focus_entryU16 == 0U)
	{
		fl_menu_end_of_list_BOOL = TRUE;
	}

	return fl_menu_end_of_list_BOOL;

}
/*============================================================================
** Function Name:    hmi_menu_logic_is_it_start_of_list
** Visibility:       global
** Description:      Interface to identity whether current focus entry/focus line is in start of list
** Invocation:       Invoked by hmi_menu_logic_UP_action ()
** Inputs/:          p_menu_cntrl_SP
** Outputs           TRUE/FALSE
** Critical Section: None.
** Created:          24-Nov-2013 by csakthiv
** Updated:
**==========================================================================*/
static BOOLEAN hmi_menu_logic_is_it_start_of_list(MENU_CONTROL_T const *p_menu_cntrl_SP)
{
	BOOLEAN fl_menu_end_of_list_BOOL;

	fl_menu_end_of_list_BOOL = FALSE;
	/* below check is modified from previous version verify it again*/
	/* previous check           fl_dec_focus_entry_U16 = MIN_VALUE(p_menu_cntrl_SP->focus_entry_U16, \
            p_menu_cntrl_SP->focus_line_U16+p_menu_cntrl_SP->line_fast_inc);*/

	if((p_menu_cntrl_SP->focus_entry_U16 == 0U)&&
			(p_menu_cntrl_SP->focus_line_U16 == 0U))
	{
		fl_menu_end_of_list_BOOL = TRUE;
	}
	return fl_menu_end_of_list_BOOL;
}
/*============================================================================
** Function Name:    hmi_menu_logic_LEFT_action
** Visibility:       global
** Description:      This function process the Menu Left Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_LEFT_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8)
{
  MENU_CB_RESULT_T          fl_cb_result_e;
  UINT8                     fl_item_entry_type_U8 = 0U;
  UINT16                    fl_entry_array_idx_U16;
  MENU_DEF_T  const        *fl_menu_def_SP;
  UINT16                    fl_item_properties_U16 = 0U;
  BOOLEAN                   fl_disp_update_BOOL;
  MENU_ANIM_DATA_T          fl_menu_anim_data;
  UINT8                     fl_menu_action_U8 = p_menu_action_U8;

  fl_cb_result_e        = MENU_CB_ACTION_NONE;
  fl_disp_update_BOOL   = FALSE;

  if((p_menu_cntrl_SP != FNULL) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
  {
	fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
	if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
	{
		/*For dynamic menu, number of entries may be more than HMI_MAX_MENU_ITEMS. In this case,
		fl_entry_array_idx_U16 will contains actual index instead of absolute index. Also if
		'is_menu_item_enable_cb' is null, then the index value will be taken from focus_line_U16*/
		#ifdef HMI_MENU_ITEM_CONFIG_FEATURE_FOR_DYN_MENU
		if ((fl_menu_def_SP->is_menu_item_enable_cb != FNULL) && (p_menu_cntrl_SP->focus_entry_U16 < HMI_MAX_MENU_ITEMS))
		{
			/* hmi_menu_logic_get_absl_index_focus_entry is not used here intentionally since focus_line_U16 is  set to
			** fl_entry_array_idx_U16 if p_menu_cntrl_SP->focus_entry_U16 > HMI_MAX_MENU_ITEMS
			*/
			fl_entry_array_idx_U16 = p_menu_cntrl_SP->menu_itm_absl_indx[p_menu_cntrl_SP->focus_entry_U16];
			/* clear Gray out item bit */
			fl_entry_array_idx_U16 = fl_entry_array_idx_U16 & (~((UINT16)(BIT7)));
		}
		else
#endif
		{
			fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_line_U16;
		}
	}
	else
	{
		if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) != 0U)
		{
			fl_entry_array_idx_U16 = 0;
		}
		else
		{
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
			fl_entry_array_idx_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
			/* clear Gray out item bit */
			fl_entry_array_idx_U16 = fl_entry_array_idx_U16 & (~((UINT16)(BIT7)));
#else
			fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_entry_U16;
#endif
		}
	}
	if (fl_entry_array_idx_U16 < fl_menu_def_SP->total_entry_nbr)
	{
		fl_item_properties_U16 = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_properties;
		fl_item_entry_type_U8 = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_entry_type;

		fl_menu_anim_data.menu_anim_prev_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
		fl_menu_anim_data.menu_anim_prev_menu_id_E = p_menu_cntrl_SP->menu_id;
		fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
		fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);

		if (fl_item_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_BARGRAPH)
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) != 0U)
			{
				if (p_menu_cntrl_SP->focus_line_U16 == 0U)
				{
					if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND) != 0U)
					{
					p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->menu_entry_nbr;
					}
				}
				else
				{
					p_menu_cntrl_SP->focus_line_U16--;
				}
			}
			if ((fl_menu_def_SP->cb != FNULL) && \
				((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) == 0U))
			{
				if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_DECREMENT, p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
				else
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_DECREMENT_FAST, p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
				fl_cb_result_e = MENU_CB_ACTION_SCALE_ADJ_LEFT_ANM;
				fl_disp_update_BOOL = TRUE;
			}
		}
		else
		{
			if ((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_EXIT) != 0U)
			{
				fl_cb_result_e = MENU_CB_ACTION_EXIT;
			}
			else
			{
				/* irrespective of left/left_long action, for item property BACK open parent menu */
				if ((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_BACK) != 0U)
				{
					fl_menu_action_U8 = MENU_ACTION_LEFT;
				}
				if (p_menu_cntrl_SP->menu_level_U8 != HMI_MENU_LEVEL_0)
				{
					fl_cb_result_e = hmi_menu_logic_left_menu_action(p_menu_cntrl_SP, fl_menu_action_U8);
					fl_disp_update_BOOL = TRUE;
				}
			}
		}
	}
	if (fl_disp_update_BOOL != FALSE)
	{
		fl_menu_anim_data.menu_anim_curr_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
		fl_menu_anim_data.menu_anim_curr_menu_id_E = p_menu_cntrl_SP->menu_id;
		fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
		fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
		fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
		(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
		fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
		fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#else
		fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
		fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#endif
#else
		if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
		{
			hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
		}
		else
		{
			hmi_menu_logic_View_Mngr_Rq(p_menu_cntrl_SP->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
			#ifdef LSH_ANIMATION_SUPPORT_ENABLED
									, ANIM_MAX_ID
			#endif
									, HMI_MENU_SCREEN_ADD);
		}
#endif
	}

  }
  return (fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_RIGHT_action
** Visibility:       global
** Description:      This function process the Menu Right Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_RIGHT_action(MENU_CONTROL_T *p_menu_cntrl_SP)
{
  MENU_CB_RESULT_T            fl_cb_result_e;
  UINT8                       fl_get_menu_inst_U8;
  UINT16                      fl_entry_array_idx_U16;
  const MENU_DEF_T           *fl_sub_menu_def_ptr;
	MENU_DEF_T  const          *fl_menu_def_SP;
	MENU_ANIM_DATA_T            fl_menu_anim_data;
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	BOOLEAN                     fl_itm_gray_out_BOOL;
#endif

	fl_cb_result_e       = MENU_CB_ACTION_NONE;
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	fl_itm_gray_out_BOOL = FALSE;
#endif

	if(p_menu_cntrl_SP != FNULL)
	{
		fl_get_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(p_menu_cntrl_SP->menu_id);
	}
	if((p_menu_cntrl_SP != FNULL)&&(fl_get_menu_inst_U8 < NB_OF_MENU_INSTANCE) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
		if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
		{
			/*For dynamic menu, number of entries may be more than HMI_MAX_MENU_ITEMS. In this case,
			fl_entry_array_idx_U16 will contains actual index instead of absolute index. Also if 
			'is_menu_item_enable_cb' is null, then the index value will be taken from focus_line_U16*/
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE_FOR_DYN_MENU
			if((fl_menu_def_SP->is_menu_item_enable_cb != FNULL) && (p_menu_cntrl_SP->focus_entry_U16 < HMI_MAX_MENU_ITEMS))
			{
				/* hmi_menu_logic_get_absl_index_focus_entry is not used here intentionally since focus_line_U16 is  set to
				** fl_entry_array_idx_U16 if p_menu_cntrl_SP->focus_entry_U16 > HMI_MAX_MENU_ITEMS
				*/
				fl_entry_array_idx_U16 = p_menu_cntrl_SP->menu_itm_absl_indx[p_menu_cntrl_SP->focus_entry_U16];
			}
			else
#endif
			{
				fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_line_U16;
			}
		}
		else
		{
			if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) != 0U)
			{
				fl_entry_array_idx_U16 = 0;
			}
			else
			{
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
				fl_entry_array_idx_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
#else
				fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_entry_U16;
#endif
			}
		}
		fl_menu_anim_data.menu_anim_prev_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
		fl_menu_anim_data.menu_anim_prev_menu_id_E = p_menu_cntrl_SP->menu_id;
		fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
		fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	/* Item Gray out check - No action on it */
		if((TESTBIT(fl_entry_array_idx_U16, (UINT16)BIT7)) && ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != MENU_PRO_DYNAMIC))
		{
			fl_itm_gray_out_BOOL = TRUE;
		}
		if(fl_itm_gray_out_BOOL == FALSE)
		{
#endif
			if (fl_entry_array_idx_U16 < fl_menu_def_SP->total_entry_nbr)
			{
				if ((fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_properties & MENU_ITEM_PRO_DISABLED) == 0U)
				{
					if (fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_entry_type == MENU_ITEM_ENTRY_TYPE_MENU)
					{
						fl_sub_menu_def_ptr = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].utype.sub_menu;
						/* Call callback */
						if (fl_menu_def_SP->cb != NULL)
						{
							fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_RIGHT, p_menu_cntrl_SP, MENU_BTN_INVALID);
						}
						/* Sub menu */
						if (fl_sub_menu_def_ptr != FNULL)
						{
							fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_sub_menu_def_ptr, fl_menu_def_SP, fl_get_menu_inst_U8, MENU_ACTION_OPEN_FROM_PARENT);
							#ifdef LSH_ANIMATION_SUPPORT_ENABLED
							if (fl_cb_result_e != MENU_CB_ACTION_WAIT)
							{
											fl_cb_result_e = MENU_CB_ACTION_WIPER_RIGHT_ANM;
										#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
											MENU_DO_FRAME_EXPAND_ANIMATION;
										#endif
							}
							else
							{
								fl_cb_result_e = MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM;
							}
							#endif
						}
					}
					else if (fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_entry_type == MENU_ITEM_ENTRY_TYPE_BARGRAPH)
					{

						if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) != 0U)
						{
							if ((p_menu_cntrl_SP->focus_line_U16 + 1U) == p_menu_cntrl_SP->menu_entry_nbr)
							{
								if((p_menu_cntrl_SP->menu_properties & MENU_PRO_FOCUS_WRAPAROUND)!= 0U)
								{
									p_menu_cntrl_SP->focus_line_U16 = 0;
								}
							}
							else if (p_menu_cntrl_SP->focus_line_U16 < p_menu_cntrl_SP->menu_entry_nbr)
							{
								p_menu_cntrl_SP->focus_line_U16++;
							}
							else
							{
								/*Do Nothing*/
							}
						}
						if((fl_menu_def_SP->cb != FNULL) && \
							((p_menu_cntrl_SP->menu_properties & MENU_PRO_CLOCK_FORMAT) == 0U))
						{
							if (p_menu_cntrl_SP->menu_state == MENU_STATE_NORMAL)
							{
								(void)fl_menu_def_SP->cb(MENU_ACTION_INCREMENT, p_menu_cntrl_SP, MENU_BTN_INVALID);
							}
							else
							{
								(void)fl_menu_def_SP->cb(MENU_ACTION_INCREMENT_FAST, p_menu_cntrl_SP, MENU_BTN_INVALID);
							}
							fl_cb_result_e = MENU_CB_ACTION_SCALE_ADJ_RIGHT_ANM;
						}
					}
					else
					{
						/*No Action*/
					}
				}
			}
			fl_menu_anim_data.menu_anim_curr_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
			fl_menu_anim_data.menu_anim_curr_menu_id_E = p_menu_cntrl_SP->menu_id;
			fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
			fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
			(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#else
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#endif
#else
			if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
			{
				hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
			}
			else
			{
				hmi_menu_logic_View_Mngr_Rq(p_menu_cntrl_SP->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
				, ANIM_MAX_ID
#endif
				, HMI_MENU_SCREEN_ADD);
			}
#endif
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
		}
#endif
		
	}
	return (fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_OK_action
** Visibility:       global
** Description:      This function process the Menu Ok Action.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_OK_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8)
{
  MENU_CB_RESULT_T      fl_cb_result_e;
  MENU_LIST_ID_T        fl_get_menu_ID_e;
  UINT8                 fl_get_menu_inst_U8;
  UINT8                 fl_get_entry_type_U8= 0U;
  UINT16                fl_entry_array_idx_U16;
  UINT16                fl_item_properties_U16 = 0U;
  const MENU_DEF_T     *fl_sub_menu_ptr;
  MENU_DEF_T  const    *fl_menu_def_SP;
  MENU_ANIM_DATA_T      fl_menu_anim_data;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  BOOLEAN               fl_menu_close_anim_BOOL;
#endif
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
  BOOLEAN               fl_itm_gray_out_BOOL;
#endif
  fl_cb_result_e          = MENU_CB_ACTION_NONE;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  fl_menu_close_anim_BOOL = FALSE;
#endif
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
  fl_itm_gray_out_BOOL = FALSE;
#endif
  if(p_menu_cntrl_SP != FNULL)
  {
    fl_get_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(p_menu_cntrl_SP->menu_id);
  }
  if((p_menu_cntrl_SP != FNULL)&&(fl_get_menu_inst_U8 < NB_OF_MENU_INSTANCE) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
  {
	fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
	if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != 0U)
	{
		/*For dynamic menu, number of entries may be more than HMI_MAX_MENU_ITEMS. In this case,
		fl_entry_array_idx_U16 will contains actual index instead of absolute index. Also if
		'is_menu_item_enable_cb' is null, then the index value will be taken from focus_line_U16*/
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE_FOR_DYN_MENU
			if ((fl_menu_def_SP->is_menu_item_enable_cb != FNULL) && (p_menu_cntrl_SP->focus_entry_U16 < HMI_MAX_MENU_ITEMS))
			{
				/* hmi_menu_logic_get_absl_index_focus_entry is not used here intentionally since focus_line_U16 is  set to
				** fl_entry_array_idx_U16 if p_menu_cntrl_SP->focus_entry_U16 > HMI_MAX_MENU_ITEMS
				*/
				fl_entry_array_idx_U16 = p_menu_cntrl_SP->menu_itm_absl_indx[p_menu_cntrl_SP->focus_entry_U16];
			}
			else
#endif
			{
				fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_line_U16;
			}
	}
	else
	{
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
		fl_entry_array_idx_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
#else
		fl_entry_array_idx_U16 = p_menu_cntrl_SP->focus_entry_U16;
#endif
	}

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	/* Item Gray out check - No action on it */
	if ((TESTBIT(fl_entry_array_idx_U16, (UINT16)BIT7)) && ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) != MENU_PRO_DYNAMIC))
	{
		fl_itm_gray_out_BOOL = TRUE;
	}
	if (fl_itm_gray_out_BOOL == FALSE)
	{
#endif
		if (fl_entry_array_idx_U16 < fl_menu_def_SP->total_entry_nbr)
		{
				fl_item_properties_U16 = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_properties;
				fl_get_entry_type_U8 = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_entry_type;
				fl_menu_anim_data.menu_anim_prev_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
				fl_menu_anim_data.menu_anim_prev_menu_id_E = p_menu_cntrl_SP->menu_id;
				fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
				fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);
				if (fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_MENU)
				{
					if ((fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_properties & MENU_ITEM_PRO_DISABLED) == 0U)
					{
						fl_sub_menu_ptr = fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].utype.sub_menu;

						if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DISABLE_SELECTED_ENTRY) == 0U)
						{
			#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
							p_menu_cntrl_SP->selected_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
			#else
							p_menu_cntrl_SP->selected_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
			#endif
						}

						/* Call callback */
						if (fl_menu_def_SP->cb != NULL)
						{
							fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, p_menu_cntrl_SP, MENU_BTN_INVALID);
						}
						/* Sub menu */

			#ifdef LSH_ANIMATION_SUPPORT_ENABLED
						if (TESTBIT(fl_cb_result_e, HMI_MENU_EXIT_WITH_ANIM_MASK))
						{
							fl_menu_close_anim_BOOL = TRUE;
						}
						if ((fl_sub_menu_ptr != FNULL) &&
							(fl_cb_result_e != MENU_CB_ACTION_EXIT) &&
							(fl_menu_close_anim_BOOL == FALSE))
			#else
						if ((fl_sub_menu_ptr != FNULL) && (fl_cb_result_e != MENU_CB_ACTION_EXIT))
			#endif
						{
							fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_sub_menu_ptr, fl_menu_def_SP, fl_get_menu_inst_U8, MENU_ACTION_OPEN_FROM_PARENT);
			#ifdef LSH_ANIMATION_SUPPORT_ENABLED
							if (fl_cb_result_e != MENU_CB_ACTION_WAIT)
							{
												fl_cb_result_e = MENU_CB_ACTION_WIPER_RIGHT_ANM;
			#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
												MENU_DO_FRAME_EXPAND_ANIMATION;
			#endif
							}
							else
							{
												fl_cb_result_e = MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM;
							}
			#endif
						}
					}
				}

				else if (fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_BARGRAPH)

				{
					if (fl_menu_def_SP->cb != NULL)
					{
						fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, p_menu_cntrl_SP, MENU_BTN_INVALID);
					}
		#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					if (TESTBIT(fl_cb_result_e, HMI_MENU_EXIT_WITH_ANIM_MASK))
					{
						fl_menu_close_anim_BOOL = TRUE;
					}
					if ((fl_cb_result_e != MENU_CB_ACTION_EXIT) && (fl_menu_close_anim_BOOL == FALSE))
		#else
							if (fl_cb_result_e != MENU_CB_ACTION_EXIT)
		#endif
					{
					/* Root menu => Nothing to do */
					fl_cb_result_e = MENU_CB_ACTION_EXIT;
					}
				}
				else if ((fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_LABEL) ||
								(fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_EXE) ||
								(fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_TOGGLE))

				{
					if ((fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].item_properties & MENU_ITEM_PRO_DISABLED) == 0U)
					{
						if (fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_TOGGLE)
						{
									if (*(hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].entry_array.static_array[fl_entry_array_idx_U16].utype.toggle) == TRUE)
									{
										*(hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].entry_array.static_array[fl_entry_array_idx_U16].utype.toggle) = FALSE;
									}
									else
									{
										*(hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].entry_array.static_array[fl_entry_array_idx_U16].utype.toggle) = TRUE;
									}
						}
						if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DISABLE_SELECTED_ENTRY) == 0U)
						{
			#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
									p_menu_cntrl_SP->selected_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP);
			#else
									p_menu_cntrl_SP->selected_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
			#endif
						}
						/* Open the Menu Instance */
						if ((fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_EXE) &&
							(p_menu_action_U8 == MENU_ACTION_OK_IN) &&
							(fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].utype.sub_menu != NULL))
						{
									fl_get_menu_ID_e = hmi_menu_logic_get_menu_index(fl_menu_def_SP->entry_array.static_array[fl_entry_array_idx_U16].utype.sub_menu);
									MENU_CORE_MENU_OPEN(fl_get_menu_ID_e, HMI_MENU_INSTANCE_OPEN_ANIM);
						}
						/* Call callback */
						if (fl_menu_def_SP->cb != NULL)
						{
									fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, p_menu_cntrl_SP, MENU_BTN_INVALID);
						}

						if (fl_get_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_LABEL)
						{
									/* for item entry property BACK, open parent menu */
									if ((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_BACK) != 0U)
									{
														fl_cb_result_e = hmi_menu_logic_left_menu_action(p_menu_cntrl_SP, MENU_ACTION_LEFT);
									}
									else if ((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_EXIT) != 0U)
									{
														fl_cb_result_e = MENU_CB_ACTION_EXIT;
									}
									else
									{
														/* Comment added to fix MISRA Warning 4023158 */
									}
						}

						/* Since in the EXE type of Menu, Ok press shall always open the new Menu
						there is no need to refresh the Menu */
						if (fl_get_entry_type_U8 != MENU_ITEM_ENTRY_TYPE_EXE)
						{
									hmi_menu_logic_Menu_Refresh(p_menu_cntrl_SP->menu_id);
						}
					}
				}
				else
				{
				}

				fl_menu_anim_data.menu_anim_curr_focus_line_U16 = p_menu_cntrl_SP->focus_line_U16;
				fl_menu_anim_data.menu_anim_curr_menu_id_E = p_menu_cntrl_SP->menu_id;
				fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = p_menu_cntrl_SP->focus_entry_U16;
				fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(p_menu_cntrl_SP);
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
				if (fl_menu_anim_data.menu_anim_curr_menu_id_E != fl_menu_anim_data.menu_anim_prev_menu_id_E)
				{
					fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
					(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
					fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
					fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
				}
				else
				{
					fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
					fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
				}
	#else
				fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
				fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
	#endif
	#else
				if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
				{
					hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
				}
				else
				{
					hmi_menu_logic_View_Mngr_Rq(p_menu_cntrl_SP->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
								,ANIM_MAX_ID								
	#endif
								,HMI_MENU_SCREEN_ADD);					
				}
	#endif
		}
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	}
#endif
  }
  return (fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Other_action
** Visibility:       global
** Description:      This function process all the Menu Action other than
                     LEFT/RIGHT/UP/DOWN.
                     1. It calls the specific component CallBack and indicate
                        the Action.
                     2. Holds the return value to settle down in the
                        corresponding states.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/:          p_menu_action_U8, p_menu_cntrl_SP
** Outputs           fl_cb_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_Other_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8)
{
  MENU_CB_RESULT_T       fl_cb_result_e;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  UINT8                  p_menu_anim_ID_U8;
#endif
  fl_cb_result_e       = MENU_CB_ACTION_NONE;
  if(p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID)
  {
	  if (hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].cb != NULL)
	  {
	    fl_cb_result_e = hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].cb((MENU_ACTION_T)p_menu_action_U8, p_menu_cntrl_SP, MENU_BTN_INVALID);
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	    if(TESTBIT(fl_cb_result_e, HMI_MENU_EXIT_WITH_ANIM_MASK))
	    {
	      /*fl_cb_result_e contains 16 bit result. Here we are extracting the first 8 bit data
	      to get the animation id*/
	      p_menu_anim_ID_U8 = (UINT8)(fl_cb_result_e & HMI_MENU_CB_CLOSE_ANIM_MASK);
	      hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id, p_menu_anim_ID_U8);
	    }
	    else if(fl_cb_result_e == MENU_CB_ACTION_EXIT)
	    {
	      /* If menu needs to be close without any animation, then close it through anim_max */
	      hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id, ANIM_MAX_ID);
	    }
	#else
	    if (fl_cb_result_e == MENU_CB_ACTION_EXIT)
	    {
	      hmi_menu_logic_Menu_Close(p_menu_cntrl_SP->menu_id);
	    }
	#endif
		else
		{
			switch(fl_cb_result_e)
			{
			case MENU_CB_ACTION_NONE:
				break;
			case MENU_CB_ACTION_DOWN:
									fl_cb_result_e = hmi_menu_logic_DOWN_action(p_menu_cntrl_SP);
				break;
			case MENU_CB_ACTION_UP:
									fl_cb_result_e = hmi_menu_logic_UP_action(p_menu_cntrl_SP);
				break;
			case MENU_CB_ACTION_RIGHT:
									fl_cb_result_e = hmi_menu_logic_RIGHT_action(p_menu_cntrl_SP);
				break;
			case MENU_CB_ACTION_LEFT:
				fl_cb_result_e = hmi_menu_logic_LEFT_action(p_menu_cntrl_SP, p_menu_action_U8);
				break;
			case MENU_CB_ACTION_OK:
				fl_cb_result_e = hmi_menu_logic_OK_action(p_menu_cntrl_SP, p_menu_action_U8);
				break;
			default:
				/* To fix MISRA Warning C-2012 Rule 16.4 */
				break;
			}
		}
      }
  }
  return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Menu_Refresh
** Visibility:       global
** Description:      This function triggers the presentation from Menu
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs:           p_menu_pre_state_U8 - MENU_PRE_ADD_STATE
                                         - MENU_PRE_REMOVE_STATE
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_Menu_Refresh(MENU_LIST_ID_T p_menu_id_U8)
{
  MENU_CONTROL_T const *fl_menu_rfrsh_ID_ptr;
  LSH_STATE_ID_T fl_menu_screen_id_U8;

  fl_menu_rfrsh_ID_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
  if(fl_menu_rfrsh_ID_ptr != FNULL)
  {
    fl_menu_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_rfrsh_ID_ptr);
		hmi_menu_logic_View_Mngr_Rq(p_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			, ANIM_MAX_ID
#endif
			, HMI_MENU_SCREEN_ADD);
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_Menu_Rebuild
** Visibility:       global
** Description:      This function triggers the reloading of MEnu contents
                     and finally triggers the presentation.
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          01-Dec-2013 by csakthiv
**==========================================================================*/
void hmi_menu_logic_Menu_Rebuild(MENU_LIST_ID_T p_menu_id_U8)
{
	MENU_CONTROL_T        *fl_menu_cntrl_inst_ptr;
	UINT8                  fl_get_menu_inst_U8;
	MENU_CB_RESULT_T       fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	UINT16                 fl_store_focused_entry_U16;
	MENU_ANIM_DATA_T       fl_menu_anim_data;
	#if(HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID) || (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_DECR_TILL_VALID)
	UINT16                 fl_item_absl_focus_entry_U16;
	#endif
	fl_menu_cntrl_inst_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);

	if(fl_menu_cntrl_inst_ptr != FNULL)
	{
		fl_get_menu_inst_U8    = hmi_menu_logic_get_menu_inst_no(p_menu_id_U8);
		if(fl_get_menu_inst_U8 < NB_OF_MENU_INSTANCE)
		{
			fl_menu_anim_data.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_inst_ptr->focus_line_U16;
			fl_menu_anim_data.menu_anim_prev_menu_id_E = fl_menu_cntrl_inst_ptr->menu_id;
			fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_inst_ptr->focus_entry_U16;
			fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_inst_ptr);

			#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
				fl_store_focused_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_cntrl_inst_ptr);;
				fl_store_focused_entry_U16 = fl_store_focused_entry_U16 & (~((UINT16)(BIT7)));
			#endif


			hmi_menu_logic_create_menu(p_menu_id_U8, fl_get_menu_inst_U8);
			if(fl_menu_cntrl_inst_ptr->menu_id < TOTAL_MENU_ID)
			{
				if(hmi_menu_const_struct_array_table[fl_menu_cntrl_inst_ptr->menu_id].cb != FNULL)
				{
					fl_cb_result_e = hmi_menu_const_struct_array_table[fl_menu_cntrl_inst_ptr->menu_id].cb(MENU_ACTION_REBUILD,\
					fl_menu_cntrl_inst_ptr, MENU_BTN_INVALID);
				}
				#ifdef LSH_ANIMATION_SUPPORT_ENABLED
				if(fl_cb_result_e != MENU_CB_ACTION_WAIT)
				{
					fl_cb_result_e = MENU_CB_ACTION_REBUILD_ANM;
				}
				else
				{
					/* menu chart will enter into wait state*/
				}
				#endif

				#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
					/* check is made to ensure that the stored item is present after rebuild.
					Also if the item is not present then the last saved itm value is updated 
					inside the hmi_menu_app_get_stored_menu_item() and the default value is considered */
				#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
				if((fl_menu_cntrl_inst_ptr->menu_properties & MENU_PRO_HISTORY_MENU) != 0U)
				{
					fl_store_focused_entry_U16 = hmi_menu_app_get_stored_menu_item(fl_menu_cntrl_inst_ptr->menu_id);
				}
				#endif
				/* Should not be a Dynamic Menu */
				if((fl_menu_cntrl_inst_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U)
				{
						hmi_menu_logic_set_valid_focus_entry(fl_menu_cntrl_inst_ptr, fl_store_focused_entry_U16);
				}

				/*Here we are checking the 'is_menu_item_enable_cb != null' validation to ensure that absolute
					index is updated for dynamic menu.*/
				/*if static || (dynamic && is_menu_item_enable_cb != null && focus_entry < HMI_MAX_MENU_ITEMS) */
				if(((fl_menu_cntrl_inst_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U) ||
					((hmi_menu_const_struct_array_table[fl_menu_cntrl_inst_ptr->menu_id].is_menu_item_enable_cb != FNULL) &&
					(fl_menu_cntrl_inst_ptr->focus_entry_U16 < HMI_MAX_MENU_ITEMS)))
				{
							#if (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID)
								fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_cntrl_inst_ptr);
								if(TESTBIT(fl_item_absl_focus_entry_U16,BIT7))
								{
									/* on reload's rebuild if the current focus entry is greyout, then increment fe till valid fe */
									hmi_menu_logic_down_focus_entry(fl_menu_cntrl_inst_ptr);
								}
							#elif (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_DECR_TILL_VALID)
								fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_cntrl_inst_ptr);
								if(TESTBIT(fl_item_absl_focus_entry_U16,(UINT16)BIT7))
								{
									/* on reload's rebuild if the current focus entry is greyout, then decrement fe till valid fe */
									hmi_menu_logic_up_focus_entry(fl_menu_cntrl_inst_ptr);
								}
							#else
								/* do nothing.keep the focus entry in the greyed out item itself */
							#endif
					}

					if ((fl_menu_cntrl_inst_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U)
					{
						hmi_menu_logic_Focusline_Center(fl_menu_cntrl_inst_ptr);
					}
					#endif
					fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_inst_ptr->focus_line_U16;
					fl_menu_anim_data.menu_anim_curr_menu_id_E = fl_menu_cntrl_inst_ptr->menu_id;
					fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_inst_ptr->focus_entry_U16;
					fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_inst_ptr);

		#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
					if(fl_menu_cntrl_inst_ptr->displayed_lines == NO_DISP_LINES_1)
					{
							fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
							(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
							fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
							fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
					}
					else
					{
							fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
							fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
					}
			#else
					fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
					fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			#endif
		#else
					hmi_menu_logic_View_Mngr_Rq(p_menu_id_U8, fl_menu_anim_data.menu_anim_curr_screen_id_U8
						#ifdef LSH_ANIMATION_SUPPORT_ENABLED
							, ANIM_MAX_ID
						#endif
							, HMI_MENU_SCREEN_ADD);
	#endif
					/*Update the callback result to menu core chart like animation,please wait or completed*/
					hmi_menu_chart_menu_rebuild(&l_menu_core_chart_inst_array[fl_get_menu_inst_U8],fl_cb_result_e);
			}
		}
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_Menu_ReinitAction
** Visibility:       global
** Description:      Reinitialization Actions are performed.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/Outputs:   p_menu_cntrl_SP
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_logic_Menu_ReinitAction(MENU_CONTROL_T *p_menu_cntrl_SP)
{
  MENU_CB_RESULT_T       fl_cb_result_e;
  fl_cb_result_e = hmi_menu_logic_Other_action(p_menu_cntrl_SP, MENU_ACTION_REINIT);
  return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_MenuDataAvailable
** Visibility:       global
** Description:      After the Data is recieved then the Menu Actions are done here
** Invocation:       Invoked by Menu chart
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          23-July-2014 by csakthiv
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_logic_MenuDataAvailable(MENU_LIST_ID_T p_menu_id_U8)
{
  MENU_CONTROL_T        *fl_menu_cntrl_ptr;
  MENU_CB_RESULT_T      fl_cb_result_e;
  UINT8                 fl_menu_inst_idx_U8;
  MENU_ANIM_DATA_T      fl_menu_anim_data;
  
  fl_cb_result_e      = MENU_CB_ACTION_NONE;
  fl_menu_inst_idx_U8 = hmi_menu_logic_get_menu_inst_no(p_menu_id_U8);
  fl_menu_cntrl_ptr   = hmi_menu_logic_get_required_menu_instance(fl_menu_inst_idx_U8);
  
  if((fl_menu_cntrl_ptr != FNULL) && (fl_menu_inst_idx_U8 < NB_OF_MENU_INSTANCE))
  {
	fl_menu_anim_data.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
	fl_menu_anim_data.menu_anim_prev_menu_id_E      = fl_menu_cntrl_ptr->menu_id;
    fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
	fl_menu_anim_data.menu_anim_prev_screen_id_U8   = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);

	fl_menu_cntrl_ptr   = &l_menu_instance_array[fl_menu_inst_idx_U8]; 

    if ((fl_menu_cntrl_ptr->menu_id < TOTAL_MENU_ID) && (hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id].cb != NULL))
    {
      if(FALSE != l_end_of_fast_scroll_BOOL)
      {
        /*Once the End of list or Start of list reached during fast scroll on last
          request response we need to Stop the fast scroll animation and change
          the mode to normal to get the full display.*/
        hmi_menu_fast_scroll_inactive(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8]);
        l_end_of_fast_scroll_BOOL = FALSE;
      }
      fl_cb_result_e = hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id].cb(MENU_ACTION_DATA_AVAIL, fl_menu_cntrl_ptr, MENU_BTN_INVALID);
      #ifdef LSH_ANIMATION_SUPPORT_ENABLED
		#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
     		MENU_DO_FRAME_EXPAND_ANIMATION;
	 	#endif
	  #endif
    }
    fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
    fl_menu_anim_data.menu_anim_curr_menu_id_E       = fl_menu_cntrl_ptr->menu_id;
	fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
	fl_menu_anim_data.menu_anim_curr_screen_id_U8    = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
	fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
	#else
	if(MENU_CB_ACTION_EXIT == fl_cb_result_e)
	{
		hmi_menu_logic_Menu_Close(fl_menu_cntrl_ptr->menu_id);
	}
	else
	{
			hmi_menu_logic_View_Mngr_Rq(fl_menu_cntrl_ptr->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
				, ANIM_MAX_ID
#endif
				, HMI_MENU_SCREEN_ADD);
	}
	#endif
  }
  return(fl_cb_result_e);
}

/*============================================================================
** Function Name:    hmi_menu_logic_MenuCompletion
** Visibility:       global
** Description:      After completion of the Fast Scroll the Menu Actions are
**                   handled to bring the display.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/Outputs:   p_menu_def_ptr
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_logic_MenuCompletion(
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
	MENU_LIST_ID_T p_menu_id_U8
#else
	void
#endif
	)
{
	MENU_CB_RESULT_T    fl_cb_result_e = MENU_CB_ACTION_NONE;

#ifdef HMI_MENU_FAST_SCROLL_ENABLE
	MENU_CONTROL_T      *fl_menu_cntrl_ptr;
	MENU_ANIM_DATA_T      fl_menu_anim_data;

	fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);

	if (fl_menu_cntrl_ptr != FNULL)
	{
		fl_menu_anim_data.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
		fl_menu_anim_data.menu_anim_prev_menu_id_E     = fl_menu_cntrl_ptr->menu_id;
		fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
		fl_menu_anim_data.menu_anim_prev_screen_id_U8   = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);
		fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
		fl_menu_anim_data.menu_anim_curr_menu_id_E     = fl_menu_cntrl_ptr->menu_id;
		fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
		fl_menu_anim_data.menu_anim_curr_screen_id_U8   = fl_menu_anim_data.menu_anim_prev_screen_id_U8;

		if (hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id].cb != NULL)
		{
			fl_cb_result_e = hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id].cb(MENU_ACTION_COMPLETION, fl_menu_cntrl_ptr, MENU_BTN_INVALID);
		}
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
		fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
		fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#else
		hmi_menu_logic_View_Mngr_Rq(fl_menu_cntrl_ptr->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			, ANIM_MAX_ID
#endif
			, HMI_MENU_SCREEN_ADD);
#endif
	}
#endif
	return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Set_MenuState
** Visibility:       global
** Description:      After completion of the Fast Scroll the Menu Actions are
**                   handled to bring the display.
** Invocation:       Invoked by hmi_menu_chart_process_menu_action ()
** Inputs/Outputs:   p_menu_def_ptr
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_Set_MenuState(MENU_LIST_ID_T p_menu_id_U8,UINT8 p_menu_state_U8)
{
  MENU_CONTROL_T      *fl_menu_cntrl_ptr;
  fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
  if(fl_menu_cntrl_ptr != FNULL)
  {
     fl_menu_cntrl_ptr->menu_state = p_menu_state_U8;
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_process_menu_action
** Visibility:       global
** Description:      This function routes to the respective Menu Button function
**                   handlers to process the button.
** Invocation:       Invoked by hmi_chart.c
** Inputs/Outputs:   p_menu_action_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_logic_process_menu_action(MENU_LIST_ID_T p_menu_id_U8, UINT8 p_menu_action_U8)
{
	MENU_CB_RESULT_T        fl_cb_result_e;
	MENU_CONTROL_T         *fl_menu_cntrl_ptr;
	fl_cb_result_e    = MENU_CB_ACTION_NONE;

	fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);

	if(fl_menu_cntrl_ptr != FNULL)
	{
		switch (p_menu_action_U8)
		{
		case MENU_ACTION_UP:
		case MENU_ACTION_UP_FAST:
				fl_cb_result_e = hmi_menu_logic_UP_action(fl_menu_cntrl_ptr);
			break;
		case MENU_ACTION_DOWN:
		case MENU_ACTION_DOWN_FAST:
				fl_cb_result_e = hmi_menu_logic_DOWN_action(fl_menu_cntrl_ptr);
			break;
		case MENU_ACTION_LEFT:
		case MENU_ACTION_LEFT_LONG:
			fl_cb_result_e = hmi_menu_logic_LEFT_action(fl_menu_cntrl_ptr, p_menu_action_U8);
			break;
		case MENU_ACTION_RIGHT:
		case MENU_ACTION_RIGHT_LONG:
				fl_cb_result_e = hmi_menu_logic_RIGHT_action(fl_menu_cntrl_ptr);
			break;
		case MENU_ACTION_OK_IN:
		case MENU_ACTION_OK_LONG:
		case MENU_ACTION_OK_RELEASE:
			fl_cb_result_e = hmi_menu_logic_OK_action(fl_menu_cntrl_ptr, p_menu_action_U8);
			break;
		default:
			fl_cb_result_e = hmi_menu_logic_Other_action(fl_menu_cntrl_ptr, p_menu_action_U8);
			break;
		}
	}
	return(fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Set_SelectEntry
** Visibility:       global
** Description:      This function is used to set the particular Menu item
**                   as selected one. Application should call this interface 
**                   in MENU_ACTION_OPEN so that both focus and selected entry will be same.
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_def_ptr, p_entry_S16
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          24-Oct-2013 by csakthiv
**==========================================================================*/
void hmi_menu_logic_Set_SelectEntry(MENU_CONTROL_T *p_menu_cntrl_SP, UINT16 p_entry_S16)
{
  /* Selected value is loaded */
  if((p_menu_cntrl_SP->menu_properties & MENU_PRO_DISABLE_SELECTED_ENTRY) == 0U)
  {
    p_menu_cntrl_SP->selected_entry_U16 = p_entry_S16;
  }
  /* Validate and update the selected and focus entry value */
  if (p_menu_cntrl_SP->selected_entry_U16 == MENU_INVALID_ENTRY)
  {
    /* Set focus on the first entry */
    p_menu_cntrl_SP->focus_entry_U16 = 0;
  }
  else
  {
    if((p_menu_cntrl_SP->menu_properties & MENU_PRO_DISABLE_SELECTED_ENTRY) == 0U)
    {
       #ifdef HMI_MENU_ITEM_CONFIG_FEATURE
    	p_menu_cntrl_SP->focus_entry_U16 = hmi_menu_logic_get_focus_entry(p_menu_cntrl_SP,p_menu_cntrl_SP->selected_entry_U16);
       #else
         p_menu_cntrl_SP->focus_entry_U16 = p_menu_cntrl_SP->selected_entry_U16; 
       #endif
	  }
  }
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
  #ifdef HMI_MENU_ITEM_CONFIG_FEATURE
     HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_SP->menu_id, hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_SP));
  #else
     HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_SP->menu_id, p_menu_cntrl_SP->focus_entry_U16);
  #endif
#endif
  /* To make the focus line on the center of the display */
  hmi_menu_logic_Focusline_Center(p_menu_cntrl_SP);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Focusline_Center
** Visibility:       global
** Description:      Focus line position handling while opening the Menu
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_cntrl_SP
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_Focusline_Center(MENU_CONTROL_T *p_menu_cntrl_SP)
{
  if ((p_menu_cntrl_SP->focus_entry_U16 < (p_menu_cntrl_SP->displayed_lines >> 1U)) || \
    (p_menu_cntrl_SP->menu_entry_nbr <= p_menu_cntrl_SP->displayed_lines))
  {
    p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_entry_U16;
  }
  else
  {
#ifdef HMI_MENU_CORE_CENTRE_FOCUS_LINE
    /* Used in L538,TVM and P552 */
    if (p_menu_cntrl_SP->focus_entry_U16 >= (p_menu_cntrl_SP->menu_entry_nbr - (p_menu_cntrl_SP->displayed_lines >> 1)))
    {
      p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_entry_U16 - (p_menu_cntrl_SP->menu_entry_nbr - p_menu_cntrl_SP->displayed_lines);
    }
    else
    {
      p_menu_cntrl_SP->focus_line_U16 = ((UINT16)(p_menu_cntrl_SP->displayed_lines - (UINT16)1)) >> (UINT16)1;
    }
#else
    /* Used in P42 */
    p_menu_cntrl_SP->focus_line_U16 = ((UINT16)((p_menu_cntrl_SP->focus_entry_U16) % (p_menu_cntrl_SP->displayed_lines))) ;
#endif

  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_set_valid_focus_entry
** Visibility:       global
** Description:      This function is used for validating the stored focus entry
**                   and assigning the proper value.
** Invocation:       Invoked by Menu core
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          03-May-2010 by jpradeep
** Updated:          03-May-2010 by jpradeep
**==========================================================================*/
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
static void hmi_menu_logic_set_valid_focus_entry(MENU_CONTROL_T *p_menu_cntrl_SP, UINT16 p_store_focused_entry_U16)
{
	UINT16 fl_menu_entry;
	UINT16 fl_get_absl_indx_val_U16;
	BOOLEAN fl_item_config_BOOL;
	UINT16 fl_store_focused_entry_U16 = p_store_focused_entry_U16;
	fl_item_config_BOOL = FALSE;
	fl_store_focused_entry_U16 = fl_store_focused_entry_U16 & (~((UINT16)(BIT7))); /*clear gray out bit*/

	if (p_menu_cntrl_SP != FNULL)
	{
		for (fl_menu_entry = 0; fl_menu_entry < p_menu_cntrl_SP->menu_entry_nbr; fl_menu_entry++)
		{
			fl_get_absl_indx_val_U16 = p_menu_cntrl_SP->menu_itm_absl_indx[fl_menu_entry];
			fl_get_absl_indx_val_U16 = fl_get_absl_indx_val_U16 & (~((UINT16)(BIT7))); /*clear gray out bit*/
			if (fl_get_absl_indx_val_U16 == fl_store_focused_entry_U16)
			{
				p_menu_cntrl_SP->focus_entry_U16 = fl_menu_entry;
				fl_item_config_BOOL = TRUE;
				break;
			}
		}
		if (fl_item_config_BOOL == FALSE)
		{
			p_menu_cntrl_SP->focus_entry_U16 = 0;
		}
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
		hmi_menu_logic_update_history_info(p_menu_cntrl_SP);
#endif
	}
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_CreateLabel_Items
** Visibility:       global
** Description:      This function is used for quick Creation of the
**                   Menu items with similar type - Label
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_item_entry_ptr
                     p_nb_entries_U16
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_CreateLabel_Items(MENU_ITEM_ENTRY_T *p_item_entry_ptr, UINT16 p_nb_entries_U16)
{
  UINT16 ind;
  for (ind = 0 ; ind < p_nb_entries_U16; ind++)
  {
    p_item_entry_ptr[ind].item_entry_type = MENU_ITEM_ENTRY_TYPE_LABEL;
    p_item_entry_ptr[ind].item_properties = MENU_ITEM_PRO_LABEL_ID;
    p_item_entry_ptr[ind].item_symbol     = 0;
    p_item_entry_ptr[ind].utype.sub_menu  = FNULL;
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_CreateMenu_Items
** Visibility:       global
** Description:      This function is used for quick Creation of the
**                   Menu items with similar type - Menu
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_item_entry_ptr
                     p_nb_entries_U16
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_CreateMenu_Items(MENU_ITEM_ENTRY_T *p_item_entry_ptr, UINT16 p_nb_entries_U16)
{
  UINT16 ind;
  for (ind = 0 ; ind < p_nb_entries_U16; ind++)
  {
    p_item_entry_ptr[ind].item_entry_type = MENU_ITEM_ENTRY_TYPE_MENU;
    p_item_entry_ptr[ind].item_properties = 0;
    p_item_entry_ptr[ind].utype.sub_menu  = FNULL;
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_MenuIsOpen
** Visibility:       global
** Description:      This function Checks whether the Requested Menu is open or not
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
BOOLEAN hmi_menu_logic_MenuIsOpen(MENU_LIST_ID_T p_menu_id_U8)
{
  BOOLEAN         fl_status_BOOL = FALSE;
  MENU_CONTROL_T   const *fl_menu_inst_ID_ptr;

  fl_menu_inst_ID_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
  if(fl_menu_inst_ID_ptr != FNULL)
  {
    fl_status_BOOL = TRUE;
  }
  return(fl_status_BOOL);
}
/*============================================================================
** Function Name:    hmi_menu_logic_Get_MenuTimeOut
** Visibility:       global
** Description:      This function returns the Menu Timeout value
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          19-Feb-2013 by csakthiv
**==========================================================================*/
UINT8 hmi_menu_logic_get_menu_timeout_value(MENU_LIST_ID_T p_menu_id_U8)
{
  UINT8 fl_timeOut_U8 = 0U;
  if (p_menu_id_U8 < TOTAL_MENU_ID)
  {
	fl_timeOut_U8 = hmi_menu_const_struct_array_table[p_menu_id_U8].timeout;

	#ifdef HMI_MENU_TIMEOUT_CONGIF_FEATURE_ENABLE
	if((UINT8)HMI_MENU_ITEM_TIMEOUT_CONFIGURABLE == fl_timeOut_U8)
	{
	  fl_timeOut_U8 = HMI_MENU_TIMEOUT_INTERFACE();
	}
	#endif
  }

  return(fl_timeOut_U8);
}

/*============================================================================
** Function Name:    hmi_menu_logic_Set_ParentFocus
** Visibility:       global
** Description:      This function sets the fouces marker while coming back
**                   and loading the Parent Menu from SubMenu.
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   p_menu_cntrl_ptr, p_sub_menu_ptr
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
static void hmi_menu_logic_Set_ParentFocus(MENU_CONTROL_T *p_menu_cntrl_ptr, const MENU_DEF_T *p_sub_menu_ptr)
{
    UINT16 ind;
    UINT8 fl_get_itm_entry_type_U8;
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
    UINT16 fl_get_itm_absl_indx_U16;
#endif
    MENU_DEF_T const *fl_get_sub_menu_SP;
    MENU_DEF_T const *fl_menu_def_SP;

    if ((p_menu_cntrl_ptr != FNULL) && (p_menu_cntrl_ptr->menu_id < TOTAL_MENU_ID))
    {
        fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
        for (ind = 0; ind < p_menu_cntrl_ptr->menu_entry_nbr; ind++)
        {
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
            fl_get_itm_absl_indx_U16 = (UINT16)p_menu_cntrl_ptr->menu_itm_absl_indx[ind];
            fl_get_itm_absl_indx_U16 = fl_get_itm_absl_indx_U16 & (~((UINT16)(BIT7)));
	  
            if (fl_get_itm_absl_indx_U16 < fl_menu_def_SP->total_entry_nbr)
            {
                fl_get_itm_entry_type_U8 = fl_menu_def_SP->entry_array.static_array[fl_get_itm_absl_indx_U16].item_entry_type;
                fl_get_sub_menu_SP = fl_menu_def_SP->entry_array.static_array[fl_get_itm_absl_indx_U16].utype.sub_menu;
                if ((fl_get_itm_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_MENU) && (fl_get_sub_menu_SP == p_sub_menu_ptr))
                {
                    /* Set parent focus to the current menu */
                    p_menu_cntrl_ptr->focus_entry_U16 = ind;
                    break;
                }
            }
#else
            fl_get_itm_entry_type_U8 = fl_menu_def_SP->entry_array.static_array[ind].item_entry_type;
            fl_get_sub_menu_SP = fl_menu_def_SP->entry_array.static_array[ind].utype.sub_menu;
            if ((fl_get_itm_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_MENU) && (fl_get_sub_menu_SP == p_sub_menu_ptr))
            {
            /* Set parent focus to the current menu */
            p_menu_cntrl_ptr->focus_entry_U16 = ind;
            break;
            }
#endif
        }
#ifdef HMI_MENU_HISTORY_HANDLING_FEATURE
        /* Below code is to store the focus entry when the incoming menu(p_sub_menu_ptr) is hidden dynamically.
        In this case above for loop will be failed to update the history as fl_menu_def_SP->entry_array does
        not containg the incoming menu item. So by default the focus entry will be pointing to zero. This value
        needs to updated in the history*/
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
        HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_ptr->menu_id, hmi_menu_logic_get_absl_index_focus_entry(p_menu_cntrl_ptr));
#else
        HMI_MENU_HISTORY_STORE_MENU_ITEM(p_menu_cntrl_ptr->menu_id, p_menu_cntrl_ptr->focus_entry_U16);
#endif
#endif
        p_menu_cntrl_ptr->menu_level_U8 = hmi_menu_logic_get_Menu_level(p_menu_cntrl_ptr->menu_id);
    }
}

/*============================================================================
** Function Name:    hmi_menu_logic_Is_CurrentMenuOpen
** Visibility:       global
** Description:      This function Checks whether the focused Menu is open or not.
** Invocation:       Invoked by Application
** Inputs:           None
** Outputs:          BOOLEAN
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
BOOLEAN hmi_menu_logic_Is_CurrentMenuOpen(void)
{
  BOOLEAN fl_ret_status_BOOL;
  fl_ret_status_BOOL  = FALSE;

  if(Current_focus_menu_ptr != FNULL)
  {
    fl_ret_status_BOOL = TRUE;
  }
  return(fl_ret_status_BOOL);
}
/*============================================================================
** Function Name:    hmi_menu_logic_View_Mngr_Rq
** Visibility:       global
** Description:      This function adds the state to the View Manager
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   p_menu_id_U8, p_CB_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          24-Jan-2014 by csakthiv
**==========================================================================*/
static void hmi_menu_logic_View_Mngr_Rq(MENU_LIST_ID_T fl_menu_id_E, LSH_STATE_ID_T fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	, UINT8 fl_anim_id_U8
#endif
	, UINT8 fl_screen_action_U8)
{
	if(fl_screen_action_U8 == HMI_MENU_SCREEN_ADD)
	{
		(void)LSH_ADD_STATE_EXT(fl_menu_screen_id_U8,fl_anim_id_U8,fl_menu_id_E);
	}
	else if(fl_screen_action_U8 == HMI_MENU_SCREEN_REMOVE)
	{
		(void)LSH_REM_STATE_EXT(fl_menu_screen_id_U8,fl_anim_id_U8,fl_menu_id_E);
	}
	else
	{
		/* do nothing */
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_Close_all_Menu
** Visibility:       global
** Description:      This function adds the state to the View Manager
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   p_menu_id_U8, p_CB_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_Close_all_Menu(void)
{
	UINT8 fl_instance;
	for (fl_instance = 0; fl_instance < NB_OF_MENU_INSTANCE; fl_instance++)
	{
		if (l_menu_instance_array[fl_instance].inst_status_BOOL != HMI_MENU_LOGIC_INST_INACTIVE)
		{
			MENU_CORE_MENU_CLOSE(l_menu_instance_array[fl_instance].menu_id, ANIM_MAX_ID);
		}
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_activate_animation
** Visibility:       global
** Description:      This function shall activate the Menu animation to LSH
** Invocation:       Invoked by hmi_menu_core_chart/logic.c
** Inputs/Outputs:   p_menu_id_U8, p_CB_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
void hmi_menu_logic_activate_animation(MENU_LIST_ID_T p_menu_id_U8, MENU_CB_RESULT_T p_menu_cb_actn_e)
{
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
	MENU_CONTROL_T       const *fl_menu_cntrl_ptr;
	LSH_STATE_ID_T       fl_logic_st_id_U8;
	MENU_ANIM_DATA_T     fl_anim_data_SA;
	UINT8                fl_anim_id_U8;

	fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
	if(fl_menu_cntrl_ptr != FNULL)
	{
		fl_logic_st_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);
		fl_anim_data_SA.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
		fl_anim_data_SA.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
		fl_anim_data_SA.menu_anim_prev_menu_id_E = fl_menu_cntrl_ptr->menu_id;
		fl_anim_data_SA.menu_anim_curr_menu_id_E = fl_menu_cntrl_ptr->menu_id;
		fl_anim_data_SA.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
		fl_anim_data_SA.menu_anim_prev_screen_id_U8 = fl_logic_st_id_U8;
		fl_anim_data_SA.menu_anim_curr_screen_id_U8 = fl_logic_st_id_U8;
        fl_anim_data_SA.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
        fl_anim_data_SA.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
		fl_anim_id_U8 = hmi_menu_logic_get_animation_ID(&fl_anim_data_SA, p_menu_cb_actn_e);
		hmi_menu_logic_View_Mngr_Rq(p_menu_id_U8, fl_logic_st_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			, fl_anim_id_U8
#endif
			, HMI_MENU_SCREEN_ADD);
	}
#else
	/*QAC 8.1.2 Fix.*/
	p_menu_id_U8 = p_menu_id_U8;
	p_menu_cb_actn_e = p_menu_cb_actn_e;
#endif
}
/*============================================================================
** Function Name:    hmi_menu_logic_deactivate_animation
** Visibility:       global
** Description:      This function shall deactivate the Menu animation to LSH
** Invocation:       Invoked by hmi_menu_core_chart/logic.c
** Inputs/Outputs:   MENU_CB_RESULT_T p_menu_cb_actn_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          30-Jan-2014 by csakthiv
**==========================================================================*/
void hmi_menu_logic_deactivate_animation(MENU_LIST_ID_T p_menu_id_U8, MENU_CB_RESULT_T p_menu_cb_actn_e)
{
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  LSH_STATE_ID_T         fl_logic_st_id_U8;
  MENU_CONTROL_T       const *fl_menu_cntrl_ptr;
  fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
  if(fl_menu_cntrl_ptr != FNULL)
  {
     fl_logic_st_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);
     if(p_menu_cb_actn_e ==MENU_CB_ACTION_WAIT)
     {
       (void)LSH_ADD_STATE_EXT(fl_logic_st_id_U8, HMI_MENU_ANIMATION_ABORT,p_menu_id_U8);
     }
     else
     {
       (void)LSH_ADD_STATE_EXT(fl_logic_st_id_U8, ANIM_MAX_ID,p_menu_id_U8);
     }
  }
#else
	/*QAC 8.1.2 Fix.*/
	p_menu_id_U8 = p_menu_id_U8;
	p_menu_cb_actn_e = p_menu_cb_actn_e;
#endif
}
/*============================================================================
** Function Name:    hmi_menu_logic_get_animation_ID
** Visibility:       global
** Description:      This function shall provide the required animation ID to
**                   be sent.
** Invocation:       Invoked by hmi_menu_core_chart/logic.c
** Inputs/Outputs:   p_menu_cb_action_e
** Critical Section: None.
** Created:          19-Jul-2010 by jpradeep
** Updated:          19-Jul-2010 by jpradeep
**==========================================================================*/
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
static UINT8 hmi_menu_logic_get_animation_ID(MENU_ANIM_DATA_T * fl_menu_anim_data_ptr, MENU_CB_RESULT_T p_menu_cb_action_e)
{
	UINT8 fl_ret_anim_ID_U8;

	fl_ret_anim_ID_U8 = ANIM_MAX_ID;
	switch (p_menu_cb_action_e)
	{
	case MENU_CB_ACTION_WAIT:
		fl_ret_anim_ID_U8 = HMI_MENU_PLEASE_WAIT_ANM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_FASTUP:
		fl_ret_anim_ID_U8 = HMI_MENU_FAST_SCROLL_UP_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_FASTDOWN:
		fl_ret_anim_ID_U8 = HMI_MENU_FAST_SCROLL_DOWN_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WIPER_LEFT_ANM:
	case MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_WIPER_LEFT_ANM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WIPER_RIGHT_ANM:
	case MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_WIPER_RIGHT_ANM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_DOUBLE_WIPER_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_DOUBLE_WIPER_ANM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_FOCUS_MOVE_UP_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_FOCUS_FRAME_MOVE_UP_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_FOCUS_MOVE_DOWN_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_FOCUS_FRAME_MOVE_DOWN_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WNDW_MOVE_UP_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_LIST_WNDW_MOVE_UP_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WNDW_MOVE_DOWN_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_LIST_WNDW_MOVE_DOWN_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WRAP_RND_UP_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_ITEM_WRAP_ROUND_UP_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_WRAP_RND_DOWN_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_ITEM_WRAP_ROUND_DOWN_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_SCALE_ADJ_LEFT_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_SCALE_ADJUST_LEFT_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_SCALE_ADJ_RIGHT_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_SCALE_ADJUST_RIGHT_ANIM(fl_menu_anim_data_ptr);
		break;
	case MENU_CB_ACTION_REBUILD_ANM:
		fl_ret_anim_ID_U8 = HMI_MENU_REBUILD_ANIM(fl_menu_anim_data_ptr);
   	    break;
	default:
		 /* To fix MISRA Warning C-2012 Rule 16.4 */
		break;
	}

	return(fl_ret_anim_ID_U8);
}
#endif

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/*============================================================================
** Function Name:    hmi_menu_logic_get_crnt_menu_level
** Visibility:       global
** Description:      This function shall be used to load the menu level element
**                   in the Menu control structure.
** Invocation:       Invoked by logic.c
** Inputs/Outputs:   p_menu_cntrl_ptr
** Critical Section: None.
** Created:          22-Jul-2010 by jpradeep
** Updated:          22-Jul-2010 by jpradeep
**==========================================================================*/
UINT8 hmi_menu_logic_get_crnt_menu_level(void)
{
  MENU_CONTROL_T const *p_menu_cntrl_ptr;
  p_menu_cntrl_ptr =  hmi_menu_logic_Get_Focus_MenuInstance();
  return(p_menu_cntrl_ptr->menu_level_U8);
}
/*============================================================================
** Function Name:    hmi_menu_logic_CB_result_action
** Visibility:       global
** Description:      This function shall be used to handle the CB result action
** Invocation:       Invoked by logic.c
** Inputs/Outputs:   p_menu_cntrl_ptr
** Critical Section: None.
** Created:          22-Jul-2010 by jpradeep
** Updated:          21-Feb-2013 by csakthiv
**==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static MENU_CB_RESULT_T hmi_menu_logic_CB_result_anim(MENU_ANIM_DATA_T  *fl_menu_anim_data, MENU_CB_RESULT_T p_CB_result_e)
{
	MENU_CB_RESULT_T fl_ret_CB_value_e;
	MENU_LIST_ID_T fl_menu_id_U8;
	UINT8 fl_anim_id_U8;
	UINT8 fl_cb_anim_id_U8;
	UINT8 fl_menu_screen_action_U8;
	MENU_CONTROL_T const *fl_focus_menu_cntrl_SP;
#ifndef HMI_MENU_DISABLE_ANIM_ST_CHECK
	BOOLEAN fl_menu_anim_st_Bool;
#endif
	LSH_STATE_ID_T fl_menu_screen_id_U8;
	UINT8 fl_menu_inst_idx_U8;


	fl_ret_CB_value_e = MENU_CB_ACTION_COMPLETED;

	fl_menu_screen_action_U8 = fl_menu_anim_data->menu_anim_screen_action_U8;
	fl_focus_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(fl_menu_anim_data->menu_anim_curr_menu_id_E);
	fl_menu_inst_idx_U8 = hmi_menu_logic_get_menu_inst_no(fl_menu_anim_data->menu_anim_curr_menu_id_E);

	if((fl_focus_menu_cntrl_SP != NULL)&&(fl_menu_inst_idx_U8 < NB_OF_MENU_INSTANCE))
	{
		/* no need to check the validity of  fl_menu_inst_idx_U8 as it is generated from tool */
		/* check menu id  present in any instance */
#ifndef HMI_MENU_DISABLE_ANIM_ST_CHECK
		fl_menu_anim_st_Bool = ( hmi_menu_chart_is_anim_st(&l_menu_core_chart_inst_array[fl_menu_inst_idx_U8]) ? TRUE : FALSE);
#endif
		if((fl_menu_screen_action_U8 == HMI_MENU_SCREEN_ADD)||(fl_menu_screen_action_U8 == HMI_MENU_SCREEN_REMOVE))
		{
			if(fl_menu_screen_action_U8 == HMI_MENU_SCREEN_ADD)
			{
				fl_menu_screen_id_U8 = fl_menu_anim_data->menu_anim_curr_screen_id_U8;
				fl_menu_id_U8        = fl_menu_anim_data->menu_anim_curr_menu_id_E;
			}
			else
			{
				fl_menu_screen_id_U8 = fl_menu_anim_data->menu_anim_prev_screen_id_U8;
				fl_menu_id_U8        = fl_menu_anim_data->menu_anim_prev_menu_id_E;
			}

			fl_anim_id_U8 = hmi_menu_logic_get_animation_ID(fl_menu_anim_data, p_CB_result_e);

			if(TESTBIT(p_CB_result_e, HMI_MENU_EXIT_WITH_ANIM_MASK))
			{
				/* Request action is for MenuClose */
				/*Extract animation id from MENU_CB_RESULT_T*/
				/*As per the current implementation, animation id will be within the range of 0 to 255.
				Hence typecasting UINT16 to UINT8 will not be an issue*/
				fl_cb_anim_id_U8 = (UINT8)(p_CB_result_e & HMI_MENU_CB_CLOSE_ANIM_MASK);
				hmi_menu_logic_Menu_Close(fl_menu_id_U8, fl_cb_anim_id_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_COMPLETED;
			}
			else if(p_CB_result_e == MENU_CB_ACTION_COMPLETED)
			{
			  /* 
              ** RTC: 914805: (when previous and current screen id's are same) or
			  **              (when previous and current client(menu) id's are same)
			  **              it is not required to post the screen update with "ANIM_MAX_ID"
			  **              to the LSH,  since in both the cases their respective presentation
			  ** 			  handler will be same hence for screen update, VM will anyhow
			  **              called to its corresponding presentations.
			  */
			  if((fl_menu_anim_data->menu_anim_prev_menu_id_E != fl_menu_anim_data->menu_anim_curr_menu_id_E) || 
			     (fl_menu_anim_data->menu_anim_prev_screen_id_U8 != fl_menu_anim_data->menu_anim_curr_screen_id_U8))
			  {
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, fl_menu_screen_action_U8);
			  }
			  fl_ret_CB_value_e = p_CB_result_e;
			}
#ifdef HMI_MENU_DISABLE_ANIM_ST_CHECK
			else if(fl_anim_id_U8 == (UINT8)(ANIM_MAX_ID)) 
#else
			else if((fl_anim_id_U8 == (UINT8)(ANIM_MAX_ID))&&(fl_menu_anim_st_Bool == FALSE))
#endif
			{
				/* if application configured ANIM_MAX_ID for some of the anims then Menu core move
				   to completed state instead of ANIM state*/
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_COMPLETED;
			}
			else if(p_CB_result_e == MENU_CB_ACTION_WAIT)
			{
				/* if it is wait animation, and menu core is already in animaiton(wiper anim or focus down anim), then menu core should
				 * move to wait anim state. otherwise , data available will not be received and blank animation screen displayed.
				 * wait is high priority so kept above anim_st check . dont change it. while in animation state,if wait comes
				 * then menu core should move to wait state
				 * No animation in please wait ON left, right, up , down, please wait will be triggered by chart*/
				/*Below line commented to fix the issue with please wait animation
				RTC ID for this issue: 338230: C346 MCA MFd :Please wait shown in channel guide until menu timeout*/
				/*hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, fl_menu_screen_action_U8);*/
				fl_ret_CB_value_e = p_CB_result_e;
			}
			else if((p_CB_result_e == MENU_CB_ACTION_FASTUP)||
				(p_CB_result_e == MENU_CB_ACTION_FASTDOWN))
			{
				/* if it is fast up/down, then it should enter into scroll st in menu core model. so checked before
				   before checking for anim state. */
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, fl_anim_id_U8
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = p_CB_result_e;
			}
#ifndef HMI_MENU_DISABLE_ANIM_ST_CHECK
			else if(fl_menu_anim_st_Bool != FALSE)
			{
#ifdef HMI_MENU_SMOOTH_FAST_ANIMATION
				/* Store the latest screen_id in the queue if the expected action is ADD.
				If it is REMOVE action, we no need to perform anything*/
				if(fl_menu_screen_action_U8 == HMI_MENU_SCREEN_ADD)
				{
					l_screen_id_in_queue = fl_menu_screen_id_U8;
				}
	    	    fl_ret_CB_value_e = MENU_CB_ACTION_ANIMATION;
#else
				/* When left/right button pressed during anim state then need to 
				stay in wait state hence MENU_CB_ACTION_WAIT is returned. 
				If not in wait state then data available request will not be processed*/

			    if((p_CB_result_e == MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_DOUBLE_WIPER_WAIT_ANM))
				{
				  fl_ret_CB_value_e = MENU_CB_ACTION_WAIT;
				}
				else
				{

			    	/* if menu core is already in anim state, then it should be maintained in the same state.
			    	 * ANIM_MAX_ID will be animation id e.g., Right wiper animation and then immediate down press*/
                    /* 
                    ** RTC: 914805: (when previous and current screen id's are same) or
					**              (when previous and current client(menu) id's are same)
					**              it is not required to post the screen update with "ANIM_MAX_ID"
					**              to the LSH,  since in both the cases their respective presentation
					** 				handler will be same hence for screen update, VM will anyhow
					**              called to its corresponding presentations.
					*/   
			        if((fl_menu_anim_data->menu_anim_prev_menu_id_E != fl_menu_anim_data->menu_anim_curr_menu_id_E) || 
			           (fl_menu_anim_data->menu_anim_prev_screen_id_U8 != fl_menu_anim_data->menu_anim_curr_screen_id_U8))
			        {
			     	   hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
                                           #ifdef LSH_ANIMATION_SUPPORT_ENABLED
			    		                           , ANIM_MAX_ID
                                           #endif
			    		                          , fl_menu_screen_action_U8);
				    }
					fl_ret_CB_value_e = MENU_CB_ACTION_ANIMATION;

				}
#endif
 
			}
#endif
			else if((p_CB_result_e == MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_DOUBLE_WIPER_WAIT_ANM))
			{
				if((hmi_menu_const_struct_array_table[fl_menu_id_U8].properties & MENU_PRO_DYNAMIC) != 0U)
				{
					/* Start the wait temp timer */
					hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,fl_menu_id_U8);
				}
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, fl_anim_id_U8
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_WAIT;
			}
			else if((p_CB_result_e == MENU_CB_ACTION_FOCUS_MOVE_UP_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_FOCUS_MOVE_DOWN_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WNDW_MOVE_UP_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WNDW_MOVE_DOWN_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WIPER_LEFT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WIPER_RIGHT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_DOUBLE_WIPER_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_REBUILD_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_SCALE_ADJ_LEFT_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_SCALE_ADJ_RIGHT_ANM))
			{
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, fl_anim_id_U8
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_ANIMATION;
			}
			else if((p_CB_result_e == MENU_CB_ACTION_WRAP_RND_UP_ANM)||
				(p_CB_result_e == MENU_CB_ACTION_WRAP_RND_DOWN_ANM))
			{
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, fl_anim_id_U8
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_COMPLETED;
			}
			else
			{
				hmi_menu_logic_View_Mngr_Rq(fl_menu_id_U8, fl_menu_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, fl_menu_screen_action_U8);
				fl_ret_CB_value_e = MENU_CB_ACTION_COMPLETED;
			}
		}
	}
	return(fl_ret_CB_value_e);
}
#endif

/*============================================================================
** Function Name:    hmi_menu_logic_load_absl_index
** Visibility:       global
** Description:      This function shall load the ansolute index value of the
**                   menu items.
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr
** Outputs:          None.
** Critical Section: None.
** Created:          25-Aug-2010 by jpradeep
** Updated:          25-Aug-2010 by jpradeep
**==========================================================================*/
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
static void hmi_menu_logic_load_absl_index(MENU_CONTROL_T* p_menu_cntrl_ptr)
{
  /*Any change in this function will also affect Menu_Reload interface*/
  UINT8 fl_get_ret_val_U8;
  UINT16 fl_get_item_pro_U16;
  UINT16 fl_new_index_U16;
  UINT16 fl_old_index_U16;
#ifdef HMI_MENU_FLOATING_MENU_FEATURE
  UINT8 fl_floating_menu_focus_entry_U8;
#endif
  BOOLEAN fl_itm_enable_cb_st_BOOL;
  MENU_DEF_T const* fl_menu_def_SP;

  fl_itm_enable_cb_st_BOOL = FALSE;
  if ((p_menu_cntrl_ptr != FNULL) && (p_menu_cntrl_ptr->menu_id < TOTAL_MENU_ID))
  {
    fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
    /* check the presence of menu item enable cb function */
    if (fl_menu_def_SP->is_menu_item_enable_cb != FNULL)
    {
      fl_itm_enable_cb_st_BOOL = TRUE;
    }
    hmi_menu_logic_intialize_load_absl_index(p_menu_cntrl_ptr);

    for (fl_old_index_U16 = 0; fl_old_index_U16 < p_menu_cntrl_ptr->menu_entry_nbr; fl_old_index_U16++)
    {
      /* check for the configuration function */
      if (FALSE != fl_itm_enable_cb_st_BOOL)
      {
        fl_get_item_pro_U16 = fl_menu_def_SP->entry_array.static_array[fl_old_index_U16].item_properties;
        fl_new_index_U16 = hmi_menu_logic_get_next_free_absl_index(p_menu_cntrl_ptr);
        if ((fl_get_item_pro_U16 & MENU_ITEM_PRO_CONFIGURABLE) != 0U)
        {
#ifdef HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE
          fl_get_ret_val_U8 = fl_menu_def_SP->is_menu_item_enable_cb(fl_old_index_U16, p_menu_cntrl_ptr->menu_id);
#else
          fl_get_ret_val_U8 = fl_menu_def_SP->is_menu_item_enable_cb(fl_old_index_U16);
#endif
          if (fl_new_index_U16 < HMI_MAX_MENU_ITEMS)
          {
            if ((MENU_ITEM_CONFIG_ACTIVE == fl_get_ret_val_U8) || (MENU_ITEM_CONFIG_GRAY_OUT == fl_get_ret_val_U8))
            {

              p_menu_cntrl_ptr->menu_itm_absl_indx[fl_new_index_U16] = fl_old_index_U16;
              if (MENU_ITEM_CONFIG_GRAY_OUT == fl_get_ret_val_U8)
              {
                SETBIT(p_menu_cntrl_ptr->menu_itm_absl_indx[fl_new_index_U16], (UINT16)BIT7);
              }
            }
#ifdef HMI_MENU_FLOATING_MENU_FEATURE
            else if (MENU_ITEM_CONFIG_FLOATING == fl_get_ret_val_U8)
            {
              fl_floating_menu_focus_entry_U8 = HMI_MENU_LOGIC_GET_FLOATING_MENU_FOCUS_ENTRY(p_menu_cntrl_ptr->menu_id, fl_old_index_U16);
              p_menu_cntrl_ptr->menu_itm_absl_indx[fl_floating_menu_focus_entry_U8] = fl_old_index_U16;
            }
#endif
            else if (MENU_ITEM_CONFIG_INACTIVE == fl_get_ret_val_U8)
            {

              p_menu_cntrl_ptr->menu_itm_absl_indx[fl_new_index_U16] = 0xFE; /*index inactive replace it with active index*/
            }
            else
            {
              /* do nothing */
            }
          }
        }
        else
        {
          /* Load item as default */
          p_menu_cntrl_ptr->menu_itm_absl_indx[fl_new_index_U16] = fl_old_index_U16;
        }
      }
      else
      {
        /* Load all items as default */
        p_menu_cntrl_ptr->menu_itm_absl_indx[fl_old_index_U16] = fl_old_index_U16;
      }
    }
    p_menu_cntrl_ptr->menu_entry_nbr = hmi_menu_logic_arrange_absl_index(p_menu_cntrl_ptr);
    if (p_menu_cntrl_ptr->menu_entry_nbr == 0U)
    {
      UINT8 menu_index;
      /* if none of the item is active, initalize item absl to 0 focus entry so that always first item's
      screen will be displayed instead of accesssing invalid focus entry location. Previsouly in get_screen_id
      it was accessing FE or FF focus entry's screen id */
      for (menu_index = 0; menu_index < HMI_MAX_MENU_ITEMS; menu_index++)
      {
        p_menu_cntrl_ptr->menu_itm_absl_indx[menu_index] = 0;
      }
    }
  }
}

/*============================================================================
** Function Name:    hmi_menu_logic_intialize_load_absl_index_array
** Visibility:       global
** Description:      This function intialize load absolute index array to 0xFF
**                   reference.
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           p_menu_cntrl_ptr
** Outputs:
** Critical Section: None.
** Created:          23-Jan-2013 csakthiv
** Updated:
**==========================================================================*/
static void hmi_menu_logic_intialize_load_absl_index(MENU_CONTROL_T * p_menu_cntrl_ptr)
{
	UINT16 fl_menu_entry;
	for (fl_menu_entry = 0; fl_menu_entry < p_menu_cntrl_ptr->menu_entry_nbr; fl_menu_entry++)
	{
		p_menu_cntrl_ptr->menu_itm_absl_indx[fl_menu_entry] = 0xFF;
	}
}
/*============================================================================
** Function Name:    hmi_menu_logic_get_next_free_absl_index
** Visibility:       global
** Description:      This function gives next available free index
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr, fl_current_index_U8
** Outputs:          next free index
** Critical Section: None.
** Created:          23-Jan-2013 csakthiv
** Updated:
**==========================================================================*/
static UINT16 hmi_menu_logic_get_next_free_absl_index(MENU_CONTROL_T const *p_menu_cntrl_ptr)
{
	UINT16 fl_current_index_U16;

	for (fl_current_index_U16 = 0; fl_current_index_U16 < p_menu_cntrl_ptr->menu_entry_nbr; fl_current_index_U16++)
	{
		if (p_menu_cntrl_ptr->menu_itm_absl_indx[fl_current_index_U16] == 0xFFU)
		{
			break;
		}
	}
	return fl_current_index_U16;
}
/*============================================================================
** Function Name:    hmi_menu_logic_arrange_absl_index
** Visibility:       global
** Description:      This function arranges absl index i.e., removing invalid/blank index
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr, fl_current_index_U8
** Outputs:          next free index
** Critical Section: None.
** Created:          23-Jan-2013 csakthiv
** Updated:
**==========================================================================*/
static UINT16 hmi_menu_logic_arrange_absl_index(MENU_CONTROL_T * p_menu_cntrl_ptr)
{
	UINT16 fl_old_index_U16;
	UINT16 fl_new_index_U16;
	fl_new_index_U16 = 0;

	for (fl_old_index_U16 = 0; fl_old_index_U16 < p_menu_cntrl_ptr->menu_entry_nbr; fl_old_index_U16++)
	{
		/* both free and inactive are considered as free index locations*/
		if ((p_menu_cntrl_ptr->menu_itm_absl_indx[fl_old_index_U16] != 0xFFU) &&
			(p_menu_cntrl_ptr->menu_itm_absl_indx[fl_old_index_U16] != 0xFEU))
		{
			if (fl_new_index_U16 < HMI_MAX_MENU_ITEMS)
			{
				p_menu_cntrl_ptr->menu_itm_absl_indx[fl_new_index_U16] = p_menu_cntrl_ptr->menu_itm_absl_indx[fl_old_index_U16];
				fl_new_index_U16++;
			}
		}
	}
	/* returns total number of entries in the menu */
	return fl_new_index_U16;
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_absl_index_focus_entry
** Visibility:       global
** Description:      This function returns the absolute index of focus entry
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr
** Outputs:          None
** Critical Section: None.
** Created:          23-Sep-2015 aperumal
** Updated:
**==========================================================================*/
UINT16 hmi_menu_logic_get_absl_index_focus_entry(MENU_CONTROL_T const *p_menu_cntrl_ptr)
{
	UINT16 fl_focus_entry_U16 = 0;
	if ((p_menu_cntrl_ptr->menu_properties & MENU_PRO_DYNAMIC) != 0U)
	{
		if (p_menu_cntrl_ptr->focus_entry_U16 < HMI_MAX_MENU_ITEMS)
		{
			fl_focus_entry_U16 = p_menu_cntrl_ptr->menu_itm_absl_indx[p_menu_cntrl_ptr->focus_entry_U16];
		}
		else
		{
			fl_focus_entry_U16 = p_menu_cntrl_ptr->focus_entry_U16;
		}
	}
	else
	{
		if (p_menu_cntrl_ptr->focus_entry_U16 < HMI_MAX_MENU_ITEMS)
		{
			fl_focus_entry_U16 = p_menu_cntrl_ptr->menu_itm_absl_indx[p_menu_cntrl_ptr->focus_entry_U16];
		}
	}
	return fl_focus_entry_U16;
}
#endif
/*============================================================================
** Function Name:    hmi_menu_logic_Get_item_entry_array
** Visibility:       global
** Description:      This function shall give the menu item entry array
**                   reference.
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr, p_focus_entry_U16
** Outputs:          MENU_ITEM_ENTRY_T
** Critical Section: None.
** Created:          25-Aug-2010 by jpradeep
** Updated:          25-Aug-2010 by jpradeep
**==========================================================================*/
MENU_ITEM_ENTRY_T const *hmi_menu_logic_Get_item_entry_array(MENU_CONTROL_T const *p_menu_cntrl_ptr, UINT16 p_focus_entry_U16)
{
  UINT16 fl_get_absl_index_U16 = 0U;
  UINT16 fl_total_entry_nbr_U16;
  MENU_ITEM_ENTRY_T  const  *fl_menu_item_entry_sp;

  fl_menu_item_entry_sp = FNULL;
  if((p_menu_cntrl_ptr != FNULL) && (p_menu_cntrl_ptr->menu_id<TOTAL_MENU_ID))
  {

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	if(p_focus_entry_U16 < HMI_MAX_MENU_ITEMS)
	{
		fl_get_absl_index_U16  = (UINT16)p_menu_cntrl_ptr->menu_itm_absl_indx[p_focus_entry_U16];

	   	/* clear Gray out item bit */
	   	fl_get_absl_index_U16 = fl_get_absl_index_U16 & (~((UINT16)(BIT7)));
	}

#else
   	fl_get_absl_index_U16  = p_focus_entry_U16;
#endif
    /* so if it is dynamic with focus entry greater than entry_nbr then , null will be returned */
	fl_total_entry_nbr_U16 = hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].total_entry_nbr;
	if ((p_menu_cntrl_ptr->focus_entry_U16 < fl_total_entry_nbr_U16) && (fl_get_absl_index_U16 < fl_total_entry_nbr_U16))
	{
		fl_menu_item_entry_sp = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].entry_array.static_array[fl_get_absl_index_U16];
	}

	else
	{
		/* if dynamic menu, send the item entry pointer of zeroth entry, as focus entry is greater than menu entry nbr*/
		fl_get_absl_index_U16 = (UINT16)0;
		if (fl_get_absl_index_U16 < fl_total_entry_nbr_U16)
		{
				fl_menu_item_entry_sp = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].entry_array.static_array[fl_get_absl_index_U16];
		}
	}
  }
  return(fl_menu_item_entry_sp);
}

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
/*============================================================================
** Function Name:    hmi_menu_logic_is_all_menu_items_configured
** Visibility:       global
** Description:      This function shall be used to check the status about
**                   the configuration of all items in the Menu.
**                   This function shall be used if all the Menu items are
**                   NVM configured.
**                   It doesn't suit for the case if any one of the item is
**                   displayed only when all its submenu items are configured.
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_LIST_ID_T
** Outputs:          TRUE/FALSE
** Critical Section: None.
** Created:          25-Aug-2010 by jpradeep
** Updated:          24-Jul-2013 by csakthiv
**==========================================================================*/
UINT8 hmi_menu_logic_is_any_menu_item_configured(MENU_LIST_ID_T p_menu_ID_e)
{
  UINT16 fl_menu_entry;
  UINT8 fl_ret_st_U8;
  MENU_DEF_T  const    *fl_menu_def_SP;

  /* if cb is null then return value will be active*/
  fl_ret_st_U8 = MENU_ITEM_CONFIG_ACTIVE;
  if(p_menu_ID_e < TOTAL_MENU_ID)
  {
	  fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_ID_e];

	  if(fl_menu_def_SP->is_menu_item_enable_cb != FNULL)
	  {
		for (fl_menu_entry = 0; fl_menu_entry<fl_menu_def_SP->total_entry_nbr; fl_menu_entry++)
		{
		  #ifdef HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE
		  fl_ret_st_U8 = fl_menu_def_SP->is_menu_item_enable_cb(fl_menu_entry,p_menu_ID_e);
		  #else
		  fl_ret_st_U8 = fl_menu_def_SP->is_menu_item_enable_cb(fl_menu_entry);
		  #endif
		  if(MENU_ITEM_CONFIG_INACTIVE != fl_ret_st_U8)
		  {
			break;
		  }
		}
	  }
  }
  return(fl_ret_st_U8);
}
/****************************************************************************
Function Name     : hmi_menu_app_get_focus_entry_val
Description       : It gives the current focus_entry_value
Invocation        : hmi_menu_logic_interface.c
Parameters        : MENU_CONTROL_T *, UINT16
Return Value      : UINT16
Critical Section  : None
******************************************************************************/
UINT16 hmi_menu_logic_get_focus_entry(MENU_CONTROL_T const *p_hmi_app_ptr, UINT16 p_itm_absl_indx_U16)
{
	UINT16 fl_menu_entry;
	UINT16 fl_ret_focus_entry_val_U16;
	UINT16 fl_absl_focus_entry_U16;
	UINT16 fl_itm_absl_indx_U16 = p_itm_absl_indx_U16;

	fl_ret_focus_entry_val_U16 = 0;
	/* clear Gray out item bit */
	fl_itm_absl_indx_U16 = fl_itm_absl_indx_U16 & (~((UINT16)(BIT7)));

	for (fl_menu_entry = 0; fl_menu_entry < p_hmi_app_ptr->menu_entry_nbr; fl_menu_entry++)
	{
		fl_absl_focus_entry_U16 = p_hmi_app_ptr->menu_itm_absl_indx[fl_menu_entry];
		/* clear Gray out item bit */
		fl_absl_focus_entry_U16 = fl_absl_focus_entry_U16 & (~((UINT16)(BIT7)));
		if (fl_absl_focus_entry_U16 == fl_itm_absl_indx_U16)
		{
			fl_ret_focus_entry_val_U16 = fl_menu_entry;
			break;
		}
	}
	return(fl_ret_focus_entry_val_U16);
}
/****************************************************************************
Function Name     : hmi_menu_app_is_stored_item_enabled
Description       : This function shall provide the stored menu item status
                    after checking the loaded items from absl index.
Invocation        : By hmi_menu_app_get_stored_menu_item
Parameters        : p_menu_cntrl_ptr, p_stored_item_U8
Return Value      : BOOLEAN
Critical Section  : None
******************************************************************************/
BOOLEAN hmi_menu_logic_is_stored_item_enabled(MENU_LIST_ID_T p_menu_ID_e, UINT8 p_stored_item_U8)
{
  UINT16 fl_menu_entry;
  UINT16 fl_get_absl_indx_val_U16;
  BOOLEAN fl_item_config_BOOL;
  MENU_CONTROL_T const *fl_menu_inst_ptr;
  UINT8 fl_stored_item_U8 = p_stored_item_U8;

  fl_item_config_BOOL = FALSE;
  fl_menu_inst_ptr = hmi_menu_logic_get_menu_instance(p_menu_ID_e);

  fl_stored_item_U8 = fl_stored_item_U8 & (~((UINT8)(BIT7))); /*clear gray out bit*/

  if(fl_menu_inst_ptr != FNULL)
  {
    for(fl_menu_entry=0; fl_menu_entry<fl_menu_inst_ptr->menu_entry_nbr; fl_menu_entry++)
    {
      fl_get_absl_indx_val_U16 = (UINT16)fl_menu_inst_ptr->menu_itm_absl_indx[fl_menu_entry];
      fl_get_absl_indx_val_U16 = fl_get_absl_indx_val_U16 & (~((UINT16)(BIT7))); /*clear gray out bit*/
      if (fl_get_absl_indx_val_U16 == fl_stored_item_U8)
      {
        fl_item_config_BOOL = TRUE;
        break;
      }
    }
  }
  return(fl_item_config_BOOL);
}
#endif /* End of HMI_MENU_ITEM_CONFIG_FEATURE */

/*============================================================================
** Function Name:    hmi_menu_logic_Menu_Update
** Visibility:       global   
** Description:      This function triggers the reloading of Menu without 
                     changing focus and finally triggers the presentation.
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          15-Oct-2013 by csakthiv
**==========================================================================*/
void hmi_menu_logic_Menu_Update(MENU_LIST_ID_T p_menu_id_U8)
{
	MENU_CONTROL_T        *fl_menu_def_inst_ptr;
	UINT8                  fl_get_menu_inst_U8;
	UINT16                 fl_store_menu_entry_nbr_U16;
	MENU_CB_RESULT_T       fl_cb_result_e;
	MENU_ANIM_DATA_T       fl_menu_anim_data;
	#if(HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID) || (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_DECR_TILL_VALID)
	UINT16                 fl_item_absl_focus_entry_U16;
	#endif
	fl_cb_result_e        = MENU_CB_ACTION_COMPLETED;
	fl_menu_def_inst_ptr  = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
	fl_get_menu_inst_U8   = hmi_menu_logic_get_menu_inst_no(p_menu_id_U8);
	if((fl_menu_def_inst_ptr != NULL) && (fl_get_menu_inst_U8 < NB_OF_MENU_INSTANCE) && (fl_menu_def_inst_ptr->menu_id < TOTAL_MENU_ID))
	{	
		MENU_DEF_T const *fl_menu_def_SP;
		fl_menu_anim_data.menu_anim_prev_focus_line_U16  = fl_menu_def_inst_ptr->focus_line_U16;
		fl_menu_anim_data.menu_anim_prev_menu_id_E       = fl_menu_def_inst_ptr->menu_id;
		fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_def_inst_ptr->focus_entry_U16;
		fl_menu_anim_data.menu_anim_prev_screen_id_U8    = hmi_menu_logic_get_screen_id(fl_menu_def_inst_ptr);
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_menu_def_inst_ptr->menu_id];
		if (hmi_menu_const_struct_array_table[fl_menu_def_inst_ptr->menu_id].cb != NULL)
		{
			fl_store_menu_entry_nbr_U16 = fl_menu_def_inst_ptr->menu_entry_nbr;
		#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
			/* check the presence of menu item enable cb function */
			if (fl_menu_def_SP->is_menu_item_enable_cb != FNULL)
			{
				fl_menu_def_inst_ptr->menu_entry_nbr = hmi_menu_const_struct_array_table[fl_menu_def_inst_ptr->menu_id].total_entry_nbr;
				hmi_menu_logic_load_absl_index(fl_menu_def_inst_ptr);
			}
		#else
				/*if HMI_MENU_ITEM_CONFIG_FEATURE is not enabled,then application will do config feature check and update the entry nbr in
				MENU_ACTION_REBUILD callback*/
				fl_cb_result_e = hmi_menu_const_struct_array_table[fl_menu_def_inst_ptr->menu_id].cb(MENU_ACTION_REBUILD, fl_menu_def_inst_ptr, MENU_BTN_INVALID);
		#endif
			if (fl_store_menu_entry_nbr_U16 != fl_menu_def_inst_ptr->menu_entry_nbr)
			{
				fl_menu_def_inst_ptr->focus_entry_U16 = 0;
				fl_menu_def_inst_ptr->focus_line_U16 = 0;
				fl_menu_def_inst_ptr->selected_entry_U16 = MENU_INVALID_ENTRY;
			}
		#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
			/* for dynamic menu application will update selection marker in MENU_ACTION_REBUILD callback */
			fl_cb_result_e = hmi_menu_const_struct_array_table[fl_menu_def_inst_ptr->menu_id].cb(MENU_ACTION_REBUILD, fl_menu_def_inst_ptr, MENU_BTN_INVALID);
		#endif
		}
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
		if (fl_cb_result_e != MENU_CB_ACTION_WAIT)
		{
	  	  fl_cb_result_e = MENU_CB_ACTION_REBUILD_ANM;
		}
		else
		{
	      /* menu chart will enter into wait state*/
		}
#endif

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
		/*Here we are checking the 'is_menu_item_enable_cb != null' validation to ensure that absolute
		index is updated for dynamic menu.*/
		/*if static || (dynamic && is_menu_item_enable_cb != null && focus_entry < HMI_MAX_MENU_ITEMS) */
		if (((fl_menu_def_inst_ptr->menu_properties & MENU_PRO_DYNAMIC) == 0U) ||
			((fl_menu_def_SP->is_menu_item_enable_cb != FNULL) && (fl_menu_def_inst_ptr->focus_entry_U16 < HMI_MAX_MENU_ITEMS)))
		{
		#if (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID)
			fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_def_inst_ptr);
			if (TESTBIT(fl_item_absl_focus_entry_U16, BIT7))
			{
				/* on update if the current focus entry is greyout, then increment fe till valid fe */
				hmi_menu_logic_down_focus_entry(fl_menu_def_inst_ptr);
			}
		#elif (HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT == HMI_MENU_FOCUS_ENTRY_DECR_TILL_VALID)
			fl_item_absl_focus_entry_U16 = fl_menu_def_inst_ptr->menu_itm_absl_indx[fl_menu_def_inst_ptr->focus_entry_U16];
			if (TESTBIT(fl_item_absl_focus_entry_U16, BIT7))
			{
				/* on update if the current focus entry is greyout, then decrement fe till valid fe */
				hmi_menu_logic_up_focus_entry(fl_menu_def_inst_ptr);
			}
		#else
			/* do nothing.keep the focus entry in the greyed out item itself */
		#endif
		}
#endif
/*when rebuild happens need to expand if needed*/
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
		MENU_DO_FRAME_EXPAND_ANIMATION;
#endif
#endif

		fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_def_inst_ptr->focus_line_U16;
		fl_menu_anim_data.menu_anim_curr_menu_id_E = fl_menu_def_inst_ptr->menu_id;
		fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_def_inst_ptr->focus_entry_U16;
		fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_def_inst_ptr);

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
		if (fl_menu_def_inst_ptr->displayed_lines == NO_DISP_LINES_1)
		{
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
			(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
		}
		else
		{
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
		}
#else
		fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
		fl_cb_result_e = hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#endif
#else
		hmi_menu_logic_View_Mngr_Rq(fl_menu_def_inst_ptr->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
			#ifdef LSH_ANIMATION_SUPPORT_ENABLED
									,ANIM_MAX_ID
			#endif
									,HMI_MENU_SCREEN_ADD);
#endif
		/*Update the callback result to menu core chart like animation,please wait or completed*/
		hmi_menu_chart_menu_rebuild(&l_menu_core_chart_inst_array[fl_get_menu_inst_U8], fl_cb_result_e);
	}
}
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
/****************************************************************************
Function Name     : hmi_menu_logic_Menu_reload
Description       : This function is used to load the Menu freshly whenever
                    Menu item is deconfigured or conditions becomes invalid
                    inorder to show the display either Gray out or completely
                    removal.This function is called priodically from application.
Invocation        : By hmi application file
Parameters        : fl_menu_id_U8
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_Menu_Reload(MENU_LIST_ID_T fl_menu_id_U8)
{
  MENU_DEF_T  const* fl_current_menu_ref_ptr;
  MENU_DEF_T  const* fl_parent_menu_def_ptr;
  MENU_DEF_T  const* fl_submenu_menu_def_ptr;
  MENU_DEF_T  const* fl_menu_def_SP;
  MENU_CONTROL_T* fl_menu_cntrl_ptr;
  MENU_CONTROL_T       fl_menu_cntrl_copy;
  MENU_CB_RESULT_T     fl_cb_result_e;
  MENU_LIST_ID_T       fl_get_menu_ID_index_e;
  MENU_ANIM_DATA_T     fl_menu_anim_data;
  BOOLEAN              fl_disp_reload_BOOL;
  BOOLEAN              fl_consider_prnt_menu_ptr_BOOL;
  UINT8                fl_menu_level_cnt_U8;
  UINT8                fl_dst_menu_level_cnt_U8;
  UINT8                fl_menu_inst_no_U8;
  UINT8                fl_get_itm_status_U8;
  UINT16                fl_get_item_indx_U16;
  UINT8                fl_level_cnt_difference_U8;
  UINT16               fl_menu_level;
#if (HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT == HMI_MENU_FOCUS_ENTRY_TO_ZER0)
  UINT16               fl_item_absl_focus_entry_U16;
#endif
#ifdef HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE
  MENU_LIST_ID_T       fl_item_cb_menu_id_e;
#endif
  fl_disp_reload_BOOL = FALSE;
  fl_consider_prnt_menu_ptr_BOOL = FALSE;
  fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(fl_menu_id_U8);
  fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
  fl_get_itm_status_U8 = MENU_ITEM_CONFIG_ACTIVE;

  if ((fl_menu_cntrl_ptr != NULL) && (fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE))
  {
    if (fl_menu_cntrl_ptr->menu_id < TOTAL_MENU_ID)
    {
      fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id];
      fl_current_menu_ref_ptr = &hmi_menu_const_struct_array_table[fl_menu_cntrl_ptr->menu_id];
      fl_submenu_menu_def_ptr = fl_current_menu_ref_ptr;
      fl_parent_menu_def_ptr = fl_submenu_menu_def_ptr;
      /* Find the Menu level */
      fl_menu_level_cnt_U8 = hmi_menu_logic_get_Menu_level(fl_menu_cntrl_ptr->menu_id);
      if (fl_menu_level_cnt_U8 != 0U)
      {
        while (fl_disp_reload_BOOL == FALSE)
        {
          /* Initialize w.r.t current Menu before starting */
          fl_submenu_menu_def_ptr = fl_current_menu_ref_ptr;
          fl_parent_menu_def_ptr = fl_submenu_menu_def_ptr;
          /* parent and submenu ptr are found */
          for (fl_menu_level = 0; fl_menu_level < fl_menu_level_cnt_U8; fl_menu_level++)
          {
            fl_submenu_menu_def_ptr = fl_parent_menu_def_ptr;
            fl_parent_menu_def_ptr = fl_submenu_menu_def_ptr->parent_menu;
          }
          /* check for the menu level count- if the item is not found on
          any of the level other that 0 then it should be a self Menu rebuild
          and hence the item entry array refernce is not needed */
          if (fl_menu_level_cnt_U8 != 0U)
          {
            /* Validate the repective item configuration */
            fl_get_item_indx_U16 = hmi_menu_logic_get_item_indx_frm_prnt_submenu(fl_parent_menu_def_ptr, fl_submenu_menu_def_ptr);
            if (fl_get_item_indx_U16 < fl_parent_menu_def_ptr->total_entry_nbr)
            {
              if ((fl_parent_menu_def_ptr->entry_array.static_array[fl_get_item_indx_U16].item_properties & MENU_ITEM_PRO_CONFIGURABLE) != 0U)
              {
                if (fl_parent_menu_def_ptr->is_menu_item_enable_cb != FNULL)
                {
#ifdef HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE
                  fl_item_cb_menu_id_e = hmi_menu_logic_get_menu_index(fl_parent_menu_def_ptr);
                  fl_get_itm_status_U8 = fl_parent_menu_def_ptr->is_menu_item_enable_cb(fl_get_item_indx_U16, fl_item_cb_menu_id_e);
#else
                  fl_get_itm_status_U8 = fl_parent_menu_def_ptr->is_menu_item_enable_cb(fl_get_item_indx_U16);
#endif
                }
                if (MENU_ITEM_CONFIG_ACTIVE != fl_get_itm_status_U8)
                {
                  fl_disp_reload_BOOL = TRUE;
                  fl_consider_prnt_menu_ptr_BOOL = TRUE;
                }
              }
            }
            fl_menu_level_cnt_U8--;
          }
          else
          {
            fl_disp_reload_BOOL = TRUE;
          }
        }
      }

      /* Menu structure loading and animation triggerring logic */
      /* count value is reloaded again since it is lost above */
      fl_menu_level_cnt_U8 = hmi_menu_logic_get_Menu_level(fl_menu_cntrl_ptr->menu_id);
      if (fl_consider_prnt_menu_ptr_BOOL != FALSE)
      {
        fl_get_menu_ID_index_e = hmi_menu_logic_get_menu_index(fl_parent_menu_def_ptr);
        fl_dst_menu_level_cnt_U8 = hmi_menu_logic_get_Menu_level(fl_get_menu_ID_index_e);
      }
      else
      {
        fl_dst_menu_level_cnt_U8 = hmi_menu_logic_get_Menu_level(fl_menu_cntrl_ptr->menu_id);
      }

      if (fl_menu_level_cnt_U8 != fl_dst_menu_level_cnt_U8)
      {
        /* Intimate the Focus Menu about the Reload via callback */
        if (fl_menu_def_SP->cb != NULL)
        {
          (void)fl_menu_def_SP->cb(MENU_ACTION_RELOAD, fl_menu_cntrl_ptr, MENU_BTN_INVALID);
        }
        fl_menu_anim_data.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
        fl_menu_anim_data.menu_anim_prev_menu_id_E = fl_menu_cntrl_ptr->menu_id;
        fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
        fl_menu_anim_data.menu_anim_prev_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);
        fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_parent_menu_def_ptr, fl_submenu_menu_def_ptr, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
        /* Reload the menu cntrl ptr to ensure that we are pointing the correct instance after
           closing the menu instance if opened. It is really needed only when there is a instance
           but for additional robustness it is newly fetched */
        hmi_menu_logic_update_current_focus_menu_ptr();
        fl_menu_cntrl_ptr = hmi_menu_logic_get_required_menu_instance(fl_menu_inst_no_U8);
#if (HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT == HMI_MENU_FOCUS_ENTRY_TO_ZER0)
        fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_cntrl_ptr);
        if (TESTBIT(fl_item_absl_focus_entry_U16, (UINT16)BIT7))
        {
          /* on reload and on opening parent menu, if the focus entry is greyed ,then move first entry*/
          fl_menu_cntrl_ptr->focus_entry_U16 = 0;
        }
#endif
        hmi_menu_logic_Focusline_Center(fl_menu_cntrl_ptr);

        fl_level_cnt_difference_U8 = fl_menu_level_cnt_U8 - fl_dst_menu_level_cnt_U8;
        hmi_lsh_freeze_button_events_ext(fl_menu_anim_data.menu_anim_prev_screen_id_U8, fl_menu_anim_data.menu_anim_prev_menu_id_E);

        if (fl_level_cnt_difference_U8 > HMI_MENU_LEVEL_1)
        {
          fl_cb_result_e = MENU_CB_ACTION_DOUBLE_WIPER_ANM;
        }
        else
        {
          if (fl_cb_result_e != MENU_CB_ACTION_WAIT)
          {
            fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_ANM;
          }
          else
          {
            fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM;
          }
        }
        fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
        fl_menu_anim_data.menu_anim_curr_menu_id_E = fl_menu_cntrl_ptr->menu_id;
        fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
        fl_menu_anim_data.menu_anim_curr_screen_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
        fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
        (void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
        fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
        (void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#else
        fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
        (void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
#endif
#else
        if (MENU_CB_ACTION_EXIT == fl_cb_result_e)
        {
          hmi_menu_logic_Menu_Close(fl_menu_cntrl_ptr->menu_id);
        }
        else
        {
          hmi_menu_logic_View_Mngr_Rq(fl_menu_cntrl_ptr->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
            , ANIM_MAX_ID
#endif
            , HMI_MENU_SCREEN_ADD);
        }
#endif
      }
      else
      {
        (void)memcpy((void*)&fl_menu_cntrl_copy, (void*)fl_menu_cntrl_ptr, sizeof(MENU_CONTROL_T));
        fl_menu_cntrl_copy.menu_entry_nbr = hmi_menu_const_struct_array_table[fl_menu_cntrl_copy.menu_id].total_entry_nbr;
        /* new menu_entry_nbr will be updated in fl_menu_cntrl_copy */
        hmi_menu_logic_load_absl_index(&fl_menu_cntrl_copy);

        if ((fl_menu_cntrl_copy.menu_entry_nbr == 0U) && ((fl_menu_cntrl_ptr->menu_properties & MENU_PRO_GOTO_PARENT_ON_ZERO_ENTRY) != 0U))
        {
          if (fl_menu_def_SP->cb != NULL)
          {
            (void)fl_menu_def_SP->cb(MENU_ACTION_RELOAD, &fl_menu_cntrl_copy, MENU_BTN_INVALID);
          }
          hmi_menu_logic_open_parent_menu(fl_menu_cntrl_copy.menu_id);
#if (HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT == HMI_MENU_FOCUS_ENTRY_TO_ZER0)
          fl_item_absl_focus_entry_U16 = hmi_menu_logic_get_absl_index_focus_entry(fl_menu_cntrl_ptr);
          if (TESTBIT(fl_item_absl_focus_entry_U16, (UINT16)BIT7))
          {
            /* on reload and on opening parent menu, if the focus entry is greyed ,then move first entry*/
            fl_menu_cntrl_ptr->focus_entry_U16 = 0;
          }
#endif
        }
        else if (fl_menu_cntrl_copy.menu_entry_nbr != fl_menu_cntrl_ptr->menu_entry_nbr)
        {
          hmi_menu_logic_Menu_Rebuild(fl_menu_cntrl_ptr->menu_id);
          fl_menu_cntrl_ptr->menu_properties |= MENU_PRO_DYNAMIC_UPDATE;
        }
        else
        {
          /*check individual index of menu are same*/
          for (fl_menu_level = 0; fl_menu_level < fl_menu_cntrl_ptr->menu_entry_nbr; fl_menu_level++)
          {
            if (fl_menu_cntrl_copy.menu_itm_absl_indx[fl_menu_level] != fl_menu_cntrl_ptr->menu_itm_absl_indx[fl_menu_level])
            {
              hmi_menu_logic_Menu_Rebuild(fl_menu_cntrl_ptr->menu_id);
              fl_menu_cntrl_ptr->menu_properties |= MENU_PRO_DYNAMIC_UPDATE;
              break;
            }
          }
        }
        /* if both entry_nbr and indivudual index are same then no rebuild not required*/
      }
    }
  }
}
#endif
/****************************************************************************
Function Name     : hmi_menu_logic_Menu_reload
Description       : This function is used to load the Menu freshly whenever
                    Menu item is deconfigured or conditions becomes invalid
                    inorder to show the display either Gray out or completely
                    removal
Invocation        : By hmi application file
Parameters        : p_menu_cntrl_ptr, p_stored_item_U8
Return Value      : None
Critical Section  : None
******************************************************************************/
static UINT16 hmi_menu_logic_get_item_indx_frm_prnt_submenu(const MENU_DEF_T *p_parent_menu_def_ptr, const MENU_DEF_T *p_submenu_menu_def_ptr)
{
	UINT16 fl_index;

	for (fl_index = 0; fl_index < p_parent_menu_def_ptr->total_entry_nbr; fl_index++)
	{
		if ((p_parent_menu_def_ptr->entry_array.static_array[fl_index].item_entry_type == MENU_ITEM_ENTRY_TYPE_MENU) ||
			(p_parent_menu_def_ptr->entry_array.static_array[fl_index].item_entry_type == MENU_ITEM_ENTRY_TYPE_EXE))
		{
			if (p_parent_menu_def_ptr->entry_array.static_array[fl_index].utype.sub_menu == p_submenu_menu_def_ptr)
			{
				break;
			}
		}
	}
	return(fl_index);
}

/****************************************************************************
Function Name     : hmi_menu_logic_get_Menu_level
Description       : This function is used to get the Requested Menu level value
Invocation        : By hmi application file
Parameters        : p_menu_ID_e
Return Value      : None
Critical Section  : None
******************************************************************************/
static UINT8 hmi_menu_logic_get_Menu_level(MENU_LIST_ID_T p_menu_ID_e)
{
  UINT8 fl_menu_level_val_U8;

  fl_menu_level_val_U8 = 0;
  if(p_menu_ID_e < TOTAL_MENU_ID)
  {
  	const MENU_DEF_T *fl_menu_def_ptr;
	fl_menu_def_ptr = &hmi_menu_const_struct_array_table[p_menu_ID_e];
    while(fl_menu_def_ptr->parent_menu != NULL)
    {
      fl_menu_def_ptr = fl_menu_def_ptr->parent_menu;
      fl_menu_level_val_U8++;
    }
  }
  return(fl_menu_level_val_U8);
}
/****************************************************************************
Function Name     : hmi_menu_logic_start_timer
Description       : Common Interface to start all the timers used in Menu Core
Invocation        : hmi_menu_core_01_chart.c
Parameters        : timer type and menu id.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_start_timer(UINT8 fl_timer_type_U8, MENU_LIST_ID_T fl_menu_id_U8)
{
	MENU_CONTROL_T   const *fl_menu_cntrl_SP;
	UINT8 fl_menu_inst_U8;
	UINT8 fl_timer_val_U8;
    fl_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
 	fl_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(fl_menu_id_U8);

	if((fl_menu_cntrl_SP != NULL)&&(fl_menu_inst_U8 < NB_OF_MENU_INSTANCE))
	{

    if (fl_timer_type_U8 == MENU_CORE_OPEN_TIMER)
    {
      fl_timer_val_U8 = hmi_menu_logic_get_menu_timeout_value(fl_menu_id_U8);
      if (fl_timer_val_U8 != 0U)
      {
        HMI_MENU_START_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id, fl_timer_val_U8);
      }
      else
      {
        /* if submenu's timeout is zero, then it will be stopped below*/
        hmi_menu_logic_stop_timer(MENU_CORE_OPEN_TIMER, fl_menu_id_U8);
      }
    }
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
    else if (fl_timer_type_U8 == MENU_CORE_WAIT_TIMER)
    {
      HMI_MENU_START_WAIT_TEMP_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_wait_timer_id, HMI_MENU_WAIT_TEMP_TIMER_VALUE);
    }
#endif
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
    else if (fl_timer_type_U8 == MENU_CORE_FASTSCROLL_CNT_INCR_TIMER)
    {
      HMI_MENU_FS_START_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_fastscroll_timer_id, HMI_MENU_FS_CNT_INCR_TIMER_VALUE);
    }
    else if (fl_timer_type_U8 == MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER)
    {
      HMI_MENU_FS_START_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_fastscroll_timer_id, HMI_MENU_FS_RUN_WAIT_TIMER_VALUE);
    }
    else if (fl_timer_type_U8 == MENU_CORE_FASTSCROLL_CNT_START_TIMER)
    {
      HMI_MENU_FS_START_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_fastscroll_timer_id, HMI_MENU_FS_CNT_START_TIMER_VALUE);
    }
#endif
    else
    {
    }
  }
}
/****************************************************************************
Function Name     : hmi_menu_logic_stop_timer
Description       : Common Interface to stop all the timers used in Menu Core
Invocation        : hmi_menu_core_01_chart.c
Parameters        : timer type and menu id.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_stop_timer(UINT8 fl_timer_type_U8, MENU_LIST_ID_T fl_menu_id_U8)
{
	MENU_CONTROL_T const * fl_menu_cntrl_SP;
	UINT8 fl_menu_inst_U8;

  fl_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
 	fl_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(fl_menu_id_U8);

	if((fl_menu_cntrl_SP != NULL)&&(fl_menu_inst_U8 < NB_OF_MENU_INSTANCE))
	{
		switch(fl_timer_type_U8)
		{
		case MENU_CORE_OPEN_TIMER:
			HMI_MENU_STOP_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id);
			break;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
		case MENU_CORE_WAIT_TIMER:
			HMI_MENU_STOP_WAIT_TEMP_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_wait_timer_id);
			break;
#endif
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
		case MENU_CORE_FASTSCROLL_CNT_INCR_TIMER:
		case MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER:
		case MENU_CORE_FASTSCROLL_CNT_START_TIMER:
			HMI_MENU_FS_STOP_TIMER(fl_menu_id_U8, hmi_menu_inst_config_table[fl_menu_inst_U8].menu_fastscroll_timer_id);
			break;
#endif
		default:
           /* Adding comment to fix MISRA warning 3847096 */ 
			break;
		}
	}
}
/****************************************************************************
Function Name     : hmi_menu_logic_open_timer_timeout
Description       : Menu Open Timer timeout.
Invocation        : hmi_menu_core_01_chart.c
Parameters        : fl_timer_id_U8.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_open_timer_timeout(UINT8 fl_timer_id_U8
                                  #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                    , UINT8 fl_close_anim_id_U8
                                  #endif
                                  )
{
    UINT8 fl_menu_inst_U8;
    for(fl_menu_inst_U8 = 0;fl_menu_inst_U8 < NB_OF_MENU_INSTANCE;fl_menu_inst_U8++)
    {
       if(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id == fl_timer_id_U8)
       {
#ifndef HMI_MENU_OPEN_PARENT_ON_TIMEOUT
          hmi_menu_logic_process_menu_close(MENU_ACTION_CLOSE_ON_TIMEOUT,l_menu_instance_array[fl_menu_inst_U8].menu_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                  ,fl_close_anim_id_U8
#endif
                                 );
#else
	      hmi_menu_logic_open_parent_menu(l_menu_instance_array[fl_menu_inst_U8].menu_id);
#endif	
								 
            break;
       }
    }
}
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/****************************************************************************
Function Name     : hmi_menu_logic_wait_timer_timeout
Description       : Wait Timer timout. Start Please wait Anim.
Invocation        : hmi_menu_core_01_chart.c
Parameters        : fl_timer_id_U8.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_wait_timer_timeout(UINT8 fl_timer_id_U8)
{
    UINT8 fl_menu_inst_U8;
    for(fl_menu_inst_U8 = 0;fl_menu_inst_U8 < NB_OF_MENU_INSTANCE;fl_menu_inst_U8++)
    {
       if(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_wait_timer_id == fl_timer_id_U8)
       {
          hmi_menu_chart_Wait_temp_timeout(&l_menu_core_chart_inst_array[fl_menu_inst_U8]);
          break;
       }
    }
}
#endif
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
/****************************************************************************
Function Name     : hmi_menu_logic_fast_scroll_timer_timeout
Description       : Fast Scroll timout. Start Fastscroll Anim.
Invocation        : hmi_menu_core_01_chart.c
Parameters        : fl_timer_id_U8.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_fast_scroll_timer_timeout(UINT8 fl_timer_id_U8)
{
    UINT8 fl_menu_inst_U8;
    for(fl_menu_inst_U8 = 0;fl_menu_inst_U8 < NB_OF_MENU_INSTANCE;fl_menu_inst_U8++)
    {
       if(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_fastscroll_timer_id == fl_timer_id_U8)
       {
          hmi_menu_chart_Menu_FSTimeout(&l_menu_core_chart_inst_array[fl_menu_inst_U8]);
          break;
       }
    }

}
#endif

/*============================================================================
** Function Name:    hmi_menu_logic_left_menu_action
** Description:      This function shall be used to perform left action.
** Invocation:       Invoked by logic.c
** Inputs/Outputs:   p_menu_cntrl_ptr, menu action
** Critical Section: None.
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_left_menu_action(MENU_CONTROL_T *p_menu_cntrl_SP, UINT8 p_menu_action_U8)
{
	MENU_CB_RESULT_T fl_cb_result_e;
	MENU_CB_RESULT_T fl_gotoParentMenu_U8;
	const MENU_DEF_T *fl_sub_menu_ref_ptr;
	const MENU_DEF_T *fl_root_menu_ref_ptr;
	MENU_DEF_T const *fl_menu_def_SP;
	UINT8 fl_menu_inst_no_U8;
	UINT16 temp;
	BOOLEAN temp_1;

	fl_gotoParentMenu_U8 = 0;
	fl_cb_result_e = MENU_CB_ACTION_NONE;
	temp_1 = FALSE;

	if ((p_menu_cntrl_SP != FNULL) && (p_menu_cntrl_SP->menu_id < TOTAL_MENU_ID))
	{
	   fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(p_menu_cntrl_SP->menu_id);
	   fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
	   if ((p_menu_cntrl_SP->menu_level_U8 != HMI_MENU_LEVEL_0) && (fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE))
	   {
		  if ((p_menu_cntrl_SP->menu_level_U8 > HMI_MENU_LEVEL_1) &&
			  (p_menu_action_U8 == MENU_ACTION_LEFT_LONG))
		  {
			UINT8 fl_menu_level_to_move = 0U;
			UINT8 fl_cur_menu_level = p_menu_cntrl_SP->menu_level_U8;
	/*Below macro is used to open the menu with the custom level for the LEFT_LONG action.
	Application should provide the implementation for HMI_MENU_GET_MENU_LEVEL_TO_MOVE function*/
	#ifdef HMI_MENU_GET_MENU_LEVEL_TO_MOVE
			fl_menu_level_to_move = HMI_MENU_GET_MENU_LEVEL_TO_MOVE(p_menu_cntrl_SP->menu_id);
			/*set fl_cb_result_e to MENU_BTN_ABSORBED for invalid input*/
			if (fl_menu_level_to_move >= fl_cur_menu_level)
			{
								fl_cb_result_e = MENU_BTN_ABSORBED;
			}
			if (fl_cb_result_e != MENU_BTN_ABSORBED)
	#endif
			{
				/* Open the ROOT Menu - to be implemented */
				/* Loading the menu level to be taken care */
				fl_sub_menu_ref_ptr = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
				fl_root_menu_ref_ptr = hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id].parent_menu;
				while (fl_root_menu_ref_ptr != NULL)
				{
					fl_cur_menu_level--;
					if ((fl_root_menu_ref_ptr->parent_menu != NULL) &&
						(fl_menu_level_to_move != fl_cur_menu_level))
					{
							fl_sub_menu_ref_ptr = fl_root_menu_ref_ptr;
							fl_root_menu_ref_ptr = fl_root_menu_ref_ptr->parent_menu;
					}
					else
					{
							fl_root_menu_ref_ptr = NULL;
					}
				}
				/* post MENU_ACTION_CLOSE to existing menu*/
				if (fl_menu_def_SP->cb != FNULL)
				{
					(void)fl_menu_def_SP->cb(MENU_ACTION_CLOSE, p_menu_cntrl_SP, MENU_BTN_INVALID);
				}
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
				(void)hmi_menu_logic_SubMenu_Open(fl_sub_menu_ref_ptr->parent_menu, fl_sub_menu_ref_ptr, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
	#else
		fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_sub_menu_ref_ptr->parent_menu, fl_sub_menu_ref_ptr, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
	#endif
	#if 0
			hmi_menu_logic_Set_ParentFocus(p_menu_cntrl_SP, fl_sub_menu_ref_ptr);
	#endif
				hmi_menu_logic_Focusline_Center(p_menu_cntrl_SP);
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
				/* Trigger DOUBLE WIPER */
				/* below commented check was there in L538 menu core and not in C520.In this release */
				/* removed, need to anlayse its requirement                                          */
				/* if(fl_cb_result_e == MENU_CB_ACTION_WAIT)*/
				fl_cb_result_e = MENU_CB_ACTION_DOUBLE_WIPER_ANM;
	#endif
			}
		  }
		  else
		  {
			/* hmi_menu_logic_process_menu_close should be called here. Will be changed in future req/redesign
			in redesign return from application will not be considered*/
			if (fl_menu_def_SP->cb != NULL)
			{
				fl_gotoParentMenu_U8 = fl_menu_def_SP->cb(MENU_ACTION_CLOSE, p_menu_cntrl_SP, MENU_BTN_INVALID);
			}
			temp = p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC;
			if (MENU_CB_ACTION_NONE == fl_gotoParentMenu_U8)
			{
				temp_1 = TRUE;
			}
			if ((0U != temp) && (FALSE != temp_1))
			{
				/*
				* Redisplay current menu
				*/
				fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_menu_def_SP, fl_menu_def_SP, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
			}
			else
			{
				if (fl_menu_def_SP->parent_menu != FNULL)
				{
					fl_sub_menu_ref_ptr = &hmi_menu_const_struct_array_table[p_menu_cntrl_SP->menu_id];
					/* We are in a submenu: close sub menu */
					fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_menu_def_SP->parent_menu, fl_sub_menu_ref_ptr, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
	#if 0
			hmi_menu_logic_Set_ParentFocus(p_menu_cntrl_SP, fl_sub_menu_ref_ptr);
	#endif
					hmi_menu_logic_Focusline_Center(p_menu_cntrl_SP);
				}
			}
	#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			/* Trigger LEFT WIPER*/
			if (fl_cb_result_e != MENU_CB_ACTION_WAIT)
			{
				fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_ANM;
	#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
				MENU_DO_FRAME_EXPAND_ANIMATION;
	#endif
			}
			else
			{
				fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM;
			}
	#endif
		  }
		  if ((p_menu_cntrl_SP->menu_properties & MENU_PRO_DYNAMIC) == 0U)
		  {
		    p_menu_cntrl_SP->menu_level_U8 = hmi_menu_logic_get_Menu_level(p_menu_cntrl_SP->menu_id);
		  }
	   }
	}
	return (fl_cb_result_e);
}
/*============================================================================
** Function Name:    hmi_menu_logic_process_available_data
** Description:      This function intimate menu core that requested data is available
** Invocation:       Invoked by Application(RDAP)
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
void hmi_menu_logic_process_available_data(MENU_LIST_ID_T fl_menu_id_U8)
{
  UINT8 fl_menu_inst_no_U8;
  fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
  if(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
  {
     hmi_menu_chart_DataAvailable(&l_menu_core_chart_inst_array[fl_menu_inst_no_U8]);
  }
}
/*============================================================================
** Function Name:    hmi_menu_logic_exit_fast_scroll
** Description:      This function is called by application to stop fast scroll
** Invocation:       Invoked by Application(RDAP)
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
void hmi_menu_logic_exit_fast_scroll(MENU_LIST_ID_T fl_menu_id_U8)
{
  UINT8 fl_menu_inst_no_U8;
  fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
  if(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE)
  {
     hmi_menu_fast_scroll_inactive(&l_menu_core_chart_inst_array[fl_menu_inst_no_U8]);
  }
}
/*============================================================================
** Function Name    : hmi_menu_core_disable_timer_status
** Visibility       : Local, Interface to the Popup Core
** Description      : Disable the timer status
** Invocation       : Invoked by the menu Core
** Inputs/Outputs   : disable timer status
** Critical Section : No
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
static void hmi_menu_logic_disable_open_timer_status(MENU_LIST_ID_T fl_menu_id_U8)
{
	UINT8 fl_menu_inst_U8;
  fl_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
	if(fl_menu_inst_U8 < NB_OF_MENU_INSTANCE)
  {
		l_menu_instance_array[fl_menu_inst_U8].timer_status_BOOL =  FALSE;
	}
}
/*============================================================================
** Function Name    : hmi_menu_core_enable_timer_status
** Visibility       : Local, Interface to the Popup Core
** Description      : Disable the timer status
** Invocation       : Invoked by the menu Core
** Inputs/Outputs   : enable timer status
** Critical Section : No
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
static void hmi_menu_logic_enable_open_timer_status(MENU_LIST_ID_T fl_menu_id_U8)
{
	UINT8 fl_menu_inst_U8;
  fl_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
	if(fl_menu_inst_U8 < NB_OF_MENU_INSTANCE)
  	{
	    l_menu_instance_array[fl_menu_inst_U8].timer_status_BOOL =  TRUE;
	}
}
/*============================================================================
** Function Name    : hmi_menu_logic_is_open_timer_enabled
** Visibility       : Local, Interface to the Popup Core
** Description      : Disable the timer status
** Invocation       : Invoked by the menu Core
** Inputs/Outputs   : disable timer status
**                    
**                    
** Critical Section : No
** Created          : 20 sep, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
static BOOLEAN hmi_menu_logic_is_open_timer_enabled(MENU_LIST_ID_T fl_menu_id_U8)
{
	UINT8 fl_menu_inst_U8;
	BOOLEAN fl_timer_status_BOOL = FALSE;
  fl_menu_inst_U8  = hmi_menu_logic_get_menu_inst_no(fl_menu_id_U8);
	if(fl_menu_inst_U8 < NB_OF_MENU_INSTANCE)
	{
		fl_timer_status_BOOL = l_menu_instance_array[fl_menu_inst_U8].timer_status_BOOL;
	}
	return fl_timer_status_BOOL; 
}
/*============================================================================
** Function Name    : hmi_menu_logic_process_menu_close
** Description      : Process different menu close (timeout,close by app,close by child,parent)
** Invocation       : Invoked by the menu Core
** Inpu1ts/Outputs  : menu_close_action,menu_id,anim_id
** Critical Section : No
** Created          : 19 Oct, 2013 CSAKTHIV
** Updated          : 
**==========================================================================*/
static void hmi_menu_logic_process_menu_close(UINT8 fl_menu_close_action_U8, MENU_LIST_ID_T p_close_menu_id_e
                                                   #ifdef LSH_ANIMATION_SUPPORT_ENABLED
						                      	   ,UINT8 p_menu_anim_ID_U8
						                           #endif
												   )
{
	UINT8                  fl_logic_st_id_U8;
	UINT8                  fl_menu_inst_array_idx_U8;
	MENU_CONTROL_T        *fl_menu_close_ptr;
	MENU_DEF_T  const     *fl_menu_def_SP;

	/* Array Access Boundary check */
	if(p_close_menu_id_e < TOTAL_MENU_ID)
	{
		/* Get the menu instance array index based on menu id */
		fl_menu_inst_array_idx_U8 = hmi_menu_logic_get_menu_inst_no(p_close_menu_id_e);
		/* Find the Menu instance to be closed */
		fl_menu_close_ptr   = hmi_menu_logic_get_menu_instance(p_close_menu_id_e);
		/* check the close condition */
		if((fl_menu_close_ptr != FNULL) && (fl_menu_inst_array_idx_U8 < NB_OF_MENU_INSTANCE) && (fl_menu_close_ptr->menu_id < TOTAL_MENU_ID))
		{
		  fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_menu_close_ptr->menu_id];
		  fl_logic_st_id_U8 = hmi_menu_logic_get_screen_id(fl_menu_close_ptr);

		  if ((fl_menu_close_action_U8 == MENU_ACTION_FORCED_CLOSE) ||
			  (fl_menu_close_action_U8 == MENU_ACTION_CLOSE_ON_TIMEOUT))
		  {
			if (fl_menu_def_SP->cb != FNULL)
			{
				(void)fl_menu_def_SP->cb((MENU_ACTION_T)fl_menu_close_action_U8, fl_menu_close_ptr, MENU_BTN_INVALID);
			}
			/*there is no need to check the return value from application. If menu_close is called then it is required to intimate
			the app about close action. If return value is checked, then there will be more changes in menu core whenever menu_close is called */

			/* Destroy the menu instance only when the current menu id is same as p_close_menu_id_e. */
			hmi_menu_logic_destroy_menu_instance(p_close_menu_id_e);
			hmi_menu_logic_update_current_focus_menu_ptr();
			(void)LSH_REM_STATE_EXT(fl_logic_st_id_U8, p_menu_anim_ID_U8, p_close_menu_id_e);
		  }

		  /* case MENU_ACTION_CLOSE:
		  callback called in left_action. since return value from application this cannot be included
		  It will be changed on future redesign in which return value from application will not be considered
		  action will be taken based on menu_level */
		}
	}
}


/*============================================================================
** Function Name:    hmi_menu_logic_get_screen_id
** Visibility:       global
** Description:      This function is to get the screen based on the focus entry
**
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr, p_focus_entry_U16
** Outputs:          LSH_STATE_ID_T
** Critical Section: None.
** Created:          15-Jan-2014
** Updated:
**==========================================================================*/
LSH_STATE_ID_T   hmi_menu_logic_get_screen_id(MENU_CONTROL_T const* p_menu_cntrl_ptr)
{
  /*Initialize with invalid screen id*/
  LSH_STATE_ID_T        fl_screen_id_U8 = LSH_NUMBER_OF_LOGIC_STATES;

  if (p_menu_cntrl_ptr != FNULL)
  {
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
    UINT16                 fl_get_absl_index_U16;
    UINT16                fl_menu_total_entry_nbr_U16;
    UINT16                fl_focus_entry_U16;

    fl_focus_entry_U16 = p_menu_cntrl_ptr->focus_entry_U16;
    if (p_menu_cntrl_ptr->menu_id < TOTAL_MENU_ID)
    {
      fl_menu_total_entry_nbr_U16 = hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].total_entry_nbr;
      if ((fl_focus_entry_U16 >= fl_menu_total_entry_nbr_U16) || ((p_menu_cntrl_ptr->focus_entry_U16 >= HMI_MAX_MENU_ITEMS)))
      {
        /* may be a dynamic menu like cd track list, preset list */
        fl_focus_entry_U16 = 0;
      }
	  
      
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
	  if (fl_focus_entry_U16 < HMI_MAX_MENU_ITEMS)
      {
        fl_get_absl_index_U16 = (UINT16)p_menu_cntrl_ptr->menu_itm_absl_indx[fl_focus_entry_U16];
        /* clear Gray out item bit */
        fl_get_absl_index_U16 = fl_get_absl_index_U16 & (~((UINT16)(BIT7)));
	  }
	  else
	  {
		fl_get_absl_index_U16 = fl_menu_total_entry_nbr_U16; //Setting invalid value. This is added for warning fix
	  }
#else
        fl_get_absl_index_U16 = fl_focus_entry_U16;
#endif
      
      if (fl_get_absl_index_U16 < fl_menu_total_entry_nbr_U16)
      {
        fl_screen_id_U8 = hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].entry_array.static_array[fl_get_absl_index_U16].item_screen_id_U8;
      }
    }
#else
    fl_screen_id_U8 = (UINT8)(hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].disp_screen_id);
#endif
  }
  return(fl_screen_id_U8);
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_menu_inst_no
** Visibility:       global
** Description:      This function is to get the instance no for the menu id . Instance no is decided from configuration in tool.
**
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_CONTROL_T *ptr, p_focus_entry_U16
** Outputs:          LSH_STATE_ID_T
** Critical Section: None.
** Created:          15-April-2014 by CSAKTHIV
** Updated:
**==========================================================================*/
static UINT8 hmi_menu_logic_get_menu_inst_no(MENU_LIST_ID_T fl_menu_id_U8)
{
	UINT8 fl_menu_inst_no = NB_OF_MENU_INSTANCE;
	if (fl_menu_id_U8 < TOTAL_MENU_ID)
	{
		fl_menu_inst_no = hmi_menu_const_struct_array_table[fl_menu_id_U8].inst_no;
	}
	return fl_menu_inst_no;
}
/*============================================================================
** Function Name:    hmi_menu_logic_open_parent_menu
** Visibility:       global
** Description:      This interface opens the parent menu for the given child active menu
**
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_LIST_ID_T fl_curr_menu_id_U8
** Outputs:          void
** Critical Section: None.
** Created:          09-July-2014 by CSAKTHIV
** Updated:
**==========================================================================*/
void hmi_menu_logic_open_parent_menu(MENU_LIST_ID_T fl_curr_menu_id_U8)
{
	MENU_DEF_T  const   *fl_parent_menu_def_ptr;
	MENU_DEF_T  const   *fl_current_menu_def_ptr;
	UINT8                fl_menu_inst_no_U8;
	MENU_ANIM_DATA_T     fl_menu_anim_data;
    MENU_CONTROL_T      *fl_menu_cntrl_ptr;
	MENU_CB_RESULT_T     fl_cb_result_e;

	fl_menu_cntrl_ptr = hmi_menu_logic_get_menu_instance(fl_curr_menu_id_U8);

	if(fl_menu_cntrl_ptr != NULL)
	{
		fl_menu_inst_no_U8 = hmi_menu_logic_get_menu_inst_no(fl_curr_menu_id_U8);
		fl_current_menu_def_ptr = &hmi_menu_const_struct_array_table[fl_curr_menu_id_U8];
		fl_parent_menu_def_ptr  = hmi_menu_const_struct_array_table[fl_curr_menu_id_U8].parent_menu;
		if((fl_parent_menu_def_ptr != NULL)&&(fl_menu_inst_no_U8 < NB_OF_MENU_INSTANCE))
		{
			fl_menu_anim_data.menu_anim_prev_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
			fl_menu_anim_data.menu_anim_prev_menu_id_E     = fl_menu_cntrl_ptr->menu_id;
			fl_menu_anim_data.menu_anim_prev_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
			fl_menu_anim_data.menu_anim_prev_screen_id_U8   = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);

			/* hmi_menu_logic_process_menu_close should be called here. Will be changed in future req/redesign
			in redesign return from application will not be considered*/
			if (fl_current_menu_def_ptr->cb != NULL)
			{
				(void)fl_current_menu_def_ptr->cb(MENU_ACTION_CLOSE, fl_menu_cntrl_ptr, MENU_BTN_INVALID);
			}

			fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_parent_menu_def_ptr, fl_current_menu_def_ptr, fl_menu_inst_no_U8, MENU_ACTION_OPEN_FROM_CHILD);
			/* Reload the menu cntrl ptr to ensure that we are pointing the correct instance after
			closing the menu instance if opened. It is really needed only when there is a instance
			but for additional robustness it is newly fetched */
			hmi_menu_logic_update_current_focus_menu_ptr();
			fl_menu_cntrl_ptr = hmi_menu_logic_get_required_menu_instance(fl_menu_inst_no_U8);
			hmi_menu_logic_Focusline_Center(fl_menu_cntrl_ptr);
			hmi_lsh_freeze_button_events_ext(fl_menu_anim_data.menu_anim_prev_screen_id_U8,fl_menu_anim_data.menu_anim_prev_menu_id_E);

      #ifdef LSH_ANIMATION_SUPPORT_ENABLED
			/* Trigger LEFT WIPER*/
			if(fl_cb_result_e != MENU_CB_ACTION_WAIT)
			{
				fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_ANM;
				#ifdef HMI_MENU_DO_FRAME_EXPAND_ANIMATION
					MENU_DO_FRAME_EXPAND_ANIMATION;
				#endif
			}
			else
			{
				fl_cb_result_e = MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM;
			}
      #endif


			fl_menu_anim_data.menu_anim_curr_focus_line_U16 = fl_menu_cntrl_ptr->focus_line_U16;
			fl_menu_anim_data.menu_anim_curr_menu_id_E     = fl_menu_cntrl_ptr->menu_id;
			fl_menu_anim_data.menu_anim_curr_focus_entry_U16 = fl_menu_cntrl_ptr->focus_entry_U16;
			fl_menu_anim_data.menu_anim_curr_screen_id_U8   = hmi_menu_logic_get_screen_id(fl_menu_cntrl_ptr);

		#ifdef LSH_ANIMATION_SUPPORT_ENABLED
			#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_REMOVE;
			(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			#else
			fl_menu_anim_data.menu_anim_screen_action_U8 = HMI_MENU_SCREEN_ADD;
			(void)hmi_menu_logic_CB_result_anim(&fl_menu_anim_data, fl_cb_result_e);
			#endif	
		#else
			if(MENU_CB_ACTION_EXIT == fl_cb_result_e)
			{
				hmi_menu_logic_Menu_Close(fl_menu_cntrl_ptr->menu_id);
			}
			else
			{
				hmi_menu_logic_View_Mngr_Rq(fl_menu_cntrl_ptr->menu_id, fl_menu_anim_data.menu_anim_curr_screen_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
					, ANIM_MAX_ID
#endif
					, HMI_MENU_SCREEN_ADD);
			}
		#endif
		}
	}
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_parent_menu_id
** Visibility:       global
** Description:      Interface to get the parent menu id for the given menu id. If no parent, TOTAL_MENU_ID 
**                   will be returned
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           MENU_LIST_ID_T fl_curr_menu_id_U8
** Outputs:          MENU_LIST_ID_T
** Critical Section: None.
** Created:          09-July-2014 by CSAKTHIV
** Updated:
**==========================================================================*/
MENU_LIST_ID_T hmi_menu_logic_get_parent_menu_id(MENU_LIST_ID_T fl_curr_menu_id_U8)
{
	MENU_DEF_T  const   *fl_parent_menu_def_ptr;
	MENU_LIST_ID_T       fl_parent_menu_id_e = TOTAL_MENU_ID;
    if(fl_curr_menu_id_U8 < TOTAL_MENU_ID)
    {
		fl_parent_menu_def_ptr  = hmi_menu_const_struct_array_table[fl_curr_menu_id_U8].parent_menu;
		if(fl_parent_menu_def_ptr != NULL)
		{
			fl_parent_menu_id_e = hmi_menu_logic_get_menu_index(fl_parent_menu_def_ptr);
		}
    }
	return fl_parent_menu_id_e;
}
#if ((defined (HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT)&& defined(HMI_MENU_CORE_PAGE_BASED_FOCUS_FOR_GREYOUT)) || defined(LSH_ANIMATION_SUPPORT_ENABLED))
/*============================================================================
** Function Name:    hmi_menu_logic_get_page_number
** Visibility:       global
** Description:      Interface to get the page number of the focus entry based on the number of displayed lines.
** Invocation:       Invoked by hmi_menu_logic.c
** Inputs:           UINT16 fl_focus_entry_U16, UINT16 fl_displayed_lines_U16
** Outputs:          
** Critical Section: None.
** Created:          23-August-2014 by CSAKTHIV
** Updated:
**==========================================================================*/
static UINT16 hmi_menu_logic_get_page_number(UINT16 fl_focus_entry_U16, UINT16 fl_displayed_lines_U16)
{
  UINT16 fl_menu_page_number_U16;
  if ((fl_focus_entry_U16 == 0U) || (fl_displayed_lines_U16 == 0U))
  {
    fl_menu_page_number_U16 = 0;
  }
  else
  {
    fl_menu_page_number_U16 = (fl_focus_entry_U16 / fl_displayed_lines_U16);
  }
  return fl_menu_page_number_U16;
}
#endif
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
** CMS Rev 1.0      03-APR-10    jpradeep
** Creation.
**
**==========================================================================*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 22-04-10
Traceability      : Menu Core Development
Change Description: Modified the properties from enum to Macro and the function
                    Prototypes are defined correctly.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-05-10
Traceability      : Menu Core Development
Change Description: Review comments updated.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 26-05-10
Traceability      : Menu Core Development
Change Description: Review comments updates and QAC ver 7.1 fixes
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 29-05-10
Traceability      : Menu Core Development
Change Description: Menu Fast scroll implementation.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 06-06-10
Traceability      : Menu Core Development
Change Description: Following defects/Improvements were made
                  1.Menu Left/Right increment issue on the CLOCK Menu
                    Cause: AVC, SOUND Menu path has been taken
                    Fix  : Differentiated by checking the CLOCK MEnu
                           Property.

                  2.Menu not Open on Fast Menu Button Press
                    Cause: Timing issue. Before Menu close function being
                           called, Menu Open is called hence another instance
                           for the same is created.
                    Fix  : Check made inside the hmi_menu_logic_Menu_Open()
                           whether the triggered menu is already opened or not.

                  3.Menu Focus line center(Parent focus) while LEFT btn press form Submenu
                    Cause: Instead of the submenu reference current menu refernce is pointed
                           to the function hmi_menu_logic_Set_ParentFocus()
                    Fix  : Stored the submenu reference and pointed correctly.

                  4.Property MENU_PRO_DISABLE_SELECTED_ENTRY added to enable the
                    Selected Entry or not.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 16-06-10
Traceability      : const - Definition
Change Description: const is prefixed at certain places and MENU_CONTROL_T
                    is changed to MENU_DEF_T
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 24-06-10
Traceability      : Menu Fast scroll updation
Change Description: Corrected the Menu Fast scroll compilation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 28-06-10
Traceability      : Menu UTP Framework Addition
Change Description: Menu UTP framework has been done with the Macro
                    HMI_MENU_CORE_UINT_TEST_ENABLE
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 30-06-10
Traceability      : Menu Animation Support
Change Description: Updated the LSH interface to support the animation bascially
                    to get clean compile.Menu Animation Feature support shall
                    be implemented completely later.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 10-07-10
Traceability      : Menu Defect fixes
Change Description: Made a FNULL check befor calling the callback().
                    Button CB result set as MENU_PROCESS_MENU as default
                    inside the hmi_menu_logic_button_processing()
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-07-10
Traceability      : Menu Issue fixes
Change Description: 1.In hmi_menu_logic_OK_action() , added the
                      hmi_menu_logic_View_Mngr_Rq().
                    2.In hmi_menu_logic_button_processing(), the function
                      hmi_menu_chart_Btn_trigger() is executed only if any of
                      the menu action is found otherwise fl_menu_btn_action_U8
                      is returned with MENU_BTN_NONE.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 13-07-10
Traceability      : Menu Defect fixes
Change Description: Made a FNULL check inside the function to fetch the ptr
                    hmi_menu_logic_get_menu_from_history()
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 20-07-10
Traceability      : Menu Animation support
Change Description: Menu animation handling logic and functions are added
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 20-07-10
Traceability      : Menu Animation - PR 34646 comments update
Change Description: Defect-> 5
                    Check of MENU_CB_ACTION_EXIT() shall be made prior to
                    sending the view_manager_display Request for animation
                    and display triggerring in all the mentioned functions.
                    Fix:
                    MENU_CB_ACTION_EXIT made prior to sending the update for
                    hmi_menu_logic_View_Mngr_Rq().
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 20-07-10
Traceability      : CQ 90396
Change Description: p_menu_id_U8 parameter removed from certain functions.
                    Current_menu_ptr is used to fetch the menu_id since stored
                    menu_ID got changed over the course of time while processing.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 26-07-10
Traceability      : Menu Animation Feature
Change Description: Menu Animation feature implementation completed.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-08-10
Traceability      : Menu Animation Feature - PR 34885 review comments updated
Change Description: Defect 1: In MenuOpen(), AnimID was not sent
                              Inside Menu_Open(), animID sent directly via lsh
                    Defect 2: MENU_CB_ACTION_EXIT is checked inside OK_action
                              Since MSB bit is set if the animation is enable
                              TESTBIT() used instead of that.
                    Defect 3: Menu level set as 0 before trigger Wiper/Double
                              Moved the menu level set function after triggering
                              Wiper/Double Wiper animation.
                    Defect 4: ANIM_WAIT macro be added inside case of Get_anim_ID()
                              Added inside the function.
                    Defect 5: UP/DOWN/list Anim should not enter ANIMATION_ST
                              Reloaded the callback value as CB_Completed.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-08-10
Traceability      : Menu Animation Feature - CQ 91449
Change Description: Made Return CB as completed and OR check instead of AND
                    Menu level update happens after updating the Double/Wiper
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : emanoj1
CDSID             : 04-Aug-2010
Traceability      : C520 L1 trip timer reset handling
Change Description: Added focus lost and got menu action notification via the
                    menu callback.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 07-Aug-2010
Traceability      : History Menu ID Insertion
Change Description: Since the MenuID seems to be different within the Menu and
                    submenu the history array which inturn looks at the menu
                    instance array triggers the presentation of instance array.
                    But if the screen Id's are different this logic doesn't work
                    Hence menuID history array has been inserted and it was
                    handled only in the Presentation Deactivation.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 05-Sept-2010
Traceability      : Menu LEFT long press button handling
Change Description: Menu LEFT long press action has been done and the changes
                    were made inside the hmi_menu_logic_LEFT_action().
                    The logic has the Animation triggeering too.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 07-Sept-2010
Traceability      : PR comments updated- 35968
Change Description: Modifications done on the below functions
                    hmi_menu_logic_create_menu, hmi_menu_logic_load_absl_index
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 07-Sept-2010
Traceability      : PR comments updated- 34499
Change Description: Review comments updated
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 08-Sept-2010
Traceability      : Menu core modifications
Change Description: 1.Menu timer started and stopped according to the LOST and
                      GOT FOCUS from the LSH indication. This is because if a
                      warning popups on the Menu then the Menu Timer should be
                      stopped and restarted once the Popup clears.
                    2.In Menu Rebuild function menu instance no is loaded wrongly
                      with menu ID which is corrected.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 29-Sept-2010
Traceability      : PR comments updated- 36952
Change Description: Defect:2
                    New function has been added to validate the item is configured
                    hmi_menu_logic_is_stored_item_enabled() which is bascially
                    used for the history handling feature. HMI application shall
                    call this function and validates from the loaded menu that
                    the item is configured or not.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 30-9-2010
By                : jpradeep
Traceability      : BSDI00093540 - Menu Timer is not restarted upon btn action
                                   on certain Menus
Change Description: If the return value is MENU_BTN_RESTART_TIMER_ABSORBED or
                    MENU_BTN_RESTART_TIMER_NONE then the
                    hmi_menu_logic_Restart_MenuTimer() function is called
                    and current active menu ptr timer is started.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 05-10-10
CDSID             : jpradeep
Traceability      : Menu Core Enhancement
Change Description: The max value of the  array hmi_menu_map_actions[] has been
                    changed to HMI_MENU_TOTAL_BTN_ACNS_MAPPED. The intent of this
                    change is to remove the unwanted menu actions being mapped.
                    Now the array consists only the needed btn sctions that are
                    to be mapped upon corresponding menu actions.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 05-10-10
CDSID             : jpradeep
Traceability      : Menu Core Enhancement
Change Description: MENU_DEF_T  const    *fl_menu_def_SP defined in many
                    functions and accessed in the rest of the logic inside the
                    fucntion. It makes accessing faster.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 22-11-10
CDSID             : jpradeep
Traceability      : Menu Core Issue fixes
Change Description: Issue: Buttons are processed on the submenu eventhough the
                           screen ID's are different.
                    Root cause: It is because the button IDs are posted directly
                    to the focus_menu_ptr from rx_handler.
                    Solution: valid menu instance checkis made to pass the button
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : msenthi4
CDSID             : 18-10-10
Traceability      : Fast scroll support.
Change Description: Return valuse was removed as it was forced to send as fast
                    action status. we need the call back value as wait until
                    RDAP send the data available message.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : msenthi4
CDSID             : 03-11-10
Traceability      : Fast scroll support.
Change Description: End or start of list aniamtion issue fix changes during fast scroll
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 31-12-10
CDSID             : jpradeep
Traceability      : Menu Core Enhancement
Change Description: Added the function hmi_menu_logic_get_required_menu_instance
                    Menu Up action logic revert back to original as there is
                    a wrap round issue found in c520
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-11-10
Traceability      : Menu Item Gray scale support
Change Description: Implemented the Menu item Gray scale logic
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-11-10
Traceability      : MenuClose Animation
Change Description: Issue: Unable to close the Menu instance.
                    Root cause:
                    (Menu close animation was handled differently wherein the
                    animation triggered was based on the source and the
                    destination. Hence the application shall sent the return
                    value of call back with AnimationID instead of
                    MENU_CB_ACTION_COMPLETED or MENU_CB_ACTION_EXIT.
                    In order to identify such cases the MSB bit is set.)
                    In c520 since the MSB bit is not set the Menu instance
                    close was not happened.
                    Fix:
                    MSB bit is set while Menu Instance close by the apps
                    and the MSB bit is cleared while sending animation.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-11-10
Traceability      : Menu Wrap round issue
Change Description: Issue:
                    If only one item is present then also Wrap round occurs.
                    Root cause:
                    There is no logic to block the wrap round if only one
                    item is present earlier.
                    Fix:
                    Before triggering the Wrap round animation checked the
                    (entry_nbr value != 1)
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-11-10
Traceability      : QAC issue fix
Change Description: TESTBIT conditions triggered QAC errors which have been
                    fixed.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 12-11-10
Traceability      : Menu instance close
Change Description: In Menu ok button function, the CB value other than EXIT
                    is forcefully made as EXIT and the open submenu fn is
                    deleted.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 18-Feb-10
Traceability      : Btn handling while Menu Animation running
Change Description: Blocked the Menu Navigation buttons while animation is
                    running.
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 25-Feb-10
Traceability      : Peer review comments update - 40139
Change Description: Menu LEFT/DOUBLE WIPER animation trigger conditions
                    for Menu_Reload() i.e Gray out feature is modified.
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 03-Mar-10
Traceability      : Btn handling while Menu Animation running
Change Description: Menu LEFT/DOUBLE/RIGHT WIPER animation conditions are checked
                    inside the hmi_menu_logic_CB_result_anim() and are forced
                    to enter inside the Animation state. So when those animations
                    are ongoing the button presses are absorbed.
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 30-Mar-11
Traceability      : Left/Right btn block on UP/DOWN animation
Change Description: Blocked the left and Right buttons when the UP/DOWN
                    scroll animation is progressing.
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jpradeep
CDSID             : 05-May-11
Traceability      : Focus bar position retaining after Menu Rebuild/Reload
Change Description: Focus bar position is remembered before doing the
                    Rebuild or Refresh action and then it is validated and
                    retained.
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : vsarava2
CDSID             : 15-Jun-11
Traceability      : Focus handler change
Change Description: Focus handler change changed as per latest LSH
----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jmanojku
CDSID             : 26-07-2011
Traceability      : BSDI00107085 
Change Description: added a new member in the control t structure to store the 
					focus status of the current avtive pointer the timer value 
					is set to 0 when the focus is lost to keep the previous menu 
					active
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : jmanojku
CDSID             : 12-08-2011
Traceability      : Menu timeout issue in L1 C520(BSDI00108032) 
Change Description: Focus not checked for the varient without animation as the 
					focus handler is not called by LSH
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 12.9.2011
By                 : jmanojku
Traceability       : BSDI00104707 
Change Description : Changed menu item as configurable to all sub menu items
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 23.Sep.2011
By                 : jmanojku
Traceability       : SCR-BSDI00105028 
Change Description : Function implemented to check the change and update the menu.
					 This is called in RR 					
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date               : 23.Sep.2011
By                 : jmanojku
Traceability       : SCR-BSDI00105028 
Change Description : the menu level is set when the parant focus is changed 
					
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 30.Sep.2011
By                 : jmanojku
Traceability       : Improvement  
Change Description : Added the Bit check in reload\check_for_relaod functions
			
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 20 Oct 2011
By                 : jpradeep
Traceability       : Dynamic Menu Issue fix
Change Description : Introduced a new menu property MENU_PRO_DYNAMIC_UPDATE
					 and it is updated only after upon Menu_Rebuild	due to 
					 the dynamic removal of Items inside the Menu.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 03 Nov 2011
By                 : jpradeep
Traceability       : CQ 110076
Change Description : Issue:
                     Menu Timeouts after opening a Popup via Menu item 
                     Root cause:
                     Menu timer is started after opening the Popup from the 
                     chart without considering whether the Menu has the focus
                     or not.
                     Resolution:
                     The return status of lsh_add_state() is considered and the
                     current focus menu ptr is updated with the status. So only 
                     if the Menu has focus status as GOT_FOCUS then the timer
					 is started otherwise it is not started.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 11 Nov 2011
By                 : jpradeep
Traceability       : Dynamic Menu Reload
Change Description : Dynamic check reload function has been removed and the logic
                     is incorporated with available Menu Reload function.
					 Dynamic Rebuild is also modified to consider the valid 
					 last saved absolute index for the MEnus having history feature.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 04 Feb 2012
By                 : jpradeep
Traceability       : BSDI00113053
                     Issue - etracker 10967645: C520N - Ford ECO mode screen frozen
Change Description : Root cause:
                     history menu ID array in the menu core logic is overwritten.
                     Since history is lost presentation is not routed and display
                     remains on the screen forever.
                     This happens on when the left btn is pressed and left move
                     animation is started meanwhile another menu instance
                     (Eco overlay) is opened.Since background action happened
                     and the Activation status from lsh made the history array to
                     overwrite on the first (opened) instance rather than 
                     zeroth instance (base menu). It is due updation of array 
                     using the variable l_nb_of_active_instance_S8 which remains 1.
                     Resolution:
                     Updation of Menu ID on the history array has been done
                     based on the menu instance number.
                     Also return status from the lsh is taken care on the Menu_Open()
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 16 Feb 2012
By                 : jpradeep
Traceability       : BSDI00113053
                     Issue - etracker 10967645: C520N - Ford ECO mode screen frozen
                     Peer Review ID - 51697
Change Description : Peer review logged defects fixed - 1, 2, 4 & 5
                     Freezed the buttons upon new menu instance being opened
                     so that the level move or other Menu actions can be
                     stopped.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 12 Mar 2012
By                 : jpradeep
Traceability       : BSDI00110862 - Sometimes focus bar position is not correct
Change Description : Menu reload shall make the pointer to Parent Menu. Since
                     all the Menu Id's of settings menu have the same screen ID,
                     the buttons registered on current Menu be processed on its 
                     parent Menu also. So while level move animation is triggered
                     the buttons are freezed by calling lsh interface.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 03 Apr 2012
By                 : jpradeep
Traceability       : BSDI00115128 - Trip Menu UP/DOWN action is not working
                                    when ACC- Canceled is displayed
Change Description : Root cause:
                     Current_focus_menu_ptr is not updated after instance closes.
                     It is updated only if it gets GOT_FOCUS from lsh.
                     Fix:
                     Current_focus_menu_ptr is updated to below instance
                     once the higher instance closes.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10 Jan 2013
By                 : csakthiv
Traceability       : Redesign
                     
Change Description : Added Multi Instance Support
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 21 Feb 2013
By                 : csakthiv
Traceability       : Redesign
Change Description : Floating Menu Changes;get_anim_id check added in CB_result_anim interface
                     to check whether application is configured some of the anim as invalid.

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 22 Feb 2013
By                 : VMUTHUSU
Traceability       : HMI integratin issue fixes
Change Description : Start time should be invoked only if the timeout configuration is 
                     WITHOUT_TIMEOUT
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10 Apr 2013
By                 : csakthiv
Traceability       : 50917 and 49905
Change Description : Added history macro whereever focus entry is changing. Cleared greyout bit
                     in item absl variable before checking. Sync Changes for TVM. 
					 New property for Dynamic focus and Notification of focus to Application.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 22 Apr 2013
By                 : csakthiv
Traceability       : 
Change Description : Menu Reload Changes,BIT7 Clear for Grayout,Fast Window change property.
                     Entry_nbr >0 check added in Up and Down action to avoid reset    
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 16-May-2013
CDSID             : kcsarava
Traceability      : Added new requirements which is applicable for both menu core 
                    and menu core lite
Change Description: Added multi action with single button support with multi btn 
                    map action table
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 17-May-2013
CDSID             : kcsarava
Traceability      : Added new requirements which is applicable for both menu core 
                    and menu core lite
Change Description: Added BACK and EXIT support in item properties
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 30-May-2013
CDSID             : csakthiv
Traceability      : current focus ptr changed based on Menu open not based on View manager set_focus
                    
Change Description: Added BACK and EXIT support in item properties
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 6-July-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Menu Instance Queue added, PR defect Fix,Focus line Centre,
                    Table for handling buttons in Anim state and QAC warning for Sid and text
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 31-July-2013
CDSID             : csakthiv
Traceability      : 
Change Description: stoping of menu open timer moved to destroy menu instance interface.
                    
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 1-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Renammed MENU_INVALID to TOTAL_MENU_ID as there was a reset issue
                    in C490 as MENU_INVALID is 0xff and the other parameter is MENU_LIST enum.
                    
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 1-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Menu_close return value check from application removed. Menu core itself calling the 
                    Menu_close interface. But there is no return value for this interface.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 5-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Menu_close in Menu_Reload removed. Menu will be opened as submenu not as a seperate menu.
                    
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 6-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Handling deactivate in set focus handler made configurable. It is enabled only for TVM.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Macro added for Menu_open,menu_close ,menu open timeout. Application
                    will use the macro instead of interface. Checking with LSH_ANIMATION
					macro done by menu core.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-August-2013
CDSID             : csakthiv
Traceability      : 
Change Description: Used LSH_ADD_STATE_EXT and LSH_REM_STATE_EXT. Macro HMI_MENU_TVM_MENU_INSTANCE_HANDLING
                    removed .
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 06-Oct-2013
CDSID             : csakthiv
Traceability      : RTC 79385
Change Description: Animation added for Menu Rebuild. Menu chart also updated based on Menu rebuild application
                    cb result
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 15-Oct-2013
CDSID             : csakthiv
Traceability      : RTC 57306
Change Description: Left and right buttons removed from fast scroll configuration button. For sound menu bass and fader 
                    bar movement will be handled by adding repeat event in sea component. Menu core will support
					fast scroll only for up and down buttons.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-Oct-2013
CDSID             : csakthiv
Traceability      : 84370
Change Description: Enum MENU_ACTION_CLOSE_ON_TIMEOUT to inform application that menu is closed on timeout.
                    Return value from application will not be considered.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-Oct-2013
CDSID             : csakthiv
Traceability      : 
Change Description: 1.hmi_menu_logic_Focusline_Center changed from static to extern. Applications are calling
                    hmi_menu_logic_Set_SelectEntry() unnecessarily to call hmi_menu_logic_Focusline_Center().
                    Now application can call hmi_menu_logic_Focusline_Center() separately. 
					2.Focus Entry = 0 to number of item
					Selected Entry = menu item number(item_absl_index value).
					In presenation this value should be converted to 0 to entry_nbr.  
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 01-Dec-2013
CDSID             : csakthiv
Traceability      :
Change Description: Menu Rebuild MENU_CONTROL_T ptr passed to application corrected from current_menu_focus_ptr to instance menu _ptr
                    MENU OPEN TIMER restarted on submenu open with submenu timeout value.
                    hmi_menu_logic_get_menu_instance interface changed from static to extern for Frame expand animation for TVM
                    Both changes done based TVM defects.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 06-Dec-2013
CDSID             : csakthiv
Traceability      :
Change Description: Redesign of UP and DOWN menu actions for P42 Program's SKIP on grey out implementation.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 15-Dec-2013
CDSID             : csakthiv
Traceability      :
Change Description: Menu core exist from animation state,if second screen is added without animation. This issue fixed in this release.
                    Clock format number of entries corrected. Done for TVM.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 15-Dec-2013
CDSID             : csakthiv
Traceability      :
Change Description: MENU_ACTION_CLOSE called when LEFT_LONG is pressed in any menu. close action posted to existing menu

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 15-Feb-2014
CDSID             : csakthiv
Traceability      :
Change Description: C346 MCA Global Clock screen Defect fix.

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 6-Mar-2014
CDSID             : csakthiv
Traceability      : Bug115: Menu Level is set incorrectly for dynamic menus
 	 	 	 	 	Bug122: Anim state is not changing to Anim complete state during contenous UP and Down Button action
Change Description: 1. Default menu level was set before the application callback so that application set menu level not
                       overwritten by menu core
                    2. In menu core chart, for all instance if current focus menu is null, it is going to inactive state,
                       but that is wrong. So checked whether menu id in that instance is active. If it is not active move to
                       inactive state.
                    3. QAC warning Fix and Null/Invalid return value check added
                    4. Animation state of menu core is now in sync with view manager. Handled ANIMATION_STARTED status from
                       view manager. Previously menu core enter into anim state immediately after placing anim request. Now
                       menu core will enter into anim state only after receiving ANIMATION_STARTED_EV from view manager.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 10-Mar-2014
CDSID             : csakthiv
Traceability      : Bug 28: Support for separate Closing and Opening animations during Menu traversal(Up/Down/Left/Right) 
Change Description: 1. Support for Content screen Menu added as configurable from menu configurator tool
					2. Enable HMI_MENU_CORE_CONTENT_MENU_ENABLED macro from menu tool if Content screen menu feature for the project.
					3. Setting the parent menu focus entry on pressing left button was done by menu core before calling
					   application callback. Because of calling after application callback,application set focus entry
					   is replaced by menu cores default value. This change is required to support P552 tabbed content screen menus
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 18-Mar-2014
CDSID             : csakthiv
Traceability      : Bug 125
Change Description: For removing screen id, add the previous menu id as client id and for adding screen id use the current
                    menu id as client id.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 28-Mar-2014
CDSID             : csakthiv
Traceability      : Bug 177
Change Description: value for HMI_MENU_EXIT_WITH_ANIM_MASK is defined based on the configuration in tool. If UINT8(if anim id < 125), then BIT7 used as
                    anim mask and if UINT16(if anim id > 125) then BIT15 is used as anim mask.This is made configurable so that there is no 
					need to make changes in existing program. 
                    
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 3-April-2014
CDSID             : csakthiv
Traceability      : Bug 142
Change Description: Core and tool version mismatch check. If they are different, then compiler error will be generated from core.
					QAC warning fix.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 6-April-2014
CDSID             : csakthiv
Traceability      : Bug 52,Bug 185 ,Bug 186
Change Description: Fast scrool issue in TVM and MCA fixed. In create menu, dynamic menu initialized first, before 
                    calling the item config callback.
					
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 10-April-2014
CDSID             : csakthiv
Traceability      :
Change Description: After fastscroll down action not working.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 12-May-2014
CDSID             : csakthiv
Traceability      : Bug id: 198
Change Description: Screen id information from LSH in presenation cb passed to application through prsnt_screen_id in MENU_CONTROL_T
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-May-2014
CDSID             : csakthiv
Traceability      : Bug id:
Change Description: MENU_ACTION_DEACTIVATED included as action to pass the information that screen is closed
                    by view manager due to priority conflict. Application can action based on their requirement
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-June-2014
CDSID             : csakthiv
Traceability      : Bug id:	207
Change Description:  Release event is not triggered for OK button menu action
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 23-July-2014
CDSID             : csakthiv
Traceability      : Bug id:
Change Description: hmi_menu_logic_MenuDataAvailable() processed based on input menu id instead of 
                    current_focus_menu_ptr
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 23-July-2014
CDSID             : csakthiv
Traceability      : Bug id:
Change Description: Logical error in hmi_menu_logic_update_current_focus_menu_ptr()
-----------------------------------------------------------------------------*/
 /*---------------------------------------------------------------------------
Date              : 15-Sep-2014
CDSID             : csakthiv
Traceability      : Bug id:
Change Description: 1. Task id:200226 If all items in a page is greyout then while up/down then page will be displayed once.
                    2. Task id:205664 Item Config Cb Index for application will be generated in a seperate structure for application.
					3. Task id:205666 Open Parent Menu interface added so that application can open the parent menu for the passed menu id.
					4. Task id:209409 Upon Menu Rebuild/Menu Open, stored focus entry to be mapped with the updated item.  Task id:205666
                    5. Task id:209382 Coverity and Warning fix for Leopard and C346 MCA
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-Sep-2014
CDSID             : csakthiv
Traceability      : Bug id:
Change Description: Task Id: 212081 LSH Freeze in menu open made configurable.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-Nov-2014
CDSID             : csakthiv
Traceability      : Bug id:	209388
Change Description: Task Id: 209388 Individual presentation handler for menu item.
                             Missing #else condition in down button action.
							 245133: Limited window focus line movement feature for Hyundai AE
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 28-Nov-2014
CDSID             : adevi
Traceability      : Task id:247726
Change Description: hmi_menu_logic_get_required_menu_instance function
                    is made global.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 10-Dec-2014
CDSID             : CSAKTHIV
Traceability      : Task id:254797,248423
Change Description: If item is greyedout on rebuild, then menu core will move to next valid item.
                    If item is greyout on reload, then menu core will focus entry to first item.
					Both the above requirement is applied only when configured in .cfg.
					Refer $.cfg file for configuration details.Refer attached excel in taskid for requirement
 					Fixed S101 compiler Warnings.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  06-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  QAC 8.1.2 Warnings resolved.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  10-FEB-15  
By                :  KKUBENDI
Traceability      :
Change Description:  Compiler warning fix for Honda THAA..
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  26-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  Task 284549: CGEA MFD: Right/Ok HK on Ipod in device list does
                     not open track list
                     Fix: hmi_menu_logic_LEFT_action, hmi_menu_logic_RIGHT_action and 
           hmi_menu_logic_OK_action functions are modified to find absolute index for
           dynamic menu configuration.

                     Task 294375: Timer not restarting for two menu of the same instance
                     Fix: Validation code added i hmi_menu_logic_Menu_Open to avoid 
           stopping the timer when we open menu with the same instance.
                     Root cause for this issue: When we open the menu with the same
           instance as previous, 'hmi_menu_logic_disable_open_timer_status' function will
           update 'timer_status_BOOL' value to false. In 'hmi_menu_logic_button_processing' 
           menu core will start the timer only when 'timer_status_BOOL' is TRUE. So After 
           the timer is getting elapsed, the menu is closed even when we do Up/Down action.
                      
                     'hmi_menu_logic_create_menu_instance'  function modified to destroy the
           instance if we open the menu with the same instance.

                     Use case :  
                     Steps:
                      Open M1 with instance 0.
                      Open M2 with same instance in M1 close callback function.
                      Do the same steps for > n times. n - maximum number of instance
                     Issue - Menu will not be opened as l_nb_of_active_instance_S8 is
                      exceeds the maximum number of instance
                     Root cause:  In hmi_menu_logic_create_menu_instance, we are not doing  
           any validation to increment the l_nb_of_active_instance_S8 value. So when we do  
           this operation more than the no. of instance times, l_nb_of_active_instance_S8
           incremented to the maximum value. After that if we open any high priority menu, 
           it will not be opened as l_nb_of_active_instance_S8 exceeds the max no. of
           instances. This is due to failure of destroying the current instance in
           hmi_menu_logic_destroy_menu_instance function(hmi_menu_logic_destroy_menu_instance
           is called in hmi_menu_logic_process_menu_close after the callback).           
 
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  03-Mar-15  
By                :  arajase2
Traceability      :  Issue Fix - C296731: Dynamic menus do not close for ok button press
Change Description:  1. MENU_CB_RESULT_T type changed from UINT8 to UINT16
                     2. hmi_menu_logic_process_menu_action function return type changed
              from UINT8 to MENU_CB_RESULT_T
                     3. Updated HMI_MENU_CB_CLOSE_ANIM_MASK  value to (0x00FF) from Ox7F.
              This macro is to extract the animation id from the menu ID. In the previous
              version, animation exit condition is saved in 8th Bit of the menu id.This
              will not work if the number of animation id is more than 127.
                     4. hmi_menu_rx_button_handler function modified to return the result
              as UINT8 value instead of MENU_CB_RESULT
                     5. hmi_menu_logic_Other_action function modified to pass extracted
              animation id to menu_close
                     6. Clearing 8th bit code is removed from hmi_menu_logic_process_menu_close
              function.

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  18-Mar-15  
By                :  arajase2
Traceability      :  Issue Fix - 307142: CGEA Yukawa MFD:  Left HK not working in media dynamic list
Change Description:  Modified 'hmi_menu_logic_LEFT_action' to clear the 7th bit(clear Gray out item bit),
              after getting the absolute menu index for dynamic configuration.
                     NULL check validation added in hmi_menu_logic_is_FS_Enabled for coverity fix.

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  08-APR-15  
By                :  arajase2
Traceability      :  320855: Review comments for Task 307142
Change Description:  Modified 'hmi_menu_logic_is_FS_Enabled' to fix review comment.

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  23-APR-15  
By                :  arajase2
Traceability      :  312965: UP375: Menu core timer start
Change Description:  Modified 'hmi_menu_logic_button_processing' function to avoid menu
restart when cb result is MENU_BTN_NONE or MENU_BTN_ABSORBED. This will be done based on
HMI_MENU_NOT_RESTART_TIMER_ON_NONE_ABSORBED macro

Expected behavior for the button actions should be something like below:  
 1)  MENU_BTN_PROCESS_MENU   Restart the timer and process the button for the current active menu
 2)  MENU_BTN_NONE           Do not restart the timer (or do not change the timer status) and
 pass the button event to its lower priority screens
 3)  MENU_BTN_ABSORBED       Do not restart the timer (or do not change the timer status) and 
 absorb the button
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  24-APR-15  
By                :  arajase2
Traceability      :  330168: Hyundai AE: Changes for Focus Bar movement defect fix - 
Menu items rearranged in 1st and 2nd depth containing more menu items than display size
Change Description:  Modified 'hmi_menu_logic_Menu_Rebuild' function to avoid the function
call to 'hmi_menu_logic_Focusline_Center' when HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT macro
is enabled. This change is to fix the issue with focus line movement when the menu item is
grey out dynamically. Actual issue is focus line is moved to center due to hmi_menu_logic_Focusline_Center
function call and then it is decremented due to menu grayout.
 -----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  27-APR-15  
By                :  arajase2
Traceability      :  320421: P552 L0: Menu core robustness action for Invalid/missing presentation CB
Change Description:  NULL ptr validation added before calling presentation_cb, cb and is_menu_item_enable_cb
function call
 -----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  19-MAY-15  
By                :  arajase2
Traceability      :  340511: Hyundai AE: Focus line is not updated properly when menu item is hidden dynamically
Change Description:  hmi_menu_logic_Menu_Rebuild function is modified to move the function
call to 'hmi_menu_logic_Focusline_Center' outside of HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT macro.
 -----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  19-MAY-15  
By                :  arajase2
Traceability      :  344163: Hyundai AE:  Menu item history not updated when CAN signal is invalid
Change Description:  hmi_menu_logic_Set_ParentFocus function is modified to store the focus entry when
the incoming menu(p_sub_menu_ptr) is hidden dynamically. In this case existing for loop will be failed to
update the history as fl_menu_def_SP->entry_array does not containg the incoming menu item. 
So by default the focus entry will be pointing to zero. When we enable the hidden items, focus entry
is pointing to this new menu(previously stored value). It contradicts with the previous focus entry.
To fix this default value is updated in the history
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  14-JUL-15  
By                :  arajase2
Traceability      :  371940: UI CORE QAC analysis and Fix- Prepare Deviation List for UI core warnings- MENU CORE
Change Description:  Changes done to fix QAC warnings for Honda THAA.
hmi_menu_logic_FS_check_Btn_vs_Menutype and hmi_menu_logic_Get_EntryType functions are removed as these are
not used from the application. Input parameter for hmi_Menu_initialize is removed.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  14-JUL-15  
By                :  arajase2
Traceability      :  338230: C346 MCA MFd :Please wait shown in channel guide until menu timeout
Change Description:  Changes done to fix issue with please wait animation. Changes done by csakthiv
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  16-JUL-15  
By                :  arajase2
Traceability      :  352612: S101: compiler warnings in menu core
Change Description:  Compiler and some QAC warnings are fixed 
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  19-AUG-15  
By                :  arajase2
Traceability      :  386004: CGEA MFD:Request to menu core to support �HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT� functionality
for the function hmi_menu_logic_Menu_Update() as well to address Vehicle settings menu center aligning unnecessarily
(371654) in CGEA program
                     403713: Honda T6ZA : Menu scroll up animation is not working
Change Description:  386004 - Modified hmi_menu_logic_Menu_Update function to include the code to support
HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT. Code is copied from Rebuild method
                     Compiler error resolved when we disable ITEM_CONFIG_FEATURE and enable CONTENT_MENU
                     403713 -  hmi_menu_logic_decr_till_valid_focus_entry function modified to call hmi_menu_logic_decr_focus_entry
function when HMI_MENU_CORE_FOCUS_DISABLED_FOR_GREYOUT and HMI_MENU_ITEM_CONFIG_FEATURE macros are defined.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  04-SEP-15  
By                :  arajase2
Traceability      :  405689: Changes to be done in Menu core for Fast animation support ,
To abort the current animation if the application send the abort request
Change Description:  Added new macro HMI_MENU_SMOOTH_FAST_ANIMATION to do smooth animation
  when we do fast button processing. If we enable this macro, menu core will wait for
  closing current animation and open the recent screen id. This avoids the activate/deactivate
  the intermediate screen id
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  07-SEP-15  
By                :  arajase2
Traceability      :  Addressed review comments for 386004
Change Description:  412100: Frame expand should be called after doing the check for incre /decr focus entry.
412093: clearing the focus entry in (fl_menu_cntrl_inst_ptr->focus_entry_U16 = 0) HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID
 -----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  11-SEP-15  
By                :  arajase2
Traceability      :  421175 : Focus marker moving to grayed out item in Ford ecomode. 
                     421174 : Focus marker shift upwards when select category in set category.
Issue             :  For dynamic menu, if current menu does not have 'item config callback', then menu_itm_absl_indx
array does not contain valid entries. So when we access the values from this array, it has the previous loaded entries
which results unexpected focus movement
Change Description:  421174: Issue fix with HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT implementation for dynamic menu.
                     hmi_menu_logic_Menu_Rebuild and hmi_menu_logic_Menu_Update function changed to handle dynamic menu
                     421175: hmi_menu_logic_decr_till_valid_focus_entry function modified to assign values for 
                     fl_start_focus_entry_U16 and fl_start_focus_line_U16 before calling hmi_menu_logic_decr_focus_entry
                     function
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  14-SEP-15  
By                :  arajase2
Traceability      :  421175 : Focus marker moving to grayed out item in Ford ecomode. 
                     421174 : Focus marker shift upwards when select category in set category.
Change Description:  Review comment fix. Addressed QAC warnings in Menu core
 -----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  05-OCT-15
By                :  arajase2
Traceability      :  419936: Menu core compiler warnings fix for fast scroll implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  18-Mar-16
By                :  aperumal
Traceability      :  Coverity warning fix for Honda Thaa 549240
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  21-Mar-16
By                :  aperumal
Traceability      :  Coverity warning fix for Honda Thaa 11858
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  17-Oct-16
By                :  aperumal
Traceability      :  Introduced API hmi_menu_logic_get_active_menu_instance_ptr
                     to get the active menu instance - B515 
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  19-Dec-16
By                :  adevi
Traceability      :  768330:Left/right button press when animation is runnning is handled by staing
                     in wait state itself - B515 
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  18-Jan-17
By                :  aperumal
Traceability      :  785145: For Content Menu, Remove and add the screen only if the number of 
                     display lines is 1                     
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  27-Jan-17
By                :  VGAJJI
Traceability      :  QAC Warnings Fix - B515, RTC ID : 767356
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  10-May-17
By                :  arajase2
Traceability      :  863415: CMFB MISRA Warning fixes - menu.core
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  07-Jun-17
By                :  arajase2
Traceability      :  882810: CMFB MISRA Warning fixes - Menu Configurator Auto Code Generation
Changes:

In MENU_DEF_T structure MENU_ITEM_ENTRY_T *entry_array; member is changed as
union {
MENU_ITEM_ENTRY_T const *static_array;
MENU_ITEM_ENTRY_T *dynamic_array;
}item_entry_array;
#define entry_array item_entry_array.static_array

By default entry_array will points to static entry array. Application will get compilation errors
to update dynamic menu entries. In this case, application code needs to be changed to use 
item_entry_array.dynamic_array

MENU_DYNAMIC_ENTRY_ARRAY_MAP_T structure member   MENU_ITEM_ENTRY_T *entry_array; is 
renamed as dynamic_entry_array to avoid conflicts with the entry_array macro

-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  09-Jun-17
By                :  arajase2
Traceability      :  884988: Macro entry_array is not required as this will replace 
all the words in "entry_array"  with the expr
Changes:
#define entry_array item_entry_array.static_array removed from types.h and
corresponding changes done in hmi_menu_core_01_logic.c file
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  19-Jun-17
By                :  arajase2
Traceability      :  891824: Release version update in iceapple tools and components
Changes: Change the core major and minor version as 4 and 30 respectively
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  18-Jul-17
By                :  arajase2
Traceability      :  905460: CMFB Coverity warning fix
Changes: New macro LSH_ANIM_MASK_CLEAR created to fix coverity warning when we use ~ operator
ie. ~(LSH_ANIM_MASK) is replaced with its mask LSH_ANIM_MASK_CLEAR
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  02-Nov-17
By                :  kkubendi
Traceability      :  985437: Menu Core closing the current instance during menu timer 
time out condition. 
Changes: Updated function hmi_menu_logic_open_timer_timeout() to handle 
newly introduced macro HMI_MENU_OPEN_PARENT_ON_TIMEOUT.
	
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  09-11-17
By                :  adevi
Traceability      :  990906: MENU_CB_ACTION_EXIT UI Core changes
Changes: When animation is enabled MENU_CB_ACTION_EXIT is handled by closing menu with ANIM_MX_ID
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  21-08-18
By                :  arajase2
Traceability      :  1180146: MKRA-312505-Menu_Core- menu_level_U8 is not giving menu level
                    from root menu
Changes           :  Usage of hmi_menu_logic_load_menu_level function is replaced with
hmi_menu_logic_get_Menu_level function hmi_menu_logic_load_menu_level will update menu level to 2
if it is greater than 2. Now menu level is updated with the actual value
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  21-08-18
By                :  arajase2
Traceability      :  1175162: 313114:Honda MKRA Menu Core needs interface to Jump from
Destination Level to Source Level
Changes           :  New function macro HMI_MENU_GET_MENU_LEVEL_TO_MOVE introduced to get the
menu level to move for LEFT_LONG action and this is used in hmi_menu_left_action function.
If the macro is not defined then root menu will be opened for this menu action
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
