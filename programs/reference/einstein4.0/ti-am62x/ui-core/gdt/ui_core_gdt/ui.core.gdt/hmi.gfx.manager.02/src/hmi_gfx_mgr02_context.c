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
 ** Name:           hmi_gfx_mgr02_context.c
 **
 ** Description:    
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_CONTEXT_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include <math.h>
#include <float.h>
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_generic.h"
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
  #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))
#include "hmi_gfx_mgr02_font.h"
    #include "hmi_gfx_mgr02_text.h"
  #endif
#endif

#if defined(GFX_MGR02_OPEN_GL)
 #if defined(WIN32)
  #include <stdio.h>
  #include <windows.h>
  #include <TCHAR.h>
 #endif
  #include "EGL/egl.h"
  #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
    #include <GLES2/gl2.h>
  #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
    #include <GLES/gl.h>
  #else
    #error "GL ES version not supported."
  #endif
#endif

#if defined(GFX_MGR02_FUJITSU)
  #if ((GFX_MGR02_IRIS_INSTR_BUFF_SIZE & 3) != 0)
    #error "Memory should be word aligned!."
  #endif
#endif

#if defined(GFX_MGR02_OPEN_VG)
 #include "hmi_gfx_mgr02_ovglib.h"
 #include "VG/openvg.h"
 #include "VG/vgu.h"
 #include "VG/vgext.h"
 #include "EGL/egl.h"

 #ifdef GFX_MGR02_ENABLE_FSL_EXTENTIONS
  #include "EGL/eglext.h"
  #include "EGL/eglfsl.h"
  #ifdef HEAP_MONITOR
    #include "hmon.h"
  #endif
  #include "hmi_gfx_mgr02_reg.h"
  #include "graphics.h"
 #endif
#endif

#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
  #include "ncg_defs.h"
  #include "ncg_memory.h"
  #include "iodefine.h"
#endif

#ifdef GFX_MGR02_FUJITSU
#include "iris_drv.h"
#include "mml_gdc_display.h"
#include "panel_definition.h"
#include "sm_util.h"
#include "hmi_gfx_mgr02_irislib.h"
#include "hmi_gfx_mgr02_safety.h"
#endif

#ifdef GFX_MGR02_SOFTWARE
  #ifdef GFX_MGR02_USE_TIDSS
  #include "hmi_gfx_mgr02_tidss_dispif.h"
  #endif
#endif

#if defined (GFX_MGR02_AMBER) ||defined (GFX_MGR02_TRAVEO2)
#if defined (GFX_MGR02_AMBER)
#include "hmi_gfx_mgr02_amber.h"
#include "hmi_gfx_mgr02_amber_iris.h"
#endif
#if defined (GFX_MGR02_TRAVEO2)
#include "hmi_gfx_mgr02_tv2.h"
#include "hmi_gfx_mgr02_tv2_iris.h"
#include "hmi_gfx_mgr02_amber_iris.h"
#include "ut_compat.h"
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
    #include "fs_itype.h"
  #endif
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && 	\
    ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||  \
    (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2) || \
    (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)))
    #if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
      /* include the Shaper (wtle and harfbuzz) engine header file  */
      #include "hmi_gfx_mgr02_shape_engine.h"
    #endif
#endif
#endif

#if defined (GFX_MGR02_IMXRT)
#include "hmi_gfx_mgr02_imxrt.h"
#endif

#if defined(GFX_MGR02_AMBER_IRIS)
#include "hmi_gfx_mgr02_amber_iris.h"
#endif

#if defined(GFX_MGR02_IMXRT_PXP) || (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0))
#include "hmi_gfx_mgr02_imxrt_pxp.h"
#include "hmi_gfx_mgr02_imxrt_lcdif.h"
#if defined(GFX_STRING_CACHE_ENABLED)
#include "hmi_gfx_mgr02_cache.h"
#endif
#endif

#if defined(GFX_MGR02_VGLITE)
#include "hmi_gfx_mgr02_vglite.h"
#if (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0) && defined (GFX_MGR02_USE_EXT_FONT_ENGINE)
    #if (!defined(GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH)) || (GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH == 0)
        #error "define GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH with appropriate size in the hmi_gfx_mgr02.cfg file"    
    #endif
#endif
#endif

#if defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
#include "sm_util.h"
#include "ut_compatibility.h"
    #if defined(GFX_STRING_CACHE_ENABLED)
    #include "hmi_gfx_mgr02_cache.h"
    #endif
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))
#if defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
#include "hmi_gfx_mgr02_cache.h"
#endif
#if defined(GFX_MGR02_USER_DEFINED_MM)
#include "ftmodapi.h"
#endif
#endif

#if defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(__MQXOS__)
 #include "hmi_gfx_mgr02_driver_mqx.h"
#if defined(HMI_GFX_MGR02_ARCH04)
 #include "hmi_gfx_mgr02_fault.h"
#endif
#endif

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
  #define LAYER_1 0U
  #define LAYER_2 1U 
  extern NCGuint32 aui32NCGFrameMemHeap[NCG_FRAME_MEM_HEAP_SIZE/sizeof(NCGuint32)];
  NativeWindowType window_ctx[GFX_MGR02_NUM_LAYERS];
  NativePixmap front_ctx[GFX_MGR02_NUM_LAYERS];
  NativePixmap back_ctx[GFX_MGR02_NUM_LAYERS] ;
  UINT8 *ptr_ctx = 0;
  UINT32 l_source_address_ctx;
  UINT32 current_render_fb_addr_ctx;
  UINT32 l_front_buffer_address_ctx[GFX_MGR02_NUM_LAYERS];
  UINT32 l_back_buffer_address_ctx[GFX_MGR02_NUM_LAYERS];
  static const EGLint attr_list_Win[] =
  {
    EGL_COLORSPACE,     EGL_COLORSPACE_sRGB,
    EGL_RENDER_BUFFER,  EGL_BACK_BUFFER,
    /* end */
    EGL_NONE
  };
  /*
  ** Number of Frame buffers per layer.
  ** Maximum number of FB is 3, Min is 1
  */
  #define GFX_DRIVER_NUM_FB  (1U)
#elif defined( GFX_MGR02_DRIVER_SINGLE_FB)
  /*
  ** Number of Frame buffers per layer.
  ** Maximum number of FB is 3, Min is 1
  */
  #define GFX_DRIVER_NUM_FB  (1U)
#else
  /*
  ** Number of Frame buffers per layer.
  ** Maximum number of FB is 3, Min is 1
  */
  #define GFX_DRIVER_NUM_FB  (2U)
#endif

/*! attribute list for the window surface */

#ifdef WIN32
  #define GFX_MGR02_MAX_EGL_CONFIGS (1)
#elif defined(GFX_MGR02_FARADAY)
  #define GFX_MGR02_MAX_EGL_CONFIGS (5)
#else
  #define GFX_MGR02_MAX_EGL_CONFIGS (1)
#endif

typedef struct
{
   GFX_UINT frnt_id:2;
   GFX_UINT back_id:2;
   GFX_UINT last_id:2;
   GFX_UINT ready  :1;
   GFX_UINT active :1;
   union
   {
      GFX_UINT    val;
      struct
      {
         GFX_UINT    b_locked:1;  /* incates this buffer can be used or not               */
         GFX_UINT    b_update:1;  /* indicates this buffer has updates pending to display */
      }sts;
   }fb[GFX_DRIVER_NUM_FB];
   UINT16 client_id;
   void * fb_ptr[GFX_DRIVER_NUM_FB];
}GFX_MGR02_FB_INFO_T;

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)|| defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)|| defined(GFX_MGR02_IMXRT_PXP)
static void * hmi_gfx_mgr02_context_swap_fb(GFX_MGR02_FB_INFO_T * fl_fb_info_SP);
static UINT32 hmi_gfx_mgr02_context_find_next_fb(GFX_MGR02_FB_INFO_T * fl_fb_info_SP);
static void   hmi_gfx_mgr02_context_backfb_slock(GFX_MGR02_FB_INFO_T * fl_fb_info_SP, u_gx_flocal p_lock);
#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0) ||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
static void hmi_gfx_mgr02_context_widget_init(void);
#endif
#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
static void  hmi_gfx_mgr02_context_swap_buffers(u_gx_flocal p_layer_id);
#endif
#endif

#if defined(GFX_MGR02_OPEN_VG) && !defined(GFX_MGR02_RENESAS_OPENVG_LIB)
 static UINT32 context_ovg_pre_init(void);
 static UINT32 context_ovg_layer_init(UINT32 p_index);
#elif defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_RENESAS_OPENVG_LIB)
 static UINT32 context_ovg_pre_init(void);
 static UINT32 context_ovg_layer_init(UINT32 p_index);
#elif defined(GFX_MGR02_FUJITSU)
 static void context_fjt_pre_init(void);
 static UINT32 context_fjt_layer_init(UINT32 p_index);
#endif
#if defined(GFX_MGR02_SOFTWARE)
 static void context_swr_pre_init(void);
#endif
#if defined(GFX_MGR02_AMBER_IRIS)
 static void context_amber_iris_layer_init(UINT32 p_layer);
#endif
#if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT)
 static void context_imxrt_pxp_layer_init(UINT32 p_layer);
#endif
#if defined(GFX_MGR02_MONOTFT)
 static void hmi_context_monolib_pre_init(void);
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT) && (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_DIGITYPE)
static void context_ext_font_engine_initialize(void);
#endif
#endif


#if defined(GFX_MGR02_FUJITSU)
extern MML_GDC_SURF_FORMAT hmi_gfx_mgr02_irislib_get_disp_pix_format(u_gx_flocal p_pix_format);
#endif
#if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
extern void hmi_gfx_mgr02_ovg_text_context_initialize(void);
#endif

#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE))
static void hmi_gfx_mgr02_context_allocate_decompr_buffer(void);
static void hmi_gfx_mgr02_context_free_decompr_buffer(void);
#endif

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

static GFX_MGR02_CONTEXT_T   l_context_S;

#if defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)||defined(GFX_MGR02_VGLITE)
static GFX_MGR02_FB_INFO_T   l_fb_info_S[GFX_MGR02_NUM_LAYERS];
#endif /*#if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_FUJITSU)*/

#if defined(GFX_MGR02_OPEN_VG)
static EGLint     l_egl_surface_attrib[GFX_MGR02_NUM_LAYERS][5];
static EGLSurface l_egl_surface[GFX_MGR02_NUM_LAYERS][GFX_DRIVER_NUM_FB];
static EGLContext l_egl_context[GFX_MGR02_NUM_LAYERS];
static EGLDisplay dsp = EGL_NO_DISPLAY;
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB)
static EGLSurface l_egl_shared_surface;
static EGLContext l_egl_shared_context;
#endif

#if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0
static GFX_MGR02_FB_INFO_T l_dcu_fb_info_S[GFX_MGR02_NUM_DCU_OVG_WIDGETS];
static EGLContext          l_dcu_fb_context[GFX_MGR02_NUM_DCU_OVG_WIDGETS];
static EGLConfig           l_dcu_fb_config[GFX_MGR02_NUM_DCU_OVG_WIDGETS];
static UINT16              l_dcu_fb_width[GFX_MGR02_NUM_DCU_OVG_WIDGETS][GFX_DRIVER_NUM_FB];
static UINT16              l_dcu_fb_height[GFX_MGR02_NUM_DCU_OVG_WIDGETS][GFX_DRIVER_NUM_FB];
static EGLSurface          l_dcu_fb_surface[GFX_MGR02_NUM_DCU_OVG_WIDGETS][GFX_DRIVER_NUM_FB];
#endif

static EGLint const lc_config_attribs_argb8888[] =
{
   EGL_RED_SIZE,       8,
   EGL_GREEN_SIZE,     8,
   EGL_BLUE_SIZE,      8,
   EGL_ALPHA_SIZE,     8,
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
   EGL_ALPHA_MASK_SIZE, 8,
#else
   EGL_ALPHA_MASK_SIZE, 0,
#endif
#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
   EGL_SURFACE_TYPE,       EGL_WINDOW_BIT,
   EGL_RENDERABLE_TYPE,    EGL_OPENVG_BIT,
   EGL_NATIVE_VISUAL_TYPE, ( EGLint )NATIVE_ARGB8888,
   EGL_ALPHA_MASK_SIZE,    0,
#elif defined(GFX_MGR02_FARADAY)
   EGL_RENDERABLE_TYPE,EGL_OPENVG_BIT,
#else
   EGL_SURFACE_TYPE,   EGL_PBUFFER_BIT,
#endif
   EGL_NONE
};

static EGLint const lc_config_attribs_rgb565[] =
{
   EGL_RED_SIZE,       5,
   EGL_GREEN_SIZE,     6,
   EGL_BLUE_SIZE,      5,
   EGL_ALPHA_SIZE,     0,
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
   EGL_ALPHA_MASK_SIZE, 8,
#else
   EGL_ALPHA_MASK_SIZE, 0,
#endif
#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
   EGL_SURFACE_TYPE,       EGL_WINDOW_BIT,
   EGL_RENDERABLE_TYPE,    EGL_OPENVG_BIT,
   EGL_NATIVE_VISUAL_TYPE, ( EGLint )NATIVE_COLOR,
   EGL_ALPHA_MASK_SIZE,    0,
#elif defined(GFX_MGR02_FARADAY)
   EGL_RENDERABLE_TYPE,EGL_OPENVG_BIT,
#else
   EGL_SURFACE_TYPE,   EGL_PBUFFER_BIT,
#endif
   EGL_NONE
};

static EGLint const lc_config_attribs_argb4444[] =
{
   EGL_RED_SIZE,       4,
   EGL_GREEN_SIZE,     4,
   EGL_BLUE_SIZE,      4,
   EGL_ALPHA_SIZE,     4,
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
   EGL_ALPHA_MASK_SIZE, 8,
#else
   EGL_ALPHA_MASK_SIZE, 0,
#endif
   EGL_SURFACE_TYPE,   EGL_PBUFFER_BIT,
   EGL_STENCIL_SIZE,   0,
   EGL_NONE
};
#endif /* #if defined(GFX_MGR02_OPEN_VG) */

#if (((defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT)) && \
    defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && \
    defined(GFX_MGR02_SOFTWARE_FB_SIZE)) || defined(GFX_MGR02_FUJITSU) || \
    (defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_USE_TIDSS)))
static UINT32 l_fb_total_available_size;
static UINT32 l_fb_cur_address;
static UINT8 const lc_fb_bytes_for_8pix[GFX_MGR02_NUM_PIX_FORMATS] = 
{
   /* GFX_MGR02_PIX_FORMAT_INVALID  */ 0,
   /* GFX_MGR02_PIX_FORMAT_1BPP     */ 1,
   /* GFX_MGR02_PIX_FORMAT_2BPP     */ 2,
   /* GFX_MGR02_PIX_FORMAT_4BPP     */ 4,
   /* GFX_MGR02_PIX_FORMAT_8BPP     */ 8,
   /* GFX_MGR02_PIX_FORMAT_RGB565   */ 16,
   /* GFX_MGR02_PIX_FORMAT_ARGB4444 */ 16,
   /* GFX_MGR02_PIX_FORMAT_ARGB1555 */ 16,
   /* GFX_MGR02_PIX_FORMAT_YVYU422  */ 16,
   /* GFX_MGR02_PIX_FORMAT_RGB666   */ 18,
   /* GFX_MGR02_PIX_FORMAT_RGB888   */ 24,
   /* GFX_MGR02_PIX_FORMAT_ARGB6666 */ 24,
   /* GFX_MGR02_PIX_FORMAT_ARGB8888 */ 32,
   /* GFX_MGR02_PIX_FORMAT_A1       */ 1,
   /* GFX_MGR02_PIX_FORMAT_A2       */ 2,
   /* GFX_MGR02_PIX_FORMAT_A4       */ 4,
   /* GFX_MGR02_PIX_FORMAT_A8       */ 8
};
#if GFX_MGR02_NUM_PIX_FORMATS != 17
  #error "lc_fb_bytes_for_8pix needs update\n"
#endif
#endif /*#if defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE)*/

#if defined(GFX_MGR02_FUJITSU)
static  MML_GDC_PE_CONTEXT_CONTAINER   l_mml_gdc_pixeng_ctx_c[GFX_MGR02_NUM_LAYERS];
static  MML_GDC_SURFACE_CONTAINER      l_mml_gdc_store_surf_c[GFX_MGR02_NUM_LAYERS][GFX_DRIVER_NUM_FB];
static  MML_GDC_DISP_WINDOW            l_mml_gdc_disp_window[GFX_MGR02_NUM_LAYERS];
static  MML_GDC_DISPLAY                l_mml_gdc_display;
#endif

#if defined (GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2)
 #if GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0
  static GFX_MGR02_FB_INFO_T  l_amber_fb_info_S[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];
  #if defined(GFX_MGR02_TRAVEO2)
  static CYGFX_BE_CONTEXT    l_mml_gdc_pixeng_ctx[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];
  static CYGFX_SURFACE       l_mml_gdc_store_surf[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  #else
  static MML_GDC_PE_CONTEXT  l_mml_gdc_pixeng_ctx[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];
  static MML_GDC_SURFACE     l_mml_gdc_store_surf[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  #endif
  static UINT16               l_amber_fb_width[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  static UINT16               l_amber_fb_height[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  #if ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)|| ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))))
  static  void *                     l_de_path_buffer[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];
  #endif
 #endif
#endif

#if defined (GFX_MGR02_AMBER_IRIS)
  static  MML_GDC_PE_CONTEXT  l_ambr_irs_mml_gdc_pixeng_ctx[GFX_MGR02_NUM_LAYERS];
  static MML_GDC_SURFACE      l_ambr_irs_mml_gdc_store_surf[GFX_MGR02_NUM_LAYERS][GFX_DRIVER_NUM_FB];
  #if ((GFX_MGR02_NUM_OF_SVGS >0)|| (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)))
  static  void *              l_ambr_irs_de_path_buffer[GFX_MGR02_NUM_LAYERS];
  #endif
#endif

#if defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0)
  static GFX_MGR02_FB_INFO_T  l_imxrt_fb_info_S[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS];  
  static UINT16               l_imxrt_fb_width[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  static UINT16               l_imxrt_fb_height[GFX_MGR02_NUM_AMBER_MERGE_WIDGETS][GFX_DRIVER_NUM_FB];
  #if (((GFX_MGR02_NUM_OF_SVGS > 0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)) && defined(GFX_MGR02_VGLITE))
  static void*                l_vglite_path_cmd_buf = NULL;
  #endif
#endif

#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE))
static void *l_decompr_buffer = NULL;
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
  /* 
  ** l_ft_init_status == 1 --> Error
  ** l_ft_init_status == 0 --> Success
  */
 static  FT_Error l_ft_init_status = 1;
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)) && !defined (GFX_MGR02_KEPLER)
  static FS_LONG  l_ft_init_status = 1;
  static FS_STATE *l_mt_client_state;
#endif

#if defined(GFX_MGR02_SOFTWARE)
#if defined(GFX_MGR02_USE_TIDSS)

#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_ARGB4444) || \
    (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_ARGB1555) || \
    (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_RGB565)
    #define GFX_MGR02_LAYERS_BYTES_PER_PIXEL  (2U)
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_ARGB8888)
    #define GFX_MGR02_LAYERS_BYTES_PER_PIXEL  (4U)
#else
    #define GFX_MGR02_LAYERS_BYTES_PER_PIXEL  (4U)
#endif 
 
/* Frame buffers for dss pipeline */
static UINT8 l_frame_buffer[GFX_DRIVER_NUM_FB][(UINT32)GFX_MGR02_LAYERS_MAX_WIDTH * (UINT32)GFX_MGR02_LAYERS_MAX_HEIGHT * GFX_MGR02_LAYERS_BYTES_PER_PIXEL] __attribute__ ((section (".dssFrameBuffer"), aligned (4096)));
#endif
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0) ||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_set_active
Description          : This function sets the widget contexts to active state
Invocation           : Called by dcu build function after detecting that a 
                       openvg widget is active
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_widget_set_active(UINT32 p_client_id)
{
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)
    if(p_client_id <(UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS)
    {
        l_dcu_fb_info_S[p_client_id].active = (UINT8)1;
    }
#else
    
    if(p_client_id <(UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {	
     #if defined(GFX_MGR02_IMXRT)		
        l_imxrt_fb_info_S[p_client_id].active = (UINT8)1;
    #else
        l_amber_fb_info_S[p_client_id].active = (UINT8)1;	 
    #endif	
    }
    
#endif
}
#endif
/****************************************************************************
 Function Name        : void hmi_gfx_mgr02_context_shutdown()
 Description          : Initializes ishutdown of context
 Invocation           : When ever generic context needs to be initialized
 Return Value         : None
 Critical Section     : None
 Parameters           : None
 ******************************************************************************/
void hmi_gfx_mgr02_context_shutdown(void) 
{
#if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_OPEN_VG)
 #if defined(GFX_MGR02_RENESAS_OPENVG_LIB)
   UINT32                   i;
#elif !(defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_SOFTWARE))
   UINT32                   i,j;
 #endif
#endif

/* Shutdown sequence for openVG platform */
#if defined(GFX_MGR02_OPEN_VG)
   #ifdef GFX_MGR02_RENESAS_OPENVG_LIB
      if(dsp != EGL_NO_DISPLAY)
      {
         vgFinish();
         if(eglMakeCurrent(dsp, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT) == EGL_FALSE)
         {
            GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
         }
       #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG)
         for(i=0; i < GFX_MGR02_NUM_LAYERS; i++)
         {
           /*
           ** TODO : renesas init and shut down design is not handling
           ** multiple layers at the moment. it overwrites values a 
           ** single static variable location for all the layers.
           ** this has to be redesigned. when there is an application need
           ** for more than one layer.
           */
           if(l_egl_surface[i][0] != EGL_NO_SURFACE)
           {
              if(eglDestroySurface(dsp, l_egl_surface[i][0]) == EGL_FALSE)
              {
                 GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYSURFACE_FAULT);
              }
           }
           if(l_egl_context[i] != EGL_NO_CONTEXT)
           {
              if(eglDestroyContext(dsp, l_egl_context[i]) == EGL_FALSE)
              {
                 GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYCONTEXT_FAULT);
              }
              l_egl_context[i] = EGL_NO_CONTEXT;
           }
           if(window_ctx[i] != NATIVE_NO_WINDOW)
           {
              if(destroyNativeWindow(window_ctx[i]))
              {
                 GFX_MGR02_LOG_ERROR(GFX_DESTROYNATIVEWINDOW_FAULT);
              }
           }
           if(front_ctx[i] != NATIVE_NO_PIXMAP)
           { 
              if(destroyNativePixmap(front_ctx[i]))
              {
                 GFX_MGR02_LOG_ERROR(GFX_DESTROYNATIVEPIXMAP_FAULT);
              }
           }
           if(back_ctx[i] != NATIVE_NO_PIXMAP)
           {
              if(destroyNativePixmap(back_ctx[i]))
              {
                 GFX_MGR02_LOG_ERROR(GFX_DESTROYNATIVEPIXMAP_FAULT);
              }
           }
        }
      #endif
        if(eglTerminate(dsp) == EGL_FALSE)
        {
           GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLTERMINATE_FAULT);
        }
        dsp = EGL_NO_DISPLAY;
      }
      eglCleanUp();
      vgCleanUp();
      NCGSYS_FrameMemDestroy();
      termNativeResource();
   #else
    #if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
      hmi_gfx_mgr02_ovglib_cache_distroy();
    #endif
      if(dsp != EGL_NO_DISPLAY)
      {
        vgFinish();
        if(eglMakeCurrent(dsp, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT) == EGL_FALSE)
        {
           GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
        }
        if(l_egl_shared_context != EGL_NO_CONTEXT)
        {
           if(eglDestroyContext(dsp, l_egl_shared_context) == EGL_FALSE)
           {
              GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYCONTEXT_FAULT);
           }
           l_egl_shared_context = EGL_NO_CONTEXT;
        }
        if(l_egl_shared_surface != EGL_NO_SURFACE)
        {
           if(eglDestroySurface(dsp, l_egl_shared_surface) == EGL_FALSE)
           {
              GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYSURFACE_FAULT);
           }
           l_egl_shared_surface = EGL_NO_SURFACE;
        }
        for(i=0; i < GFX_MGR02_NUM_LAYERS; i++)
        {
           if(l_egl_context[i] != EGL_NO_CONTEXT)
           {
              if(eglDestroyContext(dsp, l_egl_context[i]) == EGL_FALSE)
              {
                 GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYCONTEXT_FAULT);
              }
              l_egl_context[i] = EGL_NO_CONTEXT;
           }
        }
        for(i=0; i < GFX_MGR02_NUM_LAYERS; i++)
        {
           for(j=0; j < GFX_DRIVER_NUM_FB; j++)
           {
              if(l_egl_surface[i][j] != EGL_NO_SURFACE)
              {
                 if(eglDestroySurface( dsp, l_egl_surface[i][j]) == EGL_FALSE)
                 {
                    GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYSURFACE_FAULT);
                 }
                 l_egl_surface[i][j] = EGL_NO_SURFACE;
              }
           }
        }
        if(eglTerminate(dsp) == EGL_FALSE)
        {
           GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLTERMINATE_FAULT);
        }
      }
     #if defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(__MQXOS__)
      hmi_gfx_mgr02_driver_mqx_dcu_shutdown();
      if(gpu_fini() == FALSE)
      {
         GFX_MGR02_LOG_ERROR(GFX_MGR02_GPU_FINI_FAULT);
      }
     #endif
      dsp = EGL_NO_DISPLAY;
   #endif
#endif

/* Shutdown sequence for fujitsu platform */
#if defined(GFX_MGR02_FUJITSU)
   {
      UINT32 fl_layer_idx;
      MM_S32 ret = MML_OK;
      for(fl_layer_idx=(UINT32)0; fl_layer_idx < (UINT32)GFX_MGR02_NUM_LAYERS; fl_layer_idx++)
      {
         if(l_mml_gdc_disp_window[fl_layer_idx] != 0)
         {
            UTIL_SUCCESS(ret, mmlGdcDispDestroyWindow(l_mml_gdc_disp_window[fl_layer_idx]));
            l_mml_gdc_disp_window[fl_layer_idx] = 0;
         }
      }
      if(l_mml_gdc_display != 0)
      {
         UTIL_SUCCESS(ret, mmlGdcDispCloseDisplay(l_mml_gdc_display));
         UTIL_SUCCESS(ret, mmlGdcSysUninitializeDriver());
         l_mml_gdc_display = 0;
      }
   }
#endif

/* Shutdown sequence for software platform */
#if defined(GFX_MGR02_SOFTWARE)
  #if defined(GFX_MGR02_USE_TIDSS)
  for(UINT8 fl_index = (UINT8)0; fl_index < (UINT8)GFX_MGR02_NUM_LAYERS; fl_index++)
  {
    (void)hmi_gfx_mgr02_tidss_dispif_shutdown(fl_index);
  }
  #endif
#endif

/* Shutdown sequence for amber iris platform */
#if defined(GFX_MGR02_AMBER_IRIS)
{
    UINT32 i,j;
    MM_S32 ret;
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];
    for(i = (UINT32)0; i < GFX_MGR02_NUM_LAYERS; i++)
    {
        if(l_ambr_irs_mml_gdc_pixeng_ctx[i] != NULL)
        {
            mmlGdcPeDeleteContext(l_ambr_irs_mml_gdc_pixeng_ctx[i]);
            l_ambr_irs_mml_gdc_pixeng_ctx[i] = NULL;
        }		   
        for(j = (UINT32)0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
        {
            if(l_ambr_irs_mml_gdc_store_surf[i][j] !=NULL)
            {
                IRIS_API_CHECK(ret, mmlGdcSmDeleteSurfaceObjects((MM_U32)1, &l_ambr_irs_mml_gdc_store_surf[i][j]));
                l_ambr_irs_mml_gdc_store_surf[i][j] = NULL;
            }
        }
    #if ((GFX_MGR02_NUM_OF_SVGS >0)|| (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)))
        if(l_ambr_irs_de_path_buffer[i]!=NULL)
        {
            hmi_gfx_mgr02_amber_mem_mgmt_free(l_ambr_irs_de_path_buffer[i]);     
            l_ambr_irs_de_path_buffer[i]=NULL; 
        }
    #endif
    }
    #if !defined(GFX_MGR02_AMBER)
    HMI_GFX_MGR02_AMBER_IRIS_SHUTDOWN();
    #endif     
    for(j=0U; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
    {
        if(fl_fb_info_SP->fb_ptr[j] != NULL)
        {
            hmi_gfx_mgr02_amber_mem_mgmt_free(fl_fb_info_SP->fb_ptr[j]);
            fl_fb_info_SP->fb_ptr[j] = NULL;
        }
    }	 
}
#endif

/* Shutdown sequence for amber/tv2 platform */
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)
   {
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)     
       UINT32 i;
       UINT32 j;
       MM_S32 ret;
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)/*To avoid coverity warning CID 5620904: Logically dead code (DEADCODE)*/
       UINT32 fl_fb_info_count =   ((UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS-(UINT32)1);
#endif
       /*Release the IRIS driver resources*/
       GFX_MGR02_FB_INFO_T * fl_fb_info_SP; 
       for(i=0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
       {
          if(l_mml_gdc_pixeng_ctx[i] != NULL)
          {
             mmlGdcPeDeleteContext(l_mml_gdc_pixeng_ctx[i]);
             l_mml_gdc_pixeng_ctx[i] = NULL;
          }

          for(j=0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
          {
             if(l_mml_gdc_store_surf[i][j] != NULL)
             {
                IRIS_API_CHECK(ret, mmlGdcSmDeleteSurfaceObjects(1U, &(l_mml_gdc_store_surf[i][j])));
                l_mml_gdc_store_surf[i][j] = NULL;
             }
          }
       }
#endif
       /* Stop IRIS Engine */
       hmi_gfx_mgr02_amber_shutdown();
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
        /* Free the memory used for frame buffers. */
       fl_fb_info_SP = &l_amber_fb_info_S[0];
       for(i=0U; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
       {
          for(j=0U; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
          {
             if(fl_fb_info_SP->fb_ptr[j] != NULL)
             {
                hmi_gfx_mgr02_amber_mem_mgmt_free(fl_fb_info_SP->fb_ptr[j]);
                fl_fb_info_SP->fb_ptr[j] = NULL;
             }
          }
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)/*To avoid coverity warning CID 5620904: Logically dead code (DEADCODE)*/
          if (i != fl_fb_info_count)
          {
            fl_fb_info_SP++;
          }
#endif
       }
#endif
   }
#endif

/* Shutdown sequence for imxrt platform */
#if defined(GFX_MGR02_IMXRT)
{
    #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0)
    /* Free the memory used for frame buffers. */
    UINT32 i;
    UINT32 j;
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[0];
    for(i=0U; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
    {
        for(j=0U; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
        {
            if(fl_fb_info_SP->fb_ptr[j] != NULL)
            {					 
                hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_fb_info_SP->fb_ptr[j]);
                fl_fb_info_SP->fb_ptr[j] = NULL;
            }
        }
        fl_fb_info_SP++;
    }
    
    /* Free vglite path command buffer memory */
    #if (((GFX_MGR02_NUM_OF_SVGS >0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)) && defined(GFX_MGR02_VGLITE))
    if (l_vglite_path_cmd_buf != NULL) 
    {
        hmi_gfx_mgr02_imxrt_mem_mgmt_free(l_vglite_path_cmd_buf);
        l_vglite_path_cmd_buf = NULL;
    }
    #endif

    #endif
    
    hmi_gfx_mgr02_imxrt_lcdif_shutdown(0);
}
#endif

/* Shutdown sequence for imxrt pxp platform */
#if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT) 
{
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];
    UINT8 fb_idx;
    
    for(fb_idx = 0U; fb_idx < GFX_DRIVER_NUM_FB; fb_idx++)
    {
        if(fl_fb_info_SP->fb_ptr[fb_idx] != NULL)
        {
            hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_fb_info_SP->fb_ptr[fb_idx]);
            fl_fb_info_SP->fb_ptr[fb_idx] = NULL;
        }
    }
}
#endif

/* Shutdown sequence for external font engine feature */
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
   /* 
  ** l_ft_init_status == 1 --> Error
  ** l_ft_init_status == 0 --> Success
  */
   if(l_ft_init_status == 0)
   {
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) ||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)
    #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
        FTC_Manager fl_ftc_manager;
        fl_ftc_manager = hmi_gfx_mgr02_get_ft2_cachemgr_handler(); 
		
         if(fl_ftc_manager != NULL) {
            FTC_Manager_Reset(fl_ftc_manager);
            FTC_Manager_Done(fl_ftc_manager);
         }
    #endif
    #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && defined(GFX_MGR02_USER_DEFINED_MM)  
        (void)FT_Done_Library(l_context_S.rprop.ft2_library);
    #else
        (void)FT_Done_FreeType((l_context_S.rprop.ft2_library));
    #endif

    #endif
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined (GFX_MGR02_KEPLER)
     (void)FS_end_client(l_mt_client_state);
     (void)FS_exit(&l_context_S.rprop.mt_fs_state);
    #endif
   }
   else
   {
    #ifdef GFX02_DEBUG_CONTEXT
      (void)printf("ctxterr\n");
      (void)fflush(stdout);
    #endif
   }
   l_ft_init_status = 1;

   #if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
     hmi_gfx_mgr02_shape_engine_shutdown();
   #endif
#endif

/* Shutdown sequence for string cache feature */
#if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_AMBER) || defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)
{
    #if defined(GFX_STRING_CACHE_ENABLED)
    hmi_gfx_mgr02_cache_shutdown();
    #endif
}
#endif

/* Shutdown sequence for compression feature */
#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE))
{
    /* Free memory used for capturing image data after sw rle decompression */
    hmi_gfx_mgr02_context_free_decompr_buffer();       
}
#endif

/* Generic shutdown sequence */
hmi_gfx_mgr02_generic_shutdown();

}

#if defined(GFX_MGR02_OPEN_VG) && defined(GFX_MGR02_RENESAS_OPENVG_LIB)
/****************************************************************************
Function Name        : void context_ovg_pre_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static UINT32 context_ovg_pre_init(void)
{
   UINT32          fl_index;
   EGLErrorCodeREL egl_err ;
   VGErrorCodeREL  vg_err ;
   NCGint32        ret_ncg ;
   UINT32          fl_return = FALSE;

   initNativeResource() ;
   /* Start up EGL1.4 and OpenVG 1.1 library */
   egl_err = eglStartUp() ;
   if( egl_err == EGL_REL_NO_ERROR )
   {
      ret_ncg = NCGSYS_FrameMemCreate(( NCGuint32 )aui32NCGFrameMemHeap, ( NCGuint32 )NCG_FRAME_MEM_HEAP_SIZE, ( NCGuint32 )0 ) ;
      if( ret_ncg == NCG_no_err )
      {
        vg_err = vgStartUp() ;
        if( vg_err == VG_REL_NO_ERROR )
        {
          dsp = eglGetDisplay(EGL_DEFAULT_DISPLAY);
          if(dsp != EGL_NO_DISPLAY)
          {
            if(eglInitialize(dsp, GFX_MGR02_NULL_PTR, GFX_MGR02_NULL_PTR) != EGL_FALSE)
            {
              for(fl_index=0; fl_index < GFX_MGR02_NUM_LAYERS; fl_index++)
              {
                l_egl_context[fl_index] = EGL_NO_CONTEXT;
              }
              fl_return = TRUE;
            }
            else
            {
              GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLINITIALIZE_FAULT);
            }
          }
          else
          {
            GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLGETDISPLAY_FAULT);
          }
        }
        else
        {
          GFX_MGR02_LOG_ERROR(GFX_MGR02_VGSTARTUP_FAULT);
        }
      }
      else
      {
        GFX_MGR02_LOG_ERROR(GFX_MGR02_NCGSYS_FRAMEMEMCREATE_FAULT);
      }
   }
   else
   {
     GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLSTARTUP_FAULT);
   }
   return fl_return; 
}
/****************************************************************************
Function Name        : UINT32 context_ovg_layer_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : Layer index
******************************************************************************/
static UINT32 context_ovg_layer_init(UINT32 p_index)
{
  EGLint const * fl_config_p;
  EGLint         numconfigs;
  EGLConfig      cfg = GFX_MGR02_NULL_PTR;
  u_gx_flocal    fl_pix_format = lc_layer_def_S[p_index].pix_format;
  NativePixmapInfo pixmap_info;
  UINT32         fl_fb_bytes_for_pix = 0;
  EGLint         fl_value;
  EGLBoolean     ret;
  UINT32         j;
  GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];
  UINT32         fl_return = FALSE;

  if(l_egl_context[p_index] == EGL_NO_CONTEXT)
  {
    switch(fl_pix_format)
    {
      case GFX_MGR02_PIX_FORMAT_RGB565:
      {
        fl_config_p   = lc_config_attribs_rgb565;
        fl_fb_bytes_for_pix = 2;
      }
      break;
      case GFX_MGR02_PIX_FORMAT_ARGB4444:
      {
        fl_config_p   = lc_config_attribs_argb4444;
        fl_fb_bytes_for_pix = 2;
      }
      break;
      case GFX_MGR02_PIX_FORMAT_ARGB8888:
      {
        fl_config_p   = lc_config_attribs_argb8888;
        fl_fb_bytes_for_pix = 4;
       }
       break;
       default:
       {
         fl_config_p = (EGLint const *)0;
        #ifdef GFX02_DEBUG_CONTEXT
         gfx_debug("Unsupported framebuffer format for openvg [%d]\n", fl_pix_format);
        #endif
       }
       break;
    }
    if(fl_config_p != (EGLint *)0)
    {
      if(eglChooseConfig(dsp, fl_config_p, &cfg, 1, &numconfigs) != EGL_FALSE)
      {
        /* Create Native Surface */
        ret = eglGetConfigAttrib(dsp, cfg, EGL_NATIVE_VISUAL_TYPE, &fl_value);
        if(ret != EGL_FALSE)
        {
          front_ctx[p_index] = createNativePixmap( fl_value, lc_layer_def_S[p_index].area.width, lc_layer_def_S[p_index].area.height ) ;
          if( front_ctx[p_index] != NATIVE_NO_PIXMAP )
          {
            back_ctx[p_index] = createNativePixmap( fl_value, lc_layer_def_S[p_index].area.width, lc_layer_def_S[p_index].area.height ) ;
            if( back_ctx[p_index] != NATIVE_NO_PIXMAP )
            {
              window_ctx[p_index] = createNativeWindow( front_ctx[p_index], back_ctx[p_index] ) ;
              if( window_ctx[p_index] != NATIVE_NO_WINDOW )
              {
                /* Create EGL Surface */
                l_egl_surface[p_index][0] = eglCreateWindowSurface( dsp, cfg, window_ctx[p_index], attr_list_Win ) ;
                if( l_egl_surface[p_index][0] != EGL_NO_SURFACE )
                {
                  /* Specify the current rendering API */
                  ret = eglBindAPI( EGL_OPENVG_API ) ;
                  if( ret != EGL_FALSE )
                  {
                    l_egl_context[p_index] = eglCreateContext( dsp, cfg, NULL, NULL ) ;
                    if( l_egl_context[p_index] != EGL_NO_CONTEXT )
                    {
                      ret = getNativePixmapInfo(front_ctx[p_index], &pixmap_info);
                      if (ret == NATIVE_TRUE) 
                      {
                       #if GFX_DRIVER_NUM_FB > 1
                         /* Due to some limitation in renesas lib, this line was added. If FB less than 1 not required*/
                         /* coverity fix 10159 High*/
                         fl_fb_info_SP[p_index].fb_ptr[1] = (void *)pixmap_info.phy_addr;
                       #endif
                         l_front_buffer_address_ctx[p_index] = pixmap_info.phy_addr;
                      }
                      ret = getNativePixmapInfo(back_ctx[p_index], &pixmap_info);
                      if (ret == NATIVE_TRUE) 
                      {
                        fl_fb_info_SP[p_index].fb_ptr[0] = (void *)pixmap_info.phy_addr;
                        l_back_buffer_address_ctx[p_index] = pixmap_info.phy_addr;
                      }
                      showNativeWindow( window_ctx[p_index] ) ;
                      /* Need to reinitialize the frame buffer since the memory is used by OpenVG
                         in the intermediate and it is not cleared when freed. So it results
                         in grey lines in the bottom of the display if left uninitialized.
                         This is before the clock display */
       
                      ptr_ctx =(UINT8 *)l_back_buffer_address_ctx[p_index];
                      (void)memset(ptr_ctx,0, lc_layer_def_S[p_index].area.width*lc_layer_def_S[p_index].area.height*fl_fb_bytes_for_pix);
                      ptr_ctx =(UINT8 *)l_front_buffer_address_ctx[p_index];
                      (void)memset(ptr_ctx,0, lc_layer_def_S[p_index].area.width*lc_layer_def_S[p_index].area.height*fl_fb_bytes_for_pix);
                      /* Make the specified context and surface current */
                      ret = eglMakeCurrent( dsp, l_egl_surface[p_index][0], l_egl_surface[p_index][0], l_egl_context[p_index] ) ;
                      if( ret != EGL_FALSE )
                      {
                       #if defined(GFX_MGR02_ENABLE_HW_DITHERING)
                         /* enable HW dithering support */
                         if(fl_pix_format == GFX_MGR02_PIX_FORMAT_ARGB8888)
                         {
                            vgSeti( VG_DITHER_REL, VG_FALSE);
                         }
                         else
                         {
                            vgSeti( VG_DITHER_REL, VG_TRUE);
                         }
                       #else
                         vgSeti( VG_DITHER_REL, VG_FALSE);
                       #endif
                       fl_return = TRUE;
                      }
                      else
                      {
                        GFX_MGR02_LOG_ERROR( GFX_MGR02_EGLMAKECURRENT_FAULT);
                      }
                    }
                    else
                    {
                      GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCREATECONTEXT_FAULT);
                    }
                  }
                  else
                  {
                    GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLBINDAPI_FAULT);
                  }
                }
                else
                {
                  GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCREATEWINDOWSURFACE_FAULT);
                }
              }
              else
              {
                GFX_MGR02_LOG_ERROR(GFX_MGR02_CREATENATIVEWINDOW_FAULT);
              }
            }
            else
            {
              GFX_MGR02_LOG_ERROR(GFX_MGR02_CREATENATIVEPIXMAP_FAULT);
            }
          }
          else
          {
            GFX_MGR02_LOG_ERROR(GFX_MGR02_CREATENATIVEPIXMAP_FAULT);
          }
        }
        else
        {
          GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLGETCONFIGATTRIB_FAULT);
        }
      }
      else
      {
        GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCHOOSECONFIG_FAULT);
      }
    }
  }
  return fl_return;
}
#endif

#if defined(GFX_MGR02_OPEN_VG) && !defined(GFX_MGR02_RENESAS_OPENVG_LIB)
/****************************************************************************
Function Name        : void context_ovg_pre_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static UINT32 context_ovg_pre_init(void)
{
   UINT32        fl_index;
   EGLConfig     cfg = GFX_MGR02_NULL_PTR;
   EGLint        numconfigs;
   UINT32        fl_return = FALSE;
#if defined(GFX_MGR02_FARADAY) && !defined(WIN32)
   if(gpu_init() == FALSE)
   {
      GFX_MGR02_LOG_ERROR(GFX_MGR02_GPU_INIT_FAULT);
   }
   else
#endif
   {
       if(eglBindAPI(EGL_OPENVG_API) != EGL_FALSE)
       {
          dsp = eglGetDisplay(EGL_DEFAULT_DISPLAY);
          if(dsp != EGL_NO_DISPLAY)
          {
            if(eglInitialize(dsp, GFX_MGR02_NULL_PTR, GFX_MGR02_NULL_PTR) != EGL_FALSE)
            {
              for(fl_index=0; fl_index < GFX_MGR02_NUM_LAYERS; fl_index++)
              {
                 l_egl_context[fl_index] = EGL_NO_CONTEXT;
              }
              if(eglChooseConfig(dsp, lc_config_attribs_argb8888, &cfg, 1, &numconfigs) != EGL_FALSE)
              {
                l_egl_shared_context = eglCreateContext(dsp, cfg, EGL_NO_CONTEXT, NULL);
                if(l_egl_shared_context != EGL_NO_CONTEXT)
                {
                  l_egl_surface_attrib[0][0] = EGL_WIDTH;
                  l_egl_surface_attrib[0][1] = 16;
                  l_egl_surface_attrib[0][2] = EGL_HEIGHT;
                  l_egl_surface_attrib[0][3] = 1;
                  l_egl_surface_attrib[0][4] = EGL_NONE;
                  l_egl_shared_surface       = eglCreatePbufferSurface(dsp, cfg, l_egl_surface_attrib[0]);
                  if(l_egl_shared_surface != EGL_NO_SURFACE)
                  {
                    if(eglMakeCurrent(dsp, l_egl_shared_surface, l_egl_shared_surface, l_egl_shared_context) != EGL_FALSE)
                    {
                      fl_return = TRUE;
                    }
                    else
                    {
                      GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
                    } 
                  }
                  else
                  {
                    GFX_MGR02_LOG_ERROR(GFX_MGR02_CREATE_PBUFFERSURFACE_FAULT);
                  }
                }
                else
                {
                  GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCREATECONTEXT_FAULT);
                }
              }
              else
              {
                GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCHOOSECONFIG_FAULT);
              }
            }
            else
            {
              GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLINITIALIZE_FAULT);
            }
         
          }
          else
          {
            GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLGETDISPLAY_FAULT);
          }
       }
       else
       {
         GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLBINDAPI_FAULT);
       }
   }
   return fl_return;
}
/****************************************************************************
Function Name        : UINT32 context_ovg_layer_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : Layer index
******************************************************************************/
static UINT32 context_ovg_layer_init(UINT32 p_index)
{
  EGLint const * fl_config_p;
  EGLint         numconfigs;
  EGLConfig      cfg = GFX_MGR02_NULL_PTR;
  u_gx_flocal    fl_pix_format = lc_layer_def_S[p_index].pix_format;
 #if GFX_MGR02_MAX_EGL_CONFIGS > 1
   EGLint        fl_alpha_size;
   EGLint        fl_green_size;
   EGLint        fl_value;
 #endif
   UINT32        j;
  GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];
 #if defined(GFX_MGR02_ENABLE_FSL_EXTENTIONS)
   EGLPbufferDimFSL dim;
 #endif
  UINT32         fl_return = FALSE;

  if(l_egl_context[p_index] == EGL_NO_CONTEXT)
  {
    switch(fl_pix_format)
    {
      case GFX_MGR02_PIX_FORMAT_RGB565:
      {
        fl_config_p   = lc_config_attribs_rgb565;
       #if GFX_MGR02_MAX_EGL_CONFIGS > 1
        fl_alpha_size = 0;
        fl_green_size = 6;
       #endif
      }
      break;
      case GFX_MGR02_PIX_FORMAT_ARGB4444:
      {
        fl_config_p   = lc_config_attribs_argb4444;
       #if GFX_MGR02_MAX_EGL_CONFIGS > 1
        fl_alpha_size = 4;
        fl_green_size = 4;
       #endif
      }
      break;
      case GFX_MGR02_PIX_FORMAT_ARGB8888:
      {
        fl_config_p   = lc_config_attribs_argb8888;
       #if GFX_MGR02_MAX_EGL_CONFIGS > 1
        fl_alpha_size = 8;
        fl_green_size = 8;
       #endif
      }
      break;
      default:
      {
        fl_config_p = (EGLint const *)0;
       #ifdef GFX02_DEBUG_CONTEXT
        gfx_debug("Unsupported framebuffer format for openvg [%d]\n", fl_pix_format);
       #endif
      }
      break;
  }
  if(fl_config_p != (EGLint *)0)
  {
    #if GFX_MGR02_MAX_EGL_CONFIGS > 1
     /*
      ** First get number of maximum matching egl configurations.
      ** and then choose the one that macthes our configuration
     */
     if(eglChooseConfig(dsp, fl_config_p, 0, 0, &numconfigs) != EGL_FALSE)
    #else
     if(eglChooseConfig(dsp, fl_config_p, &cfg, 1, &numconfigs) != EGL_FALSE)
    #endif
     {
      #if GFX_MGR02_MAX_EGL_CONFIGS > 1
        EGLConfig fl_cfg[GFX_MGR02_MAX_EGL_CONFIGS];
        (void)eglChooseConfig(dsp, fl_config_p, &fl_cfg[0], GFX_MGR02_MAX_EGL_CONFIGS, &numconfigs);
         while(numconfigs > 0)
         {
           numconfigs--;
           if(eglGetConfigAttrib(dsp, fl_cfg[numconfigs], EGL_GREEN_SIZE, &fl_value) != EGL_FALSE)
           {
             if(fl_value == fl_green_size)
             {
                if(eglGetConfigAttrib(dsp, fl_cfg[numconfigs],EGL_ALPHA_SIZE, &fl_value) != EGL_FALSE)
                {
                  if(fl_value == fl_alpha_size)
                  {
                    cfg = fl_cfg[numconfigs];
                    numconfigs = 1;
                    break;
                  }
                }
              }
           }
         }
       #endif
       #if !defined(WIN32)
         if(numconfigs != 0)
       #endif
         {
           l_egl_context[p_index] = eglCreateContext(dsp, cfg, l_egl_shared_context, NULL);
           if(l_egl_context[p_index] != EGL_NO_CONTEXT)
           {
             l_egl_surface_attrib[p_index][0] = EGL_WIDTH;
             l_egl_surface_attrib[p_index][1] = (EGLint)lc_layer_def_S[p_index].area.width;
             l_egl_surface_attrib[p_index][2] = EGL_HEIGHT;
             l_egl_surface_attrib[p_index][3] = (EGLint)lc_layer_def_S[p_index].area.height;
             l_egl_surface_attrib[p_index][4] = EGL_NONE;
             for(j=0; j < GFX_DRIVER_NUM_FB; j++)
             {
               l_egl_surface[p_index][j]  = eglCreatePbufferSurface(dsp, cfg, l_egl_surface_attrib[p_index]);
               if(l_egl_surface[p_index][j] != EGL_NO_SURFACE)
               {
                #if defined(GFX_MGR02_ENABLE_FSL_EXTENTIONS)
                 (void)eglGetPbufferDimFSL(&dim,dsp,l_egl_surface[p_index][j]);
                 fl_fb_info_SP[p_index].fb_ptr[j] = (void *)(dim.Add);
                #else
                 /* For Renesas OpenVG the NCGSYS_FrameMemCreate() called above will allocate FB */
                 #error "OpenVG Framebuffer pointer loading not handled for non FSL targets\n"
                #endif
               }
               else
               {
                 GFX_MGR02_LOG_ERROR(GFX_MGR02_CREATE_PBUFFERSURFACE_FAULT);
                 break; /* will come out of the loop <for(j=0; j < GFX_DRIVER_NUM_FB; j++)> */
               }
             }
             if(l_egl_surface[p_index][0] != EGL_NO_SURFACE)
             {
               if(eglMakeCurrent(dsp, l_egl_surface[p_index][0], l_egl_surface[p_index][0], l_egl_context[p_index]) != EGL_FALSE)
               {
                 fl_return = TRUE;
               }
               else
               {
                 GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
               }
             }
           }
           else
           { 
             GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCREATECONTEXT_FAULT);
           }
         }
        #if !defined(WIN32)
         else
         {
           GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCHOOSECONFIG_FAULT);
         }
        #endif
       }
       else
       {
         GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLCHOOSECONFIG_FAULT);
       }
    }
  }
  return fl_return;
}
#endif

#if defined(GFX_MGR02_FUJITSU)
/****************************************************************************
Function Name        : void context_fjt_pre_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void context_fjt_pre_init(void)
{
  MM_U32 fl_memory_size;
  MM_S32 ret = MML_OK;

  l_fb_total_available_size = (UINT32)(GFX_MGR02_CALYPSO_VRAM_SIZE - GFX_MGR02_IRIS_DBG_SIZE);
  l_fb_cur_address          = (UINT32)GFX_MGR02_IRIS_VRAM_BASE;

  // driver initialization
  UTIL_SUCCESS(ret, mmlGdcSysInitializeDriver(0));
  fl_memory_size = (UINT32)GFX_MGR02_IRIS_INSTR_BUFF_SIZE;
  UTIL_SUCCESS(ret, mmlGdcSysSetInstructionBuffer((void *)l_fb_cur_address, fl_memory_size));
  /* GFX_MGR02_IRIS_INSTR_BUFF_SIZE memory is allocated for IRIS COmmand Sequencer - Instruction Buffer,
  so update the current address */
  if(ret==MML_OK)
  {
    l_fb_cur_address          += fl_memory_size;
    l_fb_total_available_size -= fl_memory_size;
  }
  else
  {
   #ifdef GFX02_DEBUG_CONTEXT
     gfx_debug("Fujitsu Driver or Command Sequencer Instruction Buffer is not Initialised properly");
   #endif
  }
  l_mml_gdc_display = 0;
  UTIL_SUCCESS(ret, mmlGdcIrsDispOpenDisplay((MML_GDC_IRS_DISP_PROPERTIES*)&l_mml_gdc_dispParams, &l_mml_gdc_display));
}
/****************************************************************************
Function Name        : void context_fjt_layer_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : Layer index
******************************************************************************/
static UINT32 context_fjt_layer_init(UINT32 p_index)
{
    u_gx_flocal    fl_pix_format = lc_layer_def_S[p_index].pix_format;
    MML_GDC_DISP_WINDOW_PROPERTIES fl_mml_gdc_disp_winprop;
    MML_GDC_SURF_FORMAT fl_gdc_pix_format;
    UINT32         j;
    MM_S32 ret = MML_OK;
    MM_U08 fl_ditherenable = (MM_U08)0;
    MML_GDC_DISP_DITHER_FORMAT fl_ditherformat = MML_GDC_DISP_DITHER_FORMAT_888;
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];

    UTIL_SUCCESS(ret, mmlGdcPeResetContext(&l_mml_gdc_pixeng_ctx_c[p_index]));
    fl_gdc_pix_format = hmi_gfx_mgr02_irislib_get_disp_pix_format(fl_pix_format);
    for(j=(UINT32)0; j < (UINT32)GFX_DRIVER_NUM_FB; j++)
    {
       UTIL_SUCCESS(ret, mmlGdcSmResetSurfaceObject(&l_mml_gdc_store_surf_c[p_index][j]));

       fl_fb_info_SP[p_index].fb_ptr[j] = hmi_gfx_mgr02_context_alloc_fb(fl_pix_format,
                                       (u_gx_flocal)lc_layer_def_S[p_index].area.width,
                                       (u_gx_flocal)lc_layer_def_S[p_index].area.height);
       UTIL_SUCCESS(ret, mmlGdcSmAssignBuffer(&l_mml_gdc_store_surf_c[p_index][j], 
                                              (MM_U32)lc_layer_def_S[p_index].area.width, 
                                              (MM_U32)lc_layer_def_S[p_index].area.height, 
                                              fl_gdc_pix_format, 
                                              (void*)fl_fb_info_SP[p_index].fb_ptr[j], (MM_U32)0));
    }
    fl_mml_gdc_disp_winprop.topLeftX = (MM_U32)lc_layer_def_S[p_index].area.x;
    fl_mml_gdc_disp_winprop.topLeftY = (MM_U32)lc_layer_def_S[p_index].area.y;
    fl_mml_gdc_disp_winprop.width    = (MM_U32)lc_layer_def_S[p_index].area.width;
    fl_mml_gdc_disp_winprop.height   = (MM_U32)lc_layer_def_S[p_index].area.height;
    fl_mml_gdc_disp_winprop.layerId  = (MM_U32)MML_GDC_DISP_LAYER_0;
    fl_mml_gdc_disp_winprop.layerId += p_index;

    l_mml_gdc_disp_window[p_index] = 0;
    UTIL_SUCCESS(ret, mmlGdcDispCreateWindow(l_mml_gdc_display, 
                                             &fl_mml_gdc_disp_winprop, 
                                             &l_mml_gdc_disp_window[p_index]));
    UTIL_SUCCESS(ret, mmlGdcPeAttribute(&l_mml_gdc_pixeng_ctx_c[p_index], 
                      MML_GDC_PE_ATTR_ZERO_POINT, 
                      MML_GDC_PE_ATTR_ZERO_UP_LEFT));

    UTIL_SUCCESS(ret, mmlGdcDispSetAttribute(l_mml_gdc_display, 
                                             l_mml_gdc_disp_window[p_index], 
                                             MML_GDC_DISP_ATTR_ENABLE_VSYNC, (MM_U32)MM_TRUE));
    switch(lc_layer_def_S[p_index].pix_format)
    {
    case GFX_MGR02_PIX_FORMAT_RGB565:
        fl_ditherformat =MML_GDC_DISP_DITHER_FORMAT_565;
        fl_ditherenable =(MM_U08)MM_TRUE;
    break;
    case GFX_MGR02_PIX_FORMAT_RGB666:
        fl_ditherformat =MML_GDC_DISP_DITHER_FORMAT_666;
        fl_ditherenable = (MM_U08)MM_TRUE;
    break;
    case GFX_MGR02_PIX_FORMAT_RGB888:
        fl_ditherformat =MML_GDC_DISP_DITHER_FORMAT_888;
        fl_ditherenable = (MM_U08)MM_TRUE;
    break;
    default:
        fl_ditherformat =MML_GDC_DISP_DITHER_FORMAT_888;
        fl_ditherenable = (MM_U08)MM_FALSE;
    break;
    }
    
    UTIL_SUCCESS(ret, mmlGdcDispDitherCtrl(l_mml_gdc_display,(MM_BOOL)fl_ditherenable,MML_GDC_DISP_SPATDITH,MML_GDC_DISP_DITHER_ALIGNMENT_LEFT,fl_ditherformat));

    return TRUE;
}
#endif
#if defined(GFX_MGR02_AMBER_IRIS)
/****************************************************************************
Function Name        : void context_amber_iris_layer_init()
Description          : Initializes amber iris pixel engine
Invocation           : When ever generic context needs to be initialized
Return Value         : void
Critical Section     : None
Parameters           : Layer index
******************************************************************************/
static void context_amber_iris_layer_init(UINT32 p_layer)
{
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP;
    UINT32                fl_fb_index;
    MML_GDC_PE_CONTEXT    fl_pe_cntx;
    MML_GDC_SURFACE       fl_str_surf;
    MML_GDC_SURF_FORMAT   fl_gdc_pix_format;
    MM_S32                ret;
    IrisMemInfo fl_memory_s;
    fl_fb_info_SP = &l_fb_info_S[p_layer];
    #if !defined(GFX_MGR02_AMBER)
    HMI_GFX_MGR02_AMBER_IRIS_INIT();
    #endif

    for(fl_fb_index=(UINT32)0; fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB; fl_fb_index++)
    {
        fl_pe_cntx  = l_ambr_irs_mml_gdc_pixeng_ctx[p_layer];
        fl_str_surf = l_ambr_irs_mml_gdc_store_surf[p_layer][fl_fb_index];

        if(fl_pe_cntx == (MML_GDC_PE_CONTEXT)NULL)
        {
            IRIS_API_CHECK(ret, mmlGdcPeGenContext(&fl_pe_cntx));
         #if ((GFX_MGR02_NUM_OF_SVGS >0)|| (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
            if(l_ambr_irs_de_path_buffer[p_layer]==NULL)
            {

                fl_memory_s.MemCateg = IRIS_DE_PATH_BUFFER;
                fl_memory_s.WidgetClientId = 0xFFFFFFFF;
                fl_memory_s.Alignment = (UINT32)4; /*4 Byte alignement*/
                fl_memory_s.Size = (UINT32)GFX_MGR02_DE_PATHBUF_SIZE;
                fl_memory_s.ExtMemory = (UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
                #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
                #endif
                l_ambr_irs_de_path_buffer[p_layer]= hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);

                if(l_ambr_irs_de_path_buffer[p_layer]!=NULL)
                {
                    IRIS_API_CHECK(ret, mmlGdcDeSetPathBuffer(fl_pe_cntx, l_ambr_irs_de_path_buffer[p_layer], (MM_U32)GFX_MGR02_DE_PATHBUF_SIZE));
                }
            }
         #endif
         #ifdef GFX_MGR02_ENABLE_HW_DITHERING
            if(lc_layer_def_S[p_layer].pix_format < (UINT8)GFX_MGR02_PIX_FORMAT_RGB888)
            {
            #ifdef GFX02_DEBUG_INFO
                printf("GDC_PE_CTX_ATTR_DITHER set for client %d\n", p_cgb->client_id);
            #endif
                IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_COLOR, (MM_U32)MM_TRUE));
                IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_ALPHA, (MM_U32)MM_TRUE));
            }
         #endif
        }
        if(fl_pe_cntx != (MML_GDC_PE_CONTEXT)NULL)
        {
            IRIS_API_CHECK(ret, mmlGdcSmGenSurfaceObjects((MM_U32)1, &fl_str_surf));
            if(fl_str_surf != (MML_GDC_SURFACE)NULL)
            {
                UINT32 fl_bpp;
                fl_gdc_pix_format = hmi_gfx_mgr02_amber_get_wdg_pix_format((u_gx_flocal)lc_layer_def_S[p_layer].pix_format);
                fl_bpp          = hmi_gfx_mgr02_get_bpp(fl_gdc_pix_format);

                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_str_surf, 
                    (MM_U32)lc_layer_def_S[p_layer].area.width, 
                    (MM_U32)lc_layer_def_S[p_layer].area.height, 
                    fl_gdc_pix_format, 
                    NULL, 
                    (MM_U32)0));
                if(fl_fb_index == (UINT32)0)
                {
                    fl_memory_s.MemCateg = IRIS_PIXENG_FRONT_RENDER_BUFFER;
                }
                else
                {
                    fl_memory_s.MemCateg = IRIS_PIXENG_BACK_RENDER_BUFFER;
                }
                fl_memory_s.WidgetClientId = 0xFFFFFFFFu; /*Client Id for merge Widget*/
                fl_memory_s.Alignment = (UINT32)32;       /*32 Byte alignement*/
                fl_memory_s.Size = (((UINT32)lc_layer_def_S[p_layer].area.width*lc_layer_def_S[p_layer].area.height*fl_bpp)>>3U);
                #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
                fl_memory_s.ExtMemory = (UINT8)0;
                #else
                fl_memory_s.ExtMemory = (UINT8)0; 
                #endif
                #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
                #endif
                fl_fb_info_SP->fb_ptr[fl_fb_index] =  hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
                #ifdef GFX02_DEBUG_INFO
                if(fl_fb_info_SP->fb_ptr[fl_fb_index] == (UINT32)0)
                {
                    printf("VRAM allocation  Failed\n");
                }
                #endif
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, 
                                                         MML_GDC_SURF_ATTR_BASE_ADDRESS, 
                                                         (MM_U32)fl_fb_info_SP->fb_ptr[fl_fb_index]));

            }

        }

        l_ambr_irs_mml_gdc_store_surf[p_layer][fl_fb_index] = fl_str_surf;
        l_ambr_irs_mml_gdc_pixeng_ctx[p_layer]              = fl_pe_cntx;

    }
}
#endif

#if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT)
/****************************************************************************
Function Name        : void context_imxrt_pxp_layer_init()
Description          : Initializes imxrt_pxp pixel engine
Invocation           : When ever generic context needs to be initialized
Return Value         : void
Critical Section     : None
Parameters           : Layer index
******************************************************************************/
static void context_imxrt_pxp_layer_init(UINT32 p_layer)
{
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP;
    UINT32                fl_fb_index;
    pxp_output_pixel_format_t fl_gdc_pix_format;
    PixEngMemInfo fl_memory_s;
    if (p_layer < GFX_MGR02_NUM_LAYERS)
    {
        fl_fb_info_SP = &l_fb_info_S[p_layer];
        #if !defined(GFX_MGR02_IMXRT)
        hmi_gfx_mgr02_imxrt_lcdif_display_initialize();
        hmi_gfx_mgr02_imxrt_lcdif_layer_initialize(p_layer);
        #endif
        for(fl_fb_index=(UINT32)0; fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB; fl_fb_index++)
        {
            UINT32 fl_bpp;
            fl_gdc_pix_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format((u_gx_flocal)lc_layer_def_S[p_layer].pix_format);
            fl_bpp          = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_gdc_pix_format);
            if(fl_fb_index == (UINT32)0)
            {
                fl_memory_s.MemCateg = IMXRT_LAYER_FRONT_RENDER_BUFFER;
            }
            else
            {
                fl_memory_s.MemCateg = IMXRT_LAYER_BACK_RENDER_BUFFER;
            }
            fl_memory_s.WidgetClientId = 0xFFFFFFFFu; /*Client Id for merge Widget*/
            fl_memory_s.Alignment = (UINT32)32;       /*32 Byte alignement*/
            fl_memory_s.Size = (((UINT32)lc_layer_def_S[p_layer].area.width*lc_layer_def_S[p_layer].area.height*fl_bpp)>>3U);
            fl_memory_s.ExtMemory = (UINT8)0; 
            #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
            fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
            #endif
            fl_fb_info_SP->fb_ptr[fl_fb_index] =  hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
            
            #ifdef GFX02_DEBUG_INFO
            if(fl_fb_info_SP->fb_ptr[fl_fb_index] == (UINT32)0)
            {
                printf("VRAM allocation  Failed\n");
            }
            #endif
            
            #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                hmi_gfx_mgr02_context_allocate_decompr_buffer();
            #endif 
        }
    }
}
#endif

#if defined(GFX_MGR02_SOFTWARE)
/****************************************************************************
Function Name        : void context_swr_pre_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void context_swr_pre_init(void)
{
  #if defined(GFX_MGR02_USE_TIDSS)
  l_fb_total_available_size = (GFX_DRIVER_NUM_FB * (UINT32)GFX_MGR02_LAYERS_MAX_WIDTH * (UINT32)GFX_MGR02_LAYERS_MAX_HEIGHT * GFX_MGR02_LAYERS_BYTES_PER_PIXEL);
  l_fb_cur_address          = (UINT32)l_frame_buffer;
  #elif defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE)
  l_fb_total_available_size = GFX_MGR02_SOFTWARE_FB_SIZE;
  l_fb_cur_address          = GFX_MGR02_SOFTWARE_FB_ADDRESS;
  #endif
  
  #if defined(GFX_MGR02_USE_TIDSS)
  for(UINT8 fl_index = (UINT8)0; fl_index < (UINT8)GFX_MGR02_NUM_LAYERS; fl_index++)
  {
    (void)memset((void*)l_frame_buffer, 0x00, (size_t)(l_fb_total_available_size));
    
    (void)hmi_gfx_mgr02_tidss_dispif_init(fl_index);
  }
  #endif
}
#endif

#if defined(GFX_MGR02_MONOTFT)
/****************************************************************************
Function Name        : void hmi_context_monolib_pre_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/

static void hmi_context_monolib_pre_init(void)
{
  #if defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE)
   l_fb_total_available_size = GFX_MGR02_SOFTWARE_FB_SIZE;
   l_fb_cur_address          = GFX_MGR02_SOFTWARE_FB_ADDRESS;
  #endif
}
#endif
/****************************************************************************
Function Name        : UINT32 hmi_gfx_mgr02_context_initialize()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : UINT32, boolean of context init status
Critical Section     : None
Parameters           : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_context_initialize(void)
{
#if defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)
   UINT32                fl_index,j;
   u_gx_flocal           fl_pix_format;
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[0];
#endif
#if defined(GFX_MGR02_OPEN_VG)
   UINT32                fl_ret_status = FALSE;
#else
   UINT32                fl_ret_status;	
#endif

#if defined(GFX_MGR02_SOFTWARE)
   context_swr_pre_init();
#elif defined(GFX_MGR02_MONOTFT) && defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE)
   hmi_context_monolib_pre_init();
#elif defined(GFX_MGR02_FUJITSU)
   context_fjt_pre_init();
#endif

#if defined(GFX_MGR02_OPEN_VG)
   if(context_ovg_pre_init() != FALSE)
#endif
   {
   #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)
     for(fl_index=(UINT32)0; fl_index < (UINT32)GFX_MGR02_NUM_LAYERS; fl_index++)
     {
       fl_fb_info_SP[fl_index].frnt_id   = (UINT8)GFX_DRIVER_NUM_FB;
       fl_fb_info_SP[fl_index].back_id   = (UINT8)GFX_DRIVER_NUM_FB;
       fl_fb_info_SP[fl_index].last_id   = (UINT8)GFX_DRIVER_NUM_FB;
       fl_fb_info_SP[fl_index].client_id = (UINT16)GFX_MGR02_INVALID_CLIENT_ID;

       for(j=(UINT32)0; j < (UINT32)GFX_DRIVER_NUM_FB; j++)
       {
         fl_fb_info_SP[fl_index].fb_ptr[j] = (void *)0;
         fl_fb_info_SP[fl_index].fb[j].val = (UINT8)0;
       }

       fl_pix_format = lc_layer_def_S[fl_index].pix_format;

       if(fl_pix_format < (u_gx_flocal)GFX_MGR02_NUM_PIX_FORMATS)
       {
        #if defined(GFX_MGR02_OPEN_VG)
         if(lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_OPENVG)
         {
           if(context_ovg_layer_init(fl_index) == FALSE)
           {
             break;
           }
         }
         else
        #endif /* #if defined(GFX_MGR02_OPEN_VG) */
        #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT)
         if((lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_SOFTWARE)||
             (lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_MONOTFT))
         {
           for(j=0; j < GFX_DRIVER_NUM_FB; j++)
           {
             fl_fb_info_SP[fl_index].fb_ptr[j] = hmi_gfx_mgr02_context_alloc_fb(fl_pix_format, 
                                                                         lc_layer_def_S[fl_index].area.width, 
                                                                         lc_layer_def_S[fl_index].area.height);
           }
         }
         else
        #endif /* #if defined(GFX_MGR02_SOFTWARE) */
        #if defined(GFX_MGR02_FUJITSU)
         if(lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_FUJITSU)
         {
           if(context_fjt_layer_init(fl_index) == FALSE)
           {
             break;
           }
         }
        #endif/* #if defined(GFX_MGR02_FUJITSU) */
        #if defined(GFX_MGR02_AMBER_IRIS)
         if(lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_AMBER_IRIS)
         {
           context_amber_iris_layer_init(fl_index);
         }
        #endif/* #if defined(GFX_MGR02_AMBER_IRIS) */
        #if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT) 
         if(lc_layer_def_S[fl_index].target == GFX_MGR02_TARGET_IMXRT_PXP)
         {
           context_imxrt_pxp_layer_init(fl_index);
         }
        #endif/* #if defined(GFX_MGR02_IMXRT_PXP) */        
         {
         }
       }
     }
   #endif  /* #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_FUJITSU)*/
   #if defined(GFX_MGR02_OPEN_VG)
     /* check if all layer init loops completed (no errors). */
     if(fl_index >= (UINT32)GFX_MGR02_NUM_LAYERS)
   #endif
     {
#if defined(GFX_MGR02_OPEN_GL)	&&  defined(GFX_MGR02_DYNAMIC_BOUNDS_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
       l_context_S.rprop.gl_string_ptr = NULL;
#endif
       l_context_S.rprop.alignment = (UINT8)0;
       l_context_S.rprop.draw_mode = (UINT8)0;
       l_context_S.rprop.clip_mode = (UINT8)0;
       l_context_S.rprop.font_id   = (UINT8)0;
       l_context_S.rprop.clut      = (UINT16)0;
       l_context_S.rprop.fg_color  = (GFX_MGR02_COLOR)0;
       l_context_S.rprop.bg_color  = (GFX_MGR02_COLOR)0;
     #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2) || defined (GFX_MGR02_VGLITE)
       l_context_S.rprop.pivot.x = (GFX_MGR02_FSIZE_X_T)0;
       l_context_S.rprop.pivot.y = (GFX_MGR02_FSIZE_Y_T)0;
     #endif
     #if defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(__MQXOS__)
       hmi_gfx_mgr02_driver_mqx_dcu_init();
     #endif
     #if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
       hmi_gfx_mgr02_context_widget_init();
     #endif 
     #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)
       hmi_gfx_mgr02_generic_initialize();
     #endif
     #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
      #if (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT) && (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_DIGITYPE)
        context_ext_font_engine_initialize();
      #endif
     #endif
     #if defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
      (void)hmi_gfx_mgr02_ovg_text_context_initialize();
     #endif
      #if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_AMBER) || defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)
      {
          #if defined(GFX_STRING_CACHE_ENABLED)
          hmi_gfx_mgr02_cache_init();
          #endif
      }
      #endif
      fl_ret_status = TRUE;
     }
   }
   return fl_ret_status;
}

#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT) && (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_DIGITYPE)
/****************************************************************************
Function Name        : void context_ext_font_engine_initialize()
Description          : Initializes external font engine for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void context_ext_font_engine_initialize(void)
{
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)
    FT_Error fl_ft_error;
    UINT32   fl_font_id;
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined (GFX_MGR02_KEPLER)
    UINT32   fl_font_id;
#endif

#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)
    #if defined(GFX_MGR02_USER_DEFINED_MM)
    static struct FT_MemoryRec_ l_ft2_memory;
    l_ft2_memory.user    = NULL;
    l_ft2_memory.alloc   = (FT_Alloc_Func)MemAlloc;
    l_ft2_memory.free    = (FT_Free_Func)MemFree;
    l_ft2_memory.realloc = (FT_Realloc_Func)MemRealloc;
    fl_ft_error = FT_New_Library( &l_ft2_memory, &l_context_S.rprop.ft2_library );
    FT_Add_Default_Modules(l_context_S.rprop.ft2_library);   
    #else
    fl_ft_error = FT_Init_FreeType(&l_context_S.rprop.ft2_library);
    #endif   
    l_ft_init_status = fl_ft_error;
    if(fl_ft_error == 0)
    {
        GFX_MGR02_FONT const * fl_font;
        #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
        fl_ft_error = hmi_gfx_mgr02_ft2_cache_init(l_context_S.rprop.ft2_library);
        if(fl_ft_error == 0)
        #endif
        {
            for(fl_font_id = 0; fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS; fl_font_id++)
            {
                l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face = NULL;
                fl_font = &lc_gfx_font_table[fl_font_id];
                if((fl_font->is_group == (UINT8)0) && (fl_font->is_ffile != (UINT8)0))
                {
                    #if defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                    fl_ft_error = hmi_gfx_mgr02_ft2_cache_face_init(fl_font_id);
                    if(fl_ft_error == 0)
                    {
                        l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_font_size = (UINT8)fl_font->height_pts;
                    }
                    #else
                    UINT8 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(fl_font_id);
                    if (fl_ft2_face_index == fl_font_id)
                    {
                    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
                      fl_ft_error = FT_New_Memory_Face( l_context_S.rprop.ft2_library, 
                                                    fl_font->f.ffile_name, 
                                                    (FT_Long)fl_font->extfontsize, 
                                                    0, 
                                                    &l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face);
                    #else
                      fl_ft_error = FT_New_Face(l_context_S.rprop.ft2_library,
                                            fl_font->f.ffile_name,
                                            0,
                                            &l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face);
                    #endif
                    }
                    else
                    {
                      l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face = l_context_S.rprop.ft2_faceprop[fl_ft2_face_index].ft2_face;
                    }
                    if(fl_ft_error == 0)
                    {
                        GFX_FLOAT ptsize;
                        #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && !(defined(GFX_MGR02_VGLITE))
                        GFX_FLOAT per;
                        FT_Face                face;
                        face    = l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face;
                        per     = ((GFX_FLOAT)face->ascender/(GFX_FLOAT)(face->ascender-face->descender));
                        ptsize  = ((GFX_FLOAT)(fl_font->p.height * 72 * 64)/(GFX_FLOAT)GFX_MGR02_DPI);
                        ptsize *= per;
                        #else
                        ptsize = (fl_font->height_pts*64.0f);
                        #endif
                        fl_ft_error = FT_Set_Char_Size(
                                           l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face,   /* handle to face object           */
                                           0,                                        /* char_width in 1/64th of points  */
                                           (FT_F26Dot6)ptsize,                                   /* char_height in 1/64th of points */
                                           GFX_MGR02_DPI,                            /* horizontal device resolution    */
                                           GFX_MGR02_DPI );                          /* vertical device resolution      */
                        if(fl_ft_error == 0)
                        {
                            #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && !(defined(GFX_MGR02_VGLITE))
                            l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_font_size = (UINT8)fl_font->p.height;
                            #else
                            l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_font_size = (UINT8)fl_font->height_pts;
                            #endif
                        }
                    }
                    #endif
                }
            }
        }
    }
#endif

#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined (GFX_MGR02_KEPLER)
    /*unsigned long heapSize = 512*1024;  specify 512 KB heap size for FS_init */
    #ifndef GFX_MGR02_MONOTYPE_HEAP_SIZE
    l_ft_init_status = FS_init(&l_context_S.rprop.mt_fs_state,512U*1024U);
    #else
    l_ft_init_status = FS_init(&l_context_S.rprop.mt_fs_state,(FS_ULONG)GFX_MGR02_MONOTYPE_HEAP_SIZE);
    #endif
    if(l_ft_init_status == SUCCESS)
    {
        GFX_MGR02_FONT const * fl_font;
        l_mt_client_state = FS_new_client(&l_context_S.rprop.mt_fs_state, 0); 
        for(fl_font_id=0U; fl_font_id<(UINT32)GFX_MGR02_NUM_OF_FONTS;fl_font_id++)
        {
            l_context_S.rprop.mt_font_name[fl_font_id][0] = (FILECHAR)0;
            fl_font = &lc_gfx_font_table[fl_font_id];
            if((fl_font->is_group == 0U) && (fl_font->is_ffile != 0U))
            {
                #if defined(GFX_MGR02_USE_FILESYSTEM)
                /* Add the font to the list of fonts known by iType. */ /* Returns name of loaded font in name buffer. */ 
                (void)FS_load_font(&l_context_S.rprop.mt_fs_state,  (FILECHAR *)fl_font->f.ffile_name, GFX_MGR02_NULL_PTR, 0, MAX_FONT_NAME_LEN, (FILECHAR *)&l_context_S.rprop.mt_font_name[fl_font_id]);
                #else
                /* Add the font to the list of fonts known by iType. */ /* Returns name of loaded font in name buffer. */ 
                (void)FS_load_font(&l_context_S.rprop.mt_fs_state, GFX_MGR02_NULL_PTR, (FS_BYTE *)fl_font->f.ffile_name, 0, MAX_FONT_NAME_LEN, (FILECHAR *)&l_context_S.rprop.mt_font_name[fl_font_id]);
                #endif 
            }
        }
    }
#endif

#if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
    (void)hmi_gfx_mgr02_shape_engine_initialize();
#endif
}

#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined (GFX_MGR02_KEPLER)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_mt_client_handler()
Description          : Returns the client handler of monotype font engine
Invocation           : By get text width interface
Return Value         : Client Handler
Critical Section     : None
Parameters           : None
******************************************************************************/
FS_STATE* hmi_gfx_mgr02_get_mt_client_handler(void)
{
  return l_mt_client_state;
}
#endif /* (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined (GFX_MGR02_KEPLER) */
 #endif	 /* (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT) && (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_DIGITYPE) */
#endif   /* GFX_MGR02_USE_EXT_FONT_ENGINE */

#if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)
#if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT)

#if ((GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0)||(GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
/****************************************************************************
Function Name        : void hmi_gfx_mgr02_context_widget_init()
Description          : Initializes internal data for the kepler openvg widget
                       rendering context
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void hmi_gfx_mgr02_context_widget_init(void)
{
  UINT32 i;
  UINT32 j;
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)
  GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_dcu_fb_info_S[0];

  for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS; i++)
  {
    fl_fb_info_SP->active  = (UINT8)0;
    fl_fb_info_SP->frnt_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->back_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->last_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->ready   = (UINT8)0;
    l_dcu_fb_context[i]    = EGL_NO_CONTEXT;
    l_dcu_fb_config[i]     = (EGLConfig)0;
    for(j=(UINT32)0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
    {
      l_dcu_fb_width[i][j]     = (UINT16)0;
      l_dcu_fb_height[i][j]    = (UINT16)0;
      fl_fb_info_SP->fb_ptr[j] = (void *)0;
      fl_fb_info_SP->fb[j].val = (UINT8)0;
      l_dcu_fb_surface[i][j]   = EGL_NO_SURFACE;
    }
    fl_fb_info_SP++;
  }
#else
#if defined (GFX_MGR02_IMXRT)
  GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[0];
#else
  GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_amber_fb_info_S[0];
#endif
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0)
  UINT16                  fl_img_id;
  UINT16                  fl_client_id;
  const GFX_MGR02_IMAGE_DEF_T * fl_runtime_widget_ptr;
#endif
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)/*To avoid coverity warning CID 5620904: Logically dead code (DEADCODE)*/
  UINT32 fl_fb_info_count =   ((UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS-(UINT32)1);
#endif
  for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
  {
    fl_fb_info_SP->active  = (UINT8)0;
    fl_fb_info_SP->frnt_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->back_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->last_id = (UINT8)GFX_DRIVER_NUM_FB;
    fl_fb_info_SP->ready   = (UINT8)0;
#if !defined (GFX_MGR02_IMXRT)
    l_mml_gdc_pixeng_ctx[i]    = (MML_GDC_PE_CONTEXT)0;
#endif
    for(j=(UINT32)0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
    {
      fl_fb_info_SP->fb_ptr[j]   = NULL;
      fl_fb_info_SP->fb[j].val   = (UINT8)0;
#if !defined (GFX_MGR02_IMXRT)
      l_mml_gdc_store_surf[i][j] = (MML_GDC_SURFACE)0;
#endif
    }
#if defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_TRAVEO2)
#if ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))))
    l_de_path_buffer[i]=NULL;
#endif
#endif
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)/*To avoid coverity warning CID 5620904: Logically dead code (DEADCODE)*/
    if (i != fl_fb_info_count)
    {
      fl_fb_info_SP++;
    }
#endif
  }
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && (GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0)
  for(i = (UINT32)0; i < (UINT32)GFX_MGR02_NUM_OF_SWDGS; i++)
  {
      fl_img_id = lc_swidget_layer_def_S[i].image_id;
      fl_client_id = lc_swidget_layer_def_S[i].client_id; 
      if((lc_swidget_layer_def_S[i].merge!=(UINT8)0) && (fl_client_id < GFX_MGR02_NUM_AMBER_MERGE_WIDGETS))
      {
         for(j=(UINT32)0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
         {
            if(lc_swidget_layer_def_S[i].clip_mode == GFX_MGR02_WP_CLIP_NONE)
            {
                #if !defined(GFX_MGR02_IMXRT)
                fl_runtime_widget_ptr = hmi_gfx_mgr02_amber_get_runtime_widget_ptr(fl_img_id);
                #else
                fl_runtime_widget_ptr = hmi_gfx_mgr02_imxrt_get_runtime_widget_ptr(fl_img_id);
                #endif	
                if(fl_runtime_widget_ptr !=NULL)
                {	
                    #if !defined(GFX_MGR02_IMXRT)
                    l_amber_fb_width[fl_client_id][j]  = fl_runtime_widget_ptr->width;
                    l_amber_fb_height[fl_client_id][j] = fl_runtime_widget_ptr->height;
                    #else
                    l_imxrt_fb_width[fl_client_id][j]  = fl_runtime_widget_ptr->width;
                    l_imxrt_fb_height[fl_client_id][j] = fl_runtime_widget_ptr->height;
                    #endif
                }
                else
                {
                    #if defined(GFX_MGR02_IMXRT)
                    l_imxrt_fb_width[fl_client_id][j] = (UINT16)0;
                    l_imxrt_fb_height[fl_client_id][j] = (UINT16)0;
                    #else
                    l_amber_fb_width[fl_client_id][j] = (UINT16)0;
                    l_amber_fb_height[fl_client_id][j] = (UINT16)0;
                    #endif 
                }
            }
            else
            {
                #if defined(GFX_MGR02_IMXRT)
                l_imxrt_fb_width[fl_client_id][j] = (UINT16)0;
                l_imxrt_fb_height[fl_client_id][j] = (UINT16)0;
                #else
                l_amber_fb_width[fl_client_id][j] = (UINT16)0;
                l_amber_fb_height[fl_client_id][j] = (UINT16)0;
                #endif
            }
         }
      } 
  }
#endif  
#endif
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_prepare
Description          : This function makes all the widget context to be in
                       inactive state. This is called prior to a screen build
                       operation by layout manager. During the screen build
                       active widgets context will be set to active state by
                       hmi_gfx_mgr02_context_widget_set_active() function call
                       during the build time. This will help to determine how
                       many widgets are really active after the build operation
                       by layout manager. So that the resource reserved by 
                       inactive widgets can be freed up by function
                       hmi_gfx_mgr02_context_widget_done()
Invocation           : Called by layout manager before the build operation
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_widget_prepare(void)
{
   UINT32 i;
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_dcu_fb_info_S[0];

   for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS; i++)
   {
      fl_fb_info_SP->active = (UINT8)0;
      fl_fb_info_SP++;
   }
#else
   #if !defined (GFX_MGR02_IMXRT)
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_amber_fb_info_S[0];
   #else	   
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[0];
   #endif 

   for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
   {
      fl_fb_info_SP->active = (UINT8)0;
      fl_fb_info_SP++;
   }
   GFX_MGR02_UNUSED_VAR(fl_fb_info_SP);
#endif
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_swap_widget
Description          : Makes the BG buffer the active buffer
Invocation           : Invoked by build screen
Return Value         : Pointer to active frame buffer
Critical Section     : None
Parameters           : Client ID
******************************************************************************/
void * hmi_gfx_mgr02_context_swap_widget(u_gx_flocal p_client_id)
{
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = NULL;
    
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2) && !defined(GFX_MGR02_IMXRT)
    if(p_client_id <(UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS)
    {
        fl_fb_info_SP = &l_dcu_fb_info_S[p_client_id];
    }
#else
    if(p_client_id <(UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
        #if defined(GFX_MGR02_IMXRT)
    fl_fb_info_SP = &l_imxrt_fb_info_S[p_client_id];
    #else
        fl_fb_info_SP = &l_amber_fb_info_S[p_client_id];
    #endif	    
    }
#endif
    return(hmi_gfx_mgr02_context_swap_fb(fl_fb_info_SP));
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_end_update
Description          : Called by the generic library after finishing the 
                       building of a DCU ovg widget layer
Invocation           : Invoked by generic library
Return Value         : None
Critical Section     : None
Parameters           : Client ID
******************************************************************************/
void hmi_gfx_mgr02_context_widget_end_update(UINT32 p_client_id, 
                                             UINT32 p_updated
#if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)
                                             ,UINT8 p_use_extram
#endif
                                             )
{
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = NULL;
    UINT32                fl_fb_index ;
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2) && !defined(GFX_MGR02_IMXRT)

    if(p_client_id < (UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS)
    {
        fl_fb_info_SP = &l_dcu_fb_info_S[p_client_id];
    }
#else
    if(p_client_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
        #if defined(GFX_MGR02_IMXRT)
        fl_fb_info_SP = &l_imxrt_fb_info_S[p_client_id];
        #else 			
        fl_fb_info_SP = &l_amber_fb_info_S[p_client_id];
        #endif
    }
#endif
    if(fl_fb_info_SP !=NULL)
    {
        fl_fb_index = fl_fb_info_SP->back_id;
    }

#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)
   if(eglMakeCurrent(dsp, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT) == EGL_FALSE)
   {
      GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
   }
#endif
   if((fl_fb_info_SP !=NULL)&&(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)&&(fl_fb_info_SP->fb[fl_fb_index].sts.b_locked != (UINT8)0))
   {
      if(p_updated != (UINT32)FALSE)
      {
      #if defined(WIN32)
         if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_OPENVG)
         {
            eglCopyVGtoSurface();
         }
      #endif
         fl_fb_info_SP->fb[fl_fb_index].sts.b_locked = (UINT8)0;
      #ifdef GFX_MGR02_AMBER_USE_VRAM_HRAM
         if(p_use_extram != GFX_MGR02_USE_VRAM_HRAM)
         {
            fl_fb_info_SP->last_id = fl_fb_info_SP->back_id;
         }
      #else
         fl_fb_info_SP->last_id = fl_fb_info_SP->back_id;
      #endif
         fl_fb_info_SP->fb[fl_fb_index].sts.b_update = (UINT8)1;
         fl_fb_info_SP->ready   = (UINT8)1;
      }
      else
      {
         fl_fb_info_SP->fb[fl_fb_index].val = (UINT8)0;
      }
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_done
Description          : This function releases all resources held by inactive
                       widget contexts.
Invocation           : Called by layout manager after the build operation
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_widget_done(void)
{
    UINT32 i;
    UINT32 j;
#if !defined(GFX_MGR02_AMBER) && !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_dcu_fb_info_S[0];

    for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_DCU_OVG_WIDGETS; i++)
    {
        if(fl_fb_info_SP->active == (UINT8)0)
        {
            fl_fb_info_SP->frnt_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->back_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->last_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->ready   = (UINT8)0;

            for(j=(UINT32)0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
            {
                l_dcu_fb_width[i][j]     = (UINT16)0;
                l_dcu_fb_height[i][j]    = (UINT16)0;
                fl_fb_info_SP->fb_ptr[j] = (void *)0;
                fl_fb_info_SP->fb[j].val = (UINT8)0;
                if(l_dcu_fb_surface[i][j] != EGL_NO_SURFACE)
                {
                    if(eglDestroySurface(dsp, l_dcu_fb_surface[i][j]) == EGL_FALSE)
                    {
                        GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLDESTROYSURFACE_FAULT);
                    }
                    l_dcu_fb_surface[i][j] = EGL_NO_SURFACE;
                }
            }
        }
        fl_fb_info_SP++;
    }
#else
    #if defined(GFX_MGR02_IMXRT)
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[0];
    #else
    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_amber_fb_info_S[0];
    #endif
 #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)
    UINT32 fl_fb_info_count =   ((UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS-(UINT32)1);
 #endif
    for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
    {
        if(fl_fb_info_SP->active == (UINT8)0)
        {
            fl_fb_info_SP->frnt_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->back_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->last_id = (UINT8)GFX_DRIVER_NUM_FB;
            fl_fb_info_SP->ready   = (UINT8)0;

            for(j=0; j<(UINT32)GFX_DRIVER_NUM_FB; j++)
            {
                if(fl_fb_info_SP->fb_ptr[j] != NULL)
                {
                    #if defined(GFX_MGR02_IMXRT)
                        hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_fb_info_SP->fb_ptr[j]);
                    #else
                        hmi_gfx_mgr02_amber_mem_mgmt_free(fl_fb_info_SP->fb_ptr[j]);
                    #endif                    
                    fl_fb_info_SP->fb_ptr[j] = NULL;
                }
                fl_fb_info_SP->fb[j].val = (UINT8)0;
                /*Free the inactive store surfaces*/
                #if !defined(GFX_MGR02_IMXRT)
                if(l_mml_gdc_store_surf[i][j] !=(MML_GDC_SURFACE)NULL)
                {
                    #if defined(GFX_MGR02_TRAVEO2) && defined(LBO_OTF_FEATURE_CC)
                    UINT8 fl_otf_win_U8 = hmi_gfx_mgr02_is_otf_win_surface(l_mml_gdc_store_surf[i][j]);
                    if(fl_otf_win_U8 == (UINT8)0)
                    {
                        (void)utSmDeleteSurfaceObjects((CYGFX_S32)1, &l_mml_gdc_store_surf[i][j]);
                    }
                    #else
                    (void)mmlGdcSmDeleteSurfaceObjects((MM_U32)1, &l_mml_gdc_store_surf[i][j]);
                    #endif
                    l_mml_gdc_store_surf[i][j] = (MML_GDC_SURFACE)0;
                }
                #endif
            }
            #if !defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)
            #if defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_TRAVEO2)
            /*Delete the inactive Pixel engine context*/
            if(l_mml_gdc_pixeng_ctx[i] != (MML_GDC_PE_CONTEXT)0)
            {
                mmlGdcPeDeleteContext(l_mml_gdc_pixeng_ctx[i]);
                l_mml_gdc_pixeng_ctx[i] = NULL;
            }
            #if ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))))
            if(l_de_path_buffer[i]!=NULL)
            {
                hmi_gfx_mgr02_amber_mem_mgmt_free(l_de_path_buffer[i]);     
                l_de_path_buffer[i]=NULL; 
            }
            #endif
            #endif
            #endif
        }
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 1)/*To avoid coverity warning CID 5620904: Logically dead code (DEADCODE)*/
        if (i != fl_fb_info_count)
        {
            fl_fb_info_SP++;
        }
#endif
    }
#endif
}
#endif /* #if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0 */

#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_done
Description          : This function releases all resources held by inactive
                       widget contexts.
Invocation           : Called by layout manager after the build operation
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_reset_widget_buff_id(void)
{
   #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0)
    UINT32 i;
    /* clear the buffer id here. otherwise hmi_gfx_mgr02_context_is_widget_builded_first() return FALSE. 
       eventhough all the windows are destroyed as window_rebuild flag is set                         */
    for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
    {
       /* frnt_id should not be initialized otherwise both buffer will get locked*/ 
       #if defined(GFX_MGR02_IMXRT)  
       l_imxrt_fb_info_S[i].back_id = (UINT8)GFX_DRIVER_NUM_FB;
       l_imxrt_fb_info_S[i].last_id = (UINT8)GFX_DRIVER_NUM_FB;
       #else		   
       l_amber_fb_info_S[i].back_id = (UINT8)GFX_DRIVER_NUM_FB;
       l_amber_fb_info_S[i].last_id = (UINT8)GFX_DRIVER_NUM_FB;
       #endif
    }
    #endif
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_widget_begin_update
Description          : Called by the generic library before starting the 
                       building of a DCU ovg or swr widget layer
Invocation           : Invoked by generic library
Return Value         : None
Critical Section     : None
Parameters           : Client ID, width, height, format, target and target buffer
******************************************************************************/
GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_widget_begin_update(GFX_MGR02_CONTEXT_GB_T * p_cgb)
{
   GFX_MGR02_CONTEXT_T * fl_cntx_SP = (GFX_MGR02_CONTEXT_T *)0;

   l_context_S.rprop.fb_format = (UINT8)p_cgb->fb_format;
   l_context_S.rprop.fb_target = (UINT8)p_cgb->fb_target;
   l_context_S.rprop.fb_w      = p_cgb->area.width;
   l_context_S.rprop.fb_h      = p_cgb->area.height;
   l_context_S.rprop.fb_P      = p_cgb->render_buffer;
   l_context_S.rprop.layer_id  = (UINT8)GFX_MGR02_NUM_LAYERS+(UINT8)p_cgb->client_id;

#if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0
    if(p_cgb->fb_target == GFX_MGR02_TARGET_OPENVG)
    {
      GFX_MGR02_FB_INFO_T * fl_fb_info_SP;
      UINT32                fl_fb_index;
      EGLSurface            fl_egl_surface;
      EGLContext            fl_egl_context;
      EGLBoolean            ret;
      EGLint                numconfigs;

      fl_fb_info_SP = &l_dcu_fb_info_S[p_cgb->client_id];
      fl_fb_index   = hmi_gfx_mgr02_context_find_next_fb(fl_fb_info_SP);

      if(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)
      {
         EGLint const * fl_config_p;
      #if GFX_MGR02_MAX_EGL_CONFIGS > 1
         EGLint         fl_alpha_size;
         EGLint         fl_green_size;
      #endif

         fl_egl_surface = l_dcu_fb_surface[p_cgb->client_id][fl_fb_index];
         fl_egl_context = l_dcu_fb_context[p_cgb->client_id];
         
         if(fl_egl_context == EGL_NO_CONTEXT)
         {
            /*
            ** Create contexts for DCU openvg widget rendering, one created per supported
            ** buffer formats.
            */
            if(p_cgb->fb_format == (UINT32)GFX_MGR02_PIX_FORMAT_RGB565)
            {
               fl_config_p   = lc_config_attribs_rgb565;
            #if GFX_MGR02_MAX_EGL_CONFIGS > 1
               fl_alpha_size = (EGLint)0;
               fl_green_size = (EGLint)6;
            #endif
            }
            else if(p_cgb->fb_format == (UINT32)GFX_MGR02_PIX_FORMAT_ARGB4444)
            {
               fl_config_p   = lc_config_attribs_argb4444;
            #if GFX_MGR02_MAX_EGL_CONFIGS > 1
               fl_alpha_size = (EGLint)4;
               fl_green_size = (EGLint)4;
            #endif
            }
            else
            {
               fl_config_p   = lc_config_attribs_argb8888;
            #if GFX_MGR02_MAX_EGL_CONFIGS > 1
               fl_alpha_size = (EGLint)8;
               fl_green_size = (EGLint)8;
            #endif
            }
            
         #if GFX_MGR02_MAX_EGL_CONFIGS > 1
            /*
            ** First get number of maximum matching egl configurations.
            ** and then choose the one that macthes our configuration
            */
            ret = eglChooseConfig(dsp, fl_config_p,   0, 0, &numconfigs);
            if((numconfigs > 0) && (ret != EGL_FALSE))
            {
               EGLConfig fl_cfg[GFX_MGR02_MAX_EGL_CONFIGS];
               EGLint    fl_gvalue;
               EGLint    fl_avalue;
               ret = eglChooseConfig(dsp, fl_config_p, &fl_cfg[0], GFX_MGR02_MAX_EGL_CONFIGS, &numconfigs);
               if(ret != EGL_FALSE)
               {
                  ret = EGL_FALSE;
                  while((numconfigs > 0) && (ret == EGL_FALSE))
                  {
                     numconfigs--;
                     if(eglGetConfigAttrib(dsp, fl_cfg[numconfigs], EGL_GREEN_SIZE, &fl_gvalue) != EGL_FALSE)
                     {
                        if(eglGetConfigAttrib(dsp, fl_cfg[numconfigs],EGL_ALPHA_SIZE, &fl_avalue) != EGL_FALSE)
                        {
                           if((fl_gvalue == fl_green_size) && (fl_avalue == fl_alpha_size))
                           {
                              /* This config matches or reequirement */
                              l_dcu_fb_config[p_cgb->client_id] = fl_cfg[numconfigs];
                              ret                          = EGL_TRUE;
                           }
                        }
                     }
                  }
               }
            }
         #else
            ret = eglChooseConfig(dsp, fl_config_p, &l_dcu_fb_config[p_cgb->client_id], 1, &numconfigs);
         #endif
            if(ret != EGL_FALSE)
            {
               fl_egl_context = eglCreateContext(dsp, l_dcu_fb_config[p_cgb->client_id], l_egl_shared_context, NULL);
            }
            else
            {
                GFX_MGR02_LOG_ERROR( GFX_MGR02_EGLCREATECONTEXT_FAULT);
            }
         }
         if(fl_egl_context != EGL_NO_CONTEXT)
         {
            if((fl_egl_surface == EGL_NO_SURFACE) ||
               (l_dcu_fb_width[p_cgb->client_id][fl_fb_index]  != p_cgb->area.width) ||
               (l_dcu_fb_height[p_cgb->client_id][fl_fb_index] != p_cgb->area.height))
            {
               EGLint fl_surface_attrib[5];

               fl_surface_attrib[0] = EGL_WIDTH;
               fl_surface_attrib[1] = (EGLint)p_cgb->area.width;
               fl_surface_attrib[2] = EGL_HEIGHT;
               fl_surface_attrib[3] = (EGLint)p_cgb->area.height;
               fl_surface_attrib[4] = EGL_NONE;

               if(fl_egl_surface != EGL_NO_SURFACE)
               {
                  /*
                  ** If a surface already exists, then its dimentions are changed now
                  ** so delete current and recreate a new surface.
                  */ 
                  (void)eglDestroySurface(dsp, fl_egl_surface);
               }
               l_dcu_fb_width[p_cgb->client_id][fl_fb_index]   = p_cgb->area.width;
               l_dcu_fb_height[p_cgb->client_id][fl_fb_index]  = p_cgb->area.height;
               fl_egl_surface = eglCreatePbufferSurface(dsp, l_dcu_fb_config[p_cgb->client_id], fl_surface_attrib);
            }   
         #if defined(GFX_MGR02_ENABLE_FSL_EXTENTIONS)
            if(fl_egl_surface != EGL_NO_SURFACE)
            {
               EGLPbufferDimFSL dim;
               (void)eglGetPbufferDimFSL(&dim, dsp, fl_egl_surface);
               fl_fb_info_SP->fb_ptr[fl_fb_index] = (void *)(dim.Add);
               p_cgb->area.width  = dim.Width;
               p_cgb->area.height = dim.Height;
               l_context_S.rprop.fb_w = dim.Width;
               l_context_S.rprop.fb_h = dim.Height;
            }
         #endif
         }

         l_dcu_fb_surface[p_cgb->client_id][fl_fb_index] = fl_egl_surface;
         l_dcu_fb_context[p_cgb->client_id]              = fl_egl_context;

         if((fl_egl_surface != EGL_NO_SURFACE) && (fl_egl_context != EGL_NO_CONTEXT))
         {
            /*
            ** All set to perform the update.
            */
         #if defined(GFX_MGR02_ENABLE_FSL_EXTENTIONS)
            l_context_S.rprop.fb_P      = fl_fb_info_SP->fb_ptr[fl_fb_index];
            if(l_context_S.rprop.fb_P != (void *)0)
         #endif
            {
               (void)eglMakeCurrent(dsp, 
                              fl_egl_surface, 
                              fl_egl_surface, 
                              fl_egl_context);
               hmi_gfx_mgr02_context_backfb_slock(fl_fb_info_SP, (u_gx_flocal)TRUE);
               fl_cntx_SP = &l_context_S;
            }
         }
         else
         {
            l_dcu_fb_width[p_cgb->client_id][fl_fb_index]  = (UINT16)0;
            l_dcu_fb_height[p_cgb->client_id][fl_fb_index] = (UINT16)0;
            fl_fb_info_SP->fb_ptr[fl_fb_index]        = (void *)0;
         }
      }
    }
    else
#endif /* #if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0 */
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && !defined(GFX_MGR02_IMXRT)
    if((p_cgb->fb_target == GFX_MGR02_TARGET_AMBER)||(p_cgb->fb_target == GFX_MGR02_TARGET_TRAVEO2))
    {
      GFX_MGR02_FB_INFO_T * fl_fb_info_SP;
      UINT32                fl_fb_index;
      #if defined(GFX_MGR02_TRAVEO2)
      CYGFX_BE_CONTEXT    fl_pe_cntx;
      CYGFX_SURFACE       fl_str_surf;
      CYGFX_SM_FORMAT     fl_gdc_pix_format;
      #else
      MML_GDC_PE_CONTEXT    fl_pe_cntx;
      MML_GDC_SURFACE       fl_str_surf;
      MML_GDC_SURF_FORMAT   fl_gdc_pix_format;
      #endif
      MM_S32                ret;
      IrisMemInfo fl_memory_s;
      #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      l_context_S.rprop.pe_sync = p_cgb->pe_sync;
      #endif
      if(p_cgb->client_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
      {
          #if defined(GFX_MGR02_IMXRT)
          fl_fb_info_SP = &l_imxrt_fb_info_S[p_cgb->client_id];
          #else			  
          fl_fb_info_SP = &l_amber_fb_info_S[p_cgb->client_id];
          #endif
          
          #ifdef GFX_MGR02_AMBER_USE_VRAM_HRAM
          if(p_cgb->use_extram == GFX_MGR02_USE_VRAM_HRAM)
          {
           fl_fb_info_SP->last_id = (GFX_UINT)1;
           fl_fb_info_SP->frnt_id = (GFX_UINT)1;
           fl_fb_info_SP->back_id = (GFX_UINT)0;
           fl_fb_index = (UINT32)0;
          }
          else
          #endif
          {
            
            #if defined(GFX_MGR02_TRAVEO2)
            if(p_cgb->wdg_height>(UINT16)0)
            {
                fl_fb_info_SP->last_id = 0;
                fl_fb_info_SP->frnt_id = 0;
                fl_fb_info_SP->back_id = 0;
                fl_fb_index =0;
            }
            else
            #endif
            {
                fl_fb_index   = hmi_gfx_mgr02_context_find_next_fb(fl_fb_info_SP);  
            }
          }
          if(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)
          {
             fl_pe_cntx  = l_mml_gdc_pixeng_ctx[p_cgb->client_id];
             #if defined(GFX_MGR02_TRAVEO2)
             if(p_cgb->wdg_height>(UINT16)0)
             {
                fl_str_surf = p_cgb->pe_tsurf;
             }
             else
             #endif
             {
               fl_str_surf = l_mml_gdc_store_surf[p_cgb->client_id][fl_fb_index];
             }
             if(fl_pe_cntx == (MML_GDC_PE_CONTEXT)NULL)
             {
                #if defined(GFX_MGR02_TRAVEO2)
                IRIS_API_CHECK(ret,utPeGenContext(&fl_pe_cntx));
                #if !defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)
                if(p_cgb->render_mode == CYGFX_BE_RENDER_MODE_LBO)
                {
                    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_LBO));
                }
                else if(p_cgb->render_mode == CYGFX_BE_RENDER_MODE_MIXED)
                {
                    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_MIXED));
                }
                else
                {
                    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_IBO));
                }
                IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_TASK, p_cgb->priority));
                #endif
                #else
                    IRIS_API_CHECK(ret, mmlGdcPeGenContext(&fl_pe_cntx));
                #endif
                #if ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))))
                if(l_de_path_buffer[p_cgb->client_id]==NULL)
                {
                    fl_memory_s.MemCateg = IRIS_DE_PATH_BUFFER;
                    fl_memory_s.WidgetClientId = 0xFFFFFFFF;
                    fl_memory_s.Alignment = (UINT32)4; /*4 Byte alignement*/
                    fl_memory_s.Size = (UINT32)GFX_MGR02_DE_PATHBUF_SIZE;
                    fl_memory_s.ExtMemory =(UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
                    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
                    #endif
            
                    l_de_path_buffer[p_cgb->client_id]= hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
                  if(l_de_path_buffer[p_cgb->client_id]!=NULL)
                  {
                      IRIS_API_CHECK(ret, mmlGdcDeSetPathBuffer(fl_pe_cntx, l_de_path_buffer[p_cgb->client_id], (MM_U32)GFX_MGR02_DE_PATHBUF_SIZE));
                  }
                }
                #endif
             #if (defined(GFX_MGR02_ENABLE_HW_DITHERING) && !defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED))
                if(l_context_S.rprop.fb_format < (UINT8)GFX_MGR02_PIX_FORMAT_RGB888)
                {
                #ifdef GFX02_DEBUG_INFO
                   printf("GDC_PE_CTX_ATTR_DITHER set for client %d\n", p_cgb->client_id);
                #endif
                   IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_COLOR, (MM_U32)MM_TRUE));
                   IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_ALPHA, (MM_U32)MM_TRUE));
                }
             #endif
             }
             if(fl_pe_cntx != (MML_GDC_PE_CONTEXT)NULL)
             {
                #if defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)
                  if(p_cgb->render_mode == CYGFX_BE_RENDER_MODE_LBO)
                  {
                      IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_LBO));
                  }
                  else if(p_cgb->render_mode == CYGFX_BE_RENDER_MODE_MIXED)
                  {
                      IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_MIXED));
                  }
                  else
                  {
                      IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_RENDER_MODE, CYGFX_BE_RENDER_MODE_IBO));
                  }
                  IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(fl_pe_cntx, CYGFX_BE_CTX_ATTR_TASK, p_cgb->priority)); 
                  #ifdef GFX_MGR02_ENABLE_HW_DITHERING
                      if(l_context_S.rprop.fb_format < (UINT8)GFX_MGR02_PIX_FORMAT_RGB888)
                      {
                      #ifdef GFX02_DEBUG_INFO
                        printf("GDC_PE_CTX_ATTR_DITHER set for client %d\n", p_cgb->client_id);
                      #endif
                        IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_COLOR, (MM_U32)MM_TRUE));
                        IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_ALPHA, (MM_U32)MM_TRUE));
                      }
                      else
                      {
                      #ifdef GFX02_DEBUG_INFO
                        printf("GDC_PE_CTX_ATTR_DITHER set for client %d\n", p_cgb->client_id);
                      #endif
                        IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_COLOR, (MM_U32)MM_FALSE));
                        IRIS_API_CHECK(ret, mmlGdcPeAttribute(fl_pe_cntx, MML_GDC_PE_CTX_ATTR_DITHER_ALPHA, (MM_U32)MM_FALSE));
                      }
                  #endif
                #endif
                UINT32 fl_max_size       =( (UINT32)l_amber_fb_width[p_cgb->client_id][fl_fb_index]*l_amber_fb_height[p_cgb->client_id][fl_fb_index]);

                if((fl_str_surf != (MML_GDC_SURFACE)NULL)&&
                   (fl_fb_info_SP->fb_ptr[fl_fb_index] != NULL)&& 
                   (fl_max_size >= ((UINT32)p_cgb->area.width*p_cgb->area.height)))
                {
                   /*if surface already created and bound size is less than already allocated surface buffer
                     then no need to free memory and allocate again. Use the same buffer 
                    */
                    IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_WIDTH, (MM_U32)p_cgb->area.width));
                    #if defined(GFX_MGR02_TRAVEO2)
                    if(p_cgb->wdg_height>(UINT16)0)
                    {
                        IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_HEIGHT,(MM_U32)p_cgb->wdg_height));
                    }
                    else
                    #endif
                    {
                        IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_HEIGHT,(MM_U32)p_cgb->area.height));
                    }
                }
                else
                {
                    if(fl_fb_info_SP->fb_ptr[fl_fb_index] != NULL)
                    {               
                        #if defined(GFX_MGR02_TRAVEO2) && defined(LBO_OTF_FEATURE_CC)
                        if(p_cgb->wdg_height == (UINT16)0)
                        #endif
                        {
                            hmi_gfx_mgr02_amber_mem_mgmt_free(fl_fb_info_SP->fb_ptr[fl_fb_index]);
                            fl_fb_info_SP->fb_ptr[fl_fb_index] = NULL;
                        }
                    }
                    if(fl_str_surf == (MML_GDC_SURFACE)NULL)
                    {
                       IRIS_API_CHECK(ret, mmlGdcSmGenSurfaceObjects((MM_U32)1, &fl_str_surf));
                    }
                    if(fl_str_surf != (MML_GDC_SURFACE)NULL)
                    {
                        fl_gdc_pix_format = hmi_gfx_mgr02_amber_get_wdg_pix_format((u_gx_flocal)p_cgb->fb_format);
                      
                                
                       #if defined(GFX_MGR02_TRAVEO2)
                        CYGFX_U32 width = (CYGFX_U32)0;
                        CYGFX_U32 height = (CYGFX_U32)0;
                        IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(fl_str_surf,CYGFX_SM_ATTR_WIDTH,&width));
                        IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(fl_str_surf,CYGFX_SM_ATTR_HEIGHT,&height));

                       if(fl_gdc_pix_format == CYGFX_SM_FORMAT_A6R6G6B6)
                       #else
                       if(fl_gdc_pix_format == MML_GDC_SURF_FORMAT_A6R6G6B6)
                       #endif					   
                       {
                            #if defined(GFX_MGR02_TRAVEO2) && defined(LBO_OTF_FEATURE_CC)
                            if(p_cgb->wdg_height>(UINT16)0)
                            {
                                if(((CYGFX_U32)p_cgb->area.width != width)||((CYGFX_U32)p_cgb->wdg_height != height))
                                {
                                    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_str_surf, 
                                                                      (CYGFX_U32)p_cgb->area.width, 
                                                                      (CYGFX_U32)p_cgb->wdg_height, 
                                                                      CYGFX_SM_FORMAT_R8G8B8A8, 
                                                                      NULL, 
                                                                      (MM_U32)0));   
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_str_surf, CYGFX_SM_ATTR_BITPERPIXEL, (CYGFX_U32)0x18));
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_str_surf, CYGFX_SM_ATTR_COLORBITS,  (CYGFX_U32)0x06060606));
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_str_surf, CYGFX_SM_ATTR_COLORSHIFT, (CYGFX_U32)0x120c0600));

                                }
                            }
                            else
                            #endif
                            {
                                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_str_surf, 
                                                                  (MM_U32)p_cgb->area.width, 
                                                                  (MM_U32)p_cgb->area.height, 
                                                                  MML_GDC_SURF_FORMAT_R8G8B8A8, 
                                                                  NULL, 
                                                                  (MM_U32)0)); 
                                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_COLORBITS,  (UINT32)0x06060606));
                                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x120c0600));
                            }

                       }
                       else
                       {
                           #if defined(GFX_MGR02_TRAVEO2)
                            if(p_cgb->wdg_height>(UINT16)0)
                            {
                                if(((CYGFX_U32)p_cgb->area.width != width)||((CYGFX_U32)p_cgb->wdg_height != height))
                                {
                                    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_str_surf, 
                                                                      (CYGFX_U32)p_cgb->area.width, 
                                                                      (CYGFX_U32)p_cgb->wdg_height, 
                                                                      fl_gdc_pix_format, 
                                                                      NULL, 
                                                                      (CYGFX_U32)0));
                                }
                            }
                            else
                            #endif
                            {
                                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_str_surf, 
                                                                  (MM_U32)p_cgb->area.width, 
                                                                  (MM_U32)p_cgb->area.height, 
                                                                  fl_gdc_pix_format, 
                                                                  NULL, 
                                                                  (MM_U32)0));
                            }
                       }
                       l_amber_fb_width[p_cgb->client_id][fl_fb_index]  = p_cgb->area.width;
                        #if defined(GFX_MGR02_TRAVEO2)
                        if(p_cgb->wdg_height>(UINT16)0)
                        {
                            l_amber_fb_height[p_cgb->client_id][fl_fb_index] = p_cgb->wdg_height;
                        }
                        else
                        #endif
                        {
                            l_amber_fb_height[p_cgb->client_id][fl_fb_index] = p_cgb->area.height;
                        }
                       if(fl_fb_index==(UINT32)0)
                       {
                           fl_memory_s.MemCateg = IRIS_WIDGET_FRONT_RENDER_BUFFER;
                       }
                       else
                       {
                           fl_memory_s.MemCateg = IRIS_WIDGET_BACK_RENDER_BUFFER;
                       }
                       fl_memory_s.WidgetClientId = p_cgb->client_id; /*Client Id for merge Widget*/
                       fl_memory_s.Alignment = (UINT32)32;       /*32 Byte alignement*/
                       fl_memory_s.Size = 0U;
                       #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                       fl_memory_s.WidgetFBGroupId = p_cgb->fb_group_id;
                       #endif
                       IRIS_API_CHECK(ret, mmlGdcSmGetAttribute(fl_str_surf, 
                                                                MML_GDC_SURF_ATTR_SIZEINBYTES, 
                                                                (MM_U32*)&fl_memory_s.Size));
                       #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
                       fl_memory_s.ExtMemory = p_cgb->use_extram;
                       #else
                       fl_memory_s.ExtMemory = (UINT8)0; 
                       #endif
                       #ifdef GFX_MGR02_AMBER_USE_VRAM_HRAM
                       /* Allocate memory in both VRAM and HRAM */
                       if(fl_memory_s.ExtMemory == 2)
                       {
                           fl_memory_s.ExtMemory = 0;
                           fl_fb_info_SP->fb_ptr[fl_fb_index] = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
                           #ifdef GFX02_DEBUG_INFO
                           if(fl_fb_info_SP->fb_ptr[fl_fb_index] == 0)
                           {
                              printf("VRAM allocation  Failed\n");
                           }
                           #endif
                           fl_fb_index = 1;
                           if(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)
                           {
                               fl_memory_s.ExtMemory = 1;
                               fl_fb_info_SP->fb_ptr[fl_fb_index] = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
                               #ifdef GFX02_DEBUG_INFO
                               if(fl_fb_info_SP->fb_ptr[fl_fb_index] == 0)
                               {
                                   printf("VRAM allocation  Failed\n");
                               }
                               #endif
                               IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, 
                                                        MML_GDC_SURF_ATTR_BASE_ADDRESS, 
                                                        (MM_U32)fl_fb_info_SP->fb_ptr[fl_fb_index]));
                           }
                           else
                           {
                               #ifdef GFX02_DEBUG_INFO
                                   printf("Error in getting next fb\n");
                               #endif
                           }
                       }
                       else
                       #endif /* GFX_MGR02_AMBER_USE_VRAM_HRAM */
                       {
                           if(fl_fb_info_SP->fb_ptr[fl_fb_index] == NULL)
                           {
                                fl_fb_info_SP->fb_ptr[fl_fb_index] =  hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);

                                #ifdef GFX02_DEBUG_INFO
                                   if(fl_fb_info_SP->fb_ptr[fl_fb_index] == 0)
                                   {
                                      printf("VRAM allocation  Failed\n");
                                   }
                                #endif                                
                           }
                           #if defined(GFX_MGR02_TRAVEO2)
                           {
                               CYGFX_U32 fl_str_addr_u32= (CYGFX_U32)0;
                               IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(fl_str_surf, CYGFX_SM_ATTR_VIRT_ADDRESS, &fl_str_addr_u32));
                               if(fl_str_addr_u32 == (CYGFX_U32)0)
                               {
                                    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_str_surf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)fl_fb_info_SP->fb_ptr[fl_fb_index])); 
                               }
                           }
                           #else
                            IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_str_surf, MML_GDC_SURF_ATTR_BASE_ADDRESS, (MM_U32)fl_fb_info_SP->fb_ptr[fl_fb_index]));                                                               
                           #endif

                       }
                   }
                   
                }
             }

             l_mml_gdc_store_surf[p_cgb->client_id][fl_fb_index] = fl_str_surf;
             l_mml_gdc_pixeng_ctx[p_cgb->client_id]              = fl_pe_cntx;
                
             if((fl_pe_cntx != (MML_GDC_PE_CONTEXT)0) && (fl_str_surf != (MML_GDC_SURFACE)0))
             {
                l_context_S.rprop.pe_ctx   = fl_pe_cntx;
                l_context_S.rprop.pe_tsurf = fl_str_surf;
                p_cgb->pe_tsurf            = fl_str_surf;
                #if defined(GFX_MGR02_TRAVEO2) 
                l_context_S.rprop.wdg_height	= p_cgb->wdg_height;
                l_context_S.rprop.render_mode	= p_cgb->render_mode;
                l_context_S.rprop.priority		= p_cgb->priority;
                #ifdef LBO_OTF_FEATURE_CC
                if(p_cgb->wdg_height>(UINT16)0)
                {
                    hmi_gfx_mgr02_set_otf_wnd_surf(p_cgb);
                }
                #endif
                #endif
                #if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
                l_context_S.rprop.pe_msurf = p_cgb->pe_msurf;
                l_context_S.rprop.mask_mode = p_cgb->mask_mode;
                #endif
                hmi_gfx_mgr02_context_backfb_slock(fl_fb_info_SP, (u_gx_flocal)TRUE);
                fl_cntx_SP = &l_context_S;
             }
             else
             {
                l_amber_fb_width[p_cgb->client_id][fl_fb_index]  = (UINT16)0;
                l_amber_fb_height[p_cgb->client_id][fl_fb_index] = (UINT16)0;
                fl_fb_info_SP->fb_ptr[fl_fb_index]               = NULL;
             }
         }
      }
    }
    else
#endif /* #if GFX_MGR02_NUM_DCU_OVG_WIDGETS > 0 */
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && defined(GFX_MGR02_IMXRT)
    if((p_cgb->fb_target == (GFX_MGR02_TARGET_IMXRT_PXP)) || (p_cgb->fb_target == (GFX_MGR02_TARGET_VGLITE)))
    {
        GFX_MGR02_FB_INFO_T * fl_fb_info_SP;		
        PixEngMemInfo fl_memory_s;
        UINT32 fl_max_size;
        UINT32 fl_fb_index;
        UINT32 fl_bpp;		
        lcdifv2_pixel_format_t fl_pix_format;
        if (p_cgb->client_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
        {
            fl_pix_format =	hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format(p_cgb->fb_format);
            fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
            fl_fb_info_SP = &l_imxrt_fb_info_S[p_cgb->client_id];		
            fl_fb_index   = hmi_gfx_mgr02_context_find_next_fb(fl_fb_info_SP);  
            if(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)
            {
                fl_max_size =( (UINT32)l_imxrt_fb_width[p_cgb->client_id][fl_fb_index]*l_imxrt_fb_height[p_cgb->client_id][fl_fb_index]);
          
                if((fl_fb_info_SP->fb_ptr[fl_fb_index] == NULL) || (fl_max_size < ((UINT32)p_cgb->area.width*p_cgb->area.height)))
                {
                    if(fl_fb_info_SP->fb_ptr[fl_fb_index] != NULL)
                    {               
                        hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_fb_info_SP->fb_ptr[fl_fb_index]);
                        fl_fb_info_SP->fb_ptr[fl_fb_index] = NULL;
                    }
                    l_imxrt_fb_width[p_cgb->client_id][fl_fb_index]  = p_cgb->area.width;
                    l_imxrt_fb_height[p_cgb->client_id][fl_fb_index] = p_cgb->area.height;
                    if(fl_fb_index == (UINT32)0)
                    {
                        fl_memory_s.MemCateg = IMXRT_WIDGET_FRONT_RENDER_BUFFER;
                    }
                    else
                    {
                        fl_memory_s.MemCateg = IMXRT_WIDGET_BACK_RENDER_BUFFER;
                    }   
                    fl_memory_s.WidgetClientId = p_cgb->client_id; 
                    fl_memory_s.Alignment = (UINT32)32; /*32 Byte alignement*/
                    fl_memory_s.Size = (((UINT32)l_imxrt_fb_width[p_cgb->client_id][fl_fb_index]*l_imxrt_fb_height[p_cgb->client_id][fl_fb_index]*fl_bpp)>>3U);
                    fl_memory_s.ExtMemory = (UINT8)1;
                    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                    fl_memory_s.WidgetFBGroupId = p_cgb->fb_group_id;
                    #endif
                    fl_fb_info_SP->fb_ptr[fl_fb_index] = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s); 
                    if(fl_fb_info_SP->fb_ptr[fl_fb_index]  !=NULL)
                    {
                        l_context_S.rprop.fb_P = (void *)fl_fb_info_SP->fb_ptr[fl_fb_index];
                        hmi_gfx_mgr02_context_backfb_slock(fl_fb_info_SP, (u_gx_flocal)TRUE);
                        fl_cntx_SP = &l_context_S;
                    }
                #if (((GFX_MGR02_NUM_OF_SVGS > 0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)) && defined(GFX_MGR02_VGLITE))
                    if ((p_cgb->fb_target == GFX_MGR02_TARGET_VGLITE) && (l_vglite_path_cmd_buf == NULL))
                    {
                        fl_memory_s.MemCateg         = IMXRT_VGLITE_PATH_CMD_BUFFER;
                        fl_memory_s.WidgetClientId   = 0xFFFFFFFFu;
                        fl_memory_s.Alignment        = (UINT32)32;
                        /* GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH is the maximum path buffer size required for rendering all the characters */
                        /* GFX_MGR02_MAX_PATH_CMD_BUF_LENGTH is the maximum path buffer size required for rendering svg images */
                        #if defined (GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)
                        fl_memory_s.Size             = (GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH > GFX_MGR02_MAX_PATH_CMD_BUF_LENGTH) ? ((UINT32)GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH) : ((UINT32)GFX_MGR02_MAX_PATH_CMD_BUF_LENGTH);
                        #else 
                        fl_memory_s.Size             = ((UINT32)GFX_MGR02_MAX_PATH_CMD_BUF_LENGTH); 
                        #endif                    
                        fl_memory_s.ExtMemory        = (UINT8)1;
                        #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                        fl_memory_s.WidgetFBGroupId  = GFX_MGR02_INVALID_FB_GROUP_ID;
                        #endif
                        l_vglite_path_cmd_buf        = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
                    }
                #endif
                #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                    hmi_gfx_mgr02_context_allocate_decompr_buffer();
                #endif                  
                }
                else
                {
                    /* Use the same buffer */
                    l_context_S.rprop.fb_P = (void *)fl_fb_info_SP->fb_ptr[fl_fb_index];
                    hmi_gfx_mgr02_context_backfb_slock(fl_fb_info_SP, (u_gx_flocal)TRUE);
                    fl_cntx_SP = &l_context_S;
                }        			 
            }
        }			
    }
    else
#endif
    {
       fl_cntx_SP = &l_context_S;
    }
  return(fl_cntx_SP);
}
#endif /* #if defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_OPEN_VG)  */
#endif /* #if defined(GFX_MGR02_KEPLER) */

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_begin_update
Description          : Loads the rendering context for the passed layer
                       finds a free back buffer where building can be started
                       If everything is OK returns the context pointer
                       If anything fails returns NULL pointer
Invocation           : Invoked by build screen
Return Value         : Pointer to context
Critical Section     : None
Parameters           : Layer ID and pointer to layer
******************************************************************************/
GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_begin_update(u_gx_flocal                   p_layer_id, 
                                                         GFX_MGR02_LAYER_DEF_T const * p_layer_table_SP,
                                                         u_gx_flocal                   p_lock)
{
   GFX_MGR02_CONTEXT_T * fl_cntx_SP = GFX_MGR02_NULL_PTR;
#if defined(GFX_MGR02_SOFTWARE)||defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_VGLITE)
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP;
   UINT32                fl_fb_index;
#endif
   if(p_layer_id < GFX_MGR02_NUM_LAYERS)
   {
       l_context_S.rprop.layer_id  = (UINT8)p_layer_id;
       l_context_S.rprop.fb_format = p_layer_table_SP->pix_format;
       l_context_S.rprop.fb_target = p_layer_table_SP->target;
       l_context_S.rprop.fb_w      = p_layer_table_SP->area.width;
       l_context_S.rprop.fb_h      = p_layer_table_SP->area.height;
    #if defined(GFX_MGR02_OPEN_GL)
       fl_cntx_SP = &l_context_S;
       GFX_MGR02_UNUSED_VAR(p_lock);
    #elif defined(GFX_MGR02_SOFTWARE)||defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER_IRIS)|| defined(GFX_MGR02_IMXRT_PXP)|| defined(GFX_MGR02_VGLITE)
       fl_fb_info_SP = &l_fb_info_S[p_layer_id];
       fl_fb_index   = hmi_gfx_mgr02_context_find_next_fb(fl_fb_info_SP);

       if(fl_fb_index < (UINT32)GFX_DRIVER_NUM_FB)
       {
          l_context_S.rprop.fb_P = fl_fb_info_SP->fb_ptr[fl_fb_index];
       }
       else
       {
          l_context_S.rprop.fb_P = (void *)0;
       }
       
       #ifdef GFX_MGR02_USE_TIDSS
       (void)hmi_gfx_mgr02_tidss_dispif_dequeue((uint8_t)p_layer_id);
       #endif
       
       if((l_context_S.rprop.fb_P != (void *)0) && (p_layer_table_SP->pix_format < (UINT8)GFX_MGR02_NUM_PIX_FORMATS))
       {
          if(p_layer_table_SP->target == GFX_MGR02_TARGET_OPENVG)
          {
          #if defined(GFX_MGR02_OPEN_VG)   
             if(l_egl_context[p_layer_id] != EGL_NO_CONTEXT)
             {
                /*
                ** Lock the buffer as we are now starting the building
                */
                if(eglMakeCurrent(dsp, 
                                  l_egl_surface[p_layer_id][fl_fb_index], 
                                  l_egl_surface[p_layer_id][fl_fb_index], 
                                  l_egl_context[p_layer_id]) != EGL_FALSE)
                {
                #if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
                   if(fl_fb_info_SP->last_id < GFX_DRIVER_NUM_FB)
                   {
                      if(fl_fb_info_SP->last_id != fl_fb_info_SP->back_id)
                      {
                         GFX_MGR02_IMAGE_DEF_T       fl_image_def_t;
                         fl_image_def_t.format     = p_layer_table_SP->pix_format;
                         fl_image_def_t.pixel_data = fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id];
                         fl_image_def_t.width      = p_layer_table_SP->area.width;
                         fl_image_def_t.height     = p_layer_table_SP->area.height;

                         hmi_gfx_mgr02_ovglib_pre_copy_fb(&l_context_S,&fl_image_def_t);
                         fl_fb_info_SP->last_id = fl_fb_info_SP->back_id;
                      }
                   }
                #endif
                   hmi_gfx_mgr02_context_backfb_slock(&l_fb_info_S[p_layer_id], p_lock);
                   fl_cntx_SP = &l_context_S;
                }
                else
                {
                   GFX_MGR02_LOG_ERROR(GFX_MGR02_EGLMAKECURRENT_FAULT);
                }
             }
          #endif
          }
          else
          {
          #if defined(GFX_MGR02_FUJITSU)
             /*
             ** Lock the buffer as we are now starting the building
             */
            if(p_layer_table_SP->target == GFX_MGR02_TARGET_FUJITSU)
            {
               MM_S32 ret = MML_OK;
               l_context_S.rprop.pe_ctx   = &l_mml_gdc_pixeng_ctx_c[p_layer_id];
               l_context_S.rprop.pe_tsurf = &l_mml_gdc_store_surf_c[p_layer_id][fl_fb_index];
               UTIL_SUCCESS(ret, mmlGdcPeBindSurface(l_context_S.rprop.pe_ctx, 
                                   MML_GDC_PE_STORE|MML_GDC_PE_DST,  
                                   l_context_S.rprop.pe_tsurf));
            }
          #endif
          #if defined(GFX_MGR02_AMBER_IRIS)
             /*
             ** Lock the buffer as we are now starting the building
             */
            if(p_layer_table_SP->target == GFX_MGR02_TARGET_AMBER_IRIS)
            {
               MM_S32 ret = MML_OK;
               l_context_S.rprop.pe_ctx   = l_ambr_irs_mml_gdc_pixeng_ctx[p_layer_id];
               l_context_S.rprop.pe_tsurf = l_ambr_irs_mml_gdc_store_surf[p_layer_id][fl_fb_index];
               IRIS_API_CHECK(ret, mmlGdcPeBindSurface(l_context_S.rprop.pe_ctx, 
                                   MML_GDC_PE_STORE|MML_GDC_PE_DST,  
                                   l_context_S.rprop.pe_tsurf));
            }
          #endif
          #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_FUJITSU) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE)
             hmi_gfx_mgr02_context_backfb_slock(&l_fb_info_S[p_layer_id], p_lock);
          #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
             if(fl_fb_info_SP->last_id < GFX_DRIVER_NUM_FB)
             {
                if(fl_fb_info_SP->last_id != fl_fb_info_SP->back_id)
                {
                   #if defined(GFX_MGR02_MONOTFT)
                   #ifdef WIN32
                   GFX_MGR02_IMAGE_DEF_T       fl_image_def_t;
                   fl_image_def_t.format     = p_layer_table_SP->pix_format;
                   fl_image_def_t.pixel_data = fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id];
                   fl_image_def_t.width      = p_layer_table_SP->area.width;
                   fl_image_def_t.height     = p_layer_table_SP->area.height;

                   hmi_gfx_mgr02_monolib_pre_copy_fb(&l_context_S,&fl_image_def_t);
                   #endif
                   #endif
                   #if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_SOFTWARE)
                    (void)hmi_gfx_mgr02_context_copy_fb(p_layer_id,&l_context_S);
                   #endif
                   fl_fb_info_SP->last_id = fl_fb_info_SP->back_id;
                }
             }
          #endif
             fl_cntx_SP = &l_context_S;
          #endif
          }
       }
    #else	
       GFX_MGR02_UNUSED_VAR(p_lock);
    #endif
	
   }
   return(fl_cntx_SP);
}

#if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_SOFTWARE) ||defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER) || defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_IMXRT)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_end_update
Description          : This function is called by manager after making sure 
                       that the frame buffer locked by the begin_update is 
                       updated by the manager. This function will unlock the
                       framebuffer and set the b_update and ready flag to 
                       indicate that there is a new frame buffer available to 
                       display
Invocation           : Invoked by build screen
Return Value         : None
Critical Section     : None
Parameters           : Layer ID
******************************************************************************/
void hmi_gfx_mgr02_context_end_update(u_gx_flocal p_layer_id, UINT32 p_updated)
{
    if(p_layer_id < GFX_MGR02_NUM_LAYERS)
    {
    #if defined(GFX_MGR02_SOFTWARE) ||defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_IMXRT_PXP)
      GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[p_layer_id];
    #if defined(GFX_MGR02_AMBER_IRIS) || (defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT)) || (defined(GFX_MGR02_SOFTWARE) && !defined(GFX_MGR02_USE_TIDSS))
      void                * fl_fb_P;
    #endif
      if(fl_fb_info_SP->back_id < GFX_DRIVER_NUM_FB)
      {
         if(fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked != (UINT32)0)
         {
            if(p_updated != (UINT32)FALSE)
            {
               if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_OPENVG)
               {
                  #ifdef WIN32
                  #if defined(GFX_MGR02_OPEN_VG)
                    eglCopyVGtoSurface();
                  #endif
                  #endif
                  #ifdef GFX_MGR02_RENESAS_OPENVG_LIB
                    hmi_gfx_mgr02_context_swap_buffers(p_layer_id);
                  #endif
               }
               fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked = (UINT8)0;
               fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_update = (UINT8)1;
               fl_fb_info_SP->ready   = (UINT8)1;
               fl_fb_info_SP->last_id = fl_fb_info_SP->back_id;
            #if defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(__MQXOS__)
               hmi_gfx_mgr02_driver_mqx_dcu_swap_layer();
            #endif
            #if defined(GFX_MGR02_FUJITSU)
               hmi_gfx_mgr02_context_swap_layer(p_layer_id);
               if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_FUJITSU)
               {
                  MM_S32 ret = MML_OK;

                  UTIL_SUCCESS(ret, mmlGdcDispSetSurface(l_mml_gdc_disp_window[p_layer_id], 
                                                         &l_mml_gdc_store_surf_c[p_layer_id][fl_fb_info_SP->frnt_id]));
                  UTIL_SUCCESS(ret, mmlGdcDispCommit(l_mml_gdc_display));
                  #ifdef GFX_MGR02_IRIS_SIG_UNIT_ENABLED
                    hmi_gfx_mgr02_safety_manage_signature_unit();
                  #endif
               }
            #endif
            #if defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER)
               fl_fb_P = hmi_gfx_mgr02_context_swap_layer(p_layer_id);
               if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_AMBER_IRIS)
               {
                  HMI_GFX_MGR02_AMBER_IRIS_RENDER_WINDOW(p_layer_id,fl_fb_P);
               }
            #endif
            #if defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT)
               fl_fb_P = hmi_gfx_mgr02_context_swap_layer(p_layer_id);
               if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_IMXRT_PXP)
               {
                  hmi_gfx_mgr02_imxrt_lcdif_render_window(p_layer_id,fl_fb_P);
                  hmi_gfx_mgr02_imxrt_lcdif_TriggerShadowLoad(p_layer_id);
               }
            #endif     
            #if defined(GFX_MGR02_MONOTFT)
              GFX_MGR02_LCD_UPDATE(fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id]);
            #endif
            #if defined(GFX_MGR02_SOFTWARE)
              #ifdef GFX_MGR02_USE_TIDSS
              (void)hmi_gfx_mgr02_context_swap_layer(p_layer_id);
              (void)hmi_gfx_mgr02_tidss_dispif_update((uint8_t)p_layer_id);
              #else
              fl_fb_P = hmi_gfx_mgr02_context_swap_layer(p_layer_id);
              GFX_MGR02_LCD_UPDATE(fl_fb_P);
              #endif
            #endif 
            }
            else
            {
              fl_fb_info_SP->fb[fl_fb_info_SP->back_id].val = (UINT8)0;
            }
         }
      }
    #else
      GFX_MGR02_UNUSED_VAR(p_updated);
    #endif
    }
}

#if defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT) || defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_FUJITSU)|| defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_back_fb_slock
Description          : Sets or clears the b_locked of the currently selected
                       back buffer.
Invocation           : Invoked by build screen
Return Value         : None
Critical Section     : None
Parameters           : Layer ID and lock status
******************************************************************************/
static void hmi_gfx_mgr02_context_backfb_slock(GFX_MGR02_FB_INFO_T * fl_fb_info_SP, u_gx_flocal p_lock)
{
    if((fl_fb_info_SP !=NULL)&&(fl_fb_info_SP->back_id < (UINT32)GFX_DRIVER_NUM_FB))
    {
        if(p_lock == (u_gx_flocal)0)
        {
          fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked = (UINT8)0;
        }
        else
        {
          fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked = (UINT8)1;
        }
    }
}

#if !defined(GFX_MGR02_AMBER)&&!defined(GFX_MGR02_AMBER_IRIS)&& !defined(GFX_MGR02_TRAVEO2)&& !defined(GFX_MGR02_IMXRT)&& !defined(GFX_MGR02_IMXRT_PXP)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_back_fb_supdate
Description          : Sets or clears the b_update of the currently selected
                       back buffer.
Invocation           : Invoked by build screen
Return Value         : None
Critical Section     : None
Parameters           : Layer ID and update status
******************************************************************************/
void hmi_gfx_mgr02_context_back_fb_supdate(u_gx_flocal p_layer_id, u_gx_flocal p_update)
{
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[p_layer_id];
   if(p_update == (u_gx_flocal)0)
   {
      fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_update = (UINT8)0;
   }
   else
   {
      fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_update = (UINT8)1;
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_pre_copy_fb
Description          : Copies the previously built buffer to the current back 
                       buffer so that a changed region only update can be made.
                       Need to be called after hmi_gfx_mgr02_context_begin_update
                       and after checking if there are graphics updates pending
                       by the graphics manager.
Invocation           : Invoked by build screen
Return Value         : None
Critical Section     : None
Parameters           : Layer ID
******************************************************************************/
void hmi_gfx_mgr02_context_pre_copy_fb(u_gx_flocal p_layer_id)
{
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[p_layer_id];
   GFX_UINT fl_last_id = fl_fb_info_SP->last_id;
   GFX_UINT fl_back_id = fl_fb_info_SP->back_id;

   if(fl_fb_info_SP->last_id < (UINT32)GFX_DRIVER_NUM_FB)
   {
      if(fl_last_id  != fl_back_id)
      {
         /*
         ** TODO : Perform a copy from last framebuffer to current
         ** back buffer.
         */
      }
   }
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_find_next_fb
Description          : Finds the next free framebuffer and returns the pointer.
                       In case no free buffer returns a NULL pointer
Invocation           : Invoked by build screen
Return Value         : None
Critical Section     : None
Parameters           : Layer ID
******************************************************************************/
static UINT32 hmi_gfx_mgr02_context_find_next_fb(GFX_MGR02_FB_INFO_T * fl_fb_info_SP)
{
   u_gx_flocal           fl_temp              = (u_gx_flocal)GFX_DRIVER_NUM_FB;
   UINT32                fl_fb_index          = (UINT32)GFX_DRIVER_NUM_FB;

   while(fl_temp > (u_gx_flocal)0)
   {
      fl_temp--;
      fl_fb_info_SP->back_id++;
      if(fl_fb_info_SP->back_id >= (UINT32)GFX_DRIVER_NUM_FB)
      {
         fl_fb_info_SP->back_id = (UINT8)0;
      }
      if(fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked == (UINT32)0)
      {
         /*
         ** Found the buffer
         */
         fl_temp     = (u_gx_flocal)0;
         fl_fb_index = (UINT32)fl_fb_info_SP->back_id;
      }
   }
   return(fl_fb_index);
}

#if (defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER))||(defined(GFX_MGR02_IMXRT_PXP) && !defined(GFX_MGR02_IMXRT))||defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_SOFTWARE)|| defined(GFX_MGR02_MONOTFT)|| defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_OPEN_GL)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_swap_layer
Description          : Makes the current active 
Invocation           : Invoked by build screen
Return Value         : Pointer to context
Critical Section     : None
Parameters           : Layer ID and pointer to layer
******************************************************************************/
void * hmi_gfx_mgr02_context_swap_layer(u_gx_flocal p_layer_id)
{
    void * fl_fb_ptr = GFX_MGR02_NULL_PTR;
    
    if (p_layer_id < GFX_MGR02_NUM_LAYERS)
    {
        fl_fb_ptr = hmi_gfx_mgr02_context_swap_fb(&l_fb_info_S[p_layer_id]);
    }
    return fl_fb_ptr;
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_swap_fb
Description          : Makes the current active 
Invocation           : Invoked by build screen
Return Value         : Pointer to context
Critical Section     : None
Parameters           : Layer ID and pointer to layer
******************************************************************************/
static void * hmi_gfx_mgr02_context_swap_fb(GFX_MGR02_FB_INFO_T * fl_fb_info_SP)
{
   void                * fl_fb_P       = (void *)0;

   if((fl_fb_info_SP != NULL)&&(fl_fb_info_SP->ready != (UINT32)0))
   {
      /*
      ** TODO : for triple buffering to work we shall look at the last updated
      **        buffer. fl_fb_info_SP->back_id may not be the the one it may be
      **        in lock and update in progress state.
      */
      if((fl_fb_info_SP->back_id < (UINT32)GFX_DRIVER_NUM_FB)&&(fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_update != (UINT32)0))
      {
         fl_fb_info_SP->ready = (UINT8)0;
         if(fl_fb_info_SP->frnt_id < (UINT32)GFX_DRIVER_NUM_FB)
         {
            fl_fb_info_SP->fb[fl_fb_info_SP->frnt_id].val = (UINT8)0;
         }
         fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_locked = (UINT8)1;
         fl_fb_info_SP->fb[fl_fb_info_SP->back_id].sts.b_update = (UINT8)0;
         fl_fb_info_SP->frnt_id = fl_fb_info_SP->back_id;
         if(fl_fb_info_SP->frnt_id < (UINT32)GFX_DRIVER_NUM_FB)
         {
            fl_fb_P = fl_fb_info_SP->fb_ptr[fl_fb_info_SP->frnt_id];
         }
      }
   }
   return(fl_fb_P);

}
#endif /* #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG)|| defined(GFX_MGR02_FUJITSU) */
#endif /* #if defined(GFX_MGR02_SOFTWARE) || defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)|| defined(GFX_MGR02_FUJITSU)*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_reset_state()
Description          : Clears the context state values to default values.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_reset_state(void)
{
   l_context_S.state.loc.x     = 0; 
   l_context_S.state.loc.y     = 0;
   l_context_S.state.alpha     = (GFX_MGR02_ALPHA)255;
   l_context_S.state.invisible = (UINT8)0;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)|| defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined (GFX_MGR02_VGLITE)
   l_context_S.state.matrix[0] = (GFX_FLOAT)1;
   l_context_S.state.matrix[1] = (GFX_FLOAT)0;
   l_context_S.state.matrix[2] = (GFX_FLOAT)0;
   l_context_S.state.matrix[3] = (GFX_FLOAT)0;
   l_context_S.state.matrix[4] = (GFX_FLOAT)1;
   l_context_S.state.matrix[5] = (GFX_FLOAT)0;
   l_context_S.state.matrix[6] = (GFX_FLOAT)0;
   l_context_S.state.matrix[7] = (GFX_FLOAT)0;
   l_context_S.state.matrix[8] = (GFX_FLOAT)1;
#endif
 #if defined(GFX_MGR02_KEPLER)
   if(l_context_S.rprop.fb_target == GFX_MGR02_TARGET_DCU)
   {
      /*
      ** For the DCU case we need not clip the area outside the TFT
      ** viewing area since DCU will take care of the clipping.
      ** If we set clipping here, then it will make the widgets to
      ** not build fully, if part of the widget falls outside TFT area.
      ** set the clip area to a maximum possible area with SINT16
      */
      l_context_S.state.clip.sx = (SINT16)(-32768); /* -32768 */
      l_context_S.state.clip.sy = (SINT16)(-32768); /* -32768 */
      l_context_S.state.clip.ex = (SINT16)0x7FFF; /* +32767 */
      l_context_S.state.clip.ey = (SINT16)0x7FFF; /* +32767 */
   }
   else
 #endif
   {
      l_context_S.state.clip.sx   = 0;
      l_context_S.state.clip.sy   = 0;
      l_context_S.state.clip.ex   = (SINT16)l_context_S.rprop.fb_w;
      l_context_S.state.clip.ey   = (SINT16)l_context_S.rprop.fb_h;
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_ptr()
Description          : Gets the context buffer pointer
Invocation           : Invoked by the library routines.
Return Value         : Context pointer
Parameters           : None
******************************************************************************/
GFX_MGR02_CONTEXT_T * hmi_gfx_mgr02_context_get_ptr(void)
{
   return(&l_context_S);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_state_get()
Description          : copies the context state to the passed buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Pointer to context state buffer
******************************************************************************/
void hmi_gfx_mgr02_context_state_get(GFX_MGR02_CONTEXT_STATE_T * p_context)
{
   if(p_context != GFX_MGR02_NULL_PTR)
   {
      p_context->loc.x     = l_context_S.state.loc.x; 
      p_context->loc.y     = l_context_S.state.loc.y;
      p_context->alpha     = l_context_S.state.alpha;
      p_context->invisible = l_context_S.state.invisible;
   #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
      p_context->matrix[0] = l_context_S.state.matrix[0];
      p_context->matrix[1] = l_context_S.state.matrix[1];
      p_context->matrix[2] = l_context_S.state.matrix[2];
      p_context->matrix[3] = l_context_S.state.matrix[3];
      p_context->matrix[4] = l_context_S.state.matrix[4];
      p_context->matrix[5] = l_context_S.state.matrix[5];
      p_context->matrix[6] = l_context_S.state.matrix[6];
      p_context->matrix[7] = l_context_S.state.matrix[7];
      p_context->matrix[8] = l_context_S.state.matrix[8];
   #endif
      p_context->clip.sx   = l_context_S.state.clip.sx;
      p_context->clip.sy   = l_context_S.state.clip.sy;
      p_context->clip.ex   = l_context_S.state.clip.ex;  
      p_context->clip.ey   = l_context_S.state.clip.ey;  
   }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_state_set()
Description          : Updates the context state to the one passed in buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : Pointer to context state buffer
******************************************************************************/
void hmi_gfx_mgr02_context_state_set(GFX_MGR02_CONTEXT_STATE_T const * p_context)
{
   if(p_context != GFX_MGR02_NULL_PTR)
   {
      l_context_S.state.loc.x     = p_context->loc.x; 
      l_context_S.state.loc.y     = p_context->loc.y;
      l_context_S.state.alpha     = p_context->alpha;
      l_context_S.state.invisible = p_context->invisible;
   #if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)|| defined (GFX_MGR02_VGLITE)
      l_context_S.state.matrix[0] = p_context->matrix[0];
      l_context_S.state.matrix[1] = p_context->matrix[1];
      l_context_S.state.matrix[2] = p_context->matrix[2];
      l_context_S.state.matrix[3] = p_context->matrix[3];
      l_context_S.state.matrix[4] = p_context->matrix[4];
      l_context_S.state.matrix[5] = p_context->matrix[5];
      l_context_S.state.matrix[6] = p_context->matrix[6];
      l_context_S.state.matrix[7] = p_context->matrix[7];
      l_context_S.state.matrix[8] = p_context->matrix[8];
   #endif
      l_context_S.state.clip.sx   = p_context->clip.sx;
      l_context_S.state.clip.sy   = p_context->clip.sy;
      l_context_S.state.clip.ex   = p_context->clip.ex;  
      l_context_S.state.clip.ey   = p_context->clip.ey;  
   }
}
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0) && (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_render_get()
Description          : copies the context render properties to the passed buffer
Invocation           : Invoked by build screen logics.
Return Value         : None
Parameters           : Pointer to context render buffer
******************************************************************************/
void hmi_gfx_mgr02_context_render_get(GFX_MGR02_CONTEXT_RENDER_PROP_T * p_context)
{
   if(p_context != GFX_MGR02_NULL_PTR)
   {
      p_context->alignment           = l_context_S.rprop.alignment;
      p_context->bg_color  		     = l_context_S.rprop.bg_color;
      p_context->clip_mode           = l_context_S.rprop.clip_mode;
      p_context->clut                = l_context_S.rprop.clut;
      p_context->draw_mode           = l_context_S.rprop.draw_mode;
      p_context->fb_format           = l_context_S.rprop.fb_format;
      p_context->fb_h                = l_context_S.rprop.fb_h;
      p_context->fb_P                = l_context_S.rprop.fb_P;
      p_context->fb_target           = l_context_S.rprop.fb_target;
      p_context->fb_w                = l_context_S.rprop.fb_w;
      p_context->fg_color            = l_context_S.rprop.fg_color;
      p_context->font_id             = l_context_S.rprop.font_id;
      p_context->text_width          = l_context_S.rprop.text_width;   

   #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
      p_context->font_size           = l_context_S.rprop.font_size;
   #endif
      p_context->layer_id            = l_context_S.rprop.layer_id;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
      p_context->pivot               = l_context_S.rprop.pivot;
#endif
#if defined(GFX_MGR02_AMBER_IRIS)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
   #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      p_context->pe_sync	         = l_context_S.rprop.pe_sync;
   #endif
      p_context->pe_ctx              = l_context_S.rprop.pe_ctx;
      #if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
      p_context->pe_tsurf            = l_context_S.rprop.pe_tsurf;
      p_context->pe_msurf            = l_context_S.rprop.pe_msurf;  
      #endif
#endif
#if defined(GFX_MGR02_FUJITSU)
      p_context->pe_ctx              = l_context_S.rprop.pe_ctx; 
      p_context->pe_tsurf            = l_context_S.rprop.pe_tsurf;
#endif
      p_context->scroll_offset       = l_context_S.rprop.scroll_offset;
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_render_set()
Description          : Updates the context render properties to the one passed in buffer
Invocation           : Invoked by build screen logics.
Return Value         : None
Parameters           : Pointer to context render buffer
******************************************************************************/
void hmi_gfx_mgr02_context_render_set(GFX_MGR02_CONTEXT_RENDER_PROP_T const * p_context)
{
   if(p_context != GFX_MGR02_NULL_PTR)
   {
      l_context_S.rprop.alignment           = p_context->alignment;
      l_context_S.rprop.bg_color  			= p_context->bg_color;
      l_context_S.rprop.clip_mode           = p_context->clip_mode;
      l_context_S.rprop.clut                = p_context->clut;
      l_context_S.rprop.draw_mode           = p_context->draw_mode;
      l_context_S.rprop.fb_format           = p_context->fb_format;
      l_context_S.rprop.fb_h                = p_context->fb_h;
      l_context_S.rprop.fb_P                = p_context->fb_P;
      l_context_S.rprop.fb_target           = p_context->fb_target;
      l_context_S.rprop.fb_w                = p_context->fb_w;
      l_context_S.rprop.fg_color            = p_context->fg_color;
      l_context_S.rprop.font_id             = p_context->font_id;
      l_context_S.rprop.text_width          = p_context->text_width;   

   #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2))
      l_context_S.rprop.font_size           = p_context->font_size;
   #endif
      l_context_S.rprop.layer_id            = p_context->layer_id;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2) || defined (GFX_MGR02_VGLITE)
      l_context_S.rprop.pivot               = p_context->pivot;
#endif
#if defined(GFX_MGR02_AMBER_IRIS)|| (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
   #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      l_context_S.rprop.pe_sync	            = p_context->pe_sync;
   #endif
      l_context_S.rprop.pe_ctx              = p_context->pe_ctx;
      #if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
      l_context_S.rprop.pe_tsurf            = p_context->pe_tsurf;
      l_context_S.rprop.pe_msurf            = p_context->pe_msurf;  
      #endif
#endif
#if defined(GFX_MGR02_FUJITSU)
      l_context_S.rprop.pe_ctx              = p_context->pe_ctx; 
      l_context_S.rprop.pe_tsurf            = p_context->pe_tsurf;
#endif
      l_context_S.rprop.scroll_offset       = p_context->scroll_offset;
   }
}
#endif
#if defined(GFX_MGR02_SOFTWARE)||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_MONOTFT)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_alloc_fb()
Description          : Allocates the frame buffer based on passed layer info
                       - Determines number of bytes needed for the FB
                       - Reserves the required size in l_fb_total_available_size
                       - Derives the pointer from l_fb_cur_address and returns
Invocation           : Invoked by build screen.
Return Value         : NULL pointer if allocation fails else a valid pointer
                       to frame buffer  
Parameters           : Frame buffer pixel format, width pixels and height pixels
******************************************************************************/
void * hmi_gfx_mgr02_context_alloc_fb(u_gx_flocal p_pix_format, 
                                      u_gx_flocal p_fb_width, 
                                      u_gx_flocal p_fb_height)
{
   u_gx_flocal fl_fb_bytes_for_8pix = (u_gx_flocal)0;
   u_gx_flocal fl_fb_ptr            = (u_gx_flocal)0;
   
   #if (defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE)) || defined(GFX_MGR02_USE_TIDSS) || defined (GFX_MGR02_FUJITSU) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2)
   if(p_pix_format < (u_gx_flocal)GFX_MGR02_NUM_PIX_FORMATS)
   {
      u_gx_flocal fl_fb_width = p_fb_width;
      fl_fb_bytes_for_8pix = lc_fb_bytes_for_8pix[p_pix_format];
      if(fl_fb_bytes_for_8pix >= (u_gx_flocal)8)
      {
         u_gx_flocal fl_fb_bytes_per_pixel;
         fl_fb_bytes_per_pixel  = (u_gx_flocal)(fl_fb_bytes_for_8pix >> 3);
         fl_fb_width            *= fl_fb_bytes_per_pixel;
         fl_fb_width            *= p_fb_height; /* p_fb_width contains total byted needed for fb */
      }
      else
      {
         u_gx_flocal fl_fb_pix_per_byte;
         #if defined(GFX_MGR02_MONOTFT)
         fl_fb_pix_per_byte =  (u_gx_flocal)(((u_gx_flocal)8)/fl_fb_bytes_for_8pix);
         #else
         u_gx_flocal fl_rounding_factor;
         u_gx_flocal fl_fb_bytes_for_8pix_decrement = fl_fb_bytes_for_8pix;
         fl_fb_bytes_for_8pix_decrement--;
         fl_rounding_factor = (u_gx_flocal)(fl_fb_bytes_for_8pix_decrement);
         fl_fb_pix_per_byte = (u_gx_flocal)(((u_gx_flocal)8) >> fl_rounding_factor);
         fl_fb_width        += fl_rounding_factor;
         #endif
         fl_fb_width        /= fl_fb_pix_per_byte;
         fl_fb_width        *= p_fb_height; /* p_fb_width contains total byted needed for fb */
      }
      if(fl_fb_width <= (u_gx_flocal)l_fb_total_available_size)
      {
         l_fb_total_available_size -= fl_fb_width;
         fl_fb_ptr                  = l_fb_cur_address;
      #ifdef GFX_MGR02_SOFTWARE_FB_ALIGN
         fl_fb_ptr = GFX_MGR02_SOFTWARE_FB_ALIGN(fl_fb_ptr);
         if(fl_fb_ptr > (u_gx_flocal)l_fb_cur_address)
         {
            fl_fb_width += (fl_fb_ptr-l_fb_cur_address);
         }
      #endif
         l_fb_cur_address          += fl_fb_width;
      }
   #ifdef GFX02_DEBUG_CONTEXT
      else
      {
         gfx_debug("SWR framebuffer allocation failed, Needed %dbytes, Available %dbytes\n", p_fb_width, l_fb_total_available_size);
      }
   #endif
   }
   #endif /* defined(GFX_MGR02_SOFTWARE_FB_ADDRESS) && defined(GFX_MGR02_SOFTWARE_FB_SIZE) */
   return((void *)fl_fb_ptr);
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_combine_clip()
Description          : Sets the clipping area to the passed area. Passed area
                       is evaluated first. If outside current area then 
                       discarded. If with in or partly with in current area
                       then the passed area is clamped and made as the new
                       clip area.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : clip area values
******************************************************************************/
UINT32 hmi_gfx_mgr02_context_validate_clip(GFX_MGR02_VISIBLE_AREA       * p_cur_clip_SP, 
                                           GFX_MGR02_VISIBLE_AREA const * p_new_clip_SP)
{
   UINT32 fl_invisible = (UINT32)FALSE;

   if( (p_new_clip_SP->ex < p_cur_clip_SP->sx) || (p_new_clip_SP->sx > p_cur_clip_SP->ex) ||
       (p_new_clip_SP->ey < p_cur_clip_SP->sy) || (p_new_clip_SP->sy > p_cur_clip_SP->ey))
   {
      /* 
      ** New clip region is outside current clip region
      ** and therefore invisible
      */
      p_cur_clip_SP->sx = 0;
      p_cur_clip_SP->sy = 0;
      p_cur_clip_SP->ex = 0;
      p_cur_clip_SP->ey = 0;
      fl_invisible      = (UINT32)TRUE;
   }
   else
   {
      /*
      ** Clamp the area within the current clip region
      */
      if(p_new_clip_SP->sx > p_cur_clip_SP->sx)
      {
         p_cur_clip_SP->sx = p_new_clip_SP->sx;
      }
      if(p_new_clip_SP->ex < p_cur_clip_SP->ex)
      {
         p_cur_clip_SP->ex = p_new_clip_SP->ex;
      }
      if(p_new_clip_SP->sy > p_cur_clip_SP->sy)
      {
         p_cur_clip_SP->sy = p_new_clip_SP->sy;
      }
      if(p_new_clip_SP->ey < p_cur_clip_SP->ey)
      {
         p_cur_clip_SP->ey = p_new_clip_SP->ey;
      }
      if((p_cur_clip_SP->sx == 0) &&
         (p_cur_clip_SP->sy == 0) &&
         (p_cur_clip_SP->ex == 0) &&
         (p_cur_clip_SP->ey == 0))
      {
         fl_invisible = (UINT32)TRUE;
      }
   }
   return(fl_invisible);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_combine_clip()
Description          : Sets the clipping area to the passed area. Passed area
                       is evaluated first. If outside current area then 
                       discarded. If with in or partly with in current area
                       then the passed area is clamped and made as the new
                       clip area.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : clip area values
******************************************************************************/
UINT32 hmi_gfx_mgr02_context_combine_clip(GFX_MGR02_VISIBLE_AREA     * p_cur_clip_SP, 
                                          GFX_MGR02_IAREA_DATA const * p_new_clip_SP)
{
   GFX_MGR02_VISIBLE_AREA fl_new_clip;

   fl_new_clip.sx  = (p_new_clip_SP->x + l_context_S.state.loc.x);
   fl_new_clip.sy  = (p_new_clip_SP->y + l_context_S.state.loc.y);
   fl_new_clip.ex  = (SINT16)p_new_clip_SP->width;
   fl_new_clip.ey  = (SINT16)p_new_clip_SP->height;
   fl_new_clip.ex += fl_new_clip.sx;
   fl_new_clip.ey += fl_new_clip.sy;

   return(hmi_gfx_mgr02_context_validate_clip(p_cur_clip_SP, (GFX_MGR02_VISIBLE_AREA const *)&fl_new_clip));
}

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_clip_va()
Description          : Sets the clipping area to the passed area. Passed area
                       is evaluated first. If outside current area then 
                       discarded. If with in or partly with in current area
                       then the passed area is clamped and made as the new
                       clip area.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : clip area values
******************************************************************************/
void hmi_gfx_mgr02_context_set_clip_va(GFX_MGR02_VISIBLE_AREA const * p_clip_SP)
{
   if(hmi_gfx_mgr02_context_validate_clip(&l_context_S.state.clip, p_clip_SP) == FALSE)
   {
      l_context_S.state.invisible &= (UINT8)(~GFX_MGR02_CONTEXT_CLIP_FLAG);
   }
   else
   {
      l_context_S.state.invisible |= (UINT8)(~GFX_MGR02_CONTEXT_CLIP_FLAG);
   }
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_clip()
Description          : Sets the clipping area to the passed area. Passed area
                       is evaluated first. If outside current area then 
                       discarded. If with in or partly with in current area
                       then the passed area is clamped and made as the new
                       clip area.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : clip area values
******************************************************************************/
void hmi_gfx_mgr02_context_set_clip(GFX_MGR02_IAREA_DATA const * p_clip_SP)
{
   if(hmi_gfx_mgr02_context_combine_clip(&l_context_S.state.clip, p_clip_SP) == (UINT32)FALSE)
   {
      l_context_S.state.invisible &= GFX_MGR02_CLR_CONTEXT_CLIP_FLAG;
   }
   else
   {
      l_context_S.state.invisible |= GFX_MGR02_CLR_CONTEXT_CLIP_FLAG;
   }
}
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0) && (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_IMXRT))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_masksurf()
Description          : set the mask surface
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : mask surface
******************************************************************************/
void hmi_gfx_mgr02_context_set_masksurf(MML_GDC_SURFACE const p_pe_msurf)
{
    l_context_S.rprop.pe_msurf  = p_pe_msurf;
}
#endif
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_maskmode()
Description          : Set the mask mode
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : mask mode
******************************************************************************/
void hmi_gfx_mgr02_context_set_maskmode(UINT8 p_mask_mode)
{
    l_context_S.rprop.mask_mode =  p_mask_mode;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_loc()
Description          : Adds the given xy values to the existing xy.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : offset xy values
******************************************************************************/
void hmi_gfx_mgr02_context_set_loc(GFX_MGR02_ILOC_DATA const * p_xy_SP)
{
    l_context_S.state.loc.x = (SINT16)(l_context_S.state.loc.x + p_xy_SP->x); 
    l_context_S.state.loc.y = (SINT16)(l_context_S.state.loc.y + p_xy_SP->y);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_alpha()
Description          : multiplies the passed alpha with current alpha and the 
                       resultant alpha is used.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : alpha values
******************************************************************************/
void hmi_gfx_mgr02_context_set_alpha(u_gx_flocal p_alpha)
{
   l_context_S.state.invisible &= GFX_MGR02_CLR_CONTEXT_ALPHA_FLAG;
   if(p_alpha == (u_gx_flocal)0)
   {
      l_context_S.state.alpha      = (GFX_MGR02_ALPHA)0;
      l_context_S.state.invisible |= (UINT8)GFX_MGR02_CONTEXT_ALPHA_FLAG;
   }
   else if(p_alpha != (u_gx_flocal)255)
   {
      u_gx_flocal fl_alpha = p_alpha;
      fl_alpha  *= l_context_S.state.alpha;
      fl_alpha >>= 8U;
      l_context_S.state.alpha = (GFX_MGR02_ALPHA)(fl_alpha);
      if(l_context_S.state.alpha == (GFX_MGR02_ALPHA)0)
      {
         l_context_S.state.invisible |= (UINT8)GFX_MGR02_CONTEXT_ALPHA_FLAG;
      }
   }
   else
   {
      /*warning fix*/
   }
}

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined (GFX_MGR02_AMBER)||defined (GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined (GFX_MGR02_VGLITE)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_pivot()
Description          : updates the pivot value to the passed pivot value.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : pivot xy values
******************************************************************************/
void hmi_gfx_mgr02_context_set_pivot(GFX_MGR02_FLOC_DATA const * p_pivot)
{
   l_context_S.rprop.pivot.x = p_pivot->x;
   l_context_S.rprop.pivot.y = p_pivot->y;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_mul_matrix()
Description          : multiplies the passed matrix
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : matrix values
******************************************************************************/
void hmi_gfx_mgr02_context_mul_matrix(GFX_FLOAT * p_dest_matrix, GFX_FLOAT const * p_src_matrix)
{
   GFX_FLOAT temp[9];

   if((fabsf(p_src_matrix[0] - (GFX_FLOAT)1) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[1] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[2] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[3] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[4] - (GFX_FLOAT)1) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[5] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[6] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[7] - (GFX_FLOAT)0) > FLT_EPSILON) ||
      (fabsf(p_src_matrix[8] - (GFX_FLOAT)1) > FLT_EPSILON) )
   {
      temp[0] = p_dest_matrix[0];
      temp[1] = p_dest_matrix[1];
      temp[2] = p_dest_matrix[2];
      temp[3] = p_dest_matrix[3];
      temp[4] = p_dest_matrix[4];
      temp[5] = p_dest_matrix[5];
      temp[6] = p_dest_matrix[6];
      temp[7] = p_dest_matrix[7];
      temp[8] = p_dest_matrix[8];

      p_dest_matrix[0]  = (temp[0] * p_src_matrix[0]);
      p_dest_matrix[0] += (temp[3] * p_src_matrix[1]);
      p_dest_matrix[0] += (temp[6] * p_src_matrix[2]);

      p_dest_matrix[1]  = (temp[1] * p_src_matrix[0]);
      p_dest_matrix[1] += (temp[4] * p_src_matrix[1]);
      p_dest_matrix[1] += (temp[7] * p_src_matrix[2]);

      p_dest_matrix[2]  = (temp[2] * p_src_matrix[0]);
      p_dest_matrix[2] += (temp[5] * p_src_matrix[1]);
      p_dest_matrix[2] += (temp[8] * p_src_matrix[2]);

      p_dest_matrix[3]  = (temp[0] * p_src_matrix[3]);
      p_dest_matrix[3] += (temp[3] * p_src_matrix[4]);
      p_dest_matrix[3] += (temp[6] * p_src_matrix[5]);
   
      p_dest_matrix[4]  = (temp[1] * p_src_matrix[3]);
      p_dest_matrix[4] += (temp[4] * p_src_matrix[4]);
      p_dest_matrix[4] += (temp[7] * p_src_matrix[5]);

      p_dest_matrix[5]  = (temp[2] * p_src_matrix[3]);
      p_dest_matrix[5] += (temp[5] * p_src_matrix[4]);
      p_dest_matrix[5] += (temp[8] * p_src_matrix[5]);

      p_dest_matrix[6]  = (temp[0] * p_src_matrix[6]);
      p_dest_matrix[6] += (temp[3] * p_src_matrix[7]);
      p_dest_matrix[6] += (temp[6] * p_src_matrix[8]);

      p_dest_matrix[7]  = (temp[1] * p_src_matrix[6]);
      p_dest_matrix[7] += (temp[4] * p_src_matrix[7]);
      p_dest_matrix[7] += (temp[7] * p_src_matrix[8]);

      p_dest_matrix[8]  = (temp[2] * p_src_matrix[6]);
      p_dest_matrix[8] += (temp[5] * p_src_matrix[7]);
      p_dest_matrix[8] += (temp[8] * p_src_matrix[8]);
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_matrix()
Description          : multiplies the passed matrix with current matrix.
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : matrix values
******************************************************************************/
void hmi_gfx_mgr02_context_set_matrix(GFX_FLOAT const * p_matrix)
{
   hmi_gfx_mgr02_context_mul_matrix(l_context_S.state.matrix, p_matrix);
}
#endif

#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)
#ifdef GFX_MGR02_RENESAS_OPENVG_LIB
#define ROWS 0
static void   hmi_gfx_mgr02_context_swap_buffers(u_gx_flocal p_layer_id)
{
    #if ROWS > 0
    UINT32   count = (480 * ROWS);
    UINT32 * dest;
    UINT32 * src;
    #endif
    GFX_MGR02_ISIZE_W_T fl_layer_width;
    GFX_MGR02_ISIZE_H_T fl_layer_height;

    GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_fb_info_S[p_layer_id];

    /* DO a DMA transfer */
    if(p_layer_id == (u_gx_flocal)LAYER_1)
    {
        current_render_fb_addr_ctx = VDC4.GR2_FLM2.BIT.GR2_BASE;
    }
    else if(p_layer_id == (u_gx_flocal)LAYER_2)
    {
         current_render_fb_addr_ctx = VDC4.GR3_FLM2.BIT.GR3_BASE;
    }
    else
    {
        /*To Fix MISRA warning.*/
    }
    if(current_render_fb_addr_ctx == l_front_buffer_address_ctx[p_layer_id])
    {
        l_source_address_ctx  = l_back_buffer_address_ctx[p_layer_id];
    }
    else
    {
        l_source_address_ctx = l_front_buffer_address_ctx[p_layer_id];
    }
    
    fl_layer_width  = lc_layer_def_S[p_layer_id].area.width;
    fl_layer_height = lc_layer_def_S[p_layer_id].area.height;
    /*Channel 0 used for transfer*/
    DMAC.CHCR0.BIT.DE = 0;
    /*Destination address*/
    DMAC.DAR0.LONG    = current_render_fb_addr_ctx;
    /* source address */
    DMAC.SAR0.LONG    = l_source_address_ctx;
    /* count for transfer no. of times DMA transfer */
    #if ROWS > 0
    DMAC.DMATCR0.LONG = fl_layer_width*(fl_layer_height-ROWS);
    #else
    DMAC.DMATCR0.LONG = fl_layer_width*fl_layer_height;
    #endif
    if(lc_layer_def_S[p_layer_id].pix_format == GFX_MGR02_PIX_FORMAT_ARGB8888)
    {
        /* Transfered in 4 bytes upto count mentioned in DMATCR0 */
        DMAC.CHCR0.LONG   = 0x80005410;
    }
    else
    {
        /* Transfered in 2 bytes upto count mentioned in DMATCR0 */
        DMAC.CHCR0.LONG   = 0x80005408;
    }
    /* Normal mode */
    DMAC.DMAOR.WORD  |= 1;
    DMAC.CHCR0.BIT.DE = 1;

    #if ROWS > 0
    dest = (UINT32 *)(current_render_fb_addr_ctx);
    src  = (UINT32 *)(l_source_address_ctx);
    src  += (fl_layer_width*(fl_layer_height-ROWS));
    dest += (fl_layer_width*(fl_layer_height-ROWS));

    while(count)
    {
       count--;
       *dest =*src;
       dest++;
       src++;
    }
    #endif

    while(DMAC.CHCR0.BIT.TE == 0);
}
#endif /* #ifdef GFX_MGR02_RENESAS_OPENVG_LIB */

#endif /*#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_textprop()
Description          : Updates the text properties to context buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : property values
******************************************************************************/
void hmi_gfx_mgr02_context_set_textprop(u_gx_flocal p_font_id,
                                        u_gx_flocal p_alignment,
                                        u_gx_flocal p_draw_mode,
                                        u_gx_flocal p_clip_mode,
                                        u_gx_flocal p_scroll_offset,
                                        u_gx_flocal p_width
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE))
                                        ,UINT8 p_font_pt_size
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
                                        , UINT8 p_shapping_required
#endif
#endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
                                        ,UINT8 p_max_shrink
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
                                         , UINT32 p_pre_render_index
#endif
                                        )
{
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
    #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
    //Font Height Points to Pixel Calculation
    UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id(p_font_id);
    FT_Face face = NULL;
    if(fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
        face     = l_context_S.rprop.ft2_faceprop[fl_font_id].ft2_face;
    }
    l_context_S.rprop.font_size.point_size = p_font_pt_size;
    if(face != NULL)
    {
        #if defined (GFX_MGR02_USE_FREETYPE2_OS2_TABLE) && defined(GFX_MGR02_VGLITE)
        TT_OS2 * os2 = (TT_OS2 *)FT_Get_Sfnt_Table(face, ft_sfnt_os2);
        if (os2 != (TT_OS2 *)0)
        {
            l_context_S.rprop.font_size.height = (UINT8)(((GFX_FLOAT)p_font_pt_size/(GFX_FLOAT)face->units_per_EM) * (GFX_FLOAT)(os2->usWinAscent + os2->usWinDescent));
        }
        else
        #endif
        {
            l_context_S.rprop.font_size.height = (UINT8)(((GFX_FLOAT)((GFX_FLOAT)p_font_pt_size/(GFX_FLOAT)face->units_per_EM) * (GFX_FLOAT)(face->ascender - face->descender)));    
        }
    }
    #elif ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))
    if(l_context_S.rprop.font_size.point_size != p_font_pt_size)
    {
       FONT_METRICS fm;
       UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id(p_font_id);
       l_context_S.rprop.font_size.point_size = p_font_pt_size;
       (void)FS_set_font((FS_STATE *)l_mt_client_state, (FILECHAR *)l_context_S.rprop.mt_font_name[fl_font_id]);
       (void)FS_set_scale((FS_STATE *)l_mt_client_state, (FS_LONG)(p_font_pt_size*65536), 0, 0, (FS_LONG)(p_font_pt_size*65536));
       (void)FS_font_metrics((FS_STATE *)l_mt_client_state,&fm);
       l_context_S.rprop.font_size.height = (UINT8)(((GFX_FLOAT)((GFX_FLOAT)p_font_pt_size/(GFX_FLOAT)fm.unitsPerEm) * (GFX_FLOAT)(fm.hhea_ascent - fm.hhea_descent))); 
    }
    #endif
#endif
   l_context_S.rprop.alignment     = (GFX_UINT)p_alignment;
   l_context_S.rprop.draw_mode     = (GFX_UINT)p_draw_mode;
   l_context_S.rprop.clip_mode     = (GFX_UINT)p_clip_mode;
   l_context_S.rprop.font_id       = (UINT8)p_font_id;
   l_context_S.rprop.scroll_offset = (UINT16)p_scroll_offset;
   l_context_S.rprop.text_width    = (GFX_MGR02_ISIZE_W_T)p_width;

#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
   l_context_S.rprop.pre_render_index = p_pre_render_index;
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
   l_context_S.rprop.shaping_required = p_shapping_required;
#endif
#endif
#if ((defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
   l_context_S.rprop.max_shrink    = (UINT8)p_max_shrink;
#endif
}

#if (defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)) 
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_text_width()
Description          : Updates the text width property to context buffer
Invocation           : Invoked by build text.
Return Value         : None
Parameters           : text width property
******************************************************************************/    
void hmi_gfx_mgr02_context_set_text_width(GFX_MGR02_ISIZE_W_T p_text_width)
{
    l_context_S.rprop.text_width    = p_text_width;
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_fg_color()
Description          : Updates the fg color property to context buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : property values
******************************************************************************/
void hmi_gfx_mgr02_context_set_fg_color(GFX_MGR02_COLOR p_fg_color)
{
   l_context_S.rprop.fg_color = p_fg_color;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_bg_color()
Description          : Updates the bg color property to context buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : property values
******************************************************************************/
void hmi_gfx_mgr02_context_set_bg_color(GFX_MGR02_COLOR p_bg_color)
{
   l_context_S.rprop.bg_color = p_bg_color;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_clut()
Description          : Updates the clut property to context buffer
Invocation           : Invoked by build screen.
Return Value         : None
Parameters           : property values
******************************************************************************/
void hmi_gfx_mgr02_context_set_clut(u_gx_flocal p_clut)
{
   l_context_S.rprop.clut = (UINT16)p_clut;
}

#if ((defined (GFX_MGR02_AMBER)|| defined(GFX_MGR02_TRAVEO2)) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0) && ((GFX_MGR02_NUM_OF_SVGS >0) || (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0) && defined(GFX_MGR02_TV2_HISTOGRAM_ENABLED)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_free_amber_pathbuffers()
Description          : This function is used to deallocate the path buffer.
Invocation           : Invoked by shutdown function.
Return Value         : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_context_free_amber_pathbuffers(void)
{
  UINT32 fl_index=0UL;
  for(;fl_index<(UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS;fl_index++)
  {
    if(l_de_path_buffer[fl_index]!=NULL)  
    {
      hmi_gfx_mgr02_amber_mem_mgmt_free(l_de_path_buffer[fl_index]);
      l_de_path_buffer[fl_index]=NULL;
    }
  }
}
#endif

#if defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_TRAVEO2)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_copy_fb
Description          : Copies the previously built buffer to the current back 
                       buffer so that a changed region only update can be made.
                       Need to be called after hmi_gfx_mgr02_context_widget_begin_update
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_dcu_gen_widget
Return Value         : None
Critical Section     : None
Parameters           : p_cgb, p_cntx_SP
******************************************************************************/
SINT32 hmi_gfx_mgr02_context_copy_fb(UINT32 p_client_layer_id, GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
   SINT32 ret = (SINT32)0; /*MML_OK;   */
#if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) || defined(GFX_MGR02_AMBER_IRIS)

   MML_GDC_SURFACE_CONTAINER fl_mml_gdc_src_surf_c;
   MML_GDC_SURFACE           fl_mml_gdc_src_surf;  
   MML_GDC_SURFACE_CONTAINER fl_mml_gdc_dst_surf_c;
   MML_GDC_SURFACE           fl_mml_gdc_dst_surf;   
   const GFX_MGR02_FB_INFO_T * fl_fb_info_SP =NULL;
   MML_GDC_SURF_FORMAT   fl_gdc_pix_format;
   MM_U32 fl_ib_cur = 0;
 #if defined(GFX_MGR02_AMBER_IRIS) && defined(GFX_MGR02_AMBER)
   if(p_cntx_SP->rprop.fb_target ==GFX_MGR02_TARGET_AMBER_IRIS)
   { 
        if(p_client_layer_id < (UINT32)GFX_MGR02_NUM_LAYERS)
        {
            fl_fb_info_SP = &l_fb_info_S[p_client_layer_id];
        }
   }
   else
   {
        if(p_client_layer_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
        {		 
            #if defined(GFX_MGR02_IMXRT)	
            fl_fb_info_SP = &l_imxrt_fb_info_S[p_client_layer_id];
            #else
            fl_fb_info_SP = &l_amber_fb_info_S[p_client_layer_id];
            #endif
        }
   }
 #elif defined(GFX_MGR02_AMBER_IRIS) && !defined(GFX_MGR02_AMBER)
    if(p_client_layer_id < (UINT32)GFX_MGR02_NUM_LAYERS)
    {
        fl_fb_info_SP = &l_fb_info_S[p_client_layer_id];
    }
 #else
    if(p_client_layer_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
  #if defined (GFX_MGR02_IMXRT)
    fl_fb_info_SP = &l_imxrt_fb_info_S[p_client_layer_id];
  #else
    fl_fb_info_SP = &l_amber_fb_info_S[p_client_layer_id];
  #endif
    }
#endif  
   if((fl_fb_info_SP !=NULL)&&(fl_fb_info_SP->last_id < GFX_DRIVER_NUM_FB)&&(fl_fb_info_SP->back_id < GFX_DRIVER_NUM_FB)
       &&( fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id] != NULL))
   {
     if(fl_fb_info_SP->last_id != fl_fb_info_SP->back_id)
     {
        fl_gdc_pix_format = hmi_gfx_mgr02_amber_get_wdg_pix_format((u_gx_flocal)p_cntx_SP->rprop.fb_format);
        
        fl_mml_gdc_src_surf = &fl_mml_gdc_src_surf_c;
        IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_src_surf));
        
        fl_mml_gdc_dst_surf = &fl_mml_gdc_dst_surf_c;
        IRIS_API_CHECK(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_dst_surf));
        
        
        #if defined(GFX_MGR02_TRAVEO2)
        if(fl_gdc_pix_format == CYGFX_SM_FORMAT_A6R6G6B6)
        #else
        if(fl_gdc_pix_format == MML_GDC_SURF_FORMAT_A6R6G6B6)
        #endif					   
        {
                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_src_surf, 
                                                     p_cntx_SP->rprop.fb_w, 
                                                     p_cntx_SP->rprop.fb_h, 
                                                     MML_GDC_SURF_FORMAT_R8G8B8A8,
                                                     (void*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id], 
                                                     (UINT32)0));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORBITS,  (UINT32)0x06060606));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x120c0600));												 

                IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_dst_surf, 
                                                     p_cntx_SP->rprop.fb_w, 
                                                     p_cntx_SP->rprop.fb_h, 
                                                     MML_GDC_SURF_FORMAT_R8G8B8A8,
                                                     (void*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id], 
                                                     (UINT32)0));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_dst_surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (UINT32)0x18));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_dst_surf, MML_GDC_SURF_ATTR_COLORBITS,  (UINT32)0x06060606));
                IRIS_API_CHECK(ret, mmlGdcSmSetAttribute(fl_mml_gdc_dst_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (UINT32)0x120c0600));													 
        
        }
        else
        {
            IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_src_surf, 
                                                     p_cntx_SP->rprop.fb_w, 
                                                     p_cntx_SP->rprop.fb_h, 
                                                     (MML_GDC_SURF_FORMAT)fl_gdc_pix_format,
                                                     (void*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id], 
                                                     (UINT32)0));

            IRIS_API_CHECK(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_dst_surf, 
                                                     p_cntx_SP->rprop.fb_w, 
                                                     p_cntx_SP->rprop.fb_h, 
                                                     (MML_GDC_SURF_FORMAT)fl_gdc_pix_format,
                                                     (void*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id], 
                                                     (UINT32)0)); 
        } 
 
        IRIS_API_CHECK(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_mml_gdc_src_surf));
        IRIS_API_CHECK(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_STORE, fl_mml_gdc_dst_surf));
        /* DST should be set to 0 or both DST and SRC surf address should be same,else driver return error in mmlGdcPeBlt*/
        IRIS_API_CHECK(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_DST, NULL));
        IRIS_API_CHECK(ret, mmlGdcPeBlendMode(p_cntx_SP->rprop.pe_ctx,
                                             MML_GDC_PE_BM_GL_FUNC_ADD,
                                             MML_GDC_PE_BM_GL_FUNC_ADD,
                                             MML_GDC_PE_BM_GL_FUNC_ADD,
                                             MML_GDC_PE_BM_GL_FUNC_ADD));
        /* Change blend mode to source */
        IRIS_API_CHECK(ret, mmlGdcPeBlendFunc(p_cntx_SP->rprop.pe_ctx,
                                    MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ZERO,
                                            MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ZERO,
                                            MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ZERO,
                                            MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ZERO));
        
        IRIS_API_CHECK(ret, mmlGdcPeBlt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
        #if defined(GFX_MGR02_TRAVEO2)
        if(p_cntx_SP->rprop.wdg_height==(UINT16)0)
        {
            IRIS_API_CHECK(ret, CyGfx_BeFlush(p_cntx_SP->rprop.pe_ctx));
        }
        IRIS_API_CHECK(ret, CyGfx_BeGetAttribute(p_cntx_SP->rprop.pe_ctx,CYGFX_BE_CTX_ATTR_CURRENT_INSTRUCTION_BUFFER, &fl_ib_cur));
        #else
        IRIS_API_CHECK(ret, mmlGdcConfigGetAttribute(MML_GDC_CONFIG_ATTR_CURRENT_INSTRUCTION_BUFFER, &fl_ib_cur));
        #endif
        if(fl_ib_cur < 4096U)
        {
          #ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
             IRIS_API_CHECK(ret, mmlGdcPeSync(p_cntx_SP->rprop.pe_sync));
             do
             {
                ret = mmlGdcSyncWait(p_cntx_SP->rprop.pe_sync, 0);
             }while(ret == MML_ERR_GDC_SYNC_TIMEOUT);
          #else
            #if defined(GFX_MGR02_TRAVEO2)
            IRIS_API_CHECK(ret, CyGfx_BeFinish(p_cntx_SP->rprop.pe_ctx));
            #else
                (void)mmlGdcPeFinish();
            #endif
          #endif
        }                                           
        IRIS_API_CHECK(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, GFX_MGR02_NULL_PTR));
        /* Restore blend mode to src over */
        IRIS_API_CHECK(ret, mmlGdcPeBlendFunc(p_cntx_SP->rprop.pe_ctx, 
                                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                            MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                            MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                            MML_GDC_PE_BF_GL_ONE,       MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA));

                                                        
       }
   
   }
  

#endif    
   return(ret);
   }
#endif


#if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0)) || defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_SOFTWARE)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_copy_fb
Description          : Copies the previously built buffer to the current back
                       buffer so that a changed region only update can be made.
                       Need to be called after hmi_gfx_mgr02_context_widget_begin_update
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_dcu_gen_widget
Return Value         : None
Critical Section     : None
Parameters           : p_cgb, p_cntx_SP
******************************************************************************/
SINT32 hmi_gfx_mgr02_context_copy_fb(UINT32 p_client_layer_id, GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
    SINT32 ret = (SINT32)0;
    const GFX_MGR02_FB_INFO_T * fl_fb_info_SP = GFX_MGR02_NULL_PTR;
    
#if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0))
    if (p_client_layer_id < GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
        fl_fb_info_SP = &l_imxrt_fb_info_S[p_client_layer_id];
#elif (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_SOFTWARE))
    if (p_client_layer_id < GFX_MGR02_NUM_LAYERS)
    {
        fl_fb_info_SP = &l_fb_info_S[p_client_layer_id];
#endif

        if((fl_fb_info_SP->last_id < GFX_DRIVER_NUM_FB) &&
            (fl_fb_info_SP->back_id < GFX_DRIVER_NUM_FB) &&
            (fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id] != NULL))
        {
            if(fl_fb_info_SP->last_id != fl_fb_info_SP->back_id)
            {
#if defined(GFX_MGR02_VGLITE)
                if (p_cntx_SP->rprop.fb_target == GFX_MGR02_TARGET_VGLITE)
                {
                    ret = hmi_gfx_mgr02_vglite_fb_copy(p_cntx_SP, fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id], fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id]);
                }
                else
#endif           
#if defined(GFX_MGR02_IMXRT_PXP)
                if (p_cntx_SP->rprop.fb_target == GFX_MGR02_TARGET_IMXRT_PXP)
                {
                    UINT32 fl_size;
                    UINT32 fl_bpp_size;
                    pxp_output_pixel_format_t fl_out_fb_format;
                    fl_out_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
                    fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
                    fl_size = (UINT32)p_cntx_SP->rprop.fb_w * (UINT32)p_cntx_SP->rprop.fb_h * (fl_bpp_size/8u);
                    ret = hmi_gfx_mgr02_imxrt_pxp_mem_copy((UINT32*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id],(UINT32*)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id], fl_size);
                }
                else
#endif  
#if defined(GFX_MGR02_SOFTWARE)
                if (p_cntx_SP->rprop.fb_target == GFX_MGR02_TARGET_SOFTWARE)
                {
                    /* Invoke build routine for frame buffer copy for software platform */
                    if (p_cntx_SP->rprop.fb_format < (UINT8)GFX_MGR02_NUM_PIX_FORMATS)
                    {
                        UINT32 fl_fb_bytes_per_pixel = ((UINT32)lc_fb_bytes_for_8pix[p_cntx_SP->rprop.fb_format] >> 3U);
                        UINT32 fl_frame_buffer_size = ((UINT32)p_cntx_SP->rprop.fb_h * ((UINT32)p_cntx_SP->rprop.fb_w * fl_fb_bytes_per_pixel));
                        
                        (void)memcpy(fl_fb_info_SP->fb_ptr[fl_fb_info_SP->back_id], (void const *)fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id], (size_t)fl_frame_buffer_size);
                    }
                }
                else
#endif
                {
                    /* Dummy else to avoid warning */
                }
            }
        }
    }

    return(ret);
}
#endif

#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_is_widget_builded_first
Description          : 
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_dcu_gen_widget
Return Value         : TRUE or FALSE
Critical Section     : None
Parameters           : p_cgb
******************************************************************************/
UINT8 hmi_gfx_mgr02_context_is_widget_builded_first(const GFX_MGR02_CONTEXT_GB_T * p_cgb)
{
   UINT8 fl_first_build= (UINT8)TRUE;
#if (defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT))  && (GFX_MGR02_NUM_OF_SWDGS > 0)
    const GFX_MGR02_FB_INFO_T * fl_fb_info_SP = NULL;
    if(p_cgb->client_id < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {		
        #if defined(GFX_MGR02_IMXRT)		
        fl_fb_info_SP = &l_imxrt_fb_info_S[p_cgb->client_id];  
        #else			
        fl_fb_info_SP = &l_amber_fb_info_S[p_cgb->client_id];  
        #endif
    }
    if((fl_fb_info_SP !=NULL)&&(fl_fb_info_SP->last_id < (GFX_UINT)GFX_DRIVER_NUM_FB)&&(fl_fb_info_SP->back_id < (GFX_UINT)GFX_DRIVER_NUM_FB)
       &&( fl_fb_info_SP->fb_ptr[fl_fb_info_SP->last_id] != NULL))
    {
       fl_first_build= (UINT8)FALSE;
    }
#endif
  return(fl_first_build) ;
}

#endif /* #ifdef GFX_MGR02_DIRTY_REGION_REDRAW */ 

#if defined(GFX_MGR02_AMBER_USE_VRAM_HRAM)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_pixeng_ctx
Description          : Returns the pixel engine context of the widget
Invocation           : Invoked by hmi_gfx_mgr02_render_display
Return Value         : MML_GDC_PE_CONTEXT
Critical Section     : None
Parameters           : Client ID
******************************************************************************/
MML_GDC_PE_CONTEXT hmi_gfx_mgr02_context_get_pixeng_ctx(UINT32 client_id)
{
    MML_GDC_PE_CONTEXT pe_ctx = NULL;
    if(client_id < GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
        pe_ctx = l_mml_gdc_pixeng_ctx[client_id];
    }
    return pe_ctx;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_fb
Description          : Returns the framebuffer address of the widget
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_dcu_gen_widget
Return Value         : Frame buffer address
Critical Section     : None
Parameters           : Client ID and Buffer ID
******************************************************************************/
void * hmi_gfx_mgr02_context_get_fb(GFX_UINT client_id, GFX_UINT buffer_id)
{
    void * fl_fb_P = NULL;
    #if (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
     GFX_MGR02_FB_INFO_T * fl_fb_info_SP;    
    if(client_id < GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
    {
        #if defined(GFX_MGR02_IMXRT)		
        fl_fb_info_SP = &l_imxrt_fb_info_S[client_id];
        #else			
        fl_fb_info_SP = &l_amber_fb_info_S[client_id];
        #endif
        if(buffer_id < GFX_DRIVER_NUM_FB)
        {
            fl_fb_P = fl_fb_info_SP->fb_ptr[buffer_id];
        }
    }
    #endif
    return fl_fb_P;
}
#endif /* GFX_MGR02_AMBER_USE_VRAM_HRAM */
#if (defined (GFX_MGR02_AMBER)|| defined (GFX_MGR02_TRAVEO2)||defined (GFX_MGR02_IMXRT))&& (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_front_fb
Description          : Returns the front frame buffer of the widget
Invocation           : Invoked by layout
Return Value         : Frame buffer address
Critical Section     : None
Parameters           : Client ID
******************************************************************************/
void * hmi_gfx_mgr02_context_get_front_fb(GFX_UINT client_id)
{
  void * fl_fb_P = NULL;
  if(client_id < (GFX_UINT)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS)
  {
    #if defined (GFX_MGR02_IMXRT)	
    const GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[client_id];
    #else		
    const GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_amber_fb_info_S[client_id];
    #endif
    if(fl_fb_info_SP->frnt_id < (GFX_UINT)GFX_DRIVER_NUM_FB)
    {
      fl_fb_P = fl_fb_info_SP->fb_ptr[fl_fb_info_SP->frnt_id];
    }
  }
  return fl_fb_P;
}
#endif /*GFX_MGR02_AMBER && GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0*/

#if defined (GFX_MGR02_SOFTWARE)
void* hmi_gfx_mgr02_context_get_front_fb(u_gx_flocal p_layer_id)
{
    void* fl_fb_P = NULL;
    if(p_layer_id < GFX_MGR02_NUM_LAYERS)
    {
      GFX_MGR02_FB_INFO_T* fl_fb_info_SP = &l_fb_info_S[p_layer_id];
      if (fl_fb_info_SP->frnt_id < (GFX_UINT)GFX_DRIVER_NUM_FB)
      {
         fl_fb_P = fl_fb_info_SP->fb_ptr[fl_fb_info_SP->frnt_id];
      }
    }
    return fl_fb_P;
}
#endif /*GFX_MGR02_AMBER && GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0*/

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_ft2_font_size
Description          : Returns the font size of the freetype font id passed
Invocation           : Invoked by set_text_font_size API
Return Value         : Font size
Critical Section     : None
Parameters           : p_font_id
******************************************************************************/
UINT8 hmi_gfx_mgr02_context_get_ft2_font_size(UINT32 p_font_id)
{
    UINT8 fl_ret_u8=(UINT8)0;
    if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
        fl_ret_u8 = l_context_S.rprop.ft2_faceprop[p_font_id].ft2_font_size;
    }
    return fl_ret_u8;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_set_ft2_font_size
Description          : Sets the font size of the freetype font id passed in context.
Invocation           : Invoked by set_text_font_size API
Return Value         : None
Critical Section     : None
Parameters           : p_font_id, font size
******************************************************************************/
void hmi_gfx_mgr02_context_set_ft2_font_size(UINT32 p_font_id, UINT8 p_fnt_pt_size)
{
    if(p_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
        l_context_S.rprop.ft2_faceprop[p_font_id].ft2_font_size = p_fnt_pt_size;
    }
}

UINT32 hmi_gfx_mgr02_context_get_ft2_face_index(UINT32 p_font_id)
{
  UINT32 fl_index;
#if !defined(GFX_MGR02_TRAVEO2) || defined(GFX_DISABLE_FONT_FACE_OPTIMIZATION)
  fl_index = p_font_id;
#else
  for (fl_index = 0; fl_index < GFX_MGR02_NUM_OF_FONTS; fl_index++)
  {
    if (lc_gfx_font_table[fl_index].f.ffile_name == lc_gfx_font_table[p_font_id].f.ffile_name)
    {
      break;
    }
  }
#endif
  return fl_index;
}
#endif
#if (defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2) ||defined (GFX_MGR02_IMXRT))&& (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
/*============================================================================
 ** Function Name:    hmi_gfx_mgr02_manage_widget_memory
 ** Visibility:       Local
 ** Description:      Interface to free the back buffer of inactive merge widgets.
 **                   
 ** Invocation:       By hmi_gfx_mgr02_amber.c
 ** Inputs/Outputs:   layer_index, None
 ** Critical Section: None
 **==========================================================================*/
void hmi_gfx_mgr02_manage_widget_memory(void)
{
   #if defined (GFX_MGR02_IMXRT)   
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_imxrt_fb_info_S[0];
   #else	   
   GFX_MGR02_FB_INFO_T * fl_fb_info_SP = &l_amber_fb_info_S[0];
   #endif
   GFX_UINT fl_fb_index;
   GFX_UINT fl_front_id;
   UINT32 i;
   for(i=(UINT32)0; i < (UINT32)GFX_MGR02_NUM_AMBER_MERGE_WIDGETS; i++)
   {
      if(fl_fb_info_SP->active == (UINT8)0)
      {
         fl_front_id = fl_fb_info_SP->frnt_id;
         if(fl_front_id < (GFX_UINT)GFX_DRIVER_NUM_FB)
         {
           for(fl_fb_index=(GFX_UINT)0 ;fl_fb_index < (GFX_UINT)GFX_DRIVER_NUM_FB; fl_fb_index++)
           {
             /* Free all memory other than pointing by frnt_id */
             if(fl_fb_index != fl_front_id)
             {             
               if(fl_fb_info_SP->fb_ptr[fl_fb_index] != NULL)
               {
                     #if defined (GFX_MGR02_IMXRT) 					 
                     hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_fb_info_SP->fb_ptr[fl_fb_index]);
                     #else						 
                     hmi_gfx_mgr02_amber_mem_mgmt_free(fl_fb_info_SP->fb_ptr[fl_fb_index]);
                     #endif
                  fl_fb_info_SP->fb_ptr[fl_fb_index] = NULL;
               }
             }
           }
         }
      }
      fl_fb_info_SP++;
   }
   GFX_MGR02_UNUSED_VAR(fl_fb_info_SP);
}
#endif

#if ((GFX_MGR02_NUM_AMBER_MERGE_WIDGETS > 0) && (((GFX_MGR02_NUM_OF_SVGS > 0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)) && defined(GFX_MGR02_VGLITE)))
void* hmi_gfx_mgr02_context_get_path_cmd_buf(void)
{
    return l_vglite_path_cmd_buf;
}
#endif

#if defined(GFX_MGR02_COMPRESSION_ENABLED) && (defined(GFX_MGR02_IMXRT_PXP) || defined(GFX_MGR02_VGLITE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_sw_decompr_buffer
Description          : returns decompression buffer pointer
Invocation           : platfirm specific image build routine
Return Value         : decompr buffer ptr
Critical Section     : none
Parameters           : None
******************************************************************************/
void * hmi_gfx_mgr02_context_get_sw_decompr_buffer(void)
{
    return l_decompr_buffer;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_allocate_decompr_buffer
Description          : allocates decompression buffer 
Invocation           : context during layer init or widget init
Return Value         : none
Critical Section     : none
Parameters           : None
******************************************************************************/
static void hmi_gfx_mgr02_context_allocate_decompr_buffer(void)
{
    if (l_decompr_buffer == NULL)
    {
        PixEngMemInfo fl_memory_s;
        
        fl_memory_s.MemCateg         = IMXRT_SWRLE_DECOMPR_BUFFER;
        fl_memory_s.WidgetClientId   = 0xFFFFFFFFUL;
        fl_memory_s.Alignment        = (UINT32)32;
        fl_memory_s.ExtMemory        = (UINT8)1;
        /* maximum size required to hold largest decompressed image data (in bytes) */
        fl_memory_s.Size             = GFX_MGR02_DECOMPR_BUF_SIZE;
        #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
        fl_memory_s.WidgetFBGroupId  = GFX_MGR02_INVALID_FB_GROUP_ID;
        #endif
        
        l_decompr_buffer             = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_free_decompr_buffer
Description          : Deallocates decompression buffer 
Invocation           : context shutdown 
Return Value         : none
Critical Section     : none
Parameters           : None
******************************************************************************/
static void hmi_gfx_mgr02_context_free_decompr_buffer(void)
{
    if (l_decompr_buffer != NULL)
    {
        hmi_gfx_mgr02_imxrt_mem_mgmt_free(l_decompr_buffer);
    } 
}
#endif

#if (defined(GFX_MGR02_SOFTWARE) && defined(GFX_MGR02_USE_TIDSS))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_context_get_fb_addr
Description          : returns requested frame buffer pointer
Invocation           : while DSS driver init routine
Return Value         : frame buffer ptr
Critical Section     : none
Parameters           : frame_id
******************************************************************************/
void * hmi_gfx_mgr02_context_get_fb_addr(UINT32 p_frame_index)
{
    if(p_frame_index < GFX_DRIVER_NUM_FB)
    {
        return (void *)&l_frame_buffer[p_frame_index][0];
    }
    return GFX_MGR02_NULL_PTR;
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
 **============================================================================
 ** CMS Rev 1.67      04-Apr-2018     ADEVI
 ** 1079104: Monotype client handler implementation.
**
 ** CMS Rev 1.66      21-Mar-2018    KKUBENDI
 ** 1080939: Code: Free the back buffer of a merge widget in start rendering of next frame   
 ** Introduced function hmi_gfx_mgr02_manage_widget_memory
 **
 ** CMS Rev 1.65      14-Mar-2018     ADEVI
 ** 1054545: Freetype cache implementation.
 **
 ** CMS Rev 1.64      10-Jan-2018     ADEVI
 ** 1031255: B515 - Multi layer support for programs using open VG platform.
 **
 ** CMS Rev 1.63      19-Dec-2017     SBOLLAM
 ** Added Harfbuzz and WorldType shape engine support.
 ** Ref Task : 978896
 **
 ** CMS Rev 1.62      23-Nov-2017    ARAJASE2
 ** 994906: P552 L1, L2 - OpenVG rendering texts are not displayed (Core Migration).
 ** Usage of GFX_MGR02_VG_CACHE_ENABLED macro is replaced with new macros
 ** GFX_MGR02_VG_IMG_CACHE_ENABLED and GFX_MGR02_VG_TXT_CACHE_ENABLED
 **
 ** CMS Rev 1.61      08-Nov-2017    KKUBENDI
 ** 968307, 968274, 968289 : PR Defect Fixes
 **
 ** CMS Rev 1.60      16-Oct-2017    ADEVI
 ** 968995: GM-CHUD: Amber: GDT - Text Misplaced Downwards issue resolved.
 ** 
 ** CMS Rev 1.59      19-Sep-2017    KKUBENDI
 ** 939889: Mazda J59: Kepler2- Graphics building in HRAM and transfer to VRAM to display
 ** 
 ** CMS Rev 1.58     18-Sep-2017    ARAJASE2
 ** 921462: Dynamic Font update issue in Amber platform with External font
 ** hmi_gfx_mgr02_context_set_textprop function is changed to accept font_size parameter
 **
 ** CMS Rev 1.57      7-Sep-2017    CSAKTHIV
 ** 944993: Dirty Area Enabling lead to deallocation of memory
 ** 
 ** CMS Rev 1.56      1-Sep-2017    CSAKTHIV
 ** 944993: Dirty Area Enabling lead to deallocation of memory
 **
 ** CMS Rev 1.55      1-Sep-2017    SSIGAMAN
 ** 912798: Different FrameBuffer configuration support in GDT required
 ** ARGB6666 and YUV422 widget rendering formats added.
 **
 ** CMS Rev 1.54     21-Aug-2017    CSAKTHIV
 ** PR Defect fix 942671
 ** PR Defect Fix.
 **
 ** CMS Rev 1.53     21-Aug-2017    CSAKTHIV
 ** RTC 942633,942627:
 ** PR Defect Fix.
 **
 ** CMS Rev 1.52     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.51     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 1.50      16-Aug-2017    SSIGAMAN
 ** 908966: Static allocation of VRAM required.
 ** Modified the files inorder to support user to allocate the required memories
 ** widget rendering and memory required for Draw engine and widget warping.
 **
 ** CMS Rev 1.49     04/08/17    ADEVI
 ** 924879 : Monotype Font Integration in Kepler I.
 **
 ** CMS Rev 1.48     29/06/17    SSRINI19
 ** 880883 : GM-CHUD QAC MISRA additional warning fixes
 **
 ** CMS Rev 1.48     06-JUL-2017    ADEVI
 ** RTC ID: 871825:  Changes to support MONOTFT Platform
 **
 ** CMS Rev 1.47     07/02/2016    SBOLLAM
 ** RTC ID: 750237:  Updated error logging capability and added
 **                  OVG software recovery capability
 **
 ** CMS Rev 1.46      16-DEC-2016    EMANOJ1
 ** Faraday Future - Touch object auto selection does not work (RTC : 767349)
 ** hmi_gfx_mgr02_context_begin_update() function was finding and locking the next
 ** available framebuffer. But when the dirty area initial processing is done, it was
 ** resulting in unnecessarily locking the framebuffer, causing the updates to be not
 ** happening. So a parameter is added to begin update to specify whether a lock is needed
 ** or not. 
 **
 ** CMS Rev 1.45     15-Dec-2016    SSIGAMAN
 ** 766753: BAIC:Provide option to allocate memory for frame buffer in HRAM
 ** The API mmlGdcVideoAlloc() replaced with hmi_gfx_mgr02_amber_mem_mgmt_malloc().
 ** 
 ** CMS Rev 1.44     21-Nov-2016    SSIGAMAN
 ** RTC 747872: Display Flickering in BAIC 
 ** Previous Frame buffer copy is not happening due to the typo error in initial value of ret
 ** in hmi_gfx_mgr02_context_copy_fb(); it is corrected now. 
 ** 
 ** CMS Rev 1.43     02-NOV-2016    APERUMAL
 ** 735553: Porsche Misra warning fixes 
 **
 ** CMS Rev 1.42     18-July-2016    SSIGAMAN
 ** RTC 639228: 
 ** PR Comments Fix. The alpha and path buffer variables are used within the 
 ** GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0 conditional check.
 **
 ** CMS Rev 1.41     14-JULY-2016    CSAKTHIV
 ** 643863: Monotype shutdown not done in context shutdown
 **
 ** CMS Rev 1.40     13-JULY-2016    SSIGAMAN
 ** 635164: GDT: There is no release of the FT2 lib on hmi_gfx_mgr02_context_shutdown
 ** FT_Done_FreeType() API is called in the context shutdown funtion as per Deian's 
 ** recommendation.
 **
 ** CMS Rev 1.39     5-May-2016    SSIGAMAN
 ** RTC 628373: Freetype text rendering: 1st character is missing in the 
 **             1st rendering string of the context if morethan 1 pixel engine context used.
 ** Changes are done in such a manner that the pixel engine context to have their own path buffers.
 **
 ** CMS Rev 1.38     08-JULY-2016    SSIGAMAN
 ** 639042: Porsche Misra warning Fix
 **
 ** CMS Rev 1.37      28-Apr-2016    ADEVI
 ** 543906: Support for dynamic change of the text box size
 **
 ** CMS Rev 1.36     04-April-2016    SSIGAMAN
 ** 560174: Amber Freetype:First letter of the text is not get displayed for the second iteration
 ** Path buffer setting is moved from hmi_gfx_mgr02_amber_iris.c to this module to avoid
 ** setting the path buffer for a pixel engine context multiple times which caused the issue 
 ** in drawing the character.
 ** 
 ** CMS Rev 1.35      29-Mar-2016    SVIKRAM
 ** 521269: Compiler warnings fix
 **
 ** CMS Rev 1.34     28-Mar-2016    SSIGAMAN
 ** 551894 & 551898
 ** Instruction buffer overflow check included in the frame buffer copy.
 ** Also the (frnt_id != back_id) check is modified as (last_id != back_id) as per recommendation.
 **
 ** CMS Rev 1.33     24-Mar-2016    SSIGAMAN
 ** 554958: Amber:Support for freetype text cache 
 ** Cache Support added for freetype in order to improve the rendering performance.
 **
 ** CMS Rev 1.32     17-Mar-2016    SSIGAMAN
 ** 549069:
 ** Blend mode is changed to source while copying frame buffer. 
 ** It is restored to SRC OVER after the copy. 
 **
 ** CMS Rev 1.31     19-Feb-2016    SSIGAMAN
 ** RTC 527247:
 ** When morethan one buffer configured for the merge widget means, on the second/consecutive instant
 ** There are chances that the pixel engine context is valid and width/heigh same but the frame buffer
 ** will not get allocated. To avoid this frame buffer is check aginst NULL.
 **
 ** CMS Rev 1.30     29-Jan-2015    APERUMAL
 ** RTC 507885:
 ** QAC warnings fix for Honda Thaa
 **
 ** CMS Rev 1.29     28-Dec-2015    CSAKTHIV
 ** RTC 490199:
 ** Monotype integration.
 ** CMS Rev 1.28     3-Nov-2015    SSIGAMAN
 ** RTC 456457:
 ** Added hmi_gfx_mgr02_context_copy_fb() function to copy the front buffer to back buffer
 ** when GFX_MGR02_DIRTY_REGION_REDRAW macro is enabled.So that the dirty portion will be redrawn
 ** on top of old content. 
 **
 ** CMS Rev 1.27     02-Nov-2015   SSIGAMAN
 ** Ref RTC# 437002.
 ** Updated the frame buffer formats for A8, A4, A2, A1 as per the
 ** review recommendation for Amber platform.
 **
 ** CMS Rev 1.26      15-Sep-2015    SSIGAMAN  
 ** Improvement activity. Generic module function's called only if merge widget is available.
 **
 ** CMS Rev 1.25      27-August-2015    APERUMAL  
 ** Fixed compiler warning for Honda Thaa
 **
 ** CMS Rev 1.24      05-August-2015    VTODOROV
 ** Fixed a memory leak issue
 **
 ** CMS Rev 1.23    4-Aug-2015    ARAJASE2
 ** Angle brackets is replaced with double quotes in #include to fix QAC error
 **
 ** CMS Rev 1.22     6-July-2015    CSAKTHIV           RTC 371597
 ** Compiler warning and coverity fix.
 ** 
 ** CMS Rev 1.21     9-June-2015    CSAKTHIV           RTC 311173
 ** Support to use 3layers in Renesas OpenVG MFD.
 ** 
 ** CMS Rev 1.20     26-May-2015    ADEVI           RTC 346671
 ** Removed peSync from hmi_gfx_mgr02_context_end_update function since its 
 ** implemented in irislib.c.
 ** 
 ** CMS Rev 1.19     06-May-2015    CSAKTHIV
 ** Signature Unit changes
 **
 ** CMS Rev 1.19     30-Mar-2015    CSAKTHIV
 ** coverity fix 10159 High. RTC 312732
 **
 ** CMS Rev 1.18     10-Feb-2015  SSIGAMAN
 ** Added the Shutdown sequence for the Spansion Amber platform.
 **
 ** CMS Rev 1.17     5-Feb-2015    ADEVI
 ** Changes done to avoid compilation error.
 **
 ** CMS Rev 1.16      20-Jan-2015    EMANOJ1
 ** Implemented surface and context handling for FUJITSU platform and also 
 ** implemented the shutdown sequence for the titan (RTC #256452)
 **
 ** CMS Rev 1.15     10-Nov-2014    EMANOJ1
 ** Spansion Iris engine Amber-I changes for Kepler2.
 **
 ** CMS Rev 1.14     30-Aug-2014    SSIGAMAN
 ** Spansion Iris engine Amber-I changes for Kepler2.
 **
 ** CMS Rev 1.13     25-Nov-2013    CMUTHUSA
 ** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
 **
 ** CMS Rev 1.12     17-Mar-2014    EMANOJ1
 ** RTC : Defect 133048
 ** hmi_gfx_mgr02_context_initialize updated to fix character size issue observed
 ** with freetype (characters were appearing bigger than they appear in GDT). The
 ** issue was that the character size selection was applied to the font height from
 ** baseline and the decender was not included. So when we target for a specific
 ** pixel size the over all size after considering decender was more. Where as in
 ** GDT the height was including acsender + decender
 ** 
 ** CMS Rev 1.11     03-Apr-2014    EMANOJ1
 ** RTC : Defect 123898
 ** Openvg DCU layer freezed because both framebuffers are getting locked. This
 ** happended when hmi_gfx_mgr02_context_widget_end_update() didn't released the
 ** backbuffer for case where there was not updates done to the buffer by build
 ** routine. In sch case the backbuffer was left as locked condition leaving 
 ** both front and back buffer loackedup leading to a freeze condition. To fix
 ** the back buffer is released in detecting that there is no updates the buffer
 **
 ** CMS Rev 1.10     06-Aug-2013    EMANOJ1
 ** hmi_gfx_mgr02_context_widget_end_update() updated to make the eglMakeCurrent
 ** call with NULL context and surface to release the current context. Passing
 ** a context value with NULL surface is an invalid invocation procedure. But
 ** TODO : this implementation has to be checked with Faraday vg library.
 **
 ** CMS Rev 1.9      29-Jun-2013    EMANOJ1
 ** Ver 1.6 changes reverted since the release all doesn't seem to work as expected
 ** during a wake up init or during warm reset init.
 **
 ** CMS Rev 1.8      28-Jun-2013    EMANOJ1
 ** GFX_MGR02_VG_CACHE is not binded by the context. For this the 
 ** 0 to GFX_MGR02_NUM_LAYERS are used as ID for the layers
 ** GFX_MGR02_NUM_LAYERS onwards is used as ID for OVG widgets in DCU target
 ** This unique identifier is used to tag an object created by GFX_MGR02_VG_CACHE
 **
 ** CMS Rev 1.7      27-Jun-2013    EMANOJ1
 ** eglChooseConfig for faraday is updated. In faraday egl driver it returns a 
 ** number of matching configs when we invoke the eglChooseConfig. So code updated
 ** to first qurey the matching configurations and then to search and find the
 ** correct config that we need. This was done to make the RGB565 buffer option
 ** working in faraday.
 ** Memory leak issue noted on repeated egl context distroy fixed temporarily
 ** by removing the distroy from hmi_gfx_mgr02_context_widget_done() - TODO
 ** need to investigate on the best sequence for this later.
 ** Also need to investigate if the GFX_MGR02_VG_CACHE needs a binding with
 ** context or not.
 **
 ** CMS Rev 1.6      21-Jun-2013    EMANOJ1
 ** Added hmi_gfx_mgr02_context_shutdown function to relase all resources used
 ** by context.
 **
 ** CMS Rev 1.5      19-Jun-2013    EMANOJ1
 ** hmi_gfx_mgr02_context_reset_state updated to set the clip area to a 
 ** maximum possible area in the case of DCU as the clipping need not be done
 ** to TFT view area limit and that will be handled by DCU hardware itself.
 **
 ** CMS Rev 1.4      20-May-2013    EMANOJ1
 ** hmi_gfx_mgr02_context_begin_update updated to fix issue with eglMakeCurrent
 ** invocation. EGL context was passed wrongly earlier, which is fixed now.
 **
 ** CMS Rev 1.3      15-May-2013    EMANOJ1
 ** hmi_gfx_mgr02_context_validate_clip renamed as hmi_gfx_mgr02_context_combine_clip
 ** because it was doing a combing and validation operation .
 ** Added hmi_gfx_mgr02_context_set_clip_va to accept clip area as 
 ** GFX_MGR02_VISIBLE_AREA type.
 ** Added a paremeter to hmi_gfx_mgr02_context_end_update to specify whether any
 ** update is made to the framebuffer to decide whether to swap the buffer or not
 **
 ** CMS Rev 1.2      20-Mar-2013    EMANOJ1
 ** Added interface to expose matrix multiplication function to other modules
 **
 ** CMS Rev 1.1      15-Mar-2013    EMANOJ1/ASHEKHAR
 ** Updated compiler switches to make it work for different combinations
 ** Added the layer_id element in context for openVG to load appropriate default
 ** matrix from application function.
 ** Updated hmi_gfx_mgr02_context_combine_clip() to add the current XY location
 ** to allow clip location also getting moved with XY movement of the parent 
 ** element. For example if the clip is set to (x,y,w,h) for a widget A, and if the 
 ** widget getting moved by (10, 5) pixels, this change will make the clip area to
 ** (x+10,y+5,w,h) there by clip area also getting moved by (10, 5) pixels
 **
 ** CMS Rev 1.0      09-Aug-2012    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
