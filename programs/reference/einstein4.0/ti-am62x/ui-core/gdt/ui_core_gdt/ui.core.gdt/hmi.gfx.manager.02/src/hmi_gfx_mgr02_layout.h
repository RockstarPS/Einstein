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
** Name:           hmi_gfx_mgr02_layout.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_LAYOUT_H
#define HMI_GFX_MGR02_LAYOUT_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_language_interface.h"
#if defined(LNG_UNICODE) && !defined(WIN32)
   #include "wchar.h"
#endif
#include "hmi_gfx_mgr02.cfg"
#include "hmi_gfx_mgr02_cfg.h"
#include "hmi_gfx_mgr02_types.h"
#include "hmi_gfx_mgr02_font.h"
#include "hmi_gfx_anim_engine_cfg.h"

#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
#if (defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED))
#include "hmi_gfx_mgr02_warp_tables.cfg"
#endif
#endif

#if defined(GFX_MGR02_OPEN_VG)
#include "hmi_gfx_mgr02_fault.h"
#endif

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #if GFX_NUM_ANIMATIONS > 0
   #include "hmi_gfx_anim_engine.h"
  #endif 
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
#endif

#if !defined(LNG_UNICODE) && (GFX_MGR02_UNICODE != 0)
#error "Widechar is used in GDT tool but disabled in language tool"
#endif

#if defined(LNG_UNICODE) && (GFX_MGR02_UNICODE != 1)
#error "Widechar is used in language tool but disabled in GDT tool"
#endif

#if (defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)) && !defined(GFX_MGR02_DIRTY_REGION_REDRAW)
#error "Dirty Region Redraw should be enbaled for IMXRT platform"
#endif
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#define GFX_MGR02_VIDEO_CAPTURE_NOT_DONE           (0x00U)
#define GFX_MGR02_VIDEO_CAPTURE_DONE               (0x01U)
#define GFX_MGR02_SHUT_DOWN_VIDEO_UNIT             (0xFFU)
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
typedef enum
{
    GUI_GFX_MGR_NO_ERROR                = 0,
    GUI_GFX_MGR_INVALID_SCR_ELEM_ID     = 0x1001,
    GUI_GFX_MGR_INVALID_DTEXT_ELEM_ID   = 0x1002,
    GUI_GFX_MGR_INVALID_DWDG_ELEM_ID    = 0x1003,
    GUI_GFX_MGR_INVALID_ANIM_ELEM_ID    = 0x1004,
    GUI_GFX_MGR_INVALID_DIMG_ELEM_ID    = 0x1005,
    GUI_GFX_MGR_INVALID_OBJ_TYPE        = 0x1006,
    GUI_GFX_MGR_INVALID_ATTRIB          = 0x1007,
    GUI_GFX_MGR_INVALID_TARGET          = 0x1008,     
    GUI_GFX_MGR_INVALID_PRIORITY        = 0x1009,
    GUI_GFX_MGR_INVALID_DLAYOUT         = 0x100A,
    GUI_GFX_MGR_BAD_HANDLE_ERROR        = 0x10FF
}GUI_GFX_MGR_ERROR_CODE_T;

#ifndef GFX_MGR02_UNUSED_VAR
#define GFX_MGR02_UNUSED_VAR(X)  (void)(X)
#endif
#ifndef GFX_MGR02_UNUSED_PTR
#define GFX_MGR02_UNUSED_PTR(X)  (void)(X)
#endif


#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS) ||defined (GFX_MGR02_TRAVEO2)
    #define IRIS_API_CHECK(rc, execute)                 \
                            {                           \
                                (rc)= (execute);        \
                                if( MML_OK != (rc))     \
                                {                       \
                                }                       \
                            }
#endif

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
typedef struct
{
  GFX_UINT num_of_display_lines : 14;
  GFX_UINT is_data_available    : 1;
}GFX_MGR02_MULTI_LINE_INFO;

typedef struct
{
  GFX_UINT string_length:14;
  GFX_UINT is_arabic_hard_cut:1;
  GFX_UINT is_char_hard_cut:1;
}GFX_MGR02_INT_MULTI_LINE_DATA;

typedef struct
{
  UINT16 start_pos;
  union
  {
    UINT16 strlength;
    GFX_MGR02_INT_MULTI_LINE_DATA int_multi_line_data;
  }parameter;
}GFX_MGR02_MULTI_LINE_DATA;

typedef struct
{
  u_gx_flocal  alignment;
  u_gx_flocal  clip_mode;
  u_gx_flocal  font_id;
  u_gx_flocal  num_of_display_lines;
  u_gx_flocal  scroll_offset;
  u_gx_flocal  text_width;
  BOOLEAN      evaluale_and_run;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
  UINT8        font_pt_size;
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
	UINT8      complex_script_flag;
#endif
}GFX_MGR02_MULTI_LINE_DEPENDENT_PARAM;

#define GFX_MGR02_MULTI_IS_DATA_AVBL(data)              (((data) & 0x8000U) >> 15U)
#define GFX_MGR02_MULTI_IS_DATA_MODIFIED(data)          (((data) & 0x4000U) >> 14U)
#define GFX_MGR02_MULTI_SET_DATA_AVBL(data, buffer)     ((buffer) |= (UINT16)((UINT32)(data) << 15U))
#define GFX_MGR02_MULTI_SET_DATA_MODIFIED(data, buffer) ((buffer) |= (UINT16)((UINT32)(data) << 14U))
#define GFX_MGR02_MULTI_NUM_OF_LINES(data)              ((data) & 0x3FFFU)

#define GFX_MGR02_MULTI_LINE_ARRAY_SIZE      ((u_gx_flocal)GFX_MGR02_MAX_LINES_OF_MULTI_LINE_TEXTS << 1U)
#define GFX_MGR02_MULTI_BYTES_OF_DATA_PER_LINE  2U

#ifdef LNG_UNICODE
#define GFX_MGR02_MULTI_INC_STRING_INDEX(index)  ((index) += 1UL)
#else
#define GFX_MGR02_MULTI_INC_STRING_INDEX(index)  ((index) += 2UL)
#endif

#endif
#ifdef GFX_MGR02_CHECKSUM_ENABLED
 #define GFX_MGR02_CHECKSUM_FAILED    (0u)
 #define GFX_MGR02_CHECKSUM_MATCHED   (1u)
#endif

#ifdef HMI_GFX_MGR02_PRIV_C
typedef struct
{
   SINT16 sx;
   SINT16 sy;
   SINT16 ex;
   SINT16 ey;
   UINT8  is_transparent;
   UINT8  alpha;
}GFX_MGR02_ELEMENT_AREA;

#define GFX_MGR02_GLES_11 (11)
#define GFX_MGR02_GLES_20 (20)
#ifndef GFX_MGR02_GLES_VERSION
 #define GFX_MGR02_GLES_VERSION (GFX_MGR02_GLES_20)
#endif


/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
GFX_MGR02_ANIM_DATA_T * hmi_gfx_mgr02_layout_get_anim_data(void);
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
GFX_MGR02_ELEM_LIST_T const * hmi_gfx_mgr02_layout_get_selected_swidget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
UINT32 hmi_gfx_mgr02_layout_get_dwidget_selection(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif
#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
GFX_MGR02_ELEM_LIST_T const * hmi_gfx_mgr02_layout_get_selected_simage(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif
UINT32 hmi_gfx_mgr02_layout_is_element_changed(UINT32 p_base_id, UINT32 p_obj_id);
UINT32 hmi_gfx_mgr02_layout_is_element_childrens_changed(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, BOOLEAN p_parent);
void hmi_gfx_mgr02_layout_validate_layer_area(GFX_MGR02_ELEMENT_AREA  * p_elem_area,
                                              UINT32                    p_vaof_index,
                                              BOOLEAN                    p_total_area,
                                              UINT32                    p_layer_index);
#endif /* #ifdef HMI_GFX_MGR02_PRIV_C */

#ifdef GFX_MGR02_CHECKSUM_ENABLED
UINT8 hmi_gfx_mgr02_layout_initialize(void);
#else
void hmi_gfx_mgr02_layout_initialize(void);
#endif
void hmi_gfx_mgr02_layout_shutdown(void);
void hmi_gfx_mgr02_layout_startup(void);
void hmi_gfx_mgr02_layout_emergency_shutdown(void);
void hmi_gfx_mgr02_layout_build_screen(void);
#if defined(GFX_OVG_FAULT_HANDLE) && defined(GFX_MGR02_OPEN_VG)
void hmi_gfx_mgr02_layout_ctx_init(void);
#endif
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_screen(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_screen_dyn_priority(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show,UINT8 priority);
#if GFX_MGR02_NUM_OF_DTEXTS > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string);
#ifndef GFX_MGR02_SHAPE_ENGINE_ENABLED
void hmi_gfx_mgr02_layout_default_text_shape(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string, HMI_CHAR * p_dest_string, 
                                             UINT8 p_compare, UINT16 p_num_chars
                                        #if defined(HMI_LANG_PRE_RENDER_ENABLED)
                                            , UINT8 p_process_bidi
                                        #endif
                                            );
#endif
#if HM_LANG_MAX_SID > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid);
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
UINT32 hmi_gfx_mgr02_layout_get_prerender_index(UINT16 p_elem_id);
#endif

#endif
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_width(GFX_MGR02_DTEXT_ID          p_elem_id, 
                                                             GFX_MGR02_TEXT_WIDTH_INFO * p_text_info);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_width_ext(GFX_MGR02_DTEXT_ID p_elem_id, 
                                                                 GFX_MGR02_TEXT_WIDTH_INFO * p_text_info,
                                                                 UINT32            p_alignment);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_char_metrics(HMI_CHAR p_char,
                                                               UINT32   p_font_id,
                                                               GFX_MGR02_FONT_CHAR_METRICS * p_metrics);

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string,GFX_MGR02_ANIM_ELEM_ID p_anim_id);
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_inter_line_spacing(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT8 p_inter_line_spacing);
#endif
#if HM_LANG_MAX_SID > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_multi_line_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid,GFX_MGR02_ANIM_ELEM_ID p_anim_id);
#endif
#endif
#endif
#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dwidget(GFX_MGR02_DWDG_ELEM_ID p_elem_id, UINT32 p_index);
#endif
#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dimage(GFX_MGR02_DIMG_ELEM_ID p_elem_id, UINT32 p_index);
#endif
#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_clut(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_clut_id);
#endif
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_alpha(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ALPHA p_alpha);

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) || \
    (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || \
    ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IAREA_DATA const * p_area);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IAREA_DATA * p_area);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA const * p_dim);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA * p_dim);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim_w(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_w);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_dim_h(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_h);
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_vclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_VCLIP_DATA const * p_clip);
 #if !defined(GFX_MGR02_KEPLER)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_hclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_HCLIP_DATA const * p_clip);
 #endif
#endif
#endif /* (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) */

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_draw_color(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_color);
#endif

GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id,GFX_MGR02_ILOC_DATA const * p_pos);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA * p_pos);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_default_properties(GFX_MGR02_ANIM_ELEM_ID p_elem_id);
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pivot_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_pivot_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_mul_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT  const * p_matrix);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_scale(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_scalex, GFX_FLOAT p_scaley);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_obj_rotate(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_angle);
GFX_FLOAT * hmi_gfx_mgr02_layout_get_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id);
GFX_FLOAT const * hmi_gfx_mgr02_layout_get_def_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id);
UINT32 hmi_gfx_mgr02_layout_matrix_copy(GFX_FLOAT * p_dst, GFX_FLOAT const * p_src);
#endif

#if defined(GFX_MGR02_AMBER) ||defined(GFX_MGR02_TRAVEO2)
#if (((GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS >0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0))&&((defined(GFX_MGR02_LAYER_WARPING_ENABLED)) || (defined(GFX_MGR02_WIDGET_WARPING_ENABLED))))	
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_warping_table(GFX_MGR02_ANIM_ELEM_ID p_elem_id, const MML_GDC_WARP_PARAM* p_warp_param, UINT8 * p_warp_data, UINT8 p_force_update);
#endif
#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
UINT32 hmi_gfx_mgr02_layout_get_amber_driver_status(void);
void  hmi_gfx_mgr02_layout_restart_AmberDriver(void);
#endif
void hmi_gfx_mgr02_layout_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32);
#endif

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_layout_push_touch_event(GFX_MGR02_TOUCH_QDATA * p_touch_data_SP, UINT8 p_touch_id);
UINT32 hmi_gfx_mgr02_layout_is_touch_events_pending(UINT8 p_touch_id);
void hmi_gfx_mgr02_layout_freeze_touch_event(GFX_MGR02_SCR_ELEM_ID p_screen_id, UINT8 p_touch_id);
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
UINT32 hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def);
void hmi_gfx_mgr02_render_user_layer(UINT32 p_base_id);
#endif
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
UINT32 hmi_gfx_mgr02_load_mdl_3d_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def);
#endif
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
UINT32 hmi_gfx_mgr02_layout_select_gfont_index(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left);
#endif
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
UINT32 hmi_gfx_mgr02_layout_set_text_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                          UINT32                 p_alignment, 
                                          UINT32                 p_draw_mode,
                                          UINT32                 p_clip_mode);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_scroll_parameter(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                                      UINT16                 p_scroll_offset);
#if (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_font(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_font_id
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))))
, UINT8 p_font_pt_size
#endif
);
#endif /* #ifdef GFX_MGR02_AMBER */
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  BOOLEAN hmi_gfx_mgr02_is_line_break_char(HMI_CHAR p_char_unicode, UINT8 p_is_complex, UINT8 p_is_character, UINT8 p_unique_font_id);
  BOOLEAN hmi_gfx_mgr02_is_printable_char(HMI_CHAR p_char_unicode, UINT8 p_is_complex, UINT8 p_is_character, UINT8 p_unique_font_id);
  void hmi_gfx_mgr02_get_shaping_flags(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, HMI_CHAR const * p_src_str_ptr, u_gx_flocal p_line_start_pos, GFX_MGR02_SHAPE_FLAGS *p_shape_flags);
#else
  BOOLEAN hmi_gfx_mgr02_is_line_break_char(HMI_CHAR p_char_unicode);
  BOOLEAN hmi_gfx_mgr02_is_printable_char(HMI_CHAR p_char_unicode);
#endif
void hmi_gfx_mgr02_get_dyn_text_multiline_data(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP, GFX_MGR02_MULTI_LINE_INFO *p_multi_line, GFX_MGR02_MULTI_LINE_DATA *p_multi_line_array, u_gx_flocal p_scroll);
void hmi_gfx_mgr02_set_dyn_text_multiline_data(GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP, GFX_MGR02_MULTI_LINE_INFO const *p_multi_line, GFX_MGR02_MULTI_LINE_DATA const* p_multi_line_array, BOOLEAN p_updateData);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_get_multiline_info(GFX_MGR02_DTEXT_ID p_elem_id, GFX_MGR02_MULTI_LINE_INFO *p_multi_line_data);
UINT16 hmi_gfx_mgr02_get_total_lines_in_multiline(GFX_MGR02_DTEXT_ID p_elem_id);
void hmi_gfx_mgr02_layout_run_multiline_algorithm(GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, BOOLEAN p_complete, BOOLEAN p_EvalAndRun);
#endif

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
void hmi_gfx_mgr02_layout_process_touch_events(void);
#endif
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_force_set_screen(void);
#endif

#if defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_IMXRT)
BOOLEAN hmi_gfx_mgr02_layout_is_render_done(void);
#endif

#if defined(GFX_MGR02_DLAYOUT_ENABLED)
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_select_dlayout_index(GFX_MGR02_LAYOUT_ID p_selection_index);
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_elem_area_offset_ptr(UINT16 p_clip_idx);
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS>0
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_image_layer_def_ptr(UINT32 p_elem_id);
#endif
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_image_layer_ptr(UINT32 p_prop_idx);
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_image_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_image_const_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
GFX_MGR02_TEXT_DEF_T const* hmi_gfx_mgr02_get_txt_layer_def_ptr(UINT32 p_elem_id);
#endif
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
GFX_MGR02_TEXT_DEF_T const* hmi_gfx_mgr02_get_text_layer_ptr(UINT32 p_prop_idx);
GFX_MGR02_TEXT_PROPERTY const* hmi_gfx_mgr02_get_txt_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_TEXT_INSTANCES > 0
GFX_MGR02_TEXT_PROPERTY const* hmi_gfx_mgr02_get_txt_const_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
GFX_MGR02_FILL_DEF_T const* hmi_gfx_mgr02_get_fill_layer_def_ptr(UINT32 p_elem_id);
#endif
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
GFX_MGR02_FILL_PROPERTY const* hmi_gfx_mgr02_get_fill_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_FILL_INSTANCES > 0
GFX_MGR02_FILL_PROPERTY const* hmi_gfx_mgr02_get_fill_const_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
GFX_MGR02_TILE_DEF_T const* hmi_gfx_mgr02_get_tile_layer_def_ptr(UINT32 p_elem_id);
#endif
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
GFX_MGR02_TILE_PROPERTY const* hmi_gfx_mgr02_get_tile_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_TILE_INSTANCES > 0
GFX_MGR02_TILE_PROPERTY const* hmi_gfx_mgr02_get_tile_const_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_OF_SVGS > 0
GFX_MGR02_OVG_OBJECT_T const* hmi_gfx_mgr02_get_svg_layer_def_ptr(UINT32 p_elem_id);
UINT16 hmi_gfx_mgr02_get_svg_clip_idx(UINT32 p_prop_idx);
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_svg_elem_area_offset_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
GFX_MGR02_OVG_PROPERTY const* hmi_gfx_mgr02_get_svg_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_SVG_INSTANCES > 0
GFX_MGR02_OVG_PROPERTY const* hmi_gfx_mgr02_get_svg_const_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
GFX_MGR02_IMAGE_DEF_T const* hmi_gfx_mgr02_get_user_img_layer_def_ptr(UINT32 p_elem_id);
#endif
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
GFX_MGR02_IMAGE_PROPERTY const* hmi_gfx_mgr02_get_user_img_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_OF_SWDGS > 0
GFX_MGR02_WIDGET_DEF_T const* hmi_gfx_mgr02_get_swidget_layer_def_ptr(UINT32 p_elem_id);
UINT16 hmi_gfx_mgr02_get_swidget_clip_idx(UINT32 p_prop_idx);
GFX_MGR02_VISIBLE_AREA const* hmi_gfx_mgr02_get_wdg_elem_area_offset_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
GFX_MGR02_WIDGET_PROPERTY const* hmi_gfx_mgr02_get_widget_anim_prop_ptr(UINT32 p_prop_idx);
#endif
#if GFX_MGR02_NUM_SWDG_INSTANCES > 0
GFX_MGR02_WIDGET_PROPERTY const* hmi_gfx_mgr02_get_swidget_const_prop_ptr(UINT32 p_prop_idx);
#endif
#endif /* #if defined(GFX_MGR02_DLAYOUT_ENABLED) */

#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
UINT32 hmi_gfx_mgr02_layout_get_disp_content_status(void);
#endif
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
void * hmi_gfx_mgr02_layout_get_front_fb(GFX_UINT client_id);
#endif

#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
  UINT32 hmi_gfx_mgr02_layout_set_text_special_effects_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_TXT_SPECIAL_EFFECTS * p_obj_effects);
#endif /* #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) */

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
UINT32 hmi_gfx_mgr02_layout_get_num_drecs(void);
GFX_MGR02_VISIBLE_AREA * hmi_gfx_mgr02_layout_get_drect(UINT32 p_index);
#endif

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
GFX_MGR02_CAPTURE_INIT_STATUS hmi_gfx_mgr02_layout_get_capture_init_status(void);
void hmi_gfx_mgr02_layout_set_frame_capture_done_status(UINT8 p_val);
UINT8 hmi_gfx_mgr02_layout_get_frame_capture_done_status(void);
#if (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
void hmi_gfx_mgr02_layout_set_display_property(CYGFX_DISP_ATTR p_attr_name, CYGFX_U32 p_val);
#endif
#endif

#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
UINT8 hmi_gfx_mgr02_layout_get_text_global_max_shrink(void);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_global_max_shrink(UINT8 p_max_shrink);
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0)
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_get_text_property_max_shrink(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 * p_max_shrink);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_layout_set_text_property_max_shrink(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_max_shrink);
#endif
#endif

#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
UINT8 hmi_gfx_mgr02_layout_get_txt_shaping_required(UINT16 p_elem_id);
#endif
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
BOOLEAN hmi_gfx_mgr02_layout_get_text_scroll_status(GFX_MGR02_ANIM_ELEM_ID p_obj_id);
void hmi_gfx_mgr02_layout_start_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id);
void hmi_gfx_mgr02_layout_stop_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id);
void hmi_gfx_mgr02_layout_reset_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id);
void hmi_gfx_mgr02_layout_stop_reset_scroll(GFX_MGR02_ANIM_ELEM_ID p_text_anim_id);
#endif

#if (defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_USE_TIDSS))
SINT32 hmi_gfx_mgr02_layout_set_dss_pipeline_alpha(UINT8 p_disp_id, UINT8 p_pipeline_id, GFX_MGR02_ALPHA p_alpha);
#endif

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
** CMS Rev 3.8     15-Feb-2018    ARAJASE2
** 1035493: GM-CHUD : Fetching the MULTI_LINE_INFO for text with lines > 255
**
** CMS Rev 3.7     18-Sep-2017    ADEVI
** 955614: Multi-line Scroll Optimization And Max lines increased.
** 
** CMS Rev 3.6     18-Sep-2017    ARAJASE2
** 921462: Dynamic Font update issue in Amber platform with External font
**
** CMS Rev 3.5      6-Sep-2017    ADEVI
** 948804: Amber driver run time recovery implementation.
**
** CMS Rev 3.4     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 3.3     23-Aug-2017    ADEVI
** 929657: Dynamic Text Width Change
** 
** CMS Rev 3.2      08-Aug-2017    ARAJASE2
** Added new function hmi_gfx_mgr02_layout_set_inter_line_spacing to support dynamic update
** of inter line spacing
** 922409: Dynamic Inter-line spacing for multi-line text
**
** CMS Rev 3.1    29/06/17    SSRINI19
** 880883 : GM-CHUD QAC MISRA additional warning fixes

** CMS Rev 3.0    5-May-2017    ADEVI
** 847451: GM-CHUD- Multi line changes
**
** CMS Rev 2.9     12-Apr-2017    ADEVI
** 829051: Amber:Multi line feature integration
**
** CMS Rev 2.8     07/02/2016    SBOLLAM
** RTC ID: 750237: Updated error logging capability and added
**                 OVG software recovery capability
**
** CMS Rev 2.7      26-Aug-2016    ADEVI
** 656058: Arabic hard cut multi line requirements implementaion

** CMS Rev 2.6      18-Aug-2016    CMUTHUSA
** 674040: Right Alignment in Arabic Layout moves the Textbox out of range
**
** CMS Rev 2.5      22-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 2.4     22-July-2016    ADEVI
** 610788: Multi - line data saved and new line requirement changes.
**
** CMS Rev 2.3     28-Apr-2016    ADEVI         RTC 546876
** Add support to change the Text Size Dynamically when Font Engine is used.
**
** CMS Rev 2.2     15-Feb-2016    ADEVI         RTC 494789
** Multi line text Implementation - NEW FORD requirements.
**
** CMS Rev 2.1     5-Feb-2015    APERUMAL
** RTC 512949:
** Compiler warnings fix for B515
**
** CMS Rev 2.0     20-Nov-2015    APERUMAL
** Ref RTC: 467010
** Introduced macro GFX_MGR02_UNUSED_VAR to avoid Compiler, qac and coverity
** warnings on unused variables
**
** CMS Rev 1.9     22-Aug-2015    APERUMAL
** Ref RTC: 405974
** QA C warnings fix for Honda Thaa
**
** CMS Rev 1.8     5-Feb-2015    ADEVI
** Ref RTC: 282879
** hmi_gfx_mgr02_layout_set_screen_dyn_priority interface added.

** CMS Rev 1.7     24-Nov-2014    ADEVI
** Ref RTC: 204201
** hmi_gfx_mgr02_layout_set_text_scroll_parameter argument clip mode removed.
**
** CMS Rev 1.6     11-Nov-2014    ADEVI
** Ref RTC# 204201.
** hmi_gfx_mgr02_layout_set_text_scroll_parameter function added to set the 
** scroll offset value and clip mode during scroll.
**
** CMS Rev 1.5     03-Oct-2014    EMANOJ1
** Ref RTC# 214249, 211516, 126581
** hmi_gfx_mgr02_layout_freeze_touch_event function added to freeze further touch 
** events for active button (for usage while switching layouts). 
**
** CMS Rev 1.4     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.3      19-Mar-2014    EMANOJ1
** Added api hmi_gfx_mgr02_layout_get_char_metrics to get the font metrics
**
** CMS Rev 1.2      15-Mar-2012    ASHEKHAR
** Added interfaces for shutdown
**
** CMS Rev 1.1      18-Jan-13    ASHEKHAR
** Updated interfaces for the interface layer..
**
** CMS Rev 1.0      08-Aug-12    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
