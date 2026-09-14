/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2014. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_amber.c
 **
 ** Description:    Amber gfx manager module for its driver
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define GUI_GFX_MANAGER_AMBER_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"


#ifdef GFX_MGR02_AMBER
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_amber.h"
#include "hmi_gfx_mgr02_amber_iris.h"

#include "ut_compatibility.h"

#ifdef GFX02_DEBUG_INFO
#include "mml_gdc_erp.h"
#endif

#include "hmi_gfx_mgr02_clut_table.h"
#include "panel_definition.h"
#if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED)
#include "hmi_gfx_mgr02_warp_tables.cfg"
#endif /* #if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_LAYER_WARPING_ENABLED) */ 
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
#include GFX_MGR02_3D_MDL_INCLUDE_H
#endif
#ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
#include "hmi_gfx_mgr02_capture_video.h"
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
#define GFX_MGR02_INVALID_LAYER             (MML_GDC_DISP_LAYER_4 + 1UL)


#define GFX_MGR02_IS_MULTI_LAYER(feature) (((feature) & MML_GDC_DISP_FEATURE_MULTI_LAYER) != 0)

#define GFX_MGR02_ELEMENT_VISIBLE      ((UINT32)2)
#define GFX_MGR02_ELEMENT_INVISIBLE    ((UINT32)1)
#define GFX_MGR02_ELEMENT_INVALID      ((UINT32)0)

/*Iris Driver Not Supports the 2BPP, 4BPP and ARGB6666 . So this is temp implementation for now.*/
#ifndef MML_GDC_SURF_FORMAT_RGB4
#define MML_GDC_SURF_FORMAT_RGB4 (MM_U08)27
#endif
#ifndef MML_GDC_SURF_FORMAT_RGB2
#define MML_GDC_SURF_FORMAT_RGB2 (MM_U08)28
#endif
#ifndef	GFX_MGR02_AMBER_IS_TCFLASH
#define GFX_MGR02_AMBER_IS_TCFLASH(addr)    (((UINT32)(addr)) < 0x02000000UL)
#endif
#ifndef GFX_MGR02_AMBER_REMAP_TCFLASH
#define GFX_MGR02_AMBER_REMAP_TCFLASH(addr) (((UINT8*)(addr)) + 0x04000000UL)
#endif
/*
Macros for commiting only the the windows which needs updated.
*/
#define GFX_MGR02_AMBER_WIN_DIRTY    ((UINT8)0x00)		/*If the window attributes changed*/
#define GFX_MGR02_AMBER_WIN_UPDATED  ((UINT8)0x01)		/*If the window atrributes are updated and not committed to display.*/
#define GFX_MGR02_AMBER_WIN_COMMITED ((UINT8)0x02)		/*After commiting the window for display.*/

/* Defines the data required for managing a single window */
typedef struct
{
    /*
    ** MML handles for the window & its surface
    */
    MML_GDC_DISP_WINDOW            win;
    MML_GDC_DISP_WINDOW_PROPERTIES win_prop;
    MML_GDC_SURFACE                surf;
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
  MML_GDC_DISPLAY             display;		                               /*Display Handle*/
  UINT32                      bg_colour;								   /*Display BG Colour*/
  GFX_MGR02_WINDOW_DATA_T     window_data[GFX_MGR02_NUM_AMBER_LAYERS];     /*Windows associated with Display*/
  #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
  MML_GDC_SYNC                gpu_sync;									   /*Sync for knowing the GPU finished rendering or Not*/
  #endif
  MML_GDC_SYNC                disp_sync;									   /*Sync for knowing the Display finished Commiting or Not*/
  UINT8                       num_of_visible_elements;                     /*Number of active elements in the Display. */
  UINT8                       num_of_planes_used;                          /*Number of planes used. This is needed to restrict planes per Disp controller.*/
  #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
  UINT8                       gpusync_flag;								   /*It will hold Boolean value to check whether the GPU sync is inserted or not for frame.*/
  #endif
}GFX_MGR02_DISPLAY_DATA_T;
/*Recommended Window creation Order*/
#if GFX_MGR02_NUM_LAYERS>1 
static const UINT32 lc_amber_window_creation_order[GFX_MGR02_NUM_OF_PLANES] =
{
   MML_GDC_DISP_FEATURE_DECODE | MML_GDC_DISP_FEATURE_INDEX_COLOR,
   MML_GDC_DISP_FEATURE_DECODE |MML_GDC_DISP_FEATURE_CAPTURE,
   MML_GDC_DISP_FEATURE_MULTI_LAYER|MML_GDC_DISP_FEATURE_WARP,
   MML_GDC_DISP_FEATURE_MULTI_LAYER |MML_GDC_DISP_FEATURE_INDEX_COLOR,
   MML_GDC_DISP_FEATURE_MULTI_LAYER |MML_GDC_DISP_FEATURE_INDEX_COLOR
};
#endif
/*Hardware Driver Busy Status*/
/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index);
static void hmi_gfx_mgr02_create_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index);
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index);
static void hmi_gfx_mgr02_manage_layers_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,\
                                                 UINT32 p_layer_index,
                                                 UINT32 p_multi_layer);
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area,\
                                                           UINT32 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP);
#if (GFX_MGR02_NUM_OF_SWDGS > 0)
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                  GFX_MGR02_ELEMENT_AREA * p_elem_area);
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
static void hmi_gfx_mgr02_build_widget(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index);
#endif
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)
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
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0) /*sbollam*/
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
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
static void hmi_gfx_mgr02_set_blendmode(GFX_MGR02_WINDOW_DATA_T const * p_wind, GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP, UINT32 p_blend_mode);
#endif
static GFX_MGR02_DRIVER_BUSY_STATUS_T hmi_gfx_mgr02_amber_driver_status(UINT32 p_layer_ID_U8);
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

static  void*                   l_vInstrBuffer = NULL;
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0)|| (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2) || ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))))
static  void*                   l_alpha_buffer =NULL;
#endif

static  volatile UINT8          l_gfx_mgr_shutdown_status;
static  GFX_MGR02_ANIM_DATA_T * l_layer_anim_data_SP;

static  UINT8                   l_cur_num_of_elements[GFX_MGR02_NUM_LAYERS];
static  MML_GDC_DISP_LAYER      l_cur_free_layer;
#ifdef GFX02_DEBUG_INFO
 static UINT32                  l_tot_num_of_elements;
 static UINT32                  l_debug_vram_usage;
#endif
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T l_fractional_plane_data[GFX_MGR02_NUM_OF_FRACTIONAL_PLANES];
#ifdef GFX_MGR02_LAYER_WARPING_ENABLED
static GFX_MGR02_FRACTIONAL_PLANE_DATA_T l_warp_plane_data; /* there is only one warp plane */
#endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
static GFX_MGR02_IMAGE_DEF_T l_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif

static UINT8 l_cur_fractional_plane =0;
static UINT8 l_prev_fractional_plane =0;

static 	GFX_MGR02_DISPLAY_DATA_T l_disp_comp[GFX_MGR02_NUM_LAYERS];
static  GFX_MGR02_DRIVER_BUSY_STATUS_T l_gfx_mgr02_amber_driver_status = GFX_MGR02_DRIVER_FREE;
static  UINT8 l_gfx_mgr02_amber_element_dirty_u8 =(UINT8)0;
static  UINT8 l_gfx_mgr02_amber_dwdg_dirty_u8 =0;
static GFX_MGR02_ELEM_LIST_T const *l_root_elem_list_SP=NULL;
static UINT32 l_content_ready_ondisplay =(UINT32)0;
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

/****************************************************************************
Function Name        : hmi_gfx_mgr02_initialize
Description          : Initializes the Iris Driver and internal variables.
Invocation           : Invoked by manager
Parameters           : None
Return Value         : None
Critical Section     : None
External Interfaces  : None
** Created:          21-Aug-2014 by NKRISHN9
** Updated:          21-Aug-2014 by NKRISHN9
******************************************************************************/
void hmi_gfx_mgr02_initialize(void)
{
   MML_GDC_SYSINIT_INFO fl_sys_init = GFX_MGR02_CUSTOM_GDC_SYSINIT_INITIALIZER;
    GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP;
   MM_S32  ret;
    UINT8   fl_disp_index_u8;
    UINT8   fl_index_u8;
    UINT8   fl_no_planes_u8=(UINT8)GFX_MGR02_NUM_OF_PLANES;
    IrisMemInfo fl_memory_s;

    l_gfx_mgr02_amber_driver_status = GFX_MGR02_DRIVER_FREE;
    l_content_ready_ondisplay =(UINT32)0;
    l_vInstrBuffer = NULL;
    
   l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_NORMAL;
   l_layer_anim_data_SP      = hmi_gfx_mgr02_layout_get_anim_data();
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
   (void)memcpy((void *)&l_runtime_wdg_image_layer_def_S[0], 
          (const void *)&lc_runtime_wdg_image_layer_def_S[0], 
          sizeof(l_runtime_wdg_image_layer_def_S));
#endif

   IRIS_API_CHECK(ret, mmlGdcSysInitializeDriver(&fl_sys_init));
   (void)hmi_gfx_mgr02_amber_mem_mgmt_init();
#ifdef GFX02_DEBUG_INFO
   mmlGdcErpSetPrintf(stdout_printf);
#endif
    fl_memory_s.MemCateg = IRIS_PE_INSTRUCTION_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU; /*Not applicable for Instruction Buffer*/
    fl_memory_s.Alignment = (UINT32)32; /*32 Byte alignement*/
    fl_memory_s.Size = (UINT32)GFX_MGR02_IRIS_INSTR_BUFF_SIZE;
    fl_memory_s.ExtMemory = (UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    l_vInstrBuffer = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
   IRIS_API_CHECK(ret, mmlGdcSysSetInstructionBuffer(l_vInstrBuffer, (UINT32)GFX_MGR02_IRIS_INSTR_BUFF_SIZE));
#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0)|| (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2) || ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))))

    fl_memory_s.MemCateg = IRIS_DE_ALPHA_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU; /*Not applicable for Instruction Buffer*/
    fl_memory_s.Alignment = (UINT32)4; /*4 Byte alignement*/
    fl_memory_s.Size = (UINT32)GFX_MGR02_DE_ALPHABUF_SIZE;
    fl_memory_s.ExtMemory =(UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    l_alpha_buffer =  hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
    if(l_alpha_buffer!=NULL)
    {     
       IRIS_API_CHECK(ret, mmlGdcDeSetAlphaBuffer((UINT32)GFX_MGR02_DE_AREA_WIDTH,(UINT32)GFX_MGR02_DE_AREA_HEIGHT,(UINT32)8, l_alpha_buffer, (UINT32)GFX_MGR02_DE_ALPHABUF_SIZE));
    }
#endif
#if GFX_MGR02_NUM_LAYERS>1 
    for (fl_disp_index_u8 = (UINT8)0; fl_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_disp_index_u8++)
#else  
    fl_disp_index_u8 = (UINT8)0;
#endif     
    {
      l_disp_comp[fl_disp_index_u8].num_of_visible_elements =(UINT8)0;
      l_disp_comp[fl_disp_index_u8].bg_colour     = lc_amber_disp_bg_colour_u32a[fl_disp_index_u8];
	  #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
	  l_disp_comp[fl_disp_index_u8].gpusync_flag =(UINT8)0;
      IRIS_API_CHECK(ret, mmlGdcSyncCreate((MM_U32)1, &l_disp_comp[fl_disp_index_u8].gpu_sync));
	  #endif

    #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_DISPLAY_MODE)
    {
      GFX_MGR02_CAPTURE_INIT_STATUS fl_status; 
      fl_status = hmi_gfx_mgr02_capture_to_display_init();
      if(fl_status == GFX_MGR02_CAPTURE_INIT_SUCCESS)
      {
        l_disp_timing.capCtx = *(hmi_gfx_mgr02_get_capture_context());
      }
    }
    #endif

	  IRIS_API_CHECK(ret, mmlGdcSyncCreate((MM_U32)1, &l_disp_comp[fl_disp_index_u8].disp_sync));
      IRIS_API_CHECK(ret, mmlGdcDispOpenDisplay((MML_GDC_DISP_PROPERTIES *)&l_mml_gdc_dispParams[fl_disp_index_u8],
                                                                         &l_disp_comp[fl_disp_index_u8].display));
      if(ret !=	MML_OK)
      {
        #ifdef GFX02_DEBUG_INFO
        printf("Display Open Failed Err Code: %x.\n",ret);
        #endif
      }

      #ifdef GFX_MGR02_ENABLE_HW_DITHERING
        #if GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB666
        IRIS_API_CHECK(ret, mmlGdcDispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  MML_GDC_DISP_DITHON,
                                                  MML_GDC_DISP_TEMPDITH,
                                                  MML_GDC_DISP_DITHRS11LOW,
                                                  MML_GDC_DISP_DITHER106));
        #elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB565
        IRIS_API_CHECK(ret, mmlGdcDispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  MML_GDC_DISP_DITHON,
                                                  MML_GDC_DISP_TEMPDITH,
                                                  MML_GDC_DISP_DITHRS11LOW,
                                                  MML_GDC_DISP_DITHER105));
        #elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB888
        IRIS_API_CHECK(ret, mmlGdcDispDitherCtrl(l_disp_comp[fl_disp_index_u8].display,
                                                  MML_GDC_DISP_DITHON,
                                                  MML_GDC_DISP_TEMPDITH,
                                                  MML_GDC_DISP_DITHRS11LOW,
                                                  MML_GDC_DISP_DITHER108));
        #endif
      #endif
      IRIS_API_CHECK(ret, mmlGdcDispSetAttribute(l_disp_comp[fl_disp_index_u8].display,MML_GDC_DISP_ATTR_BACKGROUND_COLOR,l_disp_comp[fl_disp_index_u8].bg_colour)); 
      IRIS_API_CHECK(ret, mmlGdcDispSetAttribute(l_disp_comp[fl_disp_index_u8].display,MML_GDC_DISP_ATTR_INCLUDE_WIN_COMMIT,(MM_U32)MM_TRUE));

     #ifdef GFX_MGR02_IRIS_GAMMA_CORRECTION
	  if((GFX_MGR02_IRIS_GAMMA_RED_CLUT != NULL) && (GFX_MGR02_IRIS_GAMMA_GREEN_CLUT != NULL) && (GFX_MGR02_IRIS_GAMMA_BLUE_CLUT != NULL))
	  {
	    IRIS_API_CHECK(ret, mmlGdcDispCLUTData(l_disp_comp[fl_disp_index_u8].display,
                                               MML_GDC_DISP_CLUT_FORMAT_33,
                                               GFX_MGR02_IRIS_GAMMA_RED_CLUT,
                                               GFX_MGR02_IRIS_GAMMA_GREEN_CLUT,
                                               GFX_MGR02_IRIS_GAMMA_BLUE_CLUT));
      }  
	 #endif
      IRIS_API_CHECK(ret, mmlGdcDispCommit(l_disp_comp[fl_disp_index_u8].display));
      l_content_ready_ondisplay =(UINT32)1;
      fl_index_u8=(UINT8)0;
      fl_win_data_SP = &l_disp_comp[fl_disp_index_u8].window_data[0];
      while(fl_index_u8<(UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
      {
        fl_win_data_SP->next_elem_sp = NULL;
        fl_win_data_SP->curr_elem_sp = NULL;
        fl_win_data_SP->root_elem_sp = NULL;
        IRIS_API_CHECK(ret, mmlGdcSmGenSurfaceObjects((MM_U32)1, &fl_win_data_SP->surf));
        fl_win_data_SP->win_prop.sub_layerId  = MML_GDC_DISP_SUB_LAYER_DEFAULT;
        fl_win_data_SP->win_prop.outputScreen = MML_GDC_DISP_OUTPUT_SCREEN_PRIMARY;
        fl_win_data_SP->win = NULL;
        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
        fl_win_data_SP->win_colour = 0UL;
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
        fl_win_data_SP->win_prop.layerId  = ((MML_GDC_DISP_LAYER)(fl_no_planes_u8-0x01u));
        fl_win_data_SP->win_prop.topLeftX = (MM_U32)0;		 
        fl_win_data_SP->win_prop.topLeftY = (MM_U32)0;
        fl_win_data_SP->win_prop.width    = l_mml_gdc_dispParams[fl_disp_index_u8].xResolution;
        fl_win_data_SP->win_prop.height   = l_mml_gdc_dispParams[fl_disp_index_u8].yResolution;
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
        if((lc_amber_window_creation_order[fl_counter_u8]==fl_win_data_SP->win_prop.features)&&
           (fl_win_data_SP->win==0))
        {
          IRIS_API_CHECK(ret, mmlGdcDispWinCreate(l_disp_comp[1].display,
                                                &fl_win_data_SP->win_prop,
                                                &fl_win_data_SP->win));
          
          if(ret!=MML_OK)
          {
              #ifdef GFX02_DEBUG_INFO
              printf("Window Creation Failed %x\n",ret);
              #endif
          }
          
        }
        
      }
      fl_win_data_SP++;
    }
    #endif
   #if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
   GFX_MGR02_3D_MDL_INITIALIZE;
   #endif
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_build_screen
Description          : Builds the screens that are active.
Invocation           : Invoked by manager
Parameters           : p_layer_ID_U8
Return Value         : None
Critical Section     : None
External Interfaces  : None
** Created:          21-Aug-2014 by NKRISHN9
** Updated:          21-Aug-2014 by NKRISHN9
******************************************************************************/
void hmi_gfx_mgr02_build_screen(UINT32 p_layer_ID_U32)
{
   UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
   
#ifdef GFX02_DEBUG_INFO
   MM_U32 fl_size1 = 0;
   MM_U32 fl_size2 = 0;

   l_debug_vram_usage = FALSE;
#endif
   UINT8 i;
   
   if ((p_layer_ID_U32 < (UINT32)GFX_MGR02_NUM_LAYERS) && (fl_shutdown_state != GFX_MGR02_SHUTDOWN_EMERGENCY))
   {
     
      #if GFX_MGR02_NUM_LAYERS >1
      if (p_layer_ID_U32 == (UINT32)0)
	  #endif	  
      {
          for(i= (UINT8)0; i< GFX_MGR02_NUM_OF_FRACTIONAL_PLANES; i++)
          {
             l_fractional_plane_data[i].fp_layer_id             = 	GFX_MGR02_INVALID_LAYER;
             l_fractional_plane_data[i].fp_no_of_sub_layer_used =  (UINT32)0;
          }
          l_cur_fractional_plane =(UINT8)0;
          l_prev_fractional_plane =(UINT8)0;
          #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
          l_warp_plane_data.fp_layer_id = GFX_MGR02_INVALID_LAYER;
          l_warp_plane_data.fp_no_of_sub_layer_used = 0;
          #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
      }
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
#ifdef GFX02_DEBUG_INFO
   if(l_debug_vram_usage != FALSE)
   {
      mmlGdcVideoGetSize(&fl_size1);
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
      mmlGdcVideoGetFreeTotal(&fl_size2);
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
      mmlGdcVideoGetLargestBlock(&fl_size1);
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

   #ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
   #if((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
   {
      UINT8 fl_status = hmi_gfx_mgr02_capture_video_get_status();
	  if(fl_status == FALSE)
	  {
          hmi_gfx_mgr02_capture_video_shutdown();
	  }
   }
   #endif
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers(UINT32 p_layer_index)
{
   UINT32                  fl_max_priority;
   GFX_MGR02_SCREEN_ID_T const * fl_cur_screen;
   UINT32                  fl_cur_screen_id;

   if (p_layer_index < (UINT32)GFX_MGR02_NUM_LAYERS)
   {
      #ifdef GFX_MGR02_CAPTURE_VIDEO_ENABLED
      #if((GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE) || (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE))
      {
        hmi_gfx_mgr02_capture_video_set_status(FALSE);
      }
      #endif
      #endif

       fl_max_priority = lc_layer_def_S[p_layer_index].nb_priority;
       fl_cur_screen   = lc_layer_def_S[p_layer_index].prio_stack;
       l_disp_comp[p_layer_index].num_of_visible_elements=(UINT8)0;
       l_disp_comp[p_layer_index].num_of_planes_used=(UINT8)0;
       l_gfx_mgr02_amber_element_dirty_u8 =(UINT8)0;
       #if GFX_MGR02_NUM_LAYERS >1
	   if (p_layer_index > 0)
       {
         l_cur_free_layer  = (MML_GDC_DISP_LAYER)(MML_GDC_DISP_LAYER_4 - lc_amber_num_planes_u8a[0]);       
       }
       else
       #endif 	   		   
       {
	     l_cur_free_layer   = MML_GDC_DISP_LAYER_4;
       }
    #ifdef GFX02_DEBUG_INFO
       l_tot_num_of_elements = 0;
    #endif

       while(fl_max_priority > 0UL)
       {
          fl_max_priority--;
          fl_cur_screen_id = fl_cur_screen[fl_max_priority];
          if(fl_cur_screen_id < (UINT32)GFX_MGR02_NUM_OF_SCREENS)
          {
             hmi_gfx_mgr02_manage_layers_cp_childrens(fl_cur_screen_id, p_layer_index);
          }
       }
       hmi_gfx_mgr02_manage_widget_memory();
    #ifdef GFX02_DEBUG_INFO
       printf("INFO - Windows Needed    = %d\n", l_tot_num_of_elements);
       printf("INFO - Allocated windows = %d\n", l_disp_comp[p_layer_index].num_of_visible_elements);
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_manage_layers_cp_childrens(UINT32 p_screen_id, UINT32 p_layer_index)
{
   GFX_MGR02_SCREEN_DEF_T const * fl_screen_def_SP = &lc_screen_def_S[p_screen_id];
   GFX_MGR02_ELEM_LIST_T  const * fl_elem_list_SP;
   UINT32                         fl_num_of_elem;
   GFX_MGR02_ANIM_DATA_T  const      * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
    
   (void)hmi_gfx_mgr02_context_begin_update(p_layer_index, &lc_layer_def_S[p_layer_index], FALSE);
   hmi_gfx_mgr02_context_reset_state();
   hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_anim_prop_SP->layer_alpha[p_layer_index]);
   hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_anim_prop_SP->layer_loc[p_layer_index]);

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
      fl_elem_list_SP = &fl_screen_def_SP->child[fl_num_of_elem-0x01u];
      while(fl_num_of_elem > (UINT32)0)
      {
         fl_num_of_elem--;
         if(l_disp_comp[p_layer_index].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
         {
              l_disp_comp[p_layer_index].window_data[l_disp_comp[p_layer_index].num_of_visible_elements].root_elem_sp = fl_elem_list_SP;
         }
         l_gfx_mgr02_amber_element_dirty_u8=(UINT8)0;
         l_gfx_mgr02_amber_dwdg_dirty_u8=(UINT8)0;
         l_root_elem_list_SP = NULL;
         hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP, p_layer_index, FALSE);
         if(fl_num_of_elem != (UINT32)0)
         {
            fl_elem_list_SP = &fl_elem_list_SP[-1];
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static void hmi_gfx_mgr02_manage_layers_cp_child(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, 
                                                 UINT32                        p_layer_index,
                                                 UINT32                        p_multi_layer)
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
    UINT32                         fl_win_features = 0;
	UINT32                         fl_element_valid = FALSE; 
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER) || defined(GFX_MGR02_LAYER_WARPING_ENABLED)	
	MML_GDC_DISP_LAYER                         fl_prev_num_of_layers = MML_GDC_DISP_LAYER_4;
#endif	
#ifdef GFX_MGR02_LAYER_WARPING_ENABLED
    GFX_MGR02_LAYER_DEF_T const* fl_layer_desc_SP;
#endif
    
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
                hmi_gfx_mgr02_manage_layers_cp_child(p_elem_list_SP, p_layer_index, p_multi_layer);
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
                  fl_num_of_elem  = p_elem_list_SP->num_child_elements;
                  if(fl_num_of_elem > (UINT32)0)
                  {
                     if((fl_widget_desc_SP->merge == (UINT8)0) && (p_multi_layer == FALSE))
                     {
                        l_cur_fractional_plane+= 0x01U; 
                     } 
                     fl_elem_list_SP = &p_elem_list_SP->child[fl_num_of_elem- 0x01u];
                     while(fl_num_of_elem > (UINT32)0)
                     {
                        fl_num_of_elem--;
                        if(l_disp_comp[p_layer_index].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
                        {
                             l_disp_comp[p_layer_index].window_data[l_disp_comp[p_layer_index].num_of_visible_elements].root_elem_sp =  p_elem_list_SP;
                        }
                        hmi_gfx_mgr02_manage_layers_cp_child(fl_elem_list_SP, p_layer_index, TRUE);
                        fl_elem_list_SP = &fl_elem_list_SP[-1];
                     }
                  }
                  fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
				  fl_element_valid = FALSE;
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
                       hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index);
                   #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0
                       if(fl_widget_desc_SP->rr_engine == GFX_MGR02_RT_DEFAULT)
                       {
                          hmi_gfx_mgr02_context_widget_set_active(fl_widget_desc_SP->client_id);
                       }
#endif
#if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
                       fl_image_desc_SP = &lc_image_layer_def_S[fl_widget_desc_SP->image_id];
			           if(hmi_gfx_mgr02_is_image_transparent(fl_image_desc_SP->format) == TRUE)
                       {
                         fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                       }
                       else 
                       {
                         fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                       }
#endif
                   }
#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
                   /* widgets with their own warping should not use the warping plane */
                   if(fl_widget_desc_SP->warp_id == GFX_MGR02_INVALID_WARP)
               #endif /* #ifdef GFX_MGR02_WIDGET_WARPING_ENABLED */
                   {
                    #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                       fl_layer_desc_SP = &lc_layer_def_S[p_layer_index];
                       if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
                       {
                           /* current layer should be warped, so we request the widget to be assigned for warping plane */
                           fl_win_features = MML_GDC_DISP_FEATURE_WARP;
                       }
                    #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */

                   }
                   if(hmi_gfx_mgr02_amber_get_wdg_pix_format(fl_widget_desc_SP->fb_format) == MML_GDC_SURF_FORMAT_YVYU422)
                   {
                   /*YUV format can't be combined with Warp*/
                        fl_win_features = MML_GDC_DISP_FEATURE_YUV1BUFF;
                   }
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
           GFX_MGR02_IMAGE_DEF_T const * fl_image_desc_SP = &lc_image_layer_def_S[fl_base_id];
           fl_vaof_index = hmi_gfx_mgr02_get_image_layer_area(p_elem_list_SP, &fl_elem_area);
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, fl_vaof_index, TRUE, p_layer_index);
        #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
           fl_layer_desc_SP = &lc_layer_def_S[p_layer_index];
           if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
           {
               /* current layer should be warped, so we request the image to be assigned for warping plane */

               /* Note that if the image is compressed this flag will be replaced, but its OK, because warp plane
                * does not support decoding anyway, so the problem will be in the design
                */
               fl_win_features = MML_GDC_DISP_FEATURE_WARP;
           }
        #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
        #if defined(GFX_MGR02_COMPRESSION_ENABLED)
           if(p_multi_layer == FALSE)
           {
              if(fl_image_desc_SP->comp_size != (UINT32)0)
              {
                 fl_win_features |= MML_GDC_DISP_FEATURE_DECODE;
              }
           }
        #endif
           if((fl_image_desc_SP->format == MML_GDC_SURF_FORMAT_A8RGB8 )||
                 (fl_image_desc_SP->format == MML_GDC_SURF_FORMAT_RGB8 )||
                 (fl_image_desc_SP->format == MML_GDC_SURF_FORMAT_RGB4 )||
                 (fl_image_desc_SP->format == MML_GDC_SURF_FORMAT_RGB2 )||
                 (fl_image_desc_SP->format == MML_GDC_SURF_FORMAT_RGB1 ))
           {	
                 fl_win_features |= MML_GDC_DISP_FEATURE_INDEX_COLOR;
           }
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
        break;
    #endif
    #if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
        case GFX_MGR02_TYPE_STEXT:
        case GFX_MGR02_TYPE_DTEXT:
        {
        #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
           fl_layer_desc_SP = &lc_layer_def_S[p_layer_index];
           if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
           {
               /* current layer should be warped, so we request the text to be assigned for warping plane */
               fl_win_features = MML_GDC_DISP_FEATURE_WARP;
           }
        #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
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
           fl_layer_desc_SP = &lc_layer_def_S[p_layer_index];
           if(fl_layer_desc_SP->warp_id != GFX_MGR02_INVALID_WARP)
           {
               /* current layer should be warped, so we request the "fill" to be assigned for warping plane */
               fl_win_features = MML_GDC_DISP_FEATURE_WARP;
           }
        #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
           hmi_gfx_mgr02_get_tile_fill_layer_area(p_elem_list_SP, &fl_elem_area);
           fl_elem_area.alpha = fl_context_SP->state.alpha;
           fl_elem_area.sx    = fl_context_SP->state.loc.x;
           fl_elem_area.sy    = fl_context_SP->state.loc.y;
           hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
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
            if (fl_elem_list_SP->base_id < (UINT32)GFX_MGR02_NUM_USER_LAYERS)
            {
              /* Get the element area of the user_image element */
              GFX_MGR02_IMAGE_DEF_T * fl_image_def_SP = &l_layer_anim_data_SP->user_image_layer[fl_elem_list_SP->base_id];
              (void)hmi_gfx_mgr02_load_user_layer_def_info(fl_elem_list_SP->base_id, fl_image_def_SP);
              if((fl_image_def_SP->pixel_data != GFX_MGR02_NULL_PTR) && 
                 (fl_image_def_SP->height     != (UINT16)0)        && 
                 (fl_image_def_SP->width      != (UINT16)0))
              {
                (void)hmi_gfx_mgr02_get_image_layer_area(fl_elem_list_SP, &fl_elem_area);
                fl_elem_area.alpha = fl_context_SP->state.alpha;
                fl_elem_area.sx    = fl_context_SP->state.loc.x;
                fl_elem_area.sy    = fl_context_SP->state.loc.y;
                hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
                if(hmi_gfx_mgr02_is_image_transparent(fl_image_def_SP->format) == TRUE)
                {
                  fl_elem_area.is_transparent = (UINT8)GFX_MGR02_TRANSPARENT;
                }
                else
                {
                  fl_elem_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
                }
                fl_element_valid   = TRUE;
              }
              
              if(l_gfx_mgr02_amber_element_dirty_u8 ==(UINT8)0)
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
            fl_win_features       = MML_GDC_DISP_FEATURE_CAPTURE;
            hmi_gfx_mgr02_get_video_layer_area(p_elem_list_SP, &fl_elem_area);
            hmi_gfx_mgr02_layout_validate_layer_area(&fl_elem_area, GFX_MGR02_INVALID_ID, TRUE, p_layer_index);
            l_gfx_mgr02_amber_element_dirty_u8 = TRUE;
        }
        break;
    #endif

    #if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
        case GFX_MGR02_TYPE_3D_MDL:
        {
            /* Get the element area of the user_image element */
            GFX_MGR02_IMAGE_DEF_T * fl_image_def_SP = &l_layer_anim_data_SP->mdl_3d_layer[p_elem_list_SP->base_id];
            hmi_gfx_mgr02_load_mdl_3d_layer_def_info(p_elem_list_SP->base_id, fl_image_def_SP);
            fl_vaof_index               =   hmi_gfx_mgr02_get_image_layer_area(p_elem_list_SP, &fl_elem_area);
            fl_elem_area.alpha          =   fl_context_SP->state.alpha;
            fl_elem_area.sx             =   fl_context_SP->state.loc.x;
            fl_elem_area.sy             =   fl_context_SP->state.loc.y;
 		    fl_elem_area.is_transparent =   (UINT8)GFX_MGR02_TRANSPARENT;
  	        fl_element_valid            =   TRUE;
		    fl_win_features             =   (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT;
			if(l_gfx_mgr02_amber_element_dirty_u8 ==(UINT8)0)
            {
             l_gfx_mgr02_amber_element_dirty_u8 = (UINT8)hmi_gfx_mgr02_layout_is_element_changed((UINT32)p_elem_list_SP->base_id, p_elem_list_SP->obj_id);
            }
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
       UINT32                    fl_cur_layer_index = l_disp_comp[p_layer_index].num_of_visible_elements;
       GFX_MGR02_WINDOW_DATA_T * fl_win_data_SP     = &l_disp_comp[p_layer_index].window_data[fl_cur_layer_index];
       UINT8 fl_sublayer_available;
       {
           if(hmi_gfx_mgr02_manage_layers_is_child_visible(&fl_elem_area, 
                                                           l_disp_comp[p_layer_index].num_of_visible_elements, 
                                                           &l_disp_comp[p_layer_index].window_data[0]) == GFX_MGR02_ELEMENT_VISIBLE)
           {
              /* 
              ** The below element win_prop area includes vaoa index i.e. opaque area to be considered 
              ** fl_elem_area_SP-> is the actual position of the element 
              */
              if(fl_win_data_SP->win_prop.topLeftX != (MM_U32)fl_elem_area.sx)
              {
                fl_win_data_SP->win_prop.topLeftX =(MM_U32) fl_elem_area.sx;
                fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
              }
              if(fl_win_data_SP->win_prop.topLeftY != (MM_U32)fl_elem_area.sy)
              {
                fl_win_data_SP->win_prop.topLeftY = (MM_U32)fl_elem_area.sy; 
                fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
              }
              if(fl_win_data_SP->win_prop.width != ((MM_U32)fl_elem_area.ex- (MM_U32)fl_elem_area.sx))
              {
                fl_win_data_SP->win_prop.width    = ((MM_U32)fl_elem_area.ex- (MM_U32)fl_elem_area.sx); 
                fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
              }
              if(fl_win_data_SP->win_prop.height != ((MM_U32)fl_elem_area.ey-(MM_U32)fl_elem_area.sy))
              {
                fl_win_data_SP->win_prop.height   = ((MM_U32)fl_elem_area.ey-(MM_U32)fl_elem_area.sy);
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
              if((l_cur_free_layer <= MML_GDC_DISP_LAYER_4)&&
                (l_disp_comp[p_layer_index].num_of_planes_used <= lc_amber_num_planes_u8a[p_layer_index]))
              {
                /* here > o is checked , as first element 0 will be kept in seperate layer */
                if(l_disp_comp[p_layer_index].num_of_visible_elements > (UINT8)0)
                {
#if defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER) || defined(GFX_MGR02_LAYER_WARPING_ENABLED)
                  fl_prev_num_of_layers = l_cur_free_layer; 
#endif
#if !defined(GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER)
                  fl_sublayer_available = hmi_gfx_mgr02_is_sublayer_available(l_cur_free_layer);
                  if((l_disp_comp[p_layer_index].window_data[l_disp_comp[p_layer_index].num_of_visible_elements-(UINT8)1].root_elem_sp !=fl_win_data_SP->root_elem_sp)||
                      ((TRUE == p_multi_layer)&&(FALSE == fl_sublayer_available)))
                  { 
                    l_cur_free_layer--;
                    l_disp_comp[p_layer_index].num_of_planes_used++;

                    if((l_disp_comp[p_layer_index].window_data[l_disp_comp[p_layer_index].num_of_visible_elements-(UINT8)1].root_elem_sp !=fl_win_data_SP->root_elem_sp) &&
                      ((l_cur_fractional_plane>(UINT8)0)&&(l_prev_fractional_plane ==l_cur_fractional_plane))&&
                      (p_multi_layer== TRUE))
                    {
                      l_cur_free_layer++;
                      l_disp_comp[p_layer_index].num_of_planes_used--;
                    }
                    if(p_multi_layer== TRUE)
                    {
                      l_prev_fractional_plane =l_cur_fractional_plane;
                    }
                  }
#else
                  l_cur_free_layer--;
                  l_disp_comp[p_layer_index].num_of_planes_used++;
#endif
                }
                else
                {
                  if(p_multi_layer== TRUE)
                  {
                    l_prev_fractional_plane =l_cur_fractional_plane;
                  }
                  l_disp_comp[p_layer_index].num_of_planes_used++;
                }
                fl_win_data_SP->win_prop.layerId = (MML_GDC_DISP_LAYER)l_cur_free_layer;

              #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
                 if(l_warp_plane_data.fp_no_of_sub_layer_used >= GFX_MGR02_NUM_OF_SUB_LAYER)
                 {
                     /* there is no more space on the warp plane - do not warp the element*/
                     fl_win_features &= ~MML_GDC_DISP_FEATURE_WARP;
                 }

                 if((fl_win_features & MML_GDC_DISP_FEATURE_WARP) == MML_GDC_DISP_FEATURE_WARP)
                 {
                     /* make the window to have warp property */
                     fl_win_data_SP->win_prop.features = fl_win_features | MML_GDC_DISP_FEATURE_MULTI_LAYER;

                     /* calculate the layer and sublayer of the warp plane */
                     if(l_warp_plane_data.fp_layer_id == GFX_MGR02_INVALID_LAYER)
                     {
                         /* warp plane still not been used, use the current layer */
                         fl_win_data_SP->win_prop.sub_layerId = (MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-l_warp_plane_data.fp_no_of_sub_layer_used);

                         l_warp_plane_data.fp_layer_id = fl_win_data_SP->win_prop.layerId;
                         l_warp_plane_data.fp_no_of_sub_layer_used++;
                     }
                     else
                     {
                         /* warp plane already used, so inherit its layer */
                         fl_win_data_SP->win_prop.layerId = (MML_GDC_DISP_LAYER)l_warp_plane_data.fp_layer_id;
                         fl_win_data_SP->win_prop.sub_layerId =(MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-l_warp_plane_data.fp_no_of_sub_layer_used);
                         l_warp_plane_data.fp_no_of_sub_layer_used++;

                         /* restore the current layer since we reused the one from the warp plane */
                         l_cur_free_layer = fl_prev_num_of_layers;
                         l_disp_comp[p_layer_index].num_of_planes_used--;

                     }

                 }
                 else
              #endif /* #ifdef GFX_MGR02_LAYER_WARPING_ENABLED */
                 if(p_multi_layer == FALSE)
                 {
                    fl_win_data_SP->win_prop.features = fl_win_features;
                 }
                 else
                 {
                   fl_win_data_SP->win_prop.features =(fl_win_features| MML_GDC_DISP_FEATURE_MULTI_LAYER);
                   /* since fractional plane is not allocated and other layer is allocated for this element , 		   */
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
                       fl_win_data_SP->win_prop.sub_layerId  = (MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
                       fl_fp_data_S->fp_no_of_sub_layer_used++;
                     }
                     else
                     {
                       fl_elem_area.sx = fl_win_data_SP->win_prop.topLeftX;
                       fl_elem_area.sy = fl_win_data_SP->win_prop.topLeftY;
                       fl_elem_area.ex = fl_win_data_SP->win_prop.width;
                       fl_elem_area.ey = fl_win_data_SP->win_prop.height;
                       fl_no_of_element_U32 = l_disp_comp[p_layer_index].num_of_visible_elements;
                       fl_element_overlaps  = FALSE;
                       while((fl_no_of_element_U32 != 0)&&(l_disp_comp[p_layer_index].window_data[fl_no_of_element_U32-1].win_prop.layerId != fl_fp_data_S->fp_layer_id))
                       {
                         /* first check inbetween layer overlap if it overlapes then we cannot allocate to fl_fp_data_S.fp_layer_id*/
                         fl_check_num_elements =  1;/* num of element in that layer check one by one as we dont know no of element in each layer*/
                         if(hmi_gfx_mgr02_is_fractional_element_visible(&fl_elem_area,fl_check_num_elements,&l_disp_comp[p_layer_index].window_data[fl_no_of_element_U32-1],TRUE) != GFX_MGR02_ELEMENT_VISIBLE)
                         {
                           fl_element_overlaps = TRUE;
                         }
                         fl_no_of_element_U32--;
                       }
                       if((fl_element_overlaps == FALSE)&&(fl_no_of_element_U32 != 0))
                       {
                         /* check for overlap and blending in fl_fp_data_S.fp_layer_id */
                         fl_check_num_elements = fl_fp_data_S->fp_no_of_sub_layer_used;/*???????? need to check num of elements in fl_fp_data_S.fp_layer_id*/ 	  
                         if(hmi_gfx_mgr02_is_fractional_element_visible(&fl_elem_area,fl_check_num_elements,&l_disp_comp[p_layer_index].window_data[fl_no_of_element_U32-1],FALSE) == GFX_MGR02_ELEMENT_VISIBLE)
                         {
                           /* change the already assigned layer id to fractional plane layer id. */
                           fl_win_data_SP->win_prop.layerId      = (MML_GDC_DISP_LAYER)fl_fp_data_S->fp_layer_id;
                           fl_win_data_SP->win_prop.sub_layerId  = (MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
                           fl_fp_data_S->fp_no_of_sub_layer_used++;
                           /*revert back already decremented num of layer as new layer is not used */
                           l_cur_free_layer = fl_prev_num_of_layers;
                           l_disp_comp[p_layer_index].num_of_planes_used--;
                         }
                         else
                         {
                           fl_fp_data_S = hmi_gfx_mgr02_get_unused_fractional_plane();
                           if(fl_fp_data_S != NULL)
                           {
                             /* change the already assigned layer id to fractional plane layer id. */
                             fl_fp_data_S->fp_layer_id             = l_cur_free_layer;
                             fl_win_data_SP->win_prop.layerId      = (MML_GDC_DISP_LAYER)l_cur_free_layer;
                             fl_win_data_SP->win_prop.sub_layerId  = (MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-fl_fp_data_S->fp_no_of_sub_layer_used);
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
                       if(l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_no_of_sub_layer_used<MML_GDC_DISP_SUB_LAYER_8)
                       {
                         fl_win_data_SP->win_prop.sub_layerId  = (MML_GDC_DISP_SUB_LAYER)(MML_GDC_DISP_SUB_LAYER_8-l_fractional_plane_data[l_cur_fractional_plane-0x01U].fp_no_of_sub_layer_used);
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
                    fl_win_data_SP->see_through = 0;
                 }
                 else
                 {
                    fl_win_data_SP->see_through = 1;
                 }

                 if(l_disp_comp[p_layer_index].num_of_visible_elements < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
                 {
                      l_disp_comp[p_layer_index].num_of_visible_elements++;
                 }
                 #ifdef GFX02_DEBUG_INFO
                    l_tot_num_of_elements++;
                 #endif
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
 ** Created:          
 ** Updated:          
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
	    if(l_fractional_plane_data[i].fp_no_of_sub_layer_used < MML_GDC_DISP_SUB_LAYER_8)
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
      if(l_fractional_plane_data[i].fp_no_of_sub_layer_used < (UINT32)MML_GDC_DISP_SUB_LAYER_8)
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
/* Deviation - MISRA C-2012 Rule 17.2 - Recursive function call cannot be avoided */
static UINT32 hmi_gfx_mgr02_manage_layers_is_child_visible(GFX_MGR02_ELEMENT_AREA const * p_area, 
                                                           UINT32 p_num_elements,
                                                           GFX_MGR02_WINDOW_DATA_T  * p_window_SP)
{
    UINT32                  fl_layer_visible = GFX_MGR02_ELEMENT_INVALID;
    GFX_MGR02_ELEMENT_AREA  fl_area={0,0,0,0,GFX_MGR02_OPEQUE,255};
    GFX_MGR02_ELEMENT_AREA  fl_area2={0,0,0,0,GFX_MGR02_OPEQUE,255};
    SINT16                  fl_temp;

    while((fl_layer_visible == GFX_MGR02_ELEMENT_INVALID) && (p_num_elements > (UINT32)0))
    {
        fl_area.sx    = (SINT16)p_window_SP->win_prop.topLeftX;
        fl_area.sy    = (SINT16)p_window_SP->win_prop.topLeftY;
        fl_area.ex    = (SINT16)p_window_SP->win_prop.width;
        fl_area.ey    = (SINT16)p_window_SP->win_prop.height;
        fl_area.alpha = (UINT8)p_window_SP->alpha;

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
        else if((p_window_SP->see_through != (UINT8)0) || (fl_area.alpha < (UINT8)255))
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_SEETHROUGH;
        }
        else
        {
            fl_area.is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        }

        
        p_num_elements--;
        p_window_SP++;
        while(p_num_elements>(UINT32)0)
        {
            p_num_elements--;
            p_window_SP++;
            if(p_window_SP->win_prop.sub_layerId!= (MML_GDC_DISP_SUB_LAYER)MML_GDC_DISP_SUB_LAYER_DEFAULT)
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
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, p_num_elements, p_window_SP);
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
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, p_num_elements, p_window_SP);
                                fl_area2.sy      = fl_temp;
                                fl_area2.ey      = fl_area.ey;
                            }
                            if((fl_area.sx > p_area->sx) && (fl_layer_visible != GFX_MGR02_ELEMENT_VISIBLE))
                            {
                                /*
                                ** Visible Left portion of the p_area rectangle
                                */
                                fl_area2.ex      = (fl_area.sx - (SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, p_num_elements, p_window_SP);
                                fl_area2.ex      = p_area->ex;
                                
                            }
                            if((fl_area.ex < p_area->ex) && (fl_layer_visible != GFX_MGR02_ELEMENT_VISIBLE))
                            {
                                /*
                                ** Visible Right portion of the p_area rectangle
                                */
                                fl_area2.sx      = (fl_area.ex+(SINT16)1);
                                fl_layer_visible = hmi_gfx_mgr02_manage_layers_is_child_visible((GFX_MGR02_ELEMENT_AREA const *)&fl_area2, p_num_elements, p_window_SP);
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
 ** Created:          16-Aug-2018 by ADEVI
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
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
            hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&l_layer_anim_data_SP->tile_prop[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_layer_anim_data_SP->tile_prop[fl_obj_id].alpha);
            p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.width;
            p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->tile_prop[fl_obj_id].dim.height;
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
            hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&l_layer_anim_data_SP->fill_prop[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)l_layer_anim_data_SP->fill_prop[fl_obj_id].alpha);
            p_elem_area->ex             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.width;
            p_elem_area->ey             = (SINT16)l_layer_anim_data_SP->fill_prop[fl_obj_id].dim.height;
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        #endif
        }
    }
    else
    {
        if(fl_obj_type == GFX_MGR02_TYPE_TILE)
        {
        #if GFX_MGR02_NUM_TILE_INSTANCES > 0
            hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&lc_tile_const_property_S[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_tile_const_property_S[fl_obj_id].alpha);
            p_elem_area->ex      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.width;
            p_elem_area->ey      = (SINT16)lc_tile_layer_def_S[p_elem_list_SP->base_id].dim.height;
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        #endif
        }
        else
        {
        #if GFX_MGR02_NUM_FILL_INSTANCES > 0
            hmi_gfx_mgr02_context_set_loc(&lc_fill_const_property_S[fl_obj_id].coord);
            hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_fill_const_property_S[fl_obj_id].alpha);
            p_elem_area->ex      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.width;
            p_elem_area->ey      = (SINT16)lc_fill_layer_def_S[p_elem_list_SP->base_id].dim.height;
            p_elem_area->is_transparent = (UINT8)GFX_MGR02_OPEQUE;
        #endif
        }
    }
}
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_image_layer_area
 ** Visibility:       static
 ** Description:      fetches the Image elments area.
 ** Invocation:
 ** Inputs/Outputs:  GFX_MGR02_ELEMENT_AREA, GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_image_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                GFX_MGR02_ELEMENT_AREA       * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    #if((GFX_MGR02_NUM_USER_LAYERS > 0 )|| (GFX_MGR02_NUM_3D_MDL_LAYERS > 0))
    UINT32 fl_obj_type   = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);
    #endif
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    GFX_MGR02_IMAGE_DEF_T const * fl_image_layer_def_SP;

#if GFX_MGR02_NUM_USER_LAYERS > 0
    if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
    {
       fl_image_layer_def_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
       #if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
           GFX_MGR02_IMAGE_DYN_PROPERTY * fl_img_dyn_prop_SP = &l_layer_anim_data_SP->user_prop[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc((GFX_MGR02_ILOC_DATA const *)&fl_img_dyn_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_dyn_prop_SP->alpha);
       #endif
       }
       else
       {
       #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
           GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_prop_SP->alpha);
       #endif
       }
    }
    else
#endif
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
    if(fl_obj_type == GFX_MGR02_TYPE_3D_MDL)
    {
       fl_image_layer_def_SP = &l_layer_anim_data_SP->mdl_3d_layer[p_elem_list_SP->base_id];
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {

       }
       else
       {
       #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
           GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_prop_SP->alpha);
       #endif
       }
    }
    else
#endif
    {
    #if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
       fl_image_layer_def_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
       #if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
           GFX_MGR02_IMAGE_DYN_PROPERTY const * fl_img_dyn_prop_SP = &l_layer_anim_data_SP->image_prop[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_dyn_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_dyn_prop_SP->alpha);
       #endif
       }
       else
       {
       #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
           GFX_MGR02_IMAGE_PROPERTY const * fl_img_prop_SP = &lc_img_const_property_S[fl_obj_id];
           hmi_gfx_mgr02_context_set_loc(&fl_img_prop_SP->coord);
           hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)fl_img_prop_SP->alpha);
       #endif
       }
       if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
       {
           fl_vaof_index = (UINT8)fl_image_layer_def_SP->vaoa_index;
       }
     #endif
    }
    p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
    p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static UINT32 hmi_gfx_mgr02_get_widget_layer_area(GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP,
                                                  GFX_MGR02_ELEMENT_AREA      * p_elem_area)
{
    UINT32 fl_vaof_index = GFX_MGR02_INVALID_ID;
    UINT32 fl_obj_id     = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
    UINT32 fl_base_id    = p_elem_list_SP->base_id;
    GFX_MGR02_WIDGET_DEF_T const * fl_widget_layer_def_SP = &lc_swidget_layer_def_S[fl_base_id];
    

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
       GFX_MGR02_IMAGE_DEF_T   *fl_image_layer_def_SP = &l_runtime_wdg_image_layer_def_S[fl_widget_layer_def_SP->image_id];
       
       if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
       {
		#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
          UINT32 fl_aligned_width;
          UINT32 fl_aligned_height;

          GFX_MGR02_WIDGET_DYN_PROPERTY * fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];

          (void)hmi_gfx_mgr02_generic_get_element_bound(p_elem_list_SP, GFX_MGR02_TARGET_AMBER, fl_bound);

          fl_widg_dyn_prop_SP->coord.x    = (SINT16)fl_bound[0];
          fl_widg_dyn_prop_SP->coord.y    = (SINT16)fl_bound[1];
          fl_bound[0] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.x; /* get any remaining fractional part */
          fl_bound[1] -= (GFX_FLOAT)fl_widg_dyn_prop_SP->coord.y;
          
          fl_aligned_width  = ((UINT32)fl_bound[2]+(UINT32)fl_bound[0]+(UINT32)0.5);
          fl_aligned_height = ((UINT32)fl_bound[3]+(UINT32)fl_bound[1]+(UINT32)0.5);
          
          fl_image_layer_def_SP->width  = (GFX_MGR02_ISIZE_W_T)(fl_aligned_width);
          fl_image_layer_def_SP->height = (GFX_MGR02_ISIZE_H_T)(fl_aligned_height);
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
          fl_vaof_index = (UINT8)fl_image_layer_def_SP->vaoa_index;
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
       GFX_MGR02_IMAGE_DEF_T   const *fl_image_layer_def_SP = &lc_image_layer_def_S[fl_widget_layer_def_SP->image_id];
    p_elem_area->ey = (SINT16)fl_image_layer_def_SP->height;
    p_elem_area->ex = (SINT16)fl_image_layer_def_SP->width;
       if(fl_image_layer_def_SP->vaoa_index != (UINT8)0)
       {
          fl_vaof_index = (UINT8)fl_image_layer_def_SP->vaoa_index;
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
        GFX_MGR02_WIDGET_DYN_PROPERTY const  * fl_widg_dyn_prop_SP = &l_layer_anim_data_SP->widget_prop[fl_obj_id];
        GFX_MGR02_WIDGET_PROPERTY const * fl_elem_prop_SP;
        GFX_MGR02_ILOC_DATA               fl_coord;

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
        if(fl_widget_layer_def_SP->merge != (UINT8)0)
        {
           hmi_gfx_mgr02_context_set_loc(&lc_swdg_const_property_S[fl_obj_id].coord);
        }
        hmi_gfx_mgr02_context_set_alpha((u_gx_flocal)lc_swdg_const_property_S[fl_obj_id].alpha);
    #endif 
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_render_display(UINT32 p_layer_index)
{
  static  UINT32                  l_prev_disp_bg_color[GFX_MGR02_NUM_LAYERS]={0};
  MM_S32 ret = MML_OK;
  UINT8 fl_next_element;
  UINT8 fl_shutdown_state  = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
  GFX_MGR02_WINDOW_DATA_T     * fl_win_data_SP;
  UINT32 fl_feature_mask;
  UINT32 fl_decode_feature_count = 0UL;
  UINT8 fl_cur_window_U8;
  UINT8 fl_win_order_changed_u8 = (UINT8)FALSE;
  UINT8 fl_disp_commit_needed_u8 = (UINT8)FALSE;
   UINT8 fl_exit_check_flag = FALSE;
  if((l_disp_comp[p_layer_index].num_of_visible_elements> (UINT8)0) &&(fl_shutdown_state != GFX_MGR02_SHUTDOWN_EMERGENCY))
  {
    /*
    ** Previous sync operations has completed, we can now start
    ** render and update for new updates.
    ** Destroy inactive windows if any
    */
    fl_next_element = l_disp_comp[p_layer_index].num_of_visible_elements;
    fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    while(fl_next_element < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS)
    {
      if(fl_win_data_SP->win != NULL)
      {
        if((fl_win_data_SP->win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) == (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT)
        {
          /* Switch the window Off for Brontes Stream */
          IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(fl_win_data_SP->win, MML_GDC_DISP_WIN_ATTR_DISABLE, (UINT32)MM_TRUE));
          IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(fl_win_data_SP->win));
        }
        else
        {
          IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(fl_win_data_SP->win));
        }
        fl_win_data_SP->win         = NULL;
        fl_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
      }
      fl_next_element++;
      fl_win_data_SP++;
    }
    /*
    Check whether Window order got changed. If changed then destroy all windows 
    and render the content freshly.
    */
    fl_next_element         = l_disp_comp[p_layer_index].num_of_visible_elements;
    fl_win_data_SP          = &l_disp_comp[p_layer_index].window_data[fl_next_element-0x01u];
    while(fl_next_element > (UINT8)0) 
    {

      fl_win_data_SP->win_prop.topLeftX = (UINT32)fl_win_data_SP->posx;
      fl_win_data_SP->win_prop.topLeftY = (UINT32)fl_win_data_SP->posy;
      fl_win_data_SP->valid             = 0x01u;

      if(fl_win_data_SP->win != NULL)
      {
        MM_U32 fl_win_param = 0U;
                UINT32 fl_win_valid = FALSE;
        /*
        ** check if the window plane & features match the next window
        ** requirement. If yet we neednot destroy the window
        */
        if(mmlGdcDispWinGetAttribute( fl_win_data_SP->win,
          MML_GDC_DISP_WIN_ATTR_LAYER_ID,
          &fl_win_param) == MML_OK)
        {
          if(fl_win_param == fl_win_data_SP->win_prop.layerId)
          {
            if(mmlGdcDispWinGetAttribute( fl_win_data_SP->win,
              MML_GDC_DISP_WIN_ATTR_FEATURE,
              &fl_win_param) == MML_OK)
            {

              if(fl_win_data_SP->win_prop.features == fl_win_param) 
              {
                          fl_win_valid =TRUE;
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
      fl_next_element--;
      fl_win_data_SP--;
    }
    if(fl_win_order_changed_u8 != (UINT8)FALSE)
    {
      fl_next_element         = l_disp_comp[p_layer_index].num_of_visible_elements;
      fl_win_data_SP          = &l_disp_comp[p_layer_index].window_data[fl_next_element-0x01u];

      while(fl_next_element > (UINT8)0)
      {
        fl_win_data_SP->win_prop.topLeftX = (UINT32)fl_win_data_SP->posx;
        fl_win_data_SP->win_prop.topLeftY = (UINT32)fl_win_data_SP->posy;
        fl_win_data_SP->valid = TRUE;
        fl_next_element--;
        fl_win_data_SP--;		
      }
      for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < (UINT8)GFX_MGR02_NUM_AMBER_LAYERS; fl_cur_window_U8++)
      {
        if(l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win != NULL)
        {
          IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win));
          l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win = NULL;
          l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts = GFX_MGR02_AMBER_WIN_DIRTY;
        }	
      }		
      hmi_gfx_mgr02_context_reset_widget_buff_id();
    }


    /*
    ** Allocate windows in recomended order
    ** 1. window with feature MML_GDC_DISP_FEATURE_DECODE
    ** 2. window with feature MML_GDC_DISP_FEATURE_IMAGE_PROCESSING, MML_GDC_DISP_FEATURE_CAPTURE, MML_GDC_DISP_FEATURE_YUV1BUFF).
    ** 3. window with feature MML_GDC_DISP_FEATURE_EXTERN_ALPHA.
    ** 4. window with feature MML_GDC_DISP_FEATURE_WARP.
    ** 5. window with feature MML_GDC_DISP_FEATURE_MULTI_LAYER (cannot have decode feature)
    ** 6. window with feature MML_GDC_DISP_FEATURE_INDEX_COLOR
    ** 7. Rest of the windows
    */
    fl_next_element = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask = ((UINT32)(MML_GDC_DISP_FEATURE_DECODE|MML_GDC_DISP_FEATURE_MULTI_LAYER));

      while((fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) && (fl_exit_check_flag == FALSE) )
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_DECODE)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
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
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** Allocate Windows with MML_GDC_DISP_FEATURE_IMAGE_PROCESSING, MML_GDC_DISP_FEATURE_
    CAPTURE, MML_GDC_DISP_FEATURE_YUV1BUFF.
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask = ((UINT32)(MML_GDC_DISP_FEATURE_IMAGE_PROCESSING|MML_GDC_DISP_FEATURE_CAPTURE|MML_GDC_DISP_FEATURE_YUV1BUFF));

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if(((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_IMAGE_PROCESSING)||
          ((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_CAPTURE)||
          ((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_YUV1BUFF))
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP, p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** Allocate Windows with MML_GDC_DISP_FEATURE_EXTERN_ALPHA Here.
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask = ((UINT32)(MML_GDC_DISP_FEATURE_EXTERN_ALPHA));

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }

    /*
    ** Allocate Windows with MML_GDC_DISP_FEATURE_WARP feature here.
    ** The Warp Plane is a Fractional Plane.
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask = ((UINT32)(MML_GDC_DISP_FEATURE_MULTI_LAYER|MML_GDC_DISP_FEATURE_WARP));

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements)
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** Allocate all multilayer feature windows
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask = ((UINT32)(MML_GDC_DISP_FEATURE_MULTI_LAYER|MML_GDC_DISP_FEATURE_INDEX_COLOR));

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == fl_feature_mask)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }

    /*
    ** Allocate all multilayer feature windows
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_MULTI_LAYER)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** Allocate all indexcolor feature windows
    */
    fl_next_element  = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP   = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask |= (UINT32)MML_GDC_DISP_FEATURE_INDEX_COLOR;

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_INDEX_COLOR)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** Brontes windows
    */
    fl_next_element = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
    fl_feature_mask |= (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT;
    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements)
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }
    /*
    ** All other windows
    */
    fl_next_element = (l_disp_comp[p_layer_index].num_of_visible_elements-0x01u);
    fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];

    while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements) 
    {
      if(fl_win_data_SP->valid != (UINT8)0)
      {
        if((fl_win_data_SP->win_prop.features & fl_feature_mask) == 0UL)
        {
          hmi_gfx_mgr02_render_window(fl_win_data_SP,p_layer_index);
        }
      }
      else
      {
        break;
      }
      fl_next_element--;
      fl_win_data_SP--;
    }

      /*
      ** Check Whether the Display Commit Needed or not?
      */
	  	for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < l_disp_comp[p_layer_index].num_of_visible_elements; fl_cur_window_U8++)
		{
			if(l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts == GFX_MGR02_AMBER_WIN_UPDATED)
			{
				fl_disp_commit_needed_u8 = (UINT8)TRUE;
				break;
			}	
		}
		if(l_prev_disp_bg_color[p_layer_index] != l_disp_comp[p_layer_index].bg_colour)
		{
			
			(void)mmlGdcDispSetAttribute(l_disp_comp[p_layer_index].display,MML_GDC_DISP_ATTR_BACKGROUND_COLOR,l_disp_comp[p_layer_index].bg_colour); 
            l_prev_disp_bg_color[p_layer_index] =l_disp_comp[p_layer_index].bg_colour;
			fl_disp_commit_needed_u8 = (UINT8)TRUE;
		}
      /*
      ** Commit the Display for the changes.
      */
		if(fl_disp_commit_needed_u8 != (UINT8)FALSE)
		{
			#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
			if(l_disp_comp[p_layer_index].gpusync_flag != (UINT8)0)
			{
				IRIS_API_CHECK(ret, mmlGdcDispWaitSync(l_disp_comp[p_layer_index].display, l_disp_comp[p_layer_index].gpu_sync));
				l_disp_comp[p_layer_index].gpusync_flag = (UINT8)0;
			}
			#endif
			IRIS_API_CHECK(ret, mmlGdcDispCommit(l_disp_comp[p_layer_index].display));
			#if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)
   			GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP;
   			GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP;
   			GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
   			GFX_MGR02_CONTEXT_T p_cntx_SP;
			UINT32 fl_obj_type;
 		    
			fl_next_element = l_disp_comp[p_layer_index].num_of_visible_elements-0x01u;
			fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
			while(fl_next_element < l_disp_comp[p_layer_index].num_of_visible_elements)
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
	                p_cntx_SP.rprop.fb_target  = GFX_MGR02_TARGET_AMBER; 
					p_cntx_SP.rprop.fb_format   = fl_widget_desc_SP->fb_format;
				    p_cntx_SP.rprop.fb_w  = fl_image_desc_SP->width;
					p_cntx_SP.rprop.fb_h = fl_image_desc_SP->height;
	         		#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
	         		p_cntx_SP.rprop.pe_sync    = l_disp_comp[p_layer_index].gpu_sync;
	         		#endif
					MML_GDC_PE_CONTEXT fl_pe_cntx  = hmi_gfx_mgr02_context_get_pixeng_ctx(fl_widget_desc_SP->client_id);
					p_cntx_SP.rprop.pe_ctx = fl_pe_cntx;
							if(fl_pe_cntx != (MML_GDC_PE_CONTEXT)NULL)
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
				fl_next_element--;
				fl_win_data_SP--;				
			}
			#endif /* GFX_MGR02_AMBER_USE_VHRAM_HRAM */
			IRIS_API_CHECK(ret, mmlGdcDispSync(l_disp_comp[p_layer_index].display,l_disp_comp[p_layer_index].disp_sync));
			#ifdef GFX_MGR02_AMBER_SKIP_BUSY_CHK
            IRIS_API_CHECK(ret, mmlGdcPeWaitSync(l_disp_comp[p_layer_index].disp_sync));
			#endif			
		    for(fl_cur_window_U8=(UINT8)0; fl_cur_window_U8 < l_disp_comp[p_layer_index].num_of_visible_elements; fl_cur_window_U8++)
			{
				if(l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts == GFX_MGR02_AMBER_WIN_UPDATED)
				{
					l_disp_comp[p_layer_index].window_data[fl_cur_window_U8].win_sts = GFX_MGR02_AMBER_WIN_COMMITED;
				}	
			}
            l_content_ready_ondisplay =(UINT32)2;
			
		}

      l_cur_num_of_elements[p_layer_index] = l_disp_comp[p_layer_index].num_of_visible_elements;
   }
   else
   {
	    /*Destroy the active windows if the number visible element is Zero.*/
	    fl_next_element = (UINT8)0;
        fl_win_data_SP  = &l_disp_comp[p_layer_index].window_data[fl_next_element];
        while(fl_next_element < (UINT8)l_cur_num_of_elements[p_layer_index])
        {
            if(fl_win_data_SP->win != NULL)
            {
                if((fl_win_data_SP->win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) == (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT)
                {
                    IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(fl_win_data_SP->win, MML_GDC_DISP_WIN_ATTR_DISABLE, (UINT32)MM_TRUE));
                }
                IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(fl_win_data_SP->win));
                fl_win_data_SP->win         = NULL;
                fl_win_data_SP->win_prop.topLeftX = (UINT32)0;
                fl_win_data_SP->win_prop.topLeftY = (UINT32)0;
                fl_win_data_SP->win_prop.width =0;
                fl_win_data_SP->win_prop.height =0;
                fl_win_data_SP->win_prop.features = 0;
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
        if(fl_disp_commit_needed_u8 == (UINT8)TRUE)
        {
            IRIS_API_CHECK(ret, mmlGdcDispCommit(l_disp_comp[p_layer_index].display));
            IRIS_API_CHECK(ret, mmlGdcDispSync(l_disp_comp[p_layer_index].display,l_disp_comp[p_layer_index].disp_sync));
            l_cur_num_of_elements[p_layer_index]=(UINT8)0;
            l_content_ready_ondisplay =(UINT32)1;
        }
    }
   GFX_MGR02_UNUSED_VAR(ret);
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
    UINT8            		fl_layer_overlap=0;

    while((fl_layer_visible == GFX_MGR02_ELEMENT_INVALID) && (p_num_elements > 0))
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
        p_num_elements--;
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
#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_set_blendmode
 ** Visibility:       static
 ** Description:      
 ** Invocation:       
 ** Inputs/Outputs:   
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static void hmi_gfx_mgr02_set_blendmode(GFX_MGR02_WINDOW_DATA_T const * p_wind, GFX_MGR02_IMAGE_DEF_T  const * p_image_desc_SP, UINT32 p_blend_mode)
{
   UINT32 fl_win_blend_mode = p_blend_mode;
   UINT32 fl_bg_color;
   MM_S32 ret;
   if((p_wind->win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) == 0UL) 
   {
      switch(p_image_desc_SP->format)
      {
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
         case MML_GDC_SURF_FORMAT_A4RGB4:
         {
            fl_win_blend_mode |= (UINT32)(MML_GDC_DISP_BLEND_SOURCE_ALPHA);
         }
         break;

         case MML_GDC_SURF_FORMAT_A8:
         case MML_GDC_SURF_FORMAT_A4:
         case MML_GDC_SURF_FORMAT_A2:
         case MML_GDC_SURF_FORMAT_A1:
         {
            fl_win_blend_mode |= (UINT32)(MML_GDC_DISP_BLEND_SOURCE_ALPHA|MML_GDC_DISP_BLEND_SOURCE_MULTIPLY_ALPHA);
         }
         break;

         default:
         {
            fl_win_blend_mode |= (UINT32)MML_GDC_DISP_BLEND_NONE;
         }
   	     break;
      }
   }
   fl_bg_color = p_wind->alpha;
   if(fl_bg_color < (UINT32)255)
   {
      fl_win_blend_mode |= (UINT32)MML_GDC_DISP_BLEND_GLOBAL_ALPHA;
   }                        

   if(p_image_desc_SP->chroma_key != (UINT8)0)
   {
      fl_bg_color |= (p_image_desc_SP->color << 8U);
      fl_win_blend_mode |= (UINT32)MML_GDC_DISP_BLEND_TRANSPARENCY;
   }
   else
   {
      fl_bg_color |=  (p_wind->win_colour << 8U);
   }
   if(fl_win_blend_mode != 0UL)
   {
      IRIS_API_CHECK(ret, mmlGdcDispWinSetBlendMode(p_wind->win, fl_win_blend_mode));
      IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(p_wind->win, MML_GDC_DISP_WIN_ATTR_COLOR, fl_bg_color));
   }
   else
   {
        IRIS_API_CHECK(ret, mmlGdcDispWinSetBlendMode(p_wind->win, (UINT32)MML_GDC_DISP_BLEND_NONE));
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_create_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index)
{
   MM_S32 ret;
   if(p_win_data_SP->win == NULL)
   {
   #ifdef GFX02_DEBUG_INFO
      printf("CreateWndow[%d] - plane=%d features=%X", (p_win_data_SP-&l_disp_comp[p_layer_index].window_data[0]), p_win_data_SP->win_prop.layerId,p_win_data_SP->win_prop.features);
   #endif
      IRIS_API_CHECK(ret, mmlGdcDispWinCreate(l_disp_comp[p_layer_index].display,
                                            &p_win_data_SP->win_prop,
                                            &p_win_data_SP->win));
      IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(p_win_data_SP->win, MML_GDC_DISP_WIN_ATTR_DISABLE, (UINT32)MM_FALSE));
      if((p_win_data_SP->win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) != (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT)
      {
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_TILE_MODE,
                                                 (UINT32)MML_GDC_DISP_TILE_MODE_ZERO));
      }
   }
   else
   {
   #ifdef GFX02_DEBUG_INFO
      printf("UpdateWndow[%d] - plane=%d features=%X\n", (p_win_data_SP-&l_disp_comp[p_layer_index].window_data[0]), p_win_data_SP->win_prop.layerId,p_win_data_SP->win_prop.features);
   #endif
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_TOPLEFT_X,
                                                 p_win_data_SP->win_prop.topLeftX));
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y,
                                                 p_win_data_SP->win_prop.topLeftY));
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_WIDTH,
                                                 p_win_data_SP->win_prop.width));
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_HEIGHT,
                                                 p_win_data_SP->win_prop.height));
   }
   #ifdef GFX_MGR02_LAYER_WARPING_ENABLED
    {
        GFX_MGR02_WARP_ID warp_id = lc_layer_def_S[p_layer_index].warp_id;
        if((warp_id != GFX_MGR02_INVALID_WARP) && (warp_id < l_warp_table_size))
        {
			void  * fl_buff_ptr = (void  *)l_warp_table[warp_id].warp_buffer;
            if((p_win_data_SP->win_prop.features & MML_GDC_DISP_FEATURE_WARP) == MML_GDC_DISP_FEATURE_WARP)
            {
                if(fl_buff_ptr != NULL)
                {
                  if(GFX_MGR02_AMBER_IS_TCFLASH(fl_buff_ptr))
                  {
                     fl_buff_ptr = GFX_MGR02_AMBER_REMAP_TCFLASH(fl_buff_ptr);
                  }
                }                
                IRIS_API_CHECK(ret,mmlGdcDispWinSetWarpBuffer(p_win_data_SP->win,
                                                            (const MML_GDC_WARP_PARAM*)(l_warp_table[warp_id].warp_params),
                                                            fl_buff_ptr,
                                                            NULL));
            }
        }
    }
   #endif
#if defined(GFX_CYPRESS_ROTATION_ENABLED)
   MM_FLOAT matrix[6]= CUSTOM_MATRIX_DISPLAY;
   matrix[4]=p_win_data_SP->win_prop.width;
   matrix[5]=p_win_data_SP->win_prop.height;
   if(p_win_data_SP->win_prop.width!= l_mml_gdc_dispParams[0].xResolution)
   {
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_TOPLEFT_X,
                                                 (l_mml_gdc_dispParams[0].xResolution-p_win_data_SP->win_prop.topLeftX-p_win_data_SP->win_prop.width)));
   }
   if(p_win_data_SP->win_prop.height!= l_mml_gdc_dispParams[0].yResolution)
   {
      IRIS_API_CHECK(ret,mmlGdcDispWinSetAttribute(p_win_data_SP->win,
                                                 MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y,
                                                 (l_mml_gdc_dispParams[0].yResolution-p_win_data_SP->win_prop.topLeftY-p_win_data_SP->win_prop.height)));

   }
   IRIS_API_CHECK(ret,mmlGdcDispWinSetMatrix(p_win_data_SP->win,MML_GDC_DISP_BUFF_TARGET_COLOR_BUFF,matrix));
#endif
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_render_window(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_layer_index)
{
   UINT32 fl_obj_type;
   UINT32 fl_obj_id;
   GFX_MGR02_ELEM_LIST_T const * fl_elem_list_SP = p_win_data_SP->next_elem_sp;
   MM_S32 ret = MML_OK;

    
   if((fl_elem_list_SP != NULL)&& (p_win_data_SP->win_sts == GFX_MGR02_AMBER_WIN_DIRTY))
   {
      /*
      ** Static elements which does not require RAM. So by default prepare the
      ** DCU configuration registers.
      */
      fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(fl_elem_list_SP->obj_id);
      fl_obj_id   = GFX_MGR02_GET_OBJ_ID(fl_elem_list_SP->obj_id);

      p_win_data_SP->win_prop.topLeftX =(UINT32)p_win_data_SP->posx;
      p_win_data_SP->win_prop.topLeftY =(UINT32)p_win_data_SP->posy;

      switch(fl_obj_type)
      {
      #if (GFX_MGR02_NUM_OF_SWDGS > 0) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
         case GFX_MGR02_TYPE_SWIDGET:
         {
            hmi_gfx_mgr02_build_widget(p_win_data_SP, fl_elem_list_SP,p_layer_index);
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
            hmi_gfx_mgr02_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index);
         }
         break;
      #endif
      #if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_WINDOW_MODE)
         case GFX_MGR02_TYPE_VIDEO_LAYER:
         {
            hmi_gfx_mgr02_build_video(p_win_data_SP, fl_elem_list_SP, p_layer_index);
         }
         break;
      #endif
      #if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
         case GFX_MGR02_TYPE_3D_MDL:
         {
            hmi_gfx_mgr02_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index);
         }
         break;
      #endif
      #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
         case GFX_MGR02_TYPE_SIMAGE:
         {
            hmi_gfx_mgr02_build_image(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index);
         }
         break;
      #endif
      #if GFX_MGR02_NUM_OF_FILLS > 0
         case GFX_MGR02_TYPE_FILL:
         {
            hmi_gfx_mgr02_build_fill(p_win_data_SP, fl_obj_id, fl_elem_list_SP,p_layer_index);
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
               IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(p_win_data_SP->win));
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
        MM_S32                    ret = MML_OK;	 
        GFX_MGR02_CAPTURE_INIT_STATUS          fl_cap_init_status;
        static UINT8              fl_stability_flag = TRUE;  

        fl_cap_init_status = hmi_gfx_mgr02_get_capture_init_status();
        hmi_gfx_mgr02_capture_video_set_status(TRUE);  

        if(fl_cap_init_status != GFX_MGR02_CAPTURE_INIT_SUCCESS)
        {
            GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status;    		
            fl_init_status = hmi_gfx_mgr02_capture_to_window_init(l_mml_gdc_dispParams[p_layer_index].modeLine, lc_video_layer_def_S);

            if(fl_init_status == GFX_MGR02_CAPTURE_INIT_SUCCESS)
            {
                MML_GDC_SYNC*              fl_cap_sync;

                hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index); 
                IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(p_win_data_SP->win, MML_GDC_DISP_WIN_ATTR_COLOR, 0x00000000));
                IRIS_API_CHECK(ret, mmlGdcDispWinSetBlendMode(p_win_data_SP->win, MML_GDC_DISP_BLEND_GLOBAL_ALPHA));
                IRIS_API_CHECK(ret, mmlGdcDispWinSetCapture(p_win_data_SP->win, *fl_cap_ctx));
                IRIS_API_CHECK(ret, mmlGdcDispWinCommit(p_win_data_SP->win));
                if(ret != MML_OK)
                {
                    hmi_gfx_mgr02_set_capture_signal_loss(GFX_MGR02_CAPTURE_INIT_SIGNAL_LOSS);
                }
                else
                {
                    fl_stability_flag = FALSE;
                    fl_cap_sync = hmi_gfx_mgr02_get_capture_sync();	
                    IRIS_API_CHECK(ret, mmlGdcCapSyncVSync(*fl_cap_ctx, *fl_cap_sync,GFX_MGR02_CAPTURE_TO_WIN_FRAMES_TO_SKIP));
                    p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                }
            } 
        }
        else if(fl_stability_flag == FALSE)
        {
            MML_GDC_SYNC*              fl_cap_sync;
            fl_cap_sync = hmi_gfx_mgr02_get_capture_sync();	
            if (MML_ERR_GDC_SYNC_TIMEOUT == mmlGdcSyncWait(*fl_cap_sync, 0))
            {
            }
            else
            {
                /* switch window on, after 2 frames (cap-to-win is now stable) */
                IRIS_API_CHECK(ret, mmlGdcDispWinSetBlendMode(p_win_data_SP->win, MML_GDC_DISP_BLEND_NONE));
                IRIS_API_CHECK(ret, mmlGdcDispWinCommit(p_win_data_SP->win));
                p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
                fl_stability_flag = TRUE;
            }
        }
        else
        {
        }
    }
}
#endif

#if (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0) || (GFX_MGR02_NUM_USER_LAYERS > 0)||(GFX_MGR02_NUM_3D_MDL_LAYERS > 0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_build_image
 ** Visibility:       static
 ** Description:      Builds/Updates image element
 ** Invocation:       By hmi_gfx_mgr02_render_window
 ** Inputs/Outputs:   GFX_MGR02_ELEM_LIST_T
 ** Critical Section: None.
 ** Created:          06-Oct-2014 by SSIGAMAN.
 **==========================================================================*/
static void hmi_gfx_mgr02_build_image(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
   GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
   #if defined(GFX_MGR02_CLIPPED_WIDGETS)
   GFX_MGR02_IAREA_DATA           fl_elem_area_S={(SINT16)0,(SINT16)0,(UINT16)0,(UINT16)0};
   SINT32                         fl_start_offset = 0;
   UINT32                         fl_bpp = (UINT32)0;
   #endif
   UINT32                         fl_obj_id;
   UINT32                         fl_obj_type;
   UINT32                         fl_rle_words;
   UINT32                         fl_invisible = FALSE;
   MM_S32                         ret = MML_OK;
   void                         * fl_buff_ptr;


   if(p_elem_list_SP != GFX_MGR02_NULL_PTR)
   {
      fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
      fl_obj_type = GFX_MGR02_GET_OBJ_TYPE(p_elem_list_SP->obj_id);

   #if GFX_MGR02_NUM_USER_LAYERS > 0
      if(fl_obj_type == GFX_MGR02_TYPE_USER_LAYER)
      {
         fl_image_desc_SP = &l_layer_anim_data_SP->user_image_layer[p_elem_list_SP->base_id];
      }
      else
   #endif
      {
	     #if  GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
         fl_image_desc_SP = &lc_image_layer_def_S[p_elem_list_SP->base_id];
         #endif
      }
 	  if(fl_obj_type != GFX_MGR02_TYPE_3D_MDL)
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
             fl_start_offset = (p_win_data_SP->clip.sx - (SINT32)p_win_data_SP->win_prop.topLeftX);
             if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->width))
             {
                fl_bpp          = hmi_gfx_mgr02_get_bpp((UINT32)(fl_image_desc_SP->format));
                fl_buff_ptr     = &((UINT8 *)fl_buff_ptr)[(fl_bpp * (UINT32)fl_start_offset)>>3U];
                fl_start_offset = (p_win_data_SP->clip.sy - (SINT32)p_win_data_SP->win_prop.topLeftY);

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
                    p_win_data_SP->win_prop.topLeftX = (UINT32)p_win_data_SP->clip.sx;
                    p_win_data_SP->win_prop.topLeftY = (UINT32)p_win_data_SP->clip.sy;
                    p_win_data_SP->win_prop.width    = (UINT32)p_win_data_SP->clip.ex;
                    p_win_data_SP->win_prop.width   -= (UINT32)p_win_data_SP->clip.sx;
                    p_win_data_SP->win_prop.height   = (UINT32)p_win_data_SP->clip.ey;
                    p_win_data_SP->win_prop.height  -= (UINT32)p_win_data_SP->clip.sy;
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
          if(GFX_MGR02_AMBER_IS_TCFLASH(fl_buff_ptr))
          {
             fl_buff_ptr = GFX_MGR02_AMBER_REMAP_TCFLASH(fl_buff_ptr);
          }
          IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(p_win_data_SP->surf));
          if((MML_GDC_SURF_FORMAT_RGB4 == fl_image_desc_SP->format) ||
             (MML_GDC_SURF_FORMAT_RGB2 == fl_image_desc_SP->format) ||
             (MML_GDC_SURF_FORMAT_A6R6G6B6 == fl_image_desc_SP->format))
          {
                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                       p_win_data_SP->win_prop.width, 
                                                       p_win_data_SP->win_prop.height,
                                                       MML_GDC_SURF_FORMAT_R8G8B8A8, 
                                                       fl_buff_ptr,
                                                       fl_rle_words));

                if(MML_GDC_SURF_FORMAT_RGB2 ==fl_image_desc_SP->format)
                {
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x02));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORBITS,   (UINT32)0x02020200));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORSHIFT,  (UINT32)0x00000000));
                }
                else if(MML_GDC_SURF_FORMAT_RGB4 ==fl_image_desc_SP->format)
                {
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x04));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORBITS,   (UINT32)0x04040400));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORSHIFT,  (UINT32)0x00000000));
                }
                else
                {
                  /*MML_GDC_SURF_FORMAT_A6R6G6B6*/
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORBITS, (UINT32)0x06060606));
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x0c060012));
                }
          }
          else
          {	
             IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                    p_win_data_SP->win_prop.width,
                                                    p_win_data_SP->win_prop.height,
                                                    (MML_GDC_SURF_FORMAT)fl_image_desc_SP->format,
                                                    fl_buff_ptr, 
                                                    fl_rle_words));
          }
          #if defined(GFX_MGR02_CLIPPED_WIDGETS)		
          if(fl_start_offset >= 0)
          {	
             IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_WIDTH, p_win_data_SP->win_prop.width));
             IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_HEIGHT,p_win_data_SP->win_prop.height));
             IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_STRIDE,((fl_image_desc_SP->width * fl_bpp)+7UL)>>3U));
          }
          #endif	  
          #if defined(GFX_MGR02_COMPRESSION_ENABLED)
          if(fl_rle_words != (UINT32)0)
          {
            switch(fl_image_desc_SP->compression)
            {
               case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLE:
               {
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, (UINT32)MML_GDC_SURF_COMP_RLC));
               }
               break;
               case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLA:
               {
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, (UINT32)MML_GDC_SURF_COMP_RLA));
               }
               break;
               case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLD:
               {
                  IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, (UINT32)MML_GDC_SURF_COMP_RLAD));
               }
               break;
               default:
               {
            	   /*For fixing MISRA warning.*/
               }
               break;
            }
          }
          #endif

          #if GFX_MGR02_NUM_OF_CLUTS > 0
          if(fl_image_desc_SP->clut < (UINT16)GFX_MGR02_NUM_OF_CLUTS)
          {
              GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_image_desc_SP->clut];
			 void * fl_clut_p =(void *) fl_elem_clut_SP->CLUT;
			 if(GFX_MGR02_AMBER_IS_TCFLASH(fl_clut_p))
             {
               fl_clut_p = GFX_MGR02_AMBER_REMAP_TCFLASH(fl_clut_p);
             }
              IRIS_API_CHECK(ret, mmlGdcSmAssignClut(p_win_data_SP->surf,MML_GDC_SURF_CLM_INDEX_RGB,(UINT32)fl_elem_clut_SP->CLUTsize,MML_GDC_SURF_CLF_R8G8B8,fl_clut_p));
              IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_CLUTBITPERPIXEL, (UINT32)0x18));
              IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_CLUTCOLORBITS,   (UINT32)0x08080800));
              IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_CLUTCOLORSHIFT,  (UINT32)0x00081000)); 
          }
          #endif
        }
      }
      if(fl_invisible==FALSE)
      {
          hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
          if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))			  
          {
          #if (GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0)     
            GFX_MGR02_IMAGE_DYN_PROPERTY const * fl_image_dyn_property_SP= &l_layer_anim_data_SP->image_prop[fl_obj_id];
            p_win_data_SP->win_colour = fl_image_dyn_property_SP->fg_color;
          #endif 
          }
          else
          {
          #if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0  
            GFX_MGR02_IMAGE_PROPERTY const * fl_image_const_prop_SP = &lc_img_const_property_S[fl_obj_id];
            p_win_data_SP->win_colour = fl_image_const_prop_SP->fg_color;
          #endif
          }
          hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP,(UINT32)MML_GDC_DISP_BLEND_SOURCE_MULTIPLY_ALPHA);
          if((p_win_data_SP->win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) != (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) 
          {
            IRIS_API_CHECK(ret, mmlGdcDispWinSetSurface(p_win_data_SP->win, (UINT32)MML_GDC_DISP_BUFF_TARGET_COLOR_BUFF,p_win_data_SP->surf));
          }
          p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
      }
      #ifdef GFX02_DEBUG_INFO
      printf("Build Image  -- win=%X, Surf=%X\n", p_win_data_SP->win,p_win_data_SP->surf);
      #endif
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
 ** Created:          14-Sep-2014 by SSIGAMAN.
 **==========================================================================*/
static void hmi_gfx_mgr02_build_fill(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, UINT32 p_obj_id, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
    GFX_MGR02_IAREA_DATA           fl_elem_area_S={(SINT16)0,(SINT16)0,(UINT16)0,(UINT16)0};
    #if GFX_MGR02_NUM_FILL_INSTANCES > 0
    GFX_MGR02_FILL_DEF_T  const * fl_fill_desc_SP;
    #endif
    UINT32                       fl_invisible = FALSE;
    SINT32 ret= MML_OK;
    UINT32 fl_rgba_u32;
    #if GFX_MGR02_NUM_FILL_INSTANCES > 0
    fl_fill_desc_SP  = &lc_fill_layer_def_S[p_elem_list_SP->base_id];
    #endif
    if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
    {
    #if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
         UINT32  fl_obj_id   = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
         GFX_MGR02_FILL_DYN_PROPERTY  const * fl_fill_anim_prop_SP = &l_layer_anim_data_SP->fill_prop[fl_obj_id];
         UINT32 fl_temp;
         fl_temp = (fl_fill_anim_prop_SP->color>>24U); /*get alpha value of the fill colour*/
         fl_temp = ((fl_temp* fl_fill_anim_prop_SP->alpha)/(UINT32)255);
         fl_temp = (fl_temp <<24U);
         p_win_data_SP->win_colour   = (fl_fill_anim_prop_SP->color<<8U);/*AARRGGBB format*/
         p_win_data_SP->win_colour   = (p_win_data_SP->win_colour>>8U);
         p_win_data_SP->win_colour  |= fl_temp;
         fl_elem_area_S.height		 = fl_fill_anim_prop_SP->dim.height;
         fl_elem_area_S.width        = fl_fill_anim_prop_SP->dim.width;
    #endif
    }
    else
    {
     #if GFX_MGR02_NUM_FILL_INSTANCES > 0
         p_win_data_SP->win_colour   = fl_fill_desc_SP->color;
         fl_elem_area_S.height		 = fl_fill_desc_SP->dim.height;
         fl_elem_area_S.width        = fl_fill_desc_SP->dim.width;
     #endif
    }
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
    fl_elem_area_S.x      = (SINT16)p_win_data_SP->win_prop.topLeftX;
    fl_elem_area_S.y      = (SINT16)p_win_data_SP->win_prop.topLeftY;
    if(hmi_gfx_mgr02_context_combine_clip(&p_win_data_SP->clip,(GFX_MGR02_IAREA_DATA const *)&fl_elem_area_S) == FALSE)
    {
      p_win_data_SP->win_prop.topLeftX = (UINT32)p_win_data_SP->clip.sx;
      p_win_data_SP->win_prop.topLeftY = (UINT32)p_win_data_SP->clip.sy;
      p_win_data_SP->win_prop.width    = (UINT32)p_win_data_SP->clip.ex;
      p_win_data_SP->win_prop.width   -= (UINT32)p_win_data_SP->clip.sx;
      p_win_data_SP->win_prop.height   = (UINT32)p_win_data_SP->clip.ey;
      p_win_data_SP->win_prop.height  -= (UINT32)p_win_data_SP->clip.sy;
    }
    else
    {
      fl_invisible =TRUE;
    }
    #else
    if(fl_invisible==FALSE)
    {
      p_win_data_SP->win_prop.width = (UINT32)fl_elem_area_S.width;
      p_win_data_SP->win_prop.height =(UINT32)fl_elem_area_S.height;
    }
    GFX_MGR02_UNUSED_VAR(fl_elem_area_S.x);
    GFX_MGR02_UNUSED_VAR(fl_elem_area_S.y);
    #endif
    if(fl_invisible==FALSE)
    {
        hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
        IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(p_win_data_SP->surf));
        IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf,
                                               p_win_data_SP->win_prop.width, 
                                               p_win_data_SP->win_prop.height,
                                               MML_GDC_SURF_FORMAT_R8G8B8A8, 
                                                             (void *)0, 
                                                             (UINT32)0));

        fl_rgba_u32 = p_win_data_SP->win_colour;
        fl_rgba_u32 = fl_rgba_u32<<8U;                  /*Remove Alpha content*/
        fl_rgba_u32 |= (p_win_data_SP->win_colour>>24U);/*Now added the colour with Alpha Content to get RRGGBBAA format */

        IRIS_API_CHECK(ret, mmlGdcDispWinSetBlendMode(p_win_data_SP->win, MML_GDC_DISP_BLEND_GLOBAL_ALPHA|MML_GDC_DISP_BLEND_SOURCE_MULTIPLY_ALPHA));
        IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute( p_win_data_SP->win,MML_GDC_DISP_WIN_ATTR_COLOR,fl_rgba_u32));
        IRIS_API_CHECK(ret, mmlGdcDispWinSetSurface(p_win_data_SP->win, (UINT32)MML_GDC_DISP_BUFF_TARGET_COLOR_BUFF, p_win_data_SP->surf));
        p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
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
 ** Created:          21-Aug-2014 by NKRISHN9
 ** Updated:          21-Aug-2014 by NKRISHN9
 **==========================================================================*/
static void hmi_gfx_mgr02_build_widget(GFX_MGR02_WINDOW_DATA_T * p_win_data_SP, GFX_MGR02_ELEM_LIST_T const * p_elem_list_SP, UINT32 p_layer_index)
{
   GFX_MGR02_WIDGET_DEF_T const * fl_widget_desc_SP;
   GFX_MGR02_IMAGE_DEF_T  const * fl_image_desc_SP;
   GFX_MGR02_CONTEXT_GB_T         fl_build_elem_S;

   UINT32   fl_clear_buffer          = FALSE;
   UINT32   fl_clear_color           = 0UL;
   UINT32   fl_element_change_status ;
   UINT32   fl_pix_format;
   UINT32   fl_obj_id;
   MM_ERROR ret = MML_OK;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   GFX_MGR02_VISIBLE_AREA         fl_elem_clip_S;
   SINT32                         fl_start_offset;
   UINT32                         fl_bpp = 0UL;
   UINT32                         fl_buff_offset = 0UL;
#endif

   fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list_SP->base_id];

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
    
   fl_obj_id = GFX_MGR02_GET_OBJ_ID(p_elem_list_SP->obj_id);
   fl_build_elem_S.area.width  = fl_image_desc_SP->width;
   fl_build_elem_S.area.height = fl_image_desc_SP->height;
   fl_build_elem_S.fb_format   = fl_widget_desc_SP->fb_format;
   fl_pix_format = hmi_gfx_mgr02_amber_get_wdg_pix_format(fl_build_elem_S.fb_format); 

   if(GFX_MGR02_IS_DYNAMIC_PROP(p_elem_list_SP->obj_id))
   {
   #if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
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
   #endif
   }
   else
   {
   #if GFX_MGR02_NUM_SWDG_INSTANCES > 0
      fl_build_elem_S.area.x = lc_swdg_const_property_S[fl_obj_id].coord.x;
      fl_build_elem_S.area.y = lc_swdg_const_property_S[fl_obj_id].coord.y;
	  p_win_data_SP->win_colour = lc_swdg_const_property_S[fl_obj_id].fg_color;
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
            fl_start_offset = (p_win_data_SP->clip.sx - (SINT32)p_win_data_SP->win_prop.topLeftX);
            if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->width))
            {
               fl_bpp          = hmi_gfx_mgr02_get_bpp(fl_pix_format);
               fl_buff_offset  = ((fl_bpp * (UINT32)fl_start_offset)>>3U);
               fl_start_offset = (p_win_data_SP->clip.sy - (SINT32)p_win_data_SP->win_prop.topLeftY);
               if((fl_start_offset >= 0) && (fl_start_offset < (SINT32)fl_image_desc_SP->height))
               {
                  fl_buff_offset += ((UINT32)fl_start_offset * ((fl_bpp * fl_image_desc_SP->width)>>3U));
                  p_win_data_SP->win_prop.topLeftX = (UINT32)p_win_data_SP->clip.sx;
                  p_win_data_SP->win_prop.topLeftY = (UINT32)p_win_data_SP->clip.sy;
                  p_win_data_SP->win_prop.width    = (UINT32)p_win_data_SP->clip.ex;
                  p_win_data_SP->win_prop.width   -= (UINT32)p_win_data_SP->clip.sx;
                  p_win_data_SP->win_prop.height   = (UINT32)p_win_data_SP->clip.ey;
                  p_win_data_SP->win_prop.height  -= (UINT32)p_win_data_SP->clip.sy;
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
         fl_build_elem_S.fb_target  = GFX_MGR02_TARGET_AMBER;
         #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
         fl_build_elem_S.pe_sync    = l_disp_comp[p_layer_index].gpu_sync;
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
         /* dirty area check true for mask widget and normal widget */
         fl_build_elem_S.dirty_area = TRUE;
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
		 
         if((fl_updated != FALSE)||( p_win_data_SP->render_buffer != fl_build_elem_S.render_buffer)||(NULL == p_win_data_SP->win))
         {
            p_win_data_SP->render_buffer = fl_build_elem_S.render_buffer;
            IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(p_win_data_SP->surf));
          #if defined(GFX_MGR02_CLIPPED_WIDGETS) 
            if((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)||
               (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height))
            {
            #ifdef GFX02_DEBUG_INFO
               printf("Offset=%d, Addr=%X\n",fl_buff_offset,fl_build_elem_S.render_buffer);
            #endif
               fl_buff_offset += (UINT32)fl_build_elem_S.render_buffer;
               if(fl_pix_format == MML_GDC_SURF_FORMAT_A6R6G6B6)
               {
                    IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                             p_win_data_SP->win_prop.width, 
                                                             p_win_data_SP->win_prop.height, 
                                                             MML_GDC_SURF_FORMAT_R8G8B8A8, 
                                                             (void *)fl_buff_offset, 
                                                             (UINT32)0));                  
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORBITS,  (UINT32)0x06060606));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x120c0600));

               }
               else
               {

                   IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                          p_win_data_SP->win_prop.width,
                                                          p_win_data_SP->win_prop.height,
                                                          (MML_GDC_SURF_FORMAT)fl_pix_format,
                                                          (void *)fl_buff_offset,
                                                          (UINT32)0));
               }
               IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_WIDTH, p_win_data_SP->win_prop.width));
               IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_HEIGHT,p_win_data_SP->win_prop.height));
               IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_STRIDE,((fl_image_desc_SP->width * fl_bpp)+7UL)>>3U));
            }
            else
         #endif
            {
               if(fl_pix_format == MML_GDC_SURF_FORMAT_A6R6G6B6)
               {
                    IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                             p_win_data_SP->win_prop.width, 
                                                             p_win_data_SP->win_prop.height, 
                                                             MML_GDC_SURF_FORMAT_R8G8B8A8, 
                                                             (void *)fl_build_elem_S.render_buffer,
                                                             (UINT32)0));                  
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORBITS,  (UINT32)0x06060606));
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x120c0600));

               }
               else
               {
                   IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf, 
                                                          p_win_data_SP->win_prop.width,
                                                          p_win_data_SP->win_prop.height,
                                                         (MML_GDC_SURF_FORMAT)fl_pix_format,
                                                         (void *)fl_build_elem_S.render_buffer,
                                                         (UINT32)0));
               }
            }
            hmi_gfx_mgr02_create_window(p_win_data_SP, p_layer_index);
            hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP, (UINT32)MML_GDC_DISP_BLEND_NONE);
         #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
            l_disp_comp[p_layer_index].gpusync_flag =(UINT8)1;
         #endif   
            IRIS_API_CHECK(ret, mmlGdcDispWinSetSurface(p_win_data_SP->win, 
                                                      (UINT32)MML_GDC_DISP_BUFF_TARGET_COLOR_BUFF,
                                                      p_win_data_SP->surf));
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
            hmi_gfx_mgr02_set_blendmode(p_win_data_SP, fl_image_desc_SP, (UINT32)MML_GDC_DISP_BLEND_NONE);
            IRIS_API_CHECK(ret, mmlGdcDispWinSetSurface(p_win_data_SP->win, 
                                                      (UINT32)MML_GDC_DISP_BUFF_TARGET_COLOR_BUFF,
                                                      p_win_data_SP->surf));
            p_win_data_SP->win_sts = GFX_MGR02_AMBER_WIN_UPDATED;
           }
            GFX_MGR02_UNUSED_VAR(fl_pix_format);
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
            IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(p_win_data_SP->surf));
         #if defined(GFX_MGR02_CLIPPED_WIDGETS) 
            if((p_win_data_SP->win_prop.width != fl_build_elem_S.area.width)||
               (p_win_data_SP->win_prop.height != fl_build_elem_S.area.height))
            {
            #ifdef GFX02_DEBUG_INFO
               printf("Offset=%d, Addr=%X\n", fl_buff_offset, p_win_data_SP->render_buffer);
            #endif
               fl_buff_offset += (UINT32)p_win_data_SP->render_buffer;
               IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf,
                                                      p_win_data_SP->win_prop.width,
                                                      p_win_data_SP->win_prop.height,
                                                      (MML_GDC_SURF_FORMAT)fl_pix_format,
                                                      (void *)fl_buff_offset,
                                                      (UINT32)0));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_WIDTH, p_win_data_SP->win_prop.width));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_HEIGHT, p_win_data_SP->win_prop.height));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(p_win_data_SP->surf, MML_GDC_SURF_ATTR_STRIDE, ((fl_image_desc_SP->width * fl_bpp) + 7UL) >> 3U));
            }
            else
         #endif
            {
                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(p_win_data_SP->surf,
                                                      p_win_data_SP->win_prop.width,
                                                      p_win_data_SP->win_prop.height,
                                                      (MML_GDC_SURF_FORMAT)fl_pix_format,
                                                      (void *)p_win_data_SP->render_buffer,
                                                      (UINT32)0));
            }
            hmi_gfx_mgr02_create_window(p_win_data_SP,p_layer_index);
         }
      }
      else
      {
      }
   }
    GFX_MGR02_UNUSED_VAR(ret);
}
#endif /* GFX_MGR02_NUM_OF_SWDGS > 0 */
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_is_emergency_shutdown_req_active
 ** Visibility:       Global
 ** Description:      Returns the shutdown mode type.
 ** Invocation:       By 
 ** Inputs/Outputs:   l_gfx_mgr_shutdown_status
 ** Critical Section: None.
 ** Created:          05-Sep-2014
 ** Updated:          05-Sep-2014
 **==========================================================================*/
UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
   return (l_gfx_mgr_shutdown_status);
}
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_emergency_shutdown
 ** Visibility:       Global
 ** Description:      Sets the shutdown mode type.
 ** Invocation:       By 
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          05-Sep-2014
 ** Updated:          05-Sep-2014
 **==========================================================================*/
void hmi_gfx_mgr02_emergency_shutdown(void)
{
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_EMERGENCY;
}

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_normal_shutdown
 ** Visibility:       Global
 ** Description:      This function for Destroying the window in shutdown sequence.
 **                   
 ** Invocation:       By hmi_gfx_mgr02_context_shutdown()
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          10-Feb-2015 by SSIGAMAN
 ** Updated:          10-Feb-2015 by SSIGAMAN
 **==========================================================================*/
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
                if((l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win_prop.features & (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT) == (UINT32)MML_GDC_DISP_FEATURE_STREAM_INPUT)
                {
                  /* Switch the window Off for Brontes Stream */
                  IRIS_API_CHECK(ret, mmlGdcDispWinSetAttribute(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win, MML_GDC_DISP_WIN_ATTR_DISABLE, (UINT32)MM_TRUE));
                  IRIS_API_CHECK(ret, mmlGdcDispWinCommit(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win));
                  IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win));
                }
                else
                {
                  IRIS_API_CHECK(ret, mmlGdcDispWinDestroy(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win));
                }
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].win = NULL;

            }

            if(l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf !=NULL)
            {
                IRIS_API_CHECK(ret, mmlGdcSmDeleteSurfaceObjects((MM_U32)1, &l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf));
                l_disp_comp[fl_display_index_U8].window_data[fl_cur_window_U8].surf = NULL;
            }
        }
        #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
        if(l_disp_comp[fl_display_index_U8].gpu_sync !=NULL)
        {
            IRIS_API_CHECK(ret, mmlGdcSyncDelete((MM_U32)1, &l_disp_comp[fl_display_index_U8].gpu_sync));
            l_disp_comp[fl_display_index_U8].gpu_sync = NULL;
        }
        #endif
        if(l_disp_comp[fl_display_index_U8].disp_sync !=NULL)
        {
            IRIS_API_CHECK(ret, mmlGdcSyncDelete((MM_U32)1, &l_disp_comp[fl_display_index_U8].disp_sync));
            l_disp_comp[fl_display_index_U8].disp_sync = NULL;
        }
    }
    #if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
    GFX_MGR02_3D_MDL_UNINITIALIZE;
    #endif
#if GFX_MGR02_NUM_LAYERS>1		
    for (fl_display_index_U8 = (UINT8)0; fl_display_index_U8 < (UINT8)GFX_MGR02_NUM_LAYERS; fl_display_index_U8++)
#else
    fl_display_index_U8 = (UINT8)0;	
#endif		
    {
        if (l_disp_comp[fl_display_index_U8].display != NULL)
        {
            IRIS_API_CHECK(ret, mmlGdcDispCloseDisplay(l_disp_comp[fl_display_index_U8].display));
            l_disp_comp[fl_display_index_U8].display = NULL;
        }
        l_disp_comp[fl_display_index_U8].num_of_visible_elements =(UINT8)0;
        l_cur_num_of_elements[fl_display_index_U8] = (UINT8)0;
        l_content_ready_ondisplay =(UINT32)0;
    }
     IRIS_API_CHECK(ret, mmlGdcSysUninitializeDriver());

    if(NULL != l_vInstrBuffer)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_vInstrBuffer);
        l_vInstrBuffer = NULL;
    }
    #if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0)|| (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))))	
    if(NULL != l_alpha_buffer)
    {
        hmi_gfx_mgr02_amber_mem_mgmt_free(l_alpha_buffer);
        l_alpha_buffer = NULL;
    }
	
	hmi_gfx_mgr02_context_free_amber_pathbuffers();
    #endif

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
 ** Created:          20-Dec-2015 by SSIGAMAN
 ** Updated:          20-Dec-2015 by SSIGAMAN
 **==========================================================================*/
static GFX_MGR02_DRIVER_BUSY_STATUS_T hmi_gfx_mgr02_amber_driver_status(UINT32 p_layer_ID_U8)
{
   SINT32 ret;
   GFX_MGR02_DRIVER_BUSY_STATUS_T fl_return_value=GFX_MGR02_DRIVER_FREE;

    #if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)&& defined(GFX_MGR02_AMBER_USE_MML_PE_SYNC))
    /*Check the pixel engine sync status*/
    ret = mmlGdcSyncWait(l_disp_comp[p_layer_ID_U8].gpu_sync, 0);
    if(MML_ERR_GDC_SYNC_TIMEOUT == ret)
    {
      fl_return_value = GFX_MGR02_DRIVER_BUSY_IRIS_ENGINE;
    }
    else
    #endif
    {
      /*Check whether the all active windows are commited?*/
        ret = mmlGdcSyncWait(l_disp_comp[p_layer_ID_U8].disp_sync, 0);
        if (MML_ERR_GDC_SYNC_TIMEOUT == ret)
        {
           fl_return_value = GFX_MGR02_DRIVER_BUSY_WINDOW_COMMIT;
        }	
    }

    l_gfx_mgr02_amber_driver_status = fl_return_value;
    return(fl_return_value);
}

#ifdef GFX_MGR02_AMBER_DRIVER_RUNTIME_RECOVERY
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_get_amber_driver_cur_status
 ** Visibility:       Global
 ** Description:      Returns the current amber driver status
 **                   
 ** Invocation:       By Layout
 ** Inputs/Outputs:   Output=0-> Free.
 **                   Output=1-> Busy.
 ** Critical Section: None.
 **==========================================================================*/
UINT32 hmi_gfx_mgr02_get_amber_driver_cur_status(void)
{
    UINT32 fl_amber_driver_status_u32 = (UINT32)FALSE;
    if(l_gfx_mgr02_amber_driver_status != GFX_MGR02_DRIVER_FREE)
    {
        fl_amber_driver_status_u32 = (UINT32)TRUE;
    }
    else
    {
    }
    return (fl_amber_driver_status_u32);
}
#endif

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_driver_busy
 ** Visibility:       Global
 ** Description:      This function will be used to find the busy status of the 
 **                   Amber Driver.
 **                   
 ** Invocation:       By Application
 ** Inputs/Outputs:   Output=0-> Free.
 **                   Output=1-> Busy.
 ** Critical Section: None.
 ** Created:          12-Jan-2016 by SSIGAMAN
 ** Updated:          12-Jan-2016 by SSIGAMAN
 **==========================================================================*/
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

/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_set_disp_bgcolor
 ** Visibility:       Global
 ** Description:      This function is used to set the BG colour of the Display.
 **                   
 ** Invocation:       By Application
 ** Inputs/Outputs:   Tndex of the Display , BG colour
 ** Critical Section: None.
 ** Created:          08-Dec-2015 by SSIGAMAN
 ** Updated:          08-Dec-2015 by SSIGAMAN
 **==========================================================================*/

void hmi_gfx_mgr02_amber_set_disp_bgcolor(UINT8 p_disp_index_u8, UINT32 p_bg_color_u32)
{
	
    if(p_disp_index_u8 < (UINT8)GFX_MGR02_NUM_LAYERS)
    {
      l_disp_comp[p_disp_index_u8].bg_colour = p_bg_color_u32;
    }
}
#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_get_runtime_widget_ptr
 ** Visibility:       Global
 ** Description:      Interface to get pointer of l_runtime_wdg_image_layer_def_S .
 **                   
 ** Invocation:       By hmi_gfx_mgr02_context.c
 ** Inputs/Outputs:   
 ** Critical Section: None.
 ** Created:          28-Jul-2017 by CSAKTHIV
 ** Updated:          
 **==========================================================================*/

GFX_MGR02_IMAGE_DEF_T * hmi_gfx_mgr02_amber_get_runtime_widget_ptr(UINT16 p_img_id)
{
    return &l_runtime_wdg_image_layer_def_S[p_img_id];	
}
#endif
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_amber_get_disp_content_status
 ** Visibility:       Global
 ** Description:      Interface to get display content status .
 **                   
 ** Invocation:       By hmi_gfx_mgr02_layout.c
 ** Inputs/Outputs:   l_content_ready_ondisplay
 **                   0 -> default.
 **                   1 -> Display active with background colour set.
 **                   2 -> Display active with active layer alongwith 
 **                        background colour set.
 ** Critical Section: None.
 **==========================================================================*/

UINT32 hmi_gfx_mgr02_amber_get_disp_content_status(void)
{
    return(l_content_ready_ondisplay);
}

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
 ** CMS Rev 1.54      27-Feb-2020    ssigaman
 ** 1415553: [HBC]: Blank screen is shown in Normal mode
 ** Window creation and buffer update is done in case the window handle is null and 
 ** if it is not having a valid buffer due to window hierarchy change.
 **
 ** CMS Rev 1.53      31-Aug-2018     ADEVI
 ** 1149379: Capture Video Driver for KeplerII
 **
 ** CMS Rev 1.52      11-Oct-2017    KKUBENDI
 ** 968271, 968272 : PR Defect Fixes
 **
 ** CMS Rev 1.51      19-Sep-2017    KKUBENDI
 ** 939889: Mazda J59: Kepler2- Graphics building in HRAM and transfer to VRAM to display
 **
 ** CMS Rev 1.50      1-Sep-2017    CSAKTHIV
 ** 944993: Dirty Area Enabling lead to deallocation of memory
 **
 ** CMS Rev 1.49      6-Sep-2017    ADEVI
 ** 948804: Amber driver run time recovery implementation.
 **
 ** CMS Rev 1.48      1-Sep-2017    SSIGAMAN
 ** 912798: Different FrameBuffer configuration support in GDT required
 ** ARGB6666 and YUV422 widget rendering formats added.
 **
 ** CMS Rev 1.47      16-Aug-2017    SSIGAMAN
 ** 908966: Static allocation of VRAM required.
 ** Modified the files inorder to support user to allocate the required memories
 ** widget rendering and memory required for Draw engine and widget warping.
 **
 ** CMS Rev 1.46     28-Jul-2017    CSAKTHIV
 ** RTC 919137: Alpha value not reflecting for fill.
 ** 
 ** CMS Rev 1.45     25-Jul-2017    SSIGAMAN
 ** RTC 919137: Alpha value not reflecting for fill.
 ** Alpha animation change is considered in the code.
 **
 ** CMS Rev 1.44     29/06/17    SSRINI19
 ** 880883 : GM-CHUD QAC MISRA additional warning fixes
 
 ** CMS Rev 1.43     04-April-2017    SSIGAMAN
 ** 816744: Update GDT to allow configurable warping data
 ** Supported to have warping coordinate bufferin internal flash.
 ** Offset added as like for images.
 ** 
 **  CMS Rev 1.42    15-Mar-2017   SSRINI19
 **  RTC 811782 - Compiler warning fixes for GM-CHUD program 
 **  Fix: In hmi_gfx_mgr02_manage_layers_cp_child () variable fl_prev_num_of_layers's type is 
 **  changed to MML_GDC_DISP_LAYER
 **  In hmi_gfx_mgr02_manage_layers_cp_child () variable fl_layer_desc_SP's duplicate declarations 
 **  are removed
 **   
 ** CMS Rev 1.41      17-Mar-2017    SSIGAMAN
 ** 827183: BAIC: Elements missing in close Animation stage.
 ** The num_of_planes_used is compared with max_num_of_planes allocated using lessthan earlier.
 ** Due to this, 5th planes contents are not get considered in manage layers function.
 ** Now corrected it by comparing with lessthan or equal symbol.
 **
 ** CMS Rev 1.40      09-Jan-2017    SSIGAMAN
 **  778496: Amber:Compilation Errors based on elements added in the GDT design.
 ** Conditional Compilation macros added.
 **
 ** CMS Rev 1.39      06-Jan-2017    SSIGAMAN
 ** 774563: Got Compilation Error if there is no image element with Animation=FALSE.
 ** lc_img_const_property_S is accessed only if GFX_MGR02_NUM_SIMAGE_INSTANCES is
 ** greater than 0 to avoid this error.
 ** 
 ** CMS Rev 1.38      05-Jan-2017    SSIGAMAN
 ** 776797: Iris Driver migration to S6J3200-2DGraphicsDriver-v2.0.0-beta
 ** Updated the Iris Driver Version to v2.0 beta. 
 ** The window sync and wincommit APIs are replaced with Display commit and sync APIs. 
 **  
 ** CMS Rev 1.37      22-DEC-2016    SSIGAMAN
 ** 758383: BAIC: Image which is out of display area is not detected as invisible item
 ** Condition added in the hmi_gfx_mgr02_manage_layers_cp_child() to find 
 ** the height and width of widget and image. If it is 0 means, 
 ** element validity is set as FALSE.
 **
 ** CMS Rev 1.36      16-DEC-2016    EMANOJ1
 ** Faraday Future - Touch object auto selection does not work (RTC : 767349)
 ** Updates due to function prototype change
 **
 ** CMS Rev 1.35     15-Dec-2016    SSIGAMAN
 ** 766753: BAIC:Provide option to allocate memory for frame buffer in HRAM
 ** The API mmlGdcVideoAlloc() replaced with hmi_gfx_mgr02_amber_mem_mgmt_malloc()
 ** and mmlGdcVideoFree() with hmi_gfx_mgr02_amber_mem_mgmt_free().
 **
 ** CMS Rev 1.34     21-Nov-2016    SSIGAMAN
 ** RTC 747872: Display Flickering in BAIC 
 ** Width and Height of the window marked as Dirty always earlier which is
 ** Corrected now. 
 **
 ** CMS Rev 1.33     18-July-2016    SSIGAMAN
 ** RTC 639228: 
 ** PR Comments Fix. The alpha and path buffer variables are used within the 
 ** GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0 conditional check.
 **
 ** CMS Rev 1.32     5-May-2016    SSIGAMAN
 ** RTC 628373: Freetype text rendering: 1st character is missing in the 
 **             1st rendering string of the context if morethan 1 pixel engine context used.
 ** Changes are done in such a manner that the pixel engine context to have their own path buffers.
 **
 ** CMS Rev 1.31     11-May-2016    SSIGAMAN
 ** 592820: Turing Coverity Warning Fix for ui.core.gdt
 **
 ** CMS Rev 1.30     4-May-2016    SSIGAMAN
 ** RTC 571865: 
 ** The structure member da_redraw in GFX_MGR02_CONTEXT_GB_T is removed
 ** as per PR comments.
 **
 ** CMS Rev 1.29      29-Mar-2016    SVIKRAM
 ** 521269: Compiler warnings fix
 **
 ** CMS Rev 1.28      24-Mar-2016    SVIKRAM
 ** 521380: Coverity issue fix
 **
 ** CMS Rev 1.27     29-Feb-2016    SSIGAMAN
 ** 520770: Amber: Alpha animation is not working properly
 ** Defect: The variable l_gfx_mgr02_amber_element_dirty_u8 not updated as dirty
 ** when the alpha value changes for the merge widget.
 ** Fix: The corresponding window is made as dirty on the value change.
 **      Also the window colour updation for image corrected based on the anim prop.
 **
 ** CMS Rev 1.26     19-Feb-2016    SSIGAMAN
 ** 521152: Amber: Not able to build more than 2 priority levels of screens at a time
 ** Defect:The isse is when adding the different priority screens one by one; 
 ** the window reordering is happening and it got missed to update.
 ** Fix: On windoe reordering the active windows are marked as Dirty in order to rebuild.
 **
 ** CMS Rev 1.25     27-Jan-2016    SSIGAMAN
 ** 508330: Don't restrict the dithering to 16Bit and 18Bit even 24Bit shall be considered 
 ** Dithering enabled for RGB888 format.        
 ** 
 ** CMS Rev 1.24     25-Jan-2016    SSIGAMAN
 ** 443667: Each call to hmi_gfx_mgr02_layout_build_screen() takes about 2msec
 **         even if no change in graphics
 ** Window commit and element rendering APIs called only they is a change in 
 ** the elements.
 **
 ** CMS Rev 1.23     12-Jan-2016    SSIGAMAN
 ** RTC : 489838
 ** Driver Busy status API updated to share busy or free alone.
 **
 ** CMS Rev 1.22     11-Jan-2016    VTODOROV/SSIGAMAN
 ** RTC :
 ** Warping Changes Integrated.
 **
 ** CMS Rev 1.21     11-Jan-2016    SSIGAMAN
 ** RTC :497416
 ** Added Dual Display Support.
 **
 ** CMS Rev 1.20     20-Dec-2015    SSIGAMAN
 ** RTC :486376
 ** Added Support to render the Keep Layer widget element within Keep Layer widget.
 **
 ** CMS Rev 1.19     20-Dec-2015    SSIGAMAN
 ** RTC :486359
 ** Added API for checking the Driver Status whether Busy or Free.
 **
 ** CMS Rev 1.18     25-Nov-2015    SSIGAMAN
 ** RTC :467621
 ** The previous used Window is destroyed if the feature is different from current active windows
 ** to solve not creating the window with intended feature.
 **
 ** CMS Rev 1.17     25-Nov-2015    SSIGAMAN
 ** RTC :467638
 ** Iris Blit engine will able to access the image stored in the internal flash
 ** through the virtual address only. If it was accessed it will through the NMI exception.
 ** So, the check is introduced and if it is in internal flash then the OFFSET is added to 
 ** passed address.
 **
 ** CMS Rev 1.16     25-Nov-2015    SSIGAMAN
 ** RTC :467618
 ** 3D element width and height set by user got modified in 
 ** hmi_gfx_mgr02_get_image_layer_area(). So, corrected it.
 **
 ** CMS Rev 1.15     6-Nov-2015    SSIGAMAN
 ** RTC :
 ** Issue: Clip for Keep Layer widget is not working for some combination and the element
 ** outside the boundry also got displayed.
 ** Rootcause: Clip related functions not get executed when clip's sx and widows top left
 ** are same. So, the windows properties are not updated properly to clip the elements.
 **
 ** CMS Rev 1.14     3-Nov-2015    SSIGAMAN
 ** RTC 456457:
 ** Dirty Area Redraw is applicable for merge widgets with CLIP=TRUE.
 **
 ** CMS Rev 1.13     02-Nov-2015   SSIGAMAN
 ** Ref RTC# 437002.
 ** Updated the frame buffer formats for A8, A4, A2, A1, 8BPP, 4BPP, 2BPP and 1BPP
 ** as per review recommendation for Amber platform
 **
 ** CMS Rev 1.12     27-Oct-2015   SSIGAMAN
 ** Ref RTC# 443664:
 ** The Fractional window allocation is by default as per the user design in the GDT Design. 
 ** In this case Fractional layer content overlap is allowed.
 ** If the the macro GFX_MGR02_AUTO_ALLOCATE_FRACTIONAL_LAYER is defined means, 
 ** the Graphics manager will take control of deciding the window allocation based on 
 ** the element property.
 **
 ** CMS Rev 1.11     13-Oct-2015   SSIGAMAN
 ** Ref RTC# 437002.
 ** Add support for 8BPP frame buffer for Amber platform
 ** 
 ** CMS Rev 1.10     12-Oct-2015   CSAKTHIV
 ** Ref RTC# 428203.
 ** Integrating changes from CES demo changes done by valdimir
 **
 ** CMS Rev 1.9     29-Sep-2015   SSIGAMAN
 ** Ref RTC# 428197.
 ** Added MML_GDC_DISP_BLEND_SOURCE_MULTIPLY_ALPHA to the blend mode to Alpha mask images.
 ** 
 ** CMS Rev 1.8     24-Sep-2015   CSAKTHIV
 ** Ref RTC# 428250.
 ** Add a support in Gfx manger to to set Background colour for the display.
 ** 
 ** CMS Rev 1.7     15-Sep-2015   SSIGAMAN
 ** Ref RTC# 370662.
 ** Changes are done to make Alpha and Path Buffer of the Draw engine as configurable item.
 ** Also done some improvement activity to resolve compiler errors.
 **	Fill functionality added.
 **
 ** CMS Rev 1.6     26-Aug-2015   SSIGAMAN
 ** Ref RTC# 408667.
 ** Added the compression size to the assign buffer API for 2BPP and 4BPP index format.
 **
 ** CMS Rev 1.5     24-Aug-2015   SSIGAMAN
 ** Ref RTC# 405395.
 ** Changes are made to support Indexed image rendering in Amber platform.
 **
 ** CMS Rev 1.4      27-August-2015    CSAKTHIV
 ** Ref RTC 326037 3D Brontes implementation.
 **
 ** CMS Rev 1.3      05-August-2015    VTODOROV
 ** Emergency shutdown has been added.
 **
 ** CMS Rev 1.2      12-July-2015   CSAKTHIV
 ** Ref RTC# 371941
 ** Utilization of available Fractional plane window.
 ** 
 ** CMS Rev 1.1      02-Apr-2015   EMANOJ1
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
 ** CMS Rev 1.0      05-Sep-2014   SSIGAMAN
 ** Creation.
 **==========================================================================*/

#ifdef  __cplusplus
}
#endif
#endif /* #if defined(GFX_MGR02_AMBER) */

