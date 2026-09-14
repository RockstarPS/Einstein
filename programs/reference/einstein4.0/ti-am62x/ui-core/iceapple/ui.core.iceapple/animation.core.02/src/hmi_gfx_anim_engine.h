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
** Name:           hmi_gfx_anim_engine.h
**
** Description:    public interface header for the animation engine
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_ANIM_ENGINE_H
#define HMI_GFX_ANIM_ENGINE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_anim_engine_types.h"
#include "hmi_gfx_anim_engine_cfg.h"


/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

/*
** hmi_gfx_anim_command() - p_param_flag options. These options can be bitwise
**                          combined to form derived commands. 
** GFX_ANIM_REPLAY - Starts animation from begening for forward direction(fwd)
**                                    from ending   for reverse direction(rwd)
** GFX_ANIM_PLAY   - Plays the animation if it is in stop state
**                   If animation is in pause state, it is started from its current
**                   position.
**                   If animation is already running does nothing.
** GFX_ANIM_STOP   - Stops the animation by bringing it to an end.
** GFX_ANIM_PAUSE  - Pauses the animation
** GFX_ANIM_FWD    - Set animation direction as forward direction
** GFX_ANIM_RWD    - Set animation direction as reverse direction
*/
#define GFX_ANIM_PLAY       ((UINT8)(0x01))
#define GFX_ANIM_STOP       ((UINT8)(0x02))
#define GFX_ANIM_PAUSE      ((UINT8)(0x04))
#define GFX_ANIM_REPLAY     ((UINT8)(GFX_ANIM_PLAY|GFX_ANIM_STOP))
#define GFX_ANIM_FWD        ((UINT8)(0x00))
#define GFX_ANIM_RWD        ((UINT8)(0x08))

#define GFX_ANIM_IS_DIR_FWD(param)   ((((UINT8)(param)) & GFX_ANIM_RWD) == GFX_ANIM_FWD)
#define GFX_ANIM_IS_DIR_RWD(param)   ((((UINT8)(param)) & GFX_ANIM_RWD) == GFX_ANIM_RWD)
#define GFX_ANIM_MAKE_CMD(id, param) (((id)<<8) | (param))
#define GFX_ANIM_GET_ID(cmd)         (((cmd)>>8))
#define GFX_ANIM_GET_CMD(cmd)        (((cmd) & 0xFF))
/*
** Interfaces to start animation by ID
*/
#define hmi_gfx_anim_replay_fwd(client_id, anim_id) hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_REPLAY|GFX_ANIM_FWD))
#define hmi_gfx_anim_replay_rwd(client_id, anim_id) hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_REPLAY|GFX_ANIM_RWD))
#define hmi_gfx_anim_play_fwd(client_id, anim_id)   hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_PAUSE|GFX_ANIM_PLAY|GFX_ANIM_FWD))
#define hmi_gfx_anim_play_rwd(client_id, anim_id)   hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_PAUSE|GFX_ANIM_PLAY|GFX_ANIM_RWD))
#define hmi_gfx_anim_stop(client_id, anim_id)       hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_STOP))
#define hmi_gfx_anim_pause(client_id, anim_id)      hmi_gfx_anim_command((client_id), (anim_id), (GFX_ANIM_PAUSE))
/*
** Interfaces to start animation by a command (an encoded ID and Option Paramter)
** e.g. hmi_gfx_anim_play(client id, GFX_ANIM_MAKE_CMD(anim_id, p_param_flag option))
**      hmi_gfx_anim_play(0, GFX_ANIM_MAKE_CMD(GFX_TEST_ANIM, GFX_ANIM_PLAY))
*/
#define hmi_gfx_anim_play(client_id, command)       hmi_gfx_anim_command((client_id), GFX_ANIM_GET_ID(command), GFX_ANIM_GET_CMD(command))

/*
** Function return status for hmi_gfx_anim_command()
*/
#define GFX_ANIM_STATE_STOPPED  (0U)
#define GFX_ANIM_STATE_RUNNING  (1U)
#define GFX_ANIM_STATE_PAUSED   (2U)
#define GFX_ANIM_STATE_FAULT    (3U)

/* 
vmuthusu igdt migration activity for TVM
added this for backward compatibility with existing application code
need to decide whether to retain this or remove this and let the
application take care of this
*/
#define ANIMATION_INVALID_ID    GFX_NUM_ANIMATIONS
#define ANIM_GET_ANIM_ID        0xFF

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

#if GFX_NUM_ANIMATIONS > 0
void hmi_gfx_anim_engine_init(void);
void hmi_gfx_anim_engine_tick(void);
UINT32 hmi_gfx_anim_command(UINT32 p_client_id, UINT32 p_anim_id, UINT32 p_param_flag);
void hmi_gfx_anim_engine(void);
UINT32 hmi_gfx_anim_get_client_id(UINT32 p_anim_id, UINT32 * p_client_id);
UINT32 hmi_gfx_anim_get_current_anim_id(void);
void hmi_gfx_anim_set_element_list(UINT32 p_anim_id,UINT32 p_frame_id,UINT8 p_index,UINT8 p_size,UINT32 * p_elem_list);
#if defined(GFX_ANIM_DLAYOUT_ENABLED)
void hmi_gfx_anim_engine_set_layout_selection(UINT8 p_layout_id);
#endif
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
** CMS Rev 1.0      27-Nov-12    EMANOJ1
** Creation.
**
**============================================================================
**
** CMS Rev 1.1      04/17/13    VMUTHUSU
** Added the two macros ANIMATION_INVALID_ID and ANIM_GET_ANIM_ID for 
** backward compatibility with application code written for ANIM CORE01 as 
** part of IGDT migration activity for TVM program
**
** CMS Rev 1.2     24-SEP-15    ADEVI             RTC: 368734
** Interface hmi_gfx_anim_get_current_anim_id added to get current anim id.
**
** CMS Rev 1.3     08-JULY-16   APERUMAL
** RTC 639042: Porsche Misra warning Fix
**
** CMS Rev 1.4      26-Jul-2016    CMUTHUSA
** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
**
** CMS Rev 1.5      16-Jun-2017    arajase2
** 890525: Compilation error in MISRA warning fix - Animation core

**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
