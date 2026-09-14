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
 ** Name:           hmi_gfx_manager_swlib.c
 **
 ** Description:    module for software rendering interfaces
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

 /************************** Start of Module *********************************/

 /*****************************************************************************
                             Module Name
 *****************************************************************************/

#define HMI_GFX_MGR02_SWRLIB_C
#define HMI_GFX_MGR02_PRIV_C 

 /*****************************************************************************
                             Include files
 *****************************************************************************/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_SOFTWARE)
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_swrlib.h"
#include "hmi_gfx_mgr02_text.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*****************************************************************************
                            Macro & Type Definitions
*****************************************************************************/

typedef struct
{
   GFX_MGR02_ISIZE_X_T x;
   GFX_MGR02_ISIZE_Y_T y;
   GFX_MGR02_ISIZE_W_T w;
   GFX_MGR02_ISIZE_H_T h;
   GFX_MGR02_ISIZE_W_T x_offset;
   GFX_MGR02_ISIZE_H_T y_offset;
}GFX_MGR02_CLIP_IMAGE_DATA;

#if defined GFX_MGR02_COMPRESSION_ENABLED
typedef struct
{
    UINT8 const * bmp_data;  /*Compressed image data address*/
    UINT32   data;           /*Decompressed image data*/
    UINT8   count;           /*Number of times the same data to be repeated*/
    UINT8   flag;            /*If flag is 1 means, repeat the data, count number of times.*/         
}GFX_ONLINE_RLE;
#endif
/*****************************************************************************
                            Static Function Declarations
*****************************************************************************/

static void hmi_gfx_mgr02_swrlib_build_rgb565(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_rgb565_ext(GFX_MGR02_CONTEXT_T   const* p_context_SP, GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_argb8888_ext(GFX_MGR02_CONTEXT_T const* p_context_SP, GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_argb8888_optimized(GFX_MGR02_CONTEXT_T const* p_context_SP, GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_32bpp(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_a4_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_a8_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_a4_trans_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_a8_trans_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static void hmi_gfx_mgr02_swrlib_build_argb4444(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP);
static GFX_MGR02_ISIZE_W_T hmi_gfx_mgr02_swrlib_next_loc(UINT8* const p_flag, GFX_MGR02_ISIZE_W_T p_width_offs);
#ifdef GFX_MGR02_CLIPPED_WIDGETS
static void hmi_gfx_mgr02_swrlib_clip(GFX_MGR02_CONTEXT_T const * p_context_SP, GFX_MGR02_CLIP_IMAGE_DATA * p_clip_image_data_SP);
#endif
#if defined GFX_MGR02_COMPRESSION_ENABLED
static void GfxDriverRLEonline(GFX_ONLINE_RLE * p_rle_online, UINT8 p_src_format_u8);
static void GfxDriverRLEonlineNLine(GFX_ONLINE_RLE * p_rle_online, UINT8 p_src_format_u8, UINT16 p_width_u16);
#endif
static void hmi_gfx_mgr02_swrlib_render_bmp_font(GFX_MGR02_CONTEXT_T const * p_cntx_SP, 
                                                 HMI_CHAR const * p_string_ptr, 
                                                 GFX_MGR02_FONT const * p_font_SP, 
                                                 UINT32 p_draw_color, 
                                                 UINT32 p_str_length,
                                                 SINT16 p_start_x);
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
static void hmi_gfx_mgr02_swrlib_blend_operation(void* p_fb_cur_pixel_ptr, UINT8 p_src_a, UINT32 p_src_color_rgb, UINT8 p_fb_format);

/*****************************************************************************
                            Static Variable Declarations
*****************************************************************************/

static volatile UINT8 l_gfx_mgr_shutdown_status;

/*****************************************************************************
                            Function Definitions
*****************************************************************************/

/****************************************************************************
 ** Function Name:    hmi_gfx_mgr02_emergency_shutdown
 ** Description:      Set the shutdown mode type as emergency shutdown
 ** Invocation:       Layout
 ** Inputs/Outputs:   None
 ** Critical Section: None.
******************************************************************************/
void hmi_gfx_mgr02_emergency_shutdown(void)
{
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_EMERGENCY;
}

/****************************************************************************
 ** Function Name:    hmi_gfx_mgr02_is_emergency_shutdown_req_active
 ** Description:      Returns the shutdown mode type.
 ** Invocation:       Internal
 ** Inputs/Outputs:   l_gfx_mgr_shutdown_status
 ** Critical Section: None.
******************************************************************************/
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
    return l_gfx_mgr_shutdown_status;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP,
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{   
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
    UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    if ((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
        && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
        )
    {
        UINT8 fl_bgcolor_alpha = (UINT8)(0x000000FFUL & (p_elem_def_SP->color >> 24U));

        if(p_cntx_SP->state.alpha != 0U)
        {
            if(GFX_MGR02_PIX_FORMAT_RGB565 == p_cntx_SP->rprop.fb_format)
            {
                switch (p_elem_def_SP->format)
                {
                    case VG_sRGB_565:
                        hmi_gfx_mgr02_swrlib_build_rgb565(p_cntx_SP,p_elem_def_SP);
                    break;

                    case VG_sARGB_8888:
                        hmi_gfx_mgr02_swrlib_build_32bpp(p_cntx_SP,p_elem_def_SP);
                    break;

                    case VG_A_4:
                        if(GFX_MGR02_IMAGE_CHROMA_KEY_YES == p_elem_def_SP->chroma_key)
                        {
                            hmi_gfx_mgr02_swrlib_build_a4_trans_image(p_cntx_SP,p_elem_def_SP);
                        }
                        else
                        {
                            hmi_gfx_mgr02_swrlib_build_a4_image(p_cntx_SP,p_elem_def_SP);
                        }
                    break;

                    case VG_A_8:
                        if(GFX_MGR02_IMAGE_CHROMA_KEY_YES == p_elem_def_SP->chroma_key)
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_trans_image(p_cntx_SP,p_elem_def_SP);
                        }
                        else
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_image(p_cntx_SP,p_elem_def_SP);
                        }
                    break;

                    default:
                    /* Not supported formats in software */
                    break;
                }
            }
            else if(GFX_MGR02_PIX_FORMAT_ARGB4444 == p_cntx_SP->rprop.fb_format)
            {
                switch (p_elem_def_SP->format)
                {
                    case VG_A_4:
                        if(GFX_MGR02_IMAGE_CHROMA_KEY_YES == p_elem_def_SP->chroma_key)
                        {
                            hmi_gfx_mgr02_swrlib_build_a4_trans_image(p_cntx_SP,p_elem_def_SP);
                        }
                        else
                        {
                            hmi_gfx_mgr02_swrlib_build_a4_image(p_cntx_SP,p_elem_def_SP);
                        }
                    break;

                    case VG_A_8:
                        if(GFX_MGR02_IMAGE_CHROMA_KEY_YES == p_elem_def_SP->chroma_key)
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_trans_image(p_cntx_SP,p_elem_def_SP);
                        }
                        else
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_image(p_cntx_SP,p_elem_def_SP);
                        }
                    break;

                    case VG_sARGB_4444:
                        hmi_gfx_mgr02_swrlib_build_argb4444(p_cntx_SP,p_elem_def_SP);
                    break;
                    default:
                    /* Not supported formats in software */
                    break;
                }
            }
            else if(GFX_MGR02_PIX_FORMAT_ARGB8888 == p_cntx_SP->rprop.fb_format)
            {
                switch (p_elem_def_SP->format)
                {
                    case VG_sRGB_565:
                    {
                        hmi_gfx_mgr02_swrlib_build_rgb565_ext(p_cntx_SP, p_elem_def_SP);
                    }
                    break;
                    case VG_sARGB_8888:
                    {
                        hmi_gfx_mgr02_swrlib_build_argb8888_ext(p_cntx_SP, p_elem_def_SP);
                    }
                    break;
                    case VG_A_8:
                    {
                        if ((0U == fl_bgcolor_alpha) || ( GFX_MGR02_IMAGE_CHROMA_KEY_YES == p_elem_def_SP->chroma_key))
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_trans_image(p_cntx_SP, p_elem_def_SP);
                        }
                        else if (255U == fl_bgcolor_alpha)
                        {
                            hmi_gfx_mgr02_swrlib_build_a8_image(p_cntx_SP, p_elem_def_SP);
                        }
                        else
                        {
                            /* Invalid Configuration - bg color alpha should be 0 or 255 only */
                        }
                    }
                    break;
                    default:
                        /* Image format is not supported in the software platform */
                    break;
                }
            }
            else
            {
                /* fb target format is not supported in the software platform */
            }
        }
    }
#endif
   return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_fill
Description          : Builds a fill object
Invocation           : Invoked internally
Parameters           : element definition and dimention of fill area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_build_fill(GFX_MGR02_CONTEXT_T  const * p_context_SP, 
                                            GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{
    UINT32 fl_global_alpha_U32, fl_fillcolor_alpha_U32, fl_alpha_U32;

    fl_global_alpha_U32     = (UINT32)p_context_SP->state.alpha;
    fl_fillcolor_alpha_U32  = ((0xFF000000UL & p_context_SP->rprop.fg_color) >> 24);
    fl_alpha_U32            = (fl_fillcolor_alpha_U32 * fl_global_alpha_U32) / 255UL;

    if (fl_global_alpha_U32 != 0UL)
    {
        GFX_MGR02_CLIP_IMAGE_DATA fl_clip_data_S;

        fl_clip_data_S.x        = p_context_SP->state.loc.x;
        fl_clip_data_S.y        = p_context_SP->state.loc.y;
        fl_clip_data_S.w        = p_dim->width;
        fl_clip_data_S.h        = p_dim->height;
        fl_clip_data_S.x_offset = 0;
        fl_clip_data_S.y_offset = 0;
        
#ifdef GFX_MGR02_CLIPPED_WIDGETS
        hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif
        if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
        {            
            UINT16  fl_prev_bg_U16;
            UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
            UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;

            GFX_MGR02_ISIZE_W_T  fl_cur_x_size, fl_image_width;
            GFX_MGR02_ISIZE_H_T  fl_image_height;
            GFX_MGR02_ISIZE_W_T  fl_frame_width_offs;
       
            fl_image_height = fl_clip_data_S.h-fl_clip_data_S.y_offset;
            fl_image_width  = fl_clip_data_S.w-fl_clip_data_S.x_offset;
            fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;

            switch (p_context_SP->rprop.fb_format)
            {
                case GFX_MGR02_PIX_FORMAT_RGB565:
                {
                    UINT32 fl_load_color_U32;
                    UINT32 fl_prev_blend_U32 = 0UL;
                    UINT16 * fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                    fl_frame_buff_U16P = fl_frame_buff_U16P + (((fl_clip_data_S.y) * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);
                    
                    fl_fgB_U32 = p_context_SP->rprop.fg_color;
                    fl_fgG_U32 = (fl_fgB_U32 >> 8); 
                    fl_fgR_U32 = (fl_fgG_U32 >> 8); 
                    
                    fl_fgR_U32 = (((fl_fgR_U32 & 0x000000FFUL) * 31U)/255UL);        /* 8 bit to 5 bit */
                    fl_fgG_U32 = (((fl_fgG_U32 & 0x000000FFUL) * 63U)/255UL);        /* 8 bit to 6 bit */
                    fl_fgB_U32 = (((fl_fgB_U32 & 0x000000FFUL) * 31U)/255UL);        /* 8 bit to 5 bit */ 
                    
                    fl_load_color_U32 = (fl_fgB_U32 | (fl_fgG_U32 << 5) | (fl_fgR_U32 << 11));
                    
                    if((fl_alpha_U32 == 255UL) || (fl_fillcolor_alpha_U32 == 0UL))
                    {
                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;

                            while(0U != fl_cur_x_size)
                            {
                                fl_cur_x_size--;

                                /* Perform Direct Copy */
                                *fl_frame_buff_U16P = (UINT16)fl_load_color_U32;
                                fl_frame_buff_U16P += 1;
                            }
                            fl_frame_buff_U16P += fl_frame_width_offs;
                        }
                    }
                    else
                    {
                        /* Layer format is RGB565 and fillcolor format is ARGB8888
                           Scale down RGB888 to RGB565 and blend it with background */ 
                                
                        /* Perform Blend Operation for first pixel and cache its blend result */
                        
                        /* Load BG Color */
                        fl_prev_bg_U16 = *fl_frame_buff_U16P;                             
                        
                        fl_BgB_U32 = fl_prev_bg_U16; 
                        fl_BgG_U32 = (fl_BgB_U32 >> 5); 
                        fl_BgR_U32 = (fl_BgG_U32 >> 6);
                        
                        fl_BgB_U32 &= 0x0000001FUL; 
                        fl_BgG_U32 &= 0x0000003FUL; 
                        fl_BgR_U32 &= 0x0000001FUL;
                        
                        /* Blend Operation */
                        fl_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                        fl_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                        fl_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                        fl_prev_blend_U32 = fl_BgB_U32  | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11);

                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;

                            while(0U != fl_cur_x_size)
                            {
                                fl_cur_x_size--;
                                
                                if(fl_prev_bg_U16 == *fl_frame_buff_U16P)
                                {
                                    /* Copy previous blend operation result */
                                    *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                                }
                                else
                                {           
                                    /* Perform Blend Operation */ 
                                    /* Load BG Color */
                                    fl_prev_bg_U16 = *fl_frame_buff_U16P; 
                                    
                                    fl_BgB_U32 = fl_prev_bg_U16; 
                                    fl_BgG_U32 = (fl_BgB_U32 >> 5); 
                                    fl_BgR_U32 = (fl_BgG_U32 >> 6);
                                    
                                    fl_BgB_U32 &= 0x0000001FUL; 
                                    fl_BgG_U32 &= 0x0000003FUL; 
                                    fl_BgR_U32 &= 0x0000001FUL;

                                    /* Blend */
                                    fl_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                                    fl_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                                    fl_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);

                                    fl_prev_blend_U32 = fl_BgB_U32 | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11);

                                    /* Writeback */
                                    *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                                }
                                fl_frame_buff_U16P += 1;
                            }
                            fl_frame_buff_U16P += fl_frame_width_offs;
                        }
                    }
                }
                break;
                case GFX_MGR02_PIX_FORMAT_ARGB4444:
                {
                    UINT32 fl_load_color_U32, fl_fr_alphaU32;
                    UINT32 fl_prev_blend_U32 = 0UL;
                    UINT16 *fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                    fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);
                    
                    fl_fgB_U32 = p_context_SP->rprop.fg_color >> 4;
                    fl_fgG_U32 = (fl_fgB_U32 >> 8); 
                    fl_fgR_U32 = (fl_fgG_U32 >> 8);
                    
                    fl_fgB_U32 &= 0x0000000FUL; 
                    fl_fgG_U32 &= 0x0000000FUL; 
                    fl_fgR_U32 &= 0x0000000FUL;
                    
                    fl_alpha_U32 = fl_alpha_U32/17UL; /* 8 to 4 bit*/

                    fl_load_color_U32 = (UINT16)((fl_alpha_U32 << 12) | fl_fgB_U32 | (fl_fgG_U32 << 4) | (fl_fgR_U32 << 8));
                    
                    if((fl_alpha_U32 == 15UL) || (fl_fillcolor_alpha_U32 == 0UL))
                    {
                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;

                            while(0U != fl_cur_x_size)
                            {
                                fl_cur_x_size--;
                                
                                /* Perform Direct Copy */
                                *fl_frame_buff_U16P = (UINT16)fl_load_color_U32;
                                fl_frame_buff_U16P += 1;
                            }
                            fl_frame_buff_U16P += fl_frame_width_offs;
                        }   
                    }
                    else
                    {
                        /* Layer format is ARGB4444 and fillcolor format is ARGB8888
                           Scale down ARGB8888 to ARGB4444 and blend it with background */ 
                           
                        /* Perform Blend Operation for first pixel and cache its blend result */
                        
                        /* Load BG Color */
                        fl_prev_bg_U16 = *fl_frame_buff_U16P;
                        fl_BgR_U32 = 0x000FUL; fl_BgG_U32 = 0x000FUL; fl_BgB_U32 = 0x000FUL;
                        
                        /* Blend */
                        fl_BgR_U32 = (fl_BgR_U32 + fl_fgR_U32)/2UL;
                        fl_BgG_U32 = (fl_BgG_U32 + fl_fgG_U32)/2UL;
                        fl_BgB_U32 = (fl_BgB_U32 + fl_fgB_U32)/2UL;

                        fl_prev_blend_U32 = (UINT32)((fl_alpha_U32 << 12) | fl_BgB_U32  | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));

                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;

                            while(0U != fl_cur_x_size)
                            {
                                fl_cur_x_size--;
                                
                                if(fl_prev_bg_U16 == *fl_frame_buff_U16P)
                                {
                                    /* Copy previous blend operation result */
                                    *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                                }
                                else
                                {
                                    /* Perform Blend Operation */ 
                                    /* Load BG Color */
                                    fl_prev_bg_U16 = *fl_frame_buff_U16P;                             
                                    fl_fr_alphaU32 = (((((UINT32)fl_prev_bg_U16 & 0x0000F000UL) >> 12U)) * fl_alpha_U32) / 15UL;

                                    fl_BgB_U32 = fl_prev_bg_U16; fl_BgG_U32 = (fl_BgB_U32 >> 4); fl_BgR_U32 = (fl_BgG_U32 >> 4);
                                    fl_BgB_U32 &= 0x0000000FUL; fl_BgG_U32 &= 0x0000000FUL; fl_BgR_U32 &= 0x0000000FUL;
                                    
                                    /* Blend */
                                    fl_BgR_U32 = (fl_BgR_U32 + fl_fgR_U32)/2UL;
                                    fl_BgG_U32 = (fl_BgG_U32 + fl_fgG_U32)/2UL;
                                    fl_BgB_U32 = (fl_BgB_U32 + fl_fgB_U32)/2UL;
                                    fl_prev_blend_U32 = (UINT32)((fl_fr_alphaU32 << 12) | fl_BgB_U32  | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));
                                    
                                    /* Writeback */
                                    *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                                }
                                fl_frame_buff_U16P += 1;
                            }
                            fl_frame_buff_U16P += fl_frame_width_offs;
                        }
                    }
                }
                break;
                case GFX_MGR02_PIX_FORMAT_ARGB8888:
                {
                    UINT32 *fl_frame_buff_U32P = (UINT32*)p_context_SP->rprop.fb_P;
                    UINT32  fl_load_color_U32;
                    
                    fl_frame_buff_U32P = fl_frame_buff_U32P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);
                    fl_load_color_U32 = p_context_SP->rprop.fg_color;
                    
                    if((fl_alpha_U32 == 255UL) || (fl_fillcolor_alpha_U32 == 0UL))
                    {
                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;
                            
                            while(0U != fl_cur_x_size)
                            {
                                fl_cur_x_size--;
                                
                                /* Perform Direct Copy */ 
                                *fl_frame_buff_U32P = fl_load_color_U32;
                                fl_frame_buff_U32P += 1;
                            }
                            fl_frame_buff_U32P += fl_frame_width_offs;
                        }
                    }
                    else
                    {
                        UINT32 fl_prev_dst_p = 0UL;
                        UINT32 fl_prev_blend_U32 = 0UL;
                        
                        while(0U != fl_image_height)
                        {
                            fl_image_height--;
                            fl_cur_x_size = fl_image_width;
                            
                            while(0U != fl_cur_x_size)
                            {
                                if (fl_prev_dst_p == *fl_frame_buff_U32P)
                                {
                                    /* Copy previous blend operation result */
                                    *fl_frame_buff_U32P = fl_prev_blend_U32;
                                }
                                else
                                {
                                    /* Perform Blend Operation */ 
                                    fl_prev_dst_p = *fl_frame_buff_U32P;
                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_alpha_U32, fl_load_color_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                    fl_prev_blend_U32 = *fl_frame_buff_U32P;
                                }
                                fl_cur_x_size--;
                                fl_frame_buff_U32P += 1;
                            }
                            fl_frame_buff_U32P += fl_frame_width_offs;
                        }
                    }
                }
                break;
                default:
                {
                    /* Dummy default case to avoid warning */
                }
                break;
            }
        }
    }
    
    GFX_MGR02_UNUSED_PTR(p_elem_def_SP);
    return 0;
}

#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_tile
Description          : Builds a tile object
Invocation           : Invoked internally
Parameters           : element definition and dimention of tile area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_build_tile(GFX_MGR02_CONTEXT_T  const * p_env_SP, 
                                            GFX_MGR02_TILE_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{
    UINT8 fl_x_count_U8;
    UINT8 fl_y_count_U8;
    SINT16 fl_tile_x_U16 = p_env_SP->state.loc.x;
    SINT16 fl_tile_y_U16 = p_env_SP->state.loc.y;
    GFX_MGR02_ISIZE_X_T fl_render_x;
    GFX_MGR02_ISIZE_Y_T fl_render_y;
    GFX_MGR02_ILOC_DATA fl_context_loc_SP;
    GFX_MGR02_IMAGE_DEF_T const *fl_image_SP = &lc_image_layer_def_S[p_elem_def_SP->id];

    /* Set tile area as clip area as this is considered as clip for image */
    GFX_MGR02_IAREA_DATA fl_tile_area_SP;

    fl_x_count_U8 = 0; fl_y_count_U8 = 0; 

    fl_tile_area_SP.x = 0; fl_tile_area_SP.y = 0;
    fl_tile_area_SP.width = p_dim->width;
    fl_tile_area_SP.height = p_dim->height; 
    hmi_gfx_mgr02_context_set_clip(&fl_tile_area_SP);

    fl_render_y = p_env_SP->state.loc.y;
    while(fl_render_y < (fl_tile_y_U16 + (SINT16)p_dim->height))
    {
        fl_render_x = p_env_SP->state.loc.x;
        fl_x_count_U8 = 0;
        while(fl_render_x < (fl_tile_x_U16 + (SINT16)p_dim->width))
        {           
            switch(fl_image_SP->format)
            {
                case VG_sRGB_565:
                case GFX_MGR02_16BPP_RGB565:
                {
                    hmi_gfx_mgr02_swrlib_build_rgb565(p_env_SP,fl_image_SP);
                }
                break;

                case VG_sARGB_8888:
                case GFX_MGR02_32BPP:
                {
                    hmi_gfx_mgr02_swrlib_build_32bpp(p_env_SP,fl_image_SP);
                }
                break;

                case VG_A_4:
                case GFX_MGR02_4BPP_TRANSPARENCY:
                {
                    hmi_gfx_mgr02_context_set_fg_color(fl_image_SP->color);
                    if(GFX_MGR02_IMAGE_CHROMA_KEY_NONE == fl_image_SP->chroma_key)
                    {
                        hmi_gfx_mgr02_swrlib_build_a4_trans_image(p_env_SP,fl_image_SP);
                    }
                    else
                    {
                        hmi_gfx_mgr02_swrlib_build_a4_image(p_env_SP,fl_image_SP);
                    }
                }
                break;

                case VG_A_8:
                case GFX_MGR02_8BPP_TRANSPARENCY:
                {
                    hmi_gfx_mgr02_context_set_fg_color(fl_image_SP->color);
                    if(GFX_MGR02_IMAGE_CHROMA_KEY_NONE == fl_image_SP->chroma_key)
                    {
                        hmi_gfx_mgr02_swrlib_build_a8_trans_image(p_env_SP,fl_image_SP);
                    }
                    else
                    {
                        hmi_gfx_mgr02_swrlib_build_a8_image(p_env_SP,fl_image_SP);
                    }
                }
                break;

                case VG_sARGB_4444:
                case GFX_MGR02_16BPP_ARGB4444:
                {
                    hmi_gfx_mgr02_swrlib_build_argb4444(p_env_SP,fl_image_SP);
                }
                break;

                default:
                /* Not supported formats in software */
                break;
            }
            fl_x_count_U8++;
            /* to set the next image x location in tile */
            fl_context_loc_SP.x = (GFX_MGR02_ISIZE_X_T)fl_image_SP->width;
            fl_context_loc_SP.y = 0;
            hmi_gfx_mgr02_context_set_loc(&fl_context_loc_SP);
            
            fl_render_x = (fl_render_x + (GFX_MGR02_ISIZE_X_T)fl_image_SP->width);
        }
        /* reset the x location to previous location */
        fl_context_loc_SP.x = -((SINT16)fl_image_SP->width) * (SINT16)fl_x_count_U8;
        fl_context_loc_SP.y = 0;
        hmi_gfx_mgr02_context_set_loc(&fl_context_loc_SP);

        fl_y_count_U8++;
        /* to set next image y loaction in tile */
        fl_context_loc_SP.x = 0;
        fl_context_loc_SP.y = (SINT16)fl_image_SP->height;
        hmi_gfx_mgr02_context_set_loc(&fl_context_loc_SP);

        fl_render_y = (fl_render_y + (GFX_MGR02_ISIZE_Y_T)fl_image_SP->height);
    }
    /* reset the y loation to previous location */
    fl_context_loc_SP.x = 0;
    fl_context_loc_SP.y = -((SINT16)fl_image_SP->height) * fl_y_count_U8;
    hmi_gfx_mgr02_context_set_loc(&fl_context_loc_SP);

    return 0;
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_rgb565
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_rgb565(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
    fl_clip_data_S.x_offset = 0;
    fl_clip_data_S.y_offset = 0;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif

    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT16 const * fl_bmp_data_U16P;
        UINT16 * fl_frame_buff_U16P;

        GFX_MGR02_ISIZE_W_T fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T fl_image_height;

        UINT16 fl_prev_bg_U16, fl_prev_fg_U16;
        UINT32 fl_prev_blend_U32;
        UINT32 fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32 fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32 fl_alpha_U32;
#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        UINT16 fl_bmp_data_U16;
        fl_alpha_U32 = (UINT32)p_context_SP->state.alpha;

        fl_bmp_data_U16P   = p_elem_def_SP->pixel_data;
        fl_frame_buff_U16P = p_context_SP->rprop.fb_P;
#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U16P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
        }
        else
#endif
        {
            fl_bmp_data_U16P = &fl_bmp_data_U16P[(fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset];
        }
        fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w)+fl_clip_data_S.x);

        fl_image_width  = fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h-fl_clip_data_S.y_offset;

        fl_frame_width_offs=p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs=p_elem_def_SP->width - fl_image_width;

        fl_prev_bg_U16 = 0; fl_prev_fg_U16 = 0;
        fl_prev_blend_U32 = 0;

        if(p_elem_def_SP->chroma_key == GFX_MGR02_IMAGE_CHROMA_KEY_YES)
        {
            UINT32 fl_trans_color_U32;
            /* Transparent color */
            fl_BgB_U32 = p_elem_def_SP->color; fl_BgG_U32 = (fl_BgB_U32 >> 8); fl_BgR_U32 = (fl_BgG_U32 >> 8);
            fl_BgR_U32   = (((fl_BgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
            fl_BgG_U32   = (((fl_BgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
            fl_BgB_U32   = (((fl_BgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
            fl_trans_color_U32=fl_BgR_U32+fl_BgG_U32+fl_BgB_U32;

            while(0U != fl_image_height)
            {
                fl_image_height--;
                fl_cur_x_size  = fl_image_width;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                fl_data_count_U16 = (UINT16)0;
#endif
                while(0U != fl_cur_x_size)
                {
                    fl_cur_x_size--;                        
#if defined GFX_MGR02_COMPRESSION_ENABLED

                    if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                    {
                        if (fl_rle_cur_s.count == (UINT8)0)
                        {
                            GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                        }
                        if (fl_rle_cur_s.count > (UINT8)0) {
                            fl_rle_cur_s.count--;
                        }
                        if (fl_rle_cur_s.flag == (UINT8)FALSE)
                        {
                            fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data++;
                            fl_bmp_data_U16 = fl_bmp_data_U16 << 8U;
                            fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data++));
                        }
                        else
                        {
                            fl_bmp_data_U16 = (UINT16)fl_rle_cur_s.data;
                        }

                        fl_data_count_U16++;
                        if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                        {
                            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                            fl_data_count_U16 = (UINT16)0;
                        }
                    }
                    else
#endif
                    {
                        fl_bmp_data_U16 = *fl_bmp_data_U16P;
                    }
                    /* The layer format is RGB 565 and image format is RGB 565
                       blend forground and back ground if the alpha value is other than 0 and 255 */
                       /* In this case the image build itself must not be called */
                    if (fl_trans_color_U32 != fl_bmp_data_U16)
                    {
                        if(fl_alpha_U32 == 255UL)
                        {
                            *fl_frame_buff_U16P = fl_bmp_data_U16;
                        }
                        else if ((fl_prev_fg_U16 == fl_bmp_data_U16) && (fl_prev_bg_U16 == *fl_frame_buff_U16P))
                        {
                            *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                        }
                        else
                        {
                            fl_prev_bg_U16 = *fl_frame_buff_U16P;
                            fl_prev_fg_U16 = fl_bmp_data_U16;

                            fl_fgB_U32 = (UINT32)fl_prev_fg_U16;
                            fl_fgG_U32 = (fl_fgB_U32 >> 5); fl_fgR_U32 = (fl_fgG_U32 >> 6);
                            fl_fgB_U32 &= 0x0000001FUL; fl_fgG_U32 &= 0x0000003FUL; fl_fgR_U32 &= 0x0000001FUL;

                            /* Load BG Color */
                            fl_BgB_U32 = (UINT32)fl_prev_bg_U16;
                            fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32 = (fl_BgG_U32 >> 6);
                            fl_BgB_U32 &= 0x0000001FUL; fl_BgG_U32 &= 0x0000003FUL;fl_BgR_U32 &= 0x0000001FUL;

                            /* Blend */
                            fl_fgR_U32   = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                            fl_fgG_U32   = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                            fl_fgB_U32   = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                            fl_prev_blend_U32 = fl_fgB_U32  + (fl_fgG_U32 << 5) + (fl_fgR_U32 << 11);

                            /* Writeback */
                            *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                        }
                    }

                    fl_frame_buff_U16P += 1;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
                    {
                        fl_bmp_data_U16P += 1;
                    }
                }
                fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                if (p_elem_def_SP->comp_size == (UINT32)0)
#endif
                {
                    fl_bmp_data_U16P = fl_bmp_data_U16P + fl_image_width_offs;
                }
            }
        }
        else
        {
            while(0U != fl_image_height)
            {
                fl_image_height--;
                fl_cur_x_size  = fl_image_width;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    fl_data_count_U16 = (UINT16)0;
#endif
                while(0U != fl_cur_x_size)
                {
                    fl_cur_x_size--; 
#if defined GFX_MGR02_COMPRESSION_ENABLED

                    if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                    {
                        if (fl_rle_cur_s.count == (UINT8)0)
                        {
                            GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                        }
                        if (fl_rle_cur_s.count > (UINT8)0) {
                            fl_rle_cur_s.count--;
                        }
                        if (fl_rle_cur_s.flag == (UINT8)FALSE)
                        {
                            fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data++;
                            fl_bmp_data_U16 = fl_bmp_data_U16 << 8U;
                            fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data++));
                        }
                        else
                        {
                            fl_bmp_data_U16 = (UINT16)fl_rle_cur_s.data;
                        }

                        fl_data_count_U16++;
                        if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                        {
                            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                            fl_data_count_U16 = (UINT16)0;
                        }
                    }
                    else
#endif
                    {
                        fl_bmp_data_U16 = *fl_bmp_data_U16P;
                    }

                    /* The layer format is RGB 565 and image format is RGB 565
                       blend forground and back ground if the alpha value is other than 0 and 255 */
                    /* In this case the image build itself must not be called */
                    if(fl_alpha_U32 == 255)
                    {
                        *fl_frame_buff_U16P = fl_bmp_data_U16;
                    }
                    else if((fl_prev_fg_U16 == fl_bmp_data_U16) && (fl_prev_bg_U16 == *fl_frame_buff_U16P))
                    {
                        *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                    }
                    else
                    {
                        fl_prev_bg_U16   = *fl_frame_buff_U16P;
                        fl_prev_fg_U16   = fl_bmp_data_U16;

                        fl_fgB_U32 = (UINT32)fl_prev_fg_U16;
                        fl_fgG_U32 = (fl_fgB_U32 >> 5); fl_fgR_U32 = (fl_fgG_U32 >> 6);
                        fl_fgB_U32 &= 0x0000001FUL; fl_fgG_U32 &= 0x0000003FUL; fl_fgR_U32 &= 0x0000001FUL;

                        /* Load BG Color */
                        fl_BgB_U32 = (UINT32)fl_prev_bg_U16;
                        fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32 = (fl_BgG_U32 >> 6);
                        fl_BgB_U32 &= 0x0000001FUL; fl_BgG_U32 &= 0x0000003FUL;fl_BgR_U32 &= 0x0000001FUL;

                        /* Blend */
                        fl_fgR_U32   = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                        fl_fgG_U32   = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                        fl_fgB_U32   = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                        fl_prev_blend_U32 = fl_fgB_U32  + (fl_fgG_U32 << 5) + (fl_fgR_U32 << 11);

                        /* Writeback */
                        *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                    }
                    fl_frame_buff_U16P+=1;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
                    {
                        fl_bmp_data_U16P += 1;
                    }
                }
                fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                if (p_elem_def_SP->comp_size == (UINT32)0)
#endif 
                {
                    fl_bmp_data_U16P = fl_bmp_data_U16P + fl_image_width_offs;
                }
            }
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_rgb565_ext
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_rgb565_ext(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
    UINT32 fl_temp_bmp_data;
    fl_clip_data_S.x_offset = 0;
    fl_clip_data_S.y_offset = 0;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif
    if ((p_context_SP->state.loc.x < (SINT16)p_context_SP->rprop.fb_w) && (p_context_SP->state.loc.y < (SINT16)p_context_SP->rprop.fb_h))
    {
        if ((p_context_SP->state.loc.x + (SINT16)p_elem_def_SP->width) > (SINT16)p_context_SP->rprop.fb_w)
        {
            SINT16 temp_w = ((p_context_SP->state.loc.x + (SINT16)p_elem_def_SP->width) - (SINT16)p_context_SP->rprop.fb_w);
            fl_clip_data_S.w -= (UINT16)temp_w;
        }
        if ((p_context_SP->state.loc.y + (SINT16)p_elem_def_SP->height) > (SINT16)p_context_SP->rprop.fb_h)
        {
            SINT16 temp_h = ((p_context_SP->state.loc.y + (SINT16)p_elem_def_SP->height) - (SINT16)p_context_SP->rprop.fb_h);
            fl_clip_data_S.h -= (UINT16)temp_h;
        }
        if ((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
        {
            UINT16 const* fl_bmp_data_U16P;
            UINT32* fl_frame_buff_U16P;
            UINT32 red;
            UINT32 green;
            UINT32 blue;
            UINT32 alpha;

            GFX_MGR02_ISIZE_W_T fl_image_width, fl_cur_x_size;
            GFX_MGR02_ISIZE_W_T fl_frame_width_offs, fl_image_width_offs;
            GFX_MGR02_ISIZE_H_T fl_image_height;

            UINT32 fl_prev_bg_U16;
            UINT16 fl_prev_fg_U16;
            UINT32 fl_prev_blend_U32;
            UINT32 fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
            UINT32 fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
            UINT32 fl_alpha_U32;
#if defined GFX_MGR02_COMPRESSION_ENABLED        
            GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
            UINT16        fl_data_count_U16 = (UINT16)0;
#endif
            UINT16 fl_bmp_data_U16;

            fl_alpha_U32 = (UINT32)p_context_SP->state.alpha;

            fl_bmp_data_U16P = p_elem_def_SP->pixel_data;
            fl_frame_buff_U16P = p_context_SP->rprop.fb_P;
#if defined GFX_MGR02_COMPRESSION_ENABLED
            if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
                fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U16P;
                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
            }
            else
#endif
            {
                fl_bmp_data_U16P = &fl_bmp_data_U16P[(fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset];
            }
            fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

            fl_image_width = fl_clip_data_S.w - fl_clip_data_S.x_offset;
            fl_image_height = fl_clip_data_S.h - fl_clip_data_S.y_offset;

            fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
            fl_image_width_offs = p_elem_def_SP->width - fl_image_width;

            fl_prev_bg_U16 = 0; fl_prev_fg_U16 = 0;
            fl_prev_blend_U32 = 0;

            if (p_elem_def_SP->chroma_key == GFX_MGR02_IMAGE_CHROMA_KEY_YES)
            {
                UINT32 fl_trans_color_U32;
                /* Transparent color */
                fl_BgB_U32 = p_elem_def_SP->color; fl_BgG_U32 = (fl_BgB_U32 >> 8); fl_BgR_U32 = (fl_BgG_U32 >> 8);
                fl_BgR_U32 = (((fl_BgR_U32 & 0x000000FFUL) * 31UL) / 255UL);        /* 8 bit to 5 bit */
                fl_BgG_U32 = (((fl_BgG_U32 & 0x000000FFUL) * 63UL) / 255UL);        /* 8 bit to 6 bit */
                fl_BgB_U32 = (((fl_BgB_U32 & 0x000000FFUL) * 31UL) / 255UL);        /* 8 bit to 5 bit */
                fl_trans_color_U32 = fl_BgR_U32 + fl_BgG_U32 + fl_BgB_U32;

                while (0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = fl_image_width;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    fl_data_count_U16 = (UINT16)0;
#endif
                    while (0U != fl_cur_x_size)
                    {
                        fl_cur_x_size--;
#if defined GFX_MGR02_COMPRESSION_ENABLED

                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data++;
                                fl_bmp_data_U16 = fl_bmp_data_U16 << 8U;
                                fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data++));
                            }
                            else
                            {
                                fl_bmp_data_U16 = (UINT16)fl_rle_cur_s.data;
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U16 = *fl_bmp_data_U16P;
                        }
                        /* The layer format is RGB 565 and image format is RGB 565
                           blend forground and back ground if the alpha value is other than 0 and 255 */
                           /* In this case the image build itself must not be called */
                        if (fl_trans_color_U32 != fl_bmp_data_U16)
                        {
                            if (fl_alpha_U32 == 255UL)
                            {
                                *fl_frame_buff_U16P = fl_bmp_data_U16;
                            }
                            else if ((fl_prev_fg_U16 == fl_bmp_data_U16) && (fl_prev_bg_U16 == *fl_frame_buff_U16P))
                            {
                                *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                            }
                            else
                            {
                                fl_prev_bg_U16 = *fl_frame_buff_U16P;
                                fl_prev_fg_U16 = fl_bmp_data_U16;

                                fl_fgB_U32 = (UINT32)fl_prev_fg_U16;
                                fl_fgG_U32 = (fl_fgB_U32 >> 5); fl_fgR_U32 = (fl_fgG_U32 >> 6);
                                fl_fgB_U32 &= 0x0000001FUL; fl_fgG_U32 &= 0x0000003FUL; fl_fgR_U32 &= 0x0000001FUL;

                                /* Load BG Color */
                                fl_BgB_U32 = (UINT32)fl_prev_bg_U16;
                                fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32 = (fl_BgG_U32 >> 6);
                                fl_BgB_U32 &= 0x0000001FUL; fl_BgG_U32 &= 0x0000003FUL; fl_BgR_U32 &= 0x0000001FUL;

                                /* Blend */
                                fl_fgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                                fl_fgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                                fl_fgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                                fl_prev_blend_U32 = fl_fgB_U32 + (fl_fgG_U32 << 5) + (fl_fgR_U32 << 11);

                                /* Writeback */
                                *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                            }
                        }
                        fl_frame_buff_U16P += 1;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
                        {
                            fl_bmp_data_U16P += 1;
                        }
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P + fl_frame_width_offs;
                    fl_bmp_data_U16P = fl_bmp_data_U16P + fl_image_width_offs;
                }
            }
            else
            {
                while (0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = fl_image_width;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    fl_data_count_U16 = (UINT16)0;
#endif
                    while (0U != fl_cur_x_size)
                    {
                        fl_cur_x_size--;
#if defined GFX_MGR02_COMPRESSION_ENABLED

                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data++;
                                fl_bmp_data_U16 = fl_bmp_data_U16 << 8U;
                                fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data++));
                            }
                            else
                            {
                                fl_bmp_data_U16 = (UINT16)fl_rle_cur_s.data;
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U16 = *fl_bmp_data_U16P;
                        }
                        /* The layer format is RGB 565 and image format is RGB 565
                           blend forground and back ground if the alpha value is other than 0 and 255 */
                           /* In this case the image build itself must not be called */
                        if (fl_alpha_U32 == 255UL)
                        {
                            fl_temp_bmp_data = fl_bmp_data_U16;
                            red = ((((fl_temp_bmp_data >> 11) & 0x1FU) * 527U) + 23U) >> 6;
                            green = ((((fl_temp_bmp_data >> 5) & 0x3FU) * 259U) + 33U) >> 6;
                            blue = (((fl_temp_bmp_data & 0x1FU) * 527U) + 23U) >> 6;
                            alpha = 255;

                            *fl_frame_buff_U16P = (alpha << 24) | (red << 16) | (green << 8) | blue;
                        }
                        else if ((fl_prev_fg_U16 == fl_bmp_data_U16) && (fl_prev_bg_U16 == *fl_frame_buff_U16P))
                        {
                            *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                        }
                        else
                        {
                            fl_prev_bg_U16 = *fl_frame_buff_U16P;
                            fl_prev_fg_U16 = fl_bmp_data_U16;

                            fl_fgB_U32 = (UINT32)fl_prev_fg_U16;
                            fl_fgG_U32 = (fl_fgB_U32 >> 5); fl_fgR_U32 = (fl_fgG_U32 >> 6);
                            fl_fgB_U32 &= 0x0000001FUL; fl_fgG_U32 &= 0x0000003FUL; fl_fgR_U32 &= 0x0000001FUL;

                            /* Load BG Color */
                            fl_BgB_U32 = (UINT32)fl_prev_bg_U16;
                            fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32 = (fl_BgG_U32 >> 6);
                            fl_BgB_U32 &= 0x0000001FUL; fl_BgG_U32 &= 0x0000003FUL; fl_BgR_U32 &= 0x0000001FUL;

                            /* Blend */
                            fl_fgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                            fl_fgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                            fl_fgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                            fl_prev_blend_U32 = fl_fgB_U32 + (fl_fgG_U32 << 5) + (fl_fgR_U32 << 11);

                            /* Writeback */
                          //  *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                            fl_temp_bmp_data = (UINT16)fl_prev_blend_U32;
                            red = ((((fl_temp_bmp_data >> 11U) & 0x1FU) * 527U) + 23U) >> 6;
                            green = ((((fl_temp_bmp_data >> 5U) & 0x3FU) * 259U) + 33U) >> 6;
                            blue = (((fl_temp_bmp_data & 0x1FU) * 527U) + 23U) >> 6;
                            alpha = 0xFF;

                            *fl_frame_buff_U16P = (alpha << 24) | (red << 16) | (green << 8) | blue;

                        }

                        fl_frame_buff_U16P += 1;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
                        {
                            fl_bmp_data_U16P += 1;
                        }
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P + fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
                    {
                        fl_bmp_data_U16P = fl_bmp_data_U16P + fl_image_width_offs;
                    }
                }
            }
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_argb8888_ext
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_argb8888_ext(GFX_MGR02_CONTEXT_T const* p_context_SP, GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP, &fl_clip_data_S);
#endif
    if ((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT32* fl_frame_buff_U32P;
        UINT32  const* fl_bmp_data_U32P;

        UINT32 fl_global_alpha_U32, fl_alpha_U32;
        UINT32 fl_bmp_data_U32;
        UINT32 fl_prev_dst_p = 0UL, fl_prev_src_p = 0UL, fl_prev_blend_p = 0UL;
        
        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;
        
#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = 0;
#endif

        fl_frame_buff_U32P = (UINT32*)p_context_SP->rprop.fb_P;
        fl_frame_buff_U32P = fl_frame_buff_U32P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

        fl_bmp_data_U32P = (UINT32 const*)p_elem_def_SP->pixel_data;
#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
        {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U32P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
        }
        else
#endif
        {
            fl_bmp_data_U32P = fl_bmp_data_U32P + ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset);
        }
        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;

        fl_image_width = fl_clip_data_S.w - fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h - fl_clip_data_S.y_offset;
        fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs = p_elem_def_SP->width - fl_image_width;

        while (0U != fl_image_height)
        {
            fl_image_height--;
            fl_cur_x_size = fl_image_width;
#if defined GFX_MGR02_COMPRESSION_ENABLED
            fl_data_count_U16 = (UINT16)0;
#endif
            while (0U != fl_cur_x_size)
            {
#if defined GFX_MGR02_COMPRESSION_ENABLED
                if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                {
                    if (fl_rle_cur_s.count == (UINT8)0)
                    {
                        GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                    }
                    if (fl_rle_cur_s.count > (UINT8)0)
                    {
                        fl_rle_cur_s.count--;
                    }
                    if (fl_rle_cur_s.flag == FALSE)
                    {
                        fl_bmp_data_U32 = *fl_rle_cur_s.bmp_data++;
                        fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                        fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data++));
                        fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                        fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data++));
                        fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                        fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data++));
                    }
                    else
                    {
                        fl_bmp_data_U32 = fl_rle_cur_s.data;
                    }

                    fl_data_count_U16++;
                    if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                    {
                        GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                        fl_data_count_U16 = (UINT16)0;
                    }
                    fl_alpha_U32 = (UINT32)((fl_bmp_data_U32 >> 24u) & 0x000000FFu);
                }
                else
#endif
                {
                    fl_bmp_data_U32 = *fl_bmp_data_U32P;
                    fl_alpha_U32 = (UINT32)((fl_bmp_data_U32 >> 24U) & 0x000000FFUL);
                }
                
                fl_alpha_U32 = (fl_global_alpha_U32 * fl_alpha_U32 ) / 255UL;
                if (fl_alpha_U32 != 0UL)
                {
                    if ((*fl_frame_buff_U32P == fl_prev_dst_p) && (fl_bmp_data_U32 == fl_prev_src_p))
                    {
                        *fl_frame_buff_U32P = fl_prev_blend_p;    
                    }
                    else
                    {
                        fl_prev_dst_p = *fl_frame_buff_U32P;
                        fl_prev_src_p = fl_bmp_data_U32;
                        
                        if (255UL == fl_alpha_U32)
                        {
                            *fl_frame_buff_U32P = (fl_bmp_data_U32);
                        }
                        else
                        {
                            
                            hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_alpha_U32, fl_bmp_data_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                        }
                        
                        fl_prev_blend_p = *fl_frame_buff_U32P;
                        
                    }
                }
                
                fl_cur_x_size--;
                fl_frame_buff_U32P += 1;
                #if defined GFX_MGR02_COMPRESSION_ENABLED   
                if (p_elem_def_SP->comp_size == (UINT32)0)
                #endif      
                {
                    fl_bmp_data_U32P += 1;
                }
            }
            fl_frame_buff_U32P = fl_frame_buff_U32P + fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
            if (p_elem_def_SP->comp_size == (UINT32)0)
#endif      
            {
                fl_bmp_data_U32P = fl_bmp_data_U32P + fl_image_width_offs;
            }
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_argb8888_optimized
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_argb8888_optimized(GFX_MGR02_CONTEXT_T const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT32  *fl_frame_buff_U16P;
        UINT32  const * fl_bmp_data_U16P;
        
        UINT32  fl_global_alpha_U32, fl_alpha_U32;
        UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32  fl_load_color_U32;

        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

        fl_frame_buff_U16P   = p_context_SP->rprop.fb_P;
        fl_frame_buff_U16P   = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

        fl_bmp_data_U16P     = p_elem_def_SP->pixel_data;
        fl_bmp_data_U16P     = fl_bmp_data_U16P + ((fl_clip_data_S.y_offset * p_elem_def_SP->width)+fl_clip_data_S.x_offset);

        fl_global_alpha_U32  = (UINT32)p_context_SP->state.alpha;

        fl_image_width       = fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height      = fl_clip_data_S.h-fl_clip_data_S.y_offset;
        fl_frame_width_offs  = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs  = p_elem_def_SP->width - fl_image_width;

        while(0U != fl_image_height)
        {
            fl_image_height--;
            fl_cur_x_size = fl_image_width;
            while(0U != fl_cur_x_size)
            {
                fl_cur_x_size--;
                fl_load_color_U32 = ((UINT32)*fl_bmp_data_U16P) & 0x00FFFFFFUL;

                fl_alpha_U32 = (UINT32) (((*fl_bmp_data_U16P)>>24) & 0x000000FFUL);

                fl_alpha_U32 = (fl_global_alpha_U32 * fl_alpha_U32)/255UL;
                /* (fl_alpha_32 * 255/15 *fl_global_alpha_U32/255 */

                if(fl_alpha_U32!=0UL)
                {
                    if(255UL==fl_alpha_U32)
                    {
                        fl_load_color_U32 = fl_load_color_U32 + 0xFF000000UL;
                    }
                    else
                    {
                        fl_alpha_U32 = ((((UINT32)(((*fl_frame_buff_U16P) & 0xFF000000UL) >> 24)) * fl_alpha_U32)/255UL);

                        fl_fgR_U32 = (fl_load_color_U32>>16) & 0x000000FFUL;
                        fl_fgG_U32 = (fl_load_color_U32>>8) & 0x000000FFUL;
                        fl_fgB_U32 = (fl_load_color_U32 & 0x000000FFUL);

                        fl_BgR_U32 = (UINT32)*fl_frame_buff_U16P;
                        fl_BgG_U32 = (fl_BgR_U32>>8);

                        fl_BgB_U32 = (fl_BgR_U32 & 0x000000FFUL);
                        fl_BgR_U32 = (fl_BgG_U32>>8) & 0x000000FFUL;
                        fl_BgG_U32 = fl_BgG_U32 & 0x000000FFUL;

                        fl_fgR_U32 = (fl_BgR_U32 + fl_fgR_U32)/2UL;
                        fl_fgG_U32 = (fl_BgG_U32 + fl_fgG_U32)/2UL;
                        fl_fgB_U32 = (fl_BgB_U32 + fl_fgB_U32)/2UL;

                        fl_fgR_U32 = (fl_alpha_U32*fl_fgR_U32)/255UL;
                        fl_fgG_U32 = (fl_alpha_U32*fl_fgG_U32)/255UL;
                        fl_fgB_U32 = (fl_alpha_U32*fl_fgB_U32)/255UL;
                        fl_load_color_U32 = (fl_fgR_U32<<16) | (fl_fgG_U32<<8) | fl_fgB_U32 | (fl_alpha_U32<<24);
                    }
                    *fl_frame_buff_U16P = (UINT16)fl_load_color_U32;
                }

                fl_frame_buff_U16P+=1;
                fl_bmp_data_U16P+=1;
            }
            fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
            fl_bmp_data_U16P = fl_bmp_data_U16P+fl_image_width_offs;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_32bpp
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_32bpp(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif
    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT8  fl_alpha_flag_U8;

        UINT16  const *fl_bmp_data_U16P;
        UINT16  *fl_frame_buff_U16P;
        UINT16  const *fl_alpha_data_U16P;
        UINT16  fl_prev_bg_U16, fl_prev_fg_U16;

        UINT32  fl_alpha_U32, fl_prev_alpha_U32, fl_prev_blend_U32;
        UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32  fl_global_alpha_U32;

        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size, fl_new_width_offs;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

        fl_frame_buff_U16P = p_context_SP->rprop.fb_P;
        fl_bmp_data_U16P = p_elem_def_SP->pixel_data;
        fl_alpha_data_U16P = &fl_bmp_data_U16P[(p_elem_def_SP->width * p_elem_def_SP->height)];

        fl_frame_buff_U16P = fl_frame_buff_U16P+((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w)+(fl_clip_data_S.x));
        fl_bmp_data_U16P = &fl_bmp_data_U16P[((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset)];
        fl_alpha_data_U16P = &fl_alpha_data_U16P[((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset)/2U];

        fl_image_width=fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height=fl_clip_data_S.h-fl_clip_data_S.y_offset;
        fl_alpha_flag_U8 = (((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset) % 2U);

        fl_prev_bg_U16 = 0; fl_prev_fg_U16 = 0; 
        fl_prev_alpha_U32 = 0; fl_prev_blend_U32 = 0;

        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;

        fl_frame_width_offs=p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs=p_elem_def_SP->width - fl_image_width;

        while( 0U != fl_image_height)
        {
            fl_image_height--;
            fl_cur_x_size = fl_image_width;
            while( 0U != fl_cur_x_size)
            {
                fl_cur_x_size--;
                /* The layer format is RGB 565 and image format is rgb 565. Alpha
                blend forground and back ground if the alpha value is other than 0 and 255 */
                if(fl_alpha_flag_U8 == 0U)
                {
                    fl_alpha_U32 = ((UINT32)(*fl_alpha_data_U16P) >> 8);
                    fl_alpha_flag_U8 = 1;
                }
                else
                {
                    fl_alpha_U32 = (UINT32)(*fl_alpha_data_U16P);
                    fl_alpha_flag_U8 = 0;
                    fl_alpha_data_U16P +=1;
                }

                fl_alpha_U32 = (0x000000FFUL & fl_alpha_U32);
                fl_alpha_U32 = ((fl_global_alpha_U32 * fl_alpha_U32)/255UL);

                if(fl_alpha_U32 != (UINT32)0) /* In this case the image build itself must not be called */
                {
                    if(fl_alpha_U32 == (UINT32)255)
                    {
                        *fl_frame_buff_U16P = *fl_bmp_data_U16P;
                    }
                    else if((fl_prev_fg_U16 == *fl_bmp_data_U16P) && (fl_prev_bg_U16 == *fl_frame_buff_U16P)&&(fl_alpha_U32==fl_prev_alpha_U32))
                    {
                        *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                    }
                    else
                    {   
                        fl_prev_bg_U16 = *fl_frame_buff_U16P; fl_prev_fg_U16 = *fl_bmp_data_U16P; 
                        fl_prev_alpha_U32 = fl_alpha_U32;
        
                        fl_fgB_U32 = (UINT32)fl_prev_fg_U16;
                        fl_fgG_U32 = (fl_fgB_U32 >> 5); fl_fgR_U32 = (fl_fgG_U32 >> 6);
                        fl_fgB_U32 &= 0x0000001FUL; fl_fgG_U32  &= 0x0000003FUL; fl_fgR_U32  &= 0x0000001FUL;
                    
                        /* Load BG Color */
                        fl_BgB_U32   = (UINT32)fl_prev_bg_U16; 
                        fl_BgG_U32   = (fl_BgB_U32 >> 5); fl_BgR_U32   = (fl_BgG_U32 >> 6);
                        fl_BgB_U32  &= 0x0000001FUL; fl_BgG_U32  &= 0x0000003FUL; fl_BgR_U32  &= 0x0000001FUL;
                    
                        /* Blend */
                        fl_fgR_U32   = (((fl_BgR_U32 << 8) + (fl_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                        fl_fgG_U32   = (((fl_BgG_U32 << 8) + (fl_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                        fl_fgB_U32   = (((fl_BgB_U32 << 8) + (fl_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                        fl_prev_blend_U32 = fl_fgB_U32  + (fl_fgG_U32 << 5) + (fl_fgR_U32 << 11);

                        /* Writeback */
                        *fl_frame_buff_U16P = (UINT16)fl_prev_blend_U32;
                    }
                }
                fl_bmp_data_U16P+=1;
                fl_frame_buff_U16P+=1;
            }
            fl_frame_buff_U16P += fl_frame_width_offs;
            fl_bmp_data_U16P += fl_image_width_offs;

            fl_new_width_offs=hmi_gfx_mgr02_swrlib_next_loc(&fl_alpha_flag_U8, fl_image_width_offs);
            fl_alpha_data_U16P+=(UINT16)fl_new_width_offs;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_a8_image
Description          : Performs the A8 (alpha mask) image building with opaque bg color
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_a8_image(GFX_MGR02_CONTEXT_T const * p_context_SP, GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA fl_clip_data_S;
    
    fl_clip_data_S.x = p_context_SP->state.loc.x; 
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width; 
    fl_clip_data_S.h = p_elem_def_SP->height;

#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif

    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT8 *fl_bmp_data_U8P;
        UINT8 fl_bmp_data_U8;
        UINT16 fl_load_color_U16, fl_fg_color_U16, fl_load_trans_color_U16;
        UINT32 fl_global_alpha_U32, fl_src_alpha_U32, fl_prev_alpha1_U32;
        UINT32 fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32 fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32 fl_fg_color_U32 = p_context_SP->rprop.fg_color;
        UINT32 fl_bg_color_U32 = p_elem_def_SP->color;

        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        
        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;
        fl_bmp_data_U8P     = (UINT8*)p_elem_def_SP->pixel_data;

#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U8P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
        }
        else
#endif
        {
            fl_bmp_data_U8P = fl_bmp_data_U8P + ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset);
        }

        fl_image_width  = fl_clip_data_S.w - fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h - fl_clip_data_S.y_offset;

        fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs = p_elem_def_SP->width - fl_image_width;

        fl_prev_alpha1_U32 = 0;

        switch (p_context_SP->rprop.fb_format)
        {
            case GFX_MGR02_PIX_FORMAT_RGB565:
            {
                UINT16 * fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                /* Transparent color */
                fl_BgB_U32 = p_elem_def_SP->color; fl_BgG_U32 = (fl_BgB_U32 >> 8); fl_BgR_U32 = (fl_BgG_U32 >> 8);

                fl_fgB_U32 = (fl_fg_color_U32 & 0x000000FFUL);
                fl_fgG_U32 = ((fl_fg_color_U32 & 0x0000FF00UL) >> 8U);
                fl_fgR_U32 = ((fl_fg_color_U32 & 0x00FF0000UL) >> 16U);

                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
                fl_fg_color_U16 = (UINT16)((fl_fgR_U32 << 11) | (fl_fgG_U32 << 5) | fl_fgB_U32);

                /* Transparent color */
                fl_BgR_U32   = (((fl_BgR_U32 & 0x000000FFUL) * 31)/255);        /* 8 bit to 5 bit */
                fl_BgG_U32   = (((fl_BgG_U32 & 0x000000FFUL) * 63)/255);        /* 8 bit to 6 bit */
                fl_BgB_U32   = (((fl_BgB_U32 & 0x000000FFUL) * 31)/255);        /* 8 bit to 5 bit */ 
                fl_load_trans_color_U16 = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11));

                while(0U != fl_image_height)
                {
                    fl_image_height--; fl_cur_x_size = 0U;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }
                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8; 
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }
                        fl_src_alpha_U32 = (fl_global_alpha_U32 * fl_src_alpha_U32)/255UL;

                        if(0UL == fl_src_alpha_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_trans_color_U16;
                        }
                        else if(255UL == fl_src_alpha_U32)
                        {
                            *fl_frame_buff_U16P = fl_fg_color_U16;
                        }
                        else if(fl_prev_alpha1_U32 == fl_src_alpha_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_color_U16;
                        }
                        else 
                        {
                            UINT32  fl_r_BgR_U32, fl_r_BgG_U32, fl_r_BgB_U32;
                            fl_prev_alpha1_U32=fl_src_alpha_U32;

                            /* Blend */
                            fl_r_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_src_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                            fl_r_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_src_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                            fl_r_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_src_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);

                            /* Writeback */
                            fl_load_color_U16 = (UINT16)(fl_r_BgB_U32  + (fl_r_BgG_U32 << 5) + (fl_r_BgR_U32 << 11));
                            *fl_frame_buff_U16P = fl_load_color_U16;
                        }
                        fl_frame_buff_U16P+=1; fl_cur_x_size++;
                    }

                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                    
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
            }
            break;
            case GFX_MGR02_PIX_FORMAT_ARGB4444:
            {
                UINT16 fl_blend_color_U16;
                UINT16* fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                /* Transparent color */
                fl_BgB_U32 = p_elem_def_SP->color; fl_BgG_U32 = (fl_BgB_U32 >> 8); fl_BgR_U32 = (fl_BgG_U32 >> 8);
                
                fl_fgB_U32 = (fl_fg_color_U32 & 0x000000FFUL);
                fl_fgG_U32 = ((fl_fg_color_U32 & 0x0000FF00UL) >> 8U);
                fl_fgR_U32 = ((fl_fg_color_U32 & 0x00FF0000UL) >> 16U);

                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */ 
                fl_fg_color_U16 = (UINT16)(0x0000F000UL | ((fl_fgR_U32 << 8) | (fl_fgG_U32 << 4) | fl_fgB_U32));

                /* Transparent color */
                fl_BgR_U32   = (((fl_BgR_U32 & 0x000000FFUL) * 15)/255);        /* 8 bit to 4 bit */
                fl_BgG_U32   = (((fl_BgG_U32 & 0x000000FFUL) * 15)/255);        /* 8 bit to 4 bit */
                fl_BgB_U32   = (((fl_BgB_U32 & 0x000000FFUL) * 15)/255);        /* 8 bit to 4 bit */ 
                fl_load_trans_color_U16 = (UINT16)(0x0000F000UL | fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));

                /* Blend */
                fl_BgR_U32 = (fl_fgR_U32+fl_BgR_U32)/2UL;
                fl_BgG_U32 = (fl_fgG_U32+fl_BgG_U32)/2UL;
                fl_BgB_U32 = (fl_fgB_U32+fl_BgB_U32)/2UL;
                fl_blend_color_U16 = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));

                while(0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = 0U;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8; /* image format is 8 bpp */
                        fl_src_alpha_U32 = (fl_global_alpha_U32 * fl_src_alpha_U32)/(255UL*17UL);
                        /* ((fl_alpha1_32  * fl_global_alpha_U32 /255)*15/255) */

                        if(0UL == fl_src_alpha_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_trans_color_U16;
                        }
                        else if(15UL == fl_src_alpha_U32)
                        {
                            *fl_frame_buff_U16P = fl_fg_color_U16;
                        }
                        else
                        {
                            UINT32 fl_frame_alpha_U32;
                            fl_frame_alpha_U32 = (((UINT32)(*fl_frame_buff_U16P) & 0x0000F000UL) >> 12U);
                            
                            if(0UL != fl_frame_alpha_U32)
                            {
                                fl_src_alpha_U32 = (fl_src_alpha_U32 * fl_frame_alpha_U32)/15UL;
                            }
                            *fl_frame_buff_U16P =((UINT16)(fl_src_alpha_U32<<12)) | fl_blend_color_U16;
                        }
                        fl_frame_buff_U16P+=1;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }
                        
                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
            }
            break;
            case GFX_MGR02_PIX_FORMAT_ARGB8888:
            {
                UINT32 fl_prev_dst_p = 0UL, fl_prev_src_a = 0UL, fl_prev_blend_p = 0UL;
                UINT32 *fl_frame_buff_U32P = (UINT32*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U32P = fl_frame_buff_U32P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                while (0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = 0U;
                    while (fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8;

                        if ((fl_cur_x_size > 0U) && (*fl_frame_buff_U32P == fl_prev_dst_p) && (fl_src_alpha_U32 == fl_prev_src_a))
                        {
                            *fl_frame_buff_U32P = fl_prev_blend_p;
                        }
                        else 
                        {
                            fl_prev_dst_p = *fl_frame_buff_U32P;
                            fl_prev_src_a = fl_src_alpha_U32;
                            
                            if (0U == fl_src_alpha_U32)
                            {
                                if (255U == fl_global_alpha_U32)
                                {
                                    *fl_frame_buff_U32P = fl_bg_color_U32;
                                }
                                else
                                {
                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_global_alpha_U32, fl_bg_color_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                }
                            }
                            else if (255U == fl_src_alpha_U32)
                            {
                                if (255U == fl_global_alpha_U32)
                                {
                                    *fl_frame_buff_U32P = fl_fg_color_U32;
                                }
                                else
                                {
                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_global_alpha_U32, fl_fg_color_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                }
                            }
                            else
                            {
                                UINT32 fl_blended_result_U32 = fl_bg_color_U32;
                                hmi_gfx_mgr02_swrlib_blend_operation((void*)(&fl_blended_result_U32), (UINT8)fl_src_alpha_U32, fl_fg_color_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                            
                                if (255U == fl_global_alpha_U32)
                                {
                                    *fl_frame_buff_U32P = fl_blended_result_U32;
                                }
                                else
                                {
                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_global_alpha_U32, fl_blended_result_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                }
                            }
                            fl_prev_blend_p = *fl_frame_buff_U32P;
                        }

                        fl_frame_buff_U32P += 1;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }

                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U32P = fl_frame_buff_U32P + fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
            }
            break;
            default:
            {
                /* Comment added to fix MISRA warning */
            }
            break;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_a8_trans_image
Description          : Performs the A8 (alpha mask) image building with transparent bg color
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_a8_trans_image(GFX_MGR02_CONTEXT_T const * p_context_SP, GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x; 
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width; 
    fl_clip_data_S.h = p_elem_def_SP->height;

#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP, &fl_clip_data_S);
#endif

    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT8 *fl_bmp_data_U8P;
        UINT8 fl_bmp_data_U8;
        UINT16 fl_fg_color_U16;
        UINT32 fl_global_alpha_U32, fl_src_alpha_U32;
        UINT32 fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32 fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32 fl_fg_color_U32 = p_context_SP->rprop.fg_color;

        GFX_MGR02_ISIZE_W_T fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T fl_image_height;

#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        
        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;
        fl_bmp_data_U8P     = (UINT8*)p_elem_def_SP->pixel_data;

#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U8P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
        }
        else
#endif
        {
            fl_bmp_data_U8P = fl_bmp_data_U8P + ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset);
        }
        
        /* Draw color */
        fl_fgB_U32 = (fl_fg_color_U32 & 0x000000FFUL);
        fl_fgG_U32 = ((fl_fg_color_U32 & 0x0000FF00UL) >> 8U);
        fl_fgR_U32 = ((fl_fg_color_U32 & 0x00FF0000UL) >> 16U);

        fl_image_width  = fl_clip_data_S.w - fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h - fl_clip_data_S.y_offset;

        fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs = p_elem_def_SP->width - fl_image_width;

        switch (p_context_SP->rprop.fb_format)
        {
            case GFX_MGR02_PIX_FORMAT_RGB565:
            {
                UINT16* fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
                fl_fg_color_U16 = (UINT16)((fl_fgR_U32 << 11) | (fl_fgG_U32<<5) | fl_fgB_U32);

                while(0U != fl_image_height)
                {
                    fl_image_height--; 
                    fl_cur_x_size = 0U;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8; 
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }
                        fl_src_alpha_U32 = (fl_global_alpha_U32 * fl_src_alpha_U32)/255UL;

                        if(0UL != fl_src_alpha_U32)
                        {
                            if(255UL == fl_src_alpha_U32)
                            {
                                *fl_frame_buff_U16P = fl_fg_color_U16;
                            }
                            else 
                            {
                                fl_BgB_U32=*fl_frame_buff_U16P;
                                fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32   = (fl_BgG_U32 >> 6);

                                fl_BgB_U32 &= 0x0000001FU; fl_BgG_U32 &= 0x0000003FU; fl_BgR_U32 &= 0x0000001FU;

                                /* Blend */
                                fl_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_src_alpha_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                                fl_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_src_alpha_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                                fl_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_src_alpha_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);

                                /* Writeback */
                                *fl_frame_buff_U16P = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11));
                            }
                        }
                        fl_frame_buff_U16P+=1; fl_cur_x_size++;
                    }

                    fl_frame_buff_U16P +=(UINT16)fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                    
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
            }
            break;
            case GFX_MGR02_PIX_FORMAT_ARGB4444:
            {
                UINT16* fl_frame_buff_U16P = (UINT16*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U16P = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */ 
                fl_fg_color_U16 = (UINT16)(0x0000F000UL | ((fl_fgR_U32 << 8) | (fl_fgG_U32<<4) | fl_fgB_U32));

                while(0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = 0U;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8; /* image format is 8 bpp */
                        fl_src_alpha_U32 = (fl_global_alpha_U32 * fl_src_alpha_U32)/(255UL*17UL);
                        /* ((fl_alpha1_32  * fl_global_alpha_U32 /255)*15/255) */
                        if(0UL != fl_src_alpha_U32)
                        {
                            if(15UL == fl_src_alpha_U32)
                            {
                                *fl_frame_buff_U16P = fl_fg_color_U16;
                            }
                            else
                            {
                                UINT32 fl_frame_alpha_U32;
                                fl_frame_alpha_U32 = (((UINT32)(*fl_frame_buff_U16P) & 0x0000F000UL) >> 12U);
                                if(0UL != fl_frame_alpha_U32)
                                {
                                    fl_src_alpha_U32 = (fl_src_alpha_U32 * fl_frame_alpha_U32)/15UL;
                                }
                                fl_BgB_U32 = (UINT32) *fl_frame_buff_U16P;
                                fl_BgG_U32 = (fl_BgB_U32 >> 4); fl_BgR_U32 = (fl_BgG_U32 >> 4);
                                fl_BgB_U32 &= 0x0000000FUL; fl_BgG_U32 &= 0x0000000FUL; fl_BgR_U32 &= 0x0000000FUL;

                                /* Blend */
                                fl_BgR_U32 = (fl_fgR_U32+fl_BgR_U32)/2UL;
                                fl_BgG_U32 = (fl_fgG_U32+fl_BgG_U32)/2UL;
                                fl_BgB_U32 = (fl_fgB_U32+fl_BgB_U32)/2UL;
                                *fl_frame_buff_U16P = (UINT16)((fl_src_alpha_U32 << 12) | fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));
                            }
                        }
                        fl_frame_buff_U16P+=1;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }
                        
                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
            }
            break;
            case GFX_MGR02_PIX_FORMAT_ARGB8888:
            {
                UINT32 fl_prev_dst_p = 0UL, fl_prev_src_a = 0UL, fl_prev_blend_p = 0UL;
                UINT32* fl_frame_buff_U32P = (UINT32*)p_context_SP->rprop.fb_P;
                fl_frame_buff_U32P = fl_frame_buff_U32P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w) + fl_clip_data_S.x);

                while (0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size = 0U;
                    while (fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        fl_src_alpha_U32 = (UINT32)fl_bmp_data_U8;
                        fl_src_alpha_U32 = (fl_global_alpha_U32 * fl_src_alpha_U32) / 255UL;
                        
                        if (0U != fl_src_alpha_U32)
                        {
                            if ((*fl_frame_buff_U32P == fl_prev_dst_p) && (fl_src_alpha_U32 == fl_prev_src_a))
                            {
                                *fl_frame_buff_U32P = fl_prev_blend_p;
                            }
                            else
                            {
                                fl_prev_dst_p = *fl_frame_buff_U32P;
                                fl_prev_src_a = fl_src_alpha_U32;
                                
                                if (255U == fl_src_alpha_U32)
                                {
                                    *fl_frame_buff_U32P = fl_fg_color_U32;
                                }
                                else
                                {
                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_frame_buff_U32P, (UINT8)fl_src_alpha_U32, fl_fg_color_U32, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                }
                                
                                fl_prev_blend_p = *fl_frame_buff_U32P;
                            }
                        }

                        fl_frame_buff_U32P += 1;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                        if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                        {
                            fl_bmp_data_U8P += 1;
                        }

                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U32P = fl_frame_buff_U32P + fl_frame_width_offs;
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif
                    {
                        fl_bmp_data_U8P += (UINT8)fl_image_width_offs;
                    }
                }
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

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_a4_image
Description          : Performs the alpha 4 image building with out bg color.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_a4_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x; fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width; fl_clip_data_S.h = p_elem_def_SP->height;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif

    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT8   *fl_bmp_data_U8P, fl_nibble;
        UINT16  *fl_frame_buff_U16P;
        UINT16  fl_load_color_U16, fl_load_trans_color_U16, fl_fg_color_U16;
        UINT32  fl_global_alpha_U32, fl_alpha1_U32, fl_prev_alpha1_U32;
        UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32  fl_r_BgR_U32, fl_r_BgG_U32, fl_r_BgB_U32;
        UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        
        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size, fl_new_width_offs;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        UINT8 fl_bmp_data_U8;
        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;
        fl_frame_buff_U16P  = p_context_SP->rprop.fb_P;
        fl_frame_buff_U16P  = fl_frame_buff_U16P + ((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w)+fl_clip_data_S.x);
        fl_bmp_data_U8P     = (UINT8 *)p_elem_def_SP->pixel_data;
#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U8P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset)/2u);
        }
        else
#endif
        {
            fl_bmp_data_U8P = fl_bmp_data_U8P+(((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset)/2u);
        }
        fl_nibble = (UINT8)(((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset)%2u);

        /* Draw color */
        fl_fgB_U32 = p_context_SP->rprop.fg_color; fl_fgG_U32 = (fl_fgB_U32 >> 8); fl_fgR_U32 = (fl_fgG_U32 >> 8);
        /* Transparent color */
        fl_BgB_U32 = p_elem_def_SP->color; fl_BgG_U32 = (fl_BgB_U32 >> 8); fl_BgR_U32 = (fl_BgG_U32 >> 8);

        fl_image_width  = fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h-fl_clip_data_S.y_offset;
        fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs = p_elem_def_SP->width - fl_image_width;

        fl_prev_alpha1_U32=0; fl_load_color_U16=0;

        switch (p_context_SP->rprop.fb_format)
        {
            case GFX_MGR02_PIX_FORMAT_RGB565:
            {
                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
                fl_fg_color_U16 = (UINT16)((fl_fgR_U32 << 11) | (fl_fgG_U32 << 5) | fl_fgB_U32);

                /* Transparent color */
                fl_BgR_U32   = (((fl_BgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
                fl_BgG_U32   = (((fl_BgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
                fl_BgB_U32   = (((fl_BgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
                fl_load_trans_color_U16 = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11));

                while(0U != fl_image_height)
                {
                    fl_image_height--; fl_cur_x_size = 0;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width)/2u);
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }
                        if(0U != fl_nibble)
                        {
                          fl_alpha1_U32 = (0x0000000FUL & ((UINT32)fl_bmp_data_U8 >> 4U));
                          #if defined GFX_MGR02_COMPRESSION_ENABLED
                          if (p_elem_def_SP->comp_size == (UINT32)0)
                          #endif
                          {
                              fl_bmp_data_U8P++;
                          }
                          fl_nibble = 0;
                        }
                        else
                        {
                          fl_alpha1_U32 = (0x0000000FUL & (UINT32)fl_bmp_data_U8); /* Lower nibble */
                          fl_nibble=1;
                        }
                        fl_alpha1_U32 = (fl_global_alpha_U32 * fl_alpha1_U32)/15UL;
                        /* (fl_alpha1_32 * 255/15) *fl_global_alpha_U32/255 */

                        if(0UL == fl_alpha1_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_trans_color_U16;
                        }
                        if(255UL == fl_alpha1_U32)
                        {
                            *fl_frame_buff_U16P = fl_fg_color_U16;
                        }
                        else if(fl_prev_alpha1_U32 == fl_alpha1_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_color_U16;
                        }
                        else 
                        {
                            fl_prev_alpha1_U32=fl_alpha1_U32;

                            /* Blend */
                            fl_r_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha1_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                            fl_r_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha1_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                            fl_r_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha1_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                            fl_load_color_U16 = (UINT16)(fl_r_BgB_U32 | (fl_r_BgG_U32 << 5) | (fl_r_BgR_U32 << 11));

                            /* Writeback */
                            *fl_frame_buff_U16P = (UINT16)fl_load_color_U16;

                        }
                        fl_frame_buff_U16P+=1; fl_cur_x_size++;
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P + fl_frame_width_offs;
                    fl_new_width_offs=hmi_gfx_mgr02_swrlib_next_loc(&fl_nibble, fl_image_width_offs);
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                    
                    {
                        fl_bmp_data_U8P+=(UINT8)fl_new_width_offs;
                    }
                }
            }
            break;

            case GFX_MGR02_PIX_FORMAT_ARGB4444:
            {
                UINT16 fl_blend_color_U16;
                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */ 
                fl_fg_color_U16 = (UINT16)(0x0000F000UL | ((fl_fgR_U32 << 8) | (fl_fgG_U32<<4) | fl_fgB_U32));

                /* Transparent color */
                fl_BgR_U32   = (((fl_BgR_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_BgG_U32   = (((fl_BgG_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_BgB_U32   = (((fl_BgB_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */ 
                fl_load_trans_color_U16 = (UINT16)(0x0000F000UL | ((fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32<<8))));

                /* Blend */
                fl_BgR_U32 = (fl_fgR_U32+fl_BgR_U32)/2UL;
                fl_BgG_U32 = (fl_fgG_U32+fl_BgG_U32)/2UL;
                fl_BgB_U32 = (fl_fgB_U32+fl_BgB_U32)/2UL;
                fl_blend_color_U16 = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));

                while( 0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size=0;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width)/2u);
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }

                        if(0U !=fl_nibble)
                        {
                            fl_alpha1_U32 = (UINT32)(0x0000000FUL & (UINT32)(fl_bmp_data_U8>>4u));
                            #if defined GFX_MGR02_COMPRESSION_ENABLED
                            if (p_elem_def_SP->comp_size == (UINT32)0)
                            #endif
                            {
                                fl_bmp_data_U8P++;
                            }
                            fl_nibble=0;
                        }
                        else
                        {
                            fl_alpha1_U32 = (UINT32)(0x0000000FUL & (UINT32)(fl_bmp_data_U8)); /* Lower nibble */
                            fl_nibble=1;
                        }
                        fl_alpha1_U32 = (fl_global_alpha_U32 * fl_alpha1_U32)/255UL;
                        /* (fl_alpha1_32 ) * (fl_global_alpha_U32 * 15/255)/15 */

                        if(0UL == fl_alpha1_U32)
                        {
                            *fl_frame_buff_U16P = fl_load_trans_color_U16;
                        }
                        else if(15UL == fl_alpha1_U32)
                        {
                            *fl_frame_buff_U16P = fl_fg_color_U16;
                        }
                        else
                        {
                            UINT32 fl_frame_alpha_U32;
                            fl_frame_alpha_U32 = (((UINT32)*fl_frame_buff_U16P & 0x0000F000UL)>>12);
                            
                            if(0UL != fl_frame_alpha_U32)
                            {
                                fl_alpha1_U32 = (fl_alpha1_U32 * fl_frame_alpha_U32)/15UL;
                            }
                            *fl_frame_buff_U16P =((UINT16)(fl_alpha1_U32<<12)) | fl_blend_color_U16;
                        }
                        fl_frame_buff_U16P+=1;
                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
                    fl_new_width_offs=hmi_gfx_mgr02_swrlib_next_loc(&fl_nibble, fl_image_width_offs);
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                    {
                        fl_bmp_data_U8P+=(UINT8)fl_new_width_offs;
                    }
                }
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

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_a4_trans_image
Description          : Performs the image building with chroma color and alpha 4.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_a4_trans_image(GFX_MGR02_CONTEXT_T   const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x; fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width; fl_clip_data_S.h = p_elem_def_SP->height;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif
    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT8   *fl_bmp_data_U8P, fl_nibble;
        UINT16  *fl_frame_buff_U16P;
        UINT16  fl_fg_color_U16;
        UINT32  fl_global_alpha_U32, fl_alpha1_U32;
        UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;

        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size, fl_new_width_offs;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

#if defined GFX_MGR02_COMPRESSION_ENABLED        
        GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
        UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        UINT8 fl_bmp_data_U8;
        fl_global_alpha_U32 = (UINT32)p_context_SP->state.alpha;
        fl_frame_buff_U16P  = p_context_SP->rprop.fb_P;
        fl_frame_buff_U16P  = fl_frame_buff_U16P+((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w)+fl_clip_data_S.x);
        fl_bmp_data_U8P     = (UINT8 *)p_elem_def_SP->pixel_data;
#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U8P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset)/2u);
        }
        else
#endif
        {
            fl_bmp_data_U8P = fl_bmp_data_U8P+(((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset)/2u);
        }
        fl_nibble = (UINT8)(((fl_clip_data_S.y_offset*p_elem_def_SP->width)+fl_clip_data_S.x_offset) % 2U);

        /* Draw color */
        fl_fgB_U32 = p_context_SP->rprop.fg_color; fl_fgG_U32 = (fl_fgB_U32 >> 8); fl_fgR_U32 = (fl_fgG_U32 >> 8);

        fl_image_width  = fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height = fl_clip_data_S.h-fl_clip_data_S.y_offset;
        fl_frame_width_offs = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs = p_elem_def_SP->width - fl_image_width;


        switch (p_context_SP->rprop.fb_format)
        {
            case GFX_MGR02_PIX_FORMAT_RGB565:
            {
                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 63UL)/255UL);        /* 8 bit to 6 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 31UL)/255UL);        /* 8 bit to 5 bit */ 
                fl_fg_color_U16 = (UINT16)((fl_fgR_U32 << 11) | (fl_fgG_U32<<5) | fl_fgB_U32);

                while(0U != fl_image_height)
                {
                    fl_image_height--; fl_cur_x_size=0;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width)/2u);
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }
                        
                        if(0U != fl_nibble)
                        {
                          fl_alpha1_U32 = (0x0000000FUL & ((UINT32)fl_bmp_data_U8 >> 4U));
                          #if defined GFX_MGR02_COMPRESSION_ENABLED
                          if (p_elem_def_SP->comp_size == (UINT32)0)
                          #endif
                          {
                              fl_bmp_data_U8P++;
                          }
                          fl_nibble = 0;
                        }
                        else
                        {
                          fl_alpha1_U32 = (0x0000000FUL & (UINT32)fl_bmp_data_U8); /* Lower nibble */
                          fl_nibble=1;
                        }
                        fl_alpha1_U32 = (fl_global_alpha_U32 * fl_alpha1_U32)/15UL;
                        /* (fl_alpha1_32 * 255/15) *fl_global_alpha_U32/255 */


                        if(0UL != fl_alpha1_U32)
                        {
                            if(255UL == fl_alpha1_U32)
                            {
                                *fl_frame_buff_U16P = fl_fg_color_U16;
                            }
                            else 
                            {
                                fl_BgB_U32=(UINT32)(*fl_frame_buff_U16P);
                                fl_BgG_U32 = (fl_BgB_U32 >> 5); fl_BgR_U32   = (fl_BgG_U32 >> 6);

                                fl_BgB_U32 &= 0x0000001FUL; fl_BgG_U32 &= 0x0000003FUL; fl_BgR_U32 &= 0x0000001FUL;

                                /* Blend */
                                fl_BgR_U32 = (((fl_BgR_U32 << 8) + (fl_alpha1_U32 * (fl_fgR_U32 - fl_BgR_U32))) >> 8);
                                fl_BgG_U32 = (((fl_BgG_U32 << 8) + (fl_alpha1_U32 * (fl_fgG_U32 - fl_BgG_U32))) >> 8);
                                fl_BgB_U32 = (((fl_BgB_U32 << 8) + (fl_alpha1_U32 * (fl_fgB_U32 - fl_BgB_U32))) >> 8);
                                *fl_frame_buff_U16P = (UINT16)(fl_BgB_U32 | (fl_BgG_U32 << 5) | (fl_BgR_U32 << 11));
                            }
                        }
                        fl_frame_buff_U16P+=1; fl_cur_x_size++;

                    }

                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
                    fl_new_width_offs=hmi_gfx_mgr02_swrlib_next_loc(&fl_nibble, fl_image_width_offs);
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0) 
#endif                    
                    {
                        fl_bmp_data_U8P+=(UINT8)fl_new_width_offs;
                    }
                }
            }
            break;

            case GFX_MGR02_PIX_FORMAT_ARGB4444:
            {
                /* Draw color */
                fl_fgR_U32   = (((fl_fgR_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgG_U32   = (((fl_fgG_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */
                fl_fgB_U32   = (((fl_fgB_U32 & 0x000000FFUL) * 15UL)/255UL);        /* 8 bit to 4 bit */ 
                fl_fg_color_U16 = (UINT16)(0x0000F000UL | ((fl_fgR_U32 << 8) | (fl_fgG_U32<<4) | fl_fgB_U32));

                while( 0U != fl_image_height)
                {
                    fl_image_height--;
                    fl_cur_x_size=0;
                    while(fl_cur_x_size < fl_image_width)
                    {
#if defined GFX_MGR02_COMPRESSION_ENABLED                        
                        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0))
                        {
                            if (fl_rle_cur_s.count == (UINT8)0)
                            {
                                GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                            }
                            if (fl_rle_cur_s.count > (UINT8)0) {
                                fl_rle_cur_s.count--;
                            }
                            if (fl_rle_cur_s.flag == (UINT8)FALSE)
                            {
                                fl_bmp_data_U8 = *fl_rle_cur_s.bmp_data++;
                            }
                            else
                            {
                                fl_bmp_data_U8 = (UINT8)(fl_rle_cur_s.data & 0xffu);
                            }

                            fl_data_count_U16++;
                            if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                            {
                                GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width)/2u);
                                fl_data_count_U16 = (UINT16)0;
                            }
                        }
                        else
#endif
                        {
                            fl_bmp_data_U8 = *fl_bmp_data_U8P;
                        }
                        if(0U !=fl_nibble)
                        {
                            fl_alpha1_U32 = (UINT32)(0x0000000FUL & (UINT32)(fl_bmp_data_U8>>4u));
                            #if defined GFX_MGR02_COMPRESSION_ENABLED
                            if (p_elem_def_SP->comp_size == (UINT32)0)
                            #endif
                            {
                                fl_bmp_data_U8P++;
                            }
                            fl_nibble=0;
                        }
                        else
                        {
                            fl_alpha1_U32 = (UINT32)(0x0000000FUL & (UINT32)(fl_bmp_data_U8)); /* Lower nibble */
                            fl_nibble=1;
                        }
                        fl_alpha1_U32 = (fl_global_alpha_U32 * fl_alpha1_U32)/255UL;
                        /* (fl_alpha1_32 ) * (fl_global_alpha_U32 * 15/255)/15 */

                        if(0UL != fl_alpha1_U32)
                        {
                            if(15UL == fl_alpha1_U32)
                            {
                                *fl_frame_buff_U16P = fl_fg_color_U16;
                            }
                            else
                            {
                                UINT32 fl_frame_alpha_U32;
                                fl_frame_alpha_U32 = (((UINT32)*fl_frame_buff_U16P & 0x0000F000UL)>>12);
                            
                                if(0UL !=fl_frame_alpha_U32)
                                {
                                    fl_alpha1_U32 = (fl_alpha1_U32 * fl_frame_alpha_U32)/15UL;
                                }

                                fl_BgB_U32 = (UINT32) *fl_frame_buff_U16P;

                                fl_BgG_U32 = (fl_BgB_U32 >> 4); fl_BgR_U32 = (fl_BgG_U32 >> 4);
                                fl_BgB_U32 &= 0x0000000FUL; fl_BgG_U32 &= 0x0000000FUL; fl_BgR_U32 &= 0x0000000FUL;

                                /* Blend */
                                fl_BgR_U32 = (fl_fgR_U32+fl_BgR_U32)/2UL;
                                fl_BgG_U32 = (fl_fgG_U32+fl_BgG_U32)/2UL;
                                fl_BgB_U32 = (fl_fgB_U32+fl_BgB_U32)/2UL;
                                *fl_frame_buff_U16P = (UINT16)((fl_alpha1_U32 << 12) | fl_BgB_U32 | (fl_BgG_U32 << 4) | (fl_BgR_U32 << 8));
                  
                            }
                        }
                        fl_frame_buff_U16P+=1;
                        fl_cur_x_size++;
                    }
                    fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
                    fl_new_width_offs=hmi_gfx_mgr02_swrlib_next_loc(&fl_nibble, fl_image_width_offs);
#if defined GFX_MGR02_COMPRESSION_ENABLED
                    if (p_elem_def_SP->comp_size == (UINT32)0)
#endif                        
                    {
                        fl_bmp_data_U8P+=(UINT8)fl_new_width_offs;
                    }
                }
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

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_argb4444
Description          : Performs the image building.
Invocation           : sw library
Return Value         : none
Critical Section     : none
Parameters           : Image definition and context
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_build_argb4444(GFX_MGR02_CONTEXT_T const * p_context_SP,GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP)
{
    GFX_MGR02_CLIP_IMAGE_DATA  fl_clip_data_S;

    fl_clip_data_S.x = p_context_SP->state.loc.x;
    fl_clip_data_S.y = p_context_SP->state.loc.y;
    fl_clip_data_S.w = p_elem_def_SP->width;
    fl_clip_data_S.h = p_elem_def_SP->height;
#ifdef GFX_MGR02_CLIPPED_WIDGETS
    hmi_gfx_mgr02_swrlib_clip(p_context_SP,&fl_clip_data_S);
#endif
    if((fl_clip_data_S.x_offset < fl_clip_data_S.w) &&(fl_clip_data_S.y_offset < fl_clip_data_S.h))
    {
        UINT16  *fl_frame_buff_U16P;
        UINT16  const * fl_bmp_data_U16P;
        
        UINT32  fl_global_alpha_U32, fl_alpha_U32;
        UINT32  fl_BgR_U32, fl_BgG_U32, fl_BgB_U32;
        UINT32  fl_fgR_U32, fl_fgG_U32, fl_fgB_U32;
        UINT32  fl_load_color_U32;

        GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
        GFX_MGR02_ISIZE_W_T  fl_frame_width_offs, fl_image_width_offs;
        GFX_MGR02_ISIZE_H_T  fl_image_height;

#if defined GFX_MGR02_COMPRESSION_ENABLED
            GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
            UINT16        fl_data_count_U16 = (UINT16)0;
#endif
        fl_frame_buff_U16P   = p_context_SP->rprop.fb_P;
        fl_frame_buff_U16P   = fl_frame_buff_U16P+((fl_clip_data_S.y * (SINT16)p_context_SP->rprop.fb_w)+fl_clip_data_S.x);

        fl_bmp_data_U16P     = p_elem_def_SP->pixel_data;
#if defined GFX_MGR02_COMPRESSION_ENABLED
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > (UINT32)0)) {
            fl_rle_cur_s.bmp_data = (UINT8*)fl_bmp_data_U16P;
            GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset));
        }
        else
#endif
        {
            fl_bmp_data_U16P = fl_bmp_data_U16P + ((fl_clip_data_S.y_offset * p_elem_def_SP->width) + fl_clip_data_S.x_offset);
        }
        fl_global_alpha_U32  = (UINT32)p_context_SP->state.alpha;

        fl_image_width       = fl_clip_data_S.w-fl_clip_data_S.x_offset;
        fl_image_height      = fl_clip_data_S.h-fl_clip_data_S.y_offset;
        fl_frame_width_offs  = p_context_SP->rprop.fb_w - fl_image_width;
        fl_image_width_offs  = p_elem_def_SP->width - fl_image_width;

        while(0U != fl_image_height)
        {
            fl_image_height--;
            fl_cur_x_size = fl_image_width;
            #if defined GFX_MGR02_COMPRESSION_ENABLED
            fl_data_count_U16 = (UINT16)0;
            #endif
            while(0U != fl_cur_x_size)
            {
                #if defined GFX_MGR02_COMPRESSION_ENABLED
                UINT16 fl_bmp_data_U16;
                #endif
                fl_cur_x_size--;
#if defined GFX_MGR02_COMPRESSION_ENABLED   
                if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > 0))
                {
                    if (fl_rle_cur_s.count ==(UINT8)0)
                    {
                        GfxDriverRLEonline(&fl_rle_cur_s, p_elem_def_SP->format);
                    }
                    if (fl_rle_cur_s.count > (UINT8)0) {
                        fl_rle_cur_s.count--;
                    }
                    if (fl_rle_cur_s.flag == (UINT8)FALSE)
                    {
                        fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data++;
                        fl_bmp_data_U16 = fl_bmp_data_U16 << 8U;
                        fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data++));
                    }
                    else
                    {
                        fl_bmp_data_U16 = fl_rle_cur_s.data;
                    }

                    fl_data_count_U16++;
                    if ((fl_data_count_U16 == fl_image_width) && (p_elem_def_SP->width > fl_image_width))
                    {
                        GfxDriverRLEonlineNLine(&fl_rle_cur_s, p_elem_def_SP->format, (p_elem_def_SP->width - fl_image_width));
                        fl_data_count_U16 = (UINT16)0;
                    }
                    fl_load_color_U32 = ((UINT32)fl_bmp_data_U16) & 0x00000FFFu;
                    fl_alpha_U32 = (UINT32)(((fl_bmp_data_U16) >> 12u) & 0x0000000FUL);
                }
                else
#endif
                {
                    fl_load_color_U32 = ((UINT32)*fl_bmp_data_U16P) & 0x00000FFFu;

                    fl_alpha_U32 = (UINT32)(((UINT32)(*fl_bmp_data_U16P) >> 12u) & 0x0000000FUL);
                 }
                fl_alpha_U32 = (fl_global_alpha_U32 * fl_alpha_U32)/15u;
                /* (fl_alpha_32 * 255/15 *fl_global_alpha_U32/255 */

                if(fl_alpha_U32 != 0UL)
                {
                    if(255UL == fl_alpha_U32)
                    {
                        fl_load_color_U32 = fl_load_color_U32 + 0x0000F000UL;
                    }
                    else
                    {
                        fl_alpha_U32 = ((((UINT32)(*fl_frame_buff_U16P) & 0x0000F000UL) >> 12U) * fl_alpha_U32) / 255U;

                        fl_fgR_U32 = (fl_load_color_U32>>8) & 0x0000000FUL;
                        fl_fgG_U32 = (fl_load_color_U32>>4) & 0x0000000FUL;
                        fl_fgB_U32 = (fl_load_color_U32 & 0x0000000FUL);

                        fl_BgR_U32 = (UINT32)*fl_frame_buff_U16P;
                        fl_BgG_U32 = (fl_BgR_U32>>4);

                        fl_BgB_U32 = (fl_BgR_U32 & 0x0000000FUL);
                        fl_BgR_U32 = (fl_BgG_U32>>4) & 0x0000000FUL;
                        fl_BgG_U32 = fl_BgG_U32 & 0x0000000FUL;

                        fl_fgR_U32 = (fl_BgR_U32 + fl_fgR_U32)/2UL;
                        fl_fgG_U32 = (fl_BgG_U32 + fl_fgG_U32)/2UL;
                        fl_fgB_U32 = (fl_BgB_U32 + fl_fgB_U32)/2UL;

                        fl_load_color_U32 = (fl_fgR_U32<<8) | (fl_fgG_U32<<4) | fl_fgB_U32 | (fl_alpha_U32<<12);
                    }
                    *fl_frame_buff_U16P = (UINT16)fl_load_color_U32;
                }

                fl_frame_buff_U16P+=1;
                #if defined GFX_MGR02_COMPRESSION_ENABLED   
                if (p_elem_def_SP->comp_size == (UINT32)0)
                #endif      
                {
                    fl_bmp_data_U16P += 1;
                }
            }
            fl_frame_buff_U16P = fl_frame_buff_U16P+fl_frame_width_offs;
            fl_bmp_data_U16P = fl_bmp_data_U16P+fl_image_width_offs;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_build_text
Description          : Builds a text object
Invocation           : generic
Parameters           : context pointer, element definition and pointer to string
Return Value         : 0 if success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                            HMI_CHAR             const * p_string,
                                            u_gx_flocal                  p_text_actual_width)
{
    HMI_CHAR const * fl_string_ptr = NULL;
    GFX_UINT         fl_alignment  = p_cntx_SP->rprop.alignment;
    UINT32           fl_str_length = 0UL;
    UINT16           fl_text_width;
    UINT8            fl_shutdown_state;

    #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    static HMI_CHAR l_irislib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
    #endif
    
    fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
    if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    #if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx) && (p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
    #endif
    )
    {
        UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
        GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);   

        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
            GFX_MGR02_TEXT_INFO fl_text_info_S;
            
            fl_text_info_S.print_str_P          = p_string;
            fl_text_info_S.max_available_width  = p_cntx_SP->rprop.text_width;
            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            fl_text_info_S.append_str = TRUE;
            l_irislib_clip_text_str[0] = (HMI_CHAR)0;
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
            #if (defined(GFX_MGR02_CLIP_TEXT_ENABLE))
            fl_string_ptr = l_irislib_clip_text_str;
            #else
            fl_string_ptr = fl_text_info_S.print_str_P;
            #endif
            
            fl_text_width = fl_text_info_S.print_width;
            fl_str_length = fl_text_info_S.print_length_U8;
        }
        else
        {
            fl_text_width = (UINT16)0;
        }
        
        if(fl_text_width > (UINT16)0)
        {
            GFX_MGR02_CLIP_IMAGE_DATA fl_clip_data_S = { 0 };
            GFX_MGR02_CONTEXT_T fl_context_sp;
            UINT32 fl_fg_color;
            UINT32 fl_bg_color;
            SINT32 fl_start_x;
            SINT32 fl_txtbox_strt_x;
            UINT8  fl_draw_mode;
            
            /* Assuming current alignment as the default alignment,
            ** Compute how much cursur position needs to be adjusted for 
            ** each alignment for drawing the text string & text background. 
            */
            if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
                fl_txtbox_strt_x = (SINT32)p_cntx_SP->rprop.text_width - 1;
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
                fl_start_x       = (fl_text_width > p_cntx_SP->rprop.text_width) ? (((SINT32)p_cntx_SP->rprop.text_width / 2)) : ((SINT32)fl_text_width / 2);
                fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width / 2);
            }
            else
            {
                fl_start_x       = 0;
                fl_txtbox_strt_x = 0;
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
                    fl_txtbox_strt_x += (((SINT32)p_cntx_SP->rprop.text_width + 1)/2);
                    fl_txtbox_strt_x -= 1;
                    fl_start_x += (((SINT32)p_cntx_SP->rprop.text_width + 1)/2);
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
                    fl_start_x -= (((SINT32)p_cntx_SP->rprop.text_width + 1)/2);
                    fl_txtbox_strt_x -= (((SINT32)p_cntx_SP->rprop.text_width - 1)/2);
                }
                else
                {
                    /* To fix MISRA warning */
                }
            }
            else /* Left alignment */
            {
                if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
                {
                    fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width/2);
                    fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width/2);
                }
                else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
                {
                    fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width - 1);
                    fl_start_x += ((SINT32)p_cntx_SP->rprop.text_width - 1);
                }
                else
                {
                    /* To fix MISRA warning */
                }
            }
            #endif

            fl_start_x       = ((SINT32)p_cntx_SP->state.loc.x - fl_start_x);
            fl_txtbox_strt_x = ((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x);
            fl_draw_mode     = (UINT8)p_cntx_SP->rprop.draw_mode;
            fl_fg_color      = p_cntx_SP->rprop.fg_color;
            
            hmi_gfx_mgr02_context_state_get(&fl_context_sp.state);
            fl_context_sp.rprop = p_cntx_SP->rprop;

            if (fl_draw_mode != GFX_MGR02_TP_DRAW_TRANSP)
            {
                /* Render text background colour */
                UINT32 fl_bg_color_alpha;
                
                if (fl_draw_mode == GFX_MGR02_TP_DRAW_REVERSE)
                {
                    fl_bg_color = p_cntx_SP->rprop.fg_color;
                    fl_fg_color = p_cntx_SP->rprop.bg_color;
                }
                else /* GFX_MGR02_TP_DRAW_NORMAL */
                {
                    fl_bg_color = p_cntx_SP->rprop.bg_color;
                }
                
                fl_bg_color_alpha = (fl_bg_color >> 24U);

                if((fl_bg_color_alpha != 0U) || (p_cntx_SP->state.alpha != 0U))
                {
                    GFX_MGR02_IDIM_DATA fl_dim;
                    
                    fl_dim.width = (UINT16)p_cntx_SP->rprop.text_width;
                    fl_dim.height = (UINT16)fl_font_SP->p.height;

                    fl_context_sp.state.loc.x       = (SINT16)fl_txtbox_strt_x;
                    fl_context_sp.rprop.fg_color    = fl_bg_color;
                    
                    (void)hmi_gfx_mgr02_swrlib_build_fill((GFX_MGR02_CONTEXT_T const *)&fl_context_sp, GFX_MGR02_NULL_PTR, (GFX_MGR02_IDIM_DATA const *)&fl_dim);
                }  
            }

            fl_clip_data_S.x = (SINT16)fl_txtbox_strt_x;
            fl_clip_data_S.y = p_cntx_SP->state.loc.y;
            fl_clip_data_S.w = p_cntx_SP->rprop.text_width;
            fl_clip_data_S.h = fl_font_SP->p.height;

            /* Update current clip based on textbox area */
#ifdef GFX_MGR02_CLIPPED_WIDGETS
            hmi_gfx_mgr02_swrlib_clip(p_cntx_SP, &fl_clip_data_S);
#endif
            if ((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
            {
                fl_context_sp.state.clip.sx = fl_clip_data_S.x;
                fl_context_sp.state.clip.sy = fl_clip_data_S.y;
                fl_context_sp.state.clip.ex = fl_clip_data_S.x + ((SINT16)fl_clip_data_S.w - (SINT16)fl_clip_data_S.x_offset);
                fl_context_sp.state.clip.ey = fl_clip_data_S.y + ((SINT16)fl_clip_data_S.h - (SINT16)fl_clip_data_S.y_offset);

                /* Bitmap Font rendering */
                hmi_gfx_mgr02_swrlib_render_bmp_font((GFX_MGR02_CONTEXT_T const*)&fl_context_sp, fl_string_ptr, fl_font_SP, fl_fg_color, fl_str_length, (SINT16)fl_start_x);
            }
        }
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
        gfx_debug("SWRLIB - Text elem = %08X skipped\n", (UINT32)p_elem_def_SP);
    }
#endif    
    GFX_MGR02_UNUSED_VAR(p_text_actual_width);
    return (s_gx_flocal)0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_render_bmp_font
Description          : Renders bitmap font 
Invocation           : Invoked internally
Parameters           : context pointer, 
                       string pointer,
                       font object pointer
                       draw color,
                       string length,
                       starting x co-ordinate.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_render_bmp_font(GFX_MGR02_CONTEXT_T const * p_cntx_SP, 
                                                 HMI_CHAR const * p_string_ptr, 
                                                 GFX_MGR02_FONT const * p_font_SP, 
                                                 UINT32 p_draw_color, 
                                                 UINT32 p_str_length,
                                                 SINT16 p_start_x)
{ 
    HMI_CHAR const * fl_string_ptr = p_string_ptr;
    UINT32 fl_draw_color = p_draw_color; 
    UINT32 fl_str_length = p_str_length;
    SINT16 fl_glyph_draw_x = p_start_x;
    SINT16 fl_glyph_draw_y = p_cntx_SP->state.loc.y;
    UINT8 fl_font_bpp = GFX_MGR02_GET_BPP(p_font_SP->f.lut_ptr->attributes);
    UINT8 fl_font_char_space = p_font_SP->char_space;
    GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
    UINT8 const * fl_glyph_data_U8P;
    UINT8 const * fl_glyph_line_U8P;
    UINT8 fl_glyph_data_U8;
    UINT8 fl_glyph_width;
    UINT8 fl_glyph_height;
    UINT16 fl_cur_clip_h;
    UINT16 fl_cur_clip_w;
    SINT16 fl_glyph_soffset_x, fl_glyph_soffset_y; 
    SINT16 fl_start_pen_pos_x, fl_cur_pen_pos_x;
    SINT16 fl_start_pen_pos_y;
    UINT8 fl_remaining_width;
    UINT8 fl_pixels_per_byte;
    UINT8 fl_pix_in_byte_remaining;
    UINT8 fl_bit_mask_for_pixel;
    
    switch(fl_font_bpp)
    {
        case GFX_MGR02_FONT_ENCODING_4BPP:
        {
            fl_pixels_per_byte = 2U;
            fl_bit_mask_for_pixel = 0x0FU;
        }
        break;
        case GFX_MGR02_FONT_ENCODING_2BPP:
        {
            fl_pixels_per_byte = 4U;
            fl_bit_mask_for_pixel = 0x03U;
        }
        break;
        case GFX_MGR02_FONT_ENCODING_1BPP:
        {
            fl_pixels_per_byte = 8U;
            fl_bit_mask_for_pixel = 0x01U;
        }
        break;
        case GFX_MGR02_FONT_ENCODING_8BPP:
        default:
        { 
            fl_pixels_per_byte = 1U;
            fl_bit_mask_for_pixel = 0xFFU;
        }
        break;
    }
    
    while(fl_str_length > 0UL)
    {
        fl_str_length--;
        
        fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(*fl_string_ptr, p_font_SP->f.lut_ptr, (UINT32)p_font_SP->size_table,
                                                #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                                                (UINT32)(p_cntx_SP->rprop.font_id),
                                                #endif
                                                (UINT32)FALSE);
        
        #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT
        if(fl_font_fcc_SP == GFX_MGR02_NULL_PTR)
        {
            fl_font_fcc_SP = lc_default_char_config_SPA[p_cntx_SP->rprop.font_id];
        }
        #endif
        
        if (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
        {
            fl_glyph_width = fl_font_fcc_SP->width;
            fl_glyph_height = fl_font_fcc_SP->height;
            fl_glyph_line_U8P = fl_font_fcc_SP->fdata;
            fl_glyph_soffset_x = fl_glyph_draw_x + fl_font_fcc_SP->x_soffset;
            fl_glyph_soffset_y = fl_glyph_draw_y + fl_font_fcc_SP->y_soffset;
            
            if (fl_glyph_line_U8P != GFX_MGR02_NULL_PTR) /* Valid glyph data */
            {
                GFX_MGR02_CLIP_IMAGE_DATA fl_clip_data_S = {0};

                fl_clip_data_S.x = fl_glyph_soffset_x;
                fl_clip_data_S.y = fl_glyph_soffset_y;
                fl_clip_data_S.w = fl_glyph_width;
                fl_clip_data_S.h = fl_glyph_height;
                
                /* Update current clip based on glyph area */
                #ifdef GFX_MGR02_CLIPPED_WIDGETS
                hmi_gfx_mgr02_swrlib_clip(p_cntx_SP, &fl_clip_data_S);
                #endif
                
                if ((fl_clip_data_S.x_offset < fl_clip_data_S.w) && (fl_clip_data_S.y_offset < fl_clip_data_S.h))
                {
                    fl_cur_clip_h = fl_clip_data_S.h - fl_clip_data_S.y_offset;
                    fl_cur_clip_w = fl_clip_data_S.w - fl_clip_data_S.x_offset;

                    fl_start_pen_pos_x = ((fl_glyph_soffset_x) > fl_clip_data_S.x) ? (fl_glyph_soffset_x) : (fl_clip_data_S.x);
                    fl_start_pen_pos_y = ((fl_glyph_soffset_y) > fl_clip_data_S.y) ? (fl_glyph_soffset_y) : (fl_clip_data_S.y);
                    
                    if(p_cntx_SP->rprop.fb_format == (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888) /* 32bpp frame buffer format */
                    {
                        UINT32 * fl_fb_cur_pixel_U32P; /* pointing to current pixel in frame buffer */
                        UINT32 * fl_fb_cur_line_U32P;  /* pointing to current line in frame buffer */
                        UINT32 fl_prev_dst_p = 0UL, fl_prev_src_a = 0UL, fl_prev_blend_p = 0UL ;
                        UINT32 fl_src_a;
                        UINT32 fl_dst_p;

                        fl_fb_cur_line_U32P = (UINT32*)p_cntx_SP->rprop.fb_P;
                        
                        /* Offset frame buffer address based on clip */
                        fl_fb_cur_line_U32P = &fl_fb_cur_line_U32P[((fl_start_pen_pos_y * (SINT16)p_cntx_SP->rprop.fb_w) + fl_start_pen_pos_x)];

                        /* Offset glyph buffer address based on clip */
                        fl_glyph_line_U8P = &fl_glyph_line_U8P[((((fl_start_pen_pos_y - fl_glyph_soffset_y) * ((SINT16)fl_glyph_width + ((SINT16)fl_pixels_per_byte - (SINT16)1))) + (fl_start_pen_pos_x - fl_glyph_soffset_x)) / (SINT16)fl_pixels_per_byte)];

                        while(0U < fl_cur_clip_h)
                        {
                            fl_cur_clip_h--;

                            fl_remaining_width = (UINT8)fl_cur_clip_w;
                            fl_cur_pen_pos_x = fl_start_pen_pos_x;
                            fl_fb_cur_pixel_U32P = fl_fb_cur_line_U32P;
                            fl_glyph_data_U8P = fl_glyph_line_U8P;

                            while(0U < fl_remaining_width)
                            {
                                fl_glyph_data_U8 = *fl_glyph_data_U8P;
                                    
                                if(fl_glyph_data_U8 != 0U)
                                {
                                    if(fl_font_bpp == GFX_MGR02_FONT_ENCODING_8BPP)
                                    {
                                        fl_src_a = (UINT32)fl_glyph_data_U8;
                                        fl_src_a = ((fl_src_a * p_cntx_SP->state.alpha) / 255UL);

                                        if(fl_src_a != 0U)
                                        {
                                            fl_dst_p = *fl_fb_cur_pixel_U32P; /* Destination pixel */
                                            if (255U == fl_src_a)
                                            {
                                                *fl_fb_cur_pixel_U32P = ((0xFF000000UL) | (fl_draw_color & 0x00FFFFFFUL));
                                            }
                                            else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                            {
                                                *fl_fb_cur_pixel_U32P = fl_prev_blend_p;
                                            }
                                            else
                                            {
                                                hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U32P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);

                                                fl_prev_blend_p = *fl_fb_cur_pixel_U32P;
                                                fl_prev_dst_p = fl_dst_p;
                                                fl_prev_src_a = fl_src_a;
                                            }
                                        }
                                        fl_fb_cur_pixel_U32P++;
                                        fl_remaining_width--;
                                    }
                                    else /* to handle for 4bpp, 2bpp & 1bpp font */
                                    {   
                                        if(fl_remaining_width > fl_pixels_per_byte)
                                        {
                                            SINT16 fl_diff_x = (fl_cur_pen_pos_x - fl_glyph_soffset_x);
                                            if (((UINT8)fl_diff_x % fl_pixels_per_byte) == 0U)
                                            {
                                                fl_pix_in_byte_remaining = fl_pixels_per_byte;
                                            }
                                            else
                                            {
                                          
                                                fl_pix_in_byte_remaining = (fl_pixels_per_byte - ((UINT8)fl_diff_x % fl_pixels_per_byte));
                                                fl_glyph_data_U8 >>= ((fl_pixels_per_byte - fl_pix_in_byte_remaining) * (8U / fl_pixels_per_byte));
                                            }
                                        }
                                        else 
                                        {
                                            fl_pix_in_byte_remaining = fl_remaining_width;
                                        }
                                                
                                        while(0U != fl_pix_in_byte_remaining)
                                        {
                                            fl_src_a = ((((UINT32)fl_glyph_data_U8 & (UINT32)fl_bit_mask_for_pixel) * 255UL) / (UINT32)fl_bit_mask_for_pixel);
                                            fl_src_a = ((fl_src_a * p_cntx_SP->state.alpha) / 255UL);

                                            if(fl_src_a != 0U)
                                            {
                                                fl_dst_p = *fl_fb_cur_pixel_U32P; /* Destination pixel */
                                                if (255U == fl_src_a)
                                                {
                                                    *fl_fb_cur_pixel_U32P = ((0xFF000000UL) | (fl_draw_color & 0x00FFFFFFUL));
                                                }
                                                else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                                {
                                                    *fl_fb_cur_pixel_U32P = fl_prev_blend_p;
                                                }
                                                else
                                                {
                                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U32P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888);
                                                    
                                                    fl_prev_blend_p = *fl_fb_cur_pixel_U32P;
                                                    fl_prev_dst_p = fl_dst_p;
                                                    fl_prev_src_a = fl_src_a;
                                                }
                                            }
                                            fl_glyph_data_U8 >>= (8U / fl_pixels_per_byte);
                                            fl_fb_cur_pixel_U32P++;
                                            fl_pix_in_byte_remaining--;
                                            fl_remaining_width--;
                                            fl_cur_pen_pos_x++;
                                        }
                                    }
                                }
                                else 
                                {
                                    if(fl_font_bpp == GFX_MGR02_FONT_ENCODING_8BPP)
                                    {
                                        fl_remaining_width--;
                                        fl_fb_cur_pixel_U32P++;
                                    }
                                    else /* to handle for 4bpp, 2bpp & 1bpp font */
                                    {
                                        if (fl_remaining_width >= fl_pixels_per_byte)
                                        {
                                            SINT16 fl_diff_x = (fl_cur_pen_pos_x - fl_glyph_soffset_x);
                                            if (((UINT8)fl_diff_x % fl_pixels_per_byte) == 0U)
                                            {
                                                fl_remaining_width -= fl_pixels_per_byte;
                                                fl_cur_pen_pos_x += (SINT16)fl_pixels_per_byte;
                                                fl_fb_cur_pixel_U32P = &fl_fb_cur_pixel_U32P[fl_pixels_per_byte];
                                            }
                                            else
                                            {
                                                UINT8 fl_adjust_by = (fl_pixels_per_byte - ((UINT8)fl_diff_x % fl_pixels_per_byte));
                                                fl_remaining_width -= fl_adjust_by;
                                                fl_cur_pen_pos_x += (SINT16)fl_adjust_by;
                                                fl_fb_cur_pixel_U32P = &fl_fb_cur_pixel_U32P[fl_adjust_by];
                                            }
                                        }
                                        else
                                        {
                                            fl_remaining_width = 0;
                                        }
                                    }
                                }
                                fl_glyph_data_U8P++;
                            }
                            fl_fb_cur_line_U32P = &fl_fb_cur_line_U32P[p_cntx_SP->rprop.fb_w];
                            fl_glyph_line_U8P = &fl_glyph_line_U8P[((fl_glyph_width + (fl_pixels_per_byte - 1U)) / fl_pixels_per_byte)];
                        }
                    }
                    else /* 16bpp frame buffer format */
                    {
                        UINT16* fl_fb_cur_pixel_U16P; /* pointing to current pixel in frame buffer */
                        UINT16* fl_fb_cur_line_U16P;  /* pointing to current line in frame buffer */
                        UINT16 fl_prev_dst_p = 0U, fl_prev_src_a = 0U, fl_prev_blend_p = 0U;
                        UINT16 fl_src_a, fl_src_r, fl_src_g, fl_src_b;
                        UINT16 fl_dst_p;

                        fl_fb_cur_line_U16P = (UINT16*)p_cntx_SP->rprop.fb_P;

                        /* Offset frame buffer address based on clip */
                        fl_fb_cur_line_U16P = &fl_fb_cur_line_U16P[((fl_start_pen_pos_y * (SINT16)p_cntx_SP->rprop.fb_w) + fl_start_pen_pos_x)];

                        /* Offset glyph buffer address based on clip */
                        fl_glyph_line_U8P = &fl_glyph_line_U8P[((((fl_start_pen_pos_y - fl_glyph_soffset_y) * ((SINT16)fl_glyph_width + ((SINT16)fl_pixels_per_byte - 1))) + (fl_start_pen_pos_x - fl_glyph_soffset_x)) / (SINT16)fl_pixels_per_byte)];

                        while (0U < fl_cur_clip_h)
                        {
                            fl_cur_clip_h--;

                            fl_remaining_width = (UINT8)fl_cur_clip_w;
                            fl_cur_pen_pos_x = fl_start_pen_pos_x;
                            fl_fb_cur_pixel_U16P = fl_fb_cur_line_U16P;
                            fl_glyph_data_U8P = fl_glyph_line_U8P;

                            while (0U < fl_remaining_width)
                            {
                                fl_glyph_data_U8 = *fl_glyph_data_U8P;

                                if (fl_glyph_data_U8 != 0U)
                                {
                                    if (fl_font_bpp == GFX_MGR02_FONT_ENCODING_8BPP)
                                    {
                                        fl_src_a = (UINT16)fl_glyph_data_U8;
                                        fl_src_a = ((fl_src_a * p_cntx_SP->state.alpha) / 255U);

                                        if (fl_src_a != 0U)
                                        {
                                            fl_dst_p = *fl_fb_cur_pixel_U16P; /* Destination pixel */
                                            if (p_cntx_SP->rprop.fb_format == (UINT8)GFX_MGR02_PIX_FORMAT_ARGB4444)
                                            {
                                                /* Scale down A8, R8, G8, B8 to A4, R4, G4, B4 */

                                                /* half of the divisor added to the numerator to achieve proper rounding when
                                                 * performing the integer division and avoid any rounding errors */

                                                fl_src_a = (((0xFU * fl_src_a) + 127U) / 255U);
                                                
                                                if (15U == fl_src_a)
                                                {
                                                    fl_src_r = (UINT16)(((0xFU * ((fl_draw_color >> 16U) & 0xFFU)) + 127U) / 255U);
                                                    fl_src_g = (UINT16)(((0xFU * ((fl_draw_color >> 8U) & 0xFFU)) + 127U) / 255U);
                                                    fl_src_b = (UINT16)(((0xFU * ((fl_draw_color) & 0xFFU)) + 127U) / 255U);
                                                    *fl_fb_cur_pixel_U16P = (UINT16)((0xF000U) | (UINT16)(fl_src_r << 8U) | (UINT16)(fl_src_g << 4U) | fl_src_b);
                                                }
                                                else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                                {
                                                    *fl_fb_cur_pixel_U16P = fl_prev_blend_p;
                                                }
                                                else
                                                {
                                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U16P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB4444);

                                                    fl_prev_blend_p = *fl_fb_cur_pixel_U16P;
                                                    fl_prev_dst_p = fl_dst_p;
                                                    fl_prev_src_a = fl_src_a;
                                                }
                                            }
                                            else /* frame buffer format rgb565 */
                                            {
                                                /* Scale down R8, G8, B8 to R5, G6, B5 */

                                                if (255U == fl_src_a)
                                                {
                                                    fl_src_r = (UINT16)(((0x1FU * ((fl_draw_color >> 16U) & 0xFFU)) + 127U) / 255U);
                                                    fl_src_g = (UINT16)(((0x3FU * ((fl_draw_color >> 8U) & 0xFFU)) + 127U) / 255U);
                                                    fl_src_b = (UINT16)(((0x1FU * ((fl_draw_color) & 0xFFU)) + 127U) / 255U);
                                                    *fl_fb_cur_pixel_U16P = (UINT16)((UINT16)(fl_src_r << 11U) | (UINT16)(fl_src_g << 5U) | fl_src_b);
                                                }
                                                else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                                {
                                                    *fl_fb_cur_pixel_U16P = fl_prev_blend_p;
                                                }
                                                else
                                                {
                                                    hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U16P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_RGB565);

                                                    fl_prev_blend_p = *fl_fb_cur_pixel_U16P;
                                                    fl_prev_dst_p = fl_dst_p;
                                                    fl_prev_src_a = fl_src_a;
                                                }
                                            }
                                        }
                                        fl_fb_cur_pixel_U16P++;
                                        fl_remaining_width--;
                                    }
                                    else /* to handle for 4bpp, 2bpp & 1bpp font encoding */
                                    {
                                        if (fl_remaining_width > fl_pixels_per_byte)
                                        {
                                            SINT16 fl_diff_x = (fl_cur_pen_pos_x - fl_glyph_soffset_x);
                                            if (((UINT8)fl_diff_x % fl_pixels_per_byte) == 0U)
                                            {
                                                fl_pix_in_byte_remaining = fl_pixels_per_byte;
                                            }
                                            else
                                            {
                                                fl_pix_in_byte_remaining = (fl_pixels_per_byte - ((UINT8)fl_diff_x % fl_pixels_per_byte));
                                                fl_glyph_data_U8 >>= ((fl_pixels_per_byte - fl_pix_in_byte_remaining) * (8U / fl_pixels_per_byte));
                                            }
                                        }
                                        else
                                        {
                                            fl_pix_in_byte_remaining = fl_remaining_width;
                                        }

                                        while (0U != fl_pix_in_byte_remaining)
                                        {
                                            /* Scale up src alpha to 8bits */
                                            fl_src_a = ((((UINT16)fl_glyph_data_U8 & (UINT16)fl_bit_mask_for_pixel) * 255U) / (UINT16)fl_bit_mask_for_pixel);
                                            fl_src_a = ((fl_src_a * p_cntx_SP->state.alpha) / 255U);

                                            if (fl_src_a != 0U)
                                            {
                                                fl_dst_p = *fl_fb_cur_pixel_U16P; /* Destination pixel */
                                                if (p_cntx_SP->rprop.fb_format == (UINT8)GFX_MGR02_PIX_FORMAT_ARGB4444)
                                                {
                                                    /* Scale down A8, R8, G8, B8 to A4, R4, G4, B4 */

                                                    /* half of the divisor added to the numerator to achieve proper rounding when
                                                     * performing the integer division and avoid any rounding errors */

                                                    fl_src_a = (((0xFU * fl_src_a) + 127U) / 255U);

                                                    if (15U == fl_src_a)
                                                    {
                                                        fl_src_r = (UINT16)(((0xFU * ((fl_draw_color >> 16U) & 0xFFU)) + 127U) / 255U);
                                                        fl_src_g = (UINT16)(((0xFU * ((fl_draw_color >> 8U) & 0xFFU)) + 127U) / 255U);
                                                        fl_src_b = (UINT16)(((0xFU * ((fl_draw_color) & 0xFFU)) + 127U) / 255U);
                                                        *fl_fb_cur_pixel_U16P = (UINT16)((0xF000U) | (UINT16)(fl_src_r << 8U) | (UINT16)(fl_src_g << 4U) | fl_src_b);
                                                    }
                                                    else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                                    {
                                                        *fl_fb_cur_pixel_U16P = fl_prev_blend_p;
                                                    }
                                                    else
                                                    {
                                                        hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U16P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_ARGB4444);

                                                        fl_prev_blend_p = *fl_fb_cur_pixel_U16P;
                                                        fl_prev_dst_p = fl_dst_p;
                                                        fl_prev_src_a = fl_src_a;
                                                    }
                                                }
                                                else /* frame buffer format rgb565 */
                                                {
                                                    /* Scale down R8, G8, B8 to R5, G6, B5 */

                                                    if (255U == fl_src_a)
                                                    {
                                                        fl_src_r = (UINT16)(((0x1FU * ((fl_draw_color >> 16U) & 0xFFU)) + 127U) / 255U);
                                                        fl_src_g = (UINT16)(((0x3FU * ((fl_draw_color >> 8U) & 0xFFU)) + 127U) / 255U);
                                                        fl_src_b = (UINT16)(((0x1FU * ((fl_draw_color) & 0xFFU)) + 127U) / 255U);
                                                        *fl_fb_cur_pixel_U16P = (UINT16)((UINT16)(fl_src_r << 11U) | (UINT16)(fl_src_g << 5U) | fl_src_b);
                                                    }
                                                    else if ((fl_dst_p == fl_prev_dst_p) && (fl_src_a == fl_prev_src_a))
                                                    {
                                                        *fl_fb_cur_pixel_U16P = fl_prev_blend_p;
                                                    }
                                                    else
                                                    {
                                                        hmi_gfx_mgr02_swrlib_blend_operation((void*)fl_fb_cur_pixel_U16P, (UINT8)fl_src_a, fl_draw_color, (UINT8)GFX_MGR02_PIX_FORMAT_RGB565);

                                                        fl_prev_blend_p = *fl_fb_cur_pixel_U16P;
                                                        fl_prev_dst_p = fl_dst_p;
                                                        fl_prev_src_a = fl_src_a;
                                                    }
                                                }
                                            }
                                            fl_glyph_data_U8 >>= (8U / fl_pixels_per_byte);
                                            fl_fb_cur_pixel_U16P++;
                                            fl_pix_in_byte_remaining--;
                                            fl_remaining_width--;
                                            fl_cur_pen_pos_x++;
                                        }
                                    }
                                }
                                else
                                {
                                    if (fl_font_bpp == GFX_MGR02_FONT_ENCODING_8BPP)
                                    {
                                        fl_remaining_width--;
                                        fl_fb_cur_pixel_U16P++;
                                    }
                                    else /* to handle for 4bpp, 2bpp & 1bpp font encoding */
                                    {
                                        if (fl_remaining_width >= fl_pixels_per_byte)
                                        {
                                            SINT16 fl_diff_x = (fl_cur_pen_pos_x - fl_glyph_soffset_x);
                                            if (((UINT8)fl_diff_x % fl_pixels_per_byte) == 0U)
                                            {
                                                fl_remaining_width -= fl_pixels_per_byte;
                                                fl_cur_pen_pos_x += (SINT16)fl_pixels_per_byte;
                                                fl_fb_cur_pixel_U16P = &fl_fb_cur_pixel_U16P[fl_pixels_per_byte];
                                            }
                                            else
                                            {
                                                UINT8 fl_adjust_by = (fl_pixels_per_byte - ((UINT8)fl_diff_x % fl_pixels_per_byte));
                                                fl_remaining_width -= fl_adjust_by;
                                                fl_cur_pen_pos_x += (SINT16)fl_adjust_by;
                                                fl_fb_cur_pixel_U16P = &fl_fb_cur_pixel_U16P[fl_adjust_by];
                                            }
                                        }
                                        else
                                        {
                                            fl_remaining_width = 0;
                                        }
                                    }
                                }
                                fl_glyph_data_U8P++;
                            }
                            fl_fb_cur_line_U16P = &fl_fb_cur_line_U16P[p_cntx_SP->rprop.fb_w];
                            fl_glyph_line_U8P = &fl_glyph_line_U8P[((fl_glyph_width + (fl_pixels_per_byte - 1U)) / fl_pixels_per_byte)];
                        }
                    }
                }
            }
            fl_glyph_draw_x = fl_glyph_draw_x + ((SINT16)fl_font_fcc_SP->owidth + (SINT16)fl_font_char_space);
        }    
        fl_string_ptr++;
    }
}

static void hmi_gfx_mgr02_swrlib_blend_operation(void* p_fb_cur_pixel_ptr, UINT8 p_src_a, UINT32 p_src_color_rgb, UINT8 p_fb_format)
{
    switch(p_fb_format)
    {
        case (UINT8)GFX_MGR02_PIX_FORMAT_ARGB8888:
        {
            UINT32 fl_src_a, fl_src_r, fl_src_g, fl_src_b;
            UINT32 fl_dst_p, fl_dst_a, fl_dst_r, fl_dst_g, fl_dst_b;
            UINT32 fl_blend_a, fl_blend_r, fl_blend_g, fl_blend_b;
            UINT32 *fl_fb_cur_pixel_U32P = (UINT32*)p_fb_cur_pixel_ptr;
            UINT32 fl_one_minus_src_a; 
            
            fl_src_a = (UINT32)p_src_a;
            fl_one_minus_src_a = (255UL - fl_src_a);
            
            fl_dst_p = *fl_fb_cur_pixel_U32P;
            fl_dst_a = ((fl_dst_p >> 24U) & 0xFFU);
            fl_dst_r = ((fl_dst_p >> 16U) & 0xFFU);
            fl_dst_g = ((fl_dst_p >> 8U) & 0xFFU);
            fl_dst_b = ((fl_dst_p) & 0xFFU);
             
            fl_src_r = ((((fl_src_a) * ((p_src_color_rgb >> 16U) & 0xFFU)) + 128U) >> 8U);
            fl_src_g = ((((fl_src_a) * ((p_src_color_rgb >> 8U) & 0xFFU)) + 128U) >> 8U);
            fl_src_b = ((((fl_src_a) * ((p_src_color_rgb) & 0xFFU)) + 128U) >> 8U);

            fl_blend_r = ((((fl_one_minus_src_a * fl_dst_r) + 128U) >> 8U) + fl_src_r);
            fl_blend_g = ((((fl_one_minus_src_a * fl_dst_g) + 128U) >> 8U) + fl_src_g);
            fl_blend_b = ((((fl_one_minus_src_a * fl_dst_b) + 128U) >> 8U) + fl_src_b);
            fl_blend_a = ((((fl_one_minus_src_a * fl_dst_a) + 128U) >> 8U) + fl_src_a);

            *fl_fb_cur_pixel_U32P = ((fl_blend_a << 24U) | (fl_blend_r << 16U) | (fl_blend_g << 8U) | fl_blend_b);
        }
        break;
        case (UINT8)GFX_MGR02_PIX_FORMAT_ARGB4444:
        {
            UINT16 fl_src_a, fl_src_r, fl_src_g, fl_src_b;
            UINT16 fl_dst_p, fl_dst_a, fl_dst_r, fl_dst_g, fl_dst_b;
            UINT16 fl_blend_p, fl_blend_a, fl_blend_r, fl_blend_g, fl_blend_b;
            UINT16* fl_fb_cur_pixel_U16P = (UINT16*)p_fb_cur_pixel_ptr;
            
            fl_src_r = (UINT16)(((0xFU * ((p_src_color_rgb >> 16U) & 0xFFU)) + 127U) / 255U);
            fl_src_g = (UINT16)(((0xFU * ((p_src_color_rgb >> 8U) & 0xFFU)) + 127U) / 255U);
            fl_src_b = (UINT16)(((0xFU * ((p_src_color_rgb) & 0xFFU)) + 127U) / 255U);
            fl_src_a = (UINT16)p_src_a;

            fl_dst_p = *fl_fb_cur_pixel_U16P;
            fl_dst_a = ((fl_dst_p >> 12U) & 0xFU);

            fl_dst_r = ((((fl_dst_a) * ((fl_dst_p >> 8U) & 0xFU)) + 7U) / 15U);
            fl_dst_g = ((((fl_dst_a) * ((fl_dst_p >> 4U) & 0xFU)) + 7U) / 15U);
            fl_dst_b = ((((fl_dst_a) * ((fl_dst_p) & 0xFU)) + 7U) / 15U);

            fl_src_r = (((fl_src_a * fl_src_r) + 7U) / 15U);
            fl_src_g = (((fl_src_a * fl_src_g) + 7U) / 15U);
            fl_src_b = (((fl_src_a * fl_src_b) + 7U) / 15U);

            fl_blend_r = (((((15U - fl_src_a) * fl_dst_r) + 7U) / 15U) + fl_src_r);
            fl_blend_g = (((((15U - fl_src_a) * fl_dst_g) + 7U) / 15U) + fl_src_g);
            fl_blend_b = (((((15U - fl_src_a) * fl_dst_b) + 7U) / 15U) + fl_src_b);
            fl_blend_a = (((((15U - fl_src_a) * fl_dst_a) + 7U) / 15U) + fl_src_a);

            fl_blend_p = (UINT16)((UINT16)(fl_blend_a << 12U) | (UINT16)(fl_blend_r << 8U) | (UINT16)(fl_blend_g << 4U) | fl_blend_b);
            *fl_fb_cur_pixel_U16P = fl_blend_p;
        }
        break;
        case (UINT8)GFX_MGR02_PIX_FORMAT_RGB565:
        {
            UINT16 fl_src_a, fl_src_r, fl_src_g, fl_src_b;
            UINT16 fl_dst_p, fl_dst_r, fl_dst_g, fl_dst_b;
            UINT16 fl_blend_p, fl_blend_r, fl_blend_g, fl_blend_b;
            UINT16* fl_fb_cur_pixel_U16P = (UINT16*)p_fb_cur_pixel_ptr;
            
            fl_src_a = (UINT16)p_src_a;
            fl_dst_p = *fl_fb_cur_pixel_U16P;

            fl_dst_r = ((fl_dst_p >> 6U) & 0x1FU);
            fl_dst_g = ((fl_dst_p >> 5U) & 0x3FU);
            fl_dst_b = ((fl_dst_p) & 0x1FU);

            fl_src_r = (UINT16)(((0x1FU * ((p_src_color_rgb >> 16U) & 0xFFU)) + 127U) / 255U);
            fl_src_g = (UINT16)(((0x3FU * ((p_src_color_rgb >> 8U) & 0xFFU)) + 127U) / 255U);
            fl_src_b = (UINT16)(((0x1FU * ((p_src_color_rgb) & 0xFFU)) + 127U) / 255U);

            fl_src_r = (((fl_src_a * fl_src_r) + 127U) / 255U);
            fl_src_g = (((fl_src_a * fl_src_g) + 127U) / 255U);
            fl_src_b = (((fl_src_a * fl_src_b) + 127U) / 255U);

            fl_blend_r = (((((31U - (((0x1FU * fl_src_a) + 127U) / 255U)) * fl_dst_r) + 15U) / 31U) + fl_src_r);
            fl_blend_g = (((((63U - (((0x3FU * fl_src_a) + 127U) / 255U)) * fl_dst_g) + 31U) / 63U) + fl_src_g);
            fl_blend_b = (((((31U - (((0x1FU * fl_src_a) + 127U) / 255U)) * fl_dst_b) + 15U) / 31U) + fl_src_b);

            fl_blend_p = (UINT16)((UINT16)(fl_blend_r << 11U) | (UINT16)(fl_blend_g << 5U) | fl_blend_b);
            *fl_fb_cur_pixel_U16P = fl_blend_p;
        }
        break;
        default:
        break;
    }

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_init(void)
{
    l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_NORMAL;
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
#endif
    return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
#endif
   GFX_MGR02_UNUSED_PTR(p_cntx_SP);
   return (s_gx_flocal)1;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_finish
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
s_gx_flocal hmi_gfx_mgr02_swrlib_finish(void)
{
   return (s_gx_flocal)1;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_get_bound
Description          : Calculates the transformed bounds of a passed element
boundary
Invocation           : Invoked by gfx manager02
Parameters           : Object Type, Context and Boundary
Return Value         : Boundary
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_swrlib_get_bound(UINT32 p_obj_type, 
                                           GFX_MGR02_CONTEXT_T const * p_cntx_SP, 
                                           GFX_FLOAT * p_bounds)
{
  p_bounds[0] = (GFX_FLOAT)p_cntx_SP->state.loc.x;
  p_bounds[1] = (GFX_FLOAT)p_cntx_SP->state.loc.y;
  
  GFX_MGR02_UNUSED_VAR(p_obj_type);
  
  return((s_gx_flocal)TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_next_loc
Description          : find new offset
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static GFX_MGR02_ISIZE_W_T hmi_gfx_mgr02_swrlib_next_loc(UINT8 * const p_flag, GFX_MGR02_ISIZE_W_T p_width_offs)
{
    GFX_MGR02_ISIZE_W_T r_width_offs;
    
    if(*p_flag==1U)
    {
        if(1U == (p_width_offs%2U))
        {
          *p_flag=0;
        }
        else
        {
          *p_flag=1;
        }
        r_width_offs = ((p_width_offs/2U)+(p_width_offs%2U));
    }
    else
    {
        *p_flag = (UINT8)(p_width_offs%2U);
        r_width_offs = (p_width_offs/2U);
    }
    return(r_width_offs);
}

#ifdef GFX_MGR02_CLIPPED_WIDGETS
/****************************************************************************
Function Name        : hmi_gfx_mgr02_swrlib_clip
Description          : Perform the validation of the image to set the possible
                       area for drawing operation w.r.t active clip area.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void hmi_gfx_mgr02_swrlib_clip(GFX_MGR02_CONTEXT_T   const * p_context_SP, GFX_MGR02_CLIP_IMAGE_DATA * p_clip_image_data_SP)
{
    GFX_MGR02_ISIZE_H_T fl_y_offset;
    GFX_MGR02_ISIZE_W_T fl_x_offset;
    GFX_MGR02_ISIZE_H_T fl_y_size;
    GFX_MGR02_ISIZE_W_T fl_x_size;

    GFX_MGR02_ISIZE_X_T fl_clip_x       = p_context_SP->state.clip.sx;
    GFX_MGR02_ISIZE_Y_T fl_clip_y       = p_context_SP->state.clip.sy;
    GFX_MGR02_ISIZE_H_T fl_clip_height  = (GFX_MGR02_ISIZE_H_T)(p_context_SP->state.clip.ey - p_context_SP->state.clip.sy);
    GFX_MGR02_ISIZE_W_T fl_clip_width   = (GFX_MGR02_ISIZE_W_T)(p_context_SP->state.clip.ex - p_context_SP->state.clip.sx);
        
    p_clip_image_data_SP->x_offset = 0;
    p_clip_image_data_SP->y_offset = 0;

    if(p_clip_image_data_SP->y > fl_clip_y)
    {
        fl_y_offset = (GFX_MGR02_ISIZE_H_T)(p_clip_image_data_SP->y - fl_clip_y);
        if(fl_clip_height > fl_y_offset)
        {
            fl_y_size = (fl_clip_height - fl_y_offset);
            if(fl_y_size < p_clip_image_data_SP->h)
            {
                p_clip_image_data_SP->h = fl_y_size;
            }
        }
        else
        {
            p_clip_image_data_SP->h = 0;
        }
    }
    else
    {
        fl_y_offset = (GFX_MGR02_ISIZE_H_T)(fl_clip_y - p_clip_image_data_SP->y);
        if(fl_y_offset < p_clip_image_data_SP->h)
        {
            fl_y_size = (p_clip_image_data_SP->h-fl_y_offset);
            if(fl_y_size > fl_clip_height)
            {
                p_clip_image_data_SP->h = fl_y_offset+fl_clip_height;
            }
            p_clip_image_data_SP->y_offset = fl_y_offset;
        }
        else
        {
            p_clip_image_data_SP->h = 0;
        }
    }

    if(p_clip_image_data_SP->h != 0U)
    {
        if(p_clip_image_data_SP->x > fl_clip_x)
        {
            fl_x_offset = (GFX_MGR02_ISIZE_W_T)(p_clip_image_data_SP->x - fl_clip_x);
            if(fl_clip_width > fl_x_offset)
            {
                fl_x_size = (fl_clip_width - fl_x_offset);
                if(fl_x_size < p_clip_image_data_SP->w)
                {
                    p_clip_image_data_SP->w = fl_x_size;
                }
            }
            else
            {
                p_clip_image_data_SP->w = 0;
            }
        }
        else
        {
            fl_x_offset = (GFX_MGR02_ISIZE_W_T)(fl_clip_x - p_clip_image_data_SP->x);
            if(fl_x_offset < p_clip_image_data_SP->w)
            {
                fl_x_size = (p_clip_image_data_SP->w - fl_x_offset);
                if(fl_x_size > fl_clip_width)
                {
                    p_clip_image_data_SP->w = fl_clip_width+fl_x_offset;
                }
                p_clip_image_data_SP->x_offset = fl_x_offset;
            }
            else
            {
                p_clip_image_data_SP->w = 0;
            }
        }
    }
    p_clip_image_data_SP->x += (SINT16)p_clip_image_data_SP->x_offset;
    p_clip_image_data_SP->y += (SINT16)p_clip_image_data_SP->y_offset;
}
#endif

#if defined GFX_MGR02_COMPRESSION_ENABLED
/****************************************************************************
Function Name        : GfxDriverRLEonline
Description          : Decodes the RLE sequence and fills the
                         repeat flag  - p_rle_online->flag
                         repeat count - p_rle_online->count
                         repeat data  - p_rle_online->data
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
static void GfxDriverRLEonline(GFX_ONLINE_RLE * p_rle_online, UINT8 p_src_format_u8)
{
    p_rle_online->count = *p_rle_online->bmp_data;

    if ((p_rle_online->count & 0x80) == 0)
    {
        p_rle_online->flag = (UINT8)FALSE;
    }
    else
    {
    
        p_rle_online->count &= 0x7Fu;

        p_rle_online->flag = (UINT8)TRUE;
        p_rle_online->bmp_data++;
        switch (p_src_format_u8)
        {
        case VG_A_4:
        case VG_A_8:
            p_rle_online->data = (*p_rle_online->bmp_data);
            break;
        case VG_sRGB_565:
        case VG_sARGB_4444:
            p_rle_online->data = (*p_rle_online->bmp_data);
            p_rle_online->data = p_rle_online->data << 8U;
            p_rle_online->bmp_data++;
            p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
            break;
        case VG_sARGB_8888:
            p_rle_online->data = (*p_rle_online->bmp_data);
            p_rle_online->data = p_rle_online->data << 8U;
            p_rle_online->bmp_data++;
            p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));

            p_rle_online->data = p_rle_online->data << 8U;
            p_rle_online->bmp_data++;
            p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
            p_rle_online->data = p_rle_online->data << 8U;
            p_rle_online->bmp_data++;
            p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
            break;
        default:
            {
               /* 
                * If other formats are used, then the corresponding change has to me made.
                * So, we are not expecting the control to reach here.
                * If it reaches here then it is considered as A8 image.
                */
                p_rle_online->data = (*p_rle_online->bmp_data);
            }
            break;
        }
    }
    p_rle_online->bmp_data++;
}
/****************************************************************************
Function Name        : GfxDriverRLEonlineNLine
Description          : Skips the current RLE decode sequence by number of
                       pixels passed in p_width
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
static void GfxDriverRLEonlineNLine(GFX_ONLINE_RLE * p_rle_online, UINT8 p_src_format_u8, UINT16 p_width_u16)
{
    UINT16 fl_width_u16 = p_width_u16;
    while (fl_width_u16 > (UINT16)0)
    {
        if (p_rle_online->count == (UINT8)0)
        {
            GfxDriverRLEonline(p_rle_online, p_src_format_u8);
        }
        if ((UINT16)p_rle_online->count >= fl_width_u16)
        {
            if (p_rle_online->flag == (UINT8)FALSE)
            {
                switch (p_src_format_u8)
                {
                    case VG_A_4:
                    case VG_A_8:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[fl_width_u16];
                        break;
                    case VG_sRGB_565:
                    case VG_sARGB_4444:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[fl_width_u16* (UINT16)2];
                        break;
                    case VG_sARGB_8888:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[(fl_width_u16* (UINT16)4)];
                        break;
                     default:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[fl_width_u16];
                        break;
                }
            }
            p_rle_online->count -= (UINT8)fl_width_u16;
            fl_width_u16 = (UINT16)0;
        }
        else
        {
            fl_width_u16 -= (UINT16)p_rle_online->count;
            if (p_rle_online->flag == (UINT8)FALSE)
            {
                switch (p_src_format_u8)
                {
                    case VG_A_4:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[p_rle_online->count];
                        break;
                    case VG_A_8:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[p_rle_online->count];
                        break;
                    case VG_sRGB_565:
                    case VG_sARGB_4444:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[(p_rle_online->count * (UINT16)2)];
                        break;
                    case VG_sARGB_8888:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[(p_rle_online->count* (UINT16)4)];
                        break;
                    default:
                        p_rle_online->bmp_data = &p_rle_online->bmp_data[p_rle_online->count];
                        break;
                }
            }
            p_rle_online->count = (UINT8)0;
        }
    }
}

#endif


#ifdef  __cplusplus
}
#endif

#endif /* #if defined(GFX_MGR02_SOFTWARE) */

 /****************************************************************************
 ** C M S    R E V I S I O N    N O T E S
 *****************************************************************************
 **
 ** For each change to this file, be sure to record:
 ** 1.  Who made the change and when the change was made.
 ** 2.  Why the change was made and the intended result.
 **
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 *****************************************************************************
 **
 ** CMS Rev 1.4     05-June-2020    SSIGAMAN
 ** 1443164: SWLib: Software RLE compression support.
 **
 ** CMS Rev 1.3     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 1.2      03-Apr-2013    ASHEKHAR/YSREEMAN
 ** Resolved QAC warnings.
 **
 ** CMS Rev 1.1      15-Mar-2012    ASHEKHAR
 ** Resolved issue with respect to default matrix. OpenVG origin is at bottom
 **
 ** CMS Rev 1.0      09-Aug-2012    YSREEMAN
 ** Creation.
 ***************************************************************************/


 /************************** End of Module *********************************/
