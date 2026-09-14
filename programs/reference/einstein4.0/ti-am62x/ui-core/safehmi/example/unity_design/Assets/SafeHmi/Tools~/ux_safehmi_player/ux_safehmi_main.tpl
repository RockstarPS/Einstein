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
** Name:           @filename@
**
** Description:    @filedescription@
**
** Organization:   UI Frameworks & Tools, Visteon
**
**============================================================================
**
**==========================================================================*/

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "ux_shmi_uimain.h"
@includes@
@include_image@

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
@macros@

#if UX_SHMI_MAX_DESIGN_DEPTH > UX_SHMI_MAX_SCENE_DEPTH
  #error "UX_SHMI_MAX_DESIGN_DEPTH should be <= UX_SHMI_MAX_SCENE_DEPTH"
#endif

namespace UX_SHMI_PLAYER
{
@class@

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
@funcprotos@

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**===========================================================================*/
@memallocs@
@memallocs_tables@

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
@entrypoints@

@setfprotos@


}//namespace-UX_SHMI_PLAYER

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
** CMS Rev 1.0      04-Feb-2016  emanoj1
** Creation.
**
**==========================================================================*/

/* end of file =============================================================*/
