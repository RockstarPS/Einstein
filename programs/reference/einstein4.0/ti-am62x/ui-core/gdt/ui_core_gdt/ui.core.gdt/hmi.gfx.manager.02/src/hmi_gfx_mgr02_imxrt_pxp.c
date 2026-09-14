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
** Name:           hmi_gfx_mgr02_imxrt_pxp.c
**
** Description:    Building Graphics element using IMXRT PXP driver API
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#define HMI_GFX_MGR02_IMXRT_PXP_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_IMXRT_PXP)

#include "hmi_gfx_mgr02_imxrt.h"
#include "hmi_gfx_mgr02_context.h"
#ifdef GFX02_DEBUG_INFO
#include "fsl_debug_console.h"
#endif
#include "hmi_gfx_mgr02_imxrt_pxp.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "hmi_gfx_mgr02_cache.h"

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
#include "hmi_gfx_mgr02_sw_compression.h"
#endif

#ifdef  __cplusplus
extern "C" {
#endif

//#define USE_IMXRT_PXP_QUEUE

#define GFX_MGR02_IMXRT_FLUSH_PENDING     (0x01U)
#define GFX_MGR02_IMXRT_FB_UPDATED        (0x02U)

#define GFX_MGR02_IMXRT_NO_FLUSH_PENDING     (0xFEU)

  /*============================================================================
  ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
  **==========================================================================*/
#define PXP_ID PXP

#define GM2_IMXRT_R(argb)  ((UINT8)(((argb) >> 16UL) & (UINT32)0xFF))
#define GM2_IMXRT_G(argb)  ((UINT8)(((argb) >>  8UL) & (UINT32)0xFF))
#define GM2_IMXRT_B(argb)  ((UINT8)(argb))
#define GM2_IMXRT_A(argb)  ((UINT8)((argb)>> 24UL))

#define MAX_NO_OF_PXP_COMMAND_BUFFER      2

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/


static void hmi_gfx_mgr02_imxrt_pxp_blt(void);
static void hmi_gfx_mgr02_imxrt_pxp_get_character_buf(UINT8 * p_char_alphadata,
                                                      UINT32 * p_char_argb_data,
                                                      UINT32 p_fg_color,
                                                      UINT32 p_char_width,
                                                      UINT32 p_char_height);
static pxp_ps_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(u_gx_flocal p_pix_format);
static UINT32 hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(pxp_ps_pixel_format_t p_format);
static UINT32 hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(pxp_as_pixel_format_t p_format);
#if defined(GFX_PERFORMANCE_MEASUREMENT)
extern UINT32 hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(UINT32 fl_end_time, UINT32 fl_start_time);
extern UINT32 hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count(void);
#endif
#if !defined(GFX_MGR02_IMXRT)	
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void);
#endif
static pxp_as_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(u_gx_flocal p_pix_format);
static void draw_windows_bmp_string(SINT16 x, GFX_MGR02_CONTEXT_T  const *p_cntx_SP,
                                    HMI_CHAR const * p_string_p,
                                    GFX_MGR02_FONT const * p_font_SP, UINT32 p_fg_color, UINT32 p_str_length);

/*=============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

typedef struct _pxp_command
{
  UINT32 CTRL;
  UINT32 STAT;
  UINT32 OUT_CTRL;
  UINT32 OUT_BUF;
  UINT32 OUT_BUF2;
  UINT32 OUT_PITCH;
  UINT32 OUT_LRC;
  UINT32 OUT_PS_ULC;
  UINT32 OUT_PS_LRC;
  UINT32 OUT_AS_ULC;
  UINT32 OUT_AS_LRC;
  UINT32 PS_CTRL;
  UINT32 PS_BUF;
  UINT32 PS_UBUF;
  UINT32 PS_VBUF;
  UINT32 PS_PITCH;
  UINT32 PS_BACHGROUND;
  UINT32 PS_SCALE;
  UINT32 PS_OFFSET;
  UINT32 PS_CLRKEYLOW;
  UINT32 PS_CLRKEYHIGH;
  UINT32 AS_CTRL;
  UINT32 AS_BUF;
  UINT32 AS_PITCH;
  UINT32 AS_CLRKEYLOW;
  UINT32 AS_CLRKEYHIGH;
  UINT32 CSC1_COEF0;
  UINT32 CSC1_COEF1;
  UINT32 CSC1_COEF2;
#if !(defined(FSL_FEATURE_PXP_HAS_NO_CSC2) && FSL_FEATURE_PXP_HAS_NO_CSC2)
  UINT32 CSC2_CTRL;
  UINT32 CSC2_COEF0;
  UINT32 CSC2_COEF1;
  UINT32 CSC2_COEF2;
  UINT32 CSC2_COEF3;
  UINT32 CSC2_COEF4;
  UINT32 CSC2_COEF5;
#else
  UINT32 CSC2_RESERVE[7];
#endif
#if !(defined(FSL_FEATURE_PXP_HAS_NO_LUT) && FSL_FEATURE_PXP_HAS_NO_LUT)
  UINT32 LUT_CTRL;
  UINT32 LUT_ADDR;
  UINT32 LUT_DATA;
  UINT32 LUT_EXTMEM;
  UINT32 CFA;
#else
  UINT32 LUT_RESERVE[5];
#endif
  UINT32 HIST_CTRL;
  UINT32 HIST2_PARAM;
  UINT32 HIST4_PARAM;
  UINT32 HIST8_PARAM0;
  UINT32 HIST8_PARAM1;
  UINT32 HIST16_PARAM0;
  UINT32 HIST16_PARAM1;
  UINT32 HIST16_PARAM2;
  UINT32 HIST16_PARAM3;
  UINT32 POWER;
  UINT32 NEXT;
} pxp_command_t;

static  UINT8   l_imxrt_draw_sts;
static  volatile UINT8          l_gfx_mgr_shutdown_status;

static UINT32 l_char_argb_buf[2][GFX_MGRO02_FONT_CHARBUF_MAX_SIZE];

#ifdef USE_IMXRT_PXP_QUEUE
static pxp_command_t l_pxp_command_buffer[MAX_NO_OF_PXP_COMMAND_BUFFER];
static UINT8 l_pxp_command_buffer_index = 0;
#endif
/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_init
Description          : Initializes the library internal variables
Invocation           : 
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_init(void)
{
  l_imxrt_draw_sts = (UINT8)0;
#ifdef USE_IMXRT_PXP_QUEUE
  l_pxp_command_buffer_index = 0;
#endif
#if !defined(GFX_MGR02_IMXRT)
  l_gfx_mgr_shutdown_status = GFX_MGR02_SHUTDOWN_NORMAL;
#endif
  PXP_Init(PXP_ID);
  PXP_EnableCsc1(PXP_ID, false);     /* Disable CSC1, it is enabled by default. */
  PXP_SetProcessBlockSize(PXP_ID, kPXP_BlockSize16); /* Block size 16x16 for higher performance */
  return((s_gx_flocal)TRUE);
}
#if !defined(GFX_MGR02_IMXRT)
/*============================================================================
** Function Name:    hmi_gfx_mgr02_is_emergency_shutdown_req_active
** Visibility:       Global
** Description:      Sets the shutdown mode type.
** Invocation:       By 
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          05-Sep-2014
** Updated:          05-Sep-2014
**==========================================================================*/
static UINT8 hmi_gfx_mgr02_is_emergency_shutdown_req_active(void)
{
  return (l_gfx_mgr_shutdown_status);
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_start
Description          : Initializes the library internal variables
Invocation           : 
Parameters           : GFX_MGR02_CONTEXT_T
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{

  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

  if(GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
  {
    l_imxrt_draw_sts = (UINT8)0;
  }
  GFX_MGR02_UNUSED_PTR(p_cntx_SP);
  return(TRUE);
}
#ifdef USE_IMXRT_PXP_QUEUE
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
pxp_command_t * hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer(void)
{
  return &l_pxp_command_buffer[l_pxp_command_buffer_index];
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_blt
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_imxrt_pxp_blt(void)
{
  #ifdef USE_IMXRT_PXP_QUEUE
  pxp_command_t * fl_pxp_comm_buff = hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer();
  while (PXP_IsNextCommandPending(PXP_ID))
  {
  }
  PXP_ClearStatusFlags(PXP_ID, kPXP_CompleteFlag);
  PXP_SetNextCommand(PXP_ID, fl_pxp_comm_buff);
  l_pxp_command_buffer_index++;
  if(l_pxp_command_buffer_index == MAX_NO_OF_PXP_COMMAND_BUFFER)
  {
     l_pxp_command_buffer_index = 0;
  }
  l_imxrt_draw_sts = (GFX_MGR02_IMXRT_FLUSH_PENDING|GFX_MGR02_IMXRT_FB_UPDATED);
  #else
  PXP_Start(PXP_ID);
  /* Wait for process complete. */
  while (!(kPXP_CompleteFlag & PXP_GetStatusFlags(PXP_ID)))
  {

  }
  PXP_ClearStatusFlags(PXP_ID, kPXP_CompleteFlag);
  l_imxrt_draw_sts = (GFX_MGR02_IMXRT_FLUSH_PENDING|GFX_MGR02_IMXRT_FB_UPDATED);
  #endif
}



#ifdef USE_IMXRT_PXP_QUEUE
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_build_image
Description          : Build the image object of the merge widget.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_image().
Parameters           : GFX_MGR02_CONTEXT_T , GFX_MGR02_IMAGE_DEF_T
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_image(GFX_MGR02_CONTEXT_T  const *p_cntx_SP , GFX_MGR02_IMAGE_DEF_T  const *p_elem_def_SP)
{
  UINT32   fl_fg_color;
  UINT32   fl_alpha_temp;
  UINT32   fl_rle_words;
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  UINT32 fl_start_time;
  UINT32 fl_end_time;
  UINT32 fl_time_in_msec;
#endif

  void *   vImgAddr;
  UINT8    fl_rgba[4];
  UINT8    fl_shutdown_state;
  UINT16   fl_clip_w;
  UINT16   fl_clip_h;
  UINT32 fl_out_bpp_size;
  UINT32 fl_ps_bpp_size;
  UINT32 fl_as_bpp_size;
  UINT32 fl_out_fb_format;
  UINT32 fl_as_fb_format;
  UINT32 fl_ps_fb_format;
  pxp_porter_duff_config_t pdConfig;
  s_gx_flocal fl_return_value=(s_gx_flocal)FALSE;
  void *   fl_dest_ptr;

  vImgAddr  = (void*)p_elem_def_SP->pixel_data;

#if defined(GFX_PERFORMANCE_MEASUREMENT)
  fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
#endif
  /*
  ** 1. Create the surface object for the image and assign the image data to the surface.
  ** 2. Assign the CLUT if any.
  ** 3. Bind the surface to the passed pixel engine context
  */
  fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy))
  {
      if(p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
      {
          fl_ps_fb_format =  p_elem_def_SP->format;
          fl_ps_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(p_elem_def_SP->format);
          fl_as_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(p_cntx_SP->rprop.fb_format);
          fl_as_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(fl_as_fb_format);

      }
      else
      {
          fl_ps_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(p_cntx_SP->rprop.fb_format);
          fl_ps_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(fl_ps_fb_format);
          /* AS buffer - source image */
          fl_as_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(p_elem_def_SP->format);


      }
      fl_out_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
      fl_out_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);

      fl_dest_ptr = (UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)p_cntx_SP->state.clip.sy * (fl_out_bpp_size/8)) + ((UINT32)p_cntx_SP->state.clip.sx* (fl_out_bpp_size/8));
      vImgAddr  = (UINT32)vImgAddr + ((UINT32)p_elem_def_SP->width * (UINT32)(p_cntx_SP->state.clip.sy - p_cntx_SP->state.loc.y) * (fl_as_bpp_size/8)) + ((UINT32)(p_cntx_SP->state.clip.sx - p_cntx_SP->state.loc.x)* (fl_as_bpp_size/8));

      pxp_command_t * fl_pxp_comm_buff = hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer();


      fl_clip_w = p_cntx_SP->state.clip.ex - p_cntx_SP->state.clip.sx;
      fl_clip_h = p_cntx_SP->state.clip.ey-p_cntx_SP->state.clip.sy;
      fl_pxp_comm_buff->CTRL       = PXP_CTRL_ROT_POS(0) | PXP_CTRL_ENABLE_MASK| PXP_CTRL_NEXT_IRQ_ENABLE_MASK|PXP_CTRL_IRQ_ENABLE_MASK |PXP_CTRL_BLOCK_SIZE(kPXP_BlockSize16);
      fl_pxp_comm_buff->STAT       = 0x00000000;                              /* STAT, don't care */
      fl_pxp_comm_buff->OUT_CTRL   = PXP_OUT_CTRL_FORMAT(fl_out_fb_format)|PXP_OUT_CTRL_INTERLACED_OUTPUT(kPXP_OutputProgressive); /* OUT_CTRL */
      if(p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
      {
        fl_pxp_comm_buff->OUT_BUF    = (UINT32)fl_dest_ptr;                                             /* OUT_BUF */
      }
      else
      {
        fl_pxp_comm_buff->OUT_BUF    = (UINT32)vImgAddr;                                             /* OUT_BUF */
      }
      fl_pxp_comm_buff->OUT_BUF2   = 0x00000000;                                                      /* OUT_BUF2 */
      fl_pxp_comm_buff->OUT_PITCH  = p_cntx_SP->rprop.fb_w * (fl_out_bpp_size/8);                     /* OUT_PITCH */
      fl_pxp_comm_buff->OUT_LRC    = PXP_OUT_LRC_Y(fl_clip_h -1) | PXP_OUT_LRC_X(fl_clip_w -1);       /* OUT_LRC */
      fl_pxp_comm_buff->OUT_PS_ULC = PXP_OUT_PS_ULC_Y(0) | PXP_OUT_PS_ULC_X(0);                       /* OUT_PS_ULC */
      fl_pxp_comm_buff->OUT_PS_LRC = PXP_OUT_PS_LRC_Y(fl_clip_h -1) | PXP_OUT_PS_LRC_X(fl_clip_w -1); /* OUT_PS_LRC */
      /* Disable AS. */
      fl_pxp_comm_buff->OUT_AS_ULC    = PXP_OUT_AS_ULC_Y(0) | PXP_OUT_AS_ULC_X(0);                            /* OUT_AS_ULC */
      fl_pxp_comm_buff->OUT_AS_LRC    = PXP_OUT_AS_LRC_Y(fl_clip_h -1) | PXP_OUT_AS_LRC_X(fl_clip_w -1);      /* OUT_AS_LRC */

      fl_pxp_comm_buff->PS_CTRL       = PXP_PS_CTRL_FORMAT(fl_ps_fb_format);          /* PS_CTRL */
      fl_pxp_comm_buff->PS_UBUF       = 0x00000000;                                   /* PS_UBUF */
      fl_pxp_comm_buff->PS_VBUF       = 0x00000000;                                   /* PS_VBUF */
      if(p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
      {
        fl_pxp_comm_buff->PS_PITCH  = p_elem_def_SP->width *(fl_ps_bpp_size/8);               /* OUT_PITCH */
        fl_pxp_comm_buff->PS_BUF    = (UINT32)vImgAddr;                                    /* PS_BUF */        
        fl_pxp_comm_buff->AS_BUF    = fl_dest_ptr;                                         /* AS_BUF */

      }
      else
      {      
        fl_pxp_comm_buff->PS_PITCH      = p_cntx_SP->rprop.fb_w * (fl_out_bpp_size/8);  /* PS_PITCH */
        fl_pxp_comm_buff->PS_BUF        = (UINT32)fl_dest_ptr;                          /* PS_BUF */        
        fl_pxp_comm_buff->AS_BUF        = vImgAddr;                                     /* AS_BUF */
      }  
      fl_pxp_comm_buff->PS_BACHGROUND = 0x00000000;                                   /* PS_BACHGROUND */
      fl_pxp_comm_buff->PS_SCALE      = 0x10001000;                                   /* PS_SCALE */
      fl_pxp_comm_buff->PS_OFFSET     = 0x00000000;                                   /* PS_OFFSET */
      fl_pxp_comm_buff->PS_CLRKEYLOW  = 0x00FFFFFF;                                   /* PS_CLRKEYLOW */
      fl_pxp_comm_buff->PS_CLRKEYHIGH = 0x00000000;                                   /* PS_CLRKEYHIGH */
      fl_pxp_comm_buff->AS_CTRL       = PXP_AS_CTRL_FORMAT(p_elem_def_SP->format)|PXP_AS_CTRL_ROP(kPXP_RopMaskAs)|PXP_AS_CTRL_ALPHA(p_cntx_SP->state.alpha)|PXP_AS_CTRL_ALPHA_CTRL(kPXP_AlphaMultiply); /* AS_CTRL */

      fl_pxp_comm_buff->AS_PITCH      = p_elem_def_SP->width *(fl_as_bpp_size/8);     /* AS_PITCH */
      if(p_elem_def_SP->chroma_key !=0U)
      {			
        fl_pxp_comm_buff->AS_CLRKEYLOW  = p_cntx_SP->rprop.fg_color;                  /* AS_CLRKEYLOW */
        fl_pxp_comm_buff->AS_CLRKEYHIGH = p_cntx_SP->rprop.fg_color;                  /* AS_CLRKEYHIGH */
      }
      else			
      {
        fl_pxp_comm_buff->AS_CLRKEYLOW  = 0x00FFFFFF;                            /* AS_CLRKEYLOW */
        fl_pxp_comm_buff->AS_CLRKEYHIGH = 0x00000000;                            /* AS_CLRKEYHIGH */

      }
      if(p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
      {

          fl_pxp_comm_buff->CSC1_COEF0 = PXP_CSC1_COEF0_YCBCR_MODE(0x0U) | PXP_CSC1_COEF0_BYPASS(0x1U)
                                                                | PXP_CSC1_COEF0_C0(0x100U)
                                                                | PXP_CSC1_COEF0_Y_OFFSET(0x0U)
                                                                | PXP_CSC1_COEF0_UV_OFFSET(0x0U);

          fl_pxp_comm_buff->CSC1_COEF1 = PXP_CSC1_COEF1_C1(0x0123U)        /* 1.140. */
                                                                | PXP_CSC1_COEF1_C4(0x0208U);     /* 2.032. */
          fl_pxp_comm_buff->CSC1_COEF2 = PXP_CSC1_COEF2_C2(0x076BU)        /* -0.851. */
                                                                | PXP_CSC1_COEF2_C3(0x079BU);     /* -0.394. */
      }
      else
      {
          fl_pxp_comm_buff->CSC1_COEF0    = 0x00000000;            /* CSC1_COEF0, don't care. */
          fl_pxp_comm_buff->CSC1_COEF1    = 0x00000000;                            /* CSC1_COEF1, don't care. */
          fl_pxp_comm_buff->CSC1_COEF2    = 0x00000000;                            /* CSC1_COEF2, don't care. */

      }
#if !(defined(FSL_FEATURE_PXP_HAS_NO_CSC2) && FSL_FEATURE_PXP_HAS_NO_CSC2)
      fl_pxp_comm_buff->CSC2_CTRL  = PXP_CSC2_CTRL_BYPASS_MASK; /* CSC2_CTRL */
      fl_pxp_comm_buff->CSC2_COEF0 = 0x00000000;                /* CSC2_COEF0, don't care. */
      fl_pxp_comm_buff->CSC2_COEF1 = 0x00000000;                /* CSC2_COEF1, don't care. */
      fl_pxp_comm_buff->CSC2_COEF2 = 0x00000000;                /* CSC2_COEF2, don't care. */
      fl_pxp_comm_buff->CSC2_COEF3 = 0x00000000;                /* CSC2_COEF3, don't care. */
      fl_pxp_comm_buff->CSC2_COEF4 = 0x00000000;                /* CSC2_COEF4, don't care. */
      fl_pxp_comm_buff->CSC2_COEF5 = 0x00000000;                /* CSC2_COEF5, don't care. */
#endif
#if !(defined(FSL_FEATURE_PXP_HAS_NO_LUT) && FSL_FEATURE_PXP_HAS_NO_LUT)
      fl_pxp_comm_buff->LUT_CTRL   = PXP_LUT_CTRL_BYPASS_MASK; /* LUT_CTRL */
      fl_pxp_comm_buff->LUT_ADDR   = 0x00000000;               /* LUT_ADDR */
      fl_pxp_comm_buff->LUT_DATA   = 0x00000000;               /* LUT_DATA */
      fl_pxp_comm_buff->LUT_EXTMEM = 0x00000000;               /* LUT_EXTMEM */
      fl_pxp_comm_buff->CFA        = 0x00000000;               /* CFA */
#endif
      fl_pxp_comm_buff->HIST_CTRL     = 0x00000020;            /* HIST_CTRL */
      fl_pxp_comm_buff->HIST2_PARAM   = 0x00000F00;            /* HIST2_PARAM */
      fl_pxp_comm_buff->HIST4_PARAM   = 0x0F0A0500;            /* HIST4_PARAM */
      fl_pxp_comm_buff->HIST8_PARAM0  = 0x06040200;            /* HIST8_PARAM0 */
      fl_pxp_comm_buff->HIST8_PARAM1  = 0x0F0D0B09;            /* HIST8_PARAM1 */
      fl_pxp_comm_buff->HIST16_PARAM0 = 0x03020100;            /* HIST16_PARAM0 */
      fl_pxp_comm_buff->HIST16_PARAM1 = 0x07060504;            /* HIST16_PARAM1 */
      fl_pxp_comm_buff->HIST16_PARAM2 = 0x0B0A0908;            /* HIST16_PARAM2 */
      fl_pxp_comm_buff->HIST16_PARAM3 = 0x0F0E0D0C;            /* HIST16_PARAM3 */
      fl_pxp_comm_buff->POWER         = 0x00000000;            /* POWER */
      fl_pxp_comm_buff->NEXT          = 0x00000000;            /* NEXT, don't care */ 

      /* Output buffer. */
      hmi_gfx_mgr02_imxrt_pxp_blt();
#if defined(GFX_PERFORMANCE_MEASUREMENT)
    fl_end_time     = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
    fl_time_in_msec = hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_end_time,fl_start_time);
#ifdef GFX_DEBUG_INFO
    PRINTF("\r\n Build image %08X %d \r\n",p_elem_def_SP, fl_time_in_msec);
#endif
#endif
  }
#ifdef GFX02_DEBUG_INFO
  else
  {
    gfx_debug("PXP for Imxrt - Image elem =%08X skipped\n", p_elem_def_SP);
  }
#endif

  fl_return_value = (s_gx_flocal)TRUE;
  return(fl_return_value);

}
#else
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_build_image
Description          : Build the image object of the merge widget.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_image().
Parameters           : GFX_MGR02_CONTEXT_T , GFX_MGR02_IMAGE_DEF_T
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_image(GFX_MGR02_CONTEXT_T  const* p_cntx_SP, GFX_MGR02_IMAGE_DEF_T  const* p_elem_def_SP)
{
    #if defined(GFX_PERFORMANCE_MEASUREMENT)
    UINT32 fl_start_time;
    UINT32 fl_end_time;
    UINT32 fl_time_in_msec;
    #endif
    UINT8    fl_shutdown_state;
    UINT32   fl_bpp_size;
    void*    fl_dest_ptr;
    UINT32   fl_fg_color;
    void*    vImgAddr = NULL;

    pxp_output_pixel_format_t fl_out_fb_format;
    pxp_as_pixel_format_t     fl_as_fb_format;
    pxp_ps_pixel_format_t     fl_ps_fb_format;
  
    s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;

    if ((pxp_ps_pixel_format_t)p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
    {
        PXP_EnableCsc1(PXP_ID, true);
        PXP_SetCsc1Mode(PXP_ID, kPXP_Csc1YCbCr2RGB);
    }
    else
    {
        PXP_EnableCsc1(PXP_ID, false);     /* Disable CSC1, it is enabled by default. */
    }
    PXP_SetProcessBlockSize(PXP, kPXP_BlockSize16); /* Block size 16x16 for higher performance */

    #if defined(GFX_PERFORMANCE_MEASUREMENT)
    fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
    #endif
    
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
        pxp_output_buffer_config_t  outputBufferConfig;
        pxp_as_buffer_config_t      asBufferConfig;
        pxp_porter_duff_config_t    pdConfig;

        UINT16 fl_clip_w;
        UINT16 fl_clip_h;

        GFX_MGR02_VISIBLE_AREA fl_curr_clip;
        GFX_MGR02_VISIBLE_AREA fl_new_clip;

        fl_curr_clip.sx = p_cntx_SP->state.clip.sx;
        fl_curr_clip.sy = p_cntx_SP->state.clip.sy;
        fl_curr_clip.ex = p_cntx_SP->state.clip.ex;
        fl_curr_clip.ey = p_cntx_SP->state.clip.ey;

        fl_new_clip.sx = p_cntx_SP->state.loc.x;
        fl_new_clip.sy = p_cntx_SP->state.loc.y;
        fl_new_clip.ex = fl_new_clip.sx + (SINT16)p_elem_def_SP->width;
        fl_new_clip.ey = fl_new_clip.sy + (SINT16)p_elem_def_SP->height;

        (void)hmi_gfx_mgr02_context_validate_clip(&fl_curr_clip, &fl_new_clip);
        fl_clip_w = fl_curr_clip.ex - fl_curr_clip.sx;
        fl_clip_h = fl_curr_clip.ey - fl_curr_clip.sy;

        #if defined(GFX_MGR02_COMPRESSION_ENABLED)
        if ((p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_SWRLE) && (p_elem_def_SP->comp_size > 0UL))
        {     
            void * fl_frame_buff_ptr = hmi_gfx_mgr02_context_get_sw_decompr_buffer();
            if (fl_frame_buff_ptr != GFX_MGR02_NULL_PTR)
            {
                if ((pxp_as_pixel_format_t)p_elem_def_SP->format == kPXP_AsPixelFormatARGB4444)
                {
                    hmi_gfx_mgr02_comp_decompr_16bpp(p_elem_def_SP, &((UINT16*)fl_frame_buff_ptr)[0]);
                    vImgAddr = fl_frame_buff_ptr;
                }
                else if ((pxp_as_pixel_format_t)p_elem_def_SP->format == kPXP_AsPixelFormatARGB8888)
                {
                    hmi_gfx_mgr02_comp_decompr_32bpp(p_elem_def_SP, &((UINT32*)fl_frame_buff_ptr)[0]);
                    vImgAddr = fl_frame_buff_ptr;
                }
                else
                { 
                    vImgAddr = (void*)p_elem_def_SP->pixel_data;
                }
            }
        }
        else
        #endif
        {
            vImgAddr = (void*)p_elem_def_SP->pixel_data;
        }
        
        if (vImgAddr != NULL)
        {
            if (p_elem_def_SP->format == kPXP_AsPixelFormatIndex8BPP)
            {
                /* Disable PS */
                PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U);
                PXP_SetProcessSurfaceBackGroundColor(PXP_ID, 0);

                fl_as_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(p_elem_def_SP->format);
                fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(fl_as_fb_format);
                asBufferConfig.pixelFormat = fl_as_fb_format;
                asBufferConfig.bufferAddr = (UINT32)vImgAddr;
                asBufferConfig.pitchBytes = p_elem_def_SP->width;

                PXP_SetAlphaSurfaceBufferConfig(PXP_ID, &asBufferConfig);
                PXP_SetAlphaSurfacePosition(PXP_ID, 0, 0, (fl_clip_w / 2U) - 1U, fl_clip_h - 1U);

                fl_dest_ptr = (void*)((UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_curr_clip.sy) + ((UINT32)fl_curr_clip.sx));

                /* Output buffer. */
                fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
                fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
                outputBufferConfig.pixelFormat = fl_out_fb_format;
                outputBufferConfig.interlacedMode = kPXP_OutputProgressive;
                outputBufferConfig.buffer0Addr = (UINT32)fl_dest_ptr;
                outputBufferConfig.buffer1Addr = (UINT32)0U;
                outputBufferConfig.pitchBytes = p_cntx_SP->rprop.fb_w;
                outputBufferConfig.width = p_elem_def_SP->width / (fl_bpp_size / 8U);
                outputBufferConfig.height = p_elem_def_SP->height;
                PXP_SetOutputBufferConfig(PXP_ID, &outputBufferConfig);

                /* Configure SRC OVER Porter-Duff blending */
                pdConfig.enable = 1;
                pdConfig.dstFactorMode = kPXP_PorterDuffFactorInversed;
                pdConfig.srcFactorMode = kPXP_PorterDuffFactorOne;
                pdConfig.srcColorMode = kPXP_PorterDuffColorInversed;
                pdConfig.dstColorMode = kPXP_PorterDuffColorStraight;
                pdConfig.srcGlobalAlphaMode = kPXP_PorterDuffScaledAlpha;
                pdConfig.dstGlobalAlphaMode = kPXP_PorterDuffLocalAlpha;
                pdConfig.dstAlphaMode = kPXP_PorterDuffAlphaStraight;
                pdConfig.srcAlphaMode = kPXP_PorterDuffAlphaStraight;
                pdConfig.dstGlobalAlpha = 0U;
                pdConfig.srcGlobalAlpha = p_cntx_SP->state.alpha;
                PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
    
                hmi_gfx_mgr02_imxrt_pxp_blt();
    
                pdConfig.enable = 0;
                PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
            }
            else
            {
                if ((pxp_ps_pixel_format_t)p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
                {
                    void* fl_y_ptr = vImgAddr;
                    void* fl_u_ptr = (void*)((UINT32)vImgAddr + (p_elem_def_SP->height * p_elem_def_SP->width));
                    void* fl_v_ptr = (void*)((UINT32)vImgAddr + (p_elem_def_SP->height * p_elem_def_SP->width) + ((p_elem_def_SP->height * p_elem_def_SP->width) / 4U));

                    /* use process surface for input image or video frame */
                    fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp((pxp_ps_pixel_format_t)p_elem_def_SP->format);
                    pxp_ps_buffer_config_t psBufferConfig = {
                      .pixelFormat = (pxp_ps_pixel_format_t)p_elem_def_SP->format,
                      .swapByte = false,
                      .bufferAddr = ((UINT32)fl_y_ptr + ((UINT32)p_elem_def_SP->width * (UINT32)(fl_curr_clip.sy - p_cntx_SP->state.loc.y) * (fl_bpp_size / 8U)) + ((UINT32)(fl_curr_clip.sx - p_cntx_SP->state.loc.x) * (fl_bpp_size / 8U))),
                      .bufferAddrU = ((UINT32)fl_u_ptr + ((UINT32)p_elem_def_SP->width * (UINT32)(fl_curr_clip.sy - p_cntx_SP->state.loc.y) * (fl_bpp_size / 32U)) + ((UINT32)(fl_curr_clip.sx - p_cntx_SP->state.loc.x) * (fl_bpp_size / 32U))),
                      .bufferAddrV = ((UINT32)fl_v_ptr + ((UINT32)p_elem_def_SP->width * (UINT32)(fl_curr_clip.sy - p_cntx_SP->state.loc.y) * (fl_bpp_size / 32U)) + ((UINT32)(fl_curr_clip.sx - p_cntx_SP->state.loc.x) * (fl_bpp_size / 32U))),
                      .pitchBytes = p_elem_def_SP->width * (fl_bpp_size / 8U),
                    };
                    PXP_SetProcessSurfaceBufferConfig(PXP_ID, &psBufferConfig);

                    /* Disable AS */
                    fl_as_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(p_cntx_SP->rprop.fb_format);
                    fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(fl_as_fb_format);
                    fl_dest_ptr = (void*)((UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_curr_clip.sy * (fl_bpp_size / 8U)) + ((UINT32)fl_curr_clip.sx * (fl_bpp_size / 8U)));
                    PXP_SetAlphaSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U);

                    PXP_EnableOverWrittenAlpha(PXP_ID, true);
                    PXP_SetOverwrittenAlphaValue(PXP_ID, 255U);
                }
                else
                {
                    /* use alpha surface for input image */
                    fl_ps_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(p_cntx_SP->rprop.fb_format);
                    fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(fl_ps_fb_format);
                    fl_dest_ptr = (void*)((UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_curr_clip.sy * (fl_bpp_size / 8U)) + ((UINT32)fl_curr_clip.sx * (fl_bpp_size / 8U)));

                    pxp_ps_buffer_config_t psBufferConfig = {
                      .pixelFormat = fl_ps_fb_format,
                      .swapByte = false,
                      .bufferAddr = (UINT32)fl_dest_ptr,
                      .bufferAddrU = 0U,
                      .bufferAddrV = 0U,
                      .pitchBytes = p_cntx_SP->rprop.fb_w * (fl_bpp_size / 8U),
                    };
                    PXP_SetProcessSurfaceBufferConfig(PXP_ID, &psBufferConfig);

                    /* Alpha blending or color keying enabled - PS must be enabled to fetch background pixels
                    PS and OUT buffers are the same, blend will be done in-place */

                    /* AS buffer for source image */

                    fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp((pxp_as_pixel_format_t)p_elem_def_SP->format);
                    asBufferConfig.pixelFormat = (pxp_as_pixel_format_t)p_elem_def_SP->format;
                    asBufferConfig.bufferAddr = (UINT32)vImgAddr + ((UINT32)p_elem_def_SP->width * (UINT32)(fl_curr_clip.sy - p_cntx_SP->state.loc.y) * (fl_bpp_size / 8U)) + ((UINT32)(fl_curr_clip.sx - p_cntx_SP->state.loc.x) * (fl_bpp_size / 8U));
                    asBufferConfig.pitchBytes = p_elem_def_SP->width * (fl_bpp_size / 8U);

                    PXP_SetAlphaSurfaceBufferConfig(PXP_ID, &asBufferConfig);
                    PXP_SetAlphaSurfacePosition(PXP_ID, 0, 0, (fl_clip_w - 1U), (fl_clip_h - 1U));

                    /* Configure SRC OVER Porter-Duff blending */
                    (void)memset(&pdConfig, 0, sizeof(pxp_porter_duff_config_t));
                    pdConfig.enable = 1;
                    pdConfig.dstFactorMode = kPXP_PorterDuffFactorInversed;
                    pdConfig.srcFactorMode = kPXP_PorterDuffFactorOne;
                    pdConfig.srcColorMode = kPXP_PorterDuffColorInversed;
                    pdConfig.dstColorMode = kPXP_PorterDuffColorStraight;
                    pdConfig.srcGlobalAlphaMode = kPXP_PorterDuffScaledAlpha;
                    pdConfig.dstGlobalAlphaMode = kPXP_PorterDuffLocalAlpha;
                    pdConfig.dstAlphaMode = kPXP_PorterDuffAlphaStraight;
                    pdConfig.srcAlphaMode = kPXP_PorterDuffAlphaStraight;
                    pdConfig.dstGlobalAlpha = 0U;
                    pdConfig.srcGlobalAlpha = p_cntx_SP->state.alpha;
                    PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
                }

                PXP_SetProcessSurfaceBackGroundColor(PXP_ID, 0U);
                PXP_SetProcessSurfacePosition(PXP_ID, 0, 0, (fl_clip_w - 1U), (fl_clip_h - 1U));

                fl_fg_color = p_cntx_SP->rprop.fg_color;
                if (p_elem_def_SP->chroma_key != 0U)
                {
                    PXP_SetAlphaSurfaceOverlayColorKey(PXP_ID, fl_fg_color, fl_fg_color);
                }
                PXP_EnableAlphaSurfaceOverlayColorKey(PXP_ID, p_elem_def_SP->chroma_key);

                /* Output buffer. */
                fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
                fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
                outputBufferConfig.pixelFormat = fl_out_fb_format;
                outputBufferConfig.interlacedMode = kPXP_OutputProgressive;
                outputBufferConfig.buffer0Addr = (UINT32)fl_dest_ptr;
                outputBufferConfig.buffer1Addr = (UINT32)0U;
                outputBufferConfig.pitchBytes = p_cntx_SP->rprop.fb_w * (fl_bpp_size / 8U);
                outputBufferConfig.width = fl_clip_w;
                outputBufferConfig.height = fl_clip_h;
                PXP_SetOutputBufferConfig(PXP_ID, &outputBufferConfig);

                hmi_gfx_mgr02_imxrt_pxp_blt();

                if ((pxp_ps_pixel_format_t)p_elem_def_SP->format == kPXP_PsPixelFormatYVU420)
                {
                    PXP_EnableOverWrittenAlpha(PXP_ID, false);
                }
                else
                {
                    pdConfig.enable = 0;
                    PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
                }
                #if defined(GFX_PERFORMANCE_MEASUREMENT)
                fl_end_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
                fl_time_in_msec = hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_end_time, fl_start_time);
                #ifdef GFX_DEBUG_INFO
                PRINTF("\r\n Build image %08X %d \r\n", p_elem_def_SP, fl_time_in_msec);
                #endif
                #endif
            }
        }
    }
    #ifdef GFX02_DEBUG_INFO
    else
    {
        gfx_debug("PXP for Imxrt - Image elem =%08X skipped\n", p_elem_def_SP);
    }
    #endif
    fl_return_value = (s_gx_flocal)TRUE;
    return(fl_return_value);
}
#endif

#ifdef USE_IMXRT_PXP_QUEUE
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_buf_copy
Description          : Build the image object of the merge widget.
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_image().
Parameters           : GFX_MGR02_CONTEXT_T , GFX_MGR02_IMAGE_DEF_T
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_mem_copy(UINT32  *p_src_ptr , UINT32  *p_dest_ptr, UINT32 p_size)
{
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  UINT32 fl_start_time;
  UINT32 fl_stop_time;
  UINT32 fl_time_in_msec;
#endif
  UINT32 fl_out_bpp_size;
  UINT32 fl_ps_fb_format;
  UINT32 fl_as_fb_format;
  UINT32 fl_out_fb_format;
  status_t fl_pxp_st;
  s_gx_flocal fl_return_value = (s_gx_flocal)TRUE;
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
#endif
  GFX_MGR02_CONTEXT_T const * fl_context_ptr = hmi_gfx_mgr02_context_get_ptr();
  fl_out_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(fl_context_ptr->rprop.fb_format);
  fl_ps_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(fl_context_ptr->rprop.fb_format);

  fl_out_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
  //fl_pxp_st = PXP_StartMemCopy(PXP_ID, p_src_ptr, p_dest_ptr, p_size);

  pxp_command_t * fl_pxp_comm_buff = hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer();

  fl_pxp_comm_buff->CTRL       = PXP_CTRL_ROT_POS(0) | PXP_CTRL_ENABLE_MASK | PXP_CTRL_NEXT_IRQ_ENABLE_MASK |PXP_CTRL_IRQ_ENABLE_MASK| PXP_CTRL_BLOCK_SIZE(kPXP_BlockSize16);
  fl_pxp_comm_buff->STAT       = 0x00000000;                              /* STAT, don't care */
  fl_pxp_comm_buff->OUT_CTRL   = PXP_OUT_CTRL_FORMAT(fl_out_fb_format)|PXP_OUT_CTRL_INTERLACED_OUTPUT(kPXP_OutputProgressive); /* OUT_CTRL */
  fl_pxp_comm_buff->OUT_BUF    = (UINT32)p_dest_ptr;                /* OUT_BUF */
  fl_pxp_comm_buff->OUT_BUF2   = 0x00000000;                              /* OUT_BUF2 */
  fl_pxp_comm_buff->OUT_PITCH  = fl_context_ptr->rprop.fb_w * (fl_out_bpp_size/8);                 /* OUT_PITCH */
  fl_pxp_comm_buff->OUT_LRC    = PXP_OUT_LRC_Y(fl_context_ptr->rprop.fb_h - 1U) | PXP_OUT_LRC_X(fl_context_ptr->rprop.fb_w - 1U); /* OUT_LRC */
  fl_pxp_comm_buff->OUT_PS_ULC = PXP_OUT_PS_ULC_Y(0x3FFFu) | PXP_OUT_PS_ULC_X(0x3FFFu);        /* OUT_PS_ULC */
  fl_pxp_comm_buff->OUT_PS_LRC = PXP_OUT_PS_LRC_Y(0) | PXP_OUT_PS_LRC_X(0);        /* OUT_PS_LRC */
  /* Disable AS. */
  fl_pxp_comm_buff->OUT_AS_ULC    = PXP_OUT_AS_ULC_Y(0) | PXP_OUT_AS_ULC_X(0);                            /* OUT_AS_ULC */
  fl_pxp_comm_buff->OUT_AS_LRC    = PXP_OUT_AS_LRC_Y(fl_context_ptr->rprop.fb_h - 1U) | PXP_OUT_AS_LRC_X(fl_context_ptr->rprop.fb_w - 1U);                            /* OUT_AS_LRC */

  fl_pxp_comm_buff->PS_CTRL       = 0x00000000;                            /* PS_CTRL */
  fl_pxp_comm_buff->PS_BUF        = (UINT32)0;                             /* PS_BUF */
  fl_pxp_comm_buff->PS_UBUF       = 0x00000000;                            /* PS_UBUF */
  fl_pxp_comm_buff->PS_VBUF       = 0x00000000;                            /* PS_VBUF */
  fl_pxp_comm_buff->PS_PITCH      = 0x00000000;                            /* PS_PITCH */
  fl_pxp_comm_buff->PS_BACHGROUND = 0x00000000;                            /* PS_BACHGROUND */
  fl_pxp_comm_buff->PS_SCALE      = 0x10001000;                            /* PS_SCALE */
  fl_pxp_comm_buff->PS_OFFSET     = 0x00000000;                            /* PS_OFFSET */
  fl_pxp_comm_buff->PS_CLRKEYLOW  = 0x00FFFFFF;                            /* PS_CLRKEYLOW */
  fl_pxp_comm_buff->PS_CLRKEYHIGH = 0x00000000;                            /* PS_CLRKEYHIGH */
  fl_pxp_comm_buff->AS_CTRL       = PXP_AS_CTRL_FORMAT(fl_out_fb_format)|PXP_AS_CTRL_ROP(kPXP_RopMergeAs)|PXP_AS_CTRL_ALPHA(255)|PXP_AS_CTRL_ALPHA_CTRL(kPXP_AlphaRop);                            /* AS_CTRL */
  fl_pxp_comm_buff->AS_BUF        = p_src_ptr;                            /* AS_BUF */
  fl_pxp_comm_buff->AS_PITCH      = fl_context_ptr->rprop.fb_w *(fl_out_bpp_size/8);                            /* AS_PITCH */
  fl_pxp_comm_buff->AS_CLRKEYLOW  = 0x00FFFFFF;                            /* AS_CLRKEYLOW */
  fl_pxp_comm_buff->AS_CLRKEYHIGH = 0x00000000;                            /* AS_CLRKEYHIGH */

  fl_pxp_comm_buff->CSC1_COEF0    = 0x00000000;                            /* CSC1_COEF0, don't care. */
  fl_pxp_comm_buff->CSC1_COEF1    = 0x00000000;                            /* CSC1_COEF1, don't care. */
  fl_pxp_comm_buff->CSC1_COEF2    = 0x00000000;                            /* CSC1_COEF2, don't care. */
#if !(defined(FSL_FEATURE_PXP_HAS_NO_CSC2) && FSL_FEATURE_PXP_HAS_NO_CSC2)
  fl_pxp_comm_buff->CSC2_CTRL  = PXP_CSC2_CTRL_BYPASS_MASK; /* CSC2_CTRL */
  fl_pxp_comm_buff->CSC2_COEF0 = 0x00000000;                /* CSC2_COEF0, don't care. */
  fl_pxp_comm_buff->CSC2_COEF1 = 0x00000000;                /* CSC2_COEF1, don't care. */
  fl_pxp_comm_buff->CSC2_COEF2 = 0x00000000;                /* CSC2_COEF2, don't care. */
  fl_pxp_comm_buff->CSC2_COEF3 = 0x00000000;                /* CSC2_COEF3, don't care. */
  fl_pxp_comm_buff->CSC2_COEF4 = 0x00000000;                /* CSC2_COEF4, don't care. */
  fl_pxp_comm_buff->CSC2_COEF5 = 0x00000000;                /* CSC2_COEF5, don't care. */
#endif
#if !(defined(FSL_FEATURE_PXP_HAS_NO_LUT) && FSL_FEATURE_PXP_HAS_NO_LUT)
  fl_pxp_comm_buff->LUT_CTRL   = PXP_LUT_CTRL_BYPASS_MASK; /* LUT_CTRL */
  fl_pxp_comm_buff->LUT_ADDR   = 0x00000000;               /* LUT_ADDR */
  fl_pxp_comm_buff->LUT_DATA   = 0x00000000;               /* LUT_DATA */
  fl_pxp_comm_buff->LUT_EXTMEM = 0x00000000;               /* LUT_EXTMEM */
  fl_pxp_comm_buff->CFA        = 0x00000000;               /* CFA */
#endif
  fl_pxp_comm_buff->HIST_CTRL     = 0x00000020; /* HIST_CTRL */
  fl_pxp_comm_buff->HIST2_PARAM   = 0x00000F00; /* HIST2_PARAM */
  fl_pxp_comm_buff->HIST4_PARAM   = 0x0F0A0500; /* HIST4_PARAM */
  fl_pxp_comm_buff->HIST8_PARAM0  = 0x06040200; /* HIST8_PARAM0 */
  fl_pxp_comm_buff->HIST8_PARAM1  = 0x0F0D0B09; /* HIST8_PARAM1 */
  fl_pxp_comm_buff->HIST16_PARAM0 = 0x03020100; /* HIST16_PARAM0 */
  fl_pxp_comm_buff->HIST16_PARAM1 = 0x07060504; /* HIST16_PARAM1 */
  fl_pxp_comm_buff->HIST16_PARAM2 = 0x0B0A0908; /* HIST16_PARAM2 */
  fl_pxp_comm_buff->HIST16_PARAM3 = 0x0F0E0D0C; /* HIST16_PARAM3 */
  fl_pxp_comm_buff->POWER         = 0x00000000; /* POWER */
  fl_pxp_comm_buff->NEXT          = 0x00000000; /* NEXT, don't care */

  hmi_gfx_mgr02_imxrt_pxp_blt();



#if defined(GFX_PERFORMANCE_MEASUREMENT)
  fl_stop_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
  fl_time_in_msec = COUNT_TO_MSEC(fl_stop_time - fl_start_time , SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#ifdef GFX_DEBUG_INFO
  PRINTF("\rMemcpy msec %d\r\n",fl_time_in_msec );
#endif
#endif
  return(fl_return_value);
}
#else
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_mem_copy(UINT32  *p_src_ptr , UINT32  *p_dest_ptr, UINT32 p_size)
{
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  UINT32 fl_start_time;
  UINT32 fl_stop_time;
  UINT32 fl_time_in_msec;
#endif
  status_t fl_pxp_st;
  s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
#endif
  if((p_size != 0U) && (p_src_ptr != NULL) && (p_dest_ptr != NULL))
  {
    if((p_size % 512U) == 0U)
    {
      fl_pxp_st = PXP_StartMemCopy(PXP_ID, (UINT32)p_src_ptr, (UINT32)p_dest_ptr, p_size);
    }
    else
    {
      pxp_as_pixel_format_t fl_as_fb_format;
      UINT32 fl_as_bpp_size;
      pxp_pic_copy_config_t fl_mem_copy_config;
      GFX_MGR02_CONTEXT_T const * fl_context_ptr = hmi_gfx_mgr02_context_get_ptr();
      fl_as_fb_format =  hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(fl_context_ptr->rprop.fb_format);
      fl_as_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(fl_as_fb_format);
      fl_mem_copy_config.srcPicBaseAddr = (UINT32)p_src_ptr;
      fl_mem_copy_config.srcPitchBytes = fl_context_ptr->rprop.fb_w * (fl_as_bpp_size/8U);
      fl_mem_copy_config.srcOffsetX = 0;
      fl_mem_copy_config.srcOffsetY = 0;
      fl_mem_copy_config.destPicBaseAddr = (UINT32)p_dest_ptr;
      fl_mem_copy_config.destPitchBytes =  fl_context_ptr->rprop.fb_w * (fl_as_bpp_size/8);
      fl_mem_copy_config.destOffsetX = 0;
      fl_mem_copy_config.destOffsetY = 0;
      fl_mem_copy_config.width = fl_context_ptr->rprop.fb_w;
      fl_mem_copy_config.height = fl_context_ptr->rprop.fb_h;
      fl_mem_copy_config.pixelFormat = fl_as_fb_format;
      fl_pxp_st = PXP_StartPictureCopy(PXP_ID, &fl_mem_copy_config);
    }
    if(fl_pxp_st == kStatus_Success)
    {
      fl_return_value = (s_gx_flocal)TRUE;
    }
    while (!(kPXP_CompleteFlag & PXP_GetStatusFlags(PXP_ID)))
    {

    }
    PXP_ClearStatusFlags(PXP_ID, kPXP_CompleteFlag);
#if defined(GFX_PERFORMANCE_MEASUREMENT)
    fl_stop_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
    fl_time_in_msec = COUNT_TO_MSEC(fl_stop_time - fl_start_time , SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#ifdef GFX_DEBUG_INFO
    PRINTF("\rMemcpy msec %d\r\n",fl_time_in_msec );
#endif
#endif
  }
  return(fl_return_value);
}
#endif

#ifdef USE_IMXRT_PXP_QUEUE
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_build_fill
Description          : Builds the fill object of the merge widget.
Invocation           : 
Parameters           : None
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_fill(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim)
{
  UINT32 fl_fg_color;
  UINT32 fl_alpha_temp;
  UINT8  fl_rgba[4];
  UINT32 fl_fb_format;
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  UINT32 fl_start_time;
  UINT32 fl_end_time;
  UINT32 fl_time_in_msec;
#endif

  UINT16   fl_clip_w;
  UINT16   fl_clip_h;

  void *   fl_dest_ptr;

  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

  s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;

  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy))
  {
#if defined(GFX_PERFORMANCE_MEASUREMENT)
    fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
#endif
    /* OUT buffer configure */
    fl_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
    UINT32 fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_fb_format);

    fl_clip_w = p_cntx_SP->state.clip.ex - p_cntx_SP->state.clip.sx;
    fl_clip_h = p_cntx_SP->state.clip.ey - p_cntx_SP->state.clip.sy;
    fl_dest_ptr = (UINT32)(p_cntx_SP->rprop.fb_P + (UINT32)p_cntx_SP->rprop.fb_w * (UINT32)p_cntx_SP->state.clip.sy * (fl_bpp_size/8) + ((UINT32)p_cntx_SP->state.clip.sx * (fl_bpp_size/8)));

      pxp_command_t * fl_pxp_comm_buff = hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer();
      fl_pxp_comm_buff->CTRL       = PXP_CTRL_ROT_POS(0) | PXP_CTRL_ENABLE_MASK|PXP_CTRL_NEXT_IRQ_ENABLE_MASK| PXP_CTRL_IRQ_ENABLE_MASK | PXP_CTRL_BLOCK_SIZE(kPXP_BlockSize16);
      fl_pxp_comm_buff->STAT       = 0x00000000;                              /* STAT, don't care */
      fl_pxp_comm_buff->OUT_CTRL   = PXP_OUT_CTRL_FORMAT(fl_fb_format)|PXP_OUT_CTRL_INTERLACED_OUTPUT(kPXP_OutputProgressive); /* OUT_CTRL */
      fl_pxp_comm_buff->OUT_BUF    = (UINT32)fl_dest_ptr;                /* OUT_BUF */
      fl_pxp_comm_buff->OUT_BUF2   = 0x00000000;                              /* OUT_BUF2 */
      fl_pxp_comm_buff->OUT_PITCH  = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8);                 /* OUT_PITCH */
      fl_pxp_comm_buff->OUT_LRC    = PXP_OUT_LRC_Y(fl_clip_h) | PXP_OUT_LRC_X(fl_clip_w); /* OUT_LRC */
      fl_pxp_comm_buff->OUT_PS_ULC = PXP_OUT_PS_ULC_Y(0xFFFFU) | PXP_OUT_PS_ULC_X(0xFFFFU);        /* OUT_PS_ULC */
      fl_pxp_comm_buff->OUT_PS_LRC = PXP_OUT_PS_LRC_Y(0) | PXP_OUT_PS_LRC_X(0);        /* OUT_PS_LRC */
      /* Disable AS. */

      fl_pxp_comm_buff->OUT_AS_ULC    = PXP_OUT_AS_ULC_Y(0xFFFFU) | PXP_OUT_AS_ULC_X(0xFFFFU);                            /* OUT_AS_ULC */
      fl_pxp_comm_buff->OUT_AS_LRC    = PXP_OUT_AS_LRC_Y(0) | PXP_OUT_AS_LRC_X(0);                            /* OUT_AS_LRC */
      fl_pxp_comm_buff->PS_CTRL       = 0x00000000; /* PS_CTRL */
      fl_pxp_comm_buff->PS_BUF        = 0x00000000;               /* PS_BUF */
      fl_pxp_comm_buff->PS_UBUF       = 0x00000000;                            /* PS_UBUF */
      fl_pxp_comm_buff->PS_VBUF       = 0x00000000;                            /* PS_VBUF */
      fl_pxp_comm_buff->PS_PITCH      = 0x00000000; /* PS_PITCH */
      fl_pxp_comm_buff->PS_BACHGROUND = p_cntx_SP->rprop.fg_color;              /* PS_BACHGROUND */
      fl_pxp_comm_buff->PS_SCALE      = 0x10001000;                            /* PS_SCALE */
      fl_pxp_comm_buff->PS_OFFSET     = 0x00000000;                            /* PS_OFFSET */
      fl_pxp_comm_buff->PS_CLRKEYLOW  = 0x00FFFFFF;                            /* PS_CLRKEYLOW */
      fl_pxp_comm_buff->PS_CLRKEYHIGH = 0x00000000;                            /* PS_CLRKEYHIGH */
      fl_pxp_comm_buff->AS_CTRL       = 0x00000000;
      fl_pxp_comm_buff->AS_BUF        = 0x00000000;                            /* AS_BUF */
      fl_pxp_comm_buff->AS_PITCH      = 0x00000000;                            /* AS_PITCH */
      fl_pxp_comm_buff->AS_CLRKEYLOW  = 0x00FFFFFF;                            /* AS_CLRKEYLOW */
      fl_pxp_comm_buff->AS_CLRKEYHIGH = 0x00000000;                            /* AS_CLRKEYHIGH */
      fl_pxp_comm_buff->CSC1_COEF0    = 0x00000000;                            /* CSC1_COEF0, don't care. */
      fl_pxp_comm_buff->CSC1_COEF1    = 0x00000000;                            /* CSC1_COEF1, don't care. */
      fl_pxp_comm_buff->CSC1_COEF2    = 0x00000000;                            /* CSC1_COEF2, don't care. */
#if !(defined(FSL_FEATURE_PXP_HAS_NO_CSC2) && FSL_FEATURE_PXP_HAS_NO_CSC2)
      fl_pxp_comm_buff->CSC2_CTRL  = PXP_CSC2_CTRL_BYPASS_MASK; /* CSC2_CTRL */
      fl_pxp_comm_buff->CSC2_COEF0 = 0x00000000;                /* CSC2_COEF0, don't care. */
      fl_pxp_comm_buff->CSC2_COEF1 = 0x00000000;                /* CSC2_COEF1, don't care. */
      fl_pxp_comm_buff->CSC2_COEF2 = 0x00000000;                /* CSC2_COEF2, don't care. */
      fl_pxp_comm_buff->CSC2_COEF3 = 0x00000000;                /* CSC2_COEF3, don't care. */
      fl_pxp_comm_buff->CSC2_COEF4 = 0x00000000;                /* CSC2_COEF4, don't care. */
      fl_pxp_comm_buff->CSC2_COEF5 = 0x00000000;                /* CSC2_COEF5, don't care. */
#endif
#if !(defined(FSL_FEATURE_PXP_HAS_NO_LUT) && FSL_FEATURE_PXP_HAS_NO_LUT)
      fl_pxp_comm_buff->LUT_CTRL   = PXP_LUT_CTRL_BYPASS_MASK; /* LUT_CTRL */
      fl_pxp_comm_buff->LUT_ADDR   = 0x00000000;               /* LUT_ADDR */
      fl_pxp_comm_buff->LUT_DATA   = 0x00000000;               /* LUT_DATA */
      fl_pxp_comm_buff->LUT_EXTMEM = 0x00000000;               /* LUT_EXTMEM */
      fl_pxp_comm_buff->CFA        = 0x00000000;               /* CFA */
#endif
      fl_pxp_comm_buff->HIST_CTRL     = 0x00000020; /* HIST_CTRL */
      fl_pxp_comm_buff->HIST2_PARAM   = 0x00000F00; /* HIST2_PARAM */
      fl_pxp_comm_buff->HIST4_PARAM   = 0x0F0A0500; /* HIST4_PARAM */
      fl_pxp_comm_buff->HIST8_PARAM0  = 0x06040200; /* HIST8_PARAM0 */
      fl_pxp_comm_buff->HIST8_PARAM1  = 0x0F0D0B09; /* HIST8_PARAM1 */
      fl_pxp_comm_buff->HIST16_PARAM0 = 0x03020100; /* HIST16_PARAM0 */
      fl_pxp_comm_buff->HIST16_PARAM1 = 0x07060504; /* HIST16_PARAM1 */
      fl_pxp_comm_buff->HIST16_PARAM2 = 0x0B0A0908; /* HIST16_PARAM2 */
      fl_pxp_comm_buff->HIST16_PARAM3 = 0x0F0E0D0C; /* HIST16_PARAM3 */
      fl_pxp_comm_buff->POWER         = 0x00000000; /* POWER */
      fl_pxp_comm_buff->NEXT          = 0x00000000; /* NEXT, don't care */

      hmi_gfx_mgr02_imxrt_pxp_blt();

#if defined(GFX_PERFORMANCE_MEASUREMENT)
      fl_end_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
      fl_time_in_msec = hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_end_time,fl_start_time);
#ifdef GFX_DEBUG_INFO
      PRINTF("\r\n Build fill %d \r\n",fl_time_in_msec);
#endif
#endif
  }
#ifdef GFX02_DEBUG_INFO
  else
  {
    gfx_debug("PXP for IMXRT - Fill elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  fl_return_value = (s_gx_flocal)TRUE;
  return(fl_return_value);
}
#else
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_build_fill
Description          : Builds the fill object of the merge widget.
Invocation           : 
Parameters           : None
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_fill(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_FILL_DEF_T   const *p_elem_def_SP, GFX_MGR02_IDIM_DATA const *p_dim)
{
  UINT32 fl_fg_color;
  UINT32 fl_alpha_temp;
  UINT8  fl_fillcolor_alpha;
#if defined(GFX_PERFORMANCE_MEASUREMENT)
  UINT32 fl_start_time;
  UINT32 fl_end_time;
  UINT32 fl_time_in_msec;
#endif

  void *   fl_dest_ptr;
  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
  s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;

  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
    {
        pxp_output_pixel_format_t fl_out_fb_format;
        PXP_EnableCsc1(PXP_ID, false);     /* Disable CSC1, it is enabled by default. */
        PXP_SetProcessBlockSize(PXP, kPXP_BlockSize16); /* Block size 16x16 for higher performance */
        
    #if defined (GFX_PERFORMANCE_MEASUREMENT)
        fl_start_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
    #endif
        /* OUT buffer configure */
        fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
        UINT32 fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
        
        UINT16 fl_clip_w;
        UINT16 fl_clip_h;
        
        GFX_MGR02_VISIBLE_AREA fl_curr_clip;
        GFX_MGR02_VISIBLE_AREA fl_new_clip;
        
        fl_curr_clip.sx = p_cntx_SP->state.clip.sx;
        fl_curr_clip.sy = p_cntx_SP->state.clip.sy;
        fl_curr_clip.ex = p_cntx_SP->state.clip.ex;
        fl_curr_clip.ey = p_cntx_SP->state.clip.ey;

        fl_new_clip.sx = p_cntx_SP->state.loc.x;
        fl_new_clip.sy = p_cntx_SP->state.loc.y;
        fl_new_clip.ex = fl_new_clip.sx + (SINT16)p_elem_def_SP->dim.width;
        fl_new_clip.ey = fl_new_clip.sy + (SINT16)p_elem_def_SP->dim.height;
        
        (void)hmi_gfx_mgr02_context_validate_clip(&fl_curr_clip, &fl_new_clip);
        fl_clip_w = fl_curr_clip.ex - fl_curr_clip.sx;
        fl_clip_h = fl_curr_clip.ey - fl_curr_clip.sy;
        fl_dest_ptr = (void *)((UINT32)(p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * ((UINT32)fl_curr_clip.sy * (fl_bpp_size / 8U))) + ((UINT32)fl_curr_clip.sx * (fl_bpp_size / 8U))));
        pxp_output_buffer_config_t outputConfig = {
            .pixelFormat    = fl_out_fb_format,
            .interlacedMode = kPXP_OutputProgressive,
            .buffer0Addr    = (UINT32)fl_dest_ptr,
            .buffer1Addr    = (UINT32)NULL,
            .pitchBytes     = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8U),
            .width          = (UINT32)fl_clip_w,
            .height         = (UINT32)fl_clip_h,
        };	  
        PXP_SetOutputBufferConfig(PXP_ID, &outputConfig);

        fl_fg_color = p_cntx_SP->rprop.fg_color;
        fl_fillcolor_alpha = GM2_IMXRT_A(fl_fg_color);

        if((fl_fillcolor_alpha!=(UINT8)0) && ((p_cntx_SP->state.alpha<(UINT8)255) || (fl_fillcolor_alpha<(UINT8)255)))
        {
            /* Fill with opacity - AS used as source (same as OUT), PS used as color generator, blended together */
            pxp_as_buffer_config_t asBufferConfig;
            pxp_porter_duff_config_t pdConfig;
            pxp_as_pixel_format_t fl_as_fb_format;

            fl_alpha_temp = (UINT32)p_cntx_SP->state.alpha * fl_fillcolor_alpha;
            fl_fillcolor_alpha = (UINT8)(fl_alpha_temp/(UINT32)255);
            fl_as_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(p_cntx_SP->rprop.fb_format); 		
            /* Set AS to OUT */
            asBufferConfig.pixelFormat = fl_as_fb_format;
            asBufferConfig.bufferAddr  = (UINT32)outputConfig.buffer0Addr;
            asBufferConfig.pitchBytes  = outputConfig.pitchBytes;

            PXP_SetAlphaSurfacePosition(PXP_ID, 0, 0, fl_clip_w-1U, fl_clip_h-1U );
            PXP_SetAlphaSurfaceBufferConfig(PXP_ID, &asBufferConfig);
            PXP_EnableAlphaSurfaceOverlayColorKey(PXP_ID, 0);

            /* Disable PS, use as color generator */
            PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U);
            PXP_SetProcessSurfaceBackGroundColor(PXP_ID, fl_fg_color);

            /* Configure DST OVER Porter-Duff blending */
            (void)memset(&pdConfig, 0, sizeof(pxp_porter_duff_config_t));
            pdConfig.enable             = 1;
            pdConfig.srcFactorMode      = kPXP_PorterDuffFactorInversed;
            pdConfig.dstFactorMode      = kPXP_PorterDuffFactorOne;
            pdConfig.dstColorMode       = kPXP_PorterDuffColorInversed;
            pdConfig.srcColorMode       = kPXP_PorterDuffColorStraight;
            pdConfig.dstGlobalAlphaMode = kPXP_PorterDuffGlobalAlpha;
            pdConfig.srcGlobalAlphaMode = kPXP_PorterDuffLocalAlpha;
            pdConfig.srcAlphaMode       = kPXP_PorterDuffAlphaStraight; 
            pdConfig.dstAlphaMode       = kPXP_PorterDuffAlphaStraight; 
            pdConfig.srcGlobalAlpha     = 0U;
            pdConfig.dstGlobalAlpha     = fl_fillcolor_alpha;
            PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);   
            
            hmi_gfx_mgr02_imxrt_pxp_blt();
                
            pdConfig.enable             = 0;
            PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
        }
        else
        {
            /* Simple color fill without opacity - AS disabled, PS as color generator */
            PXP_SetAlphaSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable AS. */
            PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable PS. */
            PXP_SetProcessSurfaceBackGroundColor(PXP_ID, fl_fg_color);		    
            
            PXP_EnableOverWrittenAlpha(PXP_ID, true);
            PXP_SetOverwrittenAlphaValue(PXP_ID, fl_fillcolor_alpha);
            hmi_gfx_mgr02_imxrt_pxp_blt();
            PXP_EnableOverWrittenAlpha(PXP_ID, false);
        }

    #if defined(GFX_PERFORMANCE_MEASUREMENT)
        fl_end_time = hmi_gfx_mgr02_imxrt_pxp_get_cpu_cycle_count();
        fl_time_in_msec = hmi_gfx_mgr02_imxrt_pxp_get_time_in_msec(fl_end_time,fl_start_time);
    #ifdef GFX_DEBUG_INFO
        PRINTF("\r\n Build fill %d \r\n",fl_time_in_msec);
    #endif
    #endif
    }
#ifdef GFX02_DEBUG_INFO
    else
    {
        gfx_debug("PXP for IMXRT - Fill elem =%08X skipped\n", p_elem_def_SP);
    }
#else
    GFX_MGR02_UNUSED_PTR(p_elem_def_SP);	 
#endif
    GFX_MGR02_UNUSED_PTR(p_dim);
    fl_return_value = (s_gx_flocal)TRUE;
    return(fl_return_value);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_bound
Description          : Calculates the transformed bounds of an elements passed
boundary
Invocation           : 
Parameters           : Object, Context and boundary
Return Value         : Boundary
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds)
{
  p_bounds[0] = (GFX_FLOAT)p_cntx_SP->state.loc.x;
  p_bounds[1] = (GFX_FLOAT)p_cntx_SP->state.loc.y;
  /* return True by default since no error condition has been identified */
  GFX_MGR02_UNUSED_VAR(p_obj_type);
  return((s_gx_flocal)TRUE);
}


/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format
Description          : This function will provide the output buffer pixel format
                       of imxrt pxp engine.
Invocation           : 
Parameters           : u_gx_flocal
Return Value         : pxp_output_pixel_format_t
Critical Section     : None
External Interfaces  : None
******************************************************************************/
pxp_output_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(u_gx_flocal p_pix_format)
{
  pxp_output_pixel_format_t fl_gdc_pix_format;

  switch (p_pix_format)
  {

  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB565:
    fl_gdc_pix_format = kPXP_OutputPixelFormatRGB565;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB888:
    /* Since PS support only 32 bit, here also 32 considered for RGB888. ie., Alpha always 255 */
    fl_gdc_pix_format = kPXP_OutputPixelFormatRGB888;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB1555:
    fl_gdc_pix_format = kPXP_OutputPixelFormatARGB1555;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB4444:
    fl_gdc_pix_format = kPXP_OutputPixelFormatARGB4444;
    break;
  case GFX_MGR02_PIX_FORMAT_8BPP:
    fl_gdc_pix_format = kPXP_OutputPixelFormatRGB565;
    break;
  case GFX_MGR02_PIX_FORMAT_4BPP:
    fl_gdc_pix_format = kPXP_OutputPixelFormatRGB565;
    break;
  case GFX_MGR02_PIX_FORMAT_2BPP:
    fl_gdc_pix_format = kPXP_OutputPixelFormatRGB565;
    break;
  default:
    fl_gdc_pix_format = kPXP_OutputPixelFormatARGB8888;
    break;
  }
  return(fl_gdc_pix_format);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format
Description          : This function will provide process buffer pixel format
                       of imxrt pxp engine.
Invocation           : 
Parameters           : u_gx_flocal
Return Value         : pxp_ps_pixel_format_t
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static pxp_ps_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(u_gx_flocal p_pix_format)
{
  pxp_ps_pixel_format_t fl_gdc_pix_format;

  switch (p_pix_format)
  {

  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB565:
    fl_gdc_pix_format = kPXP_PsPixelFormatRGB565;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB888:
    //fl_gdc_pix_format = kPXP_OutputPixelFormatRGB888P;
    fl_gdc_pix_format = kPXP_PsPixelFormatRGB888;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB4444:
    fl_gdc_pix_format = kPXP_PsPixelFormatRGB444;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB1555:
      fl_gdc_pix_format = kPXP_PsPixelFormatRGB555;
      break;

  default:
    fl_gdc_pix_format = kPXP_PsPixelFormatRGB888;
    break;
  }
  return(fl_gdc_pix_format);

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format
Description          : This function will provide process buffer pixel format
                       of imxrt pxp engine.
Invocation           :
Parameters           : u_gx_flocal
Return Value         : pxp_ps_pixel_format_t
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static pxp_as_pixel_format_t hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(u_gx_flocal p_pix_format)
{
  pxp_as_pixel_format_t fl_gdc_pix_format;

  switch (p_pix_format)
  {
   
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB4444:
    fl_gdc_pix_format = kPXP_AsPixelFormatARGB4444;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB1555:
    fl_gdc_pix_format = kPXP_AsPixelFormatARGB1555;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB8888:
    fl_gdc_pix_format = kPXP_AsPixelFormatARGB8888;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB565:
    fl_gdc_pix_format = kPXP_AsPixelFormatRGB565;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB888:
    fl_gdc_pix_format = kPXP_AsPixelFormatRGB888;
    break;
  case (u_gx_flocal)kPXP_AsPixelFormatIndex8BPP:
    fl_gdc_pix_format = kPXP_AsPixelFormatRGB565;
    break;
  case (u_gx_flocal)kPXP_AsPixelFormatIndex4BPP:
    fl_gdc_pix_format = kPXP_AsPixelFormatRGB565;
    break;
  case (u_gx_flocal)kPXP_AsPixelFormatIndex2BPP:
    fl_gdc_pix_format = kPXP_AsPixelFormatRGB565;
    break;
  default:
    fl_gdc_pix_format = kPXP_AsPixelFormatARGB8888;
    break;
  }
  return(fl_gdc_pix_format);

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_build_text
Description          : Builds the text object . 
Invocation           : Invoked by hmi_gfx_mgr02_generic_build_text()
Parameters           : GFX_MGR02_CONTEXT_T, GFX_MGR02_TEXT_DEF_T, HMI_CHAR, u_gx_flocal
Return Value         : s_gx_flocal
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP ,
                                           GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, 
                                           HMI_CHAR const *p_string, 
                                           u_gx_flocal p_text_actual_width
#if (defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                           ,u_gx_flocal p_is_multi_line_text
#endif
                                           )
{
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
  static HMI_CHAR l_irislib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif

  GFX_MGR02_FONT const * fl_font_SP;
  HMI_CHAR       const * fl_string_ptr = NULL;
  HMI_CHAR       const * fl_print_str  = NULL;
  UINT32   fl_str_length = 0UL;
  UINT16   fl_text_width;
  GFX_UINT fl_alignment  = p_cntx_SP->rprop.alignment;
  UINT32   fl_font_id;
#ifdef GFX_STRING_CACHE_ENABLED
  /*Below variable is used only for allocating memory for full string when string cache is enabled.*/
  UINT16 fl_full_text_width = 0U;
#endif
  SINT16 fl_glyph_draw_x;

#ifndef GFX_STRING_CACHE_ENABLED
  UINT8  fl_use_ttf_engine = (UINT8)0;
#endif
    
  s_gx_flocal fl_return_value = (s_gx_flocal)FALSE;
  UINT8 fl_shutdown_state     = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
  if((p_cntx_SP->state.invisible == (UINT8)0) && (GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
    && (p_cntx_SP->state.clip.ex > p_cntx_SP->state.clip.sx)&&(p_cntx_SP->state.clip.ey > p_cntx_SP->state.clip.sy)
#endif
    )
  {
    fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_cntx_SP->rprop.font_id);
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
    if(fl_font_SP != GFX_MGR02_NULL_PTR)
    {
      GFX_MGR02_TEXT_INFO fl_text_info_S;
      fl_text_info_S.print_str_P         = p_string;
      fl_text_info_S.max_available_width = p_cntx_SP->rprop.text_width;
      #if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE))
      fl_text_info_S.font_pt_size = p_cntx_SP->rprop.font_size.point_size;
      #endif

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

#if (defined(GFX_MGR02_CLIP_TEXT_ENABLE))
      fl_print_str  = l_irislib_clip_text_str;
#else
      fl_print_str  = fl_text_info_S.print_str_P;
#endif
      fl_string_ptr = fl_print_str;
      fl_text_width = fl_text_info_S.print_width;
      fl_str_length = fl_text_info_S.print_length_U8;
#ifdef GFX_STRING_CACHE_ENABLED
      fl_full_text_width = fl_text_info_S.print_width;
#endif
    }
    else
    {
      fl_text_width = (UINT16)0;
    }
    if(fl_text_width > (UINT16)0)
    {
      UINT32 fl_fg_color;
      UINT32 fl_bg_color;
      SINT32 fl_start_x;
      UINT32 fl_alpha_temp;
      SINT32 fl_txtbox_strt_x;
      UINT8  fl_bgfill_color_alpha;
      UINT8  fl_draw_mode;

#ifdef GFX_STRING_CACHE_ENABLED
      UINT8 * fl_str_img_data;
#endif

      if(fl_text_width > p_cntx_SP->rprop.text_width)
      {
        fl_text_width = p_cntx_SP->rprop.text_width;
      }
      if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
      {
        fl_txtbox_strt_x = (SINT32)p_cntx_SP->rprop.text_width;
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          fl_start_x     = ((SINT32)fl_text_width - 1);
        }
        else
        {
          fl_start_x     = (SINT32)(fl_text_width);
        }
      }
      else if (fl_alignment == GFX_MGR02_TP_ALIGN_CENTRE)
      {
        fl_start_x       = ((SINT32)fl_text_width /2);
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
          fl_start_x       -= ((SINT32)p_cntx_SP->rprop.text_width / 2);
          fl_txtbox_strt_x -= ((SINT32)p_cntx_SP->rprop.text_width/2);
          
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        { 
          fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width/2);
          fl_txtbox_strt_x -=1;
          fl_start_x       += ((SINT32)p_cntx_SP->rprop.text_width / 2);
          /* Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text. */
          /* So it needs to be considered here */
          fl_start_x       -= 1;
        }
        else
        {
          /*To Fix MISRA warning*/
        }
      }
      else if (fl_alignment == GFX_MGR02_TP_ALIGN_RIGHT)
      {
        if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
        {
          fl_start_x       -= (SINT32)(p_cntx_SP->rprop.text_width);
          fl_txtbox_strt_x = 0;
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
        {
          fl_start_x       -= ((SINT32)p_cntx_SP->rprop.text_width/2);
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
          fl_start_x       += ((SINT32)p_cntx_SP->rprop.text_width/2);
          fl_txtbox_strt_x = ((SINT32)p_cntx_SP->rprop.text_width/2);
        }
        else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
        {
          fl_txtbox_strt_x += ((SINT32)p_cntx_SP->rprop.text_width -(SINT32)1);
          fl_start_x       += (SINT32)p_cntx_SP->rprop.text_width;
          /*  Tool generates (p_cntx_SP->state.loc.x = TextWidth + startx -1) for right aligned text.So it needs to be considered here  */
          fl_start_x       -= 1; 
        }
        else
        {
          /*To fix MISRA warning.*/
        }
      }
#endif

      fl_start_x   = ((SINT32)p_cntx_SP->state.loc.x - fl_start_x);
      fl_txtbox_strt_x = ((SINT32)p_cntx_SP->state.loc.x - fl_txtbox_strt_x);
      fl_draw_mode = (UINT8)p_cntx_SP->rprop.draw_mode;
      fl_fg_color  = p_cntx_SP->rprop.fg_color;

      if (fl_draw_mode != GFX_MGR02_TP_DRAW_TRANSP)
      {
        pxp_output_pixel_format_t  fl_out_fb_format;
        UINT16   fl_clip_w;
        UINT16   fl_clip_h;
        UINT32   fl_bpp_size;
        void *   fl_dest_ptr;
        
        GFX_MGR02_VISIBLE_AREA fl_curr_clip;
        GFX_MGR02_VISIBLE_AREA fl_new_clip;

        PXP_EnableCsc1(PXP_ID, false);     /* Disable CSC1, it is enabled by default. */
        PXP_SetProcessBlockSize(PXP, kPXP_BlockSize16); /* Block size 16x16 for higher performance */

        fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
        fl_bpp_size      = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
                
        fl_curr_clip.sx = p_cntx_SP->state.clip.sx;
        fl_curr_clip.sy = p_cntx_SP->state.clip.sy;
        fl_curr_clip.ex = p_cntx_SP->state.clip.ex;
        fl_curr_clip.ey = p_cntx_SP->state.clip.ey;

        fl_new_clip.sx = (SINT16)fl_txtbox_strt_x;
        fl_new_clip.sy = p_cntx_SP->state.loc.y;
        fl_new_clip.ex = fl_new_clip.sx + (SINT16)p_cntx_SP->rprop.text_width;
        fl_new_clip.ey = fl_new_clip.sy + (SINT16)fl_font_SP->p.height;

        (void)hmi_gfx_mgr02_context_validate_clip(&fl_curr_clip, &fl_new_clip);
        fl_clip_w = fl_curr_clip.ex - fl_curr_clip.sx;
        fl_clip_h = fl_curr_clip.ey - fl_curr_clip.sy;
        
        fl_dest_ptr = (void *)((UINT32)(p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_curr_clip.sy * (fl_bpp_size / 8U)) + ((UINT32)fl_curr_clip.sx * (fl_bpp_size / 8U))));

        pxp_output_buffer_config_t outputConfig = {

          .pixelFormat    = fl_out_fb_format,
          .interlacedMode = kPXP_OutputProgressive,
          .buffer0Addr    = (UINT32)fl_dest_ptr,
          .buffer1Addr    = (UINT32)NULL,
          .pitchBytes     = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8U),
          .width          = (UINT32)fl_clip_w,
          .height         = (UINT32)fl_clip_h,

        };
        PXP_SetOutputBufferConfig(PXP_ID, &outputConfig);

        if (fl_draw_mode == GFX_MGR02_TP_DRAW_REVERSE)
        {
          fl_bg_color = p_cntx_SP->rprop.fg_color;
          fl_fg_color = p_cntx_SP->rprop.bg_color;
        }
        else
        {
          fl_bg_color = p_cntx_SP->rprop.bg_color;
        }

        fl_bgfill_color_alpha = GM2_IMXRT_A(fl_bg_color); /* Alpha */
      
        if((p_cntx_SP->state.alpha < (UINT8)255) || (fl_bgfill_color_alpha < (UINT8)255))
        {
          fl_alpha_temp = ((UINT32)fl_bgfill_color_alpha*p_cntx_SP->state.alpha);
          fl_bgfill_color_alpha = (UINT8)(fl_alpha_temp/(UINT32)255);
                  
          pxp_as_buffer_config_t asBufferConfig;
          pxp_porter_duff_config_t pdConfig;
          
          pxp_as_pixel_format_t fl_as_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_pix_format(p_cntx_SP->rprop.fb_format); 
          /* Set AS to OUT */
          asBufferConfig.pixelFormat = fl_as_fb_format;
          asBufferConfig.bufferAddr  = (UINT32)outputConfig.buffer0Addr;
          asBufferConfig.pitchBytes  = outputConfig.pitchBytes;
          
          PXP_SetAlphaSurfacePosition(PXP_ID, 0, 0, fl_clip_w-1U, fl_clip_h-1U );
          PXP_SetAlphaSurfaceBufferConfig(PXP_ID, &asBufferConfig);
          PXP_EnableAlphaSurfaceOverlayColorKey(PXP_ID, 0);

          /* Disable PS, use as color generator */
          PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U);
          PXP_SetProcessSurfaceBackGroundColor(PXP_ID, fl_bg_color);

          /* Configure DST OVER Porter-Duff blending */
          (void)memset(&pdConfig, 0, sizeof(pxp_porter_duff_config_t));
          pdConfig.enable             = 1;
          pdConfig.srcFactorMode      = kPXP_PorterDuffFactorInversed;
          pdConfig.dstFactorMode      = kPXP_PorterDuffFactorOne;
          pdConfig.dstColorMode       = kPXP_PorterDuffColorInversed;
          pdConfig.srcColorMode       = kPXP_PorterDuffColorStraight;
          pdConfig.dstGlobalAlphaMode = kPXP_PorterDuffGlobalAlpha;
          pdConfig.srcGlobalAlphaMode = kPXP_PorterDuffLocalAlpha;
          pdConfig.srcAlphaMode       = kPXP_PorterDuffAlphaStraight; 
          pdConfig.dstAlphaMode       = kPXP_PorterDuffAlphaStraight; 
          pdConfig.srcGlobalAlpha     = 0U;
          pdConfig.dstGlobalAlpha     = fl_bgfill_color_alpha;
          PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);		
            
          hmi_gfx_mgr02_imxrt_pxp_blt();
            
          pdConfig.enable             = 0;
          PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);

        }
        else
        {
          PXP_SetAlphaSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable AS. */
          PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable PS. */
          PXP_SetProcessSurfaceBackGroundColor(PXP_ID, fl_bg_color);
          PXP_EnableOverWrittenAlpha(PXP_ID, true);
          PXP_SetOverwrittenAlphaValue(PXP_ID, fl_bgfill_color_alpha);
          hmi_gfx_mgr02_imxrt_pxp_blt();
          PXP_EnableOverWrittenAlpha(PXP_ID, false);
        }
      }

#ifdef GFX_STRING_CACHE_ENABLED
      /*
      1. Get the bmp pointer for the string from the cache.
        2. If it is not available then render that string and put it in the cache.
      */
      fl_str_img_data = hmi_gfx_mgr02_get_string_cache_ptr(fl_string_ptr, p_cntx_SP, fl_font_SP, fl_font_id, fl_fg_color);

      if(fl_str_img_data == NULL)
      {
        /* 
        1. Create a string.        
        */

        GFX_STRING_CACHE_INFO element;
        PixEngMemInfo fl_memory_s;
        UINT8 fl_font_height       = fl_font_SP->p.height;
        fl_glyph_draw_x            = (SINT16)0;
        fl_memory_s.MemCateg       = IMXRT_STRING_CACHE_BUFFER;
        fl_memory_s.WidgetClientId = 0xFFFFFFFFu; 
        fl_memory_s.Alignment      = (UINT32)32; /*32 Byte alignement*/
        fl_memory_s.Size           = (UINT32)(fl_full_text_width*fl_font_height*4);/* Considering ARGB8888 */
        fl_memory_s.ExtMemory      = (UINT8)1;
        #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
        fl_memory_s.WidgetFBGroupId = GFX_MGR02_INVALID_FB_GROUP_ID;
        #endif
        fl_str_img_data            = hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&fl_memory_s);
        
        if(fl_str_img_data != NULL)
        {
          GFX_MGR02_CONTEXT_T fl_context_sp;
          (void)memset(fl_str_img_data,0,fl_memory_s.Size);
          hmi_gfx_mgr02_context_state_get(&fl_context_sp.state);
          fl_context_sp.rprop           = p_cntx_SP->rprop;
          fl_context_sp.rprop.fb_P      = (void *)fl_str_img_data;
          fl_context_sp.rprop.fb_w      = fl_full_text_width;
          fl_context_sp.rprop.fb_h      = fl_font_height;
          fl_context_sp.rprop.fb_format = kPXP_OutputPixelFormatARGB8888;
          fl_context_sp.state.loc.x     = 0;
          fl_context_sp.state.loc.y     = 0;
          fl_context_sp.state.alpha     = 255;
          
          draw_windows_bmp_string(fl_glyph_draw_x, &fl_context_sp, fl_string_ptr, fl_font_SP, fl_fg_color, fl_str_length);
          
          (void)HMI_STRNCPY(element.String, fl_string_ptr,(UINT32)GFX_MGR02_MAX_TEXT_LENGTH);
          element.String[GFX_MGR02_MAX_TEXT_LENGTH] = (HMI_CHAR)'\0';
          element.StringLen   = (UINT8)fl_str_length;
          element.FontId      = fl_font_id;
          element.FontSize    = fl_font_height;
          element.Buf         = fl_str_img_data;
          element.drawColor   = fl_fg_color;
          element.bmpWidth    = (UINT16)fl_full_text_width;

          hmi_gfx_mgr02_add_string_in_cache_queue(&element);
          
        }
      }
#endif

#ifndef GFX_STRING_CACHE_ENABLED
      fl_glyph_draw_x = (SINT16)fl_start_x;
      if (fl_use_ttf_engine == (UINT8)0)
      {
        draw_windows_bmp_string(fl_glyph_draw_x,p_cntx_SP,
        fl_string_ptr, fl_font_SP, fl_fg_color, fl_str_length);
      }
      else
      {
        /* To do for Monotype or Freetype Font engine */
      }
#else
      if(fl_str_img_data !=NULL)
      {         
        GFX_MGR02_IMAGE_DEF_T fl_element_def_SP;
        GFX_MGR02_CONTEXT_T fl_context_sp;

        GFX_MGR02_VISIBLE_AREA fl_new_clip;
        fl_new_clip.sx  = (SINT16)fl_start_x;
        fl_new_clip.sy  = p_cntx_SP->state.loc.y;
        fl_new_clip.ex  = fl_new_clip.sx + fl_full_text_width;
        fl_new_clip.ey  = fl_new_clip.sy + fl_font_SP->p.height;

        hmi_gfx_mgr02_context_state_get(&fl_context_sp.state);
        fl_context_sp.rprop           = p_cntx_SP->rprop;
        fl_context_sp.state.invisible = hmi_gfx_mgr02_context_validate_clip(&fl_context_sp.state.clip, &fl_new_clip);
        fl_context_sp.state.loc.x     = (SINT16)fl_start_x;

        fl_element_def_SP.format      = kPXP_AsPixelFormatARGB8888;
        fl_element_def_SP.compression = GFX_MGR02_IMAGE_COMPRESSION_NONE;
        fl_element_def_SP.chroma_key  = GFX_MGR02_IMAGE_CHROMA_KEY_NONE;
        fl_element_def_SP.vaoa_index  = 0;
        fl_element_def_SP.clut        = GFX_MGR02_NUM_OF_CLUTS;
        fl_element_def_SP.width       = fl_full_text_width;
        fl_element_def_SP.height      = fl_font_SP->p.height;
        fl_element_def_SP.color       =	0x0;
        fl_element_def_SP.pixel_data  = fl_str_img_data;
        hmi_gfx_mgr02_imxrt_pxp_build_image(&fl_context_sp, &fl_element_def_SP);
      }
#endif      
    }
  }
#ifdef GFX02_DEBUG_INFO
  else
  {
    gfx_debug("Imxrt Pxp - Text elem =%08X skipped\n", p_elem_def_SP);
  }
#endif
  fl_return_value = (s_gx_flocal)TRUE;
  GFX_MGR02_UNUSED_VAR(p_text_actual_width);
  return(fl_return_value);
}

/****************************************************************************
Function Name        : draw_windows_bmp_string
Description          : Build the outline font text.
Invocation           : Invoked by hmi_gfx_mgr02_imxrt_pxp_build_text()
Parameters           : SINT16 - X position
                       GFX_MGR02_CONTEXT_T  const * - Context
                       HMI_CHAR       const * String to render 
                       GFX_MGR02_FONT const * -Font info 
                       UINT8 * - Draw Colour
                       UINT32  - string Length
Return Value         :
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void draw_windows_bmp_string(SINT16 x, GFX_MGR02_CONTEXT_T const *p_cntx_SP,
                                    HMI_CHAR const * p_string_p, GFX_MGR02_FONT const * p_font_SP,
                                    UINT32 p_fg_color,	UINT32 p_str_length)
{
  HMI_CHAR const * fl_string_ptr = p_string_p;
  UINT32 fl_fg_color             = p_fg_color;
  SINT16 fl_glyph_draw_x         = x;
  SINT16 fl_glyph_draw_y         = p_cntx_SP->state.loc.y;
  UINT32 fl_alpha_temp;
  UINT8  fl_draw_color_alpha;
  SINT16 fl_glyph_width;
  SINT16 fl_glyph_height;
  SINT16 gpos_delta_x;
  UINT32 fl_bpp_size;
  SINT16 gpos_delta_y;
  pxp_ps_pixel_format_t fl_ps_fb_format;
  pxp_output_pixel_format_t fl_out_fb_format;
  
  GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
  void * vImgAddr;
  void * fl_dest_ptr;
  UINT32 fl_str_length           = p_str_length;
  UINT16 fl_clip_w;
  UINT16 fl_clip_h;


#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
  SINT16 fl_glyph_advance_x = 0;
#endif
#endif
  SINT32 fl_str_index       = (SINT32)0;
  UINT8 fl_buff_index       = 0U;
  GFX_FLOAT fl_resultantX   = 0.0F;
  GFX_FLOAT fl_resultantY   = 0.0F;
  
  fl_draw_color_alpha = GM2_IMXRT_A(fl_fg_color); /* Alpha */

  if((p_cntx_SP->state.alpha < (UINT8)255)||(fl_draw_color_alpha < (UINT8)255))
  {
    fl_alpha_temp       = ((UINT32)fl_draw_color_alpha*p_cntx_SP->state.alpha);
    fl_draw_color_alpha = (UINT8)(fl_alpha_temp/(UINT32)255);
  }
  else
  {
    fl_draw_color_alpha = p_cntx_SP->state.alpha;
  }

  while(fl_str_length > (UINT32)0)
  {
    fl_str_length--;
    fl_font_fcc_SP  = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], p_font_SP->f.lut_ptr, (UINT32)p_font_SP->size_table,
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
      (UINT32)(p_cntx_SP->rprop.font_id),
#endif
      (UINT32)FALSE);
    if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
    {
      fl_glyph_width  = (SINT16)fl_font_fcc_SP->width;
      fl_glyph_height = (SINT16)fl_font_fcc_SP->height;

      if (fl_font_fcc_SP->fdata != NULL)/*Valid font data*/
      {
        GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0f, 0.0f };
        vImgAddr = (void *)fl_font_fcc_SP->fdata;
        hmi_gfx_mgr02_imxrt_pxp_get_character_buf(vImgAddr, (UINT32 *)&l_char_argb_buf[fl_buff_index], fl_fg_color, fl_glyph_width, fl_glyph_height);
        vImgAddr = (void *)&l_char_argb_buf[fl_buff_index];
        if (fl_buff_index == 1U)
        {
            fl_buff_index = 0;
        }
        else
        {
            fl_buff_index = 1;
        }

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        GFX_MGR02_GPOS_DELTA fl_gpos_info = {0.0f, 0.0f};
        BOOLEAN fl_gpos_found = FALSE;
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        if((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
        if(GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U)
#else
        if(GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U)
#endif
        {
          (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (fl_string_ptr-1) , fl_str_index, p_font_SP ,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
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
        fl_gpos_found = hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_gpos_info, &fl_string_ptr[0] ,fl_str_index ,p_font_SP, p_cntx_SP,  GFX_MGR02_LANG_READ_DIR_LTR);
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
        if(((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U)) ||
          ((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U)))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
        if((fl_gpos_found == TRUE) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U))
#else
        if((fl_gpos_found == TRUE) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U))
#endif
        {
          fl_glyph_advance_x += (SINT16)fl_font_fcc_SP->owidth;
        }
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
        if(GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U)
        {
          (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, p_font_SP ,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
        }
#endif /* GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
        if(GFX_MGR02_IS_HEBREW_VOWEL(fl_string_ptr[0]) == 1U)
        {
          (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0] , 0,p_font_SP ,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
        }                
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */
#endif /* GFX_MGR02_FONT_GPOS_TABLE_ENABLED */
        {

          gpos_delta_x = (SINT16)(fl_delta_pixels.gpos_delta_pixels_x + 0.5f);
          gpos_delta_y = (SINT16)(fl_delta_pixels.gpos_delta_pixels_y + 0.5f);

          fl_resultantX = (GFX_FLOAT)((fl_font_fcc_SP->x_soffset) + gpos_delta_x) ;
          fl_resultantY = (GFX_FLOAT)((fl_font_fcc_SP->y_soffset) - gpos_delta_y);

#if !(defined(GFX_STRING_CACHE_ENABLED))

          GFX_MGR02_VISIBLE_AREA fl_curr_clip;
          GFX_MGR02_VISIBLE_AREA fl_new_clip;
          UINT8  fl_invisible;
          
          fl_curr_clip.sx = p_cntx_SP->state.clip.sx;
          fl_curr_clip.sy = p_cntx_SP->state.clip.sy;
          fl_curr_clip.ex = p_cntx_SP->state.clip.ex;
          fl_curr_clip.ey =	p_cntx_SP->state.clip.ey;
          fl_new_clip.sx  = fl_glyph_draw_x + fl_resultantX;
          fl_new_clip.sy  = p_cntx_SP->state.loc.y + fl_resultantY;
          fl_new_clip.ex  = fl_new_clip.sx + fl_glyph_width;
          fl_new_clip.ey  =	fl_new_clip.sy + fl_glyph_height;
          fl_invisible    = hmi_gfx_mgr02_context_validate_clip(&fl_curr_clip, &fl_new_clip);
          
          if((fl_invisible == 0U) && (fl_curr_clip.ex > fl_curr_clip.sx) && (fl_curr_clip.ey > fl_curr_clip.sy))
#else
          GFX_MGR02_VISIBLE_AREA fl_curr_clip;
          fl_curr_clip.sx = fl_glyph_draw_x + fl_resultantX;
          fl_curr_clip.sy = p_cntx_SP->state.loc.y + fl_resultantY;
          fl_curr_clip.ex = fl_curr_clip.sx + fl_glyph_width;
          fl_curr_clip.ey =	fl_curr_clip.sy + fl_glyph_height;
          
#endif
          {
            fl_clip_w = fl_curr_clip.ex - fl_curr_clip.sx;
            fl_clip_h = fl_curr_clip.ey - fl_curr_clip.sy;

#ifdef USE_IMXRT_PXP_QUEUE
            UINT32 fl_ps_fb_format  = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(p_cntx_SP->rprop.fb_format);
            UINT32 fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
            UINT32 fl_as_bpp_size   = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(kPXP_AsPixelFormatARGB8888);
            UINT32 fl_ps_bpp_size   = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(fl_ps_fb_format);	
            UINT32 fl_out_bpp_size  = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);	
            pxp_command_t * fl_pxp_comm_buff = hmi_gfx_mgr02_imxrt_pxp_get_active_pxp_buffer();
            fl_dest_ptr = (UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_glyph_draw_y * (fl_out_bpp_size/8)) + ((UINT32)fl_glyph_draw_x* (fl_out_bpp_size/8));

            //fl_pxp_comm_buff->CTRL       = PXP_CTRL_ROT_POS(0) | PXP_CTRL_ENABLE_MASK| PXP_CTRL_NEXT_IRQ_ENABLE_MASK|PXP_CTRL_IRQ_ENABLE_MASK |PXP_CTRL_BLOCK_SIZE(kPXP_BlockSize16);
            fl_pxp_comm_buff->CTRL       = PXP_CTRL_ROT_POS(0) | PXP_CTRL_ENABLE_MASK|PXP_CTRL_BLOCK_SIZE(kPXP_BlockSize16);
            fl_pxp_comm_buff->STAT       = 0x00000000;                              /* STAT, don't care */
            fl_pxp_comm_buff->OUT_CTRL   = PXP_OUT_CTRL_FORMAT(fl_out_fb_format)|PXP_OUT_CTRL_INTERLACED_OUTPUT(kPXP_OutputProgressive); /* OUT_CTRL */
            fl_pxp_comm_buff->OUT_BUF    = (UINT32)fl_dest_ptr;                     /* OUT_BUF */
            fl_pxp_comm_buff->OUT_BUF2   = 0x00000000;                              /* OUT_BUF2 */
            fl_pxp_comm_buff->OUT_PITCH  = p_cntx_SP->rprop.fb_w * (fl_out_bpp_size/8);                 /* OUT_PITCH */
            fl_pxp_comm_buff->OUT_LRC    = PXP_OUT_LRC_Y(fl_glyph_height -1) | PXP_OUT_LRC_X(fl_glyph_width -1); /* OUT_LRC */
            fl_pxp_comm_buff->OUT_PS_ULC = PXP_OUT_PS_ULC_Y(0) | PXP_OUT_PS_ULC_X(0);        /* OUT_PS_ULC */
            fl_pxp_comm_buff->OUT_PS_LRC = PXP_OUT_PS_LRC_Y(fl_glyph_height -1) | PXP_OUT_PS_LRC_X(fl_glyph_width -1);        /* OUT_PS_LRC */

            fl_pxp_comm_buff->OUT_AS_ULC    = PXP_OUT_AS_ULC_Y(0) | PXP_OUT_AS_ULC_X(0);                            /* OUT_AS_ULC */
            fl_pxp_comm_buff->OUT_AS_LRC    = PXP_OUT_AS_LRC_Y(fl_glyph_height -1) | PXP_OUT_AS_LRC_X(fl_glyph_width -1);                            /* OUT_AS_LRC */
            fl_pxp_comm_buff->PS_CTRL       = PXP_PS_CTRL_FORMAT(fl_ps_fb_format);   /* PS_CTRL */
            fl_pxp_comm_buff->PS_BUF        = (UINT32)fl_dest_ptr;                   /* PS_BUF */
            fl_pxp_comm_buff->PS_UBUF       = 0x00000000;                            /* PS_UBUF */
            fl_pxp_comm_buff->PS_VBUF       = 0x00000000;                            /* PS_VBUF */
            fl_pxp_comm_buff->PS_PITCH      = p_cntx_SP->rprop.fb_w * (fl_ps_bpp_size/8); /* PS_PITCH */
            fl_pxp_comm_buff->PS_BACHGROUND = 0x00000000;                            /* PS_BACHGROUND */
            fl_pxp_comm_buff->PS_SCALE      = 0x10001000;                            /* PS_SCALE */
            fl_pxp_comm_buff->PS_OFFSET     = 0x00000000;                            /* PS_OFFSET */
            fl_pxp_comm_buff->PS_CLRKEYLOW  = 0x00FFFFFF;                            /* PS_CLRKEYLOW */
            fl_pxp_comm_buff->PS_CLRKEYHIGH = 0x00000000;                            /* PS_CLRKEYHIGH */
            fl_pxp_comm_buff->AS_CTRL       = PXP_AS_CTRL_FORMAT(kPXP_AsPixelFormatARGB8888)|PXP_AS_CTRL_ROP(kPXP_RopMaskAs)|PXP_AS_CTRL_ALPHA(p_cntx_SP->state.alpha)|PXP_AS_CTRL_ALPHA_CTRL(kPXP_AlphaMultiply);                 /* AS_CTRL */
            fl_pxp_comm_buff->AS_BUF        = (UINT32)vImgAddr;                      /* AS_BUF */
            fl_pxp_comm_buff->AS_PITCH      = fl_glyph_width *(fl_as_bpp_size/8);    /* AS_PITCH */
            fl_pxp_comm_buff->AS_CLRKEYLOW  = 0x00FFFFFF;                            /* AS_CLRKEYLOW */
            fl_pxp_comm_buff->AS_CLRKEYHIGH = 0x00000000;                            /* AS_CLRKEYHIGH */


            fl_pxp_comm_buff->CSC1_COEF0    = 0x00000000;                            /* CSC1_COEF0, don't care. */
            fl_pxp_comm_buff->CSC1_COEF1    = 0x00000000;                            /* CSC1_COEF1, don't care. */
            fl_pxp_comm_buff->CSC1_COEF2    = 0x00000000;                            /* CSC1_COEF2, don't care. */
#if !(defined(FSL_FEATURE_PXP_HAS_NO_CSC2) && FSL_FEATURE_PXP_HAS_NO_CSC2)
            fl_pxp_comm_buff->CSC2_CTRL  = PXP_CSC2_CTRL_BYPASS_MASK; /* CSC2_CTRL */
            fl_pxp_comm_buff->CSC2_COEF0 = 0x00000000;                /* CSC2_COEF0, don't care. */
            fl_pxp_comm_buff->CSC2_COEF1 = 0x00000000;                /* CSC2_COEF1, don't care. */
            fl_pxp_comm_buff->CSC2_COEF2 = 0x00000000;                /* CSC2_COEF2, don't care. */
            fl_pxp_comm_buff->CSC2_COEF3 = 0x00000000;                /* CSC2_COEF3, don't care. */
            fl_pxp_comm_buff->CSC2_COEF4 = 0x00000000;                /* CSC2_COEF4, don't care. */
            fl_pxp_comm_buff->CSC2_COEF5 = 0x00000000;                /* CSC2_COEF5, don't care. */
#endif
#if !(defined(FSL_FEATURE_PXP_HAS_NO_LUT) && FSL_FEATURE_PXP_HAS_NO_LUT)
            fl_pxp_comm_buff->LUT_CTRL   = PXP_LUT_CTRL_BYPASS_MASK; /* LUT_CTRL */
            fl_pxp_comm_buff->LUT_ADDR   = 0x00000000;               /* LUT_ADDR */
            fl_pxp_comm_buff->LUT_DATA   = 0x00000000;               /* LUT_DATA */
            fl_pxp_comm_buff->LUT_EXTMEM = 0x00000000;               /* LUT_EXTMEM */
            fl_pxp_comm_buff->CFA        = 0x00000000;               /* CFA */
#endif
            fl_pxp_comm_buff->HIST_CTRL     = 0x00000020; /* HIST_CTRL */
            fl_pxp_comm_buff->HIST2_PARAM   = 0x00000F00; /* HIST2_PARAM */
            fl_pxp_comm_buff->HIST4_PARAM   = 0x0F0A0500; /* HIST4_PARAM */
            fl_pxp_comm_buff->HIST8_PARAM0  = 0x06040200; /* HIST8_PARAM0 */
            fl_pxp_comm_buff->HIST8_PARAM1  = 0x0F0D0B09; /* HIST8_PARAM1 */
            fl_pxp_comm_buff->HIST16_PARAM0 = 0x03020100; /* HIST16_PARAM0 */
            fl_pxp_comm_buff->HIST16_PARAM1 = 0x07060504; /* HIST16_PARAM1 */
            fl_pxp_comm_buff->HIST16_PARAM2 = 0x0B0A0908; /* HIST16_PARAM2 */
            fl_pxp_comm_buff->HIST16_PARAM3 = 0x0F0E0D0C; /* HIST16_PARAM3 */
            fl_pxp_comm_buff->POWER         = 0x00000000; /* POWER */
            fl_pxp_comm_buff->NEXT          = 0x00000000; /* NEXT, don't care */		  


            while (PXP_IsNextCommandPending(PXP_ID))
            {
            }
            PXP_ClearStatusFlags(PXP_ID, kPXP_CompleteFlag);
            //l_gfx_imxrt_pxp_blt_pending = 1;
            PXP_SetNextCommand(PXP_ID, fl_pxp_comm_buff);
            l_pxp_command_buffer_index++;
            if(l_pxp_command_buffer_index == MAX_NO_OF_PXP_COMMAND_BUFFER)
            {
              l_pxp_command_buffer_index = 0;
            }
#else	/* Without Queue blending */

            pxp_output_buffer_config_t outputBufferConfig;
            pxp_as_buffer_config_t asBufferConfig;
            pxp_porter_duff_config_t pdConfig;
            PXP_EnableCsc1(PXP_ID, false);     /* Disable CSC1, it is enabled by default. */
            PXP_SetProcessBlockSize(PXP, kPXP_BlockSize16); /* Block size 16x16 for higher performance */

            fl_ps_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_pix_format(p_cntx_SP->rprop.fb_format);
            fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(fl_ps_fb_format);
            fl_dest_ptr = (void *)((UINT32)p_cntx_SP->rprop.fb_P + ((UINT32)p_cntx_SP->rprop.fb_w * (UINT32)fl_curr_clip.sy * (fl_bpp_size/8U)) + ((UINT32)fl_curr_clip.sx * (fl_bpp_size/8U)));
            pxp_ps_buffer_config_t psBufferConfig = {
              .pixelFormat = fl_ps_fb_format,
              .swapByte    = false,
              .bufferAddr  = (UINT32)fl_dest_ptr,
              .bufferAddrU = 0U,
              .bufferAddrV = 0U,
              .pitchBytes  = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8U),
            };

            /* Alpha blending or color keying enabled - PS must be enabled to fetch background pixels
            PS and OUT buffers are the same, blend will be done in-place */

            PXP_SetProcessSurfaceBufferConfig(PXP_ID, &psBufferConfig);

            /* AS buffer - source image */
            asBufferConfig.pixelFormat = kPXP_AsPixelFormatARGB8888;

            fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(asBufferConfig.pixelFormat);
            asBufferConfig.bufferAddr  = (UINT32)vImgAddr + (fl_glyph_width * (fl_curr_clip.sy - fl_glyph_draw_y)*(fl_bpp_size/8U)) + ((fl_curr_clip.sx - fl_glyph_draw_x)*(fl_bpp_size/8U));
            //asBufferConfig.bufferAddr  =  (UINT32)vImgAddr + ((UINT32)p_elem_def_SP->width * (UINT32)fl_curr_clip.sy * (fl_bpp_size/8U)) + ((UINT32)(p_cntx_SP->state.clip.sx - p_cntx_SP->state.loc.x)* (fl_bpp_size/8U));
            asBufferConfig.pitchBytes  = fl_glyph_width *(fl_bpp_size/8U);
            
            PXP_SetAlphaSurfaceBufferConfig(PXP_ID, &asBufferConfig);
            PXP_EnableAlphaSurfaceOverlayColorKey(PXP_ID, 0);
            
            PXP_SetAlphaSurfacePosition(PXP_ID, 0, 0, (fl_clip_w -1U) ,(fl_clip_h -1U));
            PXP_SetProcessSurfacePosition(PXP_ID, 0, 0 , (fl_clip_w -1U), (fl_clip_h -1U));
            
            /* Output buffer. */
            fl_out_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
            fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_out_fb_format);
            outputBufferConfig.pixelFormat    = fl_out_fb_format;
            outputBufferConfig.interlacedMode = kPXP_OutputProgressive;
            outputBufferConfig.buffer0Addr    = (UINT32)fl_dest_ptr;
            outputBufferConfig.buffer1Addr    = (UINT32)0U;
            outputBufferConfig.pitchBytes     = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8U);
            outputBufferConfig.width          = fl_clip_w;
            outputBufferConfig.height         = fl_clip_h;
            PXP_SetOutputBufferConfig(PXP_ID, &outputBufferConfig);			
                        
            /* Configure SRC OVER Porter-Duff blending */
            (void)memset(&pdConfig, 0, sizeof(pxp_porter_duff_config_t));
            pdConfig.enable             = 1;
            pdConfig.dstFactorMode      = kPXP_PorterDuffFactorInversed;
            pdConfig.srcFactorMode      = kPXP_PorterDuffFactorOne;
            pdConfig.srcColorMode       = kPXP_PorterDuffColorInversed;
            pdConfig.dstColorMode       = kPXP_PorterDuffColorStraight;
            pdConfig.srcGlobalAlphaMode = kPXP_PorterDuffScaledAlpha;
            pdConfig.dstGlobalAlphaMode = kPXP_PorterDuffLocalAlpha;
            pdConfig.dstAlphaMode       = kPXP_PorterDuffAlphaStraight; 
            pdConfig.srcAlphaMode       = kPXP_PorterDuffAlphaStraight; 
            pdConfig.dstGlobalAlpha     = 0U;
            pdConfig.srcGlobalAlpha     = fl_draw_color_alpha;
            PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);		
            
            hmi_gfx_mgr02_imxrt_pxp_blt();
            
            pdConfig.enable             = 0;
            PXP_SetPorterDuffConfig(PXP_ID, &pdConfig);
#endif /* USE_IMXRT_PXP_QUEUE */
          }
        }
      }
      fl_glyph_draw_x = fl_glyph_draw_x + (SINT16)fl_font_fcc_SP->owidth;
    }
    fl_string_ptr++;
    fl_str_index++;
  }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_character_buf
Description          : This function will provide character buffer in ARGB8888
                       format after appending fg_color with alpha data of font.
Invocation           : 
Parameters           : p_char_alphadata,p_char_argb_data,p_fg_color,p_char_width,p_char_height
Return Value         : void
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_imxrt_pxp_get_character_buf(UINT8 * p_char_alphadata,
                                                      UINT32 * p_char_argb_data,
                                                      UINT32 p_fg_color,
                                                      UINT32 p_char_width,
                                                      UINT32 p_char_height)
{
  UINT32 i;
  UINT32 fl_copy_bytes = p_char_height * p_char_width;
  UINT32 fl_char_alpha;
  UINT32 fl_fg_color;
  UINT32 fl_argb;
  UINT32 * fl_char_argb_data = p_char_argb_data;
  UINT8 * fl_char_alphadata = p_char_alphadata;
  for(i = 0; i < fl_copy_bytes; i++)
  {
    fl_char_alpha = *((UINT32 *)fl_char_alphadata) << 24;

    fl_fg_color = p_fg_color & 0x00ffffffU;
    fl_argb = (fl_char_alpha|fl_fg_color);

    *fl_char_argb_data = fl_argb;
    fl_char_argb_data++;
    fl_char_alphadata++;
  }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp
Description          : This function will provide output buffer bpp of imxrt
                       for the passed format
Invocation           : 
Parameters           : pxp_output_pixel_format_t
Return Value         : UINT32 bpp
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(pxp_output_pixel_format_t p_format)
{
  UINT32 fl_bpp;
  switch(p_format)
  {
  case kPXP_OutputPixelFormatARGB8888:
  case kPXP_OutputPixelFormatYUV1P444:
  case kPXP_OutputPixelFormatRGB888:
    {
      fl_bpp = (UINT32)32;
    }
    break;


  case kPXP_OutputPixelFormatRGB888P:
    {
      fl_bpp = (UINT32)24;
    }
    break;
  case kPXP_OutputPixelFormatARGB1555:
  case kPXP_OutputPixelFormatARGB4444:
  case kPXP_OutputPixelFormatRGB555:
  case kPXP_OutputPixelFormatRGB565:
  case kPXP_OutputPixelFormatUYVY1P422:
  case kPXP_OutputPixelFormatVYUY1P422:
  case kPXP_OutputPixelFormatYUV2P422:
  case kPXP_OutputPixelFormatYUV2P420:
  case kPXP_OutputPixelFormatYVU2P422:
  case kPXP_OutputPixelFormatYVU2P420:
    {
      fl_bpp = (UINT32)16;
    }
    break;
  case kPXP_OutputPixelFormatY8:
    {
      fl_bpp = (UINT32)8;
    }
    break;
  case kPXP_OutputPixelFormatY4:

    {
      fl_bpp = (UINT32)4;
    }
    break;
  default:
    {
      fl_bpp = (UINT32)32;
    }
    break;
  }
  return(fl_bpp);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp
Description          : This function will provide bpp of imxrt
                       for the passed alpha buffer format
Invocation           :
Parameters           : pxp_as_pixel_format_t
Return Value         : UINT32 bpp
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_imxrt_pxp_get_alpha_buf_bpp(pxp_as_pixel_format_t p_format)
{
  UINT32 fl_bpp;
  switch(p_format)
  {
  case kPXP_AsPixelFormatARGB8888:
  case kPXP_AsPixelFormatRGB888:
    {
      fl_bpp = (UINT32)32;
    }
    break;
  case kPXP_AsPixelFormatARGB1555:
  case kPXP_AsPixelFormatARGB4444:
  case kPXP_AsPixelFormatRGB555:
  case kPXP_AsPixelFormatRGB444:
  case kPXP_AsPixelFormatRGB565:
    {
      fl_bpp = (UINT32)16;
    }
    break;
  default:
    {
      fl_bpp = (UINT32)32;
    }
    break;
  }
  return(fl_bpp);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp
Description          : This function will provide bpp of imxrt
                       for the passed process  buffer format
Invocation           :
Parameters           : pxp_ps_pixel_format_t
Return Value         : UINT32 bpp
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_imxrt_pxp_get_process_buf_bpp(pxp_ps_pixel_format_t p_format)
{
    UINT32 fl_bpp;
    switch(p_format)
    {
        case kPXP_PsPixelFormatYUV1P444:
        {
            fl_bpp = (UINT32)32;
        }
        break;

        case kPXP_PsPixelFormatUYVY1P422:
        case kPXP_PsPixelFormatVYUY1P422:
        case kPXP_PsPixelFormatYUV2P422:
        case kPXP_PsPixelFormatYUV2P420:
        case kPXP_PsPixelFormatYVU2P422:
        case kPXP_PsPixelFormatYVU2P420:
        case kPXP_PsPixelFormatYVU422:
        case kPXP_PsPixelFormatYVU420:
        {
            fl_bpp = (UINT32)8;       /* Y channel bits */
        }
        break;
        case kPXP_PsPixelFormatRGB555:
        case kPXP_PsPixelFormatRGB444:
        case kPXP_PsPixelFormatRGB565:
        {
            fl_bpp = (UINT32)16;
        }
        break;
        case kPXP_PsPixelFormatY8:
        case kPXP_PsPixelFormatY4:
        default:
        {
            fl_bpp = (UINT32)32;
        }
        break;
    }
    return(fl_bpp);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_clear_buffer
Description          : Clears the framebuffer with passed color
Invocation           : Invoked internally
Parameters           : fill color
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color)
{
  s_gx_flocal fl_return_value=(s_gx_flocal)FALSE;
  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();
  UINT32 fl_fg_color = p_clear_color;
  UINT8  fl_fillcolor_alpha;

  if(GFX_MGR02_SHUTDOWN_EMERGENCY != fl_shutdown_state)
  {
    PXP_EnableCsc1(PXP_ID, false);                   /* Disable CSC1, it is enabled by default. */
    PXP_SetProcessBlockSize(PXP, kPXP_BlockSize16);  /* Block size 16x16 for higher performance */
    fl_fillcolor_alpha = GM2_IMXRT_A(fl_fg_color);
    pxp_output_pixel_format_t fl_fb_format = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_pix_format(p_cntx_SP->rprop.fb_format);
    UINT32 fl_bpp_size = hmi_gfx_mgr02_imxrt_pxp_get_output_buf_bpp(fl_fb_format);

    pxp_output_buffer_config_t outputConfig = 
    {
        .pixelFormat    = fl_fb_format,
        .interlacedMode = kPXP_OutputProgressive,
        .buffer0Addr    = (UINT32)p_cntx_SP->rprop.fb_P,
        .buffer1Addr    = (UINT32)NULL,
        .pitchBytes     = p_cntx_SP->rprop.fb_w * (fl_bpp_size/8U),
        .width          = (UINT32)p_cntx_SP->rprop.fb_w,
        .height         = (UINT32)p_cntx_SP->rprop.fb_h,
    };	  
    PXP_SetOutputBufferConfig(PXP_ID, &outputConfig);
    PXP_SetAlphaSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable AS. */
    PXP_SetProcessSurfacePosition(PXP_ID, 0xFFFFU, 0xFFFFU, 0U, 0U); /* Disable PS. */
    PXP_SetProcessSurfaceBackGroundColor(PXP_ID, fl_fg_color);
    PXP_EnableOverWrittenAlpha(PXP_ID, true);
    PXP_SetOverwrittenAlphaValue(PXP_ID, fl_fillcolor_alpha);
    hmi_gfx_mgr02_imxrt_pxp_blt();
    PXP_EnableOverWrittenAlpha(PXP_ID, false);
  }
  fl_return_value = (s_gx_flocal)TRUE;
  return(fl_return_value);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_imxrt_pxp_finish
Description          : This function to be called after all the blit commands of the widget are sent
to the command queue. 
Invocation           : hmi_gfx_mgr02_generic_build_dcu_gen_widget()
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_imxrt_pxp_finish(void)
{


  UINT8 fl_shutdown_state = hmi_gfx_mgr02_is_emergency_shutdown_req_active();

  if(GFX_MGR02_SHUTDOWN_EMERGENCY == fl_shutdown_state)
  {
      
    l_imxrt_draw_sts = (UINT8)0;  
  }
  #ifndef USE_IMXRT_PXP_QUEUE
  else
  {
    l_imxrt_draw_sts &= GFX_MGR02_IMXRT_NO_FLUSH_PENDING;  
      
  }
  #endif
  return((s_gx_flocal)l_imxrt_draw_sts);
}
#ifdef USE_IMXRT_PXP_QUEUE
/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_pxp_wait2complete_blit
** Visibility:       Global
** Description:
** Invocation:       By
** Inputs/Outputs:
** Critical Section: None.
** Created:
** Updated:
**==========================================================================*/
void hmi_gfx_mgr02_imxrt_pxp_wait2complete_blit(void)
{
  while (PXP_IsNextCommandPending(PXP_ID))
  {
  }
  if((l_imxrt_draw_sts & GFX_MGR02_IMXRT_FLUSH_PENDING) != 0)
  {
    /* Wait for process complete. */
    while (!(kPXP_CompleteFlag & PXP_GetStatusFlags(PXP_ID)))
    {
    }
    PXP_ClearStatusFlags(PXP_ID, kPXP_CompleteFlag);
    l_imxrt_draw_sts &= GFX_MGR02_IMXRT_NO_FLUSH_PENDING;
  }
}
#endif

#ifdef  __cplusplus
}
#endif

#endif /* #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0))|| defined(GFX_MGR02_IMXRT_PXP) */

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
** CMS Rev 1.0      15-Jun-2021    CSAKTHIV
** Initial version.
**==========================================================================*/
/* end of file =============================================================*/

