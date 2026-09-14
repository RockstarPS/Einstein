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

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_view_manager_02_autocode.h"
#include "hmi_view_manager_02.h"
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*
** Typedefine to hold the configuration associated to a logic state.
** priority    - Priority of the logic state.
** layer_id    - Layer ID of the logic state.
** handler_idx - Index in to event handler functions in l_lsh_ev_handler_config_SA[].
*/
typedef struct
{
   UINT8 priority;
   UINT8 handler_idx;
   UINT8 layer_id;
}LSH_DISP_STATE_CONF_T;

/*
** Type defines to hold the display priority stack configuration for a layer.
** ptr        - Pointer to a prioty stack LSH_STATE_ID_T array
** deact_ptr  - Pointer to LSH_STATE_ID_T array where deactivated states are stored. This
**              used by the hmi_lsh_task() to decide whether the presentation
**              callback to be invoked to notify the deactivations.
** change_ptr - Indicates that either ptr or deact_ptr contents are updated due to
**              a hmi_lsh_add_state() or hmi_lsh_remove_state()
** hap_ptr    - Pointer to a UINT8 which hold the highest active priority (hap)
**              for the layer.
** size       - Specifies the size of priority stack.
*/
typedef struct
{
   SFhmi_view_manager_02InstanceStruct * vm_ptr;
   UINT8                               * hap_ptr;
   UINT8                                 size;
}LSH_DPM_STACK_CONF_T;

#include "hmi_logic_state_handler.dat"
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/



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
static volatile UINT16         l_remap_button_id_U16;
static volatile LSH_STATE_ID_T l_remap_target_ls_id;
static volatile UINT8          l_remap_target_ls_client_id;

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
 ** Updated:          29-Dec-2010 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_initialize(UINT8 p_init_type_U8)
{
    UINT8 fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
    UINT8 fl_layer_id_U8;

    hmi_view_manager_02_initializer();

    /*
    ** Free all button slots
    */
    while (fl_count_U8 > (UINT8)0)
    {
        fl_count_U8--;
		l_sed_button_status_S[fl_count_U8].button_id = LSH_INVALID_BUTTON_ID;
        l_sed_button_status_S[fl_count_U8].state = LSH_BUTTON_INACTIVE_STATE;
        l_sed_button_status_S[fl_count_U8].logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
        l_sed_button_status_S[fl_count_U8].client_id = (UINT8)LSH_INVALID_CLIENT_ID; 
        
    }

    /*
    ** Free all the logic current display state, previous state
    ** and stack changed flags.
    */
#if LSH_NUMBER_OF_LAYERS > 1
	fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
    while(fl_layer_id_U8 > (UINT8)0)
	{
		fl_layer_id_U8--;	
#else
		fl_layer_id_U8 = 0;
#endif  
	    
        

		fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];

		if (fl_dpm_config_SP->size > (UINT8)0)
		{
			SFhmi_view_manager_02InstanceStruct * fl_dpm_stack_P = fl_dpm_config_SP->vm_ptr;

			fl_count_U8 = 0;

			while (fl_count_U8 < fl_dpm_config_SP->size)
			{
				initialize_hmi_view_manager_02(fl_dpm_stack_P);
				fl_dpm_stack_P++;
				fl_count_U8++;
			}
			*fl_dpm_config_SP->hap_ptr = fl_dpm_config_SP->size;
		}
#if LSH_NUMBER_OF_LAYERS > 1		
    }
#endif	
    l_remap_button_id_U16 = LSH_INVALID_BUTTON_ID;
    l_remap_target_ls_id  = LSH_NUMBER_OF_LOGIC_STATES;
    l_remap_target_ls_client_id  = (UINT8)LSH_INVALID_CLIENT_ID;
    HMI_UNUSED_VAR(p_init_type_U8);
}

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
 ** Updated:          27-Dec-2010 by EMANOJ1
 **==========================================================================*/
UINT8 hmi_lsh_add_state(LSH_STATE_ID_T    p_logic_state_id_U8
                     #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                       ,UINT8 p_anim_id
                     #endif
                       )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

    if (p_logic_state_id_U8 <(LSH_STATE_ID_T) LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                hmi_vm_add_state(  &fl_dpm_config_SP->vm_ptr[fl_priority_U8],
                                    LSH_VM_STATE_ID(LSH_INVALID_CLIENT_ID,p_logic_state_id_U8),
                                #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                p_anim_id
                                #else
                                ANIM_MAX_ID
                                #endif
                                );
                fl_focus_state_U8 = 0;
            }
        }
    }
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
 ** Updated:          29-Dec-2010 by EMANOJ1
 **==========================================================================*/
UINT8 hmi_lsh_remove_state(  LSH_STATE_ID_T p_logic_state_id_U8
                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                           , UINT8 p_anim_id
                          #endif
                          )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

    if (p_logic_state_id_U8 < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
	            hmi_vm_remove_state(  &fl_dpm_config_SP->vm_ptr[fl_priority_U8],
	                                LSH_VM_STATE_ID(LSH_INVALID_CLIENT_ID,p_logic_state_id_U8),
	                               #ifdef LSH_ANIMATION_SUPPORT_ENABLED
	                                  p_anim_id
	                               #else
	                                  ANIM_MAX_ID
	                               #endif
	                               );
                fl_focus_state_U8 = 0;
            }
        }
    }
    return(fl_focus_state_U8);
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
 ** Updated:          27-Dec-2010 by EMANOJ1
 **==========================================================================*/
UINT8 hmi_lsh_add_state_ext(  LSH_STATE_ID_T p_logic_state_id_U8
                       #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                        , UINT8   p_anim_id
                       #endif
                       ,UINT8 p_client_id_U8
                       )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

    if (p_logic_state_id_U8 < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
	            hmi_vm_add_state(  &fl_dpm_config_SP->vm_ptr[fl_priority_U8],
	                            LSH_VM_STATE_ID(p_client_id_U8,p_logic_state_id_U8),
	                            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
	                               p_anim_id
	                            #else
	                               ANIM_MAX_ID
	                            #endif
	                            );
	            fl_focus_state_U8 = 0;
            }
        }
    }
    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_remove_state_ext
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
 ** Updated:          29-Dec-2010 by EMANOJ1
 **==========================================================================*/
UINT8 hmi_lsh_remove_state_ext(  LSH_STATE_ID_T p_logic_state_id_U8
                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                           , UINT8 p_anim_id
                          #endif
                          ,UINT8 p_client_id_U8
                          )
{
    UINT8 fl_focus_state_U8 = LSH_INVALID_STATUS;

    if (p_logic_state_id_U8 < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                hmi_vm_remove_state(  &fl_dpm_config_SP->vm_ptr[fl_priority_U8],
                            LSH_VM_STATE_ID(p_client_id_U8,p_logic_state_id_U8),
                            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                               p_anim_id
                            #else
                               ANIM_MAX_ID
                            #endif
                               );
            	fl_focus_state_U8 = 0;
            }
        }
    }
    return(fl_focus_state_U8);
}

/*============================================================================
 ** Function Name:    hmi_lsh_get_focus_status
 ** Visibility:       global
 ** Description:      This function returns the focus status for the requested
 **                   logic state ID.
 ** Invocation:       Invoked by VM statemachine and application when required.
 ** Inputs/Outputs:   in  - Logic state id in p_logic_state_id_U8.
 **                   out - any of the following
 **                         LSH_FOCUS_STATUS_INACTIVE if none of the states has
 **                                                   focus
 **                         LSH_FOCUS_STATUS_OK if requested state has focus
 **                         LSH_FOCUS_STATUS_HIDEN if requested state has no
 **                                                focus
 **                         LSH_FOCUS_STATUS_INVALID invalid state id passed
 ** Critical Section: None.
 ** Created:          07-Apr-2011 by EMANOJ1
 ** Updated:          07-Apr-2011 by EMANOJ1
 **==========================================================================*/
UINT32 hmi_lsh_get_focus_status(LSH_STATE_ID_T p_logic_state_id_U8)
{
    LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    UINT32                        fl_priority_U8;
    UINT32 fl_status_U32 = LSH_FOCUS_STATUS_INVALID;

    if(p_logic_state_id_U8 <(LSH_STATE_ID_T) LSH_NUMBER_OF_LOGIC_STATES)
    {
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (*fl_dpm_config_SP->hap_ptr >= fl_dpm_config_SP->size)
            {
	            /*
	            ** There is no High Priority state available
	            */
            	fl_status_U32 = LSH_FOCUS_STATUS_INACTIVE;
            }
            else if (*fl_dpm_config_SP->hap_ptr == fl_priority_U8)
            {
	            /*
	            ** Passes state is the Highest priority state
	            */
            	fl_status_U32 = LSH_FOCUS_STATUS_OK;
            }
            else
            {
	            /*
	            ** Passed state is hidden below another high priority
	            ** state.
	            */
	            fl_status_U32 = LSH_FOCUS_STATUS_HIDEN;
            }
        }
    }
    else
    {
        fl_status_U32 = LSH_FOCUS_STATUS_INVALID;
    }
    return(fl_status_U32);
}

/*============================================================================
 ** Function Name:    hmi_lsh_focus_handler
 ** Visibility:       private
 ** Description:      This function invokes the focus handler of passed state.
 ** Invocation:       Invoked by VM statemachine only.
 ** Inputs/Outputs:   in  - Logic state id in p_logic_state_id_U8.
 **                         focus status in p_status_U8
 **                   out - none
 ** Critical Section: None.
 ** Created:          07-Apr-2011 by EMANOJ1
 ** Updated:          26-Jan-2014 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_focus_handler(UINT16 p_logic_state_id_U16, UINT8 p_status_U8)
{
#if LSH_NUMBER_OF_EV_HANDLERS > 0
    LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
    LSH_FOCUS_HANDLER_T         * fl_focus_handler_FP;
    UINT32                        fl_priority_U8;
    LSH_FOCUS_HANDLER_STATUS_T    fl_focus_hndl_status_S;

    if(LSH_GET_STATE_ID((p_logic_state_id_U16)) <(LSH_STATE_ID_T) LSH_NUMBER_OF_LOGIC_STATES)
    {
		fl_state_conf_SP = &lc_lsh_screen_config_SA[LSH_GET_STATE_ID((p_logic_state_id_U16))];
		fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            fl_focus_hndl_status_S.logic_state_id = LSH_GET_STATE_ID((p_logic_state_id_U16));
            fl_focus_hndl_status_S.client_id = LSH_GET_CLIENT_ID((p_logic_state_id_U16));
            fl_focus_hndl_status_S.focus_status = p_status_U8;

            if (fl_state_conf_SP->handler_idx < (UINT8)LSH_NUMBER_OF_EV_HANDLERS)
            {
                fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];

                if ((fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER) && (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER))
                {
                    fl_focus_handler_FP = fl_handler_SP->focus;

                    if ((p_status_U8 & LSH_GOT_FOCUS_STATUS) != (UINT8)0)
                    {
                        if ((*fl_dpm_config_SP->hap_ptr >= fl_dpm_config_SP->size) ||
                            (*fl_dpm_config_SP->hap_ptr <= fl_priority_U8))
                        {
                            if (*fl_dpm_config_SP->hap_ptr < fl_priority_U8)
                            {
                                /*
                                ** Passed priority is higher than the hap_ptr, so
                                ** Issue lost focus notification to the HAP state.
                                */
                                LSH_FOCUS_HANDLER_STATUS_T fl_hap_focus_hndl_sts_S;
                                UINT32 fl_hap_handler_index;
                                LSH_EV_HANDLER_CONF_T const *fl_hap_handler_SP;

                                fl_hap_focus_hndl_sts_S.logic_state_id = LSH_GET_STATE_ID((fl_dpm_config_SP->vm_ptr[*fl_dpm_config_SP->hap_ptr].l_gfx_active_state_id));

                                if (fl_hap_focus_hndl_sts_S.logic_state_id < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
                                {
                                    fl_hap_handler_index = lc_lsh_screen_config_SA[fl_hap_focus_hndl_sts_S.logic_state_id].handler_idx;
                                    if (fl_hap_handler_index < (UINT32)LSH_NUMBER_OF_EV_HANDLERS)
                                    {
                                        fl_hap_handler_SP = &lc_lsh_ev_handler_config_SA[fl_hap_handler_index];
                                        if (fl_hap_handler_SP->focus != LSH_NULL_FOCUS_HANDLER)
                                        {
                                            fl_hap_focus_hndl_sts_S.focus_id = LSH_GET_STATE_ID((p_logic_state_id_U16));
                                            fl_hap_focus_hndl_sts_S.focus_status = LSH_LOST_FOCUS_STATUS;
                                            fl_hap_focus_hndl_sts_S.client_id = LSH_GET_CLIENT_ID((fl_dpm_config_SP->vm_ptr[*fl_dpm_config_SP->hap_ptr].l_gfx_active_state_id));
                                            fl_hap_handler_SP->focus(&fl_hap_focus_hndl_sts_S);
    #ifdef LSH_FOCUS_STATUS_FOR_ALL_SCREEN
                                            LSH_FOCUS_STATUS_FOR_ALL_SCREEN(&fl_hap_focus_hndl_sts_S);
    #endif
                                        }
                                    }
                                }
                            }
                            /*
                            ** Update the heighest active priority if
                            ** 1. passed state is of greater priority than hap_ptr OR
                            ** 2. if the hap_ptr is invalid
                            */
                            if ((fl_focus_handler_FP != LSH_NULL_FOCUS_HANDLER) && (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER))
                            {
                                if (*fl_dpm_config_SP->hap_ptr >= fl_dpm_config_SP->size)
                                {
                                    fl_focus_hndl_status_S.focus_id = fl_focus_hndl_status_S.logic_state_id;
                                }
                                else
                                {
                                    fl_focus_hndl_status_S.focus_id = LSH_GET_STATE_ID((fl_dpm_config_SP->vm_ptr[*fl_dpm_config_SP->hap_ptr].l_gfx_active_state_id));
                                }
                                fl_focus_hndl_status_S.focus_status = p_status_U8;
                                fl_handler_SP->focus(&fl_focus_hndl_status_S);
    #ifdef LSH_FOCUS_STATUS_FOR_ALL_SCREEN
                                LSH_FOCUS_STATUS_FOR_ALL_SCREEN(&fl_focus_hndl_status_S);
    #endif
                            }
                            *fl_dpm_config_SP->hap_ptr = (UINT8)fl_priority_U8;
                        }
                        else
                        {
                            /*
                            ** Not the heighest priority state, so pass the status as
                            ** LSH_LOST_FOCUS_STATUS.
                            */
                            if ((fl_focus_handler_FP != LSH_NULL_FOCUS_HANDLER) && (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER))
                            {
                                fl_focus_hndl_status_S.focus_status &= LSH_GOT_FOCUS_CLR_STATUS;
                                fl_focus_hndl_status_S.focus_status |= LSH_LOST_FOCUS_STATUS;
                                fl_focus_hndl_status_S.focus_id = LSH_GET_STATE_ID((fl_dpm_config_SP->vm_ptr[*fl_dpm_config_SP->hap_ptr].l_gfx_active_state_id));
                                fl_handler_SP->focus(&fl_focus_hndl_status_S);
    #ifdef LSH_FOCUS_STATUS_FOR_ALL_SCREEN
                                LSH_FOCUS_STATUS_FOR_ALL_SCREEN(&fl_focus_hndl_status_S);
    #endif
                            }
                        }
                    }
                    else
                    {
                        if ((p_status_U8 & LSH_DEACTIVATED_STATUS) != (UINT8)0)
                        {
                            /*
                            ** Reset the HAP if the HAP matches with the deactivated
                            ** states priority.
                            */
                            if (*fl_dpm_config_SP->hap_ptr == fl_priority_U8)
                            {
                                *fl_dpm_config_SP->hap_ptr = fl_dpm_config_SP->size;
                            }
                        }
                        if ((fl_focus_handler_FP != LSH_NULL_FOCUS_HANDLER) && (fl_handler_SP->focus != LSH_NULL_FOCUS_HANDLER))
                        {
                            fl_focus_hndl_status_S.focus_id = LSH_GET_STATE_ID((p_logic_state_id_U16));
                            fl_handler_SP->focus(&fl_focus_hndl_status_S);
    #ifdef LSH_FOCUS_STATUS_FOR_ALL_SCREEN
                            LSH_FOCUS_STATUS_FOR_ALL_SCREEN(&fl_focus_hndl_status_S);
    #endif
                        }
                    }
                }
            }
        }
    }
#endif
}

/*============================================================================
 ** Function Name:    hmi_lsh_run_presentation
 ** Visibility:       private
 ** Description:      This function invokes the presentation handler of passed state.
 ** Invocation:       Invoked by VM statemachine only.
 ** Inputs/Outputs:   in  - Logic state id in p_logic_state_id_U8.
 **                         status in p_status_U8
 **                         client id in p_client_id
 **                   out - none
 ** Critical Section: None.
 ** Created:          07-Apr-2011 by EMANOJ1
 ** Updated:          27-aug-2013 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_run_presentation(UINT16 p_logic_state_id_U16, UINT8 p_status)
{
#if LSH_NUMBER_OF_EV_HANDLERS > 0
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
    LSH_PRESN_HANDLER_STATUS_T fl_handler_status_S;
    if((LSH_GET_STATE_ID((p_logic_state_id_U16))) < (UINT8)LSH_NUMBER_OF_LOGIC_STATES)
    {
       fl_state_conf_SP = &lc_lsh_screen_config_SA[LSH_GET_STATE_ID((p_logic_state_id_U16))];
       if (fl_state_conf_SP->handler_idx < (UINT8)LSH_NUMBER_OF_EV_HANDLERS)
       {
          fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_state_conf_SP->handler_idx];
          if (fl_handler_SP->presentation != LSH_NULL_PRESN_HANDLER)
          {
             fl_handler_status_S.logic_state_id = LSH_GET_STATE_ID((p_logic_state_id_U16));
             fl_handler_status_S.presentation_status = p_status;
             fl_handler_status_S.client_id = LSH_GET_CLIENT_ID((p_logic_state_id_U16));
             fl_handler_SP->presentation(&fl_handler_status_S);
          }
       }
    }
#endif
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
 ** Updated:          06-Apr-2011 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_execute_presentation(UINT16 p_logic_state_id_U16)
{
    if (LSH_GET_STATE_ID((p_logic_state_id_U16)) < (UINT8)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[LSH_GET_STATE_ID((p_logic_state_id_U16))];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                hmi_vm_force_presentation(&fl_dpm_config_SP->vm_ptr[fl_priority_U8]);
            }
        }
    }
}

/*============================================================================
 ** Function Name:    hmi_lsh_task_ext
 ** Visibility:       global
 ** Description:      hmi_lsh_task() executes all the logic states where as 
 **                   this function executes the lsh task for a given logic state
 **                   This can be used by application if they wish to selectively 
 **                   run the lsh task for specific states.
 ** Invocation:       .
 ** Inputs/Outputs:   None.
 ** Critical Section: None.
 ** Created:          17-Jan-2015 by EMANOJ1
 ** Updated:          17-Jan-2015 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_task_ext(UINT16 p_logic_state_id_U16)
{
    if (LSH_GET_STATE_ID((p_logic_state_id_U16)) < (UINT8)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[LSH_GET_STATE_ID((p_logic_state_id_U16))];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                hmi_vm_tick(&fl_dpm_config_SP->vm_ptr[fl_priority_U8]);
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
 ** Updated:          16-Jul-2010 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_task(void)
{
    LSH_DPM_STACK_CONF_T const *fl_dpm_config_SP;
    SFhmi_view_manager_02InstanceStruct *fl_vm_instance_SP;
    UINT32 fl_layer_id_U8;

    SINT32 fl_priority_S8;
#if LSH_NUMBER_OF_LAYERS > 1
    fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
    while (fl_layer_id_U8 > (UINT8)0)
    {
        fl_layer_id_U8--;
#else
    fl_layer_id_U8 = 0;
#endif

        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];
        fl_priority_S8 = (SINT32)fl_dpm_config_SP->size;
        fl_priority_S8--;
        if (fl_priority_S8 >= 0)
        {
            fl_vm_instance_SP = &fl_dpm_config_SP->vm_ptr[fl_priority_S8];
            /*
            ** This function executes from high priority to low so that
            ** if a high priority state gets deactivated, hmi_lsh_focus_handler
            ** can set the next highest priority in the same cycle itself.
            */
            while (fl_priority_S8 >= 0)
            {
                fl_priority_S8--;
                hmi_vm_tick(fl_vm_instance_SP);
                fl_vm_instance_SP--;
            }
        }

#if LSH_NUMBER_OF_LAYERS > 1
    }
#endif
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
 ** Updated:          26-Jan-2014 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_post_button_event(UINT16 p_button_id_U16, UINT8 p_button_event_U8)
{
	/*
	** Following table contains the button id range for all the configured
	** number of button slots.
	*/
	static const LSH_BUTTON_SLOT_CONFIG_T lc_sed_button_slot_config_SA[LSH_NUMBER_OF_BUTTON_SLOTS] =
	{
	   LSH_BUTTON_ID_SLOT_CONFIG_LIST
	};
    LSH_EVENT_HANDLER_STATUS_T fl_btn_hndlr_status;
#if LSH_NUMBER_OF_EV_HANDLERS > 0
    UINT8          fl_return_state_U8 = LSH_STATUS_NONE;
    SFhmi_view_manager_02InstanceStruct const * fl_vm_inst_P;
    LSH_DPM_STACK_CONF_T          const * fl_dpm_config_SP;
    UINT8          fl_dpm_stack_count;
    UINT8          fl_layer_id_U8;
    UINT8          fl_count_U8;
    UINT8          fl_slot_id_U8;
    UINT8          fl_free_slot_id_U8;
    BOOLEAN        fl_found_config_U8;
    UINT8          fl_active_client_id;
    LSH_STATE_ID_T fl_active_state;
    UINT16         fl_anim_mask;

    fl_count_U8 = 0;
    fl_slot_id_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    fl_free_slot_id_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
    fl_found_config_U8 = FALSE;
    /*
    ** Find the slot of the passed button id if already present in slot array.
    ** If its a new button then get a free slot for the button.
    */
    while ((fl_slot_id_U8 == (UINT8)LSH_NUMBER_OF_BUTTON_SLOTS) && (fl_count_U8 < (UINT8)LSH_NUMBER_OF_BUTTON_SLOTS))
    {
        if ((p_button_id_U16 >= lc_sed_button_slot_config_SA[fl_count_U8].start_button_id) && (p_button_id_U16
                <= lc_sed_button_slot_config_SA[fl_count_U8].end_button_id))
        {
            if (l_sed_button_status_S[fl_count_U8].button_id == p_button_id_U16)
            {
                fl_slot_id_U8 = fl_count_U8;
            }
            else if (fl_free_slot_id_U8 == (UINT8)LSH_NUMBER_OF_BUTTON_SLOTS)
            {
                if (l_sed_button_status_S[fl_count_U8].button_id == (UINT16)LSH_INVALID_BUTTON_ID)
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
    if (fl_slot_id_U8 == (UINT8)LSH_NUMBER_OF_BUTTON_SLOTS)
    {
        fl_slot_id_U8 = fl_free_slot_id_U8;
    }
    /*
    ** Now perform the button event dispatching only if slot is available.
    */
    if (fl_slot_id_U8 != (UINT8)LSH_NUMBER_OF_BUTTON_SLOTS)
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
            l_sed_button_status_S[fl_slot_id_U8].client_id = (UINT8)LSH_INVALID_CLIENT_ID;
            /*
            ** Start the dispatch with high priority layer to low priority layer
            ** In each layer high priority display to low priority display.
            */
			#if LSH_NUMBER_OF_LAYERS > 1
			fl_layer_id_U8 = LSH_NUMBER_OF_LAYERS;
			while(fl_layer_id_U8 > (UINT8)0)
			{
				fl_layer_id_U8--;	
			#else
				fl_layer_id_U8 = 0;
			#endif 
                
                fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_layer_id_U8];

                if (fl_dpm_config_SP->size > (UINT8)0)
                {
                    fl_vm_inst_P     = &fl_dpm_config_SP->vm_ptr[fl_dpm_config_SP->size - 1U];
                    fl_dpm_stack_count = fl_dpm_config_SP->size;

                    while (fl_dpm_stack_count > (UINT8)0)
                    {
                        fl_dpm_stack_count--;
                        fl_active_state     = LSH_GET_STATE_ID((fl_vm_inst_P->l_gfx_active_state_id));
                        fl_active_client_id = LSH_GET_CLIENT_ID((fl_vm_inst_P->l_gfx_active_state_id));
                        if((fl_vm_inst_P->l_gfx_prev_focus & LSH_ANIM_STARTED_STATUS) != (UINT8)0)
                        {
                           fl_anim_mask = LSH_ANIM_MASK;
                        }
                        else
                        {
                           fl_anim_mask = 0;
                        }
                        if (fl_active_state < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
                        {
                            LSH_EV_HANDLER_CONF_T const * fl_handler_SP;

                            fl_count_U8 = lc_lsh_screen_config_SA[fl_active_state].handler_idx;
                            if (fl_count_U8 < (UINT8)LSH_NUMBER_OF_EV_HANDLERS)
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
                                    l_remap_target_ls_client_id = LSH_INVALID_CLIENT_ID;
                                    fl_btn_hndlr_status.logic_state_id = fl_active_state;
                                    fl_btn_hndlr_status.client_id = fl_active_client_id;
                                    fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8|fl_anim_mask);
                                    fl_return_state_U8 = fl_handler_SP->event(&fl_btn_hndlr_status);
                                    if ((fl_return_state_U8 & ((UINT8)LSH_STATUS_ABSORBED)) != (UINT8)0)
                                    {
										 /*
                                           ** Register the button against the state and break the loop.
                                           */
                                        l_sed_button_status_S[fl_slot_id_U8].logic_state_id = fl_active_state;
                                        l_sed_button_status_S[fl_slot_id_U8].client_id = fl_active_client_id;
                                        if(l_remap_target_ls_id  != (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES) 
										{
											 if  (l_remap_button_id_U16 == p_button_id_U16)
											{

											   /*
											   ** If the remap has been called and the button ID matches,
											   ** then register the button to l_remap_target_ls_id as
											   ** fl_active_state may want to remap the event
											   */
											   l_sed_button_status_S[fl_slot_id_U8].logic_state_id = l_remap_target_ls_id;
											   l_sed_button_status_S[fl_slot_id_U8].client_id = l_remap_target_ls_client_id;
											}
										}                                        
                                        fl_dpm_stack_count = 0;
										#if LSH_NUMBER_OF_LAYERS > 1
                                        fl_layer_id_U8     = 0;
										#endif
                                    }
                                }
                            }
                        }
                        fl_vm_inst_P--;
                    }
                }
#if LSH_NUMBER_OF_LAYERS > 1				
            }
#endif			
        }
        else
        {
            /*
            ** Button is already registered, so deliver the button events to the
            ** registred state.
            */
            if (l_sed_button_status_S[fl_slot_id_U8].state != (UINT8)LSH_BUTTON_FREEZE_STATUS)
            {
                UINT8 fl_client_id;
                LSH_STATE_ID_T fl_logic_state;
                fl_logic_state = l_sed_button_status_S[fl_slot_id_U8].logic_state_id;
                fl_client_id = l_sed_button_status_S[fl_slot_id_U8].client_id;

                if (fl_logic_state < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
                {
                    LSH_EV_HANDLER_CONF_T const * fl_handler_SP;
                    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
                    UINT8                         fl_priority_U8;

                    fl_state_conf_SP = &lc_lsh_screen_config_SA[fl_logic_state];
                    fl_priority_U8 = fl_state_conf_SP->priority;
                    if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
                    {
                        fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
                        if (fl_priority_U8 < fl_dpm_config_SP->size)
                        {
                    		if((LSH_GET_STATE_ID((fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_gfx_active_state_id)) == fl_logic_state)&&\
                                (LSH_GET_CLIENT_ID((fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_gfx_active_state_id)) == fl_client_id))
                            {
                                fl_count_U8 = lc_lsh_screen_config_SA[fl_logic_state].handler_idx;
                                if (fl_count_U8 < (UINT8)LSH_NUMBER_OF_EV_HANDLERS)
                                {
                                    fl_handler_SP = &lc_lsh_ev_handler_config_SA[fl_count_U8];
                                    if (fl_handler_SP->event != LSH_NULL_EVENT_HANDLER)
                                    {
                                        if ((fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_gfx_prev_focus & LSH_ANIM_STARTED_STATUS) != 0U)
                                        {
                                            fl_anim_mask = LSH_ANIM_MASK;
                                        }
                                        else
                                        {
                                            fl_anim_mask = 0;
                                        }
                                        fl_btn_hndlr_status.logic_state_id = fl_logic_state;
                                        fl_btn_hndlr_status.client_id = fl_client_id;
                                        fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8 | fl_anim_mask);
                                        fl_return_state_U8 = fl_handler_SP->event(&fl_btn_hndlr_status);
                                    }
                                }
                            }
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
            /* In Button Freeze state, the buttons should not be passed to the default handler */
            else
            {
                fl_return_state_U8 = LSH_STATUS_ABSORBED;
            }
        }
        if (p_button_event_U8 == (UINT8)LSH_BUTTON_INACTIVE_STATE)
        {
            /*
            ** Relese the slot on button release
            */
            #ifdef LSH_UNFREEZE_BUTTON_EVENT_HANDLER
            if(((UINT8)LSH_BUTTON_FREEZE_STATUS)==l_sed_button_status_S[fl_slot_id_U8].state)
            {
              fl_btn_hndlr_status.logic_state_id = l_sed_button_status_S[fl_slot_id_U8].logic_state_id;
              fl_btn_hndlr_status.client_id =  l_sed_button_status_S[fl_slot_id_U8].client_id;
              fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
              (void) LSH_UNFREEZE_BUTTON_EVENT_HANDLER(&fl_btn_hndlr_status);
            }
            #endif
            l_sed_button_status_S[fl_slot_id_U8].button_id = LSH_INVALID_BUTTON_ID;
            l_sed_button_status_S[fl_slot_id_U8].logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
            l_sed_button_status_S[fl_slot_id_U8].client_id = (UINT8)LSH_INVALID_CLIENT_ID;
        }
    }
#ifdef LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER
 #if LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER > 0
    if((fl_return_state_U8 == (UINT8)LSH_STATUS_NONE)&&(fl_slot_id_U8<(UINT8)LSH_NUMBER_OF_BUTTON_SLOTS))
    {
        fl_btn_hndlr_status.logic_state_id = l_sed_button_status_S[fl_slot_id_U8].logic_state_id;
        fl_btn_hndlr_status.client_id =  l_sed_button_status_S[fl_slot_id_U8].client_id;
        fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
        (void) hmi_lsh_default_button_event_handler(&fl_btn_hndlr_status);
    }
#else
  HMI_UNUSED_VAR(fl_return_state_U8);
 #endif
#else
  HMI_UNUSED_VAR(fl_return_state_U8);
 #error "LSH_NEED_DEFAULT_BUTTON_EVENT_HANDLER needs to be set to either 0 or 1"
#endif

#else /* #if LSH_NUMBER_OF_EV_HANDLERS > 0 */
    fl_btn_hndlr_status.logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
    fl_btn_hndlr_status.client_id  = LSH_INVALID_CLIENT_ID;
    fl_btn_hndlr_status.button_command = LSH_GET_COMMAND(p_button_id_U16, p_button_event_U8);
    (void) hmi_lsh_default_button_event_handler(&fl_btn_hndlr_status);
#endif
}

/*============================================================================
 ** Function Name:    hmi_lsh_freeze_button_events_ext
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
 ** Created:          24-Jan-2014 by NKRISHN9
 ** Updated:          24-Jan-2014 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_freeze_button_events_ext(LSH_STATE_ID_T p_logic_state_id_U16, UINT8 p_client_id_U8)
{
    UINT8 fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;    

    if (p_logic_state_id_U16 == (LSH_STATE_ID_T)LSH_ALL_LOGIC_STATES)
    {
        /*
        ** Freeze all the buttons
        */
        while (fl_count_U8 > (UINT8)0)
        {
            fl_count_U8--;            
			if (l_sed_button_status_S[fl_count_U8].logic_state_id < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
            {
                l_sed_button_status_S[fl_count_U8].state = LSH_BUTTON_FREEZE_STATUS;
            }
            
        }
		
    }
    else
    {
        /*
        ** Freeze buttons registred against a logic state.
        */
        while (fl_count_U8 > (UINT8)0)
        {
            fl_count_U8--;            
			if ((l_sed_button_status_S[fl_count_U8].logic_state_id == p_logic_state_id_U16)\
                  &&(l_sed_button_status_S[fl_count_U8].client_id==p_client_id_U8))
            {
                l_sed_button_status_S[fl_count_U8].state = LSH_BUTTON_FREEZE_STATUS;
            }
            
        }
    }
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
 ** Updated:          24-Jan-2014 by nkrishn9
 **==========================================================================*/
void hmi_lsh_freeze_button_events(LSH_STATE_ID_T p_logic_state_id_U16)
{
    hmi_lsh_freeze_button_events_ext(p_logic_state_id_U16, LSH_INVALID_CLIENT_ID);
}

/*============================================================================
 ** Function Name:    hmi_lsh_remap_button_events_ext
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
 ** Created:          26-Jan-2014 by NKRISHN9
 ** Updated:          26-Jan-2014 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_remap_button_events_ext(UINT16 p_button_id_U16, LSH_STATE_ID_T p_target_ls_id, UINT8 p_client_id_U8)
{
#if LSH_NUMBER_OF_EV_HANDLERS > 0
    LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
    LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
    UINT16                fl_active_logic_state;
    UINT16                fl_active_gfx_state;
    UINT8                 fl_priority_U8;

    if (p_target_ls_id < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
    {
        UINT16 fl_target_vm_ls_id;
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_target_ls_id];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                fl_active_logic_state = fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_logic_active_state_id;
                fl_active_gfx_state = fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_gfx_active_state_id;

                fl_target_vm_ls_id = (UINT16)LSH_VM_STATE_ID(p_client_id_U8, p_target_ls_id);
                if ((fl_active_logic_state == fl_target_vm_ls_id) || (fl_active_gfx_state == fl_target_vm_ls_id))
                {
                    /*
                    ** Both Source and Target state are active
                    */
                    UINT8 fl_count_U8;
                    fl_count_U8 = lc_lsh_screen_config_SA[p_target_ls_id].handler_idx;
                    if (fl_count_U8 < (UINT8)LSH_NUMBER_OF_EV_HANDLERS)
                    {
                        LSH_EV_HANDLER_CONF_T const *fl_handler_SP;
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
                            LSH_BUTTON_SLOT_STATUS_T *fl_sed_button_status_SP = &l_sed_button_status_S[0];
                            l_remap_button_id_U16 = p_button_id_U16;
                            l_remap_target_ls_id = p_target_ls_id;
                            l_remap_target_ls_client_id = p_client_id_U8;
                            fl_count_U8 = LSH_NUMBER_OF_BUTTON_SLOTS;
                            while (fl_count_U8 > (UINT8)0)
                            {
                                fl_count_U8--;
                                if ((fl_sed_button_status_SP->button_id == p_button_id_U16) &&
                                    (fl_sed_button_status_SP->logic_state_id != (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES))
                                {
                                    /* reassign the slot and exit loop */
                                    fl_sed_button_status_SP->logic_state_id = p_target_ls_id;
                                    fl_sed_button_status_SP->client_id = p_client_id_U8;
                                    fl_count_U8 = 0;
                                    /* we were able to find the button ID, so clear the request from store */
                                    l_remap_button_id_U16 = LSH_INVALID_BUTTON_ID;
                                    l_remap_target_ls_id = LSH_NUMBER_OF_LOGIC_STATES;
                                    l_remap_target_ls_client_id = LSH_INVALID_CLIENT_ID;
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
        while (fl_count_U8 > (UINT8)0)
        {
            fl_count_U8--;
            if (fl_sed_button_status_SP->button_id == p_button_id_U16)
            {
                /* init the slot and exit the loop */
                fl_sed_button_status_SP->button_id      = LSH_INVALID_BUTTON_ID;
                fl_sed_button_status_SP->state          = LSH_BUTTON_INACTIVE_STATE;
                fl_sed_button_status_SP->logic_state_id = LSH_NUMBER_OF_LOGIC_STATES;
                fl_sed_button_status_SP->client_id      = (UINT8)LSH_INVALID_CLIENT_ID;
                fl_count_U8 = 0;
            }
            else
            {
                fl_sed_button_status_SP = &fl_sed_button_status_SP[1];
            }
        }
    }
#endif
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
 ** Updated:          1-Jan-2014 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_remap_button_events(UINT16 p_button_id_U16, LSH_STATE_ID_T p_target_ls_id)
{
  hmi_lsh_remap_button_events_ext(p_button_id_U16, p_target_ls_id, LSH_INVALID_CLIENT_ID);
}

#ifdef LSH_ANIMATION_SUPPORT_ENABLED
/*============================================================================
 ** Function Name:    hmi_lsh_animation_done_cb
 ** Visibility:       global
 ** Description:      This function is the callback function for the animation
 **                   completion.
 ** Invocation:       Invoked by Animation components when on completing an animation.
 **
 ** Inputs/Outputs:   in  - Logic state id to be activated in p_logic_state_id_U8.
 ** Critical Section: None.
 ** Created:          23-Jun-2010 by GPURUSO1
 ** Updated:          03-Jan-2011 by EMANOJ1
 **==========================================================================*/
void hmi_lsh_animation_done_cb(UINT8 p_prio_U8, UINT32 p_logic_state_id_U32, UINT8 p_anim_ID)
{
    if (LSH_GET_STATE_ID(((UINT16)p_logic_state_id_U32)) < (UINT8)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DPM_STACK_CONF_T  const * fl_dpm_config_SP;
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[LSH_GET_STATE_ID(((UINT16)p_logic_state_id_U32))];
        fl_priority_U8   = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];

            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                hmi_vm_animation_completed(&fl_dpm_config_SP->vm_ptr[fl_priority_U8]);
            }
        }
  }
  HMI_UNUSED_VAR(p_prio_U8);
  HMI_UNUSED_VAR(p_anim_ID);
}

/*============================================================================
** Function Name:    hmi_lsh_inspect_scr_animation_status
** Visibility:       global
** Description:      return animation active status for a screen
** Invocation:       Invoked by application to inspect animation active status
**
** Inputs/Outputs:   in  - Priority
** Critical Section: None.
** Created:          29-Jul-2014 by NKRISHN9
** Updated:          29-Jul-2014 by NKRISHN9
**==========================================================================*/
BOOLEAN  hmi_lsh_inspect_scr_animation_status(LSH_STATE_ID_T p_logic_state_id_U8, UINT8 p_client_id_U8)
{
    BOOLEAN r_animation_active = FALSE;
    if (p_logic_state_id_U8 < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
    {
        LSH_DISP_STATE_CONF_T const * fl_state_conf_SP;
        UINT8                         fl_priority_U8;
        LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;

        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8 = fl_state_conf_SP->priority;
        if (fl_state_conf_SP->layer_id < LSH_NUMBER_OF_LAYERS)
        {
            fl_dpm_config_SP = &lc_lsh_dpm_config_SA[fl_state_conf_SP->layer_id];
            if (fl_priority_U8 < fl_dpm_config_SP->size)
            {
                if(fl_dpm_config_SP->vm_ptr[fl_priority_U8].l_gfx_active_state_id==\
                    LSH_VM_STATE_ID(p_client_id_U8, p_logic_state_id_U8))
                {
                    r_animation_active = hmi_lsh_inspect_animation_status(fl_priority_U8,
                                                                          fl_state_conf_SP->layer_id);
                }
            }
        }
    }
    return(r_animation_active);
}

/*============================================================================
 ** Function Name:    hmi_lsh_inspect_animation_status
 ** Visibility:       global
 ** Description:      return animation active status for 
                      a layer - valid layer id & max priority 
                      a priority -  valid layer id & valid priority 
 ** Invocation:       Invoked by application to inspect animation active status
 **
 ** Inputs/Outputs:   in  - Priority
 ** Critical Section: None.
 ** Created:          22-Aug-2013 by NKRISHN9
 ** Updated:          22-Aug-2013 by NKRISHN9
 **==========================================================================*/
BOOLEAN  hmi_lsh_inspect_animation_status(UINT8 p_prio_U8, UINT32 p_layer_id_U32)
{
    BOOLEAN r_animation_active;
    r_animation_active=FALSE;
    if(p_layer_id_U32 < (UINT32)LSH_NUMBER_OF_LAYERS)
    {
      LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
      SFhmi_view_manager_02InstanceStruct * fl_vm_instance_SP;

      UINT8 fl_priority_U8;

      fl_dpm_config_SP  = &lc_lsh_dpm_config_SA[p_layer_id_U32];

      if(p_prio_U8<fl_dpm_config_SP->size)
      {
        fl_vm_instance_SP = &fl_dpm_config_SP->vm_ptr[p_prio_U8];
        r_animation_active=(BOOLEAN)hmi_vm_animation_active_status(fl_vm_instance_SP);
      }
      else
      {
        for(fl_priority_U8=0;(fl_priority_U8<fl_dpm_config_SP->size);fl_priority_U8++)
        {
          fl_vm_instance_SP = &fl_dpm_config_SP->vm_ptr[fl_priority_U8];
          r_animation_active=(BOOLEAN)hmi_vm_animation_active_status(fl_vm_instance_SP);
          if(r_animation_active==TRUE)
		  {
			  break;
		  }
        }
      }
    }
    return(r_animation_active);
}

/*============================================================================
 ** Function Name:    hmi_lsh_inspect_state_animation_id
 ** Visibility:       global
 ** Description:      animation active status for 
                      a layer - valid layer id & max priority 
                      a priority -  valid layer id & valid priority 
 ** Invocation:       Invoked by application to inspect animation active id.
 **					  Do not use this interface for entire application logic or state design. The proper design
						is "tracking the proper state of system by modeling and make appropriate logical decision
						in model". Heavily relying and revolving around viewer status is not advisable.
						logic_active_anim_id - current anim id in input context.
						logic_deactivate_anim_id - current close anim id in input context.
						graphic_active_anim_id - current active anim id in graphics(output screen)
 ** Inputs/Outputs:   in  - Priority, layer and anim state
 ** Critical Section: None.
 ** Created:          25-Aug-2015 by NKRISHN9
 ** Updated:          25-Aug-2015 by NKRISHN9
 **==========================================================================*/
void hmi_lsh_inspect_state_animation_id(UINT8 p_prio_U8, UINT32 p_layer_id_U32, LSH_ANIM_STATE_ID * const p_state)
{
   
    if(p_layer_id_U32 < (UINT32)LSH_NUMBER_OF_LAYERS)
    {
      LSH_DPM_STACK_CONF_T const * fl_dpm_config_SP;
      SFhmi_view_manager_02InstanceStruct const * fl_vm_inst_P;

      fl_dpm_config_SP  = &lc_lsh_dpm_config_SA[p_layer_id_U32];

      if(p_prio_U8<fl_dpm_config_SP->size)
      {
        fl_vm_inst_P = &fl_dpm_config_SP->vm_ptr[p_prio_U8];
        p_state->logic_active_anim_id=fl_vm_inst_P->l_logic_active_anim_id;
		p_state->logic_deactivate_anim_id=fl_vm_inst_P->l_gfx_deactivate_anim;
		p_state->graphic_active_anim_id=fl_vm_inst_P->l_gfx_active_anim_id;
      }
	}
}

/*============================================================================
 ** Function Name:    hmi_lsh_get_screen_priority
 ** Visibility:       global
 ** Description:      return the priority of the screen                       
 ** Invocation:       Invoked by Animation core interface layer **
 ** Inputs/Outputs:   Logic state id
 ** Critical Section: None.
 ** Created:          10-Feb-2017 by APERUMAL
 **==========================================================================*/
UINT8 hmi_lsh_get_screen_priority(LSH_STATE_ID_T p_logic_state_id_U8)
{
  LSH_DISP_STATE_CONF_T const *fl_state_conf_SP;
  UINT8 fl_priority_U8 = LSH_NB_PRIORITY;
  if (p_logic_state_id_U8 < (LSH_STATE_ID_T)LSH_NUMBER_OF_LOGIC_STATES)
  {
        fl_state_conf_SP = &lc_lsh_screen_config_SA[p_logic_state_id_U8];
        fl_priority_U8 = fl_state_conf_SP->priority;
  }
  return (fl_priority_U8);
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
 ** CMS Rev 1.36     18-Jul-17    arajase2
 ** RTC ID: 905460: CMFB Coverity warning fix
 ** Changes: New macro LSH_ANIM_MASK_CLEAR and LSH_GOT_FOCUS_CLR_STATUS created to fix
 ** coverity warning when we use ~ operator
 ** ie. ~(LSH_ANIM_MASK) is replaced with its mask LSH_ANIM_MASK_CLEAR
 ** and ~(LSH_GOT_FOCUS_STATUS) is replaced with LSH_GOT_FOCUS_CLR_STATUS
 **
 ** CMS Rev 1.35     16-Jun-2017    arajase2
 ** Revert the MISRA fixes as it injects compiler warnings
 **
 ** CMS Rev 1.34     13-Feb-2017    aperumal
 ** Provided an interface to return the priority of the screen 
 **
 ** CMS Rev 1.33     1-Sep-2015    NKRISHN9
 ** Added hmi_lsh_inspect_state_animation_id interface. 
 **
 **	CMS Rev 1.32 17-Feb-2015    NKRISHN9
 	 The animation id in input and output context of graphics is provided as below in new interface,
	 logic_active_anim_id - current anim id in input context.
	 logic_deactivate_anim_id - current close anim id in input context.
	 graphic_active_anim_id - current active anim id in graphics(output screen)
 ** CMS Rev 1.31     17-Feb-2015    EMANOJ1
 ** Added hmi_lsh_task_ext to support Rtc #290842 (hmi_lsh_execute_presentation() 
 ** doesnot execute the Presentation for the newly added LSH Priority when 
 ** hmi_lsh_task is not executed)
 **
 ** CMS Rev 1.30     10-Feb-2015    kkubendi
 ** Compiler Warnings resolved for Honda THAA.
 **
 ** CMS Rev 1.30     06-Feb-2015    arajase2
 ** QAC 8.1.2 Warnings resolved.
 **
 ** CMS Rev 1.29     12-Dec-2014    nkrishn9
 ** Focus id defect. changes to give high priority screen id in low priority focus hndlr.
 **
 ** CMS Rev 1.28     19-May-2014    EMANOJ1
 ** hmi_lsh_focus_handler updated to fix P42M coverity issues 10791, 10799
 **
 ** CMS Rev 1.27     26-Jan-2014    NKRISHN9
 ** Define the LSH_UNFREEZE_BUTTON_EVENT_HANDLER macro, if aplication is required to get the 
 ** release event of all button id for the freezed screen.
 **
 ** CMS Rev 1.26     26-Jan-2014    NKRISHN9
 ** hmi_lsh_focus_handler will not consider the focus status of logic state if
 ** focus and presentation handler is not configured for corresponding state.
 ** LSH_FOCUS_STATUS_FOR_ALL_SCREEN handler configuration is added to give the 
 ** focus status of all screen in one handler (Requirement for sync of MFD).
 ** Added client id to button event handler and related changes in freeze,
 ** remap button event interface.
 **
 ** CMS Rev 1.25     1-0ct-2013    NKRISHN9
 ** hmi_lsh_post_button_event is updated to absorb the button id state if 
 ** corresponding screen is removed for subsequent button state (screen removed
 ** during press state). 
 ** Merged vmuthusu(SANAND2) following changes,
 ** Blocked the button from passing on to the default handler during Button
 ** Freeze State, in the function hmi_lsh_post_button_event() 
 **
 ** CMS Rev 1.24     27-Aug-2013    NKRISHN9
 ** Added interface hmi_lsh_inspect_animation_status
 ** Presentation structure and its interface is update with client id.
 **
 ** CMS Rev 1.23     07-Dec-2012    EMANOJ1
 ** Removed the dependancy with animation core 01 in order to make it work with
 ** new animation core 02. By removing the direct dependancy, any animation could 
 ** be integrated.
 **
 ** Added two interfaces to start and stop animation, this needs to be implemented
 ** by apps if animation support is enabled. hmi_lsh_start_animation() and 
 ** hmi_lsh_stop_animation()
 **
 ** CMS Rev 1.22     09-Oct-2012    ASHEKHAR
 **  Changed the focus, presentation, event handler individual parameters to
 **  structure members.
 **
 ** CMS Rev 1.21     04-Jul-2012    EMANOJ1
 ** #ifndef MATLAB_MEX_FILE protection removed as this code might be used by
 ** application inside another matlab simulation and under the simulation
 ** environment matlab will define MATLAB_MEX_FILE causing the view manager
 ** init functions to blocked and not being invoked.
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

