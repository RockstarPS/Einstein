/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
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

File Name        :  hmi_menu_interface.h
Module Short Name:  MENU
VOBName          :  
Author           :  kcsarava
Description      :  HMI Menu Interface Header

Organization     :  HMI Sub System,
                    Visteon Corporation

******************************************************************************/

#ifndef HMI_MENU_CORE_LITE_01_LOGIC_H
#define HMI_MENU_CORE_LITE_01_LOGIC_H

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

#include "tmwtypes.h"
#include "hmi_language_interface.h"
#include "hmi_menu_core_lite_01.cfg"

#ifdef HMI_MENU_CORE_LITE_01_LOGIC_C
#define EXTERN_pfx
#else
#define EXTERN_pfx extern
#endif

/*****************************************************************************
*                                 Constant Declarations                    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
******************************************************************************/

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define MENU_ACTION_EXIT                    (0)


/* Menu Item properties All the Below mentioned properties are to be
** set at Menu.MENU_ITEM_ENTRY_T ->item_properties while configuring 
** the Menu item. 
** 
** Following Menu Items are Not supported 
** 1.MENU_ITEM_PRO_SELECTION
** 2.MENU_ITEM_PRO_DISABLED
** 3.MENU_ITEM_PRO_LABEL_ID
** 4.MENU_ITEM_PRO_CONFIGURABLE
** 5.MENU_ITEM_PRO_RADIO_BTN
** 6.MENU_PRO_ITEM_STRING
** 7.MENU_ITEM_STRING_U8
** 8.MENU_ITEM_PRO_TGL_WITH_MENU
** 9.MENU_ITEM_PRO_GRAY_OUT     
** */

#define MENU_ITEM_PRO_ACTION_BACK          (0x0200)
#define MENU_ITEM_PRO_ACTION_EXIT          (0x0400)

#define MIN_VALUE(a,b)                ((a<b)?a:b)

#define HMI_MENU_LOGIC_INST_INACTIVE          0x01
#define HMI_MENU_LOGIC_INST_ACTIVE            0x02   

/*
** Menu Properties
** All the Below mentioned properties are to be 
** set at MENU_DEF_T ->properties while
** configuring the Menu.
** 
** Following Menu properties are Not supported 
** 1. MENU_PRO_CLASSICAL_MENU
** 2. MENU_PRO_ANIMATION
** 3. MENU_PRO_WITH_SCROLL_BAR
** 4. MENU_PRO_DYNAMIC
** 5. MENU_PRO_SCROLL_ROLLING
** 6. MENU_PRO_NO_ROOT_FOLDER
** 7. MENU_PRO_EXTERNAL_SCROLL_ROLLING
** 8. MENU_PRO_NO_FAST_SCROLL
** 9. MENU_PRO_DISABLE_SELECTED_ENTRY
** 11.MENU_PRO_HISTORY_MENU
** 12.MENU_PRO_TXT_STATIC
** 13.MENU_PRO_DISABLE_CURSOR
** 14.MENU_PRO_DISABLE_SCROLL_BAR
** 15.MENU_PRO_DYNAMIC_UPDATE
** */

#define MENU_PRO_FOCUS_WRAPAROUND            (0x0040)
#define MENU_PRO_CLOCK_FORMAT                (0x0200)

/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Declaration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
typedef LANG_SID_T      HMI_LANG_SID;

/* The enum consists of the Menu Actions.
** Applicable Button Actions can be mapped to the Respective Menu Actions. */
typedef enum
{
   MENU_ACTION_NONE,                 /* MENU_ACTION_NONE,     */
   MENU_ACTION_CLOSE,                /* MENU_ACTION_CLOSED,   */
   MENU_ACTION_OPEN,                 /* MENU_ACTION_OPEN,     */
   MENU_ACTION_UP,                   /* MENU_MOVE_UP_E,       */
   MENU_ACTION_DOWN,                 /* MENU_MOVE_DN_E,       */
   MENU_ACTION_LEFT,                 /* MENU_MOVE_LEFT_E,     */
   MENU_ACTION_RIGHT,                /* MENU_MOVE_RIGHT_E,    */
   MENU_ACTION_LEFT_LONG,            /* MENU_WAIT_FOR_DATA_E, */
   MENU_ACTION_OK_IN,                /* MENU_DATA_AVAILABLE_E,*/
   MENU_ACTION_VALIDATE_BUTTON,      /* MENU_BUTTON_DATA_E,   */
   MENU_ACTION_FORCED_CLOSE,         /* MENU_EXIT_ACTION      */
   MENU_ACTION_INCREMENT,            
   MENU_ACTION_DECREMENT,            
   MENU_ACTION_OPEN_FROM_PARENT,     
   MENU_ACTION_OPEN_FROM_CHILD,      
   MENU_ACTION_LOST_FOCUS,           
   MENU_ACTION_GOT_FOCUS             
                                     /* MENU_ACTION_DONE,     */
}MENU_ACTION_T;

/*It defines the state of the menu */ 
typedef enum
{
  MENU_ACTIVE_E,
  MENU_INACTIVE_E,
  MENU_NO_STATUS_E
}MENU_STATUS_T;

/* Different item entry type
** MENU_ITEM_ENTRY_TYPE_LABEL    - Normal
** MENU_ITEM_ENTRY_TYPE_MENU     - Item having Submenu
** MENU_ITEM_ENTRY_TYPE_BARGRAPH - Bargraph */
typedef enum {
   MENU_ITEM_ENTRY_TYPE_LABEL,
   MENU_ITEM_ENTRY_TYPE_MENU,
   MENU_ITEM_ENTRY_TYPE_BARGRAPH,
} MENU_ITEM_ENTRY_TYPE_T;

/* Two types of item label type used when MENU_ITEM_LABEL_TYPE_ID   - Passing SID
** MENU_ITEM_LABEL_TYPE_STR  - Passing String */
typedef enum {
   MENU_ITEM_LABEL_TYPE_ID,
   MENU_ITEM_LABEL_TYPE_STR 
} MENU_ITEM_LABEL_TYPE_T;

/*
** Structure Definition for Display Menu which has control Parametrs
*/
typedef struct menu_t {
   UINT8                                    menu_id;
   UINT8                                    inst_status_U8;
   UINT8                                    menu_state;
   UINT8                                    displayed_lines;
   UINT8                                    menu_instance_no;
   UINT8                                    menu_level_U8;
   UINT16                                   focus_line_U16;
   UINT16                                   focus_entry_U16;        /* Active Entry in the display */
   UINT16                                   selected_entry_U16;     /* Selected entry in the display */
   UINT16                                   menu_properties;
   UINT16                                   menu_entry_nbr;
}MENU_CONTROL_T;

/* Call Back for Menu Button and Actions */
typedef MENU_CB_RESULT_T (MENU_CALLBACK_T)(MENU_ACTION_T, MENU_CONTROL_T *, UINT16 p_button_command_U16);

typedef void (MENU_CALLBACK_PRESNT_T)(MENU_CONTROL_T *, UINT8 p_lsh_status_U8);

typedef char               MENU_LABEL_CHAR;
 
typedef MENU_LABEL_CHAR*   MENU_LABEL_T;

/* Structure Declaration for Menu ITEM entry type - BARGRAPH */
typedef struct {
   SINT8                       *cur_value;
   SINT8                        min_value;
   SINT8                        max_value;
   UINT8                      inc;
   UINT8                      item_bargraph_properties;
}MENU_ITEM_ENTRY_BARGRAPH_T;

/* Structure Declaration for Menu ITEM */
typedef struct {
    UINT8              item_entry_type;
    UINT16             item_properties;
    UINT8              item_symbol;
    union {
       MENU_LABEL_T      str;
       HMI_LANG_SID      id;
    } label;
    union {
        void                        *foo;        /* Usefull for static declaration only */
        struct menu_def             *sub_menu;
        MENU_ITEM_ENTRY_BARGRAPH_T  *bargraph;
        BOOLEAN_T                   *toggle;
    } utype;
} MENU_ITEM_ENTRY_T;

/* Structure Definition for Menu */
typedef struct menu_def{
   UINT8                  disp_screen_id;
   UINT8                  total_display_lines;
   UINT8                  timeout;
   HMI_LANG_SID             menu_header_label;
   UINT16                 total_entry_nbr;
   UINT16                 properties;
   UINT8                  table_index;
   MENU_CALLBACK_T         *cb;
   MENU_CALLBACK_PRESNT_T  *presentation_cb;
   struct menu_def         *parent_menu;
   MENU_ITEM_ENTRY_T       *entry_array;
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
   MENU_CALLBACK_CNFG_T    *is_menu_item_enable_cb;
#endif
}MENU_DEF_T;

/* Structure Declaration for Button and Menu Action Mapping */
typedef struct {
   UINT8     menu_action;
   UINT16    button_action;
}MENU_BTN_TO_ACTIONS_MAP_T;

typedef struct {
   MENU_BTN_TO_ACTIONS_MAP_T const   *hmi_menu_map_actions_table;
   UINT8                              hmi_menu_total_btn_acns_mapped;
}MENU_BTN_ACNS_MAP_TABLE_T;

typedef struct {
   UINT8     menu_open_timer_id;
}MENU_INST_CONFIG_T;

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
extern MENU_DEF_T                 const  hmi_menu_const_struct_array_table[HMI_MENU_ID_COUNT];
extern MENU_BTN_ACNS_MAP_TABLE_T  const  hmi_menu_map_actions_table_ptr[HMI_MENU_TABLE_COUNT];
extern MENU_INST_CONFIG_T         const  hmi_menu_inst_config_table[NB_OF_MENU_INSTANCE];

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
EXTERN_pfx void hmi_menu_initialize(void);
EXTERN_pfx void hmi_menu_logic_Menu_Open(MENU_LIST_ID_T p_open_menu_id_e);
EXTERN_pfx void hmi_menu_logic_Menu_Close(MENU_LIST_ID_T p_close_menu_id_e);
EXTERN_pfx void hmi_menu_logic_Close_all_Menu(void);
EXTERN_pfx MENU_CONTROL_T  *hmi_menu_logic_Get_FocusMenu(void);
EXTERN_pfx BOOLEAN_T hmi_menu_logic_MenuIsOpen(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx UINT8 hmi_menu_logic_get_available_menu_instance(void);
EXTERN_pfx MENU_CONTROL_T  *hmi_menu_logic_get_menu_instance(MENU_LIST_ID_T p_menu_id_U8);
EXTERN_pfx BOOLEAN_T hmi_menu_logic_Is_CurrentMenuOpen(void);
EXTERN_pfx void hmi_menu_logic_open_timer_timeout(UINT8 fl_timer_id_U8);

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
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 18-Apr-2013
CDSID             : kcsarava
Traceability      : 
Change Description: hmi_menu_logic_Get_FocusMenu --> interface changed from
                    local to public
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 24-Apr-2013
CDSID             : kcsarava
Traceability      : for PR ID: 65051
Change Description: PR defect fixes
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
Change Description: Removed animation and fast scroll variable from MENU_INST_CONFIG_T
                    Removed line_fast_inc from MENU_CONTROL_T and timer ID macro.
                    Removed p_init_type_U8 in hmi_menu_initialize
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 14-May-2013
CDSID             : kcsarava
Traceability      : 
Change Description: to support config tool updates
-----------------------------------------------------------------------------*/

