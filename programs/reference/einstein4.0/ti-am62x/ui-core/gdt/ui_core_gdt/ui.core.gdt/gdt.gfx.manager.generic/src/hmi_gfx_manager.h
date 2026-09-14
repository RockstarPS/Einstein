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

File Name        :  hmi_gfx_manager.h
Module Short Name:  GFX_MGR
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Application interfaces provided by the Graphics Manager
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/
#ifndef HMI_GFX_MANAGER_H
#define HMI_GFX_MANAGER_H

#include "system.h"
#include "hmi_gfx_mgr_app.cfg"
#include "hmi_gfx_mgr_cfg.h"

#ifdef GFX_OPEN_VG
#include <VG/openvg.h>
#include <VG/vgu.h>
#endif

#ifndef HMI_GFX_MANAGER_C
#define EXTERN  extern
#else
#define EXTERN
#endif

#ifndef GFX_MANAGER_NEED_POST_COPY_USER_CONTROL
  #define GFX_MANAGER_NEED_POST_COPY_USER_CONTROL    (0)
#endif
#ifndef GFX_MANAGER_NEED_BEGIN_UPDATE_NOTIFICATION
  #define GFX_MANAGER_NEED_BEGIN_UPDATE_NOTIFICATION (0)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#if(GFX_PIX_FORMAT == GFX_1BPP_SEG)||(GFX_PIX_FORMAT == GFX_SEG)
#if NB_LAYERS > 1
extern UINT8 GfxManagerBuildSegmentScreen(void);
#else
extern void GfxManagerBuildSegmentScreen(void);
#endif
#endif
extern void send_buffer(UINT8 layer, void * buffer);
/*****************************************************************************
*                                 Constant Declarations                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* purpose, unit, and resolution                                              *
******************************************************************************/


#if (GFX_PIX_FORMAT == GFX_1BPP)||(GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
#define GFX_PIX_FORMAT_ALPHA   0x01U 
#elif (GFX_PIX_FORMAT == GFX_2BPP)
#define GFX_PIX_FORMAT_ALPHA   0x03U
#else
#define GFX_PIX_FORMAT_ALPHA   0x0FU
#endif

/*
** Bit encoding macros for the dynamic text UINT8 properties;
** b7 b6 b54 b32 b10
**  '  '  '   '   '----- Alignment
**  '  '  '   '--------- Draw Mode
**  '  '  '------------- Clip Mode
**  '  '---------------- Scroll
**  '------------------- Unused
** Use the GFX_TEXT_PROPERTY_IS_XXXX(prop) macro definitions from Global Macro Definitions
** section rather than directly using the below constant bit/mask definitions.
*/


#define GFX_TEXT_PROPERTY_ALIGN_MASK    (0x03)  /*bits 1 and 0*/
#define GFX_TEXT_PROPERTY_ALIGN_LEFT    (0x00)
#define GFX_TEXT_PROPERTY_ALIGN_RIGHT   (0x01)
#define GFX_TEXT_PROPERTY_ALIGN_CENTRE  (0x02)
#define GFX_TEXT_PROPERTY_ALIGN_UNUSED  (0x03)

#define GFX_TEXT_PROPERTY_DRAW_MASK     (0x0C)  /*bits 3 and 2*/
#define GFX_TEXT_PROPERTY_DRAW_NORMAL   (0x00)
#define GFX_TEXT_PROPERTY_DRAW_REVERSE  (0x04)
#define GFX_TEXT_PROPERTY_DRAW_TRANSP   (0x08)
#define GFX_TEXT_PROPERTY_DRAW_UNUSED   (0x0C)

#define GFX_TEXT_PROPERTY_CLIP_MASK     (0x30)  /*bits 5 and 4*/
#define GFX_TEXT_PROPERTY_CLIP_NORMAL   (0x00)  /* String is clipped to the specified rectangle. */
#define GFX_TEXT_PROPERTY_CLIP_FIT      (0x10)  /* String is clipped but char will be removed if they cannot be fully shown */
#define GFX_TEXT_PROPERTY_CLIP_APPEND   (0x20)  /* When the string is not fully fit in the specified rectangle, a specified string is appended to show that clipping is performed. Eg. Tripcomputer can be displayed as Tripcomp...*/
#define GFX_TEXT_PROPERTY_NO_CLIP       (0x30)  /* No clipping is performed. String is displayed as is (Not supported at the moment) */

#define GFX_TEXT_PROPERTY_SCROLABLE     (0x40)  /*bit 6       */
#define GFX_TEXT_PROPERTY_UNUSED        (0x80)  /*bit 7       */

/*
** WIDGET_DEF_T "property" attribute bit definitions.
** Bit 0 and 1 specifies the alignment mode
** Bit 2 and 3 specifies the clipping mode
*/
#define GFX_WIDGET_CLIP_MASK            (0x0C)
#define GFX_WIDGET_CLIP_NONE            (0x00)
#define GFX_WIDGET_CLIP_STATIC          (0x04)
#define GFX_WIDGET_CLIP_DYNAMIC         (0x08)
#define GFX_WIDGET_AREA                 (0x0C)
#define GFX_WIDGET_ALIGN_MASK           (0x03)
#define GFX_WIDGET_ALIGN_NONE           (0x00)
#define GFX_WIDGET_ALIGN_LEFT           (0x01)
#define GFX_WIDGET_ALIGN_CENTER         (0x02)
#define GFX_WIDGET_ALIGN_RIGHT          (0x03)

#if GFX_COMPRESSED_IMAGES > 0
/*
** Image compression flags
** State encoding for the image compression configuration info flag UINT8 info;
*/
#define GFX_IMAGE_COMPRESSION_NONE      (0)  /* No compression used   */
#define GFX_IMAGE_COMPRESSION_LOSSLESS  (1)  /* Loss less compression */
#define GFX_IMAGE_COMPRESSION_LOSSY     (2)  /* RGB555 compression    */
#endif

#define GFX_REMOVE_SCREEN_EV            (0U)
#define GFX_ACTIVATE_SCREEN_EV          (1)
#define GFX_REFRESH_SCREEN_EV           (0xFFU)

#define PATH_PROP_FILL_ENABLED          0x0001
#define PATH_PROP_FILL_RULE_NONZERO     0x0000
#define PATH_PROP_FILL_RULE_EVENODD     0x0002
#define PATH_PROP_STROKE_ENABLED        0x0004
#define PATH_PROP_BLEND_ENABLED         0x0008

#define PATH_PROP_LINE_CAP              (0x0003<<4)
#define PATH_PROP_LINE_CAP_BUTT         0x0000
#define PATH_PROP_LINE_CAP_ROUND        (0x0001<<4)
#define PATH_PROP_LINE_CAP_SQUARE       (0x0002<<4)

#define PATH_PROP_LINE_JOIN             (0x0003<<6)
#define PATH_PROP_LINE_JOIN_MITER       0x0000
#define PATH_PROP_LINE_JOIN_ROUND       (0x0001<<6)
#define PATH_PROP_LINE_JOIN_BEVEL       (0x0002<<6)

#define PATH_PROP_FILL_PAINT            (0x0003<<8)
#define PATH_PROP_FILL_PAINT_COLOR      (0x0000)
#define PATH_PROP_FILL_PAINT_LGRAD      (0x0001<<8)
#define PATH_PROP_FILL_PAINT_RGRAD      (0x0002<<8)

#define PATH_PROP_STROKE_PAINT          (0x0003<<10)
#define PATH_PROP_STROKE_PAINT_COLOR    (0x0000)
#define PATH_PROP_STROKE_PAINT_LGRAD    (0x0001<<10)
#define PATH_PROP_STROKE_PAINT_RGRAD    (0x0002<<10)

#define PATH_PROP_FILL_SPREAD           (0x0003<<12)
#define PATH_PROP_FILL_SPREAD_PAD       (0x0000)
#define PATH_PROP_FILL_SPREAD_REPEAT    (0x0001<<12)
#define PATH_PROP_FILL_SPREAD_REFLECT   (0x0002<<12)

#define PATH_PROP_STROKE_SPREAD         (0x0003<<14)
#define PATH_PROP_STROKE_SPREAD_PAD     (0x0000)
#define PATH_PROP_STROKE_SPREAD_REPEAT  (0x0001<<14)
#define PATH_PROP_STROKE_SPREAD_REFLECT (0x0002<<14)

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define GFX_TEXT_PROPERTY_IS_ALIGN_LEFT(prop)   (((prop) & GFX_TEXT_PROPERTY_ALIGN_MASK) == 0)
#define GFX_TEXT_PROPERTY_IS_ALIGN_RIGHT(prop)  (((prop) & GFX_TEXT_PROPERTY_ALIGN_MASK) == GFX_TEXT_PROPERTY_ALIGN_RIGHT)
#define GFX_TEXT_PROPERTY_IS_ALIGN_CENTRE(prop) (((prop) & GFX_TEXT_PROPERTY_ALIGN_MASK) == GFX_TEXT_PROPERTY_ALIGN_CENTRE)

#define GFX_TEXT_PROPERTY_IS_DRAW_NORMAL(prop)  (((prop) & GFX_TEXT_PROPERTY_DRAW_MASK) == 0)
#define GFX_TEXT_PROPERTY_IS_DRAW_REVERSE(prop) (((prop) & GFX_TEXT_PROPERTY_DRAW_MASK) == GFX_TEXT_PROPERTY_DRAW_REVERSE)
#define GFX_TEXT_PROPERTY_IS_DRAW_TRANSP(prop)  (((prop) & GFX_TEXT_PROPERTY_DRAW_MASK) == GFX_TEXT_PROPERTY_DRAW_TRANSP)

#define GFX_TEXT_PROPERTY_IS_CLIP_NORMAL(prop)  (((prop) & GFX_TEXT_PROPERTY_CLIP_MASK) == 0)
#define GFX_TEXT_PROPERTY_IS_CLIP_FIT(prop)     (((prop) & GFX_TEXT_PROPERTY_CLIP_MASK) == GFX_TEXT_PROPERTY_CLIP_FIT)
#define GFX_TEXT_PROPERTY_IS_CLIP_APPEND(prop)  (((prop) & GFX_TEXT_PROPERTY_CLIP_MASK) == GFX_TEXT_PROPERTY_CLIP_APPEND)
#define GFX_TEXT_PROPERTY_IS_CLIP_NONE(prop)    (((prop) & GFX_TEXT_PROPERTY_CLIP_MASK) == GFX_TEXT_PROPERTY_NO_CLIP)

#define GFX_TEXT_PROPERTY_IS_SCROLABLE(prop)    (((prop) & GFX_TEXT_PROPERTY_SCROLABLE) != 0)

/*
** Max index definitions for all dynamic elements
*/
#define MAX_INDEX_SCREEN_INDEX                          (NB_SCREENS)
#define MAX_INDEX_DYN_BITMAPS_INDEX                     (MAX_INDEX_SCREEN_INDEX           	+ NB_DYN_BITMAPS)
#define MAX_INDEX_DYN_TEXTS_INDEX                       (MAX_INDEX_DYN_BITMAPS_INDEX      	+ NB_DYN_TEXTS)
#define MAX_INDEX_DYN_WIDGETS_INDEX                     (MAX_INDEX_DYN_TEXTS_INDEX        	+ NB_DYN_WIDGETS)
#define MAX_INDEX_DYN_CLIP_WIDGETS_INDEX                (MAX_INDEX_DYN_WIDGETS_INDEX      	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_NFILL_INDEX                       (MAX_INDEX_DYN_CLIP_WIDGETS_INDEX 	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_X_BITMAP_INDEX                    (MAX_INDEX_DYN_NFILL_INDEX        	+ NB_ALL_DYN_XY_BITMAPS)
#define MAX_INDEX_DYN_Y_BITMAP_INDEX                    (MAX_INDEX_DYN_X_BITMAP_INDEX     	+ NB_ALL_DYN_XY_BITMAPS)
#define MAX_INDEX_DYN_XY_BITMAP_INDEX                   (MAX_INDEX_DYN_Y_BITMAP_INDEX     	+ NB_ALL_DYN_XY_BITMAPS)
#define MAX_INDEX_DYN_X_DBITMAP_INDEX                   (MAX_INDEX_DYN_XY_BITMAP_INDEX    	+ NB_DYNXY_DIMAGES)
#define MAX_INDEX_DYN_Y_DBITMAP_INDEX                   (MAX_INDEX_DYN_X_DBITMAP_INDEX    	+ NB_DYNXY_DIMAGES)
#define MAX_INDEX_DYN_ALPHA_DBITMAP_INDEX               (MAX_INDEX_DYN_Y_DBITMAP_INDEX    	+ NB_DYNXY_DIMAGES)
#define MAX_INDEX_DYN_X_DTEXT_INDEX                     (MAX_INDEX_DYN_ALPHA_DBITMAP_INDEX	+ NB_DYNXY_TEXTS)
#define MAX_INDEX_DYN_Y_DTEXT_INDEX                     (MAX_INDEX_DYN_X_DTEXT_INDEX      	+ NB_DYNXY_TEXTS)
#define MAX_INDEX_DYN_ALPHA_DTEXT_INDEX                 (MAX_INDEX_DYN_Y_DTEXT_INDEX      	+ NB_DYNXY_TEXTS)
#define MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX                (MAX_INDEX_DYN_ALPHA_DTEXT_INDEX  	+ NB_DYNXY_TEXTS)
#if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
  #define MAX_INDEX_DYN_NBLINES_DTEXT_INDEX             (MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX   + NB_DYNXY_TEXTS)
#else
  #define MAX_INDEX_DYN_NBLINES_DTEXT_INDEX             (MAX_INDEX_DYN_DCOLOR_DTEXT_INDEX)
#endif

#define MAX_INDEX_DYN_X_NFILL_INDEX                     (MAX_INDEX_DYN_NBLINES_DTEXT_INDEX 	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_Y_NFILL_INDEX                     (MAX_INDEX_DYN_X_NFILL_INDEX       	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_W_NFILL_INDEX                     (MAX_INDEX_DYN_Y_NFILL_INDEX       	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_H_NFILL_INDEX                     (MAX_INDEX_DYN_W_NFILL_INDEX       	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_ALPHA_NFILL_INDEX                 (MAX_INDEX_DYN_H_NFILL_INDEX       	+ NB_DYN_FILL_SCREENS)
#define MAX_INDEX_DYN_COLOR_NFILL_INDEX                 (MAX_INDEX_DYN_ALPHA_NFILL_INDEX   	+ NB_DYN_FILL_SCREENS)

#define MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX              (MAX_INDEX_DYN_COLOR_NFILL_INDEX   	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX              (MAX_INDEX_DYN_X_CLIP_WIDGETS_INDEX	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX              (MAX_INDEX_DYN_Y_CLIP_WIDGETS_INDEX	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX              (MAX_INDEX_DYN_W_CLIP_WIDGETS_INDEX	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_X_WIDGETS_INDEX					(MAX_INDEX_DYN_H_CLIP_WIDGETS_INDEX	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_Y_WIDGETS_INDEX					(MAX_INDEX_DYN_X_WIDGETS_INDEX     	+ NB_DYNAMIC_CLIP_WIDGETS)
#define MAX_INDEX_DYN_ALPHA_WIDGETS_INDEX               (MAX_INDEX_DYN_Y_WIDGETS_INDEX     	+ NB_DYNAMIC_CLIP_WIDGETS)

#define MAX_DYNAMIC_ELEMENT_INDEX                       (MAX_INDEX_DYN_ALPHA_WIDGETS_INDEX)

/*
** Get index for dynamic elements
*/
#define GET_SCREEN_INDEX(x)                             (x)
#define GET_DYN_BITMAPS_INDEX(x)                        ((x)-MAX_INDEX_SCREEN_INDEX)
#define GET_DYN_TEXTS_INDEX(x)                          ((x)-MAX_INDEX_DYN_BITMAPS_INDEX)
#define GET_DYN_WIDGETS_INDEX(x)                        ((x)-MAX_INDEX_DYN_TEXTS_INDEX)
#define GET_DYN_CLIP_WIDGETS_INDEX(x)                   ((x)-MAX_INDEX_DYN_WIDGETS_INDEX)
#define GET_DYN_NFILL_INDEX(x)                          ((x)-MAX_INDEX_DYN_CLIP_WIDGETS_INDEX)
#define GET_DYN_XY_BITMAPS_INDEX(x)                     ((x)-MAX_INDEX_DYN_NFILL_INDEX)
#define GET_DYN_X_BITMAPS_INDEX(x)                      ((x)-MAX_INDEX_DYN_NFILL_INDEX)
#define GET_DYN_Y_BITMAPS_INDEX(x)                      ((x)-MAX_INDEX_DYN_X_BITMAP_INDEX)
#define GET_DYN_ALPHA_BITMAPS_INDEX(x)                  ((x)-MAX_INDEX_DYN_Y_BITMAP_INDEX)
/*
** Max index definitions for all static elements
*/
#define MAX_INDEX_FILL_SCREENS_INDEX                    (MAX_DYNAMIC_ELEMENT_INDEX         + NB_FILL_SCREENS)
#define MAX_INDEX_VERT_PATTERN_FILL_INDEX               (MAX_INDEX_FILL_SCREENS_INDEX      + NB_VERT_PATTERN_FILL)
#define MAX_INDEX_HORZ_PATTERN_FILL_INDEX               (MAX_INDEX_VERT_PATTERN_FILL_INDEX + NB_HORZ_PATTERN_FILL)
#define MAX_INDEX_BITMAPS_INDEX                         (MAX_INDEX_HORZ_PATTERN_FILL_INDEX + NB_ALL_BITMAPS)
#define MAX_INDEX_WIDGETS_INDEX                         (MAX_INDEX_BITMAPS_INDEX           + NB_WIDGETS)
#define MAX_INDEX_STEXTS_INDEX                          (MAX_INDEX_WIDGETS_INDEX           + NB_STATIC_TEXTS)
#define MAX_INDEX_SCROLL_INDEX                          (MAX_INDEX_STEXTS_INDEX            + NB_DYN_TEXTS)
#define MAX_ELEMENT_INDEX                               (MAX_INDEX_STEXTS_INDEX)

#define MAX_INDEX_BMP_DRAW_NORMAL_INDEX                 (NB_SXY_BITMAPS)
#define MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX               (MAX_INDEX_BMP_DRAW_NORMAL_INDEX      + NB_SXY_ALPHAMAP)
#define MAX_INDEX_BMP_DRAW_OVGMAP_INDEX                 (MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX    + NB_SXY_OVG)
#define MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX             (MAX_INDEX_BMP_DRAW_ALPHAMAP_INDEX    + NB_SXY_COLORTRANSBITMAP)
#define MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX            (MAX_INDEX_BMP_DRAW_COLORTRANS_INDEX  + NB_SXY_ALPHABITMAP)
#define MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX            (MAX_INDEX_BMP_DRAW_ALPHABITMAP_INDEX + NB_SXY_UNIALPHAMAP)
#define MAX_INDEX_BMP_DRAW_UNIALPHABITMAP_INDEX         (MAX_INDEX_BMP_DRAW_UNIALPHAMAP_INDEX + NB_SXY_UNIALPHABITMAP)

#define MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX          (NB_DYN_XY_BITMAPS)
#define MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX        (MAX_INDEX_DYN_XY_BMP_DRAW_NORMAL_INDEX      + NB_DYN_XY_ALPHAMAP)
#define MAX_INDEX_DYN_XY_BMP_DRAW_OVGMAP_INDEX          (MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX    + NB_DYN_XY_OVG)
#define MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX      (MAX_INDEX_DYN_XY_BMP_DRAW_ALPHAMAP_INDEX    + NB_DYN_XY_COLORTRANSBITMAP)
#define MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX     (MAX_INDEX_DYN_XY_BMP_DRAW_COLORTRANS_INDEX  + NB_DYN_XY_ALPHABITMAP)
#define MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX     (MAX_INDEX_DYN_XY_BMP_DRAW_ALPHABITMAP_INDEX + NB_DYN_XY_UNIALPHAMAP)
#define MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHABITMAP_INDEX  (MAX_INDEX_DYN_XY_BMP_DRAW_UNIALPHAMAP_INDEX + NB_DYN_XY_UNIALPHABITMAP)
/*
** Get index for static elements
*/
#define GET_FILL_SCREENS_INDEX(x)                       ((x)-MAX_DYNAMIC_ELEMENT_INDEX)
#define GET_VERT_PATTERN_FILL_INDEX(x)                  ((x)-MAX_INDEX_FILL_SCREENS_INDEX)
#define GET_HORZ_PATTERN_FILL_INDEX(x)                  ((x)-MAX_INDEX_VERT_PATTERN_FILL_INDEX)
#define GET_BITMAPS_INDEX(x)                            ((x)-MAX_INDEX_HORZ_PATTERN_FILL_INDEX)
#define GET_WIDGETS_INDEX(x)                            ((x)-MAX_INDEX_BITMAPS_INDEX)
#define GET_STEXTS_INDEX(x)                             ((x)-MAX_INDEX_WIDGETS_INDEX)

#if GFX_TOUCH_SCREEN_ENABLED > 0
   #define GFX_MOUSE_MOVE_EV    (0)
   #define GFX_MOUSE_DOWN_EV    (1)
   #define GFX_MOUSE_CANCEL_EV  (2)
   #define GFX_MOUSE_UP_EV      (3)
#endif

#if GFX_MGR01_MAX_SEGMENTS > 16
 typedef UINT32 HMI_SEG;
#else
 typedef UINT16 HMI_SEG;
#endif

#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
	#if(GFX_COLOR_MODE == GFX_FOUR_GS)
			typedef enum
			{
			   GFX_SEG_WHITE = 0,
			   GFX_SEG_LIGHT_GRAY = 1,
			   GFX_SEG_DARK_GRAY = 3,
			   GFX_SEG_BLACK = 7
			}GFX_SEG_COLOR;
      #define GFX_SEG_DEFAULT GFX_SEG_WHITE
	#elif(GFX_COLOR_MODE == GFX_SIXTEEN_GS)
		typedef enum
		{
		   GFX_SEG_GS0 = 0,
		   GFX_SEG_GS1,
		   GFX_SEG_GS2,
		   GFX_SEG_GS3,
		   GFX_SEG_GS4,
		   GFX_SEG_GS5,
		   GFX_SEG_GS6,
		   GFX_SEG_GS7,
		   GFX_SEG_GS8,
		   GFX_SEG_GS9,
		   GFX_SEG_GS10,
		   GFX_SEG_GS11,
		   GFX_SEG_GS12,
		   GFX_SEG_GS13,
		   GFX_SEG_GS14,
		   GFX_SEG_GS15
		}GFX_SEG_COLOR;
      #define GFX_SEG_DEFAULT GFX_SEG_GS0
	#endif
#endif
/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
#ifdef GFX_OPEN_VG
typedef struct
{
   VGfloat rgba[4];
}OVG_COLOR_DEF_T;

typedef struct
{
   VGfloat         bbox[4];
   VGfloat         matrix[9];
   UINT32          stop_length;
   VGfloat const * stop_table;
}OVG_LGRAD_DEF_T;

typedef struct
{
   VGfloat         bbox[5];
   VGfloat         matrix[9];
   UINT32          stop_length;
   VGfloat const * stop_table;
}OVG_RGRAD_DEF_T;

typedef struct
{
   UINT16          attributes;
   UINT16          numSegments;
   VGfloat         mitter_limit;
   VGfloat         stroke_width;
   void    const * fillPaint;
   void    const * strokePaint;
   VGubyte const * pathSegments;
   VGfloat const * pathData;
}OVG_PATH_DEF_T;

typedef struct
{
   UINT32                 num_paths_u8;
   VGfloat                bounds[4];    /* X, Y, Width, Height */
   OVG_PATH_DEF_T const * path_array_u32ap;
}OVG_OBJECT_T;
#endif

#if MAX_ELEMENT_INDEX <= 256
   typedef UINT8  GFX_ELEMENT_ID_T;
#else
   typedef UINT16 GFX_ELEMENT_ID_T;
#endif

#if defined(WIN32) || defined(WINCE) || defined(GFX_OPEN_VG)
   typedef SINT32 GFX_SIZE_W_T;
   typedef SINT32 GFX_SIZE_X_T;
   typedef SINT32 GFX_SIZE_H_T;
   typedef SINT32 GFX_SIZE_Y_T;
   typedef SINT32 GFX_ELEMENT_DATA_T;
#else
 typedef UINT16  GFX_SIZE_W_T;
 typedef UINT16  GFX_SIZE_H_T;

 typedef SINT16  GFX_SIZE_X_T;
 typedef SINT16  GFX_SIZE_Y_T;
 #if (GFX_MAX_ELEMENT_DATA_LENGTH <= 255) && \
    (GFX_MAX_H_LENGTH            <= 255) && \
    (GFX_MAX_W_LENGTH            <= 255) && \
    (GFX_SCROLABLE_TEXT_SUPPORT  == 0  )
   typedef UINT8  GFX_ELEMENT_DATA_T;
 #else
   typedef UINT16 GFX_ELEMENT_DATA_T;
 #endif
#endif

#if GFX_MAX_TEXT_LENGTH <= 255
   typedef UINT8  GFX_TEXT_LENGTH_T;
#else
   typedef UINT16 GFX_TEXT_LENGTH_T;
#endif

#define GFX_SCREEN_CHANGED_FLAG  (0x01U)
#if NB_SCREENS <= 255
   typedef UINT8  SCREEN_ID_T;
#else
   typedef UINT16 SCREEN_ID_T;
#endif

#if GFX_UNICODE_ENABLED
   typedef UINT16 GFX_CHAR;
#else
   typedef UINT8  GFX_CHAR;
#endif

#if (GFX_MAX_ELEMENT_DATA_LENGTH <= 255)
   typedef UINT8  DYN_BITMAP_DATA_T;
   typedef UINT8  DYN_WIDGET_DATA_T;
#else
   typedef UINT16 DYN_BITMAP_DATA_T;
   typedef UINT16 DYN_WIDGET_DATA_T;
#endif

typedef UINT8 GFX_FONT_ID_T;

#if GFX_PIX_FORMAT <= GFX_8BPP
   typedef UINT8  GFX_COLOR_T;
#elif GFX_PIX_FORMAT <= GFX_RGB565
   typedef UINT16 GFX_COLOR_T;
#elif GFX_PIX_FORMAT == GFX_ARGB8888
   typedef UINT32 GFX_COLOR_T;
#else
   #error "Unsupported Color Depth \n"
#endif

#if GFX_PIX_FORMAT == GFX_SEG
  #if GFX_MAX_BACK_PLANES > 4
   typedef UINT16  GFX_FB_COLOR_T;
  #else
   typedef GFX_COLOR_T GFX_FB_COLOR_T;
  #endif
#else
  typedef GFX_COLOR_T GFX_FB_COLOR_T;
#endif


typedef UINT8 GFX_ALPHA_T;

/*
** Strcuture to specify the co-ordinate
*/
typedef struct
{
   GFX_SIZE_X_T  x;
   GFX_SIZE_Y_T  y;
   UINT8 alpha;   
#ifdef GFX_OPEN_VG
   VGfloat       matrix[9];
   VGfloat       px;
   VGfloat       py;
   VGfloat       alpha;
   VGfloat       reflection_height;
   VGfloat       reflection_dist2surf;
   OVG_OBJECT_T const * p_ovg;
#endif
}COORDINATE_DEF_T;

/*
** Strcuture to specify a rectangle area
*/
typedef struct
{
   GFX_SIZE_X_T  x;
   GFX_SIZE_Y_T  y;
   GFX_SIZE_W_T  w;
   GFX_SIZE_H_T  h;
}RECTANGLE_DEF_T;

/*
** This structure is to specify extended properties for Text element
** draw_color - drawing color ro be used for the text.
** nb_lines   - number of lines to be used.
*/
typedef struct
{
   COORDINATE_DEF_T coord;  /* co-ordinate for this element                      */
   GFX_COLOR_T      draw_color;
#if (GFX_MULTI_LINE_TEXT_ENABLED > 0)
   UINT8            nb_lines;
#endif
}GFX_TEXT_PROPERTY;

/*
** Data structure to specify an elements property
*/
typedef struct
{
   GFX_ELEMENT_ID_T  id;    /* unique ID of the element                                */
#ifdef GFX_INDEPENDANT_PROPERTY_ENABLED
   void      const * prop;  /* pointer to any property for this element. could be null */
#endif
}GFX_ELEMENT_PROPERTY;

/*
** Data structure to hold a list of element property.
*/
typedef struct
{
   UINT16                        nb_elements;
   GFX_ELEMENT_PROPERTY const * element_table;
}GFX_ELEMENT_LIST;

typedef struct
{
#if defined(GFX_ALIGNED_WIDGETS_ENABLED) || defined(GFX_CLIPPED_WIDGETS_ENABLED)
   UINT8            property;
#endif
#if defined(GFX_ALIGNED_WIDGETS_ENABLED)
   UINT8            inter_element_space;
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   UINT8            clip_index;
#endif
   GFX_ELEMENT_LIST list;
}WIDGET_DEF_T;

typedef struct
{
   RECTANGLE_DEF_T clip;
   COORDINATE_DEF_T dyn_prop;   
#ifdef GFX_OPEN_VG
   VGfloat matrix[9];
#endif
}WIDGET_PROPERTY_T;

typedef struct
{
  UINT16  widget_id;
  UINT16  widget_index;
}WIDGET_ACTIVE_PATH_DEF_T;

typedef struct
{
  RECTANGLE_DEF_T            area;
  UINT16                     widget_id;
  UINT16                     num_path;
  WIDGET_ACTIVE_PATH_DEF_T * selection_path;
}WIDGET_TOUCH_INFO_DEF_T;

typedef struct
{
   UINT8        priority;
#if NB_LAYERS > 1
   UINT8        layerid;
#endif
   WIDGET_DEF_T widget;
#if GFX_TOUCH_SCREEN_ENABLED > 0
   UINT16                    no_touch_points;
   WIDGET_TOUCH_INFO_DEF_T * touch_points_table;
#endif
}SCREEN_TABLE_T;

typedef struct
{
   GFX_SIZE_W_T        width;
   GFX_SIZE_H_T        height;
   UINT8               nb_priority;
#if GFX_PIX_FORMAT >= GFX_8BPP
   UINT8               pix_format;
#endif
#if NB_LAYERS > 1 || GFX_PIX_FORMAT >= GFX_8BPP
   COORDINATE_DEF_T  * coord_ptr;
#endif
#if (GFX_PIX_FORMAT == GFX_1BPP_SEG)||(GFX_PIX_FORMAT == GFX_SEG)
   UINT8               layer_type;
   UINT8			  *icon_mask;
#endif
#if GFX_PIX_FORMAT >= GFX_8BPP
   GFX_ALPHA_T       * alpha_ptr;
#endif
   SCREEN_ID_T       * psid_tptr;
}LAYER_TABLE_T;


typedef struct
{
   UINT8             properties;
   GFX_SIZE_W_T      width;
   UINT8             font_id;
   GFX_TEXT_LENGTH_T length;
#ifdef GFX_CLIP_APEND_STRING_CONFIGED
   GFX_SIZE_W_T      ap_str_width;
#endif
#ifdef GFX_CLIP_APEND_STRING_CONFIGED
   GFX_CHAR        * ap_str;
#endif
   GFX_CHAR        * data_ptr;
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
   GFX_SEG_COLOR           *  seg_color;
#endif
}DYN_TEXT_DEF_T;

#ifdef GFX_OPEN_VG

typedef struct
{
   VGImageFormat format;
   VGint         stride;
   GFX_SIZE_W_T  w;
   GFX_SIZE_H_T  h;
   void const  * bmp_data;
}BITMAP_DEF_T;

typedef struct
{
   GFX_SIZE_X_T  cx;
   GFX_SIZE_Y_T  cy;
   GFX_SIZE_W_T  cw;
   GFX_SIZE_H_T  ch;
   OVG_OBJECT_T const * ovg_data;
}OVGMAP_DEF_T;

typedef struct
{
   VGImageFormat format;
   VGint         stride;
   GFX_SIZE_W_T  w;
   GFX_SIZE_H_T  h;
#ifdef GFX_MGR_USE_INT_RGB
   GFX_COLOR_T   draw_color;
#else
   VGfloat       draw_color[4]; /* RGBA format */
#endif
   void const  * alpha_data;
}ALPHAMAP_DEF_T;

typedef struct
{
   GFX_SIZE_W_T  width;
   GFX_SIZE_H_T  height;
#ifdef GFX_MGR_USE_INT_RGB
   GFX_COLOR_T   color;
#else
   VGfloat       color[4];  /* RGBA format */
#endif
}FILL_SCREEN_DEF_T;

typedef struct
{
   VGImageFormat format;
   VGint         stride;
   GFX_SIZE_W_T  bmp_width;
   GFX_SIZE_H_T  bmp_height;
   GFX_SIZE_W_T  width;
   GFX_SIZE_H_T  height;
   void const  * bmp_data;
}HV_FILL_PATTERN_DEF_T;

typedef struct
{
   COORDINATE_DEF_T   pivot;
   VGfloat            matrix[9];
}GFX_OVG_DYNAMIC_PROPERTY;

typedef struct
{
   COORDINATE_DEF_T            translation;
   OVG_OBJECT_T              * p_ovg;
}GFX_OVG_OBJ_PROPERTY;

#else

typedef struct
{
   GFX_SIZE_W_T  width;
   GFX_SIZE_H_T  height;
   GFX_COLOR_T   color;
}FILL_SCREEN_DEF_T;

typedef struct
{
#if GFX_COMPRESSED_IMAGES > 0
   UINT8                    info;
   UINT32                   data_size;
#endif
   GFX_SIZE_W_T             w;
   GFX_SIZE_H_T             h;
   GFX_COLOR_T      const * bmp_data;
}BITMAP_DEF_T;

typedef struct
{
   GFX_SIZE_W_T  w;
   GFX_SIZE_H_T  h;
   GFX_COLOR_T   color;
   GFX_ALPHA_T      const * alpha_data;
}ALPHAMAP_DEF_T;

typedef struct
{
#if GFX_COMPRESSED_IMAGES > 0
   UINT8               info;
   UINT32              data_size;
#endif
   GFX_SIZE_W_T        w;
   GFX_SIZE_H_T        h;
   GFX_ALPHA_T         alpha;
   GFX_COLOR_T      const * bmp_data;
}UNIALPHABITMAP_DEF_T;

typedef struct
{
   GFX_SIZE_W_T       w;
   GFX_SIZE_H_T       h;
   GFX_COLOR_T        color;
   GFX_ALPHA_T        alpha;
}UNIALPHAMAP_DEF_T;

typedef struct
{
#if GFX_COMPRESSED_IMAGES > 0
   UINT8               info;
   UINT32              data_size;
#endif
   GFX_SIZE_W_T        w;
   GFX_SIZE_H_T        h;
   GFX_COLOR_T      const * bmp_data;
   GFX_ALPHA_T      const * alpha_data;
}ALPHABITMAP_DEF_T;

typedef struct
{
#if GFX_COMPRESSED_IMAGES > 0
   UINT8               info;
   UINT32              data_size;
#endif
   GFX_SIZE_W_T        w;
   GFX_SIZE_H_T        h;
   GFX_COLOR_T         color;
   GFX_COLOR_T      const * bmp_data;
}COLORTRANSMAP_DEF_T;

typedef struct
{
   GFX_SIZE_W_T        width;
   GFX_SIZE_H_T        height;
   GFX_COLOR_T const * bmp_data;
}HV_FILL_PATTERN_DEF_T;

#endif

typedef struct
{
   SINT8 x_soffset;
   SINT8 x_eoffset;
   SINT8 y_soffset;
   UINT8 owidth;
   UINT8 width;
   UINT8 height;
   UINT8 const * fdata;
}GFX_FONT_CHAR_CONFIG;

typedef struct
{
   GFX_CHAR                     ch_code;
   UINT8                        attributes;
   GFX_FONT_CHAR_CONFIG const * fcc_ptr;
}GFX_FONT_LUT;

typedef struct
{
   GFX_CHAR             size_table;
   UINT8                is_group;
   union
   {
      UINT8                   height;
      UINT8                   group_sel_index;
   }p;
#if defined (GFX_MGR01_DEFAULT_FONT)
   UINT8                      default_index;
#else
   UINT8                      unused_index;
#endif
   union
   {
      void                 const * ptr;
      GFX_FONT_LUT         const * lut_ptr;
      UINT8                const * grp_ptr;
   }f;
}GFX_FONT;

#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
typedef struct
{
    HMI_SEG   lower_32_seg_val;
  #if GFX_MGR01_MAX_SEGMENTS > 32
    HMI_SEG   higher_32_seg_val;
  #endif
}GFX_CHAR_BIT_MASK_VAL;

typedef struct
{
   GFX_CHAR                ch_unicode;
   GFX_CHAR_BIT_MASK_VAL   const *   ch_bit_mask_data; /* Exact char bit mask values of a passed unicode */
}GFX_CHAR_BIT_MASK;


typedef struct
{
   UINT8     seg_per_char_U8;
   UINT8     no_of_char_U8;
   UINT8     char_range_U8[2];
   UINT16 const *char_pos_U8P;
   GFX_CHAR_BIT_MASK  const   *char_bit_mask_ptr;  /* Containere of all bit mask data values with corresopning unicodes */
   UINT8     actual_char_entries;
}GFX_SEG_FONT;
#endif

#if GFX_TOUCH_SCREEN_ENABLED > 0
typedef struct
{
   UINT32 x;
   UINT32 y;
   UINT32 btn_id;
   UINT32 button_state;
   UINT32 btn_ev;
}GFX_TOUCH_EVENT;

typedef struct
{
   UINT32 x;
   UINT32 y;
   UINT32 event;
}GFX_TOUCH_QDATA;
#endif

/*
** Data structure to specify an text width info property
*/
#if NB_DYN_TEXTS > 0 || NB_STATIC_TEXTS > 0
typedef struct
{
   GFX_CHAR      *input_str_ptr;                  /* original string */
   GFX_SIZE_W_T   tot_available_width;           /* available width */
   GFX_CHAR       disp_str_ptr[MAX_TEXT_LENGTH];  /* display string */
   GFX_SIZE_W_T   disp_width;                     /* display width */
   GFX_SIZE_X_T   disp_len;                       /* display length */
   UINT8          text_clip_flag;                 /* status of text clipping */     
   UINT8          getTotalStringWidth;            /* Flag to get total width of string */
}GFX_TEXT_WIDTH_INFO_DEF_T;
#endif

#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
typedef enum
{
   LEFT_CLIP = 0,
   RIGHT_CLIP,
   CLIP_MAX
}GFX_CLIP_INFO;
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

extern void GfxManagerInitialize(void);
extern void GfxManagerExit(void);
extern UINT8 GfxManagerSelectGroupFontIndex(GFX_ELEMENT_ID_T p_font_id, GFX_ELEMENT_DATA_T p_selection_index);

#if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
  extern UINT8 GfxManagerBuildScreen(UINT8 p_post_copy_flag_U8);
#else
  extern UINT8 GfxManagerBuildScreen(void);
#endif

void GfxManager_set_screen_changed_status(void);


#ifdef GFX_OPEN_VG
void GfxManagerRotate(GFX_ELEMENT_ID_T p_element, VGfloat p_rotate);
void GfxManagerScale(GFX_ELEMENT_ID_T p_element, VGfloat p_scale_x, VGfloat p_scale_y);
void GfxManagerTranslate(GFX_ELEMENT_ID_T p_element, VGfloat p_tx, VGfloat p_ty);
void GfxManagerSetReflection(GFX_ELEMENT_ID_T p_element, VGfloat p_distance, VGfloat p_height);
void GfxManagerSetAlpha(GFX_ELEMENT_ID_T p_element, VGfloat p_alpha);
void GfxManagerSetMatrix(GFX_ELEMENT_ID_T p_element, VGfloat * matrix);
void GfxManagerReSetMatrix(GFX_ELEMENT_ID_T p_element);
#endif
#if NB_DYN_ELEMENTS > 0
extern void GfxManagerSendEvent(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data);
extern UINT8 GfxManagerGetEvent(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T *p_data);
extern void GfxManagerSetDynScreenPriority(GFX_ELEMENT_ID_T p_element, GFX_ELEMENT_DATA_T p_data, UINT8 p_priority);
extern void GfxManagerSetDefaultProperties(GFX_ELEMENT_ID_T p_element);
#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
extern void GfxManagerSetScreenDynPosition(GFX_ELEMENT_ID_T p_element, GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y);
#endif
#if NB_DYN_TEXTS > 0
    extern void GfxManagerSendText(GFX_ELEMENT_ID_T p_element, GFX_CHAR const *p_str);
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
      extern void GfxManagerSetTextColor(GFX_ELEMENT_ID_T p_element,GFX_SEG_COLOR p_color_value);    
#endif
    extern GFX_CHAR const *GfxManagerGetText(GFX_ELEMENT_ID_T p_element);
    extern void GfxManagerGetTextFitWidth(GFX_ELEMENT_ID_T p_element, GFX_TEXT_WIDTH_INFO_DEF_T *p_txt_info_S);
#endif
#if NB_DYN_BITMAPS > 0
#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
   extern void GfxManagerSetIcon(GFX_ELEMENT_ID_T p_element,
#if defined(GFX_MGR01_MULTI_COLOR_SUPPORT)
                                 GFX_SEG_COLOR color_value
#else
                                 BOOLEAN state_b
#endif
   );
#endif
#endif
#endif

#if GFX_TOUCH_SCREEN_ENABLED > 0
  void GfxManagerProcessTouchEvents(void);
  void GfxManagerPushTouchEvent(GFX_TOUCH_QDATA * p_touch_data_SP);
#endif

#undef EXTERN
#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
extern void GfxDriverSegmentBuildText(DYN_TEXT_DEF_T const * pc_dyn_text_def_SP);
#endif
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
Date              :  25-Sep-2018
By                :  arajase2
Traceability      :  1201732: Gfx Mgr01 - Segmented display related code to be protected
Change Description:  Protection added for the below structures to avoid the inclusion in non segmented code
                     GFX_CHAR_BIT_MASK_VAL
                     GFX_CHAR_BIT_MASK
                     GFX_SEG_FONT

Date              :  29-Jan-2018
By                :  sbollam
Traceability      :  1039129
Change Description:  Extend no'of segments to 64/char and no'of back planes to 8.

Date              :  14-APR-2017
By                :  kkubendi
Traceability      :  791443
Change Description:  GFX01/HyundaiQxC: Update Graphics Manager 01 to support XY,Alpha animation, 
					 Alpha and Image blending.

Date              :  09-AUG-2016
By                :  sbollam
Traceability      :  660802
Change Description:  Newton2.0 - 32bit segment support
Date              :  19-JAN-2015
By                :  adevi
Traceability      :  491345
Change Description:  Font grouping and dynamic font id change interface.

Date              :  13-JAN-2015
By                :  sanand2
Traceability      :  491347
Change Description:  Append string feature update.

Date              :  28-DEC-2015
By                :  adevi
Traceability      :  489987
Change Description:  Dynamic screen position change interface introduced.

Date              :  12-OCT-2015
By                :  adevi
Traceability      :  430157
Change Description:  GfxManagerSetDefaultProperties interface introduced.

Date              :17/7/2015
By                :adevi
Traceability      :RTC 368488
Change Description:New interface added to set dynamic screen priority.

Date              :  06-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  QAC 8.1.2 Warnings resolved.

Date              :  12-Dec-2014
By                :  adevi
Traceability      :
Change Description:  1. MAX_INDEX_SCROLL_INDEX macro introduced.

Date              :03/12/2014
By                :adevi
Traceability      :
Change Description:getTotalStringWidth member added in GFX_TEXT_WIDTH_INFO_DEF_T
                   structure.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :27/8/2014
By                :adevi
Traceability      :
Change Description:GFX_TEXT_WIDTH_INFO_DEF_T structure definition made when
                   NB_STATIC_TEXTS or NB_DYN_TEXTS is > 0.
-----------------------------------------------------------------------------*/
