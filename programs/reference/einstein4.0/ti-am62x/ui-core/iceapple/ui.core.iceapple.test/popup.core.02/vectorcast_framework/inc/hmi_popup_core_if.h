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

#include "hmi_language_interface.h"

#ifndef  HMI_POPUP_CORE_IF_H
#include "hmi_logic_state_handler.h"
#define  HMI_POPUP_CORE_IF_H
#ifndef HMI_POPUP_CORE_IF_C

#define EXTERN_pfx extern
#else
#define EXTERN_pfx 
#endif

#define POPUP_CONFIGURATOR_VERSION_1_00_17

typedef enum
{
    L_POPUP_LAYER0_ID,
    L_POPUP_LAYER1_ID,
    L_POPUP_LAYER5_ID,
    L_POPUP_LAYER9_ID,
    L_POPUP_LAYER10_ID,
    POPUP_MAX_LAYERS

}POPUP_LAYER_ID;

typedef enum
{
    POPUP_CLOSED_ON_TIMEOUT_EVT,
    POPUP_CLOSED_ON_CANCEL_EVT,
    POPUP_CLOSED_ON_OK_EVT,
    POPUP_CLOSED_ON_DEMAND_EVT,
    POPUP_CLOSED_ON_ACK_EVT,
    POPUP_CLOSED_ON_MAX_ENTRY_EVT,
    POPUP_PROGRESS_BAR_INC_EVT,
    POPUP_MIN_TIME_EXPIRE_EVT,
    POPUP_INVALID_EVT

} POPUP_EVENTS;

#define POPUP_ANIM_MAX_ID 0x0FF
#define POPUP_ANIMATION_ID UINT8
#define CHAR_TYPE (UINT8)
#define POPUP_MAX_KEYPAD_CONFIG_ENTRY  ( 2 )
#define POPUP_MAX_CHAR_ENTERY_PER_BUTTON  ( 1 )
#define POPUP_MAX_KEYPAD_CONFIG_ENTRY  ( 2 )
#define POPUP_MAX_CHAR_ENTERY_PER_BUTTON  ( 1 )
#define POPUP_MAX_KEYPAD_CONFIG_ENTRY  ( 2 )
#define POPUP_MAX_CHAR_ENTERY_PER_BUTTON  ( 1 )
#define POPUP_BTN_INVALID (0xFFFF)

/***************************************************************/
/*               Button Handler Return Types                   */
/***************************************************************/

#define POPUP_BTN_ABSORBED   (LSH_STATUS_ABSORBED)
#define POPUP_BTN_ACTION     (LSH_STATUS_ACTION)
#define POPUP_BTN_NONE       (LSH_STATUS_NONE)
#define POPUP_BTN_BLOCK      (0x80)

/* Typedefinition of the Popup Id's to be used by the application */

typedef enum
{
    L0_POPUP_INFO_0_0,
    L0_POPUP_INFO_0_1,
    L0_POPUP_INFO_0_2,
    L1_POPUP_PROG_1_0,
    L1_POPUP_KEYPAD_1_1,
    L1_POPUP_INFO_1_2,
    L1_POPUP_ACK_1_3,
    L1_POPUP_INFO_1_4,
    L5_POPUP_ACK_5_0,
    L5_POPUP_KEYPAD_5_1,
    L5_POPUP_PROG_5_2,
    L5_POPUP_ACK_5_3,
    L5_POPUP_KEYPAD_5_4,
    L9_POPUP_INFO_9_0,
    L10_POPUP_INFO_10_0,
    L10_POPUP_INFO_10_1,
    L10_POPUP_INFO_10_2,
    L10_POPUP_KEYPAD_10_3,
    L_POPUP_MAX_COUNT
}POPUP_ID;

typedef enum
{
    POPUP_STATE_ACTIVE,
    POPUP_STATE_INACTIVE,
    POPUP_STATE_INVALID
}POPUP_STATES;

typedef struct
{
    POPUP_ID total_popup_count;
    POPUP_ID active_popup_id;
}POPUP_INFO_DATA_TYPE;

typedef struct
{
    POPUP_ID popup_id;
    UINT16 btn_id;
    UINT8 btn_state;
}POPUP_KEYPAD_SET_TYPE;

typedef struct
{
    POPUP_ID popup_id;
    HMI_CHAR *entry;
    UINT8 len_U8;
}POPUP_KEYPAD_CONTENT_TYPE;

typedef struct
{
    POPUP_ID popup_id;
    UINT8 *cnt_ptr_U8; 
}POPUP_PROGRESS_COUNT_TYPE;

typedef enum
{
    POPUP_CONTEXT_INPUT,
    POPUP_CONTEXT_DISPLAY
}POPUP_CONTEXT_TYPE;

#ifndef POPUP_EVENT_HANDLER_NULL
typedef void (POPUP_EVENT_HANDLER_T)(POPUP_EVENTS);
#define POPUP_EVENT_HANDLER_NULL   ((POPUP_EVENT_HANDLER_T *)0)

typedef BOOLEAN (POPUP_VALIDATE_HANDLER_T)(POPUP_KEYPAD_CONTENT_TYPE *);
#define POPUP_VALIDATE_HANDLER_NULL  ((POPUP_VALIDATE_HANDLER_T *) 0)
#endif

/* Function Interface to the Application */
/*********************************************************************************************
 * Layer                : Layer0
 * Event Handler        : hmi_popup_core_layer0_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer0_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer0_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer0_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T  *p_event_hndl_status_SP);
void hmi_popup_core_layer0_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_layer0_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);

/*********************************************************************************************
 * Layer                : Layer1
 * Event Handler        : hmi_popup_core_layer1_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer1_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer1_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer1_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T  *p_event_hndl_status_SP);
void hmi_popup_core_layer1_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_layer1_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);

/*********************************************************************************************
 * Layer                : Layer5
 * Event Handler        : hmi_popup_core_layer5_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer5_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer5_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer5_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T  *p_event_hndl_status_SP);
void hmi_popup_core_layer5_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_layer5_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);

/*********************************************************************************************
 * Layer                : Layer9
 * Event Handler        : hmi_popup_core_layer9_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer9_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer9_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer9_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T  *p_event_hndl_status_SP);
void hmi_popup_core_layer9_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_layer9_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);

/*********************************************************************************************
 * Layer                : Layer10
 * Event Handler        : hmi_popup_core_layer10_rx_button_handler
 * Focus Handler        : hmi_popup_core_layer10_disp_foucus_handler
 * Presentation Handler : hmi_popup_core_layer10_disp_presentation_handler
*********************************************************************************************/
UINT8 hmi_popup_core_layer10_rx_button_handler(LSH_EVENT_HANDLER_STATUS_T  *p_event_hndl_status_SP);
void hmi_popup_core_layer10_disp_foucus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_layer10_disp_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);


/*********************************************************************************
 *Function Name    : hmi_popup_core_initialize
 *Description      : This function should be called during COLD, WARM, WAKEUP
**********************************************************************************/
void hmi_popup_core_initialize(void);

/**********************************************************************************
 *Function Name    : hmi_popup_core_activate_popup
 *                 : hmi_popup_core_deactivate_popup
 *                 : hmi_popup_core_forced_deactivate_popup
 *Description      : This function should be called to active/ deactivate a particular
 *                   popup.
 * Inputs/Outputs  : p_popup_id - Enumeration of the Popup to be activated
 *                   p_anim_id  - Animation ID to perform 
**********************************************************************************/
extern UINT8 hmi_popup_core_activate_popup(POPUP_ID p_popup_id, POPUP_ANIMATION_ID p_anim_id);
extern UINT8 hmi_popup_core_deactivate_popup(POPUP_ID p_popup_id, POPUP_ANIMATION_ID p_anim_id);
extern UINT8 hmi_popup_core_forced_deactivate_popup(POPUP_ID p_popup_id, POPUP_ANIMATION_ID p_anim_id);

/**********************************************************************************
 *Function Name    : hmi_popup_core_timeout_callback
 *Description      : This function should be called by the timer module when a 
 *                   a timer started by the popup is expired. The popup core is 
 *                   notified of the expiery with an event.
 * Inputs/Outputs  : p_timer_id - Timer that is expired
 *                   p_event  - Event provided suring the start of the timer 
**********************************************************************************/
void hmi_popup_core_timeout_callback(UINT16 p_timer_id, UINT16 p_event);

extern UINT8 hmi_popup_core_get_keypad_content(POPUP_KEYPAD_CONTENT_TYPE *const p_keypad_content);
extern void hmi_popup_core_set_keypad_entry(POPUP_KEYPAD_SET_TYPE const * const p_keypad_set);
extern BOOLEAN hmi_popup_core_start_timer(POPUP_ID p_popup_id);
extern BOOLEAN hmi_popup_core_stop_timer(POPUP_ID p_popup_id);

extern BOOLEAN hmi_popup_core_get_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE *p_progress);
extern BOOLEAN hmi_popup_core_set_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE const * const p_progress);

/**********************************************************************************
 *Function Name    : hmi_popup_core_rx_button_handler
 *                   hmi_popup_core_focus_handler
 *                   hmi_popup_core_presentation_handler
 *Description      : Internal interface to hmi_popup_core_if.c
**********************************************************************************/
UINT8 hmi_popup_core_rx_button_handler(POPUP_LAYER_ID p_layer_id, LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
void hmi_popup_core_focus_handler(POPUP_LAYER_ID p_layer,LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
void hmi_popup_core_presentation_handler(POPUP_LAYER_ID p_layer, LSH_PRESN_HANDLER_STATUS_T const * const p_presn_hndl_status_SP);
void hmi_popup_core_task(void);


/**********************************************************************************
 *Function Name    : hmi_popup_core_get_keypad_content



 *Description      : Interface to set the key pad entry variable
                     Care should be taken while writing as the string will not be validated

**********************************************************************************/
UINT8 hmi_popup_core_set_keypad_content(POPUP_KEYPAD_CONTENT_TYPE const * const p_keypad_content);



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
void hmi_popup_core_remap_button_events(UINT16 p_button_id_U16, POPUP_ID p_popup_id );

/*============================================================================
 ** Function Name    : hmi_popup_core_get_active_popup_id()
 ** Visibility       : Global, Interface to the Popup Core Application
 ** Description      : This function returns the raw popup id of the active
 **                    popup in a given layer
 ** Invocation       : Application
 **==========================================================================*/
extern void hmi_popup_core_get_popup_info(POPUP_INFO_DATA_TYPE * const p_info_data, POPUP_LAYER_ID p_layer_id);
extern BOOLEAN hmi_popup_core_inspect_popup_active(POPUP_ID p_popup_id, POPUP_CONTEXT_TYPE p_context_type);

extern void hmi_app_popup_core_update_handler(POPUP_STATES p_popup_state);

#ifndef LSH_ANIMATION_SUPPORT_ENABLED
#ifndef HMI_POPUP_CORE_C
#define hmi_popup_core_activate_popup(x) hmi_popup_core_activate_popup(x,POPUP_ANIM_MAX_ID)
#define hmi_popup_core_deactivate_popup(x) hmi_popup_core_deactivate_popup(x,POPUP_ANIM_MAX_ID)
#define hmi_popup_core_forced_deactivate_popup(x) hmi_popup_core_forced_deactivate_popup(x,POPUP_ANIM_MAX_ID)
#endif
#endif
extern UINT8 hmi_popup_info_0_0_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_0_0_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_0_0_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_info_0_0_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_info_0_1_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_0_1_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_0_1_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_info_0_1_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_info_0_2_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_0_2_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_0_2_presentation_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_info_0_2_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_prog_1_0_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_prog_1_0_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_prog_1_0_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_info_1_0_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_keypad_1_1_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_keypad_1_1_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_keypad_1_1_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_keypad_1_1_popupevent_handler(POPUP_EVENTS p_event_e);
extern BOOLEAN hmi_popup_validation_hndler(POPUP_KEYPAD_CONTENT_TYPE *p_keypad_validate);
extern UINT8 hmi_popup_info_1_2_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_1_2_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_1_2_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_info_1_2_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_ack_1_3_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_ack_1_3_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_iack_1_3_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_iack_1_3_popupevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_info_0_0_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern BOOLEAN hmi_popup_validation_hndler(POPUP_KEYPAD_CONTENT_TYPE *p_keypad_validate);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern void hmi_popup_default_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern UINT8 hmi_popup_keypad_10_0_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_keypad_10_0_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_keypad_10_0_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_keypad_10_0_ppevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_keypad_10_1_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_10_1_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_10_1_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_keypad_10_1_ppevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_keypad_10_2_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_info_10_2_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_info_10_2_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_keypad_10_2_ppevent_handler(POPUP_EVENTS p_event_e);
extern UINT8 hmi_popup_keypad_10_3_event_handler(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP);
extern void hmi_popup_keypad_10_3_focus_handler(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP);
extern  void  hmi_popup_keypad_10_3_present_handler(LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP);
extern void hmi_popup_keypad_10_3_ppevent_handler(POPUP_EVENTS p_event_e);
extern BOOLEAN hmi_popup_validation_hndler(POPUP_KEYPAD_CONTENT_TYPE *p_keypad_validate);
extern UINT8 AppHandler(LSH_STATE_ID_T p_logic_state_id, UINT8 p_anim_id, UINT8 p_client_id, POPUP_LAYER_ID p_layer_id);



#undef EXTERN_pfx
#endif  /* #ifndef  HMI_POPUP_CORE_IF_C */

