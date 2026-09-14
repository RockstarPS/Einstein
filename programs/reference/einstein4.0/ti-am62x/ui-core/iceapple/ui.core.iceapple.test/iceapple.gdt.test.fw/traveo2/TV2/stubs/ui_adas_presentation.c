/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2022. Visteon Corporation owns all rights to this work and
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
** File Name            :   ui_digital_speed_presentation.c
** Module Short Name    :   ui_digital_speed_presentation
** Author               :   bhariha1
** Description          :   Digital speed presentation Logic.
** Organization         :   Driver Information Software Section,
**                          DI Core Engineering Department
**
*******************************************************************************/
/******************************************************************************
** Compiler Name        :   GHS
** Target Processor     :   Traveo 2
*******************************************************************************/

/******************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/

 /******************************************************************************
  *                                 Project Includes                           *
 ******************************************************************************/

#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02.cfg"
#include "hmi_gfx_mgr02_cfg.h"
#ifdef GFX_MGR02_TV2_MONOTYPE_ADAS_DEMO

#include "ui_adas_presentation.h"

#define UI_PATTERN_THICK		(UINT8)0
#define UI_PATTERN_THIN			(UINT8)1
#define UI_PATTERN_COUNT		(UINT8)2

#define UI_CASUAL_DRIVE_MODE	(UINT8)0
#define UI_SMART_DRIVE_MODE		(UINT8)1
#define UI_SPORT_DRIVE_MODE		(UINT8)2

#define UI_SPD_ONE_DGT_MIN		(UINT16)0
#define UI_SPD_ONE_DGT_MAX		(UINT16)9
#define UI_SPD_TWO_DGT_MIN		(UINT16)10
#define UI_SPD_TWO_DGT_MAX		(UINT16)99
#define UI_SPD_THREE_DGT_MIN	(UINT16)100
#define UI_SPD_THREE_DGT_MAX	(UINT16)999
#define UI_SPD_INVALID			(UINT16)65535
#define UI_SPD_FACTOR_TEN		(UINT16)10
#define UI_SPD_FACTOR_HNDRD		(UINT16)100

#define DSPEED_POS              (UINT8)0
#define UI_DSPEED_BIT_ENABLED	(IOCtrl_Type)1
#define UI_GET_BIT(val,pos)     (((val) >> (pos)) & (UINT8)1)

static const GFX_MGR02_DWDG_ELEM_ID hmi_gfx_pattern_sel[UI_PATTERN_COUNT] =
{
  GFX_DWDG_DGTL_SPD_THICK_DGT_SEL,
  GFX_DWDG_DGTL_SPD_THIN_DGT_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_1digit_mid_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_1DGT_MID_SEL,
  GFX_DIMG_THIN_1DGT_MID_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_2digit_left_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_2DGT_LEFT_SEL,
  GFX_DIMG_THIN_2DGT_LEFT_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_2digit_right_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_2DGT_RIGHT_SEL,
  GFX_DIMG_THIN_2DGT_RIGHT_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_3digit_left_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_3DGT_LEFT_SEL,
  GFX_DIMG_THIN_3DGT_LEFT_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_3digit_mid_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_3DGT_MID_SEL,
  GFX_DIMG_THIN_3DGT_MID_SEL
};

static const GFX_MGR02_DIMG_ELEM_ID hmi_gfx_3digit_right_image_sel[UI_PATTERN_COUNT] =
{
  GFX_DIMG_THICK_3DGT_RIGHT_SEL,
  GFX_DIMG_THIN_3DGT_RIGHT_SEL
};

static BOOLEAN l_metstyle_digispd_forced_update_st = FALSE;
static UINT8 l_pattern_sel_index_U8 = UI_PATTERN_THIN;


/****************************************************************************
Function Name     : void ui_digital_speed_presentation_update(void)
Description       : Presentation update function for digital speed display.
Invocation        : HmiView.c
Parameters        : None
Return Value      : None
Critical Section  : None
******************************************************************************/
void ui_digital_speed_presentation_update(void)
{
  UINT16 fl_speed_val_U16 = UI_UINT16_VAL_INIT;
  UINT16 fl_ones_place_U16 = UI_UINT16_VAL_INIT;
  UINT16 fl_tens_place_U16 = UI_UINT16_VAL_INIT;
  UINT16 fl_hndrds_place_U16 = UI_UINT16_VAL_INIT;
  UINT8 fl_Display_Distance_Unit_U8 = UI_UINT8_VAL_INIT;
  static UINT16 speed_stub = 0;

  speed_stub++;
  if (speed_stub > 6000)
  {
    speed_stub = 0;
  }
  fl_speed_val_U16 = speed_stub / 60;

  if (UI_PATTERN_COUNT <= l_pattern_sel_index_U8)
  {
    l_pattern_sel_index_U8 = UI_PATTERN_THIN;
  }

  (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_DGTL_SPD_SEL, l_pattern_sel_index_U8);
  (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_DGTL_SPD_UNIT_TXT_SEL, fl_Display_Distance_Unit_U8);

  if (UI_SPD_ONE_DGT_MAX >= fl_speed_val_U16)
  {
    /* One digit display - 0 to 9 */
    (void)hmi_gfx_mgr02_layout_select_dwidget(hmi_gfx_pattern_sel[l_pattern_sel_index_U8], \
      GFX_DWDG_DGTL_SPD_THIN_DGT_SEL_IDX_WDG_THIN_ONE_DGT);

    /* Use same speed value as index */
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_1digit_mid_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_speed_val_U16);
  }
  else if (UI_SPD_TWO_DGT_MAX >= fl_speed_val_U16)
  {
    /* Two digit display 10 to 99 */
    (void)hmi_gfx_mgr02_layout_select_dwidget(hmi_gfx_pattern_sel[l_pattern_sel_index_U8], \
      GFX_DWDG_DGTL_SPD_THIN_DGT_SEL_IDX_WDG_THIN_TWO_DGT);

    /* Extract ones and tens place digits */
    fl_ones_place_U16 = fl_speed_val_U16 % UI_SPD_FACTOR_TEN;
    fl_tens_place_U16 = (fl_speed_val_U16 / UI_SPD_FACTOR_TEN) % UI_SPD_FACTOR_TEN;

    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_2digit_left_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_tens_place_U16);
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_2digit_right_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_ones_place_U16);
  }
  else if (UI_SPD_THREE_DGT_MAX >= fl_speed_val_U16)
  {
    /* Three digit display 100 to 999 */
    (void)hmi_gfx_mgr02_layout_select_dwidget(hmi_gfx_pattern_sel[l_pattern_sel_index_U8], \
      GFX_DWDG_DGTL_SPD_THIN_DGT_SEL_IDX_WDG_THIN_THREE_DGT);

    /* Extract ones, tens and hundreds place digits */
    fl_ones_place_U16 = fl_speed_val_U16 % UI_SPD_FACTOR_TEN;
    fl_tens_place_U16 = (fl_speed_val_U16 / UI_SPD_FACTOR_TEN) % UI_SPD_FACTOR_TEN;
    fl_hndrds_place_U16 = (fl_speed_val_U16 / UI_SPD_FACTOR_HNDRD) % UI_SPD_FACTOR_TEN;

    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_left_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_hndrds_place_U16);
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_mid_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_tens_place_U16);
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_right_image_sel[l_pattern_sel_index_U8], \
      (UINT32)fl_ones_place_U16);
  }
  else if (UI_SPD_INVALID >= fl_speed_val_U16)
  {
    /* INVALID VALUE 65535 */
    (void)hmi_gfx_mgr02_layout_select_dwidget(hmi_gfx_pattern_sel[l_pattern_sel_index_U8], \
      UI_INVALID_INDEX);

    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_left_image_sel[l_pattern_sel_index_U8], \
      UI_INVALID_INDEX);
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_mid_image_sel[l_pattern_sel_index_U8], \
      UI_INVALID_INDEX);
    (void)hmi_gfx_mgr02_layout_select_dimage(hmi_gfx_3digit_right_image_sel[l_pattern_sel_index_U8], \
      UI_INVALID_INDEX);
  }
  else
  {
    /* Do Nothing */
  }

}

#define ADAS_SPEED_CONTROL (2U)
#define MAX_SEQ (8U)
#define MAX_DIST (65534)
#define MAX_SEQ_STEPS (125) //4seconds
typedef enum
{
  ADAS_TYPE_BIKE = 0,
  ADAS_TYPE_CAR,
  ADAS_TYPE_TRUCK,
  ADAS_TYPE_INVALID = 255
}adas_obj_type;
typedef enum
{
  ADAS_POS_LEFT = 0,
  ADAS_POS_CENTER,
  ADAS_POS_RIGHT,
  ADAS_POS_INVALID = 255
}adas_obj_position;
typedef struct
{
  adas_obj_type fl_object_type;
  adas_obj_position fl_object_position;
  UINT16 fl_object_set_distance;
  UINT16 fl_object_distance;
  UINT16 fl_dist_inc;
}adas_obj;
#define LC_ADAS_OBJ_INIT { \
    {ADAS_TYPE_CAR,ADAS_POS_LEFT,MAX_DIST+1,MAX_DIST+1,0},\
    {ADAS_TYPE_CAR,ADAS_POS_LEFT,0,0,0},\
    {ADAS_TYPE_TRUCK,ADAS_POS_CENTER,MAX_DIST+1,MAX_DIST+1,0},\
    {ADAS_TYPE_BIKE,ADAS_POS_RIGHT,0,0,0},\
    {ADAS_TYPE_CAR,ADAS_POS_RIGHT,0,0,0},\
    {ADAS_TYPE_INVALID,ADAS_POS_INVALID,MAX_DIST+1,MAX_DIST+1,0},\
}
static void ui_menu_adas_poc_update(void)
{
  static adas_obj fl_vehicle[6] = LC_ADAS_OBJ_INIT;
  static UINT8 adas_seq = 0;
  static UINT8 prev_adas_seq = 255;
  static UINT16 adas_vehicle_dist = 0;
  static UINT16 fl_adas_vehicle_dist = 0;
  static UINT8 fl_blink = 0;
  static UINT8 adas_speed = 0;
  static UINT8 lane_speed = 0;
  static UINT8 lane_speed_curved = 0;
  static UINT8 fade_value = 255;
  static UINT8 fade_in_out = 0;
  static const GFX_MGR02_DWDG_ELEM_ID fl_object_obj_dwdg[6] = { GFX_DWDG_OBJ_1,GFX_DWDG_OBJ_2,GFX_DWDG_OBJ_3,GFX_DWDG_OBJ_4,GFX_DWDG_OBJ_5,GFX_DWDG_OBJ_6 };
  static const GFX_MGR02_DWDG_ELEM_ID fl_object_type_dwdg[6][3] = { \
  {GFX_DWDG_OBJ_1_BIKE,   GFX_DWDG_OBJ_1_CAR, GFX_DWDG_OBJ_1_TRUCK}, \
  {GFX_DWDG_OBJ_2_BIKE,   GFX_DWDG_OBJ_2_CAR, GFX_DWDG_OBJ_2_TRUCK}, \
  {GFX_DWDG_OBJ_3_BIKE,   GFX_DWDG_OBJ_3_CAR, GFX_DWDG_OBJ_3_TRUCK}, \
  {GFX_DWDG_OBJ_4_BIKE,   GFX_DWDG_OBJ_4_CAR, GFX_DWDG_OBJ_4_TRUCK}, \
  {GFX_DWDG_OBJ_5_BIKE,   GFX_DWDG_OBJ_5_CAR, GFX_DWDG_OBJ_5_TRUCK}, \
  {GFX_DWDG_OBJ_6_BIKE,   GFX_DWDG_OBJ_6_CAR, GFX_DWDG_OBJ_6_TRUCK}, \
  };
  static const GFX_MGR02_DIMG_ELEM_ID fl_object_pos_dimg[6][3][3] = { \
  {                                                                                                   \
      {GFX_DIMG_OBJ_1_BIKE_LEFT,      GFX_DIMG_OBJ_1_BIKE_CENTER,     GFX_DIMG_OBJ_1_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_1_CAR_LEFT,       GFX_DIMG_OBJ_1_CAR_CENTER,      GFX_DIMG_OBJ_1_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_1_TRUCK_LEFT,     GFX_DIMG_OBJ_1_TRUCK_CENTER,    GFX_DIMG_OBJ_1_TRUCK_RIGHT},    \
  },                                                                                                  \
  {                                                                                                   \
      {GFX_DIMG_OBJ_2_BIKE_LEFT,      GFX_DIMG_OBJ_2_BIKE_CENTER,     GFX_DIMG_OBJ_2_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_2_CAR_LEFT,       GFX_DIMG_OBJ_2_CAR_CENTER,      GFX_DIMG_OBJ_2_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_2_TRUCK_LEFT,     GFX_DIMG_OBJ_2_TRUCK_CENTER,    GFX_DIMG_OBJ_2_TRUCK_RIGHT},    \
  },                                                                                                  \
  {                                                                                                   \
      {GFX_DIMG_OBJ_3_BIKE_LEFT,      GFX_DIMG_OBJ_3_BIKE_CENTER,     GFX_DIMG_OBJ_3_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_3_CAR_LEFT,       GFX_DIMG_OBJ_3_CAR_CENTER,      GFX_DIMG_OBJ_3_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_3_TRUCK_LEFT,     GFX_DIMG_OBJ_3_TRUCK_CENTER,    GFX_DIMG_OBJ_3_TRUCK_RIGHT},    \
  },                                                                                                  \
  {                                                                                                   \
      {GFX_DIMG_OBJ_4_BIKE_LEFT,      GFX_DIMG_OBJ_4_BIKE_CENTER,     GFX_DIMG_OBJ_4_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_4_CAR_LEFT,       GFX_DIMG_OBJ_4_CAR_CENTER,      GFX_DIMG_OBJ_4_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_4_TRUCK_LEFT,     GFX_DIMG_OBJ_4_TRUCK_CENTER,    GFX_DIMG_OBJ_4_TRUCK_RIGHT},    \
  },                                                                                                  \
  {                                                                                                   \
      {GFX_DIMG_OBJ_5_BIKE_LEFT,      GFX_DIMG_OBJ_5_BIKE_CENTER,     GFX_DIMG_OBJ_5_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_5_CAR_LEFT,       GFX_DIMG_OBJ_5_CAR_CENTER,      GFX_DIMG_OBJ_5_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_5_TRUCK_LEFT,     GFX_DIMG_OBJ_5_TRUCK_CENTER,    GFX_DIMG_OBJ_5_TRUCK_RIGHT},    \
  },                                                                                                  \
  {                                                                                                   \
      {GFX_DIMG_OBJ_6_BIKE_LEFT,      GFX_DIMG_OBJ_6_BIKE_CENTER,     GFX_DIMG_OBJ_6_BIKE_RIGHT},     \
      {GFX_DIMG_OBJ_6_CAR_LEFT,       GFX_DIMG_OBJ_6_CAR_CENTER,      GFX_DIMG_OBJ_6_CAR_RIGHT},      \
      {GFX_DIMG_OBJ_6_TRUCK_LEFT,     GFX_DIMG_OBJ_6_TRUCK_CENTER,    GFX_DIMG_OBJ_6_TRUCK_RIGHT},    \
  },                                                                                                  \
  };

  (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_ADAS_LANE_GREY_LEFT, lane_speed / 2);
  //(void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_ADAS_LANE_GREY_RIGHT,lane_speed);
  //(void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_ADAS_LANE_GREEN_LEFT,lane_speed);
  (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_ADAS_LANE_GREEN_RIGHT, lane_speed / 2);
  (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_LANE_GREEN_SEQ, lane_speed_curved / 2);
  lane_speed++;
  if (lane_speed > 34)
  {
    lane_speed = 0;
  }
  lane_speed_curved++;
  if (lane_speed_curved > 24)
  {
    lane_speed_curved = 0;
  }

  adas_speed++;
  if (adas_speed > 1)
  {
    adas_speed = 0;
  }
  else
  {
    return;
  }

  switch (adas_seq)
  {
  case 0:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    fl_vehicle[0].fl_object_set_distance = 0xFFFF;
    fl_vehicle[1].fl_object_set_distance = 0x6FFF;
    fl_vehicle[2].fl_object_set_distance = 1;
    fl_vehicle[3].fl_object_set_distance = 0;
    fl_vehicle[4].fl_object_set_distance = 0;
    break;
  case 1:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    fl_vehicle[0].fl_object_set_distance = 0x6FFF + 0x4000;
    fl_vehicle[1].fl_object_set_distance = 0x5FFF;
    fl_vehicle[2].fl_object_set_distance = 0x7FFF;
    fl_vehicle[3].fl_object_set_distance = 0xAAAA;
    fl_vehicle[4].fl_object_set_distance = 0;
    break;
  case 2:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    fl_vehicle[0].fl_object_set_distance = 0x4000;
    fl_vehicle[1].fl_object_set_distance = 0;
    fl_vehicle[2].fl_object_set_distance = 0xDFFF;
    fl_vehicle[3].fl_object_set_distance = 0xFFFF;
    fl_vehicle[4].fl_object_set_distance = 0xAAAA;
    break;
  case 3:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    fl_vehicle[0].fl_object_set_distance = 0;
    fl_vehicle[1].fl_object_set_distance = 0;
    fl_vehicle[2].fl_object_set_distance = 0xFFFF;
    fl_vehicle[3].fl_object_set_distance = 0xFFFF;
    fl_vehicle[4].fl_object_set_distance = 0xFFFF;
    break;
  case 4:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    break;
  case 5:
    fl_vehicle[0].fl_object_set_distance = 0xFFFF;
    fl_vehicle[1].fl_object_set_distance = 0;
    fl_vehicle[2].fl_object_set_distance = 0xFFFF;
    fl_vehicle[3].fl_object_set_distance = 0;
    fl_vehicle[4].fl_object_set_distance = 0;
    fl_vehicle[0].fl_object_distance = 0xFFFF;
    fl_vehicle[1].fl_object_distance = 0;
    fl_vehicle[2].fl_object_distance = 0xFFFF;
    fl_vehicle[3].fl_object_distance = 0;
    fl_vehicle[4].fl_object_distance = 0;
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 1);
    break;
  case 6:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 2);
    break;
  case 7:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 3);
    fl_vehicle[0].fl_object_set_distance = 0xFFFF;
    fl_vehicle[1].fl_object_set_distance = 0;
    fl_vehicle[2].fl_object_set_distance = 0xFFFF;
    fl_vehicle[3].fl_object_set_distance = 0;
    fl_vehicle[4].fl_object_set_distance = 0;
    fl_vehicle[0].fl_object_distance = 0xFFFF;
    fl_vehicle[1].fl_object_distance = 0;
    fl_vehicle[2].fl_object_distance = 0xFFFF;
    fl_vehicle[3].fl_object_distance = 0;
    fl_vehicle[4].fl_object_distance = 0;
    fade_in_out = 0;
    fade_value = 255;
    break;
  case 8:
    if (fade_in_out == 0)
    {
      (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
      fade_value = fade_value - 15;
      if (fade_value <= 0)
      {
        fade_in_out = 1;
      }
    }
    else
    {
      (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 4);
      fade_value = fade_value + 15;
      if (fade_value >= 255)
      {
        fade_in_out = 0;
        adas_seq++;
      }
    }
    // hmi_gfx_mgr02_layout_set_obj_alpha(GFX_WDG_ADAS_LCA_CONTAINER_ANIM, fade_value);
    break;
  case 9:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 4);
    break;
  case 10:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 4);
    fade_in_out = 0;
    fade_value = 255;
    break;
  case 11:
    if (fade_in_out == 0)
    {
      (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 4);
      fade_value = fade_value - 15;
      if (fade_value <= 0)
      {
        fade_in_out = 1;
      }
    }
    else
    {
      (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
      fade_value = fade_value + 15;
      if (fade_value >= 255)
      {
        fade_in_out = 0;
        adas_seq++;
      }
    }
    // hmi_gfx_mgr02_layout_set_obj_alpha(GFX_WDG_ADAS_LCA_CONTAINER_ANIM, fade_value);
    break;
  case 12:
    (void)hmi_gfx_mgr02_layout_select_dwidget(GFX_DWDG_ADAS_LCA, 0);
    break;
  }
  if ((adas_seq <= 5) || (adas_seq == 12))
  {
    if (prev_adas_seq != adas_seq)
    {
      prev_adas_seq = adas_seq;
      for (UINT8 i = 0; i < 6; i++)
      {
        if (fl_vehicle[i].fl_object_distance > fl_vehicle[i].fl_object_set_distance)
        {
          fl_vehicle[i].fl_dist_inc = (fl_vehicle[i].fl_object_distance - fl_vehicle[i].fl_object_set_distance) / MAX_SEQ_STEPS;
        }
        else
        {
          fl_vehicle[i].fl_dist_inc = (fl_vehicle[i].fl_object_set_distance - fl_vehicle[i].fl_object_distance) / MAX_SEQ_STEPS;
        }
      }
      adas_vehicle_dist = 0U;
    }
    for (UINT8 i = 0; i < 6; i++)
    {

      if (fl_vehicle[i].fl_object_distance > fl_vehicle[i].fl_object_set_distance)
      {
        if ((fl_vehicle[i].fl_object_distance - fl_vehicle[i].fl_dist_inc) < fl_vehicle[i].fl_object_set_distance)
        {
          fl_vehicle[i].fl_object_distance = fl_vehicle[i].fl_object_set_distance;
        }
        else if (fl_vehicle[i].fl_object_distance > fl_vehicle[i].fl_dist_inc)
        {
          fl_vehicle[i].fl_object_distance = fl_vehicle[i].fl_object_distance - fl_vehicle[i].fl_dist_inc;
        }
        else
        {
          fl_vehicle[i].fl_object_distance = 0;
        }
      }
      else if (fl_vehicle[i].fl_object_distance < fl_vehicle[i].fl_object_set_distance)
      {
        if ((fl_vehicle[i].fl_object_distance + fl_vehicle[i].fl_dist_inc) > fl_vehicle[i].fl_object_set_distance)
        {
          fl_vehicle[i].fl_object_distance = fl_vehicle[i].fl_object_set_distance;
        }
        else if ((fl_vehicle[i].fl_object_distance + fl_vehicle[i].fl_dist_inc) < (MAX_DIST + 1))
        {
          fl_vehicle[i].fl_object_distance = fl_vehicle[i].fl_object_distance + fl_vehicle[i].fl_dist_inc;
        }
        else
        {
          fl_vehicle[i].fl_object_distance = MAX_DIST + 1;
        }
      }
      if ((fl_vehicle[i].fl_object_distance == 0) || (fl_vehicle[i].fl_object_distance > MAX_DIST))
      {
        fl_adas_vehicle_dist = 255;
      }
      else
      {
        fl_adas_vehicle_dist = ((59 * fl_vehicle[i].fl_object_distance) / (MAX_DIST - 1));
      }
      (void)hmi_gfx_mgr02_layout_select_dwidget(fl_object_obj_dwdg[i], fl_vehicle[i].fl_object_type);
      (void)hmi_gfx_mgr02_layout_select_dwidget(fl_object_type_dwdg[i][fl_vehicle[i].fl_object_type], fl_vehicle[i].fl_object_position);
      (void)hmi_gfx_mgr02_layout_select_dimage(fl_object_pos_dimg[i][fl_vehicle[i].fl_object_type][fl_vehicle[i].fl_object_position], fl_adas_vehicle_dist);
    }

    adas_vehicle_dist++;
    if ((adas_seq == 12) || (adas_seq == 4))
    {
      if (adas_vehicle_dist > 40)
      {
        adas_vehicle_dist = 0U;
        adas_seq++;
      }
    }
    else
    {
      if (adas_vehicle_dist > MAX_SEQ_STEPS) //4 seconds
      {
        adas_vehicle_dist = 0U;
        adas_seq++;
      }
    }
#if 0
    if ((fl_vehicle[0].fl_object_distance == fl_vehicle[0].fl_object_set_distance) && \
      (fl_vehicle[1].fl_object_distance == fl_vehicle[1].fl_object_set_distance) && \
      (fl_vehicle[2].fl_object_distance == fl_vehicle[2].fl_object_set_distance) && \
      (fl_vehicle[3].fl_object_distance == fl_vehicle[3].fl_object_set_distance) && \
      (fl_vehicle[4].fl_object_distance == fl_vehicle[4].fl_object_set_distance))
    {
      adas_seq++;
    }
#endif
  }

  if ((adas_seq == 5) || (adas_seq == 6))
  {
    if (adas_seq == 5)
    {
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_LCA_TRAJECTORY_SCAN, adas_vehicle_dist);
      adas_vehicle_dist++;
      if (adas_vehicle_dist > 59)
      {
        adas_vehicle_dist = 0U;
        adas_seq++;
      }
    }
    if (adas_seq == 6)
    {
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_LCA_TRAJECTORY_SEQ, adas_vehicle_dist);
      adas_vehicle_dist++;
      if (adas_vehicle_dist > 104)
      {
        adas_vehicle_dist = 0U;
        adas_seq++;
      }
    }

    fl_blink++;
    if (fl_blink > 30)
    {
      fl_blink = 0;
    }
    if (fl_blink < 15)
    {
      hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_ADAS_MAIN_CAR_INDICATOR_ANIM, 0);
    }
    else
    {
      hmi_gfx_mgr02_layout_set_obj_alpha(GFX_IMG_ADAS_MAIN_CAR_INDICATOR_ANIM, 255);
    }
  }

  if (adas_seq == 7)
  {
    (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_LCA_CAR_TRANSITION_SEQ, adas_vehicle_dist);
    (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_LCA_LANE_TRANSITION_SEQ, adas_vehicle_dist);
    adas_vehicle_dist++;
    if (adas_vehicle_dist > 59)
    {
      adas_vehicle_dist = 0U;
      adas_seq++;
    }
  }

  if ((adas_seq == 9) || (adas_seq == 10))
  {
    adas_vehicle_dist++;
    if (adas_vehicle_dist > (59 * 3))
    {
      adas_vehicle_dist = 0U;
      if (adas_seq == 10)
      {
        (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_BIKE_RIGHT_SEQ, 255);
        (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_TRUCK_MID_SEQ, 255);
        (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_CAR_LEFT_SEQ, 255);
      }
      adas_seq++;
    }
    if (adas_seq == 9)
    {
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_BIKE_RIGHT_SEQ, (adas_vehicle_dist) / 3);
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_TRUCK_MID_SEQ, ((59 * 3) - adas_vehicle_dist) / 3);
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_CAR_LEFT_SEQ, (adas_vehicle_dist) / 3);
    }
    else if (adas_seq == 10)
    {
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_BIKE_RIGHT_SEQ, ((59 * 3) - adas_vehicle_dist) / 3);
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_TRUCK_MID_SEQ, (adas_vehicle_dist) / 3);
      (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_CAR_LEFT_SEQ, ((59 * 3) - adas_vehicle_dist) / 3);
    }
  }
  else
  {
    (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_BIKE_RIGHT_SEQ, 255);
    (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_TRUCK_MID_SEQ, 255);
    (void)hmi_gfx_mgr02_layout_select_dimage(GFX_DIMG_CURVED_CAR_LEFT_SEQ, 255);
  }
  if (adas_seq > MAX_SEQ)
  {
    adas_seq = 0U;
  }
}

void scr_adas_presentation_handler(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
  switch (p_presen_hndl_status_SP->presentation_status)
  {
  case LSH_ACTIVATED_STATUS:
  {
    (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, TRUE);
    GFX_MGR02_ILOC_DATA fl_pos;
    hmi_gfx_mgr02_layout_get_obj_pos(GFX_WDG_VEHICLE_DATA_ANIM, &fl_pos);
    //fl_pos.x = 220;
    fl_pos.y = 30;
    hmi_gfx_mgr02_layout_set_obj_pos(GFX_WDG_VEHICLE_DATA_ANIM, &fl_pos);
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_CRUSINGRANGE_VALUE, L"508");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_CRUSINGRANGE_UNIT, L"km");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_OAT_VALUE, L"25");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_CLOCK_HOUR, L"12");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_CLOCK_COLON, L":");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_CLOCK_MIN, L"02");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_ODO_VALUE, L"1046");
    (void)hmi_gfx_mgr02_layout_set_text(GFX_TXT_ODO_UNIT, L"km");
  }
  break;
  case LSH_REFRESH_STATUS:
    ui_menu_adas_poc_update();
    ui_digital_speed_presentation_update();
    break;
  case LSH_DEACTIVATED_STATUS:
    (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, false);
    break;
  default:
    break;
  }
}
static int speed = 0;
static int xpos = 24;
static int count = 0;
static void UpdateSpeed()
{
  UINT16 fl_speed_value = speed;
  UINT8 fl_speed_value_digit;
  HMI_CHAR fl_speed_txt[4];

  HMI_CHAR fl_speed_txt_digit[2];
  (void)HMI_SNPRINTF(fl_speed_txt,
    4,
    HMI_TEXT((void*)"%d"),
    fl_speed_value);

  fl_speed_value_digit = (fl_speed_value % 10);
  (void)HMI_SNPRINTF(fl_speed_txt_digit,
    2,
    HMI_TEXT((void*)"%d"),
    fl_speed_value_digit);
  hmi_gfx_mgr02_if_set_text(GFX_TXT_PERF_SPEED_ONES, fl_speed_txt_digit);

  fl_speed_value_digit = (fl_speed_value / 10);
  fl_speed_value_digit = (fl_speed_value_digit % 10);

  (void)HMI_SNPRINTF(fl_speed_txt_digit,
    2,
    HMI_TEXT((void*)"%d"),
    fl_speed_value_digit);
  hmi_gfx_mgr02_if_set_text(GFX_TXT_PERF_SPEED_TENS, fl_speed_txt_digit);

  fl_speed_value_digit = (fl_speed_value / 100);
  (void)HMI_SNPRINTF(fl_speed_txt_digit,
    2,
    HMI_TEXT((void*)"%d"),
    fl_speed_value_digit);
  hmi_gfx_mgr02_if_set_text(GFX_TXT_PERF_SPEED_HUNDREDS, fl_speed_txt_digit);
}

void scr_main_presentation(LSH_PRESN_HANDLER_STATUS_T* p_presen_hndl_status_SP)
{
  switch (p_presen_hndl_status_SP->presentation_status)
  {
  case LSH_ACTIVATED_STATUS:
    (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, TRUE);
    break;
  case LSH_REFRESH_STATUS:
  {
    count++;
    if (count == 30)
    {
      count = 0;
      xpos += 1;
      speed += 1;
      if (speed > 288)
      {
        speed = 0;
      }
      if (xpos > 450)
      {
        xpos = 30;
      }
    }
    UpdateSpeed();
    hmi_gfx_mgr02_if_set_obj_pos_x(GFX_IMG_TACHO_FILL_MASK_ANIM, xpos);
  }
  break;
  case LSH_DEACTIVATED_STATUS:
    (void)hmi_gfx_mgr02_if_set_screen(p_presen_hndl_status_SP->logic_state_id, false);
    break;
  default:
    break;
  }
}
#endif

 /* End of File */
