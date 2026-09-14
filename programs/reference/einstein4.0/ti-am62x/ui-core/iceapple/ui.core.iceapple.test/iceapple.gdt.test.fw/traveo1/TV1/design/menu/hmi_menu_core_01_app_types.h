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
** Name:           hmi_menu_core_01_app_types_0.h
**
** Description:    File contains application specific data structures.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/


/* Structure Declaration for Menu ITEM with App entries*/
typedef struct {
	UINT8 menu_app_item_cb_id;
}MENU_APP_ITEM_ENTRY_T;

/* Structure Declaration for Menu Definitions with App entries */
typedef struct menu_app_def{
	union
	{
		MENU_APP_ITEM_ENTRY_T const *static_array;
		MENU_APP_ITEM_ENTRY_T *dynamic_array;
	}entry_array;
}MENU_APP_DEF_T;

/* External declaration of application specific structure table*/
extern MENU_APP_DEF_T const hmi_app_menu_const_struct_array_table[TOTAL_MENU_ID];

