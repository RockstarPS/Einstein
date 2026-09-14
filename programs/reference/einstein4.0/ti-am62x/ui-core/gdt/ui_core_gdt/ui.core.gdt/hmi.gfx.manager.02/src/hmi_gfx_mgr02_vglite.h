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
** Name:           hmi_gfx_mgr02_vglite.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/

#ifndef HMI_GFX_MGR02_VGLITE_H
#define HMI_GFX_MGR02_VGLITE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_VGLITE)

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#ifdef HMI_GFX_MGR02_VGLITE_C
#define GFX_VGLITE_EXTERN
#else
#define GFX_VGLITE_EXTERN extern
#endif


#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

#define GFX_VGL_UTIL_SUCCESS(rc, execute)                     \
{                                                             \
    (rc) = (execute);                                         \
    if ((rc) != VG_LITE_SUCCESS){/*while( 1 == 1 ){} should be added while debugging so in error case It loops*/}           \
}


#if (GFX_MGR02_NUM_OF_SVGS > 0)
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_build_svg(GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_MGR02_OVG_OBJECT_T const * p_elem_def_SP);
#endif
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_init(void);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_shutdown(void);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_finish(void);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, GFX_MGR02_IDIM_DATA  const * p_dim);
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_build_image(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, GFX_MGR02_IMAGE_DEF_T  const * p_elem_def_SP);
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_build_text(GFX_MGR02_CONTEXT_T   const *p_cntx_SP , GFX_MGR02_TEXT_DEF_T   const *p_elem_def_SP, 
                                                              HMI_CHAR const *p_string, u_gx_flocal p_text_actual_width
                                                              #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                                              ,u_gx_flocal p_is_multi_line_text
                                                              #endif
                                                              );
#endif                                                              
GFX_VGLITE_EXTERN s_gx_flocal hmi_gfx_mgr02_vglite_fb_copy(GFX_MGR02_CONTEXT_T const * p_cntx_SP, void  *p_src_ptr , void  *p_dst_ptr);

#endif /* #if defined(GFX_MGR02_VGLITE) */

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
** CMS Rev 1.0      31-Jan-2022     MCHOUDHA
** Initial version created 
**==========================================================================*/

/* end of file =============================================================*/
#endif
