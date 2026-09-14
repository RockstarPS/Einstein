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
** Name:           hmi_menu_presentation.h
**
** Description:
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_MENU_PRESENTATION_H
#define HMI_MENU_PRESENTATION_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_language_interface.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef HMI_MENU_PRESENTATION_C
#define Extern_pfx 
#else
#define Extern_pfx extern
#endif

#define MENU_4LINE_NB_LAYOUTS (1)
#define MENU_4LINE_NB_LINES   (6) /* additional line is for scroll animation */
#define MENU_WITH_FOUR_ITEMS             ((UINT8)4)


#define GFX_MENU_NO_ICON               0xFF   /*  Always last */

typedef enum {
    GFX_MENU_AUX_ICON,
    GFX_MENU_PHONE_ICON,
    GFX_MENU_MENU_ICON,
    GFX_MENU_SUBMENU_ARROW_ICON
}GFX_MENU_ICON_TYPES;


/*4-Line Menu Layout Ids*/
typedef enum
{
    GFX_MENU_LAYOUT_SCR_MENU    /* GFX_L2_4LINE_LIST_CONENT_ROOT_MENU      */
}MENU_APP_LAYOUT;

enum
{
  MENU_CURSOR_TYPE_FOUR_LINE_MENU,
  MENU_CURSOR_TYPE_INVALID
};

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
Extern_pfx void hmi_menu_prn_hndlr(struct menu_t *hmi_menu_presentation, UINT8_T p_lsh_status_U8);
Extern_pfx UINT8 hmi_menu_vehicle_settings_item_cb(UINT8 p_entry_val_U8);
Extern_pfx UINT8 hmi_menu_common_item_cb(UINT8 p_entry_val_U8);
#undef Extern_pfx
#endif
