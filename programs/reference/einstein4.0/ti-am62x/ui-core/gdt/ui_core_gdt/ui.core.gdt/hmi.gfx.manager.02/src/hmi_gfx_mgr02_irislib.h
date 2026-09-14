/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_mgr02_irislib.h
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_IRISLIB_H
#define HMI_GFX_MGR02_IRISLIB_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_safety.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_types.h"
#if defined(GFX_MGR02_FUJITSU)
#include "iris_drv.h"
#include "util_math.h"
#include "hmi_gfx_mgr02_dirty_area.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*******************************************************************************
 Macro Definitions
*******************************************************************************/
/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

s_gx_flocal hmi_gfx_mgr02_irislib_init(void);
s_gx_flocal hmi_gfx_mgr02_irislib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
s_gx_flocal hmi_gfx_mgr02_irislib_build_image(GFX_MGR02_CONTEXT_T  const * , GFX_MGR02_IMAGE_DEF_T  const *);
s_gx_flocal hmi_gfx_mgr02_irislib_build_fill(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_FILL_DEF_T   const *, GFX_MGR02_IDIM_DATA const *);
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
s_gx_flocal hmi_gfx_mgr02_irislib_build_tile(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TILE_DEF_T   const *, GFX_MGR02_IDIM_DATA const *);
#endif
s_gx_flocal hmi_gfx_mgr02_irislib_build_text(GFX_MGR02_CONTEXT_T   const * , GFX_MGR02_TEXT_DEF_T   const *, HMI_CHAR const *, u_gx_flocal);
s_gx_flocal hmi_gfx_mgr02_irislib_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, GFX_FLOAT * p_bounds);
s_gx_flocal hmi_gfx_mgr02_irislib_finish(
#ifdef GFX_MGR02_IRIS_PIXEL_POKING
GFX_MGR02_CONTEXT_T   const * 
#else
void
#endif
);
MML_GDC_SURF_FORMAT hmi_gfx_mgr02_irislib_get_disp_pix_format(u_gx_flocal p_pix_format);
#ifdef GFX_MGR02_IRIS_PIXEL_POKING
void hmi_gfx_mgr02_irislib_init_pixel_buffer(void);
GFX_MGR02_PIXEL_POKING_STATUS hmi_gfx_mgr02_irislib_set_pixel_data(GFX_MGR02_PIXEL_DATA p_set_pixel_data, UINT32 p_buffer_id);
#endif


/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif
#endif /* #if defined(GFX_MGR02_FUJITSU) */

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
** CMS Rev 1.0      14-Aug-2013     CMUTHUSA
** Creation.
** First version archived in RTC
**==========================================================================

**============================================================================
**
** CMS Rev 1.1      25-May-2015     ADEVI
** RTC 323189:
** Functions introduced for pixel poking feature.
**==========================================================================
**============================================================================
**
** CMS Rev 1.2      01-Oct-2015     APERUMAL
** RTC 434948
** Compiler warning fix for Porsche
**==========================================================================*/


/* end of file =============================================================*/
#endif
