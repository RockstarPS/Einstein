/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_anim_engine_types.h
**
** Description:    type definitions for the animation engine
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_ANIM_ENGINE_TYPES_H
#define HMI_GFX_ANIM_ENGINE_TYPES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_anim_engine_cfg.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#ifndef GFX_ANIM02_NULL_PTR
 #define GFX_ANIM02_NULL_PTR    ((void *)0)
#endif
#ifndef GFX_ANIM_NULL_HANDLER
 #define GFX_ANIM_NULL_HANDLER  ((void *)0)
#endif

typedef UINT32 (ANIM_APP_INTERPOLATE_CB)(UINT32 p_cur_step, UINT32 p_max_step);
typedef UINT32 (ANIM_APP_GOTO_CONDN_CB)(UINT32 p_cur_step);

#if defined (GFX_ANIM_APP_CB_WITH_ANIM_ID)
typedef void (ANIM_APP_CB)(UINT32 p_cur_frame, UINT32 p_total_frames, UINT32 p_current_anim_id);
#else
typedef void (ANIM_APP_CB)(UINT32 p_cur_frame, UINT32 p_total_frames);
#endif
typedef float ANIM_FLOAT;

enum
{
   ANIM_TYPE_ALPHA,
   ANIM_TYPE_AREA,
   ANIM_TYPE_WD_HT,
   ANIM_TYPE_COLOR,
   ANIM_TYPE_DATA,
   ANIM_TYPE_GO_TO,
   ANIM_TYPE_MAL,
   ANIM_TYPE_MAP,
   ANIM_TYPE_SCREEN,
   ANIM_TYPE_SCROLL_UP,
   ANIM_TYPE_SCROLL_DN,
   ANIM_TYPE_ROTATE,
   ANIM_TYPE_SCALE,
   ANIM_TYPE_TRANSFORM,
   ANIM_NUM_TYPES
};

typedef struct
{
   SINT16 x;
   SINT16 y;
}GFX_ANIM_POINT_T;

typedef struct
{
   UINT32 argb;
}GFX_ANIM_ARGB_T;

typedef struct
{
   SINT16 w;
   SINT16 h;
}GFX_ANIM_SIZE_T;

typedef struct
{
   SINT16 x;
   SINT16 y;
   SINT16 w;
   SINT16 h;
}GFX_ANIM_RECT_T;

typedef struct
{
    GFX_ANIM_POINT_T end;
}GFX_ANIM_MAL_T;

typedef struct
{
    GFX_ANIM_MAL_T   def_val;
    GFX_ANIM_MAL_T * cur_val;
}GFX_ANIM_MAL_DYN_T;

typedef struct
{
   GFX_ANIM_ARGB_T start;
   GFX_ANIM_ARGB_T end;
}GFX_ANIM_COLOR_T;

typedef struct
{
    UINT8   start;
    UINT8   end;
}GFX_ANIM_ALPHA_T;

typedef struct
{
    GFX_ANIM_ALPHA_T   def_val;
    GFX_ANIM_ALPHA_T * cur_val;
}GFX_ANIM_ALPHA_DYN_T;

typedef struct
{
    SINT16   start;
    SINT16   end;
}GFX_ANIM_DATA_T;

typedef struct
{
    GFX_ANIM_RECT_T  end;
}GFX_ANIM_AREA_T;

typedef struct
{
    GFX_ANIM_AREA_T   def_val;
    GFX_ANIM_AREA_T * cur_val;
}GFX_ANIM_AREA_DYN_T;

typedef struct
{
   GFX_ANIM_SIZE_T end;
}GFX_ANIM_WDHT_T;

typedef struct
{
   UINT16 goto_frame;
   UINT16 repeat_cnt;
}GFX_ANIM_GOTO_T;

typedef struct
{
   UINT16       num_points;
   GFX_ANIM_POINT_T * points;
}GFX_ANIM_MAP_T;

typedef struct
{
    ANIM_FLOAT angle;
}GFX_ANIM_ROTATE_T;

typedef struct
{
    ANIM_FLOAT scale;
}GFX_ANIM_SCALE_T;

typedef struct
{
    ANIM_FLOAT  matrix[9];
}GFX_ANIM_TRANSFORM_T;

typedef struct
{
   union
   {
      void                    * fn;
      ANIM_APP_INTERPOLATE_CB * user_ip;
      ANIM_APP_GOTO_CONDN_CB  * user_goto;
      UINT8                   * goto_count;
   }handler;
   union
   {
      void                 * all;
      GFX_ANIM_ALPHA_T     * alpha;
      GFX_ANIM_AREA_T      * area;
      GFX_ANIM_WDHT_T      * wd_ht;
      GFX_ANIM_COLOR_T     * color;
      GFX_ANIM_DATA_T      * data;
      GFX_ANIM_GOTO_T      * go_to;
      GFX_ANIM_MAL_T       * mal;
      GFX_ANIM_MAP_T       * map;
      GFX_ANIM_ROTATE_T    * rotate;
      GFX_ANIM_SCALE_T     * scale;
      GFX_ANIM_TRANSFORM_T * transform;
      GFX_ANIM_MAL_DYN_T   * dyn_mal;
      GFX_ANIM_AREA_DYN_T  * dyn_area;
	  GFX_ANIM_ALPHA_DYN_T * dyn_alpha;
   }val;
   union
   {
	   UINT32 const * static_elem_list;       /* list of elements in this animation type */
	   UINT32       * dynamic_elem_list;      /* list of elements in this animation type */
   }elem_list;   
   UINT32         start_time;      /* reuse for goto frame */
   UINT32         duration;        /* reuse for goto count */
   UINT16         rate;            /* rate in mSec * 10 */
   UINT8          num_elements;    /* number of elements in elem_list */
   UINT8          type:7;          /* mal, map, goto etc. */
   UINT8          dynamic_data:1;  /* if hander is valid or not */
}GFX_ANIM_TYPES_DEF_T;

typedef struct
{
   UINT16                        rate;
   UINT8                         num_types;
   UINT32                        duration;
   union 
   {
      GFX_ANIM_TYPES_DEF_T const *static_types;
      GFX_ANIM_TYPES_DEF_T       *dynamic_types;
   }types;          
   UINT8                         read_only_flag;
}GFX_ANIM_FRAME_DEF_T;

typedef struct
{
   UINT32                       num_frames:8;
   UINT32                       duration  :24;
   GFX_ANIM_FRAME_DEF_T const * frames;
   ANIM_APP_CB                * cb;
}GFX_ANIM_DEF_T;

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

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
** CMS Rev 1.7      15-Jun-17 arajase2
** 889840: CMFB MISRA Warning fixes animation.core -  SPRINT43
** Introduced float32_t typedefinition and used this instead of float
**
** CMS Rev 1.6      10-May-17 arajase2
** 844701: CMFB MISRA Warning fixes - animation.core

** CMS Rev 1.5      30-Apr-13    EMANOJ1
** GFX_ANIM_MAL_DYN_T added to support dynamic MAL animations
**
** CMS Rev 1.4      11-Apr-13    EMANOJ1
** Start value removed for MAL, AREA and WhHt Animations as they are offset based 
**
** CMS Rev 1.2      05-Apr-13    EMANOJ1
** Added cur frame parameter to go to condition check function
**
** CMS Rev 1.1      20-Mar-13    EMANOJ1
** Added support for an application callback function in GFX_ANIM_DEF_T
**
** CMS Rev 1.0      27-Nov-12    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
