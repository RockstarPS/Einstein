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
** Name:           hmi_gfx_mgr02_monolib.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_MONOLIB_H
#define HMI_GFX_MGR02_MONOLIB_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_MONOTFT)
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*#if GFX_MGR02_PIX_FORMAT <= GFX_MGR02_PIX_FORMAT_8BPP
   typedef UINT8  GFX_COLOR_T;
#elif GFX_MGR02_PIX_FORMAT <= GFX_MGR02_PIX_FORMAT_RGB565
   typedef UINT16 GFX_COLOR_T;
#elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_ARGB8888
   typedef UINT32 GFX_COLOR_T;
#else
   #error "Unsupported Color Depth \n"
#endif
*/

/*
Below content in types.h
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)
#define GFX_MGR02_PIX_FORMAT_ALPHA   0x01 
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
#define GFX_MGR02_PIX_FORMAT_ALPHA   0x03
#else
#define GFX_MGR02_PIX_FORMAT_ALPHA   0x0F
#endif*/



/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

s_gx_flocal hmi_gfx_mgr02_monolib_build_image(GFX_MGR02_CONTEXT_T  const * , GFX_MGR02_IMAGE_DEF_T  const *);
s_gx_flocal hmi_gfx_mgr02_monolib_build_fill(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_FILL_DEF_T   const *, GFX_MGR02_IDIM_DATA const *);
s_gx_flocal hmi_gfx_mgr02_monolib_build_text(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TEXT_DEF_T   const *, HMI_CHAR const *, u_gx_flocal);
s_gx_flocal hmi_gfx_mgr02_monolib_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
s_gx_flocal hmi_gfx_mgr02_monolib_finish(void);
s_gx_flocal hmi_gfx_mgr02_monolib_init(void);
s_gx_flocal hmi_gfx_mgr02_monolib_shutdown(void);
s_gx_flocal hmi_gfx_mgr02_monolib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
void hmi_gfx_mgr02_monolib_normal_rle_image(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          );
void hmi_gfx_mgr02_monolib_trans_rle_image(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha,
                           GFX_MGR02_COLOR trans_color
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          );
#endif /* #if defined(GFX_MGR02_MONOTFT) */

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

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
** CMS Rev #        Date            By
** CMS Rev X.X      dd-mmm-yyyy     CDSID
**
**============================================================================
**
** CMS Rev 1.0      08-Aug-2012     EMANOJ1
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
#endif
