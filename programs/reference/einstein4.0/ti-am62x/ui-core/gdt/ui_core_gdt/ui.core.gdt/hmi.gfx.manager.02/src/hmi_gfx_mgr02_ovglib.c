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
** Name:           hmi_gfx_mgr02_ovglib.c
**
** Description:    OpenVG library interface routines to perform drawing 
**                 operations for graphics manager 02.
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#define GUI_GFX_MANAGER_OVGLIB_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_OPEN_VG)
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_dirty_area.h"
#include "hmi_gfx_mgr02_ovglib.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_text.h"
#if defined(GFX_MGR02_USE_FILESYSTEM)
#include <stdio.h>
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
#include "hmi_gfx_mgr02_ovg_table.dat"
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
#include "hmi_gfx_mgr02_cache.h"
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
#include "fs_itype.h"
#endif
#endif
#if defined(GFX_MGR02_VG_CACHE_ENABLED)
#error "GFX_MGR02_VG_CACHE_ENABLED is obsolete now. Use GFX_MGR02_VG_IMG_CACHE_ENABLED for image and GFX_MGR02_VG_TXT_CACHE_ENABLED for text caching."
#endif
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) && defined(FSL_CONST_IMAGES)
#error "GFX_MGR02_VG_IMG_CACHE_ENABLED should be defined to use FSL_CONST_IMAGES "
#endif
#ifdef GFX_MGR02_THEME_ENABLED
#include "hmi_gfx_mgr02_theme.h"
#endif
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER)
#if defined(GFX_MGR02_COMPRESSION_ENABLED)  
#include "rle_if.h"
#endif
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#define GFX_MGR02_ARABIC_VOWEL_START        (0x64BU)
#define GFX_MGR02_ARABIC_VOWEL_END          (0x658U)
#define GFX_MGR02_IS_ARABIC_VOWEL(char_unicode)    ((((char_unicode) >= GFX_MGR02_ARABIC_VOWEL_START) && ((char_unicode) <= GFX_MGR02_ARABIC_VOWEL_END)) ? 1U:0U)
#endif
#endif
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define GM2_GCFR(argb) (((VGfloat)(((argb) >> 16) & 0xFF))/255.0f)
#define GM2_GCFG(argb) (((VGfloat)(((argb) >>  8) & 0xFF))/255.0f)
#define GM2_GCFB(argb) (((VGfloat)(((argb) ) & 0xFF))/255.0f)    
#define GM2_GCFA(argb) (((VGfloat)(((argb) >> 24)))/255.0f)

#define GFX_MGR02_OVGLIB_FLUSH_PENDING  (0x01)
#define GFX_MGR02_OVGLIB_FB_UPDATED     (0x02)

#ifdef GFX_MGR02_VG_RENDER_QUALITY                                    
#if GFX_MGR02_VG_RENDER_QUALITY == 1
#define GFX_MGR02_VG_RENDER_QUALITY_CONFIG   VG_RENDERING_QUALITY_FASTER
#define GFX_MGR02_VG_IMAGE_QUALITY_CONFIG    VG_IMAGE_QUALITY_FASTER
#define GFX_MGR02_VG_SURFACE_QUALITY_CONFIG  VG_IMAGE_QUALITY_FASTER
#elif GFX_MGR02_VG_RENDER_QUALITY == 2
#define GFX_MGR02_VG_RENDER_QUALITY_CONFIG   VG_RENDERING_QUALITY_BETTER
#define GFX_MGR02_VG_IMAGE_QUALITY_CONFIG    VG_IMAGE_QUALITY_BETTER
#define GFX_MGR02_VG_SURFACE_QUALITY_CONFIG  VG_IMAGE_QUALITY_BETTER
/* Added for vybrid(b515), where display is good if image and surface config is different */
#elif GFX_MGR02_VG_RENDER_QUALITY == 3
#define GFX_MGR02_VG_RENDER_QUALITY_CONFIG   VG_RENDERING_QUALITY_BETTER
#define GFX_MGR02_VG_IMAGE_QUALITY_CONFIG    VG_IMAGE_QUALITY_FASTER
#define GFX_MGR02_VG_SURFACE_QUALITY_CONFIG  VG_IMAGE_QUALITY_BETTER
#else
#ifndef GFX_MGR02_VG_RENDER_QUALITY_CONFIG
#define GFX_MGR02_VG_RENDER_QUALITY_CONFIG   VG_RENDERING_QUALITY_NONANTIALIASED
#endif
#ifndef GFX_MGR02_VG_IMAGE_QUALITY_CONFIG
#define GFX_MGR02_VG_IMAGE_QUALITY_CONFIG    VG_IMAGE_QUALITY_NONANTIALIASED
#endif
#ifndef GFX_MGR02_VG_SURFACE_QUALITY_CONFIG
#define GFX_MGR02_VG_SURFACE_QUALITY_CONFIG  VG_IMAGE_QUALITY_NONANTIALIASED
#endif
#endif
#else
#define GFX_MGR02_VG_RENDER_QUALITY_CONFIG   VG_RENDERING_QUALITY_BETTER
#define GFX_MGR02_VG_IMAGE_QUALITY_CONFIG    VG_IMAGE_QUALITY_BETTER
#define GFX_MGR02_VG_SURFACE_QUALITY_CONFIG  VG_IMAGE_QUALITY_BETTER
#endif

#define FONTS_NONE   0
#define FONTS_BITMAP 1
#define FONTS_SVG    2

#define GFX_MGR02_OVGLIB_NB_CLIENTS (GFX_MGR02_NUM_LAYERS+GFX_MGR02_NUM_DCU_OVG_WIDGETS)

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

static u_gx_flocal hmi_gfx_mgr02_ovglib_get_stride(u_gx_flocal p_image_type, u_gx_flocal p_image_width);
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
static void hmi_gfx_mgr02_ovglib_cache_update_live_count(UINT32 p_client_id);
#endif
static void hmi_gfx_mgr02_ovglib_vgSetParameteri(GFX_MGR02_VG_OBJ_TYPES p_bitmap_def_type, UINT32  p_setattributes,UINT32 p_handle);
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static void hmi_gfx_mgr02_ovglib_set_clip(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
#endif

#if GFX_MGR02_NUM_OF_FONTS > 0
#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && (GFX_MGR02_PRECREATE_FONTS != FONTS_NONE)
static void hmi_gfx_mgr02_ovglib_add_vfont_char(UINT32 p_ch_code, GFX_MGR02_OVG_GLYPH_DEF_T const * p_glyph, VGFont p_font);
#endif
static void hmi_gfx_mgr02_ovglib_font_init(void);
#endif

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/


static UINT8 l_ovglib_draw_sts;
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static VGint l_ovglib_clip_rect[4];
#endif

#ifndef GFX_MGR02_USER_DEFINED_INIT_MATRIX
static VGfloat l_vg_init_matrix[9];
#define GFX_MGR02_GET_INIT_MATRIX(x) (&l_vg_init_matrix[0])
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
static UINT8 l_vg_client_id;
#endif

#if (GFX_MGR02_NUM_OF_FONTS > 0) && (GFX_MGR02_PRECREATE_FONTS != FONTS_NONE)
VGFont l_vg_font[GFX_MGR02_NUM_OF_FONTS];
#endif

#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
static HMI_CHAR l_ovglib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif
#ifdef GFX_OVG_FAULT_HANDLE
static UINT32 l_ovglib_error;
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_cache_init
Description          : Empties the VG Image cache
Invocation           : Invoked internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static u_gx_flocal hmi_gfx_mgr02_ovglib_get_stride(u_gx_flocal p_image_type, u_gx_flocal p_image_width)
{
  p_image_type &= 0x0F;

  switch(p_image_type)
  { 
  case VG_sRGBX_8888:
  case VG_sRGBA_8888:
  case VG_sRGBA_8888_PRE:
  case VG_lRGBX_8888:
  case VG_lRGBA_8888:
  case VG_lRGBA_8888_PRE:
    {
      p_image_width <<= 2;
    }
    break;

  case VG_sRGB_565:
  case VG_sRGBA_5551:
  case VG_sRGBA_4444:
    {
      p_image_width <<= 1;
    }
    break;

  case VG_BW_1:
#if defined(OPENVG_VERSION_1_1)
  case VG_A_1:
#endif
    {
      p_image_width  += 7;
      p_image_width >>= 3;
    }
    break;

#if defined(OPENVG_VERSION_1_1)
  case VG_A_4:
    {
      p_image_width++;
      p_image_width >>= 1;
    }
    break;
#endif

  case VG_sL_8:
  case VG_lL_8:
  case VG_A_8:
  default:
    {
    	/*For MISRA warning fix.*/
    }
    break;
  }
  return(p_image_width);
}

#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_cache_init
Description          : Empties the VG Image cache
Invocation           : Invoked internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ovglib_cache_init(void)
{
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
  GFX_MGR02_VG_CACHE * fl_obj_vg_cache_def_S;
  UINT32 fl_index_1_U32;
  UINT32 fl_index_2_U32;
  UINT32 fl_vg_ctx_cache_size;

  for(fl_index_1_U32 = 0; fl_index_1_U32 < GFX_MGR02_OVGLIB_NB_CLIENTS; fl_index_1_U32++)
  {
    fl_obj_vg_cache_def_S = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_buf_SP;
    fl_vg_ctx_cache_size  = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_size;
    for(fl_index_2_U32 = 0;fl_index_2_U32 < fl_vg_ctx_cache_size;fl_index_2_U32++)
    {
      fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle = VG_INVALID_HANDLE;
      fl_obj_vg_cache_def_S[fl_index_2_U32].obj_def_SP = NULL;
      fl_obj_vg_cache_def_S[fl_index_2_U32].live_count = 0;
#ifdef GFX_MGR02_THEME_ENABLED
      fl_obj_vg_cache_def_S[fl_index_2_U32].theme_id = GFX_MGR02_THEME_MAX;
#endif
#if defined(GFX_MGR02_USE_FILESYSTEM) && defined(FSL_CONST_IMAGES)
      fl_obj_vg_cache_def_S[fl_index_2_U32].pixel_data = NULL;
#endif
    }
  }
#endif
#if defined (GFX_MGR02_VG_TXT_CACHE_ENABLED)
  hmi_gfx_mgr02_cache_init();
#endif

}

/*****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_cache_distroy
Description          : Empties the VG Image cache
Invocation           : Invoked internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ovglib_cache_distroy(void)
{
#if defined (GFX_MGR02_VG_IMG_CACHE_ENABLED)
  GFX_MGR02_VG_CACHE * fl_obj_vg_cache_def_S;
  UINT32 fl_index_1_U32;
  UINT32 fl_index_2_U32;
  UINT32 fl_vg_ctx_cache_size;

  for(fl_index_1_U32 = 0; fl_index_1_U32 < GFX_MGR02_OVGLIB_NB_CLIENTS; fl_index_1_U32++)
  {
    fl_obj_vg_cache_def_S = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_buf_SP;
    fl_vg_ctx_cache_size  = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_size;
    for(fl_index_2_U32 = 0;fl_index_2_U32 < fl_vg_ctx_cache_size;fl_index_2_U32++)
    {
      if(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle != VG_INVALID_HANDLE)
      {
        switch(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_type)
        {
        case GFX_MGR02_BITMAP_TYPE_E:
          {
#ifndef FSL_CONST_IMAGES
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
#else
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
#if defined(GFX_MGR02_USE_FILESYSTEM)
            free(fl_obj_vg_cache_def_S[fl_index_2_U32].pixel_data);
#endif
#endif
          }
          break;
        case GFX_MGR02_VECTOR_TYPE_E:
          {
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
          }
          break;
        case GFX_MGR02_FPAINT_TYPE_COLOR_E:
        case GFX_MGR02_SPAINT_TYPE_COLOR_E:
        case GFX_MGR02_FPAINT_TYPE_LGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_LGRAD_E:
        case GFX_MGR02_FPAINT_TYPE_RGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_RGRAD_E:
          {
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
          }
          break;
        default:
          /* Added for QA C warning */
          break;
        }
      }
      fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle = VG_INVALID_HANDLE;
      fl_obj_vg_cache_def_S[fl_index_2_U32].obj_def_SP = NULL;
      fl_obj_vg_cache_def_S[fl_index_2_U32].live_count = 0;
      fl_obj_vg_cache_def_S[fl_index_2_U32].obj_type   = GFX_MGR02_INVALID_TYPE_E;
#ifdef GFX_MGR02_THEME_ENABLED
      fl_obj_vg_cache_def_S[fl_index_2_U32].theme_id   = GFX_MGR02_THEME_MAX;
#endif
#if defined(GFX_MGR02_USE_FILESYSTEM) && defined(FSL_CONST_IMAGES)
      fl_obj_vg_cache_def_S[fl_index_2_U32].pixel_data = NULL;
#endif
    }
  }
#endif
#if defined (GFX_MGR02_VG_TXT_CACHE_ENABLED)
  hmi_gfx_mgr02_cache_shutdown();
#endif

}
#endif /* #if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED) */

#if defined (GFX_MGR02_VG_IMG_CACHE_ENABLED)
/*****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_remove_from_cache
Description          : Removes the passed pixel data element from cache.
Invocation           : Invoked internally/externally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ovglib_remove_from_cache(void const * p_obj_def_S)
{
  GFX_MGR02_VG_CACHE * fl_obj_vg_cache_def_S;
  UINT32 fl_index_1_U32;
  UINT32 fl_index_2_U32;
  UINT32 fl_vg_ctx_cache_size;
  for(fl_index_1_U32 = 0; fl_index_1_U32 < GFX_MGR02_OVGLIB_NB_CLIENTS; fl_index_1_U32++)
  {
    fl_obj_vg_cache_def_S = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_buf_SP;
    fl_vg_ctx_cache_size  = lc_vg_cache_config_def_S[fl_index_1_U32].vg_ctx_cache_size;
    for(fl_index_2_U32 = 0;fl_index_2_U32 < fl_vg_ctx_cache_size;fl_index_2_U32++)
    {
      if((fl_obj_vg_cache_def_S[fl_index_2_U32].obj_def_SP == p_obj_def_S)&&
        (fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle != VG_INVALID_HANDLE))
      {
        switch(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_type)
        {
        case GFX_MGR02_BITMAP_TYPE_E:
          {
#ifndef FSL_CONST_IMAGES
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
#else
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
#if defined(GFX_MGR02_USE_FILESYSTEM)
            free(fl_obj_vg_cache_def_S[fl_index_2_U32].pixel_data);
#endif
#endif
          }
          break;
        case GFX_MGR02_VECTOR_TYPE_E:
          {
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
          }
          break;
        case GFX_MGR02_FPAINT_TYPE_COLOR_E:
        case GFX_MGR02_SPAINT_TYPE_COLOR_E:
        case GFX_MGR02_FPAINT_TYPE_LGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_LGRAD_E:
        case GFX_MGR02_FPAINT_TYPE_RGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_RGRAD_E:
          {
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle));
          }
          break;
        default:
          /* Added for QA C warning */
          break;
        }
        fl_obj_vg_cache_def_S[fl_index_2_U32].obj_handle = VG_INVALID_HANDLE;
        fl_obj_vg_cache_def_S[fl_index_2_U32].obj_def_SP = NULL;
        fl_obj_vg_cache_def_S[fl_index_2_U32].live_count = 0;
        fl_obj_vg_cache_def_S[fl_index_2_U32].obj_type   = GFX_MGR02_INVALID_TYPE_E;
#ifdef GFX_MGR02_THEME_ENABLED
        fl_obj_vg_cache_def_S[fl_index_2_U32].theme_id   = GFX_MGR02_THEME_MAX;
#endif
#if defined(GFX_MGR02_USE_FILESYSTEM) && defined(FSL_CONST_IMAGES)
        fl_obj_vg_cache_def_S[fl_index_2_U32].pixel_data = NULL;
#endif
        break;
      }

    }
  }
}


/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_cache_update_live_count
Description          : Reduces the live count of the images in vg image cache
Invocation           : Invoked internally
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglib_cache_update_live_count(UINT32 p_client_id)
{
  GFX_MGR02_VG_CACHE * fl_obj_vg_cache_def_S;
  UINT32 fl_index_1_U32;
  UINT32 fl_vg_ctx_cache_size;

  if(p_client_id < GFX_MGR02_OVGLIB_NB_CLIENTS)
  {
    fl_obj_vg_cache_def_S = lc_vg_cache_config_def_S[p_client_id].vg_ctx_cache_buf_SP;
    fl_vg_ctx_cache_size  = lc_vg_cache_config_def_S[p_client_id].vg_ctx_cache_size;
    for(fl_index_1_U32 = 0;fl_index_1_U32 < fl_vg_ctx_cache_size;fl_index_1_U32++)
    {
      if(fl_obj_vg_cache_def_S[fl_index_1_U32].live_count != 0)
      {
        fl_obj_vg_cache_def_S[fl_index_1_U32].live_count--;
      }
      if(fl_obj_vg_cache_def_S[fl_index_1_U32].live_count == 0)
      {
        if(fl_obj_vg_cache_def_S[fl_index_1_U32].obj_def_SP != NULL)
        {
          hmi_gfx_mgr02_ovglib_remove_from_cache(fl_obj_vg_cache_def_S[fl_index_1_U32].obj_def_SP);
        }
      }
    }
  }
}
#endif /* #if GFX_MGR02_VG_CACHE_SIZE > 0 */
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_load_imagefile_to_mem
Description          : Reads the image file and loads it in to RAM. If the 
image is compressed then uncompress it.
Invocation           : Invoked internally
Parameters           : 
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 * hmi_gfx_mgr02_ovglib_load_imagefile_to_mem(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP,
  UINT32                        p_byte_per_px)
{
  UINT8 * fl_dest_tex        = GFX_MGR02_NULL_PTR;
#ifdef GFX_MGR02_USE_FILESYSTEM 
#ifdef GFX_MGR02_THEME_ENABLED
  FILE * fl_image_file = hmi_gfx_mgr02_theme_fopen(p_elem_def_SP->pixel_data);
#else
  FILE * fl_image_file = fopen(p_elem_def_SP->pixel_data, "rb");
#endif

  if(fl_image_file != 0)
  {
    UINT32  fl_blk_size;
    fl_blk_size  = p_byte_per_px;
    fl_blk_size *= p_elem_def_SP->width;
    fl_blk_size *= p_elem_def_SP->height;
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
    /* for mqx use uncached memory for malloc */
    fl_dest_tex       = (UINT8 *)_mem_alloc_uncached(fl_blk_size);
#else
    fl_dest_tex       = (UINT8 *)malloc(fl_blk_size);
#endif
    if(fl_dest_tex != 0)
    {
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      if(p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
      {
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER)
        UINT8  fl_offset;
        UINT32 fl_comp_size;
        UINT8 * fl_src_tex        = GFX_MGR02_NULL_PTR; 
        fl_src_tex                = (UINT8 *)_mem_alloc_uncached(fl_blk_size);
        if(fl_src_tex != 0)
        {
          if(fread(&fl_offset, 1, 1, fl_image_file) != 1)
          {
            _mem_free(fl_src_tex);
            fl_src_tex = 0;
            _mem_free(fl_dest_tex);
            fl_dest_tex = 0;
          }
          else if(fread(&fl_comp_size, 4, 1, fl_image_file) != 1)
          {
            _mem_free(fl_src_tex);
            fl_src_tex = 0;
            _mem_free(fl_dest_tex);
            fl_dest_tex = 0;
          }    
          else if(fread(fl_src_tex, 1, fl_comp_size, fl_image_file) != fl_comp_size)
          {

            _mem_free(fl_src_tex);
            fl_src_tex = 0;
            _mem_free(fl_dest_tex);
            fl_dest_tex = 0;
          }
          else
          {
            rle_decode((UINT32)fl_src_tex, (UINT32)fl_dest_tex, BPP32, fl_comp_size, p_elem_def_SP->height, p_elem_def_SP->width, 1, 1, p_elem_def_SP->width, p_elem_def_SP->height);
            _mem_free(fl_src_tex);
            fl_src_tex = 0;
          }
        }
        else
        {
          _mem_free(fl_dest_tex);
          fl_dest_tex = 0;
          GFX_MGR02_OVG_LOG_ERROR(l_ovglib_error, GFX_MGR02_MEMORY_ALLOC_FAULT);
        }
#else 
        SINT32  fl_rle_size = (SINT32)(p_elem_def_SP->comp_size);
        UINT8   fl_cmd_byte;
        UINT8   fl_data[4];
        UINT8 * fl_dcomp_buffp    = fl_dest_tex;
        UINT32  fl_dcomp_rem_size = fl_blk_size;
        while((fl_rle_size > 0) && (fl_dcomp_rem_size > 0))
        {
          fl_rle_size--;
          if(fread(&fl_cmd_byte, 1, 1, fl_image_file) != 1)
          {
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
            _mem_free(fl_dest_tex);
#else
            free(fl_dest_tex);
#endif
            fl_dest_tex      = 0;
            fl_rle_size = 0;
          }
          else if((fl_cmd_byte & 0x80) != 0)
          {
            fl_cmd_byte &= 0x7F;
            if(fread(&fl_data, 1, p_byte_per_px, fl_image_file) != p_byte_per_px)
            {
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
              _mem_free(fl_dest_tex);
#else
              free(fl_dest_tex);
#endif
              fl_dest_tex      = 0;
              fl_rle_size = 0;
            }
            else
            {
              fl_rle_size -= p_byte_per_px;
              fl_cmd_byte++;
              while(fl_cmd_byte > 0)
              {
                fl_cmd_byte--;
                if(fl_dcomp_rem_size < p_byte_per_px)
                {
                  p_byte_per_px = fl_dcomp_rem_size;
                  fl_cmd_byte   = 0;
                }
                memcpy(fl_dcomp_buffp, fl_data, p_byte_per_px);
                fl_dcomp_buffp    += p_byte_per_px;
                fl_dcomp_rem_size -= p_byte_per_px;
              }
            }
          }
          else
          {
            fl_cmd_byte++;
            fl_blk_size = (p_byte_per_px*fl_cmd_byte);
            if(fl_dcomp_rem_size < fl_blk_size)
            {
              fl_blk_size = fl_dcomp_rem_size;
            }
            if(fread(fl_dcomp_buffp, 1, fl_blk_size, fl_image_file) != fl_blk_size)
            {
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
              _mem_free(fl_dest_tex);
#else
              free(fl_dest_tex);
#endif
              fl_dest_tex      = 0;
              fl_rle_size = 0;
            }
            else
            {
              fl_dcomp_buffp    += fl_blk_size;
              fl_rle_size       -= fl_blk_size;
              fl_dcomp_rem_size -= fl_blk_size;
            }
          }
        }
#endif
      }
      else if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
      {
        /* other compression types not supported currently */
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
        _mem_free(fl_dest_tex);
#else
        free(fl_dest_tex);
#endif
        fl_dest_tex = 0;
      }
      else
#endif
      {
        if(fread(fl_dest_tex, 1, fl_blk_size, fl_image_file) != fl_blk_size)
        {
          /* 
          ** error condition 	                                                                     
          */
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && defined(__MQXOS__)
          _mem_free(fl_dest_tex);
#else
          free(fl_dest_tex);
#endif
          fl_dest_tex = 0;
        }
      }
    }
    else
    {
      GFX_MGR02_OVG_LOG_ERROR(l_ovglib_error, GFX_MGR02_MEMORY_ALLOC_FAULT);
    }
    fclose(fl_image_file);
  }
#else
  GFX_MGR02_UNUSED_VAR(p_byte_per_px);
  GFX_MGR02_UNUSED_PTR(p_elem_def_SP); 
#endif
  return(fl_dest_tex);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_vgSetParameteri
Description          : Performs vgSetParameteri depending on the bitmapdef type
Invocation           : Invoked by hmi_gfx_mgr02_ovglib_cache_get_object
Parameters           : Input: p_bitmap_def_type  - Type of Image type
p_setattributes    - attributes of the image 
p_handle           - Local handle
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglib_vgSetParameteri(GFX_MGR02_VG_OBJ_TYPES p_bitmap_def_type, UINT32  p_setattributes, UINT32 p_handle)
{
  if((p_bitmap_def_type == GFX_MGR02_FPAINT_TYPE_LGRAD_E) || (p_bitmap_def_type == GFX_MGR02_FPAINT_TYPE_RGRAD_E))
  {
    if((p_setattributes & GFX_MGR02_PATH_PROP_FILL_SPREAD) == GFX_MGR02_PATH_PROP_FILL_SPREAD_PAD)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_PAD));
    }
    else if((p_setattributes & GFX_MGR02_PATH_PROP_FILL_SPREAD) == GFX_MGR02_PATH_PROP_FILL_SPREAD_REPEAT)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_REPEAT));
    }
    else if((p_setattributes & GFX_MGR02_PATH_PROP_FILL_SPREAD) == GFX_MGR02_PATH_PROP_FILL_SPREAD_REFLECT)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_REFLECT));
    }
    else
    {
    	/*For MISRA warning fix.*/
    }
  }
  else
  {
    if((p_setattributes & GFX_MGR02_PATH_PROP_STROKE_SPREAD) == GFX_MGR02_PATH_PROP_STROKE_SPREAD_PAD)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_PAD));
    }
    else if((p_setattributes & GFX_MGR02_PATH_PROP_STROKE_SPREAD) == GFX_MGR02_PATH_PROP_STROKE_SPREAD_REPEAT)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_REPEAT));
    }
    else if((p_setattributes & GFX_MGR02_PATH_PROP_STROKE_SPREAD) == GFX_MGR02_PATH_PROP_STROKE_SPREAD_REFLECT)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(p_handle,  VG_PAINT_COLOR_RAMP_SPREAD_MODE,   VG_COLOR_RAMP_SPREAD_REFLECT));
    }
    else
    {
    	/*For MISRA warning fix.*/
    }
  }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_cache_get_object
Description          : Searches through the image cache for the passed object
If found, returns the handle. If not found in cache
then frees up the oldest image and then creates new VG
image object.
Invocation           : Invoked internally by GfxDriverBuildBitmapImage
Parameters           : Input: *pc_bitmap_def_S - Image Buffer.
bitmap_def_type  - Type of Image type
attributes       - attributes of the image 
Return Value         : UINT32 - VG_INVALID_HANDLE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_ovglib_cache_get_object(void const           * pc_bitmap_def_S, 
  GFX_MGR02_VG_OBJ_TYPES bitmap_def_type, 
  UINT32                 p_raw_data,
  UINT32                 p_attributes)
{
  UINT32 fl_handle = VG_INVALID_HANDLE;
  UINT8 * fl_tex;
  UINT32 fl_byte_per_pix;

  if(pc_bitmap_def_S != NULL)
  {
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
#ifdef GFX_MGR02_THEME_ENABLED
    UINT32 fl_active_theme_U32 = hmi_gfx_mgr02_theme_get_active_theme();
#endif
    void const * fl_obj_def_S;
    GFX_MGR02_VG_CACHE_CONFIG const * fl_vg_config_buf_S = NULL;
    GFX_MGR02_VG_CACHE * fl_obj_vg_cache_def_S; 
    UINT32       fl_vg_ctx_cache_size;
    UINT32          index    = 0;
    UINT32          lu_count = 256;
    UINT32          lu_index = 0;
    if(bitmap_def_type == GFX_MGR02_BITMAP_TYPE_E)
    {
      fl_obj_def_S = ((GFX_MGR02_IMAGE_DEF_T const *)pc_bitmap_def_S)->pixel_data;
    }
    else
    {
      fl_obj_def_S = pc_bitmap_def_S;
    }
    /* 
    ** Each OpenVG context has individual cache buffers and the buffer addresses and their
    ** size is stored in the vg cache config buffer. The client id, which denotes the context,
    ** indexes into the cache config buffer to get the address,size of the VG cache specific
    ** to the context/client id 
    */
    if(l_vg_client_id < GFX_MGR02_OVGLIB_NB_CLIENTS)
    {
      fl_vg_config_buf_S = &lc_vg_cache_config_def_S[l_vg_client_id];
    }
    if(fl_vg_config_buf_S != NULL)
#endif
    {
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
      fl_obj_vg_cache_def_S = fl_vg_config_buf_S->vg_ctx_cache_buf_SP;
      fl_vg_ctx_cache_size  = fl_vg_config_buf_S->vg_ctx_cache_size;
      if((fl_obj_vg_cache_def_S != NULL) && (fl_vg_ctx_cache_size > 0))
#endif
      { 
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
        while(index <  (UINT32)fl_vg_ctx_cache_size)
        {
#ifndef GFX_MGR02_THEME_ENABLED  
          if(fl_obj_vg_cache_def_S[index].obj_def_SP == fl_obj_def_S)
#else
          if((fl_obj_vg_cache_def_S[index].obj_def_SP == fl_obj_def_S)&&
            ((fl_obj_vg_cache_def_S[index].obj_type != GFX_MGR02_BITMAP_TYPE_E)||
            (fl_obj_vg_cache_def_S[index].theme_id == fl_active_theme_U32)))
#endif
          {
            /* Image handle exists in the cache already */
            fl_obj_vg_cache_def_S[index].live_count   = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
            return(fl_obj_vg_cache_def_S[index].obj_handle);
          }
          else if(lu_count != 0)
          {
            if(fl_obj_vg_cache_def_S[index].obj_handle == VG_INVALID_HANDLE)
            {
              /* 
              ** This is a freelocation, mark this in lu_index, so that we could
              ** use this to create this object if its not found
              */
              lu_count = 0;
              lu_index = index;
            }
            else if(fl_obj_vg_cache_def_S[index].live_count < lu_count)
            {
              /*
              ** Mark the object which was not used for quite some time
              ** (the one which has a low live_count). We could distroy
              ** this if we could not create the requested object
              */
              lu_count = (UINT32)fl_obj_vg_cache_def_S[index].live_count;
              lu_index = index;
            }
            else
            {
            	/*For MISRA warning fix.*/
            }
          }
          else
          {
        	  /*For MISRA warning fix.*/
          }
          index++;
        }
        for(index = lu_index; index < (UINT32)fl_vg_ctx_cache_size; index++)
        {
          fl_handle = fl_obj_vg_cache_def_S[index].obj_handle;
          if((fl_obj_vg_cache_def_S[index].live_count == lu_count) && (fl_handle != VG_INVALID_HANDLE))
          {
            if(fl_obj_vg_cache_def_S[index].obj_type == GFX_MGR02_VECTOR_TYPE_E)
            {
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(fl_handle));
            }
            else if(fl_obj_vg_cache_def_S[index].obj_type < GFX_MGR02_FPAINT_TYPE_COLOR_E)
            {
#ifndef FSL_CONST_IMAGES
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_handle));
#else
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_handle));
#if defined(GFX_MGR02_USE_FILESYSTEM)
              free(fl_obj_vg_cache_def_S[index].pixel_data);
#endif
#endif
            }
            else if(fl_obj_vg_cache_def_S[index].obj_type < GFX_MGR02_SPAINT_TYPE_RGRAD_E)
            {
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(fl_handle));
            }
            else
            {
            	/*For MISRA warning fix.*/
            }
            fl_obj_vg_cache_def_S[index].obj_type   = GFX_MGR02_INVALID_TYPE_E;
            fl_obj_vg_cache_def_S[index].obj_handle = VG_INVALID_HANDLE;
            fl_obj_vg_cache_def_S[index].live_count = 0;
            fl_obj_vg_cache_def_S[index].obj_def_SP = NULL;
#ifdef GFX_MGR02_THEME_ENABLED  
            fl_obj_vg_cache_def_S[index].theme_id   = GFX_MGR02_THEME_MAX;
#endif
          }
        }
#endif/*GFX_MGR02_VG_IMG_CACHE_ENABLED*/
        switch(((GFX_MGR02_IMAGE_DEF_T const *)pc_bitmap_def_S)->format)
        {
        case VG_A_8:
          {
            fl_byte_per_pix  = 1;
          }
          break;
        case VG_sARGB_8888:
        case VG_sXRGB_8888:
          {
            fl_byte_per_pix  = 4;
          }
          break;
        case VG_sARGB_4444:
        case VG_sARGB_1555:
        case VG_sRGB_565:
          {
            fl_byte_per_pix  = 2;
          }
          break;
        default: 
          {
            fl_byte_per_pix = 0;
          }
          break;
        }
        switch(bitmap_def_type)
        {
        case GFX_MGR02_BITMAP_TYPE_E:
          {
            GFX_MGR02_IMAGE_DEF_T const * fl_bitmap_def_S = (GFX_MGR02_IMAGE_DEF_T const *)pc_bitmap_def_S;
            u_gx_flocal                   fl_stride;
            if(p_raw_data == FALSE)
            {
              fl_tex = hmi_gfx_mgr02_ovglib_load_imagefile_to_mem((GFX_MGR02_IMAGE_DEF_T const *)pc_bitmap_def_S,fl_byte_per_pix);
              fl_stride = hmi_gfx_mgr02_ovglib_get_stride(fl_bitmap_def_S->format,   fl_bitmap_def_S->width);
            }
            else
            {
              fl_stride = hmi_gfx_mgr02_ovglib_get_stride(fl_bitmap_def_S->format,   fl_bitmap_def_S->width);
            }

#ifdef FSL_CONST_IMAGES
            if(p_raw_data == FALSE)
            {

              if(fl_tex != NULL)
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateConstImageFSL, fl_handle=vgCreateConstImageFSL(fl_bitmap_def_S->format,
                  fl_tex,
                  fl_stride,
                  fl_bitmap_def_S->width,
                  fl_bitmap_def_S->height,
                  GFX_MGR02_VG_IMAGE_QUALITY_CONFIG,
                  VG_FALSE));
              }

            }
            else
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateConstImageFSL, fl_handle=vgCreateConstImageFSL(fl_bitmap_def_S->format,
                fl_bitmap_def_S->pixel_data,
                fl_stride,
                fl_bitmap_def_S->width,
                fl_bitmap_def_S->height,
                GFX_MGR02_VG_IMAGE_QUALITY_CONFIG,
                VG_FALSE));

            }
            if(fl_handle != VG_INVALID_HANDLE)
            {
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = fl_obj_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_BITMAP_TYPE_E;
#if defined(GFX_MGR02_USE_FILESYSTEM)
              fl_obj_vg_cache_def_S[lu_index].pixel_data = fl_tex;
#endif
#ifdef GFX_MGR02_THEME_ENABLED  
              fl_obj_vg_cache_def_S[lu_index].theme_id   = fl_active_theme_U32;
#endif
#endif
            }
#else
            if(p_raw_data == FALSE)
            {
              if(fl_tex != NULL)
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_handle=vgCreateImage((VGImageFormat)fl_bitmap_def_S->format, 
                  (VGint)fl_bitmap_def_S->width, 
                  (VGint)fl_bitmap_def_S->height, 
                  GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));

                if(fl_handle != VG_INVALID_HANDLE)
                {
                  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_handle,
                    fl_tex,
                    (VGint)fl_stride,
                    (VGImageFormat)fl_bitmap_def_S->format,
                    0,
                    0,
                    (VGint)fl_bitmap_def_S->width,
                    (VGint)fl_bitmap_def_S->height));

                }
                (void)free(fl_tex);
              }
            }
            else
            {

              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_handle=vgCreateImage((VGImageFormat)fl_bitmap_def_S->format, 
                (VGint)fl_bitmap_def_S->width, 
                (VGint)fl_bitmap_def_S->height, 
                GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));


              if(fl_handle != VG_INVALID_HANDLE)
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_handle,
                  fl_bitmap_def_S->pixel_data,
                  (VGint)fl_stride,
                  (VGImageFormat)fl_bitmap_def_S->format,
                  0,
                  0,
                  (VGint)fl_bitmap_def_S->width,
                  (VGint)fl_bitmap_def_S->height));
              }
            }
            if(fl_handle != VG_INVALID_HANDLE)
            {
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = fl_obj_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_BITMAP_TYPE_E;
#ifdef GFX_MGR02_THEME_ENABLED  
              fl_obj_vg_cache_def_S[lu_index].theme_id   = fl_active_theme_U32;
#endif
#endif
            }

#endif
          }
          break;

        case GFX_MGR02_VECTOR_TYPE_E:
          {
            GFX_MGR02_OVG_PATH_DEF_T const * fl_ovg_path_SP = (GFX_MGR02_OVG_PATH_DEF_T const *)pc_bitmap_def_S;

            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePath, fl_handle=vgCreatePath( VG_PATH_FORMAT_STANDARD,
              VG_PATH_DATATYPE_F,
              1.0f,
              0.0f,
              0,
              0,
              VG_PATH_CAPABILITY_APPEND_FROM|VG_PATH_CAPABILITY_APPEND_TO));

            if(fl_handle != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(fl_handle,
                (VGint)fl_ovg_path_SP->numSegments,
                fl_ovg_path_SP->path_segments_u8p,
                fl_ovg_path_SP->path_data_fp));
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = pc_bitmap_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_VECTOR_TYPE_E;
#endif
            }
          }
          break;

        case GFX_MGR02_FPAINT_TYPE_COLOR_E:
        case GFX_MGR02_SPAINT_TYPE_COLOR_E:
          {
            GFX_MGR02_OVG_COLOR_DEF_T const * fl_color_SP = (GFX_MGR02_OVG_COLOR_DEF_T const *)pc_bitmap_def_S;
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, fl_handle=vgCreatePaint());
            if(fl_handle != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_handle, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_handle, VG_PAINT_COLOR, 4, fl_color_SP->rgba));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(fl_handle,  VG_FILL_PATH));
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = pc_bitmap_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_FPAINT_TYPE_COLOR_E;
#endif
            }
          }
          break;

        case GFX_MGR02_FPAINT_TYPE_LGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_LGRAD_E:
          {
            GFX_MGR02_OVG_LGRAD_DEF_T const * fl_color_SP = (GFX_MGR02_OVG_LGRAD_DEF_T const *)pc_bitmap_def_S;
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, fl_handle=vgCreatePaint());
            if(fl_handle != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_handle,  VG_PAINT_TYPE, VG_PAINT_TYPE_LINEAR_GRADIENT));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_handle, VG_PAINT_LINEAR_GRADIENT,          4, fl_color_SP->bbox));
              hmi_gfx_mgr02_ovglib_vgSetParameteri(bitmap_def_type,p_attributes,fl_handle);
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_handle,  VG_PAINT_COLOR_RAMP_PREMULTIPLIED, VG_FALSE));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_handle, VG_PAINT_COLOR_RAMP_STOPS, (VGint)fl_color_SP->stop_length, fl_color_SP->stop_table_fp));
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = pc_bitmap_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_FPAINT_TYPE_LGRAD_E;
#endif
            }
          }
          break;

        case GFX_MGR02_FPAINT_TYPE_RGRAD_E:
        case GFX_MGR02_SPAINT_TYPE_RGRAD_E:
          {
            GFX_MGR02_OVG_RGRAD_DEF_T const * fl_color_SP = (GFX_MGR02_OVG_RGRAD_DEF_T const *)pc_bitmap_def_S;
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, fl_handle=vgCreatePaint());
            if(fl_handle != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_handle,  VG_PAINT_TYPE, VG_PAINT_TYPE_RADIAL_GRADIENT));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_handle, VG_PAINT_RADIAL_GRADIENT, 5, fl_color_SP->bbox));
              hmi_gfx_mgr02_ovglib_vgSetParameteri(bitmap_def_type,p_attributes,fl_handle);
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_handle,  VG_PAINT_COLOR_RAMP_PREMULTIPLIED, VG_FALSE));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_handle, VG_PAINT_COLOR_RAMP_STOPS, (VGint)fl_color_SP->stop_length, fl_color_SP->stop_table_fp));
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              fl_obj_vg_cache_def_S[lu_index].obj_def_SP = pc_bitmap_def_S;
              fl_obj_vg_cache_def_S[lu_index].live_count = GFX_MGR02_MAX_IMAGE_CACHE_LIVE;
              fl_obj_vg_cache_def_S[lu_index].obj_type   = GFX_MGR02_FPAINT_TYPE_RGRAD_E;
#endif
            }
          }
          break;
        default:
          {
            /*
            ** Unsupported type
            */
            fl_handle = VG_INVALID_HANDLE;
          }
          break;
        }
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
        fl_obj_vg_cache_def_S[lu_index].obj_handle = fl_handle;
#endif
      }/*(fl_obj_vg_cache_def_S != 0)*/
    }/*(fl_vg_config_buf_S != 0)*/
  }/*(pc_bitmap_def_S != 0)*/
  return(fl_handle);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_init(void)
{
  l_ovglib_draw_sts     = 0;
#ifdef GFX_OVG_FAULT_HANDLE
  l_ovglib_error        = 0;
#endif
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  l_ovglib_clip_rect[0] = 0;
  l_ovglib_clip_rect[1] = 0;
  l_ovglib_clip_rect[2] = 0;
  l_ovglib_clip_rect[3] = 0;
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED) || defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
  hmi_gfx_mgr02_ovglib_cache_init();
#endif
#ifdef GFX_DRIVER_SUPPORT_VECTOR_FONT
  VGF_Init();
#endif

#ifndef GFX_MGR02_USER_DEFINED_INIT_MATRIX
  l_vg_init_matrix[0] = 1;
  l_vg_init_matrix[1] = 0;
  l_vg_init_matrix[2] = 0;
  l_vg_init_matrix[3] = 0;
  l_vg_init_matrix[4] = 1;
  l_vg_init_matrix[5] = 0;
  l_vg_init_matrix[6] = 0;
  l_vg_init_matrix[7] = 0;
  l_vg_init_matrix[8] = 1;
#endif
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
  l_vg_client_id      = 0;
#endif
#if GFX_MGR02_NUM_OF_FONTS > 0
  hmi_gfx_mgr02_ovglib_font_init();
#endif
  return(TRUE);
}

#if GFX_MGR02_NUM_OF_FONTS > 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_font_init
Description          : Precreates the fonts in to a shared context.
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglib_font_init(void)
{
#if GFX_MGR02_PRECREATE_FONTS != FONTS_NONE
  UINT32                 fl_font_id;
  GFX_MGR02_FONT const * fl_font_table_SP = &lc_gfx_font_table[0];

  for(fl_font_id = 0; fl_font_id < GFX_MGR02_NUM_OF_FONTS; fl_font_id++,fl_font_table_SP++)
  {
    if(fl_font_table_SP->is_group == 0)
    {
      if(fl_font_table_SP->is_vfont == 0)
      {
      }
#if ((GFX_MGR02_PRECREATE_FONTS & FONTS_SVG) != 0) && (GFX_MGR02_OVG_FONT_PRESENT > 0)
      else
      {
        GFX_MGR02_FONT_LUT const * fl_ovg_ptr_SP = fl_font_table_SP->f.ovg_ptr->lut_ptr;
        UINT32                 i;
        UINT32                 fl_glyphs;
        for(i=0,fl_glyphs=0; i < fl_font_table_SP->size_table; i++,fl_ovg_ptr_SP++)
        {
          if((fl_ovg_ptr_SP->attributes & GFX_MGR02_FONT_SEARCH_MODE_DIRECT) != 0)
          {
            fl_glyphs++;
          }
          else if((fl_ovg_ptr_SP->attributes & GFX_MGR02_FONT_SEARCH_MODE_TLUP) != 0)
          {
            fl_glyphs += (fl_ovg_ptr_SP[1].ch_code-fl_ovg_ptr_SP->ch_code);
          }
          else
          {
        	  /*For MISRA warning fix*/
          }
        }
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateFont, l_vg_font[fl_font_id]=vgCreateFont(fl_glyphs));
        if(l_vg_font[fl_font_id] != VG_INVALID_HANDLE)
        {
          fl_ovg_ptr_SP = fl_font_table_SP->f.ovg_ptr->lut_ptr;
          for(i=0; i < fl_font_table_SP->size_table; i++, fl_ovg_ptr_SP++)
          {
            if((fl_ovg_ptr_SP->attributes & GFX_MGR02_FONT_SEARCH_MODE_DIRECT) != 0)
            {
              hmi_gfx_mgr02_ovglib_add_vfont_char(fl_ovg_ptr_SP->ch_code, 
                (GFX_MGR02_OVG_GLYPH_DEF_T const *)fl_ovg_ptr_SP->fcc_ptr,
                l_vg_font[fl_font_id]);
            }
            else if((fl_ovg_ptr_SP->attributes & GFX_MGR02_FONT_SEARCH_MODE_TLUP) != 0)
            {
              GFX_MGR02_OVG_GLYPH_DEF_T const * fl_glyph_SP = (GFX_MGR02_OVG_GLYPH_DEF_T const *)fl_ovg_ptr_SP->fcc_ptr;
              UINT32                            fl_ch_code  = fl_ovg_ptr_SP->ch_code;
              UINT32                            fl_end_code = fl_ovg_ptr_SP[1].ch_code;
              while(fl_ch_code < fl_end_code)
              {
                hmi_gfx_mgr02_ovglib_add_vfont_char(fl_ch_code, 
                  fl_glyph_SP,
                  l_vg_font[fl_font_id]);
                fl_ch_code++;
                fl_glyph_SP++;
              }
            }
            else
            {
            	/*For MISRA warning.*/
            }
          }
        }
      }
#endif
    }
  }
#endif
}

#if (GFX_MGR02_OVG_FONT_PRESENT > 0) && (GFX_MGR02_PRECREATE_FONTS != FONTS_NONE)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_add_vfont_char
Description          : Precreates the passed glyph.
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglib_add_vfont_char(UINT32 p_ch_code, GFX_MGR02_OVG_GLYPH_DEF_T const * p_glyph, VGFont p_font)
{
  VGPath  vgpath = VG_INVALID_HANDLE;
  VGfloat fl_origin[2];
  VGfloat fl_escapement[2];

  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgpath=vgCreatePath(VG_PATH_FORMAT_STANDARD, 
    VG_PATH_DATATYPE_S_16, 
    1.0f, 
    0.0f, 
    0, 
    0, 
    VG_PATH_CAPABILITY_ALL));
  if(vgpath != VG_INVALID_HANDLE)
  {
    if(p_glyph->num_p_segs != 0)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(vgpath, 
        p_glyph->num_p_segs, 
        p_glyph->path_segments_u8p, 
        p_glyph->path_data_s16p));
    }
    fl_origin[0]     = 0.0f;
    fl_origin[1]     = 0.0f;
    fl_escapement[0] = (GFX_FLOAT)p_glyph->x_advance;
    fl_escapement[1] = 0.0f;
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToPath, vgSetGlyphToPath(p_font, p_ch_code, vgpath, VG_FALSE, fl_origin, fl_escapement));
    GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(vgpath));
  }
}
#endif /* #if (GFX_MGR02_OVG_FONT_PRESENT > 0) && (GFX_MGR02_PRECREATE_FONTS != FONTS_NONE) */
#endif /* #if GFX_MGR02_NUM_OF_FONTS > 0 */

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_RENDERING_QUALITY, GFX_MGR02_VG_RENDER_QUALITY_CONFIG));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_QUALITY,     GFX_MGR02_VG_SURFACE_QUALITY_CONFIG));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_SCISSORING, VG_FALSE));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MASKING,    VG_FALSE));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  l_ovglib_clip_rect[0] = 0;
  l_ovglib_clip_rect[1] = 0;
  l_ovglib_clip_rect[2] = (VGint)p_cntx_SP->rprop.fb_w;
  l_ovglib_clip_rect[3] = (VGint)p_cntx_SP->rprop.fb_h;
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetiv, vgSetiv(VG_SCISSOR_RECTS, 4, l_ovglib_clip_rect));
#endif

#ifndef GFX_MGR02_USER_DEFINED_INIT_MATRIX
  l_vg_init_matrix[0] = 1;
  l_vg_init_matrix[1] = 0;
  l_vg_init_matrix[2] = 0;
  l_vg_init_matrix[3] = 0;
#if defined(GFX_MGR02_VG_MIRROR_OUTPUT) || defined(WIN32)
  l_vg_init_matrix[4] = -1;
#else
  l_vg_init_matrix[4] = 1;
#endif
  l_vg_init_matrix[5] = 0;
  l_vg_init_matrix[6] = 0;
#if defined(GFX_MGR02_VG_MIRROR_OUTPUT) || defined(WIN32)
  l_vg_init_matrix[7] = p_cntx_SP->rprop.fb_h;
#else
  l_vg_init_matrix[7] = 0;
#endif
  l_vg_init_matrix[8] = 1;
#endif
  l_ovglib_draw_sts = 0;
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
  l_vg_client_id    = p_cntx_SP->rprop.layer_id;
#endif
  return(TRUE);
}
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_set_clip
Description          : Sets the clip area to the passed one if it is new area
Invocation           : Invoked internally
Parameters           : Clip area via context pointer
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ovglib_set_mask_mode(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
  if(p_cntx_SP->rprop.mask_mode == GFX_MGR02_MASK_WIDGET_NORMAL) 
  {
     GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MASKING, VG_TRUE));
  }
  else
  {
     GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MASKING, VG_FALSE));
  }
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_finish
Description          : Function to be called after all building operation are
completed. This will perform the VG flush to perform
any pending VG operations 
Invocation           : Invoked by manager
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_finish(void)
{
  if((l_ovglib_draw_sts & GFX_MGR02_OVGLIB_FLUSH_PENDING) != 0)
  {
    l_ovglib_draw_sts &= (UINT8)(~GFX_MGR02_OVGLIB_FLUSH_PENDING);
    vgFinish();
#if defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
    hmi_gfx_mgr02_ovglib_cache_update_live_count(l_vg_client_id);
#endif
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
    hmi_gfx_mgr02_cache_update_live_count();
#endif
  }
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW
#ifdef GFX_MGR02_DIRTY_REGION_REDRAW_DEBUG
  if((l_ovglib_draw_sts != FALSE) || (hmi_gfx_mgr02_dar_get_num_drects() != 0))
  {
    GFX_MGR02_VISIBLE_AREA * fl_drect_SP;
    UINT32 fl_num_drects = hmi_gfx_mgr02_dar_get_num_drects();
    UINT32 fl_cur_index  = 0;
    VGubyte const path_cmd[]  = { VG_MOVE_TO_ABS,
      VG_HLINE_TO_REL,
      VG_VLINE_TO_REL,
      VG_HLINE_TO_REL,
      VG_CLOSE_PATH
    };
    VGshort path_data[5];
    VGPaint brush;
    VGPath  path;
    VGfloat fl_rgba[4] = {1.0f, 1.0f, 0.0f, 1.0f};
    static SINT32 dar_color = 0;

    if(dar_color == 0)
    {
      fl_rgba[0] = 1.0f;
      fl_rgba[1] = 1.0f;
      fl_rgba[2] = 0.0f;
      fl_rgba[3] = 1.0f;
      dar_color = 1;
    }
    else
    {
      fl_rgba[0] = 0.0f;
      fl_rgba[1] = 0.0f;
      fl_rgba[2] = 1.0f;
      fl_rgba[3] = 1.0f;
      dar_color=0;
    }

    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, brush=vgCreatePaint());
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE));
    vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetf, vgSetf(VG_STROKE_LINE_WIDTH,  2.0f));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE,   VG_BLEND_SRC_OVER));
    if(brush != VG_INVALID_HANDLE)
    {
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush, VG_STROKE_PATH));
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
    }
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_SCISSORING, VG_FALSE));

    while(fl_cur_index < fl_num_drects)
    {
      fl_drect_SP = hmi_gfx_mgr02_dar_get_drect(fl_cur_index);
      if(fl_drect_SP != 0)
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePath, path=vgCreatePath( VG_PATH_FORMAT_STANDARD, 
          VG_PATH_DATATYPE_S_16, 
          1.0f, 0.0f, 0, 0, 
          VG_PATH_CAPABILITY_ALL));

        path_data[0] = fl_drect_SP->sx;
        path_data[1] = fl_drect_SP->sy;
        path_data[2] = (fl_drect_SP->ex-fl_drect_SP->sx);
        path_data[3] = (fl_drect_SP->ey-fl_drect_SP->sy);
        path_data[4] = -(fl_drect_SP->ex-fl_drect_SP->sx);
        if(path != VG_INVALID_HANDLE)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(path, 5, path_cmd, path_data));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawPath, vgDrawPath(path, VG_STROKE_PATH));
          GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(path));
        }
      }
      fl_cur_index++;
    }
    vgFinish();
  }
#endif
#endif
  return((s_gx_flocal)l_ovglib_draw_sts);
}

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_set_clip
Description          : Sets the clip area to the passed one if it is new area
Invocation           : Invoked internally
Parameters           : Clip area via context pointer
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglib_set_clip(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
  VGint fl_cw = p_cntx_SP->state.clip.ex;
  VGint fl_ch = p_cntx_SP->state.clip.ey;

  fl_cw -= p_cntx_SP->state.clip.sx;
  fl_ch -= p_cntx_SP->state.clip.sy;

  if((l_ovglib_clip_rect[0] != p_cntx_SP->state.clip.sx) ||
    (l_ovglib_clip_rect[1] != p_cntx_SP->state.clip.sy) ||
    (l_ovglib_clip_rect[2] != fl_cw) ||
    (l_ovglib_clip_rect[3] != fl_ch))
  {
    VGint clip_rect[4];
    if((l_ovglib_draw_sts & GFX_MGR02_OVGLIB_FLUSH_PENDING) != 0)
    {
      l_ovglib_draw_sts &= (UINT8)(~GFX_MGR02_OVGLIB_FLUSH_PENDING);
      vgFinish();
    }
    clip_rect[0] = p_cntx_SP->state.clip.sx;
    clip_rect[1] = ((p_cntx_SP->rprop.fb_h-p_cntx_SP->state.clip.sy)-fl_ch);
    clip_rect[2] = fl_cw;
    clip_rect[3] = fl_ch;
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_SCISSORING, VG_TRUE));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetiv, vgSetiv(VG_SCISSOR_RECTS, 4, clip_rect));
    l_ovglib_clip_rect[0] = p_cntx_SP->state.clip.sx;
    l_ovglib_clip_rect[1] = p_cntx_SP->state.clip.sy;
    l_ovglib_clip_rect[2] = fl_cw;
    l_ovglib_clip_rect[3] = fl_ch;
  }
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
  GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
  VGImage fl_image_handle;

  if(p_cntx_SP->state.invisible == 0)
  {
#if defined(GFX_MGR02_USE_FILESYSTEM)
    fl_image_handle = hmi_gfx_mgr02_ovglib_cache_get_object(p_elem_def_SP, GFX_MGR02_BITMAP_TYPE_E,FALSE, 0);
#else
    fl_image_handle = hmi_gfx_mgr02_ovglib_cache_get_object(p_elem_def_SP, GFX_MGR02_BITMAP_TYPE_E,TRUE, 0);
#endif
    if(fl_image_handle != VG_INVALID_HANDLE)
    {
      VGfloat fl_rgba[4];
      VGPaint brush;
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
	if(p_cntx_SP->rprop.mask_mode != GFX_MGR02_MASK_WIDGET_NORMAL)
#endif
	{
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, brush=vgCreatePaint()); 
      if(brush != VG_INVALID_HANDLE)
      {
        if((p_elem_def_SP->format == VG_A_8) ||
          (p_elem_def_SP->format == VG_A_4) ||
          (p_elem_def_SP->format == VG_A_1))
        {
          fl_rgba[0] = GM2_GCFR(p_cntx_SP->rprop.fg_color);
          fl_rgba[1] = GM2_GCFG(p_cntx_SP->rprop.fg_color);
          fl_rgba[2] = GM2_GCFB(p_cntx_SP->rprop.fg_color);
          fl_rgba[3] = GM2_GCFA(p_cntx_SP->rprop.fg_color);
          if(p_cntx_SP->state.alpha < 255)
          {
            fl_rgba[3] *= ((VGfloat)p_cntx_SP->state.alpha);
            fl_rgba[3]  /= 255.0f;
          }
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,       VG_FILL_PATH));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE,   VG_DRAW_IMAGE_STENCIL));
        }
        else
        {
          fl_rgba[0] = 1.0f;
          fl_rgba[1] = 1.0f;
          fl_rgba[2] = 1.0f;
          if(p_cntx_SP->state.alpha < 255)
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE,   VG_DRAW_IMAGE_MULTIPLY));
            fl_rgba[3] = ((VGfloat)p_cntx_SP->state.alpha/255.0f);
          }
          else
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE, VG_DRAW_IMAGE_NORMAL));
            fl_rgba[3] = 1.0f;
          }
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,       VG_FILL_PATH));
        }
      }
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,  VG_MATRIX_FILL_PAINT_TO_USER));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,   VG_MATRIX_IMAGE_USER_TO_SURFACE));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
#if GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED != 0
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(p_cntx_SP->state.loc.x+p_elem_def_SP->width),(VGfloat)p_cntx_SP->state.loc.y));
#else
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x,(VGfloat)p_cntx_SP->state.loc.y));
#endif
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(-p_cntx_SP->rprop.pivot.x),(VGfloat)(-p_cntx_SP->rprop.pivot.y)));

      switch(p_elem_def_SP->format)
      {

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
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
        }
        break;
      default:
        {
          if(p_cntx_SP->state.alpha < 255)
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
          }
          else
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC));
          }
        }
        break;
      }
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawImage, vgDrawImage(fl_image_handle));
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));

#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
#ifndef FSL_CONST_IMAGES
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_image_handle));
#else
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_image_handle));
#endif
#endif
      l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
	}
#if (GFX_MGR02_NUM_MASK_WIDGETS > 0)
    else
    {
       if(p_cntx_SP->rprop.mask_mode == GFX_MGR02_MASK_WIDGET_NORMAL)
       {
    	   hmi_gfx_mgr02_ovglib_set_mask_mode(p_cntx_SP);
    	   GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMask, vgMask(fl_image_handle, VG_SET_MASK, p_cntx_SP->state.loc.x, ((p_cntx_SP->rprop.fb_h-p_cntx_SP->state.loc.y)-p_elem_def_SP->height) , p_elem_def_SP->width, p_elem_def_SP->height));   
       }
    }
#endif 
    }                   
#ifdef GFX02_DEBUG_OVG
    gfx_debug("ovglib - Image elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
      p_cntx_SP->state.loc.x,
      p_cntx_SP->state.loc.y,
      p_elem_def_SP->width,
      p_elem_def_SP->height);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - Image elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  return 0;
}
#if defined(GFX_MGR02_USE_FILESYSTEM)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_uimage(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
  GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
  VGImage fl_image_handle;

  if(p_cntx_SP->state.invisible == 0)
  {
    fl_image_handle = hmi_gfx_mgr02_ovglib_cache_get_object(p_elem_def_SP, GFX_MGR02_BITMAP_TYPE_E, TRUE, 0);
    if(fl_image_handle != VG_INVALID_HANDLE)
    {
      VGfloat fl_rgba[4];
      VGPaint brush;
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, brush=vgCreatePaint());
      if(brush != VG_INVALID_HANDLE)
      {
        if((p_elem_def_SP->format == VG_A_8) ||
          (p_elem_def_SP->format == VG_A_4) ||
          (p_elem_def_SP->format == VG_A_1))
        {
          fl_rgba[0] = GM2_GCFR(p_cntx_SP->rprop.fg_color);
          fl_rgba[1] = GM2_GCFG(p_cntx_SP->rprop.fg_color);
          fl_rgba[2] = GM2_GCFB(p_cntx_SP->rprop.fg_color);
          fl_rgba[3] = GM2_GCFA(p_cntx_SP->rprop.fg_color);
          if(p_cntx_SP->state.alpha < 255)
          {
            fl_rgba[3] *= ((VGfloat)p_cntx_SP->state.alpha);
            fl_rgba[3]  /= 255.0f;
          }
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,       VG_FILL_PATH));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE,   VG_DRAW_IMAGE_STENCIL));
        }
        else if(p_cntx_SP->state.alpha < 255)
        {
          fl_rgba[0] = 1.0f;
          fl_rgba[1] = 1.0f;
          fl_rgba[2] = 1.0f;
          fl_rgba[3] = ((VGfloat)p_cntx_SP->state.alpha/255.0f);
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,       VG_FILL_PATH));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE,   VG_DRAW_IMAGE_MULTIPLY));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,  VG_MATRIX_FILL_PAINT_TO_USER));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
        }
        else
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE, VG_DRAW_IMAGE_NORMAL));
        }
      }

      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,   VG_MATRIX_IMAGE_USER_TO_SURFACE));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
#if GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED != 0
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x+p_elem_def_SP->width,(VGfloat)p_cntx_SP->state.loc.y));
#else
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x,(VGfloat)p_cntx_SP->state.loc.y));
#endif
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(-p_cntx_SP->rprop.pivot.x),(VGfloat)(-p_cntx_SP->rprop.pivot.y)));

      switch(p_elem_def_SP->format)
      {

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
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
        }
        break;
      default:
        {
          if(p_cntx_SP->state.alpha < 255)
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
          }
          else
          {
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC));
          }
        }
        break;
      }
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawImage, vgDrawImage(fl_image_handle));
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));

#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
#ifndef FSL_CONST_IMAGES
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_image_handle));
#else
      GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_image_handle));
#endif
#endif
      l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
    }                   
#ifdef GFX02_DEBUG_OVG
    gfx_debug("ovglib - Image elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
      p_cntx_SP->state.loc.x,
      p_cntx_SP->state.loc.y,
      p_elem_def_SP->width,
      p_elem_def_SP->height);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - Image elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  return 0;
}
#endif
#if !defined(GFX_MGR02_RENESAS_OPENVG_LIB) && defined(GFX_MGR02_FARADAY) && !defined(GFX_MGR02_KEPLER) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_pre_copy_fb
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_pre_copy_fb(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
  GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)

{
#if defined(FSL_CONST_IMAGES)
  VGImage fl_image_handle;

  u_gx_flocal fl_stride;

  fl_stride = hmi_gfx_mgr02_ovglib_get_stride(VG_sARGB_8888,   p_elem_def_SP->width);

  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateConstImageFSL, fl_image_handle=vgCreateConstImageFSL(VG_sARGB_8888,
    p_elem_def_SP->pixel_data,
    fl_stride,
    p_elem_def_SP->width,
    p_elem_def_SP->height,
    GFX_MGR02_VG_IMAGE_QUALITY_CONFIG,
    VG_FALSE));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE, VG_DRAW_IMAGE_NORMAL));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,  VG_MATRIX_FILL_PAINT_TO_USER));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,   VG_MATRIX_IMAGE_USER_TO_SURFACE));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetivgSeti, (VG_SCISSORING, VG_FALSE));
  if(fl_image_handle != VG_INVALID_HANDLE)
  {
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawImage, vgDrawImage(fl_image_handle));
    GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_image_handle));
  }
  l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
#else
  u_gx_flocal  fl_stride;

  fl_stride =  hmi_gfx_mgr02_ovglib_get_stride(VG_sARGB_8888,   p_elem_def_SP->width);

  /*hmi_gfx_mgr02_driver_mqx_request_dma_trasnfer(p_cntx_SP->rprop.fb_P,p_elem_def_SP->pixel_data,fl_stride*p_elem_def_SP->height);*/
  memcpy(p_cntx_SP->rprop.fb_P,p_elem_def_SP->pixel_data,fl_stride*p_elem_def_SP->height);
#endif
  return 0;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_clear_buffer
Description          : Clears the framebuffer with passed color
Invocation           : Invoked internally
Parameters           : fill color
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color)
{
  VGfloat fl_rgba[4];
  fl_rgba[0] = GM2_GCFR(p_clear_color);
  fl_rgba[1] = GM2_GCFG(p_clear_color);
  fl_rgba[2] = GM2_GCFB(p_clear_color);
  fl_rgba[3] = GM2_GCFA(p_clear_color);
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetfv, vgSetfv( VG_CLEAR_COLOR, 4, fl_rgba));
  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgClear, vgClear( 0, 0, p_cntx_SP->rprop.fb_w, p_cntx_SP->rprop.fb_h));
  return(0);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_fill
Description          : Builds a fill object
Invocation           : Invoked internally
Parameters           : element definition and dimention of fill area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
  GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, 
  GFX_MGR02_IDIM_DATA  const * p_dim)
{
  if(p_cntx_SP->state.invisible == 0)
  {
    VGfloat fl_rgba[4];
    fl_rgba[0] = GM2_GCFR(p_cntx_SP->rprop.fg_color);
    fl_rgba[1] = GM2_GCFG(p_cntx_SP->rprop.fg_color);
    fl_rgba[2] = GM2_GCFB(p_cntx_SP->rprop.fg_color);
    fl_rgba[3] = GM2_GCFA(p_cntx_SP->rprop.fg_color);

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif

#if defined(GFX_MGR02_OVG_USE_VG_CLEAR) && !defined(GFX_MGR02_DIRTY_REGION_REDRAW)
    if((p_cntx_SP->state.loc.x <= 0) && (p_cntx_SP->state.loc.y <= 0) &&
      (p_dim->width  >= p_cntx_SP->rprop.fb_w) &&
      (p_dim->height >= p_cntx_SP->rprop.fb_h)   )
    {
      /*
      ** If the fill area equals the frame buffer width and height then
      ** use vg clear api. limitation is that we can't apply any
      ** transformations.
      */
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetfv, vgSetfv( VG_CLEAR_COLOR, 4, fl_rgba));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgClear, vgClear( 0, 0, p_cntx_SP->rprop.fb_w, p_cntx_SP->rprop.fb_h));
      l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
    }
    else
#endif
#if defined(GFX_MGR02_OVG_USE_VG_CLEAR) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
      if(fl_rgba[3] == 0)
      {
        /*
        ** If the fill color alpha is zero, treat this as a special case for clearing
        ** the buffer. it is OK since normally an application will not use a fill with
        ** alpha = 0 as it will have no effect
        ** limitation  :no transformations applied here
        */
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetfv, vgSetfv( VG_CLEAR_COLOR, 4, fl_rgba));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgClear, vgClear(p_cntx_SP->state.loc.x, 
          (p_cntx_SP->rprop.fb_h-(p_cntx_SP->state.loc.y+p_dim->height)), 
          p_dim->width, 
          p_dim->height));
        l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
      }
      else
#endif
      {
        if(p_cntx_SP->state.alpha < 255)
        {
          fl_rgba[3] *= ((VGfloat)p_cntx_SP->state.alpha);
          fl_rgba[3]   /= 255.0f;
        }

        if(fl_rgba[3] > 0.0f)
        {
          VGubyte const path_cmd[]  = { VG_MOVE_TO_ABS,
            VG_HLINE_TO_REL,
            VG_VLINE_TO_REL,
            VG_HLINE_TO_REL,
            VG_CLOSE_PATH
          };
          VGshort path_data[5];
          /*
          ** If the fill area is smaller then create rectangular path
          ** and then fill the path area.
          */
          VGPaint brush;
          VGPath  path;
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, brush=vgCreatePaint());
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePath, path=vgCreatePath( VG_PATH_FORMAT_STANDARD, 
            VG_PATH_DATATYPE_S_16, 
            1.0f, 0.0f, 0, 0, 
            VG_PATH_CAPABILITY_ALL));
          if((brush != VG_INVALID_HANDLE) && (path != VG_INVALID_HANDLE))
          {
            path_data[0] = 0;
            path_data[1] = 0;
            path_data[2] = (VGshort)p_dim->width;
            path_data[3] = (VGshort)p_dim->height;
            path_data[4] = (-(VGshort)p_dim->width);

            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(path, 5, path_cmd, path_data));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE));

            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
#if GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED != 0
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(p_cntx_SP->state.loc.x+p_dim->width),(VGfloat)p_cntx_SP->state.loc.y));
#else
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x,(VGfloat)p_cntx_SP->state.loc.y));
#endif
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate(-((VGfloat)p_cntx_SP->rprop.pivot.x),-((VGfloat)p_cntx_SP->rprop.pivot.y)));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE,   VG_BLEND_SRC_OVER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(brush, VG_PAINT_COLOR, 4, fl_rgba));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush, VG_FILL_PATH));

            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawPath, vgDrawPath(path, VG_FILL_PATH));
            l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(path));
            GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
          }
        }
      }
#ifdef GFX02_DEBUG_OVG
      gfx_debug("ovglib - Fill elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
        p_cntx_SP->state.loc.x,
        p_cntx_SP->state.loc.y,
        p_dim->width,
        p_dim->height);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - Fill elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  GFX_MGR02_UNUSED_PTR(p_elem_def_SP);
  return 0;
}
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_tile
Description          : Builds a tile object
Invocation           : Invoked internally
Parameters           : element definition and dimention of tile area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_tile(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
  GFX_MGR02_TILE_DEF_T const * p_elem_def_SP, 
  GFX_MGR02_IDIM_DATA  const * p_dim)
{
  if(p_cntx_SP->state.invisible == 0)
  {
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
    VGImage fl_image_handle;
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
    GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP = hmi_gfx_mgr02_get_image_layer_def_ptr(p_elem_def_SP->id);
#else
    GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP = &lc_image_layer_def_S[p_elem_def_SP->id];
#endif
#if defined(GFX_MGR02_USE_FILESYSTEM)
    fl_image_handle = hmi_gfx_mgr02_ovglib_cache_get_object(fl_element_def_SP, GFX_MGR02_BITMAP_TYPE_E, FALSE, 0);
#else
    fl_image_handle = hmi_gfx_mgr02_ovglib_cache_get_object(fl_element_def_SP, GFX_MGR02_BITMAP_TYPE_E, TRUE, 0);
#endif

    if(fl_image_handle != VG_INVALID_HANDLE)
    {
      VGPaint brush;
      VGPath  path;
      VGubyte const path_cmd[]  = { VG_MOVE_TO_ABS,
        VG_HLINE_TO_REL,
        VG_VLINE_TO_REL,
        VG_HLINE_TO_REL,
        VG_CLOSE_PATH
      };
      VGshort path_data[5];

      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, brush=vgCreatePaint());
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePath, path=vgCreatePath(VG_PATH_FORMAT_STANDARD,
        VG_PATH_DATATYPE_S_16,
        1.0f, 0.0f, 0, 0,
        VG_PATH_CAPABILITY_ALL));

      if((brush != VG_INVALID_HANDLE) && (path != VG_INVALID_HANDLE))
      {
        path_data[0] = 0;
        path_data[1] = 0;
        path_data[2] = (VGshort)p_dim->width;
        path_data[3] = (VGshort)p_dim->height;
        path_data[4] = -((VGshort)p_dim->width);
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(path, 5, path_cmd, path_data));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush, VG_PAINT_TYPE, VG_PAINT_TYPE_PATTERN));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgPaintPattern, vgPaintPattern(brush, fl_image_handle));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(brush, VG_PAINT_PATTERN_TILING_MODE, VG_TILE_REPEAT));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush, VG_FILL_PATH));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC));

        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
#if GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED != 0
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(p_cntx_SP->state.loc.x+p_dim->width),(VGfloat)p_cntx_SP->state.loc.y));
#else
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x,(VGfloat)p_cntx_SP->state.loc.y));
#endif
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate(-p_cntx_SP->rprop.pivot.x,-p_cntx_SP->rprop.pivot.y));

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
        hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawPath, vgDrawPath(path, VG_FILL_PATH));
        l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
#ifndef FSL_CONST_IMAGES
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_image_handle));
#else
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_image_handle));
#endif
#endif
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(path));
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
      }
    }
#endif
#ifdef GFX02_DEBUG_OVG
    gfx_debug("ovglib - Fill elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
      p_cntx_SP->state.loc.x,
      p_cntx_SP->state.loc.y,
      p_dim->width,
      p_dim->height);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - Tile elem =%08X skipped\n", p_elem_def_SP);
  }
#endif

  GFX_MGR02_UNUSED_PTR(p_cntx_SP);
  GFX_MGR02_UNUSED_PTR(p_elem_def_SP);
  GFX_MGR02_UNUSED_PTR(p_dim);

  return 0;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_text
Description          : Builds a text object
Invocation           : Invoked internally
Parameters           : element definition and pointer to string
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
  GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
  HMI_CHAR             const * p_string,
  u_gx_flocal                  p_text_actual_width
#if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
  ,u_gx_flocal                 p_is_multi_line_text
#endif
  )
{
  GFX_MGR02_FONT const * fl_font_SP;
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
  GFX_MGR02_OGLIB_DYN_TEX_ID fl_dtex_code;
#endif
  UINT32                 fl_str_length;
  HMI_CHAR       const * fl_string_ptr;
  HMI_CHAR       const * fl_print_str;
  UINT32                 fl_text_width;
  UINT32 fl_font_index = hmi_gfx_mgr02_get_font_id(p_cntx_SP->rprop.font_id);

  if(p_cntx_SP->state.invisible == 0)
  {
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_index);

    if(fl_font_SP != GFX_MGR02_NULL_PTR)
    {
      {
        GFX_MGR02_TEXT_INFO fl_text_info_S;
        fl_text_info_S.print_str_P = p_string;
        if(p_text_actual_width != 0)
        {
          fl_text_info_S.max_available_width = (UINT16)p_text_actual_width;
        }
        else
        {
          fl_text_info_S.max_available_width = p_cntx_SP->rprop.text_width;
        }
        fl_text_info_S.target = GFX_MGR02_TARGET_OPENVG;
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
        if(fl_font_SP->is_ffile != 0)
        {
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          GFX_FLOAT font_height_pts_temp = fl_font_SP->height_pts*65536.0f;
          /* Set this font as the font to be used.                                */
          FS_set_font((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, (FILECHAR *)p_cntx_SP->rprop.mt_font_name[fl_font_index]);
          /* Set the scale, we are assuming that xppem == yppem and no rotation   */
          /* or skewing. Note: ppem<<16 converts the specified ppem value into a  */
          /* 16.16 fixed point value.                                             */
          FS_set_scale((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, (FS_LONG)(font_height_pts_temp), 0, 0, (FS_LONG)(font_height_pts_temp));
          /* Set the character mapping, here we expect that the font being used   */
          /* will have a Unicode cmap table as indicated by the 3,1 arguments.    */
          FS_set_cmap((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, 3,1);

#endif
        }
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
#if defined(GFX_MGR02_OPEN_VG) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
        if(p_is_multi_line_text != FALSE)
        {
          fl_text_info_S.append_str = FALSE;
        }
        else
#endif
        {
          fl_text_info_S.append_str = TRUE;
        }
        l_ovglib_clip_text_str[0] = 0;
#else
        fl_text_info_S.append_str = FALSE;
#endif
        fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
        #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
        fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
        #endif
        (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
          (UINT32)p_cntx_SP->rprop.font_id,
          p_cntx_SP->rprop.clip_mode,
          p_cntx_SP->rprop.alignment
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          ,l_ovglib_clip_text_str
#endif
          );

        fl_text_width = fl_text_info_S.print_width;
        fl_str_length = fl_text_info_S.print_length_U8;
        fl_print_str  = fl_text_info_S.print_str_P;
        fl_string_ptr = fl_print_str;
      }
    }
    else
    {
      fl_text_width = 0;
    }
    if(fl_text_width > 0)
    {
      GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
      VGPaint          fl_txt_paint;
      VGuint           fl_fg_color;
      VGfloat          fl_draw_color[4];
      VGfloat          fl_origin[2];
      VGfloat          fl_escapement[2];
      VGImage          fl_font_img;
      SINT32           fl_start_x;
      VGFont           fl_vg_font;
      SINT32           fl_pivot_offset;

      fl_fg_color      = p_cntx_SP->rprop.fg_color;
      fl_draw_color[3] = (VGfloat)(UINT8)(fl_fg_color >> 24); /* A */
      fl_draw_color[0] = (VGfloat)(UINT8)(fl_fg_color >> 16); /* R */
      fl_draw_color[1] = (VGfloat)(UINT8)(fl_fg_color >> 8);  /* G */
      fl_draw_color[2] = (VGfloat)(UINT8)(fl_fg_color);       /* B */

      if(p_cntx_SP->state.alpha < 255)
      {
        fl_draw_color[3] *= (VGfloat)p_cntx_SP->state.alpha;
        fl_draw_color[3] /= 255.0f;
      }

      fl_draw_color[3] /= 255.0f;
      fl_draw_color[2] /= 255.0f;
      fl_draw_color[1] /= 255.0f;
      fl_draw_color[0] /= 255.0f;

      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePaint, fl_txt_paint=vgCreatePaint());
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_IMAGE_MODE, VG_DRAW_IMAGE_STENCIL));
      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
      if(fl_txt_paint != VG_INVALID_HANDLE)
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameteri, vgSetParameteri(fl_txt_paint,  VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetParameterfv, vgSetParameterfv(fl_txt_paint, VG_PAINT_COLOR, 4, fl_draw_color));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(fl_txt_paint, VG_FILL_PATH|VG_STROKE_PATH));
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(fl_txt_paint));
      }

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif

      if(fl_text_width > p_cntx_SP->rprop.text_width)
      {
        fl_text_width = p_cntx_SP->rprop.text_width;
      }
      if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_RIGHT)) != 0)
      {
        fl_pivot_offset = (p_cntx_SP->rprop.text_width - fl_text_width);
        /* The alignment is changed during runtime as right aligned text 
        fl_start_x = (fl_text_width - 1) is done below considering that its a right aligned
        text.  But only for right aligned text generated from the tool, the below calculation 
        is required. Eg: x = 100; textwidth = 100. since tool generates start x for right aligned pixel as
        199.  But for left aligned text start x = 100. So (fl_text_width - 1) is not required */
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          fl_start_x      = (SINT32)(fl_text_width - 1);
        }
        else
        {
          fl_start_x      = (SINT32)(fl_text_width);
        }
      }
      else if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_CENTRE)) != 0)
      {
        fl_start_x      = (SINT32)(fl_text_width >> 1);
        fl_pivot_offset = ((p_cntx_SP->rprop.text_width - fl_text_width)/2);
      }
      else
      {
        fl_start_x      = 0;
        fl_pivot_offset = 0;
      }
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
      if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_CENTRE)
      {
        /* 
        ** handle case where the current alignment is different than default alignment 
        */
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
        {
          fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width>>1);
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          fl_start_x += (SINT16)(p_cntx_SP->rprop.text_width >> 1);
          /* Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text. */
          /* So it needs to be considered here */
          fl_start_x -= 1;
        }
        else
        {
        	/*For MISRA warning fix.*/
        }
      }
      else if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT)
      {
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
        {
          fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width);
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
        {
          fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width >> 1);
        }
        else
        {
        	/*For MISRA warning fix.*/
        }
      }
      else
      {
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
        {
          fl_start_x += (SINT16)(p_cntx_SP->rprop.text_width>>1);
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          fl_start_x += p_cntx_SP->rprop.text_width;
          /*  Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text.So it needs to be considered here  */
          fl_start_x -= 1; 
        }
        else
        {
        	/*For MISRA warning fix.*/
        }
      }
#endif

#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1))
      fl_start_x = ((p_cntx_SP->state.loc.y-(SINT16)fl_start_x)-fl_pivot_offset);
#else
      fl_start_x = ((p_cntx_SP->state.loc.x-(SINT16)fl_start_x)-fl_pivot_offset);
#endif

#if ((GFX_MGR02_PRECREATE_FONTS & FONTS_SVG) != 0)
      if(fl_font_SP->is_vfont != 0)
      {
        UINT32 fl_font_id = (fl_font_SP-&lc_gfx_font_table[0]);

        if(fl_font_id < GFX_MGR02_NUM_OF_FONTS)
        {
          fl_vg_font = l_vg_font[fl_font_id];
        }
        else
        {
          fl_vg_font = VG_INVALID_HANDLE;
        }
      }
      else
#endif
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateFont, fl_vg_font=vgCreateFont(1));
      }
      if(fl_vg_font != VG_INVALID_HANDLE)
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE,   VG_MATRIX_GLYPH_USER_TO_SURFACE));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));

#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1))
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x-(fl_font_SP->p.height+fl_font_SP->p.height), (VGfloat)fl_start_x));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(p_cntx_SP->rprop.pivot.x),(VGfloat)fl_pivot_offset-p_cntx_SP->rprop.pivot.y));
#else
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)fl_start_x, (VGfloat)p_cntx_SP->state.loc.y));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)(fl_pivot_offset-p_cntx_SP->rprop.pivot.x),(VGfloat)-p_cntx_SP->rprop.pivot.y));
#endif
#if GFX_MGR02_OVG_FONT_PRESENT > 0
        if(fl_font_SP->is_vfont != 0)
        {
          GFX_FLOAT fl_scale = (GFX_FLOAT)fl_font_SP->f.ovg_ptr->ptsize/(GFX_FLOAT)(fl_font_SP->f.ovg_ptr->bmsize);
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgScale, vgScale(fl_scale, fl_scale));
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate(0, (GFX_FLOAT)fl_font_SP->f.ovg_ptr->acent));
        }
#endif
        fl_origin[0]  = 0;
        fl_origin[1]  = 0;
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetfv, vgSetfv(VG_GLYPH_ORIGIN, 2, fl_origin));
#if GFX_MGR02_OVG_FONT_PRESENT > 0
        if(fl_font_SP->is_vfont != 0)
        {
#if ((GFX_MGR02_PRECREATE_FONTS & FONTS_SVG) == 0)
          GFX_MGR02_OVG_GLYPH_DEF_T const * fl_vg_glyph_SP;
          VGPath vgpath;
          while(fl_str_length > 0)
          {
            fl_str_length--;
            fl_vg_glyph_SP = (GFX_MGR02_OVG_GLYPH_DEF_T const *)hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.ovg_ptr->lut_ptr, fl_font_SP->size_table, 
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
              (UINT32)p_cntx_SP->rprop.font_id,
#endif
              TRUE);
            if(fl_vg_glyph_SP->num_p_segs != 0)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreatePath, vgpath=vgCreatePath(VG_PATH_FORMAT_STANDARD, 
                VG_PATH_DATATYPE_S_16, 
                1.0f, 
                0.0f, 
                0, 
                0, 
                VG_PATH_CAPABILITY_ALL));
              if(vgpath != VG_INVALID_HANDLE)
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgAppendPathData, vgAppendPathData(vgpath, 
                  fl_vg_glyph_SP->num_p_segs, 
                  fl_vg_glyph_SP->path_segments_u8p, 
                  fl_vg_glyph_SP->path_data_s16p));
              }
            }
            fl_origin[0]     = 0.0f;
            fl_origin[1]     = 0.0f;
            fl_escapement[0] = (GFX_FLOAT)fl_vg_glyph_SP->x_advance;
            fl_escapement[1] = 0.0f;
            if(vgpath != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToPath, vgSetGlyphToPath(fl_vg_font, fl_string_ptr[0], vgpath, VG_FALSE, fl_origin, fl_escapement));
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawGlyph, vgDrawGlyph(fl_vg_font, fl_string_ptr[0], VG_FILL_PATH, VG_FALSE));
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(vgpath));
            }
            fl_string_ptr++;
          }
#endif
        }
        else
#endif
        {
          SINT32 fl_str_index = (SINT32)0;
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          FS_FIXED fl_asc;
          FS_FIXED fl_dsc;
          FS_FIXED fl_led;
          FsAscDescLeadSource fl_src;
          (void)FS_get_ascender_descender_leading((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, &fl_asc, &fl_dsc, &fl_led, &fl_src);
          fl_asc >>= 16;
#endif
#endif
          while(fl_str_length > 0)
          {
            fl_str_length--;
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
            if(fl_font_SP->is_ffile != 0)
            {
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
              FS_GLYPHMAP const * fl_vg_glyph_SP;
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
              GFX_MGR02_TEXTURE * fl_textture;
              fl_dtex_code.b.dyn_data = 1;
              fl_dtex_code.b.obj_id   = fl_font_index;
              fl_dtex_code.b.obj_code = fl_string_ptr[0];
              fl_textture             = hmi_gfx_mgr02_get_char_cache_ptr(fl_dtex_code.id);
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
              if((fl_textture->id != fl_dtex_code.id) || (GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U))
#else
              if(fl_textture->id != fl_dtex_code.id)
#endif 
#endif
              {
                if(FS_map_char((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state,	fl_string_ptr[0]) != 0)
                {
                  fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[0],FS_MAP_GRAYMAP8);
                }
                else
                {
                  /* render defalt character configured in hmi_gfx_mgr02.cfg*/
                  fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR,FS_MAP_GRAYMAP8);
                }
                if(fl_vg_glyph_SP != GFX_MGR02_NULL_PTR)
                {
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1))
                  if(fl_vg_glyph_SP->bits != 0)
                  {
                    fl_origin[1]     = (VGfloat)fl_vg_glyph_SP->lo_x;
                    fl_origin[0]     = (VGfloat)(fl_asc - fl_vg_glyph_SP->hi_y);
                    fl_escapement[1] = (VGfloat)fl_vg_glyph_SP->i_dx;
                    fl_escapement[0] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, (VGint)fl_vg_glyph_SP->height, 
                      (VGint)fl_vg_glyph_SP->width, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                    if(fl_font_img != VG_INVALID_HANDLE)
                    {
                      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_font_img,
                        fl_vg_glyph_SP->bits,
                        (fl_vg_glyph_SP->height+1)>>1,
                        VG_A_4,
                        0,
                        0,
                        (VGint)fl_vg_glyph_SP->height,
                        (VGint)fl_vg_glyph_SP->width));
                    }

                  }
                  else
                  {
                    fl_origin[0]     = 0.0f;
                    fl_origin[1]     = 0.0f;
                    fl_escapement[1] = (VGfloat)fl_vg_glyph_SP->i_dx;
                    fl_escapement[0] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, 1, 1, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                  }
#else
                  if(fl_vg_glyph_SP->height != 0)
                  {
                    GFX_MGR02_GPOS_DELTA fl_delta_pixels = {0.0, 0.0};

#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
                    /* If input string contains any arabic zero width characters
                    * then handle these characters specially.
                    */
                    if(GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U)
                    {
                      (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, fl_font_index,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
                    }
#endif /* #if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED) */
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
                    /* If input string contains any thai zero width characters
                    * then handle these characters specially.
                    */
                    if(GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U)
                    {
                      (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (fl_string_ptr-1), fl_str_index, fl_font_index,p_cntx_SP,GFX_MGR02_LANG_READ_DIR_RTL);
                    }
#endif /* #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED) */
                    fl_origin[0]     = -((VGfloat)(fl_vg_glyph_SP->lo_x+fl_delta_pixels.gpos_delta_pixels_x));
                    fl_origin[1]     = -(VGfloat)(fl_asc - fl_vg_glyph_SP->hi_y + fl_font_SP->baseline_offset - fl_delta_pixels.gpos_delta_pixels_y);
                    fl_escapement[0] = (VGfloat)fl_vg_glyph_SP->i_dx;
                    fl_escapement[1] = 0.0f;
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
                    if(fl_textture->id != fl_dtex_code.id)
#endif
#endif
                    {
                      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_8, (VGint)fl_vg_glyph_SP->width, 
                        (VGint)fl_vg_glyph_SP->height, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                      if(fl_font_img != VG_INVALID_HANDLE)
                      {
                        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_font_img,
                          fl_vg_glyph_SP->bits,
                          (fl_vg_glyph_SP->width),
                          VG_A_8,
                          0,
                          0,
                          (VGint)fl_vg_glyph_SP->width,
                          (VGint)fl_vg_glyph_SP->height));
                      }
                    }
                  }
                  else
                  {
                    fl_origin[0]     = 0.0f;
                    fl_origin[1]     = 0.0f;
                    fl_escapement[0] = (VGfloat)fl_vg_glyph_SP->i_dx;
                    fl_escapement[1] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_8, 1, 1, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                  }
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
                  if(fl_textture->id != fl_dtex_code.id)
#endif
                  {
                    if(fl_font_img != VG_INVALID_HANDLE)
                    {
                      fl_textture->id            = fl_dtex_code.id;
                      fl_textture->font_id       = fl_font_index;
                      fl_textture->imageid       = fl_font_img;
                      fl_textture->origin[0]     = fl_origin[0];
                      fl_textture->origin[1]     = fl_origin[1];
                      fl_textture->escapement[0] = fl_escapement[0];
                      fl_textture->escapement[1] = fl_escapement[1];
                      fl_textture->data          = (void *)fl_vg_glyph_SP->bits;
                      fl_textture->live          = (GFX_MGR02_MAX_CACHE_LIVE+1);
                    }
                  }
#endif
#endif
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
                  if((fl_textture->id == fl_dtex_code.id) && (GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U))
                  {
                    fl_font_img = fl_textture->imageid;
                    /* character already available in cache */
                    fl_textture->live = (GFX_MGR02_MAX_CACHE_LIVE+1);
                  }
#endif
#endif
                  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToImage, vgSetGlyphToImage(fl_vg_font, fl_string_ptr[0], fl_font_img, fl_origin, fl_escapement));
                  GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawGlyph, vgDrawGlyph(fl_vg_font, fl_string_ptr[0], VG_FILL_PATH, VG_FALSE));
#ifndef GFX_MGR02_VG_TXT_CACHE_ENABLED
#ifndef FSL_CONST_IMAGES
                  GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_font_img));
#else
                  GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_font_img));
#endif
#endif
                  (void)FS_free_char((FS_STATE *)&p_cntx_SP->rprop.mt_fs_state, (FS_VOID *)fl_vg_glyph_SP);
                }
#endif /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)*/
              }	/* if(fl_textture->id != fl_dtex_code.id)*/
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
              else
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToImage, vgSetGlyphToImage(fl_vg_font, fl_string_ptr[0], fl_textture->imageid,
                  fl_textture->origin, fl_textture->escapement));
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawGlyph, vgDrawGlyph(fl_vg_font, fl_string_ptr[0], VG_FILL_PATH, VG_FALSE));
                /* character already available in cache */
                fl_textture->live = (GFX_MGR02_MAX_CACHE_LIVE+1); 
              }
#endif
            }
            else
#endif /*#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE */
            {

#if defined (GFX_MGR02_VG_TXT_CACHE_ENABLED)
              GFX_MGR02_TEXTURE * fl_textture;
              fl_dtex_code.b.dyn_data = 1;
              fl_dtex_code.b.obj_id   = fl_font_index;
              fl_dtex_code.b.obj_code = fl_string_ptr[0];
              fl_textture             = hmi_gfx_mgr02_get_char_cache_ptr(fl_dtex_code.id);
              if(fl_textture->id != fl_dtex_code.id)
#endif
              {
                fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                  (UINT32)p_cntx_SP->rprop.font_id,
#endif
                  FALSE);

                if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
                {
#if ((GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 1) && (GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED == 1))
                  if(fl_font_fcc_SP->fdata != 0)
                  {
                    fl_origin[1]     = -((VGfloat)fl_font_fcc_SP->x_soffset);
                    fl_origin[0]     = -((VGfloat)fl_font_fcc_SP->y_soffset);
                    fl_escapement[1] = (VGfloat)fl_font_fcc_SP->owidth;
                    fl_escapement[0] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, (VGint)fl_font_fcc_SP->height, 
                      (VGint)fl_font_fcc_SP->width, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                    if(fl_font_img != VG_INVALID_HANDLE)
                    {
                      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_font_img,
                        fl_font_fcc_SP->fdata,
                        (fl_font_fcc_SP->height+1)>>1,
                        VG_A_4,
                        0,
                        0,
                        (VGint)fl_font_fcc_SP->height,
                        (VGint)fl_font_fcc_SP->width));
                    }
                  }
                  else
                  {
                    fl_origin[0]     = 0.0f;
                    fl_origin[1]     = 0.0f;
                    fl_escapement[1] = (VGfloat)fl_font_fcc_SP->owidth;
                    fl_escapement[0] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, 1, 1, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                  }
#else
                  if(fl_font_fcc_SP->fdata != (UINT8 *)0)
                  {
                    fl_origin[0]     = -((VGfloat)fl_font_fcc_SP->x_soffset);
                    fl_origin[1]     = -((VGfloat)fl_font_fcc_SP->y_soffset);
                    fl_escapement[0] = (VGfloat)fl_font_fcc_SP->owidth;
                    fl_escapement[1] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, (VGint)fl_font_fcc_SP->width, 
                      (VGint)fl_font_fcc_SP->height, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                    if(fl_font_img != VG_INVALID_HANDLE)
                    {
                      GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgImageSubData, vgImageSubData(fl_font_img,
                        fl_font_fcc_SP->fdata,
                        (fl_font_fcc_SP->width+1)>>1,
                        VG_A_4,
                        0,
                        0,
                        (VGint)fl_font_fcc_SP->width,
                        (VGint)fl_font_fcc_SP->height));
                    }
                  }
                  else
                  {
                    fl_origin[0]     = 0.0f;
                    fl_origin[1]     = 0.0f;
                    fl_escapement[0] = (VGfloat)fl_font_fcc_SP->owidth;
                    fl_escapement[1] = 0.0f;
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgCreateImage, fl_font_img=vgCreateImage(VG_A_4, 1, 1, GFX_MGR02_VG_IMAGE_QUALITY_CONFIG));
                  }
#endif
                  if(fl_font_img != VG_INVALID_HANDLE)
                  {
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToImage, vgSetGlyphToImage(fl_vg_font, fl_string_ptr[0], fl_font_img, fl_origin, fl_escapement));
                    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawGlyph, vgDrawGlyph(fl_vg_font, fl_string_ptr[0], VG_FILL_PATH, VG_FALSE));
#ifndef GFX_MGR02_VG_TXT_CACHE_ENABLED
#ifndef FSL_CONST_IMAGES
                    GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyImage, vgDestroyImage(fl_font_img));
#else
                    GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyConstImageFSL, vgDestroyConstImageFSL(fl_font_img));
#endif
#endif
                  }
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
                  if(fl_font_img != VG_INVALID_HANDLE)
                  { 
                    fl_textture->id            = fl_dtex_code.id;
                    fl_textture->font_id       = fl_font_index;
                    fl_textture->imageid       = fl_font_img;
                    fl_textture->origin[0]     = fl_origin[0];
                    fl_textture->origin[1]     = fl_origin[1];
                    fl_textture->escapement[0] = fl_escapement[0];
                    fl_textture->escapement[1] = fl_escapement[1];
                    fl_textture->data          = (void *)fl_font_fcc_SP->fdata;
                    fl_textture->live          = (GFX_MGR02_MAX_CACHE_LIVE+1);
                  }
#endif
                }
              }
#if defined(GFX_MGR02_VG_TXT_CACHE_ENABLED)
              else
              {
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetGlyphToImage, vgSetGlyphToImage(fl_vg_font, fl_string_ptr[0], fl_textture->imageid,
                  fl_textture->origin, fl_textture->escapement));
                GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawGlyph, vgDrawGlyph(fl_vg_font, fl_string_ptr[0], VG_FILL_PATH, VG_FALSE));
                /* character already available in cache */
                fl_textture->live = (GFX_MGR02_MAX_CACHE_LIVE+1); 
              }
#endif
            }
            fl_string_ptr++;
            fl_str_index++;
          }
        }
#ifdef GFX02_DEBUG_OVG
#if GFX_MGR02_UNICODE != 0    
        wprintf(L"ovglib - Text %s printed\n", fl_string_ptr);
#else
        printf(L"ovglib - Text %s printed\n", fl_string_ptr);
#endif
#endif
#if GFX_MGR02_OVG_FONT_PRESENT > 0
        if(fl_font_SP->is_vfont != 0)
        {
#if ((GFX_MGR02_PRECREATE_FONTS & FONTS_SVG) == 0)
          GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyFont, vgDestroyFont(fl_vg_font));
#endif
        }
        else
#endif
        {
          GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyFont, vgDestroyFont(fl_vg_font));
        }
      }
      l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
    }
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - Text elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_build_svg
Description          : Builds a vector graphics object
Invocation           : Invoked internally
Parameters           : element definition.
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_build_svg(GFX_MGR02_CONTEXT_T    const * p_cntx_SP, 
  GFX_MGR02_OVG_OBJECT_T const * p_elem_def_SP)
{
  GFX_MGR02_OVG_PATH_DEF_T const * fl_cur_path_sp;
  void const * fl_last_fpaint = (void const *)0;
  void const * fl_last_spaint = (void const *)0;
  VGbitfield fl_paintModes;
  UINT32     fl_path_count_U32;
  VGPath     fl_vgpath;

  if(p_cntx_SP->state.invisible == 0)
  {
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_ovglib_set_clip(p_cntx_SP);
#endif

    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadMatrix, vgLoadMatrix(GFX_MGR02_GET_INIT_MATRIX(p_cntx_SP->rprop.layer_id)));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate((VGfloat)p_cntx_SP->state.loc.x,(VGfloat)p_cntx_SP->state.loc.y));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(p_cntx_SP->state.matrix));
    GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgTranslate, vgTranslate(-((VGfloat)p_cntx_SP->rprop.pivot.x),-((VGfloat)p_cntx_SP->rprop.pivot.y)));

    fl_cur_path_sp    = p_elem_def_SP->path_array_sap;
    fl_path_count_U32 = p_elem_def_SP->num_paths;

    while(fl_path_count_U32 > 0)
    {
      fl_paintModes = 0;

      fl_vgpath = (VGPath)hmi_gfx_mgr02_ovglib_cache_get_object(fl_cur_path_sp, GFX_MGR02_VECTOR_TYPE_E, TRUE, 0);

      if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_BLEND_ENABLED) == GFX_MGR02_PATH_PROP_BLEND_ENABLED)
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC_OVER));
      }
      else
      {
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_BLEND_MODE, VG_BLEND_SRC));
      }

      if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_ENABLED) == GFX_MGR02_PATH_PROP_FILL_ENABLED)
      {
        if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_RULE_EVENODD) == GFX_MGR02_PATH_PROP_FILL_RULE_EVENODD)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_FILL_RULE, VG_EVEN_ODD));
        }
        else
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_FILL_RULE, VG_NON_ZERO));
        }
        if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_PAINT) == GFX_MGR02_PATH_PROP_FILL_PAINT_COLOR)
        {
          GFX_MGR02_OVG_COLOR_DEF_T const * fl_color_def_VP = (GFX_MGR02_OVG_COLOR_DEF_T const *)fl_cur_path_sp->fill_paint_vp;
          if(fl_color_def_VP != fl_last_fpaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_def_VP, GFX_MGR02_FPAINT_TYPE_COLOR_E, TRUE, 0);
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_FILL_PATH));
              fl_last_fpaint = fl_color_def_VP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes = VG_FILL_PATH;
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_PAINT) == GFX_MGR02_PATH_PROP_FILL_PAINT_LGRAD)
        {
          GFX_MGR02_OVG_LGRAD_DEF_T const * fl_color_lg_SP = (GFX_MGR02_OVG_LGRAD_DEF_T const *)fl_cur_path_sp->fill_paint_vp;

          if(fl_color_lg_SP != fl_last_fpaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_lg_SP, GFX_MGR02_FPAINT_TYPE_LGRAD_E, TRUE, fl_cur_path_sp->attributes);
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
            if(fl_color_lg_SP->matrix[8] != 0)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(fl_color_lg_SP->matrix));
            }
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_FILL_PATH));
              fl_last_fpaint = fl_color_lg_SP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes = VG_FILL_PATH;
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_PAINT) == GFX_MGR02_PATH_PROP_FILL_PAINT_RGRAD)
        {
          GFX_MGR02_OVG_RGRAD_DEF_T const * fl_color_rg_SP = (GFX_MGR02_OVG_RGRAD_DEF_T const *)fl_cur_path_sp->fill_paint_vp;

          if(fl_color_rg_SP != fl_last_fpaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_rg_SP, GFX_MGR02_FPAINT_TYPE_RGRAD_E, TRUE, fl_cur_path_sp->attributes);
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
            if(fl_color_rg_SP->matrix[8] != 0)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(fl_color_rg_SP->matrix));
            }
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_FILL_PATH));
              fl_last_fpaint = fl_color_rg_SP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes = VG_FILL_PATH;
        }
        else
        {
          /* Unsupported */
        }
      }
      if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_STROKE_ENABLED) == GFX_MGR02_PATH_PROP_STROKE_ENABLED)
      {
        if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_CAP) == GFX_MGR02_PATH_PROP_LINE_CAP_ROUND)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_CAP_STYLE, VG_CAP_ROUND));
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_CAP) == GFX_MGR02_PATH_PROP_LINE_CAP_SQUARE)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_CAP_STYLE, VG_CAP_SQUARE));
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_CAP) == GFX_MGR02_PATH_PROP_LINE_CAP_BUTT)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_CAP_STYLE, VG_CAP_BUTT));
        }
        else
        {
        	/*For MISRA warning fix.*/
        }
        if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_JOIN) == GFX_MGR02_PATH_PROP_LINE_JOIN_ROUND)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_JOIN_STYLE, VG_JOIN_ROUND));
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_JOIN) == GFX_MGR02_PATH_PROP_LINE_JOIN_BEVEL)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_JOIN_STYLE, VG_JOIN_BEVEL));
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_LINE_JOIN) == GFX_MGR02_PATH_PROP_LINE_JOIN_MITER)
        {
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_STROKE_JOIN_STYLE, VG_JOIN_MITER));
        }
        else
        {
        	/*For MISRA warning fix.*/
        }
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetf, vgSetf(VG_STROKE_LINE_WIDTH,  fl_cur_path_sp->stroke_width));
        GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetf, vgSetf(VG_STROKE_MITER_LIMIT, fl_cur_path_sp->mitter_limit));
        if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_STROKE_PAINT) == GFX_MGR02_PATH_PROP_STROKE_PAINT_COLOR)
        {
          GFX_MGR02_OVG_COLOR_DEF_T const * fl_color_SP = (GFX_MGR02_OVG_COLOR_DEF_T const *)fl_cur_path_sp->stroke_paint_vp;

          if(fl_color_SP != fl_last_spaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_SP, GFX_MGR02_SPAINT_TYPE_COLOR_E, TRUE, 0);
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_STROKE_PATH));
              fl_last_spaint = fl_color_SP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes |= VG_STROKE_PATH;
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_STROKE_PAINT) == GFX_MGR02_PATH_PROP_STROKE_PAINT_LGRAD)
        {
          GFX_MGR02_OVG_LGRAD_DEF_T const * fl_color_lg_SP = (GFX_MGR02_OVG_LGRAD_DEF_T const *)fl_cur_path_sp->stroke_paint_vp;

          if(fl_color_lg_SP != fl_last_spaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_lg_SP, GFX_MGR02_SPAINT_TYPE_LGRAD_E, TRUE, fl_cur_path_sp->attributes);
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
            if(fl_color_lg_SP->matrix[8] != 0)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(fl_color_lg_SP->matrix));
            }
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_STROKE_PATH));
              fl_last_spaint = fl_color_lg_SP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes |= VG_STROKE_PATH;
        }
        else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_STROKE_PAINT) == GFX_MGR02_PATH_PROP_STROKE_PAINT_RGRAD)
        {
          GFX_MGR02_OVG_RGRAD_DEF_T const * fl_color_rg_SP = (GFX_MGR02_OVG_RGRAD_DEF_T const *)fl_cur_path_sp->stroke_paint_vp;

          if(fl_color_rg_SP != fl_last_spaint)
          {
            VGPaint brush = hmi_gfx_mgr02_ovglib_cache_get_object((void const *)fl_color_rg_SP, GFX_MGR02_SPAINT_TYPE_RGRAD_E, TRUE, fl_cur_path_sp->attributes);
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSeti, vgSeti(VG_MATRIX_MODE, VG_MATRIX_FILL_PAINT_TO_USER));
            GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgLoadIdentity, vgLoadIdentity());
            if(fl_color_rg_SP->matrix[8] != 0)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgMultMatrix, vgMultMatrix(fl_color_rg_SP->matrix));
            }
            if(brush != VG_INVALID_HANDLE)
            {
              GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgSetPaint, vgSetPaint(brush,  VG_STROKE_PATH));
              fl_last_spaint = fl_color_rg_SP;
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
              GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPaint, vgDestroyPaint(brush));
#endif
            }
          }
          fl_paintModes |= VG_STROKE_PATH;
        }
        else
        {
          /* unsupported */
        }
      }
      if(fl_paintModes != 0)
      {
        if(fl_vgpath != VG_INVALID_HANDLE)
        { 
          GFX_OVG_UTIL_SUCCESS(l_ovglib_error, vgDrawPath, vgDrawPath(fl_vgpath, fl_paintModes));
        }
        l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
      }
#if !defined(GFX_MGR02_VG_IMG_CACHE_ENABLED)
      if(fl_vgpath != VG_INVALID_HANDLE)
      { 
        GFX_OVG_UTIL_VG_DESTROY(l_ovglib_error, vgDestroyPath, vgDestroyPath(fl_vgpath));
      }
#endif
      fl_cur_path_sp++;
      fl_path_count_U32--;
    }
#ifdef GFX02_DEBUG_OVG
    gfx_debug("ovglib - SVG elem =%08X printed\n", p_elem_def_SP);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("ovglib - SVG elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_fb_updated
Description          : Sets the flag to indicate that a ovg command was issued
and the framebuffer will change. This can be used by 
application to force an update when they perform
any openVG sequences with in a user image handler.
Invocation           : Invoked by generic manager
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ovglib_fb_updated(void)
{
  l_ovglib_draw_sts = (GFX_MGR02_OVGLIB_FLUSH_PENDING|GFX_MGR02_OVGLIB_FB_UPDATED);
}

/****************************************************************************
Function Name        : _ovglig_util_matrix_translate
Description          : internal matrix translation function.
Invocation           : Invoked by hmi_gfx_mgr02_ovglib_get_bound()
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ovglig_util_matrix_translate(GFX_FLOAT * m2, GFX_FLOAT tx, GFX_FLOAT ty)
{
  GFX_FLOAT fl_m2[3];

  fl_m2[0] = m2[6];
  fl_m2[1] = m2[7];
  fl_m2[2] = m2[8];

  m2[6]  = (m2[0] * tx);
  m2[6] += (m2[3] * ty);
  m2[6] += (fl_m2[0]);
  m2[7]  = (m2[1] * tx);
  m2[7] += (m2[4] * ty);
  m2[7] += (fl_m2[1]);
  m2[8]  = (m2[2] * tx);
  m2[8] += (m2[5] * ty);
  m2[8] += (fl_m2[2]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_get_bound
Description          : Calculates the transformed bounds of an elements passed
boundary
Invocation           : Invoked by generic manager
Parameters           : context, element def and elements bounds (un transformed).
p_bounds index 0,1 (x,y) 2,3 (width,height)
Return Value         : Updates transformed bounds in to p_bound_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ovglib_get_bound(UINT32                p_obj_type,
  GFX_MGR02_CONTEXT_T const * p_cntx_SP,  /* QA C warning fix RTC : 405974 */
  GFX_FLOAT               * p_bounds)
{
  VGfloat fl_cur_matrix[9];
  VGfloat x1;
  VGfloat y1;
  VGfloat x2;
  VGfloat y2;
  VGfloat x3;
  VGfloat y3;
  VGfloat x4;
  VGfloat y4;
  VGfloat minx;
  VGfloat miny;
  VGfloat maxx;
  VGfloat maxy;

  fl_cur_matrix[0]  = (p_cntx_SP->state.matrix[0]);
  fl_cur_matrix[0] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[2]);
  fl_cur_matrix[1]  = (p_cntx_SP->state.matrix[1]);
  fl_cur_matrix[1] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[2]);
  fl_cur_matrix[2]  = (p_cntx_SP->state.matrix[2]);

  fl_cur_matrix[3]  = (p_cntx_SP->state.matrix[3]);
  fl_cur_matrix[3] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[5]);
  fl_cur_matrix[4]  = (p_cntx_SP->state.matrix[4]);
  fl_cur_matrix[4] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[5]);
  fl_cur_matrix[5]  = (p_cntx_SP->state.matrix[5]);

  fl_cur_matrix[6]  = (p_cntx_SP->state.matrix[6]);
  fl_cur_matrix[6] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[8]);
  fl_cur_matrix[7]  = (p_cntx_SP->state.matrix[7]);
  fl_cur_matrix[7] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[8]);
  fl_cur_matrix[8]  = (p_cntx_SP->state.matrix[8]);

  if(p_obj_type == GFX_MGR02_TYPE_SVG)
  {
    hmi_gfx_mgr02_ovglig_util_matrix_translate(fl_cur_matrix, p_bounds[0], p_bounds[1]);
  }
  hmi_gfx_mgr02_ovglig_util_matrix_translate(fl_cur_matrix, -p_cntx_SP->rprop.pivot.x, -p_cntx_SP->rprop.pivot.y);

  if(p_obj_type == GFX_MGR02_TYPE_SIMAGE)
  {
    x1 = (fl_cur_matrix[6]/fl_cur_matrix[8]);
    y1 = (fl_cur_matrix[7]/fl_cur_matrix[8]);
    x2 = ((p_bounds[2]*fl_cur_matrix[0]) + fl_cur_matrix[6])/((p_bounds[2]*fl_cur_matrix[2])+ fl_cur_matrix[8]);
    y2 = ((p_bounds[2]*fl_cur_matrix[1]) + fl_cur_matrix[7])/((p_bounds[2]*fl_cur_matrix[2])+ fl_cur_matrix[8]);
    x3 = ((p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6])/((p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
    y3 = ((p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7])/((p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
    x4 = ((p_bounds[2]*fl_cur_matrix[0]) + (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6])/((p_bounds[2]*fl_cur_matrix[2])+ (p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
    y4 = ((p_bounds[2]*fl_cur_matrix[1]) + (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7])/((p_bounds[2]*fl_cur_matrix[2])+ (p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
  }
  else
  {
    x1 = fl_cur_matrix[6];
    y1 = fl_cur_matrix[7];
    x2 = (p_bounds[2]*fl_cur_matrix[0]) + fl_cur_matrix[6];
    y2 = (p_bounds[2]*fl_cur_matrix[1]) + fl_cur_matrix[7];
    x3 = (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6];
    y3 = (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7];
    x4 = (p_bounds[2]*fl_cur_matrix[0]) + (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6];
    y4 = (p_bounds[2]*fl_cur_matrix[1]) + (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7];
  }
  if(x1 < x2)
  {
    minx = x1;
    maxx = x2;
  }
  else
  {
    minx = x2;
    maxx = x1;
  }
  if(x3 < minx)
  {
    minx = x3;
  }
  if(x4 < minx)
  {
    minx = x4;
  }
  if(x3 > maxx)
  {
    maxx = x3;
  }
  if(x4 > maxx)
  {
    maxx = x4;
  }

  if(y1 < y2)
  {
    miny = y1;
    maxy = y2;
  }
  else
  {
    miny = y2;
    maxy = y1;
  }
  if(y3 < miny)
  {
    miny = y3;
  }
  if(y4 < miny)
  {
    miny = y4;
  }
  if(y3 > maxy)
  {
    maxy = y3;
  }
  if(y4 > maxy)
  {
    maxy = y4;
  }

  p_bounds[0] = minx;
  p_bounds[1] = miny;
  p_bounds[2] = (maxx-minx);
  p_bounds[3] = (maxy-miny);

  return 0;
}
#endif /* #if defined(GFX_MGR02_OPEN_VG) */

#ifdef  __cplusplus
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

** CMS Rev 1.45    18-Dec-2017    KKUBENDI
** 985451: Thai language support in GDT for Kepler 2 platform with bitmap font
**
** CMS Rev 1.44    23-Nov-2017    ARAJASE2
** 994906: P552 L1, L2 - OpenVG rendering texts are not displayed (Core Migration).
** Usage of GFX_MGR02_VG_CACHE_ENABLED macro is replaced with new macros
** GFX_MGR02_VG_IMG_CACHE_ENABLED and GFX_MGR02_VG_TXT_CACHE_ENABLED
**
** CMS Rev 1.43     23-Aug-2017    ADEVI
** 929657: Dynamic Text Width Change
** 
** CMS Rev 1.42    24-Jul-2017    SBOLLAM
** RTC ID: 918040: Fixing text cache issue, taking cached drawing
**                 co-ordinates for zw character, but it shouldn't take
**
** CMS Rev 1.41    24-Jul-2017    SBOLLAM
** RTC ID: 917605: Implemented GPOS- MarkToLigature table
**
** CMS Rev 1.40     07/02/2016    SBOLLAM
** RTC ID: 750237: Updated error logging capability and added
**                 OVG software recovery capability
**
** CMS Rev 1.39     07-Feb-2017    VGAJJI
** 796121: gfx_mgr02: Code protection check was missed for bmp fonts
**
** CMS Rev 1.38     12-Jan-2017    CSAKTHIV
** 782855: Truncation of text and image in left side. Refer NXP forum and B515 defect.
**
** CMS Rev 1.37     24-Nov-2016    CSAKTHIV
** 753474: All characters in UI gets overlapped when theme is changed with 1000*500 image
** Removed theme id check from hmi_gfx_mgr02_ovglib_removed_from_cache().
**
** CMS Rev 1.36     15-Sep-2016    SBOLLAM
** 695578: GPOS handling through mono type font engine.
** Description: Rendering arabic zw chars using GPOS
**
** CMS Rev 1.36      22-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.35     15-Feb-2016    ADEVI         RTC 494789
** Multi line text Implementation - NEW FORD requirements.
**
** CMS Rev 1.34     11-Feb-2015    ADEVI
** RTC 520133:
** Issue in MFD.  One pixel truncation for alignment change from left to right.
**
** CMS Rev 1.33     05-Feb-2015    APERUMAL
** RTC 512949:
** Compiler warnings fix for B515
**
** CMS Rev 1.32     29-Jan-2015    APERUMAL
** RTC 507885:
** QAC warnings fix for Honda Thaa
**
** CMS Rev 1.31     28-Dec-2015    CSAKTHIV         RTC 490199
** Monotype Implementation
**
** CMS Rev 1.30     27-Nov-2015    CSAKTHIV         RTC 460855
** Theme support for B515
**
** CMS Rev 1.29     28-Oct-2015    ADEVI         RTC 412568
** Multi line text Implementation - Initial Version.
**
** CMS Rev 1.28      31-Aug-2015    APERUMAL
** Rtc 257931
** Changed the UINT32 functional local variable names using _U8 subscript
** to _U32 subscript
**
** CMS Rev 1.27      31-Aug-2015    APERUMAL
** Rtc 409066
** Updated the hmi_gfx_mgr02_ovglib_cache_update_live_count() and called the
** function from hmi_gfx_mgr02_ovglib_finish() to resolve unused function
** QAC warning for Honda Thaa
**
** CMS Rev 1.26      19-Jun-2015    EMANOJ1
** Rtc 362035
** Deactivated elements were not properly getting cleared after the verification 
** of 360412 change. This was due to the fact that clip area was not being set
** and it remained at the previous set value. This cases the clear & build 
** request not getting processed due to incorrect clip area.
**
** CMS Rev 1.25      17-Jun-2015    EMANOJ1
** Rtc 360412 - Support for clear buffer when dirty area redraw enabled is added
**
** CMS Rev 1.24      08-Jun-2015    EMANOJ1
** Rtc 353768 - Position of text and fill corrected for rotated display case
**
** CMS Rev 1.23      24-Apr-2015    EMANOJ1
** Rtc 341088 : China team reported that a popup image border size is differing
** in the GDT and target. This was due to the fact that a paint was not set.
**
** CMS Rev 1.22      17-Feb-2015    EMANOJ1
** vgCreateConstImageFSL updated to fix RTC work item#290501
** Image sporadically get flipped in display due to the fact that vgCreateConstImageFSL
** called without passing its last parameter. So the vgCreateConstImageFSL read
** the last parameter as a junk value resulting in sporadic operation. Now the 
** function is called as per prototype definition in freescale header file.
**
** CMS Rev 1.21      07-Jan-2015    EMANOJ1
** Integrated RBHARAT2 changes done in 816:rel-UI-CORE-3.12.40-P552_OPENVG_CONTEXT_CACHE_SUPPORT
** baseline (CMS rev 1.18) in to latest version
**
** CMS Rev 1.20      06-Jan-2015    EMANOJ1
** Ref : RTC#264915
** hmi_gfx_mgr02_ovglib_get_stride - updated to round the stride calculation for
** 1bpp and 4bpp images.
** Updated hmi_gfx_mgr02_ovglib_build_text to support anti clockwise 90degree
** rotation.
**
** CMS Rev 1.19      17-Dec-2014    EMANOJ1
** Updated PR comments SMIS#80960
**
** CMS Rev 1.18      14-Dec-2014    RBHARAT2
** RTC 250101 - VG cache implementation modified to have individual cache buffers
**
** CMS Rev 1.17      10-Nov-2014    EMANOJ1
** hmi_gfx_mgr02_ovglib_cache_get_object - fixed an issue where index 0 of
** cache was overwritten when the search cannot identify a free location for
** given client_id. This will result in lossing of the image handle located in 
** index0 and causing a memory leak.
** Fix is done to reserve one each location for every client ID in the begening
** of the cache. Rest of the area will be used as general purpose. This will ensure
** that if the search cannot find a location in general purpose area, it can use 
** the dedicated index at the begening to allocate the image rather than overwriting
** in to another client's handle.
**
** CMS Rev 1.16      08-May-2014    EMANOJ1
** memory leak issue fixed due to non-invokation of vgDestroyConstImageFSL
** 
** CMS Rev 1.15      20-Nov-2013    SBOLLAM
** Modified hmi_gfx_mgr02_ovglib_build_text to consider p_text_actual_width
**
** CMS Rev 1.14      26-Aug-2013    EMANOJ1
** hmi_gfx_mgr02_ovglib_get_bound updated to directly write the bound as float
** in to the passed array to support bound calculation for the dynamic buffer
** allocation in DCU OpenVg widgets with clip=false settings. Also removed
** the bound clamp to clip area from here as it was only needed for the dirty
** region update and therefore this is now commonly handled at 
** hmi_gfx_mgr02_dar_add()
**
** CMS Rev 1.13      19-Aug-2013    EMANOJ1
** Added a target parameter for text width calculation and printing as the 
** text.c has been updated to utilize this parameter.
**
** CMS Rev 1.12     26-Jul-2013    EMANOJ1
** Added hmi_gfx_mgr02_ovglib_fb_updated() function to externally force an
** update.
**
** CMS Rev 1.12     26-Jul-2013    EMANOJ1
** Added precreation of vector fonts to improve text rendering speed.
**
** CMS Rev 1.11     11-Jul-2013    EMANOJ1
** hmi_gfx_mgr02_ovglib_cache_get_object updated to track an image objects with
** its pixel_data pointer rather than the object def pointer since user type
** images, the pixel data could be changed by the user at run time and we donot
** track with pixel data pointer we will still show the old image.
** TOTO : what if the user type image pixel_data contens are getting changed?
** In this case the pointer remain the same but contens change. This case needs
** to be handled later. Also hmi_gfx_mgr02_ovglib_cache_update_live_count handling
** to be taken care later as well.
**
** CMS Rev 1.10     28-Jun-2013    EMANOJ1
** image gradient paint option is removed for now as it is not supported
**
** CMS Rev 1.9      28-Jun-2013    EMANOJ1
** GFX_MGR02_VG_CACHE is not binded by the context. For this the 
** 0 to GFX_MGR02_NUM_LAYERS are used as ID for the layers
** GFX_MGR02_NUM_LAYERS onwards is used as ID for OVG widgets in DCU target
** This unique identifier is used to tag an object created by GFX_MGR02_VG_CACHE
** This is to prevent an object created in a different context being given to
** another context.
**
** CMS Rev 1.8      20-Jun-2013    EMANOJ1
** Updated to add element opeque status bit to support element visibility
** check by DAR to speed up rendering by removal of invisible elements from 
** rendering.
**
** CMS Rev 1.7      12-Jun-2013    EMANOJ1
** right2left handling was made common for all platforms and its implementation
** is now done using GFX_MGR02_GALIGNMENT() which sets the correct alignment at 
** source itself and the ovglib now doesn't need to handle anything.
** Add code to handle the case of dynamic modification of text alignment
**
** CMS Rev 1.6      10-Jun-2013    EMANOJ1
** Added code to swap all right/left alignment to left/right if the right2left
** proerty flag of a font group is set.
**
** CMS Rev 1.5      07-Jun-2013    EMANOJ1
** Implemented vector fonts based text rendering.
**
** CMS Rev 1.4      28-May-2013     EMANOJ1
** Merged muthu's fix for text color issue (R and B were swapped earlier)
**
** CMS Rev 1.3      15-May-2013     EMANOJ1
** Added hmi_gfx_mgr02_ovglib_get_bound() interface to calculate the 
** transformed bounds of an element
** Fixed an issue with text color as the VG_IMAGE_MODE was not set earlier
**
** CMS Rev 1.2      03-Apr-2013    ASHEKHAR
** Resolved QAC Warnings.
**
** CMS Rev 1.2      22-Mar-2013    VMUTHUSU
** Change NULL_PTR to GFX_MGR02_NULL_PTR
**
** CMS Rev 1.1      15-Mar-2012    EMANOJ1
** Resolved issue with respect to default matrix. OpenVG origin is at bottom
** left corner, where as display origin needs to be top, left corner to get
** image correctly getting displayed. So the default matrix needs to be set to
** mirror the final output. Added a provision to configure the default matrix 
** by application.
** Setting the clip area for all build routines added.
** Added support for SVG image clipping and text building
**
** CMS Rev 1.0      09-Aug-2012    EMANOJ1
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
