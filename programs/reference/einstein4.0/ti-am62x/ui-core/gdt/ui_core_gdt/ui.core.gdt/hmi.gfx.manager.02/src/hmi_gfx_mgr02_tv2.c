/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_tv2.c
 **
 ** Description:    
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define GUI_GFX_MANAGER_TV2_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"


#if defined(GFX_MGR02_TRAVEO2)
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_tv2.h"
#include "hmi_gfx_mgr02_tv2_iris.h"
#include "hmi_gfx_mgr02_amber_iris.h"
#include "hmi_gfx_mgr02_tv2_clut.h"

#include "ut_compatibility.h"
#include "ut_disp.h"
#include "cy_fpdlink.h"

#ifdef GFX02_DEBUG_INFO
#include "cygfx_erp_types.h"
#endif

#include "hmi_gfx_mgr02_clut_table.h"
#include "panel_definition.h"
#if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED)
#include "hmi_gfx_mgr02_warp_tables.cfg"
#endif /* #if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_LAYER_WARPING_ENABLED) */ 

#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
#include "cap_util.h"
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
#define GFX_MGR02_NUM_AMBER_LAYERS          (26) /*((3*8)+1+1)*/
#define GFX_MGR02_NUM_OF_SUB_LAYER          ((UINT32)0x08)
#define GFX_MGR02_NUM_OF_DECODE_LAYERS      ((UINT32)0x02)
#ifdef GFX_MGR02_LAYER_WARPING_ENABLED
#define GFX_MGR02_NUM_OF_FRACTIONAL_PLANES  0x02U
#else
#define GFX_MGR02_NUM_OF_FRACTIONAL_PLANES  0x03U
#endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
#define GFX_MGR02_INVALID_LAYER             (CYGFX_DISP_LAYER_4 + 1UL)


#define GFX_MGR02_IS_MULTI_LAYER(feature) (((feature) & CYGFX_DISP_FEATURE_MULTI_LAYER) != 0)

#define GFX_MGR02_ELEMENT_VISIBLE      ((UINT32)2)
#define GFX_MGR02_ELEMENT_INVISIBLE    ((UINT32)1)
#define GFX_MGR02_ELEMENT_INVALID      ((UINT32)0)


/*
Macros for commiting only the the windows which needs updated.
*/
#define GFX_MGR02_AMBER_WIN_DIRTY    ((UINT8)0x00)      /*If the window attributes changed*/
#define GFX_MGR02_AMBER_WIN_UPDATED  ((UINT8)0x01)      /*If the window atrributes are updated and not committed to display.*/
#define GFX_MGR02_AMBER_WIN_COMMITED ((UINT8)0x02)      /*After commiting the window for display.*/

#define INSTR_BUF_SIZE_MIN ((CYGFX_U32)1024)
#define INSTR_BUF_SIZE_MAX ((CYGFX_U32)((CYGFX_U32)0x40000-(CYGFX_U32)4))
#define INSTR_BUF_SIZE_ALIGN ((CYGFX_U32)4)

#define NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ((CYGFX_S32)2)
#define NUM_OF_OTF_WINDOWS       ((CYGFX_U08)4)

/* Defines the data required for managing a single window */
typedef struct
{
    /*
    ** MML handles for the window & its surface
    */
    CYGFX_WINDOW                   win;
    CYGFX_DISP_WINDOW_PROPERTIES_S win_prop;
    CYGFX_SURFACE                  surf;
#ifdef LBO_OTF_FEATURE_CC
    CYGFX_SYNC                     be_sync; 
    CYGFX_SYNC                     win_sync;
#endif    
    /*
    **  root_elem_sp - holds the parent element pointer. Used for Fractional planes identification
    **                 fractional planes share the same parent
    **  next_elem_sp - element to be rendered next in to the window
    **  curr_elem_sp - currently displayed element in window
    **  clip         - clip area of the window
    */
    GFX_MGR02_ELEM_LIST_T  const * root_elem_sp;
    GFX_MGR02_ELEM_LIST_T  const * next_elem_sp;
    GFX_MGR02_ELEM_LIST_T  const * curr_elem_sp;
    GFX_MGR02_VISIBLE_AREA         clip;
    void                         * render_buffer;
    UINT32 win_colour;
    SINT32 posx;
    SINT32 posy;
    UINT8  alpha;
#ifdef LBO_OTF_FEATURE_CC    
    UINT8 besync_valid;
#endif    
    GFX_UINT  see_through:1;
    GFX_UINT  win_sts:2;
    GFX_UINT  valid:1;

}GFX_MGR02_WINDOW_DATA_T;

/* Defines the data required for managing a single window */
typedef struct
{
    UINT32 fp_layer_id;
    UINT32 fp_no_of_sub_layer_used;
}GFX_MGR02_FRACTIONAL_PLANE_DATA_T;
typedef struct 
{
  CYGFX_DISP                  display;                                     /*Display Handle*/
  UINT32                      bg_colour;                                   /*Display BG Colour*/
  CYGFX_U32                   input_control;                                /*Display input control*/
  GFX_MGR02_WINDOW_DATA_T     window_data[GFX_MGR02_NUM_AMBER_LAYERS];     /*Windows associated with Display*/
#ifndef LBO_OTF_FEATURE_CC
  #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
  CYGFX_SYNC                  gpu_sync;					   /*Sync for knowing the GPU finished rendering or Not*/
  #endif
#endif
  CYGFX_SYNC                  disp_sync;                                   /*Sync for knowing the Display finished Commiting or Not*/
  UINT8                       num_of_visible_elements;                     /*Number of active elements in the Display. */
  UINT8                       num_of_planes_used;                          /*Number of planes used. This is needed to restrict planes per Disp controller.*/
#ifndef LBO_OTF_FEATURE_CC
  #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
  UINT8                       gpusync_flag;				   /*It will hold Boolean value to check whether the GPU sync is inserted or not for frame.*/
  #endif
#endif  
}GFX_MGR02_DISPLAY_DATA_T;
/*Recommended Window creation Order*/
#if GFX_MGR02_NUM_LAYERS>1 
static const UINT32 lc_amber_window_creation_order[GFX_MGR02_NUM_OF_PLANES] =
{
    CYGFX_DISP_FEATURE_DECODE | CYGFX_DISP_FEATURE_INDEX_COLOR,
    CYGFX_DISP_FEATURE_DECODE |CYGFX_DISP_FEATURE_CAPTURE,
    CYGFX_DISP_FEATURE_MULTI_LAYER|CYGFX_DISP_FEATURE_WARP,
    CYGFX_DISP_FEATURE_MULTI_LAYER |CYGFX_DISP_FEATURE_INDEX_COLOR,
    CYGFX_DISP_FEATURE_MULTI_LAYER |CYGFX_DISP_FEATURE_INDEX_COLOR
};
#endif
#ifdef LBO_OTF_FEATURE_CC
typedef struct 
{
    CYGFX_SYNC  vsync;
    CYGFX_U08   allow_win;
}GFX_MGR02_OTF_WIN_S;
static GFX_MGR02_OTF_WIN_S  l_otf[NUM_OF_OTF_WINDOWS];
#endif
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
static CYGFX_U32 l_prev_disp_attribute[GFX_MGR02_NUM_LAYERS]={0};
#endif
/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_create_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index_u32);
static CYGFX_ERROR hmi_gfx_mgr02_destroy_invalid_windows(UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_allocate_windows(UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index_u32);
static void hmi_gfx_mgr02_manage_layers_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,\
                                                 UINT32 p_layer_index_u32,
                                                 UINT32 p_multi_layer_u32);
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area,\
                                                           UINT8 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP);
#if (GFX_MGR02_NUM_OF_SWDGS > 0)
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                  GFX_MGR02_ELEMENT_AREA * p_elem_area);
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
static void hmi_gfx_mgr02_build_widget(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
#endif
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
static void hmi_gfx_mgr02_build_image(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
#endif
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
static void hmi_gfx_mgr02_build_video(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
static void hmi_gfx_mgr02_get_video_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA       * p_elem_area);
#endif

#if GFX_MGR02_NUM_OF_FILLS > 0
static void hmi_gfx_mgr02_build_fill(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
#endif
#if (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TILES > 0)
static void hmi_gfx_mgr02_get_tile_fill_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,\
                                                   GFX_MGR02_ELEMENT_AREA * p_elem_area);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA * p_elem_area);
#endif
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
static UINT32 hmi_gfx_mgr02_is_fractional_element_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT32 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP,
                                                           UINT8  p_check_btwn_layers);
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T * hmi_gfx_mgr02_get_available_fraction_plane_layer(void);
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T *  hmi_gfx_mgr02_get_unused_fractional_plane(void);
#endif
static UINT8 hmi_gfx_mgr02_is_sublayer_available(UINT32 fl_layer_id_U32);
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
static UINT8 hmi_gfx_mgr02_is_image_transparent(UINT8 fl_format_U8);
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
static void hmi_gfx_mgr02_set_blendmode(GFX_MGR02_WINDOW_DATA_T const * p_wind, GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP, CYGFX_U32 p_blend_mode);
#endif
static GFX_MGR02_DRIVER_BUSY_STATUS_T hmi_gfx_mgr02_amber_driver_status(UINT32 p_layer_id_u32);
#ifdef LBO_OTF_FEATURE_CC
static void hmi_gfx_mgr02_prepare_otfwindow(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_CONTEXT_GB_T * p_build,GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP,UINT32 p_layer_index);
#endif
#if GFX_MGR02_NUM_OF_CLUTS > 0U
static void hmi_gfx_mgr02_tv2_free_unused_cluts(void);
#endif
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
static  void*                   l_memtask0_ib = NULL;
static  void*                   l_memtask1_ib = NULL;
static  void*                   l_memtask2_ib = NULL;
#ifdef LBO_OTF_FEATURE_CC
static  void*                   l_wintask0_ib = NULL;
static  void*                   l_wintask1_ib = NULL;
static  void*                   l_wintask2_ib = NULL;
static  void*                   l_wintask3_ib = NULL;
#endif
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0) || ((GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2) || ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))))
static  void*                   l_alpha_buffer =NULL;
#endif

static  volatile UINT8          l_gfx_mgr_shutdown_status;
static  GFX_MGR02_ANIM_DATA_T * l_layer_anim_data_SP;

static  UINT8                   l_cur_num_of_elements[GFX_MGR02_NUM_LAYERS];
static  CYGFX_DISP_LAYER      l_cur_free_layer;
#ifdef GFX02_DEBUG_INFO
static  UINT32                  l_tot_num_of_elements;
static  UINT32                  l_debug_vram_usage;
#endif
static  GFX_MGR02_FRACTIONAL_PLANE_DATA_T l_fractional_plane_data[GFX_MGR02_NUM_OF_FRACTIONAL_PLANES];
#ifdef GFX_MGR02_LAYER_WARPING_ENABLED
static  GFX_MGR02_FRACTIONAL_PLANE_DATA_T l_warp_plane_data; /* there is only one warp plane */
#endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
static  GFX_MGR02_IMAGE_DEF_T l_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif

static  UINT8 l_cur_fractional_plane = (UINT8)0;
static  UINT8 l_prev_fractional_plane = (UINT8)0;

static  GFX_MGR02_DISPLAY_DATA_T l_disp_comp[GFX_MGR02_NUM_LAYERS];
static  GFX_MGR02_DRIVER_BUSY_STATUS_T l_gfx_mgr02_amber_driver_status = GFX_MGR02_DRIVER_FREE;
static  UINT8 l_gfx_mgr02_amber_element_dirty_u8 =(UINT8)0;
static  UINT8 l_gfx_mgr02_amber_dwdg_dirty_u8 =0;
static  GFX_MGR02_ELEM_LIST_T const *l_root_elem_list_SP=NULL;
static  UINT32 l_content_ready_ondisplay =(UINT32)0;
#ifdef LBO_OTF_FEATURE_CC
static  CYGFX_WINDOW last_otf_window;
#endif
#if GFX_MGR02_NUM_OF_CLUTS > 0U
static UINT16 l_curframe_clut_idx_u16a[GFX_MGR02_NUM_AMBER_LAYERS];
static UINT16 l_last_frame_clut_idx_u16a[GFX_MGR02_NUM_AMBER_LAYERS];
#endif
/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef GFX02_DEBUG_INFO
void stdout_printf(const char *string)
{
   if(0 < strlen(string) )
   {
      printf(string);
   }
}
#endif

void hmi_gfx_mgr02_initialize(void)
{
    CYGFX_SYSINIT_INFO_S fl_sys_init = GFX_MGR02_CUSTOM_GDC_SYSINIT_INITIALIZER;
    GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP;
    CYGFX_CAP_CTX fl_cap_ctx = NULL;
    CYGFX_U32  fl_pll;
    CYGFX_S32  ret;
    IrisMemInfo fl_memory_s;
    UINT8   fl_disp_index_u8;
    UINT8   fl_index_u8;
    UINT8   fl_no_planes_u8=(UINT8)GFX_MGR02_NUM_OF_PLANES;
    CYGFX_U08   clockDivider[GFX_MGR02_NUM_LAYERS]={0};
    #ifdef LBO_OTF_FEATURE_CC
    CYGFX_U08  win_no;
    #endif
    l_gfx_mgr02_amber_driver_status = GFX_MGR02_DRIVER_FREE;
    l_content_ready_ondisplay =(UINT32)0;
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_NORMAL;
    l_layer_anim_data_SP      = hmi_gfx_mgr02_layout_get_anim_data();
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
    (void)memcpy((void *)&l_runtime_wdg_image_layer_def_S[0], 
          (const void *)&lc_runtime_wdg_image_layer_def_S[0], 
          sizeof(l_runtime_wdg_image_layer_def_S));
#endif

    IRIS_API_CHECK(ret, CyGfx_SysInitializeDriver(&fl_sys_init));
    (void)hmi_gfx_mgr02_amber_mem_mgmt_init();
#ifdef GFX02_DEBUG_INFO
    CyGfx_ErpSetPrintf(stdout_printf);
#endif
    fl_memory_s.MemCateg = IRIS_PE_IB_MEMTASK0;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU; /*Not applicable for Instruction Buffer*/
    fl_memory_s.Alignment = (CYGFX_U32)8; /*64 Bit aligned*/
    fl_memory_s.ExtMemory = (UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_MEMTASK0_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {    
        l_memtask0_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_MEM_PRIO_0, l_memtask0_ib, fl_memory_s.Size));
    }
    fl_memory_s.MemCateg = IRIS_PE_IB_MEMTASK1;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_MEMTASK1_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_memtask1_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_MEM_PRIO_1, l_memtask1_ib, fl_memory_s.Size));
    }
    fl_memory_s.MemCateg = IRIS_PE_IB_MEMTASK2;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_MEMTASK2_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_memtask2_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_MEM_PRIO_2, l_memtask2_ib, fl_memory_s.Size));
    }
#ifdef LBO_OTF_FEATURE_CC    
    fl_memory_s.MemCateg = IRIS_PE_IB_WINTASK0;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_WINTASK0_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_wintask0_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_WIN_PRIO_0, l_wintask0_ib, fl_memory_s.Size));
    }
    fl_memory_s.MemCateg = IRIS_PE_IB_WINTASK1;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_WINTASK1_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_wintask1_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_WIN_PRIO_1, l_wintask1_ib, fl_memory_s.Size));
    }
    fl_memory_s.MemCateg = IRIS_PE_IB_WINTASK2;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_WINTASK2_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_wintask2_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_WIN_PRIO_2, l_wintask2_ib, fl_memory_s.Size));
    }
    fl_memory_s.MemCateg = IRIS_PE_IB_WINTASK3;
    fl_memory_s.Size = (CYGFX_U32)(((CYGFX_U32)GFX_MGR02_IRIS_WINTASK3_IBUFF_SIZE/INSTR_BUF_SIZE_ALIGN)*INSTR_BUF_SIZE_ALIGN);
    if((fl_memory_s.Size >= INSTR_BUF_SIZE_MIN) && (fl_memory_s.Size <= INSTR_BUF_SIZE_MAX))
    {
        l_wintask3_ib = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
        IRIS_API_CHECK(ret, CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK_WIN_PRIO_3, l_wintask3_ib, fl_memory_s.Size));
    }
#endif
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0) || ((GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2) || ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))))

    fl_memory_s.MemCateg = IRIS_DE_ALPHA_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU; /*Not applicable for Instruction Buffer*/
    fl_memory_s.Alignment = (CYGFX_U32)4; /*4 Byte alignement*/
    fl_memory_s.Size = (CYGFX_U32)GFX_MGR02_DE_ALPHABUF_SIZE;
    fl_memory_s.ExtMemory =(UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    l_alpha_buffer =  hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
    if(l_alpha_buffer!=NULL)
    {     
       IRIS_API_CHECK(ret, CyGfx_DeSetAlphaBuffer((CYGFX_U32)GFX_MGR02_DE_AREA_WIDTH,(CYGFX_U32)GFX_MGR02_DE_AREA_HEIGHT,(CYGFX_U32)8, l_alpha_buffer, (CYGFX_U32)GFX_MGR02_DE_ALPHABUF_SIZE));
    }
#endif
#if GFX_MGR02_NUM_LAYERS>1 
    for (fl_disp_index_u8 = (UINT8)0; fl_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_disp_index_u8++)
#else  
    fl_disp_index_u8 = (UINT8)0;
#endif
    {
        l_disp_comp[fl_disp_index_u8].num_of_visible_elements = (UINT8)0;
        l_disp_comp[fl_disp_index_u8].bg_colour = lc_amber_disp_bg_colour_u32a[fl_disp_index_u8];
        l_disp_comp[fl_disp_index_u8].input_control = CYGFX_DISP_INPUT_CONTROL_PRIMARY;
#ifndef LBO_OTF_FEATURE_CC
        #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
        l_disp_comp[fl_disp_index_u8].gpusync_flag =(UINT8)0;
        IRIS_API_CHECK(ret, utSyncCreate((CYGFX_U32)1, &l_disp_comp[fl_disp_index_u8].gpu_sync));
        #endif
#endif
        IRIS_API_CHECK(ret, utSyncCreate((CYGFX_U32)1, &l_disp_comp[fl_disp_index_u8].disp_sync));
        #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
        {
            GFX_MGR02_CAPTURE_INIT_STATUS fl_status; 
            fl_status = hmi_gfx_mgr02_capture_to_display_init();
            if(fl_status == GFX_MGR02_CAPTURE_INIT_SUCCESS)
            {
                fl_cap_ctx = *(hmi_gfx_mgr02_get_capture_context());
            }
        }
        IRIS_API_CHECK(ret, CyGfx_ConfigSetAttribute(CYGFX_CONFIG_ATTR_DISPLAY_NOBLOCK,1U));
        IRIS_API_CHECK(ret, CyGfx_ConfigSetAttribute(CYGFX_CONFIG_ATTR_CAPTURE_NOBLOCK,1U));
        IRIS_API_CHECK(ret, CyGfx_DispSetAttribute(l_disp_comp[fl_disp_index_u8].display, CYGFX_DISP_ATTR_IN_CTRL, l_disp_comp[fl_disp_index_u8].input_control));
        #endif
        IRIS_API_CHECK(ret, utDispGetPll(l_mml_gdc_dispParams[fl_disp_index_u8].timing.pixelClock, l_mml_gdc_dispParams[fl_disp_index_u8].displayMode, &clockDivider[fl_disp_index_u8], &fl_pll));
        IRIS_API_CHECK(ret, CyGfx_DispOpenDisplay((CYGFX_DISP_PROPERTIES_S*)&l_mml_gdc_dispParams[fl_disp_index_u8],&l_disp_comp[fl_disp_index_u8].display,fl_cap_ctx));
        
        if(CYGFX_DISP_CONTROLLER_0 == l_mml_gdc_dispParams[fl_disp_index_u8].outputController)
        {
            if(CYGFX_DISP_MODE_SINGLE_SCREEN == l_mml_gdc_dispParams[fl_disp_index_u8].displayMode)
            {
                IRIS_API_CHECK(ret, utDispEnableFpdLink(clockDivider[fl_disp_index_u8], l_mml_gdc_dispParams[fl_disp_index_u8].displayMode, Fpdlink0));				
            }
            #ifdef VIDEOSS0_FPDLINK1            
            else if(CYGFX_DISP_MODE_DUAL_CHANNEL == l_mml_gdc_dispParams[fl_disp_index_u8].displayMode)
            {
                /* The both FpdLink outputs are operating synchronously, driven by display controller 0*/
                IRIS_API_CHECK(ret, utDispEnableFpdLink(clockDivider[fl_disp_index_u8], l_mml_gdc_dispParams[fl_disp_index_u8].displayMode, FpdlinkDual01));
            }
            else
            {
                /*Not clear for CYGFX_DISP_MODE_DUAL_SCREEN ond CYGFX_DISP_MODE_DUAL_VIEW modes for now.*/
            }
            #endif            
        }
        #ifdef VIDEOSS0_FPDLINK1        
        else
        {
                if(CYGFX_DISP_MODE_DUAL_CHANNEL != l_mml_gdc_dispParams[fl_disp_index_u8].displayMode)
                {
                    IRIS_API_CHECK(ret, utDispEnableFpdLink(clockDivider[fl_disp_index_u8], l_mml_gdc_dispParams[fl_disp_index_u8].displayMode, Fpdlink1));
                }
        }
        #endif        
        
        if(ret !=    CYGFX_OK)
        {
            #ifdef GFX02_DEBUG_INFO
            printf("Display Open Failed Err Code: %x.\n",ret);
            #endif
        }

#ifdef GFX_MGR02_ENABLE_HW_DITHERING
        #if GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB666
        IRIS_API_CHECK(ret, CyGfx_DispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  CYGFX_DISP_DITHER_ON,
                                                  CYGFX_DISP_DITHER_MODE_TEMP,
                                                  CYGFX_DISP_DITHER_RANGE_S11LOW,
                                                  CYGFX_DISP_DITHER_FORMAT_106));
        #elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB565
        IRIS_API_CHECK(ret, CyGfx_DispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  CYGFX_DISP_DITHER_ON,
                                                  CYGFX_DISP_DITHER_MODE_TEMP,
                                                  CYGFX_DISP_DITHER_RANGE_S11LOW,
                                                  CYGFX_DISP_DITHER_FORMAT_105));
        #elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB888
        IRIS_API_CHECK(ret, CyGfx_DispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  CYGFX_DISP_DITHER_ON,
                                                  CYGFX_DISP_DITHER_MODE_TEMP,
                                                  CYGFX_DISP_DITHER_RANGE_S11LOW,
                                                  CYGFX_DISP_DITHER_FORMAT_108));
        #endif
#endif
        IRIS_API_CHECK(ret, CyGfx_DispSetAttribute(l_disp_comp[fl_disp_index_u8].display,CYGFX_DISP_ATTR_BACKGROUND_COLOR,l_disp_comp[fl_disp_index_u8].bg_colour));
#ifndef LBO_OTF_FEATURE_CC
/*For OTF feature to work the attribute CYGFX_DISP_ATTR_INCLUDE_WIN_COMMIT must be FALSE.*/     
     IRIS_API_CHECK(ret, CyGfx_DispSetAttribute(l_disp_comp[fl_disp_index_u8].display,CYGFX_DISP_ATTR_INCLUDE_WIN_COMMIT,(MM_U32)MM_TRUE));
#endif
#ifdef GFX_MGR02_IRIS_GAMMA_CORRECTION
        if((GFX_MGR02_IRIS_GAMMA_RED_CLUT != NULL) && (GFX_MGR02_IRIS_GAMMA_GREEN_CLUT != NULL) && (GFX_MGR02_IRIS_GAMMA_BLUE_CLUT != NULL))
        {
            IRIS_API_CHECK(ret, CyGfx_CmSetClutData((l_disp_comp[fl_disp_index_u8].display,
                                                    CYGFX_CM_CLUT_UNIT_0,
                                                    CYGFX_CM_CLUT_FORMAT_33,
                                                    GFX_MGR02_IRIS_GAMMA_RED_CLUT,
                                                    GFX_MGR02_IRIS_GAMMA_GREEN_CLUT,
                                                    GFX_MGR02_IRIS_GAMMA_BLUE_CLUT));
                                                   
        }  
#endif
        IRIS_API_CHECK(ret, CyGfx_DispCommit(l_disp_comp[fl_disp_index_u8].display));
        l_content_ready_ondisplay =(UINT32)1;
        fl_index_u8=(UINT8)0;
        fl_win_data_SP = &l_disp_comp[fl_disp_index_u8].window_data[0];
        while(fl_index_u8<(UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP->next_elem_sp = NULL;
            fl_win_data_SP->curr_elem_sp = NULL;
            fl_win_data_SP->root_elem_sp = NULL;
            IRIS_API_CHECK(ret, utSmGenSurfaceObjects((CYGFX_U32)1, &fl_win_data_SP->surf));
            #ifdef LBO_OTF_FEATURE_CC
            IRIS_API_CHECK(ret, utSyncCreate((CYGFX_U32)1, &fl_win_data_SP->be_sync));
            IRIS_API_CHECK(ret, utSyncCreate((CYGFX_U32)1, &fl_win_data_SP->win_sync));
            #endif
            fl_win_data_SP->win_prop.sub_layerId  = CYGFX_DISP_SUB_LAYER_DEFAULT;
            fl_win_data_SP->win_prop.outputScreen = CYGFX_DISP_OUTPUT_SCREEN_PRIMARY;
            fl_win_data_SP->win = NULL;
            fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
            fl_win_data_SP->win_colour = 0UL;
            #ifdef LBO_OTF_FEATURE_CC
            fl_win_data_SP->besync_valid = 0U;
            #endif
            fl_index_u8++;
            /* Incrementing till the last iteration*/
            if (fl_index_u8 < (UINT8)(GFX_MGR02_NUM_AMBER_LAYERS))
            {
                fl_win_data_SP++;
            }   
        }
        /* 
        Create windows to ensure allocation of windows with requested features for respective Displays.
        */
        fl_win_data_SP = &l_disp_comp[fl_disp_index_u8].window_data[0];
        for(fl_index_u8=(UINT8)0;fl_index_u8< lc_amber_num_planes_u8a[fl_disp_index_u8];fl_index_u8++)
        {
            fl_win_data_SP->win_prop.features = lc_amber_plane_features_u32a[fl_disp_index_u8][fl_index_u8];
            fl_win_data_SP->win_prop.layerId  = ((CYGFX_DISP_LAYER)(fl_no_planes_u8-0x01U));
            fl_win_data_SP->win_prop.topLeftX = (CYGFX_U32)0;        
            fl_win_data_SP->win_prop.topLeftY = (CYGFX_U32)0;
            fl_win_data_SP->win_prop.width    = l_mml_gdc_dispParams[fl_disp_index_u8].timing.Hact;
            fl_win_data_SP->win_prop.height   = l_mml_gdc_dispParams[fl_disp_index_u8].timing.Vact;
            fl_no_planes_u8--;
            fl_win_data_SP++;
        }
    }
    /*Blocking the Layer for 2nd Display alone is enough in Initialization.*/
    #if GFX_MGR02_NUM_LAYERS>1 
    fl_win_data_SP = &l_disp_comp[1].window_data[0];
    for(fl_index_u8=0;fl_index_u8< lc_amber_num_planes_u8a[1];fl_index_u8++)
    {
        UINT8 fl_counter_u8;
        for(fl_counter_u8=(UINT8)0;fl_counter_u8< (UINT8)GFX_MGR02_NUM_OF_PLANES;fl_counter_u8++)
        {
            if((lc_amber_window_creation_order[fl_counter_u8] == fl_win_data_SP->win_prop.features)&&
               (fl_win_data_SP->win == 0))
            {
                IRIS_API_CHECK(ret, CyGfx_DispWinCreate(l_disp_comp[1].display,
                                                    &fl_win_data_SP->win_prop,
                                                    &fl_win_data_SP->win));
              
                if(ret != CYGFX_OK)
                {
                    #ifdef GFX02_DEBUG_INFO
                    printf("Window Creation Failed %x\n",ret);
                    #endif
                }
                #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
                IRIS_API_CHECK(ret, CyGfx_WinSetAttribute(fl_win_data_SP->win, CYGFX_WIN_ATTR_COLOR, 255));
                IRIS_API_CHECK(ret, CyGfx_WinSetBlendMode(fl_win_data_SP->win, CYGFX_WIN_BLEND_GLOBAL_ALPHA));
                #endif
            }

        }
        fl_win_data_SP++;
    }
    #endif
#ifdef LBO_OTF_FEATURE_CC
    for (win_no= (CYGFX_U08)0; win_no<NUM_OF_OTF_WINDOWS;win_no++)
    {
        IRIS_API_CHECK(ret, utSyncCreate((CYGFX_U32)1, &l_otf[win_no].vsync));
        l_otf[win_no].allow_win = ((CYGFX_U08)1);
    }
#endif    
    #if GFX_MGR02_NUM_OF_CLUTS > 0U 
    {
        UINT8 fl_clut_idx_u8;   
        hmi_gfx_mgr02_tv2_pallette_init();  
        for(fl_clut_idx_u8 =0; fl_clut_idx_u8< (UINT8)GFX_MGR02_NUM_AMBER_LAYERS ; fl_clut_idx_u8++)
        {
            l_curframe_clut_idx_u16a[fl_clut_idx_u8] = GFX_MGR02_NUM_OF_CLUTS;
            l_last_frame_clut_idx_u16a[fl_clut_idx_u8] = GFX_MGR02_NUM_OF_CLUTS;
        }
    }
    #endif
}

void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U32)
{
   UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
   
#ifdef GFX02_DEBUG_INFO
    CYGFX_U32 fl_size1 = 0;
    CYGFX_U32 fl_size2 = 0;

   l_debug_vram_usage = FALSE;
#endif
   UINT8 i;
    #ifdef LBO_OTF_FEATURE_CC
    CYGFX_U08 fl_otfwin_no;
    #endif
    #if GFX_MGR02_NUM_OF_CLUTS > 0U 
    UINT8 fl_clut_idx_u8;   
    #endif
   if ((p_layer_ID_U32 < (UINT32)GFX_MGR02_NUM_LAYERS) && (fl_shutdown_state != GFX_MGR02_SHUTDOWN_EMERGENCY))
   {
     
      #if GFX_MGR02_NUM_LAYERS >1
      if (p_layer_ID_U32 == (UINT32)0)
      #endif      
      {
          for(i= (UINT8)0; i< GFX_MGR02_NUM_OF_FRACTIONAL_PLANES; i++)
          {
             l_fractional_plane_data[i].fp_layer_id             =   GFX_MGR02_INVALID_LAYER;
             l_fractional_plane_data[i].fp_no_of_sub_layer_used =  (UINT32)0;
          }
          l_cur_fractional_plane =(UINT8)0;
          l_prev_fractional_plane =(UINT8)0;
          #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
          l_warp_plane_data.fp_layer_id = GFX_MGR02_INVALID_LAYER;
          l_warp_plane_data.fp_no_of_sub_layer_used = 0;
          #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
      }
#ifdef LBO_OTF_FEATURE_CC
       for(fl_otfwin_no = (CYGFX_U08)0;fl_otfwin_no < NUM_OF_OTF_WINDOWS; fl_otfwin_no++)
        {
            CYGFX_S32  ret;
            ret = CyGfx_SyncWaitSync(l_otf[fl_otfwin_no].vsync, (CYGFX_S32)0);
            if(CYGFX_OK == ret)
            {
                l_otf[fl_otfwin_no].allow_win = ((CYGFX_U08)1);
            }
        }
#endif        
    #if GFX_MGR02_NUM_OF_CLUTS > 0U 
    for(fl_clut_idx_u8 =0; fl_clut_idx_u8< (UINT8)GFX_MGR02_NUM_AMBER_LAYERS ; fl_clut_idx_u8++)
    {
        l_curframe_clut_idx_u16a[fl_clut_idx_u8] = GFX_MGR02_NUM_OF_CLUTS;
    }
    hmi_gfx_mgr02_tv2_free_blit_pallettes();
    #endif
      /*
      ** 1. Analyze all the layers in active screens from low priority to high priority
      ** 2. Find out list of layers that are visible, exclude layers which will be hidden.
      ** 3. Assign plane and its windows for the visible layers
      ** 4. Build the visible 26 layers and enable them
      ** 5. To do -> After the visible layers are built, perform building operation for invisible
      **    widget/text layers so that they will be ready to display once they become
      **    visible.
      */
      hmi_gfx_mgr02_manage_layers(p_layer_ID_U32); 	  
      if(GFX_MGR02_DRIVER_FREE == l_gfx_mgr02_amber_driver_status)
      {

         /*
         ** hmi_gfx_mgr02_manage_layers has to be outside this if loop since
         ** the iris merge widgets needs to be set active regardless
         ** of sync status. Otherwise the hmi_gfx_mgr02_context_widget_done
         ** will assume that the widgets are inactive and therefore
         ** delete its context & surfaces.
         */
         hmi_gfx_mgr02_render_display(p_layer_ID_U32);
      }
   }
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
    #if((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
    {
        UINT8 fl_status = hmi_gfx_mgr02_layout_get_frame_capture_done_status();
        if(fl_status == GFX_MGR02_SHUT_DOWN_VIDEO_UNIT)
        {
            hmi_gfx_mgr02_capture_video_shutdown();
        }
    }
    #endif
#endif
#if GFX_MGR02_NUM_OF_CLUTS > 0U 
    hmi_gfx_mgr02_tv2_free_unused_cluts();	
    for(fl_clut_idx_u8 =0; fl_clut_idx_u8 < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS ; fl_clut_idx_u8++)
    {
        l_last_frame_clut_idx_u16a[fl_clut_idx_u8] = l_curframe_clut_idx_u16a[fl_clut_idx_u8];
    }
#endif
#ifdef GFX02_DEBUG_INFO
   if(l_debug_vram_usage != FALSE)
   {
      utVideoGetSize(&fl_size1);
      if(fl_size1 >= (1024*1024))
      {
         printf("Total VRAM size    = %fMBytes\n", ((GFX_FLOAT)fl_size1/(1024.0*1024.0)));
      }
      else if(fl_size1 >= (1024))
      {
         printf("Total VRAM size    = %fKBytes\n", ((GFX_FLOAT)fl_size1/(1024.0)));
      }
      else
      {
         printf("Total VRAM size    = %dBytes\n", fl_size1);
      }
      utVideoGetFreeTotal(&fl_size2);
      fl_size1 -= fl_size2;
      if(fl_size2 >= (1024*1024))
      {
         printf("Total VRAM Usage   = %fMBytes\n", ((GFX_FLOAT)(fl_size1)/(1024.0*1024.0)));
      }
      else if(fl_size1 >= (1024))
      {
         printf("Total VRAM Usage   = %fKBytes\n", ((GFX_FLOAT)(fl_size1)/(1024.0)));
      }
      else
      {
         printf("Total VRAM Usage   = %dBytes\n", (fl_size1));
      }
      utVideoGetLargestBlock(&fl_size1);
      if(fl_size1 >= (1024*1024))
      {
         printf("Largest Free Block = %fMBytes\n", ((GFX_FLOAT)(fl_size1)/(1024.0*1024.0)));
      }
      else if(fl_size1 >= (1024))
      {
         printf("Largest Free Block = %fKBytes\n", ((GFX_FLOAT)fl_size1/(1024.0)));
      }
      else
      {
         printf("Largest Free Block = %dBytes\n", fl_size2);
      }
   }
#endif

}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers
 ** Visibility:       static
 ** Description:      This function copies all elements in currently active
 **                   screens to next_elem_sp
 **                   Each element in list is then validated to see if they
 **                   fully or partly visible.
 **                   Partly or fully visible elements index
 **                   Total number of visible layers are restricted to the
 **                   number of DCU layers.
 **                   Refer to 02_design\layer_allocation.doc
 ** Invocation:       Invoked by hmi_gfx_mgr02_build_screen() to determine the
 **                   visible elements to be built.
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index_u32)
{
   UINT32                  fl_max_priority;
   GFX_MGR02_SCREEN_ID_T const * fl_cur_screen;
   UINT32                  fl_cur_screen_id;

   if (p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
   {
      #ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
      #if((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
      {
        hmi_gfx_mgr02_capture_video_set_status(FALSE);
      }
      #endif
      #endif

       fl_max_priority = lc_layer_def_S[p_layer_index_u32].nb_priority;
       fl_cur_screen   = lc_layer_def_S[p_layer_index_u32].prio_stack;
       l_disp_comp[p_layer_index_u32].num_of_visible_elements=(UINT8)0;
       l_disp_comp[p_layer_index_u32].num_of_planes_used=(UINT8)0;
       l_gfx_mgr02_amber_element_dirty_u8 =(UINT8)0;
       #if GFX_MGR02_NUM_LAYERS >1
       if (p_layer_index_u32 > 0)
       {
         l_cur_free_layer  = (CYGFX_DISP_LAYER)(CYGFX_DISP_LAYER_4 - lc_amber_num_planes_u8a[0]);       
       }
       else
       #endif              
       {
         l_cur_free_layer   = CYGFX_DISP_LAYER_4;
       }
    #ifdef GFX02_DEBUG_INFO
       l_tot_num_of_elements = 0;
    #endif
       while(fl_max_priority > 0UL )
       {   
         fl_max_priority--;
         if(fl_max_priority<(lc_layer_def_S[p_layer_index_u32].nb_priority))
         {    
             fl_cur_screen_id = fl_cur_screen[fl_max_priority];
             if(fl_cur_screen_id < (UINT32)GFX_MGR02_NUM_OF_SCREENS)
             {
                hmi_gfx_mgr02_manage_layers_cp_childrens(fl_cur_screen_id, p_layer_index_u32);
             }
         }
       }
       hmi_gfx_mgr02_manage_widget_memory();
    #ifdef GFX02_DEBUG_INFO
       printf("INFO - Windows Needed    = %d\n", l_tot_num_of_elements);
       printf("INFO - Allocated windows = %d\n", l_disp_comp[p_layer_index_u32].num_of_visible_elements);
    #endif
   }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_childrens
 ** Visibility:       static
 ** Description:      This function copies the visible elements of passed screen
 **                   to render list  
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index_u32)
{
    GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP= NULL;
    GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP;
    UINT32                         fl_num_of_elem;
    GFX_MGR02_ANIM_DATA_T  const      * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    
    if(p_screen_id < (UINT32)GFX_MGR02_NUM_OF_SCREENS)
    {
        fl_screen_def_SP = &lc_screen_def_S[p_screen_id];
    }
    
    if((p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS) &&(fl_screen_def_SP != NULL))
    {
        (void)hmi_gfx_mgr02_context_begin_update(p_layer_index_u32, &lc_layer_def_S[p_layer_index_u32], (u_gx_flocal)FALSE);
        hmi_gfx_mgr02_context_reset_state();
        hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_anim_prop_SP->layer_alpha[p_layer_index_u32]);
        hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_anim_prop_SP->layer_loc[p_layer_index_u32]);

        #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS > 0
        if(fl_screen_def_SP->anim_index < (UINT8)(GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS))
        {
          hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_anim_prop_SP->group_alpha[fl_screen_def_SP->anim_index]);
          hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_anim_prop_SP->group_loc[fl_screen_def_SP->anim_index]);        
        }
        #endif /* #if GFX_MGR02_NUM_SCREEN_ANIM_ELEMENTS> 0 */

        fl_num_of_elem  = fl_screen_def_SP->num_child_elements;
        if(fl_num_of_elem > (UINT32)0)
        {
          fl_elem_list_SP = &fl_screen_def_SP->child[fl_num_of_elem-0x01U];
          while(fl_num_of_elem > (UINT32)0)
          {
             fl_num_of_elem--;
             if(l_disp_comp[p_layer_index_u32].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
             {
                  l_disp_comp[p_layer_index_u32].window_data[l_disp_comp[p_layer_index_u32].num_of_visible_elements].root_elem_sp = fl_elem_list_SP;
             }
             l_gfx_mgr02_amber_element_dirty_u8=(UINT8)0;
             l_gfx_mgr02_amber_dwdg_dirty_u8=(UINT8)0;
             l_root_elem_list_SP = NULL;
             hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP, p_layer_index_u32, (UINT32)FALSE);
             if(fl_num_of_elem != (UINT32)0)
             {
                fl_elem_list_SP = &fl_elem_list_SP[-1];
             }
          }
        }

    }
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_layers_cp_child
 ** Visibility:       static
 ** Description:      This function copy the passed child element after verifying
 **                   that it is visible 
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, 
                                                 UINT32                        p_layer_index_u32,
                                                 UINT32                        p_multi_layer_u32)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    GFX_MGR02_ELEM_LIST_T const *fl_elem_list_SP;
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    #endif
    #if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0)||(GFX_MGR02_NUM_OF_SWDGS > 0)
    UINT32 fl_base_id    = p_elem_list_SP->base_id;
    #endif
    #if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
    UINT32 fl_check_num_elements;
    UINT32                         fl_no_of_element_U32;
    UINT32                         fl_element_overlaps;
    GFX_MGR02_FRACTIONAL_PLANE_DATA_T  * fl_fp_data_S;
    #endif
    
    #if GFX_MGR02_NUM_OF_SWDGS > 0
    UINT32                         fl_num_of_elem;
    #endif
    GFX_MGR02_CONTEXT_STATE_T      fl_cur_context_S;
    GFX_MGR02_ELEMENT_AREA         fl_elem_area ={0,0,0,0,GFX_MGR02_OPEQUE,255};
    #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    GFX_MGR02_ANIM_DATA_T  const      * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    #endif
    GFX_MGR02_CONTEXT_T const         * fl_context_SP   = hmi_gfx_mgr02_context_get_ptr();
    CYGFX_U32                      fl_win_features = 0;
    BOOLEAN                         fl_element_valid = FALSE; 
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER) || defined(GFX_MGR02_LAYER_WARPING_ENABLED)   
    CYGFX_DISP_LAYER                         fl_prev_num_of_layers = CYGFX_DISP_LAYER_4;
#endif  
#ifdef GFX_MGR02_LAYER_WARPING_ENABLED
    GFX_MGR02_LAYER_DEF_T const* fl_layer_desc_SP;
#endif
    
    hmi_gfx_mgr02_context_state_get(&fl_cur_context_S);
    if(p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        switch(fl_obj_type)
        {
        #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0)
            case GFX_MGR02_TYPE_DWIDGET:
            case GFX_MGR02_TYPE_DIMAGE:
            {
            #if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
                if((GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))&& (fl_obj_id < (UINT32)GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS))
                {
                    hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_anim_prop_SP->group_loc[fl_obj_id]);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_anim_prop_SP->group_alpha[fl_obj_id]);
                }
            #endif
                if(l_gfx_mgr02_amber_element_dirty_u8 == (UINT8)0)
                {
                    l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
                }
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
                    if(l_gfx_mgr02_amber_element_dirty_u8==(UINT8)1)
                    {
                        l_gfx_mgr02_amber_dwdg_dirty_u8 = (UINT8)1;
                        l_root_elem_list_SP = p_elem_list_SP;
                    }
                    hmi_gfx_mgr02_manage_layers_cp_child(p_elem_list_SP, p_layer_index_u32, p_multi_layer_u32);
                }
                fl_element_valid = FALSE;
            }
            break;
        #endif /* #if (GFX_MGR02_NUM_DYNAMIC_WIDGETS > 0) || (GFX_MGR02_NUM_DYNAMIC_IMAGES > 0) */
        #if GFX_MGR02_NUM_OF_SWDGS > 0
            case GFX_MGR02_TYPE_SWIDGET:
            {
                if(fl_base_id < (UINT32)GFX_MGR02_NUM_OF_SWDGS)
                {
                    GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
                    GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP = &lc_swidget_layer_def_S[fl_base_id];

                    fl_vaof_index = hmi_gfx_mgr02_get_widget_layer_area(p_elem_list_SP, &fl_elem_area);

                    if(fl_widget_desc_SP->merge == (UINT8)0)
                    {
                        if (fl_context_SP->state.alpha > (UINT8)0)
                        {
                            fl_num_of_elem = p_elem_list_SP->num_child_elements;
                            if (fl_num_of_elem > (UINT32)0)
                            {
                                if ((fl_widget_desc_SP->merge == (UINT8)0) && (p_multi_layer_u32 == FALSE))
                                {
                                    l_cur_fractional_plane += 0x01U;
                                }
                                fl_elem_list_SP = &p_elem_list_SP->child[fl_num_of_elem - 0x01U];
                                while (fl_num_of_elem > (UINT32)0)
                                {
                                    fl_num_of_elem--;
                                    if (l_disp_comp[p_layer_index_u32].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
                                    {
                                        l_disp_comp[p_layer_index_u32].window_data[l_disp_comp[p_layer_index_u32].num_of_visible_elements].root_elem_sp = p_elem_list_SP;
                                    }
                                    hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP, p_layer_index_u32, (UINT32)TRUE);
                                    fl_elem_list_SP = &fl_elem_list_SP[-1];
                                }
                            }
                            fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                            fl_element_valid = FALSE;
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
                            fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                        }
                        else
                    #endif
                        {
                            hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index_u32);
                       #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0
                            if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
                            {
                                 hmi_gfx_mgr02_context_widget_set_active((UINT32)fl_widget_desc_SP->client_id);
                            }
    #endif
    #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
                            if(fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
                            {
                                fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
                            
                                if(hmi_gfx_mgr02_is_image_transparent(fl_image_desc_SP->format) == TRUE)
                                {
                                    fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                                }
                                else 
                                {
                                    fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                                }
                            }
    #endif
                        }
                    #ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
                       /* widgets with their own warping should not use the warping plane */
                        if(fl_widget_desc_SP->warp_id == GFX_MGR02_INVALID_WARP)
                   #endif /* #ifdef GFX_MGR02_WIDGET_WARPING_ENABLED */
                        {
                        #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                            fl_layer_desc_SP = &lc_layer_def_S[p_layer_index_u32];
                            if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
                            {
                               /* current layer should be warped, so we request the widget to be assigned for warping plane */
                                fl_win_features = CYGFX_DISP_FEATURE_WARP;
                            }
                        #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */

                        }
                        if(hmi_gfx_mgr02_amber_get_wdg_pix_format((u_gx_flocal)fl_widget_desc_SP->fb_format) == CYGFX_SM_FORMAT_YVYU422)
                        {
                        /*YUV format can't be combined with Warp*/
                            fl_win_features = CYGFX_DISP_FEATURE_YUV1BUFF;
                        }
#ifdef LBO_OTF_FEATURE_CC
                        switch(fl_widget_desc_SP->priority)
                        {
                            case CYGFX_BE_TASK_WIN_PRIO_0:
                            {
                                fl_win_features |= CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0;
                            }
                            break;
                            case CYGFX_BE_TASK_WIN_PRIO_1:
                            {
                                fl_win_features |= CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1;
                            }
                            break;
                            case CYGFX_BE_TASK_WIN_PRIO_2:
                            {
                                fl_win_features |= CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2;
                            }
                            break;
                            case CYGFX_BE_TASK_WIN_PRIO_3:
                            {
                                fl_win_features |= CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3;
                            }
                            break;

                            default:
                            {
                             /*to avoid misra warning*/
                            }
                            break;
                        }
#endif                        
                        if((fl_elem_area.ex > (SINT16)0)&& (fl_elem_area.ey > (SINT16)0))
                        {
                            fl_element_valid   = TRUE;
                        }
                        if(l_gfx_mgr02_amber_element_dirty_u8 == (UINT8)0)
                        {
                            l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_childrens_changed(p_elem_list_SP, TRUE);
                        }
                    }
                }
            }
            break;
        #endif /* #if GFX_MGR02_NUM_OF_SWDGS > 0 */
        #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
            case GFX_MGR02_TYPE_SIMAGE:
            {
                if(fl_base_id < (UINT32)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
                {
                    GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP = &lc_image_layer_def_S[fl_base_id];
                    fl_vaof_index = hmi_gfx_mgr02_get_image_layer_area(p_elem_list_SP, &fl_elem_area);
                    fl_elem_area.alpha = fl_context_SP->state.alpha;
                    fl_elem_area.sx    = fl_context_SP->state.loc.x;
                    fl_elem_area.sy    = fl_context_SP->state.loc.y;
                    hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index_u32);
                    #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                    fl_layer_desc_SP = &lc_layer_def_S[p_layer_index_u32];
                    if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
                    {
                       /* current layer should be warped, so we request the image to be assigned for warping plane */

                       /* Note that if the image is compressed this flag will be replaced, but its OK, because warp plane
                        * does not support decoding anyway, so the problem will be in the design
                        */
                        fl_win_features = CYGFX_DISP_FEATURE_WARP;
                    }
                    #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
                    #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                    if(p_multi_layer_u32 == FALSE)
                    {
                        if(fl_image_desc_SP->comp_size != (UINT32)0)
                        {
                            fl_win_features |= CYGFX_DISP_FEATURE_DECODE;
                        }
                    }
                    #endif
                    #if GFX_MGR02_NUM_OF_CLUTS > 0U
                    if((fl_image_desc_SP->format == CYGFX_SM_FORMAT_A8RGB8 )||
                         (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB8 )||
                         (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB4 )||
                         (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB2 )||
                         (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB1 ))
                    {   
                        fl_win_features |= CYGFX_DISP_FEATURE_INDEX_COLOR;
                        if(l_disp_comp[p_layer_index_u32].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
                        {
                            l_curframe_clut_idx_u16a[l_disp_comp[p_layer_index_u32].num_of_visible_elements] = fl_image_desc_SP->clut;
                        }
                    }
                    #endif		
                    if(hmi_gfx_mgr02_is_image_transparent(fl_image_desc_SP->format) == TRUE)
                    {
                        fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                    }
                    else
                    {
                        fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                    }
                    if((fl_elem_area.ex > (SINT16)0)&& (fl_elem_area.ey > (SINT16)0))
                    {
                        fl_element_valid   = TRUE;
                    }
                    if(l_gfx_mgr02_amber_element_dirty_u8 == (UINT8)0)
                    {
                        l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
                    }
                }
            }
            break;
        #endif
        #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
            case GFX_MGR02_TYPE_STEXT:
            case GFX_MGR02_TYPE_DTEXT:
            {
                #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                fl_layer_desc_SP = &lc_layer_def_S[p_layer_index_u32];
                if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
                {
                   /* current layer should be warped, so we request the text to be assigned for warping plane */
                   fl_win_features = CYGFX_DISP_FEATURE_WARP;
                }
                #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
                fl_elem_area.alpha = fl_context_SP->state.alpha;
                fl_elem_area.sx    = fl_context_SP->state.loc.x;
                fl_elem_area.sy    = fl_context_SP->state.loc.y;
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index_u32);
                /* for text always considered as transparent */
                fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                fl_element_valid   = TRUE;
                if(l_gfx_mgr02_amber_element_dirty_u8 ==(UINT8)0)
                {
                    l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
                }
            }
            break;
        #endif
        #if (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TILES > 0)
            case GFX_MGR02_TYPE_TILE:
            case GFX_MGR02_TYPE_FILL:
            {
                #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                fl_layer_desc_SP = &lc_layer_def_S[p_layer_index_u32];
                if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
                {
                   /* current layer should be warped, so we request the "fill" to be assigned for warping plane */
                   fl_win_features = CYGFX_DISP_FEATURE_WARP;
                }
                #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
                hmi_gfx_mgr02_get_tile_fill_layer_area(p_elem_list_SP, &fl_elem_area);
                fl_elem_area.alpha = fl_context_SP->state.alpha;
                fl_elem_area.sx    = fl_context_SP->state.loc.x;
                fl_elem_area.sy    = fl_context_SP->state.loc.y;
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index_u32);
                /* always considered as transparent */
                fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                fl_element_valid   = TRUE;
                if(l_gfx_mgr02_amber_element_dirty_u8 ==(UINT8)0)
                {
                    l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
                }
            }
            break;
        #endif
        #if GFX_MGR02_NUM_USER_LAYERS > 0
            case GFX_MGR02_TYPE_USER_LAYER:
            {
                fl_elem_list_SP = p_elem_list_SP;
                if(fl_elem_list_SP->base_id < GFX_MGR02_NUM_USER_LAYERS)
                {
                    /* Get the element area of the user_image element */
                    GFX_MGR02_IMAGE_DEF_T *fl_image_def_SP = &l_layer_anim_data_SP->user_image_layer[fl_elem_list_SP->base_id];
                    (void)hmi_gfx_mgr02_load_user_layer_def_info(fl_elem_list_SP->base_id, fl_image_def_SP);
                    if ((fl_image_def_SP->pixel_data != GFX_MGR02_NULL_PTR) &&
                        (fl_image_def_SP->height != (UINT16)0) &&
                        (fl_image_def_SP->width != (UINT16)0))
                    {
                        (void)hmi_gfx_mgr02_get_image_layer_area(fl_elem_list_SP, &fl_elem_area);
                        fl_elem_area.alpha = fl_context_SP->state.alpha;
                        fl_elem_area.sx = fl_context_SP->state.loc.x;
                        fl_elem_area.sy = fl_context_SP->state.loc.y;
                        hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index_u32);
                        
                        if (hmi_gfx_mgr02_is_image_transparent(fl_image_def_SP->format) == TRUE)
                        {
                            fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                        }
                        else
                        {
                            fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                        }
                        
                        fl_element_valid   = TRUE;
                    }
                    
                    if(l_gfx_mgr02_amber_element_dirty_u8 == (UINT8)0)
                    {
                        l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
                    }
                }
            }
            break;
        #endif
        #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
            case GFX_MGR02_TYPE_VIDEO_LAYER:
            {
                fl_element_valid      = TRUE;
                fl_win_features       = CYGFX_DISP_FEATURE_CAPTURE;
                hmi_gfx_mgr02_get_video_layer_area(p_elem_list_SP, &fl_elem_area);
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index_u32);
                l_gfx_mgr02_amber_element_dirty_u8 = TRUE;
            }
            break;
        #endif
            default:
            {
                fl_element_valid   = FALSE;
            }
            break;
        }


        if((fl_context_SP->state.invisible == (UINT8)0)&&(fl_element_valid == TRUE))
        {
            /*
            ** This element is with in displayable area and is not transparent.
            ** This element can be added to the render list and validated for
            ** visibility.
            */
            UINT32                    fl_cur_layer_index = l_disp_comp[p_layer_index_u32].num_of_visible_elements;
            GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP     = NULL;
            UINT8 fl_sublayer_available;
            if(fl_cur_layer_index < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
            {
                fl_win_data_SP =&l_disp_comp[p_layer_index_u32].window_data[fl_cur_layer_index];
            }
            if(fl_win_data_SP !=NULL)
            {
                if(hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_elem_area, 
                                                               l_disp_comp[p_layer_index_u32].num_of_visible_elements, 
                                                               &l_disp_comp[p_layer_index_u32].window_data[0]) == GFX_MGR02_ELEMENT_VISIBLE)
                {
                    /* 
                    ** The below element win_prop area includes vaoa index i.e. opaque area to be considered 
                    ** fl_elem_area_SP-> is the actual position of the element 
                    */
                    if(fl_win_data_SP->win_prop.topLeftX != (CYGFX_U32)fl_elem_area.sx)
                    {
                        fl_win_data_SP->win_prop.topLeftX =(CYGFX_U32) fl_elem_area.sx;
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->win_prop.topLeftY != (CYGFX_U32)fl_elem_area.sy)
                    {
                        fl_win_data_SP->win_prop.topLeftY = (CYGFX_U32)fl_elem_area.sy; 
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->win_prop.width != ((CYGFX_U32)fl_elem_area.ex- (CYGFX_U32)fl_elem_area.sx))
                    {
                        fl_win_data_SP->win_prop.width    = ((CYGFX_U32)fl_elem_area.ex- (CYGFX_U32)fl_elem_area.sx); 
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->win_prop.height != ((CYGFX_U32)fl_elem_area.ey-(CYGFX_U32)fl_elem_area.sy))
                    {
                        fl_win_data_SP->win_prop.height   = ((CYGFX_U32)fl_elem_area.ey-(CYGFX_U32)fl_elem_area.sy);
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->alpha != fl_elem_area.alpha)
                    {
                        fl_win_data_SP->alpha             = fl_elem_area.alpha;
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->clip.sx != fl_context_SP->state.clip.sx)
                    {
                        fl_win_data_SP->clip.sx           = fl_context_SP->state.clip.sx;
                    }
                    if(fl_win_data_SP->clip.sy != fl_context_SP->state.clip.sy)
                    {
                        fl_win_data_SP->clip.sy           = fl_context_SP->state.clip.sy;
                    }
                    if(fl_win_data_SP->clip.ex != fl_context_SP->state.clip.ex)
                    {
                        fl_win_data_SP->clip.ex           = fl_context_SP->state.clip.ex;
                    }
                    if(fl_win_data_SP->clip.ey != fl_context_SP->state.clip.ey)
                    {
                        fl_win_data_SP->clip.ey           = fl_context_SP->state.clip.ey;
                    }
                    if(fl_win_data_SP->curr_elem_sp  != p_elem_list_SP)
                    {
                        fl_win_data_SP->curr_elem_sp      = p_elem_list_SP;
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if(fl_win_data_SP->next_elem_sp  != p_elem_list_SP)
                    {
                        fl_win_data_SP->next_elem_sp      = p_elem_list_SP;
                    }
                    if(l_gfx_mgr02_amber_element_dirty_u8 == (UINT8)1)
                    {
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                        l_gfx_mgr02_amber_element_dirty_u8=(UINT8)0;
                    }
                    if((l_gfx_mgr02_amber_dwdg_dirty_u8 == (UINT8)1) &&(l_root_elem_list_SP == fl_win_data_SP->root_elem_sp))
                    {
                        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    }
                    if((l_cur_free_layer <= CYGFX_DISP_LAYER_4)&&
                        (l_disp_comp[p_layer_index_u32].num_of_planes_used <= lc_amber_num_planes_u8a[p_layer_index_u32]))
                    {
                        /* here > o is checked , as first element 0 will be kept in seperate layer */
                        if(l_disp_comp[p_layer_index_u32].num_of_visible_elements > (UINT8)0)
                        {
                        #if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER) || defined(GFX_MGR02_LAYER_WARPING_ENABLED)
                            fl_prev_num_of_layers = l_cur_free_layer; 
                        #endif
                            #if !defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
                            fl_sublayer_available = hmi_gfx_mgr02_is_sublayer_available((UINT32)l_cur_free_layer);
                            if((l_disp_comp[p_layer_index_u32].window_data[l_disp_comp[p_layer_index_u32].num_of_visible_elements-(UINT8)1].root_elem_sp !=fl_win_data_SP->root_elem_sp)||
                              ((TRUE == p_multi_layer_u32)&&(FALSE == fl_sublayer_available)))
                            {
                                l_cur_free_layer--;
                                l_disp_comp[p_layer_index_u32].num_of_planes_used++;

                                if((l_disp_comp[p_layer_index_u32].window_data[l_disp_comp[p_layer_index_u32].num_of_visible_elements-(UINT8)1].root_elem_sp !=fl_win_data_SP->root_elem_sp) &&
                                  ((l_cur_fractional_plane>(UINT8)0)&&(l_prev_fractional_plane ==l_cur_fractional_plane))&&
                                  (p_multi_layer_u32== TRUE))
                                {
                                    l_cur_free_layer++;
                                    l_disp_comp[p_layer_index_u32].num_of_planes_used--;
                                }
                                if(p_multi_layer_u32== TRUE)
                                {
                                    l_prev_fractional_plane =l_cur_fractional_plane;
                                }
                            }
                            #else
                            l_cur_free_layer--;
                            l_disp_comp[p_layer_index_u32].num_of_planes_used++;
                            #endif
                        }
                        else
                        {
                            if(p_multi_layer_u32== TRUE)
                            {
                                l_prev_fractional_plane =l_cur_fractional_plane;
                            }
                            l_disp_comp[p_layer_index_u32].num_of_planes_used++;
                        }
                        fl_win_data_SP->win_prop.layerId = (CYGFX_DISP_LAYER)l_cur_free_layer;

                        #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                        if(l_warp_plane_data.fp_no_of_sub_layer_used >= GFX_MGR02_NUM_OF_SUB_LAYER)
                        {
                         /* there is no more space on the warp plane - do not warp the element*/
                         fl_win_features &= ~CYGFX_DISP_FEATURE_WARP;
                        }

                        if((fl_win_features & CYGFX_DISP_FEATURE_WARP) == CYGFX_DISP_FEATURE_WARP)
                        {
                            /* make the window to have warp property */
                            fl_win_data_SP->win_prop.features = fl_win_features | CYGFX_DISP_FEATURE_MULTI_LAYER;

                            /* calculate the layer and sublayer of the warp plane */
                            if(l_warp_plane_data.fp_layer_id == GFX_MGR02_INVALID_LAYER)
                            {
                                /* warp plane still not been used, use the current layer */
                                fl_win_data_SP->win_prop.sub_layerId = (CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-l_warp_plane_data.fp_no_of_sub_layer_used);

                                l_warp_plane_data.fp_layer_id = fl_win_data_SP->win_prop.layerId;
                                l_warp_plane_data.fp_no_of_sub_layer_used++;
                            }
                            else
                            {
                                /* warp plane already used, so inherit its layer */
                                fl_win_data_SP->win_prop.layerId = (CYGFX_DISP_LAYER)l_warp_plane_data.fp_layer_id;
                                fl_win_data_SP->win_prop.sub_layerId =(CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-l_warp_plane_data.fp_no_of_sub_layer_used);
                                l_warp_plane_data.fp_no_of_sub_layer_used++;

                                /* restore the current layer since we reused the one from the warp plane */
                                l_cur_free_layer = fl_prev_num_of_layers;
                                l_disp_comp[p_layer_index_u32].num_of_planes_used--;

                            }

                        }
                        else
                        #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
                        if(p_multi_layer_u32 == FALSE)
                        {
                            fl_win_data_SP->win_prop.features = fl_win_features;
                        }
                        else
                        {
                            fl_win_data_SP->win_prop.features =(fl_win_features| CYGFX_DISP_FEATURE_MULTI_LAYER);
                            /* since fractional plane is not allocated and other layer is allocated for this element ,          */
                            /* we need to move this element to any one of fractional layer in l_fractional_plane_data[]. */
                            #if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
                            fl_fp_data_S = hmi_gfx_mgr02_get_available_fraction_plane_layer();
                            if(fl_fp_data_S != NULL)
                            {
                                /* Check whether element can be fitted into this sub layer */
                                if(fl_fp_data_S->fp_layer_id == GFX_MGR02_INVALID_LAYER)
                                {
                                    /* Layer not allocated to FP. Assign current layer to FP */ 
                                    fl_fp_data_S->fp_layer_id = fl_win_data_SP->win_prop.layerId;
                                    fl_win_data_SP->win_prop.sub_layerId  = (CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
                                    fl_fp_data_S->fp_no_of_sub_layer_used++;
                                }
                                else
                                {
                                    fl_elem_area.sx = fl_win_data_SP->win_prop.topLeftX;
                                    fl_elem_area.sy = fl_win_data_SP->win_prop.topLeftY;
                                    fl_elem_area.ex = fl_win_data_SP->win_prop.width;
                                    fl_elem_area.ey = fl_win_data_SP->win_prop.height;
                                    fl_no_of_element_U32 = l_disp_comp[p_layer_index_u32].num_of_visible_elements;
                                    fl_element_overlaps  = FALSE;
                                    while((fl_no_of_element_U32 != 0)&&(l_disp_comp[p_layer_index_u32].window_data[fl_no_of_element_U32-1].win_prop.layerId != fl_fp_data_S->fp_layer_id))
                                    {
                                        /* first check inbetween layer overlap if it overlapes then we cannot allocate to fl_fp_data_S.fp_layer_id*/
                                        fl_check_num_elements =  1;/* num of element in that layer check one by one as we dont know no of element in each layer*/
                                        if(hmi_gfx_mgr02_is_fractional_element_visible(&fl_elem_area,fl_check_num_elements,&l_disp_comp[p_layer_index_u32].window_data[fl_no_of_element_U32-1],TRUE) != GFX_MGR02_ELEMENT_VISIBLE)
                                        {
                                            fl_element_overlaps = TRUE;
                                        }
                                        fl_no_of_element_U32--;
                                    }
                                    if((fl_element_overlaps == FALSE)&&(fl_no_of_element_U32 != 0))
                                    {
                                        /* check for overlap and blending in fl_fp_data_S.fp_layer_id */
                                        fl_check_num_elements = fl_fp_data_S->fp_no_of_sub_layer_used;/*???????? need to check num of elements in fl_fp_data_S.fp_layer_id*/     
                                        if(hmi_gfx_mgr02_is_fractional_element_visible(&fl_elem_area,fl_check_num_elements,&l_disp_comp[p_layer_index_u32].window_data[fl_no_of_element_U32-1],FALSE) == GFX_MGR02_ELEMENT_VISIBLE)
                                        {
                                            /* change the already assigned layer id to fractional plane layer id. */
                                            fl_win_data_SP->win_prop.layerId      = (CYGFX_DISP_LAYER)fl_fp_data_S->fp_layer_id;
                                            fl_win_data_SP->win_prop.sub_layerId  = (CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
                                            fl_fp_data_S->fp_no_of_sub_layer_used++;
                                            /*revert back already decremented num of layer as new layer is not used */
                                            l_cur_free_layer = fl_prev_num_of_layers;
                                            l_disp_comp[p_layer_index_u32].num_of_planes_used--;
                                        }
                                        else
                                        {
                                            fl_fp_data_S = hmi_gfx_mgr02_get_unused_fractional_plane();
                                            if(fl_fp_data_S != NULL)
                                            {
                                                /* change the already assigned layer id to fractional plane layer id. */
                                                fl_fp_data_S->fp_layer_id             = l_cur_free_layer;
                                                fl_win_data_SP->win_prop.layerId      = (CYGFX_DISP_LAYER)l_cur_free_layer;
                                                fl_win_data_SP->win_prop.sub_layerId  = (CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
                                                fl_fp_data_S->fp_no_of_sub_layer_used++;
                                                /*No revert back of layer as it is new layer */
                                            }    
                                        }
                                    } 
                                }
                            }
                            #else /*defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)*/
                            {
                                /*Have a track of number of Sub layer windows used. 
                                This can be used to avoid if there are more than 8 active elements in Keep Layer widget.*/
                                if((l_cur_fractional_plane<=GFX_MGR02_NUM_OF_FRACTIONAL_PLANES) && (l_cur_fractional_plane > (UINT8)0))
                                {
                                    l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_layer_id=l_cur_free_layer;
                                    if(l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_no_of_sub_layer_used<CYGFX_DISP_SUB_LAYER_8)
                                    {
                                        fl_win_data_SP->win_prop.sub_layerId  = (CYGFX_DISP_SUB_LAYER)(CYGFX_DISP_SUB_LAYER_8-l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_no_of_sub_layer_used);
                                        l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_no_of_sub_layer_used++;   
                                    }
                                }
                            }
                            #endif 
                        }
                        /*
                        ** fl_win_data_SP->win_prop.topLeftX, topLeftY, width & height
                        ** stores the elements visible area information for visibility
                        ** check.
                        ** So temporarily store the elements actual XY location here
                        ** to restore it later back to win_prop. The width & height
                        ** information can be later read from element def.
                        */
                        fl_win_data_SP->posx = (SINT32)(fl_context_SP->state.loc.x);
                        fl_win_data_SP->posy = (SINT32)(fl_context_SP->state.loc.y);

                        if(fl_elem_area.is_transparent == (UINT8)GFX_MGR02_OPEQUE)
                        {
                            fl_win_data_SP->see_through = 0U;
                        }
                        else
                        {
                            fl_win_data_SP->see_through = 1U;
                        }

                        if(l_disp_comp[p_layer_index_u32].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
                        {
                            l_disp_comp[p_layer_index_u32].num_of_visible_elements++;
                        }
                        #ifdef GFX02_DEBUG_INFO
                        l_tot_num_of_elements++;
                        #endif
                    }
                }
            }
        }
    }
    hmi_gfx_mgr02_context_state_set(&fl_cur_context_S);
}
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_available_fraction_plane_layer
 ** Visibility:       static
 ** Description:      
 **                   
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T * hmi_gfx_mgr02_get_available_fraction_plane_layer(void)
{
    /*l_no_of_fractional_planes_used_in_layer[1] will be lower priority/nearer compared [0] .So start from GFX_MGR02_NUM_OF_FRACTIONAL_PLANES*/
    /*Eventhough both planes are partially used, always return the nearest plane. It will overlaps with nearest*/
    /*then anyways plane next to it cannot be used */
    UINT8 i;
    GFX_MGR02_FRACTIONAL_PLANE_DATA_T * fl_fp_data_SP = NULL;
    for(i = 0; i < GFX_MGR02_NUM_OF_FRACTIONAL_PLANES; i++)
    {
        if(l_fractional_plane_data[i].fp_no_of_sub_layer_used < CYGFX_DISP_SUB_LAYER_8)
        {
            /* fl_fp_data_SP means first fp itself free no need to check for low priority fp */
            if((l_fractional_plane_data[i].fp_layer_id == GFX_MGR02_INVALID_LAYER)&&
             (fl_fp_data_SP == NULL))
            {
                fl_fp_data_SP = &l_fractional_plane_data[i];
                return fl_fp_data_SP;
            }
            else
            {
                if(fl_fp_data_SP == NULL)
                {
                    fl_fp_data_SP = &l_fractional_plane_data[i];
                }
                else
                {
                    /* get low priority layer id used fractional plane */
                    if(l_fractional_plane_data[i].fp_layer_id < fl_fp_data_SP->fp_layer_id)
                    {
                        fl_fp_data_SP = &l_fractional_plane_data[i];
                    }
                }
            }
        }
    }
    return fl_fp_data_SP; 
}
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_unused_fractional_plane
 ** Visibility:       static
 ** Description:      This function copy the passed child element after verifying
 **                   that it is visible 
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          
 ** Updated:          
 **==========================================================================*/
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T *  hmi_gfx_mgr02_get_unused_fractional_plane(void)
{
    UINT8 i;
    GFX_MGR02_FRACTIONAL_PLANE_DATA_T * fl_fp_data_SP = NULL;

    /* need to check whether of GFX_MGR02_NUM_OF_FRACTIONAL_PLANES can be got from GDT gen code*/ 
    for(i= 0; i< GFX_MGR02_NUM_OF_FRACTIONAL_PLANES; i++)
    {
        if(l_fractional_plane_data[i].fp_layer_id == GFX_MGR02_INVALID_LAYER) 
        {
            fl_fp_data_SP = &l_fractional_plane_data[i];
        }
    }
    return fl_fp_data_SP;
}
#endif
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_unused_fractional_plane
 ** Visibility:       static
 ** Description:      This function copy the passed child element after verifying
 **                   that it is visible 
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          
 ** Updated:          
 **==========================================================================*/
static UINT8 hmi_gfx_mgr02_is_sublayer_available(UINT32 fl_layer_id_U32)
{
    UINT8 i;
    UINT8 fl_return_value = FALSE;

    /* need to check whether of GFX_MGR02_NUM_OF_FRACTIONAL_PLANES can be got from GDT gen code*/ 
    for(i= (UINT8)0; i< GFX_MGR02_NUM_OF_FRACTIONAL_PLANES; i++)
    {
        if(l_fractional_plane_data[i].fp_layer_id == fl_layer_id_U32) 
        {
            if(l_fractional_plane_data[i].fp_no_of_sub_layer_used < (UINT32)CYGFX_DISP_SUB_LAYER_8)
            {
                fl_return_value = TRUE;
                break;
            } 
        }
    }
    return(fl_return_value);
}

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
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT8 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP)
{
    UINT32                  fl_layer_visible = GFX_MGR02_ELEMENT_INVALID;
    GFX_MGR02_ELEMENT_AREA  fl_area={0,0,0,0,GFX_MGR02_OPEQUE,255};
    GFX_MGR02_ELEMENT_AREA  fl_area2={0,0,0,0,GFX_MGR02_OPEQUE,255};
    SINT16                  fl_temp;
    UINT8 fl_num_elements = p_num_elements;
    GFX_MGR02_WINDOW_DATA_T  * fl_window_SP = p_window_SP;
    while((fl_layer_visible == GFX_MGR02_ELEMENT_INVALID) && (fl_num_elements > (UINT32)0))
    {
        fl_area.sx    = (SINT16)fl_window_SP->win_prop.topLeftX;
        fl_area.sy    = (SINT16)fl_window_SP->win_prop.topLeftY;
        fl_area.ex    = (SINT16)fl_window_SP->win_prop.width;
        fl_area.ey    = (SINT16)fl_window_SP->win_prop.height;
        fl_area.alpha = (UINT8)fl_window_SP->alpha;

        if(fl_area.alpha == (UINT8)0)
        {
            /* 
            ** The alpha will never be a value of zero. i.e. if zero then this
            ** element will never add to the windows itself. It is only for safety 
            ** purpose 
            ** nkrishn9 confirm the statement from emanoj 
            */
            fl_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
        }
        else if((fl_window_SP->see_through != (UINT8)0) || (fl_area.alpha < (UINT8)255))
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_SEETHROUGH;
        }
        else
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        }
        fl_num_elements--;
        fl_window_SP++;
        while(fl_num_elements>(UINT32)0)
        {
            fl_num_elements--;
            fl_window_SP++;
            if(fl_window_SP->win_prop.sub_layerId!= (CYGFX_DISP_SUB_LAYER)CYGFX_DISP_SUB_LAYER_DEFAULT)
            {
                if(fl_area.is_transparent == (UINT8)GFX_MGR02_OPEQUE)
                {
                    if((fl_area.sx <= p_area->sx) && (fl_area.sy <= p_area->sy) &&
                       (fl_area.ex >= p_area->ex) && (fl_area.ey >= p_area->ey))
                    {
                        /*
                        ** p_area is completely hidden in fl_area
                        */
                        fl_layer_visible = GFX_MGR02_ELEMENT_INVISIBLE;
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
                                fl_area2.ey      = (fl_area.sy - (SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, fl_num_elements, fl_window_SP);
                                fl_area2.sy      = fl_area.sy;
                                fl_area2.ey      = p_area->ey;
                            }
                            if((fl_area.ey < p_area->ey) && (fl_layer_visible != GFX_MGR02_ELEMENT_VISIBLE))
                            {
                                /*
                                ** Visible bottom portion of the p_area rectangle
                                */
                                fl_temp          = fl_area2.sy;
                                fl_area2.sy      = (fl_area.ey + (SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, fl_num_elements, fl_window_SP);
                                fl_area2.sy      = fl_temp;
                                fl_area2.ey      = fl_area.ey;
                            }
                            if((fl_area.sx > p_area->sx) && (fl_layer_visible != GFX_MGR02_ELEMENT_VISIBLE))
                            {
                                /*
                                ** Visible Left portion of the p_area rectangle
                                */
                                fl_area2.ex      = (fl_area.sx - (SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, fl_num_elements, fl_window_SP);
                                fl_area2.ex      = p_area->ex;
                                
                            }
                            if((fl_area.ex < p_area->ex) && (fl_layer_visible != GFX_MGR02_ELEMENT_VISIBLE))
                            {
                                /*
                                ** Visible Right portion of the p_area rectangle
                                */
                                fl_area2.sx      = (fl_area.ex+(SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, fl_num_elements, fl_window_SP);
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
        }
    }
    if(fl_layer_visible == GFX_MGR02_ELEMENT_INVALID)
    {
        fl_layer_visible = GFX_MGR02_ELEMENT_VISIBLE;
    }
    return(fl_layer_visible);
}

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_video_layer_area
 ** Visibility:       static
 ** Description:      fetches the video elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_get_video_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA       * p_elem_area)
{
    p_elem_area->sx    = lc_video_layer_def_S.coord.x;  
    p_elem_area->sy    = lc_video_layer_def_S.coord.y;  
    p_elem_area->alpha = 255;
    p_elem_area->ey = (SINT16)lc_video_layer_def_S.dim.height;
    p_elem_area->ex = (SINT16)lc_video_layer_def_S.dim.width;   
    p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
    hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&lc_video_layer_def_S.coord);
    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)p_elem_area->alpha);
}
#endif 

#if (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TILES > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_tile_fill_layer_area
 ** Visibility:       static
 ** Description:      fetches the Tile, Fill elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_get_tile_fill_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, GFX_MGR02_ELEMENT_AREA * p_elem_area)
{
    UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    UINT32 fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
        if(fl_obj_type == GFX_MGR02_TYPE_TILE)
        {
        #if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_ANIM_ELEMENTS)
            {
                hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&l_layer_anim_data_SP->tile_prop[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_layer_anim_data_SP->tile_prop[fl_obj_id].alpha);
                p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.width;
                p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.height;
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
            }
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
            {
                hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&l_layer_anim_data_SP->fill_prop[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_layer_anim_data_SP->fill_prop[fl_obj_id].alpha);
                p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.width;
                p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.height;
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
            }
        #endif
        }
    }
    else
    {
        if(fl_obj_type == GFX_MGR02_TYPE_TILE)
        {
        #if GFX_MGR02_NUM_TILE_INSTANCES > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_TILE_INSTANCES)
            {
                hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&lc_tile_const_property_S[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_tile_const_property_S[fl_obj_id].alpha);
                if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_TILES)
                {
                    p_elem_area->ex      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.width;
                    p_elem_area->ey      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.height;
                }
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
            }
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_INSTANCES > 0
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_INSTANCES)
            {
                hmi_gfx_mgr02_context_set_loc(&lc_fill_const_property_S[fl_obj_id].coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_fill_const_property_S[fl_obj_id].alpha);
                if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS)
                {
                    p_elem_area->ex      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.width;
                    p_elem_area->ey      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.height;
                }
                p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
            }
        #endif
        }
    }
}
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_image_layer_area
 ** Visibility:       static
 ** Description:      fetches the Image elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA       * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    #if(GFX_MGR02_NUM_USER_LAYERS > 0 )
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    #endif
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    GFX_MGR02_IMAGE_DEF_T const * fl_image_layer_def_SP =NULL;

#if GFX_MGR02_NUM_USER_LAYERS > 0
    if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
    {
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
        {
            fl_image_layer_def_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
        }
        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
            GFX_MGR02_IMAGE_DYN_PROPERTY * fl_img_dyn_prop_SP = NULL;
            if(fl_obj_id< (UINT32)GFX_MGR02_NUM_USER_ANIM_ELEMENTS)
            {
                fl_img_dyn_prop_SP =&l_layer_anim_data_SP->user_prop[fl_obj_id];
                hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_img_dyn_prop_SP->coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_dyn_prop_SP->alpha);
            }
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
            GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = NULL;
            if(fl_obj_id< (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
            {
                fl_img_prop_SP=&lc_img_const_property_S[fl_obj_id];
                hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_prop_SP->alpha);
            }
        #endif
        }
    }
    else
#endif
    {
    #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
        {
            fl_image_layer_def_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
            if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
            {
            #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
                GFX_MGR02_IMAGE_DYN_PROPERTY const * fl_img_dyn_prop_SP = NULL;
                if(fl_obj_id <(UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
                {
                    fl_img_dyn_prop_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc(&fl_img_dyn_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_dyn_prop_SP->alpha);
                }
            #endif
            }
            else
            {
            #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
                GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = NULL;
                if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
                {
                    fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
                    hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_prop_SP->alpha);
                }
            #endif
            }
            if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
            {
                fl_vaof_index = (UINT32)fl_image_layer_def_SP->vaoa_index;
            }
        }
     #endif
    }
    if(fl_image_layer_def_SP != NULL)
    {
        p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
        p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
    }
    p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
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
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                  GFX_MGR02_ELEMENT_AREA      * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32 fl_base_id    = p_elem_list_SP->base_id;
    GFX_MGR02_WIDGET_DEF_T const * fl_widget_layer_def_SP =  NULL;
    if(fl_base_id < (UINT32)GFX_MGR02_NUM_OF_SWDGS)
    {
        fl_widget_layer_def_SP =&lc_swidget_layer_def_S[fl_base_id];

        if((fl_widget_layer_def_SP->rr_engine == GFX_MGR02_RT_DEFAULT) && 
           (fl_widget_layer_def_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE)
           &&(fl_widget_layer_def_SP->merge!=(UINT8)0))
        {
    #if (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0)
           GFX_FLOAT  fl_bound[4];
           /*
           ** For AMBER rendering mode, if clip not set, then the
           ** widget area needs to be calculated dynamically based
           ** current transformed bounds of the widget layer
           ** For this to work the element has to be animation enabled, so that
           ** its XY location can be modified.
           ** After the bound is calculated, it needs to be loaded to l_runtime_wdg_image_layer_def_S
           ** which is placed in RAM.
           */
            GFX_MGR02_IMAGE_DEF_T   *fl_image_layer_def_SP = NULL;
            if(fl_widget_layer_def_SP->image_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
            {	
                fl_image_layer_def_SP =&l_runtime_wdg_image_layer_def_S[fl_widget_layer_def_SP->image_id];
           
                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
                {
                    #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
                    UINT32 fl_aligned_width;
                    UINT32 fl_aligned_height;

                    GFX_MGR02_WIDGET_DYN_PROPERTY * fl_widg_dyn_prop_SP = NULL;
                    if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
                    {
                        fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
                        (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_list_SP, GFX_MGR02_TARGET_TRAVEO2, fl_bound);

                        fl_widg_dyn_prop_SP->coord.x    = (SINT16)fl_bound[0];
                        fl_widg_dyn_prop_SP->coord.y    = (SINT16)fl_bound[1];
                        fl_bound[0] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.x; /* get any remaining fractional part */
                        fl_bound[1] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.y;

                        fl_aligned_width  = ((UINT32)fl_bound[2]+(UINT32)fl_bound[0]+(UINT32)0.5);
                        fl_aligned_height = ((UINT32)fl_bound[3]+(UINT32)fl_bound[1]+(UINT32)0.5);

                        fl_image_layer_def_SP->width  = (GFX_MGR02_ISIZE_W_T)(fl_aligned_width);
                        fl_image_layer_def_SP->height = (GFX_MGR02_ISIZE_H_T)(fl_aligned_height);
                    }
                    #endif
                }            
                else
                {
                    fl_image_layer_def_SP->width  = (UINT16)0;
                    fl_image_layer_def_SP->height = (UINT16)0;
                }
                p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
                p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
                if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
                {
                    fl_vaof_index = (UINT32)fl_image_layer_def_SP->vaoa_index;
                }
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
            #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0   
            GFX_MGR02_IMAGE_DEF_T   const *fl_image_layer_def_SP = NULL;
            if(fl_widget_layer_def_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {
                fl_image_layer_def_SP = &lc_image_layer_def_S[fl_widget_layer_def_SP->image_id];
                p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
                p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
                if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
                {
                    fl_vaof_index = (UINT32)fl_image_layer_def_SP->vaoa_index;
                }
            }
            #endif
        }

        if(fl_widget_layer_def_SP->merge != (UINT8)0)
        {
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        }

        if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
        {
        #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
            GFX_MGR02_WIDGET_DYN_PROPERTY const  * fl_widg_dyn_prop_SP = NULL;
            GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
            GFX_MGR02_ILOC_DATA               fl_coord;
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
            {
                fl_widg_dyn_prop_SP =&l_layer_anim_data_SP->widget_prop[fl_obj_id];
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_widg_dyn_prop_SP->alpha);
             #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                if(fl_widget_layer_def_SP->clip_mode != GFX_MGR02_WP_CLIP_NONE)
                {
                    /*
                    ** When hmi_gfx_mgr02_context_set_clip is invoked, the clip
                    ** start X & Y is added with the current XY location in context
                    ** So we need to make sure we just have the offset of XY movement
                    ** alone in context prior to hmi_gfx_mgr02_context_set_clip call
                    ** After this call we can set the raw co-ordinate values
                    */
                    fl_elem_prop_SP = &lc_widget_anim_property_S[fl_obj_id];
                    fl_coord.x      = (SINT16)(-fl_elem_prop_SP->coord.x);
                    fl_coord.y      = (SINT16)(-fl_elem_prop_SP->coord.y);
                    hmi_gfx_mgr02_context_set_loc(&fl_coord);
                    hmi_gfx_mgr02_context_set_loc(&fl_widg_dyn_prop_SP->coord);
                    hmi_gfx_mgr02_context_set_clip(&fl_widg_dyn_prop_SP->clip);
                    if(fl_widget_layer_def_SP->merge != (UINT8)0)
                    {
                        fl_coord.x = -fl_coord.x;
                        fl_coord.y = -fl_coord.y;
                        hmi_gfx_mgr02_context_set_loc(&fl_coord);
                    }
                }
                else
             #endif             
                if(fl_widget_layer_def_SP->merge == (UINT8)0)
                {
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
            if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
            {
                if(fl_widget_layer_def_SP->merge != (UINT8)0)
                {
                    hmi_gfx_mgr02_context_set_loc(&lc_swdg_const_property_S[fl_obj_id].coord);
                }
                hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_swdg_const_property_S[fl_obj_id].alpha);
            }
        #endif 
        }
        
    }
    return(fl_vaof_index);
}
#endif  /* GFX_MGR02_NUM_OF_SWDGS */

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_display
 ** Visibility:       static
 ** Description:      This function copies the visible elements of passed screen
 **                   to render list  
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index_u32)
{
    static  UINT32 l_prev_disp_bg_color[GFX_MGR02_NUM_LAYERS]={0};
    CYGFX_S32 ret = CYGFX_OK;
    GFX_MGR02_WINDOW_DATA_T     * fl_win_data_SP;
    UINT8 fl_next_element;
    UINT8 fl_shutdown_state  = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    UINT8 fl_cur_window_U8;
    UINT8 fl_disp_commit_needed_u8 = (UINT8)FALSE;
    
    if(p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        if((l_disp_comp[p_layer_index_u32].num_of_visible_elements> (UINT8)0) &&(fl_shutdown_state != GFX_MGR02_SHUTDOWN_EMERGENCY))
        {

            ret = hmi_gfx_mgr02_destroy_invalid_windows(p_layer_index_u32);
            hmi_gfx_mgr02_allocate_windows(p_layer_index_u32);
          /*
          ** Check Whether the Display Commit Needed or not?
          */
            for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < l_disp_comp[p_layer_index_u32].num_of_visible_elements; fl_cur_window_U8++)
            {
                if(l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win_sts == GFX_MGR02_AMBER_WIN_UPDATED)
                {
                    fl_disp_commit_needed_u8 = (UINT8)TRUE;
                    break;
                }   
            }

          /*
          ** Commit the Display for the changes.
          */
            if(fl_disp_commit_needed_u8 != (UINT8)FALSE)
            {
                IRIS_API_CHECK(ret, CyGfx_DispCommit(l_disp_comp[p_layer_index_u32].display));
#ifdef LBO_OTF_FEATURE_CC
                fl_next_element = (UINT8)0;
                fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
                while(fl_next_element < (UINT8)l_disp_comp[p_layer_index_u32].num_of_visible_elements)
                {
                    if(fl_win_data_SP->besync_valid != (UINT8)0)
                    {
                        IRIS_API_CHECK(ret, CyGfx_WinWaitSync(fl_win_data_SP->win,fl_win_data_SP->be_sync));
                        fl_win_data_SP->besync_valid = (UINT8)0;
                    }
                    if(fl_win_data_SP->win != NULL)
                    {
                        IRIS_API_CHECK(ret, CyGfx_WinCommit(fl_win_data_SP->win));
                        
                    }
                    fl_next_element++;
                    fl_win_data_SP++;
                }
#endif                
                #if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)
                GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP;
                GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP;
                GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
                GFX_MGR02_CONTEXT_T p_cntx_SP;
                UINT32 fl_obj_type;
                
                fl_next_element = l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U;
                fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
                while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements)
                {   
                    if(fl_win_data_SP->valid != (UINT8)0)
                    {
                        p_elem_list_SP = fl_win_data_SP->next_elem_sp;
                        fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
                        if(fl_obj_type == GFX_MGR02_TYPE_SWIDGET)
                        {
                            fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
                            if(fl_widget_desc_SP->use_extram == GFX_MGR02_USE_VRAM_HRAM)
                            {
                                #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS>0
                                if((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT) && 
                                   (fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE))
                                {
                                      fl_image_desc_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
                                }
                                else
                                #endif
                                {
                                    #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0 
                                    fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
                                    #endif
                                }
                                p_cntx_SP.rprop.fb_target  = GFX_MGR02_TARGET_TRAVEO2; 
                                p_cntx_SP.rprop.fb_format   = fl_widget_desc_SP->fb_format;
                                p_cntx_SP.rprop.fb_w  = fl_image_desc_SP->width;
                                p_cntx_SP.rprop.fb_h = fl_image_desc_SP->height;
#ifndef(LBO_OTF_FEATURE_CC)
                                #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
                                p_cntx_SP.rprop.pe_sync    = l_disp_comp[p_layer_index_u32].gpu_sync;
                                #endif
#endif                                
                                CYGFX_BE_CONTEXT fl_pe_cntx  = hmi_gfx_mgr02_context_get_pixeng_ctx(fl_widget_desc_SP->client_id);
                                p_cntx_SP.rprop.pe_ctx = fl_pe_cntx;
                                if(fl_pe_cntx != (CYGFX_BE_CONTEXT)NULL)
                                {
                                    (void)hmi_gfx_mgr02_context_copy_fb(fl_widget_desc_SP->client_id, &p_cntx_SP);
                                }
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                    if (fl_next_element > 0U)
                    {
                        fl_next_element--;
                        fl_win_data_SP--;
                    }
                    else
                    {
                        break;
                    }               
                }
                #endif /* GFX_MGR02_AMBER_USE_VRAM_HRAM */
                #ifdef LBO_OTF_FEATURE_CC
                fl_next_element = (UINT8)0;
                fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
                while(fl_next_element < (UINT8)l_disp_comp[p_layer_index_u32].num_of_visible_elements)
                {

                    if((fl_win_data_SP->win != NULL)&&(fl_win_data_SP->win_sync!=NULL))
                    {
                        IRIS_API_CHECK(ret, CyGfx_WinGetSync(fl_win_data_SP->win,fl_win_data_SP->win_sync));
                    }
                    fl_next_element++;
                    fl_win_data_SP++;
                }
                #endif				
                IRIS_API_CHECK(ret, CyGfx_DispGetSync(l_disp_comp[p_layer_index_u32].display,l_disp_comp[p_layer_index_u32].disp_sync));
                #ifdef GFX_MGR02_AMBER_SKIP_BUSY_CHK
                IRIS_API_CHECK(ret, mmlGdcPeWaitSync(l_disp_comp[p_layer_index_u32].disp_sync));
                #endif          
                for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < l_disp_comp[p_layer_index_u32].num_of_visible_elements; fl_cur_window_U8++)
                {
                    if(l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win_sts == GFX_MGR02_AMBER_WIN_UPDATED)
                    {
                        l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win_sts = GFX_MGR02_AMBER_WIN_COMMITED;
                    }   
                }
                l_content_ready_ondisplay =(UINT32)2;
                fl_disp_commit_needed_u8 = (UINT8)FALSE;
            }

          l_cur_num_of_elements[p_layer_index_u32] = l_disp_comp[p_layer_index_u32].num_of_visible_elements;
       }
        else
        {
            /*Destroy the active windows if the number visible element is Zero.*/
            fl_next_element = (UINT8)0;
            fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            while(fl_next_element < (UINT8)l_cur_num_of_elements[p_layer_index_u32])
            {
                if(fl_win_data_SP->win != NULL)
                {
                    IRIS_API_CHECK(ret, CyGfx_WinDestroy(fl_win_data_SP->win));
                    fl_win_data_SP->win         = NULL;
                    fl_win_data_SP->win_prop.topLeftX = (CYGFX_U32)0;
                    fl_win_data_SP->win_prop.topLeftY = (CYGFX_U32)0;
                    fl_win_data_SP->win_prop.width =(CYGFX_U32)0;
                    fl_win_data_SP->win_prop.height =(CYGFX_U32)0;
                    fl_win_data_SP->win_prop.features = (CYGFX_U32)0;
                    fl_win_data_SP->next_elem_sp = NULL;
                    fl_win_data_SP->curr_elem_sp = NULL;
                    fl_win_data_SP->root_elem_sp = NULL;
                    fl_win_data_SP->posx = 0;
                    fl_win_data_SP->posy = 0;
                    fl_win_data_SP->alpha = 0;
                    fl_win_data_SP->win_colour = 0;
                    fl_win_data_SP->see_through =0;
                    fl_win_data_SP->valid =(UINT8) 0;
                    fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                    fl_disp_commit_needed_u8 = (UINT8)TRUE;
                }
                fl_next_element++;
                fl_win_data_SP++;
            }
            if (fl_disp_commit_needed_u8 == (UINT8)TRUE)
            {
                l_cur_num_of_elements[p_layer_index_u32] = (UINT8)0;
                l_content_ready_ondisplay = (UINT32)1;
            }
        }
        if (l_prev_disp_bg_color[p_layer_index_u32] != l_disp_comp[p_layer_index_u32].bg_colour)
        {
            (void)CyGfx_DispSetAttribute(l_disp_comp[p_layer_index_u32].display, CYGFX_DISP_ATTR_BACKGROUND_COLOR, l_disp_comp[p_layer_index_u32].bg_colour);
            l_prev_disp_bg_color[p_layer_index_u32] = l_disp_comp[p_layer_index_u32].bg_colour;
            fl_disp_commit_needed_u8 = (UINT8)TRUE;
        }
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
        if (l_prev_disp_attribute[p_layer_index_u32] != l_disp_comp[p_layer_index_u32].input_control)
        {
            l_prev_disp_attribute[p_layer_index_u32] = l_disp_comp[p_layer_index_u32].input_control;
            IRIS_API_CHECK(ret, CyGfx_DispSetAttribute(l_disp_comp[p_layer_index_u32].display, CYGFX_DISP_ATTR_IN_CTRL, l_disp_comp[p_layer_index_u32].input_control));
            fl_disp_commit_needed_u8 = (UINT8)TRUE;
        }
#endif
        if (fl_disp_commit_needed_u8 == (UINT8)TRUE)
        {
            IRIS_API_CHECK(ret, CyGfx_DispCommit(l_disp_comp[p_layer_index_u32].display));
            IRIS_API_CHECK(ret, CyGfx_DispGetSync(l_disp_comp[p_layer_index_u32].display, l_disp_comp[p_layer_index_u32].disp_sync));
        }
    }	
    GFX_MGR02_UNUSED_VAR(ret);
}


static CYGFX_ERROR hmi_gfx_mgr02_destroy_invalid_windows(UINT32 p_layer_index_u32)
{
    CYGFX_ERROR ret = CYGFX_OK;
    GFX_MGR02_WINDOW_DATA_T     * fl_win_data_SP;
    UINT8 fl_next_element;
    UINT8 fl_cur_window_U8;
    UINT8 fl_win_order_changed_u8 = (UINT8)FALSE;
    
    if(p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        fl_next_element = l_disp_comp[p_layer_index_u32].num_of_visible_elements;
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            while(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
            {
                if(fl_win_data_SP->win != NULL)
                {
                    #ifdef LBO_OTF_FEATURE_CC
                    CYGFX_U32 fl_win_param_U32;
                    if(CyGfx_WinGetAttribute( fl_win_data_SP->win,CYGFX_WIN_ATTR_FEATURE,&fl_win_param_U32) == CYGFX_OK)
                    {
                        if((fl_win_param_U32 & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[0].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[0].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[1].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[1].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[2].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[2].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[3].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[3].allow_win = ((CYGFX_U08)0);
                        }
                        else
                        {
                            /*Do Nothing.*/
                        }
                    }
                    IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_win_data_SP->surf));
                    #endif
                    IRIS_API_CHECK(ret, CyGfx_WinDestroy(fl_win_data_SP->win));

                    fl_win_data_SP->win         = NULL;
                    fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                }
                fl_next_element++;
                fl_win_data_SP++;
            }
        }
        /*
        Check whether Window order got changed. If changed then destroy all windows 
        and render the content freshly.
        */
        fl_next_element = l_disp_comp[p_layer_index_u32].num_of_visible_elements -1U;
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP          = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            while(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
            {

                fl_win_data_SP->win_prop.topLeftX = (CYGFX_U32)fl_win_data_SP->posx;
                fl_win_data_SP->win_prop.topLeftY = (CYGFX_U32)fl_win_data_SP->posy;
                fl_win_data_SP->valid             = 0x01U;

                if(fl_win_data_SP->win != NULL)
                {
                    CYGFX_U32 fl_win_param = 0U;
                    UINT32 fl_win_valid = FALSE;
                    /*
                    ** check if the window plane & features match the next window
                    ** requirement. If yet we neednot destroy the window
                    */
                    if(CyGfx_WinGetAttribute( fl_win_data_SP->win, CYGFX_WIN_ATTR_LAYER_ID, &fl_win_param) == CYGFX_OK)
                    {
                        if(fl_win_param == fl_win_data_SP->win_prop.layerId)
                        {
                            if(CyGfx_WinGetAttribute( fl_win_data_SP->win,
                              CYGFX_WIN_ATTR_FEATURE,
                              &fl_win_param) == CYGFX_OK)
                            {

                                if(fl_win_data_SP->win_prop.features == fl_win_param) 
                                {
         
                                    if(((fl_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0)) &&
                                       ((fl_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1)) &&
                                       ((fl_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2)) &&
                                       ((fl_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3)))
                                       
                                    {
                                        fl_win_valid =TRUE;
                                    }
                                    else
                                    {
                                        CYGFX_U32 fl_win_height_U32 = 0U;
                                        CYGFX_U32 fl_win_width_U32 = 0U;
                                        IRIS_API_CHECK(ret, CyGfx_WinGetAttribute( fl_win_data_SP->win,CYGFX_WIN_ATTR_HEIGHT,&fl_win_height_U32));
                                        IRIS_API_CHECK(ret, CyGfx_WinGetAttribute( fl_win_data_SP->win,CYGFX_WIN_ATTR_WIDTH,&fl_win_width_U32));                               
                                        if((fl_win_data_SP->win_prop.width == fl_win_width_U32)&&(fl_win_data_SP->win_prop.height == fl_win_height_U32))
                                        {
                                            fl_win_valid =TRUE;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                    if(fl_win_valid == FALSE)
                    {
                      /*Window Order Got changed. Destroy all windows in order to 
                        reallocate it. 
                        */  
                        fl_win_order_changed_u8 = (UINT8)TRUE;
                        break;
                    }
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
        if(fl_win_order_changed_u8 != (UINT8)FALSE)
        {
            fl_next_element         = l_disp_comp[p_layer_index_u32].num_of_visible_elements -0x01U;
            fl_win_data_SP          = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];

            while(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
            {
                fl_win_data_SP->win_prop.topLeftX = (CYGFX_U32)fl_win_data_SP->posx;
                fl_win_data_SP->win_prop.topLeftY = (CYGFX_U32)fl_win_data_SP->posy;
                fl_win_data_SP->valid = TRUE;
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }      
            }
            for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS; fl_cur_window_U8++)
            {
                if(l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win != NULL)
                {
                    #ifdef LBO_OTF_FEATURE_CC
                    CYGFX_U32 fl_win_param_U32;
                    if(CyGfx_WinGetAttribute( l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win,CYGFX_WIN_ATTR_FEATURE,&fl_win_param_U32) == CYGFX_OK)
                    {
                        if((fl_win_param_U32 & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[0].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[0].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[1].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[1].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[2].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[2].allow_win = ((CYGFX_U08)0);
                        }
                        else if((fl_win_param_U32  & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) ==(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3))
                        {
                            IRIS_API_CHECK(ret, CyGfx_DispGetVSync(l_disp_comp[p_layer_index_u32].display, l_otf[3].vsync, NUM_OF_OTF_WINDOW_FRAMES_TO_SKIP ));
                            l_otf[3].allow_win = ((CYGFX_U08)0);
                        }
                        else
                        {
                            /*Do Nothing.*/
                        }
                    }

                    #endif
                    IRIS_API_CHECK(ret, CyGfx_WinDestroy(l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win));

                    l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win = NULL;
                    l_disp_comp[p_layer_index_u32].window_data[fl_cur_window_U8].win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
                }   
            }       
            hmi_gfx_mgr02_context_reset_widget_buff_id();
        }
    }
    return ret;
}

static void hmi_gfx_mgr02_allocate_windows(UINT32 p_layer_index_u32)
{
    GFX_MGR02_WINDOW_DATA_T     * fl_win_data_SP;
    UINT32 fl_feature_mask;
    UINT32 fl_decode_feature_count = 0UL;
    UINT8 fl_next_element;
    UINT8 fl_exit_check_flag = FALSE;
    
    if(p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        /*
        ** Allocate windows in recomended order
        ** 1. window with feature CYGFX_DISP_FEATURE_DECODE
        ** 2. window with feature CYGFX_DISP_FEATURE_IMAGE_PROCESSING, CYGFX_DISP_FEATURE_CAPTURE, CYGFX_DISP_FEATURE_YUV1BUFF).
        ** 3. window with feature CYGFX_DISP_FEATURE_EXTERN_ALPHA.
        ** 4. window with feature CYGFX_DISP_FEATURE_WARP.
        ** 5. window with feature CYGFX_DISP_FEATURE_MULTI_LAYER (cannot have decode feature)
        ** 6. window with feature CYGFX_DISP_FEATURE_INDEX_COLOR
        ** 7. Rest of the windows
        */
        fl_next_element = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((CYGFX_U32)(CYGFX_DISP_FEATURE_DECODE|CYGFX_DISP_FEATURE_MULTI_LAYER));

            while((fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) && (fl_exit_check_flag == FALSE) )
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_DECODE)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                        fl_decode_feature_count++;
                        if(fl_decode_feature_count >= GFX_MGR02_NUM_OF_DECODE_LAYERS)
                        {
                        /*
                        ** No more decode windows are allowed
                        */
                              fl_exit_check_flag = TRUE;
                        }
                    }
                }
                else
                {
                /*
                ** here onwards, the windows are not valid as there is not enough planes to allocate them.
                */
                    fl_exit_check_flag = TRUE;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate Windows with CYGFX_DISP_FEATURE_IMAGE_PROCESSING, CYGFX_DISP_FEATURE_CAPTURE and CYGFX_DISP_FEATURE_YUV1BUFF.
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((CYGFX_U32)(CYGFX_DISP_FEATURE_IMAGE_PROCESSING|CYGFX_DISP_FEATURE_CAPTURE|CYGFX_DISP_FEATURE_YUV1BUFF));

            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if(((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_IMAGE_PROCESSING)||
                      ((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_CAPTURE)||
                      ((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_YUV1BUFF))
                    {
                      hmi_gfx_mgr02_render_window(fl_win_data_SP, p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate Windows with CYGFX_DISP_FEATURE_EXTERN_ALPHA Here.
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((UINT32)(CYGFX_DISP_FEATURE_EXTERN_ALPHA));

            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate Windows with CYGFX_DISP_FEATURE_WARP feature here.
            ** The Warp Plane is a Fractional Plane.
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((UINT32)(CYGFX_DISP_FEATURE_MULTI_LAYER|CYGFX_DISP_FEATURE_WARP));

            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements)
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate all multilayer feature windows
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((UINT32)(CYGFX_DISP_FEATURE_MULTI_LAYER|CYGFX_DISP_FEATURE_INDEX_COLOR));

            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate all multilayer feature windows
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {			
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask = ((UINT32)(CYGFX_DISP_FEATURE_MULTI_LAYER));
            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_MULTI_LAYER)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** Allocate all indexcolor feature windows
            */
        fl_next_element  = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP   = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            fl_feature_mask  = (CYGFX_U32)CYGFX_DISP_FEATURE_INDEX_COLOR;

            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (CYGFX_U32)CYGFX_DISP_FEATURE_INDEX_COLOR)
                    {
                        hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                    }
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
        }
            /*
            ** All other windows
            */
        fl_next_element = (l_disp_comp[p_layer_index_u32].num_of_visible_elements-0x01U);
        if(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
        {
            fl_win_data_SP  = &l_disp_comp[p_layer_index_u32].window_data[fl_next_element];
            
            while(fl_next_element < l_disp_comp[p_layer_index_u32].num_of_visible_elements) 
            {
                if(fl_win_data_SP->valid != (UINT8)0)
                {
                    hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index_u32);
                }
                else
                {
                    break;
                }
                if (fl_next_element > 0U)
                {
                    fl_next_element--;
                    fl_win_data_SP--;
                }
                else
                {
                    break;
                }
            }
            
        }
    }
}
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_fractional_element_visible
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
 **                   +\\\c+\\\   b   +
 **                   -----------------
 **                   this function will recursively check for the exposed sub area
 **                   'a' (Visible top portion) and 'b' (Visible Right portion) seperately
 **                   against elem 2 to 5 to see if they are getting
 **                   hidden or not.  So after the recursive loop finally determines that
 **                   a passed area is fully hidden it returns FALSE else it returns TRUE.
 **                   02_design\hmi_gfx_mgr02_design.xls implements a xls macro to proveout
 **                   this logic.
 ** Invocation:       By hmi_gfx_mgr02_manage_layers().
 ** Inputs/Outputs:   p_area              - Pointer to area of the element
 **                   p_elem_list_SAP     - Pointer to the element list above.
 **                   p_num_elements      - number of elements in p_elem_list_SAP.
 **                   p_check_btwn_layers - TRUE  - check to be done between layer
 **                                         FALSE - check to be done between sub layers   
 ** Critical Section: None.
 ** Created:          
 ** Updated:          
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_is_fractional_element_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT32 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP,
                                                           UINT8  p_check_btwn_layers)
{
    UINT32                  fl_layer_visible = GFX_MGR02_ELEMENT_INVALID;
    GFX_MGR02_ELEMENT_AREA  fl_area={0,0,0,0,GFX_MGR02_OPEQUE,255};
    GFX_MGR02_ELEMENT_AREA  fl_area2={0,0,0,0,GFX_MGR02_OPEQUE,255};
    SINT16                  fl_temp=0;
    UINT8                   fl_layer_overlap=0;
    UINT32                  fl_num_elements = p_num_elements;
    while((fl_layer_visible == GFX_MGR02_ELEMENT_INVALID) && (fl_num_elements > 0U))
    {
        fl_area.sx        = (SINT16)p_window_SP->win_prop.topLeftX;
        fl_area.sy        = (SINT16)p_window_SP->win_prop.topLeftY;
        fl_area.ex        = (SINT16)p_window_SP->win_prop.width;
        fl_area.ey        = (SINT16)p_window_SP->win_prop.height;
        fl_area.alpha     = (UINT8)p_window_SP->alpha;
        fl_layer_overlap  = FALSE;

        if(p_window_SP->alpha == 0)
        {
            /* 
            ** The alpha will never be a value of zero. i.e. if zero then this
            ** element will never add to the windows itself. It is only for safety 
            ** purpose 
            ** nkrishn9 confirm the statement from emanoj 
            */
            fl_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
        }
        else if((p_window_SP->see_through != 0) || (p_window_SP->alpha < 255))
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_SEETHROUGH;
        }
        else
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        }

        if((fl_area.sx <= p_area->sx) && (fl_area.sy <= p_area->sy) &&
           (fl_area.ex >= p_area->ex) && (fl_area.ey >= p_area->ey))
        {
            /*
            ** p_area is completely hidden in fl_area
            */
            fl_layer_overlap = TRUE;
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
                 fl_layer_overlap = TRUE;

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
        if((fl_layer_overlap == TRUE)&&(p_check_btwn_layers == TRUE))
        {
           fl_layer_visible = GFX_MGR02_ELEMENT_INVISIBLE; 
        }

        /* Only for within the same fractional plane */  
        else if((p_check_btwn_layers == FALSE)&&(fl_layer_overlap == TRUE))
        {
             
           if (fl_area.is_transparent != (UINT8)GFX_MGR02_OPEQUE)
           {
               /* if executed , then its p_check_btwn_layers = FALSE ie. within sub layers*/
               fl_layer_visible = GFX_MGR02_ELEMENT_INVISIBLE; 
           }
        }
        else
        {
            /* do nothing */
        }
        fl_num_elements--;
        p_window_SP--;
    }
    if(fl_layer_visible == GFX_MGR02_ELEMENT_INVALID)
    {
       fl_layer_visible = GFX_MGR02_ELEMENT_VISIBLE;
    }
    return(fl_layer_visible);
}
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_image_transparent
 ** Visibility:       static
 ** Description:      
 ** Invocation:       
 ** Inputs/Outputs:   
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static UINT8 hmi_gfx_mgr02_is_image_transparent(UINT8 fl_format_U8)
{
   UINT8 fl_image_transparent_U8;
   switch(fl_format_U8)
   {
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
      {
         fl_image_transparent_U8 = TRUE;
      }
      break;
      default:
      {
         fl_image_transparent_U8 = FALSE;
      }
        break;
   }
   return fl_image_transparent_U8;
}
#endif
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_set_blendmode
 ** Visibility:       static
 ** Description:      
 ** Invocation:       
 ** Inputs/Outputs:   
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static void hmi_gfx_mgr02_set_blendmode(GFX_MGR02_WINDOW_DATA_T const * p_wind, GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP, CYGFX_U32 p_blend_mode)
{
    CYGFX_U32 fl_win_blend_mode = p_blend_mode;
    UINT32 fl_bg_color;
    CYGFX_S32 ret;

    switch(p_image_desc_SP->format)
    {
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
        case CYGFX_SM_FORMAT_A4RGB4:
        {
            fl_win_blend_mode |= (CYGFX_U32)(CYGFX_WIN_BLEND_SOURCE_ALPHA);
        }
        break;

        case CYGFX_SM_FORMAT_A8:
        case CYGFX_SM_FORMAT_A4:
        case CYGFX_SM_FORMAT_A2:
        case CYGFX_SM_FORMAT_A1:
        {
            fl_win_blend_mode |= (CYGFX_U32)(CYGFX_WIN_BLEND_SOURCE_ALPHA|CYGFX_WIN_BLEND_SOURCE_MULTIPLY_ALPHA);
        }
        break;

        default:
        {
            fl_win_blend_mode |= (CYGFX_U32)CYGFX_WIN_BLEND_NONE;
        }
        break;
    }
    
    fl_bg_color = p_wind->alpha;
    
    if(fl_bg_color < (UINT32)255)
    {
        fl_win_blend_mode |= (CYGFX_U32)CYGFX_WIN_BLEND_GLOBAL_ALPHA;
    }                        

    if(p_image_desc_SP->chroma_key != (UINT8)0)
    {
        fl_bg_color |= (p_image_desc_SP->color << 8U);
        fl_win_blend_mode |= (CYGFX_U32)CYGFX_WIN_BLEND_TRANSPARENCY;
    }
    else
    {
        fl_bg_color |=  (p_wind->win_colour << 8U);
    }
    
    if(fl_win_blend_mode != 0UL)
    {
        IRIS_API_CHECK(ret, CyGfx_WinSetBlendMode(p_wind->win, fl_win_blend_mode));
        IRIS_API_CHECK(ret, CyGfx_WinSetAttribute(p_wind->win, CYGFX_WIN_ATTR_COLOR, fl_bg_color));
    }
    else
    {
        IRIS_API_CHECK(ret, CyGfx_WinSetBlendMode(p_wind->win, (CYGFX_U32)CYGFX_WIN_BLEND_NONE));
    }
    
    GFX_MGR02_UNUSED_VAR(ret);
}
#endif
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_window
 ** Visibility:       static
 ** Description:      
 **                   
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_create_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index_u32)
{
    CYGFX_ERROR ret = CYGFX_OK;
    if(p_layer_index_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        if(p_win_data_SP->win == NULL)
        {
        #ifdef GFX02_DEBUG_INFO
            printf("CreateWndow[%d] - plane=%d features=%X", (p_win_data_SP-&l_disp_comp[p_layer_index_u32].window_data[0]), p_win_data_SP->win_prop.layerId,p_win_data_SP->win_prop.features);
        #endif
            IRIS_API_CHECK(ret, CyGfx_DispWinCreate(l_disp_comp[p_layer_index_u32].display,
                                                &p_win_data_SP->win_prop,
                                                &p_win_data_SP->win));
            IRIS_API_CHECK(ret, CyGfx_WinSetAttribute(p_win_data_SP->win, CYGFX_WIN_ATTR_DISABLE, (CYGFX_U32)CYGFX_FALSE));

            IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                     CYGFX_WIN_ATTR_TILE_MODE,
                                                     (CYGFX_U32)CYGFX_DISP_TILE_MODE_ZERO));
        }
        else
        {
        #ifdef GFX02_DEBUG_INFO
            printf("UpdateWndow[%d] - plane=%d features=%X\n", (p_win_data_SP-&l_disp_comp[p_layer_index_u32].window_data[0]), p_win_data_SP->win_prop.layerId,p_win_data_SP->win_prop.features);
        #endif
            IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                     CYGFX_WIN_ATTR_TOPLEFT_X,
                                                     p_win_data_SP->win_prop.topLeftX));
            IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                     CYGFX_WIN_ATTR_TOPLEFT_Y,
                                                     p_win_data_SP->win_prop.topLeftY));
            #ifdef GFX02_DEBUG_INFO
            printf("The CYGFX_WIN_ATTR_WIDTH and CYGFX_WIN_ATTR_HEIGHT attributes are read only for OTF window.\n");
            #endif
            #ifdef LBO_OTF_FEATURE_CC
            if(((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0)) &&
               ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1)) &&
               ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2)) &&
               ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3)))
            {
                IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                         CYGFX_WIN_ATTR_WIDTH,
                                                         p_win_data_SP->win_prop.width));
                IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                         CYGFX_WIN_ATTR_HEIGHT,
                                                         p_win_data_SP->win_prop.height));
            }
            #else
                IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                         CYGFX_WIN_ATTR_WIDTH,
                                                         p_win_data_SP->win_prop.width));
                IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                         CYGFX_WIN_ATTR_HEIGHT,
                                                         p_win_data_SP->win_prop.height));                
            #endif
        }
    #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
        {
            GFX_MGR02_WARP_ID warp_id = lc_layer_def_S[p_layer_index_u32].warp_id;
            if((warp_id != GFX_MGR02_INVALID_WARP) && (warp_id < l_warp_table_size))
            {
                void  * fl_buff_ptr = (void  *)l_warp_table[warp_id].warp_buffer;
                if((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_WARP) == CYGFX_DISP_FEATURE_WARP)
                {
                    
                    IRIS_API_CHECK(ret,CyGfx_WinSetWarpBuffer(p_win_data_SP->win,
                                                             (const MML_GDC_WARP_PARAM*)(l_warp_table[warp_id].warp_params),
                                                             fl_buff_ptr,
                                                             NULL));
                }
            }
        }
    #endif
    #if defined(GFX_CYPRESS_ROTATION_ENABLED)
        CYGFX_FLOAT matrix[6]= CUSTOM_MATRIX_DISPLAY;
        matrix[4]=p_win_data_SP->win_prop.width;
        matrix[5]=p_win_data_SP->win_prop.height;
        if(p_win_data_SP->win_prop.width!= l_mml_gdc_dispParams[p_layer_index_u32].timing.Hact)
        {
          IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                     CYGFX_WIN_ATTR_TOPLEFT_X,
                                                     (l_mml_gdc_dispParams[p_layer_index_u32].timing.Hact-p_win_data_SP->win_prop.topLeftX-p_win_data_SP->win_prop.width)));
        }
        if(p_win_data_SP->win_prop.height!= l_mml_gdc_dispParams[p_layer_index_u32].timing.Vact)
        {
          IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,
                                                     CYGFX_WIN_ATTR_TOPLEFT_Y,
                                                     (l_mml_gdc_dispParams[p_layer_index_u32].timing.Vact-p_win_data_SP->win_prop.topLeftY-p_win_data_SP->win_prop.height)));

        }
        IRIS_API_CHECK(ret,CyGfx_WinSetGeoMatrix(p_win_data_SP->win,CYGFX_DISP_BUFF_TARGET_COLOR_BUFF,matrix));
    #endif
    }
    GFX_MGR02_UNUSED_VAR(ret);
}
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_render_window
 ** Visibility:       static
 ** Description:      
 **                   
 ** Invocation:       Invoked by 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index_u32)
{
    UINT32 fl_obj_type;
    UINT32 fl_obj_id;
    GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP = p_win_data_SP->next_elem_sp;
    CYGFX_S32 ret = CYGFX_OK;


    if((fl_elem_list_SP != NULL)&& (p_win_data_SP->win_sts == GFX_MGR02_AMBER_WIN_DIRTY))
    {
        /*
        ** Static elements which does not require RAM. So by default prepare the
        ** DCU configuration registers.
        */
        fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
        fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);

        p_win_data_SP->win_prop.topLeftX =(CYGFX_U32)p_win_data_SP->posx;
        p_win_data_SP->win_prop.topLeftY =(CYGFX_U32)p_win_data_SP->posy;

        switch(fl_obj_type)
        {
        #if (GFX_MGR02_NUM_OF_SWDGS > 0) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
            case GFX_MGR02_TYPE_SWIDGET:
            {
                #ifdef LBO_OTF_FEATURE_CC
                if((((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) == (CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0)) && (l_otf[0].allow_win != ((CYGFX_U08)0)))||
                   (((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) == (CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1)) && (l_otf[1].allow_win != ((CYGFX_U08)0)))||
                   (((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) == (CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2)) && (l_otf[2].allow_win != ((CYGFX_U08)0)))||
                   (((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) == (CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3)) && (l_otf[3].allow_win != ((CYGFX_U08)0)))||
                   (((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_0)) &&
                    ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_1)) &&
                    ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_2)) &&
                    ((p_win_data_SP->win_prop.features & CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3) !=(CYGFX_U32)(CYGFX_DISP_FEATURE_OTF_WIN_PRIO_3))))
                    {
                        hmi_gfx_mgr02_build_widget(p_win_data_SP, fl_elem_list_SP,p_layer_index_u32);
                    }
                #else
                    hmi_gfx_mgr02_build_widget(p_win_data_SP, fl_elem_list_SP,p_layer_index_u32);
                #endif
            }
            break;
        #endif
        #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
            case GFX_MGR02_TYPE_STEXT:
            case GFX_MGR02_TYPE_DTEXT:
            {
            /* TODO : not supported */
            }
            break;
        #endif
        #if GFX_MGR02_NUM_USER_LAYERS > 0
            case GFX_MGR02_TYPE_USER_LAYER:
            {
                hmi_gfx_mgr02_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index_u32);
            }
            break;
        #endif
        #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
            case GFX_MGR02_TYPE_VIDEO_LAYER:
            {
                hmi_gfx_mgr02_build_video(p_win_data_SP, fl_elem_list_SP, p_layer_index_u32);
            }
            break;
        #endif

        #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
            case GFX_MGR02_TYPE_SIMAGE:
            {
                hmi_gfx_mgr02_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index_u32);
            }
            break;
        #endif
        #if GFX_MGR02_NUM_OF_FILLS > 0
            case GFX_MGR02_TYPE_FILL:
            {
                hmi_gfx_mgr02_build_fill(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index_u32);
            }
            break;
        #endif
        #if GFX_MGR02_NUM_OF_TILES > 0
            case GFX_MGR02_TYPE_TILE:
            {
                /* TODO : not supported */
            }
            break;
        #endif
            default:
            {
            /*
            ** This condition will never happen
            */
                if(p_win_data_SP->win != NULL)
                {
                    IRIS_API_CHECK(ret, CyGfx_WinDestroy(p_win_data_SP->win));
                    p_win_data_SP->win = NULL;
                }
            }
            break;
        }
    }
    GFX_MGR02_UNUSED_VAR(ret);
}
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
static void hmi_gfx_mgr02_build_video(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        CYGFX_S32                    ret = CYGFX_OK;     
        GFX_MGR02_CAPTURE_INIT_STATUS          fl_cap_init_status;
        static UINT8              fl_stability_flag = TRUE;  

        fl_cap_init_status = hmi_gfx_mgr02_get_capture_init_status();
        hmi_gfx_mgr02_capture_video_set_status(TRUE);  

        if(fl_cap_init_status != GFX_MGR02_CAPTURE_INIT_SUCCESS)
        {
            GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status;           
            fl_init_status = hmi_gfx_mgr02_capture_to_window_init(&l_disp_timing, lc_video_layer_def_S);

            if(fl_init_status == GFX_MGR02_CAPTURE_INIT_SUCCESS)
            {
                MML_GDC_SYNC*              fl_cap_sync;
                CYGFX_CAP_CTX *fl_cap_ctx = hmi_gfx_mgr02_get_capture_context();
                hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index); 
                IRIS_API_CHECK(ret, CyGfx_WinSetCapture(p_win_data_SP->win, *fl_cap_ctx));
                IRIS_API_CHECK(ret, CyGfx_WinCommit(p_win_data_SP->win));
                fl_cap_sync = hmi_gfx_mgr02_get_capture_sync(); 
                if (CYGFX_ERP_ERR_SYNC_TIMEOUT == CyGfx_SyncWaitSync(*fl_cap_sync, (CYGFX_S32)0))
                {
                }
                else
                {
                    /* switch window on, after 2 frames (cap-to-win is now stable) */
                    IRIS_API_CHECK(ret, CyGfx_WinSetBlendMode(p_win_data_SP->win, CYGFX_WIN_BLEND_NONE));
                    IRIS_API_CHECK(ret, CyGfx_WinCommit(p_win_data_SP->win));
                    p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                    fl_stability_flag = TRUE;
                }
            } 
        }

    }
}
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_image
 ** Visibility:       static
 ** Description:      Builds/Updates image element
 ** Invocation:       By hmi_gfx_mgr02_render_window
 ** Inputs/Outputs:   GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_build_image(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP =GFX_MGR02_NULL_PTR;
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
    GFX_MGR02_IAREA_DATA           fl_elem_area_S={(SINT16)0,(SINT16)0,(UINT16)0,(UINT16)0};
    SINT32                         fl_start_offset = 0;
    UINT32                         fl_bpp = (UINT32)0;
    #endif
    UINT32                         fl_obj_id;
    #if GFX_MGR02_NUM_USER_LAYERS > 0
    UINT32                         fl_obj_type;
    #endif
    UINT32                         fl_rle_words;
    UINT32                         fl_invisible = FALSE;
    CYGFX_S32                         ret = CYGFX_OK;
    void                         * fl_buff_ptr;

    if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
    {
        fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        #if GFX_MGR02_NUM_USER_LAYERS > 0
        fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
        #endif
        #if GFX_MGR02_NUM_USER_LAYERS > 0
        if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER) 
        {
            if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_USER_LAYERS)
            {
                fl_image_desc_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
            }
        }
        else
        #endif
        {
            #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
            if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
            {
                fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
            }
            #endif
        }
        if(fl_image_desc_SP != GFX_MGR02_NULL_PTR)
        {
            fl_buff_ptr  = (void *)fl_image_desc_SP->pixel_data;

            #if defined(GFX_MGR02_COMPRESSION_ENABLED)

                fl_rle_words = fl_image_desc_SP->comp_size;

            #else
            fl_rle_words =(UINT32)0;  
            #endif

            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            fl_elem_area_S.x      =(SINT16)p_win_data_SP->win_prop.topLeftX;
            fl_elem_area_S.y      =(SINT16) p_win_data_SP->win_prop.topLeftY;
            fl_elem_area_S.width  = fl_image_desc_SP->width;
            fl_elem_area_S.height = fl_image_desc_SP->height;

            hmi_gfx_mgr02_context_reset_state();
            if(hmi_gfx_mgr02_context_combine_clip(&p_win_data_SP->clip,&fl_elem_area_S) == FALSE)
            {
                fl_start_offset = ((SINT32)p_win_data_SP->clip.sx - (SINT32)p_win_data_SP->win_prop.topLeftX);
                if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->width))
                {
                    fl_bpp          = hmi_gfx_mgr02_get_bpp((UINT32)(fl_image_desc_SP->format));
                    fl_buff_ptr     = &((UINT8 *)fl_buff_ptr)[(fl_bpp * (UINT32)fl_start_offset)>>3U];
                    fl_start_offset = ((SINT32)p_win_data_SP->clip.sy - (SINT32)p_win_data_SP->win_prop.topLeftY);

                    if((GFX_MGR02_ISIZE_W_T)fl_start_offset < fl_image_desc_SP->width)
                    {
                        if(fl_start_offset > 0)
                        {
                            fl_buff_ptr = &((UINT8 *)fl_buff_ptr)[(UINT32)fl_start_offset * ((fl_bpp * fl_image_desc_SP->width)>>3U)];
                        }
                        else
                        {
                          /*
                          ** There is no Y clipping needed, but still the clip is valid
                          ** so just load a positive value so that the succeding if(fl_start_offset > 0)
                          ** becomes true and proceedes with the clip configurations
                           */
                           fl_start_offset = 1;
                        }
                        p_win_data_SP->win_prop.topLeftX = (CYGFX_U32)p_win_data_SP->clip.sx;
                        p_win_data_SP->win_prop.topLeftY = (CYGFX_U32)p_win_data_SP->clip.sy;
                        p_win_data_SP->win_prop.width    = (CYGFX_U32)p_win_data_SP->clip.ex;
                        p_win_data_SP->win_prop.width   -= (CYGFX_U32)p_win_data_SP->clip.sx;
                        p_win_data_SP->win_prop.height   = (CYGFX_U32)p_win_data_SP->clip.ey;
                        p_win_data_SP->win_prop.height  -= (CYGFX_U32)p_win_data_SP->clip.sy;
                    }
                }
                else
                {
                    fl_start_offset = 0;
                }
            }
            else
            {
                fl_invisible=TRUE;
            }
             #endif
             if(fl_invisible==FALSE)
             {

                IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(p_win_data_SP->surf));
                if((CYGFX_SM_FORMAT_RGB4 == fl_image_desc_SP->format) ||
                 (CYGFX_SM_FORMAT_RGB2 == fl_image_desc_SP->format) ||
                 (CYGFX_SM_FORMAT_A6R6G6B6 == fl_image_desc_SP->format))
                {
                    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                           p_win_data_SP->win_prop.width, 
                                                           p_win_data_SP->win_prop.height,
                                                           CYGFX_SM_FORMAT_R8G8B8A8, 
                                                           fl_buff_ptr,
                                                           fl_rle_words));

                    if(CYGFX_SM_FORMAT_RGB2 ==fl_image_desc_SP->format)
                    {
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x02));
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS,   (CYGFX_U32)0x02020200));
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT,  (CYGFX_U32)0x00000000));
                    }
                    else if(CYGFX_SM_FORMAT_RGB4 ==fl_image_desc_SP->format)
                    {
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x04));
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS,   (CYGFX_U32)0x04040400));
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT,  (CYGFX_U32)0x00000000));
                    }
                    else
                    {
                      /*CYGFX_SM_FORMAT_A6R6G6B6*/
                      IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x18));
                      IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS, (CYGFX_U32)0x06060606));
                      IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT, (CYGFX_U32)0x0c060012));
                    }
                }
                else
                {       
                    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                        p_win_data_SP->win_prop.width,
                                                        p_win_data_SP->win_prop.height,
                                                        (CYGFX_SM_FORMAT)fl_image_desc_SP->format,
                                                        fl_buff_ptr, 
                                                        fl_rle_words));
                }
                #if defined(GFX_MGR02_CLIPPED_WIDGETS)      
                if(fl_start_offset >= 0)
                {   
                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_WIDTH, p_win_data_SP->win_prop.width));
                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_HEIGHT,p_win_data_SP->win_prop.height));
                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_STRIDE,((fl_image_desc_SP->width * fl_bpp)+7UL)>>3U));
                }
                #endif    
                #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                if(fl_rle_words != (UINT32)0)
                {
                    switch(fl_image_desc_SP->compression)
                    {
                        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLE:
                        {
                            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (CYGFX_U32)CYGFX_SM_COMP_RLC));
                        }
                        break;
                        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLA:
                        {
                            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (CYGFX_U32)CYGFX_SM_COMP_RLA));
                        }
                        break;
                        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLD:
                        {
                            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (CYGFX_U32)CYGFX_SM_COMP_RLAD));
                        }
                        break;
                        default:
                        {
                           /*To avoid MISRA warning.*/
                        }
                        break;
                    }
                }
                #endif

                #if GFX_MGR02_NUM_OF_CLUTS > 0U
                if(fl_image_desc_SP->clut < GFX_MGR02_NUM_OF_CLUTS)
                {
                    CYGFX_PALETTE fl_pal_p = NULL;
                    GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_image_desc_SP->clut];
                    CYGFX_U32 fl_clut_index_width_u32;
                    UINT16 fl_clut_size;
                    
                    if((fl_image_desc_SP->format == CYGFX_SM_FORMAT_A8RGB8) || (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB8))
                    {
                        fl_clut_size = 256U; 
                    }
                    else if (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB4 )
                    {
                        fl_clut_size = 16U;
                    }
                    else if (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB2 )
                    {
                        fl_clut_size = 4U;
                    }
                    else if (fl_image_desc_SP->format == CYGFX_SM_FORMAT_RGB1 )
                    {
                        fl_clut_size = 2U;
                    }
                    else
                    {
                        fl_clut_size = 256U;
                    }
                    
                    fl_clut_index_width_u32 = hmi_gfx_mgr02_tv2_get_clut_index_width(fl_clut_size);
                    fl_pal_p = hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION_DISPLAY, fl_elem_clut_SP->CLUT);
                    if(fl_pal_p == NULL)
                    {
                        fl_pal_p = hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION_DISPLAY, (const void*)fl_elem_clut_SP->CLUT, fl_clut_size);
                        if(fl_pal_p == NULL)
                        {
                            hmi_gfx_mgr02_tv2_free_unused_cluts();
                            fl_pal_p = hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION_DISPLAY, (const void*)fl_elem_clut_SP->CLUT, fl_clut_size);
                        #ifdef GFX02_DEBUG_INFO
                            if(fl_pal_p ==NULL)
                            {
                                printf("\nOnly 1KB Display Palette RAM available. It seems; your design needs morethan that. Optimize the design.\n");
                            }
                        #endif
                        }
                    }
                    if (CYGFX_SM_FORMAT_A8RGB8 == fl_image_desc_SP->format)
                    {            
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS, ((fl_clut_index_width_u32 << 24u) | (0x00000008UL))));
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT, fl_clut_index_width_u32));
                    }
                    else
                    {
                        /* Since alpha bits are zero for non-APAL16 indexed images, there is no need to set COLORSHIFT for alpha channel */
                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS, (fl_clut_index_width_u32 << 24u)));
                    }
                    
                    IRIS_API_CHECK(ret, CyGfx_SmPaletteAssign(p_win_data_SP->surf, fl_pal_p));
                }
                #endif
            }
          
            if(fl_invisible==FALSE)
            {
                hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))           
                {
                    #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)     
                    GFX_MGR02_IMAGE_DYN_PROPERTY const * fl_image_dyn_property_SP;
                    if(fl_obj_id < (UINT32)GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS)
                    {
                        fl_image_dyn_property_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
                        p_win_data_SP->win_colour = fl_image_dyn_property_SP->fg_color;
                    }
                    #endif 
                }
                else
                {
                    #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0  
                    GFX_MGR02_IMAGE_PROPERTY const * fl_image_const_prop_SP;
                    if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SIMAGE_INSTANCES)
                    {
                        fl_image_const_prop_SP= &lc_img_const_property_S[fl_obj_id];
                        p_win_data_SP->win_colour = fl_image_const_prop_SP->fg_color;
                    }
                    #endif
                }
                hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP,(CYGFX_U32)CYGFX_WIN_BLEND_SOURCE_MULTIPLY_ALPHA);
                IRIS_API_CHECK(ret, CyGfx_WinSetSurface(p_win_data_SP->win, (CYGFX_U32)CYGFX_DISP_BUFF_TARGET_COLOR_BUFF,p_win_data_SP->surf));
                p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                #ifdef LBO_OTF_FEATURE_CC
                p_win_data_SP->besync_valid = (UINT8)0;
                #endif
            }
            #ifdef GFX02_DEBUG_INFO
            printf("Build Image  -- win=%X, Surf=%X\n", p_win_data_SP->win,p_win_data_SP->surf);
            #endif
        }
    }
    GFX_MGR02_UNUSED_VAR(ret);
    GFX_MGR02_UNUSED_VAR(p_obj_id);
}
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_fill
 ** Visibility:       static
 ** Description:      Builds/Updates fill element
 ** Invocation:       By hmi_gfx_mgr02_render_window
 ** Inputs/Outputs:   GFX_MGR02_WINDOW_DATA_T, UINT32, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_build_fill(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    GFX_MGR02_IAREA_DATA           fl_elem_area_S={(SINT16)0,(SINT16)0,(UINT16)0,(UINT16)0};
    UINT32                       fl_invisible = FALSE;
    SINT32 ret= CYGFX_OK;
    UINT32 fl_rgba_u32;

    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
        UINT32  fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
        GFX_MGR02_FILL_DYN_PROPERTY  const * fl_fill_anim_prop_SP;
        UINT32 fl_temp;
        if(fl_obj_id < (UINT32)GFX_MGR02_NUM_FILL_ANIM_ELEMENTS)
        {
            fl_fill_anim_prop_SP = &l_layer_anim_data_SP->fill_prop[fl_obj_id];		
            fl_temp = (fl_fill_anim_prop_SP->color>>24U); /*get alpha value of the fill colour*/
            fl_temp = ((fl_temp* fl_fill_anim_prop_SP->alpha)/(UINT32)255);
            fl_temp = (fl_temp <<24U);
            p_win_data_SP->win_colour   = (fl_fill_anim_prop_SP->color<<8U);/*AARRGGBB format*/
            p_win_data_SP->win_colour   = (p_win_data_SP->win_colour>>8U);
            p_win_data_SP->win_colour  |= fl_temp;
            fl_elem_area_S.height       = fl_fill_anim_prop_SP->dim.height;
            fl_elem_area_S.width        = fl_fill_anim_prop_SP->dim.width;
        }
    #endif
    }
    else
    {
     #if GFX_MGR02_NUM_FILL_INSTANCES > 0
         GFX_MGR02_FILL_DEF_T  const * fl_fill_desc_SP;
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_FILLS)
        {
            fl_fill_desc_SP  = &lc_fill_layer_def_S[p_elem_list_SP->base_id];
            p_win_data_SP->win_colour   = fl_fill_desc_SP->color;
            fl_elem_area_S.height       = fl_fill_desc_SP->dim.height;
            fl_elem_area_S.width        = fl_fill_desc_SP->dim.width;
        }
     #endif
    }
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
    fl_elem_area_S.x      = (SINT16)p_win_data_SP->win_prop.topLeftX;
    fl_elem_area_S.y      = (SINT16)p_win_data_SP->win_prop.topLeftY;
    if(hmi_gfx_mgr02_context_combine_clip(&p_win_data_SP->clip,(GFX_MGR02_IAREA_DATA const *)&fl_elem_area_S) == FALSE)
    {
        p_win_data_SP->win_prop.topLeftX = (CYGFX_U32)p_win_data_SP->clip.sx;
        p_win_data_SP->win_prop.topLeftY = (CYGFX_U32)p_win_data_SP->clip.sy;
        p_win_data_SP->win_prop.width    = (CYGFX_U32)p_win_data_SP->clip.ex;
        p_win_data_SP->win_prop.width   -= (CYGFX_U32)p_win_data_SP->clip.sx;
        p_win_data_SP->win_prop.height   = (CYGFX_U32)p_win_data_SP->clip.ey;
        p_win_data_SP->win_prop.height  -= (CYGFX_U32)p_win_data_SP->clip.sy;
    }
    else
    {
        fl_invisible =TRUE;
    }
    #else
    if(fl_invisible==FALSE)
    {
        p_win_data_SP->win_prop.width = (CYGFX_U32)fl_elem_area_S.width;
        p_win_data_SP->win_prop.height =(CYGFX_U32)fl_elem_area_S.height;
    }
    #endif
    if(fl_invisible==FALSE)
    {
        hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
        IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(p_win_data_SP->surf));
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf,
                                                    p_win_data_SP->win_prop.width, 
                                                    p_win_data_SP->win_prop.height,
                                                    CYGFX_SM_FORMAT_R8G8B8A8, 
                                                    (void *)0, 
                                                    (CYGFX_U32)0));

        fl_rgba_u32 = p_win_data_SP->win_colour;
        fl_rgba_u32 = fl_rgba_u32<<8U;                  /*Remove Alpha content*/
        fl_rgba_u32 |= (p_win_data_SP->win_colour>>24U);/*Now added the colour with Alpha Content to get RRGGBBAA format */
        IRIS_API_CHECK(ret,CyGfx_WinSetAttribute(p_win_data_SP->win,CYGFX_WIN_ATTR_TILE_MODE,(CYGFX_U32)CYGFX_DISP_TILE_MODE_CONST ))
        IRIS_API_CHECK(ret, CyGfx_WinSetBlendMode(p_win_data_SP->win, CYGFX_WIN_BLEND_GLOBAL_ALPHA|CYGFX_WIN_BLEND_SOURCE_MULTIPLY_ALPHA));
        IRIS_API_CHECK(ret, CyGfx_WinSetAttribute( p_win_data_SP->win,CYGFX_WIN_ATTR_COLOR,fl_rgba_u32));
        IRIS_API_CHECK(ret, CyGfx_WinSetSurface(p_win_data_SP->win, (CYGFX_U32)CYGFX_DISP_BUFF_TARGET_COLOR_BUFF, p_win_data_SP->surf));
        p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
        #ifdef LBO_OTF_FEATURE_CC
        p_win_data_SP->besync_valid = (UINT8)0;
        #endif
    }
    GFX_MGR02_UNUSED_VAR(ret);
    GFX_MGR02_UNUSED_VAR(p_obj_id);
}
#endif /* GFX_MGR02_NUM_OF_FILLS */


#if (GFX_MGR02_NUM_OF_SWDGS > 0) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_widget
 ** Visibility:       static
 ** Description:      Builds the widget element for the first time. Initializes
 **                   RAM and then copies all active elements.
 ** Invocation:       By hmi_gfx_mgr02_build_visible_elements
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 **==========================================================================*/
static void hmi_gfx_mgr02_build_widget(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP =GFX_MGR02_NULL_PTR;
    GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP=GFX_MGR02_NULL_PTR;
    GFX_MGR02_CONTEXT_GB_T         fl_build_elem_S;

    UINT32   fl_clear_buffer          = FALSE;
    UINT32   fl_clear_color           = 0UL;
    UINT32   fl_element_change_status ;
    UINT32   fl_pix_format;
    UINT32   fl_obj_id;
    CYGFX_ERROR ret = CYGFX_OK;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    GFX_MGR02_VISIBLE_AREA         fl_elem_clip_S;
    SINT32                         fl_start_offset;
    UINT32                         fl_bpp = 0UL;
    UINT32                         fl_buff_offset = 0UL;
#endif
    if(p_layer_index<GFX_MGR02_NUM_LAYERS)
    {  
        if(p_elem_list_SP->base_id < (UINT16)GFX_MGR02_NUM_OF_SWDGS)
        {
            fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];
        }
        if(fl_widget_desc_SP != GFX_MGR02_NULL_PTR)
        {
        #if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS>0
            if((fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT) && 
              (fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE))
            {
                if(fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
                {
                    fl_image_desc_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_desc_SP->image_id];
                }
            }
            else
        #endif
            {
                #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0 
                if(fl_widget_desc_SP->image_id < (UINT16)GFX_MGR02_NUM_OF_IMAGE_LAYERS)
                {
                    fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
                }
                #endif
            }
            if(fl_image_desc_SP !=GFX_MGR02_NULL_PTR)
            {
                fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
                fl_build_elem_S.area.width  = fl_image_desc_SP->width;
                fl_build_elem_S.area.height = fl_image_desc_SP->height;
                fl_build_elem_S.fb_format   = fl_widget_desc_SP->fb_format;
                fl_pix_format = hmi_gfx_mgr02_amber_get_wdg_pix_format(fl_build_elem_S.fb_format); 

                if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
                {
                #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
                    if(fl_obj_id < (UINT32)GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS)
                    {
                        if(fl_widget_desc_SP->clip_mode == GFX_MGR02_WP_CLIP_NONE) 
                        {
                            GFX_MGR02_WIDGET_DYN_PROPERTY const * fl_wdgt_anim_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
                            fl_build_elem_S.area.x = fl_wdgt_anim_prop_SP->coord.x;
                            fl_build_elem_S.area.y = fl_wdgt_anim_prop_SP->coord.y;
                            /*Clear Colour is made TRUE here. Dirty Area Redraw not applicable for GFX_MGR02_WP_CLIP_NONE widgets.
                            For the widgets of type other than GFX_MGR02_WP_CLIP_NONE, the application logic to handle to clear
                            the widget by adding the Fill screen.*/
                            fl_clear_buffer        = TRUE;
                            fl_clear_color         = fl_widget_desc_SP->bg_fill_color;
                            p_win_data_SP->win_colour = fl_wdgt_anim_prop_SP->fg_color;
                        }
                        else
                        {
                            fl_build_elem_S.area.x = lc_widget_anim_property_S[fl_obj_id].coord.x;
                            fl_build_elem_S.area.y = lc_widget_anim_property_S[fl_obj_id].coord.y;
                            p_win_data_SP->win_colour = lc_widget_anim_property_S[fl_obj_id].fg_color;
                        }
                    }
                #endif
                }
                else
                {
                    #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
                    if(fl_obj_id < (UINT32)GFX_MGR02_NUM_SWDG_INSTANCES)
                    {
                        fl_build_elem_S.area.x = lc_swdg_const_property_S[fl_obj_id].coord.x;
                        fl_build_elem_S.area.y = lc_swdg_const_property_S[fl_obj_id].coord.y;
                        p_win_data_SP->win_colour = lc_swdg_const_property_S[fl_obj_id].fg_color;
                    }
                    #endif
                }
                #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                fl_elem_clip_S.sx = (SINT16)p_win_data_SP->win_prop.topLeftX;
                fl_elem_clip_S.sy = (SINT16)p_win_data_SP->win_prop.topLeftY;
                fl_elem_clip_S.ex = (SINT16)fl_build_elem_S.area.width;
                fl_elem_clip_S.ey = (SINT16)fl_build_elem_S.area.height;
                fl_elem_clip_S.ex+= fl_elem_clip_S.sx;
                fl_elem_clip_S.ey+= fl_elem_clip_S.sy;
                if(hmi_gfx_mgr02_context_validate_clip(&p_win_data_SP->clip,
                                                  &fl_elem_clip_S) == FALSE)
                {
                    fl_start_offset = ((SINT32)p_win_data_SP->clip.sx - (SINT32)p_win_data_SP->win_prop.topLeftX);
                    if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->width))
                    {
                       fl_bpp          = hmi_gfx_mgr02_get_bpp(fl_pix_format);
                       fl_buff_offset  = ((fl_bpp * (UINT32)fl_start_offset)>>3U);
                       fl_start_offset = ((SINT32)p_win_data_SP->clip.sy - (SINT32)p_win_data_SP->win_prop.topLeftY);
                       if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->height))
                       {
                          fl_buff_offset += ((UINT32)fl_start_offset * ((fl_bpp * fl_image_desc_SP->width)>>3U));
                          p_win_data_SP->win_prop.topLeftX = (CYGFX_U32)p_win_data_SP->clip.sx;
                          p_win_data_SP->win_prop.topLeftY = (CYGFX_U32)p_win_data_SP->clip.sy;
                          p_win_data_SP->win_prop.width    = (CYGFX_U32)p_win_data_SP->clip.ex;
                          p_win_data_SP->win_prop.width   -= (CYGFX_U32)p_win_data_SP->clip.sx;
                          p_win_data_SP->win_prop.height   = (CYGFX_U32)p_win_data_SP->clip.ey;
                          p_win_data_SP->win_prop.height  -= (CYGFX_U32)p_win_data_SP->clip.sy;
                       }
                    }
                }
                #endif
                if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
                {
                    /* 
                    ** no need to build again if the content is active / nothing changed
                    */
                    fl_element_change_status = hmi_gfx_mgr02_layout_is_element_childrens_changed(p_elem_list_SP, TRUE);
                    if((fl_element_change_status != FALSE) || (p_win_data_SP->win_sts == GFX_MGR02_AMBER_WIN_DIRTY))
                    {
                        UINT32 fl_updated;
                        fl_build_elem_S.client_id  = (UINT32)fl_widget_desc_SP->client_id;
                        #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                        fl_build_elem_S.fb_group_id   = fl_widget_desc_SP->fb_group_id;
                        #endif
                        fl_build_elem_S.fb_target  = GFX_MGR02_TARGET_TRAVEO2;
                        #ifdef LBO_OTF_FEATURE_CC
                        p_win_data_SP->besync_valid = (UINT8)1;
                        #endif
                        if(fl_widget_desc_SP->render_mode == CYGFX_BE_RENDER_MODE_LBO)
                        {
                            fl_build_elem_S.render_mode = CYGFX_BE_RENDER_MODE_LBO; 
                            fl_build_elem_S.wdg_height = fl_widget_desc_SP->wdg_height;
                            IRIS_API_CHECK(ret, CyGfx_BeSetTaskCopses(fl_widget_desc_SP->priority,fl_widget_desc_SP->num_of_cops));
                            #ifdef LBO_OTF_FEATURE_CC
                            if(fl_build_elem_S.wdg_height > (UINT16)0)
                            {
                                /*OTF widget. So, Dirty Area Redraw not applicable for it.*/
                                fl_build_elem_S.dirty_area = FALSE;
                                p_win_data_SP->besync_valid = (UINT8)0;
                            }
                            else
                            #endif
                            {
                                /*Render the content into Frame Buffer Memory*/
                                fl_build_elem_S.dirty_area = TRUE;
                            }
                        }
                        else if(fl_widget_desc_SP->render_mode == CYGFX_BE_RENDER_MODE_MIXED)
                        {
                            fl_build_elem_S.render_mode = CYGFX_BE_RENDER_MODE_MIXED; 
                            fl_build_elem_S.wdg_height = fl_widget_desc_SP->wdg_height;
                            IRIS_API_CHECK(ret, CyGfx_BeSetTaskCopses(fl_widget_desc_SP->priority,fl_widget_desc_SP->num_of_cops));
                            fl_build_elem_S.dirty_area = TRUE;
                        }
                        else
                        {
                            fl_build_elem_S.render_mode = CYGFX_BE_RENDER_MODE_IBO;  
                            fl_build_elem_S.dirty_area = TRUE;
                            fl_build_elem_S.wdg_height = (UINT16)0;
                        }

                        fl_build_elem_S.priority = fl_widget_desc_SP->priority;                
                        #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
    #ifndef LBO_OTF_FEATURE_CC

                        fl_build_elem_S.pe_sync    = l_disp_comp[p_layer_index].gpu_sync;
       
    #else
                        fl_build_elem_S.pe_sync = p_win_data_SP->be_sync;
    #endif                    
                        #endif
                        fl_build_elem_S.clr_buffer = fl_clear_buffer;
                        fl_build_elem_S.clr_color  = fl_clear_color;
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
                        #ifdef LBO_OTF_FEATURE_CC
                        if(fl_build_elem_S.wdg_height > (UINT16)0)
                        {
                            hmi_gfx_mgr02_prepare_otfwindow(p_win_data_SP, &fl_build_elem_S,fl_image_desc_SP,p_layer_index);
                        }
                        #endif
                        #if GFX_MGR02_NUM_MASK_WIDGETS>0
                        if(fl_widget_desc_SP->mask_mode != GFX_MGR02_MASK_WIDGET_DISABLED)
                        {
                            GFX_MGR02_CONTEXT_T * fl_context_sp;
                            GFX_MGR02_ELEM_LIST_T const * fl_mask_content_sp;
                            fl_context_sp = hmi_gfx_mgr02_context_get_ptr();
                            hmi_gfx_mgr02_generic_build_mask_element(fl_context_sp,p_elem_list_SP->child,GFX_MGR02_GENERIC_BUILD,TRUE);
                            fl_build_elem_S.pe_msurf = fl_context_sp->rprop.pe_msurf;
                            fl_build_elem_S.mask_mode = fl_widget_desc_SP->mask_mode;
                            fl_mask_content_sp = p_elem_list_SP->child;
                            fl_mask_content_sp++;
                            /*mask content should be widget otherwise pixel bilt will not happens*/
                            fl_updated = hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, fl_mask_content_sp);
                            hmi_gfx_mgr02_amber_bind_mask_surf(fl_context_sp , NULL);
                        }
                        else
                        #endif
                        {
                            fl_updated = hmi_gfx_mgr02_generic_build_dcu_gen_widget(&fl_build_elem_S, p_elem_list_SP);
                        }
                        if(fl_build_elem_S.wdg_height ==(UINT16)0)
                        {
                            if((fl_updated != FALSE)||( p_win_data_SP->render_buffer != fl_build_elem_S.render_buffer)||(NULL == p_win_data_SP->win))
                            {
                                p_win_data_SP->render_buffer = fl_build_elem_S.render_buffer;
                                IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(p_win_data_SP->surf));
                                #if defined(GFX_MGR02_CLIPPED_WIDGETS) 
                                if((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)||
                                   (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height))
                                {
                                #ifdef GFX02_DEBUG_INFO
                                   printf("Offset=%d, Addr=%X\n",fl_buff_offset,fl_build_elem_S.render_buffer);
                                #endif
                                    fl_buff_offset += (UINT32)fl_build_elem_S.render_buffer;
                                    if(fl_pix_format == CYGFX_SM_FORMAT_A6R6G6B6)
                                    {
                                        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                                                 p_win_data_SP->win_prop.width, 
                                                                                 p_win_data_SP->win_prop.height, 
                                                                                 CYGFX_SM_FORMAT_R8G8B8A8, 
                                                                                 (void *)fl_buff_offset, 
                                                                                 (CYGFX_U32)0));                  
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x18));
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS,  (CYGFX_U32)0x06060606));
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT, (CYGFX_U32)0x120c0600));

                                    }
                                    else
                                    {

                                       IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                                              p_win_data_SP->win_prop.width,
                                                                              p_win_data_SP->win_prop.height,
                                                                              (CYGFX_SM_FORMAT)fl_pix_format,
                                                                              (void *)fl_buff_offset,
                                                                              (CYGFX_U32)0));
                                    }
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_WIDTH, p_win_data_SP->win_prop.width));
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_HEIGHT,p_win_data_SP->win_prop.height));
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_STRIDE,((fl_image_desc_SP->width * fl_bpp)+7UL)>>3U));
                                }
                                else
                                #endif
                                {
                                    if(fl_pix_format == CYGFX_SM_FORMAT_A6R6G6B6)
                                    {
                                        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                                                 p_win_data_SP->win_prop.width, 
                                                                                 p_win_data_SP->win_prop.height, 
                                                                                 CYGFX_SM_FORMAT_R8G8B8A8, 
                                                                                 (void *)fl_build_elem_S.render_buffer,
                                                                                 (CYGFX_U32)0));                  
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x18));
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORBITS,  (CYGFX_U32)0x06060606));
                                        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_COLORSHIFT, (CYGFX_U32)0x120c0600));

                                    }
                                    else
                                    {
                                       IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf, 
                                                                              p_win_data_SP->win_prop.width,
                                                                              p_win_data_SP->win_prop.height,
                                                                             (CYGFX_SM_FORMAT)fl_pix_format,
                                                                             (void *)fl_build_elem_S.render_buffer,
                                                                             (CYGFX_U32)0));
                                    }
                                }
                                hmi_gfx_mgr02_create_window(p_win_data_SP, p_layer_index);
                                hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP, (CYGFX_U32)CYGFX_WIN_BLEND_NONE);
    #ifndef LBO_OTF_FEATURE_CC
                            #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
                            l_disp_comp[p_layer_index].gpusync_flag =(UINT8)1;
                            #endif   
    #endif
                                IRIS_API_CHECK(ret, CyGfx_WinSetSurface(p_win_data_SP->win,(CYGFX_U32)CYGFX_DISP_BUFF_TARGET_COLOR_BUFF, p_win_data_SP->surf));
                                p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                                #ifdef GFX02_DEBUG_INFO
                                printf("Build Widget -- win=%X, Surf=%X\n",p_win_data_SP->win,p_win_data_SP->surf);
                                l_debug_vram_usage = TRUE;
                                #endif
                            }
                            else
                            {
                                if(p_win_data_SP->win != NULL)
                                {
                                    hmi_gfx_mgr02_create_window(p_win_data_SP, p_layer_index);
                                    hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP, (CYGFX_U32)CYGFX_WIN_BLEND_NONE);
                                    IRIS_API_CHECK(ret, CyGfx_WinSetSurface(p_win_data_SP->win, 
                                                                              (CYGFX_U32)CYGFX_DISP_BUFF_TARGET_COLOR_BUFF,
                                                                              p_win_data_SP->surf));
                                    p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                                }
                                GFX_MGR02_UNUSED_VAR(fl_pix_format);
                            }
                        }
                        else
                        {
                            if(fl_updated != FALSE)
                            {
                                p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                            }
                        }
                    }
                    else if((UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id) != FALSE)
                    {
                        /*
                        ** TODO : When the content need not be build, we still have to support
                        **        Widget xy movement & clip movement
                        ** to support clip movement, we have to update the fb pointer
                        ** and stride just like how we did after the build. But here we don't have
                        ** access to the frame buffer pointer. this needs to be fixed later
                        */
                        if(p_win_data_SP->win != NULL)
                        {
                            IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(p_win_data_SP->surf));
                            #if defined(GFX_MGR02_CLIPPED_WIDGETS) 
                            if((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)||
                               (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height))
                            {
                            #ifdef GFX02_DEBUG_INFO
                               printf("Offset=%d, Addr=%X\n", fl_buff_offset, p_win_data_SP->render_buffer);
                            #endif
                               fl_buff_offset += (UINT32)p_win_data_SP->render_buffer;
                               IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf,
                                                                      p_win_data_SP->win_prop.width,
                                                                      p_win_data_SP->win_prop.height,
                                                                      (CYGFX_SM_FORMAT)fl_pix_format,
                                                                      (void *)fl_buff_offset,
                                                                      (CYGFX_U32)0));
                                IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_WIDTH, p_win_data_SP->win_prop.width));
                                IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_HEIGHT, p_win_data_SP->win_prop.height));
                                IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_win_data_SP->surf, CYGFX_SM_ATTR_STRIDE, ((fl_image_desc_SP->width * fl_bpp) + 7UL) >> 3U));
                            }
                            else
                            #endif
                            {
                                IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(p_win_data_SP->surf,
                                                                      p_win_data_SP->win_prop.width,
                                                                      p_win_data_SP->win_prop.height,
                                                                      (CYGFX_SM_FORMAT)fl_pix_format,
                                                                      (void *)p_win_data_SP->render_buffer,
                                                                      (CYGFX_U32)0));
                            }
                            hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
                        }
                    }
                    else
                    {
                        /*Do Nothing.*/
                    }
                }
                
            }
        }
        GFX_MGR02_UNUSED_VAR(ret);
    }
}
#endif /* GFX_MGR02_NUM_OF_SWDGS > 0 */

UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
   return (l_gfx_mgr_shutdown_status);
}

void hmi_gfx_mgr02_emergency_shutdown(void)
{
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_EMERGENCY;
}

void hmi_gfx_mgr02_amber_shutdown(void)
{
    UINT8   fl_cur_window_U8;
    UINT8 fl_display_index_U8;
    SINT32  ret;
#if GFX_MGR02_NUM_LAYERS>1  
    for (fl_display_index_U8 = (UINT8)0; fl_display_index_U8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_display_index_U8++)
#else
    fl_display_index_U8 = (UINT8)0;
#endif
    {
        for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS; fl_cur_window_U8++)
        {
            if(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win != NULL)
            {
                IRIS_API_CHECK(ret, CyGfx_WinDestroy(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win));
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win = NULL;

            }

            if(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf !=NULL)
            {
                IRIS_API_CHECK(ret, utSmDeleteSurfaceObjects((CYGFX_U32)1, &l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf));
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf = NULL;
            }
#ifdef LBO_OTF_FEATURE_CC
            if(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].be_sync !=NULL)
            {
                IRIS_API_CHECK(ret, utSyncDelete((CYGFX_U32)1, &l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].be_sync));
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].be_sync = NULL;
            }
            if(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win_sync !=NULL)
            {
                IRIS_API_CHECK(ret, utSyncDelete((CYGFX_U32)1, &l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win_sync));
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win_sync = NULL;
            }
#endif	    
        }
#ifndef LBO_OTF_FEATURE_CC
        #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
        if(l_disp_comp[fl_display_index_U8].gpu_sync !=NULL)
        {
            IRIS_API_CHECK(ret, utSyncDelete((CYGFX_U32)1, &l_disp_comp[fl_display_index_U8].gpu_sync));
            l_disp_comp[fl_display_index_U8].gpu_sync = NULL;
        }
        #endif
#endif        
        if(l_disp_comp[fl_display_index_U8].disp_sync !=NULL)
        {
            IRIS_API_CHECK(ret, utSyncDelete((CYGFX_U32)1, &l_disp_comp[fl_display_index_U8].disp_sync));
            l_disp_comp[fl_display_index_U8].disp_sync = NULL;
        }
    }
#if GFX_MGR02_NUM_LAYERS>1      
    for (fl_display_index_U8 = (UINT8)0; fl_display_index_U8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_display_index_U8++)
#else
    fl_display_index_U8 = (UINT8)0; 
#endif      
    {
        if (l_disp_comp[fl_display_index_U8].display != NULL)
        {
            IRIS_API_CHECK(ret, CyGfx_DispCloseDisplay(l_disp_comp[fl_display_index_U8].display));
            l_disp_comp[fl_display_index_U8].display = NULL;
        }
        l_disp_comp[fl_display_index_U8].num_of_visible_elements =(UINT8)0;
        l_cur_num_of_elements[fl_display_index_U8] = (UINT8)0;
        l_content_ready_ondisplay =(UINT32)0;
    }
    #if GFX_MGR02_NUM_OF_CLUTS > 0U
    hmi_gfx_mgr02_tv2_free_all_pallettes();
    #endif
    if(NULL != l_memtask0_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_memtask0_ib);
        l_memtask0_ib = NULL;
    }
    if(NULL != l_memtask1_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_memtask1_ib);
        l_memtask1_ib = NULL;
    }
    if(NULL != l_memtask2_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_memtask2_ib);
        l_memtask2_ib = NULL;
    }
#ifdef LBO_OTF_FEATURE_CC    
    if(NULL != l_wintask0_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_wintask0_ib);
        l_wintask0_ib = NULL;
    }
    if(NULL != l_wintask1_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_wintask1_ib);
        l_wintask1_ib = NULL;
    }
    if(NULL != l_wintask2_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_wintask2_ib);
        l_wintask2_ib = NULL;
    }
    if(NULL != l_wintask3_ib)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_wintask3_ib);
        l_wintask3_ib = NULL;
    }
#endif    
    #if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0)|| ((GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))))   
    if(NULL != l_alpha_buffer)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_alpha_buffer);
        l_alpha_buffer = NULL;
    }
    
    hmi_gfx_mgr02_context_free_amber_pathbuffers();
    #endif

    IRIS_API_CHECK(ret, CyGfx_SysDeInitializeDriver());
    GFX_MGR02_UNUSED_VAR(ret);


}
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_driver_status
 ** Visibility:       Local
 ** Description:      This function will be used to find the busy status of the 
 **                   Hardware Drivers(GPU and Window).
 **                   
 ** Invocation:       Internal
 ** Inputs/Outputs:   Driver Busy Status
 ** Critical Section: None.
 **==========================================================================*/
static GFX_MGR02_DRIVER_BUSY_STATUS_T hmi_gfx_mgr02_amber_driver_status(UINT32 p_layer_id_u32)
{
    SINT32 ret;
    GFX_MGR02_DRIVER_BUSY_STATUS_T fl_return_value=GFX_MGR02_DRIVER_FREE;  
#ifndef LBO_OTF_FEATURE_CC
    if(p_layer_id_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        #if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)&& defined(GFX_MGR02_AMBER_USE_MML_PE_SYNC))
        /*Check the pixel engine sync status*/
        ret = CyGfx_SyncWaitSync(l_disp_comp[p_layer_id_u32].gpu_sync, (CYGFX_S32)0);
        if(CYGFX_ERP_ERR_SYNC_TIMEOUT == ret)
        {
          fl_return_value = GFX_MGR02_DRIVER_BUSY_IRIS_ENGINE;
        }
        else
        #endif
        {
          /*Check whether the all active windows are commited?*/
            ret = CyGfx_SyncWaitSync(l_disp_comp[p_layer_id_u32].disp_sync, (CYGFX_S32)0);
            if (CYGFX_ERP_ERR_SYNC_TIMEOUT == ret)
            {
               fl_return_value = GFX_MGR02_DRIVER_BUSY_WINDOW_COMMIT;
            }   
        }
    }
#else
    const GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP;
    UINT8 fl_next_element = (UINT8)0;
    if(p_layer_id_u32 < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        fl_win_data_SP  = &l_disp_comp[p_layer_id_u32].window_data[fl_next_element];
        while(fl_next_element < (UINT8)l_disp_comp[p_layer_id_u32].num_of_visible_elements)
        {
            if(fl_win_data_SP->win != NULL)
            {
                if(fl_win_data_SP->win_sync != NULL)
                {
                    ret=CyGfx_SyncWaitSync(fl_win_data_SP->win_sync,(CYGFX_S32)0);
                    if(ret==CYGFX_ERP_ERR_SYNC_TIMEOUT)
                    {
                        fl_return_value = GFX_MGR02_DRIVER_BUSY_WINDOW_COMMIT;
                        break;
                    }
                }   
            }
            fl_next_element++;
            fl_win_data_SP++;
        }
    }
#endif
    l_gfx_mgr02_amber_driver_status = fl_return_value;
    return(fl_return_value);
}

#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY

UINT32 hmi_gfx_mgr02_get_amber_driver_cur_status(void)
{
    UINT32 fl_amber_driver_status_u32 = (UINT32)FALSE;
    if(l_gfx_mgr02_amber_driver_status != GFX_MGR02_DRIVER_FREE)
    {
        fl_amber_driver_status_u32 = (UINT32)TRUE;
    }
    return (fl_amber_driver_status_u32);
}
#endif

UINT8 hmi_gfx_mgr02_amber_driver_busy(void)
{
    UINT8 fl_layer_index;
    UINT8 fl_result = (UINT8)0;
#if GFX_MGR02_NUM_LAYERS>1 
    for(fl_layer_index = (UINT8)0; fl_layer_index < (UINT8)GFX_MGR02_NUM_LAYERS; fl_layer_index++)
#else
    fl_layer_index = (UINT8)0;
#endif
    {
        if((GFX_MGR02_DRIVER_BUSY_STATUS_T)GFX_MGR02_DRIVER_FREE != hmi_gfx_mgr02_amber_driver_status((UINT32)fl_layer_index))
        {
            fl_result = (UINT8)1;
#if GFX_MGR02_NUM_LAYERS>1          
            break;
#endif          
        }
    }
    return fl_result;
}

void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32)
{
    
    if(p_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS)
    {
      l_disp_comp[p_disp_index_u8].bg_colour = p_bg_color_u32;
    }
}
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0

GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_amber_get_runtime_widget_ptr(UINT16 p_img_id)
{
    GFX_MGR02_IMAGE_DEF_T *fl_return= NULL;
    if(p_img_id < (UINT16)GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS)
    {
        fl_return = &l_runtime_wdg_image_layer_def_S[p_img_id];  
    }
    return(fl_return);
}
#endif

UINT32 hmi_gfx_mgr02_amber_get_disp_content_status(void)
{
    return(l_content_ready_ondisplay);
}
#ifdef LBO_OTF_FEATURE_CC
static void hmi_gfx_mgr02_prepare_otfwindow(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_CONTEXT_GB_T * p_build,GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP,UINT32 p_layer_index)
{
    if((p_win_data_SP->win ==0)||(p_win_data_SP->win != last_otf_window))
    {
        hmi_gfx_mgr02_create_window(p_win_data_SP, p_layer_index);
        hmi_gfx_mgr02_set_blendmode(p_win_data_SP, p_image_desc_SP, (CYGFX_U32)CYGFX_WIN_BLEND_NONE);
    }
    last_otf_window = p_win_data_SP->win;
    p_build->pe_tsurf = p_win_data_SP->surf;
}
void hmi_gfx_mgr02_set_otf_wnd_surf(const GFX_MGR02_CONTEXT_GB_T * p_build)
{
    SINT32 ret = CYGFX_OK;
    IRIS_API_CHECK(ret, CyGfx_WinSetSurface(last_otf_window,(CYGFX_U32)CYGFX_DISP_BUFF_TARGET_COLOR_BUFF, p_build->pe_tsurf));
    GFX_MGR02_UNUSED_VAR(ret);
}

UINT8 hmi_gfx_mgr02_is_otf_win_surface(const CYGFX_SURFACE_OBJECT_S * p_surf)
{
    
    const GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP;
    UINT8 fl_index_u8;
    UINT8 fl_ret_U8 = (UINT8)0;
    fl_win_data_SP = &l_disp_comp[0].window_data[0];
    for(fl_index_u8=(UINT8)0;fl_index_u8<(UINT8)GFX_MGR02_NUM_AMBER_LAYERS;fl_index_u8++)
    {
        if(fl_win_data_SP->surf == p_surf)
        {
            fl_ret_U8=(UINT8)1;
            break;
        }

        fl_win_data_SP++;   
    }
    return fl_ret_U8;    
}
#endif
#if GFX_MGR02_NUM_OF_CLUTS >0U

static void hmi_gfx_mgr02_tv2_free_unused_cluts(void)
{
    GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP =NULL;
    UINT16 fl_clut_id;
    UINT16 fl_sorted_clut_idx_u16a[GFX_MGR02_NUM_AMBER_LAYERS];
    UINT16 fl_unused_clut_idx_u16a[GFX_MGR02_NUM_AMBER_LAYERS];
    UINT8 fl_unused_idx_counter_u8 = 0U; 
        
    /*sort the current palette index array*/
    UINT8 i;
    UINT8 j;
    for (i = 0U; i <(UINT8)GFX_MGR02_NUM_AMBER_LAYERS; i++)
    {
        fl_sorted_clut_idx_u16a[i] = GFX_MGR02_NUM_OF_CLUTS;
        fl_unused_clut_idx_u16a[i] = GFX_MGR02_NUM_OF_CLUTS;
    }
    for (i = 0U; i <(UINT8)GFX_MGR02_NUM_AMBER_LAYERS; i++)
    {
        fl_sorted_clut_idx_u16a[i] = l_curframe_clut_idx_u16a[i];
    }
    for (i = 0U; i <(UINT8)GFX_MGR02_NUM_AMBER_LAYERS; i++)
    {   
        UINT16 temp;
        for (j = i + 1U; j < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS; j++)
        {
            if (fl_sorted_clut_idx_u16a[j] < fl_sorted_clut_idx_u16a[i])
            {
                temp = fl_sorted_clut_idx_u16a[j];
                fl_sorted_clut_idx_u16a[j]=fl_sorted_clut_idx_u16a[i];
                fl_sorted_clut_idx_u16a[i] = temp;
            }
        }
    }
    /*remove dublicates*/
    j=0U;
    for (i=0U; i < ((UINT8)GFX_MGR02_NUM_AMBER_LAYERS - 1U); i++)
    {
        if((fl_sorted_clut_idx_u16a[i] != fl_sorted_clut_idx_u16a[i+1U])&& (fl_sorted_clut_idx_u16a[i] < (UINT16)GFX_MGR02_NUM_OF_CLUTS))
        {
            fl_sorted_clut_idx_u16a[j] = fl_sorted_clut_idx_u16a[i];
            j=j+1U;
        }
    }
    /*findout the unused clut*/
    for (i = 0U; i <(UINT8)GFX_MGR02_NUM_AMBER_LAYERS; i++)
    {
        UINT16 present = 0U;
        for (j = 0U; j <(UINT8)GFX_MGR02_NUM_AMBER_LAYERS; j++)
        {
            
            if (l_last_frame_clut_idx_u16a[i] != (UINT16)GFX_MGR02_NUM_OF_CLUTS)
            {
                if (l_last_frame_clut_idx_u16a[i] == fl_sorted_clut_idx_u16a[j])
                {
                    /*If the clut idx in l_last_frame_clut_idx_u16a[] is matches with fl_sorted_clut_idx_u16a, skip this member and check for another one.*/
                    present = 1U;
                    break;
                }				
            }
        }
        if ((present ==0U) && (l_last_frame_clut_idx_u16a[i] != (UINT16)GFX_MGR02_NUM_OF_CLUTS))
        {
            fl_unused_clut_idx_u16a[fl_unused_idx_counter_u8] = l_last_frame_clut_idx_u16a[i];
            fl_unused_idx_counter_u8 = fl_unused_idx_counter_u8+1U;
        }
    }
    /*remove the unused palettes.*/
    for(; fl_unused_idx_counter_u8>0U; fl_unused_idx_counter_u8--)
    {
        fl_clut_id = fl_unused_clut_idx_u16a[fl_unused_idx_counter_u8-1U];
        if(fl_clut_id < (UINT16)GFX_MGR02_NUM_OF_CLUTS)
        {
            fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_clut_id];
            hmi_gfx_mgr02_tv2_remove_clut(CYGFX_PALETTE_REGION_DISPLAY,(const void *)fl_elem_clut_SP->CLUT);
        }

    }   
}
#endif
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
void hmi_gfx_mgr02_tv2_set_display_property(CYGFX_DISP_ATTR p_attr_name, CYGFX_U32 p_val)
{
    UINT8 fl_disp_index_u8;
    if (p_attr_name == CYGFX_DISP_ATTR_IN_CTRL)
    {
#if GFX_MGR02_NUM_LAYERS > 1
        for (fl_disp_index_u8 = (UINT8)0; fl_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_disp_index_u8++)
#else
        fl_disp_index_u8 = (UINT8)0;
#endif
        {
            l_disp_comp[fl_disp_index_u8].input_control = p_val;
        }
    }
}
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
 **============================================================================*/
 
#ifdef  __cplusplus
}
#endif
#endif

