/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2008. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_dcu_sim_w32.c
**
** Description:    This file is the main entry point for the kepler HMI simulation
**                 framework. This does the necessary initialization and creates
**                 threads to run application and display window.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_DCU_SIM_W32_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <windows.h>
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_dcu_sim_w32.h"
#if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_FARADAY)
#include "dma.handler.h"
#endif
#ifdef HMI_GFX_DAO_SIMU
#include "hmi_gfx_mgr_altia.h"
#endif
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
#include "hmi_gfx_mgr_gest_drag.h"
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define GFX_DCU_MAX_LAYER_ID (GFX_MGR02_NUM_DCU_LAYERS-1)

#define SWAP_MSB_AND_LSB
#define BLINK_ACTIVE_OFF  (0)
#define BLINK_ACTIVE_ON   (1)
#define BLINK_INACTIVE    (2)

#define GSIM_WINDOW_RESIZE_MSG_ID (0x5A)
#define GSIM_WINDOW_DATA_MSG_ID   (0xA5)
typedef struct
{
   int lcd_size_width;
   int lcd_size_height;
   int zoom;
}LCD_SIZE;

LCD_SIZE lcd_size;
HWND     ghWnd=NULL;
HDC      ghDC;
HGLRC    ghRC;

typedef struct
{
   SINT16 fl_x : 12;
   SINT16 fl_y : 10;
}DCU_POS;

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
extern void AppMain(void);
void        hmi_sim_DMA_process(void);
void        hmi_sim_dcu_process(void);
static void hmi_sim_tick(void);
LONG WINAPI MainWndProc (HWND, UINT, WPARAM, LPARAM);
BOOL        bSetupPixelFormat(HDC);
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
static DRAG_ENG  drag_ctx;
#endif

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
int                   l_button_pressed  = FALSE;
UINT16                l_system_tick_U16 = 0;
static volatile UINT8 l_tick_flag_U8    = 0;
unsigned            * l_fb_p            = 0;
#ifdef HMI_GFX_DAO_SIMU
UINT32 *              l_Update_P;
#endif
int                   l_update_pending;
int                   l_cur_x;
int                   l_cur_y;
signed                l_max_x;
signed                l_max_y;

unsigned char l_cursor_blink_state_U8 = BLINK_INACTIVE;
unsigned int  l_cursor_blink_count_U8;

struct DCU_tag           dcu_reg;
struct EDMA_tag          edma_reg;
struct DMAMUX_tag        dmamux_reg;
#if !defined(GFX_MGR02_FARADAY)
struct CGM_tag           cgm_reg;
struct SIU_tag           siu_reg;
#endif
struct RLE_tag           rle_reg;

HBITMAP  hbitmap = 0;       // bitmap handle
VOID   * pvBits  = 0;       // pointer to DIB section

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:       hmi_sim_Blend_ARGB
** Description:         Blends an ARGB type pixel as per DCU blending modes
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-AUG-2010 by EMANOJ1
** Updated:             15-AUG-2010 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Blend_ARGB(unsigned p_layer, int x, int y, unsigned p_alpha, unsigned p_red, unsigned p_green, unsigned p_blue)
{
   unsigned * p_fbp;
   unsigned fl_fbr;
   unsigned fl_fbg;
   unsigned fl_fbb;
   unsigned a;

   if((x >= 0) && (y >= 0)&&(x < (int)(DCU.DISP_SIZE.B.DELTA_X * 16)) && (y < (int)(DCU.DISP_SIZE.B.DELTA_Y)))
   {
   y = (lcd_size.lcd_size_height-y);
   y--;
   p_fbp = &l_fb_p[((DCU.DISP_SIZE.B.DELTA_X * 16)*y)+x];

   fl_fbr = (unsigned char)(*p_fbp >> 16);
   fl_fbg = (unsigned char)(*p_fbp >> 8);
   fl_fbb = (unsigned char)(*p_fbp);

   /*
   ** images with alpha channel
   */
   if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 0)
   {
      /* No alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else
      {
         /* remove selected pixels */
         if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) ||  /* In PC we are operating in BGR */
            (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
            (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
            (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
            (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
            (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
         {
            *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
         }
      }
   }
   else if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 1)
   {
      /* alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         a = p_alpha;
      }
      else if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) || /* In PC we are operating in BGR */
              (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
              (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
              (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
              (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
              (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
      {
         a = 255;
      }
      else
      {
         a = p_alpha;
      }

      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   else if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 2)
   {
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         a  = p_alpha;
         a *= DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
         a /= 255;
      }
      else if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) || /* In PC we are operating in BGR */
              (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
              (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
              (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
              (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
              (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
      {
         a  = p_alpha;
         a *= DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
         a /= 255;
      }
      else
      {
         a = 0; /* Remove selected pixels */
      }

      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   else
   {
      /* Default setting */
      *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
   }
   }
}
#if defined(GFX_MGR02_MONOTFT)

/*============================================================================
** Function Name:       hmi_sim_Blend_1_2_4BPP
** Description:         Blends an 1_2_4BPP type pixel as per DCU blending modes
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
**==========================================================================*/
static void hmi_sim_Blend_1_2_4BPP(unsigned p_layer, int x, int y, unsigned p_data)
{
   unsigned * p_fbp;

   if((x >= 0) && (y >= 0)&&(x < (int)(DCU.DISP_SIZE.B.DELTA_X * 16)) && (y < (int)(DCU.DISP_SIZE.B.DELTA_Y)))
   {
	   p_fbp = &l_fb_p[0];


	   /*
	   ** images without alpha channel
	   */
	   if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 0)
	   {
		  /* No alpha blending */
		  if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
		  {
			 // *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
			  UINT32 index = 0;
			 y = lcd_size.lcd_size_height-(y+1);
			 index = (y*lcd_size.lcd_size_width)+x;
			 p_fbp[index] = p_data;
		  }
		  else
		  {

		  }
	   }
	   else
	   {
		  /* Default setting */
		  *p_fbp = p_data;
	   }
   }
}
#endif
/*============================================================================
** Function Name:       hmi_sim_Blend_RGB
** Description:         Blends an RGB type pixel as per DCU blending modes
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-AUG-2010 by EMANOJ1
** Updated:             15-AUG-2010 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Blend_RGB(unsigned p_layer, int x, int y, unsigned p_red, unsigned p_green, unsigned p_blue)
{
   unsigned * p_fbp;
   unsigned fl_fbr;
   unsigned fl_fbg;
   unsigned fl_fbb;
   unsigned a;

   if((x >= 0) && (y >= 0)&&(x < (int)(DCU.DISP_SIZE.B.DELTA_X * 16)) && (y < (int)(DCU.DISP_SIZE.B.DELTA_Y)))
   {
#ifndef GFX_MGR02_MONOTFT
   y = (lcd_size.lcd_size_height-y);
   y--;
   p_fbp = &l_fb_p[((DCU.DISP_SIZE.B.DELTA_X * 16)*y)+x];
#else
   p_fbp = &l_fb_p[0];
#endif
   fl_fbr = (unsigned char)(*p_fbp >> 16);
   fl_fbg = (unsigned char)(*p_fbp >> 8);
   fl_fbb = (unsigned char)(*p_fbp);

   /*
   ** images without alpha channel
   */
   if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 0)
   {
      /* No alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
#ifndef GFX_MGR02_MONOTFT

         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
#else
		  UINT32 index = 0;
		 y = lcd_size.lcd_size_height-(y+1);
		 index = (y*lcd_size.lcd_size_width)+x;
         p_fbp[index] = p_red;
#endif
      }
      else
      {
         /* remove selected pixels */
         if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) || /* In PC we are operating in BGR */
            (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
            (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
            (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
            (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
            (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
         {
            *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
         }
      }
   }
   else if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 1)
   {
      /* alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }
      else if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) || /* In PC we are operating in BGR */
              (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
              (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
              (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
              (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
              (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
      {
         a = 255;
      }
      else
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }

      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   else if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 2)
   {
       /* alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }
      else if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) || /* In PC we are operating in BGR */
         (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
         (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
         (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
         (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
         (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }
      else
      {
         a = 0; /* Remove selected pixels */
      }

      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   else
   {
      /* Default setting */
      *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
   }
   }
}

/*============================================================================
** Function Name:       hmi_sim_Blend_ALPHA
** Description:         Blends a transparency type pixel as per DCU blending modes
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-AUG-2010 by EMANOJ1
** Updated:             15-AUG-2010 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Blend_ALPHA(unsigned p_layer, int x, int y, unsigned p_alpha)
{
   unsigned * p_fbp;
   unsigned fl_fbr;
   unsigned fl_fbg;
   unsigned fl_fbb;
   unsigned a;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned p_red;
   unsigned p_green;
   unsigned p_blue;

   if((x >= 0) && (y >= 0)&&(x < (int)(DCU.DISP_SIZE.B.DELTA_X * 16)) && (y < (int)(DCU.DISP_SIZE.B.DELTA_Y)))
   {
   y = (lcd_size.lcd_size_height-y);
   y--;
   p_fbp = &l_fb_p[((DCU.DISP_SIZE.B.DELTA_X * 16)*y)+x];

   fl_fbr = (unsigned char)(*p_fbp >> 16);
   fl_fbg = (unsigned char)(*p_fbp >> 8);
   fl_fbb = (unsigned char)(*p_fbp);

   if(DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 0)
   {
      /* No alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
      #if 0 //defined(GFX_MGR02_FARADAY)
         p_red   = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 16);
         p_green = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 8);
         p_blue  = (unsigned char)(DCU.LAYER[p_layer].FG.F.R);
         fl_fbr  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R >> 16);
         fl_fbg  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R >> 8);
         fl_fbb  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R);
      #else
         p_red   = (unsigned char)(DCU.FG[p_layer].F.R >> 16);
         p_green = (unsigned char)(DCU.FG[p_layer].F.R >> 8);
         p_blue  = (unsigned char)(DCU.FG[p_layer].F.R);
         fl_fbr  = (unsigned char)(DCU.FG[p_layer].B.R >> 16);
         fl_fbg  = (unsigned char)(DCU.FG[p_layer].B.R >> 8);
         fl_fbb  = (unsigned char)(DCU.FG[p_layer].B.R);
      #endif
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (p_alpha * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (p_alpha * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (p_alpha * (p_blue  - fl_fbb))) >> 8);

         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
   }
   else if((DCU.LAYER[p_layer].CTRLDESCL4.B.AB == 2) && (DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 1))
   {
      /* Ignore BG color */
   #if 0 //def  GFX_MGR02_FARADAY
      p_red   = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 16);
      p_green = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 8);
      p_blue  = (unsigned char)(DCU.LAYER[p_layer].FG.F.R);
   #else
      p_red   = (unsigned char)(DCU.FG[p_layer].F.R >> 16);
      p_green = (unsigned char)(DCU.FG[p_layer].F.R >> 8);
      p_blue  = (unsigned char)(DCU.FG[p_layer].F.R);
   #endif   
      a       = p_alpha;
      a      *= DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      a      /= 255;
      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   else
   {
   #if 0 //def  GFX_MGR02_FARADAY
      p_red   = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 16);
      p_green = (unsigned char)(DCU.LAYER[p_layer].FG.F.R >> 8);
      p_blue  = (unsigned char)(DCU.LAYER[p_layer].FG.F.R);
      b  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R >> 16);
      g  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R >> 8);
      r  = (unsigned char)(DCU.LAYER[p_layer].FG.B.R);
   #else
      p_red   = (unsigned char)(DCU.FG[p_layer].F.R >> 16);
      p_green = (unsigned char)(DCU.FG[p_layer].F.R >> 8);
      p_blue  = (unsigned char)(DCU.FG[p_layer].F.R);
      b  = (unsigned char)(DCU.FG[p_layer].B.R >> 16);
      g  = (unsigned char)(DCU.FG[p_layer].B.R >> 8);
      r  = (unsigned char)(DCU.FG[p_layer].B.R);
   #endif   

      p_red   = (unsigned char)(((r << 8) + (p_alpha * (p_red   - r))) >> 8);
      p_green = (unsigned char)(((g << 8) + (p_alpha * (p_green - g))) >> 8);
      p_blue  = (unsigned char)(((b << 8) + (p_alpha * (p_blue  - b))) >> 8);

      /* alpha blending */
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.BB == 0)
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }
      else if((p_red   > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_R) ||
              (p_red   < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_R) ||
              (p_green > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_G) ||
              (p_green < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_G) ||
              (p_blue  > DCU.LAYER[p_layer].CTRLDESCL5.B.CKMAX_B) ||
              (p_blue  < DCU.LAYER[p_layer].CTRLDESCL6.B.CKMIN_B))
      {
         a = 255;
      }
      else
      {
         a = DCU.LAYER[p_layer].CTRLDESCL4.B.TRANS;
      }

      if(a == 255)
      {
         *p_fbp = ((p_red<<16) + (p_green<<8) + p_blue);
      }
      else if(a != 0)
      {
         fl_fbr = (unsigned char)(((fl_fbr << 8) + (a * (p_red   - fl_fbr))) >> 8);
         fl_fbg = (unsigned char)(((fl_fbg << 8) + (a * (p_green - fl_fbg))) >> 8);
         fl_fbb = (unsigned char)(((fl_fbb << 8) + (a * (p_blue  - fl_fbb))) >> 8);
         *p_fbp = ((fl_fbr<<16) + (fl_fbg<<8) + fl_fbb);
      }
      else
      {
      }
   }
   }
   else
   {
       //printf("Error\n");
   }
}
#if defined(GFX_MGR02_MONOTFT)
/*============================================================================
** Function Name:       hmi_sim_Copy_1_2_4BPP
** Description:         Processes 1_2_4BPP image.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Copy_1_2_4BPP(unsigned * p_data, unsigned p_layer)
{
#if GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP
   UINT8 lpix_cnt = 2;
 #if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
   UINT8 pix_msk = 0x0F;
 #else
   UINT8 pix_msk = 0xF0;
 #endif
   UINT8 pix_sht = 0x04;
#elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP
   UINT8 lpix_cnt = 4;
 #if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
   UINT8 pix_msk = 0x03;
 #else
   UINT8 pix_msk = 0xC0;
 #endif
   UINT8 pix_sht = 0x02;
#else
   UINT8 lpix_cnt = 8;
 #if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
   UINT8 pix_msk = 0x01;
 #else
   UINT8 pix_msk = 0x80;
 #endif
   UINT8 pix_sht = 0x01;
 #endif
   int pix_cnt;
   unsigned int pdta,pift;
  

   UINT8* framebufferdata;
   signed x = l_cur_x;
   signed y = l_cur_y;
   framebufferdata = p_data;

#if GFX_MGR02_HOR_PACKING == 0   
   for(y = 0;y < (l_max_y); y+=lpix_cnt)
   {
      for(x = 0; x < (l_max_x); x++)
      {
         UINT8 pix     = *framebufferdata++;
         for(pix_cnt=0;pix_cnt < lpix_cnt;pix_cnt++)
         {
            pdta = (pix & pix_msk);
         #if (GFX_MGR02_BIT_ORDER_LSB_FIRST==0)
            pdta >>= (8-pix_sht);
			pdta *= 0xFF;
			pdta /= (pix_msk>>(8-pix_sht));
			pdta = (0xFF000000|pdta|(pdta<<8)+(pdta<<16));
            hmi_sim_Blend_1_2_4BPP(p_layer, x, y+pix_cnt, pdta);
			pix <<= pix_sht;
         #else
			pdta *= 0xFF;
			pdta /= pix_msk;
			pdta = (0xFF000000|pdta|(pdta<<8)+(pdta<<16));
            hmi_sim_Blend_1_2_4BPP(p_layer, x, y+pix_cnt, pdta);
			pix >>= pix_sht;
         #endif
		 }
      }
   }
#else
   for(y = 0;y < (l_max_y); y++)
   {
      for(x = 0; x < (l_max_x); x+=lpix_cnt)
      {
         UINT8 pix     = *framebufferdata++;
         for(pix_cnt=0;pix_cnt < lpix_cnt;pix_cnt++)
         {
            pdta = (pix & pix_msk);
         #if (GFX_MGR02_BIT_ORDER_LSB_FIRST==0)
            pdta >>= (8-pix_sht);
			pdta *= 0xFF;
			pdta /= (pix_msk>>(8-pix_sht));
			pdta = (0xFF000000|pdta|(pdta<<8)+(pdta<<16));
            hmi_sim_Blend_1_2_4BPP(p_layer, x+pix_cnt, y, pdta);
			pix <<= pix_sht;
         #else
			pdta *= 0xFF;
			pdta /= pix_msk;
			pdta = (0xFF000000|pdta|(pdta<<8)+(pdta<<16));
            hmi_sim_Blend_1_2_4BPP(p_layer, x+pix_cnt, y, pdta);
			pix >>= pix_sht;
         #endif
         }
      }
   }
#endif
}
#endif
/*============================================================================
** Function Name:       hmi_sim_CopyIndexed
** Description:         Copies an Indexed bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_CopyIndexed(unsigned height, unsigned width, unsigned * p_data, unsigned p_layer, unsigned bpp)
{
   unsigned data;
   unsigned x_size;
   unsigned color;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   unsigned c_reload;
   unsigned c_mask;
   unsigned count;
#if defined(GFX_MGR02_MONOTFT)
   unsigned count2;
#endif
   unsigned c_shift;
   signed x = l_cur_x;
   signed y = l_cur_y;
   UINT16 * apal_data;

   if(bpp == 0x1F)
   {
      c_reload = 32;      //1bpp
      c_mask   = 1;
      c_shift  = 1;
   }
   else if(bpp == 0x0F)
   {
      c_reload = 16;      //2bpp
      c_mask   = 3;
      c_shift  = 2;
   }
   else if(bpp == 0x07)
   {
      c_reload = 8;       //4bpp
      c_mask   = 15;
      c_shift  = 4;
   }
   else if(bpp == 0x03)
   {
      c_reload = 4;       //8bpp
      c_mask   = 255;
      c_shift  = 8;
   }
   else if(bpp != 0x01) //APAL8
   {
      return;
   }

#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP) 
{
#if defined(GFX_MGR02_MONOTFT)

   	hmi_sim_Copy_1_2_4BPP(p_data,p_layer);
#endif
}
#else
   if(DCU.LAYER[p_layer].CTRLDESCL4.B.BPP==GFX_MGR02_16BPP_APAL8)
   {
      int ab = DCU.LAYER[p_layer].CTRLDESCL4.B.AB;
      //DCU.LAYER[p_layer].CTRLDESCL4.B.AB = 2;
      apal_data = (UINT16 *)p_data;
      #if defined(GFX_MGR02_MONOTFT)
	  count2 = 0;
      #endif
      while(height)
      {
         if(y >= l_max_y)
         {
            break;
         }
         height--;
         x_size = width;
         x      = l_cur_x;

         while(x_size)
         {
            x_size--;
            data = *apal_data++;
            if(x < l_max_x)
            {
               a     = (data >> 8);
               color = DCU.CLUT[DCU.LAYER[p_layer].CTRLDESCL4.B.LUOFFS+((data & 0xFF))];
               r     = (color >> 16) & 0xFF;
               g     = (color >> 8)  & 0xFF;
               b     = (color & 0xFF);
               hmi_sim_Blend_ARGB(p_layer, x, y, a, r, g, b);
               x++;
            }
         }
         y++;
      }
      DCU.LAYER[p_layer].CTRLDESCL4.B.AB = ab;
   }
   else
   {
      while(height)
      {
         if(y >= l_max_y)
         {
            break;
         }
         height--;
         x_size = width/c_reload;
         x      = l_cur_x;

         while(x_size)
         {
            x_size--;
            data = *p_data++;
            count = c_reload;
            #if defined(GFX_MGR02_MONOTFT)
			count2  =0;
            #endif
            while(count)
            {
               count--;
               if(x < l_max_x)
               {
                  color = DCU.CLUT[DCU.LAYER[p_layer].CTRLDESCL4.B.LUOFFS+(data & c_mask)];
                  r     = (color >> 16) & 0xFF;
                  g     = (color >> 8)  & 0xFF;
                  b     = (color & 0xFF);
                  a     = 255;
                  #if defined(GFX_MGR02_MONOTFT)
				      #if GFX_ROTATED_IMAGES == 0  
                      hmi_sim_Blend_RGB(p_layer, x, y+count2, r, g, b);
                      #else
				      hmi_sim_Blend_RGB(p_layer, x+count2, y, r, g, b);
                      #endif
                  #else
                  hmi_sim_Blend_RGB(p_layer, x, y, r, g, b);
                  #endif
                  //hmi_sim_Blend_ARGB(p_layer, x, y, a, r, g, b);
                  data >>= c_shift;
                  #if defined(GFX_MGR02_MONOTFT)
				  count2++;
				  if(count2 == 2)
				  {
                  x++;
				  count2  =0;
				  }
                  #endif
               }
            }
         }
         y++;
      }
   }
#endif
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_CopyRGB565
** Description:         Copies an RGB565 bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_CopyRGB565(unsigned height, unsigned width, UINT16 * p_data, unsigned p_layer)
{
   unsigned data;
   unsigned x_size;
   unsigned color;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   signed x = l_cur_x;
   signed y = l_cur_y;

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         data = *p_data++;

         if(x < l_max_x)
         {
         #ifdef RGB565_SWAP_MSB_AND_LSB
            data <<= 8;
            data  |= (data >> 16);
         #endif
            color = data & 0xFFFF;

            r     = ((color >> 11) & 0x1F);
            g     = ((color >> 5)  & 0x3F);
            b     = (color & 0x1F);

            a = 255;
            r = (r*255)/0x1F;
            g = (g*255)/0x3F;
            b = (b*255)/0x1F;
            hmi_sim_Blend_RGB(p_layer, x, y, r, g, b);
            x++;
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_Copy24BPP
** Description:         Copies a 24BPP bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Copy24BPP(unsigned height, unsigned width, unsigned char * p_data, unsigned p_layer)
{
   unsigned x_size;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   unsigned count;
   signed x = l_cur_x;
   signed y = l_cur_y;

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width/4;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         count = 4;
         while(count)
         {
            count--;
         #ifdef SWAP_MSB_AND_LSB
            r = *p_data++;
            g = *p_data++;
            b = *p_data++;
         #else
            b = *p_data++;
            g = *p_data++;
            r = *p_data++;
         #endif
            if(x < l_max_x)
            {
               a = 255;
               hmi_sim_Blend_RGB(p_layer, x, y, r, g, b);
               x++;
            }
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_Copy32BPP
** Description:         Copies a 32BPP bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_Copy32BPP(unsigned height, unsigned width, unsigned char * p_data, unsigned p_layer)
{
   unsigned x_size;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   signed x = l_cur_x;
   signed y = l_cur_y;

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         a     = *p_data++;
         r     = *p_data++;
         g     = *p_data++;
         b     = *p_data++;

         if(x < l_max_x)
         {
            hmi_sim_Blend_ARGB(p_layer, x, y, a, r, g, b);
            x++;
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_CopyARGB1555
** Description:         Copies an ARGB1555 bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_CopyARGB1555(unsigned height, unsigned width, UINT16 * p_data, unsigned p_layer)
{
   unsigned data;
   unsigned x_size;
   unsigned color;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   signed x = l_cur_x;
   signed y = l_cur_y;

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         data  = *p_data++;
         if(x < l_max_x)
         {
         #ifdef ARGB1555_SWAP_MSB_AND_LSB
            data <<= 8;
            data  |= (data >> 16);
         #endif
            color = data & 0xFFFF;
            a     = ((color >> 15) & 0x01);
            r     = ((color >> 10) & 0x1F);
            g     = ((color >> 5)  & 0x1F);
            b     = (color         & 0x1F);
            r     = (r*255)/0x1F;
            g     = (g*255)/0x1F;
            b     = (b*255)/0x1F;
            if(a)
            {
               a = 255;
            }
            hmi_sim_Blend_ARGB(p_layer, x, y, a, r, g, b);
            x++;
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_CopyARGB4444
** Description:         Copies an ARGB4444 bitmap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_CopyARGB4444(unsigned height, unsigned width, UINT16 * p_data, unsigned p_layer)
{
   unsigned data;
   unsigned x_size;
   unsigned color;
   unsigned r;
   unsigned g;
   unsigned b;
   unsigned a;
   signed x = l_cur_x;
   signed y = l_cur_y;

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         data   = *p_data++;
         if(x < l_max_x)
         {
         #ifdef ARGB4444_SWAP_MSB_AND_LSB
            data <<= 8;
            data  |= (data >> 16);
         #endif
            color = data & 0xFFFF;
            a     = ((color >> 12) & 0x0F);
            r     = ((color >>  8) & 0x0F);
            g     = ((color >>  4) & 0x0F);
            b     = ((color      ) & 0x0F);

            a = (a*255)/15;
            r = (r*255)/15;
            g = (g*255)/15;
            b = (b*255)/15;
            hmi_sim_Blend_ARGB(p_layer, x, y, a, r, g, b);
            x++;
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_CopyARGB4444
** Description:         Copies a 4/8BPP alphamap image to framebuffer.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_CopyAlphamap(unsigned height, unsigned width, unsigned * p_data, unsigned p_layer, unsigned bpp)
{
   unsigned data;
   unsigned x_size;
   unsigned a;
   unsigned c_reload;
   unsigned c_mask;
   unsigned count;
   unsigned c_shift;
   signed x = l_cur_x;
   signed y = l_cur_y;

   if(bpp == 0x07)
   {
      c_reload = 8;       //4bpp
      c_mask   = 15;
      c_shift  = 4;
   }
   else if(bpp == 0x03)
   {
      c_reload = 4;       //8bpp
      c_mask   = 255;
      c_shift  = 8;
   }
   else
   {
      return;
   }

   while(height)
   {
      if(y >= l_max_y)
      {
         break;
      }
      height--;
      x_size = width/c_reload;
      x      = l_cur_x;

      while(x_size)
      {
         x_size--;
         data = *p_data++;
         if(x < l_max_x)
         {
            count = c_reload;
            while(count)
            {
               count--;
               a = ((data & c_mask)*255)/c_mask;
               hmi_sim_Blend_ALPHA(p_layer, x, y, a);
               data >>= c_shift;
               x++;
            }
         }
      }
      y++;
   }
   //l_cur_x = x;
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_indexed
** Description:         Performs a copy/tile of an indexed bitmap image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_indexed(int p_layer, unsigned p_mask)
{
   char       fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed     s_x       = l_cur_x;

   width &= ~p_mask;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            return FALSE; /*The size of the graphic must be less than or equal to the size of the layer.*/
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_CopyIndexed(height, width, fl_data, p_layer, p_mask);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_CopyIndexed(height, width, fl_data, p_layer, p_mask);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_alphamap
** Description:         Performs a copy/tile of an alphamap image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_alphamap(int p_layer, unsigned p_mask)
{
   char       fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed   s_x = l_cur_x;

   width &= ~p_mask;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_CopyAlphamap(height, width, fl_data, p_layer, p_mask);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_CopyAlphamap(height, width, fl_data, p_layer, p_mask);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_rgb565
** Description:         Performs a copy/tile of an RGB565 image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_rgb565(int p_layer)
{
   char fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed   s_x = l_cur_x;

   width &= ~0x01;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_CopyRGB565(height, width, (UINT16 *)fl_data, p_layer);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_CopyRGB565(height, width, (UINT16 *)fl_data, p_layer);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_24bpp
** Description:         Performs a copy/tile of a RGB888 image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_24bpp(int p_layer)
{
   char fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed   s_x = l_cur_x;

   width &= ~0x03;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            fl_data = (unsigned int *)&DCU.CLUT[DCU.LAYER[p_layer].CTRLDESCL4.B.LUOFFS];
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_Copy24BPP(height, width, (void *)fl_data, p_layer);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_Copy24BPP(height, width, (void *)fl_data, p_layer);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_32bpp
** Description:         Performs a copy/tile of a ARGB8888 image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_32bpp(int p_layer)
{
   char fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed   s_x = l_cur_x;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_Copy32BPP(height, width, (void *)fl_data, p_layer);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_Copy32BPP(height, width, (void *)fl_data, p_layer);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_argb1555
** Description:         Performs a copy/tile of a ARGB1555 image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_argb1555(int p_layer)
{
   char fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed   s_x = l_cur_x;

   width &= ~0x01;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_CopyARGB1555(height, width, (UINT16 *)fl_data, p_layer);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_CopyARGB1555(height, width, (UINT16 *)fl_data, p_layer);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_copy_argb4444
** Description:         Performs a copy/tile of a ARGB4444 image after
**                      validating properties.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static char hmi_sim_dcu_copy_argb4444(int p_layer)
{
   char       fl_status = FALSE;
   unsigned   width     = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
   unsigned   height    = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
   unsigned * fl_data   = (unsigned *)DCU.LAYER[p_layer].CTRLDESCL3.R;
   signed     s_x       = l_cur_x;

   width &= ~0x01;

   if(width)
   {
      fl_status = TRUE;
      if(DCU.LAYER[p_layer].CTRLDESCL4.B.TILE_EN != 0)
      {
         unsigned tile_height;
         unsigned tile_width;
         unsigned cur_tile_width;

         tile_height = DCU.LAYER[p_layer].CTRLDESCL1.B.HEIGHT;
         tile_width  = DCU.LAYER[p_layer].CTRLDESCL1.B.WIDTH;
         width       = (DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_HOR_SIZE*16);
         height      = DCU.LAYER[p_layer].CTRLDESCL7.B.TILE_VER_SIZE;

         if(tile_width < width)
         {
            tile_width = width;
         }
         if(tile_height < height)
         {
            tile_height = height;
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width) >= (DCU.DISP_SIZE.B.DELTA_X * 16))
         {
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
         }
         else
         {
            l_max_x = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSX+tile_width);
         }
         if((DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height) >= DCU.DISP_SIZE.B.DELTA_Y)
         {
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
         }
         else
         {
            l_max_y = (DCU.LAYER[p_layer].CTRLDESCL2.B.POSY+tile_height);
         }
         if(DCU.LAYER[p_layer].CTRLDESCL4.B.DATA_SEL != 0)
         {
            /*
            ** If the graphic is fetched from CLUT/tile memory then
            ** it must be in RGB888 format.
            */
            return FALSE;
         }
         while(tile_height)
         {
            if(l_cur_y >= l_max_y)
            {
               break;
            }
            if(tile_height > height)
            {
               tile_height -= height;
            }
            else
            {
               tile_height = 0;
            }
            cur_tile_width = tile_width;
            l_cur_x = s_x;
            while(cur_tile_width)
            {
               if(cur_tile_width > width)
               {
                  cur_tile_width -= width;
               }
               else
               {
                  cur_tile_width = 0;
               }
               hmi_sim_CopyARGB4444(height, width, (UINT16 *)fl_data, p_layer);
               l_cur_x += width;
            }
            l_cur_y+= height;
         }
      }
      else
      {
         hmi_sim_CopyARGB4444(height, width, (UINT16 *)fl_data, p_layer);
      }
   }
   return(fl_status);
}

/*============================================================================
** Function Name:       hmi_sim_dcu_process
** Description:         This function builds all the 16DCU layers in to a frame
**                      buffer and then request for a display refresh.
** Invocation:
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_dcu_process(void)
{
   char       fl_copy_status;
   unsigned * fl_fbp = l_fb_p;

   if((DCU.DISP_SIZE.B.DELTA_X !=  0) &&  \
      (DCU.DISP_SIZE.B.DELTA_Y !=  0) &&  \
      (DCU.DCU_MODE.B.DCU_MODE ==  1) && fl_fbp)
   {
      int i;
      unsigned size = DCU.DISP_SIZE.B.DELTA_X*16*DCU.DISP_SIZE.B.DELTA_Y;
      unsigned bgc  = DCU.BGND.R;

      while(size)
      {
         /*
         ** Fill the whole framebuffer with background color.
         */
         size--;
         *fl_fbp  = bgc;
         fl_fbp++;
      }

      size   = DCU.DISP_SIZE.B.DELTA_X*16*(DCU.DISP_SIZE.B.DELTA_Y-1);
      fl_fbp = (l_fb_p+size);

      for(i=GFX_DCU_MAX_LAYER_ID; i >= 0; i--)
      {
         DCU_POS fl_pos;
         fl_pos.fl_x = (SINT16)DCU.LAYER[i].CTRLDESCL2.B.POSX;
         fl_pos.fl_y = (SINT16)DCU.LAYER[i].CTRLDESCL2.B.POSY;
         if((DCU.LAYER[i].CTRLDESCL4.B.EN != 0) &&
            (DCU.LAYER[i].CTRLDESCL1.B.WIDTH)   &&
            (DCU.LAYER[i].CTRLDESCL1.B.HEIGHT)  &&
            (fl_pos.fl_y < (signed)DCU.DISP_SIZE.B.DELTA_Y) &&
            (fl_pos.fl_x < (signed)(DCU.DISP_SIZE.B.DELTA_X*16)))
         {
            l_cur_x = fl_pos.fl_x;
            l_cur_y = fl_pos.fl_y;
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;

            /* copy the image */
            switch(DCU.LAYER[i].CTRLDESCL4.B.BPP)
            {
               case GFX_MGR02_1BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_indexed(i, 0x1F);
               }
               break;
               case GFX_MGR02_2BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_indexed(i, 0x0F);
               }
               break;
               case GFX_MGR02_4BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_indexed(i, 0x07);
               }
               break;
               case GFX_MGR02_8BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_indexed(i, 0x03);
               }
               break;
               case GFX_MGR02_16BPP_APAL8:
               {
                  fl_copy_status = hmi_sim_dcu_copy_indexed(i, 0x01);
               }
               break;
               case GFX_MGR02_16BPP_RGB565:
               {
                  fl_copy_status = hmi_sim_dcu_copy_rgb565(i);
               }
               break;
               case GFX_MGR02_24BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_24bpp(i);
               }
               break;
               case GFX_MGR02_32BPP:
               {
                  fl_copy_status = hmi_sim_dcu_copy_32bpp(i);
               }
               break;
               case GFX_MGR02_4BPP_TRANSPARENCY:
               {
                  fl_copy_status = hmi_sim_dcu_copy_alphamap(i, 0x07);
               }
               break;
               case GFX_MGR02_8BPP_TRANSPARENCY:
               {
                  fl_copy_status = hmi_sim_dcu_copy_alphamap(i, 0x03);
               }
               break;
               case GFX_MGR02_4BPP_LUMINANCE:
               {
                  fl_copy_status = hmi_sim_dcu_copy_alphamap(i, 0x07);
               }
               break;
               case GFX_MGR02_8BPP_LUMINANCE:
               {
                  fl_copy_status = hmi_sim_dcu_copy_alphamap(i, 0x03);
               }
               break;
               case GFX_MGR02_16BPP_ARGB1555:
               {
                  fl_copy_status = hmi_sim_dcu_copy_argb1555(i);
               }
               break;
               case GFX_MGR02_16BPP_ARGB4444:
               {
                  fl_copy_status = hmi_sim_dcu_copy_argb4444(i);
               }
               break;
               default:
               {
                  fl_copy_status = FALSE;
               }
               break;
            }
         }
      }
      if(DCU.CTRLDESCCURSOR3.B.CUR_EN != 0)
      {
         /* Check for blink on/off transition and prepare to start/stop blinking */
         if(l_cursor_blink_state_U8 == BLINK_INACTIVE)
         {
            if(DCU.CTRLDESCCURSOR4.B.EN_BLINK != 0)
            {
               if(DCU.CTRLDESCCURSOR4.B.HWC_BLINK_ON != 0)
               {
                  l_cursor_blink_state_U8 = BLINK_ACTIVE_ON;
                  /* count is decremented first, so add one to accomodate this */
                  l_cursor_blink_count_U8 = (DCU.CTRLDESCCURSOR4.B.HWC_BLINK_ON+1);
               }
            }
         }
         else if((DCU.CTRLDESCCURSOR4.B.EN_BLINK == 0) || (DCU.CTRLDESCCURSOR4.B.HWC_BLINK_ON == 0))
         {
            l_cursor_blink_state_U8 = BLINK_INACTIVE;
         }
         else
         {
         }
         /* Manage the blink counters to perform the On/Off */
         if(l_cursor_blink_state_U8 != BLINK_INACTIVE)
         {
            if(l_cursor_blink_count_U8 > 0)
            {
               l_cursor_blink_count_U8--;
            }
            if(l_cursor_blink_count_U8 == 0)
            {
               if(l_cursor_blink_state_U8 == BLINK_ACTIVE_ON)
               {
                  if(DCU.CTRLDESCCURSOR4.B.HWC_BLINK_OFF != 0)
                  {
                     l_cursor_blink_state_U8 = BLINK_ACTIVE_OFF;
                     l_cursor_blink_count_U8 = DCU.CTRLDESCCURSOR4.B.HWC_BLINK_OFF;
                  }
               }
               else
               {
                  l_cursor_blink_state_U8 = BLINK_ACTIVE_ON;
                  l_cursor_blink_count_U8 = DCU.CTRLDESCCURSOR4.B.HWC_BLINK_ON;
               }
            }
         }
         /* Build the cursor only if it needs to be visible */
         if(l_cursor_blink_state_U8 != BLINK_ACTIVE_OFF)
         {
            unsigned height    = 0;
            unsigned tot_width = (DCU.CTRLDESCCURSOR1.B.WIDTH+31)/32;
            unsigned mask      = 0x01;
            unsigned width;
            unsigned data;
            unsigned index;
            unsigned color;
            unsigned * fl_fbp_temp;
            unsigned fl_x;
            signed   y;
            /*
            ** Cursor needs to be shown, so build the cursor
            */
            l_cur_x = DCU.CTRLDESCCURSOR2.B.POSX;
            l_cur_y = DCU.CTRLDESCCURSOR2.B.POSY;
            l_max_x = (DCU.DISP_SIZE.B.DELTA_X * 16);
            l_max_y = DCU.DISP_SIZE.B.DELTA_Y;
            /*
            ** simulation window y orogin is bottom left corner and the DCU
            ** window y origin is top left corner. Perform the remapping to find out the
            ** frame buffer pointer.
            */
            y       = (DCU.DISP_SIZE.B.DELTA_Y - (l_cur_y+1));
            fl_fbp  = l_fb_p + ((y * DCU.DISP_SIZE.B.DELTA_X * 16)+l_cur_x);
            index   = 0;
            while(height < DCU.CTRLDESCCURSOR1.B.HEIGHT)
            {
               if(l_cur_y >= l_max_y)
               {
                  break;
               }
               fl_fbp_temp = fl_fbp;
               width = tot_width;
               fl_x  = l_cur_x;
               while(width)
               {
                  data = DCU.CURSOR[index++];
                  mask = 0x01;
                  while(mask)
                  {
                     if((data & mask) && ((int)fl_x < l_max_x))
                     {
                        color = DCU.CTRLDESCCURSOR3.B.CURSOR_DEFAULT_COLOR;
                        /*
                        ** Simulation window color format is BGR888 where as DCU is RGB888
                        ** so swap the B and R before writing.
                        */
                        color        = (color & 0x00FF00) + ((color >> 8) & 0xFF) + ((((unsigned char)color)<<16) & 0xFF0000);
                        *fl_fbp_temp = color;
                     }
                     fl_x++;
                     fl_fbp_temp++;
                     mask <<= 1;
                  }
                  width--;
               }
               l_cur_y++;
               height++;
               /*
               ** simulation window y orogin is bottom left corner, thats why we are decrementing
               ** by one row.
               */
               fl_fbp -= (DCU.DISP_SIZE.B.DELTA_X * 16);
            }
         }
      }
   }
}

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
static void hmi_sim_rle_process(void)
{
   UINT8 * rlesrc = 0;
   UINT8 * rledst = 0;
   int i, d1=0,d2=0;

   if(EDMA.CR.B.EMLM == 1)
   {
      for (i = 0u; i < 16; i++ )
      {
         if(DMAMUX.CHCONFIG[i].B.SOURCE == DMA_SR_RLE_Tx_FIFO)
         {
            rledst = EDMA.TCD[i].DADDR;
            EDMA.TCD[i].SADDR = 0;
            if(EDMA.SERQ.R == i)
            {
               EDMA.SERQ.R = DMA_MAXIMUM_SUPPORTED_CHANNELS;
            }
            d1=i;
         }
         else if(DMAMUX.CHCONFIG[i].B.SOURCE == DMA_SR_RLE_Rx_FIFO)
         {
            rlesrc = EDMA.TCD[i].SADDR;
            EDMA.TCD[i].SADDR = 0;
            if(EDMA.SERQ.R == i)
            {
               EDMA.SERQ.R = DMA_MAXIMUM_SUPPORTED_CHANNELS;
            }
            d2=i;
         }
         else
         {
         }
      }
      if(rledst && rlesrc)
      {
         int rle_format = RLE.ICR.B.WIDTH;
         int size       = RLE.CISR.B.SIZE;
         int rle_width  = RLE.DICR.B.X;
         int rle_height = RLE.DICR.B.Y;
         int sp_x       = RLE.SPCR.B.X;
         int sp_y       = RLE.SPCR.B.Y;
         int ep_x       = RLE.EPCR.B.X;
         int ep_y       = RLE.EPCR.B.Y;
         int command;
         unsigned int data;
         while(size > 0)
         {
            command = rlesrc[0];rlesrc++;size--;
            if(command & 0x80)
            {
               command &= 0x7F;
               while(command >= 0)
               {
                  if(rle_format == 0)
                  {
                     data = rlesrc[0];
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 1)
                  {
                     data = rlesrc[0];
                     rledst[0] = data;rledst++;
                     data = rlesrc[1];
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 2)
                  {
                     data = rlesrc[0];
                     rledst[0] = data;rledst++;
                     data = rlesrc[1];
                     rledst[0] = data;rledst++;
                     data = rlesrc[2];
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 3)
                  {
                     data = rlesrc[0];
                     rledst[0] = data;rledst++;
                     data = rlesrc[1];
                     rledst[0] = data;rledst++;
                     data = rlesrc[2];
                     rledst[0] = data;rledst++;
                     data = rlesrc[3];
                     rledst[0] = data;rledst++;
                  }
                  else
                  {
                     command = -1;size=0;
                  }
                  command--;
               }
               if(rle_format == 0)
               {
                  rlesrc++;size--;
               }
               else if(rle_format == 1)
               {
                  rlesrc+=2;size-=2;
               }
               else if(rle_format == 2)
               {
                  rlesrc+=3;size-=3;
               }
               else if(rle_format == 3)
               {
                  rlesrc+=4;size-=4;
               }
               else
               {
                  command = -1;size=0;
               }
            }
            else
            {
               while(command >= 0)
               {
                  if(rle_format == 0)
                  {
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 1)
                  {
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 2)
                  {
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                  }
                  else if(rle_format == 3)
                  {
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                     data = rlesrc[0];rlesrc++;size--;
                     rledst[0] = data;rledst++;
                  }
                  else
                  {
                     command = -1;size=0;
                  }
                  command--;
               }
            }
         }
         DMAMUX.CHCONFIG[d1].B.SOURCE = DMA_SR_ALWAYS_ENB_0;
         DMAMUX.CHCONFIG[d2].B.SOURCE = DMA_SR_ALWAYS_ENB_0;
         DMA_Handler_ChannelISR(d1, DMA_COMPLETE_ISR);
         DMA_Handler_ChannelISR(d2, DMA_COMPLETE_ISR);
         hmi_gfx_mgr02_rle_isr();
      }
   }
}
#endif

#if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_FARADAY)
static void hmi_sim_DMA_process(void)
{
    uint32_t i, iMinor, iMajor;
    uint32_t iMinorLoopCount, iMLOFF;
    uint32_t tcd_nbytes;
    uint8_t  *addressSrc, *addressDest;
    uint8_t dma_active;
    uint8_t iSMLOE, iDMLOE;
    uint8_t src_xfr_size, dest_xfr_size, xfr_size;
    uint8_t source_data[4];
    uint8_t loop_count;
    uint8_t xfr_count;
    uint8_t index;

    if(EDMA.CR.B.EMLM == 1)
    {
        dma_active = 0;

        for (i = 0u; i < 16; i++ )
        {
            while((EDMA.SERQ.R == i) && (DMA_Handler_GetChannelStatus(i) != DMA_CH_IDLE))
            {
                if((DMAMUX.CHCONFIG[i].B.SOURCE == DMA_SR_RLE_Rx_FIFO) || 
                   (DMAMUX.CHCONFIG[i].B.SOURCE == DMA_SR_RLE_Tx_FIFO))
                {
                #ifdef GFX_MGR02_COMPRESSION_ENABLED
                   hmi_sim_rle_process();
                #endif
                   break;
                }
                
                EDMA.SERQ.R = DMA_MAXIMUM_SUPPORTED_CHANNELS;
                dma_active = 1;

                addressSrc = (uint8_t *)EDMA.TCD[ i ].SADDR;
                addressDest = (uint8_t *)EDMA.TCD[ i ].DADDR;

                tcd_nbytes = EDMA.TCD[i].NBYTESu.R;

                if ((tcd_nbytes & 0x00000001) != 0)
                {
                  iSMLOE = 1;
                }
                else
                {
                  iSMLOE = 0;
                }

                if ((tcd_nbytes & 0x00000002) != 0)
                {
                  iDMLOE = 1;
                }
                else
                {
                  iDMLOE = 0;
                }

                if (iSMLOE != 0 || iDMLOE != 0)
                {
                   iMLOFF = (tcd_nbytes & 0x003FFFFC) >> 2;
                   iMinorLoopCount = (tcd_nbytes & 0xFFC00000) >> 22;
                }
                else
                {
                   iMLOFF = 0;
                   iMinorLoopCount = ((EDMA.TCD[i].NBYTESu.B.MLOFF) << 10) + EDMA.TCD[i].NBYTESu.B.NBYTES;
                }


                if (EDMA.TCD[i].SSIZE == 0)
                {
                    src_xfr_size = 1;
                }
                else if (EDMA.TCD[i].SSIZE == 1)
                {
                    src_xfr_size = 2;
                }
                else if (EDMA.TCD[i].SSIZE == 2)
                {
                    src_xfr_size = 4;
                }

                if (EDMA.TCD[i].DSIZE == 0)
                {
                    dest_xfr_size = 1;
                }
                else if (EDMA.TCD[i].DSIZE == 1)
                {
                    dest_xfr_size = 2;
                }
                else if (EDMA.TCD[i].DSIZE == 2)
                {
                    dest_xfr_size = 4;
                }

                if (EDMA.TCD[i].SSIZE < EDMA.TCD[i].DSIZE)
                {
                    xfr_size = dest_xfr_size;
                }
                else
                {
                    xfr_size = src_xfr_size;
                }


                for(iMajor=0; iMajor < EDMA.TCD[i].BITER; iMajor++)
                {
                    for(iMinor=0; iMinor < iMinorLoopCount; iMinor+=xfr_size)
                    {
                        loop_count = xfr_size / src_xfr_size;
                        index = 0;
                        while (loop_count != 0)
                        {
                        #if 0
                            memcpy(&source_data[index], &addressSrc[index], src_xfr_size);
                            index += src_xfr_size;
                        #else
                            xfr_count = src_xfr_size;
                            while (xfr_count != 0)
                            {
                                source_data[index] = addressSrc[index];
                                index++;
                                xfr_count--;
                            }
                        #endif
                            loop_count--;
                            addressSrc = addressSrc + EDMA.TCD[i].SOFF;
                        }

                        loop_count = xfr_size / dest_xfr_size;
                        index = 0;
                        while (loop_count != 0)
                        {
                        #if 0
                            memcpy(&addressDest[index], &source_data[index], dest_xfr_size);
                            index += dest_xfr_size;
                        #else
                            xfr_count = dest_xfr_size;
                            while (xfr_count != 0)
                            {
                                addressDest[index] = source_data[index];
                                index++;
                                xfr_count--;
                            }
                        #endif
                            loop_count--;
                            addressDest = addressDest + EDMA.TCD[i].DOFF;
                        }
                    }


                    if (iSMLOE == 1)
                    {
                        addressSrc +=  iMLOFF;
                    }

                    if (iDMLOE == 1)
                    {
                        addressDest +=  iMLOFF;
                    }

                }
                DMA_Handler_ChannelISR(i, DMA_COMPLETE_ISR);
            }
        }
    }
}
#endif

/*============================================================================
** Function Name:       TimerProc
** Description:         Timer tick.
** Invocation:          Executed every HMI_SIMUL_TICK_MSEC mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
   l_system_tick_U16++;
   if((l_system_tick_U16 % HMI_SIMUL_DCU_TICK_RATE) == 0)
   {
      l_tick_flag_U8 = 1;
      hmi_sim_tick();
   }
}

/*============================================================================
** Function Name:       hmi_sim_tick
** Description:         Schedules the DCU ISR and the DCU process.
** Invocation:          Called by GLUT framework every 33mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
static void hmi_sim_tick(void)
{
   int fl_update_pending;
   if((DCU.DCU_MODE.B.DCU_MODE) && (l_fb_p))
   {
   #ifdef HMI_GFX_DAO_SIMU
      if((l_tick_flag_U8 == 1) && (*l_Update_P == 2))
   #else
      if(l_tick_flag_U8 == 1)
   #endif
      {
         fl_update_pending = l_update_pending;
         if(fl_update_pending)
         {
            l_update_pending = 0;
         }
         l_tick_flag_U8 = 0;
         DCU.INT_STATUS.B.VS_BLANK = 1;
         HMI_SIM_DCU_ISR();
         DCU.INT_STATUS.B.DMA_TRANS_FINISH = 1;
         HMI_SIM_DCU_ISR();
         DCU.INT_STATUS.B.VS_BLANK = 0;
         DCU.INT_STATUS.B.DMA_TRANS_FINISH = 0;
      #if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_FARADAY)
         hmi_sim_DMA_process();
      #endif
         if(fl_update_pending)
         {
            hmi_sim_dcu_process();
            InvalidateRect(ghWnd, NULL, FALSE);
         #ifdef HMI_GFX_DAO_SIMU
            *l_Update_P = 1;
         #endif
         }
      }      
   }
}

#ifndef HMI_GFX_DAO_SIMU
/*============================================================================
**
** Function Name:       DrawPixels
** Visibility:          global.
** Description:         Blends the framebuffer in to the simulation window
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             13/Jan/11 by EMANOJ1
** Updated:             13/Jan/11 by EMANOJ1
**==========================================================================*/
static void DrawPixels(HWND hWnd, HDC hdcwnd)
{
   HDC           hdc;           // handle of the DC we will create
   BITMAPINFO    bmi;           // bitmap header
   ULONG         ulWindowWidth, ulWindowHeight;      // window width/height
   RECT          rt;            // used for getting window dimensions
   ULONG         ulBitmapWidth, ulBitmapHeight;      // bitmap width/height

   GetClientRect(hWnd, &rt);
   ulWindowWidth  = rt.right  - rt.left;
   ulWindowHeight = rt.bottom - rt.top;
   hdc = CreateCompatibleDC(hdcwnd);

   if((hbitmap == 0) && (ulWindowWidth) && (ulWindowHeight))
   {
      ZeroMemory(&bmi, sizeof(BITMAPINFO));
      ulBitmapWidth  = ulWindowWidth;
      ulBitmapHeight = ulWindowHeight;
      ulBitmapWidth  = lcd_size.lcd_size_width;
      ulBitmapHeight = lcd_size.lcd_size_height;
      bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
      bmi.bmiHeader.biWidth       = ulBitmapWidth;
      bmi.bmiHeader.biHeight      = ulBitmapHeight;
      bmi.bmiHeader.biPlanes      = 1;
      bmi.bmiHeader.biBitCount    = 32;         // four 8-bit components
      bmi.bmiHeader.biCompression = BI_RGB;
      bmi.bmiHeader.biSizeImage   = (ulBitmapWidth * ulBitmapHeight * 4);
      hbitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
   #ifndef HMI_GFX_DAO_SIMU
      l_fb_p  = pvBits;
   #endif
   }

   if((DCU.DISP_SIZE.B.DELTA_X !=  0) &&  \
      (DCU.DISP_SIZE.B.DELTA_Y !=  0) &&  \
      (DCU.DCU_MODE.B.DCU_MODE  == 1)     )
   {
   #ifdef HMI_GFX_DAO_SIMU
	   memcpy(pvBits, l_fb_p, ulWindowWidth*ulWindowHeight*4);
   #endif
       SelectObject(hdc, hbitmap);
       BitBlt(hdcwnd,
              rt.left,       rt.top,
              ulWindowWidth, ulWindowHeight,
              hdc,
              0, 0,
              SRCCOPY);
       DeleteDC(hdc);
   }
}

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
VOID CALLBACK DragTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
   drag_process(&drag_ctx);
}
#endif

/*============================================================================
**
** Function Name:       MainWndProc
** Visibility:          global.
** Description:         main window procedure.
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
LONG WINAPI MainWndProc (HWND    hWnd, UINT    uMsg, WPARAM  wParam, LPARAM  lParam)
{
   LONG         lRet = 1;
   PAINTSTRUCT  ps;
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
   static int   l_distance;
#endif

   switch (uMsg)
   {
   case WM_CREATE:
      {
         ghDC = GetDC(hWnd);
         if (!bSetupPixelFormat(ghDC))
         {
            PostQuitMessage (0);
         }
      }
      break;

   case WM_PAINT:
      {
         HDC hwndc = BeginPaint(hWnd, &ps);
         DrawPixels(hWnd, hwndc);
         EndPaint(hWnd, &ps);
         lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
      }
      break;

   case WM_SIZE:
      {
      }
      break;

   case WM_CLOSE:
      {
         if (ghDC)
         {
            ReleaseDC(ghWnd, ghDC);
            ghRC = 0;
            ghDC = 0;
         }
         DestroyWindow (ghWnd);
      }
      break;

   case WM_DESTROY:
      {
         if(ghDC)
         {
            ReleaseDC(ghWnd, ghDC);
         }
         PostQuitMessage (0);
      }
      break;

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
  case WM_MOUSEMOVE:
    {
      if(l_button_pressed != FALSE)
      {
        GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
        fl_touch_data_SP.x     = LOWORD(lParam);
        fl_touch_data_SP.y     = HIWORD(lParam);
        fl_touch_data_SP.event = GFX_MGR02_MOUSE_MOVE_EV;
        
        drag_mouse_ev(&drag_ctx, uMsg, fl_touch_data_SP.x, fl_touch_data_SP.y);
		if(drag_ctx.y.tdistance == 0)
		{
		   fl_touch_data_SP.distance = 0;
		}
		else
		{
		   fl_touch_data_SP.distance = (l_distance-drag_ctx.y.tdistance);
		}
		fl_touch_data_SP.velocity = drag_ctx.y.velocity;
		fl_touch_data_SP.gesture  = GFX_MGR02_GESTURE_DRAG;

        hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
        l_distance = drag_ctx.y.tdistance;
      }
    }
    break;

  case WM_LBUTTONDOWN:
    {
      GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
      fl_touch_data_SP.x     = LOWORD(lParam);
      fl_touch_data_SP.y     = HIWORD(lParam);
      fl_touch_data_SP.event = GFX_MGR02_MOUSE_DOWN_EV;

      drag_mouse_ev(&drag_ctx, uMsg, fl_touch_data_SP.x, fl_touch_data_SP.y);
	  fl_touch_data_SP.distance = 0;
	  fl_touch_data_SP.velocity = 0;
	  fl_touch_data_SP.gesture  = GFX_MGR02_GESTURE_NONE;

      hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
      l_button_pressed = TRUE;
	  l_distance = 0;
    }
    break;

  case WM_LBUTTONUP:
    {
      if(l_button_pressed != FALSE)
      {
        GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
        fl_touch_data_SP.x     = LOWORD(lParam);
        fl_touch_data_SP.y     = HIWORD(lParam);
        fl_touch_data_SP.event = GFX_MGR02_MOUSE_UP_EV;

        drag_mouse_ev(&drag_ctx, uMsg, fl_touch_data_SP.x, fl_touch_data_SP.y);
		if(drag_ctx.y.tdistance == 0)
		{
		   fl_touch_data_SP.distance = 0;
		}
		else
		{
		   fl_touch_data_SP.distance = (l_distance-drag_ctx.y.tdistance);
		}
		fl_touch_data_SP.velocity = drag_ctx.y.velocity;
		fl_touch_data_SP.gesture  = GFX_MGR02_GESTURE_DRAG;

        hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP);
        l_distance = drag_ctx.y.tdistance;
        l_button_pressed = FALSE;
      }
    }
    break;
#endif

   default:
      {
         lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
      }
      break;
   }
   return lRet;
}

/*============================================================================
**
** Function Name:       bSetupPixelFormat
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
static BOOL bSetupPixelFormat(HDC hdc)
{
   PIXELFORMATDESCRIPTOR pfd, *ppfd;
   int pixelformat;

   ppfd = &pfd;

   ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
   ppfd->nVersion = 1;
   ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
      PFD_DOUBLEBUFFER;
   ppfd->dwLayerMask = PFD_MAIN_PLANE;
   ppfd->iPixelType = PFD_TYPE_COLORINDEX;
   ppfd->cColorBits = 8;
   ppfd->cDepthBits = 16;
   ppfd->cAccumBits = 0;
   ppfd->cStencilBits = 0;

   pixelformat = ChoosePixelFormat(hdc, ppfd);

   if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 )
   {
      MessageBox(NULL, TEXT("ChoosePixelFormat failed"), TEXT("Error"), MB_OK);
      return FALSE;
   }

   if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE)
   {
      MessageBox(NULL, TEXT("SetPixelFormat failed"), TEXT("Error"), MB_OK);
      return FALSE;
   }

   return TRUE;
}
#endif

/*============================================================================
**
** Function Name:       DestroyLcdWindow
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             26/Aug/10 by TVIJAYAS
** Updated:             09/Aug/12 by ASHEKHAR
**==========================================================================*/
void hmi_gfx02_dcu_sim_stop(void)
{
  #ifdef HMI_GFX_DAO_SIMU
  free(l_fb_p);
  #else
   ghWnd = FindWindow(TEXT("GDTSimWinClass"), TEXT("GDTSimWindow"));
   if(ghWnd != NULL)
   {
     DestroyWindow(ghWnd);
     UnregisterClass(TEXT("GDTSimWinClass"),GetModuleHandle(NULL));
   }
   if(hbitmap)
   {
      DeleteObject(hbitmap);
      hbitmap = 0;
   }
  #endif
}
/*============================================================================
**
** Function Name:       gls_init
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
void hmi_gfx02_dcu_sim_init(int zoom)
{
#ifdef HMI_GFX_DAO_SIMU
   lcd_size.lcd_size_width  = DCU.DISP_SIZE.B.DELTA_X*16;
   lcd_size.lcd_size_height = DCU.DISP_SIZE.B.DELTA_Y;
   lcd_size.zoom            = zoom;
   l_Update_P = GetMemPointer(0);
   l_fb_p = GetMemPointer(1);
   *l_Update_P = 2;
    SetTimer(NULL, 0, HMI_SIMUL_TICK_MSEC, TimerProc);
#else
   RECT       rect;
   WNDCLASS   wndclass;
   LPWNDCLASS wndclassinfo = NULL;

   ghWnd = FindWindow(TEXT("GDTSimWinClass"), TEXT("GDTSimWindow"));
   if(ghWnd != NULL)
   {
       return;
   }

   lcd_size.lcd_size_width  = DCU.DISP_SIZE.B.DELTA_X*16;
   lcd_size.lcd_size_height = DCU.DISP_SIZE.B.DELTA_Y;
   lcd_size.zoom            = zoom;
   /* Register the frame class */
   wndclass.style         = 0;
   wndclass.lpfnWndProc   = (WNDPROC)MainWndProc;
   wndclass.cbClsExtra    = 0;
   wndclass.cbWndExtra    = 0;
   wndclass.hInstance     = GetModuleHandle(NULL);
   wndclass.hIcon         = LoadIcon (GetModuleHandle(NULL), TEXT("GDTSimWinClass"));
   wndclass.hCursor       = LoadCursor (NULL,IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
   wndclass.lpszMenuName  = TEXT("GDTSimWinClass");
   wndclass.lpszClassName = TEXT("GDTSimWinClass");


   if(!GetClassInfo(GetModuleHandle(NULL),TEXT("GDTSimWinClass"),wndclassinfo))
   {
      if (!RegisterClass (&wndclass) )
      {
        return;
      }
   }

   /* Create the frame */
   ghWnd = CreateWindow (TEXT("GDTSimWinClass"),
                         TEXT("GDTSimWindow"),
                         0,
                         CW_USEDEFAULT,
                         CW_USEDEFAULT,
                         lcd_size.lcd_size_width,
                         lcd_size.lcd_size_height,
                         NULL,
                         NULL,
                         GetModuleHandle(NULL),
                         NULL);

   /* make sure window was created */
   if (!ghWnd)
   {
      printf("Simulation window creation failed, exiting gls_init.\n");
      return;
   }

   GetClientRect(ghWnd, &rect);
   if(lcd_size.lcd_size_width > rect.right)
   {
      rect.right = (lcd_size.lcd_size_width-rect.right);
   }
   else
   {
      rect.right = 0;
   }
   rect.right += lcd_size.lcd_size_width;
   if(lcd_size.lcd_size_height > rect.bottom)
   {
      rect.bottom = (lcd_size.lcd_size_height-rect.bottom);
   }
   else
   {
      rect.bottom = 0;
   }
   rect.bottom += lcd_size.lcd_size_height;
   MoveWindow(ghWnd,rect.left, rect.top, rect.right, rect.bottom, TRUE);
   ShowWindow (ghWnd, 1);
   UpdateWindow (ghWnd);
   /*Start the timer to schedule the DCU interrupt*/
   SetTimer(NULL, 0, HMI_SIMUL_TICK_MSEC, TimerProc);
#if defined(GFX_MGR02_MONOTFT)
DCU.CLUT[0] =0;
DCU.CLUT[1] =0x111111;
DCU.CLUT[2] =0x222222;
DCU.CLUT[3] =0x333333;
DCU.CLUT[4] =0x444444;
DCU.CLUT[5] =0x555555;
DCU.CLUT[6] =0x666666;
DCU.CLUT[7] =0x777777;
DCU.CLUT[8] =0x888888;
DCU.CLUT[9] =0x999999;
DCU.CLUT[10] =0xAAAAAA;
DCU.CLUT[11] =0xBBBBBB;
DCU.CLUT[12] =0xCCCCCC;
DCU.CLUT[13] =0xDDDDDD;
DCU.CLUT[14] =0xEEEEEE;
DCU.CLUT[15] =0xFFFFFF;
#endif
 #if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
   SetTimer(NULL, 0, DRAG_TIMER_TICK_RATE_MS, DragTimerProc);
 #endif
#endif
}

/*============================================================================
**
** Function Name:       gls_update_lcd
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
void hmi_gfx02_dcu_sim_update(void)
{
   l_update_pending = 1;
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
**
** Rev 1.0         15-SEP-2009    EMANOJ1
** Creation
**
** Rev 1.1         23-SEP-2009    EMANOJ1
** All the image copy functions updated to properly clip the off screen portion
** of the image and to coorrectly display the tiling.
** Implemented the Cursor display and Cursor Blinking
**
** Rev 1.2         14-JULY-2010   tvijayas
** Removed all thread implementation to avoid matlab crashing when stopped and
** started again. used seperate LCD app simulator.removed GLUT usage.
**
** Rev 1.3         10-Jul-12      EMANOJ1
** Updated based on the BPP_and_encoding type definitions changes in 
** hmi_gfx_mgr02_types.h
**
** Rev 1.4        09-Aug-2012     ASHEKHAR
** Updated to include the Altia DAO rendering.
**
** Rev 1.5        27-Aug-2012     ASHEKHAR
** Fixed X, Y- position (negative y position) Updated the following functions.
** 1. hmi_sim_Blend_ARGB 
** 2. hmi_sim_Blend_RGB
** 3. hmi_sim_Blend_ALPHA
**==========================================================================*/

/*

This simulation Uses the GLUT Win32:-

COPYRIGHT:

The OpenGL Utility Toolkit distribution for Win32 (Windows NT &
Windows 95) contains source code modified from the original source
code for GLUT version 3.3 which was developed by Mark J. Kilgard.  The
original source code for GLUT is Copyright 1997 by Mark J. Kilgard.
GLUT for Win32 is Copyright 1997 by Nate Robins and is not in the
public domain, but it is freely distributable without licensing fees.
It is provided without guarantee or warrantee expressed or implied.
It was ported with the permission of Mark J. Kilgard by Nate Robins.

THIS SOURCE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OR MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

OpenGL (R) is a registered trademark of Silicon Graphics, Inc.
*/

/* end of file =============================================================*/
#ifdef  __cplusplus
}
#endif
