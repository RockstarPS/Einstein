/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2010. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/

/*****************************************************************************

 File Name        :  hmi_menu_core_01_logic.h
 Module Short Name:  Menu Core
 VOBName          :  sw_hmi_ss\hmi_menu_core_01
 Author           :  jpradeep
 Description      :  This file contains the headers of Menu core logic
 Organization     :  Driver Information Software Section,
 Visteon Corporation
 ******************************************************************************/

#ifndef HMI_MENU_CORE_01_LOGIC_H
#define HMI_MENU_CORE_01_LOGIC_H

#include "tmwtypes.h"
#include "hmi_language_interface.h"
#include "hmi_menu_core_01_chart.h"
#include "hmi_menu_core_01.cfg"

#ifndef HMI_MENU_CORE_01_LOGIC_C
#define EXTERN_pfx extern
#else
#define EXTERN_pfx
#endif
/*****************************************************************************
 *                                 Global Macro Definitions                   *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#define MENU_CORE_MENU_OPEN(menu_id, anim_id)                              hmi_menu_logic_Menu_Open(menu_id, anim_id)
#define MENU_CORE_MENU_CLOSE(menu_id,anim_id)                              hmi_menu_logic_Menu_Close(menu_id, anim_id)
#define MENU_CORE_OPEN_TIMER_TIMEOUT(timer_id,anim_id)                     hmi_menu_logic_open_timer_timeout(timer_id, anim_id)
#else
#define MENU_CORE_MENU_OPEN(menu_id, anim_id)                              hmi_menu_logic_Menu_Open(menu_id)
#define MENU_CORE_MENU_CLOSE(menu_id, anim_id)                             hmi_menu_logic_Menu_Close(menu_id)
#define MENU_CORE_OPEN_TIMER_TIMEOUT(timer_id, anim_id)                    hmi_menu_logic_open_timer_timeout(timer_id)
#endif



/*****************************************************************************
 *                                 Type Declaration                           *
 *----------------------------------------------------------------------------*
 * Declaration of type shall be accompanied by a comment that explains the    *
 * purpose and usage of the type.                                             *
 ******************************************************************************/
/*****************************************************************************
 *                                 Global Variable Declarations               *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/

/*****************************************************************************
 *                                 Global Constant Declarations		         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * Purpose, unit and resolution                                               *
 ******************************************************************************/
extern MENU_DEF_T const hmi_menu_const_struct_array_table[TOTAL_MENU_ID];
extern MENU_BTN_ACNS_MAP_TABLE_T const hmi_menu_map_actions_table_ptr[HMI_MENU_TABLE_COUNT];
extern MENU_INST_CONFIG_T const hmi_menu_inst_config_table[NB_OF_MENU_INSTANCE];
extern UINT8 const hmi_menu_actions_allowed_in_anim[HMI_MENU_ACTION_IN_ANIM_COUNT];
extern MENU_DYNAMIC_ENTRY_ARRAY_MAP_T const hmi_menu_const_dynamic_menu_table[TOTAL_DYNAMIC_MENU_ITEMS];

/*****************************************************************************
 *                                 Global Function Prototypes                 *
 ******************************************************************************/
EXTERN_pfx void hmi_menu_initialize(void);
EXTERN_pfx void hmi_menu_logic_Menu_Refresh(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_Menu_Open(MENU_LIST_ID_T p_open_menu_id_e
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
,UINT8 p_open_anim_ID_U8
#endif
);
EXTERN_pfx void hmi_menu_logic_Menu_Close(MENU_LIST_ID_T p_close_menu_id_e
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
,UINT8 p_menu_anim_ID_U8
#endif
);
EXTERN_pfx BOOLEAN hmi_menu_logic_is_menu_action_allowed_in_anim_state(UINT8 fl_menu_action_U8);
EXTERN_pfx void hmi_menu_logic_Close_all_Menu(void);
EXTERN_pfx void hmi_menu_logic_Menu_Rebuild(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_Set_SelectEntry(MENU_CONTROL_T *p_menu_cntrl_SP,
UINT16 p_entry_S16);
EXTERN_pfx void hmi_menu_logic_CreateLabel_Items(
MENU_ITEM_ENTRY_T *p_item_entry_ptr, UINT16 p_nb_entries_U16);
EXTERN_pfx void hmi_menu_logic_CreateMenu_Items(MENU_ITEM_ENTRY_T *p_item_entry_ptr,
UINT16 p_nb_entries_U16);
EXTERN_pfx UINT8 hmi_menu_logic_get_crnt_menu_level(void);
EXTERN_pfx void hmi_menu_logic_process_available_data(MENU_LIST_ID_T fl_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_exit_fast_scroll(MENU_LIST_ID_T fl_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_Set_MenuState(MENU_LIST_ID_T p_menu_id_U8,
UINT8 p_menu_state_U8);
EXTERN_pfx void hmi_menu_logic_activate_animation(MENU_LIST_ID_T p_menu_id_U8,
MENU_CB_RESULT_T p_menu_cb_actn_e);
EXTERN_pfx void hmi_menu_logic_deactivate_animation(MENU_LIST_ID_T p_menu_id_U8,
MENU_CB_RESULT_T p_menu_cb_actn_e);
EXTERN_pfx BOOLEAN hmi_menu_logic_is_FS_Enabled(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx BOOLEAN hmi_menu_logic_Is_CurrentMenuOpen(void);
EXTERN_pfx BOOLEAN hmi_menu_logic_MenuIsOpen(MENU_LIST_ID_T p_menu_id_U8);
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
EXTERN_pfx BOOLEAN hmi_menu_logic_FS_check_is_Btn_rel(UINT16 p_button_command_U16);
EXTERN_pfx UINT16 hmi_menu_logic_FS_convert_Btn_status(BOOLEAN p_status_BOOL,
UINT16 p_btn_cmd_U16);
EXTERN_pfx MENU_CB_RESULT_T hmi_menu_button_handler(MENU_LIST_ID_T p_menu_id_U8,
UINT16 p_btn_cmd_U16, UINT8 p_menu_state_U8);
#endif
EXTERN_pfx UINT8 hmi_menu_logic_get_menu_timeout_value(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx MENU_CB_RESULT_T hmi_menu_logic_process_menu_action(MENU_LIST_ID_T p_menu_id_U8,
UINT8 p_menu_action_U8);

EXTERN_pfx MENU_CB_RESULT_T hmi_menu_logic_Menu_ReinitAction(
MENU_CONTROL_T *p_menu_cntrl_SP);
EXTERN_pfx MENU_CB_RESULT_T hmi_menu_logic_MenuDataAvailable(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx MENU_CB_RESULT_T hmi_menu_logic_MenuCompletion(
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
	MENU_LIST_ID_T p_menu_id_U8
#else
    void
#endif
	);
EXTERN_pfx MENU_CONTROL_T *hmi_menu_logic_Get_Focus_MenuInstance(void);
EXTERN_pfx MENU_LIST_ID_T hmi_menu_logic_get_parent_menu_id(MENU_LIST_ID_T fl_curr_menu_id_U8);
EXTERN_pfx MENU_CONTROL_T *hmi_menu_logic_get_menu_instance(
MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx LSH_STATE_ID_T   hmi_menu_logic_get_screen_id(MENU_CONTROL_T const *p_menu_cntrl_ptr);
EXTERN_pfx MENU_ITEM_ENTRY_T const *hmi_menu_logic_Get_item_entry_array(MENU_CONTROL_T const *p_menu_cntrl_ptr, UINT16 p_focus_entry_U16);
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
EXTERN_pfx UINT8 hmi_menu_logic_is_any_menu_item_configured(MENU_LIST_ID_T p_menu_ID_e);
EXTERN_pfx UINT16 hmi_menu_logic_get_focus_entry(MENU_CONTROL_T const *p_hmi_app_ptr, UINT16 p_itm_absl_indx_U16);
EXTERN_pfx BOOLEAN hmi_menu_logic_is_stored_item_enabled(MENU_LIST_ID_T p_menu_ID_e, UINT8 p_stored_item_U8);
EXTERN_pfx void hmi_menu_logic_Menu_Update(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_Menu_Reload(MENU_LIST_ID_T fl_menu_id_U8);
EXTERN_pfx UINT16 hmi_menu_logic_get_absl_index_focus_entry(MENU_CONTROL_T const *p_menu_cntrl_ptr);
#endif
EXTERN_pfx void hmi_menu_logic_start_timer(UINT8 fl_timer_type_U8,
MENU_LIST_ID_T fl_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_stop_timer(UINT8 fl_timer_type_U8,
MENU_LIST_ID_T fl_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_open_timer_timeout(UINT8 fl_timer_id_U8
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
, UINT8 fl_close_anim_id_U8
#endif
);
EXTERN_pfx void hmi_menu_logic_open_parent_menu(MENU_LIST_ID_T fl_curr_menu_id_U8);
EXTERN_pfx void hmi_menu_logic_Focusline_Center(MENU_CONTROL_T *p_menu_cntrl_SP);
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
EXTERN_pfx void hmi_menu_logic_wait_timer_timeout(UINT8 fl_timer_id_U8);
#endif
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
EXTERN_pfx void hmi_menu_logic_fast_scroll_timer_timeout(UINT8 fl_timer_id_U8);
#endif
EXTERN_pfx MENU_CONTROL_T *hmi_menu_logic_get_required_menu_instance(UINT8 p_menu_inst_num_U8);
EXTERN_pfx MENU_CONTROL_T *hmi_menu_logic_get_active_menu_instance_ptr(UINT8 p_menu_inst_num_U8);
#undef EXTERN_pfx

#endif

/*End of File*/
/*****************************************************************************
 *   for each change to this file, be sure to record:                         *
 *      1.  who made the change and when the change was made                  *
 *      2.  why the change was made and the intended result                   *
 *   Following block needs to be repeated for each change
 ******************************************************************************
 *   Note: In the traceability column we need to trace back to the Design Doc.*
 *   For the initial version it is traced to the Design Document section.     *
 *   For further changes it shall trace to the source of the change which may *
 *   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *   other reason                                                             *
 ******************************************************************************/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 29-03-10
 Traceability      : Initial version
 Change Description: Initial version created
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 22-04-10
 Traceability      : Compilation error
 Change Description: Modified the properties from enum to Macro and the function
 Prototypes are defined correctly.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 26-05-10
 Traceability      : Menu Core Development
 Change Description: Review comments updates and QAC ver 7.1 fixes
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 06-06-10
 Traceability      : Menu Core Development
 Change Description: Property MENU_PRO_DISABLE_SELECTED_ENTRY added.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 09-06-10
 Traceability      : Menu Core Development
 Change Description: Enum(MENU_ACTION_REBUILD) order changed.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 16-06-10
 Traceability      : Compiler Warning Resolve
 Change Description: Since the View State Manager has made provision to declare
 the handlers in it, they are removed from here.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 28-06-10
 Traceability      : Menu Fast scroll Implementation
 Change Description: Added MENU_ACTION_UP_RELEASE, MENU_ACTION_DOWN_RELEASE,
 MENU_ACTION_LEFT_RELEASE, MENU_ACTION_RIGHT_RELEASE
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 28-06-10
 Traceability      : Macro change
 Change Description: MENU_PRO_DYNAMIC & MENU_PRO_EXTERNAL_SCROLL_ROLLING was
 defined with the same value which is corrected.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 20-07-10
 Traceability      : Menu Animation support
 Change Description: Menu animation handling functions are extern.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 20-07-10
 Traceability      : CQ 90396
 Change Description: p_menu_id_U8 parameter removed from certain functions.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 26-07-10
 Traceability      : Menu Animation Feature
 Change Description: Menu Animation feature implementation completed.
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
 CDSID             : 05-09-10
 Traceability      : Lang SID typedef, const Migration
 Change Description: Declared the SID refernce inside the Menu structure as
 HMI_LANG_SID.
 Some functions are declared with const identifier.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 09-09-10
 Traceability      : PR comments - 36039
 Change Description: Migrated to new template and comments updated infront of
 Menu and item properties.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 29-Sept-2010
 Traceability      : PR comments updated- 36952
 Change Description: Defect:2
 Extern the function hmi_menu_logic_is_stored_item_enabled()
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : 05-10-10
 CDSID             : jpradeep
 Traceability      : Menu Core Enhancement
 Change Description: HMI_MENU_ACTIONS_COUNT changed to HMI_MENU_TOTAL_BTN_ACNS_MAPPED.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : 31-12-10
 CDSID             : jpradeep
 Traceability      : Menu Core Enhancement
 Change Description: Extern the function hmi_menu_logic_get_required_menu_instance
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 12-11-10
 Traceability      : Menu Item Gray scale support
 Change Description: Implemented the Menu item Gray scale logic
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : jpradeep
 CDSID             : 26-07-2011
 Traceability      : BSDI00107085
 Change Description: added a new member in the control t structure to store the
 focus status of the current avtive pointer
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date               : 12.9.2011
 By                 : jmanojku
 Traceability       : BSDI00104707
 Change Description : added the  macros for the menu configuratble for submenu
 items
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date              : 20.09.2011
 CDSID             : jmanojku
 Traceability      : BSDI00104707
 Change Description: moved the  macros for the menu configuratble for submenu
 items to cfg file
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date               : 23.Sep.2011
 By                 : jmanojku
 Traceability       : SCR-BSDI00105028
 Change Description : Function implemented to check the change and update the menu.
 This is called in RR Added the prototype
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date               : 20 Oct 2011
 By                 : jpradeep
 Traceability       : Dynamic Menu Issue fix
 Change Description : Introduced a new menu property MENU_PRO_DYNAMIC_UPDATE
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 Date               : 17 Nov 2011
 By                 : jpradeep
 Traceability       : Menu Reload
 Change Description : Introduced a new menu action item called MENU ACTION RELOAD
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
 Date              : 6-July-2013
 CDSID             : csakthiv
 Traceability      :
 Change Description: Menu Instance Queue added, PR defect Fix,Focus line Centre,
 Table for handling buttons in Anim state and QAC warning for Sid and text
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
 Change Description: hmi_menu_logic_Focusline_Center changed from static to extern. Applications are calling
 hmi_menu_logic_Set_SelectEntry() unnecessarily to call hmi_menu_logic_Focusline_Center().
 Now application can call hmi_menu_logic_Focusline_Center() separately.
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
 Date              : 15-Jan-2014
 CDSID             : csakthiv
 Traceability      :
 Change Description: HMI_LANG_SID and MENU_LABEL_T swapped in union of MENU_DEF_T.
 Reason: initializing a union, by default the first element of union would be initialized.
 To avoid QAC warning. Also, tool change is required. while typecasting the language SID, it should be
 typecasted with HMI_LANG_SID instead of MENU_LABEL_T.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 3-April-2014
CDSID             : csakthiv
Traceability      : Bug 142
Change Description: Core and tool version mismatch check. If they are different, then compiler error will be generated from core.
                    QAC warning fix.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 28-Nov-2014
CDSID             : adevi
Traceability      : Task id:247726
Change Description: hmi_menu_logic_get_required_menu_instance function
                    is made global.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  06-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  QAC 8.1.2 Warnings resolved.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  03-Mar-15
By                :  arajase2
Traceability      :  Issue Fix - C296731: Dynamic menus do not close for ok button press
Change Description:  hmi_menu_logic_process_menu_action function return type changed
              from UINT8 to MENU_CB_RESULT_T
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  05-OCT-15
By                :  arajase2
Traceability      :  419936: Menu core compiler warnings fix for fast scroll implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  11-May-16
By                :  aperumal
Traceability      :  512197: Turing Compiler Warning fix -  File ends without new line
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  07-Jun-17
By                :  arajase2
Traceability      :  882810: CMFB MISRA Warning fixes - Menu Configurator Auto Code Generation

Return type for MENU_ITEM_ENTRY_T const *hmi_menu_logic_Get_item_entry_array function is
changed as const pointer
-----------------------------------------------------------------------------*/


