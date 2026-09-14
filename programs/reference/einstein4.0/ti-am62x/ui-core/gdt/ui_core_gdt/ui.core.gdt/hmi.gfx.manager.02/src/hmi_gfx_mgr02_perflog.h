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
** Name:           hmi_gfx_mgr02_perflog.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_PERFLOG_H
#define HMI_GFX_MGR02_PERFLOG_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

enum
{
   GFX_LOG_OVERALL,
   GFX_LOG_PROCESSING,
   GFX_LOG_RENDERING,
   GFX_LOG_DIRTY_AREA_PROCESSING,
   GFX_LOG_SWAP_BUFFER,
#ifdef GFX_MGR02_KEPLER
   GFX_LOG_DCU_OVERALL,
   GFX_LOG_DCU_PROCESSING,
   GFX_LOG_DCU_RENDERING,
   GFX_LOG_DCU_OPENVG,
   GFX_LOG_DCU_EDMA,
   GFX_LOG_DCU_MULTICOLOR,
   GFX_LOG_DCU_ISR,
   GFX_LOG_DCU_OFFSCRN_CPY,
   GFX_LOG_DCU_EDMA_ISR,
   GFX_LOG_DCU_DF2VS,
#endif
   GFX_LOG_MAX
};

#ifdef GFX_MGR02_KEPLER
 #define GFX_LOG_MAX_NUM (15)
#else
 #define GFX_LOG_MAX_NUM (5)
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

#ifdef GFX_MGR02_ENABLE_LOG
 void gfxlogstart(UINT32 id);
 void gfxlogend(UINT32 id);
 void gfxlogstop(UINT32 id);
 void gfxlogcontinue(UINT32 id);
 void gfxlogupdate(void);
 void gfxloginit(void);
#else
 #define gfxlogstart(id)
 #define gfxlogend(id)
 #define gfxlogstop(id)
 #define gfxlogcontinue(id)
 #define gfxlogupdate()
 #define gfxloginit()
#endif

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

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
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** CMS Rev 1.1      17-Dec-2013    EMANOJ1
** More metrics added for DCU
**
** CMS Rev 1.0      17-May-13    EMANOJ1
** Creation.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
