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

 File Name        :  hmi_menu_core_01_types.h
 Module Short Name:  Menu Core
 VOBName          :  sw_hmi_ss\hmi_menu_core_01
 Author           :  csakthiv
 Description      :  This file contains the headers of Menu core logic
 Organization     :  Driver Information Software Section,
 Visteon Corporation
 ******************************************************************************/

#ifndef HMI_MENU_CORE_01_TYPES_H
#define HMI_MENU_CORE_01_TYPES_H

/*****************************************************************************
 *                                 Global Macro Definitions                   *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

/* Menu Item properties
 ** All the Below mentioned properties are to be
 ** set at Menu.MENU_ITEM_ENTRY_T ->item_properties while
 ** configuring the Menu item.
 */

#define MENU_ITEM_PRO_DISABLED              (0x0002U)
#define MENU_ITEM_PRO_LABEL_ID              (0x0004U)
#define MENU_ITEM_PRO_CONFIGURABLE          (0x0008U)
#define MENU_ITEM_PRO_RADIO_BTN             (0x0010U)
#define MENU_PRO_ITEM_STRING                (0x0020U)
#define MENU_ITEM_STRING_U8                 (0x0040U)
#define MENU_ITEM_PRO_TGL_WITH_MENU         (0x0080U)
#define MENU_ITEM_PRO_GRAY_OUT              (0x0100U)
#define MENU_ITEM_PRO_ACTION_BACK           (0x0200U)
#define MENU_ITEM_PRO_ACTION_EXIT           (0x0400U)

#define HMI_MENU_BTN_STATUS_IN               TRUE
#define HMI_MENU_BTN_STATUS_LONG             FALSE

#define MIN_VALUE(a,b)                       ((a<b)?a:b)

#define HMI_MENU_LOGIC_INST_INACTIVE          FALSE
#define HMI_MENU_LOGIC_INST_ACTIVE            TRUE

#define MENU_BTN_INVALID                     (0xFFFF)
#define HMI_MENU_EXIT_WITH_ANIM_MASK         (0x8000U)
 
/*
 ** Menu Properties
 ** All the Below mentioned properties are to be
 ** set at MENU_DEF_T ->properties while
 ** configuring the Menu.
 */
#define MENU_PRO_GOTO_PARENT_ON_ZERO_ENTRY   (0x0001U)
#define MENU_PRO_FAST_WINDOW_CHANGE          (0x0002U) /* MENU_PRO_NO_FAST_SCROLL should be enabled for this property. both prop. are mutually exclu.*/
#define MENU_PRO_LTD_WND_FOCUS_ENTRY         (0x0004U) /* Added for hyundai requirement where will not reach the end of the screen. Stops before last line. */
#define MENU_PRO_DYNAMIC                     (0x0008U)
#define MENU_PRO_SCROLL_ROLLING              (0x0010U)
#define MENU_PRO_DYNAMIC_FOCUS_LINE          (0x0020U) /* Focus will be skipped based on ITEM property MENU_ITEM_PRO_FOCUS_DISABLED*/
#define MENU_PRO_FOCUS_WRAPAROUND            (0x0040U)
#define MENU_PRO_EXTERNAL_SCROLL_ROLLING     (0x0080U)
#define MENU_PRO_NO_FAST_SCROLL              (0x0100U)
#define MENU_PRO_CLOCK_FORMAT                (0x0200U)
#define MENU_PRO_DISABLE_SELECTED_ENTRY      (0x0400U)
#define MENU_PRO_HISTORY_MENU                (0x0800U)
#define MENU_PRO_TXT_STATIC                  (0x1000U)
#define MENU_PRO_DISABLE_CURSOR              (0x2000U)
#define MENU_PRO_DISABLE_SCROLL_BAR          (0x4000U)
#define MENU_PRO_DYNAMIC_UPDATE              (0x8000U)

#define MENU_PRO_DYNAMIC_UPDATE_MASK         (~MENU_PRO_DYNAMIC_UPDATE)

#define MENU_ITEM_CONFIG_INACTIVE            (0x00U)
#define MENU_ITEM_CONFIG_ACTIVE              (0x01U)
#define MENU_ITEM_CONFIG_GRAY_OUT            (0x02U)
#define MENU_ITEM_CONFIG_FLOATING            (0x03U)

#define MENU_CORE_OPEN_TIMER                     1U
#define MENU_CORE_WAIT_TIMER                     2U
#define MENU_CORE_FASTSCROLL_CNT_INCR_TIMER      3U
#define MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER      4U
#define MENU_CORE_FASTSCROLL_CNT_START_TIMER     5U

#define HMI_MENU_SCREEN_ADD                      1U
#define HMI_MENU_SCREEN_REMOVE                   2U

/* possible configuration value for HMI_MENU_SET_FOCUS_ENTRY_REBUILD_GREYOUT Refer .cfg file*/
#define HMI_MENU_FOCUS_ENTRY_DECR_TILL_VALID     1
#define HMI_MENU_FOCUS_ENTRY_INCR_TILL_VALID     2
#define HMI_MENU_FOCUS_ENTRY_REBUILD_DEFUALT     3
/* possible configuration value for HMI_MENU_SET_FOCUS_ENTRY_RELOAD_GREYOUT Refer .cfg file*/
#define HMI_MENU_FOCUS_ENTRY_TO_ZER0             1 
#define HMI_MENU_FOCUS_ENTRY_RELOAD_DEFUALT      2


typedef LANG_SID_T HMI_LANG_SID;


#define   MENU_ACTION_UP                                   (0U)
#define   MENU_ACTION_UP_FAST                              (1U)
#define   MENU_ACTION_UP_RELEASE                           (2U)
#define   MENU_ACTION_DOWN                                 (3U)
#define   MENU_ACTION_DOWN_FAST                            (4U)
#define   MENU_ACTION_DOWN_RELEASE                         (5U)
#define   MENU_ACTION_LEFT                                 (6U)
#define   MENU_ACTION_LEFT_LONG                            (7U)
#define   MENU_ACTION_LEFT_RELEASE                         (8U)
#define   MENU_ACTION_RIGHT                                (9U)
#define   MENU_ACTION_RIGHT_LONG                           (10U)
#define   MENU_ACTION_RIGHT_RELEASE                        (11U)
#define   MENU_ACTION_OK_IN                                (12U)
#define   MENU_ACTION_OK_LONG                              (13U)
#define   MENU_ACTION_OK_RELEASE                           (14U) /* For OK/SET Button Alone  */
#define   MENU_MC_BUTTON_RELEASE                           (15U) /* For UP/DOWN/LEFT/RIGHT   */
#define   MENU_ACTION_BUTTON_0                             (16U)
#define   MENU_ACTION_BUTTON_1                             (17U)
#define   MENU_ACTION_BUTTON_2                             (18U)
#define   MENU_ACTION_BUTTON_3                             (19U)
#define   MENU_ACTION_BUTTON_4                             (20U)
#define   MENU_ACTION_BUTTON_5                             (21U)
#define   MENU_ACTION_BUTTON_6                             (22U)
#define   MENU_ACTION_BUTTON_7                             (23U)
#define   MENU_ACTION_BUTTON_8                             (24U)
#define   MENU_ACTION_BUTTON_9                             (25U)
#define   MENU_ACTION_BUTTON_STAR                          (26U)
#define   MENU_ACTION_BUTTON_SHARP                         (27U)
#define   MENU_ACTION_BUTTON_SK1                           (28U)
#define   MENU_ACTION_LONG_BUTTON_SK1                      (29U)
#define   MENU_ACTION_RELEASE_BUTTON_SK1                   (30U)
#define   MENU_ACTION_BUTTON_SK2                           (31U)
#define   MENU_ACTION_LONG_BUTTON_SK2                      (32U)
#define   MENU_ACTION_RELEASE_BUTTON_SK2                   (33U)
#define   MENU_ACTION_BUTTON_SK3                           (34U)
#define   MENU_ACTION_LONG_BUTTON_SK3                      (35U)
#define   MENU_ACTION_RELEASE_BUTTON_SK3                   (36U)
#define   MENU_ACTION_BUTTON_SK4                           (37U)
#define   MENU_ACTION_LONG_BUTTON_SK4                      (38U)
#define   MENU_ACTION_RELEASE_BUTTON_SK4                   (39U)
#define   MENU_ACTION_OPEN                                 (40U)
#define   MENU_ACTION_CLOSE                                (41U)
#define   MENU_ACTION_OPEN_FROM_PARENT                     (42U)
#define   MENU_ACTION_OPEN_FROM_CHILD                      (43U)
#define   MENU_ACTION_INCREMENT                            (44U)
#define   MENU_ACTION_INCREMENT_FAST                       (45U)
#define   MENU_ACTION_DECREMENT                            (46U)
#define   MENU_ACTION_DECREMENT_FAST                       (47U)
#define   MENU_ACTION_FORCED_CLOSE                         (48U)
#define   MENU_ACTION_COMPLETION                           (49U)
#define   MENU_ACTION_DATA_AVAIL                           (50U)
#define   MENU_ACTION_REINIT                               (51U)
#define   MENU_ACTION_NORMAL                               (52U)
#define   MENU_ACTION_FAST                                 (53U)
#define   MENU_ACTION_REBUILD                              (54U)
#define   MENU_ACTION_VALIDATE_BUTTON                      (55U)
#define   MENU_ACTION_LOST_FOCUS                           (56U)
#define   MENU_ACTION_GOT_FOCUS                            (57U)
#define   MENU_ACTION_RELOAD                               (58U)
#define   MENU_ACTION_NONE                                 (59U)
#define   MENU_ACTION_CLOSE_ON_TIMEOUT                     (60U)
#define   MENU_ACTION_DEACTIVATED                          (61U)
#define   MENU_ACTION_TOTAL                                (62U)

typedef UINT16 MENU_ACTION_T;
typedef UINT16 MENU_CB_RESULT_T;

#define   MENU_BTN_NONE                                    (0U)
#define   MENU_BTN_ABSORBED                                (1U)
#define   MENU_BTN_RESTART_TIMER_ABSORBED                  (2U)
#define   MENU_BTN_RESTART_TIMER_NONE                      (3U)
#define   MENU_BTN_ACTION                                  (4U)
#define   MENU_BTN_PROCESS_MENU                            (5U)
#define   MENU_BTN_CASCADED                                (6U)
#define   MENU_CB_ACTION_NONE                              (7U)
#define   MENU_CB_ACTION_EXIT                              (8U)
#define   MENU_CB_ACTION_COMPLETED                         (9U)
#define   MENU_CB_ACTION_WAIT                              (10U)
#define   MENU_CB_ACTION_ANIMATION_WAIT                    (11U)
#define   MENU_CB_ACTION_FASTUP                            (12U)
#define   MENU_CB_ACTION_FASTDOWN                          (13U)
#define   MENU_CB_ACTION_ANIMATION                         (14U)
#define   MENU_CB_ACTION_RELEASE_KEY                       (15U)
#define   MENU_CB_ACTION_DOWN                              (16U)
#define   MENU_CB_ACTION_UP                                (17U)
#define   MENU_CB_ACTION_RIGHT                             (18U)
#define   MENU_CB_ACTION_LEFT                              (19U)
#define   MENU_CB_ACTION_OK                                (20U)
#define   MENU_CB_ACTION_WIPER_LEFT_ANM                    (21U)
#define   MENU_CB_ACTION_WIPER_LEFT_WAIT_ANM               (22U)
#define   MENU_CB_ACTION_WIPER_RIGHT_ANM                   (23U)
#define   MENU_CB_ACTION_WIPER_RIGHT_WAIT_ANM              (24U)
#define   MENU_CB_ACTION_DOUBLE_WIPER_ANM                  (25U)
#define   MENU_CB_ACTION_DOUBLE_WIPER_WAIT_ANM             (26U)
#define   MENU_CB_ACTION_FOCUS_MOVE_UP_ANM                 (27U)
#define   MENU_CB_ACTION_FOCUS_MOVE_DOWN_ANM               (28U)
#define   MENU_CB_ACTION_WNDW_MOVE_UP_ANM                  (29U)
#define   MENU_CB_ACTION_WNDW_MOVE_UP_WAIT_ANM             (30U)
#define   MENU_CB_ACTION_WNDW_MOVE_DOWN_WAIT_ANM           (31U)
#define   MENU_CB_ACTION_WNDW_MOVE_DOWN_ANM                (32U)
#define   MENU_CB_ACTION_WRAP_RND_UP_ANM                   (33U)
#define   MENU_CB_ACTION_WRAP_RND_DOWN_ANM                 (34U)
#define   MENU_CB_ACTION_SCALE_ADJ_LEFT_ANM                (35U)
#define   MENU_CB_ACTION_SCALE_ADJ_RIGHT_ANM               (36U)
#define   MENU_CB_ACTION_REBUILD_ANM                       (37U)
#define   MENU_CB_ACTION_MAX                               (0xffffU)

/*
 ** The Menu State is set by the Application to indicate the
 ** Presentation so that it shall monitor the status and update
 ** the display accordingly.
 ** MENU_STATE_NORMAL     - Normal function and set as default
 ** MENU_STATE_WAIT_DATA  - In Wait state
 ** MENU_STATE_FAST_UP    - Fast Up Movement of items
 ** MENU_STATE_FAST_DOWN  - Fast Up Movement of items
 */

typedef UINT16 MENU_STATE_T;
#define   MENU_STATE_NORMAL            (0U)
#define   MENU_STATE_WAIT_DATA         (1U)
#define   MENU_STATE_ANIMATION         (2U)
#define   MENU_STATE_FAST              (3U)


/*
 ** Different item entry type
 ** MENU_ITEM_ENTRY_TYPE_LABEL    - Normal
 ** MENU_ITEM_ENTRY_TYPE_TOGGLE   - Item Toggle
 ** MENU_ITEM_ENTRY_TYPE_MENU     - Item having Submenu
 ** MENU_ITEM_ENTRY_TYPE_BARGRAPH - Bargraph
 ** MENU_ITEM_ENTRY_TYPE_EXE      - Special items
 */
#define MENU_ITEM_ENTRY_TYPE_LABEL      (UINT8)0
#define MENU_ITEM_ENTRY_TYPE_TOGGLE     (UINT8)1
#define MENU_ITEM_ENTRY_TYPE_MENU       (UINT8)2
#define MENU_ITEM_ENTRY_TYPE_BARGRAPH   (UINT8)3
#define MENU_ITEM_ENTRY_TYPE_EXE        (UINT8)4

/* Structure Definition for Display Menu which has control Parametrs */
typedef struct menu_t {
	MENU_LIST_ID_T menu_id;
	BOOLEAN inst_status_BOOL;
	BOOLEAN timer_status_BOOL;
	UINT8 menu_state;
	UINT16 displayed_lines;
	UINT8 line_fast_inc;
	UINT8 menu_level_U8;
	UINT16 focus_line_U16;
	UINT16 focus_entry_U16;
	UINT16 selected_entry_U16;
	UINT16 menu_properties;
	UINT16 menu_entry_nbr;
	LSH_STATE_ID_T prsnt_screen_id;   /* screen id received from LSH for presentation callback */
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
UINT16 menu_itm_absl_indx[HMI_MAX_MENU_ITEMS];
#endif
} MENU_CONTROL_T;

typedef struct {
UINT8 menu_open_timer_id;
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
UINT8 menu_wait_timer_id;
#endif
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
UINT8 menu_fastscroll_timer_id;
#endif
} MENU_INST_CONFIG_T;

typedef struct menu_anim_data{
UINT16 menu_anim_prev_focus_line_U16;
UINT16 menu_anim_curr_focus_line_U16;
MENU_LIST_ID_T menu_anim_prev_menu_id_E;
MENU_LIST_ID_T menu_anim_curr_menu_id_E;
UINT8 menu_anim_screen_action_U8;
LSH_STATE_ID_T menu_anim_prev_screen_id_U8;
LSH_STATE_ID_T menu_anim_curr_screen_id_U8;
UINT16 menu_anim_prev_focus_entry_U16;
UINT16 menu_anim_curr_focus_entry_U16;
} MENU_ANIM_DATA_T;

/* Call Back for Menu Button and Actions */
typedef MENU_CB_RESULT_T (MENU_CALLBACK_T)(MENU_ACTION_T p_action, MENU_CONTROL_T * p_ctrl,UINT16 p_button_command_U16);

typedef void (MENU_CALLBACK_PRESNT_T)(MENU_CONTROL_T * p_ctrl, UINT8 p_lsh_status_U8);

#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
#ifdef HMI_MENU_ITEM_CONFIG_WITH_APP_INDEX_FEATURE
typedef UINT8 (MENU_CALLBACK_CNFG_T)(UINT16 p_val, MENU_LIST_ID_T p_mnu_list_id);
#else
typedef UINT8 (MENU_CALLBACK_CNFG_T)(UINT16 p_val);
#endif
#endif

typedef UINT8 MENU_LABEL_CHAR;

typedef MENU_LABEL_CHAR* MENU_LABEL_T;

/* Structure Declaration for Menu ITEM entry type - BARGRAPH */
typedef struct {
SINT8 *cur_value;
SINT8 min_value;
SINT8 max_value;
UINT8 inc;
UINT8 item_bargraph_properties;
} MENU_ITEM_ENTRY_BARGRAPH_T;

typedef struct menu_def MENU_DEF_T;
/* Structure Declaration for Menu ITEM */
typedef struct {
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
LSH_STATE_ID_T item_screen_id_U8;
#endif
#ifdef HMI_MENU_CORE_CONTENT_MENU_ENABLED
MENU_CALLBACK_PRESNT_T *presentation_cb;
#endif
UINT8 item_entry_type;
UINT16 item_properties;
UINT8 item_symbol;
#ifdef HMI_MENU_ITEMS_WITH_TWO_ICONS
UINT8 item_symbol2;
#endif
union {
HMI_LANG_SID id;
MENU_LABEL_T str;
} label;
union {
void *foo; /* Usefull for static declaration only */
MENU_DEF_T const *sub_menu;
MENU_ITEM_ENTRY_BARGRAPH_T *bargraph;
BOOLEAN *toggle;
} utype;
} MENU_ITEM_ENTRY_T;

/* Structure Definition for Menu */
struct menu_def {
#ifndef HMI_MENU_CORE_CONTENT_MENU_ENABLED
GFX_MGR02_SCR_ELEM_ID disp_screen_id;
#endif
UINT8 total_display_lines;
UINT8 timeout;
UINT8 inst_no;
HMI_LANG_SID menu_header_label;
UINT16 total_entry_nbr;
UINT16 properties;
UINT8 table_index;
MENU_CALLBACK_T *cb;
#ifndef HMI_MENU_CORE_CONTENT_MENU_ENABLED
MENU_CALLBACK_PRESNT_T *presentation_cb;
#endif
MENU_DEF_T const *parent_menu;
union {
MENU_ITEM_ENTRY_T const *static_array;
MENU_ITEM_ENTRY_T *dynamic_array;
}entry_array;
#ifdef HMI_MENU_ITEM_CONFIG_FEATURE
MENU_CALLBACK_CNFG_T *is_menu_item_enable_cb;
#endif
};

typedef struct
{
  MENU_LIST_ID_T menu_id;
  MENU_ITEM_ENTRY_T const *entry_array;
}MENU_DYNAMIC_ENTRY_ARRAY_MAP_T;


/* Structure Declaration for Button and Menu Action Mapping */
typedef struct {
  MENU_ACTION_T menu_action;
  UINT16 button_action;
} MENU_BTN_TO_ACTIONS_MAP_T;

typedef struct {
  MENU_BTN_TO_ACTIONS_MAP_T const *hmi_menu_map_actions_table;
  UINT8 hmi_menu_total_btn_acns_mapped;
} MENU_BTN_ACNS_MAP_TABLE_T;

#ifdef HMI_MENU_LSH_FREEZE_CONFIG
typedef struct {
  LSH_STATE_ID_T freeze_disp_screen_id;
  MENU_LIST_ID_T freeze_menu_id;
} MENU_LSH_FREEZE_T;
#endif

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
Date              : 6-Mar-2014
CDSID             : csakthiv
Traceability      : Initial version.
Change Description: File created to avoid some of the compiler error due to inclustion of file.
 -----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 28-Mar-2014
CDSID             : csakthiv
Traceability      : Bug 125
Change Description: value for HMI_MENU_EXIT_WITH_ANIM_MASK is defined based on the configuration in tool. If UINT8(if anim id < 125), then BIT7 used as
                    anim mask and if UINT16(if anim id > 125) then BIT15 is used as anim mask.This is made configurable so that there is no 
					need to make changes in existing program. 
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-May-2014
CDSID             : csakthiv
Traceability      : Bug
Change Description: MENU_ACTION_DEACTIVATED included as action to pass the information that screen is closed
                    by view manager due to priority conflict. Application can action based on their requirement
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 10-12-14
CDSID             : csakthiv
Traceability      : Task id:254797
Change Description: If item is greyedout on rebuild, then menu core will move to next valid item.
                    If item is greyout on reload, then menu core will set focus entry to first item.
					Both the above requirement is applied only when configured in .cfg.
					Refer $.cfg file for configuration details.Refer attached excel in taskid for requirement
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  10-FEB-15  
By                :  KKUBENDI
Traceability      :
Change Description:  Compiler warning fix for Honda THAA..
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  03-Mar-15
By                :  arajase2
Traceability      :  Issue Fix - C296731: Dynamic menus do not close for ok button press
Change Description:  MENU_CB_RESULT_T type changed from UINT8 to UINT16
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  07-Sep-15
By                :  arajase2
Change Description:  HMI_MENU_EXIT_WITH_ANIM_MASK is moved from autogenerated code to types.h
as this is not configurable property
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

MENU_DEF_T structure

1. MENU_ITEM_ENTRY_T *entry_array; member is changed as
union {
MENU_ITEM_ENTRY_T const *static_array;
MENU_ITEM_ENTRY_T *dynamic_array;
}item_entry_array;
#define entry_array item_entry_array.static_array

By default entry_array will points to static entry array. Application will get compilation errors
to update dynamic menu entries. In this case, application code needs to be changed to use 
item_entry_array.dynamic_array

2. struct menu_def *parent_menu; is changed as MENU_DEF_T const *parent_menu; - Parent menu will point to
the const array. So here const is added and type definition for struct menu_def is moved at the beginning of
the file

MENU_DYNAMIC_ENTRY_ARRAY_MAP_T;
structure member   MENU_ITEM_ENTRY_T *entry_array; is renamed as dynamic_entry_array to avoid 
conflicts with the entry_array macro

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
