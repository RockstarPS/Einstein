/*=============================================================================
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
 ** Name:           hmi_gfx_mgr02_layout.c
 **
 ** Description:    
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#ifndef HMI_GFX_MGR02_LAYOUT_C
#define HMI_GFX_MGR02_LAYOUT_C
#define HMI_GFX_MGR02_PRIV_C

/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#if defined(WIN32)
#include <windows.h>
#endif
#include <math.h>
#include <float.h>
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_perflog.h"
#if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT)||defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
  #include "hmi_gfx_mgr02_generic.h"
  #include "hmi_gfx_mgr02_dirty_area.h"
#else
  #include "hmi_gfx_mgr02_context.h"
#endif

#if defined(GFX_MGR02_KEPLER)
  #include "hmi_gfx_mgr02_dcu.h"
  #include "hmi_gfx_mgr02_driver.h"
    #ifndef GFX_MGR02_EXT_FONT_ENGINE
      #error "GFX_MGR02_EXT_FONT_ENGINE should be defined for KeplerI Platform"
    #endif
#else
    #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
      #ifndef GFX_MGR02_EXT_FONT_ENGINE
        #error "External font engine should be configured in cfg since its used in GDT Tool"
      #endif
    #endif
#endif

#ifdef GFX_MGR02_IRIS_SIG_UNIT_ENABLED
  #include "hmi_gfx_mgr02_safety.h"
#endif

#if defined(GFX_MGR02_AMBER)
  #include "hmi_gfx_mgr02_amber.h"
#endif

#if defined(GFX_MGR02_AMBER_IRIS)
  #include "hmi_gfx_mgr02_amber_iris.h"
#endif

#if defined(GFX_MGR02_TRAVEO2)
  #include "hmi_gfx_mgr02_tv2.h"
  #include "hmi_gfx_mgr02_amber_iris.h"
#endif

#if defined(GFX_MGR02_IMXRT)
  #include "hmi_gfx_mgr02_imxrt.h"
#endif

#if defined(GFX_MGR02_IMXRT_PXP)
  #include "hmi_gfx_mgr02_imxrt_pxp.h"
  #include "hmi_gfx_mgr02_imxrt_lcdif.h"
#endif

#if defined(GFX_MGR02_SOFTWARE)
  #ifdef GFX_MGR02_USE_TIDSS
  #include "hmi_gfx_mgr02_tidss_dispif.h"
  #endif
#endif

#if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)
#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
 #include "hmi_gfx_mgr02_devanagari.h"
#endif
#include "hmi_gfx_mgr02_gsub.h"
#endif

#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_image_data.h"
#include "hmi_gfx_mgr02_text.h"

#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
#if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_DEFAULT)
  #include "hmi_bidi_algo.h"
#endif
#endif

#if defined(WIN32) || defined(MATLAB_MEX_FILE)
#if !defined(NUNIT_TESTING) && !defined(GFX_MGR02_OPEN_GL) && !defined(GFX_MGR02_AMBER)
#include <stdio.h>
#include "hmi_gfx_dcu_sim_w32.h"
#endif
#endif

#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
#include "hmi_lang_pre_render.h"
#endif

#ifdef  __cplusplus
extern "C" {
#endif
/*=============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#define HMI_GFX_MGR02_ELEMENT_VISIBLE      (2)
#define HMI_GFX_MGR02_ELEMENT_INVISIBLE    (1)
#define HMI_GFX_MGR02_ELEMENT_INVALID      (0)

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_OVG
#elif defined(GFX_MGR02_FUJITSU)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_FJT
#elif defined(GFX_MGR02_AMBER)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_ABR
#elif defined(GFX_MGR02_AMBER_IRIS)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_IRS
#elif defined(GFX_MGR02_TRAVEO2)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_TRAVEO2
#elif defined(GFX_MGR02_IMXRT)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_IMXRT
#elif defined(GFX_MGR02_IMXRT_PXP)
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_IMXRT_PXP
#else   
   #define GFX_MGR_RESET_ANIM_PROPERTIES    GFX_MGR02_PLATFORM_DCU
#endif
/*
** Bit operation macros to Check,Set and Clear the manager flags
*/
#define GFX_MGR02_IS_CHANGED(flag_array, obj_id) ((((flag_array)[(UINT8)(((UINT16)(obj_id))>>3U)]) & ((UINT8)(((UINT8)1)<<(((UINT16)(obj_id))&0x07U)))) != ((UINT8)0))
#define GFX_MGR02_SET_FLAG(flag_array, obj_id)   ((flag_array)[(UINT8)(((UINT16)(obj_id))>>3U)]   |= ((UINT8)(((UINT8)1)<<(((UINT16)(obj_id))&0x07U))))
#define GFX_MGR02_CLR_FLAG(flag_array, obj_id)   (((flag_array)[(UINT8)(((UINT16)(obj_id))>>3U)]) &= (UINT8)~(UINT8)(1U<<(((UINT16)(obj_id))&0x07U)))

#ifndef GFX_MGR02_INLINE_INIT
  #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)
   #define GFX_MGR02_INLINE_INIT  (0)
  #else
   #define GFX_MGR02_INLINE_INIT  (1)
  #endif
#else
   #if (GFX_MGR02_INLINE_INIT == 1)
      #if defined(GFX_OVG_FAULT_HANDLE) && defined(GFX_MGR02_OPEN_VG)
        #error "Fault handling cannot be achieve if INLINE_INIT is enabled."
      #endif
   #endif
#endif

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
  #define GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)  (hmi_gfx_mgr02_get_image_layer_ptr(fl_prop_index_u32)->width)
  #define GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32) (hmi_gfx_mgr02_get_image_layer_ptr(fl_prop_index_u32)->height)
 #else
  #define GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)  (lc_image_layer_def_S[lc_img_anim_property_S[(fl_prop_index_u32)].base_id].width)
  #define GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32) (lc_image_layer_def_S[lc_img_anim_property_S[(fl_prop_index_u32)].base_id].height)
 #endif /* GFX_MGR02_DLAYOUT_ENABLED */
 #define GFX_MGR02_GET_ORIG_SIMAGE_PIVOT_X(fl_prop_index_u32)	(lc_img_anim_property_S[(fl_prop_index_u32)].pivot.x)
 #define GFX_MGR02_GET_ORIG_SIMAGE_PIVOT_Y(fl_prop_index_u32)	(lc_img_anim_property_S[(fl_prop_index_u32)].pivot.y)

#endif /* GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
  #define GFX_MGR02_GET_ANIM_ELEM_CLIP_WDGT_HEIGHT(fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height)
  #define GFX_MGR02_GET_ANIM_ELEM_CLIP_WIDGET_WIDTH(fl_prop_index_u32) (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width)
  #define GFX_MGR02_GET_ORIG_SWIDGET_PIVOT_X(fl_prop_index_u32)        (lc_widget_anim_property_S[(fl_prop_index_u32)].pivot.x)
  #define GFX_MGR02_GET_ORIG_SWIDGET_PIVOT_Y(fl_prop_index_u32)        (lc_widget_anim_property_S[(fl_prop_index_u32)].pivot.y)

#endif /* GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
  #define GFX_MGR02_GET_ANIM_ELEM_FILL_HEIGHT(fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_GET_ANIM_ELEM_FILL_WIDTH(fl_prop_index_u32)   (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_GET_ORIG_FILL_ANIM_PIVOT_X(fl_prop_index_u32) (lc_fill_anim_property_S[(fl_prop_index_u32)].pivot.x)
  #define GFX_MGR02_GET_ORIG_FILL_ANIM_PIVOT_Y(fl_prop_index_u32) (lc_fill_anim_property_S[(fl_prop_index_u32)].pivot.y)

#endif /* GFX_MGR02_NUM_FILL_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
  #define GFX_MGR02_GET_ANIM_ELEM_SVG_HEIGHT(fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_GET_ANIM_ELEM_SVG_WIDTH(fl_prop_index_u32)   (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_GET_ORIG_SVG_ANIM_PIVOT_X(fl_prop_index_u32) (lc_svg_anim_property_S[(fl_prop_index_u32)].pivot.x)
  #define GFX_MGR02_GET_ORIG_SVG_ANIM_PIVOT_Y(fl_prop_index_u32) (lc_svg_anim_property_S[(fl_prop_index_u32)].pivot.y)
#endif /* GFX_MGR02_NUM_SVG_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
  #define GFX_MGR02_GET_ANIM_ELEM_TILE_HEIGHT(fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_GET_ANIM_ELEM_TILE_WIDTH(fl_prop_index_u32)   (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_GET_ORIG_TILE_ANIM_PIVOT_X(fl_prop_index_u32) (lc_tile_anim_property_S[(fl_prop_index_u32)].pivot.x)
  #define GFX_MGR02_GET_ORIG_TILE_ANIM_PIVOT_Y(fl_prop_index_u32) (lc_tile_anim_property_S[(fl_prop_index_u32)].pivot.y)
#endif /* GFX_MGR02_NUM_TILE_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
  #define   GFX_MGR02_GET_ANIM_ELEM_TEXT_WIDTH(fl_prop_index_u32)   (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].width)
  #define   GFX_MGR02_GET_ORIG_TEXT_ANIM_PIVOT_X(fl_prop_index_u32) (lc_text_anim_property_S[(fl_prop_index_u32)].pivot.x)
  #define   GFX_MGR02_GET_ORIG_TEXT_ANIM_PIVOT_Y(fl_prop_index_u32) (lc_text_anim_property_S[(fl_prop_index_u32)].pivot.y)
#endif /* GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS */

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
 #if defined(GFX_MGR02_DLAYOUT_ENABLED) 
  #define   GFX_MGR02_GET_ORIG_ELEM_TEXT_WIDTH(fl_prop_index_u32)  (hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32)->width)
 #else
  #define   GFX_MGR02_GET_ORIG_ELEM_TEXT_WIDTH(fl_prop_index_u32)  (lc_text_layer_def_S[lc_text_anim_property_S[(fl_prop_index_u32)].base_id].width)
 #endif	 /* GFX_MGR02_DLAYOUT_ENABLED */
#endif /* GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS */



#if GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1

  #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    /***** Macros for altering X of static image **********/
    #define GFX_MGR02_GET_SIMAGE_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
    #define GFX_MGR02_SET_SIMAGE_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32))))
    /***** Macros for altering Y of static image **********/
    #define GFX_MGR02_GET_SIMAGE_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_SIMAGE_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
        /***** Macros for getting original x,y of static image **********/
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.x)
      #else
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_img_anim_property_S[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)                   (lc_img_anim_property_S[(fl_prop_index_u32)].coord.x)
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    /***** Macros for altering Y of static widgets **********/
    #define GFX_MGR02_GET_SWIDGET_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_SWIDGET_Y_COORD(fl_offset_pos_y,l_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))
    /***** Macros for altering X of static widgets**********/
    #define GFX_MGR02_GET_SWIDGET_X_COORD(fl_prop_index_u32)        (GFX_MGR02_LAYERS_MAX_HEIGHT - (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y + GFX_MGR02_GET_ANIM_ELEM_CLIP_WDGT_HEIGHT(fl_prop_index_u32)))
    #define GFX_MGR02_SET_SWIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_CLIP_WDGT_HEIGHT(fl_prop_index_u32))))
 
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
          /***** Macros for getting original x,y of static widget **********/
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
          #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.y) + hmi_gfx_mgr02_get_wdg_elem_area_offset_ptr(fl_prop_index_u32)->ey))
          #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #else
          #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_widget_anim_property_S[(fl_prop_index_u32)].coord.y) + lc_elem_area_offset_SA[lc_swidget_layer_def_S[(fl_prop_index_u32)].clip_index].ey))
          #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (lc_widget_anim_property_S[(fl_prop_index_u32)].coord.x)
        #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */

      #if defined GFX_MGR02_CLIPPED_WIDGETS 
        /***** Macros for altering Y of clipped widgets **********/
        #define GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x)
        #define GFX_MGR02_SET_CLIP_WIDGET_Y_COORD(fl_offset_pos_y,l_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x) = (fl_offset_pos_y))
        /***** Macros for altering X of clipped widgets **********/
        #define GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32)        (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y) + GFX_MGR02_GET_ANIM_ELEM_CLIP_WDGT_HEIGHT(fl_prop_index_u32)))
        #define GFX_MGR02_SET_CLIP_WIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_CLIP_WDGT_HEIGHT(fl_prop_index_u32))))
        /***** Macros for altering Width of clipped widgets **********/
        #define GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height)
        #define GFX_MGR02_SET_CLIP_WIDGET_WIDTH(fl_clip_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height) = (fl_clip_width))
        /***** Macros for altering Height of clipped widgets **********/
        #define GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width)
        #define GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(fl_clip_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width) = (fl_clip_height))
      #endif /* GFX_MGR02_CLIPPED_WIDGETS */
  #endif /* GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    /***** Macros for altering X of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_X_COORD(fl_prop_index_u32)                    (GFX_MGR02_LAYERS_MAX_HEIGHT - (l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y +  GFX_MGR02_LAYERS_MAX_HEIGHT))
    #define GFX_MGR02_SET_GROUP_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_LAYERS_MAX_HEIGHT)))
    /***** Macros for altering Y of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_Y_COORD(fl_prop_index_u32)                    (l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x)
    #define GFX_MGR02_SET_GROUP_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x) = (fl_offset_pos_y))
  #endif /* GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
  /***** Macros for altering X of user anim elements **********/
  #define GFX_MGR02_GET_USER_ANIM_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - (l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
  #define GFX_MGR02_SET_USER_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32))))
  /***** Macros for altering Y of user anim elements **********/
  #define GFX_MGR02_GET_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_USER_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of user anim elements **********/
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
     #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
     #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.x)
    #else
      #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
      #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.x)
    #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_USER_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
  /***** Macros for altering Y of fill anim **********/
  #define GFX_MGR02_GET_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_FILL_ANIM_Y_COORD(fl_offset_pos_y,l_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))
  /***** Macros for altering X of fill anim**********/
  #define GFX_MGR02_GET_FILL_ANIM_X_COORD(fl_prop_index_u32)        (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_FILL_HEIGHT(fl_prop_index_u32)))
  #define GFX_MGR02_SET_FILL_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_FILL_HEIGHT(fl_prop_index_u32))))
  /***** Macros for altering Width of fill anim **********/
  #define GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_SET_FILL_ANIM_WIDTH(fl_dim_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height) = (fl_dim_width))
  /***** Macros for altering Height of fill anim **********/
  #define GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_SET_FILL_ANIM_HEIGHT(fl_dim_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width) = (fl_dim_height))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of fill anim elements **********/
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
     #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)     (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.y) + hmi_gfx_mgr02_get_fill_layer_def_ptr(fl_prop_index_u32)->dim.height))
     #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    	(hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.x)
    #else
     #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)     (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_fill_anim_property_S[(fl_prop_index_u32)].coord.y) + lc_fill_layer_def_S[(fl_prop_index_u32)].dim.height))
      #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (lc_fill_anim_property_S[(fl_prop_index_u32)].coord.x)
    #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_FILL_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
  /***** Macros for altering X of svg elements **********/
  #define GFX_MGR02_GET_SVG_ANIM_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32)))
  #define GFX_MGR02_SET_SVG_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_IMG_HEIGHT(fl_prop_index_u32))))
  /***** Macros for altering Y of svg elements **********/
  #define GFX_MGR02_GET_SVG_ANIM_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_SVG_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))

    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of static widget **********/
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      #define GFX_MGR02_GET_ORIG_SVG_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.y) + hmi_gfx_mgr02_get_svg_elem_area_offset_ptr(fl_prop_index_u32)->ey))
      #define GFX_MGR02_GET_ORIG_SVG_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.x)
    #else
      #define GFX_MGR02_GET_ORIG_SVG_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_svg_anim_property_S[(fl_prop_index_u32)].coord.y) + lc_elem_area_offset_SA[lc_svg_layer_def_S[(fl_prop_index_u32)].clip_index].ey))
      #define GFX_MGR02_GET_ORIG_SVG_Y_COORD(fl_prop_index_u32)    (lc_svg_anim_property_S[(fl_prop_index_u32)].coord.x)
    #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_SVG_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
  /***** Macros for altering Y of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_TILE_ANIM_Y_COORD(fl_offset_pos_y,l_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))
  /***** Macros for altering X of tile anim**********/
  #define GFX_MGR02_GET_TILE_ANIM_X_COORD(fl_prop_index_u32)        (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y) + GFX_MGR02_GET_ANIM_ELEM_TILE_HEIGHT(fl_prop_index_u32)))
  #define GFX_MGR02_SET_TILE_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x)+GFX_MGR02_GET_ANIM_ELEM_TILE_HEIGHT(fl_prop_index_u32))))
  /***** Macros for altering Width of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_SET_TILE_ANIM_WIDTH(fl_dim_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height) = (fl_dim_width))
  /***** Macros for altering Height of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_SET_TILE_ANIM_HEIGHT(fl_dim_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width) = (fl_dim_height))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of tile anim elements **********/
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
          #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.y) + hmi_gfx_mgr02_get_tile_layer_def_ptr(fl_prop_index_u32)->dim.height))
          #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.x)
      #else
          #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_tile_anim_property_S[(fl_prop_index_u32)].coord.y) + lc_tile_layer_def_S[(fl_prop_index_u32)].dim.height))
          #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (lc_tile_anim_property_S[(fl_prop_index_u32)].coord.x)
      #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_TILE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
  /***** Macros for altering X of text **********/
  #define GFX_MGR02_GET_TEXT_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y)))
  #define GFX_MGR02_SET_TEXT_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y) = (GFX_MGR02_LAYERS_MAX_HEIGHT-((fl_offset_pos_x))))
  /***** Macros for altering Y of text **********/
  #define GFX_MGR02_GET_TEXT_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_TEXT_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_y))

    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of text **********/
   #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.y)))
      #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.x)
   #else
      #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_HEIGHT - ((lc_text_anim_property_S[(fl_prop_index_u32)].coord.y)))
      #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (lc_text_anim_property_S[(fl_prop_index_u32)].coord.x)
   #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
   #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 ((hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32))->alignment)
   #else
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 (lc_text_layer_def_S[lc_text_anim_property_S[(fl_prop_index_u32)].base_id].alignment)
   #endif  
  #endif  /* GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS */

#elif GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1

  #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    /***** Macros for altering X of static image **********/
    #define GFX_MGR02_GET_SIMAGE_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_SIMAGE_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    /***** Macros for altering Y of static image **********/
    #define GFX_MGR02_GET_SIMAGE_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)))
    #define GFX_MGR02_SET_SIMAGE_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32))))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
     #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.y)
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - (((hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.x)) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)))
     #else
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)                   (lc_img_anim_property_S[(fl_prop_index_u32)].coord.y)
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_img_anim_property_S[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)))
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
  /***** Macros for altering Y of static widgets **********/
  #define GFX_MGR02_GET_SWIDGET_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_CLIP_WIDGET_WIDTH(fl_prop_index_u32)))
  #define GFX_MGR02_SET_SWIDGET_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_CLIP_WIDGET_WIDTH(fl_prop_index_u32))))
  /***** Macros for altering X of static widgets **********/
  #define GFX_MGR02_GET_SWIDGET_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y)
  #define GFX_MGR02_SET_SWIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of static widget **********/
     #if defined(GFX_MGR02_DLAYOUT_ENABLED)
       #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.x) + hmi_gfx_mgr02_get_wdg_elem_area_offset_ptr(fl_prop_index_u32)->ex))
     #else
       #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (lc_widget_anim_property_S[(fl_prop_index_u32)].coord.y)
       #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_widget_anim_property_S[(fl_prop_index_u32)].coord.x) + lc_elem_area_offset_SA[lc_swidget_layer_def_S[(fl_prop_index_u32)].clip_index].ex))
     #endif /* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */

    #if defined GFX_MGR02_CLIPPED_WIDGETS 
      /***** Macros for altering Y of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x + GFX_MGR02_GET_ANIM_ELEM_CLIP_WIDGET_WIDTH(fl_prop_index_u32)))
      #define GFX_MGR02_SET_CLIP_WIDGET_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_CLIP_WIDGET_WIDTH(fl_prop_index_u32))))
      /***** Macros for altering X of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y)
      #define GFX_MGR02_SET_CLIP_WIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y) = (fl_offset_pos_x))
      /***** Macros for altering Width of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height)
      #define GFX_MGR02_SET_CLIP_WIDGET_WIDTH(fl_clip_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height) = (fl_clip_width))
      /***** Macros for altering Height of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width)
      #define GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(fl_clip_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width) = (fl_clip_height))
    #endif /* GFX_MGR02_CLIPPED_WIDGETS */
  #endif /* GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    /***** Macros for altering X of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_X_COORD(fl_prop_index_u32)                    (l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y)
    #define GFX_MGR02_SET_GROUP_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y) = (fl_offset_pos_x))
    /***** Macros for altering Y of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_Y_COORD(fl_prop_index_u32)                    (GFX_MGR02_LAYERS_MAX_WIDTH  - ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x) + GFX_MGR02_LAYERS_MAX_WIDTH))
    #define GFX_MGR02_SET_GROUP_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_LAYERS_MAX_WIDTH)))
  #endif /* GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    /***** Macros for altering X of user anim elements **********/
    #define GFX_MGR02_GET_USER_ANIM_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_USER_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    /***** Macros for altering Y of user anim elements **********/
    #define GFX_MGR02_GET_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)))
    #define GFX_MGR02_SET_USER_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32))))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
       #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - (hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.x) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32))
    #else
      #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)                   (lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.y)
      #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_IMG_WIDTH(fl_prop_index_u32)))
     #endif	/* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_USER_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    /***** Macros for altering Y of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_FILL_WIDTH(fl_prop_index_u32)))
    #define GFX_MGR02_SET_FILL_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_FILL_WIDTH(fl_prop_index_u32))))
    /***** Macros for altering X of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_FILL_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    /***** Macros for altering Width of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height)
    #define GFX_MGR02_SET_FILL_ANIM_WIDTH(fl_dim_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height) = ((UINT16)fl_dim_width))
    /***** Macros for altering Height of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width)
    #define GFX_MGR02_SET_FILL_ANIM_HEIGHT(fl_dim_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width) = ((UINT16)fl_dim_height))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
        /***** Macros for getting original x,y of fill anim elements **********/
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.y)
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.x) + (hmi_gfx_mgr02_get_fill_layer_def_ptr(fl_prop_index_u32)->dim.width)))
      #else
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)    (lc_fill_anim_property_S[(fl_prop_index_u32)].coord.y)
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_fill_anim_property_S[(fl_prop_index_u32)].coord.x) + (lc_fill_layer_def_S[(fl_prop_index_u32)].dim.width)))
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_FILL_ANIM_ELEMENTS */  

  #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
  /***** Macros for altering Y of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_TILE_WIDTH(fl_prop_index_u32)))
  #define GFX_MGR02_SET_TILE_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_TILE_WIDTH(fl_prop_index_u32))))
  /***** Macros for altering X of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y)
  #define GFX_MGR02_SET_TILE_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
  /***** Macros for altering Width of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height)
  #define GFX_MGR02_SET_TILE_ANIM_WIDTH(fl_dim_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height) = (fl_dim_width))
  /***** Macros for altering Height of tile anim **********/
  #define GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width)
  #define GFX_MGR02_SET_TILE_ANIM_HEIGHT(fl_dim_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width) = (fl_dim_height))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
      /***** Macros for getting original x,y of fill anim elements **********/
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.y)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.x) + (hmi_gfx_mgr02_get_tile_layer_def_ptr(fl_prop_index_u32)->dim.width)))
      #else
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (lc_tile_anim_property_S[(fl_prop_index_u32)].coord.y)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_tile_anim_property_S[(fl_prop_index_u32)].coord.x) + (lc_tile_layer_def_S[(fl_prop_index_u32)].dim.width)))
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_TILE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    /***** Macros for altering X of svg element **********/
    #define GFX_MGR02_GET_SVG_ANIM_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_SVG_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    /***** Macros for altering Y of svg element **********/
    #define GFX_MGR02_GET_SVG_ANIM_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x) + GFX_MGR02_GET_ANIM_ELEM_SVG_WIDTH(fl_prop_index_u32)))
    #define GFX_MGR02_SET_SVG_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x) = (GFX_MGR02_LAYERS_MAX_WIDTH-((fl_offset_pos_y)+GFX_MGR02_GET_ANIM_ELEM_SVG_WIDTH(fl_prop_index_u32))))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.y)
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.x) + hmi_gfx_mgr02_get_svg_elem_area_offset_ptr(fl_prop_index_u32)->ex))
      #else
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_X_COORD(fl_prop_index_u32)    (lc_svg_anim_property_S[(fl_prop_index_u32)].coord.y)
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_Y_COORD(fl_prop_index_u32)    (GFX_MGR02_LAYERS_MAX_WIDTH - ((lc_svg_anim_property_S[(fl_prop_index_u32)].coord.x) + lc_elem_area_offset_SA[lc_svg_layer_def_S[(fl_prop_index_u32)].clip_index].ex))
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    /***** Macros for altering X of text **********/
    #define GFX_MGR02_GET_TEXT_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_TEXT_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_x))
    /***** Macros for altering Y of text**********/
    #define GFX_MGR02_GET_TEXT_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x))
    #define GFX_MGR02_SET_TEXT_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x = (GFX_MGR02_LAYERS_MAX_WIDTH-(fl_offset_pos_y)))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.y)	
        #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.x))
       #else
        #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (lc_text_anim_property_S[(fl_prop_index_u32)].coord.y)
        #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (GFX_MGR02_LAYERS_MAX_WIDTH - (lc_text_anim_property_S[(fl_prop_index_u32)].coord.x))
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */ 
   #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 ((hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32))->alignment)   
   #else
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 (lc_text_layer_def_S[lc_text_anim_property_S[(fl_prop_index_u32)].base_id].alignment)             
   #endif  
  #endif /* GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS */

#else /* If rotation support not enabled */

  #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    /***** Macros for altering X of static image **********/
    #define GFX_MGR02_GET_SIMAGE_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_SIMAGE_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_x))
    /***** Macros for altering Y of static image **********/
    #define GFX_MGR02_GET_SIMAGE_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_SIMAGE_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.image_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_y))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)		(hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)		(hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32)		(lc_img_anim_property_S[(fl_prop_index_u32)].coord.x)
        #define GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32)		(lc_img_anim_property_S[(fl_prop_index_u32)].coord.y)
       #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
  /***** Macros for altering Y of static widgets **********/
  #define GFX_MGR02_GET_SWIDGET_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y)
  #define GFX_MGR02_SET_SWIDGET_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_y))
  /***** Macros for altering X of static widgets **********/
  #define GFX_MGR02_GET_SWIDGET_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x)
  #define GFX_MGR02_SET_SWIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_x))
    #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
          #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.y)
          #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->coord.x)
       #else
          #define GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32)    (lc_widget_anim_property_S[(fl_prop_index_u32)].coord.y)
          #define GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32)    (lc_widget_anim_property_S[(fl_prop_index_u32)].coord.x)
       #endif /* GFX_MGR02_DLAYOUT_ENABLED */
    #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */

    #if defined GFX_MGR02_CLIPPED_WIDGETS
      /***** Macros for altering Y of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y)
      #define GFX_MGR02_SET_CLIP_WIDGET_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.y) = (fl_offset_pos_y))
      /***** Macros for altering X of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x)
      #define GFX_MGR02_SET_CLIP_WIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.x) = (fl_offset_pos_x))
      /***** Macros for altering Width of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width)
      #define GFX_MGR02_SET_CLIP_WIDGET_WIDTH(fl_clip_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.width) = (fl_clip_width))
      /***** Macros for altering Height of clipped widgets **********/
      #define GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height)
      #define GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(fl_clip_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.widget_prop[(fl_prop_index_u32)].clip.height) = (fl_clip_height))
    #endif /* GFX_MGR02_CLIPPED_WIDGETS */
  #endif /* GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    /***** Macros for altering X of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_X_COORD(fl_prop_index_u32)                    (l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x)
    #define GFX_MGR02_SET_GROUP_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].x) = (fl_offset_pos_x))
    /***** Macros for altering Y of group anim elements(DIMAGE/DWIDGET) **********/
    #define GFX_MGR02_GET_GROUP_ANIM_Y_COORD(fl_prop_index_u32)                    (l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y)
    #define GFX_MGR02_SET_GROUP_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.group_loc[(fl_prop_index_u32)].y) = (fl_offset_pos_y))
  #endif /* GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    /***** Macros for altering X of user anim elements **********/
    #define GFX_MGR02_GET_USER_ANIM_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_USER_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_x))
    /***** Macros for altering Y of user anim elements **********/
    #define GFX_MGR02_GET_USER_ANIM_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_USER_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  ((l_gfx_mgr02_anim_data_S.user_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_y))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)				(hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)				(hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32)				(lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.x)
        #define GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32)				(lc_user_img_anim_property_S[(fl_prop_index_u32)].coord.y)
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_USER_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    /***** Macros for altering Y of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_Y_COORD(fl_prop_index_u32)    l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y
    #define GFX_MGR02_SET_FILL_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.y) = (fl_offset_pos_y))
    /***** Macros for altering X of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_FILL_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].coord.x) = (fl_offset_pos_x))
    /***** Macros for altering Width of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height)
    #define GFX_MGR02_SET_FILL_ANIM_HEIGHT(f1_dim_height,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.height) = ((UINT16)(f1_dim_height)))
    /***** Macros for altering Height of fill anim **********/
    #define GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width)
    #define GFX_MGR02_SET_FILL_ANIM_WIDTH(f1_dim_width,fl_prop_index_u32)    ((l_gfx_mgr02_anim_data_S.fill_prop[(fl_prop_index_u32)].dim.width) = ((UINT16)(f1_dim_width)))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32)    lc_fill_anim_property_S[(fl_prop_index_u32)].coord.x
        #define GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32)    lc_fill_anim_property_S[(fl_prop_index_u32)].coord.y
      #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_FILL_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
    /***** Macros for altering Y of tile anim **********/
    #define GFX_MGR02_GET_TILE_ANIM_Y_COORD(fl_prop_index_u32)    l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y
    #define GFX_MGR02_SET_TILE_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.y = (fl_offset_pos_y))
    /***** Macros for altering X of tile anim **********/
    #define GFX_MGR02_GET_TILE_ANIM_X_COORD(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_TILE_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].coord.x = (fl_offset_pos_x))
    /***** Macros for altering height of tile anim **********/
    #define GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height)
    #define GFX_MGR02_SET_TILE_ANIM_HEIGHT(fl_dim_height,fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.height = ((UINT16)fl_dim_height))
    /***** Macros for altering width of tile anim **********/
    #define GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width)
    #define GFX_MGR02_SET_TILE_ANIM_WIDTH(fl_dim_width,fl_prop_index_u32)    (l_gfx_mgr02_anim_data_S.tile_prop[(fl_prop_index_u32)].dim.width = ((UINT16)fl_dim_width))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32)    (lc_tile_anim_property_S[(fl_prop_index_u32)].coord.x)
        #define GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32)    (lc_tile_anim_property_S[(fl_prop_index_u32)].coord.y)
       #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_TILE_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    /***** Macros for altering X of svg elements **********/
    #define GFX_MGR02_GET_SVG_ANIM_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_SVG_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.x = (fl_offset_pos_x))
    /***** Macros for altering Y of svg elements **********/
    #define GFX_MGR02_GET_SVG_ANIM_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_SVG_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.svg_prop[(fl_prop_index_u32)].coord.y = (fl_offset_pos_y))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_X_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_Y_COORD(fl_prop_index_u32)    (hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_X_COORD(fl_prop_index_u32)    lc_svg_anim_property_S[(fl_prop_index_u32)].coord.x
        #define GFX_MGR02_GET_ORIG_SVG_ANIM_Y_COORD(fl_prop_index_u32)    lc_svg_anim_property_S[(fl_prop_index_u32)].coord.y
       #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
  #endif /* GFX_MGR02_NUM_SVG_ANIM_ELEMENTS */

  #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    /***** Macros for altering X of text **********/
    #define GFX_MGR02_GET_TEXT_X_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x)
    #define GFX_MGR02_SET_TEXT_X_COORD(fl_offset_pos_x,fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.x = (fl_offset_pos_x))
    /***** Macros for altering Y of text **********/
    #define GFX_MGR02_GET_TEXT_Y_COORD(fl_prop_index_u32)                   (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y)
    #define GFX_MGR02_SET_TEXT_Y_COORD(fl_offset_pos_y,fl_prop_index_u32)  (l_gfx_mgr02_anim_data_S.text_prop[(fl_prop_index_u32)].coord.y = (fl_offset_pos_y))
      #if defined GFX_MGR02_SET_ANIM_OFFSET_POSITION
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.x)
        #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32)->coord.y)
       #else
        #define GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)                   (lc_text_anim_property_S[(fl_prop_index_u32)].coord.x)
        #define GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32)                   (lc_text_anim_property_S[(fl_prop_index_u32)].coord.y)
       #endif /* GFX_MGR02_DLAYOUT_ENABLED */
      #endif /* GFX_MGR02_SET_ANIM_OFFSET_POSITION */
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 ((hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32))->alignment)   
    #else
      #define GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32)                 (lc_text_layer_def_S[lc_text_anim_property_S[(fl_prop_index_u32)].base_id].alignment)             
    #endif  
      
  #endif /* GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS */
#endif /* #if GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED */

#if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_VGLITE) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#include "hmi_gfx_mgr02_svg_table.dat"
#endif

#include "hmi_gfx_mgr02_config.dat"

#ifdef GFX_MGR02_LAYOUT_API_VERIFICATION
static volatile BOOLEAN l_gfx_build_screen_started = FALSE;
static void hmi_gfx_mgr02_layout_verify_caller(void)
{ 
  if(l_gfx_build_screen_started == TRUE)
  {
    while(1)
    {
      
    }
  }
}
#define GFX_MGR02_VERIFY_LAYOUT_API_CALL hmi_gfx_mgr02_layout_verify_caller();
#else
#define GFX_MGR02_VERIFY_LAYOUT_API_CALL
#endif // GFX_MGR02_LAYOUT_API_VERIFICATION
/*=============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static void hmi_gfx_mgr02_layout_reset_anim_flags(void);
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_widget_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id);
#endif
#if ((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0))
static UINT32 hmi_gfx_mgr02_layout_reset_image_anim_prop(UINT32 p_obj_type, UINT32 p_obj_index, UINT32 p_platform_id);
#endif  /*((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0))*/
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_text_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id);
#endif
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_tile_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id);
#endif
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_fill_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id);
#endif
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_group_anim(UINT32 p_prop_index_U32);
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
static UINT32 hmi_gfx_mgr02_layout_reset_svg_anim(UINT32 p_prop_index_U32);
#endif

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
static void hmi_gfx_mgr02_layout_set_matrix_anim_flags(GFX_MGR02_ANIM_ELEM_ID p_elem_id);
#endif

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
static void hmi_gfx_mgr02_layout_process_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP, UINT8	p_touch_id);
static UINT32 hmi_gfx_mgr02_layout_pop_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP, UINT8 p_touch_id);
static u_gx_flocal hmi_gfx_mgr02_layout_check_touch_point(GFX_MGR02_TOUCH_QDATA       * p_touch_data_SP,
                                                          UINT8 const                 * p_touch_pt_path_U8P,
                                                          GFX_MGR02_ELEM_LIST_T const * p_elem_SP,
                                                          GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                          u_gx_flocal p_cur_priority,
                                                          UINT8	p_touch_id);
static u_gx_flocal hmi_gfx_mgr02_layout_is_touch_object_visible(GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                                u_gx_flocal p_cur_priority,
                                                                GFX_MGR02_VISIBLE_AREA * p_touch_area_SP);
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
static void hmi_gfx_mgr02_layout_reset_anim_sts(void);
#endif
/*=============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    static UINT8 l_fill_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_FILL_ANIM_ELEMENTS + 7U)/8U];
#endif  /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
    static UINT8 l_tile_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_TILE_ANIM_ELEMENTS + 7U)/8U];
#endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    static UINT8 l_text_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS + 7U)/8U];  
 #if defined(GFX_MGR02_KEPLER)
    /*
    ** For DCU if the alignment, clipmode changes it has to be rebuilt
    ** so the change flag is saved seperately.
    */
    static UINT8 l_text_anim_dcu_changed_flag_U8A[(GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS + 7)/8];
 #endif
 #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
 static UINT8 l_txt_scroll_status_flag_U8A[(GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS + 7U)/8U]; 
 #endif
#endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    static UINT8 l_text_shaping_required_flag_U8A[(GFX_MGR02_NUM_OF_TEXT_LAYERS + 7U) / 8U];
#endif
#endif
#endif /* #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 */

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    static UINT8 l_wdg_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS+7U)/8U];
  #if defined(GFX_MGR02_KEPLER)
    /*
    ** For DCU if the horizontal clip properties change, we need to rebuild the 
    ** widget.
    */
    static UINT8 l_wdg_anim_dcu_changed_flag_U8A[(GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS+7U)/8U];
  #endif
#endif /* #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    static UINT8 l_img_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS+7U)/8U];
#endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    static UINT8 l_group_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS+7U)/8U];
#endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    static UINT8 l_svg_anim_elem_changed_flag_U8A[(GFX_MGR02_NUM_SVG_ANIM_ELEMENTS+7U)/8U];
#endif

#if GFX_MGR02_NUM_USER_LAYERS > 0
  #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    static UINT8 l_user_image_elem_changed_flag_U8A[(GFX_MGR02_NUM_USER_ANIM_ELEMENTS+7U)/8U];
  #endif /* #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0 */
#endif /* #if GFX_MGR02_NUM_USER_LAYERS > 0 */

#if GFX_MGR02_NUM_OF_DTEXTS > 0
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
static UINT32 l_text_prerender_index[GFX_MGR02_NUM_OF_DTEXTS];
#endif
static UINT8  l_dtext_elem_changed_flag_U8A[(GFX_MGR02_NUM_OF_DTEXTS + 7U) / 8U];
static GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_internal(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string
                                                                       #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                                                       , UINT8 p_process_bidi
                                                                       #endif
                                                                       );
#endif /* #if GFX_MGR02_NUM_OF_DTEXTS > 0 */

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
static UINT8  l_dwidget_elem_changed_flag_U8A[(GFX_MGR02_NUM_DYNAMIC_WIDGETS+7)/8];
#endif /* #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0 */

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
static UINT8  l_dimage_elem_changed_flag_U8A[(GFX_MGR02_NUM_DYNAMIC_IMAGES+7)/8];
#endif /* #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0 */

#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
static UINT8 l_font_elem_changed_flag_U8A[(GFX_MGR02_NUM_OF_FONTS+7)/8];
#endif

static UINT8  l_screen_changed_flag_U8A[(GFX_MGR02_NUM_PRIORITY+7)/8];

#if defined(__CWCC__)
  #pragma push
  #pragma section RW "GFX02_LAYOUT_RW_DATA" "GFX02_LAYOUT_RW_DATA"
  #define GFX02_LAYOUT_RW_DATA_PREFIX __declspec(section "GFX02_LAYOUT_RW_DATA")
#elif defined(__RENESAS__)
  #pragma section GFX02_LAYOUT_RW_DATA
#elif defined(__ghs__)
  #pragma ghs section bss="GFX02_LAYOUT_RW_DATA"
#elif defined(__GNUC__)
  #define GFX02_LAYOUT_RW_DATA_PREFIX __attribute__((section("GFX02_LAYOUT_RW_DATA")))  
#endif
#ifndef GFX02_LAYOUT_RW_DATA_PREFIX
  #define GFX02_LAYOUT_RW_DATA_PREFIX
#endif
  /*
  ** Allow the application to place the large RAM consumers to be kept in 
  ** a user defined memory segment to allow relocation to high capacity RAM
  */
  #if defined(__IAR_SYSTEMS_ICC__)
     #pragma location=".GFX02_LAYOUT_RW_DATA"
   #endif
 static GFX02_LAYOUT_RW_DATA_PREFIX GFX_MGR02_ANIM_DATA_T l_gfx_mgr02_anim_data_S;
 #if GFX_MGR02_NUM_OF_DTEXTS > 0
   #if defined(__IAR_SYSTEMS_ICC__)
     #pragma location=".GFX02_LAYOUT_RW_DATA"
   #endif
 static GFX02_LAYOUT_RW_DATA_PREFIX HMI_CHAR l_dynamic_text_buffer[GFX_MGR02_DTEXTS_BUFFER_SIZE];
  #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
       GFX02_LAYOUT_RW_DATA_PREFIX GFX_MGR02_SHAPE_ML_DATA l_shape_ml_dtext_buffer[GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS];
    #endif
  #endif
#if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
       GFX02_LAYOUT_RW_DATA_PREFIX HMI_CHAR l_dynamic_text_buffer_presen[GFX_MGR02_DTEXTS_BUFFER_SIZE];
       extern UINT8  l_dtext_do_shape_flag_U8A[(GFX_MGR02_NUM_OF_DTEXTS + 7) / 8];
#endif
 #endif
 #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
   #if defined(__IAR_SYSTEMS_ICC__)
     #pragma location=".GFX02_LAYOUT_RW_DATA"
   #endif
  static GFX02_LAYOUT_RW_DATA_PREFIX HMI_CHAR l_input_string[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
  static GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_text_internal(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string,GFX_MGR02_ANIM_ELEM_ID p_anim_id
                                                                       #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                                                        , UINT8 p_process_bidi
                                                                           #endif
                                                                       );
 #endif

#if defined(__CWCC__)
  #pragma pop
#elif (defined(__RENESAS__))
  #pragma section
#elif defined(__ghs__)
   #pragma ghs section bss=default
#endif

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
static UINT16 l_dyn_widget_selection[GFX_MGR02_NUM_DYNAMIC_WIDGETS];
#endif
#if  GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
static UINT16 l_dyn_image_selection[GFX_MGR02_NUM_DYNAMIC_IMAGES];
#endif

#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
static UINT8 l_global_text_max_shrink;
#endif
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
typedef struct
{
    GFX_MGR02_TOUCH_QDATA l_touch_event_queue_S[GFX_MGR02_TOUCH_EVENT_Q_SIZE];
    GFX_MGR02_VISIBLE_AREA        l_last_touch_area_S;
    GFX_MGR02_ELEM_LIST_T const * l_last_touch_elem_SP;
    GFX_MGR02_SCR_ELEM_ID         l_tcur_screen;
    UINT32 l_tcount_U32;
    UINT32 l_twrite_index_U32;
    UINT32 l_tread_index_U32;
}GFX_MGR02_TOUCH_T;
static GFX_MGR02_TOUCH_T l_touch_data[GFX_MGR02_TOUCH_NO_OF_FINGERS];
GFX_MGR02_CREATE_CS(l_tcritical_section);
#endif

#if defined(GFX_MGR02_DLAYOUT_ENABLED)
static GFX_MGR02_LAYOUT_ID l_dlayout_selection_U8;
static BOOLEAN l_dlayout_changed_flag_bool;
#endif
/*
** EGL init is time consuming, so this flag is to schedule them during build screen
*/
static GFX_MGR02_CTX_INIT_STATUS l_cntx_init_status=GFX_MGR02_NOT_DONE;
#ifdef GFX_MGR02_CHECKSUM_ENABLED
static UINT8 l_cntx_checksum_status_U8=GFX_MGR02_CHECKSUM_MATCHED;
#endif 

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
static void hmi_gfx_mgr02_set_multiline_data_modified(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP, BOOLEAN p_modified);
#if defined(GFX_MGR02_RUN_ML_ALG_FROM_PRESN) 
static BOOLEAN hmi_gfx_mgr02_get_multiline_data_modified(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP);
#endif
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
static UINT8 l_tv2_mipi_csi2_frame_capture_done = GFX_MGR02_VIDEO_CAPTURE_NOT_DONE;
#endif
/*=============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_initialize
** Visibility:       global
** Description:      Initializes all the dynamic data to default values
** Invocation:       Called by graphics manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          17-Sep-2012 by EMANOJ1
** Updated:          15-Dec-2012 by ASHEKHAR
**===========================================================================*/
#ifdef GFX_MGR02_CHECKSUM_ENABLED
UINT8 hmi_gfx_mgr02_layout_initialize(void)
#else
void hmi_gfx_mgr02_layout_initialize(void)
#endif
{
   UINT32 fl_loop_index_u32;
   UINT32 fl_num_screen_priority;
#ifdef GFX_MGR02_LAYOUT_API_VERIFICATION
  l_gfx_build_screen_started = FALSE;
#endif // GFX_MGR02_LAYOUT_API_VERIFICATION
#ifdef GFX_MGR02_CHECKSUM_ENABLED   
   if(gfx_mgr02_dat_checksum == GFX_MGR02_CFG_CHECKSUM)   
   {
      l_cntx_checksum_status_U8=GFX_MGR02_CHECKSUM_MATCHED;	   	
#endif   
   gfxloginit();

#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
   /*
   ** Group animations are valid for Screens, dynamic widgets and dynamic images
   ** generally they will have x, y and alpha animations. But for screen alone additionally
   ** there will be a background color component. Screens are always kept first in
   ** the list so (i < GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS) can be done to init
   ** the background color.
   */
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      (void)hmi_gfx_mgr02_layout_reset_group_anim(fl_loop_index_u32);
   }
#endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
   /*
   ** Layer will support x/y animations to allow movement of the entire layer
   ** This can be used for screen offset adjustments or animations.
   */
#if GFX_MGR02_NUM_LAYERS>1    
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS; fl_loop_index_u32++)
#else
    fl_loop_index_u32 = (UINT32)0;
#endif
   {
      l_gfx_mgr02_anim_data_S.layer_alpha[fl_loop_index_u32] = (GFX_MGR02_ALPHA)255;
      l_gfx_mgr02_anim_data_S.layer_loc[fl_loop_index_u32].x = 0;
      l_gfx_mgr02_anim_data_S.layer_loc[fl_loop_index_u32].y = 0;
    #if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP) 
      l_gfx_mgr02_anim_data_S.layer_color[fl_loop_index_u32] = 0xFFU; 
    #else
      l_gfx_mgr02_anim_data_S.layer_color[fl_loop_index_u32] = 0xFF000000U; 
    #endif
   }

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
    fl_loop_index_u32 = (UINT32)0;
#endif
   {
      (void)hmi_gfx_mgr02_layout_reset_image_anim_prop(GFX_MGR02_TYPE_SIMAGE, fl_loop_index_u32, (UINT32)GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
   fl_loop_index_u32 = (UINT32)0;
#endif    
   {
      (void)hmi_gfx_mgr02_layout_reset_image_anim_prop(GFX_MGR02_TYPE_USER_LAYER, fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
   fl_loop_index_u32 = (UINT32)0;
#endif    
   {
      (void)hmi_gfx_mgr02_layout_reset_fill_anim_prop(fl_loop_index_u32, (UINT32)GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
   fl_loop_index_u32 = (UINT32)0;
#endif    
   {
      hmi_gfx_mgr02_layout_reset_tile_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 1
    for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
    fl_loop_index_u32 = (UINT32)0;
#endif    
    {
       (void)hmi_gfx_mgr02_layout_reset_widget_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
    }
#endif

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
   fl_loop_index_u32 = (UINT32)0;
#endif    
   {
       (void)hmi_gfx_mgr02_layout_reset_text_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif
#if GFX_MGR02_NUM_OF_DTEXTS > 0
  #ifdef GFX_MGR02_CLR_DYN_TXT_BUFFER
   (void)memset(l_dynamic_text_buffer, 0, (sizeof(HMI_CHAR)) * (GFX_MGR02_DTEXTS_BUFFER_SIZE));
  #endif
   l_gfx_mgr02_anim_data_S.dtext_str = &l_dynamic_text_buffer[0];
  #if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
   (void)memset(l_dynamic_text_buffer_presen, 0, (sizeof(HMI_CHAR)) * (GFX_MGR02_DTEXTS_BUFFER_SIZE));
   (void)memset((void *)&l_dtext_do_shape_flag_U8A[0], 0, sizeof(l_dtext_do_shape_flag_U8A));
  #endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
   (void)memset((void*)&l_text_prerender_index[0], 0XFF, sizeof(l_text_prerender_index));
#endif
#endif
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
   (void)memcpy(l_dyn_widget_selection, lc_dyn_widget_selection, sizeof(l_dyn_widget_selection));
#endif
#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
   (void)memcpy(l_dyn_image_selection,  lc_dyn_image_selection,  sizeof(l_dyn_image_selection));
#endif
#if GFX_MGR02_NUM_LAYERS>1 
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS; fl_loop_index_u32++)
#else
    fl_loop_index_u32 = (UINT32)0;	
#endif	   
   {
      for(fl_num_screen_priority =(UINT32)0; fl_num_screen_priority < (UINT32)lc_layer_def_S[fl_loop_index_u32].nb_priority; fl_num_screen_priority++)
      {
         lc_layer_def_S[fl_loop_index_u32].prio_stack[fl_num_screen_priority] = (GFX_MGR02_SCREEN_ID_T)GFX_MGR02_NUM_OF_SCREENS;
      }
   }
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 1
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS; fl_loop_index_u32++)
#else
   fl_loop_index_u32 = (UINT32)0;
#endif    
   {
      (void)hmi_gfx_mgr02_layout_reset_svg_anim(fl_loop_index_u32);
   }
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
   l_dlayout_selection_U8=(GFX_MGR02_LAYOUT_ID)0;
#endif
   hmi_gfx_mgr02_layout_reset_anim_flags();
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
    hmi_gfx_mgr02_capture_video_init();
#endif
#if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
   hmi_gfx_mgr02_initialize();
#endif

#if (GFX_MGR02_INLINE_INIT == 0)
   l_cntx_init_status = GFX_MGR02_NOT_DONE;
#else
   if(hmi_gfx_mgr02_context_initialize() != FALSE)
   {
     l_cntx_init_status = GFX_MGR02_DONE;
   }
   else
   {
     l_cntx_init_status = GFX_MGR02_PARTIALLY_DONE;
   }
#endif

   hmi_gfx_mgr02_font_init();

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
   GFX_MGR02_INIT_CS(l_tcritical_section);
   GFX_MGR02_ENTER_CS(l_tcritical_section);
   for (fl_loop_index_u32 = 0U; fl_loop_index_u32 < (UINT32)GFX_MGR02_TOUCH_NO_OF_FINGERS; fl_loop_index_u32++)
   {
     l_touch_data[fl_loop_index_u32].l_tcount_U32 = 0;
     l_touch_data[fl_loop_index_u32].l_twrite_index_U32 = 0;
     l_touch_data[fl_loop_index_u32].l_tread_index_U32 = 0;
     l_touch_data[fl_loop_index_u32].l_last_touch_elem_SP = GFX_MGR02_NULL_PTR;
     l_touch_data[fl_loop_index_u32].l_last_touch_area_S.sx = 0;
     l_touch_data[fl_loop_index_u32].l_last_touch_area_S.sy = 0;
     l_touch_data[fl_loop_index_u32].l_last_touch_area_S.ex = 0;
     l_touch_data[fl_loop_index_u32].l_last_touch_area_S.ey = 0;
     l_touch_data[fl_loop_index_u32].l_tcur_screen = GFX_MGR02_NUM_OF_SCREENS;
   }
   GFX_MGR02_LEAVE_CS(l_tcritical_section);
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
   (void)memcpy(&l_gfx_mgr02_anim_data_S.user_image_layer, hmi_gfx_mgr02_get_user_img_layer_def_ptr(0), sizeof(l_gfx_mgr02_anim_data_S.user_image_layer));
#else
   (void)memcpy(&l_gfx_mgr02_anim_data_S.user_image_layer, &lc_user_image_layer_def_S[0], sizeof(l_gfx_mgr02_anim_data_S.user_image_layer));
#endif
#endif
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
   (void)memcpy(&l_gfx_mgr02_anim_data_S.mdl_3d_layer, &lc_3d_image_layer_def_S[0], sizeof(l_gfx_mgr02_anim_data_S.mdl_3d_layer));
#endif
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
   hmi_gfx_mgr02_dar_init();
#endif
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #if GFX_NUM_ANIMATIONS > 0
    hmi_gfx_anim_engine_init();
  #endif
#endif
#ifdef GFX_MGR02_IRIS_SIG_UNIT_ENABLED
    hmi_gfx_mgr02_safety_init();
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    (void)memset((void *)&l_input_string[0], 0, sizeof(l_input_string));
#endif
#if !defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_INLINE_INIT == 1)
  GFX_MGR02_UNUSED_VAR(l_cntx_init_status);
#endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
  l_global_text_max_shrink = 100U;
#endif
#ifdef GFX_MGR02_CHECKSUM_ENABLED
   }
   else
   {
       l_cntx_checksum_status_U8 = GFX_MGR02_CHECKSUM_FAILED;	   
   }
   return(l_cntx_checksum_status_U8);
#endif
}/* End of hmi_gfx_mgr02_layout_initialize() */

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_shutdown
** Visibility:       global
** Description:      Invokes shutdown process for graphics manager.
** Invocation:       Called by graphics manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**===========================================================================*/
void hmi_gfx_mgr02_layout_shutdown(void)
{
  #if defined(GFX_MGR02_OPEN_VG)
   if(l_cntx_init_status != GFX_MGR02_NOT_DONE)
  #endif
   {
     hmi_gfx_mgr02_context_shutdown();
     l_cntx_init_status = GFX_MGR02_NOT_DONE;
   }
}

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_emergency_shutdown
** Visibility:       global
** Description:      Invokes emergency shutdown process for graphics manager.
** Invocation:       Called by graphics manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**===========================================================================*/
void hmi_gfx_mgr02_layout_emergency_shutdown(void)
{
#if defined(GFX_MGR02_KEPLER)
   hmi_gfx_mgr02_emergency_shutdown();
#endif
}

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_startup
** Visibility:       global
** Description:      Invokes startup process for graphics manager.
** Invocation:       Called by graphics manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          19-Feb-2013 by ASHEKHAR
** Updated:          19-Feb-2013 by ASHEKHAR
**===========================================================================*/
void hmi_gfx_mgr02_layout_startup(void)
{
#if defined(GFX_MGR02_KEPLER)
   hmi_gfx_mgr02_driver_startup();
#endif
}
#if defined(GFX_OVG_FAULT_HANDLE) && defined(GFX_MGR02_OPEN_VG)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_ctx_init()
Description          : Initializes internal data for first tme use
                       When ever generic context needs to be initialized
Invocation           : Application,when error handling feature is enabled
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_layout_ctx_init(void)
{
  #if (GFX_MGR02_INLINE_INIT == 0)
   if(hmi_gfx_mgr02_context_initialize() != FALSE)
   {
     l_cntx_init_status = GFX_MGR02_DONE;
   }
   else
   {
     l_cntx_init_status = GFX_MGR02_PARTIALLY_DONE;
   }
  #endif 
}
#endif
/*=============================================================================
** Function Name:    gui_gfx_mgr_build_screen()
** Visibility:       global
** Description:      Selects the corresponding interface to be invoked based on
**                   the Target type for the passed screen element. Invokes
**                   the DCU or OpenVG/SW set_screen() API's based on the target
**                   type of the associated SCREEN element.
**                   Used to select the SCREEN to be shown or not to be shown
** Invocation:       By the presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          15-Aug-2012 by ASHEKHAR
**===========================================================================*/
void hmi_gfx_mgr02_layout_build_screen(void)
{
    UINT32 fl_layer_index;
#if (defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER))
    UINT32 fl_is_display_updated = (UINT32)FALSE;
#endif    
#ifdef GFX_MGR02_LAYOUT_API_VERIFICATION
l_gfx_build_screen_started = TRUE;
#endif // GFX_MGR02_LAYOUT_API_VERIFICATION
#ifdef GFX_MGR02_CHECKSUM_ENABLED
   if(l_cntx_checksum_status_U8 != GFX_MGR02_CHECKSUM_FAILED)
   {
#endif
    gfxlogstart(GFX_LOG_OVERALL);
    gfxlogstart(GFX_LOG_RENDERING);
    gfxlogstop(GFX_LOG_RENDERING);
    gfxlogstart(GFX_LOG_PROCESSING);
    gfxlogstart(GFX_LOG_SWAP_BUFFER);
    gfxlogstop(GFX_LOG_SWAP_BUFFER);

#if !defined(GFX_OVG_FAULT_HANDLE)
 #if (GFX_MGR02_INLINE_INIT == 0)
    if(l_cntx_init_status == GFX_MGR02_NOT_DONE)
    {
      if(hmi_gfx_mgr02_context_initialize() != FALSE)
      {
        l_cntx_init_status = GFX_MGR02_DONE;
      }
      else
      {
        l_cntx_init_status = GFX_MGR02_PARTIALLY_DONE;
      }
    }
 #endif
#endif

#if (GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
    hmi_gfx_mgr02_context_widget_prepare();
#endif
#if GFX_MGR02_NUM_LAYERS>1 
    for(fl_layer_index = (UINT32)0; fl_layer_index < (UINT32)GFX_MGR02_NUM_LAYERS; fl_layer_index++)
#else
    fl_layer_index = (UINT32)0;
#endif
    {
        switch(lc_layer_def_S[fl_layer_index].target)
        {
        #ifdef GFX_MGR02_KEPLER
           case GFX_MGR02_TARGET_DCU:
           case GFX_MGR02_TARGET_DCULITE:
           {
               hmi_gfx_mgr02_build_screen(fl_layer_index);
           }
           break;
        #endif
        #if defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER) 
           case GFX_MGR02_TARGET_AMBER_IRIS:
           {
               if(hmi_gfx_mgr02_generic_build_screen(fl_layer_index) != FALSE)
               {
                  fl_is_display_updated = (UINT32)TRUE;
               }
           }
           break;
        #endif
        #if defined(GFX_MGR02_AMBER_IRIS) && defined(GFX_MGR02_AMBER) 
           case GFX_MGR02_TARGET_AMBER_IRIS:
           {
               hmi_gfx_mgr02_generic_build_screen(fl_layer_index);
           }
           break;
        #endif
        #if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT) 
           case GFX_MGR02_TARGET_IMXRT_PXP:
           {
               (void)hmi_gfx_mgr02_generic_build_screen(fl_layer_index);
           }
           break;
        #endif    
        #if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)
           case GFX_MGR02_TARGET_SOFTWARE:
           case GFX_MGR02_TARGET_MONOTFT:
           case GFX_MGR02_TARGET_OPENVG:
           case GFX_MGR02_TARGET_OPENGL:
           case GFX_MGR02_TARGET_FUJITSU:
           {
          #if  defined(GFX_MGR02_DLAYOUT_ENABLED)
                (void)hmi_gfx_mgr02_generic_build_screen(fl_layer_index, (u_gx_flocal)l_dlayout_changed_flag_bool);
          #else
                (void)hmi_gfx_mgr02_generic_build_screen(fl_layer_index);
          #endif
           }
           break;
        #endif
        #if defined(GFX_MGR02_AMBER)
           case GFX_MGR02_TARGET_AMBER:
           {
              hmi_gfx_mgr02_build_screen(fl_layer_index);
           }
           break;
        #endif
        #if defined(GFX_MGR02_IMXRT)
           case GFX_MGR02_TARGET_IMXRT:
           {
              hmi_gfx_mgr02_imxrt_build_screen(fl_layer_index);
           }
           break;
        #endif
        #if defined(GFX_MGR02_TRAVEO2)
           case GFX_MGR02_TARGET_TRAVEO2:
           {
              hmi_gfx_mgr02_build_screen(fl_layer_index);
           }
           break;
        #endif
           default:
           {
               /*To Fix MISRA warning.*/
           }
           break;
        }
    }
#if (GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
    hmi_gfx_mgr02_context_widget_done();
#endif
    hmi_gfx_mgr02_layout_reset_anim_flags();
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
  #if !defined(NUNIT_TESTING) && !defined(GFX_MGR02_OPEN_GL)
    hmi_gfx02_dcu_sim_update();
  #endif
#endif
  #if defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER)
    if(fl_is_display_updated == TRUE)
    {
       HMI_GFX_MGR02_AMBER_IRIS_COMMIT_WINDOW();
    }
  #endif
#ifdef GFX_MGR02_LAYOUT_API_VERIFICATION
      l_gfx_build_screen_started = FALSE;
#endif // GFX_MGR02_LAYOUT_API_VERIFICATION
    gfxlogend(GFX_LOG_OVERALL);
    gfxlogend(GFX_LOG_PROCESSING);
    gfxlogupdate();
#ifdef GFX_MGR02_CHECKSUM_ENABLED
   }
#endif
}
/*=============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_is_element_changed
 ** Visibility:       global
 ** Description:      Returns TRUE if the passed element has changed its 
 **                   properties (e.g. XY location, text value etc). Otherwise
 **                   returns FALSE. This is primarily used to determine whether
 **                   or not an element needs to be rebuilt.
 ** Invocation:       Invoked by hmi_gfx_mgr02_generic
 ** Inputs/Outputs:   Base ID, Object ID 
 ** Critical Section: None.
 ** Created:          12-May-2013 by EMANOJ1
 ** Updated:          12-May-2013 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_is_element_changed(UINT32 p_base_id, UINT32 p_obj_id)
{
  UINT32 fl_obj_changed = (UINT32)FALSE;
  UINT32 fl_obj_index = GFX_MGR02_GET_OBJ_ID(p_obj_id);
  UINT32 fl_obj_dynamic = (UINT32)FALSE;
  if (GFX_MGR02_IS_DYNAMIC_PROP(p_obj_id))
  {
    fl_obj_dynamic = (UINT32)TRUE;
  }

  switch (GFX_MGR02_GET_OBJ_TYPE(p_obj_id))
  {
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    case GFX_MGR02_TYPE_SWIDGET:
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
      {
        if (fl_obj_dynamic != (UINT32)FALSE)
        {
          if (GFX_MGR02_IS_ELEM_CHANGED(l_wdg_anim_elem_changed_flag_U8A, fl_obj_index))
          {
            fl_obj_changed = (UINT32)TRUE;
          }
#if defined(GFX_MGR02_KEPLER)
          else if (GFX_MGR02_IS_ELEM_CHANGED(l_wdg_anim_dcu_changed_flag_U8A, fl_obj_index))
          {
            fl_obj_changed = (UINT32)TRUE;
          }
          else
          {
          }
#endif
        }
    }
  }
  break;
#endif
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
  case GFX_MGR02_TYPE_DWIDGET:
  {
    if ((p_base_id < (UINT32)GFX_MGR02_NUM_DYNAMIC_WIDGETS) && GFX_MGR02_IS_ELEM_CHANGED(l_dwidget_elem_changed_flag_U8A, p_base_id))
    {
      fl_obj_changed = (UINT32)TRUE;
    }
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    else if ((fl_obj_index < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS) && (fl_obj_dynamic != (UINT32)FALSE))
    {
      if (GFX_MGR02_IS_ELEM_CHANGED(l_group_anim_elem_changed_flag_U8A, fl_obj_index))
      {
        fl_obj_changed = (UINT32)TRUE;
      }
    }
    else
    {
      //MISRA.IF.NO_ELSE fix
    }
#endif
  }
  break;
#endif
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
  case GFX_MGR02_TYPE_SIMAGE:
  {
    if (fl_obj_index < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
    {
      if (fl_obj_dynamic != (UINT32)FALSE)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_img_anim_elem_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
  }
  break;
#endif
#if  GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
  case GFX_MGR02_TYPE_DIMAGE:
  {
    if ((p_base_id < (UINT32)GFX_MGR02_NUM_DYNAMIC_IMAGES) && (GFX_MGR02_IS_ELEM_CHANGED(l_dimage_elem_changed_flag_U8A, p_base_id)))
    {
      fl_obj_changed = (UINT32)TRUE;
    }
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    else if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if ((fl_obj_index < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS) && (GFX_MGR02_IS_ELEM_CHANGED(l_group_anim_elem_changed_flag_U8A, fl_obj_index)))
      {
        fl_obj_changed = (UINT32)TRUE;
      }
    }
    else
    {
      /*MISRA.IF.NO_ELSE fix*/
    }
#endif
  }
  break;
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
  case GFX_MGR02_TYPE_STEXT:
  case GFX_MGR02_TYPE_DTEXT:
  {
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
      {
        if ((GFX_MGR02_IS_ELEM_CHANGED(l_text_anim_elem_changed_flag_U8A, fl_obj_index))
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            || (hmi_gfx_mgr02_layout_get_text_scroll_status((GFX_MGR02_ANIM_ELEM_ID)p_obj_id) != FALSE)
#endif
        )
        {
          fl_obj_changed = (UINT32)TRUE;
        }
#if defined(GFX_MGR02_KEPLER)
        else if (GFX_MGR02_IS_ELEM_CHANGED(l_text_anim_dcu_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
        else
        {
        }
#endif
      }
    }
#endif
#if GFX_MGR02_NUM_OF_DTEXTS > 0
    if (GFX_MGR02_GET_OBJ_TYPE(p_obj_id) == GFX_MGR02_TYPE_DTEXT)
    {
      if (p_base_id < (UINT32)GFX_MGR02_NUM_OF_DTEXTS)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_dtext_elem_changed_flag_U8A, p_base_id))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
#endif
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
    if (fl_obj_changed == (UINT32)FALSE)
    {
      /*
      ** TODO : for text with animation we can also change the font_id. But here
      ** we are considering only the default font id. It needs to be addressed
      ** in some way such as remove the provision of font_id from dyanamic text
      ** animation properties or in some good way later.
      */
      if (p_base_id < (UINT32)GFX_MGR02_NUM_OF_TEXT_LAYERS)
      {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
        GFX_MGR02_TEXT_DEF_T const* fl_text_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_base_id);
#else
        GFX_MGR02_TEXT_DEF_T const* fl_text_def_SP = &lc_text_layer_def_S[p_base_id];
#endif
        if (GFX_MGR02_IS_ELEM_CHANGED(l_font_elem_changed_flag_U8A, fl_text_def_SP->font_id))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
#endif
  }
  break;
#endif
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
  case GFX_MGR02_TYPE_TILE:
  {
    if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_tile_anim_elem_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
  }
  break;
#endif
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
  case GFX_MGR02_TYPE_FILL:
  {
    if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_fill_anim_elem_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
  }
  break;
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0  
  case GFX_MGR02_TYPE_USER_LAYER:
  {
    #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_user_image_elem_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
    if (fl_obj_changed != TRUE)
    #endif
    {
      if (p_base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
      {
        UINT32 fl_pwidth;
        UINT32 fl_pheight;
        GFX_MGR02_IMAGE_DEF_T *fl_element_def_SP = &l_gfx_mgr02_anim_data_S.user_image_layer[p_base_id];
#if defined(GFX_MGR02_VGLITE)
        fl_pwidth = (UINT32)fl_element_def_SP->width - (UINT32)fl_element_def_SP->padding;
#else
        fl_pwidth = fl_element_def_SP->width;
#endif
        fl_pheight = fl_element_def_SP->height;
        if (hmi_gfx_mgr02_load_user_layer_def_info(p_base_id, fl_element_def_SP) != (UINT32)FALSE)
        {
          fl_obj_changed = (u_gx_flocal)TRUE;
        }
        else
        {
#if defined(GFX_MGR02_VGLITE)
          if (fl_pwidth != ((UINT32)fl_element_def_SP->width - (UINT32)fl_element_def_SP->padding))
#else
          if (fl_pwidth != fl_element_def_SP->width)
#endif
          {
            fl_obj_changed = (u_gx_flocal)TRUE;
          }
          else if (fl_pheight != fl_element_def_SP->height)
          {
            fl_obj_changed = (u_gx_flocal)TRUE;
          }
          else
          {
            /*For MISRA warning fix.*/
          }
        }
      }
    }
  }
  break;
#endif  
#if GFX_MGR02_NUM_VIDEO_LAYERS > 0
  case GFX_MGR02_TYPE_VIDEO_LAYER:
  {
    fl_obj_changed = (UINT32)TRUE;
  }
  break;
#endif

  case GFX_MGR02_TYPE_SCREEN:
  {
    if ((p_base_id < (UINT32)GFX_MGR02_NUM_PRIORITY) && (GFX_MGR02_IS_ELEM_CHANGED(l_screen_changed_flag_U8A, p_base_id)))
    {
      fl_obj_changed = (UINT32)TRUE;
    }
#if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
    else if (fl_obj_index < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS)
    {
      if (GFX_MGR02_IS_ELEM_CHANGED(l_group_anim_elem_changed_flag_U8A, fl_obj_index))
      {
        fl_obj_changed = (UINT32)TRUE;
      }
    }
    else
    {
      /*MISRA.IF.NO_ELSE fix added*/
    }
#endif
  }
  break;
  case GFX_MGR02_TYPE_LAYER:
  {
  }
  break;
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
  case GFX_MGR02_TYPE_SVG:
  {
    if (fl_obj_dynamic != (UINT32)FALSE)
    {
      if (fl_obj_index < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
      {
        if (GFX_MGR02_IS_ELEM_CHANGED(l_svg_anim_elem_changed_flag_U8A, fl_obj_index))
        {
          fl_obj_changed = (UINT32)TRUE;
        }
      }
    }
  }
  break;
#endif
  default:
  {
    /*For fixing MISRA warning.*/
  }
  break;
  }
  return(fl_obj_changed);
}

/*=============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_is_element_changed
 ** Visibility:       static
 ** Description:      Returns TRUE if the passed element or any of its children
 **                   has changed its properties (e.g. XY location, text value
 **                   etc). Otherwise returns FALSE. This is primarily used to
 **                   determine whether or not an element needs to be rebuilt
 **                   or not.
 ** Invocation:       Invoked by hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   Object Type, POinter to Element
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          28-May-2013 by EMANOJ1
 **==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
UINT32 hmi_gfx_mgr02_layout_is_element_childrens_changed(GFX_MGR02_ELEM_LIST_T const* p_elem_list_SP, BOOLEAN p_parent)
{
  UINT32 fl_return_sts = (UINT32)FALSE;
  UINT32 fl_obj_type;
  /*
  ** For DCU only widget and text are built in RAM and requires a rebuild.
  ** A rebuild is required only if its contents requires a change
  ** So for text we need to see if the text string or its alignment, font has changed
  ** For widgets we have to see if any of its children has changed.
  */
  if (p_elem_list_SP != GFX_MGR02_NULL_PTR)
  {
    if (p_parent == FALSE)
    {
      fl_return_sts = hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
    }
    else
    {
      fl_return_sts = (UINT32)FALSE;
    }
    if (fl_return_sts == (UINT32)FALSE)
    {
      fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
      if ((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT))
      {
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_KEPLER)
        UINT32 fl_txt_obj_index = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        UINT32 fl_obj_dynamic = GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id);
        if (fl_obj_dynamic != (UINT32)FALSE)
        {
          if (GFX_MGR02_IS_ELEM_CHANGED(l_text_anim_dcu_changed_flag_U8A, fl_txt_obj_index))
          {
            /* if alignment, clip mode or draw mode changes we have to rebuild text */
            fl_return_sts = (UINT32)TRUE;
          }
        }
#endif
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_KEPLER)
        if (fl_return_sts == (UINT32)FALSE)
#endif
        {
          if (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
          {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
            GFX_MGR02_TEXT_DEF_T const* fl_text_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_list_SP->base_id);
#else
            GFX_MGR02_TEXT_DEF_T const* fl_text_def_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
#endif
            if (GFX_MGR02_IS_ELEM_CHANGED(l_font_elem_changed_flag_U8A, fl_text_def_SP->font_id))
            {
              /* if font is changed, we need to rebuild text */
              fl_return_sts = (UINT32)TRUE;
            }
          }
        }
#endif
#if GFX_MGR02_NUM_OF_DTEXTS > 0
        if (fl_obj_type == GFX_MGR02_TYPE_DTEXT)
        {
          if (p_elem_list_SP->base_id < (UINT32)GFX_MGR02_NUM_OF_DTEXTS)
          {
            if (GFX_MGR02_IS_ELEM_CHANGED(l_dtext_elem_changed_flag_U8A, p_elem_list_SP->base_id))
            {
              /* if the text content is changed, we have to rebuild */
              fl_return_sts = (UINT32)TRUE;
            }
          }
        }
#endif
      }
      else
#endif
#if GFX_MGR02_NUM_OF_SWDGS > 0
        if (fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
        {
#if (defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) && (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)

          UINT32 fl_obj_index = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
#if defined(GFX_MGR02_KEPLER)
          if (GFX_MGR02_IS_ELEM_CHANGED(l_wdg_anim_dcu_changed_flag_U8A, fl_obj_index))
          {
            /*
            ** widget need to rebuild if horizontal clip (x or width) changes
            ** or if the widget's transformation matrix changes
            */
            fl_return_sts = (UINT32)TRUE;
          }
#endif
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
          if (GFX_MGR02_IS_ELEM_CHANGED(l_wdg_anim_elem_changed_flag_U8A, fl_obj_index))
          {
            /*Widget need to be rebuild if warp buffer is set.*/
            fl_return_sts = (UINT32)TRUE;
          }
#endif
          else
#endif
          {
            UINT32 fl_wdg_elem_counter;
            GFX_MGR02_ELEM_LIST_T const* fl_elem_list_SP;
            fl_elem_list_SP = p_elem_list_SP->child;
            fl_wdg_elem_counter = p_elem_list_SP->num_child_elements;
            while ((fl_wdg_elem_counter > (UINT32)0) && (fl_return_sts == FALSE))
            {
              /*
              ** widget needs to rebuild if any of its children's has changed any of
              ** their properties.
              */
              fl_return_sts = hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_list_SP, FALSE);
              fl_elem_list_SP++;
              fl_wdg_elem_counter--;
            }
          }
        }
        else
#endif
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
          if (fl_obj_type == GFX_MGR02_TYPE_DWIDGET)
          {
            /*
            ** This will be executed if a DCU layer static widget contains a
            ** dynamic widget. In this case rebuild is needed if any of the
            ** properties of the selected widget or its children are changed
            */
            GFX_MGR02_ELEM_LIST_T const* fl_elem_list_SP;
            fl_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_swidget(p_elem_list_SP);
            if (fl_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
              fl_return_sts = hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_list_SP, FALSE);
            }
          }
          else
#endif
#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
            if (fl_obj_type == GFX_MGR02_TYPE_DIMAGE)
            {
              /*
              ** This will be executed if a DCU layer static widget contains a
              ** dynamic image. In this case rebuild is needed if any of the
              ** properties of the selected image is changed
              */
              GFX_MGR02_ELEM_LIST_T const* fl_elem_list_SP;
              fl_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_list_SP);
              if (fl_elem_list_SP != GFX_MGR02_NULL_PTR)
              {
                fl_return_sts = hmi_gfx_mgr02_layout_is_element_changed((UINT32)fl_elem_list_SP->base_id, fl_elem_list_SP->obj_id);
              }
            }
            else
#endif
            {
          	 /*warning fix*/
            }
    }
  }
  return(fl_return_sts);
}

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_dwidget_selection
** Visibility:       static
** Description:      Returns the current dynamic widget selection index.
** Invocation:
** Inputs/Outputs:
** Critical Section: None.
** Created:          15-Oct-2013 by EMANOJ1
** Updated:          15-Oct-2013 by EMANOJ1
**===========================================================================*/
UINT32 hmi_gfx_mgr02_layout_get_dwidget_selection(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32 fl_cur_index;
    if((p_elem_list_SP->child != GFX_MGR02_NULL_PTR) && 
       (p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_DYNAMIC_WIDGETS))
    {
       fl_cur_index = l_dyn_widget_selection[p_elem_list_SP->base_id];
    }
    else
    {
       fl_cur_index = p_elem_list_SP->num_child_elements;
    }
    return(fl_cur_index);
}

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_selected_swidget
** Visibility:       static
** Description:      Determines the selected widget element. If the selected
**                   widget is again a dynamic widget, this function recursively
**                   calls until a valid static widget element is determined.
** Invocation:
** Inputs/Outputs:
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**===========================================================================*/
GFX_MGR02_ELEM_LIST_T const * hmi_gfx_mgr02_layout_get_selected_swidget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
  GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP = GFX_MGR02_NULL_PTR;
  if(p_elem_list_SP->child != GFX_MGR02_NULL_PTR)
  {
    UINT32 fl_cur_index;
    if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_DYNAMIC_WIDGETS)
    {
       fl_cur_index = l_dyn_widget_selection[p_elem_list_SP->base_id];
       if(fl_cur_index < p_elem_list_SP->num_child_elements)
       {
         fl_elem_list_SP = p_elem_list_SP->child;
         fl_elem_list_SP = &fl_elem_list_SP[fl_cur_index];
       }
    }
  }
  return(fl_elem_list_SP);
}
#endif

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_selected_simage
** Visibility:       static
** Description:      Determines the selected image element. If the selected
**                   image is again a dynamic image, this function recursively
**                   calls until a valid static image element is determined.
** Invocation:
** Inputs/Outputs:
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**===========================================================================*/
GFX_MGR02_ELEM_LIST_T const * hmi_gfx_mgr02_layout_get_selected_simage(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
  GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP = GFX_MGR02_NULL_PTR;
  if(p_elem_list_SP->child != GFX_MGR02_NULL_PTR)
  {
    UINT32 fl_cur_index;
    if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_DYNAMIC_IMAGES)
    {
      fl_cur_index = l_dyn_image_selection[p_elem_list_SP->base_id];
      if(fl_cur_index < p_elem_list_SP->num_child_elements)
      {
        fl_elem_list_SP = p_elem_list_SP->child;
        fl_elem_list_SP = &fl_elem_list_SP[fl_cur_index];
      }
    }
  }
  return(fl_elem_list_SP);
}
#endif
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_anim_data()
** Visibility:       global
** Description:      Provides animation element properties
** Invocation:       By the manager layer
** Inputs/Outputs:   Returns Pointer to the animation elements.
** Critical Section: None
** Created:          19-Nov-2012 by ASHEKHAR
** Updated:          19-Nov-2012 by ASHEKHAR
**===========================================================================*/
GFX_MGR02_ANIM_DATA_T * hmi_gfx_mgr02_layout_get_anim_data(void)
{
    return(&l_gfx_mgr02_anim_data_S);
}
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_force_set_screen()
** Visibility:       global
** Description:      Used when dirty and theme used together. When theme is changed
**                   existing screen will not be updated. Using this interface
**                   screen will be forced to change state.
** Invocation:       By the presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Screen ID to be activated/deactivated
**                   p_show = TRUE/FALSE Screen is shown/removed
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_force_set_screen(void)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;

    (void)memset((void *)&l_screen_changed_flag_U8A[0], 0xFF, sizeof(l_screen_changed_flag_U8A));

    return (fl_return_result); 
}
#endif
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_screen()
** Visibility:       global
** Description:      Selects the corresponding interface to be invoked based on
**                   the Target type for the passed screen element. Invokes
**                   the DCU or OpenVG/SW set_screen() API's based on the target
**                   type of the associated SCREEN element.
**                   Used to select the SCREEN to be shown or not to be shown
** Invocation:       By the presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Screen ID to be activated/deactivated
**                   p_show = TRUE/FALSE Screen is shown/removed
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          28-Jan-2013 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_screen(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show)
{
    GFX_MGR02_SCREEN_DEF_T   const * fl_screen_def_SP;
    GFX_MGR02_LAYER_DEF_T    const * fl_layer_table_SP;
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result  = GUI_GFX_MGR_NO_ERROR;

    /* 
    if GFX_MGR02_NUM_LAYERS is 1 then we won't get the layerid from the SCREEN DEF Table
    so in order to work correctly initialize fl_layer_id_u8 with "0" value and this will be
    updated with actual layerid if GFX_MGR02_NUM_LAYERS > 1 else it will be "0" indicating
    only one layer
    */
    UINT8                            fl_layer_id_u8;

    if((GFX_MGR02_SCREEN_ID_T)p_elem_id < ((GFX_MGR02_SCREEN_ID_T)GFX_MGR02_NUM_OF_SCREENS))
    {
        /* get the layerid based on the received screen id */
        fl_screen_def_SP  = &lc_screen_def_S[p_elem_id];
#if GFX_MGR02_NUM_LAYERS > 1
        fl_layer_id_u8    = fl_screen_def_SP->layerid;
#else
       fl_layer_id_u8 = (UINT8)0;
#endif
        /* from the layerid get the target type */
        fl_layer_table_SP = &lc_layer_def_S[fl_layer_id_u8];

        if(fl_screen_def_SP->priority < fl_layer_table_SP->nb_priority)
        {
            if(p_show != (UINT32)0)
            {
                if((GFX_MGR02_SCREEN_ID_T)p_elem_id != fl_layer_table_SP->prio_stack[fl_screen_def_SP->priority])
                {
                    fl_layer_table_SP->prio_stack[fl_screen_def_SP->priority] = (GFX_MGR02_SCREEN_ID_T)p_elem_id;
                    GFX_MGR02_SET_FLAG(l_screen_changed_flag_U8A, fl_screen_def_SP->priority);
                }
            }
            else
            {
                if((GFX_MGR02_SCREEN_ID_T)p_elem_id == fl_layer_table_SP->prio_stack[fl_screen_def_SP->priority])
                {
                    fl_layer_table_SP->prio_stack[fl_screen_def_SP->priority] = (GFX_MGR02_SCREEN_ID_T)GFX_MGR02_NUM_OF_SCREENS;
                    GFX_MGR02_SET_FLAG(l_screen_changed_flag_U8A, fl_screen_def_SP->priority);
                }
            }
        }
        else
        {
            fl_return_result = GUI_GFX_MGR_INVALID_PRIORITY;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_SCR_ELEM_ID;
    }
    return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_set_screen() */


/*=============================================================================
** Function Name:    GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_screen_dyn_priority()
** Visibility:       global
** Description:      Selects the corresponding interface to be invoked based on
**                   the Target type for the passed screen element. Invokes
**                   the DCU or OpenVG/SW set_screen() API's based on the target
**                   type of the associated SCREEN element.
**                   Used to select the SCREEN to be shown or not to be shown
** Invocation:       By the presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Screen ID to be activated/deactivated
**                   p_show = TRUE/FALSE Screen is shown/removed
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          28-Jan-2013 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_screen_dyn_priority(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show,UINT8 priority)
{
    GFX_MGR02_LAYER_DEF_T    const * fl_layer_table_SP;
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result  = GUI_GFX_MGR_NO_ERROR;

    /* 
    if GFX_MGR02_NUM_LAYERS is 1 then we won't get the layerid from the SCREEN DEF Table
    so in order to work correctly initialize fl_layer_id_u8 with "0" value and this will be
    updated with actual layerid if GFX_MGR02_NUM_LAYERS > 1 else it will be "0" indicating
    only one layer
    */
    UINT8                            fl_layer_id_u8;

    if((GFX_MGR02_SCREEN_ID_T)p_elem_id <(GFX_MGR02_SCREEN_ID_T) GFX_MGR02_NUM_OF_SCREENS)
    {

#if GFX_MGR02_NUM_LAYERS > 1
        /* get the layerid based on the received screen id */
        GFX_MGR02_SCREEN_DEF_T   const * fl_screen_def_SP = &lc_screen_def_S[p_elem_id];
        fl_layer_id_u8    = fl_screen_def_SP->layerid;
#else
        fl_layer_id_u8 = (UINT8)0;
#endif
        /* from the layerid get the target type */
        fl_layer_table_SP = &lc_layer_def_S[fl_layer_id_u8];

        if ((priority < fl_layer_table_SP->nb_priority) && (priority < (UINT8)GFX_MGR02_NUM_PRIORITY))
        {
            if(p_show != (UINT32)0)
            {
                if((GFX_MGR02_SCREEN_ID_T)p_elem_id != fl_layer_table_SP->prio_stack[priority])
                {
                    fl_layer_table_SP->prio_stack[priority] = (GFX_MGR02_SCREEN_ID_T)p_elem_id;
                    GFX_MGR02_SET_FLAG(l_screen_changed_flag_U8A, priority);
                }
            }
            else
            {
                if((GFX_MGR02_SCREEN_ID_T)p_elem_id == fl_layer_table_SP->prio_stack[priority])
                {
                    fl_layer_table_SP->prio_stack[priority] = (GFX_MGR02_SCREEN_ID_T)GFX_MGR02_NUM_OF_SCREENS;
                    GFX_MGR02_SET_FLAG(l_screen_changed_flag_U8A, priority);
                }
            }
        }
        else
        {
            fl_return_result = GUI_GFX_MGR_INVALID_PRIORITY;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_SCR_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

#if GFX_MGR02_NUM_OF_DTEXTS > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_text_width
** Visibility:       global
** Description:      For a passed input string, returns the actual width that 
**                   could be fitted in passed text id.
** Invocation:       By Presentation layer
** Inputs/Outputs:   in - p_elem_id of the text element
**                   in - pointer to a locally allocated GFX_MGR02_TEXT_WIDTH_INFO structure
**                   in - p_text_info->iostring : load the pointer to string which
**                                            should be checked for fit
**                   in - p_text_info->ifont_id : font id to be used, leave as
**                                            GFX_MGR02_NUM_OF_FONTS to use
**                                            default font configured for the text
**                   in - p_text_info->imax_available_width : max_available_width to be used,
**                                            pass it as 0xFFFFu to get full string width or
**                                            pass it as 0U to use default value to get the shrink percentage
**                   in - p_text_info->font_size : font_size to be used.
**                   out - p_text_info->iostring : modified string pointer
**                   out - p_text_info->owidth   : width of string that will fit
**                   out - p_text_info->ostr_length : length of string that will fit
**                   out - p_text_info->oclip_flag : 0 - no clipping, 1 - string is clipped
**                   out - p_text_info->oshrink   : shrinking applied on current string, 
**                   if clip mode is configured as "GFX_MGR02_TP_CLIP_SHRINK_FIT" & 
**                   imax_available_width is passed as 0U
** Critical Section: None
** Created:          24-May-2013 by EMANOJ1
** Updated:          08-Nov-2013 by EMANOJ1
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_width(GFX_MGR02_DTEXT_ID          p_elem_id, 
                                                             GFX_MGR02_TEXT_WIDTH_INFO * p_text_info)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result;
    if((p_elem_id < ((GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS)) && (p_text_info != GFX_MGR02_NULL_PTR))
    {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_id);
        #else
        GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = &lc_text_layer_def_S[p_elem_id];
        #endif
        UINT32                       fl_font_id;
        GFX_MGR02_TEXT_INFO          fl_text_info_S;
        UINT32 fl_alignment;
        
        #if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        UINT8 fl_scale_down;
        UINT8 fl_max_shrink = hmi_gfx_mgr02_layout_get_text_global_max_shrink();
        #endif

        fl_text_info_S.dyn_text_def_SP = fl_text_desc_SP;
        if(p_text_info->ifont_id < (UINT8)GFX_MGR02_NUM_OF_FONTS)
        {
           fl_font_id = p_text_info->ifont_id;
        }
        else
        {
           fl_font_id = fl_text_desc_SP->font_id;
        }
        
        fl_alignment = fl_text_desc_SP->alignment;
        #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
        if(((UINT32)fl_text_desc_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
        {
          UINT32 fl_anim_id        = fl_text_desc_SP->anim_id;
          UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_anim_id);
          UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(fl_anim_id);

          if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
          {
            fl_alignment = l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].alignment;

#if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
            if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
            {
              if (l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].max_shrink != 100U)
              {
                /* max available width is scaled up here to calculate actual string width for shrink calculaion */
                fl_max_shrink = l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].max_shrink;
              }
            }
#endif
          }
        }
#endif  /* #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) */

        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)|| (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
        fl_text_info_S.font_pt_size     = p_text_info->font_pt_size;
        #endif
        
        #if defined(GFX_MGR02_TRAVEO2)
        if (p_text_info->imax_available_width > 0U)
        {
            /* App needs to pass imax_available_width as 0xFFFFu to get thw width of the full string irrespective of textbox width */
            fl_text_info_S.max_available_width = p_text_info->imax_available_width;
        }
        else
        #endif
        {
          fl_text_info_S.max_available_width = fl_text_desc_SP->width;
          #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
          if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
          {
            fl_text_info_S.max_available_width = (fl_text_info_S.max_available_width * 100U)/ fl_max_shrink;
          }
          #endif
        }

        fl_text_info_S.print_str_P         = p_text_info->iostring;
        fl_text_info_S.target              = p_text_info->target;
        
        #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
        {
            fl_text_info_S.append_str = (UINT8)TRUE;
        }
        else
        {
            fl_text_info_S.append_str = (UINT8)FALSE;
        }
        #else
            fl_text_info_S.append_str = (UINT8)FALSE;
        #endif
        
        #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
        fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
        #endif
        #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
         fl_text_info_S.scroll = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_id)->scroll;
        #else
          fl_text_info_S.scroll = lc_text_layer_def_S[p_elem_id].scroll;
        #endif
        #endif
        fl_text_info_S.print_str_P         =  p_text_info->iostring;

        if((p_text_info->num_chars_to_process == (UINT16)GFX_MGR02_INVALID_TYPE) || (p_text_info->num_chars_to_process == (UINT16)0))
        {
          fl_text_info_S.num_chars_to_process = fl_text_desc_SP->num_chars;
        }
        else
        {
          fl_text_info_S.num_chars_to_process = p_text_info->num_chars_to_process;
        }
        #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined (GFX_MGR02_TRAVEO2))
        #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
        fl_text_info_S.is_complex = 0U;
        fl_text_info_S.str_offset_idx = 0U;
        #endif
        #endif
        
        p_text_info->oclip_flag = (UINT8)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                                   fl_font_id,  
                                                                   (UINT32)fl_text_desc_SP->clip_mode,
                                                                   (UINT32)GFX_MGR02_GALIGNMENT(fl_font_id, fl_alignment)
                                                                #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                   ,GFX_MGR02_NULL_PTR
                                                                #endif
                                                                #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                   ,GFX_MGR02_NULL_PTR
                                                                #endif
                                                                   );
        #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
        fl_scale_down = (UINT8)100;        
        if ((fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT) 
        #if defined(GFX_MGR02_TRAVEO2)    
            && (p_text_info->imax_available_width == 0U)
        #endif
        )
        {
          if (p_text_info->oclip_flag == (GFX_UINT)0)
          {
            if (fl_text_desc_SP->width < fl_text_info_S.print_width)
            {
              fl_scale_down = (UINT8)((fl_text_desc_SP->width * 100U)/fl_text_info_S.print_width);
              if ((fl_scale_down % 5U) != 0U)
              {
                fl_scale_down = (fl_scale_down/5U) * 5U;
              }
            }
          }
          else 
          {
            fl_scale_down = fl_max_shrink;
          }
        }
        p_text_info->oshrink     = 100U - (fl_scale_down);  /* shrinking % applied on current string.*/
        #endif
        
        p_text_info->iostring    = fl_text_info_S.print_str_P;
        p_text_info->owidth      = fl_text_info_S.print_width;
        p_text_info->ostr_length = fl_text_info_S.print_length_U8;
        
        fl_return_result         = GUI_GFX_MGR_NO_ERROR;
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID;
    }
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_text_width_ext
** Visibility:       global
** Description:      Interface to get text width with bidi logic and using the alignment
**                   input from user.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   in - p_elem_id of the text element
**                   in - pointer to a locally allocated GFX_MGR02_TEXT_WIDTH_INFO structure
**                   in - p_text_info->iostring : load the pointer to string which
**                                            should be checked for fit
**                   in - p_text_info->ifont_id : font id to be used, leave as
**                                            GFX_MGR02_NUM_OF_FONTS to use
**                                            default font configured for the text
**                   in - p_text_info->imax_available_width : max_available_width to be used,
**                                            pass it as 0xFFFFu to get full string width or
**                                            pass it as 0U to use default value to get the shrink percentage
**                   in - p_text_info->font_size : font_size to be used.
**                   out - p_text_info->iostring : modified string pointer
**                   out - p_text_info->owidth   : width of string that will fit
**                   out - p_text_info->ostr_length : length of string that will fit
**                   out - p_text_info->oclip_flag : 0 - no clipping, 1 - string is clipped
**                   out - p_text_info->oshrink   : shrinking applied on current string, 
**                   if clip mode is configured as "GFX_MGR02_TP_CLIP_SHRINK_FIT" &
**                   imax_available_width is passed as 0U
**					 in  - p_alignment: right or left aligned text
** Critical Section: None.
** Created:          12-May-2015 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_width_ext(GFX_MGR02_DTEXT_ID p_elem_id, 
                                                             GFX_MGR02_TEXT_WIDTH_INFO * p_text_info,
                                                             UINT32            p_alignment)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result;
    if((p_elem_id < ((GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS)) && (p_text_info != GFX_MGR02_NULL_PTR))
    {
        #ifndef GFX_MGR02_SHAPE_ENGINE_ENABLED
        HMI_CHAR fl_string_A[GFX_MGR02_MAX_TEXT_LENGTH+1];
        #endif
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
        #else
        GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = &lc_text_layer_def_S[p_elem_id];
        #endif
        UINT32                       fl_font_id;
        GFX_MGR02_TEXT_INFO          fl_text_info_S;
    
        #if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        UINT8 fl_scale_down;
        UINT8 fl_max_shrink = hmi_gfx_mgr02_layout_get_text_global_max_shrink();
        #endif
        
        if(p_text_info->ifont_id < (UINT8)GFX_MGR02_NUM_OF_FONTS)
        { 
            fl_font_id = p_text_info->ifont_id;
        }
        else
        {
            fl_font_id = fl_text_desc_SP->font_id;
        }
        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
        fl_text_info_S.font_pt_size     = p_text_info->font_pt_size;
        #endif
        
        #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
        if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
        {
          if(((UINT32)fl_text_desc_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
          {
            UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
            if(fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
            {
              if(l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].max_shrink != 100U)
              {
                /* max available width is scaled up here to calculate actual string width without clipping */
                fl_max_shrink =l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].max_shrink;
              }
            }
          }
        }
        #endif



        #if defined(GFX_MGR02_TRAVEO2)
        if (p_text_info->imax_available_width > 0U)
        {
            /* App needs to pass imax_available_width as 0xFFFFu to get thw width of the full string irrespective of textbox width */
            fl_text_info_S.max_available_width = p_text_info->imax_available_width;    
        }
        else
        #endif
        {
          fl_text_info_S.max_available_width = fl_text_desc_SP->width;
          #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
          if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
          {
            fl_text_info_S.max_available_width = (fl_text_info_S.max_available_width * 100U)/fl_max_shrink;
          }
          #endif
        }

        fl_text_info_S.target              = p_text_info->target;
        fl_text_info_S.append_str          = FALSE;
        fl_text_info_S.dyn_text_def_SP     = fl_text_desc_SP;
        #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_text_info_S.scroll = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_id)->scroll;
        #else
        fl_text_info_S.scroll = lc_text_layer_def_S[p_elem_id].scroll;
        #endif
        #endif
     
        if((p_text_info->num_chars_to_process == (UINT16)GFX_MGR02_INVALID_TYPE) || (p_text_info->num_chars_to_process == (UINT16)0))
        {
            fl_text_info_S.num_chars_to_process = fl_text_desc_SP->num_chars;
        }
        else
        {
            fl_text_info_S.num_chars_to_process = p_text_info->num_chars_to_process;
        }
        #ifndef GFX_MGR02_SHAPE_ENGINE_ENABLED
        (void)memset(&fl_string_A[0], 0, (sizeof(HMI_CHAR)) * ((UINT16)GFX_MGR02_MAX_TEXT_LENGTH+1U));
        hmi_gfx_mgr02_layout_default_text_shape(p_elem_id, p_text_info->iostring,
                                            &fl_string_A[0], (UINT8)FALSE, (UINT16)GFX_MGR02_MAX_TEXT_LENGTH
                                          #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                            ,(UINT8)TRUE
                                          #endif
                                           );
        fl_text_info_S.print_str_P         = &fl_string_A[0];
        #else
        fl_text_info_S.print_str_P         = p_text_info->iostring;
        #endif
        #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
        fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
        #endif
        #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined (GFX_MGR02_TRAVEO2))
        #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
        fl_text_info_S.is_complex = 0U;
        fl_text_info_S.str_offset_idx = 0U;
        #endif
        #endif
        if(p_alignment == GFX_MGR02_INVALID_TYPE)
        {
            UINT32 fl_alignment = fl_text_desc_SP->alignment;
            #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
            if(((UINT32)fl_text_desc_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
            {
                UINT32 fl_anim_id        = fl_text_desc_SP->anim_id;
                UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(fl_anim_id);
                UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(fl_anim_id);

                if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
                {
                    fl_alignment = l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].alignment;
                }
            }
            #endif  /* #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) */
            p_text_info->oclip_flag = (UINT8)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                                    fl_font_id,  
                                                                    (UINT32)fl_text_desc_SP->clip_mode,
                                                                    GFX_MGR02_GALIGNMENT(fl_font_id,fl_alignment)
                                                            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                    ,GFX_MGR02_NULL_PTR
                                                            #endif
                                                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                    ,GFX_MGR02_NULL_PTR
                                                            #endif
                                                                    );
        }
        else
        {
            p_text_info->oclip_flag = (UINT8)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                                    fl_font_id,  
                                                                    (UINT32)fl_text_desc_SP->clip_mode,
                                                                    p_alignment
                                                            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                    ,GFX_MGR02_NULL_PTR
                                                            #endif
                                                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                    ,GFX_MGR02_NULL_PTR
                                                            #endif
                                                                    );
        }
    
        #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
        fl_scale_down = (UINT8)100;        
        if ((fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
        #if defined(GFX_MGR02_TRAVEO2)    
            && (p_text_info->imax_available_width == 0U)
        #endif
        )
        {
          if (p_text_info->oclip_flag == (GFX_UINT)0)
          {
            if (fl_text_desc_SP->width < fl_text_info_S.print_width)
            {
              fl_scale_down = (UINT8)((fl_text_desc_SP->width * 100U)/fl_text_info_S.print_width);
              if ((fl_scale_down % 5U) != 0U)
              {
                fl_scale_down = (fl_scale_down/5U) * 5U;
              }
            }
          }
          else 
          {
            fl_scale_down = fl_max_shrink;
          }
        }
        p_text_info->oshrink     = 100U - (fl_scale_down);  /* shrinking % applied on current string.*/
        #endif

        p_text_info->owidth      = fl_text_info_S.print_width;
        p_text_info->ostr_length = fl_text_info_S.print_length_U8;
        fl_return_result = GUI_GFX_MGR_NO_ERROR;
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID;
    }
    return(fl_return_result);
}
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_txt_shaping_required()
** Description:      API to get whether text shaping is needed or not
**                   This will return the value based on text or any properties 
**                   which affect the shaping is changed or not.
** Invocation:       By Core before calling the get_text_width API
** Inputs/Outputs:   Returns whether reshaping required or now
**                   p_elem_id ==> Text elem ID to check shaping related parameters updated or not
**===========================================================================*/
UINT8 hmi_gfx_mgr02_layout_get_txt_shaping_required(UINT16 p_elem_id)
{
  return GFX_MGR02_IS_CHANGED(l_text_shaping_required_flag_U8A, p_elem_id);
}
#endif
#endif

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic text element.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_string  ==> Pointer to NULL terminated string
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          29-Jan-2013 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string)
{   
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  #if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
  if(p_elem_id < ((GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS))
  {
    l_text_prerender_index[p_elem_id] = UINT32_MAX;
  }
  #endif
  return hmi_gfx_mgr02_layout_set_text_internal(p_elem_id, p_string
    #ifdef HMI_LANG_PRE_RENDER_ENABLED
    , TRUE
    #endif
  );
}
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_internal()
** Visibility:       static
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic text element.
** Invocation:       By hmi_gfx_mgr02_layout_set_text
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_string  ==> Pointer to NULL terminated string
** Critical Section: None
** Created:          15-Aug-2012 by VMUTHUSU
** Updated:          29-Jan-2013 by ASHEKHAR
**===========================================================================*/
static GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_internal(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string
#if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                                                       , UINT8 p_process_bidi
#endif
                                                                       )
{
  GUI_GFX_MGR_ERROR_CODE_T  fl_return_result  = GUI_GFX_MGR_NO_ERROR;
  if((p_elem_id < ((GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS)) && (p_string != GFX_MGR02_NULL_PTR))
  {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
#else
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[p_elem_id];
#endif
    if (fl_text_layer_def_SP->string_index < (UINT32)GFX_MGR02_DTEXTS_BUFFER_SIZE)
    {
        HMI_CHAR                    * fl_dest_string = &l_dynamic_text_buffer[fl_text_layer_def_SP->string_index];
        u_gx_flocal fl_num_chars    = fl_text_layer_def_SP->num_chars;
    #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
        if(fl_text_layer_def_SP->max_num_of_lines > (UINT16)1)
        {
          fl_num_chars = fl_num_chars * fl_text_layer_def_SP->max_num_of_lines;
        }
    #endif
    #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) || defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
        BOOLEAN fl_UseShapeEngine = TRUE;
        /* Dynamic font id support currently implemented only for below combinations 
        Hence it require to fetch the font id from text anim properties */
    #if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
      (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
        if(((UINT32)fl_text_layer_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
        {
          UINT32 fl_font_id;
          GFX_MGR02_FONT const * fl_font_SP;
          UINT32 fl_anim_id        = fl_text_layer_def_SP->anim_id;
          UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(fl_anim_id);
          UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(fl_anim_id);

          if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
          {
            fl_font_id = l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].font_id;
          }
          else
          {
            fl_font_id = fl_text_layer_def_SP->font_id;
          }
          fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_font_id);
          fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id); 
          if((fl_font_SP != GFX_MGR02_NULL_PTR) && (fl_font_SP->is_ffile != (UINT8)0))
          {
            fl_UseShapeEngine = TRUE;
          }
          else
          {
            fl_UseShapeEngine = FALSE;
          }
        }
    #endif  /* #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) */
    #endif /*  #if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))*/
        if(fl_UseShapeEngine == TRUE)/*Using Shape engine*/
        {
          if(HMI_STRNCMP(fl_dest_string, p_string,(UINT32)fl_num_chars) != 0)
          {
            (void)HMI_STRNCPY(fl_dest_string, p_string, fl_num_chars);
             GFX_MGR02_SET_FLAG(l_dtext_elem_changed_flag_U8A, p_elem_id);
             //TODO: Shaping required flag should not be set to true when there is any change in the text element
             //During menu transition, for the same text element, text will be changed dynamically, 
             //Need to remove the below code and test the behaviour for monotype(Toyota)
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))
             GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, p_elem_id);
#endif
#endif
           #if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
             GFX_MGR02_SET_FLAG(l_dtext_do_shape_flag_U8A, p_elem_id);
           #endif
          }
        }
        else
    #endif /*GFX_MGR02_SHAPE_ENGINE_ENABLED*/
        {
    #if (!defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) && !defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF))
            hmi_gfx_mgr02_layout_default_text_shape(p_elem_id, p_string, fl_dest_string, (UINT8)TRUE, (UINT16)fl_num_chars
                                                #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                                   ,p_process_bidi
                                                #endif
                                                   );
	#endif
        }
    }
    else 
    {
        fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    }
  }
  else
  {
    fl_return_result = GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID;
  }
  return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_set_text() */
#ifndef GFX_MGR02_SHAPE_ENGINE_ENABLED
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_default_text_shape()
** Visibility:       Global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for shaping the text with default shape eninge
**                   and setting the text value for a ynamic text element.
** Invocation:       By internal API's
** Inputs/Outputs:   
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_string  ==> Pointer to NULL terminated string
**                   p_dest_string  ==> Pointer to output buffer
**                   p_compare  ==> Flag to decide whether compare processed string and  
**                                  load into output buffer
** Critical Section: None
** Created:          25-Nov-2020
** Updated:          
**===========================================================================*/
void hmi_gfx_mgr02_layout_default_text_shape(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string, HMI_CHAR * p_dest_string, 
                                             UINT8 p_compare, UINT16 p_num_chars
                                           #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                             , UINT8 p_process_bidi
                                           #endif
                                            )
{
#if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)	
#if !defined(GFX_MGR02_MONOTFT) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
  #if defined(GFX_MGR02_DLAYOUT_ENABLED)
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
  #else
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[p_elem_id];
  #endif
#endif
#endif
#if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) 
    BOOLEAN fl_BiDiRequired = (UINT8)FALSE;
#endif
#if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)
    BOOLEAN fl_gsubRequired = (UINT8)FALSE;
    char const   * fl_lang_tag = "";
#endif
#if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)|| defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED) 
    u_gx_flocal        fl_string_length;
#endif
    HMI_CHAR         * fl_string_ptr = GFX_MGR02_NULL_PTR;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
    /*
       Below condition added to avoid Coverity warning when GFX_MGR02_MAX_TEXT_LENGTH < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS.
       In the issue case, GFX_MGR02_MAX_TEXT_LENGTH = 254 and GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS = 211
       p_num_chars is passed as 254(GFX_MGR02_MAX_TEXT_LENGTH) when it's called from  hmi_gfx_mgr02_layout_get_text_width_ext().
       Here size of l_input_string is 211(GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS), l_input_string[p_num_chars] = 0; will lead to
       out of bound issue when p_num_chars is 254
    */
#if (GFX_MGR02_MAX_TEXT_LENGTH > GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
    HMI_CHAR                    fl_string_A[GFX_MGR02_MAX_TEXT_LENGTH + 1U];    
    if(p_num_chars > (UINT16)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
    {      
      (void)memset(fl_string_A, 0, (sizeof(HMI_CHAR)) * ((UINT16)GFX_MGR02_MAX_TEXT_LENGTH + 1U));
      (void)HMI_STRNCPY(&fl_string_A[0], p_string, (UINT32)p_num_chars);
      if (p_num_chars < (UINT16)(GFX_MGR02_MAX_TEXT_LENGTH + 1))
      {
        fl_string_A[p_num_chars] = (HMI_CHAR)0;
        fl_string_ptr = &fl_string_A[0];
      }
    }
    else
#endif
    {
      (void)HMI_STRNCPY(&l_input_string[0], p_string, (UINT32)p_num_chars);
      if (p_num_chars < (UINT16)(GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1))
      {
          l_input_string[p_num_chars] = (HMI_CHAR)0;
          fl_string_ptr = &l_input_string[0];
      }
    }
#else
    HMI_CHAR                    fl_string_A[GFX_MGR02_MAX_TEXT_LENGTH + 1];

    (void)memset(fl_string_A, 0, (sizeof(HMI_CHAR)) * ((UINT16)GFX_MGR02_MAX_TEXT_LENGTH + 1U));
    (void)HMI_STRNCPY(&fl_string_A[0], p_string, (UINT32)p_num_chars);
    if (p_num_chars < (UINT16)(GFX_MGR02_MAX_TEXT_LENGTH + 1))
    {
        fl_string_A[p_num_chars] = (HMI_CHAR)0;
        fl_string_ptr = &fl_string_A[0];
    }
#endif
    if (fl_string_ptr != GFX_MGR02_NULL_PTR)
    {
    #if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)|| defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED) 
          fl_string_length = (u_gx_flocal)HMI_STRLEN(&fl_string_ptr[0]);
    #endif
    #if defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
          if(hmi_gfx_mgr02_get_arabic_char_count(fl_string_ptr, (UINT16)fl_string_length) != 0U)
          {
    #if defined(HMI_LANG_PRE_RENDER_ENABLED)
            fl_BiDiRequired = p_process_bidi;
    #else
            fl_BiDiRequired = TRUE;
    #endif
    #if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)
            /*As of now, we are supporting Arabic gsub for GMC only. Hence the below condition added*/
    #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
            fl_lang_tag = "arab";
            fl_gsubRequired = (UINT8)TRUE;
    #endif
    #endif
          }
    #endif
    #if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
          if(hmi_gfx_mgr02_get_hebrew_char_count(fl_string_ptr,(UINT16)fl_string_length) != 0U)
          {
    #if defined(HMI_LANG_PRE_RENDER_ENABLED)
            fl_BiDiRequired = p_process_bidi;
    #else
            fl_BiDiRequired = TRUE;
    #endif
          }
    #endif
    #if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)
    #if defined GFX_MGR02_THAI_LANG_SUPPORT_NEEDED
          if(hmi_gfx_mgr02_get_thai_char_count(fl_string_ptr,(UINT16)fl_string_length) != 0U)
          {
            fl_lang_tag = "thai";
            fl_gsubRequired = (UINT8)TRUE;
          }
    #endif
    #if defined GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED
          if(hmi_gfx_mgr02_get_devanagari_char_count(fl_string_ptr,(UINT16)fl_string_length) != 0U)
          {
            fl_lang_tag = "dev2";
            fl_gsubRequired = (UINT8)TRUE;
          }
    #endif
    #endif
    #if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
          if(fl_BiDiRequired == (UINT8)TRUE)
          {
            (void)bidi_process(fl_string_ptr , (u_bidi_flocal)fl_string_length);
          }
    #endif
    #if defined(GFX_MGR02_FONT_GSUB_TABLE_ENABLED)
          if(fl_gsubRequired == (UINT8)TRUE)
          {
            HMI_GFX_DEVN_REORDER_INFO fl_dev_reorder_S;
         #if !defined(GFX_MGR02_MONOTFT)
            HMI_CHAR      *fl_out_str;
         #else
            /* For mono platform's heap section is defined hence getting linker error for malloc */
            #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
              HMI_CHAR       fl_out_str[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1];
            #else
              HMI_CHAR       fl_out_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
            #endif
         #endif
            UINT32        fl_num_chars_cpy;
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            UINT8 fl_font_id = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_id)->font_id;
    #else
            UINT8 fl_font_id = (UINT8)hmi_gfx_mgr02_get_font_id(lc_text_layer_def_S[p_elem_id].font_id);
    #endif
            fl_string_length   = (u_gx_flocal)HMI_STRLEN(&fl_string_ptr[0]);

    #if !defined(GFX_MGR02_MONOTFT)
       #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
            if(fl_text_layer_def_SP->max_num_of_lines > (UINT16)1)
            {
              fl_out_str   = (HMI_CHAR *)malloc((sizeof(HMI_CHAR)) * (GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1U));
              fl_num_chars_cpy = GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH;
            }
            else
            {
              fl_out_str   = (HMI_CHAR *)malloc((sizeof(HMI_CHAR)) * ((UINT16)GFX_MGR02_MAX_TEXT_LENGTH + 1U));
              fl_num_chars_cpy = GFX_MGR02_MAX_TEXT_LENGTH;
            }
       #else
            {
              fl_out_str   = (HMI_CHAR *)malloc((sizeof(HMI_CHAR)) * ((UINT16)GFX_MGR02_MAX_TEXT_LENGTH + 1U));
              fl_num_chars_cpy = GFX_MGR02_MAX_TEXT_LENGTH;
            }
       #endif
    #else
            #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
              fl_num_chars_cpy = GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH;
            #else
              fl_num_chars_cpy = GFX_MGR02_MAX_TEXT_LENGTH;
            #endif
    #endif
            if(fl_out_str != GFX_MGR02_NULL_PTR)
            {
                (void)memset(fl_out_str, 0, (sizeof(HMI_CHAR)) * (fl_num_chars_cpy + 1U));
                if(strncmp(fl_lang_tag, "arab", 4) == 0)
                {
                    hmi_gfx_mgr02_get_string_reverse(&fl_string_ptr[0], (UINT16)fl_string_length);
                }
                if(fl_font_id < (UINT8)GFX_MGR02_NUM_OF_FONTS)
                {
                  fl_dev_reorder_S.i_lookup     = lc_gfx_font_table[fl_font_id].gsub_lookup_list;
                  fl_dev_reorder_S.i_lookup_count = lc_gfx_font_table[fl_font_id].gsub_lookup_cnt;
                  fl_dev_reorder_S.i_script_lookup = lc_gfx_font_table[fl_font_id].gsub_script_lookup;
                  fl_dev_reorder_S.i_script_count = lc_gfx_font_table[fl_font_id].gsub_script_cnt;
                }
                fl_dev_reorder_S.i_src      = fl_string_ptr;
                fl_dev_reorder_S.o_dst      = fl_out_str;
                fl_dev_reorder_S.i_script = fl_lang_tag;

                #if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
                fl_dev_reorder_S.o_dst_len  = (UINT16)(fl_string_length);
                if ((strncmp(fl_lang_tag, "deva", 4) == 0) || (strncmp(fl_lang_tag, "dev2", 4) == 0))
                {
                    const SINT32 *utf8_offsets = NULL;
                    fl_string_length =(u_gx_flocal)hmi_indic_ot_reorder(fl_dev_reorder_S.i_src,
                      utf8_offsets,
                      (SINT32)fl_dev_reorder_S.o_dst_len,
                      &hmi_deva_class_table,
                      fl_dev_reorder_S.o_dst,
                      NULL,
                      NULL,
                      NULL);

                    fl_string_length = HMI_STRLEN(fl_dev_reorder_S.o_dst);
                    (void)HMI_STRNCPY(fl_string_ptr, fl_dev_reorder_S.o_dst, (UINT32)fl_string_length);
                    fl_string_ptr[fl_string_length] = 0;
                    (void)memset(fl_out_str, 0, (sizeof(HMI_CHAR)) * (fl_num_chars_cpy + 1U));
                }
                #endif

                fl_dev_reorder_S.o_dst_len = (UINT16)(fl_num_chars_cpy);
                hmi_gfx_mgr02_gsub_process(&fl_dev_reorder_S, fl_num_chars_cpy);
                #if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
                if ((strncmp(fl_lang_tag, "deva", 4) == 0) || (strncmp(fl_lang_tag, "dev2", 4) == 0))
                {
                  if(HMI_STRLEN(fl_dev_reorder_S.o_dst) == 0)
                  {
                      (void)HMI_STRNCPY(fl_dev_reorder_S.o_dst, fl_string_ptr, (UINT32)fl_string_length);
                      fl_dev_reorder_S.o_dst[fl_string_length] = 0;
                  }
                }
                #endif
                if (strncmp(fl_lang_tag, "arab", 4) == 0)
                {
                    fl_string_length = HMI_STRLEN(fl_dev_reorder_S.o_dst);
                    hmi_gfx_mgr02_get_string_reverse(fl_dev_reorder_S.o_dst, (UINT16)fl_string_length);
                }
                if (p_compare != (UINT8)FALSE)
                {
                    if (HMI_STRNCMP(p_dest_string, fl_dev_reorder_S.o_dst, (UINT32)p_num_chars) != 0)
                    {
                        (void)HMI_STRNCPY(p_dest_string, fl_dev_reorder_S.o_dst, p_num_chars);
                        GFX_MGR02_SET_FLAG(l_dtext_elem_changed_flag_U8A, p_elem_id);
                    }
                }
                else
                {
                    (void)HMI_STRNCPY(p_dest_string, fl_dev_reorder_S.o_dst, p_num_chars);
                }
    #if !defined(GFX_MGR02_MONOTFT)
              free(fl_out_str);
    #endif
            }
            else
            {
                if (p_compare != (UINT8)FALSE)
                {
                    if (HMI_STRNCMP(p_dest_string, p_string, (UINT32)p_num_chars) != 0)
                    {
                        (void)HMI_STRNCPY(p_dest_string, p_string, p_num_chars);
                        GFX_MGR02_SET_FLAG(l_dtext_elem_changed_flag_U8A, p_elem_id);
                    }
                }
                else
                {
                    (void)HMI_STRNCPY(p_dest_string, p_string, p_num_chars);
                }
            }
        }
        else
    #endif
        {
            if (p_compare != (UINT8)FALSE)
            {
                if (HMI_STRNCMP(p_dest_string, fl_string_ptr, ((UINT32)p_num_chars)) != 0)
                {
                    (void)HMI_STRNCPY(p_dest_string, fl_string_ptr, ((UINT32)p_num_chars));
                    GFX_MGR02_SET_FLAG(l_dtext_elem_changed_flag_U8A, p_elem_id);
                }
            }
            else
            {
                (void)HMI_STRNCPY(p_dest_string, fl_string_ptr, ((UINT32)p_num_chars));
            }
        }
    }
}
#endif
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_sid()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic text element.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_sid  ==> Pointer to NULL terminated string
** Critical Section: None
** Created:          10-May-2016 by ASHEKHAR
** Updated:          10-May-2016 by ASHEKHAR
**===========================================================================*/
#if HM_LANG_MAX_SID > 0
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
UINT32 hmi_gfx_mgr02_layout_get_sid_index(LANG_SID_T p_sid) 
{
  UINT32 fl_sid_index = HMI_PRE_RENDER_SIDS;
  UINT32 left = 0;
  UINT32 right = HMI_PRE_RENDER_SIDS - 1;
  while (left <= right) 
  {
    UINT32 mid = left + (right - left) / 2;
    if (lc_sid_map[mid].sid == p_sid) 
    {
      fl_sid_index = lc_sid_map[mid].index;
      break;
    }
    else if (lc_sid_map[mid].sid < p_sid) 
    {
      left = mid + 1;
    }
    else 
    {
      right = mid - 1;
    }
  }
  return fl_sid_index;
}
#endif
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result;
  HMI_CHAR const* fl_string_ptr;
#if defined(GFX_MGR02_TRAVEO2) && defined(HMI_LANG_PRE_RENDER)
  if (p_elem_id < GFX_MGR02_TOTAL_NUM_OF_DTEXTS)
  {
    UINT32 fl_text_prerender_index = UINT32_MAX;
    UINT8 fl_language_id = hmi_language_if_get_current_language();
    if (fl_language_id < HMI_NUM_LANGUAGES)
    {
      // Language index to access lc_pre_render_glyph_index array
      UINT8 fl_prerender_lang_index = lc_prerender_lang_index[fl_language_id];
      if (fl_prerender_lang_index != 0xFF)
      {
        UINT32 fl_sid_index = hmi_gfx_mgr02_layout_get_sid_index(p_sid);
        if (fl_sid_index < HMI_PRE_RENDER_SIDS)
        {
          fl_text_prerender_index = (UINT32)((fl_prerender_lang_index * HMI_PRE_RENDER_SIDS) + fl_sid_index);
        }
      }
    }
    l_text_prerender_index[p_elem_id] = fl_text_prerender_index;
  }
#endif

#if !defined(HM_LANG_USE_INERNAL_STRING_BUFFER)
    HMI_CHAR fl_text_A[GFX_MGR02_MAX_TEXT_LENGTH+1];
    /* 
    ** make the string as a empty to protect in case the language 
    ** i/f doesnot updates the buffer at all
    */
    fl_text_A[0] = 0; 
    hmi_language_if_get_string_ptr(p_sid, &fl_text_A[0], (UINT8)GFX_MGR02_MAX_TEXT_LENGTH);
    fl_string_ptr = &fl_text_A[0];
#else
    fl_string_ptr = hmi_language_if_get_string_ptr(p_sid);
    if(fl_string_ptr == GFX_MGR02_NULL_PTR)
    {
       fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    }
    else
#endif
    {
        #ifdef HMI_LANG_PRE_RENDER_ENABLED 
        fl_return_result = hmi_gfx_mgr02_layout_set_text_internal(p_elem_id, fl_string_ptr, (UINT8)FALSE);
        #else
        fl_return_result = hmi_gfx_mgr02_layout_set_text_internal(p_elem_id, fl_string_ptr);
        #endif
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
UINT32 hmi_gfx_mgr02_layout_get_prerender_index(UINT16 p_elem_id)
{
  UINT32 fl_prerender_index = UINT32_MAX;
  if (p_elem_id < (UINT16)GFX_MGR02_NUM_OF_DTEXTS)
  {
    fl_prerender_index = l_text_prerender_index[p_elem_id];
  }
  return fl_prerender_index;
}
#endif


#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_OPEN_GL)||defined (GFX_MGR02_TRAVEO2))
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_multi_line_text()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic multi line text element.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_string  ==> Pointer to NULL terminated string
** Critical Section: None
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string,GFX_MGR02_ANIM_ELEM_ID p_anim_id)
{
    #if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
    if(p_elem_id < ((GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS))
    {
      l_text_prerender_index[p_elem_id] = UINT32_MAX;
    }
    #endif
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return hmi_gfx_mgr02_layout_set_multi_line_text_internal(p_elem_id, p_string, p_anim_id
                                      #ifdef HMI_LANG_PRE_RENDER_ENABLED
                                      , TRUE
                                      #endif
                                      );
}


/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_multi_line_text_internal()
** Visibility:       static
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic multi line text element.
** Invocation:       By hmi_gfx_mgr02_layout_set_multi_line_text()
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_string  ==> Pointer to NULL terminated string
** Critical Section: None
**===========================================================================*/
static GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_text_internal(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string,GFX_MGR02_ANIM_ELEM_ID p_anim_id
                                                             #ifdef HMI_LANG_PRE_RENDER_ENABLED
                                                              , UINT8 p_process_bidi
                                                             #endif
                                                              )
{
    GUI_GFX_MGR_ERROR_CODE_T      fl_return_result     = GUI_GFX_MGR_NO_ERROR;

    if(p_elem_id <(GFX_MGR02_DTEXT_ID) GFX_MGR02_NUM_OF_DTEXTS)
    {   
     (void)hmi_gfx_mgr02_layout_set_text_internal(p_elem_id, p_string
                                                      #ifdef HMI_LANG_PRE_RENDER_ENABLED
                                                     , p_process_bidi
                                                     #endif
                                                     );
      if(GFX_MGR02_IS_CHANGED(l_dtext_elem_changed_flag_U8A, p_elem_id))
      {
        GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP;
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_text_layer_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
      #else
        fl_text_layer_def_SP = &lc_text_layer_def_S[p_elem_id];
      #endif

        if(fl_text_layer_def_SP->max_num_of_lines > (UINT16)1)
        {
          UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_anim_id);
          UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_anim_id);
          if(GFX_MGR02_IS_DYNAMIC_PROP(p_anim_id))
          {
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
            if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
              (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
            {
              hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_def_SP, TRUE);
            }
            else
            {
              
              fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
            }
#endif
          }
          else
          {
            hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_def_SP, TRUE);
          }
        }
       }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID;
    }
    return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_set_multi_line_text() */



#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_inter_line_spacing()
** Visibility:       global
** Description:      Sets the inter line spacing value for a Dynamic Text element
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id - The Text element ID to which a inter line spacing needs to be changed
**                   p_inter_line_spacing = spacing needs to updated
**                   Note:
**                   Valid value for interline spacing should be positive. Application team should test thoroughly
**                   with all languages if they want to use negative spacing to avoid overlapping issues.
**                   Negative spacing allowed specifically for MKTA.
** Critical Section: None
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_inter_line_spacing(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT8 p_inter_line_spacing)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;
  if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    if (((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
        (fl_prop_index < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
    {
#ifdef GFX_MGR02_DLAYOUT_ENABLED
      GFX_MGR02_TEXT_DEF_T const *fl_text_layer_prop_SP = hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index);
#else
      GFX_MGR02_TEXT_DEF_T const *fl_text_layer_prop_SP = GFX_MGR02_NULL_PTR;
      GFX_MGR02_TEXT_PROPERTY const *fl_text_canim_prop_SP = &lc_text_anim_property_S[fl_prop_index];
      if (fl_text_canim_prop_SP->base_id < GFX_MGR02_NUM_OF_TEXT_LAYERS)
      {
        fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
      }
#endif
      if (fl_text_layer_prop_SP != GFX_MGR02_NULL_PTR)
      {
        /* Only when the GDT designed text is a multi line text then inter line spacing can be changed */
        if (fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1)
        {
          if (l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index].inter_line_spacing != p_inter_line_spacing)
          {
            l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index].inter_line_spacing = p_inter_line_spacing;
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index);
          }
        }
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return (fl_return_result);
} /* End of hmi_gfx_mgr02_layout_set_inter_line_spacing() */

#endif
#if HM_LANG_MAX_SID > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_multi_line_sid()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic text element.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Text elem ID to which a new string to be copied
**                   p_sid  ==> Pointer to NULL terminated string
** Critical Section: None
** Created:          10-May-2016 by ASHEKHAR
** Updated:          10-May-2016 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid, GFX_MGR02_ANIM_ELEM_ID p_anim_id)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result;
    HMI_CHAR * fl_string_ptr;
#if !defined(HM_LANG_USE_INERNAL_STRING_BUFFER)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined (GFX_MGR02_TRAVEO2))
    /* 
    ** make the string as a empty to protect in case the language 
    ** i/f doesnot updates the buffer at all
    */
    l_input_string[0] = 0; 
    /*Maximum 255 characters are supported*/
    if (HM_LANG_MAX_STRING_SIZE < GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
    {
      hmi_language_if_get_string_ptr(p_sid, &l_input_string[0], (UINT8)HM_LANG_MAX_STRING_SIZE);
    }
    else
    {
      hmi_language_if_get_string_ptr(p_sid, &l_input_string[0], (UINT8)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH);
    }
    l_input_string[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH] = 0;
    fl_string_ptr = &l_input_string[0];
#else
    HMI_CHAR fl_text_A[GFX_MGR02_MAX_TEXT_LENGTH+1];
    /* 
    ** make the string as a empty to protect in case the language 
    ** i/f doesnot updates the buffer at all
    */
    fl_text_A[0] = 0; 
    hmi_language_if_get_string_ptr(p_sid, &fl_text_A[0], GFX_MGR02_MAX_TEXT_LENGTH);
    fl_string_ptr = &fl_text_A[0];
#endif
#else
    fl_string_ptr = hmi_language_if_get_string_ptr(p_sid);
    if(fl_string_ptr == GFX_MGR02_NULL_PTR)
    {
       fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    }
    else
#endif
    {
        #ifdef HMI_LANG_PRE_RENDER_ENABLED 
        fl_return_result = hmi_gfx_mgr02_layout_set_multi_line_text_internal(p_elem_id, fl_string_ptr, p_anim_id, (UINT8)FALSE);
        #else
        fl_return_result = hmi_gfx_mgr02_layout_set_multi_line_text_internal(p_elem_id, fl_string_ptr, p_anim_id);
        #endif
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
#endif
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_char_metrics
** Visibility:       global
** Description:      Returns the character metrics
** Invocation:       Invoked by application
** Inputs/Outputs:   p_char    - character for which metrics to be retrived
**                   p_font_id - font id to be used
**                   p_metrics - Pointer to GFX_MGR02_FONT_CHAR_METRICS where the
**                               metrics will be copied
**                   Returns GUI_GFX_MGR_NO_ERROR on success
** Critical Section: None.
** Created:          19-Mar-2014 by EMANOJ1
** Updated:          19-Mar-2014 by EMANOJ1
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_char_metrics(HMI_CHAR p_char,
                                                               UINT32   p_font_id,
                                                               GFX_MGR02_FONT_CHAR_METRICS * p_metrics)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_ret_sts = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    UINT32   fl_font_id = p_font_id;
    
    if((fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS) && (p_metrics != GFX_MGR02_NULL_PTR))
    {
        GFX_MGR02_FONT const * fl_font_SP;
        fl_font_id  = hmi_gfx_mgr02_get_font_id(fl_font_id);
        fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
       
        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
        #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
            if(fl_font_SP->is_ffile != (UINT8)FALSE)
            {
            #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
                GFX_MGR02_CONTEXT_T const * p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
                FT_Face      face = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
                if(face != 0)
                {
                    GFX_FLOAT fl_per;
                    FT_GlyphSlot slot = face->glyph;
                    #if defined (GFX_MGR02_USE_FREETYPE2_OS2_TABLE) && defined(GFX_MGR02_VGLITE)
                    TT_OS2 * os2 = (TT_OS2 *)FT_Get_Sfnt_Table(face, ft_sfnt_os2);
                    if (os2 != (TT_OS2 *)0)
                    {
                        fl_per = ((GFX_FLOAT)(-os2->usWinDescent))/(GFX_FLOAT)(os2->usWinAscent + os2->usWinDescent);
                    }
                    else
                    #endif
                    {
                        fl_per = ((GFX_FLOAT)face->descender)/(GFX_FLOAT)(face->ascender-face->descender);
                    }
                    SINT32 fl_top_y_offset = (SINT32)((GFX_FLOAT)fl_font_SP->p.height * fl_per);
                    FT_UInt glyph_index     = FT_Get_Char_Index(face, p_char);
                    (void)FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT|FT_LOAD_FORCE_AUTOHINT);
                    p_metrics->x_soffset = (SINT8)(slot->metrics.horiBearingX >> 6);
                    p_metrics->y_soffset = fl_top_y_offset;
                    p_metrics->y_soffset+= (SINT8)(fl_font_SP->p.height);
                    p_metrics->y_soffset-= (SINT8)(slot->metrics.horiBearingY >> 6);
                    p_metrics->width     = (UINT8)(slot->metrics.width >> 6);
                    p_metrics->height    = (UINT8)(slot->metrics.height >> 6);
                    p_metrics->owidth    = (UINT8)(slot->metrics.horiAdvance >> 6);
                    p_metrics->oheight   = fl_font_SP->p.height;
                    fl_ret_sts           = GUI_GFX_MGR_NO_ERROR;
                }
            #else
            /* TODO: implement for different font engines as required at a later stage */
            #endif
            }
            else
        #endif
        #if GFX_MGR02_OVG_FONT_PRESENT > 0
            if(fl_font_SP->is_vfont != 0)
            {
                /* TODO : implement this later */
            }
            else
        #endif
            {
                GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
                fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(p_char, fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table, 
                                                    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                                                     p_font_id,
                                                    #endif
                                                    (UINT32)FALSE);
                if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
                {
                    p_metrics->x_soffset = fl_font_fcc_SP->x_soffset;
                    p_metrics->y_soffset = fl_font_fcc_SP->y_soffset;
                    p_metrics->width     = fl_font_fcc_SP->width;
                    p_metrics->height    = fl_font_fcc_SP->height;
                    p_metrics->owidth    = fl_font_fcc_SP->owidth;
                    p_metrics->oheight   = fl_font_SP->p.height;
                    fl_ret_sts           = GUI_GFX_MGR_NO_ERROR;
                }
            }
        }
    }
    return (fl_ret_sts);
}
#endif /* #if GFX_MGR02_NUM_OF_DTEXTS > 0 */ 


#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
/****************************************************************************
Function Name        : hmi_gfx_mgr02_is_line_break_char()
Description          : Returns whether the passed char is a line break char or not.
Invocation           : Invoked by hmi_gfx_mgr02_multiline_algorithm.
Return Value         : TRUE/FALSE
Parameters           : Unicode of character
******************************************************************************/
BOOLEAN hmi_gfx_mgr02_is_line_break_char(HMI_CHAR p_char_unicode, UINT8 p_is_complex, UINT8 p_is_character, UINT8 p_unique_font_id)
{
  UINT8 i;
  BOOLEAN fl_found = FALSE;

  if((p_is_character == (UINT8)TRUE) || (p_is_complex != (UINT8)TRUE))
  {
#if GFX_MGR02_TOTAL_LINE_BREAK_CHAR > 1
    for(i = 0; i < (UINT8)GFX_MGR02_TOTAL_LINE_BREAK_CHAR; i++)
#else
    i = 0;
#endif
    { 
      if(p_char_unicode == lc_gfx_line_break_char_unicode[i])
      { 
        fl_found = TRUE;
      }
    }
  }
  else
  {
    GFX_MGR02_SHAPE_CMAP_TABLE const *fl_ml_lb_cmap_table = &lc_gfx_font_ml_lb_cmap[p_unique_font_id];

#if GFX_MGR02_TOTAL_LINE_BREAK_CHAR > 1
    for(i = 0; i < (UINT8)GFX_MGR02_TOTAL_LINE_BREAK_CHAR; i++)
#else
    i = 0;
#endif
    { 
      if(i < fl_ml_lb_cmap_table->num_chars)
      {
        if(p_char_unicode == fl_ml_lb_cmap_table->ml_cmap[i].char_glyphid)
        { 
          fl_found = TRUE;
        }
      }
    }
  }
  return fl_found;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_is_printable_char()
Description          : Returns whether the passed char is a printable char or not.
Invocation           : Invoked by hmi_gfx_mgr02_multiline_algorithm.
Return Value         : TRUE/FALSE
Parameters           : Unicode of character and flag to indicate char/glyphid
******************************************************************************/
BOOLEAN hmi_gfx_mgr02_is_printable_char(HMI_CHAR p_char_unicode, UINT8 p_is_complex, UINT8 p_is_character, UINT8 p_unique_font_id)
{
  BOOLEAN fl_found = FALSE;

  if((p_is_character == (UINT8)TRUE) || (p_is_complex != (UINT8)TRUE))
  {
    /*Below configuration done to allow space char in the beginning of multiline as per the request from MKTA*/
#ifdef GFX_MGR02_ALLOW_SPACE_IN_ML_START_POS 
    if((p_char_unicode >= 32U) && (p_char_unicode != 127U))
#else
    if((p_char_unicode > 32U) && (p_char_unicode != 127U))
#endif
    {
      fl_found = TRUE;
    }
  }
  else
  {
    GFX_MGR02_SHAPE_CMAP_TABLE const *fl_ml_lb_cmap_table = &lc_gfx_font_ml_sp_cmap[p_unique_font_id];
    HMI_CHAR fl_space_glyph_id = 0U;
    HMI_CHAR fl_del_glyph_id   = 0U;
    UINT8 i;

    for(i = 0U; i < (UINT8)fl_ml_lb_cmap_table->num_chars; i++)
    { 
      if((HMI_CHAR)32 == fl_ml_lb_cmap_table->ml_cmap[i].char_unicode)
      { 
        fl_space_glyph_id = fl_ml_lb_cmap_table->ml_cmap[i].char_glyphid;
      }
      else if((HMI_CHAR)127 == fl_ml_lb_cmap_table->ml_cmap[i].char_unicode)
      { 
        fl_del_glyph_id = fl_ml_lb_cmap_table->ml_cmap[i].char_glyphid;
      }
      else
      {
        /* Do nothing */
      }
    }
    /*Below configuration done to allow space char in the beginning of multiline as per the request from MKTA*/
#ifdef GFX_MGR02_ALLOW_SPACE_IN_ML_START_POS 
    if((p_char_unicode >= fl_space_glyph_id) && (p_char_unicode != fl_del_glyph_id))
#else
    if((p_char_unicode > fl_space_glyph_id) && (p_char_unicode != fl_del_glyph_id))
#endif
    {
      fl_found = TRUE;
    }
  }
  return fl_found;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_shaping_flags()
Description          : Returns the all flag info which need to invoke shaper
Invocation           : 
Return Value         : 
Parameters           : 
******************************************************************************/
void hmi_gfx_mgr02_get_shaping_flags(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, HMI_CHAR const * p_src_str_ptr, u_gx_flocal p_line_start_pos, GFX_MGR02_SHAPE_FLAGS *p_shape_flags)
{
  GFX_MGR02_SHAPE_FLAGS       * fl_shape_flags = p_shape_flags;
  GFX_MGR02_SHAPE_ML_DATA     * fl_ML_data_ptr = GFX_MGR02_NULL_PTR; 
  UINT32                        fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_elem_def_SP->anim_id));
  GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_anim_prop_S = GFX_MGR02_NULL_PTR; 
  UINT32                        fl_font_id;
  GFX_MGR02_FONT const        * fl_font_SP;
  u_gx_flocal                   fl_line_start_position = p_line_start_pos;
  GFX_MGR02_ANIM_DATA_T       *fl_anim_data =  hmi_gfx_mgr02_layout_get_anim_data();

  if(fl_prop_index_u32 < GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
  {
    fl_text_anim_prop_S =  &fl_anim_data->text_prop[fl_prop_index_u32];
  }
  if(p_elem_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
  {
    fl_ML_data_ptr = &l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index];
  }
  if((fl_ML_data_ptr != GFX_MGR02_NULL_PTR) && (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR))
  {
    if(fl_text_anim_prop_S->complex_script == 1U)
    {
      if(p_line_start_pos == (u_gx_flocal)GFX_STR_INVALID_INDEX)
      {
        /* This will be helpful when we doesn't know the index from source string */
        /* This logic gives the current index string from the source string */
        HMI_CHAR const *fl_src_str_ptr = &fl_ML_data_ptr->input_string[0];
        UINT32   fl_current_index = (UINT32)p_src_str_ptr - (UINT32)fl_src_str_ptr;
        fl_current_index = fl_current_index >> 1;  /* HMI_CHAR size is 2 bytes, hence devide it by 2 */
        fl_line_start_position = fl_current_index;
      }
      fl_shape_flags->current_str_index = (UINT16)fl_line_start_position;

      fl_shape_flags->complexity_flag = fl_text_anim_prop_S->complex_script;
      fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_text_anim_prop_S->font_id);
      fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
      if(fl_line_start_position <= GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
      {
        fl_shape_flags->char_flag = fl_ML_data_ptr->is_character[fl_line_start_position];
      }
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)))
      if(fl_font_SP != GFX_MGR02_NULL_PTR)
      {
        fl_shape_flags->unique_fntid_flag = fl_font_SP->unique_id;
      }
      else
#endif
      {
        fl_shape_flags->unique_fntid_flag = 0U;
      }
    }
    else
    {
        fl_shape_flags->char_flag = 1U;
        fl_shape_flags->complexity_flag = 0U;
        fl_shape_flags->current_str_index = 0U;
        fl_shape_flags->unique_fntid_flag = 0U;
    }
  }
}
#else
/****************************************************************************
Function Name        : hmi_gfx_mgr02_is_line_break_char()
Description          : Returns whether the passed char is a line break char or not.
Invocation           : Invoked by hmi_gfx_mgr02_multiline_algorithm.
Return Value         : TRUE/FALSE
Parameters           : Unicode of character
******************************************************************************/
BOOLEAN hmi_gfx_mgr02_is_line_break_char(HMI_CHAR p_char_unicode)
{
  UINT8 i;
  BOOLEAN fl_found = FALSE;
#if GFX_MGR02_TOTAL_LINE_BREAK_CHAR > 1
  for(i = 0; i < (UINT8)GFX_MGR02_TOTAL_LINE_BREAK_CHAR; i++)
#else
  i = 0;
#endif
  { 
    if(p_char_unicode == lc_gfx_line_break_char_unicode[i])
    { 
      fl_found = TRUE;
    }
  }
  return fl_found;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_is_printable_char()
Description          : Returns whether the passed char is a printable char or not.
Invocation           : Invoked by hmi_gfx_mgr02_multiline_algorithm.
Return Value         : TRUE/FALSE
Parameters           : Unicode of character
******************************************************************************/
BOOLEAN hmi_gfx_mgr02_is_printable_char(HMI_CHAR p_char_unicode)
{
  BOOLEAN fl_found = FALSE;
  /*Below configuration done to allow space char in the beginning of multiline as per the request from MKTA*/
#ifdef GFX_MGR02_ALLOW_SPACE_IN_ML_START_POS 
  if((p_char_unicode >= 32U) && (p_char_unicode != 127U)) 
#else 
  if((p_char_unicode > 32U) && (p_char_unicode != 127U)) 
#endif 
  {
    fl_found = TRUE;
  }
  return fl_found;
}
#endif
#endif

#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_select_gfont_index
** Visibility:       global
** Description:      Sets a selected font index and the right2left flag for a  
**                   passed font group ID
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_select_gfont_index(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left)
{
   UINT32 fl_ret_sts;
   fl_ret_sts = hmi_gfx_mgr02_select_gfont(p_font_id, p_selection_index, p_right2left);
   if(fl_ret_sts != (UINT32)FALSE)
   {
      GFX_MGR02_SET_FLAG(l_font_elem_changed_flag_U8A, p_font_id);
      fl_ret_sts = (UINT32)GUI_GFX_MGR_NO_ERROR;
   }
   else
   {
      fl_ret_sts = ((UINT32)GUI_GFX_MGR_BAD_HANDLE_ERROR);
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return(fl_ret_sts);
}
#endif /* #if GFX_MGR02_NUM_OF_FONT_GROUPS > 0 */

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_prop
** Visibility:       global
** Description:      Sets the text element property for the passed text 
**                   element.
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          10-Jun-2013 by EMANOJ1
** Updated:          10-Jun-2013 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_set_text_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                          UINT32                 p_alignment, 
                                          UINT32                 p_draw_mode,
                                          UINT32                 p_clip_mode)
{
   GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
   UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
   UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
      if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
         (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
      {
         GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
         if ((fl_text_dyn_prop_SP->alignment != p_alignment) && (p_alignment != GFX_MGR02_TP_ALIGN_NOCHANGE))
         {
            fl_text_dyn_prop_SP->alignment = (GFX_UINT)p_alignment;
         #if defined(GFX_MGR02_KEPLER)
            GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
         #else
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
         #endif
         }
         if ((fl_text_dyn_prop_SP->draw_mode != p_draw_mode) && (p_draw_mode != GFX_MGR02_TP_DRAW_NOCHANGE))
         {
            fl_text_dyn_prop_SP->draw_mode = (GFX_UINT)p_draw_mode;
         #if defined(GFX_MGR02_KEPLER)
            GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
         #else
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
         #endif
         }
         if ((fl_text_dyn_prop_SP->clip_mode != p_clip_mode) && (p_clip_mode != GFX_MGR02_TP_CLIP_NOCHANGE))
         {
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
           GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
           GFX_MGR02_TEXT_PROPERTY const * fl_text_canim_prop_SP = &lc_text_anim_property_S[fl_prop_index_u32];
           GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = GFX_MGR02_NULL_PTR;
           if(fl_text_canim_prop_SP->base_id < GFX_MGR02_NUM_OF_TEXT_LAYERS)
           {
             fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
           }
#endif
           if (fl_text_layer_prop_SP != GFX_MGR02_NULL_PTR)
           {
             if ((fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1) &&
                 (fl_text_layer_prop_SP->dynamic != (UINT8)0))
             {
               hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_prop_SP, TRUE);
             }
           }
#endif

#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
	       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
           GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index_u32))->base_id);
		   #else
		   GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, lc_text_anim_property_S[fl_prop_index_u32].base_id);
		   #endif
#endif
#endif
		   
           fl_text_dyn_prop_SP->clip_mode = (GFX_UINT)p_clip_mode;
#if defined(GFX_MGR02_KEPLER)
           GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
#else
           GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
#endif
         }
         fl_return_result = GUI_GFX_MGR_NO_ERROR;
      }
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return((UINT32)fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_scroll_parameter
** Visibility:       global
** Description:      Sets the scroll offset value during scroll
**                   for the passed text element.
** Invocation:       Invoked by application
** Inputs/Outputs:   Element Id , scroll offset value.
** Critical Section: None.
** Created:          10-Nov-2014 by ADEVI
** Updated:          10-Nov-2014 by ADEVI
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_scroll_parameter(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                                      UINT16                 p_scroll_offset) 
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
  UINT8  fl_scroll_feature;
  if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
      (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS))
    {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP =hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
#endif 
      fl_scroll_feature = (UINT8)fl_text_layer_def_SP->scroll;

      if(fl_scroll_feature == GFX_MGR02_TP_SCROLL_ENABLE)
      {
        GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
        if((UINT16)fl_text_dyn_prop_SP->scroll_offset != p_scroll_offset)
        {
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
          /*Vertical scroll validation for multiline text*/
          u_gx_flocal fl_total_lines = ((u_gx_flocal)p_scroll_offset + fl_text_dyn_prop_SP->num_of_display_lines);
          if ((fl_text_layer_def_SP->max_num_of_lines > (UINT16)1) && (fl_total_lines > fl_text_layer_def_SP->max_num_of_lines))
          {
            /* Space available only till max lines */
            fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
          }
          else
#endif
          {
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
            //setting changed flag only when we change to zero to non-zero and vice versa
            //Zero  -> text width is calculated for the fittable string(append string added if the string is not fit)
            //Non-Zero->Text width is calculated is for the entire string. Scroll offset applied by using the clip rectangle in the full string.
            if ((fl_text_dyn_prop_SP->scroll_offset > 0.0) != (p_scroll_offset > 0U))
            {
              GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, lc_text_anim_property_S[fl_prop_index_u32].base_id);
            }
#endif
#endif
            /*Horizontal scroll offset for single line/vertical scroll offset for multiline*/
            fl_text_dyn_prop_SP->scroll_offset = (GFX_FLOAT)p_scroll_offset;
#if defined(GFX_MGR02_KEPLER)
            GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
#else
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
#endif

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#if defined(GFX_MGR02_RUN_ML_ALG_FROM_PRESN)
            if((fl_text_layer_def_SP->max_num_of_lines > (UINT16)1) &&
              (fl_text_layer_def_SP->dynamic != (UINT8)0) )
            {
              BOOLEAN fl_is_multiline_data_modified = hmi_gfx_mgr02_get_multiline_data_modified(fl_text_layer_def_SP);
              if (fl_is_multiline_data_modified == (BOOLEAN)FALSE)
              {
                hmi_gfx_mgr02_layout_run_multiline_algorithm(fl_text_layer_def_SP, FALSE, TRUE);
              }
            }
#endif
#endif


            fl_return_result = GUI_GFX_MGR_NO_ERROR;
          }
        }
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return(fl_return_result);
}
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
/*=============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_get_text_scroll_status
 ** Visibility:       global
 ** Description:      Returns the scrolling status of a particular text
 ** Invocation:       Invoked by hmi_gfx_mgr02_generic
 ** Inputs/Outputs:   Object ID 
 ** Critical Section: None.
 **==========================================================================*/
BOOLEAN hmi_gfx_mgr02_layout_get_text_scroll_status(GFX_MGR02_ANIM_ELEM_ID p_obj_id)
{ 
  BOOLEAN result = FALSE;
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_obj_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_obj_id);
  if(GFX_MGR02_IS_DYNAMIC_PROP(p_obj_id))
  { 
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
      (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT32)GFX_MGR02_NUM_OF_TEXT_LAYERS))
    {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP =hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
#endif 
      if(fl_text_layer_def_SP->scroll == GFX_MGR02_TP_SCROLL_ENABLE)
      { 
        result = GFX_MGR02_IS_CHANGED(l_txt_scroll_status_flag_U8A, fl_prop_index_u32);
      }
    }
  }


  return (result);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_start_scroll
** Visibility:       global
** Description:      Sets scroll of the text with animation as 1
** Invocation:       Invoked by application
** Inputs/Outputs:   Anim Id.
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_layout_start_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id)
{
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_text_anim_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_text_anim_id);
  if(GFX_MGR02_IS_DYNAMIC_PROP(p_text_anim_id))
  {
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
      (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT32)GFX_MGR02_NUM_OF_TEXT_LAYERS))
    {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP =hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
#endif 
      if(fl_text_layer_def_SP->scroll == GFX_MGR02_TP_SCROLL_ENABLE)
      {
        GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        GFX_MGR02_SET_FLAG(l_txt_scroll_status_flag_U8A, fl_prop_index_u32);
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_stop_scroll
** Visibility:       global
** Description:      Sets scroll of the text with animation as 0
** Invocation:       Invoked by application
** Inputs/Outputs:   Anim Id.
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_layout_stop_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id)
{
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_text_anim_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_text_anim_id);
  if(GFX_MGR02_IS_DYNAMIC_PROP(p_text_anim_id))
  {
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
      (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT32)GFX_MGR02_NUM_OF_TEXT_LAYERS))
    {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP =hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
#endif 
      if(fl_text_layer_def_SP->scroll== GFX_MGR02_TP_SCROLL_ENABLE)
      {
        if(GFX_MGR02_IS_CHANGED(l_txt_scroll_status_flag_U8A, fl_prop_index_u32) == TRUE)
        { 
          GFX_MGR02_CLR_FLAG(l_txt_scroll_status_flag_U8A, fl_prop_index_u32);
        }
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_scroll
** Visibility:       global
** Description:      resets the scroll offset to 0
** Invocation:       Invoked by application
** Inputs/Outputs:   Anim Id.
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_layout_reset_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id)
{
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_text_anim_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_text_anim_id);
  if(GFX_MGR02_IS_DYNAMIC_PROP(p_text_anim_id))
  {
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
      (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT32)GFX_MGR02_NUM_OF_TEXT_LAYERS))
    {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP =hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
      GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
#endif 
      GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
      if(fl_text_layer_def_SP->scroll == GFX_MGR02_TP_SCROLL_ENABLE)
      {
        if(fl_text_dyn_prop_SP->scroll_offset != (GFX_FLOAT)0.0)
        { 
          GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
          fl_text_dyn_prop_SP->scroll_offset = (GFX_FLOAT)0.0;
        }
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_stop_reset_scroll
** Visibility:       global
** Description:      Sets scroll of the text with animation as 0 and
**                   resets the scroll offset
** Invocation:       Invoked by application
** Inputs/Outputs:   Anim Id.
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_layout_stop_reset_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id)
{
  hmi_gfx_mgr02_layout_reset_scroll(p_text_anim_id);
  hmi_gfx_mgr02_layout_stop_scroll(p_text_anim_id);
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
}
#endif

#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_text_property_max_shrink
** Visibility:       global
** Description:      Returns the max shrink property value 
**                   for the passed text element.
** Invocation:       Invoked by application
** Inputs/Outputs:   Element Id , max shrink value.
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_property_max_shrink(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 * p_max_shrink)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
  UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

  if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
       (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
    {
      GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
      *p_max_shrink = fl_text_dyn_prop_SP->max_shrink;
      fl_return_result = GUI_GFX_MGR_NO_ERROR;
    }
    else
    {
      fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
    }
  }
  return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_property_max_shrink
** Visibility:       global
** Description:      Sets the maximum percentage of shrinking to be allowed
**                   for the passed text element.
** Invocation:       Invoked by application
** Inputs/Outputs:   Element Id , max shrink value.
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_property_max_shrink(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_max_shrink)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
  if(p_max_shrink <= 100U)
  {
    UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
      if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
         (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
      {
        GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
        if(fl_text_dyn_prop_SP->max_shrink != p_max_shrink)
        {
          fl_text_dyn_prop_SP->max_shrink = p_max_shrink;
          GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        }
        fl_return_result = GUI_GFX_MGR_NO_ERROR;
      }
      else
      {
        fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return(fl_return_result);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_global_max_shrink
** Visibility:       global
** Description:      Sets the maximum percentage of shrinking to be allowed
**                   for all the texts globally.
** Invocation:       Invoked by application
** Inputs/Outputs:   max shrink value.
** Critical Section: None.
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_global_max_shrink(UINT8 p_max_shrink)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
  if(p_max_shrink <= 100U)
  {
    l_global_text_max_shrink = p_max_shrink;
    fl_return_result = GUI_GFX_MGR_NO_ERROR;
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_text_global_max_shrink
** Visibility:       global
** Description:      Returns the global max shrink value
** Invocation:       Invoked by application
** Inputs/Outputs:   max shrink value.
** Critical Section: None.
**==========================================================================*/
UINT8 hmi_gfx_mgr02_layout_get_text_global_max_shrink(void)
{
  return(l_global_text_max_shrink);
}

#endif



#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP))
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_font()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   This interface is used for setting the text value for a
**                   dynamic text element.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
** Critical Section: None
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_font(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_font_id
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))
, UINT8 p_font_pt_size
#endif
)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_error = GUI_GFX_MGR_INVALID_TARGET;

  UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

  if (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
    {
      GFX_MGR02_TEXT_DYN_PROPERTY *fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];

      if ((fl_text_dyn_prop_SP->font_id < (UINT8)GFX_MGR02_NUM_OF_FONTS) && (p_font_id < (UINT8)GFX_MGR02_NUM_OF_FONTS))
      {
        if (fl_text_dyn_prop_SP->font_id != p_font_id)
        {
          fl_text_dyn_prop_SP->font_id = p_font_id;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))
          if (fl_text_dyn_prop_SP->font_pt_size != p_font_pt_size)
          {
            fl_text_dyn_prop_SP->font_pt_size = p_font_pt_size;
          }
#endif
#if defined(GFX_MGR02_KEPLER)
          GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
#else
          GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2))
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
          GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, lc_text_anim_property_S[fl_prop_index_u32].base_id);
#endif
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_TRAVEO2))
          {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
            GFX_MGR02_TEXT_DEF_T const *fl_text_layer_def_SP = hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index_u32);
#else
            GFX_MGR02_TEXT_DEF_T const *fl_text_layer_def_SP = GFX_MGR02_NULL_PTR;
            if (lc_text_anim_property_S[fl_prop_index_u32].base_id < GFX_MGR02_NUM_OF_TEXT_LAYERS)
            {
              fl_text_layer_def_SP = &lc_text_layer_def_S[lc_text_anim_property_S[fl_prop_index_u32].base_id];
            }
#endif
            if (fl_text_layer_def_SP != GFX_MGR02_NULL_PTR)
            {
              if ((fl_text_layer_def_SP->max_num_of_lines > (UINT8)1) &&
                  (fl_text_layer_def_SP->dynamic != (UINT8)0))
              {
                hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_def_SP, TRUE);
              }
            }
          }
#endif
        }
        fl_error = GUI_GFX_MGR_NO_ERROR;
      }
    }
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return fl_error;
}
#endif /* GFX_MGR02_AMBER */
#endif

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_dyn_text_multiline_data()
Description          : Returns the p_multi_line_array and p_multi_line from the
                       corresponding location of l_dynamic_text_buffer. 
Invocation           : Invoked by graphics manager.
Return Value         : void
Parameters           : GFX_MGR02_TEXT_DEF_T, GFX_MGR02_MULTI_LINE_INFO, GFX_MGR02_MULTI_LINE_DATA, scroll offset
******************************************************************************/
void hmi_gfx_mgr02_get_dyn_text_multiline_data(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP, GFX_MGR02_MULTI_LINE_INFO *p_multi_line, GFX_MGR02_MULTI_LINE_DATA *p_multi_line_array, u_gx_flocal p_scroll)
{
  UINT32 fl_data_index;
  u_gx_flocal fl_actual_displayed_lines = p_scroll;
  u_gx_flocal fl_multi_line_data;
  u_gx_flocal fl_num_chars;
  GFX_MGR02_MULTI_LINE_DATA *fl_multi_line_array = p_multi_line_array;
  p_multi_line->is_data_available = 0;
  p_multi_line->num_of_display_lines = 0;
  fl_num_chars = (u_gx_flocal)p_elem_def_SP->max_num_of_lines * (u_gx_flocal)p_elem_def_SP->num_chars;

  if((p_elem_def_SP->max_num_of_lines > (UINT16)1) && (fl_num_chars > (u_gx_flocal)0))
  {
    fl_data_index = p_elem_def_SP->string_index + fl_num_chars;
    fl_data_index++;
    if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
    {
      fl_multi_line_data = (u_gx_flocal)l_dynamic_text_buffer[fl_data_index];
      p_multi_line->num_of_display_lines = (GFX_UINT)GFX_MGR02_MULTI_NUM_OF_LINES(fl_multi_line_data); 
      p_multi_line->is_data_available   = GFX_MGR02_MULTI_IS_DATA_AVBL(fl_multi_line_data);
      fl_data_index = (UINT32)(fl_data_index + (p_scroll*GFX_MGR02_MULTI_BYTES_OF_DATA_PER_LINE));
      GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index); /*2 byte increment for skipping total number of displayed lines*/
      while(fl_actual_displayed_lines <  p_elem_def_SP->max_num_of_lines)
      {
        HMI_CHAR  *fl_dyn_text_buffer     = &l_dynamic_text_buffer[0];
        GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);
        if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          fl_multi_line_array->start_pos     = fl_dyn_text_buffer[fl_data_index];
        }
        GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);
        if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          fl_multi_line_array->parameter.strlength = (UINT16)fl_dyn_text_buffer[fl_data_index];
          /*If there is no data available, then break the loop to avoid unnecessary calculations*/
          if(fl_multi_line_array->parameter.strlength == 0U)
          {
            break;
          }
        }
        fl_actual_displayed_lines++;
        fl_multi_line_array++;
      }
    }
  }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_set_dyn_text_multiline_data()
Description          : Sets the p_multi_line_array and p_multi_line in the
                       corresponding location of l_dynamic_text_buffer. 
Invocation           : Invoked by graphics manager.
Return Value         : void
Parameters           : GFX_MGR02_DTEXT_ID, GFX_MGR02_MULTI_LINE_INFO, GFX_MGR02_MULTI_LINE_DATA
******************************************************************************/
void hmi_gfx_mgr02_set_dyn_text_multiline_data(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP,
                                               GFX_MGR02_MULTI_LINE_INFO const*p_multi_line,
                                               GFX_MGR02_MULTI_LINE_DATA const*p_multi_line_array,
                                               BOOLEAN p_updateData)
{
  GFX_MGR02_MULTI_LINE_DATA const*fl_multi_line_array = p_multi_line_array;
  if(p_elem_def_SP->dynamic != (UINT8)0)
  {
    if(p_elem_def_SP->max_num_of_lines > (UINT16)1)
    {	
      UINT32 fl_data_index;
      u_gx_flocal fl_num_of_lines = 0;
      u_gx_flocal fl_num_chars = (u_gx_flocal)p_elem_def_SP->max_num_of_lines * (u_gx_flocal)p_elem_def_SP->num_chars;

      fl_data_index = p_elem_def_SP->string_index + fl_num_chars;
      fl_data_index++;
      if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
      {
        l_dynamic_text_buffer[fl_data_index] = p_multi_line->num_of_display_lines;
        GFX_MGR02_MULTI_SET_DATA_AVBL(p_multi_line->is_data_available, l_dynamic_text_buffer[fl_data_index]);
        GFX_MGR02_MULTI_SET_DATA_MODIFIED(FALSE, l_dynamic_text_buffer[fl_data_index]);
        if(p_updateData != FALSE)
        {
          GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);/*2 byte for saving total number of displayed lines*/
          GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);/*Start saving algorithm output from this index*/
          while(fl_num_of_lines < (u_gx_flocal)p_elem_def_SP->max_num_of_lines)
          {
            HMI_CHAR  *fl_dyn_text_buffer     = &l_dynamic_text_buffer[0];
            if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
            {
              fl_dyn_text_buffer[fl_data_index] = fl_multi_line_array->start_pos;
            }
            GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);
            if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
            {
              fl_dyn_text_buffer[fl_data_index] = fl_multi_line_array->parameter.strlength;
              fl_multi_line_array++;
            }
            GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index);
            fl_num_of_lines++;
          }
        }
      }
    }
  }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_multiline_info()
Description          : Fills the p_multi_line_data of the p_elem_id passed. 
Invocation           : Invoked by Application.
Return Value         : GUI_GFX_MGR_ERROR_CODE_T
Parameters           : GFX_MGR02_DTEXT_ID, GFX_MGR02_MULTI_LINE_INFO 
******************************************************************************/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_get_multiline_info(GFX_MGR02_DTEXT_ID p_elem_id, GFX_MGR02_MULTI_LINE_INFO *p_multi_line_data)
{
  GUI_GFX_MGR_ERROR_CODE_T      fl_return_result     = GUI_GFX_MGR_NO_ERROR;

  if(p_elem_id < (GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS)
  {
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP;
   #if defined(GFX_MGR02_DLAYOUT_ENABLED)
    fl_text_layer_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
   #else
    fl_text_layer_def_SP = &lc_text_layer_def_S[p_elem_id];
   #endif
    if(fl_text_layer_def_SP->max_num_of_lines > (UINT16)1)
    {
      HMI_CHAR fl_multi_line_data;
      UINT32 fl_data_index;
      fl_data_index = fl_text_layer_def_SP->string_index + ((UINT32)fl_text_layer_def_SP->num_chars * (UINT32)fl_text_layer_def_SP->max_num_of_lines);
      fl_data_index++;
      hmi_gfx_mgr02_layout_run_multiline_algorithm(fl_text_layer_def_SP, FALSE, FALSE);
      if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
      {
        fl_multi_line_data = l_dynamic_text_buffer[fl_data_index];
        p_multi_line_data->num_of_display_lines = (GFX_UINT)GFX_MGR02_MULTI_NUM_OF_LINES(fl_multi_line_data);
        p_multi_line_data->is_data_available   = (GFX_UINT)GFX_MGR02_MULTI_IS_DATA_AVBL(fl_multi_line_data);
      }
    }
    else
    {
      p_multi_line_data->is_data_available    = 0;
      p_multi_line_data->num_of_display_lines = 0;
      fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    }
  }
  else
  {
    fl_return_result = GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID;
  }
  return (fl_return_result);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_set_multiline_data_modified()
Description          : sets the multi line data updated information for the passed 
                       text element definition data. 
Invocation           : Invoked by layout interfaces.
Return Value         : None
Parameters           : TEXT_DEF, BOOLEAN 
******************************************************************************/
static void hmi_gfx_mgr02_set_multiline_data_modified(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP, BOOLEAN p_modified)
{
  /*string index for the current text*/
  u_gx_flocal fl_data_index  = (u_gx_flocal)p_elem_def_SP->string_index;
  /*Total number of characters for the entire multi line text*/
  u_gx_flocal fl_num_chars   = (u_gx_flocal)p_elem_def_SP->max_num_of_lines * (u_gx_flocal)p_elem_def_SP->num_chars;
  fl_data_index += fl_num_chars;/*Skip the multiline text*/
  fl_data_index++;/*Skip null character of the multiline text*/
  if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
  {
    GFX_MGR02_MULTI_SET_DATA_MODIFIED(p_modified, l_dynamic_text_buffer[fl_data_index]);
    if (p_modified == TRUE)
    {
//Invalidating the existing algorithm output.
#ifndef GFX_MGR02_RUN_ML_ALG_FROM_PRESN
      GFX_MGR02_MULTI_LINE_INFO fl_multi_line_info;
      fl_multi_line_info.is_data_available = 0;
      fl_multi_line_info.num_of_display_lines = 0;
      GFX_MGR02_MULTI_LINE_DATA fl_multi_line_array[GFX_MGR02_MULTI_LINE_ARRAY_SIZE];
      (void)memset(&fl_multi_line_array[0], 0, sizeof(fl_multi_line_array));
      hmi_gfx_mgr02_set_dyn_text_multiline_data(p_elem_def_SP, &fl_multi_line_info, &fl_multi_line_array[0], TRUE);
#endif
      GFX_MGR02_MULTI_INC_STRING_INDEX(fl_data_index); /*Skip no of displayed lines information*/
      /*Set invalid value. This value is set to avoid returning wrong value when we call
        hmi_gfx_mgr02_get_total_lines_in_multiline in the below sequence.
        hmi_gfx_mgr02_get_total_lines_in_multiline
        hmi_gfx_mgr02_layout_set_obj_dim_w(Or any dependent parameter)
        hmi_gfx_mgr02_generic_build_text - Here algorithm will not run for the entire text.
        hmi_gfx_mgr02_get_total_lines_in_multiline
      */
      if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
      {
        l_dynamic_text_buffer[fl_data_index] = 0U;
      }
    }
  }
}
#if defined(GFX_MGR02_RUN_ML_ALG_FROM_PRESN) 
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_multiline_data_modified()
Description          : gets the multi line data updated information for the passed 
                       text element definition data. 
Invocation           : Invoked by layout interfaces.
Return Value         : BOOLEAN  - Data modified or not
Parameters           : TEXT_DEF 
******************************************************************************/
static BOOLEAN hmi_gfx_mgr02_get_multiline_data_modified(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP)
{
  BOOLEAN fl_status = FALSE;
  /*string index for the current text*/
  u_gx_flocal fl_data_index  = (u_gx_flocal)p_elem_def_SP->string_index;
  /*Total number of characters for the entire multi line text*/
  u_gx_flocal fl_num_chars   = (u_gx_flocal)p_elem_def_SP->max_num_of_lines * (u_gx_flocal)p_elem_def_SP->num_chars;
  fl_data_index += fl_num_chars;/*Skip the multiline text*/
  fl_data_index++;/*Skip null character of the multiline text*/
  if(fl_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
  {
    fl_status = (BOOLEAN)GFX_MGR02_MULTI_IS_DATA_MODIFIED(l_dynamic_text_buffer[fl_data_index]);
  }
  return fl_status;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_total_lines_in_multiline()
Description          : Calculate the total number of lines in the given multiline text
Invocation           : Invoked by Application.
Return Value         : UINT16 - Total number of lines in the given text
Parameters           : GFX_MGR02_DTEXT_ID 
******************************************************************************/
UINT16 hmi_gfx_mgr02_get_total_lines_in_multiline(GFX_MGR02_DTEXT_ID p_elem_id)
{
  UINT16 fl_return_result = 0U;/*Invalid value*/;
  if(p_elem_id < (GFX_MGR02_DTEXT_ID)GFX_MGR02_NUM_OF_DTEXTS)
  {
    GFX_MGR02_TEXT_DEF_T const  * fl_text_layer_def_SP;
    u_gx_flocal fl_num_chars              = 0U;
    /*Index to point the displayed lines/isDataAvailabl/IsMultiLineData modified flags*/
    u_gx_flocal fl_displayed_lines_index  = 0U;

#if defined(GFX_MGR02_DLAYOUT_ENABLED)
    fl_text_layer_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr((UINT32)p_elem_id);
#else
    fl_text_layer_def_SP = &lc_text_layer_def_S[p_elem_id];
#endif
    fl_num_chars              =   (u_gx_flocal)(fl_text_layer_def_SP->max_num_of_lines) *
      (u_gx_flocal)(fl_text_layer_def_SP->num_chars);
    fl_displayed_lines_index  =   (u_gx_flocal)fl_text_layer_def_SP->string_index + fl_num_chars;/*Skip input text*/
    fl_displayed_lines_index++;/*Skip null character*/
    if(fl_displayed_lines_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
    {
      if(GFX_MGR02_MULTI_IS_DATA_MODIFIED(l_dynamic_text_buffer[fl_displayed_lines_index]) == FALSE)
      {
        u_gx_flocal fl_tot_line_index = fl_displayed_lines_index;
        GFX_MGR02_MULTI_INC_STRING_INDEX(fl_tot_line_index);/*Move to total no of lines*/
        if(fl_tot_line_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          fl_return_result = l_dynamic_text_buffer[fl_tot_line_index];
        }
        /*if fl_return_result has the default value means algorithm is not run for the complete text.
        Hence set modified flag to true and run the algorithm again. The below use case will be applicable
        when we call hmi_gfx_mgr02_get_total_lines_in_multiline after calling build_text*/
        if(fl_return_result == 0U)
        {
          GFX_MGR02_MULTI_SET_DATA_MODIFIED(TRUE, l_dynamic_text_buffer[fl_displayed_lines_index]);
        }
      }
      /*Run and get the data if the value is not valid*/
      if(fl_return_result == 0U)
      {
        u_gx_flocal fl_tot_line_index = fl_displayed_lines_index;
        hmi_gfx_mgr02_layout_run_multiline_algorithm(fl_text_layer_def_SP, TRUE, FALSE);
        GFX_MGR02_MULTI_INC_STRING_INDEX(fl_tot_line_index);/*Move to total no of lines*/
        if(fl_tot_line_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          fl_return_result = l_dynamic_text_buffer[fl_tot_line_index];
        }
      }
    }
  }
  return (fl_return_result);
}


/********************************************************************************************
Function Name        : hmi_gfx_mgr02_layout_run_multiline_algorithm()
Description          : Prepare GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM and execute corresponding
                       multiline algorithm based on the language and update algorithm ouput
                       in l_dynamic_buffer
Invocation           : Invoked by layout/generic functions.
Return Value         : None
Parameters           : GFX_MGR02_TEXT_DEF_T - Pointer to GFX_MGR02_TEXT_DEF_T structure
                     , BOOLEAN p_complete   - To decide whether to run algorithm for the
                        entire text/number of displayed lines
                     , BOOLEAN p_EvalAndRun - To decide whether to run algorithm for the
                        entire text/number of displayed linesand
**********************************************************************************************/
void hmi_gfx_mgr02_layout_run_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP,
                                                   BOOLEAN p_complete,
                                                   BOOLEAN p_EvalAndRun)
{
  if(p_elem_def_SP->max_num_of_lines > (UINT16)1)
  {
    u_gx_flocal fl_num_chars = (u_gx_flocal)p_elem_def_SP->max_num_of_lines * (u_gx_flocal)p_elem_def_SP->num_chars;
    u_gx_flocal fl_multi_line_data_index = p_elem_def_SP->string_index + fl_num_chars;
    fl_multi_line_data_index++;/*Increment for null char*/
    if(fl_multi_line_data_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
    {
      if((GFX_MGR02_MULTI_IS_DATA_MODIFIED(l_dynamic_text_buffer[fl_multi_line_data_index]) != FALSE) ||
        (p_EvalAndRun != FALSE))
      {
        HMI_CHAR      const * fl_string_ptr = GFX_MGR02_NULL_PTR;
        HMI_CHAR      const * fl_temp_str_ptr = GFX_MGR02_NULL_PTR;
        u_gx_flocal fl_scroll_offset = 0U;
        u_gx_flocal fl_num_of_display_lines = 0U;
        GFX_MGR02_MULTI_LINE_DATA             fl_multi_line_array[GFX_MGR02_MULTI_LINE_ARRAY_SIZE];
        GFX_MGR02_MULTI_LINE_INFO             fl_multi_line_info = {0};
      GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM  fl_multi_line_param = {0};
  #if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
        BOOLEAN fl_RunRTL = (UINT8)FALSE;
  #endif
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_def_SP->anim_id))
        {
  #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
          u_gx_flocal fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_def_SP->anim_id);
          u_gx_flocal fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_def_SP->anim_id);

  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          GFX_MGR02_TEXT_PROPERTY const * fl_text_anim_prop_static = GFX_MGR02_NULL_PTR;
          if(fl_prop_index_u32 < GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
          {
            fl_text_anim_prop_static = &lc_text_anim_property_S[fl_prop_index_u32];
            /* Inovke shape engine only when text element data got changed and script is complex */
            if(hmi_gfx_mgr02_layout_is_element_changed((UINT32)fl_text_anim_prop_static->base_id, p_elem_def_SP->anim_id) != (UINT32)FALSE)
            {
              UINT16 fl_str_len;
              GFX_MGR02_ANIM_DATA_T *fl_anim_data =  hmi_gfx_mgr02_layout_get_anim_data();
              GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_anim_prop_S = GFX_MGR02_NULL_PTR;
#if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
              UINT8 fl_RTL_language = 0;
#endif
              UINT8 fl_complex_script = 0;
              if(p_elem_def_SP->string_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
              {
                fl_text_anim_prop_S = &fl_anim_data->text_prop[fl_prop_index_u32];
                fl_string_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
                fl_str_len = (UINT16)HMI_STRLEN(fl_string_ptr);
                if ((hmi_gfx_mgr02_get_arabic_char_count(fl_string_ptr, fl_str_len) != 0U) || \
                  (hmi_gfx_mgr02_get_hebrew_char_count(fl_string_ptr, fl_str_len) != 0U))
                {
                  fl_complex_script = 1U;
#if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
                  fl_RTL_language = 1U;
#endif
                }
                else if(hmi_gfx_mgr02_get_thai_char_count(fl_string_ptr, fl_str_len) != 0U)
                {
                  fl_complex_script = 1U;
                }
                else
                {
                  /*do nothing*/
                }
                if(fl_complex_script != 0U)
                {
                  UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_text_anim_prop_S->font_id);
                  GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
                  if (p_elem_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
                  {
                    fl_ML_data_ptr = &l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index];
                  }
#if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
                  TsShaperText *fl_shaper_ptr = hmi_gfx_mgr02_shape_engine_get_gpos(fl_font_id, NULL, fl_string_ptr, TRUE, fl_str_len, NULL);
                  if((fl_shaper_ptr != GFX_MGR02_NULL_PTR) && (fl_ML_data_ptr != GFX_MGR02_NULL_PTR))
                  {
                    UINT16 fl_index = 0;
                    UINT16 fl_shape_index = 0;
                    TsTextProcessInfo * textInfo;
                    fl_str_len = (UINT16)fl_shaper_ptr->textInfoArrayLen;
                    fl_text_anim_prop_S->complex_script = 1U;

                    while(fl_index < fl_str_len)
                    {
                      textInfo = GFX_MGR02_NULL_PTR;
                      if(fl_shape_index < fl_str_len)
                      {
                        textInfo = &fl_shaper_ptr->textInfoArray[fl_shape_index];
                      }
                      /* Skip invalid glyphs (previously assigned the NOP value) */
                      if ((textInfo != GFX_MGR02_NULL_PTR) && ((TsUInt16)TsGlyphID_NOP != textInfo->glyphID))
                      {
                        if ((0U != textInfo->glyphID) && (textInfo->character > 32U))
                        {
                          fl_ML_data_ptr->input_string[fl_index] = textInfo->glyphID;
                          fl_ML_data_ptr->is_character[fl_index] = 0;
                        }
                        else
                        {
                          fl_ML_data_ptr->input_string[fl_index] = (HMI_CHAR)textInfo->character;
                          fl_ML_data_ptr->is_character[fl_index] = 1;
                        }
                        fl_ML_data_ptr->delta_val[fl_index].delta_pixels_x = (SINT16)textInfo->advance.x;
                        fl_ML_data_ptr->delta_val[fl_index].delta_pixels_y = (SINT16)textInfo->advance.y;
                        fl_index++;
                      }
                      fl_shape_index++;
                    }
                    fl_ML_data_ptr->input_string[fl_index] = 0U;
                  }
 #elif (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
                  UINT16 fl_shape_str_size = fl_str_len * 2U; //This should have enough space to expand the input string. So allocating 2X the size of input string
                  HMI_CHAR *fl_shaped_string_ptr = (HMI_CHAR*)malloc((sizeof(HMI_CHAR)) * (fl_shape_str_size));
                  if (fl_shaped_string_ptr != GFX_MGR02_NULL_PTR)
                  {
                    GFX_MGR02_HB_SHAPE_INFO* fl_shaper_ptr = hmi_gfx_mgr02_process_ubidi(fl_string_ptr, fl_str_len, fl_RTL_language, fl_font_id, fl_shaped_string_ptr);
                    if ((fl_shaper_ptr != GFX_MGR02_NULL_PTR) && (fl_ML_data_ptr != GFX_MGR02_NULL_PTR))
                    {
                      UINT16 fl_index = 0;
                      fl_str_len = (UINT16)fl_shaper_ptr->glyph_count;
                      fl_text_anim_prop_S->complex_script = 1U;

                      for (fl_index = 0; fl_index < fl_shaper_ptr->glyph_count; fl_index++)
                      {
                        if (fl_shaper_ptr->content_type[fl_index] == HB_BUFFER_CONTENT_TYPE_UNICODE)
                        {
                          fl_ML_data_ptr->is_character[fl_index] = 1U;
                          fl_ML_data_ptr->input_string[fl_index] = fl_shaper_ptr->unicode[fl_index];
                        }
                        else if (fl_shaper_ptr->content_type[fl_index] == HB_BUFFER_CONTENT_TYPE_GLYPHS)
                        {
                          fl_ML_data_ptr->is_character[fl_index] = 0U;
                          fl_ML_data_ptr->input_string[fl_index] = fl_shaper_ptr->code_point[fl_index];
                        }
                        fl_ML_data_ptr->delta_val[fl_index].delta_pixels_x = fl_shaper_ptr->x_offset[fl_index];
                        fl_ML_data_ptr->delta_val[fl_index].delta_pixels_y = fl_shaper_ptr->y_offset[fl_index];
                      }
                      fl_ML_data_ptr->input_string[fl_index] = 0U;
                    }
                    free(fl_shaped_string_ptr);
                    fl_shaped_string_ptr = 0;
                  }
 #endif
                }
                else
                {
                  fl_text_anim_prop_S->complex_script = 0U;
                }
              }
            }
          }
  #endif
          if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
          {
            GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
            fl_multi_line_param.num_of_display_lines  = (p_complete != FALSE) ? (u_gx_flocal)p_elem_def_SP->max_num_of_lines : 
              (u_gx_flocal)fl_text_dyn_prop_SP->num_of_display_lines; /*To run for complete text*/
            fl_num_of_display_lines                   = (u_gx_flocal)fl_text_dyn_prop_SP->num_of_display_lines;
            fl_multi_line_param.alignment             = (u_gx_flocal)fl_text_dyn_prop_SP->alignment;
            fl_multi_line_param.clip_mode             = (u_gx_flocal)fl_text_dyn_prop_SP->clip_mode;
            fl_multi_line_param.font_id               = (u_gx_flocal)fl_text_dyn_prop_SP->font_id;
  #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
            fl_multi_line_param.font_pt_size          = fl_text_dyn_prop_SP->font_pt_size;
  #endif
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            fl_multi_line_param.complex_script_flag   = fl_text_dyn_prop_SP->complex_script;
  #endif
            fl_multi_line_param.text_width            = (u_gx_flocal)fl_text_dyn_prop_SP->width;
            fl_multi_line_param.scroll_offset         =  (p_complete != FALSE) ? 0U : (u_gx_flocal)fl_text_dyn_prop_SP->scroll_offset; /*To run for complete text*/
            fl_scroll_offset                          = (u_gx_flocal)fl_text_dyn_prop_SP->scroll_offset;
            fl_multi_line_param.evaluale_and_run      = p_EvalAndRun;
          }
  #endif
        }
        else
        {
          fl_multi_line_param.num_of_display_lines    = (p_complete != FALSE) ? (u_gx_flocal)p_elem_def_SP->max_num_of_lines : 
              (u_gx_flocal)p_elem_def_SP->num_of_display_lines; /*To run for complete text*/
          fl_num_of_display_lines                     = (u_gx_flocal)p_elem_def_SP->num_of_display_lines;
          fl_multi_line_param.alignment               = (u_gx_flocal)p_elem_def_SP->alignment;
          fl_multi_line_param.clip_mode               = (u_gx_flocal)p_elem_def_SP->clip_mode;
          fl_multi_line_param.font_id                 = (u_gx_flocal)p_elem_def_SP->font_id;
  #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
          fl_multi_line_param.font_pt_size            = (UINT8)lc_gfx_font_table[p_elem_def_SP->font_id].height_pts;
  #endif
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          fl_multi_line_param.complex_script_flag   = 0U;
  #endif
          fl_multi_line_param.text_width              = (u_gx_flocal)p_elem_def_SP->width;
          fl_multi_line_param.scroll_offset           = 0U;
          fl_multi_line_param.evaluale_and_run        = p_EvalAndRun;
        }

        (void)memset(&fl_multi_line_array[0], 0, sizeof(fl_multi_line_array));
  #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
        if(p_elem_def_SP->string_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          if(fl_multi_line_param.complex_script_flag == 1U)
          {
            if(p_elem_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
            {
              /* Run algorithm on shape engine ran data which is stored in another buffer */
              fl_temp_str_ptr = (HMI_CHAR const *)&l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index].input_string;
            }
            fl_string_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
          }
          else
          {
            fl_temp_str_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
            fl_string_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
          }
        }
  #else
        if(p_elem_def_SP->string_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
        {
          fl_temp_str_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
          fl_string_ptr = &l_dynamic_text_buffer[p_elem_def_SP->string_index];
        }
  #endif
  #if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
  #ifdef GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED
        if((fl_string_ptr != GFX_MGR02_NULL_PTR) && (hmi_gfx_mgr02_get_arabic_char_count(fl_string_ptr,(UINT16)HMI_STRLEN(fl_string_ptr)) != 0U))
        {
          fl_RunRTL = (UINT8)TRUE;
        }
        else
  #endif
  #ifdef GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED
        if((fl_string_ptr != GFX_MGR02_NULL_PTR) && (hmi_gfx_mgr02_get_hebrew_char_count(fl_string_ptr,(UINT16)HMI_STRLEN(fl_string_ptr)) != 0U))
        {
          fl_RunRTL = (UINT8)TRUE;
        }
        else
  #endif
        {
          /* Do Nothing */
        }
        if(fl_RunRTL == (UINT8)TRUE)
          {
            fl_string_ptr = fl_temp_str_ptr;
            if(fl_string_ptr != GFX_MGR02_NULL_PTR)
            {
              fl_multi_line_info = hmi_gfx_mgr02_run_RTL_multiline_algorithm(p_elem_def_SP,
                                  fl_string_ptr, &fl_multi_line_array[0], &fl_multi_line_param,TRUE);
            }
          }
          else
  #endif
          {
            fl_string_ptr = fl_temp_str_ptr;
            if(fl_string_ptr != GFX_MGR02_NULL_PTR)
            {
              fl_multi_line_info = hmi_gfx_mgr02_run_multiline_algorithm(p_elem_def_SP,
                                  fl_string_ptr, &fl_multi_line_array[0], &fl_multi_line_param,FALSE);
            }
          }
        if(p_complete != FALSE)
        {
          u_gx_flocal fl_total_number_of_lines      = (u_gx_flocal)fl_multi_line_info.num_of_display_lines;
          u_gx_flocal fl_tot_line_index             = fl_multi_line_data_index;
          BOOLEAN fl_is_data_available              = FALSE;
          GFX_MGR02_MULTI_INC_STRING_INDEX(fl_tot_line_index);
          /*Set the calculated number of lines in dynamic buffer*/
          if(fl_tot_line_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
          {
            l_dynamic_text_buffer[fl_tot_line_index]  = (HMI_CHAR)fl_total_number_of_lines;
          }

          /*Update multiline info with the current value to avoid wrong value updation when
          we call hmi_gfx_mgr02_get_total_lines_in_multiline during build text. Check 
          hmi_gfx_mgr02_set_multiline_data_modified function for further details*/
          fl_is_data_available                      = ((fl_scroll_offset + fl_num_of_display_lines) < fl_total_number_of_lines) ? TRUE : FALSE;
          fl_multi_line_info.is_data_available      = fl_is_data_available;
          fl_multi_line_info.num_of_display_lines   = (fl_is_data_available != FALSE)? (UINT16)(fl_num_of_display_lines) :
            (UINT16)(fl_total_number_of_lines - fl_scroll_offset);
        }

        /*If we move to the last scroll, then update the total lines to avoid unnecessary algorithm execution*/
        if((p_EvalAndRun != FALSE) && (fl_multi_line_info.is_data_available == FALSE) &&
          (fl_multi_line_info.num_of_display_lines != 0U))
        {
          u_gx_flocal fl_total_number_of_lines      = (u_gx_flocal)(fl_scroll_offset + fl_multi_line_info.num_of_display_lines);
          u_gx_flocal fl_tot_line_index             = fl_multi_line_data_index;
          GFX_MGR02_MULTI_INC_STRING_INDEX(fl_tot_line_index);
          /*Set the calculated number of lines in dynamic buffer*/
          if(fl_tot_line_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
          {
            l_dynamic_text_buffer[fl_tot_line_index]  = (HMI_CHAR)fl_total_number_of_lines;
          }
        }
      }
    }
  }
}

#endif

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_select_dwidget()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   Sets the selection index for a dynamic widget.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Dynamic widget element ID  
**                   p_index   ==> Selection index
** Critical Section: None
** Created:          17-Aug-2012 by VMUTHUSU
** Updated:          20-Nov-2012 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dwidget(GFX_MGR02_DWDG_ELEM_ID p_elem_id, UINT32 p_index)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;
    UINT32                           fl_obj_type_u32    = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32                           fl_prop_index_u32  = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    if(fl_obj_type_u32 == GFX_MGR02_TYPE_DWIDGET)
    {
        /* passed object is of type Dynamic Widget */
        if(fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_DYNAMIC_WIDGETS)
        {
            if(l_dyn_widget_selection[fl_prop_index_u32] != (UINT16)p_index)
            {
                /* passed element is within the Dynamic Widget range */
                l_dyn_widget_selection[fl_prop_index_u32] = (UINT16)p_index;
                GFX_MGR02_SET_FLAG(l_dwidget_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
        {
            /* passed dynamic widget index is not valid */
            fl_return_result = GUI_GFX_MGR_INVALID_DWDG_ELEM_ID;
        }
    }
    else
    {
        /* passed object type is invalid for this interface return error */
        fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_select_dwidget() */

#endif /* #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0 */

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_select_dimage()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   Sets the selection index for a dynamic image.
** Invocation:       By Presentation layer.
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Dynamic image element ID  
**                   p_index   ==> Selection index
** Critical Section: None
** Created:          17-Aug-2012 by VMUTHUSU
** Updated:          17-Aug-2012 by VMUTHUSU
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dimage(GFX_MGR02_DIMG_ELEM_ID p_elem_id, UINT32 p_index)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;
    UINT32                           fl_obj_type_u32    = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32                           fl_prop_index_u32  = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    if(fl_obj_type_u32 == GFX_MGR02_TYPE_DIMAGE)
    {
        /* passed object is of type Dynamic Image */
        if(fl_prop_index_u32 < ((UINT32)GFX_MGR02_NUM_DYNAMIC_IMAGES))
        {
            if(l_dyn_image_selection[fl_prop_index_u32] != (UINT16)p_index)
            {
                l_dyn_image_selection[fl_prop_index_u32] = (UINT16)p_index;
                GFX_MGR02_SET_FLAG(l_dimage_elem_changed_flag_U8A,fl_prop_index_u32);
            }
        }
        else
        {
            /* passed dynamic image is not valid */
            fl_return_result = GUI_GFX_MGR_INVALID_DIMG_ELEM_ID;
        }
    }
    else
    {
        /* passed object type is invalid for this interface return error */
        fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_select_dimage() */

#endif /* #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0 */

#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_clut()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   Sets the CLUT index for the requested element.
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Elem ID 
**                   p_clut_id ==> clut index 
** Critical Section: None
** Created:          17-Aug-2012 by VMUTHUSU
** Updated:          05-Nov-2012 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_clut(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_clut_id)
{

    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;
    if(((UINT32)p_elem_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
    {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);
        if(fl_obj_type == GFX_MGR02_TYPE_SIMAGE) 
        {
      #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
        if (fl_prop_index < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
        {
            if(l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index].clut != p_clut_id)
            {
                l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index].clut = (UINT16)p_clut_id;
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index);
            }
        }
        else
        {
             fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
             GFX_MGR02_UNUSED_VAR(p_clut_id);
        }
      #else
          GFX_MGR02_UNUSED_VAR(fl_prop_index);
      #endif
        }
    #if defined(GFX_MGR02_KEPLER)
        else if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
        {
      #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
        if(fl_prop_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
        {
            if(l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index].clut != p_clut_id)
            {
                l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index].clut = (UINT16)p_clut_id;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index);
            }			
      
        }
        else
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
            GFX_MGR02_UNUSED_VAR(p_clut_id);
        }
      #else
          GFX_MGR02_UNUSED_VAR(fl_prop_index);
      #endif
        }
        else
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
            GFX_MGR02_UNUSED_VAR(p_clut_id);
        }
    #endif
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        GFX_MGR02_UNUSED_VAR(p_clut_id);
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
#endif /* (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) */

/*=============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_alpha
** Visibility:       global
** Description:      Sets the alpha for the requested element.
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and alpha value in p_alpha
** Critical Section: None.
** Created:          19-Apr-2011 by EMANOJ1
** Updated:          16-Aug-2012 by ASHEKHAR
**===========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_alpha(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ALPHA p_alpha)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0       
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
       
            if(l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index_u32].alpha  = p_alpha;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))
        {
            if(l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) */
    #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
           if(l_gfx_mgr02_anim_data_S.user_prop[fl_prop_index_u32].alpha != p_alpha)
           {
                l_gfx_mgr02_anim_data_S.user_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
           }
        }
        else
    #endif /* #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0) */
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0   /* Coverity ID#10047 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
       
            if(l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0  /* Coverity ID#10047 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
       
            if(l_gfx_mgr02_anim_data_S.tile_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.tile_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0  /* Coverity ID#10047 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
        
            if(l_gfx_mgr02_anim_data_S.fill_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.fill_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        
        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            if(l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].alpha != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].alpha = p_alpha;
                GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
        if(((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) || (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) ||
            (fl_obj_type == GFX_MGR02_TYPE_SCREEN)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
        {
        
            if(l_gfx_mgr02_anim_data_S.group_alpha[fl_prop_index_u32] != p_alpha)
            {
                l_gfx_mgr02_anim_data_S.group_alpha[fl_prop_index_u32] = p_alpha;
                GFX_MGR02_SET_FLAG(l_group_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || \
    (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) || \
    (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || \
    ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_area
** Visibility:       global
** Description:      Sets the clipping property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_clip
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IAREA_DATA const * p_area)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
#endif

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id) && (fl_obj_type == GFX_MGR02_TYPE_SWIDGET) 	&& (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
    {
       /* 
       ** Clipping is applicable only for widgets, if image or text needs any clipping
       ** animation the element shall be placed inside the widget and 
       ** perform the clipping animations.
       */
      #if defined(GFX_MGR02_CLIPPED_WIDGETS)
         #if defined(GFX_MGR02_KEPLER)
        if((GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32) != p_area->height) ||
           (GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32) != p_area->y))
        {
            GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(p_area->height,fl_prop_index_u32);
            GFX_MGR02_SET_CLIP_WIDGET_Y_COORD(p_area->y,fl_prop_index_u32);
            GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        }
        if((GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32) != p_area->x) ||
           (GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32) != p_area->width))
        {
              GFX_MGR02_SET_CLIP_WIDGET_WIDTH(p_area->width,fl_prop_index_u32);
              GFX_MGR02_SET_CLIP_WIDGET_X_COORD(p_area->x,fl_prop_index_u32);
              GFX_MGR02_SET_FLAG(l_wdg_anim_dcu_changed_flag_U8A, fl_prop_index_u32);
        }
     #else
        GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_widget_danim_prop_SP = &l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index_u32];
        if((fl_widget_danim_prop_SP->clip.height != p_area->height) ||
           (fl_widget_danim_prop_SP->clip.y      != p_area->y) ||
           (fl_widget_danim_prop_SP->clip.x      != p_area->x) ||
           (fl_widget_danim_prop_SP->clip.width  != p_area->width))
        {
            fl_widget_danim_prop_SP->clip.height  = p_area->height;
            fl_widget_danim_prop_SP->clip.width   = p_area->width;
            fl_widget_danim_prop_SP->clip.x       = p_area->x;
            fl_widget_danim_prop_SP->clip.y       = p_area->y;
            GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        }
     #endif
    #endif
    }
    else
#endif		
    {
    #if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0)
        GFX_MGR02_IDIM_DATA fl_dim;
        fl_dim.width  = p_area->width;
        fl_dim.height = p_area->height;
        fl_return_result = hmi_gfx_mgr02_layout_set_obj_dim(p_elem_id, (GFX_MGR02_IDIM_DATA const *)&fl_dim);
        if(fl_return_result == GUI_GFX_MGR_NO_ERROR)
        {
           GFX_MGR02_ILOC_DATA fl_pos;
           fl_pos.x = p_area->x;
           fl_pos.y = p_area->y;
           fl_return_result =  hmi_gfx_mgr02_layout_set_obj_pos(p_elem_id, (GFX_MGR02_ILOC_DATA const *)&fl_pos);
        }
    #endif
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_area
** Visibility:       global
** Description:      Sets the clipping property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_area
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IAREA_DATA * p_area)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
#endif

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id) && (fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
    {
       /* 
       ** Clipping is applicable only for widgets, if image or text needs any clipping
       ** animation the element shall be placed inside the widget and 
       ** perform the clipping animations.
       */
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
       p_area->height = GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32);
       p_area->width  = GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32);
       p_area->x      = GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32);
       p_area->y      = GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32);
    #endif
    }
    else
#endif
    {
    #if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0)
        GFX_MGR02_IDIM_DATA fl_dim;
        fl_return_result = hmi_gfx_mgr02_layout_get_obj_dim(p_elem_id, &fl_dim);
        if(fl_return_result == GUI_GFX_MGR_NO_ERROR)
        {
           GFX_MGR02_ILOC_DATA fl_pos;
           fl_return_result =  hmi_gfx_mgr02_layout_get_obj_pos(p_elem_id, &fl_pos);
           if(fl_return_result == GUI_GFX_MGR_NO_ERROR)
           {
              p_area->width  = fl_dim.width;
              p_area->height = fl_dim.height;
              p_area->x      = fl_pos.x;
              p_area->y      = fl_pos.y;
           }
        }
    #endif
    }
    return (fl_return_result);
}

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_vclip
** Visibility:       global
** Description:      Sets the vertical clipping property for the requested
**                   element. Property can be set only if the element is having
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_clip
** Critical Section: None.
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_vclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_VCLIP_DATA const * p_clip)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;
    UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id) && (fl_obj_type == GFX_MGR02_TYPE_SWIDGET) &&
       (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
    {
        SINT32                          fl_sy;
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        UINT16 base_id = hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->base_id;
    #else
        UINT16 base_id = lc_widget_anim_property_S[fl_prop_index_u32].base_id;
    #endif
        
        if (base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
        {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            UINT8 fl_clip_mode =hmi_gfx_mgr02_get_swidget_layer_def_ptr(base_id)->clip_mode;
        #else
            UINT8 fl_clip_mode =(UINT8)lc_swidget_layer_def_S[base_id].clip_mode;
        #endif
            
            if(fl_clip_mode != GFX_MGR02_WP_CLIP_NONE)
            {
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                UINT16 clip_index = hmi_gfx_mgr02_get_swidget_clip_idx(base_id);
                GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr(clip_index);
            #else
                GFX_MGR02_VISIBLE_AREA const*  fl_elem_offset_ptr = GFX_MGR02_NULL_PTR;
                UINT16 clip_index = lc_swidget_layer_def_S[base_id].clip_index;
                if( clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
                {
                   fl_elem_offset_ptr=&lc_elem_area_offset_SA[clip_index];
                }
            #endif
                if(fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
                {
                   fl_sy  = fl_elem_offset_ptr->sy;
                   fl_sy += (SINT32)p_clip->start_line;

                   if((GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index_u32) != p_clip->num_lines) ||
                     (GFX_MGR02_GET_CLIP_WIDGET_Y_COORD(fl_prop_index_u32) != fl_sy))
                   {
                     GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(p_clip->num_lines,fl_prop_index_u32);
                     GFX_MGR02_SET_CLIP_WIDGET_Y_COORD((SINT16)fl_sy,fl_prop_index_u32);
                     GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
                   }
                }
                
            }
        }
        else 
        {
            fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
        }
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
 #if !defined(GFX_MGR02_KEPLER)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_hclip
** Visibility:       global
** Description:      Sets the horizontal clipping property for the requested
**                   element. Property can be set only if the element is having
**                   a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and clip property in p_clip
** Critical Section: None.
** Critical Section: None.
** Created:          05-Apr-2016 by SBOLLAM
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_hclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_HCLIP_DATA const * p_clip)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;
    UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id) && (fl_obj_type == GFX_MGR02_TYPE_SWIDGET) &&
       (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
    {
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        UINT16 base_id = hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_prop_index_u32)->base_id;
    #else
        UINT16 base_id = lc_widget_anim_property_S[fl_prop_index_u32].base_id;
    #endif
        
        if (base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
        {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            UINT8 fl_clip_mode =hmi_gfx_mgr02_get_swidget_layer_def_ptr(base_id)->clip_mode;
        #else
            UINT8 fl_clip_mode =(UINT8)lc_swidget_layer_def_S[base_id].clip_mode;
        #endif 
     
            if (fl_clip_mode != GFX_MGR02_WP_CLIP_NONE)
            {
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                UINT16 clip_index = hmi_gfx_mgr02_get_swidget_clip_idx(base_id);
                GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr(clip_index);
            #else
                GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr = GFX_MGR02_NULL_PTR;
                UINT16 clip_index = lc_swidget_layer_def_S[base_id].clip_index;
                if( clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
                {
                   fl_elem_offset_ptr=&lc_elem_area_offset_SA[clip_index];
                }
            #endif
               if(fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
               {
                   SINT16 sx = fl_elem_offset_ptr->sx;
                   sx += p_clip->start_column;
 
                   if((GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index_u32) != p_clip->num_columns) ||
                   (GFX_MGR02_GET_CLIP_WIDGET_X_COORD(fl_prop_index_u32) != sx))
                   {
                    GFX_MGR02_SET_CLIP_WIDGET_WIDTH(p_clip->num_columns, fl_prop_index_u32);
                    GFX_MGR02_SET_CLIP_WIDGET_X_COORD(sx, fl_prop_index_u32);
                    GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
                   }
               }                
            }
        }
        else
        {
            fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
        }
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
 #endif
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_dim
** Visibility:       global
** Description:      Sets the Width and Height configuration for the requested element.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and tile parameters in p_tile
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA const * p_dim)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;
    if(((UINT32)p_elem_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
    {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10048 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
        
            if((GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index) != p_dim->height) ||
                GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index) != p_dim->width)
            {
                GFX_MGR02_SET_TILE_ANIM_HEIGHT(p_dim->height,fl_prop_index);
                GFX_MGR02_SET_TILE_ANIM_WIDTH(p_dim->width,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A,fl_prop_index);
            }
       
        }
        else 
    #endif
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10048 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
        
            if((GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index) != p_dim->height) ||
                (GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index) != p_dim->width))
            {
                GFX_MGR02_SET_FILL_ANIM_HEIGHT(p_dim->height,fl_prop_index);
                GFX_MGR02_SET_FILL_ANIM_WIDTH(p_dim->width,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A,fl_prop_index);
            }
        
        }
        else 
    #endif
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
        {
        #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            GFX_MGR02_WIDGET_DYN_PROPERTY * fl_swdg_elem_prop_SP = &l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index];
         #if defined(GFX_MGR02_KEPLER)
            if(GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index) != p_dim->height)
            {
                GFX_MGR02_SET_CLIP_WIDGET_HEIGHT(p_dim->height,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index);
            }
            if(GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index) != p_dim->width)
            {
                GFX_MGR02_SET_CLIP_WIDGET_WIDTH(p_dim->width,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_wdg_anim_dcu_changed_flag_U8A, fl_prop_index);
            }
         #else
            if((fl_swdg_elem_prop_SP->clip.height != p_dim->height) ||
                (fl_swdg_elem_prop_SP->clip.width != p_dim->width))
            {
                fl_swdg_elem_prop_SP->clip.height = p_dim->height;
                fl_swdg_elem_prop_SP->clip.width  = p_dim->width;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index);
            }
         #endif
        #endif
        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
        }
    }
    else
    {
        fl_return_result   = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_dim
** Visibility:       global
** Description:      Sets the Width and Height configuration for the requested element.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and tile parameters in p_tile
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA * p_dim)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result   = GUI_GFX_MGR_NO_ERROR;

    if((p_dim != (GFX_MGR02_IDIM_DATA *)0) && (((UINT32)p_elem_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY))
    {
        UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0  /* Coverity #10051 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
            p_dim->height = GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index);
            p_dim->width  = GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index);
        }
        else 
    #endif
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10051 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
            p_dim->height = GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index);
            p_dim->width  = GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index);
        }
        else 
    #endif
    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
        {
        #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            p_dim->height = GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index);
            p_dim->width  = GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index);
        #endif
        }
        else
    #endif    
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
        }
    }
    else
    {
        fl_return_result   = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_dim_w()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_data_mode ==> Data mode to be set  
** Critical Section: None
** Created:          15-Aug-2012 by ASHEKHAR
** Updated:          15-Aug-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim_w(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_w)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;
    if(((UINT32)p_elem_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
    {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10067 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index < ((UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)))
        {
        
             if(GFX_MGR02_GET_TILE_ANIM_WIDTH(fl_prop_index) != p_dim_w)
            {
                GFX_MGR02_SET_TILE_ANIM_WIDTH(p_dim_w,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A,fl_prop_index);
            }
        
        }
        else 
    #endif
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10067 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index < ((UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)))
        {
       
             if(GFX_MGR02_GET_FILL_ANIM_WIDTH(fl_prop_index) != p_dim_w)
            {
                GFX_MGR02_SET_FILL_ANIM_WIDTH(p_dim_w,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index);
            }
      
        }
        else 
    #endif
    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
        {
        #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            GFX_MGR02_WIDGET_DYN_PROPERTY * fl_swdg_elem_prop_SP = &l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index];
         #if defined(GFX_MGR02_KEPLER)
            if(GFX_MGR02_GET_CLIP_WIDGET_WIDTH(fl_prop_index) != p_dim_w)
            {
                GFX_MGR02_SET_CLIP_WIDGET_WIDTH(p_dim_w,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_wdg_anim_dcu_changed_flag_U8A, fl_prop_index);
            }
         #else
            if(fl_swdg_elem_prop_SP->clip.width != p_dim_w)
            {
                fl_swdg_elem_prop_SP->clip.width  = (UINT16)p_dim_w;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index);
            }
         #endif
        #endif
        }
        else
    #endif
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT))&& (fl_prop_index < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
          GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index];
          if((fl_text_dyn_prop_SP->width != p_dim_w) && (p_dim_w <=(UINT32)GFX_MGR02_LAYERS_MAX_WIDTH))
          {
            fl_text_dyn_prop_SP->width = (GFX_MGR02_ISIZE_W_T)p_dim_w;
            #if defined(GFX_MGR02_KEPLER)
            GFX_MGR02_SET_FLAG(l_text_anim_dcu_changed_flag_U8A, fl_prop_index);
            #else
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index);
            {
              #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
              #ifdef  GFX_MGR02_DLAYOUT_ENABLED
              GFX_MGR02_TEXT_DEF_T    const* fl_text_layer_prop_SP = hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index);
              #else
              GFX_MGR02_TEXT_PROPERTY const* fl_text_canim_prop_SP = &lc_text_anim_property_S[fl_prop_index];
              GFX_MGR02_TEXT_DEF_T    const* fl_text_layer_prop_SP = GFX_MGR02_NULL_PTR;
              if (fl_text_canim_prop_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
              {
                fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
              }
              #endif
              if (fl_text_layer_prop_SP != GFX_MGR02_NULL_PTR)
              {
                if ((fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1) &&
                (fl_text_layer_prop_SP->dynamic != (UINT8)0))
                {
                  hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_prop_SP, TRUE);
                }
              }
              else
              {
                fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
              }
              #endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
              GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_index))->base_id);
#else
              GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, lc_text_anim_property_S[fl_prop_index].base_id);
#endif
#endif
#endif
            }
            #endif
          }
        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
        }
    }
    else
    {
        fl_return_result   = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_dim_h()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_data_mode ==> Data mode to be set  
** Critical Section: None
** Created:          15-Aug-2012 by ASHEKHAR
** Updated:          15-Aug-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim_h(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_h)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result   = GUI_GFX_MGR_NO_ERROR;

    if(((UINT32)p_elem_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
    {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity Issue 10043 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
          if(GFX_MGR02_GET_OBJ_PLATFORM_TYPE((p_elem_id)) != GFX_MGR02_PLATFORM_OVG)
          {
            if(GFX_MGR02_GET_TILE_ANIM_HEIGHT(fl_prop_index) != p_dim_h)
            {
              GFX_MGR02_SET_TILE_ANIM_HEIGHT(p_dim_h,fl_prop_index);
              GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A,fl_prop_index);
            }
          }
       
        }
        else 
    #endif
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity Issue 10043 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
          if(GFX_MGR02_GET_OBJ_PLATFORM_TYPE((p_elem_id)) != GFX_MGR02_PLATFORM_OVG)
          {       
            if(GFX_MGR02_GET_FILL_ANIM_HEIGHT(fl_prop_index) != p_dim_h)
            {
                GFX_MGR02_SET_FILL_ANIM_HEIGHT(p_dim_h,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index);
            }
          }
        }
        else 
    #endif
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS) /* Coverity Issue 10043 */
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))
        {
          if(GFX_MGR02_GET_OBJ_PLATFORM_TYPE((p_elem_id)) != GFX_MGR02_PLATFORM_OVG)
          {       
            if(GFX_MGR02_GET_CLIP_WIDGET_HEIGHT(fl_prop_index) != p_dim_h)
            {
                GFX_MGR02_SET_CLIP_WIDGET_HEIGHT((UINT16)p_dim_h,fl_prop_index);
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index);
            }
          }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
      #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) && 
        (fl_prop_index < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
          #ifdef  GFX_MGR02_DLAYOUT_ENABLED
          GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = hmi_gfx_mgr02_get_text_layer_ptr(fl_prop_index);
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
          UINT16 fl_base_id = (hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_idx))->base_id;
#endif
#endif
          #else
          GFX_MGR02_TEXT_PROPERTY const * fl_text_canim_prop_SP = &lc_text_anim_property_S[fl_prop_index];
          GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = GFX_MGR02_NULL_PTR;
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
          UINT16 fl_base_id = fl_text_canim_prop_SP->base_id;
#endif
#endif
          if(fl_text_canim_prop_SP->base_id < GFX_MGR02_NUM_OF_TEXT_LAYERS)
          {
            fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
          }
          #endif
          /* Only when the GDT designed text is a multi line text then display lines can be changed */
          if(fl_text_layer_prop_SP != GFX_MGR02_NULL_PTR)
          {
            if((fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1) &&
              (p_dim_h <= fl_text_layer_prop_SP->max_num_of_lines))
            {
              if(l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index].num_of_display_lines != p_dim_h)
              {
                l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index].num_of_display_lines = (UINT8)p_dim_h;
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index);
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#if defined(GFX_MGR02_RUN_ML_ALG_FROM_PRESN) 
                if ((fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1) &&
                  (fl_text_layer_prop_SP->dynamic != (UINT8)0))
                {
                  BOOLEAN fl_is_multiline_data_modified = hmi_gfx_mgr02_get_multiline_data_modified(fl_text_layer_prop_SP);
                  if (fl_is_multiline_data_modified == (BOOLEAN)FALSE)
                  {
                    hmi_gfx_mgr02_layout_run_multiline_algorithm(fl_text_layer_prop_SP, FALSE, TRUE);
                  }
                }
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                GFX_MGR02_SET_FLAG(l_text_shaping_required_flag_U8A, fl_base_id);
#endif
#endif
#endif
              }
            }
          }
          else
          {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
          }
        }
        else
      #endif
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_OBJ_TYPE;
        }
    }
    else
    {
        fl_return_result   = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
#endif /* (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) */

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_draw_color
** Visibility:       global
** Description:      Sets the foreground color for the requested element. Color
**                   can be set only if the element type is other than
**                   GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET AND if the
**                   element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and color in p_color
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_draw_color(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_color)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP) 
  if(p_color > GFX_MGR02_PIX_MAX_COLOR)
  {
    fl_return_result = GUI_GFX_MGR_INVALID_ATTRIB;
  }
else
#endif
{
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
            #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
            if(l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index_u32].fg_color != p_color)
            {
                l_gfx_mgr02_anim_data_S.widget_prop[fl_prop_index_u32].fg_color = p_color;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
            #endif
        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))
        {
             if(l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index_u32].fg_color != p_color)
             {
                l_gfx_mgr02_anim_data_S.image_prop[fl_prop_index_u32].fg_color = p_color;
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
             }
        }
        else
    #endif /* #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) */
    #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
            if(l_gfx_mgr02_anim_data_S.user_prop[fl_prop_index_u32].fg_color != p_color)
            {
                l_gfx_mgr02_anim_data_S.user_prop[fl_prop_index_u32].fg_color = p_color;
                GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 /* Coverity #10053 */
        if(((fl_obj_type == GFX_MGR02_TYPE_DTEXT) || (fl_obj_type == GFX_MGR02_TYPE_STEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
            if(l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].color != p_color)
            {
                l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32].color = p_color;
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10053 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
            if(l_gfx_mgr02_anim_data_S.fill_prop[fl_prop_index_u32].color != p_color)
            {
                l_gfx_mgr02_anim_data_S.fill_prop[fl_prop_index_u32].color = p_color;
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return (fl_return_result);
}
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pos_x
** Visibility:       global
** Description:      Sets the x coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x property in p_pos_x
** Critical Section: None.
** Created:          05-Nov-2011 by ASHEKHAR
** Updated:          05-Nov-2011 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
        SINT16   fl_offset_pos_x = p_pos_x;
        UINT32   fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32   fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
         #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_SWIDGET_X_COORD(fl_prop_index_u32);
         #endif
            if(GFX_MGR02_GET_SWIDGET_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_SWIDGET_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
                fl_offset_pos_x += GFX_MGR02_GET_ORIG_SIMAGE_X_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_SIMAGE_X_COORD(fl_prop_index_u32) !=fl_offset_pos_x)
            {
                GFX_MGR02_SET_SIMAGE_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if	(GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
             #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
                fl_offset_pos_x += GFX_MGR02_GET_ORIG_USER_ANIM_X_COORD(fl_prop_index_u32);
             #endif
             if(GFX_MGR02_GET_USER_ANIM_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
             {
                 GFX_MGR02_SET_USER_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                 GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
             }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) /* Coverity #10049 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS) && (lc_text_anim_property_S[fl_prop_index_u32].base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
              /*Calculate the x position by adding the passed offset based on the alignment*/
                        
              if(GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32) == GFX_MGR02_TP_ALIGN_CENTRE)
              {
                  fl_offset_pos_x += (GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32)- (GFX_MGR02_GET_ANIM_ELEM_TEXT_WIDTH(fl_prop_index_u32)/2));
              }
              else if(GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32) == GFX_MGR02_TP_ALIGN_RIGHT)
              {
                  fl_offset_pos_x += (GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32) - GFX_MGR02_GET_ANIM_ELEM_TEXT_WIDTH(fl_prop_index_u32));
              }
              else
              {
                  fl_offset_pos_x += GFX_MGR02_GET_ORIG_TEXT_X_COORD(fl_prop_index_u32);    
              }
            #endif

            if(GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32) == GFX_MGR02_TP_ALIGN_CENTRE)
            {
                fl_offset_pos_x+= ((SINT16)GFX_MGR02_GET_ANIM_ELEM_TEXT_WIDTH(fl_prop_index_u32)/2);
            }
            else if(GFX_MGR02_GET_ORIG_TEXT_ALIGNMENT(fl_prop_index_u32) == GFX_MGR02_TP_ALIGN_RIGHT)
            {
                fl_offset_pos_x+= ((SINT16)GFX_MGR02_GET_ANIM_ELEM_TEXT_WIDTH(fl_prop_index_u32)-1);
            }
            else
            {
                /*To Fix MISRA warning.*/
            }    

            if(GFX_MGR02_GET_TEXT_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_TEXT_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_TILE_ANIM_X_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_TILE_ANIM_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_TILE_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_FILL_ANIM_X_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_FILL_ANIM_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_FILL_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        
        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_SVG_ANIM_X_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_SVG_ANIM_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_SVG_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
        if(((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) || (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) ||
            (fl_obj_type == GFX_MGR02_TYPE_SCREEN)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
        {
            /*
            ** Group animations are valid for Screens, dynamic widgets and dynamic images
            */
            if(GFX_MGR02_GET_GROUP_ANIM_X_COORD(fl_prop_index_u32) != fl_offset_pos_x)
            {
                GFX_MGR02_SET_GROUP_ANIM_X_COORD(fl_offset_pos_x,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_group_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pos_y
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
        SINT16 fl_offset_pos_y   = p_pos_y;
        UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
         #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SWIDGET_Y_COORD(fl_prop_index_u32);
         #endif
            if(GFX_MGR02_GET_SWIDGET_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_SWIDGET_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)) 
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SIMAGE_Y_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_SIMAGE_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_SIMAGE_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) */
    #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0  /* Coverity #10050 */
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
             #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
             fl_offset_pos_y += GFX_MGR02_GET_ORIG_USER_ANIM_Y_COORD(fl_prop_index_u32);
             #endif
             if(GFX_MGR02_GET_USER_ANIM_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
             {
                 GFX_MGR02_SET_USER_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                 GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
             }
        }
        else
    #endif /* #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0) */       
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 /* Coverity #10050 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
                (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {

            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_TEXT_Y_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_TEXT_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_TEXT_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10050 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {

            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_TILE_ANIM_Y_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_TILE_ANIM_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_TILE_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10050 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {

            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_FILL_ANIM_Y_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_FILL_ANIM_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_FILL_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SVG_ANIM_Y_COORD(fl_prop_index_u32);
            #endif
            if(GFX_MGR02_GET_SVG_ANIM_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_SVG_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
        if(((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) || (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) ||
            (fl_obj_type == GFX_MGR02_TYPE_SCREEN)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
        {
            /*
            ** Group animations are valid for Screens, dynamic widgets and dynamic images
            */
            if(GFX_MGR02_GET_GROUP_ANIM_Y_COORD(fl_prop_index_u32) != fl_offset_pos_y)
            {
                GFX_MGR02_SET_GROUP_ANIM_Y_COORD(fl_offset_pos_y,fl_prop_index_u32);
                GFX_MGR02_SET_FLAG(l_group_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pos
** Visibility:       global
** Description:      Sets the x, y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id,GFX_MGR02_ILOC_DATA const * p_pos)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result;
    if((p_pos != GFX_MGR02_NULL_PTR) && (GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id)))
    {
        fl_return_result = hmi_gfx_mgr02_layout_set_obj_pos_x(p_elem_id, p_pos->x);
        if(fl_return_result == (GUI_GFX_MGR_ERROR_CODE_T)GUI_GFX_MGR_NO_ERROR)
        {
           fl_return_result = hmi_gfx_mgr02_layout_set_obj_pos_y(p_elem_id, p_pos->y);
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pos_y
** Visibility:       global
** Description:      Sets the y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and y property in p_pos_y
** Critical Section: None.
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA * p_pos)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
            p_pos->x = GFX_MGR02_GET_SWIDGET_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_SWIDGET_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)) 
        {
            p_pos->x = GFX_MGR02_GET_SIMAGE_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_SIMAGE_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif
    #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
            p_pos->x = GFX_MGR02_GET_USER_ANIM_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_USER_ANIM_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif /* #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0) */
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0  /* Coverity #10052 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
            p_pos->x = GFX_MGR02_GET_TEXT_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_TEXT_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10052 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
            p_pos->x = GFX_MGR02_GET_TILE_ANIM_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_TILE_ANIM_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10052 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
            p_pos->x = GFX_MGR02_GET_FILL_ANIM_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_FILL_ANIM_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
        if(((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) || (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) ||
            (fl_obj_type == GFX_MGR02_TYPE_SCREEN)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
        {

            p_pos->x = GFX_MGR02_GET_GROUP_ANIM_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_GROUP_ANIM_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            p_pos->x = GFX_MGR02_GET_SVG_ANIM_X_COORD(fl_prop_index_u32);
            p_pos->y = GFX_MGR02_GET_SVG_ANIM_Y_COORD(fl_prop_index_u32);
        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_default_properties()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   
**                   
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_default_properties(GFX_MGR02_ANIM_ELEM_ID p_elem_id)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result = GUI_GFX_MGR_NO_ERROR;
   UINT32 fl_obj_type                         = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
   UINT32 fl_prop_index_U32                   = GFX_MGR02_GET_OBJ_ID(p_elem_id);
   UINT32 fl_platform_type                    = GFX_MGR02_GET_OBJ_PLATFORM_TYPE(p_elem_id);

   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
   #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
      if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
      {
         if(hmi_gfx_mgr02_layout_reset_widget_anim_prop(fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif
   #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
      if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)) 
      {
         if(hmi_gfx_mgr02_layout_reset_image_anim_prop(fl_obj_type, fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif /* #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) */
   #if (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0) /* Coverity Issue 10042 */
   if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
   {
         if(hmi_gfx_mgr02_layout_reset_image_anim_prop(fl_obj_type, fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_U32);
         }
   }
   else
   #endif
   #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
      if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
         (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
      {
         if(hmi_gfx_mgr02_layout_reset_text_anim_prop(fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif
   #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
      if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
      {
         if(hmi_gfx_mgr02_layout_reset_tile_anim_prop(fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif
   #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
      if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
      {
         if(hmi_gfx_mgr02_layout_reset_fill_anim_prop(fl_prop_index_U32, fl_platform_type) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
   #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
      if(((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) || (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) ||
         (fl_obj_type == GFX_MGR02_TYPE_SCREEN)) &&
         (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
      {
         /*
         ** Group animations are valid for Screens, dynamic widgets and dynamic images
         */
         if(hmi_gfx_mgr02_layout_reset_group_anim(fl_prop_index_U32) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_group_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
   #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
      if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_U32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
      {
         if(hmi_gfx_mgr02_layout_reset_svg_anim(fl_prop_index_U32) != (UINT32)FALSE)
         {
            GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_U32);
         }
      }
      else
   #endif
      {
         fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
      }
   }
   else
   {
      fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return (fl_return_result);
}/* End of hmi_gfx_mgr02_layout_set_obj_default_properties() */

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pivot_x
** Visibility:       global
** Description:      Sets the pivot x coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x property in p_pos_x
** Critical Section: None.
** Created:          15-Mar-2018 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pivot_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
        SINT16   fl_offset_pos_x = p_pos_x;
        UINT32       fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
          #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_SWIDGET_PIVOT_X(fl_prop_index_u32);
          #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_prop_index_u32].pivot.x = (GFX_FLOAT)fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))
        {
         #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_SIMAGE_PIVOT_X(fl_prop_index_u32);
         #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_prop_index_u32].pivot.x = (GFX_FLOAT)fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
    #if	(GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
          #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
             fl_offset_pos_x += GFX_MGR02_GET_ORIG_USER_ANIM_PIVOT_X(fl_prop_index_u32);
          #endif
             if(fabsf(l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x)>FLT_EPSILON )
             {
                 l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_prop_index_u32].pivot.x = fl_offset_pos_x;
                 GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
             }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) /* Coverity #10049 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_TEXT_ANIM_PIVOT_X(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_prop_index_u32].pivot.x = (GFX_FLOAT)fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_TILE_ANIM_PIVOT_X(fl_prop_index_u32);
            #endif
            if(l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_prop_index_u32].pivot.x != fl_offset_pos_x)
            {
                l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_prop_index_u32].pivot.x = fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_FILL_ANIM_PIVOT_X(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_prop_index_u32].pivot.x = (GFX_FLOAT)fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_x += GFX_MGR02_GET_ORIG_SVG_ANIM_PIVOT_X(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].pivot.x - (GFX_FLOAT)fl_offset_pos_x)>FLT_EPSILON )
            {
                l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].pivot.x = (GFX_FLOAT)fl_offset_pos_x;
                GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_obj_pivot_y
** Visibility:       global
** Description:      Sets the pivot y coordinate property for the requested
**                   element. Property can be set only if the element type is
**                   other than GFX_MGR02_TYPE_DIMAGE or GFX_MGR02_TYPE_DWIDGET
**                   AND if the element is having a dynamic property enabled.
** Invocation:       By presentation layer or the graphics interface layer
** Inputs/Outputs:   element ID in p_elem_id and x property in p_pos_x
** Critical Section: None.
** Created:          15-Mar-2018 by CSAKTHIV
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pivot_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y)
{
    GUI_GFX_MGR_ERROR_CODE_T         fl_return_result = GUI_GFX_MGR_NO_ERROR;
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
    {
        SINT16   fl_offset_pos_y = p_pos_y;
        UINT32       fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
        UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
        {
         #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SWIDGET_PIVOT_Y(fl_prop_index_u32);
         #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_prop_index_u32].pivot.y - (GFX_FLOAT)fl_offset_pos_y) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_prop_index_u32].pivot.y = (GFX_FLOAT)fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))
        {
         #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SIMAGE_PIVOT_Y(fl_prop_index_u32);
         #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_prop_index_u32].pivot.y - (GFX_FLOAT)fl_offset_pos_y) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_prop_index_u32].pivot.y = (GFX_FLOAT)fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
    #if	(GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
        if((fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS))
        {
          #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
             fl_offset_pos_y += GFX_MGR02_GET_ORIG_USER_ANIM_PIVOT_Y(fl_prop_index_u32);
          #endif
             if(fabsf(l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_prop_index_u32].pivot.y - fl_offset_pos_y) > FLT_EPSILON)
             {
                 l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_prop_index_u32].pivot.y = fl_offset_pos_y;
                 GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_prop_index_u32);
             }
        }
        else
    #endif
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) /* Coverity #10049 */
        if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_TEXT_ANIM_PIVOT_Y(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_prop_index_u32].pivot.y - (GFX_FLOAT)fl_offset_pos_y) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_prop_index_u32].pivot.y = (GFX_FLOAT)fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_TILE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_TILE_ANIM_PIVOT_Y(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_prop_index_u32].pivot.y - fl_offset_pos_y) >FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_prop_index_u32].pivot.y = fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        
        }
        else
    #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 /* Coverity #10049 */
        if((fl_obj_type == GFX_MGR02_TYPE_FILL) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS))
        {
        
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_FILL_ANIM_PIVOT_Y(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_prop_index_u32].pivot.y - (GFX_FLOAT)fl_offset_pos_y) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_prop_index_u32].pivot.y =(GFX_FLOAT)fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }
        }
        else
    #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
    #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
        if((fl_obj_type == GFX_MGR02_TYPE_SVG) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS))
        {
            #if defined(GFX_MGR02_SET_ANIM_OFFSET_POSITION)
            fl_offset_pos_y += GFX_MGR02_GET_ORIG_SVG_ANIM_PIVOT_Y(fl_prop_index_u32);
            #endif
            if(fabsf(l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].pivot.y - (GFX_FLOAT)fl_offset_pos_y) > FLT_EPSILON)
            {
                l_gfx_mgr02_anim_data_S.svg_prop[fl_prop_index_u32].pivot.y = (GFX_FLOAT)fl_offset_pos_y;
                GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
            }

        }
        else
    #endif
        {
            fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
        }
    }
    else
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return (fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_matrix_copy()
** Visibility:       global
** Description:      Copies the source matrix to destination matrix and also 
                     checks for any changes .
                     TODO:implement a nearest comparison for float rather than
                     exact values.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns TRUE if the source and destination are different.
** Critical Section: None
** Created:          02-Jul-2013 by EMANOJ1
** Updated:          02-Jul-2013 by EMANOJ1
**==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_matrix_copy(GFX_FLOAT * p_dst, GFX_FLOAT const * p_src)
{
   UINT32 fl_changed = (UINT32)FALSE;
   if(fabsf(p_dst[0] - p_src[0]) > FLT_EPSILON)
   {
      p_dst[0]   = p_src[0];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[1] - p_src[1]) > FLT_EPSILON)
   {
      p_dst[1]   = p_src[1];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[2] - p_src[2]) > FLT_EPSILON)
   {
      p_dst[2]   = p_src[2];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[3] - p_src[3]) > FLT_EPSILON)
   {
      p_dst[3]   = p_src[3];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[4] - p_src[4]) > FLT_EPSILON)
   {
      p_dst[4]   = p_src[4];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[5] - p_src[5]) > FLT_EPSILON)
   {
      p_dst[5]   = p_src[5];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[6] - p_src[6]) > FLT_EPSILON)
   {
      p_dst[6]   = p_src[6];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[7] - p_src[7]) > FLT_EPSILON)
   {
      p_dst[7]   = p_src[7];
      fl_changed = (UINT32)TRUE;
   }
   if(fabsf(p_dst[8] - p_src[8]) > FLT_EPSILON)
   {
      p_dst[8]   = p_src[8];
      fl_changed = (UINT32)TRUE;
   }
   return(fl_changed);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_transformation()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix)
{
    UINT32 fl_obj_type  = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_obj_id    = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_NO_ERROR;

    if((GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)||GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id) && (p_matrix != GFX_MGR02_NULL_PTR))
    {
       switch(fl_obj_type)
       {
       case GFX_MGR02_TYPE_SWIDGET:
       {
       #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
            #if defined(GFX_MGR02_KEPLER)
             GFX_MGR02_SET_FLAG(l_wdg_anim_dcu_changed_flag_U8A, fl_obj_id);
            #else
             GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_obj_id);
            #endif
           }
         }
       #endif
       }
       break;
       case GFX_MGR02_TYPE_SIMAGE:
       {
       #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
              GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_obj_id);
           }
         }
       #endif
       }
       break;
       case GFX_MGR02_TYPE_USER_LAYER:
       {
   #if GFX_MGR02_NUM_USER_LAYERS > 0
   #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
              GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_obj_id);
           }
         }
   #endif
   #endif
       }
       break;
       case GFX_MGR02_TYPE_STEXT:
       case GFX_MGR02_TYPE_DTEXT:
       {
   #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
             GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_obj_id);
           }
         }
   #endif
       }
       break;
       case GFX_MGR02_TYPE_TILE:
       {
   #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix))
           {
             GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_obj_id);
           }
         }
   #endif
       }
       break;
       case GFX_MGR02_TYPE_FILL:
       {
   #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
              GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_obj_id);
           }
         }
   #endif
       }
       break;
       case GFX_MGR02_TYPE_SVG:
       {
   #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
         if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
         {
           GFX_FLOAT * fl_matrix = &l_gfx_mgr02_anim_data_S.svg_prop[fl_obj_id].matrix[0];
           if(hmi_gfx_mgr02_layout_matrix_copy(fl_matrix, p_matrix) != (UINT32)0)
           {
              GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_obj_id);
           }
         }
   #endif
       }
       break;
       default:
       {
           /*For fixing MISRA warning.*/
       }
       break;
       }
    }
    else
    {
       fl_return_result = GUI_GFX_MGR_INVALID_TARGET;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_transformation()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_mul_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result;
   if((GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)||GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
       GFX_FLOAT * fl_matrix = hmi_gfx_mgr02_layout_get_obj_transformation(p_elem_id);
       if(fl_matrix != GFX_MGR02_NULL_PTR)
       {
          hmi_gfx_mgr02_context_mul_matrix(fl_matrix, p_matrix);
          hmi_gfx_mgr02_layout_set_matrix_anim_flags(p_elem_id);
          fl_return_result = GUI_GFX_MGR_NO_ERROR;
       }
       else
       {
          fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
       }
   }
   else
   {
       fl_return_result = GUI_GFX_MGR_INVALID_TARGET;
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return(fl_return_result);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_scale()
** Visibility:       global
** Description:      Invokes the corresponding interface based on the Objects
**                   target type.
**                   
**                   
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_scale(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_scalex, GFX_FLOAT p_scaley)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result = GUI_GFX_MGR_NO_ERROR;
   GFX_FLOAT * fl_matrix; 
   if((GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)||GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
       fl_matrix = hmi_gfx_mgr02_layout_get_obj_transformation(p_elem_id);
       if(fl_matrix != GFX_MGR02_NULL_PTR)
       {
          if((fabsf(fl_matrix[0] - p_scalex) > FLT_EPSILON) || (fabsf(fl_matrix[4] - p_scaley) > FLT_EPSILON))
          {
            fl_matrix[0] = p_scalex;
            fl_matrix[4] = p_scaley;
            hmi_gfx_mgr02_layout_set_matrix_anim_flags(p_elem_id);
          }
       }
       else
       {
           fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
       }
   }
   else
   {
       fl_return_result = GUI_GFX_MGR_INVALID_TARGET;
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return(fl_return_result);
}

#if defined(GFX_MGR02_MATRIX_MULTI_ROTATE) 
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_rotate()
** Visibility:       global
** Description:      Invokes the when rotate to be done along with previous matrix
**                   value. GMHud is using this. If required , app should
**                   define this in hmi_gfx_mgr02.cfg
**
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_rotate(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_angle)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result = GUI_GFX_MGR_NO_ERROR;
   GFX_FLOAT * fl_dst_matrix;
   GFX_FLOAT fl_src_matrix[9];
   if((GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)||GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
       fl_dst_matrix = hmi_gfx_mgr02_layout_get_obj_transformation(p_elem_id);
       if(fl_dst_matrix != GFX_MGR02_NULL_PTR)
       {
          fl_src_matrix[0] = cosf(p_angle);
          fl_src_matrix[1] = sinf(p_angle);
          fl_src_matrix[2] = 0;

          fl_src_matrix[3] = -fl_src_matrix[1];
          fl_src_matrix[4] = fl_src_matrix[0];
          fl_src_matrix[5] = 0;

          fl_src_matrix[6] = 0;
          fl_src_matrix[7] = 0;
          fl_src_matrix[8] = 1;
          hmi_gfx_mgr02_context_mul_matrix(fl_dst_matrix,fl_src_matrix);
          hmi_gfx_mgr02_layout_set_matrix_anim_flags(p_elem_id);
       }
       else
       {
           fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
       }
   }
   else
   {
       fl_return_result = GUI_GFX_MGR_INVALID_TARGET;
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return(fl_return_result);

}
#else
/*============================================================================
** Function Name:    hmi_gfx_mgr02_set_obj_rotate()
** Visibility:       global
** Description:      Invokes the when rotate to be done without previous matrix
**                   value. 
**                   
** Invocation:       By Presentation layer
** Inputs/Outputs:   Returns the ErrorCode. Look into GUI_GFX_MGR_ERROR_CODE_T
**                   various error code values available.
**                   p_elem_id ==> Anim Element id to be resetted
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/

GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_rotate(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_angle)
{
   GUI_GFX_MGR_ERROR_CODE_T  fl_return_result = GUI_GFX_MGR_NO_ERROR;
   GFX_FLOAT * fl_matrix; 
   if((GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)||GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
       fl_matrix = hmi_gfx_mgr02_layout_get_obj_transformation(p_elem_id);
       if(fl_matrix != GFX_MGR02_NULL_PTR)
       {
          GFX_FLOAT fl_cos_angle = cosf(p_angle);
          GFX_FLOAT fl_sin_angle = sinf(p_angle);
          if((fabsf(fl_matrix[0] - fl_cos_angle) > FLT_EPSILON) || (fabsf(fl_matrix[1] - fl_sin_angle) > FLT_EPSILON))
          {
              fl_matrix[0] = fl_cos_angle;
              fl_matrix[1] = fl_sin_angle;
              fl_matrix[3] = -fl_matrix[1];
              fl_matrix[4] = fl_matrix[0];
              hmi_gfx_mgr02_layout_set_matrix_anim_flags(p_elem_id);
          }
       }
       else
       {
           fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
       }
   }
   else
   {
       fl_return_result = GUI_GFX_MGR_INVALID_TARGET;
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return(fl_return_result);
}
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_def_obj_transformation()
** Visibility:       global
** Description:      fetches the matrix index for the requested element ID.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Element Id, Returns the Pointer to the Matrix of the element.
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
GFX_FLOAT const * hmi_gfx_mgr02_layout_get_def_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id)
{
  GFX_FLOAT const * fl_matrix = GFX_MGR02_NULL_PTR;
  UINT32 fl_obj_type        = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  UINT32 fl_obj_id          = GFX_MGR02_GET_OBJ_ID(p_elem_id);

  if((GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)||GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    switch(fl_obj_type)
    {
    case GFX_MGR02_TYPE_SWIDGET:
      #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix = &(hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_widget_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    case GFX_MGR02_TYPE_SIMAGE:
      #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix = &(hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_img_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    case GFX_MGR02_TYPE_USER_LAYER:
      #if GFX_MGR02_NUM_USER_LAYERS > 0
      #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix = &(hmi_gfx_mgr02_get_user_img_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_user_img_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      #endif
      break;
    case GFX_MGR02_TYPE_STEXT:
    case GFX_MGR02_TYPE_DTEXT:
      #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix = &(hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_text_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    case GFX_MGR02_TYPE_TILE:
      #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix =&(hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_tile_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    case GFX_MGR02_TYPE_FILL:
      #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix =&(hmi_gfx_mgr02_get_fill_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_fill_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    case GFX_MGR02_TYPE_SVG:
      #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_matrix = &(hmi_gfx_mgr02_get_svg_anim_prop_ptr(fl_obj_id)->matrix[0]);
        #else
        fl_matrix = &lc_svg_anim_property_S[fl_obj_id].matrix[0];
        #endif
      }
      #endif
      break;
    default:
    {
         /*For fixing MISRA warning.*/
    }
      break;
    }
  }
  return(fl_matrix);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_get_obj_transformation()
** Visibility:       global
** Description:      fetches the matrix index for the requested element ID.
** Invocation:       By Presentation layer
** Inputs/Outputs:   Element Id, Returns the Pointer to the Matrix of the element.
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
GFX_FLOAT * hmi_gfx_mgr02_layout_get_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id)
{
  GFX_FLOAT * fl_matrix = GFX_MGR02_NULL_PTR;
  UINT32 fl_obj_type         = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  UINT32 fl_obj_id           = GFX_MGR02_GET_OBJ_ID(p_elem_id);

  if((GFX_MGR02_IS_PLATFORM_OVG(p_elem_id)||GFX_MGR02_IS_PLATFORM_FUJITSU(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER(p_elem_id)||GFX_MGR02_IS_PLATFORM_AMBER_IRIS(p_elem_id)||GFX_MGR02_IS_PLATFORM_TRAVEO2(p_elem_id)||GFX_MGR02_IS_PLATFORM_VGLITE(p_elem_id)) && GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
  {
    switch(fl_obj_type)
    {
    case GFX_MGR02_TYPE_SWIDGET:
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.widget_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    case GFX_MGR02_TYPE_SIMAGE:
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.image_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    case GFX_MGR02_TYPE_USER_LAYER:
#if GFX_MGR02_NUM_USER_LAYERS > 0
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.user_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
#endif
      break;
    case GFX_MGR02_TYPE_STEXT:
    case GFX_MGR02_TYPE_DTEXT:
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.text_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    case GFX_MGR02_TYPE_TILE:
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.tile_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    case GFX_MGR02_TYPE_FILL:
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.fill_ovg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    case GFX_MGR02_TYPE_SVG:
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
      if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
      {
        fl_matrix = &l_gfx_mgr02_anim_data_S.svg_prop[fl_obj_id].matrix[0];
      }
#endif
      break;
    default:
    {
         /*For fixing MISRA warning.*/
    }
      break;
    }
  }
  return(fl_matrix);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_matrix_anim_flags()
** Visibility:       global
** Description:      Sets the anim element flags for matrix animations for the requested element ID.
** Invocation:       By matrix animation interfaces
** Inputs/Outputs:   Element Id, Returns void.
** Critical Section: None
** Created:          10-Dec-2012 by ASHEKHAR
** Updated:          10-Dec-2012 by ASHEKHAR
**==========================================================================*/
static void hmi_gfx_mgr02_layout_set_matrix_anim_flags(GFX_MGR02_ANIM_ELEM_ID p_elem_id)
{
  UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_id);
  UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
  switch (fl_obj_type)
  {
  case GFX_MGR02_TYPE_SWIDGET:
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
    {
#if defined(GFX_MGR02_KEPLER)
      GFX_MGR02_SET_FLAG(l_wdg_anim_dcu_changed_flag_U8A, fl_obj_id);
#else
      GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_obj_id);
#endif
    }
#endif
    break;
  case GFX_MGR02_TYPE_SIMAGE:
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
    break;
  case GFX_MGR02_TYPE_USER_LAYER:
#if GFX_MGR02_NUM_USER_LAYERS > 0
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_user_image_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
#endif
    break;
  case GFX_MGR02_TYPE_STEXT:
  case GFX_MGR02_TYPE_DTEXT:
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
    break;
  case GFX_MGR02_TYPE_TILE:
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_tile_anim_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
    break;
  case GFX_MGR02_TYPE_FILL:
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_fill_anim_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
    break;
  case GFX_MGR02_TYPE_SVG:
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    if (fl_obj_id < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
    {
      GFX_MGR02_SET_FLAG(l_svg_anim_elem_changed_flag_U8A, fl_obj_id);
    }
#endif
    break;
  default:
  {
    /*For fixing MISRA warning.*/
  }
  break;
  }
}
#endif

/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_anim_flags
** Visibility:       local
** Description:      resets animation change status indication, dynamic element
**                   change status flags.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static void hmi_gfx_mgr02_layout_reset_anim_flags(void)
{

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_fill_anim_elem_changed_flag_U8A[0], 0, sizeof(l_fill_anim_elem_changed_flag_U8A));
#endif  /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_tile_anim_elem_changed_flag_U8A[0], 0, sizeof(l_tile_anim_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_text_anim_elem_changed_flag_U8A[0], 0, sizeof(l_text_anim_elem_changed_flag_U8A));  
 #if defined(GFX_MGR02_KEPLER)
    (void)memset((void *)&l_text_anim_dcu_changed_flag_U8A[0], 0, sizeof(l_text_anim_dcu_changed_flag_U8A));
 #endif
#endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    (void)memset((void*)&l_text_shaping_required_flag_U8A[0], 0, sizeof(l_text_shaping_required_flag_U8A));
#endif
#endif
#endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
    
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_wdg_anim_elem_changed_flag_U8A[0], 0, sizeof(l_wdg_anim_elem_changed_flag_U8A));
  #if defined(GFX_MGR02_KEPLER)
    (void)memset((void *)&l_wdg_anim_dcu_changed_flag_U8A[0], 0, sizeof(l_wdg_anim_dcu_changed_flag_U8A));
  #endif
#endif /* #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_img_anim_elem_changed_flag_U8A[0], 0, sizeof(l_img_anim_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_group_anim_elem_changed_flag_U8A[0], 0, sizeof(l_group_anim_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_USER_LAYERS > 0
  #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    (void)memset((void *)&l_user_image_elem_changed_flag_U8A[0], 0, sizeof(l_user_image_elem_changed_flag_U8A));
  #endif /* #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0 */
#endif /* #if GFX_MGR02_NUM_USER_LAYERS > 0 */

#if GFX_MGR02_NUM_OF_DTEXTS > 0
      (void)memset((void *)&l_dtext_elem_changed_flag_U8A[0], 0, sizeof(l_dtext_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_OF_DTEXTS > 0 */

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
     (void)memset((void *)&l_dwidget_elem_changed_flag_U8A[0], 0, sizeof(l_dwidget_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0 */

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
     (void)memset((void *)&l_dimage_elem_changed_flag_U8A[0], 0, sizeof(l_dimage_elem_changed_flag_U8A));
#endif /* #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0 */

#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
     (void)memset((void *)&l_svg_anim_elem_changed_flag_U8A[0], 0, sizeof(l_svg_anim_elem_changed_flag_U8A));
#endif
     (void)memset((void *)&l_screen_changed_flag_U8A[0], 0, sizeof(l_screen_changed_flag_U8A));

#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
     (void)memset((void *)&l_font_elem_changed_flag_U8A[0], 0, sizeof(l_font_elem_changed_flag_U8A));
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  l_dlayout_changed_flag_bool=FALSE;
#endif
}

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_widget_anim_prop
** Visibility:       local
** Description:      resets widget animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_widget_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id)
{
    UINT32 fl_changed = (UINT32)FALSE;
    if(p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
    {
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
       GFX_MGR02_WIDGET_PROPERTY const * fl_widget_canim_prop_SP = hmi_gfx_mgr02_get_widget_anim_prop_ptr(p_prop_index_U32);
    #else
       GFX_MGR02_WIDGET_PROPERTY const * fl_widget_canim_prop_SP = &lc_widget_anim_property_S[p_prop_index_U32];
    #endif
       if (fl_widget_canim_prop_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
       {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
           GFX_MGR02_WIDGET_DEF_T    const * fl_widget_layer_prop_SP = hmi_gfx_mgr02_get_swidget_layer_def_ptr(fl_widget_canim_prop_SP->base_id);
        #else
           GFX_MGR02_WIDGET_DEF_T    const * fl_widget_layer_prop_SP = &lc_swidget_layer_def_S[fl_widget_canim_prop_SP->base_id];
        #endif
        
           GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_widget_danim_prop_SP = &l_gfx_mgr02_anim_data_S.widget_prop[p_prop_index_U32];
           
        #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
          #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
          #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
          GFX_MGR02_IMAGE_DEF_T const * fl_image_layer_prop_SP;
          if (fl_widget_layer_prop_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
          {
              fl_image_layer_prop_SP            = &lc_image_layer_def_S[fl_widget_layer_prop_SP->image_id];
              if(fl_widget_danim_prop_SP->clut != fl_image_layer_prop_SP->clut)
              {
                 fl_widget_danim_prop_SP->clut = fl_image_layer_prop_SP->clut;
                 fl_changed = (UINT32)TRUE;
              }
          }
          #endif
          #endif
          #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
          if(fl_widget_danim_prop_SP->fg_color != fl_widget_canim_prop_SP->fg_color)
          {
             fl_widget_danim_prop_SP->fg_color = fl_widget_canim_prop_SP->fg_color;
             fl_changed = (UINT32)TRUE;
          }
          #endif
          if(fl_widget_danim_prop_SP->coord.x != fl_widget_canim_prop_SP->coord.x)
          {
             fl_widget_danim_prop_SP->coord.x = fl_widget_canim_prop_SP->coord.x;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_widget_danim_prop_SP->coord.y != fl_widget_canim_prop_SP->coord.y)
          {
             fl_widget_danim_prop_SP->coord.y = fl_widget_canim_prop_SP->coord.y;
             fl_changed = (UINT32)TRUE;
          }
        #endif
          if(fl_widget_danim_prop_SP->alpha != fl_widget_canim_prop_SP->alpha)
          {
             fl_widget_danim_prop_SP->alpha = fl_widget_canim_prop_SP->alpha;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_widget_layer_prop_SP->clip_index == (UINT8)0)
          {
             if(fl_widget_danim_prop_SP->clip.height != (UINT16)0xFFFF)
             {
                fl_widget_danim_prop_SP->clip.height = (UINT16)0xFFFF;
                fl_changed = (UINT32)TRUE;
             }
             if(fl_widget_danim_prop_SP->clip.width != (UINT16)0xFFFF)
             {
                fl_widget_danim_prop_SP->clip.width = (UINT16)0xFFFF;
                fl_changed = (UINT32)TRUE;
             }
             if(fl_widget_danim_prop_SP->clip.x != 0)
             {
                fl_widget_danim_prop_SP->clip.x = 0;
                fl_changed = (UINT32)TRUE;
             }
             if(fl_widget_danim_prop_SP->clip.y != 0)
             {
                fl_widget_danim_prop_SP->clip.y = 0;
                fl_changed = (UINT32)TRUE;
             }
          }
          else
          {
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr(fl_widget_layer_prop_SP->clip_index);
            #else
              GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr = GFX_MGR02_NULL_PTR;
              if( fl_widget_layer_prop_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
              {
                fl_elem_offset_ptr=&lc_elem_area_offset_SA[fl_widget_layer_prop_SP->clip_index];
              }
            #endif
             if(fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
             {
               if(fl_widget_danim_prop_SP->clip.height != (UINT16)fl_elem_offset_ptr->ey)
               {
                fl_widget_danim_prop_SP->clip.height = (UINT16)fl_elem_offset_ptr->ey;
                fl_changed = (UINT32)TRUE;
               }
               if(fl_widget_danim_prop_SP->clip.width != (UINT16)fl_elem_offset_ptr->ex)
               {
                fl_widget_danim_prop_SP->clip.width = (UINT16)fl_elem_offset_ptr->ex;
                fl_changed = (UINT32)TRUE;
               }
               if(fl_widget_danim_prop_SP->clip.x != fl_elem_offset_ptr->sx)
               {
                fl_widget_danim_prop_SP->clip.x = fl_elem_offset_ptr->sx;
                fl_changed = (UINT32)TRUE;
               }
               if(fl_widget_danim_prop_SP->clip.y != fl_elem_offset_ptr->sy)
               {
                fl_widget_danim_prop_SP->clip.y = fl_elem_offset_ptr->sy;
                fl_changed = (UINT32)TRUE;
               }
             }             
          }
        #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
          if(hmi_gfx_mgr02_layout_matrix_copy((&l_gfx_mgr02_anim_data_S.widget_ovg_prop[p_prop_index_U32].matrix[0]),
                                              &fl_widget_canim_prop_SP->matrix[0]) != (UINT32)FALSE)
          {
             fl_changed = (UINT32)TRUE;
          }
          if(fabsf(l_gfx_mgr02_anim_data_S.widget_ovg_prop[p_prop_index_U32].pivot.x - fl_widget_canim_prop_SP->pivot.x) > FLT_EPSILON)
          {
             l_gfx_mgr02_anim_data_S.widget_ovg_prop[p_prop_index_U32].pivot.x = fl_widget_canim_prop_SP->pivot.x;
             fl_changed = (UINT32)TRUE;
          }
          if(fabsf(l_gfx_mgr02_anim_data_S.widget_ovg_prop[p_prop_index_U32].pivot.y - fl_widget_canim_prop_SP->pivot.y) > FLT_EPSILON)
          {
             l_gfx_mgr02_anim_data_S.widget_ovg_prop[p_prop_index_U32].pivot.y = fl_widget_canim_prop_SP->pivot.y;
             fl_changed = (UINT32)TRUE;
          }

        #endif
       }
    }
    GFX_MGR02_UNUSED_VAR(p_platform_id);
    return(fl_changed);
}
#endif

#if ((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0))
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_image_anim_prop
** Visibility:       local
** Description:      resets image animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          18-Mar-2013 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_image_anim_prop(UINT32 p_obj_type, UINT32 p_obj_index, UINT32 p_platform_id)
{
    GFX_MGR02_IMAGE_PROPERTY  const * fl_img_cprop_SP = NULL;
    GFX_MGR02_IMAGE_DEF_T     const * fl_img_base_SP = NULL;
    GFX_MGR02_IMAGE_DYN_PROPERTY    * fl_img_dynamic_anim_prop_SP = NULL; 
 #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY * fl_ovg_ext_prop_SP;
 #endif
    UINT32 fl_changed = (UINT32)FALSE;
 
    if(p_obj_type == GFX_MGR02_TYPE_SIMAGE)
    {
    #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 
        if (p_obj_index < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
        {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            fl_img_cprop_SP             = hmi_gfx_mgr02_get_image_anim_prop_ptr(p_obj_index);
        #else
            fl_img_cprop_SP             = &lc_img_anim_property_S[p_obj_index];
        #endif
            if (fl_img_cprop_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_img_base_SP              = hmi_gfx_mgr02_get_image_layer_def_ptr(fl_img_cprop_SP->base_id);
            #else
                fl_img_base_SP              = &lc_image_layer_def_S[fl_img_cprop_SP->base_id];
            #endif
            
                fl_img_dynamic_anim_prop_SP = &l_gfx_mgr02_anim_data_S.image_prop[p_obj_index];
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                fl_ovg_ext_prop_SP          = &l_gfx_mgr02_anim_data_S.image_ovg_prop[p_obj_index];
                if(hmi_gfx_mgr02_layout_matrix_copy((&fl_ovg_ext_prop_SP->matrix[0]),
                                                    &fl_img_cprop_SP->matrix[0]) != ((UINT32)FALSE))
                {
                   fl_changed = (UINT32)TRUE;
                }
                if(fabsf(fl_ovg_ext_prop_SP->pivot.x - fl_img_cprop_SP->pivot.x) > FLT_EPSILON)
                {
                   fl_ovg_ext_prop_SP->pivot.x = fl_img_cprop_SP->pivot.x;
                   fl_changed = (UINT32)TRUE;
                }
                if(fabsf(fl_ovg_ext_prop_SP->pivot.y - fl_img_cprop_SP->pivot.y) > FLT_EPSILON)
                {
                   fl_ovg_ext_prop_SP->pivot.y = fl_img_cprop_SP->pivot.y;
                   fl_changed = (UINT32)TRUE;
                }
            #endif
            }
        }
    #else
      fl_img_dynamic_anim_prop_SP = NULL; 
    #endif
    }
    else
    {
    #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
        if (p_obj_index < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
        {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            fl_img_cprop_SP             = hmi_gfx_mgr02_get_user_img_anim_prop_ptr(p_obj_index);
        #else
            fl_img_cprop_SP             = &lc_user_img_anim_property_S[p_obj_index];
        #endif
            if (fl_img_cprop_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
            {				
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_img_base_SP              = hmi_gfx_mgr02_get_user_img_layer_def_ptr(fl_img_cprop_SP->base_id);
            #else
                fl_img_base_SP              = &lc_user_image_layer_def_S[fl_img_cprop_SP->base_id];
            #endif
            
                fl_img_dynamic_anim_prop_SP = &l_gfx_mgr02_anim_data_S.user_prop[p_obj_index];
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                fl_ovg_ext_prop_SP          = &l_gfx_mgr02_anim_data_S.user_ovg_prop[p_obj_index];
                if(hmi_gfx_mgr02_layout_matrix_copy((&fl_ovg_ext_prop_SP->matrix[0]),
                                                    &fl_img_cprop_SP->matrix[0]) != ((UINT32)FALSE))
                {
                   fl_changed = (UINT32)TRUE;
                }
                if(fabsf(fl_ovg_ext_prop_SP->pivot.x - fl_img_cprop_SP->pivot.x) > FLT_EPSILON)
                {
                   fl_ovg_ext_prop_SP->pivot.x = fl_img_cprop_SP->pivot.x;
                   fl_changed = (UINT32)TRUE;
                }
                if(fabsf(fl_ovg_ext_prop_SP->pivot.y - fl_img_cprop_SP->pivot.y) > FLT_EPSILON)
                {
                   fl_ovg_ext_prop_SP->pivot.y = fl_img_cprop_SP->pivot.y;
                   fl_changed = (UINT32)TRUE;
                }
            #endif
            }
        }
    #else
      fl_img_dynamic_anim_prop_SP = NULL; 
    #endif
    }

    if(fl_img_dynamic_anim_prop_SP != NULL)
    {
      if(fl_img_dynamic_anim_prop_SP->alpha != fl_img_cprop_SP->alpha)
      {
         fl_img_dynamic_anim_prop_SP->alpha = fl_img_cprop_SP->alpha;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_img_dynamic_anim_prop_SP->clut != fl_img_base_SP->clut)
      {
         fl_img_dynamic_anim_prop_SP->clut = fl_img_base_SP->clut;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_img_dynamic_anim_prop_SP->fg_color != fl_img_cprop_SP->fg_color)
      {
         fl_img_dynamic_anim_prop_SP->fg_color = fl_img_cprop_SP->fg_color;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_img_dynamic_anim_prop_SP->coord.x != fl_img_cprop_SP->coord.x)
      {
         fl_img_dynamic_anim_prop_SP->coord.x = fl_img_cprop_SP->coord.x;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_img_dynamic_anim_prop_SP->coord.y != fl_img_cprop_SP->coord.y)
      {
         fl_img_dynamic_anim_prop_SP->coord.y = fl_img_cprop_SP->coord.y;
         fl_changed = (UINT32)TRUE;
      }
    }
    
    GFX_MGR02_UNUSED_VAR(p_platform_id);

    return(fl_changed);
}
#endif  /*((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0))*/

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_text_anim_prop
** Visibility:       local
** Description:      resets text animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_text_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id)
{
   UINT32 fl_changed = (UINT32)FALSE;
   if(p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
   {
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TEXT_PROPERTY const * fl_text_canim_prop_SP = hmi_gfx_mgr02_get_txt_anim_prop_ptr(p_prop_index_U32);
      {
          GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP =  hmi_gfx_mgr02_get_text_layer_ptr(p_prop_index_U32);
    #else
      GFX_MGR02_TEXT_PROPERTY const * fl_text_canim_prop_SP = &lc_text_anim_property_S[p_prop_index_U32];
      if (fl_text_canim_prop_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
      {
          GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
    #endif
          GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_danim_prop_SP   = &l_gfx_mgr02_anim_data_S.text_prop[p_prop_index_U32];

          if(fl_text_danim_prop_SP->alignment != fl_text_layer_prop_SP->alignment)
          {
             fl_text_danim_prop_SP->alignment = fl_text_layer_prop_SP->alignment;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->alpha != fl_text_canim_prop_SP->alpha)
          {
             fl_text_danim_prop_SP->alpha = fl_text_canim_prop_SP->alpha;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->clip_mode != fl_text_layer_prop_SP->clip_mode)
          {
             fl_text_danim_prop_SP->clip_mode = fl_text_layer_prop_SP->clip_mode;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->color != fl_text_canim_prop_SP->color)
          {
             fl_text_danim_prop_SP->color = fl_text_canim_prop_SP->color;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->coord.x != fl_text_canim_prop_SP->coord.x)
          {
             fl_text_danim_prop_SP->coord.x = fl_text_canim_prop_SP->coord.x;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->coord.y != fl_text_canim_prop_SP->coord.y)
          {
             fl_text_danim_prop_SP->coord.y = fl_text_canim_prop_SP->coord.y;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->draw_mode != fl_text_layer_prop_SP->draw_mode)
          {
             fl_text_danim_prop_SP->draw_mode = fl_text_layer_prop_SP->draw_mode;
             fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->font_id != fl_text_layer_prop_SP->font_id)
          {
             fl_text_danim_prop_SP->font_id = fl_text_layer_prop_SP->font_id;
             fl_changed = (UINT32)TRUE;
          }
    #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
          {
            UINT32 fl_font_id;
            fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_text_layer_prop_SP->font_id);
            if (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
            {
                if (fl_text_danim_prop_SP->font_pt_size != (UINT8)lc_gfx_font_table[fl_font_id].height_pts)
                {
                    fl_text_danim_prop_SP->font_pt_size = (UINT8)lc_gfx_font_table[fl_font_id].height_pts;
                    fl_changed = TRUE;
                }
            }
          }
    #endif
          if(fl_text_danim_prop_SP->scroll_offset != 0.0)
          {
             fl_text_danim_prop_SP->scroll_offset = (GFX_FLOAT)0.0;
             fl_changed = (UINT32)TRUE;
          }
		  #if ((defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS))&& defined(GFX_MGR02_CLIP_TEXT_ENABLE))
          if(fl_text_danim_prop_SP->max_shrink != fl_text_canim_prop_SP->max_shrink)
          {
             fl_text_danim_prop_SP->max_shrink = fl_text_canim_prop_SP->max_shrink;
             fl_changed = (UINT32)TRUE;
          }
		  #endif
          if(fl_text_danim_prop_SP->width != fl_text_layer_prop_SP->width)
          {
             fl_text_danim_prop_SP->width = fl_text_layer_prop_SP->width;
             fl_changed = (UINT32)TRUE;
          }      
       #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
          if(fl_text_danim_prop_SP->num_of_display_lines != fl_text_layer_prop_SP->num_of_display_lines)
          {
            fl_text_danim_prop_SP->num_of_display_lines = fl_text_layer_prop_SP->num_of_display_lines;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->inter_line_spacing != fl_text_layer_prop_SP->inter_line_spacing)
          {
            fl_text_danim_prop_SP->inter_line_spacing = fl_text_layer_prop_SP->inter_line_spacing;
            fl_changed = (UINT32)TRUE;
          }
       #endif
       
       #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
          if(fl_text_danim_prop_SP->txt_special_effects.effect_type != DEFAULT_TXT_INVALID_EFFECT)
          {
            fl_text_danim_prop_SP->txt_special_effects.effect_type = DEFAULT_TXT_INVALID_EFFECT;
            fl_changed = (UINT32)TRUE;
          }
          #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          if(fl_text_danim_prop_SP->txt_special_effects.bold_percentage != DEFAULT_TXT_BOLD_PERCENTAGE)
          {
            fl_text_danim_prop_SP->txt_special_effects.bold_percentage = DEFAULT_TXT_BOLD_PERCENTAGE;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->txt_special_effects.otl_width != DEFAULT_TXT_OTL_WIDTH)
          {
            fl_text_danim_prop_SP->txt_special_effects.otl_width = DEFAULT_TXT_OTL_WIDTH;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->txt_special_effects.otl_opacity != DEFAULT_TXT_OTL_OPACITY)
          {
            fl_text_danim_prop_SP->txt_special_effects.otl_opacity = DEFAULT_TXT_OTL_OPACITY;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->txt_special_effects.shadow_bg_col != DEFAULT_TXT_SHADOW_COLOR)
          {
            fl_text_danim_prop_SP->txt_special_effects.shadow_bg_col = DEFAULT_TXT_SHADOW_COLOR;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->txt_special_effects.shadow_x != DEFAULT_TXT_SHADOW_X)
          {
            fl_text_danim_prop_SP->txt_special_effects.shadow_x = DEFAULT_TXT_SHADOW_X;
            fl_changed = (UINT32)TRUE;
          }
          if(fl_text_danim_prop_SP->txt_special_effects.shadow_y != DEFAULT_TXT_SHADOW_Y)
          {
            fl_text_danim_prop_SP->txt_special_effects.shadow_y = DEFAULT_TXT_SHADOW_Y;
            fl_changed = (UINT32)TRUE;
          }
          #endif
       #endif  /* #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) */

       #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined (GFX_MGR02_VGLITE)
          if((p_platform_id == GFX_MGR02_PLATFORM_IMXRT) || (p_platform_id == GFX_MGR02_PLATFORM_OVG)||(p_platform_id == GFX_MGR02_PLATFORM_FJT)||(p_platform_id == GFX_MGR02_PLATFORM_ABR)||(p_platform_id == GFX_MGR02_PLATFORM_IRS)||(p_platform_id == GFX_MGR02_PLATFORM_TRAVEO2))
          {
             if(hmi_gfx_mgr02_layout_matrix_copy((&l_gfx_mgr02_anim_data_S.text_ovg_prop[p_prop_index_U32].matrix[0]),
                                                 &fl_text_canim_prop_SP->matrix[0]) != (UINT32)FALSE)
             {
                fl_changed = TRUE;
             }
             if(fabsf(l_gfx_mgr02_anim_data_S.text_ovg_prop[p_prop_index_U32].pivot.x - fl_text_canim_prop_SP->pivot.x) > FLT_EPSILON)
             {
                l_gfx_mgr02_anim_data_S.text_ovg_prop[p_prop_index_U32].pivot.x = fl_text_canim_prop_SP->pivot.x;
                fl_changed = (UINT32)TRUE;
             }
             if(fabsf(l_gfx_mgr02_anim_data_S.text_ovg_prop[p_prop_index_U32].pivot.y - fl_text_canim_prop_SP->pivot.y) > FLT_EPSILON)
             {
                l_gfx_mgr02_anim_data_S.text_ovg_prop[p_prop_index_U32].pivot.y = fl_text_canim_prop_SP->pivot.y;
                fl_changed = (UINT32)TRUE;
             }

          }
       #else
          GFX_MGR02_UNUSED_VAR(p_platform_id);
       #endif
      }
   }
   return(fl_changed);
}
#endif


#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_tile_anim_prop
** Visibility:       local
** Description:      resets tile animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_tile_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id)
{
   UINT32 fl_changed = (UINT32)FALSE;
   if(p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
   {
  #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      GFX_MGR02_TILE_PROPERTY const * fl_tile_canim_prop_SP = hmi_gfx_mgr02_get_tile_anim_prop_ptr(p_prop_index_U32);
      GFX_MGR02_TILE_DEF_T    const * fl_tile_layer_prop_SP = hmi_gfx_mgr02_get_tile_layer_def_ptr(fl_tile_canim_prop_SP->base_id);
  #else
      GFX_MGR02_TILE_PROPERTY const * fl_tile_canim_prop_SP = &lc_tile_anim_property_S[p_prop_index_U32];
      GFX_MGR02_TILE_DEF_T    const * fl_tile_layer_prop_SP = &lc_tile_layer_def_S[fl_tile_canim_prop_SP->base_id];
  #endif
      GFX_MGR02_TILE_DYN_PROPERTY  * fl_tile_danim_prop_SP = &l_gfx_mgr02_anim_data_S.tile_prop[p_prop_index_U32];
      
      if(fl_tile_danim_prop_SP->alpha != fl_tile_canim_prop_SP->alpha)
      {
         fl_tile_danim_prop_SP->alpha = fl_tile_canim_prop_SP->alpha;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_tile_danim_prop_SP->coord.x != fl_tile_canim_prop_SP->coord.x)
      {
         fl_tile_danim_prop_SP->coord.x = fl_tile_canim_prop_SP->coord.x;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_tile_danim_prop_SP->coord.y != fl_tile_canim_prop_SP->coord.y)
      {
         fl_tile_danim_prop_SP->coord.y = fl_tile_canim_prop_SP->coord.y;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_tile_danim_prop_SP->dim.width != fl_tile_layer_prop_SP->dim.width)
      {
         fl_tile_danim_prop_SP->dim.width = fl_tile_layer_prop_SP->dim.width;
         fl_changed = (UINT32)TRUE;
      }
      if(fl_tile_danim_prop_SP->dim.height != fl_tile_layer_prop_SP->dim.height)
      {
         fl_tile_danim_prop_SP->dim.height = fl_tile_layer_prop_SP->dim.height;
         fl_changed = (UINT32)TRUE;
      }
   #if defined(GFX_MGR02_OPEN_VG) ||  defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
      if((p_platform_id == GFX_MGR02_PLATFORM_OVG)||(p_platform_id == GFX_MGR02_PLATFORM_FJT)||(p_platform_id == GFX_MGR02_PLATFORM_ABR)||(p_platform_id == GFX_MGR02_PLATFORM_IRS)||(p_platform_id == GFX_MGR02_PLATFORM_TRAVEO2))
      {
         if(hmi_gfx_mgr02_layout_matrix_copy((&l_gfx_mgr02_anim_data_S.tile_ovg_prop[p_prop_index_U32].matrix[0]),
                                             &fl_tile_canim_prop_SP->matrix[0]) != (UINT32)FALSE)
         {
            fl_changed = (UINT32)TRUE;
         }
         if(fabsf(l_gfx_mgr02_anim_data_S.tile_ovg_prop[p_prop_index_U32].pivot.x - fl_tile_canim_prop_SP->pivot.x) > FLT_EPSILON)
         {
            l_gfx_mgr02_anim_data_S.tile_ovg_prop[p_prop_index_U32].pivot.x = fl_tile_canim_prop_SP->pivot.x;
            fl_changed = (UINT32)TRUE;
         }
         if(fabsf(l_gfx_mgr02_anim_data_S.tile_ovg_prop[p_prop_index_U32].pivot.y - fl_tile_canim_prop_SP->pivot.y) > FLT_EPSILON)
         {
            l_gfx_mgr02_anim_data_S.tile_ovg_prop[p_prop_index_U32].pivot.y = fl_tile_canim_prop_SP->pivot.y;
            fl_changed = (UINT32)TRUE;
         }

      }
   #else
      GFX_MGR02_UNUSED_VAR(p_platform_id);
   #endif
   }
   return(fl_changed);
}
#endif

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_fill_anim_prop
** Visibility:       local
** Description:      resets fill animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_fill_anim_prop(UINT32 p_prop_index_U32, UINT32 p_platform_id)
{
    UINT32 fl_changed = (UINT32)FALSE;
    if(p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
    {
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        GFX_MGR02_FILL_PROPERTY const * fl_fill_canim_prop_SP     = hmi_gfx_mgr02_get_fill_anim_prop_ptr(p_prop_index_U32);
    #else
        GFX_MGR02_FILL_PROPERTY const * fl_fill_canim_prop_SP     = &lc_fill_anim_property_S[p_prop_index_U32];
    #endif
        if (fl_fill_canim_prop_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS)
        {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            GFX_MGR02_FILL_DEF_T    const * fl_fill_base_SP           = hmi_gfx_mgr02_get_fill_layer_def_ptr(fl_fill_canim_prop_SP->base_id);
        #else
            GFX_MGR02_FILL_DEF_T    const * fl_fill_base_SP           = &lc_fill_layer_def_S[fl_fill_canim_prop_SP->base_id];
        #endif
       
            GFX_MGR02_FILL_DYN_PROPERTY  * fl_fill_danim_prop_SP = &l_gfx_mgr02_anim_data_S.fill_prop[p_prop_index_U32];
          
            if(fl_fill_danim_prop_SP->alpha != fl_fill_canim_prop_SP->alpha)
            {
                fl_fill_danim_prop_SP->alpha = fl_fill_canim_prop_SP->alpha;
                fl_changed = (UINT32)TRUE;
            }
            if(fl_fill_danim_prop_SP->color != fl_fill_base_SP->color)
            {
               fl_fill_danim_prop_SP->color = fl_fill_base_SP->color;
               fl_changed = (UINT32)TRUE;
            }
            if(fl_fill_danim_prop_SP->coord.x != fl_fill_canim_prop_SP->coord.x)
            {
               fl_fill_danim_prop_SP->coord.x = fl_fill_canim_prop_SP->coord.x;
               fl_changed = (UINT32)TRUE;
            }
            if(fl_fill_danim_prop_SP->coord.y != fl_fill_canim_prop_SP->coord.y)
            {
               fl_fill_danim_prop_SP->coord.y = fl_fill_canim_prop_SP->coord.y;
               fl_changed = (UINT32)TRUE;
            }
            if(fl_fill_danim_prop_SP->dim.width != fl_fill_base_SP->dim.width)
            {
               fl_fill_danim_prop_SP->dim.width = fl_fill_base_SP->dim.width;
               fl_changed = (UINT32)TRUE;
            }
            if(fl_fill_danim_prop_SP->dim.height != fl_fill_base_SP->dim.height)
            {
               fl_fill_danim_prop_SP->dim.height = fl_fill_base_SP->dim.height;
               fl_changed = (UINT32)TRUE;
            }
        #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
            if((p_platform_id == GFX_MGR02_PLATFORM_IMXRT) || (p_platform_id == GFX_MGR02_PLATFORM_OVG) || (p_platform_id == GFX_MGR02_PLATFORM_FJT)||(p_platform_id == GFX_MGR02_PLATFORM_ABR)||(p_platform_id == GFX_MGR02_PLATFORM_IRS)||(p_platform_id == GFX_MGR02_PLATFORM_TRAVEO2))
            {
              if(hmi_gfx_mgr02_layout_matrix_copy((&l_gfx_mgr02_anim_data_S.fill_ovg_prop[p_prop_index_U32].matrix[0]),
                                                 &fl_fill_canim_prop_SP->matrix[0]) != (UINT32)FALSE)
              {
                fl_changed = (UINT32)TRUE;
              }
              if(fabsf(l_gfx_mgr02_anim_data_S.fill_ovg_prop[p_prop_index_U32].pivot.x - fl_fill_canim_prop_SP->pivot.x) > FLT_EPSILON)
              {
                l_gfx_mgr02_anim_data_S.fill_ovg_prop[p_prop_index_U32].pivot.x = fl_fill_canim_prop_SP->pivot.x;
                fl_changed = (UINT32)TRUE;
              }
              if(fabsf(l_gfx_mgr02_anim_data_S.fill_ovg_prop[p_prop_index_U32].pivot.y - fl_fill_canim_prop_SP->pivot.y) > FLT_EPSILON)
              {
                l_gfx_mgr02_anim_data_S.fill_ovg_prop[p_prop_index_U32].pivot.y = fl_fill_canim_prop_SP->pivot.y;
                fl_changed = (UINT32)TRUE;
              }
            }
        #else
          GFX_MGR02_UNUSED_VAR(p_platform_id);
        #endif /* #if defined(GFX_MGR02_OPEN_VG) */
       }
    }
   return(fl_changed);
}
#endif

#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_group_anim
** Visibility:       local
** Description:      resets group animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_group_anim(UINT32 p_prop_index_U32)
{
   UINT32 fl_changed = (UINT32)FALSE;
   if(p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS)
   {
      if(l_gfx_mgr02_anim_data_S.group_alpha[p_prop_index_U32] != (GFX_MGR02_ALPHA)255)
      {
         l_gfx_mgr02_anim_data_S.group_alpha[p_prop_index_U32] = (GFX_MGR02_ALPHA)255;
         fl_changed = (UINT32)TRUE;
      }
      if(l_gfx_mgr02_anim_data_S.group_loc[p_prop_index_U32].x != 0)
      {
         l_gfx_mgr02_anim_data_S.group_loc[p_prop_index_U32].x = 0;
         fl_changed = (UINT32)TRUE;
      }
      if(l_gfx_mgr02_anim_data_S.group_loc[p_prop_index_U32].y != 0)
      {
         l_gfx_mgr02_anim_data_S.group_loc[p_prop_index_U32].y = 0;
         fl_changed = (UINT32)TRUE;
      }
   }
   return(fl_changed);
}
#endif

#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_reset_svg_anim
** Visibility:       local
** Description:      resets SVG animation elements to its default position.
** Invocation:       Called by graphics layout manager
** Inputs/Outputs:   None
** Critical Section: None
** Created:          05-Nov-2012 by ASHEKHAR
** Updated:          05-Nov-2012 by ASHEKHAR
**==========================================================================*/
static UINT32 hmi_gfx_mgr02_layout_reset_svg_anim(UINT32 p_prop_index_U32)
{
    UINT32 fl_changed = (UINT32)FALSE;
    if (p_prop_index_U32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
    {
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        GFX_MGR02_OVG_PROPERTY const * fl_ovg_property_SP  = hmi_gfx_mgr02_get_svg_anim_prop_ptr(p_prop_index_U32);
    #else
        GFX_MGR02_OVG_PROPERTY const * fl_ovg_property_SP  = &lc_svg_anim_property_S[p_prop_index_U32];
    #endif
        GFX_MGR02_OVG_DYN_PROPERTY   * fl_ovg_anim_prop_SP = &l_gfx_mgr02_anim_data_S.svg_prop[p_prop_index_U32];

        if(fl_ovg_anim_prop_SP->alpha != fl_ovg_property_SP->alpha)
        {
            fl_ovg_anim_prop_SP->alpha = fl_ovg_property_SP->alpha;
            fl_changed = (UINT32)TRUE;
        }
        if(fl_ovg_anim_prop_SP->coord.x != fl_ovg_property_SP->coord.x)
        {
            fl_ovg_anim_prop_SP->coord.x = fl_ovg_property_SP->coord.x;
            fl_changed = (UINT32)TRUE;
        }
        if(fl_ovg_anim_prop_SP->coord.y != fl_ovg_property_SP->coord.y)
        {
            fl_ovg_anim_prop_SP->coord.y = fl_ovg_property_SP->coord.y;
            fl_changed = (UINT32)TRUE;
        }
        if(hmi_gfx_mgr02_layout_matrix_copy((fl_ovg_anim_prop_SP->matrix),
                                           (GFX_FLOAT const *)fl_ovg_property_SP->matrix) != (UINT32)FALSE)
        {
            fl_changed = (UINT32)TRUE;
        }
        if(fabsf(l_gfx_mgr02_anim_data_S.svg_prop[p_prop_index_U32].pivot.x - fl_ovg_property_SP->pivot.x) > FLT_EPSILON)
        {
            l_gfx_mgr02_anim_data_S.svg_prop[p_prop_index_U32].pivot.x = fl_ovg_property_SP->pivot.x;
            fl_changed = (UINT32)TRUE;
        }
        if(fabsf(l_gfx_mgr02_anim_data_S.svg_prop[p_prop_index_U32].pivot.y - fl_ovg_property_SP->pivot.y) > FLT_EPSILON)
        {
            l_gfx_mgr02_anim_data_S.svg_prop[p_prop_index_U32].pivot.y = fl_ovg_property_SP->pivot.y;
            fl_changed = (UINT32)TRUE;
        }
    }
    return(fl_changed);
}

#endif

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_push_touch_event
Description          : This function pushes button events to the queue.
Invocation           : By application.
Parameters           : Pointer to GFX_MGR02_TOUCH_QDATA.
Return Value         : None.
Critical Section     : None.
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_layout_push_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP, UINT8 p_touch_id)
{
   if((p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS)&&(l_touch_data[p_touch_id].l_tcount_U32 < GFX_MGR02_TOUCH_EVENT_Q_SIZE))
   {
      GFX_MGR02_TOUCH_QDATA * fl_touch_data_SP;
      UINT32                  fl_twrite_U32 = l_touch_data[p_touch_id].l_twrite_index_U32;

      fl_touch_data_SP = &l_touch_data[p_touch_id].l_touch_event_queue_S[fl_twrite_U32];
      memcpy(fl_touch_data_SP, p_touch_data_SP, sizeof(GFX_MGR02_TOUCH_QDATA));
      fl_twrite_U32++;
      if(fl_twrite_U32 >= GFX_MGR02_TOUCH_EVENT_Q_SIZE)
      {
         fl_twrite_U32 = 0;
      }
      l_touch_data[p_touch_id].l_twrite_index_U32 = fl_twrite_U32;
      GFX_MGR02_ENTER_CS(l_tcritical_section);
      l_touch_data[p_touch_id].l_tcount_U32++;
      GFX_MGR02_LEAVE_CS(l_tcritical_section);
   }
#ifdef GFX02_DEBUG_LAYOUT
   else
   {
      gfx_debug("hmi_gfx_mgr02_layout_push_touch_event Q FULL Error\n");
   }
#endif  
   GFX_MGR02_VERIFY_LAYOUT_API_CALL 
}

/****************************************************************************
Function Name        : GfxManagerPopTouchEvent
Description          : This function pops button events from the queue.
Invocation           : By GfxManagerProcessTouchEvents.
Parameters           : Pointer to GFX_TOUCH_QDATA where the touch event will be
                       written.
Return Value         : Returns zero if there are no events in queue
                       If the p_touch_data_SP is updated with an event returns
                       non zero.
Critical Section     : None.
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_layout_pop_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP,UINT8 p_touch_id)
{
   UINT32 fl_sts_U32;

   if((p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS)&&(l_touch_data[p_touch_id].l_tcount_U32 > 0) && (p_touch_data_SP != 0))
   {
      GFX_MGR02_TOUCH_QDATA * fl_touch_data_SP;
      UINT32  fl_tread_U32  = l_touch_data[p_touch_id].l_tread_index_U32;
      fl_touch_data_SP = &l_touch_data[p_touch_id].l_touch_event_queue_S[fl_tread_U32];
      memcpy(p_touch_data_SP, fl_touch_data_SP, sizeof(GFX_MGR02_TOUCH_QDATA));
      fl_tread_U32++;
      if(fl_tread_U32 >= GFX_MGR02_TOUCH_EVENT_Q_SIZE)
      {
         fl_tread_U32 = 0;
      }
      l_touch_data[p_touch_id].l_tread_index_U32 = fl_tread_U32;
      GFX_MGR02_ENTER_CS(l_tcritical_section);
      l_touch_data[p_touch_id].l_tcount_U32--;
      GFX_MGR02_LEAVE_CS(l_tcritical_section);
      fl_sts_U32 = (UINT32)TRUE;
   }
   else
   {
      fl_sts_U32 = (UINT32)FALSE;
   }
   return(fl_sts_U32);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_freeze_touch_event
Description          : Freeze further events of the active button by making
                       the touch area invalid. All further events to application
                       for the active button is sent with GFX_MGR02_MOUSE_OUTOF_BOUND
                       flag. 
                       Note : Processed only if passed screen id matches to the
                       touch events screen id or GFX_MGR02_NUM_OF_SCREENS is passed
Invocation           : By application.
Parameters           : None
Return Value         : None
Critical Section     : Yes
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_layout_freeze_touch_event(GFX_MGR02_SCR_ELEM_ID p_screen_id,UINT8 p_touch_id)
{
   GFX_MGR02_ENTER_CS(l_tcritical_section);
   if((p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS)&&(l_touch_data[p_touch_id].l_last_touch_elem_SP != GFX_MGR02_NULL_PTR))
   {
      if((l_touch_data[p_touch_id].l_tcur_screen == p_screen_id) || (p_screen_id == GFX_MGR02_NUM_OF_SCREENS))
      {
         /* -1 not used since it is used for outof bound */
          l_touch_data[p_touch_id].l_last_touch_area_S.sx =  0;
          l_touch_data[p_touch_id].l_last_touch_area_S.sy =  0;
          l_touch_data[p_touch_id].l_last_touch_area_S.ex = -2;
          l_touch_data[p_touch_id].l_last_touch_area_S.ey = -2;
      }
   }
   GFX_MGR02_LEAVE_CS(l_tcritical_section);
}
 
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_process_touch_events
Description          : This function pops button events from the queue and
                       hands it over to the GfxManagerTouchEventHandler to
                       despatch it to application.
                       TODO : Element transformations not taken in to
                              account, so button area is the default code
                              generation values only.
                              If the button is deactivated / removed from
                              screen due to a graphics command after the
                              first button event is sent, still the events
                              gets routed to the same button.
Invocation           : By application.
Parameters           : None.
Return Value         :
Critical Section     : This function needs to be called from the same context
                       as the sending of events/data to the graphics manager.
                       Ideally needs to call at the end of the Graphics_Task()
                       This cuntion sets the internal event data so by calling
                       it at the end will make sure that it reads and sets the
                       correct data.
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_layout_process_touch_events(void)
{
   GFX_MGR02_TOUCH_QDATA fl_touch_event_SP;
   UINT8 fl_finger_count;
   for (fl_finger_count = 0; fl_finger_count < GFX_MGR02_TOUCH_NO_OF_FINGERS; fl_finger_count++)
   {
       while (hmi_gfx_mgr02_layout_pop_touch_event(&fl_touch_event_SP, fl_finger_count) != 0)
       {
           if(l_touch_data[fl_finger_count].l_last_touch_elem_SP != GFX_MGR02_NULL_PTR)
           {
               GFX_MGR02_ENTER_CS(l_tcritical_section);
               if ((fl_touch_event_SP.x < l_touch_data[fl_finger_count].l_last_touch_area_S.sx) ||
                   (fl_touch_event_SP.x > l_touch_data[fl_finger_count].l_last_touch_area_S.ex) ||
                   (fl_touch_event_SP.y < l_touch_data[fl_finger_count].l_last_touch_area_S.sy) ||
                   (fl_touch_event_SP.y > l_touch_data[fl_finger_count].l_last_touch_area_S.ey))
               {
                   /*
                   ** Touch freezed so set GFX_MGR02_MOUSE_FREEZE bit
                   */
                   if ((l_touch_data[fl_finger_count].l_last_touch_area_S.sx == 0) && (l_touch_data[fl_finger_count].l_last_touch_area_S.ex == -2) &&
                       (l_touch_data[fl_finger_count].l_last_touch_area_S.sy == 0) && (l_touch_data[fl_finger_count].l_last_touch_area_S.ey == -2))
                   {
                       fl_touch_event_SP.event |= GFX_MGR02_MOUSE_FREEZE;
                   }
                   else
                   {
                       /*
                       ** Touch point moved outside the selected element.
                       ** So load invalid area to makesure that we can remember this condition
                       ** even if the point later comes back to elements area later.
                       ** (By having an invalid area makes sure that touch point inside condition
                       ** never becomes valid again)
                       */
                       l_touch_data[fl_finger_count].l_last_touch_area_S.sx = 0;
                       l_touch_data[fl_finger_count].l_last_touch_area_S.sy = 0;
                       l_touch_data[fl_finger_count].l_last_touch_area_S.ex = -1;
                       l_touch_data[fl_finger_count].l_last_touch_area_S.ey = -1;
                       /*
                       ** (Normal press and release with in element bound is
                       ** indicated by GFX_MGR02_MOUSE_UP_EV itself) But
                       ** POINT MOVED outside the bounds of the button
                       ** is indicated by passing a GFX_MGR02_MOUSE_OUTOF_BOUND
                       ** FLAG along with mouse event to provide the application
                       ** the ability to decide whether to process or no to
                       */
                       fl_touch_event_SP.event |= GFX_MGR02_MOUSE_OUTOF_BOUND;
                   }
               }
               GFX_MGR02_LEAVE_CS(l_tcritical_section);
               fl_touch_event_SP.finger = fl_finger_count;
               hmi_gfx_mgr02_app_touch_event_handler(l_touch_data[fl_finger_count].l_last_touch_elem_SP->obj_id, &fl_touch_event_SP);
               if (GFX_MGR02_GET_MOUSE_EV(fl_touch_event_SP.event) == GFX_MGR02_MOUSE_UP_EV)
               {
#if defined(GFX_MGR02_AUTOSELECT_TOUCH_WIDGET) 
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
                   if (GFX_MGR02_GET_OBJ_TYPE(l_touch_data[fl_finger_count].l_last_touch_elem_SP->obj_id) == GFX_MGR02_TYPE_DWIDGET)
                   {
                       /*
                       ** Incase of dynamic widget, bring back the selection one down when the
                       ** button is released.
                       */
                       SINT32 fl_selection = hmi_gfx_mgr02_layout_get_dwidget_selection(l_touch_data[fl_finger_count].l_last_touch_elem_SP);
                       fl_selection--;
                       if (fl_selection >= 0)
                       {
                           hmi_gfx_mgr02_layout_select_dwidget(l_touch_data[fl_finger_count].l_last_touch_elem_SP->obj_id, fl_selection);
                       }
                   }
#endif
#endif
                   GFX_MGR02_ENTER_CS(l_tcritical_section);
                   l_touch_data[fl_finger_count].l_last_touch_elem_SP = GFX_MGR02_NULL_PTR;
                   l_touch_data[fl_finger_count].l_tcur_screen = GFX_MGR02_NUM_OF_SCREENS;
                   GFX_MGR02_LEAVE_CS(l_tcritical_section);
               }
           }
           else if (GFX_MGR02_GET_MOUSE_EV(fl_touch_event_SP.event) == GFX_MGR02_MOUSE_DOWN_EV)
           {
               hmi_gfx_mgr02_layout_process_touch_event(&fl_touch_event_SP, fl_finger_count);
           }
           else
           {
           }
       }
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_is_touch_object_visible
Description          : Given touch button area is checked for full visibility
                       If the button is fully or partly obstructed by any 
                       high priority screens then returns a FALSE, If the 
                       button is fully visible returns TRUE.
Invocation           : Internally by manager.
Parameters           : Layer and priority information of the button and the
                       button area
Return Value         : TRUE/FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_layout_is_touch_object_visible(GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                                u_gx_flocal p_cur_priority,
                                                                GFX_MGR02_VISIBLE_AREA * p_touch_area_SP)
{
   u_gx_flocal fl_ts_priority_U8 = p_layer_table_SP->nb_priority;
   u_gx_flocal fl_ts_screen_id;
   GFX_FLOAT       fl_hp_scr_bound[4];
   GFX_MGR02_VISIBLE_AREA fl_scr_area_S;

   p_cur_priority++;
   while(fl_ts_priority_U8 > p_cur_priority)
   {
      fl_ts_priority_U8--;
      fl_ts_screen_id = p_layer_table_SP->prio_stack[fl_ts_priority_U8];
      if(fl_ts_screen_id < GFX_MGR02_NUM_OF_SCREENS)
      {
         GFX_MGR02_ELEM_LIST_T fl_scr_elem_S;
         fl_scr_elem_S.num_child_elements = lc_screen_def_S[fl_ts_screen_id].num_child_elements;
         fl_scr_elem_S.child = lc_screen_def_S[fl_ts_screen_id].child;
         hmi_gfx_mgr02_generic_get_element_bound(&fl_scr_elem_S, 
                                                 p_layer_table_SP->target,
                                                 fl_hp_scr_bound);
         fl_scr_area_S.sx  = (SINT16)fl_hp_scr_bound[0];
         fl_scr_area_S.sy  = (SINT16)fl_hp_scr_bound[1];
         fl_scr_area_S.ex  = (SINT16)fl_hp_scr_bound[2];
         fl_scr_area_S.ey  = (SINT16)fl_hp_scr_bound[3];
         fl_scr_area_S.ex += fl_scr_area_S.sx;
         fl_scr_area_S.ey += fl_scr_area_S.sy;
         if( (p_touch_area_SP->sx >= fl_scr_area_S.sx) && 
             (p_touch_area_SP->ex <= fl_scr_area_S.ex) &&
             (p_touch_area_SP->sy >= fl_scr_area_S.sy) &&
             (p_touch_area_SP->ey <= fl_scr_area_S.ey))
         {
            return((u_gx_flocal)FALSE);
         }
      }
   }
   return((u_gx_flocal)TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_process_touch_event
Description          : Searches through all touch area in the active screens
                       in all the layers, to find a match for the passed event
                       location. Once a match is found, notifies the application
                       for action.
Invocation           : Internally by manager.
Parameters           : x,y coordinate of the touch and the touch event
                       Touch event can be GFX_MOUSE_MOVE_EV, GFX_MOUSE_DOWN_EV
                       or GFX_MOUSE_UP_EV
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_layout_process_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP,UINT8 p_touch_id)
{
    GFX_MGR02_LAYER_DEF_T  const * fl_layer_table_SP;
    GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP;
    u_gx_flocal                    fl_cur_priority_U8;
    u_gx_flocal                    fl_screen_id;
    u_gx_flocal                    fl_layer_index = GFX_MGR02_NUM_LAYERS;
    u_gx_flocal                    fl_num_touch_points;
    UINT8 const          * const * fl_touch_pt_path_U8AP;
    UINT8 const                  * fl_touch_pt_path_U8P;
    
    while((fl_layer_index > 0)&&(p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS))
    {
        fl_layer_index--;
        fl_layer_table_SP  = &lc_layer_def_S[fl_layer_index];
        fl_cur_priority_U8 = fl_layer_table_SP->nb_priority;
        while(fl_cur_priority_U8 > 0)
        {
            fl_cur_priority_U8--;
            fl_screen_id = fl_layer_table_SP->prio_stack[fl_cur_priority_U8];
            if(fl_screen_id < GFX_MGR02_NUM_OF_SCREENS)
            {
                fl_screen_def_SP      = &lc_screen_def_S[fl_screen_id];
                fl_num_touch_points   = fl_screen_def_SP->no_touch_points;  
                fl_touch_pt_path_U8AP = fl_screen_def_SP->touch_points_table;
                if((fl_num_touch_points != 0) && (fl_touch_pt_path_U8AP != 0))
                {
                   while(fl_num_touch_points > 0)
                   {
                      fl_num_touch_points--;
                      fl_touch_pt_path_U8P = *fl_touch_pt_path_U8AP;
                      fl_touch_pt_path_U8AP++;
                      hmi_gfx_mgr02_context_begin_update(fl_layer_index, &lc_layer_def_S[fl_layer_index], FALSE);
                      hmi_gfx_mgr02_context_reset_state();
                      hmi_gfx_mgr02_context_set_loc(&l_gfx_mgr02_anim_data_S.layer_loc[fl_layer_index]);
                   #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
                      if(fl_screen_def_SP->anim_index < GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)
                      {       
                         hmi_gfx_mgr02_context_set_loc(&l_gfx_mgr02_anim_data_S.group_loc[fl_screen_def_SP->anim_index]);        
                      }
                   #endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */
                      if(hmi_gfx_mgr02_layout_check_touch_point(p_touch_data_SP,
                                                                &fl_touch_pt_path_U8P[1],
                                                                &fl_screen_def_SP->child[fl_touch_pt_path_U8P[0]],
                                                                fl_layer_table_SP,
                                                                fl_cur_priority_U8,
                                                                p_touch_id))
                      {
                          /*
                          ** Touch event is processed, so exit all the loops.
                          ** prevent passing the events to other buttons
                          */
                          fl_num_touch_points = 0;
                          fl_layer_index      = 0;
                          fl_cur_priority_U8  = 0;
                          GFX_MGR02_ENTER_CS(l_tcritical_section);
                          l_touch_data[p_touch_id].l_tcur_screen       = fl_screen_id;
                          GFX_MGR02_LEAVE_CS(l_tcritical_section);
                      }
                   }
                }
            }
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_apply_touch_property
Description          : Applies the passed elements xy, clip and area properties
                       in to the context structure.
Invocation           : Internally by manager.
Parameters           : element
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_layout_apply_touch_property(GFX_MGR02_ELEM_LIST_T const * p_elem_SP)
{
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
  GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
   GFX_MGR02_WIDGET_DEF_T const    * fl_element_def_SP;
   GFX_MGR02_IAREA_DATA              fl_clip_area_SP;
   UINT32                            fl_obj_id_U32;
   UINT32                            fl_obj_type_U32;
   #if defined(GFX_MGR02_IMXRT)
   UINT16 base_id;
   UINT8 fl_clip_mode;
   #endif 
   fl_obj_id_U32   = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   fl_obj_type_U32 = GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id);

   /* if widget is animable element */
   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
   {
      if(fl_obj_type_U32 == GFX_MGR02_TYPE_SWIDGET)
      {
      #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
       #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_IMXRT)
         GFX_MGR02_ILOC_DATA  fl_coord;
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
         GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP = hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_obj_id_U32);
        #else
         GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id_U32];
        #endif
       #endif
         fl_elem_anim_prop_SP = &l_gfx_mgr02_anim_data_S.widget_prop[fl_obj_id_U32];
		 #if defined(GFX_MGR02_IMXRT)
         base_id = lc_widget_anim_property_S[fl_obj_id_U32].base_id;
	 	 fl_clip_mode =lc_swidget_layer_def_S[base_id].clip_mode;
         #endif 
       #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_IMXRT)
         /*
         ** If kepler platform present then widget co-ordinates indicate 
         ** actual location, but ovg and swr handles only offset co-orinate for
         ** widgets.
         */
         fl_coord.x  = fl_elem_anim_prop_SP->coord.x;
         fl_coord.y  = fl_elem_anim_prop_SP->coord.y;
         fl_coord.x -= fl_elem_prop_SP->coord.x;
         fl_coord.y -= fl_elem_prop_SP->coord.y;
         hmi_gfx_mgr02_context_set_loc(&fl_coord);
       #else       
         hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
       #endif       
       #if defined(GFX_MGR02_CLIPPED_WIDGETS)
		 #if defined(GFX_MGR02_IMXRT)
		  if(fl_clip_mode != GFX_MGR02_WP_CLIP_NONE)
          {
           hmi_gfx_mgr02_context_set_clip(&fl_elem_anim_prop_SP->clip);
		  }
         #else
           hmi_gfx_mgr02_context_set_clip(&fl_elem_anim_prop_SP->clip);
		 #endif 
       #else
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_element_def_SP      = hmi_gfx_mgr02_get_swidget_layer_def_ptr(p_elem_SP->base_id);
        GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr(fl_element_def_SP->clip_index);
        #else
        GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr = GFX_MGR02_NULL_PTR;
        fl_element_def_SP      = &lc_swidget_layer_def_S[p_elem_SP->base_id];
        if( fl_element_def_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
        {
           fl_elem_offset_ptr=&lc_elem_area_offset_SA[fl_element_def_SP->clip_index];
        }
        #endif
         if( fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
         {             
           fl_clip_area_SP.x      = fl_elem_offset_ptr->sx;
           fl_clip_area_SP.y      = fl_elem_offset_ptr->sy;
           fl_clip_area_SP.width  = (UINT16)fl_elem_offset_ptr->ex;          
           fl_clip_area_SP.height = (UINT16)fl_elem_offset_ptr->ey;
           hmi_gfx_mgr02_context_set_clip(&fl_clip_area_SP);
         }
       #endif
      #endif /* #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 */
      }
   #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0)
      else  if(fl_obj_type_U32 == GFX_MGR02_TYPE_DWIDGET)
      {
      #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
         hmi_gfx_mgr02_context_set_loc(&l_gfx_mgr02_anim_data_S.group_loc[fl_obj_id_U32]);
      #endif
      }
   #endif
      else
      {
      }
   }
   else
   {
      if(fl_obj_type_U32 == GFX_MGR02_TYPE_SWIDGET)
      {   
      #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
         GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr;
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
         fl_element_def_SP      = hmi_gfx_mgr02_get_swidget_layer_def_ptr(p_elem_SP->base_id);
         fl_elem_offset_ptr     = hmi_gfx_mgr02_get_elem_area_offset_ptr(fl_element_def_SP->clip_index);
        #else
         fl_element_def_SP      = &lc_swidget_layer_def_S[p_elem_SP->base_id];
         fl_elem_offset_ptr     = &lc_elem_area_offset_SA[fl_element_def_SP->clip_index];
        #endif
         fl_clip_area_SP.x      = fl_elem_offset_ptr->sx;
         fl_clip_area_SP.y      = fl_elem_offset_ptr->sy;
         fl_clip_area_SP.width  = (UINT16)fl_elem_offset_ptr->ex;          
         fl_clip_area_SP.height = (UINT16)fl_elem_offset_ptr->ey;
         hmi_gfx_mgr02_context_set_clip(&fl_clip_area_SP);
      #endif /*#if GFX_MGR02_NUM_SWDG_INSTANCES > 0*/
      }
   }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_check_touch_point
Description          : Searches through current path and if the current path 
                       is valid, then checks the mouse co-orditaes against the
                       accumulated selected elements x, y , width, height 
                       information. If the mouse location falls in the selected
                       elements area then emits an event to application and 
                       returns TRUE.
                       This function executed recursively for every path index
                       until the end is reached which is marked by a path 
                       index value of 255.
Invocation           : Internally by manager.
Parameters           : x,y coordinate of the touch and the touch event
                       Touch event can be GFX_MOUSE_MOVE_EV, GFX_MOUSE_DOWN_EV
                       or GFX_MOUSE_UP_EV
                       Touch path information array
                       Current element
Return Value         : TRUE if touch event is mapped to the given path
Critical Section     : None
External Interfaces  : hmi_gfx_mgr02_app_touch_event_handler()
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_layout_check_touch_point(GFX_MGR02_TOUCH_QDATA       * p_touch_data_SP,
                                                          UINT8 const                 * p_touch_pt_path_U8P,
                                                          GFX_MGR02_ELEM_LIST_T const * p_elem_SP,
                                                          GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                          u_gx_flocal p_cur_priority,
                                                          UINT8 p_touch_id)
{
   GFX_MGR02_ELEM_LIST_T const * fl_sel_elem_SP = GFX_MGR02_NULL_PTR;
   GFX_MGR02_CONTEXT_T         * fl_context_SP;
   u_gx_flocal fl_ret_status = FALSE;
   u_gx_flocal fl_elem_index = *p_touch_pt_path_U8P;
   SINT32      fl_sx;
   SINT32      fl_sy;
   SINT32      fl_ex;
   SINT32      fl_ey;

   hmi_gfx_mgr02_layout_apply_touch_property(p_elem_SP);
   if(p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS)
   {
       if(GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id) == GFX_MGR02_TYPE_SWIDGET)
       {
          if(fl_elem_index < p_elem_SP->num_child_elements)
          {
             fl_sel_elem_SP = &p_elem_SP->child[fl_elem_index];
          }
          else
          {
          #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
           #ifdef GFX_MGR02_ENABLE_TOUCH_OBJ_SIZE_CALC
             /*
             ** in some cases rather than animating the touch widget, the objects within
             ** the touch widgets might be animated by an application. This will also result
             ** in the touch widget to be in a different size, position. 
             ** Inorder to account this, calculate the bound of the widget, and then apply
             ** it. 
             */
             GFX_FLOAT fl_bound[4];
             if(hmi_gfx_mgr02_generic_get_element_bound(p_elem_SP, p_layer_table_SP->target, fl_bound) != FALSE)
             {
                GFX_MGR02_IAREA_DATA fl_clip_SP;
                fl_clip_SP.x      = (SINT16)fl_bound[0];
                fl_clip_SP.y      = (SINT16)fl_bound[1];
                fl_clip_SP.width  = (UINT16)fl_bound[2];
                fl_clip_SP.height = (UINT16)fl_bound[3];
                hmi_gfx_mgr02_context_set_clip(&fl_clip_SP);
             }
           #endif	 
          #endif
             fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
             fl_sx = (fl_context_SP->state.clip.sx);
             fl_sy = (fl_context_SP->state.clip.sy);
             fl_ex = (fl_context_SP->state.clip.ex);  
             fl_ey = (fl_context_SP->state.clip.ey);  
             if((p_touch_data_SP->x >= fl_sx) && (p_touch_data_SP->x <= fl_ex) && 
                (p_touch_data_SP->y >= fl_sy) && (p_touch_data_SP->y <= fl_ey))
             {
                /*
                ** Touch detected.
                */
                if(hmi_gfx_mgr02_layout_is_touch_object_visible(p_layer_table_SP, 
                                                                p_cur_priority, 
                                                                &fl_context_SP->state.clip) != (u_gx_flocal)FALSE)
                {
                   GFX_MGR02_ENTER_CS(l_tcritical_section);
                   l_touch_data[p_touch_id].l_last_touch_area_S.sx = (SINT16)fl_sx;
                   l_touch_data[p_touch_id].l_last_touch_area_S.sy = (SINT16)fl_sy;
                   l_touch_data[p_touch_id].l_last_touch_area_S.ex = (SINT16)fl_ex;
                   l_touch_data[p_touch_id].l_last_touch_area_S.ey = (SINT16)fl_ey;
                   l_touch_data[p_touch_id].l_last_touch_elem_SP   = p_elem_SP;
                   GFX_MGR02_LEAVE_CS(l_tcritical_section);
                   p_touch_data_SP->finger = p_touch_id;
                   hmi_gfx_mgr02_app_touch_event_handler(p_elem_SP->obj_id, p_touch_data_SP);
                   fl_ret_status = (u_gx_flocal)TRUE;
                }
             }
          }
       }
    #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0)
       else
       {
          fl_sel_elem_SP = hmi_gfx_mgr02_layout_get_selected_swidget(p_elem_SP);
          if(fl_elem_index < p_elem_SP->num_child_elements)
          {
             p_elem_SP = &p_elem_SP->child[fl_elem_index];
             if(fl_sel_elem_SP != p_elem_SP)
             {
                /*
                ** Current widget selection doesn't match with what this touch path
                ** selection is, so the touch path is not valid.
                */
                fl_sel_elem_SP = GFX_MGR02_NULL_PTR;
             }
          }
          else if(fl_sel_elem_SP != GFX_MGR02_NULL_PTR)
          {
          #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
           #ifdef GFX_MGR02_ENABLE_TOUCH_OBJ_SIZE_CALC
             /*
             ** in some cases rather than animating the touch widget, the objects within
             ** the touch widgets might be animated by an application. This will also result
             ** in the touch widget to be in a different size, position. 
             ** Inorder to account this, calculate the bound of the widget, and then apply
             ** it. 
             */
             GFX_FLOAT fl_bound[4];
             if(hmi_gfx_mgr02_generic_get_element_bound(p_elem_SP, p_layer_table_SP->target, fl_bound) != FALSE)
             {
                GFX_MGR02_IAREA_DATA fl_clip_SP;
                fl_clip_SP.x      = (SINT16)fl_bound[0];
                fl_clip_SP.y      = (SINT16)fl_bound[1];
                fl_clip_SP.width  = (UINT16)fl_bound[2];
                fl_clip_SP.height = (UINT16)fl_bound[3];
                hmi_gfx_mgr02_context_set_clip(&fl_clip_SP);
             }
           #endif 
          #endif 
             /*
             ** End of path reached and last element is a dynamic widget
             ** This means that the touch enable was configured to a dynamic
             ** widget level. Now in order to see if the touch is valid or not
             ** the selected static widget of the dynamic widget has to be 
             ** validated against the touch co-ordinates. 
             */
             hmi_gfx_mgr02_layout_apply_touch_property(fl_sel_elem_SP);
             fl_context_SP   = hmi_gfx_mgr02_context_get_ptr();
             fl_sx           = (fl_context_SP->state.clip.sx);
             fl_sy           = (fl_context_SP->state.clip.sy);
             fl_ex           = (fl_context_SP->state.clip.ex);  
             fl_ey           = (fl_context_SP->state.clip.ey);  

             if((p_touch_data_SP->x >= fl_sx) && (p_touch_data_SP->x <= fl_ex) && 
                (p_touch_data_SP->y >= fl_sy) && (p_touch_data_SP->y <= fl_ey))
             {
                /*
                ** Touch detected.
                */
                if(hmi_gfx_mgr02_layout_is_touch_object_visible(p_layer_table_SP, 
                                                                p_cur_priority, 
                                                                &fl_context_SP->state.clip) != (u_gx_flocal)FALSE)
                {
                   GFX_MGR02_ENTER_CS(l_tcritical_section);
                   l_touch_data[p_touch_id].l_last_touch_area_S.sx = (SINT16)fl_sx;
                   l_touch_data[p_touch_id].l_last_touch_area_S.sy = (SINT16)fl_sy;
                   l_touch_data[p_touch_id].l_last_touch_area_S.ex = (SINT16)fl_ex;
                   l_touch_data[p_touch_id].l_last_touch_area_S.ey = (SINT16)fl_ey;
                   l_touch_data[p_touch_id].l_last_touch_elem_SP   = p_elem_SP;
                   GFX_MGR02_LEAVE_CS(l_tcritical_section);
                   /*
                   ** Move the dynamic widget selection to next to show highlight
                   */
                #if defined(GFX_MGR02_AUTOSELECT_TOUCH_WIDGET) 
                   fl_sx = hmi_gfx_mgr02_layout_get_dwidget_selection(p_elem_SP);
                   fl_sx++;
                   if(fl_sx < p_elem_SP->num_child_elements)
                   {
                      hmi_gfx_mgr02_layout_select_dwidget(p_elem_SP->obj_id, fl_sx);
                   }
                #endif
                   /*
                   ** Notify application
                   */
                   p_touch_data_SP->finger = p_touch_id;
                   hmi_gfx_mgr02_app_touch_event_handler(p_elem_SP->obj_id, p_touch_data_SP);
                   fl_ret_status  = (u_gx_flocal)TRUE;
                }
             }
             fl_sel_elem_SP = GFX_MGR02_NULL_PTR;
          }
          else
          {
          }
       }
    #endif
       if(fl_sel_elem_SP != GFX_MGR02_NULL_PTR)
       {
          fl_ret_status = hmi_gfx_mgr02_layout_check_touch_point(p_touch_data_SP,
                                                                 &p_touch_pt_path_U8P[1], 
                                                                 fl_sel_elem_SP,
                                                                 p_layer_table_SP,
                                                                 p_cur_priority,
                                                                 p_touch_id);
       }
   }
   return(fl_ret_status);
}
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_is_touch_events_pending
 ** Visibility:       global
 ** Description:      
 ** Invocation:       
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          20-Feb-2014 by EMANOJ1
 ** Updated:          20-Feb-2014 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_is_touch_events_pending(UINT8 p_touch_id)
{
    UINT32 fl_ret = (UINT32)0 ;
    if(p_touch_id < GFX_MGR02_TOUCH_NO_OF_FINGERS)
    {
        fl_ret = (l_touch_data[p_touch_id].l_tcount_U32);
    }
     return fl_ret;
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_validate_layer_area
 ** Visibility:       static
 ** Description:      Validates an elements area for boundary and updates the
 **                   area status as one of the below
 **                   transparent,     (GFX_MGR02_TRANSPARENT)
 **                   half-transparent (GFX_MGR02_SEETHROUGH)
 **                   OR opeque        (GFX_MGR02_OPEQUE)
 ** Invocation:       by hmi_gfx_mgr02_get_element_area
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          10-Jul-2013 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_layout_validate_layer_area(GFX_MGR02_ELEMENT_AREA * p_elem_area,
                                              UINT32                   p_vaof_index,
                                              BOOLEAN                   p_total_area,
                                              UINT32                   p_layer_index)
{
    if(p_elem_area != GFX_MGR02_NULL_PTR)
    {
        if(p_elem_area->is_transparent != (UINT8)GFX_MGR02_TRANSPARENT)
        {
            /*
            ** Element is fully visible or partly visible.
            ** Now check and see if this layer hides any other already exisitng layers
            ** If yes, remove those from the l_gfx_mgr02_data_S.next_elem_list_sa and
            ** l_next_visible_elem_area_SA
            */
            p_elem_area->ex += p_elem_area->sx;
            p_elem_area->ey += p_elem_area->sy;
            /*
            ** Subtract the outer transparent area from the elements 
            ** total area to find the opeque rectangle region.
            */
            if(p_vaof_index != GFX_MGR02_INVALID_ID)
            {
                #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr((UINT16)p_vaof_index);
                #else
                GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr = GFX_MGR02_NULL_PTR;
                if( p_vaof_index < GFX_MGR02_NUM_VISIBLE_AREA)
                {
                    fl_elem_offset_ptr=&lc_elem_area_offset_SA[p_vaof_index];
                }                
                #endif
                if(fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
                {
                   if(fl_elem_offset_ptr->sx == GFX_MGR02_OFFSET_TRANSPARENT)
                   {
                      /* This element is fully transparent */
                      p_elem_area->is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                   }
                   else if(fl_elem_offset_ptr->sx == GFX_MGR02_OFFSET_SEETHROUGH)
                   {
                      /* This element is partially transparent */
                      p_elem_area->is_transparent = (UINT8)GFX_MGR02_SEETHROUGH;
                   }
                   else
                   {
                      /* apply the offset since the value is valid */
                      p_elem_area->sx += fl_elem_offset_ptr->sx;
                      p_elem_area->sy += fl_elem_offset_ptr->sy;
                      p_elem_area->ex -= fl_elem_offset_ptr->ex;
                      p_elem_area->ey -= fl_elem_offset_ptr->ey;
                   }
                }
            }
         #if defined(GFX_MGR02_ALLOWED_OVERLAP_ERROR_W) && defined(GFX_MGR02_ALLOWED_OVERLAP_ERROR_H)
          #if (GFX_MGR02_ALLOWED_OVERLAP_ERROR_W > 0) && (GFX_MGR02_ALLOWED_OVERLAP_ERROR_H > 0)
            /*
            ** When the base elements area is requested we can reduce the area by
            ** an offset GFX_MGR02_ALLOWED_OVERLAP_ERROR_W/GFX_MGR02_ALLOWED_OVERLAP_ERROR_H
            ** So that the base element will be considered little smaller by the
            ** hmi_gfx_mgr02_manage_layers_is_child_visible() loop so that if only a little portion of
            ** the image only is visible then it could be marked as invisible and can be
            ** taken off from DCU allocation.
            ** E.g. if image 1 is low priority and its area is (10, 10, 100, 100) and image 2
            ** which is of heigher priority than image 1 and has an area of (12, 12, 98, 98)
            ** In this case without the overlap error, both image 1 and image 2 gets the DCU
            ** allocation. With an overlap error of 2, image 1 size will be reduced by 2 becomes
            ** (12,12,98,98) and therefore looks as if completely hidden by image 2. In this case
            ** only image 2 gets a DCU allocated.
            ** So GFX_MGR02_ALLOWED_OVERLAP_ERROR_W, GFX_MGR02_ALLOWED_OVERLAP_ERROR_H allows
            ** application to specify a small error offset while determining a element is
            ** visible or not.
            */
            if(p_total_area != FALSE)
            {
                if((p_elem_area->ex > p_elem_area->sx) &&
                   (p_elem_area->ey > p_elem_area->sy)   )
                {
                    if((p_elem_area->ex > (GFX_MGR02_ALLOWED_OVERLAP_ERROR_W << 1)) &&
                       (p_elem_area->ey > (GFX_MGR02_ALLOWED_OVERLAP_ERROR_H << 1))    )
                    {
                        p_elem_area->sx += GFX_MGR02_ALLOWED_OVERLAP_ERROR_W;
                        p_elem_area->sy += GFX_MGR02_ALLOWED_OVERLAP_ERROR_H;
                        p_elem_area->ex -= GFX_MGR02_ALLOWED_OVERLAP_ERROR_W;
                        p_elem_area->ey -= GFX_MGR02_ALLOWED_OVERLAP_ERROR_H;
                    }
                }
            }
          #else
          GFX_MGR02_UNUSED_VAR(p_total_area);
          #endif
          #else
          GFX_MGR02_UNUSED_VAR(p_total_area);
          #endif
            if(p_elem_area->alpha == (UINT8)0)
            {
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
            }
            else if(p_elem_area->alpha < (UINT8)255)
            {
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_SEETHROUGH;
            }
            else
            {
                /*To Fix MISRA warning.*/
            }
            if((p_elem_area->ex <= 0) && (p_elem_area->ey <= 0))
            {
                p_elem_area->sx = 0;
                p_elem_area->sy = 0;
                p_elem_area->ex = 0;
                p_elem_area->ey = 0;
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
            }
            else
            {
                if(p_elem_area->sx < 0)
                {
                    p_elem_area->sx = 0;
                }
                if(p_elem_area->ex < 0)
                {
                    p_elem_area->ex = 0;
                }
                if(p_elem_area->sy < 0)
                {
                    p_elem_area->sy = 0;
                }
                if(p_elem_area->ey < 0)
                {
                    p_elem_area->ey = 0;
                }
                if (p_layer_index < GFX_MGR02_NUM_LAYERS)
                {
                    if((p_elem_area->ex <= p_elem_area->sx)      ||
                       (p_elem_area->ey <= p_elem_area->sy)      ||
                       (p_elem_area->sx >= (SINT16)lc_layer_def_S[p_layer_index].area.width) ||
                       (p_elem_area->sy >= (SINT16)lc_layer_def_S[p_layer_index].area.height) ||
                       (p_elem_area->ex <= lc_layer_def_S[p_layer_index].area.x) ||
                       (p_elem_area->ey <= lc_layer_def_S[p_layer_index].area.y))
                    {
                        /*
                        ** Area is invalid or are outside displayable area
                        */
                        p_elem_area->is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                    }
                }

            }
        }
        else
        {
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
        }
   }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_is_render_done
 ** Visibility:       static
 ** Description:      Checks if the rendering of the last frame been done
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          21-April-2016 by VTODOROV
 ** Updated:          21-April-2016 by VTODOROV
 **==========================================================================*/
#if defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
BOOLEAN hmi_gfx_mgr02_layout_is_render_done(void)
{
   BOOLEAN fl_ret_status = FALSE;
   #if defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
   if (hmi_gfx_mgr02_amber_driver_busy() == (UINT8)0)
   #elif defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
   if (hmi_gfx_mgr02_imxrt_lcdif_is_render_done() == TRUE)
   #endif
   {
     fl_ret_status = TRUE;
   }
   return (fl_ret_status);
}

#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_get_amber_driver_status
 ** Visibility:       Global
 ** Description:      Returns the current amber driver status
 ** Inputs:           None.
 ** Outputs:          Output=0-> Free.
 **                   Output=1-> Busy.
 ** Critical Section: None.
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_get_amber_driver_status(void)
{
   UINT32 fl_status_u32;
   fl_status_u32 = hmi_gfx_mgr02_get_amber_driver_cur_status();
   return fl_status_u32;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_restart_AmberDriver
 ** Visibility:       Global
 ** Description:      Shuts down graphics manager layout and restarts Amber driver
 **                   and initialises context.
 ** Inputs/Outputs:
 ** Critical Section: None.
 **==========================================================================*/
void hmi_gfx_mgr02_layout_restart_AmberDriver(void)
{
    (void)hmi_gfx_mgr02_layout_shutdown();
    (void)hmi_gfx_mgr02_initialize();
    if(hmi_gfx_mgr02_context_initialize() != FALSE)
    {
      l_cntx_init_status = GFX_MGR02_DONE;
    }
    else
    {
      l_cntx_init_status = GFX_MGR02_PARTIALLY_DONE;
    }	
}
#endif
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_set_warping_table
 ** Visibility:       static
 ** Description:      Updates the Warping Table
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          21-April-2016 by ASHEKHAR
 ** Updated:          21-April-2016 by ASHEKHAR
 **==========================================================================*/
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
#if (((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS >0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))&&((defined(GFX_MGR02_LAYER_WARPING_ENABLED)) || (defined(GFX_MGR02_WIDGET_WARPING_ENABLED))))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_warping_table(GFX_MGR02_ANIM_ELEM_ID p_elem_id, const MML_GDC_WARP_PARAM* p_warp_param, UINT8 * p_warp_data, UINT8 p_force_update)
{
    GUI_GFX_MGR_ERROR_CODE_T fl_return_result;
    UINT32       fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
    #if (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
    if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS))/* Widget Animation */
    {
        if(((l_warp_table[0].warp_params != p_warp_param) || (l_warp_table[0].warp_buffer != p_warp_data)) || (p_force_update == TRUE))
        {
            l_warp_table[0].warp_params = p_warp_param;
            l_warp_table[0].warp_buffer = p_warp_data;
            GFX_MGR02_SET_FLAG(l_wdg_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        }
        fl_return_result = GUI_GFX_MGR_NO_ERROR;
    }
    else
    #endif		
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS >0)
    if((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS))/* Image Animation */
    {
        if(((l_warp_table[0].warp_params != p_warp_param) || (l_warp_table[0].warp_buffer != p_warp_data)) || (p_force_update == TRUE))
        {
            l_warp_table[0].warp_params = p_warp_param;
            l_warp_table[0].warp_buffer = p_warp_data;
            GFX_MGR02_SET_FLAG(l_img_anim_elem_changed_flag_U8A, fl_prop_index_u32);
        }
        fl_return_result = GUI_GFX_MGR_NO_ERROR;
    }
    else
    #endif
    {
        fl_return_result = GUI_GFX_MGR_INVALID_ANIM_ELEM_ID;
    }
    GFX_MGR02_VERIFY_LAYOUT_API_CALL
    return(fl_return_result);
}
#endif

void hmi_gfx_mgr02_layout_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32)
{
  hmi_gfx_mgr02_amber_set_disp_bgcolor(p_disp_index_u8,p_bg_color_u32);
}
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_select_dlayout_index
** Visibility:       global
** Description:      Sets a selected design layout index 
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          15-Jul-2016 by CMUTHUSA
** Updated:          15-Jul-2016 by CMUTHUSA
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dlayout_index(GFX_MGR02_LAYOUT_ID p_selection_index)
{
  GUI_GFX_MGR_ERROR_CODE_T fl_ret_sts;
  if(p_selection_index < GFX_MGR02_NUM_OF_LAYOUTS)
  {
    if(p_selection_index!=l_dlayout_selection_U8)
    {
      l_dlayout_selection_U8=p_selection_index;
      hmi_gfx_mgr02_layout_reset_anim_sts();
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #if GFX_NUM_ANIMATIONS > 0
      hmi_gfx_anim_engine_set_layout_selection((UINT8)l_dlayout_selection_U8);
  #endif
#endif
      l_dlayout_changed_flag_bool=TRUE;

    }
    fl_ret_sts = GUI_GFX_MGR_NO_ERROR;
  }
  else
  {
    fl_ret_sts = GUI_GFX_MGR_INVALID_DLAYOUT;
  }
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return(fl_ret_sts);
}

#if GFX_MGR02_NUM_OF_IMAGE_LAYERS>0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_image_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_IMAGE_DEF_T Table index
******************************************************************************/
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_image_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id; 
  GFX_MGR02_IMAGE_DEF_T const* fl_image_def_S=lc_image_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_image_def_S[fl_elem_id]);
}
#endif
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_image_layer_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_IMAGE_DEF_T Table index
******************************************************************************/
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_image_layer_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  UINT16 fl_base_id=hmi_gfx_mgr02_get_image_anim_prop_ptr(fl_prop_idx)->base_id;
  GFX_MGR02_IMAGE_DEF_T const* fl_image_def_S=lc_image_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_image_def_S[fl_base_id]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_image_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_IMAGE_PROPERTY Table index
******************************************************************************/
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_image_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  GFX_MGR02_IMAGE_PROPERTY const* fl_image_prop_S=lc_img_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_image_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_image_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_IMAGE_PROPERTY Table index
******************************************************************************/
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_image_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  GFX_MGR02_IMAGE_PROPERTY const* fl_image_prop_S=lc_img_const_property_SP[l_dlayout_selection_U8];
  return(&fl_image_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_txt_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_TEXT_DEF_T Table index
******************************************************************************/
GFX_MGR02_TEXT_DEF_T const* hmi_gfx_mgr02_get_txt_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id; 
  GFX_MGR02_TEXT_DEF_T const* fl_text_def_S=lc_text_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_text_def_S[fl_elem_id]);
}
#endif
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_text_layer_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_TEXT_DEF_T Table index
******************************************************************************/
GFX_MGR02_TEXT_DEF_T const* hmi_gfx_mgr02_get_text_layer_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  UINT16 fl_base_id=(hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_prop_idx))->base_id;
  GFX_MGR02_TEXT_DEF_T const* fl_text_def_S=lc_text_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_text_def_S[fl_base_id]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_txt_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_TEXT_PROPERTY Table index
******************************************************************************/
GFX_MGR02_TEXT_PROPERTY const* hmi_gfx_mgr02_get_txt_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  GFX_MGR02_TEXT_PROPERTY const* fl_text_prop_S=lc_text_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_text_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_TEXT_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_txt_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_TEXT_PROPERTY Table index
******************************************************************************/
GFX_MGR02_TEXT_PROPERTY const* hmi_gfx_mgr02_get_txt_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx; 
  GFX_MGR02_TEXT_PROPERTY const* fl_text_prop_S=lc_text_const_property_SP[l_dlayout_selection_U8];
  return(&fl_text_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_fill_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_FILL_DEF_T Table index
******************************************************************************/
GFX_MGR02_FILL_DEF_T const* hmi_gfx_mgr02_get_fill_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id; 
  GFX_MGR02_FILL_DEF_T const* fl_fill_def_S=lc_fill_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_fill_def_S[fl_elem_id]);
}
#endif
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_fill_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_FILL_PROPERTY Table index
******************************************************************************/
GFX_MGR02_FILL_PROPERTY const* hmi_gfx_mgr02_get_fill_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_FILL_PROPERTY const* fl_fill_prop_S=lc_fill_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_fill_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_FILL_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_fill_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_FILL_PROPERTY Table index
******************************************************************************/
GFX_MGR02_FILL_PROPERTY const* hmi_gfx_mgr02_get_fill_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_FILL_PROPERTY const* fl_fill_prop_S=lc_fill_const_property_SP[l_dlayout_selection_U8];
  return(&fl_fill_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_tile_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_TILE_DEF_T Table index
******************************************************************************/
GFX_MGR02_TILE_DEF_T const* hmi_gfx_mgr02_get_tile_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id; 
  GFX_MGR02_TILE_DEF_T const* fl_tile_def_S=lc_tile_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_tile_def_S[fl_elem_id]);
}
#endif
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_tile_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_TILE_PROPERTY Table index
******************************************************************************/
GFX_MGR02_TILE_PROPERTY const* hmi_gfx_mgr02_get_tile_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_TILE_PROPERTY const* fl_tile_prop_S=lc_tile_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_tile_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_TILE_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_tile_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_TILE_PROPERTY Table index
******************************************************************************/
GFX_MGR02_TILE_PROPERTY const* hmi_gfx_mgr02_get_tile_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_TILE_PROPERTY const* fl_tile_prop_S=lc_tile_const_property_SP[l_dlayout_selection_U8];
  return(&fl_tile_prop_S[fl_prop_idx]);
}
#endif

#if GFX_MGR02_NUM_OF_SVGS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_svg_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_OVG_OBJECT_T Table index
******************************************************************************/
GFX_MGR02_OVG_OBJECT_T const* hmi_gfx_mgr02_get_svg_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id;
  GFX_MGR02_OVG_OBJECT_T const* fl_svg_def_S=lc_svg_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_svg_def_S[fl_elem_id]);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_svg_clip_idx()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_prop_idx
Return Value   		 : UINT16 clip_index
******************************************************************************/
UINT16 hmi_gfx_mgr02_get_svg_clip_idx(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_OVG_OBJECT_T const* fl_svg_def_S=lc_svg_layer_def_SP[l_dlayout_selection_U8];
  return(fl_svg_def_S[fl_prop_idx].clip_index);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_svg_elem_area_offset_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_VISIBLE_AREA Table index
******************************************************************************/
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_svg_elem_area_offset_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx=p_prop_idx;
  UINT16 fl_clip_idx =hmi_gfx_mgr02_get_svg_clip_idx(fl_prop_idx);
  GFX_MGR02_VISIBLE_AREA const* fl_tb_base_ptr=lc_elem_area_offset_SP[l_dlayout_selection_U8];
  return(&fl_tb_base_ptr[fl_clip_idx]);
}
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_svg_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_OVG_PROPERTY Table index
******************************************************************************/
GFX_MGR02_OVG_PROPERTY const* hmi_gfx_mgr02_get_svg_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_OVG_PROPERTY const* fl_svg_prop_S=lc_svg_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_svg_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_SVG_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_svg_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_OVG_PROPERTY Table index
******************************************************************************/
GFX_MGR02_OVG_PROPERTY const* hmi_gfx_mgr02_get_svg_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_OVG_PROPERTY const* fl_svg_prop_S=lc_svg_const_property_SP[l_dlayout_selection_U8];
  return(&fl_svg_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_user_img_layer_def_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_IMAGE_DEF_T Table index
******************************************************************************/
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_user_img_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id;
  GFX_MGR02_IMAGE_DEF_T const* fl_user_img_def_S=lc_user_image_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_user_img_def_S[fl_elem_id]);
}
#endif
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_user_img_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_IMAGE_PROPERTY Table index
******************************************************************************/
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_user_img_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_IMAGE_PROPERTY const*fl_user_img_prop_S=lc_user_img_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_user_img_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_OF_SWDGS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_swidget_layer_def_ptr()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_elem_id
Return Value   		 : pointer to GFX_MGR02_WIDGET_DEF_T Table index
******************************************************************************/
GFX_MGR02_WIDGET_DEF_T const* hmi_gfx_mgr02_get_swidget_layer_def_ptr(UINT32 p_elem_id)
{
  UINT32 fl_elem_id =p_elem_id; 
  GFX_MGR02_WIDGET_DEF_T const* fl_swidget_def_S=lc_swidget_layer_def_SP[l_dlayout_selection_U8];
  return(&fl_swidget_def_S[fl_elem_id]);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_swidget_clip_idx()
Description          : 
Invocation           : global
Parameters			 : UINT32 p_prop_idx
Return Value   		 : UINT16 clip_index
******************************************************************************/
UINT16 hmi_gfx_mgr02_get_swidget_clip_idx(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_WIDGET_DEF_T const* fl_swdg_def_S=lc_swidget_layer_def_SP[l_dlayout_selection_U8];
  return(fl_swdg_def_S[fl_prop_idx].clip_index);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_wdg_elem_area_offset_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_VISIBLE_AREA Table index
******************************************************************************/
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_wdg_elem_area_offset_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx=p_prop_idx;
  UINT16 fl_clip_idx =hmi_gfx_mgr02_get_swidget_clip_idx(fl_prop_idx);
  GFX_MGR02_VISIBLE_AREA const* fl_tb_base_ptr=lc_elem_area_offset_SP[l_dlayout_selection_U8];
  return(&fl_tb_base_ptr[fl_clip_idx]);
}
#endif
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_widget_anim_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_WIDGET_PROPERTY Table index
******************************************************************************/
GFX_MGR02_WIDGET_PROPERTY const* hmi_gfx_mgr02_get_widget_anim_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_WIDGET_PROPERTY const* fl_swidget_prop_S=lc_widget_anim_property_SP[l_dlayout_selection_U8];
  return(&fl_swidget_prop_S[fl_prop_idx]);
}
#endif
#if GFX_MGR02_NUM_SWDG_INSTANCES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_swidget_const_prop_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT32 p_prop_idx
Return Value   		 : pointer to GFX_MGR02_WIDGET_PROPERTY Table index
******************************************************************************/
GFX_MGR02_WIDGET_PROPERTY const* hmi_gfx_mgr02_get_swidget_const_prop_ptr(UINT32 p_prop_idx)
{
  UINT32 fl_prop_idx =p_prop_idx;
  GFX_MGR02_WIDGET_PROPERTY const* fl_swidget_prop_S=lc_swdg_const_property_SP[l_dlayout_selection_U8];
  return(&fl_swidget_prop_S[fl_prop_idx]);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_elem_area_offset_ptr()
Description          : 
Invocation           : global
Parameters 			 : UINT16 p_clip_idx
Return Value   		 : pointer to GFX_MGR02_VISIBLE_AREA Table index
******************************************************************************/
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_elem_area_offset_ptr(UINT16 p_clip_idx)
{
  UINT16 fl_clip_idx =p_clip_idx;
  GFX_MGR02_VISIBLE_AREA const* fl_tb_base_ptr=lc_elem_area_offset_SP[l_dlayout_selection_U8];
  return(&fl_tb_base_ptr[fl_clip_idx]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_reset_anim_sts(void)
Description          : Initialize the gfx Anim elements as per new layout
Invocation           : global
Parameters 			 : none
Return Value   		 : none
******************************************************************************/
static void hmi_gfx_mgr02_layout_reset_anim_sts(void)
{
   UINT32 fl_loop_index_u32;   
#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
   /*
   ** Group animations are valid for Screens, dynamic widgets and dynamic images
   ** generally they will have x, y and alpha animations. But for screen alone additionally
   ** there will be a background color component. Screens are always kept first in
   ** the list so (i < GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS) can be done to init
   ** the background color.
   */
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      (void)hmi_gfx_mgr02_layout_reset_group_anim(fl_loop_index_u32);
   }
#endif /* #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0 */
   /*
   ** Layer will support x/y animations to allow movement of the entire layer
   ** This can be used for screen offset adjustments or animations.
   */
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS; fl_loop_index_u32++)
   {
      l_gfx_mgr02_anim_data_S.layer_alpha[fl_loop_index_u32] = (GFX_MGR02_ALPHA)255;
      l_gfx_mgr02_anim_data_S.layer_loc[fl_loop_index_u32].x = 0;
      l_gfx_mgr02_anim_data_S.layer_loc[fl_loop_index_u32].y = 0;
      l_gfx_mgr02_anim_data_S.layer_color[fl_loop_index_u32] = 0xFF000000U;                
   }

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      (void)hmi_gfx_mgr02_layout_reset_image_anim_prop(GFX_MGR02_TYPE_SIMAGE, fl_loop_index_u32, (UINT32)GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      (void)hmi_gfx_mgr02_layout_reset_image_anim_prop(GFX_MGR02_TYPE_USER_LAYER, fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      (void)hmi_gfx_mgr02_layout_reset_fill_anim_prop(fl_loop_index_u32, (UINT32)GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      hmi_gfx_mgr02_layout_reset_tile_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS; fl_loop_index_u32++)
    {
       (void)hmi_gfx_mgr02_layout_reset_widget_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
    }
#endif

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
       (void)hmi_gfx_mgr02_layout_reset_text_anim_prop(fl_loop_index_u32, GFX_MGR_RESET_ANIM_PROPERTIES);
   }
#endif
#if GFX_MGR02_NUM_OF_DTEXTS > 0
   l_gfx_mgr02_anim_data_S.dtext_str = &l_dynamic_text_buffer[0];
#endif
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
   (void)memcpy(l_dyn_widget_selection, lc_dyn_widget_selection, sizeof(l_dyn_widget_selection));
#endif
#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
   (void)memcpy(l_dyn_image_selection,  lc_dyn_image_selection,  sizeof(l_dyn_image_selection));
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
   for(fl_loop_index_u32 = (UINT32)0; fl_loop_index_u32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS; fl_loop_index_u32++)
   {
      hmi_gfx_mgr02_layout_reset_svg_anim(fl_loop_index_u32);
   }
#endif

#if GFX_MGR02_NUM_USER_LAYERS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
   (void)memcpy(&l_gfx_mgr02_anim_data_S.user_image_layer, hmi_gfx_mgr02_get_user_img_layer_def_ptr(0), sizeof(l_gfx_mgr02_anim_data_S.user_image_layer));
#else
   (void)memcpy(&l_gfx_mgr02_anim_data_S.user_image_layer, &lc_user_image_layer_def_S[0], sizeof(l_gfx_mgr02_anim_data_S.user_image_layer));
#endif
#endif

}
#endif /* #if defined(GFX_MGR02_DLAYOUT_ENABLED) */
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_layout_get_disp_content_status
 ** Visibility:       Global
 ** Description:      Interface to get display content status .
 **                   
 ** Invocation:       By GdtCdd.c
 ** Inputs/Outputs:   l_content_ready_ondisplay
 **                   0 -> default.
 **                   1 -> Display active with background colour set.
 **                   2 -> Display active with active layer alongwith 
 **                        background colour set.
 **                        
 ** Critical Section: None.
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_get_disp_content_status(void)
{
  #if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
    return(hmi_gfx_mgr02_amber_get_disp_content_status());
  #else
    return(hmi_gfx_mgr02_imxrt_get_disp_content_status());
  #endif
}
#endif
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_get_front_fb
Description          : Returns the front frame buffer of the widget
Invocation           : Invoked by Presentation logic
Return Value         : Frame buffer address
Critical Section     : None
Parameters           : Client ID
******************************************************************************/
void * hmi_gfx_mgr02_layout_get_front_fb(GFX_UINT client_id)
{
    return(hmi_gfx_mgr02_context_get_front_fb(client_id));
}
#endif

#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_set_text_special_effects_prop
** Visibility:       global
** Description:      Sets the text element special effects properties for  
**                   the passed text element.
** Invocation:       Invoked by if_layer/application
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          ---
** Updated:          ---
**==========================================================================*/
UINT32 hmi_gfx_mgr02_layout_set_text_special_effects_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_TXT_SPECIAL_EFFECTS * p_obj_effects) 
{
   GUI_GFX_MGR_ERROR_CODE_T fl_return_result = GUI_GFX_MGR_BAD_HANDLE_ERROR;
   UINT32 fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_id);
   UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID(p_elem_id);
   UINT32 fl_width_change = (UINT32)FALSE;

   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_id))
   {
      if(((fl_obj_type == GFX_MGR02_TYPE_STEXT) || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)) &&
         (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
      {
         GFX_MGR02_TEXT_DYN_PROPERTY * fl_text_dyn_prop_SP = &l_gfx_mgr02_anim_data_S.text_prop[fl_prop_index_u32];
         
         if(fl_text_dyn_prop_SP->txt_special_effects.effect_type != p_obj_effects->effect_type)
         {
           fl_text_dyn_prop_SP->txt_special_effects.effect_type = p_obj_effects->effect_type;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
          fl_width_change = (UINT32)TRUE;
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
           if(p_obj_effects->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
           {
             if((p_obj_effects->bold_percentage >= VALID_TXT_BOLD_PERCENTAGE_RANGE_START) &&
                (p_obj_effects->bold_percentage <= VALID_TXT_BOLD_PERCENTAGE_RANGE_END))
             {
               fl_text_dyn_prop_SP->txt_special_effects.bold_percentage = p_obj_effects->bold_percentage;
               fl_return_result = GUI_GFX_MGR_NO_ERROR;
               fl_width_change = (UINT32)TRUE;
             }
           }
           else if((p_obj_effects->effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT) || (p_obj_effects->effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT))
           {
             if((p_obj_effects->otl_width >= VALID_TXT_OTL_WIDTH_RANGE_START)     &&
                (p_obj_effects->otl_width <= VALID_TXT_OTL_WIDTH_RANGE_END)       &&
                (p_obj_effects->otl_opacity >= VALID_TXT_OTL_OPACITY_RANGE_START) &&
                (p_obj_effects->otl_opacity <= VALID_TXT_OTL_OPACITY_RANGE_END))
             {
                fl_text_dyn_prop_SP->txt_special_effects.otl_width = p_obj_effects->otl_width;
                fl_text_dyn_prop_SP->txt_special_effects.otl_opacity = p_obj_effects->otl_opacity;
                fl_return_result = GUI_GFX_MGR_NO_ERROR;
                fl_width_change = (UINT32)TRUE;
             }
           }
           else if(p_obj_effects->effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT)
           {
             if(((p_obj_effects->shadow_bg_col & VALID_TXT_SHADOW_COLOR) != 0U) &&
                (p_obj_effects->shadow_x >= VALID_TXT_SHADOW_XY_RANGE_START)    &&
                (p_obj_effects->shadow_x <= VALID_TXT_SHADOW_XY_RANGE_END)      &&
                (p_obj_effects->shadow_y >= VALID_TXT_SHADOW_XY_RANGE_START)    &&
                (p_obj_effects->shadow_y <= VALID_TXT_SHADOW_XY_RANGE_END))
             {
               fl_text_dyn_prop_SP->txt_special_effects.shadow_bg_col = p_obj_effects->shadow_bg_col;
               fl_text_dyn_prop_SP->txt_special_effects.shadow_x = p_obj_effects->shadow_x;
               fl_text_dyn_prop_SP->txt_special_effects.shadow_y = p_obj_effects->shadow_y;
               fl_return_result = GUI_GFX_MGR_NO_ERROR;
               fl_width_change = (UINT32)TRUE;
             }
           }
           else
#endif
           {
             if(p_obj_effects->effect_type <= GFX_MGR02_TXT_INVALID_EFFECT)
             {
               fl_return_result = GUI_GFX_MGR_NO_ERROR;
             }
           }
         }
         else if((p_obj_effects->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)             ||
                 (p_obj_effects->effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT)      ||
                 (p_obj_effects->effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT)  ||
                 (p_obj_effects->effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT))
         {
           #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
           if((fl_text_dyn_prop_SP->txt_special_effects.bold_percentage != p_obj_effects->bold_percentage) &&
              (p_obj_effects->bold_percentage >= VALID_TXT_BOLD_PERCENTAGE_RANGE_START)                    &&
              (p_obj_effects->bold_percentage <= VALID_TXT_BOLD_PERCENTAGE_RANGE_END))
           {
             fl_text_dyn_prop_SP->txt_special_effects.bold_percentage = p_obj_effects->bold_percentage;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
             fl_width_change = (UINT32)TRUE;
           }
           if((fl_text_dyn_prop_SP->txt_special_effects.otl_width != p_obj_effects->otl_width) &&
              (p_obj_effects->otl_width >= VALID_TXT_OTL_WIDTH_RANGE_START)                    &&
              (p_obj_effects->otl_width <= VALID_TXT_OTL_WIDTH_RANGE_END))
           {
             fl_text_dyn_prop_SP->txt_special_effects.otl_width = p_obj_effects->otl_width;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
             fl_width_change = (UINT32)TRUE;
           }
           if((fl_text_dyn_prop_SP->txt_special_effects.otl_opacity != p_obj_effects->otl_opacity) &&
              (p_obj_effects->otl_opacity >= VALID_TXT_OTL_OPACITY_RANGE_START)                    &&
              (p_obj_effects->otl_opacity <= VALID_TXT_OTL_OPACITY_RANGE_END))
           {
             fl_text_dyn_prop_SP->txt_special_effects.otl_opacity = p_obj_effects->otl_opacity;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
           }
           if((fl_text_dyn_prop_SP->txt_special_effects.shadow_bg_col != p_obj_effects->shadow_bg_col) &&
              ((p_obj_effects->shadow_bg_col & VALID_TXT_SHADOW_COLOR) != 0U))
           {
             fl_text_dyn_prop_SP->txt_special_effects.shadow_bg_col = p_obj_effects->shadow_bg_col;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
           }
           if((fl_text_dyn_prop_SP->txt_special_effects.shadow_x != p_obj_effects->shadow_x) &&
              (p_obj_effects->shadow_x >= VALID_TXT_SHADOW_XY_RANGE_START)                   &&
              (p_obj_effects->shadow_x <= VALID_TXT_SHADOW_XY_RANGE_END))
           {
             fl_text_dyn_prop_SP->txt_special_effects.shadow_x = p_obj_effects->shadow_x;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
             fl_width_change = (UINT32)TRUE;
           }
           if((fl_text_dyn_prop_SP->txt_special_effects.shadow_y != p_obj_effects->shadow_y) &&
              (p_obj_effects->shadow_y >= VALID_TXT_SHADOW_XY_RANGE_START)                   &&
              (p_obj_effects->shadow_y <= VALID_TXT_SHADOW_XY_RANGE_END))
           {
             fl_text_dyn_prop_SP->txt_special_effects.shadow_y = p_obj_effects->shadow_y;
             fl_return_result = GUI_GFX_MGR_NO_ERROR;
             fl_width_change = (UINT32)TRUE;
           }
           #endif
         }
         else
         {
           /* Do nothing */
         }
         if(fl_width_change == (UINT32)TRUE)
         {
          #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
           GFX_MGR02_TEXT_PROPERTY const * fl_text_canim_prop_SP = &lc_text_anim_property_S[fl_prop_index_u32];
           GFX_MGR02_TEXT_DEF_T    const * fl_text_layer_prop_SP = &lc_text_layer_def_S[fl_text_canim_prop_SP->base_id];
           if((fl_text_layer_prop_SP->max_num_of_lines > (UINT16)1) &&
              (fl_text_layer_prop_SP->dynamic != (UINT8)0))
           {
             hmi_gfx_mgr02_set_multiline_data_modified(fl_text_layer_prop_SP, TRUE);
           }
          #endif
         }
         if(fl_return_result == GUI_GFX_MGR_NO_ERROR)
         {
           GFX_MGR02_SET_FLAG(l_text_anim_elem_changed_flag_U8A, fl_prop_index_u32);
         }
      }
   }
   GFX_MGR02_VERIFY_LAYOUT_API_CALL
   return((UINT32)fl_return_result);
}
#endif /* #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) */
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_get_num_drecs
Description          : Returns the number of dirty rectangle
Invocation           : Invoked by Application
Return Value         : UINT32
Critical Section     : None
Parameters           : None
******************************************************************************/

UINT32 hmi_gfx_mgr02_layout_get_num_drecs(void)
{
    UINT32 fl_num_rect= hmi_gfx_mgr02_dar_get_num_drects();
    return( fl_num_rect);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_get_num_drecs
Description          : Returns the sx,sy, ex and ey of the dirty rectangle of the passed index.
Invocation           : Invoked by Application
Return Value         : GFX_MGR02_VISIBLE_AREA
Critical Section     : None
Parameters           : UINT32:index
******************************************************************************/

GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_layout_get_drect(UINT32 p_index)
{
    GFX_MGR02_VISIBLE_AREA * fl_drect_SP;
    fl_drect_SP = hmi_gfx_mgr02_dar_get_drect(p_index);
    return(fl_drect_SP);
}
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_get_capture_init_status
Description          : Returns the initialisation status of the capture video module
Invocation           : Invoked by Application
Return Value         : GFX_MGR02_CAPTURE_INIT_STATUS
Critical Section     : None
Parameters           : None
******************************************************************************/
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_layout_get_capture_init_status(void)
{
  GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status;
  fl_init_status = hmi_gfx_mgr02_get_capture_init_status();
  return(fl_init_status);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_set_frame_capture_done_status
Description          : Sets the frame capture status
Invocation           : 1. Invoked by GdtCdd where mipi interrupt registered.
                       2. Application can use this to force shutdown the video capture unit
                       with value 0xFF to free video memory when not required 
Return Value         : None
Critical Section     : None
Parameters           : UINT8: status 
******************************************************************************/
void hmi_gfx_mgr02_layout_set_frame_capture_done_status(UINT8 p_val)
{
  l_tv2_mipi_csi2_frame_capture_done = p_val;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_get_frame_capture_done_status
Description          : Returns the frame capture status
Invocation           : Invoked by Application
Return Value         : UINT8: status
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT8 hmi_gfx_mgr02_layout_get_frame_capture_done_status(void)
{
  return(l_tv2_mipi_csi2_frame_capture_done);
}
#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_set_display_property
Description          : calls hmi_gfx_mgr02_tv2_set_display_property from layout
Invocation           : invoked in GdtCdd should not be called from application
Return Value         : void
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_layout_set_display_property(CYGFX_DISP_ATTR p_attr_name, CYGFX_U32 p_val)
{
  hmi_gfx_mgr02_tv2_set_display_property(p_attr_name, p_val);
}
#endif
#endif /* #ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED */

#if (defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_USE_TIDSS))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_layout_set_dss_pipeline_alpha
Description          : Set alpha for display pipeline
Invocation           : Invoked by Presentation logic
Return Value         : driver return value
Critical Section     : None
Parameters           : disp id, pipeline id, alpha value
******************************************************************************/
SINT32 hmi_gfx_mgr02_layout_set_dss_pipeline_alpha(UINT8 p_disp_id, UINT8 p_pipeline_id, GFX_MGR02_ALPHA p_alpha)
{
  GFX_MGR02_VERIFY_LAYOUT_API_CALL
  return ((SINT32)hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha((uint8_t)p_disp_id, (uint8_t)p_pipeline_id, (uint8_t)p_alpha));
}
#endif

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date            By
** CMS Rev X.X      dd-mmm-yyyy     CDSID
**
**============================================================================
** CMS Rev 1.95      6-Apr-2018    SBOLLAM
** 1056323: GMC-HUD: gfx_mgr changes for zero width chars rendering support 
**          with freetype font engine and GSUB process
**
** CMS Rev 1.94      22-Mar-2018    ADEVI
** 1081537: GMC-HUD - Issue fix for FG4_UI: Two CCOI screens shown at once
**
** CMS Rev 1.93      15-Feb-2018    ARAJASE2
** 1035493: GM-CHUD : Fetching the MULTI_LINE_INFO for text with lines > 255
**
** CMS Rev 1.92      01-Feb-2018     ARAJASE2
** Moved l_input_string  variable to GFX02_LAYOUT_RW_DATA section
** Ref Task : 1047346: GM-CHUD - GDT Integration Issues
**
** CMS Rev 1.91      19-Dec-2017     SBOLLAM
** Added Harfbuzz and WorldType shape engine support.
** Ref Task : 978896
**
** CMS Rev 1.90      29-Nov-2017    SBOLLAM
** 994945: Integrated WTLE shape engine.
**
** CMS Rev 1.89     30-Nov-2017    ARAJASE2
** 1005357: Graphics Manager update for Hebrew Text rendering
** Enabled existing arabic related code for GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED macro also.
** Renamed the following functions since it supports both arabic and Hebrew(RTL - Right to Left)
** hmi_gfx_mgr02_arabic_multiline_algorithm --> hmi_gfx_mgr02_RTL_multiline_algorithm
** hmi_gfx_mgr02_run_arabic_multiline_algorithm --> hmi_gfx_mgr02_run_RTL_multiline_algorithm
**
** CMS Rev 1.88     18-Sep-2017    ADEVI
** 955614: Multi-line Scroll Optimization And Max lines increased.
** 
** CMS Rev 1.87     18-Sep-2017    ARAJASE2
** 921462: Dynamic Font update issue in Amber platform with External font
** GFX_MGR02_TEXT_INFO and GFX_MGR02_TEXT_WIDTH_INFO structures are updated to add new memer
** GFX_MGR02_FONT_SIZE_T font_size;
** hmi_gfx_mgr02_layout_get_text_width and hmi_gfx_mgr02_layout_get_text_width_ext functions
** are updated to use this new member
** Mutiline support functions are updated to update font size in the multiline param
** Multiline algorithm is invoked in hmi_gfx_mgr02_layout_set_font function
**
** CMS Rev 1.86      6-Sep-2017    ADEVI
** 948804: Amber driver run time recovery implementation.
**
** CMS Rev 1.85     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.84     23-Aug-2017    ADEVI
** 929657: Dynamic Text Width Change
** 
** CMS Rev 1.83      08-Aug-2017    ARAJASE2
** Added new function hmi_gfx_mgr02_layout_set_inter_line_spacing to support dynamic update
** of inter line spacing
** 922409: Dynamic Inter-line spacing for multi-line text
**
** CMS Rev 1.82    29-Jun-2017    SSRINI19
** 880883 : GM-CHUD QAC MISRA additional warning fixes
**
** CMS Rev 1.81     06-JUL-2017    ADEVI
** RTC ID: 871825:  Changes to support MONOTFT Platform
**
** CMS Rev 1.80    09-Jun-2017    SSIGAMAN
** 853909: GDT - Right alighned texts are displayed to the right of DrawPoint.
** Fix: Texts x position is modified based on the current and original alignment.
**
** CMS Rev 1.79    18-Apr-2017    SSRINI19
** 846153: GM-CHUD- QAC warning fixes
** 
** CMS Rev 1.78     12-Apr-2017    ADEVI
** 829051: Amber:Multi line feature integration
**
** CMS Rev 1.77     04-April-2017    SSIGAMAN
** 816744: Update GDT to allow configurable warping data
** Changes done to consider warptable change to rebuild the elements.
**
** CMS Rev 1.76     07/02/2016    SBOLLAM
** RTC ID: 750237: Updated error logging capability and added
**                 OVG software recovery capability
**
** CMS Rev 1.75      7-Feb-2017    SSIGAMAN
** 798244: GM-CHUD: identifier "l_wdg_anim_elem_changed_flag_U8A" is undefined
**         when no widget with Anim=TRUE and warping feature enabled.
** Fix:    Added conditional compilation part to avoid the access of the function
**         if no widget with Animation equal to TRUE.
**

** CMS Rev 1.74      10-Feb-2017    KKUBENDI
** 800730: GfxMgr02/Luxoft: Change type of "string_index" in GFX_MGR02_TEXT_DEF_T from UINT16 to UINT32
**
** CMS Rev 1.73      16-DEC-2016    EMANOJ1
** Faraday Future - Incorrect object reported as touched (RTC : 767355)
** hmi_gfx_mgr02_layout_check_touch_point() updated 
** 1. to add an option to dynamically calculate the touch object area for touch validation.
** 2. to break the loop when the final path is reached in the case of a dynamci widget.
**    Done by placing fl_sel_elem_SP = GFX_MGR02_NULL_PTR; outside the loop 
** Faraday Future - Touch object auto selection does not work (RTC : 767349)
** hmi_gfx_mgr02_context_begin_update() function was finding and locking the next
** available framebuffer. But when the dirty area initial processing is done, it was
** resulting in unnecessarily locking the framebuffer, causing the updates to be not
** happening. So a parameter is added to begin update to specify whether a lock is needed
** or not. 
**
** CMS Rev 1.72      02-NOV-2016    APERUMAL
** 735553: Porsche Misra warnings fixes
**
** CMS Rev 1.71      26-Aug-2016    ADEVI
** 656058: Arabic hard cut multi line requirements implementaion
**
** CMS Rev 1.70      25-Aug-2016    SANAND2
** 679532: QAC warnings fix for Arabic multi line implementaion - Part II
** 
** CMS Rev 1.69      18-Aug-2016    CMUTHUSA
** 674040: Right Alignment in Arabic Layout moves the Textbox out of range
**
** CMS Rev 1.68      28-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.67     28-JULY-2016    SANAND2
** 641381: Arabic multi line changes PR defect fix.
**
** CMS Rev 1.66     27-JULY-2016    SANAND2
** 641381: Arabic multi line changes.
**
** CMS Rev 1.65     22-July-2016    ADEVI
** 623405: Arabic multi line algorithm changes.
**
** CMS Rev 1.64     July-2016    ADEVI
** 610788: Multi - line data saved and new line requirement changes.
**
** CMS Rev 1.63     08-JULY-2016    SSIGAMAN
** 639042: Porsche Misra warning Fix
**
** CMS Rev 1.62     03-June-2016    SSIGAMAN
** 611785: Compiler Warnings after THAI Lang Integration in Turing
**
** CMS Rev 1.61     02-June-2016    CSAKTHIV
** 566848 Thai support using GSUB table 
**
** CMS Rev 1.60     11-May-2016    SSIGAMAN
** 592820: Turing Coverity Warning Fix for ui.core.gdt
**
** CMS Rev 1.59      28-Apr-2016    ADEVI
** 546876: Dynamic horizontal clip for widgets
** Add support to change the Text Size Dynamically when Font Engine is used.
** 
** CMS Rev 1.58      04-Apr-2016    SBOLLAM
** 558616: Dynamic horizontal clip for widgets
** Added a new interface <hmi_gfx_mgr02_layout_set_obj_hclip>
** CMS Rev 1.57      05-Mar-2016    CSAKTHIV
** 564659 for B515 Theme. Interface added to force screen change.
**
** CMS Rev 1.56      24-Mar-2016    SVIKRAM
** 521380: Coverity issue fix
**
** CMS Rev 1.55     19-Feb-2016    SSIGAMAN
** RTC 527167: Fill with anim enabled not rendering in merge widget 
** The matrix for the animation is not updated for the fill. 
** So, endedup having 3x3 matrix with all of it elements equal to 0.
**
** CMS Rev 1.54     15-Feb-2016    ADEVI         RTC 494789
** Multi line text Implementation - NEW FORD requirements.
**
** CMS Rev 1.53     29-Jan-2016    APERUMAL
** RTC 507885:
** QAC warnings fix for Honda Thaa
**
** CMS Rev 1.52     28-Oct-2015    ADEVI         RTC 412568
** Multi line text Implementation - Initial Version.
**
** CMS Rev 1.54     27-Oct-2015   SSIGAMAN
** Ref RTC# 443671
** Changes to support XY animation for merge widget of Amber platform .
** 
** CMS Rev 1.53     13-Oct-2015   SSIGAMAN
** Ref RTC# 437002.
** Add support for 8BPP frame buffer for Amber platform
**
** CMS Rev 1.52     01-Oct-2015   APERUMAL
** Ref RTC# 434948
** Compiler warning fix for Porsche
**
** CMS Rev 1.51     25-Sep-2015   APERUMAL
** Ref RTC# 430656
** Removed the dummy function hmi_gfx_mgr02_layout_set_data_mode to fix QA C 
** warning for Honda Thaa.
**
** CMS Rev 1.50     28-Jul-2015   EMANOJ1
** Ref RTC# 388950
** Updated hmi_gfx_mgr02_layout_push_touch_event & hmi_gfx_mgr02_layout_pop_touch_event
** functions to fix a data corruption issue due to improper mutex usage.
**
** CMS Rev 1.49     23-Jul-2015   ARAJASE2
** 380645: W207 Compiler warnings 
** Compiler warning fix for W207 
**
** CMS Rev 1.48     07-Jul-2015   EMANOJ1
** Ref RTC# 373900.
** To support Gesture events
**
** CMS Rev 1.47     02-Apr-2015   EMANOJ1
** Ref RTC# 317729.
** Touch area is offsetted when _set_obj_pos_x() api is called with object id
** of 255.
** Screen animation index was compared against GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS
** and GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS had a value > 255. anim_index is UINT8 
** and the invalid index was generated as 255. So this comparison got true and 
** always read the 255th index of group_loc[] location
** Fix : comparison made against GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS rather than
** GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS.
** if(fl_screen_def_SP->anim_index < GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)
**
** CMS Rev 1.46     5-Feb-2015    ADEVI
** Ref RTC: 282879
** hmi_gfx_mgr02_layout_set_screen_dyn_priority interface added.

** CMS Rev 1.45     24-Nov-2014    ADEVI
** Ref RTC: 204201
** hmi_gfx_mgr02_layout_set_text_scroll_parameter argument clip mode removed.
** In hmi_gfx_mgr02_layout_reset_text_anim_prop, the scroll offset is reset.
**
** CMS Rev 1.44     17-Nov-2014    ADEVI
** Ref RTC: 227142
** Tile animation macros for rotation support corrected.
**
** CMS Rev 1.43     13-Nov-2014    ADEVI
** Ref RTC# 239784.
** In hmi_gfx_mgr02_layout_build_screen #ifdefined GFX_MGR02_AMBER check added.
**
** CMS Rev 1.42     11-Nov-2014    ADEVI
** Ref RTC# 204201.
** hmi_gfx_mgr02_layout_set_text_scroll_parameter function added to set the 
** scroll offset value and clip mode during scroll.
**
** CMS Rev 1.41     10-Nov-2014    EMANOJ1
** Compiler error fixes in rotation macro addition
**
** CMS Rev 1.40     30-Oct-2014    ADEVI
** Ref RTC: 227142
** For rotation support all the CHECK macros modified with GET macros
**
** CMS Rev 1.39     16-Oct-2014    EMANOJ1
** Ref RTC# 214249
** In hmi_gfx_mgr02_layout_freeze_touch_event,ex and ey values changed from -1 to -2 
** to differentiate between out of bound and freeze
**
** CMS Rev 1.38     03-Oct-2014    EMANOJ1
** Ref RTC# 214249, 211516, 126581
** hmi_gfx_mgr02_layout_freeze_touch_event function added to freeze further touch 
** events for active button (for usage while switching layouts). 
**
** CMS Rev 1.37     01-Sep-2014    EMANOJ1
** l_cntx_init_pending flag is protected by new configuration item 
** GFX_MGR02_INLINE_INIT to allow control by application
** 
** CMS Rev 1.36     20-Aug-2014    EMANOJ1
** RTC task#196620 : GFX02_LAYOUT_RW_DATA segment added to allow application 
** to relocate l_gfx_mgr02_anim_data_S and l_dynamic_text_buffer to user 
** defined memory section.
**
** CMS Rev 1.35     25-Jul-2014    EMANOJ1
** hmi_gfx_mgr02_layout_process_touch_events function made public and its 
** invocation from hmi_gfx_mgr02_layout_build_screen() removed, so that
** unnecessary build screen is not performed due to touch event processing
** Now hmi_gfx_mgr02_layout_process_touch_events will be done by IF and
** it will decide whether to schedule a hmi_gfx_mgr02_layout_build_screen()
**
** CMS Rev 1.34     19-May-2014    EMANOJ1
** hmi_gfx_mgr02_layout_validate_layer_area() updated to fix a coverity issue.
**
** CMS Rev 1.33     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.33     21-Apr-2014    NKRISHN9
** Animation engine is initialize during graphics start up(ACTIVATION EV)
**
** CMS Rev 1.32     19-Mar-2014    EMANOJ1
** Added api hmi_gfx_mgr02_layout_get_char_metrics to get the font metrics
**
** CMS Rev 1.31     20-Feb-2014    EMANOJ1
** Updated to fix RTC 121262 (touch events on low priority screens)
**
** CMS Rev 1.30     31-Jan-2014    EMANOJ1
** Compiler error in hmi_gfx_mgr02_layout_reset_svg_anim fixed (RTC : 117960)
**
** CMS Rev 1.29     29-Jan-2014    EMANOJ1
** RTC workitem = 116968
** Fixed an issue of p_touch_pt_path_U8P incrementing twice whch was causing
** invalid touch element ID to be passed to application.
**
** CMS Rev 1.28     02-Jan-2014    EMANOJ1
** hmi_gfx_mgr02_layout_set_obj_default_properties and related sub functions 
** updated to set the element changed flag only if there is a difference in
** current and default properties. This is to avoid causing a rebuild incase
** where the application calls this API back to back or in every presentation
** cycle.
**
** CMS Rev 1.27     11-Nov-2013    EMANOJ1
** Reverted 1.26 change as it was suggested to be not really needed. So to keep
** the API same the change is reverted.
**
** CMS Rev 1.26     09-Nov-2013    EMANOJ1
** hmi_gfx_mgr02_layout_get_text_width updated to consider the append bool
** flag for text width calculation.
**
** CMS Rev 1.25     31-Oct-2013    EMANOJ1
** OpenVG init was consuming more time (order of few 10 mSec) and there fore
** affecting DI startup time. So the context init was now being scheduled from
** Graphics task to minimize the startup time.
**
** CMS Rev 1.24     22-Oct-2013    EMANOJ1
** Renamed hmi_gfx_mgr02_layout_dcu_is_element_changed to
** hmi_gfx_mgr02_layout_is_element_childrens_changed as it is now required for 
** non DCU version as well. Done to fix an issue related to aligned widget
** update issue when dirty region redraw is enabled.
**
** CMS Rev 1.23     11-Sep-2013    EMANOJ1
** Image getting hide issue in P552 fixed.
** hmi_gfx_mgr02_layout_set_obj_vclip updated to consider the current clip
** location in to account while calculating the clip rectangle from the vclip
** paramters. vlcip parameter always starts from 0 to height of the object
** the zero needs to be mapped to the current clip rectangle.
**
** CMS Rev 1.22     19-Aug-2013    EMANOJ1
** Added a target parameter for text width calculation and printing as the 
** text.c has been updated to utilize this parameter.
**
** CMS Rev 1.21     14-Aug-2013    EMANOJ1
** Fixed compiler switch usage related to user type image.
** Fixed an issue with touch button handling where background operations were 
** getting triggered. For example if priority 0 screen has touch enabled areas
** and priority 1 screen also got some touch areas. Now if the user touches
** in an inactive area of priotiy 1 screen, the press was getting passed to
** priority 0 and if the press was causing actions in priority 0. idealy
** the butoon shouldn't have been passed priority 0 at all.
** Now the fix is done to stop the button processing once a screen with
** touch button is processed regardless of the button falls in to an
** activie area or not.
**
** CMS Rev 1.20     10-Jul-2013    EMANOJ1
** hmi_gfx_mgr02_layout_validate_layer_area() updated to fix an issue where an 
** element with "0" alpha still remained active on display.
**
** CMS Rev 1.19     04-Jul-2013    EMANOJ1
** Logic to find changes in matrix so that rebuild is triggered only on change
**
** CMS Rev 1.18     21-Jun-2013    EMANOJ1
** hmi_gfx_mgr02_layout_dcu_is_element_changed updated fix an issue where a 
** widget containing a dynamic image/dynami widget has changed a proprty but
** rebuild was not getting triggered due to missing of logic to detect this
** change.
**
** CMS Rev 1.17     18-Jun-2013    EMANOJ1
** Added l_wdg_anim_dcu_changed_flag_U8A to support rebuilding of DCU widgets
** layer if clip X or width is getting changed.
**
** CMS Rev 1.16     18-Jun-2013    EMANOJ1
** Reworked pre-render, memory allocation operations to makesure we don't 
** rebuild GRAM contents if the change is in the parent which can be applied
** directly to DCU layers example if the position of the parent objects
** changes, it need not be rebuilt again we could just program the DCU layers 
** to make the operations faster. hmi_gfx_mgr02_layout_dcu_is_element_changed
** function updated to look for changes that requires rebuild.
** TODO : if any of the non DCU properties get changed at parent level
**        what would we need to do? currently these changes does not trigger
**        a rebuild (e.g transformations, clip area etc)
**
** CMS Rev 1.15     12-Jun-2013    EMANOJ1
** right2left handling added with the help of GFX_MGR02_GALIGNMENT()
**
** CMS Rev 1.14     10-Jun-2013    EMANOJ1
** Added interface to set/get font group properties, text element properties
**
** CMS Rev 1.13     28-May-2013    EMANOJ1
** hmi_gfx_mgr02_layout_dcu_is_element_changed() function updated to correctly
** return the lement status when the change is in a child element. In the process
** optimized the element change implementation to reuse existing function
** hmi_gfx_mgr02_layout_is_element_changed and to remove unnecessary code.
**
** CMS Rev 1.12     17-May-2013    EMANOJ1
** hmi_gfx_mgr02_layout_reset_anim_flags called after hmi_gfx_mgr02_layout_process_touch_events
** was causing an issue where the hmi_gfx_mgr02_layout_process_touch_events was
** calling an application call back through which application changed anim paramers.
** Now the hmi_gfx_mgr02_layout_reset_anim_flags sequenced after this will clear 
** the object changed flag and will result in the change not getting reflected.
** To fix this the sequence is reversed.
** The touch co-ordinate calculation and evaluation was happening wrongly when the 
** object was moved. For now a hack is done and need to fully evaluate various 
** possible usecases.
**
** CMS Rev 1.11     15-May-2013    EMANOJ1
** Added support for dirty area redraw. Functions updated to provide element change
** status correctly.
**
** CMS Rev 1.10     03-May-2013    EMANOJ1
** Issue with detection of touch event was fixed. Updated the function
** hmi_gfx_mgr02_layout_process_touch_event to call the context_begin_update
** function to set the clip area correctly. Earlier the clip area used was the
** previously set value and this will result in sporadic failure of the detection
**
** CMS Rev 1.9      19-Apr-2013    EMANOJ1
** Set area and dim updated to update widget clip area. Added get functions for
** area and dim
**
** CMS Rev 1.8      08-Apr-2013    EMANOJ1
** hmi_gfx_mgr02_layout_process_touch_events and hmi_gfx_mgr02_layout_check_touch_point
** updated to pass the GFX_MGR02_TOUCH_QDATA structure pointer itself to 
** application to allow app to also get the touch co-ordinate information. 
** Added GFX_MGR02_MOUSE_OUTOF_BOUND flag handling to indicate that the touch point
** went outside the bound of the element.
**
** CMS Rev 1.7      03-Apr-2013    ASHEKHAR
** QAC Warnings resolved 
**
** CMS Rev 1.6      26-Mar-2013    EMANOJ1
** Compiler issues related to context when OpenVg and SWR are not used is 
** resolved
**
** CMS Rev 1.5      22-Mar-2013    VMUTHUSU
** Change NULL_PTR to GFX_MGR02_NULL_PTR
**
** CMS Rev 1.4      20-Mar-2013    EMANOJ1
** Added interface to expose matrix multiplication function. Fixed issue in
** hmi_gfx_mgr02_layout_set_obj_rotate(). Added function to read the default
** object matrix (hmi_gfx_mgr02_layout_get_def_obj_transformation())
** Compiler issue fixes
** hmi_gfx_mgr02_layout_reset_svg_anim() function updated
**
** CMS Rev 1.3      15-Mar-2013    ASHEKHAR
** Updated compiler switches to make it work for different combinations
**
** CMS Rev 1.2      05-Nov-2012     ASHEKHAR
** Implement the new interfaces required for Layout Manager.
**
** CMS Rev 1.1      23-Sep-2012     VMUTHUSU
** Implement the new interfaces required for Layout Manager.
**
** CMS Rev 1.0      09-Aug-2012     EMANOJ1
** Creation.
**==========================================================================*/
#ifdef  __cplusplus
}
#endif
#endif
/* end of file =============================================================*/
