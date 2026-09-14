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
** Name:           hmi_gfx_mgr02_theme.h
**
** Description:
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_THEME_H
#define HMI_GFX_MGR02_THEME_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_THEME_ENABLED

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
void hmi_gfx_mgr02_theme_init(void);
void hmi_gfx_mgr02_theme_set_active_theme(UINT32 fl_theme_U32);
UINT32 hmi_gfx_mgr02_theme_get_active_theme(void);
FILE * hmi_gfx_mgr02_theme_fopen(char const * fl_file_name_ptr);

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif
#endif /* #if defined(GFX_MGR02_THEME_ENABLED) */

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
** CMS Rev 1.0      27-Nov-2015     csakthiv
** Creation.
** Theme support for B515 460855
**==========================================================================*/


/* end of file =============================================================*/
#endif
