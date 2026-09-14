/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2014. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_imxrt_lcdif.c
**
** Description:    Defines interface that calls LCDIFV2 driver API
**                 
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#define HMI_GFX_MGR02_IMXRT_LCDIF_C
/*============================================================================
** I N C L U D E   F I L E S 
**==========================================================================*/
#include "hmi_gfx_mgr02_context.h"
#if (defined(GFX_MGR02_IMXRT))|| defined(GFX_MGR02_IMXRT_PXP)
#include "hmi_gfx_mgr02_imxrt_pxp.h"
#include "hmi_gfx_mgr02_imxrt_lcdif.h"
#include "panel_definition_imxrt.h"


/*******************************************************************************
* Definitions
******************************************************************************/

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/


static BOOLEAN l_render_done = true;



/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format
** Visibility:       Global
** Description:      Checks if the rendering of the last frame been done
**
** Invocation:       By hmi_gfx_mgr02_layout_build_screen
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
lcdifv2_pixel_format_t hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format(UINT8 p_pix_format)
{
	lcdifv2_pixel_format_t fl_gdc_pix_format;

  switch (p_pix_format)
  {

  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB888:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB8888;
	 break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB8888:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB8888;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB1555:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB1555;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_ARGB4444:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB4444;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_YVYU422:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatYUYV;
    break;
  case (u_gx_flocal)GFX_MGR02_PIX_FORMAT_RGB565:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatRGB565;
    break;
  case GFX_MGR02_PIX_FORMAT_8BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex8BPP;
  break;
  case GFX_MGR02_PIX_FORMAT_4BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex4BPP;
  break;
  case GFX_MGR02_PIX_FORMAT_2BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex2BPP;
  break;
  default:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatRGB888;
    break;
  }
  return(fl_gdc_pix_format);


}


/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format
** Visibility:       Global
** Description:      Checks if the rendering of the last frame been done
**
** Invocation:       By hmi_gfx_mgr02_layout_build_screen
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
lcdifv2_pixel_format_t hmi_gfx_mgr02_imxrt_lcdif_map_image_pix_format(UINT8 p_pix_format)
{
  lcdifv2_pixel_format_t fl_gdc_pix_format;


  switch (p_pix_format)
  {

  case kPXP_AsPixelFormatRGB565:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatRGB565;
    break;
  case kPXP_AsPixelFormatARGB8888:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB8888;
    break;
  case kPXP_AsPixelFormatARGB1555:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB1555;
    break;
  case kPXP_AsPixelFormatARGB4444:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatARGB4444;
    break;
  case kPXP_AsPixelFormatIndex8BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex8BPP;
  break;
  case kPXP_AsPixelFormatIndex4BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex4BPP;
  break;
  case kPXP_AsPixelFormatIndex2BPP:
	fl_gdc_pix_format = kLCDIFV2_PixelFormatIndex2BPP;
  break;
  default:
    fl_gdc_pix_format = kLCDIFV2_PixelFormatRGB888;
    break;
  }

  return(fl_gdc_pix_format);


}

UINT8 hmi_gfx_mgr02_imxrt_lcdif_get_bpp(lcdifv2_pixel_format_t p_gdc_pix_format)
{
    uint8_t ret;

    switch (p_gdc_pix_format)
    {

    case kLCDIFV2_PixelFormatABGR8888:
    case kLCDIFV2_PixelFormatARGB8888:
         ret = 32;
         break;
    case kLCDIFV2_PixelFormatUYVY:
    case kLCDIFV2_PixelFormatVYUY:
    case kLCDIFV2_PixelFormatYUYV:
    case kLCDIFV2_PixelFormatYVYU:
    case kLCDIFV2_PixelFormatRGB565:
    case kLCDIFV2_PixelFormatARGB1555:
    case kLCDIFV2_PixelFormatARGB4444:
         ret = 16;
         break;
    case kLCDIFV2_PixelFormatRGB888:
         ret = 24;
         break;
    case kLCDIFV2_PixelFormatIndex8BPP:
         ret = 8;
         break;
    case kLCDIFV2_PixelFormatIndex4BPP:
         ret = 4;
         break;
    case kLCDIFV2_PixelFormatIndex2BPP:
        ret = 2;
        break;
    case kLCDIFV2_PixelFormatIndex1BPP:
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }

    return ret;
}


/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_display_initialize
** Visibility:       Global
** Description:      This function for rendering the window
**
** Invocation:       By hmi_gfx_mgr02_context_end_update()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_imxrt_lcdif_display_initialize(void)
{
  lcdifv2_display_config_t lcdifv2Config = {0};

  LCDIFV2_DisplayGetDefaultConfig(&lcdifv2Config);

  lcdifv2Config.panelWidth    = DEMO_PANEL_WIDTH;
  lcdifv2Config.panelHeight   = DEMO_PANEL_HEIGHT;
  lcdifv2Config.hsw           = DEMO_HSW;
  lcdifv2Config.hfp           = DEMO_HFP;
  lcdifv2Config.hbp           = DEMO_HBP;
  lcdifv2Config.vsw           = DEMO_VSW;
  lcdifv2Config.vfp           = DEMO_VFP;
  lcdifv2Config.vbp           = DEMO_VBP;
  lcdifv2Config.polarityFlags = DEMO_POL_FLAGS;
  lcdifv2Config.lineOrder     = kLCDIFV2_LineOrderRGB;

  LCDIFV2_Init(DEMO_LCDIF);
  LCDIFV2_SetDisplayConfig(DEMO_LCDIF, &lcdifv2Config);
  LCDIFV2_EnableInterrupts(DEMO_LCDIF, DEMO_CORE_ID, (uint32_t)kLCDIFV2_VerticalBlankingInterrupt);
  LCDIFV2_EnableDisplay(DEMO_LCDIF, true);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_initialize
** Visibility:       Global
** Description:      This function for rendering the window
**                   
** Invocation:       By hmi_gfx_mgr02_context_end_update()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_imxrt_lcdif_layer_initialize(UINT32 p_layer_id)
{
  lcdifv2_pixel_format_t fl_pix_format;
  UINT32 fl_bpp;
  lcdifv2_buffer_config_t bufferConfig = {0};
 
  if(p_layer_id<GFX_MGR02_NUM_LAYERS)
  {
    fl_pix_format = hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format(lc_layer_def_S[p_layer_id].pix_format);
    fl_bpp = hmi_gfx_mgr02_imxrt_lcdif_get_bpp(fl_pix_format);
    LCDIFV2_SetLayerSize(DEMO_LCDIF, p_layer_id, lc_layer_def_S[p_layer_id].area.width, lc_layer_def_S[p_layer_id].area.height);
    LCDIFV2_SetLayerOffset(DEMO_LCDIF, p_layer_id, lc_layer_def_S[p_layer_id].area.x, lc_layer_def_S[p_layer_id].area.y);
    bufferConfig.strideBytes = (lc_layer_def_S[p_layer_id].area.width * fl_bpp) >> 3U;
    bufferConfig.pixelFormat = fl_pix_format;
    LCDIFV2_SetLayerBufferConfig(DEMO_LCDIF, p_layer_id, &bufferConfig);
  }
}
/*============================================================================
** Function Name:    hmi_app_amber_iris_render_window
** Visibility:       Global
** Description:      This function for mapping fb to layer and enabling the layer.
**                   
** Invocation:       By hmi_gfx_mgr02_context_end_update()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/

void hmi_gfx_mgr02_imxrt_lcdif_render_window(UINT32 p_layer_id, void * p_fb_ptr)
{
    if(p_fb_ptr != NULL)
    {
    /* wait loop for pxp to complete blit */
    #ifdef USE_IMXRT_PXP_QUEUE
        hmi_gfx_mgr02_imxrt_pxp_wait2complete_blit();
    #endif
        l_render_done = false;
        LCDIFV2_SetLayerBufferAddr(DEMO_LCDIF, p_layer_id, (UINT32)(UINT8 *)p_fb_ptr);
        LCDIFV2_EnableLayer(DEMO_LCDIF, p_layer_id, true);
        /* For the DBI interface display, application must wait for the first
        * frame buffer sent to the panel.
        */
    }
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_TriggerShadowLoad
** Visibility:       Global
** Description:      This function for Triggering ShadowLoad Registers.
**                   
** Invocation:       By hmi_gfx_mgr02_render_display()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/

void hmi_gfx_mgr02_imxrt_lcdif_TriggerShadowLoad(UINT32 p_layer_id)
{
    LCDIFV2_TriggerLayerShadowLoad(DEMO_LCDIF, p_layer_id);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_disable_layer
** Visibility:       Global
** Description:      This function for Destroying the window in shutdown sequence.
**                   
** Invocation:       By hmi_gfx_mgr02_context_shutdown()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_imxrt_lcdif_disable_layer(UINT32 p_layer_id)
{  
    LCDIFV2_EnableLayer(DEMO_LCDIF, p_layer_id, false);
    LCDIFV2_TriggerLayerShadowLoad(DEMO_LCDIF, p_layer_id);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_shutdown
** Visibility:       Global
** Description:      This function for Destroying the window in shutdown sequence.
**                   
** Invocation:       By hmi_gfx_mgr02_context_shutdown()
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/
void hmi_gfx_mgr02_imxrt_lcdif_shutdown(UINT32 p_layer_id)
{
  LCDIFV2_DisableInterrupts(DEMO_LCDIF, (uint8_t)DEMO_CORE_ID, (uint32_t)kLCDIFV2_VerticalBlankingInterrupt);
  LCDIFV2_Deinit(DEMO_LCDIF); 
  GFX_MGR02_UNUSED_VAR(p_layer_id);
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_imxrt_lcdif_is_render_done
** Visibility:       Global
** Description:      Checks if the rendering of the last frame been done
**                   
** Invocation:       By hmi_gfx_mgr02_layout_build_screen
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/

BOOLEAN hmi_gfx_mgr02_imxrt_lcdif_is_render_done(void)
{
  return(l_render_done);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_layout_is_render_done
** Visibility:       Global
** Description:      Checks if the rendering of the last frame been done
**
** Invocation:       By hmi_gfx_mgr02_layout_build_screen
** Inputs/Outputs:   None
** Critical Section: None.
**==========================================================================*/

void hmi_gfx_mgr02_imxrt_lcdif_vblank_interrupt(void)
{
  l_render_done = true;
}
#endif /* #if (defined(GFX_MGR02_IMXRT) && (GFX_MGR02_NUM_IMXRT_MERGE_WIDGETS>0))|| defined(GFX_MGR02_IMXRT_PXP) */
/*---------------------------------------------------------------------------
Date              : 21/7/2021
CDSID             : CSAKTHIV
Traceability      :
Change Description: Initial version
Compliances:
-----------------------------------------------------------------------------*/
