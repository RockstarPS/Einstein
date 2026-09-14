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
** Name:           hmi_gfx_mgr02_imxrt_lcdif.h
**
** Description:    Header file having the API required to interface to LCDIFV2 driver
**                 
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_IMXRT_LCDIF_H
#define HMI_GFX_MGR02_IMXRT_LCDIF_H

#include "hmi_gfx_mgr02_layout.h"

#include "fsl_lcdifv2.h"


#ifdef HMI_GFX_MGR02_IMXRT_LCDIF_C
	#define GFX_IMXRT_LCDIFV2_EXTERN
#else
	#define GFX_IMXRT_LCDIFV2_EXTERN extern
#endif

#if defined(GFX_MGR02_IMXRT) || defined(GFX_MGR02_IMXRT_PXP)
		#ifndef kPXP_AsPixelFormatIndex8BPP
			#define kPXP_AsPixelFormatIndex8BPP (u_gx_flocal)0x20
		#endif
		#ifndef kPXP_AsPixelFormatIndex4BPP
			#define kPXP_AsPixelFormatIndex4BPP (u_gx_flocal)0x21
		#endif
		#ifndef kPXP_AsPixelFormatIndex2BPP
			#define kPXP_AsPixelFormatIndex2BPP (u_gx_flocal)0x22
		#endif
#endif

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_display_initialize(void);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_layer_initialize(UINT32 p_layer_id);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_shutdown(UINT32 p_layer_id);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_render_window(UINT32 p_layer_id,   void * p_fb_ptr);
GFX_IMXRT_LCDIFV2_EXTERN BOOLEAN hmi_gfx_mgr02_imxrt_lcdif_is_render_done(void);
GFX_IMXRT_LCDIFV2_EXTERN lcdifv2_pixel_format_t hmi_gfx_mgr02_imxrt_lcdif_get_layer_pix_format(UINT8 p_pix_format);
GFX_IMXRT_LCDIFV2_EXTERN lcdifv2_pixel_format_t hmi_gfx_mgr02_imxrt_lcdif_map_image_pix_format(UINT8 p_pix_format);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_vblank_interrupt(void);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_disable_layer(UINT32 p_layer_id);
GFX_IMXRT_LCDIFV2_EXTERN UINT8 hmi_gfx_mgr02_imxrt_lcdif_get_bpp(lcdifv2_pixel_format_t p_gdc_pix_format);
GFX_IMXRT_LCDIFV2_EXTERN void hmi_gfx_mgr02_imxrt_lcdif_TriggerShadowLoad(UINT32 p_layer_id);
/*---------------------------------------------------------------------------
Date              : 27/6/21
CDSID             : CSAKTHIV
Traceability      :
Change Description: Initial version
Compliances:
-----------------------------------------------------------------------------*/
#undef GFX_IMXRT_LCDIFV2_EXTERN
#endif
