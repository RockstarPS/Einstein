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
** Name:           hmi_gfx_mgr02_vglite.c
**
** Description:    VGLite library interface routines to perform drawing 
**                 operations for graphics manager 02.
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_MGR02_VGLITE_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_VGLITE)
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_vglite.h"
#include "hmi_gfx_mgr02_imxrt.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_cache.h"

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
#include "hmi_gfx_mgr02_sw_compression.h"
#endif

#include "vg_lite_platform.h"

// #define GFX_PERFORMANCE_MEASUREMENT
#if defined(GFX_PERFORMANCE_MEASUREMENT)
#include "Gpt.h"
#include "OsApi.h"
#endif

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define GFX_MGR02_VGLITE_FLUSH_PENDING        ((UINT8)0x01)
#define GFX_MGR02_VGLITE_FB_UPDATED           ((UINT8)0x02)

#define GFX_MGR02_VGLITE_GPU_MEM_BASE         (0x0U)
#define GFX_MGR02_VGLITE_REGISTER_MEM_BASE    (0x41800000U)

#define GFX_MGR02_GET_ALPHA(color)            ((color) >> 24U)
#define GFX_MGR02_MODIFY_ALPHA(color,alpha)   (((color) & 0x00FFFFFFU) | ((alpha) << 24U))
#define GFX_MGR02_ARGB_TO_ABGR(color)         (((color) & 0xFF00FF00U) | (((color) & 0x00FF0000U) >> 16U) | (((color) & 0x000000FFU) << 16U))

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE==GFX_MGR02_FREETYPE))
#define GFX_MGR02_VECTOR  FT_Vector

/* Path data operations. */
#define GFX_MGR02_CDALIGN(value, by) (((value) + (by) - 1) & ~((by) - 1))
#define GFX_MGR02_CDMIN(x, y) (((x) > (y)) ? (y) : (x))
#define GFX_MGR02_CDMAX(x, y) (((x) > (y)) ? (x) : (y))

//#define GFX_MGR02_VGLITE_APPLY_TRANSFORMATION_ON_WHOLE_TEXT
#endif

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE)&&(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
static void hmi_gfx_mgr02_vglite_draw_outline_string(SINT16 p_start_x, GFX_MGR02_CONTEXT_T  const *p_cntx_SP, HMI_CHAR const * p_string_p, GFX_MGR02_FONT const * p_font_SP, vg_lite_color_t p_draw_color, UINT32 p_str_length
                                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                                  , UINT16 p_scroll_offset
                                                  , GFX_UINT p_alignment
                                                    #endif
                                                    );
#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
static UINT32 hmi_gfx_mgr02_vglite_render_cache_outline_glyph(FT_OutlineGlyph const glyph, vg_lite_path_t *p_vgpath);
#endif
static UINT32 hmi_gfx_mgr02_vglite_render_outline_glyph(FT_GlyphSlot const glyph, vg_lite_path_t *p_vgpath);
static UINT32 hmi_gfx_mgr02_vglite_outline_move_to(const GFX_MGR02_VECTOR *to, void *user);
static UINT32 hmi_gfx_mgr02_vglite_outline_line_to(const GFX_MGR02_VECTOR *to, void *user);
static UINT32 hmi_gfx_mgr02_vglite_outline_conic_to(const GFX_MGR02_VECTOR *control, const GFX_MGR02_VECTOR *to, void *user);
static UINT32 hmi_gfx_mgr02_vglite_outline_cubic_to(const GFX_MGR02_VECTOR *control1, const GFX_MGR02_VECTOR *control2, const GFX_MGR02_VECTOR *to, void *user);
static UINT32 hmi_gfx_mgr02_vglite_append_path_data_abs(vg_lite_path_t *path, UINT8 cmd, void *data);
static SINT32 hmi_gfx_mgr02_vglite_get_data_count(UINT8 cmd);
#endif    
static void hmi_gfx_mgr02_vglite_util_matrix_translate(vg_lite_float_t * m2, vg_lite_float_t tx, vg_lite_float_t ty);
static void hmi_gfx_mgr02_vglite_matrix_translate(vg_lite_float_t tx, vg_lite_float_t ty);
static void hmi_gfx_mgr02_vglite_matrix_multiply(vg_lite_float_t const *matrix);
static void hmi_gfx_mgr02_vglite_matrix_load_identity(void);
static SINT32 hmi_gfx_mgr02_vglite_get_bpp(vg_lite_buffer_format_t p_pix_format);
static vg_lite_blend_t hmi_gfx_mgr02_vglite_get_blendmode(GFX_MGR02_CONTEXT_T const * p_cntx_SP, vg_lite_buffer_format_t format);
static vg_lite_buffer_format_t hmi_gfx_mgr02_vglite_get_pixel_format(UINT8 p_pix_format);
#if !defined(GFX_MGR02_IMXRT)
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
#endif
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static void hmi_gfx_mgr02_vglite_set_clip(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
#endif
void GPU2D_IRQHandler(void);
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

#if defined(GFX_PERFORMANCE_MEASUREMENT)
static UINT8 counter = 0u;
static GFX_FLOAT fl_render_time[100];
#endif

static vg_lite_error_t l_vgl_error;
static UINT8 l_vglite_draw_sts;
static vg_lite_matrix_t l_vglite_matrix;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
static vg_lite_rectangle_t l_vglite_clip_rect;
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_init
Description          : Initializes the library's internal variables
Invocation           : Invoked by graphics manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_init(void)
{
  PixEngMemInfo fl_memory_s;
  void *vglite_heap_base = NULL;
  l_vglite_draw_sts     = (UINT8)0;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  l_vglite_clip_rect.x      = 0;
  l_vglite_clip_rect.y      = 0;
  l_vglite_clip_rect.width  = 0;
  l_vglite_clip_rect.height = 0;
#endif
  
  fl_memory_s.MemCateg         = IMXRT_VGLITE_DRIVER_HEAP_MEM;
  fl_memory_s.WidgetClientId   = 0xFFFFFFFFu;
  fl_memory_s.Alignment        = (UINT32)32;
  fl_memory_s.Size             = GFX_MGR02_VGLITE_HEAP_SIZE;
  fl_memory_s.ExtMemory        = (UINT8)1;
  #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
  fl_memory_s.WidgetFBGroupId    = GFX_MGR02_INVALID_FB_GROUP_ID;
  #endif
    
  vglite_heap_base = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
  vg_lite_init_mem(GFX_MGR02_VGLITE_REGISTER_MEM_BASE, GFX_MGR02_VGLITE_GPU_MEM_BASE, vglite_heap_base, GFX_MGR02_VGLITE_HEAP_SIZE);
  
  #if (GFX_MGR02_NUM_OF_SVGS > 0) || (GFX_MGR02_NUM_OF_FILLS > 0) || (GFX_MGR02_NUM_OF_TEXT_LAYERS > 0)
  GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init(GFX_MGR02_VGLITE_TW, GFX_MGR02_VGLITE_TH));
  #else
  GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init(0,0));    
  #endif
  
  GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_set_command_buffer_size(GFX_MGR02_VGLITE_CMDBUF_SIZE));

  return((s_gx_flocal)1);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_vglite_shutdown
** Visibility:       Global
** Description:      This function for closing the vg_lite in shutdown sequence.
**                   
** Invocation:       By hmi_gfx_mgr02_context_shutdown()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
s_gx_flocal hmi_gfx_mgr02_vglite_shutdown(void)
{  
  (void)vg_lite_close();
  return((s_gx_flocal)1);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
  s_gx_flocal fl_ret_value = 0;
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  l_vglite_clip_rect.x = 0;
  l_vglite_clip_rect.y = 0;
  l_vglite_clip_rect.width  = (SINT32)p_cntx_SP->rprop.fb_w;
  l_vglite_clip_rect.height = (SINT32)p_cntx_SP->rprop.fb_h;
  GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_enable_scissor());
  GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_set_scissor(l_vglite_clip_rect.x,l_vglite_clip_rect.y,l_vglite_clip_rect.width,l_vglite_clip_rect.height));
#endif

  l_vglite_draw_sts = 0;
  fl_ret_value = 1;
  return(fl_ret_value);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_finish
Description          : Function to be called after all building operation are
                       completed. This will perform the VG LITE finish to 
                       perform any pending VG operations
Invocation           : Invoked by manager
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
                       drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_finish(void)
{
    if((l_vglite_draw_sts & GFX_MGR02_VGLITE_FLUSH_PENDING) != (UINT8)0)
    {
        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_finish());
        l_vglite_draw_sts = GFX_MGR02_VGLITE_FB_UPDATED;
        
        /* TODO This needs to be moved to shutdown*/
        //vg_lite_close();
    }
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_disable_scissor());  /* TODO Need to check if scissor needs to be disabled once enabled if clip is set*/
#endif

    return((s_gx_flocal)l_vglite_draw_sts);
}

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_set_clip
Description          : Sets the clip area to the passed one if it is new area
Invocation           : Invoked internally
Parameters           : Clip area via context pointer
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_vglite_set_clip(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
  SINT16 fl_clip_w = p_cntx_SP->state.clip.ex - p_cntx_SP->state.clip.sx;;
  SINT16 fl_clip_h = p_cntx_SP->state.clip.ey - p_cntx_SP->state.clip.sy;

  if((l_vglite_clip_rect.x != p_cntx_SP->state.clip.sx) ||
     (l_vglite_clip_rect.y != p_cntx_SP->state.clip.sy) ||
     (l_vglite_clip_rect.width != fl_clip_w) ||
     (l_vglite_clip_rect.height != fl_clip_h))
  {

    l_vglite_clip_rect.x      = p_cntx_SP->state.clip.sx;
    l_vglite_clip_rect.y      = p_cntx_SP->state.clip.sy;
    l_vglite_clip_rect.width  = fl_clip_w;
    l_vglite_clip_rect.height = fl_clip_h;
    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_set_scissor(l_vglite_clip_rect.x,l_vglite_clip_rect.y,l_vglite_clip_rect.width,l_vglite_clip_rect.height));
  }
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_build_fill
Description          : Builds a fill element
Invocation           : Invoked internally
Parameters           : element definition and dimensions of fill area
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, GFX_MGR02_IDIM_DATA  const * p_dim)
{
  s_gx_flocal fl_ret_value = 0;
  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
  {
    vg_lite_buffer_t dstBuffer = {0};
    vg_lite_color_t fl_fill_color = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.fg_color);
    UINT32 fl_fillcolor_alpha = GFX_MGR02_GET_ALPHA(fl_fill_color);
    vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
    SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);

    dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
    dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
    dstBuffer.stride             = (SINT32)p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);
    dstBuffer.format             = fl_dst_pixel_format;
    dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
    dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;

#if defined(GFX_MGR02_CLIPPED_WIDGETS) 
    hmi_gfx_mgr02_vglite_set_clip(p_cntx_SP);
#endif

#if defined(GFX_MGR02_CLIPPED_WIDGETS) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
    if(fl_fillcolor_alpha == 0u)
    {
        /*
        ** If the fill color alpha is zero, treat this as a special case for clearing
        ** the buffer. it is OK since normally an application will not use a fill with
        ** alpha = 0 as it will have no effect
        ** limitation : no transformations applied here
        */
        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_clear(&dstBuffer, &l_vglite_clip_rect, fl_fill_color));
        l_vglite_draw_sts = (GFX_MGR02_VGLITE_FLUSH_PENDING);
    }
    else
#endif
    {
        if((p_cntx_SP->state.alpha < (UINT8)255) || (fl_fillcolor_alpha < (UINT8)255))
        {
           /*
           ** If the fillcolor alpha or global alpha is less than 255, then draw a rectangular path
           ** and then fill the path area with the passed color blending it onto the destination/frame buffer.
           */
           fl_fillcolor_alpha = (UINT32)p_cntx_SP->state.alpha * fl_fillcolor_alpha;
           fl_fillcolor_alpha = (fl_fillcolor_alpha/(UINT32)255);
           fl_fill_color = GFX_MGR02_MODIFY_ALPHA(fl_fill_color, fl_fillcolor_alpha);
        } 
        
        if(fl_fillcolor_alpha > 0u)
        {
            vg_lite_path_t fl_vgpath;
            SINT16 fl_path_cmd_buf[] = {VLC_OP_MOVE, 0, 0,
                                       VLC_OP_LINE_REL, (SINT16)p_dim->width, 0,
                                       VLC_OP_LINE_REL, 0, (SINT16)p_dim->height,
                                       VLC_OP_LINE_REL, -((SINT16)p_dim->width), 0,
                                       VLC_OP_END};
            
            (void)memset((void*)&fl_vgpath, 0, (sizeof(vg_lite_path_t)));
            
            GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init_path(&fl_vgpath, VG_LITE_S16, VG_LITE_HIGH, sizeof(fl_path_cmd_buf), fl_path_cmd_buf, (vg_lite_float_t)0, (vg_lite_float_t)0, (vg_lite_float_t)p_dim->width, (vg_lite_float_t)p_dim->height));

            hmi_gfx_mgr02_vglite_matrix_load_identity();
            hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)p_cntx_SP->state.loc.x, (vg_lite_float_t)p_cntx_SP->state.loc.y);
            hmi_gfx_mgr02_vglite_matrix_multiply(p_cntx_SP->state.matrix);  
            hmi_gfx_mgr02_vglite_matrix_translate(-(p_cntx_SP->rprop.pivot.x),-(p_cntx_SP->rprop.pivot.y));

            GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_draw(&dstBuffer, &fl_vgpath, VG_LITE_FILL_EVEN_ODD, &l_vglite_matrix, VG_LITE_BLEND_SRC_OVER, fl_fill_color));
            l_vglite_draw_sts = (GFX_MGR02_VGLITE_FLUSH_PENDING);
            GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_clear_path(&fl_vgpath));
        }
    }
#ifdef GFX02_DEBUG_OVG
      gfx_debug("vglite - Fill elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
        p_cntx_SP->state.loc.x, p_cntx_SP->state.loc.y, p_dim->width, p_dim->height);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("vglite - Fill elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  GFX_MGR02_UNUSED_PTR(p_elem_def_SP);
  return fl_ret_value;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_clear_buffer
Description          : Clears the framebuffer with passed color
Invocation           : Invoked internally
Parameters           : fill color
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color)
{
    s_gx_flocal fl_return_value = (s_gx_flocal)0;
    vg_lite_buffer_t dstBuffer = {0};
    vg_lite_color_t fl_clear_color = GFX_MGR02_ARGB_TO_ABGR(p_clear_color);
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

    if(GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    {
        vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
        SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);

        dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
        dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
        dstBuffer.stride             = (SINT32)p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);
        dstBuffer.format             = fl_dst_pixel_format;
        dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
        dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;

        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_clear(&dstBuffer, GFX_MGR02_NULL_PTR, fl_clear_color));
    }

    fl_return_value = (s_gx_flocal)1;
    return(fl_return_value);

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_build_image
Description          : Builds a bitmap image element
Invocation           : Invoked internally
Parameters           : element definition, context
Return Value         : -
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_build_image(GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
    s_gx_flocal fl_ret_value = 0;
    UINT8 fl_shutdown_state  = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
   
    if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
    {
        void * vImgAddr = GFX_MGR02_NULL_PTR;
        vg_lite_blend_t fl_blend_mode;
        vg_lite_color_t fl_mix_color;
        vg_lite_buffer_t dstBuffer;
        vg_lite_buffer_t srcBuffer;
        SINT32 fl_src_bpp_size;
        SINT32 fl_dst_bpp_size;
        uint32_t fl_vglite_img_bounds[4]; /* x, y, width and height of the source image to blit */
        
        #if defined(GFX_MGR02_COMPRESSION_ENABLED)
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > 0UL))
        {
            void * fl_frame_buff_ptr = hmi_gfx_mgr02_context_get_sw_decompr_buffer();
            if (fl_frame_buff_ptr != GFX_MGR02_NULL_PTR)
            {
                switch((vg_lite_buffer_format_t)p_elem_def_SP->format)
                {            
                    case VG_LITE_A8:
                    {
                        hmi_gfx_mgr02_comp_decompr_8bpp(p_elem_def_SP, &((UINT8*)fl_frame_buff_ptr)[0]);
                        vImgAddr = fl_frame_buff_ptr;
                    }
                    break;
                    case VG_LITE_BGRA4444:
                    case VG_LITE_BGRA5551:
                    case VG_LITE_BGR565:
                    {
                        hmi_gfx_mgr02_comp_decompr_16bpp(p_elem_def_SP, &((UINT16*)fl_frame_buff_ptr)[0]);
                        vImgAddr = fl_frame_buff_ptr;
                    }
                    break;
                    case VG_LITE_BGRA8888:
                    {
                        hmi_gfx_mgr02_comp_decompr_32bpp(p_elem_def_SP, &((UINT32*)fl_frame_buff_ptr)[0]);
                        vImgAddr = fl_frame_buff_ptr;
                    }
                    break;
                    default:
                    { 
                        /* The following line is added to avoid warnings. While it may remain dormant in most cases,
                        ** it is essential for maintaining code integrity and ensuring robustness. Please retain for 
                        ** future reference */
                        vImgAddr = (void*)p_elem_def_SP->pixel_data;
                    }
                    break;
                }
            }
        }
        else
        #endif
        {
            vImgAddr = (void*)p_elem_def_SP->pixel_data;
        }
        
        if (vImgAddr != GFX_MGR02_NULL_PTR)
        {
            (void)memset((void*)&dstBuffer, 0, (sizeof(vg_lite_buffer_t)));
            (void)memset((void*)&srcBuffer, 0, (sizeof(vg_lite_buffer_t)));
            
            /* Configure Destination Buffer */
            vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
            fl_dst_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);
            dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
            dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
            dstBuffer.stride             = (((SINT32)p_cntx_SP->rprop.fb_w * fl_dst_bpp_size)/8);
            dstBuffer.format             = fl_dst_pixel_format;
            dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
            dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;

            /* Configure Source Buffer */
            fl_src_bpp_size = hmi_gfx_mgr02_vglite_get_bpp((vg_lite_buffer_format_t)p_elem_def_SP->format);
            srcBuffer.width              = (SINT32)p_elem_def_SP->width;
            srcBuffer.height             = (SINT32)p_elem_def_SP->height;
            srcBuffer.stride             = (((SINT32)p_elem_def_SP->width * fl_src_bpp_size)/8);
            srcBuffer.format             = (vg_lite_buffer_format_t)p_elem_def_SP->format;
            srcBuffer.memory             = vImgAddr;
            srcBuffer.address            = (UINT32)vImgAddr;
            
            hmi_gfx_mgr02_vglite_matrix_load_identity();
        #if GFX_MGR02_ROTATION_90_DEG_ANTICLOCKWISE_ENABLED != 0
            hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)(p_cntx_SP->state.loc.x + p_elem_def_SP->width),(vg_lite_float_t)p_cntx_SP->state.loc.y);
        #else
            hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)p_cntx_SP->state.loc.x, (vg_lite_float_t)p_cntx_SP->state.loc.y);
        #endif
            hmi_gfx_mgr02_vglite_matrix_multiply(p_cntx_SP->state.matrix); /* Matrix Transformation */
            hmi_gfx_mgr02_vglite_matrix_translate((-p_cntx_SP->rprop.pivot.x),(-p_cntx_SP->rprop.pivot.y)); /* Pivot */
            fl_blend_mode = hmi_gfx_mgr02_vglite_get_blendmode(p_cntx_SP, (vg_lite_buffer_format_t)p_elem_def_SP->format); /* Alpha Blending mode based on image format */

        #if defined(GFX_MGR02_CLIPPED_WIDGETS)
            hmi_gfx_mgr02_vglite_set_clip(p_cntx_SP);
        #endif
            
            if (((vg_lite_buffer_format_t)p_elem_def_SP->format == VG_LITE_A8) || ((vg_lite_buffer_format_t)p_elem_def_SP->format == VG_LITE_A4)) /* A8, A4 alha mask support */
            {
                fl_mix_color = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.fg_color);
                srcBuffer.image_mode = VG_LITE_MULTIPLY_IMAGE_MODE;
                
                if (p_cntx_SP->state.alpha < 255U)
                {
                    fl_mix_color = GFX_MGR02_MODIFY_ALPHA(fl_mix_color, (UINT32)p_cntx_SP->state.alpha);
                }
            }
            else
            {
                if (p_cntx_SP->state.alpha < 255U)
                {
                    fl_mix_color = (((UINT32)(p_cntx_SP->state.alpha) << 24U) | (0x00FFFFFFU));
                    srcBuffer.image_mode = VG_LITE_MULTIPLY_IMAGE_MODE;
                }
                else
                {
                    fl_mix_color = 0U;
                    srcBuffer.image_mode = VG_LITE_NORMAL_IMAGE_MODE;
                }
            }
            
            fl_vglite_img_bounds[0] = (UINT32)0;
            fl_vglite_img_bounds[1] = (UINT32)0;
            fl_vglite_img_bounds[2] = (UINT32)p_elem_def_SP->width - p_elem_def_SP->padding; /* Crop out padded pixels */
            fl_vglite_img_bounds[3] = p_elem_def_SP->height;
            
            GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_blit_rect(&dstBuffer, &srcBuffer, &fl_vglite_img_bounds[0], &l_vglite_matrix, fl_blend_mode, fl_mix_color,  VG_LITE_FILTER_BI_LINEAR));
            l_vglite_draw_sts = (GFX_MGR02_VGLITE_FLUSH_PENDING);
            fl_ret_value = 1;
            
            #if defined(GFX_MGR02_COMPRESSION_ENABLED)            
            if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
            {
                
                l_vglite_draw_sts = GFX_MGR02_VGLITE_FB_UPDATED;
                GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_finish());     
            }
            #endif

            #ifdef GFX02_DEBUG_OVG
            gfx_debug("vglite - Image elem =%08X[x=%d,y=%d,w=%d,h=%d] printd\n", p_elem_def_SP,
              p_cntx_SP->state.loc.x,
              p_cntx_SP->state.loc.y,
              p_elem_def_SP->width,
              p_elem_def_SP->height);
            #endif
        }
    }
    #ifdef GFX02_DEBUG_OVG
    else
    {
        gfx_debug("vglite - Image elem =%08X skipped\n", p_elem_def_SP);
    }
    #endif
    return fl_ret_value;
}

#if (GFX_MGR02_NUM_OF_SVGS > 0)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_build_svg
Description          : Builds a vector graphics object
Invocation           : Invoked internally
Parameters           : element definition, pointer to context
Return Value         : return 1 if successful else 0
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_vglite_build_svg(GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_MGR02_OVG_OBJECT_T const * p_elem_def_SP)
{
  s_gx_flocal fl_ret_value = (s_gx_flocal)0;
  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
  {
    
    GFX_MGR02_OVG_PATH_DEF_T const * fl_cur_path_sp;
    vg_lite_path_t fl_vgpath;
    vg_lite_buffer_t dstBuffer = {0};
    void * fl_path_cmd_buf;
    UINT32 fl_path_count_U32;
    
    (void)memset((void*)&fl_vgpath, 0, (sizeof(vg_lite_path_t)));

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    hmi_gfx_mgr02_vglite_set_clip(p_cntx_SP);
#endif

    hmi_gfx_mgr02_vglite_matrix_load_identity();
    hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)p_cntx_SP->state.loc.x, (vg_lite_float_t)p_cntx_SP->state.loc.y);
    hmi_gfx_mgr02_vglite_matrix_multiply(p_cntx_SP->state.matrix);
    hmi_gfx_mgr02_vglite_matrix_translate(-(p_cntx_SP->rprop.pivot.x),-(p_cntx_SP->rprop.pivot.y));
    vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
    SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);

    dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
    dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
    dstBuffer.stride             = (SINT32)p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);
    dstBuffer.format             = fl_dst_pixel_format;
    dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
    dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;

    fl_cur_path_sp               = p_elem_def_SP->path_array_sap;
    fl_path_count_U32            = p_elem_def_SP->num_paths;
    fl_path_cmd_buf              = hmi_gfx_mgr02_context_get_path_cmd_buf();

    if (fl_path_cmd_buf != GFX_MGR02_NULL_PTR)
    {
       while(fl_path_count_U32 > 0u)
       {

          vg_lite_blend_t fl_blend_mode;
          vg_lite_fill_t fl_fill_rule;

          GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init_path(&fl_vgpath, VG_LITE_FP32, VG_LITE_HIGH, (UINT32)0, fl_path_cmd_buf, p_elem_def_SP->bounds[0], p_elem_def_SP->bounds[1], p_elem_def_SP->bounds[2], p_elem_def_SP->bounds[3]));
          (void)vg_lite_path_append(&fl_vgpath, (UINT8*)fl_cur_path_sp->path_segments_u8p, (void*)fl_cur_path_sp->path_data_fp, fl_cur_path_sp -> numSegments);

          if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_BLEND_ENABLED) == GFX_MGR02_PATH_PROP_BLEND_ENABLED)
          {
             fl_blend_mode = VG_LITE_BLEND_SRC_OVER;
          }
          else
          {
             fl_blend_mode = VG_LITE_BLEND_NONE;
          }

          if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_ENABLED) == GFX_MGR02_PATH_PROP_FILL_ENABLED)
          {
                if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_RULE) == GFX_MGR02_PATH_PROP_FILL_RULE_EVENODD)
                {
                    fl_fill_rule = VG_LITE_FILL_EVEN_ODD;
                }
                else /* GFX_MGR02_PATH_PROP_FILL_RULE_NONZERO */
                {
                    fl_fill_rule = VG_LITE_FILL_NON_ZERO;
                }

                if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_PAINT) == GFX_MGR02_PATH_PROP_FILL_PAINT_LGRAD)
                {
                    /* TODO: 1575885: VGLite: Implement Linear and Radial Gradient Path Fill Paint in SVG Rendering */
                }
                else if((fl_cur_path_sp->attributes & GFX_MGR02_PATH_PROP_FILL_PAINT) == GFX_MGR02_PATH_PROP_FILL_PAINT_RGRAD)
                {
                    /* TODO: 1575885: VGLite: Implement Linear and Radial Gradient Path Fill Paint in SVG Rendering */
                }
                else /* GFX_MGR02_PATH_PROP_FILL_PAINT_COLOR */
                {
                    GFX_MGR02_OVG_COLOR_DEF_T fl_fill_color;
                    
                    (void)memcpy((void *)&fl_fill_color, fl_cur_path_sp->fill_paint_vp, sizeof(GFX_MGR02_OVG_COLOR_DEF_T));
                    
                    if (p_cntx_SP->state.alpha < 255U)
                    {
                       fl_fill_color.color = GFX_MGR02_MODIFY_ALPHA(fl_fill_color.color, (UINT32)p_cntx_SP->state.alpha);
                    }
                    
                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_draw(&dstBuffer, &fl_vgpath, fl_fill_rule, &l_vglite_matrix, fl_blend_mode, fl_fill_color.color));
                    l_vglite_draw_sts = (GFX_MGR02_VGLITE_FLUSH_PENDING);
                }
          }

          GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_clear_path(&fl_vgpath));

          fl_cur_path_sp++;
          fl_path_count_U32--;
       }
       fl_ret_value = (s_gx_flocal)1;
    }
#ifdef GFX02_DEBUG_OVG
    gfx_debug("vglite - SVG elem =%08X printed\n", p_elem_def_SP);
#endif
  }
#ifdef GFX02_DEBUG_OVG
  else
  {
    gfx_debug("vglite - SVG elem =%08X skipped\n", p_elem_def_SP);
  }
#endif

  return fl_ret_value;
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_build_text
Description          : Builds the text object . 
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_text()
Parameters           : GFX_MGR02_CONTEXT_T, GFX_MGR02_TEXT_DEF_T, HMI_CHAR, u_gx_flocal
Return Value         : s_gx_flocal
Critical Section     : None
External Interfaces  : None
******************************************************************************/
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
s_gx_flocal hmi_gfx_mgr02_vglite_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP ,
                                           GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, 
                                           HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width
                                           #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                           ,u_gx_flocal p_is_multi_line_text
                                           #endif
                                           )
{
    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    static HMI_CHAR l_irislib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
    #endif

    HMI_CHAR const * fl_string_ptr = NULL;
    HMI_CHAR const * fl_print_str  = NULL;
    GFX_UINT fl_alignment  = p_cntx_SP->rprop.alignment;
    UINT32   fl_str_length = 0UL;
    UINT16   fl_text_width;
    SINT16   fl_glyph_draw_x;
    #ifdef GFX_STRING_CACHE_ENABLED
    /* Below variable is used only for allocating memory for full string when string cache is enabled */
    UINT16 fl_full_text_width = 0U;
    UINT8 fl_cache_buffer_padding;
    #endif

    s_gx_flocal fl_ret_value = (s_gx_flocal)0;
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
    UINT16 fl_scroll_offset = 0U;
    BOOLEAN fl_scroll_enabled = hmi_gfx_mgr02_layout_get_text_scroll_status((GFX_MGR02_ANIM_ELEM_ID)p_elem_def_SP->anim_id);
#endif
    if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
    {
        #if defined(GFX_PERFORMANCE_MEASUREMENT)
        GFX_FLOAT fl_start_time, fl_end_time;
        OsApi_SuspendAllInterrupts();
        fl_start_time = (Gpt_GetTimeElapsed(1)/60);
        #endif
        
        UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
        GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
        UINT8 fl_use_ttf_engine = (UINT8)0;        

        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
            GFX_MGR02_TEXT_INFO fl_text_info_S;
            
            fl_text_info_S.print_str_P         = p_string;
            fl_text_info_S.max_available_width = p_cntx_SP->rprop.text_width;
            fl_text_info_S.font_pt_size = p_cntx_SP->rprop.font_size.point_size;
            fl_use_ttf_engine = fl_font_SP->is_ffile;
        #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
        #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
            if(p_is_multi_line_text != FALSE)
            {
                fl_text_info_S.append_str = FALSE;
            }
            else
        #endif
            {
                fl_text_info_S.append_str = TRUE;
            }
            l_irislib_clip_text_str[0] = 0;
        #else
            fl_text_info_S.append_str = FALSE;
        #endif
            fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
            fl_text_info_S.dyn_text_def_SP      = p_elem_def_SP;
        #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
            fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
        #endif
            (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                               (UINT32)p_cntx_SP->rprop.font_id,
                                               (UINT32)p_cntx_SP->rprop.clip_mode,
                                               (UINT32)p_cntx_SP->rprop.alignment
        #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                                ,l_irislib_clip_text_str
        #endif
                                               );
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
            if (p_is_multi_line_text == FALSE)/*Below scroll functionality is not applicable for Multiline text*/
#endif
            {
              if (fl_scroll_enabled == TRUE) && ((p_cntx_SP->rprop.clip_mode & GFX_MGR02_TP_CLIP_SHRINK_FIT) != GFX_MGR02_TP_CLIP_SHRINK_FIT))
              { 
                if(fl_text_info_S.print_width > p_cntx_SP->rprop.text_width)
                {
                    if(p_cntx_SP->rprop.scroll_offset <= (fl_text_info_S.print_width - p_cntx_SP->rprop.text_width))
                    {
                        fl_scroll_offset = p_cntx_SP->rprop.scroll_offset;
                    }
                    else
                    {
                        fl_scroll_offset = (fl_text_info_S.print_width - p_cntx_SP->rprop.text_width);
                        hmi_gfx_mgr02_layout_stop_scroll((GFX_MGR02_ANIM_ELEM_ID)p_elem_def_SP->anim_id);
#if defined(GFX_MGR02_SCROLL_COMPLETE_CB)
                        GFX_MGR02_SCROLL_COMPLETE_CB(p_elem_def_SP->anim_id);
#endif
                    }
                }
                if ((fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                || ((fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT) && !((hmi_gfx_mgr02_get_arabic_char_count(fl_text_info_S.print_str_P,(UINT16)fl_text_info_S.print_length_U8) != 0U) || \
        (hmi_gfx_mgr02_get_hebrew_char_count(fl_text_info_S.print_str_P,(UINT16)fl_text_info_S.print_length_U8) != 0U))))
                {
                  fl_alignment = GFX_MGR02_TP_ALIGN_LEFT;
                }
              }
            }
#endif
#if (defined(GFX_MGR02_CLIP_TEXT_ENABLE))
#if (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED) && defined(GFX_MGR02_EXT_FONT_ENGINE))
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
            
            fl_print_str  = fl_text_info_S.print_str_P;
#endif
        
            fl_string_ptr = fl_print_str;
            fl_text_width = fl_text_info_S.print_width;
            fl_str_length = fl_text_info_S.print_length_U8;
        
        #ifdef GFX_STRING_CACHE_ENABLED
            fl_full_text_width = ((fl_text_info_S.print_width % 16u) != 0u) ? (((fl_text_info_S.print_width/16u)+1u)*16u) : (fl_text_info_S.print_width);
            fl_cache_buffer_padding = (UINT8)(fl_full_text_width - fl_text_info_S.print_width);
        #endif
        }
        else
        {
            fl_text_width = (UINT16)0;
        }
        
        if(fl_text_width > (UINT16)0)
        {
            vg_lite_color_t fl_fg_color;
            vg_lite_color_t fl_bg_color;
            SINT32 fl_start_x;
            SINT32 fl_pivot_offset;
            SINT32 fl_txtbox_strt_x;
            UINT8  fl_draw_mode;
        #ifdef GFX_STRING_CACHE_ENABLED
            void  *fl_str_img_data;
        #endif
        #if defined(GFX_MGR02_CLIPPED_WIDGETS) 
            hmi_gfx_mgr02_vglite_set_clip(p_cntx_SP);
        #endif

            if((fl_text_width > p_cntx_SP->rprop.text_width)
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
           &&(fl_scroll_enabled == FALSE)
#endif
            )
            {
                fl_text_width = p_cntx_SP->rprop.text_width;
            }
            
            if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
                fl_txtbox_strt_x = (SINT32)p_cntx_SP->rprop.text_width;
                fl_pivot_offset  = ((SINT32)p_cntx_SP->rprop.text_width - (SINT32)fl_text_width);
                if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                    fl_start_x      = ((SINT32)fl_text_width - 1);
                }
                else
                {
                    fl_start_x      = (SINT32)(fl_text_width);
                }
            }
            else if (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
                fl_start_x       = ((SINT32)fl_text_width / 2);
                fl_pivot_offset  = (((SINT32)p_cntx_SP->rprop.text_width -(SINT32)fl_text_width) / 2);
                fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width / 2);
            }
            else
            {
                fl_start_x       = 0;
                fl_txtbox_strt_x = 0;
                fl_pivot_offset  = 0;
            }
        #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
            if (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
                /* 
                ** handle case where the current alignment is different than default alignment 
                */
                if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
                {
                    fl_start_x -= ((SINT32)p_cntx_SP->rprop.text_width/2);
                    fl_txtbox_strt_x -= ((SINT32)p_cntx_SP->rprop.text_width/2);
                }
                else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                    fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width/2);
                    fl_txtbox_strt_x -=1;
                    fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width /2);
                    /* Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text. */
                    /* So it needs to be considered here */
                    fl_start_x -= 1;
                }
                else
                {
                    /* To Fix MISRA warning */
                }
            }
            else if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
                if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
                {
                    fl_start_x -= (SINT32)(p_cntx_SP->rprop.text_width);
                    fl_txtbox_strt_x = 0;
                }
                else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                {
                    fl_start_x -= ((SINT32)p_cntx_SP->rprop.text_width/2);
                    fl_txtbox_strt_x -= ((SINT32)p_cntx_SP->rprop.text_width/2);
                }
                else
                {
                    fl_txtbox_strt_x -=1;
                }
            }
            else
            {
                if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                {
                    fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width/2);
                    fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width/2);
                }
                else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                    fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width -(SINT32)1);
                    fl_start_x += (SINT32)p_cntx_SP->rprop.text_width;
                    /*  Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text.So it needs to be considered here  */
                    fl_start_x -= 1; 
                }
                else
                {
                    /* To fix MISRA warning */
                }
            }
        #endif

            fl_start_x       = ((SINT32)p_cntx_SP->state.loc.x - (fl_start_x + fl_pivot_offset));
            fl_txtbox_strt_x = ((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x);
            fl_draw_mode     = (UINT8)p_cntx_SP->rprop.draw_mode;
            fl_fg_color      = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.fg_color);
            
            if (fl_draw_mode != GFX_MGR02_TP_DRAW_TRANSP)
            {
                UINT32 fl_bgfill_color_alpha;
                vg_lite_buffer_t dstBuffer = {0};
                vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
                SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);
                
                dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
                dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
                dstBuffer.stride             = (SINT32)p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);
                dstBuffer.format             = fl_dst_pixel_format;
                dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
                dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;
                                
                if (fl_draw_mode == GFX_MGR02_TP_DRAW_REVERSE)
                {
                  fl_bg_color = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.fg_color);
                  fl_fg_color = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.bg_color);
                }
                else
                {
                  fl_bg_color = GFX_MGR02_ARGB_TO_ABGR(p_cntx_SP->rprop.bg_color);
                }
                
                fl_bgfill_color_alpha = GFX_MGR02_GET_ALPHA(fl_bg_color);

                if((p_cntx_SP->state.alpha < (UINT8)255) || (fl_bgfill_color_alpha < (UINT32)255))
                {
                   /*
                   ** If the bgcolor alpha or global alpha is less than 255, then draw a rectangular path
                   ** and fill the path area with the passed background color blending it onto the destination/frame buffer.
                   */
                   fl_bgfill_color_alpha = (UINT32)p_cntx_SP->state.alpha * fl_bgfill_color_alpha;
                   fl_bgfill_color_alpha = (fl_bgfill_color_alpha/(UINT32)255);
                   fl_bg_color = GFX_MGR02_MODIFY_ALPHA(fl_bg_color, fl_bgfill_color_alpha);
                } 
                
                if(fl_bgfill_color_alpha > 0u)
                {
                    vg_lite_path_t fl_vgpath;
                    SINT16 fl_path_cmd_buf[] = {VLC_OP_MOVE, 0, 0,
                                               VLC_OP_LINE_REL, (SINT16)p_cntx_SP->rprop.text_width, 0,
                                               VLC_OP_LINE_REL, 0, (SINT16)fl_font_SP->p.height,
                                               VLC_OP_LINE_REL, -((SINT16)p_cntx_SP->rprop.text_width), 0,
                                               VLC_OP_END};
                    
                    (void)memset((void*)&fl_vgpath, 0, (sizeof(vg_lite_path_t)));
                    
                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init_path(&fl_vgpath, VG_LITE_S16, VG_LITE_HIGH, sizeof(fl_path_cmd_buf), fl_path_cmd_buf, (vg_lite_float_t)0, (vg_lite_float_t)0, (vg_lite_float_t)p_cntx_SP->rprop.text_width, (vg_lite_float_t)fl_font_SP->p.height));

                    hmi_gfx_mgr02_vglite_matrix_load_identity();
                    hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)fl_txtbox_strt_x, (vg_lite_float_t)p_cntx_SP->state.loc.y);
                    hmi_gfx_mgr02_vglite_matrix_multiply(p_cntx_SP->state.matrix);  
                    hmi_gfx_mgr02_vglite_matrix_translate(-(p_cntx_SP->rprop.pivot.x),-(p_cntx_SP->rprop.pivot.y));

                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_draw(&dstBuffer, &fl_vgpath, VG_LITE_FILL_EVEN_ODD, &l_vglite_matrix, VG_LITE_BLEND_SRC_OVER, fl_bg_color));
                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_clear_path(&fl_vgpath));
                }  
            }
            
#ifdef GFX_STRING_CACHE_ENABLED
            
            /*
            ** 1. Get the pointer for the passed string from the cache.
            ** 2. If it is not available then render that string and put it in the cache.
            */
          
            fl_str_img_data = hmi_gfx_mgr02_get_string_cache_ptr(fl_string_ptr, p_cntx_SP, fl_font_SP, fl_font_id, fl_fg_color);

            if(fl_str_img_data == GFX_MGR02_NULL_PTR)
            {
                GFX_STRING_CACHE_INFO element;
                PixEngMemInfo fl_memory_s;
                GFX_MGR02_CONTEXT_T fl_context_sp;
                UINT8 fl_font_height = p_cntx_SP->rprop.font_size.height;
                
                fl_memory_s.MemCateg       = IMXRT_STRING_CACHE_BUFFER;
                fl_memory_s.WidgetClientId = 0xFFFFFFFFu; 
                fl_memory_s.Alignment      = (UINT32)32; /*32 Byte alignement*/
                fl_memory_s.Size           = (UINT32)(fl_full_text_width * fl_font_height); /* Assuming string cache buffer format as A8 */
                fl_memory_s.ExtMemory      = (UINT8)1;
                #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
                fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
                #endif
                fl_str_img_data            = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
            
                if(fl_str_img_data != GFX_MGR02_NULL_PTR)
                {
                    (void)memset(fl_str_img_data,0,fl_memory_s.Size);
                    hmi_gfx_mgr02_context_state_get(&fl_context_sp.state);
                    
                    fl_context_sp.rprop           = p_cntx_SP->rprop;
                    fl_context_sp.rprop.fb_P      = fl_str_img_data;
                    fl_context_sp.rprop.fb_w      = fl_full_text_width;
                    fl_context_sp.rprop.fb_h      = fl_font_height;
                    fl_context_sp.rprop.fb_format = GFX_MGR02_PIX_FORMAT_A8;
                    fl_context_sp.rprop.pivot.x   = 0;
                    fl_context_sp.rprop.pivot.y   = 0;
                    fl_context_sp.state.loc.x     = 0;
                    fl_context_sp.state.loc.y     = 0;
                    fl_context_sp.state.clip.sx   = fl_context_sp.state.loc.x;
                    fl_context_sp.state.clip.sy   = fl_context_sp.state.loc.y;
                    fl_context_sp.state.clip.ex   = fl_full_text_width;
                    fl_context_sp.state.clip.ey   = fl_font_height;
                    fl_context_sp.state.alpha     = 255U;
                    fl_context_sp.state.matrix[0] = (GFX_FLOAT)1;
                    fl_context_sp.state.matrix[1] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[2] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[3] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[4] = (GFX_FLOAT)1;
                    fl_context_sp.state.matrix[5] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[6] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[7] = (GFX_FLOAT)0;
                    fl_context_sp.state.matrix[8] = (GFX_FLOAT)1;
                    fl_glyph_draw_x               = (SINT16)0;
                    
                    if (fl_use_ttf_engine == (UINT8)1)
                    {
                        
                        hmi_gfx_mgr02_vglite_draw_outline_string(fl_glyph_draw_x, &fl_context_sp, fl_string_ptr, fl_font_SP, fl_fg_color, fl_str_length
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                          , fl_scroll_offset
                          , fl_alignment
#endif
                        );
                        
                        (void)HMI_STRNCPY(element.String, fl_string_ptr,(UINT32)GFX_MGR02_MAX_TEXT_LENGTH);
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                        element.isScrolled = fl_scroll_enabled;
#endif
                        element.String[GFX_MGR02_MAX_TEXT_LENGTH] = (HMI_CHAR)'\0';
                        element.StringLen   = (UINT8)fl_str_length;
                        element.FontId      = fl_font_id;
                        element.FontSize    = fl_font_height;
                        element.Buf         = (UINT8*) fl_str_img_data;
                        element.drawColor   = fl_fg_color;
                        element.bmpWidth    = (UINT16)fl_full_text_width;

                        hmi_gfx_mgr02_add_string_in_cache_queue(&element);
                    }
                }
            }
            
            if(fl_str_img_data != GFX_MGR02_NULL_PTR)
            {         
                GFX_MGR02_IMAGE_DEF_T fl_element_def_SP;
                GFX_MGR02_CONTEXT_T fl_context_sp;

                fl_element_def_SP.format      = (UINT8)VG_LITE_A8;
                fl_element_def_SP.compression = GFX_MGR02_IMAGE_COMPRESSION_NONE;
                fl_element_def_SP.chroma_key  = GFX_MGR02_IMAGE_CHROMA_KEY_NONE;
                fl_element_def_SP.vaoa_index  = 0;
                fl_element_def_SP.width       = fl_full_text_width;
                fl_element_def_SP.padding     = fl_cache_buffer_padding;
                fl_element_def_SP.height      = p_cntx_SP->rprop.font_size.height;
                fl_element_def_SP.color       =	0x0;
                fl_element_def_SP.pixel_data  = (void const*)fl_str_img_data;

                hmi_gfx_mgr02_context_state_get(&fl_context_sp.state);
                fl_context_sp.state.loc.x     = (SINT16)fl_start_x;
                fl_context_sp.rprop           = p_cntx_SP->rprop;
                fl_context_sp.rprop.fg_color  = fl_fg_color;
                fl_context_sp.rprop.pivot.x -= ((GFX_FLOAT)fl_pivot_offset);
                
                hmi_gfx_mgr02_vglite_build_image(&fl_context_sp, &fl_element_def_SP);
            }
#else
            fl_glyph_draw_x = (SINT16)fl_start_x;
            ((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->rprop.pivot.x -= ((GFX_FLOAT)fl_pivot_offset);
            if (fl_use_ttf_engine == (UINT8)1)
            {
                /* Freetype Font rendering */
                hmi_gfx_mgr02_vglite_draw_outline_string(fl_glyph_draw_x, p_cntx_SP, fl_string_ptr, fl_font_SP, fl_fg_color, fl_str_length                                    
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                  , fl_scroll_offset
                  , fl_alignment
#endif
                );
                l_vglite_draw_sts = (GFX_MGR02_VGLITE_FLUSH_PENDING);
                fl_ret_value = (s_gx_flocal)0;
            }
#endif      
        }
#if defined(GFX_PERFORMANCE_MEASUREMENT)
        fl_end_time = (Gpt_GetTimeElapsed(1)/60);
        fl_render_time[counter++] = fl_end_time - fl_start_time; //time in microseconds
        if(counter == 100)
        {
            counter = 0u;
        }
        OsApi_ResumeAllInterrupts();
#endif
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
        gfx_debug("VGLITE - Text elem =%08X skipped\n", p_elem_def_SP);
    }
#endif    
    GFX_MGR02_UNUSED_VAR(p_text_actual_width);
    return fl_ret_value;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_draw_outline_string
Description          : 
Invocation           : Invoked by hmi_gfx_mgr02_vglite_build_text
Parameters           : 
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static void hmi_gfx_mgr02_vglite_draw_outline_string(SINT16 p_start_x, 
                                                    GFX_MGR02_CONTEXT_T const *p_cntx_SP, 
                                                    HMI_CHAR const *p_string_p, 
                                                    GFX_MGR02_FONT const *p_font_SP, 
                                                    vg_lite_color_t p_draw_color, 
                                                    UINT32 p_str_length
                                                    #if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                                                  , UINT16 p_scroll_offset
                                                  , GFX_UINT p_alignment
                                                    #endif
                                                    )
{
    #if defined(GFX_MGR02_VGLITE_APPLY_TRANSFORMATION_ON_WHOLE_TEXT)
    void                 *fl_temp_buffer;
    UINT16                fl_text_width;
    UINT8                 fl_temp_buffer_padding;
    GFX_MGR02_IMAGE_DEF_T fl_element_def_SP;
    GFX_MGR02_CONTEXT_T   fl_cntx_SP;
    PixEngMemInfo         fl_memory_s;
    SINT16                fl_glyph_draw_x = 0;
    SINT16                fl_glyph_draw_y = 0;
    #else
    SINT16                fl_glyph_draw_x = p_start_x;
    SINT16                fl_glyph_draw_y = p_cntx_SP->state.loc.y;
    #endif
    
    SINT16                fl_glyph_y_offset;
    vg_lite_color_t       fl_draw_color = p_draw_color;
    vg_lite_buffer_t      dstBuffer = {0};
    void                 *fl_path_cmd_buf;
    HMI_CHAR const       *fl_string_ptr = p_string_p;
    UINT32                fl_str_length = p_str_length;

    UINT32                fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
    
    if (fl_font_id <(UINT32)GFX_MGR02_NUM_OF_FONTS)
    {
        FT_Face          face = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_face;
        FT_GlyphSlot     fl_glyph_slot = face->glyph;
        FT_Error         fl_ft_error;
        BOOLEAN          fl_usekerning_bool = (FT_HAS_KERNING(face) != 0) ? TRUE : FALSE;
        
        #if defined(GFX_MGR02_AMBER_FT2_CACHE_ENABLED)
        UINT8            fl_font_size_pts = p_cntx_SP->rprop.ft2_faceprop[fl_font_id].ft2_font_size;
        FT_Glyph         fl_glyph = GFX_MGR02_NULL_PTR;
        FTC_ImageTypeRec fl_type;
        FTC_ImageCache   fl_ftc_image_cache;
        #endif
       
        fl_path_cmd_buf = hmi_gfx_mgr02_context_get_path_cmd_buf();
        if (fl_path_cmd_buf != GFX_MGR02_NULL_PTR)
        {
            FT_UInt fl_prev_glyph_index = (FT_UInt)0;
            FT_UInt fl_curr_glyph_index;
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
            vg_lite_float_t fl_scroll_offset = (vg_lite_float_t)(p_scroll_offset);
            if (p_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
                fl_scroll_offset = -fl_scroll_offset;
            }
#endif
#if defined(GFX_MGR02_VGLITE_APPLY_TRANSFORMATION_ON_WHOLE_TEXT)
            fl_text_width = ((p_cntx_SP->rprop.text_width % 16u) != 0u) ? (((p_cntx_SP->rprop.text_width/16u)+1u)*16u) : (p_cntx_SP->rprop.text_width);
            fl_temp_buffer_padding = (UINT8)(fl_text_width - p_cntx_SP->rprop.text_width);
            
            fl_cntx_SP.state.clip.sx = 0;
            fl_cntx_SP.state.clip.sy = 0;
            fl_cntx_SP.state.clip.ex = p_cntx_SP->rprop.text_width;
            fl_cntx_SP.state.clip.ey = p_cntx_SP->rprop.font_size.height;

#if defined(GFX_MGR02_CLIPPED_WIDGETS) 
                hmi_gfx_mgr02_vglite_set_clip((GFX_MGR02_CONTEXT_T const *)&fl_cntx_SP);
#endif
            
            fl_memory_s.MemCateg       = IMXRT_VGLITE_TEXT_TEMP_BUFFER;
            fl_memory_s.WidgetClientId = 0xFFFFFFFFu; 
            fl_memory_s.Alignment      = (UINT32)32; /*32 Byte alignement*/
            fl_memory_s.Size           = (UINT32)(fl_text_width * p_cntx_SP->rprop.font_size.height);
            fl_memory_s.ExtMemory      = (UINT8)1;
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
            fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
#endif
            fl_temp_buffer             = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
            
            if (fl_temp_buffer != GFX_MGR02_NULL_PTR)
            {
                vg_lite_buffer_format_t fl_dst_pixel_format = VG_LITE_A8;
                SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);

                dstBuffer.width              = (SINT32)fl_text_width;
                dstBuffer.height             = (SINT32)p_cntx_SP->rprop.font_size.height;
                dstBuffer.stride             = (SINT32)fl_text_width * (fl_bpp_size/8);
                dstBuffer.format             = fl_dst_pixel_format;
                dstBuffer.memory             = fl_temp_buffer;
                dstBuffer.address            = (UINT32)fl_temp_buffer;
#else
            {
#if defined(GFX_MGR02_CLIPPED_WIDGETS) 
                hmi_gfx_mgr02_vglite_set_clip(p_cntx_SP);
#endif
                
                vg_lite_buffer_format_t fl_dst_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
                SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_dst_pixel_format);

                dstBuffer.width              = (SINT32)p_cntx_SP->rprop.fb_w;
                dstBuffer.height             = (SINT32)p_cntx_SP->rprop.fb_h;
                dstBuffer.stride             = (SINT32)p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);
                dstBuffer.format             = fl_dst_pixel_format;
                dstBuffer.memory             = p_cntx_SP->rprop.fb_P;
                dstBuffer.address            = (UINT32)p_cntx_SP->rprop.fb_P;
#endif
#if defined (GFX_MGR02_USE_FREETYPE2_OS2_TABLE)
                TT_OS2 * os2 = (TT_OS2 *)FT_Get_Sfnt_Table(face, ft_sfnt_os2);
                if (os2 != (TT_OS2 *)0)
                {
                    fl_glyph_y_offset = (SINT16)(((GFX_FLOAT)((os2->usWinAscent * p_cntx_SP->rprop.font_size.point_size)))/face->units_per_EM);
                }
                else
#endif
                {    
                    fl_glyph_y_offset = (SINT16)(((GFX_FLOAT)((face->ascender * p_cntx_SP->rprop.font_size.point_size)))/face->units_per_EM);
                }
                    
                fl_glyph_draw_y += fl_glyph_y_offset;
                
                while(fl_str_length > 0u)
                {
                    vg_lite_path_t fl_vgpath;
                    fl_str_length--;
                    fl_curr_glyph_index = FT_Get_Char_Index(face, fl_string_ptr[0]);
                    
                    if ((fl_usekerning_bool == (BOOLEAN)TRUE) && (fl_prev_glyph_index != (FT_UInt)0) && (fl_curr_glyph_index != (FT_UInt)0))
                    {
                        FT_Vector stcKerningDelta = {0};
                        (void)FT_Get_Kerning(face, fl_prev_glyph_index, fl_curr_glyph_index, (FT_UInt)FT_KERNING_DEFAULT, &stcKerningDelta);
                        fl_glyph_draw_x += (stcKerningDelta.x >> 6u);
                    }

#if defined(GFX_MGR02_VGLITE_APPLY_TRANSFORMATION_ON_WHOLE_TEXT)
                    hmi_gfx_mgr02_vglite_matrix_load_identity();
                    hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)fl_glyph_draw_x, (vg_lite_float_t)fl_glyph_draw_y);
#else
                    if (p_cntx_SP->state.alpha < 255U)
                    {
                       fl_draw_color = GFX_MGR02_MODIFY_ALPHA(fl_draw_color, (UINT32)p_cntx_SP->state.alpha);
                    }

                    hmi_gfx_mgr02_vglite_matrix_load_identity();

                    hmi_gfx_mgr02_vglite_matrix_translate((vg_lite_float_t)p_start_x
#if defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)
                          -fl_scroll_offset
#endif
                          , (vg_lite_float_t)(p_cntx_SP->state.loc.y));
                    hmi_gfx_mgr02_vglite_matrix_multiply(p_cntx_SP->state.matrix);
                    hmi_gfx_mgr02_vglite_matrix_translate(-((p_cntx_SP->rprop.pivot.x - fl_glyph_draw_x) + p_start_x),-(p_cntx_SP->rprop.pivot.y - fl_glyph_y_offset));
                #endif
                    
                    (void)memset((void*)&fl_vgpath, 0, (sizeof(vg_lite_path_t)));
                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_init_path(&fl_vgpath, VG_LITE_FP32, VG_LITE_HIGH, (UINT32)0, fl_path_cmd_buf, 0, 0, 0, 0));
                    fl_prev_glyph_index = fl_curr_glyph_index;
                    
                #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                    fl_type.face_id = (FTC_FaceID) &lc_gfx_font_table[fl_font_id];
                    fl_type.width   = (FT_UInt)fl_font_size_pts;
                    fl_type.height  = (FT_UInt)fl_font_size_pts;
                    if(p_font_SP->is_autohint != FALSE)
                    {
                        fl_type.flags = (FT_LOAD_DEFAULT|FT_LOAD_FORCE_AUTOHINT);
                    }
                    else
                    {
                        fl_type.flags = FT_LOAD_DEFAULT;
                    }
                    fl_ftc_image_cache = hmi_gfx_mgr02_get_ft2_imgcache_handler();
                    fl_ft_error = FTC_ImageCache_Lookup(fl_ftc_image_cache, &fl_type, fl_curr_glyph_index, &fl_glyph, NULL);
                    
                    if (fl_string_ptr[0] != (HMI_CHAR)32) /* Skipping vglite draw for space character */
                    {
                        if((fl_ft_error == 0) && (fl_glyph != GFX_MGR02_NULL_PTR) && ((FT_Glyph_Format)FT_GLYPH_FORMAT_OUTLINE == fl_glyph->format))
                        {
                            if (hmi_gfx_mgr02_vglite_render_cache_outline_glyph((FT_OutlineGlyph)fl_glyph, &fl_vgpath) == (UINT32)0)
                            {    
                                GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_draw(&dstBuffer, &fl_vgpath, VG_LITE_FILL_EVEN_ODD, &l_vglite_matrix, VG_LITE_BLEND_SRC_OVER, fl_draw_color));
                            }
                            else
                            { 
                                /* Application needs to increase GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH value to render current character */
                            }                        
                            fl_glyph_draw_x += (fl_glyph->advance.x >> 16);
                            fl_glyph_draw_y += (fl_glyph->advance.y >> 16);
                        }
                    }
                    else
                    {
                        fl_glyph_draw_x += (fl_glyph->advance.x >> 16);
                        fl_glyph_draw_y += (fl_glyph->advance.y >> 16);
                    }
                    
                    if(fl_ft_error != FALSE)
                #endif
                    {    
                        if(p_font_SP->is_autohint != FALSE) 
                        {
                            fl_ft_error = FT_Load_Glyph(face, fl_curr_glyph_index, (FT_LOAD_DEFAULT|FT_LOAD_FORCE_AUTOHINT));
                        }
                        else
                        {
                            fl_ft_error = FT_Load_Glyph(face, fl_curr_glyph_index, FT_LOAD_DEFAULT);
                        }
                        
                        if (fl_string_ptr[0] != (HMI_CHAR)32) /* Skipping vglite draw for space character */
                        {    
                            if(((FT_Glyph_Format)FT_GLYPH_FORMAT_OUTLINE == fl_glyph_slot->format) && (fl_ft_error == 0))
                            {                
                                if (hmi_gfx_mgr02_vglite_render_outline_glyph(face->glyph, &fl_vgpath) == (UINT32)0)
                                {
                                    GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_draw(&dstBuffer, &fl_vgpath, VG_LITE_FILL_EVEN_ODD, &l_vglite_matrix, VG_LITE_BLEND_SRC_OVER, fl_draw_color));
                                }
                                else
                                { 
                                    /* Application needs to increase GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH value to render current character */
                                }
                                fl_glyph_draw_x += (fl_glyph_slot->advance.x >> 6);
                                fl_glyph_draw_y += (fl_glyph_slot->advance.y >> 6);
                            }
                        }
                        else
                        {
                            fl_glyph_draw_x += (fl_glyph_slot->advance.x >> 6);
                            fl_glyph_draw_y += (fl_glyph_slot->advance.y >> 6);
                        }
                    }
                    fl_string_ptr++;
                }   
        #if defined(GFX_MGR02_VGLITE_APPLY_TRANSFORMATION_ON_WHOLE_TEXT)
                fl_element_def_SP.format      = (UINT8)VG_LITE_A8;
                fl_element_def_SP.compression = GFX_MGR02_IMAGE_COMPRESSION_NONE;
                fl_element_def_SP.chroma_key  = GFX_MGR02_IMAGE_CHROMA_KEY_NONE;
                fl_element_def_SP.vaoa_index  = 0;
                fl_element_def_SP.width       = fl_text_width;
                fl_element_def_SP.padding     = fl_temp_buffer_padding;
                fl_element_def_SP.height      = p_cntx_SP->rprop.font_size.height;
                fl_element_def_SP.color       =	0x0;
                fl_element_def_SP.pixel_data  = (void const*)fl_temp_buffer;

                ((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->state.loc.x = (SINT16)p_start_x;
                hmi_gfx_mgr02_vglite_build_image(p_cntx_SP ,&fl_element_def_SP);
                hmi_gfx_mgr02_imxrt_mem_mgmt_free(fl_temp_buffer);
        #endif 
            }   
        }
    }
}

#ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_render_cache_outline_glyph
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_vglite_render_cache_outline_glyph(FT_OutlineGlyph const glyph, vg_lite_path_t *p_vgpath)
{
    UINT32 fl_error;
    
    const FT_Outline_Funcs fl_outline_fp =
    {
        (FT_Outline_MoveToFunc)hmi_gfx_mgr02_vglite_outline_move_to,
        (FT_Outline_LineToFunc)hmi_gfx_mgr02_vglite_outline_line_to,
        (FT_Outline_ConicToFunc)hmi_gfx_mgr02_vglite_outline_conic_to,
        (FT_Outline_CubicToFunc)hmi_gfx_mgr02_vglite_outline_cubic_to,
        0, 0
    };

    fl_error = (UINT32)FT_Outline_Decompose(&glyph->outline, &fl_outline_fp, (void *)p_vgpath);
    
    /* check if path buffer is full, if not append end command and close the path */
    if ( fl_error == (UINT32)0)  
    {        
        UINT8 fl_type_u8 = VLC_OP_END; 
        fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs(p_vgpath, fl_type_u8, GFX_MGR02_NULL_PTR);
    }
  
    return fl_error;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_render_outline_glyph
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_vglite_render_outline_glyph(FT_GlyphSlot const glyph, vg_lite_path_t *p_vgpath)	
{
    UINT32 fl_error;

    const FT_Outline_Funcs fl_outline_fp =
    {
        (FT_Outline_MoveToFunc)hmi_gfx_mgr02_vglite_outline_move_to,
        (FT_Outline_LineToFunc)hmi_gfx_mgr02_vglite_outline_line_to,
        (FT_Outline_ConicToFunc)hmi_gfx_mgr02_vglite_outline_conic_to,
        (FT_Outline_CubicToFunc)hmi_gfx_mgr02_vglite_outline_cubic_to,
        0, 0
    };

    fl_error = (UINT32)FT_Outline_Decompose(&glyph->outline, &fl_outline_fp, (void *)p_vgpath);
    
    /* check if path buffer is full, if not append end command and close the path */
    if ( fl_error == (UINT32)0) 
    {        
        UINT8 fl_type_u8 = VLC_OP_END; 
        fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs(p_vgpath, fl_type_u8, GFX_MGR02_NULL_PTR);
    }
    return fl_error;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_outline_move_to
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static UINT32 hmi_gfx_mgr02_vglite_outline_move_to(const GFX_MGR02_VECTOR *to, void *user)
{
    UINT32 fl_error = 0u; 
    UINT8 fl_type_u8 = VLC_OP_MOVE;
    vg_lite_float_t path_data[2] = {((vg_lite_float_t)to->x/64.0f), 
                              ((vg_lite_float_t)to->y/-64.0f)};
    fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs((vg_lite_path_t *)user, fl_type_u8, (void*)&path_data);
    return (fl_error);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_outline_line_to
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static UINT32 hmi_gfx_mgr02_vglite_outline_line_to(const GFX_MGR02_VECTOR *to, void *user)
{
    UINT32 fl_error = 0u;
    UINT8 fl_type_u8 = VLC_OP_LINE;
    vg_lite_float_t path_data[2] = {((vg_lite_float_t)to->x/64.0f), 
                              ((vg_lite_float_t)to->y/-64.0f)};
    fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs((vg_lite_path_t *)user, fl_type_u8, (void*)&path_data);
    return (fl_error);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_outline_conic_to
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static UINT32 hmi_gfx_mgr02_vglite_outline_conic_to(const GFX_MGR02_VECTOR *control, const GFX_MGR02_VECTOR *to, void *user)
{
    UINT32 fl_error = 0u;
    UINT8 fl_type_u8 = VLC_OP_QUAD;
    vg_lite_float_t path_data[4] = {((vg_lite_float_t)control->x/64.0f), 
                              ((vg_lite_float_t)control->y/-64.0f), 
                              ((vg_lite_float_t)to->x/64.0f), 
                              ((vg_lite_float_t)to->y/-64.0f)}; 
    fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs((vg_lite_path_t *)user, fl_type_u8, (void*)&path_data);
    return (fl_error);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_outline_cubic_to
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static UINT32 hmi_gfx_mgr02_vglite_outline_cubic_to(const GFX_MGR02_VECTOR *control1, const GFX_MGR02_VECTOR *control2, const GFX_MGR02_VECTOR *to, void *user)
{
    UINT32 fl_error = 0u;
    UINT8 fl_type_u8 = VLC_OP_CUBIC;
    vg_lite_float_t path_data[6] = {((vg_lite_float_t)control1->x/64.0f), 
                              ((vg_lite_float_t)control1->y/-64.0f),
                              ((vg_lite_float_t)control2->x/64.0f), 
                              ((vg_lite_float_t)control2->y/-64.0f),
                              ((vg_lite_float_t)to->x/64.0f), 
                              ((vg_lite_float_t)to->y/-64.0f)}; 
    fl_error = hmi_gfx_mgr02_vglite_append_path_data_abs((vg_lite_path_t *)user, fl_type_u8, (void*)&path_data);
    return (fl_error);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_append_path_data_abs
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static UINT32 hmi_gfx_mgr02_vglite_append_path_data_abs(vg_lite_path_t *path, UINT8 cmd, void *data)
{
    SINT32 j;
    vg_lite_float_t *dataf = (vg_lite_float_t*)data;
    vg_lite_float_t *pathf = NULL;
    uint8_t *pathc = NULL;
    UINT32 fl_path_buf_full = (UINT32)0;
    SINT32 data_size = (SINT32)sizeof(vg_lite_float_t); /* data format is assumed as VG_LITE_FP32 */
    vg_lite_float_t cx = 0.0f, cy = 0.0f;
    
    SINT32 offset = path->path_length;
    SINT32 dataCount = hmi_gfx_mgr02_vglite_get_data_count(cmd);
    pathc = (uint8_t *)path->path;
    
    if ((GFX_MGR02_CDALIGN((offset+1), data_size) + (dataCount * data_size)) <= GFX_MGR02_TXT_PATH_CMD_BUF_LENGTH)
    {
        *(pathc + offset) = cmd;
        offset++;
        if ((dataCount > 0) && (dataf != GFX_MGR02_NULL_PTR))
        {
          offset = GFX_MGR02_CDALIGN(offset, data_size);
          pathf = (vg_lite_float_t*)(pathc + offset);
          for (j = 0; j < (dataCount / 2); j++)
          {
            pathf[j * 2] = *dataf;
            dataf++;
            pathf[(j * 2) + 1] = *dataf;
            dataf++;

            cx = (vg_lite_float_t)pathf[j * 2];
            cy = (vg_lite_float_t)pathf[(j * 2) + 1];

            /* Update path bounds. */
            path->bounding_box[0] = GFX_MGR02_CDMIN(path->bounding_box[0], cx);
            path->bounding_box[2] = GFX_MGR02_CDMAX(path->bounding_box[2], cx);
            path->bounding_box[1] = GFX_MGR02_CDMIN(path->bounding_box[1], cy);
            path->bounding_box[3] = GFX_MGR02_CDMAX(path->bounding_box[3], cy);
          }
          offset += (dataCount * data_size);
        }
        path->path_length = offset;
    }
    else
    {
        /* Path command buffer is either already full or will overflow on appending more data; 
         * no more commands and path data can be appended into the path buffer */
        fl_path_buf_full = (UINT32)1;
    }
    return fl_path_buf_full;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_get_data_count
Description          : 
Invocation           : Invoked internally
Parameters           : 
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/

static SINT32 hmi_gfx_mgr02_vglite_get_data_count(UINT8 cmd)
{
    SINT32 data_count;
    
    switch (cmd)
    {
        case VLC_OP_END:   
        case VLC_OP_CLOSE: 
            data_count = 0;
        break;
        
        case VLC_OP_MOVE:    
        case VLC_OP_MOVE_REL:
        case VLC_OP_LINE:   
        case VLC_OP_LINE_REL:
            data_count = 2;
        break;
        
        case VLC_OP_QUAD:     
        case VLC_OP_QUAD_REL:
            data_count = 4;
        break;
        
        case VLC_OP_CUBIC:    
        case VLC_OP_CUBIC_REL:
            data_count = 6;
        break;
        
        default:
            data_count = -1;
        break;    
    }
    return data_count;
}

#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_get_pixel_format
Description          : To get vglite pixel format of the passed buffer format
Invocation           : Invoked internally
Parameters           : frame buffer pixel format or element pixel format type
Return Value         : corresponding vglite pixel format
Critical Section     :
External Interfaces  :
******************************************************************************/
static vg_lite_buffer_format_t hmi_gfx_mgr02_vglite_get_pixel_format(UINT8 p_pix_format)
{
    vg_lite_buffer_format_t fmt;
    switch (p_pix_format)
    {
        case GFX_MGR02_PIX_FORMAT_A8:
            fmt = VG_LITE_A8;
        break;
        
        case GFX_MGR02_PIX_FORMAT_RGB565:
            fmt = VG_LITE_BGR565;
        break;

        case GFX_MGR02_PIX_FORMAT_ARGB1555:
            fmt = VG_LITE_BGRA5551;
        break;

        case GFX_MGR02_PIX_FORMAT_ARGB4444:
            fmt = VG_LITE_BGRA4444;
        break;
        
        case GFX_MGR02_PIX_FORMAT_ARGB8888:
        default:
            fmt = VG_LITE_BGRA8888;
        break;
    }
    return fmt;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_get_blendmode
Description          : To get vglite blendmode of the passed image format
Invocation           : Invoked internally
Parameters           : image format
Return Value         : blendmode
Critical Section     :
External Interfaces  :
******************************************************************************/
static vg_lite_blend_t hmi_gfx_mgr02_vglite_get_blendmode(GFX_MGR02_CONTEXT_T const * p_cntx_SP, vg_lite_buffer_format_t format)
{
    vg_lite_blend_t fl_blend_mode;
    switch(format)
    {
        case VG_LITE_BGRA8888:
        case VG_LITE_BGRA4444:
        case VG_LITE_BGRA5551:
        case VG_LITE_A8:
        case VG_LITE_A4:
        {
            fl_blend_mode = VG_LITE_BLEND_SRC_OVER;
        }
        break;
        default:
        {
            if(p_cntx_SP->state.alpha < 255U)
            {
                fl_blend_mode = VG_LITE_BLEND_SRC_OVER;
            }
            else
            {
                fl_blend_mode = VG_LITE_BLEND_NONE;
            }
        }
        break;
    }
    return fl_blend_mode;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_get_bpp
Description          : To get bits per pixel value of the passed buffer format
Invocation           : Invoked internally
Parameters           : vglite buffer format
Return Value         : bits per pixel value
Critical Section     :
External Interfaces  :
******************************************************************************/
static SINT32 hmi_gfx_mgr02_vglite_get_bpp(vg_lite_buffer_format_t p_pix_format)
{
    SINT32 fl_bpp;
    switch (p_pix_format)
    {
        case VG_LITE_BGRA8888:
            fl_bpp = 32;
        break;

        case VG_LITE_BGRA4444:
        case VG_LITE_BGRA5551:
        case VG_LITE_BGR565:
            fl_bpp = 16;
        break;
        
        case VG_LITE_A8:
            fl_bpp = 8;
        break;

        case VG_LITE_A4:
            fl_bpp = 4;
        break;            

        default:
             fl_bpp = 32;
        break;
    }
    return fl_bpp;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_fb_copy
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/

s_gx_flocal hmi_gfx_mgr02_vglite_fb_copy(GFX_MGR02_CONTEXT_T const * p_cntx_SP, void  *p_src_ptr , void  *p_dst_ptr)
{
    s_gx_flocal fl_ret_value = (s_gx_flocal) 0;
    if((p_src_ptr != NULL) && (p_dst_ptr != NULL))
    {
        vg_lite_buffer_t dstBuffer = {0};
        vg_lite_buffer_t srcBuffer = {0}; 

        UINT16 fb_width = (p_cntx_SP->rprop.fb_w/16u) * 16u;
        UINT16 fb_height = (p_cntx_SP->rprop.fb_h * p_cntx_SP->rprop.fb_w)/fb_width;
        UINT16 fl_remaining_pixels = ((p_cntx_SP->rprop.fb_h * p_cntx_SP->rprop.fb_w) - (fb_height * fb_width));
        
        vg_lite_buffer_format_t fl_pixel_format = hmi_gfx_mgr02_vglite_get_pixel_format(p_cntx_SP->rprop.fb_format);
        SINT32 fl_bpp_size = hmi_gfx_mgr02_vglite_get_bpp(fl_pixel_format);
        
        /* Configure Destination Buffer */
        dstBuffer.width              = (SINT32)fb_width;
        dstBuffer.height             = (SINT32)fb_height;
        dstBuffer.stride             = (SINT32)fb_width * (fl_bpp_size/8);
        dstBuffer.format             = fl_pixel_format;
        dstBuffer.memory             = p_dst_ptr;
        dstBuffer.address            = (UINT32)p_dst_ptr;

        /* Configure Source Buffer */
        srcBuffer.width              = (SINT32)fb_width;
        srcBuffer.height             = (SINT32)fb_height;
        srcBuffer.stride             = (SINT32)fb_width * (fl_bpp_size/8);
        srcBuffer.format             = fl_pixel_format;
        srcBuffer.memory             = p_src_ptr;
        srcBuffer.address            = (UINT32)p_src_ptr;

        hmi_gfx_mgr02_vglite_matrix_load_identity();
        
        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_disable_premultiply());
        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_blit(&dstBuffer, &srcBuffer, &l_vglite_matrix, VG_LITE_BLEND_NONE, 0, VG_LITE_FILTER_POINT));
        GFX_VGL_UTIL_SUCCESS(l_vgl_error, vg_lite_enable_premultiply());
        
        if (fl_remaining_pixels > 0U)
        {
            void *fl_dst_ptr = (void*)(dstBuffer.address + ((UINT32)dstBuffer.stride*(UINT32)dstBuffer.height));
            void const *fl_src_ptr = (void*)(srcBuffer.address + ((UINT32)srcBuffer.stride*(UINT32)srcBuffer.height));
            
            (void)memcpy(fl_dst_ptr, fl_src_ptr, (fl_remaining_pixels * ((UINT32)fl_bpp_size/8U)));
        }
        
        fl_ret_value = 1;
    }
    return (fl_ret_value);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_get_bound
Description          : Calculates the transformed bounds of an elements passed boundary
Invocation           : invoked by hmi_gfx_mgr02_generic.c
Parameters           : Object Type, Context and bounds
Return Value         : Boundary
Critical Section     : None
External Interfaces  : None
******************************************************************************/

s_gx_flocal hmi_gfx_mgr02_vglite_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds)
{
   vg_lite_float_t fl_cur_matrix[9];
   vg_lite_float_t x1;
   vg_lite_float_t y1;
   vg_lite_float_t x2;
   vg_lite_float_t y2;
   vg_lite_float_t x3;
   vg_lite_float_t y3;
   vg_lite_float_t x4;
   vg_lite_float_t y4;
   vg_lite_float_t minx;
   vg_lite_float_t miny;
   vg_lite_float_t maxx;
   vg_lite_float_t maxy;

   fl_cur_matrix[0]  = (p_cntx_SP->state.matrix[0]);
   fl_cur_matrix[0] += ((vg_lite_float_t)p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[2]);
   fl_cur_matrix[1]  = (p_cntx_SP->state.matrix[1]);
   fl_cur_matrix[1] += ((vg_lite_float_t)p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[2]);
   fl_cur_matrix[2]  = (p_cntx_SP->state.matrix[2]);

   fl_cur_matrix[3]  = (p_cntx_SP->state.matrix[3]);
   fl_cur_matrix[3] += ((vg_lite_float_t)p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[5]);
   fl_cur_matrix[4]  = (p_cntx_SP->state.matrix[4]);
   fl_cur_matrix[4] += ((vg_lite_float_t)p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[5]);
   fl_cur_matrix[5]  = (p_cntx_SP->state.matrix[5]);

   fl_cur_matrix[6]  = (p_cntx_SP->state.matrix[6]);
   fl_cur_matrix[6] += ((vg_lite_float_t)p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[8]);
   fl_cur_matrix[7]  = (p_cntx_SP->state.matrix[7]);
   fl_cur_matrix[7] += ((vg_lite_float_t)p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[8]);
   fl_cur_matrix[8]  = (p_cntx_SP->state.matrix[8]);

   if(p_obj_type == GFX_MGR02_TYPE_SVG)
   {
      /* TODO Check whether vg_lite_translate can be used here*/
      hmi_gfx_mgr02_vglite_util_matrix_translate(fl_cur_matrix, p_bounds[0], p_bounds[1]);
   }
   hmi_gfx_mgr02_vglite_util_matrix_translate(fl_cur_matrix, -p_cntx_SP->rprop.pivot.x, -p_cntx_SP->rprop.pivot.y);

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

   return 1;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_util_matrix_translate
Description          : Internal matrix translation function.
Invocation           : Invoked by hmi_gfx_mgr02_ogllib_get_bound()
Parameters           : Matrix, Tx, Ty.
Return Value         : None
******************************************************************************/

static void hmi_gfx_mgr02_vglite_util_matrix_translate(vg_lite_float_t * m2, vg_lite_float_t tx, vg_lite_float_t ty)
{
   vg_lite_float_t fl_m2[3];

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
Function Name        : hmi_gfx_mgr02_vglite_matrix_translate
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/

static void hmi_gfx_mgr02_vglite_matrix_translate(vg_lite_float_t tx,vg_lite_float_t ty)
{
   vg_lite_translate(tx, ty, &l_vglite_matrix);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_matrix_load_identity
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/

static void hmi_gfx_mgr02_vglite_matrix_load_identity(void)
{
   vg_lite_identity(&l_vglite_matrix);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_vglite_matrix_multiply
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/

static void hmi_gfx_mgr02_vglite_matrix_multiply(vg_lite_float_t const *matrix)
{
    vg_lite_matrix_t fl_temp_matrix;
    UINT8 row, column;

    /* Process all rows. */
    for (row = 0u; row < 3u; row++)
    {
        /* Process all columns. */
        for (column = 0u; column < 3u; column++)
        {
            /* Compute matrix entry. */
            fl_temp_matrix.m[row][column] =  (l_vglite_matrix.m[row][0] * matrix[(3u * column) + 0u])
                                           + (l_vglite_matrix.m[row][1] * matrix[(3u * column) + 1u])
                                           + (l_vglite_matrix.m[row][2] * matrix[(3u * column) + 2u]);
        }
    }

    l_vglite_matrix.m[0][0] = fl_temp_matrix.m[0][0];
    l_vglite_matrix.m[0][1] = fl_temp_matrix.m[0][1];
    l_vglite_matrix.m[0][2] = fl_temp_matrix.m[0][2];
    l_vglite_matrix.m[1][0] = fl_temp_matrix.m[1][0];
    l_vglite_matrix.m[1][1] = fl_temp_matrix.m[1][1];
    l_vglite_matrix.m[1][2] = fl_temp_matrix.m[1][2];
    l_vglite_matrix.m[2][0] = fl_temp_matrix.m[2][0];
    l_vglite_matrix.m[2][1] = fl_temp_matrix.m[2][1];
    l_vglite_matrix.m[2][2] = fl_temp_matrix.m[2][2];
}

#if !defined(GFX_MGR02_IMXRT)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_is_emergency_shutdown_req_active
Description          : Get emergency shutdown mode status
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
  return (l_gfx_mgr_shutdown_status);
}
#endif

/****************************************************************************
Function Name        : GPU2D_IRQHandler
Description          : IRQ_Handler for GPU hardware.
Invocation           :
Parameters           : None
Return Value         : None
Critical Section     :
External Interfaces  :
******************************************************************************/
void GPU2D_IRQHandler(void)
{
    #if defined(APM_ENABLED) && defined(APM_ISR_CHECK_POINT_ENABLED)
    /* Following change has been added by the platform team to measure ISR cpu load in freertos */
    Apm_PreCheckpointProcess(1); 
    #endif

    vg_lite_IRQHandler();

    #if defined(APM_ENABLED) && defined(APM_ISR_CHECK_POINT_ENABLED)
    Apm_PostCheckpointProcess(1);
    #endif
    /*SDK_ISR_EXIT_BARRIER is added for Errata ERR009005 fix, Ref - IMXRT1170CE 2024.pdf */
    SDK_ISR_EXIT_BARRIER;
}

#endif /* #if defined(GFX_MGR02_VGLITE) */

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
** 
** CMS Rev 1.0      31-Jan-2022     MCHOUDHA
** Initial version created
**==========================================================================*/


/* end of file =============================================================*/
