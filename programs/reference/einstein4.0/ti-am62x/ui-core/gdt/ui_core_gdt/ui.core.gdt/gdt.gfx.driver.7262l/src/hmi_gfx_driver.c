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

File Name        :  hmi_gfx_driver.c
Module Short Name:  Driver
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Graphics Driver

Organization     :  Driver Information Software Section,
                    Visteon Corporation
List the compiler name with the ersion number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :  
Target Processor :  
******************************************************************************/

#define HMI_GFX_DRIVER_C
/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

#ifndef WIN32
  #include "iodefine.h"
#endif

#include "system.h"

#ifndef WIN32
  #include "sched.h"
  #include "kernel.h"
#else
  #include "hmi_simulation_tick.h"
  #include "gfx_lcd_simulator.h"
  #include <string.h>
#endif

#include "hmi_gfx_driver.h"

#ifdef ENABLE_FPS_CALCULATION
  #include "B2YY12.c"
#endif

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
** Layer indexes.
*/
#define GFX_DRIVER_LAYER_0        (0)
#define GFX_DRIVER_LAYER_1        (1)
/*
** Frame buffer indexes.
*/
#define GFX_DRIVER_FB_0           (0)
#define GFX_DRIVER_FB_1           (1)
/*
** Supported devices
*/
#define GFX_DRV_7262L             (0)
#define GFX_DRV_7262              (1)

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#if NB_LAYERS > 2
  #error "This driver Supports only up to two layers.."
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
static GFX_DRV_FADE_PARAMS l_fade_data[NB_FADE_EFFECT_CONFIG] =
{
  HMI_FADE_CONFIG
};

typedef struct
{
   UINT8    b_open          : 1;
   UINT8    b_active        : 1;
   UINT8    b_update        : 1;
   UINT8    b_fb_copied     : 1;
   UINT8    b_work_fb_index : 1;
}GFX_DRIVER_LAYER_DATA_T;

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

#ifdef ENABLE_FPS_CALCULATION
  UINT16 fps_start_count; 
  UINT16 fps_end_count; 
  UINT16 fps_longest_count = 0;          
  UINT16 fps_base_count;
#endif

#if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
  static volatile       UINT8    l_fade_effect_mode_U8;
  static                UINT8    l_fade_effect_id_U8;
#endif

#if NB_LAYERS > 1
  static GFX_DRIVER_LAYER_DATA_T * l_working_layer_data_SP;
#else
  #define p_lid_U8                 (GFX_DRIVER_LAYER_0) 
  #define l_working_layer_data_SP  (&l_layer_data_S[GFX_DRIVER_LAYER_0])
#endif

static GFX_DRIVER_LAYER_DATA_T   l_layer_data_S[NB_LAYERS];

#ifdef WIN32
  UINT16  l_fade_alpha_U8 = 255;
  UINT8   l_win1_handle   = 0;
#endif

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
  static RECTANGLE_DEF_T  l_clip_area_S[1];
#endif

/*
** Declared by GDT generated code..
*/
extern LAYER_TABLE_T lc_layer_table_S[NB_LAYERS];


/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/
#ifdef ENABLE_FPS_CALCULATION
  static void GfxDriverUpdateFps(void);
#endif

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
#ifndef WIN32
/****************************************************************************
Function Name        : GfxDriverTFTInitialize
Description          : Function to Initialize the TFT 
Invocation           : Called by Operating Mode Manager once the Display Power
                       is Enabled 
Parameters           : None
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverTFTInitialize(void)
{
   /*
   ** Initialize the VDC
   */
   VDC3.GRCMEN1.BIT.VEN            = 1;
   VDC3.GRCMEN2.BIT.VEN            = 1;
   VDC3.GRCBUSCNT1.BIT.ENDIAN      = 0;
   VDC3.GRCBUSCNT2.BIT.ENDIAN      = 0;
   VDC3.VIDEO_MODE.BIT.ENDIAN_DISP = 0;
   VDC3.VIDEO_MODE.BIT.ENDIAN_MAIN = 0;
   VDC3.VIDEO_MODE.BIT.INV_CbCr    = 0;
   /*
   ** Port Configuration.
   */
   PORT.PGIOR1.BIT.PG21IOR         = 1;
   PORT.PGDR1.BIT.PG21DR           = 1;
   PORT.PGCR5.BIT.PG20MD           = 1;
   PORT.PGCR5.BIT.PG21MD           = 0;
/*    PORT.PECR1.BIT.PE4MD            = 3; */
/*    PORT.PECR1.BIT.PE5MD            = 3; */
   PORT.PFCR3.BIT.PF12MD           = 0;
   PORT.PFIOR0.BIT.PF12IOR         = 1;
   PORT.PFDR0.BIT.PF12DR           = 1;
   PORT.PFCR2.BIT.PF8MD            = 3;
   PORT.PFCR0.WORD                 = 0x3333;       /* DV_DATA3-0           */
   PORT.PFCR1.WORD                 = 0x3333;       /* DV_DATA7-4           */
   PORT.PGCR7.WORD                 = 0x5A01;
// PORT.PGCR7.BIT.PG0MD            = 1;            /* LCD_DATA00           */
   PORT.PGCR0.BIT.PG1MD            = 1;            /* LCD_DATA01           */
   PORT.PGCR0.BIT.PG2MD            = 1;            /* LCD_DATA02           */
   PORT.PGCR0.BIT.PG3MD            = 1;            /* LCD_DATA03           */
   PORT.PGCR1.WORD                 = 0x1111;       /* LCD_DATA07-04        */
   PORT.PGCR2.WORD                 = 0x1111;       /* LCD_DATA11-08        */
   PORT.PGCR3.WORD                 = 0x1111;       /* LCD_DATA15-12        */
   PORT.PGCR4.WORD                 = 0x1111;       /* LCD_CLK, DE, HSYNC, VSYNC*/
   /*
   ** Interrupt Configuration
   */
   VDC3.SGINTCNT.BIT.LINE_STATUS   = 0;
   VDC3.SGINTCNT.BIT.INT_LINE_EN   = 0;
   VDC3.SGINTCNT.BIT.INT_LINE_NUM  = 0;
   INTC.IPR10.BIT._VDC3            = 10;
   CPG.STBCR7.BIT.MSTP74           = 0;
   /*
   ** LCD panel configuration
   */ 
   VDC3.GRA_VSYNC_TIM.LONG      = 0x0000000B; /* GRA_VSYNC_START */
   VDC3.SYNCNT.LONG             = 0x0000000C; /* VSYNC_TYPE & HSYNC_TYPE Inverted */
   VDC3.PANEL_CLKSEL.BIT.ICKEN  = 0;
#ifdef YUKAWA_VER1_HARDWARE
   VDC3.PANEL_CLKSEL.LONG       = (0x00003000 + PANEL_CLK_DIV_RATIO);
#else   /* YUKAWA_VER2_HARDWARE*/
   VDC3.PANEL_CLKSEL.LONG       = 0x00001001;
#endif
   VDC3.SYN_SIZE.LONG           = ((PANEL_TOTAL_VLINE_NB << 16) + PANEL_TOTAL_HPIXEL_NB); 
   VDC3.PANEL_VSYNC_TIM.LONG    = PANEL_VSYNC_WIDTH;
   VDC3.PANEL_HSYNC_TIM.LONG    = PANEL_HSYNC_WIDTH;
   VDC3.DE_SIZE.LONG            = ((PANEL_VDISPLAY_LINE << 16) + PANEL_HDISPLAY_PIXEL);
   VDC3.DE_START.LONG           = ((PANEL_VBACK_PORCH   << 16) + PANEL_HBACK_PORCH);
   /*
   ** Initialize the Layer 1 
   */
   VDC3.GROPSOFST1.BIT.GROPSOFST= lc_layer_table_S[GFX_DRIVER_LAYER_0].width * 2;
   VDC3.GROPSADR1.BIT.GROPSADR  = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
   VDC3.GROPSWH1.BIT.GROPSW     = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
   VDC3.GROPSWH1.BIT.GROPSH     = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
   VDC3.GROPDPHV1.BIT.GROPDPV   = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y;
   VDC3.GROPDPHV1.BIT.GROPDPH   = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x;
   VDC3.GROPEWH1.BIT.GROPEW     = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
   VDC3.GROPEWH1.BIT.GROPEH     = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
   VDC3.GROPEDPHV1.BIT.GROPEDPV = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y;
   VDC3.GROPEDPHV1.BIT.GROPEDPH = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x;
   if(lc_layer_table_S[GFX_DRIVER_LAYER_0].pix_format == GFX_ARGB4444)
   {
      VDC3.GRCBUSCNT1.BIT.BUS_FORMAT  = 1; /*ARGB4444*/
   }
   else
   {
      VDC3.GRCBUSCNT1.BIT.BUS_FORMAT  = 0; /*RGB565*/
   }
   VDC3.GRCBUSCNT1.BIT.BURST_MODE  = 0;
 #if NB_LAYERS > 1
   /*
   ** Initialize the Layer 2 
   */
   VDC3.GROPSOFST2.BIT.GROPSOFST= lc_layer_table_S[GFX_DRIVER_LAYER_1].width * 2;
   VDC3.GROPSADR2.BIT.GROPSADR  = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
   VDC3.GROPSWH2.BIT.GROPSW     = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
   VDC3.GROPSWH2.BIT.GROPSH     = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
   VDC3.GROPDPHV2.BIT.GROPDPV   = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
   VDC3.GROPDPHV2.BIT.GROPDPH   = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
   VDC3.GROPEWH2.BIT.GROPEW     = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
   VDC3.GROPEWH2.BIT.GROPEH     = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
   VDC3.GROPEDPHV2.BIT.GROPEDPV = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
   VDC3.GROPEDPHV2.BIT.GROPEDPH = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
   if(lc_layer_table_S[GFX_DRIVER_LAYER_1].pix_format == GFX_ARGB4444)
   {
      VDC3.GRCBUSCNT2.BIT.BUS_FORMAT  = 1; /*ARGB4444*/
   }
   else
   {
      VDC3.GRCBUSCNT2.BIT.BUS_FORMAT  = 0; /*RGB565*/
   }
   VDC3.GRCBUSCNT2.BIT.BURST_MODE  = 0;
 #endif

   VDC3.GROPBASERGB1.BIT.BASE_R    = 0;
   VDC3.GROPBASERGB1.BIT.BASE_G    = 0;
   VDC3.GROPBASERGB1.BIT.BASE_B    = 0;
 #ifdef GFX_DRIVER_CHROMA_KEY_RGB565_COLOR
   VDC3.GROPCRKY0_1.BIT.CROMAKR    = ((GFX_DRIVER_CHROMA_KEY_RGB565_COLOR >>11) & 0x1F);
   VDC3.GROPCRKY0_1.BIT.CROMAKG    = ((GFX_DRIVER_CHROMA_KEY_RGB565_COLOR >> 5) & 0x1F);
   VDC3.GROPCRKY0_1.BIT.CROMAKB    = (GFX_DRIVER_CHROMA_KEY_RGB565_COLOR        & 0x1F);
   VDC3.GROPCRKY1_1.BIT.ALPHA      = 0;
   VDC3.GROPCRKY1_1.BIT.R          = 0x1F;
   VDC3.GROPCRKY1_1.BIT.G          = 0x3F;
   VDC3.GROPCRKY1_1.BIT.B          = 0x1F;
   VDC3.GROPCRKY0_1.BIT.CKEN       = 1;
 #endif
   VDC3.GROPEDPA1.BIT.DEFA         = 0;
   VDC3.GROPEDPA1.BIT.ACOEF        = 0;
   VDC3.GROPEDPA1.BIT.ARATE        = 0;
   VDC3.GROPEDPA1.BIT.AMOD         = 0;
   VDC3.GROPEDPA1.BIT.AEN          = 0;
   VDC3.SGMODE.BIT.EX_SYNC_MODE    = 0;

   /*
   ** Update all the settings
   */
   VDC3.GRCMEN1.BIT.DEN            = 1;
   VDC3.GRCMEN1.BIT.VEN            = 0;
   VDC3.GRCMEN1.BIT.WE             = 1;
   VDC3.GROPEDPA1.BIT.WE           = 1;
 #if NB_LAYERS > 1
   VDC3.GRCMEN2.BIT.VEN            = 1;
   VDC3.GRCMEN2.BIT.DEN            = 1;
 #else
   VDC3.GRCMEN2.BIT.VEN            = 1;
 #endif
   VDC3.GRCMEN2.BIT.WE             = 1;

 #if GFX_DRIVER_ENABLE_VIDEO_IN != 0
   /*
   ** Initialize the Video In.
   */
   VDC3.VIDEO_SIZE.LONG          = 0x010702D0;  // VIDEO_HEIGHT=240, VIDEO_WIDTH=720
   VDC3.VIDEO_VSTART.LONG        = 0x0001011A;  // 0x0013011A  VIDEO_VSTART_TOP=19, VIDEO_VSTART_BTM=282
   VDC3.VIDEO_HSTART.LONG        = 0x00000114;  // VIDEO_HSTART=276
   VDC3.VIDEO_VSYNC_TIM1.LONG    = 0x0048014F;  // VIDEO_VSYNC_START1_TOP=22, VIDEO_VSYNC_START1_BTM=285
   VDC3.VIDEO_VSYNC_TIM2.LONG    = 0x30;
   VDC3.VIDEO_SAVE_NUM.LONG      = 0x00000000;  // FIELD_SAVE_NUM=1
   VDC3.VIDEO_IMAGE_CNT.LONG     = 0x80800302;  // SCALE_V=11,SUBU_SCALE_V=1 ~51.4 (x2 for full) 
   VDC3.VIDEO_BASEADR.LONG       = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
   VDC3.VIDEO_LINE_OFFSET.LONG   = 0x3C0;
   VDC3.VIDEO_FIELD_OFFSET.LONG  = 0x17A20;
   VDC3.VIDEO_LINEBUFF_NUM.LONG  = 0x107;        // number of video line buffer
   VDC3.VIDEO_DISP_SIZE.LONG     = 0x010701E0;  // VIDEO_DISP_HEIGHT=240, VIDEO_DISP_WIDTH=480
   VDC3.VIDEO_DISP_HSTART.LONG   = 0x25;        // Horizontal position

   VDC3.VIDEO_INT_CNT.BIT.INT_V_EN     = 1;
   VDC3.VIDEO_INT_CNT.BIT.V_PERIOD     = 0;
   VDC3.VIDEO_INT_CNT.BIT.F_END        = 0;
   VDC3.VIDEO_INT_CNT.BIT.INT_F_EN     = 1;

 #endif
}
#endif

#ifndef WIN32
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverInitialize(void)
{
   GFX_COLOR_T           fl_fill_color_U16 = 0;
   GFX_DRV_ENV_INFO      fl_drv_context_S;
#if NB_LAYERS > 1
   UINT8                 fl_lid_U8;
#endif
   /*
   ** Initialize the local variables to default values.
   */
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   l_fade_effect_mode_U8             = GFX_FADE_EFFECT_INACTIVE;
   l_fade_effect_id_U8               = 0;
 #endif

   fl_drv_context_S.fb_P      = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
   fl_drv_context_S.fb_w      = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
   fl_drv_context_S.fb_h      = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
   fl_drv_context_S.fb_format = lc_layer_table_S[GFX_DRIVER_LAYER_0].pix_format;
   GfxDriverSetEnv(&fl_drv_context_S);
#if NB_LAYERS > 1
   l_working_layer_data_SP         = &l_layer_data_S[GFX_DRIVER_LAYER_0];
#endif
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_open          = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_active        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_update        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied     = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 0;

 #if NB_LAYERS > 1
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_open          = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_active        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_update        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied     = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index = 0;
 #endif
   
   /* DMAOR is not set during the GfxBuildFillScreen() routine and DMA transfer was initiated
   because of which we got a COP fail. Hence initializing this DMAOR here so that BuildFillScreen
   DMA transfer will not fail 
   KernelUpdateWatchdog() is called here to makesure that we don't get a watchdog reset because of
   a memset() call.
   Timing measurement done for memset seems to take 3.0mSec whereas for a DMA transfer it took
   7.3mSec for a single framebuffer intialization 
   VMUTHUSU - 19May2011 */

   DMAC.DMAOR.WORD  |= 1;
   KernelUpdateWatchdog();
   memset(&l_l0_fb1_U8A[0],0x00,0x3FC00);
   KernelUpdateWatchdog();
   memset(&l_l0_fb2_U8A[1],0x00,0x3FC00);

   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x = (PANEL_HBACK_PORCH-16) + GFX_DRIVER_LCD_X_OFFSET; 
   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y = (PANEL_HBACK_PORCH-1)  + GFX_DRIVER_LCD_Y_OFFSET; 

 #if (NB_LAYERS > 1)  && (GFX_DRIVER_DEVICE_VARIENT != GFX_DRV_7262L)
   DMAC.CHCR0.BIT.DE = 0;
   DMAC.SAR0.LONG    = (UINT32)&fl_fill_color_U16;
   DMAC.DAR0.LONG    = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
   DMAC.DMATCR0.LONG = (GFX_L1_MAX_W_LENGTH*GFX_L1_MAX_H_LENGTH);
   DMAC.CHCR0.LONG   = 0x80004408;
   DMAC.CHCR0.BIT.DE = 1;
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x  = (PANEL_HBACK_PORCH-16) + GFX_DRIVER_LCD_X_OFFSET; 
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x += ((GFX_L0_MAX_W_LENGTH-GFX_L1_MAX_W_LENGTH)/2);
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y  = (PANEL_HBACK_PORCH-1)  + GFX_DRIVER_LCD_Y_OFFSET; 
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y += ((GFX_L0_MAX_H_LENGTH-GFX_L1_MAX_H_LENGTH)/2);
   while(DMAC.CHCR0.BIT.TE == 0);

   /*Initialize the another frame buffer for issue fix BSDI00095277 - Abnormal Behaviour(Some white color screen)
   in MFD when doing battery cycle*/
   DMAC.CHCR0.BIT.DE = 0;
   DMAC.SAR0.LONG    = (UINT32)&fl_fill_color_U16;
   DMAC.DAR0.LONG    = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
   DMAC.DMATCR0.LONG = (GFX_L1_MAX_W_LENGTH*GFX_L1_MAX_H_LENGTH);
   DMAC.CHCR0.LONG   = 0x80004408;
   DMAC.CHCR0.BIT.DE = 1;   
   while(DMAC.CHCR0.BIT.TE == 0);
 #endif
}
#else /*#ifndef WIN32*/
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverInitialize(void)
{
   GFX_DRV_ENV_INFO fl_drv_context_S;
   /*
   ** Initialize the local variables to default values.
   */
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   l_fade_effect_mode_U8             = GFX_FADE_EFFECT_INACTIVE;
   l_fade_effect_id_U8               = 0;
 #endif
#if NB_LAYERS > 1
   l_working_layer_data_SP           = &l_layer_data_S[GFX_DRIVER_LAYER_0];
#endif
   fl_drv_context_S.fb_P      = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
   fl_drv_context_S.fb_w      = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
   fl_drv_context_S.fb_h      = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
   fl_drv_context_S.fb_format = lc_layer_table_S[GFX_DRIVER_LAYER_0].pix_format;
   GfxDriverSetEnv(&fl_drv_context_S);

   l_layer_data_S[GFX_DRIVER_LAYER_0].b_open          = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_active        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_update        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied     = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 0;

 #if NB_LAYERS > 1
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_open          = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_active        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_update        = FALSE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied     = TRUE;
   l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index = 0;
 #endif

   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x = 0; 
   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y = 0; 
 #if NB_LAYERS > 1
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x = (GFX_L0_MAX_W_LENGTH-GFX_L1_MAX_W_LENGTH)>>1; 
   lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y = (GFX_L0_MAX_H_LENGTH-GFX_L1_MAX_H_LENGTH)>>1; 
 #endif
   l_win1_handle = gls_add_layer(255, GFX_MAX_W_LENGTH, GFX_MAX_H_LENGTH);
   gls_main_loop(hmi_simulation_1mSec_tick);
}
#endif


#if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverSetFadeEffect(UINT8 fl_fade_id_U8)
{
   if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ACTIVE)
   {
      /*** Abort the fade effect if the fade effect is ongoing*/
      l_fade_effect_mode_U8 = GFX_FADE_EFFECT_ABORT;
      while(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ABORT);
   }
   if(fl_fade_id_U8 < NB_FADE_EFFECT_CONFIG)
   {
      l_fade_effect_mode_U8 = GFX_FADE_EFFECT_REQUESTED;
      l_fade_effect_id_U8   = fl_fade_id_U8;
   }
   else
   {
      l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
   }

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
UINT8 GfxDriverIsFadeEffectInProgress(void)
{
   if((l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE)||(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_REQUESTED))
   {
      return(FALSE);
   }
   else
   {
      return(TRUE);
   }
}
#endif /*#if GFX_DRIVER_ENABLE_FADE_EFFECT > 0*/

/****************************************************************************
Function Name        : void GfxDriverBeginUpdate(UINT8 p_lid_U8){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
void GfxDriverBeginUpdate(UINT8 p_lid_U8)
#else
void GfxDriverBeginUpdate(void)
#endif
{
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   RECTANGLE_DEF_T fl_clip_area_SP;
#endif
   GFX_DRV_ENV_INFO fl_drv_context_S;

#if NB_LAYERS > 1
   l_working_layer_data_SP           = &l_layer_data_S[p_lid_U8];
#endif
   l_working_layer_data_SP->b_update = TRUE;

   fl_drv_context_S.fb_P      = l_layer_fb_pointer_table[p_lid_U8][l_working_layer_data_SP->b_work_fb_index];
   fl_drv_context_S.fb_w      = lc_layer_table_S[p_lid_U8].width;
   fl_drv_context_S.fb_h      = lc_layer_table_S[p_lid_U8].height;
   fl_drv_context_S.fb_format = lc_layer_table_S[p_lid_U8].pix_format;

   GfxDriverSetEnv(&fl_drv_context_S);

#ifdef ENABLE_FPS_CALCULATION
   fps_start_count = fps_base_count;
#endif

#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   fl_clip_area_SP.x = 0;
   fl_clip_area_SP.y = 0;
 #if NB_LAYERS > 1
   fl_clip_area_SP.w = lc_layer_table_S[p_lid_U8].width;;
   fl_clip_area_SP.h = lc_layer_table_S[p_lid_U8].height;;
 #else
   fl_clip_area_SP.w = lc_layer_table_S[0].width;;
   fl_clip_area_SP.h = lc_layer_table_S[0].height;;
 #endif
   GfxDriverSetClipArea(&fl_clip_area_SP);
#endif
}
/****************************************************************************
Function Name        : UINT8 GfxDriverCheckBusyStatus(UINT8 p_lid_U8){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
UINT8 GfxDriverCheckBusyStatus(UINT8 p_lid_U8)
#else
UINT8 GfxDriverCheckBusyStatus(void)
#endif
{
#ifndef WIN32
   UINT8 fl_driver_busy_BOOL = TRUE;
   /*
   ** Layer 0 cannot be refreshed while video is streaming or if the 
   ** Fade effect is in progress. because we are sharing the RAM.
   */
   if((p_lid_U8 != 0) || (VDC3.VIDEO_MODE.BIT.VIDEO_MAIN_EXE == 0))
   {
    #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
      if((l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE)  || 
         (l_fade_effect_mode_U8 == GFX_FADE_EFFECT_REQUESTED)    )
    #endif
      {
       #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
         if((p_lid_U8 == 0) && (l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied == FALSE))
         {
            /* 
            ** If fade in was active earlier and just finished now, we wouldn't have copied
            ** the current buffer to back buffer. So initiate DMA transfer of current buffer
            ** to working buffer
            */
            DMAC.CHCR0.BIT.DE = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 1;
            }
            else
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 0;
            }
            DMAC.DMATCR0.LONG = (lc_layer_table_S[GFX_DRIVER_LAYER_0].width*lc_layer_table_S[GFX_DRIVER_LAYER_0].height);
            DMAC.CHCR0.LONG   = 0x80005408;
            DMAC.CHCR0.BIT.DE = 1;
            l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = TRUE;
            while(DMAC.CHCR0.BIT.TE == 0);
         }
       #if NB_LAYERS > 1
         else if((p_lid_U8 == 1) && (l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied == FALSE))
         {
            /* 
            ** If fade in was active earlier and just finished now, we wouldn't have copied
            ** the current buffer to back buffer. So initiate DMA transfer of current buffer
            ** to working buffer
            */
            DMAC.CHCR0.BIT.DE = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index == 0)
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
               l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index = 1;
            }
            else
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
               l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index = 0;
            }
            DMAC.DMATCR0.LONG = (lc_layer_table_S[GFX_DRIVER_LAYER_1].width*lc_layer_table_S[GFX_DRIVER_LAYER_1].height);
            DMAC.CHCR0.LONG   = 0x80005408;
            DMAC.CHCR0.BIT.DE = 1;
            l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied = TRUE;
            while(DMAC.CHCR0.BIT.TE == 0);
         }
         else
         {
         }
       #endif /*#if NB_LAYERS > 1*/
       #endif /*#if GFX_DRIVER_ENABLE_FADE_EFFECT > 0*/
         fl_driver_busy_BOOL               = FALSE;
      }
   }
   return(fl_driver_busy_BOOL);
#else
   UINT8 fl_driver_busy_BOOL;
   if((l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE) || (l_fade_effect_mode_U8 == GFX_FADE_EFFECT_REQUESTED))
   {
      GFX_DRV_ENV_INFO fl_drv_context_S;
      if(l_working_layer_data_SP->b_fb_copied == FALSE)
      {
         memcpy((void *)l_layer_fb_pointer_table[p_lid_U8][(l_working_layer_data_SP->b_work_fb_index+1) & 0x01],
                (void *)l_layer_fb_pointer_table[p_lid_U8][l_working_layer_data_SP->b_work_fb_index],
                (lc_layer_table_S[p_lid_U8].width*lc_layer_table_S[p_lid_U8].height*2));
         l_working_layer_data_SP->b_work_fb_index++;
      }
      l_working_layer_data_SP->b_update = TRUE;
      fl_driver_busy_BOOL               = FALSE;
      fl_drv_context_S.fb_P             = l_layer_fb_pointer_table[p_lid_U8][l_working_layer_data_SP->b_work_fb_index];
      fl_drv_context_S.fb_w             = lc_layer_table_S[p_lid_U8].width;
      fl_drv_context_S.fb_h             = lc_layer_table_S[p_lid_U8].height;
      fl_drv_context_S.fb_format        = lc_layer_table_S[p_lid_U8].pix_format;
      GfxDriverSetEnv(&fl_drv_context_S);
   }
   else
   {
      fl_driver_busy_BOOL = TRUE;
   }
   return(fl_driver_busy_BOOL);
#endif
}

/****************************************************************************
Function Name        : void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
void GfxDriverEndUpdate(UINT8 p_active_layers_U8, UINT8 p_post_copy_flag_U8)
#else
void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8)
#endif
{
#ifndef WIN32
 #ifdef ENABLE_FPS_CALCULATION
   GfxDriverUpdateFps();
 #endif
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_REQUESTED)
   {
      if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
      {
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied  = FALSE;
         VDC3.GROPEDPHV2.BIT.GROPEDPH   = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x;
         VDC3.GROPEDPHV2.BIT.GROPEDPV   = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y;
         VDC3.GROPEWH2.BIT.GROPEW       = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
         VDC3.GROPSWH2.BIT.GROPSW       = lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
         VDC3.GROPEWH2.BIT.GROPEH       = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
         VDC3.GROPSWH2.BIT.GROPSH       = lc_layer_table_S[GFX_DRIVER_LAYER_0].height;
         VDC3.GROPDPHV2.BIT.GROPDPV     = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y;
         VDC3.GROPDPHV2.BIT.GROPDPH     = lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x;
         VDC3.GROPSOFST2.BIT.GROPSOFST  = GFX_L0_MAX_W_LENGTH * 2;
         VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = VDC3.GRCBUSCNT1.BIT.BUS_FORMAT;

         VDC3.GROPEDPA2.BIT.DEFA        =  l_fade_data[l_fade_effect_id_U8].InitialAlpha;  /* initial alpha */
         VDC3.GROPEDPA2.BIT.ACOEF       = l_fade_data[l_fade_effect_id_U8].CoefAddSub;/* Value to Add or Subtract */
         VDC3.GROPEDPA2.BIT.ARATE       = l_fade_data[l_fade_effect_id_U8].FrameRate;
         VDC3.GROPEDPA2.BIT.AMOD        = l_fade_data[l_fade_effect_id_U8].Fade_in_out;  /* 1 add, 2 subtract */
         VDC3.GROPEDPA2.BIT.AEN         = 1;/* 1: Alpha Control Feature Enabled, 0: Disbaled*/
         VDC3.GROPSADR2.BIT.GROPSADR    = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
         VDC3.GRCMEN2.BIT.DEN           = 1; /* Layer 2 emable */
         VDC3.GROPEDPA2.BIT.WE          = 1;
         VDC3.GRCMEN2.BIT.WE            = 1;
         while(VDC3.GRCMEN2.BIT.WE);
         l_fade_effect_mode_U8          = GFX_FADE_EFFECT_ACTIVE;
         if(VDC3.SGINTCNT.BIT.LINE_STATUS != 0)
         {
            VDC3.SGINTCNT.BIT.LINE_STATUS = 0;
         }
         VDC3.SGINTCNT.BIT.INT_LINE_EN  = 1;
      }
    #if NB_LAYERS > 1
      if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
      {
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = FALSE;
      }
    #endif
   }
   else if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE)
 #endif
   {
      if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
      {
         VDC3.GROPSADR1.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
         VDC3.GRCMEN1.LONG   = 0x80000002;
      }
    #if NB_LAYERS > 1
      if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
      {
         VDC3.GROPSADR2.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index];
         VDC3.GRCMEN2.LONG   = 0x80000003;
      }
      else if((p_active_layers_U8 & 0x02) == 0)
      {
         VDC3.GRCMEN2.LONG   = 0x80000001;
      }
      else
      {
      }
    #endif
      /* 
      ** Swap the working buffer 
      */
      if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
      {
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index++;
         if((p_post_copy_flag_U8 & (1<<GFX_DRIVER_LAYER_0)) != 0)
         {
            DMAC.CHCR0.BIT.DE = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
            }
            else
            {
               DMAC.DAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               DMAC.SAR0.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
            }
            DMAC.DMATCR0.LONG = (lc_layer_table_S[GFX_DRIVER_LAYER_0].width*lc_layer_table_S[GFX_DRIVER_LAYER_0].height);
            DMAC.CHCR0.LONG   = 0x80005408;
         }
      }
   #if NB_LAYERS > 1
      if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
      {
         l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index++;
         if((p_post_copy_flag_U8 & (1<<GFX_DRIVER_LAYER_1)) != 0)
         {
            DMAC.CHCR1.BIT.DE = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index == 0)
            {
               DMAC.DAR1.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
               DMAC.SAR1.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
            }
            else
            {
               DMAC.DAR1.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
               DMAC.SAR1.LONG = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
            }
            DMAC.DMATCR1.LONG = (lc_layer_table_S[GFX_DRIVER_LAYER_1].width*lc_layer_table_S[GFX_DRIVER_LAYER_1].height);
            DMAC.CHCR1.LONG   = 0x80005408;
         }
      }
   #endif
      while((VDC3.GRCMEN1.BIT.WE != 0) || (VDC3.GRCMEN2.BIT.WE != 0));
      if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
      {
         /* 
         ** Initiate DMA transfer of current buffer to working buffer 
         */
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_update = FALSE;
         if((p_post_copy_flag_U8 & (1<<GFX_DRIVER_LAYER_0)) != 0)
         {
            DMAC.CHCR0.BIT.DE = 1;
            while(DMAC.CHCR0.BIT.TE == 0);
         }
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = TRUE;
      }
    #if NB_LAYERS > 1
      if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
      {
         /* 
         ** Initiate DMA transfer of current buffer to working buffer 
         */
         l_layer_data_S[GFX_DRIVER_LAYER_1].b_update = FALSE;
         if((p_post_copy_flag_U8 & (1<<GFX_DRIVER_LAYER_1)) != 0)
         {
            DMAC.CHCR1.BIT.DE = 1;
            while(DMAC.CHCR1.BIT.TE == 0);
         }
         l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied = TRUE;
      }
    #endif
   }
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   else
   {
   }
 #endif
#else
   int x, y;
   if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
   {
      memcpy((void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index+1) & 0x01],
             (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index],
             (lc_layer_table_S[GFX_DRIVER_LAYER_0].width*lc_layer_table_S[GFX_DRIVER_LAYER_0].height*sizeof(GFX_COLOR_T)));
      l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = TRUE;
      l_layer_data_S[GFX_DRIVER_LAYER_0].b_update    = FALSE;
      l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index++;
   }
#if NB_LAYERS > 1
   if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
   {
      memcpy((void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][(l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index+1) & 0x01],
             (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index],
             (GFX_L1_MAX_W_LENGTH*GFX_L1_MAX_H_LENGTH*sizeof(GFX_COLOR_T)));
      l_layer_data_S[GFX_DRIVER_LAYER_1].b_fb_copied = TRUE;
      l_layer_data_S[GFX_DRIVER_LAYER_1].b_update    = FALSE;
      l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index++;
   }
#endif
   for(y=0; y < GFX_MAX_H_LENGTH; y++)
   {
      for(x=0; x < GFX_MAX_W_LENGTH; x++)
      {
         unsigned r;
         unsigned g;
         unsigned b;
         unsigned c;
         GFX_COLOR_T * fb = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];

         fb += (y*GFX_MAX_W_LENGTH)+x;

      #ifdef GFX_R_AND_B_ENCODED_WITH_BIT_5_TO_1
         b = (*fb & 0x1F)<<1;b++;
         g = (*fb>>5) & 0x3F;
         r = ((*fb>>11) & 0x1F)<<1;r++;

         b   = ((b*255)/63);
         g   = ((g*255)/63);
         r   = ((r*255)/63);

         c   = b;
         c <<= 8;
         c  += g;
         c <<= 8;
         c  += r;
      #else
         b = (*fb & 0x1F);
         g = (*fb>>5) & 0x3F;
         r = ((*fb>>11) & 0x1F);

         b = ((b*255)/31);
         g = ((g*255)/63);
         r = ((r*255)/31);

         c   = b;
         c <<= 8;
         c  += g;
         c <<= 8;
         c  += r;
      #endif
      #if NB_LAYERS > 1
         if((x >= lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x) && (y >= lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y))
         {
            unsigned x1 = x - lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
            unsigned y1 = y - lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
            if((x1 < lc_layer_table_S[GFX_DRIVER_LAYER_1].width) && (y1 < lc_layer_table_S[GFX_DRIVER_LAYER_1].height))
            {
            unsigned a1;
            unsigned r1;
            unsigned g1;
            unsigned b1;
            unsigned c1;
            
            GFX_COLOR_T * fb1 = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];

            fb1 += (y1*lc_layer_table_S[GFX_DRIVER_LAYER_1].width)+x1;

            if(lc_layer_table_S[GFX_DRIVER_LAYER_1].pix_format == GFX_ARGB4444)
            {
               a1   = *fb1;
               b1   = (a1 & 0x0F)*17;
               a1 >>=4;
               g1   = (a1 & 0x0F)*17;
               a1 >>=4;
               r1   = (a1 & 0x0F)*17;
               a1 >>=4;
               a1   = (a1 & 0x0F)*17;
            }
            else
            {
            #ifdef GFX_R_AND_B_ENCODED_WITH_BIT_5_TO_1
               b1 = (*fb1 & 0x1F)<<1;b1++;
               g1 = (*fb1>>5) & 0x3F;
               r1 = ((*fb1>>11) & 0x1F)<<1;r1++;
               b1 = ((b1*255)/63);
               g1 = ((g1*255)/63);
               r1 = ((r1*255)/63);
            #else
               b1 = (*fb1 & 0x1F);
               g1 = (*fb1>>5) & 0x3F;
               r1 = ((*fb1>>11) & 0x1F);
               b1 = ((b1*255)/31);
               g1 = ((g1*255)/63);
               r1 = ((r1*255)/31);
            #endif
               a1 = 255;
            }
            if(a1 > 0 && a1 < 255)
            {
               /* Blend */
               if(r1 > r)
               {
                  r1   = (((r << 8) + (a1 * (r1 - r))) >> 8);
               }
               else
               {
                  r1   = (((r << 8) - (a1 * (r - r1))) >> 8);
               }
               if(g1 > g)
               {
                  g1   = (((g << 8) + (a1 * (g1 - g))) >> 8);
               }
               else
               {
                  g1   = (((g << 8) - (a1 * (g - g1))) >> 8);
               }
               if(r1 > r)
               {
                  b1   = (((b << 8) + (a1 * (b1 - b))) >> 8);
               }
               else
               {
                  b1   = (((b << 8) - (a1 * (b - b1))) >> 8);
               }
            }
            if(a1 > 0)
            {
               c  = r1 + (g1 << 8) + (b1 << 16);
            }
            }
         }
      #endif
         gls_fb_write_xy(l_win1_handle, x, y, c);
      }
   }
   gls_update_lcd();
#endif
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
void GfxDriverVSyncISR(void)
{
#ifndef WIN32
   if(VDC3.SGINTCNT.BIT.LINE_STATUS != 0)
   {
      VDC3.SGINTCNT.BIT.LINE_STATUS = 0;
    #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
      if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ACTIVE)
      {
         if(VDC3.GROPEDPA2.BIT.AST == 0)
         {
            VDC3.GROPSADR1.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
          #if NB_LAYERS > 1
            VDC3.GROPEDPHV2.BIT.GROPEDPH  = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
            VDC3.GROPEDPHV2.BIT.GROPEDPV  = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
            VDC3.GROPSWH2.BIT.GROPSW      = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
            VDC3.GROPEWH2.BIT.GROPEW      = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
            VDC3.GROPSWH2.BIT.GROPSH      = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
            VDC3.GROPEWH2.BIT.GROPEH      = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
            VDC3.GROPDPHV2.BIT.GROPDPV    = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
            VDC3.GROPDPHV2.BIT.GROPDPH    = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
            VDC3.GROPSOFST2.BIT.GROPSOFST = GFX_L1_MAX_W_LENGTH * 2;
            VDC3.GROPEWH2.LONG            = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index == 0)
            {
               VDC3.GROPSADR2.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
            }
            else
            {
               VDC3.GROPSADR2.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
            }
            if(lc_layer_table_S[GFX_DRIVER_LAYER_1].pix_format == GFX_ARGB4444)
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = 1;
            }
            else
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = 0;
            }
            VDC3.GRCMEN2.LONG = 0x80000003; /* Enable layer 2 */
          #else
            VDC3.GRCMEN2.LONG = 0x80000001; /* disable layer 2 */
          #endif
            VDC3.GRCMEN1.LONG     = 0x80000002;
            l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
            VDC3.SGINTCNT.BIT.INT_LINE_EN = 0;
         }
      }
      else if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ABORT)
      {
         if(VDC3.GRCMEN2.BIT.DEN != 0)
         {
            VDC3.GROPEDPA1.BIT.AEN = 0;
            VDC3.GROPSADR1.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
          #if NB_LAYERS > 1
            VDC3.GROPEDPHV2.BIT.GROPEDPH  = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
            VDC3.GROPEDPHV2.BIT.GROPEDPV  = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
            VDC3.GROPSWH2.BIT.GROPSW      = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
            VDC3.GROPEWH2.BIT.GROPEW      = lc_layer_table_S[GFX_DRIVER_LAYER_1].width;
            VDC3.GROPSWH2.BIT.GROPSH      = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
            VDC3.GROPEWH2.BIT.GROPEH      = lc_layer_table_S[GFX_DRIVER_LAYER_1].height;
            VDC3.GROPDPHV2.BIT.GROPDPV    = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->y;
            VDC3.GROPDPHV2.BIT.GROPDPH    = lc_layer_table_S[GFX_DRIVER_LAYER_1].coord_ptr->x;
            VDC3.GROPSOFST2.BIT.GROPSOFST = GFX_L1_MAX_W_LENGTH * 2;
            VDC3.GROPEWH2.LONG            = 0;
            if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)
            {
               VDC3.GROPSADR1.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_1];
            }
            else
            {
               VDC3.GROPSADR1.LONG = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_1][GFX_DRIVER_FB_0];
            }
            if(lc_layer_table_S[GFX_DRIVER_LAYER_1].pix_format == GFX_ARGB4444)
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = 1;
            }
            else
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = 0;
            }
            VDC3.GRCMEN2.LONG = 0x80000003; /* Enable layer 2 */
          #else
            VDC3.GRCMEN2.LONG = 0x80000001; /* disable layer 2 */
          #endif
            VDC3.GRCMEN1.LONG     = 0x80000002;
         }
         l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
         VDC3.SGINTCNT.BIT.INT_LINE_EN  = 0;
      }
      else
    #endif
   #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
      {
      }
   #endif
   }
#else
   if((l_fade_alpha_U8 != 255) && (l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ACTIVE))
   {
      l_fade_alpha_U8 += 10;
      if(l_fade_alpha_U8 >= 255)
      {
         l_fade_alpha_U8       = 255;
         l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
      }
      {
         int x, y;
         for(y=0; y < GFX_MAX_H_LENGTH; y++)
         {
            for(x=0; x < GFX_MAX_W_LENGTH; x++)
            {
               unsigned r0, r1;
               unsigned g0, g1;
               unsigned b0, b1, c;
               GFX_COLOR_T * fb0 = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
               GFX_COLOR_T * fb1 = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index+1)&0x01];
               fb0 += (y*GFX_MAX_W_LENGTH)+x;
               fb1 += (y*GFX_MAX_W_LENGTH)+x;
               b0 = *fb0 & 0x1F;
               g0 = (*fb0>>5) & 0x3F;
               r0 = (*fb0>>11) & 0x1F;
               b1 = *fb1 & 0x1F;
               g1 = (*fb1>>5) & 0x3F;
               r1 = (*fb1>>11) & 0x1F;
               /* Blend */
               if(r0 > r1)
               {
                  r0 = (((r1 << 8) + (l_fade_alpha_U8 * (r0 - r1))) >> 8);
               }
               else
               {
                  r0 = (((r1 << 8) - (l_fade_alpha_U8 * (r1 - r0))) >> 8);
               }
               if(g0 > g1)
               {
                  g0 = (((g1 << 8) + (l_fade_alpha_U8 * (g0 - g1))) >> 8);
               }
               else
               {
                  g0 = (((g1 << 8) - (l_fade_alpha_U8 * (g1 - g0))) >> 8);
               }
               if(b0 > b1)
               {
                  b0 = (((b1 << 8) + (l_fade_alpha_U8 * (b0 - b1))) >> 8);
               }
               else
               {
                  b0 = (((b1 << 8) - (l_fade_alpha_U8 * (b1 - b0))) >> 8);
               }
               c = ((b0*255)/31);
               c <<= 8;
               c+= ((g0*255)/63);
               c <<= 8;
               c+= ((r0*255)/31);
               gls_fb_write_xy(l_win1_handle, x, y, c);
            }
         }
         gls_update_lcd();
      }
   }
#endif
}

#ifdef ENABLE_FPS_CALCULATION
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverFpsText(GFX_SIZE_X_T fl_start_x, GFX_SIZE_Y_T fl_start_y, UINT8 * fl_disp_string_P)
{
   GFX_SIZE_X_T    fl_x_size;
   GFX_SIZE_X_T    fl_rem_x_size;
   GFX_SIZE_Y_T    fl_y_size;
   UINT8           fl_font_data;
   UINT8           fl_aa_data;
   UINT8           fl_pix_in_byte_count;
   GFX_SIZE_X_T    fl_cur_x;
   GFX_SIZE_Y_T    fl_cur_y;
   UINT8 const   * fl_font_data_P;
   GFX_COLOR_T   * fl_cur_frame_buff_P;
   GFX_COLOR_T   * fl_frame_buff_P;
   GUI_FONT_PROP const * fl_font_search_table_P;
   GUI_FONT const* fl_font_P = &GUI_FontB2YY12;

   while(*fl_disp_string_P != 0)
   {
      fl_font_search_table_P = fl_font_P->p.pProp;

      while(fl_font_search_table_P != 0)
      {
         if((*fl_disp_string_P >= fl_font_search_table_P->First) && \
            (*fl_disp_string_P <= fl_font_search_table_P->Last)     )
         {
            fl_font_data_P         = (&fl_font_search_table_P->paCharInfo[(*fl_disp_string_P - fl_font_search_table_P->First)])->pData;
            fl_x_size              = fl_font_search_table_P->paCharInfo[(*fl_disp_string_P - fl_font_search_table_P->First)].XSize;
            fl_y_size              = fl_font_P->YSize;
            fl_cur_y               = fl_start_y;
            fl_frame_buff_P        = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
            fl_frame_buff_P       += ((fl_cur_y * lc_layer_table_S[GFX_DRIVER_LAYER_0].width)+fl_start_x);
            while(fl_y_size)
            {
               fl_cur_x            = fl_start_x;
               fl_rem_x_size       = fl_x_size;
               fl_cur_frame_buff_P = fl_frame_buff_P;

               while(fl_rem_x_size)
               {
                  fl_font_data = *fl_font_data_P;
                  if(fl_rem_x_size > 8)
                  {
                     fl_pix_in_byte_count = 8;
                     fl_rem_x_size       -= 8;
                  }
                  else
                  {
                     fl_pix_in_byte_count = fl_rem_x_size;
                     fl_rem_x_size        = 0;
                  }
                  while(fl_pix_in_byte_count)
                  {
                     fl_pix_in_byte_count--;
                     if(fl_font_data & 0x80)
                     {
                        *fl_cur_frame_buff_P = 0xFFFF;
                     }
                     else
                     {
                        *fl_cur_frame_buff_P = 0;
                     }
                     fl_font_data <<= 1;
                     fl_cur_x++;
                     fl_cur_frame_buff_P++;
                  }
                  fl_font_data_P++;
               }
               fl_cur_y++;
               fl_y_size--;
               fl_frame_buff_P += lc_layer_table_S[GFX_DRIVER_LAYER_0].width;
            }
            fl_start_x             = fl_cur_x;
            fl_font_search_table_P = 0;
         }
         else
         {
            fl_font_search_table_P = fl_font_search_table_P->pNext;
         }
      }
      fl_disp_string_P++;
   }
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
static void GfxDriverUpdateFps(void)
{
   unsigned char fl_disp_buff[30];
   fps_end_count  = fps_base_count;
   fps_end_count -= fps_start_count;

#if PROD_SPEC_SCHEDULER_ISR_RATE == 2
   fps_end_count <<= 1;
#elif PROD_SPEC_SCHEDULER_ISR_RATE == 4
   fps_end_count <<= 2;
#else
   #error "error in fps"
#endif

   if(fps_end_count > fps_longest_count)
   {
     fps_longest_count = fps_end_count;
   }

   fl_disp_buff[0]  = '[';
   fl_disp_buff[1]  = 'C';
   fl_disp_buff[2]  = 'u';
   fl_disp_buff[3]  = 'r';
   fl_disp_buff[4]  = ' ';
   fl_disp_buff[5]  = '0'+((fps_end_count/1000)%10);
   fl_disp_buff[6]  = '0'+((fps_end_count/100)%10);
   fl_disp_buff[7]  = '0'+((fps_end_count/10)%10);
   fl_disp_buff[8]  = '0'+(fps_end_count%10);
   fl_disp_buff[9]  = ' ';
   fl_disp_buff[10]  = 'm';
   fl_disp_buff[11] = 'S';
   fl_disp_buff[12] = 'e';
   fl_disp_buff[13] = 'c';
   fl_disp_buff[14] = ']';
   fl_disp_buff[15] = 0;
   GfxDriverFpsText(0, 210, (void *)fl_disp_buff);
   fl_disp_buff[1]  = 'M';
   fl_disp_buff[2]  = 'a';
   fl_disp_buff[3]  = 'x';
   fl_disp_buff[4]  = ' ';
   fl_disp_buff[5]  = '0'+((fps_longest_count/1000)%10);
   fl_disp_buff[6]  = '0'+((fps_longest_count/100)%10);
   fl_disp_buff[7]  = '0'+((fps_longest_count/10)%10);
   fl_disp_buff[8]  = '0'+(fps_longest_count%10);
/* array 9 to 15 taken care above*/
   GfxDriverFpsText(0, 225, (void *)fl_disp_buff);
}
#endif /*#ifdef ENABLE_FPS_CALCULATION*/

#if GFX_DRIVER_ENABLE_VIDEO_IN != 0
/****************************************************************************
Function Name        : 
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverDisableVideoInput(void)
{
#ifndef WIN32
   if(VDC3.VIDEO_MODE.BIT.VIDEO_MAIN_EXE != 0)
   {
      VDC3.GRCMEN1.LONG             = 0x80000002;
      VDC3.VIDEO_MODE.LONG          = 0x00;
   #if GFX_DRIVER_SYNC_WITH_VIDEO_IN > 0
      VDC3.SGMODE.BIT.EX_SYNC_MODE  = 0;
   #endif
   }
#endif
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
void GfxDriverEnableVideoInput(void)
{
#ifndef WIN32
   if(VDC3.VIDEO_MODE.BIT.VIDEO_MAIN_EXE == 0)
   {
   #if GFX_DRIVER_SYNC_WITH_VIDEO_IN > 0
      VDC3.SGMODE.BIT.EX_SYNC_MODE  = 1;
   #endif
      VDC3.VIDEO_BASEADR.LONG       = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
      VDC3.VIDEO_MODE.LONG          = 0x13;
      VDC3.GRCMEN1.LONG             = 0x80000003;
   }
#endif
}

/****************************************************************************/
/*
**  @brief      interrupt function from vector no.171
**
**              This function receives the interrupt from vector.
**
*/
void Gfx_api_interrupt_VISYNCJ(void)
{
  /*! check the V_PERIOD interrupt status                                 */
  if (VDC3.VIDEO_INT_CNT.BIT.INT_V_EN
      && VDC3.VIDEO_INT_CNT.BIT.V_PERIOD)
  {
      VDC3.VIDEO_INT_CNT.BIT.V_PERIOD     = 0;
  }
}
/****************************************************************************/
/*
**  @brief      interrupt function from vector no.173
**
**              This function receives the interrupt from vector.
**
*/
void Gfx_api_interrupt_VIFIELDE(void)
{
   /*! check the F_END interrupt status                                    */
   if (VDC3.VIDEO_INT_CNT.BIT.INT_F_EN
       && VDC3.VIDEO_INT_CNT.BIT.F_END)
   {
       VDC3.VIDEO_INT_CNT.BIT.F_END        = 0;
       if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)                                                                              
       {                                                                                                                                        
        l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index++;                                                                                   
       }                                                                                                                                        
       else                                                                                                                                     
       {                                                                                                                                        
        l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 0;                                                                                 
       }                                                                                                                                        
       VDC3.VIDEO_BASEADR.LONG       = (long)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];  
   }
}



#endif /*#if GFX_DRIVER_ENABLE_VIDEO_IN != 0*/

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
Date              : 24-NOV-10
By                : BSATHYAK
Traceability      : BSATHYAK_L538_D3P_BLD_1_DEP
Change Description: Update HW Port inits from L538 common_prn_init to driver
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 30-MAR-11
By                : VGANESHK
Traceability      : BSDI00095277 - Abnormal Behaviour(Some white color screen) 
                    in MFD when doing battery cycle
Change Description: Initialized both the frame buffers
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 05-APR-11
By                : EMANOJ1
Traceability      : SH7262 datasheet - Port G Ctrl Reg 7
Change Description: Initialized PGCR7 as per spec
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 27-APR-11
By                : CSAKTHIV
Traceability      : BSDI00102644
Change Description: Volume popup flicker issue due to fade.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 19-May-11
By                : VMUTHUSU
Traceability      : TBD
Change Description: CL260 failure due to DMA transfer. Changed to memset() for
                    framebuffer initialization. Only for Layer0 is done.
					Layer 1 needs to be fixed.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 08-June-11
By                : VMUTHUSU
Traceability      : MFD Blank issue during cold temperatures
Change Description: Added a new interface GfxDriverTFTInitialize(). This would
                    be called by the Operating Mode Manager once the Display
                    power enable is Turned ON  
-----------------------------------------------------------------------------*/
