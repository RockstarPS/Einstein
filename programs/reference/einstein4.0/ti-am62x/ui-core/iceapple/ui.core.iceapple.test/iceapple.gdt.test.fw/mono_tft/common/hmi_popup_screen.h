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
** Name:           hmi_popup_screen.h
**
** Description:
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_popup_core_if.h"


/* Keypad button events config */
#define	ButtonStateActive		  0x01	    /*Press (Evt Trigg)*/
/* LSH_GET_COMMAND(id, sts) (((id) << 4)|(sts)) so LEFT_SHIFT value is 4 */
#define BUTTON_ID_LEFT_SHIFT  ((UINT8)4)
#define KEYPAD_0_IN           ((((UINT16)BTN_ID_0) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_1_IN           ((((UINT16)BTN_ID_1) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_2_IN           ((((UINT16)BTN_ID_2) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_3_IN           ((((UINT16)BTN_ID_3) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_4_IN           ((((UINT16)BTN_ID_4) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_5_IN           ((((UINT16)BTN_ID_5) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_6_IN           ((((UINT16)BTN_ID_6) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_7_IN           ((((UINT16)BTN_ID_7) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_8_IN           ((((UINT16)BTN_ID_8) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)
#define KEYPAD_9_IN           ((((UINT16)BTN_ID_9) << BUTTON_ID_LEFT_SHIFT)  | (UINT8)ButtonStateActive)


UINT8 scr_popup_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
void scr_popup_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void scr_popup_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP);

