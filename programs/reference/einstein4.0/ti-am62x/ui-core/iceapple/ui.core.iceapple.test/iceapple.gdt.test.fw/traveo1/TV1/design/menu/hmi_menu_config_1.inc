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
** Name:           hmi_menu_config_1.inc
**
** Description:    File contains MENU_ITEM_ENTRY_T and MENU_DEF_T entires.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/


#ifndef HMI_MENU_CONFIG_1_INC
#define HMI_MENU_CONFIG_1_INC

#include "hmi_menu_def_1.inc"
#include "hmi_language_identifiers.h"
#include "ui_core_iceapple.cfg"
#include "hmi_menu_config_if.h"




UI_IA_DATA_PREFIX const MENU_INST_CONFIG_T hmi_menu_inst_config_table[NB_OF_MENU_INSTANCE] =
{
     {
       eUSMMenuTimeoutTimer
     },
     {
       eUSMMenuTimeoutTimer
     }
};
UI_IA_DATA_PREFIX const UINT8 hmi_menu_actions_allowed_in_anim[HMI_MENU_ACTION_IN_ANIM_COUNT] =
{
	MENU_ACTION_UP,
	MENU_ACTION_DOWN,
	MENU_ACTION_LEFT,
	MENU_ACTION_RIGHT
};

static UI_IA_DATA_PREFIX MENU_BTN_TO_ACTIONS_MAP_T const hmi_menu_map_actions_1[]=
{
	{
		MENU_ACTION_UP,               			UP_IN                         
	},
	{
		MENU_ACTION_DOWN,             			DOWN_IN                       
	},
	{
		MENU_ACTION_LEFT,             			LEFT_IN                       
	},
	{
		MENU_ACTION_RIGHT,            			RIGHT_IN                      
	},
	{
		MENU_ACTION_OK_IN,            			OK_IN                         
	}
};

UI_IA_DATA_PREFIX MENU_BTN_ACNS_MAP_TABLE_T const hmi_menu_map_actions_table_ptr[HMI_MENU_TABLE_COUNT]=
{
	{hmi_menu_map_actions_1, ((sizeof(hmi_menu_map_actions_1))/(sizeof(hmi_menu_map_actions_1[0]))) }
};
static UI_IA_DATA_PREFIX MENU_ITEM_ENTRY_T const hmi_mnu_tripcomp_eco_group_item_entries[TRIPCOMP_ECO_GROUP_MENU_ITEMS] =
{
    {
     GFX_SCR_STD_TRIP,/* Display Screen ID */
     hmi_menu_tc_group_presentation_handler,/* Presentation Callback */
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     MENU_ITEM_PRO_CONFIGURABLE,/* Properties */
     NULL_PARAM,/* Symbol */
     {
      (HMI_LANG_SID)NULL_PARAM/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    }
};

static UI_IA_DATA_PREFIX MENU_ITEM_ENTRY_T const hmi_mnu_root_item_entries[ROOT_MENU_ITEMS] =
{
    {
     GFX_SCR_ROOT_MENU,/* Display Screen ID */
     hmi_menu_root_presentation_handler,/* Presentation Callback */
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     MENU_ITEM_PRO_CONFIGURABLE,/* Properties */
     NULL_PARAM,/* Symbol */
     {
      (HMI_LANG_SID)NULL_PARAM/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    }
};

static UI_IA_DATA_PREFIX MENU_APP_ITEM_ENTRY_T const hmi_mnu_tripcomp_eco_group_app_item_entries[TRIPCOMP_ECO_GROUP_MENU_ITEMS] =
{
    {
      NULL_PARAM
    }
};

static UI_IA_DATA_PREFIX MENU_APP_ITEM_ENTRY_T const hmi_mnu_root_app_item_entries[ROOT_MENU_ITEMS] =
{
    {
      NULL_PARAM
    }
};

UI_IA_DATA_PREFIX MENU_DEF_T const hmi_menu_const_struct_array_table[TOTAL_MENU_ID] =
{
     {
      NO_DISP_LINES_1,/* Number of Lines */
      MENU_TIMER_0S,/* menu Timeout */
      HMI_MENU_INSTANCE_0, /* Menu Instance */
      NULL_PARAM,/* Header Label */
      TRIPCOMP_ECO_GROUP_MENU_ITEMS,/* Number of Entries in a menu */
      MENU_PRO_FOCUS_WRAPAROUND | MENU_PRO_HISTORY_MENU,/* menu Properties */
      MENU_BTN_TABLE_DEFAULT,/* Menu Map Actions Table ID */
      hmi_menu_tc_group_callback,/* menu CallBack Function */
      NULL,/* Parent menu */
      {
#if defined(__STDC_VERSION__ ) &&  (__STDC_VERSION__ >= 199901L)
       .static_array = (MENU_ITEM_ENTRY_T const *) hmi_mnu_tripcomp_eco_group_item_entries/* menu Entry Array */
#else
       (MENU_ITEM_ENTRY_T *) hmi_mnu_tripcomp_eco_group_item_entries/* menu Entry Array */
#endif
      },
      hmi_menu_tc_group_items_config_callback/* menu Configuration CallBack Function */
     },
     {
      NO_DISP_LINES_1,/* Number of Lines */
      MENU_TIMER_0S,/* menu Timeout */
      HMI_MENU_INSTANCE_1, /* Menu Instance */
      NULL_PARAM,/* Header Label */
      ROOT_MENU_ITEMS,/* Number of Entries in a menu */
      MENU_PRO_FOCUS_WRAPAROUND | MENU_PRO_HISTORY_MENU,/* menu Properties */
      MENU_BTN_TABLE_DEFAULT,/* Menu Map Actions Table ID */
      hmi_menu_root_callback,/* menu CallBack Function */
      NULL,/* Parent menu */
      {
#if defined(__STDC_VERSION__ ) &&  (__STDC_VERSION__ >= 199901L)
       .static_array = (MENU_ITEM_ENTRY_T const *) hmi_mnu_root_item_entries/* menu Entry Array */
#else
       (MENU_ITEM_ENTRY_T *) hmi_mnu_root_item_entries/* menu Entry Array */
#endif
      },
      hmi_menu_root_items_config_callback/* menu Configuration CallBack Function */
     }
};

UI_IA_DATA_PREFIX MENU_APP_DEF_T const hmi_app_menu_const_struct_array_table[TOTAL_MENU_ID] =
{
     {
      {
      	(MENU_APP_ITEM_ENTRY_T const *) hmi_mnu_tripcomp_eco_group_app_item_entries
      }
     },
     {
      {
      	(MENU_APP_ITEM_ENTRY_T const *) hmi_mnu_root_app_item_entries
      }
     }
};

UI_IA_DATA_PREFIX MENU_DYNAMIC_ENTRY_ARRAY_MAP_T const hmi_menu_const_dynamic_menu_table[TOTAL_DYNAMIC_MENU_ITEMS] = 
{
	{ TOTAL_MENU_ID,                           NULL }
};
#endif
