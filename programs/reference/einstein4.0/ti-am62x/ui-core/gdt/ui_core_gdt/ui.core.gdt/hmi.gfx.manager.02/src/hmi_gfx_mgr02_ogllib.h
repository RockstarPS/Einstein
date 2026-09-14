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
** Name:           hmi_gfx_mgr02_ovglib.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_OGLLIB_H
#define HMI_GFX_MGR02_OGLLIB_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_OPEN_GL)
 #if defined(WIN32)
  #include <stdio.h>
  #include <windows.h>
  #include <TCHAR.h>
 #endif
  #include <EGL/egl.h>
  #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
    #include <GLES2/gl2.h>
  #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
    #include <GLES/gl.h>
  #else
    #error "GL ES version not supported."
  #endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
s_gx_flocal hmi_gfx_mgr02_ogllib_init(void);
s_gx_flocal hmi_gfx_mgr02_ogllib_shutdown(void);
s_gx_flocal hmi_gfx_mgr02_ogllib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
s_gx_flocal hmi_gfx_mgr02_ogllib_finish(void);
s_gx_flocal hmi_gfx_mgr02_ogllib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP);
#if defined(GFX_MGR02_USE_FILESYSTEM)
s_gx_flocal hmi_gfx_mgr02_ogllib_build_uimage(GFX_MGR02_CONTEXT_T   const * p_cntx_SP,
                                              GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP);
#endif
s_gx_flocal hmi_gfx_mgr02_ogllib_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
s_gx_flocal hmi_gfx_mgr02_ogllib_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
s_gx_flocal hmi_gfx_mgr02_ogllib_build_tile(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TILE_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim);
#endif
s_gx_flocal hmi_gfx_mgr02_ogllib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                            HMI_CHAR             const * p_string,
                                            u_gx_flocal                  p_text_actual_width
#if defined(GFX_MGR02_OPEN_GL) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                           ,u_gx_flocal                 p_is_multi_line_text
#endif
);
void hmi_gfx_mgr02_ogllib_fb_updated(void);
s_gx_flocal hmi_gfx_mgr02_ogllib_get_bound(UINT32                p_obj_type,
                                           GFX_MGR02_CONTEXT_T const * p_cntx_SP,
                                           GFX_FLOAT               * p_bounds);
void hmi_gfx_mgr02_ogllib_remove_tex(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP, void const* p_img_id);

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif

#endif /* #if defined(GFX_MGR02_OPEN_GL) */
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
** CMS Rev 1.3      28-Jan-2014    EMANOJ1
** Updated to support user image type to load image from a RAM buffer even in the
** case of GFX_MGR02_USE_FILESYSTEM defined (RTC Task 116960).
**
** CMS Rev 1.2      26-Aug-2013     EMANOJ1
** Updated to support dynamic buffer allocation for OpenVg wdgets with 
** clip=false setting in kepler DCU targets.
**
** CMS Rev 1.1      15-May-2013     EMANOJ1
** Added hmi_gfx_mgr02_ovglib_get_bound() interface to calculate the 
** transformed bounds of an element
**
** CMS Rev 1.0      08-Aug-2012     EMANOJ1
** Creation.
**==========================================================================*/


/* end of file =============================================================*/
#endif
