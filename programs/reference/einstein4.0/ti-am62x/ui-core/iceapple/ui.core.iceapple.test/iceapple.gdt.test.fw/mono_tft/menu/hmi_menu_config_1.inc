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
#include "hmi_menu_core_01_logic.h"
#include "hmi_menu_presentation.h"




UI_IA_DATA_PREFIX const MENU_INST_CONFIG_T hmi_menu_inst_config_table[NB_OF_MENU_INSTANCE] =
{
     {
       HMI_MENU_OPEN_TIMER_ID,
       HMI_MENU_WAIT_TIMER_ID
     }
};
UI_IA_DATA_PREFIX const UINT8 hmi_menu_actions_allowed_in_anim[HMI_MENU_ACTION_IN_ANIM_COUNT] =
{
	MENU_ACTION_TOTAL
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
static UI_IA_DATA_PREFIX MENU_ITEM_ENTRY_T const hmi_mnu_root_item_entries[ROOT_MENU_ITEMS] =
{
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_AUX_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_1052/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_PHONE_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_1053/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_MENU,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_MENU_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_13/* Label */
     },
     {
#if defined(__STDC_VERSION__ ) && (__STDC_VERSION__ >= 199901L)
      .sub_menu = (MENU_DEF_T const *)&hmi_menu_const_struct_array_table[SETTINGS_MENU_ID]/* Submenu Link */
#else
      (void *)&hmi_menu_const_struct_array_table[SETTINGS_MENU_ID]/* Submenu Link */
#endif
     }
    }
};

static UI_IA_DATA_PREFIX MENU_ITEM_ENTRY_T const hmi_mnu_settings_item_entries[SETTINGS_MENU_ITEMS] =
{
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_303/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_MENU,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_309/* Label */
     },
     {
#if defined(__STDC_VERSION__ ) && (__STDC_VERSION__ >= 199901L)
      .sub_menu = (MENU_DEF_T const *)&hmi_menu_const_struct_array_table[VEHICLE_SETTINGS_MENU_ID]/* Submenu Link */
#else
      (void *)&hmi_menu_const_struct_array_table[VEHICLE_SETTINGS_MENU_ID]/* Submenu Link */
#endif
     }
    }
};

static UI_IA_DATA_PREFIX MENU_ITEM_ENTRY_T const hmi_mnu_vehicle_settings_item_entries[VEHICLE_SETTINGS_MENU_ITEMS] =
{
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_1024/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_920/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_1461/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    },
    {
     MENU_ITEM_ENTRY_TYPE_LABEL,/* Menu Type */
     NULL_PARAM,/* Properties */
     GFX_MENU_NO_ICON,/* Symbol */
     {
      (HMI_LANG_SID)SID_TxtID_1_1121/* Label */
     },
     {
      NULL/* Submenu Link */
     }
    }
};

UI_IA_DATA_PREFIX MENU_DEF_T const hmi_menu_const_struct_array_table[TOTAL_MENU_ID] =
{
     {
      GFX_SCR_MENU,/* Screen ID */
      NO_DISP_LINES_4,/* Number of Lines */
      MENU_TIMER_30S,/* menu Timeout */
      HMI_MENU_INSTANCE_0, /* Menu Instance */
      SID_TxtID_1_14,/* Header Label */
      ROOT_MENU_ITEMS,/* Number of Entries in a menu */
      MENU_PRO_NO_FAST_SCROLL,/* menu Properties */
      MENU_BTN_TABLE_DEFAULT,/* Menu Map Actions Table ID */
      NULL,/* menu CallBack Function */
      hmi_menu_prn_hndlr,/* Presentation CallBack Function */
      NULL,/* Parent menu */
      {
#if defined(__STDC_VERSION__ ) &&  (__STDC_VERSION__ >= 199901L)
       .static_array = (MENU_ITEM_ENTRY_T const *) hmi_mnu_root_item_entries/* menu Entry Array */
#else
       (MENU_ITEM_ENTRY_T *) hmi_mnu_root_item_entries/* menu Entry Array */
#endif
      },
      NULL/*  menu Configuration CallBack Function*/
     },
     {
      GFX_SCR_MENU,/* Screen ID */
      NO_DISP_LINES_4,/* Number of Lines */
      MENU_TIMER_30S,/* menu Timeout */
      HMI_MENU_INSTANCE_0, /* Menu Instance */
      SID_TxtID_1_13,/* Header Label */
      SETTINGS_MENU_ITEMS,/* Number of Entries in a menu */
      MENU_PRO_NO_FAST_SCROLL | MENU_PRO_DISABLE_SELECTED_ENTRY,/* menu Properties */
      MENU_BTN_TABLE_DEFAULT,/* Menu Map Actions Table ID */
      NULL,/* menu CallBack Function */
      hmi_menu_prn_hndlr,/* Presentation CallBack Function */
      (MENU_DEF_T const *)&hmi_menu_const_struct_array_table[ROOT_MENU_ID],/* Parent menu */
      {
#if defined(__STDC_VERSION__ ) &&  (__STDC_VERSION__ >= 199901L)
       .static_array = (MENU_ITEM_ENTRY_T const *) hmi_mnu_settings_item_entries/* menu Entry Array */
#else
       (MENU_ITEM_ENTRY_T *) hmi_mnu_settings_item_entries/* menu Entry Array */
#endif
      },
      NULL/*  menu Configuration CallBack Function*/
     },
     {
      GFX_SCR_MENU,/* Screen ID */
      NO_DISP_LINES_4,/* Number of Lines */
      MENU_TIMER_30S,/* menu Timeout */
      HMI_MENU_INSTANCE_0, /* Menu Instance */
      SID_TxtID_1_309,/* Header Label */
      VEHICLE_SETTINGS_MENU_ITEMS,/* Number of Entries in a menu */
      MENU_PRO_NO_FAST_SCROLL | MENU_PRO_DISABLE_SELECTED_ENTRY,/* menu Properties */
      MENU_BTN_TABLE_DEFAULT,/* Menu Map Actions Table ID */
      NULL,/* menu CallBack Function */
      hmi_menu_prn_hndlr,/* Presentation CallBack Function */
      (MENU_DEF_T const *)&hmi_menu_const_struct_array_table[SETTINGS_MENU_ID],/* Parent menu */
      {
#if defined(__STDC_VERSION__ ) &&  (__STDC_VERSION__ >= 199901L)
       .static_array = (MENU_ITEM_ENTRY_T const *) hmi_mnu_vehicle_settings_item_entries/* menu Entry Array */
#else
       (MENU_ITEM_ENTRY_T *) hmi_mnu_vehicle_settings_item_entries/* menu Entry Array */
#endif
      },
      NULL/*  menu Configuration CallBack Function*/
     }
};

UI_IA_DATA_PREFIX MENU_DYNAMIC_ENTRY_ARRAY_MAP_T const hmi_menu_const_dynamic_menu_table[TOTAL_DYNAMIC_MENU_ITEMS] = 
{
	{ TOTAL_MENU_ID,                           NULL }
};
#endif
