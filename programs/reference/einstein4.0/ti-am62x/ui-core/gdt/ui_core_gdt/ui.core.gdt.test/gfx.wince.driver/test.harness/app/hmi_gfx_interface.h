/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2010. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_gfx_interface.h
**
** Description:    Interface file for the graphics interface
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_INTERFACE_H
#define HMI_GFX_INTERFACE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_interface.cfg"
#include "hmi_gfx_driver.h"
#include "hmi_gfx_manager.h"
#include "hmi_language_identifiers.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

typedef enum
{
   HMI_GFX_IF_NULL_CMD,
   HMI_GFX_IF_SEND_EVENT_CMD,
#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
   HMI_GFX_IF_SEND_TEXT_CMD,
   HMI_GFX_IF_SEND_SID_CMD,
#endif
#if HMI_GFX_IF_NEED_FADE_CMD > 0
   HMI_GFX_IF_FADE_IN_CMD,
#endif
#if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
   HMI_GFX_IF_VIDEO_ENABLE_CMD,
   HMI_GFX_IF_VIDEO_DISABLE_CMD,
#endif
   HMI_GFX_IF_FLUSH_OUTPUT_CMD,
   HMI_GFX_IF_FLUSH_INLINE_CMD,
   HMI_GFX_IF_NUM_CMDS
}GFX_IF_CMD_T;

#if HMI_GFX_IF_QUEUE_SIZE > 256
   typedef UINT16 GFX_IF_CMD_INDEX_T;
#else
   typedef UINT8  GFX_IF_CMD_INDEX_T;
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

extern void hmi_gfx_if_initialize(UINT8 p_cold_init_BOOL);
extern void hmi_gfx_if_exit(void);


#if HMI_GFX_IF_NEED_FADE_CMD > 0
  void hmi_gfx_if_send_fade_cmd(UINT16 p_fadein_config_id_U16);
#endif /* #if HMI_GFX_IF_NEED_FADE_CMD > 0 */

void hmi_gfx_if_send_data_cmd(GFX_ELEMENT_ID_T p_element_id, SINT32 p_element_data);

#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
  void hmi_gfx_if_send_text_cmd(GFX_ELEMENT_ID_T p_element_id, GFX_CHAR const * p_string);
  void hmi_gfx_if_send_sid_cmd(GFX_ELEMENT_ID_T p_element_id, LANG_SID_T p_sid_U32);
#endif /* #if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0 */

void hmi_gfx_if_update_inline_cmd(UINT8 p_precopy_U8);
void hmi_gfx_if_update_cmd(void);

#if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
  void hmi_gfx_if_enable_video_in_cmd(void);
  void hmi_gfx_if_disable_video_in_cmd(void);
#endif /* #if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0 */

void Graphics_Task(void);

UINT8 hmi_gfx_if_get_update_pending(void);

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
** Rev 1.3          28-SEP-10    VSARAVA2
** SID command parameter data type changed from U16 to LANG_SID_T.
**
** Rev 1.2          16-APR-10    GYUVAMAT
** Fixed QAC warnings.
**
** Rev 1.1          28-MAR-10    GRAMKUMA
** Changed HMI_SNPRINTF definition from wprintf to swprintf.
**
** Rev 1.0          03-MAR-10    EMANOJ1
** Creation.
**==========================================================================*/

#if defined(__cplusplus)
} /* extern "C" */
#endif

/* end of file =============================================================*/
#endif
