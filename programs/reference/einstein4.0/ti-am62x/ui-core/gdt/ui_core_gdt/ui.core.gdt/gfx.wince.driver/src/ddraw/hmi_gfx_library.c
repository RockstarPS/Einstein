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

#include "system.h"
#include "hmi_gfx_driver.h"
#include "hmi_gfx_mgr_font.h"
#include "hmi_gfx_mgr_font.rom"
#include <VG/openvg.h>
#include <VG/vgu.h>

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

static const VGfloat lc_init_transform_matrix[] =
{
   1.0f,  0.0f,               0.0f,
   0.0f, -1.0f,               0.0f,
   0.0f,  GFX_MAX_H_LENGTH,   1.0f
};

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define NB_CHARACTERS_APPEND  (3)

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
  UINT32              bmp_format;
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

static RECTANGLE_DEF_T  l_clip_area_S[1];
static GFX_DRV_ENV_INFO l_drv_context_S;

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
  l_drv_context_S.hdc       = p_drv_context_SP->hdc;
}

#if NB_BITMAPS >= 0
#if GFX_COMPRESSED_IMAGES > 0
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
#ifndef USE_DDRAW
   if(pc_bitmap_def_S->format == VG_sXRGB_8888)
   {
      GFX_COLOR_T       * fl_frame_buff_P;
      GFX_COLOR_T       * fl_cur_frame_buff_P;
      GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
      UINT32              fl_x_size     = pc_bitmap_def_S->w;
      UINT32              fl_y_size     = pc_bitmap_def_S->h;
      UINT32              fl_x          = coord->x;
      UINT32              fl_y          = coord->y;
      UINT32              fl_cur_x_size;
      UINT32              fl_fb_offset;

      fl_fb_offset     = l_drv_context_S.fb_h;
      fl_fb_offset    -= (coord->y+1);
      fl_fb_offset    *= l_drv_context_S.fb_w;
      fl_fb_offset    += coord->x;
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += fl_fb_offset;

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
         fl_frame_buff_P -= l_drv_context_S.fb_w;
      }
   }
#endif
#ifdef USE_DDRAW
   if(pc_bitmap_def_S->format == VG_sRGB_565)
   {
      UINT16       * fl_frame_buff_P;
      UINT16       * fl_cur_frame_buff_P;
      UINT16 const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;
      UINT32         fl_x_size     = pc_bitmap_def_S->w;
      UINT32         fl_y_size     = pc_bitmap_def_S->h;
      UINT32         fl_x          = coord->x;
      UINT32         fl_y          = coord->y;
      UINT32         fl_cur_x_size;
      UINT32         fl_fb_offset;

      fl_fb_offset     = coord->y;
      fl_fb_offset    *= l_drv_context_S.fb_w;
      fl_fb_offset    += coord->x;
      fl_frame_buff_P  = (UINT16 *)l_drv_context_S.fb_P;
      fl_frame_buff_P += fl_fb_offset;

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
static void GfxDriverImageBlend(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
#ifdef USE_DDRAW
  UINT16            * fl_frame_buff_P;
  UINT16            * fl_cur_frame_buff_P;
#else
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
#endif
  GFX_COLOR_T const * fl_bmp_data_P = pc_bitmap_def_S->bmp_data;

  UINT32              fl_x_size     = pc_bitmap_def_S->w;
  UINT32              fl_y_size     = pc_bitmap_def_S->h;
  UINT32              fl_x          = coord->x;
  UINT32              fl_y          = coord->y;
  UINT32              fl_cur_x_size;
  UINT32              fl_fb_offset;
  UINT32              fl_first_time = 1;

  SINT32              fl_BgR;
  SINT32              fl_BgG;
  SINT32              fl_BgB;
  SINT32              fl_fgR;
  SINT32              fl_fgG;
  SINT32              fl_fgB;
  UINT32              fl_alpha_fg;
  UINT32              fl_prev_bg = -1;
  UINT32              fl_prev_fg = -1;

#ifdef USE_DDRAW
  fl_fb_offset    =  coord->y;
#else
  fl_fb_offset     = l_drv_context_S.fb_h;
  fl_fb_offset    -= (coord->y+1);
#endif
  fl_fb_offset    *= l_drv_context_S.fb_w;
  fl_fb_offset    += coord->x;
#ifdef USE_DDRAW
  fl_frame_buff_P  = (UINT16 *)l_drv_context_S.fb_P;
#else
  fl_frame_buff_P  = l_drv_context_S.fb_P;
#endif
  fl_frame_buff_P += fl_fb_offset;

  while(fl_y_size)
  {
     fl_y_size--;
     fl_cur_frame_buff_P = fl_frame_buff_P;
     fl_cur_x_size       = fl_x_size;

     while(fl_cur_x_size)
     {
        fl_cur_x_size--;

        fl_fgR = *fl_bmp_data_P++;
        fl_BgR = *fl_cur_frame_buff_P;

        if((fl_prev_fg == fl_fgR) && (fl_prev_bg == fl_BgR) && (fl_first_time == 0))
        {
           /*
           ** Previous blend color match with current one
           ** so no need to perform blend again, just write the prev result
           */
           *fl_cur_frame_buff_P = (UINT16)fl_fgB;
        }
        else
        {
           fl_alpha_fg = fl_fgR & 0xFF000000;

           if(fl_alpha_fg == 0xFF000000)
           {
           #ifdef USE_DDRAW
              fl_fgB = (fl_fgR >> 3) & 0x0000001F;
              fl_fgG = (fl_fgR >> 5) & 0x000007E0;
              fl_fgR = (fl_fgR >> 8) & 0x0000F800;
              fl_fgR |= fl_fgG;
              fl_fgR |= fl_fgB;
           #endif
              *fl_cur_frame_buff_P = (UINT16)fl_fgR;
           }
           else if(fl_alpha_fg != 0)
           {
              fl_alpha_fg >>= 24;
              fl_prev_fg    = fl_fgR;
              fl_fgR       &= 0x00FFFFFF;

           #ifdef USE_DDRAW
              fl_fgB     = (fl_fgR >> 3);
              fl_fgG     = (fl_fgB >> 7);
              fl_fgR     = (fl_fgG >> 9);
              fl_fgB    &= 0x1F;
              fl_fgG    &= 0x3F;
           #else
              fl_fgB     = fl_fgR;
              fl_fgG     = (fl_fgB >> 8);
              fl_fgR     = (fl_fgG >> 8);
              fl_fgB    &= 0xFF;
              fl_fgG    &= 0xFF;
           #endif

              fl_prev_bg = fl_BgR;
           #ifdef USE_DDRAW
              fl_BgB   = fl_BgR;
              fl_BgG   = (fl_BgB >> 5);
              fl_BgR   = (fl_BgG >> 6);
              fl_BgB  &= 0x1F;
              fl_BgG  &= 0x3F;
           #else
              fl_BgB   = fl_prev_bg & 0x00FFFFFF;
              fl_BgG   = (fl_BgB >> 8);
              fl_BgR   = (fl_BgG >> 8);
              fl_BgB  &= 0xFF;
              fl_BgG  &= 0xFF;
           #endif

              /* Blend */
              if(fl_fgR >= fl_BgR)
              {
                 fl_fgR = ((fl_BgR + ((fl_alpha_fg * (fl_fgR - fl_BgR)) >> 8)));
              }
              else
              {
                 fl_fgR = ((fl_BgR - ((fl_alpha_fg * (fl_BgR - fl_fgR)) >> 8)));
              }
              if(fl_fgG >= fl_BgG)
              {
                 fl_fgG = ((fl_BgG + ((fl_alpha_fg * (fl_fgG - fl_BgG)) >> 8)));
              }
              else
              {
                 fl_fgG = ((fl_BgG - ((fl_alpha_fg * (fl_BgG - fl_fgG)) >> 8)));
              }
              if(fl_fgB >= fl_BgB)
              {
                 fl_fgB = ((fl_BgB + ((fl_alpha_fg * (fl_fgB - fl_BgB)) >> 8)));
              }
              else
              {
                 fl_fgB = ((fl_BgB - ((fl_alpha_fg * (fl_BgB - fl_fgB)) >> 8)));
              }

           #ifdef USE_DDRAW
             #ifdef DEBUG
              if(fl_fgR > 0x1F || fl_fgG > 0x3F || fl_fgB > 0x1F)
              {
                 printf("a=%d,b=%d,f=%d\n",fl_alpha_fg,fl_prev_bg, fl_alpha_fg);
              }
             #endif
              fl_fgB  += ((fl_fgG << 5) + (fl_fgR << 11));
           #else
              fl_fgB  += ((fl_fgG << 8) + (fl_fgR << 16));
           #endif

              /* Writeback */
              *fl_cur_frame_buff_P = (UINT16)fl_fgB;
              fl_first_time = 0;
           }
           else
           {
           }
           *fl_cur_frame_buff_P++;
        }
     }
  #ifdef USE_DDRAW
     fl_frame_buff_P += l_drv_context_S.fb_w;
  #else
     fl_frame_buff_P -= l_drv_context_S.fb_w;
  #endif
  }
}

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
   SINT32 fl_h_offset;
   SINT32 fl_y_size;
   SINT32 fl_x_size;

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
        if(p_clip_image_data_SP->bmp_format == VG_sRGB_565)
        {
           ((UINT16 *)p_clip_image_data_SP->bmp_data_P) += (fl_h_offset*p_clip_image_data_SP->w);
        }
        else
        {
           p_clip_image_data_SP->bmp_data_P += (fl_h_offset*p_clip_image_data_SP->w);
        }
        if(l_drv_context_S.fb_format == GFX_ARGB4444)
        {
          p_clip_image_data_SP->alpha_data_P += (fl_h_offset*((p_clip_image_data_SP->w+1)>>1));
        }
        else
        {
          p_clip_image_data_SP->alpha_data_P += (fl_h_offset*p_clip_image_data_SP->w);
        }
     #ifdef USE_DDRAW
        ((UINT16 *)p_clip_image_data_SP->frame_buff_P) += (fl_h_offset*l_drv_context_S.fb_w);
     #else
        p_clip_image_data_SP->frame_buff_P += (fl_h_offset*l_drv_context_S.fb_w);
     #endif
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
      #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
         else
         {
            p_clip_image_data_SP->w = 0;
         }
      #endif /* GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED */
      }
      else
      {
         p_clip_image_data_SP->w_offset = (l_clip_area_S[0].x - p_clip_image_data_SP->x);
         if(p_clip_image_data_SP->w_offset < p_clip_image_data_SP->w)
         {
            fl_x_size = (p_clip_image_data_SP->w - p_clip_image_data_SP->w_offset);
            if(fl_x_size > l_clip_area_S[0].w)
            {
               fl_x_size = l_clip_area_S[0].w;
            }
            if(p_clip_image_data_SP->bmp_format == VG_sRGB_565)
            {
               ((UINT16 *)p_clip_image_data_SP->bmp_data_P) += p_clip_image_data_SP->w_offset;
            }
            else
            {
               p_clip_image_data_SP->bmp_data_P += p_clip_image_data_SP->w_offset;
            }
            p_clip_image_data_SP->alpha_data_P += p_clip_image_data_SP->w_offset;
         #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
          #ifdef USE_DDRAW
            ((UINT16 *)p_clip_image_data_SP->frame_buff_P) += p_clip_image_data_SP->w_offset;
          #else
            p_clip_image_data_SP->frame_buff_P += p_clip_image_data_SP->w_offset;
          #endif
         #endif /* GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED */
            p_clip_image_data_SP->w_offset      = (p_clip_image_data_SP->w-fl_x_size);
            p_clip_image_data_SP->w             = fl_x_size;
         }
      #if (GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED)
         else
         {
            p_clip_image_data_SP->w = 0;
         }
      #endif /* GFX_MANAGER_LOW_PRIORITY_SCREEN_UPDATE == GFX_PAINT_CHANGED */
      }
   }
}

/****************************************************************************
Function Name        : GfxDriverClipImageCopy
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverClipImageCopy(CLIP_IMAGE_DATA * p_clip_image_data_S)
{
#ifndef USE_DDRAW
   if(p_clip_image_data_S->bmp_format == VG_sXRGB_8888)
   {
       UINT32        fl_cur_x_size;
       GFX_COLOR_T * fl_cur_frame_buff_P;

       while(p_clip_image_data_S->h)
       {
          p_clip_image_data_S->h--;
          fl_cur_frame_buff_P = p_clip_image_data_S->frame_buff_P;
          fl_cur_x_size       = p_clip_image_data_S->w;
          while(fl_cur_x_size)
          {
             fl_cur_x_size--;
             *fl_cur_frame_buff_P++ = *p_clip_image_data_S->bmp_data_P++;
          }
          p_clip_image_data_S->frame_buff_P -= l_drv_context_S.fb_w;
          p_clip_image_data_S->bmp_data_P   += p_clip_image_data_S->w_offset;
       }
   }
 #ifdef DEBUG
   else
   {
      printf("Unsupported Image Format.");
   }
 #endif
#endif
#ifdef USE_DDRAW
   if(p_clip_image_data_S->bmp_format == VG_sRGB_565)
   {
      UINT32   fl_cur_x_size;
      UINT16 * fl_frame_buff_P = (UINT16 *)p_clip_image_data_S->frame_buff_P;
      UINT16 * fl_cur_frame_buff_P;

      while(p_clip_image_data_S->h)
      {
         p_clip_image_data_S->h--;
         fl_cur_frame_buff_P = fl_frame_buff_P;
         fl_cur_x_size       = p_clip_image_data_S->w;
         while(fl_cur_x_size)
         {
            fl_cur_x_size--;
            *fl_cur_frame_buff_P++ = *((UINT16 *)p_clip_image_data_S->bmp_data_P)++;
         }
         fl_frame_buff_P                             += l_drv_context_S.fb_w;
         ((UINT16 *)p_clip_image_data_S->bmp_data_P) += p_clip_image_data_S->w_offset;
      }
   }
 #ifdef DEBUG
   else
   {
      printf("Unsupported Image Format.");
   }
 #endif
#endif
}

/****************************************************************************
Function Name        : GfxDriverClipImageCopy
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverClipImageBlend(CLIP_IMAGE_DATA * p_clip_image_data_S)
{
#ifdef USE_DDRAW
    UINT16      * fl_frame_buff_P = (UINT16 *)p_clip_image_data_S->frame_buff_P;
    UINT16      * fl_cur_frame_buff_P;
#else
    GFX_COLOR_T * fl_frame_buff_P = p_clip_image_data_S->frame_buff_P;
    GFX_COLOR_T * fl_cur_frame_buff_P;
#endif

    UINT32        fl_cur_x_size;
    SINT32        fl_BgR;
    SINT32        fl_BgG;
    SINT32        fl_BgB;
    SINT32        fl_fgR;
    SINT32        fl_fgG;
    SINT32        fl_fgB;
    UINT32        fl_alpha_fg;
    UINT32        fl_prev_bg = -1;
    UINT32        fl_prev_fg = -1;
    UINT32        fl_first_time = 1;

    while(p_clip_image_data_S->h)
    {
       p_clip_image_data_S->h--;
       fl_cur_frame_buff_P = fl_frame_buff_P;
       fl_cur_x_size       = p_clip_image_data_S->w;
       while(fl_cur_x_size)
       {
          fl_cur_x_size--;

          fl_fgR = *p_clip_image_data_S->bmp_data_P++;
          fl_BgR = *fl_cur_frame_buff_P;

          if((fl_prev_fg == fl_fgR) && (fl_prev_bg == fl_BgR) && (fl_first_time == 0))
          {
             /*
             ** Previous blend color match with current one
             ** so no need to perform blend again, just write the prev result
             */
             *fl_cur_frame_buff_P = (UINT16)fl_fgB;
          }
          else
          {
             fl_alpha_fg = fl_fgR & 0xFF000000;

             if(fl_alpha_fg == 0xFF000000)
             {
             #ifdef USE_DDRAW
                fl_fgB = (fl_fgR >> 3) & 0x0000001F;
                fl_fgG = (fl_fgR >> 5) & 0x000007E0;
                fl_fgR = (fl_fgR >> 8) & 0x0000F800;
                fl_fgR |= fl_fgG;
                fl_fgR |= fl_fgB;
             #endif
                *fl_cur_frame_buff_P = (UINT16)fl_fgR;
             }
             else if(fl_alpha_fg != 0)
             {
                fl_alpha_fg >>= 24;
                fl_prev_fg = fl_fgR;
                fl_fgR    &= 0x00FFFFFF;

             #ifdef USE_DDRAW
                fl_fgB     = (fl_fgR >> 3);
                fl_fgG     = (fl_fgB >> 7);
                fl_fgR     = (fl_fgG >> 9);
                fl_fgB    &= 0x1F;
                fl_fgG    &= 0x3F;
             #else
                fl_fgB     = fl_fgR;
                fl_fgG     = (fl_fgB >> 8);
                fl_fgR     = (fl_fgG >> 8);
                fl_fgB    &= 0xFF;
                fl_fgG    &= 0xFF;
             #endif

                fl_prev_bg = fl_BgR;
             #ifdef USE_DDRAW
                fl_BgB   = fl_BgR;
                fl_BgG   = (fl_BgB >> 5);
                fl_BgR   = (fl_BgG >> 6);
                fl_BgB  &= 0x1F;
                fl_BgG  &= 0x3F;
             #else
                fl_BgB   = fl_prev_bg & 0x00FFFFFF;
                fl_BgG   = (fl_BgB >> 8);
                fl_BgR   = (fl_BgG >> 8);
                fl_BgB  &= 0xFF;
                fl_BgG  &= 0xFF;
             #endif

                /* Blend */
                if(fl_fgR >= fl_BgR)
                {
                   fl_fgR = ((fl_BgR + ((fl_alpha_fg * (fl_fgR - fl_BgR)) >> 8)));
                }
                else
                {
                   fl_fgR = ((fl_BgR - ((fl_alpha_fg * (fl_BgR - fl_fgR)) >> 8)));
                }
                if(fl_fgG >= fl_BgG)
                {
                   fl_fgG = ((fl_BgG + ((fl_alpha_fg * (fl_fgG - fl_BgG)) >> 8)));
                }
                else
                {
                   fl_fgG = ((fl_BgG - ((fl_alpha_fg * (fl_BgG - fl_fgG)) >> 8)));
                }
                if(fl_fgB >= fl_BgB)
                {
                   fl_fgB = ((fl_BgB + ((fl_alpha_fg * (fl_fgB - fl_BgB)) >> 8)));
                }
                else
                {
                   fl_fgB = ((fl_BgB - ((fl_alpha_fg * (fl_BgB - fl_fgB)) >> 8)));
                }
             #ifdef USE_DDRAW
               #ifdef DEBUG
                if(fl_fgR > 0x1F || fl_fgG > 0x3F || fl_fgB > 0x1F)
                {
                   printf("a=%d,b=%d,f=%d\n",fl_alpha_fg,fl_prev_bg, fl_alpha_fg);
                }
               #endif
                fl_fgB  += ((fl_fgG << 5) + (fl_fgR << 11));
             #else
                fl_fgB  += ((fl_fgG << 8) + (fl_fgR << 16));
             #endif
                /* Writeback */
                *fl_cur_frame_buff_P = (UINT16)fl_fgB;
                fl_first_time = 0;
             }
             else
             {
             }
             *fl_cur_frame_buff_P++;
          }
       }
    #ifdef USE_DDRAW
       fl_frame_buff_P += l_drv_context_S.fb_w;
    #else
       fl_frame_buff_P -= l_drv_context_S.fb_w;
    #endif
       p_clip_image_data_S->bmp_data_P += p_clip_image_data_S->w_offset;
    }
}

/****************************************************************************
Function Name        : GfxDriverBuildBitmapImage
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverBuildBitmapImage(COORDINATE_DEF_T const * coord, BITMAP_DEF_T const * pc_bitmap_def_S)
{
  if( (l_clip_area_S[0].x != 0)                     ||
      (l_clip_area_S[0].y != 0)                     ||
      (l_clip_area_S[0].w != l_drv_context_S.fb_w)  ||
      (l_clip_area_S[0].h != l_drv_context_S.fb_h)  ||
      (pc_bitmap_def_S->w >  l_drv_context_S.fb_w)  ||
      (pc_bitmap_def_S->h >  l_drv_context_S.fb_h)   )
  {
     UINT32           fl_fb_offset;
     CLIP_IMAGE_DATA  fl_clip_image_data_S;
#ifdef USE_DDRAW
     UINT16         * fl_frame_buff_P;
#else
     GFX_COLOR_T    * fl_frame_buff_P;
#endif

     fl_clip_image_data_S.bmp_data_P    = pc_bitmap_def_S->bmp_data;
     fl_clip_image_data_S.x             = coord->x;
     fl_clip_image_data_S.y             = coord->y;
     fl_clip_image_data_S.w             = pc_bitmap_def_S->w;
     fl_clip_image_data_S.h             = pc_bitmap_def_S->h;
     fl_clip_image_data_S.bmp_format    = pc_bitmap_def_S->format;

#ifdef USE_DDRAW
     fl_fb_offset  = fl_clip_image_data_S.y;
#else
     fl_fb_offset  = l_drv_context_S.fb_h;
     fl_fb_offset -= (fl_clip_image_data_S.y+1);
#endif
     fl_fb_offset    *= l_drv_context_S.fb_w;
     fl_fb_offset    += fl_clip_image_data_S.x;
#ifdef USE_DDRAW
     fl_frame_buff_P  = (UINT16 *)l_drv_context_S.fb_P;
#else
     fl_frame_buff_P  = l_drv_context_S.fb_P;
#endif
     fl_frame_buff_P += fl_fb_offset;

     fl_clip_image_data_S.frame_buff_P = (GFX_COLOR_T *)fl_frame_buff_P;

     GfxDriverImageClip(&fl_clip_image_data_S);

     switch(pc_bitmap_def_S->format)
     {
        case VG_sXRGB_8888:
        case VG_sRGB_565:
        {
           GfxDriverClipImageCopy(&fl_clip_image_data_S);
        }
        break;
        case VG_sARGB_8888:
        {
           GfxDriverClipImageBlend(&fl_clip_image_data_S);
        }
        break;
        default:
        {
           /* Unsupported image format */
        }
        break;
     }
  }
  else
  {
   #if GFX_COMPRESSED_IMAGES > 0
    if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSLESS)
    {
       /*GfxDriverLossLessCompImageCopy(coord, pc_bitmap_def_S);*/
    }
    else if(pc_bitmap_def_S->info == GFX_IMAGE_COMPRESSION_LOSSY)
    {
       /*GfxDriverLossyCompImageCopy(coord, pc_bitmap_def_S);*/
    }
    else
   #endif
    {
       switch(pc_bitmap_def_S->format)
       {
          case VG_sXRGB_8888:
          case VG_sRGB_565:
          {
             GfxDriverImageCopy(coord, pc_bitmap_def_S);
          }
          break;
          case VG_sARGB_8888:
          {
             GfxDriverImageBlend(coord, pc_bitmap_def_S);
          }
          break;
          default:
          {
          #ifdef DEBUG
             /* Unsupported image format */
             printf("Unsupported image format\n");
          #endif
          }
          break;
       }
    }
  }
}
#endif /*#if NB_BITMAPS > 0*/

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
   SINT32 fgR;
   SINT32 fgG;
   SINT32 fgB;
   SINT32 bgR;
   SINT32 bgG;
   SINT32 bgB;
   UINT32 fl_BgColor;

#ifdef GFX_2BPP_FONTS
   #define GFX_FB_DIV 3
#else
   #define GFX_FB_DIV 15
#endif

 #ifdef USE_DDRAW
   fgB     = (color>> 3);
   fgG     = (fgB  >> 7);
   fgR     = (fgG  >> 9);
   fgG    &= 0x003F;
   fgB    &= 0x001F;
 #else
   fgB = (color &  0xFF);
   fgG = (color >> 8);
   fgR = (fgG   >> 8);
   fgG = (fgG & 0xFF);
 #endif

 #ifdef USE_DDRAW
   fl_BgColor = *((UINT16 *)p_dest_buff_ptr);
   bgB = (GFX_COLOR_T)(fl_BgColor &  0x1F);
   bgG = (GFX_COLOR_T)(fl_BgColor >> 5);
   bgR = (bgG >> 6);
   bgG = (bgG & 0x3F);
 #else
   fl_BgColor = *p_dest_buff_ptr;
   bgB = (UINT8)(fl_BgColor);
   bgG = (fl_BgColor >> 8);
   bgR = (bgG >> 8);
   bgG = (bgG & 0xFF);
 #endif

#ifndef GFX_2BPP_FONTS
   fgR = ((bgR + ((aa * (fgR - bgR)) / GFX_FB_DIV)));
   fgG = ((bgG + ((aa * (fgG - bgG)) / GFX_FB_DIV)));
   fgB = ((bgB + ((aa * (fgB - bgB)) / GFX_FB_DIV)));
#else
   if(aa == 0x02)
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
#endif

#ifdef USE_DDRAW
 #ifdef DEBUG
   if(fgR > 0x1F || fgG > 0x3F || fgB > 0x1F)
   {
      printf("a=%d,b=%d,f=%d\n",aa,*((UINT16 *)p_dest_buff_ptr), color);
   }
 #endif
   *((UINT16 *)p_dest_buff_ptr) = (UINT16)(fgB + (fgG << 5) + (fgR << (6 + 5)));
#else
   *p_dest_buff_ptr = fgB + (fgG << 8) + (fgR << 16);
#endif
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
Parameters           : p_clip_text_info_SP->disp_string_P - Pointer to String
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
      if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_CENTRE) == GFX_TEXT_PROPERTY_ALIGN_CENTRE)
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
      if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_RIGHT) == GFX_TEXT_PROPERTY_ALIGN_RIGHT)
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
      else if((p_clip_text_info_SP->dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_ALIGN_CENTRE) == GFX_TEXT_PROPERTY_ALIGN_CENTRE)
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
Function Name        : GfxDriverTextRenderer
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
 #ifdef USE_DDRAW
   UINT16                     * fl_cur_frame_buff_P;
   UINT16                     * fl_frame_buff_P;
 #else
   GFX_COLOR_T                * fl_cur_frame_buff_P;
   GFX_COLOR_T                * fl_frame_buff_P;
 #endif
   UINT8 const                * fl_font_data_P;
   UINT8                        fl_font_data;
   GFX_SIZE_Y_T                 fl_cur_y;
   GFX_SIZE_W_T                 fl_x_size;
   GFX_SIZE_W_T                 fl_font_width;
   GFX_SIZE_H_T                 fl_font_height;
   GFX_SIZE_W_T                 fl_cur_width;
   UINT8                        fl_pix_in_byte_count;
   UINT8                        fl_aa_data;
   GFX_SIZE_Y_T                 fl_clip_end_y = (l_clip_area_S[0].h + l_clip_area_S[0].y);

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
      fl_start_x = start_x;
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
         #ifdef USE_DDRAW
            fl_frame_buff_P = (UINT16 *)l_drv_context_S.fb_P;
            fl_frame_buff_P+= ((fl_cur_y * l_drv_context_S.fb_w)+fl_start_x);
         #else
            fl_frame_buff_P = l_drv_context_S.fb_P;
            fl_frame_buff_P+= (((l_drv_context_S.fb_h-(fl_cur_y+1)) * l_drv_context_S.fb_w)+fl_start_x);
         #endif

            while(fl_font_height)
            {
               fl_font_height--;
               if((fl_cur_y < l_clip_area_S[0].y) || (fl_cur_y >= fl_clip_end_y))
               {
			   #ifdef GFX_2BPP_FONTS
                  fl_font_data_P += ((fl_font_width+3)>>2);
			   #else
                  fl_font_data_P += ((fl_font_width+1)>>1);
			   #endif
               }
               else
               {
                  fl_cur_width        = fl_font_width;
                  fl_cur_frame_buff_P = fl_frame_buff_P;

                  while(fl_cur_width)
                  {
                     fl_font_data = *fl_font_data_P++;
                     if(fl_font_data != 0)
                     {
                     #ifdef GFX_2BPP_FONTS
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
					 #else
                        if(fl_cur_width > 2)
                        {
                           fl_pix_in_byte_count = 2;
                           fl_cur_width        -= 2;
                        }
                        else
                        {
                           fl_pix_in_byte_count = (UINT8)fl_cur_width;
                           fl_cur_width         = 0;
                        }
					 #endif

                        while(fl_pix_in_byte_count)
                        {
                           fl_pix_in_byte_count--;
						#ifdef GFX_2BPP_FONTS
                           fl_aa_data = (fl_font_data & 0x03);
						#else
                           fl_aa_data = (fl_font_data & 0x0F);
						#endif
                           if(fl_aa_data != 0)
                           {
                              GfxDriver_2bppAA_PixelWrite((GFX_COLOR_T *)fl_cur_frame_buff_P, fl_aa_data, fl_draw_color);
                           }
						#ifdef GFX_2BPP_FONTS
                           fl_font_data >>= 2;
						#else
                           fl_font_data >>= 4;
						#endif
                           fl_cur_frame_buff_P++;
                        }
                     }
				  #ifdef GFX_2BPP_FONTS
                     else if(fl_cur_width > 4)
                     {
                       fl_cur_width        -= 4;
                       fl_cur_frame_buff_P += 4;
                     }
				  #else
                     else if(fl_cur_width > 2)
                     {
                       fl_cur_width        -= 2;
                       fl_cur_frame_buff_P += 2;
                     }
				  #endif
                     else
                     {
                       break;
                     }
                  }
               }
               fl_cur_y++;
            #ifdef USE_DDRAW
               fl_frame_buff_P += l_drv_context_S.fb_w;
            #else
               fl_frame_buff_P -= l_drv_context_S.fb_w;
            #endif
            }
         }
         fl_start_x += fl_font_base_P->x_eoffset;
      }
      fl_disp_string_P++;
   }
   return(fl_start_x);
}

/****************************************************************************
Function Name        : GfxDriverBuildText
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

#if (NB_FILL_SCREENS > 0) || (NB_VERT_PATTERN_FILL > 0) || (NB_HORZ_PATTERN_FILL > 0)
/****************************************************************************
Function Name        : GfxDriverFillScreenClip
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

#if NB_FILL_SCREENS > 0
/****************************************************************************
Function Name        : GfxDriverBuildFillScreen
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverBuildFillScreen(COORDINATE_DEF_T const * coord, FILL_SCREEN_DEF_T const * pc_fill_screen_def_S)
{
#ifdef USE_DDRAW
  UINT16       * fl_cur_frame_buff_P;
  UINT16       * fl_frame_buff_P;
#else
  GFX_COLOR_T  * fl_cur_frame_buff_P;
  GFX_COLOR_T  * fl_frame_buff_P;
#endif
  UINT32         fl_cur_width;
  GFX_COLOR_T    fl_fill_color = pc_fill_screen_def_S->color;
  UINT32         fl_width      = pc_fill_screen_def_S->width;
  UINT32         fl_fb_offset;

#ifdef USE_DDRAW
  UINT32 fl_fgB  = (fl_fill_color >> 3);
  UINT32 fl_fgG  = (fl_fgB >> 2);
  UINT32 fl_fgR  = (fl_fgG >> 3);
  fl_fgB &= 0x001F;
  fl_fgG &= 0x07E0;
  fl_fgR &= 0xF800;
  fl_fill_color  =  (fl_fgR|fl_fgG|fl_fgB);
#endif

  if( (l_clip_area_S[0].x != 0)                     ||
      (l_clip_area_S[0].y != 0)                     ||
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
    #ifdef USE_DDRAW
       fl_fb_offset     = fl_clip_data_S.y;
    #else
       fl_fb_offset     = l_drv_context_S.fb_h;
       fl_fb_offset    -= (fl_clip_data_S.y+1);
    #endif
       fl_fb_offset    *= l_drv_context_S.fb_w;
       fl_fb_offset    += fl_clip_data_S.x;
    #ifdef USE_DDRAW
       fl_frame_buff_P  = (UINT16 *)l_drv_context_S.fb_P;
    #else
       fl_frame_buff_P  = l_drv_context_S.fb_P;
    #endif
       fl_frame_buff_P += fl_fb_offset;

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
       #ifdef USE_DDRAW
          fl_frame_buff_P -= l_drv_context_S.fb_w;
       #else
          fl_frame_buff_P += l_drv_context_S.fb_w;
       #endif
       }
    }
  }
  else
  {
     UINT32 fl_width  = pc_fill_screen_def_S->width;
     UINT32 fl_height = pc_fill_screen_def_S->height;
     /*
     ** Use Software Copy when fill width doesnot matches the buffer X size
     */
   #ifdef USE_DDRAW
     fl_fb_offset     = coord->y;
   #else
     fl_fb_offset     = l_drv_context_S.fb_h;
     fl_fb_offset    -= (coord->y+1);
   #endif
     fl_fb_offset    *= l_drv_context_S.fb_w;
     fl_fb_offset    += coord->x;
   #ifdef USE_DDRAW
     fl_frame_buff_P  = (UINT16 *)l_drv_context_S.fb_P;
   #else
     fl_frame_buff_P  = l_drv_context_S.fb_P;
   #endif
     fl_frame_buff_P += fl_fb_offset;

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
     #ifdef USE_DDRAW
        fl_frame_buff_P += l_drv_context_S.fb_w;
     #else
        fl_frame_buff_P -= l_drv_context_S.fb_w;
     #endif
     }
  }
}
#endif /*#if NB_FILL_SCREENS > 0*/

#if NB_VERT_PATTERN_FILL > 0
/****************************************************************************
Function Name        : GfxDriverBuildVerticalPatternFill
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
  UINT32              fl_cur_height;
  UINT32              fl_fb_offset;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_color_ptr;

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

      fl_fb_offset     = l_drv_context_S.fb_h;
      fl_fb_offset    -= (fl_clip_data_S.y+1);
      fl_fb_offset    *= l_drv_context_S.fb_w;
      fl_fb_offset    += fl_clip_data_S.x;
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += fl_fb_offset;

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
          fl_cur_frame_buff_P -= l_drv_context_S.fb_w;
        }
        fl_color_ptr++;
        fl_frame_buff_P++;
      }
    }
  }
  else
    {
    GFX_SIZE_W_T        fl_width      = pc_fill_screen_def_S->width;
    GFX_SIZE_H_T        fl_height     = pc_fill_screen_def_S->height;

    fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
    fl_fb_offset     = l_drv_context_S.fb_h;
    fl_fb_offset    -= (coord->y+1);
    fl_fb_offset    *= l_drv_context_S.fb_w;
    fl_fb_offset    += coord->x;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += fl_fb_offset;
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
        fl_cur_frame_buff_P -= l_drv_context_S.fb_w;
      }
      fl_color_ptr++;
      fl_frame_buff_P++;
    }
  }
}
#endif /*#if NB_VERT_PATTERN_FILL > 0*/

#if NB_HORZ_PATTERN_FILL > 0
/****************************************************************************
Function Name        : GfxDriverBuildHorizontalPatternFill
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
  UINT32              fl_cur_width;
  UINT32              fl_fb_offset;
  GFX_COLOR_T       * fl_cur_frame_buff_P;
  GFX_COLOR_T       * fl_frame_buff_P;
  GFX_COLOR_T const * fl_color_ptr;

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
      fl_fb_offset     = l_drv_context_S.fb_h;
      fl_fb_offset    -= (fl_clip_data_S.y+1);
      fl_fb_offset    *= l_drv_context_S.fb_w;
      fl_fb_offset    += fl_clip_data_S.x;
      fl_frame_buff_P  = l_drv_context_S.fb_P;
      fl_frame_buff_P += fl_fb_offset;

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
        fl_frame_buff_P -= l_drv_context_S.fb_w;
      }
    }
  }
  else
    {
    GFX_SIZE_W_T  fl_width  = pc_fill_screen_def_S->width;
    GFX_SIZE_H_T  fl_height = pc_fill_screen_def_S->height;

    fl_color_ptr     = pc_fill_screen_def_S->bmp_data;
    fl_fb_offset     = l_drv_context_S.fb_h;
    fl_fb_offset    -= (coord->y+1);
    fl_fb_offset    *= l_drv_context_S.fb_w;
    fl_fb_offset    += coord->x;
    fl_frame_buff_P  = l_drv_context_S.fb_P;
    fl_frame_buff_P += fl_fb_offset;
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
      fl_frame_buff_P -= l_drv_context_S.fb_w;
    }
  }
}
#endif /*#if NB_HORZ_PATTERN_FILL > 0*/

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
Date              : 28-Dec-2010
By                : ksriniv2
Traceability      : Rev 1.0
Change Description: Updated the code as per peer review comments

Date              : 13-Aug-2009
By                : emanoj1
Traceability      : Rev 1.0
Change Description: Seperated all rendering functions to this file to better
                    handle the driver related changes between 7262 and 7262L
                    The rendering routines will remain same for both 7262
                    and 7262L where as the framebuffer management will be
                    different and which will be handled by the hmi_gfx_driver
-----------------------------------------------------------------------------*/

