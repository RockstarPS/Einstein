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
Description      :  Graphics Driver for the 640K varient
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

#include "iodefine.h"
#include "glib_dma.h"
#include "glib_lcd.h"
#include "rgs_api.h"
#include "system.h"
#include "sched.h"
#include "kernel.h"
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

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct
{
   UINT8    b_open          : 1;
   UINT8    b_active        : 1;
   UINT8    b_update        : 1;
   UINT8    b_fb_copied     : 1;
   UINT8    b_work_fb_index : 1;
}GFX_DRIVER_LAYER_DATA_T;

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
  static volatile UINT8 l_fade_effect_mode_U8;
  static          UINT8 l_fade_effect_id_U8;
#endif

static volatile UINT8 l_vsync_request_BOOL;

#if NB_LAYERS < 1
  #define p_lid_U8 (GFX_DRIVER_LAYER_0) 
#endif
#define l_working_layer_data_SP  (&l_layer_data_S[GFX_DRIVER_LAYER_0])

static GFX_DRIVER_LAYER_DATA_T   l_layer_data_S[NB_LAYERS];

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
   RGS_Display           display;
   RGS_GraphicsAttrList  graphics_attr;
   RGS_AttrChromaKey     attr_chroma_key;
   RGS_AttrAlpha         alpha_mode;
   T_DMAC_TRANS          fl_dma_tfr_S;
   GFX_COLOR_T           fl_fill_color_U16 = 0;
   GFX_DRV_ENV_INFO      fl_drv_context_S;
   /*
   ** Initialize the local variables to default values.
   */
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   l_fade_effect_mode_U8             = GFX_FADE_EFFECT_INACTIVE;
   l_fade_effect_id_U8               = 0;
 #endif
   l_vsync_request_BOOL              = FALSE;
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
   /*
   ** Initialize the Graphics Frame buffer memory
   */
   fl_dma_tfr_S.src_adr = (void *)&fl_fill_color_U16;
   fl_dma_tfr_S.dst_adr = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
   fl_dma_tfr_S.count   = (GFX_LAYER_0_MAX_W_LENGTH*GFX_LAYER_0_MAX_H_LENGTH);
   glib_Dmac_Trans_FixedSource(0, &fl_dma_tfr_S);
   /*
   ** Load the display offset values
   */
   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->x = GFX_DRIVER_LCD_X_OFFSET; 
   lc_layer_table_S[GFX_DRIVER_LAYER_0].coord_ptr->y = GFX_DRIVER_LCD_Y_OFFSET; 
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
   PORT.PGCR5.BIT.PG20MD           = 1;            /* LCD_EXTCLK           */
   PORT.PGCR5.BIT.PG21MD           = 0;
   PORT.PECR1.BIT.PE4MD            = 3;
   PORT.PECR1.BIT.PE5MD            = 3;
   PORT.PFCR2.BIT.PF8MD            = 3;
   PORT.PFCR0.WORD                 = 0x3333;       /* DV_DATA3-0           */
   PORT.PFCR1.WORD                 = 0x3333;       /* DV_DATA7-4           */
   PORT.PGCR7.BIT.PG0MD            = 1;            /* LCD_DATA00           */
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
   VDC3.SGINTCNT.BIT.INT_LINE_EN   = 1;
   VDC3.SGINTCNT.BIT.INT_LINE_NUM  = 0;
   INTC.IPR10.BIT._VDC3            = 10;
   CPG.STBCR7.BIT.MSTP74           = 0;
   /*
   ** LCD panel configuration
   */ 
   VDC3.GRA_VSYNC_TIM.BIT.GRA_VSYNC_START           = LCD_REFERENCE_VSYNC_GRAPHICS_OFFSET;
   VDC3.VIDEO_VSYNC_TIM1.BIT.VIDEO_VSYNC_START1_TOP = LCD_REFERENCE_VSYNC_VIDEO_TOP_OFFSET;
   VDC3.VIDEO_VSYNC_TIM1.BIT.VIDEO_VSYNC_START1_BTM = LCD_REFERENCE_VSYNC_VIDEO_BOTTOM_OFFSET;
   VDC3.SYNCNT.BIT.RGB_TIM                          = LCD_DATA_OUTPUT_TIMING;
   VDC3.SYNCNT.BIT.VSYNC_TIM                        = LCD_VSYNC_OUTPUT_TIMING; 
   VDC3.SYNCNT.BIT.HSYNC_TIM                        = LCD_HSYNC_OUTPUT_TIMING;
   VDC3.SYNCNT.BIT.DE_TIM                           = LCD_DATA_ENABLE_OUTPUT_TIMING;
   VDC3.SYNCNT.BIT.M_DISP_TIM                       = LCD_MODULATION_SIGNAL_TIMING;
   VDC3.SYNCNT.BIT.VSYNC_TYPE                       = LCD_IS_INVERTED_VSYNC_SIGNAL;
   VDC3.SYNCNT.BIT.HSYNC_TYPE                       = LCD_IS_INVERTED_HSYNC_SIGNAL;
   VDC3.SYNCNT.BIT.DE_TYPE                          = LCD_IS_INVERTED_DATA_OUTPUT_SIGNAL;
   VDC3.SYNCNT.BIT.M_DISP_TYPE                      = LCD_IS_INVERTED_MODULATION_SIGNAL;
   VDC3.PANEL_CLKSEL.BIT.ICKEN                      = 0;
   VDC3.PANEL_CLKSEL.BIT.ICKSEL                     = LCD_PANEL_CLOCKS;
   VDC3.PANEL_CLKSEL.BIT.DCDR                       = LCD_DCDR;
   VDC3.PANEL_CLKSEL.BIT.ICKEN                      = 1;
   VDC3.SYN_SIZE.BIT.SYN_HEIGHT                     = LCD_VERTICAL_TOTAL_LINE_NUMBER;
   VDC3.SYN_SIZE.BIT.SYN_WIDTH                      = LCD_HORIZONTAL_TOTAL_PIXEL_NUMBER;
   VDC3.PANEL_VSYNC_TIM.BIT.VSYNC_START             = 0;
   VDC3.PANEL_VSYNC_TIM.BIT.VSYNC_END               = LCD_VSYNC_WIDTH;
   VDC3.PANEL_HSYNC_TIM.BIT.HSYNC_START             = 0;
   VDC3.PANEL_HSYNC_TIM.BIT.HSYNC_END               = LCD_HSYNC_WIDTH;
   VDC3.DE_SIZE.BIT.DE_HEIGHT                       = LCD_VERTICAL_ACTIVE_LINE;
   VDC3.DE_SIZE.BIT.DE_WIDTH                        = LCD_HORIZONTAL_ACTIVE_PIXEL;
   VDC3.DE_START.BIT.DE_START_V                     = LCD_VERTICAL_ACTIVE_LINE_OFFSET;
   VDC3.DE_START.BIT.DE_START_H                     = LCD_HORIZONTAL_ACTIVE_PIXEL_OFFSET;
   VDC3.AC_LINE_NUM.BIT.AC_LINE_NUM                 = LCD_MODULATION_TOGGLE_NUMBER;
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
	VDC3.GRCMEN1.BIT.VEN	           = 0;
   VDC3.GRCMEN1.BIT.WE             = 1;
   VDC3.GROPEDPA1.BIT.WE           = 1;
	VDC3.GRCMEN2.BIT.VEN	           = 1;
	VDC3.GRCMEN2.BIT.WE             = 1;
 #if GFX_DRIVER_ENABLE_VIDEO_IN != 0
   /*
   ** Initialize the Video In.
   */
   VDC3.VIDEO_SIZE.LONG          = 0x00F002D0;  // VIDEO_HEIGHT=240, VIDEO_WIDTH=720
   VDC3.VIDEO_VSTART.LONG        = 0x0013011A;  // VIDEO_VSTART_TOP=19, VIDEO_VSTART_BTM=282
   VDC3.VIDEO_HSTART.LONG        = 0x00000114;  // VIDEO_HSTART=276
   VDC3.VIDEO_VSYNC_TIM1.LONG    = 0x0048014F;  // VIDEO_VSYNC_START1_TOP=22, VIDEO_VSYNC_START1_BTM=285
   VDC3.VIDEO_VSYNC_TIM2.LONG    = 0x30;
   VDC3.VIDEO_SAVE_NUM.LONG      = 0x00000000;  // FIELD_SAVE_NUM=1
   VDC3.VIDEO_IMAGE_CNT.LONG     = 0x80800302;  // SCALE_V=11,SUBU_SCALE_V=1 ~51.4 (x2 for full) 
   VDC3.VIDEO_BASEADR.LONG       = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
   VDC3.VIDEO_LINE_OFFSET.LONG   = 0x3C0;
   VDC3.VIDEO_FIELD_OFFSET.LONG  = 0x17A20;
   VDC3.VIDEO_LINEBUFF_NUM.LONG  = 0xFF;        // number of video line buffer
   VDC3.VIDEO_DISP_SIZE.LONG     = 0x00F001E0;  // VIDEO_DISP_HEIGHT=240, VIDEO_DISP_WIDTH=480
   VDC3.VIDEO_DISP_HSTART.LONG   = 0x25;        // Horizontal position
 #endif
}

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
   if(fl_fade_id_U8 < NB_FADE_EFFECT_CONFIG)
   {
      l_fade_effect_mode_U8 = GFX_FADE_EFFECT_REQUESTED;
      l_fade_effect_id_U8   = fl_fade_id_U8;
   }
   else if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ACTIVE)
   {
      l_fade_effect_mode_U8 = GFX_FADE_EFFECT_ABORT;
      while(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_ABORT);
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
   if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE)
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
   RECTANGLE_DEF_T fl_clip_area_SP
#endif
   GFX_DRV_ENV_INFO fl_drv_context_S;
   fl_drv_context_S.fb_P      = l_layer_fb_pointer_table[p_lid_U8][l_working_layer_data_SP->b_work_fb_index];
   fl_drv_context_S.fb_w      = lc_layer_table_S[p_lid_U8].width;
   fl_drv_context_S.fb_h      = lc_layer_table_S[p_lid_U8].height;
   fl_drv_context_S.fb_format = lc_layer_table_S[p_lid_U8].pix_format;
   GfxDriverSetEnv(&fl_drv_context_S);
   l_working_layer_data_SP->b_update = TRUE;
#ifdef ENABLE_FPS_CALCULATION
   fps_start_count = fps_base_count;
#endif
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
   fl_clip_area_SP.x = 0;
   fl_clip_area_SP.y = 0;
   fl_clip_area_SP.w = lc_layer_table_S[0].width;;
   fl_clip_area_SP.h = lc_layer_table_S[0].height;;
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
            T_DMAC_TRANS  fl_dma_tfr_S;
            if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)
            {
               fl_dma_tfr_S.dst_adr              = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               fl_dma_tfr_S.src_adr              = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 1;
            }
            else
            {
               fl_dma_tfr_S.dst_adr              = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               fl_dma_tfr_S.src_adr              = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index = 0;
            }
            fl_dma_tfr_S.count   = (lc_layer_table_S[GFX_DRIVER_LAYER_0].width*lc_layer_table_S[GFX_DRIVER_LAYER_0].height);
            glib_Dmac_Trans(0, &fl_dma_tfr_S);
            l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = TRUE;
         }
       #endif /*#if GFX_DRIVER_ENABLE_FADE_EFFECT > 0*/
         fl_driver_busy_BOOL               = FALSE;
      }
   }
   return(fl_driver_busy_BOOL);
}

/****************************************************************************
Function Name        : void GfxDriverEndUpdate(void){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
#if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
  void GfxDriverEndUpdate(UINT8 p_active_layers_U8, UINT8 p_post_copy_flag_U8)
#else
  void GfxDriverEndUpdate(UINT8 p_active_layers_U8)
#endif
#else
#if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
  void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8)
#else
  void GfxDriverEndUpdate(void)
#endif
#endif
{
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
         VDC3.GROPSOFST2.BIT.GROPSOFST  = GFX_LAYER_0_MAX_W_LENGTH * 2;
         VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = VDC3.GRCBUSCNT1.BIT.BUS_FORMAT;
         VDC3.GROPEDPA2.BIT.DEFA        = 0;  /* initial alpha */
         VDC3.GROPEDPA2.BIT.ACOEF       = 5;
         VDC3.GROPEDPA2.BIT.ARATE       = 1;
         VDC3.GROPEDPA2.BIT.AMOD        = 1;  /* 1 add, 2 subtract */
         VDC3.GROPEDPA2.BIT.AEN         = 1;
         VDC3.GROPSADR2.BIT.GROPSADR    = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
         VDC3.GRCMEN2.BIT.DEN           = 1; /* Layer 2 emable */
         VDC3.GROPEDPA2.BIT.WE          = 1;
         VDC3.GRCMEN2.BIT.WE            = 1;
         while(VDC3.GRCMEN2.BIT.WE);
         l_fade_effect_mode_U8 = GFX_FADE_EFFECT_ACTIVE;
      }
   }
   else if(l_fade_effect_mode_U8 == GFX_FADE_EFFECT_INACTIVE)
 #endif
   {
      GfxDriverSyncDisplay();
      if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
      {
         /* 
         ** Initiate DMA transfer of current buffer to working buffer 
         */
         if((p_post_copy_flag_U8 & (1<<GFX_DRIVER_LAYER_0)) != 0)
         {
            T_DMAC_TRANS  fl_dma_tfr_S;
            if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index == 0)
            {
               fl_dma_tfr_S.dst_adr = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
               fl_dma_tfr_S.src_adr = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
            }
            else
            {
               fl_dma_tfr_S.dst_adr = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_1];
               fl_dma_tfr_S.src_adr = (void *)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][GFX_DRIVER_FB_0];
            }
            fl_dma_tfr_S.count   = (lc_layer_table_S[GFX_DRIVER_LAYER_0].width*lc_layer_table_S[GFX_DRIVER_LAYER_0].height);
            glib_Dmac_Trans(0, &fl_dma_tfr_S);
         }
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_fb_copied = TRUE;
         l_layer_data_S[GFX_DRIVER_LAYER_0].b_update    = FALSE;
      }
   }
 #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
   else
   {
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
void GfxDriverVSyncISR(void)
{
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
            VDC3.GROPSOFST2.BIT.GROPSOFST = GFX_LAYER_1_MAX_W_LENGTH * 2;
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
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = ARGB4444;
            }
            else
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = RGB565;
            }
            VDC3.GRCMEN2.LONG = 0x80000003; /* Enable layer 2 */
          #else
            VDC3.GRCMEN2.LONG = 0x80000001; /* disable layer 2 */
          #endif
            VDC3.GRCMEN1.LONG     = 0x80000002;
            l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
            l_vsync_request_BOOL  = FALSE;
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
            VDC3.GROPSOFST2.BIT.GROPSOFST = GFX_LAYER_1_MAX_W_LENGTH * 2;
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
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = ARGB4444;
            }
            else
            {
               VDC3.GRCBUSCNT2.BIT.BUS_FORMAT = RGB565;
            }
            VDC3.GRCMEN2.LONG = 0x80000003; /* Enable layer 2 */
          #else
            VDC3.GRCMEN2.LONG = 0x80000001; /* disable layer 2 */
          #endif
            VDC3.GRCMEN1.LONG     = 0x80000002;
            l_vsync_request_BOOL  = FALSE;
         }
         l_fade_effect_mode_U8 = GFX_FADE_EFFECT_INACTIVE;
      }
      else
    #endif
      if(l_vsync_request_BOOL != FALSE)
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
       #endif
         l_vsync_request_BOOL = FALSE;
      }
   #if GFX_DRIVER_ENABLE_FADE_EFFECT > 0
      else
      {
      }
   #endif
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
void GfxDriverSyncDisplay(void)
{
   l_vsync_request_BOOL = TRUE;
   while(l_vsync_request_BOOL != FALSE); 
   /* 
   ** Swap the working buffer 
   */
   if(l_layer_data_S[GFX_DRIVER_LAYER_0].b_update != FALSE)
   {
      l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index++;
   }
#if NB_LAYERS > 1
   if(l_layer_data_S[GFX_DRIVER_LAYER_1].b_update != FALSE)
   {
      l_layer_data_S[GFX_DRIVER_LAYER_1].b_work_fb_index++;
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
void GfxDriverFpsText(GFX_SIZE_X_T fl_start_x, GFX_SIZE_Y_T fl_start_y, GFX_CHAR * fl_disp_string_P)
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
            fl_frame_buff_P        = l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];;
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
                        *fl_cur_frame_buff_P = 0x001F;
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

   sprintf((void *)fl_disp_buff, "[Cur %03d mSec]", fps_end_count);
   GfxDriverFpsText(0, 210, (void *)fl_disp_buff);
   sprintf((void *)fl_disp_buff, "[Max %03d mSec]", fps_longest_count);
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
   if(VDC3.VIDEO_MODE.BIT.VIDEO_MAIN_EXE != 0)
   {
      VDC3.GRCMEN1.LONG             = 0x80000002;
      VDC3.VIDEO_MODE.LONG          = 0x00;
   #if GFX_DRIVER_SYNC_WITH_VIDEO_IN > 0
      VDC3.SGMODE.BIT.EX_SYNC_MODE  = 0;
   #endif
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
void GfxDriverEnableVideoInput(void)
{
   if(VDC3.VIDEO_MODE.BIT.VIDEO_MAIN_EXE == 0)
   {
   #if GFX_DRIVER_SYNC_WITH_VIDEO_IN > 0
      VDC3.SGMODE.BIT.EX_SYNC_MODE  = 1;
   #endif
      VDC3.VIDEO_BASEADR.LONG       = (UINT32)l_layer_fb_pointer_table[GFX_DRIVER_LAYER_0][l_layer_data_S[GFX_DRIVER_LAYER_0].b_work_fb_index];
      VDC3.VIDEO_MODE.LONG          = 0x13;
      VDC3.GRCMEN1.LONG             = 0x80000003;
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
Date              :
By                :
Traceability      :
Change Description:
-----------------------------------------------------------------------------*/

