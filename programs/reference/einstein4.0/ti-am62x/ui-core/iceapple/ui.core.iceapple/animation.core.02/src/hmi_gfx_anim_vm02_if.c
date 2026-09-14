/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2011. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_anim_if.c
**
** Description:    This file is created to interface anim core with View 
**                 Manager 02. This is an optional file.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_ANIM_IF_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_anim_engine.cfg"
#include "hmi_logic_state_handler.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/*============================================================================
** Function Name:    hmi_lsh_start_animation
** Visibility:       global
** Description:      Starts the animation
** Invocation:       By VM02
** Inputs/Outputs:   In  : Information animation to be started
**                   Out : Returns TRUE if animation is started else FALSE
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
UINT32 hmi_lsh_start_animation(UINT32 p_state_id, UINT32 p_anim_id)
{
  UINT32 fl_animation_started = 0;// (UINT32)FALSE - For MISRA fix FALSE is changed as 0
#if GFX_NUM_ANIMATIONS > 0
   if(p_anim_id != (UINT32)ANIM_MAX_ID)
   {
      if(hmi_gfx_anim_replay_fwd(p_state_id, p_anim_id) == (UINT32)GFX_ANIM_STATE_RUNNING)
      {
        fl_animation_started = 1; // (UINT32)TRUE - For MISRA fix TRUE is changed as 1
      }
   }
#else
   HMI_UNUSED_VAR(p_anim_id);
   HMI_UNUSED_VAR(p_state_id);
#endif
   return(fl_animation_started);
}

/*============================================================================
** Function Name:    hmi_lsh_stop_animation
** Visibility:       global
** Description:      Stops the requested animation
** Invocation:       By VM02
** Inputs/Outputs:   Information on animation to be stopped
** Critical Section: None.
** Created:          27-Nov-2012 by EMANOJ1
** Updated:          27-Nov-2012 by EMANOJ1
**==========================================================================*/
void hmi_lsh_stop_animation(UINT32 p_state_id, UINT32 p_anim_id)
{
#if GFX_NUM_ANIMATIONS > 0
	(void)hmi_gfx_anim_stop(p_state_id, p_anim_id);
#else
	HMI_UNUSED_VAR(p_anim_id);
	HMI_UNUSED_VAR(p_state_id);
#endif
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
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** CMS Rev 1.2      03-Sep-15    ARAJASE2
** Resolved compiler warnings in hmi_lsh_start_animation and hmi_lsh_stop_animation.
** Removed unused parameter
**
** CMS Rev 1.1      16-Apr-13    EMANOJ1
** QAC 7.1 fixes
**
** CMS Rev 1.0      27-Nov-12    EMANOJ1
** Creation.
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
