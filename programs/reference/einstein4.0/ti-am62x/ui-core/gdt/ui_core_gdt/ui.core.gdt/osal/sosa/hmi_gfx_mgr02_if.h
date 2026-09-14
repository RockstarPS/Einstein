/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_if.h
**
** Description:    Interface header for the graphics manager for the
**                 Kepler Spectrum/RainbowLite Platform.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_IF_H
#define HMI_GFX_MGR02_IF_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_language_interface.h"
#include "hmi_gfx_mgr02_layout.h"
#if defined(LNG_UNICODE) && !defined(WIN32)
   #include "wchar.h"
#endif

#if defined(GFX_MGR02_KEPLER)
#include "hmi_gfx_mgr02_dcu.h"
#include "hmi_gfx_mgr02_driver.h"
#endif

#if !defined(MATLAB_MEX_FILE)
  #include "tmwtypes.h"
  #include "hmi_gfx_mgr02_if_chart.h"
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#if (GFX_MGR02_IF_TASK_RATE==0) || (GFX_MGR02_IF_APP_PRESENTATION_RATE == 0)
   #error "GFX_MGR02_IF_APP_PRESENTATION_RATE and GFX_MGR02_IF_TASK_RATE should be > 0\n"
#endif


#define GFX_MGR02_IF_PRESENTATION_SCHED_COUNT (GFX_MGR02_IF_APP_PRESENTATION_RATE/GFX_MGR02_IF_TASK_RATE)

#if GFX_MGR02_IF_PRESENTATION_SCHED_COUNT == 0
   #error "GFX_MGR02_IF_APP_PRESENTATION_RATE should be set >= GFX_MGR02_IF_TASK_RATE\n"
#elif GFX_MGR02_IF_PRESENTATION_SCHED_COUNT >= 255
   #error "GFX_MGR02_IF_PRESENTATION_SCHED_COUNT exceeded design limit of 255\n"
#endif            
/*
** Any update to any of the below structures shall be followed up with
** changes in PrintDataStructureMemoryUsage() of GDT coder so that the
** memory usage information is rightly populated by the coder.
*/
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

void   hmi_gfx_mgr02_if_KSColdInit(void);
void   hmi_gfx_mgr02_if_KSWarmInit(void);
void   hmi_gfx_mgr02_if_KSWakeUp(void);
void   hmi_gfx_mgr02_if_KSSleep(void);
#if defined(GFX_MGR02_KEPLER)
void   hmi_gfx_mgr02_if_disable_dcu(void);
void   hmi_gfx_mgr02_if_enable_dcu(void);
#endif

UINT32 hmi_gfx_mgr02_if_presentation_task(void);

void hmi_gfx_mgr02_if_force_update(void);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_screen(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show);

GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_screen_dyn_priority(GFX_MGR02_SCR_ELEM_ID p_elem_id, UINT32 p_show, UINT8 priority);
#if GFX_MGR02_NUM_OF_DTEXTS > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string);
  #if HM_LANG_MAX_SID > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid);
  #endif
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_text_width_ext(GFX_MGR02_DTEXT_ID p_elem_id, GFX_MGR02_TEXT_WIDTH_INFO * p_text_info,UINT32 p_alignment);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_text_width(GFX_MGR02_DTEXT_ID p_elem_id, GFX_MGR02_TEXT_WIDTH_INFO * p_text_info);
#if (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_AMBER)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_multi_line_text(GFX_MGR02_DTEXT_ID p_elem_id, HMI_CHAR const * p_string, GFX_MGR02_ANIM_ELEM_ID p_anim_id);
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_inter_line_spacing(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT8 p_inter_line_spacing);
#endif/*#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0*/
#if HM_LANG_MAX_SID > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_multi_line_sid(GFX_MGR02_DTEXT_ID p_elem_id, LANG_SID_T p_sid, GFX_MGR02_ANIM_ELEM_ID p_anim_id);
#endif
#endif
#endif /*#if GFX_MGR02_NUM_OF_DTEXTS > 0*/

#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dwidget(GFX_MGR02_DWDG_ELEM_ID p_elem_id, UINT32 p_index);
#endif /*#if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0*/

#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dimage(GFX_MGR02_DIMG_ELEM_ID p_elem_id, UINT32 p_index);
#endif /*#if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0*/

#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_clut(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_clut_id);
#endif

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || \
    (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0) || \
    ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_area(GFX_MGR02_ANIM_ELEM_ID p_elem_id,  GFX_MGR02_IAREA_DATA const * p_clip);
#endif

#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) && defined(GFX_MGR02_CLIPPED_WIDGETS))
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_vclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_VCLIP_DATA const * p_clip);
  #if !defined(GFX_MGR02_KEPLER)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_hclip(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_HCLIP_DATA const * p_clip);
  #endif
#endif

GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_alpha(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_alpha);
#if ((GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_fg_color(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_color);
#endif
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA const * p_pos);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_get_obj_pos(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_ILOC_DATA * p_pos);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_default_properties(GFX_MGR02_ANIM_ELEM_ID p_elem_id);

#if (GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_tile(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_TILE_DATA const * p_tile);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_MGR02_IDIM_DATA const * p_dim);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim_w(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_w);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_dim_h(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT32 p_dim_h);
#endif

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pivot_x(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_x);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_pivot_y(GFX_MGR02_ANIM_ELEM_ID p_elem_id, SINT16 p_pos_y);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_mul_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_transformation(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT const * p_matrix);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_scale(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_scalex, GFX_FLOAT p_scaley);
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_obj_rotate(GFX_MGR02_ANIM_ELEM_ID p_elem_id, GFX_FLOAT p_angle);
#endif

#if (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_gfont_index(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left);
#endif

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_text_prop(GFX_MGR02_ANIM_ELEM_ID p_elem_id,
                                                          UINT32                 p_alignment, 
                                                          UINT32                 p_draw_mode,
                                                          UINT32                 p_clip_mode);
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS))
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_set_font(GFX_MGR02_ANIM_ELEM_ID p_elem_id, UINT8 p_font_id, UINT8 p_font_pt_size);
#endif
#endif
#if defined(GFX_MGR02_USE_PTHREAD_MUTEX)
void hmi_gfx_mgr02_if_begin_update(void);
void hmi_gfx_mgr02_if_end_update(void);
#endif
#if ((GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) && defined(GFX_MGR02_OPEN_VG))
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_add_to_vgcache(UINT32 fl_image_base_id);
#endif

#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_if_select_dlayout_index(GFX_MGR02_LAYOUT_ID p_selection_index);
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
** CMS Rev 1.11      08-Aug-2017    ARAJASE2
** Added new function hmi_gfx_mgr02_if_set_inter_line_spacing to support dynamic update
** of inter line spacing
** 922409: Dynamic Inter-line spacing for multi-line text
**
** CMS Rev 1.10      22-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.9     22-July-2016    ADEVI
** 610788: Multi - line data saved and new line requirement changes.
**
** CMS Rev 1.8      06-April-2016    ADEVI
** 546876: Add support to change the Text Size Dynamically when Font Engine is used.
** Included hmi_gfx_mgr02_if_set_font() API
**
** CMS Rev 1.7      06-April-2016    CSAKTHIV
** 557102: Interface to create openvg image handle before starting animation
**
** CMS Rev 1.6      24-Mar-2016    SVIKRAM
** 521380: Coverity issue fix
**
** CMS Rev 1.5     27-May-2015    CSAKTHIV
** Ref RTC: 338234
** hmi_gfx_mgr02_if_get_text_width interface added.
**
** CMS Rev 1.4     5-Feb-2015    ADEVI
** Ref RTC: 282879
** hmi_gfx_mgr02_if_set_screen_dyn_priority interface added.
**
** CMS Rev 1.3     25-Nov-2013    CMUTHUSA
** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
**
** CMS Rev 1.2      30-Apr-2013    EMANOJ1
** Compiler switch updated for functions hmi_gfx_mgr02_if_set_obj_area and
** hmi_gfx_mgr02_if_set_obj_vclip to support area animation for fill and tile
**
** CMS Rev 1.1      19-Feb-2013    ASHEKHAR
** Updated all new interfaces for gfx mgr02.
**
** CMS Rev 1.0      05-May-11    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
