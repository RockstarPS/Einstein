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
** Name:           hmiapp_stub.h
**
** Description:    Public header file for timer_support functionality
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/

#ifndef HMIAPP_STUB_H
#define HMIAPP_STUB_H

#include "swtmr.h"
#include "hmi_SIF.h"
#include "hmi_msgDefinition.h"

#define EXTERN  extern

#define hmi_msg_sequence_display_KSWTIMER 50
#define hmi_msg_sequence_hold_KSWTIMER 100
#define hmi_msg_sequence_ack_KSWTIMWE 0
#define hmi_msg_sequence_1sec_KSWTIMWE 600
#define hmi_msg_sequence_msgq_1sec_KSWTIMER 0
#define hmi_msg_sequence_ind_KSWTIMWE 0
#define hmi_msg_sequence_cycle_KSWTIMER 0
#define hmi_msg_sequence_oldwrng_1sec_KSWTIMER 0
#define hmi_msg_sequence_Ackwrng_1sec_KSWTIMER 0

#  ifndef eUSMMenuTimeoutTimer
#   define eUSMMenuTimeoutTimer (37U)
#  endif

#define hmi_menu_start_KSWTIMER	112

#define MSG_SEQUENCE_NOTIFY


#define HM_MS(x)            ( ((UINT16)(x) / (UINT16)4u) )

#define TO_MILLISEC(x)      ( TIMER_13BIT_BASE_4MS | HM_MS(x) )

EXTERN void ui_msg_show_new_msg_notification(const MSG_VIEWINFO_T* p_msg_info_S);
EXTERN void ui_msg_hide_msg_notification(eMessageIdentity p_MsgId_E);

#define UP_IN                   0
#define RIGHT_IN                   0
#define LEFT_IN                   0
#define DOWN_IN                   0
#define OK_IN                   0

#define CLR_DUR_TRANS_TO_OFF 	(UINT8)(0x02)
#define NO 						(UINT8)(0x00)
#define YES 					(UINT8)(0x01)

#define UI_U16_INVALID_VALUE        (UINT16)0xFFFF


typedef struct _UI_WARNING_DATA_T
{
    UI_WARNING_STATUS_T status;         /**< current warning status */
    UI_WARNING_EVENT_T event;           /**< warning event */
    UINT16 payload;                     /**< payload, 0xFFFF invalid */
} UI_WARNING_DATA_T, * UI_PTR_WARNING_DATA_T;


/* Stores the WARNING ID'S and corresponding properties*/
typedef struct _UI_WARNING_DETAIL_DATA_T
{
    void (*warndetailptr)(UINT16* p_warning_data_ptr);         /* Payload Callback */
    void (*warnackcallback)(UI_WARNING_ID_T p_warning_id_T);              /* Acknowledgement callback */
    UINT8  l_ignition_trans_clear_U8;                                     /* Transition clear */
    UINT8  l_master_warning_lamp_U8;                                      /* Master Warning Lamp */
    UINT8  l_hide_interrupted_popup_redisplay;                            /* popup will not be re-displayed when it is interrupted by another  */
    UINT8  l_popup_display_once_ign_cycle;								  /* popup to be displayed only once at IGN cycle */
} UI_WARNING_DETAIL_DATA_T, * APP_UI_PTR_WARNING_DATA_T;

#endif
