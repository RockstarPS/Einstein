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
 ** Name:           hmi_logic_state_handler.c
 **
 ** Description:    This module handles the logic state (screen) priority
 **                 stack management for multiple layers, manages the
 **                 presentation callback for active states/screens in the
 **                 priority stack and routes the button events to the
 **                 active states/screens in the priority stack.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_LOGIC_STATE_HANDLER_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "system.h"
#include "hmi_logic_state_handler.h"
#include "hmi_logic_state_handler.dat"

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
#include "hmi_animation01_core.h"
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
static void hmi_lsh_animation_done_cb(UINT8 p_prio_U8, UINT8 p_logic_state_id_U8, ANIMATION_ID p_anim_ID, UINT8 p_anim_client_id_U8);
#endif


/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*
** Following table contains the button id range for all the configured
** number of button slots.
*/
static const LSH_BUTTON_SLOT_CONFIG_T lc_sed_button_slot_config_SA[LSH_NUMBER_OF_BUTTON_SLOTS] =
{
   LSH_BUTTON_ID_SLOT_CONFIG_LIST
};

/*
** This holds the current status information of the individual slots.
** SED will use this status to register button id's against a display
** id.
*/
static LSH_BUTTON_SLOT_STATUS_T l_sed_button_status_S[LSH_NUMBER_OF_BUTTON_SLOTS];

/*
** holds the button ID and state to be remapped incase the LSH
** was not able to find the button in any of the slots. In such case
** the request will be stored in to this variables and processed later.
** This is to handle a case where the hmi_lsh_remap_button_events called
** from a button handler when the requested button is still not registred
** So hmi_lsh_remap_button_events may not find the button in any of the slots
** So the request will be stored in to the variables and when the
** hmi_lsh_post_button_eventfinally register the button event, will register
** the button to l_remap_target_ls_id.
*/
volatile UINT16         l_remap_button_id_U16;
volatile LSH_STATE_ID_T l_remap_target_ls_id;

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/*============================================================================
 ** Function Name:    hmi_lsh_initialize
 ** Visibility:       global
 ** Description:      This is the initialization function for the LSH. This
 **                   function initializes all status variable maintained by
 **                   LSH.
 ** Invocation:       Invoked by application when ever LSH needs to be
 **                   initialized
 ** Inputs/Outputs:   p_init_type_U8 indicates the init type as Cold or Warm.
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
void hmi_lsh_initialize(UINT8 p_init_type_U8)
{
    UINT8 fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    LSH_BUTTON_SLOT_STATUS_T * fl_sed_button_status_SP = &l_sed_button_status_S[0];
    LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
#if LSH_NUMBER_OF_LAYERS > 1
    UINT8 fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
#endif

    /*
    ** Free all button slots
    */
    while (fl_count_U8 > 0)
    {
        fl_count_U8--;
        fl_sed_button_status_SP->button_id = LSH_INVALID_BUTTON_ID;
        fl_sed_button_status_SP->state = LSH_BUTTON_INACTIVE_STATE;
        fl_sed_button_status_SP->logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
        fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
    }

    /*
    ** Free all the logic current display state, previous state
    ** and stack changed flags.
    */
#if LSH_NUMBER_OF_LAYERS > 1
    while(fl_layer_id_U8 > 0)
#endif
    {
    #if LSH_NUMBER_OF_LAYERS > 1
        fl_layer_id_U8--;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];
    #else
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[0];
    #endif
        if (fl_dpm_config_SP->size > 0)
        {
            LSH_STATE_ID_T * fl_dpm_stack_P = fl_dpm_config_SP->ptr;
            LSH_STATE_ID_T * fl_dpm_prev_stack_P = fl_dpm_config_SP->deact_ptr;
            UINT8 * fl_dpm_chg_flag_P = fl_dpm_config_SP->change_ptr;
			UINT8 * fl_dpm_client_id_P = fl_dpm_config_SP->client_ptr;
            fl_count_U8 = fl_dpm_config_SP->size;

            while (fl_count_U8 > 0)
            {
                fl_count_U8--;
                *fl_dpm_stack_P = LSH_NUMBER_OF_LOGIC_STATES;
                fl_dpm_stack_P = &fl_dpm_stack_P[1];
                *fl_dpm_prev_stack_P = LSH_NUMBER_OF_LOGIC_STATES;
                fl_dpm_prev_stack_P = &fl_dpm_prev_stack_P[1];
				*fl_dpm_client_id_P = LSH_INVALID_CLIENT_ID;
				fl_dpm_client_id_P = &fl_dpm_client_id_P[1];
            }

            fl_count_U8 = ((fl_dpm_config_SP->size + 7) >> 3);

            while (fl_count_U8 > 0)
            {
                fl_count_U8--;
                *fl_dpm_chg_flag_P = 0;
                fl_dpm_chg_flag_P = &fl_dpm_chg_flag_P[1];
            }
            *fl_dpm_config_SP->hap_ptr = 0;
        }
    }
    l_remap_button_id_U16 = LSH_INVALID_BUTTON_ID;
    l_remap_target_ls_id  = LSH_NUMBER_OF_LOGIC_STATES;
}

/*============================================================================
 ** Function Name:    void hmi_lsh_add_state_ext()
 ** Visibility:       global
 ** Description:      This function adds the passed logic state to the priority
 **                   table. If this has a higher priority than the the activate
 **                   states in the table, then a focus lost notification is
 **                   given to the next low priority state.
 **                   If a logic state is replaced then call the presentation
 **                   of the removed state to notify that the logic state is
 **                   deactivated so that it can perform any display removal
 **                   activities.
 ** Invocation:       Invoked by logic components when ever it needs a logic state
 **                   to be activated.
 ** Inputs/Outputs:   in  - Logic state id to be activated in p_logic_state_id_U8.
 **							Animation id to be activated in p_anim_id
 **							Client id to be stacked in p_client_id_U8
 **                   out - Bitwise OR of the following
 **                         LSH_INVALID_STATUS    if passed state id is invalid
 **                         LSH_LOST_FOCUS_STATUS if passed state is added and is
 **                                               not having focus currently.
 **                         LSH_GOT_FOCUS_STATUS  if passed state is added and is
 **                                               having focus currently.
 **                         LSH_ANIM_STARTED_STATUS if animation is requested and
 **                                                 accepted by the anim core.
 **                                                 in this case a focus callback
 **                                                 will be made on completion of
 **                                                 animation
 ** Critical Section: None.
 ** Created:          15-Dec-2011 by CMUTHUSA
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
UINT8 hmi_lsh_add_state_ext(  LSH_STATE_ID_T p_logic_state_id_U8
                       #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                        , ANIMATION_ID   p_anim_id
                       #endif
					   , UINT8 p_client_id_U8
                       )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

    if (p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
        LSH_FOCUS_HANDLER_STATUS_T  fl_focus_hndl_status_S;
        LSH_STATE_ID_T                fl_active_state;
        UINT8                         fl_priority_U8;
		UINT8						fl_active_client_id_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
		
        if (fl_priority_U8 < fl_dpm_config_SP->size)
        {
            fl_active_state = fl_dpm_config_SP->ptr[fl_priority_U8];
            if (fl_active_state != p_logic_state_id_U8)
            {
                if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                {
                    /*
                    ** Overwriting the same priority screen. Two things to do
                    ** 1. Mark the deactivation. deact_ptr[] will be cleared by hmi_lsh_task
                    **    when it runs by filling LSH_NUMBER_OF_LOGIC_STATES
                    **    a. only the first deactivation before hmi_lsh_task executes.
                    **    b. only if presentation has noted the activation (change_ptr must be clear)
                    **    Becuase the presentation may not need to know intermediate transitions.
                    */
                    if (fl_dpm_config_SP->deact_ptr[fl_priority_U8] == LSH_NUMBER_OF_LOGIC_STATES)
                    {
                        if ((fl_dpm_config_SP->change_ptr[fl_priority_U8 / 8] & ((UINT8)(1 << (fl_priority_U8 & 7)))) == 0)
                        {
                            fl_dpm_config_SP->deact_ptr[fl_priority_U8] = fl_active_state;
                        }
                    }
                    /*
                    ** 2. Invoke the focus handler of the display getting removed to intimate
                    **    the de-activation.
                    */
                    fl_active_client_id_U8 = fl_dpm_config_SP->client_ptr[fl_priority_U8];
                    fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_active_state];
                    if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                    {
                        fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                        if (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER)
                        {
                            fl_focus_hndl_status_S.logic_state_id = fl_active_state;
                            fl_focus_hndl_status_S.focus_status   = LSH_DEACTIVATED_STATUS;
                            fl_focus_hndl_status_S.focus_id  = p_logic_state_id_U8;
							fl_focus_hndl_status_S.client_id  = fl_active_client_id_U8;
                            fl_handler_SP->focus(&fl_focus_hndl_status_S);
                            hmi_lsh_freeze_button_events(fl_active_state);
                        }
                    }
                }
                else if (fl_priority_U8 > *fl_dpm_config_SP->hap_ptr)
                {
                    /*
                    ** New logic state for the priority and is a high priority too.
                    ** Notify the active high priority state that it is loosing focus to a
                    ** high priority state.
                    */
                    fl_active_state = fl_dpm_config_SP->ptr[*fl_dpm_config_SP->hap_ptr];
					fl_active_client_id_U8 = fl_dpm_config_SP->client_ptr[*fl_dpm_config_SP->hap_ptr]; 
                    *fl_dpm_config_SP->hap_ptr = fl_priority_U8;

                    if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                    {
                        fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_active_state];
                        if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                        {
                            fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                            if (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER)
                            {
                                fl_focus_hndl_status_S.logic_state_id = fl_active_state;
                                fl_focus_hndl_status_S.focus_status   = LSH_LOST_FOCUS_STATUS;
                                fl_focus_hndl_status_S.focus_id  = p_logic_state_id_U8;
								fl_focus_hndl_status_S.client_id  = fl_active_client_id_U8;
                                fl_handler_SP->focus(&fl_focus_hndl_status_S);
                            }
                        }
                    }
                }
                else
                {
                    /*
                    ** Screen is new for the priority but is having low priority than
                    ** the currently active highest priority state.
                    */
                }
                /*
                ** Update the priority stack with new state and notify the presentation.
                */
                fl_dpm_config_SP->ptr[fl_priority_U8]             = p_logic_state_id_U8;
                fl_dpm_config_SP->change_ptr[fl_priority_U8 / 8] |= (UINT8)(1 << ((fl_priority_U8) & 7));
				fl_dpm_config_SP->client_ptr[fl_priority_U8] = p_client_id_U8;
            }
            if(fl_priority_U8 == *fl_dpm_config_SP->hap_ptr)
            {
                /*
                ** This display is the highest priority display and so has the focus.
                */
                fl_focus_state_U8 = LSH_GOT_FOCUS_STATUS;
            }
            else
            {
                fl_focus_state_U8 = LSH_LOST_FOCUS_STATUS;
            }
        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
            /* Request for the Animation */
            if(hmi_anim01_start_frame_sequence(fl_priority_U8,
                                               p_logic_state_id_U8,
                                               p_anim_id,
                                               hmi_lsh_animation_done_cb,p_client_id_U8) != FALSE)
            {
               fl_focus_state_U8 |= LSH_ANIM_STARTED_STATUS;
            }
        #endif
        }
    }
    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_remove_state_ext()
 ** Visibility:       global
 ** Description:      This function removes the passed logic state from the priority
 **                   table. If this was the highest priority state, then a focus
 **                   gained notification is given to the next high priority state.
 **                   Also calls the presentation to notify that the logic state is
 **                   deactivated so that it can perform any display removal
 **                   activities.
 ** Invocation:       Invoked by logic components when ever it needs a logic state
 **                   to be deactivated.
 ** Inputs/Outputs:   in  - Logic state id to be deactivated in p_logic_state_id_U8.
 **							Animation id to be activated in p_anim_id
 **							Client id to be passed to Animation in p_client_id_U8
 **                   out - Bitwise OR of the following
 **                         LSH_INVALID_STATUS     if passed state id is invalid
 **                         LSH_DEACTIVATED_STATUS if passed state is removed.
 **                         LSH_ANIM_STARTED_STATUS if animation is requested and
 **                                                 accepted by the anim core.
 **                                                 in this case a focus callback
 **                                                 will be made on completion of
 **                                                 animation
 ** Critical Section: None.
 ** Created:          15-Dec-2011 by CMUTHUSA
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
UINT8 hmi_lsh_remove_state_ext(  LSH_STATE_ID_T p_logic_state_id_U8
                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                           , ANIMATION_ID p_anim_id
                          #endif
						  , UINT8 p_client_id_U8 
                          )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;
    if (p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
        LSH_FOCUS_HANDLER_STATUS_T  fl_focus_hndl_status_S;
        LSH_STATE_ID_T                fl_active_state;
        UINT8                         fl_priority_U8;
		UINT8						fl_active_client_id_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
        fl_priority_U8   = fl_state_conf_SP->priority;

        if (fl_priority_U8 < fl_dpm_config_SP->size)
        {
            fl_active_state = fl_dpm_config_SP->ptr[fl_priority_U8];

            if (fl_active_state == p_logic_state_id_U8)
            {
                if (fl_active_state == l_remap_target_ls_id)
                {
                    /*
                    ** If the target button remap state has been deactivated
                    ** then clear the queue so that we don't remap the button
                    ** to a deactivated state.
                    */
                    l_remap_target_ls_id = LSH_NUMBER_OF_LOGIC_STATES;
                }
                /*
                ** Mark the deactivation in deact_ptr[]. deact_ptr[] will be cleared by hmi_lsh_task
                ** when it runs by filling LSH_NUMBER_OF_LOGIC_STATES.
                ** a. only the first deactivation before hmi_lsh_task executes.
                ** b. only if presentation has noted the activation (change_ptr must be clear)
                ** Becuase the presentation may not need to know intermediate transitions.
                */
                if (fl_dpm_config_SP->deact_ptr[fl_priority_U8] == LSH_NUMBER_OF_LOGIC_STATES)
                {
                    if ((fl_dpm_config_SP->change_ptr[fl_priority_U8 / 8] & ((UINT8)(1 << (fl_priority_U8 & 7)))) == 0)
                    {
                        fl_dpm_config_SP->deact_ptr[fl_priority_U8] = fl_active_state;
                    }
                }
                /*
                ** Freeze all button id's registered against the state.
                */
                if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                {
                    fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                    if (fl_handler_SP->event != LSH_NULL_EVENT_HANDLER)
                    {
                        hmi_lsh_freeze_button_events(fl_active_state);
                    }
                }
                fl_dpm_config_SP->ptr[fl_priority_U8] = LSH_NUMBER_OF_LOGIC_STATES;
                fl_dpm_config_SP->change_ptr[fl_priority_U8 / 8] |= (UINT8)(1 << (fl_priority_U8 & 7));
                fl_dpm_config_SP->client_ptr[fl_priority_U8] = LSH_INVALID_CLIENT_ID;
                
                /*
                ** If the deactivated state was the high priority one, then find the next
                ** high priority active state and notify that it has got the focus now.
                */
                
                if (fl_priority_U8 == *fl_dpm_config_SP->hap_ptr)
                {
                    UINT8 fl_got_focus_U8 = FALSE;
                    while ((fl_got_focus_U8 == FALSE) && (*fl_dpm_config_SP->hap_ptr > 0))
                    {
                        (*fl_dpm_config_SP->hap_ptr)--;
                        fl_active_state = fl_dpm_config_SP->ptr[*fl_dpm_config_SP->hap_ptr];
                        fl_active_client_id_U8 = fl_dpm_config_SP->client_ptr[*fl_dpm_config_SP->hap_ptr];
                        if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                        {
                            fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_active_state];
                            if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                            {
                                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                                if (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER)
                                {
                                    fl_focus_hndl_status_S.logic_state_id = fl_active_state;
                                    fl_focus_hndl_status_S.focus_status   = LSH_GOT_FOCUS_STATUS;
                                    fl_focus_hndl_status_S.focus_id  = p_logic_state_id_U8;
                                    fl_focus_hndl_status_S.client_id = fl_active_client_id_U8;
                                    fl_handler_SP->focus(&fl_focus_hndl_status_S);
                                }
                            }
                            fl_got_focus_U8 = TRUE;
                        }
                    }
                }
            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                if(hmi_anim01_start_frame_sequence(fl_priority_U8,
                                                   p_logic_state_id_U8,
                                                   p_anim_id,
                                                   hmi_lsh_animation_done_cb,p_client_id_U8) != FALSE)
                {
                    fl_focus_state_U8 = LSH_DEACT_PENDING_STATUS;
                }
                else
            #endif
                {
                    fl_focus_state_U8 = LSH_DEACTIVATED_STATUS;
                }
            }
        }
    }
    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_force_presentation_rebuild
 ** Visibility:       global
 ** Description:      This will set a redraw flag so that when hmi_lsh_task will
 **                   schedule the presentation when next time it runs with
 **                   the status of LSH_ACTIVATED_STATUS for the specified display
 **                   state.
 ** Invocation:       Invoked by clients when ever necessary to redraw the presentation.
 ** Inputs/Outputs:   Pass the specific logic state id for invoking its presentation.
 **                   Pass LSH_ALL_LOGIC_STATES if all the active logic state needs
 **                   to be redrawn.
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          19-Feb-2010 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_force_presentation_rebuild(LSH_STATE_ID_T p_logic_state_id_U8)
{
    LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    LSH_STATE_ID_T fl_active_state;
    UINT8 fl_count_U8;

    if (p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        /* Force the redraw flag for the specified state */
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
        fl_count_U8 = fl_state_conf_SP->priority;

        if (fl_count_U8 < fl_dpm_config_SP->size)
        {
            fl_active_state = fl_dpm_config_SP->ptr[fl_count_U8];
            if (fl_active_state == p_logic_state_id_U8)
            {
                (fl_dpm_config_SP->change_ptr[fl_count_U8 >> 3]) |= (UINT8)(1 << ((fl_count_U8) & 7));
            }
        }
    }
    else if (p_logic_state_id_U8 == LSH_ALL_LOGIC_STATES)
    {
        /* Force the redraw flag for all active states */
    #if LSH_NUMBER_OF_LAYERS > 1
        UINT8 fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
        while(fl_layer_id_U8 > 0)
    #endif
        {
        #if LSH_NUMBER_OF_LAYERS > 1
            fl_layer_id_U8--;
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];
        #else
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[0];
        #endif
            if (fl_dpm_config_SP->size > 0)
            {
                fl_count_U8 = fl_dpm_config_SP->size;

                while (fl_count_U8 > 0)
                {
                    fl_count_U8--;
                    fl_active_state = fl_dpm_config_SP->ptr[fl_count_U8];

                    if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                    {
                        (fl_dpm_config_SP->change_ptr[fl_count_U8 >> 3]) |= (UINT8)(1 << ((fl_count_U8) & 7));
                    }
                }
            }
        }
    }
    else
    {
        /*
        ** Invalid state ID's are ignored.
        */
    }
}

/*============================================================================
 ** Function Name:    hmi_lsh_execute_presentation
 ** Visibility:       global
 ** Description:      This function executes the presentation for the passed
 **                   logical state if the passed state is active. Presentation
 **                   scheduling is blocked for a priority level or whole when
 **                   an animation is in progress. This provides a means to
 **                   schedule a blocked presentation when required by the anim
 **                   core.
 ** Invocation:       Invoked by animation core to schedule the presentation
 **                   for a specified logical state during the animation sequence.
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          29-Dec-2010 by EMANOJ1
 ** Updated:          22-May-2015 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_execute_presentation(LSH_STATE_ID_T p_logic_state_id_U8)
{
    LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
    LSH_STATE_ID_T                fl_active_state;
    LSH_STATE_ID_T                fl_deactive_state;
    UINT8                         fl_priority_U8;
    UINT8                         fl_lsh_status_U8;
    LSH_PRESN_HANDLER_STATUS_T    fl_handler_status_S;

    if(p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

        if (fl_priority_U8 < fl_dpm_config_SP->size)
        {
            fl_active_state = fl_dpm_config_SP->ptr[fl_priority_U8];
            if (((fl_dpm_config_SP->change_ptr[fl_priority_U8 >> 3]) & ((UINT8)(1 << (fl_priority_U8 & 0x07)))) != 0)
            {
               fl_deactive_state = fl_dpm_config_SP->deact_ptr[fl_priority_U8];
               if (fl_deactive_state < LSH_NUMBER_OF_LOGIC_STATES)
               {
                  if ((fl_deactive_state == p_logic_state_id_U8) || (fl_active_state == p_logic_state_id_U8))
                  {
                     /*
                     ** If the current active state or the state in the deactivation stack
                     ** matches with requested state, then we need to execute the presentation
                     */
                     fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_deactive_state];
                     if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                     {
                        fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                        if (fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER)
                        {
						   fl_handler_status_S.logic_state_id=fl_deactive_state;
						   fl_handler_status_S.presentation_status=LSH_DEACTIVATED_STATUS;
                           fl_handler_SP->presentation(&fl_handler_status_S);
						    /* vm01 interface fl_handler_SP->presentation(fl_deactive_state, LSH_DEACTIVATED_STATUS); */
                        }
                     }
                     fl_dpm_config_SP->deact_ptr[fl_priority_U8] = LSH_NUMBER_OF_LOGIC_STATES;
                  }
               }
            }
            if (fl_active_state == p_logic_state_id_U8)
            {
                if (((fl_dpm_config_SP->change_ptr[fl_priority_U8 >> 3]) & ((UINT8)(1 << (fl_priority_U8 & 0x07)))) != 0)
                {
                    (fl_dpm_config_SP->change_ptr[fl_priority_U8 >> 3]) &= (UINT8)(~(1 << ((fl_priority_U8) & 7)));
                    fl_lsh_status_U8 = LSH_ACTIVATED_STATUS;
                }
                else
                {
                    fl_lsh_status_U8 = LSH_REFRESH_STATUS;
                }
                fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
                if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                {
                    fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                    if (fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER)
                    {
					    fl_handler_status_S.logic_state_id=p_logic_state_id_U8;
					    fl_handler_status_S.presentation_status=fl_lsh_status_U8;
                        fl_handler_SP->presentation(&fl_handler_status_S);
                        /* vm01 interface fl_handler_SP->presentation(p_logic_state_id_U8, fl_lsh_status_U8); */
                    }
                }
            }
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_lsh_task
 ** Visibility:       global
 ** Description:      This function implements the presentation function handling
 **                   for the active logic states available in the priority table.
 **                   This will invoke presentation function of active logic states
 **                   Presetation will be invoked with following status parameter
 **                   LSH_DEACTIVATED_STATUS - Indicates that associated logic state
 **                                            is deactivated. Presentation can use
 **                                            this to deactivate display.
 **                   LSH_ACTIVATED_STATUS   - Indicates that associated logic state
 **                                            is activated. Use this bring up the
 **                                            screen and all the contents for the
 **                                            first time
 **                   LSH_REFRESH_STATUS     - Indicates that logic state is already
 **                                            active and presentation only need to
 **                                            refresh the changed items.
 **                   When animation support is enabled the whole presentation
 **                   or for a particular priority can be disabled using
 **                   configuration to prevent interference to animation.
 ** Invocation:       Invoked by clients periodically or when ever necessary to
 **                   update the presentation.
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          22-May-2015 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_task(void)
{
    LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
    UINT8 fl_count_U8;
    UINT8 fl_lsh_status_U8;
    UINT8 fl_ack_deactivation;
    LSH_PRESN_HANDLER_STATUS_T    fl_handler_status_S;
#if LSH_NUMBER_OF_LAYERS > 1
    UINT8 fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;

    while(fl_layer_id_U8 > 0)
#endif
    {
    #if LSH_NUMBER_OF_LAYERS > 1
        fl_layer_id_U8--;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];
    #else
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[0];
    #endif
        if (fl_dpm_config_SP->size > 0)
        {
            LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
            LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
            LSH_STATE_ID_T                fl_active_state;
		#if defined(LSH_ANIMATION_SUPPORT_ENABLED) && defined(LSH_ANIM_BLOCK_INDIVIDUAL_PRIOR_PRESNT)
            LSH_STATE_ID_T                fl_anim_state;
        #endif            
            fl_count_U8 = fl_dpm_config_SP->size;

        #if defined(LSH_ANIMATION_SUPPORT_ENABLED) && !defined(LSH_ANIM_BLOCK_INDIVIDUAL_PRIOR_PRESNT)
            if (LSH_CHECK_ANIMATION_SEQNCR_INACTIVE())
        #endif
            {
                /* Presentation function should not be executed for any prio level if
                 * an animation is active */
                /*
                ** First invoke presetation for all deactivated states.
                */
                for(fl_count_U8 = 0; fl_count_U8 < fl_dpm_config_SP->size; fl_count_U8++)
                {
                    if (((fl_dpm_config_SP->change_ptr[fl_count_U8 >> 3]) & ((UINT8)(1 << (fl_count_U8 & 0x07)))) != 0)
                    {
                        fl_active_state = fl_dpm_config_SP->deact_ptr[fl_count_U8];
                        if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                        {
                            fl_ack_deactivation = TRUE;
                            fl_state_conf_SP    = &lc_lsh_screen_config_SA[fl_active_state];
                            if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                            {
                                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                                if (fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER)
                                {
                                #if defined(LSH_ANIMATION_SUPPORT_ENABLED) && defined(LSH_ANIM_BLOCK_INDIVIDUAL_PRIOR_PRESNT)
                                    fl_anim_state = hmi_anim01_get_current_animation_state(fl_count_U8);
                                    if (fl_anim_state == LSH_NUMBER_OF_LOGIC_STATES)
                                    {
                                       /*
                                       ** There are no animations pending for the priority, so we can
                                       ** intimate the deactivation.
                                       */
                                       fl_handler_status_S.logic_state_id=fl_active_state;
                                       fl_handler_status_S.presentation_status=LSH_DEACTIVATED_STATUS;
                                       fl_handler_SP->presentation(&fl_handler_status_S);

                                        /* vm01 interface fl_handler_SP->presentation(fl_active_state, LSH_DEACTIVATED_STATUS); */
                                    }
                                  #if defined(LSH_PRESENT_DEACT_PENDING_STATUS_ENABLED)
                                    else
                                    {
                                       /*
                                       ** Indicate to presentation that its deactivation is
                                       ** pending since an animation is in progress on its priority
                                       ** for a different screen.
                                       */
                                       if(fl_anim_state != fl_active_state)
                                       {
                                          fl_handler_status_S.logic_state_id=fl_active_state;
                                          fl_handler_status_S.presentation_status=LSH_DEACT_PENDING_STATUS;
                                          fl_handler_SP->presentation(&fl_handler_status_S);

                                          /* fl_handler_SP->presentation(fl_active_state, LSH_DEACT_PENDING_STATUS); nkrihsn9 */
                                       }
                                       /*
                                       ** Animation is pending so don't clear the deact_ptr[]
                                       */
                                       fl_ack_deactivation = FALSE;
                                    }
                                  #else
                                    else
                                    {
                                       /*
                                       ** Animation is pending so don't clear the deact_ptr[]
                                       */
                                       fl_ack_deactivation = FALSE;
                                    }
                                  #endif
                                #else
                                    fl_handler_status_S.logic_state_id=fl_active_state;
                                    fl_handler_status_S.presentation_status=LSH_DEACTIVATED_STATUS;
                                    fl_handler_SP->presentation(&fl_handler_status_S);

                                     /* vm01 interface fl_handler_SP->presentation(fl_active_state, LSH_DEACTIVATED_STATUS);*/
                                #endif
                                }
                            }
                            if(fl_ack_deactivation != FALSE)
                            {
                               fl_dpm_config_SP->deact_ptr[fl_count_U8] = LSH_NUMBER_OF_LOGIC_STATES;
                            }
                        }
                    }
                }
                /*
                ** Next invoke presetation for activate states
                */
                for(fl_count_U8 = 0; fl_count_U8 < fl_dpm_config_SP->size; fl_count_U8++)
                {
                #if defined(LSH_ANIMATION_SUPPORT_ENABLED) && defined(LSH_ANIM_BLOCK_INDIVIDUAL_PRIOR_PRESNT)
                    if (hmi_anim01_get_current_animation_state(fl_count_U8) == LSH_NUMBER_OF_LOGIC_STATES)
                #endif
                    {
                        if (((fl_dpm_config_SP->change_ptr[fl_count_U8 >> 3]) & ((UINT8)(1 << (fl_count_U8 & 0x07)))) != 0)
                        {
                            (fl_dpm_config_SP->change_ptr[fl_count_U8 >> 3]) &= (UINT8)(~(1 << ((fl_count_U8) & 7)));
                            fl_lsh_status_U8 = LSH_ACTIVATED_STATUS;
                        }
                        else
                        {
                            fl_lsh_status_U8 = LSH_REFRESH_STATUS;
                        }
                        fl_active_state = fl_dpm_config_SP->ptr[fl_count_U8];
                        if (fl_active_state < LSH_NUMBER_OF_LOGIC_STATES)
                        {
                            fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_active_state];
                            if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                            {
                                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                                if (fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER)
                                {
                                    fl_handler_status_S.logic_state_id=fl_active_state;
                                    fl_handler_status_S.presentation_status=fl_lsh_status_U8;
                                    fl_handler_SP->presentation(&fl_handler_status_S);
                                     /* vm01 interface fl_handler_SP->presentation(fl_active_state, fl_lsh_status_U8);*/
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_lsh_post_button_event
 ** Visibility:       global
 ** Description:      Application needs to call this function when ever
 **                   it detects a button event. This routine will
 **                   deliver the button events from high priority display
 **                   to low priority display until a priority display
 **                   returns the status as LSH_STATUS_ABSORBED.
 **                   If none of the active displays in priority table
 **                   absorbs the button, the button event is given to the
 **                   LSH_DEFAULT_BUTTON_EVENT_HANDLER.
 ** Invocation:       Invoked by application when ever button event is detected.
 ** Inputs/Outputs:   Button ID in p_button_id_U16 and state of the button in
 **                   p_button_event_U8.
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          22-May-2015 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_post_button_event(UINT16 p_button_id_U16, UINT8 p_button_event_U8)
{
    LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
#if LSH_NUMBER_OF_LAYERS > 1
    UINT8 fl_layer_id_U8;
#endif
    UINT8 fl_count_U8;
    UINT8 fl_slot_id_U8;
    UINT8 fl_free_slot_id_U8;
    UINT8 fl_found_config_U8;
    UINT8 fl_return_state_U8 = LSH_STATUS_NONE;
    LSH_STATE_ID_T fl_logic_state_id_U16;
    LSH_EVENT_HANDLER_STATUS_T fl_btn_hndlr_status;

    fl_count_U8 = 0;
    fl_slot_id_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    fl_free_slot_id_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    fl_found_config_U8 = FALSE;
    /*
    ** Find the slot of the passed button id if already present in slot array.
    ** If its a new button then get a free slot for the button.
    */
    while ((fl_slot_id_U8 == LSH_NUMBER_OF_BUTTON_SLOTS) && (fl_count_U8 < LSH_NUMBER_OF_BUTTON_SLOTS))
    {
        if ((p_button_id_U16 >= lc_sed_button_slot_config_SA[fl_count_U8].start_button_id) && (p_button_id_U16
                <= lc_sed_button_slot_config_SA[fl_count_U8].end_button_id))
        {
            if (l_sed_button_status_S[fl_count_U8].button_id == p_button_id_U16)
            {
                fl_slot_id_U8 = fl_count_U8;
            }
            else if (fl_free_slot_id_U8 == LSH_NUMBER_OF_BUTTON_SLOTS)
            {
                if (l_sed_button_status_S[fl_count_U8].button_id == LSH_INVALID_BUTTON_ID)
                {
                    /* make a note of the first free slot */
                    fl_free_slot_id_U8 = fl_count_U8;
                }
                else
                {
                    fl_count_U8++;
                }
            }
            else
            {
                fl_count_U8++;
            }
            fl_found_config_U8 = TRUE;
        }
        else if (fl_found_config_U8 == FALSE)
        {
            /*
            ** We haven't yet found the configured slot area for the passed button ID.
            ** So moving to next slot.
            */
            fl_count_U8++;
        }
        else
        {
            /*
            ** We have scanned all the configured slot locations for the specified
            ** button, so no point in searching other slots. So exiting.
            */
            fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
        }
    }
    /*
    ** If the button was not already present in the slot array, then assign a
    ** free slot for it.
    */
    if (fl_slot_id_U8 == LSH_NUMBER_OF_BUTTON_SLOTS)
    {
        fl_slot_id_U8 = fl_free_slot_id_U8;
    }
    /*
    ** Now perform the button event dispatching only if slot is available.
    */
    if (fl_slot_id_U8 != LSH_NUMBER_OF_BUTTON_SLOTS)
    {
        if (l_sed_button_status_S[fl_slot_id_U8].button_id != p_button_id_U16)
        {
            /*
            ** First event for the Button. So find the consumer of this event by
            ** passing events from high priority to low priority states.
            */
            l_sed_button_status_S[fl_slot_id_U8].button_id = p_button_id_U16;
            l_sed_button_status_S[fl_slot_id_U8].state = p_button_event_U8;
            l_sed_button_status_S[fl_slot_id_U8].logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;

        #if LSH_NUMBER_OF_LAYERS > 1
            /*
            ** Start the dispatch with high priority layer to low priority layer
            ** In each layer high priority display to low priority display.
            */
            fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
            while(fl_layer_id_U8 > 0)
        #endif
            {
                LSH_STATE_ID_T * fl_dpm_stack_P;
                UINT8 fl_dpm_stack_count;

            #if LSH_NUMBER_OF_LAYERS > 1
                fl_layer_id_U8--;
                fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];
            #else
                fl_dpm_config_SP = &lc_lsh_dpm_config_SA[0];
            #endif

                if (fl_dpm_config_SP->size > 0)
                {
                    fl_dpm_stack_P = &fl_dpm_config_SP->ptr[fl_dpm_config_SP->size - 1];
                    fl_dpm_stack_count = fl_dpm_config_SP->size;

                    while (fl_dpm_stack_count > 0)
                    {
                        fl_dpm_stack_count--;
                        if (*fl_dpm_stack_P < LSH_NUMBER_OF_LOGIC_STATES)
                        {
                            LSH_EV_HANDLER_CONF_T const * fl_handler_SP;

                            fl_count_U8 = lc_lsh_screen_config_SA[*fl_dpm_stack_P].handler_idx;
                            if (fl_count_U8 < LSH_NUMBER_OF_EV_HANDLERS)
                            {
                                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_count_U8];

                                if (fl_handler_SP->event != LSH_NULL_EVENT_HANDLER)
                                {
                                    /*
                                    ** Clear the remap requests so that we will in a position
                                    ** to identify if fl_handler_SP->event() has requested for
                                    ** a remap from the fl_handler_SP->event() context
                                    */
                                    l_remap_button_id_U16 = LSH_INVALID_BUTTON_ID;
                                    l_remap_target_ls_id  = LSH_NUMBER_OF_LOGIC_STATES;

                                    fl_logic_state_id_U16 = *fl_dpm_stack_P;
                                
								    fl_btn_hndlr_status.logic_state_id = fl_logic_state_id_U16;
                                    fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
                                    fl_return_state_U8 = fl_handler_SP->event(&fl_btn_hndlr_status);

                                   /* vm01 interface fl_return_state_U8 = fl_handler_SP->event((*fl_dpm_stack_P),
                                            LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8)); 
                                #if LSH_ENCODE_BUTTON_ID_AND_STATE > 0
	                                #else
									Not supported
                                    fl_return_state_U8 = fl_handler_SP->event(fl_logic_state_id_U16, p_button_id_U16,
                                            p_button_event_U8);
                               	 #endif*/
                                    if ((fl_return_state_U8 & LSH_STATUS_ABSORBED) != 0)
                                    {
                                        if (*fl_dpm_stack_P < LSH_NUMBER_OF_LOGIC_STATES)
                                        {
                                            if((l_remap_button_id_U16 == p_button_id_U16) &&
                                               (l_remap_target_ls_id  != LSH_NUMBER_OF_LOGIC_STATES))
                                            {

                                               /*
                                               ** If the remap has been called and the button ID matches,
                                               ** then register the button to l_remap_target_ls_id as
                                               ** fl_logic_state_id_U16 may want to remap the event
                                               */
                                               l_sed_button_status_S[fl_slot_id_U8].logic_state_id = l_remap_target_ls_id;
                                            }
                                            else
                                            {
                                               /*
                                               ** Register the button against the state and break the loop.
                                               */
                                               l_sed_button_status_S[fl_slot_id_U8].logic_state_id = fl_logic_state_id_U16;
                                            }
                                        }
                                        fl_dpm_stack_count = 0;
                                    }
                                }
                            }
                        }
                        fl_dpm_stack_P--;
                    }
                }
            }
        }
        else
        {
            /*
            ** Button is already registered, so deliver the button events to the
            ** registred state.
            */
            if (l_sed_button_status_S[fl_slot_id_U8].state != LSH_BUTTON_FREEZE_STATUS)
            {
                LSH_STATE_ID_T fl_logic_state = l_sed_button_status_S[fl_slot_id_U8].logic_state_id;

                if (fl_logic_state < LSH_NUMBER_OF_LOGIC_STATES)
                {
                    LSH_EV_HANDLER_CONF_T const * fl_handler_SP;

                    fl_count_U8 = lc_lsh_screen_config_SA[fl_logic_state].handler_idx;
                    if (fl_count_U8 < LSH_NUMBER_OF_EV_HANDLERS)
                    {
                        fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_count_U8];
                        if (fl_handler_SP->event != LSH_NULL_EVENT_HANDLER)
                        {

						    fl_btn_hndlr_status.logic_state_id = fl_logic_state;
                            fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
                            fl_return_state_U8 = fl_handler_SP->event(&fl_btn_hndlr_status);

                            /* vm01 interface - fl_return_state_U8 = fl_handler_SP->event(fl_logic_state, 
                                    LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8));		  

                            fl_return_state_U8 = fl_handler_SP->event(fl_logic_state, p_button_id_U16, p_button_event_U8);
							 not supported */

                        }
                    }
                }
                else
                {
                    /*
                    ** This button is not registered to any logic state, so issue to default handler
                    */
                    fl_return_state_U8 = LSH_STATUS_NONE;
                }
            }
        }
        if (p_button_event_U8 == LSH_BUTTON_INACTIVE_STATE)
        {
            /*
            ** Relese the slot on button release
            */
            l_sed_button_status_S[fl_slot_id_U8].button_id = LSH_INVALID_BUTTON_ID;
            l_sed_button_status_S[fl_slot_id_U8].logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
        }
    }
#ifdef LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER
 #if LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER > 0
    if(fl_return_state_U8 == LSH_STATUS_NONE)
    {

        fl_btn_hndlr_status.logic_state_id = l_sed_button_status_S[fl_slot_id_U8].logic_state_id;
        fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
        (void) hmi_lsh_default_button_event_handler(&fl_btn_hndlr_status);
 /* vm01 interface  (void) hmi_lsh_default_button_event_handler(l_sed_button_status_S[fl_slot_id_U8].logic_state_id,
                LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8));
  #if LSH_ENCODE_BUTTON_ID_AND_STATE > 0`		not supported
        (void)hmi_lsh_default_button_event_handler(l_sed_button_status_S[fl_slot_id_U8].logic_state_id,p_button_id_U16, p_button_event_U8); */

    }
 #endif
#else
 #error "LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER needs to be set to either 0 or 1"
#endif
}

/*============================================================================
 ** Function Name:    hmi_lsh_freeze_button_events
 ** Visibility:       global
 ** Description:      Application needs to call this function when ever
 **                   it wants to freeze buttons registered against a display id.
 **                   After calling this function SED will stop the processing
 **                   of buttons registered against the passed display id until
 **                   all the buttons become SED_BUTTON_INACTIVE_EVENT.
 **                   Generaly this function will be configured in the DPM to notify
 **                   SED when ever a display id gets removed or loses its
 **                   focus (becomes inactive), so that those buttons can be
 **                   freezed.
 ** Invocation:       Invoked when ever a display id is removed.
 **                   Invoked by application when ever it wants to freeze buttons
 **                   registered against a display id.
 ** Inputs/Outputs:   display identifier.
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          19-Feb-2010 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_freeze_button_events(LSH_STATE_ID_T p_logic_state_id_U16)
{
    UINT8 fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    LSH_BUTTON_SLOT_STATUS_T * fl_sed_button_status_SP = &l_sed_button_status_S[0];

    if (p_logic_state_id_U16 == LSH_ALL_LOGIC_STATES)
    {
        /*
        ** Freeze all the buttons
        */
        while (fl_count_U8 > 0)
        {
            fl_count_U8--;
            if (fl_sed_button_status_SP->logic_state_id < LSH_NUMBER_OF_LOGIC_STATES)
            {
                fl_sed_button_status_SP->state = LSH_BUTTON_FREEZE_STATUS;
            }
            fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
        }
    }
    else
    {
        /*
        ** Freeze buttons registred against a logic state.
        */
        while (fl_count_U8 > 0)
        {
            fl_count_U8--;
            if (fl_sed_button_status_SP->logic_state_id == p_logic_state_id_U16)
            {
                fl_sed_button_status_SP->state = LSH_BUTTON_FREEZE_STATUS;
            }
            fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_lsh_remap_button_events
 ** Visibility:       global
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
 **
 ** Invocation:       Invoked when ever there is a real need.
 ** Inputs/Outputs:   in  - Button ID and target logic state ID's.
 **                   Make sure that you pass the button ID and not the encoded
 **                   command in case of a LSH_ENCODE_BUTTON_ID_AND_STATE build.
 ** Critical Section: None.
 ** Created:          25-Dec-2010 by EMANOJ1
 ** Updated:          29-Dec-2010 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_remap_button_events(UINT16 p_button_id_U16, LSH_STATE_ID_T p_target_ls_id)
{
    LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    LSH_STATE_ID_T                fl_active_state;
    UINT8                         fl_priority_U8;

    if (p_target_ls_id < LSH_NUMBER_OF_LOGIC_STATES)
    {
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_target_ls_id];
        fl_priority_U8   = fl_state_conf_SP->priority;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
        fl_active_state  = fl_dpm_config_SP->ptr[fl_priority_U8];

        if (fl_active_state == p_target_ls_id)
        {
            /*
            ** Both Source and Target state are active
            */
            UINT8 fl_count_U8;
            fl_count_U8 = lc_lsh_screen_config_SA[p_target_ls_id].handler_idx;
            if (fl_count_U8 < LSH_NUMBER_OF_EV_HANDLERS)
            {
                LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_count_U8];
                if (fl_handler_SP->event != LSH_NULL_EVENT_HANDLER)
                {
                    /*
                    ** Remap button slot registry to the p_target_ls_id only
                    ** if the p_target_ls_id has got a valid event handler.
                    ** Store the request to l_remap_button_id_U16 and
                    ** l_remap_target_ls_id to process it later incase we cannot
                    ** find the button ID in any of the slots.
                    */
                    LSH_BUTTON_SLOT_STATUS_T * fl_sed_button_status_SP = &l_sed_button_status_S[0];
                    l_remap_button_id_U16 = p_button_id_U16;
                    l_remap_target_ls_id  = p_target_ls_id;
                    fl_count_U8           = LSH_NUMBER_OF_BUTTON_SLOTS;
                    while (fl_count_U8 > 0)
                    {
                        fl_count_U8--;
                        if ((fl_sed_button_status_SP->button_id      == p_button_id_U16) &&
                            (fl_sed_button_status_SP->logic_state_id != LSH_NUMBER_OF_LOGIC_STATES))
                        {
                            /* reassign the slot and exit loop */
                            fl_sed_button_status_SP->logic_state_id = p_target_ls_id;
                            fl_count_U8                             = 0;
                            /* we were able to find the button ID, so clear the request from store */
                            l_remap_button_id_U16                   = LSH_INVALID_BUTTON_ID;
                            l_remap_target_ls_id                    = LSH_NUMBER_OF_LOGIC_STATES;
                        }
                        else
                        {
                            fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
                        }
                    }
                }
            }
        }
    }
    else
    {
        /*
        ** LSH_NUMBER_OF_LOGIC_STATES is specified as target state so clear the
        ** registred slots with p_source_ls_id to allow a re-distribution of
        ** registered button events.
        */
        UINT8 fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
        LSH_BUTTON_SLOT_STATUS_T * fl_sed_button_status_SP = &l_sed_button_status_S[0];
        while (fl_count_U8 > 0)
        {
            fl_count_U8--;
            if (fl_sed_button_status_SP->button_id == p_button_id_U16)
            {
                /* init the slot and exit the loop */
                fl_sed_button_status_SP->button_id      = LSH_INVALID_BUTTON_ID;
                fl_sed_button_status_SP->state          = LSH_BUTTON_INACTIVE_STATE;
                fl_sed_button_status_SP->logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
                fl_count_U8                             = 0;
            }
            else
            {
                fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
            }
        }
    }

}

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/*============================================================================
 ** Function Name:    hmi_lsh_animation_done_cb()
 ** Visibility:       global
 ** Description:      This function is the callback function for the animation
 **                   completion.
 ** Invocation:       Invoked by Animation components when on completing an animation.
 **
 ** Inputs/Outputs:   in  - Logic state id to be activated in p_logic_state_id_U8.
 ** Critical Section: None.
 ** Created:          23-Jun-2010 by GPURUSO1
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
static void hmi_lsh_animation_done_cb(UINT8 p_prio_U8, UINT8 p_logic_state_id_U8, ANIMATION_ID p_anim_ID, UINT8 p_anim_client_id_U8)
{
    if (p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
        LSH_FOCUS_HANDLER_STATUS_T  fl_focus_hndl_status_S;
        LSH_STATE_ID_T                fl_active_state;
        LSH_STATE_ID_T                fl_anim_r_state;
        LSH_STATE_ID_T                fl_anim_q_state;
        UINT8                         fl_priority_U8;
        UINT8                         fl_lsh_status_U8  = LSH_INVALID_STATUS;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

        if (fl_priority_U8 < fl_dpm_config_SP->size)
        {
            /*
            ** Throw focus callback only if there are no more pending animations
            ** either running or in queue for the active state.
            */
            fl_anim_r_state = hmi_anim01_get_current_animation_state(fl_priority_U8);
            fl_anim_q_state = hmi_anim01_get_queued_animation_state(fl_priority_U8);
            if((fl_anim_r_state != p_logic_state_id_U8) && (fl_anim_q_state != p_logic_state_id_U8))
            {
                fl_active_state = fl_dpm_config_SP->ptr[fl_priority_U8];
                if(fl_active_state == p_logic_state_id_U8)
                {
                    if(fl_priority_U8 >= *fl_dpm_config_SP->hap_ptr)
                    {
                        /* The state is active in LSH and is the highest priority one */
                        fl_lsh_status_U8 = (LSH_GOT_FOCUS_STATUS|LSH_ANIM_COMPLETE_STATUS);
                    }
                    else
                    {
                        /* The state is active in LSH and is not the highest priority one */
                        fl_lsh_status_U8 = (LSH_LOST_FOCUS_STATUS|LSH_ANIM_COMPLETE_STATUS);
                    }
                }
                else
                {
                    /* The state is no more active in LSH */
                    fl_lsh_status_U8 = (LSH_DEACTIVATED_STATUS|LSH_ANIM_COMPLETE_STATUS);
                }
                /*
                ** Call the Focus Handler to inform of the completion of the animation
                ** and to notify of their focus status
                */
                if (fl_state_conf_SP->handler_idx < LSH_NUMBER_OF_EV_HANDLERS)
                {
                    fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
                    if (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER)
                    {
                        fl_focus_hndl_status_S.logic_state_id = p_logic_state_id_U8;
                        fl_focus_hndl_status_S.focus_status   = fl_lsh_status_U8;
                        if(*fl_dpm_config_SP->hap_ptr >= fl_dpm_config_SP->size)
                        {
                            fl_focus_hndl_status_S.focus_id = LSH_NUMBER_OF_LOGIC_STATES;
                        }
                        else
                        {
                            fl_focus_hndl_status_S.focus_id = fl_dpm_config_SP->ptr[*fl_dpm_config_SP->hap_ptr];
                        }
						fl_focus_hndl_status_S.client_id  =p_anim_client_id_U8;

                        fl_handler_SP->focus(&fl_focus_hndl_status_S);
                    }
                }
            }
        }
    }
}
#endif

/*============================================================================
 ** Function Name:    void hmi_lsh_add_state()
 ** Visibility:       global
 ** Description:      This function adds the passed logic state to the priority
 **                   table. If this has a higher priority than the the activate
 **                   states in the table, then a focus lost notification is
 **                   given to the next low priority state.
 **                   If a logic state is replaced then call the presentation
 **                   of the removed state to notify that the logic state is
 **                   deactivated so that it can perform any display removal
 **                   activities.
 ** Invocation:       Invoked by logic components when ever it needs a logic state
 **                   to be activated.
 ** Inputs/Outputs:   in  - Logic state id to be activated in p_logic_state_id_U8.
 **                   out - Bitwise OR of the following
 **                         LSH_INVALID_STATUS    if passed state id is invalid
 **                         LSH_LOST_FOCUS_STATUS if passed state is added and is
 **                                               not having focus currently.
 **                         LSH_GOT_FOCUS_STATUS  if passed state is added and is
 **                                               having focus currently.
 **                         LSH_ANIM_STARTED_STATUS if animation is requested and
 **                                                 accepted by the anim core.
 **                                                 in this case a focus callback
 **                                                 will be made on completion of
 **                                                 animation
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
UINT8 hmi_lsh_add_state(  LSH_STATE_ID_T p_logic_state_id_U8
                       #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                        , ANIMATION_ID   p_anim_id
                       #endif
                       )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;
	
	fl_focus_state_U8 = hmi_lsh_add_state_ext(p_logic_state_id_U8	
                       #ifdef LSH_ANIMATION_SUPPORT_ENABLED			
                        ,p_anim_id									
                       #endif										
					   ,LSH_INVALID_CLIENT_ID
                       );


    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_remove_state
 ** Visibility:       global
 ** Description:      This function removes the passed logic state from the priority
 **                   table. If this was the highest priority state, then a focus
 **                   gained notification is given to the next high priority state.
 **                   Also calls the presentation to notify that the logic state is
 **                   deactivated so that it can perform any display removal
 **                   activities.
 ** Invocation:       Invoked by logic components when ever it needs a logic state
 **                   to be deactivated.
 ** Inputs/Outputs:   in  - Logic state id to be deactivated in p_logic_state_id_U8.
 **                   out - Bitwise OR of the following
 **                         LSH_INVALID_STATUS     if passed state id is invalid
 **                         LSH_DEACTIVATED_STATUS if passed state is removed.
 **                         LSH_ANIM_STARTED_STATUS if animation is requested and
 **                                                 accepted by the anim core.
 **                                                 in this case a focus callback
 **                                                 will be made on completion of
 **                                                 animation
 ** Critical Section: None.
 ** Created:          19-Feb-2010 by EMANOJ1
 ** Updated:          15-Dec-2011 by CMUTHUSA
 **==========================================================================*/
UINT8 hmi_lsh_remove_state(  LSH_STATE_ID_T p_logic_state_id_U8
                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                           , ANIMATION_ID p_anim_id
                          #endif
                          )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

	fl_focus_state_U8 = hmi_lsh_remove_state_ext(p_logic_state_id_U8	
                       #ifdef LSH_ANIMATION_SUPPORT_ENABLED				
                        ,p_anim_id										
                       #endif											
					   ,LSH_INVALID_CLIENT_ID
                       );

    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_highest_active_priority_state()
 ** Visibility:       global
 ** Description:      This function returns the current high active priority state
 **                   from the LSH prioritytable. 
 ** Invocation:       Invoked by logic components when ever high active priority state
 **                   to be known from LSH priority table.
 ** Inputs/Outputs:   in  - LSH_STATE_ID_T p_logic_state_id_U8
 **                   out - LSH_STATE_ID_T fl_highest_active_state_U8 - Highest active state
 ** Critical Section: None.
 ** Created:          21-Dec-2011 by CMUTHUSA
 ** Updated:          21-Dec-2011 by CMUTHUSA
 **==========================================================================*/
LSH_STATE_ID_T hmi_lsh_highest_active_priority_state(LSH_STATE_ID_T p_logic_state_id_U8)
{
	LSH_STATE_ID_T fl_highest_active_state_U8 = LSH_NUMBER_OF_LOGIC_STATES;

    if (p_logic_state_id_U8 < LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
		UINT8 fl_lsh_hap_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
		fl_lsh_hap_U8 = *fl_dpm_config_SP->hap_ptr;
		
		if (fl_lsh_hap_U8 < fl_dpm_config_SP->size)
		{
			fl_highest_active_state_U8 = fl_dpm_config_SP->ptr[fl_lsh_hap_U8];
		}
	}	
    return(fl_highest_active_state_U8);
}

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
 ** CMS Rev 1.29      22-MAY-2015    NKRISHN9
 ** Change the interface of focus, event(default event) and presentation handler to vm02
 **
 ** CMS Rev 1.28      21-Dec-2011    CMUTHUSA
 ** Added Interface to return the highest active priority state from the LSH Stack
 **
 ** CMS Rev 1.27      16-Dec-2011    CMUTHUSA
 ** Ref. BSDI00111721,PR Defect Fix : 49842
 ** Focus Status Sync missing between LSH, Popup, Animation cores Fix -
 **	a new structure memeber client_id is introduced in LSH_FOCUS_HANDLER_STATUS_T structure,
 ** pointer handler for the client_id is introduced in LSH_DPM_STACK_CONF_T structure
 ** the new interfaces hmi_lsh_add_state_ext,hmi_lsh_remove_state_ext are added with client_id 
 ** as additional parameter and the client id is stacked in LSH_DPM_STACK_CONF_T & passed 
 ** in the repective focus handler & Animation call invocations.
 **
 ** CMS Rev 1.26     06-Jul-2011    EMANOJ1
 ** Ref. BSDI00106633
 ** When deactivation is executed for priority N and an animation was in progress
 ** for priority N, flag fl_ack_deactivation was set to FALSE indicating that the
 ** presentation will not be executed with LSH_DEACTIVATED_STATUS. If for any of
 ** the next priorities (N+1 onwards) if deactivation was pending and no animation
 ** for that priority, a logical error of not resetting the fl_ack_deactivation
 ** flag caused the deact_ptr[] clearing. This prevented the writing of new deactivations
 ** in to the array and hence the presentation deactivated was getting missed.
 ** Now code is updated to set fl_ack_deactivation to TRUE on every priority iteration
 **
 ** CMS Rev 1.25     17-Jun-2011    EMANOJ1
 ** Ref. Review while integrating 1.24 and 1.23
 ** Updated hmi_lsh_animation_done_cb() to load fl_focus_hndl_status_S.focus_id with
 ** logic state ID of highest active priority pointed by *fl_dpm_config_SP->hap_ptr
 ** rather than loading the p_logic_state_id_U8 itself.
 **
 ** CMS Rev 1.24    16-JUN-2011    VSARAVA2
 ** PR-44988 PR fix. 1.Structure decalred as function local. 2. focus_id initilized in
 ** lsh_animation_done_cb().
 ** BSDI00102619 - This LSH change done to send the existing/new logic state id to focus
 ** handler function. So that application specific focus handler can check the focus_id
 ** and take decision to remove existing screen to not.
 **
 ** CMS Rev 1.23    14-JUN-2011    VSARAVA2/EMANOJ1
 ** All focus handler function calling parameter changed to strucutre to support
 ** future modifications
 **
 ** CMS Rev 1.22     17-Jun-2011    EMANOJ1
 ** Ref. Unit testing
 ** To fix the following issues
 ** 1. LSH_DEACTIVATED_STATUS is not called after passing LSH_DEACT_PENDING_STATUS
 **    because the deact_ptr[] got cleared. Now prevented the clearing of deact_ptr[]
 **    if animation is pending.
 ** 2. When a popup gets deactivated with animation, its presentation will get
 **    LSH_DEACT_PENDING_STATUS which will cause it to deactivate its layers. So
 **    animation won't be visible. So if the animation is for the deactivated popup
 **    itself, then no need to pass the LSH_DEACT_PENDING_STATUS.
 **
 ** CMS Rev 1.21     16-Jun-2011    EMANOJ1
 ** Ref. BSDI00101615
 ** hmi_lsh_task updated to pass LSH_DEACT_PENDING_STATUS to presentation, if the
 ** logic state got removed but an animation is in progress on the priority.
 ** In this case LSH_DEACT_PENDING_STATUS will be given to presentation until
 ** the animation on its priority ends. After animation finishes a LSH_DEACTIVATED_STATUS
 ** will be issues as before.
 **
 ** CMS Rev 1.20     06-Apr-2011    EMANOJ1
 ** hmi_lsh_execute_presentation updated fix an array overindex issue per
 ** SMIS PR.ID.42589 issue#1
 **
 ** CMS Rev 1.19     30-Mar-2011    EMANOJ1
 ** hmi_lsh_execute_presentation updated to fix issue reported by vmuthusu
 ** that presentation is not called with LSH_DEACTIVATED_STATUS if a logic
 ** state is removed.
 **
 ** CMS Rev 1.18     03-Jan-2011    EMANOJ1
 ** hmi_lsh_animation_done_cb updated to fix an issue where the focus handler
 ** was not invoked initimating a logic state deactivation after animation.
 **
 ** CMS Rev 1.17     29-Dec-2010    EMANOJ1
 ** Introduced l_remap_button_id_U16 and l_remap_target_ls_id to store the request
 ** if the hmi_lsh_remap_button_events() cannot find the button ID in any of the
 ** slots. This was added to handle a case where the hmi_lsh_remap_button_events()
 ** was called from an event handler during ButtonX's first event. In this scenario
 ** hmi_lsh_remap_button_events() will not find ButtonX in any of the slots as it
 ** is not registered. So hmi_lsh_remap_button_events() will fail in this case
 ** To overcome this, under this scenario hmi_lsh_remap_button_events will store the
 ** request in to l_remap_button_id_U16 and l_remap_target_ls_id AND the
 ** hmi_lsh_post_button_event will do the remap after ButtonX is registered.
 **
 ** CMS Rev 1.16     28-Dec-2010    EMANOJ1
 ** hmi_lsh_remove_state updated to pass return status as LSH_DEACTIVATED_STATUS
 ** if animation is not done by animation core.
 **
 ** CMS Rev 1.15     27-Dec-2010    EMANOJ1
 ** 1. hmi_lsh_add_state
 **    a. modified to update the LSH stack with passed state immediately
 **       With this change hmi_lsh_add_state_confirmed function is no longer required
 **       and so is removed.
 **    b. hmi_lsh_add_state is modified to have return status in LSH_ANIMATION_SUPPORT_ENABLED
 **       build as well.
 **    c. Modified hmi_lsh_add_state to provide LSH_ANIM_STARTED_STATUS as a status to
 **       focus handler when an animation is requested to is in progress with animation
 **       core.
 ** 2. hmi_lsh_remove_state
 **    a. modified to perform a removal of state from the LSH stack
 **       immediately. With this change hmi_lsh_remove_state_confirmed is no longer
 **       required and so is removed.
 **    b. Modified to have return status indicating removal and animation progress.
 ** 3. Added hmi_lsh_animation_done_cb for the animation core to indicate
 **    completion of animations.
 ** 4. Added hmi_lsh_remap_button_events to remap a button ID to a new logic state
 **
 ** CMS Rev 1.14     23-Dec-2010    GPURUSO1
 ** Added support to block only the individual Priorit's Presentation
 ** when an animation is active for that priority
 **
 ** ** CMS Rev 1.13     20-Dec-2010    GPURUSO1
 ** Moved the definition of the macro to block the presenation to the .cfg.
 ** Modified the code of the focus handler to have the ANIMATION_COMPLETED status
 ** only to the valid animations.
 **
 ** CMS Rev 1.12     18-Oct-2010    EMANOJ
 ** Modified the default Initialisation for the Button Handlers to LSH_STATUS_NONE
 ** so that when there are no states added the button events are handled by the
 ** default button handlers.
 ** Handled the Return type of the Button Handler if the press event is already
 ** registered with a state, And if the state is not processing the later button
 ** events, the events are routed to the default button handlers
 **
 ** CMS Rev 1.11     16-Jul-2010    EMANOJ
 ** Ref-SMIS PR-ID 34516
 ** Updated hmi_lsh_task to Optimize the for loop.
 **
 ** CMS Rev 1.10     14-Jul-2010    EMANOJ
 ** Ref-BSDI00090066
 ** Updated hmi_lsh_task to first invoke all deactivated presetation callbacks
 ** followed by the active ones so that the layers can be deallocated before
 ** building the new displays in Kepler platform (C520).
 ** Called the presetation from low priority to high priority so that the layer
 ** allocation can be done in increasing priority order by the presentation.
 **
 ** CMS Rev 1.9      10-Jul-2010    EMANOJ
 ** Remembering the previous state for registering the button press when there
 ** is change in the state triggered by the RX handler.
 **
 ** CMS Rev 1.8      10-Jul-2010    GPURUSO1
 ** Added code for the boundary checking for out of range for lc_lsh_ev_handler_config_SA.
 **
 ** CMS Rev 1.7      25-Jun-2010    GPURUSO1
 ** Added support for the Animation. An Parameter has been added to the public
 ** interface and the code flow has been modified.
 **
 ** CMS Rev 1.6      25-May-2010    EMANOJ1
 ** hmi_lsh_post_button_event updated to fix a scenario where the button event
 ** handler itself caused a hmi_lsh_remove_state and thus removing the state.
 ** This caused the button event to be passed on to the default event handler.
 **
 ** CMS Rev 1.5      12-May-2010    EMANOJ1
 ** LSH_EVENT_HANDLER_T updated to pass logic state id also as a parameter.
 **
 ** CMS Rev 1.4      16-Apr-2010    EMANOJ1
 ** Added return value for hmi_lsh_add_state() to initimate the caller, whether
 ** the specified state has got the focus or not.
 **
 ** CMS Rev 1.3      16-Apr-2010    GYUVAMAT
 ** Fixed QAC warnings.
 **
 ** CMS Rev 1.2      17-Mar-2010    VMUTHUSU
 ** Initialize the fl_return_state_U8 variable to LSH_STATUS_NONE and update it
 ** with the return value of the event handler after it was invoked so that the
 ** default handler will be invoked correctly.
 **
 **
 ** CMS Rev 1.1      11-Mar-2010    EMANOJ1
 ** Added LSH_DEFAULT_BUTTON_EVENT_HANDLER function to hmi_lsh_post_button_event()
 ** to handle unhandled button events. Changed the return type of
 ** hmi_lsh_post_button_event to void.
 **
 ** CMS Rev 1.0      19-Feb-2010    EMANOJ1
 ** Creation.
 **==========================================================================*/

/* end of file =============================================================*/

