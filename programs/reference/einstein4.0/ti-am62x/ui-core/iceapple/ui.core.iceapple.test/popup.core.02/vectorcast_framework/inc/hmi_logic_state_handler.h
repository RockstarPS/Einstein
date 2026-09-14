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
** Name:           hmi_logic_state_handler.h
**
** Description:    Interface header for the logic state handler.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_LOGIC_STATE_HANDLER_H
#define HMI_LOGIC_STATE_HANDLER_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_logic_state_handler.cfg"
#include "hmi_logic_state_handler.inc"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*
** Internal status definition used by LSH to notify the event, focus and
** presentation handlers of status changes.
** LSH_DEACTIVATED_STATUS - Indicates a state has been deactivated.
** LSH_ACTIVATED_STATUS   - Indicates a state has been activated
** LSH_LOST_FOCUS_STATUS  - Indicates a state has lost its focus
** LSH_GOT_FOCUS_STATUS   - Indicates a state has regained focus
** LSH_INVALID_STATUS     - Indicates an invalid situation.
*/
#define LSH_LOST_FOCUS_STATUS       (0x01)
#define LSH_GOT_FOCUS_STATUS        (0x02)
#define LSH_DEACTIVATED_STATUS      (0x04)
#define LSH_ACTIVATED_STATUS        (0x08)
#define LSH_REFRESH_STATUS          (0x0C)
#define LSH_ANIM_COMPLETE_STATUS    (0x10)
#define LSH_ANIM_STARTED_STATUS     (0x20)
#define LSH_UNASSIGNED_STATUS       (0x40)
#define LSH_INVALID_STATUS          (0x80) /*0x80 is a reserved for the INVALID so don't use it */
#define LSH_DEACT_PENDING_STATUS    (LSH_DEACTIVATED_STATUS|LSH_ANIM_STARTED_STATUS)

/*
** LSH_ALL_LOGIC_STATES macro represents all the logic states.
** So when ever passing this as a logic state ID to supported API,
** it means that the function has to do the requested action on all
** the active logic states.
*/
#define LSH_ALL_LOGIC_STATES     (LSH_NUMBER_OF_LOGIC_STATES)

/*
** LSH_INVALID_CLIENT_ID macro represents the invalid Client ID.
** So when ever passing this as a Client ID to supported LSH API,
** it means that the function has been called without the calling 
** client's Information, so that invalid ID shall be stored in LSH Stack.
*/

/*
** Specifies the status value that can be used to represent the Freeze state.
** This needs to be an unused p_button_event_U8 value to avoid clashes.
** So the freeze status is assigned 0xFF and the application need to make sure
** that they don't use 0xFF state for a button.
*/
#define LSH_BUTTON_FREEZE_STATUS (0xFF)

/*
** Following is the button process status indication values. These are bit encoded
** so multiple status can be returned to the caller.
** The status shall be used for all application button event handler functions.
** LSH_STATUS_ABSORBED - If this bit is set in the return status it indicates that
**                       the button is absorbed by the button processing function
**                       and no further actions need to be performed.
**                       If this bit is clear then it indicates that button is not
**                       absorbed by the button event handling function and it shall
**                       be passed on to next low priority level for processing.
** LSH_STATUS_ACTION   - If this bit is set it indicates that the button event handler
**                       has performed some actions for the event.
** LSH_STATUS_NONE     - None of the above bits are set. i.e. Button is not absorbed
**                       and no action also taken. So needs to pass on to next low
**                       priority display.
*/
#define LSH_STATUS_ABSORBED      (0x01)
#define LSH_STATUS_ACTION        (0x02)
#define LSH_STATUS_NONE          (0x00)

/*
** Event handlers shall follow the prototype
** UINT8 hmi_<component_short_name>_rx_button_event(UINT16 p_button_cmd_U8);
** returns status  - LSH_STATUS_ABSORBED, LSH_STATUS_ACTION, LSH_STATUS_NONE
** p_button_cmd_U8 - is encoded as 0xCCCS, where
**                   CCC - 0x000 to 0xFFE is the button identifier or any id defined
**                         by the application.
**                         0xFFF is reserved by LSH to define its internal events.
**                   S   - 0x0 to 0xF is the button status (press, hold release etc)
**                         Status 0x0 is reserved by LSH to represent an inactive
**                         button.
**                   This way button id 0x000 can generate commands from
**                   0x0000 to 0x000F.
** When it is necessary to configure null event handler, use LSH_NULL_EVENT_HANDLER
*/
typedef UINT8 (LSH_EVENT_HANDLER_T)(LSH_EVENT_HANDLER_STATUS_T *);
#define LSH_NULL_EVENT_HANDLER   ((LSH_EVENT_HANDLER_T *)0)
#define LSH_RESERVED_ID          (0xFFF)
/*
   LSH_BTN_ID_MASK_CFG
                      - LSH_ID_8_BIT_MASK  
                        currently used by TVM program. Logic id is 8 bit.
                      - LSH_ID_12_BIT_MASK
                        currently used by other than TVM program. Logic id is 12 bit.
                        Animation mask requirement tailored to TVM which will be analysed later
*/
#define LSH_ID_8_BIT_MASK  0
#define LSH_ID_12_BIT_MASK 1

#ifndef LSH_BTN_ID_MASK_CFG
  #error "LSH_BTN_ID_MASK_CFG configuration is not defined for hmi_logic_state_handler.h"
#else
#if (LSH_BTN_ID_MASK_CFG == LSH_ID_8_BIT_MASK)
/* TVM programs */
  #define LSH_ID_MASK              (0xFF00)  /* 8bits for Button Ids*/
  #define LSH_ANIM_MASK            (0x0080)  /* Most significant bit of the status byte will point to Anim Mask */
  #define LSH_STATUS_MASK          (0x007F)  /* remaining 7bits will point to the button status */
  #define LSH_GET_ID(x)            ((x & LSH_ID_MASK) >> 8)
  #define LSH_IS_ANIM(x)           ((x & LSH_ANIM_MASK) == LSH_ANIM_MASK)
  #define LSH_GET_STATUS(x)        (x & LSH_STATUS_MASK)
  #define LSH_GET_COMMAND(id, sts) (((id) << 8)|(sts))
#else
/* other programs */
  #define LSH_ID_MASK              (0x7FF0)
  #define LSH_ANIM_MASK            (0x8000)
  #define LSH_STATUS_MASK          (0x000F)
  #define LSH_GET_ID(x)            ((x & LSH_ID_MASK) >> 4)
  #define LSH_IS_ANIM(x)           ((x & LSH_ANIM_MASK) == LSH_ANIM_MASK)
  #define LSH_GET_STATUS(x)        (x & LSH_STATUS_MASK)
  #define LSH_GET_COMMAND(id, sts) (((id) << 4)|(sts))
#endif /* #if LSH_BTN_ID_MASK_CFG */
#endif /* #ifndef LSH_BTN_ID_MASK_CFG */


#define LSH_VM_STATE_ID(client_id, logic_id) ((((UINT16)client_id)<<((UINT16)0x0008)) | (((UINT16)0x00FF & (UINT16)logic_id)))
#define LSH_GET_STATE_ID(vm_state_id)        ((LSH_STATE_ID_T)(0x00FF & vm_state_id))
#define LSH_GET_CLIENT_ID(vm_state_id)       ((UINT8)((vm_state_id)>>0x0008))
#define LSH_INVALID_CLIENT_ID     (0x00FF)
/* The all vm logic state is assigned in vm mgr chart for active logic and gfx state id if no logic state is active */
#define LSH_ALL_VM_LOGIC_STATES  LSH_VM_STATE_ID(LSH_INVALID_CLIENT_ID, LSH_ALL_LOGIC_STATES)

/*
** Prototy for the focus event handler.
** void hmi_<component_short_name>_set_focus(LSH_STATE_ID_T p_logic_state_U8, UINT8 p_focus_U8)
** p_logic_state_U8 - is the logic state ID
** p_focus_U8       - will indicate whether focus gained(LSH_GOT_FOCUS_STATUS) or
**                    focus lost(LSH_LOST_FOCUS_STATUS)
** When it is necessary to configure null focus handler, use LSH_NULL_FOCUS_HANDLER
*/
typedef void (LSH_FOCUS_HANDLER_T)(LSH_FOCUS_HANDLER_STATUS_T *);
#define LSH_NULL_FOCUS_HANDLER ((LSH_FOCUS_HANDLER_T *)0)

/*
** Prototy for the presentation handler.
** void hmi_<component_short_name>_presentation(LSH_STATE_ID_T p_logic_state_U8, UINT8 p_status_U8)
** p_logic_state_U8 - is the logic state ID
** p_status_U8      - will indicates following
**                    LSH_DEACTIVATED_STATUS - Indicates the logic state is deactivated
**                                             so presentation can send commands to remove
**                                             associated screens.
**                    LSH_ACTIVATED_STATUS   - Indicates the logic state is activated
**                                             so presentation can send commands to activate
**                                             associated screen and its content.
**                    LSH_REFRESH_STATUS     - Indicates a refresh command
**                                             Presentation can use this to send only the changed
**                                             information associated to the screen.
** When it is necessary to configure null presentation handler, use LSH_NULL_PRESN_HANDLER
*/
typedef void (LSH_PRESN_HANDLER_T)(LSH_PRESN_HANDLER_STATUS_T *);
#define LSH_NULL_PRESN_HANDLER ((LSH_PRESN_HANDLER_T *)0)

/*
** Typedefine to hold the configuration associated to a logic state's
** event handlers.
** event_handler        - Button event handler function for the logic state.
** set_focus_handler    - Focus change event handler for the logic state.
** presentation_handler - Presentation handler for the logic state.
*/
typedef struct
{
   LSH_EVENT_HANDLER_T * event;
   LSH_FOCUS_HANDLER_T * focus;
   LSH_PRESN_HANDLER_T * presentation;
}LSH_EV_HANDLER_CONF_T;

/*
** This structure holds the data associated with a button event manager slot.
** Button event manager is designed to tracks a pre-defined number of buttons
** set by SED_NUMBER_OF_SLOTS. Once all the slots are filled with active buttons
** button event manager ignores all other button events that are received. Each slot
** will track one button with its Identifier, State and associated display id.
** The status information is used to register a button to the display id which
** consumes the button even and then to make sure that further events of the button
** until released is only delivered to the same display id.
*/
typedef struct
{
   UINT16         button_id;
   UINT8          state;
   LSH_STATE_ID_T logic_state_id;
}LSH_BUTTON_SLOT_STATUS_T;

/*
** Following structure is for configuring the valid range of button Id's for
** a slot. The slot will accept only button id's tanging from >= start_event
** to <= end_event.
*/
typedef struct
{
   UINT16 start_button_id;
   UINT16 end_button_id;
}LSH_BUTTON_SLOT_CONFIG_T;

#define LSH_FOCUS_STATUS_INACTIVE  0
#define LSH_FOCUS_STATUS_OK        1
#define LSH_FOCUS_STATUS_HIDEN     2
#define LSH_FOCUS_STATUS_INVALID   3

/*
** Animation support related definitions.
*/
#ifndef LSH_ANIMATION_SUPPORT_ENABLED
  /* creating dummy functions to get it go incase no animation support needed */
  #define hmi_lsh_start_animation(p_priority, p_state_id, p_anim_id, p_client_id) (FALSE)
  #define hmi_lsh_stop_animation(p_priority, p_state_id, p_anim_id, p_client_id)
  #define GFX_NUM_ANIMATIONS (254)
#endif


#define ANIM_MAX_ID   (GFX_NUM_ANIMATIONS)
#define ANIM_ABORT_ID (GFX_NUM_ANIMATIONS+1)



#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  #define LSH_ADD_STATE(state, anim) hmi_lsh_add_state(state, anim)
  #define LSH_ADD_STATE_EXT(state, anim, client) hmi_lsh_add_state_ext(state, anim, client)
  #define LSH_REM_STATE(state, anim) hmi_lsh_remove_state(state, anim)
  #define LSH_REM_STATE_EXT(state, anim, client) hmi_lsh_remove_state_ext(state, anim, client)
#else
  #define LSH_ADD_STATE(state, anim) hmi_lsh_add_state(state)
  #define LSH_ADD_STATE_EXT(state, anim, client) hmi_lsh_add_state_ext(state, client)
  #define LSH_REM_STATE(state, anim) hmi_lsh_remove_state(state)
  #define LSH_REM_STATE_EXT(state, anim, client) hmi_lsh_remove_state_ext(state, client)
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

extern void  hmi_lsh_initialize(UINT8 p_init_type_U8);

/* Interface with Animation Support */
extern UINT8 hmi_lsh_add_state(LSH_STATE_ID_T    p_logic_state_id_U8
                               #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                               , UINT8 p_anim_id
							   #endif
                               );
extern UINT8 hmi_lsh_remove_state(LSH_STATE_ID_T p_logic_state_id_U8
                               #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                  , UINT8 p_anim_id
							   #endif
                                  );
extern UINT8 hmi_lsh_add_state_ext(LSH_STATE_ID_T    p_logic_state_id_U8,
                               #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                   UINT8 p_anim_id,
							   #endif
                                   UINT8 p_client_id_U8);
extern UINT8 hmi_lsh_remove_state_ext(LSH_STATE_ID_T p_logic_state_id_U8,
                               #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                      UINT8 p_anim_id,
							   #endif
                                      UINT8 p_client_id_U8);

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
extern void   hmi_lsh_animation_done_cb(UINT8 p_prio_U8, UINT32 p_logic_state_id_U32, UINT8 p_anim_ID);
extern UINT32 hmi_lsh_start_animation(UINT32 p_priority, UINT32 p_state_id, UINT32 p_anim_id);
extern void   hmi_lsh_stop_animation( UINT32 p_priority, UINT32 p_state_id, UINT32 p_anim_id);
extern BOOLEAN  hmi_lsh_inspect_animation_status(UINT8 p_prio_U8, UINT32 p_layer_id_U32);
#endif

extern void  hmi_lsh_force_presentation_rebuild(LSH_STATE_ID_T p_logic_state_id_U8);
extern void  hmi_lsh_task(void);
extern void  hmi_lsh_freeze_button_events(LSH_STATE_ID_T p_logic_state_id_U16);
extern void  hmi_lsh_post_button_event(UINT16 p_button_id_U16, UINT8 p_button_event_U8);
extern void  hmi_lsh_remap_button_events(UINT16 p_button_id_U16, LSH_STATE_ID_T p_target_ls_id);

/*
** Prototype for the default button event handler to be implemented by the application
*/
extern UINT8 hmi_lsh_default_button_event_handler(LSH_EVENT_HANDLER_STATUS_T * p_btn_command_id);

extern void hmi_lsh_execute_presentation(UINT16 p_logic_state_id_U16);

extern void  hmi_lsh_run_presentation(UINT16 p_logic_state_id_U16, UINT8 p_status);

extern UINT32 hmi_lsh_get_focus_status(LSH_STATE_ID_T p_logic_state_id_U8);
extern void  hmi_lsh_focus_handler(UINT16 p_logic_state_id_U16, UINT8 p_status_U8);

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
** CMS Rev 1.11     18-Nov-2013    nkrishn9
** LSH_BTN_ID_MASK_CFG is configuration is defined.
** 
** CMS Rev 1.10     1-oct-2013    nkrishn9
** Abort animation is updated. client id and logic id is combined for view manager chart
** as single id
**
** CMS Rev 1.9     1-oct-2013    nkrishn9
** Added interface hmi_lsh_inspect_animation_status
** Presentation structure and its interface is update with client id.
** different client id but same logic id cases, add and remove same logic state id is handled.
**
** CMS Rev 1.8      05/02/13    VMUTHUSU
** Update the LSH_GET mask macros to support the TVM MFD Programme
**
** CMS Rev 1.7      10-Oct-2012    ASHEKHAR
** Grouped individual handler parameters to a structure parameters.
** Fixed QAC warnings.
**
** CMS Rev 1.6      04-Jul-2012    EMANOJ1
** LSH_GET_COMMAND macro updated provided additional braces.
** LSH_START_ANIM macro and hmi_lsh_animation_done_cb function is protected 
** with LSH_ANIMATION_SUPPORT_ENABLED config
**
** CMS Rev 1.5      27-Dec-2010    EMANOJ1
** Added hmi_lsh_remap_button_events to remap a button ID to a new logic state
** Added return status to hmi_lsh_remove_state
** Added return status to hmi_lsh_add_state for LSH_ANIMATION_SUPPORT_ENABLED
**
** CMS Rev 1.4      25-Jun-2010    GPURUSO1
** Added support for the Animation. An Parameter has beed added to the public
** interface and the code flow has been modified.
**
** CMS Rev 1.3      14-Jun-2010    EMANOJ1
** Include order updated. Now GDT will generate the externs required for the
** event handlers and application need not #include their header files.
**
** CMS Rev 1.2      12-May-2010    EMANOJ1
** LSH_EVENT_HANDLER_T updated to pass logic state id also as a parameter.
**
** CMS Rev 1.1      11-Mar-2010    EMANOJ1
** Updated the return type of hmi_lsh_post_button_event
**
** CMS Rev 1.0      09-FEB-10    EMANOJ1
** Creation.
**
**==========================================================================*/

/* end of file =============================================================*/
#endif
