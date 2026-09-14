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
** Name:           hmi_menu_presentation.c
**
** Description:
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_MENU_PRESENTATION_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_language_interface.h"
#include "hmi_menu_core_01_logic.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_cfg.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_menu_presentation.h"
#include "hmi_menu_config_1.inc"
#include <time.h>
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

typedef struct
{
  SINT16 textx;
  SINT16 texty;
  UINT32_T text; /*GFX_MGR02_DTEXT_ID */
  UINT32_T text_anim; /*GFX_MGR02_ANIM_ELEM_ID*/

  UINT32_T icon; /*GFX_MGR02_DIMG_ELEM_ID*/
  UINT32_T arrow; /* GFX_MGR02_DIMG_ELEM_ID*/
}MENU_1LINE_T;

typedef struct
{
  UINT16_T  sel_x;
  UINT16_T  sel_y;
  UINT16_T  cur_x;
  UINT16_T  cur_y;
}MENU_LINE_CURSOR_T;


/*Note:If Inserting or Removing line in lc_4line_cursor[]
please Update the macro LC_4LINE_CURSOR_ENTRIES value*/
static const MENU_LINE_CURSOR_T lc_4line_cursor[] =
{
  {32 , 58,32 , 58},
  {32 ,107,32 ,107},
  {32 ,156,32 ,156},
  {32 ,205,32 ,205},
  {500,300,500,300}
};

static const MENU_1LINE_T four_line_menu_config[MENU_4LINE_NB_LAYOUTS][MENU_4LINE_NB_LINES] =
{
  {
    {78    ,   70   , GFX_TXT_MENU_VC_C1, GFX_TXT_MENU_VC_C1_ANIM, GFX_IMG_VC_MENU_G1, GFX_IMG_ARROW_MENU_A1},
    {78    ,  119   , GFX_TXT_MENU_VC_C2, GFX_TXT_MENU_VC_C2_ANIM, GFX_IMG_VC_MENU_G2, GFX_IMG_ARROW_MENU_A2},
    {78    ,  168   , GFX_TXT_MENU_VC_C3, GFX_TXT_MENU_VC_C3_ANIM, GFX_IMG_VC_MENU_G3, GFX_IMG_ARROW_MENU_A3},
    {78    ,  217   , GFX_TXT_MENU_VC_C4, GFX_TXT_MENU_VC_C4_ANIM, GFX_IMG_VC_MENU_G4, GFX_IMG_ARROW_MENU_A4},
    {78    ,  268   , GFX_TXT_MENU_VC_C5, GFX_TXT_MENU_VC_C5_ANIM, GFX_IMG_VC_MENU_G5, GFX_IMG_ARROW_MENU_A5},
    {78    ,   12   , GFX_TXT_MENU_VC_C6, GFX_TXT_MENU_VC_C6_ANIM, GFX_IMG_VC_MENU_G6, GFX_IMG_ARROW_MENU_A6}
  }
};


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

void hmi_menu_prn_clear_all_lines(struct menu_t * hmi_menu_presentation, UINT16 fl_layout );
void hmi_menu_prn_update_all_lines(struct menu_t *hmi_menu_presentation,UINT16 fl_layout);
void hmi_menu_prn_update_icon(struct menu_t *hmi_menu_presentation, MENU_1LINE_T const * fl_menu_line_config_U8, UINT16_T fl_menu_item_absl_index_U16);
void hmi_menu_prn_update_text(struct menu_t *hmi_menu_presentation, MENU_1LINE_T const * fl_menu_line_config_U8, UINT16_T fl_menu_item_abls_indx_U16);
void hmi_menu_prn_update_one_line(struct menu_t *hmi_menu_presentation, UINT8 menu_line_no, UINT16_T fl_layout);
void hmi_menu_prn_time(void);
void hmi_menu_prn_update_cursor(UINT8_T fl_cursor_type_U8, UINT16 fl_menu_focus_line_U8);
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:    hmi_menu_prn_hndlr
** Visibility:       global
** Description:      This is the function to display the menu screen in the
**                   Presentation.
** Invocation:       Invoked by application when ever menu screen
**                    needs to be displayed or updated
** Inputs/Outputs:   p_lsh_status_U8 indicates the activate or deactivate or refresh.
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_hndlr(struct menu_t *hmi_menu_presentation, UINT8_T p_lsh_status_U8)
{
  if((p_lsh_status_U8 != LSH_DEACTIVATED_STATUS) && (hmi_menu_presentation !=NULL))
  {
	  UINT8 temp = hmi_menu_logic_get_active_menu_instance_ptr(3);
	  hmi_menu_logic_Menu_Rebuild(0);
    hmi_menu_prn_update_all_lines(hmi_menu_presentation, GFX_MENU_LAYOUT_SCR_MENU);
    /*Update Time*/
    hmi_menu_prn_time();
    /* Update Header with Header Label*/
    (void)hmi_gfx_mgr02_if_set_sid(GFX_TXT_MENU_HEADER, 
      (UINT16)hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].menu_header_label);
    (void)hmi_gfx_mgr02_if_set_screen(hmi_menu_presentation->prsnt_screen_id, 1);
  }
  else
  {
    (void)hmi_gfx_mgr02_if_set_screen(hmi_menu_presentation->prsnt_screen_id, 0);
  }
}

/*============================================================================
** Function Name:    hmi_menu_prn_update_all_lines
** Visibility:       local
** Description:      This is the  function to display the menu elements
**
** Invocation:       Invoked by presentation when ever menu elements
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_update_all_lines(struct menu_t *hmi_menu_presentation, UINT16_T fl_layout)
{
  UINT8 gfxAnim;
  UINT8_T  fl_menu_display_lines_U8 = hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].total_display_lines;

  hmi_menu_prn_clear_all_lines(hmi_menu_presentation, fl_layout);
  for(gfxAnim = 0; gfxAnim < fl_menu_display_lines_U8; gfxAnim++)
  {
    if(gfxAnim < hmi_menu_presentation->menu_entry_nbr)
    {
      /* to update each line of menu along with selection marker*/
      hmi_menu_prn_update_one_line(hmi_menu_presentation, gfxAnim, fl_layout);

      /*to update cursor or focus line of menu*/
      if(gfxAnim == hmi_menu_presentation->focus_line_U16)
      {
        if((hmi_menu_presentation->menu_properties & MENU_PRO_DISABLE_CURSOR) == 0)
        {
          hmi_menu_prn_update_cursor(MENU_CURSOR_TYPE_FOUR_LINE_MENU, hmi_menu_presentation->focus_line_U16);
        }
        else
        {
          /* invalid value for cursor to disable it */
          hmi_menu_prn_update_cursor(MENU_CURSOR_TYPE_INVALID,4);
        }
      }
    }
  }
}

/*============================================================================
** Function Name:    hmi_menu_prn_clear_all_lines
** Visibility:       local
** Description:      This is the  function to clear the menu elements
**
** Invocation:       Invoked by presentation when ever menu elements
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_clear_all_lines(struct menu_t * hmi_menu_presentation, UINT16 fl_layout )
{
  UINT16_T gfxAnim;
  if((hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].total_display_lines) <= MENU_WITH_FOUR_ITEMS)
  {
    if (four_line_menu_config[fl_layout] != NULL)
    { 
      for(gfxAnim = 0; gfxAnim < MENU_4LINE_NB_LINES; gfxAnim++)
      {
        (void)hmi_gfx_mgr02_if_select_dimage(four_line_menu_config[fl_layout][gfxAnim].icon, GFX_MENU_NO_ICON);
        (void)hmi_gfx_mgr02_if_select_dimage(four_line_menu_config[fl_layout][gfxAnim].arrow, GFX_MENU_NO_ICON);
        (void)hmi_gfx_mgr02_if_set_sid(four_line_menu_config[fl_layout][gfxAnim].text,SID_TxtID_1_Blank);
      }
    }
  }
}

/*============================================================================
** Function Name:    hmi_menu_prn_update_one_line
** Visibility:       local
** Description:      This is the  function to display the menu elements
**
** Invocation:       Invoked by presentation when ever menu elements
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_update_one_line(struct menu_t *hmi_menu_presentation, UINT8 menu_line_no, UINT16_T fl_layout)
{
  UINT16 fl_displayed_lines_U16 = 0;
  MENU_1LINE_T const * fl_menu_line_config_U8 = NULL;
  UINT16 fl_menu_item_abls_indx_U16 = 0;

  UINT16 fl_property_U16 = 0;

  fl_property_U16 = hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].properties;

  if(((fl_property_U16 & MENU_PRO_TXT_STATIC) != (UINT16)0) ||
    ((fl_property_U16 & MENU_PRO_DYNAMIC) == (UINT16)0))
  {
    fl_displayed_lines_U16 = hmi_menu_presentation->focus_entry_U16 - hmi_menu_presentation->focus_line_U16;
  }
  if((fl_property_U16 & MENU_PRO_DYNAMIC) == (UINT16)0)
  {
    fl_menu_item_abls_indx_U16 = hmi_menu_presentation->menu_itm_absl_indx[fl_displayed_lines_U16 + menu_line_no];
  }
  else
  {
    fl_menu_item_abls_indx_U16 = (fl_displayed_lines_U16 + menu_line_no);
  }
  if((hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].total_display_lines) <= MENU_WITH_FOUR_ITEMS)
  {
    fl_menu_line_config_U8 = &four_line_menu_config[fl_layout][menu_line_no];
  }

  if(fl_menu_line_config_U8 != NULL)
  {
    hmi_menu_prn_update_icon(hmi_menu_presentation, fl_menu_line_config_U8, fl_menu_item_abls_indx_U16);
    hmi_menu_prn_update_text(hmi_menu_presentation, fl_menu_line_config_U8, fl_menu_item_abls_indx_U16);
  }
}

/*============================================================================
** Function Name:    hmi_menu_prn_update_icon
** Visibility:       local
** Description:      This is the  function to display the menu icon for each line.
**
** Invocation:       Invoked by presentation when ever menu cursor
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.       
**==========================================================================*/
void hmi_menu_prn_update_icon(struct menu_t *hmi_menu_presentation, MENU_1LINE_T const * fl_menu_line_config_U8, UINT16_T fl_menu_item_absl_index_U16)
{
  UINT8 entryType = hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_absl_index_U16].item_entry_type;
  (void)hmi_gfx_mgr02_if_select_dimage(fl_menu_line_config_U8->icon, hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_absl_index_U16].item_symbol);
  if(entryType == MENU_ITEM_ENTRY_TYPE_MENU)
  {
    (void)hmi_gfx_mgr02_if_select_dimage(fl_menu_line_config_U8->arrow, 0);
  }
  else
  {
    (void)hmi_gfx_mgr02_if_select_dimage(fl_menu_line_config_U8->arrow, GFX_MENU_NO_ICON);
  }   
}

/*============================================================================
** Function Name:    hmi_menu_prn_update_text
** Visibility:       local
** Description:      This is the  function to display the menu cursor
**
** Invocation:       Invoked by presentation when ever menu cursor
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
*==========================================================================*/
void hmi_menu_prn_update_text(struct menu_t *hmi_menu_presentation, MENU_1LINE_T const * fl_menu_line_config_U8,
                              UINT16_T fl_menu_item_abls_indx_U16)
{
  /*Update text of current line*/
  (void)hmi_gfx_mgr02_if_set_obj_pos_x(fl_menu_line_config_U8->text_anim, fl_menu_line_config_U8->textx);
  (void)hmi_gfx_mgr02_if_set_obj_pos_y(fl_menu_line_config_U8->text_anim, fl_menu_line_config_U8->texty);
  if((hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_abls_indx_U16].item_properties & MENU_ITEM_STRING_U8) != 0 )
  {
  }
  else if((hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_abls_indx_U16].item_properties & MENU_PRO_ITEM_STRING) == 0)  /* if 0 then it is SID*/
  {
    (void)hmi_gfx_mgr02_if_set_sid(fl_menu_line_config_U8->text, (UINT16)hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_abls_indx_U16].label.str);
  }
  else if((hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_abls_indx_U16].item_properties & MENU_PRO_ITEM_STRING) != 0 )
  {
    (void)hmi_gfx_mgr02_if_set_text(fl_menu_line_config_U8->text, (void*)hmi_menu_const_struct_array_table[hmi_menu_presentation->menu_id].entry_array.static_array[fl_menu_item_abls_indx_U16].label.str);
  }
  else
  {
    (void)hmi_gfx_mgr02_if_set_sid(fl_menu_line_config_U8->text, SID_TxtID_1_Blank);
  }
}

void hmi_menu_vehicle_settings_item_cb()
{
}

void hmi_menu_common_item_cb()
{
}


/*============================================================================
** Function Name:    hmi_menu_prn_update_cursor
** Visibility:       local
** Description:      This is the  function to display the menu cursor
**
** Invocation:       Invoked by presentation when ever menu cursor
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_update_cursor(UINT8_T fl_cursor_type_U8, UINT16 fl_menu_focus_line_U8)
{
  if(fl_cursor_type_U8 == MENU_CURSOR_TYPE_FOUR_LINE_MENU)
  {
    (void)hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_MENU_FOCUS_ANIM, lc_4line_cursor[fl_menu_focus_line_U8].cur_x);
    (void)hmi_gfx_mgr02_if_set_obj_pos_y(GFX_IMG_MENU_FOCUS_ANIM, lc_4line_cursor[fl_menu_focus_line_U8].cur_y);
  }
}


/*============================================================================
** Function Name:    hmi_menu_prn_time
** Visibility:       local
** Description:      This is the  function to display the time
**
** Invocation:       Invoked by presentation when ever time
**                   needs to be displayed or updated
** Inputs/Outputs:   NA
** Critical Section: None.
**==========================================================================*/
void hmi_menu_prn_time(void)
{
  HMI_CHAR current_time[30];

  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  (void)HMI_SNPRINTF(current_time, 30, HMI_TEXT("%2lu:%02lu"), \
  (UINT32)timeinfo->tm_hour, (UINT32)timeinfo->tm_min);
  (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_MENU_TIME, current_time);
}

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
 ** CMS Rev 1.0      19-Mar-2015    arajase2
 ** Creation.
 **==========================================================================*/

