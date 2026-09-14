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
 ** Name:           hmi_gfx_mgr02_dcu.c
 **
 ** Description:    Main graphics manager 02 logic implementation module
 **                 Manages the display building operations.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_DCU_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
    defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    #include "mcu_preg.h"
#endif
#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_KEPLER
#include "hmi_gfx_mgr02_defs.h"
#include "hmi_gfx_mgr02_font.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_dcu.h"
#include "hmi_gfx_mgr02_text.h"
#include "dma.handler.h"
#include "graphics.h"
#include "hmi_gfx_mgr02_image_data.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_driver.h"
#include "hmi_gfx_mgr02_mem.h"
#include "hmi_gfx_mgr02_perflog.h"


#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#include "ExtFontEngine_wrapper.h"
#endif

#if (GFX_MGR02_NUM_OF_SWDGS > 0) && (defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE))
#include "hmi_gfx_mgr02_generic.h"
#endif

#if  defined(GFX_MGR02_SHUTDOWN_TEST)
#include "hmi_gfx_mgr02_test.h"
#endif
#if defined(WIN32) || defined(MATLAB_MEX_FILE)
#if !defined(NUNIT_TESTING)
  #include <windows.h>
  #include <stdio.h>
#endif
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#ifdef GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK
 #if (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT)
  #error "GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK option cannot be used with external font engine" 
 #endif
#endif

#if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT) && !defined(GFX_MGR02_CLIPPED_WIDGETS)
  /* TODO : need to fix this limitation */
  #error "multi color functionality currently not working with GFX_MGR02_CLIPPED_WIDGETS=0"
#endif

#if defined(GFX_MGR02_FARADAY)
 #if GFX_MGR02_NUM_DCU_LAYERS > 64
    #error "Only 64 DCU layers are supported"
 #endif
#else
 #if GFX_MGR02_NUM_DCU_LAYERS > 16
    #error "Only 16 DCU layers are supported"
 #endif
 #if defined(GFX_MGR02_RESERVE_LAYERS_FOR_HIGH_PRIORITY_SCREEN)
    /*
    ** this option is currently supported only for the non faraday versions
    ** FOr faraday version the number of layers are 32-64, so this support
    ** may not be required. Also enabling this option will make the layer
    ** copy difficuly for the faraday due to the fact that the tiling
    ** support is only available on top 8 layers and bottom 8 layers.
    ** in order to optimally utilize this, we are copying the top to bottom
    ** and bottom to top symultaniously on a faraday target.
    */
    #define GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
 #endif
#endif

#if defined(GFX_MGR02_USE_GRAPHICS_TASK_CONTEXT)
 #define GFX_MGR02_GRAPHICS_TASK_CONTEXT
#elif defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
 #define GFX_MGR02_GRAPHICS_TASK_CONTEXT
#else
#endif
#define HMI_GFX_MGR02_ELEMENT_VISIBLE      (2)
#define HMI_GFX_MGR02_ELEMENT_INVISIBLE    (1)
#define HMI_GFX_MGR02_ELEMENT_INVALID      (0)
/*
** Defines the maximum depth to be supported in widget building.
** e.g below shows a parent widget containing child widget 1 inturn
** the child widget 1 contains child widget 2. In this case the overall
** path depth is 2 and to support the building we need to have
** GFX_MGR02_MAX_WDG_PATH_DEPTH set atleat to 2.
** parent_widget--
**               "--- Text
**               "--- ChildWidget1 -- (Depth = 1)
**               "                " --- ChildWidget2 (Depth = 2)
**               "--- Text\
** Note :- In this version of the GDT the max widget depth is set to
** 10 and user cannot change. This could later be generated from GDT
** or given as an option to user to configure.
*/
#define GFX_MGR02_MAX_WDG_PATH_DEPTH       (10)

#define GFX_MGR02_APPEND_WDGT_ANIM_PARAMS   (0)
#define GFX_MGR02_INIT_WDGT_ANIM_PARAMS     (1)
#define GFX_MGR02_DISCARD_WDGT_ANIM_PARAMS  (2)
/*
** Bit operation macros to Check,Set and Clear the manager flags
*/
#define GFX_MGR02_IS_CHANGED(flag_array, obj_id) ((((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) & (UINT8)(1<<(((UINT16)(obj_id))&0x07u))) != 0)
#define GFX_MGR02_SET_FLAG(flag_array, obj_id)   ((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]   |= (UINT8)(1<<(((UINT16)(obj_id))&0x07u)))
#define GFX_MGR02_CLR_FLAG(flag_array, obj_id)   (((flag_array)[(UINT8)(((UINT16)(obj_id))>>3u)]) &= (UINT8)~(UINT8)(1u<<(((UINT16)(obj_id))&0x07)))

#ifdef HMI_GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
 #ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
  #define GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
 #endif
#endif

#ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
#if GFX_MGR02_NUM_OF_CLUTS > 0
#define HMI_GFX_MGR02_SET_CLUT_INDEX(dcu_lay_sp, clut_index)  ((dcu_lay_sp)->CTRLDESCL4.B.LUOFFS = l_clut_items_U16A[(clut_index)])
#else
#define HMI_GFX_MGR02_SET_CLUT_INDEX(dcu_lay_sp, clut_index)
#endif
#else
#define HMI_GFX_MGR02_SET_CLUT_INDEX(dcu_lay_sp, clut_index)  ((dcu_lay_sp)->CTRLDESCL4.B.LUOFFS = (clut_index))
#endif

#if defined(WIN32) || defined(MATLAB_MEX_FILE)
 #if !defined(NUNIT_TESTING)
   #define HMI_GFX_MGR02_DEBUG_PROCESS_MSG()      \
           {                                      \
              MSG  msg;                           \
              if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) \
              {                                \
                 TranslateMessage(&msg);       \
                 DispatchMessage(&msg);        \
              }                                \
           }
 #else
   #define HMI_GFX_MGR02_DEBUG_PROCESS_MSG() \
   {                                         \
       l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;\
       l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_IDLE;\
   }
 #endif
#else
   #define HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
#endif

#if !defined(GFX_MGR02_SHUTDOWN_TEST)
#define GFX_MGR_TEST_SHUTDOWN(p_count)
#endif

#if (GFX_MGR02_NUM_USER_LAYERS > 0) || \
    defined(GFX_MGR02_SOFTWARE)     || \
    defined(GFX_MGR02_OPEN_VG)      || \
    defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT) || \
    defined(GFX_MGR02_WDG_ALPHA_CONTROL)
   #define GFX_MGR02_BG_RENDERING 1
#else
   #define GFX_MGR02_BG_RENDERING 0
#endif

#define GFX_MGR02_TMP_TEXT_WIDTH(p)    ((p)->CTRLDESCL3.R)
#define GFX_MGR02_TMP_POSX(p)          ((p)->CTRLDESCL5.R)
#define GFX_MGR02_TMP_POSY(p)          ((p)->CTRLDESCL6.R)
#define GFX_MGR02_TMP_FB_INDEX(p)      ((p)->CTRLDESCL6.R)
#define GFX_MGR02_TMP_FB_CHANGED(p)    ((p)->CTRLDESCL7.R)
#define GFX_MGR02_TMP_FB_RENGINE(p)    ((p)->CTRLDESCL5.R)

#ifndef GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES
 #define GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES (8)
#endif

#if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
    defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
  #ifdef WIN32
     __int64 winGetPerformCounter(void)
    {
      LARGE_INTEGER lPerformanceCount = {0};
      QueryPerformanceCounter(&lPerformanceCount);
      return(lPerformanceCount.QuadPart);
    }
    #define GFX_TCOUNT            winGetPerformCounter()
  #else
    #define GFX_TCOUNT      (STM.CNT.R)
  #endif  
  #if (GFX_MGR02_VBLANK_PERIOD_USEC < 1000) ||  (GFX_MGR02_VBLANK_PERIOD_USEC > 4746)
    #error "As per the spec vblank duration is out of threshold"
  #endif
  #if (GFX_MGR02_BUILD_VBLANK_DIFFER_COUNT < 1) ||  (GFX_MGR02_BUILD_VBLANK_DIFFER_COUNT > 4)
    #error "Number of vblank cycles should be atleast 1 or less than or equal 4"
  #endif
#endif

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
#ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
static void hmi_gfx_mgr02_load_all_clut(void);
#else
static void hmi_gfx_mgr02_load_active_cluts(void);
#endif
static void hmi_gfx_mgr02_get_tile_fill_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ELEMENT_AREA * p_elem_area);
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) /*sbollam*/
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA * p_elem_area);
#endif
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index);

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
static void hmi_gfx_mgr02_get_text_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ELEMENT_AREA * p_elem_area);
static void hmi_gfx_mgr02_get_printable_text_area(UINT32 p_cur_alignment, UINT32 p_new_alignment,
                                                  GFX_MGR02_ISIZE_W_T p_text_width,
                                                  GFX_MGR02_VISIBLE_AREA * p_visible_area);
#endif

static void hmi_gfx_mgr02_load_alpha_blend_properties(UINT32 p_dcu_layer, UINT32 p_chroma_key);

#if (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0) || (GFX_MGR02_NUM_OF_SWDGS > 0)
static void hmi_gfx_mgr02_blank_display_area(UINT32 p_dcu_layer, UINT32 p_elem_bg_fill_color);
#endif

#if GFX_MGR02_NUM_OF_SWDGS > 0
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                 GFX_MGR02_ELEMENT_AREA * p_elem_area);
static void hmi_gfx_mgr02_build_widget(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
static UINT32 hmi_gfx_mgr02_render_swidget(GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP, UINT32 fl_obj_id);
#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) || (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0)
static UINT32 hmi_gfx_mgr02_print_widget_image(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ILOC_DATA const * p_offset_loc_SP);
#endif
static UINT32 hmi_gfx_mgr02_print_widget(void);
static UINT32 hmi_gfx_mgr02_print_widget_elements(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
static GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_print_widget_text(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ILOC_DATA const * p_offset_loc_SP);
#endif
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static void hmi_gfx_mgr02_set_vclip(UINT32 p_dcu_layer);
#endif
static void hmi_gfx_mgr02_bg_render_swidget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_cur_layer);
#endif

#if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
static void hmi_gfx_mgr02_build_image(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#if defined(__GFX_MGR02_RLE_ENABLED) || defined(GFX_MGR02_BUILDALL_IN_GRAM)
static UINT32 hmi_gfx_mgr02_render_image(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 fl_obj_id);
#endif
#endif

#if defined(GFX_MGR02_BUILDALL_IN_GRAM) && (GFX_MGR02_NUM_OF_TILES > 0)
static UINT32 hmi_gfx_mgr02_render_tile(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 fl_obj_id);
#endif

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
static void hmi_gfx_mgr02_build_text(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
static void hmi_gfx_mgr02_build_fill(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
static void hmi_gfx_mgr02_build_tile(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif

static void   hmi_gfx_mgr02_init_virtual_layers(UINT8 p_layer_index);
static UINT32 hmi_gfx_mgr02_pre_render_loop(void);

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 && !defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
static UINT32 hmi_gfx_mgr02_render_text(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP);
#endif

static UINT32 hmi_gfx_mgr02_dma_render_loop(void);
static void   hmi_gfx_mgr02_bg_render_loop(UINT32 p_cur_layer);

static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layer_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT32 p_num_elements,
                                                           struct DCU_LAYER_tag  * p_vir_layer_SP);

#if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
static void hmi_gfx_mgr02_pp_multi_color_area(SINT32 p_sx,
                                              SINT32 p_sy,
                                              SINT32 p_width,
                                              SINT32 p_height,
                                              UINT32 p_color,
                                              UINT32 p_layer);
#endif
#if defined(GFX_MGR02_WDG_ALPHA_CONTROL)
static void hmi_gfx_mgr02_pp_multi_alpha_area(SINT32 p_sx,
                                              SINT32 p_sy,
                                              SINT32 p_width,
                                              SINT32 p_height,
                                              UINT32 p_color,
                                              UINT32 p_layer);
#endif
#if defined(GFX_MGR02_WDG_ALPHA_CONTROL) || defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
static void hmi_gfx_mgr02_pp_multi_color_widget_image(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                      GFX_MGR02_ILOC_DATA    const * p_offset_SP,
                                                      GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                      UINT32                         p_layer,
                                                      UINT32                         p_mcolor);
static void hmi_gfx_mgr02__pp_multi_color_widget_text(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                     GFX_MGR02_ILOC_DATA    const * p_offset_loc_SP,
                                                     GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                     UINT32                         p_layer,
                                                     UINT32                         p_mcolor);
static void hmi_gfx_mgr02_pp_for_multi_color_widget_elements(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                         GFX_MGR02_ILOC_DATA    const * p_offset_SP,
                                                         GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                         UINT32                         p_layer,
                                                         UINT32                         p_mcolor);
static void hmi_gfx_mgr02_pp_multicolor_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_dcu_layer, UINT32 p_mcolor);
#endif
static void hmi_gfx_mgr02_gram_print_done(UINT32 p_process_mode);
static void hmi_gfx_mgr02_program_dcu_layers(void);
#if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
extern void hmi_gfx_mgr02_ovg_text_print_text(void);
extern GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_ovg_text_print_widget_text(GFX_MGR02_TEXT_INFO fl_text_info_S,
	                                                           GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
	                                                       	   UINT8 p_current_layer,
	                                                       	   UINT8 p_font_ht,
	                                                       	   SINT32 fl_twidth,
	                                                       	   SINT32 fl_theight,
	                                                       	   UINT8 p_bpp);
#endif

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

static volatile UINT8           l_gfx_mgr_shutdown_status;
static volatile UINT8           l_gfx_mgr_edma_process_mode;
static volatile UINT8           l_gfx_mgr_vsync_process_mode;
static GFX_MGR02_CONTROL_DATA_T l_gfx_mgr02_data_S;
/* 
** Use Virtual Layers to copy the Data once all screen data is copied move 
** virtual layers to actual DCU layers. 
*/
static struct DCU_FG_tag        l_gfx_virtual_layer_fg[GFX_MGR02_NUM_DCU_LAYERS];
static struct DCU_LAYER_tag     l_gfx_virtual_layer[GFX_MGR02_NUM_DCU_LAYERS];

#ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
/*
** l_clut_items_SA[] holds the CLUT offset for each of the CLUT's
*/
#if ((GFX_MGR02_NUM_OF_CLUTS > 0) && (GFX_MGR02_NUM_OF_CLUTS <= 2048))
static UINT16 l_clut_items_U16A[GFX_MGR02_NUM_OF_CLUTS];
#else
#if (GFX_MGR02_NUM_OF_CLUTS > 2048)
#error "Current implementation supports only up to 2048 CLUTs"
#endif
#endif
#endif

#ifdef GFX_MGR02_DCU_ENABLE_HCLIP
static Graphics_Object_t l_source_go;
static Graphics_Object_t l_target_go;
#endif

#if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
    defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
static UINT32 l_vblank_start_time;
static UINT8  l_differ_build_flag;
static UINT8  l_vblank_cycles;
#endif

UINT8 const lc_dcu_image_width_byte_U8A[GFX_MGR02_16BPP_APAL8+1] = 
{
/*  GFX_MGR02_1BPP                 */ 32,
/*  GFX_MGR02_2BPP                 */ 16,
/*  GFX_MGR02_4BPP                 */ 8,
/*  GFX_MGR02_8BPP                 */ 4,
/*  GFX_MGR02_16BPP_RGB565         */ 2,
/*  GFX_MGR02_24BPP                */ 3,
/*  GFX_MGR02_32BPP                */ 1,
/*  GFX_MGR02_4BPP_TRANSPARENCY    */ 8,
/*  GFX_MGR02_8BPP_TRANSPARENCY    */ 4,
/*  GFX_MGR02_4BPP_LUMINANCE       */ 8,
/*  GFX_MGR02_8BPP_LUMINANCE       */ 4,
/*  GFX_MGR02_16BPP_ARGB1555       */ 2,
/*  GFX_MGR02_16BPP_ARGB4444       */ 2,
/*  GFX_MGR02_16BPP_APAL8          */ 2
};

#if GFX_MGR02_NUM_OF_SWDGS > 0
static GFX_MGR02_ELEM_LIST_T const * l_widget_elem_path_SPA[GFX_MGR02_MAX_WDG_PATH_DEPTH];
static UINT8 l_widget_num_path_U8A[GFX_MGR02_MAX_WDG_PATH_DEPTH];
static SINT8 l_widget_depth_level;
static GFX_MGR02_ILOC_DATA l_widget_offset_loc[GFX_MGR02_MAX_WDG_PATH_DEPTH];
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static GFX_MGR02_VISIBLE_AREA l_widget_clip[GFX_MGR02_MAX_WDG_PATH_DEPTH];
#endif
#endif

static UINT32 l_disp_bg_color;
static GFX_MGR02_ANIM_DATA_T * l_layer_anim_data_SP;

#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
  GFX_MGR02_IMAGE_DEF_T l_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
  extern GFX_MGR02_IMAGE_DEF_T const lc_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif

#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
 static HMI_CHAR l_dcu_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif

#if defined(__GFX_MGR02_RLE_ENABLED)
  static UINT8 const lc_rle_bpp[GFX_MGR02_MAX_BPP] = 
  {
  /*  GFX_MGR02_1BPP                 */ 0, 
  /*  GFX_MGR02_2BPP                 */ 0, 
  /*  GFX_MGR02_4BPP                 */ 0, 
  /*  GFX_MGR02_8BPP                 */ 0, 
  /*  GFX_MGR02_16BPP_RGB565         */ 1, 
  /*  GFX_MGR02_24BPP                */ 2, 
  /*  GFX_MGR02_32BPP                */ 3, 
  /*  GFX_MGR02_4BPP_TRANSPARENCY    */ 0, 
  /*  GFX_MGR02_8BPP_TRANSPARENCY    */ 0, 
  /*  GFX_MGR02_4BPP_LUMINANCE       */ 0, 
  /*  GFX_MGR02_8BPP_LUMINANCE       */ 0, 
  /*  GFX_MGR02_16BPP_ARGB1555       */ 1, 
  /*  GFX_MGR02_16BPP_ARGB4444       */ 1, 
  /*  GFX_MGR02_16BPP_APAL8          */ 1
  };
  #define GFX_MGR02_RLE_BPP(x)  (((x) < GFX_MGR02_MAX_BPP)?lc_rle_bpp[(x)]:0)
#endif

#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
  #if defined(WIN32) || defined(MATLAB_MEX_FILE)
    UINT8 dcu_gallo_memory[GFX_MGR02_GRAM_DCU_SIZE];
    #define GFX_MGR02_GRAM_DCU_BASE  ((UINT32)&dcu_gallo_memory[0])
   #ifndef GFX_MGR02_GRAM_BASE
    extern UINT8 gallo_memory[GFX_MGR02_GRAM_SIZE];
    #define GFX_MGR02_GRAM_BASE  ((UINT32)&gallo_memory[0])
   #endif
  #endif
  #ifndef GFX_MGR02_BUILDALL_IN_GRAM
    #error "BuildAll in GRAM configuration is not enabled"
  #endif
  #if !defined(GFX_MGR02_GRAM_DCU_BASE) || !defined(GFX_MGR02_GRAM_DCU_SIZE)
    #error "OFF screen build set up needs a dedicated DCU display GRAM base"
  #endif
#endif

#if defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
static volatile UINT8 l_gfx_mgr_process_gt_mode;
#endif

#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
UINT8 LanguageSelect;
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
extern UINT8 const lc_gfx_mono_append_txt_font_width[];
#endif
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
extern UINT8 const lc_gfx_digi_append_txt_font_width[];
#endif
#endif


/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
/*
** Workaround for a data corruption observed by the use of isel instruction
** Refer ui.core.gdt.doc\hmi.gfx.manager.02\release\SR# 1-1248551151.msg
*/
#ifndef WIN32
#pragma push
#pragma gen_isel off     
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_initialize
 ** Visibility:       global
 ** Description:      Initializes all internal variable data to its default
 ** Invocation:       By presentation layer when ever it wants to restart.
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          24-Jan-2012 by ASHEKHAR
 **==========================================================================*/
void hmi_gfx_mgr02_initialize(void)
{
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
    UINT8 fl_current_font_engine =  ui_app_get_cur_font_engine();
#endif
    l_gfx_mgr02_data_S.visible_num_of_elements = 0;
    l_gfx_mgr02_data_S.cur_build_layer         = 0;
    l_gfx_mgr02_data_S.hp_num_elements         = 0;

    l_gfx_mgr_shutdown_status    = GFX_MGR02_SHUTDOWN_NORMAL;
    l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_IDLE;
    l_gfx_mgr_edma_process_mode  = GFX_MGR02_PMODE_IDLE;
#if defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    l_gfx_mgr_process_gt_mode    = GFX_MGR02_PMODE_IDLE;
#endif
    l_layer_anim_data_SP         = hmi_gfx_mgr02_layout_get_anim_data();

    (void)memset((void *)&l_gfx_mgr02_data_S.next_elem_list_sa[0],
                 0x00,
                 sizeof(l_gfx_mgr02_data_S.next_elem_list_sa));

    hmi_gfx_mgr02_mem_initialize();

#if defined(__GFX_MGR02_RLE_ENABLED)
    Graphics_Initialize_RleImageDecoder(0,0,0,0,0,0,0,0);
#endif

#if GFX_MGR02_NUM_OF_SWDGS > 0
    l_widget_depth_level = -1;
#endif

#ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
    hmi_gfx_mgr02_load_all_clut();
#endif
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
    memcpy((void *)&l_runtime_wdg_image_layer_def_S[0], 
           (void *)&lc_runtime_wdg_image_layer_def_S[0], 
           sizeof(l_runtime_wdg_image_layer_def_S));
    l_gfx_mgr02_data_S.rt_wdg_img_layer_def_SP = &l_runtime_wdg_image_layer_def_S[0];
#endif
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
  LanguageSelect=hmi_language_if_get_current_language();
  {
    UINT8 Region;
    switch(LanguageSelect){
    case HMI_LANGUAGE_JAPANESE:
      Region=1; break;
    case HMI_LANGUAGE_KOREA:
      Region=2; break;
    case HMI_LANGUAGE_TAIWANESE:
      Region=3; break;
    case HMI_LANGUAGE_CHINESE:
      Region=4; break;
    default:
      Region=0; break;
    }
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
    if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
#endif
    {
        digi_init(Region);
    }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)		
    else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
#endif
    {
    monotype_init(Region);
    }
#endif
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
    else
    {
    }
    #endif
  }
#endif
#if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
    defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    l_vblank_start_time = 0;
    l_differ_build_flag = FALSE;
    l_vblank_cycles = 0;
#endif
}

static void hmi_gfx_mgr02_program_dcu_layers(void)
{
   /* CLUT and layer programming possible only during vblank period */
   SINT32 fl_dcu_index;
   UINT32 fl_vl_index;
   UINT32 fl_num_elem;
#ifdef GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
   UINT32 fl_lp_start_index;
#endif
#if defined(GFX_MGR02_FARADAY)
   SINT32 fl_end_index;
   SINT32 fl_dcu_top_index = 0;
#endif    
   /* Load CLUT ... */
#ifdef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
   hmi_gfx_mgr02_load_active_cluts();
#endif

   fl_dcu_index = (GFX_MGR02_NUM_DCU_LAYERS-1);
   /*
   ** Copy all the low priority layers from l_gfx_virtual_layer[] array
   ** DCU's lowest priority layer onwards to highest DCU layer
   ** This is to make sure that the lowest priority layer in the 
   ** l_gfx_virtual_layer[] array gets assigned to lowest priority DCU
   ** layer.
   ** Refer to 02_design\layer_allocation.doc
   */
   if(l_gfx_mgr02_data_S.lp_num_elements > 0)
   {
      fl_vl_index       = l_gfx_mgr02_data_S.cur_layer_index;
      fl_num_elem       = l_gfx_mgr02_data_S.lp_num_elements;
   #ifdef GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
      fl_lp_start_index = l_gfx_mgr02_data_S.start_layer_index;
   #endif
   #if defined(GFX_MGR02_FARADAY)
      fl_end_index      = (fl_vl_index-fl_num_elem);
      fl_dcu_top_index  = 0;
      if(fl_end_index < 0)
      {
         fl_end_index   = (GFX_MGR02_NUM_DCU_LAYERS - fl_end_index);
      }
   #endif    
       
      while(fl_num_elem > 0)
      {
         fl_num_elem--;
      #ifdef GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
         if(fl_vl_index <= fl_lp_start_index)
      #else
         if(fl_vl_index == 0)
      #endif
         {
            fl_vl_index = (GFX_MGR02_NUM_DCU_LAYERS-1);
         }
         else
         {
            fl_vl_index--;
         }
         DCU.LAYER[fl_dcu_index].CTRLDESCL1.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL1.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL2.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL2.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL3.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL3.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL4.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL4.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL5.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL5.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL6.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL6.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL7.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL7.R;
      #if defined(GFX_MGR02_FARADAY) && !defined(WIN32)
         DCU.LAYER[fl_dcu_index].FG.F.R       = l_gfx_virtual_layer_fg[fl_vl_index].F.R;
         DCU.LAYER[fl_dcu_index].FG.B.R       = l_gfx_virtual_layer_fg[fl_vl_index].B.R;
      #else
         DCU.FG[fl_dcu_index].F.R             = l_gfx_virtual_layer_fg[fl_vl_index].F.R;
         DCU.FG[fl_dcu_index].B.R             = l_gfx_virtual_layer_fg[fl_vl_index].B.R;
      #endif
         fl_dcu_index--;
      #if defined(GFX_MGR02_FARADAY)
         /*
         ** For the Faraday, the tiling is supported on only the top 8 and bottom eight layers.
         ** so we are splitting our layer allocation equally on top and bottom layers
         ** to support tiling layers on lower priority 8 layers and the top prioroity layers
         */
         if(fl_num_elem > 0)
         {
            fl_num_elem--;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL1.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL1.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL2.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL2.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL3.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL3.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL4.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL4.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL5.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL5.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL6.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL6.R;
            DCU.LAYER[fl_dcu_top_index].CTRLDESCL7.R = l_gfx_virtual_layer[fl_end_index].CTRLDESCL7.R;
         #if defined(GFX_MGR02_FARADAY) && !defined(WIN32)
            DCU.LAYER[fl_dcu_top_index].FG.F.R       = l_gfx_virtual_layer_fg[fl_end_index].F.R;
            DCU.LAYER[fl_dcu_top_index].FG.B.R       = l_gfx_virtual_layer_fg[fl_end_index].B.R;
         #else
            DCU.FG[fl_dcu_top_index].F.R             = l_gfx_virtual_layer_fg[fl_end_index].F.R;
            DCU.FG[fl_dcu_top_index].B.R             = l_gfx_virtual_layer_fg[fl_end_index].B.R;
         #endif
            fl_dcu_top_index++;
            fl_end_index++;
         }
      #endif
      }
   }
 #ifdef GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
   /*
   ** Incase if we have got high priority layers
   ** Copy that next. Order of copy is same as above.
   */
   if(l_gfx_mgr02_data_S.hp_num_elements > 0)
   {
      fl_vl_index = l_gfx_mgr02_data_S.start_layer_index;
      fl_num_elem = l_gfx_mgr02_data_S.hp_num_elements;
      while(fl_num_elem > 0)
      {
         fl_num_elem--;
         if(fl_vl_index == 0)
         {
            fl_vl_index = (l_gfx_mgr02_data_S.hp_num_elements-1);
         }
         else
         {
            fl_vl_index--;
         }
         DCU.LAYER[fl_dcu_index].CTRLDESCL1.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL1.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL2.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL2.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL3.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL3.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL4.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL4.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL5.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL5.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL6.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL6.R;
         DCU.LAYER[fl_dcu_index].CTRLDESCL7.R = l_gfx_virtual_layer[fl_vl_index].CTRLDESCL7.R;

      #if defined(GFX_MGR02_FARADAY) && !defined(WIN32)
         DCU.LAYER[fl_dcu_index].FG.F.R       = l_gfx_virtual_layer_fg[fl_vl_index].F.R;
         DCU.LAYER[fl_dcu_index].FG.B.R       = l_gfx_virtual_layer_fg[fl_vl_index].B.R;
      #else
         DCU.FG[fl_dcu_index].F.R             = l_gfx_virtual_layer_fg[fl_vl_index].F.R;
         DCU.FG[fl_dcu_index].B.R             = l_gfx_virtual_layer_fg[fl_vl_index].B.R;
      #endif
         fl_dcu_index--;
      }
   }
 #endif
   /*
   ** Disable all unused layers..
   */
 #if defined(GFX_MGR02_FARADAY)
   while(fl_dcu_index >= fl_dcu_top_index)
 #else
   while(fl_dcu_index >= 0)
 #endif
   {
      DCU.LAYER[fl_dcu_index].CTRLDESCL4.R = 0;
      fl_dcu_index--;
   }
   DCU.BGND.R = l_disp_bg_color;
}

#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_vblank_isr
 ** Visibility:       global
 ** Description:      Vertical blank ISR. Handles the graphics building
 **                   activity during the vblank.
 ** Invocation:       None
 ** Inputs/Outputs:   p_type - Type of the ISR
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          21-Jul-2015 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_vblank_isr(UINT32 p_type)
{
   UINT32 fl_process_mode = l_gfx_mgr_vsync_process_mode;

#ifdef GFX_MGR02_ENABLE_LOG
   gfxlogstart(GFX_LOG_DCU_ISR);
   if(p_type == GFX_MGR02_DCU_TXFR_FINISH)
   {
      gfxlogstart(GFX_LOG_DCU_DF2VS);
   }
   else if(p_type == GFX_MGR02_DCU_VSYNC_START)
   {
      gfxlogend(GFX_LOG_DCU_DF2VS);
   }
   else
   {
	   /*For MISRA warning Fix*/
   }
#endif

   l_gfx_mgr_vsync_process_mode = 0;

#if (GFX_NUM_ANIMATIONS > 0) && defined(GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC)
   if(p_type == GFX_MGR02_DCU_VSYNC_START)
   {
      hmi_gfx_anim_engine_tick();
   }
#endif

   if(l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)
   {
      if((p_type == GFX_MGR02_DCU_TXFR_FINISH) || (p_type == GFX_MGR02_DCU_VSYNC_START))
      {
         if((fl_process_mode & GFX_MGR02_PMODE_START_BUILD) != 0)
         {
            /*
            ** eDMA rendering start
            */
            (void)hmi_gfx_mgr02_dma_render_loop();
         }
         if((fl_process_mode & GFX_MGR02_PMODE_CPY_WBUF2GRAM) != 0)
         {
         #if defined(GFX_MGR02_GRAM_DCU_BASE)
            if((GFX_MGR02_GRAM_DCU_BASE != 0) && (GFX_MGR02_GRAM_SIZE >= GFX_MGR02_GRAM_DCU_SIZE))
            {
               l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_SWAP_GRAM;
               gfxlogstart(GFX_LOG_DCU_OFFSCRN_CPY);
               if(hmi_gfx_mgr02_memcpy_64bit(hmi_gfx_mgr02_mem_getbase(), 
                                             GFX_MGR02_GRAM_DCU_BASE, 
                                             GFX_MGR02_GRAM_DCU_SIZE) != DMA_NO_ERROR)
               {
                  l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
               }
            }
         #endif
            fl_process_mode = GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU;
         }
         if((fl_process_mode & GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU) != 0)
         {
            if(p_type == GFX_MGR02_DCU_VSYNC_START)
            {
               hmi_gfx_mgr02_program_dcu_layers();
            }
            else
            {
               l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU;
            }
         }
      }
      else
      {
         l_gfx_mgr_vsync_process_mode = fl_process_mode;
      }
   #ifdef HMI_GFX_MGR02_CALC_QSPI_CHKSUM
      HMI_GFX_MGR02_PERFORM_QSPI_CHECKSUM();
   #endif
   }
   gfxlogend(GFX_LOG_DCU_ISR);
}
#else
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_vblank_isr
 ** Visibility:       global
 ** Description:      Vertical blank ISR. Handles the graphics building
 **                   activity during the vblank.
 ** Invocation:       None
 ** Inputs/Outputs:   p_type - Type of the ISR
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          21-Jul-2015 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_vblank_isr(UINT32 p_type)
{
   UINT32 fl_process_mode = l_gfx_mgr_vsync_process_mode;

#ifdef GFX_MGR02_ENABLE_LOG
   gfxlogstart(GFX_LOG_DCU_ISR);
   if(p_type == GFX_MGR02_DCU_TXFR_FINISH)
   {
      gfxlogstart(GFX_LOG_DCU_DF2VS);
   }
   else if(p_type == GFX_MGR02_DCU_VSYNC_START)
   {
      gfxlogend(GFX_LOG_DCU_DF2VS);
   }
   else
   {
	   /*For MISRA warning fix.*/
   }
#endif

   l_gfx_mgr_vsync_process_mode = 0;

   GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_1)

#if (GFX_NUM_ANIMATIONS > 0) && defined(GFX_MGR02_SCHED_ANIM_TICKS_IN_VSYNC)
   if(p_type == GFX_MGR02_DCU_VSYNC_START)
   {
      hmi_gfx_anim_engine_tick();
   }
#endif

   if(l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)
   {
      if((p_type == GFX_MGR02_DCU_TXFR_FINISH) || (p_type == GFX_MGR02_DCU_VSYNC_START))
      {
         if((fl_process_mode & GFX_MGR02_PMODE_START_BUILD) != 0)
         {
         #if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
             defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
             !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
              l_vblank_cycles++;
              l_vblank_start_time = GFX_TCOUNT;
			  if(l_differ_build_flag == FALSE)
			  {
                /*
                ** eDMA rendering start
                */
                (void)hmi_gfx_mgr02_dma_render_loop();
			  }
			  else
			  {
			    hmi_gfx_mgr02_gram_print_done_isr();
			  }
         #else
              /*
              ** eDMA rendering start
              */
              (void)hmi_gfx_mgr02_dma_render_loop();
         #endif
         }
         if((fl_process_mode & GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU) != 0)
         {
            if(p_type == GFX_MGR02_DCU_VSYNC_START)
            {
               hmi_gfx_mgr02_program_dcu_layers();
            }
            else
            {
               l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU;
            }
         }
      }
      else
      {
         l_gfx_mgr_vsync_process_mode = fl_process_mode;
      }
   #ifdef HMI_GFX_MGR02_CALC_QSPI_CHKSUM
      HMI_GFX_MGR02_PERFORM_QSPI_CHECKSUM();
   #endif
   }
   GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_2)
   gfxlogend(GFX_LOG_DCU_ISR);
}
#endif

#if defined(__GFX_MGR02_RLE_ENABLED)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_rle_isr
 ** Visibility:       local
 ** Description:      Invoked by the freescale library on completion of a
 **                   requested graphics operation. From this function
 **                   based on the process mode hmi graphics manager schedules
 **                   the next operation.
 ** Invocation:       By Freescale library
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          05-OCT-2013 by NKRISHN9
 ** Updated:          06-OCT-2013 by NKRISHN9
 **==========================================================================*/
void hmi_gfx_mgr02_rle_isr(void)
{
   UINT32 fl_rle_status;

   if (1 == RLE.ISR.B.TXDIF)
   {
      RLE.RIER.B.TXDIE = 0;

      /*
      ** Following are some quick fix to make the back to back RLE
      ** request work. Without this back to back operation were getting
      ** crashed. We were not getting rle interrupt for the second image.
      ** TODO : check with FSL to find a better way to know whether 
      **        all the fifo content is transfered.
      **        Also directly indexing the TCD with channel # may get
      **        wrong if the dma.handler configuration uses a different
      **        mapping. This also needs to be worked out.
      */
   #ifndef WIN32
      while(RLE.SR.B.TXFILL != 0)
      {
        /* Do nothing */  
      }
      
      while(EDMA.TCD[GFX_MGR02_DMA_RLE_READ_CHANNEL].DONE == 0)
      {
        /* Do nothing */  
      }
      (void)Prod_Spec_Delay_Microseconds(1); /* TODO : fix it later, temporary fix for RLE hang issue */
   #endif

      /*----------------------------------------------------------------------*/
      /* Service the interrupt                                                */
      /*----------------------------------------------------------------------*/
      fl_rle_status  = RLE.ISR.R;
      RLE.ISR.R      = fl_rle_status;
      RLE.MCR.B.MDIS = 1;
      /* 
      ** TODO : DMA_Handler_ChannelISR call is to make the DMA channel IDLE. 
      **        Need to workout with infra team to handle this in a better way.
      */
      DMA_Handler_ChannelISR((dma_channel_num_type)GFX_MGR02_DMA_CHANNEL,(UINT8)DMA_COMPLETE_ISR);
      DMA_Handler_ChannelISR((dma_channel_num_type)GFX_MGR02_DMA_RLE_READ_CHANNEL,(UINT8)DMA_COMPLETE_ISR);
      hmi_gfx_mgr02_gram_print_done_isr();
   }
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_gram_print_done
 ** Visibility:       local
 ** Description:      Invoked on completion of a requested graphics operation. 
 **                   From this function based on the process mode 
 **                   hmi graphics manager schedules the next operation.
 ** Invocation:       By Freescale library
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context or GT context).
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          06-Dec-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_gram_print_done(UINT32 p_process_mode)
{
    if(p_process_mode == GFX_MGR02_PMODE_INIT_GRAM)
    {
       /*
       ** pre-render hmi_gfx_mgr02_blank_display_area()
       ** callback, so we can ignore this
       */
    }
    else if(l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)
    {
    #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
       if(p_process_mode == GFX_MGR02_PMODE_BUILD_WIDGET_SUB_CPY)
       {
          l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_WIDGET;
          if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                            &l_source_go,
                            &l_target_go,
                            (UINT16)l_target_go.x,
                            (UINT16)l_target_go.y,
                            &hmi_gfx_mgr02_gram_print_done_isr) != GRAPHICS_ERROR_OK)
          {
             /*
             ** paste failed, so we can continue with rest of the widget
             ** building
             */
             l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
          #if GFX_MGR02_NUM_OF_SWDGS > 0
             (void)hmi_gfx_mgr02_print_widget();
          #endif
          }
       }
       else
    #endif /* #ifdef GFX_MGR02_DCU_ENABLE_HCLIP */
        if(p_process_mode == GFX_MGR02_PMODE_BUILD_WIDGET)
        {
           /*
           ** Widget building is in progress, so pass control to
           ** hmi_gfx_mgr02_print_widget to perform building of next element in
           ** current widget.
           */
        #if GFX_MGR02_NUM_OF_SWDGS > 0
           (void)hmi_gfx_mgr02_print_widget();
        #endif
        }
        else
        {
           /*
           ** GFX_MGR02_PMODE_BUILD_IMAGE or GFX_MGR02_PMODE_UPDATE_GRAM
           ** continue the render loop to the next layer, if its not
           ** due to a memory init cllback from the print routines.
           ** if its a memory init callback, no need to increment layer
           ** since we have to continue the building of the layer
           */
           if(p_process_mode != GFX_MGR02_PMODE_UPDATE_GRAM)
           {
              l_gfx_mgr02_data_S.cur_build_layer++;
           }
           (void)hmi_gfx_mgr02_dma_render_loop();
        }
    }
    else
    {
       /* 
       ** If Emergency Shutdown requested need not process further elements, just make it idle
       ** and terminate further updates.
       */
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_gram_print_done_isr
 ** Visibility:       local
 ** Description:      Invoked by the freescale library on completion of a
 **                   requested graphics operation. From this function
 **                   based on the process mode hmi graphics manager schedules
 **                   the next operation.
 ** Invocation:       By Freescale library
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          06-Dec-2012 by ASHEKHAR
 **==========================================================================*/
void hmi_gfx_mgr02_gram_print_done_isr(void)
{
    UINT32 fl_process_mode  = l_gfx_mgr_edma_process_mode;
	UINT32 fl_delta_time=0;

    gfxlogstart(GFX_LOG_DCU_EDMA_ISR);
    l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;

#if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
    defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)

	if(l_vblank_cycles >= 1)
	{
	  fl_delta_time = (GFX_TCOUNT-l_vblank_start_time);
	}

	if((fl_delta_time > GFX_MGR02_VBLANK_PERIOD_USEC) && (l_vblank_cycles <= GFX_MGR02_BUILD_VBLANK_DIFFER_COUNT))
	{
	  /*
	  ** Activate differed build. Continue the rest of the items, in next vblank ISR
	  ** by invoking hmi_gfx_mgr02_gram_print_done(fl_process_mode);
	  */
	  l_differ_build_flag          = TRUE;
	  l_gfx_mgr_edma_process_mode  = fl_process_mode;
	  l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_START_BUILD;
	}
	else
	{
	  hmi_gfx_mgr02_gram_print_done(fl_process_mode);
	}
#elif !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    hmi_gfx_mgr02_gram_print_done(fl_process_mode);
#else
    /*
    ** Store the status to be handled by background task
    ** hmi_gfx_mgr02_bg_gram_print_handler()
    */
    l_gfx_mgr_process_gt_mode = fl_process_mode;
#endif
    gfxlogend(GFX_LOG_DCU_EDMA_ISR);
}

#if defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_bg_gram_print_handler
 ** Visibility:       local
 ** Description:      This handles the eDMA build operation as a background
 **                   or GT task rather than on eDMA isr chaining. This is 
 **                   used when a external font engine is used where we cannot
 **                   use eDMA and chaining it in ISR will have execution time 
 **                   penalty. So doing this is as a BG task is ideal. The 
 **                   eDMA ISR will only set the l_gfx_mgr_process_gt_mode
 **                   flag in this case and this flag will be handled by this
 **                   function.
 ** Invocation:       By hmi_gfx_mgr02_build_screen
 ** Inputs/Outputs:   None
 ** Critical Section: None
 ** Created:          17-Dec-2013 by EMANOJ1
 ** Updated:          08-Jan-2014 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_bg_gram_print_handler(void)
{
   UINT8 fl_process_mode;

   while((l_gfx_mgr02_data_S.cur_build_layer < l_gfx_mgr02_data_S.visible_num_of_elements) &&
         (l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY))
   {
      GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_3)
      while((l_gfx_mgr_process_gt_mode   == GFX_MGR02_PMODE_IDLE) && 
            (l_gfx_mgr_edma_process_mode != GFX_MGR02_PMODE_IDLE) &&
            (l_gfx_mgr_shutdown_status   != GFX_MGR02_SHUTDOWN_EMERGENCY))
      {
         /*
         ** Wait until we have a completion flag available.
         */
         GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_4)
         HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
      }
      fl_process_mode           = l_gfx_mgr_process_gt_mode;
      l_gfx_mgr_process_gt_mode = GFX_MGR02_PMODE_IDLE;
      if(l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)
      {
         hmi_gfx_mgr02_gram_print_done(fl_process_mode);
      }
   }
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_screen
 ** Visibility:       global
 ** Description:      Builds the screens that are active in  l_cur_screen_selection
 **                   array
 ** Invocation:       By presentation layer or the graphics interface layer
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          05-Jul-2012 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U8)
{
    UINT32 fl_layer_index;
    UINT32 fl_overlap_slayer;
#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
    UINT32 fl_mem_offset;
#endif

    gfxlogstart(GFX_LOG_DCU_OVERALL);
    gfxlogstart(GFX_LOG_DCU_PROCESSING);
    gfxlogstart(GFX_LOG_DCU_RENDERING);
    gfxlogstart(GFX_LOG_DCU_OPENVG);
    gfxlogstart(GFX_LOG_DCU_EDMA);
    gfxlogstart(GFX_LOG_DCU_MULTICOLOR);
 #if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
	defined(GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING) && \
	!defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
	l_differ_build_flag = FALSE;
	l_vblank_cycles = 0;
 #endif

    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_5)
    /*
    ** 1. Analyze all the layers in active screens from low priority to high priority
    ** 2. Find out list of layers that are visible, exclude layers which will be hidden.
    ** 3. Assign DCU layers for the visible layers
    ** 4. Build the visible 16 layers and enable them
    ** 5. After the visible layers are built, perform building operation for invisible
    **    widget/text layers so that they will be ready to display once they become
    **    visible.
    */
    hmi_gfx_mgr02_manage_layers(p_layer_ID_U8);

    /*
    ** Preprocess the active layers and create all layer
    ** configurations in to a virtuel layer so that the
    ** ISR load can be minimized.
    */
    l_gfx_mgr02_data_S.cur_build_layer = GFX_MGR02_NUM_DCU_LAYERS;
    fl_overlap_slayer                  = hmi_gfx_mgr02_pre_render_loop();
    gfxlogend(GFX_LOG_DCU_PROCESSING);
#if defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    l_gfx_mgr_process_gt_mode = GFX_MGR02_PMODE_IDLE;
#endif
    /*
    ** After preprocess if there are any layers content needs
    ** to be built in GRAM then initiate that in next vblank
    */
    if(l_gfx_mgr02_data_S.cur_build_layer < GFX_MGR02_NUM_DCU_LAYERS)
    {
       gfxlogcontinue(GFX_LOG_DCU_EDMA);
    #if defined(GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK) && \
	    !defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
       l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_START_BUILD;
    #else
       (void)hmi_gfx_mgr02_dma_render_loop();
    #endif
    }

    /*
    ** When donot rebuild unchanged element option is enabled,
    ** and if there are no chnages in any of the widget/text element then
    ** hmi_gfx_mgr02_dma_render_loop() will not run and the next element
    ** list will not get copied to current element list. This could be a problem
    ** if some of the items get removed from the element list becuuse then
    ** there will be a mismatch between the cur_elem_list_sa[] and 
    ** l_cur_gram_alloc_table[], this loop here was added to avoid this mismatch
    ** TODO : if there are noc ahnges we don't need to perform the memory allocation
    **        and hmi_gfx_mgr02_copy_front_to_back_buffer() itself.
    **        the backbuffer can point to the front itself. This needs to be handled
    **        at a later stage and until then this fix will have to remain here.
    */
    fl_layer_index = 0;
    while(fl_layer_index < l_gfx_mgr02_data_S.visible_num_of_elements)
    {
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_6)
       l_gfx_mgr02_data_S.cur_elem_list_sa[fl_layer_index] = \
                   l_gfx_mgr02_data_S.next_elem_list_sa[fl_layer_index];
       fl_layer_index++;
    }
    while(fl_layer_index < GFX_MGR02_NUM_DCU_LAYERS)
    {
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_7)
       l_gfx_mgr02_data_S.cur_elem_list_sa[fl_layer_index] = (GFX_MGR02_ELEM_LIST_T *)0;
       l_gfx_virtual_layer[fl_layer_index].CTRLDESCL4.B.EN = 0;
       fl_layer_index++;
    }

#if defined(GFX_MGR02_GRAPHICS_TASK_CONTEXT)
    hmi_gfx_mgr02_bg_gram_print_handler();
#endif

#if GFX_MGR02_BG_DMA_SEQ_RENDERING != 0
    /*
    ** Wait until the DMA build operations finishes
    ** if the rendering mode is set to sequential so that
    ** we allow the hmi_gfx_mgr02_bg_render_loop to run only
    ** after all DMA operations finish
    */
    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_8)
    while(((l_gfx_mgr_vsync_process_mode != GFX_MGR02_PMODE_IDLE) ||
           (l_gfx_mgr_edma_process_mode  != GFX_MGR02_PMODE_IDLE))   && 
          (l_gfx_mgr_shutdown_status     != GFX_MGR02_SHUTDOWN_EMERGENCY))
    {
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_9)
        HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
    }
#endif

#if GFX_MGR02_BG_RENDERING > 0
    /*
    ** Perform background layer building (OpenVG / SOftware) and post-processing
    ** operation on eDMA built layers (e.g multi color conversion).
    */
    fl_layer_index = 0;
    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_10)
    while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
          (fl_layer_index            <  l_gfx_mgr02_data_S.visible_num_of_elements))
    {
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_11)
       hmi_gfx_mgr02_bg_render_loop(fl_layer_index);
       fl_layer_index++;
    }
#endif

#if GFX_MGR02_BG_DMA_SEQ_RENDERING == 0
    /*
    ** Wait until the DMA build operations finish
    */
    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_12)
    while(((l_gfx_mgr_vsync_process_mode != GFX_MGR02_PMODE_IDLE) ||
           (l_gfx_mgr_edma_process_mode  != GFX_MGR02_PMODE_IDLE))   && 
          (l_gfx_mgr_shutdown_status     != GFX_MGR02_SHUTDOWN_EMERGENCY))
    {
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_13)
        HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
    }
#endif

#if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
    /*
    ** When the offscreen build option is enabled, the actual address to be
    ** programmed to the DCU is from GFX_MGR02_GRAM_DCU_BASE, so
    ** we have to apply an offset to the GFX_MGR02_GRAM_BASE address to make
    ** in to this region. FILL alone is skipped as we donot build that in to 
    ** GRAM
    */
    fl_layer_index = 0;
    fl_mem_offset  = ((UINT32)(GFX_MGR02_OFSCRN2GRAM_OFFSET));
    while((fl_layer_index            <  l_gfx_mgr02_data_S.visible_num_of_elements) && 
          (l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY))
    {
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_14)
       if(GFX_MGR02_GET_OBJ_TYPE(l_gfx_mgr02_data_S.cur_elem_list_sa[fl_layer_index]->obj_id) != GFX_MGR02_TYPE_FILL)
       {
          l_gfx_virtual_layer[fl_layer_index].CTRLDESCL3.R += fl_mem_offset;
       }
       fl_layer_index++;
    }
    l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_CPY_WBUF2GRAM;
#elif (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_VBLANK)
    /*
    ** If memory overlaps present and GFX_MGR02_BUILD_DCU_VBLANK set, 
    ** then those contents are skipped by the earlier hmi_gfx_mgr02_dma_render_loop
    ** We have to now build them during the vblank period in an effort to
    ** show them without any issues. So here we are changing the 
    ** GFX_MGR02_GRAM_CHUNK_STS_xxxxxxxxx status to 
    ** GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED and then initiating a build again.
    */
    if(fl_overlap_slayer < l_gfx_mgr02_data_S.visible_num_of_elements)
    {
       GFX_MGR02_GRAM_CHUNK * fl_buff_ptr;

       fl_layer_index = 0;

       while((fl_layer_index            <  l_gfx_mgr02_data_S.visible_num_of_elements) && 
             (l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY))
       {
          GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_15)
          fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(fl_layer_index);
          if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
          {
             if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_WAIT_SYNC)
             {
                fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED;
             }
          }
          fl_layer_index++;
       }

       l_gfx_mgr02_data_S.cur_build_layer = fl_overlap_slayer;

       /*
       ** Overlap flag is set so we have to trigger the build for
       ** overlapped content and the layer programming together.
       */
       l_gfx_mgr_vsync_process_mode = (GFX_MGR02_PMODE_START_BUILD|GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU);
    #if (GFX_MGR02_BG_RENDERING > 0) && (GFX_MGR02_NUM_OF_SWDGS > 0) && \
         (defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT) || defined(GFX_MGR02_WDG_ALPHA_CONTROL))
       /*
       ** Perform the multi-color conversion operations after the buffer is 
       ** is built for overlapped layers. This may cause problems as we already
       ** programmed the dcu layers. But we have no other options at this point
       */
       fl_layer_index = fl_overlap_slayer;
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_16)
       while((fl_layer_index            <  l_gfx_mgr02_data_S.visible_num_of_elements) && 
             (l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY))
       {
          GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[fl_layer_index];
          if(GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id) == GFX_MGR02_TYPE_SWIDGET)
          {
             GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP = &lc_swidget_layer_def_S[fl_elem_list_SP->base_id];
             if(fl_widget_desc_SP->rr_engine  == GFX_MGR02_RT_DEFAULT)
             {
                while((l_gfx_mgr02_data_S.cur_build_layer <= fl_layer_index) && 
                      (l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY))
                {
                   /* wait until eDMA build the layer */
                   HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
                   GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_17)
                }
             #if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
                hmi_gfx_mgr02_pp_multicolor_widget(fl_elem_list_SP, fl_layer_index, fl_widget_desc_SP->multicolor);
             #else
                hmi_gfx_mgr02_pp_multicolor_widget(fl_elem_list_SP, fl_layer_index, 0);
             #endif
             }
          }
          GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_18)
          fl_layer_index++;
       }
    #endif
    }
    else
    {
       /*
       ** Now we have all the contents ready so start programming the DCU
       ** by copying the softlayer info to DCU layers
       */
       l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU;
    }
#else
    l_gfx_mgr_vsync_process_mode = GFX_MGR02_PMODE_COPY_SLAYER_TO_DCU;
#endif  /* #if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_VBLANK) */

    gfxlogend(GFX_LOG_DCU_RENDERING);
    /*
    ** Wait for everything to finish before exiting.
    */
    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_19)
    while(((l_gfx_mgr_vsync_process_mode != GFX_MGR02_PMODE_IDLE) ||
           (l_gfx_mgr_edma_process_mode  != GFX_MGR02_PMODE_IDLE))   && 
          (l_gfx_mgr_shutdown_status    != GFX_MGR02_SHUTDOWN_EMERGENCY))
    {
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_20)
       HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
    }
    hmi_gfx_mgr02_mem_done();
    gfxlogend(GFX_LOG_DCU_OVERALL);
#ifdef GFX02_DEBUG_INFO
    gfx_debug("INFO    - hmi_gfx_mgr02_build_screen done!\n");
#endif
}

#ifdef HMI_GFX_MGR02_ENABLE_DCU_TEST
/*============================================================================
**
** Function Name:       void hmi_gfx_mgr02_init_for_EOL_mode(UINT8 enable_test_pattern)
**
** Visibility:          This function is externally visible via the
**                      "hmi_gfx_mgr02.h" header file.
**
** Description:         Function to be called to enable the display and
**                      the DCU so that the display will be active and
**                      can be tested in EOL mode.
**
** Invocation:          Called by the application code prior to entering
**                      EOL mode.
**
** Inputs/Outputs:      The "enable_test_pattern" input parameter will be
**                      used to determine if the colorbar test pattern should
**                      be turned on.  If it is non-zero, the pattern will
**                      be turned on, otherwise it will not.
**
** Critical Section:    None
**
** Created:             27/06/12 by ASHEKHAR
**
** Updated:             27/06/12 by ASHEKHAR
**
**==========================================================================*/
void hmi_gfx_mgr02_init_for_EOL_mode(UINT32 p_enable_test_pattern)
{
  hmi_gfx_mgr02_driver_startup();
  hmi_gfx_mgr02_initialize();
  hmi_gfx_mgr02_driver_enable_dcu();
  if(p_enable_test_pattern != 0)
  {
     hmi_gfx_mgr02_EnableDCUTest();
  }
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_set_process_mode
 ** Visibility:       global (for graphics manager internal use only)
 ** Description:      Sets the current process mode.
 ** Invocation:       By gfx mgr 02 modules
 ** Inputs/Outputs:   l_gfx_mgr_process_mode
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          05-May-2011 by EMANOJ1
 **==========================================================================*/
void hmi_gfx_mgr02_set_process_mode(UINT8 p_process_mode)
{
#ifdef GFX_MGR02_ENABLE_LOG
   if(l_gfx_mgr_edma_process_mode == GFX_MGR02_PMODE_SWAP_GRAM)
   {
      gfxlogend(GFX_LOG_DCU_OFFSCRN_CPY);
   }
#endif
   l_gfx_mgr_edma_process_mode = p_process_mode;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_process_mode
 ** Visibility:       global (for graphics manager internal use only)
 ** Description:      Returns the current process mode.
 ** Invocation:       By gfx mgr 02 modules
 ** Inputs/Outputs:   l_gfx_mgr_process_mode
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          05-May-2011 by EMANOJ1
 **==========================================================================*/
UINT8 hmi_gfx_mgr02_get_process_mode(void)
{
   return(l_gfx_mgr_edma_process_mode);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_control_data_ptr
 ** Visibility:       global (for graphics manager internal use only)
 ** Description:      Returns the control data pointer.
 ** Invocation:       By gfx mgr 02 modules
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          05-May-2011 by EMANOJ1
 **==========================================================================*/
GFX_MGR02_CONTROL_DATA_T * hmi_gfx_mgr02_get_control_data_ptr(void)
{
   return(&l_gfx_mgr02_data_S);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_emergency_shutdown
 ** Visibility:       global (for graphics manager internal use only)
 ** Description:      Sets the shutdown mode type.
 ** Invocation:       By 
 ** Inputs/Outputs:   p_shutdown_req
 ** Critical Section: None.
 ** Created:          06-Dec-2012 by ASHEKHAR
 ** Updated:          06-Dec-2012 by ASHEKHAR
 **==========================================================================*/
void hmi_gfx_mgr02_emergency_shutdown(void)
{
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_EMERGENCY;
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
    /* 
    ** TODO: Temporary fix for the RLE hang issue observed by P42M 
    ** when emergency shutdown is performed while RLE decoding is 
    ** in progress. Currently it is not know how the RLE unit can 
    ** be stopped.
    ** RLE operation is ongoing, so wait until the rle operation
    ** finishes and the RLE ISR does RLE.MCR.B.MDIS = 1
    */
    while(RLE.MCR.B.MDIS == 0)
    {
      /* Do nothing */  
    }
    /* 
    ** Cancel the remaining data transfer on DMA channel. Stop the
    ** executing channel and force the minor loop to be
    ** finished
    */
    (void)DMA_Handler_CancelRequest((dma_channel_num_type)GFX_MGR02_DMA_RLE_READ_CHANNEL);
#endif
    (void)DMA_Handler_CancelRequest((dma_channel_num_type)GFX_MGR02_DMA_CHANNEL);
}


/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_emergency_shutdown_req_active
 ** Visibility:       global (for graphics manager internal use only)
 ** Description:      returns the shutdown mode type.
 ** Invocation:       By 
 ** Inputs/Outputs:   l_gfx_mgr_shutdown_status
 ** Critical Section: None.
 ** Created:          06-Dec-2012 by ASHEKHAR
 ** Updated:          06-Dec-2012 by ASHEKHAR
 **==========================================================================*/
UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
    return(l_gfx_mgr_shutdown_status);
}

#ifndef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
/*============================================================================
** Function Name:    hmi_gfx_mgr02_load_all_clut
** Visibility:       static
** Description:      Loads all the CLUT into the CLUT RAM
** Invocation:       Invoked by GDG02
** Inputs/Outputs:   p_layer_id_U32
** Critical Section: None.
** Created:          03-Jul-2010 by EMANOJ1
** Updated:          17-Jan-2011 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_mgr02_load_all_clut(void)
{
#if GFX_MGR02_NUM_OF_CLUTS > 0
    UINT32         i;
    UINT32         fl_top_index_U32  = 0;
    UINT32       * fl_clut_ram_U32AP = (UINT32 *)(void *)&DCU.CLUT[0];
    UINT32 const * fl_clut_rom_U32AP;
    UINT32         fl_clut_size_U32;
    GFX_MGR02_CLUT_DATA const * fl_clut_config_SP = &lc_gfx_mgr02_clut_array[0];
    for (i=0; i < GFX_MGR02_NUM_OF_CLUTS; i++)
    {
        l_clut_items_U16A[i] = (UINT16)fl_top_index_U32;
        fl_clut_rom_U32AP    = fl_clut_config_SP->CLUT;
        fl_top_index_U32    += fl_clut_config_SP->CLUTsize; /* find the next CLUT index */
        fl_clut_size_U32     = fl_clut_config_SP->CLUTsize;
        /*
        ** If the next index is <= DCU3_CLUT_NUM_ENTRIES means that the current
        ** copy will do only till < DCU3_CLUT_NUM_ENTRIES and there fore we will
        ** not overflow CLUT RAM in the copy.
        */
        if(fl_top_index_U32 <= DCU3_CLUT_NUM_ENTRIES)
        {
            while(fl_clut_size_U32 > 0)
            {
                fl_clut_size_U32--;
                *fl_clut_ram_U32AP = *fl_clut_rom_U32AP;
                fl_clut_ram_U32AP = &fl_clut_ram_U32AP[1];
                fl_clut_rom_U32AP = &fl_clut_rom_U32AP[1];
            }
        }
    #ifdef GFX02_DEBUG_ERROR
        else
        {
            gfx_debug("ERROR   - Total CLUT entries exceeded DCU3_CLUT_NUM_ENTRIES.\n");
            gfx_debug("          All cluts are not loaded. Use option GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED.\n");
        }
    #endif
        fl_clut_config_SP = &fl_clut_config_SP[1];
    }
#endif
}
#else
/*============================================================================
** Function Name:    hmi_gfx_mgr02_load_active_cluts
** Visibility:       static
** Description:      Loads active layers CLUT into the CLUT RAM
** Invocation:       Invoked internally when ever CLUT needs to be loaded
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          21-Mar-2012 by ASHEKHAR
** Updated:          21-Mar-2014 by EMANOJ1
**==========================================================================*/
static void hmi_gfx_mgr02_load_active_cluts(void)
{
#if GFX_MGR02_NUM_OF_CLUTS > 0
   UINT32 fl_clut_offset = 0;
   UINT16 fl_loaded_clut_id_table_UA[GFX_MGR02_NUM_DCU_LAYERS];
   UINT16 fl_already_loaded_clut_id;
   UINT32 i;
   UINT32 j;
   UINT32 fl_num_loaded_clut=0;
   UINT32 fl_to_be_loaded_clut_id;
   UINT32 fl_clut_loaded_offset;
   GFX_MGR02_CLUT_DATA const * fl_clut_config_SP;
   UINT32              const * fl_clut_rom_U32AP;
   /*
   ** To avoid loss of voltatile qualification of &DCU.CLUT[0]
   */
   GFX_VUINT32                   * fl_output_U32AP = &DCU.CLUT[0];

   for(i=0; i < GFX_MGR02_NUM_DCU_LAYERS; i++)
   {
      fl_to_be_loaded_clut_id = l_gfx_virtual_layer[i].CTRLDESCL4.B.LUOFFS;
      if((l_gfx_virtual_layer[i].CTRLDESCL4.B.EN != 0) && (fl_to_be_loaded_clut_id < GFX_MGR02_NUM_OF_CLUTS))
      {
         /*
         ** Check whether the requested CLUT is already loaded to the CLUT RAM
         ** by searching fl_loaded_clut_id_table_UA[] array.
         */
         fl_clut_loaded_offset=0;
         for(j=0; j < fl_num_loaded_clut; j++)
         {
            fl_already_loaded_clut_id = fl_loaded_clut_id_table_UA[j];
            if(fl_already_loaded_clut_id == fl_to_be_loaded_clut_id)
            {
               /*
               ** The requested CLUT is already loaded so we only need
               ** to set the offset of the already loaded clut.
               ** No need to perform a GfxMgrLoadCLUT in this case
               */
               l_gfx_virtual_layer[i].CTRLDESCL4.B.LUOFFS = fl_clut_loaded_offset;
               break;
            }
            else
            {
               fl_clut_loaded_offset += lc_gfx_mgr02_clut_array[fl_already_loaded_clut_id].CLUTsize;
            }
         }
         if(j == fl_num_loaded_clut)
         {
            fl_clut_config_SP = &lc_gfx_mgr02_clut_array[fl_to_be_loaded_clut_id];
            /*
            ** fl_to_be_loaded_clut_id not present in the loaded CLUT list
            ** so we need to perform a CLUT loading in addition to the offset
            ** setting.
            */
            l_gfx_virtual_layer[i].CTRLDESCL4.B.LUOFFS = fl_clut_offset;

            /*
            ** Verify that the CLUT offset + CLUT size does not exceed the size
            ** of the CLUT RAM.
            */
            fl_clut_offset += fl_clut_config_SP->CLUTsize;
            if (fl_clut_offset <= GFX_MGR02_MAX_CLUT_INDEX)
            {
              /*
              ** Load the specified CLUT into the CLUT RAM at the specified offset.
              */
              fl_clut_rom_U32AP = fl_clut_config_SP->CLUT;
              for (j = 0; j < fl_clut_config_SP->CLUTsize; j++)
              {
                *fl_output_U32AP = *fl_clut_rom_U32AP;
                fl_clut_rom_U32AP = &fl_clut_rom_U32AP[1];
                fl_output_U32AP = &fl_output_U32AP[1];
              }
            }
            else
            {
            #ifdef GFX02_DEBUG_ERROR
               gfx_debug("ERROR   - Total CLUT entries exceeded DCU3_CLUT_NUM_ENTRIES.\n");
               gfx_debug("          All cluts are not loaded. Revist the design.\n");
            #endif
               /*
               ** Disable the layer as the CLUT cannot be loaded for this layer
               */
               l_gfx_virtual_layer[i].CTRLDESCL4.B.EN = 0;
            }
            fl_loaded_clut_id_table_UA[fl_num_loaded_clut] = (UINT16)fl_to_be_loaded_clut_id;
            fl_num_loaded_clut++;
         }
      }
      else
      {
         l_gfx_virtual_layer[i].CTRLDESCL4.B.LUOFFS = 0x00u;
      }
   }
#endif
}
#endif

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_text_layer_area
 ** Visibility:       static
 ** Description:      fetches the Text elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          05-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_get_text_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ELEMENT_AREA * p_elem_area)
{
   UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
   UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
   UINT32 fl_base_id  = p_elem_list_SP->base_id;
   UINT8  fl_valid_text = 0;
   UINT32 fl_font_id;
   UINT32 fl_alignment;
   UINT32 fl_clip_mode;
   UINT32 fl_divisor;
   UINT32 fl_text_font_format;
   UINT32 fl_remainder;
   GFX_MGR02_FONT       const * fl_font_SP;
   GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = &lc_text_layer_def_S[fl_base_id];
   GFX_MGR02_ISIZE_W_T fl_text_width = 0;

   p_elem_area->ex = 0x00;
   p_elem_area->ey = 0x00;
   p_elem_area->is_transparent = GFX_MGR02_TRANSPARENT;

   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
   {
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
     GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_prop_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
     fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_prop_SP->font_id);
     p_elem_area->sx = fl_text_prop_SP->coord.y;
#if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1)
     p_elem_area->sy = fl_text_prop_SP->coord.x - fl_font_SP->p.height;
#else
     p_elem_area->sy = fl_text_prop_SP->coord.x;
#endif
#else
     p_elem_area->sx = fl_text_prop_SP->coord.x;
     p_elem_area->sy = fl_text_prop_SP->coord.y;
#endif
     fl_font_id      = fl_text_prop_SP->font_id;
     fl_alignment    = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_prop_SP->alignment);
     fl_clip_mode    = fl_text_prop_SP->clip_mode;
     fl_text_width   = fl_text_prop_SP->width;
     hmi_gfx_mgr02_context_set_alpha(fl_text_prop_SP->alpha);
#endif
   }
   else
   {
#if GFX_MGR02_NUM_TEXT_INSTANCES > 0
     GFX_MGR02_TEXT_PROPERTY const * fl_text_prop_SP = &lc_text_const_property_S[fl_obj_id];
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
     fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_SP->font_id);
     p_elem_area->sx = fl_text_prop_SP->coord.y;
#if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1)
     p_elem_area->sy = fl_text_prop_SP->coord.x - fl_font_SP->p.height;
#else
     p_elem_area->sy = fl_text_prop_SP->coord.x;

#endif
#else
     p_elem_area->sx = fl_text_prop_SP->coord.x;
     p_elem_area->sy = fl_text_prop_SP->coord.y;
#endif
     fl_font_id      = fl_text_desc_SP->font_id;
     fl_alignment    = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_SP->alignment);
     fl_clip_mode    = fl_text_desc_SP->clip_mode;
     fl_text_width   = fl_text_desc_SP->width;
     hmi_gfx_mgr02_context_set_alpha(fl_text_prop_SP->alpha);
#endif
   }

   fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
   
   if(fl_font_SP != GFX_MGR02_NULL_PTR)
   {
   #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
      if((fl_font_SP->is_ffile == 0) && (fl_font_SP->is_vfont == 0))
   #else
      if(fl_font_SP->is_vfont == 0)  /* vector fonts not supported for edma printing */
   #endif
      {
         GFX_MGR02_TEXT_INFO  fl_text_info_S;

         fl_text_font_format   = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);
         fl_text_font_format >>= 2;
         /*
         ** Based on actual string width calculate the endx and endy
         ** If text property is Normal, then its not transparent and full width
         ** needs to be considered.
         */
         if(fl_text_desc_SP->dynamic != 0)
         {
         #if GFX_MGR02_NUM_OF_DTEXTS > 0
            fl_text_info_S.print_str_P = &l_layer_anim_data_SP->dtext_str[fl_text_desc_SP->string_index];
         #else
            fl_text_info_S.print_str_P = NULL; 
         #endif
         }
         else
         {
         #if GFX_MGR02_NUM_OF_STEXTS > 0
            fl_text_info_S.print_str_P = (void *)&lc_static_text_buffer[fl_text_desc_SP->string_index];
         #else
            fl_text_info_S.print_str_P = NULL;            
         #endif
         }
          
         fl_text_info_S.max_available_width = fl_text_width;
         fl_text_info_S.target              = GFX_MGR02_TARGET_DCU;

#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
         fl_text_info_S.append_str          = TRUE;
#else
         fl_text_info_S.append_str          = FALSE;
#endif
#if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
         fl_text_info_S.scroll = lc_text_layer_def_S[p_elem_list_SP->base_id].scroll;
#endif
         fl_text_info_S.num_chars_to_process = fl_text_desc_SP->num_chars;
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
         fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
#endif
         if(fl_text_info_S.print_str_P != NULL)
         {
           (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                              fl_font_id,
                                              fl_clip_mode,
                                              fl_alignment
                                              #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                              ,GFX_MGR02_NULL_PTR
                                              #endif
                                              );

           if((fl_text_info_S.print_width != 0x00) && (fl_text_font_format <= GFX_MGR02_8BPP))
           {
              GFX_MGR02_VISIBLE_AREA fl_visible_area;
    
              p_elem_area->ex = fl_text_info_S.print_width;
              p_elem_area->ey = fl_font_SP->p.height;

              if(p_elem_area->ex > fl_text_width)
              {
                 p_elem_area->ex = (SINT16)fl_text_width;
              }


              fl_visible_area.sx = p_elem_area->sx;
              fl_visible_area.sy = p_elem_area->sy;
              fl_visible_area.ex = p_elem_area->ex;
              fl_visible_area.ey = p_elem_area->ey;

              hmi_gfx_mgr02_get_printable_text_area(fl_text_desc_SP->alignment, fl_alignment, fl_text_width, &fl_visible_area); 

              p_elem_area->sx = fl_visible_area.sx;
              p_elem_area->sy = fl_visible_area.sy;
              p_elem_area->ex = fl_visible_area.ex;
              p_elem_area->ey = fl_visible_area.ey;

#if !defined(GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED)
              if(GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes) == GFX_MGR02_FONT_ENCODING_4BPP)
              {
                 if((p_elem_area->sx & 1) != 0)
                 {
                    /*
                    ** Inside widget, the 4BPP texts cannot be rendered on odd X location
                    ** due to the fact that eDMA can copy only to byte boundaries. But text
                    ** layers has no problem since text layer is displayed via DCU layer
                    ** But when text layer is shown along with a text inside a widget, it
                    ** may become a problem. So here we are making the odd co-ordinate to
                    ** even for the text layer, so that they also behave same as a text in
                    ** a widget.
                    */
                    p_elem_area->sx--;
                 }
              }
           #endif
              fl_divisor   = lc_dcu_image_width_byte_U8A[fl_text_font_format];
           #if defined(GFX_MGR02_FARADAY) || defined(CWR_MPC5645S_LITE) || defined(CWR_MPC5645S)
              /* 
              ** Force 64bit alignment for rainbow/faraday 
              ** Otherwise if we perform any vclip animations on this objcet there are
              ** chances that the address will loose the alignment and the DCU will not
              ** display the graphic properly. lc_dcu_image_width_byte_U8A[] is by defaullt
              ** for 32bit alignment so x2 will make it 64bit
              */
              fl_divisor <<= 1; 
           #endif
              fl_remainder = (p_elem_area->ex % fl_divisor);
              if(fl_remainder != 0)
              {
                 p_elem_area->ex += (SINT16)(fl_divisor - fl_remainder);
              }
              if(p_elem_area->ex != 0x00)
              {
                 /* 
                 ** make it visible only if it is visible 
                 */
                 GFX_MGR02_ILOC_DATA fl_loc;
                 if(fl_text_desc_SP->draw_mode == GFX_MGR02_TP_DRAW_TRANSP)
                 {
                    p_elem_area->is_transparent = GFX_MGR02_SEETHROUGH;
                 }
                 else
                 {
                    p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
                 }
      
                 #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)
                   fl_loc.x = p_elem_area->sx;
                   p_elem_area->sx = p_elem_area->sy;
                   p_elem_area->sy = fl_loc.x;

                   fl_loc.x = p_elem_area->ex;
                   p_elem_area->ex = p_elem_area->ey;
                   p_elem_area->ey = fl_loc.x;
                 #endif

                 fl_loc.x = p_elem_area->sx;
                 fl_loc.y = p_elem_area->sy;
                 hmi_gfx_mgr02_context_set_loc(&fl_loc);
              }
           }
         }
      }
   }
}



/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_printable_text_area
 ** Visibility:       static
 ** Description:      Calculates the text element area based on current alignment and rotation type.
                      For clockwise rotation, text is rendered from the last character. Hence the area
                      calculation is changed to handle this as below
                        Left and Right  -  Location should be moved to opposite end of the text
                        Center          -  No change required
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_VISIBLE_AREA p_visible_area  -> Area to be updated
                          p_visible_area->ex - Must contain the print width
                     GFX_MGR02_ISIZE_W_T p_text_width       -> Text box width,
                     UINT32 p_alignment_designed            -> Textbox alignment designed in GDT tool
                     UINT32 p_alignment_updated             -> Textbox alignment updated through API
 ** Critical Section: None.
 ** Created:          05-Jun-2018 by ARAJASE2
 ** Updated:          05-Jun-2018 by ARAJASE2
 **==========================================================================*/
static void hmi_gfx_mgr02_get_printable_text_area(UINT32 p_alignment_designed, UINT32 p_alignment_updated,
                                                  GFX_MGR02_ISIZE_W_T p_text_width,
                                                  GFX_MGR02_VISIBLE_AREA * p_visible_area)
{
  if(p_alignment_updated == GFX_MGR02_TP_ALIGN_CENTRE)
  {
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
    /* 
    ** handle case where the current alignment is different than default alignment 
    */
    if(p_alignment_designed == GFX_MGR02_TP_ALIGN_LEFT)
    {
      /*When we go from Center alignment to Left, sx is changed to top most end of the text box*/
    #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx -= (SINT16)(p_text_width>>1);
    #else
      p_visible_area->sx += (SINT16)(p_text_width>>1);
    #endif
    }
    else if(p_alignment_designed == GFX_MGR02_TP_ALIGN_RIGHT)
    {
    #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx += (SINT16)(p_text_width>>1);
      p_visible_area->sx -= 1;
    #else
      /* Since centre aligned the generated width should be divided by 2 */ 
      p_visible_area->sx -= (SINT16)(p_text_width>>1);
      /* Since for right aligned text the generated start x from the tool will be 1 pixel less.  */
      p_visible_area->sx += 1;
    #endif
    }
    else
    {
    	/*For MISRA warning fix.*/
    }
    #endif
    p_visible_area->sx = (SINT16)(p_visible_area->sx - (p_visible_area->ex / 2));
  }
  else if(p_alignment_updated == GFX_MGR02_TP_ALIGN_RIGHT)
  {
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
    if(p_alignment_designed == GFX_MGR02_TP_ALIGN_LEFT)
    {
      #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx -= (SINT16)(p_text_width);
      #else
      p_visible_area->sx += (SINT16)(p_text_width);
      #endif
    }
    else if(p_alignment_designed == GFX_MGR02_TP_ALIGN_CENTRE)
    {
      #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx -= (SINT16)(p_text_width >> 1);
      #else
      p_visible_area->sx += (SINT16)(p_text_width >> 1);
      #endif
    }
    else
    {
    	/*For MISRA warning fix.*/
    }
    #endif
    #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
    p_visible_area->sx--;
    #else
    p_visible_area->sx = (SINT16)(p_visible_area->sx - p_visible_area->ex);
    p_visible_area->sx++;
    #endif
  }
  else
  {
    #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
    if(p_alignment_designed == GFX_MGR02_TP_ALIGN_CENTRE)
    {
      #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx += (SINT16)(p_text_width>>1);
      #else
      p_visible_area->sx -= (SINT16)(p_text_width>>1);
      #endif
    }
    else if(p_alignment_designed == GFX_MGR02_TP_ALIGN_RIGHT)
    {
      #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
      p_visible_area->sx += p_text_width;
      /* Since for right aligned text the generated start x from the tool will be 1 pixel less.  */
      p_visible_area->sx--;
      #else
      p_visible_area->sx -= p_text_width;
      /* Since for right aligned text the generated start x from the tool will be 1 pixel less.  */
      p_visible_area->sx++;
      #endif
    }
    else
    {
    	/*For MISRA warning fix.*/
    }
    #endif
    #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 1))
    p_visible_area->sx -= p_visible_area->ex;
    #endif
  }
}
#endif /* GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_tile_fill_layer_area
 ** Visibility:       static
 ** Description:      fetches the Tile, Fill elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          05-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_get_tile_fill_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ELEMENT_AREA * p_elem_area)
{
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32 fl_base_id  = p_elem_list_SP->base_id;
    
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
        if(fl_obj_type == GFX_MGR02_TYPE_TILE)
        {
        #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
            hmi_gfx_mgr02_context_set_loc(&l_layer_anim_data_SP->tile_prop[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha(l_layer_anim_data_SP->tile_prop[fl_obj_id].alpha);
            p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.width;
            p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.height;
            p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
            hmi_gfx_mgr02_context_set_loc(&l_layer_anim_data_SP->fill_prop[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha(l_layer_anim_data_SP->fill_prop[fl_obj_id].alpha);
            p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.width;
            p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.height;
            p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
        #endif
        }
    }
    else
    {
        if(fl_obj_type == GFX_MGR02_TYPE_TILE)
        {
        #if GFX_MGR02_NUM_TILE_INSTANCES > 0
            hmi_gfx_mgr02_context_set_loc(&lc_tile_const_property_S[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha(lc_tile_const_property_S[fl_obj_id].alpha);
            p_elem_area->ex      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.width;
            p_elem_area->ey      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.height;
            p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_INSTANCES > 0
            hmi_gfx_mgr02_context_set_loc(&lc_fill_const_property_S[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha(lc_fill_const_property_S[fl_obj_id].alpha);
            p_elem_area->ex      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.width;
            p_elem_area->ey      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.height;
            p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
        #endif
        }
    }
}

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) /*sbollam*/
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_image_layer_area
 ** Visibility:       static
 ** Description:      fetches the Image elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          05-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    GFX_MGR02_IMAGE_DEF_T const * fl_image_layer_def_SP = GFX_MGR02_NULL_PTR;

#if GFX_MGR02_NUM_USER_LAYERS > 0
    if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
    {
       fl_image_layer_def_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
       #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
           GFX_MGR02_IMAGE_DYN_PROPERTY * fl_img_dyn_prop_SP = &l_layer_anim_data_SP->user_prop[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_dyn_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha(fl_img_dyn_prop_SP->alpha);
       #endif
       }
       else
       {
       #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
           GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha(fl_img_prop_SP->alpha);
       #endif
       }
    }
    else
#endif
    {
    #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
       fl_image_layer_def_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
       if(fl_image_layer_def_SP !=GFX_MGR02_NULL_PTR )
       {
         if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
         {
         #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
             GFX_MGR02_IMAGE_DYN_PROPERTY * fl_img_dyn_prop_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
             hmi_gfx_mgr02_context_set_loc(&fl_img_dyn_prop_SP->coord);
             hmi_gfx_mgr02_context_set_alpha(fl_img_dyn_prop_SP->alpha);
         #endif
         }
         else
         {
         #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
             GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
             hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
             hmi_gfx_mgr02_context_set_alpha(fl_img_prop_SP->alpha);
         #endif
         }
         if(fl_image_layer_def_SP->vaoa_index != 0)
         {
             fl_vaof_index = fl_image_layer_def_SP->vaoa_index;
         }
       }
    #endif
    }
    if(fl_image_layer_def_SP != GFX_MGR02_NULL_PTR)
    {
       p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
       p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
       p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
    }
    return(fl_vaof_index);
}
#endif /* (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) */

#if GFX_MGR02_NUM_OF_SWDGS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_widget_layer_area
 ** Visibility:       static
 ** Description:      fetches the Widget elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T, Visible Area Offset
 ** Critical Section: None.
 ** Created:          05-Nov-2012 by ASHEKHAR
 ** Updated:          05-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                  GFX_MGR02_ELEMENT_AREA      * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32 fl_base_id    = p_elem_list_SP->base_id;
    GFX_MGR02_WIDGET_DEF_T const * fl_widget_layer_def_SP = &lc_swidget_layer_def_S[fl_base_id];
    GFX_MGR02_IMAGE_DEF_T  const * fl_image_layer_def_SP;

    if((fl_widget_layer_def_SP->rr_engine == GFX_MGR02_RT_OPENVG) && 
       (fl_widget_layer_def_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE))
    {
    #if (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0) && defined(GFX_MGR02_OPEN_VG)
       /*
       ** For OpenVG rendering mode, if clip not set, then the
       ** widget area needs to be calculated dynamically based
       ** current transformed bounds of the widget layer
       ** For this to work the element has to be animation enabled, so that
       ** its XY location can be modified.
       ** After the bound is calculated, it needs to be loaded to l_runtime_wdg_image_layer_def_S
       ** which is placed in RAM.
       */
       fl_image_layer_def_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_layer_def_SP->image_id];
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
       #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
          GFX_FLOAT  fl_bound[4];
          UINT32 fl_aligned_width;
          UINT32 fl_aligned_height;

          GFX_MGR02_WIDGET_DYN_PROPERTY * fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];

          hmi_gfx_mgr02_generic_get_element_bound(p_elem_list_SP, GFX_MGR02_TARGET_OPENVG, fl_bound);
          fl_widg_dyn_prop_SP->coord.x    = (SINT16)fl_bound[0];
          fl_widg_dyn_prop_SP->coord.y    = (SINT16)fl_bound[1];
          fl_bound[0] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.x; /* get any remaining fractional part */
          fl_bound[1] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.y;
          
          fl_aligned_width  = (UINT32)(fl_bound[2]+fl_bound[0]+0.5f);
          fl_aligned_height = (UINT32)(fl_bound[3]+fl_bound[1]+0.5f);
          
       #if GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES > 1
          /*
          ** Perform alignment of width since target ovg libraries have byte
          ** alignment requirement for framebuffer width.
          */
          if(fl_widget_layer_def_SP->fb_format == GFX_MGR02_PIX_FORMAT_ARGB8888)
          {
             fl_aligned_width += (GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES-1);
             fl_aligned_width &= (UINT32)~(GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES-1);
          }
          else
          {
             /* assume everything else as 16bit (RGB565, ARGB4444, ARGB1555) */
             fl_aligned_width += ((GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES*2)-1);
             fl_aligned_width &= (UINT32)~((GFX_MGR02_OVG_BUFFER_W_ALIGN_BYTES*2)-1);
          }
       #endif
          if(fl_aligned_width > fl_image_layer_def_SP->width)
          {
             ((GFX_MGR02_IMAGE_DEF_T *)(fl_image_layer_def_SP))->width  = (GFX_MGR02_ISIZE_W_T)(fl_aligned_width);
          }
          if(fl_aligned_height > fl_image_layer_def_SP->height)
          {
             ((GFX_MGR02_IMAGE_DEF_T *)(fl_image_layer_def_SP))->height = (GFX_MGR02_ISIZE_H_T)(fl_aligned_height);
          }
       #endif
       }            
       else
       {
          ((GFX_MGR02_IMAGE_DEF_T *)(fl_image_layer_def_SP))->width  = 0;
          ((GFX_MGR02_IMAGE_DEF_T *)(fl_image_layer_def_SP))->height = 0;
       }
       p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
       p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
       if(fl_image_layer_def_SP->vaoa_index != 0)
       {
          fl_vaof_index = fl_image_layer_def_SP->vaoa_index;
       }
    #else
       /*
       ** Not a valid configuration & never expected to run. 
       ** Make the layer invisible
       */
       p_elem_area->ey  = -1;
       p_elem_area->ex  = -1;
    #endif
    }
    else
    {
       fl_image_layer_def_SP = &lc_image_layer_def_S[fl_widget_layer_def_SP->image_id];
       p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
       p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
       if(fl_image_layer_def_SP->vaoa_index != 0)
       {
          fl_vaof_index = fl_image_layer_def_SP->vaoa_index;
       }
    }

    if(fl_widget_layer_def_SP->merge != 0)
    {
       p_elem_area->is_transparent = GFX_MGR02_OPEQUE;
    }

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
        GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
        GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
        GFX_MGR02_ILOC_DATA               fl_coord;

        hmi_gfx_mgr02_context_set_alpha(fl_widg_dyn_prop_SP->alpha);

     #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        if(fl_widget_layer_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
        {
            /*
            ** Widget co-ordinates indicate actual location, so
            ** subtract default xy to get offset value. because
            ** when we set the clip we will be adding the offset
            ** location to it as well to make the clip also shifted
            ** This means when hmi_gfx_mgr02_context_set_clip is invoked
            ** the context location shall contain an offset value
            */
            fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id];
            fl_coord.x      = (SINT16)(-fl_elem_prop_SP->coord.x);
            fl_coord.y      = (SINT16)(-fl_elem_prop_SP->coord.y);
            hmi_gfx_mgr02_context_set_loc(&fl_coord);
            hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
            hmi_gfx_mgr02_context_set_clip(&fl_widg_dyn_prop_SP->clip);
            /*
            ** Once the clip is updated we need to make the co-ordinates to actual
            ** XY location by adding the default value again. This is needed
            ** only if the widget is merge layer type widget. For keep
            ** layer type widget, the location can remail as offset value.
            */
            if(fl_widget_layer_def_SP->merge != 0)
            {
               fl_coord.x = -fl_coord.x;
               fl_coord.y = -fl_coord.y;
               hmi_gfx_mgr02_context_set_loc(&fl_coord);
            }
        }
        else
     #endif
        if(fl_widget_layer_def_SP->merge == 0)
        {
            /*
            ** Widget co-ordinates indicate actual location, so
            ** subtract default xy to get offset value incase if this
            ** widget is a keep layer type widget.
            */
            fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id];
            fl_coord.x      = (SINT16)(-fl_elem_prop_SP->coord.x);
            fl_coord.y      = (SINT16)(-fl_elem_prop_SP->coord.y);
            hmi_gfx_mgr02_context_set_loc(&fl_coord);
            hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
        }
        else
        {
           hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
        }
    #endif
    }
    else
    {
    #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
        if(fl_widget_layer_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
        {
           if(fl_widget_layer_def_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
           {             
              GFX_MGR02_IAREA_DATA fl_clip_area_SP;
              fl_clip_area_SP.x       = lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].sx;
              fl_clip_area_SP.y       = lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].sy;
              fl_clip_area_SP.width   = (UINT16)lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].ex;          
              fl_clip_area_SP.height  = (UINT16)lc_elem_area_offset_SA[fl_widget_layer_def_SP->clip_index].ey;
              hmi_gfx_mgr02_context_set_clip(&fl_clip_area_SP); 
           }   
        }
        if(fl_widget_layer_def_SP->merge != 0)
        {
           hmi_gfx_mgr02_context_set_loc(&lc_swdg_const_property_S[fl_obj_id].coord);
        }
        hmi_gfx_mgr02_context_set_alpha(lc_swdg_const_property_S[fl_obj_id].alpha);
    #endif 
    }
    return(fl_vaof_index);
}
#endif  /* GFX_MGR02_NUM_OF_SWDGS */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_is_child_visible
 ** Visibility:       static
 ** Description:      Determines whether a passed layer is visible or not.
 **                   A passed area is checked against each element above it to
 **                   determine if it is hidden or not. Incase the passed area
 **                   is partially hidden, the exposed area will be again examined
 **                   recursively to see the overall hidden or visible status.
 **                   For example for a reactangle area X, and if there are 5 elements
 **                   above it (elem 1 to 5). Now if elem 1 covers only a small area c
 **                   as shown below
 **                   -----------------
 **                   +               +
 **                   + a             +
 **                   +-------+++++++++
 **                   +\\\c\\\+   b   +
 **                   -----------------
 **                   this function will recursively check for the exposed sub area
 **                   'a' (Visible top portion) and 'b' (Visible Right portion) seperately
 **                   against elem 2 to 5 to see if they are getting
 **                   hidden or not.  So after the recursive loop finally determines that
 **                   a passed area is fully hidden it returns FALSE else it returns TRUE.
 **                   02_design\hmi_gfx_mgr02_design.xls implements a xls macro to proveout
 **                   this logic.
 ** Invocation:       By hmi_gfx_mgr02_manage_layers().
 ** Inputs/Outputs:   p_area          - Pointer to area of the element
 **                   p_elem_list_SAP - Pointer to the element list above.
 **                   p_num_elements  - number of elements in p_elem_list_SAP.
 ** Critical Section: None.
 ** Created:          05-May-2011 by EMANOJ1
 ** Updated:          18-Jul-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT32 p_num_elements,
                                                           struct DCU_LAYER_tag  * p_vir_layer_SP)
{
    UINT32                  fl_layer_visible = HMI_GFX_MGR02_ELEMENT_INVALID;
    GFX_MGR02_ELEMENT_AREA  fl_area;
    GFX_MGR02_ELEMENT_AREA  fl_area2;
    SINT16                  fl_temp;

    while((fl_layer_visible == HMI_GFX_MGR02_ELEMENT_INVALID) && (p_num_elements > 0))
    {
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_21)
        fl_area.sx    = (SINT16)p_vir_layer_SP->CTRLDESCL2.B.POSX;
        fl_area.sy    = (SINT16)p_vir_layer_SP->CTRLDESCL2.B.POSY; 
        fl_area.ex    = (SINT16)p_vir_layer_SP->CTRLDESCL1.B.WIDTH; 
        fl_area.ey    = (SINT16)p_vir_layer_SP->CTRLDESCL1.B.HEIGHT; 
        fl_area.alpha = (UINT8)p_vir_layer_SP->CTRLDESCL4.B.TRANS;

        if(p_vir_layer_SP->CTRLDESCL4.B.TRANS == 0)
        {
            fl_area.is_transparent = GFX_MGR02_TRANSPARENT;
        }
        else if((p_vir_layer_SP->CTRLDESCL4.B.BB != 0) || (p_vir_layer_SP->CTRLDESCL4.B.TRANS < 255))
        {
            fl_area.is_transparent = GFX_MGR02_SEETHROUGH;
        }
        else
        {
            fl_area.is_transparent = GFX_MGR02_OPEQUE;
        }

        p_num_elements--;
        p_vir_layer_SP++;

        if(fl_area.is_transparent == GFX_MGR02_OPEQUE)
        {
            if((fl_area.sx <= p_area->sx) && (fl_area.sy <= p_area->sy) &&
               (fl_area.ex >= p_area->ex) && (fl_area.ey >= p_area->ey))
            {
                /*
                ** p_area is completely hidden in fl_area
                */
                fl_layer_visible = HMI_GFX_MGR02_ELEMENT_INVISIBLE;
            }
            else if( ((fl_area.sx >= p_area->sx) && (fl_area.sx <= p_area->ex)) ||
                     ((fl_area.ex >= p_area->sx) && (fl_area.ex <= p_area->ex)) ||
                     ((fl_area.sx <  p_area->sx) && (fl_area.ex >  p_area->ex)) )
            {
                if( ((fl_area.sy >= p_area->sy) && (fl_area.sy <= p_area->ey)) ||
                    ((fl_area.ey >= p_area->sy) && (fl_area.ey <= p_area->ey)) ||
                    ((fl_area.sy <  p_area->sy) && (fl_area.ey >  p_area->ey)) )
                {
                    /*
                    ** Layer is overlapping.
                    */
                    fl_area2.sx = p_area->sx;
                    fl_area2.sy = p_area->sy;
                    fl_area2.ex = p_area->ex;
                    fl_area2.ey = p_area->ey;
                    fl_area2.is_transparent = p_area->is_transparent;

                    if(fl_area.sy > p_area->sy)
                    {
                        /*
                        ** Visible top portion of the p_area rectangle
                        */
                        fl_area2.ey      = (SINT16)(fl_area.sy - 1);
                        fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_area2, p_num_elements, p_vir_layer_SP);
                        fl_area2.sy      = fl_area.sy;
                        fl_area2.ey      = p_area->ey;
                    }
                    if((fl_area.ey < p_area->ey) && (fl_layer_visible != HMI_GFX_MGR02_ELEMENT_VISIBLE))
                    {
                        /*
                        ** Visible bottom portion of the p_area rectangle
                        */
                        fl_temp          = fl_area2.sy;
                        fl_area2.sy      = (SINT16)(fl_area.ey + 1);
                        fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_area2, p_num_elements, p_vir_layer_SP);
                        fl_area2.sy      = fl_temp;
                        fl_area2.ey      = fl_area.ey;
                    }
                    if((fl_area.sx > p_area->sx) && (fl_layer_visible != HMI_GFX_MGR02_ELEMENT_VISIBLE))
                    {
                        /*
                        ** Visible Left portion of the p_area rectangle
                        */
                        fl_area2.ex      = (SINT16)(fl_area.sx - 1);
                        fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_area2, p_num_elements, p_vir_layer_SP);
                        fl_area2.ex      = p_area->ex;
                        fl_area2.sx      = fl_area.sx;
                    }
                    if((fl_area.ex < p_area->ex) && (fl_layer_visible != HMI_GFX_MGR02_ELEMENT_VISIBLE))
                    {
                        /*
                        ** Visible Right portion of the p_area rectangle
                        */
                        fl_area2.sx      = (SINT16)(fl_area.ex+1);
                        fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_area2, p_num_elements, p_vir_layer_SP);
                    }
                }
                /*
                ** ELSE - Layer is not overlapping with fl_area so need to proceed to
                **        next element in p_elem_list_SAP to see if that is overlapping.
                */
            }
            else
            {
               /* QAC fix... */
            }
            /*
            ** ELSE - Layer is not overlapping with fl_area so need to proceed to
            **        next element in p_elem_list_SAP to see if that is overlapping.
            */
        }
    }
    if(fl_layer_visible == HMI_GFX_MGR02_ELEMENT_INVALID)
    {
       fl_layer_visible = HMI_GFX_MGR02_ELEMENT_VISIBLE;
    }
    return(fl_layer_visible);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_child
 ** Visibility:       static
 ** Description:      This function copy the passed child element after verifying
 **                   that it is visible 
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          14-Feb-2013 by EMANOJ1
 ** Updated:          14-Feb-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layer_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32 fl_base_id    = p_elem_list_SP->base_id;
    UINT32 fl_text_width = 0;
#if GFX_MGR02_NUM_OF_SWDGS > 0
    GFX_MGR02_ELEM_LIST_T const  * fl_elem_list_SP;
    UINT32                         fl_num_of_elem;
#endif
    GFX_MGR02_CONTEXT_STATE_T      fl_cur_context_S;
    GFX_MGR02_VISIBLE_AREA const * fl_area_offset_SP = GFX_MGR02_NULL_PTR;
    GFX_MGR02_ELEMENT_AREA         fl_elem_area;
    GFX_MGR02_ANIM_DATA_T        * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    GFX_MGR02_CONTEXT_T          * fl_context_SP   = hmi_gfx_mgr02_context_get_ptr();

    fl_elem_area.is_transparent = GFX_MGR02_TRANSPARENT;

    hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);

    switch(fl_obj_type)
    {
    #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0)
        case GFX_MGR02_TYPE_DWIDGET:
        case GFX_MGR02_TYPE_DIMAGE:
        {
        #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
            if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
               hmi_gfx_mgr02_context_set_loc(&fl_anim_prop_SP->group_loc[fl_obj_id]);
               hmi_gfx_mgr02_context_set_alpha(fl_anim_prop_SP->group_alpha[fl_obj_id]);
            }
        #endif
            if(fl_obj_type == GFX_MGR02_TYPE_DWIDGET)
            {
            #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
                p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_swidget(p_elem_list_SP);
            #endif
            }
            else
            {
            #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
                p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_list_SP);
            #endif
            }
            if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
                hmi_gfx_mgr02_manage_layer_cp_child(p_elem_list_SP, p_layer_index);
            }
        }
        break;
    #endif /* #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0) */
    #if GFX_MGR02_NUM_OF_SWDGS > 0
        case GFX_MGR02_TYPE_SWIDGET:
        {
           if(fl_base_id < GFX_MGR02_NUM_OF_SWDGS)
           {
               GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP = &lc_swidget_layer_def_S[fl_base_id];

               fl_vaof_index = hmi_gfx_mgr02_get_widget_layer_area(p_elem_list_SP, &fl_elem_area);
               
               if(fl_widget_desc_SP->merge == 0)
               {
                   fl_num_of_elem  = p_elem_list_SP->num_child_elements;
                   if(fl_num_of_elem > 0)
                   {
                       fl_elem_list_SP = &p_elem_list_SP->child[fl_num_of_elem-1];
                       while(fl_num_of_elem > 0)
                       {
                           fl_num_of_elem--;
                           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_22)
                           hmi_gfx_mgr02_manage_layer_cp_child(fl_elem_list_SP, p_layer_index);
                           fl_elem_list_SP = &fl_elem_list_SP[-1];
                           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_23)
                       }
                   }
               }
               else
               {
               #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                   GFX_MGR02_VISIBLE_AREA fl_clipped_area;
               #endif
               
                   fl_elem_area.alpha = fl_context_SP->state.alpha;
                   fl_elem_area.sx    = fl_context_SP->state.loc.x;
                   fl_elem_area.sy    = fl_context_SP->state.loc.y;
               
               #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                   fl_clipped_area.sx = fl_elem_area.sx;
                   fl_clipped_area.sy = fl_elem_area.sy;
                   fl_clipped_area.ex = (fl_elem_area.ex+fl_elem_area.sx);
                   fl_clipped_area.ey = (fl_elem_area.ey+fl_elem_area.sy);

                   if(hmi_gfx_mgr02_context_validate_clip(&fl_clipped_area, &fl_context_SP->state.clip) != FALSE)
                   {
                      fl_elem_area.is_transparent = GFX_MGR02_TRANSPARENT;
                   }
                   else
               #endif
                   {
                    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                       /* fl_elem_area has x,y,width and height */
                       fl_elem_area.sx = fl_clipped_area.sx;
					   fl_elem_area.sy = fl_clipped_area.sy;
					   fl_elem_area.ex = fl_clipped_area.ex - fl_clipped_area.sx;
					   fl_elem_area.ey = fl_clipped_area.ey - fl_clipped_area.sy;
                    #endif
                       hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index);
                   #if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0
                       if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_OPENVG)
                       {
                          hmi_gfx_mgr02_context_widget_set_active(fl_widget_desc_SP->client_id);
                       }
                   #endif
                   }
               }
           }
        }
        break;
    #endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
    #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
        case GFX_MGR02_TYPE_SIMAGE:
        {
           fl_vaof_index = hmi_gfx_mgr02_get_image_layer_area(p_elem_list_SP, &fl_elem_area);
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index);
        }
        break;
    #endif
    #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
        case GFX_MGR02_TYPE_STEXT:
        case GFX_MGR02_TYPE_DTEXT:
        {
           hmi_gfx_mgr02_get_text_layer_area(p_elem_list_SP, &fl_elem_area);
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
             fl_text_width      = fl_elem_area.ey;
           #else
             fl_text_width      = fl_elem_area.ex;
           #endif
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
        }
        break;
    #endif
    #if (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TILES > 0)
        case GFX_MGR02_TYPE_TILE:
        case GFX_MGR02_TYPE_FILL:
        {
           hmi_gfx_mgr02_get_tile_fill_layer_area(p_elem_list_SP, &fl_elem_area);
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
        }
        break;
    #endif
    #if GFX_MGR02_NUM_USER_LAYERS > 0
        case GFX_MGR02_TYPE_USER_LAYER:
        {
            /* Get the element area of the user_image element */
            GFX_MGR02_IMAGE_DEF_T * fl_image_def_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
            (void)hmi_gfx_mgr02_load_user_layer_def_info(p_elem_list_SP->base_id, fl_image_def_SP);
            if((fl_image_def_SP->pixel_data != GFX_MGR02_NULL_PTR) && 
               (fl_image_def_SP->height     != 0)        && 
               (fl_image_def_SP->width      != 0))
            {
               (void)hmi_gfx_mgr02_get_image_layer_area(p_elem_list_SP, &fl_elem_area);
               fl_elem_area.alpha = fl_context_SP->state.alpha;
               fl_elem_area.sx    = fl_context_SP->state.loc.x;
               fl_elem_area.sy    = fl_context_SP->state.loc.y;
               hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
            }
        }
        break;
    #endif
        default:
        {
        	/*For MISRA warning.*/
        }
        break;
    }
    if((fl_elem_area.is_transparent != GFX_MGR02_TRANSPARENT) && 
       (fl_context_SP->state.invisible == 0))     
    {
       /*
       ** This element is with in displayable area and is not transparent.
       ** This element can be added to the render list and validated for
       ** visibility.
       */
       if(hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_elem_area, 
                                                       l_gfx_mgr02_data_S.visible_num_of_elements, 
                                                       &l_gfx_virtual_layer[0]) == HMI_GFX_MGR02_ELEMENT_VISIBLE)
       {
          UINT32                   fl_cur_layer_index = l_gfx_mgr02_data_S.cur_layer_index;
          GFX_MGR02_CONTEXT_T    * fl_context_sp      = hmi_gfx_mgr02_context_get_ptr();
          GFX_MGR02_VISIBLE_AREA * fl_elem_area_SP    = &l_gfx_mgr02_data_S.elem_area_sa[fl_cur_layer_index];
          struct DCU_LAYER_tag   * fl_vir_layer_SP    = &l_gfx_virtual_layer[fl_cur_layer_index];

          fl_vir_layer_SP->CTRLDESCL2.B.POSX    = fl_elem_area.sx;
          fl_vir_layer_SP->CTRLDESCL2.B.POSY    = fl_elem_area.sy; 
          fl_vir_layer_SP->CTRLDESCL1.B.WIDTH   = fl_elem_area.ex; 
          fl_vir_layer_SP->CTRLDESCL1.B.HEIGHT  = fl_elem_area.ey;
          fl_vir_layer_SP->CTRLDESCL4.B.TRANS   = fl_elem_area.alpha;
          fl_elem_area_SP->sx                   = fl_context_sp->state.clip.sx;
          fl_elem_area_SP->sy                   = fl_context_sp->state.clip.sy;
          fl_elem_area_SP->ex                   = fl_context_sp->state.clip.ex;
          fl_elem_area_SP->ey                   = fl_context_sp->state.clip.ey;
          l_gfx_mgr02_data_S.next_elem_list_sa[fl_cur_layer_index] = p_elem_list_SP;
          /*
          ** Temporarily store the element XY location here so that after the
          ** managelayer finishes, we can restore it back to  CTRLDESCL2.B.POSX
          ** and CTRLDESCL2.B.POSY.
          */
          GFX_MGR02_TMP_POSX(fl_vir_layer_SP)       = (UINT32)(fl_context_sp->state.loc.x);
          GFX_MGR02_TMP_POSY(fl_vir_layer_SP)       = (UINT32)(fl_context_sp->state.loc.y);
          GFX_MGR02_TMP_TEXT_WIDTH(fl_vir_layer_SP) = fl_text_width;

          if(fl_elem_area.is_transparent == GFX_MGR02_OPEQUE)
          {
             fl_vir_layer_SP->CTRLDESCL4.B.BB = 0;
          }
          else
          {
             fl_vir_layer_SP->CTRLDESCL4.B.BB = 1;
          }

          l_gfx_mgr02_data_S.cur_layer_index++;
          if(l_gfx_mgr02_data_S.cur_layer_index >= GFX_MGR02_NUM_DCU_LAYERS)
          {
             l_gfx_mgr02_data_S.cur_layer_index = l_gfx_mgr02_data_S.start_layer_index;
          }
          if(l_gfx_mgr02_data_S.visible_num_of_elements < GFX_MGR02_NUM_DCU_LAYERS)
          {
             l_gfx_mgr02_data_S.visible_num_of_elements++;
          }
       #ifdef GFX02_DEBUG_INFO
          l_gfx_mgr02_data_S.l_tot_num_of_elements++;
       #endif
       }
    }
    hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_childrens
 ** Visibility:       static
 ** Description:      This function copies the visible elements of passed screen
 **                   to render list  
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          14-Feb-2013 by EMANOJ1
 ** Updated:          14-Feb-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index)
{
    GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP = &lc_screen_def_S[p_screen_id];
    GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP;
    UINT32                         fl_num_of_elem;
    GFX_MGR02_ANIM_DATA_T        * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    
    (void)hmi_gfx_mgr02_context_begin_update(p_layer_index, &lc_layer_def_S[p_layer_index], FALSE);
    hmi_gfx_mgr02_context_reset_state();
    hmi_gfx_mgr02_context_set_alpha(fl_anim_prop_SP->layer_alpha[p_layer_index]);
    hmi_gfx_mgr02_context_set_loc(&fl_anim_prop_SP->layer_loc[p_layer_index]);

#if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
    if(fl_screen_def_SP->anim_index < GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS)
    {
        hmi_gfx_mgr02_context_set_alpha(fl_anim_prop_SP->group_alpha[fl_screen_def_SP->anim_index]);
        hmi_gfx_mgr02_context_set_loc(&fl_anim_prop_SP->group_loc[fl_screen_def_SP->anim_index]);        
    }
#endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */

    fl_num_of_elem  = fl_screen_def_SP->num_child_elements;
    if(fl_num_of_elem > 0)
    {
        fl_elem_list_SP = &fl_screen_def_SP->child[fl_num_of_elem-1];
        while(fl_num_of_elem > 0)
        {
            fl_num_of_elem--;
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_24)
            hmi_gfx_mgr02_manage_layer_cp_child(fl_elem_list_SP, p_layer_index);
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_25)
            if(fl_num_of_elem != 0)
            {
               fl_elem_list_SP = &fl_elem_list_SP[-1];
            }
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers
 ** Visibility:       static
 ** Description:      This function copies all elements in currently active
 **                   screens to l_gfx_mgr02_data_S.next_elem_list_sa[] array and the
 **                   elements priority to l_gfx_mgr02_data_S.next_elem_prio_u8a[]
 **                   Each element in list is then validated to see if they
 **                   fully or partly visible.
 **                   Partly or fully visible elements index
 **                   (in l_gfx_mgr02_data_S.next_elem_list_sa[] array) is then noted
 **                   in to l_gfx_mgr02_data_S.dcu_to_elem_u8a[] array. At the
 **                   end of this loop l_gfx_mgr02_data_S.dcu_to_elem_u8a[] will
 **                   have index of elements which are visible. The element
 **                   can be accessed by indexing in to l_gfx_mgr02_data_S.next_elem_list_sa[]
 **                   array.
 **                   Total number of visible layers are restricted to the
 **                   number of DCU layers.
 **                   Refer to 02_design\layer_allocation.doc
 ** Invocation:       Invoked by hmi_gfx_mgr02_build_screen() to determine the
 **                   visible elements to be built.
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          16-Dec-2012 by ASHEKHAR
 ** Updated:          16-Dec-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index)
{
    UINT32                          fl_max_priority;
    GFX_MGR02_SCREEN_ID_T         * fl_cur_screen;
    UINT32                          fl_cur_screen_id;

    l_disp_bg_color = 0;
    fl_max_priority = lc_layer_def_S[p_layer_index].nb_priority;
    fl_cur_screen   = lc_layer_def_S[p_layer_index].prio_stack;

    l_gfx_mgr02_data_S.cur_layer_index         = 0;
    l_gfx_mgr02_data_S.start_layer_index       = 0;
    l_gfx_mgr02_data_S.visible_num_of_elements = 0;
    l_gfx_mgr02_data_S.lp_num_elements         = 0;
    l_gfx_mgr02_data_S.hp_num_elements         = 0;
#ifdef GFX02_DEBUG_INFO
    l_gfx_mgr02_data_S.l_tot_num_of_elements   = 0;
#endif

#ifdef GFX_MGR02_GMGR_RESERVE_LAYERS_FOR_HP_SCR
    while((fl_max_priority > 0) && (l_gfx_mgr02_data_S.visible_num_of_elements == 0))
    {
       fl_max_priority--;
       fl_cur_screen_id = fl_cur_screen[fl_max_priority];
       if(fl_cur_screen_id < GFX_MGR02_NUM_OF_SCREENS)
       {
          l_disp_bg_color = lc_screen_def_S[fl_cur_screen_id].bg_color;
          hmi_gfx_mgr02_manage_layers_cp_childrens(fl_cur_screen_id, p_layer_index);
       }
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_26)
    }
    l_gfx_mgr02_data_S.hp_num_elements = l_gfx_mgr02_data_S.visible_num_of_elements;

    if(l_gfx_mgr02_data_S.visible_num_of_elements < GFX_MGR02_NUM_DCU_LAYERS)
#endif
    {
       l_gfx_mgr02_data_S.start_layer_index = l_gfx_mgr02_data_S.visible_num_of_elements;

       while(fl_max_priority > 0) 
       { 
          fl_max_priority--; 
          fl_cur_screen_id = fl_cur_screen[fl_max_priority]; 
          if(fl_cur_screen_id < GFX_MGR02_NUM_OF_SCREENS) 
          { 
             l_disp_bg_color = lc_screen_def_S[fl_cur_screen_id].bg_color;
             hmi_gfx_mgr02_manage_layers_cp_childrens(fl_cur_screen_id, p_layer_index); 
          }
          GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_27)
       } 
       l_gfx_mgr02_data_S.lp_num_elements = (UINT8)(l_gfx_mgr02_data_S.visible_num_of_elements - l_gfx_mgr02_data_S.hp_num_elements);
    }
#ifdef GFX02_DEBUG_INFO
    gfx_debug("INFO    - Total Number of DCU Layers Needed = %d\n", l_gfx_mgr02_data_S.l_tot_num_of_elements);
    gfx_debug("INFO    - Total Number of Visible Layers    = %d\n", l_gfx_mgr02_data_S.visible_num_of_elements);
#endif
}

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
#if GFX_MGR02_NUM_OF_SWDGS > 0
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_print_widget_text
 ** Visibility:       local
 ** Description:      Used to copy widget text to GRAM buffer.
 ** Invocation:       Inovked by hmi_gfx_mgr02_print_widget_elements
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          24-May-2013 by EMANOJ1
 ** Updated:          24-May-2013 by EMANOJ1
 **==========================================================================*/
static GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_print_widget_text(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ILOC_DATA const * p_offset_loc_SP)
{
    GFX_MGR02_FONT_CODE_T         fl_return_sts        = GFX_MGR02_FONT_ERROR_FAIL;
    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
    GFX_MGR02_TEXT_DEF_T const  * fl_text_desc_prop_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
    struct DCU_LAYER_tag        * fl_dcu_layer_SP      = &l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer];
    GFX_MGR02_FONT        const * fl_font_SP;
    UINT32                        fl_obj_id;
    UINT32                        fl_alignment;
    UINT32                        fl_clip_mode;
    UINT32                        fl_font_id;
    UINT32                        fl_clip_flag;
    UINT16                        fl_scroll_offset = 0;
    GFX_MGR02_ISIZE_W_T           fl_text_width = 0;
    GFX_MGR02_VISIBLE_AREA        fl_visible_text_area;


    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_widget_clip[l_widget_depth_level];
    #else
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer];
    #endif
    #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
        HMI_CHAR             const * f1_scroll_print_str_P = 0;
    #endif
        SINT32 fl_sx;
        SINT32 fl_sy;
        SINT32 fl_ex;
        SINT32 fl_ey;
        SINT32 fl_wdg_sx = fl_widget_area->sx;
        SINT32 fl_wdg_sy = fl_widget_area->sy;
        SINT32 fl_wdg_ex = fl_widget_area->ex;
        SINT32 fl_wdg_ey = fl_widget_area->ey;
        SINT32 fl_twidth;
        SINT32 fl_theight;
        SINT32 fl_swidth;
        SINT32 fl_sheight;
        SINT32 fl_s_offset = 0;

        fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
          GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_dynamic_prop_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
          fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_prop_SP->font_id); 
#if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1) 
          fl_sy        = fl_text_dynamic_prop_SP->coord.x - fl_font_SP->p.height;
#else
          fl_sy        = fl_text_dynamic_prop_SP->coord.x;
#endif
          fl_sx        = fl_text_dynamic_prop_SP->coord.y;
#else
          fl_sx        = fl_text_dynamic_prop_SP->coord.x;
          fl_sy        = fl_text_dynamic_prop_SP->coord.y;
#endif
          fl_font_id   = fl_text_dynamic_prop_SP->font_id;
          fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_dynamic_prop_SP->alignment);
          fl_clip_mode = fl_text_dynamic_prop_SP->clip_mode;
          fl_s_offset  = (SINT32)fl_text_dynamic_prop_SP->scroll_offset;
          fl_scroll_offset = fl_text_dynamic_prop_SP->scroll_offset;
          fl_text_width     = fl_text_dynamic_prop_SP->width;
#endif
        }
        else
        {
        #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
            fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_prop_SP->font_id);
#if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1) 
            fl_sy        = lc_text_const_property_S[fl_obj_id].coord.x - fl_font_SP->p.height;
#else
            fl_sy        = lc_text_const_property_S[fl_obj_id].coord.x;
#endif
            fl_sx        = lc_text_const_property_S[fl_obj_id].coord.y;
            #else
            fl_sx        = lc_text_const_property_S[fl_obj_id].coord.x;
            fl_sy        = lc_text_const_property_S[fl_obj_id].coord.y;
            #endif

           fl_font_id   = fl_text_desc_prop_SP->font_id;
           fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_prop_SP->alignment);
           fl_clip_mode = fl_text_desc_prop_SP->clip_mode;
           fl_text_width     = fl_text_desc_prop_SP->width;
        #endif
        }

        hmi_gfx_mgr02_context_set_textprop(fl_font_id,
                                           fl_alignment,
                                           fl_text_desc_prop_SP->draw_mode,
                                           fl_clip_mode,
                                           fl_scroll_offset,
                                           fl_text_width);
        fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);

        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
        #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
           if((fl_font_SP->is_ffile == 0) && (fl_font_SP->is_vfont == 0))
        #else
           if(fl_font_SP->is_vfont == 0) /* vector fonts not supported for edma printing */
        #endif
           {
              GFX_MGR02_TEXT_INFO fl_text_info_S;
              fl_text_info_S.dyn_text_def_SP = NULL;
              fl_text_info_S.print_sindex_U8 = 0;

              if(fl_text_desc_prop_SP->dynamic != 0)
              {
              #if GFX_MGR02_NUM_OF_DTEXTS > 0
                  fl_text_info_S.print_str_P = &l_layer_anim_data_SP->dtext_str[fl_text_desc_prop_SP->string_index];
                  #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
                    f1_scroll_print_str_P    = fl_text_info_S.print_str_P;
                  #endif
              #else
                 fl_text_info_S.print_str_P = NULL;
              #endif
              }
              else
              {
              #if GFX_MGR02_NUM_OF_STEXTS > 0
                  fl_text_info_S.print_str_P = (void *)&lc_static_text_buffer[fl_text_desc_prop_SP->string_index];
                  #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
                    f1_scroll_print_str_P    = fl_text_info_S.print_str_P;
                  #endif
              #else
                 fl_text_info_S.print_str_P = NULL;
              #endif
              }
              if(fl_text_info_S.print_str_P != NULL)
              {
              #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                fl_twidth = (UINT16)(fl_wdg_ey-fl_wdg_sy);
                fl_theight  = (UINT16)(fl_wdg_ex-fl_wdg_sx);
              #else
                fl_theight = (UINT16)(fl_wdg_ey-fl_wdg_sy);
                fl_twidth  = (UINT16)(fl_wdg_ex-fl_wdg_sx);
              #endif

              fl_text_info_S.max_available_width = fl_text_width;
              fl_text_info_S.target              = GFX_MGR02_TARGET_DCU;
           
              /* 
              ** no hclip support as of now, so clamp the width to the available width 
              ** this is not required once we implement hclip for text
              ** TODO : this check may not be good enough, and start x also to be
              ** considered such as (startx+width) > endx
              */
              if(fl_text_info_S.max_available_width > fl_twidth)
              {
                 fl_text_info_S.max_available_width = (UINT16)fl_twidth;
              }
              /* ---- */
           #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
              fl_text_info_S.append_str = TRUE;

           #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
              fl_text_info_S.scroll = lc_text_layer_def_S[p_elem_list_SP->base_id].scroll;
           #endif
              l_dcu_clip_text_str[0]    = 0;
           #else
              fl_text_info_S.append_str = FALSE;
           #endif
           #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
            fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
           #endif
            fl_text_info_S.num_chars_to_process = fl_text_desc_prop_SP->num_chars;
            #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) || (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
            if((fl_s_offset > 0) && (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT))
            {
			  UINT16 fl_temp;
              fl_text_info_S.append_str = FALSE;
              fl_clip_mode = GFX_MGR02_TP_NO_CLIP;
              fl_text_info_S.num_chars_to_process = GFX_MGR02_MAX_TEXT_LENGTH;
			  fl_temp = fl_text_info_S.max_available_width;
			  fl_text_info_S.max_available_width = 0xFFFFu;
              fl_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                          fl_font_id,  
                                                          fl_clip_mode,
                                                          fl_alignment
                                                          #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                          ,GFX_MGR02_NULL_PTR
                                                          #endif
                                                          );

            
              fl_text_info_S.max_available_width = fl_temp;
              if(fl_text_info_S.print_width >= fl_s_offset)
              {
                if((fl_text_info_S.print_width - fl_s_offset) > fl_text_info_S.max_available_width)
                {
                  fl_s_offset = fl_text_info_S.print_width - (fl_text_info_S.max_available_width + fl_s_offset);
                  fl_text_info_S.print_sindex_U8 = 0;
                  fl_text_info_S.print_width = fl_text_info_S.max_available_width;
                }
                else
                {
                  fl_text_info_S.print_sindex_U8 = fl_text_info_S.max_available_width - (fl_text_info_S.print_width - fl_s_offset);
                  fl_text_info_S.print_width -= fl_s_offset;
                  fl_s_offset = 0;
                }
              }
              else
              {
                fl_text_info_S.print_width = fl_text_info_S.max_available_width;
              }
            }
            else
            #endif
            {
              fl_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                           fl_font_id,  
                           fl_clip_mode,
                           fl_alignment
                        #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                          ,l_dcu_clip_text_str
                        #endif
                          );
            }
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)       
              fl_sx     += p_offset_loc_SP->y;
              fl_sy     += p_offset_loc_SP->x;
#else
              fl_sx     += p_offset_loc_SP->x;
              fl_sy     += p_offset_loc_SP->y;
#endif
              fl_swidth  = fl_text_info_S.print_width;
              fl_sheight = fl_font_SP->p.height;
#if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
              if(fl_text_info_S.print_width > fl_text_info_S.max_available_width)
              {
                fl_swidth = fl_text_info_S.max_available_width;
              }
#endif
              fl_visible_text_area.sx = fl_sx;
              fl_visible_text_area.sy = fl_sy;
              fl_visible_text_area.ex = fl_swidth;
              fl_visible_text_area.ey = fl_sheight;

              hmi_gfx_mgr02_get_printable_text_area(fl_text_desc_prop_SP->alignment, fl_alignment, fl_text_width, &fl_visible_text_area); 

              fl_sx       = fl_visible_text_area.sx;
              fl_sy       = fl_visible_text_area.sy;
              fl_swidth   = fl_visible_text_area.ex;
              fl_sheight  = fl_visible_text_area.ey;


              fl_ex = (fl_sx+fl_swidth);
              fl_ey = (fl_sy+fl_sheight);

             #if (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 0)
              /*To match with the previous code(Before extracting the area calculation into 
              hmi_gfx_mgr02_get_printable_text_area function)*/
              if(fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
              {
                fl_ex--;
              }
             #endif
             #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                fl_swidth = fl_ex;
                fl_ex = fl_ey;
                fl_ey = fl_swidth;

                fl_swidth = fl_sx;
                fl_sx = fl_sy;
                fl_sy = fl_swidth;
             #endif

              if((fl_ex <= fl_wdg_sx) || (fl_sx >= fl_wdg_ex) ||
                 (fl_ey <= fl_wdg_sy) || (fl_sy >= fl_wdg_ey))
              {
                 /* 
                 ** Text completely hidden, so skipping
                 */
              }
              else if((fl_sx < fl_wdg_sx) || (fl_ex > fl_wdg_ex))
              {
              #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
                 /* 
                 ** TODO : Text requires horizontal clipping, this requires an additional DMA 
                 ** operation which requires a work buffer. So perform only if this 
                 ** enabled by user config
                 */
              #endif
              }
              else
              {
                 /*
                 ** No Hclip is needed. Either no clip is required or only vclip is required
                 ** for the text.
                 */
                 fl_sx = (fl_sx-fl_wdg_sx);
                 fl_sy = (fl_sy-fl_wdg_sy);

                 #if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)|| (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
                   /* When the scroll_offset is >0 then the length of the full */
                   /* string need to be considered. So the fl_text_info_S is   */
                   /* overwritten with the actual values from text buffer.     */
                   if((fl_s_offset > 0) && (fl_alignment != GFX_MGR02_TP_ALIGN_RIGHT))
                   {
                     fl_text_info_S.print_str_P     = f1_scroll_print_str_P;
                     fl_text_info_S.print_length_U8 = 0;
                     if(f1_scroll_print_str_P != GFX_MGR02_NULL_PTR)
                     {
                       while(f1_scroll_print_str_P[0] != 0)
                       {
                         fl_text_info_S.print_length_U8++; 
                         f1_scroll_print_str_P++;
                       }
                     }
                   }
                 #endif
                 #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                 if(fl_sx < 0)
                 {
                    fl_s_offset -= fl_sx;
                    fl_sheight  += fl_sx;
                    fl_sx        = 0;
                 }
                 if((fl_sx+fl_sheight) > fl_theight)
                 {
                    fl_sheight = (fl_theight-fl_sx);
                 }
                 #else
                 if(fl_sy < 0)
                 {
                    fl_s_offset -= fl_sy;
                    fl_sheight  += fl_sy;
                    fl_sy        = 0;
                 }
                 if((fl_sy+fl_sheight) > fl_theight)
                 {
                    fl_sheight = (fl_theight-fl_sy);
                 }
                 #endif
              #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                 fl_text_info_S.coord.x = (SINT16)(fl_sx + (SINT16)(fl_widget_area->sx-l_widget_clip[0].sx));
                 fl_text_info_S.coord.y = (SINT16)(fl_sy + (SINT16)(fl_widget_area->sy-l_widget_clip[0].sy));
              #else
                 fl_text_info_S.coord.x = (SINT16)(fl_sx);
                 fl_text_info_S.coord.y = (SINT16)(fl_sy);
              #endif
                 fl_text_info_S.db_format = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
              #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
                 if((FALSE != fl_clip_flag) && (fl_text_info_S.print_width > fl_text_info_S.max_available_width)&& \
                                                             (lc_text_layer_def_S[p_elem_list_SP->base_id].scroll != GFX_MGR02_TP_SCROLL_ENABLE))
                 {
                     fl_return_sts = hmi_gfx_mgr02_ovg_text_print_widget_text(fl_text_info_S, 
                                          p_elem_list_SP, 
                                          l_gfx_mgr02_data_S.cur_build_layer, 
                                          fl_font_SP->p.height,
                                          fl_twidth, 
                                          fl_theight, 
                                          (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP);
                     if(fl_return_sts == GFX_MGR02_FONT_WRITE_ACTIVE)
                     {
                        hmi_gfx_mgr02_gram_print_done_isr();		  
                     }
                     else
                     {
                         l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                     }
                 }
                 else
                 #endif
                 {
                     GFX_MGR02_GRAM_CHUNK * fl_buff_ptr;
                     fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
                     if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
                     {
                        fl_return_sts = hmi_gfx_mgr02_font_fsl_edma_print(
                                        &fl_text_info_S,
                                        &hmi_gfx_mgr02_gram_print_done_isr,
                                        fl_buff_ptr->address,
                                        l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH,
                                        fl_s_offset,
                                        fl_sheight);
                     }
                   }
                }
              } /* end of else for GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING */
           }
        }
    }
    return(fl_return_sts);
}
#elif ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
static GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_print_widget_text(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ILOC_DATA const * p_offset_loc_SP)
{
    GFX_MGR02_TEXT_DEF_T const  * fl_text_desc_prop_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
    struct DCU_LAYER_tag        * fl_dcu_layer_SP      = &l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer];
    GFX_MGR02_FONT_CODE_T         fl_return_sts        = GFX_MGR02_FONT_ERROR_FAIL;
    GFX_MGR02_FONT        const * fl_font_SP;
    UINT32                        fl_obj_id;
    UINT32                        fl_alignment;
    UINT32                        fl_clip_mode;
    UINT32                        fl_font_id;
    UINT32 capinfo;
    UINT32 vertical_offset;
    Graphics_Object_t fl_source;
    Graphics_Object_t fl_target;
    UINT32   txt_font_width;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
    UINT8 fl_current_font_engine =  ui_app_get_cur_font_engine();
#endif


    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_widget_clip[l_widget_depth_level];
    #else
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer];
    #endif
        SINT32 fl_sx;
        SINT32 fl_sy;
        SINT32 fl_ex;
        SINT32 fl_ey;
        SINT32 fl_wdg_sx = fl_widget_area->sx;
        SINT32 fl_wdg_sy = fl_widget_area->sy;
        SINT32 fl_wdg_ex = fl_widget_area->ex;
        SINT32 fl_wdg_ey = fl_widget_area->ey;
        SINT32 fl_twidth;
        SINT32 fl_theight;
        SINT32 fl_swidth;
        SINT32 fl_sheight;
        SINT32 fl_s_offset;
        UINT32 fl_color;
        UINT16 fl_alpha;
        UINT32 width, height;
        UINT32 ret, xbytes;
        UINT16 *pstr; UINT32 len, bmp_width;
        UINT16 text_multicolor;
        UINT8 *ExtFont_gdraw_area;
        GFX_MGR02_ISIZE_W_T  fl_text_width = 0;
        fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
           GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_dynamic_prop_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];
           fl_sx        = fl_text_dynamic_prop_SP->coord.x;
           fl_sy        = fl_text_dynamic_prop_SP->coord.y;
           fl_font_id   = fl_text_dynamic_prop_SP->font_id;
           fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_dynamic_prop_SP->alignment);
           fl_clip_mode = fl_text_dynamic_prop_SP->clip_mode;
           fl_color     = fl_text_dynamic_prop_SP->color;
           fl_alpha     = fl_text_dynamic_prop_SP->alpha;
           fl_text_width = fl_text_dynamic_prop_SP->width;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
           fl_sx        = lc_text_const_property_S[fl_obj_id].coord.x;
           fl_sy        = lc_text_const_property_S[fl_obj_id].coord.y;
           fl_font_id   = fl_text_desc_prop_SP->font_id;
           fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_prop_SP->alignment);
           fl_clip_mode = fl_text_desc_prop_SP->clip_mode;
           fl_color     = lc_text_const_property_S[fl_obj_id].color;
           fl_alpha     = lc_text_const_property_S[fl_obj_id].alpha;
           fl_text_width = fl_text_desc_prop_SP->width;
        #endif
        }

        /*  RTC 133578 - issue fix provided by Sakai, Takayoshi (T.)
        fl_font_SP = &lc_gfx_font_table[fl_font_id]; */
        fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
		#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
			if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
		#endif
			{
		          txt_font_width = lc_gfx_digi_append_txt_font_width[fl_font_id];
			}
		#endif
		#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
			else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
		#endif
			{
		         txt_font_width = lc_gfx_mono_append_txt_font_width[fl_font_id];
		    }
		#endif
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
			else
			{
			}
		#endif

        
        //Change font data priority along with the current display language.
        if(LanguageSelect!=hmi_language_if_get_current_language()){
            LanguageSelect=hmi_language_if_get_current_language();
            {
                UINT8 Region;
                switch(LanguageSelect){
                   case HMI_LANGUAGE_JAPANESE:
                     Region=1; break;
                   case HMI_LANGUAGE_KOREA:
                     Region=2; break;
                   case HMI_LANGUAGE_TAIWANESE:
                     Region=3; break;
                   case HMI_LANGUAGE_CHINESE:
                     Region=4; break;
                   default:
                     Region=0; break;
                }
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
        if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
#endif
        {
            digi_deinit();
            digi_init(Region);
        }
#endif
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
        else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
#endif
        {
            monotype_deinit();
            monotype_init(Region);
        }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
        else
        {
        }
#endif

            }
        }

        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
           if(fl_font_SP->is_vfont == 0) /* vector fonts not supported for edma printing */
           {
              GFX_MGR02_TEXT_INFO fl_text_info_S;

              if(fl_text_desc_prop_SP->dynamic != 0)
              {
              #if GFX_MGR02_NUM_OF_DTEXTS > 0
                  fl_text_info_S.print_str_P = (void *)&l_layer_anim_data_SP->dtext_str[fl_text_desc_prop_SP->string_index];
              #endif
              }
              else
              {
              #if GFX_MGR02_NUM_OF_STEXTS > 0
                  fl_text_info_S.print_str_P = (void *)&lc_static_text_buffer[fl_text_desc_prop_SP->string_index];
              #endif
              }
              fl_theight = (UINT16)(fl_wdg_ey-fl_wdg_sy);
              fl_twidth  = (UINT16)(fl_wdg_ex-fl_wdg_sx);
              fl_text_info_S.max_available_width = fl_text_width;
              fl_text_info_S.target              = GFX_MGR02_TARGET_DCU;

              len = HMI_STRLEN ((HMI_CHAR*) fl_text_info_S.print_str_P);

              if ( (fl_text_info_S.print_str_P != GFX_MGR02_NULL_PTR) &&
                    (len > 0) )
              {
                 GFX_MGR02_VISIBLE_AREA        fl_visible_text_area;
                 pstr=(HMI_CHAR*)fl_text_info_S.print_str_P;
                text_multicolor = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
                if(text_multicolor==0x7 || text_multicolor==0x8){
                   //BPP=4fb0111 = Transparency mode 4bpp
                   //BPP=4fb1000 = Transparency mode 8bpp
                   fl_color=fl_alpha;  // Use Alpha value as color parameter instead of Color value.
                }
                if(fl_font_id==11){  //4.2mm list screen
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
                if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
#endif
                {
                 ret=digi_render_text_special(pstr,len, txt_font_width,\
                               text_multicolor,fl_color,\
                               fl_text_info_S.max_available_width,fl_font_SP->p.height,\
                               &width, &height,&ExtFont_gdraw_area);
                }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)		
                else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
#endif
                {
                 ret=monotype_render_text_special(pstr,len, txt_font_width,\
                               text_multicolor,fl_color,\
                               fl_text_info_S.max_available_width,fl_font_SP->p.height,\
                               &width, &height,&ExtFont_gdraw_area);
                }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
                else
                {
                }
#endif
                }else{
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
                if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
#endif
                {
                    ret=digi_render_text(pstr,len, txt_font_width,\
                               text_multicolor,fl_color,\
                               fl_text_info_S.max_available_width,fl_font_SP->p.height,\
                               &width, &height,&ExtFont_gdraw_area);
                }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)		
                else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
#endif
                {
                    ret=monotype_render_text(pstr,len, txt_font_width,\
                               text_multicolor,fl_color,\
                               fl_text_info_S.max_available_width,fl_font_SP->p.height,\
                               &width, &height,&ExtFont_gdraw_area);
                }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
                else
                {
                }
#endif
                }
                bmp_width=width;
                xbytes=width;
                if(ret<0){
                  return fl_return_sts;
                }

#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)       
              fl_sx     += p_offset_loc_SP->y;
              fl_sy     += p_offset_loc_SP->x;
#else
              fl_sx     += p_offset_loc_SP->x;
              fl_sy     += p_offset_loc_SP->y;
#endif
              fl_swidth  = bmp_width;
              fl_sheight = height;
              
              fl_visible_text_area.sx = fl_sx;
              fl_visible_text_area.sy = fl_sy;
              fl_visible_text_area.ex = fl_swidth;
              fl_visible_text_area.ey = fl_sheight;

              hmi_gfx_mgr02_get_printable_text_area(fl_text_desc_prop_SP->alignment, fl_alignment, fl_text_width, &fl_visible_text_area); 

              fl_sx       = fl_visible_text_area.sx;
              fl_sy       = fl_visible_text_area.sy;
              fl_swidth   = fl_visible_text_area.ex;
              fl_sheight  = fl_visible_text_area.ey;
              
              fl_ex = (fl_sx+bmp_width);
              fl_ey = (fl_sy+fl_sheight);

              #if (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 0)
              /*To match with the previous code(Before extracting the area calculation into 
              hmi_gfx_mgr02_get_printable_text_area function)*/
              if(fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
              {
                fl_ex--;
              }
              #endif

              if((fl_ex <= fl_wdg_sx) || (fl_sx >= fl_wdg_ex) ||
                 (fl_ey <= fl_wdg_sy) || (fl_sy >= fl_wdg_ey))
              {
                 /*
                 ** Text completely hidden, so skipping
                 */
              }
              else if((fl_sx < fl_wdg_sx) || (fl_ex > fl_wdg_ex))
              {
              #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
                 /*
                 ** TODO : Text requires horizontal clipping, this requires an additional DMA
                 ** operation which requires a work buffer. So perform only if this
                 ** enabled by user config
                 */
              #endif
              }
              else

              {
                 /** No Hclip is needed. Either no clip is required or only vclip is required
                 ** for the text.
                 */
                 fl_sx = (fl_sx-fl_wdg_sx);
                 fl_sy = (fl_sy-fl_wdg_sy);

                 if(fl_sy < 0)
                 {
                    fl_s_offset  = -fl_sy;
                    fl_sheight  -= fl_s_offset;
                    fl_sy        = 0;
                 }
                 else
                 {
                    fl_s_offset = 0;
                 }
                 if((fl_sy+fl_sheight) > fl_theight)
                 {
                    fl_sheight = (fl_theight-fl_sy);
                 }

              #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                 fl_text_info_S.coord.x = (SINT16)(fl_sx + (SINT16)(fl_widget_area->sx-l_widget_clip[0].sx));
                 fl_text_info_S.coord.y = (SINT16)(fl_sy + (SINT16)(fl_widget_area->sy-l_widget_clip[0].sy));
              #else
                 fl_text_info_S.coord.x = (SINT16)(fl_sx);
                 fl_text_info_S.coord.y = (SINT16)(fl_sy);
              #endif
                 fl_text_info_S.db_format = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;

              fl_source.height = height;
              fl_source.width  = xbytes;
              fl_source.address = (UINT32)&ExtFont_gdraw_area[0];
              fl_source.BPP = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
              fl_source.x = fl_sx;
              fl_source.y = fl_sy;

              fl_target.height        = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
              fl_target.width         = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
              fl_target.BPP           = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
              fl_target.address       = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer)->address;
          {  //GraphicPaste
            UINT8 flag=0;
            text_multicolor = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;

            if(fl_source.y<0 || fl_source.x<0) flag=1;
            if((fl_source.x+fl_source.width)>=fl_target.width){
              flag=1;
            }
             if(fl_source.width>=fl_target.width) flag=1;
            if(fl_source.y>=fl_target.height){
              flag=1;
            }else{
               if((fl_source.y+fl_source.height)>=fl_target.height){
                  fl_source.height=fl_target.height-fl_source.y;
               }
            }
            //Check Internal GRAM
            if((fl_target.address & 0xF0000000)==0x60000000){
              SINT32 i,a,b;
              UINT32 target_end;

              switch(text_multicolor){
                case 12:
                    a=2;b=1; break;
                default:
                    a=1; b=2; break;
              }
              target_end=fl_target.address+(((fl_target.width*fl_target.height)*a)/b);
              if(fl_target.address+(((fl_target.width*(fl_source.y+fl_source.height)+fl_source.x+fl_source.width)*a)/b) >=target_end)
              {
                for(i=0;i<fl_source.height;i++){
                  if(fl_target.address+((((fl_target.width*(fl_source.y+i)+(fl_source.x+fl_source.width))*a)/b))>=target_end){
                    fl_source.height=i-1; break;
                  }
                }
              }
            }

              if( (fl_source.height > 0) && (fl_target.height > 0) ) /*&& (flag==0)*/
              {
                 l_gfx_mgr_edma_process_mode |= GFX_MGR02_PMODE_BUILD_WIDGET;

                 if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                   &fl_source,
                   &fl_target,
                   (UINT16) fl_source.x,
                   (UINT16) (fl_source.y-fl_s_offset),
                   &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
                 {
                   fl_return_sts = GFX_MGR02_FONT_WRITE_ACTIVE;
                 }
                 else
                 {
                   l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                 }
              }
              else
              {
                 l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
              }

          } //GraphicPaste
              }
           }
           else
           {
              return fl_return_sts;//Text is NULL. Skip
           }
        }
      }
    }
    return(fl_return_sts);
}
#endif /* #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER) */
#endif /* GFX_MGR02_NUM_OF_SWDGS */
#endif /* GFX_MGR02_NUM_OF_TEXT_LAYERS */

#if GFX_MGR02_NUM_OF_SWDGS > 0
#if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) || (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_print_widget_image
 ** Visibility:       local
 ** Description:      Used to copy widget image to GRAM buffer.
 **
 ** Invocation:       Inovked by hmi_gfx_mgr02_print_widget_elements
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          30-May-2013 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_print_widget_image(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ILOC_DATA const * p_offset_loc_SP)
{
    GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_prop_SP;
    struct DCU_LAYER_tag        * fl_dcu_layer_SP  = &l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer];
    Graphics_Object_t             fl_source;
    Graphics_Object_t             fl_target;
    UINT32                        fl_return_sts = FALSE;
    UINT32                        fl_obj_id;
#ifdef GFX02_DEBUG_INFO
    UINT32 fl_image_size;
#endif
    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_widget_clip[l_widget_depth_level];
    #else
        GFX_MGR02_VISIBLE_AREA * fl_widget_area = &l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer];
    #endif
        SINT32 fl_sx;
        SINT32 fl_sy;
        SINT32 fl_ex;
        SINT32 fl_ey;
        SINT32 fl_wdg_sx = fl_widget_area->sx;
        SINT32 fl_wdg_sy = fl_widget_area->sy;
        SINT32 fl_wdg_ex = fl_widget_area->ex;
        SINT32 fl_wdg_ey = fl_widget_area->ey;

        fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
           fl_sx = l_layer_anim_data_SP->image_prop[fl_obj_id].coord.x;
           fl_sy = l_layer_anim_data_SP->image_prop[fl_obj_id].coord.y;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
           fl_sx = lc_img_const_property_S[fl_obj_id].coord.x;
           fl_sy = lc_img_const_property_S[fl_obj_id].coord.y;
        #endif
        }

        fl_image_desc_prop_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
        fl_source.height      = fl_image_desc_prop_SP->height;
        fl_source.width       = fl_image_desc_prop_SP->width;
        fl_source.address     = (UINT32)(fl_image_desc_prop_SP->pixel_data);
        fl_target.height      = (UINT16)(fl_wdg_ey-fl_wdg_sy);
        fl_target.width       = (UINT16)(fl_wdg_ex-fl_wdg_sx);
        fl_sx                += p_offset_loc_SP->x;
        fl_sy                += p_offset_loc_SP->y;
        fl_ex                 = (fl_sx+fl_source.width);
        fl_ey                 = (fl_sy+fl_source.height);

        if((fl_ex <= fl_wdg_sx) || (fl_sx >= fl_wdg_ex) ||
           (fl_ey <= fl_wdg_sy) || (fl_sy >= fl_wdg_ey))
        {
           /* 
           ** Image completely hidden, so skipping this image printing
           */
        }
     #if defined(__GFX_MGR02_RLE_ENABLED)
        else if((fl_image_desc_prop_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE) || \
                (fl_sx < fl_wdg_sx) || (fl_ex > fl_wdg_ex))
     #else
        else if((fl_sx < fl_wdg_sx) || (fl_ex > fl_wdg_ex))
     #endif
        {
           /* 
           ** Image requires horizontal clipping, this requires an additional DMA 
           ** operation which requires a work buffer. So perform only if this 
           ** enabled by user config
           ** If option not enabled, horizotal clipped images will be skipped from
           ** printing.
           */
        #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
           fl_ex = (fl_ex-fl_sx); /* Calculate the source image width  */
           fl_ey = (fl_ey-fl_sy); /* Calculate the source image height */
           /*
           ** Convert the origin of the source image with respect to the origin of its
           ** parent widget.
           */
           fl_sx = (fl_sx-fl_wdg_sx);
           fl_sy = (fl_sy-fl_wdg_sy);
           /*
           ** Now verify the start XY locations. If it is negative means it is outside widgets
           ** set boundary, so we need to clip it.
           ** Load fl_source.x,y with the co-ordinate of the source image w.r.t its parent widget
           ** top left as origin.
           */
           if(fl_sx < 0)
           {
              fl_sx        = -fl_sx;
              fl_source.x  = 0;
              fl_ex       -= fl_sx;
           }
           else
           {
              fl_source.x = (SINT16)fl_sx;
              fl_sx       = 0;
           }
           if(fl_sy < 0)
           {
              fl_sy         = -fl_sy;
              fl_source.y   = 0;
              fl_ey        -= fl_sy;
           }
           else
           {
              fl_source.y = (SINT16)fl_sy;
              fl_sy       = 0;
           }
           /*
           ** Verify the end xy co-ordinates to see if they go ouside the
           ** widgets boundary. If yes then clip the width and height.
           */
           if((fl_source.x+fl_ex) > fl_target.width)
           {
              fl_ex = (fl_target.width-fl_source.x);
           }
           if((fl_source.y+fl_ey) > fl_target.height)
           {
              fl_ey = (fl_target.height-fl_source.y);
           }
           /*
           ** Load the width/height to target buffer width height and
           ** convert the width and height in fl_ex/y to end xy position by
           ** adding the start xy position to it (endx = startx + width)
           */
           fl_target.width  = (UINT16)fl_ex;
           fl_target.height = (UINT16)fl_ey;
           fl_ex           += fl_sx;
           fl_ey           += fl_sy;

           fl_target.BPP     = (UINT8)fl_dcu_layer_SP->CTRLDESCL4.B.BPP;
           fl_target.address = hmi_gfx_mgr02_get_size_for_bpp(fl_target.BPP, (fl_target.width*fl_target.height), FALSE);
           fl_target.address = hmi_gfx_mgr02_get_workbuffer(fl_target.address);

           if(fl_target.address != 0)
           {
              GFX_MGR02_GRAM_CHUNK * fl_buffer_ptr;           
              fl_source.BPP = fl_target.BPP;
              l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_WIDGET_SUB_CPY;

              l_source_go.height  = fl_target.height; 
              l_source_go.width   = fl_target.width; 
              l_source_go.BPP     = fl_target.BPP;    
              l_source_go.address = fl_target.address;
           #if defined(GFX_MGR02_CLIPPED_WIDGETS)
              l_target_go.x       = fl_source.x + (SINT16)(fl_widget_area->sx-l_widget_clip[0].sx);
              l_target_go.y       = fl_source.y + (SINT16)(fl_widget_area->sy-l_widget_clip[0].sy);
              fl_widget_area      = &l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer];
              l_target_go.height  = fl_widget_area->ey;
              l_target_go.width   = fl_widget_area->ex;
           #else
              l_target_go.x       = fl_source.x;
              l_target_go.y       = fl_source.y;
              l_target_go.height  = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
              l_target_go.width   = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
           #endif
              l_target_go.BPP     = fl_target.BPP;    
                
              fl_buffer_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
              if(fl_buffer_ptr != GFX_MGR02_NULL_PTR)
              {
                 l_target_go.address = fl_buffer_ptr->address;
              }
           #if defined(__GFX_MGR02_RLE_ENABLED)
              if(fl_image_desc_prop_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
              {   
                  if(Graphics_RleDmaSource((UINT32) fl_source.address,fl_image_desc_prop_SP->height,fl_image_desc_prop_SP->width)==GRAPHICS_ERROR_OK)
                  {
                     /*----------------------------------------------------------------------*/
                     /* Set up the DMA channel for output from the RLE decoder               */
                     /*----------------------------------------------------------------------*/
                     if(Graphics_RleDmaDestination((UINT32)fl_target.address, fl_ey-fl_sy,fl_ex-fl_sx)==GRAPHICS_ERROR_OK)
                     {

                       /*----------------------------------------------------------------------*/
                       /* Set up RLE decoder                                                   */
                       /*----------------------------------------------------------------------*/
                       Graphics_Initialize_RleImageDecoder(GFX_MGR02_RLE_BPP(fl_image_desc_prop_SP->format),\
                                                           fl_image_desc_prop_SP->comp_size, 
                                                           fl_image_desc_prop_SP->height, 
                                                           fl_image_desc_prop_SP->width,
                                                           (UINT32)fl_sx,
                                                           (UINT32)fl_sy,
                                                           (UINT32)fl_ex,
                                                           (UINT32)fl_ey);
                       /*----------------------------------------------------------------------*/
                       /* Start the RLE decoder                                                */
                       /*----------------------------------------------------------------------*/
                       Graphics_Start_RleImageDecoder();
                       fl_return_sts = TRUE;
                     }
                     else
                     {
                        l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                     #ifdef GFX02_DEBUG_ERROR
                        gfx_debug("ERROR   - -- Copy Image , ID %02d - Skipped. Graphics_SubCopy failed\n", fl_obj_id);
                     #endif
                    }
                 }
              }
              else 
           #endif /* #if defined(__GFX_MGR02_RLE_ENABLED) */
              if(Graphics_SubCopy(GFX_MGR02_DMA_CHANNEL,
                                  &fl_source,
                                  &fl_target,
                                  (UINT16)fl_sx,
                                  (UINT16)fl_sy,
                                  (UINT16)fl_ex,
                                  (UINT16)fl_ey,
                                  &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
              {
                 fl_return_sts = TRUE;
              }
              else
              {
                 l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
              #ifdef GFX02_DEBUG_ERROR
                 gfx_debug("ERROR   - -- Copy Image , ID %02d - Skipped. Graphics_SubCopy failed\n", fl_obj_id);
              #endif
              }
           }
         #ifdef GFX02_DEBUG_ERROR
           else
           {
              gfx_debug("ERROR   - -- Copy Image , ID %02d - Skipped. Workbuffer allocation %dBytes failed\n", fl_obj_id, hmi_gfx_mgr02_get_size_for_bpp(fl_target.BPP, (fl_target.width*fl_target.height));
           }
         #endif
        #endif /* #ifdef GFX_MGR02_DCU_ENABLE_HCLIP */
        }
        else
        {
           /*
           ** No Hclip is needed. Either no clip is required or only vclip is required
           ** for the image. 
           ** Make the start xy location of the image with respect to origin
           ** of the widget start x,y location
           */
           fl_sx = (fl_sx-fl_wdg_sx);
           fl_sy = (fl_sy-fl_wdg_sy);

           if(fl_sy == 0)
           {
              /*
              ** Image starts at widgets origin itself, so just need to check if the
              ** end of the image goes outside the widget boundary. So checking the
              ** height and clamping it to available height(widget's height).
              */
              if(fl_source.height > fl_target.height)
              {
                 fl_source.height = fl_target.height;
              }
           }
           else if(fl_sy < 0)
           {
              /* 
              ** start y is less than 0 means top portion of the image lies 
              ** outside the widgets top boundary. So top portion needs to be 
              ** clipped.
              */
              fl_sy = -fl_sy;   /* sy now indicated number of lines that lies above the widget start */
              if(fl_source.height > fl_sy)
              {
                 /* clip the number of lines that lie outside widget boundary */
                 fl_source.height  -= (UINT16)fl_sy;
                 fl_source.address += hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_prop_SP->format, (fl_image_desc_prop_SP->width * fl_sy),FALSE);
                 if(fl_source.height > fl_target.height)
                 {
                    /* 
                    ** clamp the height to widgets bound if bottom portion of the 
                    ** image goes out of widgets bottom boundary
                    */
                    fl_source.height = fl_target.height;
                 }
              }
              else
              {
                 /* 
                 ** whole image is outside the widget top boundary hence not visible at all.
                 ** This should not happen because we enter the vclip only if image visible. 
                 ** But added as a error protection, 
                 */
                 fl_source.height = 0;
              }
              fl_sy = 0; /* set start y to start of widget */
           }
           else if(fl_sy < fl_target.height)
           {
              /*
              ** Image start is after the widgets start location
              */
              if((fl_sy+fl_source.height) > fl_target.height)
              {
                 if(fl_target.height > fl_sy)
                 {
                    fl_source.height = (UINT16)((SINT32)fl_target.height-fl_sy);
                 }
                 else
                 {
                    fl_source.height = 0;
                 }
              }
           }
           else
           {
              fl_source.height = 0;
           }
           if((fl_target.height > 0) && (fl_source.height > 0))
           {
              GFX_MGR02_GRAM_CHUNK * fl_buff_ptr;
              /* 
              ** initialting DMA only if something is visible 
              ** Reload the target width and height with actual layer width and height.
              ** >We cannot use l_gfx_virtual_layer[] for this since it would have been 
              ** updated if the layer has a clipping enabled. So we have to read it from
              ** elem_area_sa[]
              ** >When clipping is not enabled then we can read the W/H from l_gfx_virtual_layer 
              ** In this case we should not use elem_area_sa[] since ey and ex will have
              ** the end xy locations and not width/height
              */
           #if defined(GFX_MGR02_CLIPPED_WIDGETS)
              fl_target.height  = (UINT16)l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer].ey;
              fl_target.width   = (UINT16)l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer].ex;
           #else
              fl_target.height  = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
              fl_target.width   = l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
           #endif
              fl_target.BPP     = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
              fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
              if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
              {
                fl_target.address = fl_buff_ptr->address;
              
              #if defined(__GFX_MGR02_RLE_ENABLED)
                if(fl_image_desc_prop_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
              #endif
                {
                   l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_WIDGET;
                   if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                                     &fl_source,
                                     &fl_target,
                                   #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                                     (UINT16)(fl_sx + (SINT16)(fl_widget_area->sx-l_widget_clip[0].sx)),
                                     (UINT16)(fl_sy + (SINT16)(fl_widget_area->sy-l_widget_clip[0].sy)),
                                   #else
                                     (UINT16)(fl_sx),
                                     (UINT16)(fl_sy),
                                   #endif
                                     &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
                   {
                      fl_return_sts = TRUE;
                   }
                   else
                   {
                      l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                   }
                }
              }
           }
        }
    #ifdef GFX02_DEBUG_ERROR
        if(fl_return_sts == FALSE)
        {
            gfx_debug("ERROR   - -- Copy Image , ID %02d - Skipped due to invalid configuration\n",fl_obj_id);
        }
    #endif
    #ifdef GFX02_DEBUG_INFO
        if(fl_return_sts != FALSE)
        {
           fl_image_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_prop_SP->format, (fl_image_desc_prop_SP->width * fl_image_desc_prop_SP->height),TRUE);
           gfx_debug("INFO    - -- Copy Image , Layer %02d, GRAM size 0x%08X Bytes\n", l_gfx_mgr02_data_S.cur_build_layer, fl_image_size);
        }
    #endif
    }
    return(fl_return_sts);
}
#endif /* #if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) */

#if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_color_area
 ** Visibility:       local
 ** Description:      Runs through the passed area and converts the pixels to
 **                   ARGB4444
 ** Invocation:       Invoked by hmi_gfx_mgr02_pp_multi_color_widget
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          19-Sep-2013 by EMANOJ1
 ** Updated:          19-Sep-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_pp_multi_color_area(SINT32 p_sx,
                                              SINT32 p_sy,
                                              SINT32 p_width,
                                              SINT32 p_height,
                                              UINT32 p_color,
                                              UINT32 p_layer)
{
   UINT16                   fl_color_ARGB_U16;
   UINT32                   fl_width;
   GFX_MGR02_VISIBLE_AREA * fl_cur_clip_SP   = &l_gfx_mgr02_data_S.elem_area_sa[p_layer];
   GFX_MGR02_GRAM_CHUNK   * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_layer);
   UINT16                 * fl_sbuffer_U16P;
   UINT16                 * fl_pixel_U16P;
   UINT8                  * fl_alpha_U8P;
   UINT16                   fl_alpha;

   if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
   {
      if((fl_gram_chunk_SP->address != 0) && (fl_gram_chunk_SP->size != 0))
      {
         /* 
         ** identify the odd pixels and make it even
         */
         if((p_width & 0x01) != 0)
         {
            p_width++;
         }
         /* extract ARGB8888 color to ARGB4444*/
         fl_width  = (UINT8)(p_color >> 16);
         fl_width *= 0x0F;
         fl_width /= 0xFF;
         fl_width <<= 8;
         fl_color_ARGB_U16 = (UINT16)fl_width;
         fl_width  = (UINT8)(p_color >> 8);
         fl_width *= 0x0F;
         fl_width /= 0xFF;
         fl_width <<= 4;
         fl_color_ARGB_U16 |= (UINT16)fl_width;
         fl_width  = (UINT8)(p_color);
         fl_width *= 0x0F;
         fl_width /= 0xFF;
         fl_color_ARGB_U16 |= fl_width;

         /*Widget start address*/
         fl_sbuffer_U16P  = (UINT16 *)fl_gram_chunk_SP->address;
         fl_sbuffer_U16P += (p_sy * fl_cur_clip_SP->ex);
         fl_sbuffer_U16P += p_sx;
         /* loop for the height of the element*/
         while (((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (p_height > 0))
         {
             fl_width = p_width;
             fl_pixel_U16P = (fl_sbuffer_U16P+fl_width);
             fl_alpha_U8P  = (UINT8 *)(fl_sbuffer_U16P);
             fl_alpha_U8P += (fl_width >> 1);
             GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_28)
             /* width of the alpha data of the element*/
             while(((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (fl_width > 0))
             {
                 GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_29)
                 fl_width--;
                 fl_pixel_U16P--;
                 fl_alpha_U8P--;
                 fl_alpha = fl_alpha_U8P[0];
                 if(fl_alpha != 0)
                 {
                    fl_alpha_U8P[0] = 0;
                    if((fl_alpha & 0xF0)!= 0)
                    {
                       *fl_pixel_U16P  = fl_color_ARGB_U16;
                       *fl_pixel_U16P |= ((fl_alpha & 0xF0) << 8);
                    }
                    fl_pixel_U16P--;
                    fl_width--;
                    fl_alpha &= 0x0F;
                    if(fl_alpha != 0)
                    {
                       *fl_pixel_U16P  = fl_color_ARGB_U16;
                       *fl_pixel_U16P |= (fl_alpha << 12);
                    }
                 }
                 else
                 {
                    fl_pixel_U16P--;
                    fl_width--;
                 }
             }
             p_height--;
             fl_sbuffer_U16P += fl_cur_clip_SP->ex;
         }
      }
   }
}
#endif

#if defined(GFX_MGR02_WDG_ALPHA_CONTROL)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_alpha_area
 ** Visibility:       local
 ** Description:      Runs through the passed area and applies alpha
 **                   currently restricted only to 4BPP Transparancy type layers
 ** Invocation:       Invoked by hmi_gfx_mgr02_pp_multi_color_widget
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          20-Nov-2013 by EMANOJ1
 ** Updated:          20-Nov-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_pp_multi_alpha_area(SINT32 p_sx,
                                              SINT32 p_sy,
                                              SINT32 p_width,
                                              SINT32 p_height,
                                              UINT32 p_alpha,
                                              UINT32 p_layer)
{
   if((p_alpha < 255) && (l_gfx_virtual_layer[p_layer].CTRLDESCL4.B.BPP == GFX_MGR02_4BPP_TRANSPARENCY))
   {
      UINT32                   fl_width;
      UINT32                   fl_stride; 
      GFX_MGR02_VISIBLE_AREA * fl_cur_clip_SP   = &l_gfx_mgr02_data_S.elem_area_sa[p_layer];
      GFX_MGR02_GRAM_CHUNK   * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_layer);
      UINT8                  * fl_sbuffer_U8P;
      UINT8                  * fl_pixel_U8P;

      if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
      {
         if((fl_gram_chunk_SP->address != 0) && (fl_gram_chunk_SP->size != 0))
         {
            /* 
            ** identify the odd pixels and make it even
            */
            if((p_width & 0x01) != 0)
            {
               p_width++;
            }
            /*
            ** Widget start address
            */
            fl_stride       = (fl_cur_clip_SP->ex>>1);
            fl_sbuffer_U8P  = (UINT8 *)fl_gram_chunk_SP->address;
            fl_sbuffer_U8P += (p_sy * fl_stride);
            fl_sbuffer_U8P += (p_sx>>1);
            
            if(p_alpha == 0)
            {
               while (((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (p_height > 0))
               {
                  GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_30)
                  fl_width     = p_width;
                  fl_pixel_U8P = fl_sbuffer_U8P;
                  while(((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (fl_width > 0))
                  {
                     GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_31)
                     fl_width-=2;
                     *fl_pixel_U8P = 0;
                     fl_pixel_U8P++;
                  }
                  p_height--;
                  fl_sbuffer_U8P += fl_stride;
               }
            }
            else
            {
               UINT32 fl_pix1;
               UINT32 fl_pix2;
               while (((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (p_height > 0))
               {
                  GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_32)
                  fl_width     = p_width;
                  fl_pixel_U8P = fl_sbuffer_U8P;
                  while(((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)) && (fl_width > 0))
                  {
                     GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_33)
                     fl_width-=2;
                     fl_pix1  = *fl_pixel_U8P;
                     if(fl_pix1 > 0)
                     {
                        fl_pix2  = (fl_pix1 >> 4);
                        fl_pix1 &= 0x0F;
                        fl_pix1 *= p_alpha;
                        fl_pix1 /= 255;
                        fl_pix2 *= p_alpha;
                        fl_pix2 /= 255;
                        *fl_pixel_U8P = (UINT8)((fl_pix2<<4)|fl_pix1);
                     }
                     fl_pixel_U8P++;
                  }
                  p_height--;
                  fl_sbuffer_U8P += fl_stride;
               }
            }
         }
      }
   }
}
#endif

#if defined(GFX_MGR02_WDG_ALPHA_CONTROL) || defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_color_widget_image
 ** Visibility:       local
 ** Description:      Converts the widget image element area to ARGB4444
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          03-Sep-2013 by EMANOJ1
 ** Updated:          03-Sep-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_pp_multi_color_widget_image(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                      GFX_MGR02_ILOC_DATA    const * p_offset_SP,
                                                      GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                      UINT32                         p_layer,
                                                      UINT32                         p_mcolor)
{
    if(p_elem_list_SP != GFX_MGR02_NULL_PTR) /* RTC #338264	*/
    {
       GFX_MGR02_IMAGE_DEF_T const  * fl_image_desc_prop_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
       UINT32                        fl_obj_id;
       SINT32 fl_sx;
       SINT32 fl_sy;
       SINT32 fl_ex;
       SINT32 fl_ey;
       SINT32 fl_swidth = fl_image_desc_prop_SP->width;
       SINT32 fl_sheight = fl_image_desc_prop_SP->height;
       UINT32 fl_alpha;
       SINT32 fl_wdg_sx = p_clip_SP->sx;
       SINT32 fl_wdg_sy = p_clip_SP->sy;
       SINT32 fl_wdg_ex = p_clip_SP->ex;
       SINT32 fl_wdg_ey = p_clip_SP->ey;

       fl_wdg_ex += fl_wdg_sx;
       fl_wdg_ey += fl_wdg_sy;
       fl_obj_id  = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
       #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
          GFX_MGR02_IMAGE_DYN_PROPERTY const * fl_image_dynamic_prop_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];

          fl_sx        = fl_image_dynamic_prop_SP->coord.x;            
          fl_sy        = fl_image_dynamic_prop_SP->coord.y;
          fl_alpha     = fl_image_dynamic_prop_SP->alpha;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
            fl_sx        = lc_img_const_property_S[fl_obj_id].coord.x;
            fl_sy        = lc_img_const_property_S[fl_obj_id].coord.y;
            fl_alpha     = lc_img_const_property_S[fl_obj_id].alpha;
        #endif
        }

        fl_sx     += p_offset_SP->x;
        fl_sy     += p_offset_SP->y;
        fl_ex = (fl_sx+fl_swidth);
        fl_ey = (fl_sy+fl_sheight);
        if(p_mcolor != TRUE)
        {
           if((fl_sx >= fl_wdg_sx )&&(fl_sy >= fl_wdg_sy )&&(fl_ex <= fl_wdg_ex )&&(fl_ey <= fl_wdg_ey )) 
           {
              /* The image falls within the widget boundary */
              fl_sx = (fl_sx-fl_wdg_sx);
              fl_sy = (fl_sy-fl_wdg_sy);
              #if defined(GFX_MGR02_WDG_ALPHA_CONTROL)
                 hmi_gfx_mgr02_pp_multi_alpha_area(fl_sx, fl_sy, fl_swidth, fl_sheight, fl_alpha, p_layer);
              #endif
           }
        }
        /* TODO: Horizontal and vertical clipping */

    }
}

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_color_widget_text
 ** Visibility:       local
 ** Description:      Builds the Text and Images from the widgets elements.
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          03-Sep-2013 by EMANOJ1
 ** Updated:          03-Sep-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02__pp_multi_color_widget_text(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                     GFX_MGR02_ILOC_DATA    const * p_offset_loc_SP,
                                                     GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                     UINT32                         p_layer,
                                                     UINT32                         p_mcolor)
{
    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        GFX_MGR02_TEXT_DEF_T const  * fl_text_desc_prop_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
        GFX_MGR02_FONT        const * fl_font_SP;
        UINT32                        fl_obj_id;
        UINT32                        fl_alignment;
        UINT32                        fl_clip_mode;
        UINT32                        fl_font_id;
 
        SINT32 fl_sx;
        SINT32 fl_sy;
        SINT32 fl_ex;
        SINT32 fl_ey;
        SINT32 fl_wdg_sx = p_clip_SP->sx;
        SINT32 fl_wdg_sy = p_clip_SP->sy;
        SINT32 fl_wdg_ex = p_clip_SP->ex;
        SINT32 fl_wdg_ey = p_clip_SP->ey;
        SINT32 fl_twidth;
        SINT32 fl_theight;
        SINT32 fl_swidth;
        SINT32 fl_sheight;
        UINT32 fl_color;
        UINT32 fl_alpha;
        GFX_MGR02_ISIZE_W_T fl_text_width = 0;
        UINT32                        fl_clip_flag;
        UINT16                        fl_scroll_offset=0U;

        fl_wdg_ex += fl_wdg_sx;
        fl_wdg_ey += fl_wdg_sy;
        fl_obj_id  = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
          GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_dynamic_prop_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];
         #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
          fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_prop_SP->font_id); 
          #if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1)
          fl_sy      = fl_text_dynamic_prop_SP->coord.x - fl_font_SP->p.height;
          #else
          fl_sy      = fl_text_dynamic_prop_SP->coord.x;
          #endif
          fl_sx      = fl_text_dynamic_prop_SP->coord.y;
         #else
          fl_sx        = fl_text_dynamic_prop_SP->coord.x;
          fl_sy        = fl_text_dynamic_prop_SP->coord.y;
         #endif
          fl_font_id   = fl_text_dynamic_prop_SP->font_id;
          fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_dynamic_prop_SP->alignment);
          fl_clip_mode = fl_text_dynamic_prop_SP->clip_mode;
          fl_color     = fl_text_dynamic_prop_SP->color;
          fl_alpha     = fl_text_dynamic_prop_SP->alpha;
          fl_text_width = fl_text_dynamic_prop_SP->width;
          fl_scroll_offset = fl_text_dynamic_prop_SP->scroll_offset;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
          #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
            fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_prop_SP->font_id);
            #if (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1)
            fl_sy      = lc_text_const_property_S[fl_obj_id].coord.x - fl_font_SP->p.height;
            #else
            fl_sy      = lc_text_const_property_S[fl_obj_id].coord.x;
            #endif
            fl_sx      = lc_text_const_property_S[fl_obj_id].coord.y;
          #else
            fl_sx        = lc_text_const_property_S[fl_obj_id].coord.x;
            fl_sy        = lc_text_const_property_S[fl_obj_id].coord.y;
          #endif
           fl_font_id   = fl_text_desc_prop_SP->font_id;
           fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_prop_SP->alignment);
           fl_clip_mode = fl_text_desc_prop_SP->clip_mode;
           fl_color     = lc_text_const_property_S[fl_obj_id].color;
           fl_alpha     = lc_text_const_property_S[fl_obj_id].alpha;
           fl_text_width = fl_text_desc_prop_SP->width;
        #endif
        }

        fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);

        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
           /* 
           ** vector fonts not supported for edma printing 
           ** convertion currently supported only for A4 format to ARGB4444 only
           */
        #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
           if((fl_font_SP->is_ffile == 0) && (fl_font_SP->is_vfont == 0) && 
              (GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes) == GFX_MGR02_FONT_ENCODING_4BPP))
        #else   
           if((fl_font_SP->is_vfont == 0) && (GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes) == GFX_MGR02_FONT_ENCODING_4BPP))
        #endif
           {
              GFX_MGR02_TEXT_INFO fl_text_info_S;

              if(fl_text_desc_prop_SP->dynamic != 0)
              {
              #if GFX_MGR02_NUM_OF_DTEXTS > 0
                  fl_text_info_S.print_str_P = &l_layer_anim_data_SP->dtext_str[fl_text_desc_prop_SP->string_index];
              #else
                  fl_text_info_S.print_str_P = NULL;
              #endif
              }
              else
              {
              #if GFX_MGR02_NUM_OF_STEXTS > 0
                  fl_text_info_S.print_str_P = (void *)&lc_static_text_buffer[fl_text_desc_prop_SP->string_index];
              #else
                  fl_text_info_S.print_str_P = NULL;
              #endif
              }
              if(fl_text_info_S.print_str_P != NULL)
              {
                
                GFX_MGR02_VISIBLE_AREA fl_visible_text_area;
                #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                  fl_twidth  = (UINT16)(fl_wdg_ey-fl_wdg_sy);
                  fl_theight = (UINT16)(fl_wdg_ex-fl_wdg_sx);
                #else
                  fl_theight = (UINT16)(fl_wdg_ey-fl_wdg_sy);
                  fl_twidth  = (UINT16)(fl_wdg_ex-fl_wdg_sx);
                #endif
                fl_text_info_S.max_available_width = fl_text_width;
                fl_text_info_S.target              = GFX_MGR02_TARGET_DCU;
           
                /* 
                ** no hclip support as of now, so clamp the width to the available width 
                ** this is not required once we implement hclip for text
                ** TODO : this check may not be good enough, and start x also to be
                ** considered such as (startx+width) > endx
                */
                if(fl_text_info_S.max_available_width > fl_twidth)
                {
                   fl_text_info_S.max_available_width = (UINT16)fl_twidth;
                }
                /* ---- */
             #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
               fl_text_info_S.append_str = TRUE;
             #else
               fl_text_info_S.append_str = FALSE;
             #endif
             #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
              fl_text_info_S.scroll = lc_text_layer_def_S[p_elem_list_SP->base_id].scroll;
             #endif
              fl_text_info_S.num_chars_to_process = fl_text_desc_prop_SP->num_chars;
              #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
              fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
              #endif
                fl_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                                 fl_font_id,  
                                                 fl_clip_mode,
                                                 fl_alignment
                                            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                ,GFX_MGR02_NULL_PTR
                                            #endif
                                                );
                /* 
                ** When the given input string is truncated for a scroll enabled text
                ** and the scroll offset set by app presentation is greater than 0,
                ** then it is recommended to convert the entire textbox configured (available width)
                ** pixels from 4BPP AM format to ARGB4444 format
                */
                if((fl_clip_flag == TRUE) && (fl_text_desc_prop_SP->scroll == TRUE) && (fl_scroll_offset > 0U))
                {
                  fl_text_info_S.print_width = fl_text_info_S.max_available_width; 
                }
#if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)       
              fl_sx     += p_offset_loc_SP->y;
              fl_sy     += p_offset_loc_SP->x;
#else
              fl_sx     += p_offset_loc_SP->x;
              fl_sy     += p_offset_loc_SP->y;
#endif
                fl_swidth  = fl_text_info_S.print_width;
                fl_sheight = fl_font_SP->p.height;

             #ifdef GFX02_DEBUG_INFO
                gfx_debug("Text ID%d -- Coord [%d,%d]",fl_obj_id, fl_sx, fl_sy);
             #endif
                fl_visible_text_area.sx = fl_sx;
                fl_visible_text_area.sy = fl_sy;
                fl_visible_text_area.ex = fl_swidth;
                fl_visible_text_area.ey = fl_sheight;

                hmi_gfx_mgr02_get_printable_text_area(fl_text_desc_prop_SP->alignment, fl_alignment, fl_text_width, &fl_visible_text_area); 

                fl_sx       = fl_visible_text_area.sx;
                fl_sy       = fl_visible_text_area.sy;
                fl_swidth   = fl_visible_text_area.ex;
                fl_sheight  = fl_visible_text_area.ey;

                fl_ex = (fl_sx+fl_swidth);
                fl_ey = (fl_sy+fl_sheight);

#if (GFX_MGR02_ROTATION_90_DEG_CLOCKWISE_ENABLED == 0)
                /*To match with the previous code(Before extracting the area calculation into 
                hmi_gfx_mgr02_get_printable_text_area function)*/
                if(fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                  fl_ex--;
                }
#endif

               #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                  fl_twidth = fl_ex;
                  fl_ex     = fl_ey;
                  fl_ey     = fl_twidth;

                  fl_twidth = fl_sx;
                  fl_sx     = fl_sy;
                  fl_sy     = fl_twidth;
               #endif

                if((fl_ex <= fl_wdg_sx) || (fl_sx >= fl_wdg_ex) ||
                   (fl_ey <= fl_wdg_sy) || (fl_sy >= fl_wdg_ey))
                {
                   /* 
                   ** Text completely hidden, so skipping
                   */
                }
                else if((fl_sx < fl_wdg_sx) || (fl_ex > fl_wdg_ex))
                {
                #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
                   /* 
                   ** TODO : Text requires horizontal clipping, this requires an additional DMA 
                   ** operation which requires a work buffer. So perform only if this 
                   ** enabled by user config
                   */
                #endif
                }
                else
                {
                   /*
                   ** No Hclip is needed. Either no clip is required or only vclip is required
                   ** for the text.
                   */
                   fl_sx = (fl_sx-fl_wdg_sx);
                   fl_sy = (fl_sy-fl_wdg_sy);
                   #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                   if(fl_sx < 0)
                   {
                      fl_sheight  += fl_sx;
                      fl_sx        = 0;
                   }
                   if((fl_sx+fl_sheight) > fl_theight)
                   {
                      fl_sheight = (fl_theight-fl_sx);
                   }
                   #else
                   if(fl_sy < 0)
                   {
                      fl_sheight  += fl_sy;
                      fl_sy        = 0;
                   }
                   if((fl_sy+fl_sheight) > fl_theight)
                   {
                     fl_sheight = (fl_theight-fl_sy);
                   }
                   #endif   
                
                #ifdef GFX02_DEBUG_INFO   
                   gfx_debug("--Coord [%d,%d] swsh[%d,%d]", fl_sx, fl_sy, fl_swidth, fl_sheight);
                #endif

                #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
                  fl_twidth  = fl_swidth;
                  fl_swidth  = fl_sheight;
                  fl_sheight = fl_twidth;
                #endif

                   if(p_mcolor != FALSE)
                   {
                   #if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
                      hmi_gfx_mgr02_pp_multi_color_area(fl_sx, fl_sy, fl_swidth, fl_sheight, fl_color, p_layer);
                   #endif
                   }
                   else
                   {
                   #if defined(GFX_MGR02_WDG_ALPHA_CONTROL)
                      hmi_gfx_mgr02_pp_multi_alpha_area(fl_sx, fl_sy, fl_swidth, fl_sheight, fl_alpha, p_layer);
                   #endif
                   }
                }
             #ifdef GFX02_DEBUG_INFO
                gfx_debug("\n");
             #endif
               }
             }
          }
      }
}
#endif
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_color_widget_elements
 ** Visibility:       local
 ** Description:      Builds the Text and Images from the widgets elements.
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          03-Sep-2013 by EMANOJ1
 ** Updated:          03-Sep-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_pp_for_multi_color_widget_elements(GFX_MGR02_ELEM_LIST_T  const * p_elem_list_SP,
                                                         GFX_MGR02_ILOC_DATA    const * p_offset_SP,
                                                         GFX_MGR02_VISIBLE_AREA const * p_clip_SP,
                                                         UINT32                         p_layer,
                                                         UINT32                         p_mcolor)
{
   if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
   {
      UINT32                     fl_obj_id       = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
      UINT32                     fl_obj_type     = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
      GFX_MGR02_ANIM_DATA_T    * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
      UINT32                     fl_invisible    = FALSE;
      GFX_MGR02_ILOC_DATA        fl_coord;
      GFX_MGR02_VISIBLE_AREA     fl_cur_clip;

   #if defined(GFX_MGR02_CLIPPED_WIDGETS)
      GFX_MGR02_VISIBLE_AREA     fl_new_clip;
      fl_cur_clip.sx = p_clip_SP->sx;
      fl_cur_clip.sy = p_clip_SP->sy;
      fl_cur_clip.ex = p_clip_SP->ex;
      fl_cur_clip.ey = p_clip_SP->ey;
      fl_new_clip.sx = fl_cur_clip.sx;
      fl_new_clip.sy = fl_cur_clip.sy;
      fl_new_clip.ex = fl_cur_clip.ex;
      fl_new_clip.ey = fl_cur_clip.ey;
   #else
      fl_cur_clip.sx = p_clip_SP->sx;
      fl_cur_clip.sy = p_clip_SP->sy;
      fl_cur_clip.ex = p_clip_SP->ex;
      fl_cur_clip.ey = p_clip_SP->ey;
      fl_cur_clip.ex-= fl_cur_clip.sx;
      fl_cur_clip.ey-= fl_cur_clip.sy;
   #endif
      fl_coord.x     = p_offset_SP->x;
      fl_coord.y     = p_offset_SP->y;

   #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) || (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0)
      if((fl_obj_type == GFX_MGR02_TYPE_DIMAGE) || (fl_obj_type == GFX_MGR02_TYPE_SIMAGE))
      {
       #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
         while((fl_obj_type == GFX_MGR02_TYPE_DIMAGE) && (p_elem_list_SP != GFX_MGR02_NULL_PTR))
         {
            if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
            #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
               fl_coord.x += l_layer_anim_data_SP->group_loc[fl_obj_id].x;
               fl_coord.y += l_layer_anim_data_SP->group_loc[fl_obj_id].y;
            #endif
            }
         #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
            p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_list_SP);
         #else
            p_elem_list_SP = GFX_MGR02_NULL_PTR;
         #endif
            if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
               fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
               fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
            }
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_34)
         }
       #endif    
         hmi_gfx_mgr02_pp_multi_color_widget_image(p_elem_list_SP, &fl_coord, &fl_cur_clip, p_layer, p_mcolor);
      }
      else
   #endif
   #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
      if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) || (fl_obj_type == GFX_MGR02_TYPE_STEXT))
      {
         hmi_gfx_mgr02__pp_multi_color_widget_text(p_elem_list_SP, &fl_coord, &fl_cur_clip, p_layer, p_mcolor);
      }
      else
   #endif
   #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
      if(fl_obj_type == GFX_MGR02_TYPE_DWIDGET)
      {
          while((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) && (p_elem_list_SP != GFX_MGR02_NULL_PTR))
          {
             if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
             {
             #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
                fl_coord.x += l_layer_anim_data_SP->group_loc[fl_obj_id].x;
                fl_coord.y += l_layer_anim_data_SP->group_loc[fl_obj_id].y;
             #endif
             }
             p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_swidget(p_elem_list_SP);
             if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
             {
                fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
                fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
             }
             GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_35)
          }
          if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
          {
             hmi_gfx_mgr02_pp_for_multi_color_widget_elements(p_elem_list_SP, &fl_coord, &fl_cur_clip, p_layer, p_mcolor);
          }
      }
      else
   #endif
      if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
      {
         GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
         GFX_MGR02_WIDGET_DEF_T    const * fl_widget_prop_SP;
         UINT32                            fl_num_elements = p_elem_list_SP->num_child_elements;
         GFX_MGR02_ELEM_LIST_T     const * fl_elem_list_SP = p_elem_list_SP->child;
         
         if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
         {
         #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_elem_anim_prop_SP;
            fl_elem_prop_SP      = &lc_widget_anim_property_S[fl_obj_id];
            fl_elem_anim_prop_SP = &fl_anim_prop_SP->widget_prop[fl_obj_id];
            fl_widget_prop_SP    = &lc_swidget_layer_def_S[fl_elem_prop_SP->base_id];
            /*
            ** Load the current depth level offset values to next level
            ** as a init value.
            */
            fl_coord.x += fl_elem_anim_prop_SP->coord.x;
            fl_coord.y += fl_elem_anim_prop_SP->coord.y;

            if(fl_widget_prop_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
            {
                fl_coord.x -= fl_elem_prop_SP->coord.x;
                fl_coord.y -= fl_elem_prop_SP->coord.y;
            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                if(fl_widget_prop_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                {
                   fl_new_clip.sx = fl_elem_anim_prop_SP->clip.x;
                   fl_new_clip.sy = fl_elem_anim_prop_SP->clip.y;
                   fl_new_clip.ex = fl_elem_anim_prop_SP->clip.width;
                   fl_new_clip.ey = fl_elem_anim_prop_SP->clip.height;
                   /*
                   ** If the widget position is offsetted by certain position, then
                   ** clip also should be moved by that much. There fore we add the
                   ** offset location fl_coord_SP[1].x, y to clip
                   */
                   fl_new_clip.sx += fl_coord.x;
                   fl_new_clip.sx += fl_coord.y;
                }
            #endif
            }
         #endif
         }
         else
         {
         #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
            fl_elem_prop_SP   = &lc_swdg_const_property_S[fl_obj_id];
            fl_widget_prop_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
          #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            if(fl_widget_prop_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
            {
               fl_new_clip.sx = lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].sx;
               fl_new_clip.sy = lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].sy;
               fl_new_clip.ex = (UINT16)lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].ey;
               fl_new_clip.ey = (UINT16)lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].ex;
               /*
               ** If the widget position is offsetted by certain position, then
               ** clip also should be moved by that much. There fore we add the
               ** offset location fl_coord_SP[1].x, y to clip
               */
               fl_new_clip.sx += fl_coord.x;
               fl_new_clip.sx += fl_coord.y;
            }
          #endif
         #endif
         }
      #if defined(GFX_MGR02_CLIPPED_WIDGETS)
         fl_new_clip.ex += fl_new_clip.sx;
         fl_new_clip.ey += fl_new_clip.sy;
         fl_cur_clip.ex += fl_cur_clip.sx;
         fl_cur_clip.ey += fl_cur_clip.sy;
         fl_invisible    = hmi_gfx_mgr02_context_validate_clip(&fl_cur_clip, &fl_new_clip);
         fl_cur_clip.ex -= fl_cur_clip.sx;
         fl_cur_clip.ey -= fl_cur_clip.sy;
      #endif
         while(fl_num_elements > 0)
         {
            fl_num_elements--;
            hmi_gfx_mgr02_pp_for_multi_color_widget_elements(fl_elem_list_SP, &fl_coord, &fl_cur_clip, p_layer, p_mcolor);
            fl_elem_list_SP++;
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_36)
         }
      }
      else
      {
         /*
         ** Unsupported element so skip it
         */
      }
   }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pp_multi_color_widget
 ** Visibility:       local
 ** Description:      Builds the Text and Images from the widgets elements.
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          03-Sep-2013 by EMANOJ1
 ** Updated:          03-Sep-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_pp_multicolor_widget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, 
                                                UINT32 p_dcu_layer, 
                                                UINT32 p_mcolor)
{
   UINT32                   fl_elem_list_num = p_elem_list_SP->num_child_elements;
   GFX_MGR02_ILOC_DATA      fl_offset_S;
   GFX_MGR02_VISIBLE_AREA   fl_clip_S;
   GFX_MGR02_VISIBLE_AREA * fl_cur_clip_SP   = &l_gfx_mgr02_data_S.elem_area_sa[p_dcu_layer];
   GFX_MGR02_GRAM_CHUNK   * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_dcu_layer);

   if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
   {
      if(fl_gram_chunk_SP->status == GFX_MGR02_GRAM_CHUNK_STS_BUILT)
      {
         p_elem_list_SP = p_elem_list_SP->child;
   
         while(fl_elem_list_num > 0)
         {
            fl_elem_list_num--;
            fl_clip_S.sx  = fl_cur_clip_SP->sx;
            fl_clip_S.sy  = fl_cur_clip_SP->sy;
            fl_clip_S.ex  = fl_cur_clip_SP->ex;
            fl_clip_S.ey  = fl_cur_clip_SP->ey;
            fl_offset_S.x = 0;
            fl_offset_S.y = 0;
            hmi_gfx_mgr02_pp_for_multi_color_widget_elements(p_elem_list_SP,
                                                         &fl_offset_S,
                                                         &fl_clip_S,
                                                         p_dcu_layer,
                                                         p_mcolor);
            p_elem_list_SP++;
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_37)
         }
         fl_gram_chunk_SP->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
      }
   }
}
#endif /* #if defined(GFX_MGR02_WDG_ALPHA_CONTROL) ||   defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT) */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_print_widget
 ** Visibility:       local
 ** Description:      Builds the Text and Images from the widgets elements.
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          01-Feb-2012 by ASHEKHAR
 ** Updated:          06-Dec-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_print_widget(void)
{
    GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP;
    UINT32 fl_Ret_Value = FALSE;
    UINT32 fl_elem_list_num;
    UINT32 fl_elem_list_cur;
    UINT32 fl_exit_loop = FALSE;

    while((l_widget_depth_level >= 0) && (fl_exit_loop == FALSE))
    {
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_38)
        fl_elem_list_SP  = l_widget_elem_path_SPA[l_widget_depth_level];
        fl_elem_list_num = fl_elem_list_SP->num_child_elements;
        fl_elem_list_cur = l_widget_num_path_U8A[l_widget_depth_level];
        if(fl_elem_list_cur >= fl_elem_list_num)
        {
            /*
            ** All the elements in current level is completed.
            */
            if(l_widget_depth_level > 0)
            {
                GFX_MGR02_ELEM_LIST_T const * fl_wdgt_element_SP;
                /*
                ** Going back one lavel to the previous, if are at child level
                */
                l_widget_depth_level--;
                fl_wdgt_element_SP = &l_widget_elem_path_SPA[l_widget_depth_level]->child[l_widget_num_path_U8A[l_widget_depth_level]];
                /* Set the clip and offset of the widget position... */
            }
            else
            {
                /*
                ** If we are at parent level then, whole widget building is done.
                ** So exit the loop
                */
                l_gfx_mgr02_data_S.cur_build_layer++;
                fl_Ret_Value = hmi_gfx_mgr02_dma_render_loop();
                fl_exit_loop = TRUE;
            }
        }
        else
        {
            fl_elem_list_SP = &fl_elem_list_SP->child[fl_elem_list_cur];

            if(hmi_gfx_mgr02_print_widget_elements(fl_elem_list_SP) != FALSE)
            {
                /*
                ** DMA request is made to build this element so we can break
                ** the loop for now. And from the DMA callback we will continue the
                ** loop again
                */
                fl_Ret_Value = TRUE;
                fl_exit_loop = TRUE;
            }
            else
            {
                /*
                ** This element was skipped by hmi_gfx_mgr02_print_widget_elements(),
                ** so continue the loop to try the next element
                */
            }
        }
    }
    return(fl_Ret_Value);
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_print_widget_elements
 ** Visibility:       local
 ** Description:      Builds the Text and Images from the widgets elements.
 ** Invocation:       Invoked by hmi_gfx_build_widget
 ** Inputs/Outputs:
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_print_widget_elements(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                     fl_ret_val      = FALSE;
   if(p_elem_list_SP != GFX_MGR02_NULL_PTR) 
   {
    UINT32                     fl_obj_id       = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32                     fl_obj_type     = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    GFX_MGR02_ANIM_DATA_T    * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    UINT32                     fl_invisible    = FALSE;

    l_widget_num_path_U8A[l_widget_depth_level]++;
    
    if(
      #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
        (fl_obj_type == GFX_MGR02_TYPE_DIMAGE) || 
      #endif
        (fl_obj_type == GFX_MGR02_TYPE_SIMAGE))
    {
    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0) || (GFX_MGR02_NUM_SIMAGE_INSTANCES > 0)
        GFX_MGR02_ILOC_DATA fl_coord;
        fl_coord.x = l_widget_offset_loc[l_widget_depth_level].x;
        fl_coord.y = l_widget_offset_loc[l_widget_depth_level].y;
     #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
        while((fl_obj_type == GFX_MGR02_TYPE_DIMAGE) && (p_elem_list_SP != GFX_MGR02_NULL_PTR))
        {
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_39)
            if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
            #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
               fl_coord.x += l_layer_anim_data_SP->group_loc[fl_obj_id].x;
               fl_coord.y += l_layer_anim_data_SP->group_loc[fl_obj_id].y;
            #endif
            }
        #if GFX_MGR02_NUM_DYNAMIC_IMAGES > 0
            p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_simage(p_elem_list_SP);
        #else
            p_elem_list_SP = GFX_MGR02_NULL_PTR;
        #endif
            if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
               fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
               fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
            }
        }
     #endif    
        /* Image Coordinates - */
        fl_ret_val = hmi_gfx_mgr02_print_widget_image(p_elem_list_SP, &fl_coord);
    #endif
    }
    else if((fl_obj_type == GFX_MGR02_TYPE_DTEXT) || (fl_obj_type == GFX_MGR02_TYPE_STEXT))
    {
    #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
        l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_WIDGET;
        if(hmi_gfx_mgr02_print_widget_text(p_elem_list_SP, &l_widget_offset_loc[l_widget_depth_level]) != GFX_MGR02_FONT_ERROR_FAIL)
        {
            fl_ret_val = TRUE;
        }
        else
        {
            l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
        }
    #else
     #ifdef GFX02_DEBUG_ERROR
        gfx_debug("ERROR   - l_gfx_mgr02_data_S.visible_num_of_elements(%d) > GFX_MGR02_NUM_DCU_LAYERS\n", l_gfx_mgr02_data_S.visible_num_of_elements);
     #endif
    #endif
    }
    else if(fl_obj_type == GFX_MGR02_TYPE_DWIDGET)
    {
    #if GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0
        GFX_MGR02_ILOC_DATA fl_coord;
        fl_coord.x = 0;
        fl_coord.y = 0;
        while((fl_obj_type == GFX_MGR02_TYPE_DWIDGET) && (p_elem_list_SP != GFX_MGR02_NULL_PTR))
        {
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_40)
            if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
            #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
               fl_coord.x += l_layer_anim_data_SP->group_loc[fl_obj_id].x;
               fl_coord.y += l_layer_anim_data_SP->group_loc[fl_obj_id].y;
            #endif
            }
            p_elem_list_SP = hmi_gfx_mgr02_layout_get_selected_swidget(p_elem_list_SP);
            if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
               fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
               fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
            }
        }
        if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
        {
           /*
           ** Depth level may change in hmi_gfx_mgr02_print_widget_elements, so
           ** note the current level and add the accumulated offset.
           ** subtract it after call to hmi_gfx_mgr02_print_widget_elements
           ** because the added value would have been transfered to next depth
           ** by hmi_gfx_mgr02_print_widget_elements
           */
           GFX_MGR02_ILOC_DATA * fl_loc_SP = &l_widget_offset_loc[l_widget_depth_level];
           /* 
           ** decrementing l_widget_num_path_U8A[l_widget_depth_level] to prevent
           ** tha double increment since we are calling hmi_gfx_mgr02_print_widget_elements()
           ** again. 
           */
           l_widget_num_path_U8A[l_widget_depth_level]--;
           fl_loc_SP->x += fl_coord.x;
           fl_loc_SP->y += fl_coord.y;
           (void)hmi_gfx_mgr02_print_widget_elements(p_elem_list_SP);
           fl_loc_SP->x -= fl_coord.x;
           fl_loc_SP->y -= fl_coord.y;
        }
    #endif
    }
    else if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
    {
            if(l_widget_depth_level < (GFX_MGR02_MAX_WDG_PATH_DEPTH-1))
            {
                GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
                GFX_MGR02_WIDGET_DEF_T    const * fl_widget_prop_SP;
                GFX_MGR02_ILOC_DATA             * fl_coord_SP;
            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                GFX_MGR02_IAREA_DATA              fl_elem_area;
                GFX_MGR02_IAREA_DATA      const * fl_elem_area_SP = GFX_MGR02_NULL_PTR;
                GFX_MGR02_VISIBLE_AREA          * fl_clip_area_SP;
                GFX_MGR02_VISIBLE_AREA            fl_new_clip;
                fl_new_clip.sx = 0;
                fl_new_clip.sy = 0;
            #endif
                
                fl_coord_SP      = &l_widget_offset_loc[l_widget_depth_level];
                fl_coord_SP[1].x = fl_coord_SP->x;
                fl_coord_SP[1].y = fl_coord_SP->y;
                
                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
                {
                #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
                   GFX_MGR02_WIDGET_DYN_PROPERTY   * fl_elem_anim_prop_SP;
                   fl_elem_prop_SP      = &lc_widget_anim_property_S[fl_obj_id];
                   fl_elem_anim_prop_SP = &fl_anim_prop_SP->widget_prop[fl_obj_id];
                   fl_widget_prop_SP    = &lc_swidget_layer_def_S[fl_elem_prop_SP->base_id];
                   /*
                   ** Load the current depth level offset values to next level
                   ** as a init value.
                   */

                   fl_coord_SP[1].x += fl_elem_anim_prop_SP->coord.x;
                   fl_coord_SP[1].y += fl_elem_anim_prop_SP->coord.y;
                   if(fl_widget_prop_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
                   {
                       fl_coord_SP[1].x -= fl_elem_prop_SP->coord.x;
                       fl_coord_SP[1].y -= fl_elem_prop_SP->coord.y;
                   #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                       if(fl_widget_prop_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                       {
                          fl_elem_area_SP = &fl_elem_anim_prop_SP->clip;
                          /*
                          ** If the widget position is offsetted by certain position, then
                          ** clip also should be moved by that much. There fore we add the
                          ** offset location fl_coord_SP[1].x, y to clip
                          */
                          fl_new_clip.sx  = fl_coord_SP[1].x;
                          fl_new_clip.sy  = fl_coord_SP[1].y;
                       }
                   #endif
                   }
                #endif
                }
                else
                {
                #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
                   fl_elem_prop_SP   = &lc_swdg_const_property_S[fl_obj_id];
                   fl_widget_prop_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
                 #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                   if(fl_widget_prop_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                   {
                      if(fl_widget_prop_SP->clip_index < GFX_MGR02_NUM_VISIBLE_AREA)
                      {             
                         fl_elem_area.x      = lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].sx;
                         fl_elem_area.y      = lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].sy;
                         fl_elem_area.height = (UINT16)lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].ey;
                         fl_elem_area.width  = (UINT16)lc_elem_area_offset_SA[fl_widget_prop_SP->clip_index].ex;
                         fl_elem_area_SP     = &fl_elem_area;
                      }
                      /*
                      ** If the widget position is offsetted by certain position, then
                      ** clip also should be moved by that much. There fore we add the
                      ** offset location fl_coord_SP[1].x, y to clip
                      */
                      fl_new_clip.sx  = fl_coord_SP[1].x;
                      fl_new_clip.sy  = fl_coord_SP[1].y;
                   }
                 #endif
                #endif
                }
            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                fl_clip_area_SP       = &l_widget_clip[l_widget_depth_level];
                fl_clip_area_SP[1].sx = fl_clip_area_SP->sx;
                fl_clip_area_SP[1].sy = fl_clip_area_SP->sy;
                fl_clip_area_SP[1].ex = fl_clip_area_SP->ex;
                fl_clip_area_SP[1].ey = fl_clip_area_SP->ey;
                if(fl_elem_area_SP != GFX_MGR02_NULL_PTR)
                {
                   fl_new_clip.sx += fl_elem_area_SP->x;
                   fl_new_clip.sy += fl_elem_area_SP->y;
                   fl_new_clip.ex  = (SINT16)fl_elem_area_SP->width;
                   fl_new_clip.ey  = (SINT16)fl_elem_area_SP->height;
                   fl_new_clip.ex += fl_new_clip.sx;
                   fl_new_clip.ey += fl_new_clip.sy;
                   fl_invisible    = hmi_gfx_mgr02_context_validate_clip(&fl_clip_area_SP[1], &fl_new_clip);
                }
            #endif
                if(fl_invisible == FALSE)
                {
                   l_widget_depth_level++;
                   l_widget_elem_path_SPA[l_widget_depth_level] = p_elem_list_SP;
                   l_widget_num_path_U8A[l_widget_depth_level]  = 0;
                }
            }
            else
            {
                /*
                ** Not enough buffer available to go one more level down so
                ** we can just skip this element
                */
            }
        }
    else
    {
        /*
        ** Unsupported element so skip it
        */
    }
    }
    return(fl_ret_val);
}
#endif /* GFX_MGR02_NUM_OF_SWDGS  */

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_set_vclip
 ** Visibility:       static
 ** Description:      Updated the layer object pointer and height based on the
 **                   requested vertical clipping.
 ** Invocation:       By
 ** Inputs/Outputs:   in p_dcu_layer_SP - Pointer to the DCU virtual layer to
 **                                       which vclip needs to be applied
 **                   in p_vclip_data_SP - Vertical clipping data
 **                   in p_alignment     - TRUE if a 64bit alignment needs to
 **                                        be applied to width calculation
 **                                        Must be TRUE for DTEXT and WIDGETS
 **                   out Updated the Start address and Height of object based
 **                       on vclip data in the passed p_dcu_layer_SP.
 ** Critical Section: None.
 ** Created:          16-Mar-2012 by EMANOJ1
 ** Updated:          11-Jun-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_set_vclip(UINT32 p_dcu_layer)
{
   struct DCU_LAYER_tag         * fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];
   GFX_MGR02_VISIBLE_AREA const * fl_vclip_data_SP = &l_gfx_mgr02_data_S.elem_area_sa[p_dcu_layer];
   UINT32 fl_num_of_visible_lines;
   UINT32 fl_width_bytes;
   UINT32 fl_height;
   UINT32 fl_width;

   SINT32 fl_vclip_num_lines  = (fl_vclip_data_SP->ey-fl_vclip_data_SP->sy);
   SINT32 fl_vclip_start_line = (fl_vclip_data_SP->sy - fl_dcu_layer_SP->CTRLDESCL2.B.POSY);

   if(fl_vclip_start_line < 0)
   {
      fl_vclip_num_lines += fl_vclip_start_line;
      fl_vclip_start_line = 0;
   }
   else
   {
      fl_dcu_layer_SP->CTRLDESCL2.B.POSY = fl_vclip_data_SP->sy;
   }
   if(fl_vclip_num_lines < 0)
   {
      fl_vclip_num_lines = 0;
   }

   fl_height = (UINT32)fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT;
   fl_width  = (UINT32)fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH;

   if((fl_vclip_num_lines  >  0) &&
      (fl_vclip_start_line <  (SINT32)fl_height))
   {
      /*
      ** Find out the total number of visible lines by subtracting the
      ** start line from the available height. The requested number of
      ** lines (fl_vclip_num_lines) should always be less than
      ** the total visible lines (fl_num_of_visible_lines)
      */
      fl_num_of_visible_lines = (fl_height - fl_vclip_start_line);
      if((UINT32)fl_vclip_num_lines < fl_num_of_visible_lines)
      {
         fl_num_of_visible_lines = fl_vclip_num_lines;
      }
      if(fl_num_of_visible_lines == 0)
      {
         /*
         ** Number of visible line is 0, so object need not be displayed
         */
         fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
      }
      else if(fl_num_of_visible_lines != fl_height)
      {
         if(fl_dcu_layer_SP->CTRLDESCL4.B.TILE_EN != 0)
         {
            fl_vclip_start_line %= fl_dcu_layer_SP->CTRLDESCL7.B.TILE_VER_SIZE;
            fl_dcu_layer_SP->CTRLDESCL7.B.TILE_VER_SIZE -= fl_vclip_start_line;
            fl_width = (fl_dcu_layer_SP->CTRLDESCL7.B.TILE_HOR_SIZE*16);
         }
         fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT = fl_num_of_visible_lines;
         fl_width_bytes  = hmi_gfx_mgr02_get_size_for_bpp(fl_dcu_layer_SP->CTRLDESCL4.B.BPP,
                                                          fl_width,
                                                          FALSE);
         if(fl_vclip_start_line != 0)
         {
            fl_width_bytes *= fl_vclip_start_line;
            fl_dcu_layer_SP->CTRLDESCL3.R += fl_width_bytes;
         }
      }
      else
      {
         /*
         ** No change needed in configuration as the number of line matches
         ** base objects height and there fore no clipping is necessary
         */
      }
   }
   else if(fl_vclip_start_line < GFX_NO_CLIP)
   {
      fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
   }
   else
   {
	   /*For MISRA warning fix.*/
   }
}
#endif  /* #if defined(GFX_MGR02_CLIPPED_WIDGETS) */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_load_alpha_blend_properties
 ** Visibility:       static
 ** Description:      Updates the layer object Alpha blending, Chroma Key settings
 ** Invocation:       By
 ** Inputs/Outputs:   in p_dcu_layer  -    DCU virtual layer Index
 **                   in p_chroma_key - Chroma Key enable / disble.
 ** Critical Section: None.
 ** Created:          17-Dec-2012 by ASHEKHAR
 ** Updated:          17-Dec-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_load_alpha_blend_properties(UINT32 p_dcu_layer, UINT32 p_chroma_key)
{
    struct DCU_LAYER_tag  * fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];
    UINT32 fl_bg_color = l_gfx_virtual_layer_fg[p_dcu_layer].B.R;

    if(p_chroma_key == GFX_MGR02_IMAGE_CHROMA_KEY_YES)
    {
       fl_dcu_layer_SP->CTRLDESCL6.B.CKMIN_R = (UINT8)(fl_bg_color >> 16);
       fl_dcu_layer_SP->CTRLDESCL6.B.CKMIN_G = (UINT8)(fl_bg_color >> 8);
       fl_dcu_layer_SP->CTRLDESCL6.B.CKMIN_B = (UINT8)fl_bg_color;
       fl_dcu_layer_SP->CTRLDESCL5.B.CKMAX_R = (UINT8)(fl_bg_color >> 16);
       fl_dcu_layer_SP->CTRLDESCL5.B.CKMAX_G = (UINT8)(fl_bg_color >> 8);
       fl_dcu_layer_SP->CTRLDESCL5.B.CKMAX_B = (UINT8)fl_bg_color;
       fl_dcu_layer_SP->CTRLDESCL4.B.BB = 1;
    }
    else
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.BB = 0;
    }
    if(fl_dcu_layer_SP->CTRLDESCL4.B.TRANS != 255)
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.AB = 2;
    }
    else if((fl_dcu_layer_SP->CTRLDESCL4.B.BPP >= GFX_MGR02_32BPP) ||
            (fl_dcu_layer_SP->CTRLDESCL4.B.BPP <= GFX_MGR02_16BPP_APAL8))
    {
       /* For all ARGB formats */
       if(p_chroma_key == GFX_MGR02_IMAGE_CHROMA_KEY_YES)
       {
          fl_dcu_layer_SP->CTRLDESCL4.B.AB = 2;
       }
       else
       {
          fl_dcu_layer_SP->CTRLDESCL4.B.AB = 1;
       }
    }
    else
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.AB = 0;
    }
}

#if (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0) || (GFX_MGR02_NUM_OF_SWDGS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_blank_display_area
 ** Visibility:       static
 ** Description:      Updates GRAM with back ground color for text/ widget elements.
 **                   RAM and then copies all active elements.
 ** Invocation:       By hmi_gfx_mgr02_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_blank_display_area(UINT32 p_dcu_layer, UINT32 p_elem_bg_fill_color)
{
    struct DCU_LAYER_tag * fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];
    GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer);

    if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
    {
    if((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
       (fl_gram_chunk_SP->status == GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED))
    {
        Graphics_Object_t  fl_target;
        SINT32             fl_width;
        fl_target.height  = (UINT16)fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT;
        fl_target.width   = (UINT16)fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH;
        fl_target.BPP     = (UINT8)fl_dcu_layer_SP->CTRLDESCL4.B.BPP;
        fl_target.address = fl_gram_chunk_SP->address;
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_41)
        while((l_gfx_mgr_edma_process_mode != GFX_MGR02_PMODE_IDLE) && 
              (fl_target.height > 0) &&
              (l_gfx_mgr_shutdown_status   != GFX_MGR02_SHUTDOWN_EMERGENCY))
        {
            /*
            ** Perform CPU clear if DMA is busy
            ** Perform one line clear by CPU and check for DMA availability. If DMA
            ** is available then break the loop and use DMA to blank the pending
            ** area.
            */
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_42)
            fl_width = hmi_gfx_mgr02_get_size_for_bpp(fl_target.BPP, fl_target.width, FALSE);
            while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) && (fl_width > 0))
            {
                GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_43)
                *((UINT32 *)fl_target.address)  = p_elem_bg_fill_color;
                fl_target.address += 4;
                fl_width          -= 4;
            }
            fl_target.height--;
        }
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_44)
        if((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) && (fl_target.height > 0))
        {
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_45)
            l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_INIT_GRAM;
            if(Graphics_BlankArea(GFX_MGR02_DMA_CHANNEL,
                                  &fl_target,
                                  p_elem_bg_fill_color,
                                  &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
            {
                GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_46)
                fl_gram_chunk_SP->status = GFX_MGR02_GRAM_CHUNK_STS_INITED;
            }
            if(fl_gram_chunk_SP->status != GFX_MGR02_GRAM_CHUNK_STS_INITED)
            {
                l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
            #ifdef GFX02_DEBUG_ERROR
                gfx_debug("ERROR   - GRAM init failed for layer %d\n", p_dcu_layer);
            #endif
            }
        }
        else
        {
            fl_gram_chunk_SP->status = GFX_MGR02_GRAM_CHUNK_STS_INITED;
        }
    }
}
}
#endif  /* (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0) || (GFX_MGR02_NUM_OF_SWDGS > 0) */

#if GFX_MGR02_NUM_OF_SWDGS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_widget
 ** Visibility:       static
 ** Description:      Builds the widget element for the first time. Initializes
 **                   RAM and then copies all active elements.
 ** Invocation:       By hmi_gfx_mgr02_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_build_widget(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                            fl_obj_id;
    UINT32                            fl_obj_type;
    struct DCU_LAYER_tag            * fl_dcu_layer_SP;
    GFX_MGR02_WIDGET_DEF_T    const * fl_widget_desc_SP;
    GFX_MGR02_IMAGE_DEF_T     const * fl_image_desc_SP;
    GFX_MGR02_GRAM_CHUNK            * fl_gram_chunk_SP;    
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    GFX_MGR02_VISIBLE_AREA            fl_clipped_area;
#endif
    GFX_MGR02_VISIBLE_AREA          * fl_context_clip;
    GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP = GFX_MGR02_NULL_PTR;
    SINT32                            fl_x_offset = 0;

    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        fl_obj_type       = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
        fl_obj_id         = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        fl_dcu_layer_SP   = &l_gfx_virtual_layer[p_dcu_layer];
        fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];

    #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
        if((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_OPENVG)    && 
           (fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE))
        {
           fl_image_desc_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
        }
        else
    #endif
        {
           fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
        }
        fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT = fl_image_desc_SP->height;
        fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH  = fl_image_desc_SP->width;
        fl_dcu_layer_SP->CTRLDESCL4.B.BPP    = fl_image_desc_SP->format;
    #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
        if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_OPENVG)
        {
           fl_dcu_layer_SP->CTRLDESCL3.R = 0;
        }
        else
    #endif
        {
           fl_gram_chunk_SP = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer);
           if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
           {
             fl_dcu_layer_SP->CTRLDESCL3.R = fl_gram_chunk_SP->address;
           }
           else
           {
             fl_dcu_layer_SP->CTRLDESCL3.R = 0; 
           }
        }
        /* 
        ** clear the GRAM for DMA based rendering widgets, for other leave it to 
        ** respective libraries to take care.
        */
        if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
        {
           hmi_gfx_mgr02_blank_display_area(p_dcu_layer, fl_widget_desc_SP->bg_fill_color);
        }
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
           fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id];
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
           fl_elem_prop_SP = &lc_swdg_const_property_S[fl_obj_id];
        #endif
        }

        fl_context_clip = &l_gfx_mgr02_data_S.elem_area_sa[p_dcu_layer];

        if(fl_dcu_layer_SP->CTRLDESCL3.R != 0)
        {
           fl_dcu_layer_SP->CTRLDESCL4.B.EN = 1;
        }
    #if defined(GFX_MGR02_OPEN_VG)
        else if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_OPENVG)
        {
           fl_dcu_layer_SP->CTRLDESCL4.B.EN = 1;
        }
        else
        {
        }
    #endif

    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        /*
        ** Clipping in Y axis is taken care by DCU programming by hmi_gfx_mgr02_set_vclip
        ** Clipping in X axis needs to be handled by software, so here we are
        ** finding the clipped area and updaing the POSX and WIDTH property.
        */
        /* H clipping for openvg & software will be taken care during its building */
        if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
        {
           fl_clipped_area.sx = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSX;
           fl_clipped_area.sy = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSY;
           fl_clipped_area.ex = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH  + fl_clipped_area.sx);
           fl_clipped_area.ey = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT + fl_clipped_area.sy);
           fl_x_offset        = fl_clipped_area.sx;

           if(hmi_gfx_mgr02_context_validate_clip(&fl_clipped_area, fl_context_clip) == FALSE)
           {
           #ifdef GFX_MGR02_DCU_ENABLE_HCLIP
              UINT32 fl_factor = lc_dcu_image_width_byte_U8A[fl_dcu_layer_SP->CTRLDESCL4.B.BPP];
              UINT32 fl_mod;
            #if defined(GFX_MGR02_FARADAY) || defined(CWR_MPC5645S_LITE) || defined(CWR_MPC5645S)
              /* 
              ** Force 64bit alignment for rainbow/faraday 
              ** Otherwise if we perform any vclip animations on this objcet there are
              ** chances that the address will loose the alignment and the DCU will not
              ** display the graphic properly. lc_dcu_image_width_byte_U8A[] is by defaullt
              ** for 32bit alignment so x2 will make it 64bit
              */
              fl_factor <<= 1;
            #endif
              fl_dcu_layer_SP->CTRLDESCL2.B.POSX  = fl_clipped_area.sx;
              fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH = (fl_clipped_area.ex-fl_clipped_area.sx);
              fl_mod = (fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH % fl_factor);
              if(fl_mod != 0)
              {
                 fl_factor -= fl_mod; 
                 fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH += fl_factor;
              }
           #endif
              fl_x_offset -= fl_clipped_area.sx;
           }
           else
           {
              fl_x_offset = 0;
           }
        }
        /*
        ** elem_area_sa is reused from this point to store the DCU layer
        ** xy, Width/Height information for the render loops - 
        ** hmi_gfx_mgr02_print_widget_image / text routines
        ** This is done this way because the hmi_gfx_mgr02_set_vclip might
        ** have modified the Y and height information of the DCU layer
        ** and therefore refering CTRLDESCL2.B.POSY and CTRLDESCL1.B.HEIGHT
        ** may not give us the correct buffer information.
        ** - hmi_gfx_mgr02_set_vclip requires the original elem_area_sa[]
        **   information, so we are temporarily storing the information
        **   to fl_clipped_area before calling hmi_gfx_mgr02_set_vclip
        */
        fl_clipped_area.sx = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSX;
        fl_clipped_area.ex = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH);
        fl_clipped_area.sy = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSY;
        fl_clipped_area.ey = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT);
        hmi_gfx_mgr02_set_vclip(p_dcu_layer);
        fl_context_clip->sx = fl_clipped_area.sx;
        fl_context_clip->sy = fl_clipped_area.sy;
        fl_context_clip->ex = fl_clipped_area.ex;
        fl_context_clip->ey = fl_clipped_area.ey;
    #else
        fl_context_clip->sx = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSX;
        fl_context_clip->sy = (SINT16)fl_dcu_layer_SP->CTRLDESCL2.B.POSY;
        fl_context_clip->ex = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH);
        fl_context_clip->ey = (SINT16)(fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT);
    #endif /* #if defined(GFX_MGR02_CLIPPED_WIDGETS) */
        if(fl_elem_prop_SP != GFX_MGR02_NULL_PTR)
        {
           /*
           ** Since the animated XY positions are taken care in DCU layer
           ** itself, we just have to pass the default XY position to the
           ** widget printing routine. Because the child elements inside widget
           ** need not be aware that the widget has moved since the movement
           ** is done by DCU and the element needs to be in same relative location
           ** from the top left corner of the widget.
           */
           fl_context_clip->sx  = (SINT16)fl_elem_prop_SP->coord.x;
           fl_context_clip->sx += (SINT16)fl_x_offset;
           fl_context_clip->sy  = (SINT16)fl_elem_prop_SP->coord.y;
        }
        l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_image_desc_SP->color;

        hmi_gfx_mgr02_load_alpha_blend_properties(p_dcu_layer, fl_image_desc_SP->chroma_key);
        
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            GFX_MGR02_WIDGET_DYN_PROPERTY const * fl_wdgt_anim_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
            l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_wdgt_anim_prop_SP->fg_color;
            if(fl_wdgt_anim_prop_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
            {
                HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_wdgt_anim_prop_SP->clut);
            }
        #endif  /* GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0 */
        }
        else
        {
        #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
            GFX_MGR02_WIDGET_PROPERTY const * fl_widget_non_anim_prop_SP = &lc_swdg_const_property_S[fl_obj_id];
            l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_widget_non_anim_prop_SP->fg_color;
            if(fl_image_desc_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
            {
                HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_image_desc_SP->clut);
            }
        #endif  /* GFX_MGR02_NUM_SWDG_INSTANCES > 0 */
        }
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_47)
    #ifdef GFX02_DEBUG_INFO
        gfx_debug("INFO    - Create widget id %d on layer %d\n", p_obj_id, p_dcu_layer);
    #endif
        GFX_MGR02_UNUSED_VAR(p_obj_id);
    }
}
#endif /* GFX_MGR02_NUM_OF_SWDGS > 0 */

#if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr_build_image
 ** Visibility:       static
 ** Description:      Builds/Updates image element
 ** Invocation:       By hmi_gfx_mgr_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_build_image(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                         fl_obj_id;
    UINT32                         fl_obj_type;
    GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
    struct DCU_LAYER_tag         * fl_dcu_layer_SP;

    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);

        fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];
    #if GFX_MGR02_NUM_USER_LAYERS > 0
        if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
        {
            fl_image_desc_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
            fl_dcu_layer_SP->CTRLDESCL3.R  = (UINT32)(fl_image_desc_SP->pixel_data);
        }
        else
    #endif
        {
            fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
        #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
            fl_dcu_layer_SP->CTRLDESCL3.R  = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer)->address;
        #else
         #if defined(__GFX_MGR02_RLE_ENABLED)
            if(fl_image_desc_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
            {
               GFX_MGR02_GRAM_CHUNK   * fl_gram_chunk_SP = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer);
               if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
               {
                 fl_dcu_layer_SP->CTRLDESCL3.R  =  fl_gram_chunk_SP->address;
               }
               else
               {
                 fl_dcu_layer_SP->CTRLDESCL3.R  = 0;
               }
            }
            else
         #endif
            {
               fl_dcu_layer_SP->CTRLDESCL3.R  = (UINT32)(fl_image_desc_SP->pixel_data);
            }
        #endif
        }
        fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT = fl_image_desc_SP->height;
        fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH  = fl_image_desc_SP->width;
        fl_dcu_layer_SP->CTRLDESCL4.B.BPP    = fl_image_desc_SP->format;
        if(fl_dcu_layer_SP->CTRLDESCL3.R != 0)
        {
           fl_dcu_layer_SP->CTRLDESCL4.B.EN = 1;
        }
        else
        {
           fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
        }
        l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_image_desc_SP->color;

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0)
            GFX_MGR02_IMAGE_DYN_PROPERTY * fl_image_dyn_property_SP;
            if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
            {
            #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
                fl_image_dyn_property_SP = &l_layer_anim_data_SP->user_prop[fl_obj_id];
            #else
                fl_image_dyn_property_SP = NULL;
            #endif
            }
            else
            {
            #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)    
                fl_image_dyn_property_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
            #else
                fl_image_dyn_property_SP = NULL;
            #endif
            }
            if(fl_image_dyn_property_SP != NULL)
            {
              if(fl_image_dyn_property_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
              {
                 HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_image_dyn_property_SP->clut);
              }
              l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_image_dyn_property_SP->fg_color;
            }
             /* Set Chroma key... */
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
            GFX_MGR02_IMAGE_PROPERTY const * fl_image_non_anim_prop_SP = &lc_img_const_property_S[fl_obj_id];
            if(fl_image_desc_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
            {
                HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_image_desc_SP->clut);
            }
            l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_image_non_anim_prop_SP->fg_color;
            /* Set Chroma key... */
        #endif
        }
        l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_image_desc_SP->color;
        hmi_gfx_mgr02_load_alpha_blend_properties(p_dcu_layer, fl_image_desc_SP->chroma_key);
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        hmi_gfx_mgr02_set_vclip(p_dcu_layer);
    #endif
        GFX_MGR02_UNUSED_VAR(p_obj_id);
    #ifdef GFX02_DEBUG_INFO
        gfx_debug("INFO    - Create image  id %d on layer %d\n", p_obj_id, p_dcu_layer);
    #endif
    }
}
#endif /* GFX_MGR02_NUM_OF_IMAGE_LAYERS */

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_text
 ** Visibility:       static
 ** Description:      Builds/Updates Text element
 ** Invocation:       By hmi_gfx_mgr02_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_build_text(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                         fl_obj_id       = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32                         fl_chroma_key   = GFX_MGR02_IMAGE_CHROMA_KEY_NONE;
    GFX_MGR02_TEXT_DEF_T   const * fl_text_desc_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
    struct DCU_LAYER_tag         * fl_dcu_layer_SP = &l_gfx_virtual_layer[p_dcu_layer];
    UINT32                         fl_elem_bg_fill_color = 0;
    UINT32                         fl_draw_mode;
    UINT32                         fl_text_alignment;
    UINT32                         fl_font_BPP;
    UINT32                         fl_font_id = fl_text_desc_SP->font_id;
    GFX_MGR02_FONT         const * fl_font_SP;
    GFX_MGR02_GRAM_CHUNK         * fl_gram_chunk_SP;
    /* 
    ** text width was temporarily stored in CTRLDESCL3 by hmi_gfx_mgr02_manage_layers_cp_child
    ** so load it to WIDTH register before loading the CTRLDESCL3 with GRAM address
    */
    #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
      fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT = GFX_MGR02_TMP_TEXT_WIDTH(fl_dcu_layer_SP);
    #else
      fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH = GFX_MGR02_TMP_TEXT_WIDTH(fl_dcu_layer_SP);
    #endif

    fl_gram_chunk_SP = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer);

	if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
	{
      fl_dcu_layer_SP->CTRLDESCL3.R       = fl_gram_chunk_SP->address;
#if GFX_MGR02_NUM_OF_FONTS > 0
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
       GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_dyn_property_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];

       fl_draw_mode      = fl_text_dyn_property_SP->draw_mode;
       fl_font_id        = fl_text_dyn_property_SP->font_id;
       fl_text_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_dyn_property_SP->alignment);
       if(fl_text_dyn_property_SP->draw_mode != GFX_MGR02_TP_DRAW_REVERSE)
       {
           l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_text_dyn_property_SP->color;
           l_gfx_virtual_layer_fg[p_dcu_layer].B.R = lc_text_anim_property_S[fl_obj_id].bg_color;
           fl_chroma_key = (fl_text_dyn_property_SP->draw_mode == GFX_MGR02_TP_DRAW_TRANSP) ? GFX_MGR02_IMAGE_CHROMA_KEY_YES :fl_chroma_key ;
       }
       else
       {
           l_gfx_virtual_layer_fg[p_dcu_layer].F.R = lc_text_anim_property_S[fl_obj_id].bg_color;
           l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_text_dyn_property_SP->color;
       }
    #endif
    }
    else
    {
    #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
       GFX_MGR02_TEXT_PROPERTY     const * fl_text_non_anim_prop_SP = &lc_text_const_property_S[fl_obj_id];
       fl_draw_mode      = fl_text_desc_SP->draw_mode;
       fl_text_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_SP->alignment);
       l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_text_non_anim_prop_SP->color;
       l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_text_non_anim_prop_SP->bg_color;
       if(fl_text_desc_SP->draw_mode != GFX_MGR02_TP_DRAW_REVERSE)
       {
           l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_text_non_anim_prop_SP->color;
           l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_text_non_anim_prop_SP->bg_color;
           fl_chroma_key =(fl_text_desc_SP->draw_mode == GFX_MGR02_TP_DRAW_TRANSP) ? GFX_MGR02_IMAGE_CHROMA_KEY_YES :fl_chroma_key;
       }
       else
       {
           l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_text_non_anim_prop_SP->bg_color;
           l_gfx_virtual_layer_fg[p_dcu_layer].B.R = fl_text_non_anim_prop_SP->color;
       }
    #endif
    }

    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
    
    if((fl_dcu_layer_SP->CTRLDESCL3.R == 0) || (fl_font_SP == GFX_MGR02_NULL_PTR))
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
    }
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
    else if((fl_font_SP->is_ffile == 0) && (fl_font_SP->is_vfont == 0))
#else
    else if(fl_font_SP->is_vfont == 0)
#endif
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.EN     = 1;
       fl_font_BPP                          = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);
    #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)
       fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH  = fl_font_SP->p.height;
    #else
       fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT = fl_font_SP->p.height;
    #endif

       switch(fl_font_BPP)
       {
          case GFX_MGR02_FONT_ENCODING_1BPP: 
          {
             fl_dcu_layer_SP->CTRLDESCL4.B.BPP = GFX_MGR02_1BPP;
          }
          break;
          case GFX_MGR02_FONT_ENCODING_2BPP: 
          {
             fl_dcu_layer_SP->CTRLDESCL4.B.BPP = GFX_MGR02_2BPP;
          }
          break;
          case GFX_MGR02_FONT_ENCODING_4BPP: 
          {
             fl_dcu_layer_SP->CTRLDESCL4.B.BPP = GFX_MGR02_4BPP_TRANSPARENCY;
          #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)
             /* When the font height is not a multiple of 8 then */
             /* increase its value to the nearest next multiple of 8  */
             fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH +=  0x07;
             fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH &= ~0x07;
          #endif
          }
          break;
          case GFX_MGR02_FONT_ENCODING_8BPP: 
          {
             fl_dcu_layer_SP->CTRLDESCL4.B.BPP = GFX_MGR02_8BPP_TRANSPARENCY;
          }
          break;
          default: 
          {
             fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
          }
          break;
       }
       hmi_gfx_mgr02_load_alpha_blend_properties(p_dcu_layer, fl_chroma_key);
       /* clear the GRAM */
       GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_48)
       hmi_gfx_mgr02_blank_display_area(p_dcu_layer, fl_elem_bg_fill_color);
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
       hmi_gfx_mgr02_set_vclip(p_dcu_layer);
    #endif
       GFX_MGR02_UNUSED_VAR(p_obj_id);
    #ifdef GFX02_DEBUG_INFO
       gfx_debug("INFO    - Create text   id %d on layer %d\n", p_obj_id, p_dcu_layer);
    #endif  /* GFX02_DEBUG_INFO */
    }
    else
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
    }
#endif /* GFX_MGR02_NUM_OF_FONTS */
  }
}
#endif /* GFX_MGR02_NUM_OF_TEXT_LAYERS */

#if GFX_MGR02_NUM_OF_FILLS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_fill
 ** Visibility:       static
 ** Description:      Builds/Updates fill element
 ** Invocation:       By hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_build_fill(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                       fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32                       fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

    GFX_MGR02_FILL_DEF_T  const * fl_fill_desc_SP;
    GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP;
    struct DCU_LAYER_tag        * fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];

    fl_fill_desc_SP  = &lc_fill_layer_def_S[p_elem_list_SP->base_id];
    fl_image_desc_SP = &lc_image_layer_def_S[fl_fill_desc_SP->id];

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
         GFX_MGR02_FILL_DYN_PROPERTY  const * fl_fill_anim_prop_SP = &l_layer_anim_data_SP->fill_prop[fl_obj_id];
         l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_fill_anim_prop_SP->color;
         fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT    = fl_fill_anim_prop_SP->dim.height;
         fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH     = fl_fill_anim_prop_SP->dim.width;
    #endif
    }
    else
    {
     #if GFX_MGR02_NUM_FILL_INSTANCES > 0
        GFX_MGR02_FILL_PROPERTY  const * fl_fill_non_anim_prop_SP = &lc_fill_const_property_S[fl_obj_id];
        l_gfx_virtual_layer_fg[p_dcu_layer].F.R = fl_image_desc_SP->color;
        fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT    = fl_fill_desc_SP->dim.height;
        fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH     = fl_fill_desc_SP->dim.width;
     #endif
    }
    if(fl_image_desc_SP != GFX_MGR02_NULL_PTR)
    {
        fl_dcu_layer_SP->CTRLDESCL4.B.BPP           = fl_image_desc_SP->format;
        fl_dcu_layer_SP->CTRLDESCL3.R               = (UINT32)fl_image_desc_SP->pixel_data;
        fl_dcu_layer_SP->CTRLDESCL7.B.TILE_VER_SIZE = fl_image_desc_SP->height;
        fl_dcu_layer_SP->CTRLDESCL7.B.TILE_HOR_SIZE = (fl_image_desc_SP->width/16);
        fl_dcu_layer_SP->CTRLDESCL4.B.TILE_EN       = 1;
        fl_dcu_layer_SP->CTRLDESCL4.B.EN            = 1;
        if(fl_image_desc_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
        {
            HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_image_desc_SP->clut);
        }
        hmi_gfx_mgr02_load_alpha_blend_properties(p_dcu_layer, fl_image_desc_SP->chroma_key);
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
        hmi_gfx_mgr02_set_vclip(p_dcu_layer);
    #endif
    GFX_MGR02_UNUSED_VAR(p_obj_id);
    }
}
#endif /* GFX_MGR02_NUM_OF_FILLS */

#if GFX_MGR02_NUM_OF_TILES > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_tile
 ** Visibility:       static
 ** Description:      Builds/Updates tile element
 ** Invocation:       By hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Nov-2012 by ASHEKHAR
 ** Updated:          20-Nov-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_build_tile(UINT32 p_dcu_layer, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    struct DCU_LAYER_tag        * fl_dcu_layer_SP  = &l_gfx_virtual_layer[p_dcu_layer];
    GFX_MGR02_TILE_DEF_T  const * fl_tile_desc_SP  = &lc_tile_layer_def_S[p_elem_list_SP->base_id];
    GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP = &lc_image_layer_def_S[fl_tile_desc_SP->id];

    fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT    = fl_tile_desc_SP->dim.height;
    fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH     = fl_tile_desc_SP->dim.width;
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
        UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        GFX_MGR02_TILE_DYN_PROPERTY  const * fl_tile_anim_desc_SP = &l_layer_anim_data_SP->tile_prop[fl_obj_id];
        fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT        = fl_tile_anim_desc_SP->dim.height;
        fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH         = fl_tile_anim_desc_SP->dim.width;
    #endif
    }
    l_gfx_virtual_layer_fg[p_dcu_layer].F.R     = fl_image_desc_SP->color;
  #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
    fl_dcu_layer_SP->CTRLDESCL3.R  = hmi_gfx_mgr02_get_back_buffer(p_dcu_layer)->address;
    if(fl_dcu_layer_SP->CTRLDESCL3.R != 0)
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.EN = 1;
    }
    else
    {
       fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
    }
  #else
    fl_dcu_layer_SP->CTRLDESCL3.R               = (UINT32)fl_image_desc_SP->pixel_data;
    fl_dcu_layer_SP->CTRLDESCL4.B.EN            = 1;
  #endif
    fl_dcu_layer_SP->CTRLDESCL4.B.BPP           = fl_image_desc_SP->format;
    fl_dcu_layer_SP->CTRLDESCL4.B.TILE_EN       = 1;
    fl_dcu_layer_SP->CTRLDESCL7.B.TILE_VER_SIZE = fl_image_desc_SP->height;
    fl_dcu_layer_SP->CTRLDESCL7.B.TILE_HOR_SIZE = (fl_image_desc_SP->width/16);
    if(fl_image_desc_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
    {
        HMI_GFX_MGR02_SET_CLUT_INDEX(fl_dcu_layer_SP, fl_image_desc_SP->clut);
    }
    hmi_gfx_mgr02_load_alpha_blend_properties(p_dcu_layer, fl_image_desc_SP->chroma_key);
    p_obj_id = p_obj_id;
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_set_vclip(p_dcu_layer);
#endif
#ifdef GFX02_DEBUG_INFO
    gfx_debug("INFO    - Create tile   id %d on layer %d\n", p_elem_list_SP->obj_id, p_dcu_layer);
#endif
}
#endif /* GFX_MGR02_NUM_OF_TILES */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_init_virtual_layers
 ** Visibility:       local
 ** Description:      Used to reset Virtual DCU layers.
 ** Invocation:       hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          27-Feb-2012 by ASHEKHAR
 ** Updated:          27-Feb-2012 by ASHEKHAR
 **==========================================================================*/
static void hmi_gfx_mgr02_init_virtual_layers(UINT8 p_layer_index)
{
    if(p_layer_index < GFX_MGR02_NUM_DCU_LAYERS)
    {
        struct DCU_LAYER_tag * fl_vir_layer_SP = &l_gfx_virtual_layer[p_layer_index];
        UINT8 fl_alpha;
        /*
        ** Restore the alpha and pos x,y information updated by
        ** hmi_gfx_mgr02_manage_layers_cp_child function.
        */
        fl_alpha                            = (UINT8)fl_vir_layer_SP->CTRLDESCL4.B.TRANS;
        fl_vir_layer_SP->CTRLDESCL2.B.POSX  = GFX_MGR02_TMP_POSX(fl_vir_layer_SP);
        fl_vir_layer_SP->CTRLDESCL2.B.POSY  = GFX_MGR02_TMP_POSY(fl_vir_layer_SP);
        fl_vir_layer_SP->CTRLDESCL4.R       = 0;
        fl_vir_layer_SP->CTRLDESCL5.R       = 0;
        fl_vir_layer_SP->CTRLDESCL6.R       = 0;
        fl_vir_layer_SP->CTRLDESCL7.R       = 0;
        fl_vir_layer_SP->CTRLDESCL4.B.TRANS = fl_alpha;
    }
}

#if ((GFX_MGR02_NUM_OF_SWDGS > 0)        || \
     (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)  || \
     (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || \
     defined(GFX_MGR02_BUILDALL_IN_GRAM))
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_gram_size
 ** Visibility:       static
 ** Description:      TReturns the GRAM size needed for the passed element.
 ** Invocation:       Invoked by hmi_gfx_mgr02_pre_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          18-Jun-2013 by EMANOJ1
 ** Updated:          18-Jun-2013 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_gram_size(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                          struct DCU_LAYER_tag        * p_dcu_layer_SP)
{
   UINT32 fl_size     = 0;
   UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
   UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

   if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
   {
   #if GFX_MGR02_NUM_OF_SWDGS > 0
      GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP;
      GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
      /*
      ** Memory allocation for OpenVg is taken care by EGL
      */
      fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
     #if defined(GFX_MGR02_OPEN_VG)
      if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_OPENVG)
      {
         GFX_MGR02_TMP_FB_RENGINE(p_dcu_layer_SP) = GFX_MGR02_RT_OPENVG;
      #if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN)
         if(fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE)
         {
         #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
            fl_image_desc_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
            fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_SP->format,
                                                     (UINT32)(fl_image_desc_SP->width * fl_image_desc_SP->height),
                                                     TRUE);
         #endif
         }
         else
         {
            fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
            fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_SP->format,
                                                     (UINT32)(fl_image_desc_SP->width * fl_image_desc_SP->height),
                                                     TRUE);
         }
      #endif
      }
      else
     #endif /* #if defined(GFX_MGR02_OPEN_VG) */
      {
         fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
         fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_SP->format,
                                                  (UINT32)(fl_image_desc_SP->width * fl_image_desc_SP->height),
                                                  TRUE);
      }
   #endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
   }
   else if((fl_obj_type == GFX_MGR02_TYPE_STEXT)   ||
           (fl_obj_type == GFX_MGR02_TYPE_DTEXT))
   {
   #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
    #if GFX_MGR02_NUM_OF_FONTS > 0
      UINT8 fl_text_font_format;
      GFX_MGR02_TEXT_DEF_T const * fl_text_desc_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
      GFX_MGR02_FONT       const * fl_font         = hmi_gfx_mgr02_get_font_pointer(fl_text_desc_SP->font_id);

      if(fl_font != (GFX_MGR02_FONT *)0)
      {
      #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
         if((fl_font->is_ffile == 0) && (fl_font->is_vfont == 0))
      #else
         if(fl_font->is_vfont == 0)
      #endif
         {
            fl_text_font_format   = GFX_MGR02_GET_BPP(fl_font->f.lut_ptr->attributes);
            fl_text_font_format >>= 2;

            if(fl_text_font_format <= GFX_MGR02_8BPP)
            { 
               UINT32 fl_text_elem_width = GFX_MGR02_TMP_TEXT_WIDTH(p_dcu_layer_SP);
               UINT32 fl_height = fl_font->p.height;
            #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1)
               if(GFX_MGR02_GET_BPP(fl_font->f.lut_ptr->attributes) == GFX_MGR02_FONT_ENCODING_4BPP)
               {
                  /*
                  ** Make height multiple of 8bytes to meet the DCU 4BPP image width requirement
                  */
                  fl_height += 7;
                  fl_height &= ~0x07;
               }
            #endif
               fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_text_font_format,
                                                        (UINT32)(fl_text_elem_width * fl_height),
                                                        TRUE);
            }
         }
         else
         {
            fl_size = 0;
         }
      }
    #endif
   #else
    #ifdef GFX02_DEBUG_ERROR
      gfx_debug("ERROR   - There are no text layers but the execution somehow entered text layer building\n");
    #endif
   #endif
   }
 #if defined(__GFX_MGR02_RLE_ENABLED) || defined(GFX_MGR02_BUILDALL_IN_GRAM)
   else if(fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
   {
      GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
      fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
   #if !defined(GFX_MGR02_BUILDALL_IN_GRAM)
      if(GFX_MGR02_IMAGE_COMPRESSION_HWRLE == fl_image_desc_SP->compression)
   #endif
      {
         fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_SP->format,
                                                  (UINT32)(fl_image_desc_SP->width * fl_image_desc_SP->height),
                                                  TRUE);
      }
   #if defined(__GFX_MGR02_RLE_ENABLED)
      if(GFX_MGR02_IMAGE_COMPRESSION_HWRLE == fl_image_desc_SP->compression)
      {
         /*
         ** Since the RLE eDMA is configured to do _RLE_FIFO_TXFR_SIZE chunks
         ** there is a achance that the last DMA operation might perform _RLE_FIFO_TXFR_SIZE
         ** even if there are < _RLE_FIFO_TXFR_SIZE bytes. So there is a chance of
         ** overwriting (_RLE_FIFO_TXFR_SIZE-1), incase there was only 1byte in the
         ** RLE output FIFO. So here we allocate these extra bytes
         */
         fl_size += (_RLE_FIFO_TXFR_SIZE-1);
      }
   #endif
   }
 #endif
 #if (GFX_MGR02_NUM_OF_TILES > 0) && defined(GFX_MGR02_BUILDALL_IN_GRAM)
   else if(fl_obj_type == GFX_MGR02_TYPE_TILE)
   {
      GFX_MGR02_TILE_DEF_T  const * fl_tile_desc_SP  = &lc_tile_layer_def_S[p_elem_list_SP->base_id];
      GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP = &lc_image_layer_def_S[fl_tile_desc_SP->id];
      fl_size = hmi_gfx_mgr02_get_size_for_bpp(fl_image_desc_SP->format,
                                               (UINT32)(fl_image_desc_SP->width * fl_image_desc_SP->height),
                                               TRUE);
   }
 #endif
   else
   {
   }
   return(fl_size);
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_pre_render_loop
 ** Visibility:       static
 ** Description:      This function pre calculates everything for the rendering
 **                   operation so that the ISR task has minimum processing load.
 **                   TODO : 1. if none of the elements changed and if there are
 **                             no new elements to build, copy of cur buffer to
 **                             next buffer can be skipped and just a mapping is
 **                             to be done.
 ** Invocation:       Invoked by hmi_gfx_mgr02_build_screen
 ** Inputs/Outputs:   Returns the layer index of the layer where the memory 
 **                   overlap is detected. Incase there are no memory overlaps
 **                   then GFX_MGR02_NUM_DCU_LAYERS is returned.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          29-Oct-2013 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_pre_render_loop(void)
{
    GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP;
    UINT32                      fl_obj_type;
    UINT32                      fl_obj_id;
    UINT8                       fl_cur_index;
    UINT32                      i;
    UINT32                      fl_rebuild_needed;
    UINT32                      fl_elem_changed;
    GFX_MGR02_GRAM_CHUNK      * fl_front_buff_SP;
    GFX_MGR02_GRAM_CHUNK      * fl_back_buff_SP;
    UINT32                      fl_size;
    struct DCU_LAYER_tag      * fl_dcu_layer_SP;
    UINT32                      fl_overlap_slayer = GFX_MGR02_NUM_DCU_LAYERS;

    GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_49)

    if((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) && (l_gfx_mgr02_data_S.visible_num_of_elements > 0))
    {
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_50)
        /*
        ** Determine if any elements has changes and a rebuild is necessary
        ** or not. If none of the element has parent level changes, we donot
        ** need to rebuild them.
        ** in the process temporarliy allocate the memory also
        ** NOTE : we are using l_gfx_virtual_layer[].CTRLDESCL7 and CTRLDESCL3
        ** for temporary storage by this routine.
        */
        fl_cur_index      = 0;
        fl_rebuild_needed = FALSE;
        fl_dcu_layer_SP   = &l_gfx_virtual_layer[0];
        hmi_gfx_mgr02_mem_start_alloc(l_gfx_mgr02_data_S.visible_num_of_elements);
        while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
              (fl_cur_index < l_gfx_mgr02_data_S.visible_num_of_elements))
        {
           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_51)
           hmi_gfx_mgr02_init_virtual_layers(fl_cur_index);
           fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[fl_cur_index];
           GFX_MGR02_TMP_FB_RENGINE(fl_dcu_layer_SP) = GFX_MGR02_RT_DEFAULT;
           if(fl_elem_list_SP != (GFX_MGR02_ELEM_LIST_T *)0)
           {
              fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
              fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);

           #if ((GFX_MGR02_NUM_OF_SWDGS > 0)        || \
                (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)  || \
                defined(__GFX_MGR02_RLE_ENABLED)    || \
                defined(GFX_MGR02_BUILDALL_IN_GRAM))
              fl_size = hmi_gfx_mgr02_get_gram_size(fl_elem_list_SP, fl_dcu_layer_SP);
              if(hmi_gfx_mgr02_mem_alloc(fl_cur_index, fl_size) == GFX_MGR02_GRAM_CHUNK_STS_OVERLAP)
              {
                 if(fl_overlap_slayer == GFX_MGR02_NUM_DCU_LAYERS)
                 {
                    fl_overlap_slayer = fl_cur_index;
                 }
              }
           #else
              fl_size = 0;
           #endif

              if(   (fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
                 || (fl_obj_type == GFX_MGR02_TYPE_STEXT)
                 || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)
               #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
                 || (fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
                 || (fl_obj_type == GFX_MGR02_TYPE_TILE)
               #elif defined(__GFX_MGR02_RLE_ENABLED)
                 || ((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (GFX_MGR02_IMAGE_COMPRESSION_HWRLE==lc_image_layer_def_S[fl_elem_list_SP->base_id].compression))
               #endif
                )
              {
                 i = hmi_gfx_mgr02_get_front_buffer_index(fl_elem_list_SP, fl_cur_index);
                 GFX_MGR02_TMP_FB_INDEX(fl_dcu_layer_SP) = i;
                 if(i >= GFX_MGR02_NUM_DCU_LAYERS)
                 {
                    /*
                    ** This element is not part of the current element list 
                    ** and therefore new. So there are elements that needs
                    ** to be built.
                    */
                    fl_elem_changed = TRUE;
                 }
                 else
                 {
                    /*
                    ** Element already exists, check if it requires a rebuild or not
                    */
                    fl_elem_changed = hmi_gfx_mgr02_layout_is_element_childrens_changed(fl_elem_list_SP, TRUE);
                 }
                 GFX_MGR02_TMP_FB_CHANGED(fl_dcu_layer_SP) = fl_elem_changed;
              #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
                 if(GFX_MGR02_TMP_FB_RENGINE(fl_dcu_layer_SP) == GFX_MGR02_RT_OPENVG)
                 {
                    /*
                    ** For openVG the buffer allocation is not handled by mem.c
                    ** its handled by the EGL so we need not go to mem.c
                    ** and we can just copy the status from the current front buffer
                    ** which would have been updated previously by 
                    ** hmi_gfx_mgr02_bg_render_swidget()
                    */
                    if(fl_elem_changed == FALSE)
                    {
                       fl_front_buff_SP = hmi_gfx_mgr02_get_front_buffer(i);
                       fl_back_buff_SP  = hmi_gfx_mgr02_get_back_buffer(fl_cur_index);
                       fl_back_buff_SP->status  = fl_front_buff_SP->status;
                       fl_back_buff_SP->address = fl_front_buff_SP->address;
                    }
                 }
                 else
              #endif
                 {
                    if(fl_elem_changed != FALSE)
                    {
                       fl_rebuild_needed = TRUE;
                    }
                 }
              }
           }
           else
           {
              (void)hmi_gfx_mgr02_mem_alloc(fl_cur_index, 0);
           }
           fl_cur_index++;
           fl_dcu_layer_SP++;
        }
        /*
        ** If any element has changes that means we have to allocate the memory
        ** to those which has changes. With the current scheme of memory allocation
        ** by mem.c, it allocates memory for even the unchanged elements as well.
        ** So this loop will copy the current mem of unchanged elements to the 
        ** newly allocated memory by mem.c
        */
        fl_cur_index    = 0;
        fl_dcu_layer_SP = &l_gfx_virtual_layer[0];
        if(fl_rebuild_needed != FALSE)
        {
           while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
                 (fl_cur_index < l_gfx_mgr02_data_S.visible_num_of_elements))
           {
              GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_52)
              fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[fl_cur_index];
              if(fl_elem_list_SP != (GFX_MGR02_ELEM_LIST_T *)0)
              {
                 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
                 if(   (fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
                    || (fl_obj_type == GFX_MGR02_TYPE_STEXT)
                    || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)
                  #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
                    || (fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
                    || (fl_obj_type == GFX_MGR02_TYPE_TILE)
                  #elif defined(__GFX_MGR02_RLE_ENABLED)
                    || ((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (GFX_MGR02_IMAGE_COMPRESSION_HWRLE==lc_image_layer_def_S[fl_elem_list_SP->base_id].compression))
                  #endif
                   )
                 {
                    i = GFX_MGR02_TMP_FB_INDEX(fl_dcu_layer_SP);
                    if(i < GFX_MGR02_NUM_DCU_LAYERS)
                    {
                       fl_elem_changed = GFX_MGR02_TMP_FB_CHANGED(fl_dcu_layer_SP);
                       if( (fl_elem_changed == FALSE)
                        #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
                            && (GFX_MGR02_TMP_FB_RENGINE(fl_dcu_layer_SP) != GFX_MGR02_RT_OPENVG) 
                        #endif
                            && (hmi_gfx_mgr02_copy_front_to_back_buffer(i, fl_cur_index) == FALSE)
                         )
                             {
                                /* 
                                ** unable to perform copy, so mark this as changed to perform
                                ** building from this layer onwards.
                                */
                                fl_elem_changed = TRUE;
                       }
                    }
                    else
                    {
                       fl_elem_changed = TRUE;
                    }
                    if((l_gfx_mgr02_data_S.cur_build_layer == GFX_MGR02_NUM_DCU_LAYERS) && (fl_elem_changed != FALSE))
                    {
                      /*
                      ** Mark the start index for the render loop to start the
                      ** building process.
                      */
                      if(GFX_MGR02_TMP_FB_RENGINE(fl_dcu_layer_SP) == GFX_MGR02_RT_DEFAULT)
                      {
                        l_gfx_mgr02_data_S.cur_build_layer = fl_cur_index;
                      }
                    }
                 }
              }
              fl_cur_index++;
              fl_dcu_layer_SP++;
           }
        }
        else
        {
           /*
           ** Nothing has changed, so memory allocation not required. 
           ** Only we need to remap current allocation to next allocation
           */
           fl_overlap_slayer = GFX_MGR02_NUM_DCU_LAYERS;
           hmi_gfx_mgr02_mem_cancel_alloc();
           while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
                 (fl_cur_index < l_gfx_mgr02_data_S.visible_num_of_elements))
           {
              GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_53)
           #if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)  
              if(GFX_MGR02_TMP_FB_RENGINE(fl_dcu_layer_SP) != GFX_MGR02_RT_OPENVG)
           #endif
              {
                 fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[fl_cur_index];
                 i               = GFX_MGR02_NUM_DCU_LAYERS;
                 if(fl_elem_list_SP != (GFX_MGR02_ELEM_LIST_T *)0)
                 {
                    fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
                    fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);
                    if(   (fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
                       || (fl_obj_type == GFX_MGR02_TYPE_STEXT)
                       || (fl_obj_type == GFX_MGR02_TYPE_DTEXT)
                     #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
                       || (fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
                       || (fl_obj_type == GFX_MGR02_TYPE_TILE)
                     #elif defined(__GFX_MGR02_RLE_ENABLED)
                       || ((fl_obj_type == GFX_MGR02_TYPE_SIMAGE) && (GFX_MGR02_IMAGE_COMPRESSION_HWRLE==lc_image_layer_def_S[fl_elem_list_SP->base_id].compression))
                     #endif
                      )
                    {
                       i = GFX_MGR02_TMP_FB_INDEX(fl_dcu_layer_SP);
                    }
                 }
                 fl_back_buff_SP = hmi_gfx_mgr02_get_back_buffer(fl_cur_index);
                 if(fl_back_buff_SP != GFX_MGR02_NULL_PTR)
                 {
                   if(i < GFX_MGR02_NUM_DCU_LAYERS)
                   {
                     fl_front_buff_SP = hmi_gfx_mgr02_get_front_buffer(i);
                     if(fl_front_buff_SP != GFX_MGR02_NULL_PTR)
                     {
                       fl_back_buff_SP->size    = fl_front_buff_SP->size;
                       fl_back_buff_SP->address = fl_front_buff_SP->address;
                       fl_back_buff_SP->status  = fl_front_buff_SP->status;
                     }
                   }
                   else
                   {
                      fl_back_buff_SP->size    = 0;
                      fl_back_buff_SP->address = 0;
                      fl_back_buff_SP->status  = GFX_MGR02_GRAM_CHUNK_STS_NONE;
                   }
                 }
              }
              fl_cur_index++;
              fl_dcu_layer_SP++;
           }
        }
        hmi_gfx_mgr02_mem_end_alloc();
        /*
        ** perform the pre-render operations
        */
        fl_cur_index = 0;
        while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
              (fl_cur_index < l_gfx_mgr02_data_S.visible_num_of_elements))
        {
           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_54)
           fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[fl_cur_index];
            
           if(fl_elem_list_SP != (GFX_MGR02_ELEM_LIST_T *)0)
           {
              /*
              ** Static elements which does not require RAM. So by default prepare the
              ** DCU configuration registers.
              */
              fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
              fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);
              switch(fl_obj_type)
              {
              #if GFX_MGR02_NUM_OF_SWDGS > 0
                 case GFX_MGR02_TYPE_SWIDGET:
                 {
                    hmi_gfx_mgr02_build_widget(fl_cur_index, fl_obj_id, fl_elem_list_SP);
                 }
                 break;
              #endif
              #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
                 case GFX_MGR02_TYPE_STEXT:
                 case GFX_MGR02_TYPE_DTEXT:
                 {
                    hmi_gfx_mgr02_build_text(fl_cur_index, fl_obj_id, fl_elem_list_SP);
                 }
                 break;
              #endif
              #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0 || GFX_MGR02_NUM_USER_LAYERS > 0
               #if GFX_MGR02_NUM_USER_LAYERS > 0
                 case GFX_MGR02_TYPE_USER_LAYER:
               #endif
               #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
                 case GFX_MGR02_TYPE_SIMAGE:
               #endif
                 {
                    hmi_gfx_mgr02_build_image(fl_cur_index, fl_obj_id, fl_elem_list_SP);
                 }
                 break;
              #endif
              #if GFX_MGR02_NUM_OF_FILLS > 0
                 case GFX_MGR02_TYPE_FILL:
                 {
                    hmi_gfx_mgr02_build_fill(fl_cur_index, fl_obj_id, fl_elem_list_SP);
                 }
                 break;
              #endif
              #if GFX_MGR02_NUM_OF_TILES > 0
                 case GFX_MGR02_TYPE_TILE:
                 {
                    hmi_gfx_mgr02_build_tile(fl_cur_index, fl_obj_id, fl_elem_list_SP);
                 }
                 break;
              #endif
                 default:
                 {
                    /*
                    ** This condition will never happen, still handled as a
                    ** recovery mechanism. Disable the layer.
                    */
                    l_gfx_virtual_layer[fl_cur_index].CTRLDESCL4.B.EN = 0;
                 #ifdef GFX02_DEBUG_ERROR
                    gfx_debug("ERROR   - Invalid layer type in Build id=%d, type=%d\n", fl_obj_id, fl_obj_type);
                 #endif
                 }
                 break;
              }
           }
           fl_cur_index++;
        }
        hmi_gfx_mgr02_swap_backbuff_to_frontbuff();
        /*
        ** Disable all inactive layers
        */
        for(i=fl_cur_index; i < GFX_MGR02_NUM_DCU_LAYERS; i++)
        {
            l_gfx_virtual_layer[i].CTRLDESCL4.B.EN = 0;
        #ifdef GFX_MGR02_DYNAMIC_CLUT_LOAD_SUPPORT_NEEDED
            l_gfx_virtual_layer[i].CTRLDESCL4.B.LUOFFS = GFX_MGR02_NUM_OF_CLUTS;
        #endif
        }
        GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_55)
        while((l_gfx_mgr_edma_process_mode != GFX_MGR02_PMODE_IDLE) && 
              (l_gfx_mgr_shutdown_status   != GFX_MGR02_SHUTDOWN_EMERGENCY))
        {
            /*
            ** Wait while any of the blank area requests are pending
            */
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_56)
            HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
        }
    }
    else
    {
        /*
        ** nothing is active to be displayed
        ** In the next vblank isr we can disable all the layers.
        */
        for(i=0; i < GFX_MGR02_NUM_DCU_LAYERS; i++)
        {
            l_gfx_virtual_layer[i].CTRLDESCL4.B.EN = 0;
        }
        hmi_gfx_mgr02_mem_initialize();
        l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
    }
    return(fl_overlap_slayer);
}

#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 && !defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_text
 ** Visibility:       static
 ** Description:      tHandles the rendering for a text element.
 ** Invocation:       Invoked by hmi_gfx_mgr02_dma_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_render_text(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP)
{
    UINT32                       fl_wait_callback_response = FALSE;
    GFX_MGR02_TEXT_DEF_T const * fl_text_desc_prop_SP = &lc_text_layer_def_S[p_elem_list_SP->base_id];
    GFX_MGR02_GRAM_CHUNK       * fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
    GFX_MGR02_TEXT_INFO          fl_text_info_S;
    UINT32                       fl_return_sts = FALSE;
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
    UINT32 ret;
    UINT32 width;
    UINT32 height;
    UINT32 xbytes;
    UINT32 capinfo;
    UINT32 vertical_offset;
    Graphics_Object_t fl_source;
    Graphics_Object_t fl_target;
    UINT32   txt_font_width;
    UINT32 len, bmp_width;
    UINT16 *pstr;
    UINT8 *ExtFont_gdraw_area;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
    UINT8 fl_current_font_engine =  ui_app_get_cur_font_engine();
#endif
#endif
    if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
    {
      /*
      ** If the eDMA layers with overlapped memory allocation with active
      ** content need not be scheduled for a vblank build, then those
      ** layers memory status can be forced as GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED
      ** to force a build in the normal build operation itself.
      */
  #if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_VBLANK)
      if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_OVERLAP)
      {
         fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_WAIT_SYNC;
      }
  #else
      if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_OVERLAP)
      {
         fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED;
      }
  #endif
      if((fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED) &&
       (l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.TRANS != 0x00))
      {
          /*
          ** GRAM is not initialized yet. so initialize it before
          ** doing any printing operation
          */
        Graphics_Object_t fl_target;
        fl_target.height        = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
        fl_target.width         = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
        fl_target.BPP           = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
        fl_target.address       = fl_buff_ptr->address;
        fl_buff_ptr->status     = GFX_MGR02_GRAM_CHUNK_STS_INITED;
        if((fl_target.height != 0) && (fl_target.width != 0))
        {
           l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_UPDATE_GRAM;
           if(Graphics_BlankArea(GFX_MGR02_DMA_CHANNEL,
                                 &fl_target,
                                 0,
                                 &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
           {
              fl_wait_callback_response = TRUE;
           }
        }
        if(fl_wait_callback_response == FALSE)
        {
        #ifdef GFX02_DEBUG_ERROR
            gfx_debug("ERROR   - GRAM init failed for layer %d\n", l_gfx_mgr02_data_S.cur_build_layer);
        #endif
            /* If DMA start fails we should come out from the loop. */
            l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
            l_gfx_mgr02_data_S.cur_build_layer++;
        }
      }
      else if((fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_INITED) &&
              (l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.TRANS != 0x00))
      {
          UINT32 fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
          UINT32 fl_alignment;
          UINT32 fl_clip_mode;
          UINT32 fl_font_id;
          UINT32 fl_scroll_offset = 0;
          GFX_MGR02_ISIZE_W_T fl_text_width = 0;
          GFX_MGR02_FONT const * fl_font_SP;

          if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
          {
          #if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
             GFX_MGR02_TEXT_DYN_PROPERTY const * fl_text_dynamic_prop_SP = &l_layer_anim_data_SP->text_prop[fl_obj_id];
             fl_font_id   = fl_text_dynamic_prop_SP->font_id;
             fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_dynamic_prop_SP->alignment);
             fl_clip_mode = fl_text_dynamic_prop_SP->clip_mode;
             fl_scroll_offset = fl_text_dynamic_prop_SP->scroll_offset;
             fl_text_width = fl_text_dynamic_prop_SP->width;
          #endif
          }
          else
          {
          #if GFX_MGR02_NUM_TEXT_INSTANCES > 0
             fl_font_id   = fl_text_desc_prop_SP->font_id;
             fl_alignment = GFX_MGR02_GALIGNMENT(fl_font_id, fl_text_desc_prop_SP->alignment);
             fl_clip_mode = fl_text_desc_prop_SP->clip_mode;
             fl_text_width = fl_text_desc_prop_SP->width;
          #endif
          }
     
       #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT)
          hmi_gfx_mgr02_context_set_textprop(fl_font_id,
                                             fl_alignment,
                                             fl_text_desc_prop_SP->draw_mode,
                                             fl_clip_mode,
                                             fl_scroll_offset,
											 fl_text_width);

          fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
     #elif ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
        /*  RTC 133578 - issue fix provided by Sakai, Takayoshi (T.)
        fl_font_SP = &lc_gfx_font_table[fl_font_id]; */
        fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
		#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)	
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
			if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
		#endif
			{
		          txt_font_width = lc_gfx_digi_append_txt_font_width[fl_font_id];
			}
		#endif
		#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)) && defined(GFX_MGR02_KEPLER)
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
			else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
		#endif
			{
		         txt_font_width = lc_gfx_mono_append_txt_font_width[fl_font_id];
		    }
		#endif
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
			else
			{
			}
		#endif
       #else 
          #error "This GFX_MGR02_EXT_FONT_ENGINE option not supported"
       #endif

          if(fl_font_SP != GFX_MGR02_NULL_PTR)
          {
             if(fl_text_desc_prop_SP->dynamic != 0)
             {
             #if GFX_MGR02_NUM_OF_DTEXTS > 0
                fl_text_info_S.print_str_P = &l_layer_anim_data_SP->dtext_str[fl_text_desc_prop_SP->string_index];
             #endif
             }
             else
             {
             #if GFX_MGR02_NUM_OF_STEXTS > 0
                fl_text_info_S.print_str_P = (void *)&lc_static_text_buffer[fl_text_desc_prop_SP->string_index];
             #endif
             }
             fl_text_info_S.max_available_width = fl_text_width;
             fl_text_info_S.target              = GFX_MGR02_TARGET_DCU;
             /* 
             ** no hclip support as of now, so clamp the width to the available width 
             ** this is not required once we implement hclip for text
             */
             #if (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) 
               if(fl_text_info_S.max_available_width > l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT)
               {
                  fl_text_info_S.max_available_width = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
               }
               #else
               if(fl_text_info_S.max_available_width > l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH)
               {
                  fl_text_info_S.max_available_width = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
               }
             #endif

             fl_text_info_S.coord.x      = 0;
             fl_text_info_S.coord.y      = 0;
             fl_text_info_S.print_sindex_U8  = 0;
             l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_TEXT;
             fl_text_info_S.db_format    = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;

		  fl_text_info_S.num_chars_to_process = fl_text_desc_prop_SP->num_chars;
          #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT)
           #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
             fl_text_info_S.append_str = TRUE;
             l_dcu_clip_text_str[0] = 0;
           #else
             fl_text_info_S.append_str = FALSE;
           #endif
           #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
           fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
           #endif
             (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                          fl_font_id,
                                          fl_clip_mode,
                                          fl_alignment
                                        #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                         ,l_dcu_clip_text_str
                                        #endif
                                         );

             fl_return_sts = hmi_gfx_mgr02_font_fsl_edma_print(
                                    &fl_text_info_S,
                                    &hmi_gfx_mgr02_gram_print_done_isr,
                                    fl_buff_ptr->address,
                                    l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH,
                                    0,
                                    0);
             if(fl_return_sts != GFX_MGR02_FONT_ERROR_FAIL)
             {
                 fl_wait_callback_response = TRUE;
             }
             else
             {
                 l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                 l_gfx_mgr02_data_S.cur_build_layer++;
             }
        #elif (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE)
             fl_target.height        = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
             fl_target.width         = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
             fl_source.BPP = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
             len = HMI_STRLEN ((DT16_ushort*) fl_text_info_S.print_str_P);

             if((fl_text_info_S.print_str_P != GFX_MGR02_NULL_PTR) && (len <=fl_text_info_S.num_chars_to_process) &&
                (len > 0) )
             {
                pstr=(DT16_ushort*) fl_text_info_S.print_str_P;
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)				
                if(fl_current_font_engine == GFX_MGR02_DIGITYPE)
#endif
                {
                ret=digi_render_text(pstr,len, txt_font_width,\
                                 (UINT16)fl_source.BPP,(UINT32)0x100,\
                                 fl_target.width,fl_target.height,\
                                 &width, &height,&ExtFont_gdraw_area);
                }
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)		
                else if(fl_current_font_engine == GFX_MGR02_MONOTYPE)
#endif
                {
                ret=monotype_render_text(pstr,len, txt_font_width,\
                                 (UINT16)fl_source.BPP,(UINT32)0x100,\
                                 fl_target.width,fl_target.height,\
                                 &width, &height,&ExtFont_gdraw_area);
                }
#endif	
		#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGI_OR_MONO_TYPE)	
			else
			{
			}
		#endif
                bmp_width=width;
                xbytes        = width;
                fl_return_sts = FALSE;

                if(ret >= 0)
                {

                   fl_source.height = height;
                   fl_source.width  = xbytes;
                   fl_source.BPP = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
                 fl_source.address = (UINT32)&ExtFont_gdraw_area[0];
                   fl_source.x = fl_text_info_S.coord.x;
                   fl_source.y = fl_text_info_S.coord.y;

                   fl_target.height        = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.HEIGHT;
                   fl_target.width         = (UINT16)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL1.B.WIDTH;
                   fl_target.BPP           = (UINT8)l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer].CTRLDESCL4.B.BPP;
                   fl_target.address       = fl_buff_ptr->address;
                   l_gfx_mgr_edma_process_mode |= GFX_MGR02_PMODE_BUILD_WIDGET;
                   if(fl_source.width > fl_target.width)
                   {
                      fl_source.width = fl_target.width;
                   }
                   if((fl_source.height > 0) && (fl_target.height > 0))
                   {
                      if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                                        &fl_source,
                                        &fl_target,
                                        (UINT16)fl_source.x,
                                        (UINT16)fl_source.y,
                                        &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
                      {
                         fl_return_sts = TRUE;
                      }
                   }
                }
             }
             if(fl_return_sts != FALSE)
             {
                fl_wait_callback_response = TRUE;
             }
             else
             {
                l_gfx_mgr02_data_S.cur_build_layer++;
                l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
             }
          #endif /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_DIGITYPE) */
             fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
          }
      }
      else
      {
          /*
          ** The text is already up to date, no need to build it
          */
          l_gfx_mgr02_data_S.cur_build_layer++;
      }
    }
    return(fl_wait_callback_response);
}
#endif  /* GFX_MGR02_NUM_OF_TEXT_LAYERS */

#if GFX_MGR02_NUM_OF_SWDGS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_swidget
 ** Visibility:       static
 ** Description:      tHandles the rendering for a static widget.
 ** Invocation:       Invoked by hmi_gfx_mgr02_dma_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          18-Mar-2014 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_render_swidget(GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP, UINT32 fl_obj_id)
{
    struct DCU_LAYER_tag * fl_dcu_layer_SP  = &l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer];
    UINT32                 fl_wait_callback_response = FALSE;
    GFX_MGR02_GRAM_CHUNK * fl_buff_ptr               = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
    GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP = &lc_swidget_layer_def_S[fl_elem_list_SP->base_id];

    if(fl_widget_desc_SP->rr_engine != GFX_MGR02_RT_DEFAULT)
    {
        /*
        ** This layer is not built by DMA, so skipping
        */
        l_gfx_mgr02_data_S.cur_build_layer++;
    }
    else
    {
       /*
       ** If the eDMA layers with overlapped memory allocation with active
       ** content need not be scheduled for a vblank build, then those
       ** layers memory status can be forced as GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED
       ** to force a build in the normal build operation itself.
       */
       if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
       {
    #if (GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_VBLANK)
       if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_OVERLAP)
       {
          fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_WAIT_SYNC;
       }
    #else
       if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_OVERLAP)
       {
          fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED;
       }
    #endif
       if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED)
       {
           /*
           ** GRAM is not initialized yet. so initialize it before
           ** doing any printing operation
           */
           Graphics_Object_t fl_target;
           UINT32            fl_bg_fill_color;

           fl_bg_fill_color   = fl_widget_desc_SP->bg_fill_color;
           fl_target.height   = (UINT16)fl_dcu_layer_SP->CTRLDESCL1.B.HEIGHT;
           fl_target.width    = (UINT16)fl_dcu_layer_SP->CTRLDESCL1.B.WIDTH;
           fl_target.BPP      = (UINT8)fl_dcu_layer_SP->CTRLDESCL4.B.BPP;
           fl_target.address  = fl_buff_ptr->address;
           fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_INITED;
           if((fl_target.height != 0) && (fl_target.width != 0))
           { 
              l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_UPDATE_GRAM;
              if(Graphics_BlankArea(GFX_MGR02_DMA_CHANNEL,
                                    &fl_target,
                                    fl_bg_fill_color,
                                    &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
              {
                 fl_wait_callback_response = TRUE;
              }
           }
           if(fl_wait_callback_response == FALSE)
           {
           #ifdef GFX02_DEBUG_ERROR
               gfx_debug("ERROR   - GRAM init failed for layer %d\n", l_gfx_mgr02_data_S.cur_build_layer);
           #endif
               l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
               l_gfx_mgr02_data_S.cur_build_layer++;
           }
       }
       else if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_INITED)
       {
           l_widget_depth_level      = 0;
           l_widget_elem_path_SPA[0] = fl_elem_list_SP;
           l_widget_num_path_U8A[0]  = 0;
       #if defined(GFX_MGR02_WDG_ALPHA_CONTROL)
           fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_BUILT;
       #else
        #if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
           if(fl_widget_desc_SP->multicolor != 0)
           {
              fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_BUILT;
           }
           else
        #endif
           {
              fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
           }
       #endif
           /*
           ** Initialize the context for widget building
           ** offset location to 0, 0 and clip area to widgets bounds
           */
           l_widget_offset_loc[0].x = 0;
           l_widget_offset_loc[0].y = 0;
           {
              GFX_MGR02_VISIBLE_AREA * fl_context_clip = &l_gfx_mgr02_data_S.elem_area_sa[l_gfx_mgr02_data_S.cur_build_layer];
           #if defined(GFX_MGR02_CLIPPED_WIDGETS)
              l_widget_clip[0].sx = fl_context_clip->sx;
              l_widget_clip[0].sy = fl_context_clip->sy;
              l_widget_clip[0].ex = (fl_context_clip->sx+fl_context_clip->ex);
              l_widget_clip[0].ey = (fl_context_clip->sy+fl_context_clip->ey);
           #else
              fl_context_clip->ex += fl_context_clip->sx;
              fl_context_clip->ey  += fl_context_clip->sy;
           #endif
           }
           GFX_MGR02_UNUSED_VAR(fl_obj_id);
           fl_wait_callback_response = hmi_gfx_mgr02_print_widget();
       }
       else
       {
           l_gfx_mgr02_data_S.cur_build_layer++;
         }
       }
    }
    return(fl_wait_callback_response);
}
#endif  /* GFX_MGR02_NUM_OF_SWDGS */

#if defined(GFX_MGR02_BUILDALL_IN_GRAM) && (GFX_MGR02_NUM_OF_TILES > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_tile
 ** Visibility:       static
 ** Description:      Handles the rendering for a tile image.
 ** Invocation:       Invoked by dma_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          25-SEP-2013 by EMANOJ1
 ** Updated:          25-SEP-2013 by EMANOJ1
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_render_tile(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 fl_obj_id)
{
   GFX_MGR02_TILE_DEF_T  const * fl_tile_desc_SP  = &lc_tile_layer_def_S[p_elem_list_SP->base_id];
   GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP = &lc_image_layer_def_S[fl_tile_desc_SP->id];
   GFX_MGR02_GRAM_CHUNK  * fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
   UINT32 fl_wait_callback_response = FALSE;
   if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
   {
      if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED)
      {
         Graphics_Object_t fl_source;
         Graphics_Object_t fl_target;
         fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
         fl_source.width   = fl_image_desc_SP->width;
         fl_source.height  = fl_image_desc_SP->height; 
         fl_source.address = (UINT32)fl_image_desc_SP->pixel_data; 
         fl_target.width   = fl_image_desc_SP->width;
         fl_target.height  = fl_image_desc_SP->height; 
         fl_target.address = (UINT32)fl_buff_ptr->address; 
         fl_target.BPP     = fl_image_desc_SP->format;
         l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_IMAGE;
         if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                              &fl_source,
                              &fl_target,
                              0,
                              0,
                              &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
         {
            fl_wait_callback_response = TRUE;
         }
      }
   }
   if(FALSE == fl_wait_callback_response)
   {
      l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
      l_gfx_mgr02_data_S.cur_build_layer++;
   }
   return(fl_wait_callback_response);
}
#endif  /* #if defined(GFX_MGR02_BUILDALL_IN_GRAM) && (GFX_MGR02_NUM_OF_TILES > 0) */

#if defined(__GFX_MGR02_RLE_ENABLED) || defined(GFX_MGR02_BUILDALL_IN_GRAM)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_image
 ** Visibility:       static
 ** Description:      Handles the rendering for a static rle compressed image.
 **                   TODO : RLE unit supports only compressed size of 65535.
 **                          how to overcome...
 ** Invocation:       Invoked by dma_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          25-SEP-2013 by NKRISHN9
 ** Updated:          25-SEP-2013 by NKRISHN9
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_render_image(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 fl_obj_id)
{
   UINT32  fl_wait_callback_response = FALSE;
   GFX_MGR02_GRAM_CHUNK  * fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(l_gfx_mgr02_data_S.cur_build_layer);
   
   if(fl_buff_ptr != GFX_MGR02_NULL_PTR)
   {
     if(fl_buff_ptr->status == GFX_MGR02_GRAM_CHUNK_STS_ALLOCATED)
     {
        struct  DCU_LAYER_tag * fl_dcu_layer_SP  = &l_gfx_virtual_layer[l_gfx_mgr02_data_S.cur_build_layer];
        GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];

     #if defined(__GFX_MGR02_RLE_ENABLED)
        if(GFX_MGR02_IMAGE_COMPRESSION_HWRLE == fl_image_desc_SP->compression)
        {
           /*----------------------------------------------------------------------*/
           /* Set up the DMA channel for input to RLE decoder                      */
           /*----------------------------------------------------------------------*/
           if(Graphics_RleDmaSource((UINT32) fl_image_desc_SP->pixel_data, fl_image_desc_SP->height, fl_image_desc_SP->width)==GRAPHICS_ERROR_OK)
           {
              /*----------------------------------------------------------------------*/
              /* Set up the DMA channel for output from the RLE decoder               */
              /*----------------------------------------------------------------------*/
              if(Graphics_RleDmaDestination((UINT32)fl_buff_ptr->address, fl_image_desc_SP->height, fl_image_desc_SP->width)==GRAPHICS_ERROR_OK)
              {
                  fl_wait_callback_response   = TRUE;
                  fl_buff_ptr->status         = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
                  l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_IMAGE;
                  /*----------------------------------------------------------------------*/
                  /* Set up RLE decoder                                                   */
                  /*----------------------------------------------------------------------*/
                  Graphics_Initialize_RleImageDecoder(GFX_MGR02_RLE_BPP(fl_dcu_layer_SP->CTRLDESCL4.B.BPP), fl_image_desc_SP->comp_size, fl_image_desc_SP->height, fl_image_desc_SP->width,1,1,fl_image_desc_SP->width,fl_image_desc_SP->height);
                  /*----------------------------------------------------------------------*/
                  /* Start the RLE decoder                                                */
                  /*----------------------------------------------------------------------*/
                  Graphics_Start_RleImageDecoder();
              }
           }
        }
        else
     #endif
        {
        #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
           Graphics_Object_t fl_source;
           Graphics_Object_t fl_target;
           fl_buff_ptr->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
           fl_source.width   = fl_image_desc_SP->width;
           fl_source.height  = fl_image_desc_SP->height; 
           fl_source.address = (UINT32)fl_image_desc_SP->pixel_data; 
           fl_target.width   = fl_image_desc_SP->width;
           fl_target.height  = fl_image_desc_SP->height; 
           fl_target.address = fl_buff_ptr->address; 
           fl_target.BPP     = fl_image_desc_SP->format;
           l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_BUILD_IMAGE;
           if(Graphics_Paste(GFX_MGR02_DMA_CHANNEL,
                             &fl_source,
                             &fl_target,
                             0,
                             0,
                             &hmi_gfx_mgr02_gram_print_done_isr) == GRAPHICS_ERROR_OK)
           {
              fl_wait_callback_response = TRUE;
           }
        #endif
        }
        if(FALSE == fl_wait_callback_response)
        {
           l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
           l_gfx_mgr02_data_S.cur_build_layer++;
        }
     }
     else
     {
        /* The image is already up to date, no need to build it */
        l_gfx_mgr02_data_S.cur_build_layer++;
     }
   }
   
   GFX_MGR02_UNUSED_VAR(fl_obj_id);

   return(fl_wait_callback_response);
}
#endif  /* #if defined(__GFX_MGR02_RLE_ENABLED) || defined(GFX_MGR02_BUILDALL_IN_GRAM) */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_dma_render_loop
 ** Visibility:       static
 ** Description:      this function pre calculates everything for the rendering operation so that
 **                   the ISR task has minimum processing load.
 ** Invocation:       Invoked by hmi_gfx_mgr02_vblank_isr
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          14-Mar-2012 by EMANOJ1
 ** Updated:          14-Mar-2012 by ASHEKHAR
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_dma_render_loop(void)
{
    GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP;
    UINT32                        fl_obj_type;
    UINT32                        fl_obj_id;
    UINT32                        fl_wait_callback_response = FALSE;

    if(l_gfx_mgr02_data_S.visible_num_of_elements > 0)
    {
        while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
              (l_gfx_mgr02_data_S.cur_build_layer < l_gfx_mgr02_data_S.visible_num_of_elements) && 
              (fl_wait_callback_response == 0))
        {
            GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_57)

            fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[l_gfx_mgr02_data_S.cur_build_layer];

            if(fl_elem_list_SP != GFX_MGR02_NULL_PTR)
            {
                fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
                fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);
                
                if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
                {
                #if GFX_MGR02_NUM_OF_SWDGS > 0
                    fl_wait_callback_response = hmi_gfx_mgr02_render_swidget(fl_elem_list_SP, fl_obj_id);
                #endif
                }
                else if((fl_obj_type == GFX_MGR02_TYPE_STEXT) ||
                        (fl_obj_type == GFX_MGR02_TYPE_DTEXT))
                {
                #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
                    #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
                       hmi_gfx_mgr02_ovg_text_print_text();
                    #else
                       fl_wait_callback_response = hmi_gfx_mgr02_render_text(fl_elem_list_SP);
                    #endif
                #else
                 #ifdef GFX02_DEBUG_ERROR
                    gfx_debug("ERROR   - l_gfx_mgr02_data_S.visible_num_of_elements(%d) > GFX_MGR02_NUM_DCU_LAYERS\n", l_gfx_mgr02_data_S.visible_num_of_elements);
                 #endif
                #endif  /* GFX_MGR02_NUM_OF_TEXT_LAYERS > 0 */
                }
            #if defined(__GFX_MGR02_RLE_ENABLED) || defined(GFX_MGR02_BUILDALL_IN_GRAM)
                else if(fl_obj_type == GFX_MGR02_TYPE_SIMAGE)
                {
                #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
                    fl_wait_callback_response = hmi_gfx_mgr02_render_image(fl_elem_list_SP, fl_obj_id);
                #endif
                }
            #endif
            #if defined(GFX_MGR02_BUILDALL_IN_GRAM)
                else if(fl_obj_type == GFX_MGR02_TYPE_TILE)
                {
                #if  GFX_MGR02_NUM_OF_TILES > 0
                    fl_wait_callback_response = hmi_gfx_mgr02_render_tile(fl_elem_list_SP, fl_obj_id);
                #endif
                }
            #endif
                else
                {
                    l_gfx_mgr02_data_S.cur_build_layer++;
                }
            }
            else
            {
                l_gfx_mgr02_data_S.cur_build_layer++;
            }
        }
        if(l_gfx_mgr02_data_S.cur_build_layer >= l_gfx_mgr02_data_S.visible_num_of_elements)
        {
            l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
            gfxlogend(GFX_LOG_DCU_EDMA);
        }
    }
    else
    {
        /*
        ** This should never happen, disabling all layers as an error
        ** handling mechanism.
        ** At this point none of the layers need to be active, so disable all layers
        */
        l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
        gfxlogend(GFX_LOG_DCU_EDMA);
    }
    return(fl_wait_callback_response);
}

#if GFX_MGR02_BG_RENDERING > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_bg_render_loop
 ** Visibility:       static
 ** Description:      Handles the backgrpund rendering for user images,
 **                   software & openVG widgets 
 ** Invocation:       Invoked by hmi_gfx_mgr02_dma_render_loop
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          23-Feb-2013 by EMANOJ1
 ** Updated:          23-Feb-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_bg_render_loop(UINT32 p_cur_layer)
{
    GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP = l_gfx_mgr02_data_S.next_elem_list_sa[p_cur_layer];
    
    if(fl_elem_list_SP != (GFX_MGR02_ELEM_LIST_T *)0)
    {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
        switch(fl_obj_type)
        {
        #if GFX_MGR02_NUM_USER_LAYERS > 0
            case GFX_MGR02_TYPE_USER_LAYER:
            {
               hmi_gfx_mgr02_render_user_layer(fl_elem_list_SP->base_id);
            }
            break;
        #endif
        #if GFX_MGR02_NUM_OF_SWDGS > 0
            case GFX_MGR02_TYPE_SWIDGET:
            {
               hmi_gfx_mgr02_bg_render_swidget(fl_elem_list_SP, p_cur_layer);
            }
            break;
        #endif

            default:
            {
            	/*For MISRA warning fix.*/
            }
            break;
        }
    }
}

#if GFX_MGR02_NUM_OF_SWDGS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_bg_render_swidget
 ** Visibility:       static
 ** Description:      Handles the backgrpund rendering for non DMA widgets
 **                   (software & openVG widgets) 
 ** Invocation:       Invoked by hmi_gfx_mgr02_build_screen
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          28-Feb-2013 by EMANOJ1
 ** Updated:          28-Feb-2013 by EMANOJ1
 **==========================================================================*/
static void hmi_gfx_mgr02_bg_render_swidget(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_cur_layer)
{
   struct DCU_LAYER_tag * fl_dcu_layer_SP = &l_gfx_virtual_layer[p_cur_layer];
   UINT32 fl_clear_buffer = FALSE;
   UINT32 fl_clear_color  = 0;

   if(fl_dcu_layer_SP->CTRLDESCL4.B.EN != 0)
   {
      GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
   #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)
      GFX_MGR02_CONTEXT_GB_T   fl_build_elem_S;
      GFX_MGR02_VISIBLE_AREA * fl_context_clip = &l_gfx_mgr02_data_S.elem_area_sa[p_cur_layer];
      UINT32                   fl_obj_id       = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);

      GFX_MGR02_GRAM_CHUNK * fl_buff_ptr;
      fl_buff_ptr = hmi_gfx_mgr02_get_front_buffer(p_cur_layer);
      if( fl_buff_ptr != GFX_MGR02_NULL_PTR )
      {
        fl_build_elem_S.render_buffer = (void *)fl_buff_ptr->address;
      }
      else
      {
        fl_build_elem_S.render_buffer = GFX_MGR02_NULL_PTR;
      }
      if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
      {
      #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
          if(fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE)
          {
             GFX_MGR02_WIDGET_DYN_PROPERTY const * fl_wdgt_anim_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
             fl_build_elem_S.area.x = fl_wdgt_anim_prop_SP->coord.x;
             fl_build_elem_S.area.y = fl_wdgt_anim_prop_SP->coord.y;
             fl_clear_buffer        = TRUE;
             fl_clear_color         = fl_widget_desc_SP->bg_fill_color;
          }
          else
          {
             fl_build_elem_S.area.x = lc_widget_anim_property_S[fl_obj_id].coord.x;
             fl_build_elem_S.area.y = lc_widget_anim_property_S[fl_obj_id].coord.y;
          }
      #endif
      }
      else
      {
      #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
          fl_build_elem_S.area.x = lc_swdg_const_property_S[fl_obj_id].coord.x;
          fl_build_elem_S.area.y = lc_swdg_const_property_S[fl_obj_id].coord.y;
      #endif
      }
   #endif

      switch(fl_widget_desc_SP->rr_engine)
      {
      #if defined(GFX_MGR02_OPEN_VG)
          case GFX_MGR02_RT_OPENVG:
          {
             GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_cur_layer);
             if(fl_gram_chunk_SP != GFX_MGR02_NULL_PTR)
             {
               /* 
               ** no need to build again if the content is active / nothing changed
               */
               if(fl_gram_chunk_SP->status != GFX_MGR02_GRAM_CHUNK_STS_ACTIVE)
               {
                  fl_build_elem_S.client_id   = (UINT32)fl_widget_desc_SP->client_id;
                  fl_build_elem_S.area.width  = (UINT16)fl_context_clip->ex;
                  fl_build_elem_S.area.height = (UINT16)fl_context_clip->ey;
                  fl_build_elem_S.fb_target   = GFX_MGR02_TARGET_OPENVG;
                  fl_build_elem_S.fb_format   = fl_widget_desc_SP->fb_format;
                  fl_build_elem_S.clr_buffer  = fl_clear_buffer;
                  fl_build_elem_S.clr_color   = fl_clear_color;
                  gfxlogcontinue(GFX_LOG_DCU_OPENVG);
                  if(hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, p_elem_list_SP) != FALSE)
                  {
                     if(fl_build_elem_S.render_buffer != (void *)0)
                     {
                     #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
                        fl_gram_chunk_SP->address = (UINT32)fl_build_elem_S.render_buffer;
                     #else
                        /*
                        ** When the off screen build option is enabled, we have to copy the
                        ** openvg buffer in to the build gram area so that all of the dcu
                        ** contents can be contained with in gram and we could do a single
                        ** dma transfer to display gram area
                        */
                        while((l_gfx_mgr_edma_process_mode != GFX_MGR02_PMODE_IDLE) && 
                              (l_gfx_mgr_shutdown_status   != GFX_MGR02_SHUTDOWN_EMERGENCY))
                        {
                           /*
                           ** Wait until any eDMA operation in progress finishes.
                           */
                           HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
                           GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_58)
                        }
                        if(l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY)
                        {
                           l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_SWAP_GRAM;
                           if(hmi_gfx_mgr02_memcpy_64bit((UINT32)fl_build_elem_S.render_buffer, 
                                                         (UINT32)fl_gram_chunk_SP->address,
                                                         fl_gram_chunk_SP->size) == DMA_NO_ERROR)
                           {
                              /*
                              ** Wait until the transfer is done
                              */
                              while((l_gfx_mgr_edma_process_mode == GFX_MGR02_PMODE_SWAP_GRAM) && 
                                    (l_gfx_mgr_shutdown_status   != GFX_MGR02_SHUTDOWN_EMERGENCY))
                              {
                                 HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
                                 GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_59)
                              }
                           }
                           else
                           {
                              l_gfx_mgr_edma_process_mode = GFX_MGR02_PMODE_IDLE;
                           }
                        }
                     #endif
                        fl_gram_chunk_SP->status  = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
                     }
                  }
                  gfxlogend(GFX_LOG_DCU_OPENVG);
               }
               if(fl_gram_chunk_SP->status == GFX_MGR02_GRAM_CHUNK_STS_ACTIVE)
               {
               #if (GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN)
                  if(fl_gram_chunk_SP->address != 0)
                  {
                     /* 
                     ** if vclip is active, CTRLDESCL3.R contains the framebuffer start offset
                     ** in bytes, so we are adding this to the base address of the frame buffer
                     */
                     fl_dcu_layer_SP->CTRLDESCL3.R += fl_gram_chunk_SP->address;
                     /*
                     ** fl_dcu_layer_SP->CTRLDESCL4.B.EN might be disabled
                     ** due to vclip, so we shall not enable here forcefully
                     */
                  }
                  else
                  {
                     fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
                  }
               #endif
               }
               else
               {
                  fl_dcu_layer_SP->CTRLDESCL4.B.EN = 0;
               }
             }
          }
          break;
      #endif
      #if defined(GFX_MGR02_SOFTWARE)
          case GFX_MGR02_RT_SOFTWARE:
          {
             GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_cur_layer);
             if(fl_gram_chunk_SP->status != GFX_MGR02_GRAM_CHUNK_STS_ACTIVE)
             {
                fl_build_elem_S.client_id   = (UINT32)fl_widget_desc_SP->client_id;
                fl_build_elem_S.area.width  = (UINT16)fl_context_clip->ex;
                fl_build_elem_S.area.height = (UINT16)fl_context_clip->ey;
                fl_build_elem_S.fb_target   = GFX_MGR02_TARGET_SOFTWARE;
                fl_build_elem_S.fb_format   = fl_widget_desc_SP->fb_format;
                fl_build_elem_S.clr_buffer  = FALSE;
                fl_build_elem_S.clr_color   = 0;
                hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, p_elem_list_SP);
             }
          }
          break;
      #endif
          case GFX_MGR02_RT_DEFAULT:
          {
          #if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT) || defined(GFX_MGR02_WDG_ALPHA_CONTROL)          
           #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT)
             while((l_gfx_mgr_shutdown_status != GFX_MGR02_SHUTDOWN_EMERGENCY) &&
                   (l_gfx_mgr02_data_S.cur_build_layer <= p_cur_layer))
             {
                HMI_GFX_MGR02_DEBUG_PROCESS_MSG()
                GFX_MGR_TEST_SHUTDOWN(__GFX_MGR02_60)
             }
             gfxlogcontinue(GFX_LOG_DCU_MULTICOLOR);
            #if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
             hmi_gfx_mgr02_pp_multicolor_widget(p_elem_list_SP, p_cur_layer, fl_widget_desc_SP->multicolor);
            #elif defined(GFX_MGR02_WDG_ALPHA_CONTROL)
             hmi_gfx_mgr02_pp_multicolor_widget(p_elem_list_SP, p_cur_layer, 0);
            #endif
             gfxlogend(GFX_LOG_DCU_MULTICOLOR);
           #else  /*#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT) */
             GFX_MGR02_GRAM_CHUNK * fl_gram_chunk_SP = hmi_gfx_mgr02_get_front_buffer(p_cur_layer);
             fl_gram_chunk_SP->status = GFX_MGR02_GRAM_CHUNK_STS_ACTIVE;
           #endif
          #endif
          }
          break;
          default:
          {
        	  /*For MISRA warning fix.*/
          }
          break;
      }
   }
}
#endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
#endif /* #if GFX_MGR02_BG_RENDERING > 0 */
#ifndef WIN32
#pragma pop
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
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 ** CMS Rev 1.86     08-Oct-2018    KKUBENDI
 ** 1212607: In MAL Y dir animation, text is moving in opposite direction - DCU platform/
             AntiClockwise rotation
 ** CMS Rev 1.85     05-Jun-2018    ARAJASE2
 ** 1131764: Hyundai AE/PE : Clockwise Rotation support in Kepler1
 **
 ** CMS Rev 1.84     10/01/18    ADEVI
 ** 1004848 : Clip information fectched from application and Append string located based on app input.
 **
 ** CMS Rev 1.83     23/08/17    SBOLLAM
 ** 935152 : Red pixels are apprearing while text scrolls in multi-color widget.
 **
 ** CMS Rev 1.82     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 1.81     04/08/17    ADEVI
 ** 924879 : Monotype Font Integration in Kepler I.
 **
 ** CMS Rev 1.80     06-JUL-2017    ADEVI
 ** RTC ID: 871825:  Changes to support MONOTFT Platform
 **
 ** CMS Rev 1.79     16-DEC-2016  CSAKTHIV
 **	791453 Layer is allocated for invisible low priority screen as clip set is not considered. 
 **
 ** CMS Rev 1.78     16-DEC-2016  EMANOJ1
 ** Faraday Future - Touch object auto selection does not work (RTC : 767349)
 ** Updates due to function prototype change
 **
 ** CMS Rev 1.77     02-Jun-16    SBOLLAM
 ** GFX_MGR02_BUILD_EXCEED_THAN_VBLANK_HANDLING macro added for P552 L1
 ** display scramble issue fix.
 ** Ref RTC# 639198.
 **
 ** CMS Rev 1.76     11-Apr-2016    ADEVI
 ** RTC 5570947:
 ** Right aligned text scroll for Hyundai AE SVC.
 **
 ** CMS Rev 1.75     02-Mar-2015    APERUMAL
 ** RTC 536473:
 ** Initialised default value for fl_text_info_S.dyn_text_def_SP
 ** To fix coverity warning 11156 for Hyundai AE
 **
 ** CMS Rev 1.74     11-Feb-2015    ADEVI
 ** RTC 520133:
 ** Issue in MFD.  One pixel truncation for alignment change from left to right.
 ** Issue observed in ovglib.c.  Issue reproduced in DCU.
 **
 ** CMS Rev 1.73     29-Jan-2015    APERUMAL
 ** RTC 507885:
 ** QAC warnings fix for Honda Thaa
 **
 ** CMS Rev 1.72     12-Nov-2015   SBOLLAM
 ** Ref RTC# 464097
 ** Fixed reset issue, found after enabling "DMA N CPU" 
 ** render option in GDT
 **
 ** CMS Rev 1.71     22-Aug-2015   APERUMAL
 ** Ref RTC# 405974
 ** QA C warnings fix for Honda Thaa
 **
 ** CMS Rev 1.70     28-Jul-2015   EMANOJ1
 ** Ref RTC# 389021
 ** Fixed issue where user type image is not shown in GFX_MGR02_BUILDALL_IN_GRAM
 ** build option
 **
 ** CMS Rev 1.69     21-Jul-2015   EMANOJ1
 ** Ref RTC# 309515
 ** hmi_gfx_mgr02_vblank_isr() updated to consider vsync or dma transfer finish
 ** rather than dma transfer finish alone for triggering build and copy operations
 ** due to the fact that, under high load conditions there is a chance that dcu
 ** will not trigger a dma transfer finish isr. And it might result in an endless
 ** wait & finally the DI Kernel to trigger a Graphics task timeout reset.
 **
 ** CMS Rev 1.68     17-Jun-2015   EMANOJ1
 ** Ref RTC# 360402
 ** Fixed a memory allocation issue for text layer when rotated display option is
 ** used. In rotated display option, the font height was made a multiple of 8 bytes
 ** to meet DCU requirement, but this was not considered for GRAM allocation. This
 ** caused less bytes than what is actually needed is getting allocated. 
 **
 ** CMS Rev 1.67     05-Jun-2015   EMANOJ1
 ** Ref RTC# 352764
 ** Updated to fix a horizontal alignment issue for text reported by P552 team
 **
 ** CMS Rev 1.66     02-Apr-2015   EMANOJ1
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
 ** CMS Rev 1.65    19-Jan-2015    ADEVI
 ** Ref RTC# 270611, 259720.
 ** Horizontal scroll implementation done for DCU(4/8BPP) with rotation disabled.
 ** Few compilation warnings resolved.
 ** Ref : RTC# 271822.
 ** Alpha reset issue. Centre aligned text when alpha is applied negative values
 ** are getting passed to multi_alpha_area function.  When anti clockwise rotation
 ** is enabled, then fl_sx need to be added with fl_sheight.
 **
 ** CMS Rev 1.64     07-Jan-2015    EMANOJ1
 ** Rtc#265549 : Updated to allow a quick fix in hmi_gfx_mgr02_mem.c for this RTC
 ** Rtc#265877 : Compiler warning updates (reported by Porche team)
 ** 
 ** CMS Rev 1.63     06-Jan-2015    EMANOJ1
 ** Ref : RTC#209820 : Red dot in multicolor widget
 ** Due to 1 pixel error in start X calculation, one pixel line is not converted 
 ** for multicolor and appears as a junk color.
 **
 ** CMS Rev 1.62     17-Dec-2014    ADEVI
 ** Ref : RTC# 254318, 258072
 ** Compiler warning in variable initialisation (f1_scroll_print_str_P) resolved.  
 ** Alpha issue with anti clockwise rotation set is resolved in 
 ** hmi_gfx_mgr02_pp_multi_color_widget_text. 
 **
 ** CMS Rev 1.61     10-Dec-2014    EMANOJ1
 ** Ref RTC 253865 : hmi_gfx_mgr02_build_widget updated to fix a clip issue.
 **
 ** CMS Rev 1.60     17-Nov-2014    ADEVI
 ** Ref : RTC# 204201,240749   : Peer Review ID 80425.
 ** In hmi_gfx_mgr02_print_widget_text typecasting done for f1_soffset.
 ** For anti clockwise rotated text with scroll, the text string taken completely.  
 **
 ** CMS Rev 1.59     14-Nov-2014    ADEVI
 ** Ref : RTC# 204201,240749   : Peer Review ID 80425.
 ** In hmi_gfx_mgr02_print_widget_text f1_soffset calculation modified.
 **
 ** CMS Rev 1.58     13-Nov-2014    ADEVI
 ** Ref RTC# 239784.
 ** #if GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1 check always used along with.
 ** GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1 since for text only anti-
 ** clockwise rotation support is provided now.
 **
 ** CMS Rev 1.57     11-Nov-2014    ADEVI
 ** Ref RTC# 204201.
 ** In hmi_gfx_mgr02_print_widget_text function the scroll offset value is 
 ** considered before printing the text.
 **
 ** CMS Rev 1.56     10-Nov-2014    EMANOJ1
 ** Changes due to function prototype changes while adding Spansion Iris engine 
 ** Amber-I changes for Kepler2.
 **
 ** CMS Rev 1.55     30-Oct-2014    ADEVI
 ** RTC 204201: For DCU rotation support of text with font height not in multiple
 **              of 8, the width of the text box is adjusted to the nearest multiple
 **              of 8.
 **
 ** CMS Rev 1.54     07-Oct-2014    EMANOJ1
 ** RTC 226370 : Fixed reset & scramble issue reported by the TLC team when 
 ** they use rotated TFT mode. it was duw to improper loading of l_target_go.height &
 ** l_target_go.width when clipped widget is not present.
 ** Integrated RTC:168062 changes from Kalaiselvi, Radhakrishnan (R.) <rkalaise@visteon.com>
 **
 ** CMS Rev 1.54     07-Oct-2014    EMANOJ1
 ** Robustness measure per coverity #11118 reported by P42M
 **
 ** CMS Rev 1.53     17-Jul-2014    EMANOJ1
 ** hmi_gfx_mgr02_emergency_shutdown and hmi_gfx_mgr02_rle_isr updated to make 
 ** sure the eDMA is not shutdown during an emergency shutdown request until
 ** RLE operation is in progress. This was done to fix a RLE hang issue which 
 ** triggered a reset in P42M. As per current understanding, when we shut down
 ** the memory and abort eDMA, the RLE module might have been in the middle of
 ** a decompression. It might still have some input data, so when we try to resume
 ** operation the RLE starts operating on some invalid old data left over in 
 ** the FIFO instead of the new image you are pushing in the FIFO. So this fix
 ** will make sure current RLE operation is completed before the shutdown is 
 ** performed.
 ** 
 ** CMS Rev 1.52     19-May-2014    EMANOJ1
 ** >RTC defect #156505 - fixed hang issue noted in a while loop after 
 ** hmi_gfx_mgr02_emergency_shutdown api call. The DCU was disabled and the cur 
 ** layer never advanced causing a "for ever while loop"
 ** while(l_gfx_mgr02_data_S.cur_build_layer <= p_cur_layer)
 **  @ line 6951 - hmi_gfx_mgr02_bg_render_swidget()
 **  @ line 1289 - hmi_gfx_mgr02_build_screen()
 ** >Fixed P42M coverity issue related to uninitialized variable
 **  @  hmi_gfx_mgr02_render_text()
 **
 ** CMS Rev 1.51     21-Mar-2014    EMANOJ1
 ** hmi_gfx_mgr02_load_active_cluts() updated to disable the layer if its 
 ** CLUT cannot be loaded.
 **
 ** CMS Rev 1.50     18-Mar-2014    EMANOJ1
 ** Fixed wrong loading of widget background fill color in function 
 ** hmi_gfx_mgr02_render_swidget()
 **
 ** CMS Rev 1.49     20-Feb-2014    EMANOJ1
 ** In order to support hmi_gfx_mgr02_generic_get_element_bound() API changes 
 ** due to RTC 121262
 **
 ** CMS Rev 1.48     10-Feb-2014    EMANOJ1
 ** >Fixed the sporadic header content missing issue reported in P42M. The issue
 ** was due to the fact that l_gfx_mgr_process_gt_mode was not initialized to IDLE
 ** before call to hmi_gfx_mgr02_dma_render_loop() in hmi_gfx_mgr02_build_screen()
 ** This caused the hmi_gfx_mgr02_bg_gram_print_handler() to be entered with 
 ** l_gfx_mgr_process_gt_mode = GFX_MGR02_PMODE_INIT_GRAM if the DMA ISR didn't
 ** triggered before the while loop in hmi_gfx_mgr02_bg_gram_print_handler(). In this
 ** case the while loop will break and hmi_gfx_mgr02_gram_print_done() will be called
 ** without actual DMA ISR and will cause the current layer to be skipped and move to
 ** the next layer.
 ** >isel instruction usage is disabled per ui.core.gdt.doc\hmi.gfx.manager.02\release\SR# 1-1248551151.msg
 **
 ** CMS Rev 1.47     23-Jan-2014    EMANOJ1
 ** Updated hmi_gfx_mgr02_print_widget_text to fix a one pixel error in fl_sx
 ** calculation which resulted in a fl_sx going out of bound and text not getting
 ** displayed in GFX_MGR02_TP_ALIGN_RIGHT configuration.
 **
 ** CMS Rev 1.46     21-Jan-2014    EMANOJ1
 ** Merged tsakai2 changes for multi color support with digitype integrated. 
 **
 ** CMS Rev 1.45     17-Jan-2014    EMANOJ1
 ** Updated to solve simulation hang issue.
 ** Updated to fix GFX_MGR02_GRAM_CHUNK ->status update issues for
 ** GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN build.
 **
 ** CMS Rev 1.44     08-Jan-2014    EMANOJ1
 ** Updated hmi_gfx_mgr02_bg_gram_print_handler to address a possible lock situation
 ** where hmi_gfx_mgr02_gram_print_done is not triggering a DMA transfer and then 
 ** the while loop while(l_gfx_mgr_process_gt_mode == GFX_MGR02_PMODE_IDLE); waiting
 ** for ever for a DMA completion. The fix is to check also the dma process mode
 ** l_gfx_mgr_edma_process_mode as well in the while loop.
 **
 ** CMS Rev 1.43     07-Jan-2014    EMANOJ1
 ** In the case of GFX_MGR02_GRAM_OVERAP_HANDLING == GFX_MGR02_BUILD_DCU_OFSCRN
 ** >> Updated to fix issue with graphics memory handling for openvg widget layers
 **    just like normal widgets
 ** >> Updated the copy from EGL buffer to layer buffer is changed to use eDMA to
 **    improve copy time.
 **
 ** CMS Rev 1.42     02-Jan-2014    EMANOJ1
 ** GFX_MGR02_BUILDALL_IN_GRAM config - Continous rebuild issue of image and 
 ** tile layer due to non setting of fl_buff_ptr->status to 
 ** GFX_MGR02_GRAM_CHUNK_STS_ACTIVE fixed
 **
 ** CMS Rev 1.41     18-Dec-2013    EMANOJ1
 ** Issue fixed with unnecessary memory allocation for image layer when
 ** GFX_MGR02_GRAM_OVERAP_HANDLING != GFX_MGR02_BUILD_DCU_OFSCRN fixed
 **
 ** CMS Rev 1.40     17-Dec-2013    EMANOJ1
 ** Integrated digitype font engine implementation by ABALAJI/TSAKAI2
 ** Added GFX_MGR02_GRAM_OVERAP_HANDLING = GFX_MGR02_BUILD_DCU_OFSCRN option
 ** to address flicker issues noticed in P42M
 ** Integrated RLE changes by krishnamoorthy.
 ** 
 ** CMS Rev 1.39     09-Dec-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_pp_multi_alpha_area to fix the fl_sbuffer_U8P calculation
 ** where the start x offset was not divided by 2 to cater to the 4bpp buffer ealier.
 ** this reulted in wrong start pointer calculation and if the text was not located at
 ** x = 0, then the alpha conversion was not done to entire text.
 **
 ** CMS Rev 1.38     08-Dec-2013    EMANOJ1
 ** Fixed issue with append text not showing ... when inside a widget
 ** Fixed issue with image inside a widget when clipping support is not enabled
 ** Fixed contimoos openvg layer building even when nothing is changed
 ** (hmi_gfx_mgr02_bg_render_swidget)
 ** TODO : When clipping support is not enabled, multi color text are not working
 **
 ** CMS Rev 1.37     22-Nov-2013    EMANOJ1
 ** Completed hmi_gfx_mgr02_pp_multi_alpha_area
 ** Fixed an issue with clipped image copy in widgets.
 ** Issue was that when vclip was enabled, the graphics paste was invoked
 ** with target width/height information from l_gfx_virtual_layer[]. In this case
 ** it contained clipped height information and there fore the full image did 
 ** not got copied. To fix hmi_gfx_mgr02_print_widget_image() updated to get 
 ** the target width and height from elem_area_sa[]
 **
 ** CMS Rev 1.36     21-Nov-2013    EMANOJ1
 ** hmi_gfx_mgr02_build_widget updated to fix issue of a vclip disabled layer
 ** getting enabled again.
 ** WIP : hmi_gfx_mgr02_pp_multi_alpha_area 
 **
 ** CMS Rev 1.35     09-Nov-2013    EMANOJ1
 ** Fixed an issue where where back to back RLE requests were not working.
 ** Added a wait loop inside RLE ISR to make sure the destination DMA transfer
 ** is completed before setting up the next RLE decompression request. This is
 ** a quick fix as of now and remain until we find a better solution where
 ** we could avoid this wait loop.
 **
 ** CMS Rev 1.34     07-Nov-2013    EMANOJ1
 ** Integrated the RLE code from Krishnamoorthy and small updates to set the
 ** compiler switched for RLE correctly.
 **
 ** CMS Rev 1.33     29-Oct-2013    EMANOJ1
 ** GFX_MGR02_BUILD_W_WORKBUF option added in previous version removed as the 
 ** target evaluation had shown no improvement.
 **
 ** CMS Rev 1.32     26-Oct-2013    EMANOJ1
 ** hmi_gfx_mgr02_pp_multi_color_widget_elements and hmi_gfx_mgr02_print_widget_elements
 ** updated not to add widget offset to the clip start xy in case the widget 
 ** doesnot have clip enabled. This is done to fix incorrect multi color text 
 ** update when a text is animated on the y direction.
 ** After pre-render all gram reference is changed to take from front buffer.
 **
 ** CMS Rev 1.31     25-Oct-2013    EMANOJ1
 ** l_gfx_mgr_process_mode usage for eDMA and Vsync ISR was causing issues 
 ** because of the use the DCU_TRANSFER_FINISH in 1.30, it caused some of
 ** the DCU layer copy request to be not happening due to eDMA call back 
 ** forcefully clearing the variable. So just to be on a safer side
 ** made this in to two variables, one for eDMA and one for vsync
 ** Additional option to build overlapped layers alone in workbuffer 
 ** implementation is in progress.
 **
 ** CMS Rev 1.30     21-Oct-2013    EMANOJ1
 ** hmi_gfx_mgr02_build_screen, hmi_gfx_mgr02_vblank_isr updated to first 
 ** schedule eDMA build of non overlapped memory content first and then the 
 ** overlapped content is done along with layer programming from the VBLANK ISR.
 ** Now the eDMA content building is started from the DCU_TRANSFER_FINISH
 ** ISR itself.
 ** Scheduling of animation tick from vsync ISR made configurable to give
 ** applications more control.
 **
 ** CMS Rev 1.29     21-Oct-2013    EMANOJ1
 ** hmi_gfx_mgr02_pp_multi_color_widget_elements :- 
 **   1. Multicolor text indefinite recursion in function fixed. 
 **   2. Fixed incorrect clip area handling resulted in passing invalid clip to
 **      multi color element process functions resulting non post processing of
 **      those elements
 **
 ** CMS Rev 1.28     19-Sep-2013    EMANOJ1
 ** Implemented multicolor text support. Image support not implemented.
 **
 ** CMS Rev 1.27     30-Aug-2013    EMANOJ1
 ** l_gfx_mgr_process_mode flag usage has been updated to avoid any stuckup issues
 ** Now this flag will be set before a DMA operation trigger and will be cleared
 ** immediately if the DMA trigger failed. Thereby making sure that this flag 
 ** will not get set indefenitly if the DMA trigger request itself was failed.
 ** In the process also removed the bitwise OR and AND operations that were 
 ** done with this flag.
 **
 ** CMS Rev 1.26     27-Aug-2013    EMANOJ1
 ** Updated to support the infrastructure DMA manager core package instead of the
 ** freescale DMA.c
 **
 ** CMS Rev 1.25     26-Aug-2013    EMANOJ1
 ** hmi_gfx_mgr02_get_widget_layer_area updated to support dynamic buffer 
 ** allocation for OpenVG widgets with clip=false setting. Also updated 
 ** hmi_gfx_mgr02_bg_render_swidget to perform clearing of background for
 ** clip=false widgets as these widgets needs to be rebuilt every time they
 ** change. To do this hmi_gfx_mgr02_generic_build_dcu_gen_widget updated to
 ** accept more parameters.
 **
 ** CMS Rev 1.24     19-Aug-2013    EMANOJ1
 ** Added a target parameter for text width calculation and printing as the 
 ** text.c has been updated to utilize this parameter.
 **
 ** CMS Rev 1.23     14-Aug-2013    EMANOJ1
 ** Compiler switch adjustment related to user type images.
 **
 ** CMS Rev 1.22     11-Jul-2013    EMANOJ1
 ** More error protection added before DMA initiation
 ** hmi_gfx_mgr02_manage_layers updated to break the loop if the layers are reserved
 ** for the high priority active screen.
 **
 ** CMS Rev 1.21     11-Jul-2013    KPALAMA1
 ** Corrected the variable used in hmi_gfx_mgr02_init_for_EOL_mode from 
 ** enable_test_pattern to p_enable_test_pattern.
 **
 ** CMS Rev 1.20     04-Jul-2013    EMANOJ1
 ** hmi_gfx_mgr02_pre_render_loop() updated not to cause a widget front to
 ** back buffer copy if the change is happening only in a openvg widget.
 ** openvg widgets has memory allocated by EGL and therefore the other edma
 ** widgets can hold their memory as is.
 ** TODO : hmi_gfx_mgr02_font_fsl_edma_print() handle the case where the
 ** text printing finishes even before this function returns.
 **
 ** CMS Rev 1.19     19-Jun-2013    EMANOJ1
 ** Added GFX_MGR02_SYNCHRONISE_DMA_BUILD_WITH_VBLANK option to have eDMA 
 ** rendering to be triggered regardless of VBLANK sync. See .$cfg for more
 ** details.
 **
 ** CMS Rev 1.18     18-Jun-2013    EMANOJ1
 ** Reworked pre-render, memory allocation operations to makesure we don't 
 ** rebuild GRAM contents if the change is in the parent which can be applied
 ** directly to DCU layers example if the position of the parent objects
 ** changes, it need not be rebuilt again we could just program the DCU layers 
 ** to make the operations faster.
 **
 ** CMS Rev 1.17     12-Jun-2013    EMANOJ1
 ** right2left handling added with the help of GFX_MGR02_GALIGNMENT()
 ** Add code to handle the case of dynamic modification of text alignment
 **
 ** CMS Rev 1.16     11-Jun-2013    EMANOJ1
 ** hmi_gfx_mgr02_set_vclip() further updated to handle the tile when the layer
 ** height > tile image height.
 ** Fixed an issue where one of the widget layer memory was getting swapped with 
 ** another widget and the content getting displayed wrongly as a result. The
 ** root cause was that for a particular build cycle, one of the non GRAM element
 ** got removed from the active element list and therefore the next_elem_list_sa[]
 ** was therefore had one item less than the current active cur_elem_list_sa[]
 ** Since GFX_MGR02_DONOT_REBUILD_UNCHANGED_ELEMENT was enabled and there was no
 ** change in any of the GRAm elements, hmi_gfx_mgr02_pre_render_loop() did not
 ** updated the cur_build_layer resulting in  hmi_gfx_mgr02_dma_render_loop() not to
 ** get triggered. This resulted in non copy of next_elem_list_sa to cur_elem_list_sa
 ** This made the cur_elem_list_sa out of sync with what is there on display and
 ** lost its link with the GRAM allocation since the idexex not won't match. This
 ** resulted in the hmi_gfx_mgr02_copy_front_to_back_buffer to pick the wrong 
 ** pointer and copy another elements memory thus showing a different content.
 ** Fix is done in hmi_gfx_mgr02_build_screen() to make a copy of the 
 ** next_elem_list_sa to cur_elem_list_sa if the hmi_gfx_mgr02_dma_render_loop() was
 ** not triggered.
 **
 ** CMS Rev 1.15     10-Jun-2013    EMANOJ1
 ** Issue with hmi_gfx_mgr02_set_vclip on tile is fixed. the layer HEIGHT was
 ** not getting updated for tile elements which caused a corrupt screen when the
 ** tile is subjected to a vclip due to placement of negative co-ordinates etc.
 **
 ** CMS Rev 1.14     06-Jun-2013    EMANOJ1
 ** - Updated hmi_gfx_mgr02_build_widget to perform the buffer clearing after loading
 ** the WIDTH/HEIGHT information to virtual layer.
 ** - hmi_gfx_mgr02_get_text_dim_data renamed as hmi_gfx_mgr02_get_temporary_text_width_data.
 ** Done to perform the text width calculations only at one place during
 ** the hmi_gfx_mgr02_manage_layers_cp_child() and the calculated width is temporarily
 ** stored in CTRLDESCL3. Because the width stored in CTRLDESCL1.B.WIDTH feild is 
 ** manipulated by hmi_gfx_mgr02_layout_validate_layer_area() and may not give
 ** the right data. So this temporary storing will enable us to use it during the 
 ** memory allocation and during hmi_gfx_mgr02_build_text phase with out the need
 ** to perform the recalculation.
 ** - Vector font checking added and text building skipped if selected font is a 
 ** vector font.
 ** - hmi_gfx_mgr02_build_widget routine updated to load the default XY value of the
 ** widget in to the l_gfx_mgr02_data_S.elem_area_sa[] since the print widget
 ** routines use this information as the origin of the base widget to find out
 ** offset location. Earlier code was writing the current XY location and caused
 ** an issue with P42 where the widget's position was animated and the child element
 ** used the animated XY to calculate the offset value. This resulted in the child
 ** elements offset also getting changed and finally resulting in a clipping.
 ** So by writing the default value to this will make the child elelemnts offset
 ** same regardless of the position animation to a widget. The position animation
 ** is taken care by DCU and therefore need not be passed to its childrens.
 ** - Compilation issue fix and logic fix for case when there are no clipped widgets
 ** present in generated code.
 **
 ** CMS Rev 1.13     05-Jun-2013    EMANOJ1
 ** Faraday supports tile property only on top 8 and bottom 8 layers only.
 ** So in order to utilize it better the layer allocation will be done from top to
 ** bottom and bottom to top. Total active layers will be divided in to two and
 ** top priority sections will get assigned from DCU index 0 onwards AND bottom priority
 ** sections will get allocated from MAX DCU layer onwards. This way any tile used
 ** top 8 or bottom 8 priority will utilize the tiling feature of Faraday.
 ** Memory alignment made to 8byte boundary for Faraday and Rainbow varients as the
 ** memory for these has to be aligned to 64bits boundary.
 ** Clearing of memory made prior to vclip, as vclip will modify the height of the
 ** layer and therefore the entire RAM was not getting cleared.
 **
 ** CMS Rev 1.12     30-May-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_print_widget_elements to fix issue with vertical clipping
 ** of images where an overflow in subtraction caused buffer corruption and
 ** invalid height calculation resulted in bottom portion of the image also getting
 ** clipped.
 **
 ** CMS Rev 1.11     28-May-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_print_widget_elements to add the offset XY location to
 ** clip area to make the clip area also move along with the movement of the parent
 **
 ** CMS Rev 1.10     27-May-2013    EMANOJ1
 ** Horizontal clip implementation modified the element posx and width information
 ** but this was causing the buffer information for OpenVG and software. Most
 ** Openvg target implementations has restrictions on bufferwidth. So
 ** implementation updated not to modify the width information for openvg/software
 ** when doing the clipping calculations.
 ** VClip issue fix - Vertical clip was not updating the positionY incase of 
 ** where the original Y was < clip Y location.
 **
 ** CMS Rev 1.9      23-May-2013    EMANOJ1
 ** Clipping for image elements inside widget fixed. Added support for 
 ** horizontal clipping of images inside a widget.
 ** TODO : Vertical/horizontal clipping of text inside widgets needs to be
 ** verified/fixed.
 **
 ** CMS Rev 1.8      15-May-2013    EMANOJ1
 ** - Memory corruption issue fixed in hmi_gfx_mgr02_vblank_isr(). fl_dcu_index was
 ** unsigned variable and if all the available layers are used 16 out of 16 for 
 ** rainbow case) then after the layer copy finishes fl_dcu_index will be -1. 
 ** Since it is declared as UINT32 it means a large positive value. So the unused 
 ** layer disable loop will run to clear the layers for this large positive value 
 ** times and resulting in memory corruption. So type of fl_dcu_index changed to 
 ** SINT32 and also layer disable loop comparison adjusted to >= 0 from > 0 
 ** - hmi_gfx_mgr02_layout_validate_layer_area function moved to layout.c as it 
 ** is needed by generic manager as well for dirty area calculations
 ** - hmi_gfx_mgr02_layout_is_element_changed renamed as hmi_gfx_mgr02_layout_dcu_is_element_changed
 **
 ** CMS Rev 1.7      09-May-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_vblank_isr to allocate the layers from Low priority to 
 ** high priority. 
 ** Reason - Faraday devices support tiling only on low priority 16 layers
 ** so if the allocation happens from a high to low there is every chance that 
 ** a background layer utilizing tiling feature will get allocated a layer > 16
 ** and therefore the tile effect don't work. By this change we can be sure that
 ** the loweste priority gdt layers are always on dcu lowest layers and if they
 ** use a tiling feature it works.
 **
 ** CMS Rev 1.6      12-Apr-2013    EMANOJ1
 ** Merged the faraday support changes. Compiler issue fix
 **
 ** CMS Rev 1.5      12-Apr-2013    EMANOJ1
 ** Fixed compilation issue when there were no dynamic images in design and
 ** a widget was used and a case where there were no image anim elements. 
 **
 ** CMS Rev 1.4      08-Apr-2013    EMANOJ1
 ** Updated hmi_gfx_mgr02_load_alpha_blend_properties to fix the blending
 ** parameter settings to match what was done in gfx02 V1.X
 **
 ** CMS Rev 1.3      26-Mar-2013    EMANOJ1
 ** Compiler issues related to hmi_gfx_mgr02_set_vclip() and OVG & SWR resolved
 **
 ** CMS Rev 1.2      15-Mar-2013    ASHEKHAR
 ** Updated compiler switches to make it work for different combinations
 ** Static string length is calculated using strlen function instead of taking
 ** from the configuration.
 **
 ** CMS Rev 1.1      10-Nov-2012    ASHEKHAR
 ** Restructured and Updated to support Integrated GDT tool.
 **
 ** CMS Rev 1.0      05-Sep-2012    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
#endif /* GFX_MGR02_KEPLER */

/* end of file =============================================================*/

