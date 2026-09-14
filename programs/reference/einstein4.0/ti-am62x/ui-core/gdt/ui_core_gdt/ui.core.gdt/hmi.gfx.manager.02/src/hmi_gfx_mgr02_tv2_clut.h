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
** Name:           hmi_gfx_mgr02_tv2_clut.h
**
** Description:
**
** Organization:   UE COC, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_TV2_CLUT_H
#define HMI_GFX_MGR02_TV2_CLUT_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_clut_table.h"
#if defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_OF_CLUTS > 0U)


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef HMI_GFX_MGR02_TV2_CLUT_C
	#define EXTERN
#else
	#define EXTERN extern
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*******************************************************************************
 Macro Definitions
*******************************************************************************/

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
/**
    Initialization function of the TV2 CLUT module.

    \param [in] void

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_tv2_pallette_init(void);
/**
    Function for deallocating all the pallettes.

    \param [in] void

    \retval  ::void
**/
EXTERN void hmi_gfx_mgr02_tv2_free_all_pallettes(void);


EXTERN void hmi_gfx_mgr02_tv2_free_blit_pallettes(void);


/**
    Function for checking whether the requested pallette is already present or not.

    \param [in] p_palette_region
    \param [in] p_clut_p
    \retval  ::1 if the pallette is present. 0 otherwise.
**/
EXTERN CYGFX_PALETTE hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION p_palette_region, UINT8 const *p_clut_p);
/**
    Function for allocating the pallette.

    \param [in] p_palette_region
    \param [in] p_clut_p
    \param [in] p_size_u16
    \retval  ::void.
**/
EXTERN CYGFX_PALETTE hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION p_palette_region, const void * p_clut_p, UINT16 p_size_u16);
/**
    Function for deallocating clut from CLUT RAM.

    \param [in] p_palette_region
    \param [in] p_clut_p
    \retval  ::void.
**/
EXTERN void hmi_gfx_mgr02_tv2_remove_clut(CYGFX_PALETTE_REGION p_palette_region , const void * p_clut_p);
/**
    Function to get a clut index width.

    \param [in] p_clut_count_u16
    \retval  :: width of the index.
**/
EXTERN UINT32 hmi_gfx_mgr02_tv2_get_clut_index_width(UINT16 p_clut_count_u16);
#endif
/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif
#undef EXTERN
#endif /* #if defined(GFX_MGR02_TRAVEO2) */

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

**==========================================================================*/

