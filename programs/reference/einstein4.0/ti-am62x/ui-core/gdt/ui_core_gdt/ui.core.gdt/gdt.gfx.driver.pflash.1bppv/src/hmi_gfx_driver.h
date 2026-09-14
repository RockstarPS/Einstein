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
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
#include "hmi_gfx_mgr_font.h"
#endif

#ifndef HMI_GFX_DRIVER_C
#define EXTERN  extern
#else
#define EXTERN
#endif

/*****************************************************************************
*                                 Constant Declarations                      *
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


/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

#ifndef GFX_UNUSED_PTR
#define GFX_UNUSED_PTR(X)  do { if((void *)0 == (X)){} } while(0)
#endif


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
  extern void GfxDriverBuildBitmapImage(COORDINATE_DEF_T const * p_coord_def_SP, BITMAP_DEF_T const * pc_bitmap_def_SP);
#endif

#if NB_COLORTRANSBITMAP > 0
   extern void GfxDriverBuildColorTransBitMapImage(COORDINATE_DEF_T const * p_coord_def_SP, COLORTRANSMAP_DEF_T const * pc_bitmap_def_SP);
	 
	 #if GFX_DRIVER_CUSTOM_TEXT_RENDERING > 0
	 extern void GfxDriverMakeImageTransparent( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha,
    GFX_COLOR_T trans_color);
#endif
#endif

#if NB_DYN_TEXTS > 0 || NB_STATIC_TEXTS > 0
  extern void GfxDriverBuildText(GFX_TEXT_PROPERTY const * pc_text_prop_SP, DYN_TEXT_DEF_T const * pc_dyn_text_def_SP);
  extern void GfxDriverGetTextFitWidth(GFX_TEXT_WIDTH_INFO_DEF_T *pc_text_info_SP, 
	                                   DYN_TEXT_DEF_T const * pc_dyn_text_def_SP);
  extern GFX_FONT_CHAR_CONFIG const * GfxDriverGetCharConfigInfo(GFX_CHAR p_char, 
                                                               GFX_FONT const * fl_font_tbl_P
                                                               #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT
                                                               ,UINT8 fl_font_id_u8
                                                               #endif
                                                               );

 #if GFX_DRIVER_CUSTOM_TEXT_RENDERING > 0
  extern void GfxDriverCopyImage( SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
                           UINT8 alpha
                         #if GFX_SCROLABLE_TEXT_SUPPORT != 0
                          ,UINT16 scroll_start  /* Copy start location in the x direction ( 0 to width-1) */
                          ,UINT16 scroll_length   /* how much to copy                                       */
                         #endif
						  );
 #if (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)
  extern void GfxDriverCopyImageTrans( SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
                           UINT8 alpha
                         #if GFX_SCROLABLE_TEXT_SUPPORT != 0
                          ,UINT16 scroll_start  /* Copy start location in the x direction ( 0 to width-1) */
                          ,UINT16 scroll_length   /* how much to copy                                       */
                         #endif
                           );

 extern void GfxDriverCopyImageTransInv( SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
                           UINT8 alpha
                         #if GFX_SCROLABLE_TEXT_SUPPORT != 0
                          ,UINT16 scroll_start  /* Copy start location in the x direction ( 0 to width-1) */
                          ,UINT16 scroll_length   /* how much to copy                                       */
                         #endif
                           );
#endif /*  (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP) */
  extern void GfxDriverCopyImageInv( SINT16 x,
                                   SINT16 y,
                                   const GFX_COLOR_T * bmp_data,
                                   UINT16 height,
                                   UINT16 width,
                                UINT8 alpha
                                 #if GFX_SCROLABLE_TEXT_SUPPORT != 0
                                  ,UINT16 scroll_start  /* Copy start location in the x direction ( 0 to width-1) */
                                  ,UINT16 scroll_length   /* how much to copy                                       */
                                 #endif                         
                                   );
 #endif
#endif

#if (NB_FILL_SCREENS > 0) || (NB_DYN_FILL_SCREENS > 0) || (NB_STATIC_TEXTS > 0) || (NB_DYN_TEXTS > 0)
  extern void GfxDriverBuildFillScreen(COORDINATE_DEF_T const * pc_coord_SP, FILL_SCREEN_DEF_T const * pc_fill_screen_def_SP);
#endif

#if NB_VERT_PATTERN_FILL > 0
  extern void GfxDriverBuildVerticalPatternFill(HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S);
#endif

#if NB_HORZ_PATTERN_FILL > 0
  extern void GfxDriverBuildHorizontalPatternFill(HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S);
#endif

#if NB_LAYERS > 1
  UINT8 GfxDriverCheckBusyStatus(UINT8 fl_lid_U8);
  extern void  GfxDriverEndUpdate(UINT8 fl_lid_U8);
  extern void  GfxDriverLcdUpdateComplete(UINT8 fl_lid_U8);
  extern void  GfxDriverBeginUpdate(UINT8 fl_lid_U8);
#else
  UINT8 GfxDriverCheckBusyStatus(void);
  extern void  GfxDriverEndUpdate(void);
  extern void  GfxDriverLcdUpdateComplete(void);
  extern void GfxDriverBeginUpdate(void);
#endif

extern void GfxDriverInitialize(void);
extern void GfxDriverVSyncISR(void);

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  extern void GfxDriverSetClipArea(RECTANGLE_DEF_T const * p_clip_area_SP);
  extern void GfxDriverGetClipArea(RECTANGLE_DEF_T * p_clip_area_SP);
  extern void GfxDriverReSetClipArea(void);
#endif

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
  extern void GfxDriverSetElementOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y);
  extern void GfxDriverGetElementOffset(GFX_SIZE_X_T *p_pos_x, GFX_SIZE_Y_T *p_pos_y);
  extern void GfxDriverAddElementOffset(GFX_SIZE_X_T * p_pos_x, GFX_SIZE_Y_T * p_pos_y);

  extern void GfxDriverSetWidgetOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y, UINT8 alpha);
  extern void GfxDriverAddWidgetOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y, UINT8 alpha);
  extern void GfxDriverGetWidgetOffset(GFX_SIZE_X_T *p_pos_x, GFX_SIZE_Y_T *p_pos_y, UINT8 * alpha);
#endif
#if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
extern UINT8 GfxDriverSetGroupFontIndex(GFX_ELEMENT_ID_T p_font_id, GFX_ELEMENT_DATA_T p_selection_index);
extern UINT8 GfxDriverGetGrpSelFontId(GFX_ELEMENT_ID_T p_font_id);
#endif

#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
extern void GfxDriverSegmentBuildText(DYN_TEXT_DEF_T const * pc_dyn_text_def_SP);
extern void GfxDriverSegmentBuildIcon(UINT16 com, 
                                      UINT16 seg, 
#if defined(GFX_MGR01_MULTI_COLOR_SUPPORT)
                                      GFX_SEG_COLOR status
#else
                               BOOLEAN status
#endif
);
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
extern UINT8 GfxDriverSegmentUpdateColor(UINT8 p_current_byte, GFX_SEG_COLOR p_color, UINT8 p_val);
#endif
#endif
#if GFX_COMPRESSED_IMAGES > 0
#if NB_COLORTRANSBITMAP > 0
void GfxDriverCopyRLETransImage(SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   UINT8 alpha,
                           GFX_COLOR_T trans_color
                         #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                         #endif 
						 );
#endif
#endif

#undef EXTERN
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
Date              :  25-MAY-2017
By                :  adevi
Traceability      :  873769
Change Description:  Signed values of x and y are not rendered properly.

Date              :  14-APR-2017
By                :  kkubendi
Traceability      :  791443
Change Description:  GFX01/HyundaiQxC: Update Graphics Manager 01 to support XY,Alpha animation, 
					 Alpha and Image blending.

Date              :  02-AUG-2016
By                :  adevi
Traceability      :  660538
Change Description:  S101 Issue - Wait event not getting scheduled properly

Date              :  8-APR-2015
By                :  aperumal
Traceability      :  567771
Change Description:  Moved the inclusion of hmi_gfx_mgr_font to hmi_gfx_driver.h 
                     to fix the compiler error for Hyundai DE 

Date              :  16-MAR-2015
By                :  adevi
Traceability      :  491346
Change Description:  Horizontal scan support for Hyundai DE for open vg integration.

Date              :  19-JAN-2015
By                :  adevi
Traceability      :  491345
Change Description:  Font grouping and dynamic font id change.

Date              :  28-DEC-2015
By                :  adevi
Traceability      :  489987
Change Description:  Dynamic screen position changes done.

Date              :17/7/2015
By                :adevi
Traceability      :RTC 368488, 344552, 344565
Change Description:For horizontal packing, horizontal scroll, horizontal clipping
                   and vertical clipping implemented.  For vertical packing, both
                   types of clipping implemented. So interfaces modified.

Date              :  25-Mar-2015
By                :  adevi
Traceability      :  RTC 314644
Change Description:  Added function declarations.

Date              :  12-Dec-2014
By                :  adevi
Traceability      :
Change Description:  Compiler warnings resolved.
                     Datatype declaration corrected in GfxDriverBuildColorTransBitMapImage.

Date              :  27-Oct-2014
By                :  sbollam
Traceability      :  RTC task id : 226310
Change Description:  Updated the signature of the GfxDriverBuildColorTransBitMapImage function
                     also fixed the compiler error related to dyanamic fillscreen ( by adevi)

Date              :  28-Aug-2014
By                :  adevi
Traceability      :
Change Description:  Check for (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)
                     added to avoid compiler warning.

Date              :  10-Jul-14
By                :  adevi
Traceability      :
Change Description:  Segment display interfaces and get text width interface
                     added.

Date              :  11-March-10
By                :  emanoj1
Traceability      :  
Change Description:  Transparency support added for 2bb(only for text).

Date              :  14-July-09
By                :  tvijayas
Traceability      :  
Change Description:  Schedule wait feature added.

Date              :  12-Jun-09
By                :  tvijayas
Traceability      :  
Change Description:  Initial version.
-----------------------------------------------------------------------------*/
