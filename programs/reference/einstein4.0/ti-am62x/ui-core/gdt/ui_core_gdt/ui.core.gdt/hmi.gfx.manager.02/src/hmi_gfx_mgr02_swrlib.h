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
** Name:           hmi_gfx_mgr02_swrlib.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_SWRLIB_H
#define HMI_GFX_MGR02_SWRLIB_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

/*******************************************************************************
                            Macro Definitions
*******************************************************************************/
#ifdef HMI_GFX_MGR02_SWRLIB_C
#define GFX_SWRLIB_EXTERN
#else
#define GFX_SWRLIB_EXTERN     extern
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#ifdef  __cplusplus
extern "C" {
#endif
#if defined(GFX_MGR02_SOFTWARE)
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_build_image(GFX_MGR02_CONTEXT_T   const* p_cntx_SP,
                                                               GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP);
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_build_fill(GFX_MGR02_CONTEXT_T  const* p_context_SP,
                                                              GFX_MGR02_FILL_DEF_T const* p_elem_def_SP,
                                                              GFX_MGR02_IDIM_DATA  const* p_dim);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_build_tile(GFX_MGR02_CONTEXT_T  const* p_env_SP,
                                                              GFX_MGR02_TILE_DEF_T const* p_elem_def_SP,
                                                              GFX_MGR02_IDIM_DATA  const* p_dim);
#endif
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_build_text(GFX_MGR02_CONTEXT_T  const* p_cntx_SP,
                                                              GFX_MGR02_TEXT_DEF_T const* p_elem_def_SP,
                                                              HMI_CHAR             const* p_string,
                                                              u_gx_flocal                 p_text_actual_width);
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_get_bound(UINT32 p_obj_type, 
                                                            GFX_MGR02_CONTEXT_T const * p_cntx_SP,
                                                            GFX_FLOAT * p_bounds);
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_init(void);
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
GFX_SWRLIB_EXTERN s_gx_flocal hmi_gfx_mgr02_swrlib_finish(void);

GFX_SWRLIB_EXTERN void hmi_gfx_mgr02_emergency_shutdown(void);

#endif
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
**
** CMS Rev 1.2      28-Dec-2012    YSREEMAN
** Creation. Changes were made for integrating and to resolve compilation errors
**==========================================================================*/

/* end of file =============================================================*/
#endif
