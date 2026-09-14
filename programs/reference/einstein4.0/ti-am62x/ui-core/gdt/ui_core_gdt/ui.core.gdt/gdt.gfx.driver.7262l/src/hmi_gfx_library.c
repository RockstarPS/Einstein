/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

/*****************************************************************************
File Name        :  hmi_gfx_library.c
Module Short Name:  Driver
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Graphics Library
Organization     :  Driver Information Software Section,
                    Visteon Corporation
List the compiler name with the version number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :  
Target Processor : SH7262 
******************************************************************************/
#define HMI_GFX_LIBRARY_C

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

#ifndef WIN32
  #include "iodefine.h"
#else
  #include "hmi_simulation_tick.h"
  #include "gfx_lcd_simulator.h"
  #include <string.h>
#endif

#include "system.h"

#include "hmi_gfx_driver.h"
#include "hmi_gfx_mgr_font.h"
#include "hmi_gfx_mgr_font.rom"

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

/*
** pixel count threshold to use DMA while copy to frame buffer.
*/
#define GFX_DRV_DMA_TFR_THRESHOLD (4)

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct
{
  GFX_COLOR_T       * frame_buff_P;
  GFX_COLOR_T const * bmp_data_P;
  GFX_ALPHA_T const * alpha_data_P;
  GFX_SIZE_X_T        x;
  GFX_SIZE_Y_T        y;
  GFX_SIZE_W_T        w;
  GFX_SIZE_H_T        h;
  GFX_SIZE_W_T        w_offset;
}CLIP_IMAGE_DATA;

typedef struct
{
  GFX_SIZE_X_T        x;
  GFX_SIZE_Y_T        y;
  GFX_SIZE_W_T        w;
  GFX_SIZE_H_T        h;
}CLIP_FILLSCREEN_DATA;

typedef struct
{
  GFX_COLOR_T const * src_ptr;
  GFX_COLOR_T       * dest_ptr;
  GFX_SIZE_W_T        src_width;
  GFX_SIZE_W_T        dest_width;
  UINT16              nb_trsfrs;
}GFX_DRV_DMAC_TRSFR_DATA;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
static RECTANGLE_DEF_T  l_clip_area_S[1];
#endif
static GFX_DRV_ENV_INFO l_drv_context_S;

static volatile GFX_DRV_DMAC_TRSFR_DATA l_dmac_transfer_data_S;

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/****************************************************************************
Function Name        : GfxDriverSetEnv
Description          : Sets the working environment for the library by setting
                       the frame buffer pointer, the display layer information
Invocation           : Invoked by driver before the rendering for a layer
                       is started.
Parameters           : Pointer to GFX_DRV_ENV_INFO
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverSetEnv(GFX_DRV_ENV_INFO * p_drv_context_SP)
{
  l_drv_context_S.fb_P      = p_drv_context_SP->fb_P;
  l_drv_context_S.fb_w      = p_drv_context_SP->fb_w;
  l_drv_context_S.fb_h      = p_drv_context_SP->fb_h;
  l_drv_context_S.fb_format = p_drv_context_SP->fb_format;
}
#ifndef WIN32

/****************************************************************************
Function Name        : GfxDriverDMAC0_TEIsr
Description          : DMA0 transfer complete ISR. Reloads the next transfer 
                       block in to the DMA control registers.
Invocation           : Invoked by Image Copy functions.
Parameters           : None
Return Value         : None
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverDMAC0_TEIsr(void)
{
  DMAC.CHCR0.BIT.DE = 0;
  DMAC.CHCR0.BIT.IE = 0;
  l_dmac_transfer_data_S.nb_trsfrs--;
  if(l_dmac_transfer_data_S.nb_trsfrs != 0)
  {
    l_dmac_transfer_data_S.src_ptr  += l_dmac_transfer_data_S.src_width;
    l_dmac_transfer_data_S.dest_ptr += l_dmac_transfer_data_S.dest_width;
    DMAC.SAR0.LONG    = (UINT32)l_dmac_transfer_data_S.src_ptr;
    DMAC.DAR0.LONG    = (UINT32)l_dmac_transfer_data_S.dest_ptr;
    DMAC.DMATCR0.LONG = l_dmac_transfer_data_S.dest_width;
    DMAC.CHCR0.LONG   = 0x8000540D;
  }
}
#endif
#if NB_BITMAPS >= 0
/****************************************************************************
Function Name        : GfxDriverImageCopyAreaFW
Description          : Copies an area from the image data where the copy width
                       is same as the framebuffer width and hence uses DMA.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverImageCopyAreaFW(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
#ifndef WIN32
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P;
  UINT16              fl_count_U16;
  UINT16              fl_repeat_U16;
  /*
  ** Split 60% of the transfer to DMA and 40% with software to utilize the CPU
  ** cycle while we are waiting for the DMA to end.
  */
  l_dmac_transfer_data_S.src_ptr    = pc_bitmap_def_S->bmp_data;
  l_dmac_transfer_data_S.src_ptr   += coord->x;
  l_dmac_transfer_data_S.dest_ptr   = l_drv_context_S.fb_P;
  l_dmac_transfer_data_S.dest_ptr  += (coord->y*l_drv_context_S.fb_w);
  l_dmac_transfer_data_S.dest_width = l_drv_context_S.fb_w;
  l_dmac_transfer_data_S.src_width  = pc_bitmap_def_S->w;

  fl_frame_buff_P                   = l_dmac_transfer_data_S.dest_ptr;
  fl_bmp_data_P                     = l_dmac_transfer_data_S.src_ptr;
  fl_repeat_U16                     = (pc_bitmap_def_S->h * 40)/100;
  l_dmac_transfer_data_S.nb_trsfrs  = (pc_bitmap_def_S->h-fl_repeat_U16);

  l_dmac_transfer_data_S.src_ptr   += (l_dmac_transfer_data_S.src_width  * fl_repeat_U16);
  l_dmac_transfer_data_S.dest_ptr  += (l_dmac_transfer_data_S.dest_width * fl_repeat_U16);

  DMAC.DMAOR.BIT.DME = 1;
  DMAC.CHCR0.BIT.TE  = 0;
  DMAC.CHCR0.BIT.DE  = 0;
  DMAC.SAR0.LONG     = (UINT32)l_dmac_transfer_data_S.src_ptr;
  DMAC.DAR0.LONG     = (UINT32)l_dmac_transfer_data_S.dest_ptr;
  DMAC.DMATCR0.LONG  = l_dmac_transfer_data_S.dest_width;
  DMAC.CHCR0.LONG    = 0x8000540D;

  while(fl_repeat_U16)
  {
    fl_repeat_U16--;
    fl_count_U16 = l_dmac_transfer_data_S.dest_width;
    while(fl_count_U16)
    {
      fl_count_U16--;
      *fl_frame_buff_P++ = *fl_bmp_data_P++;
    }
    fl_bmp_data_P += (l_dmac_transfer_data_S.src_width-l_dmac_transfer_data_S.dest_width);
  }

  while(l_dmac_transfer_data_S.nb_trsfrs != 0);
#else
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;

  fl_frame_buff_P  = l_drv_context_S.fb_P;
  fl_frame_buff_P += (coord->y*l_drv_context_S.fb_w);
  fl_bmp_data_P   += coord->x;

  while(fl_y_size)
  {
    fl_y_size--;
    memcpy((void *)fl_frame_buff_P, 
      (void *)fl_bmp_data_P, 
      (l_drv_context_S.fb_w*sizeof(GFX_COLOR_T)));
    fl_bmp_data_P    += fl_x_size;
    fl_frame_buff_P  += l_drv_context_S.fb_w;
  }
#endif
}

#if GFX_COMPRESSED_IMAGES > 0
/****************************************************************************
Function Name        : GfxDriverLossLessCompImageCopyFW
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverLossLessCompImageCopyFW(COORDINATE_DEF_T  const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;
  UINT16              fl_header_U16;
  UINT16              fl_rpt_data_U16;
  UINT32              fl_pix_count;

  fl_bmp_data_P   = pc_bitmap_def_S->bmp_data;
  fl_frame_buff_P = (void *)l_drv_context_S.fb_P;

  if(fl_y_size == l_drv_context_S.fb_h)
  {
    fl_pix_count = (l_drv_context_S.fb_w*l_drv_context_S.fb_h);
  }
  else
  {
    fl_frame_buff_P += ((l_drv_context_S.fb_w * coord->y)+coord->x);
    fl_pix_count     = (l_drv_context_S.fb_w * fl_y_size);
  }

  while(fl_pix_count)
  {
    fl_header_U16 = *fl_bmp_data_P++;
    if(fl_header_U16 & 0x8000)
    {
      #ifdef WIN32
      UINT16 fl_loop_count_U16;
      fl_header_U16    &= 0x7FFF;
      fl_rpt_data_U16   = *fl_bmp_data_P++;
      fl_loop_count_U16 = fl_header_U16;
      while(fl_loop_count_U16)
      {
        fl_loop_count_U16--;
        *fl_frame_buff_P = fl_rpt_data_U16;
        fl_frame_buff_P++;
      }
      #else
      fl_header_U16    &= 0x7FFF;
      fl_rpt_data_U16   = *fl_bmp_data_P++;
      DMAC.CHCR0.BIT.DE = 0;
      DMAC.SAR0.LONG    = (UINT32)&fl_rpt_data_U16;
      DMAC.DAR0.LONG    = (UINT32)fl_frame_buff_P;
      DMAC.DMATCR0.LONG = fl_header_U16;
      DMAC.CHCR0.LONG   = 0x80004408;
      DMAC.CHCR0.BIT.DE = 1;
      #endif
    }
    else
    {
      #ifdef WIN32
      UINT16 fl_loop_count_U16 = fl_header_U16;
      while(fl_loop_count_U16)
      {
        fl_loop_count_U16--;
        *fl_frame_buff_P++ = *fl_bmp_data_P++;
      }
      #else
      DMAC.CHCR0.BIT.DE = 0;
      DMAC.SAR0.LONG    = (UINT32)fl_bmp_data_P;
      DMAC.DAR0.LONG    = (UINT32)fl_frame_buff_P;
      DMAC.DMATCR0.LONG = fl_header_U16;
      DMAC.CHCR0.LONG   = 0x80005408;
      fl_bmp_data_P    += fl_header_U16;
      DMAC.CHCR0.BIT.DE = 1;
      #endif
    }
    fl_pix_count    -= fl_header_U16;
   #ifndef WIN32
    fl_frame_buff_P += fl_header_U16;
    while(DMAC.CHCR0.BIT.TE == 0);
   #endif
  }
}

/****************************************************************************
Function Name        : GfxDriverLossyCompImageCopyFW
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverLossyCompImageCopyFW(COORDINATE_DEF_T  const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;

  /*
  ** Bitmap is compressed with lossy technique. 
  ** Need to utilize the hardware decompressor
  */
#ifndef WIN32
  UINT32 fl_pix_count;
  fl_frame_buff_P = (void *)l_drv_context_S.fb_P;
  if(fl_y_size == l_drv_context_S.fb_h)
  {
    fl_pix_count = (l_drv_context_S.fb_w*l_drv_context_S.fb_h);
  }
  else
  {
    fl_frame_buff_P += ((l_drv_context_S.fb_w * coord->y)+coord->x);
    fl_pix_count     = (l_drv_context_S.fb_w * fl_y_size);
  }
  /*
  ** DCUE  = 1, IDTRG = 3, ODTRG = 3, IFEN  = 1
  */
  DCU.DCUCR.BYTE       = 0xBC;
  DMAC.CHCR0.LONG      = 0x00001808;
  DMAC.SAR0.LONG       = (UINT32)pc_bitmap_def_S->bmp_data;
  DMAC.DAR0.LONG       = (UINT32)0xFFFF5004;  /*DCU FIFO-in*/
  DMAC.DMATCR0.LONG    = pc_bitmap_def_S->data_size;
  DMAC.DMARS0.BYTE.CH0 = 0xD1;
  DMAC.CHCR1.LONG      = 0x00004808;
  DMAC.SAR1.LONG       = (UINT32)0xFFFF5008;
  DMAC.DAR1.LONG       = (UINT32)fl_frame_buff_P;
  DMAC.DMATCR1.LONG    = fl_pix_count;
  DMAC.DMARS0.BYTE.CH1 = 0xD2;
  DMAC.CHCR0.BIT.DE    = 1;
  DMAC.DMAOR.BIT.DME   = 1;
  DMAC.CHCR1.BIT.DE    = 1;
  while(DMAC.CHCR1.BIT.TE==0);
  DCU.DCUCR.BIT.DCUE   = 0;
  DMAC.CHCR0.BIT.DE    = 0;
  DMAC.CHCR1.BIT.DE    = 0;
#else
  UINT16 fl_header_U16;
  UINT16 fl_rpt_data_U16;
  UINT16 fl_B;
  UINT16 fl_cur_x_size;
  GFX_COLOR_T       * fl_cur_frame_buff_P;

  fl_bmp_data_P       = pc_bitmap_def_S->bmp_data;
  fl_frame_buff_P     = l_drv_context_S.fb_P;
  fl_frame_buff_P    += ((coord->y * l_drv_context_S.fb_w)+coord->x);
  fl_cur_x_size       = fl_x_size;
  fl_cur_frame_buff_P = fl_frame_buff_P;
  while(fl_y_size)
  {
    fl_header_U16 = *fl_bmp_data_P++;
    if(fl_header_U16 & 0x8000)
    {
      fl_B = (fl_header_U16 & 0x7FFF);
      fl_rpt_data_U16   = (fl_B & 0xFFE0);
      fl_rpt_data_U16 <<= 1;
      fl_rpt_data_U16  += (fl_B & 0x1F);
      fl_header_U16   = *fl_bmp_data_P++;
      while(fl_header_U16)
      {
        fl_header_U16--;
        *fl_cur_frame_buff_P++ = fl_rpt_data_U16;
        fl_cur_x_size--;
        if(fl_cur_x_size == 0)
        {
          fl_y_size--;
          fl_frame_buff_P    += l_drv_context_S.fb_w;
          fl_cur_frame_buff_P = fl_frame_buff_P;
          fl_cur_x_size       = fl_x_size;
        }
      }
    }
    else
    {
      fl_rpt_data_U16   = (fl_header_U16 & 0xFFE0);
      fl_rpt_data_U16 <<= 1;
      fl_rpt_data_U16  += (fl_header_U16 & 0x1F);
      *fl_cur_frame_buff_P++ = fl_rpt_data_U16;
      fl_cur_x_size--;
      if(fl_cur_x_size == 0)
      {
        fl_y_size--;
        fl_frame_buff_P    += l_drv_context_S.fb_w;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
      }
    }
  }
#endif
}

/****************************************************************************
Function Name        : GfxDriverLossLessCompImageCopy
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverLossLessCompImageCopy(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;
  GFX_SIZE_W_T        fl_cur_x_size;
  UINT16              fl_header_U16;
  UINT16              fl_rpt_data_U16;

  fl_frame_buff_P     = l_drv_context_S.fb_P;
  fl_frame_buff_P    += ((coord->y * l_drv_context_S.fb_w)+coord->x);
  fl_cur_frame_buff_P = fl_frame_buff_P;
  fl_cur_x_size       = fl_x_size;

  while(fl_y_size)
  {
    fl_header_U16 = *fl_bmp_data_P++;
    if(fl_header_U16 & 0x8000)
    {
      fl_header_U16  &= 0x7FFF;
      fl_rpt_data_U16 = *fl_bmp_data_P++;
      while(fl_header_U16)
      {
        fl_header_U16--;
        *fl_cur_frame_buff_P++ = fl_rpt_data_U16;
        fl_cur_x_size--;
        if(fl_cur_x_size == 0)
        {
          fl_y_size--;
          if(fl_y_size == 0)
          {
            return;
          }
          fl_frame_buff_P    += l_drv_context_S.fb_w;
          fl_cur_frame_buff_P = fl_frame_buff_P;
          fl_cur_x_size       = fl_x_size;
        }
      }
    }
    else
    {
      while(fl_header_U16)
      {
        fl_header_U16--;
        *fl_cur_frame_buff_P++ = *fl_bmp_data_P++;
        fl_cur_x_size--;
        if(fl_cur_x_size == 0)
        {
          fl_y_size--;
          if(fl_y_size == 0)
          {
            return;
          }
          fl_frame_buff_P    += l_drv_context_S.fb_w;
          fl_cur_frame_buff_P = fl_frame_buff_P;
          fl_cur_x_size       = fl_x_size;
        }
      }
    }
  }
}

/****************************************************************************
Function Name        : GfxDriverLossyCompImageCopy
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverLossyCompImageCopy(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;
  GFX_SIZE_W_T        fl_cur_x_size;
#ifdef WIN32
   UINT16              fl_header_U16;
  UINT16              fl_rpt_data_U16;
  UINT16              fl_B;
#endif

  fl_frame_buff_P     = l_drv_context_S.fb_P;
  fl_frame_buff_P    += ((coord->y * l_drv_context_S.fb_w)+coord->x);
  fl_cur_frame_buff_P = fl_frame_buff_P;
  fl_cur_x_size       = fl_x_size;

#ifndef WIN32
  /*
  ** DCUE  = 1, IDTRG = 3, ODTRG = 3, IFEN  = 1
  */
  DCU.DCUCR.BYTE       = 0xAF;
  DMAC.CHCR0.LONG      = 0x00001808;
  DMAC.SAR0.LONG       = (UINT32)fl_bmp_data_P;
  DMAC.DAR0.LONG       = (UINT32)0xFFFF5004;  /*DCU FIFO-in*/
  DMAC.DMATCR0.LONG    = pc_bitmap_def_S->data_size;
  DMAC.DMARS0.BYTE.CH0 = 0xD1;
  DMAC.CHCR0.BIT.DE    = 1;
  DMAC.DMAOR.BIT.DME   = 1;
  while(fl_y_size)
  {
    while(DCU.DCUOFSR.BYTE >= 2)
    {
      *fl_cur_frame_buff_P++ = DCU.DCUOD.WORD;
      fl_cur_x_size--;
      if(fl_cur_x_size == 0)
      {
        fl_y_size--;
        fl_frame_buff_P    += l_drv_context_S.fb_w;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
      }
    }
  }
  DCU.DCUCR.BIT.DCUE = 0;
  DMAC.CHCR0.BIT.DE  = 0;
#else

  while(fl_y_size)
  {
    fl_header_U16 = *fl_bmp_data_P++;
    if(fl_header_U16 & 0x8000)
    {
      fl_B = (fl_header_U16 & 0x7FFF);
      fl_rpt_data_U16   = (fl_B & 0xFFE0);
      fl_rpt_data_U16 <<= 1;
      fl_rpt_data_U16  += (fl_B & 0x1F);
      fl_header_U16   = *fl_bmp_data_P++;
      while(fl_header_U16)
      {
        fl_header_U16--;
        *fl_cur_frame_buff_P++ = fl_rpt_data_U16;
        fl_cur_x_size--;
        if(fl_cur_x_size == 0)
        {
          fl_y_size--;
          fl_frame_buff_P    += l_drv_context_S.fb_w;
          fl_cur_frame_buff_P = fl_frame_buff_P;
          fl_cur_x_size       = fl_x_size;
        }
      }
    }
    else
    {
      fl_rpt_data_U16   = (fl_header_U16 & 0xFFE0);
      fl_rpt_data_U16 <<= 1;
      fl_rpt_data_U16  += (fl_header_U16 & 0x1F);
      *fl_cur_frame_buff_P++ = fl_rpt_data_U16;
      fl_cur_x_size--;
      if(fl_cur_x_size == 0)
      {
        fl_y_size--;
        fl_frame_buff_P    += l_drv_context_S.fb_w;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
      }
    }
  }
#endif
}
#endif /*#if GFX_COMPRESSED_IMAGES > 0*/

/****************************************************************************
Function Name        : GfxDriverImageCopyFW
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverImageCopyFW(COORDINATE_DEF_T  const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T * fl_fb_P;
  GFX_SIZE_H_T  fl_y_size = pc_bitmap_def_S->h;

#ifdef WIN32
  UINT32 fl_tfr_size;
  if(fl_y_size ==l_drv_context_S.fb_h)
  {
    fl_tfr_size = (l_drv_context_S.fb_w*l_drv_context_S.fb_h*sizeof(GFX_COLOR_T));
    fl_fb_P     = l_drv_context_S.fb_P;
  }
  else
  {
    fl_tfr_size = (l_drv_context_S.fb_w*fl_y_size*sizeof(GFX_COLOR_T));
    fl_fb_P  = (void *)l_drv_context_S.fb_P;
    fl_fb_P += ((l_drv_context_S.fb_w*coord->y)+coord->x);
  }
  memcpy((void *)fl_fb_P, (void *)pc_bitmap_def_S->bmp_data, fl_tfr_size);
#else
  DMAC.CHCR0.BIT.DE = 0;
  DMAC.SAR0.LONG = (UINT32)pc_bitmap_def_S->bmp_data;
  if(fl_y_size ==l_drv_context_S.fb_h)
  {
    DMAC.DMATCR0.LONG   = (l_drv_context_S.fb_w*l_drv_context_S.fb_h);
    DMAC.DAR0.LONG = (UINT32)l_drv_context_S.fb_P;
  }
  else
  {
    DMAC.DMATCR0.LONG   = (l_drv_context_S.fb_w*fl_y_size);
    fl_fb_P  = (void *)l_drv_context_S.fb_P;
    fl_fb_P += ((l_drv_context_S.fb_w*coord->y)+coord->x);
    DMAC.DAR0.LONG = (UINT32)fl_fb_P;
  }
  DMAC.CHCR0.LONG   = 0x80005408;
  DMAC.CHCR0.BIT.DE = 1;
  while(DMAC.CHCR0.BIT.TE == 0);
#endif
}

/****************************************************************************
Function Name        : GfxDriverImageCopy
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverImageCopy(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
  GFX_SIZE_W_T        fl_x_size     = pc_bitmap_def_S->w;
  GFX_SIZE_H_T        fl_y_size     = pc_bitmap_def_S->h;
  GFX_SIZE_X_T        fl_x          = coord->x;
  GFX_SIZE_Y_T        fl_y          = coord->y;
  GFX_SIZE_W_T        fl_cur_x_size;

  fl_frame_buff_P  = l_drv_context_S.fb_P;
  fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);

#ifndef WIN32
  if(fl_cur_x_size >= GFX_DRV_DMA_TFR_THRESHOLD)
  {
    DMAC.DMAOR.BIT.DME= 1;
    /*
    ** First odd line in single DMA transfer
    */
    if(fl_y_size & 0x01)
    {
      DMAC.CHCR0.BIT.DE = 0;
      DMAC.SAR0.LONG    = (UINT32)fl_bmp_data_P;
      DMAC.DAR0.LONG    = (UINT32)fl_frame_buff_P;
      DMAC.DMATCR0.LONG = fl_x_size;
      DMAC.CHCR0.LONG   = 0x80005408;
      DMAC.CHCR0.BIT.DE = 1;
      fl_frame_buff_P  += l_drv_context_S.fb_w;
      fl_bmp_data_P    += fl_x_size;
      while(DMAC.CHCR0.BIT.TE == 0);
    }
    /*
    ** Use two DMA to transfer the rest of the lines
    */
    fl_y_size >>= 1;
    while(fl_y_size > 0)
    {
      fl_y_size--;
      DMAC.CHCR0.BIT.DE = 0;
      DMAC.SAR0.LONG    = (UINT32)fl_bmp_data_P;
      DMAC.DAR0.LONG    = (UINT32)fl_frame_buff_P;
      DMAC.DMATCR0.LONG = fl_x_size;
      DMAC.CHCR0.LONG   = 0x80005408;
      DMAC.CHCR0.BIT.DE = 1;
      fl_frame_buff_P  += l_drv_context_S.fb_w;
      fl_bmp_data_P    += fl_x_size;

      DMAC.CHCR1.BIT.DE = 0;
      DMAC.SAR1.LONG    = (UINT32)fl_bmp_data_P;
      DMAC.DAR1.LONG    = (UINT32)fl_frame_buff_P;
      DMAC.DMATCR1.LONG = fl_x_size;
      DMAC.CHCR1.LONG   = 0x80005408;
      DMAC.CHCR1.BIT.DE = 1;
      fl_frame_buff_P  += l_drv_context_S.fb_w;
      fl_bmp_data_P    += fl_x_size;

      while(DMAC.CHCR0.BIT.TE == 0);
      while(DMAC.CHCR1.BIT.TE == 0);
    }
  }
  else
#endif
    {
    while(fl_y_size)
    {
      fl_y_size--;
      fl_cur_frame_buff_P = fl_frame_buff_P;
      fl_cur_x_size       = fl_x_size;
      while(fl_cur_x_size)
      {
        fl_cur_x_size--;
        *fl_cur_frame_buff_P++ = *fl_bmp_data_P++;
      }
      fl_frame_buff_P += l_drv_context_S.fb_w;

    }
  }
}

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
/****************************************************************************
Function Name        : GfxDriverImageClip
Description          : Perform the validation of the image to set the possible
                       area for drawing operation w.r.t active clip area.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverImageClip(CLIP_IMAGE_DATA * p_clip_image_data_SP)
{
  GFX_SIZE_Y_T fl_h_offset;
  GFX_SIZE_H_T fl_y_size;
  GFX_SIZE_W_T fl_x_size;

  p_clip_image_data_SP->w_offset = 0;

  if(p_clip_image_data_SP->y > l_clip_area_S[0].y)
  {
    fl_h_offset = (p_clip_image_data_SP->y-l_clip_area_S[0].y);
    if(l_clip_area_S[0].h > fl_h_offset)
    {
      fl_y_size = (l_clip_area_S[0].h - fl_h_offset);
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
    fl_h_offset = (l_clip_area_S[0].y - p_clip_image_data_SP->y);
    if(fl_h_offset < p_clip_image_data_SP->h)
    {
      fl_y_size = (p_clip_image_data_SP->h-fl_h_offset);
      if(fl_y_size > l_clip_area_S[0].h)
      {
        fl_y_size = l_clip_area_S[0].h;
      }
      p_clip_image_data_SP->h             = fl_y_size;
      p_clip_image_data_SP->bmp_data_P   += (fl_h_offset*p_clip_image_data_SP->w);
      if(l_drv_context_S.fb_format == GFX_ARGB4444)
      {
        p_clip_image_data_SP->alpha_data_P += (fl_h_offset*((p_clip_image_data_SP->w+1)>>1));
      }
      else
      {
        p_clip_image_data_SP->alpha_data_P += (fl_h_offset*p_clip_image_data_SP->w);
      }
      p_clip_image_data_SP->frame_buff_P += (fl_h_offset*l_drv_context_S.fb_w);
    }
    else
    {
      p_clip_image_data_SP->h = 0;
    }
  }

  if(p_clip_image_data_SP->h != 0)
  {
    if(p_clip_image_data_SP->x > l_clip_area_S[0].x)
    {
      p_clip_image_data_SP->w_offset = (p_clip_image_data_SP->x-l_clip_area_S[0].x);
      if(l_clip_area_S[0].w > p_clip_image_data_SP->w_offset)
      {
        fl_x_size = l_clip_area_S[0].w - p_clip_image_data_SP->w_offset;
        if(fl_x_size > p_clip_image_data_SP->w)
        {
          p_clip_image_data_SP->w_offset = 0;
        }
        else
        {
          p_clip_image_data_SP->w_offset = (p_clip_image_data_SP->w-fl_x_size);
          p_clip_image_data_SP->w        = fl_x_size;
        }
      }
    }
    else if(p_clip_image_data_SP->x < l_clip_area_S[0].x)
    {
      p_clip_image_data_SP->w_offset = (l_clip_area_S[0].x - p_clip_image_data_SP->x);
      if(p_clip_image_data_SP->w_offset < p_clip_image_data_SP->w)
      {
        fl_x_size = (p_clip_image_data_SP->w - p_clip_image_data_SP->w_offset);
        if(fl_x_size > l_clip_area_S[0].w)
        {
          fl_x_size = l_clip_area_S[0].w;
        }
        p_clip_image_data_SP->bmp_data_P   += p_clip_image_data_SP->w_offset;
        p_clip_image_data_SP->alpha_data_P += p_clip_image_data_SP->w_offset;
        p_clip_image_data_SP->w_offset      = (p_clip_image_data_SP->w-fl_x_size);
        p_clip_image_data_SP->w             = fl_x_size;
      }
    }
    else
    {
    }
  }
}
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildBitmapImage(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_bitmap_def_S->bmp_data);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_IMAGE_DATA fl_clip_image_data_S;
    GFX_SIZE_W_T    fl_cur_x_size;
    GFX_COLOR_T   * fl_cur_frame_buff_P;

    fl_clip_image_data_S.bmp_data_P    = pc_bitmap_def_S->bmp_data;
    fl_clip_image_data_S.x             = coord->x;
    fl_clip_image_data_S.y             = coord->y;
    fl_clip_image_data_S.w             = pc_bitmap_def_S->w;
    fl_clip_image_data_S.h             = pc_bitmap_def_S->h;
    fl_clip_image_data_S.frame_buff_P  = l_drv_context_S.fb_P;
    fl_clip_image_data_S.frame_buff_P += ((fl_clip_image_data_S.y * l_drv_context_S.fb_w) +
      fl_clip_image_data_S.x);
    GfxDriverImageClip(&fl_clip_image_data_S);

   #ifndef WIN32
    if(fl_clip_image_data_S.w >= GFX_DRV_DMA_TFR_THRESHOLD)
    {
      DMAC.DMAOR.BIT.DME= 1;
      /*
      ** First odd line in single DMA transfer
      */
      fl_clip_image_data_S.w_offset += fl_clip_image_data_S.w;
      if(fl_clip_image_data_S.h & 0x01)
      {
        DMAC.CHCR0.BIT.DE = 0;
        DMAC.SAR0.LONG    = (UINT32)fl_clip_image_data_S.bmp_data_P;
        DMAC.DAR0.LONG    = (UINT32)fl_clip_image_data_S.frame_buff_P;
        DMAC.DMATCR0.LONG = fl_clip_image_data_S.w;
        DMAC.CHCR0.LONG   = 0x80005408;
        DMAC.CHCR0.BIT.DE = 1;
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
        while(DMAC.CHCR0.BIT.TE == 0);
      }
      /*
      ** Use two DMA to transfer the rest of the lines
      */
      fl_clip_image_data_S.h >>= 1;
      while(fl_clip_image_data_S.h > 0)
      {
        fl_clip_image_data_S.h--;
        DMAC.CHCR0.BIT.DE = 0;
        DMAC.SAR0.LONG    = (UINT32)fl_clip_image_data_S.bmp_data_P;
        DMAC.DAR0.LONG    = (UINT32)fl_clip_image_data_S.frame_buff_P;
        DMAC.DMATCR0.LONG = fl_clip_image_data_S.w;
        DMAC.CHCR0.LONG   = 0x80005408;
        DMAC.CHCR0.BIT.DE = 1;
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
        DMAC.CHCR1.BIT.DE = 0;
        DMAC.SAR1.LONG    = (UINT32)fl_clip_image_data_S.bmp_data_P;
        DMAC.DAR1.LONG    = (UINT32)fl_clip_image_data_S.frame_buff_P;
        DMAC.DMATCR1.LONG = fl_clip_image_data_S.w;
        DMAC.CHCR1.LONG   = 0x80005408;
        DMAC.CHCR1.BIT.DE = 1;
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
        while(DMAC.CHCR0.BIT.TE == 0);
        while(DMAC.CHCR1.BIT.TE == 0);
      }
    }
    else
   #endif
      {
      while(fl_clip_image_data_S.h)
      {
        fl_clip_image_data_S.h--;
        fl_cur_frame_buff_P = fl_clip_image_data_S.frame_buff_P;
        fl_cur_x_size       = fl_clip_image_data_S.w;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          *fl_cur_frame_buff_P++ = *fl_clip_image_data_S.bmp_data_P++;
        }
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
      }
    }
  }
  else
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */
  if(pc_bitmap_def_S->w > l_drv_context_S.fb_w)
  {
    GfxDriverImageCopyAreaFW(coord, pc_bitmap_def_S);
  }
  else if(pc_bitmap_def_S->w == l_drv_context_S.fb_w)
  {
   #if GFX_COMPRESSED_IMAGES > 0
    if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSLESS)
    {
      GfxDriverLossLessCompImageCopyFW(coord, pc_bitmap_def_S);
    }
    else if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSLESS)
    {
      GfxDriverLossyCompImageCopyFW(coord, pc_bitmap_def_S);
    }
    else
   #endif
      {
      GfxDriverImageCopyFW(coord, pc_bitmap_def_S);
    }
  }
  else
  {
   #if GFX_COMPRESSED_IMAGES > 0
    if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSLESS)
    {
      GfxDriverLossLessCompImageCopy(coord, pc_bitmap_def_S);
    }
    else if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSLESS)
    {
      GfxDriverLossyCompImageCopy(coord, pc_bitmap_def_S);
    }
    else
   #endif
    {
      GfxDriverImageCopy(coord, pc_bitmap_def_S);
    }
  }
}
#endif /*#if NB_BITMAPS > 0*/

#if NB_ALPHAMAP > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildAlphaMapImage(COORDINATE_DEF_T  const * coord, ALPHAMAP_DEF_T const * pc_bitmap_def_S)
{
#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_bitmap_def_S->alpha_data);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    GFX_COLOR_T         fl_color;
    GFX_SIZE_W_T        fl_cur_x_size;
    GFX_COLOR_T       * fl_cur_frame_buff_P;
    CLIP_IMAGE_DATA     fl_clip_image_data_S;

    fl_clip_image_data_S.alpha_data_P  = pc_bitmap_def_S->alpha_data;
    fl_clip_image_data_S.x             = coord->x;
    fl_clip_image_data_S.y             = coord->y;
    fl_clip_image_data_S.w             = pc_bitmap_def_S->w;
    fl_clip_image_data_S.h             = pc_bitmap_def_S->h;
    fl_color                           = pc_bitmap_def_S->color;
    fl_clip_image_data_S.frame_buff_P  = l_drv_context_S.fb_P;
    fl_clip_image_data_S.frame_buff_P += ((fl_clip_image_data_S.y * l_drv_context_S.fb_w) +
      fl_clip_image_data_S.x);
    GfxDriverImageClip(&fl_clip_image_data_S);
    if(l_drv_context_S.fb_format == GFX_ARGB4444)
    {
      GFX_COLOR_T fl_alpha_1;
      GFX_COLOR_T fl_alpha_2;

      while(fl_clip_image_data_S.h)
      {
        fl_clip_image_data_S.h--;
        fl_cur_frame_buff_P = fl_clip_image_data_S.frame_buff_P;
        fl_cur_x_size       = fl_clip_image_data_S.w;
        fl_cur_x_size     >>= 1;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_alpha_1 = *fl_clip_image_data_S.alpha_data_P++;
          fl_alpha_2 = (fl_alpha_1 & 0xF0);
          if(fl_alpha_2 != 0)
          {
            fl_alpha_2 <<= 8;
            fl_alpha_2  += fl_color;
            *fl_cur_frame_buff_P = fl_alpha_2;
          }
          fl_cur_frame_buff_P++;
          fl_alpha_1 &= 0x000F;
          if(fl_alpha_1 != 0)
          {
            fl_alpha_1 <<= 12;
            fl_alpha_1  += fl_color;
            *fl_cur_frame_buff_P = fl_alpha_1;
          }
          fl_cur_frame_buff_P++;
        }
        if((fl_clip_image_data_S.w & 0x01) != 0)
        {
          fl_alpha_1 = *fl_clip_image_data_S.alpha_data_P++;
          if(fl_alpha_1 != 0)
          {
            fl_alpha_1   <<= 8;
            fl_alpha_1    += fl_color;
            *fl_cur_frame_buff_P = fl_alpha_1;
          }
        }
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.alpha_data_P += fl_clip_image_data_S.w_offset;
      }
    }
    else
    {
      SINT32      fl_BgR;
      SINT32      fl_BgG;
      SINT32      fl_BgB;
      SINT32      fl_fgR;
      SINT32      fl_fgG;
      SINT32      fl_fgB;
      SINT32      fl_alpha;

      if(fl_color != 0)
      {
        fl_fgB   = fl_color;
        fl_fgG   = (fl_fgB >> 5);
        fl_fgR   = (fl_fgG >> 6);
        fl_fgB  &= 0x1F;
        fl_fgG  &= 0x3F;
      }
      else
      {
        fl_fgR = 0;
        fl_fgG = 0;
        fl_fgB = 0;
      }
      while(fl_clip_image_data_S.h)
      {
        fl_clip_image_data_S.h--;
        fl_cur_frame_buff_P = fl_clip_image_data_S.frame_buff_P;
        fl_cur_x_size       = fl_clip_image_data_S.w;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_alpha  = *fl_clip_image_data_S.alpha_data_P++;
          fl_alpha &= 0xFC;
          if(fl_alpha == 0)
          {
            *fl_cur_frame_buff_P++;
          }
          else if(fl_alpha == 0xFC)
          {
            *fl_cur_frame_buff_P++ = fl_color;
          }
          else
          {
            /* Load BG Color */
            fl_BgB   = *fl_cur_frame_buff_P;
            fl_BgG   = (fl_BgB >> 5);
            fl_BgR   = (fl_BgG >> 6);
            fl_BgB  &= 0x1F;
            fl_BgG  &= 0x3F;
            /* Blend */
            fl_BgR   = (((fl_BgR << 8) + (fl_alpha * (fl_fgR - fl_BgR))) >> 8);
            fl_BgG   = (((fl_BgG << 8) + (fl_alpha * (fl_fgG - fl_BgG))) >> 8);
            fl_BgB   = (((fl_BgB << 8) + (fl_alpha * (fl_fgB - fl_BgB))) >> 8);
            fl_BgB  += ((fl_BgG << 5) + (fl_BgR << 11));
            /* Writeback */
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_BgB;
          }
        }
        fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
        fl_clip_image_data_S.alpha_data_P += fl_clip_image_data_S.w_offset;
      }
    }
  }
  else
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */
    {
    SINT32              fl_BgR;
    SINT32              fl_BgG;
    SINT32              fl_BgB;
    SINT32              fl_fgR;
    SINT32              fl_fgG;
    SINT32              fl_fgB;
    SINT32              fl_alpha;
    GFX_COLOR_T         fl_color;
    GFX_SIZE_W_T        fl_cur_x_size;
    GFX_ALPHA_T const * fl_alpha_data_P;
    GFX_COLOR_T       * fl_cur_frame_buff_P;
    GFX_COLOR_T       * fl_frame_buff_P;
    GFX_SIZE_W_T        fl_x_size = pc_bitmap_def_S->w;
    GFX_SIZE_H_T        fl_y_size = pc_bitmap_def_S->h;

    fl_alpha_data_P  = pc_bitmap_def_S->alpha_data;
    fl_color         = pc_bitmap_def_S->color;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w) +
      coord->x);

    if(l_drv_context_S.fb_format == GFX_ARGB4444)
    {
      while(fl_y_size)
      {
        fl_y_size--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
        fl_cur_x_size     >>= 1;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_BgR = *fl_alpha_data_P++;
          fl_BgG = (fl_BgR & 0x00F0);
          if(fl_BgG != 0)
          {
            fl_BgG   <<= 8;
            fl_BgG    += fl_color;
            *fl_cur_frame_buff_P = (GFX_COLOR_T)fl_BgG;
          }
          fl_cur_frame_buff_P++;
          fl_BgR &= 0x000F;
          if(fl_BgR != 0)
          {
            fl_BgR   <<= 12;
            fl_BgR    += fl_color;
            *fl_cur_frame_buff_P = (GFX_COLOR_T)fl_BgR;
          }
          fl_cur_frame_buff_P++;
        }
        if((fl_x_size & 0x01) != 0)
        {
          fl_BgR = *fl_alpha_data_P++;
          if(fl_BgR != 0)
          {
            fl_BgR   <<= 8;
            fl_BgR    += fl_color;
            *fl_cur_frame_buff_P = (GFX_COLOR_T)fl_BgR;
          }
        }
        fl_frame_buff_P += l_drv_context_S.fb_w;
      }
    }
    else
    {
      if(fl_color != 0)
      {
        fl_fgB   = fl_color;
        fl_fgG   = (fl_fgB >> 5);
        fl_fgR   = (fl_fgG >> 6);
        fl_fgB  &= 0x1F;
        fl_fgG  &= 0x3F;
      }
      else
      {
        fl_fgR = 0;
        fl_fgG = 0;
        fl_fgB = 0;
      }
      while(fl_y_size)
      {
        fl_y_size--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_alpha  = *fl_alpha_data_P++;
          fl_alpha &= 0xFC;
          if(fl_alpha == 0)
          {
            *fl_cur_frame_buff_P++;
          }
          else if(fl_alpha == 0xFC)
          {
            *fl_cur_frame_buff_P++ = fl_color;
          }
          else
          {
            /* Load BG Color */
            fl_BgB   = *fl_cur_frame_buff_P;
            fl_BgG   = (fl_BgB >> 5);
            fl_BgR   = (fl_BgG >> 6);
            fl_BgB  &= 0x1F;
            fl_BgG  &= 0x3F;
            /* Blend */
            fl_BgR   = (((fl_BgR << 8) + (fl_alpha * (fl_fgR - fl_BgR))) >> 8);
            fl_BgG   = (((fl_BgG << 8) + (fl_alpha * (fl_fgG - fl_BgG))) >> 8);
            fl_BgB   = (((fl_BgB << 8) + (fl_alpha * (fl_fgB - fl_BgB))) >> 8);
            fl_BgB  += ((fl_BgG << 5) + (fl_BgR << 11));
            /* Writeback */
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_BgB;
          }
        }
        fl_frame_buff_P += l_drv_context_S.fb_w;
      }
    }
  }
}
#endif /*#if NB_ALPHAMAP > 0*/

#if NB_COLORTRANSBITMAP > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildColorTransBitMapImage(COORDINATE_DEF_T const * coord, COLORTRANSMAP_DEF_T const * pc_bitmap_def_S)
{
#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_bitmap_def_S->bmp_data);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_IMAGE_DATA fl_clip_image_data_S;
    GFX_SIZE_W_T    fl_cur_x_size;
    GFX_COLOR_T   * fl_cur_frame_buff_P;
    GFX_COLOR_T     fl_transP_color;
    GFX_COLOR_T     fl_draw_color;

    fl_transP_color                    = pc_bitmap_def_S->color;
    fl_clip_image_data_S.bmp_data_P    = pc_bitmap_def_S->bmp_data;
    fl_clip_image_data_S.x             = coord->x;
    fl_clip_image_data_S.y             = coord->y;
    fl_clip_image_data_S.w             = pc_bitmap_def_S->w;
    fl_clip_image_data_S.h             = pc_bitmap_def_S->h;
    fl_clip_image_data_S.frame_buff_P  = l_drv_context_S.fb_P;
    fl_clip_image_data_S.frame_buff_P += ((fl_clip_image_data_S.y * l_drv_context_S.fb_w) +
      fl_clip_image_data_S.x);
    GfxDriverImageClip(&fl_clip_image_data_S);
    while(fl_clip_image_data_S.h)
    {
      fl_clip_image_data_S.h--;
      fl_cur_frame_buff_P = fl_clip_image_data_S.frame_buff_P;
      fl_cur_x_size       = fl_clip_image_data_S.w;
      while(fl_cur_x_size)
      {
        fl_cur_x_size--;
        fl_draw_color = *fl_clip_image_data_S.bmp_data_P;
        if(fl_transP_color != fl_draw_color)
        {
          *fl_cur_frame_buff_P = fl_draw_color;
        }
        fl_clip_image_data_S.bmp_data_P++;
        fl_cur_frame_buff_P++;
      }
      fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
      fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
    }
  }
  else
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */
    {
    GFX_SIZE_W_T        fl_cur_x_size;
    GFX_COLOR_T const * fl_bmp_data_P;
    GFX_COLOR_T       * fl_cur_frame_buff_P;
    GFX_COLOR_T       * fl_frame_buff_P;
    GFX_SIZE_W_T        fl_x_size;
    GFX_SIZE_H_T        fl_y_size;
    GFX_COLOR_T         fl_transP_color;
    GFX_COLOR_T         fl_draw_color;

    fl_x_size        = pc_bitmap_def_S->w;
    fl_y_size        = pc_bitmap_def_S->h;
    fl_transP_color  = pc_bitmap_def_S->color;
    fl_bmp_data_P    = pc_bitmap_def_S->bmp_data;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);

    while(fl_y_size)
    {
      fl_y_size--;
      fl_cur_frame_buff_P = fl_frame_buff_P;
      fl_cur_x_size       = fl_x_size;
      while(fl_cur_x_size)
      {
        fl_cur_x_size--;
        fl_draw_color = *fl_bmp_data_P;
        if(fl_transP_color != fl_draw_color)
        {
          *fl_cur_frame_buff_P = fl_draw_color;
        }
        fl_cur_frame_buff_P++;
        fl_bmp_data_P++;
      }
      fl_frame_buff_P += l_drv_context_S.fb_w;
    }
  }
}
#endif  /*#if NB_COLORTRANSBITMAP > 0*/

#if NB_ALPHABITMAP > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildAlphaBitMapImage(COORDINATE_DEF_T const * coord, ALPHABITMAP_DEF_T const * pc_bitmap_def_S)
{
#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_bitmap_def_S->alpha_data);
#endif
  if(pc_bitmap_def_S->alpha_data == 0)
  {
    BITMAP_DEF_T fl_bitmap_def_S;
   #if GFX_COMPRESSED_IMAGES > 0
    fl_bitmap_def_S.info       = GFX_IMAGE_COMPRESSION_NONE;
    fl_bitmap_def_S.data_size  = 0;
   #endif
    fl_bitmap_def_S.w          = pc_bitmap_def_S->w;
    fl_bitmap_def_S.h          = pc_bitmap_def_S->h;
    fl_bitmap_def_S.bmp_data   = pc_bitmap_def_S->bmp_data;
    GfxDriverBuildBitmapImage(coord, &fl_bitmap_def_S);
  }
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  else if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_IMAGE_DATA fl_clip_image_data_S;
    GFX_SIZE_W_T    fl_cur_x_size;
    GFX_COLOR_T   * fl_cur_frame_buff_P;
    SINT32          fl_BgR;
    SINT32          fl_BgG;
    SINT32          fl_BgB;
    SINT32          fl_fgR;
    SINT32          fl_fgG;
    SINT32          fl_fgB;
    SINT32          fl_alpha;
    SINT32          fl_prevalpha = 0xFFFF;
    SINT32          fl_prev_bg;
    SINT32          fl_prev_fg;

    fl_clip_image_data_S.bmp_data_P    = pc_bitmap_def_S->bmp_data;
    fl_clip_image_data_S.alpha_data_P  = pc_bitmap_def_S->alpha_data;
    fl_clip_image_data_S.x             = coord->x;
    fl_clip_image_data_S.y             = coord->y;
    fl_clip_image_data_S.w             = pc_bitmap_def_S->w;
    fl_clip_image_data_S.h             = pc_bitmap_def_S->h;
    fl_clip_image_data_S.frame_buff_P  = l_drv_context_S.fb_P;
    fl_clip_image_data_S.frame_buff_P += ((fl_clip_image_data_S.y * l_drv_context_S.fb_w) +
      fl_clip_image_data_S.x);
    GfxDriverImageClip(&fl_clip_image_data_S);

    while(fl_clip_image_data_S.h)
    {
      fl_clip_image_data_S.h--;
      fl_cur_frame_buff_P = fl_clip_image_data_S.frame_buff_P;
      fl_cur_x_size       = fl_clip_image_data_S.w;
      while(fl_cur_x_size)
      {
        fl_cur_x_size--;
        fl_alpha  = *fl_clip_image_data_S.alpha_data_P++;
        fl_alpha &= 0xFC;
        if(fl_alpha == 0)
        {
          *fl_cur_frame_buff_P++;
          *fl_clip_image_data_S.bmp_data_P++;
        }
        else if(fl_alpha == 255)
        {
          *fl_cur_frame_buff_P++ = *fl_clip_image_data_S.bmp_data_P++;
        }
        else if((fl_prev_fg == *fl_clip_image_data_S.bmp_data_P) && (fl_alpha == fl_prevalpha) && (fl_prev_bg == *fl_cur_frame_buff_P))
        {
          *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_fgB;
          fl_clip_image_data_S.bmp_data_P++;
        }
        else
        {
          fl_prevalpha = fl_alpha;
          fl_prev_bg   = *fl_cur_frame_buff_P;
          fl_prev_fg   = *fl_clip_image_data_S.bmp_data_P++;

          fl_fgB   = fl_prev_fg;
          fl_fgG   = (fl_fgB >> 5);
          fl_fgR   = (fl_fgG >> 6);
          fl_fgB  &= 0x1F;
          fl_fgG  &= 0x3F;
          /* Load BG Color */
          fl_BgB   = fl_prev_bg;
          fl_BgG   = (fl_BgB >> 5);
          fl_BgR   = (fl_BgG >> 6);
          fl_BgB  &= 0x1F;
          fl_BgG  &= 0x3F;
          /* Blend */
          fl_fgR   = (((fl_BgR << 8) + (fl_alpha * (fl_fgR - fl_BgR))) >> 8);

          fl_fgG   = (((fl_BgG << 8) + (fl_alpha * (fl_fgG - fl_BgG))) >> 8);
          fl_fgB   = (((fl_BgB << 8) + (fl_alpha * (fl_fgB - fl_BgB))) >> 8);
          fl_fgB  += ((fl_fgG << 5) + (fl_fgR << 11));

          /* Writeback */
          *fl_cur_frame_buff_P++ = fl_fgB;
        }
      }
      fl_clip_image_data_S.frame_buff_P += l_drv_context_S.fb_w;
      fl_clip_image_data_S.bmp_data_P   += fl_clip_image_data_S.w_offset;
      fl_clip_image_data_S.alpha_data_P += fl_clip_image_data_S.w_offset;
    }
  }
#endif /*#ifdef GFX_CLIPPED_WIDGETS_ENABLED*/
  else
  {
    SINT32              fl_BgR;
    SINT32              fl_BgG;
    SINT32              fl_BgB;
    SINT32              fl_fgR;
    SINT32              fl_fgG;
    SINT32              fl_fgB;
    SINT32              fl_alpha;
    GFX_SIZE_W_T        fl_cur_x_size;
    GFX_COLOR_T const * fl_bmp_data_P;
    GFX_ALPHA_T const * fl_alpha_data_P;
    GFX_COLOR_T       * fl_cur_frame_buff_P;
    GFX_COLOR_T       * fl_frame_buff_P;
    GFX_SIZE_W_T        fl_x_size = pc_bitmap_def_S->w;
    GFX_SIZE_H_T        fl_y_size = pc_bitmap_def_S->h;

    SINT32      fl_prevalpha;
    GFX_COLOR_T fl_prev_bg;
    GFX_COLOR_T fl_prev_fg;

    fl_bmp_data_P    = pc_bitmap_def_S->bmp_data;
    fl_alpha_data_P  = pc_bitmap_def_S->alpha_data;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_prevalpha     = 0xFFFF;

    if(fl_x_size > l_drv_context_S.fb_w)
    {
      fl_frame_buff_P += (coord->y * l_drv_context_S.fb_w);
      fl_bmp_data_P   += coord->x;
      fl_alpha_data_P += coord->x;

      while(fl_y_size)
      {
        fl_y_size--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = l_drv_context_S.fb_w;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_alpha  = *fl_alpha_data_P++;
          fl_alpha &= 0xFC;
          if(fl_alpha == 0x00)
          {
            *fl_cur_frame_buff_P++;
            *fl_bmp_data_P++;
          }
          else if(fl_alpha == 0xFC)
          {
            *fl_cur_frame_buff_P++ = *fl_bmp_data_P++;
          }
          else if((fl_prev_fg == *fl_bmp_data_P) && (fl_alpha == fl_prevalpha) && (fl_prev_bg == *fl_cur_frame_buff_P))
          {
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_fgB;
            fl_bmp_data_P++;
          }
          else
          {
            fl_prevalpha = fl_alpha;
            fl_prev_bg   = *fl_cur_frame_buff_P;
            fl_prev_fg   = *fl_bmp_data_P++;

            fl_fgB   = fl_prev_fg;
            fl_fgG   = (fl_fgB >> 5);
            fl_fgR   = (fl_fgG >> 6);
            fl_fgB  &= 0x1F;
            fl_fgG  &= 0x3F;
            /* Load BG Color */
            fl_BgB   = fl_prev_bg;
            fl_BgG   = (fl_BgB >> 5);
            fl_BgR   = (fl_BgG >> 6);
            fl_BgB  &= 0x1F;
            fl_BgG  &= 0x3F;
            /* Blend */
            fl_fgR  = (((fl_BgR << 8) + (fl_alpha * (fl_fgR - fl_BgR))) >> 8);
            fl_fgG  = (((fl_BgG << 8) + (fl_alpha * (fl_fgG - fl_BgG))) >> 8);
            fl_fgB  = (((fl_BgB << 8) + (fl_alpha * (fl_fgB - fl_BgB))) >> 8);
            fl_fgB += ((fl_fgG << 5) + (fl_fgR << 11));
            /* Writeback */
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_fgB;
          }
        }
        fl_frame_buff_P += l_drv_context_S.fb_w;
        fl_bmp_data_P   += (fl_x_size-l_drv_context_S.fb_w);
        fl_alpha_data_P += (fl_x_size-l_drv_context_S.fb_w);
      }
    }
    else
    {
      fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);
      while(fl_y_size)
      {
        fl_y_size--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_x_size       = fl_x_size;
        while(fl_cur_x_size)
        {
          fl_cur_x_size--;
          fl_alpha  = *fl_alpha_data_P++;
          fl_alpha &= 0xFC; /* @RGB565 maximum alpha levels are only 64 */
          if(fl_alpha == 0x00)
          {
            *fl_cur_frame_buff_P++;
            *fl_bmp_data_P++;
          }
          else if(fl_alpha == 0xFC)
          {
            *fl_cur_frame_buff_P++ = *fl_bmp_data_P++;
          }
          else if((fl_prev_fg == *fl_bmp_data_P) && (fl_alpha == fl_prevalpha) && (fl_prev_bg == *fl_cur_frame_buff_P))
          {
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_fgB;
            fl_bmp_data_P++;
          }
          else
          {
            fl_prevalpha = fl_alpha;
            fl_prev_bg   = *fl_cur_frame_buff_P;
            fl_prev_fg   = *fl_bmp_data_P++;

            fl_fgB   = fl_prev_fg;
            fl_fgG   = (fl_fgB >> 5);
            fl_fgR   = (fl_fgG >> 6);
            fl_fgB  &= 0x1F;
            fl_fgG  &= 0x3F;
            /* Load BG Color */
            fl_BgB   = fl_prev_bg;
            fl_BgG   = (fl_BgB >> 5);
            fl_BgR   = (fl_BgG >> 6);
            fl_BgB  &= 0x1F;
            fl_BgG  &= 0x3F;
            /* Blend */
            fl_fgR  = (((fl_BgR << 8) + (fl_alpha * (fl_fgR - fl_BgR))) >> 8);
            fl_fgG  = (((fl_BgG << 8) + (fl_alpha * (fl_fgG - fl_BgG))) >> 8);
            fl_fgB  = (((fl_BgB << 8) + (fl_alpha * (fl_fgB - fl_BgB))) >> 8);
            fl_fgB += ((fl_fgG << 5) + (fl_fgR << 11));
            /* Writeback */
            *fl_cur_frame_buff_P++ = (GFX_COLOR_T)fl_fgB;
          }
        }
        fl_frame_buff_P += l_drv_context_S.fb_w;
      }
    }
  }
}
#endif /*#if NB_ALPHABITMAP > 0*/

#if NB_UNIALPHAMAP > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildUniAlphaMapImage(COORDINATE_DEF_T const * coord, UNIALPHAMAP_DEF_T const * pc_bitmap_def_S)
{
  if(l_drv_context_S.fb_format == GFX_ARGB4444)
  {
    FILL_SCREEN_DEF_T fl_fill_def_S;
    fl_fill_def_S.width  = pc_bitmap_def_S->w;
    fl_fill_def_S.height = pc_bitmap_def_S->h;
    fl_fill_def_S.color  = pc_bitmap_def_S->color;
    GfxDriverBuildFillScreen(coord, &fl_fill_def_S);
  }
}
#endif /*#if NB_UNIALPHAMAP > 0*/

#if NB_UNIALPHABITMAP > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildUniAlphaBitMapImage(COORDINATE_DEF_T const * coord, UNIALPHABITMAP_DEF_T const * pc_bitmap_def_S)
{
}
#endif /*#if NB_UNIALPHABITMAP > 0*/

#if NB_DYN_TEXTS > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriver_2bppAA_PixelWrite(GFX_COLOR_T * p_dest_buff_ptr, UINT8 aa, GFX_COLOR_T color)
{
  GFX_COLOR_T fgR;
  GFX_COLOR_T fgG;
  GFX_COLOR_T fgB;
  GFX_COLOR_T bgR;
  GFX_COLOR_T bgG;
  GFX_COLOR_T bgB;
  UINT32      fl_BgColor;

  fgB = (color &  0x1F);
  fgG = (color >> 5);
  fgR = (fgG >> 6);
  fgG = (fgG & 0x3F);

  fl_BgColor = *p_dest_buff_ptr;
  bgB = (GFX_COLOR_T)(fl_BgColor &  0x1F);
  bgG = (GFX_COLOR_T)(fl_BgColor >> 5);
  bgR = (bgG >> 6);
  bgG = (bgG & 0x3F);

  if(aa == 0x80)
  {
    fgR += ((fgR << 2) + (bgR << 1) + bgR);
    fgG += ((fgG << 2) + (bgG << 1) + bgG);
    fgB += ((fgB << 2) + (bgB << 1) + bgB);
  }
  else
  {
    fgR += ((fgR << 1) + (bgR << 2) + bgR);
    fgG += ((fgG << 1) + (bgG << 2) + bgG);
    fgB += ((fgB << 1) + (bgB << 2) + bgB);
  }
  fgR >>= 3;
  fgG >>= 3;
  fgB >>= 3;
  *p_dest_buff_ptr = fgB + (fgG << 5) + (fgR << (6 + 5));
}

/****************************************************************************
Function Name        : GfxDriverGetCharConfigInfo
Description          : Searches for the passed character in the font table
                       and returns the pointer to the char info structure.
                       If the char is missing then returns pointer to the 
                       default char if configured else returns NULL pointer.
Invocation           : Invoke with Char to be looked and Font table pointer
Parameters           : p_char        - Char to be searched
                       fl_font_tbl_P - Pointer to font table
Return Value         : Char info structure pointer or NULL pointer
Critical Section     : None
External Interfaces  : Font data tables.
******************************************************************************/
static GFX_FONT_CHAR_CONFIG const * GfxDriverGetCharConfigInfo(GFX_CHAR p_char, GFX_FONT const * fl_font_tbl_P)
{
  GFX_FONT_LUT         const * fl_font_lut_P  = fl_font_tbl_P->lut_ptr;
  GFX_FONT_CHAR_CONFIG const * fl_font_base_P = 0;

#if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID) || (GFX_CHAR_SEARCH_MODE == GFX_LUP_LINEAR)
 #if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID)
  if(fl_font_tbl_P->size_table <= 8)
 #endif
  {
    GFX_CHAR                     fl_base_char_code;
    GFX_CHAR                     fl_linear_temp_cnt;
    for(fl_linear_temp_cnt=0; fl_linear_temp_cnt<fl_font_tbl_P->size_table; fl_linear_temp_cnt++)
    {
      if(p_char == fl_font_lut_P->ch_code)
      {
        fl_font_base_P = fl_font_lut_P->fcc_ptr;
        break;
      }
      else if(p_char > fl_font_lut_P->ch_code)
      {
        if((fl_font_lut_P->attributes & GFX_FONT_SEARCH_MODE_TLUP) == GFX_FONT_SEARCH_MODE_TLUP)
        {
          fl_font_base_P    = fl_font_lut_P->fcc_ptr;
          fl_base_char_code = fl_font_lut_P->ch_code;
          fl_font_lut_P++;
          if(p_char <= fl_font_lut_P->ch_code)
          {
            if(p_char != fl_font_lut_P->ch_code)
            {
              fl_font_base_P = &fl_font_base_P[p_char - fl_base_char_code];
            }
            break;
          }
          else
          {
            fl_font_base_P = 0;
          }
          fl_linear_temp_cnt++;
        }
      }
      else
      {
        break;
      }
      fl_font_lut_P++;
    }
  }
#endif
#if GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID
  else
#endif
#if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID) || (GFX_CHAR_SEARCH_MODE == GFX_LUP_BINARY)
    {
    UINT16 fl_high_U16 = fl_font_tbl_P->size_table - 1;
    UINT16 fl_low_U16  = 0;
    UINT16 fl_mid_U16;

    while(fl_high_U16 > fl_low_U16)
    {
      fl_mid_U16 =  (fl_high_U16 - fl_low_U16)>>1;

      if(fl_mid_U16 != 0)
      {
        if(fl_font_lut_P[fl_mid_U16].ch_code < p_char)
        {
          fl_low_U16 = fl_mid_U16 + fl_low_U16;
        }
        else
        {
          fl_high_U16 = fl_mid_U16;
        }
      }
      else
      {
        if((fl_font_lut_P[fl_low_U16].attributes & GFX_FONT_SEARCH_MODE_TLUP) == GFX_FONT_SEARCH_MODE_TLUP)
        {
          if(p_char >= fl_font_lut_P[fl_low_U16].ch_code)
          {
            fl_font_base_P    = fl_font_lut_P[fl_low_U16].fcc_ptr;
            fl_font_base_P    = &fl_font_base_P[p_char - fl_font_lut_P[fl_low_U16].ch_code];
          }
        }
        else
        {
          if(p_char == fl_font_lut_P[fl_high_U16].ch_code)
          {
            fl_font_base_P    = fl_font_lut_P[fl_high_U16].fcc_ptr;
            fl_font_base_P    = &fl_font_base_P[0];
          }
          else if(p_char == fl_font_lut_P[fl_low_U16].ch_code)
          {
            fl_font_base_P    = fl_font_lut_P[fl_low_U16].fcc_ptr;
            fl_font_base_P    = &fl_font_base_P[0];
          }
        }
        break;
      }
    }
  }
#endif
  return(fl_font_base_P);
}

#ifdef GFX_EXTENDED_CHAR_PRESENT
/****************************************************************************
Function Name        : GfxDriverGetExtendedCharConfigInfo
Description          : Returnes the char config info for the extended char.
Invocation           : Invoke with Char to be looked and Font table pointer
Parameters           : p_char        - Char to be searched
                       fl_font_tbl_P - Pointer to font table
Return Value         : Char info structure pointer or NULL pointer
Critical Section     : None
External Interfaces  : Font data tables.
******************************************************************************/
static GFX_FONT_CHAR_CONFIG const * GfxDriverGetExtendedCharConfigInfo(GFX_CHAR p_char, GFX_FONT const * p_font_tbl_P)
{
  GFX_FONT_CHAR_CONFIG const * fl_font_base_P;
  fl_font_base_P = GfxDriverGetCharConfigInfo(GFX_EXTENDED_CHAR_PREFIX, p_font_tbl_P);
  if(fl_font_base_P != 0)
  {
    p_char--;
    fl_font_base_P = &fl_font_base_P[p_char];
  }
  return(fl_font_base_P);
}
#endif
/****************************************************************************
Function Name        : GfxDriverGetTextWidth
Description          : Returns the total pixel width of the passed text string.
Invocation           : 
Parameters           : p_p_clip_text_info_SP->disp_string_P - Pointer to String 
Return Value         : 0 - String not clipped, 1 - String is clipped.
Critical Section     : None
External Interfaces  : 
******************************************************************************/
UINT8 GfxDriverGetTextWidth(GFX_TEXT_INFO * p_clip_text_info_SP, UINT8 * tot_char_count)
{
  GFX_FONT_CHAR_CONFIG const * fl_font_base_P;
  GFX_FONT const             * fl_font_tbl_P           = &lc_gfx_font_table[p_clip_text_info_SP->dyn_text_def_SP->font_id];
  UINT8                        fl_clip_flag_U8         = 0;
  UINT8                        fl_tot_nb_char          = 0;  /* total number of character in the original string */
  GFX_SIZE_X_T                 fl_tot_str_size         = 0;  /* Total size of string in pixel */
  GFX_SIZE_X_T                 fl_append_length        = 0;
  GFX_CHAR                   * fl_str_start_loc_P      = p_clip_text_info_SP->print_str_P;
  GFX_CHAR                   * fl_str_end_loc_P        = 0;
  GFX_SIZE_X_T                 fl_calc_width           = 0;

  p_clip_text_info_SP->print_length_U8 = 0;

  if(*fl_str_start_loc_P == 0)
  {
    p_clip_text_info_SP->print_width = 0;
  }
  else
  {
    if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_CLIP_APPEND) == GFX_TEXT_PROPERTY_CLIP_APPEND)
    {
      if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_CENTRE) != 0)
      {
#if GFX_APPEND_PROPERTY_ENABLED > 0
        fl_append_length = p_clip_text_info_SP->dyn_text_def_SP->ap_str_width * 2;
#endif
      }
      else
      {
				#if GFX_APPEND_PROPERTY_ENABLED > 0
        fl_append_length = p_clip_text_info_SP->dyn_text_def_SP->ap_str_width;
                #endif
      }
    }
    else
    {
      fl_append_length = 0;
    }

    fl_str_end_loc_P = fl_str_start_loc_P;

    while(fl_str_end_loc_P[0] != 0)
    {
      fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_str_end_loc_P, fl_font_tbl_P);

      if(fl_font_base_P != 0)
      {
        fl_tot_str_size += fl_font_base_P->owidth;
      }
      fl_str_end_loc_P++;
      fl_tot_nb_char++;
    }

    if(fl_append_length >= p_clip_text_info_SP->max_available_width ||
      fl_tot_str_size <= p_clip_text_info_SP->max_available_width)
    {
      fl_calc_width = p_clip_text_info_SP->max_available_width;
      fl_clip_flag_U8 = 0;
    }
    else
    {
      fl_calc_width = (p_clip_text_info_SP->max_available_width - fl_append_length);
      fl_clip_flag_U8 = GFX_DRIVER_TEXT_CLIP;
    }
    /* Clip text */
    if(fl_tot_str_size > p_clip_text_info_SP->max_available_width)
    {
      if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_RIGHT) != 0)
      {
        while(fl_tot_nb_char)
        {
          fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_str_start_loc_P, fl_font_tbl_P);

          fl_str_start_loc_P++;
          fl_tot_nb_char--;

          if(fl_font_base_P != 0)
          {
            fl_tot_str_size -= fl_font_base_P->owidth;

            if(fl_tot_str_size <= fl_calc_width)
            {
              break;
            }
          }
        }
        *tot_char_count = fl_tot_nb_char;
      }
      else if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_CENTRE) != 0)
      {
        while(fl_tot_nb_char)
        {
          fl_tot_nb_char--;
          fl_str_end_loc_P--;

          fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_str_end_loc_P, fl_font_tbl_P);

          if(fl_font_base_P != 0)
          {
            fl_tot_str_size -= fl_font_base_P->owidth;
          }
          if(fl_tot_nb_char)
          {
            fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_str_start_loc_P, fl_font_tbl_P);
            fl_str_start_loc_P++;
            fl_tot_nb_char--;

            if(fl_font_base_P != 0)
            {
              fl_tot_str_size -= fl_font_base_P->owidth;
            }
          }

          if(fl_tot_str_size <= fl_calc_width)
          {
            break;
          }
        }
        *tot_char_count = fl_tot_nb_char;
      }
      else
      {
        while(fl_tot_nb_char)
        {
          fl_tot_nb_char--;
          fl_str_end_loc_P--;

          fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_str_end_loc_P, fl_font_tbl_P);

          if(fl_font_base_P != 0)
          {
            fl_tot_str_size -= fl_font_base_P->owidth;

            if(fl_tot_str_size <= fl_calc_width)
            {
              break;
            }
          }
        }
        *tot_char_count = fl_tot_nb_char;
      }
    }
    else
    {
      *tot_char_count = fl_tot_nb_char;
    }

    p_clip_text_info_SP->print_str_P = fl_str_start_loc_P;
    p_clip_text_info_SP->print_width     = fl_tot_str_size;
    p_clip_text_info_SP->print_length_U8 = fl_tot_nb_char;
  }
  return(fl_clip_flag_U8);
}
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
GFX_SIZE_X_T GfxDriverTextRenderer(GFX_TEXT_INFO * p_text_info_SP,GFX_SIZE_X_T start_x,BOOLEAN clip_flag)
{
  GFX_SIZE_X_T                 fl_start_x       = p_text_info_SP->property_SP->coord.x;
  GFX_SIZE_Y_T                 fl_start_y       = p_text_info_SP->property_SP->coord.y;
  GFX_COLOR_T                  fl_draw_color    = p_text_info_SP->property_SP->draw_color;
  GFX_CHAR                   * fl_disp_string_P = p_text_info_SP->print_str_P;
  GFX_FONT             const * fl_font_tbl_P    = &lc_gfx_font_table[p_text_info_SP->dyn_text_def_SP->font_id];
  GFX_FONT_CHAR_CONFIG const * fl_font_base_P;
  GFX_COLOR_T                * fl_cur_frame_buff_P;
  GFX_COLOR_T                * fl_frame_buff_P;
  UINT8 const                * fl_font_data_P;
  UINT8                        fl_font_data;
  GFX_SIZE_Y_T                 fl_cur_y;
  GFX_SIZE_W_T                 fl_x_size;
  GFX_SIZE_W_T                 fl_font_width;
  GFX_SIZE_H_T                 fl_font_height;
  GFX_SIZE_W_T                 fl_cur_width;
  UINT8                        fl_pix_in_byte_count;
  UINT8                        fl_aa_data;

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  GFX_SIZE_Y_T                 fl_clip_end_y = (l_clip_area_S[0].h + l_clip_area_S[0].y);
#endif

  if(clip_flag == TRUE)
  {
    if((p_text_info_SP->dyn_text_def_SP->properties & (GFX_TEXT_PROPERTY_ALIGN_CENTRE|GFX_TEXT_PROPERTY_ALIGN_RIGHT)) != 0)
    {
      /* 
      ** Centre align the text by finding the total width of text
      */
      fl_x_size = p_text_info_SP->print_width;
      if((p_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_CENTRE) != 0)
      {
        fl_x_size >>= 1;
      }
      else
      {
        fl_x_size--;
      }
      if(fl_start_x > fl_x_size)
      {
        fl_start_x -= fl_x_size;
      }
      else
      {
        fl_start_x  = 0;
      }
    }
  }
  else
  {
    fl_start_x       = start_x;
  }
  while(p_text_info_SP->print_length_U8 != 0)
  {
    p_text_info_SP->print_length_U8--;
    #ifdef GFX_EXTENDED_CHAR_PRESENT
    if(*fl_disp_string_P == GFX_EXTENDED_CHAR_PREFIX)
    {
      if(fl_disp_string_P[1] != 0)
      {
        if(fl_disp_string_P[1] <= lc_max_extended_char_index_U8A[p_text_info_SP->dyn_text_def_SP->font_id])
        {
          fl_font_base_P = GfxDriverGetExtendedCharConfigInfo(fl_disp_string_P[1], fl_font_tbl_P);
        }
        else
        {
          fl_font_base_P = 0;
        }
        fl_disp_string_P++;
      }
      else
      {
        fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P, fl_font_tbl_P);
      }
    }
    else
    #endif
    {
      fl_font_base_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P, fl_font_tbl_P);
    }
    #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT
    if(fl_font_base_P == 0)
    {
      fl_font_base_P = lc_default_char_config_SPA[p_text_info_SP->dyn_text_def_SP->font_id];
    }
    #endif
    if(fl_font_base_P != 0)
    {
      fl_start_x     += fl_font_base_P->x_soffset;
      fl_cur_y        = (fl_start_y + fl_font_base_P->y_soffset);

      fl_font_width   = fl_font_base_P->width;

      fl_font_height  = fl_font_base_P->height;
      fl_font_data_P  = fl_font_base_P->fdata;

      if(fl_font_data_P != 0)
      {
        fl_frame_buff_P = l_drv_context_S.fb_P;
        fl_frame_buff_P+= ((fl_cur_y * l_drv_context_S.fb_w)+fl_start_x);

        while(fl_font_height)
        {
          fl_font_height--;
            #ifdef GFX_CLIPPED_WIDGETS_ENABLED
          if((fl_cur_y < l_clip_area_S[0].y) || (fl_cur_y >= fl_clip_end_y))
          {
            fl_font_data_P += ((fl_font_width+3)>>2);
          }
          else
            #endif
          {
            fl_cur_width        = fl_font_width;
            fl_cur_frame_buff_P = fl_frame_buff_P;

            while(fl_cur_width)
            {
              fl_font_data = *fl_font_data_P++;
              if(fl_font_data != 0)
              {
                if(fl_cur_width > 4)
                {
                  fl_pix_in_byte_count = 4;
                  fl_cur_width        -= 4;
                }
                else
                {
                  fl_pix_in_byte_count = (UINT8)fl_cur_width;
                  fl_cur_width         = 0;
                }

                while(fl_pix_in_byte_count)
                {
                  fl_pix_in_byte_count--;
                  fl_aa_data = (fl_font_data & 0xC0);
                  if(fl_aa_data != 0)
                  {
                    if(fl_aa_data == 0xC0)
                    {
                      *fl_cur_frame_buff_P = fl_draw_color;
                    }
                    else if(l_drv_context_S.fb_format == GFX_ARGB4444)
                    {
                      if(fl_aa_data == 0x40)
                      {
                        *fl_cur_frame_buff_P = (fl_draw_color & 0x0FFF) + 0x5000;
                      }
                      else
                      {
                        *fl_cur_frame_buff_P = (fl_draw_color & 0x0FFF) + 0xA000;
                      }
                    }
                    else
                    {
                      GfxDriver_2bppAA_PixelWrite(fl_cur_frame_buff_P, fl_aa_data, fl_draw_color);
                    }
                  }
                  fl_font_data <<= 2;
                  fl_cur_frame_buff_P++;
                }
              }
              else if(fl_cur_width > 4)
              {
                fl_cur_width        -= 4;
                fl_cur_frame_buff_P += 4;
              }
              else
              {
                break;
              }
            }
          }
            #ifdef GFX_CLIPPED_WIDGETS_ENABLED
          fl_cur_y++;
            #endif
          fl_frame_buff_P += l_drv_context_S.fb_w;
        }
      }
      fl_start_x += fl_font_base_P->x_eoffset;
    }
    fl_disp_string_P++;
  }
  return(fl_start_x);
}

/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
GFX_SIZE_X_T GfxDriverBuildText(GFX_TEXT_PROPERTY const * pc_property_SP, DYN_TEXT_DEF_T const * pc_dyn_text_def_S)
{
  GFX_TEXT_INFO fl_text_info_S;
  GFX_CHAR fl_app_str[4] = {'.','.','.','\0'};
  GFX_SIZE_X_T                 fl_start_x;
  UINT8 fl_clip_flag = 0;
  UINT8 temp = 0;
  fl_text_info_S.dyn_text_def_SP     = pc_dyn_text_def_S;
  fl_text_info_S.property_SP         = pc_property_SP;
  fl_text_info_S.print_str_P         = pc_dyn_text_def_S->data_ptr;

  fl_text_info_S.max_available_width = pc_dyn_text_def_S->width;

  fl_clip_flag = GfxDriverGetTextWidth(&fl_text_info_S,&temp);

  fl_start_x = GfxDriverTextRenderer(&fl_text_info_S,fl_text_info_S.property_SP->coord.x,TRUE );

  /* check if clipping is done */
  if(fl_clip_flag > 0)
  {
    if((pc_dyn_text_def_S->properties & GFX_TEXT_PROPERTY_CLIP_APPEND) == GFX_TEXT_PROPERTY_CLIP_APPEND)
    {
      fl_text_info_S.print_str_P = fl_app_str;
      fl_text_info_S.print_length_U8 = NB_CHARACTERS_APPEND;

      if((fl_text_info_S.dyn_text_def_SP->properties & (GFX_TEXT_PROPERTY_ALIGN_RIGHT)) != 0)
      {
#if GFX_APPEND_PROPERTY_ENABLED > 0
        fl_start_x = (GFX_SIZE_X_T)((fl_text_info_S.property_SP->coord.x - fl_text_info_S.print_width) - fl_text_info_S.dyn_text_def_SP->ap_str_width);
#endif
      }
      else if((fl_text_info_S.dyn_text_def_SP->properties & (GFX_TEXT_PROPERTY_ALIGN_CENTRE)) != 0)
      {
        fl_start_x = GfxDriverTextRenderer(&fl_text_info_S,fl_start_x, FALSE);
#if GFX_APPEND_PROPERTY_ENABLED > 0
        fl_start_x = (GFX_SIZE_X_T)((fl_start_x - fl_text_info_S.print_width) - (fl_text_info_S.dyn_text_def_SP->ap_str_width * 2));
#endif
        fl_text_info_S.print_str_P = fl_app_str;
        fl_text_info_S.print_length_U8 = NB_CHARACTERS_APPEND;
      }
      else
      {

      }
      fl_start_x = GfxDriverTextRenderer(&fl_text_info_S,fl_start_x,FALSE);
    }
  }

  return fl_start_x;
}
#endif /*#if NB_DYN_TEXTS > 0*/
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
#if (NB_FILL_SCREENS > 0) || (NB_VERT_PATTERN_FILL > 0) || (NB_HORZ_PATTERN_FILL > 0)
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverFillScreenClip(CLIP_FILLSCREEN_DATA * p_clip_data_SP)
{
  GFX_SIZE_W_T  fl_x_offset;
  GFX_SIZE_H_T  fl_y_offset;

  if(p_clip_data_SP->y < l_clip_area_S[0].y)
  {
    fl_y_offset = (l_clip_area_S[0].y-p_clip_data_SP->y);
    if(fl_y_offset < p_clip_data_SP->h)
    {
      p_clip_data_SP->h -= fl_y_offset;
      if(p_clip_data_SP->h > l_clip_area_S[0].h)
      {
        p_clip_data_SP->h = l_clip_area_S[0].h;
      }
      p_clip_data_SP->y = l_clip_area_S[0].y;
    }
    else
    {
      p_clip_data_SP->h = 0;
    }
  }
  else
  {
    fl_y_offset = (p_clip_data_SP->y - l_clip_area_S[0].y);
    if(l_clip_area_S[0].h > fl_y_offset)
    {
      fl_y_offset = (l_clip_area_S[0].h - fl_y_offset);
      if(p_clip_data_SP->h > fl_y_offset)
      {
        p_clip_data_SP->h = fl_y_offset;
      }
    }
    else
    {
      p_clip_data_SP->h = 0;
    }
  }
  if(p_clip_data_SP->x < l_clip_area_S[0].x)
  {
    fl_x_offset = (l_clip_area_S[0].x-p_clip_data_SP->x);
    if(fl_x_offset < p_clip_data_SP->w)
    {
      p_clip_data_SP->w -= fl_x_offset;
      if(p_clip_data_SP->w > l_clip_area_S[0].w)
      {
        p_clip_data_SP->w = l_clip_area_S[0].w;
      }
      p_clip_data_SP->x = l_clip_area_S[0].x;
    }
    else
    {
      p_clip_data_SP->w = 0;
    }
  }
  else
  {
    fl_x_offset = (p_clip_data_SP->x - l_clip_area_S[0].x);
    if(l_clip_area_S[0].w > fl_x_offset)
    {
      fl_x_offset = (l_clip_area_S[0].w - fl_x_offset);
      if(p_clip_data_SP->w > fl_x_offset)
      {
        p_clip_data_SP->w = fl_x_offset;
      }
    }
    else
    {
      p_clip_data_SP->w = 0;
    }
  }
}
#endif /* #if (NB_FILL_SCREENS > 0) || (NB_VERT_PATTERN_FILL > 0) || (NB_HORZ_PATTERN_FILL > 0) */
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */

#if NB_FILL_SCREENS > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildFillScreen(COORDINATE_DEF_T const * coord, FILL_SCREEN_DEF_T const * pc_fill_screen_def_S)
{
  GFX_COLOR_T  * fl_cur_frame_buff_P;
  GFX_COLOR_T  * fl_frame_buff_P;
  GFX_SIZE_W_T   fl_cur_width;
  GFX_COLOR_T    fl_fill_color = pc_fill_screen_def_S->color;
  GFX_COLOR_T  * fl_bmp_data_P;
  GFX_SIZE_W_T   fl_width  = pc_fill_screen_def_S->width;

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_FILLSCREEN_DATA fl_clip_data_S;

    fl_clip_data_S.x = coord->x;
    fl_clip_data_S.y = coord->y;
    fl_clip_data_S.w = fl_width;
    fl_clip_data_S.h = pc_fill_screen_def_S->height;

    GfxDriverFillScreenClip(&fl_clip_data_S);

    if((fl_clip_data_S.w != 0) && (fl_clip_data_S.h != 0))
    {
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += ((fl_clip_data_S.y * l_drv_context_S.fb_w)+fl_clip_data_S.x);
      while(fl_clip_data_S.h)
      {
        fl_clip_data_S.h--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_cur_width        = fl_clip_data_S.w;
        while(fl_cur_width)
        {
          fl_cur_width--;
          *fl_cur_frame_buff_P++ = fl_fill_color;
        }
        fl_frame_buff_P += l_drv_context_S.fb_w;
      }
    }
  }
  else
#endif /*#ifdef GFX_CLIPPED_WIDGETS_ENABLED*/
  if(fl_width == l_drv_context_S.fb_w)
  {
    /*
    ** Use DMA when fill width matches the buffer X size
    */
    GFX_SIZE_H_T  fl_height = pc_fill_screen_def_S->height;
   #ifdef WIN32
    UINT32 fl_fill_count = l_drv_context_S.fb_w*fl_height;
    fl_bmp_data_P  = (void *)l_drv_context_S.fb_P;
    fl_bmp_data_P += ((l_drv_context_S.fb_w*coord->y)+coord->x);
    while(fl_fill_count)
    {
      *fl_bmp_data_P++ = fl_fill_color;
      fl_fill_count--;
    }
   #else
    DMAC.CHCR0.BIT.DE = 0;
    DMAC.SAR0.LONG    = (UINT32)&fl_fill_color;
    if(fl_height == l_drv_context_S.fb_h)
    {
      DMAC.DAR0.LONG    = (UINT32)l_drv_context_S.fb_P;
      DMAC.DMATCR0.LONG = l_drv_context_S.fb_w*l_drv_context_S.fb_h;
    }
    else
    {
      DMAC.DMATCR0.LONG = l_drv_context_S.fb_w*fl_height;
      fl_bmp_data_P     = (void *)l_drv_context_S.fb_P;
      fl_bmp_data_P    += ((l_drv_context_S.fb_w*coord->y)+coord->x);
      DMAC.DAR0.LONG    = (UINT32)fl_bmp_data_P;
    }
    DMAC.CHCR0.LONG   = 0x80004408;
    DMAC.CHCR0.BIT.DE = 1;
    while(DMAC.CHCR0.BIT.TE == 0);
   #endif 
  }
  else
  {
    GFX_SIZE_W_T   fl_width  = pc_fill_screen_def_S->width;
    GFX_SIZE_H_T   fl_height = pc_fill_screen_def_S->height;
    /*
    ** Use Software Copy when fill width doesnot matches the buffer X size
    */
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);
    while(fl_height)
    {
      fl_height--;
      fl_cur_frame_buff_P = fl_frame_buff_P;
      fl_cur_width        = fl_width;
      while(fl_cur_width)
      {
        fl_cur_width--;
        *fl_cur_frame_buff_P++ = fl_fill_color;
      }
      fl_frame_buff_P += l_drv_context_S.fb_w;
    }
  }
}
#endif /*#if NB_FILL_SCREENS > 0*/

#if NB_VERT_PATTERN_FILL > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildVerticalPatternFill(COORDINATE_DEF_T const * coord, HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S)
{
  GFX_COLOR_T         fl_fill_color;
  GFX_SIZE_H_T        fl_cur_height;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_color_ptr;

#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_fill_screen_def_S->bmp_data);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_FILLSCREEN_DATA fl_clip_data_S;

    fl_clip_data_S.x = coord->x;
    fl_clip_data_S.y = coord->y;
    fl_clip_data_S.w = pc_fill_screen_def_S->width;
    fl_clip_data_S.h = pc_fill_screen_def_S->height;

    GfxDriverFillScreenClip(&fl_clip_data_S);

    if((fl_clip_data_S.w != 0) && (fl_clip_data_S.h != 0))
    {
      fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
      fl_color_ptr    += (coord->x-fl_clip_data_S.x);
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += ((fl_clip_data_S.y * l_drv_context_S.fb_w)+fl_clip_data_S.x);
      while(fl_clip_data_S.w)
      {
        fl_clip_data_S.w--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_fill_color       = *fl_color_ptr;
        fl_cur_height       = fl_clip_data_S.h;
        while(fl_cur_height)
        {
          fl_cur_height--;
          *fl_cur_frame_buff_P = fl_fill_color;
          fl_cur_frame_buff_P += l_drv_context_S.fb_w;
        }
        fl_color_ptr++;
        fl_frame_buff_P++;
      }
    }
  }
  else
#endif /*#ifdef GFX_CLIPPED_WIDGETS_ENABLED*/
    {
    GFX_SIZE_W_T        fl_width      = pc_fill_screen_def_S->width;
    GFX_SIZE_H_T        fl_height     = pc_fill_screen_def_S->height;

    fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);
    while(fl_width)
    {
      fl_width--;
      fl_cur_frame_buff_P = fl_frame_buff_P;
      fl_fill_color       = *fl_color_ptr;
      fl_cur_height       = fl_height;
      while(fl_cur_height)
      {
        fl_cur_height--;
        *fl_cur_frame_buff_P = fl_fill_color;
        fl_cur_frame_buff_P += l_drv_context_S.fb_w;
      }
      fl_color_ptr++;
      fl_frame_buff_P++;
    }
  }
}
#endif /*#if NB_VERT_PATTERN_FILL > 0*/

#if NB_HORZ_PATTERN_FILL > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildHorizontalPatternFill(COORDINATE_DEF_T const * coord, HV_FILL_PATTERN_DEF_T * pc_fill_screen_def_S)
{
  GFX_COLOR_T         fl_fill_color;
  GFX_SIZE_W_T        fl_cur_width;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_color_ptr;

#ifdef GFX_NEED_DATA_PAGING_SUPPORT
  GfxDriverSelectDataPage(pc_fill_screen_def_S->bmp_data);
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  if( (l_clip_area_S[0].x != 0)                        ||
    (l_clip_area_S[0].y != 0)                        ||
    (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
    (l_clip_area_S[0].h != l_drv_context_S.fb_h)  )
  {
    CLIP_FILLSCREEN_DATA fl_clip_data_S;

    fl_clip_data_S.x = coord->x;
    fl_clip_data_S.y = coord->y;
    fl_clip_data_S.w = pc_fill_screen_def_S->width;
    fl_clip_data_S.h = pc_fill_screen_def_S->height;

    GfxDriverFillScreenClip(&fl_clip_data_S);

    if((fl_clip_data_S.w != 0) && (fl_clip_data_S.h != 0))
    {
      fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
      fl_color_ptr    += (coord->y-fl_clip_data_S.y);
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += ((fl_clip_data_S.y * l_drv_context_S.fb_w)+fl_clip_data_S.x);
      while(fl_clip_data_S.h)
      {
        fl_clip_data_S.h--;
        fl_cur_frame_buff_P = fl_frame_buff_P;
        fl_fill_color       = *fl_color_ptr;
        fl_cur_width        = fl_clip_data_S.w;
        while(fl_cur_width)
        {
          fl_cur_width--;
          *fl_cur_frame_buff_P++ = fl_fill_color;
        }
        fl_color_ptr++;
        fl_frame_buff_P += l_drv_context_S.fb_w;
      }
    }
  }
  else
#endif /* #ifdef GFX_CLIPPED_WIDGETS_ENABLED */
    {
    GFX_SIZE_W_T  fl_width  = pc_fill_screen_def_S->width;
    GFX_SIZE_H_T  fl_height = pc_fill_screen_def_S->height;

    fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += ((coord->y * l_drv_context_S.fb_w)+coord->x);
    while(fl_height)
    {
      fl_height--;
      fl_cur_frame_buff_P =  fl_frame_buff_P;
      fl_fill_color       = *fl_color_ptr;
      fl_cur_width        =  fl_width;
      while(fl_cur_width)
      {
        fl_cur_width--;
        *fl_cur_frame_buff_P++ =  fl_fill_color;
      }
      fl_color_ptr++;
      fl_frame_buff_P += l_drv_context_S.fb_w;
    }
  }
}
#endif /*#if NB_HORZ_PATTERN_FILL > 0*/

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
/****************************************************************************
Function Name        : GfxDriverSetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverSetClipArea(RECTANGLE_DEF_T const * p_clip_area_SP)
{
  l_clip_area_S[0].x = p_clip_area_SP->x;
  l_clip_area_S[0].y = p_clip_area_SP->y;
  l_clip_area_S[0].w = p_clip_area_SP->w;
  l_clip_area_S[0].h = p_clip_area_SP->h;
}
/****************************************************************************
Function Name        : GfxDriverGetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverGetClipArea(RECTANGLE_DEF_T * p_clip_area_SP)
{
  p_clip_area_SP->x = l_clip_area_S[0].x;
  p_clip_area_SP->y = l_clip_area_S[0].y;
  p_clip_area_SP->w = l_clip_area_S[0].w;
  p_clip_area_SP->h = l_clip_area_S[0].h;
}
/****************************************************************************
Function Name        : GfxDriverReSetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverReSetClipArea(void)
{
  l_clip_area_S[0].x = 0;
  l_clip_area_S[0].y = 0;
  l_clip_area_S[0].w = l_drv_context_S.fb_w;
  l_clip_area_S[0].h = l_drv_context_S.fb_h;
}
#endif /*#ifdef GFX_CLIPPED_WIDGETS_ENABLED*/

/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 13-Aug-2009
By                : emanoj1
Traceability      : Rev 1.0
Change Description: Seperated all rendering functions to this file to better
                    handle the driver related changes between 7262 and 7262L
                    The rendering routines will remain same for both 7262
                    and 7262L where as the framebuffer management will be 
                    different and which will be handled by the hmi_gfx_driver
-----------------------------------------------------------------------------*/

