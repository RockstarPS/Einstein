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
File Name        :  hmi_menu_interface.c
Module Short Name:  MENU
VOBName          :  
Author           :  kcsarava
Description      :  HMI Menu Core Source

Organization     :  HMI Sub System,
                    Visteon Corporation
**============================================================================
**
**==========================================================================*/
#define HMI_MENU_CORE_LITE_01_LOGIC_C

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#include "system.h"
#include "hmi_menu_core_lite_01_logic.h"
#ifdef HMI_MENU_CORE_UINT_TEST_ENABLE
#include <stdio.h>
#include <conio.h>
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define MENU_INVALID_ENTRY           (0xFFFF)
#define MENU_INDEX_INVALID             (0xFF)
#define MENU_BTN_INVALID             (0xFFFF)
#define HMI_MENU_LEVEL_0               (0x00)
#define HMI_MENU_LEVEL_1               (0x01)
#define HMI_MENU_LEVEL_2               (0x02)
#define FNULL                            NULL
#define MENU_STATE_NORMAL                   0

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/* It is master table for menu which is defined in hmi_menu_cfg.h file*/
/* Points to the current Menu which is align with the LSH focus*/
static MENU_CONTROL_T *Current_focus_menu_ptr;
/* Array having the Menu Instances */
static MENU_CONTROL_T  l_menu_instance_array[NB_OF_MENU_INSTANCE];
/* Holds the Number of Instance value currently */
static UINT8           l_nb_of_active_instance_U8;

/******************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/
static void hmi_menu_logic_create_menu(MENU_LIST_ID_T p_menu_id_e, UINT8 p_menu_inst_val_U8);
static void hmi_menu_logic_View_Mngr_Rq(UINT8 p_menu_id_U8, MENU_CB_RESULT_T p_CB_result_e);
MENU_CB_RESULT_T hmi_menu_logic_button_processing(MENU_CONTROL_T *fl_current_active_menu_SP,UINT16 p_button_command_U16);
static void hmi_menu_logic_process_menu_action(MENU_LIST_ID_T p_menu_id_U8, UINT8 p_menu_action_U8);
static MENU_CB_RESULT_T hmi_menu_logic_SubMenu_Open(const MENU_DEF_T *p_open_submenu_ptr, UINT8 p_menu_inst_U8, MENU_ACTION_T p_menu_action_e);
static MENU_CONTROL_T  *hmi_menu_logic_get_valid_menu_instance(LSH_STATE_ID_T p_logic_state_id_U8);
static void hmi_menu_logic_Set_ParentFocus(MENU_CONTROL_T *p_menu_cntrl_ptr, const MENU_DEF_T *p_sub_menu_ptr);
static void hmi_menu_logic_Focusline_Center(MENU_CONTROL_T *p_menu_cntrl_SP);
static UINT8 hmi_menu_logic_get_Menu_level(MENU_LIST_ID_T p_menu_ID_e);
static MENU_LIST_ID_T hmi_menu_logic_get_menu_index(const MENU_DEF_T *fl_menu_ID_ptr);
static void hmi_menu_logic_load_menu_level(MENU_CONTROL_T *p_menu_cntrl_ptr);
static MENU_CB_RESULT_T hmi_menu_logic_left_menu_action(MENU_CONTROL_T *p_menu_cntrl_ptr, UINT8 p_menu_action_U8);
static void hmi_menu_logic_start_timer(UINT8 fl_menu_id_U8);
static void hmi_menu_logic_stop_timer(UINT8 fl_menu_id_U8);
static UINT8 hmi_menu_logic_get_menu_timeout_value(UINT8 p_menu_id_U8);


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/*============================================================================
** Function Name:    hmi_menu_core_initialize
** Visibility:       Menu core
** Description:      This is the initialization function for the Menu Core and 
**                   used to initialize all status variable maintained by it
** Invocation:       Invoked by application.
** Inputs/Outputs:   void
** Critical Section: None.
**==========================================================================*/
void hmi_menu_initialize(void)
{
   UINT8 i;
   Current_focus_menu_ptr     = FNULL;
   l_nb_of_active_instance_U8 = 0;

   for(i=0; i<NB_OF_MENU_INSTANCE ; i++)
   {
     l_menu_instance_array[i].inst_status_U8 = HMI_MENU_LOGIC_INST_INACTIVE;
   }
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
******************************************************************************/
void hmi_menu_logic_Menu_Open(MENU_LIST_ID_T p_open_menu_id_e)
{
   MENU_CB_RESULT_T     fl_cb_result_e;
   UINT8                fl_find_menu_inst_val_U8;
   UINT8                fl_get_logic_st_id_U8;

   fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
   fl_find_menu_inst_val_U8 = 0;

   /* Array Access Boundary check */
   if(p_open_menu_id_e < HMI_MENU_ID_COUNT)
   {
     if(FALSE == hmi_menu_logic_MenuIsOpen(p_open_menu_id_e))
     {
       if(l_nb_of_active_instance_U8 >= NB_OF_MENU_INSTANCE)
       {
         /* Maximum Instance Reached Do Nothing */
       }
       else
       {
         fl_find_menu_inst_val_U8 = hmi_menu_logic_get_available_menu_instance();
         
         if(fl_find_menu_inst_val_U8 < NB_OF_MENU_INSTANCE)
		 {
	         l_nb_of_active_instance_U8++;
	           
	         /* Freeze the button actions of Current Focus Menu and check whether it is not zeroth instance */
	         if((Current_focus_menu_ptr != FNULL) && (l_nb_of_active_instance_U8 != 0))
	         {
	           fl_get_logic_st_id_U8 = hmi_menu_const_struct_array_table[Current_focus_menu_ptr->menu_id].disp_screen_id;
	           hmi_lsh_freeze_button_events(fl_get_logic_st_id_U8);
	         }
	         hmi_menu_logic_stop_timer(p_open_menu_id_e);
	         hmi_menu_logic_create_menu(p_open_menu_id_e, fl_find_menu_inst_val_U8);
	        
	         Current_focus_menu_ptr = &l_menu_instance_array[fl_find_menu_inst_val_U8];
	         
	         if (hmi_menu_const_struct_array_table[Current_focus_menu_ptr->menu_id].cb != FNULL)
	         {
	           fl_cb_result_e = hmi_menu_const_struct_array_table[Current_focus_menu_ptr->menu_id].cb(MENU_ACTION_OPEN, Current_focus_menu_ptr, MENU_BTN_INVALID);
	         }
	         hmi_menu_logic_load_menu_level(Current_focus_menu_ptr);
	         hmi_menu_logic_View_Mngr_Rq((UINT8)p_open_menu_id_e, fl_cb_result_e);
		 }
       }
     }
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
**==========================================================================*/
void hmi_menu_logic_Menu_Close(MENU_LIST_ID_T p_close_menu_id_e)
{
   UINT8                  fl_logic_st_id_U8;
   MENU_CONTROL_T        *fl_menu_close_ptr;
   MENU_CB_RESULT_T       fl_cb_close_rst_e;
   MENU_DEF_T  const     *fl_menu_def_SP;
   
   fl_cb_close_rst_e = MENU_CB_ACTION_COMPLETED;
   
   /* Array Access Boundary check */
   if(p_close_menu_id_e < HMI_MENU_ID_COUNT)
   {
      /* Find the Menu instance to be closed */
      fl_menu_close_ptr   = hmi_menu_logic_get_menu_instance(p_close_menu_id_e);
      /* check the close condition */
      if(fl_menu_close_ptr != FNULL)
      {
         fl_menu_def_SP      = &hmi_menu_const_struct_array_table[fl_menu_close_ptr->menu_id];
        
         if(fl_menu_def_SP->cb != FNULL)
         {
           fl_cb_close_rst_e = fl_menu_def_SP->cb(MENU_ACTION_FORCED_CLOSE, fl_menu_close_ptr, MENU_BTN_INVALID);
         }
         if(l_nb_of_active_instance_U8 != 0)
         {
            l_nb_of_active_instance_U8--;
         }
        
         if(MENU_CB_ACTION_COMPLETED == fl_cb_close_rst_e)
         {
           fl_logic_st_id_U8 = fl_menu_def_SP->disp_screen_id;
           (void)LSH_REM_STATE(fl_logic_st_id_U8, 0);
         }
      }
   }
}

/*============================================================================
** Function Name:    hmi_menu_logic_Close_all_Menu
** Visibility:       global
** Description:      This function adds the state to the View Manager
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   void
** Critical Section: None.
**==========================================================================*/
void hmi_menu_logic_Close_all_Menu(void)
{
  UINT8 i;
  for(i = 0; i< NB_OF_MENU_INSTANCE; i++)
  {
     if(l_menu_instance_array[i].inst_status_U8 == HMI_MENU_LOGIC_INST_ACTIVE)
     {
        hmi_menu_logic_Menu_Close((MENU_LIST_ID_T)l_menu_instance_array[i].menu_id);
     }
  }
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
**==========================================================================*/
static void hmi_menu_logic_create_menu(MENU_LIST_ID_T p_menu_id_e, UINT8 p_menu_inst_val_U8)
{
  MENU_CONTROL_T *fl_load_menu_ptr;
  fl_load_menu_ptr = &l_menu_instance_array[p_menu_inst_val_U8];

  fl_load_menu_ptr->menu_id            = p_menu_id_e;
  fl_load_menu_ptr->inst_status_U8     = HMI_MENU_LOGIC_INST_ACTIVE;
  fl_load_menu_ptr->focus_entry_U16    = 0;
  fl_load_menu_ptr->focus_line_U16     = 0;
  fl_load_menu_ptr->menu_instance_no   = p_menu_inst_val_U8;
  fl_load_menu_ptr->displayed_lines    = hmi_menu_const_struct_array_table[p_menu_id_e].total_display_lines;
  fl_load_menu_ptr->menu_entry_nbr     = hmi_menu_const_struct_array_table[p_menu_id_e].total_entry_nbr;
  fl_load_menu_ptr->menu_properties    = hmi_menu_const_struct_array_table[p_menu_id_e].properties;
  fl_load_menu_ptr->menu_state         = MENU_STATE_NORMAL;
  fl_load_menu_ptr->selected_entry_U16 = MENU_INVALID_ENTRY;
}

/*============================================================================
** Function Name:    hmi_menu_logic_MenuIsOpen
** Visibility:       global
** Description:      This function Checks whether the Requested Menu is open or not
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
**==========================================================================*/
BOOLEAN_T hmi_menu_logic_MenuIsOpen(MENU_LIST_ID_T p_menu_id_U8)
{
  BOOLEAN_T         fl_status_BOOL = FALSE;
  
  if(FNULL != hmi_menu_logic_get_menu_instance(p_menu_id_U8))
  {
    fl_status_BOOL = TRUE;
  }
  return(fl_status_BOOL);
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_available_menu_instance
** Visibility:       global
** Description:      This interface return instance number of available menu 
**                   instance.
** Invocation:       Menu core logic
** Inputs:           None
** Outputs:          Available menu instance.
** Critical Section: None.
**==========================================================================*/
UINT8 hmi_menu_logic_get_available_menu_instance(void)
{
   UINT8 i;
   UINT8 fl_availble_inst_U8 = 0xFF;
   
   for(i=0;i<NB_OF_MENU_INSTANCE;i++)
   {
      if(l_menu_instance_array[i].inst_status_U8 == HMI_MENU_LOGIC_INST_INACTIVE)
      {
       fl_availble_inst_U8 = i;
       break;
      } 
   }
   return fl_availble_inst_U8; 
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
**==========================================================================*/
MENU_CONTROL_T  *hmi_menu_logic_get_menu_instance(MENU_LIST_ID_T p_menu_id_U8)
{
  UINT8 i;
  MENU_CONTROL_T *fl_menu_inst_ID_ptr;
  
  fl_menu_inst_ID_ptr = FNULL;
  
  for(i = 0; i < NB_OF_MENU_INSTANCE; i++)
  {
    if(l_menu_instance_array[i].inst_status_U8 == HMI_MENU_LOGIC_INST_ACTIVE)
    {
      if(l_menu_instance_array[i].menu_id == p_menu_id_U8)
      {
         fl_menu_inst_ID_ptr = &l_menu_instance_array[i];
         break;
      }
    }
  }
  return(fl_menu_inst_ID_ptr);
}

/*============================================================================
** Function Name:    hmi_menu_logic_View_Mngr_Rq
** Visibility:       global
** Description:      This function adds the state to the View Manager
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   p_menu_id_U8, p_CB_result_e
** Critical Section: None.
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
static void hmi_menu_logic_View_Mngr_Rq(UINT8 p_menu_id_U8, MENU_CB_RESULT_T p_CB_result_e)
{
  LSH_STATE_ID_T      fl_logic_st_id_U8;
  
  if((p_CB_result_e != MENU_CB_ACTION_EXIT) && (p_CB_result_e != MENU_CB_ACTION_NONE))
  {
    fl_logic_st_id_U8 = hmi_menu_const_struct_array_table[p_menu_id_U8].disp_screen_id;
    (void)LSH_ADD_STATE(fl_logic_st_id_U8, 0);
  }
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
**==========================================================================*/
UINT8 hmi_menu_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
   MENU_CB_RESULT_T      fl_cb_result_e;
   MENU_CONTROL_T        *fl_current_active_menu_SP;
   
   fl_cb_result_e        = MENU_BTN_NONE;
   
      /* needs to change */
   fl_current_active_menu_SP = hmi_menu_logic_get_valid_menu_instance(p_event_hndl_status_SP->logic_state_id);
   
   if(fl_current_active_menu_SP != FNULL)
   {
      fl_cb_result_e = hmi_menu_logic_button_processing(fl_current_active_menu_SP, p_event_hndl_status_SP->button_command);
   }
   return(fl_cb_result_e);
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
**==========================================================================*/
void hmi_menu_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
   MENU_CONTROL_T *fl_pre_menu_ptr;
   
   /* Points the Appropriate Menu instance w.r.t Menu ID*/
   fl_pre_menu_ptr = hmi_menu_logic_get_valid_menu_instance(p_presen_hndl_status_SP->logic_state_id);
   
   if((fl_pre_menu_ptr != FNULL) && \
      (hmi_menu_const_struct_array_table[fl_pre_menu_ptr->menu_id].presentation_cb != FNULL))
   {
      hmi_menu_const_struct_array_table[fl_pre_menu_ptr->menu_id].presentation_cb(fl_pre_menu_ptr, p_presen_hndl_status_SP->presentation_status);
   }
   
   if(LSH_ACTIVATED_STATUS == p_presen_hndl_status_SP->presentation_status)
   {
   }
   else if(LSH_DEACTIVATED_STATUS == p_presen_hndl_status_SP->presentation_status)
   {
      if(fl_pre_menu_ptr != FNULL)
	  {
        fl_pre_menu_ptr->inst_status_U8 = HMI_MENU_LOGIC_INST_INACTIVE;
        /* Since instance array has been written with FNULL for the closed menu, we shall diretly
        ** assign the value as FNULL */
        fl_pre_menu_ptr = FNULL;
	  }
   }
   else
   {
      /* Do Nothing */
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
**==========================================================================*/
void hmi_menu_set_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
   MENU_CONTROL_T   * fl_focus_menu_cntrl_SP;
   MENU_DEF_T const * fl_menu_def_SP;
   
   fl_focus_menu_cntrl_SP = hmi_menu_logic_get_valid_menu_instance(p_focus_hndl_status_SP->logic_state_id);
   if(fl_focus_menu_cntrl_SP != FNULL)
   {
      fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_focus_menu_cntrl_SP->menu_id];
      if(LSH_GOT_FOCUS_STATUS == (p_focus_hndl_status_SP->focus_status & LSH_GOT_FOCUS_STATUS))
      {
        if(fl_menu_def_SP->cb != FNULL)
        {
          fl_menu_def_SP->cb(MENU_ACTION_GOT_FOCUS, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
        }
        /*Current_focus_menu_ptr will be controlled by set_focus interface and l_nb_of_instance will be
        controlled by menu_open and menu_close*/
        Current_focus_menu_ptr = fl_focus_menu_cntrl_SP;
        hmi_menu_logic_start_timer(fl_focus_menu_cntrl_SP->menu_id);
      }
      else if(LSH_LOST_FOCUS_STATUS == (p_focus_hndl_status_SP->focus_status & LSH_LOST_FOCUS_STATUS))
      {
         if(fl_menu_def_SP->cb != FNULL)
         {
           fl_menu_def_SP->cb(MENU_ACTION_LOST_FOCUS, fl_focus_menu_cntrl_SP, MENU_BTN_INVALID);
         }
         hmi_menu_logic_stop_timer(fl_focus_menu_cntrl_SP->menu_id);
      }
      else
      {
      }
      if(LSH_DEACTIVATED_STATUS == (p_focus_hndl_status_SP->focus_status & LSH_DEACTIVATED_STATUS))
      {
         hmi_menu_logic_stop_timer(fl_focus_menu_cntrl_SP->menu_id);
         hmi_menu_logic_Menu_Close((MENU_LIST_ID_T)fl_focus_menu_cntrl_SP->menu_id);
      }
   }
   else
   {
      if(l_nb_of_active_instance_U8 == 0)
      {
         Current_focus_menu_ptr = FNULL;
      }
   }
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
**==========================================================================*/
MENU_CB_RESULT_T hmi_menu_logic_button_processing(MENU_CONTROL_T *fl_current_active_menu_SP,UINT16 p_button_command_U16)
{
  MENU_CB_RESULT_T                 fl_cb_result_e;
  UINT8                            fl_menu_btn_action_U8;
  UINT8                            i;
  UINT8                            fl_table_index;
  UINT8                            fl_total_btn_acns_mapped;
  MENU_BTN_TO_ACTIONS_MAP_T const *fl_btn_action_map_SP;
  
  fl_cb_result_e        = MENU_BTN_PROCESS_MENU;
  fl_menu_btn_action_U8 = MENU_BTN_NONE;
  
  if(fl_current_active_menu_SP != FNULL)
  {
    /* Button Callback called to either process the button by Menu or not*/
    if(hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].cb != FNULL)
    {
      fl_cb_result_e = hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].cb(MENU_ACTION_VALIDATE_BUTTON, fl_current_active_menu_SP, p_button_command_U16);
    }
    if((fl_cb_result_e == MENU_BTN_PROCESS_MENU) || (fl_cb_result_e == MENU_BTN_CASCADED))
    {
       /* Map the Button Actions to Menu Actions w.r.to menu mapped table */
       fl_table_index = hmi_menu_const_struct_array_table[fl_current_active_menu_SP->menu_id].table_index;
       if(fl_table_index < HMI_MENU_TABLE_COUNT)
       {
         fl_btn_action_map_SP = hmi_menu_map_actions_table_ptr[fl_table_index].hmi_menu_map_actions_table;
         fl_total_btn_acns_mapped = hmi_menu_map_actions_table_ptr[fl_table_index].hmi_menu_total_btn_acns_mapped;
         
         for(i=0; i < fl_total_btn_acns_mapped; i++)
         {
            if(fl_btn_action_map_SP[i].button_action == p_button_command_U16)
            {
               fl_menu_btn_action_U8 = fl_btn_action_map_SP[i].menu_action;
               if(fl_menu_btn_action_U8 != MENU_ACTION_NONE)
               {
                 hmi_menu_logic_process_menu_action((MENU_LIST_ID_T)fl_current_active_menu_SP->menu_id, fl_menu_btn_action_U8);
                 hmi_menu_logic_start_timer(fl_current_active_menu_SP->menu_id);
                 fl_cb_result_e = MENU_BTN_ABSORBED;
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
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    fl_cb_result_e = MENU_BTN_NONE;
  }
  return(fl_cb_result_e);
}

/*============================================================================
** Function Name:    hmi_menu_logic_process_menu_action
** Visibility:       global
** Description:      This function routes to the respective Menu Button function
**                   handlers to process the button.
** Invocation:       Invoked by hmi_chart.c
** Inputs/Outputs:   p_menu_action_U8
** Critical Section: None.
**==========================================================================*/
static void hmi_menu_logic_process_menu_action(MENU_LIST_ID_T p_menu_id_U8, UINT8 p_menu_action_U8)
{
	BOOLEAN_T               fl_valid_BOOL;       /* used to avoid two return paths */
	BOOLEAN_T               fl_focus_entry_is_zero;
	UINT16                  fl_inc_dec_focus_entry_U16;
	UINT16                  fl_inc_dec_focus_line_U16;
	UINT16                  fl_entry_array_idx_U16;
	UINT16                  fl_menu_entry_nbr_U16;
	UINT16                  fl_menu_properties_u16;
	UINT8                   fl_item_entry_type_U8;
	UINT8                   fl_displayed_lines_U8;
	UINT8                   fl_menu_state_U8;
	UINT16                  fl_item_properties_U16;
	MENU_CB_RESULT_T        fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
	MENU_DEF_T  const      *fl_menu_def_SP;
	MENU_CONTROL_T         *fl_menu_cntrl_SP;
	const MENU_DEF_T       *fl_sub_menu_def_ptr;

	fl_valid_BOOL          = TRUE;
	fl_focus_entry_is_zero = FALSE;
	fl_sub_menu_def_ptr    = FNULL;

	fl_menu_cntrl_SP = hmi_menu_logic_get_menu_instance(p_menu_id_U8);
	if(fl_menu_cntrl_SP != FNULL)
	{
		fl_menu_def_SP = &hmi_menu_const_struct_array_table[fl_menu_cntrl_SP->menu_id];

		fl_menu_properties_u16 = fl_menu_cntrl_SP->menu_properties;
		fl_menu_entry_nbr_U16 = fl_menu_cntrl_SP->menu_entry_nbr;
		fl_displayed_lines_U8 = fl_menu_cntrl_SP->displayed_lines;
		fl_menu_state_U8 = fl_menu_cntrl_SP->menu_state;
		fl_inc_dec_focus_entry_U16 = 0;
		fl_inc_dec_focus_line_U16 = 0;

		switch (p_menu_action_U8)
		{
		case MENU_ACTION_UP:
		case MENU_ACTION_DOWN:
			{
				if((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) != 0)
				{
					if((fl_menu_def_SP->cb != FNULL) && (fl_menu_state_U8 == MENU_STATE_NORMAL))
					{
						UINT8 fl_menu_cb_value;
						if(p_menu_action_U8 == MENU_ACTION_UP)
						{
							fl_menu_cb_value = MENU_ACTION_DECREMENT;
						}
						else            /* MENU_ACTION_DOWN */
						{
							fl_menu_cb_value = MENU_ACTION_INCREMENT;
						}
						fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)fl_menu_cb_value, fl_menu_cntrl_SP, MENU_BTN_INVALID);
					}
				}
				else
				{
					if(fl_menu_state_U8 == MENU_STATE_NORMAL)
					{
						fl_inc_dec_focus_entry_U16 = 1;
						fl_inc_dec_focus_line_U16  = HMI_MENU_LINE_INCREMENT;
					}

					if(((fl_menu_cntrl_SP->focus_entry_U16 == 0) && ((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND) == 0) && \
						(p_menu_action_U8 == MENU_ACTION_UP)) || \
						(((fl_menu_cntrl_SP->focus_entry_U16 + fl_inc_dec_focus_entry_U16) >= fl_menu_entry_nbr_U16 ) && \
						((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND) == 0) && (p_menu_action_U8 == MENU_ACTION_DOWN)))
					{
						fl_valid_BOOL = FALSE;
					}
					else
					{
						if(p_menu_action_U8 == MENU_ACTION_UP)
						{
							if (fl_menu_cntrl_SP->focus_line_U16 == 0)  /* check if both focus_line and focus_entry are 0 */
							{
								fl_menu_cntrl_SP->focus_line_U16   = 0;
								if(fl_menu_cntrl_SP->focus_entry_U16 == 0)
								{  /* This flag is used to avoid the value being decremented from item 1 and 0
									which is further processed below */
									fl_focus_entry_is_zero = TRUE;
								}
								else
								{
									fl_menu_cntrl_SP->focus_entry_U16 -= fl_inc_dec_focus_entry_U16;
								}

								if((fl_menu_cntrl_SP->focus_entry_U16 == 0) && (fl_focus_entry_is_zero == TRUE))
								{
									fl_menu_cntrl_SP->focus_entry_U16 = (fl_menu_entry_nbr_U16 - fl_inc_dec_focus_entry_U16);
									if ((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND) != 0)
									{
										fl_menu_cntrl_SP->focus_line_U16 = (MIN_VALUE(fl_menu_entry_nbr_U16,fl_displayed_lines_U8) - 1);
									}
								}

							}
							else
							{  /* Set focus on previous line */
								fl_menu_cntrl_SP->focus_line_U16 -= fl_inc_dec_focus_line_U16;
								fl_menu_cntrl_SP->focus_entry_U16 -= fl_inc_dec_focus_entry_U16;
							}
						}
						else            /* MENU_ACTION_DOWN */
						{
							if((fl_menu_cntrl_SP->focus_line_U16 + fl_inc_dec_focus_line_U16) >= MIN_VALUE(fl_menu_entry_nbr_U16, fl_displayed_lines_U8))
							{
								fl_menu_cntrl_SP->focus_entry_U16 += fl_inc_dec_focus_entry_U16;
								if (fl_menu_cntrl_SP->focus_entry_U16 >= fl_menu_entry_nbr_U16)
								{
									fl_menu_cntrl_SP->focus_entry_U16 = fl_menu_cntrl_SP->focus_entry_U16 - fl_menu_entry_nbr_U16;

									if((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND) != 0)
									{
										fl_menu_cntrl_SP->focus_line_U16 = 0;
									}
								}
							}
							else
							{
								fl_menu_cntrl_SP->focus_line_U16 += fl_inc_dec_focus_line_U16;  /* Set focus on next line */
								if (fl_menu_cntrl_SP->focus_line_U16 >= fl_displayed_lines_U8)
								{
									fl_menu_cntrl_SP->focus_line_U16 = fl_displayed_lines_U8 - HMI_MENU_LINE_INCREMENT;
								}
								fl_menu_cntrl_SP->focus_entry_U16 += fl_inc_dec_focus_entry_U16;
								if (fl_menu_cntrl_SP->focus_entry_U16 >= fl_menu_entry_nbr_U16)
								{
									fl_menu_cntrl_SP->focus_entry_U16 = fl_menu_entry_nbr_U16 - 1;
								}
							}
						}
						if (fl_menu_def_SP->cb != FNULL)
						{
							fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, fl_menu_cntrl_SP, MENU_BTN_INVALID);
						}
					}
				}
			}
			break;

		case MENU_ACTION_LEFT:
		case MENU_ACTION_LEFT_LONG:
			{
				if(fl_menu_cntrl_SP != FNULL)
				{
					if((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) != 0)
					{
						fl_entry_array_idx_U16 = 0;
					}
					else
					{
						fl_entry_array_idx_U16 = fl_menu_cntrl_SP->focus_entry_U16;
					}

					fl_item_entry_type_U8 = fl_menu_def_SP->entry_array[fl_entry_array_idx_U16].item_entry_type;

					if(fl_item_entry_type_U8 == MENU_ITEM_ENTRY_TYPE_BARGRAPH)
					{
						if((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) != 0)
						{
							if((fl_menu_cntrl_SP->focus_line_U16 == 0) && \
								((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND) != 0))
							{
								fl_menu_cntrl_SP->focus_line_U16 = fl_menu_entry_nbr_U16;
							}
							else
							{
								fl_menu_cntrl_SP->focus_line_U16--;
							}
						}
						if((fl_menu_def_SP->cb != FNULL) && \
							((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) == 0))
						{
							if(fl_menu_state_U8 == MENU_STATE_NORMAL)
							{
								(void)fl_menu_def_SP->cb(MENU_ACTION_DECREMENT, fl_menu_cntrl_SP, MENU_BTN_INVALID);
							}
						}
					}
					else
					{
						fl_cb_result_e = hmi_menu_logic_left_menu_action(fl_menu_cntrl_SP, p_menu_action_U8);
					}
				}
			}
			break;

		case MENU_ACTION_RIGHT:
		case MENU_ACTION_OK_IN:
			{
				if(fl_menu_cntrl_SP != FNULL)
				{
					/* Its not applicable for MENU_ACTION_OK_IN */
					if(((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) != 0) && \
						(p_menu_action_U8 == MENU_ACTION_RIGHT))
					{
						fl_entry_array_idx_U16 = 0;
					}
					else
					{
						fl_entry_array_idx_U16 = fl_menu_cntrl_SP->focus_entry_U16;
					}

					fl_item_properties_U16 = fl_menu_def_SP->entry_array[fl_entry_array_idx_U16].item_properties;
					fl_item_entry_type_U8 = fl_menu_def_SP->entry_array[fl_entry_array_idx_U16].item_entry_type;
					switch (fl_item_entry_type_U8)
					{
					case MENU_ITEM_ENTRY_TYPE_MENU:
						{
							fl_sub_menu_def_ptr = fl_menu_def_SP->entry_array[fl_entry_array_idx_U16].utype.sub_menu;

							if (fl_menu_def_SP->cb != FNULL)  /* Call callback */
							{
								/* p_menu_action_U8 shall be either MENU_ACTION_RIGHT / MENU_ACTION_OK_IN */
								fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, fl_menu_cntrl_SP, MENU_BTN_INVALID);
							}

							if (fl_sub_menu_def_ptr != FNULL)  /* Sub menu */
							{
								fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_sub_menu_def_ptr, fl_menu_cntrl_SP->menu_instance_no, MENU_ACTION_OPEN_FROM_PARENT);
							}
						}
						break;

					case MENU_ITEM_ENTRY_TYPE_BARGRAPH:
						{
							if(p_menu_action_U8 == MENU_ACTION_OK_IN)
							{
								if (fl_menu_def_SP->cb != FNULL)
								{
									fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, fl_menu_cntrl_SP, MENU_BTN_INVALID);
								}
								if (fl_cb_result_e != MENU_CB_ACTION_EXIT)
								{
									fl_cb_result_e = MENU_CB_ACTION_EXIT;   /* Root menu => Nothing to do */
								}
							}
							else    /* inserted for clock */
							{
								if((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) != 0)
								{
									if(fl_menu_cntrl_SP->focus_line_U16 < fl_menu_entry_nbr_U16)
									{
										if((fl_menu_cntrl_SP->focus_line_U16 == (fl_menu_entry_nbr_U16 - 1)) && \
											((fl_menu_properties_u16 & MENU_PRO_FOCUS_WRAPAROUND)!= 0))
										{
											fl_menu_cntrl_SP->focus_line_U16 = 0;
										}
										else
										{
											fl_menu_cntrl_SP->focus_line_U16++;
										}
									}
								}
								if((fl_menu_def_SP->cb != FNULL) && \
									((fl_menu_properties_u16 & MENU_PRO_CLOCK_FORMAT) == 0))
								{
									if(fl_menu_state_U8 == MENU_STATE_NORMAL)
									{
										(void)fl_menu_def_SP->cb(MENU_ACTION_INCREMENT, fl_menu_cntrl_SP, MENU_BTN_INVALID);
									}
								}
							}
						}
						break;

					case MENU_ITEM_ENTRY_TYPE_LABEL:
						{
							if(p_menu_action_U8 == MENU_ACTION_OK_IN)    /* Not applicable for MENU_ACTION_RIGHT */
							{
								if (fl_menu_def_SP->cb != FNULL)    /* Call callback */
								{
									fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, fl_menu_cntrl_SP, MENU_BTN_INVALID);
								}
								/* for item entry property BACK, open parent menu */
								if((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_BACK) != 0)
								{
									fl_cb_result_e = hmi_menu_logic_left_menu_action(fl_menu_cntrl_SP, MENU_ACTION_LEFT);
								}
								else if((fl_item_properties_U16 & MENU_ITEM_PRO_ACTION_EXIT) != 0)
								{
									fl_cb_result_e = MENU_CB_ACTION_EXIT;
								}
								else
								{
								}
							}
						}
						break;

					default:
						break;
					}
				}
			}
			break;

		case MENU_ACTION_CLOSE:
			{
				if((fl_menu_cntrl_SP != FNULL) && (fl_menu_def_SP->cb != FNULL))
				{
					fl_cb_result_e = fl_menu_def_SP->cb((MENU_ACTION_T)p_menu_action_U8, fl_menu_cntrl_SP, MENU_BTN_INVALID);
				}
			}
			break;

		default:
			break;
		}

		if(FALSE != fl_valid_BOOL)
		{
			if(MENU_CB_ACTION_EXIT == fl_cb_result_e)
			{
				hmi_menu_logic_Menu_Close((MENU_LIST_ID_T)fl_menu_cntrl_SP->menu_id);
			}
			else
			{
				hmi_menu_logic_View_Mngr_Rq(fl_menu_cntrl_SP->menu_id , fl_cb_result_e);
			}
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
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_SubMenu_Open(const MENU_DEF_T *p_open_submenu_ptr, UINT8 p_menu_inst_U8, MENU_ACTION_T p_menu_action_e)
{
  MENU_CB_RESULT_T        fl_cb_result_e;
  MENU_CONTROL_T         *fl_cur_menu_ptr;
  MENU_LIST_ID_T          fl_get_menu_index_e;
  UINT8                   fl_menu_instance_no_U8;

  fl_cur_menu_ptr        = FNULL;
  fl_cb_result_e         = MENU_CB_ACTION_COMPLETED;
  fl_menu_instance_no_U8 = p_menu_inst_U8;
  fl_get_menu_index_e    = hmi_menu_logic_get_menu_index(p_open_submenu_ptr);

  if(MENU_INDEX_INVALID != fl_get_menu_index_e)
  {
    fl_cur_menu_ptr        = &l_menu_instance_array[fl_menu_instance_no_U8];
    
    /* Always submenu will be opened in the same menu instance 
    and the parent menu and submenu screens should have the same priority*/
    hmi_menu_logic_create_menu(fl_get_menu_index_e, fl_menu_instance_no_U8);
    
    if(p_menu_action_e != MENU_ACTION_OPEN_FROM_CHILD)
    {
      hmi_menu_logic_load_menu_level(fl_cur_menu_ptr);
    }
    if(hmi_menu_const_struct_array_table[fl_cur_menu_ptr->menu_id].cb != FNULL)
    {
      /* menu id logic call back */
      fl_cb_result_e = hmi_menu_const_struct_array_table[fl_cur_menu_ptr->menu_id].cb(p_menu_action_e, fl_cur_menu_ptr, MENU_BTN_INVALID);
    }
  }
  return(fl_cb_result_e);
}

/*============================================================================
** Function Name:    hmi_menu_logic_get_valid_menu_instance
** Visibility:       global
** Description:      This function is used to find the valid menu instance
**                   from the logic state ID.
**                   Bascially it checks for the Screen ID in the table and
**                   fetches the MenuID and then validate in the current available
**                   menu instance.
** Invocation:       By the Menu logic.c
** Inputs/Outputs:   p_logic_id_U8 - Logic State ID
**                   fl_find_menu_inst_ptr = valid menu instance
** Critical Section: None.
**==========================================================================*/
static MENU_CONTROL_T  *hmi_menu_logic_get_valid_menu_instance(LSH_STATE_ID_T p_logic_state_id_U8)
{
  MENU_CONTROL_T *fl_find_menu_inst_ptr;
  UINT8 fl_get_menu_ID_U8;
  UINT8 i;
  i = 0;
  fl_find_menu_inst_ptr = FNULL;
  fl_get_menu_ID_U8     = 0xFF;

  for(i = 0; i < NB_OF_MENU_INSTANCE; i++)
  {
    if(l_menu_instance_array[i].inst_status_U8 == HMI_MENU_LOGIC_INST_ACTIVE)
    {
       fl_get_menu_ID_U8 = l_menu_instance_array[i].menu_id;
       if(hmi_menu_const_struct_array_table[fl_get_menu_ID_U8].disp_screen_id == p_logic_state_id_U8)
       {
          fl_find_menu_inst_ptr = &l_menu_instance_array[i];
          break;
       }
    }
  }
  return(fl_find_menu_inst_ptr);
}

/*============================================================================
** Function Name:    hmi_menu_logic_Set_ParentFocus
** Visibility:       global
** Description:      This function sets the foucs marker & level while coming back
**                   and loading the Parent Menu from SubMenu.
** Invocation:       Invoked by hmi logic
** Inputs/Outputs:   p_menu_cntrl_ptr, p_sub_menu_ptr
** Critical Section: None.
**==========================================================================*/
static void hmi_menu_logic_Set_ParentFocus(MENU_CONTROL_T *p_menu_cntrl_ptr, const MENU_DEF_T *p_sub_menu_ptr)
{
   UINT16       ind;
   MENU_DEF_T const   * fl_get_sub_menu_SP;
   MENU_DEF_T const   * fl_menu_def_SP;
   UINT8            fl_menu_level;
   
   if (p_menu_cntrl_ptr != FNULL)
   {
      fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
      for (ind = 0; ind <p_menu_cntrl_ptr->menu_entry_nbr; ind++)
      {
        fl_get_sub_menu_SP        = fl_menu_def_SP->entry_array[ind].utype.sub_menu;
        if ((fl_menu_def_SP->entry_array[ind].item_entry_type == MENU_ITEM_ENTRY_TYPE_MENU) && \
            (fl_get_sub_menu_SP == p_sub_menu_ptr))
        {
          /* Set parent focus to the current menu */
          p_menu_cntrl_ptr->focus_entry_U16 = ind;
          break;
        }
      }
      
      fl_menu_level = hmi_menu_logic_get_Menu_level((MENU_LIST_ID_T)p_menu_cntrl_ptr->menu_id);
      if(fl_menu_level > 2)
      {
        p_menu_cntrl_ptr->menu_level_U8 = 2;
      }
      else
      {
        p_menu_cntrl_ptr->menu_level_U8 = fl_menu_level;      
      }
   }
}

/*============================================================================
** Function Name:    hmi_menu_logic_Focusline_Center
** Visibility:       global
** Description:      Focus line position handling while opening the Menu
** Invocation:       Invoked by Application
** Inputs/Outputs:   p_menu_cntrl_SP
** Critical Section: None.
**==========================================================================*/
static void hmi_menu_logic_Focusline_Center(MENU_CONTROL_T *p_menu_cntrl_SP)
{
  if ((p_menu_cntrl_SP->focus_entry_U16 < (p_menu_cntrl_SP->displayed_lines >> 1)) || \
    (p_menu_cntrl_SP->menu_entry_nbr <= p_menu_cntrl_SP->displayed_lines))
  {
    p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_entry_U16;
  }
  else
  {
    if (p_menu_cntrl_SP->focus_entry_U16 >= (p_menu_cntrl_SP->menu_entry_nbr - (p_menu_cntrl_SP->displayed_lines >> 1)))
    {
      p_menu_cntrl_SP->focus_line_U16 = p_menu_cntrl_SP->focus_entry_U16 - (p_menu_cntrl_SP->menu_entry_nbr - p_menu_cntrl_SP->displayed_lines);
    }
    else
    {
      p_menu_cntrl_SP->focus_line_U16 = ((UINT16)(p_menu_cntrl_SP->displayed_lines - 1)) >> 1;
    }
  }
}

/*============================================================================
** Function Name:    hmi_menu_logic_Get_FocusMenu
** Visibility:       global
** Description:      This function returns the current focus menu ptr
** Invocation:       Invoked by Application
** Inputs:           None
** Outputs:          MENU_CONTROL_T
** Critical Section: None
** Created:          29-Mar-2010 by jpradeep
** Updated:          29-Mar-2010 by jpradeep
**==========================================================================*/
MENU_CONTROL_T  *hmi_menu_logic_Get_FocusMenu(void)
{
  return Current_focus_menu_ptr;
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
  const MENU_DEF_T *fl_menu_def_ptr;
  UINT8 fl_menu_level_val_U8;
  
  fl_menu_level_val_U8 = 0;
  if(p_menu_ID_e < HMI_MENU_ID_COUNT)
  {
    fl_menu_def_ptr = &hmi_menu_const_struct_array_table[p_menu_ID_e];
    while(fl_menu_def_ptr->parent_menu != FNULL)
    {
      fl_menu_def_ptr = fl_menu_def_ptr->parent_menu;
      fl_menu_level_val_U8++;
    }
  }
  return(fl_menu_level_val_U8);
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
**==========================================================================*/
static MENU_LIST_ID_T hmi_menu_logic_get_menu_index(const MENU_DEF_T *fl_menu_ID_ptr)
{
  UINT8  i;
  MENU_LIST_ID_T  fl_ret_menu_def_index_e;

  fl_ret_menu_def_index_e = (MENU_LIST_ID_T)MENU_INDEX_INVALID;
  for(i=0; i<HMI_MENU_ID_COUNT; i++)
  {
    if(fl_menu_ID_ptr == &hmi_menu_const_struct_array_table[i])
    {
      fl_ret_menu_def_index_e = (MENU_LIST_ID_T)i;
      break;
    }
  }
  return(fl_ret_menu_def_index_e);
}

/*============================================================================
** Function Name:    hmi_menu_logic_Is_CurrentMenuOpen
** Visibility:       global
** Description:      This function Checks whether the focused Menu is open or not.
** Invocation:       Invoked by Application
** Inputs:           None
** Outputs:          BOOLEAN_T
** Critical Section: None.
**==========================================================================*/
BOOLEAN_T hmi_menu_logic_Is_CurrentMenuOpen(void)
{
  BOOLEAN_T fl_ret_status_BOOL = FALSE;

  if(Current_focus_menu_ptr != FNULL)
  {
    fl_ret_status_BOOL = TRUE;
  }
  return(fl_ret_status_BOOL);
}

/*============================================================================
** Function Name:    hmi_menu_logic_load_menu_level
** Visibility:       global
** Description:      This function shall be used to load the menu level element
**                   in the Menu control structure.
** Invocation:       Invoked by logic.c
** Inputs/Outputs:   p_menu_cntrl_ptr
** Critical Section: None.
**==========================================================================*/
static void hmi_menu_logic_load_menu_level(MENU_CONTROL_T *p_menu_cntrl_ptr)
{
  if(p_menu_cntrl_ptr != FNULL)
  {
    if(hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].parent_menu != FNULL)
    {
      /* Find the level */
      if(hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].parent_menu->parent_menu != FNULL)
      {
        p_menu_cntrl_ptr->menu_level_U8 = HMI_MENU_LEVEL_2;
      }
      else
      {
        p_menu_cntrl_ptr->menu_level_U8 = HMI_MENU_LEVEL_1;
      }
    }
    else
    {
      /* It should be ROOT Menu */
      p_menu_cntrl_ptr->menu_level_U8 = HMI_MENU_LEVEL_0;
    }
  }
}

/*============================================================================
** Function Name:    hmi_menu_logic_left_menu_action
** Visibility:       static
** Description:      This function shall be used to perform left action.
** Invocation:       Invoked by logic.c
** Inputs/Outputs:   p_menu_cntrl_ptr, menu action
** Critical Section: None.
**==========================================================================*/
static MENU_CB_RESULT_T hmi_menu_logic_left_menu_action(MENU_CONTROL_T *p_menu_cntrl_ptr, UINT8 p_menu_action_U8)
{
   MENU_CB_RESULT_T        fl_cb_result_e = MENU_CB_ACTION_COMPLETED;
   MENU_DEF_T  const      *fl_menu_def_SP;
   const MENU_DEF_T       *fl_sub_menu_def_ptr;
   const MENU_DEF_T       *fl_root_menu_ref_ptr;
   
   fl_menu_def_SP = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
   
   if((p_menu_cntrl_ptr->menu_level_U8 > HMI_MENU_LEVEL_1) &&
      (p_menu_action_U8 == MENU_ACTION_LEFT_LONG))
   {
      /* Loading the menu level to be taken care */
      fl_sub_menu_def_ptr  = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
      fl_root_menu_ref_ptr = hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id].parent_menu;
      while(fl_root_menu_ref_ptr != FNULL)
      {
         if(fl_root_menu_ref_ptr->parent_menu != FNULL)
         {
           fl_sub_menu_def_ptr  = fl_root_menu_ref_ptr;
           fl_root_menu_ref_ptr = fl_root_menu_ref_ptr->parent_menu;   /* update the root if it has parent */
         }
         else
         {
           fl_root_menu_ref_ptr = FNULL;
         }
      }
      fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_sub_menu_def_ptr->parent_menu, p_menu_cntrl_ptr->menu_instance_no, MENU_ACTION_OPEN_FROM_CHILD);
      hmi_menu_logic_Set_ParentFocus(p_menu_cntrl_ptr, fl_sub_menu_def_ptr);
      hmi_menu_logic_Focusline_Center(p_menu_cntrl_ptr);
   }
   else
   {
     if (fl_menu_def_SP->cb != FNULL)
     {
       fl_cb_result_e = fl_menu_def_SP->cb(MENU_ACTION_CLOSE, p_menu_cntrl_ptr, MENU_BTN_INVALID);
     }
     
     if (fl_menu_def_SP->parent_menu != FNULL)
     {
       fl_sub_menu_def_ptr = &hmi_menu_const_struct_array_table[p_menu_cntrl_ptr->menu_id];
       /* We are in a submenu: close sub menu */
       fl_cb_result_e = hmi_menu_logic_SubMenu_Open(fl_menu_def_SP->parent_menu, p_menu_cntrl_ptr->menu_instance_no, MENU_ACTION_OPEN_FROM_CHILD);
       hmi_menu_logic_Set_ParentFocus(p_menu_cntrl_ptr, fl_sub_menu_def_ptr);
       hmi_menu_logic_Focusline_Center(p_menu_cntrl_ptr);
     }
   }
   return(fl_cb_result_e);
}

/****************************************************************************
Function Name     : hmi_menu_logic_start_timer
Description       : Common Interface to start all the timers used in Menu Core
Invocation        : Invoked by logic
Parameters        : menu id.
Return Value      : None
Critical Section  : None
******************************************************************************/
static void hmi_menu_logic_start_timer(UINT8 fl_menu_id_U8)
{
   MENU_CONTROL_T   *fl_menu_cntrl_SP;
   UINT8 fl_menu_inst_U8;
   UINT8 fl_timer_val_U8;
   
   fl_menu_cntrl_SP = hmi_menu_logic_get_menu_instance((MENU_LIST_ID_T)fl_menu_id_U8);
   if(fl_menu_cntrl_SP != NULL)
   {
      fl_menu_inst_U8 = fl_menu_cntrl_SP->menu_instance_no;
      fl_timer_val_U8 = hmi_menu_logic_get_menu_timeout_value(fl_menu_id_U8);
      if(fl_timer_val_U8 != 0)
      {
          HMI_MENU_START_TIMER(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id,fl_timer_val_U8);
      }
   }
}
/****************************************************************************
Function Name     : hmi_menu_logic_stop_timer
Description       : Common Interface to stop all the timers used in Menu Core
Invocation        : Invoked by logic
Parameters        : menu id.
Return Value      : None
Critical Section  : None
******************************************************************************/
static void hmi_menu_logic_stop_timer(UINT8 fl_menu_id_U8)
{
   MENU_CONTROL_T  *fl_menu_cntrl_SP;
   UINT8 fl_menu_inst_U8;
   
   fl_menu_cntrl_SP = hmi_menu_logic_get_menu_instance((MENU_LIST_ID_T)fl_menu_id_U8);
   if(fl_menu_cntrl_SP != NULL)
   {
      fl_menu_inst_U8 = fl_menu_cntrl_SP->menu_instance_no;
      HMI_MENU_STOP_TIMER(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id);
   }
}
/****************************************************************************
Function Name     : hmi_menu_logic_open_timer_timeout
Description       : Menu Open Timer timeout.
Invocation        : invoked by application
Parameters        : fl_timer_id_U8.
Return Value      : None
Critical Section  : None
******************************************************************************/
void hmi_menu_logic_open_timer_timeout(UINT8 fl_timer_id_U8)
{
   UINT8 fl_menu_inst_U8 = 0;
   for(fl_menu_inst_U8 = 0;fl_menu_inst_U8 < NB_OF_MENU_INSTANCE;fl_menu_inst_U8++)
   {
      if(hmi_menu_inst_config_table[fl_menu_inst_U8].menu_open_timer_id == fl_timer_id_U8)
      {   
         /* Identify the menu instance with respect to the timer */
         hmi_menu_logic_Menu_Close((MENU_LIST_ID_T)l_menu_instance_array[fl_menu_inst_U8].menu_id);
         break;
      }
   }
}
/*============================================================================
** Function Name:    hmi_menu_logic_Get_MenuTimeOut
** Visibility:       global
** Description:      This function returns the Menu Timeout value
** Invocation:       Invoked by logic
** Inputs/Outputs:   p_menu_id_U8
** Critical Section: None.
**==========================================================================*/
static UINT8 hmi_menu_logic_get_menu_timeout_value(UINT8 p_menu_id_U8)
{
  UINT8             fl_timeOut_U8 = 0;
  MENU_CONTROL_T   *fl_menu_inst_ID_ptr;

  fl_menu_inst_ID_ptr = hmi_menu_logic_get_menu_instance((MENU_LIST_ID_T)p_menu_id_U8);
  if(fl_menu_inst_ID_ptr != FNULL)
  {
    fl_timeOut_U8 = hmi_menu_const_struct_array_table[fl_menu_inst_ID_ptr->menu_id].timeout;
  }
  #ifdef HMI_MENU_TIMEOUT_CONGIF_FEATURE_ENABLE
  if(HMI_MENU_ITEM_TIMEOUT_CONFIGURABLE == fl_timeOut_U8)
  {
     fl_timeOut_U8 = HMI_MENU_TIMEOUT_INTERFACE();
  }
  #endif
  return(fl_timeOut_U8);
}
/*End of File*/
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
** CMS Rev #        Date           By
** CMS Rev X.X      mm/dd/yyyy     CDSID
**
**===========================================================================
**
** CMS Rev 1.0      09-Apr-2013    kcsarava
** Creation.
**
**==========================================================================*/
/*---------------------------------------------------------------------------
Date              : 18-Apr-2013
CDSID             : kcsarava
Traceability      : Added menu levels, up/down cb
Change Description: As Menu level is not loaded, not able to open parent menu
                    with left action.  up/down cb is added. 
                    dentified in unit testing
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-Apr-2013
CDSID             : kcsarava
Traceability      : for PR ID: 65051
Change Description: PR defect fixes
                    Corrected the issue of loading Menu levels before 
                    menu logic is created in submenu_open
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 29-Apr-2013
CDSID             : kcsarava
Traceability      : for PR ID: 65051
Change Description: PR defect fixes
                    MENU_BTN_ABSORBED is given to LSH
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 30-Apr-2013
CDSID             : kcsarava
Traceability      : for PR ID: 65051
Change Description: PR defect fixes - Menu action close is added
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 08-May-2013
CDSID             : kcsarava
Traceability      : Added new requirements which is applicable for both menu core 
                    and menu core lite
Change Description: Added multi action with single button support with multi btn 
                    map action table, BACK and EXIT support in item properties
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 09-May-2013
CDSID             : kcsarava
Traceability      : for PR ID: 65725
Change Description: Removed timer id, line_fast_inc in MENU_CONTROL_T
                    Removed MENU_ITEM_PRO_ACTION_BACK, MENU_ITEM_PRO_ACTION_EXIT 
                    support for LEFT/RIGHT action.
                    Removed p_init_type_U8 in hmi_menu_initialize
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  28.2.2014
By                :  msenthi4
Traceability      :  
Change Description: Coverity warning fix. 
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
Date              : 22-05-2014
By                : msenthi4/csakthiv
Traceability      : RTC122463 defect fix.
Change Description:	menu close instance handled correctly 
----------------------------------------------------------------------------*/
