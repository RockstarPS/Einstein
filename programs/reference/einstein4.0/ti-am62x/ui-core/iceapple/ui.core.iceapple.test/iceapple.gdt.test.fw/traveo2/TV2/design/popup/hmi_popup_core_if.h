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
**==========================================================================*/

/*============================================================================
**
** Name:           hmi_popup_core_if.h
**
** Description:
                   This file is the Interface header File for the Popup C
                   ore 01. Application must include this file to interact
                    with the Popup Core Component.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/

#ifndef HMI_POPUP_CORE_IF_H
#define HMI_POPUP_CORE_IF_H

#include "hmi_logic_state_handler.h"
#include "hmi_language_interface.h"




#define L_POPUP_LAYER1_ID                                                       (0U)
#define POPUP_MAX_LAYERS                                                        (1U)

typedef UINT8 POPUP_LAYER_ID;

typedef enum
{
    POPUP_CLOSED_ON_TIMEOUT_EVT,
    POPUP_CLOSED_ON_CANCEL_EVT,
    POPUP_CLOSED_ON_OK_EVT,
    POPUP_CLOSED_ON_DEMAND_EVT,
#ifdef POPUP_TYPE_ACK
    POPUP_CLOSED_ON_ACK_EVT,
#endif
    POPUP_CLOSED_ON_MAX_ENTRY_EVT,
#ifdef POPUP_TYPE_PROGRESSBAR
    POPUP_PROGRESS_BAR_INC_EVT,
#endif
    POPUP_MIN_TIME_EXPIRE_EVT,
    POPUP_INVALID_EVT
} POPUP_EVENTS;

#define POPUP_ANIM_MAX_ID 0x0FF
#define POPUP_ANIMATION_ID UINT8
#define CHAR_TYPE (UINT8)
#define POPUP_BTN_INVALID (0xFFFF)

/***************************************************************/
/*               Button Handler Return Types                   */
/***************************************************************/

#define POPUP_BTN_ABSORBED   (LSH_STATUS_ABSORBED)
#define POPUP_BTN_ACTION     (LSH_STATUS_ACTION)
#define POPUP_BTN_NONE       (LSH_STATUS_NONE)
#define POPUP_BTN_BLOCK      (0x80)

/* Typedefinition of the Popup Id's to be used by the application */

#define L1_UI_POPUP_INFO_HDR_GRPICONS_10s                                       (0U)
#define L_POPUP_MAX_COUNT                                                       (1U)

typedef UINT8 POPUP_ID;

#define    POPUP_STATE_ACTIVE		   (0U)
#define    POPUP_STATE_INACTIVE		   (1U)
#define    POPUP_STATE_INVALID		   (2U)

typedef UINT8 POPUP_STATES;

typedef struct
{
    POPUP_ID total_popup_count;
    POPUP_ID active_popup_id;
}POPUP_INFO_DATA_TYPE;

#ifdef POPUP_TYPE_KEYPAD
typedef struct
{
    POPUP_ID popup_id;
    UINT16 btn_id;
    UINT8 btn_state;
}POPUP_KEYPAD_SET_TYPE;

typedef struct
{
    POPUP_ID popup_id;
    HMI_CHAR* entry;
    UINT8 len_U8;
}POPUP_KEYPAD_CONTENT_TYPE;
#endif

#ifdef POPUP_TYPE_PROGRESSBAR
typedef struct
{
    POPUP_ID popup_id;
    UINT8* cnt_ptr_U8;
}POPUP_PROGRESS_COUNT_TYPE;
#endif

#define    POPUP_CONTEXT_INPUT          (0U)
#define    POPUP_CONTEXT_DISPLAY        (1U)

typedef UINT8 POPUP_CONTEXT_TYPE;

typedef void (POPUP_EVENT_HANDLER_T)(POPUP_EVENTS);
#ifndef POPUP_EVENT_HANDLER_NULL
#define POPUP_EVENT_HANDLER_NULL   ((POPUP_EVENT_HANDLER_T *)((void *)0))
#endif
#ifdef POPUP_TYPE_KEYPAD
typedef BOOLEAN(POPUP_VALIDATE_HANDLER_T)(POPUP_KEYPAD_CONTENT_TYPE*);
#ifndef POPUP_VALIDATE_HANDLER_NULL
#define POPUP_VALIDATE_HANDLER_NULL  ((POPUP_VALIDATE_HANDLER_T *) ((void *)0))
#endif
#endif

/* Function Interface to the Application */
/*********************************************************************************************
 * Layer                : Layer1
 * Event Handler        : hmi_popup_core_layer1_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer1_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer1_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer1_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T* p_event_hndl_status_SP);
void hmi_popup_core_layer1_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T* p_focus_hndl_status_SP);
void hmi_popup_core_layer1_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T* p_presn_hndl_status_SP);

/*********************************************************************************
 *Function Name    : hmi_popup_core_initialize
 *Description      : This function should be called during COLD, WARM, WAKEUP
**********************************************************************************/
void hmi_popup_core_initialize(void);

/**********************************************************************************
 *Function Name    : hmi_popup_core_close_all_popup
 *Description      : This function should be called to close all popup in a
 *                   layer or popup core(Max popup layer id)
 * Inputs/Outputs  : p_layer_id - Layer id of popups to be closed.
 *                   POPUP_MAX_LAYERS  - For all popups of popupcore to close.
**********************************************************************************/
extern void hmi_popup_core_close_all_popup(POPUP_LAYER_ID p_layer_id);

/**********************************************************************************
 *Function Name    : hmi_popup_core_timeout_callback
 *Description      : This function should be called by the timer module when a
 *                   a timer started by the popup is expired. The popup core is
 *                   notified of the expiery with an event.
 * Inputs/Outputs  : p_timer_id - Timer that is expired
 *                   p_event  - Event provided suring the start of the timer
**********************************************************************************/
extern void hmi_popup_core_timeout_callback(UINT16 p_timer_id, UINT16 p_event);

#ifdef POPUP_TYPE_KEYPAD
extern UINT8 hmi_popup_core_get_keypad_content(POPUP_KEYPAD_CONTENT_TYPE* const p_keypad_content);
extern void hmi_popup_core_set_keypad_entry(POPUP_KEYPAD_SET_TYPE const* const p_keypad_set);
#endif

extern BOOLEAN hmi_popup_core_start_timer(POPUP_ID p_popup_id);
extern BOOLEAN hmi_popup_core_stop_timer(POPUP_ID p_popup_id);

#ifdef POPUP_TYPE_PROGRESSBAR
extern BOOLEAN hmi_popup_core_get_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE* p_progress);
extern BOOLEAN hmi_popup_core_set_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE const* const p_progress);
#endif

/**********************************************************************************
 *Function Name    : hmi_popup_core_rx_button_handler
 *                   hmi_popup_core_focus_handler
 *                   hmi_popup_core_presentation_handler
 *Description      : Internal interface to hmi_popup_core_if.c
**********************************************************************************/
UINT8 hmi_popup_core_rx_button_handler(POPUP_LAYER_ID p_layer_id, LSH_EVENT_HANDLER_STATUS_T* p_event_hndl_status_SP);
void hmi_popup_core_focus_handler(POPUP_LAYER_ID p_layer, LSH_FOCUS_HANDLER_STATUS_T* p_focus_hndl_status_SP);
void hmi_popup_core_presentation_handler(POPUP_LAYER_ID p_layer, LSH_PRESN_HANDLER_STATUS_T* p_presn_hndl_status_SP);
void hmi_popup_core_task(void);


#ifdef POPUP_TYPE_KEYPAD
/**********************************************************************************
 *Function Name    : hmi_popup_core_get_keypad_content



 *Description      : Interface to set the key pad entry variable
                     Care should be taken while writing as the string will not be validated

**********************************************************************************/
UINT8 hmi_popup_core_set_keypad_content(POPUP_KEYPAD_CONTENT_TYPE const* const p_keypad_content);
#endif


/**********************************************************************************
 ** Function Name    : hmi_popup_core_remap_button_events()
 ** Visibility       : Global, Interface to the Popup Core Application
 ** Description:      1. This function allows a logic state to remap a registered
 **                      p_button_id_U16 to a new logic state p_target_ls_id_U8.
 **                      This can be used on situations like a source_state opens a
 **                      a higher priority p_target_ls_id based a p_button_id_U16 press
 **                      and source_state expects the the p_target_ls_id to preocess the
 **                      further button events related to p_button_id_U16.
 **                   2. If the target state is specified as LSH_NUMBER_OF_LOGIC_STATES
 **                      then the button slot corresponding to p_button_id_U16 is
 **                      freed so that further events of the p_button_id_U16 is
 **                      redistributed.
**********************************************************************************/
void hmi_popup_core_remap_button_events(UINT16 p_button_id_U16, POPUP_ID p_popup_id);

/*============================================================================
 ** Function Name    : hmi_popup_core_get_active_popup_id()
 ** Visibility       : Global, Interface to the Popup Core Application
 ** Description      : This function returns the raw popup id of the active
 **                    popup in a given layer
 ** Invocation       : Application
 **==========================================================================*/
extern void hmi_popup_core_get_popup_info(POPUP_INFO_DATA_TYPE* const p_info_data, POPUP_LAYER_ID p_layer_id);
extern BOOLEAN hmi_popup_core_inspect_popup_active(POPUP_ID p_popup_id, POPUP_CONTEXT_TYPE p_context_type);

extern void hmi_app_popup_core_update_handler(POPUP_STATES p_popup_state);

extern UINT8 hmi_popup_core_activate_popup(POPUP_ID p_popup_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED 
    , POPUP_ANIMATION_ID p_anim_id
#endif
);
extern UINT8 hmi_popup_core_deactivate_popup(POPUP_ID p_popup_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED 
    , POPUP_ANIMATION_ID p_anim_id
#endif
);
extern UINT8 hmi_popup_core_forced_deactivate_popup(POPUP_ID p_popup_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED 
    , POPUP_ANIMATION_ID p_anim_id
#endif
);




#endif  /* #ifndef  HMI_POPUP_CORE_IF_C */

/*****************************START OF CHECK LIST DETAILS*****************************
1 . Checked all popup screen id priority(GDT)  in a popup layer is same priority in GDT.
2 . Checked Layer_0 is high priority and orderly follows as layer_1, layer_3 etc.
3 . Checked all popup in a layer is configured sequentially as its priority from high to low.
4 . Checked all timer id generated from popup tool is configured properly in os / timer support file.
5 . Checked timer macro is configured properly for running, cleared etc.
6 . Checked each group popup is configured together sequentially one by one(group number is sequential for each layer from group 1 to N).
7 . Checked all popup which has requirement to deactivate on button events is configured as ack popup instead of info popup.
8 . Checked all progress bar requirement in the project is configured as progress bar popup.
9 . Checked newly added popup is inserted at proper place holder.
10. Checked application has implemented all call back function configured in the tool.
11. Checked total popup not exceeded 255.
12. Checked all popup in a layer is configured with same corresponding popup layer presentation, focus and event handler in GDT.
13. Checked popup call back event handler with popup events has not activated or deactivated popup( which might leads to recursive).
*****************************END OF CHECK LIST DETAILS*****************************/

