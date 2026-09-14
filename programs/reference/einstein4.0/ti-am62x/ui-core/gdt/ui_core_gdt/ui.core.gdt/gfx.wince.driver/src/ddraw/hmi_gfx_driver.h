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

File Name        :  hmi_gfx_driver.h
Module Short Name:  Driver
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Graphics Driver

Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef HMI_GFX_DRIVER_H
#define HMI_GFX_DRIVER_H

#include "hmi_gfx_manager.h"
#include "hmi_gfx_driver.cfg"

#ifndef HMI_GFX_DRIVER_C
#define EXTERN  extern
#else
#define EXTERN
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************************
*                                 Constant Declarations                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
******************************************************************************/

enum
{
   GFX_FADE_EFFECT_INACTIVE,
   GFX_FADE_EFFECT_REQUESTED,
   GFX_FADE_EFFECT_ACTIVE,
   GFX_FADE_EFFECT_ABORT
};

enum
{
   GFX_FADE_EFFECT_CONFIG_0,
   NB_FADE_EFFECT_CONFIG,
   GFX_FADE_EFFECT_STOP = 0xFFFF
};

#define GFX_DRIVER_TEXT_APEND  (0x01)
#define GFX_DRIVER_TEXT_CLIP   (0x02)

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

typedef struct
{
   DYN_TEXT_DEF_T    const * dyn_text_def_SP;
   GFX_TEXT_PROPERTY const * property_SP;
   GFX_CHAR                * print_str_P;
   GFX_SIZE_W_T              append_string_width;
   GFX_SIZE_W_T              max_available_width;
   GFX_SIZE_W_T              print_width;
   UINT8                     print_length_U8;
   UINT8                     print_sindex_U8;
}GFX_TEXT_INFO;

typedef struct
{
   HDC             hdc;
   GFX_COLOR_T   * fb_P;      /* Pointer to frame buffer */
   GFX_SIZE_W_T    fb_w;      /* frame buffer width      */
   GFX_SIZE_H_T    fb_h;      /* frame buffer height     */
   UINT8           fb_format; /* frame buffer pix format */
}GFX_DRV_ENV_INFO;

/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/


#if NB_BITMAPS > 0
  void GfxDriverBuildBitmapImage(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_ALPHAMAP > 0
   void GfxDriverBuildAlphaMapImage(COORDINATE_DEF_T const * coord, ALPHAMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_COLORTRANSBITMAP > 0
   void GfxDriverBuildColorTransBitMapImage(COORDINATE_DEF_T const * coord, COLORTRANSMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_ALPHABITMAP > 0
   void GfxDriverBuildAlphaBitMapImage(COORDINATE_DEF_T const * coord, ALPHABITMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_UNIALPHAMAP > 0
   void GfxDriverBuildUniAlphaMapImage(COORDINATE_DEF_T const * coord, UNIALPHAMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_UNIALPHABITMAP > 0
   void GfxDriverBuildUniAlphaBitMapImage(COORDINATE_DEF_T const * coord, UNIALPHABITMAP_DEF_T const * pc_bitmap_def_S);
#endif

#if NB_DYN_TEXTS > 0
  GFX_SIZE_X_T GfxDriverBuildText(GFX_TEXT_PROPERTY const * pc_property_SP, DYN_TEXT_DEF_T const * pc_dyn_text_def_S);
  GFX_SIZE_X_T GfxDriverTextRenderer(GFX_TEXT_INFO * p_text_info_SP,GFX_SIZE_X_T start_x,BOOLEAN clip_flag);
  UINT8 GfxDriverGetTextWidth(GFX_TEXT_INFO * p_clip_text_info_SP,UINT8 * tot_char_count);
#endif

#if NB_FILL_SCREENS > 0
  void GfxDriverBuildFillScreen(COORDINATE_DEF_T const * coord, FILL_SCREEN_DEF_T const * pc_fill_screen_def_S);
#endif

#if NB_VERT_PATTERN_FILL > 0
  void GfxDriverBuildVerticalPatternFill(COORDINATE_DEF_T const * coord, HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S);
#endif

#if NB_HORZ_PATTERN_FILL > 0
  void GfxDriverBuildHorizontalPatternFill(COORDINATE_DEF_T const * coord, HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S);
#endif

#if NB_LAYERS > 1
  void  GfxDriverBeginUpdate(UINT8 p_lid_U8);
  UINT8 GfxDriverCheckBusyStatus(UINT8 p_lid_U8);
 #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
  void GfxDriverEndUpdate(UINT8 p_active_layers_U8, UINT8 p_post_copy_flag_U8);
 #else
  void GfxDriverEndUpdate(UINT8 p_active_layers_U8);
 #endif
#else
  void  GfxDriverBeginUpdate(void);
  UINT8 GfxDriverCheckBusyStatus(void);
 #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
  void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8);
 #else
  void GfxDriverEndUpdate(void);
 #endif
#endif

void GfxDriverSetClipArea(RECTANGLE_DEF_T const * p_clip_area_SP);
void GfxDriverReSetClipArea(void);
void GfxDriverGetClipArea(RECTANGLE_DEF_T * p_clip_area_SP);

void  GfxDriverInitialize(void);
void GfxDriverVSyncISR(HWND hWnd, LPPAINTSTRUCT lpPS);
void  GfxDriverSetFadeEffect(UINT8 fl_fade_id_U8);
UINT8 GfxDriverIsFadeEffectInProgress(void);
void  GfxDriverDisableVideoInput(void);
void  GfxDriverEnableVideoInput(void);
void  GfxDriverSetEnv(GFX_DRV_ENV_INFO * p_drv_context_SP);

#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  void GfxDriverSelectDataPage(void * p_gfx_data_P);
#endif

#undef EXTERN

#if defined(__cplusplus)
} /* extern "C" */
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
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              :
By                :
Traceability      :
Change Description:
-----------------------------------------------------------------------------*/
