/*
 * Stateflow code generation for chart:
 *    hmi_view_manager_02/hmi_view_manager_02
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 03-Sep-2015 18:05:29
 */

/* Include files */
#include "hmi_view_manager_02_autocode.h"
#include "hmi_view_manager_02.h"

/* Type Definitions */

/* Named Constants */
#define event_LSH_GFX_TICK_EV           (1U)
#define event_LSH_ANIM_COMPLETE_EV      (4U)
#define event_LSH_LOGIC_ADD_EV          (2U)
#define event_LSH_LOGIC_REMOVE_EV       (0U)
#define event_LSH_GFX_FORCE_PRESENTATION_EV (3U)
#define event_LSH_GFX_CHECK_DEACTIVATION_EV (5U)
#define IN_NO_ACTIVE_CHILD              (0)
#define IN_VM_LOGIC_ACTIVE_ST           (1)
#define IN_VM_LOGIC_INACTIVE_ST         (2)
#define IN_VM_GFX_ACTIVE_ST             (1)
#define IN_VM_GFX_NORMAL_RUN_ST         (1)
#define IN_VM_GFX_STARTUP_ANIM_ST       (2)
#define IN_VM_GFX_INACTIVE_ST           (3)
#define IN_VM_GFX_ACTIVE_PRESENT_ST     (2)
#define IN_VM_GFX_ACTIVE_ANIMATION_ST   (1)
#define IN_VM_GFX_CLOSE_ANIM_ST         (2)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void VM_LOGIC_ST(SFhmi_view_manager_02InstanceStruct *chartInstance);
static void VM_PRESENTATION_ST(SFhmi_view_manager_02InstanceStruct
 *chartInstance);
static void VM_GFX_ACTIVE_ST(SFhmi_view_manager_02InstanceStruct *chartInstance);
static void
enter_internal_VM_GFX_NORMAL_RUN_ST(SFhmi_view_manager_02InstanceStruct
 *chartInstance);

/* Function Definitions */
void initialize_hmi_view_manager_02(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  chartInstance->is_active_VM_LOGIC_ST = 0U;
  chartInstance->is_VM_LOGIC_ST = 0U;
  chartInstance->is_active_VM_PERIODIC_FOCUS_MONITOR_ST = 0U;
  chartInstance->is_active_VM_PRESENTATION_ST = 0U;
  chartInstance->is_VM_PRESENTATION_ST = 0U;
  chartInstance->is_VM_GFX_ACTIVE_ST = 0U;
  chartInstance->is_VM_GFX_NORMAL_RUN_ST = 0U;
  chartInstance->p_logic_req_state_id = MAX_uint16_T;
  chartInstance->p_logic_req_anim_id = MAX_uint8_T;
  chartInstance->l_logic_active_state_id = MAX_uint16_T;
  chartInstance->l_logic_active_anim_id = MAX_uint8_T;
  chartInstance->l_gfx_active_state_id = MAX_uint16_T;
  chartInstance->l_gfx_active_anim_id = MAX_uint8_T;
  chartInstance->l_gfx_deactivate_flag = 0U;
  chartInstance->l_gfx_deactivate_anim = MAX_uint8_T;
  chartInstance->l_gfx_prev_focus = 0U;
  chartInstance->l_gfx_presentation_state = 0U;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = CALL_EVENT;
  if(chartInstance->is_active_VM_LOGIC_ST != 1) {
    chartInstance->is_active_VM_LOGIC_ST = 1U;
    /* 
     ** Maintains the request from HMI logic
     */
  }
  chartInstance->is_VM_LOGIC_ST = (uint8_T)IN_VM_LOGIC_INACTIVE_ST;
  if(chartInstance->is_active_VM_PRESENTATION_ST != 1) {
    chartInstance->is_active_VM_PRESENTATION_ST = 1U;
    /* 
     ** Maintains the graphics state
     */
  }
  if(chartInstance->is_VM_PRESENTATION_ST != IN_VM_GFX_INACTIVE_ST) {
    chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_INACTIVE_ST;
    chartInstance->l_gfx_active_state_id = (uint16_T)LSH_ALL_VM_LOGIC_STATES;
    chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
  }
  chartInstance->is_active_VM_PERIODIC_FOCUS_MONITOR_ST = 1U;
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_view_manager_02(SFhmi_view_manager_02InstanceStruct *chartInstance)
{
  VM_LOGIC_ST(chartInstance);
  VM_PRESENTATION_ST(chartInstance);
  if((chartInstance->is_active_VM_PERIODIC_FOCUS_MONITOR_ST != 0) &&
   ((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) && (!(
      chartInstance->is_VM_PRESENTATION_ST == IN_VM_GFX_INACTIVE_ST)) &&
    (hmi_lsh_get_focus_status(LSH_GET_STATE_ID(chartInstance->
       l_gfx_active_state_id)) == LSH_FOCUS_STATUS_INACTIVE))) {
    hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
     chartInstance->l_gfx_prev_focus);
  }
}

static void VM_LOGIC_ST(SFhmi_view_manager_02InstanceStruct *chartInstance)
{
  boolean_T guard1 = false;
  if(chartInstance->is_active_VM_LOGIC_ST != 0) {
    guard1 = false;
    switch(chartInstance->is_VM_LOGIC_ST) {
     case IN_VM_LOGIC_ACTIVE_ST:
      if((_sfEvent_hmi_view_manager_02_ == event_LSH_LOGIC_REMOVE_EV) &&
       (chartInstance->p_logic_req_state_id == chartInstance->
        l_logic_active_state_id)) {
        if(chartInstance->p_logic_req_state_id ==
         chartInstance->l_gfx_active_state_id) {
          chartInstance->l_gfx_deactivate_flag = (uint8_T)TRUE;
          chartInstance->l_gfx_deactivate_anim =
            chartInstance->p_logic_req_anim_id;
          chartInstance->l_logic_active_state_id =
            (uint16_T)LSH_ALL_VM_LOGIC_STATES;
          chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          chartInstance->is_VM_LOGIC_ST = (uint8_T)IN_VM_LOGIC_INACTIVE_ST;
        } else {
          chartInstance->l_logic_active_state_id =
            (uint16_T)LSH_ALL_VM_LOGIC_STATES;
          chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          chartInstance->is_VM_LOGIC_ST = (uint8_T)IN_VM_LOGIC_INACTIVE_ST;
        }
      } else if((_sfEvent_hmi_view_manager_02_ == event_LSH_LOGIC_ADD_EV) &&
       (chartInstance->p_logic_req_state_id <
        LSH_ALL_VM_LOGIC_STATES)) {
        /*  New state is replacing current state  */
        if(chartInstance->l_logic_active_state_id !=
         chartInstance->p_logic_req_state_id) {
          if((chartInstance->p_logic_req_state_id ==
            chartInstance->l_gfx_active_state_id) &&
           (!(chartInstance->is_VM_PRESENTATION_ST ==
             IN_VM_GFX_CLOSE_ANIM_ST))) {
            chartInstance->l_gfx_deactivate_flag = (uint8_T)FALSE;
          } else {
            /* 
             ** active state is being presented by graphics so
             ** need to deactivate it
             */
            if(chartInstance->l_logic_active_state_id ==
             chartInstance->l_gfx_active_state_id) {
              chartInstance->l_gfx_deactivate_flag = (uint8_T)TRUE;
              chartInstance->l_gfx_deactivate_anim = (uint8_T)ANIM_MAX_ID;
            } else {
              /* 
               ** active state is not being presented yet by graphics
               ** so no deactivations required
               */
            }
          }
          guard1 = true;
        } else {
          /*  requested state is same as active state  */
          if(chartInstance->l_gfx_active_anim_id == ANIM_MAX_ID) {
#ifdef LSH_IGNORE_ANIM_REQUEST_DURING_ACTIVE_ANIM
            chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
#else
            chartInstance->l_logic_active_anim_id =
              chartInstance->p_logic_req_anim_id;
#endif
            if(chartInstance->l_logic_active_anim_id == ANIM_ABORT_ID) {
              chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
            }
          } else {
            /*  req state prev anim actively running  */
            guard1 = true;
          }
        }
      }
      break;
     case IN_VM_LOGIC_INACTIVE_ST:
      if((_sfEvent_hmi_view_manager_02_ == event_LSH_LOGIC_ADD_EV) &&
       (chartInstance->p_logic_req_state_id < LSH_ALL_VM_LOGIC_STATES)) {
        chartInstance->is_VM_LOGIC_ST = (uint8_T)IN_VM_LOGIC_ACTIVE_ST;
        chartInstance->l_logic_active_state_id =
          chartInstance->p_logic_req_state_id;
        chartInstance->l_logic_active_anim_id =
          chartInstance->p_logic_req_anim_id;
      } else if((_sfEvent_hmi_view_manager_02_ == event_LSH_LOGIC_REMOVE_EV) &&
       (chartInstance->p_logic_req_state_id == chartInstance->
        l_gfx_active_state_id)) {
        if(!(chartInstance->is_VM_PRESENTATION_ST == IN_VM_GFX_CLOSE_ANIM_ST)) {
          chartInstance->l_gfx_deactivate_anim =
            chartInstance->p_logic_req_anim_id;
        } else if(chartInstance->p_logic_req_anim_id == ANIM_ABORT_ID) {
          chartInstance->l_gfx_deactivate_anim =
            chartInstance->p_logic_req_anim_id;
        } else {
          /*  Do Nothing
             QAC 8.1.2 Fix */
        }
      }
      break;
     default:
      chartInstance->is_VM_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
    }
    if(guard1 == true) {
      chartInstance->l_logic_active_state_id =
        chartInstance->p_logic_req_state_id;
      chartInstance->l_logic_active_anim_id = chartInstance->p_logic_req_anim_id;
    }
  }
}

static void VM_PRESENTATION_ST(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  boolean_T guard1 = false;
  if(chartInstance->is_active_VM_PRESENTATION_ST != 0) {
    guard1 = false;
    switch(chartInstance->is_VM_PRESENTATION_ST) {
     case IN_VM_GFX_ACTIVE_ST:
      VM_GFX_ACTIVE_ST(chartInstance);
      break;
     case IN_VM_GFX_CLOSE_ANIM_ST:
      if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
       (chartInstance->l_gfx_deactivate_anim == ANIM_ABORT_ID)) {
        hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_active_anim_id);
        chartInstance->l_gfx_deactivate_anim = (uint8_T)ANIM_MAX_ID;
        guard1 = true;
      } else {
        /*  animation completed and no state active  */
        if(_sfEvent_hmi_view_manager_02_ == event_LSH_ANIM_COMPLETE_EV) {
          guard1 = true;
        }
      }
      break;
     case IN_VM_GFX_INACTIVE_ST:
      /*  Check if we have got a new logic state  */
      if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
       (chartInstance->l_logic_active_state_id < LSH_ALL_VM_LOGIC_STATES)) {
        chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_ACTIVE_ST;
        chartInstance->l_gfx_prev_focus = 0U;
        chartInstance->l_gfx_deactivate_flag = (uint8_T)FALSE;
        hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_active_anim_id);
        chartInstance->l_gfx_active_state_id =
          chartInstance->l_logic_active_state_id;
        chartInstance->l_gfx_active_anim_id =
          chartInstance->l_logic_active_anim_id;
        chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
        chartInstance->l_gfx_presentation_state = (uint8_T)LSH_ACTIVATED_STATUS;
        /*  no animations  */
        if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
          chartInstance->l_gfx_active_anim_id) == FALSE) {
          chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
          enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
        } else if(chartInstance->is_VM_GFX_ACTIVE_ST !=
         IN_VM_GFX_STARTUP_ANIM_ST) {
          chartInstance->is_VM_GFX_ACTIVE_ST =
            (uint8_T)IN_VM_GFX_STARTUP_ANIM_ST;
          hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
           (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
            LSH_ANIM_STARTED_STATUS));
        }
      }
      break;
     default:
      chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
    }
    if(guard1 == true) {
      hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
       LSH_DEACTIVATED_STATUS);
      hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
       (uint8_T)((int32_T)LSH_LOST_FOCUS_STATUS | (int32_T)
        LSH_DEACTIVATED_STATUS | (int32_T)LSH_ANIM_COMPLETE_STATUS));
      if(chartInstance->l_gfx_active_state_id !=
       chartInstance->l_logic_active_state_id) {
        hmi_lsh_freeze_button_events_ext(LSH_GET_STATE_ID(chartInstance->l_gfx_active_state_id),
         LSH_GET_CLIENT_ID(chartInstance->
          l_gfx_active_state_id));
      }
      /* 
         if we come here via l_gfx_deactivate_flag != FALSE path
         then check to see if there is an active state beccause
         focus handler can add/remove states  */
      if(chartInstance->l_logic_active_state_id < LSH_ALL_VM_LOGIC_STATES) {
        chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_ACTIVE_ST;
        chartInstance->l_gfx_prev_focus = 0U;
        chartInstance->l_gfx_deactivate_flag = (uint8_T)FALSE;
        hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_active_anim_id);
        chartInstance->l_gfx_active_state_id =
          chartInstance->l_logic_active_state_id;
        chartInstance->l_gfx_active_anim_id =
          chartInstance->l_logic_active_anim_id;
        chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
        chartInstance->l_gfx_presentation_state = (uint8_T)LSH_ACTIVATED_STATUS;
        /*  no animations  */
        if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
          chartInstance->l_gfx_active_anim_id) == FALSE) {
          chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
          enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
        } else if(chartInstance->is_VM_GFX_ACTIVE_ST !=
         IN_VM_GFX_STARTUP_ANIM_ST) {
          chartInstance->is_VM_GFX_ACTIVE_ST =
            (uint8_T)IN_VM_GFX_STARTUP_ANIM_ST;
          hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
           (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
            LSH_ANIM_STARTED_STATUS));
        }
      } else {
        chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_INACTIVE_ST;
        chartInstance->l_gfx_active_state_id = (uint16_T)LSH_ALL_VM_LOGIC_STATES;
        chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
      }
    }
  }
}

static void VM_GFX_ACTIVE_ST(SFhmi_view_manager_02InstanceStruct *chartInstance)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  if(chartInstance->is_VM_PRESENTATION_ST == IN_VM_GFX_ACTIVE_ST) {
    /* 
     ** If the logic state has gone inactive or if the deactivation flag is set
     ** then perform a deactivation. Perform the animation if requested
     */
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if(((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) ||
      (_sfEvent_hmi_view_manager_02_ ==
       event_LSH_GFX_CHECK_DEACTIVATION_EV) || (_sfEvent_hmi_view_manager_02_ ==
       event_LSH_ANIM_COMPLETE_EV)) && ((chartInstance->
       l_logic_active_state_id == LSH_ALL_VM_LOGIC_STATES) ||
      (chartInstance->l_gfx_deactivate_flag != FALSE))) {
      hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
       chartInstance->l_gfx_active_anim_id);
      if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
        chartInstance->l_gfx_deactivate_anim) != FALSE) {
        chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_CLOSE_ANIM_ST;
        chartInstance->l_gfx_active_anim_id =
          chartInstance->l_gfx_deactivate_anim;
        chartInstance->l_gfx_deactivate_anim = (uint8_T)ANIM_MAX_ID;
      } else {
        /*  Animation not started  */
        hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
         LSH_DEACTIVATED_STATUS);
        hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
         (uint8_T)((int32_T)LSH_LOST_FOCUS_STATUS | (int32_T)
          LSH_DEACTIVATED_STATUS | (int32_T)LSH_ANIM_COMPLETE_STATUS));
        if(chartInstance->l_gfx_active_state_id !=
         chartInstance->l_logic_active_state_id) {
          hmi_lsh_freeze_button_events_ext(LSH_GET_STATE_ID(chartInstance->l_gfx_active_state_id),
           LSH_GET_CLIENT_ID(chartInstance->
            l_gfx_active_state_id));
        }
        /* 
           if we come here via l_gfx_deactivate_flag != FALSE path
           then check to see if there is an active state beccause
           focus handler can add/remove states  */
        if(chartInstance->l_logic_active_state_id < LSH_ALL_VM_LOGIC_STATES) {
          chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          if(chartInstance->is_VM_PRESENTATION_ST != IN_VM_GFX_ACTIVE_ST) {
            chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_ACTIVE_ST;
            chartInstance->l_gfx_prev_focus = 0U;
            chartInstance->l_gfx_deactivate_flag = (uint8_T)FALSE;
          }
          hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
           chartInstance->l_gfx_active_anim_id);
          chartInstance->l_gfx_active_state_id =
            chartInstance->l_logic_active_state_id;
          chartInstance->l_gfx_active_anim_id =
            chartInstance->l_logic_active_anim_id;
          chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          chartInstance->l_gfx_presentation_state =
            (uint8_T)LSH_ACTIVATED_STATUS;
          /*  no animations  */
          if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
            chartInstance->l_gfx_active_anim_id) == FALSE) {
            chartInstance->is_VM_GFX_ACTIVE_ST =
              (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
            enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
          } else if(chartInstance->is_VM_GFX_ACTIVE_ST !=
           IN_VM_GFX_STARTUP_ANIM_ST) {
            chartInstance->is_VM_GFX_ACTIVE_ST =
              (uint8_T)IN_VM_GFX_STARTUP_ANIM_ST;
            hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
             (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
              LSH_ANIM_STARTED_STATUS));
          }
        } else {
          chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          chartInstance->is_VM_PRESENTATION_ST = (uint8_T)IN_VM_GFX_INACTIVE_ST;
          chartInstance->l_gfx_active_state_id =
            (uint16_T)LSH_ALL_VM_LOGIC_STATES;
          chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
        }
      }
    } else if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
     (chartInstance->l_gfx_active_state_id != chartInstance->
      l_logic_active_state_id)) {
      chartInstance->l_gfx_prev_focus = 0U;
      hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
       LSH_DEACTIVATED_STATUS);
      hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
       (uint8_T)((int32_T)LSH_LOST_FOCUS_STATUS | (int32_T)
        LSH_DEACTIVATED_STATUS | (int32_T)LSH_ANIM_COMPLETE_STATUS));
      hmi_lsh_freeze_button_events_ext(LSH_GET_STATE_ID(chartInstance->l_gfx_active_state_id),
       LSH_GET_CLIENT_ID(chartInstance->
        l_gfx_active_state_id));
      /* 
         Force a reentry if the logic state is different than
         the current graphics state
         This path is never expected to execute
       */
      hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
       chartInstance->l_gfx_active_anim_id);
      chartInstance->l_gfx_active_state_id =
        chartInstance->l_logic_active_state_id;
      chartInstance->l_gfx_active_anim_id =
        chartInstance->l_logic_active_anim_id;
      chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
      chartInstance->l_gfx_presentation_state = (uint8_T)LSH_ACTIVATED_STATUS;
      /*  no animations  */
      if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
        chartInstance->l_gfx_active_anim_id) == FALSE) {
        chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
        enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
      } else {
        chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_VM_GFX_STARTUP_ANIM_ST;
        hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
         (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
          LSH_ANIM_STARTED_STATUS));
      }
    } else {
      switch(chartInstance->is_VM_GFX_ACTIVE_ST) {
       case IN_VM_GFX_NORMAL_RUN_ST:
        if(chartInstance->is_VM_GFX_ACTIVE_ST == IN_VM_GFX_NORMAL_RUN_ST) 
		{
#if (ANIM_MAX_ID > 0)			
          if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
           (chartInstance->l_logic_active_anim_id < ANIM_MAX_ID)) {
            /*  if logic active state is different, it will exit
               in parent state   */
            hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
             chartInstance->l_gfx_active_anim_id);
            chartInstance->l_gfx_active_anim_id =
              chartInstance->l_logic_active_anim_id;
            chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
            /* 
             ** !!!!! This transition needs to be avaluated first always
             ** So if for any chance if you rearrange the states
             ** please make sure the order is maintained
             */
            if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
              chartInstance->l_gfx_active_anim_id) != FALSE) {
              chartInstance->is_VM_GFX_NORMAL_RUN_ST =
                (uint8_T)IN_VM_GFX_ACTIVE_ANIMATION_ST;
              hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
               (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
                LSH_ANIM_STARTED_STATUS));
            } else if(!(chartInstance->is_VM_GFX_NORMAL_RUN_ST ==
              IN_VM_GFX_ACTIVE_PRESENT_ST)) {
              chartInstance->is_VM_GFX_NORMAL_RUN_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              if(chartInstance->is_VM_GFX_NORMAL_RUN_ST !=
               IN_VM_GFX_ACTIVE_PRESENT_ST) {
                chartInstance->is_VM_GFX_NORMAL_RUN_ST =
                  (uint8_T)IN_VM_GFX_ACTIVE_PRESENT_ST;
                chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
                /* Added during Abort anim implementation  */
                hmi_vm_focus(chartInstance,
                 chartInstance->l_gfx_active_state_id,
                 (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
                  LSH_ANIM_COMPLETE_STATUS));
                hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
                 chartInstance->l_gfx_presentation_state);
                chartInstance->l_gfx_presentation_state =
                  (uint8_T)LSH_REFRESH_STATUS;
                /* Added during Abort anim implementation  */
                chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
              }
            } else {
              guard3 = true;
            }
          } 
		  else 
#endif
		  {
            guard3 = true;
          }
        }
        break;
       case IN_VM_GFX_STARTUP_ANIM_ST:
        if(chartInstance->is_VM_GFX_ACTIVE_ST == IN_VM_GFX_STARTUP_ANIM_ST) {
          if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
           ((chartInstance->l_logic_active_anim_id == ANIM_ABORT_ID) && (
             chartInstance->l_gfx_active_state_id ==
             chartInstance->l_logic_active_state_id))) {
            hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
             chartInstance->l_gfx_active_anim_id);
            chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
            chartInstance->is_VM_GFX_ACTIVE_ST =
              (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
            enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
          } else if(_sfEvent_hmi_view_manager_02_ == event_LSH_ANIM_COMPLETE_EV)
          {
            chartInstance->is_VM_GFX_ACTIVE_ST =
              (uint8_T)IN_VM_GFX_NORMAL_RUN_ST;
            enter_internal_VM_GFX_NORMAL_RUN_ST(chartInstance);
          } else if(_sfEvent_hmi_view_manager_02_ ==
           event_LSH_GFX_FORCE_PRESENTATION_EV) {
            hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
             chartInstance->l_gfx_presentation_state);
            chartInstance->l_gfx_presentation_state =
              (uint8_T)LSH_REFRESH_STATUS;
          }
        }
        break;
       default:
        chartInstance->is_VM_GFX_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    if(guard3 == true) {
      switch(chartInstance->is_VM_GFX_NORMAL_RUN_ST) {
       case IN_VM_GFX_ACTIVE_ANIMATION_ST:
        if(_sfEvent_hmi_view_manager_02_ == event_LSH_ANIM_COMPLETE_EV) {
          hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
           chartInstance->l_gfx_active_anim_id);
          chartInstance->l_gfx_active_anim_id =
            chartInstance->l_logic_active_anim_id;
          chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          /* 
           ** !!!!! This transition needs to be avaluated first always
           ** So if for any chance if you rearrange the states
           ** please make sure the order is maintained
           */
          if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
            chartInstance->l_gfx_active_anim_id) != FALSE) {
            chartInstance->is_VM_GFX_NORMAL_RUN_ST =
              (uint8_T)IN_VM_GFX_ACTIVE_ANIMATION_ST;
            hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
             (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
              LSH_ANIM_STARTED_STATUS));
          } else if(!(chartInstance->is_VM_GFX_NORMAL_RUN_ST ==
            IN_VM_GFX_ACTIVE_PRESENT_ST)) {
            chartInstance->is_VM_GFX_NORMAL_RUN_ST =
              (uint8_T)IN_VM_GFX_ACTIVE_PRESENT_ST;
            chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
            /* Added during Abort anim implementation  */
            hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
             (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
              LSH_ANIM_COMPLETE_STATUS));
            hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
             chartInstance->l_gfx_presentation_state);
            chartInstance->l_gfx_presentation_state =
              (uint8_T)LSH_REFRESH_STATUS;
            /* Added during Abort anim implementation  */
            chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        break;
       case IN_VM_GFX_ACTIVE_PRESENT_ST:
        /*  call refresh every alternate cycles  */
        if(_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) {
          hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
           LSH_REFRESH_STATUS);
          if(chartInstance->l_logic_active_anim_id == ANIM_ABORT_ID) {
            chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          }
        }
        break;
       default:
        chartInstance->is_VM_GFX_NORMAL_RUN_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    if(guard2 == true) {
      if((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) &&
       ((chartInstance->l_logic_active_anim_id == ANIM_ABORT_ID) && (
         chartInstance->l_gfx_active_state_id ==
         chartInstance->l_logic_active_state_id))) {
        hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_active_anim_id);
        chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
        if(!(chartInstance->is_VM_GFX_NORMAL_RUN_ST ==
          IN_VM_GFX_ACTIVE_PRESENT_ST)) {
          chartInstance->is_VM_GFX_NORMAL_RUN_ST =
            (uint8_T)IN_VM_GFX_ACTIVE_PRESENT_ST;
          chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
          /* Added during Abort anim implementation  */
          hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
           (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
            LSH_ANIM_COMPLETE_STATUS));
          hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
           chartInstance->l_gfx_presentation_state);
          chartInstance->l_gfx_presentation_state = (uint8_T)LSH_REFRESH_STATUS;
          /* Added during Abort anim implementation  */
          chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if(guard1 == true) {
      if(_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_FORCE_PRESENTATION_EV) {
        hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_presentation_state);
        chartInstance->l_gfx_presentation_state = (uint8_T)LSH_REFRESH_STATUS;
      }
    }
  }
}

static void
enter_internal_VM_GFX_NORMAL_RUN_ST(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  boolean_T guard1 = false;
  guard1 = false;
#if (ANIM_MAX_ID > 0)
  if(chartInstance->l_logic_active_anim_id < ANIM_MAX_ID) {
    hmi_lsh_stop_animation(chartInstance->l_gfx_active_state_id,
     chartInstance->l_gfx_active_anim_id);
    chartInstance->l_gfx_active_anim_id = chartInstance->l_logic_active_anim_id;
    chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
    /* 
     ** !!!!! This transition needs to be avaluated first always
     ** So if for any chance if you rearrange the states
     ** please make sure the order is maintained
     */
    if(hmi_lsh_start_animation(chartInstance->l_gfx_active_state_id,
      chartInstance->l_gfx_active_anim_id) != FALSE) {
      if(chartInstance->is_VM_GFX_NORMAL_RUN_ST !=
       IN_VM_GFX_ACTIVE_ANIMATION_ST) {
        chartInstance->is_VM_GFX_NORMAL_RUN_ST =
          (uint8_T)IN_VM_GFX_ACTIVE_ANIMATION_ST;
        hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
         (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
          LSH_ANIM_STARTED_STATUS));
      }
    } else if(!(chartInstance->is_VM_GFX_NORMAL_RUN_ST ==
      IN_VM_GFX_ACTIVE_PRESENT_ST)) {
      if(chartInstance->is_VM_GFX_NORMAL_RUN_ST != IN_VM_GFX_ACTIVE_PRESENT_ST) {
        chartInstance->is_VM_GFX_NORMAL_RUN_ST =
          (uint8_T)IN_VM_GFX_ACTIVE_PRESENT_ST;
        chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
        /* Added during Abort anim implementation  */
        hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
         (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
          LSH_ANIM_COMPLETE_STATUS));
        hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
         chartInstance->l_gfx_presentation_state);
        chartInstance->l_gfx_presentation_state = (uint8_T)LSH_REFRESH_STATUS;
        /* Added during Abort anim implementation  */
        chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
      }
    } else {
      guard1 = true;
    }
  }
  else
#endif
  {
    guard1 = true;
  }
  if(guard1 == true) {
    if(chartInstance->is_VM_GFX_NORMAL_RUN_ST != IN_VM_GFX_ACTIVE_PRESENT_ST) {
      chartInstance->is_VM_GFX_NORMAL_RUN_ST =
        (uint8_T)IN_VM_GFX_ACTIVE_PRESENT_ST;
      chartInstance->l_logic_active_anim_id = (uint8_T)ANIM_MAX_ID;
      /* Added during Abort anim implementation  */
      hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
       (uint8_T)((int32_T)LSH_GOT_FOCUS_STATUS | (int32_T)
        LSH_ANIM_COMPLETE_STATUS));
      hmi_lsh_run_presentation(chartInstance->l_gfx_active_state_id,
       chartInstance->l_gfx_presentation_state);
      chartInstance->l_gfx_presentation_state = (uint8_T)LSH_REFRESH_STATUS;
      /* Added during Abort anim implementation  */
      chartInstance->l_gfx_active_anim_id = (uint8_T)ANIM_MAX_ID;
    }
  }
}

void hmi_vm_focus(SFhmi_view_manager_02InstanceStruct *chartInstance, uint16_T
 p_state_id, uint8_T p_focus)
{
  hmi_lsh_focus_handler(p_state_id, p_focus);
  chartInstance->l_gfx_prev_focus = p_focus;
}

void hmi_vm_tick(SFhmi_view_manager_02InstanceStruct *chartInstance)
{
  uint8_T b_previousEvent;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_GFX_TICK_EV;
  VM_PRESENTATION_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_GFX_TICK_EV;
  if((chartInstance->is_active_VM_PERIODIC_FOCUS_MONITOR_ST != 0) &&
   ((_sfEvent_hmi_view_manager_02_ == event_LSH_GFX_TICK_EV) && (!(
      chartInstance->is_VM_PRESENTATION_ST == IN_VM_GFX_INACTIVE_ST)) &&
    (hmi_lsh_get_focus_status(LSH_GET_STATE_ID(chartInstance->
       l_gfx_active_state_id)) == LSH_FOCUS_STATUS_INACTIVE))) {
    hmi_vm_focus(chartInstance, chartInstance->l_gfx_active_state_id,
     chartInstance->l_gfx_prev_focus);
  }
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_vm_check_deactivation(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_GFX_CHECK_DEACTIVATION_EV;
  VM_PRESENTATION_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_vm_animation_completed(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_ANIM_COMPLETE_EV;
  VM_PRESENTATION_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_vm_force_presentation(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_GFX_FORCE_PRESENTATION_EV;
  VM_PRESENTATION_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_vm_add_state(SFhmi_view_manager_02InstanceStruct *chartInstance,
 uint16_T p_state_id, uint8_T p_anim_id)
{
  uint8_T b_previousEvent;
  chartInstance->p_logic_req_state_id = p_state_id;
  chartInstance->p_logic_req_anim_id = p_anim_id;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_LOGIC_ADD_EV;
  VM_LOGIC_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

void hmi_vm_remove_state(SFhmi_view_manager_02InstanceStruct *chartInstance,
 uint16_T p_state_id, uint8_T p_anim_id)
{
  uint8_T b_previousEvent;
  chartInstance->p_logic_req_state_id = p_state_id;
  chartInstance->p_logic_req_anim_id = p_anim_id;
  b_previousEvent = _sfEvent_hmi_view_manager_02_;
  _sfEvent_hmi_view_manager_02_ = event_LSH_LOGIC_REMOVE_EV;
  VM_LOGIC_ST(chartInstance);
  _sfEvent_hmi_view_manager_02_ = b_previousEvent;
}

boolean_T hmi_vm_animation_active_status(SFhmi_view_manager_02InstanceStruct
 *chartInstance)
{
  if((chartInstance->is_VM_GFX_ACTIVE_ST == IN_VM_GFX_STARTUP_ANIM_ST) ||
   (chartInstance->is_VM_GFX_NORMAL_RUN_ST ==
    IN_VM_GFX_ACTIVE_ANIMATION_ST) || (chartInstance->is_VM_PRESENTATION_ST ==
    IN_VM_GFX_CLOSE_ANIM_ST)) {
    return (boolean_T)TRUE != 0;
  } else {
    return (boolean_T)FALSE != 0;
  }
}

