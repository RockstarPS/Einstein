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
** Name:           hmi_popup_core.c
**
** Description:    Source file for the Popup Core
**
** Organization:   Driver info, Audio and MFD HMI Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

#include "hmi_popup_core.dat"

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
#define  HMI_TMR_TIME_OUT_TYPE                   (0x01)
#define  HMI_TMR_PROGRESS_TIMER_TYPE             (0x02)
#define  HMI_TMR_KEY_PAD_MULTI_PRESS_TYPE        (0x03)
#define  HMI_TMR_MINIMUM_TIMEOUT_TYPE            (0x04)
#define  HMI_PROGRESS_POPUP_NO_TIMEOUT_COUNT     (255)
#define  HMI_DECIMAL_NUM_BASE                    ((UINT8)10)
#define  POPUP_ANIM_STATUS_MASK					(0xF0)
#define  POPUP_FOCUS_STATUS_MASK                 (LSH_LOST_FOCUS_STATUS|LSH_GOT_FOCUS_STATUS)

typedef struct
{
   POPUP_ID total_popup_count;
   POPUP_ID popup_id;
}POPUP_ACTIVE_DATA_TYPE;


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
/*******************************************************************************
PRIVATE_FUNCTIONS_PROTOTYPE() {}
********************************************************************************/

static POPUP_LAYER_TYPE  const * hmi_popup_core_get_popup_layer(POPUP_ID p_popup_id);
static POPUP_ID hmi_popup_core_get_active_popup(POPUP_LAYER_TYPE  const *p_layer);
static void hmi_popup_core_send_event_notification(POPUP_ID p_popup_id, POPUP_EVENTS p_evt);
static UINT8 hmi_popup_core_close_popup(POPUP_ID p_popup_id, POPUP_EVENTS p_event
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
,POPUP_ANIMATION_ID p_anim_id
#endif
);
static UINT8 hmi_popup_core_deactivate(POPUP_ID_T p_popup_id, POPUP_EVENTS p_event
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
,POPUP_ANIMATION_ID p_anim_id
#endif
);
static UINT8 hmi_popup_core_activate(POPUP_LAYER_TYPE const *p_layer
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
,POPUP_ANIMATION_ID p_anim_id
#endif
);
static void hmi_popup_core_start_popup_timer(POPUP_ID p_popup_id);
static void hmi_popup_core_start_popup_min_timer(POPUP_ID p_popup_id);
static void hmi_popup_core_start_all_popup_timer(POPUP_ID p_popup_id);
static void hmi_popup_core_stop_popup_timer(POPUP_ID p_popup_id);
static void hmi_popup_core_stop_popup_min_timer(POPUP_ID p_popup_id);
static void hmi_popup_core_stop_all_popup_timer(POPUP_ID p_popup_id);
static BOOLEAN hmi_popup_core_add_to_queue(POPUP_ID p_popup_id, POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority);
static BOOLEAN hmi_popup_core_remove_from_queue(POPUP_ID p_popup_id, POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority);
static POPUP_ID hmi_popup_core_search_self_deactivate_pp_in_queue(POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority);
static POPUP_ID hmi_popup_core_get_lastin_pp_in_queue(POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority);

#ifdef POPUP_TYPE_PROGRESSBAR
static BOOLEAN hmi_popup_core_increment_progressbar_counter(POPUP_ID p_popup_id);
#endif
#ifdef POPUP_TYPE_KEYPAD
static UINT8 hmi_popup_keypad_btn_handler(POPUP_KEYPADENTRY_TYPE  const *p_keypad, UINT16 p_btn_id, POPUP_ID p_popup_id);
static BOOLEAN hmi_popup_core_inc_keypadmultitimer_counter(POPUP_ID p_popup_id);
static BOOLEAN hmi_popup_core_search_button_event(PP_BTN_EVENT_TYPE const *p_btn_ev_ptr, UINT16 p_btn_event);
#endif
static POPUP_ACTIVE_DATA_TYPE hmi_popup_core_find_active_popup_and_count(POPUP_ID p_start_index, POPUP_ID p_end_index);
static void hmi_popup_core_disable_timer_status(POPUP_ID_T p_popup_id);
static void hmi_popup_core_clear_min_deact_pndng(POPUP_ID_T p_popup_id);


/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
static POPUP_ID l_active_popup_id[POPUP_MAX_LAYERS];
#ifdef POPUP_CORE_STATE_CALLBACK_HANDLER_DEFINED
static BOOLEAN  l_popup_status;
#endif



/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
/*******************************************************************************
PUBLIC_FUNCTIONS() {}
********************************************************************************/

/*============================================================================
** Function Name    : hmi_popup_core_initialize
** Visibility       : Global, Infterface to the Application
** Description      : This function should be called to intialize the popup
**                    core
** Invocation       : Invoked by the Application
** Inputs/Outputs   : -
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
void hmi_popup_core_initialize(void)
{
  POPUP_ID_T fl_index;
  POPUP_ID_T fl_group_index;
  POPUP_ID_T fl_queue_index;
  POPUP_ID_T fl_lay_index;
  POPUP_LAYER_TYPE const * fl_layer;
#ifdef POPUP_TYPE_KEYPAD
  POPUP_KEYPADENTRY_TYPE const * l_keypad_entry_table_ptr;
#endif
#ifdef POPUP_TYPE_PROGRESSBAR
  POPUP_PROGRESSBAR_TYPE const * l_progress_bar_table_ptr;
#endif

#ifdef POPUP_CORE_STATE_CALLBACK_HANDLER_DEFINED
  l_popup_status=FALSE;
#endif
  for(fl_lay_index = (POPUP_ID_T)0; fl_lay_index < POPUP_MAX_LAYERS ; fl_lay_index++)
  {
    l_active_popup_id[fl_lay_index]=L_POPUP_MAX_COUNT;
    fl_layer = l_layer_table[fl_lay_index];
    if(fl_layer->l_group_priority_table_ptr != NULL)
    {
      for(fl_group_index = (POPUP_ID_T)0; fl_group_index <fl_layer->l_total_grp_priority_count ; fl_group_index++)
      {
        for(fl_queue_index=(POPUP_ID_T)0;fl_queue_index<(fl_layer->l_group_priority_table_ptr[fl_group_index]->queue_size);fl_queue_index++)
        {
          fl_layer->l_group_priority_table_ptr[fl_group_index]->queue[fl_queue_index]=(POPUP_ID_T)L_POPUP_MAX_COUNT;
        }
      }
    }
  }
#ifdef POPUP_TYPE_KEYPAD
  l_keypad_entry_table_ptr=l_total_pp_type.l_keypad_entry_pp_table_ptr;
  for(fl_index = (POPUP_ID_T)0; fl_index <l_total_pp_type.keypad_count_U8 ; fl_index++)
  {
    l_keypad_entry_table_ptr[fl_index].l_entry_ptr[0]='\0';
    *(l_keypad_entry_table_ptr[fl_index].l_multi_press_counter)=0;
    *(l_keypad_entry_table_ptr[fl_index].l_curr_multi_press_btn)=0;
    *(l_keypad_entry_table_ptr[fl_index].l_multi_timer_counter)=0;
  }
#endif
  
#ifdef POPUP_TYPE_PROGRESSBAR 
  l_progress_bar_table_ptr=l_total_pp_type.l_progress_bar_pp_table_ptr;
  for(fl_index = (POPUP_ID_T)0; fl_index <l_total_pp_type.progress_bar_count_U8 ; fl_index++)
  {
    *(l_progress_bar_table_ptr[fl_index].l_progress_counter_U8)=0;
  }
#endif

  for(fl_index = (POPUP_ID_T)0; fl_index < ((L_POPUP_MAX_COUNT+7U)/8U); fl_index++)
  {
    l_pp_id_sts_bit_U8[fl_index]=(POPUP_ID_T)0;
    l_pp_id_tmr_bit_U8[fl_index]=(POPUP_ID_T)0;
    l_pp_id_lsh_sts_bit_U8[fl_index]=(POPUP_ID_T)0;
    l_min_tmr_bit_U8_ptr[fl_index]=(POPUP_ID_T)0;
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_get_popup_info
** Visibility       : Global, Interface to the Application
** Description      : function could be called to find popup information
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_layer_id - Enumeration of the layer id to be inspected
**                    POPUP_INFO_DATA_TYPE - structure param ptr fill popup info
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
void hmi_popup_core_get_popup_info(POPUP_INFO_DATA_TYPE * const p_info_data, POPUP_LAYER_ID p_layer_id)
{
  POPUP_LAYER_TYPE  const * fl_layer;
  POPUP_ACTIVE_DATA_TYPE r_active;
  POPUP_ID p_start_index;
  POPUP_ID p_end_index;

  if(p_layer_id < (POPUP_LAYER_ID)POPUP_MAX_LAYERS)
  {
    fl_layer = l_layer_table[p_layer_id];
    p_start_index=POPUP_LAYER_START_INDEX((fl_layer));
    p_end_index=MAX_LAYER_POPUP_ID((fl_layer));
    r_active=hmi_popup_core_find_active_popup_and_count(p_start_index,p_end_index);
    /* The popup which is present in the lsh display of a popup layer is the active popup */
    /* The count of a layer is a number of popups added to a popup layer by a application */
     if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
     {
      	r_active.popup_id = l_active_popup_id[fl_layer->l_layer_index];
     }
   }
  else
  {
    p_start_index=(POPUP_ID)0;
    p_end_index=L_POPUP_MAX_COUNT;
    /* The highest priority popup which is active among all layers of a popup */
    /* The total popups active among all layer of a popup core which is added by application */
    r_active=hmi_popup_core_find_active_popup_and_count(p_start_index,p_end_index);
  }
  p_info_data->active_popup_id=r_active.popup_id;
  p_info_data->total_popup_count=r_active.total_popup_count;
}

/*============================================================================
** Function Name    : hmi_popup_core_inspect_popup_active
** Visibility       : Global, Interface to the Application
** Description      : function could be called to find whether popup is active 
**                    or not
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_popup_id - popup id to be inspected
                      POPUP_CONTEXT_TYPE p_context_type 
                      The popup id status is whether it is the input from app 
                      or in display context(lsh context)i.e.the
                      popup active in display for a corresponding popup layer.
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
BOOLEAN hmi_popup_core_inspect_popup_active(POPUP_ID p_popup_id, POPUP_CONTEXT_TYPE p_context_type)
{
  BOOLEAN fl_return_BOOL = FALSE;
  if((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    if((POPUP_CONTEXT_TYPE)POPUP_CONTEXT_INPUT==p_context_type)
    {
      /* Return true if the popup is active (in popup app input context i.e. even just activated pp) */
      if ((POPUP_ACTIVE((p_popup_id)))&&(!MIN_TIMER_DEACTIVATE_PENDING((p_popup_id))))
      {
        fl_return_BOOL = TRUE;
      }
    }
    else
    {
      /* Return true if the popup is active in lsh i.e.in display */
      POPUP_LAYER_TYPE const * fl_layer;
      fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
      if(fl_layer!=NULL)
      {
        if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
        {
          if (l_active_popup_id[fl_layer->l_layer_index] == p_popup_id)
          {
            fl_return_BOOL = TRUE;
          }
        }
      }
    }
  }
  return(fl_return_BOOL);
}

/*============================================================================
** Function Name    : hmi_popup_core_close_all_popup
** Visibility       : Global, Interface to the Application
** Description      : This function should be called to close all popup in a
**                    layer or popup core(Max popup layer id)
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_layer_id - Layer id of popups to be closed.
**                    POPUP_MAX_LAYERS  - For all popups of popupcore to close.
** Critical Section : No
** Created          : 30 JUL, 2012 NKRISHN9
** Updated          : 30 JUL, 2013 nkrishn9
**==========================================================================*/
void hmi_popup_core_close_all_popup(POPUP_LAYER_ID p_layer_id)
{
  POPUP_ID_T fl_index, fl_end_index;
  POPUP_LAYER_TYPE const * fl_layer;
  POPUP_ACTIVE_DATA_TYPE fl_active;

  if((POPUP_LAYER_ID)POPUP_MAX_LAYERS > p_layer_id)
  {
    fl_layer = l_layer_table[p_layer_id];
    fl_index = POPUP_LAYER_START_INDEX((fl_layer));
    fl_end_index = MAX_LAYER_POPUP_ID(fl_layer);
  }
  else
  {
    fl_index = (POPUP_ID_T)0;
    fl_end_index = (POPUP_ID_T)L_POPUP_MAX_COUNT;
  }

  fl_active = hmi_popup_core_find_active_popup_and_count((POPUP_ID)fl_index,(POPUP_ID)fl_end_index);
  fl_index = fl_active.popup_id;

  while((fl_index < fl_end_index)&&(fl_active.total_popup_count!=(POPUP_ID)0))
  {
    (void)hmi_popup_core_deactivate_popup((POPUP_ID)fl_index
                                    #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                    , (POPUP_ANIMATION_ID)POPUP_ANIM_MAX_ID
                                    #endif
                                    );
    /* Take care the minimum timer */
    fl_active = hmi_popup_core_find_active_popup_and_count((POPUP_ID)(fl_index+1U),(POPUP_ID)fl_end_index);
    fl_index = fl_active.popup_id;
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_activate_popup
** Visibility       : Global, Interface to the Application
** Description      : This function should be called to activate a particular
**                    popup.
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_popup_id - Enumeration of the Popup to be activated
**                    p_anim_id  - Animation ID to perform                     
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
UINT8 hmi_popup_core_activate_popup(POPUP_ID p_popup_id
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
  , POPUP_ANIMATION_ID p_anim_id
#endif
)
{
  /* Currently, return data is to be send "none" as view manager. In future, it
  might be revisited as required */
  UINT8 fl_return_U8 = LSH_STATUS_NONE;

  /* Is a Valid Popup id*/
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    POPUP_ID fl_active_pp;
    POPUP_ID_T fl_index;
    POPUP_ID temp_low_prty_pp_start_index;
    POPUP_ID_ATTRIBUTE_T fl_popupid_grp_priorty;
    POPUP_ID_T fl_max_layer_popup_id;
    POPUP_LAYER_TYPE const* fl_layer;

    fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
    if (fl_layer != NULL)
    {
      fl_active_pp = hmi_popup_core_get_active_popup(fl_layer);

      fl_popupid_grp_priorty = GROUP_PRIORITY(p_popup_id);
      fl_max_layer_popup_id = MAX_LAYER_POPUP_ID(fl_layer);

      /* Is no pp is active(i.e. if no popup is active in a layer, then,
      highest popupid+1 is returned from active pp handler)  or  is new pp is the
      highest/same active popup  or  is same group priority pp */
      if ((fl_active_pp >= (fl_max_layer_popup_id)) || (fl_active_pp >= p_popup_id)\
        || ((fl_popupid_grp_priorty == GROUP_PRIORITY(fl_active_pp))\
          && (fl_popupid_grp_priorty != (UINT8)NO_GROUP_PRIORITY)))
      {
        /****************************************************************************
        ** Stop the timer only if there is any low priority popup active, the API       **
        ** hmi_popup_core_get_active_popup' would return the max popup layer id in the  **
        ** layer if no popup is active in that layer.                                   **
        *****************************************************************************/
        if (fl_popupid_grp_priorty != (UINT8)NO_GROUP_PRIORITY)
        {
          if (p_popup_id == fl_active_pp)
          {
            (void)hmi_popup_core_remove_from_queue(p_popup_id, fl_layer, fl_popupid_grp_priorty);
            /* Just remove the new popup as no notification is required (and the popup will be added again)
            since, if the pp is in queue and activate the same pp might bring it to display. */
          }
          else
          {
            POPUP_ID temp_self_deactivate_pp;
            /* The popup is not already the active popup. Now, search and remove if
            any popup with self deactivate config present in the queue */
            temp_self_deactivate_pp = hmi_popup_core_search_self_deactivate_pp_in_queue(fl_layer, fl_popupid_grp_priorty);
            if (temp_self_deactivate_pp != (POPUP_ID)L_POPUP_MAX_COUNT)
            {
              (void)hmi_popup_core_remove_from_queue(temp_self_deactivate_pp, fl_layer, \
                GROUP_PRIORITY(temp_self_deactivate_pp));
              if (temp_self_deactivate_pp != p_popup_id)
              {
                (void)hmi_popup_core_deactivate((POPUP_ID_T)temp_self_deactivate_pp, POPUP_CLOSED_ON_DEMAND_EVT
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
                  , (POPUP_ANIMATION_ID)POPUP_ANIM_MAX_ID
#endif
                );
              }
            }
            if (POPUP_ACTIVE((p_popup_id)))
            {
              (void)hmi_popup_core_remove_from_queue(p_popup_id, fl_layer, fl_popupid_grp_priorty);
              /* Just remove the new popup as no notification is required (and the popup will be added again)
              since, if the pp is in queue and activate the same pp might bring it to display. */
            }
          }
          /* Add the popup to top of the queue even if popup is already in queue(which is removed above) */
          (void)hmi_popup_core_add_to_queue(p_popup_id, fl_layer, fl_popupid_grp_priorty);
          /* Search and deactivate all low priority pp which is configured as deactivate
          when high priority pp activated */

          /* find the index of low priority pp */
          /* if it is a group priority, the index is start of next group priority */

          temp_low_prty_pp_start_index = (POPUP_ID)(p_popup_id + (POPUP_ID)1);
          for (fl_index = (UINT8)(p_popup_id + (POPUP_ID_T)1); ((fl_index < (POPUP_ID_T)(fl_max_layer_popup_id))\
            && (fl_index < L_POPUP_MAX_COUNT)); fl_index++)
          {
            if (fl_popupid_grp_priorty != GROUP_PRIORITY(fl_index))
            {
              temp_low_prty_pp_start_index = (POPUP_ID)(fl_index);
              break;
            }
          }
        }
        else
        {
          /* if group priority is zero, the index of low priority pp is next popup  */
          temp_low_prty_pp_start_index = (POPUP_ID)(p_popup_id + (POPUP_ID)1);
        }

        for (fl_index = temp_low_prty_pp_start_index; ((fl_index < (fl_max_layer_popup_id)) && (fl_index < L_POPUP_MAX_COUNT)); fl_index++)
        {
          /* deactivate all low priority popup of a layer with config as deactivate and active status but not the same popup */
          if ((LOW_PRIORITY_PP_SELF_DEACTIVTION(fl_index)) && (POPUP_ACTIVE((fl_index))) && (p_popup_id != fl_index))
          {
            /* Remove the popup from respective queue if it is a group priority pp */
            if (GROUP_PRIORITY(fl_index) != (UINT8)NO_GROUP_PRIORITY)
            {
              (void)hmi_popup_core_remove_from_queue((POPUP_ID)fl_index, fl_layer, GROUP_PRIORITY(fl_index));
            }
            (void)hmi_popup_core_deactivate((POPUP_ID_T)fl_index, POPUP_CLOSED_ON_DEMAND_EVT
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
              , (POPUP_ANIMATION_ID)POPUP_ANIM_MAX_ID
#endif
            );
          }
        }

        if ((fl_active_pp != fl_max_layer_popup_id) && (fl_active_pp < (POPUP_ID)L_POPUP_MAX_COUNT))
        {
          /*check the popup is active, whether config is deactivated, new & active pp is not same*/

          if ((POPUP_ACTIVE((fl_active_pp))) && (DEACTIVATE_ACTIVE_PP(fl_active_pp))\
            && (fl_active_pp != p_popup_id))
          {
            if (GROUP_PRIORITY(fl_active_pp) != (UINT8)NO_GROUP_PRIORITY)
            {
              BOOLEAN temp_remove_status;
              POPUP_LAYER_TYPE const* fl_low_priority_pp_layer;

              fl_low_priority_pp_layer = hmi_popup_core_get_popup_layer(fl_active_pp);
              if (fl_low_priority_pp_layer != NULL)
              {
                temp_remove_status = hmi_popup_core_remove_from_queue(fl_active_pp, fl_low_priority_pp_layer, \
                  GROUP_PRIORITY(fl_active_pp));
                if (FALSE != temp_remove_status)
                {
                  (void)hmi_popup_core_deactivate((POPUP_ID_T)fl_active_pp, POPUP_CLOSED_ON_DEMAND_EVT
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
                    , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_LOWPRIO_ACTIVE_ANIM, fl_active_pp)
#endif
                  );
                }
              }
            }
            else
            {
              (void)hmi_popup_core_deactivate((POPUP_ID_T)fl_active_pp, POPUP_CLOSED_ON_DEMAND_EVT
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
                , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_LOWPRIO_ACTIVE_ANIM, fl_active_pp)
#endif
              );
            }
          }
          /* just allow to expire its timer if its type is not restart */
          if ((TIMERTYPE_RESTART(fl_active_pp)) && (fl_active_pp != p_popup_id))
          {
            hmi_popup_core_stop_popup_timer(fl_active_pp);
            hmi_popup_core_disable_timer_status((POPUP_ID_T)p_popup_id);
          }
        }

#if (POPUP_IGNORE_MIN_TIME_ON_HIGH_PRIO_POPUP!=1)
        /* Check for minimmum timer status and ignore if it is not configured i.e. POPUP_MAX_TMR */
        if (((fl_layer->l_min_tmr_id) == POPUP_MAX_TIMER)\
          || (HMI_POPUP_CHECK_TIMER(fl_layer->l_min_tmr_id) != POPUP_TMR_RUNNING))
#endif
        {
#ifdef LSH_ANIMATION_SUPPORT_ENABLED
          UINT8 p_anim_remove_id;
          POPUP_ANIMATION_ID fl_anim_id = p_anim_id;
          LSH_STATE_ID_T fl_active_lsh_ID = LSH_NUMBER_OF_LOGIC_STATES;
          if (fl_active_pp < (POPUP_ID)L_POPUP_MAX_COUNT)
          {
            fl_active_lsh_ID = LOGIC_STATE_ID(fl_active_pp);
          }
          p_anim_remove_id = POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_LOWPRIO_ACTIVE_ANIM, p_popup_id);

          if (fl_active_lsh_ID == LOGIC_STATE_ID(p_popup_id))
          {
            /* The animation needs to block if already active and new popup has same screen id */
            fl_anim_id = (POPUP_ANIMATION_ID)POPUP_ANIM_MAX_ID;
            p_anim_remove_id = (POPUP_ANIMATION_ID)POPUP_ANIM_MAX_ID;
          }
          else
          {
            p_anim_remove_id = POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_LOWPRIO_ACTIVE_ANIM, p_popup_id);
          }

#endif

          hmi_popup_core_stop_popup_min_timer(fl_active_pp);
          /* Remove the popup from LSH, it will be added when new popup is closed */
          if ((fl_active_pp < (fl_max_layer_popup_id)) && ((fl_active_pp != p_popup_id)))
          {
#ifdef LSH_APP_REM_HANDLER  
            (void)POPUP_LSH_REM_STATE_EXT(fl_active_lsh_ID, p_anim_remove_id, (UINT8)fl_active_pp, (POPUP_LAYER_ID)fl_layer->l_layer_index);
#else
            (void)POPUP_LSH_REM_STATE_EXT(fl_active_lsh_ID, p_anim_remove_id, (UINT8)fl_active_pp);
#endif
          }


#ifdef LSH_APP_ADD_HANDLER
          fl_return_U8 = POPUP_LSH_ADD_STATE_EXT(LOGIC_STATE_ID(p_popup_id), fl_anim_id, (UINT8)p_popup_id, (POPUP_LAYER_ID)fl_layer->l_layer_index);
#else
          fl_return_U8 = POPUP_LSH_ADD_STATE_EXT(LOGIC_STATE_ID(p_popup_id), fl_anim_id, (UINT8)p_popup_id);
#endif

#ifdef POPUP_TYPE_PROGRESSBAR
          if (fl_active_pp != p_popup_id)
          {
            if (POPUP_TYPE(p_popup_id) == (UINT8)POPUP_PROGRESS)
            {
              PROGRESSBAR_PP_INIT_CURRENTCOUNT(p_popup_id);
            }
          }
#endif
        }
        /* Mark the popup to be active */
        ACTIVATE_POPUP((p_popup_id));
        ACTIVATE_LSH_POPUP((p_popup_id));
        /* Mark the timer status
        So, that it can be started when current popup minimum timer expires */
        if ((lc_popup_config_table[p_popup_id].layer_timeout != 0U)
#ifdef POPUP_TYPE_KEYPAD
          || ((0U != KEYPAD_PP_MULTIPRESS_TIMEOUT(p_popup_id)) && (POPUP_TYPE(p_popup_id) == (UINT8)POPUP_KEYPAD))
#endif
          )
        {
          if (lc_popup_config_table[p_popup_id].timerid < POPUP_MAX_TIMER)
          {
            ENABLE_TIMER_STATUS((p_popup_id));
            /* Start the Timer for the requested popup if its
            * timer type is allow to expire */
            if (lc_popup_config_table[p_popup_id].timer == (UINT8)ALLOW_TO_EXPIRE)
            {
              hmi_popup_core_start_popup_timer(p_popup_id);
            }
          }
        }
      }
      else
      {
        if (!LOW_PRIORITY_PP_SELF_DEACTIVTION(p_popup_id))
        {
          /* Mark the timer status
          So, that it can be started when it priority comes */
          if (lc_popup_config_table[p_popup_id].layer_timeout != (UINT16)0)
          {
            if (lc_popup_config_table[p_popup_id].timerid < POPUP_MAX_TIMER)
            {
              ENABLE_TIMER_STATUS((p_popup_id));
            }
          }
          /* Start the Timer for the requested low priority popup if its
          * timer type is allow to expiare */
          if (lc_popup_config_table[p_popup_id].timer == (UINT8)ALLOW_TO_EXPIRE)
          {
            hmi_popup_core_start_popup_timer(p_popup_id);
          }
          if (fl_popupid_grp_priorty != (UINT8)NO_GROUP_PRIORITY)
          {
            (void)hmi_popup_core_add_to_queue(p_popup_id, fl_layer, fl_popupid_grp_priorty);
          }
          /* Mark the Popup to be active */
          ACTIVATE_POPUP((p_popup_id));
#ifdef POPUP_TYPE_PROGRESSBAR
          if (POPUP_TYPE(p_popup_id) == (UINT8)POPUP_PROGRESS)
          {
            PROGRESSBAR_PP_INIT_CURRENTCOUNT(p_popup_id);
          }
#endif
          ACTIVATE_LSH_POPUP((p_popup_id));
        }
      }
    }
  }
  return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_deativate_popup
** Visibility       : Global, Interface to the Application
** Description      : This function should be called to deactivate a particular
**                    popup.
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_popup_id - Enumeration of the Popup to be deactivated
**                    p_anim_id  - Animation ID to perform                     
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
UINT8 hmi_popup_core_deactivate_popup(POPUP_ID p_popup_id
                                      #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                      ,POPUP_ANIMATION_ID p_anim_id
                                      #endif
                                      )
{
  UINT8 fl_return_U8;
  fl_return_U8 = LSH_STATUS_NONE;
  
  /* Is valid popup */
  if((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    POPUP_LAYER_TYPE const * fl_layer; 
    UINT8 temp_timer_status;
    POPUP_ID fl_active_pp;

    /* Identify the layer to which this popup belongs to
     * and set the corresponding status bit of the popup */
    fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
    if(fl_layer!=NULL)
    {
      fl_active_pp=hmi_popup_core_get_active_popup(fl_layer);
      /* Check for Minimum Timeout Expiry */
        if(fl_active_pp != (MAX_LAYER_POPUP_ID(fl_layer)))
        {
          if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
          {
            if ((p_popup_id != l_active_popup_id[fl_layer->l_layer_index]) || (lc_popup_config_table[p_popup_id].min_timeout == (UINT16)0))
            {
              /* Minimum Timeout timer is expired , so deactivate the Popup */
              fl_return_U8 = hmi_popup_core_close_popup(p_popup_id, POPUP_CLOSED_ON_DEMAND_EVT
                                                    #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                                    , p_anim_id
                                                    #endif
                                                    );
            }
          
            else
            {
              temp_timer_status=HMI_POPUP_CHECK_TIMER(fl_layer->l_min_tmr_id);
              if(temp_timer_status != POPUP_TMR_RUNNING)
              {
                  fl_return_U8 = hmi_popup_core_close_popup(p_popup_id, POPUP_CLOSED_ON_DEMAND_EVT
                                                        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                                        , p_anim_id
                                                        #endif
                                                        );
              }
              else
              {
                  SET_MIN_TIMER_DEACTIVATE_PENDING((p_popup_id));
              }
            }
          }
        }
      
    }
  }
return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_forced_deactivate_popup
** Visibility       : Global, Interface to the Application
** Description      : This function should be called to deactivate a particular
**                    popup even with in minimum timer active.
** Invocation       : Invoked by the Application
** Inputs/Outputs   : p_popup_id - Enumeration of the Popup to be deactivated
**                    p_anim_id  - Animation ID to perform                     
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
UINT8 hmi_popup_core_forced_deactivate_popup(POPUP_ID p_popup_id
                                            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                            ,POPUP_ANIMATION_ID p_anim_id
                                            #endif
                                            )
{
  UINT8 fl_return_U8;
  fl_return_U8 = LSH_INVALID_STATUS;

  /* Is valid popup */
  if((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    fl_return_U8 = hmi_popup_core_close_popup(p_popup_id, POPUP_CLOSED_ON_DEMAND_EVT
                                              #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                              , p_anim_id
                                              #endif
                                              );
  }
  return(fl_return_U8);
}
/*============================================================================
** Function Name    : hmi_popup_core_rx_button_handler
** Visibility       : Global, Interface to the View state manager
** Description      : Function should be called when a btn event is receive
**                    while Popup is active.
** Invocation       : Invoked by the View State Manager
** Inputs/Outputs   : p_button_id_U16 - Button ID
**                    p_layer_id 
**                    p_logic_state_U8,
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 31 JUL, 2013 NKRISHN9
**==========================================================================*/
UINT8 hmi_popup_core_rx_button_handler(POPUP_LAYER_ID p_layer_id, LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
  POPUP_LAYER_TYPE const *fl_layer;
  POPUP_ID fl_active_pp;
  UINT8 fl_return_U8 = LSH_STATUS_NONE;
#if defined(POPUP_TYPE_KEYPAD) || defined(POPUP_TYPE_ACK)
  UINT16 fl_button_command_U16;
#endif
#ifdef POPUP_TYPE_ACK
  UINT8 fl_count_index;
  UINT8 fl_max_count_u8;
  BOOLEAN fl_match_found;
  UINT16 const * fl_event_ptr;
  ACK_EVENT_TYPE const *fl_ackevent_ptr;
#endif

  /* Get the Layer Information from the Raw Popup ID */
   if (p_layer_id < POPUP_MAX_LAYERS)
   {
    fl_layer = l_layer_table[p_layer_id];
    if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
    {
      fl_active_pp = l_active_popup_id[fl_layer->l_layer_index];
#if defined(POPUP_TYPE_KEYPAD) || defined(POPUP_TYPE_ACK)
      fl_button_command_U16 = p_event_hndl_status_SP->button_command & LSH_ANIM_MASK_CLEAR;
#endif
      if (fl_active_pp < L_POPUP_MAX_COUNT)
      {
        if (LOGIC_STATE_ID(fl_active_pp) == p_event_hndl_status_SP->logic_state_id)
        {
          if (POUP_EVENT_HANDLER(fl_active_pp) != LSH_NULL_EVENT_HANDLER)
          {
            /* Pass the Button Event to the respective handler function */
            fl_return_U8 = POUP_EVENT_HANDLER(fl_active_pp)(p_event_hndl_status_SP);
          }
        }
      }

#if defined(POPUP_TYPE_KEYPAD) || defined(POPUP_TYPE_ACK)
  if(((fl_return_U8 & POPUP_BTN_ABSORBED) != POPUP_BTN_ABSORBED) &&\
     ((fl_return_U8 & POPUP_BTN_ACTION) != POPUP_BTN_ACTION)&&\
     ((fl_return_U8 & POPUP_BTN_BLOCK) != POPUP_BTN_BLOCK))
      {

        switch (POPUP_TYPE(fl_active_pp))
        {
#ifdef POPUP_TYPE_KEYPAD
        case POPUP_KEYPAD:
          /* The Button is not processed by the Application */
          fl_return_U8 = hmi_popup_keypad_btn_handler(KEYPAD_PP_TBL_PTR(fl_active_pp),
                                                      fl_button_command_U16, fl_active_pp);
          break;
#endif

#ifdef POPUP_TYPE_ACK
        case POPUP_ACK:
          /* The Button is not processed by the Application */
          fl_ackevent_ptr = ACK_BTN_EVENT_PTR(fl_active_pp);
          fl_max_count_u8 = ACK_BTN_COUNT(fl_active_pp);
          fl_match_found = FALSE;
      for(fl_count_index=0;((fl_count_index<fl_max_count_u8)&&(fl_match_found==FALSE));\
               fl_count_index++)
          {
            /* Processing the acknowledge buttons*/
            if (((fl_ackevent_ptr[fl_count_index].l_btn_event_U16) == fl_button_command_U16))
            {
              fl_match_found = TRUE;
              if (ACK_BTN_TYPE(fl_active_pp, fl_count_index) == PASSED)
              {
                fl_return_U8 = POPUP_BTN_NONE;
              }
              else
              {
                fl_return_U8 = POPUP_BTN_ABSORBED;
              }
              (void)hmi_popup_core_close_popup(fl_active_pp, POPUP_CLOSED_ON_ACK_EVT
                                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                          , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_ACK_ANIM,fl_active_pp)
                                          #endif
                                          );		  
            }
          }

          fl_event_ptr = NACK_BTN_EVENT_PTR(fl_active_pp);
          fl_max_count_u8 = NACK_BTN_COUNT(fl_active_pp);
      	  for(fl_count_index=0;((fl_count_index<fl_max_count_u8)&&(fl_match_found==FALSE));\
               fl_count_index++)
          {
            /* Processing the not acknowledge buttons*/
            if (((fl_event_ptr[fl_count_index]) == fl_button_command_U16))
            {
              fl_match_found = TRUE;
              if (NACK_BTN_TYPE(fl_active_pp) == PASSED)
              {
                fl_return_U8 = POPUP_BTN_NONE;
              }
              else
              {
                fl_return_U8 = POPUP_BTN_ABSORBED;
              }
            }
          }

          if (fl_match_found == FALSE)
          {
            /* if not processed above then */
            if (NACK_BTN_TYPE(fl_active_pp) == PASSED)
            {
              fl_return_U8 = LSH_STATUS_ABSORBED;
            }
            else
            {
              fl_return_U8 = LSH_STATUS_NONE;
            }
          }
          break;
#endif
        default:
          /* To Fix Misra Warning C 2012 Rule 16.4 */
          break;
        }
      }
#endif

      if(((fl_return_U8 & ((UINT8)POPUP_BTN_ABSORBED)) ==(UINT8)(POPUP_BTN_ABSORBED))\
       ||((fl_return_U8 & ((UINT8)POPUP_BTN_ACTION)) ==(UINT8)(POPUP_BTN_ACTION)))
      {
        /* The button event has been processed and hence
         * restart the timeout timer */
        if (lc_popup_config_table[fl_active_pp].layer_timeout != (UINT16)0)
        {
          /* Start the timer only if the status is set. Do not start the timer
           * if the status is clear as Application might want to hold the
           * timer. Wait for the start of the timer until notified by the app */
          if (IS_TIMER_STATUS_ENABLE((fl_active_pp)))
          {
            hmi_popup_core_start_popup_timer(fl_active_pp);
            if (POPUP_TYPE(fl_active_pp) == (UINT8)POPUP_KEYPAD)
            {
#ifdef POPUP_TYPE_KEYPAD
              /* The popup timer is restarted so, restart the
              timer counter also to extend the popup display timer */
              *(l_total_pp_type.l_keypad_entry_pp_table_ptr[POPUP_ID_INDEX(fl_active_pp)].l_multi_timer_counter) = 0;
#endif
            }
            else if (POPUP_TYPE(fl_active_pp) == (UINT8)POPUP_PROGRESS)
            {
#ifdef POPUP_TYPE_PROGRESSBAR
              PROGRESSBAR_PP_INIT_CURRENTCOUNT(fl_active_pp);
#endif
            }
            else
            {
              /* Do nothing */
            }
          }
        }
        if ((fl_return_U8 & ((UINT8)POPUP_BTN_ABSORBED)) == ((UINT8)POPUP_BTN_ABSORBED))
        {
          fl_return_U8 = POPUP_BTN_ABSORBED;
        }
        else
        {
          fl_return_U8 = POPUP_BTN_NONE;
        }
      }
      else if ((fl_return_U8 & ((UINT8)POPUP_BTN_BLOCK)) == ((UINT8)POPUP_BTN_BLOCK))
      {
        /* Return the status as absorbed outside to process by lsh. POPUP BTN BLOCK is a internal state
           to avoid popup layer timer restart as above */
        fl_return_U8 = LSH_STATUS_ABSORBED;
      }
      else
      {
        /*Do Nothing*/
      }
    }
   }
   return (fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_focus_handler
** Visibility       : Global, Interface to the View state manager
** Description      : This function should be called whenever the popup gains
**                    or looses focus
** Invocation       : Invoked by the view state manager
** Inputs/Outputs   : p_layer, p_logic_state_U8, p_focus_U8
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
void hmi_popup_core_focus_handler(POPUP_LAYER_ID p_layer, LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
  if(p_focus_hndl_status_SP->client_id < L_POPUP_MAX_COUNT)  
  {
    POPUP_ID fl_active_pp;
    POPUP_LAYER_TYPE const *fl_layer;
    UINT8 fl_focus_status_U8;
    if (p_layer < POPUP_MAX_LAYERS)
    {
      fl_layer = l_layer_table[p_layer];
      fl_active_pp = hmi_popup_core_get_active_popup(fl_layer);
      if(((UINT8)(POPUP_FOCUS_STATUS_MASK) & p_focus_hndl_status_SP->focus_status)!=(UINT8)0)
      {
  #ifdef POPUP_CORE_STATE_CALLBACK_HANDLER_DEFINED
          /* The popup core (whole) state as ACTIVE or INACTIVE is reported here */
          if (l_total_pp_type.pp_state_handler_ptr != NULL)
          {
            POPUP_ACTIVE_DATA_TYPE fl_active;
            fl_active = hmi_popup_core_find_active_popup_and_count((POPUP_ID)0, (POPUP_ID)L_POPUP_MAX_COUNT);
            /* The flag status helps to report only on state change as either active to inactive or vice-versa */
            if ((l_popup_status == TRUE) && ((POPUP_ID)0 == fl_active.total_popup_count))
            {
              /*no more popup is active whole popup core */
              l_total_pp_type.pp_state_handler_ptr(POPUP_STATE_INACTIVE);
              l_popup_status = FALSE;
            }
            else if ((l_popup_status == FALSE) && ((POPUP_ID)1 <= fl_active.total_popup_count))
            {
              /*one or more popup is active first time */
              l_total_pp_type.pp_state_handler_ptr(POPUP_STATE_ACTIVE);
              l_popup_status = TRUE;
            }
            else
            {
              /* To Fix Misra Warning C-2012 Rule 15.7 */
            }
          }
  #endif
          /* The popup status on lsh call back (focus handler) */
          if ((UINT8)0 == ((UINT8)(LSH_DEACTIVATED_STATUS)&p_focus_hndl_status_SP->focus_status))
          {
            /* This popup is added in lsh display
             * The timer for this popup should be started only if the
             * timer status is active, otherwise the timer will be started
             * when the application request for start of the timer */
            if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
            {
              if ((l_active_popup_id[fl_layer->l_layer_index] != (POPUP_ID)p_focus_hndl_status_SP->client_id) ||
                  (((UINT8)(LSH_GOT_FOCUS_STATUS)&p_focus_hndl_status_SP->focus_status) != (UINT8)0) ||
                  (!POPUP_ACTIVE_LSH(p_focus_hndl_status_SP->client_id)))
              {
                if ((lc_popup_config_table[p_focus_hndl_status_SP->client_id].timer != (UINT8)ALLOW_TO_EXPIRE) &&
                    (IS_TIMER_STATUS_ENABLE((POPUP_ID)(p_focus_hndl_status_SP->client_id))))
                {
                  hmi_popup_core_start_all_popup_timer((POPUP_ID)p_focus_hndl_status_SP->client_id);
                }
                else
                {
                  hmi_popup_core_start_popup_min_timer((POPUP_ID)p_focus_hndl_status_SP->client_id);
                }
              }
              l_active_popup_id[fl_layer->l_layer_index] = (POPUP_ID)p_focus_hndl_status_SP->client_id;
            }
            ACTIVATE_LSH_POPUP((p_focus_hndl_status_SP->client_id));
          }
          else
          {
            if ((fl_active_pp >= (MAX_LAYER_POPUP_ID(fl_layer))) && (fl_layer->l_layer_index < POPUP_MAX_LAYERS))
            {
              l_active_popup_id[fl_layer->l_layer_index] = (POPUP_ID)L_POPUP_MAX_COUNT;
            }
            DEACTIVATE_LSH_POPUP((p_focus_hndl_status_SP->client_id));
          }
      }

      /* LOW PRIORITY POPUP FOCUS Manipulation Cases                           **
      ** 1. LSH does not differentiate between multiple popup sharing the      **
      ** same screen ID.So there is a possiblity that LSH will route GOT FOCUS **
      ** Status through anim complete cb, though the popup is not the highest  **
      ** active popup in the given popup layer.                                **
      ** 2. when a high priopopup screen is added for same LSH priority, then  **
      ** LSH deactivates the low priopopup screen, though the popup is active  **
      ** in popup stack.                                                       **
      **          LOWPRIORITY POPUP FOCUS MANIPULATION STRATEGY                **
      ** If the popup is active in the popup layer with low priority           **
      ** then LSH_LOST_FOCUS_STATUS is routed, If the popup is not active in   **
      ** the popup Layer, the LSH_DEACTIVATED_STATUS is routed to Application  **
      ** ANIMATION STATUS is not modified. it is routed as it is from LSH      */

      /* if the popup is not active in popup stack, then it will be reported as deactivate 
        otherwise lost focus  */
      if(fl_active_pp!=(POPUP_ID)p_focus_hndl_status_SP->client_id)
      {
        fl_focus_status_U8 = (p_focus_hndl_status_SP->focus_status & (UINT8)POPUP_ANIM_STATUS_MASK);

        if (POPUP_ACTIVE((p_focus_hndl_status_SP->client_id)))
        {
          /* The popup is active in popuplayer and is not the highest priority one */
          p_focus_hndl_status_SP->focus_status = (fl_focus_status_U8 | LSH_LOST_FOCUS_STATUS);
        }
        else
        {
          /* The popup is no more active in popuplayer */
          p_focus_hndl_status_SP->focus_status = (fl_focus_status_U8 | LSH_DEACTIVATED_STATUS);
        }
      }

      /*  All focus status of the logic state which are added or removed by popup to 
          lsh will be informed by lsh itself. The remaining popup which is maintained
          by popup core will be informed to app during popup core task execution */
      if(POUP_FOCUS_HANDLER((p_focus_hndl_status_SP->client_id)) != LSH_NULL_FOCUS_HANDLER)
      {
        /* Call the Popup application Focus handler */
        POUP_FOCUS_HANDLER(p_focus_hndl_status_SP->client_id)( p_focus_hndl_status_SP);
      }
    }
  }
}


/*============================================================================
** Function Name    : hmi_popup_core_presentation_handler
** Visibility       : Global, Interface to the View state manager
** Description      : This function should be called to display/ update a
**                    popup in the display.
** Invocation       : Invoked by the View state manager
** Inputs/Outputs   : p_layer, p_logic_state_U8
**                    p_status_U8
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
void hmi_popup_core_presentation_handler(POPUP_LAYER_ID p_layer, LSH_PRESN_HANDLER_STATUS_T *p_presn_hndl_status_SP)
{
  POPUP_LAYER_TYPE const *fl_layer;
  POPUP_ID fl_active_pp;
  if(p_layer < POPUP_MAX_LAYERS)
  {
    fl_layer = l_layer_table[p_layer];

    /* The active popup will be updated only during a popup added to LSH. So, the previous presentation
      deactivation will be send only after minimum time expire. The other pp are not at all added to
      LSH, so deactivation is not required other than active popup */

    /* The active popup will be updated when LSH informs through focus status.
      The other pp are not at all added to LSH, so deactivation is not required other than active popup */

    fl_active_pp = (POPUP_ID)p_presn_hndl_status_SP->client_id;

    /* There is popup active in this layer */
    if (fl_active_pp < (MAX_LAYER_POPUP_ID(fl_layer)))
    {
      if ((POPUP_ID)L_POPUP_MAX_COUNT > fl_active_pp)
      {
        if (POUP_PRESENT_HANDLER(fl_active_pp) != LSH_NULL_PRESN_HANDLER)
        {
          POUP_PRESENT_HANDLER(fl_active_pp)(p_presn_hndl_status_SP);
        }
      }
    }
  }
}
/*============================================================================
** Function Name    : hmi_popup_core_remap_button_events
** Visibility       : Global, Interface to the Timer Module
** Description      : Re map button events
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_button_id_U16
**                    p_popup_id
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
void hmi_popup_core_remap_button_events(UINT16 p_button_id_U16, POPUP_ID p_popup_id )
{
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    hmi_lsh_remap_button_events_ext(p_button_id_U16, LOGIC_STATE_ID(p_popup_id), (UINT8)p_popup_id);
  }
}
/*============================================================================
** Function Name    : hmi_popup_core_timeout_callback
** Visibility       : Global, Interface to the Timer Module
** Description      : Call Back Function for the TImer Expired Notification
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_timer_id     - Index to the Timer
**                    p_event - MSB 8 Bit - type of the Timer
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/

void hmi_popup_core_timeout_callback(UINT16 p_timer_id, UINT16 p_event)
{
  UINT8 fl_tmr_type_U8;
  POPUP_ID fl_popup_id;
  
  fl_tmr_type_U8 = (UINT8)((p_event & (UINT16)0xFF00) >> (UINT16)8);
  fl_popup_id = (POPUP_ID)(p_event & (UINT16)0x00FF);

  /* Is a Valid Popup id*/
  if ((POPUP_ID)L_POPUP_MAX_COUNT > fl_popup_id)
  {
    POPUP_LAYER_TYPE  const * fl_layer;
    POPUP_ID_ATTRIBUTE_T fl_popup_id_type;
	
    fl_layer = hmi_popup_core_get_popup_layer(fl_popup_id);
    if(fl_layer!=NULL)
    {
      fl_popup_id_type = POPUP_TYPE(fl_popup_id);

      if(fl_popup_id < (MAX_LAYER_POPUP_ID(fl_layer)))
      {
        if(fl_tmr_type_U8 == (UINT8)HMI_TMR_TIME_OUT_TYPE)
        {
          if((UINT8)POPUP_PROGRESS==fl_popup_id_type)
          {
            #ifdef POPUP_TYPE_PROGRESSBAR
            if(FALSE==hmi_popup_core_increment_progressbar_counter(fl_popup_id))
            {
              (void)hmi_popup_core_close_popup(fl_popup_id, POPUP_CLOSED_ON_TIMEOUT_EVT
                                              #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                              ,POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_PROG_TIMEOUT_ANIM,fl_popup_id)
                                              #endif
                                              );
            }
            #endif
          }
          else if((UINT8)POPUP_KEYPAD==fl_popup_id_type)
          {
            #ifdef POPUP_TYPE_KEYPAD
            if(FALSE==hmi_popup_core_inc_keypadmultitimer_counter(fl_popup_id))
            {
              (void)hmi_popup_core_close_popup(fl_popup_id, POPUP_CLOSED_ON_TIMEOUT_EVT
                                            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                            , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_TIMEOUT_ANIM,fl_popup_id)
                                            #endif
                                            );
            }
            #endif
          }
          else
          {
            /* Popup Timer has expired, Remove the Popup */
            (void)hmi_popup_core_close_popup(fl_popup_id, POPUP_CLOSED_ON_TIMEOUT_EVT
                                          #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                          , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_TIMEOUT_ANIM,fl_popup_id)
                                          #endif
                                          ); 
          }
	    }
        else if(fl_tmr_type_U8 == (UINT8)HMI_TMR_MINIMUM_TIMEOUT_TYPE)
	    {
          /* Minimum timeout timer is expired. Check if there are any DeActivation Status */
          if (fl_layer->l_min_tmr_id != HMI_NO_OF_TIMERS)
          {
            if (POPUP_MINIMUM_TIME(fl_popup_id) != (UINT16)0)
            {
              hmi_popup_core_send_event_notification((POPUP_ID)fl_popup_id, POPUP_MIN_TIME_EXPIRE_EVT);
              if(MIN_TIMER_DEACTIVATE_PENDING((fl_popup_id)))
              {
                /* This popup was deactivate before its minimum timeout */
                (void)hmi_popup_core_close_popup(fl_popup_id, POPUP_CLOSED_ON_DEMAND_EVT
                                              #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                              , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_MINTIMEOUT_ANIM,fl_popup_id)
                                              #endif
                                              );
                hmi_popup_core_clear_min_deact_pndng((POPUP_ID_T)fl_popup_id);
              }
            }
          }
	    }
	    else
	    {
          /* To Fix Misra Warning C-2012 Rule 15.7 */ 
	    }
      }
	}
  }
  HMI_UNUSED_VAR(p_timer_id);
}
/*============================================================================
** Function Name    : hmi_popup_core_start_timer()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to start popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup_id     - 
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
BOOLEAN hmi_popup_core_start_timer(POPUP_ID p_popup_id)
{
  BOOLEAN fl_return_BOOL = FALSE;
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    if(lc_popup_config_table[p_popup_id].layer_timeout != (UINT16)0)
    {
      if(lc_popup_config_table[p_popup_id].timerid<POPUP_MAX_TIMER)
      {
        POPUP_LAYER_TYPE const * fl_layer;
        fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
        /* Enable the timer status only if it is already activated by application */
        if(fl_layer!=NULL)
        {
          if(POPUP_ACTIVE((p_popup_id)))
          {
            ENABLE_TIMER_STATUS((p_popup_id));
            /* Start the timer only if it is in lsh display. Otherwise, the timer will 
            be started when it get focus */
            if(fl_layer->l_layer_index < POPUP_MAX_LAYERS)
            {
              if (l_active_popup_id[fl_layer->l_layer_index] == p_popup_id)
              {
                hmi_popup_core_start_all_popup_timer(p_popup_id);
              }
            }
          }
          fl_return_BOOL = TRUE;
        }
      }
    }
  }
  return(fl_return_BOOL);
}
/*============================================================================
** Function Name    : hmi_popup_core_stop_timer()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to stop popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup_id     - Popup Id of a Key pad entry Popup
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
BOOLEAN hmi_popup_core_stop_timer(POPUP_ID p_popup_id)
{
  BOOLEAN fl_return_BOOL = FALSE;
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    if(lc_popup_config_table[p_popup_id].layer_timeout != (UINT16)0)
    {
      if(lc_popup_config_table[p_popup_id].timerid<POPUP_MAX_TIMER)
      {
        POPUP_LAYER_TYPE const * fl_layer;
        fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);

        if(fl_layer!=NULL)
        {
          if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
          {
            if (l_active_popup_id[fl_layer->l_layer_index] == p_popup_id)
            {
              hmi_popup_core_stop_all_popup_timer(p_popup_id);
            }
          }
          hmi_popup_core_disable_timer_status((POPUP_ID_T)p_popup_id);
          fl_return_BOOL = TRUE;
        }
      }
    }
  }
  return(fl_return_BOOL);
}

#ifdef POPUP_TYPE_KEYPAD
/*============================================================================
** Function Name    : hmi_popup_core_get_keypad_content()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to stop popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup_id     - Popup Id of a Key pad entry Popup
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
UINT8 hmi_popup_core_get_keypad_content(POPUP_KEYPAD_CONTENT_TYPE *const p_keypad_content)
{
  UINT8 fl_return_U8 = 0;
  POPUP_KEYPADENTRY_TYPE  const *fl_keypad_pp;
  UINT8 fl_src_len_U8 = 0;
  UINT8 fl_des_len_U8 = 0;
  HMI_CHAR *fl_src =  NULL;

  /* Is valid popup */
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_keypad_content->popup_id)
  {
    if ((UINT8)POPUP_KEYPAD == POPUP_TYPE(p_keypad_content->popup_id))
    {
      fl_keypad_pp = KEYPAD_PP_TBL_PTR(p_keypad_content->popup_id);
      fl_src = fl_keypad_pp->l_entry_ptr;
      fl_des_len_U8 = p_keypad_content->len_U8;
      fl_src_len_U8=0;
      /* find the length of src string */
      while ((*(fl_src) != '\0')&&(fl_src_len_U8 < (fl_keypad_pp->l_max_char_U8)))
      {
        fl_src_len_U8++;
        fl_src++;
      }

      /* Copy the content */
      if (fl_src_len_U8 <= fl_des_len_U8)
      {
      /* There is enough space to copy */
        UINT8 t_counter;
        fl_src=fl_keypad_pp->l_entry_ptr;

        t_counter = 0;
        while((fl_src[t_counter] != '\0') && (t_counter < fl_src_len_U8))
        {
          p_keypad_content->entry[t_counter] = fl_src[t_counter];
          t_counter++;
        }
        /* Now load the Null Character L\0 T the end of the string */
        p_keypad_content->entry[t_counter] = '\0';
        fl_return_U8 = t_counter;
      }
      else
      {
        /* There is not enough space to copy all the items to the
        * desitination and als we cannot copy the partial items
        * that would fit in the destination */
      }
    }
  }
	return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_set_keypad_content()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to stop popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup     - Popup Id of a Key pad entry Popup
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
UINT8 hmi_popup_core_set_keypad_content(POPUP_KEYPAD_CONTENT_TYPE const * const p_keypad_content)
{
  UINT8 fl_return_U8 = 0;
  POPUP_KEYPADENTRY_TYPE  const *fl_keypad_pp;
  UINT8 fl_src_len_U8 = 0;
  UINT8 fl_des_len_U8 = 0;
  HMI_CHAR *fl_src =  NULL;
  HMI_CHAR *fl_dest = NULL;

  /* Is valid popup */
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_keypad_content->popup_id)
  {
    if ((UINT8)POPUP_KEYPAD == POPUP_TYPE(p_keypad_content->popup_id))
    {
      fl_keypad_pp = KEYPAD_PP_TBL_PTR(p_keypad_content->popup_id);
      fl_src = p_keypad_content->entry;
      fl_dest = fl_keypad_pp->l_entry_ptr;

      fl_des_len_U8 = (p_keypad_content->len_U8);
      /* find the length of src string */
      while ((*(fl_src) != '\0')&&(fl_src_len_U8 < (fl_keypad_pp->l_max_char_U8)))
      {
        fl_src_len_U8++;
        fl_src++;
      }

      fl_src = p_keypad_content->entry;
      /* Copy the content */
      if ((fl_src_len_U8 <= fl_des_len_U8) && (fl_dest != NULL))
      {
      /* There is enough space to copy */
        UINT8 t_counter;

        t_counter = 0;
        while((fl_src[t_counter] != '\0') &&
             ((t_counter < fl_src_len_U8) || (fl_src_len_U8 == 0)))
        {
          fl_dest[t_counter] = fl_src[t_counter];
          t_counter++;
        }
        /* Now load the Null Character L\0 T the end of the string */
        fl_dest[t_counter] = '\0';
        fl_return_U8 = t_counter;
      }
      else
      {
        /*Space not available to copy the source string, so don't copy*/
      }
    }
  }
	return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_set_keypad_entry()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to stop popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup     - Popup Id of a Key pad entry Popup
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
void hmi_popup_core_set_keypad_entry(POPUP_KEYPAD_SET_TYPE const * const p_keypad_set)
{
  POPUP_KEYPADENTRY_TYPE  const *fl_keypad_pp;

  /* Is valid popup */
  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_keypad_set->popup_id)
  {
    if ((UINT8)POPUP_KEYPAD == POPUP_TYPE(p_keypad_set->popup_id))
    {
      fl_keypad_pp = KEYPAD_PP_TBL_PTR(p_keypad_set->popup_id);

      /* Intialize the Key Pad Entry */
      *fl_keypad_pp->l_entry_ptr = 0;

      /* Process the Button Handler */
      /* The button data needs to be processed just when keypad popup starts. ex cd track num 
         Here, press and release is sent for the corresponding button for consistent with 
         normal event handler */
      (void)hmi_popup_keypad_btn_handler(fl_keypad_pp, LSH_GET_COMMAND (p_keypad_set->btn_id, p_keypad_set->btn_state), p_keypad_set->popup_id);
      (void)hmi_popup_keypad_btn_handler(fl_keypad_pp, LSH_GET_COMMAND (p_keypad_set->btn_id, LSH_BUTTON_INACTIVE_STATE), p_keypad_set->popup_id);
    }
  }
}
#endif

#ifdef POPUP_TYPE_PROGRESSBAR
/*============================================================================
** Function Name    : hmi_popup_core_get_progress_bar_counter()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to get popup progress bar counter 
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_progress/ true/false to set or not
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
BOOLEAN hmi_popup_core_get_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE *p_progress)
{
  BOOLEAN r_progress_bar_status;
  r_progress_bar_status=FALSE;
  if((POPUP_ACTIVE((p_progress->popup_id)))&&(POPUP_TYPE(p_progress->popup_id)==(UINT8)POPUP_PROGRESS))
  {
    *(p_progress->cnt_ptr_U8)=PROGRESSBAR_PP_CURRENTCOUNT(p_progress->popup_id);
    r_progress_bar_status=TRUE;
  }
  return(r_progress_bar_status);
}

/*============================================================================
** Function Name    : hmi_popup_core_set_progress_bar_counter()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to set progress bar counter
** Invocation       : This function is used to set popup progress bar counter 
** Inputs/Outputs   : p_progress/ true/false to set or not
** Critical Section : No
** Created          : 20 JUN, 2013 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
BOOLEAN hmi_popup_core_set_progress_bar_counter(POPUP_PROGRESS_COUNT_TYPE const * const p_progress)
{
  BOOLEAN r_progress_bar_status;
  r_progress_bar_status=FALSE;
  if((POPUP_ACTIVE((p_progress->popup_id)))&&(POPUP_TYPE(p_progress->popup_id)==(UINT8)POPUP_PROGRESS))
  {
    PROGRESSBAR_PP_CURRENTCOUNT(p_progress->popup_id)=*(p_progress->cnt_ptr_U8);
    r_progress_bar_status=TRUE;
  }
  return(r_progress_bar_status);
}
#endif

/*============================================================================
** Function Name    : hmi_popup_core_task
** Visibility       : Local
** Description      : This function should be called to execute the
**                    Presentation and focus handlers
** Invocation       : Invoked by the application 
** Inputs/Outputs   : No
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
void hmi_popup_core_task(void)
{
  UINT8 fl_index;
  UINT8 fl_index1;
  UINT16 fl_index2;
  LSH_FOCUS_HANDLER_STATUS_T  fl_focus_hndl_status_S;
  
  /* The focus status needs to give for the popups which are not added/ removed to lsh */
  /* The focus id will be same as the logic state id of the popup */
  for(fl_index = (UINT8)0; fl_index < (UINT8)((L_POPUP_MAX_COUNT+7U)/8U); fl_index++)
  {
    if(l_pp_id_sts_bit_U8[fl_index]!=l_pp_id_lsh_sts_bit_U8[fl_index])
    {
      for(fl_index1 = (UINT8)0; fl_index1 < (UINT8)8; fl_index1++)
      {
        POPUP_LAYER_TYPE const * fl_layer;
        fl_layer = hmi_popup_core_get_popup_layer((POPUP_ID)((fl_index*((UINT8)8))+fl_index1));
        fl_index2 = (fl_index*((UINT16)8))+fl_index1;
        if(fl_layer!=NULL)
        {
         if(fl_index2 < (UINT16)L_POPUP_MAX_COUNT)
         {
          if (fl_layer->l_layer_index < POPUP_MAX_LAYERS)
          {
            if((!(POPUP_ACTIVE((fl_index2))))&&(POPUP_ACTIVE_LSH((fl_index2)))\
            &&(l_active_popup_id[fl_layer->l_layer_index]!=(fl_index2)))
            {
                  /* For all the popup which are deactivated by popup core selfly, the deactivated status is
                  updated to application */
                  fl_focus_hndl_status_S.logic_state_id = LOGIC_STATE_ID(fl_index2);
                  fl_focus_hndl_status_S.focus_status = (LSH_DEACTIVATED_STATUS | LSH_LOST_FOCUS_STATUS);
                  fl_focus_hndl_status_S.focus_id = LOGIC_STATE_ID(fl_index2);
                  if (POUP_FOCUS_HANDLER(fl_index2) != LSH_NULL_FOCUS_HANDLER)
                  {
              		POUP_FOCUS_HANDLER(fl_index2)( &fl_focus_hndl_status_S);
                  }
            }
            /* The popup which are in popup core stack(not updated to lsh) of each layer need not informed
            its lost status, since it is not yet in display(updated to lsh). Even lsh will report its lost
            or gain status only after the screen comes to display (i.e. not when previous screen animation
            completion waiting time) */
          }
         }
        }
      }
      l_pp_id_lsh_sts_bit_U8[fl_index]=l_pp_id_sts_bit_U8[fl_index];
    }
  }
}

/*******************************************************************************
PRIVATE_FUNCTIONS() {}
********************************************************************************/


/*============================================================================
** Function Name    : hmi_popup_core_close_popup
** Visibility       : Internal Interface
** Description      : This function closes the current popup and activates the next
**                    priority one if any
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_layer_pp_id - Index to the Popup Layer
**                    p_event - Event to close the popup
**                    POPUP_ANIMATION_ID p_anim_id
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
static UINT8 hmi_popup_core_close_popup(POPUP_ID p_popup_id, POPUP_EVENTS p_event
                                        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                        ,POPUP_ANIMATION_ID p_anim_id
                                        #endif
                                        )
{
  UINT8 fl_return_U8 = LSH_INVALID_STATUS;
  POPUP_LAYER_TYPE const * fl_layer;
  POPUP_ID fl_active_pp;
  POPUP_ID fl_temp_active_pp;
  fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
  if(fl_layer!=NULL)
  {
   fl_temp_active_pp = hmi_popup_core_get_active_popup(fl_layer);
  
  /* Check whether the popup to deactivate is active */
  if (POPUP_ACTIVE((p_popup_id)))
  {
    #ifdef LSH_ANIMATION_SUPPORT_ENABLED
    POPUP_ANIMATION_ID fl_anim_id = p_anim_id;
    #endif
    if(VALID_GROUP_PRIORITY((p_popup_id),(fl_layer)))
    {
      if(GROUP_PRIORITY(p_popup_id)!=(UINT8)NO_GROUP_PRIORITY)
      {
        (void)hmi_popup_core_remove_from_queue(p_popup_id, fl_layer, GROUP_PRIORITY(p_popup_id));
      }
    }
    fl_return_U8=hmi_popup_core_deactivate((POPUP_ID_T)p_popup_id, p_event
                                            #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                            , fl_anim_id
                                            #endif
                                            );
    hmi_popup_core_disable_timer_status((POPUP_ID_T)p_popup_id);

    /* Do not stop the timer if it is not active popup and allow to expire type */
    if((TIMERTYPE_ALLOWTO_EXPIRE(p_popup_id))||(fl_temp_active_pp==p_popup_id))
    {
      hmi_popup_core_stop_all_popup_timer(p_popup_id);
      hmi_popup_core_clear_min_deact_pndng((POPUP_ID_T)p_popup_id);
    }

    /* while deactivating a low prio pp do not add the high prio popup again */
    fl_active_pp = hmi_popup_core_get_active_popup(fl_layer);
    if(fl_active_pp!=fl_temp_active_pp)
    {
      #ifdef LSH_ANIMATION_SUPPORT_ENABLED
      if(fl_anim_id==POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_TIMEOUT_ANIM,fl_active_pp))
      {
			fl_anim_id=POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_ADD_TIMEOUT_ANIM,fl_active_pp);
      }
      else if(fl_anim_id==POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_REMOVE_MINTIMEOUT_ANIM,fl_active_pp))
      {
		    fl_anim_id=POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_POPUP_ADD_MINTIME_ANIM,fl_active_pp);
      }
      else
      {
			fl_anim_id=POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_DEFAULT_POPUP_ADD_ANIM,fl_active_pp);
      }
      #endif
      (void)hmi_popup_core_activate(fl_layer
                                    #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                    , fl_anim_id
                                    #endif
                                    );
    }
   }
  }
  return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_deactivate
** Visibility       : Internal Interface
** Description      : This function deactivate popup 
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id - Index to the Popup id
**                    p_event - Event to close the popup
**                    POPUP_ANIMATION_ID p_anim_id
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
static UINT8 hmi_popup_core_deactivate(POPUP_ID_T p_popup_id, POPUP_EVENTS p_event
                                        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                        , POPUP_ANIMATION_ID p_anim_id
                                        #endif
                                        )
{
    UINT8 fl_return_U8 = LSH_INVALID_STATUS;
    if (p_popup_id < L_POPUP_MAX_COUNT)
    {
    #ifdef LSH_APP_REM_HANDLER
        POPUP_LAYER_TYPE const * fl_layer;
        fl_layer = hmi_popup_core_get_popup_layer((POPUP_ID)p_popup_id);
        fl_return_U8 = POPUP_LSH_REM_STATE_EXT(LOGIC_STATE_ID(p_popup_id), p_anim_id, (UINT8)p_popup_id, (POPUP_LAYER_ID)fl_layer->l_layer_index);
    #else
        fl_return_U8 = POPUP_LSH_REM_STATE_EXT(LOGIC_STATE_ID(p_popup_id), p_anim_id, (UINT8)p_popup_id);
    #endif

        /* Clear the activation status bit of the corresponding popup if the popup is de-activated */
        DEACTIVATE_POPUP((p_popup_id));
    #ifdef POPUP_TYPE_KEYPAD
        if(POPUP_TYPE(p_popup_id) == (UINT8)POPUP_KEYPAD)
        {
            *(l_total_pp_type.l_keypad_entry_pp_table_ptr[POPUP_ID_INDEX(p_popup_id)].l_curr_multi_press_btn)=0;
        }
    #endif
        hmi_popup_core_send_event_notification((POPUP_ID)p_popup_id, p_event);
    }
    return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_activate
** Visibility       : Internal Interface
** Description      : This function activates the popup
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_layer - Popup Layer pointer
**                    POPUP_ANIMATION_ID p_anim_id
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 nkrishn9
**==========================================================================*/
static UINT8 hmi_popup_core_activate(POPUP_LAYER_TYPE const *p_layer
                                    #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                    ,POPUP_ANIMATION_ID p_anim_id
                                    #endif
                                    )
{
    UINT8 fl_return_U8 = LSH_INVALID_STATUS;
    POPUP_ID fl_active_pp;
    #ifdef LSH_APP_ADD_HANDLER
    POPUP_LAYER_TYPE const * fl_layer;
    #endif

    /* Check if it has any popup to be displayed */
    fl_active_pp = hmi_popup_core_get_active_popup(p_layer);

    if (fl_active_pp < (POPUP_ID)L_POPUP_MAX_COUNT)
    {
        if (fl_active_pp != (MAX_LAYER_POPUP_ID(p_layer)))
        {
            if(VALID_GROUP_PRIORITY((fl_active_pp), (p_layer)))
            {
              if(GROUP_PRIORITY(fl_active_pp)!=(UINT8)NO_GROUP_PRIORITY)
              {
                fl_active_pp=hmi_popup_core_get_lastin_pp_in_queue(p_layer, GROUP_PRIORITY(fl_active_pp));
              }
            }

            /****************************************************************************
            ** When Invalid animation ID is passed, The screen ID is not queued to the **
            ** LSH. Due to which there are inconsistencies when multiple popup's with  **
            ** same screen ID's were builded.                                          **
            *****************************************************************************/
            #ifdef LSH_APP_ADD_HANDLER
            fl_layer = hmi_popup_core_get_popup_layer(fl_active_pp);
            fl_return_U8 = POPUP_LSH_ADD_STATE_EXT(LOGIC_STATE_ID(fl_active_pp), p_anim_id, (UINT8)fl_active_pp, (POPUP_LAYER_ID)fl_layer->l_layer_index);
            #else
            if ((POPUP_ID)L_POPUP_MAX_COUNT > fl_active_pp)
            {
              fl_return_U8 = POPUP_LSH_ADD_STATE_EXT(LOGIC_STATE_ID(fl_active_pp), p_anim_id, (UINT8)fl_active_pp);
            }
            #endif
        }
    }
    return(fl_return_U8);
}

/*============================================================================
** Function Name    : hmi_popup_core_get_popup_layer
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function returns pointer to the layer for a give
**                    Raw Popup ID
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id - Popup ID
**                    POPUP_LAYER_TYPE - Pointer to the Layer
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static POPUP_LAYER_TYPE  const * hmi_popup_core_get_popup_layer(POPUP_ID p_popup_id)
{
  UINT8 fl_layer_index_U8;
  POPUP_LAYER_TYPE  const * fl_layer = NULL;
  UINT16 fl_pp_count_U16  = 0;

  for(fl_layer_index_U8 = 0; (fl_layer_index_U8 < POPUP_MAX_LAYERS); fl_layer_index_U8++ )
  {
     fl_pp_count_U16 += l_layer_table[fl_layer_index_U8]->l_total_pp_count;
     if( p_popup_id < fl_pp_count_U16 )
     {
      /* Popup layer table is identified */
      fl_layer =  l_layer_table[fl_layer_index_U8];
      break;
     }
  }
  return(fl_layer);
}
/*============================================================================
** Function Name    : hmi_popup_core_get_active_popup
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function returns the active popup (High Priority) in
**                    a given layer
** Invocation       : invoked by the Popup Core
** Inputs/Outputs   : p_layer     - pointer to a Layer
**                    Output: High prio/ active popup
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
static POPUP_ID hmi_popup_core_get_active_popup(POPUP_LAYER_TYPE const *p_layer)
{
  POPUP_ID_T fl_index;
  POPUP_ID fl_return;

  fl_return = (POPUP_ID)(MAX_LAYER_POPUP_ID(p_layer));

  for (fl_index = POPUP_LAYER_START_INDEX((p_layer)); fl_index < (MAX_LAYER_POPUP_ID(p_layer)); fl_index++)
  {
    if (POPUP_ACTIVE((fl_index)))
    {
      fl_return = (POPUP_ID)fl_index;
      if (fl_return < L_POPUP_MAX_COUNT)
      {
        if (GROUP_PRIORITY(fl_return) != (UINT8)NO_GROUP_PRIORITY)
        {
          fl_return = hmi_popup_core_get_lastin_pp_in_queue(p_layer, GROUP_PRIORITY(fl_return));
        }
        break;
      }
     }
  }

  return(fl_return);
}
/*============================================================================
** Function Name    : hmi_popup_core_start_popup_timer  
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function Starts the relevant Popup Timers
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id - Popup ID
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_start_popup_timer(POPUP_ID p_popup_id)
{
  if(p_popup_id< (POPUP_ID)L_POPUP_MAX_COUNT)
  {
    if((UINT8)POPUP_KEYPAD!=POPUP_TYPE(p_popup_id))
    {
      if(lc_popup_config_table[p_popup_id].layer_timeout != 0U)
      {
        if(lc_popup_config_table[p_popup_id].timerid<POPUP_MAX_TIMER)
        {
          HMI_POPUP_START_TIMER((TIMER_ID_TYPE)lc_popup_config_table[p_popup_id].timerid,lc_popup_config_table[p_popup_id].layer_timeout,((UINT16)((UINT16)HMI_TMR_TIME_OUT_TYPE << 8U) | (UINT16)p_popup_id));
        }
      }
    }
    else
    {
#ifdef POPUP_TYPE_KEYPAD    
      if((lc_popup_config_table[p_popup_id].layer_timeout != 0)||(0!=KEYPAD_PP_MULTIPRESS_TIMEOUT(p_popup_id)))
      {
        if(lc_popup_config_table[p_popup_id].timerid<POPUP_MAX_TIMER)
        {
          UINT16 fl_timeout;
          fl_timeout=KEYPAD_PP_MULTIPRESS_TIMEOUT(p_popup_id);

          /* if the multipress timeout is zero, then start with layer timer */
          if(0==fl_timeout)
          {
            fl_timeout=lc_popup_config_table[p_popup_id].layer_timeout;
          }
          HMI_POPUP_START_TIMER((TIMER_ID_TYPE)lc_popup_config_table[p_popup_id].timerid, fl_timeout, ((UINT16)(HMI_TMR_TIME_OUT_TYPE << 8) | (UINT16)p_popup_id));
        }
      }
#endif
    }
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_stop_timer()
** Visibility       : Global, Interface to the Popup Core Application
** Description      : This function is used to start min popup timer
** Invocation       : Invoked by the Popup Core Application
** Inputs/Outputs   : p_popup     - Popup Id of a min timer to start
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_start_popup_min_timer(POPUP_ID p_popup_id)
{
  /*Start the Minimum timeout timer only if popup id is less than max count*/
  if(p_popup_id< (POPUP_ID)L_POPUP_MAX_COUNT)
  {
    /* Do not start the timer if the timeout time is 0 */
    if(lc_popup_config_table[p_popup_id].min_timeout != 0U)
    {
      POPUP_LAYER_TYPE const * fl_layer;
      fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
      if(fl_layer!=NULL)
      {
       if((fl_layer->l_min_tmr_id)<POPUP_MAX_TIMER)
       {
        HMI_POPUP_START_TIMER(fl_layer->l_min_tmr_id, lc_popup_config_table[p_popup_id].min_timeout,
        (UINT16)((UINT16)((UINT16)HMI_TMR_MINIMUM_TIMEOUT_TYPE << 8U)| (UINT16)p_popup_id));
       }
      }
    }
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_start_all_popup_timer
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function Starts the relevant all popup Timers
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id - Popup ID
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_start_all_popup_timer(POPUP_ID p_popup_id)
{
  hmi_popup_core_start_popup_timer(p_popup_id);
  hmi_popup_core_start_popup_min_timer(p_popup_id);
}

/*============================================================================
** Function Name    : hmi_popup_core_stop_popup_timer
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function stops the relevant popup timers
** Invocation       : Invoked by the Popup Core

** Inputs/Outputs   : p_popup_id - Popup ID
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_stop_popup_timer(POPUP_ID p_popup_id)
{
  if(p_popup_id< (POPUP_ID)L_POPUP_MAX_COUNT)
  {
    TIMER_ID_TYPE temp_timer_id;

    temp_timer_id=(TIMER_ID_TYPE)lc_popup_config_table[p_popup_id].timerid;

    if(temp_timer_id<POPUP_MAX_TIMER)
    {
      HMI_POPUP_STOP_TIMER(temp_timer_id);
    }
  }
}
/*============================================================================
** Function Name    : hmi_popup_core_stop_popup_min_timer
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function stops the relevant popup timers
** Invocation       : Invoked by the Popup Core

** Inputs/Outputs   : p_popup_id - Popup ID
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_stop_popup_min_timer(POPUP_ID p_popup_id)
{
  if(p_popup_id< (POPUP_ID)L_POPUP_MAX_COUNT)
  {
    POPUP_LAYER_TYPE const * fl_layer;
    TIMER_ID_TYPE temp_min_timer_id;
    fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
    if(fl_layer!=NULL)
    {
     temp_min_timer_id=fl_layer->l_min_tmr_id;
     if(temp_min_timer_id<POPUP_MAX_TIMER)
     {
       HMI_POPUP_STOP_TIMER(temp_min_timer_id);
     }
	}
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_stop_all_popup_timer
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function stops the relevant popup timers
** Invocation       : Invoked by the Popup Core

** Inputs/Outputs   : p_popup_id - Popup ID
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_stop_all_popup_timer(POPUP_ID p_popup_id)
{
  if(p_popup_id< (POPUP_ID)L_POPUP_MAX_COUNT)
  {
    POPUP_LAYER_TYPE const * fl_layer;
    TIMER_ID_TYPE temp_timer_id;
    TIMER_ID_TYPE temp_min_timer_id;

    fl_layer = hmi_popup_core_get_popup_layer(p_popup_id);
    if(fl_layer!=NULL)
    {
     temp_timer_id=(TIMER_ID_TYPE)lc_popup_config_table[p_popup_id].timerid;
     temp_min_timer_id=fl_layer->l_min_tmr_id;


     if(temp_timer_id<POPUP_MAX_TIMER)
     {
       HMI_POPUP_STOP_TIMER(temp_timer_id);
     }

     if(temp_min_timer_id<POPUP_MAX_TIMER)
     {
       HMI_POPUP_STOP_TIMER(temp_min_timer_id);
     }
    }
  }
}
/*============================================================================
** Function Name    : hmi_popup_core_send_event_notification
** Visibility       : Local, Interface to the Popup Core
** Description      : Closure or event notification to popup application
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id, p_evt
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_send_event_notification(POPUP_ID p_popup_id, POPUP_EVENTS p_evt)
{ 
  if(p_popup_id < L_POPUP_MAX_COUNT)
  {
    if(POUP_CORE_HANDLER(p_popup_id)!=POPUP_EVENT_HANDLER_NULL)
    {
      POUP_CORE_HANDLER(p_popup_id)(p_evt);
    }
  }
}

/*============================================================================
** Function Name    : hmi_popup_core_add_to_queue
** Visibility       : Local, Interface to the Popup Core
** Description      : add the popup to respective group priority queue of a layer
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : Inputs p_popup_id,p_layer, p_group_priority
**                  : output: true or false to say whether added
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static BOOLEAN hmi_popup_core_add_to_queue(POPUP_ID p_popup_id, POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority)
{
  POPUP_ID_T fl_index;
  BOOLEAN fl_flag;
  fl_flag=FALSE;

  /* Check it is a valid popup and group priority of a layer*/
  if (((MAX_LAYER_POPUP_ID(p_layer)) > p_popup_id) && VALID_GROUP_PRIORITY((p_popup_id), (p_layer)))
  {
    UINT8 fl_group_priority = (UINT8)(p_group_priority - 1U);
    /* move the popup from end of the queue to top to create a space to add a popup */
    if (fl_group_priority < p_layer->l_total_grp_priority_count)
    {
      for (fl_index = (UINT8)((p_layer->l_group_priority_table_ptr[fl_group_priority]->queue_size) - ((UINT8)1)); fl_index > (UINT8)0; fl_index--)
      {
       	p_layer->l_group_priority_table_ptr[fl_group_priority]->queue[fl_index] = p_layer->l_group_priority_table_ptr[fl_group_priority]->queue[fl_index - ((UINT8)1)];
      }
      /* Add the popup to start of the array */
      p_layer->l_group_priority_table_ptr[fl_group_priority]->queue[fl_index] = (POPUP_ID_T)p_popup_id;
      fl_flag = TRUE;
	}
  }

  return(fl_flag);
}

/*============================================================================
** Function Name    : hmi_popup_core_remove_from_queue
** Visibility       : Local, Interface to the Popup Core
** Description      : remove the popup to respective group priority queue of a layer
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_popup_id,p_layer, p_group_priority
**                  : output: true or false to say whether removed
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static BOOLEAN hmi_popup_core_remove_from_queue(POPUP_ID p_popup_id, POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority)
{
  BOOLEAN fl_flag;
  fl_flag=FALSE;

  if ((POPUP_ID)L_POPUP_MAX_COUNT > p_popup_id)
  {
    POPUP_ID_T fl_index;
    POPUP_ID_T *temp_grp_pp_id_ptr;
    POPUP_ID_T temp_queue_size;
    UINT8 fl_group_priority=(UINT8)(p_group_priority-1U);
    if (fl_group_priority < p_layer->l_total_grp_priority_count)
    {
      temp_grp_pp_id_ptr = p_layer->l_group_priority_table_ptr[fl_group_priority]->queue;
      temp_queue_size = p_layer->l_group_priority_table_ptr[fl_group_priority]->queue_size;

      for(fl_index=0;((fl_index<(temp_queue_size-1U))\
                      &&(temp_grp_pp_id_ptr[fl_index]!=(POPUP_ID_T)L_POPUP_MAX_COUNT));fl_index++)
      {
        if ((temp_grp_pp_id_ptr[fl_index] == p_popup_id) || (fl_flag != FALSE))
        {
	        temp_grp_pp_id_ptr[fl_index] = temp_grp_pp_id_ptr[fl_index + 1U];
	        fl_flag = TRUE;
        }
      }

      if ((fl_flag != FALSE) || (temp_queue_size == 1U))
      {
        temp_grp_pp_id_ptr[temp_queue_size - 1U] = L_POPUP_MAX_COUNT;
        fl_flag = TRUE;
      }
    }
  }
  return(fl_flag);
}

/*============================================================================
** Function Name    : hmi_popup_core_get_lastin_pp_in_queue
** Visibility       : Local, Interface to the Popup Core
** Description      : get the popup from respective group priority queue of a layer
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_layer, p_group_priority
**                  : output: popup id 
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static POPUP_ID hmi_popup_core_get_lastin_pp_in_queue(POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority)
{
  POPUP_ID return_popup_id;
  UINT8 fl_group_priority = (UINT8)(p_group_priority-1U);
  return_popup_id = L_POPUP_MAX_COUNT;

  if(fl_group_priority < p_layer->l_total_grp_priority_count)
  {
    return_popup_id = (POPUP_ID)p_layer->l_group_priority_table_ptr[fl_group_priority]->queue[0];
  }
  return(return_popup_id);
}

/*============================================================================
** Function Name    : hmi_popup_core_search_remove_slfdeacti_pp_in_queue
** Visibility       : Local, Interface to the Popup Core
** Description      : get the popup from respective group priority queue of a layer
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_layer, p_group_priority
**                  : output: popup id 
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static POPUP_ID hmi_popup_core_search_self_deactivate_pp_in_queue(POPUP_LAYER_TYPE const *p_layer, UINT8 p_group_priority)
{
  UINT8 fl_index;
  POPUP_ID return_pp_id;
  POPUP_ID_T temp_self_deact_pp_id;
  UINT8 fl_group_priority = p_group_priority;

  return_pp_id=L_POPUP_MAX_COUNT;

  if(fl_group_priority<=(UINT8)LAST_GROUP_PRIORITY)
  {
    fl_group_priority=(UINT8)(fl_group_priority-1U);

    for(fl_index=0;fl_index<p_layer->l_group_priority_table_ptr[fl_group_priority]->queue_size;fl_index++)
    {
      temp_self_deact_pp_id=p_layer->l_group_priority_table_ptr[fl_group_priority]->queue[fl_index];
      if(temp_self_deact_pp_id!=L_POPUP_MAX_COUNT)
      {
        if(POPUP_SELF_DEACTIVTION(temp_self_deact_pp_id))
        {
          return_pp_id=(POPUP_ID)temp_self_deact_pp_id;
          break;
        }
      }
    }
  }
  return(return_pp_id);
}

/*============================================================================
** Function Name    : hmi_popup_core_get_activepp_and_count_of_all_layer
** Visibility       : Global, Interface to the Application
** Description      : function could be called to find an active and total
**                    pp active in all layer. Both will be L_POPUP_MAX_COUNT,
**                    if no popup is active.
** Invocation       : Invoked by the Application
** Inputs/Outputs   : POPUP_ACTIVE_DATA_TYPE - structure return active pp and total 
**                    count of layer
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static POPUP_ACTIVE_DATA_TYPE hmi_popup_core_find_active_popup_and_count(POPUP_ID p_start_index, POPUP_ID p_end_index)
{
  POPUP_ACTIVE_DATA_TYPE r_active;
  POPUP_ID_T fl_index;
  UINT8 fl_stop_U8 = (UINT8)0;
  r_active.total_popup_count  = (POPUP_ID)0;
  r_active.popup_id = (POPUP_ID)0;
  
  for (fl_index = p_start_index; 
    (fl_index < p_end_index); fl_index++)
  {
    if ((POPUP_ACTIVE((fl_index)))&&(!MIN_TIMER_DEACTIVATE_PENDING((fl_index))))
    {
      if(fl_stop_U8 ==0U)
      {
        r_active.popup_id = (POPUP_ID)fl_index;
        if (r_active.popup_id < L_POPUP_MAX_COUNT)
        {
          if (GROUP_PRIORITY(r_active.popup_id) != (UINT8)NO_GROUP_PRIORITY)
          {
            POPUP_LAYER_TYPE const *fl_layer;
            fl_layer = hmi_popup_core_get_popup_layer(r_active.popup_id);
            if (fl_layer != NULL)
            {
              r_active.popup_id = hmi_popup_core_get_lastin_pp_in_queue(fl_layer, GROUP_PRIORITY(r_active.popup_id));
            }
          }
        }
        fl_stop_U8 = (UINT8)1;
      }
      r_active.total_popup_count++;
    }
  }
  return(r_active);
}

#ifdef POPUP_TYPE_PROGRESSBAR
/*============================================================================
** Function Name    : hmi_popup_core_increment_progressbar_counter
** Visibility       : Global, Interface to the Application
** Description      : function to provide progress bar status
** Invocation       : Invoked by the timer call back
** Inputs/Outputs   : p_popup_id, r_progress_status of a popup.
**                    
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static BOOLEAN hmi_popup_core_increment_progressbar_counter(POPUP_ID p_popup_id)
{
  BOOLEAN r_progress_status;
  r_progress_status=FALSE;
  
  /* If no timeout progress bar pop up then counter value will be 255, so timer restarted when max count reached */
  if((!PROGRESSBAR_PP_CNTR_REACH_MAXCNT(p_popup_id)) || (PROGRESSBAR_PP_MAXCOUNT(p_popup_id) == HMI_PROGRESS_POPUP_NO_TIMEOUT_COUNT  ))
  {
    PROGRESSBAR_PP_INC_COUNT(p_popup_id);
    hmi_popup_core_send_event_notification(p_popup_id, POPUP_PROGRESS_BAR_INC_EVT);
    hmi_popup_core_start_popup_timer(p_popup_id);
    r_progress_status=TRUE;
  }
  return(r_progress_status);
}
#endif

#ifdef POPUP_TYPE_KEYPAD
/*============================================================================
** Function Name    : hmi_popup_keypad_btn_handler
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function returns the pointer to the Timer for a Popup
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : p_keypad     - pointer to a Key Pad Popup
**                    p_btn_id - Button ID
**                    p_pp_id - Popup ID
**                    Output: Status of the consumption of the button evt
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 20 JUN, 2013 NKRISHN9
**==========================================================================*/
static UINT8 hmi_popup_keypad_btn_handler(POPUP_KEYPADENTRY_TYPE  const *p_keypad, UINT16 p_btn_id, POPUP_ID p_popup_id)
{
	
  UINT8 fl_index_U8;
  KEYPAD_CONFIG_TYPE const * fl_config;
  HMI_CHAR *fl_char;
  KEYPAD_EVENT_TYPE const * fl_keypad_evt;
  UINT8 fl_return = LSH_STATUS_NONE;
  UINT8 fl_str_len = 0;
  BOOLEAN fl_status_BOOL = FALSE;
  UINT16 fl_timeout_U16 = 0;

  /* The Press and hold button alone needs to handle. Other button needs to ignore.
     if current multibutton status is inactive(released), the next button is press or hold
     Also, check that the new is button is not release button */
  if((LSH_GET_STATUS( *(p_keypad->l_curr_multi_press_btn))==LSH_BUTTON_INACTIVE_STATE)&&\
    (LSH_GET_STATUS(p_btn_id)!=LSH_BUTTON_INACTIVE_STATE))
  {
    fl_config = p_keypad->config_type;
    if (FALSE!=hmi_popup_core_search_button_event(p_keypad->l_ok_event, p_btn_id))
    {
      (void)hmi_popup_core_close_popup(p_popup_id, POPUP_CLOSED_ON_OK_EVT
                                        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                        ,POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_DEFAULT_POPUP_CLOSE_ANIM,p_popup_id)
                                        #endif
                                        );
      fl_return = LSH_STATUS_ABSORBED;
      p_btn_id=0;
    }
    else if(FALSE!=hmi_popup_core_search_button_event(p_keypad->l_delete_event, p_btn_id))
    {
      /* Remove the Last Character from the display and delete */
      fl_char = p_keypad->l_entry_ptr;

      while ((*fl_char != 0)&&((fl_str_len < (p_keypad->l_max_char_U8))))
      {
        fl_str_len++;  fl_char++;
      }

      if (fl_str_len > 0)
      {
        /* Clear only if the user has entered some values */
        fl_char--;  *fl_char = 0;
      }
      fl_return = LSH_STATUS_ABSORBED;
    }
    else if(FALSE!=hmi_popup_core_search_button_event(p_keypad->l_clear_event, p_btn_id))
    {
      /* Clear all the items in the entry */
      fl_char = p_keypad->l_entry_ptr;
      *fl_char = 0;
      fl_return = LSH_STATUS_ABSORBED;
    }
    else if(FALSE!=hmi_popup_core_search_button_event(p_keypad->l_cancel_event, p_btn_id))
    {
      /* Close the Popup with the cancel event notification to the application */
      (void)hmi_popup_core_close_popup(p_popup_id, POPUP_CLOSED_ON_CANCEL_EVT
                                        #ifdef LSH_ANIMATION_SUPPORT_ENABLED
                                        , POPUP_APP_DEFINED_ANIM_FUNCTION((UINT8)HMI_DEFAULT_POPUP_CLOSE_ANIM,p_popup_id)
                                        #endif
                                        );
      fl_return = LSH_STATUS_ABSORBED;
      p_btn_id=0;
    }
    else
    {
      /* Handle for other Button Press/hold */

      /* Search for the Button Press in the Key Pad Config Table */
      fl_keypad_evt = fl_config->l_keypad_evt_ptr;
      for (fl_index_U8 = 0; ((fl_index_U8 < fl_config->l_btn_count_U8)
      && (fl_return == LSH_STATUS_NONE)); fl_index_U8++)
      {
        if (fl_keypad_evt->l_btn_event_U16 == p_btn_id)
        {
          /* Button Found */

          /* Find the current entry length and pointer entry */
          fl_str_len = 0;   fl_char = p_keypad->l_entry_ptr;
          while ((*fl_char != 0) && (fl_str_len < p_keypad->l_max_char_U8))
          {
            fl_str_len++;   fl_char++;
          }

          /*  Check for the Multiple Press if configured. Multiple press is sensed 
              only if previous and current button are same. Otherwise, exit the multi press mode */
          if (p_keypad->pp_entry_type != NUMERIC_ENTRY)
          {
            if (LSH_GET_ID(*(p_keypad->l_curr_multi_press_btn)) != LSH_GET_ID(p_btn_id))
            {
              /* Previous & Current button pressed are not the same
               * Exit the Muti press mode */
              *(p_keypad->l_multi_press_counter) = 0;
            }
          }
          else
          {
            *(p_keypad->l_multi_press_counter) = 0;
            *(p_keypad->l_multi_timer_counter)=0;
          }

          if (p_keypad->pp_entry_type != NUMERIC_ENTRY)
          {
            if ((*(p_keypad->l_multi_press_counter) != 0))
            {
              /* This is the multiple button press,
              * remove the last item from the string */

              if (fl_str_len != 0)
              {
                fl_char = &p_keypad->l_entry_ptr[(fl_str_len - 1)];
                fl_str_len --;
              }
              *fl_char = 0;
            }
          }

          if (fl_str_len  < p_keypad->l_max_char_U8)
          {
            fl_char = &p_keypad->l_entry_ptr[fl_str_len];

            /* Increment the Counter */
            if (p_keypad->pp_entry_type != NUMERIC_ENTRY)
            {
              (*p_keypad->l_multi_press_counter)++;

              /************************************************************************************
              ** The value of fl_char is updated with reference to the multi press counter value.**
              ** When the same key is pressed the value of multi press counter is incremented by **
              ** ONE without checking the boundary condition for that button press. For example  **
              ** if ButtonID_1 is pressed continously the value should be 'a'->'b'->'c'->'2'and  **
              ** then back to 'a' again. But in our case we were incrementing the counter value  **
              ** without checking the boundary condition, due to which we were showing adjacent  **
              ** values like 'a'->'b'->'c'->'d'->'2'->'d'->'e'->.... To avoid this now we are    **
              ** checking for two boundary conditions, First one is whether multi press counter  **
              ** has reached MAX value, Second one is whether value stored in fl_char is 0. So   **
              ** once the above said boundary conditions is reached we would set the counter     **
              ** value to 1 and updated the fl_char value to first press in the char array table.**
              ************************************************************************************/

              if ((*p_keypad->l_multi_press_counter) > fl_keypad_evt->l_char_count_U8)
              {
                (*p_keypad->l_multi_press_counter) = 1;
              }

              *fl_char = fl_keypad_evt->l_char_array[(*p_keypad->l_multi_press_counter) - 1];
            }
            else
            {
              /* Numeric mode will always have only one item to append */
              (*p_keypad->l_multi_press_counter) = 0;
              *fl_char = fl_keypad_evt->l_char_array[(*p_keypad->l_multi_press_counter)];
            }

            fl_char++;
            *fl_char = 0;

            hmi_popup_core_start_popup_timer(p_popup_id);

            fl_return = LSH_STATUS_ABSORBED;

            /************************************************************************************
            ** Validation has to be performed only if the popup is of type NUMRIC_ENTRY. So    **
            ** modified the IF condition, at the same time multi press timer should be started **
            ** only for non NUMRIC_ENTRY type popup's, so moved that part of the code above.   **
            ************************************************************************************/
            if (NUMERIC_ENTRY == p_keypad->pp_entry_type)
            {
              /* Validate the Button Press, by the application Validation Handler */
              if (p_keypad->pp_validation_handler_ptr != POPUP_VALIDATE_HANDLER_NULL)
              {
                POPUP_KEYPAD_CONTENT_TYPE fl_keypad_content;
                fl_keypad_content.entry=p_keypad->l_entry_ptr;
                fl_keypad_content.popup_id=p_popup_id;
                fl_keypad_content.len_U8=p_keypad->l_max_char_U8;

                fl_status_BOOL = p_keypad->pp_validation_handler_ptr(&fl_keypad_content);

                if (FALSE == fl_status_BOOL)
                {
                    /* The validation has failed, do not close the popup immediately */
                    /* start a minimum timeout time and then close the popup   */
                    fl_timeout_U16 = lc_popup_config_table[p_popup_id].min_timeout;

                    /* Validation has failed, so block the button events so that
                    * the timeout timer will not be started in the RX button handler
                    * */
                    fl_return = POPUP_BTN_BLOCK;
                }
                else
                {
	                fl_timeout_U16 = lc_popup_config_table[p_popup_id].layer_timeout;
                }
              }
              /***************************************************************************
              ** The timeout value should be defined if the validation handler is NULL. **
              ** If the timeout value is not defined it would take the default value,   **
              ** which is 0, so the popup would timeout immediately. Hence set the      **
              ** timeout value to the timeout value of the popup.                       **
              ***************************************************************************/
              else
              {
                fl_timeout_U16 = lc_popup_config_table[p_popup_id].layer_timeout;
              }
            }
            else
            {
              fl_timeout_U16 = p_keypad->l_multi_press_timeout;
            }

            if ((lc_popup_config_table[p_popup_id].layer_timeout != 0)||(p_keypad->l_multi_press_timeout!=0))
            {
              HMI_POPUP_START_TIMER((TIMER_ID_TYPE)lc_popup_config_table[p_popup_id].timerid,fl_timeout_U16, ((UINT16)(HMI_TMR_TIME_OUT_TYPE << 8) | (UINT16)p_popup_id));
            }
          } /* Check for Max Char Length */
          else
          {
            /* Absorb the button. Make sure that timers are not started  */
            fl_return = POPUP_BTN_BLOCK;
          }
        } /* Check for valid Button Press */

        fl_keypad_evt++;
      }
    }
  }
  *(p_keypad->l_curr_multi_press_btn) = p_btn_id;;
  return (fl_return);
}

/*============================================================================
** Function Name    : hmi_popup_core_inc_keypadmultitimer_counter
** Visibility       : Local, Interface to the Popup Core
** Description      : This Function returns the status of keypad pp multi 
**                    pres inc status
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : 
**                    p_popup_id - Popup ID
**                    Output: Status of the  keypad pp multi timer inc status
** Critical Section : No
** Created          : 15 OCT, 2012 NKRISHN9
** Updated          : 15 OCT, 2012 NKRISHN9
**==========================================================================*/
static BOOLEAN hmi_popup_core_inc_keypadmultitimer_counter(POPUP_ID p_popup_id)
{
  BOOLEAN r_ret_status=FALSE;
  POPUP_KEYPADENTRY_TYPE  const *fl_keypad_pp;
  fl_keypad_pp= KEYPAD_PP_TBL_PTR(p_popup_id);

  /*if the layer timeout is zero, then the popup is not an time out one
    The time count will keep on increase  
    Layer timer x multipress 0 close the popup here. since, already layer time is complete 
    Layer timer 0 multipress x Popup should not close on timer expires 
    Layer timer 0 multipress 0 The popup timer is filtered at start timer itself */

  if(((KEYPAD_PP_MULTIPRESS_TIMEOUT(p_popup_id)==0)&&
     (lc_popup_config_table[p_popup_id].layer_timeout!=0))||
     (((*(fl_keypad_pp->l_multi_timer_counter))>=(KEYPAD_PP_MAXTIMECOUNT(p_popup_id)))&&
     (lc_popup_config_table[p_popup_id].layer_timeout!=0)))
  {
    r_ret_status=FALSE;
    *(fl_keypad_pp->l_multi_timer_counter)=0;
  }
  else
  {
    *(fl_keypad_pp->l_curr_multi_press_btn)=0;
    *(fl_keypad_pp->l_multi_press_counter)=0;
    (*(fl_keypad_pp->l_multi_timer_counter))++;
    hmi_popup_core_start_popup_timer(p_popup_id);
    r_ret_status=TRUE;
  }
  return(r_ret_status);
}
/*============================================================================
** Function Name    : hmi_popup_core_search_button_event
** Visibility       : Local, Interface to the Popup Core
** Description      : find if any popup btn event is matching
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : 
**                    PP_BTN_EVENT_TYPE - p_btn_ev_ptr, button event
**                    Output: true or false ( match found or not )
** Critical Section : No
** Created          : 12 MAR, 2013 NKRISHN9
** Updated          : 12 MAR, 2013 NKRISHN9
**==========================================================================*/
static BOOLEAN hmi_popup_core_search_button_event(PP_BTN_EVENT_TYPE const *p_btn_ev_ptr, UINT16 p_btn_event)
{
  UINT8 temp_btn_count;
  BOOLEAN return_status;

  temp_btn_count=p_btn_ev_ptr->l_btn_count_U8;
  return_status=FALSE;

  while(temp_btn_count>0)
  {
    if(p_btn_ev_ptr->l_btn_keypad_evt_U16[temp_btn_count-1]==p_btn_event)
    {
      return_status=TRUE;
    }
    temp_btn_count--;
  }
  return(return_status);
}
#endif

/*============================================================================
** Function Name    : hmi_popup_core_disable_timer_status
** Visibility       : Local, Interface to the Popup Core
** Description      : Disable the timer status
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : disable timer status
**                    
**                    
** Critical Section : No
** Created          : 12 MAR, 2013 NKRISHN9
** Updated          : 12 MAR, 2013 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_disable_timer_status(POPUP_ID_T p_popup_id)
{
  DISABLE_TIMER_STATUS((p_popup_id));
}
/*============================================================================
** Function Name    : hmi_popup_core_clear_min_deact_pndng
** Visibility       : Local, Interface to the Popup Core
** Description      : Deactivate min timer pending
** Invocation       : Invoked by the Popup Core
** Inputs/Outputs   : disable timer status
**                    
**                    
** Critical Section : No
** Created          : 12 MAR, 2013 NKRISHN9
** Updated          : 12 MAR, 2013 NKRISHN9
**==========================================================================*/
static void hmi_popup_core_clear_min_deact_pndng(POPUP_ID_T p_popup_id)
{
  CLEAR_MIN_TIMER_DEACTIVATE_PENDING((p_popup_id));
}


/*============================================================================
**
**============================================================================
** Core    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** Core Rev #                Date         By
** Core Rev X.X             dd-mon-yy     CDSID
**==========================================================================
** CMS Rev 1.32            28-Feb-18   arajase2
** 1065598: CMFB Coverity Warning
** Indentation corrected. No functional change
**
** CMS Rev 1.31            18-Jul-17   arajase2
** 905460: CMFB Coverity warning fix2
** New macro LSH_ANIM_MASK_CLEAR created to fix coverity warning when we use ~ operator
** ie. ~(LSH_ANIM_MASK) is replaced with its mask LSH_ANIM_MASK_CLEAR
**
** CMS Rev 1.30            19-May-17   aperumal
** 870786: Popup core compilation issue fix: P552
**
** CMS Rev 1.29            19-May-17   arajase2
** 870767: Popup core compilation issue fix.
**
** CMS Rev 1.28            03-Feb-17   adevi
** RTC 796460 - Hyundai DE issue - Popup when retriggered the timer is not running hence.
** popup not removed.
**
** CMS Rev 1.27            16-Dec-16   adevi
** RTC 766633 - Popup core group priority queue removal issue.
**
** CMS Rev 1.26            26-Aug-16   adevi
** RTC 681202 - CGEA Popup issue while same popup is retriggered when it gets timed out.
**
** CMS Rev 1.25            03-Jun-16   vgajji
** RTC 594029 - Coverity warning fix for TURING
**
** CMS Rev 1.24            10-Oct-15   aperumal
** RTC 441519 - Coverity warning fix for Hyundai AE
**
** CMS Rev 1.23            9-Jul-15   adevi
** RTC 374473 - QAC 8.1.2 fixes.  Ref program HONDA THAA
**==========================================================================
** CMS Rev 1.22            28-May-15   kkubendi
** PR Comments 81896 - Removed macro POPUP_APP_DEFINED_ANIM_FUNCTION_ENABLED
**==========================================================================
** CMS Rev 1.21            24-Mar-15   kkubendi
** RTC ID:302209 - Introduced macros POPUP_APP_DEFINED_ANIM_FUNCTION_ENABLED
** 				and POPUP_APP_DEFINED_ANIM_FUNCTION.
**==========================================================================
** CMS Rev 1.20            18-Feb-15   adevi
** RTC 291139 - The minimum timeout timer for a given popup was not getting 
** started when layer timeout is configured as 0.In hmi_popup_core_focus_handler
** IS_TIMER_STATUS_ENABLE check is done only for layer timeout.  Min timeout
** the is started without checking the timer status.  
**==========================================================================
** CMS Rev 1.19            6-Feb-15   arajase2
** Fixed QAC 8.1.2 Warnings.
** 
**===========================================================================

**==========================================================================
** CMS Rev 1.18            2-Feb-15   adevi
** Compilation error resolved in hmi_popup_core_activate function. 
**===========================================================================

**==========================================================================
** CMS Rev 1.17            15-Dec-14   adevi
** Few Compiler warnings resolved by adding check LSH_ANIMATION_SUPPORT_ENABLED.
**===========================================================================

**==========================================================================
** CMS Rev 1.16            01-Sep-14   adevi
** Few Compiler warnings resolved.
**===========================================================================

**==========================================================================
** CMS Rev 1.15            10-Apr-14   adevi
** Removed hmi_app_popup_focus_st_update_handler function invocation since
** this will be handled in view manager.  Progress bar timer restarted for 
** no time out progress type pop up.
**===========================================================================

**==========================================================================
** CMS Rev 1.14            08-Apr-14   adevi
** Line fl_return_U8 value assigned to zero removed.
** Above change done in hmi_popup_core_deactivate_popup function.
**===========================================================================

**==========================================================================
** CMS Rev 1.13            02-Apr-14   adevi
** Review comments for Bug ID 95 fixed. Ref PR Id 74658.
** hmi_popup_core_execute_presentation function removed.
**===========================================================================

**==========================================================================
** CMS Rev 1.12            02-Apr-14   adevi
** Bug ID 178 fixed. hmi_lsh_remap_button_events_ext invoked instead of
** hmi_lsh_remap_button_events function call.  Client Id is passed.
**===========================================================================

**==========================================================================
** CMS Rev 1.11            31-Mar-14   adevi
** Bug ID 164 review comments fixed.  PR Id 74821.  Layer ID alone passed in
** POPUP_LSH_ADD_STATE_EXT and POPUP_LSH_REM_STATE_EXT.
**===========================================================================

**==========================================================================
** CMS Rev 1.10            28-Mar-14   adevi
** Bug ID 164 fixed. Renamed LSH_ADD_STATE_EXT to POPUP_LSH_ADD_STATE_EXT.
** POPUP_LSH_ADD_STATE_EXT will be defined in dat file.  If application
** handler is configured then application handler will be invoked else
** LSH_ADD_STATE_EXT will be invoked.
**===========================================================================

**==========================================================================
** CMS Rev 1.9            25-Mar-14   adevi
** Bug ID 44 fixed. Removed l_prev_active_popup_id array.
** hmi_popup_core_presentation_handler modified to invoke presentation directly.
**===========================================================================

**==========================================================================
** CMS Rev 1.8            12-Mar-14   adevi
** Peer review comments of ID 74049 fixed. Replaced switch with if statements.
**===========================================================================

**===========================================================================
** CMS Rev 1.7            08-Jan-14   adevi
** Introduced three compiler switches POPUP_TYPE_KEYPAD, POPUP_TYPE_PROGRESSBAR
** and POPUP_TYPE_ACK to isolate the code based on the pop up types configured.
**===========================================================================

**===========================================================================
** CMS Rev 1.6            16-Oct-13    ksindhuj
** RTC 83857 focus status update interface added in 
** hmi_popup_core_focus_handler 
**==========================================================================

**===========================================================================
** CMS Rev 1.5    31-Jul-13    nkrishn9
   CR: close all popup support
       Anim mask handling in button commands
       Minimum timer expire event
**===========================================================================

**===========================================================================
** CMS Rev 1.4    26-Jun-13    nkrishn9
** DF: Peer review comments
       Unit testing defect
   CR: View manager interface changed to macro
       Animation id is independent of animation core
       Progress bar set interface
       LSH_ACTION is supported in rx_handler
**===========================================================================

**===========================================================================
** CMS Rev 1.3      12-Jun-13     VMUTHUSU
** IGDT Migration activities
** Remove
**  ==> hmi_animation01_core.h file inclusion
**===========================================================================

**===========================================================================
** CMS Rev 1.2      28-May-13    nkrishn9
** CR: Whenever progress bar count is increased, the popup core will send an
       event through the popup event handler with event as follows
       POPUP_PROGRESS_BAR_INC_EVT
       Unit testing defect fix
**===========================================================================

**===========================================================================
** CMS Rev 1.1      14-Mar-13    nkrishn9
** Support keypad events and qac fix
**===========================================================================

**===========================================================================
** CMS Rev 1.0      21-Dec-12    nkrishn9
** Support of all the popups like ack, keypad, progress and info
** along with audio requirements with group priority.
**===========================================================================

**===========================================================================
** CMS Rev initial      15-Jun-11    nkrishn9
** Initial version of popup core o2
**
**==========================================================================*/
/* end of file =============================================================*/

