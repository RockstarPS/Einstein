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
 ** Name:           hmi_gfx_mgr02_generic.c
 **
 ** Description:    Rendering routine for the generic target.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_GENERIC_C
#define HMI_GFX_MGR02_PRIV_C 

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_SOFTWARE) ||defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)|| defined (GFX_MGR02_TRAVEO2)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_dirty_area.h"
#ifdef GFX_STRING_CACHE_ENABLED
#include "hmi_gfx_mgr02_cache.h"
#endif

#if defined(GFX_MGR02_SOFTWARE)
#include "hmi_gfx_mgr02_swrlib.h"
#endif
#if defined(GFX_MGR02_MONOTFT)
#include "hmi_gfx_mgr02_monolib.h"
#endif

#if defined(GFX_MGR02_OPEN_VG)
#include "hmi_gfx_mgr02_ovglib.h"
#endif

#if defined(GFX_MGR02_OPEN_GL)
#include "hmi_gfx_mgr02_ogllib.h"
#endif

#if defined(GFX_MGR02_FUJITSU)
#include "hmi_gfx_mgr02_irislib.h"
#endif

#if defined(GFX_MGR02_AMBER)
#include "hmi_gfx_mgr02_amber.h"
#endif

#if defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
#include "hmi_gfx_mgr02_amber_iris.h"
#endif
#if defined (GFX_MGR02_TRAVEO2)
#include "hmi_gfx_mgr02_tv2.h"
#include "hmi_gfx_mgr02_tv2_iris.h"
#endif

#if defined(GFX_MGR02_IMXRT)
#include "hmi_gfx_mgr02_imxrt.h"
#endif

#if defined(GFX_MGR02_IMXRT)|| defined(GFX_MGR02_IMXRT_PXP)
#include "hmi_gfx_mgr02_imxrt_pxp.h"
#endif

#if defined(GFX_MGR02_VGLITE)
#include "hmi_gfx_mgr02_vglite.h"
#endif

#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_perflog.h"

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
#include "hmi_gfx_mgr02_capture_video.h"
#endif


#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

typedef struct
{
    s_gx_flocal (*init)(void);
    s_gx_flocal (*shutdown)(void);
    s_gx_flocal (*build_start)(GFX_MGR02_CONTEXT_T const *p_cntx_SP);
    s_gx_flocal (*build_image)(GFX_MGR02_CONTEXT_T const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
    s_gx_flocal (*build_uimage)(GFX_MGR02_CONTEXT_T const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
    s_gx_flocal (*build_fill)(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
  #if GFX_MGR02_NUM_OF_TILES > 0
    s_gx_flocal (*build_tile)(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_TILE_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim);
  #endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    s_gx_flocal (*build_text)(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width, u_gx_flocal p_is_multi_line_text
                                                                                                      #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                                                       ,UINT16 p_ml_str_index
                                                                                                      #endif
                                                                                                       );
#else
    s_gx_flocal (*build_text)(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width);
#endif
#if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_VGLITE) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    s_gx_flocal (*build_svg)(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_OVG_OBJECT_T  const *p_elem_def_SP);
#endif
#if defined(GFX_MGR02_FUJITSU) && defined(GFX_MGR02_IRIS_PIXEL_POKING)
    s_gx_flocal (*build_finish)(GFX_MGR02_CONTEXT_T  const *p_cntx_SP);
#else
    s_gx_flocal (*build_finish)(void);
#endif
    s_gx_flocal (*get_bound)(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const *p_cntx_SP , GFX_FLOAT *p_bounds);
    s_gx_flocal (*clear_buffer)(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
#if defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2) 
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
    s_gx_flocal (*build_video)(GFX_MGR02_CONTEXT_T const *p_cntx_SP , GFX_MGR02_VIDEO_DEF_T const *p_elem_def_SP);
#endif
#endif
}GFX_MGR02_LIB_CB_LIST_T;


/*
** Possible target libraries supported by the generic target
*/
#define GFX_MGR02_GEN_CUR_TARGET_INDEX     (-1)
#if !defined(GFX_MGR02_SOFTWARE)
 #define GFX_MGR02_GEN_TARGET_SWR  (GFX_MGR02_GEN_CUR_TARGET_INDEX)
#else
 #define GFX_MGR02_GEN_TARGET_SWR  (GFX_MGR02_GEN_CUR_TARGET_INDEX+1)
#endif
#if !defined(GFX_MGR02_OPEN_VG)
 #define GFX_MGR02_GEN_TARGET_OVG  (GFX_MGR02_GEN_TARGET_SWR)
#else
 #define GFX_MGR02_GEN_TARGET_OVG  (GFX_MGR02_GEN_TARGET_SWR+1)
#endif
#if !defined(GFX_MGR02_OPEN_GL)
 #define GFX_MGR02_GEN_TARGET_OGL  (GFX_MGR02_GEN_TARGET_OVG)
#else
 #define GFX_MGR02_GEN_TARGET_OGL  (GFX_MGR02_GEN_TARGET_OVG+1)
#endif
#if !defined(GFX_MGR02_FUJITSU)
 #define GFX_MGR02_GEN_TARGET_FJU  (GFX_MGR02_GEN_TARGET_OGL)
#else
 #define GFX_MGR02_GEN_TARGET_FJU  (GFX_MGR02_GEN_TARGET_OGL+1)
#endif
#if !defined(GFX_MGR02_AMBER)
 #define GFX_MGR02_GEN_TARGET_ABR  (GFX_MGR02_GEN_TARGET_FJU)
#else
 #define GFX_MGR02_GEN_TARGET_ABR  (GFX_MGR02_GEN_TARGET_FJU+1)
#endif
#if !defined(GFX_MGR02_AMBER_IRIS)
 #define GFX_MGR02_GEN_TARGET_ABR_IRIS  (GFX_MGR02_GEN_TARGET_ABR)
#else
 #define GFX_MGR02_GEN_TARGET_ABR_IRIS  (GFX_MGR02_GEN_TARGET_ABR+1)
#endif
#if !defined(GFX_MGR02_MONOTFT)
 #define GFX_MGR02_GEN_TARGET_MONO      (GFX_MGR02_GEN_TARGET_ABR_IRIS)
#else
 #define GFX_MGR02_GEN_TARGET_MONO      (GFX_MGR02_GEN_TARGET_ABR_IRIS+1)
#endif
#if !defined(GFX_MGR02_IMXRT)
 #define GFX_MGR02_GEN_TARGET_IMXRT      (GFX_MGR02_GEN_TARGET_MONO)
#else
 #define GFX_MGR02_GEN_TARGET_IMXRT      (GFX_MGR02_GEN_TARGET_MONO+1)
#endif
#if !defined(GFX_MGR02_IMXRT_PXP)
 #define GFX_MGR02_GEN_TARGET_IMXRT_PXP      (GFX_MGR02_GEN_TARGET_IMXRT)
#else
 #define GFX_MGR02_GEN_TARGET_IMXRT_PXP      (GFX_MGR02_GEN_TARGET_IMXRT+1)
#endif
#if !defined(GFX_MGR02_VGLITE)
 #define GFX_MGR02_GEN_TARGET_VGLITE      (GFX_MGR02_GEN_TARGET_IMXRT_PXP)
#else
 #define GFX_MGR02_GEN_TARGET_VGLITE      (GFX_MGR02_GEN_TARGET_IMXRT_PXP+1)
#endif
#if !defined(GFX_MGR02_TRAVEO2)
 #define GFX_MGR02_GEN_TARGET_TV2      (GFX_MGR02_GEN_TARGET_VGLITE)
#else
 #define GFX_MGR02_GEN_TARGET_TV2      (GFX_MGR02_GEN_TARGET_VGLITE+1)
#endif

#define GFX_MGR02_GEN_NUM_TARGETS  (GFX_MGR02_GEN_TARGET_TV2+1)
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
#ifndef GFX_MGR02_SCROLL_SPEED_IN_PIXELS_PER_SEC
#define GFX_MGR02_SCROLL_SPEED_IN_PIXELS_PER_SEC 60.0F
#endif
#endif
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

static u_gx_flocal hmi_gfx_mgr02_generic_begin_update(u_gx_flocal p_layer_ID_U8, GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP);
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
static u_gx_flocal hmi_gfx_mgr02_generic_update_dirty_area(u_gx_flocal p_layer_ID_U8, GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP, u_gx_flocal p_layout_dirty_U8);
#else
static u_gx_flocal hmi_gfx_mgr02_generic_update_dirty_area(u_gx_flocal p_layer_ID_U8, GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP);
#endif
#endif
static void hmi_gfx_mgr02_generic_build_group(u_gx_flocal p_num_elements, GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#if GFX_MGR02_NUM_OF_SWDGS > 0
static void hmi_gfx_mgr02_generic_build_aligned_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_obj_dirty_U8);
static void hmi_gfx_mgr02_generic_build_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_obj_dirty_U8);
static u_gx_flocal hmi_gfx_mgr02_get_element_widthinfo(GFX_MGR02_ELEM_LIST_T const * p_elem_SP);
 #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
    static SINT16 hmi_gfx_mgr02_get_element_xposinfo(GFX_MGR02_ELEM_LIST_T const * p_elem_SP);
 #endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
static UINT8 hmi_gfx_mgr02_generic_is_element_right_aligned_text(GFX_MGR02_ELEM_LIST_T const * p_widget_elem_SP);
#endif
#endif

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
static void hmi_gfx_mgr02_generic_build_dimage(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8,  u_gx_flocal p_mask_enabled);
#endif
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
static void hmi_gfx_mgr02_generic_build_image(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8,  u_gx_flocal p_mask_enabled);
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
static void hmi_gfx_mgr02_generic_build_uimage(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#if(GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
static void hmi_gfx_mgr02_generic_build_video(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#endif
#endif

#if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
static void hmi_gfx_mgr02_generic_build_svg(GFX_MGR02_ELEM_LIST_T    const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
static void hmi_gfx_mgr02_generic_build_text(GFX_MGR02_ELEM_LIST_T   const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_text_actual_width, u_gx_flocal p_obj_dirty_U8);
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
static void hmi_gfx_mgr02_generic_build_tile(GFX_MGR02_ELEM_LIST_T   const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
static void hmi_gfx_mgr02_generic_build_fill(GFX_MGR02_ELEM_LIST_T   const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8);
#endif

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
static BOOLEAN hmi_gfx_mgr02_multiline_hardcut_algorithm(u_gx_flocal p_line_break_pos, GFX_MGR02_TEXT_INFO * p_text_info_SP, HMI_CHAR const * p_string,GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM  const * p_dep_param);
static u_gx_flocal hmi_gfx_mgr02_multiline_algorithm(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP, HMI_CHAR  const * p_string, GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM    const* p_dep_param);
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
static u_gx_flocal hmi_gfx_mgr02_RTL_multiline_algorithm(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP, HMI_CHAR  const * p_string, GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const * p_dep_param);
#endif
static GFX_MGR02_TEXT_INFO hmi_gfx_mgr02_get_multiline_text(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, HMI_CHAR const * p_string, u_gx_flocal p_append, u_gx_flocal *p_str_incr_length,GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const* p_dep_param, BOOLEAN p_is_RTL_lang);
static u_gx_flocal hmi_gfx_mgr02_build_multiline_text(GFX_MGR02_CONTEXT_T * p_cntx_SP,GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP,HMI_CHAR  const * p_string,u_gx_flocal p_scroll_offset,u_gx_flocal p_num_of_lines_to_be_displayed, SINT8 p_inter_line_spacing);
static u_gx_flocal hmi_gfx_mgr02_evaluate_prev_multiline_data(GFX_MGR02_TEXT_DEF_T const  * p_elem_def_SP, 
                                                              GFX_MGR02_MULTI_LINE_DATA   * p_multi_line_array, 
                                                              GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM *p_dep_param,
                                                              u_gx_flocal * p_display_lines);
static u_gx_flocal hmi_gfx_mgr02_evaluate_multiline_start_pos(HMI_CHAR const * p_string,
                                                              BOOLEAN          p_is_RTL_lang,
                                                              u_gx_flocal      p_line_start_pos
                                                           #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                              ,GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP
                                                           #endif
                                                              );
#endif

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
#if defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_VGLITE) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU) || (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0)
static GFX_MGR02_LIB_CB_LIST_T const l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_NUM_TARGETS] = 
{
#if defined(GFX_MGR02_SOFTWARE)
    {
        hmi_gfx_mgr02_swrlib_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_swrlib_start,
        hmi_gfx_mgr02_swrlib_build_image,
        hmi_gfx_mgr02_swrlib_build_image,
        hmi_gfx_mgr02_swrlib_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_swrlib_build_tile,
    #endif
        hmi_gfx_mgr02_swrlib_build_text,
    #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_SVGS > 0)
        GFX_MGR02_NULL_PTR,
    #endif  
        hmi_gfx_mgr02_swrlib_finish,
        hmi_gfx_mgr02_swrlib_get_bound,
        GFX_MGR02_NULL_PTR
    },
#endif
#if defined(GFX_MGR02_OPEN_VG)
    {
        hmi_gfx_mgr02_ovglib_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_ovglib_start,
        hmi_gfx_mgr02_ovglib_build_image,
    #if defined(GFX_MGR02_USE_FILESYSTEM)
        hmi_gfx_mgr02_ovglib_build_uimage,
    #else
        hmi_gfx_mgr02_ovglib_build_image,
    #endif
        hmi_gfx_mgr02_ovglib_build_fill,
      #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_ovglib_build_tile,
      #endif
        hmi_gfx_mgr02_ovglib_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)
        hmi_gfx_mgr02_ovglib_build_svg,
    #endif
        hmi_gfx_mgr02_ovglib_finish,
        hmi_gfx_mgr02_ovglib_get_bound,
        hmi_gfx_mgr02_ovglib_clear_buffer
    },
#endif
#if defined(GFX_MGR02_OPEN_GL)
    {
        hmi_gfx_mgr02_ogllib_init,
        hmi_gfx_mgr02_ogllib_shutdown,
        hmi_gfx_mgr02_ogllib_start,
        hmi_gfx_mgr02_ogllib_build_image,
    #if defined(GFX_MGR02_USE_FILESYSTEM)
        hmi_gfx_mgr02_ogllib_build_uimage,
    #else
        hmi_gfx_mgr02_ogllib_build_image,
    #endif
        hmi_gfx_mgr02_ogllib_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_ogllib_build_tile,
    #endif
        hmi_gfx_mgr02_ogllib_build_text,
    #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_SVGS > 0)
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_ogllib_finish,
        hmi_gfx_mgr02_ogllib_get_bound,
        hmi_gfx_mgr02_ogllib_clear_buffer
    },
#endif
#if defined(GFX_MGR02_FUJITSU)
    {
        hmi_gfx_mgr02_irislib_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_irislib_start,
        hmi_gfx_mgr02_irislib_build_image,
        hmi_gfx_mgr02_irislib_build_image,
        hmi_gfx_mgr02_irislib_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_irislib_build_tile,
    #endif
        hmi_gfx_mgr02_irislib_build_text,
    #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_SVGS > 0)
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_irislib_finish,
        hmi_gfx_mgr02_irislib_get_bound,
        GFX_MGR02_NULL_PTR
    },
#endif
#if defined(GFX_MGR02_AMBER)
    {
        hmi_gfx_mgr02_amber_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_amber_start,
        hmi_gfx_mgr02_amber_build_image,
        hmi_gfx_mgr02_amber_build_image,
        hmi_gfx_mgr02_amber_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_amber_build_tile,
    #endif
        hmi_gfx_mgr02_amber_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)	
        hmi_gfx_mgr02_amber_build_svg,
    #endif
        hmi_gfx_mgr02_amber_finish,
        hmi_gfx_mgr02_amber_get_bound,
        hmi_gfx_mgr02_amber_clear_buffer
    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)     
        ,hmi_gfx_mgr02_amber_build_video
    #endif
    },
#endif
#if defined(GFX_MGR02_AMBER_IRIS) 
    {
        hmi_gfx_mgr02_amber_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_amber_start,
        hmi_gfx_mgr02_amber_build_image,
        hmi_gfx_mgr02_amber_build_image,
        hmi_gfx_mgr02_amber_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_amber_build_tile,
    #endif
        hmi_gfx_mgr02_amber_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)	
        hmi_gfx_mgr02_amber_build_svg,
    #endif
        hmi_gfx_mgr02_amber_finish,
        hmi_gfx_mgr02_amber_get_bound,
        hmi_gfx_mgr02_amber_clear_buffer
    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)     
        ,hmi_gfx_mgr02_amber_build_video
    #endif
    },
#endif
#if defined(GFX_MGR02_MONOTFT)
    {
        hmi_gfx_mgr02_monolib_init,
        hmi_gfx_mgr02_monolib_shutdown,
        hmi_gfx_mgr02_monolib_start,
        hmi_gfx_mgr02_monolib_build_image,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_monolib_build_fill,
    #if GFX_MGR02_NUM_OF_TILES > 0
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_monolib_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)	
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_monolib_finish,
        hmi_gfx_mgr02_monolib_get_bound,
        GFX_MGR02_NULL_PTR
    },
#endif
#if defined(GFX_MGR02_IMXRT) 
    {
        hmi_gfx_mgr02_imxrt_initialize,
        GFX_MGR02_NULL_PTR, GFX_MGR02_NULL_PTR,
        GFX_MGR02_NULL_PTR,
        GFX_MGR02_NULL_PTR,
        GFX_MGR02_NULL_PTR,
#if GFX_MGR02_NUM_OF_TILES > 0
        GFX_MGR02_NULL_PTR,
#endif
        NULL,
#if (GFX_MGR02_NUM_OF_SVGS > 0)
        GFX_MGR02_NULL_PTR,
#endif
        GFX_MGR02_NULL_PTR,
        GFX_MGR02_NULL_PTR,
        GFX_MGR02_NULL_PTR
    },
#endif
#if defined(GFX_MGR02_IMXRT_PXP) 
    {
        hmi_gfx_mgr02_imxrt_pxp_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_imxrt_pxp_start,
        hmi_gfx_mgr02_imxrt_pxp_build_image,
        hmi_gfx_mgr02_imxrt_pxp_build_image,
        hmi_gfx_mgr02_imxrt_pxp_build_fill,
    #if GFX_MGR02_NUM_OF_TILES > 0
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_imxrt_pxp_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)	
        GFX_MGR02_NULL_PTR,
    #endif
        hmi_gfx_mgr02_imxrt_pxp_finish,
        hmi_gfx_mgr02_imxrt_pxp_get_bound,
        hmi_gfx_mgr02_imxrt_pxp_clear_buffer
    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)     
        ,GFX_MGR02_NULL_PTR
    #endif
    },
#endif
#if defined(GFX_MGR02_VGLITE)
    {
        hmi_gfx_mgr02_vglite_init,
        hmi_gfx_mgr02_vglite_shutdown,
        hmi_gfx_mgr02_vglite_start,
        hmi_gfx_mgr02_vglite_build_image,
        hmi_gfx_mgr02_vglite_build_image,
        hmi_gfx_mgr02_vglite_build_fill,
    #if GFX_MGR02_NUM_OF_TILES > 0
        GFX_MGR02_NULL_PTR,
    #endif
    #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        hmi_gfx_mgr02_vglite_build_text,
    #else
        GFX_MGR02_NULL_PTR,    
    #endif
    #if (GFX_MGR02_NUM_OF_SVGS > 0)
        hmi_gfx_mgr02_vglite_build_svg,
    #endif
        hmi_gfx_mgr02_vglite_finish,
        hmi_gfx_mgr02_vglite_get_bound,
        hmi_gfx_mgr02_vglite_clear_buffer
    },
#endif
#if defined(GFX_MGR02_TRAVEO2)
    {
        hmi_gfx_mgr02_tv2_init,
        GFX_MGR02_NULL_PTR,
        hmi_gfx_mgr02_tv2_start,
        hmi_gfx_mgr02_tv2_build_image,
        #if (GFX_MGR02_NUM_USER_LAYERS > 0)
        hmi_gfx_mgr02_tv2_build_uimage,
        #else
        GFX_MGR02_NULL_PTR,
        #endif
        hmi_gfx_mgr02_tv2_build_fill,
    #if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
        hmi_gfx_mgr02_tv2_build_tile,
    #endif
        hmi_gfx_mgr02_tv2_build_text,
    #if (GFX_MGR02_NUM_OF_SVGS > 0)	
        hmi_gfx_mgr02_tv2_build_svg,
    #endif
        hmi_gfx_mgr02_tv2_finish,
        hmi_gfx_mgr02_amber_get_bound,
        hmi_gfx_mgr02_tv2_clear_buffer
    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)     
        ,hmi_gfx_mgr02_tv2_build_video
    #endif
    }
#endif

};
#endif

static GFX_MGR02_LIB_CB_LIST_T const * l_lib_if_SP;
static GFX_MGR02_ANIM_DATA_T         * l_anim_prop_SP;

/*
** Different build modes l_gen_build_mode_U8 can take.
** GFX_MGR02_BUILD_NORMAL      - indicates its normal building, so element is built as is
** GFX_MGR02_BUILD_DAR_PROCESS - indicates its a dirty area pre process, so no building will
**                               happen but only an elements transformed area is determined
**                               and added to a DAR list
** GFX_MGR02_BUILD_DAR_REDRAW  - indicates its a dirty region redraw and therefore the clip
**                               is applied before the drawing is issued
** GFX_MGR02_BUILD_FIND_BOUND  - indicates this a bound calculation drive, there
**                               fore an elements transformed bounds are combined to
**                               find overall boundary for a group of elements. No building
**                               happens during this drive.
*/
#define GFX_MGR02_BUILD_NORMAL      0U
#define GFX_MGR02_BUILD_DAR_PROCESS 1U
#define GFX_MGR02_BUILD_FIND_BOUND  2U
#define GFX_MGR02_BUILD_DAR_REDRAW  3U

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  #define GFX_MGR02_IS_LINE_BREAK_CHAR(char_unicode, is_complex, is_character, unique_font_id)   hmi_gfx_mgr02_is_line_break_char((char_unicode), (is_complex), (is_character), (unique_font_id))
  #define GFX_MGR02_IS_PRINTABLE_CHAR(char_unicode, is_complex, is_character, unique_font_id)    hmi_gfx_mgr02_is_printable_char((char_unicode), (is_complex), (is_character), (unique_font_id))
#else
  #define GFX_MGR02_IS_LINE_BREAK_CHAR(char_unicode)   hmi_gfx_mgr02_is_line_break_char(char_unicode)
  #define GFX_MGR02_IS_PRINTABLE_CHAR(char_unicode)    hmi_gfx_mgr02_is_printable_char(char_unicode)
#endif
#endif

static UINT8 l_gen_build_mode_U8;

/**
** Index 0, 1 start X,Y
** Index 2,3  end X, Y
*/
static GFX_FLOAT l_elem_bound[4];

#if GFX_MGR02_NUM_OF_DTEXTS > 0 
 #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
      #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
        extern GFX_MGR02_SHAPE_ML_DATA l_shape_ml_dtext_buffer[GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS];
      #endif
 #endif
#if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
#define GFX_MGR02_SET_DO_SHAPE_FLAG(flag_array, obj_id)   ((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]   |= ((UINT8)(((UINT8)1)<<(((UINT16)(obj_id))&0x07u))))
#define GFX_MGR02_CLR_DO_SHAPE_FLAG(flag_array, obj_id)   (((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) &= (UINT8)~(UINT8)(1u<<(((UINT16)(obj_id))&0x07u)))
#define GFX_MGR02_IS_DO_SHAPE_SET(flag_array, obj_id) ((((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) & ((UINT8)((UINT8)1<<((UINT8)(((UINT16)(obj_id))&0x07u))))) != (UINT8)0)
        extern HMI_CHAR l_dynamic_text_buffer_presen[GFX_MGR02_DTEXTS_BUFFER_SIZE];
        UINT8  l_dtext_do_shape_flag_U8A[(GFX_MGR02_NUM_OF_DTEXTS + 7) / 8];
#endif
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : void hmi_gfx_mgr02_generic_initialize()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic manager needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_generic_initialize(void)
{
   u_gx_flocal fl_lib_index;
#if GFX_MGR02_GEN_NUM_TARGETS > 1
   for(fl_lib_index = (u_gx_flocal)0;  fl_lib_index < (u_gx_flocal)GFX_MGR02_GEN_NUM_TARGETS; fl_lib_index++)
#else
    fl_lib_index = 0;
#endif
   {
      if(l_sw_ovg_lib_interfaces_SA[fl_lib_index].init != (void *)0)
      {
         (void)l_sw_ovg_lib_interfaces_SA[fl_lib_index].init();
      }
   }
   l_gen_build_mode_U8 = GFX_MGR02_BUILD_NORMAL;
   l_anim_prop_SP      = hmi_gfx_mgr02_layout_get_anim_data();
   GFX_MGR02_UNUSED_PTR(l_anim_prop_SP);
}

/****************************************************************************
Function Name        : void hmi_gfx_mgr02_generic_shutdown()
Description          : Performs the shutdown sequence
Invocation           : When ever generic manager needs to do shutdown
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_generic_shutdown(void)
{
   u_gx_flocal fl_lib_index;
#if GFX_MGR02_GEN_NUM_TARGETS > 1
   for(fl_lib_index = (u_gx_flocal)0;  fl_lib_index < (u_gx_flocal)GFX_MGR02_GEN_NUM_TARGETS; fl_lib_index++)
#else
    fl_lib_index = 0;
#endif
   {
      if(l_sw_ovg_lib_interfaces_SA[fl_lib_index].shutdown != (void *)0)
      {
         (void)l_sw_ovg_lib_interfaces_SA[fl_lib_index].shutdown();
      }
   }

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_begin_update()
Description          : Sets up the environment for the passed layer 
Invocation           : Invoked by build screen.
Return Value         : TRUE if success, FALSE if failure
Parameters           : layer ID and pointer to layer configuration
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_generic_begin_update(u_gx_flocal p_layer_ID_U8, GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP)
{
   u_gx_flocal           fl_init_status = (u_gx_flocal)FALSE;
   GFX_MGR02_CONTEXT_T const * fl_context_SP;

   fl_context_SP       = hmi_gfx_mgr02_context_begin_update(p_layer_ID_U8, p_layer_table_SP, (u_gx_flocal)TRUE);
   l_gen_build_mode_U8 = GFX_MGR02_BUILD_NORMAL;
   #if defined(GFX_MGR02_SOFTWARE)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_SOFTWARE)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_SWR];
   }
   else
   #endif
   #if defined(GFX_MGR02_OPEN_VG)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_OPENVG)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_OVG];
   }
   else 
   #endif
   #if defined(GFX_MGR02_OPEN_GL)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_OPENGL)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_OGL];
   }
   else 
   #endif
   #if defined(GFX_MGR02_FUJITSU)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_FUJITSU)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_FJU];
   }
   else 
   #endif
   #if defined(GFX_MGR02_AMBER)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_AMBER)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_ABR];
   }
   else
   #endif
   #if defined(GFX_MGR02_AMBER_IRIS)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_AMBER_IRIS)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_ABR_IRIS];
   }
   else
   #endif
   #if defined(GFX_MGR02_MONOTFT)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_MONOTFT)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_MONO];
   }
   else
   #endif
   #if defined(GFX_MGR02_TRAVEO2)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_TRAVEO2)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_TV2];
   }
   else
   #endif
   #if defined(GFX_MGR02_IMXRT)
   if (p_layer_table_SP->target == GFX_MGR02_TARGET_IMXRT) 
   {
        l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT];
   } 
   else
   #endif
   #if defined(GFX_MGR02_IMXRT_PXP)
   if(p_layer_table_SP->target == GFX_MGR02_TARGET_IMXRT_PXP)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT_PXP];
   }
   else
   #endif   
   {
      l_lib_if_SP = GFX_MGR02_NULL_PTR;
   }

   if((l_anim_prop_SP != GFX_MGR02_NULL_PTR) && (l_lib_if_SP != GFX_MGR02_NULL_PTR) && (fl_context_SP != GFX_MGR02_NULL_PTR))
   {
      if(l_lib_if_SP->build_start != (void *)0)
      {
         (void)l_lib_if_SP->build_start(fl_context_SP);
      }
      fl_init_status = (u_gx_flocal)TRUE;
   }
   else
   {
     GFX_MGR02_UNUSED_PTR(fl_context_SP);
   }
 #if (defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_DIRTY_REGION_REDRAW)) || (defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_DIRTY_REGION_REDRAW))
   if(l_lib_if_SP->clear_buffer != GFX_MGR02_NULL_PTR)
   {
     (void)l_lib_if_SP->clear_buffer(fl_context_SP, 0x00U);
   }
 #endif
   return(fl_init_status);
}

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/****************************************************************************
Function Name        : void hmi_gfx_mgr02_generic_update_dirty_area()
Description          : 
Invocation           : Invoked by application when ever the screen needs to be
                       refreshed.
Return Value         : None
Critical Section     : Shall not call other API's (e.g. from interrupt level) while
                       hmi_gfx_mgr02_generic_build_screen is ongoing.
Parameters           : Layer ID
******************************************************************************/
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
static u_gx_flocal hmi_gfx_mgr02_generic_update_dirty_area(u_gx_flocal                   p_layer_ID_U8, 
                                                           GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                            u_gx_flocal p_layout_dirty_U8)
#else
static u_gx_flocal hmi_gfx_mgr02_generic_update_dirty_area(u_gx_flocal                   p_layer_ID_U8, 
                                                           GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP)
#endif

{
   const GFX_MGR02_CONTEXT_T * fl_context_SP;
   u_gx_flocal           fl_cur_priority_U8;
   u_gx_flocal           fl_obj_dirty_U8 = FALSE;
   u_gx_flocal           fl_num_dirty_area = 0;
   
   if (p_layer_ID_U8 < (u_gx_flocal)GFX_MGR02_NUM_LAYERS)
   {
       hmi_gfx_mgr02_dar_start((UINT8)p_layer_ID_U8);
       fl_context_SP       = hmi_gfx_mgr02_context_begin_update(p_layer_ID_U8, p_layer_table_SP, (u_gx_flocal)FALSE);
       l_anim_prop_SP      = hmi_gfx_mgr02_layout_get_anim_data();
       l_gen_build_mode_U8 = GFX_MGR02_BUILD_DAR_PROCESS;
       #if defined(GFX_MGR02_SOFTWARE)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_SOFTWARE)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_SWR];
       }
       else
       #endif
       #if defined(GFX_MGR02_OPEN_VG)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_OPENVG)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_OVG];
       }
       else
       #endif
       #if defined(GFX_MGR02_OPEN_GL)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_OPENGL)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_OGL];
       }
       else
       #endif
       #if defined(GFX_MGR02_FUJITSU)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_FUJITSU)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_FJU];
       }
       else
       #endif
       #if defined(GFX_MGR02_AMBER_IRIS)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_AMBER_IRIS)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_ABR_IRIS];
       }
       else
       #endif
       #if defined(GFX_MGR02_MONOTFT)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_MONOTFT)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_MONO];
       }
       else
       #endif
       #if defined(GFX_MGR02_IMXRT)
       if (p_layer_table_SP->target == GFX_MGR02_TARGET_IMXRT)
       {
            l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT];
       }
       else
       #endif
       #if defined(GFX_MGR02_IMXRT_PXP)
       if(p_layer_table_SP->target == GFX_MGR02_TARGET_IMXRT_PXP)
       {
          l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT_PXP];
       }
       else
       #endif   
       {
          l_lib_if_SP = GFX_MGR02_NULL_PTR;
       }

       if((l_anim_prop_SP != GFX_MGR02_NULL_PTR) && (l_lib_if_SP != GFX_MGR02_NULL_PTR) && (fl_context_SP != GFX_MGR02_NULL_PTR))
       {
          for(fl_cur_priority_U8 = 0; fl_cur_priority_U8 < p_layer_table_SP->nb_priority; fl_cur_priority_U8++)
          {
             u_gx_flocal fl_screen_id  = p_layer_table_SP->prio_stack[fl_cur_priority_U8];

             if(fl_screen_id < (u_gx_flocal)GFX_MGR02_NUM_OF_SCREENS)
             {
                GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP = &lc_screen_def_S[fl_screen_id];
                       
                hmi_gfx_mgr02_context_reset_state();
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_anim_prop_SP->layer_alpha[p_layer_ID_U8]);
                hmi_gfx_mgr02_context_set_loc(&l_anim_prop_SP->layer_loc[p_layer_ID_U8]);
             #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
                if(fl_screen_def_SP->anim_index < (UINT8)GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)
                {       
                   hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_anim_prop_SP->group_alpha[fl_screen_def_SP->anim_index]);
                   hmi_gfx_mgr02_context_set_loc(&l_anim_prop_SP->group_loc[fl_screen_def_SP->anim_index]);        
                }
                fl_obj_dirty_U8 = hmi_gfx_mgr02_layout_is_element_changed(fl_cur_priority_U8, (GFX_MGR02_TYPE_SCREEN|fl_screen_def_SP->anim_index));
             #else
                fl_obj_dirty_U8 = hmi_gfx_mgr02_layout_is_element_changed(fl_cur_priority_U8, (GFX_MGR02_TYPE_SCREEN|0xFFFFU));
             #endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            if(FALSE!=p_layout_dirty_U8)
            {
              fl_obj_dirty_U8=p_layout_dirty_U8;
            }
            #endif
                hmi_gfx_mgr02_generic_build_group((u_gx_flocal)fl_screen_def_SP->num_child_elements, 
                                                  fl_screen_def_SP->child, 
                                                  GFX_MGR02_GENERIC_BUILD,
                                                  fl_obj_dirty_U8);
             }
          }
       }
       hmi_gfx_mgr02_context_end_update(p_layer_ID_U8, (UINT32)FALSE);
       fl_num_dirty_area = hmi_gfx_mgr02_dar_process();
   }
   return fl_num_dirty_area;
}
#endif

/****************************************************************************
Function Name        : void hmi_gfx_mgr02_generic_build_screen()
Description          : Performs the screen building and updates the frame buffer
                       if there are any chnages to be made.
Invocation           : Invoked by application when ever the screen needs to be
                       refreshed.
Return Value         : None
Critical Section     : Shall not call other API's (e.g. from interrupt level) while
                       hmi_gfx_mgr02_generic_build_screen is ongoing.
Parameters           : Layer ID
******************************************************************************/
#ifdef  GFX_MGR02_DLAYOUT_ENABLED
u_gx_flocal hmi_gfx_mgr02_generic_build_screen(u_gx_flocal p_layer_ID_U8, u_gx_flocal p_layout_dirty_U8)
#else
u_gx_flocal hmi_gfx_mgr02_generic_build_screen(u_gx_flocal p_layer_ID_U8)
#endif
{   
    u_gx_flocal fl_status = (u_gx_flocal)FALSE;
   
    if(p_layer_ID_U8 < (u_gx_flocal)GFX_MGR02_NUM_LAYERS)
    {
       GFX_MGR02_LAYER_DEF_T const * fl_layer_table_SP = &lc_layer_def_S[p_layer_ID_U8];

    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
      {
        hmi_gfx_mgr02_capture_video_set_status(FALSE);
      }
    #endif
     
    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
       u_gx_flocal fl_num_dirty_area;
       gfxlogstart(GFX_LOG_DIRTY_AREA_PROCESSING);
    #ifdef  GFX_MGR02_DLAYOUT_ENABLED
       fl_num_dirty_area = hmi_gfx_mgr02_generic_update_dirty_area(p_layer_ID_U8, fl_layer_table_SP,p_layout_dirty_U8);
    #else
       fl_num_dirty_area = hmi_gfx_mgr02_generic_update_dirty_area(p_layer_ID_U8, fl_layer_table_SP);
    #endif

       gfxlogend(GFX_LOG_DIRTY_AREA_PROCESSING);

       if(fl_num_dirty_area > (u_gx_flocal)0)
    #endif
       {
          fl_status = hmi_gfx_mgr02_generic_begin_update(p_layer_ID_U8, fl_layer_table_SP);

          if(fl_status != (u_gx_flocal)FALSE)
          {
             u_gx_flocal              fl_cur_priority_U8;
          #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
             GFX_MGR02_IAREA_DATA     fl_clip_area;
             const GFX_MGR02_VISIBLE_AREA * fl_dirty_area;
             
             l_gen_build_mode_U8 = GFX_MGR02_BUILD_DAR_REDRAW;

             while(fl_num_dirty_area > (u_gx_flocal)0)
             {
                fl_num_dirty_area--;
                fl_dirty_area = hmi_gfx_mgr02_dar_get_drect(fl_num_dirty_area);
                if(fl_dirty_area != GFX_MGR02_NULL_PTR)
                {
          #endif
                   for(fl_cur_priority_U8 = (u_gx_flocal)0; fl_cur_priority_U8 < fl_layer_table_SP->nb_priority; fl_cur_priority_U8++)
                   {
                      u_gx_flocal fl_screen_id  = fl_layer_table_SP->prio_stack[fl_cur_priority_U8];

                      if(fl_screen_id < (u_gx_flocal)GFX_MGR02_NUM_OF_SCREENS)
                      {
                         GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP = &lc_screen_def_S[fl_screen_id];
                                
                         hmi_gfx_mgr02_context_reset_state();
                      #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                         fl_clip_area.x      = fl_dirty_area->sx;
                         fl_clip_area.y      = fl_dirty_area->sy;
                         fl_clip_area.width  = (UINT16)(fl_dirty_area->ex-fl_dirty_area->sx);
                         fl_clip_area.height = (UINT16)(fl_dirty_area->ey-fl_dirty_area->sy);
                         hmi_gfx_mgr02_context_set_clip(&fl_clip_area);
                      #endif                
                         hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_anim_prop_SP->layer_alpha[p_layer_ID_U8]);
                         hmi_gfx_mgr02_context_set_loc(&l_anim_prop_SP->layer_loc[p_layer_ID_U8]);
                      #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
                         if(fl_screen_def_SP->anim_index < (UINT8)GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)
                         {       
                            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_anim_prop_SP->group_alpha[fl_screen_def_SP->anim_index]);
                            hmi_gfx_mgr02_context_set_loc(&l_anim_prop_SP->group_loc[fl_screen_def_SP->anim_index]);        
                         }
                      #endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */
                         hmi_gfx_mgr02_generic_build_group((u_gx_flocal)fl_screen_def_SP->num_child_elements, fl_screen_def_SP->child, (u_gx_flocal)GFX_MGR02_GENERIC_BUILD, (u_gx_flocal)TRUE);
                      }
                   }
           #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                }
             }
           #endif
             fl_status = (u_gx_flocal)FALSE;
             if(l_lib_if_SP->build_finish != (void *)0)
             {
                #if defined(GFX_MGR02_FUJITSU) && defined(GFX_MGR02_IRIS_PIXEL_POKING)
                GFX_MGR02_CONTEXT_T const* fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
                #endif
                gfxlogcontinue(GFX_LOG_RENDERING);
                #if defined(GFX_MGR02_FUJITSU) && defined(GFX_MGR02_IRIS_PIXEL_POKING)
                fl_status = (u_gx_flocal)l_lib_if_SP->build_finish(fl_context_SP);
                #else
                fl_status = (u_gx_flocal)l_lib_if_SP->build_finish();
                #endif
                gfxlogstop(GFX_LOG_RENDERING);
             }
          }   
          hmi_gfx_mgr02_context_end_update(p_layer_ID_U8, fl_status);
          #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
          {
            UINT8 fl_video_status = hmi_gfx_mgr02_capture_video_get_status();
            if(fl_video_status == (UINT8)FALSE)
            {
              hmi_gfx_mgr02_capture_video_shutdown();
            }
          }
          #endif
       }
    }
    return fl_status;
}

#if (defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT))  && (GFX_MGR02_NUM_OF_SWDGS > 0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_dcu_gen_widget()
Description          : Generic build routine for building a openvg or software
                       rendering widget element of a Kepler design. This function
                       sets up the context and loops through each item in the 
                       group and invokes appropriate build routine.
Invocation           : Invoked by kepler build screen.
Return Value         : None
Parameters           : Pointer to element group and number of elements in group
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
UINT32 hmi_gfx_mgr02_generic_build_dcu_gen_widget(GFX_MGR02_CONTEXT_GB_T      * p_build,
                                                  GFX_MGR02_ELEM_LIST_T const * p_elem_list)
{
   const GFX_MGR02_CONTEXT_T * fl_cntx_SP;
   UINT32                fl_updated = FALSE;
   #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
   UINT32                fl_build_started=FALSE;
   #endif
#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
   s_gx_flocal fl_is_warp_started;
#endif
   #if defined(GFX_MGR02_SOFTWARE)
   if(p_build->fb_target == GFX_MGR02_TARGET_SOFTWARE)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_SWR];
   }
   else
   #endif
   #if defined(GFX_MGR02_OPEN_VG)
   if(p_build->fb_target == GFX_MGR02_TARGET_OPENVG)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_OVG];
   }
   else
   #endif
   #if defined(GFX_MGR02_AMBER)
   if(p_build->fb_target == GFX_MGR02_TARGET_AMBER)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_ABR];
   }
   else
   #endif
   #if defined(GFX_MGR02_MONOTFT)
   if(p_build->fb_target == GFX_MGR02_TARGET_MONOTFT)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_MONO];
   }
   else
   #endif
   #if defined(GFX_MGR02_TRAVEO2)
   if(p_build->fb_target == GFX_MGR02_TARGET_TRAVEO2)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_TV2];
   }
   else
   #endif
   #if defined(GFX_MGR02_IMXRT)
   if(p_build->fb_target == GFX_MGR02_TARGET_IMXRT)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT];
   }
   else
   #endif
  #if defined(GFX_MGR02_IMXRT_PXP)
   if(p_build->fb_target == GFX_MGR02_TARGET_IMXRT_PXP)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT_PXP];
   }
   else
   #endif
   #if defined(GFX_MGR02_VGLITE)
   if(p_build->fb_target == GFX_MGR02_TARGET_VGLITE)
   {
      l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_VGLITE];
   }
   else
   #endif
   {
      l_lib_if_SP = (GFX_MGR02_LIB_CB_LIST_T *)0;
   }

   if(l_lib_if_SP != (void *)0)
   {
      GFX_MGR02_ILOC_DATA fl_loc_S;
      l_gen_build_mode_U8 = GFX_MGR02_BUILD_NORMAL;
      l_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
      fl_cntx_SP     = hmi_gfx_mgr02_context_widget_begin_update(p_build);

      if((l_anim_prop_SP != (GFX_MGR02_ANIM_DATA_T *)0) && (fl_cntx_SP != (GFX_MGR02_CONTEXT_T *)0) && (p_elem_list->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS))
      {
        #ifdef GFX_MGR02_DIRTY_REGION_REDRAW

          u_gx_flocal            fl_num_dirty_area =(u_gx_flocal)0;
         #if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_IMXRT))
          if(p_build->dirty_area == TRUE)
         #endif
          {
             if(lc_swidget_layer_def_S[p_elem_list->base_id].clip_mode != GFX_MGR02_WP_CLIP_NONE)              
             {
                u_gx_flocal           fl_obj_dirty_U8 = FALSE;
                UINT8 fl_layer_id  = (UINT8)(GFX_MGR02_NUM_LAYERS + p_build->client_id);

                gfxlogstart(GFX_LOG_DIRTY_AREA_PROCESSING);
                hmi_gfx_mgr02_dar_start(fl_layer_id);       
                l_gen_build_mode_U8 = GFX_MGR02_BUILD_DAR_PROCESS;

                hmi_gfx_mgr02_context_reset_state();
                fl_loc_S.x = -p_build->area.x;
                fl_loc_S.y = -p_build->area.y;
                hmi_gfx_mgr02_context_set_loc(&fl_loc_S);
                
             #if defined(GFX_MGR02_IMXRT)
                fl_obj_dirty_U8 = hmi_gfx_mgr02_layout_is_element_changed(p_elem_list->base_id, p_elem_list->obj_id);
             #elif defined(GFX_MGR02_TRAVEO2)
                fl_obj_dirty_U8 = FALSE;
             #else
                fl_obj_dirty_U8 = hmi_gfx_mgr02_layout_is_element_changed(p_elem_list->child->base_id, p_elem_list->child->obj_id);
             #endif
                
                fl_obj_dirty_U8|= hmi_gfx_mgr02_context_is_widget_builded_first(p_build);
                hmi_gfx_mgr02_generic_build_group((u_gx_flocal)p_elem_list->num_child_elements, 
                                                    p_elem_list->child, 
                                                    GFX_MGR02_GENERIC_BUILD,
                                                    fl_obj_dirty_U8);
                fl_num_dirty_area = hmi_gfx_mgr02_dar_process();
                if(fl_num_dirty_area > (u_gx_flocal)0)
                {
                  (void)hmi_gfx_mgr02_context_copy_fb(p_build->client_id, fl_cntx_SP);
                }
                gfxlogend(GFX_LOG_DIRTY_AREA_PROCESSING);
             }
          }
        #endif /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */ 

#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
        fl_is_warp_started = hmi_gfx_mgr02_amber_start_warping(p_build, p_elem_list);
#endif /* #ifdef GFX_MGR02_WIDGET_WARPING_ENABLED */
        if((l_lib_if_SP->build_start != (void *)0)
          #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
              && ((fl_num_dirty_area > (u_gx_flocal)0)||
              (lc_swidget_layer_def_S[p_elem_list->base_id].clip_mode == GFX_MGR02_WP_CLIP_NONE)
            #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_IMXRT)
              ||(p_build->dirty_area == FALSE)
            #endif
          ) 
#endif
          )
        { 
          (void)l_lib_if_SP->build_start(fl_cntx_SP);
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
          fl_build_started=TRUE;
#endif
        }

        if((p_build->clr_buffer != FALSE)
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
          && ((fl_num_dirty_area > (u_gx_flocal)0)||
          (lc_swidget_layer_def_S[p_elem_list->base_id].clip_mode == GFX_MGR02_WP_CLIP_NONE)
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
          ||(p_build->dirty_area == FALSE)
#endif
          )
#endif
          )
        {
          if(l_lib_if_SP->clear_buffer != GFX_MGR02_NULL_PTR)
          {
            (void)l_lib_if_SP->clear_buffer(fl_cntx_SP, p_build->clr_color);
          }
        }

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
        if((fl_num_dirty_area > (u_gx_flocal)0)
          && (lc_swidget_layer_def_S[p_elem_list->base_id].clip_mode != GFX_MGR02_WP_CLIP_NONE)
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_IMXRT)
          &&(p_build->dirty_area == TRUE)
#endif
          )
        {       
          l_gen_build_mode_U8 = GFX_MGR02_BUILD_DAR_REDRAW;

          while(fl_num_dirty_area > 0U)
          {
          #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))
            UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list->obj_id);
          #endif						  	
            GFX_MGR02_IAREA_DATA     fl_clip_area;
            const GFX_MGR02_VISIBLE_AREA * fl_dirty_area;
            fl_num_dirty_area--;
            fl_dirty_area = hmi_gfx_mgr02_dar_get_drect(fl_num_dirty_area);
            hmi_gfx_mgr02_context_reset_state();
            if(fl_dirty_area != GFX_MGR02_NULL_PTR)
            {
              fl_clip_area.x      = fl_dirty_area->sx;
              fl_clip_area.y      = fl_dirty_area->sy;
              fl_clip_area.width  = (UINT16)(fl_dirty_area->ex-fl_dirty_area->sx);
              fl_clip_area.height = (UINT16)(fl_dirty_area->ey-fl_dirty_area->sy);
              hmi_gfx_mgr02_context_set_clip(&fl_clip_area);
              fl_loc_S.x = -p_build->area.x;
              fl_loc_S.y = -p_build->area.y;


              hmi_gfx_mgr02_context_set_loc(&fl_loc_S);
            #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))
              if (fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
              {
                 hmi_gfx_mgr02_context_set_alpha(l_anim_prop_SP->widget_prop[fl_obj_id].alpha);
              }
            #endif						
              hmi_gfx_mgr02_generic_build_group((u_gx_flocal)p_elem_list->num_child_elements, p_elem_list->child,(u_gx_flocal)GFX_MGR02_GENERIC_BUILD,(u_gx_flocal)TRUE);
            }
          }
        }
        else if((lc_swidget_layer_def_S[p_elem_list->base_id].clip_mode == GFX_MGR02_WP_CLIP_NONE)
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_IMXRT)
          ||(p_build->dirty_area == FALSE)
#endif
          )
        {
          #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))
            UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list->obj_id);
          #endif
          hmi_gfx_mgr02_context_reset_state();
          fl_loc_S.x = -p_build->area.x;
          fl_loc_S.y = -p_build->area.y;
          hmi_gfx_mgr02_context_set_loc(&fl_loc_S);
          #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))
            if (fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
            {
                hmi_gfx_mgr02_context_set_alpha(l_anim_prop_SP->widget_prop[fl_obj_id].alpha);
            }
          #endif						
          hmi_gfx_mgr02_generic_build_group((u_gx_flocal)p_elem_list->num_child_elements, p_elem_list->child, (u_gx_flocal)GFX_MGR02_GENERIC_BUILD, (u_gx_flocal)TRUE);  
        }
        else{
             /* Adding comment to fix MISRA c-2012 Rule 15.7 */
        }
#else  /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */   
        hmi_gfx_mgr02_context_reset_state();

        fl_loc_S.x = -p_build->area.x;
        fl_loc_S.y = -p_build->area.y;
        hmi_gfx_mgr02_context_set_loc(&fl_loc_S);
        hmi_gfx_mgr02_generic_build_group((u_gx_flocal)p_elem_list->num_child_elements, p_elem_list->child, GFX_MGR02_GENERIC_BUILD, TRUE);
#endif /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */   

        if(l_lib_if_SP->build_finish != (void *)0)
        {
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
          if(p_build->dirty_area == TRUE)
#endif
          {
            if(fl_build_started!=FALSE)
            {
              fl_updated = (UINT32)l_lib_if_SP->build_finish();
            }
            else
            {
              fl_updated=FALSE; 
            }
          }
          #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
          else
          {
            fl_updated = (UINT32)l_lib_if_SP->build_finish(); 
          }
          #endif
#else
          fl_updated = (UINT32)l_lib_if_SP->build_finish(); 
#endif
#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0) ||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)||defined(GFX_MGR02_IMXRT))
          hmi_gfx_mgr02_context_widget_end_update(p_build->client_id,
            fl_updated
#ifdef GFX_MGR02_AMBER_USE_VRAM_HRAM
            ,p_build->use_extram
#endif
            );
#endif
          if(fl_updated != FALSE)
          {
#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0) ||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)||defined(GFX_MGR02_IMXRT))
            if((p_build->fb_target == GFX_MGR02_TARGET_OPENVG)||(p_build->fb_target == GFX_MGR02_TARGET_AMBER)||(p_build->fb_target == GFX_MGR02_TARGET_TRAVEO2)||(p_build->fb_target == GFX_MGR02_TARGET_IMXRT_PXP)||(p_build->fb_target == GFX_MGR02_TARGET_VGLITE))
            {
#ifdef GFX_MGR02_AMBER_USE_VRAM_HRAM
              if(p_build->use_extram == GFX_MGR02_USE_VRAM_HRAM)
              {
                p_build->render_buffer = hmi_gfx_mgr02_context_get_fb(p_build->client_id, (GFX_UINT)0);
              }
              else
#endif
              {
                p_build->render_buffer = hmi_gfx_mgr02_context_swap_widget(p_build->client_id);  
              }
            }
#endif
          }
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW		  
    #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0 || defined(GFX_MGR02_IMXRT)
          else
          {/*fl_updated==FALSE*/
            UINT32 fl_num_da_u32 = hmi_gfx_mgr02_layout_get_num_drecs();
            if((FALSE != p_build->dirty_area)&&(0U == fl_num_da_u32))
            {
                /*There are scenario where the number of Dirty Areas is zero and the same time the number of windows changed.
                Due to the change in window order the l_disp_comp[] array might not hold the valid buffer address and also the window may not got created.
                So, we have to assign the front buffer address here as it is showing in the display*/
                p_build->render_buffer = hmi_gfx_mgr02_context_get_front_fb(p_build->client_id);
            }
          }
    #endif
#endif		  
        }

#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
        if((s_gx_flocal)TRUE == fl_is_warp_started)
        {
          hmi_gfx_mgr02_amber_finish_warping(p_build, p_elem_list);
        }
#endif /* #ifdef GFX_MGR02_WIDGET_WARPING_ENABLED */
      }
   }
   return(fl_updated);
}

#endif /* #if defined(GFX_MGR02_KEPLER) && (GFX_MGR02_NUM_OF_SWDGS > 0) */

/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_group()
Description          : Generic build routine for the element group. Loops
                       through each item in the group and invokes appropriate
                       build routine.
                       Note : this function is 
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Pointer to element group and number of elements in group
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
u_gx_flocal hmi_gfx_mgr02_generic_get_element_bound(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP, 
                                                    u_gx_flocal                    p_target_U8,
                                                    GFX_FLOAT * p_bound)
{
    GFX_MGR02_CONTEXT_STATE_T     fl_cntx_state_S;
    UINT32                        fl_gen_target;
    u_gx_flocal                   fl_return_sts;
    #if defined(GFX_MGR02_SOFTWARE)
    if(p_target_U8 == GFX_MGR02_TARGET_SOFTWARE)
    {    
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_SWR;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_OPEN_VG)
    if(p_target_U8 == GFX_MGR02_TARGET_OPENVG)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_OVG;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else 
    #endif
    #if defined(GFX_MGR02_OPEN_GL)
    if(p_target_U8 == GFX_MGR02_TARGET_OPENGL)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_OGL;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else 
    #endif
    #if defined(GFX_MGR02_FUJITSU)
    if(p_target_U8 ==  GFX_MGR02_TARGET_FUJITSU)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_FJU;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else 
    #endif
    #if defined(GFX_MGR02_AMBER)
    if(p_target_U8 == GFX_MGR02_TARGET_AMBER)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_ABR;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_AMBER_IRIS)
    if(p_target_U8 == GFX_MGR02_TARGET_AMBER_IRIS)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_ABR_IRIS;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_MONOTFT)
    if(p_target_U8 == GFX_MGR02_TARGET_MONOTFT)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_MONO;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_TRAVEO2)
    if(p_target_U8 == GFX_MGR02_TARGET_TRAVEO2)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_TV2;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_IMXRT)
    if (p_target_U8 == GFX_MGR02_TARGET_IMXRT)
    {        
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_IMXRT;      /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    #if defined(GFX_MGR02_IMXRT_PXP)
    if(p_target_U8 == GFX_MGR02_TARGET_IMXRT_PXP)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_IMXRT_PXP;         /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif   
    #if defined(GFX_MGR02_VGLITE)
    if (p_target_U8 == GFX_MGR02_TARGET_VGLITE)
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_TARGET_VGLITE;          /* Deviation MISRA C-2012 Rule 10.8 */
    }
    else
    #endif
    {
        fl_gen_target = (UINT32)GFX_MGR02_GEN_NUM_TARGETS;             /* Deviation MISRA C-2012 Rule 10.8 */
    }

    if(fl_gen_target != (UINT32)GFX_MGR02_GEN_NUM_TARGETS)            /* Deviation MISRA C-2012 Rule 10.8 */
    {
        l_elem_bound[0] =  32767.0F;
        l_elem_bound[1] =  32767.0F;
        l_elem_bound[2] = -32768.0F;
        l_elem_bound[3] = -32768.0F;

        hmi_gfx_mgr02_context_state_get(&fl_cntx_state_S);
        hmi_gfx_mgr02_context_reset_state();
        l_lib_if_SP         = &l_sw_ovg_lib_interfaces_SA[fl_gen_target];
        l_gen_build_mode_U8 = GFX_MGR02_BUILD_FIND_BOUND;
        hmi_gfx_mgr02_generic_build_group((u_gx_flocal)p_elem_list_SP->num_child_elements, p_elem_list_SP->child, (u_gx_flocal)GFX_MGR02_GENERIC_BUILD, (u_gx_flocal)TRUE);
        hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cntx_state_S);
        
        p_bound[0] = l_elem_bound[0];
        p_bound[1] = l_elem_bound[1];
        p_bound[2] = (l_elem_bound[2]-p_bound[0]);
        p_bound[3] = (l_elem_bound[3]-p_bound[1]);
        fl_return_sts = (u_gx_flocal)TRUE;
    }
    else
    {
        p_bound[0] = 0.0F;
        p_bound[1] = 0.0F;
        p_bound[2] = 32767.0F;
        p_bound[3] = 32767.0F;
        fl_return_sts = (u_gx_flocal)FALSE;
    }
    return(fl_return_sts);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_add_bound()
Description          : Adds the bound to existing bound to finally get 
                       combined bound for an element.
Invocation           : Invoked by build element functions.
Return Value         : None
Parameters           : Pointer to the bound for current element
******************************************************************************/
void hmi_gfx_mgr02_generic_add_bound(GFX_FLOAT * p_bound)
{
   p_bound[2] += p_bound[0];
   p_bound[3] += p_bound[1];
   if(p_bound[0] < l_elem_bound[0])
   {
      l_elem_bound[0] = p_bound[0];
   }
   if(p_bound[1] < l_elem_bound[1])
   {
      l_elem_bound[1] = p_bound[1];
   }
   if(p_bound[2] > l_elem_bound[2])
   {
      l_elem_bound[2] = p_bound[2];
   }
   if(p_bound[3] > l_elem_bound[3])
   {
      l_elem_bound[3] = p_bound[3];
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_group()
Description          : Generic build routine for the element group. Loops
                       through each item in the group and invokes appropriate
                       build routine.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Pointer to element group and number of elements in group
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static void hmi_gfx_mgr02_generic_build_group(u_gx_flocal                   p_num_elements, 
                                              GFX_MGR02_ELEM_LIST_T const * p_elem_SP, 
                                              u_gx_flocal                   p_aligned_widget,
                                              u_gx_flocal                   p_obj_dirty_U8)
{
   u_gx_flocal fl_obj_dirty_U8;
   u_gx_flocal fl_num_elements = p_num_elements;
   GFX_MGR02_ELEM_LIST_T const * fl_elem_SP = p_elem_SP;
   while(fl_num_elements > (u_gx_flocal)0)
   {
      fl_num_elements--;
      
      if(hmi_gfx_mgr02_layout_is_element_changed((UINT32)fl_elem_SP->base_id, fl_elem_SP->obj_id)!=(UINT32)0)
      {
         fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
      }
      else
      {
         fl_obj_dirty_U8 = p_obj_dirty_U8;
      }
      switch (GFX_MGR02_GET_OBJ_TYPE(fl_elem_SP->obj_id))
      {
      #if GFX_MGR02_NUM_OF_SWDGS > 0
        case GFX_MGR02_TYPE_SWIDGET:
        case GFX_MGR02_TYPE_DWIDGET:
        {
           hmi_gfx_mgr02_generic_build_widget(fl_elem_SP, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
        case GFX_MGR02_TYPE_SIMAGE:
        {
           hmi_gfx_mgr02_generic_build_image(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8, (u_gx_flocal)FALSE);
        }
        break;
      #endif
      #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
        case GFX_MGR02_TYPE_DIMAGE:
        {
           hmi_gfx_mgr02_generic_build_dimage(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8,(u_gx_flocal)FALSE);
        }
        break;
      #endif   
      #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
        case GFX_MGR02_TYPE_STEXT:
        case GFX_MGR02_TYPE_DTEXT:
        {
           hmi_gfx_mgr02_generic_build_text(fl_elem_SP, p_aligned_widget, 0, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if GFX_MGR02_NUM_OF_TILES > 0
        case GFX_MGR02_TYPE_TILE:
        {
           hmi_gfx_mgr02_generic_build_tile(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if GFX_MGR02_NUM_OF_FILLS > 0
        case GFX_MGR02_TYPE_FILL:
        {
           hmi_gfx_mgr02_generic_build_fill(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if GFX_MGR02_NUM_USER_LAYERS > 0
        case GFX_MGR02_TYPE_USER_LAYER:
        {
           hmi_gfx_mgr02_generic_build_uimage(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
      case GFX_MGR02_TYPE_VIDEO_LAYER:
        {
           hmi_gfx_mgr02_generic_build_video(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
        }
        break;
      #endif
      #if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
        case GFX_MGR02_TYPE_SVG:
        {
           hmi_gfx_mgr02_generic_build_svg(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
        }
        break;
      #endif   
        default:
        {
            /*For MISRA warning Fix.*/
        }
        break;
      }
      fl_elem_SP++;
   }
}

#if GFX_MGR02_NUM_OF_SWDGS > 0
/****************************************************************************
Function Name     : hmi_gfx_mgr02_get_element_widthinfo()
Description       : fetches the element width.
Invocation        : Invoked by hmi_gfx_mgr02_generic_build_aligned_widget.
Return Value      : None
Parameters        : static widget stack pointer
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_get_element_widthinfo(GFX_MGR02_ELEM_LIST_T const * p_elem_SP)
{
    u_gx_flocal fl_element_width = 0;
    GFX_MGR02_ELEM_LIST_T const * fl_elem_SP = p_elem_SP;
    switch(GFX_MGR02_GET_OBJ_TYPE(fl_elem_SP->obj_id))
    {
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
      case GFX_MGR02_TYPE_DIMAGE:
      {
      #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
         fl_elem_SP = hmi_gfx_mgr02_layout_get_selected_simage(fl_elem_SP);
      #else
         fl_elem_SP = GFX_MGR02_NULL_PTR;
      #endif
         if(fl_elem_SP != GFX_MGR02_NULL_PTR)
         {
            if(fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {
                #if defined(GFX_MGR02_VGLITE)
                    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                    fl_element_width = (UINT32)hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->width - (UINT32)hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->padding;
                    #else
                    fl_element_width = (UINT32)lc_image_layer_def_S[fl_elem_SP->base_id].width - (UINT32)lc_image_layer_def_S[fl_elem_SP->base_id].padding;
                    #endif
                #else
                    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                    fl_element_width = hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->width;
                    #else
                    fl_element_width = lc_image_layer_def_S[fl_elem_SP->base_id].width;
                    #endif
                #endif
            }
         }		 
      }
      break;
      case GFX_MGR02_TYPE_SIMAGE:
      {
         if(fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
         {
             #if defined(GFX_MGR02_VGLITE)
                 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                 fl_element_width = (UINT32)hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->width - (UINT32)hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->padding;
                 #else
                 fl_element_width = (UINT32)lc_image_layer_def_S[fl_elem_SP->base_id].width - (UINT32)lc_image_layer_def_S[fl_elem_SP->base_id].padding;
                 #endif
             #else
                 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                 fl_element_width = hmi_gfx_mgr02_get_image_layer_def_ptr(fl_elem_SP->base_id)->width;
                 #else
                 fl_element_width = lc_image_layer_def_S[fl_elem_SP->base_id].width;
                 #endif	
             #endif                 
         }
      }
      break;
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
        case GFX_MGR02_TYPE_STEXT:
        case GFX_MGR02_TYPE_DTEXT:
        {
            GFX_MGR02_TEXT_INFO          fl_text_info_S = {0};
            if(fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
            {
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
                GFX_MGR02_TEXT_DEF_T const* fl_text_desc_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(fl_elem_SP->base_id);
#else
                GFX_MGR02_TEXT_DEF_T const* fl_text_desc_SP = &lc_text_layer_def_S[fl_elem_SP->base_id];
#endif
                fl_text_info_S.dyn_text_def_SP = fl_text_desc_SP;
                if (fl_text_desc_SP->dynamic != (UINT8)0)
                {
#if GFX_MGR02_NUM_OF_DTEXTS > 0
#if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
                    if ((fl_text_desc_SP->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) &&
                        (fl_text_desc_SP->max_num_of_lines > 1U))
                    {
                        if (((UINT32)fl_text_desc_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
                        {
                            UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((fl_text_desc_SP->anim_id));
                            UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((fl_text_desc_SP->anim_id));

                            if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
                                (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
                            {
                                GFX_MGR02_TEXT_DYN_PROPERTY const* fl_text_anim_prop_S = &l_anim_prop_SP->text_prop[fl_prop_index_u32];

                                if (fl_text_anim_prop_S->complex_script == 1U)
                                {
                                    HMI_CHAR const* fl_dtext_str_ptr = l_anim_prop_SP->dtext_str;
                                    if (fl_text_desc_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
                                    {
                                        GFX_MGR02_SHAPE_ML_DATA* fl_ML_data_ptr = &l_shape_ml_dtext_buffer[fl_text_desc_SP->ml_string_index];
                                        fl_text_info_S.print_str_P = fl_ML_data_ptr->input_string;
                                    }
                                    l_anim_prop_SP->dtext_str = fl_dtext_str_ptr;
                                    fl_text_info_S.is_complex = 1U;
                                    fl_text_info_S.str_offset_idx = 0U;
                                    fl_text_info_S.is_ml_data_still_exist = 0U;
                                }
                                else
                                {
                                    fl_text_info_S.is_complex = 0U;
                                    fl_text_info_S.str_offset_idx = 0U;
                                    fl_text_info_S.is_ml_data_still_exist = 0U;
                                    if (fl_text_desc_SP->string_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
                                    {
                                        fl_text_info_S.print_str_P = &l_anim_prop_SP->dtext_str[fl_text_desc_SP->string_index];
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        fl_text_info_S.is_complex = 0U;
                        fl_text_info_S.str_offset_idx = 0U;
                        fl_text_info_S.is_ml_data_still_exist = 0U;
                        if (fl_text_desc_SP->string_index < GFX_MGR02_DTEXTS_BUFFER_SIZE)
                        {
                            fl_text_info_S.print_str_P = &l_anim_prop_SP->dtext_str[fl_text_desc_SP->string_index];
                        }
                    }
#else
                    if (fl_text_desc_SP->string_index < (UINT32)GFX_MGR02_DTEXTS_BUFFER_SIZE)
                    {
                        fl_text_info_S.print_str_P = &l_anim_prop_SP->dtext_str[fl_text_desc_SP->string_index];
                    }
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                    fl_text_info_S.pre_render_index = hmi_gfx_mgr02_layout_get_prerender_index(fl_elem_SP->base_id);
#endif
#else
                    if (fl_text_desc_SP->string_index < (UINT32)GFX_MGR02_DTEXTS_BUFFER_SIZE)
                    {
#if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
                        fl_text_info_S.print_str_P = &l_dynamic_text_buffer_presen[fl_text_desc_SP->string_index];
                        if (GFX_MGR02_IS_DO_SHAPE_SET(l_dtext_do_shape_flag_U8A, fl_elem_SP->base_id))
                        {
                            u_gx_flocal fl_num_chars = fl_text_desc_SP->num_chars;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
                            if (fl_element_def_SP->max_num_of_lines > (UINT16)1)
                            {
                                fl_num_chars = fl_num_chars * fl_element_def_SP->max_num_of_lines;
                            }
#endif
                            hmi_gfx_mgr02_layout_default_text_shape((GFX_MGR02_DTEXT_ID)fl_elem_SP->base_id, &l_anim_prop_SP->dtext_str[fl_text_desc_SP->string_index],
                            &l_dynamic_text_buffer_presen[fl_text_desc_SP->string_index], (UINT8)FALSE, (UINT16)fl_num_chars
#if defined(HMI_LANG_PRE_RENDER_ENABLED)
                            , (UINT8)TRUE
#endif
                            );
                            GFX_MGR02_CLR_DO_SHAPE_FLAG(l_dtext_do_shape_flag_U8A, fl_elem_SP->base_id);
                        }
#else
                        fl_text_info_S.print_str_P = &l_anim_prop_SP->dtext_str[fl_text_desc_SP->string_index];
#endif
                    }
                    else
                    {
                        fl_text_info_S.print_str_P = NULL;
                    }
#endif
#else
                    fl_text_info_S.print_str_P = NULL;
#endif
                }
                else
                {
#if GFX_MGR02_NUM_OF_STEXTS > 0
                    if (fl_text_desc_SP->string_index < (UINT32)GFX_MGR02_STEXTS_BUFFER_SIZE)
                    {
                        fl_text_info_S.print_str_P = (HMI_CHAR const*)&lc_static_text_buffer[fl_text_desc_SP->string_index];
                    }
                    else
                    {
                        fl_text_info_S.print_str_P = NULL;
                    }
#else
                    fl_text_info_S.print_str_P = NULL;
#endif
                }

                fl_text_info_S.target = GFX_MGR02_TARGET_OPENVG;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                fl_text_info_S.append_str = TRUE;
#else
                fl_text_info_S.append_str = FALSE;
#endif

                if (fl_text_info_S.print_str_P != NULL)
                {
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2))
#ifdef GFX_MGR02_CLIP_TEXT_ENABLE
                  UINT8 fl_max_shrink = 100U;
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && ((defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
                  UINT8 fl_text_changed = (UINT8)FALSE;
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && defined(GFX_MGR02_TXT_EFFECTS_ENABLED))
                  GFX_MGR02_TEXT_DYN_PROPERTY const *fl_text_anim_prop_S = GFX_MGR02_NULL_PTR;
                  if (((UINT32)fl_text_desc_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
                  {
                    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((fl_text_desc_SP->anim_id));
                    UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((fl_text_desc_SP->anim_id));
                    if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
                    {
                      GFX_MGR02_ANIM_DATA_T *fl_anim_data_SP = hmi_gfx_mgr02_layout_get_anim_data();
                      fl_text_anim_prop_S = &fl_anim_data_SP->text_prop[fl_prop_index_u32];
                    }
                  }
#endif
#endif
#endif
                    fl_text_info_S.num_chars_to_process = (UINT16)HMI_STRLEN(fl_text_info_S.print_str_P);
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
                    fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
#endif
                    if (GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_SP->obj_id))
                    {
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
                        UINT32 fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(fl_elem_SP->obj_id);
                        if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
                        {
                            GFX_MGR02_TEXT_DYN_PROPERTY const* fl_text_prop_SP = &l_anim_prop_SP->text_prop[fl_obj_id_U32];
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
                            fl_text_info_S.font_pt_size = fl_text_prop_SP->font_pt_size;
#endif
                            fl_text_info_S.max_available_width = fl_text_prop_SP->width;

#if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
                            if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
                            {
                                if (fl_text_prop_SP->max_shrink != 100U)
                                {
                                    fl_max_shrink = fl_text_prop_SP->max_shrink;
                                }
                                else
                                {
                                    fl_max_shrink = hmi_gfx_mgr02_layout_get_text_global_max_shrink();
                                }
                                fl_text_info_S.max_available_width = ((fl_text_info_S.max_available_width * 100U) / fl_max_shrink);
                            }
#endif

#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                            fl_text_changed = hmi_gfx_mgr02_layout_get_txt_shaping_required(fl_elem_SP->base_id);
                            if (fl_text_changed == (UINT8)FALSE)
                            {
                                UINT8                  fl_string_found   = (UINT8)FALSE;
                                GFX_STRING_CACHE_INFO  fl_str_cache_info = { 0 };
                                UINT8                  fl_str_length     = (UINT8)HMI_STRLEN(fl_text_info_S.print_str_P);
                                UINT32                 fl_font_id        = hmi_gfx_mgr02_get_font_id((UINT32)fl_text_prop_SP->font_id);
                                GFX_MGR02_FONT  const* fl_font_SP        = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
                                if (fl_font_SP != GFX_MGR02_NULL_PTR)
                                {
                                    if (fl_str_length > (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
                                    {
                                        fl_str_length = (UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
                                    }
                                    (void)HMI_STRNCPY(fl_str_cache_info.InString, fl_text_info_S.print_str_P, fl_str_length);
                                    fl_str_cache_info.InString[fl_str_length] = (HMI_CHAR)'\0';
                                    fl_str_cache_info.FontId                  = (UINT32)fl_font_id;
                                    fl_str_cache_info.TextBoxWidth            = fl_text_prop_SP->width;
                                    fl_str_cache_info.ClipMode                = (UINT8)fl_text_prop_SP->clip_mode;
                                    fl_str_cache_info.Alignment               = (UINT8)fl_text_prop_SP->alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                    fl_str_cache_info.isScrolled              = (fl_text_prop_SP->scroll_offset > (GFX_FLOAT)0.0) ? TRUE:FALSE; 
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                    if (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
                                    {
                                      fl_str_cache_info.special_effects.effect_type = fl_text_anim_prop_S->txt_special_effects.effect_type;
                                    }
#endif                                    
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
                                    fl_str_cache_info.FontSize                = fl_text_info_S.font_pt_size;
#else
                                    fl_str_cache_info.FontSize                = fl_font_SP->p.height;
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                    fl_str_cache_info.MaxShrink               = fl_max_shrink;
#endif
                                    fl_string_found = hmi_gfx_mgr02_get_string_cache_info(&fl_str_cache_info);
                                    if (fl_string_found == (UINT8)FALSE)
                                    {
                                        fl_text_changed = (UINT8)TRUE;
                                    }
                                    else
                                    {
                                        fl_text_info_S.print_width = fl_str_cache_info.bmpWidth;
                                    }
                                }
                                else
                                {
                                    fl_text_info_S.print_width = 0U;
                                }
                            }
                            if (fl_text_changed == (UINT8)TRUE)
#endif
#endif
                            {
                            (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                                fl_text_prop_SP->font_id,
                                                                fl_text_prop_SP->clip_mode,
                                                                GFX_MGR02_GALIGNMENT(fl_text_prop_SP->font_id, fl_text_prop_SP->alignment)
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                , GFX_MGR02_NULL_PTR
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                , GFX_MGR02_NULL_PTR
#endif
                                                                );
                            }
                        }
#endif
                    }
                    else
                    {
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
                        fl_text_info_S.font_pt_size = (UINT8)lc_gfx_font_table[fl_text_desc_SP->font_id].height_pts;
#endif
                        fl_text_info_S.max_available_width = fl_text_desc_SP->width;

#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                        if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
                        {
                            fl_text_info_S.max_available_width = (fl_text_info_S.max_available_width * 100U) / hmi_gfx_mgr02_layout_get_text_global_max_shrink();
                        }
#endif

#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                        fl_text_changed = hmi_gfx_mgr02_layout_get_txt_shaping_required(fl_elem_SP->base_id);
#ifdef GFX_MGR02_CLIP_TEXT_ENABLE
                        fl_max_shrink   = hmi_gfx_mgr02_layout_get_text_global_max_shrink();
#endif
                        if (fl_text_changed == (UINT8)FALSE)
                        {
                            UINT8                  fl_string_found   = (UINT8)FALSE;
                            GFX_STRING_CACHE_INFO  fl_str_cache_info = { 0 };
                            UINT8                  fl_str_length     = (UINT8)HMI_STRLEN(fl_text_info_S.print_str_P);
                            UINT32                 fl_font_id        = hmi_gfx_mgr02_get_font_id((UINT32)fl_text_desc_SP->font_id);
                            GFX_MGR02_FONT  const* fl_font_SP        = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
                            if (fl_font_SP != GFX_MGR02_NULL_PTR)
                            {
                                if (fl_str_length > (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
                                {
                                    fl_str_length = (UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
                                }
                                (void)HMI_STRNCPY(fl_str_cache_info.InString, fl_text_info_S.print_str_P, fl_str_length);
            
                                fl_str_cache_info.InString[fl_str_length] = (HMI_CHAR)'\0';
                                fl_str_cache_info.FontId                  = fl_font_id;
                                fl_str_cache_info.TextBoxWidth            = fl_text_desc_SP->width;
                                fl_str_cache_info.ClipMode                = (UINT8)fl_text_desc_SP->clip_mode;
                                fl_str_cache_info.Alignment               = (UINT8)fl_text_desc_SP->alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                fl_str_cache_info.isScrolled              = FALSE; 
#endif                                 
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                    if (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
                                    {
                                      fl_str_cache_info.special_effects.effect_type = fl_text_anim_prop_S->txt_special_effects.effect_type;
                                    }
#endif                     
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
                                fl_str_cache_info.FontSize                = fl_text_info_S.font_pt_size;
#else
                                fl_str_cache_info.FontSize                = fl_font_SP->p.height;
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                fl_str_cache_info.MaxShrink               = fl_max_shrink;
#endif
                                fl_string_found = hmi_gfx_mgr02_get_string_cache_info(&fl_str_cache_info);
                                if (fl_string_found == (UINT8)FALSE)
                                {
                                    fl_text_changed = (UINT8)TRUE;
                                }
                                else
                                {
                                    fl_text_info_S.print_width = fl_str_cache_info.bmpWidth;
                                }
                            }
                            else
                            {
                                fl_text_info_S.print_width = 0U;
                            }
                        }
                        if (fl_text_changed == (UINT8)TRUE)
#endif
#endif
                        {
                            (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                                fl_text_desc_SP->font_id,
                                                                fl_text_desc_SP->clip_mode,
                                                                GFX_MGR02_GALIGNMENT(fl_text_desc_SP->font_id, fl_text_desc_SP->alignment)
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                , GFX_MGR02_NULL_PTR
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                , GFX_MGR02_NULL_PTR
#endif
                                                                );
                        }
                    }
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                    if (fl_text_desc_SP->clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
                    {
                        if (fl_text_desc_SP->width < fl_text_info_S.print_width)
                        {
                            UINT8 fl_scale_down = (UINT8)((fl_text_desc_SP->width * 100U) / fl_text_info_S.print_width);
                            if ((fl_scale_down % 5U) != 0U)
                            {
                                fl_scale_down = (fl_scale_down / 5U) * 5U;
                            }
                            fl_element_width = ((fl_text_info_S.print_width * fl_scale_down) / 100U);
                        }
                        else
                        {
                            fl_element_width = fl_text_info_S.print_width;
                        }
                    }
                    else
#endif
                    {
                        fl_element_width = fl_text_info_S.print_width;
                    }
                }
            }
        }
        break;
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
        case GFX_MGR02_TYPE_TILE:
        {
            if(GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_SP->obj_id))
            {
             #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
                UINT32 fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(fl_elem_SP->obj_id);
                if (fl_obj_id_U32 < GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
                {
                    fl_element_width = l_anim_prop_SP->tile_prop[fl_obj_id_U32].dim.width;
                }
             #endif
            }
            else
            {
                if (fl_elem_SP->base_id < GFX_MGR02_NUM_OF_TILES)
                {
                 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                    fl_element_width = hmi_gfx_mgr02_get_tile_layer_def_ptr(fl_elem_SP->base_id)->dim.width;
                 #else  
                    fl_element_width =  lc_tile_layer_def_S[fl_elem_SP->base_id].dim.width;
                 #endif
                }
            }
        }
        break;
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
        case GFX_MGR02_TYPE_FILL:
        {
            if(GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_SP->obj_id))
            {
             #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
                UINT32 fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(fl_elem_SP->obj_id);
                if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
                {
                    fl_element_width = l_anim_prop_SP->fill_prop[fl_obj_id_U32].dim.width;
                }
             #endif
            }
            else
            {
                if (fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS)
                {
                 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                    fl_element_width = hmi_gfx_mgr02_get_fill_layer_def_ptr(fl_elem_SP->base_id)->dim.width;
                 #else  
                    fl_element_width = lc_fill_layer_def_S[fl_elem_SP->base_id].dim.width;
                 #endif
                }
            }
        }
        break;
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
        case GFX_MGR02_TYPE_USER_LAYER:
        {
           /* Need to Implement. */
        }
        break;
#endif
#if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
        case GFX_MGR02_TYPE_SVG:
        {
            if (fl_elem_SP->base_id < GFX_MGR02_NUM_OF_SVGS)
            {
                #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_element_width = (u_gx_flocal)(hmi_gfx_mgr02_get_svg_layer_def_ptr(fl_elem_SP->base_id)->bounds[2] + 0.5);
                #else
                fl_element_width = (u_gx_flocal)(lc_svg_layer_def_S[fl_elem_SP->base_id].bounds[2] + 0.5);
                #endif
            }
        }
        break;
#endif
        default:
        {
            /*For MISRA warning fix.*/
        }
        break;
    }
    return(fl_element_width);
}
#if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
/****************************************************************************
Function Name     : hmi_gfx_mgr02_get_element_xposinfo()
Description       : fetches the element x position.
Invocation        : Invoked by hmi_gfx_mgr02_generic_build_aligned_widget.
Return Value      : None
Parameters        : static widget stack pointer
******************************************************************************/
static SINT16 hmi_gfx_mgr02_get_element_xposinfo(GFX_MGR02_ELEM_LIST_T const * p_elem_SP)
{
   UINT32       fl_obj_id_U32;
   SINT16       fl_element_xpos = 0;

   fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   switch(GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id))
   {
   #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
      case GFX_MGR02_TYPE_DIMAGE:
      {
        GFX_MGR02_IMAGE_PROPERTY const * fl_elem_prop_SP;
       #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
        GFX_MGR02_IMAGE_DYN_PROPERTY   * fl_elem_anim_prop_SP;
       #endif
      #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
         p_elem_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_SP);
      #else
         p_elem_SP = GFX_MGR02_NULL_PTR;
      #endif
         if(p_elem_SP != GFX_MGR02_NULL_PTR)
         {
           fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
           /* Check the image is animable or non-animable */
           if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
           {
            #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
              fl_elem_anim_prop_SP = &l_anim_prop_SP->image_prop[fl_obj_id_U32];
              fl_element_xpos = fl_elem_anim_prop_SP->coord.x;
            #endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */
           }
           else
           {
            #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
              #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_elem_prop_SP = hmi_gfx_mgr02_get_image_const_prop_ptr(fl_obj_id_U32);
              #else
                fl_elem_prop_SP = &lc_img_const_property_S[fl_obj_id_U32];
              #endif
              fl_element_xpos = fl_elem_prop_SP->coord.x;
            #endif /* #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0 */
           }
         }
      }
      break;
      case GFX_MGR02_TYPE_SIMAGE:
      {
        #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
         GFX_MGR02_IMAGE_PROPERTY const * fl_elem_prop_SP;
         #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            fl_elem_prop_SP = hmi_gfx_mgr02_get_image_const_prop_ptr(fl_obj_id_U32);
         #else
            fl_elem_prop_SP = &lc_img_const_property_S[fl_obj_id_U32];
         #endif
         fl_element_xpos = fl_elem_prop_SP->coord.x;
        #endif
      }
      break;
   #endif
   #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
      case GFX_MGR02_TYPE_STEXT:
      case GFX_MGR02_TYPE_DTEXT:
      {
        /* Check the text is animable or non-animable */
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
        {
         #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
           GFX_MGR02_TEXT_DYN_PROPERTY   * fl_elem_anim_prop_SP;

           fl_elem_anim_prop_SP = &l_anim_prop_SP->text_prop[fl_obj_id_U32];
           fl_element_xpos = fl_elem_anim_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
        }
        else
        {
         #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
           GFX_MGR02_TEXT_PROPERTY const * fl_elem_prop_SP;
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
             fl_elem_prop_SP = hmi_gfx_mgr02_get_txt_const_prop_ptr(fl_obj_id_U32);
           #else
             fl_elem_prop_SP = &lc_text_const_property_S[fl_obj_id_U32];
           #endif
              fl_element_xpos = fl_elem_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_TEXT_INSTANCES > 0 */
        }
        if(hmi_gfx_mgr02_generic_is_element_right_aligned_text(p_elem_SP) != FALSE)
        {
          SINT16 fl_widget_width   = (SINT16)hmi_gfx_mgr02_get_element_widthinfo(p_elem_SP);
          fl_element_xpos =  (fl_element_xpos - fl_widget_width);
        }
      }
      break;
   #endif
   #if GFX_MGR02_NUM_OF_TILES > 0
      case GFX_MGR02_TYPE_TILE:
      {
        /* Check the tile is animable or non-animable */
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
        {
         #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
          GFX_MGR02_TILE_DYN_PROPERTY   * fl_elem_anim_prop_SP;
          fl_elem_anim_prop_SP = &l_anim_prop_SP->tile_prop[fl_obj_id_U32];
          fl_element_xpos = fl_elem_anim_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */
        }
        else
        {
         #if GFX_MGR02_NUM_TILE_INSTANCES > 0
           GFX_MGR02_TILE_PROPERTY const * fl_elem_prop_SP;
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
             fl_elem_prop_SP = hmi_gfx_mgr02_get_tile_const_prop_ptr(fl_obj_id_U32);
           #else
             fl_elem_prop_SP = &lc_tile_const_property_S[fl_obj_id_U32];
           #endif
            fl_element_xpos = fl_elem_prop_SP->coord.x;
          #endif /* #if GFX_MGR02_NUM_TILE_INSTANCES > 0 */
        }
      }
      break;
   #endif
   #if GFX_MGR02_NUM_OF_FILLS > 0
      case GFX_MGR02_TYPE_FILL:
      {
        /* Check the fill is animable or non-animable */
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
        {
         #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
          GFX_MGR02_FILL_DYN_PROPERTY   * fl_elem_anim_prop_SP;
          fl_elem_anim_prop_SP = &l_anim_prop_SP->fill_prop[fl_obj_id_U32];
          fl_element_xpos = fl_elem_anim_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
        }
        else
        {
         #if GFX_MGR02_NUM_FILL_INSTANCES > 0
           GFX_MGR02_FILL_PROPERTY const * fl_elem_prop_SP;
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
             fl_elem_prop_SP = hmi_gfx_mgr02_get_fill_const_prop_ptr(fl_obj_id_U32);
           #else
             fl_elem_prop_SP = &lc_fill_const_property_S[fl_obj_id_U32];
           #endif
            fl_element_xpos = fl_elem_prop_SP->coord.x;
          #endif /* #if GFX_MGR02_NUM_FILL_INSTANCES > 0 */
        }
      }
      break;
   #endif
   #if GFX_MGR02_NUM_USER_LAYERS > 0
      case GFX_MGR02_TYPE_USER_LAYER:
      {
           /* Need to Implement. */
      }
      break;
   #endif
   #if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2))
      case GFX_MGR02_TYPE_SVG:
      {
        /* Check the svg image is animable or non-animable */
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
        {       
         #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
           GFX_MGR02_OVG_DYN_PROPERTY   * fl_elem_anim_prop_SP;
           fl_elem_anim_prop_SP = &l_anim_prop_SP->svg_prop[fl_obj_id_U32];
           fl_element_xpos = fl_elem_anim_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0 */
        }
        else
        {   
         #if GFX_MGR02_NUM_SVG_INSTANCES > 0
           GFX_MGR02_OVG_PROPERTY const * fl_elem_prop_SP;
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
             fl_elem_prop_SP = hmi_gfx_mgr02_get_svg_const_prop_ptr(fl_obj_id_U32);
           #else
             fl_elem_prop_SP = &lc_svg_const_property_S[fl_obj_id_U32];
           #endif
           fl_element_xpos = fl_elem_prop_SP->coord.x;
         #endif /* #if GFX_MGR02_NUM_SVG_INSTANCES > 0 */
        }
      }
      break;
   #endif
      default:
      {
          /*For MiSRA warning fix.*/
      }
      break;
   }
   return(fl_element_xpos);
}
#endif

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_is_element_right_aligned_text()
Description          : Returns if the passed element is a right aligned text or not.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_aligned_widget.
Return Value         : UINT8
Parameters           : Static widget stack pointer
******************************************************************************/
static UINT8 hmi_gfx_mgr02_generic_is_element_right_aligned_text(GFX_MGR02_ELEM_LIST_T const * p_widget_elem_SP)
{
    UINT8 fl_is_right_aligned_text = FALSE;
    if(((GFX_MGR02_GET_OBJ_TYPE(p_widget_elem_SP->obj_id) == GFX_MGR02_TYPE_STEXT) || 
    (GFX_MGR02_GET_OBJ_TYPE(p_widget_elem_SP->obj_id) == GFX_MGR02_TYPE_DTEXT)))
    {
      UINT8 fl_alignment = (UINT8)0;
      #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
      UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_widget_elem_SP->obj_id);
      if(GFX_MGR02_IS_DYNAMIC_PROP(p_widget_elem_SP->obj_id))
      {
        if (fl_obj_id < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
        {
            fl_alignment = (UINT8)l_anim_prop_SP->text_prop[fl_obj_id].alignment;
        }
      }
      else
      #endif
      {
        if(p_widget_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
        {
            #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_widget_elem_SP->base_id);
            #else
            GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = &lc_text_layer_def_S[p_widget_elem_SP->base_id];
            #endif
            fl_alignment = (UINT8)fl_text_desc_SP->alignment;
        }
      }
      if(fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
      {
        fl_is_right_aligned_text = TRUE;
      }
    }
    else
    {
    }
    return fl_is_right_aligned_text;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_aligned_widget()
Description          : builds the aligned widget elements.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_widget.
Return Value         : None
Parameters           : Static widget stack pointer
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static void hmi_gfx_mgr02_generic_build_aligned_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_obj_dirty_U8)
{
  if(p_elem_SP->child != GFX_MGR02_NULL_PTR)
  {
#if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
      SINT16                      * fl_elems_posns;
      u_gx_flocal                 * fl_wdg_elems_index;
    #if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
      /* for mqx use uncached memory for malloc */
      fl_elems_posns       = (SINT16 *)_mem_alloc_system((sizeof(SINT16)) * p_elem_SP->num_child_elements);
      fl_wdg_elems_index   = (u_gx_flocal *)_mem_alloc_system((sizeof(u_gx_flocal)) * p_elem_SP->num_child_elements);
    #else
      fl_elems_posns       = (SINT16 *)malloc((sizeof(SINT16)) * p_elem_SP->num_child_elements);
      fl_wdg_elems_index   = (u_gx_flocal *)malloc((sizeof(u_gx_flocal)) * p_elem_SP->num_child_elements);
    #endif
    if((fl_elems_posns != GFX_MGR02_NULL_PTR) && (fl_wdg_elems_index != GFX_MGR02_NULL_PTR))
#endif
    {
      u_gx_flocal                   fl_wdgt_element_index;
      u_gx_flocal                   fl_widget_element_width;
      u_gx_flocal                   fl_widget_width;
      u_gx_flocal                   fl_elem_total_width = 0U;
      u_gx_flocal                   fl_inter_elem_space;
      GFX_MGR02_ILOC_DATA           fl_coord = {0,0};
      GFX_MGR02_ELEM_LIST_T const * fl_widget_elem_SP;
      GFX_MGR02_CONTEXT_STATE_T     fl_cur_context_S;
      GFX_MGR02_WIDGET_DEF_T const* fl_element_def_SP;
#if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
      u_gx_flocal                   fl_x,fl_y;
#endif

    #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
      fl_elems_posns[0]=0;
      fl_wdg_elems_index[0]=0U;
    #endif
      hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);
      fl_widget_elem_SP = &p_elem_SP->child[0];
      fl_widget_width   = hmi_gfx_mgr02_get_element_widthinfo(fl_widget_elem_SP);

      /* Build the Fill element to clear the graphics visible area. */
      hmi_gfx_mgr02_generic_build_group(1U, fl_widget_elem_SP, GFX_MGR02_ALIGNED_WIDGET_INIT, p_obj_dirty_U8);
      fl_wdgt_element_index = 1U;
      
      if(p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
      {
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
          fl_element_def_SP = hmi_gfx_mgr02_get_swidget_layer_def_ptr(p_elem_SP->base_id);
        #else
          fl_element_def_SP = &lc_swidget_layer_def_S[p_elem_SP->base_id];
        #endif

          fl_inter_elem_space   = fl_element_def_SP->inter_element_space;
          while(fl_wdgt_element_index < p_elem_SP->num_child_elements)
          {
             fl_widget_elem_SP = &p_elem_SP->child[fl_wdgt_element_index];
             fl_widget_element_width = hmi_gfx_mgr02_get_element_widthinfo(fl_widget_elem_SP);
             if(fl_widget_width >= (fl_widget_element_width + fl_elem_total_width))
             {
                  /* Only when valid element is selected and width is > 0 then interelement spacing need to be added */
                  if(fl_widget_element_width != (UINT8)0)
                  {
                    fl_elem_total_width += (fl_widget_element_width + fl_inter_elem_space);
                  }
             }
             else
             {
               fl_elem_total_width = fl_widget_width;
             }
         #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
             fl_elems_posns[fl_wdgt_element_index] = hmi_gfx_mgr02_get_element_xposinfo(fl_widget_elem_SP);
             fl_wdg_elems_index[fl_wdgt_element_index]=fl_wdgt_element_index;
         #endif
             fl_wdgt_element_index++;
          }
          if(fl_element_def_SP->alignment == (UINT8)GFX_MGR02_WP_ALIGN_CENTRE)
          {
             fl_coord.x = (((SINT16)fl_widget_width + 1) - (SINT16)fl_elem_total_width)/2;
          }
          else if(fl_element_def_SP->alignment == (UINT8)GFX_MGR02_WP_ALIGN_RIGHT)
          {
             /* For the last element also interelem space is getting added which should not happen */
             /* A right aligned element should start from the right corner */
             fl_elem_total_width = fl_elem_total_width - fl_inter_elem_space;
             fl_coord.x = ((SINT16)fl_widget_width - (SINT16)fl_elem_total_width);
          }
          else
          {
              /*For MISRA warning fix.*/
          }
          hmi_gfx_mgr02_context_set_loc(&fl_coord);
      #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
         /* Sort the widget elements indexes based on their x values */
          for(fl_x=1U; fl_x<p_elem_SP->num_child_elements; fl_x++)
          {
            for(fl_y=1U; fl_y<(p_elem_SP->num_child_elements-1U); fl_y++)
            {
              if(fl_elems_posns[fl_y] > fl_elems_posns[fl_y+1U])
              {
                SINT16 fl_temp = fl_elems_posns[fl_y+1U];
                UINT8 fl_temp2 = fl_wdg_elems_index[fl_y+1U];
                fl_elems_posns[fl_y+1U] = fl_elems_posns[fl_y];
                fl_wdg_elems_index[fl_y+1U] = fl_wdg_elems_index[fl_y];
                fl_elems_posns[fl_y] = fl_temp;
                fl_wdg_elems_index[fl_y] = fl_temp2;
              }
            }
          }
          fl_x = 1U;
          fl_wdgt_element_index = fl_wdg_elems_index[fl_x];
          while((fl_x < p_elem_SP->num_child_elements) && (fl_elem_total_width > (u_gx_flocal)0))
      #else
          fl_wdgt_element_index = 1U;
          while((fl_wdgt_element_index < p_elem_SP->num_child_elements) && (fl_elem_total_width > (u_gx_flocal)0))
      #endif
          {
             fl_widget_elem_SP = &p_elem_SP->child[fl_wdgt_element_index];
             fl_coord.x  = (SINT16)hmi_gfx_mgr02_get_element_widthinfo(fl_widget_elem_SP);
             /* Only when valid element is selected and width is > 0 then interelement spacing need to be added and element need to be built */
             if(((SINT16)fl_elem_total_width >= fl_coord.x) )
             {
               if (fl_coord.x > 0)
               {
                 fl_elem_total_width = (fl_elem_total_width - (u_gx_flocal)fl_coord.x);
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
                 if (hmi_gfx_mgr02_generic_is_element_right_aligned_text(fl_widget_elem_SP) != FALSE)
                 {
                   fl_coord.x = fl_coord.x - 1;
                   hmi_gfx_mgr02_context_set_loc(&fl_coord);
                   hmi_gfx_mgr02_generic_build_group(1U, fl_widget_elem_SP, GFX_MGR02_ALIGNED_WIDGET_BUILD, p_obj_dirty_U8);
                   fl_coord.x = (SINT16)fl_inter_elem_space;
                   hmi_gfx_mgr02_context_set_loc(&fl_coord);
                 }
                 else
#endif
                 {
                   hmi_gfx_mgr02_generic_build_group(1U, fl_widget_elem_SP, GFX_MGR02_ALIGNED_WIDGET_BUILD, p_obj_dirty_U8);
                   fl_coord.x += (SINT16)fl_inter_elem_space;
                   hmi_gfx_mgr02_context_set_loc(&fl_coord);
                 }
               }
             }
             else if(((GFX_MGR02_GET_OBJ_TYPE(fl_widget_elem_SP->obj_id) == GFX_MGR02_TYPE_STEXT) || 
                     (GFX_MGR02_GET_OBJ_TYPE(fl_widget_elem_SP->obj_id) == GFX_MGR02_TYPE_DTEXT)))
             {
             #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
                 /* Element type is STEXT/ DTEXT add the ClipText */
                 hmi_gfx_mgr02_generic_build_text(fl_widget_elem_SP, GFX_MGR02_ALIGNED_WIDGET_BUILD, fl_elem_total_width, p_obj_dirty_U8);
             #endif
                 fl_elem_total_width = 0U;
             }
             else
             {
                 /*For MISRA warning fix.*/
             }
             if(fl_inter_elem_space > (u_gx_flocal)0)
             {
                if(fl_elem_total_width > fl_inter_elem_space)
                {
                  /* Only when valid element is selected and width is > 0 then interelement spacing will be added above so need not subtract */
                  if(fl_coord.x != 0)
                  {
                    fl_elem_total_width -= fl_inter_elem_space;
                  }
                }
                else
                {
                   fl_elem_total_width  = 0U;
                }
             }
         #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
             fl_x++;
             fl_wdgt_element_index = fl_wdg_elems_index[fl_x];
         #else
             fl_wdgt_element_index++;
         #endif
          }
         hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
      }
    }
    #if defined(GFX_MGR02_ALLIGN_WDG_ELEMS_BASED_ON_X)
      #if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
        if(fl_elems_posns != GFX_MGR02_NULL_PTR)
        {
          _mem_free(fl_elems_posns);
        }
        if(fl_wdg_elems_index != GFX_MGR02_NULL_PTR)
        {
          _mem_free(fl_wdg_elems_index);
        }
      #else
        if(fl_elems_posns != GFX_MGR02_NULL_PTR)
        {
          free(fl_elems_posns);
        }
        if(fl_wdg_elems_index != GFX_MGR02_NULL_PTR)
        {
          free(fl_wdg_elems_index);
        }
      #endif
     #endif
  }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_widget()
Description          : Checks the widget elements and builds them.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Static widget stack pointer
******************************************************************************/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static void hmi_gfx_mgr02_generic_build_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_obj_dirty_U8)
{
   UINT32                            fl_obj_id_U32;
   UINT32                            fl_obj_type_U32;
   GFX_MGR02_WIDGET_DEF_T const    * fl_element_def_SP;
   GFX_MGR02_ELEM_LIST_T const * fl_elem_SP = p_elem_SP;
   u_gx_flocal fl_obj_dirty_U8 = p_obj_dirty_U8;
#if (GFX_MGR02_NUM_SWDG_INSTANCES > 0) || defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
   GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
#endif
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
  const GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
#if GFX_MGR02_NUM_SWDG_INSTANCES > 0
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   GFX_MGR02_IAREA_DATA              fl_clip_area_SP={0,0,0,0};
#endif
#endif
   GFX_MGR02_CONTEXT_STATE_T         fl_cur_context_S;

   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   fl_obj_id_U32   = GFX_MGR02_GET_OBJ_ID(fl_elem_SP->obj_id);
   fl_obj_type_U32 = GFX_MGR02_GET_OBJ_TYPE(fl_elem_SP->obj_id);
   
   if(fl_obj_type_U32 == GFX_MGR02_TYPE_SWIDGET)
   {
        if (fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
        {
        /* if widget is animable element */
        #if defined(GFX_MGR02_DLAYOUT_ENABLED)
          fl_element_def_SP = hmi_gfx_mgr02_get_swidget_layer_def_ptr(fl_elem_SP->base_id);
        #else
          fl_element_def_SP = &lc_swidget_layer_def_S[fl_elem_SP->base_id];
        #endif
          
        #if defined(GFX_MGR02_IMXRT)
          if(fl_element_def_SP->client_id != (UINT16)GFX_MGR02_INVALID_CLIENT_ID)
          { 
                #if defined(GFX_MGR02_VGLITE)
                if(fl_element_def_SP->rr_engine == GFX_MGR02_RT_VGLITE)
                {
                    l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_VGLITE];
                }
                else /* GFX_MGR02_RT_DEFAULT */
                #endif
                {
                    l_lib_if_SP = &l_sw_ovg_lib_interfaces_SA[GFX_MGR02_GEN_TARGET_IMXRT_PXP];
                }    
          }              
        #endif
        
          if(GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_SP->obj_id))
          {
          #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
             if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
             {				 
                 fl_elem_anim_prop_SP = &l_anim_prop_SP->widget_prop[fl_obj_id_U32];
               #if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
                 {
                   /*
                   ** If kepler platform present then widget co-ordinates indicate
                   ** actual location, but ovg and swr handles only offset co-orinate for
                   ** widgets.
                   */
                   GFX_MGR02_ILOC_DATA  fl_coord;
                 #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                   fl_elem_prop_SP = hmi_gfx_mgr02_get_widget_anim_prop_ptr(fl_obj_id_U32);
                 #else
                   fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id_U32];
                 #endif
                   fl_coord.x = fl_elem_anim_prop_SP->coord.x;
                   fl_coord.y = fl_elem_anim_prop_SP->coord.y;
                   fl_coord.x -= fl_elem_prop_SP->coord.x;
                   fl_coord.y -= fl_elem_prop_SP->coord.y;
                   hmi_gfx_mgr02_context_set_loc(&fl_coord);
                 }
               #else           
                 hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
               #endif       
                 hmi_gfx_mgr02_context_set_alpha(fl_elem_anim_prop_SP->alpha);
               #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                 if(fl_element_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                 {
                    hmi_gfx_mgr02_context_set_clip(&fl_elem_anim_prop_SP->clip);
                 }
               #endif
               #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                 hmi_gfx_mgr02_context_set_matrix(l_anim_prop_SP->widget_ovg_prop[fl_obj_id_U32].matrix);
                 hmi_gfx_mgr02_context_set_pivot(&l_anim_prop_SP->widget_ovg_prop[fl_obj_id_U32].pivot);
               #endif
             }
          #endif /* #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 */
          }
          else
          {
          #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
             if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
             {				 
               #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                 fl_elem_prop_SP         = hmi_gfx_mgr02_get_swidget_const_prop_ptr(fl_obj_id_U32);
               #else
                 fl_elem_prop_SP         = &lc_swdg_const_property_S[fl_obj_id_U32];
               #endif
               #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                 if(fl_element_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                 {
                   #if defined(GFX_MGR02_DLAYOUT_ENABLED)  
                   GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr=hmi_gfx_mgr02_get_elem_area_offset_ptr(fl_element_def_SP->clip_index);
                   #else
                    GFX_MGR02_VISIBLE_AREA const* fl_elem_offset_ptr = GFX_MGR02_NULL_PTR; 
                    if(fl_element_def_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
                    {                       
                      fl_elem_offset_ptr= &lc_elem_area_offset_SA[fl_element_def_SP->clip_index];   
                    }
                   #endif
                    if(fl_elem_offset_ptr != GFX_MGR02_NULL_PTR)
                    {
                      fl_clip_area_SP.x       = fl_elem_offset_ptr->sx;
                      fl_clip_area_SP.y       = fl_elem_offset_ptr->sy;
                      fl_clip_area_SP.width   = (UINT16)fl_elem_offset_ptr->ex;          
                      fl_clip_area_SP.height  = (UINT16)fl_elem_offset_ptr->ey;
                      hmi_gfx_mgr02_context_set_clip(&fl_clip_area_SP);
                    }
                 }
               #endif
                 hmi_gfx_mgr02_context_set_alpha(fl_elem_prop_SP->alpha);
               #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                 hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
                 hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
               #endif
             }
          #endif /*#if GFX_MGR02_NUM_SWDG_INSTANCES > 0*/
          }
          #if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
          if((fl_element_def_SP->mask_mode != GFX_MGR02_MASK_WIDGET_DISABLED) &&
             ((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW)))
          {
             GFX_MGR02_CONTEXT_T * fl_context_sp;
             GFX_MGR02_ELEM_LIST_T const * fl_mask_content_sp;
             fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
             #if defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
             hmi_gfx_mgr02_generic_build_mask_element(fl_context_sp, fl_elem_SP->child,(u_gx_flocal)GFX_MGR02_GENERIC_BUILD,fl_obj_dirty_U8); 
             fl_mask_content_sp = fl_elem_SP->child;
             fl_mask_content_sp++;
             hmi_gfx_mgr02_context_set_maskmode(fl_element_def_SP->mask_mode);
             hmi_gfx_mgr02_amber_set_mask_mode(fl_context_sp);
             if(fl_obj_dirty_U8 == (u_gx_flocal)FALSE)
             {
                if(hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_SP->child, TRUE) != FALSE)
                {
                   fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
                }
             }
             /* Build all the element in the mask content widget if any of the elemnt in mask image widget is changed*/
             hmi_gfx_mgr02_generic_build_group((u_gx_flocal)fl_mask_content_sp->num_child_elements, 
                                                  fl_mask_content_sp->child, 
                                                  (u_gx_flocal)GFX_MGR02_GENERIC_BUILD,
                                                  fl_obj_dirty_U8);
             hmi_gfx_mgr02_context_set_masksurf(GFX_MGR02_NULL_PTR);
             hmi_gfx_mgr02_context_set_maskmode(GFX_MGR02_MASK_WIDGET_DISABLED);
             hmi_gfx_mgr02_amber_set_mask_mode(fl_context_sp);
             hmi_gfx_mgr02_amber_bind_mask_surf(fl_context_sp,fl_context_sp->rprop.pe_msurf);
             #endif
             

             #if defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FARADAY)
             /* if any of the elements in the mask widget(parent) is changed , then build all the elements(mask, actual image) */
             hmi_gfx_mgr02_context_set_maskmode(fl_element_def_SP->mask_mode);
             hmi_gfx_mgr02_ovglib_set_mask_mode(fl_context_sp);
             hmi_gfx_mgr02_generic_build_mask_element(fl_context_sp,
                                                      fl_elem_SP->child,
                                                      (u_gx_flocal)GFX_MGR02_GENERIC_BUILD,
                                                      fl_obj_dirty_U8);
             fl_mask_content_sp = fl_elem_SP->child;
             fl_mask_content_sp++;
             hmi_gfx_mgr02_context_set_maskmode(GFX_MGR02_MASK_WIDGET_DISABLED);
             /* Build all the element in the mask content widget if any of the elemnt in mask image widget is changed*/
             hmi_gfx_mgr02_generic_build_mask_element(fl_context_sp,
                                                      fl_mask_content_sp,
                                                      (u_gx_flocal)GFX_MGR02_GENERIC_BUILD,
                                                      fl_obj_dirty_U8);


             /*mask mode is already disabled above build group */
             hmi_gfx_mgr02_ovglib_set_mask_mode(fl_context_sp);
             #endif

          }
          else
          #endif
          {
           #if defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FARADAY)
             #if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
             /* if any of the elements in the mask widget(parent) is changed , then build all the elements(mask, actual image) */
             if((fl_element_def_SP->mask_mode != GFX_MGR02_MASK_WIDGET_DISABLED) &&
                (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS))
             {
                if(fl_obj_dirty_U8 == (u_gx_flocal)FALSE)
                {
                   if(hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_SP, TRUE) != FALSE)
                   {
                      fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
                   }
                }
             }
             #endif
           #endif
             if(fl_element_def_SP->alignment == (UINT8)GFX_MGR02_WP_ALIGN_NONE)
             {
                hmi_gfx_mgr02_generic_build_group((u_gx_flocal)fl_elem_SP->num_child_elements, 
                                                  fl_elem_SP->child, 
                                                  (u_gx_flocal)GFX_MGR02_GENERIC_BUILD,
                                                  fl_obj_dirty_U8);
             }
             else
             {
                /* Build aligned widgets */
                if(fl_obj_dirty_U8 == (u_gx_flocal)FALSE)
                {
                   /*
                   ** If anything in an aligned widget changes, we have to rebuild the whole widget
                   ** itself, so check to see if any child elements inside the widget has changes
                   */
                   if(hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_SP, TRUE) != FALSE)
                   {
                      fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
                   }
                }
                hmi_gfx_mgr02_generic_build_aligned_widget(fl_elem_SP, fl_obj_dirty_U8);
             }
          }
       }
   }
#if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0)
   else
   {
      if((fl_elem_SP->child != GFX_MGR02_NULL_PTR) && (fl_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_DYNAMIC_WIDGETS))
      {
         #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
         if((GFX_MGR02_IS_DYNAMIC_PROP(fl_elem_SP->obj_id) && (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS)))
         {
            hmi_gfx_mgr02_context_set_loc(&l_anim_prop_SP->group_loc[fl_obj_id_U32]);
            hmi_gfx_mgr02_context_set_alpha(l_anim_prop_SP->group_alpha[fl_obj_id_U32]);
         }
         #endif
         fl_elem_SP = hmi_gfx_mgr02_layout_get_selected_swidget(fl_elem_SP);
         if(fl_elem_SP != GFX_MGR02_NULL_PTR)
         {
            /* Recursive call */
            if(hmi_gfx_mgr02_layout_is_element_changed(fl_elem_SP->base_id, fl_elem_SP->obj_id) != (UINT32)FALSE)
            {
               fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
            }
            hmi_gfx_mgr02_generic_build_widget(fl_elem_SP, fl_obj_dirty_U8);
         }
      }
   }
#endif
    hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
}
#endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
#if (GFX_MGR02_NUM_MASK_WIDGETS>0) && (defined (GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_FARADAY))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_mask_widget()
Description          : Builds the mask elements like image,dimage and widget
Invocation           : Invoked by generic. and amber.c
Return Value         : None
Parameters           : context,element
******************************************************************************/
void hmi_gfx_mgr02_generic_build_mask_element(GFX_MGR02_CONTEXT_T      * fl_context_sp,
                                                  GFX_MGR02_ELEM_LIST_T const * p_elem_SP,
                                                  u_gx_flocal p_aligned_widget,
                                                  u_gx_flocal p_obj_dirty_U8)
{
    UINT32  fl_obj_type;

    fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id);
    if(fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
    {
       hmi_gfx_mgr02_generic_build_image(p_elem_SP,
                                      p_aligned_widget,
                                      p_obj_dirty_U8,
                                      TRUE);
 
    }
    else if(fl_obj_type == GFX_MGR02_TYPE_DIMAGE)
    {
       hmi_gfx_mgr02_generic_build_dimage(p_elem_SP,
                                      p_aligned_widget,
                                      p_obj_dirty_U8,
                                      TRUE);

    }
    else if((fl_obj_type == GFX_MGR02_TYPE_SWIDGET)||(fl_obj_type == GFX_MGR02_TYPE_DWIDGET))  
    {
         hmi_gfx_mgr02_generic_build_widget(p_elem_SP,p_obj_dirty_U8);
    }	 
}
#endif

#if (GFX_MGR02_NUM_MASK_WIDGETS>0) && (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) ||defined(GFX_MGR02_TRAVEO2)) 
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_mask_widget()
Description          : Builds the mask elements like image,dimage and widget
Invocation           : Invoked by generic. and amber.c
Return Value         : None
Parameters           : context,element
******************************************************************************/
void hmi_gfx_mgr02_generic_build_mask_element(GFX_MGR02_CONTEXT_T      * fl_context_sp,
                                                  GFX_MGR02_ELEM_LIST_T const * p_elem_SP,
                                                  u_gx_flocal p_aligned_widget,
                                                  u_gx_flocal p_obj_dirty_U8)
{
  UINT32  fl_obj_type;
  GFX_MGR02_WIDGET_DEF_T const *  fl_widget_desc_SP;
  GFX_MGR02_IMAGE_DEF_T   *  fl_image_desc_SP;
  GFX_MGR02_CONTEXT_GB_T          fl_build_elem_S;
  GFX_MGR02_CONTEXT_RENDER_PROP_T fl_cur_context_ren_S;
  GFX_MGR02_CONTEXT_STATE_T       fl_cur_context_state_S;

  fl_build_elem_S.area.x =0;
  fl_build_elem_S.area.y =0;
  fl_build_elem_S.area.width = 0U;
  fl_build_elem_S.area.height = 0U;
  fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id);
  if(fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
  {
     hmi_gfx_mgr02_generic_build_image(p_elem_SP,
                                    p_aligned_widget,
                                    p_obj_dirty_U8,
                                    TRUE);
  }
  #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
  else if(fl_obj_type == GFX_MGR02_TYPE_DIMAGE)
  {
     hmi_gfx_mgr02_generic_build_dimage(p_elem_SP,
                                    p_aligned_widget,
                                    p_obj_dirty_U8,
                                    TRUE);
  }
  #endif
  else
  {
    /* widget */
    UINT32 fl_obj_id  = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
    if(p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
    {
      fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_SP->base_id];
      #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS>0
      if((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT) && 
        (fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE))
      {
        GFX_FLOAT  fl_bound[4] = {0.0F,0.0F,0.0F,0.0F};
        fl_image_desc_SP =  hmi_gfx_mgr02_amber_get_runtime_widget_ptr(fl_widget_desc_SP->image_id);
        if(fl_image_desc_SP != NULL)
        {
          if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
          {
            #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
            {
              UINT32 fl_aligned_width;
              UINT32 fl_aligned_height;
              GFX_MGR02_ANIM_DATA_T * fl_layer_anim_data_SP;
              GFX_MGR02_WIDGET_DYN_PROPERTY  * fl_widg_dyn_prop_SP = GFX_MGR02_NULL_PTR;
              fl_layer_anim_data_SP         = hmi_gfx_mgr02_layout_get_anim_data();
              fl_widg_dyn_prop_SP          = &fl_layer_anim_data_SP->widget_prop[fl_obj_id];
              
              #if defined(GFX_MGR02_TRAVEO2)
              (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_SP, GFX_MGR02_TARGET_TRAVEO2, fl_bound);
              #else
              (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_SP, GFX_MGR02_TARGET_AMBER, fl_bound);
              #endif
              fl_widg_dyn_prop_SP->coord.x    = (SINT16)fl_bound[0];
              fl_widg_dyn_prop_SP->coord.y    = (SINT16)fl_bound[1];
              fl_build_elem_S.area.x = (SINT16)fl_bound[0];
              fl_build_elem_S.area.y = (SINT16)fl_bound[1];
              fl_bound[0] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.x; /* get any remaining fractional part */
              fl_bound[1] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.y;

              fl_aligned_width  = ((UINT32)fl_bound[2]+(UINT32)fl_bound[0]+(UINT32)0.5);
              fl_aligned_height = ((UINT32)fl_bound[3]+(UINT32)fl_bound[1]+(UINT32)0.5);
              fl_image_desc_SP->width  = (GFX_MGR02_ISIZE_W_T)(fl_aligned_width);
              fl_image_desc_SP->height = (GFX_MGR02_ISIZE_H_T)(fl_aligned_height);
              fl_build_elem_S.area.width  = fl_image_desc_SP->width;
              fl_build_elem_S.area.height = fl_image_desc_SP->height;
            }
            #endif
          }            
          else
          {
            fl_image_desc_SP->width  = (UINT16)0;
            fl_image_desc_SP->height = (UINT16)0;
            #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
            {
              fl_build_elem_S.area.x = lc_swdg_const_property_S[fl_obj_id].coord.x;
              fl_build_elem_S.area.y = lc_swdg_const_property_S[fl_obj_id].coord.y;
            }
            #endif
          }
        }
        fl_build_elem_S.clr_buffer = TRUE;
        /* if color taken from fl_widget_desc_SP->bg_fill_color, then alpha should be kept zero ,otherwise 
          mask feature will considered that alpha value and display below screen*/
        fl_build_elem_S.clr_color  = 0;
      }
      else
      #endif
      {
        #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0 
        if(fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
        {
          fl_build_elem_S.area.width = lc_image_layer_def_S[fl_widget_desc_SP->image_id].width;
          fl_build_elem_S.area.height = lc_image_layer_def_S[fl_widget_desc_SP->image_id].height;
        }
        #endif
        if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
        {
          fl_build_elem_S.area.x = lc_widget_anim_property_S[fl_obj_id].coord.x;
          fl_build_elem_S.area.y = lc_widget_anim_property_S[fl_obj_id].coord.y;
        }
        /* clear buffer is set TRUE as there is no dirty logic run for mask widget.dirty_area set as FALSE*/
        fl_build_elem_S.clr_buffer = TRUE;
        /* if color taken from fl_widget_desc_SP->bg_fill_color, then alpha should be kept zero ,otherwise 
            mask feature will considered that alpha value and display below screen*/
        fl_build_elem_S.clr_color = 0;
      }
      fl_build_elem_S.fb_format   = fl_widget_desc_SP->fb_format;
      hmi_gfx_mgr02_context_render_get(&fl_cur_context_ren_S);
      hmi_gfx_mgr02_context_state_get(&fl_cur_context_state_S);
      fl_build_elem_S.client_id  = (UINT32)fl_widget_desc_SP->client_id;
      #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
      fl_build_elem_S.fb_group_id   = fl_widget_desc_SP->fb_group_id;
      #endif
      #if defined(GFX_MGR02_TRAVEO2)
      fl_build_elem_S.fb_target  = GFX_MGR02_TARGET_TRAVEO2;
      #else
      fl_build_elem_S.fb_target  = GFX_MGR02_TARGET_AMBER;
      #endif
      #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      fl_build_elem_S.pe_sync    = fl_context_sp->rprop.pe_sync;
      #endif
      fl_build_elem_S.render_buffer = NULL;
      #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0
      fl_build_elem_S.pe_tsurf = NULL;
      #if GFX_MGR02_NUM_MASK_WIDGETS>0
      fl_build_elem_S.pe_msurf = NULL;
      fl_build_elem_S.mask_mode = GFX_MGR02_MASK_WIDGET_DISABLED;
      #endif
      #endif
      #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
      fl_build_elem_S.use_extram    = fl_widget_desc_SP->use_extram;
      #endif
      #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)|| defined(GFX_MGR02_AMBER_IRIS)
      fl_build_elem_S.dirty_area = FALSE;
      #endif
      
      #if defined(GFX_MGR02_TRAVEO2)
      fl_build_elem_S.render_mode = fl_widget_desc_SP->render_mode; 
      fl_build_elem_S.wdg_height  = fl_widget_desc_SP->wdg_height;
      fl_build_elem_S.priority = fl_widget_desc_SP->priority;
      #endif
      /* return not considered as any way it will rendered along with src image*/
      (void)hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, p_elem_SP);
      hmi_gfx_mgr02_context_render_set(&fl_cur_context_ren_S);
      hmi_gfx_mgr02_context_state_set(&fl_cur_context_state_S);
      if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
      {
        #if defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
        hmi_gfx_mgr02_context_set_masksurf(fl_build_elem_S.pe_tsurf);
        hmi_gfx_mgr02_amber_set_mask_attributes(fl_context_sp,(SINT32)fl_build_elem_S.area.x,(SINT32)fl_build_elem_S.area.y); 
        #endif
      }
    }
  }
  hmi_gfx_mgr02_context_state_get(&fl_cur_context_state_S);
}
#endif
#if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_svg()
Description          : Builds the image
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Image stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_svg(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8)
{   
    UINT32                         fl_obj_id_U32;
    GFX_MGR02_OVG_OBJECT_T const * fl_element_def_SP;
#if GFX_MGR02_NUM_SVG_INSTANCES > 0
    GFX_MGR02_OVG_PROPERTY const * fl_elem_prop_SP;
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    GFX_MGR02_OVG_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
    GFX_MGR02_CONTEXT_STATE_T      fl_cur_context_S;

    hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);
    
    if (p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SVGS)
    {
        fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_element_def_SP = hmi_gfx_mgr02_get_svg_layer_def_ptr(p_elem_SP->base_id);
    #else
        fl_element_def_SP = &lc_svg_layer_def_S[p_elem_SP->base_id];
    #endif
        /* Check the image is animable or non-animable */
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
        {       
        #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
            if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_SVG_ANIM_ELEMENTS)
            {
                fl_elem_anim_prop_SP = &l_anim_prop_SP->svg_prop[fl_obj_id_U32];
                if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
                {
                   hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
                   if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                   {
                       fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
                   }
                }
                else
                {
                   GFX_MGR02_ILOC_DATA fl_aligned_loc;
                   fl_aligned_loc.x = 0;
                   fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
                   hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
                }
                hmi_gfx_mgr02_context_set_alpha(fl_elem_anim_prop_SP->alpha);
                hmi_gfx_mgr02_context_set_matrix(fl_elem_anim_prop_SP->matrix);
            #if defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                hmi_gfx_mgr02_context_set_pivot(&fl_elem_anim_prop_SP->pivot);
            #endif
            }
        #else
            return; /* This should never happen */
        #endif /* #if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0 */
        }
        else
        {   
        #if GFX_MGR02_NUM_SVG_INSTANCES > 0
            if(fl_obj_id_U32 < GFX_MGR02_NUM_SVG_INSTANCES)
            {
                #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_elem_prop_SP = hmi_gfx_mgr02_get_svg_const_prop_ptr(fl_obj_id_U32);
                #else
                fl_elem_prop_SP = &lc_svg_const_property_S[fl_obj_id_U32];
                #endif
                if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
                {
                   hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
                   if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                   {
                      fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
                   }
                }
                else
                {
                   GFX_MGR02_ILOC_DATA fl_aligned_loc;
                   fl_aligned_loc.x = (SINT16)0;
                   fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
                   hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
                }
                hmi_gfx_mgr02_context_set_alpha(fl_elem_prop_SP->alpha);
                hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
            #if defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
                hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
            #endif
            }
        #else
            return; /* This should never happen */
        #endif /* #if GFX_MGR02_NUM_SVG_INSTANCES > 0 */
        }
    #if GFX_MGR02_NUM_OF_SVG_CLIPS > 0
        if((fl_element_def_SP->clip_index > (UINT16)0) && ((fl_element_def_SP->clip_index < (UINT16)GFX_MGR02_NUM_OF_SVG_CLIPS)))
        {
           GFX_MGR02_IAREA_DATA const * fl_clip_SP = &lc_svg_clip_area_SA[fl_element_def_SP->clip_index];
           GFX_MGR02_ILOC_DATA          fl_loc_S;
           fl_loc_S.x = -fl_clip_SP->x;
           fl_loc_S.y = -fl_clip_SP->y;
           hmi_gfx_mgr02_context_set_loc(&fl_loc_S);
           hmi_gfx_mgr02_context_set_clip(fl_clip_SP);
        }
    #endif
        if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
        {
           gfxlogstop(GFX_LOG_PROCESSING);
           gfxlogcontinue(GFX_LOG_RENDERING);
           if(l_lib_if_SP->build_svg != GFX_MGR02_NULL_PTR)
           {
              GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
           #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
              if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW)
              {
                 GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                 if(fl_area_SP != GFX_MGR02_NULL_PTR)
                 {
                    hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                 }
                 else
                 {
                    hmi_gfx_mgr02_context_set_alpha(0);
                 }
              }
           #endif
              (void)l_lib_if_SP->build_svg(fl_context_SP, fl_element_def_SP);
           }
           gfxlogstop(GFX_LOG_RENDERING);
           gfxlogcontinue(GFX_LOG_PROCESSING);
        }
    #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
        else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
        {
           if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
           {
              GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
              GFX_MGR02_DAR_OBJECT  fl_dar_SP;
              GFX_FLOAT                 fl_bound[4];

              fl_bound[0] = fl_element_def_SP->bounds[0];
              fl_bound[1] = fl_element_def_SP->bounds[1];
              fl_bound[2] = fl_element_def_SP->bounds[2];
              fl_bound[3] = fl_element_def_SP->bounds[3];
              (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SVG, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);

              fl_dar_SP.opeque      = (UINT8)fl_element_def_SP->opeque;
              fl_dar_SP.elem_SP     = p_elem_SP;
              fl_dar_SP.dirty_area  = (UINT8)p_obj_dirty_U8;
              (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
           }
        }
    #endif
        else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
        {
           if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
           {
              GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
              GFX_FLOAT                 fl_bound[4];

              fl_bound[0] = fl_element_def_SP->bounds[0];
              fl_bound[1] = fl_element_def_SP->bounds[1];
              fl_bound[2] = fl_element_def_SP->bounds[2];
              fl_bound[3] = fl_element_def_SP->bounds[3];
              (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SVG, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
              hmi_gfx_mgr02_generic_add_bound(fl_bound);
           }
        }
        else
        { 
            /* To fix MISRA Warning c-2012 15.7 */
        }
        hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
    }
}
#endif /*(GFX_MGR02_NUM_OF_SVGS > 0) && defined(GFX_MGR02_OPEN_VG)*/

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_dimage()
Description          : Builds the dynamic image
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Image stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_dimage(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8, u_gx_flocal p_mask_enabled)
{   
   UINT32                           fl_obj_type_U32;
   GFX_MGR02_CONTEXT_STATE_T        fl_cur_context_S;
   GFX_MGR02_CONTEXT_STATE_T const *fl_cur_context_const_SP= &fl_cur_context_S;
   GFX_MGR02_ELEM_LIST_T     const *fl_elem_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_SP);
   u_gx_flocal                      fl_obj_dirty_U8;
   fl_obj_dirty_U8 = p_obj_dirty_U8;

   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   /* Check the image is animable or non-animable */
   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
   {
   #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
        UINT32 fl_obj_id_U32 = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
        if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS)
        {
       hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&l_anim_prop_SP->group_loc[fl_obj_id_U32]);
       hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_anim_prop_SP->group_alpha[fl_obj_id_U32]);
        }
   #else
       return; /* This should never happen */
   #endif
   }
   
    
   
   if(fl_elem_SP != GFX_MGR02_NULL_PTR)
   {
       /* Recursive call */
       if(fl_obj_dirty_U8 == (u_gx_flocal)FALSE)
       {
          if(hmi_gfx_mgr02_layout_is_element_changed((UINT32)fl_elem_SP->base_id,(UINT32)fl_elem_SP->obj_id) != (UINT32)FALSE)
          {
             fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
          }
       }

       fl_obj_type_U32 = GFX_MGR02_GET_OBJ_TYPE(fl_elem_SP->obj_id);
   #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
       if(fl_obj_type_U32 == (UINT32)GFX_MGR02_TYPE_SIMAGE)
       {
           hmi_gfx_mgr02_generic_build_image(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8, p_mask_enabled);
       }
       else
   #endif
   #if GFX_MGR02_NUM_USER_LAYERS > 0
       if(fl_obj_type_U32 == (UINT32)GFX_MGR02_TYPE_USER_LAYER)
       {
           hmi_gfx_mgr02_generic_build_uimage(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
       }
       else
   #endif
   #if (GFX_MGR02_NUM_OF_SVGS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
       if(fl_obj_type_U32 == (UINT32)GFX_MGR02_TYPE_SVG)
       {
           hmi_gfx_mgr02_generic_build_svg(fl_elem_SP, p_aligned_widget, fl_obj_dirty_U8);
       }
       else
   #endif
       {
        /*MISRA.IF.NO_ELSE fix*/
       }
   }
   hmi_gfx_mgr02_context_state_set(fl_cur_context_const_SP);
}
#endif /* #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0 */

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_image()
Description          : Builds the image
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Image stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_image(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget,
  u_gx_flocal p_obj_dirty_U8, u_gx_flocal p_mask_enabled )
{   
   UINT32                           fl_obj_id_U32;
   GFX_MGR02_IMAGE_DEF_T    const * fl_element_def_SP;
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0   
   GFX_MGR02_IMAGE_PROPERTY const * fl_elem_prop_SP;
#endif
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
   const GFX_MGR02_IMAGE_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
   GFX_MGR02_CONTEXT_STATE_T        fl_cur_context_S;
   fl_cur_context_S.loc.x = 0;
   fl_cur_context_S.loc.y = 0;
   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   if (p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
   {  
       #if defined(GFX_MGR02_DLAYOUT_ENABLED)
       fl_element_def_SP = hmi_gfx_mgr02_get_image_layer_def_ptr(p_elem_SP->base_id);
       #else
       fl_element_def_SP = &lc_image_layer_def_S[p_elem_SP->base_id];
       #endif
        /* Check the image is animable or non-animable */
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
       {
       #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
           if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
           {   
               fl_elem_anim_prop_SP = &l_anim_prop_SP->image_prop[fl_obj_id_U32];
               if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
               {
                   hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_elem_anim_prop_SP->coord);
                   if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                   {
                       fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
                   }
               }
               else
               {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = (SINT16)0;
                  fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
               }
               hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_anim_prop_SP->alpha);
               if(fl_element_def_SP->chroma_key !=0U)
               {
                   hmi_gfx_mgr02_context_set_fg_color(fl_element_def_SP->color);
               }
               else
               {
                   hmi_gfx_mgr02_context_set_fg_color(fl_elem_anim_prop_SP->fg_color);
               }
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
               hmi_gfx_mgr02_context_set_matrix((GFX_FLOAT const *)l_anim_prop_SP->image_ovg_prop[fl_obj_id_U32].matrix);
               hmi_gfx_mgr02_context_set_pivot(&l_anim_prop_SP->image_ovg_prop[fl_obj_id_U32].pivot);
            #endif
           }
       #else
          return;  /* This should never happen */
       #endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */
       }
       else
       {
       #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
            if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
            {
              #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                fl_elem_prop_SP = hmi_gfx_mgr02_get_image_const_prop_ptr(fl_obj_id_U32);
              #else
                fl_elem_prop_SP = &lc_img_const_property_S[fl_obj_id_U32];
              #endif
              if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
              {
                  hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
                  if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                  {
                      fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
                  }
              }
              else
              {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = 0;
                  fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
              }
              hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_prop_SP->alpha);
              if(fl_element_def_SP->chroma_key !=0U)
              {
                hmi_gfx_mgr02_context_set_fg_color(fl_element_def_SP->color);
              }
              else
              {
                  hmi_gfx_mgr02_context_set_fg_color(fl_elem_prop_SP->fg_color);
              }
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
              hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
              hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
            #endif
            }
       #else
          return;  /* This should never happen */
       #endif /* #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0 */
       }
       if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
       {
          gfxlogstop(GFX_LOG_PROCESSING);
          gfxlogcontinue(GFX_LOG_RENDERING);
          if(l_lib_if_SP->build_image != (void *)0)
          {
             const GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
          #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
             if(l_gen_build_mode_U8 == (UINT8)GFX_MGR02_BUILD_DAR_REDRAW)
             {
                const GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                if(fl_area_SP != GFX_MGR02_NULL_PTR)
                {
                   hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                }
                else
                {
                   hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
                }
             }
          #endif
          #if (GFX_MGR02_NUM_MASK_WIDGETS > 0) && (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
             if(p_mask_enabled == (u_gx_flocal)TRUE)
             {
                hmi_gfx_mgr02_amber_create_mask_image_surf((GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_element_def_SP);
             }
             else
          #else
              GFX_MGR02_UNUSED_VAR(p_mask_enabled);
          #endif
              {
                (void)l_lib_if_SP->build_image((GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_element_def_SP);
              }
          }
          gfxlogstop(GFX_LOG_RENDERING);
          gfxlogcontinue(GFX_LOG_PROCESSING);
       }
    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
       else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
       {
          if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
          {
             const GFX_MGR02_CONTEXT_T  * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
             GFX_MGR02_DAR_OBJECT   fl_dar_SP;
             GFX_FLOAT                  fl_bound[4];
             /*
             ** Consider image is not opeque if color transparancy enabled or 
             ** image has an alpha channel. So its in the hands of graphics designer
             ** to use proper settings to get maximum benefit since configuring 
             ** using an incorrect format for the purpose can result in treating the
             ** image as not opeque and will therefore result in processing of the elements
             ** which underneath it.
             */
             if(fl_element_def_SP->chroma_key != (UINT8)0)
             {
                fl_dar_SP.opeque = (UINT8)0;
             }
             else
             {
             #if defined(GFX_MGR02_VGLITE)  
                if (fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_VGLITE)
                {
                    switch(fl_element_def_SP->format)
                    {
                        case (UINT8)VG_LITE_BGRA8888:
                        case (UINT8)VG_LITE_BGRA4444:
                        case (UINT8)VG_LITE_BGRA5551:
                        case (UINT8)VG_LITE_A8:
                        case (UINT8)VG_LITE_A4:
                        {
                            fl_dar_SP.opeque = (UINT8)0;
                            break;
                        }
                        default:
                        {
                            fl_dar_SP.opeque = (UINT8)1;
                            break;
                        }
                    }
                }
                else
             #endif					
             #if defined(GFX_MGR02_IMXRT_PXP)	
                if ((fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_IMXRT) || (fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_IMXRT_PXP))
                {
                    switch(fl_element_def_SP->format)
                    {
                        case (UINT8)kPXP_AsPixelFormatARGB8888:
                        case (UINT8)kPXP_AsPixelFormatARGB1555:
                        case (UINT8)kPXP_AsPixelFormatARGB4444:
                        {
                            fl_dar_SP.opeque = (UINT8)0;
                            break;
                        }
                        default:
                        {
                            fl_dar_SP.opeque = (UINT8)1;
                            break;
                        }
                    }
                }
                else
             #endif
                {
                    fl_dar_SP.opeque = (UINT8)1;
                }					
             #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_MONOTFT)
                switch(fl_element_def_SP->format)
                {
                #if defined(GFX_MGR02_OPEN_VG)
                   case VG_sARGB_8888:
                   case VG_sARGB_8888_PRE:
                   case VG_sARGB_1555:
                   case VG_sARGB_4444:
                   case VG_lARGB_8888:
                   case VG_lARGB_8888_PRE:
                   case VG_sABGR_8888:
                   case VG_sABGR_8888_PRE:
                   case VG_sABGR_1555:
                   case VG_sABGR_4444:
                   case VG_lABGR_8888:
                   case VG_lABGR_8888_PRE:
                   case VG_A_8:
                   case VG_A_4:
                   case VG_A_1:
                 #elif (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS))  
                   case MML_GDC_SURF_FORMAT_R8G8B8A8:
                   case MML_GDC_SURF_FORMAT_A8B8G8R8:
                   case MML_GDC_SURF_FORMAT_A8R8G8B8:
                   case MML_GDC_SURF_FORMAT_B8G8R8A8:
                   case MML_GDC_SURF_FORMAT_A6R6G6B6:
                   case MML_GDC_SURF_FORMAT_R4G4B4A4:
                   case MML_GDC_SURF_FORMAT_A4R4G4B4:
                   case MML_GDC_SURF_FORMAT_R5G5B5A1:
                   case MML_GDC_SURF_FORMAT_A1R5G5B5:
                   case MML_GDC_SURF_FORMAT_A1B5G5R5:
                   case MML_GDC_SURF_FORMAT_B5G5R5A1:
                   case MML_GDC_SURF_FORMAT_A8RGB8:
                   case MML_GDC_SURF_FORMAT_A8:
                   case MML_GDC_SURF_FORMAT_A4RGB4:
                   case MML_GDC_SURF_FORMAT_A4:
                   case MML_GDC_SURF_FORMAT_A2:
                   case MML_GDC_SURF_FORMAT_A1:
                 #elif defined(GFX_MGR02_TRAVEO2)
                   case CYGFX_SM_FORMAT_R8G8B8A8:
                   case CYGFX_SM_FORMAT_A8B8G8R8:
                   case CYGFX_SM_FORMAT_A8R8G8B8:
                   case CYGFX_SM_FORMAT_B8G8R8A8:
                   case CYGFX_SM_FORMAT_A6R6G6B6:
                   case CYGFX_SM_FORMAT_R4G4B4A4:
                   case CYGFX_SM_FORMAT_A4R4G4B4:
                   case CYGFX_SM_FORMAT_R5G5B5A1:
                   case CYGFX_SM_FORMAT_A1R5G5B5:
                   case CYGFX_SM_FORMAT_A1B5G5R5:
                   case CYGFX_SM_FORMAT_B5G5R5A1:
                   case CYGFX_SM_FORMAT_A8RGB8:
                   case CYGFX_SM_FORMAT_A8:
                   case CYGFX_SM_FORMAT_A4RGB4:
                   case CYGFX_SM_FORMAT_A4:
                   case CYGFX_SM_FORMAT_A2:
                   case CYGFX_SM_FORMAT_A1:
                 #elif defined(GFX_MGR02_MONOTFT)
                   case GFX_MGR02_MONO_TRANSPARENT:
                 #else
                   case VG_A_4:
                   case VG_sARGB_8888:
                   case VG_sARGB_4444:
                 #endif
                   {
                      fl_dar_SP.opeque = (UINT8)0;
                   }
                   break;
                   default:
                   {
                      fl_dar_SP.opeque = (UINT8)1;
                   }
                   break;
                }
             #endif
             }
             
             fl_bound[0] = (GFX_FLOAT)0;
             fl_bound[1] = (GFX_FLOAT)0;
             #if defined(GFX_MGR02_VGLITE)
             fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width - (GFX_FLOAT)fl_element_def_SP->padding;
             #else
             fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width;    
             #endif
             fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->height;
             (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SIMAGE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);

             fl_dar_SP.elem_SP     = p_elem_SP;
             fl_dar_SP.dirty_area  = (UINT8)p_obj_dirty_U8;
             (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
          }
       }
    #endif
       else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
       {
          if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
          {
             const GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
             GFX_FLOAT                 fl_bound[4];
             fl_bound[0] = (GFX_FLOAT)0;
             fl_bound[1] = (GFX_FLOAT)0;
             #if defined(GFX_MGR02_VGLITE)
             fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width - (GFX_FLOAT)fl_element_def_SP->padding;
             #else
             fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width;
             #endif
             fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->height;
             (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SIMAGE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
             hmi_gfx_mgr02_generic_add_bound(fl_bound);
          }
       }
       else
       {
        /*warning fix*/
       }
       hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
       GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
   }
}
#endif /* GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0*/

#if GFX_MGR02_NUM_USER_LAYERS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_uimage()
Description          : Builds the image
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Image stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_uimage(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8)
{   
    UINT32                           fl_obj_id_U32;
    GFX_MGR02_IMAGE_DEF_T          * fl_element_def_SP;
    GFX_MGR02_IMAGE_PROPERTY const * fl_elem_prop_SP;
    GFX_MGR02_CONTEXT_STATE_T        fl_cur_context_S;
    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
    UINT32                           fl_pwidth;
    UINT32                           fl_pheight;
    u_gx_flocal fl_obj_dirty_U8 = p_obj_dirty_U8;
    #if (defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)) || (defined(GFX_MGR02_OPEN_GL))
    void const                     * fl_prev_pixel_data;
    void const                     * fl_img_id = GFX_MGR02_NULL_PTR;
    #endif
    #endif
    GFX_MGR02_CONTEXT_T            * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();

    hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   if (p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
   {
        fl_element_def_SP = &l_anim_prop_SP->user_image_layer[p_elem_SP->base_id];

    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
       
        #if defined(GFX_MGR02_VGLITE)
        fl_pwidth     = (UINT32)fl_element_def_SP->width - (UINT32)fl_element_def_SP->padding;
        #else
        fl_pwidth     = fl_element_def_SP->width;
        #endif
        fl_pheight    = fl_element_def_SP->height;
       
        #if (defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)) || (defined(GFX_MGR02_OPEN_GL))
         #if defined(GFX_MGR02_DLAYOUT_ENABLED)
            fl_img_id     = hmi_gfx_mgr02_get_user_img_layer_def_ptr(p_elem_SP->base_id);
         #else
            fl_img_id     = &lc_user_image_layer_def_S[p_elem_SP->base_id];
         #endif   
            fl_prev_pixel_data = fl_element_def_SP->pixel_data;
        #endif
        if(hmi_gfx_mgr02_load_user_layer_def_info(p_elem_SP->base_id, fl_element_def_SP) != (UINT32)FALSE)
        {
          /*
          ** app returns TRUE
          ** make this element dirty as the aplication wants it to be refreshed..
          */
            fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
        }
        else
        {
            #if defined(GFX_MGR02_VGLITE)
            if(fl_pwidth != ((UINT32)fl_element_def_SP->width - (UINT32)fl_element_def_SP->padding))
            #else
            if(fl_pwidth != fl_element_def_SP->width)
            #endif    
            {
                fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
            }
            else if(fl_pheight != fl_element_def_SP->height)
            {
                fl_obj_dirty_U8 = (u_gx_flocal)TRUE;
            }
            else
            {
              /*For MISRA warning fix.*/
            }
        }

    #if (defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)) || (defined(GFX_MGR02_OPEN_GL))
       if(fl_obj_dirty_U8)
       {
          if((fl_context_SP != GFX_MGR02_NULL_PTR) && (fl_img_id != GFX_MGR02_NULL_PTR))
          {
          #if defined(GFX_MGR02_OPEN_GL)
             if(fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_OPENGL)
             {
                if((fl_prev_pixel_data != NULL)
#ifdef OGL_DIRECT_TEXTURE_RENDERING
                  && (fl_element_def_SP->format != VG_sRGBA_8888_VIV)//For RVC direct video capturing, we should not remove the texture as it affects the performance
#endif
                  )
                {
                   hmi_gfx_mgr02_ogllib_remove_tex(0,fl_prev_pixel_data);
                }
             }
          #endif
          #if defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
             if(fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_OPENVG)
             {
                if(fl_prev_pixel_data != NULL)
                {
                   hmi_gfx_mgr02_ovglib_remove_from_cache(fl_prev_pixel_data);
                }
             }
          #endif
          }   
       }
    #endif
    #else
       (void)hmi_gfx_mgr02_load_user_layer_def_info(p_elem_SP->base_id, fl_element_def_SP);
    #endif

       if((fl_element_def_SP->pixel_data != GFX_MGR02_NULL_PTR) && 
          (fl_element_def_SP->height     != (UINT16)0)        && 
          (fl_element_def_SP->width      != (UINT16)0))
       {
          fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);

          /* Check the image is animable or non-animable */
          if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
          {
          #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
            if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
            {
                GFX_MGR02_IMAGE_DYN_PROPERTY *fl_elem_anim_prop_SP = &l_anim_prop_SP->user_prop[fl_obj_id_U32];
                if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
                {
                    hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
                    if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                    {
                        fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
                    }
                }
                else
                {
                    GFX_MGR02_ILOC_DATA fl_aligned_loc;
                    fl_aligned_loc.x = (SINT16)0;
                    fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
                    hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
                }
                hmi_gfx_mgr02_context_set_alpha(fl_elem_anim_prop_SP->alpha);
                hmi_gfx_mgr02_context_set_fg_color(fl_elem_anim_prop_SP->fg_color);
               #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
                hmi_gfx_mgr02_context_set_matrix(l_anim_prop_SP->user_ovg_prop[fl_obj_id_U32].matrix);
                hmi_gfx_mgr02_context_set_pivot(&l_anim_prop_SP->user_ovg_prop[fl_obj_id_U32].pivot);
               #endif
            }
          #else
             return;  /* This should never happen */
          #endif /* #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0 */
          }
          else
          {
          #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
            if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
            {
                #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                 fl_elem_prop_SP = hmi_gfx_mgr02_get_image_const_prop_ptr(fl_obj_id_U32); 
                #else
                 fl_elem_prop_SP = &lc_img_const_property_S[fl_obj_id_U32];
                #endif
                 if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
                 {
                     hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
                     if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                     {
                         fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
                     }
                 }
                 else
                 {
                     GFX_MGR02_ILOC_DATA fl_aligned_loc;
                     fl_aligned_loc.x = (SINT16)0;
                     fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
                     hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
                 }
                 hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_prop_SP->alpha);
                 hmi_gfx_mgr02_context_set_fg_color(fl_elem_prop_SP->fg_color);
               #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
                 hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
                 hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
               #endif
            }
          #else
             return;  /* This should never happen */
          #endif /* #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0 */
          }
          if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
          {
             gfxlogstop(GFX_LOG_PROCESSING);
             gfxlogcontinue(GFX_LOG_RENDERING);
             if(l_lib_if_SP->build_uimage != (void *)0)
             {
             #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                if(l_gen_build_mode_U8 == (UINT8)GFX_MGR02_BUILD_DAR_REDRAW)
                {
                   GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                   if(fl_area_SP != GFX_MGR02_NULL_PTR)
                   {
                      hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                   }
                   else
                   {
                      hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
                   }
                }
             #endif
                (void)l_lib_if_SP->build_uimage(fl_context_SP, fl_element_def_SP);
             }
             gfxlogstop(GFX_LOG_RENDERING);
             gfxlogcontinue(GFX_LOG_PROCESSING);
          }
       #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
          else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
          {
             if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
             {
                GFX_MGR02_DAR_OBJECT   fl_dar_SP;
                GFX_FLOAT                  fl_bound[4];
             /*
             ** Consider image is not opeque if color transparancy enabled or 
             ** image has an alpha channel. So its in the hands of graphics designer
             ** to use proper settings to get maximum benefit since configuring 
             ** using an incorrect format for the purpose can result in treating the
             ** image as not opeque and will therefore result in processing of the elements
             ** which underneath it.
             */
                if(fl_element_def_SP->chroma_key != (UINT8)0)
                {
                    fl_dar_SP.opeque = (UINT8)0;
                }
                else
                {   
                #if defined(GFX_MGR02_VGLITE)  
                    if (fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_VGLITE)
                    {
                        switch(fl_element_def_SP->format)
                        {
                            case (UINT8)VG_LITE_BGRA8888:
                            case (UINT8)VG_LITE_BGRA4444:
                            case (UINT8)VG_LITE_BGRA5551:
                            case (UINT8)VG_LITE_A8:
                            case (UINT8)VG_LITE_A4:
                            {
                                fl_dar_SP.opeque = (UINT8)0;
                                break;
                            }
                            default:
                            {
                                fl_dar_SP.opeque = (UINT8)1;
                                break;
                            }
                        }
                    }
                    else
                #endif					
                #if defined(GFX_MGR02_IMXRT_PXP)	
                    if ((fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_IMXRT) || (fl_context_SP->rprop.fb_target == GFX_MGR02_TARGET_IMXRT_PXP))
                    {
                        switch(fl_element_def_SP->format)
                        {
                            case (UINT8)kPXP_AsPixelFormatARGB8888:
                            case (UINT8)kPXP_AsPixelFormatARGB1555:
                            case (UINT8)kPXP_AsPixelFormatARGB4444:
                            {
                                fl_dar_SP.opeque = (UINT8)0;
                                break;
                            }
                            default:
                            {
                                fl_dar_SP.opeque = (UINT8)1;
                                break;
                            }
                        }
                    }
                    else
                #endif
                    {
                        fl_dar_SP.opeque = (UINT8)1;
                    }
                #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_MONOTFT)     
                    switch(fl_element_def_SP->format)
                    {
                    #if defined(GFX_MGR02_OPEN_VG)
                       case VG_sARGB_8888:
                       case VG_sARGB_8888_PRE:
                       case VG_sARGB_1555:
                       case VG_sARGB_4444:
                       case VG_lARGB_8888:
                       case VG_lARGB_8888_PRE:
                       case VG_sABGR_8888:
                       case VG_sABGR_8888_PRE:
                       case VG_sABGR_1555:
                       case VG_sABGR_4444:
                       case VG_lABGR_8888:
                       case VG_lABGR_8888_PRE:
                       case VG_A_8:
                       case VG_A_4:
                       case VG_A_1:
                     #elif (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS))  
                       case MML_GDC_SURF_FORMAT_R8G8B8A8:
                       case MML_GDC_SURF_FORMAT_A8B8G8R8:
                       case MML_GDC_SURF_FORMAT_A8R8G8B8:
                       case MML_GDC_SURF_FORMAT_A6R6G6B6:
                       case MML_GDC_SURF_FORMAT_B8G8R8A8:
                       case MML_GDC_SURF_FORMAT_R4G4B4A4:
                       case MML_GDC_SURF_FORMAT_A4R4G4B4:
                       case MML_GDC_SURF_FORMAT_R5G5B5A1:
                       case MML_GDC_SURF_FORMAT_A1R5G5B5:
                       case MML_GDC_SURF_FORMAT_A1B5G5R5:
                       case MML_GDC_SURF_FORMAT_B5G5R5A1:
                       case MML_GDC_SURF_FORMAT_A8RGB8:
                       case MML_GDC_SURF_FORMAT_A8:
                       case MML_GDC_SURF_FORMAT_A4RGB4:
                       case MML_GDC_SURF_FORMAT_A4:
                       case MML_GDC_SURF_FORMAT_A2:
                       case MML_GDC_SURF_FORMAT_A1:
                     #elif defined(GFX_MGR02_TRAVEO2)
                       case CYGFX_SM_FORMAT_R8G8B8A8:
                       case CYGFX_SM_FORMAT_A8B8G8R8:
                       case CYGFX_SM_FORMAT_A8R8G8B8:
                       case CYGFX_SM_FORMAT_A6R6G6B6:
                       case CYGFX_SM_FORMAT_B8G8R8A8:
                       case CYGFX_SM_FORMAT_R4G4B4A4:
                       case CYGFX_SM_FORMAT_A4R4G4B4:
                       case CYGFX_SM_FORMAT_R5G5B5A1:
                       case CYGFX_SM_FORMAT_A1R5G5B5:
                       case CYGFX_SM_FORMAT_A1B5G5R5:
                       case CYGFX_SM_FORMAT_B5G5R5A1:
                       case CYGFX_SM_FORMAT_A8RGB8:
                       case CYGFX_SM_FORMAT_A8:
                       case CYGFX_SM_FORMAT_A4RGB4:
                       case CYGFX_SM_FORMAT_A4:
                       case CYGFX_SM_FORMAT_A2:
                       case CYGFX_SM_FORMAT_A1:
                       #if (GFX_MGR02_NUM_USER_LAYERS > 0)
                       case GFX_MGR02_FORMAT_HISTOGRAM:
                       #endif
                     #else
                       case VG_A_4:
                       case VG_sARGB_8888:
                       case VG_sARGB_4444:
                     #endif
                       {
                          fl_dar_SP.opeque = (UINT8)0;
                       }
                       break;
                       default:
                       {
                          fl_dar_SP.opeque = (UINT8)1;
                       }
                       break;
                    }
                #endif
                }
                fl_bound[0] = (GFX_FLOAT)0;
                fl_bound[1] = (GFX_FLOAT)0;
                #if defined(GFX_MGR02_VGLITE)
                fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width - (GFX_FLOAT)fl_element_def_SP->padding;
                #else
                fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width;
                #endif
                fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->height;
                
                #if defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0)
                if(fl_element_def_SP->format == GFX_MGR02_FORMAT_HISTOGRAM)
                {
                    GFX_MGR02_HISTOGRAM_DATA const *fl_histogram_data_SP = (GFX_MGR02_HISTOGRAM_DATA const *)fl_element_def_SP->pixel_data;
                    
                    /* If the histogram curve line has some thickness to it, then some of it might render outside of the element boundary on the edges.
                    ** Therefore, it is required to increase the bounds of the histogram element to consider line width/thickness.While rendering,
                    ** histogram is shifted down as well as to the right equal to line width, so that it does not overflow outside of the bounds at
                    ** the top and left side. Then increasing the bounds by line_width * 2 from bottom and right side to compensate for line width.                    
                    */
                    
                    fl_bound[2] += (fl_histogram_data_SP->hg_line_width * 2.0F);
                    fl_bound[3] += (fl_histogram_data_SP->hg_line_width * 2.0F);
                }
                #endif
                
                (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SIMAGE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);

                fl_dar_SP.elem_SP    = p_elem_SP;
                fl_dar_SP.dirty_area = (UINT8)fl_obj_dirty_U8;
                (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
             }
          }
       #endif
          else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
          {
             if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
             {
                GFX_FLOAT                 fl_bound[4];
                fl_bound[0] = (GFX_FLOAT)0;
                fl_bound[1] = (GFX_FLOAT)0;
                #if defined(GFX_MGR02_VGLITE)
                fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width - (GFX_FLOAT)fl_element_def_SP->padding;
                #else
                fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->width;
                #endif
                fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->height;
                
                #if defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0)
                if(fl_element_def_SP->format == GFX_MGR02_FORMAT_HISTOGRAM)
                {
                    GFX_MGR02_HISTOGRAM_DATA const *fl_histogram_data_SP = (GFX_MGR02_HISTOGRAM_DATA const *)fl_element_def_SP->pixel_data;
                    
                    /* If the histogram curve line has some thickness to it, then some of it might render outside of the element boundary on the edges.
                    ** Therefore, it is required to increase the bounds of the histogram element to consider line width/thickness.While rendering,
                    ** histogram is shifted down as well as to the right equal to line width, so that it does not overflow outside of the bounds at
                    ** the top and left side. Then increasing the bounds by line_width * 2 from bottom and right side to compensate for line width.                    
                    */
                  
                    fl_bound[2] += (fl_histogram_data_SP->hg_line_width * 2.0F);
                    fl_bound[3] += (fl_histogram_data_SP->hg_line_width * 2.0F);
                }
                #endif
                
                (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_SIMAGE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
                hmi_gfx_mgr02_generic_add_bound(fl_bound);
             }
          }
          else
          {
            /*warning fix*/
          }
          hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
       }
   }
   GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
}
#endif /* #if GFX_MGR02_NUM_USER_LAYERS > 0 */

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_video()
Description          : Builds the video 
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Image stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_video(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8)
{   
   GFX_MGR02_CONTEXT_STATE_T        fl_cur_context_S;
   const GFX_MGR02_CONTEXT_T            * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();

   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   hmi_gfx_mgr02_context_set_loc(&lc_video_layer_def_S.coord);
      p_obj_dirty_U8 = (u_gx_flocal)TRUE;

      if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
      {
         gfxlogstop(GFX_LOG_PROCESSING);
         gfxlogcontinue(GFX_LOG_RENDERING);
         if(l_lib_if_SP->build_video != (void *)0)
         {
         #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
            if(l_gen_build_mode_U8 == (UINT8)GFX_MGR02_BUILD_DAR_REDRAW)
            {
               const GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
               if(fl_area_SP != GFX_MGR02_NULL_PTR)
               {
                  hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
               }
               else
               {
                  hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
               }
            }
         #endif
            (void)l_lib_if_SP->build_video(fl_context_SP, &lc_video_layer_def_S);
         }
         gfxlogstop(GFX_LOG_RENDERING);
         gfxlogcontinue(GFX_LOG_PROCESSING);
      }
   #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_MGR02_DAR_OBJECT   fl_dar_SP;
            GFX_FLOAT                  fl_bound[4];

            fl_dar_SP.opeque = (UINT8)0; 
            fl_bound[0] = (GFX_FLOAT)lc_video_layer_def_S.coord.x;
            fl_bound[1] = (GFX_FLOAT)lc_video_layer_def_S.coord.y;
            fl_bound[2] = (GFX_FLOAT)lc_video_layer_def_S.dim.width;
            fl_bound[3] = (GFX_FLOAT)lc_video_layer_def_S.dim.height;
            fl_dar_SP.elem_SP    = p_elem_SP;
            fl_dar_SP.dirty_area = (UINT8)p_obj_dirty_U8;
            (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
         }
      }
   #endif
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_FLOAT                 fl_bound[4];
            fl_bound[0] = (GFX_FLOAT)lc_video_layer_def_S.coord.x;
            fl_bound[1] = (GFX_FLOAT)lc_video_layer_def_S.coord.y;
            fl_bound[2] = (GFX_FLOAT)lc_video_layer_def_S.dim.width;
            fl_bound[3] = (GFX_FLOAT)lc_video_layer_def_S.dim.height;
            hmi_gfx_mgr02_generic_add_bound(fl_bound);
         }
      }
      else
      {
        /*warning fix*/
      }
      hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
   GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
}
#endif 

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_multiline_hardcut_algorithm()
Description          : Evaluates the string passed and returns if hard cut is 
                       required or not.
Invocation           : hmi_gfx_mgr02_multiline_algorithm().
Return Value         : BOOLEAN
Parameters           : line break char position in Current line of text, 
                       Current line of text, multi line string
******************************************************************************/
static BOOLEAN hmi_gfx_mgr02_multiline_hardcut_algorithm(u_gx_flocal          p_line_break_pos, 
                                                        GFX_MGR02_TEXT_INFO * p_text_info_SP,
                                                        HMI_CHAR      const * p_string,
                                                        GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const * p_dep_param)
{
  BOOLEAN    fl_is_hard_cut_reqd = FALSE;
  u_gx_flocal     fl_next_line_clip_flag;
  /* Since line break char occurs at p_line_break_pos, the data from next char need to be taken */
  u_gx_flocal     fl_after_line_break_char = 0; 
  HMI_CHAR   fl_next_line_string[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
  HMI_CHAR   fl_unicode;
  HMI_CHAR  const * fl_p_string_SP = p_string;
  UINT8 fl_string_len = (UINT8)HMI_STRLEN(p_string);
  GFX_MGR02_TEXT_INFO  fl_next_line_text_info_SP;
  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  HMI_CHAR   fl_append_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
  #endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};
  GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
  UINT8 fl_is_character;
  UINT8 fl_is_complex;
  UINT8 fl_fnt_uniq_id;
  GFX_MGR02_TEXT_DEF_T const * fl_dyn_text_def_SP = p_text_info_SP->dyn_text_def_SP;
  if(fl_dyn_text_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
  {
    fl_ML_data_ptr = &l_shape_ml_dtext_buffer[fl_dyn_text_def_SP->ml_string_index];
  }
#endif

  /* Get the next line string */
  if(p_line_break_pos > (u_gx_flocal)0)
  {
      /* When line break character is not found then p_line_break_pos will be 0, hence data should
      be taken from 0th position, so increment is not done for 0 */
  fl_after_line_break_char = p_line_break_pos +  (u_gx_flocal)1;
  }
  fl_p_string_SP = fl_p_string_SP + fl_after_line_break_char;
  /* Search for the line break char from the beginning so reset to 0 */
  fl_after_line_break_char = 0;

  if(fl_p_string_SP[fl_after_line_break_char] !=  (HMI_CHAR)'\0')
  {
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, fl_p_string_SP, fl_after_line_break_char, &fl_shape_flags);
    
    fl_is_complex = fl_shape_flags.complexity_flag;
    fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;
    if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
    {
      while((fl_after_line_break_char < fl_string_len) && (fl_p_string_SP[fl_after_line_break_char] != (HMI_CHAR)'\0'))
      {
        fl_unicode         = fl_p_string_SP[fl_after_line_break_char];
        fl_is_character = fl_ML_data_ptr->is_character[fl_after_line_break_char];
        fl_after_line_break_char++;
        if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) != FALSE)
        {
          break;
        }
      }
    }
    fl_next_line_text_info_SP.is_complex = fl_is_complex;
    fl_next_line_text_info_SP.str_offset_idx = (UINT16)fl_after_line_break_char;
    fl_next_line_text_info_SP.is_ml_data_still_exist = 0U;
  #else
    while((fl_after_line_break_char < fl_string_len) && (fl_p_string_SP[fl_after_line_break_char] != (HMI_CHAR)'\0'))
    {
      fl_unicode         = fl_p_string_SP[fl_after_line_break_char];
      fl_after_line_break_char++;
      if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_unicode) != FALSE)
      {
        break;
      }
    }
  #endif
    (void)memset(&fl_next_line_string[0], 0, sizeof(fl_next_line_string));
    (void)HMI_STRNCPY(&fl_next_line_string[0], fl_p_string_SP, fl_after_line_break_char);

    fl_next_line_text_info_SP.dyn_text_def_SP     = p_text_info_SP->dyn_text_def_SP;
    fl_next_line_text_info_SP.print_str_P         = &fl_next_line_string[0];
    fl_next_line_text_info_SP.coord.x             = 0;
    fl_next_line_text_info_SP.coord.y             = 0;
    fl_next_line_text_info_SP.target              = p_text_info_SP->target;
    fl_next_line_text_info_SP.max_available_width = (UINT16)p_dep_param->text_width;
    fl_next_line_text_info_SP.append_str          = p_text_info_SP->append_str;
    fl_next_line_text_info_SP.num_chars_to_process = (UINT16)HMI_STRLEN(&fl_next_line_string[0]); 
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    fl_next_line_text_info_SP.font_pt_size = p_dep_param->font_pt_size;
#endif
    #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
    fl_next_line_text_info_SP.get_dynamic_clipinfo = (UINT8)FALSE;
    #endif

    fl_next_line_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_next_line_text_info_SP,
                                                            p_dep_param->font_id,
                                                            p_dep_param->clip_mode,
                                                            p_dep_param->alignment
                                                            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                            ,&fl_append_str[0]
                                                            #endif
                                                            #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                            ,GFX_MGR02_NULL_PTR
                                                            #endif
                                                            );


    /* Only when fl_next_line_clip_flag is set it indicates that the given string cannot be */
    /* fitted in the text box, so hard cut is required if clip flag is set                  */
    if(fl_next_line_clip_flag == FALSE)
    {
      if(p_line_break_pos > (u_gx_flocal)0)
      {
      /* When hard cut need not be done, the calculated line break position is used */
      p_text_info_SP->print_length_U8 = (UINT8)(p_line_break_pos + (UINT8)1);
      }
    }
    else
    {
      fl_is_hard_cut_reqd = TRUE;
    }
  }
  return fl_is_hard_cut_reqd;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_multiline_algorithm()
Description          : Returns the string length to be incremented for next line.
                     : Print length indicates the length of string to be displayed.
Invocation           : Invoked by hmi_gfx_mgr02_get_multiline_text.
Return Value         : UINT16 fl_str_increment_length
Parameters           : Text definition, Multi line string
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_multiline_algorithm(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                               HMI_CHAR      const * p_string,
                                               GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const* p_dep_param)
{
  u_gx_flocal  fl_str_increment_length = p_clip_text_info_SP->print_length_U8;
  UINT8 fl_string_len = (UINT8)HMI_STRLEN(p_string);
  
    HMI_CHAR fl_char_unicode = p_string[p_clip_text_info_SP->print_length_U8];
    s_gx_flocal fl_line_break_char_pos = (s_gx_flocal)p_clip_text_info_SP->print_length_U8 - 1;
    HMI_CHAR *fl_after_newline_string;
    HMI_CHAR fl_line_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
    HMI_CHAR fl_search_str[3] = {0x0d,0x0a,0x00};
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};
    GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
    UINT8 fl_is_character;
    UINT8 fl_is_complex;
    UINT8 fl_fnt_uniq_id;
    GFX_MGR02_TEXT_DEF_T const * fl_dyn_text_def_SP = p_clip_text_info_SP->dyn_text_def_SP;
    if(fl_dyn_text_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
    {
      fl_ML_data_ptr = &l_shape_ml_dtext_buffer[fl_dyn_text_def_SP->ml_string_index];
    }
  #endif

    /* NEW LINE requirement implemented here */
    (void)memset(&fl_line_str[0], 0, sizeof(fl_line_str));
    (void)HMI_STRNCPY(&fl_line_str[0], p_string, p_clip_text_info_SP->print_length_U8);
    fl_after_newline_string = HMI_STRPBRK((HMI_CHAR *)(fl_line_str) ,fl_search_str);

    if(fl_after_newline_string != NULL)
    {
      UINT8 fl_after_newline_length = (UINT8)HMI_STRLEN(fl_after_newline_string);
      p_clip_text_info_SP->print_length_U8 -=  fl_after_newline_length;
      fl_str_increment_length = p_clip_text_info_SP->print_length_U8;    
      fl_str_increment_length++;
    }
    else if(p_string[p_clip_text_info_SP->print_length_U8] != (HMI_CHAR)'\0')
    {
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string,(u_gx_flocal)p_clip_text_info_SP->print_length_U8, &fl_shape_flags);
      fl_is_character = fl_shape_flags.char_flag;
      fl_is_complex = fl_shape_flags.complexity_flag;
      fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;
      if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) != FALSE)
    #else
      if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode) != FALSE)
    #endif
      {
        #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        /* Some time glyph id will also have the same value as white space characters, so ignore it */
        if(((fl_is_complex == (UINT8)TRUE) && (fl_is_character == (UINT8)TRUE)) ||
            (fl_is_complex == (UINT8)FALSE))
      #endif
        {
          if(HMI_ISSPACE((SINT32)fl_char_unicode) != 0)
          {
            /* Next line data should ignore space/tab at the end of the line */
            fl_str_increment_length++;
          }
        }
      }
      else
      {
        /* Search till any line break character is encountered from the last */
        for(;(fl_line_break_char_pos > 0);fl_line_break_char_pos--)
        {
          fl_char_unicode         = p_string[fl_line_break_char_pos];
          fl_str_increment_length = ((u_gx_flocal)fl_line_break_char_pos + 1U);
        #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
          {
            fl_is_character = fl_ML_data_ptr->is_character[fl_line_break_char_pos];
          }
          if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) != FALSE)
        #else
          if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode) != FALSE)
        #endif
          {
            break;
          }
        }

        /* If line break character is found in the p_clip_text_info_SP.print_str_P */
        /* The p_clip_text_info_SP.print_str_P is evaluated to find whether hard cut is needed */
        if(fl_line_break_char_pos >= 0)
        {
          BOOLEAN fl_hard_cut_needed;
          
          fl_hard_cut_needed = hmi_gfx_mgr02_multiline_hardcut_algorithm((u_gx_flocal)fl_line_break_char_pos,p_clip_text_info_SP, p_string, p_dep_param);
          /* If hard cut is required, then fl_str_increment_length will be the print_length_U8, i.e the complete
          string fittable in the text box need to be shown, hence print_length_U8 is taken. 
          If hard cut is not required, then calculated fl_str_increment_length will be used.  The  
          fl_str_increment_length is calculated based on the line break character position.  */  
          if(fl_hard_cut_needed != FALSE)
          {
  #ifdef GFX_MGR02_HARDCUT_ENABLED
            if(GFX_MGR02_HARDCUT_CHAR != 0)
            {
              /* When hard cut with char feature is enabled then print length is reduced by 1 to
              accomodate the hard cut character  */
              p_clip_text_info_SP->print_length_U8--;
              /* The information that char_hardcut is required or not is temporarily saved in print_sindex */
              p_clip_text_info_SP->print_sindex_U8 = TRUE;
            }
  #endif
            fl_str_increment_length = p_clip_text_info_SP->print_length_U8;
          }
        }
        /* When no line break character is detected in p_clip_text_info_SP.print_str_P */
        /* then display the data as it is  */
        else
        {
          fl_str_increment_length = p_clip_text_info_SP->print_length_U8;
        }
      }
    }
    else
    {
      /*Do nothing*/
    }

    if(fl_str_increment_length < fl_string_len)
    {
      /* Multiple spaces or tabs at the end of the line need to be ignored */
      /* Any new line should start with a printable character only         */
      fl_char_unicode = p_string[fl_str_increment_length];
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, fl_str_increment_length, &fl_shape_flags);
      fl_is_character = fl_shape_flags.char_flag;
      fl_is_complex = fl_shape_flags.complexity_flag;
      fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;
      while((p_string[fl_str_increment_length] != (HMI_CHAR)'\0') && 
            (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) == 0U))
    #else
      while((p_string[fl_str_increment_length] != (HMI_CHAR)'\0') && (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode) == 0U))   
    #endif
      {
        fl_str_increment_length++;
        if(fl_str_increment_length < fl_string_len)
        {
          fl_char_unicode = p_string[fl_str_increment_length];
          #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
          {
            fl_is_character = fl_ML_data_ptr->is_character[fl_str_increment_length];
          }
          #endif
        }
      }
    }
  
  return (fl_str_increment_length);
}

#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_RTL_multiline_algorithm()
Description          : Returns the string length to be incremented for next line.
                     : Print length indicates the length of string to be displayed.
Invocation           : Invoked by hmi_gfx_mgr02_get_multiline_text.
Return Value         : UINT16 fl_str_increment_length
Parameters           : Text definition, Multi line string
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_RTL_multiline_algorithm(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
                                               HMI_CHAR      const * p_string,
                                                GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const * p_dep_param)
{
  u_gx_flocal  fl_str_increment_length;
  u_gx_flocal fl_input_str_len_U16 = HMI_STRLEN(p_string);
  HMI_CHAR fl_char_unicode;
  u_gx_flocal fl_before_line_brk_cnt_U16 = 0;
  u_gx_flocal fl_line_break_char_pos = fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8;
  HMI_CHAR *fl_after_newline_string;
  u_gx_flocal fl_next_line_clip_flag;
  GFX_MGR02_TEXT_INFO  fl_next_line_text_info_SP;
  
 #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  HMI_CHAR             fl_append_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
 #endif
  GFX_MGR02_TEXT_DEF_T const * fl_dyn_text_def_SP = p_clip_text_info_SP->dyn_text_def_SP;
 #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};
  GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
  UINT8 fl_is_character = (UINT8)FALSE;
  UINT8 fl_is_complex;
  UINT8 fl_fnt_uniq_id;
  UINT16 fl_str_index;
  if(fl_dyn_text_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
  {
    fl_ML_data_ptr = &l_shape_ml_dtext_buffer[fl_dyn_text_def_SP->ml_string_index];
  }
#endif
  fl_str_increment_length = fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  if(fl_str_increment_length > 0U)
  {
    fl_char_unicode = p_string[fl_str_increment_length - 1U];
    fl_str_index = (UINT16)fl_str_increment_length - 1U;
    if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
    {
      fl_is_character = fl_ML_data_ptr->is_character[fl_str_increment_length - 1U];
    }
  }
  else
  {
    fl_char_unicode = p_string[0];
    fl_str_index = 0U;
    if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
    {
      fl_is_character = fl_ML_data_ptr->is_character[0];
    }
  }
  hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, (u_gx_flocal)fl_str_index, &fl_shape_flags);
  fl_is_complex = fl_shape_flags.complexity_flag;
  fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;
#else
  if(fl_str_increment_length > 0U)
  {
    fl_char_unicode = p_string[fl_str_increment_length - 1U];
  }
  else
  {
    fl_char_unicode = p_string[0];
  }
#endif

  /* NEW LINE requirement implemented here */
  /*There is no reverse function for HMI_STRPBRK function. Hence first we will check whether \r is coming. If there no
  '\r', then check for '\n'*/
  fl_after_newline_string = HMI_STRRCHR((const HMI_CHAR *)(p_clip_text_info_SP->print_str_P), (HMI_CHAR)'\r');
  if(fl_after_newline_string == GFX_MGR02_NULL_PTR)
  {
    fl_after_newline_string = HMI_STRRCHR((const HMI_CHAR *)(p_clip_text_info_SP->print_str_P), (HMI_CHAR)'\n');
  }
  if(fl_after_newline_string != GFX_MGR02_NULL_PTR)
  {
    UINT8 fl_after_newline_length = (UINT8)HMI_STRLEN(fl_after_newline_string);
    p_clip_text_info_SP->print_length_U8 = fl_after_newline_length - 1U;
    fl_str_increment_length = (fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8) - 1U;
  }
  else if((fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8) != 0U)
  {
   #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) != FALSE)
   #else
    if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode) != FALSE)
   #endif
    {
     #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      /* Some time glyph id will also have the same value as white space characters, so ignore it */
      if((fl_is_complex == (UINT8)TRUE) && (fl_is_character == (UINT8)TRUE))
     #endif
      {
        if(HMI_ISSPACE((SINT32)fl_char_unicode) != 0)
        {
          /* Next line data should ignore space/tab at the end of the line */
          fl_str_increment_length--;
        }
      }
    }
    else
    {
      /* Search till any line break character is encountered from the last */
      for(;(fl_line_break_char_pos < fl_input_str_len_U16);fl_line_break_char_pos++)
      {
        fl_char_unicode         = p_string[fl_line_break_char_pos];
        fl_str_increment_length = fl_line_break_char_pos - 1U;
        fl_before_line_brk_cnt_U16++;
       #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
        {
          fl_is_character = fl_ML_data_ptr->is_character[fl_line_break_char_pos];
        }
        if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) != FALSE)
       #else
        if(GFX_MGR02_IS_LINE_BREAK_CHAR(fl_char_unicode) != FALSE)
       #endif
        {
          break;
        }
      }

      /* If line break character is found in the p_clip_text_info_SP.print_str_P */
      if(fl_line_break_char_pos < fl_input_str_len_U16)
      {
        p_clip_text_info_SP->print_length_U8 -= (UINT8)fl_before_line_brk_cnt_U16;      
      }
      /* When no line break character is detected in p_clip_text_info_SP.print_str_P */
      else if(fl_line_break_char_pos == fl_input_str_len_U16)
      {
        fl_str_increment_length = (fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8) - (u_gx_flocal)1;
        if(p_string[fl_str_increment_length] != (HMI_CHAR)'\0')
        {
            fl_char_unicode = p_string[fl_str_increment_length];
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, fl_str_increment_length, &fl_shape_flags);
            fl_is_character = fl_shape_flags.char_flag;
            fl_is_complex = fl_shape_flags.complexity_flag;
            fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;

            hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, (u_gx_flocal)GFX_STR_INVALID_INDEX, &fl_shape_flags);
            fl_next_line_text_info_SP.is_complex = fl_is_complex;
            fl_next_line_text_info_SP.str_offset_idx = fl_shape_flags.current_str_index;
            fl_next_line_text_info_SP.is_ml_data_still_exist = 0U;
            if(GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id)==TRUE)
#else
            if(GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode)==TRUE)
#endif
            {
                fl_next_line_text_info_SP.print_str_P         = p_string;
                fl_next_line_text_info_SP.coord.x             = 0;
                fl_next_line_text_info_SP.coord.y             = 0;
                fl_next_line_text_info_SP.target              = p_clip_text_info_SP->target;
                fl_next_line_text_info_SP.max_available_width = (UINT16)p_dep_param->text_width;
                fl_next_line_text_info_SP.append_str          = TRUE;
                fl_next_line_text_info_SP.num_chars_to_process = (UINT16)fl_input_str_len_U16;
                fl_next_line_text_info_SP.dyn_text_def_SP      = fl_dyn_text_def_SP;
                fl_next_line_text_info_SP.print_length_U8      = 0U;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
                fl_next_line_text_info_SP.font_pt_size = p_dep_param->font_pt_size;
#endif
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
                fl_next_line_text_info_SP.get_dynamic_clipinfo = (UINT8)FALSE;
#endif

                fl_next_line_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_next_line_text_info_SP,
                                                                  p_dep_param->font_id,
                                                                  p_dep_param->clip_mode,
                                                                  p_dep_param->alignment
                                                                  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                                  ,&fl_append_str[0]
                                                                  #endif
                                                                  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                  ,GFX_MGR02_NULL_PTR
                                                                  #endif
                );
                /* For Arabic the hard cut requirement is the particular long word should be shown with
                ellipsis on that line and the whole word need to be ignored. 
                The information that an arabic hard cut is done is saved in print_sindex_U8 locally */

                if(fl_next_line_clip_flag == TRUE)
                {
                    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                    fl_next_line_text_info_SP.print_length_U8 -= (UINT8)GFX_MGR02_APPEND_CHAR_CNT;
                    #endif
                    p_clip_text_info_SP->print_length_U8 = fl_next_line_text_info_SP.print_length_U8;
                    p_clip_text_info_SP->print_sindex_U8 = TRUE;
                }
                /* Since the long word need to be ignored, the fl_str_increment_length is calculated
                till a line break char is encountered */
                if(fl_str_increment_length < fl_input_str_len_U16)
                {
                    fl_char_unicode = p_string[fl_str_increment_length];

#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                    hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, fl_str_increment_length, &fl_shape_flags);
                    fl_is_character = fl_shape_flags.char_flag;
                    fl_is_complex = fl_shape_flags.complexity_flag;
                    fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;
                
                    while((p_string[fl_str_increment_length] !=  (HMI_CHAR)'\0') && 
                    (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) == FALSE))
#else
                    while((p_string[fl_str_increment_length] !=  (HMI_CHAR)'\0') && (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode) == FALSE))
#endif
                    {
                        if(fl_str_increment_length != (u_gx_flocal)0)
                        {
                            fl_str_increment_length--;
                            fl_char_unicode = p_string[fl_str_increment_length];
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                            if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
                            {
                                fl_is_character = fl_ML_data_ptr->is_character[fl_str_increment_length];
                            }
#endif
                        }
                        else
                        {
                            fl_str_increment_length = GFX_MULTI_LINE_INVALID_LENGTH;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
          fl_str_increment_length = fl_input_str_len_U16 - p_clip_text_info_SP->print_length_U8 - 1U;
        }
      }
      else
      {
          /*For MISRA warning fix.*/
      }
    }
  }
  else
  {
    fl_str_increment_length = GFX_MULTI_LINE_INVALID_LENGTH;
  }

  /* Multiple spaces or tabs at the end of the line need to be ignored */
  /* Any new line should start with a printable character only         */
  if(fl_str_increment_length < fl_input_str_len_U16)
  {
    fl_char_unicode = p_string[fl_str_increment_length];
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    hmi_gfx_mgr02_get_shaping_flags(fl_dyn_text_def_SP, p_string, fl_str_increment_length, &fl_shape_flags);
    fl_is_character = fl_shape_flags.char_flag;
    fl_is_complex = fl_shape_flags.complexity_flag;
    fl_fnt_uniq_id = fl_shape_flags.unique_fntid_flag;

    while((fl_str_increment_length > 0U) && (p_string[fl_str_increment_length] !=  (HMI_CHAR)'\0') && 
          (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode, fl_is_complex, fl_is_character, fl_fnt_uniq_id) == 0U))
  #else
    while((fl_str_increment_length > 0U) && (p_string[fl_str_increment_length] != (HMI_CHAR)0) && (GFX_MGR02_IS_PRINTABLE_CHAR(fl_char_unicode) == 0U))
  #endif
    {
      fl_str_increment_length--;
      fl_char_unicode = p_string[fl_str_increment_length];
      #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
      {
        fl_is_character = fl_ML_data_ptr->is_character[fl_str_increment_length];
      }
      #endif        
    }
  }
  return (fl_str_increment_length);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_multiline_text()
Description          : Returns the multi line text with word wrap done
Invocation           : Invoked by hmi_gfx_mgr02_build_multiline_text.
Return Value         : GFX_MGR02_TEXT_INFO
Parameters           : Text definition, string, append(enable/disable)
******************************************************************************/
static GFX_MGR02_TEXT_INFO hmi_gfx_mgr02_get_multiline_text(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const * p_string,
                                        u_gx_flocal                        p_append,
                                        u_gx_flocal *             p_str_incr_length,
                                         GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   const* p_dep_param,
                                        BOOLEAN p_is_RTL_lang)
{
  GFX_MGR02_TEXT_INFO  fl_text_info_S;
  u_gx_flocal fl_clip_flag;
  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  HMI_CHAR             fl_append_string[GFX_MGR02_MAX_TEXT_LENGTH+1];
  #endif
  fl_text_info_S.dyn_text_def_SP = GFX_MGR02_NULL_PTR;
  fl_text_info_S.print_sindex_U8 = 0;

  if(p_string[0] != (HMI_CHAR)0)
  {
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};

    hmi_gfx_mgr02_get_shaping_flags(p_elem_def_SP, p_string, p_str_incr_length[0], &fl_shape_flags);
    fl_text_info_S.is_complex = fl_shape_flags.complexity_flag;
    fl_text_info_S.str_offset_idx = fl_shape_flags.current_str_index;
    fl_text_info_S.is_ml_data_still_exist = 0U;
#endif

    fl_text_info_S.print_str_P         = p_string;
    fl_text_info_S.coord.x             = 0;
    fl_text_info_S.coord.y             = 0;
    fl_text_info_S.print_width         = 0;
    fl_text_info_S.db_format           = 0;
    fl_text_info_S.print_length_U8     = 0;
    fl_text_info_S.scroll              = 0;
   #if defined(GFX_MGR02_OPEN_VG)
    fl_text_info_S.target              = GFX_MGR02_TARGET_OPENVG;
   #elif defined(GFX_MGR02_AMBER)
    fl_text_info_S.target              = GFX_MGR02_TARGET_AMBER; 
   #elif defined(GFX_MGR02_AMBER_IRIS)
    fl_text_info_S.target              = GFX_MGR02_TARGET_AMBER_IRIS;      
   #elif defined(GFX_MGR02_OPEN_GL)
    fl_text_info_S.target              = GFX_MGR02_TARGET_OPENGL;   
   #elif defined(GFX_MGR02_TRAVEO2)	
    fl_text_info_S.target              = GFX_MGR02_TARGET_TRAVEO2; 
   #elif defined(GFX_MGR02_IMXRT)
    fl_text_info_S.target              = GFX_MGR02_TARGET_IMXRT;           
   #elif defined(GFX_MGR02_IMXRT_PXP)
    fl_text_info_S.target              = GFX_MGR02_TARGET_IMXRT_PXP;
   #endif

    fl_text_info_S.dyn_text_def_SP = p_elem_def_SP;
    fl_text_info_S.max_available_width = (UINT16)p_dep_param->text_width;
    fl_text_info_S.append_str          = (UINT8)p_append;
    fl_text_info_S.num_chars_to_process = (UINT16)HMI_STRLEN(p_string);
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    fl_text_info_S.font_pt_size = p_dep_param->font_pt_size;
#endif
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
    fl_text_info_S.get_dynamic_clipinfo = (UINT8)FALSE;
#endif

    /* For arabic string, width calculation is done from right to left and for non-arabic string it is done
        from left to right. */
    fl_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                  p_dep_param->font_id,
                                                  p_dep_param->clip_mode,
                                                  p_is_RTL_lang
                                                  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                  ,&fl_append_string[0]
                                                  #endif
                                                  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                  ,GFX_MGR02_NULL_PTR
                                                  #endif
                                                  );

    if(fl_text_info_S.print_length_U8 > 0U)
    {
      #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
      /* To append at the last full word, the append string is removed before processing
      the multi-line algorithm */
      if((p_append == TRUE) && (fl_clip_flag == TRUE))
      {
          fl_text_info_S.print_length_U8 -= (UINT8)GFX_MGR02_APPEND_CHAR_CNT;
          /*This flag is set to indicate that the appended character count is removed so that it is added again if the text contains the append string during the algorithm processing */
          fl_text_info_S.append_str = TRUE;
      }
      else
      {
          fl_text_info_S.append_str = FALSE;
      }
      #else
      GFX_MGR02_UNUSED_VAR(fl_clip_flag);
      #endif
      #if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
      if(p_is_RTL_lang != FALSE)
      {
        *p_str_incr_length = hmi_gfx_mgr02_RTL_multiline_algorithm(&fl_text_info_S,p_string, p_dep_param);
      }
      else
      #endif
      {
        *p_str_incr_length = hmi_gfx_mgr02_multiline_algorithm(&fl_text_info_S,p_string, p_dep_param);
      }
    }
    else
    {
    }
  }
  else
  {
    fl_text_info_S.print_str_P = GFX_MGR02_NULL_PTR;
    fl_text_info_S.coord.x             = 0;
    fl_text_info_S.coord.y             = 0;
    fl_text_info_S.max_available_width = 0;
    fl_text_info_S.print_width         = 0;
    fl_text_info_S.print_length_U8     = 0;
    fl_text_info_S.scroll              = 0;
    fl_text_info_S.db_format           = 0;
    fl_text_info_S.target              = 0;
    fl_text_info_S.num_chars_to_process = 0;
    fl_text_info_S.append_str          = 0;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    fl_text_info_S.font_pt_size        = 0;
#endif
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
    fl_text_info_S.get_dynamic_clipinfo = (UINT8)FALSE;
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    fl_text_info_S.is_complex             = 0U;
    fl_text_info_S.str_offset_idx         = 0U;
    fl_text_info_S.is_ml_data_still_exist = 0U;
#endif
  }
  return fl_text_info_S;
}


/****************************************************************************
Function Name        : hmi_gfx_mgr02_evaluate_multiline_start_pos()
Description          : Returns the multi line start position
Invocation           : Invoked by hmi_gfx_mgr02_run_multiline_algorithm.
Return Value         : u_gx_flocal - Line start position
Parameters           : String, Arabic Bool, Current start position
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_evaluate_multiline_start_pos(HMI_CHAR const * p_string,
                                                              BOOLEAN          p_is_RTL_lang,
                                                              u_gx_flocal      p_line_start_pos
                                                           #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                              ,GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP
                                                           #endif
                                                              )
{
  HMI_CHAR                   fl_unicode;
  u_gx_flocal                fl_line_start_position = p_line_start_pos;
  u_gx_flocal fl_str_len = (u_gx_flocal)HMI_STRLEN(p_string);
  

  if((fl_line_start_position < GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH) && (fl_line_start_position < fl_str_len) && (p_string[fl_line_start_position] != (HMI_CHAR)0))
  {
    fl_unicode = p_string[fl_line_start_position];
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};
    UINT8 fl_is_character = (UINT8)FALSE;
    GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
    if(p_elem_def_SP->ml_string_index <GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS)
    {
      fl_ML_data_ptr = &l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index];
      hmi_gfx_mgr02_get_shaping_flags(p_elem_def_SP, p_string, fl_line_start_position, &fl_shape_flags);
      fl_is_character = fl_ML_data_ptr->is_character[fl_line_start_position];
    }
    while((GFX_MGR02_IS_PRINTABLE_CHAR(fl_unicode, fl_shape_flags.complexity_flag, fl_is_character, fl_shape_flags.unique_fntid_flag) == FALSE) && 
          (p_string[fl_line_start_position] != (HMI_CHAR)0))
    #else
    while((GFX_MGR02_IS_PRINTABLE_CHAR(fl_unicode) == FALSE) && (p_string[fl_line_start_position] != (HMI_CHAR)0)) 
    #endif
    {
      if(p_is_RTL_lang == FALSE)
      {
        fl_line_start_position++;
      }
      else
      {
        fl_line_start_position--;
      }
      
      if(fl_line_start_position < fl_str_len)
      {
        fl_unicode = p_string[fl_line_start_position];
        #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        if(fl_ML_data_ptr != GFX_MGR02_NULL_PTR)
        {
          fl_is_character = fl_ML_data_ptr->is_character[fl_line_start_position];
        }
        #endif
      }
    }
  }
  return fl_line_start_position;
} 

/****************************************************************************
Function Name        : hmi_gfx_mgr02_evaluate_prev_scroll_offset()
Description          : Returns the multi line array index
Invocation           : Invoked by hmi_gfx_mgr02_run_multiline_algorithm.
Return Value         : u_gx_flocal
Parameters           : Text definition, Multi line array, Multi line parameters, display lines
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_evaluate_prev_multiline_data(GFX_MGR02_TEXT_DEF_T const  * p_elem_def_SP, 
                                                            GFX_MGR02_MULTI_LINE_DATA   * p_multi_line_array, 
                                                            GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM *p_dep_param,
                                                            u_gx_flocal * p_display_lines)
{
    u_gx_flocal fl_index = 0;
    UINT16      fl_line;
    GFX_MGR02_MULTI_LINE_INFO  fl_temp_multi_info = {0};
    u_gx_flocal fl_saved_lines = 0;
    GFX_MGR02_MULTI_LINE_DATA   * fl_multi_line_array = p_multi_line_array;
    
    hmi_gfx_mgr02_get_dyn_text_multiline_data(p_elem_def_SP, &fl_temp_multi_info, p_multi_line_array, 0);

    for(fl_line = 0U; fl_line < p_elem_def_SP->max_num_of_lines; fl_line++)
    {
      fl_index = (u_gx_flocal)fl_line;
      if((fl_multi_line_array->parameter.strlength > 0U) && (fl_saved_lines < p_dep_param->num_of_display_lines))
      {
        if(p_dep_param->scroll_offset > 0U)
        {
          p_dep_param->scroll_offset--;
        }
        else
        {
          fl_saved_lines++;
        }
        fl_multi_line_array++;
      }
      else
      {
        if(fl_index > 0U)
        {
          fl_multi_line_array--;
          fl_index--;
        }
        break;
      }
    }

    *p_display_lines = fl_saved_lines;
    p_dep_param->evaluale_and_run = FALSE;
    GFX_MGR02_UNUSED_VAR(fl_multi_line_array);
    return fl_index;
} 

/****************************************************************************
Function Name        : hmi_gfx_mgr02_run_multiline_algorithm()
Description          : Performs multi line algorithm for the given text. 
Invocation           : Invoked by graphics manager.
Return Value         : GFX_MGR02_MULTI_LINE_INFO
Parameters           : text definition, string, scroll offset, multi line array, num of lines
******************************************************************************/
GFX_MGR02_MULTI_LINE_INFO hmi_gfx_mgr02_run_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const             * p_string,
                                        GFX_MGR02_MULTI_LINE_DATA              *p_multi_line_array,
                                        GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   *p_dep_param,
                                        BOOLEAN p_is_RTL_lang)
{
  GFX_MGR02_MULTI_LINE_INFO  fl_multi_line_info;
  u_gx_flocal                fl_actual_displayed_lines = 0;
  u_gx_flocal                fl_append = FALSE;
  u_gx_flocal                fl_str_incr_length     = 0;
  HMI_CHAR            const *fl_str_end_loc_SP      = p_string;
  GFX_MGR02_TEXT_INFO        fl_text_info_S;
  u_gx_flocal                fl_line_start_pos      = 0;
  u_gx_flocal                fl_current_index;
  u_gx_flocal                fl_saved_display_lines = 0;
  u_gx_flocal                fl_line_start_prev_pos = 0;
  BOOLEAN fl_data_updated                           = FALSE;
  GFX_MGR02_MULTI_LINE_DATA  *fl_multi_line_array   = &p_multi_line_array[0];

  fl_multi_line_info.is_data_available = 0;

  while((fl_actual_displayed_lines <  p_dep_param->num_of_display_lines) && (fl_str_end_loc_SP[0] != (HMI_CHAR)0))
  {    
    /* Evaluate the prev_scroll offset and Scroll the lines for the remaining p_scroll_offset */ 
    if(p_dep_param->evaluale_and_run  != FALSE)
    {
      fl_current_index     = hmi_gfx_mgr02_evaluate_prev_multiline_data(p_elem_def_SP, fl_multi_line_array, p_dep_param, &fl_saved_display_lines);
      if( fl_current_index > 0U)
      {
        fl_multi_line_array  = fl_multi_line_array + fl_current_index;
        fl_line_start_pos    = (u_gx_flocal)fl_multi_line_array->start_pos + fl_multi_line_array->parameter.strlength;
        fl_multi_line_array++;
        fl_str_end_loc_SP    = fl_str_end_loc_SP + fl_line_start_pos;
        fl_actual_displayed_lines = fl_saved_display_lines;
      }
    }
    else
    {
      fl_data_updated            = TRUE;
      if((p_dep_param->clip_mode == GFX_MGR02_TP_CLIP_APPEND) &&
      (fl_actual_displayed_lines == (p_dep_param->num_of_display_lines - 1U)) &&
      (p_dep_param->scroll_offset == 0U))
      {          
        fl_append = TRUE;
      }
      fl_line_start_prev_pos = fl_line_start_pos;
      fl_line_start_pos += hmi_gfx_mgr02_evaluate_multiline_start_pos(fl_str_end_loc_SP, p_is_RTL_lang, 0
                                                                                                  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                                                     ,p_elem_def_SP
                                                                                                  #endif
                                                                                          );
      fl_str_end_loc_SP = fl_str_end_loc_SP + (fl_line_start_pos - fl_line_start_prev_pos);
      fl_text_info_S = hmi_gfx_mgr02_get_multiline_text(p_elem_def_SP,fl_str_end_loc_SP,fl_append, &fl_str_incr_length, p_dep_param, p_is_RTL_lang);
      if((fl_text_info_S.print_str_P != GFX_MGR02_NULL_PTR) && (fl_text_info_S.print_length_U8 > 0U))
      {          
        fl_multi_line_array->start_pos     = (UINT16)fl_line_start_pos;
        fl_multi_line_array->parameter.int_multi_line_data.string_length = fl_text_info_S.print_length_U8;
        #ifdef GFX_MGR02_HARDCUT_ENABLED
        /* The information that a char hard cut is done is saved in print_sindex_U8 locally */
        if((GFX_MGR02_HARDCUT_CHAR != 0) && (fl_text_info_S.print_sindex_U8 == TRUE))
        {
          fl_multi_line_array->parameter.int_multi_line_data.is_char_hard_cut = TRUE;
        }
        #endif
        if(p_dep_param->scroll_offset == 0U)
        {
          fl_actual_displayed_lines++;
        }
        else
        {
          p_dep_param->scroll_offset--;
        }
        fl_multi_line_array++;
        fl_str_end_loc_SP = fl_str_end_loc_SP + fl_str_incr_length;
        fl_line_start_pos += fl_str_incr_length;
      }
      else
      {
        break;
      }
    }
  }

  /* After executing the last line, if text is still available then set flag */
  if(fl_actual_displayed_lines == p_dep_param->num_of_display_lines)
  {
    if(fl_str_end_loc_SP[0] != (HMI_CHAR)0)
    {
      fl_multi_line_info.is_data_available = 1U;
    }
  }
  fl_multi_line_info.num_of_display_lines = fl_actual_displayed_lines;

  /*Update the data into dynamic buffer for dynamic text*/
  if(p_elem_def_SP->dynamic != FALSE)
  {
    hmi_gfx_mgr02_set_dyn_text_multiline_data(p_elem_def_SP, &fl_multi_line_info, &p_multi_line_array[0], fl_data_updated);
  }

  return fl_multi_line_info;
}

#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_run_RTL_multiline_algorithm()
Description          : Performs multi line algorithm for the given text. 
Invocation           : Invoked by graphics manager.
Return Value         : GFX_MGR02_MULTI_LINE_INFO
Parameters           : text definition, string, scroll offset, multi line array, num of lines
******************************************************************************/
GFX_MGR02_MULTI_LINE_INFO hmi_gfx_mgr02_run_RTL_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const             * p_string,
                                        GFX_MGR02_MULTI_LINE_DATA              *p_multi_line_array,
                                        GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   *p_dep_param,
                                        BOOLEAN p_is_RTL_lang)
{
  GFX_MGR02_MULTI_LINE_INFO  fl_multi_line_info;
  u_gx_flocal          fl_actual_displayed_lines = 0;
  u_gx_flocal                fl_append = FALSE;
  
  GFX_MGR02_TEXT_INFO  fl_text_info_S;
  u_gx_flocal                fl_str_length = HMI_STRLEN(p_string);
  HMI_CHAR                   fl_str_arabic_end_loc_SP[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH + 1U];
  u_gx_flocal                fl_line_start_pos;
  u_gx_flocal                fl_str_incr_length;
  u_gx_flocal                fl_current_index;
  u_gx_flocal                fl_saved_display_lines = 0;
  BOOLEAN                    fl_data_updated        = FALSE;
  GFX_MGR02_MULTI_LINE_DATA  *fl_multi_line_array   = &p_multi_line_array[0];

  fl_multi_line_info.is_data_available = 0;
  (void)memset(&fl_str_arabic_end_loc_SP[0], 0, sizeof(fl_str_arabic_end_loc_SP)); 
  if  (fl_str_length > (u_gx_flocal)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
  {
    fl_str_length = GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH;
  }
   fl_str_incr_length = fl_str_length;
   fl_line_start_pos = fl_str_length - 1U;
  (void)HMI_STRNCPY(fl_str_arabic_end_loc_SP, p_string, fl_str_length);

  while((fl_actual_displayed_lines <  p_dep_param->num_of_display_lines) && (fl_str_arabic_end_loc_SP[0] != (HMI_CHAR)0))
  {    
    /* Scroll the lines for the given p_scroll_offset */ 
    if(p_dep_param->evaluale_and_run != FALSE)
    {
      fl_current_index = hmi_gfx_mgr02_evaluate_prev_multiline_data(p_elem_def_SP, fl_multi_line_array, p_dep_param, &fl_saved_display_lines);
      if(fl_current_index > 0U)
      {
        fl_multi_line_array += fl_current_index;
        if (fl_multi_line_array->start_pos <= GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
        {
          if(fl_multi_line_array->start_pos > 0U)
          {
            /* From the p_multi_line_array->start_pos data will be displayed.
            Hence data to be processed is from the previous character */
            fl_line_start_pos = (u_gx_flocal)fl_multi_line_array->start_pos - 1U;
          }
          else
          {
            /* When there is no data to be processed then string is made empty
            If the value is 0 then it means the whole string has been processed.*/
          }
          fl_str_arabic_end_loc_SP[fl_multi_line_array->start_pos] = (HMI_CHAR)0;
          fl_multi_line_array++;
          fl_actual_displayed_lines = fl_saved_display_lines;
        }
      }
    }
    else
    {
      fl_data_updated = TRUE;
      fl_line_start_pos = hmi_gfx_mgr02_evaluate_multiline_start_pos(p_string, p_is_RTL_lang, fl_line_start_pos
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                                                     ,
                                                                     p_elem_def_SP
#endif
      );
      if (fl_line_start_pos < GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
      {
        fl_str_arabic_end_loc_SP[fl_line_start_pos + 1U] = (HMI_CHAR)0;
        fl_str_length = HMI_STRLEN(fl_str_arabic_end_loc_SP);
        if ((p_dep_param->clip_mode == GFX_MGR02_TP_CLIP_APPEND) && (fl_actual_displayed_lines == (p_dep_param->num_of_display_lines - 1U)))
        {
          fl_append = TRUE;
        }
        fl_text_info_S = hmi_gfx_mgr02_get_multiline_text(p_elem_def_SP, fl_str_arabic_end_loc_SP, fl_append, &fl_str_incr_length, p_dep_param, p_is_RTL_lang);
        fl_line_start_pos = fl_str_length - fl_text_info_S.print_length_U8;
        if ((fl_text_info_S.print_str_P != GFX_MGR02_NULL_PTR) && (fl_text_info_S.print_length_U8 > 0U))
        {
          fl_multi_line_array->start_pos = (UINT16)fl_line_start_pos;
          fl_multi_line_array->parameter.int_multi_line_data.string_length = fl_text_info_S.print_length_U8;
          /* The information that an arabic hard cut is done is saved in print_sindex_U8 locally */
          if (fl_text_info_S.print_sindex_U8 == TRUE)
          {
            fl_multi_line_array->parameter.int_multi_line_data.is_arabic_hard_cut = TRUE;
          }
          if (p_dep_param->scroll_offset == 0U)
          {
            fl_actual_displayed_lines++;
          }
          else
          {
            p_dep_param->scroll_offset--;
          }
          fl_multi_line_array++;
          if (fl_str_incr_length < (u_gx_flocal)GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
          {
            fl_str_arabic_end_loc_SP[fl_str_incr_length + 1U] = (HMI_CHAR)0;
          }
          else
          {
            fl_str_arabic_end_loc_SP[0] = (HMI_CHAR)0;
          }
        }
        else
        {
          break;
        }
      }
    }
  }

  /* After executing the last line, if text is still available then set flag */
  if(fl_actual_displayed_lines == p_dep_param->num_of_display_lines)
  {
    if(fl_str_arabic_end_loc_SP[0] != (HMI_CHAR)0)
    {
      fl_multi_line_info.is_data_available = 1U;
    }
  }
  fl_multi_line_info.num_of_display_lines = fl_actual_displayed_lines;
  /*Update the data into dynamic buffer for dynamic text*/
  if(p_elem_def_SP->dynamic != FALSE)
  {
      hmi_gfx_mgr02_set_dyn_text_multiline_data(p_elem_def_SP, &fl_multi_line_info, &p_multi_line_array[0], fl_data_updated);
  }
  return fl_multi_line_info;
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_build_multiline_text()
Description          : Performs multi line text building.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_text.
Return Value         : none
Parameters           : Context pointer, text definition, string, scroll offset
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_build_multiline_text(GFX_MGR02_CONTEXT_T  * p_cntx_SP, 
                                        GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                        HMI_CHAR             const * p_string,
                                        u_gx_flocal                  p_scroll_offset,
                                        u_gx_flocal                  p_num_of_lines_to_be_displayed,
                                        SINT8                        p_inter_line_spacing)
{
  u_gx_flocal          fl_displayed_lines;
  u_gx_flocal          fl_actual_displayed_lines = 0;
  HMI_CHAR      const *fl_str_end_loc_SP;
  s_gx_flocal               fl_default_elem_y = p_cntx_SP->state.loc.y;
  GFX_MGR02_FSIZE_X_T       fl_default_pivot_x = p_cntx_SP->rprop.pivot.x;  
  GFX_MGR02_MULTI_LINE_DATA   fl_multi_line_array[GFX_MGR02_MULTI_LINE_ARRAY_SIZE];
  HMI_CHAR             fl_line_string[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
  GFX_MGR02_FONT const *fl_font_SP = hmi_gfx_mgr02_get_font_pointer((UINT32)p_cntx_SP->rprop.font_id);
  GFX_MGR02_MULTI_LINE_INFO  fl_multi_line_info = {0};
  HMI_CHAR       const * fl_string_ptr;
 #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  GFX_MGR02_SHAPE_FLAGS fl_shape_flags = {0U,0U,0U,0U};
 #endif

  (void)memset(&fl_multi_line_array[0], 0, sizeof(fl_multi_line_array));
  if(p_elem_def_SP->dynamic == (UINT8)0)
  {
    /* If static text then run the algorithm */
    GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM   p_multi_line_param;
    p_multi_line_param.alignment = p_cntx_SP->rprop.alignment;
    p_multi_line_param.clip_mode = p_cntx_SP->rprop.clip_mode;
    p_multi_line_param.font_id = p_cntx_SP->rprop.font_id;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    p_multi_line_param.font_pt_size = p_cntx_SP->rprop.font_size.point_size;
#endif
    p_multi_line_param.num_of_display_lines = p_num_of_lines_to_be_displayed;
    p_multi_line_param.scroll_offset = p_scroll_offset;
    p_multi_line_param.text_width = p_cntx_SP->rprop.text_width;
    p_multi_line_param.evaluale_and_run = FALSE;

   #if defined (GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) && defined (GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
    if((hmi_gfx_mgr02_get_arabic_char_count(p_string,(UINT16)HMI_STRLEN(p_string)) != 0U) ||
       (hmi_gfx_mgr02_get_hebrew_char_count(p_string,(UINT16)HMI_STRLEN(p_string)) != 0U))
    {
      fl_multi_line_info = hmi_gfx_mgr02_run_RTL_multiline_algorithm(p_elem_def_SP,p_string,&fl_multi_line_array[0],&p_multi_line_param,TRUE);
    }
    else
   #else
    #ifdef GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED
    if(hmi_gfx_mgr02_get_arabic_char_count(p_string,(UINT16)HMI_STRLEN(p_string)) != 0U)
    {
      fl_multi_line_info = hmi_gfx_mgr02_run_RTL_multiline_algorithm(p_elem_def_SP,p_string,&fl_multi_line_array[0],&p_multi_line_param,TRUE);
    }
    else
    #endif
    #ifdef GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED
    if(hmi_gfx_mgr02_get_hebrew_char_count(p_string,(UINT16)HMI_STRLEN(p_string)) != 0U)
    {
      fl_multi_line_info = hmi_gfx_mgr02_run_RTL_multiline_algorithm(p_elem_def_SP,p_string,&fl_multi_line_array[0],&p_multi_line_param,TRUE);
    }
    else
    #endif
   #endif
    {
      /* If static text then run the algorithm */
      fl_multi_line_info = hmi_gfx_mgr02_run_multiline_algorithm(p_elem_def_SP,p_string,&fl_multi_line_array[0],&p_multi_line_param,FALSE);
    }
  }
  else
  { 
    /*
Multiline algorithm executed in the following way

1.GFX_MGR02_RUN_ML_ALG_FROM_PRESN - Enabled
   a. First time algorithm will run for the number of display line configured in GDT design(pEvalAndRun - False)
   b. When there is any change in scroll offset/num of display lines, existing algorithm output is reused and alg run for the required lines(pEvalAndRun - True from set_text_scroll_parameter and set_dim_h)
   c. If there is any change in the text parameter which affects the alg output, only set_modified flag is set from that API, and from the next build, it will rerun with the latest parameters
2.GFX_MGR02_RUN_ML_ALG_FROM_PRESN - Disabled
   a. Whenever there is any change in parameter which affects the multiline alg output, alg output invalidated in set_multiline_modified API
   b. pEvalAndRun is passed as true to run only to show the current display data
*/
#if defined(GFX_MGR02_RUN_ML_ALG_FROM_PRESN)
    hmi_gfx_mgr02_layout_run_multiline_algorithm(p_elem_def_SP, FALSE, FALSE);
#else
    hmi_gfx_mgr02_layout_run_multiline_algorithm(p_elem_def_SP, FALSE, TRUE);
#endif
    /* If dynamic text then fetch the data from the saved values */
    hmi_gfx_mgr02_get_dyn_text_multiline_data(p_elem_def_SP, &fl_multi_line_info,&fl_multi_line_array[0],(u_gx_flocal)p_cntx_SP->rprop.scroll_offset);
  }

  fl_displayed_lines = fl_multi_line_info.num_of_display_lines;

 #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
  hmi_gfx_mgr02_get_shaping_flags(p_elem_def_SP, p_string, 0, &fl_shape_flags);
  if((fl_shape_flags.complexity_flag != (UINT8)FALSE) && (p_elem_def_SP->ml_string_index < GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS))
  {
     GFX_MGR02_SHAPE_ML_DATA *fl_ML_data_ptr = &l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index];
     fl_string_ptr = fl_ML_data_ptr->input_string;
  }
  else
  {
    fl_string_ptr = p_string;
  }
 #else
  fl_string_ptr = p_string;
 #endif
  while ((fl_actual_displayed_lines < fl_displayed_lines) && (fl_actual_displayed_lines < GFX_MGR02_MULTI_LINE_ARRAY_SIZE))
  {
    fl_str_end_loc_SP = fl_string_ptr;
    fl_str_end_loc_SP = fl_str_end_loc_SP + fl_multi_line_array[fl_actual_displayed_lines].start_pos;
    if(fl_str_end_loc_SP[0] != (HMI_CHAR)'\0')
    {
      UINT16 fl_num_of_chars;
      #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
      if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
      #endif
      {
        if((fl_actual_displayed_lines > (u_gx_flocal)0) && (fl_font_SP != GFX_MGR02_NULL_PTR))
        {
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
          if(fl_font_SP->is_ffile != (UINT8)FALSE)
          {
            const GFX_MGR02_FONT_SIZE_T* fl_font_size_SP = &p_cntx_SP->rprop.font_size;
            p_cntx_SP->state.loc.y += ((SINT16)fl_font_size_SP->height + (SINT16)p_inter_line_spacing);
          }
          else
#endif
          {
            p_cntx_SP->state.loc.y += ((SINT16)fl_font_SP->p.height + (SINT16)p_inter_line_spacing);
          }
        }
        fl_num_of_chars   = fl_multi_line_array[fl_actual_displayed_lines].parameter.int_multi_line_data.string_length;
        (void)memset(&fl_line_string[0], 0, sizeof(fl_line_string));
        (void)HMI_STRNCPY(&fl_line_string[0], fl_str_end_loc_SP, fl_num_of_chars);
       #if defined(GFX_MGR02_CLIP_TEXT_ENABLE) || defined(GFX_MGR02_HARDCUT_ENABLED) 
        /* After executing the last line, if text is still available then do append */
        if(((fl_actual_displayed_lines == (fl_displayed_lines-1U)) &&
        (fl_multi_line_info.is_data_available != 0U)  &&
        (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_APPEND)) ||
        (fl_multi_line_array[fl_actual_displayed_lines].parameter.int_multi_line_data.is_arabic_hard_cut == TRUE) ||
        (fl_multi_line_array[fl_actual_displayed_lines].parameter.int_multi_line_data.is_char_hard_cut == TRUE))
        {
          u_gx_flocal fl_append_str_index_U8;
          #if defined(GFX_MGR02_CLIP_TEXT_ENABLE) && defined(GFX_MGR_APPEND_BASEDON_APP_IP)
          GFX_CLIP_INFO fl_append_info;
          if(((fl_actual_displayed_lines == (fl_displayed_lines-1U)) &&
          (fl_multi_line_info.is_data_available != 0U)  &&
          (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_APPEND)))
          {
            fl_append_info = GFX_MGR_GET_CLIP_INFO(&fl_line_string[0]);
          }
          else
          {
            fl_append_info = ((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_MASK)) == GFX_MGR02_TP_ALIGN_RIGHT) ? (LEFT_CLIP) : (RIGHT_CLIP);
          }
          if(fl_append_info == RIGHT_CLIP)
          #else
          if((p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_LEFT) ||
             (p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_CENTRE))
          #endif
          {
            #ifdef GFX_MGR02_HARDCUT_ENABLED
            if(fl_multi_line_array[fl_actual_displayed_lines].parameter.int_multi_line_data.is_char_hard_cut == TRUE)
            {
              if(fl_num_of_chars <= GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
              {
                fl_line_string[fl_num_of_chars] = (HMI_CHAR)GFX_MGR02_HARDCUT_CHAR;
                fl_num_of_chars++;
              }
            }
            else
            #endif
            {
            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < (UINT8)GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
            {
              if(fl_num_of_chars <= GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
              {
                fl_line_string[fl_num_of_chars] = (HMI_CHAR)GFX_MGR02_APPEND_CHAR;
                fl_num_of_chars++;
              }
            }
            #endif
            }
          }
          #if defined(GFX_MGR02_CLIP_TEXT_ENABLE) && defined(GFX_MGR_APPEND_BASEDON_APP_IP)
          else if(fl_append_info == LEFT_CLIP)
          #else
          else if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT)
          #endif
          {
            #ifdef GFX_MGR02_HARDCUT_ENABLED
            if(fl_multi_line_array[fl_actual_displayed_lines].parameter.int_multi_line_data.is_char_hard_cut == TRUE)
            {
              fl_line_string[fl_num_of_chars] = GFX_MGR02_HARDCUT_CHAR;
              fl_num_of_chars++;
            }
            else
            #endif 
            {
            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            (void)HMI_STRNCPY(&fl_line_string[GFX_MGR02_APPEND_CHAR_CNT], fl_str_end_loc_SP, fl_num_of_chars);               
            for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < (UINT8)GFX_MGR02_APPEND_CHAR_CNT; fl_append_str_index_U8++)
            {
              fl_line_string[fl_append_str_index_U8] = (HMI_CHAR)GFX_MGR02_APPEND_CHAR;
              fl_num_of_chars++;
            }
            #endif
            }
          }
          else
          {
            /*do nothing*/
          }
        }
        #endif
        /* pivot.x value modified for each line in multiline text, so resetting to the original value */
        p_cntx_SP->rprop.pivot.x = fl_default_pivot_x;
        (void)l_lib_if_SP->build_text(p_cntx_SP, p_elem_def_SP, &fl_line_string[0], 0 , TRUE
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          , fl_multi_line_array[fl_actual_displayed_lines].start_pos
#endif
          );
      }
      fl_actual_displayed_lines++;
        
    }
    else
    {
      break;
    }
  }
  /* loc.y value modified to render the multiple lines, so its reset to the original value */
  p_cntx_SP->state.loc.y = (SINT16)fl_default_elem_y;
  return fl_actual_displayed_lines;
}
#endif


#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_text()
Description          : Builds the text.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Text stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_text(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_text_actual_width, u_gx_flocal p_obj_dirty_U8)
{
   UINT32                          fl_obj_id_U32;
   UINT32                          fl_obj_type_U32;
   GFX_MGR02_TEXT_DEF_T    const * fl_element_def_SP;
   GFX_MGR02_TEXT_PROPERTY const * fl_elem_prop_SP;
   GFX_MGR02_CONTEXT_STATE_T       fl_cur_context_S;
   HMI_CHAR                const * fl_string_ptr = GFX_MGR02_NULL_PTR;
   u_gx_flocal fl_text_actual_width = p_text_actual_width;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))  
#if defined(GFX_MGR02_DIRTY_REGION_REDRAW) || (defined(GFX_MGR02_KEPLER) && defined(GFX_MGR02_OPEN_VG))||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_TRAVEO2)
   u_gx_flocal fl_num_of_lines_displayed = 1U;
#endif
   u_gx_flocal fl_num_of_lines_to_be_displayed = 1u;
   u_gx_flocal fl_scroll_offset = 0;
   SINT8 fl_inter_line_spacing = 0;
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    BOOLEAN fl_scroll_active;
#endif
   GFX_MGR02_FONT const * fl_font_SP;
   UINT32                 fl_font_id;

   fl_cur_context_S.loc.x = 0;
   fl_cur_context_S.loc.y = 0;
   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   fl_obj_type_U32   = GFX_MGR02_GET_OBJ_TYPE(p_elem_SP->obj_id);
   if (p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TEXT_LAYERS)
   {
     #if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
     #if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
       UINT8  fl_shaping_required = hmi_gfx_mgr02_layout_get_txt_shaping_required(p_elem_SP->base_id);
     #endif
     #endif
     #if defined(GFX_MGR02_DLAYOUT_ENABLED)
       fl_element_def_SP = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_SP->base_id);
     #else
       fl_element_def_SP = &lc_text_layer_def_S[p_elem_SP->base_id];
     #endif
       fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_element_def_SP->font_id);
       
        /* Check the image is animable or non-animable */
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
       {
       #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
          if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
          {
              GFX_MGR02_TEXT_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
              UINT8 fl_max_shrink;
#endif
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
              fl_elem_prop_SP      = hmi_gfx_mgr02_get_txt_anim_prop_ptr(fl_obj_id_U32);
            #else
              fl_elem_prop_SP      = &lc_text_anim_property_S[fl_obj_id_U32];
            #endif
              fl_elem_anim_prop_SP = &l_anim_prop_SP->text_prop[fl_obj_id_U32];
              #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)) 
              fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
              if(fl_font_SP != GFX_MGR02_NULL_PTR)
              {
                fl_elem_anim_prop_SP->font_pt_size = fl_font_SP->height_pts;
              }
              #endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
              if (fl_elem_anim_prop_SP->max_shrink != 100U)
              {
                fl_max_shrink = fl_elem_anim_prop_SP->max_shrink;
              }
              else
              {
                fl_max_shrink = hmi_gfx_mgr02_layout_get_text_global_max_shrink();
              }
#endif
              #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2)) 
              fl_scroll_offset                = (u_gx_flocal)fl_elem_anim_prop_SP->scroll_offset;
              fl_num_of_lines_to_be_displayed = fl_elem_anim_prop_SP->num_of_display_lines;
              fl_inter_line_spacing           = fl_elem_anim_prop_SP->inter_line_spacing;
              #endif
              if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
              {
                  hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
                  if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                  {
                      fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
                  }
              }
              else
              {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = (SINT16)0;
                  fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
              }
              hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_anim_prop_SP->alpha);
              hmi_gfx_mgr02_context_set_textprop((u_gx_flocal)fl_elem_anim_prop_SP->font_id,
                                                 (u_gx_flocal)GFX_MGR02_GALIGNMENT(fl_elem_anim_prop_SP->font_id, fl_elem_anim_prop_SP->alignment),
                                                 (u_gx_flocal)fl_elem_anim_prop_SP->draw_mode,
                                                 (u_gx_flocal)fl_elem_anim_prop_SP->clip_mode,
                                                 (u_gx_flocal)fl_elem_anim_prop_SP->scroll_offset,
                                                 (u_gx_flocal)fl_elem_anim_prop_SP->width
        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE))
                                                 ,fl_elem_anim_prop_SP->font_pt_size
        #endif
        #if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
        #if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                                                  ,fl_shaping_required
        #endif
        #endif
        #if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
                                                 , fl_max_shrink
        #endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                                                 , hmi_gfx_mgr02_layout_get_prerender_index(p_elem_SP->base_id)
#endif
                                                 );
            #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
              hmi_gfx_mgr02_set_font_size((UINT32)fl_elem_anim_prop_SP->font_id, fl_elem_anim_prop_SP->font_pt_size);
            #endif
              hmi_gfx_mgr02_context_set_fg_color(fl_elem_anim_prop_SP->color);
              hmi_gfx_mgr02_context_set_bg_color(fl_elem_prop_SP->bg_color);
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
              hmi_gfx_mgr02_context_set_matrix(l_anim_prop_SP->text_ovg_prop[fl_obj_id_U32].matrix);
              hmi_gfx_mgr02_context_set_pivot(&l_anim_prop_SP->text_ovg_prop[fl_obj_id_U32].pivot);
            #endif
          }
       #else
          return; /* This should never happen */
       #endif /* #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0 */
       }
       else
       {
       #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
          if((fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_TEXT_INSTANCES) && (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS))
          {
           #if defined(GFX_MGR02_DLAYOUT_ENABLED)
              fl_elem_prop_SP = hmi_gfx_mgr02_get_txt_const_prop_ptr(fl_obj_id_U32);
           #else
              fl_elem_prop_SP = &lc_text_const_property_S[fl_obj_id_U32];
           #endif
              #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2)) 
                fl_num_of_lines_to_be_displayed = fl_element_def_SP->num_of_display_lines;
                fl_inter_line_spacing           = fl_element_def_SP->inter_line_spacing;
              #endif
              if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
              {
                  hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
                  if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                  {
                      fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
                  }
              }
              else
              {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = (SINT16)0;
                  fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
              }
              hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_prop_SP->alpha);
              hmi_gfx_mgr02_context_set_textprop((u_gx_flocal)fl_element_def_SP->font_id,
                                                 (u_gx_flocal)GFX_MGR02_GALIGNMENT(fl_element_def_SP->font_id, fl_element_def_SP->alignment),
                                                 (u_gx_flocal)fl_element_def_SP->draw_mode,
                                                 (u_gx_flocal)fl_element_def_SP->clip_mode,
                                                 (u_gx_flocal)0,
                                                 (u_gx_flocal)fl_element_def_SP->width
        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE))
                                                 ,(UINT8)lc_gfx_font_table[fl_font_id].height_pts
        #endif
        #if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
        #if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                                                  , fl_shaping_required
        #endif
        #endif
        #if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
                                                 ,hmi_gfx_mgr02_layout_get_text_global_max_shrink()
        #endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                                                 , hmi_gfx_mgr02_layout_get_prerender_index(p_elem_SP->base_id)
#endif
                                                 );
        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
              hmi_gfx_mgr02_set_font_size((UINT32)fl_element_def_SP->font_id, (UINT8)lc_gfx_font_table[fl_font_id].height_pts);
        #endif
              hmi_gfx_mgr02_context_set_fg_color(fl_elem_prop_SP->color);
              hmi_gfx_mgr02_context_set_bg_color(fl_elem_prop_SP->bg_color);
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
              hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
              hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
            #endif
          }
       #else
          GFX_MGR02_UNUSED_VAR(fl_font_id);
          return;  /* This should never happen */
       #endif /* #if GFX_MGR02_NUM_TEXT_INSTANCES > 0 */
       }

       if(fl_obj_type_U32 == (UINT32)GFX_MGR02_TYPE_STEXT)
       {
       #if GFX_MGR02_NUM_OF_STEXTS > 0 
           if(fl_element_def_SP->string_index < (UINT32)GFX_MGR02_STEXTS_BUFFER_SIZE)
           {
              fl_string_ptr = &lc_static_text_buffer[fl_element_def_SP->string_index];
           }
       #endif
       }
       else if(fl_obj_type_U32 == (UINT32)GFX_MGR02_TYPE_DTEXT)
       {
       #if GFX_MGR02_NUM_OF_DTEXTS > 0 
            if (fl_element_def_SP->string_index < (UINT32)GFX_MGR02_DTEXTS_BUFFER_SIZE)
            {
              #if defined(GFX_MGR02_DFLT_TXT_SHAPE_WITH_DUAL_BUF)
                 fl_string_ptr = &l_dynamic_text_buffer_presen[fl_element_def_SP->string_index];
                 if (GFX_MGR02_IS_DO_SHAPE_SET(l_dtext_do_shape_flag_U8A, p_elem_SP->base_id))
                 {
                   u_gx_flocal fl_num_chars = fl_element_def_SP->num_chars;
                  #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
                   if (fl_element_def_SP->max_num_of_lines > (UINT16)1)
                   {
                     fl_num_chars = fl_num_chars * fl_element_def_SP->max_num_of_lines;
                   }
                  #endif
                   hmi_gfx_mgr02_layout_default_text_shape((GFX_MGR02_DTEXT_ID)p_elem_SP->base_id, 
                                                          &l_anim_prop_SP->dtext_str[fl_element_def_SP->string_index],
                                                          &l_dynamic_text_buffer_presen[fl_element_def_SP->string_index], (UINT8)FALSE, (UINT16)fl_num_chars
                                                      #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                                          , (UINT8)TRUE
                                                      #endif
                                                          );
                   GFX_MGR02_CLR_DO_SHAPE_FLAG(l_dtext_do_shape_flag_U8A, p_elem_SP->base_id);
               }
              #else
              fl_string_ptr = &l_anim_prop_SP->dtext_str[fl_element_def_SP->string_index];
              #endif
            }
       #endif
       }
       else
       {
           /*For MISRA warning fix.*/
       }
       
       if(fl_string_ptr != GFX_MGR02_NULL_PTR)
       {
          if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
          {
             gfxlogstop(GFX_LOG_PROCESSING);
             gfxlogcontinue(GFX_LOG_RENDERING);
             if(l_lib_if_SP->build_text != (void *)0)
             {
                 GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
             #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW)
                {
                   const GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                   if(fl_area_SP != GFX_MGR02_NULL_PTR)
                   {
                     hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                   }
                   else
                   {
                      hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
                   }
                }
             #endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED) && (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
                // current implementation supports fl_incr_scroll should be minimum 1 pixel per frame that is GFX_MGR02_PIXEL_SEC_SCROLL_SPEED == atleast 60
                // code should be updated for lower speed
                fl_scroll_active = hmi_gfx_mgr02_layout_get_text_scroll_status((GFX_MGR02_ANIM_ELEM_ID)p_elem_SP->obj_id);
                if ((fl_scroll_active == TRUE) && (fl_context_SP->state.invisible == 0U)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
                    && (fl_context_SP->state.clip.ex > fl_context_SP->state.clip.sx) && (fl_context_SP->state.clip.ey > fl_context_SP->state.clip.sy)
#endif
                    )
                {
                  GFX_FLOAT fl_incr_scroll = (GFX_MGR02_SCROLL_SPEED_IN_PIXELS_PER_SEC / 1000.0F) * 16.67F; // assuming 60 fps frame update

                  if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
                  {
                        l_anim_prop_SP->text_prop[fl_obj_id_U32].scroll_offset += fl_incr_scroll;
                  }
                }
#endif
            #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2)) 
                if((fl_element_def_SP ->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) && 
                  (fl_element_def_SP->max_num_of_lines > 1U))
                {
                  (void)hmi_gfx_mgr02_build_multiline_text(fl_context_SP,fl_element_def_SP,
                    fl_string_ptr,fl_scroll_offset,fl_num_of_lines_to_be_displayed,fl_inter_line_spacing);
                }
                else
                {
                  (void)l_lib_if_SP->build_text(fl_context_SP, fl_element_def_SP, fl_string_ptr, fl_text_actual_width, FALSE
    #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                    , 0U
    #endif
                    );
                } 
             #else
                {
                  (void)l_lib_if_SP->build_text(fl_context_SP, fl_element_def_SP, fl_string_ptr, fl_text_actual_width);
                }
             #endif
             }
             gfxlogstop(GFX_LOG_RENDERING);
             gfxlogcontinue(GFX_LOG_PROCESSING);
          }
       #if defined(GFX_MGR02_DIRTY_REGION_REDRAW) || (defined(GFX_MGR02_KEPLER) && defined(GFX_MGR02_OPEN_VG))||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_SOFTWARE)
          else if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND))
          {
             if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
             {
                GFX_MGR02_CONTEXT_T  * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
                GFX_MGR02_TEXT_T       fl_text_context;
                GFX_MGR02_ISIZE_W_T fl_text_width = (UINT16)0;
                
             #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
                {
                   if (fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS)
                   {
                        fl_text_context.font_id = l_anim_prop_SP->text_prop[fl_obj_id_U32].font_id;
                        fl_text_width = l_anim_prop_SP->text_prop[fl_obj_id_U32].width;
                   }
                   else
                   {
                       /* Execution should not reach here*/
                       fl_text_context.font_id = 0;
                   }
                }
                else
             #endif       
                {
                #if defined(GFX_MGR02_DLAYOUT_ENABLED)
                       fl_text_context.font_id = hmi_gfx_mgr02_get_txt_layer_def_ptr(p_elem_SP->base_id)->font_id;
                #else
                       fl_text_context.font_id = lc_text_layer_def_S[p_elem_SP->base_id].font_id;
                #endif
                   fl_text_width = fl_element_def_SP->width;
                }
                if(fl_text_actual_width == (u_gx_flocal)0)
                {
                   fl_text_actual_width = fl_text_width;
                }
                if(fl_context_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                {
                   GFX_MGR02_ILOC_DATA fl_aligned_loc;
                   fl_aligned_loc.x = ((SINT16)fl_text_actual_width/2);
                   fl_aligned_loc.x = -fl_aligned_loc.x;
                   fl_aligned_loc.y = (SINT16)0;
                #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                   /* 
                   ** handle case where the current alignment is different than default alignment 
                   ** TODO : generate always the xy location top left corner and calculate
                   **        the required xy runtime to avoid these hassle
                   **        Currently the coder generates the xy based on alignment as below
                   **        left align - left top corner of the text box
                   **        center     - mid top of the text box
                   **        right      - right top corner of the text box
                   ** search #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                   ** for all these extra handling which can be removed later
                   */
                   if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
                   {
                      fl_aligned_loc.x += ((SINT16)fl_text_width/2);
                   }
                   else if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                   {
                      fl_aligned_loc.x -= ((SINT16)fl_text_width/2);
                      fl_aligned_loc.x +=1;
                   }
                   else
                   {
                       /*For MISRA warning fix.*/
                   }
                #endif
                   hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
                }
                else if(fl_context_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                   GFX_MGR02_ILOC_DATA fl_aligned_loc;
                   fl_aligned_loc.x = (SINT16)(fl_text_actual_width);
                   fl_aligned_loc.x = (1-fl_aligned_loc.x);
                   fl_aligned_loc.y = (SINT16)0;
                #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                   if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
                   {
                      fl_aligned_loc.x += (SINT16)(fl_text_width);
                   }
                   else if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                   {
                      fl_aligned_loc.x += ((SINT16)fl_text_width/2);
                   }
                   else
                   {
                       /*For MISRA warning fix.*/
                   }
                #endif
                   hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
                }
                else
                {
                #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                   GFX_MGR02_ILOC_DATA fl_aligned_loc;
                   fl_aligned_loc.x = (SINT16)0;
                   fl_aligned_loc.y = (SINT16)0;
                   if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                   {
                      fl_aligned_loc.x -= (((SINT16)fl_text_width)/2);
                   }
                   else if(fl_element_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                   {
                      fl_aligned_loc.x -= (SINT16)fl_text_width;
                   }
                   else
                   {
                       /*For MISRA warning fix.*/
                   }
                   hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
                #endif
                }
                if(fl_text_actual_width != (u_gx_flocal)0)
                {
                   fl_font_SP = hmi_gfx_mgr02_get_font_pointer((UINT32)fl_text_context.font_id);

                   if(fl_font_SP != GFX_MGR02_NULL_PTR)
                   {
                      GFX_FLOAT fl_bound[4];
                      fl_bound[0] = (GFX_FLOAT)0;
                      fl_bound[1] = (GFX_FLOAT)0;
                      fl_bound[2] = (GFX_FLOAT)fl_text_actual_width;
                  #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
                      if((fl_element_def_SP ->wrap_mode == (UINT8)GFX_MGR02_WRAP_WORD) && 
                        (fl_element_def_SP->max_num_of_lines > 1U))
                      {
                        fl_num_of_lines_displayed = hmi_gfx_mgr02_build_multiline_text(fl_context_SP,
                          fl_element_def_SP, fl_string_ptr,fl_scroll_offset,fl_num_of_lines_to_be_displayed,
                          fl_inter_line_spacing);
                      }
                      if(fl_num_of_lines_displayed > (u_gx_flocal)1)
                      {
                        #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)))
                        GFX_MGR02_CONTEXT_T * fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
                        fl_bound[3]  = ((GFX_FLOAT)fl_context_sp->rprop.font_size.height * (GFX_FLOAT)fl_num_of_lines_displayed);
                        #else
                        fl_bound[3]  = ((GFX_FLOAT)fl_font_SP->p.height * (GFX_FLOAT)fl_num_of_lines_displayed);
                        #endif
                        fl_bound[3] += ((GFX_FLOAT)(fl_inter_line_spacing) *( (GFX_FLOAT)fl_num_of_lines_displayed - 1.0F));
                      }
                      else
                    #endif
                      {
                        #if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
                        GFX_MGR02_CONTEXT_T * fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
                        fl_bound[3]  = ((GFX_FLOAT)fl_context_sp->rprop.font_size.height);
                        #elif (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
                        GFX_MGR02_CONTEXT_T * fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
                        fl_bound[3]  = (GFX_FLOAT)fl_context_sp->rprop.font_size.height;
                        #else
                        fl_bound[3] = (GFX_FLOAT)fl_font_SP->p.height;
                        #endif
                      }
                      if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
                      {
                            const GFX_MGR02_CONTEXT_T * fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
                            (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_DTEXT, (GFX_MGR02_CONTEXT_T const *)fl_context_sp, fl_bound);
                            hmi_gfx_mgr02_generic_add_bound(fl_bound);
                      }
                      else
                      {
                      #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
                         GFX_MGR02_DAR_OBJECT fl_dar_SP;
                         if(fl_context_SP->rprop.draw_mode == GFX_MGR02_TP_DRAW_TRANSP)
                         {
                            fl_dar_SP.opeque = (UINT8)0;
                         }
                         else
                         {
                            fl_dar_SP.opeque = (UINT8)1;
                         }
                         #if defined(GFX_MGR02_OPEN_GL)	&&  defined(GFX_MGR02_DYNAMIC_BOUNDS_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
                         fl_context_SP->rprop.gl_string_ptr = fl_string_ptr;
                         #endif
                         (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_DTEXT, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
                         fl_dar_SP.elem_SP     = p_elem_SP;
                         fl_dar_SP.dirty_area  = (UINT8)p_obj_dirty_U8;
                         (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
                      #endif
                      }
                   }
                }
             }
          }
       #endif
          else
          {
            /*warning fix*/
          }
       }
       hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const*)&fl_cur_context_S);
       GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
#if defined(GFX_MGR02_MONOTFT)
       GFX_MGR02_UNUSED_VAR(fl_font_id);
       GFX_MGR02_UNUSED_PTR(fl_font_SP);
#endif
   }
}
#endif
/* #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 */

#if GFX_MGR02_NUM_OF_TILES > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_tile()
Description          : Tiles the screen with the given object.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Tile screen stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_tile(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8)
{
   UINT32                          fl_obj_id_U32;
   GFX_MGR02_TILE_DEF_T    const * fl_element_def_SP;
   GFX_MGR02_TILE_PROPERTY const * fl_elem_prop_SP;
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
   GFX_MGR02_TILE_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
   GFX_MGR02_CONTEXT_STATE_T       fl_cur_context_S;

   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   #if defined(GFX_MGR02_DLAYOUT_ENABLED)
   fl_element_def_SP = hmi_gfx_mgr02_get_tile_layer_def_ptr(p_elem_SP->base_id);
   #else  
   fl_element_def_SP = &lc_tile_layer_def_S[p_elem_SP->base_id];
   #endif

    /* Check the image is animable or non-animable */
   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
   {
   #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
      GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      fl_elem_prop_SP      = hmi_gfx_mgr02_get_tile_anim_prop_ptr(fl_obj_id_U32);
    #else  
      fl_elem_prop_SP      = &lc_tile_anim_property_S[fl_obj_id_U32];
    #endif
      fl_elem_anim_prop_SP = &l_anim_prop_SP->tile_prop[fl_obj_id_U32];
      if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
      {
          hmi_gfx_mgr02_context_set_loc(&fl_elem_anim_prop_SP->coord);
          if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
          {
              fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
          }
      }
      else
      {
          GFX_MGR02_ILOC_DATA fl_aligned_loc;
          fl_aligned_loc.x = (SINT16)0;
          fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
          hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
      }
      hmi_gfx_mgr02_context_set_alpha(fl_elem_anim_prop_SP->alpha);
    #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
      hmi_gfx_mgr02_context_set_matrix(l_anim_prop_SP->tile_ovg_prop[fl_obj_id_U32].matrix);
      hmi_gfx_mgr02_context_set_pivot(&l_anim_prop_SP->tile_ovg_prop[fl_obj_id_U32].pivot);
    #endif
      if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
      {
         gfxlogstop(GFX_LOG_PROCESSING);
         gfxlogcontinue(GFX_LOG_RENDERING);
         if(l_lib_if_SP->build_tile != 0)
         {
         #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
            if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW)
            {
               GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
               if(fl_area_SP != 0)
               {
                  hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
               }
               else
               {
                  hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
               }
            }
         #endif
            (void)l_lib_if_SP->build_tile(fl_context_SP, fl_element_def_SP, &fl_elem_anim_prop_SP->dim);
         }
         gfxlogstop(GFX_LOG_RENDERING);
         gfxlogcontinue(GFX_LOG_PROCESSING);
      }
    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_MGR02_DAR_OBJECT fl_dar_SP;
            GFX_FLOAT                fl_bound[4];

            fl_bound[0] = (GFX_FLOAT)0;
            fl_bound[1] = (GFX_FLOAT)0;
            fl_bound[2] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.width;
            fl_bound[3] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.height;
            (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_TILE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);

            fl_dar_SP.elem_SP     = p_elem_SP;
            fl_dar_SP.dirty_area  = p_obj_dirty_U8;
            fl_dar_SP.opeque      = (UINT8)1;
            (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
         }
      }
    #endif
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_FLOAT                fl_bound[4];

            fl_bound[0] = (GFX_FLOAT)0;
            fl_bound[1] = (GFX_FLOAT)0;
            fl_bound[2] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.width;
            fl_bound[3] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.height;
            (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_TILE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
            (void)hmi_gfx_mgr02_generic_add_bound(fl_bound);
         }
      }
      else
      {
        /*warning fix*/
      }
   #else
      return; /* This should never happen */
   #endif /* #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0 */
   }
   else
   {
   #if GFX_MGR02_NUM_TILE_INSTANCES > 0
      GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
    #if defined(GFX_MGR02_DLAYOUT_ENABLED)
      fl_elem_prop_SP = hmi_gfx_mgr02_get_tile_const_prop_ptr(fl_obj_id_U32);
    #else  
      fl_elem_prop_SP = &lc_tile_const_property_S[fl_obj_id_U32];
    #endif
      if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
      {
          hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
          if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
          {
              fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
          }
      }
      else
      {
          GFX_MGR02_ILOC_DATA fl_aligned_loc;
          fl_aligned_loc.x = (SINT16)0;
          fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
          hmi_gfx_mgr02_context_set_loc(&fl_aligned_loc);
      }
      hmi_gfx_mgr02_context_set_alpha(fl_elem_prop_SP->alpha);
    #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
      hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
      hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
    #endif
      if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
      {
         gfxlogstop(GFX_LOG_PROCESSING);
         gfxlogcontinue(GFX_LOG_RENDERING);
         if(l_lib_if_SP->build_tile != 0)
         {
         #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
            if(l_gen_build_mode_U8 == (UINT8)GFX_MGR02_BUILD_DAR_REDRAW)
            {
               GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
               if(fl_area_SP != 0)
               {
                  hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
               }
               else
               {
                  hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)0);
               }
            }
         #endif
            (void)l_lib_if_SP->build_tile((GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_element_def_SP, &fl_element_def_SP->dim);
                                  }
         gfxlogstop(GFX_LOG_RENDERING);
         gfxlogcontinue(GFX_LOG_PROCESSING);
      }
    #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_MGR02_DAR_OBJECT fl_dar_SP;
            GFX_FLOAT                fl_bound[4];

            fl_bound[0] = (GFX_FLOAT)0;
            fl_bound[1] = (GFX_FLOAT)0;
            fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->dim.width;
            fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->dim.height;
            (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_TILE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);

            fl_dar_SP.elem_SP     = p_elem_SP;
            fl_dar_SP.dirty_area  = p_obj_dirty_U8;
            fl_dar_SP.opeque      = (UINT8)1;
            (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
         }
      }
    #endif
      else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
      {
         if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
         {
            GFX_FLOAT                fl_bound[4];

            fl_bound[0] = (GFX_FLOAT)0;
            fl_bound[1] = (GFX_FLOAT)0;
            fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->dim.width;
            fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->dim.height;
            (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_TILE, (GFX_MGR02_CONTEXT_T const *)fl_context_SP, fl_bound);
            hmi_gfx_mgr02_generic_add_bound(fl_bound);
         }
      }
      else
      {
        /*warning fix*/
      }
   #else
      return;  /* This should never happen */
   #endif /* #if GFX_MGR02_NUM_TILE_INSTANCES > 0 */
   }
   hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
}
#endif /* #if (GFX_MGR02_NUM_OF_TILES > 0) */

#if GFX_MGR02_NUM_OF_FILLS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_generic_build_fill()
Description          : Fills the screen with the given color.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Fill screen stack pointer
******************************************************************************/
static void hmi_gfx_mgr02_generic_build_fill(GFX_MGR02_ELEM_LIST_T const * p_elem_SP, u_gx_flocal p_aligned_widget, u_gx_flocal p_obj_dirty_U8)
{
   UINT32                          fl_obj_id_U32;
   GFX_MGR02_FILL_DEF_T    const * fl_element_def_SP;
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0   
   const GFX_MGR02_FILL_DYN_PROPERTY   * fl_elem_anim_prop_SP;
#endif
   GFX_MGR02_CONTEXT_STATE_T       fl_cur_context_S;
   fl_cur_context_S.loc.x = 0;
   fl_cur_context_S.loc.y = 0;
   hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

   fl_obj_id_U32     = GFX_MGR02_GET_OBJ_ID(p_elem_SP->obj_id);
   if(p_elem_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS)
   {
      #if defined(GFX_MGR02_DLAYOUT_ENABLED)
        fl_element_def_SP = hmi_gfx_mgr02_get_fill_layer_def_ptr(p_elem_SP->base_id);
      #else  
        fl_element_def_SP = &lc_fill_layer_def_S[p_elem_SP->base_id];
      #endif

        /* Check the image is animable or non-animable */
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_SP->obj_id))
       {
       #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
          if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
          {
              GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
              fl_elem_anim_prop_SP = &l_anim_prop_SP->fill_prop[fl_obj_id_U32];
              if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
              {
                  const GFX_MGR02_ILOC_DATA *fl_coord_const_p= &fl_elem_anim_prop_SP->coord;
                  hmi_gfx_mgr02_context_set_loc(fl_coord_const_p);
                  if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                  {
                      fl_cur_context_S.loc.x += fl_elem_anim_prop_SP->coord.x;
                  }
              }
              else
              {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = (SINT16)0;
                  fl_aligned_loc.y = fl_elem_anim_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
              }
              hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_anim_prop_SP->alpha);
              hmi_gfx_mgr02_context_set_fg_color(fl_elem_anim_prop_SP->color);
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
            {
              const GFX_MGR02_FLOC_DATA  *fl_elem_pivot_p = &l_anim_prop_SP->fill_ovg_prop[fl_obj_id_U32].pivot;
              hmi_gfx_mgr02_context_set_matrix(l_anim_prop_SP->fill_ovg_prop[fl_obj_id_U32].matrix);
              hmi_gfx_mgr02_context_set_pivot(fl_elem_pivot_p);
            }
            #endif
              if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
              {
                 gfxlogstop(GFX_LOG_PROCESSING);
                 gfxlogcontinue(GFX_LOG_RENDERING);
                 if(l_lib_if_SP->build_fill != GFX_MGR02_NULL_PTR)
                 {
                 #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                    if(l_gen_build_mode_U8 == (UINT8)GFX_MGR02_BUILD_DAR_REDRAW)
                    {
                       const GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                       if(fl_area_SP != GFX_MGR02_NULL_PTR)
                       {
                          GFX_MGR02_IDIM_DATA fl_dim;
                          SINT32              fl_ex = (((SINT32)fl_context_SP->state.loc.x)+((SINT32)fl_elem_anim_prop_SP->dim.width));
                          SINT32              fl_ey = (((SINT32)fl_context_SP->state.loc.y)+((SINT32)fl_elem_anim_prop_SP->dim.height));
                          hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                          if((fl_area_SP->sx == fl_context_SP->state.loc.x) &&
                             (fl_area_SP->sy == fl_context_SP->state.loc.y) &&
                             (fl_area_SP->ex == fl_ex) &&
                             (fl_area_SP->ey == fl_ey))
                          {
                             SINT16 fl_dim_width_temp;
                             SINT16 fl_dim_height_temp;
                             fl_context_SP->state.loc.x = fl_context_SP->state.clip.sx;
                             fl_context_SP->state.loc.y = fl_context_SP->state.clip.sy;
                             fl_dim_width_temp = fl_context_SP->state.clip.ex-fl_context_SP->state.clip.sx;
                             fl_dim.width  = (UINT16)(fl_dim_width_temp);
                             fl_dim_height_temp = fl_context_SP->state.clip.ey-fl_context_SP->state.clip.sy;
                             fl_dim.height = (UINT16)(fl_dim_height_temp); 
                             (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_dim);
                          }
                          else
                          {
                             (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_elem_anim_prop_SP->dim);
                          }
                       }
                       else
                       {
                         GFX_MGR02_UNUSED_PTR(fl_context_SP);  
                       }
                    }
                    else
                 #endif
                    {
                       (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_elem_anim_prop_SP->dim);
                    }
                 } 
                 else
                 {
                    GFX_MGR02_UNUSED_PTR(fl_context_SP);  
                 }
                 gfxlogstop(GFX_LOG_RENDERING);
                 gfxlogcontinue(GFX_LOG_PROCESSING);
              }
            #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
              else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
              {
                 if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
                 {
                    GFX_MGR02_DAR_OBJECT fl_dar_SP;
                    GFX_FLOAT                fl_bound[4];

                    fl_bound[0] = (GFX_FLOAT)0;
                    fl_bound[1] = (GFX_FLOAT)0;
                    fl_bound[2] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.width;
                    fl_bound[3] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.height;
                    (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_FILL, (GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_bound);

                    fl_dar_SP.elem_SP    = p_elem_SP;
                    fl_dar_SP.dirty_area = (UINT8)p_obj_dirty_U8;
                    fl_dar_SP.opeque     = (UINT8)1;
                    (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
                 }
              }
            #endif
              else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
              {
                 if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
                 {
                    GFX_FLOAT                fl_bound[4];

                    fl_bound[0] = (GFX_FLOAT)0;
                    fl_bound[1] = (GFX_FLOAT)0;
                    fl_bound[2] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.width;
                    fl_bound[3] = (GFX_FLOAT)fl_elem_anim_prop_SP->dim.height;
                    (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_FILL, (GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_bound);
                    hmi_gfx_mgr02_generic_add_bound(fl_bound);
                 }
                 else
                 {
                    GFX_MGR02_UNUSED_PTR(fl_context_SP);  
                 }
              }
              else
              {
                 GFX_MGR02_UNUSED_PTR(fl_context_SP);
              }
              hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
              GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
          }
       #endif /* #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0 */
       }
       else
       {
       #if GFX_MGR02_NUM_FILL_INSTANCES > 0
          if(fl_obj_id_U32 < (UINT32)GFX_MGR02_NUM_FILL_INSTANCES)
          {
              GFX_MGR02_FILL_PROPERTY const * fl_elem_prop_SP;
              GFX_MGR02_CONTEXT_T * fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
              #if defined(GFX_MGR02_DLAYOUT_ENABLED)
               fl_elem_prop_SP = hmi_gfx_mgr02_get_fill_const_prop_ptr(fl_obj_id_U32);
              #else
               fl_elem_prop_SP = &lc_fill_const_property_S[fl_obj_id_U32];
              #endif
              if((p_aligned_widget == (u_gx_flocal)GFX_MGR02_GENERIC_BUILD) || (p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT))
              {
                  hmi_gfx_mgr02_context_set_loc(&fl_elem_prop_SP->coord);
                  if(p_aligned_widget == (u_gx_flocal)GFX_MGR02_ALIGNED_WIDGET_INIT)
                  {
                      fl_cur_context_S.loc.x += fl_elem_prop_SP->coord.x;
                  }
              }
              else
              {
                  GFX_MGR02_ILOC_DATA fl_aligned_loc;
                  fl_aligned_loc.x = (SINT16)0;
                  fl_aligned_loc.y = fl_elem_prop_SP->coord.y;
                  hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_aligned_loc);
              }
              hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_elem_prop_SP->alpha);
              hmi_gfx_mgr02_context_set_fg_color(fl_element_def_SP->color);
            #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
              hmi_gfx_mgr02_context_set_matrix(fl_elem_prop_SP->matrix);
              hmi_gfx_mgr02_context_set_pivot(&fl_elem_prop_SP->pivot);
            #endif
              if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_NORMAL) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW))
              {
                 gfxlogstop(GFX_LOG_PROCESSING);
                 gfxlogcontinue(GFX_LOG_RENDERING);
                 if(l_lib_if_SP->build_fill != (void *)0)
                 {
                 #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
                    if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_REDRAW)
                    {
                       const GFX_MGR02_VISIBLE_AREA * fl_area_SP = hmi_gfx_mgr02_dar_get_object_area(p_elem_SP);
                       if(fl_area_SP != GFX_MGR02_NULL_PTR)
                       {
                          GFX_MGR02_IDIM_DATA fl_dim;
                          SINT32              fl_ex = (SINT32)fl_context_SP->state.loc.x + (SINT32)fl_element_def_SP->dim.width;
                          SINT32              fl_ey = (SINT32)fl_context_SP->state.loc.y + (SINT32)fl_element_def_SP->dim.height;
                          hmi_gfx_mgr02_context_set_clip_va(fl_area_SP);
                          if((fl_area_SP->sx == fl_context_SP->state.loc.x) &&
                             (fl_area_SP->sy == fl_context_SP->state.loc.y) &&
                             (fl_area_SP->ex == fl_ex) &&
                             (fl_area_SP->ey == fl_ey))
                          {
                             SINT16 fl_dim_width_temp;
                             SINT16 fl_dim_height_temp;
                             fl_context_SP->state.loc.x = fl_context_SP->state.clip.sx;
                             fl_context_SP->state.loc.y = fl_context_SP->state.clip.sy;
                             fl_dim_width_temp = fl_context_SP->state.clip.ex-fl_context_SP->state.clip.sx;
                             fl_dim.width  = (UINT16)(fl_dim_width_temp);
                             fl_dim_height_temp = fl_context_SP->state.clip.ey-fl_context_SP->state.clip.sy;
                             fl_dim.height = (UINT16)(fl_dim_height_temp);
                             (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_dim);
                          }
                          else
                          {
                             (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_element_def_SP->dim);
                          }
                       }
                    }
                    else
                 #endif
                    {
                       (void)l_lib_if_SP->build_fill((GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_element_def_SP, (GFX_MGR02_IDIM_DATA const *)&fl_element_def_SP->dim);
                    }
                 }
                 gfxlogstop(GFX_LOG_RENDERING);
                 gfxlogcontinue(GFX_LOG_PROCESSING);
              }
            #ifdef GFX_MGR02_DIRTY_REGION_REDRAW
              else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS)
              {
                 if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
                 {
                    GFX_MGR02_DAR_OBJECT fl_dar_SP;
                    GFX_FLOAT                fl_bound[4];

                    fl_bound[0] = (GFX_FLOAT)0;
                    fl_bound[1] = (GFX_FLOAT)0;
                    fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->dim.width;
                    fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->dim.height;
                    (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_FILL, (GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_bound);

                    fl_dar_SP.elem_SP     = p_elem_SP;
                    fl_dar_SP.dirty_area  = (UINT8)p_obj_dirty_U8;
                    fl_dar_SP.opeque      = (UINT8)1;
                    (void)hmi_gfx_mgr02_dar_add(&fl_dar_SP, fl_bound);
                 }
              }
            #endif
              else if(l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND)
              {
                 if(l_lib_if_SP->get_bound != GFX_MGR02_NULL_PTR)
                 {
                    GFX_FLOAT                fl_bound[4];

                    fl_bound[0] = (GFX_FLOAT)0;
                    fl_bound[1] = (GFX_FLOAT)0;
                    fl_bound[2] = (GFX_FLOAT)fl_element_def_SP->dim.width;
                    fl_bound[3] = (GFX_FLOAT)fl_element_def_SP->dim.height;
                    (void)l_lib_if_SP->get_bound(GFX_MGR02_TYPE_FILL, (GFX_MGR02_CONTEXT_T  const *)fl_context_SP, fl_bound);
                    hmi_gfx_mgr02_generic_add_bound(fl_bound);
                 }
              }
              else
              { 
                 /* To Fix Misra Warning C-2012 Rule 15.7 */
              }
              hmi_gfx_mgr02_context_state_set((GFX_MGR02_CONTEXT_STATE_T const *)&fl_cur_context_S);
              GFX_MGR02_UNUSED_VAR(p_obj_dirty_U8);
          }
       #endif /* #if GFX_MGR02_NUM_FILL_INSTANCES > 0 */
       }
   }
}
#endif /* #if GFX_MGR02_NUM_OF_FILLS > 0 */

#ifdef  __cplusplus
}
#endif

#endif 
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
 ** CMS Rev #        Date            By
 ** CMS Rev X.X      dd-mmm-yyyy     CDSID
 **
 **============================================================================'
 ** CMS Rev 1.79      27-Feb-2020    ssigaman
 ** 1415553: [HBC]: Blank screen is shown in Normal mode
 ** p_build->render_buffer is updated with front buffer of a widget if number of dirty rectangle is zero.
 **
 ** CMS Rev 1.78      03-Feb-2020    ARAJASE2
 ** 1408882: [MKTA & MKJH] - Upgradation in GDT tool to reduce the line - 
 ** spacing in case of Multi line text (709586)
 **
 ** CMS Rev 1.77      06-Nov-2019     KKUBENDI
 ** 1369434: Multi line Text Font alignment issue
 ** 
 ** CMS Rev 1.76      31-Aug-2018     ADEVI
 ** 1149379: Capture Video Driver for KeplerII
 **
 ** CMS Rev 1.75     14-Mar-2018    ARAJASE2
 ** 1073800: hmi_gfx_mgr02_run_multiline_algorithm returns wrong data
 ** Fixed issue with frame expand animation. Actual issue when we change the number of displayed
 ** lines from 1 to 2, while evaluating the previous algorithm output, it will give the line index
 ** as zero since there is no data available for the first line as algorithm will not be called.
 ** But multi line data pointer got incremented without any validation which results in empty data
 ** in the first line and actual output starts store from the second lines onwards
 **
 ** CMS Rev 1.74     15-Feb-2018    ARAJASE2
 ** 1035493: GM-CHUD : Fetching the MULTI_LINE_INFO for text with lines > 255
 **
 ** CMS Rev 1.73     10/01/18    ADEVI
 ** 1004848 : Clip information fectched from application and Append string located based on app input.
 **
 ** CMS Rev 1.72     30-Nov-2017    ARAJASE2
 ** 1005357: Graphics Manager update for Hebrew Text rendering
 ** Enabled existing arabic related code for GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED macro also.
 ** Renamed the following functions since it supports both arabic and Hebrew(RTL - Right to Left)
 ** hmi_gfx_mgr02_arabic_multiline_algorithm --> hmi_gfx_mgr02_RTL_multiline_algorithm
 ** hmi_gfx_mgr02_run_arabic_multiline_algorithm --> hmi_gfx_mgr02_run_RTL_multiline_algorithm
 **
 ** CMS Rev 1.71     23-Nov-2017    ARAJASE2
 ** 994906: P552 L1, L2 - OpenVG rendering texts are not displayed (Core Migration).
 ** Usage of GFX_MGR02_VG_CACHE_ENABLED macro is replaced with new macros
 ** GFX_MGR02_VG_IMG_CACHE_ENABLED and GFX_MGR02_VG_TXT_CACHE_ENABLED
 **
 ** CMS Rev 1.70     02-Nov-2017    KKUBENDI
 ** RTC 985440: Display is not properly there. When warning review page displayed.
 **
 ** CMS Rev 1.69     13-Oct-2017    ARAJASE2
 ** RTC 973039: GMC - GDT (904756) : Carriage return is displayed incorrectly in open source page
 **
 ** CMS Rev 1.68     19-Sep-2017    KKUBENDI
 ** RTC 939889: Mazda J59: Kepler2- Graphics building in HRAM and transfer to VRAM to display
 **
 ** CMS Rev 1.67     18-Sep-2017    ADEVI
 ** 955614: Multi-line Scroll Optimization And Max lines increased.
 ** 
 ** CMS Rev 1.66     18-Sep-2017    ARAJASE2
 ** 921462: Dynamic Font update issue in Amber platform with External font
 **
 ** CMS Rev 1.65     18-Sep-2017    SBOLLAM
 ** RTC 955706:
 ** Need a support to align the elements in the aligned widget
 ** based on elements x position.
 **
 ** CMS Rev 1.64     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.64     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 1.63      08-Aug-2017    ARAJASE2
 ** hmi_gfx_mgr02_build_multiline_text funtion prototype changed to accept inter_line_spacing as 
 ** new parameter to support dynamic update of inter line spacing
 ** 922409: Dynamic Inter-line spacing for multi-line text
 **
 ** CMS Rev 1.62     06-JUL-2017    ADEVI
 ** RTC ID: 871825:  Changes to support MONOTFT Platform
 **
 ** CMS Rev 1.61     5-May-2017    ADEVI
 ** 847451: GM-CHUD- Multi line changes
 **
 ** CMS Rev 1.60     04-May-2017    SSIGAMAN
 ** 748281: Amber:The fill within the clip widget not get rendering when DirtyArea is enabled.
 ** Fix   : In build image function, images are treated as opeque irrespective of its type.
 **         This is corrected.
 **
 ** CMS Rev 1.59     18-Apr-2017    SSRINI19
 ** 846153: GM-CHUD- QAC warning fixes
 **
 ** CMS Rev 1.58     12-Apr-2017    ADEVI
 ** 829051: Amber:Multi line feature integration
 **
 ** CMS Rev 1.57      11-Apr-2017    ADEVI
 ** 817465, 810103: B515 - Issue in processed right aligned multi line data
 **
 ** CMS Rev 1.56      09-Jan-2017    SSIGAMAN
 ** 778496: Amber:Compilation Errors based on elements added in the GDT design.
 ** Conditional Compilation macros added.
 **
 ** CMS Rev 1.55      31-Jan-2017    VGAJJI
 ** 793418: B515 - Coverity Warnings Fix
 **
 ** CMS Rev 1.54      27-Dec-2016    VGAJJI
 ** 756979: B515 - compiler Warnings Fix
 **
 ** CMS Rev 1.53      19-Dec-2016    VGAJJI
 ** 756975: B515 - Coverity Warnings Fix
 **
 ** CMS Rev 1.52      16-Dec-2016    ADEVI
 ** 767484: In multi line build break statement was missing when the pointer is null.
 **
 ** CMS Rev 1.51      16-DEC-2016    EMANOJ1
 ** Faraday Future - Touch object auto selection does not work (RTC : 767349)
 ** hmi_gfx_mgr02_context_begin_update() function was finding and locking the next
 ** available framebuffer. But when the dirty area initial processing is done, it was
 ** resulting in unnecessarily locking the framebuffer, causing the updates to be not
 ** happening. So a parameter is added to begin update to specify whether a lock is needed
 ** or not. 
 **
 ** CMS Rev 1.50      02-NOV-2016    APERUMAL
 ** 735553: Porsche Misra warning fixes 
 **
 ** CMS Rev 1.49      24-Oct-2016    CSAKTHIV
 ** 730317: Memory Leak issue in W207. 
 **
 ** CMS Rev 1.49      15-Sep-2016    ADEVI
 ** 656058: print_sindex variable used for arabic hard cut was cleared.
 **
 ** CMS Rev 1.48      09-Sep-2016    ADEVI
 ** 679272: Aligned widget implementation done for right aligned text elements
 **
 ** CMS Rev 1.47      26-Aug-2016    ADEVI
 ** 656058: Arabic hard cut multi line requirements implementaion
 **
 ** CMS Rev 1.46      25-Aug-2016    SANAND2
 ** 679532: QAC warnings fix for Arabic multi line implementaion - Part II
 **
 ** CMS Rev 1.45      28-Jul-2016    CMUTHUSA
 ** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
 **
 ** CMS Rev 1.44     28-JULY-2016    SANAND2
 ** 641381: Arabic multi line changes PR defect fix.
 **
 ** CMS Rev 1.43     27-JULY-2016    SANAND2
 ** 641381: Arabic multi line changes.
 **
 ** CMS Rev 1.42     22-July-2016    ADEVI
 ** 623405: Arabic multi line algorithm changes.
 **
 ** CMS Rev 1.41     22-July-2016    ADEVI
 ** 610788: Multi - line data saved and new line requirement changes.
 **
 ** CMS Rev 1.40     18-JULY-2016    ADEVI
 ** 606579: New line issue fix in multi line

 ** CMS Rev 1.39     08-JULY-2016    SSIGAMAN
 ** 639042: Porsche Misra warning Fix
 **
 ** CMS Rev 1.38     20-June-2016    ADEVI
 ** 622529: New line requirement in multi line and \n character ignored while rendering.
 **
 ** CMS Rev 1.37     03-June-2016    SSIGAMAN
 ** 611785: Compiler Warnings Fix in Turing.
 **
 ** CMS Rev 1.36     11-May-2016    SSIGAMAN
 ** 592820: Turing Coverity Warning Fix for ui.core.gdt
 **
 ** CMS Rev 1.35     4-May-2016    SSIGAMAN
 ** RTC 571865: 
 ** The structure member da_redraw in GFX_MGR02_CONTEXT_GB_T is removed
 ** as per PR comments.
 **
 ** CMS Rev 1.34     28-Apr-2016    ADEVI      RTC 546876,578262,543902
 ** Add support to change the Text Size Dynamically
 ** Add support for The dynamic change of text alignment property 
 ** Requirement for dynamic change of the text box size
 **
 ** CMS Rev 1.33     07-Apr-2016    ADEVI      RTC 523096
 ** Issue in B515 regarding interelement spacing when invalid dimage is selected.
 **
 ** CMS Rev 1.32     24-Mar-2016    SVIKRAM      RTC 521380
 ** Coverity issue fix
 ** CMS Rev 1.31     17-Mar-2016    SSIGAMAN
 ** 549069:
 ** Changes are done in hmi_gfx_mgr02_generic_build_dcu_gen_widget()
 ** to resolve dirty area related issues for Amber, 
 ** avoided rendering in number of dirty area is 0.
 **
 ** CMS Rev 1.30     01-Mar-2016    APERUMAL      RTC 533975
 ** Compiler error fix for B515 when Dirty Region Redraw is enabled
 **
 ** CMS Rev 1.29     15-Feb-2016    ADEVI         RTC 494789
 ** Multi line text Implementation - NEW FORD requirements.
 **
 ** CMS Rev 1.28     5-Feb-2015    APERUMAL
 ** RTC 512949:
 ** Compiler warnings fix for B515
 **
 ** CMS Rev 1.27     29-Jan-2015    APERUMAL
 ** RTC 507885:
 ** QAC warnings fix for Honda Thaa
 **
 ** CMS Rev 1.26     3-Nov-2015    SSIGAMAN
 ** RTC 456457:
 ** Dirty Area Redraw is applicable for merge widgets with CLIP=TRUE. 
 ** So, da_redraw is used to use or skip the dirty area feature for widgets.
 **
 ** CMS Rev 1.25     3-Nov-2015    SSIGAMAN
 ** RTC 456457:
 ** Updated the Module to adapt the Dirty Area Feature for Amber platform.
 **
 ** CMS Rev 1.24     28-Oct-2015    ADEVI         RTC 412568
 ** Multi line text Implementation - Initial Version.
 **
 ** CMS Rev 1.31     27-Oct-2015   SSIGAMAN
 ** Ref RTC# 443671
 ** Changes to support XY animation for merge widget of Amber platform .
 ** 
 ** CMS Rev 1.30     08-Oct-2015    APERUMAL         RTC 438709
 ** Coverity warning fix for Honda Thaa. CID 12399.
 **
 ** CMS Rev 1.29     01-Oct-2015    APERUMAL         RTC 434948
 ** Compiler warning fix for Porsche
 **
 ** CMS Rev 1.28     21-Sep-2015    CSAKTHIV         RTC 400575
 ** Binary search for texture.
 **
 ** CMS Rev 1.27     15-Sep-2015   SSIGAMAN
 ** Ref RTC# 370662.
 ** Changes are done to make Alpha and Path Buffer of the Draw engine as configurable item.
 **
 ** CMS Rev 1.26     31-Aug-2015    APERUMAL         RTC 409066
 ** Changes done for QA C warning fix in Honda Thaa
 **
 ** CMS Rev 1.25     23-July-2015    ARAJASE2         RTC 380645
 ** Changes done for compiler warning fix in W207.
 **
 ** CMS Rev 1.24     07-July-2015   SSIGAMAN       RTC 370556
 ** Changes done for adding the draw engine features of Spansion target. 
 **
 ** CMS Rev 1.23     25-May-2015    ADEVI            RTC 323189
 ** Changes done for iris pixel poking feature GFX_MGR02_IRIS_PIXEL_POKING. 
 **
 ** CMS Rev 1.22     6-Apr-2015    ADEVI
 ** In hmi_gfx_mgr02_generic_build_widget function GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS
 ** check introduced to fix the high impact MFD coverity issues. 
 **
 ** CMS Rev 1.21     02-Apr-2015   EMANOJ1
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
 ** CMS Rev 1.20     16-Oct-2014    SSIGAMAN
 ** Spansion Iris engine Amber-I changes for Kepler2.
 ** 
 ** CMS Rev 1.19     01-Sep-2014    EMANOJ1
 ** Updated hmi_gfx_mgr02_generic_build_uimage to fix review comments
 **
 ** CMS Rev 1.18     20-Aug-2014    EMANOJ1
 ** RTC task#197302
 ** hmi_gfx_mgr02_generic_build_uimage updated to detect the width/height
 ** change and then set p_obj_dirty_U8=TRUE if there is a change. Done to
 ** make sure to rebuild the changed area incase the user image has changed
 ** its width/height.
 ** Added a return value for hmi_gfx_mgr02_load_user_layer_def_info to
 ** enable application to state whether the user image has changed or not
 ** By returning TRUE, the user image is changed and the graphics manager will
 ** rebuild it.
 **
 ** CMS Rev 1.17     18-Aug-2014    EMANOJ1
 ** hmi_gfx_mgr02_generic_build_uimage updated to set the dirt flag if the 
 ** GFX_MGR02_IMAGE_DEF_T returned by hmi_gfx_mgr02_load_user_layer_def_info is
 ** different than what is already maintained by graphics manager to fix issue
 ** with dirty area redraw, when application returns a smaller image at run
 ** time than what was returned earlier.
 **
 ** CMS Rev 1.17     31-Jul-2014    EMANOJ1
 ** hmi_gfx_mgr02_generic_build_dimage did not checked whether the selected image
 ** is dirty. It was causing issues with dirty area update. Updated build_dimage
 ** to detect element change status for selected element and pass it on to the 
 ** hmi_gfx_mgr02_generic_build_image() to fix this issue.
 **
 ** CMS Rev 1.16     25-Jul-2014    EMANOJ1
 ** hmi_gfx_mgr02_generic_build_widget updated to set the p_obj_dirty_U8 flag
 ** when it is making a recursive call. This was causing issue with incorrect
 ** dirty area redraw behaviour
 **
 ** CMS Rev 1.15     25-Nov-2013    CMUTHUSA
 ** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
 **
 ** CMS Rev 1.14     20-Feb-2014    EMANOJ1
 ** RTC 121262 related changes - 
 ** Updated to make hmi_gfx_mgr02_generic_get_element_bound() available by
 ** default to fix a touch screen event handling issue. All the build functions
 ** updated to remove kepler conditional compilation
 **
 ** CMS Rev 1.13     28-Jan-2014    EMANOJ1
 ** Updated to support user image type to load image from a RAM buffer even in the
 ** case of GFX_MGR02_USE_FILESYSTEM defined (RTC Task 116960).
 **
 ** CMS Rev 1.12     20-Nov-2013    EMANOJ1/SBOLLAM
 ** hmi_gfx_mgr02_generic_build_text updated to fix a 1pixel clipping noticed
 ** for right aligned text. The DAR area calculation did not consider subtracting
 ** 1 from the width to make it co-ordinate value in the 
 ** else if((l_gen_build_mode_U8 == GFX_MGR02_BUILD_DAR_PROCESS) || (l_gen_build_mode_U8 == GFX_MGR02_BUILD_FIND_BOUND))
 ** loop
 **
 ** CMS Rev 1.12     20-Nov-2013    EMANOJ1/SBOLLAM
 ** Bugzilla : [Bug 38] All widget elements are not building when it is aligned
 ** hmi_gfx_mgr02_generic_build_aligned_widget() updated to consider inter elem 
 *  space and a copy paste error fixed.
 **
 ** CMS Rev 1.11     22-Oct-2013    EMANOJ1
 ** hmi_gfx_mgr02_generic_build_widget updated to fix an issue w.r.t update
 ** of aligned widget when there is a change to one of its element. In this 
 ** case the object were redrawn only considering area of the object which has
 ** a chnage. But the change might have caused other elements to change its
 ** position to achive the alignment and this is not considered as a dirty
 ** area and therefore creates some partial update causing an issue. Now this
 ** function is modified to consider the entire widget as dirty incase of any
 **
 ** CMS Rev 1.10     26-Aug-2013    EMANOJ1
 ** Updated to support finding bound of a widget. This is added to support the 
 ** dynamic buffer allocation for the OpenVG widgets (clip=false) in DCU
 ** targets. Also added a buffer clearing library callback support
 **
 ** CMS Rev 1.9      19-Aug-2013    EMANOJ1
 ** Added a target parameter for text width calculation and printing as the 
 ** text.c has been updated to utilize this parameter.
 **
 ** CMS Rev 1.8      20-Jun-2013    EMANOJ1
 ** Updated to add element opeque status bit to support element visibility
 ** check by DAR to speed up rendering by removal of invisible elements from 
 ** rendering.
 **
 ** CMS Rev 1.7      12-Jun-2013    EMANOJ1
 ** right2left handling added with the help of GFX_MGR02_GALIGNMENT()
 ** Add code to handle the case of dynamic modification of text alignment
 **
 ** CMS Rev 1.6      28-May-2013    EMANOJ1
 ** Fixed issue in accessing text layer def in hmi_gfx_mgr02_get_element_widthinfo
 ** hmi_gfx_mgr02_generic_build_svg updated take in to account for the start XY offset
 ** for the svg object bound in its active area calculation for dirty area redraw.
 ** This was done to fix an issue of svg images right bottom corner getting clipped
 ** issue.
 **
 ** CMS Rev 1.5      15-May-2013    EMANOJ1
 ** Updated to add support for dirty region redraw.
 ** Updated add support for user type image for OpenVG and Software
 **
 ** CMS Rev 1.4      03-Apr-2013    ASHEKHAR
 ** QAC Warning Fixes.
 **
 ** CMS Rev 1.3      22-Mar-2013    VMUTHUSU
 ** Change NULL_PTR to GFX_MGR02_NULL_PTR
 **
 ** CMS Rev 1.2      20-Mar-2013    EMANOJ1
 ** Widget clipping issue fixed by allowing clipping only if it is enabled for
 ** a widget.
 **
 ** CMS Rev 1.1      15-Mar-2013    ASHEKHAR/EMANOJ1
 ** Updated compiler switches to make it work for different combinations
 ** Resolved an issue with svg image not getting built if it was part of a 
 ** dynamic image. Splitted dynamic image handling to new function
 ** hmi_gfx_mgr02_generic_build_dimage from hmi_gfx_mgr02_generic_build_image
 ** Added support for SVG image clipping
 ** Added support for aligned widgets.
 **
 ** CMS Rev 1.0      10-OCT-2012     YSREEMAN
 ** Creation.
 ** This file is added to write the interfaces and logic required to build the 
 ** software platform screens.
**==========================================================================*/


/* end of file =============================================================*/
