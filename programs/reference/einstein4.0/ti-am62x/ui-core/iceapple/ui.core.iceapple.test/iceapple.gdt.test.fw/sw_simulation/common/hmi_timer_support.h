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
** Name:           hmi_timer_support.h
**
** Description:
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_TIMER_SUPPORT_H
#define HMI_TIMER_SUPPORT_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"



/* Message core macros */
#define   TIMER_CLEAR       0x00
#define   TIMER_EXPIRED     0x02
#define   TIMER_RUNNING     0x80

#define HMI_TIMER_CLEAR                 ((UINT8)0x00)
#define HMI_TIMER_EXPIRED               ((UINT8)0x02)
#define HMI_TIMER_RUNNING               ((UINT8)0x80)
#define HMI_TIMER_NOT_RUNNING           HMI_TIMER_CLEAR


typedef enum
{
	GUI_POPUP_LAYER0_TMR_ID,
	GUI_POPUP_LAYER1_TMR_ID,
	HMI_NO_OF_TIMERS
}TIMER_ID_TYPE;

typedef enum
{
  HMI_MENU_START_TIMER_ID,
  HMI_MENU_STOP_TIMER_ID,
  HMI_MENU_OPEN_TIMER_ID,
  HMI_MENU_WAIT_TIMER_ID,
	HMI_NO_OF_MENU_TIMERS
}MENU_TIMER_ID_TYPE;

void hmi_popup_core_support_timer_start(TIMER_ID_TYPE timer_id, UINT32 timeout_count, UINT16 p_evt_U16);
void hmi_popup_core_support_timer_stop(TIMER_ID_TYPE timer_id);
UINT8 hmi_popup_core_support_timer_check(TIMER_ID_TYPE timer_id);
void hmi_msg_core_support_timer_start(UINT32 timeout_count,TIMER_ID_TYPE timer_id);
void hmi_msg_core_support_timer_stop(TIMER_ID_TYPE timer_id);
UINT8 hmi_msg_core_support_timer_check(TIMER_ID_TYPE timer_id);
void hmi_menu_core_start_timer(UINT8 menu_id, MENU_TIMER_ID_TYPE timer_id, UINT32 timeout_count);
void hmi_menu_core_stop_timer(UINT menu_id, MENU_TIMER_ID_TYPE timer_id);

#endif