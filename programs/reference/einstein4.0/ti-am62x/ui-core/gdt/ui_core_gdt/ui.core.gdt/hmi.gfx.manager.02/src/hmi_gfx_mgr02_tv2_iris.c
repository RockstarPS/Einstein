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
** Name:           hmi_gfx_mgr02_amber_tv2_iris.c
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#define HMI_GFX_MGR02_TV2_IRIS_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

#if (defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0))
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_tv2.h"
#include "hmi_gfx_mgr02_tv2_iris.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_tv2_clut.h"
#include "hmi_gfx_mgr02_cache.h"
#include "pe_matrix.h"
#include "cygfx_draweng.h"
#if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))
#include <freetype/ftsynth.h>
#endif
#if(GFX_MGR02_NUM_MASK_WIDGETS > 0) || defined(GFX_STRING_CACHE_ENABLED)
#include "ut_compatibility.h"
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
#include <freetype/ftcache.h>
#endif
#ifndef GFX_MGR02_USE_EXT_FONT_ENGINE
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_BMPFONT))
#error "Invalid Configuration"
#endif
#endif
#if defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
#if (!defined(GFX_MGR02_USE_EXT_FONT_ENGINE) || (GFX_MGR02_EXT_FONT_ENGINE!=GFX_MGR02_MONOTYPE))
#error "Invalid Configuration"
#endif
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)))
#if (defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)  
#if !defined(GFX_MGR02_DE_PATHBUF_SIZE) || !defined(GFX_MGR02_DE_ALPHABUF_SIZE)
#error "Please configure alpha and path buffers"
#endif
#endif
#endif
#if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED)
#include "hmi_gfx_mgr02_warp_tables.cfg"
#endif /* #if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_LAYER_WARPING_ENABLED) */
#include "math.h"

#if (GFX_MGR02_NUM_USER_LAYERS > 0)
#include "de_util.h"
#endif
#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED)
#include "cap_util.h"
#endif
#ifdef  __cplusplus
extern "C" {
#endif

  /*============================================================================
  ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
  **==========================================================================*/

#define GFX_MGR02_TV2_FLUSH_PENDING     (0x01U)
#define GFX_MGR02_TV2_FB_UPDATED        (0x02U)
#define GFX_MGR02_TV2_NO_FLUSH_PENDING     (0xFEU)

#define GM2_IRIS_R(argb)  ((UINT8)(((argb) >> 16UL) & (UINT32)0xFF))
#define GM2_IRIS_G(argb)  ((UINT8)(((argb) >>  8UL) & (UINT32)0xFF))
#define GM2_IRIS_B(argb)  ((UINT8)(argb))
#define GM2_IRIS_A(argb)  ((UINT8)((argb)>> 24UL))

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))
  typedef struct
  {
    CYGFX_S32 x;
    CYGFX_S32 y;
  }GFX_MGR02_VECTOR;

#define GFX_MGR02_AMBER_OUTLN_MASK (UINT8)0x03

#elif (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
#define GFX_MGR02_VECTOR  FT_Vector
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
  static GFX_MGR02_SHAPE_INFO  l_shaper_info;
#endif

  /*============================================================================
  ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
  **==========================================================================*/

  static void hmi_gfx_mgr02_amber_Mat3x3_Multiply(CYGFX_FLOAT* p_dstmatrix, const CYGFX_FLOAT* p_src_matrix1, const CYGFX_FLOAT* p_src_matrix2);
  static CYGFX_S32 hmi_gfx_mgr02_amber_blt(CYGFX_BE_CONTEXT p_pectx, CYGFX_FLOAT p_offsetx, CYGFX_FLOAT p_offsety);
  static CYGFX_S32 hmi_gfx_mgr02_amber_blt_ext(CYGFX_BE_CONTEXT p_pectx, CYGFX_FLOAT p_offsetx, CYGFX_FLOAT p_offsety);
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  static void hmi_gfx_mgr02_amber_set_clip(GFX_MGR02_CONTEXT_T const* p_cntx_SP, CYGFX_BE_CONTEXT p_pixeng_ctx, UINT32 target, UINT8 p_force_update_u8);
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
  static SINT32 hmi_gfx_mgr02_amber_render_cache_outline_glyph(FT_OutlineGlyph const glyph, CYGFX_BE_CONTEXT p_pixeng_ctx);
#endif
  static SINT32 hmi_gfx_mgr02_amber_render_outline_glyph(FT_GlyphSlot const glyph, CYGFX_BE_CONTEXT p_pixeng_ctx);
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
  static SINT32 hmi_gfx_mgr02_amber_FtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, FT_Face p_face, SINT32 x, SINT32 y, HMI_CHAR const* p_string, UINT32 p_str_length, BOOLEAN p_autohint, CYGFX_FLOAT p_size);
#else
  static SINT32 hmi_gfx_mgr02_amber_FtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, FT_Face p_face, SINT32 x, SINT32 y, HMI_CHAR const* p_string, UINT32 p_str_length, BOOLEAN p_autohint);
#endif
#endif
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE) &&  ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))
#if !defined(GFX_STRING_CACHE_ENABLED)
  static void draw_outline_string(CYGFX_FLOAT x, GFX_MGR02_CONTEXT_T  const* p_cntx_SP, CYGFX_SM_FORMAT p_surf_format, HMI_CHAR const* p_string_p, GFX_MGR02_FONT const* p_font_SP, UINT8* p_draw_color, UINT32 p_str_length);
#endif
  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_move_to(const GFX_MGR02_VECTOR* to, void* user);
  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_line_to(const GFX_MGR02_VECTOR* to, void* user);
  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_conic_to(const GFX_MGR02_VECTOR* control, const GFX_MGR02_VECTOR* to, void* user);
  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_cubic_to(const GFX_MGR02_VECTOR* control1, const GFX_MGR02_VECTOR* control2, const GFX_MGR02_VECTOR* to, void* user);
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))
  static SINT32 hmi_gfx_mgr02_amber_MtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, GFX_MGR02_CONTEXT_T const* p_cntx_SP, SINT32 p_draw_x, SINT32 p_draw_y, HMI_CHAR const* p_string, UINT32 p_str_length, GFX_UINT p_autohint);
#endif

#ifdef GFX_STRING_CACHE_ENABLED
static void hmi_gfx_mgr02_create_img_for_string(UINT8 *p_str_img_SP,GFX_MGR02_CONTEXT_T  const * p_cntx_SP, HMI_CHAR const * p_string_p, 
                                                UINT32 p_width, GFX_MGR02_FONT const * p_font_SP
                                            #if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))
                                                ,GFX_MGR02_TXT_SPECIAL_EFFECTS* p_txt_special_prop_SP
                                            #endif
                                            #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
                                                ,UINT16 p_ml_str_index,GFX_MGR02_SHAPE_ML_DATA *p_ML_data_ptr,u_gx_flocal p_is_multi_line_text 
                                                ,GFX_MGR02_SHAPE_FLAGS *p_shape_flags
                                            #endif
                                                );

#else
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
static void draw_monotype_bmp_string(SINT32 x,GFX_MGR02_CONTEXT_T  const *p_cntx_SP,CYGFX_SM_FORMAT p_surf_format,HMI_CHAR const * p_string_p
                                     ,UINT32 p_full_text_width,GFX_MGR02_FONT const * p_font_SP,UINT8* p_draw_color,UINT32 p_str_length
                                    #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
                                     ,UINT16 p_ml_str_index,GFX_MGR02_SHAPE_ML_DATA *p_ML_data_ptr,u_gx_flocal p_is_multi_line_text
                                     ,GFX_MGR02_SHAPE_FLAGS *p_shape_flags 
                                    #endif
                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                    ,UINT16 p_scroll_offset
                                    ,GFX_UINT p_alignment
                                    #endif
                                    );
#endif
#else
static void draw_windows_bmp_string(CYGFX_FLOAT x, GFX_MGR02_CONTEXT_T  const *p_cntx_SP,
                                    CYGFX_SM_FORMAT p_surf_format,HMI_CHAR const * p_string_p,UINT32 p_full_text_width,
                                    GFX_MGR02_FONT const * p_font_SP,UINT8 const * p_draw_color,UINT32 p_str_length
                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                    ,UINT16 p_scroll_offset
                                    #endif
                                    );
#endif /* GFX_MGR02_USE_EXT_FONT_ENGINE */
#endif
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) &&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
  static void draw_freetype_bmp_string(SINT32 x, GFX_MGR02_CONTEXT_T const* p_cntx_SP, MML_GDC_SURF_FORMAT p_surf_format, HMI_CHAR const* p_string
    , GFX_MGR02_FONT const* p_font_SP, UINT8 const* p_draw_color, UINT32 p_str_length
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
     ,GFX_MGR02_TXT_SPECIAL_EFFECTS* p_txt_special_prop_SP
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    , UINT16 p_scroll_offset
    , UINT32 p_text_width
    , GFX_UINT p_alignment
#endif
  );
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
static void hmi_gfx_mgr02_amber_update_text_for_scroll(HMI_CHAR               const *p_string,
                                                       UINT16                        p_scroll_offset,
                                                       UINT16                       *p_cur_scroll_offset
                                                       , GFX_MGR02_TEXT_INFO        *p_text_info_SP
                                                       , GFX_MGR02_TEXT_DEF_T const *p_elem_def_SP
                                                       #ifndef  GFX_STRING_CACHE_ENABLED
                                                       , GFX_UINT                    p_alignment
                                                       #if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
                                                       , GFX_MGR02_SHAPE_INFO const *p_shaper_info
                                                       #endif
                                                       #endif
                                                      );
#ifndef GFX_STRING_CACHE_ENABLED
#if (!defined(GFX_MGR02_USE_EXT_FONT_ENGINE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_win_fonts(HMI_CHAR               const* p_string,
    UINT16                        p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
  );
#endif
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_mt_fonts(UINT16                      p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE))
    , GFX_MGR02_SHAPE_INFO const* p_shaper_info
    , HMI_CHAR             const* p_string
#endif
  );
#endif
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_ft_fonts(UINT16 p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
    , GFX_MGR02_SHAPE_INFO const* p_shaper_info
    , HMI_CHAR             const* p_string
#endif
  );
#endif
#endif /* GFX_STRING_CACHE_ENABLED */
#endif /* GFX_MGR02_HORIZONTAL_SCROLL_ENABLED */

  /*=============================================================================
  ** M E M O R Y   A L L O C A T I O N
  **==========================================================================*/
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
  typedef struct {
    FT_Face face;             /* The Freetype2 font object */
    FT_UInt  size;
    CYGFX_BE_CONTEXT pectx; /* 2D-Graphics-Core pixeng context for drawing  */
  }GFX_MGR02_FT2_CONTEXT_CONTAINER;
  typedef GFX_MGR02_FT2_CONTEXT_CONTAINER* GFX_MGR02_FT2_CONTEXT;
#endif


  static  UINT8   l_tv2_draw_sts;
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  static SINT32 l_tv2_clip_rect[4];
#endif
#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
  static CYGFX_SYNC l_tv2_be_sync;
#endif

#if GFX_MGR02_NUM_OF_DTEXTS > 0 
#if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_TRAVEO2))
  extern GFX_MGR02_SHAPE_ML_DATA l_shape_ml_dtext_buffer[GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS];
#endif
#endif
#endif

#if(GFX_MGR02_NUM_MASK_WIDGETS > 0)
  static CYGFX_SURFACE l_mask_image_surf = NULL;
#endif
  /*============================================================================
  ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
  **==========================================================================*/

  s_gx_flocal hmi_gfx_mgr02_tv2_init(void)
  {
    l_tv2_draw_sts = (UINT8)0;
#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
    l_tv2_be_sync = NULL;
#endif
#if defined(GFX_MGR02_CLIPPED_WIDGETS)  
    l_tv2_clip_rect[0] = (SINT32)0;
    l_tv2_clip_rect[1] = (SINT32)0;
    l_tv2_clip_rect[2] = (SINT32)0;
    l_tv2_clip_rect[3] = (SINT32)0;
#endif

#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)  && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
    l_shaper_info.shaper_out_ptr = (TsShaperText*)GFX_MGR02_NULL_PTR;
#else
    l_shaper_info.shaper_out_ptr = (GFX_MGR02_HB_SHAPE_INFO*)GFX_MGR02_NULL_PTR;
#endif
#endif
    return((s_gx_flocal)TRUE);
  }

#if GFX_MGR02_NUM_MASK_WIDGETS>0
  void hmi_gfx_mgr02_amber_set_mask_mode(GFX_MGR02_CONTEXT_T const* p_cntx_SP)
  {
    SINT32 ret = CYGFX_OK;


    if (p_cntx_SP->rprop.pe_msurf != NULL)
    {
      if (p_cntx_SP->rprop.mask_mode == GFX_MGR02_MASK_WIDGET_NORMAL)
      {
        IRIS_API_CHECK(ret, CyGfx_BeRopOperation(p_cntx_SP->rprop.pe_ctx,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_SRCCOPY));    /* For normal mask mode tested with SRCCOPY(SRC) or MASKAND(SRC & MASK) ROP mode */
      }
      else if (p_cntx_SP->rprop.mask_mode == GFX_MGR02_MASK_WIDGET_INVERTED)
      {
        IRIS_API_CHECK(ret, CyGfx_BeRopOperation(p_cntx_SP->rprop.pe_ctx,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_SRCCOPY,
          CYGFX_BE_ROP_MASKERASE));    /* For inverted mask mode tested with MASKERASE (SRC & ~MASK) ROP mode */
      }
      else
      {
        /*To Fix the MISRA warning.*/
      }
    }
    else
    {

      IRIS_API_CHECK(ret, CyGfx_BeRopOperation(p_cntx_SP->rprop.pe_ctx,
        CYGFX_BE_ROP_SRCCOPY,
        CYGFX_BE_ROP_SRCCOPY,
        CYGFX_BE_ROP_SRCCOPY,
        CYGFX_BE_ROP_SRCCOPY));
    }
  }
#endif

  s_gx_flocal hmi_gfx_mgr02_tv2_start(GFX_MGR02_CONTEXT_T const* p_cntx_SP)
  {
    SINT32 ret = CYGFX_OK;
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    {
      l_tv2_draw_sts = (UINT8)0;
#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      l_tv2_be_sync = p_cntx_SP->rprop.pe_sync;
#endif
      IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
      IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, p_cntx_SP->rprop.pe_tsurf));
#if GFX_MGR02_NUM_MASK_WIDGETS>0
      IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, p_cntx_SP->rprop.pe_msurf));
      hmi_gfx_mgr02_amber_set_mask_mode(p_cntx_SP);
#endif

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      l_tv2_clip_rect[0] = (SINT32)0;
      l_tv2_clip_rect[1] = (SINT32)0;
      l_tv2_clip_rect[2] = (SINT32)p_cntx_SP->rprop.fb_w;
      l_tv2_clip_rect[3] = (SINT32)p_cntx_SP->rprop.fb_h;
      IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
      IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE));
      IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, l_tv2_clip_rect[0], l_tv2_clip_rect[1], (UINT32)l_tv2_clip_rect[2], (UINT32)l_tv2_clip_rect[3]));
#endif
    }

    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    return(fl_return_value);
  }

  static CYGFX_S32 hmi_gfx_mgr02_amber_blt_ext(CYGFX_BE_CONTEXT p_pectx, CYGFX_FLOAT p_offsetx, CYGFX_FLOAT p_offsety)
  {
    CYGFX_S32 ret = CYGFX_OK;
    CYGFX_U32 fl_ib_cur = (CYGFX_U32)0;
    GFX_MGR02_CONTEXT_T const* fl_context_SP = hmi_gfx_mgr02_context_get_ptr();

    IRIS_API_CHECK(ret, CyGfx_BeBlt(p_pectx, p_offsetx, p_offsety));
    if (fl_context_SP->rprop.wdg_height == (UINT16)0)
    {
      IRIS_API_CHECK(ret, CyGfx_BeFlush(p_pectx));
    }
    IRIS_API_CHECK(ret, CyGfx_BeGetAttribute(p_pectx, CYGFX_BE_CTX_ATTR_CURRENT_INSTRUCTION_BUFFER, &fl_ib_cur));
    /* Buffer check size increased from 2048 to 4096 as mazda j59 is having buffer overflow issue*/
    if (fl_ib_cur < (CYGFX_U32)4096)
    {
      /*
      ** Low on command buffer..
      ** TODO : temporary fix. continous text glyph blit is causing command
      ** FIFO overflow. So we are waiting to complete the blt before proceeding
      */
#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      if (fl_context_SP->rprop.wdg_height == (UINT16)0)
      {
        IRIS_API_CHECK(ret, CyGfx_BeGetSync(p_pectx, l_tv2_be_sync));

      }
      do
      {
        ret = CyGfx_SyncWaitSync(l_tv2_be_sync, 0);
      } while (ret == CYGFX_ERP_ERR_SYNC_TIMEOUT);
#else
      IRIS_API_CHECK(ret, CyGfx_BeFinish(p_pectx));
#endif
    }
    return(ret);
  }

  static CYGFX_S32 hmi_gfx_mgr02_amber_blt(CYGFX_BE_CONTEXT p_pectx, CYGFX_FLOAT p_offsetx, CYGFX_FLOAT p_offsety)
  {
    CYGFX_S32 ret;
    ret = hmi_gfx_mgr02_amber_blt_ext(p_pectx, p_offsetx, p_offsety);
    l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING | GFX_MGR02_TV2_FB_UPDATED);
    return(ret);
  }

  s_gx_flocal hmi_gfx_mgr02_tv2_build_image(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_IMAGE_DEF_T  const* p_elem_def_SP)
  {
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_src_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_src_surf;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    UINT32   fl_fg_color;
    UINT32   fl_alpha_temp;
    UINT32   fl_rle_words;
    SINT32   ret = CYGFX_OK;
    void* vImgAddr;
    UINT8    fl_rgba[4];
    UINT8    fl_shutdown_state;
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
    /*
      Deviation from Rule:MISRA C 2012 Rule11.8 :Pointer Type Conversions
      Justification: The type casting image data to void pointer can't be avoided.
    */
    vImgAddr = (void*)p_elem_def_SP->pixel_data;

    /*
    ** 1. Create the surface object for the image and assign the image data to the surface.
    ** 2. Assign the CLUT if any.
    ** 3. Bind the surface to the passed pixel engine context
    */
    fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    if ((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
      fl_mml_gdc_src_surf = &fl_mml_gdc_src_surf_c;
      IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_src_surf));
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      fl_rle_words = p_elem_def_SP->comp_size;
#else
      fl_rle_words = (UINT32)0;
#endif
      if ((p_elem_def_SP->format == CYGFX_SM_FORMAT_A8) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A4) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A2) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A1))
      {
        UINT32 fl_bg_color = p_elem_def_SP->color;
        fl_rgba[0] = GM2_IRIS_R(fl_bg_color);  /* R */
        fl_rgba[1] = GM2_IRIS_G(fl_bg_color);  /* G */
        fl_rgba[2] = GM2_IRIS_B(fl_bg_color);  /* B */
        fl_rgba[3] = GM2_IRIS_A(fl_bg_color);  /* A */
        fl_alpha_temp = ((UINT32)fl_rgba[3] * p_cntx_SP->state.alpha);
        fl_rgba[3] = (UINT8)(fl_alpha_temp / (UINT32)0xFF);

        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf,
          (UINT32)p_elem_def_SP->width,
          (UINT32)p_elem_def_SP->height,
          CYGFX_SM_FORMAT_A8B8G8R8,
          (void*)0,
          (UINT32)0));
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_src_surf));
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
        utMat3x3LoadIdentity(fl_matrix1);
        utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
        hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
        utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
        IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
        hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif
        IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
        IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_src_surf));
      }
      if ((CYGFX_SM_FORMAT_RGB4 == p_elem_def_SP->format) ||
        (CYGFX_SM_FORMAT_RGB2 == p_elem_def_SP->format) ||
        (CYGFX_SM_FORMAT_A6R6G6B6 == p_elem_def_SP->format))
      {
        /*Currently Iris Driver not supports the 2BPP(CYGFX_SM_FORMAT_RGB2) , 4BPP(CYGFX_SM_FORMAT_RGB4)
        and 24BPP(CYGFX_SM_FORMAT_A6R6G6B6) surface formats. This If loop needs to be removed
        after the driver supports it.*/
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf,
          (UINT32)p_elem_def_SP->width,
          (UINT32)p_elem_def_SP->height,
          CYGFX_SM_FORMAT_R8G8B8A8,
          vImgAddr,
          fl_rle_words));
        if (CYGFX_SM_FORMAT_RGB2 == p_elem_def_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x02));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x02020200));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else if (CYGFX_SM_FORMAT_RGB4 == p_elem_def_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x04));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x04040400));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else
        {
          /*CYGFX_SM_FORMAT_A6R6G6B6*/
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x18));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x06060606));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x0c060012));
        }
      }
      else
      {
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf,
          (UINT32)p_elem_def_SP->width,
          (UINT32)p_elem_def_SP->height,
          (CYGFX_SM_FORMAT)p_elem_def_SP->format,
          vImgAddr,
          fl_rle_words));
      }
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      if (p_elem_def_SP->comp_size != (UINT32)0)
      {
        switch (p_elem_def_SP->compression)
        {
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLE:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLC));
        }
        break;
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLA:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLA));
        }
        break;
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLD:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLAD));
        }
        break;
        default:
        {
          /*To Fix MISRA warning.*/
        }
        break;
        }
      }
#endif
#if GFX_MGR02_NUM_OF_CLUTS > 0U
      if (p_elem_def_SP->clut != GFX_MGR02_NUM_OF_CLUTS)
      {
        CYGFX_PALETTE fl_pal_p = NULL;
        GFX_MGR02_CLUT_DATA const* fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[p_elem_def_SP->clut];

        CYGFX_U32 fl_clut_index_width_u32;
        fl_clut_index_width_u32 = hmi_gfx_mgr02_tv2_get_clut_index_width(fl_elem_clut_SP->CLUTsize);
        fl_pal_p = hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION_BLIT, fl_elem_clut_SP->CLUT);
        if (fl_pal_p == NULL)
        {
          fl_pal_p = hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION_BLIT, (const void*)fl_elem_clut_SP->CLUT, fl_elem_clut_SP->CLUTsize);
        }
        
        if (CYGFX_SM_FORMAT_A8RGB8 == p_elem_def_SP->format)
        {            
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, ((fl_clut_index_width_u32 << 24u) | (0x00000008UL))));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, fl_clut_index_width_u32));
        }
        else
        {
            /* Since alpha bits are zero for non-APAL16 indexed images, there is no need to set COLORSHIFT for alpha channel */
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (fl_clut_index_width_u32 << 24u)));
        }
        IRIS_API_CHECK(ret, CyGfx_SmPaletteAssign(fl_mml_gdc_src_surf, fl_pal_p));     
           
    }
 #endif
    if(p_elem_def_SP->format ==CYGFX_SM_FORMAT_R4G4B4A4)
    {
      IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x0804000C));
    }

    fl_fg_color = p_cntx_SP->rprop.fg_color;
    fl_rgba[0]  = GM2_IRIS_R(fl_fg_color);  /* R */
      fl_rgba[1] = GM2_IRIS_G(fl_fg_color);  /* G */
      fl_rgba[2] = GM2_IRIS_B(fl_fg_color);  /* B */
      fl_rgba[3] = GM2_IRIS_A(fl_fg_color);  /* A */

      IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_src_surf));
      if (p_elem_def_SP->chroma_key != 0U)
      {
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_TRANSPARENT, CYGFX_TRUE));
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
      }
      else
      {
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_TRANSPARENT, CYGFX_FALSE));
      }

      utMat3x3LoadIdentity(fl_matrix1);
      utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
      hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
      utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));

      IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));

      if ((p_cntx_SP->state.alpha < (UINT8)255) ||
        (fl_rgba[3] < (UINT8)255) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A8) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A4) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A2) ||
        (p_elem_def_SP->format == CYGFX_SM_FORMAT_A1))
      {
        fl_alpha_temp = ((UINT32)fl_rgba[3] * p_cntx_SP->state.alpha);
        fl_rgba[3] = (UINT8)(fl_alpha_temp / (UINT32)0xFF);

        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
        IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
          CYGFX_BE_BM_GL_FUNC_ADD,
          CYGFX_BE_BM_GL_FUNC_ADD,
          CYGFX_BE_BM_GL_FUNC_ADD,
          CYGFX_BE_BM_GL_FUNC_ADD));

        IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx,
          CYGFX_BE_BF_GL_SRC_ALPHA,
          CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
          CYGFX_BE_BF_GL_SRC_ALPHA,
          CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
          CYGFX_BE_BF_GL_SRC_ALPHA,
          CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
          CYGFX_BE_BF_GL_ONE,
          CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));

        /* Setting CYGFX_BE_SURF_ATTR_COLORMULTI as TRUE has been removed after Defect 1106955.By default it will be FALSE */
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
      }
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif
      IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
      IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("IrisEngine for Amber-I - Image elem =%08X skipped\n", p_elem_def_SP);
    }
#endif
    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    return(fl_return_value);

  }

#if defined(GFX_MGR02_CAPTURE_VIDEO_ENABLED) && (GFX_MGR02_CAPTURE_VIDEO_MODE == GFX_MGR02_CAPTURE_TO_SURFACE_MODE)
  s_gx_flocal hmi_gfx_mgr02_tv2_build_video(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_VIDEO_DEF_T  const* p_elem_def_SP)
  {
    SINT32   ret = CYGFX_OK;
    UINT8    fl_shutdown_state;
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;

    fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if ((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
      GFX_MGR02_CAPTURE_INIT_STATUS fl_init_status;
      hmi_gfx_mgr02_capture_video_set_status(TRUE);
      fl_init_status = hmi_gfx_mgr02_capture_to_surface_init(p_elem_def_SP);

      if (fl_init_status == GFX_MGR02_CAPTURE_INIT_SUCCESS)
      {
            CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
            CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
        CYGFX_SURFACE_OBJECT_S fl_mml_gdc_src_surf_c;
        CYGFX_SURFACE           fl_mml_gdc_src_surf;
        CYGFX_U32                    fl_surf_buffer;
        fl_mml_gdc_src_surf = &fl_mml_gdc_src_surf_c;

        hmi_gfx_mgr02_capture_get_surface(&fl_mml_gdc_src_surf);

        IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_PHYS_ADDRESS, &fl_surf_buffer));

        if (fl_surf_buffer != 0U)
        {
                const CYGFX_SYNC*              fl_cap_sync;
                IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_src_surf));
                #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                hmi_gfx_mgr02_amber_set_clip(p_cntx_SP,p_cntx_SP->rprop.pe_ctx,CYGFX_BE_TARGET_STORE,(UINT8)0);
                #endif
                if(hmi_gfx_mgr02_layout_get_frame_capture_done_status() == GFX_MGR02_VIDEO_CAPTURE_DONE)
                {                
                  fl_cap_sync = hmi_gfx_mgr02_get_capture_sync();
                  l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING|GFX_MGR02_TV2_FB_UPDATED);
                  IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
                  utMat3x3LoadIdentity(fl_matrix1);
                  utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
                  hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2,fl_matrix1,&p_cntx_SP->state.matrix[0]);
                  utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
                  IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3,fl_matrix2));
                  IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
                  hmi_gfx_mgr02_capture_to_surface_commit();
                  hmi_gfx_mgr02_layout_set_frame_capture_done_status(GFX_MGR02_VIDEO_CAPTURE_NOT_DONE);
                }
            }
        }
        else
      {
        fl_return_value = (s_gx_flocal)FALSE;
      }
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("IrisEngine for Amber-I - Video elem = skipped\n");
    }
#endif

    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    return(fl_return_value);
  }
#endif

#if(GFX_MGR02_NUM_MASK_WIDGETS > 0)

  void hmi_gfx_mgr02_amber_create_mask_image_surf(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_IMAGE_DEF_T  const* p_image_desc_SP)
  {
    UINT32                         fl_rle_words;
    void* fl_buff_ptr;
    SINT32   ret = CYGFX_OK;


    if (p_image_desc_SP != GFX_MGR02_NULL_PTR)
    {
      fl_buff_ptr = (void*)p_image_desc_SP->pixel_data;
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      fl_rle_words = p_image_desc_SP->comp_size;
#else
      fl_rle_words = (UINT32)0;
#endif
      if (l_mask_image_surf == NULL)
      {
        IRIS_API_CHECK(ret, utSmGenSurfaceObjects((CYGFX_U32)1, &l_mask_image_surf));
      }

      if ((CYGFX_SM_FORMAT_RGB4 == p_image_desc_SP->format) ||
        (CYGFX_SM_FORMAT_RGB2 == p_image_desc_SP->format) ||
        (CYGFX_SM_FORMAT_A6R6G6B6 == p_image_desc_SP->format))
      {
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(l_mask_image_surf,
          (UINT32)p_image_desc_SP->width,
          (UINT32)p_image_desc_SP->height,
          CYGFX_SM_FORMAT_R8G8B8A8,
          fl_buff_ptr,
          fl_rle_words));

        if (CYGFX_SM_FORMAT_RGB2 == p_image_desc_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x02));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x02020200));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else if (CYGFX_SM_FORMAT_RGB4 == p_image_desc_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x04));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x04040400));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else
        {
          /*CYGFX_SM_FORMAT_A6R6G6B6*/
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x18));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x06060606));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x0c060012));
        }
      }
      else
      {
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(l_mask_image_surf,
          (UINT32)p_image_desc_SP->width,
          (UINT32)p_image_desc_SP->height,
          (CYGFX_SM_FORMAT)p_image_desc_SP->format,
          fl_buff_ptr,
          fl_rle_words));
      }
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      if (fl_rle_words != (UINT32)0)
      {
        switch (p_image_desc_SP->compression)
        {
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLE:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLC));
        }
        break;
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLA:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLA));
        }
        break;
        case (UINT8)GFX_MGR02_IMAGE_COMPRESSION_IRLD:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLAD));
        }
        break;
        default:
        {
          /*To Fix MISRA warning.*/
        }
        break;
        }
      }
#endif

#if GFX_MGR02_NUM_OF_CLUTS > 0U
      if (p_image_desc_SP->clut != GFX_MGR02_NUM_OF_CLUTS)
      {
        CYGFX_PALETTE fl_pal_p = NULL;
        GFX_MGR02_CLUT_DATA const* fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[p_image_desc_SP->clut];

        CYGFX_U32 fl_clut_index_width_u32;
        fl_clut_index_width_u32 = hmi_gfx_mgr02_tv2_get_clut_index_width(fl_elem_clut_SP->CLUTsize);
        fl_pal_p = hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION_BLIT, fl_elem_clut_SP->CLUT);
        if (fl_pal_p == NULL)
        {
            fl_pal_p = hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION_BLIT, (const void*)fl_elem_clut_SP->CLUT, fl_elem_clut_SP->CLUTsize);
        }
        
        if (CYGFX_SM_FORMAT_A8RGB8 == p_image_desc_SP->format)
        {            
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORBITS, ((fl_clut_index_width_u32 << 24u) | (0x00000008UL))));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORSHIFT, fl_clut_index_width_u32));
        }
        else
        {
            /* Since alpha bits are zero for non-APAL16 indexed images, there is no need to set COLORSHIFT for alpha channel */
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(l_mask_image_surf, CYGFX_SM_ATTR_COLORBITS, (fl_clut_index_width_u32 << 24u)));
        }
        IRIS_API_CHECK(ret, CyGfx_SmPaletteAssign(l_mask_image_surf, fl_pal_p));     

    }
 #endif
      hmi_gfx_mgr02_context_set_masksurf(l_mask_image_surf);
      hmi_gfx_mgr02_amber_set_mask_attributes(p_cntx_SP, (SINT32)p_cntx_SP->state.loc.x, (SINT32)p_cntx_SP->state.loc.y);
    }
  }
  void hmi_gfx_mgr02_amber_bind_mask_surf(GFX_MGR02_CONTEXT_T   const* p_cntx_SP, CYGFX_SURFACE p_mask_surf)
  {
    SINT32   ret = CYGFX_OK;
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, p_mask_surf));
  }

  void hmi_gfx_mgr02_amber_set_mask_attributes(GFX_MGR02_CONTEXT_T   const* p_cntx_SP, SINT32 p_x, SINT32 p_y)
  {
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

    SINT32   ret = CYGFX_OK;

    utMat3x3LoadIdentity(fl_matrix1);
    utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_x, (GFX_FLOAT)p_y);
    hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
    utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, p_cntx_SP->rprop.pe_msurf));
    IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
  }
#endif

  s_gx_flocal hmi_gfx_mgr02_tv2_build_fill(GFX_MGR02_CONTEXT_T   const* p_cntx_SP, GFX_MGR02_FILL_DEF_T   const* p_elem_def_SP, GFX_MGR02_IDIM_DATA const* p_dim)
  {
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_src_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_src_surf;
    SINT32 ret = CYGFX_OK;
    UINT32 fl_fg_color;
    UINT32 fl_alpha_temp;
    UINT8  fl_rgba[4];
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;

    if ((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
      fl_fg_color = p_cntx_SP->rprop.fg_color;
      fl_rgba[0] = GM2_IRIS_R(fl_fg_color); /* R */
      fl_rgba[1] = GM2_IRIS_G(fl_fg_color); /* G */
      fl_rgba[2] = GM2_IRIS_B(fl_fg_color); /* B */
      fl_rgba[3] = GM2_IRIS_A(fl_fg_color); /* A */
      if (fl_rgba[3] == (UINT8)0)
      {
        CYGFX_U32 x = (CYGFX_U32)0;
        CYGFX_U32 y = (CYGFX_U32)0;
        CYGFX_U32 width = (CYGFX_U32)0;
        CYGFX_U32 height = (CYGFX_U32)0;
        IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
        if (p_cntx_SP->state.loc.x < 0)
        {
          width = (CYGFX_U32)((GFX_FLOAT)p_dim->width + (GFX_FLOAT)p_cntx_SP->state.loc.x);
        }
        else
        {
          x = (CYGFX_U32)p_cntx_SP->state.loc.x;
          width = p_dim->width;
        }
        if (p_cntx_SP->state.loc.y < 0)
        {
          height = (CYGFX_U32)((GFX_FLOAT)p_dim->height + (GFX_FLOAT)p_cntx_SP->state.loc.y);
        }
        else
        {
          y = (CYGFX_U32)p_cntx_SP->state.loc.y;
          height = p_dim->height;
        }
        IRIS_API_CHECK(ret, CyGfx_BeFill(p_cntx_SP->rprop.pe_ctx, x, y, width, height));
        l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING | GFX_MGR02_TV2_FB_UPDATED);
      }
      else
      {
        fl_mml_gdc_src_surf = &fl_mml_gdc_src_surf_c;
        IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_src_surf));
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf, (CYGFX_U32)p_elem_def_SP->dim.width, (CYGFX_U32)p_elem_def_SP->dim.height, CYGFX_SM_FORMAT_A8B8G8R8, (void*)0, (CYGFX_U32)0));
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_src_surf));
        utMat3x3LoadIdentity(fl_matrix1);
        utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
        hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
        utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
        IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));

        if ((p_cntx_SP->state.alpha < (UINT8)255) || (fl_rgba[3] < (UINT8)255))
        {
          fl_alpha_temp = ((UINT32)fl_rgba[3] * p_cntx_SP->state.alpha);
          fl_rgba[3] = (UINT8)(fl_alpha_temp / (UINT32)255);

          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
          IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
            CYGFX_BE_BM_GL_FUNC_ADD,
            CYGFX_BE_BM_GL_FUNC_ADD,
            CYGFX_BE_BM_GL_FUNC_ADD,
            CYGFX_BE_BM_GL_FUNC_ADD));

          IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_ONE, CYGFX_BE_BF_GL_ONE));

        }
        else
        {
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
        }

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
        hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif
        IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
      }
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("IrisEngine for Amber-I - Fill elem =%08X skipped\n", p_elem_def_SP);
    }
#endif
    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    return(fl_return_value);
  }

#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))

  s_gx_flocal hmi_gfx_mgr02_tv2_build_tile(GFX_MGR02_CONTEXT_T   const* p_cntx_SP, GFX_MGR02_TILE_DEF_T   const* p_elem_def_SP, GFX_MGR02_IDIM_DATA const* p_dim)
  {
    SINT32 ret = CYGFX_OK;
    s_gx_flocal fl_return_value = FALSE;
#if GFX_MGR02_NUM_OF_TILES > 0
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_src_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_src_surf = NULL;
    void* vImgAddr = NULL;
    UINT32 fl_fg_color = 0;
    UINT32 fl_alpha_temp = 0;
    UINT32 fl_rle_words = 0;
    SINT16 fl_img_width = 0;
    SINT16 fl_img_height = 0;
    SINT16 fl_img_draw_x = 0;
    SINT16 fl_img_draw_y = 0;
    SINT16 fl_tile_end_x = 0;
    SINT16 fl_tile_end_y = 0;
    UINT8  fl_rgba[4] = { 0,0,0,0 };
    UINT8  fl_shutdown_state = GFX_MGR02_SHUTDOWN_NORMAL;

    fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    if ((p_cntx_SP->state.invisible == 0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
      GFX_MGR02_IMAGE_DEF_T const* fl_element_def_SP = &lc_image_layer_def_S[p_elem_def_SP->id];
      fl_mml_gdc_src_surf = &fl_mml_gdc_src_surf_c;
      IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_src_surf));
      vImgAddr = (void*)fl_element_def_SP->pixel_data;

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      fl_rle_words = fl_element_def_SP->comp_size;
#endif
      if ((CYGFX_SM_FORMAT_RGB4 == fl_element_def_SP->format) ||
        (CYGFX_SM_FORMAT_RGB2 == fl_element_def_SP->format) ||
        (CYGFX_SM_FORMAT_A6R6G6B6 == fl_element_def_SP->format))
      {
        /*Currently Iris Driver not supports the 2BPP(CYGFX_SM_FORMAT_RGB2) and 4BPP(CYGFX_SM_FORMAT_RGB4)
        surface formats. This If loop needs to be removed after the driver supports it.*/
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf,
          (UINT32)fl_element_def_SP->width,
          (UINT32)fl_element_def_SP->height,
          CYGFX_SM_FORMAT_R8G8B8A8,
          (void*)vImgAddr,
          fl_rle_words));
        if (CYGFX_SM_FORMAT_RGB2 == fl_element_def_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x02));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x02020200));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else if (CYGFX_SM_FORMAT_RGB4 == fl_element_def_SP->format)
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x04));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x04040400));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x00000000));
        }
        else
        {
          /*CYGFX_SM_FORMAT_A6R6G6B6*/
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_BITPERPIXEL, (UINT32)0x18));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (UINT32)0x06060606));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, (UINT32)0x0c060012));
        }
      }
      else
      {
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_src_surf,
          (UINT32)fl_element_def_SP->width,
          (UINT32)fl_element_def_SP->height,
          (CYGFX_SM_FORMAT)fl_element_def_SP->format,
          (void*)vImgAddr,
          fl_rle_words));
      }
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
      if (fl_element_def_SP->comp_size != 0)
      {
        switch (fl_element_def_SP->compression)
        {
        case GFX_MGR02_IMAGE_COMPRESSION_IRLE:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLC));
        }
        break;
        case GFX_MGR02_IMAGE_COMPRESSION_IRLA:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLA));
        }
        break;
        case GFX_MGR02_IMAGE_COMPRESSION_IRLD:
        {
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COMPRESSION_FORMAT, (UINT32)CYGFX_SM_COMP_RLAD));
        }
        break;
        default:
        {
          /*To fix MISRA warning.*/
        }
        break;
        }
      }
#endif

#if GFX_MGR02_NUM_OF_CLUTS > 0U
      if (fl_element_def_SP->clut != GFX_MGR02_NUM_OF_CLUTS)
      {
        CYGFX_PALETTE fl_pal_p = NULL;
        GFX_MGR02_CLUT_DATA const* fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[fl_element_def_SP->clut];

        CYGFX_U32 fl_clut_index_width_u32;
        fl_clut_index_width_u32 = hmi_gfx_mgr02_tv2_get_clut_index_width(fl_elem_clut_SP->CLUTsize);
        fl_pal_p = hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION_BLIT, fl_elem_clut_SP->CLUT);
        if (fl_pal_p == NULL)
        {
            fl_pal_p = hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION_BLIT, (const void*)fl_elem_clut_SP->CLUT, fl_elem_clut_SP->CLUTsize);
        }
        
        if (CYGFX_SM_FORMAT_A8RGB8 == fl_element_def_SP->format)
        {            
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, ((fl_clut_index_width_u32 << 24u) | (0x00000008UL))));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORSHIFT, fl_clut_index_width_u32));
        }
        else
        {
            /* Since alpha bits are zero for non-APAL16 indexed images, there is no need to set COLORSHIFT for alpha channel */
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_src_surf, CYGFX_SM_ATTR_COLORBITS, (fl_clut_index_width_u32 << 24u)));
        }
        
        IRIS_API_CHECK(ret, CyGfx_SmPaletteAssign(fl_mml_gdc_src_surf, fl_pal_p));     
    }
 #endif
    if(ret==CYGFX_OK)
      {
        fl_fg_color = p_cntx_SP->rprop.fg_color;
        fl_rgba[0] = GM2_IRIS_R(fl_fg_color);  /* R */
        fl_rgba[1] = GM2_IRIS_G(fl_fg_color);  /* G */
        fl_rgba[2] = GM2_IRIS_B(fl_fg_color);  /* B */
        fl_rgba[3] = GM2_IRIS_A(fl_fg_color);  /* A */
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_src_surf));
        utMat3x3LoadIdentity(fl_matrix1);
        utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
        hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
        utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
        IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));

        if ((p_cntx_SP->state.alpha < 255) ||
          (fl_rgba[3] < 255) ||
          (fl_element_def_SP->format == CYGFX_SM_FORMAT_A8) ||
          (fl_element_def_SP->format == CYGFX_SM_FORMAT_A4) ||
          (fl_element_def_SP->format == CYGFX_SM_FORMAT_A2) ||
          (fl_element_def_SP->format == CYGFX_SM_FORMAT_A1))
        {
          fl_alpha_temp = ((UINT32)fl_rgba[3] * p_cntx_SP->state.alpha);
          fl_rgba[3] = (UINT8)(fl_alpha_temp / (UINT32)0xFF);
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
          IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
            CYGFX_BE_BM_GL_FUNC_ADD, \
            CYGFX_BE_BM_GL_FUNC_ADD, \
            CYGFX_BE_BM_GL_FUNC_ADD, \
            CYGFX_BE_BM_GL_FUNC_ADD));
          IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
            CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));
          /* Setting CYGFX_BE_SURF_ATTR_COLORMULTI as TRUE has been removed after Defect 1106955.By default it will be FALSE */
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
        }
        fl_tile_end_x = p_cntx_SP->state.loc.x + p_elem_def_SP->dim.width;
        fl_tile_end_y = p_cntx_SP->state.loc.y + p_elem_def_SP->dim.height;
        fl_img_height = fl_element_def_SP->height;
        for (fl_img_draw_y = p_cntx_SP->state.loc.y; fl_img_draw_y < (fl_tile_end_y); fl_img_draw_y += fl_img_height)
        {
          fl_img_width = fl_element_def_SP->width;
          if (fl_img_height <= (fl_tile_end_y - fl_img_draw_y))
          {
            fl_img_height = fl_img_height;
          }
          else
          {
            fl_img_height = fl_tile_end_y - fl_img_draw_y;
          }
          for (fl_img_draw_x = p_cntx_SP->state.loc.x; fl_img_draw_x < (fl_tile_end_x); fl_img_draw_x += fl_img_width)
          {
            if (fl_img_width <= (fl_tile_end_x - fl_img_draw_x))
            {
              fl_img_width = fl_img_width;
            }
            else
            {
              fl_img_width = fl_tile_end_x - fl_img_draw_x;
            }
            utMat3x3LoadIdentity(fl_matrix1);
            utMat3x3LoadIdentity(fl_matrix2);
            utMat3x3Translate(fl_matrix1, (GFX_FLOAT)fl_img_draw_x, (GFX_FLOAT)fl_img_draw_y);
            hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
            utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
            IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
            hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
          }
        }
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
      }
#ifdef GFX02_DEBUG_INFO
      else
      {
        gfx_debug("IrisEngine for Amber-I - Image Tile elem =%08X surface image buffer couldnot be assigned\n", p_elem_def_SP);
      }
#endif
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("IrisEngine for Amber-I  - Tile elem =%08X skipped\n", p_elem_def_SP);
    }
#endif
#endif

    if (ret == CYGFX_OK)
    {
      fl_return_value = TRUE;
    }
    return(fl_return_value);
  }
#endif

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
#ifndef GFX_STRING_CACHE_ENABLED
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_mt_fonts(UINT16                      p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE))
    , GFX_MGR02_SHAPE_INFO const* p_shaper_info
    , HMI_CHAR             const* p_string
#endif
  )
  {
#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE))
    /*If the scroll is enabled we need to take the original(full) string for processing*/
    GFX_MGR02_FONT const* fl_font_SP;
    HMI_CHAR const* fl_string_ptr = NULL;
    UINT32 fl_str_length = 0U;
    UINT16 fl_temp_width = 0U;
    UINT16 fl_displayed_width = 0xFFFFU; /*Invalid value*/
    UINT16 fl_textbox_width = p_text_info_SP->max_available_width;
    UINT8 fl_strIndex = 0U;
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
    BOOLEAN fl_thai_dev_lang = FALSE;
#endif
    UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id(p_elem_def_SP->font_id);
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
    if (GFX_MGR02_NULL_PTR != fl_font_SP)
    {
      FS_LONG err = 0;
      GFX_MGR02_CONTEXT_T* fl_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
      /* When the scroll_offset is > 0 then the length of the full string needs to be considered.*/
      /* So the fl_text_info_S is overwritten with the actual values from text buffer.     */
      FS_STATE* fl_client_state;
      fl_client_state = hmi_gfx_mgr02_get_mt_client_handler();
      if (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
      {
        (void)FS_set_font(fl_client_state, (FILECHAR*)fl_cntx_SP->rprop.mt_font_name[fl_font_id]);
      }
      /* Set the scale, we are assuming that xppem == yppem and no rotation   */
      /* or skewing. Note: ppem<<16 converts the specified ppem value into a  */
      /* 16.16 fixed point value.                                             */
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
      (void)FS_set_scale(fl_client_state, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size * 65536), 0, 0, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size * 65536));
#else
      (void)FS_set_scale(fl_client_state, (FS_LONG)(fl_font_SP->height_pts * 65536), 0, 0, (FS_LONG)(fl_font_SP->height_pts * 65536));
#endif
      /* set the cmap...                                                  */
      /* ...first try Windows Unicode with surrogates...                  */
      err = FS_set_cmap(fl_client_state, 3, 10);
      if (err != SUCCESS)
      {
        /* ...then try normal Windows Unicode                           */
        err = FS_set_cmap(fl_client_state, 3, 1);
        if (err != SUCCESS)
        {
          (void)FS_set_cmap(fl_client_state, 1, 0);
        }
      }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      if (p_shaper_info->shaper_out_ptr != GFX_MGR02_NULL_PTR)
      {
        (void)FS_set_flags(fl_client_state, FLAGS_CMAP_OFF);
      }
      else
      {
        (void)FS_set_flags(fl_client_state, FLAGS_CMAP_ON);
      }
#endif
      if (p_scroll_offset < p_text_info_SP->print_width)
      {
        UINT16 fl_last_char_width = 0U;
        FS_SHORT i_dx = 0;
        FS_SHORT i_dy = 0;
        FS_FIXED dx = 0;
        FS_FIXED dy = 0;
        UINT8 fl_break_loop = 0U;
        UINT32 fl_rem_str_length = p_text_info_SP->print_length_U8;
        fl_str_length = p_text_info_SP->print_length_U8;
        fl_string_ptr = p_text_info_SP->print_str_P;

        if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          if (p_text_info_SP->print_width >= p_scroll_offset)
          {
            if ((p_text_info_SP->print_width - p_scroll_offset) > fl_textbox_width)
            {
              *p_cur_scroll_offset = (p_text_info_SP->print_width) - (fl_textbox_width + p_scroll_offset);
            }
            else
            {
              fl_textbox_width = p_text_info_SP->print_width - p_scroll_offset;
              *p_cur_scroll_offset = 0U;
            }
          }
        }
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        {
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if ((hmi_gfx_mgr02_get_thai_char_count(p_string, (UINT16)fl_str_length) != 0U) ||
            (hmi_gfx_mgr02_get_devanagari_char_count(p_string, (UINT16)fl_str_length) != 0U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if (hmi_gfx_mgr02_get_thai_char_count(p_string, (UINT16)fl_str_length) != 0U)
#else
          if (hmi_gfx_mgr02_get_devanagari_char_count(p_string, (UINT16)fl_str_length) != 0U)
#endif
          {
            fl_thai_dev_lang = TRUE;
          }
        }
#endif
        /* When scroll is enabled then based on the scroll offset(p_start_x_offset) */
        /* the characters need to be removed from the beginning.                    */
        if (fl_rem_str_length > fl_strIndex)
        {
          (void)FS_get_advance(fl_client_state, fl_string_ptr[fl_strIndex], FS_MAP_GRAYMAP8, &i_dx, &i_dy, &dx, &dy);
          fl_last_char_width = (UINT16)i_dx;
        }
        while ((fl_rem_str_length > fl_strIndex) && (fl_string_ptr[fl_strIndex] != 0U))
        {
          fl_temp_width = fl_last_char_width + fl_font_SP->char_space;
          /*Here 0xFFFFU indicates non displayable region. This is added to calculate the start scroll offset
          by removing characters one by one. After the displayable character comes, fl_displayed_width will be
          changed to zero and then the actula width will be calculated*/
          if (fl_displayed_width == 0xFFFFU)
          {
            if (*p_cur_scroll_offset >= fl_temp_width)
            {
              fl_str_length--; /*Decrement the length of the string*/
              fl_strIndex++;   /*Move to the next char of the string*/
              *p_cur_scroll_offset = (*p_cur_scroll_offset) - fl_temp_width;
            }
            else
            {
              fl_displayed_width = 0U;
              /*Below code is to handle zero width character for arabic/thai language
              Arabic  -  Base character will come after the zwc. We need to print zwc character also since it will be
              printed on top of the base character. So below code added to move the string to the zwc location
              Thai    - We no need to any special handling since in Thai language, first base character will come and
              the zwc will come*/
#if (defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED))
              if (TRUE == fl_thai_dev_lang)
              {
                while ((fl_strIndex > 1U) && (fl_rem_str_length > fl_strIndex))
                {
                  (void)FS_get_advance(fl_client_state, fl_string_ptr[fl_strIndex], FS_MAP_GRAYMAP8, &i_dx, &i_dy, &dx, &dy);
                  fl_last_char_width = (UINT16)i_dx;
                  if (fl_last_char_width != 0U)
                  {
                    break;
                  }
                  fl_strIndex++;
                }
              }
#endif
              fl_string_ptr = &fl_string_ptr[fl_strIndex];
              fl_rem_str_length = fl_rem_str_length - fl_strIndex;
              fl_strIndex = 0U;
            }
          }
          else
          {
            fl_str_length--; /*Decrement the length of the string*/
            fl_strIndex++;   /*Move to the next char of the string*/
            if ((fl_displayed_width == 0U) && (fl_last_char_width != 0U))
            {
              fl_temp_width -= *p_cur_scroll_offset;
            }
            fl_displayed_width += (UINT16)(fl_temp_width);
            if (fl_displayed_width >= fl_textbox_width)
            {
              /*Calculate the width to of the text to be displayed based on scroll offset*/
              fl_displayed_width = fl_textbox_width;

              /*Below code is to handle zero width character for thai language
              Arabic  -  Mark(ZWC) character will come after base char. Based on the width of base char, we will
              skip the remaining character for further processing. But in case of Thai language, the mark char which
              comes after the base char also to be printed on top of the base. So below code added to move the string
              to the zwc location*/
#if (defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED))
              if (TRUE == fl_thai_dev_lang)
              {
                while ((fl_rem_str_length > fl_strIndex) && (fl_string_ptr[fl_strIndex] != 0U))
                {
                  (void)FS_get_advance(fl_client_state, fl_string_ptr[fl_strIndex], FS_MAP_GRAYMAP8, &i_dx, &i_dy, &dx, &dy);
                  fl_last_char_width = (UINT16)i_dx;
                  if (fl_last_char_width != 0U)
                  {
                    break;
                  }
                  fl_strIndex++;
                }
              }
#endif
              /* when the width of the characters to be displayed during scroll exceed the */
              /* text box width then the f1_scroll_end_offset is calculated and no more    */
              /* characters will be displayed by setting the fl_str_length to 0            */
              fl_str_length = 0U;
              fl_break_loop = 1U;
            }
          }
          if (fl_break_loop != 1U)
          {
            if (fl_str_length > 0U)
            {
              if (fl_strIndex < fl_str_length)
              {
                (void)FS_get_advance(fl_client_state, fl_string_ptr[fl_strIndex], FS_MAP_GRAYMAP8, &i_dx, &i_dy, &dx, &dy);
                fl_last_char_width = (UINT16)i_dx;
              }
            }
            else
            {
              /* when there are no more characters to be displayed and if the scroll offset  */
              /* is still greater than the last character's width then set the scroll offset */
              /* as 0 and the font pointer to NULL so that text will not be displayed.       */
              if (fl_strIndex >= fl_str_length)
              {
                fl_displayed_width = 0;
                fl_string_ptr = NULL;
              }
              fl_break_loop = 1U;
            }
          }

          if (fl_break_loop != 0U)
          {
            break;
          }
        }
        p_text_info_SP->print_width = fl_displayed_width;
      }
      else
      {
        p_text_info_SP->print_width = 0U;
      }
      p_text_info_SP->print_str_P = fl_string_ptr;
      p_text_info_SP->print_length_U8 = fl_strIndex;
    }
#endif 
  }
#endif

#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_ft_fonts(UINT16 p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
    , GFX_MGR02_SHAPE_INFO const* p_shaper_info
    , HMI_CHAR             const* p_string
#endif
  )
  {
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
    /*If the scroll is enabled we need to take the original(full) string for processing*/
    GFX_MGR02_FONT const* fl_font_SP;
    HMI_CHAR* fl_string_ptr = NULL;
    GFX_MGR02_HB_SHAPE_INFO* fl_shaper_ptr = GFX_MGR02_NULL_PTR;
    UINT8 fl_str_length = 0U;
    UINT16 fl_temp_width = 0U;
    UINT16 fl_displayed_width = 0xFFFFU; /*Invalid value*/
    UINT16 fl_textbox_width = p_text_info_SP->max_available_width;
    UINT8 fl_strIndex = 0U;
    hb_buffer_content_type_t fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
    SINT16 fl_current_x_advance = 0;
    BOOLEAN fl_complex_script = FALSE;
    if (p_shaper_info != GFX_MGR02_NULL_PTR)
    {
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      GFX_MGR02_TXT_SPECIAL_EFFECTS *fl_txt_special_prop_SP = GFX_MGR02_NULL_PTR;
      GFX_MGR02_TEXT_DYN_PROPERTY const* fl_text_anim_prop_S = GFX_MGR02_NULL_PTR;
      if (((UINT32)p_text_info_SP->dyn_text_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
      {
        UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((p_text_info_SP->dyn_text_def_SP->anim_id));
        UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_text_info_SP->dyn_text_def_SP->anim_id));

        if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
            (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
        {
          GFX_MGR02_ANIM_DATA_T *fl_anim_data = hmi_gfx_mgr02_layout_get_anim_data();
          fl_text_anim_prop_S = &fl_anim_data->text_prop[fl_prop_index_u32];
          fl_txt_special_prop_SP = (GFX_MGR02_TXT_SPECIAL_EFFECTS *)&fl_text_anim_prop_S->txt_special_effects;
        }
      }
#endif
      UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id(p_elem_def_SP->font_id);
      fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
      FT_Face          face = NULL;
      GFX_MGR02_CONTEXT_T const* fl_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
      if (GFX_MGR02_NULL_PTR != fl_font_SP)
      {
        face = fl_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
        if (p_scroll_offset < p_text_info_SP->print_width)
        {
          UINT16 fl_last_char_width = 0U;
          UINT8 fl_break_loop = 0U;
          UINT8 fl_rem_str_length = p_text_info_SP->print_length_U8;
          BOOLEAN fl_autohint_bool = hmi_gfx_mgr02_is_autohint_enabled(fl_font_id);
          fl_str_length = p_text_info_SP->print_length_U8;
          fl_string_ptr = (HMI_CHAR*)p_text_info_SP->print_str_P;
          if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
          {
            if (p_text_info_SP->print_width >= p_scroll_offset)
            {
              if ((p_text_info_SP->print_width - p_scroll_offset) > fl_textbox_width)
              {
                *p_cur_scroll_offset = (p_text_info_SP->print_width) - (fl_textbox_width + p_scroll_offset);
              }
              else
              {
                fl_textbox_width = p_text_info_SP->print_width - p_scroll_offset;
                *p_cur_scroll_offset = 0U;
              }
            }
          }
#if (defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED))
          {
            if (p_shaper_info->shaper_out_ptr != GFX_MGR02_NULL_PTR) /* we have glyph ids only.  */
            {
              /* Invoke shape engine if there any complex scripts */
              fl_shaper_ptr = (GFX_MGR02_HB_SHAPE_INFO*)p_shaper_info->shaper_out_ptr;
              if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
              {
                UINT32 fl_max_len = fl_shaper_ptr->glyph_count;
                UINT32 fl_index;
                if (fl_max_len > GFX_MGR02_MAX_TEXT_LENGTH)
                {
                  fl_max_len = GFX_MGR02_MAX_TEXT_LENGTH;
                }
                for (fl_index = 0; fl_index < fl_max_len; fl_index++)
                {
                  fl_string_ptr[fl_index] = fl_shaper_ptr->code_point[fl_index];
                }
                fl_string_ptr[fl_index] = (HMI_CHAR)0U;
                fl_rem_str_length = fl_shaper_ptr->glyph_count;
                fl_str_length = fl_rem_str_length;
              }
              fl_complex_script = TRUE;
            }
          }
#endif
          /* When scroll is enabled then based on the scroll offset(p_start_x_offset) */
          /* the characters need to be removed from the beginning.                    */
          if (fl_rem_str_length > fl_strIndex)
          {
            if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
            {
              fl_content_type = fl_shaper_ptr->content_type[fl_strIndex];
              fl_current_x_advance = fl_shaper_ptr->x_advance[fl_strIndex];
            }
            else
            {
              fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
              fl_current_x_advance = 0;
            }
            fl_last_char_width = hmi_gfx_mgr02_get_ft_char_width(face, fl_string_ptr[fl_strIndex], fl_autohint_bool
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
              , p_text_info_SP->font_pt_size, fl_font_id
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
              ,fl_txt_special_prop_SP
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              , fl_complex_script
              , fl_content_type
              , fl_current_x_advance
#endif
            );
          }
          while ((fl_rem_str_length > fl_strIndex) && (fl_string_ptr[fl_strIndex] != 0U))
          {
            fl_temp_width = fl_last_char_width;
            /*Here 0xFFFFU indicates non displayable region. This is added to calculate the start scroll offset
            by removing characters one by one. After the displayable character comes, fl_displayed_width will be
            changed to zero and then the actula width will be calculated*/
            if (fl_displayed_width == 0xFFFFU)
            {
              if (*p_cur_scroll_offset >= fl_temp_width)
              {
                fl_str_length--; /*Decrement the length of the string*/
                fl_strIndex++;   /*Move to the next char of the string*/
                *p_cur_scroll_offset = (*p_cur_scroll_offset) - fl_temp_width;
              }
              else
              {
                fl_displayed_width = 0U;
                /*Below code is to handle zero width character for arabic/thai language
                Arabic  -  Base character will come after the zwc. We need to print zwc character also since it will be
                printed on top of the base character. So below code added to move the string to the zwc location
                Thai    - We no need to any special handling since in Thai language, first base character will come and
                the zwc will come*/
#if (defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED))
                if (TRUE == fl_complex_script)
                {
                  while ((fl_strIndex > 1U) && (fl_rem_str_length > fl_strIndex))
                  {
                    if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
                    {
                      fl_content_type = fl_shaper_ptr->content_type[fl_strIndex];
                      fl_current_x_advance = fl_shaper_ptr->x_advance[fl_strIndex];
                    }
                    else
                    {
                      fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
                      fl_current_x_advance = 0;
                    }
                    fl_last_char_width = hmi_gfx_mgr02_get_ft_char_width(face, fl_string_ptr[fl_strIndex], fl_autohint_bool
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                      , p_text_info_SP->font_pt_size, fl_font_id
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                      ,fl_txt_special_prop_SP
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                      , fl_complex_script
                      , fl_content_type
                      , fl_current_x_advance
#endif
                    );
                    if (fl_last_char_width != 0U)
                    {
                      break;
                    }
                    fl_strIndex++;
                  }
                }
#endif
                fl_string_ptr = &fl_string_ptr[fl_strIndex];
                fl_rem_str_length = fl_rem_str_length - fl_strIndex;
                fl_strIndex = 0U;
              }
            }
            else
            {
              fl_str_length--; /*Decrement the length of the string*/
              fl_strIndex++;   /*Move to the next char of the string*/
              if ((fl_displayed_width == 0U) && (fl_last_char_width != 0U))
              {
                fl_temp_width -= *p_cur_scroll_offset;
              }
              fl_displayed_width += (UINT16)(fl_temp_width);
              if (fl_displayed_width >= fl_textbox_width)
              {
                /*Calculate the width to of the text to be displayed based on scroll offset*/
                fl_displayed_width = fl_textbox_width;

                /*Below code is to handle zero width character for thai language
                Arabic  -  Mark(ZWC) character will come after base char. Based on the width of base char, we will
                skip the remaining character for further processing. But in case of Thai language, the mark char which
                comes after the base char also to be printed on top of the base. So below code added to move the string
                to the zwc location*/
#if (defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED))
                if (TRUE == fl_complex_script)
                {
                  while ((fl_rem_str_length > fl_strIndex) && (fl_string_ptr[fl_strIndex] != 0U))
                  {
                    if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
                    {
                      fl_content_type = fl_shaper_ptr->content_type[fl_strIndex];
                      fl_current_x_advance = fl_shaper_ptr->x_advance[fl_strIndex];
                    }
                    else
                    {
                      fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
                      fl_current_x_advance = 0;
                    }
                    fl_last_char_width = hmi_gfx_mgr02_get_ft_char_width(face, fl_string_ptr[fl_strIndex], fl_autohint_bool
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                      , p_text_info_SP->font_pt_size, fl_font_id
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                      , fl_txt_special_prop_SP
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                      , fl_complex_script
                      , fl_content_type
                      , fl_current_x_advance
#endif
                    );
                    if (fl_last_char_width != 0U)
                    {
                      break;
                    }
                    fl_strIndex++;
                  }
                }
#endif
                /* when the width of the characters to be displayed during scroll exceed the */
                /* text box width then the f1_scroll_end_offset is calculated and no more    */
                /* characters will be displayed by setting the fl_str_length to 0            */
                fl_str_length = 0U;
                fl_break_loop = 1U;
              }
            }
            if (fl_break_loop != 1U)
            {
              if (fl_str_length > 0U)
              {
                if (fl_strIndex < fl_rem_str_length)
                {
                  if (fl_shaper_ptr != GFX_MGR02_NULL_PTR)
                  {
                    fl_content_type = fl_shaper_ptr->content_type[fl_strIndex];
                    fl_current_x_advance = fl_shaper_ptr->x_advance[fl_strIndex];
                  }
                  else
                  {
                    fl_content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
                    fl_current_x_advance = 0;
                  }
                  fl_last_char_width = hmi_gfx_mgr02_get_ft_char_width(face, fl_string_ptr[fl_strIndex], fl_autohint_bool
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                    , p_text_info_SP->font_pt_size, fl_font_id
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                    ,fl_txt_special_prop_SP
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                    , fl_complex_script
                    , fl_content_type
                    , fl_current_x_advance
#endif
                  );
                }
              }
              else
              {
                /* when there are no more characters to be displayed and if the scroll offset  */
                /* is still greater than the last character's width then set the scroll offset */
                /* as 0 and the font pointer to NULL so that text will not be displayed.       */
                if ((fl_strIndex >= fl_str_length)  && (fl_strIndex !=fl_rem_str_length))
                {
                  fl_displayed_width = 0;
                  fl_string_ptr = NULL;
                }
                fl_break_loop = 1U;
              }
            }

            if (fl_break_loop != 0U)
            {
              break;
            }
          }
          p_text_info_SP->print_width = fl_displayed_width;
        }
        else
        {
          p_text_info_SP->print_width = 0U;
        }
        p_text_info_SP->print_str_P = fl_string_ptr;
        p_text_info_SP->print_length_U8 = fl_strIndex;
      }
    }
#endif 
  } //#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) &&(GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
#endif //#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
#if (!defined(GFX_MGR02_USE_EXT_FONT_ENGINE))
  static void hmi_gfx_mgr02_amber_update_text_for_scroll_win_fonts(HMI_CHAR               const* p_string,
    UINT16                        p_scroll_offset,
    UINT16* p_cur_scroll_offset,
    GFX_MGR02_TEXT_INFO* p_text_info_SP,
    GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
    GFX_UINT                    p_alignment
  )
  {
    /*If the scroll is enabled we need to take the original(full) string for processing*/
    HMI_CHAR const* f1_scroll_print_str_P = p_string;
    GFX_MGR02_FONT const* fl_font_SP;
    GFX_MGR02_FONT_CHAR_CONFIG const* fl_font_fcc_SP;
    HMI_CHAR const* fl_string_ptr = NULL;
    UINT32 fl_str_length = 0U;
    UINT16 fl_temp_width = 0U;
    UINT16 fl_displayed_width = 0xFFFFU; /*Invalid value*/
    UINT16 fl_textbox_width = p_text_info_SP->max_available_width;
    UINT8 fl_strIndex = 0U;
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
    BOOLEAN fl_thai_dev_lang = FALSE;
#endif
#endif
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer((UINT32)p_elem_def_SP->font_id);

    if (GFX_MGR02_NULL_PTR != fl_font_SP)
    {
      /* When the scroll_offset is > 0 then the length of the full string needs to be considered.*/
      /* So the fl_text_info_S is overwritten with the actual values from text buffer.     */
      p_text_info_SP->print_str_P = f1_scroll_print_str_P;
      p_text_info_SP->print_length_U8 = 0U;
      p_text_info_SP->print_width = 0U;
      while (f1_scroll_print_str_P[0] != 0U)
      {
        /* Dynamic set font not applicable as it is external font engine. */
        fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(f1_scroll_print_str_P[0], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table,
#if defined(GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
          (UINT32)p_elem_def_SP->font_id,
#endif
          (UINT32)FALSE);
        if (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
        {
          p_text_info_SP->print_width = (p_text_info_SP->print_width) + (UINT16)(fl_font_fcc_SP->owidth);
        }
        p_text_info_SP->print_length_U8++;
        f1_scroll_print_str_P++;
        if((fl_font_fcc_SP != GFX_MGR02_NULL_PTR) && (f1_scroll_print_str_P[0] != 0U))
        {
          p_text_info_SP->print_width += fl_font_SP->char_space;
        }
      }
      if (p_scroll_offset < p_text_info_SP->print_width)
      {
        fl_str_length = p_text_info_SP->print_length_U8;
        fl_string_ptr = p_text_info_SP->print_str_P;

        fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table,
#if defined(GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
          (UINT32)p_elem_def_SP->font_id,
#endif
          (UINT32)FALSE);

        if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          if (p_text_info_SP->print_width >= p_scroll_offset)
          {
            if ((p_text_info_SP->print_width - p_scroll_offset) > fl_textbox_width)
            {
              *p_cur_scroll_offset = (p_text_info_SP->print_width) - (fl_textbox_width + p_scroll_offset);
            }
            else
            {
              fl_textbox_width = p_text_info_SP->print_width - p_scroll_offset;
              *p_cur_scroll_offset = 0U;
            }
          }
        }
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        if ((hmi_gfx_mgr02_get_thai_char_count(fl_string_ptr, (UINT16)fl_str_length) != 0U) ||
          (hmi_gfx_mgr02_get_devanagari_char_count(fl_string_ptr, (UINT16)fl_str_length) != 0U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
        if (hmi_gfx_mgr02_get_thai_char_count(fl_string_ptr, (UINT16)fl_str_length) != 0U)
#else
        if (hmi_gfx_mgr02_get_devanagari_char_count(fl_string_ptr, (UINT16)fl_str_length) != 0U)
#endif
        {
          fl_thai_dev_lang = (UINT8)TRUE;
        }
#endif
#endif
        /* When scroll is enabled then based on the scroll offset(p_start_x_offset) */
        /* the characters need to be removed from the beginning.                    */
        while (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
        {
          fl_temp_width = (UINT16)(fl_font_fcc_SP->owidth + fl_font_SP->char_space);
          /*Here 0xFFFFU indicates non displayable region. This is added to calculate the start scroll offset
          by removing characters one by one. After the displayable character comes, fl_displayed_width will be
          changed to zero and then the actula width will be calculated*/
          if (fl_displayed_width == 0xFFFFU)
          {
            if (*p_cur_scroll_offset >= fl_temp_width)
            {
              fl_str_length--; /*Decrement the length of the string*/
              fl_strIndex++;   /*Move to the next char of the string*/
              *p_cur_scroll_offset = (*p_cur_scroll_offset) - fl_temp_width;
            }
            else
            {
              fl_displayed_width = 0U;
              /*Below code is to handle zero width character for arabic/thai language
              Arabic  -  Base character will come after the zwc. We need to print zwc character also since it will be
              printed on top of the base character. So below code added to move the string to the zwc location
              Thai    - We no need to any special handling since in Thai language, first base character will come and
              the zwc will come*/
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
              if ((UINT8)FALSE == fl_thai_dev_lang)
#endif
              {
                while (fl_strIndex > 1U)
                {
                  GFX_MGR02_FONT_CHAR_CONFIG const* fl_font_temp_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[fl_strIndex - 1U], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table,
#if defined(GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                    (UINT32)p_elem_def_SP->font_id,
#endif
                    (UINT32)FALSE);
                  if ((fl_font_temp_SP != GFX_MGR02_NULL_PTR) && (fl_font_temp_SP->owidth != 0U))
                  {
                    break;
                  }
                  fl_strIndex--;
                }
              }
#endif
              fl_string_ptr = &fl_string_ptr[fl_strIndex];
              fl_strIndex = 0U;
            }
          }
          else
          {
            fl_str_length--; /*Decrement the length of the string*/
            fl_strIndex++;   /*Move to the next char of the string*/
            if ((fl_displayed_width == 0U) && (fl_font_fcc_SP->owidth != 0U))
            {
              fl_temp_width -= *p_cur_scroll_offset;
            }
            fl_displayed_width += (UINT16)(fl_temp_width);
            if (fl_displayed_width >= fl_textbox_width)
            {
              /*Calculate the width to of the text to be displayed based on scroll offset*/
              fl_displayed_width = fl_textbox_width;

              /*Below code is to handle zero width character for thai language
              Arabic  -  Mark(ZWC) character will come after base char. Based on the width of base char, we will
              skip the remaining character for further processing. But in case of Thai language, the mark char which
              comes after the base char also to be printed on top of the base. So below code added to move the string
              to the zwc location*/
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
              if ((UINT8)TRUE == fl_thai_dev_lang)
              {
                while (fl_string_ptr[fl_strIndex] != 0U)
                {
                  GFX_MGR02_FONT_CHAR_CONFIG const* fl_font_temp_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[fl_strIndex], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table,
#if defined(GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                    (UINT32)p_elem_def_SP->font_id,
#endif
                    (UINT32)FALSE);
                  if ((fl_font_temp_SP != GFX_MGR02_NULL_PTR) && (fl_font_temp_SP->owidth != 0U))
                  {
                    break;
                  }
                  fl_strIndex++;
                }
              }
#endif
#endif
              /* when the width of the characters to be displayed during scroll exceed the */
              /* text box width then the f1_scroll_end_offset is calculated and no more    */
              /* characters will be displayed by setting the fl_str_length to 0            */
              fl_str_length = 0U;
            }
          }

          if (fl_str_length > 0U)
          {
            if (fl_strIndex < fl_str_length)
            {
              fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[fl_strIndex], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table,
#if defined(GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                (UINT32)p_elem_def_SP->font_id,
#endif
                (UINT32)FALSE);
            }
          }
          else
          {
            /* when there are no more characters to be displayed and if the scroll offset  */
            /* is still greater than the last character's width then set the scroll offset */
            /* as 0 and the font pointer to NULL so that text will not be displayed.       */
            fl_font_fcc_SP = GFX_MGR02_NULL_PTR;
          }
        }
        p_text_info_SP->print_width = fl_displayed_width;
      }
      else
      {
        p_text_info_SP->print_width = 0U;
      }
      p_text_info_SP->print_str_P = fl_string_ptr;
      p_text_info_SP->print_length_U8 = fl_strIndex;
    }
  }
#endif
#endif /* GFX_STRING_CACHE_ENABLED */
  static void hmi_gfx_mgr02_amber_update_text_for_scroll(HMI_CHAR const* p_string,
    UINT16 p_scroll_offset,
    UINT16* p_cur_scroll_offset
    , GFX_MGR02_TEXT_INFO* p_text_info_SP
    , GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP
#ifndef  GFX_STRING_CACHE_ENABLED
    , GFX_UINT p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
    , GFX_MGR02_SHAPE_INFO const* p_shaper_info
#endif
#endif
  )
  {
    if ((p_string != NULL) && (p_string[0] != (HMI_CHAR)'\0'))
    {
      if (p_text_info_SP->print_width > p_text_info_SP->max_available_width)
      {
        if (p_scroll_offset < ((p_text_info_SP->print_width - p_text_info_SP->max_available_width) + ((GFX_MGR02_SCROLL_PADDING_PERCENTAGE* p_elem_def_SP->width)/100U)))
        {
          *p_cur_scroll_offset = p_scroll_offset;
#ifndef GFX_STRING_CACHE_ENABLED
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          hmi_gfx_mgr02_amber_update_text_for_scroll_mt_fonts(p_scroll_offset, p_cur_scroll_offset, p_text_info_SP, p_elem_def_SP, p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE))
        , p_shaper_info, p_string
#endif
          );
#endif
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)

          hmi_gfx_mgr02_amber_update_text_for_scroll_ft_fonts(p_scroll_offset, p_cur_scroll_offset, p_text_info_SP, p_elem_def_SP, p_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
        , p_shaper_info, p_string
#endif
          );

#endif
#else /* Windows bitmap font  */
          hmi_gfx_mgr02_amber_update_text_for_scroll_win_fonts(p_string, p_scroll_offset, p_cur_scroll_offset, p_text_info_SP, p_elem_def_SP, p_alignment);
#endif
#endif /* GFX_STRING_CACHE_ENABLED */
        }
        else
        {
          *p_cur_scroll_offset = ((p_text_info_SP->print_width - p_text_info_SP->max_available_width) + ((GFX_MGR02_SCROLL_PADDING_PERCENTAGE* p_elem_def_SP->width)/100U));
          hmi_gfx_mgr02_layout_stop_scroll((GFX_MGR02_ANIM_ELEM_ID)p_elem_def_SP->anim_id);

#if defined(GFX_MGR02_SCROLL_COMPLETE_CB)
          GFX_MGR02_SCROLL_COMPLETE_CB(p_elem_def_SP->anim_id);
#endif
        }
      }
    }
  }
#endif /* GFX_MGR02_HORIZONTAL_SCROLL_ENABLED */

  s_gx_flocal hmi_gfx_mgr02_tv2_build_text(GFX_MGR02_CONTEXT_T   const* p_cntx_SP,
    GFX_MGR02_TEXT_DEF_T   const* p_elem_def_SP,
    HMI_CHAR const* p_string,
    u_gx_flocal p_text_actual_width
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
    , u_gx_flocal p_is_multi_line_text
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    , UINT16 p_ml_str_index
#endif
#endif
  )
  {
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    static HMI_CHAR l_irislib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH + 1];
    UINT8 fl_scale_down = 100U;
#endif
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_SM_FORMAT    fl_surf_format;
    GFX_MGR02_FONT const* fl_font_SP;
    HMI_CHAR       const* fl_string_ptr = NULL;
    HMI_CHAR       const* fl_print_str = NULL;
    UINT32                 fl_str_length = 0UL;
    UINT16                 fl_text_width;
    UINT32 fl_alpha_temp;
    SINT32 ret = CYGFX_OK;
    SINT32 fl_txtbox_strt_x;
    GFX_UINT fl_alignment = p_cntx_SP->rprop.alignment;
    UINT32 fl_font_id;
    CYGFX_FLOAT fl_glyph_draw_x;
    UINT16 fl_full_text_width = 0U;
#ifdef GFX_STRING_CACHE_ENABLED 
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    UINT8 fl_shaping_required = 0U;
    GFX_STRING_CACHE_INFO fl_str_cache_info = {0};
    GFX_MGR02_ISIZE_W_T fl_text_box_width = p_cntx_SP->rprop.text_width;
#endif
#endif
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && defined(GFX_MGR02_TXT_EFFECTS_ENABLED))
    GFX_MGR02_TXT_SPECIAL_EFFECTS *fl_txt_special_prop_SP = GFX_MGR02_NULL_PTR;
#endif
    UINT8  fl_text_BPP;
#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)
    UINT8  fl_use_ttf_engine;
#else
#ifndef GFX_STRING_CACHE_ENABLED
    UINT8  fl_use_ttf_engine = (UINT8)0;
#endif
#endif    
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    GFX_MGR02_SHAPE_FLAGS fl_shape_flags1;
    GFX_MGR02_SHAPE_FLAGS* fl_shape_flags;
    GFX_MGR02_SHAPE_ML_DATA* fl_ML_data_ptr = GFX_MGR02_NULL_PTR;
#endif
#endif
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    UINT16 fl_scroll_offset = 0U;
    BOOLEAN fl_scroll_enabled = hmi_gfx_mgr02_layout_get_text_scroll_status((GFX_MGR02_ANIM_ELEM_ID)p_elem_def_SP->anim_id);
#endif
    if ((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)
#if(GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_MONOTYPE) || defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
      const GFX_MGR02_FONT_SIZE_T* fl_font_size_SP = &(p_cntx_SP->rprop.font_size);
#endif
#endif

      fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
      fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && defined(GFX_MGR02_TXT_EFFECTS_ENABLED))
          fl_txt_special_prop_SP = GFX_MGR02_NULL_PTR;
          GFX_MGR02_TEXT_DYN_PROPERTY const *fl_text_anim_prop_S = GFX_MGR02_NULL_PTR;
          if (((UINT32)p_elem_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
          {
            UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((p_elem_def_SP->anim_id));
            UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_elem_def_SP->anim_id));

            if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) && (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
            {
              GFX_MGR02_ANIM_DATA_T *fl_anim_data_SP = hmi_gfx_mgr02_layout_get_anim_data();
              fl_text_anim_prop_S = &fl_anim_data_SP->text_prop[fl_prop_index_u32];
              if (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
              {
                fl_txt_special_prop_SP = (GFX_MGR02_TXT_SPECIAL_EFFECTS *)&fl_text_anim_prop_S->txt_special_effects;
              }
            }
          }
#endif
      if (fl_font_SP != GFX_MGR02_NULL_PTR)
      {
        GFX_MGR02_TEXT_INFO fl_text_info_S;

        fl_text_info_S.print_str_P = p_string;
        fl_text_info_S.max_available_width = p_cntx_SP->rprop.text_width;
        fl_text_info_S.print_length_U8 = 0U;
        fl_text_info_S.print_width = 0U;
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
        fl_text_info_S.pre_render_index = p_cntx_SP->rprop.pre_render_index;
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        if (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
        {
          fl_text_info_S.max_available_width = (fl_text_info_S.max_available_width * 100U) / p_cntx_SP->rprop.max_shrink;
        }
#endif
        fl_text_info_S.dyn_text_def_SP = p_elem_def_SP;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)|| (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) ||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))
        fl_text_info_S.font_pt_size = p_cntx_SP->rprop.font_size.point_size;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
        fl_text_info_S.is_complex = 0U;
        fl_text_info_S.str_offset_idx = 0U;

        fl_shape_flags1.char_flag = 1U;
        fl_shape_flags1.complexity_flag = 0U;
        fl_shape_flags1.current_str_index = 0U;
        fl_shape_flags1.unique_fntid_flag = 0;
#endif 
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        if (p_is_multi_line_text != FALSE)
        {
          fl_text_info_S.append_str = (UINT8)FALSE;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          hmi_gfx_mgr02_get_shaping_flags(p_elem_def_SP, p_string, (u_gx_flocal)p_ml_str_index, &fl_shape_flags1);

          fl_text_info_S.append_str = (UINT8)FALSE;
          fl_text_info_S.is_complex = fl_shape_flags1.complexity_flag;
          fl_text_info_S.str_offset_idx = p_ml_str_index;

          fl_ML_data_ptr = &l_shape_ml_dtext_buffer[p_elem_def_SP->ml_string_index];
#endif
        }
        else
#endif
        {
          fl_text_info_S.append_str = (UINT8)TRUE;
        }
        l_irislib_clip_text_str[0] = 0;
#else
        fl_text_info_S.append_str = (UINT8)FALSE;
#endif
        fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
        fl_text_info_S.dyn_text_def_SP = p_elem_def_SP;
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
        fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
        fl_shape_flags = &fl_shape_flags1;
#endif
#if defined(GFX_STRING_CACHE_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
        fl_shaping_required = p_cntx_SP->rprop.shaping_required;
        if (fl_shaping_required == (UINT8)(FALSE))
        {
          UINT8                 fl_string_found = (UINT8)FALSE;
          fl_str_length = (UINT8)HMI_STRLEN(p_string);
          if (fl_str_length > (UINT8)GFX_MGR02_MAX_TEXT_LENGTH)
          {
            fl_str_length = (UINT8)GFX_MGR02_MAX_TEXT_LENGTH;
          }

          (void)HMI_STRNCPY(fl_str_cache_info.InString, p_string, (UINT32)(fl_str_length));
          fl_str_cache_info.InString[fl_str_length] = (HMI_CHAR)'\0';
          fl_str_cache_info.FontId = fl_font_id;
          fl_str_cache_info.TextBoxWidth = fl_text_box_width;
          fl_str_cache_info.ClipMode = (UINT8)p_cntx_SP->rprop.clip_mode;
          fl_str_cache_info.Alignment = (UINT8)p_cntx_SP->rprop.alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          if(p_cntx_SP->rprop.scroll_offset > 0U)
          {
            fl_str_cache_info.isScrolled = TRUE;
          }
          else
          {
            fl_str_cache_info.isScrolled = FALSE;
          }
#endif  
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
          fl_str_cache_info.FontSize = p_cntx_SP->rprop.font_size.point_size;
#else
          fl_str_cache_info.FontSize = fl_font_SP->p.height;
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          fl_str_cache_info.MaxShrink = p_cntx_SP->rprop.max_shrink;
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
          if (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
          { 
              fl_str_cache_info.special_effects.effect_type = fl_text_anim_prop_S->txt_special_effects.effect_type;
          }
          else
          {
            fl_str_cache_info.special_effects.effect_type = GFX_MGR02_TXT_INVALID_EFFECT;
          }
#endif
          fl_string_found = hmi_gfx_mgr02_get_string_cache_info(&fl_str_cache_info);
          if (fl_string_found == (UINT8)FALSE)
          {
            fl_shaping_required = (UINT8)TRUE;
          }
          else
          {
            fl_text_info_S.print_width = fl_str_cache_info.bmpWidth;
            fl_text_info_S.print_str_P = fl_str_cache_info.String;
            fl_text_info_S.print_length_U8 = fl_str_cache_info.StringLen;
          }
        }
        if (fl_shaping_required == (UINT8)TRUE)
#endif
#endif
        {
          (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
            (UINT32)p_cntx_SP->rprop.font_id,
            (UINT32)p_cntx_SP->rprop.clip_mode,
            (UINT32)p_cntx_SP->rprop.alignment
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            , l_irislib_clip_text_str
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            , &l_shaper_info
#endif
          );
        }
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        if (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
        {
          if (p_cntx_SP->rprop.text_width < fl_text_info_S.print_width)
          {
            GFX_FLOAT fl_scale_down_matrix[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
            fl_scale_down = (UINT8)((p_cntx_SP->rprop.text_width * 100U) / fl_text_info_S.print_width);
            if ((fl_scale_down % 5U) != 0U)
            {
              fl_scale_down = (fl_scale_down / 5U) * 5U;
            }
            utMat3x3LoadIdentity(fl_scale_down_matrix);
            fl_scale_down_matrix[0] = ((GFX_FLOAT)fl_scale_down / (GFX_FLOAT)100);
            hmi_gfx_mgr02_context_set_matrix((GFX_FLOAT const*)fl_scale_down_matrix);
            hmi_gfx_mgr02_context_set_text_width((p_cntx_SP->rprop.text_width * (UINT16)100) / fl_scale_down);
          }
          else
          {
            fl_scale_down = (UINT8)100;
          }
        }
#endif

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
        if (p_is_multi_line_text == FALSE)/*Below scroll functionality is not applicable for Multiline text*/
#endif
        {
          /*Forcefully changing alignment to left for scollable text.*/
          if (p_cntx_SP->rprop.scroll_offset > 0U)
          {
            HMI_CHAR const* fl_full_string;
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
            fl_full_string = fl_text_info_S.print_str_P;
#else
            fl_full_string = p_string;
#endif
            if ((fl_scroll_enabled == TRUE) && (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE) && (fl_text_info_S.print_width > p_elem_def_SP->width))
            {
              fl_alignment = GFX_MGR02_TP_ALIGN_LEFT;
            }
            hmi_gfx_mgr02_amber_update_text_for_scroll(fl_full_string, p_cntx_SP->rprop.scroll_offset, &fl_scroll_offset
              , &fl_text_info_S, p_elem_def_SP
#ifndef  GFX_STRING_CACHE_ENABLED
              , fl_alignment
#if (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
              , &l_shaper_info
#endif
#endif
            );
          }
        }
#endif

#if (defined(GFX_MGR02_CLIP_TEXT_ENABLE))
#if (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED) && defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_BMPFONT) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
        if (fl_scroll_enabled == TRUE)
        {
          fl_print_str = fl_text_info_S.print_str_P;
        }
        else
#endif
        {
          fl_print_str = l_irislib_clip_text_str;
        }
#else
        fl_print_str = fl_text_info_S.print_str_P;
#endif
        fl_string_ptr = fl_print_str;
        fl_text_width = fl_text_info_S.print_width;
        fl_full_text_width = fl_text_info_S.print_width;
        fl_str_length = fl_text_info_S.print_length_U8;
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) &&((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
        fl_text_BPP = fl_font_SP->bpp;
#else
        fl_text_BPP = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);
#endif
      }
      else
      {
        fl_text_width = (UINT16)0;
      }
      if (fl_text_width > (UINT16)0)
      {
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
        FS_STATE* fl_client_state = GFX_MGR02_NULL_PTR;
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
        GFX_MGR02_TXT_SPECIAL_EFFECTS* fl_txt_special_prop_SP = GFX_MGR02_NULL_PTR;
        SINT32          fl_total_draw_count = 1;
        UINT8           fl_effect_type = GFX_MGR02_TXT_INVALID_EFFECT;
        SINT32          fl_state_loc_x;
        SINT32          fl_state_loc_y;
        GFX_MGR02_CONTEXT_T* fl_cntx_SP;
#endif
#endif

#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)
        fl_use_ttf_engine = fl_font_SP->is_ffile;
        if (fl_use_ttf_engine != (UINT8)0)
        {
#if(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
          fl_client_state = (FS_STATE*)&p_cntx_SP->rprop.mt_fs_state;
          /* Set this font as the font to be used.                                */
          IRIS_API_CHECK(ret, FS_set_font(fl_client_state, (FILECHAR*)p_cntx_SP->rprop.mt_font_name[fl_font_id]));
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            /* set the flag so that get_glyph functions will turn off cmap      */
            (void)FS_set_flags(fl_client_state, FLAGS_CMAP_OFF);
          }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
          else
          {
            if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE))
            {
              /* set the flag so that get_glyph functions will turn off cmap      */
              (void)FS_set_flags(fl_client_state, FLAGS_CMAP_OFF);
            }
          }
#endif
#endif

#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
          /* By default no special effects */
          IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_NO_EFFECT));
          if (((UINT32)p_elem_def_SP->anim_id & GFX_MGR02_ATTRIB_MASK) == GFX_MGR02_ATTRIB_DYN_PROPERTY)
          {
            UINT32 fl_obj_type = GFX_MGR02_GET_OBJ_TYPE((p_elem_def_SP->anim_id));
            UINT32 fl_prop_index_u32 = GFX_MGR02_GET_OBJ_ID((p_elem_def_SP->anim_id));
            GFX_MGR02_TEXT_DYN_PROPERTY const* fl_text_anim_prop_S;

            if ((fl_obj_type == GFX_MGR02_TYPE_DTEXT) &&
              (fl_prop_index_u32 < (UINT32)GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS))
            {
              GFX_MGR02_ANIM_DATA_T* fl_anim_data_SP = hmi_gfx_mgr02_layout_get_anim_data();
              fl_text_anim_prop_S = &fl_anim_data_SP->text_prop[fl_prop_index_u32];
              if (fl_text_anim_prop_S != GFX_MGR02_NULL_PTR)
              {
                fl_txt_special_prop_SP = (GFX_MGR02_TXT_SPECIAL_EFFECTS*)&fl_text_anim_prop_S->txt_special_effects;
              }
            }

          }
          /****************** TEXT SPECIAL EFFECTS PROPERTIES UPDATE *********************/
          if (fl_txt_special_prop_SP != GFX_MGR02_NULL_PTR)
          {
            fl_effect_type = fl_txt_special_prop_SP->effect_type;
            if (fl_effect_type == GFX_MGR02_TXT_SOFTEND_EFFECT)
            {
              /* Softened effect (Softened appearance of graymap) */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_SOFTENED_ON));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_OTL_UNFILL_EFFECT)
            {
              /* No outline filled */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_OUTLINED_UNFILLED));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_EMBOSSED_EFFECT)
            {
              /* Normal text with Embossed (Edge effect with a raised appearance)*/
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_EMBOSSED));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_ENGRAVED_EFFECT)
            {
              /* Normal text with Engraved effect (Edge effect with a depressed appearance)*/
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_ENGRAVED));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT)
            {
              /* Glow effect with no outline filled */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_OUTLINED_UNFILLED));
              IRIS_API_CHECK(ret, FS_set_outline_width(fl_client_state, (fl_txt_special_prop_SP->otl_width)));
              IRIS_API_CHECK(ret, FS_set_outline_opacity(fl_client_state, (FS_FIXED)((fl_txt_special_prop_SP->otl_opacity) * 65536)));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT)
            {
              /* Normal text with glow effect */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_OUTLINED_SOFT));
              IRIS_API_CHECK(ret, FS_set_outline_width(fl_client_state, (fl_txt_special_prop_SP->otl_width)));
              IRIS_API_CHECK(ret, FS_set_outline_opacity(fl_client_state, (FS_FIXED)((fl_txt_special_prop_SP->otl_opacity) * 65536)));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
            {
              /* Normal text with Bold effect*/
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_REGULARBOLD_ON));
              IRIS_API_CHECK(ret, FS_set_bold_pct(fl_client_state, (FS_FIXED)((fl_txt_special_prop_SP->bold_percentage) * 65536)));
            }
            else if (fl_effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT)
            {
              /* Remove shadow width from the available width so that shadow effect can embedd within it */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_NO_EFFECT));
              if (p_cntx_SP->rprop.draw_mode == GFX_MGR02_TP_DRAW_TRANSP)
              {
                fl_total_draw_count = 2;
              }
              else
              {
                /* Drop shadow effect will not work for non-transparent draw mode */
                fl_total_draw_count = 1;
              }
            }
            else
            {
              /* Drop shadow effect can be achieve by setting no flags and drawring bg and fg separately */
              /* No special effects */
              /* For normal text */
              IRIS_API_CHECK(ret, FS_set_flags(fl_client_state, FLAGS_NO_EFFECT));
            }
            /************ END OF TEXT SPECIAL EFFECTS PROPERTIES UPDATE *********************/
          }
#endif /* #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)  */
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
          /* Set the scale, we are assuming that xppem == yppem and no rotation   */
          /* or skewing. Note: ppem<<16 converts the specified ppem value into a  */
          /* 16.16 fixed point value.                                             */
          IRIS_API_CHECK(ret, FS_set_scale(fl_client_state, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size * 65536), 0, 0, (FS_LONG)(p_cntx_SP->rprop.font_size.point_size * 65536)));
#else
          IRIS_API_CHECK(ret, FS_set_scale(fl_client_state, (FS_LONG)(fl_font_SP->height_pts * 65536), 0, 0, (FS_LONG)(fl_font_SP->height_pts * 65536)));
#endif
          /* Set the character mapping, here we expect that the font being used   */
          /* will have a Unicode cmap table as indicated by the 3,1 arguments.    */
          IRIS_API_CHECK(ret, FS_set_cmap(fl_client_state, (FS_USHORT)3, (FS_USHORT)10));
          if (ret != SUCCESS)
          {
            IRIS_API_CHECK(ret, FS_set_cmap(fl_client_state, (FS_USHORT)3, (FS_USHORT)1));
            if (ret != SUCCESS)
            {
              IRIS_API_CHECK(ret, FS_set_cmap(fl_client_state, (FS_USHORT)1, (FS_USHORT)0));
            }
          }
#endif
        }
#endif
#if ((defined(GFX_MGR02_TXT_EFFECTS_ENABLED)) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
        UINT8   fl_current_draw_cnt;
#ifndef GFX_STRING_CACHE_ENABLED
        UINT32  fl_str_length_bkp;
#endif
        /* If drop shadow is enabled then we have to draw the string 2 times
        ** 1 with shadow background and another with foreground of text color
        */
        for (fl_current_draw_cnt = 0U; fl_current_draw_cnt < fl_total_draw_count; fl_current_draw_cnt++)
#endif
        {
          CYGFX_SURFACE_OBJECT_S fl_mml_gdc_txt_surf_c;
          CYGFX_SURFACE           fl_mml_gdc_txt_surf;

          UINT32 fl_fg_color;
          UINT32 fl_bg_color;
          SINT32 fl_start_x;
          SINT32 fl_pivot_offset;
          UINT8  fl_bgfill_color[4];
          UINT8  fl_draw_color[4];
          UINT8  fl_draw_mode;
#ifdef GFX_STRING_CACHE_ENABLED
          void* fl_str_img_data;
#endif
          fl_fg_color = p_cntx_SP->rprop.fg_color;
#if ((defined(GFX_MGR02_TXT_EFFECTS_ENABLED)) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
          if ((fl_current_draw_cnt == 0) && (fl_total_draw_count == 2))
          {
            /* First draw shadow text with shadow color */
            fl_state_loc_x = p_cntx_SP->state.loc.x;
            fl_state_loc_y = p_cntx_SP->state.loc.y;
            fl_fg_color = fl_txt_special_prop_SP->shadow_bg_col;
            fl_cntx_SP = (GFX_MGR02_CONTEXT_T*)p_cntx_SP;
            (fl_cntx_SP->state.loc.x) = (p_cntx_SP->state.loc.x + fl_txt_special_prop_SP->shadow_x);
            (fl_cntx_SP->state.loc.y) = (p_cntx_SP->state.loc.y + fl_txt_special_prop_SP->shadow_y);
#ifndef GFX_STRING_CACHE_ENABLED
            fl_str_length_bkp = fl_str_length;
#endif
          }
          else
          {
            if ((fl_current_draw_cnt == 1) && (fl_total_draw_count == 2))
            {
              /* Now draw text actual draw color */
              fl_fg_color = p_cntx_SP->rprop.fg_color;
              (fl_cntx_SP->state.loc.x) = fl_state_loc_x;
              (fl_cntx_SP->state.loc.y) = fl_state_loc_y;
#ifndef GFX_STRING_CACHE_ENABLED
              fl_str_length = fl_str_length_bkp;
#endif
              fl_string_ptr = fl_print_str;
            }
          }
#endif   /* #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) */
          fl_mml_gdc_txt_surf = &fl_mml_gdc_txt_surf_c;
          IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));
          IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
          hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif
          fl_draw_mode = (UINT8)p_cntx_SP->rprop.draw_mode;
          if (fl_text_width > p_cntx_SP->rprop.text_width)
          {
            fl_text_width = p_cntx_SP->rprop.text_width;
          }
          if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
          {
            fl_txtbox_strt_x = (SINT32)p_cntx_SP->rprop.text_width;
            fl_pivot_offset = ((SINT32)p_cntx_SP->rprop.text_width - (SINT32)fl_text_width);
            if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
              fl_start_x = ((SINT32)fl_text_width - 1);
            }
            else
            {
              fl_start_x = (SINT32)(fl_text_width);
            }
          }
          else if (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
          {
            fl_start_x = ((SINT32)fl_text_width / 2);
            fl_pivot_offset = (((SINT32)p_cntx_SP->rprop.text_width - (SINT32)fl_text_width) / (SINT32)2);
            fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width / 2);
          }
          else
          {
            fl_start_x = 0;
            fl_txtbox_strt_x = 0;
            fl_pivot_offset = 0;
          }
#if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
          if (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
          {
            /*
            ** handle case where the current alignment is different than default alignment
            */
            if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
            {
              fl_start_x -= ((SINT32)p_cntx_SP->rprop.text_width / 2);
              fl_txtbox_strt_x -= ((SINT32)p_cntx_SP->rprop.text_width / 2);
            }
            else if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
              fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width / 2);
              fl_txtbox_strt_x -= 1;
              fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width / 2);
              /* Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text. */
              /* So it needs to be considered here */
              fl_start_x -= 1;
            }
            else
            {
              /*To Fix MISRA warning*/
            }
          }
          else if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
          {
            if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
            {
              fl_start_x -= (SINT32)(p_cntx_SP->rprop.text_width);
              fl_txtbox_strt_x = 0;
            }
            else if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
              fl_start_x -= ((SINT32)p_cntx_SP->rprop.text_width / 2);
              fl_txtbox_strt_x -= ((SINT32)p_cntx_SP->rprop.text_width / 2);
            }
            else
            {
              fl_txtbox_strt_x -= 1;
            }
          }
          else
          {
            if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
              fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width / 2);
              fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width / 2);
            }
            else if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
              fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width - (SINT32)1);
              fl_start_x += (SINT32)p_cntx_SP->rprop.text_width;
              /*  Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text.So it needs to be considered here  */
              fl_start_x -= 1;
            }
            else
            {
              /*To fix MISRA warning.*/
            }
          }
#endif

#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
          if (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_SHRINK_FIT)
          {
            if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
              fl_start_x = (((SINT32)p_cntx_SP->state.loc.x - (fl_start_x + fl_pivot_offset)) + (((SINT32)p_cntx_SP->rprop.text_width * (100 - (SINT32)fl_scale_down)) / 100));
              fl_txtbox_strt_x = (((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x) + (((SINT32)p_cntx_SP->rprop.text_width * (100 - (SINT32)fl_scale_down)) / 100));
            }
            else if (p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
              fl_start_x = (((SINT32)p_cntx_SP->state.loc.x - (fl_start_x + fl_pivot_offset)) + (((SINT32)p_cntx_SP->rprop.text_width * (100 - (SINT32)fl_scale_down)) / 200));
              fl_txtbox_strt_x = (((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x) + (((SINT32)p_cntx_SP->rprop.text_width * (100 - (SINT32)fl_scale_down)) / 200));
            }
            else
            {
              fl_start_x = ((SINT32)p_cntx_SP->state.loc.x - (fl_start_x + fl_pivot_offset));
              fl_txtbox_strt_x = ((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x);
            }
          }
          else
#endif    
          {
            fl_start_x = ((SINT32)p_cntx_SP->state.loc.x - (fl_start_x + fl_pivot_offset));
            fl_txtbox_strt_x = ((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x);
          }

          if (fl_draw_mode != GFX_MGR02_TP_DRAW_TRANSP)
          {
            if (fl_draw_mode == GFX_MGR02_TP_DRAW_REVERSE)
            {
              fl_bg_color = p_cntx_SP->rprop.fg_color;
              fl_fg_color = p_cntx_SP->rprop.bg_color;
            }
            else
            {
              fl_bg_color = p_cntx_SP->rprop.bg_color;
            }

            fl_bgfill_color[0] = GM2_IRIS_R(fl_bg_color); /* R */
            fl_bgfill_color[1] = GM2_IRIS_G(fl_bg_color); /* G */
            fl_bgfill_color[2] = GM2_IRIS_B(fl_bg_color); /* B */
            fl_bgfill_color[3] = GM2_IRIS_A(fl_bg_color); /* A */

            if ((p_cntx_SP->state.alpha < (UINT8)255) || (fl_bgfill_color[3] < (UINT8)255))
            {
              fl_alpha_temp = ((UINT32)fl_bgfill_color[3] * p_cntx_SP->state.alpha);
              fl_bgfill_color[3] = (UINT8)(fl_alpha_temp / (UINT32)255);
            }
#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))
            IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
            IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
#endif
            if (fl_use_ttf_engine == (UINT8)0)
            {
              IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_SP->p.height, CYGFX_SM_FORMAT_A8B8G8R8, (void*)0, (UINT32)0));
            }
            else
            {
#if(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
              IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_SP->p.height, CYGFX_SM_FORMAT_A8B8G8R8, (void*)0, (UINT32)0));
#else
              IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_size_SP->height, CYGFX_SM_FORMAT_A8B8G8R8, (void*)0, (UINT32)0));
#endif
            }
#else
            IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_SP->p.height, CYGFX_SM_FORMAT_A8B8G8R8, (void*)0, (UINT32)0));
#endif
            IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
            if ((p_cntx_SP->state.alpha < (UINT8)255) || (fl_bgfill_color[3] < (UINT8)255))
            {
              fl_alpha_temp = ((UINT32)fl_bgfill_color[3] * p_cntx_SP->state.alpha);
              fl_bgfill_color[3] = (UINT8)(fl_alpha_temp / (UINT32)255);
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_bgfill_color[0], (CYGFX_U32)fl_bgfill_color[1], (CYGFX_U32)fl_bgfill_color[2], (CYGFX_U32)fl_bgfill_color[3])));
              IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
                CYGFX_BE_BM_GL_FUNC_ADD,
                CYGFX_BE_BM_GL_FUNC_ADD,
                CYGFX_BE_BM_GL_FUNC_ADD,
                CYGFX_BE_BM_GL_FUNC_ADD));
              IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx,
                CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                CYGFX_BE_BF_GL_ONE, CYGFX_BE_BF_GL_ONE));
            }
            else
            {
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_bgfill_color[0], (CYGFX_U32)fl_bgfill_color[1], (CYGFX_U32)fl_bgfill_color[2], (CYGFX_U32)fl_bgfill_color[3])));
            }
            utMat3x3LoadIdentity(fl_matrix1);
            utMat3x3LoadIdentity(fl_matrix2);
            utMat3x3Translate(fl_matrix1, (GFX_FLOAT)fl_txtbox_strt_x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
            hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
            utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
            IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
            IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
          }

          fl_draw_color[0] = GM2_IRIS_R(fl_fg_color); /* R */
          fl_draw_color[1] = GM2_IRIS_G(fl_fg_color); /* G */
          fl_draw_color[2] = GM2_IRIS_B(fl_fg_color); /* B */
          fl_draw_color[3] = GM2_IRIS_A(fl_fg_color); /* A */

          if ((p_cntx_SP->state.alpha < (UINT8)255) || (fl_draw_color[3] < (UINT8)255))
          {
            fl_alpha_temp = ((UINT32)fl_draw_color[3] * p_cntx_SP->state.alpha);
            fl_draw_color[3] = (UINT8)(fl_alpha_temp / (UINT32)255);
          }
          switch (fl_text_BPP)
          {
            case (UINT8)GFX_MGR02_FONT_ENCODING_1BPP:
            {
              fl_surf_format = CYGFX_SM_FORMAT_A1;
            }
            break;
            case (UINT8)GFX_MGR02_FONT_ENCODING_2BPP:
            {
              fl_surf_format = CYGFX_SM_FORMAT_A2;
            }
            break;
            case (UINT8)GFX_MGR02_FONT_ENCODING_4BPP:
            {
              fl_surf_format = CYGFX_SM_FORMAT_A4;
            }
            break;
            case (UINT8)GFX_MGR02_FONT_ENCODING_8BPP:
            default:
            {
              fl_surf_format = CYGFX_SM_FORMAT_A8;
            }
            break;
          }
          fl_glyph_draw_x = (CYGFX_FLOAT)fl_start_x;
#ifdef GFX_STRING_CACHE_ENABLED
          /*
          1. Get the bmp pointer for the string from the cache.
          2. If it is not available then render that string and it in cache.
          */
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
          if (fl_shaping_required == (UINT8)(FALSE))
          {
            fl_str_img_data = fl_str_cache_info.Buf;
          }
          else
#endif
          {
#if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED))
            fl_str_img_data = hmi_gfx_mgr02_get_string_cache_ptr(fl_string_ptr, p_cntx_SP, fl_font_SP, fl_font_id, fl_txt_special_prop_SP);
#else
            fl_str_img_data = hmi_gfx_mgr02_get_string_cache_ptr(fl_string_ptr, p_cntx_SP, fl_font_SP, fl_font_id);
#endif
          }
          if (fl_str_img_data == NULL)
          {
            /*
            1. Create a string.
            */
            GFX_STRING_CACHE_INFO element;
            IrisMemInfo fl_memory_s;
            UINT8 fl_font_height = 0;
#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)&&(((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)) ||(GFX_MGR02_EXT_FONT_ENGINE != GFX_MGR02_MONOTYPE))
            fl_font_height = p_cntx_SP->rprop.font_size.height;
#else
            fl_font_height = fl_font_SP->p.height;
#endif
            fl_memory_s.MemCateg = IRIS_STRING_CACHE_BUFFER;
            fl_memory_s.WidgetClientId = 0xFFFFFFFFU;
            fl_memory_s.Alignment = (UINT32)32; /*32 Byte alignement*/
            if (fl_text_BPP == GFX_MGR02_FONT_ENCODING_1BPP)
            {
              if ((fl_full_text_width % 8U) == 0U)
              {
                fl_memory_s.Size = (((CYGFX_U32)fl_full_text_width * (CYGFX_U32)fl_font_height) / 8U);
              }
              else
              {
                fl_memory_s.Size = ((((((CYGFX_U32)fl_full_text_width / 8U) * 8U) + 8U) * (CYGFX_U32)fl_font_height) / 8U);
              }
            }
            else if (fl_text_BPP == GFX_MGR02_FONT_ENCODING_2BPP)
            {
              if ((fl_full_text_width % 4U) == 0U)
              {
                fl_memory_s.Size = (((CYGFX_U32)fl_full_text_width * (CYGFX_U32)fl_font_height) / 4U);
              }
              else
              {
                fl_memory_s.Size = ((((((CYGFX_U32)fl_full_text_width / 4U) * 4U) + 4U) * (CYGFX_U32)fl_font_height) / 4U);
              }
            }
            else if (fl_text_BPP == GFX_MGR02_FONT_ENCODING_4BPP)
            {
              if ((fl_full_text_width % 2U) == 0U)
              {
                fl_memory_s.Size = (((CYGFX_U32)fl_full_text_width * (CYGFX_U32)fl_font_height) / 2U);
              }
              else
              {
                fl_memory_s.Size = ((((((CYGFX_U32)fl_full_text_width / 2U) * 2U) + 2U) * (CYGFX_U32)fl_font_height) / 2U);
              }
            }
            else
            {
              fl_memory_s.Size = ((CYGFX_U32)fl_full_text_width * (CYGFX_U32)fl_font_height);
            }
#ifdef GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG
            fl_memory_s.ExtMemory = (UINT8)1;
#else
            fl_memory_s.ExtMemory = (UINT8)0;
#endif
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
            fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif
            fl_str_img_data = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
            if (fl_str_img_data != NULL)
            {
              (void)memset(fl_str_img_data, 0, fl_memory_s.Size);
              hmi_gfx_mgr02_create_img_for_string((UINT8 *)fl_str_img_data, p_cntx_SP, fl_string_ptr,
                                                  (UINT32)fl_full_text_width, fl_font_SP
#if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
                                                  ,fl_txt_special_prop_SP
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
                                                  ,p_ml_str_index, fl_ML_data_ptr, p_is_multi_line_text, fl_shape_flags
#endif
              );
              (void)HMI_STRNCPY(element.String, fl_string_ptr, (UINT32)GFX_MGR02_MAX_TEXT_LENGTH);
              element.String[GFX_MGR02_MAX_TEXT_LENGTH] = (HMI_CHAR)'\0';
#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (!defined(GFX_MGR02_TXT_EFFECTS_ENABLED))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
              element.InString[GFX_MGR02_MAX_TEXT_LENGTH] = (HMI_CHAR)'\0';
              (void)HMI_STRNCPY(element.InString, p_string, (UINT32)GFX_MGR02_MAX_TEXT_LENGTH);
              element.TextBoxWidth = fl_text_box_width;
              element.ClipMode = (UINT8)p_cntx_SP->rprop.clip_mode;
              element.Alignment = (UINT8)p_cntx_SP->rprop.alignment;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              if(p_cntx_SP->rprop.scroll_offset > 0U)
              {
                element.isScrolled = TRUE;
              }
              else
              {
                element.isScrolled = FALSE;
              }
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
              element.MaxShrink = p_cntx_SP->rprop.max_shrink;
#endif
#endif
              element.StringLen = (UINT8)HMI_STRLEN(element.String);
              element.FontId = fl_font_id;
              element.FontSize = fl_font_height;
              element.Buf = (UINT8*)fl_str_img_data;
              element.bmpWidth = (UINT16)fl_full_text_width;

#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
              if (fl_txt_special_prop_SP != GFX_MGR02_NULL_PTR)
              {
                element.special_effects.effect_type = fl_txt_special_prop_SP->effect_type;
                #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
                if (fl_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
                {
                  element.special_effects.bold_percentage = fl_txt_special_prop_SP->bold_percentage;
                }
                else if ((fl_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_NORMAL_GLOW_EFFECT) || (fl_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT))
                {
                  element.special_effects.otl_width = fl_txt_special_prop_SP->otl_width;
                  element.special_effects.otl_opacity = fl_txt_special_prop_SP->otl_opacity;
                }
                else if (fl_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_DROP_SHADOW_EFFECT)
                {
                  element.special_effects.shadow_bg_col = fl_txt_special_prop_SP->shadow_bg_col;
                  element.special_effects.shadow_x = fl_txt_special_prop_SP->shadow_x;
                  element.special_effects.shadow_y = fl_txt_special_prop_SP->shadow_y;
                }
                else
                #endif
                {
                  /* For other effects we need not to maitain all properties except its type */
                }
              }
              else
              {
                element.special_effects.effect_type = GFX_MGR02_TXT_INVALID_EFFECT;
              }
#endif
              hmi_gfx_mgr02_add_string_in_cache_queue(&element);
            }
            else
            {
              ((GFX_MGR02_CONTEXT_T*)p_cntx_SP)->rprop.pivot.x -= ((GFX_FLOAT)fl_pivot_offset);
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) &&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
              draw_freetype_bmp_string(fl_glyph_draw_x,
                                       p_cntx_SP, fl_surf_format, fl_string_ptr, fl_font_SP, &fl_draw_color[0], fl_str_length
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                       ,
                                       fl_txt_special_prop_SP
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                       ,
                                       fl_scroll_offset, fl_text_width, fl_alignment
#endif /*  (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)*/
              );
#endif
            }
          }
#endif

#ifndef GFX_STRING_CACHE_ENABLED
          ((GFX_MGR02_CONTEXT_T*)p_cntx_SP)->rprop.pivot.x -= ((GFX_FLOAT)fl_pivot_offset);
          if (fl_use_ttf_engine == (UINT8)0)
          {
#if !defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
            draw_windows_bmp_string(fl_glyph_draw_x,p_cntx_SP,fl_surf_format,
                                    fl_string_ptr, (UINT32)fl_full_text_width,fl_font_SP,&fl_draw_color[0],fl_str_length
                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                    ,fl_scroll_offset
                                    #endif
                                    );
#endif

          }
          else
          {
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE))
#if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))
            draw_outline_string(fl_glyph_draw_x, p_cntx_SP, fl_surf_format, fl_string_ptr, fl_font_SP, &fl_draw_color[0], fl_str_length);
#elif (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
            draw_monotype_bmp_string(fl_glyph_draw_x, p_cntx_SP, fl_surf_format, fl_string_ptr , fl_full_text_width
              , fl_font_SP, &fl_draw_color[0], fl_str_length
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
              , p_ml_str_index, fl_ML_data_ptr, p_is_multi_line_text, fl_shape_flags
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              , fl_scroll_offset
              , fl_alignment
#endif
            );
#elif (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
            draw_freetype_bmp_string(fl_glyph_draw_x,
                                     p_cntx_SP, fl_surf_format, fl_string_ptr, fl_font_SP, &fl_draw_color[0], fl_str_length
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                     ,
                                     fl_txt_special_prop_SP
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                     ,
                                     fl_scroll_offset, fl_text_width, fl_alignment
#endif /*  (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)*/
            );
#endif
#endif /* GFX_MGR02_USE_EXT_FONT_ENGINE */
          }
#else
          if (fl_str_img_data != NULL)
          {
            /*Clip rectangle used to clip start and end of the character based on the scroll offset*/
            SINT32 fl_scroll_clip_rect[4];
            /*There is no change in y and height for scrolling. Hence using the default values*/
            fl_scroll_clip_rect[0] = 0;
            fl_scroll_clip_rect[1] = 0;
            fl_scroll_clip_rect[2] = (SINT32)(fl_text_width);
            fl_scroll_clip_rect[3] = (SINT32)(fl_font_SP->p.height);
            if ((p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT) && (fl_full_text_width > p_cntx_SP->rprop.text_width))
            {
              fl_scroll_clip_rect[0] = ((SINT32)fl_full_text_width - (SINT32)p_cntx_SP->rprop.text_width);
              #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              fl_scroll_clip_rect[0]-= (SINT32)fl_scroll_offset;
              #endif
            }
            else
            {
              #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              fl_scroll_clip_rect[0] = (SINT32)(fl_scroll_offset);
              #endif
            }
            fl_glyph_draw_x -= (CYGFX_FLOAT)fl_scroll_clip_rect[0];
            /*start clip x may go negative values when the width of printable text is less than the text box width.*/
            if (fl_scroll_clip_rect[0] < 0)
            {
              fl_scroll_clip_rect[0] = 0;
            }
            #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            fl_scroll_clip_rect[2] = ((SINT32)fl_full_text_width - (SINT32)fl_scroll_offset);
            #endif
            if (fl_scroll_clip_rect[2] > ((SINT32)p_cntx_SP->rprop.text_width))
            {
              fl_scroll_clip_rect[2] = ((SINT32)p_cntx_SP->rprop.text_width);
            }
            if (fl_scroll_clip_rect[2] > 0)/*Valid clip width*/
            {
              IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))
              IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)fl_text_width, (UINT32)fl_font_size_SP->height, fl_surf_format, fl_str_img_data, (UINT32)0));
#else
              IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)fl_full_text_width, (UINT32)fl_font_SP->p.height, fl_surf_format, fl_str_img_data, (UINT32)0));
#endif
              IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
              IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, p_cntx_SP->rprop.pe_tsurf));
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_draw_color[0], (CYGFX_U32)fl_draw_color[1], (CYGFX_U32)fl_draw_color[2], (CYGFX_U32)fl_draw_color[3])));
              if (fl_draw_color[3] < (UINT8)255)
              {
                IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
                  CYGFX_BE_BM_GL_FUNC_ADD,
                  CYGFX_BE_BM_GL_FUNC_ADD,
                  CYGFX_BE_BM_GL_FUNC_ADD,
                  CYGFX_BE_BM_GL_FUNC_ADD));

                IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                  CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                  CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                  CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));

                IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
              }
              utMat3x3LoadIdentity(fl_matrix1);
              utMat3x3LoadIdentity(fl_matrix2);
              utMat3x3Translate(fl_matrix1, fl_glyph_draw_x, (GFX_FLOAT)p_cntx_SP->state.loc.y);
              hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
              utMat3x3Translate(fl_matrix2, (GFX_FLOAT)((GFX_FLOAT)fl_pivot_offset - p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
              IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
              hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)1);
#endif
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
              IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC));
              IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_scroll_clip_rect[0], fl_scroll_clip_rect[1],
                (UINT32)fl_scroll_clip_rect[2], (UINT32)fl_scroll_clip_rect[3]));
              IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
            }
          }
#endif
        }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)  && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
        if ((l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR) && (fl_client_state != GFX_MGR02_NULL_PTR))
        {
          /* set the flag so that get_glyph functions will turn ON cmap      */
          (void)FS_set_flags(fl_client_state, FLAGS_CMAP_ON);
        }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
        else
        {
          if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE) && (fl_client_state != GFX_MGR02_NULL_PTR))
          {
            /* set the flag so that get_glyph functions will turn ON cmap      */
            (void)FS_set_flags(fl_client_state, FLAGS_CMAP_ON);
          }
        }
#endif
#endif
#endif
      }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)  && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
      l_shaper_info.shaper_out_ptr = (TsShaperText*)GFX_MGR02_NULL_PTR;
#else
        l_shaper_info.shaper_out_ptr = (GFX_MGR02_HB_SHAPE_INFO*)GFX_MGR02_NULL_PTR;
#endif
#endif

    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("Irislib - Text elem =%08X skipped\n", p_elem_def_SP);
    }
#endif
    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    GFX_MGR02_UNUSED_VAR(p_text_actual_width);
    return(fl_return_value);
  }

#if (GFX_MGR02_NUM_OF_SVGS > 0)
  s_gx_flocal hmi_gfx_mgr02_tv2_build_svg(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_OVG_OBJECT_T  const* p_elem_def_SP)
  {
    SINT32 ret = CYGFX_OK;
    s_gx_flocal fl_return_value = FALSE;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT* fl_rgba;
    GFX_MGR02_OVG_PATH_DEF_T const* fl_cur_path_sp;
    CYGFX_U32 fl_path_count_U32;
    CYGFX_U32 fl_cur_path_buf_U32 = 0UL;

    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if ((p_cntx_SP->state.invisible == 0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
      )
    {
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)0);
#endif

      /*Translate the SVG Object*/
      utMat3x3LoadIdentity(fl_matrix1);
      utMat3x3Translate(fl_matrix1, (CYGFX_FLOAT)(p_cntx_SP->state.loc.x), (CYGFX_FLOAT)(p_cntx_SP->state.loc.y));
      hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
      utMat3x3Translate(fl_matrix2, (CYGFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (CYGFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
      IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));

      /* Set Attributes */
      IRIS_API_CHECK(ret, CyGfx_DeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_DE_ATTR_DATA_FORMAT, (UINT32)CYGFX_DE_DATA_FORMAT_FLOAT));

      fl_cur_path_sp = p_elem_def_SP->path_array_sap;
      fl_path_count_U32 = p_elem_def_SP->num_paths;
      /*Fill Path*/
      while (fl_path_count_U32 > 0UL)
      {
        /* Assign the path */
        IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, (UINT32)fl_cur_path_sp->numSegments, fl_cur_path_sp->path_segments_u8p, fl_cur_path_sp->path_data_fp));

        fl_rgba = (CYGFX_FLOAT*)fl_cur_path_sp->fill_paint_vp;
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)(fl_rgba[0] * 255), (CYGFX_U32)(fl_rgba[1] * 255), (CYGFX_U32)(fl_rgba[2] * 255), (CYGFX_U32)(fl_rgba[3] * 255))));
        do
        {
          IRIS_API_CHECK(ret, CyGfx_DeGetAttribute(p_cntx_SP->rprop.pe_ctx, MML_GDC_DE_ATTR_CURRENT_PATH_BUFFER, &fl_cur_path_buf_U32));
        } while (fl_cur_path_buf_U32 < (UINT32)(GFX_MGR02_DE_PATHBUF_SIZE / 8));
        /* start drawing */
        IRIS_API_CHECK(ret, CyGfx_DeDraw(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
        fl_cur_path_sp++;
        fl_path_count_U32--;
      }
      /*
      Stroke Path:
      1. Deassociate the Fill colour to the surface.
      2. Associate the Stroke colour to the surface.
      3. Check for the line width>0
      4. Draw the Storke
      */
      IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
      fl_cur_path_sp = p_elem_def_SP->path_array_sap;
      fl_path_count_U32 = p_elem_def_SP->num_paths;

      while (fl_path_count_U32 > 0UL)
      {
        if (fl_cur_path_sp->stroke_width > 0.0F)
        {
          CYGFX_FLOAT  fl_last_path_coordinate_f[2] = { 0.0F,0.0F };
          CYGFX_FLOAT const* fl_path_data_fp = fl_cur_path_sp->path_data_fp;
          UINT8 const* fl_path_segments_u8p = fl_cur_path_sp->path_segments_u8p;
          UINT16 fl_cur_seg_u16 = (UINT16)0;

          fl_rgba = (CYGFX_FLOAT*)fl_cur_path_sp->stroke_paint_vp;
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)(fl_rgba[0] * 255), (CYGFX_U32)(fl_rgba[1] * 255), (CYGFX_U32)(fl_rgba[2] * 255), (CYGFX_U32)(fl_rgba[3] * 255))));

          for (; fl_cur_seg_u16 < fl_cur_path_sp->numSegments; fl_cur_seg_u16++)
          {
            /* Assign the path */
            if ((CYGFX_DE_INSTR_MOVE_TO_ABS == *fl_path_segments_u8p) ||
              (CYGFX_DE_INSTR_MOVE_TO_REL == *fl_path_segments_u8p))
            {
              CYGFX_FLOAT fl_coordinate[2];
              UINT8 fl_seg_u8 = CYGFX_DE_INSTR_MOVE_TO_ABS;
              fl_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_coordinate[1] = *fl_path_data_fp;
              IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, 1UL, &fl_seg_u8, fl_coordinate));
              fl_last_path_coordinate_f[0] = fl_coordinate[0];
              fl_last_path_coordinate_f[1] = fl_coordinate[1];

            }
            else if ((CYGFX_DE_INSTR_LINE_TO_ABS == *fl_path_segments_u8p) ||
              (CYGFX_DE_INSTR_LINE_TO_REL == *fl_path_segments_u8p))
            {
              CYGFX_FLOAT fl_coordinate[10];
              CYGFX_FLOAT  fl_target_coordinate[2];
              CYGFX_FLOAT fl_dx_f;
              CYGFX_FLOAT fl_dy_f;
              CYGFX_FLOAT fl_len_f;

              CYGFX_FLOAT fl_origin_coordinate[2];
              UINT8 fl_segments[] = {
                CYGFX_DE_INSTR_MOVE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS
              };

              fl_origin_coordinate[0] = fl_last_path_coordinate_f[0];
              fl_origin_coordinate[1] = fl_last_path_coordinate_f[1];

              fl_path_data_fp++;
              fl_target_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_target_coordinate[1] = *fl_path_data_fp;

              if (CYGFX_DE_INSTR_LINE_TO_REL == *fl_path_segments_u8p)
              {
                fl_target_coordinate[0] += fl_origin_coordinate[0];
                fl_target_coordinate[1] += fl_origin_coordinate[1];
              }
              fl_last_path_coordinate_f[0] = fl_target_coordinate[0];
              fl_last_path_coordinate_f[1] = fl_target_coordinate[1];

              fl_dx_f = fl_target_coordinate[0] - fl_origin_coordinate[0];
              fl_dy_f = fl_target_coordinate[1] - fl_origin_coordinate[1];
              fl_len_f = sqrt((fl_dx_f * fl_dx_f) + (fl_dy_f * fl_dy_f));

              fl_dx_f *= (fl_cur_path_sp->stroke_width / fl_len_f) / 2.0F;
              fl_dy_f *= (fl_cur_path_sp->stroke_width / fl_len_f) / 2.0F;

              fl_origin_coordinate[0] += 0.5f;
              fl_origin_coordinate[1] += 0.5f;
              fl_target_coordinate[0] += 0.5f;
              fl_target_coordinate[1] += 0.5f;

              fl_coordinate[0] = (fl_origin_coordinate[0] - fl_dy_f);
              fl_coordinate[1] = (fl_origin_coordinate[1] + fl_dx_f);
              fl_coordinate[2] = (fl_target_coordinate[0] - fl_dy_f);
              fl_coordinate[3] = (fl_target_coordinate[1] + fl_dx_f);
              fl_coordinate[4] = (fl_target_coordinate[0] + fl_dy_f);
              fl_coordinate[5] = (fl_target_coordinate[1] - fl_dx_f);
              fl_coordinate[6] = (fl_origin_coordinate[0] + fl_dy_f);
              fl_coordinate[7] = (fl_origin_coordinate[1] - fl_dx_f);
              fl_coordinate[8] = (fl_origin_coordinate[0] - fl_dy_f);
              fl_coordinate[9] = (fl_origin_coordinate[1] + fl_dx_f);

              IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, 5UL, fl_segments, fl_coordinate));

            }
            else if ((CYGFX_DE_INSTR_QUAD_TO_ABS == *fl_path_segments_u8p) ||
              (CYGFX_DE_INSTR_QUAD_TO_REL == *fl_path_segments_u8p))
            {
              CYGFX_FLOAT fl_coordinate[14];
              CYGFX_FLOAT  fl_target_coordinate[2];
              CYGFX_FLOAT  fl_cntrl_coordinate[2];
              CYGFX_FLOAT fl_dx1_f;
              CYGFX_FLOAT fl_dy1_f;
              CYGFX_FLOAT fl_dx2_f;
              CYGFX_FLOAT fl_dy2_f;
              CYGFX_FLOAT fl_len1_f;
              CYGFX_FLOAT fl_len2_f;

              CYGFX_FLOAT fl_origin_coordinate[2];
              UINT8 fl_segments[] = {
                CYGFX_DE_INSTR_MOVE_TO_ABS,
                CYGFX_DE_INSTR_QUAD_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_QUAD_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS
              };

              fl_origin_coordinate[0] = fl_last_path_coordinate_f[0];
              fl_origin_coordinate[1] = fl_last_path_coordinate_f[1];

              fl_path_data_fp++;
              fl_cntrl_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_cntrl_coordinate[1] = *fl_path_data_fp;

              fl_path_data_fp++;
              fl_target_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_target_coordinate[1] = *fl_path_data_fp;

              if (CYGFX_DE_INSTR_QUAD_TO_REL == *fl_path_segments_u8p)
              {
                fl_target_coordinate[0] += fl_origin_coordinate[0];
                fl_target_coordinate[1] += fl_origin_coordinate[1];
              }

              fl_last_path_coordinate_f[0] = fl_target_coordinate[0];
              fl_last_path_coordinate_f[1] = fl_target_coordinate[1];

              fl_dx1_f = fl_cntrl_coordinate[0] - fl_origin_coordinate[0];
              fl_dy1_f = fl_cntrl_coordinate[1] - fl_origin_coordinate[1];
              fl_len1_f = sqrt((fl_dx1_f * fl_dx1_f) + (fl_dy1_f * fl_dy1_f));
              fl_dx2_f = fl_target_coordinate[0] - fl_cntrl_coordinate[0];
              fl_dy2_f = fl_target_coordinate[1] - fl_cntrl_coordinate[1];
              fl_len2_f = sqrt((fl_dx2_f * fl_dx2_f) + (fl_dy2_f * fl_dy2_f));

              fl_dx1_f *= (fl_cur_path_sp->stroke_width / fl_len1_f) / 2.0F;
              fl_dy1_f *= (fl_cur_path_sp->stroke_width / fl_len1_f) / 2.0F;
              fl_dx2_f *= (fl_cur_path_sp->stroke_width / fl_len2_f) / 2.0F;
              fl_dy2_f *= (fl_cur_path_sp->stroke_width / fl_len2_f) / 2.0F;

              fl_origin_coordinate[0] += 0.5f;
              fl_origin_coordinate[1] += 0.5f;
              fl_cntrl_coordinate[0] += 0.5f;
              fl_cntrl_coordinate[1] += 0.5f;
              fl_target_coordinate[0] += 0.5f;
              fl_target_coordinate[1] += 0.5f;

              fl_coordinate[0] = (fl_origin_coordinate[0] - fl_dy1_f);
              fl_coordinate[1] = (fl_origin_coordinate[1] + fl_dx1_f);
              fl_coordinate[2] = (fl_cntrl_coordinate[0] - ((fl_dy2_f + fl_dy1_f) / 2.0F));
              fl_coordinate[3] = (fl_cntrl_coordinate[1] + ((fl_dx2_f + fl_dx1_f) / 2.0F));
              fl_coordinate[4] = (fl_target_coordinate[0] - fl_dy2_f);
              fl_coordinate[5] = (fl_target_coordinate[1] + fl_dx2_f);
              fl_coordinate[6] = (fl_target_coordinate[0] + fl_dy2_f);
              fl_coordinate[7] = (fl_target_coordinate[1] - fl_dx2_f);
              fl_coordinate[8] = (fl_cntrl_coordinate[0] + ((fl_dy1_f + fl_dy2_f) / 2.0F));
              fl_coordinate[9] = (fl_cntrl_coordinate[1] - ((fl_dx1_f + fl_dx2_f) / 2.0F));
              fl_coordinate[10] = (fl_origin_coordinate[0] + fl_dy1_f);
              fl_coordinate[11] = (fl_origin_coordinate[1] - fl_dx1_f);
              fl_coordinate[12] = (fl_origin_coordinate[0] - fl_dy1_f);
              fl_coordinate[13] = (fl_origin_coordinate[1] + fl_dx1_f);

              IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, 5UL, fl_segments, fl_coordinate));

            }
            else if ((CYGFX_DE_INSTR_CUBIC_TO_ABS == *fl_path_segments_u8p) ||
              (CYGFX_DE_INSTR_CUBIC_TO_REL == *fl_path_segments_u8p))
            {
              CYGFX_FLOAT fl_coordinate[18];
              CYGFX_FLOAT  fl_target_coordinate[2];
              CYGFX_FLOAT  fl_first_cntrl_coordinate[2];
              CYGFX_FLOAT  fl_second_cntrl_coordinate[2];
              CYGFX_FLOAT fl_origin_coordinate[2];

              CYGFX_FLOAT fl_dx1_f;
              CYGFX_FLOAT fl_dy1_f;
              CYGFX_FLOAT fl_dx2_f;
              CYGFX_FLOAT fl_dy2_f;

              CYGFX_FLOAT fl_len1_f;
              CYGFX_FLOAT fl_len2_f;



              UINT8 fl_segments[] = {
                CYGFX_DE_INSTR_MOVE_TO_ABS,
                CYGFX_DE_INSTR_CUBIC_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_CUBIC_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS
              };


              fl_origin_coordinate[0] = fl_last_path_coordinate_f[0];
              fl_origin_coordinate[1] = fl_last_path_coordinate_f[1];


              fl_path_data_fp++;
              fl_first_cntrl_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_first_cntrl_coordinate[1] = *fl_path_data_fp;

              fl_path_data_fp++;
              fl_second_cntrl_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_second_cntrl_coordinate[1] = *fl_path_data_fp;

              fl_path_data_fp++;
              fl_target_coordinate[0] = *fl_path_data_fp;
              fl_path_data_fp++;
              fl_target_coordinate[1] = *fl_path_data_fp;



              if (CYGFX_DE_INSTR_CUBIC_TO_REL == *fl_path_segments_u8p)
              {
                fl_target_coordinate[0] += fl_origin_coordinate[0];
                fl_target_coordinate[1] += fl_origin_coordinate[1];
              }
              fl_last_path_coordinate_f[0] = fl_target_coordinate[0];
              fl_last_path_coordinate_f[1] = fl_target_coordinate[1];

              fl_dx1_f = fl_first_cntrl_coordinate[0] - fl_origin_coordinate[0];
              fl_dy1_f = fl_first_cntrl_coordinate[1] - fl_origin_coordinate[1];
              fl_len1_f = sqrt((fl_dx1_f * fl_dx1_f) + (fl_dy1_f * fl_dy1_f));
              fl_dx2_f = fl_target_coordinate[0] - fl_second_cntrl_coordinate[0];
              fl_dy2_f = fl_target_coordinate[1] - fl_second_cntrl_coordinate[1];
              fl_len2_f = sqrt((fl_dx2_f * fl_dx2_f) + (fl_dy2_f * fl_dy2_f));

              fl_dx1_f *= (fl_cur_path_sp->stroke_width / fl_len1_f) / 2.0F;
              fl_dy1_f *= (fl_cur_path_sp->stroke_width / fl_len1_f) / 2.0F;
              fl_dx2_f *= (fl_cur_path_sp->stroke_width / fl_len2_f) / 2.0F;
              fl_dy2_f *= (fl_cur_path_sp->stroke_width / fl_len2_f) / 2.0F;

              fl_origin_coordinate[0] += 0.5f;
              fl_origin_coordinate[1] += 0.5f;
              fl_first_cntrl_coordinate[0] += 0.5f;
              fl_first_cntrl_coordinate[1] += 0.5f;
              fl_second_cntrl_coordinate[0] += 0.5f;
              fl_second_cntrl_coordinate[1] += 0.5f;
              fl_target_coordinate[0] += 0.5f;
              fl_target_coordinate[1] += 0.5f;


              fl_coordinate[0] = (fl_origin_coordinate[0] - fl_dy1_f);
              fl_coordinate[1] = (fl_origin_coordinate[1] + fl_dx1_f);
              fl_coordinate[2] = (fl_first_cntrl_coordinate[0] - (fl_dy1_f / 2.0F));
              fl_coordinate[3] = (fl_first_cntrl_coordinate[1] + (fl_dx1_f / 2.0F));
              fl_coordinate[4] = (fl_second_cntrl_coordinate[0] - (fl_dy2_f / 2.0F));
              fl_coordinate[5] = (fl_second_cntrl_coordinate[1] + (fl_dx2_f / 2.0F));
              fl_coordinate[6] = (fl_target_coordinate[0] - fl_dy2_f);
              fl_coordinate[7] = (fl_target_coordinate[1] + fl_dx2_f);
              fl_coordinate[8] = (fl_target_coordinate[0] + fl_dy2_f);
              fl_coordinate[9] = (fl_target_coordinate[1] - fl_dx2_f);
              fl_coordinate[10] = (fl_second_cntrl_coordinate[0] + (fl_dy2_f / 2.0F));
              fl_coordinate[11] = (fl_second_cntrl_coordinate[1] - (fl_dx2_f / 2.0F));
              fl_coordinate[12] = (fl_first_cntrl_coordinate[0] + (fl_dy1_f / 2.0F));
              fl_coordinate[13] = (fl_first_cntrl_coordinate[1] - (fl_dx1_f / 2.0F));
              fl_coordinate[14] = (fl_origin_coordinate[0] + fl_dy1_f);
              fl_coordinate[15] = (fl_origin_coordinate[1] - fl_dx1_f);
              fl_coordinate[16] = (fl_origin_coordinate[0] - fl_dy1_f);
              fl_coordinate[17] = (fl_origin_coordinate[1] + fl_dx1_f);
              IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, 5UL, fl_segments, fl_coordinate));
            }
            else if (CYGFX_DE_INSTR_CLOSE_PATH == *fl_path_segments_u8p)
            {
              CYGFX_FLOAT fl_coordinate[10];
              CYGFX_FLOAT  fl_target_coordinate[2];
              CYGFX_FLOAT fl_dx_f;
              CYGFX_FLOAT fl_dy_f;
              CYGFX_FLOAT fl_len_f;

              CYGFX_FLOAT const* fl_path_coord_fp = fl_cur_path_sp->path_data_fp;

              CYGFX_FLOAT fl_origin_coordinate[2];
              UINT8 fl_segments[] = {
                CYGFX_DE_INSTR_MOVE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS,
                CYGFX_DE_INSTR_LINE_TO_ABS
              };

              fl_origin_coordinate[0] = fl_last_path_coordinate_f[0];
              fl_origin_coordinate[1] = fl_last_path_coordinate_f[1];

              fl_target_coordinate[0] = *fl_path_coord_fp;
              fl_path_coord_fp++;
              fl_target_coordinate[1] = *fl_path_coord_fp;

              fl_dx_f = fl_target_coordinate[0] - fl_origin_coordinate[0];
              fl_dy_f = fl_target_coordinate[1] - fl_origin_coordinate[1];
              fl_len_f = sqrt((fl_dx_f * fl_dx_f) + (fl_dy_f * fl_dy_f));

              fl_dx_f *= (fl_cur_path_sp->stroke_width / fl_len_f) / 2.0F;
              fl_dy_f *= (fl_cur_path_sp->stroke_width / fl_len_f) / 2.0F;

              fl_origin_coordinate[0] += 0.5f;
              fl_origin_coordinate[1] += 0.5f;
              fl_target_coordinate[0] += 0.5f;
              fl_target_coordinate[1] += 0.5f;

              fl_coordinate[0] = (fl_origin_coordinate[0] - fl_dy_f);
              fl_coordinate[1] = (fl_origin_coordinate[1] + fl_dx_f);
              fl_coordinate[2] = (fl_target_coordinate[0] - fl_dy_f);
              fl_coordinate[3] = (fl_target_coordinate[1] + fl_dx_f);
              fl_coordinate[4] = (fl_target_coordinate[0] + fl_dy_f);
              fl_coordinate[5] = (fl_target_coordinate[1] - fl_dx_f);
              fl_coordinate[6] = (fl_origin_coordinate[0] + fl_dy_f);
              fl_coordinate[7] = (fl_origin_coordinate[1] - fl_dx_f);
              fl_coordinate[8] = (fl_origin_coordinate[0] - fl_dy_f);
              fl_coordinate[9] = (fl_origin_coordinate[1] + fl_dx_f);
              IRIS_API_CHECK(ret, CyGfx_DeAppendPathData(p_cntx_SP->rprop.pe_ctx, 5UL, fl_segments, fl_coordinate));
            }
            else
            {
              /*To Fix MISRA warning.*/
            }
            IRIS_API_CHECK(ret, CyGfx_DeDraw(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
            fl_path_segments_u8p++;
          }
        }
        fl_cur_path_sp++;
        fl_path_count_U32--;

      }
      l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING | GFX_MGR02_TV2_FB_UPDATED);
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
      gfx_debug("Irislib - SVG elem =%08X skipped\n", p_elem_def_SP);
    }
#endif

    if (ret == CYGFX_OK)
    {
      fl_return_value = TRUE;
    }
    return(fl_return_value);

  }
#endif  

#if (GFX_MGR02_NUM_USER_LAYERS > 0)
  s_gx_flocal hmi_gfx_mgr02_tv2_build_uimage(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_IMAGE_DEF_T  const* p_elem_def_SP)
  {
    s_gx_flocal fl_return_value = (s_gx_flocal)0;

    if (p_elem_def_SP->format == GFX_MGR02_FORMAT_HISTOGRAM) /* Histogram Rendering */
    {
      UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
      SINT32 ret = CYGFX_OK;

      if ((p_cntx_SP->state.invisible == 0U) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
        && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
        )
      {
        GFX_MGR02_HISTOGRAM_DATA const* fl_histogram_data_SP = (GFX_MGR02_HISTOGRAM_DATA const*)p_elem_def_SP->pixel_data;

        if (fl_histogram_data_SP->hg_y_data != GFX_MGR02_NULL_PTR)
        {
          UINT8 hg_counter;
          UINT16 fl_hg_x_spacing;
          CYGFX_FLOAT hg_start_x = 0, x1, x2, y1, y2, x3, y3;
          UINT32 fl_hg_dc_alpha = (fl_histogram_data_SP->hg_draw_color_alpha * p_cntx_SP->state.alpha) / 255u;

          CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
          CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
          hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, (UINT8)0);
#endif

          utMat3x3LoadIdentity(fl_matrix1);
          utMat3x3LoadIdentity(fl_matrix2);
          utMat3x3Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x + (fl_histogram_data_SP->hg_line_width / 2.0F), (GFX_FLOAT)p_cntx_SP->state.loc.y + (fl_histogram_data_SP->hg_line_width / 2.0F));
          hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
          utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));

          IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_MASK, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
          IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA(fl_histogram_data_SP->hg_draw_color_red,
            fl_histogram_data_SP->hg_draw_color_green,
            fl_histogram_data_SP->hg_draw_color_blue,
            fl_hg_dc_alpha)));

          fl_hg_x_spacing = (p_elem_def_SP->width) / (fl_histogram_data_SP->hg_num_data_points - 1U);

          for (hg_counter = 0; hg_counter < (fl_histogram_data_SP->hg_num_data_points - 1U); hg_counter++)
          {
            x1 = hg_start_x;
            x3 = x1 + (SINT16)fl_hg_x_spacing;
            x2 = x1 + (SINT16)(fl_hg_x_spacing / 2U);

            y1 = fl_histogram_data_SP->hg_y_max - fl_histogram_data_SP->hg_y_data[hg_counter];
            y3 = fl_histogram_data_SP->hg_y_max - fl_histogram_data_SP->hg_y_data[hg_counter + 1U];
            y2 = fl_histogram_data_SP->hg_y_max - ((fl_histogram_data_SP->hg_y_data[hg_counter] + fl_histogram_data_SP->hg_y_data[hg_counter + 1U]) / 2);

            IRIS_API_CHECK(ret, utDeQuad(p_cntx_SP->rprop.pe_ctx, (GFX_FLOAT)x1, (GFX_FLOAT)y1, (GFX_FLOAT)x2, (GFX_FLOAT)y2, (GFX_FLOAT)x3, (GFX_FLOAT)y3, fl_histogram_data_SP->hg_line_width));
            if ((hg_counter < (fl_histogram_data_SP->hg_num_data_points - 2U)) && \
              ((fl_histogram_data_SP->hg_y_data[hg_counter + 1U] != fl_histogram_data_SP->hg_y_data[hg_counter + 2U]) || \
                (fl_histogram_data_SP->hg_y_data[hg_counter] != fl_histogram_data_SP->hg_y_data[hg_counter + 1U])))
            {
              IRIS_API_CHECK(ret, utDeDrawCircle(p_cntx_SP->rprop.pe_ctx, x3 + 0.5F, y3 + 0.5F, fl_histogram_data_SP->hg_line_width / 2.0F));
            }
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));

            hg_start_x = x3;
          }

          fl_return_value = (s_gx_flocal)1;
          l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING | GFX_MGR02_TV2_FB_UPDATED);
        }
      }
    }
    else
    {
      fl_return_value = hmi_gfx_mgr02_tv2_build_image(p_cntx_SP, p_elem_def_SP);
    }

    return(fl_return_value);
  }
#endif

  s_gx_flocal hmi_gfx_mgr02_tv2_clear_buffer(GFX_MGR02_CONTEXT_T const* p_cntx_SP, UINT32 p_clear_color)
  {
    UINT8  fl_rgba[4];
    SINT32  ret = CYGFX_OK;
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    {
      fl_rgba[0] = GM2_IRIS_R(p_clear_color); /* R */
      fl_rgba[1] = GM2_IRIS_G(p_clear_color); /* G */
      fl_rgba[2] = GM2_IRIS_B(p_clear_color); /* B */
      fl_rgba[3] = GM2_IRIS_A(p_clear_color); /* A */
      IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)fl_rgba[0], (CYGFX_U32)fl_rgba[1], (CYGFX_U32)fl_rgba[2], (CYGFX_U32)fl_rgba[3])));
      IRIS_API_CHECK(ret, CyGfx_BeFill(p_cntx_SP->rprop.pe_ctx, (UINT32)0, (UINT32)0, (UINT32)p_cntx_SP->rprop.fb_w, (UINT32)p_cntx_SP->rprop.fb_h));
      l_tv2_draw_sts = (GFX_MGR02_TV2_FLUSH_PENDING | GFX_MGR02_TV2_FB_UPDATED);
    }
    if (ret == CYGFX_OK)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    return(fl_return_value);
  }
  s_gx_flocal hmi_gfx_mgr02_tv2_finish(void)
  {
    SINT32 ret = CYGFX_OK;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    {
      GFX_MGR02_CONTEXT_T const* fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
      l_tv2_draw_sts &= GFX_MGR02_TV2_NO_FLUSH_PENDING;
#ifdef GFX_MGR02_AMBER_USE_MML_PE_SYNC
      if (fl_context_SP->rprop.wdg_height == (UINT16)0)
      {
        IRIS_API_CHECK(ret, CyGfx_BeGetSync(fl_context_SP->rprop.pe_ctx, l_tv2_be_sync));
        IRIS_API_CHECK(ret, CyGfx_BeFlush(fl_context_SP->rprop.pe_ctx));
      }
#else
      IRIS_API_CHECK(ret, CyGfx_BeFinish(fl_context_SP->rprop.pe_ctx));
#endif
#if(defined(GFX02_DEBUG_INFO)&&defined(GFX_MGR02_AMBER_USE_MML_PE_SYNC))
      gfx_debug("CyGfx_BeGetSync =%X\n", l_tv2_be_sync);
#endif
    }
    else
    {
      l_tv2_draw_sts = (UINT8)0;
    }
    GFX_MGR02_UNUSED_VAR(ret);
    return((s_gx_flocal)l_tv2_draw_sts);
  }

#if defined(GFX_MGR02_CLIPPED_WIDGETS)

  static void hmi_gfx_mgr02_amber_set_clip(GFX_MGR02_CONTEXT_T const* p_cntx_SP, CYGFX_BE_CONTEXT p_pixeng_ctx, UINT32 target, UINT8 p_force_update_u8)
  {
    SINT32 fl_cw = p_cntx_SP->state.clip.ex;
    SINT32 fl_ch = p_cntx_SP->state.clip.ey;
    SINT32 ret = CYGFX_OK;

    fl_cw -= p_cntx_SP->state.clip.sx;
    fl_ch -= p_cntx_SP->state.clip.sy;

    if ((l_tv2_clip_rect[0] != p_cntx_SP->state.clip.sx) ||
      (l_tv2_clip_rect[1] != p_cntx_SP->state.clip.sy) ||
      (l_tv2_clip_rect[2] != fl_cw) ||
      (l_tv2_clip_rect[3] != fl_ch) ||
      (p_force_update_u8 != (UINT8)0))
    {
      SINT32 clip_rect[4];
      clip_rect[0] = p_cntx_SP->state.clip.sx;
      clip_rect[1] = p_cntx_SP->state.clip.sy;
      clip_rect[2] = fl_cw;
      clip_rect[3] = fl_ch;
      IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_pixeng_ctx, target, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
      IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_pixeng_ctx, target));
      IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_pixeng_ctx, target, clip_rect[0], clip_rect[1], (UINT32)clip_rect[2], (UINT32)clip_rect[3]));
      l_tv2_clip_rect[0] = p_cntx_SP->state.clip.sx;
      l_tv2_clip_rect[1] = p_cntx_SP->state.clip.sy;
      l_tv2_clip_rect[2] = fl_cw;
      l_tv2_clip_rect[3] = fl_ch;
    }
    GFX_MGR02_UNUSED_VAR(ret);
  }
#endif

  static void hmi_gfx_mgr02_amber_Mat3x3_Multiply(CYGFX_FLOAT* p_dstmatrix, const CYGFX_FLOAT* p_src_matrix1, const CYGFX_FLOAT* p_src_matrix2)
  {
    p_dstmatrix[0] = (p_src_matrix1[0] * p_src_matrix2[0]) + (p_src_matrix1[3] * p_src_matrix2[1]) + (p_src_matrix1[6] * p_src_matrix2[2]);
    p_dstmatrix[1] = (p_src_matrix1[1] * p_src_matrix2[0]) + (p_src_matrix1[4] * p_src_matrix2[1]) + (p_src_matrix1[7] * p_src_matrix2[2]);
    p_dstmatrix[2] = (p_src_matrix1[2] * p_src_matrix2[0]) + (p_src_matrix1[5] * p_src_matrix2[1]) + (p_src_matrix1[8] * p_src_matrix2[2]);

    p_dstmatrix[3] = (p_src_matrix1[0] * p_src_matrix2[3]) + (p_src_matrix1[3] * p_src_matrix2[4]) + (p_src_matrix1[6] * p_src_matrix2[5]);
    p_dstmatrix[4] = (p_src_matrix1[1] * p_src_matrix2[3]) + (p_src_matrix1[4] * p_src_matrix2[4]) + (p_src_matrix1[7] * p_src_matrix2[5]);
    p_dstmatrix[5] = (p_src_matrix1[2] * p_src_matrix2[3]) + (p_src_matrix1[5] * p_src_matrix2[4]) + (p_src_matrix1[8] * p_src_matrix2[5]);

    p_dstmatrix[6] = (p_src_matrix1[0] * p_src_matrix2[6]) + (p_src_matrix1[3] * p_src_matrix2[7]) + (p_src_matrix1[6] * p_src_matrix2[8]);
    p_dstmatrix[7] = (p_src_matrix1[1] * p_src_matrix2[6]) + (p_src_matrix1[4] * p_src_matrix2[7]) + (p_src_matrix1[7] * p_src_matrix2[8]);
    p_dstmatrix[8] = (p_src_matrix1[2] * p_src_matrix2[6]) + (p_src_matrix1[5] * p_src_matrix2[7]) + (p_src_matrix1[8] * p_src_matrix2[8]);
  }


#if(defined(GFX_MGR02_USE_EXT_FONT_ENGINE) &&  ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))))

  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_move_to(const GFX_MGR02_VECTOR* to, void* user)
  {
    const UINT8 fl_type_u8 = CYGFX_DE_INSTR_MOVE_TO_ABS;
    CYGFX_ERROR ret = CYGFX_OK;

    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)1, &fl_type_u8, to));

    /* If return value is not ok then set to MML_ERR */
    if (ret != CYGFX_OK)
    {
      ret = CYGFX_ERR;
    }

    return (ret);
  }


  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_line_to(const GFX_MGR02_VECTOR* to, void* user)
  {
    const UINT8 fl_type_u8 = CYGFX_DE_INSTR_LINE_TO_ABS;
    CYGFX_ERROR ret = CYGFX_OK;

    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)1, &fl_type_u8, to));

    /* If return value is not ok then set to CYGFX_ERR */
    if (ret != CYGFX_OK)
    {
      ret = CYGFX_ERR;
    }

    return (ret);
  }

  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_conic_to(const GFX_MGR02_VECTOR* control, const GFX_MGR02_VECTOR* to, void* user)
  {
    CYGFX_ERROR ret = CYGFX_OK;
    const UINT8 fl_type_u8 = CYGFX_DE_INSTR_QUAD_TO_ABS;

    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)1, &fl_type_u8, NULL));
    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)2, NULL, control));
    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)2, NULL, to));

    /* If return value is not ok then set to CYGFX_ERR */
    if (ret != CYGFX_OK)
    {
      ret = CYGFX_ERR;
    }

    return (ret);
  }

  static CYGFX_ERROR hmi_gfx_mgr02_amber_outline_cubic_to(const GFX_MGR02_VECTOR* control1, const GFX_MGR02_VECTOR* control2, const GFX_MGR02_VECTOR* to, void* user)
  {
    CYGFX_ERROR ret = CYGFX_OK;
    const UINT8 fl_type_u8 = CYGFX_DE_INSTR_CUBIC_TO_ABS;

    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)1, &fl_type_u8, NULL));
    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)2, NULL, control1));
    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)2, NULL, control2));
    IRIS_API_CHECK(ret, CyGfx_DeAppendPathData((CYGFX_BE_CONTEXT)user, (UINT32)2, NULL, to));

    /* If return value is not ok then set to CYGFX_ERR */
    if (ret != CYGFX_OK)
    {
      ret = CYGFX_ERR;
    }

    return (ret);
  }
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_SPANSION_FT2))
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
  static SINT32 hmi_gfx_mgr02_amber_render_cache_outline_glyph(FT_OutlineGlyph const glyph, CYGFX_BE_CONTEXT p_pixeng_ctx)
  {
    SINT32 ret = CYGFX_OK;

    FT_Outline_Funcs fl_outline_fp =
    {
      &hmi_gfx_mgr02_amber_outline_move_to,
      &hmi_gfx_mgr02_amber_outline_line_to,
      &hmi_gfx_mgr02_amber_outline_conic_to,
      &hmi_gfx_mgr02_amber_outline_cubic_to,
      0, 0
    };

    IRIS_API_CHECK(ret, FT_Outline_Decompose(&glyph->outline, &fl_outline_fp, (void*)p_pixeng_ctx));

    return ret;
  }
#endif

  static SINT32 hmi_gfx_mgr02_amber_render_outline_glyph(FT_GlyphSlot const glyph, CYGFX_BE_CONTEXT p_pixeng_ctx)
  {
    SINT32 ret = CYGFX_OK;

    FT_Outline_Funcs fl_outline_fp =
    {
      &hmi_gfx_mgr02_amber_outline_move_to,
      &hmi_gfx_mgr02_amber_outline_line_to,
      &hmi_gfx_mgr02_amber_outline_conic_to,
      &hmi_gfx_mgr02_amber_outline_cubic_to,
      0, 0
    };

    IRIS_API_CHECK(ret, FT_Outline_Decompose(&glyph->outline, &fl_outline_fp, (void*)p_pixeng_ctx));

    return ret;
  }
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
  static SINT32 hmi_gfx_mgr02_amber_FtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, FT_Face p_face, SINT32 x, SINT32 y, HMI_CHAR const* p_string, UINT32 p_str_length, BOOLEAN p_autohint, CYGFX_FLOAT p_size)
#else
  static SINT32 hmi_gfx_mgr02_amber_FtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, FT_Face p_face, SINT32 x, SINT32 y, HMI_CHAR const* p_string, UINT32 p_str_length, BOOLEAN p_autohint)
#endif  
  {
    SINT32 ret = CYGFX_OK;
    UINT32 fl_index_u32;
    FT_UInt  fl_cur_glyph_index;    /* glyph index */
    FT_UInt  fl_prev_glyph_index = (FT_UInt)0;
    SINT32   fl_pen_pos_s32[2];
    BOOLEAN  fl_usekerning_bool;
    SINT32   fl_draw_x, fl_draw_y;
#if defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
    GFX_MGR02_CONTEXT_T const* fl_context_SP;
    UINT32 fl_font_id;
#endif
#if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
    hb_glyph_position_t* fl_hb_gpos_SP;
    UINT16 fl_str_length;
#endif

#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED  

    FT_Glyph         fl_glyph;
    FTC_ImageTypeRec fl_type;
    FT_Error         fl_error;
    FTC_ImageCache   fl_ftc_image_cache;
#endif   
    IRIS_API_CHECK(ret, CyGfx_DeSetAttribute(p_pixeng_ctx, CYGFX_DE_ATTR_DATA_FORMAT, (UINT32)CYGFX_DE_DATA_FORMAT_S16_6));

    if ((p_face->face_flags & FT_FACE_FLAG_KERNING) == FT_FACE_FLAG_KERNING)
    {
      fl_usekerning_bool = TRUE;
    }
    else
    {
      fl_usekerning_bool = FALSE;
    }

    fl_pen_pos_s32[0] = x * 64;
    fl_pen_pos_s32[1] = y * 64;

#if defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)
    fl_context_SP = hmi_gfx_mgr02_context_get_ptr();
    fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)fl_context_SP->rprop.font_id);
#endif
    for (fl_index_u32 = (UINT32)0; ((fl_index_u32 < p_str_length) && ((HMI_CHAR)0 != p_string[fl_index_u32])); fl_index_u32++)
    {
      if (p_string[fl_index_u32] == (HMI_CHAR)'\n')
      {
        fl_pen_pos_s32[0] = x * 64;
        fl_pen_pos_s32[1] -= (SINT32)((UINT16)p_face->height & 0xffffffc0U);
        fl_prev_glyph_index = (FT_UInt)0;
        continue;
      }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
      if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
      {
        /* After Harfbuzz shaping, p_char is already in glyph_id form */
        fl_cur_glyph_index = p_string[fl_index_u32];
      }
      else
      {
        /* Means there is no complex scripts involved */
        fl_cur_glyph_index = FT_Get_Char_Index(p_face, (FT_ULong)p_string[fl_index_u32]);
      }
#else
      fl_cur_glyph_index = FT_Get_Char_Index(p_face, (FT_ULong)p_string[fl_index_u32]);
#endif

#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
      if (fl_cur_glyph_index == (FT_UInt)0)
      {
        fl_cur_glyph_index = FT_Get_Char_Index(p_face, (FT_ULong)GFX_MGR02_DEFAULT_CHAR);
      }
#endif
      if ((fl_usekerning_bool == (BOOLEAN)CYGFX_TRUE) && (fl_prev_glyph_index != (FT_UInt)0) && (fl_cur_glyph_index != (FT_UInt)0))
      {
        FT_Vector stcKerningDelta;
        (void)FT_Get_Kerning(p_face, fl_prev_glyph_index, fl_cur_glyph_index, (FT_UInt)FT_KERNING_DEFAULT, &stcKerningDelta);
        fl_pen_pos_s32[0] += stcKerningDelta.x;
      }
      fl_draw_x = fl_pen_pos_s32[0]/64;
      fl_draw_y = fl_pen_pos_s32[1]/64;
      fl_prev_glyph_index = fl_cur_glyph_index;
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
      UINT32 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(fl_font_id);
      fl_type.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
      fl_type.width = (FT_UInt)p_size;
      fl_type.height = (FT_UInt)p_size;
      if (p_autohint != FALSE)
      {
        fl_type.flags = (FT_LOAD_DEFAULT | FT_LOAD_FORCE_AUTOHINT);
      }
      else
      {
        fl_type.flags = FT_LOAD_DEFAULT;
      }
      fl_ftc_image_cache = hmi_gfx_mgr02_get_ft2_imgcache_handler();
      fl_error = FTC_ImageCache_Lookup(fl_ftc_image_cache, &fl_type, fl_cur_glyph_index, &fl_glyph, NULL);
      if (((FT_Glyph_Format)FT_GLYPH_FORMAT_OUTLINE == fl_glyph->format) && (fl_error == 0))
      {
        IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_render_cache_outline_glyph((FT_OutlineGlyph)fl_glyph, p_pixeng_ctx));
        IRIS_API_CHECK(ret, CyGfx_DeDraw(p_pixeng_ctx, ((CYGFX_FLOAT)fl_pen_pos_s32[0] / 64.0F), ((CYGFX_FLOAT)fl_pen_pos_s32[1] / 64.0F)));
        fl_pen_pos_s32[0] += (fl_glyph->advance.x / 1024);
        fl_pen_pos_s32[1] += (fl_glyph->advance.y / 1024);
      }
      if (fl_error != FALSE)
#endif
      {
        if (p_autohint != FALSE)
        {
          IRIS_API_CHECK(ret, FT_Load_Glyph(p_face, fl_cur_glyph_index, (FT_LOAD_DEFAULT | FT_LOAD_FORCE_AUTOHINT)));
        }
        else
        {
          IRIS_API_CHECK(ret, FT_Load_Glyph(p_face, fl_cur_glyph_index, FT_LOAD_DEFAULT));
        }
        if ((FT_Glyph_Format)FT_GLYPH_FORMAT_OUTLINE == p_face->glyph->format)
        {
          IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_render_outline_glyph(p_face->glyph, p_pixeng_ctx));
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED    
          if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            fl_draw_x += l_shaper_info.shaper_out_ptr->gpos_info[fl_index_u32].x_offset;
            fl_draw_y -= l_shaper_info.shaper_out_ptr->gpos_info[fl_index_u32].y_offset;
          }
#endif


          IRIS_API_CHECK(ret, CyGfx_DeDraw(p_pixeng_ctx, (CYGFX_FLOAT)fl_draw_x, (CYGFX_FLOAT)fl_draw_y));
          fl_pen_pos_s32[0] += p_face->glyph->advance.x;
          fl_pen_pos_s32[1] += p_face->glyph->advance.y;
        }
      }
    }

    return ret;
  }
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_MONOTYPE) && defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))
  static SINT32 hmi_gfx_mgr02_amber_MtTextOut(CYGFX_BE_CONTEXT p_pixeng_ctx, GFX_MGR02_CONTEXT_T   const* p_cntx_SP, SINT32 p_draw_x, SINT32 p_draw_y, HMI_CHAR const* p_string, UINT32 p_str_length, GFX_UINT p_autohint)
  {
    SINT32     ret = CYGFX_OK;
    UINT32     fl_index_u32;
    SINT32     fl_draw_x = p_draw_x;
    SINT32     fl_draw_y = p_draw_y;
    FS_USHORT  fl_cur_glph_index;
    FS_OUTLINE const* fl_outln = NULL;
    FS_FIXED   const* x, * y;
    FS_FIXED   x0 = 0, y0 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    FS_SHORT   fl_num;
    HMI_CHAR const* fl_string_ptr = p_string;

    IRIS_API_CHECK(ret, CyGfx_DeSetAttribute(p_pixeng_ctx, CYGFX_DE_ATTR_DATA_FORMAT, CYGFX_DE_DATA_FORMAT_S32));
    IRIS_API_CHECK(ret, FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_CMAP_OFF));

    for (fl_index_u32 = (UINT32)0; ((fl_index_u32 < p_str_length) && ((HMI_CHAR)0 != fl_string_ptr[fl_index_u32])); fl_index_u32++)
    {

      if (fl_string_ptr[fl_index_u32] == (HMI_CHAR)'\n')
      {
        continue;
      }

      if (p_autohint != (GFX_UINT)0)
      {
        IRIS_API_CHECK(ret, FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_AUTOHINT_ON));
      }
      else
      {
        IRIS_API_CHECK(ret, FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_AUTOHINT_OFF));
      }
#if defined (GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
      if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
      {
        /* Shape engine will take care of default character , so need not to check cmap char check*/
        fl_cur_glph_index = fl_string_ptr[fl_index_u32];
        fl_outln = FS_get_outline((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_ULONG)fl_cur_glph_index);
      }
      else
      {
        fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[fl_index_u32]);
        if (fl_cur_glph_index != (FS_USHORT)0)
        {
          fl_outln = FS_get_outline((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_ULONG)fl_cur_glph_index);
        }
        else
        {
#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
          fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR);
          fl_outln = FS_get_outline((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_ULONG)fl_cur_glph_index);
#endif
        }
      }
#else
      fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[fl_index_u32]);
      if (fl_cur_glph_index != (FS_USHORT)0)
      {
        fl_outln = FS_get_outline((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_ULONG)fl_cur_glph_index);
      }
      else
      {
#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
        fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR);
        fl_outln = FS_get_outline((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_ULONG)fl_cur_glph_index);
#endif
      }
#endif


      if (fl_outln != GFX_MGR02_NULL_PTR)
      {
        x = fl_outln->x;
        y = fl_outln->y;
        for (fl_num = 0; fl_num < fl_outln->num; fl_num++)
        {
          switch (fl_outln->type[fl_num] & GFX_MGR02_AMBER_OUTLN_MASK)
          {
          case FS_MOVETO:
          {
            GFX_MGR02_VECTOR values;
            x0 = *x++;
            y0 = *y++;
            x0 >>= (UINT8)16;
            y0 >>= (UINT8)16;
            values.x = x0;
            values.y = y0;
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_outline_move_to(&values, p_pixeng_ctx));
            break;
          }
          case FS_LINETO:
          {
            GFX_MGR02_VECTOR values;
            x0 = *x++;
            y0 = *y++;
            x0 >>= (UINT8)16;
            y0 >>= (UINT8)16;
            values.x = x0;
            values.y = y0;
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_outline_line_to(&values, p_pixeng_ctx));
            break;
          }
          case FS_QUADTO:
          {
            GFX_MGR02_VECTOR control, to;
            x0 = *x++;
            y0 = *y++;
            x1 = *x++;
            y1 = *y++;
            x0 >>= (UINT8)16;
            y0 >>= (UINT8)16;
            x1 >>= (UINT8)16;
            y1 >>= (UINT8)16;
            control.x = x0;
            control.y = y0;
            to.x = x1;
            to.y = y1;
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_outline_conic_to(&control, &to, p_pixeng_ctx));
            break;
          }
          case FS_CUBETO:
          {
            GFX_MGR02_VECTOR control1, control2, to;
            x0 = *x++;
            y0 = *y++;
            x1 = *x++;
            y1 = *y++;
            x2 = *x++;
            y2 = *y++;
            x0 >>= (UINT8)16;
            y0 >>= (UINT8)16;
            x1 >>= (UINT8)16;
            y1 >>= (UINT8)16;
            x2 >>= (UINT8)16;
            y2 >>= (UINT8)16;
            control1.x = x0;
            control1.y = y0;
            control2.x = x1;
            control2.y = y1;
            to.x = x2;
            to.y = y2;
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_outline_cubic_to(&control1, &control2, &to, p_pixeng_ctx));
            break;
          }
          default:
          {
            /*To Fix MISRA warning.*/
            break;
          }

          }
        }

#if defined (GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)    
        if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
        {
          TsShaperText* fl_shaper_info = l_shaper_info.shaper_out_ptr;
          TsTextProcessInfo* textInfo = &fl_shaper_info->textInfoArray[fl_index_u32];
          SINT32     fl_draw_glyph_x;
          SINT32     fl_draw_glyph_y;

          fl_draw_glyph_x = fl_draw_x;
          fl_draw_glyph_y = fl_draw_y;
          fl_draw_glyph_x += textInfo->advance.x;
          fl_draw_glyph_y -= textInfo->advance.y;
          IRIS_API_CHECK(ret, CyGfx_DeDraw(p_pixeng_ctx, (CYGFX_FLOAT)fl_draw_glyph_x, (CYGFX_FLOAT)fl_draw_glyph_y));
        }
        else
        {
          IRIS_API_CHECK(ret, CyGfx_DeDraw(p_pixeng_ctx, (CYGFX_FLOAT)fl_draw_x, (CYGFX_FLOAT)fl_draw_y));
        }
#else
        IRIS_API_CHECK(ret, CyGfx_DeDraw(p_pixeng_ctx, (CYGFX_FLOAT)fl_draw_x, (CYGFX_FLOAT)fl_draw_y));
#endif          
        fl_draw_x += (fl_outln->dx >> (SINT32)16);
        IRIS_API_CHECK(ret, FS_free_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_OUTLINE*)fl_outln));
      }
    }
    return ret;
  }
#endif



#ifdef GFX_MGR02_WIDGET_WARPING_ENABLED
  s_gx_flocal hmi_gfx_mgr02_amber_start_warping(GFX_MGR02_CONTEXT_GB_T* p_build,
    GFX_MGR02_ELEM_LIST_T const* p_elem_list)
  {
    s_gx_flocal result = (s_gx_flocal)FALSE;
    GFX_MGR02_WIDGET_DEF_T const* fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list->base_id];
    SINT32  ret = CYGFX_OK;
    CYGFX_U32  fl_bpp_size_U32 = 0;

    /* At this point we already have a frame buffer where the widget will be build.
     * To perform warping transformation we need middle buffer. Something like this:
     * Build the widget inside buffer T1, then do warp transformation with Pixel engine T1 -> FB
     * So we allocate the temporary buffer T1 here.
     * We will free the temporary buffer in hmi_gfx_mgr02_amber_finish_warping but original frame buffer will stay
     * allocated for longer period. So to avoid memory fragmentation, its very important to allocate
     * the temporary buffer AFTER the frame buffer of the widget.
     */
    if ((NULL != p_build->pe_tsurf) && (GFX_MGR02_INVALID_WARP != fl_widget_desc_SP->warp_id))
    {
      void* fl_temp_fb_ptr;
      IrisMemInfo fl_memory_s;
      IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(p_build->pe_tsurf,
        MML_GDC_SURF_ATTR_SIZEINBYTES,
        &fl_bpp_size_U32));

      /* allocate memory for the temporary frame buffer */
      fl_memory_s.MemCateg = IRIS_WDG_WARP_TEMP_BUFFER;
      fl_memory_s.WidgetClientId = p_build->client_id;
      fl_memory_s.Alignment = (CYGFX_U32)32; /*32 Byte alignement*/
      fl_memory_s.Size = (CYGFX_U32)fl_bpp_size_U32;
      fl_memory_s.ExtMemory = (UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
      fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif
      fl_temp_fb_ptr = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);

      if (NULL != fl_temp_fb_ptr)
      {
        /* assign the temporary buffer to the surface */
        IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_build->pe_tsurf,
          CYGFX_SM_ATTR_VIRT_ADDRESS,
          (CYGFX_U32)fl_temp_fb_ptr));

        if (ret == CYGFX_OK)
        {
          result = (s_gx_flocal)TRUE;
        }
      }
    }

    return(result);
  }

  void hmi_gfx_mgr02_amber_finish_warping(GFX_MGR02_CONTEXT_GB_T* p_build,
    GFX_MGR02_ELEM_LIST_T const* p_elem_list)
  {
    void* fl_temp_fb_ptr = NULL;
    SINT32  ret = CYGFX_OK;
    GFX_MGR02_WIDGET_DEF_T const* fl_widget_desc_SP = &lc_swidget_layer_def_S[p_elem_list->base_id];
    GFX_MGR02_WARP_ID warp_id = fl_widget_desc_SP->warp_id;
    CYGFX_U32 fl_width, fl_height, fl_surf_format;

    CYGFX_SURFACE_OBJECT_S    fl_target;
    CYGFX_BE_CONTEXT_OBJECT_S fl_pe_ctx;
    void* fl_buff_ptr = (void*)l_warp_table[warp_id].warp_buffer;
    /* Create a surface for the target */
    IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(&fl_target));

    IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(p_build->pe_tsurf,
      CYGFX_SM_ATTR_WIDTH,
      &fl_width));
    IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(p_build->pe_tsurf,
      CYGFX_SM_ATTR_HEIGHT,
      &fl_height));
    IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(p_build->pe_tsurf,
      MML_GDC_SURF_ATTR_SURF_FORMAT,
      &fl_surf_format));

    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(&fl_target,
      fl_width,
      fl_height,
      (CYGFX_SM_FORMAT)fl_surf_format,
      p_build->render_buffer,
      (UINT32)0));

    /* Prepare pixel engine context */
    IRIS_API_CHECK(ret, CyGfx_BeResetContext(&fl_pe_ctx));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(&fl_pe_ctx, CYGFX_BE_CTX_ATTR_RENDER_MODE, p_build->render_mode));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(&fl_pe_ctx, CYGFX_BE_CTX_ATTR_TASK, p_build->priority));

    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(&fl_pe_ctx, CYGFX_BE_TARGET_STORE, &fl_target));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(&fl_pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(&fl_pe_ctx, CYGFX_BE_TARGET_SRC, p_build->pe_tsurf));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(&fl_pe_ctx, CYGFX_BE_CTX_ATTR_COLOR, (CYGFX_U32)0));

    if (warp_id < l_warp_table_size)
    {

      IRIS_API_CHECK(ret, CyGfx_BeSetWarpCoordinateBuffer(&fl_pe_ctx,
        (const MML_GDC_WARP_PARAM*)(l_warp_table[warp_id].warp_params),
        fl_buff_ptr,
        NULL));
    }
    /* Do synchronous blit (wait for the pixel engine to finish) */
    IRIS_API_CHECK(ret, CyGfx_BeBlt(&fl_pe_ctx, 0.0F, 0.0F));

    IRIS_API_CHECK(ret, CyGfx_BeFinish(&fl_pe_ctx));

    /* Release the memory for the temporary buffer */
    IRIS_API_CHECK(ret, CyGfx_SmGetAttribute(p_build->pe_tsurf,
      CYGFX_SM_ATTR_VIRT_ADDRESS,
      (CYGFX_U32*)fl_temp_fb_ptr));
    hmi_gfx_mgr02_amber_mem_mgmt_free(fl_temp_fb_ptr);

    /* Restore the frame buffer of the target surface */
    IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(p_build->pe_tsurf,
      CYGFX_SM_ATTR_VIRT_ADDRESS,
      (CYGFX_U32)p_build->render_buffer));
    GFX_MGR02_UNUSED_VAR(ret);
  }

#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))&& !defined(GFX_STRING_CACHE_ENABLED)
  static void draw_outline_string(CYGFX_FLOAT x, GFX_MGR02_CONTEXT_T  const* p_cntx_SP, CYGFX_SM_FORMAT  p_surf_format, HMI_CHAR const* p_string_p, GFX_MGR02_FONT const* p_font_SP, UINT8* p_draw_color, UINT32 p_str_length)
  {

    void* fl_temp_buffer;
    IrisMemInfo fl_memory_s;
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_txt_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_txt_surf;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    HMI_CHAR     const* fl_string_ptr = p_string_p;
    CYGFX_FLOAT fl_glyph_draw_x = x;
    CYGFX_FLOAT fl_glyph_draw_y = (CYGFX_FLOAT)p_cntx_SP->state.loc.y;

    SINT32 ret = CYGFX_OK;
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)))
    const GFX_MGR02_FONT_SIZE_T* fl_font_size_SP = &(p_cntx_SP->rprop.font_size);
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
    UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
#endif

    fl_mml_gdc_txt_surf = &fl_mml_gdc_txt_surf_c;
    /*Reset the surface for the context*/
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_DST, NULL));

    /* Draw Foreground*/
    IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));

    fl_memory_s.MemCateg = IRIS_TEXT_TEMP_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFU;
    fl_memory_s.Alignment = (UINT32)32; /*32 Byte alignement*/
#if(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
    fl_memory_s.Size = ((CYGFX_U32)p_cntx_SP->rprop.text_width * (UINT32)p_font_SP->p.height * 4U);
#else
    fl_memory_s.Size = ((CYGFX_U32)p_cntx_SP->rprop.text_width * (UINT32)fl_font_size_SP->height * 4U);
#endif
    fl_memory_s.ExtMemory = (UINT8)0; /*It is expected that the Instruction Buffer must be in VRAM*/
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif    
    fl_temp_buffer = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);

#if(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)p_font_SP->p.height, CYGFX_SM_FORMAT_A8R8G8B8, fl_temp_buffer, (UINT32)0));
#elif (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_size_SP->height, CYGFX_SM_FORMAT_A8, fl_temp_buffer, (UINT32)0));
#else
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_size_SP->height, CYGFX_SM_FORMAT_A8R8G8B8, fl_temp_buffer, (UINT32)0));
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, fl_mml_gdc_txt_surf));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_COLOR, (CYGFX_U32)0));
#if(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
    IRIS_API_CHECK(ret, CyGfx_BeFill(p_cntx_SP->rprop.pe_ctx, (UINT32)0, (UINT32)0, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)p_font_SP->p.height));
#else 
    IRIS_API_CHECK(ret, CyGfx_BeFill(p_cntx_SP->rprop.pe_ctx, (UINT32)0, (UINT32)0, (UINT32)p_cntx_SP->rprop.text_width, (UINT32)fl_font_size_SP->height));
#endif

    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_BOTTOM_LEFT));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)1);
#endif
    /* Define the color for text. */
    IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)p_draw_color[0], (CYGFX_U32)p_draw_color[1], (CYGFX_U32)p_draw_color[2], (CYGFX_U32)p_draw_color[3])));
    if (p_draw_color[3] < (UINT8)255)
    {
      IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD));

      IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));
      /* Setting CYGFX_BE_SURF_ATTR_COLORMULTI as TRUE has been removed after Defect 1106955.By default it will be FALSE */
      IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
    }

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_FtTextOut(p_cntx_SP->rprop.pe_ctx,
      p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face,
      0,
      (SINT32)(((-((GFX_FLOAT)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face->descender * (GFX_FLOAT)p_cntx_SP->rprop.font_size.point_size))) / ((GFX_FLOAT)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face->units_per_EM)),
      fl_string_ptr,
      p_str_length,
      (BOOLEAN)p_font_SP->is_autohint,
      p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size
    ));
#else
    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_FtTextOut(p_cntx_SP->rprop.pe_ctx,
      p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face,
      0,
      (SINT32)(((-((GFX_FLOAT)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face->descender * (GFX_FLOAT)p_cntx_SP->rprop.font_size.point_size))) / (((GFX_FLOAT))p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face->units_per_EM)),
      fl_string_ptr,
      p_str_length,
      (BOOLEAN)p_font_SP->is_autohint
    ));
#endif
#else
#if defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
    FS_FIXED fl_asc = 0;
    FS_FIXED fl_dsc = 0;
    FS_FIXED fl_led = 0;
    FsAscDescLeadSource fl_src;

    IRIS_API_CHECK(ret, FS_get_ascender_descender_leading((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, &fl_asc, &fl_dsc, &fl_led, &fl_src));
    fl_dsc >>= 16;

    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_MtTextOut(p_cntx_SP->rprop.pe_ctx,
      p_cntx_SP,
      0,
      (fl_dsc),
      fl_string_ptr,
      p_str_length,
      p_font_SP->is_autohint
    ));
#endif
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
    IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)p_draw_color[0], (CYGFX_U32)p_draw_color[1], (CYGFX_U32)p_draw_color[2], (CYGFX_U32)p_draw_color[3])));
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, p_cntx_SP->rprop.pe_tsurf));
    /*Do transformations if any*/
    utMat3x3LoadIdentity(fl_matrix1);
    utMat3x3LoadIdentity(fl_matrix2);
    utMat3x3Translate(fl_matrix1, fl_glyph_draw_x, fl_glyph_draw_y);
    hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, &p_cntx_SP->state.matrix[0]);
    utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
    IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_amber_set_clip(p_cntx_SP, p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_STORE, (UINT8)1);
#endif
    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));

    IRIS_API_CHECK(ret, CyGfx_BeFinish(p_cntx_SP->rprop.pe_ctx));
    if (fl_temp_buffer != NULL)
    {
      hmi_gfx_mgr02_amber_mem_mgmt_free(fl_temp_buffer);
    }

    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));

  }
#endif
#if !defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&& !defined(GFX_STRING_CACHE_ENABLED)
static void draw_windows_bmp_string(CYGFX_FLOAT x,GFX_MGR02_CONTEXT_T  const *p_cntx_SP,
                                    CYGFX_SM_FORMAT p_surf_format,HMI_CHAR const * p_string_p,UINT32 p_full_text_width,
                                    GFX_MGR02_FONT const * p_font_SP,UINT8 const * p_draw_color,UINT32 p_str_length
                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                    ,UINT16 p_scroll_offset
                                    #endif
                                     )
{
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_txt_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_txt_surf;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    HMI_CHAR     const* fl_string_ptr = p_string_p;
    CYGFX_FLOAT fl_glyph_draw_x = x;
    CYGFX_FLOAT fl_glyph_draw_y = (CYGFX_FLOAT)p_cntx_SP->state.loc.y;
    SINT16 fl_glyph_width;
    SINT16 fl_glyph_height;
    CYGFX_FLOAT gpos_delta_x;
    CYGFX_FLOAT gpos_delta_y;
    GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
    void * vImgAddr;
    UINT32 fl_str_length=p_str_length;
    UINT8 fl_font_charSpace = p_font_SP->char_space;
    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    UINT16 fl_scroll_offset = p_scroll_offset;
#endif
    SINT32 ret = CYGFX_OK;

    fl_mml_gdc_txt_surf = &fl_mml_gdc_txt_surf_c;
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
    SINT16 fl_glyph_advance_x = 0;
#endif
#endif
    SINT32 fl_str_index = (SINT32)0;
    GFX_FLOAT fl_resultantX = 0.0F;
    GFX_FLOAT fl_resultantY = 0.0F;
    IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)0, (UINT32)0, p_surf_format, (void*)0, (UINT32)0));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
    IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)p_draw_color[0], (CYGFX_U32)p_draw_color[1], (CYGFX_U32)p_draw_color[2], (CYGFX_U32)p_draw_color[3])));
    if (p_draw_color[3] < (UINT8)255)
    {
      IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD));

      IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));
      /* Setting CYGFX_BE_SURF_ATTR_COLORMULTI as TRUE has been removed after Defect 1106955.By default it will be FALSE */
      IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
    }
    utMat3x3LoadIdentity(fl_matrix1);
    utMat3x3LoadIdentity(fl_matrix2);
    utMat3x3Translate(fl_matrix1, fl_glyph_draw_x, fl_glyph_draw_y);
    hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, p_cntx_SP->state.matrix);
    utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
    fl_glyph_draw_x = (CYGFX_FLOAT)0;
    while (fl_str_length > (UINT32)0)
    {
      fl_str_length--;
      fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], p_font_SP->f.lut_ptr, (UINT32)p_font_SP->size_table,
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
        (UINT32)(p_cntx_SP->rprop.font_id),
#endif
        (UINT32)FALSE);
      if (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
      {
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        /*Clip rectangle used to clip start and end of the character based on the scroll offset*/
        SINT32 fl_scroll_clip_rect[4];
#endif
        fl_glyph_width = (SINT16)fl_font_fcc_SP->width;
        fl_glyph_height = (SINT16)fl_font_fcc_SP->height;

        if (fl_font_fcc_SP->fdata != NULL)/*Valid font data*/
        {
          GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0F, 0.0F };
          /*
            Deviation from Rule:MISRA C 2012 Rule11.8 :Pointer Type Conversions
            Justification: The type casting font data to void pointer can't be avoided.
          */
          vImgAddr = (void*)fl_font_fcc_SP->fdata;

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          GFX_MGR02_GPOS_DELTA fl_gpos_info = { 0.0F, 0.0F };
          BOOLEAN fl_gpos_found = FALSE;
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if ((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U)
#else
          if (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U)
#endif
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (&fl_string_ptr[-1]), fl_str_index, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
            /*X offset of the mark char should be positioned based on the previouse base char.
            For LTR languages, mark char will come after the base char. While rendering base char
            we are moving the x position based on owidth of the same. Hence the mark char
            position is adjusted based on previous base char position.
            Here fl_glyph_advance_x holds the owidth of the previous char*/
            fl_delta_pixels.gpos_delta_pixels_x -= (GFX_FLOAT)(fl_glyph_advance_x);
          }
          else
          {
            fl_glyph_advance_x = 0;
          }
          /*Store the owidth of the current char if is there any GPOS table found for the current and next char
          combination*/
          fl_gpos_found = hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_gpos_info, &fl_string_ptr[0], fl_str_index, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if (((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U)) ||
            ((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U)))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if ((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U))
#else
          if ((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U))
#endif
          {
            fl_glyph_advance_x += (SINT16)fl_font_fcc_SP->owidth;
          }
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U)
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
          }
#endif /* GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_HEBREW_VOWEL(fl_string_ptr[0]) == 1U)
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);

          }
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */
#endif /* GFX_MGR02_FONT_GPOS_TABLE_ENABLED */
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          {
            SINT16 fl_displayWidth = 0;
            SINT32 fl_fdata_x_soffset = (SINT32)(fl_font_fcc_SP->x_soffset) + (SINT32)(fl_delta_pixels.gpos_delta_pixels_x);
            /*There is no change in y and height for scrolling. Hence using the default values*/
            fl_scroll_clip_rect[1] = 0;
            fl_scroll_clip_rect[3] = (SINT32)fl_glyph_height;
            UINT32 fl_fittable_width = p_full_text_width;
            if(fl_fittable_width > p_cntx_SP->rprop.text_width)
            {
              fl_fittable_width = p_cntx_SP->rprop.text_width;
            }
            /*Apply start x offset to cut the first part of the character based on scroll offset*/
            if (fl_scroll_offset > 0U)
            {
              /*
                x scroll offset may be any one of the below three region
                1. Less than the glyph region - Clip start x should be 0 since clip area is for the actual glyph area
                2. With in the glyph area     - Clip start x should be calculated from the actual glyph area.
                i.e clip_x = scroll_start_x - x_soffset(font data x offset)
                3. More than the glyph area   - Character to be skipped
                */
              fl_scroll_clip_rect[0] = ((SINT32)(fl_scroll_offset) < fl_fdata_x_soffset) ?
                0 : ((SINT32)(fl_scroll_offset)-(SINT32)(fl_fdata_x_soffset));
            }
            else
            {
              fl_scroll_clip_rect[0] = 0;
            }

            fl_scroll_clip_rect[2] = ((SINT32)fl_glyph_width) - (fl_scroll_clip_rect[0]);
            /*Width of the str*/
            fl_displayWidth = (SINT16)(fl_glyph_draw_x + fl_fdata_x_soffset + fl_glyph_width);
            if (fl_displayWidth > (SINT16)fl_fittable_width)
            {
              fl_scroll_clip_rect[2] = (SINT32)((SINT32)fl_glyph_width - (SINT32)((SINT32)fl_displayWidth - (SINT32)fl_fittable_width));
            }
          }
          if ((fl_scroll_clip_rect[2] > 0) && (fl_scroll_clip_rect[0] >= 0))/*Valid clip area*/
#endif
          {
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
            if ((p_full_text_width > p_cntx_SP->rprop.text_width) && (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
            {
              if((p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT) && (fl_str_length == (p_str_length - 1U)))
              {
                fl_scroll_clip_rect[0] += (SINT32)(p_full_text_width - p_cntx_SP->rprop.text_width);
              }
              if((p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_LEFT) && (fl_str_length == 0))
              {
                fl_scroll_clip_rect[2] = (SINT32)(fl_font_fcc_SP->owidth - (p_full_text_width - p_cntx_SP->rprop.text_width));
              }
            }
            IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC));
            IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_scroll_clip_rect[0], fl_scroll_clip_rect[1],
              (UINT32)fl_scroll_clip_rect[2], (UINT32)fl_scroll_clip_rect[3]));
#endif
            if ((p_full_text_width > p_cntx_SP->rprop.text_width) && (p_cntx_SP->rprop.alignment == (UINT8)GFX_MGR02_TP_ALIGN_RIGHT) && (p_cntx_SP->rprop.clip_mode == (UINT8)GFX_MGR02_TP_CLIP_NORMAL) && (fl_str_length == (p_str_length - 1U)))
            {
              fl_glyph_draw_x -= (CYGFX_FLOAT)(p_full_text_width - p_cntx_SP->rprop.text_width);
            }
            gpos_delta_x = (fl_delta_pixels.gpos_delta_pixels_x + 0.5f);

            gpos_delta_y = (fl_delta_pixels.gpos_delta_pixels_y + 0.5f);

            fl_resultantX = (GFX_FLOAT)((fl_glyph_draw_x + fl_font_fcc_SP->x_soffset + gpos_delta_x)
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              -(GFX_FLOAT)fl_scroll_offset
#endif
              );

            fl_resultantY = (GFX_FLOAT)(((GFX_FLOAT)fl_font_fcc_SP->y_soffset) - (GFX_FLOAT)gpos_delta_y);
            utMat3x3Translate(fl_matrix2, fl_resultantX, fl_resultantY);

            IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
            utMat3x3Translate(fl_matrix2, -fl_resultantX, -fl_resultantY);
          }
        }
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
        if (fl_font_fcc_SP->owidth != 0U)
        {
          fl_glyph_draw_x -= (CYGFX_FLOAT)(fl_scroll_offset);
          fl_scroll_offset = 0U;
        }
#endif
        fl_glyph_draw_x = fl_glyph_draw_x + (CYGFX_FLOAT)fl_font_fcc_SP->owidth + (CYGFX_FLOAT)fl_font_charSpace;
      }
      fl_string_ptr++;
      fl_str_index++;
    }

    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));

  }
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
  static void draw_freetype_bmp_string(SINT32 x, GFX_MGR02_CONTEXT_T const* p_cntx_SP, MML_GDC_SURF_FORMAT p_surf_format, HMI_CHAR const* p_string
    , GFX_MGR02_FONT const* p_font_SP, UINT8 const* p_draw_color, UINT32 p_str_length
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
      ,GFX_MGR02_TXT_SPECIAL_EFFECTS* p_txt_special_prop_SP
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    , UINT16 p_scroll_offset
    , UINT32 p_text_width
    , GFX_UINT p_alignment
#endif
  )
  {
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_txt_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_txt_surf;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    HMI_CHAR     const* fl_string = p_string;
    SINT16 fl_glyph_draw_x = (SINT16)x;
    SINT16 fl_glyph_draw_y = p_cntx_SP->state.loc.y;
    UINT32 fl_glyph_width = 0;
    UINT32 fl_glyph_height = 0;
    SINT16 fl_glyph_adj_pos_x = 0;
    SINT16 fl_glyph_adj_pos_y = 0;
    SINT16 fl_glyph_advance_x = 0;
    SINT16 fl_base_height = 0;
    void* vImgAddr;
    UINT32 fl_str_length = p_str_length;
    SINT32 ret = CYGFX_OK;
    UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
    GFX_MGR02_FONT const* fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
    if (fl_font_SP != GFX_MGR02_NULL_PTR)
    {
      BOOLEAN fl_autohint = fl_font_SP->is_autohint;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
      SINT32 fl_scroll_clip_rect[4];
      UINT16 fl_scroll_offset = p_scroll_offset;
#endif
      if (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
      {
        FT_Face fl_face = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
        FTC_ImageCache fl_ftc_image_cache;
        FTC_ImageTypeRec fl_type;
        FT_Glyph fl_glyph;
        FT_Error fl_error = FT_Err_Ok;
        FTC_Manager fl_ftc_manager = hmi_gfx_mgr02_get_ft2_cachemgr_handler();
        UINT8 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(fl_font_id);
        fl_error = FTC_Manager_LookupFace(fl_ftc_manager, (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index], &fl_face);
        if (fl_error == FT_Err_Ok)
        {
          FT_Size fl_asize = GFX_MGR02_NULL_PTR;
          FTC_ScalerRec fl_scaler;
          UINT8 fl_font_size = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
          fl_scaler.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
          fl_scaler.width = 0U;
          fl_scaler.height = (FT_UInt)((GFX_FLOAT)fl_font_size * 64.0F);
          fl_scaler.pixel = 0;
          fl_scaler.x_res = GFX_MGR02_DPI;
          fl_scaler.y_res = GFX_MGR02_DPI;
          fl_error = FTC_Manager_LookupSize(fl_ftc_manager, &fl_scaler, &fl_asize);
          if ((fl_error == FT_Err_Ok) && (fl_asize != GFX_MGR02_NULL_PTR))
          {
            fl_error = FT_Activate_Size(fl_asize);
            fl_face = fl_asize->face;
            if (fl_error != FT_Err_Ok)
            {
#ifdef GFX02_DEBUG_INFO
              gfx_debug("Error in FT_Activate_Size \n");
#endif
            }
          }
        }
        else
        {
#ifdef GFX02_DEBUG_INFO
          gfx_debug("Error in FTC_Manager_LookupFace \n");
#endif
        }
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        GFX_MGR02_HB_SHAPE_INFO *fl_shaper_out_ptr = (GFX_MGR02_HB_SHAPE_INFO *)l_shaper_info.shaper_out_ptr;
#endif
        FT_UInt fl_cur_glyph_index = 0U;
        fl_mml_gdc_txt_surf = &fl_mml_gdc_txt_surf_c;
        IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));
        IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf,
                                                 (UINT32)0,
                                                 (UINT32)0,
                                                 p_surf_format,
                                                 (void *)0,
                                                 (UINT32)0));
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
        IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx,
                                                     CYGFX_BE_TARGET_SRC,
                                                     CYGFX_BE_SURF_ATTR_COLOR,
                                                     CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)p_draw_color[0],
                                                                            (CYGFX_U32)p_draw_color[1],
                                                                            (CYGFX_U32)p_draw_color[2],
                                                                            (CYGFX_U32)p_draw_color[3])));
        if (p_draw_color[3] < (UINT8)255)
        {
          IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
                                                CYGFX_BE_BM_GL_FUNC_ADD,
                                                CYGFX_BE_BM_GL_FUNC_ADD,
                                                CYGFX_BE_BM_GL_FUNC_ADD,
                                                CYGFX_BE_BM_GL_FUNC_ADD));
          IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx,
                                                CYGFX_BE_BF_GL_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_SRC_ALPHA,
                                                CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx,
                                                       CYGFX_BE_TARGET_SRC,
                                                       CYGFX_BE_SURF_ATTR_ALPHAMULTI,
                                                       (UINT32)TRUE));
        }
        utMat3x3LoadIdentity(fl_matrix1);
        utMat3x3LoadIdentity(fl_matrix2);
        utMat3x3Translate(fl_matrix1, (GFX_FLOAT)(fl_glyph_draw_x), (GFX_FLOAT)(fl_glyph_draw_y));
        hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, p_cntx_SP->state.matrix);
        utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
        fl_glyph_draw_x = 0;
        fl_glyph_draw_y = 0;
        fl_base_height = (SINT16)((fl_font_SP->height_pts / (GFX_FLOAT)fl_face->units_per_EM) * ((GFX_FLOAT)(fl_face->ascender)));
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        if (fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
        {
          fl_str_length = fl_shaper_out_ptr->glyph_count;
        }
#endif
        for (UINT32 fl_index_u32 = 0; fl_index_u32 < fl_str_length; fl_index_u32++)
        {
          fl_glyph_adj_pos_x = 0;
          fl_glyph_adj_pos_y = 0;
          vImgAddr = GFX_MGR02_NULL_PTR;
          fl_glyph_width = 0;
          fl_glyph_height = 0;
          fl_glyph_advance_x = 0;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if (fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            // String processed for append, text fit etc is in fl_string. So read the data from fl_string.
            if (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS)
            {
              fl_cur_glyph_index = fl_shaper_out_ptr->code_point[fl_index_u32];
            }
            else if (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_UNICODE)
            {
              fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)fl_string[fl_index_u32]);
            }
            else
            {
              fl_cur_glyph_index = 0U;
            }
          }
          else
          {
            fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)fl_string[fl_index_u32]);
          }
#else
          fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)fl_string[fl_index_u32]);
#endif
#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
          if (fl_cur_glyph_index == (FT_UInt)0)
          {
            fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)GFX_MGR02_DEFAULT_CHAR);
          }
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
          BOOLEAN fl_bitmap_done = FALSE;
          if (p_txt_special_prop_SP != GFX_MGR02_NULL_PTR)
          {
            if (p_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
            {
              if (fl_autohint != FALSE)
              {
                IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, (FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT)));
              }
              else
              {
                IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, FT_LOAD_RENDER));
              }
              FT_GlyphSlot_AdjustWeight(fl_face->glyph, GFX_MGR02_DEFAULT_BOLD_WEIGHT, GFX_MGR02_DEFAULT_BOLD_WEIGHT);
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)  && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
                {
                  fl_glyph_advance_x = hmi_gfx_mgr02_embold_glyph_advance(fl_face->glyph, (SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32]);
                }
                else
#endif
              {
                fl_glyph_advance_x = ((SINT16)(fl_face->glyph->advance.x >> 6)); /* advance.x is in 26.6 format */
              }
              FT_GlyphSlot fl_glyphslot = fl_face->glyph;
              fl_glyph_width = (UINT32)fl_glyphslot->bitmap.width;
              fl_glyph_height = (UINT32)fl_glyphslot->bitmap.rows;
              fl_glyph_adj_pos_x = (SINT16)fl_glyphslot->bitmap_left;
              fl_glyph_adj_pos_y = (SINT16)fl_glyphslot->bitmap_top;
              vImgAddr = (void *)fl_glyphslot->bitmap.buffer;
              fl_bitmap_done = TRUE;
            }
          }
          if (fl_bitmap_done == FALSE)
#endif
          {
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
            fl_type.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
            fl_type.width = (FT_UInt)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
            fl_type.height = (FT_UInt)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
            fl_type.flags = FT_LOAD_RENDER;
            if (fl_autohint != FALSE)
            {
              fl_type.flags |= FT_LOAD_FORCE_AUTOHINT;
            }
            fl_ftc_image_cache = hmi_gfx_mgr02_get_ft2_imgcache_handler();
            fl_error = FTC_ImageCache_Lookup(fl_ftc_image_cache, &fl_type, fl_cur_glyph_index, &fl_glyph, NULL);
            if (fl_error == FT_Err_Ok)
            {
              if (fl_glyph->format == FT_GLYPH_FORMAT_BITMAP)
              {
                FT_BitmapGlyph cached_glyph = (FT_BitmapGlyph)fl_glyph;
                fl_glyph_width = (UINT32)cached_glyph->bitmap.width;
                fl_glyph_height = (UINT32)cached_glyph->bitmap.rows;
                fl_glyph_adj_pos_x = (SINT16)cached_glyph->left;
                fl_glyph_adj_pos_y = (SINT16)(cached_glyph->top);
                vImgAddr = (void *)cached_glyph->bitmap.buffer;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)  && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
                {
                  fl_glyph_advance_x = (SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32];
                }
                else
#endif
                {
                  fl_glyph_advance_x = ((SINT16)(cached_glyph->root.advance.x >> 16)); /* advance.x is in 16.16 format */
                }
              }
              else
              {
                fl_error = FT_Err_Invalid_Glyph_Format;
              }
            }
            if (fl_error != FT_Err_Ok)
#endif
            {
              /*If FT cache disabled or glyph not found in cache*/
              FT_GlyphSlot fl_glyphslot = fl_face->glyph;
              if (fl_autohint != FALSE)
              {
                IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, (FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT)));
              }
              else
              {
                IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, FT_LOAD_RENDER));
              }
              fl_glyph_width = (UINT32)fl_glyphslot->bitmap.width;
              fl_glyph_height = (UINT32)fl_glyphslot->bitmap.rows;
              fl_glyph_adj_pos_x = (SINT16)fl_glyphslot->bitmap_left;
              fl_glyph_adj_pos_y = (SINT16)fl_glyphslot->bitmap_top;
              vImgAddr = (void *)fl_glyphslot->bitmap.buffer;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)  && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
              {
                fl_glyph_advance_x = (SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32];
              }
              else
#endif
              {
                fl_glyph_advance_x = ((SINT16)(fl_glyphslot->advance.x >> 6)); /* advance.x is in 26.6 format */
              }
            }
          }
          /*Common block */
          if ((vImgAddr != GFX_MGR02_NULL_PTR) && (fl_glyph_width > 0) && (fl_glyph_height > 0))
          {
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            SINT16 fl_displayWidth = 0;
            SINT32 fl_fdata_x_soffset = fl_glyph_adj_pos_x;
            UINT8 fl_valid_clip = 0U;
            fl_scroll_clip_rect[0] = 0;
            fl_scroll_clip_rect[1] = 0;
            fl_scroll_clip_rect[3] = (SINT32)fl_glyph_height;
            if (fl_scroll_offset > 0U)
            {
              if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
              {
                fl_scroll_clip_rect[0] = (p_text_width - (SINT32)(p_cntx_SP->rprop.text_width) - (SINT32)(fl_scroll_offset));
              }
              else
              {
                fl_scroll_clip_rect[0] = (SINT32)fl_scroll_offset;
              }
            }
            fl_scroll_clip_rect[2] = ((SINT32)fl_glyph_width) - (fl_scroll_clip_rect[0]);
            fl_displayWidth = (SINT16)(fl_glyph_draw_x + fl_fdata_x_soffset + fl_glyph_width);
            if (fl_displayWidth > (SINT16)p_text_width)
            {
              fl_scroll_clip_rect[2] = (SINT32)((SINT32)fl_glyph_width - (SINT32)((SINT32)p_text_width - (SINT32)fl_displayWidth));
            }
            if ((fl_scroll_clip_rect[2] > 0) && (fl_scroll_clip_rect[0] >= 0)) /*Valid clip area*/
            {
              fl_valid_clip = 1U; // clip is valid for all chars but last char
            }
            else
            {
              fl_scroll_clip_rect[0] = 0;
              fl_scroll_clip_rect[2] = fl_glyph_adj_pos_y;
              if (fl_scroll_clip_rect[2] > 0)
              {
                fl_valid_clip = 1U;
              }
            }
            if (fl_valid_clip > 0U)
#endif
            {
              fl_glyph_adj_pos_y = (SINT16)fl_base_height - (SINT16)fl_glyph_adj_pos_y;
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              if (fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
              {
                fl_glyph_adj_pos_x += (SINT16)(fl_shaper_out_ptr->x_offset[fl_index_u32]);
                fl_glyph_adj_pos_y -= (SINT16)(fl_shaper_out_ptr->y_offset[fl_index_u32]);
              }
#endif
              fl_glyph_adj_pos_x += fl_glyph_draw_x;
              fl_glyph_adj_pos_y += fl_glyph_draw_y;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
              IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC));
              IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_scroll_clip_rect[0], fl_scroll_clip_rect[1],
                                                     (UINT32)fl_scroll_clip_rect[2], (UINT32)fl_scroll_clip_rect[3]));
              utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(fl_glyph_adj_pos_x - fl_scroll_offset), (GFX_FLOAT)fl_glyph_adj_pos_y);
#else
              utMat3x3Translate(fl_matrix2, (GFX_FLOAT)fl_glyph_adj_pos_x, (GFX_FLOAT)fl_glyph_adj_pos_y);
#endif
              IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
              IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
              IRIS_API_CHECK(ret, CyGfx_BeFinish(p_cntx_SP->rprop.pe_ctx));
              utMat3x3Translate(fl_matrix2, -(GFX_FLOAT)fl_glyph_adj_pos_x, -(GFX_FLOAT)fl_glyph_adj_pos_y);
              fl_glyph_draw_x += fl_glyph_advance_x;
            }
          }
          else
          {
            if ((fl_glyph_width == 0) && (fl_glyph_advance_x > 0))
            {
              fl_glyph_draw_x += fl_glyph_advance_x;
            }
          }
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          if (fl_glyph_width > (UINT32)0)
          {
            fl_scroll_offset = 0U;
          }
#endif
          fl_glyph_draw_y = 0;
        }
        IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));
      }
    }
  }
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&& !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) &&  !defined(GFX_STRING_CACHE_ENABLED))
  static void draw_monotype_bmp_string(SINT32 x, GFX_MGR02_CONTEXT_T  const* p_cntx_SP, CYGFX_SM_FORMAT p_surf_format, HMI_CHAR const* p_string_p,UINT32 p_full_text_width
    , GFX_MGR02_FONT const* p_font_SP, UINT8* p_draw_color, UINT32 p_str_length
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
    , UINT16 p_ml_str_index, GFX_MGR02_SHAPE_ML_DATA* p_ML_data_ptr, u_gx_flocal p_is_multi_line_text
    , GFX_MGR02_SHAPE_FLAGS* p_shape_flags
#endif
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    , UINT16 p_scroll_offset
    , GFX_UINT p_alignment
#endif
  )
  {
    CYGFX_SURFACE_OBJECT_S fl_mml_gdc_txt_surf_c;
    CYGFX_SURFACE           fl_mml_gdc_txt_surf;
    CYGFX_FLOAT fl_matrix1[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    CYGFX_FLOAT fl_matrix2[9] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };
    HMI_CHAR     const* fl_string_ptr = p_string_p;
    SINT16 fl_glyph_draw_x = x;
    SINT16 fl_glyph_draw_y = p_cntx_SP->state.loc.y;
    SINT16 fl_glyph_width;
    SINT16 fl_glyph_height;
    void* vImgAddr;
    UINT32 fl_str_length = p_str_length;
    SINT32 codeUnitsConsumed = 1;
    UINT32 fl_char_count = HMI_STRLEN(fl_string_ptr);
    SINT32 ret = CYGFX_OK;
    FS_FIXED fl_asc = 0;
    FS_FIXED fl_dsc = 0;
    FS_FIXED fl_led = 0;
    FsAscDescLeadSource fl_src;
    SINT16 fl_prev_pos_x;
    UINT8 fl_font_charSpace= p_font_SP->char_space;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
    GFX_MGR02_SHAPE_ML_DATA* fl_ML_data_ptr = p_ML_data_ptr;
    UINT32 fl_ml_str_index = p_ml_str_index;
    GFX_MGR02_SHAPE_FLAGS* fl_shape_flags = p_shape_flags;
#endif
    UINT16  fl_index = 0U;
#endif

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    /*Clip rectangle used to clip start and end of the character based on the scroll offset*/
    SINT32 fl_scroll_clip_rect[4];
    UINT16 fl_scroll_offset = p_scroll_offset;
#endif

    fl_mml_gdc_txt_surf = &fl_mml_gdc_txt_surf_c;

    IRIS_API_CHECK(ret, CyGfx_SmResetSurfaceObject(fl_mml_gdc_txt_surf));
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(fl_mml_gdc_txt_surf, (UINT32)0, (UINT32)0, p_surf_format, (void*)0, (UINT32)0));

    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_mml_gdc_txt_surf));
    IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)p_draw_color[0], (CYGFX_U32)p_draw_color[1], (CYGFX_U32)p_draw_color[2], (CYGFX_U32)p_draw_color[3])));
    if (p_draw_color[3] < (UINT8)255)
    {
      IRIS_API_CHECK(ret, CyGfx_BeBlendMode(p_cntx_SP->rprop.pe_ctx,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD,
        CYGFX_BE_BM_GL_FUNC_ADD));

      IRIS_API_CHECK(ret, CyGfx_BeBlendFunc(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA,
        CYGFX_BE_BF_GL_SRC_ALPHA, CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA));

      /* Setting CYGFX_BE_SURF_ATTR_COLORMULTI as TRUE has been removed after Defect 1106955.By default it will be FALSE */
      IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_ALPHAMULTI, (UINT32)TRUE));
    }

    (void)FS_get_ascender_descender_leading((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, &fl_asc, &fl_dsc, &fl_led, &fl_src);
    fl_asc >>= (UINT8)16;

    utMat3x3LoadIdentity(fl_matrix1);
    utMat3x3LoadIdentity(fl_matrix2);
    utMat3x3Translate(fl_matrix1, (GFX_FLOAT)(fl_glyph_draw_x), (GFX_FLOAT)(fl_glyph_draw_y));
    hmi_gfx_mgr02_amber_Mat3x3_Multiply(fl_matrix2, fl_matrix1, p_cntx_SP->state.matrix);
    utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x), (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
    fl_prev_pos_x = 0;
    fl_glyph_draw_x = 0;
    fl_glyph_draw_y = 0;
    while (fl_str_length > (UINT32)0)
    {
      UINT32 fl_current_char;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
      if (p_is_multi_line_text != 0U)
      {
        fl_current_char = (UINT32)fl_string_ptr[0];
      }
      else
#endif
      {
        fl_current_char = TsUniEnc_decodeUTF16(fl_string_ptr, fl_char_count, &codeUnitsConsumed);
        fl_char_count -= (UINT32)codeUnitsConsumed;
        if (codeUnitsConsumed > 1)
        {
          fl_string_ptr += (codeUnitsConsumed - 1);
        }
      }

      fl_str_length--;
      if (p_font_SP->is_ffile != 0U)
      {
        FS_GLYPHMAP const* fl_vg_glyph_SP;
        FS_USHORT glphtype;
        switch (p_surf_format)
        {
        case CYGFX_SM_FORMAT_A1:
          glphtype = (FS_USHORT)FS_MAP_BITMAP;
          break;
        case CYGFX_SM_FORMAT_A2:
          glphtype = (FS_USHORT)FS_MAP_GRAYMAP2;
          break;
        case CYGFX_SM_FORMAT_A4:
          glphtype = (FS_USHORT)FS_MAP_GRAYMAP4;
          break;
        case CYGFX_SM_FORMAT_A8:
        default:
          glphtype = (FS_USHORT)FS_MAP_GRAYMAP8;
          break;
        }
#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))
        if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
        {
          /* Shape engine will take care of default character , so need not to check cmap char check*/
          fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
        }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        else
        {
          if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE))
          {
            /* Switch OFF CMAP table when the current character is
            ** (a) Unicode or (b) not matches with original string data
            ** (b) case can be occur only when there is still is data is pending to
            ** show on to display then we are appending ...
            */
            if ((fl_ML_data_ptr->is_character[fl_ml_str_index] == 1U) ||
              (fl_ML_data_ptr->input_string[fl_ml_str_index] != fl_string_ptr[0]))
            {
              UINT16 fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_ML_data_ptr->input_string[fl_ml_str_index]);
              if (fl_cur_glph_index != 0U)
              {
                /* set the flag so that get_glyph functions will turn ON cmap      */
                (void)FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_CMAP_ON);
                fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[0], glphtype);
                /* set the flag so that get_glyph functions will turn OFF cmap      */
                (void)FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_CMAP_OFF);
              }
              else
              {
                fl_vg_glyph_SP = GFX_MGR02_NULL_PTR;
              }
            }
            else
            {
              /* Shape engine will take care of default character , so need not to check cmap char check*/
              fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[0], glphtype);
            }
          }
          else
          {
            /* If shaping is not done for this string, then check whether character is exist in the font */
            if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0)
            {
              fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
            }
            else
            {
              /* render defalt character configured in hmi_gfx_mgr02.cfg*/
              fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
            }
          }
        }
#else
        else
        {
          /* If shaping is not done for this string, then check whether character is exist in the font */
          if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0)
          {
            fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
          }
          else
          {
            /* render defalt character configured in hmi_gfx_mgr02.cfg*/
            fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
          }
        }
#endif
#else
        if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0)
        {
          fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
        }
        else
        {
          /* render default character configured in hmi_gfx_mgr02.cfg*/
          fl_vg_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
        }
#endif
        if (fl_vg_glyph_SP != GFX_MGR02_NULL_PTR)
        {
          fl_glyph_width = (SINT16)fl_vg_glyph_SP->width;
          fl_glyph_height = (SINT16)fl_vg_glyph_SP->height;
#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE))
          if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            TsShaperText* fl_shaper_out_ptr = (TsShaperText*)l_shaper_info.shaper_out_ptr;
            TsTextProcessInfo* textInfo = &fl_shaper_out_ptr->textInfoArray[fl_index];
            fl_glyph_draw_x = (fl_prev_pos_x + (VGfloat)fl_vg_glyph_SP->lo_x + textInfo->advance.x);
            fl_glyph_draw_y = (fl_glyph_draw_y + (fl_asc - fl_vg_glyph_SP->hi_y - textInfo->advance.y));
          }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
          else
          {
            /* Take GPOS delta values only when below conditions met
          ** (a) current text is a multiline
          ** (b) display string belongs to complex script
          ** (c) Current character is matches with original string character
          */
            if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE) &&
              (fl_ML_data_ptr->input_string[fl_ml_str_index] == fl_string_ptr[0]))
            {
              fl_glyph_draw_x = (fl_prev_pos_x + fl_vg_glyph_SP->lo_x + fl_ML_data_ptr->delta_val[fl_ml_str_index].delta_pixels_x);
              fl_glyph_draw_y = (fl_glyph_draw_y + (fl_asc - fl_vg_glyph_SP->hi_y - fl_ML_data_ptr->delta_val[fl_ml_str_index].delta_pixels_y));
            }
            else
            {
              fl_glyph_draw_x = fl_prev_pos_x + (VGfloat)fl_vg_glyph_SP->lo_x;
              fl_glyph_draw_y = fl_glyph_draw_y + (VGfloat)(fl_asc - fl_vg_glyph_SP->hi_y);
            }
          }
#else
          else
          {
            fl_glyph_draw_x = fl_prev_pos_x + (VGfloat)fl_vg_glyph_SP->lo_x;
            fl_glyph_draw_y = fl_glyph_draw_y + (VGfloat)(fl_asc - fl_vg_glyph_SP->hi_y);
          }
#endif
#else
          fl_glyph_draw_x = fl_prev_pos_x + (VGfloat)fl_vg_glyph_SP->lo_x;
          fl_glyph_draw_y = fl_glyph_draw_y + (VGfloat)(fl_asc - fl_vg_glyph_SP->hi_y);
#endif

          if (fl_vg_glyph_SP->height > (FS_SHORT)0)
          {
            vImgAddr = (void*)fl_vg_glyph_SP->bits;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            SINT16 fl_displayWidth = 0;
            SINT32 fl_fdata_x_soffset = fl_vg_glyph_SP->lo_x;
            UINT8 fl_valid_clip = 0U;
            fl_scroll_clip_rect[0] = 0;
            fl_scroll_clip_rect[1] = 0;
            fl_scroll_clip_rect[3] = (SINT32)fl_glyph_height;
            UINT32 fl_fittable_width = p_full_text_width;
            if (fl_fittable_width > p_cntx_SP->rprop.text_width)
            {
              fl_fittable_width = p_cntx_SP->rprop.text_width;
            }
            if (fl_scroll_offset > 0U)
            {
              if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
              {
                fl_scroll_clip_rect[0] = ((SINT32)fl_fittable_width - (SINT32)(p_cntx_SP->rprop.text_width) - (SINT32)(fl_scroll_offset));
              }
              else
              {
                fl_scroll_clip_rect[0] = (SINT32)fl_scroll_offset;
              }
            }
            fl_scroll_clip_rect[2] = ((SINT32)fl_glyph_width) - (fl_scroll_clip_rect[0]);
            fl_displayWidth = (SINT16)(fl_glyph_draw_x + fl_fdata_x_soffset + fl_glyph_width);
            if (fl_displayWidth > (SINT16)fl_fittable_width)
            {
              fl_scroll_clip_rect[2] = (SINT32)((SINT32)fl_glyph_width - (SINT32)( (SINT32)fl_fittable_width- (SINT32)fl_displayWidth));
            }
            if ((fl_scroll_clip_rect[2] > 0) && (fl_scroll_clip_rect[0] >= 0))/*Valid clip area*/
            {
              fl_valid_clip = 1U;   //clip is valid for all chars but last char
            }
            else
            {
              //clip area handling for last char, if width is available
              fl_scroll_clip_rect[0] = 0;
              fl_scroll_clip_rect[2] = fl_vg_glyph_SP->i_dx;
              if (fl_scroll_clip_rect[2] > 0)
              {
                fl_valid_clip = 1U;
              }
            }
            if (fl_valid_clip > 0U)
#endif
            {
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
              IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(fl_mml_gdc_txt_surf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
              IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_USE_CLIPPING, (UINT32)TRUE));
              if ((p_full_text_width > p_cntx_SP->rprop.text_width) && (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
                if (p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                { 
                  if (fl_str_length == (p_str_length - 1U))
                  {
                    fl_scroll_clip_rect[0] += (SINT32)(p_full_text_width - p_cntx_SP->rprop.text_width);
                  }
                  fl_glyph_draw_x -= (SINT16)(p_full_text_width - p_cntx_SP->rprop.text_width);
                }
                if ((p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_LEFT) && (fl_str_length == 0U))
                {
                  fl_scroll_clip_rect[2] = (SINT32)fl_vg_glyph_SP->i_dx - (SINT32)(p_full_text_width - p_cntx_SP->rprop.text_width);
                }
              }
              IRIS_API_CHECK(ret, CyGfx_BeSelectArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC));
              IRIS_API_CHECK(ret, CyGfx_BeActiveArea(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, fl_scroll_clip_rect[0], fl_scroll_clip_rect[1],
                (UINT32)fl_scroll_clip_rect[2], (UINT32)fl_scroll_clip_rect[3]));
              utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(fl_glyph_draw_x - fl_scroll_offset), (GFX_FLOAT)fl_glyph_draw_y);
#else
              if ((p_full_text_width > p_cntx_SP->rprop.text_width) && (p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT) && (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
              {
                fl_glyph_draw_x -= (SINT16)(p_full_text_width - p_cntx_SP->rprop.text_width);
              }
              utMat3x3Translate(fl_matrix2, (GFX_FLOAT)(fl_glyph_draw_x), (GFX_FLOAT)fl_glyph_draw_y);
#endif
              IRIS_API_CHECK(ret, CyGfx_BeSetGeoMatrix(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, CYGFX_BE_GEO_MATRIX_FORMAT_3X3, fl_matrix2));
              IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(p_cntx_SP->rprop.pe_ctx, 0.0F, 0.0F));
              utMat3x3Translate(fl_matrix2, -(GFX_FLOAT)fl_glyph_draw_x, -(GFX_FLOAT)fl_glyph_draw_y);
              fl_prev_pos_x = fl_prev_pos_x + (SINT16)(fl_vg_glyph_SP->i_dx + fl_font_charSpace);
            }
          }
          else
          {
            if ((fl_vg_glyph_SP->width == 0) && (fl_vg_glyph_SP->i_dx > 0))
            {
              //space like chars
              fl_prev_pos_x = fl_prev_pos_x + (SINT16)(fl_vg_glyph_SP->i_dx + fl_font_charSpace);
            }
          }
          (void)FS_free_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_VOID*)fl_vg_glyph_SP);

#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
          if (fl_vg_glyph_SP->width > (FS_SHORT)0)
          {
            fl_scroll_offset = 0U;
          }
#endif
          fl_glyph_draw_y = 0;
        }
        fl_string_ptr++;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        fl_index++;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
        fl_ml_str_index++;
#endif
      }
    }
#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)))
    if (l_shaper_info.shaper_out_ptr == GFX_MGR02_NULL_PTR)
    {
      GFX_MGR02_UNUSED_VAR(fl_index);
    }
#endif
    IRIS_API_CHECK(ret, CyGfx_BeFinish(p_cntx_SP->rprop.pe_ctx));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(p_cntx_SP->rprop.pe_ctx, CYGFX_BE_TARGET_SRC, NULL));

  }
#endif

#ifdef GFX_STRING_CACHE_ENABLED
static void hmi_gfx_mgr02_create_img_for_string(UINT8* p_str_img_SP, GFX_MGR02_CONTEXT_T  const* p_cntx_SP, HMI_CHAR const* p_string_p,
    UINT32 p_width, GFX_MGR02_FONT const* p_font_SP
#if (defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE)))
      ,GFX_MGR02_TXT_SPECIAL_EFFECTS* p_txt_special_prop_SP
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
    , UINT16 p_ml_str_index, GFX_MGR02_SHAPE_ML_DATA* p_ML_data_ptr, u_gx_flocal p_is_multi_line_text
    , GFX_MGR02_SHAPE_FLAGS* p_shape_flags
#endif
)
{
#ifndef GFX_MGR02_USE_EXT_FONT_ENGINE
    GFX_MGR02_FONT_CHAR_CONFIG const* fl_font_fcc_SP;
#endif
    HMI_CHAR     const* fl_string_ptr = p_string_p;
    SINT16 fl_glyph_advance_x = 0;
#if !((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    SINT16 fl_glyph_width = 0;
    SINT16 fl_glyph_height = 0;
    GFX_FLOAT fl_glyph_draw_x = (GFX_FLOAT)0;
    GFX_FLOAT fl_glyph_draw_y = (GFX_FLOAT)0;
    SINT32 fl_str_index = (SINT32)0;
#endif  
    UINT32  fl_str_length = HMI_STRLEN(p_string_p);
    UINT8   fl_text_BPP;
    UINT32  fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);

#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
    SINT32 codeUnitsConsumed = 1;
    UINT32 fl_char_count = HMI_STRLEN(fl_string_ptr);
#ifndef GFX_MGRO2_AMBER_MONO_DE_RENDER
    FS_USHORT glphtype;
#endif
    FS_FIXED fl_asc = 0;
    FS_FIXED fl_dsc = 0;
    FS_FIXED fl_led = 0;
    FsAscDescLeadSource fl_src = FsAscDescLeadSource_UNKNOWN;
    fl_text_BPP = p_font_SP->bpp;
#elif defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    FT_Face fl_face = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
    SINT16 fl_base_height = 0;
    fl_text_BPP = p_font_SP->bpp;
    FT_UInt  fl_cur_glyph_index = 0U;
    BOOLEAN fl_valid_glyph = FALSE;
    FT_GlyphSlot fl_glyphslot;
    SINT16 fl_glyph_adj_pos_x = 0;
    SINT16 fl_glyph_adj_pos_y = 0;
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
    FT_Glyph         fl_glyph;
    FTC_ImageTypeRec fl_type;
    FT_Error         fl_error;
    FTC_ImageCache   fl_ftc_image_cache;
    FT_BitmapGlyph cached_glyph;
#endif
#else
    fl_text_BPP = GFX_MGR02_GET_BPP(p_font_SP->f.lut_ptr->attributes);
#endif

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
    GFX_MGR02_HB_SHAPE_INFO* fl_shaper_out_ptr = (GFX_MGR02_HB_SHAPE_INFO*)l_shaper_info.shaper_out_ptr;
    UINT32 fl_index_u32 = 0U;
    if(fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
    {
      fl_str_length = fl_shaper_out_ptr->glyph_count;
    }
#endif

#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || \
     ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
    UINT16 fl_index = 0;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
    GFX_MGR02_SHAPE_ML_DATA* fl_ML_data_ptr = p_ML_data_ptr;
    GFX_MGR02_SHAPE_FLAGS* fl_shape_flags = p_shape_flags;
#endif
    UINT32 fl_ml_str_index = p_ml_str_index;
#endif
#endif
#if ((!((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))))) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    void* vImgAddr;
#endif
    SINT32 ret = CYGFX_OK;
    CYGFX_BE_CONTEXT pectx;
    CYGFX_SURFACE    strsurf = NULL;
    CYGFX_SURFACE    srcsurf = NULL;
    CYGFX_SM_FORMAT surformat;
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    void* fl_temp_buffer;
    void* fl_path_buffer;
    IrisMemInfo fl_memory_s;
#endif
    IRIS_API_CHECK(ret, utPeGenContext(&pectx));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(pectx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
    IRIS_API_CHECK(ret, utSmGenSurfaceObjects((CYGFX_U32)1, &strsurf));
    IRIS_API_CHECK(ret, utSmGenSurfaceObjects((CYGFX_U32)1, &srcsurf));
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    fl_memory_s.MemCateg = IRIS_DE_PATH_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU;
    fl_memory_s.Alignment = (CYGFX_U32)4; /*4 Byte alignement*/
    fl_memory_s.Size = (CYGFX_U32)2048;
    fl_memory_s.ExtMemory = (UINT8)0;
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif
    fl_path_buffer = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
    IRIS_API_CHECK(ret, CyGfx_DeSetPathBuffer(pectx, fl_path_buffer, (CYGFX_U32)fl_memory_s.Size));
#endif

    switch (fl_text_BPP)
    {
        case (UINT8)GFX_MGR02_FONT_ENCODING_1BPP:
        {
          surformat = CYGFX_SM_FORMAT_A1;
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
          glphtype = FS_MAP_BITMAP;
#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
          if ((p_width % (UINT32)8) == (UINT32)0)
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = ((p_width * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)8);
#else
            fl_memory_s.Size = ((p_width * (UINT32)p_font_SP->p.height) / (UINT32)8);
#endif
          }
          else
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = (((((p_width / (UINT32)8) * (UINT32)8) + (UINT32)8) * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)8);
#else
            fl_memory_s.Size = (((((p_width / (UINT32)8) * (UINT32)8) + (UINT32)8) * (UINT32)p_font_SP->p.height) / (UINT32)8);
#endif
          }
#endif
        }
        break;
        case (UINT8)GFX_MGR02_FONT_ENCODING_2BPP:
        {
          surformat = CYGFX_SM_FORMAT_A2;
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
          glphtype = FS_MAP_GRAYMAP2;
#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
          if ((p_width % (UINT32)4) == (UINT32)0)
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = ((p_width * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)4);
#else
            fl_memory_s.Size = ((p_width * (UINT32)p_font_SP->p.height) / (UINT32)4);
#endif
          }
          else
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = (((((p_width / (UINT32)4) * (UINT32)4) + (UINT32)4) * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)4);
#else
            fl_memory_s.Size = (((((p_width / (UINT32)4) * (UINT32)4) + (UINT32)4) * (UINT32)p_font_SP->p.height) / (UINT32)4);
#endif
          }
#endif
        }
        break;
        case (UINT8)GFX_MGR02_FONT_ENCODING_4BPP:
        {
          surformat = CYGFX_SM_FORMAT_A4;
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
          glphtype = FS_MAP_GRAYMAP4;
#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
          if ((p_width % (UINT32)2) == (UINT32)0)
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = ((p_width * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)2);
#else
            fl_memory_s.Size = ((p_width * (UINT32)p_font_SP->p.height) / (UINT32)2);
#endif
          }
          else
          {
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
            fl_memory_s.Size = (((((p_width / (UINT32)2) * (UINT32)2) + (UINT32)2) * (UINT32)p_cntx_SP->rprop.font_size.height) / (UINT32)2);
#else
            fl_memory_s.Size = (((((p_width / (UINT32)2) * (UINT32)2) + (UINT32)2) * (UINT32)p_font_SP->p.height) / (UINT32)2);
#endif
          }
#endif
        }
        break;
        case (UINT8)GFX_MGR02_FONT_ENCODING_8BPP:
        default:
        {
          surformat = CYGFX_SM_FORMAT_A8;
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && !defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
          glphtype = FS_MAP_GRAYMAP8;
#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT)
          fl_memory_s.Size = ((p_width) * (UINT32)p_cntx_SP->rprop.font_size.height);
#else
          fl_memory_s.Size = ((p_width) * (UINT32)p_font_SP->p.height);
#endif
#endif
        }
        break;
    }

#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    fl_memory_s.MemCateg = IRIS_TEXT_TEMP_BUFFER;
    fl_memory_s.WidgetClientId = 0xFFFFFFFFU;
    fl_memory_s.Alignment = (UINT32)32; /*32 Byte alignement*/
    fl_memory_s.ExtMemory = (UINT8)0;
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif
    fl_temp_buffer = hmi_gfx_mgr02_amber_mem_mgmt_malloc(&fl_memory_s);
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT) || (GFX_MGR02_EXT_FONT_ENGINE !=GFX_MGR02_MONOTYPE)
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(srcsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_cntx_SP->rprop.font_size.height,
      surformat,
      fl_temp_buffer,
      (CYGFX_U32)0));
#else
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(srcsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_font_SP->p.height,
      surformat,
      fl_temp_buffer,
      (CYGFX_U32)0));
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, srcsurf));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(pectx, CYGFX_BE_CTX_ATTR_COLOR, (CYGFX_U32)0));
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT) || (GFX_MGR02_EXT_FONT_ENGINE !=GFX_MGR02_MONOTYPE)
    IRIS_API_CHECK(ret, CyGfx_BeFill(pectx, (UINT32)0, (UINT32)0, (UINT32)p_width, (UINT32)p_cntx_SP->rprop.font_size.height));
#else
    IRIS_API_CHECK(ret, CyGfx_BeFill(pectx, (UINT32)0, (UINT32)0, (UINT32)p_width, (UINT32)p_font_SP->p.height));
#endif

#else
#if defined (GFX_MGR02_USE_EXT_FONT_ENGINE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT) || (GFX_MGR02_EXT_FONT_ENGINE !=GFX_MGR02_MONOTYPE))
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(strsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_cntx_SP->rprop.font_size.height,
      surformat,
      p_str_img_SP,
      (CYGFX_U32)0));
#else
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(strsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_font_SP->p.height,
      surformat,
      p_str_img_SP,
      (CYGFX_U32)0));
#endif 

    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, strsurf));
#endif
#if defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
    (void)FS_get_ascender_descender_leading((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, &fl_asc, &fl_dsc, &fl_led, &fl_src);
    fl_asc >>= (UINT8)16;
#endif
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(pectx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_BOTTOM_LEFT));
    IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(pectx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)255)));
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)
    if (fl_font_id < (UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
      IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_FtTextOut(pectx,
        fl_face,
        0,
        (SINT32)(((-((GFX_FLOAT)fl_face->descender * (GFX_FLOAT)p_cntx_SP->rprop.font_size.point_size))) / ((GFX_FLOAT)fl_face->units_per_EM)),
        fl_string_ptr,
        fl_str_length,
        (BOOLEAN)p_font_SP->is_autohint,
        p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size
      ));
#else
      IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_FtTextOut(pectx,
        fl_face,
        0,
        (SINT32)(((-((GFX_FLOAT)fl_face->descender * (GFX_FLOAT)p_cntx_SP->rprop.font_size.point_size))) / ((GFX_FLOAT)fl_face->units_per_EM)),
        fl_string_ptr,
        fl_str_length,
        (BOOLEAN)p_font_SP->is_autohint
      ));
#endif
    }
#else
#if defined(GFX_MGRO2_AMBER_MONO_DE_RENDER)
    fl_dsc >>= 16;
    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_MtTextOut(pectx,
      p_cntx_SP,
      0,
      (fl_dsc),
      fl_string_ptr,
      fl_str_length,
      p_font_SP->is_autohint
    ));
#endif
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, srcsurf));
#if defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT) || (GFX_MGR02_EXT_FONT_ENGINE !=GFX_MGR02_MONOTYPE)
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(strsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_cntx_SP->rprop.font_size.height,
      surformat,
      p_str_img_SP,
      (CYGFX_U32)0));
#else
    IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(strsurf,
      (CYGFX_U32)p_width,
      (CYGFX_U32)p_font_SP->p.height,
      surformat,
      p_str_img_SP,
      (CYGFX_U32)0));
#endif
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_STORE | CYGFX_BE_TARGET_DST, strsurf));
    IRIS_API_CHECK(ret, CyGfx_BeSetAttribute(pectx, CYGFX_BE_CTX_ATTR_ZERO_POINT, CYGFX_BE_ATTR_ZERO_TOP_LEFT));
    IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt(pectx, 0.0F, 0.0F));
#else

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) && defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
    fl_index_u32 = 0;
    fl_base_height = (SINT16)((p_font_SP->height_pts / (GFX_FLOAT)fl_face->units_per_EM) * ((GFX_FLOAT)(fl_face->ascender)));
#endif

    while (fl_str_length > (UINT32)0)
    {
      fl_str_length--;
      
      /* External Font Engine rendering */
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))
      {
        /* Monotype Font Engine based rendering*/
        FS_GLYPHMAP const* fl_glyph_SP;
        UINT32 fl_current_char;
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        if (p_is_multi_line_text != FALSE)
        {
            fl_current_char = (UINT32)fl_string_ptr[0];
        }
        else
#endif
        {
            fl_current_char = TsUniEnc_decodeUTF16(fl_string_ptr, fl_char_count, &codeUnitsConsumed);
            fl_char_count -= codeUnitsConsumed;
            if (codeUnitsConsumed > 1)
            {
              fl_string_ptr += (codeUnitsConsumed - 1);
            }
        }

#if (defined(GFX_MGR02_SHAPE_ENGINE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))
        if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
        {
          /* Shape engine will take care of default character , so need not to check cmap char check*/
          fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
        }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        else
        {
          if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE) && (fl_ml_str_index < GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH))
          {
            /* Switch OFF CMAP table when the current character is
            ** (a) Unicode or (b) not matches with original string data
            ** (b) case can be occur only when there is still is data is pending to
            ** show on to display then we are appending ...
            */
            if ((fl_ML_data_ptr->is_character[fl_ml_str_index] == 1U) ||
              (fl_ML_data_ptr->input_string[fl_ml_str_index] != fl_string_ptr[0]))
            {
              UINT16 fl_cur_glph_index = FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_ML_data_ptr->input_string[fl_ml_str_index]);
              if (fl_cur_glph_index != 0)
              {
                /* set the flag so that get_glyph functions will turn ON cmap      */
                (void)FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_CMAP_ON);
                fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_string_ptr[0], glphtype);
                /* set the flag so that get_glyph functions will turn OFF cmap      */
                (void)FS_set_flags((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, FLAGS_CMAP_OFF);
              }
              else
              {
                fl_glyph_SP = GFX_MGR02_NULL_PTR;
              }
            }
            else
            {
              /* Shape engine will take care of default character , so need not to check cmap char check*/
              fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
            }
          }
          else
          {
            /* If shaping is not done for this string, then check whether character is exist in the font */
            if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0U)
            {
              fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
            }
            else
            {
              /* render defalt character configured in hmi_gfx_mgr02.cfg*/
              fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
            }
          }
        }
#else
        else
        {
          /* If shaping is not done for this string, then check whether character is exist in the font */
          if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0U)
          {
            fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
          }
          else
          {
            /* render defalt character configured in hmi_gfx_mgr02.cfg*/
            fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
          }
        }
#endif
#else
        if (FS_map_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char) != 0U)
        {
          fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, fl_current_char, glphtype);
        }
        else
        {
          /* render defalt character configured in hmi_gfx_mgr02.cfg*/
          fl_glyph_SP = FS_get_glyphmap((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, GFX_MGR02_DEFAULT_CHAR, glphtype);
        }
#endif  
        if (fl_glyph_SP != GFX_MGR02_NULL_PTR)
        {
          UINT8* glyph = NULL;
          fl_glyph_width = (SINT16)fl_glyph_SP->width;
          fl_glyph_height = (SINT16)fl_glyph_SP->height;

#if (defined(GFX_MGR02_SHAPE_ENGINE)) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
          if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            TsShaperText* fl_shaper_out_ptr = (TsShaperText*)l_shaper_info.shaper_out_ptr;
            if (fl_index < fl_shaper_out_ptr->textInfoArrayLen)
            {
              TsTextProcessInfo* textInfo = &fl_shaper_out_ptr->textInfoArray[fl_index];
              fl_glyph_draw_x = (fl_glyph_advance_x + (GFX_FLOAT)fl_glyph_SP->lo_x + textInfo->advance.x);
              fl_glyph_draw_y = (GFX_FLOAT)(fl_glyph_draw_y + (fl_asc - fl_glyph_SP->hi_y - textInfo->advance.y));
            }
          }
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
          else
          {
            /* Take GPOS delta values only when below conditions met
          ** (a) current text is a multiline
          ** (b) display string belongs to complex script
          ** (c) Current character is matches with original string character
          */
            if (fl_ml_str_index < GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH)
            {
              if ((p_is_multi_line_text != FALSE) && (fl_shape_flags->complexity_flag != (UINT8)FALSE) &&
                (fl_ML_data_ptr->input_string[fl_ml_str_index] == fl_string_ptr[0]))
              {
                fl_glyph_draw_x = (fl_glyph_advance_x + (GFX_FLOAT)fl_glyph_SP->lo_x + fl_ML_data_ptr->delta_val[fl_ml_str_index].delta_pixels_x);
                fl_glyph_draw_y = (GFX_FLOAT)(fl_glyph_draw_y + (fl_asc - fl_glyph_SP->hi_y - fl_ML_data_ptr->delta_val[fl_ml_str_index].delta_pixels_y));
              }
              else
              {
                fl_glyph_draw_x = fl_glyph_advance_x + (GFX_FLOAT)fl_glyph_SP->lo_x;
                fl_glyph_draw_y = fl_glyph_draw_y + (GFX_FLOAT)(fl_asc - fl_glyph_SP->hi_y);
              }
            }
          }
#else
          else
          {
            fl_glyph_draw_x = fl_glyph_advance_x + (GFX_FLOAT)fl_glyph_SP->lo_x;
            fl_glyph_draw_y = fl_glyph_draw_y + (GFX_FLOAT)(fl_asc - fl_glyph_SP->hi_y);
          }
#endif
#else
          fl_glyph_draw_x = fl_glyph_advance_x + (GFX_FLOAT)fl_glyph_SP->lo_x;
          fl_glyph_draw_y = fl_glyph_draw_y + (GFX_FLOAT)(fl_asc - fl_glyph_SP->hi_y);
#endif

          glyph = (UINT8*)fl_glyph_SP->bits;
          IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(srcsurf,
            (CYGFX_U32)0,
            (CYGFX_U32)0,
            surformat,
            NULL,
            (CYGFX_U32)0));
          IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, srcsurf));
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(pectx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)255)));
          if (glyph != NULL)
          {
            vImgAddr = (void*)glyph;

            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));
            /*below changes are to correct right alignment in normal clipping mode
            in previous case after the hardcut change in text.c the text gets cut in right end and is to be cut in
            left end. the below code crops the excess width from first character and shift the text overall to left
            by the same.
            This logic is applied only for right alignment in normal clipping mode*/
            if ((p_width > p_cntx_SP->rprop.text_width) && (p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT) && (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL))
            {
              if (fl_str_index == 0)
              {
                SINT32 fl_clip_rect[4];
                fl_clip_rect[0] = p_width - p_cntx_SP->rprop.text_width;
                fl_clip_rect[1] = 0;
                fl_clip_rect[3] = p_font_SP->p.height;
                fl_clip_rect[2] = fl_glyph_width;
                IRIS_API_CHECK(ret, CyGfx_BeSelectArea(pectx, CYGFX_BE_TARGET_SRC));
                IRIS_API_CHECK(ret, CyGfx_BeActiveArea(pectx, CYGFX_BE_TARGET_SRC, fl_clip_rect[0], fl_clip_rect[1],
                  (UINT32)fl_clip_rect[2], (UINT32)fl_clip_rect[3]));
              }
              IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt_ext(pectx, fl_glyph_draw_x - (p_width - p_cntx_SP->rprop.text_width), fl_glyph_draw_y));
            }
            else
            {
              IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt_ext(pectx, fl_glyph_draw_x, fl_glyph_draw_y));
            }
          }
          fl_glyph_advance_x = fl_glyph_advance_x + fl_glyph_SP->i_dx + p_font_SP->char_space;
          fl_glyph_draw_y = (GFX_FLOAT)0;
          (void)FS_free_char((FS_STATE*)&p_cntx_SP->rprop.mt_fs_state, (FS_VOID*)fl_glyph_SP);
        }
      }
#elif (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
      {
        /* Freetype generated bitmap based rendering */
        fl_cur_glyph_index = 0U;
        fl_valid_glyph = FALSE;
        fl_glyph_width = 0;
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
        if (fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
        {
          if (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS)
          {
            fl_cur_glyph_index = fl_shaper_out_ptr->code_point[fl_index_u32];
          }
          else if (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_UNICODE)
          {
            fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)fl_shaper_out_ptr->unicode[fl_index_u32]);
          }
          else
          {
            /* Buffer content is invalid. HB_BUFFER_CONTENT_TYPE_INVALID */
          }
        }
        else
        {
          /* Means there is no complex scripts involved */
          fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)p_string_p[fl_index_u32]);
        }
#else
        fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)p_string_p[fl_index_u32]);
#endif

#if defined(GFX_MGR02_DEFAULT_CHAR) && (GFX_MGR02_DEFAULT_CHAR > 0)
        if (fl_cur_glyph_index == (FT_UInt)0)
        {
          fl_cur_glyph_index = FT_Get_Char_Index(fl_face, (FT_ULong)GFX_MGR02_DEFAULT_CHAR);
        }
#endif
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
        BOOLEAN fl_bitmap_done = FALSE;
        if (p_txt_special_prop_SP != GFX_MGR02_NULL_PTR)
        {
          if (p_txt_special_prop_SP->effect_type == GFX_MGR02_TXT_BOLD_EFFECT)
          {
            if (p_font_SP->is_autohint != FALSE)
            {
              IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, (FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT)));
            }
            else
            {
              IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, FT_LOAD_RENDER));
            }
            FT_GlyphSlot_AdjustWeight(fl_face->glyph, GFX_MGR02_DEFAULT_BOLD_WEIGHT, GFX_MGR02_DEFAULT_BOLD_WEIGHT);
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
              if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR) && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
              {
                fl_glyph_advance_x = hmi_gfx_mgr02_embold_glyph_advance(fl_face->glyph,(SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32]);
              }
              else
#endif
            {
              fl_glyph_advance_x = (SINT16)(fl_face->glyph->advance.x >> 6); /* advance.x is in 26.6 format */
            }
            fl_glyphslot = fl_face->glyph;
            if ((fl_glyphslot->bitmap.buffer != GFX_MGR02_NULL_PTR) && (fl_glyphslot->bitmap.rows > 0U))
            {
              fl_glyph_width = (SINT16)fl_glyphslot->bitmap.width;
              fl_glyph_height = (SINT16)fl_glyphslot->bitmap.rows;
              fl_glyph_adj_pos_x = (SINT16)fl_glyphslot->bitmap_left;
              fl_glyph_adj_pos_y = (SINT16)fl_glyphslot->bitmap_top;
              vImgAddr = (void *)fl_glyphslot->bitmap.buffer;
              fl_valid_glyph = TRUE;
            }
            fl_bitmap_done = TRUE;
          }
        }
        if (fl_bitmap_done == FALSE)
#endif
        {
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
          UINT32 fl_ft2_face_index = hmi_gfx_mgr02_context_get_ft2_face_index(fl_font_id);
          fl_type.face_id = (FTC_FaceID)&lc_gfx_font_table[fl_ft2_face_index];
          fl_type.width = (FT_UInt)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
          fl_type.height = (FT_UInt)p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
          fl_type.flags = FT_LOAD_RENDER;
          if (p_font_SP->is_autohint != FALSE)
          {
            fl_type.flags |= FT_LOAD_FORCE_AUTOHINT;
          }
          fl_ftc_image_cache = hmi_gfx_mgr02_get_ft2_imgcache_handler();
          fl_error = FTC_ImageCache_Lookup(fl_ftc_image_cache, &fl_type, fl_cur_glyph_index, &fl_glyph, NULL);
          if (fl_error == FT_Err_Ok)
          {
            cached_glyph = (FT_BitmapGlyph)fl_glyph;
            if ((cached_glyph->bitmap.buffer != GFX_MGR02_NULL_PTR) && (cached_glyph->bitmap.rows > 0))
            {
              fl_glyph_width = (UINT32)cached_glyph->bitmap.width;
              fl_glyph_height = (UINT32)cached_glyph->bitmap.rows;
              fl_glyph_adj_pos_x = (SINT16)cached_glyph->left;
              fl_glyph_adj_pos_y = (SINT16)(cached_glyph->top);
              vImgAddr = (void *)cached_glyph->bitmap.buffer;
              fl_valid_glyph = TRUE;
            }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)  && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
            {
              fl_glyph_advance_x = (SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32];
            }
            else
#endif
            {
              fl_glyph_advance_x = (SINT16)(cached_glyph->root.advance.x >> 16); /* advance.x is in 16.16 format */
            }
          }
          else
#endif
          {
            fl_glyphslot = fl_face->glyph;
            if (p_font_SP->is_autohint != FALSE)
            {
              IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, (FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT)));
            }
            else
            {
              IRIS_API_CHECK(ret, FT_Load_Glyph(fl_face, fl_cur_glyph_index, FT_LOAD_RENDER));
            }
            if ((fl_glyphslot->bitmap.buffer != GFX_MGR02_NULL_PTR) && (fl_glyphslot->bitmap.rows > 0))
            {
              fl_glyph_width = (SINT16)fl_glyphslot->bitmap.width;
              fl_glyph_height = (SINT16)fl_glyphslot->bitmap.rows;
              fl_glyph_adj_pos_x = (SINT16)fl_glyphslot->bitmap_left;
              fl_glyph_adj_pos_y = (SINT16)fl_glyphslot->bitmap_top;
              vImgAddr = (void *)fl_glyphslot->bitmap.buffer;
              fl_valid_glyph = TRUE;
            }
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
            if ((fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)  && (fl_shaper_out_ptr->content_type[fl_index_u32] == HB_BUFFER_CONTENT_TYPE_GLYPHS))
            {
              fl_glyph_advance_x = (SINT16)fl_shaper_out_ptr->x_advance[fl_index_u32];
            }
            else
#endif
            {
              fl_glyph_advance_x = (SINT16)(fl_glyphslot->advance.x >> 6); /* advance.x is in 26.6 format */
            }
          }
        }
        if (fl_valid_glyph != FALSE)
        {
          fl_glyph_adj_pos_y = (SINT16)fl_base_height - (SINT16)fl_glyph_adj_pos_y;
          IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(srcsurf, (CYGFX_U32)0, (CYGFX_U32)0, surformat, NULL, (CYGFX_U32)0));
          IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, srcsurf));
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(pectx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)255)));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
          IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
          if (fl_shaper_out_ptr != GFX_MGR02_NULL_PTR)
          {
            fl_glyph_adj_pos_x += (SINT16)(fl_shaper_out_ptr->x_offset[fl_index_u32]);
            fl_glyph_adj_pos_y -= (SINT16)(fl_shaper_out_ptr->y_offset[fl_index_u32]);
          }
#endif
          fl_glyph_adj_pos_x += fl_glyph_draw_x;
          fl_glyph_adj_pos_y += fl_glyph_draw_y;
          IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt_ext(pectx,
          (GFX_FLOAT)(fl_glyph_adj_pos_x),
          (GFX_FLOAT)fl_glyph_adj_pos_y));
          IRIS_API_CHECK(ret, CyGfx_BeFinish(pectx));
          fl_glyph_draw_x += fl_glyph_advance_x;
          fl_glyph_draw_y = (GFX_FLOAT)0;
        }
        else
        {
          if ((fl_glyph_width == 0) && (fl_glyph_advance_x > 0))
          {
            fl_glyph_draw_x += fl_glyph_advance_x;
          }
        }
        fl_index_u32++;
      }
#else
      {
        /* Window BMP Font Based Rendering*/
#if !(defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)|| (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
        fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0],
          p_font_SP->f.lut_ptr,
          (UINT32)p_font_SP->size_table,
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
          (UINT32)p_cntx_SP->rprop.font_id,
#endif
          (UINT32)FALSE);
        if (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
        {
          fl_glyph_width = (SINT16)fl_font_fcc_SP->width;
          fl_glyph_height = (SINT16)fl_font_fcc_SP->height;
          GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0F, 0.0F };
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)

#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          GFX_MGR02_GPOS_DELTA fl_gpos_info = { 0.0F, 0.0F };
          BOOLEAN fl_gpos_found = FALSE;

#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if ((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U)
#else
          if (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U)
#endif
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (&fl_string_ptr[-1]), fl_str_index, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
            /*X offset of the mark char should be positioned based on the previous base char.
            For LTR languages, mark char will come after the base char. While rendering base char
            we are moving the x position based on owidth of the same. Hence the mark char
            position is adjusted based on previous base char position.
            Here fl_glyph_advance_x holds the owidth of the previous char*/
            fl_delta_pixels.gpos_delta_pixels_x -= (GFX_FLOAT)(fl_glyph_advance_x);
          }
          else
          {
            fl_glyph_advance_x = 0;
          }
          /*Store the owidth of the current char if is there any GPOS table found for the current and next char
          combination*/
          fl_gpos_found = hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_gpos_info, &fl_string_ptr[0], fl_str_index, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);

#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
          if (((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U)) ||
            ((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U)))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
          if ((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U))
#else
          if ((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U))
#endif
          {
            fl_glyph_advance_x += (SINT16)fl_font_fcc_SP->owidth;
          }
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED  || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)*/
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U)
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
          }
#endif /* GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
          if (GFX_MGR02_IS_HEBREW_VOWEL(fl_string_ptr[0]) == 1U)
          {
            (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, p_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
          }
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */
          fl_glyph_draw_y -= fl_delta_pixels.gpos_delta_pixels_y;
#endif /* GFX_MGR02_FONT_GPOS_TABLE_ENABLED */

          IRIS_API_CHECK(ret, CyGfx_SmAssignBuffer(srcsurf,
            (CYGFX_U32)0,
            (CYGFX_U32)0,
            surformat,
            NULL,
            (CYGFX_U32)0));
          IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, srcsurf));
          IRIS_API_CHECK(ret, CyGfx_BeSetSurfAttribute(pectx, CYGFX_BE_TARGET_SRC, CYGFX_BE_SURF_ATTR_COLOR, CYGFX_SM_COLOR_TO_RGBA((CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)0, (CYGFX_U32)255)));
          if (fl_font_fcc_SP->fdata != NULL)
          {
            vImgAddr = (void*)fl_font_fcc_SP->fdata;

            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_VIRT_ADDRESS, (CYGFX_U32)vImgAddr));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_WIDTH, (UINT32)fl_glyph_width));
            IRIS_API_CHECK(ret, CyGfx_SmSetAttribute(srcsurf, CYGFX_SM_ATTR_HEIGHT, (UINT32)fl_glyph_height));
            IRIS_API_CHECK(ret, hmi_gfx_mgr02_amber_blt_ext(pectx,
              (GFX_FLOAT)(((GFX_FLOAT)fl_glyph_draw_x + (GFX_FLOAT)fl_font_fcc_SP->x_soffset) + fl_delta_pixels.gpos_delta_pixels_x),
              (GFX_FLOAT)(((GFX_FLOAT)fl_glyph_draw_y + (GFX_FLOAT)fl_font_fcc_SP->y_soffset) - fl_delta_pixels.gpos_delta_pixels_y)));
          }
          fl_glyph_draw_x = fl_glyph_draw_x + (GFX_FLOAT)fl_font_fcc_SP->owidth + p_font_SP->char_space;
          fl_glyph_draw_y = (GFX_FLOAT)0;
        }
#endif
      }
#endif 
      fl_string_ptr++;
      fl_str_index++;
#if (defined(GFX_MGR02_SHAPE_ENGINE)) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE))
      fl_index++;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_SHAPE_ENGINE_ENABLED))
      fl_ml_str_index++;
#endif
    }
#endif
    IRIS_API_CHECK(ret, CyGfx_BeFinish(pectx));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_SRC, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_STORE, NULL));
    IRIS_API_CHECK(ret, CyGfx_BeBindSurface(pectx, CYGFX_BE_TARGET_DST, NULL));
    IRIS_API_CHECK(ret, utSmDeleteSurfaceObjects((CYGFX_U32)1, &strsurf));
    IRIS_API_CHECK(ret, utSmDeleteSurfaceObjects((CYGFX_U32)1, &srcsurf));
    utPeDeleteContext(pectx);
#if ((defined(GFX_MGRO2_AMBER_MONO_DE_RENDER) && (GFX_MGR02_EXT_FONT_ENGINE ==GFX_MGR02_MONOTYPE)) || (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)))
    if (fl_temp_buffer != NULL)
    {
      hmi_gfx_mgr02_amber_mem_mgmt_free(fl_temp_buffer);
    }
    if (fl_path_buffer != NULL)
    {
      hmi_gfx_mgr02_amber_mem_mgmt_free(fl_path_buffer);
    }
#else
    GFX_MGR02_UNUSED_VAR(fl_font_id);
#endif
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
#if (defined(GFX_MGR02_SHAPE_ENGINE)) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) && (!defined(GFX_MGRO2_AMBER_MONO_DE_RENDER))
    if (l_shaper_info.shaper_out_ptr != GFX_MGR02_NULL_PTR)
    {
      GFX_MGR02_UNUSED_VAR(fl_index);
    }
#endif
#endif
}

#endif
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
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
** CMS Rev 1.0      05-Jan-2021    SSIGAMAN
** Initial version.
**==========================================================================*/
/* end of file =============================================================*/

