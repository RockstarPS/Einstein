/*
 * Stateflow code generation for chart:
 *    hmi_menu_core_01_model/hmi_menu_core_01_chart
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 12-Oct-2015 12:40:30
 */

/* Include files */
#include "hmi_menu_core_01_model_autocode.h"
#include "hmi_menu_core_01_chart.h"

/* Type Definitions */

/* Named Constants */
#define event_HMI_MENU_OPEN_EV          (8U)
#define event_HMI_MENU_CLOSE_EV         (5U)
#define event_HMI_MENU_DATA_AVAIL_EV    (7U)
#define event_HMI_MENU_ANIM_EXIT_EV     (0U)
#define event_HMI_MENU_BTN_ACTIONS_EV   (6U)
#define event_HMI_MENU_BTN_MC_RELEASE_EV (15U)
#define event_HMI_MENU_FS_BTN_EV        (12U)
#define event_HMI_MENU_FS_BTN_REL_EV    (2U)
#define event_HMI_MENU_FS_REPEAT_TIMEOUT_EV (1U)
#define event_HMI_MENU_WAIT_TEMP_TIMEOUT_EV (11U)
#define event_HMI_MENU_FS_REPEAT_TIMER_EV (9U)
#define event_HMI_MENU_FS_INACTIVE_EV   (13U)
#define event_HMI_MENU_REBUILD_EV       (3U)
#define event_HMI_MENU_ANIM_STARTED_EV  (10U)
#define event_HMI_MENU_WAIT_ANIM_EXIT_EV (4U)
#define IN_NO_ACTIVE_CHILD              (0)
#define IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST (2)
#define IN_HMI_MENU_ANIM_INACTIVE_ST    (2)
#define IN_HMI_MENU_WAIT_FOR_ANIM_EXIT  (2)
#define IN_HMI_MENU_FAST_SCROLL_LIST_END_ST (3)
#define IN_HMI_MENU_WAIT_ANIM_RUNNING_ST (1)
#define IN_HMI_MENU_ANIM_ACTIVE_ST      (1)
#define IN_HMI_MENU_INACTIVE_ST         (2)
#define IN_HMI_MENU_ACTIVE_ST           (1)
#define IN_HMI_MENU_SCROLL_ST           (3)
#define IN_HMI_MENU_WAIT_ST             (4)
#define IN_HMI_MENU_WAIT_TEMP_TMR_ST    (2)
#define IN_HMI_MENU_WAIT_ACTIVE_ST      (1)
#define IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST (1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void HMI_MENU_LOGIC_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
static void
exit_internal_HMI_MENU_LOGIC_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
static void HMI_MENU_WAIT_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
static void HMI_MENU_ANIM_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);

/* Function Definitions */
void initialize_hmi_menu_core_01_chart(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  uint8_T c_previousEvent;
  chartInstance->is_active_HMI_MENU_ANIM_ST = 0U;
  chartInstance->is_HMI_MENU_ANIM_ST = 0U;
  chartInstance->is_active_HMI_MENU_FAST_SCROLL_ST = 0U;
  chartInstance->is_HMI_MENU_FAST_SCROLL_ST = 0U;
  chartInstance->is_active_HMI_MENU_LOGIC_ST = 0U;
  chartInstance->is_HMI_MENU_LOGIC_ST = 0U;
  chartInstance->is_HMI_MENU_WAIT_ST = 0U;
  chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST = 0U;
  chartInstance->l_menu_action_U8 = 0U;
  chartInstance->l_menu_action_output_U16 = 0U;
  chartInstance->l_get_btn_result_U8 = 0U;
  chartInstance->l_btn_cmd_U16 = 0U;
  chartInstance->l_menu_id_U8 = 0U;
  chartInstance->l_btn_rel_in_fast_scroll = 0U;
  chartInstance->l_menu_state = 0U;
  chartInstance->l_repeat_count = 0U;
  chartInstance->l_btn_status_BOOL = 0U;
  chartInstance->fast_scroll_active = 0U;
  chartInstance->fast_scroll_active_rel = 0U;
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = CALL_EVENT;
  /* Entry: hmi_menu_core_01_chart */
  /* Entry: HMI_MENU_LOGIC_ST */
  if(chartInstance->is_active_HMI_MENU_LOGIC_ST != 1) {
    chartInstance->is_active_HMI_MENU_LOGIC_ST = 1U;
    chartInstance->l_menu_action_output_U16 = 0U;
    chartInstance->l_menu_action_U8 = 0U;
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
    chartInstance->l_repeat_count = 0U;
    chartInstance->l_btn_cmd_U16 = 0U;
    chartInstance->l_btn_rel_in_fast_scroll = 0U;
    chartInstance->l_btn_status_BOOL = 0U;
#endif
  }
  /* Entry: HMI_MENU_INACTIVE_ST */
  chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_INACTIVE_ST;
  /* Entry: HMI_MENU_ANIM_ST */
  chartInstance->is_active_HMI_MENU_ANIM_ST = 1U;
  /* Entry: HMI_MENU_ANIM_INACTIVE_ST */
  if(chartInstance->is_HMI_MENU_ANIM_ST != IN_HMI_MENU_ANIM_INACTIVE_ST) {
    chartInstance->is_HMI_MENU_ANIM_ST = (uint8_T)IN_HMI_MENU_ANIM_INACTIVE_ST;
    c_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_WAIT_ANIM_EXIT_EV;
    /* During: HMI_MENU_WAIT_FOR_ANIM_EXIT */
    if((chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST ==
      IN_HMI_MENU_WAIT_FOR_ANIM_EXIT) && (_sfEvent_hmi_menu_core_01_model_ ==
      event_HMI_MENU_WAIT_ANIM_EXIT_EV)) {
      /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
      /* Entry: HMI_MENU_WAIT_ANIM_RUNNING_ST */
      chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
        (uint8_T)IN_HMI_MENU_WAIT_ANIM_RUNNING_ST;
      hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
       chartInstance->l_menu_id_U8);
      hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
       MENU_CB_ACTION_WAIT);
    }
    _sfEvent_hmi_menu_core_01_model_ = c_previousEvent;
  }
  /* Entry: HMI_MENU_FAST_SCROLL_ST */
  chartInstance->is_active_HMI_MENU_FAST_SCROLL_ST = 1U;
  /* Entry: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
  chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
    (uint8_T)IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST;
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

void hmi_menu_core_01_chart(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  boolean_T temp;
  /* During: hmi_menu_core_01_chart */
  HMI_MENU_LOGIC_ST(chartInstance);
  HMI_MENU_ANIM_ST(chartInstance);
  /* During: HMI_MENU_FAST_SCROLL_ST */
  if(chartInstance->is_active_HMI_MENU_FAST_SCROLL_ST != 0) {
    if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_CLOSE_EV) {
      /* Exit: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
      /* Exit: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
      /* Exit: HMI_MENU_FAST_SCROLL_LIST_END_ST */
      /* Entry: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
      chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
        (uint8_T)IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST;
    } else {
      switch(chartInstance->is_HMI_MENU_FAST_SCROLL_ST) {
       case IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST:
        /* During: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
        if(chartInstance->is_HMI_MENU_FAST_SCROLL_ST ==
         IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST) {
          if(_sfEvent_hmi_menu_core_01_model_ ==
           event_HMI_MENU_FS_REPEAT_TIMEOUT_EV) {
            hmi_menu_logic_stop_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
            temp = (chartInstance->l_repeat_count >
              HMI_MENU_SCROLL_REPEAT_COUNT);
            if(temp) {
              temp = (hmi_menu_logic_is_FS_Enabled(chartInstance->l_menu_id_U8)
               == TRUE);
            }
            if(temp) {
              chartInstance->l_menu_state = (uint8_T)MENU_STATE_FAST;
              hmi_menu_logic_start_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,
               chartInstance->l_menu_id_U8);
              if(chartInstance->l_btn_status_BOOL == HMI_MENU_BTN_STATUS_IN) {
                chartInstance->l_btn_status_BOOL =
                  ((boolean_T)HMI_MENU_BTN_STATUS_LONG != 0);
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
                chartInstance->l_btn_cmd_U16 =
                  (uint16_T)hmi_menu_logic_FS_convert_Btn_status(chartInstance->l_btn_status_BOOL,
                 chartInstance->
                 l_btn_cmd_U16);
#else
                chartInstance->l_btn_cmd_U16 = (uint16_T)MENU_BTN_INVALID;
#endif
              }
            } else {
              chartInstance->l_menu_state = (uint8_T)MENU_STATE_NORMAL;
              hmi_menu_logic_start_timer(MENU_CORE_FASTSCROLL_CNT_INCR_TIMER,
               chartInstance->l_menu_id_U8);
              chartInstance->l_repeat_count++;
              chartInstance->l_btn_status_BOOL =
                ((boolean_T)HMI_MENU_BTN_STATUS_IN != 0);
            }
            /* Exit: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
            chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            /* Entry: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
            if(chartInstance->is_HMI_MENU_FAST_SCROLL_ST !=
             IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST) {
              chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
                (uint8_T)IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST;
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
              chartInstance->l_get_btn_result_U8 =
                (uint8_T)hmi_menu_button_handler(chartInstance->l_menu_id_U8,
               chartInstance->l_btn_cmd_U16,
               chartInstance->l_menu_state);
#else
              chartInstance->l_get_btn_result_U8 =
                (uint8_T)MENU_CB_ACTION_COMPLETED;
#endif
            }
          } else if(_sfEvent_hmi_menu_core_01_model_ ==
           event_HMI_MENU_FS_INACTIVE_EV) {
            /* Exit: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
            /* Entry: HMI_MENU_FAST_SCROLL_LIST_END_ST */
            chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
              (uint8_T)IN_HMI_MENU_FAST_SCROLL_LIST_END_ST;
            hmi_menu_logic_stop_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
            hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
             chartInstance->l_menu_action_output_U16);
            chartInstance->l_repeat_count = 0U;
            chartInstance->l_menu_state = (uint8_T)MENU_STATE_NORMAL;
            hmi_menu_logic_Set_MenuState(chartInstance->l_menu_id_U8,
             MENU_STATE_NORMAL);
          } else if(_sfEvent_hmi_menu_core_01_model_ ==
           event_HMI_MENU_FS_BTN_REL_EV) {
            hmi_menu_logic_stop_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
            chartInstance->l_get_btn_result_U8 =
              (uint8_T)hmi_menu_button_handler(chartInstance->l_menu_id_U8,
             chartInstance->l_btn_cmd_U16,
             chartInstance->l_menu_state);
#else
            chartInstance->l_get_btn_result_U8 =
              (uint8_T)MENU_CB_ACTION_COMPLETED;
#endif
            chartInstance->l_repeat_count = 0U;
            if(chartInstance->l_menu_state == MENU_STATE_FAST) {
              hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
               chartInstance->l_menu_action_output_U16);
              chartInstance->l_menu_state = (uint8_T)MENU_STATE_NORMAL;
              hmi_menu_logic_Set_MenuState(chartInstance->l_menu_id_U8,
               MENU_STATE_NORMAL);
              /* Exit: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
              /* Entry: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
              chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
                (uint8_T)IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST;
            } else {
              chartInstance->l_menu_state = (uint8_T)MENU_STATE_NORMAL;
              hmi_menu_logic_Set_MenuState(chartInstance->l_menu_id_U8,
               MENU_STATE_NORMAL);
              /* Exit: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
              /* Entry: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
              chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
                (uint8_T)IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST;
            }
          } else {
            if(_sfEvent_hmi_menu_core_01_model_ ==
             event_HMI_MENU_FS_REPEAT_TIMER_EV) {
              hmi_menu_logic_start_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,
               chartInstance->l_menu_id_U8);
            }
            /* hmi_menu_logic_stop_timer(MENU_CORE_FASTSCROLL_RUN_WAIT_TIMER,l_menu_id_U8); */
          }
        }
        break;
       case IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST:
        /* During: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
        if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_FS_BTN_EV) {
          chartInstance->l_repeat_count = 1U;
          chartInstance->l_menu_state = (uint8_T)MENU_STATE_NORMAL;
          hmi_menu_logic_start_timer(MENU_CORE_FASTSCROLL_CNT_START_TIMER,
           chartInstance->l_menu_id_U8);
          /* Exit: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
          /* Entry: HMI_MENU_FAST_SCROLL_ACTIVE_ST */
          chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
            (uint8_T)IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST;
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
          chartInstance->l_get_btn_result_U8 =
            (uint8_T)hmi_menu_button_handler(chartInstance->l_menu_id_U8,
           chartInstance->l_btn_cmd_U16,
           chartInstance->l_menu_state);
#else
          chartInstance->l_get_btn_result_U8 = (uint8_T)MENU_CB_ACTION_COMPLETED;
#endif
        }
        break;
       case IN_HMI_MENU_FAST_SCROLL_LIST_END_ST:
        /* During: HMI_MENU_FAST_SCROLL_LIST_END_ST */
        if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_FS_BTN_REL_EV) {
          /* Exit: HMI_MENU_FAST_SCROLL_LIST_END_ST */
          /* Entry: HMI_MENU_FAST_SCROLL_INACTIVE_ST */
          chartInstance->is_HMI_MENU_FAST_SCROLL_ST =
            (uint8_T)IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST;
        }
        break;
       default:
        chartInstance->is_HMI_MENU_FAST_SCROLL_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
  }
}

void hmi_menu_chart_Menu_FSTimeout(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_Menu_FSTimeout */
  if(!(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST)) {
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_FS_REPEAT_TIMEOUT_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
  } else {
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_FS_REPEAT_TIMER_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
  }
}

uint8_T hmi_menu_chart_FS_btn_result(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  /* Function Call: hmi_menu_chart_FS_btn_result */
  return chartInstance->l_get_btn_result_U8;
}

boolean_T hmi_menu_chart_is_FS_st(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  /* Function Call: hmi_menu_chart_is_FS_st */
  return chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_SCROLL_ST;
}

void hmi_menu_chart_anim_started(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_anim_started */
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_ANIM_STARTED_EV;
  HMI_MENU_ANIM_ST(chartInstance);
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

void hmi_menu_chart_close(SFhmi_menu_core_01_chartInstanceStruct *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_close */
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_CLOSE_EV;
  hmi_menu_core_01_chart(chartInstance);
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

void hmi_menu_chart_Menu_open(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_id_U8, uint16_T
 p_cb_return_val_U16)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_Menu_open */
  if(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_INACTIVE_ST) {
    chartInstance->l_menu_action_output_U16 = p_cb_return_val_U16;
    chartInstance->l_menu_id_U8 = p_menu_id_U8;
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_OPEN_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
  } else {
    chartInstance->l_menu_id_U8 = p_menu_id_U8;
  }
}

void hmi_menu_chart_FS_Btn_process(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_ID_U8, uint16_T
 p_button_cmd_U16)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_FS_Btn_process */
  if(chartInstance->is_HMI_MENU_FAST_SCROLL_ST ==
   IN_HMI_MENU_FAST_SCROLL_INACTIVE_ST) {
    chartInstance->l_btn_cmd_U16 = p_button_cmd_U16;
    chartInstance->l_menu_id_U8 = p_menu_ID_U8;
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_FS_BTN_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
  } else {
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
    if(hmi_menu_logic_FS_check_is_Btn_rel(p_button_cmd_U16) == TRUE) {
      chartInstance->l_btn_cmd_U16 = p_button_cmd_U16;
      chartInstance->l_menu_id_U8 = p_menu_ID_U8;
      b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
      _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_FS_BTN_REL_EV;
      hmi_menu_core_01_chart(chartInstance);
      _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
    }
#endif
  }
}

void hmi_menu_chart_DataAvailable(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_DataAvailable */
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_DATA_AVAIL_EV;
  hmi_menu_core_01_chart(chartInstance);
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

void hmi_menu_chart_anim_exit(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_anim_exit */
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_ANIM_EXIT_EV;
  HMI_MENU_ANIM_ST(chartInstance);
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

void hmi_menu_chart_Wait_temp_timeout(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_Wait_temp_timeout */
  b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
  _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_WAIT_TEMP_TIMEOUT_EV;
  hmi_menu_core_01_chart(chartInstance);
  _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
}

static void HMI_MENU_LOGIC_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  boolean_T guard1 = false;
  /* During: HMI_MENU_LOGIC_ST */
  if(chartInstance->is_active_HMI_MENU_LOGIC_ST != 0) {
    guard1 = false;
    if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_CLOSE_EV) {
      exit_internal_HMI_MENU_LOGIC_ST(chartInstance);
      /* Entry: HMI_MENU_INACTIVE_ST */
      chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_INACTIVE_ST;
    } else if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_REBUILD_EV) {
      if((chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_FASTUP) ||
       (chartInstance->l_menu_action_output_U16 ==
        MENU_CB_ACTION_FASTDOWN)) {
        exit_internal_HMI_MENU_LOGIC_ST(chartInstance);
        /* Entry: HMI_MENU_SCROLL_ST */
        if(chartInstance->is_HMI_MENU_LOGIC_ST != IN_HMI_MENU_SCROLL_ST) {
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_SCROLL_ST;
          /* Function Call: hmi_menu_fast_scroll_trigger */
          if(chartInstance->fast_scroll_active == FALSE) {
            hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
             chartInstance->l_menu_action_output_U16);
            chartInstance->fast_scroll_active = ((boolean_T)TRUE != 0);
          } else if(chartInstance->fast_scroll_active_rel == TRUE) {
            chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
            chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
          } else {
            /*  Do Nothing
               QAC 8.1.2 Fix */
          }
        }
      } else if(chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_WAIT) {
        exit_internal_HMI_MENU_LOGIC_ST(chartInstance);
        /* Entry: HMI_MENU_WAIT_ST */
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
        /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
        if(chartInstance->is_HMI_MENU_WAIT_ST != IN_HMI_MENU_WAIT_TEMP_TMR_ST) {
          chartInstance->is_HMI_MENU_WAIT_ST =
            (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
          hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
           chartInstance->l_menu_id_U8);
        }
      } else {
        /* for MENU_CB_ACTION_ANIMATION|MENU_CB_ACTION_COMPLETED */
        if(hmi_menu_logic_MenuIsOpen(chartInstance->l_menu_id_U8) == FALSE) {
          exit_internal_HMI_MENU_LOGIC_ST(chartInstance);
          /* Entry: HMI_MENU_INACTIVE_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_INACTIVE_ST;
        } else {
          exit_internal_HMI_MENU_LOGIC_ST(chartInstance);
          /* Entry: HMI_MENU_ACTIVE_ST */
          if(chartInstance->is_HMI_MENU_LOGIC_ST != IN_HMI_MENU_ACTIVE_ST) {
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_ACTIVE_ST;
            chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
            chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
          }
        }
      }
    } else {
      switch(chartInstance->is_HMI_MENU_LOGIC_ST) {
       case IN_HMI_MENU_ACTIVE_ST:
        /* During: HMI_MENU_ACTIVE_ST */
        if((_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_BTN_ACTIONS_EV)
         && ((chartInstance->is_HMI_MENU_ANIM_ST ==
           IN_HMI_MENU_ANIM_INACTIVE_ST) ||
          (hmi_menu_logic_is_menu_action_allowed_in_anim_state(chartInstance->l_menu_action_U8)
           == TRUE))) {
          chartInstance->l_menu_action_output_U16 =
            (uint16_T)hmi_menu_logic_process_menu_action(chartInstance->l_menu_id_U8,
           chartInstance->
           l_menu_action_U8);
          if((chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_FASTUP)
           || (chartInstance->l_menu_action_output_U16 ==
            MENU_CB_ACTION_FASTDOWN)) {
            /* Exit: HMI_MENU_ACTIVE_ST */
            /* Entry: HMI_MENU_SCROLL_ST */
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_SCROLL_ST;
            /* Function Call: hmi_menu_fast_scroll_trigger */
            if(chartInstance->fast_scroll_active == FALSE) {
              hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
               chartInstance->l_menu_action_output_U16);
              chartInstance->fast_scroll_active = ((boolean_T)TRUE != 0);
            } else if(chartInstance->fast_scroll_active_rel == TRUE) {
              chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
              chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
            } else {
              /*  Do Nothing
                 QAC 8.1.2 Fix */
            }
          } else if(chartInstance->l_menu_action_output_U16 ==
           MENU_CB_ACTION_WAIT) {
            /* Exit: HMI_MENU_ACTIVE_ST */
            /* Entry: HMI_MENU_WAIT_ST */
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
            /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
            if(chartInstance->is_HMI_MENU_WAIT_ST !=
             IN_HMI_MENU_WAIT_TEMP_TMR_ST) {
              chartInstance->is_HMI_MENU_WAIT_ST =
                (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
              hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
               chartInstance->l_menu_id_U8);
            }
          } else {
            /* for MENU_CB_ACTION_ANIMATION|MENU_CB_ACTION_COMPLETED */
            if(hmi_menu_logic_MenuIsOpen(chartInstance->l_menu_id_U8) == FALSE) {
              /* Exit: HMI_MENU_ACTIVE_ST */
              /* Entry: HMI_MENU_INACTIVE_ST */
              chartInstance->is_HMI_MENU_LOGIC_ST =
                (uint8_T)IN_HMI_MENU_INACTIVE_ST;
            } else {
              /* Exit: HMI_MENU_ACTIVE_ST */
              /* Entry: HMI_MENU_ACTIVE_ST */
              chartInstance->is_HMI_MENU_LOGIC_ST =
                (uint8_T)IN_HMI_MENU_ACTIVE_ST;
              chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
              chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
            }
          }
        }
        break;
       case IN_HMI_MENU_INACTIVE_ST:
        /* During: HMI_MENU_INACTIVE_ST */
        if((chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_INACTIVE_ST) &&
         (_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_OPEN_EV)) {
          if(chartInstance->l_menu_action_output_U16 ==
           MENU_CB_ACTION_COMPLETED) {
            /* Exit: HMI_MENU_INACTIVE_ST */
            /* Entry: HMI_MENU_ACTIVE_ST */
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_ACTIVE_ST;
            chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
            chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
          } else if((chartInstance->l_menu_action_output_U16 ==
            MENU_CB_ACTION_FASTUP) || (chartInstance->l_menu_action_output_U16
            ==
            MENU_CB_ACTION_FASTDOWN)) {
            /* Exit: HMI_MENU_INACTIVE_ST */
            /* Entry: HMI_MENU_SCROLL_ST */
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_SCROLL_ST;
            /* Function Call: hmi_menu_fast_scroll_trigger */
            if(chartInstance->fast_scroll_active == FALSE) {
              hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
               chartInstance->l_menu_action_output_U16);
              chartInstance->fast_scroll_active = ((boolean_T)TRUE != 0);
            } else if(chartInstance->fast_scroll_active_rel == TRUE) {
              chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
              chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
            } else {
              /*  Do Nothing
                 QAC 8.1.2 Fix */
            }
          } else if(chartInstance->l_menu_action_output_U16 ==
           MENU_CB_ACTION_WAIT) {
            /* Exit: HMI_MENU_INACTIVE_ST */
            /* Entry: HMI_MENU_WAIT_ST */
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
            /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
            if(chartInstance->is_HMI_MENU_WAIT_ST !=
             IN_HMI_MENU_WAIT_TEMP_TMR_ST) {
              chartInstance->is_HMI_MENU_WAIT_ST =
                (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
              hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
               chartInstance->l_menu_id_U8);
            }
          } else {
            /* for MENU_CB_ACTION_ANIMATION|MENU_CB_ACTION_COMPLETED */
            if(hmi_menu_logic_MenuIsOpen(chartInstance->l_menu_id_U8) == FALSE) {
              /* Exit: HMI_MENU_INACTIVE_ST */
              /* Entry: HMI_MENU_INACTIVE_ST */
              chartInstance->is_HMI_MENU_LOGIC_ST =
                (uint8_T)IN_HMI_MENU_INACTIVE_ST;
            } else {
              /* Exit: HMI_MENU_INACTIVE_ST */
              /* Entry: HMI_MENU_ACTIVE_ST */
              chartInstance->is_HMI_MENU_LOGIC_ST =
                (uint8_T)IN_HMI_MENU_ACTIVE_ST;
              chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
              chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
            }
          }
        }
        break;
       case IN_HMI_MENU_SCROLL_ST:
        /* During: HMI_MENU_SCROLL_ST */
        if(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_SCROLL_ST) {
          if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_BTN_ACTIONS_EV) {
            chartInstance->l_menu_action_output_U16 =
              (uint16_T)hmi_menu_logic_process_menu_action(chartInstance->l_menu_id_U8,
             chartInstance->
             l_menu_action_U8);
            guard1 = true;
          } else if(_sfEvent_hmi_menu_core_01_model_ ==
           event_HMI_MENU_BTN_MC_RELEASE_EV) {
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
            chartInstance->l_menu_action_output_U16 =
              (uint16_T)hmi_menu_logic_MenuCompletion(chartInstance->l_menu_id_U8);
#else
            chartInstance->l_menu_action_output_U16 =
              (uint16_T)hmi_menu_logic_MenuCompletion();
#endif
            /*  hmi_menu_chart_FS_end_action(); */
            chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
            guard1 = true;
          }
        }
        break;
       case IN_HMI_MENU_WAIT_ST:
        HMI_MENU_WAIT_ST(chartInstance);
        break;
       default:
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    if(guard1 == true) {
      if((chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_FASTUP) ||
       (chartInstance->l_menu_action_output_U16 ==
        MENU_CB_ACTION_FASTDOWN)) {
        /* Exit: HMI_MENU_SCROLL_ST */
        /* Entry: HMI_MENU_SCROLL_ST */
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_SCROLL_ST;
        /* Function Call: hmi_menu_fast_scroll_trigger */
        if(chartInstance->fast_scroll_active == FALSE) {
          hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
           chartInstance->l_menu_action_output_U16);
          chartInstance->fast_scroll_active = ((boolean_T)TRUE != 0);
        } else if(chartInstance->fast_scroll_active_rel == TRUE) {
          chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
          chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
        } else {
          /*  Do Nothing
             QAC 8.1.2 Fix */
        }
      } else if(chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_WAIT) {
        /* Exit: HMI_MENU_SCROLL_ST */
        /* Entry: HMI_MENU_WAIT_ST */
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
        /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
        if(chartInstance->is_HMI_MENU_WAIT_ST != IN_HMI_MENU_WAIT_TEMP_TMR_ST) {
          chartInstance->is_HMI_MENU_WAIT_ST =
            (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
          hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
           chartInstance->l_menu_id_U8);
        }
      } else {
        /* for MENU_CB_ACTION_ANIMATION|MENU_CB_ACTION_COMPLETED */
        if(hmi_menu_logic_MenuIsOpen(chartInstance->l_menu_id_U8) == FALSE) {
          /* Exit: HMI_MENU_SCROLL_ST */
          /* Entry: HMI_MENU_INACTIVE_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_INACTIVE_ST;
        } else {
          /* Exit: HMI_MENU_SCROLL_ST */
          /* Entry: HMI_MENU_ACTIVE_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_ACTIVE_ST;
          chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
          chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
        }
      }
    }
  }
}

static void
exit_internal_HMI_MENU_LOGIC_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  switch(chartInstance->is_HMI_MENU_LOGIC_ST) {
   case IN_HMI_MENU_ACTIVE_ST:
    /* Exit: HMI_MENU_ACTIVE_ST */
    chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
    break;
   case IN_HMI_MENU_INACTIVE_ST:
    /* Exit: HMI_MENU_INACTIVE_ST */
    chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
    break;
   case IN_HMI_MENU_SCROLL_ST:
    /* Exit: HMI_MENU_SCROLL_ST */
    chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
    break;
   case IN_HMI_MENU_WAIT_ST:
    switch(chartInstance->is_HMI_MENU_WAIT_ST) {
     case IN_HMI_MENU_WAIT_ACTIVE_ST:
      switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
       case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
        /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
        hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
         MENU_CB_ACTION_WAIT);
        chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
        chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
       case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
        /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
        chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
       default:
        chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
      /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
      chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
     case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
      /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
      chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
     default:
      chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
    }
    /* Exit: HMI_MENU_WAIT_ST */
    hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER, chartInstance->l_menu_id_U8);
    chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
    break;
   default:
    chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
    break;
  }
}

static void HMI_MENU_WAIT_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  boolean_T guard1 = false;
  uint16_T fl_cb_result;
  /* During: HMI_MENU_WAIT_ST */
  if(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST) {
    guard1 = false;
    if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_DATA_AVAIL_EV) {
      if(chartInstance->l_btn_rel_in_fast_scroll != FALSE) {
        chartInstance->l_btn_rel_in_fast_scroll = ((boolean_T)FALSE != 0);
#ifdef HMI_MENU_FAST_SCROLL_ENABLE
        hmi_menu_logic_Set_MenuState(chartInstance->l_menu_id_U8,
         MENU_STATE_NORMAL);
        fl_cb_result =
          (uint16_T)hmi_menu_logic_MenuCompletion(chartInstance->l_menu_id_U8);
#else
        fl_cb_result = (uint16_T)hmi_menu_logic_MenuCompletion();
#endif
        if(fl_cb_result == MENU_CB_ACTION_WAIT) {
          hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
           MENU_CB_ACTION_FASTUP);
          switch(chartInstance->is_HMI_MENU_WAIT_ST) {
           case IN_HMI_MENU_WAIT_ACTIVE_ST:
            switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
             case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
              /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
              hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
               MENU_CB_ACTION_WAIT);
              chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
              /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             default:
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
            }
            /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
            /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           default:
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
          /* Exit: HMI_MENU_WAIT_ST */
          if(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST) {
            hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
            chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          }
          /* Entry: HMI_MENU_WAIT_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
          /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
          if(chartInstance->is_HMI_MENU_WAIT_ST != IN_HMI_MENU_WAIT_TEMP_TMR_ST)
          {
            chartInstance->is_HMI_MENU_WAIT_ST =
              (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
            hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    } else {
      switch(chartInstance->is_HMI_MENU_WAIT_ST) {
       case IN_HMI_MENU_WAIT_ACTIVE_ST:
        /* During: HMI_MENU_WAIT_ACTIVE_ST */
        switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
         case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
          break;
         case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
          /* During: HMI_MENU_WAIT_FOR_ANIM_EXIT */
          if(_sfEvent_hmi_menu_core_01_model_ ==
           event_HMI_MENU_WAIT_ANIM_EXIT_EV) {
            /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
            /* Entry: HMI_MENU_WAIT_ANIM_RUNNING_ST */
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_HMI_MENU_WAIT_ANIM_RUNNING_ST;
            hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
            hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
             MENU_CB_ACTION_WAIT);
          }
          break;
         default:
          chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
            (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
        }
        break;
       case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
        /* During: HMI_MENU_WAIT_TEMP_TMR_ST */
        if((chartInstance->is_HMI_MENU_WAIT_ST == IN_HMI_MENU_WAIT_TEMP_TMR_ST)
         && (_sfEvent_hmi_menu_core_01_model_ ==
          event_HMI_MENU_WAIT_TEMP_TIMEOUT_EV)) {
          /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
          /* Entry: HMI_MENU_WAIT_ACTIVE_ST */
          chartInstance->is_HMI_MENU_WAIT_ST =
            (uint8_T)IN_HMI_MENU_WAIT_ACTIVE_ST;
          if(chartInstance->is_HMI_MENU_ANIM_ST == IN_HMI_MENU_ANIM_INACTIVE_ST)
          {
            /* Entry: HMI_MENU_WAIT_ANIM_RUNNING_ST */
            if(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST !=
             IN_HMI_MENU_WAIT_ANIM_RUNNING_ST) {
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_HMI_MENU_WAIT_ANIM_RUNNING_ST;
              hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
               chartInstance->l_menu_id_U8);
              hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
               MENU_CB_ACTION_WAIT);
            }
          } else {
            /* Entry: HMI_MENU_WAIT_FOR_ANIM_EXIT */
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_HMI_MENU_WAIT_FOR_ANIM_EXIT;
          }
        }
        break;
       default:
        chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    if(guard1 == true) {
      chartInstance->l_menu_action_output_U16 =
        (uint16_T)hmi_menu_logic_MenuDataAvailable(chartInstance->l_menu_id_U8);
      if((chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_FASTUP) ||
       (chartInstance->l_menu_action_output_U16 ==
        MENU_CB_ACTION_FASTDOWN)) {
        switch(chartInstance->is_HMI_MENU_WAIT_ST) {
         case IN_HMI_MENU_WAIT_ACTIVE_ST:
          switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
           case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
            /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
            hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
             MENU_CB_ACTION_WAIT);
            chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
            /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           default:
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
          /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
         case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
          /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
         default:
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
        }
        /* Exit: HMI_MENU_WAIT_ST */
        hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
         chartInstance->l_menu_id_U8);
        /* Entry: HMI_MENU_SCROLL_ST */
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_SCROLL_ST;
        /* Function Call: hmi_menu_fast_scroll_trigger */
        if(chartInstance->fast_scroll_active == FALSE) {
          hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
           chartInstance->l_menu_action_output_U16);
          chartInstance->fast_scroll_active = ((boolean_T)TRUE != 0);
        } else if(chartInstance->fast_scroll_active_rel == TRUE) {
          chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
          chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
        } else {
          /*  Do Nothing
             QAC 8.1.2 Fix */
        }
      } else if(chartInstance->l_menu_action_output_U16 == MENU_CB_ACTION_WAIT) {
        switch(chartInstance->is_HMI_MENU_WAIT_ST) {
         case IN_HMI_MENU_WAIT_ACTIVE_ST:
          switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
           case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
            /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
            hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
             MENU_CB_ACTION_WAIT);
            chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
            /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           default:
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
          /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
         case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
          /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
         default:
          chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
          break;
        }
        /* Exit: HMI_MENU_WAIT_ST */
        hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
         chartInstance->l_menu_id_U8);
        /* Entry: HMI_MENU_WAIT_ST */
        chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_WAIT_ST;
        /* Entry: HMI_MENU_WAIT_TEMP_TMR_ST */
        if(chartInstance->is_HMI_MENU_WAIT_ST != IN_HMI_MENU_WAIT_TEMP_TMR_ST) {
          chartInstance->is_HMI_MENU_WAIT_ST =
            (uint8_T)IN_HMI_MENU_WAIT_TEMP_TMR_ST;
          hmi_menu_logic_start_timer(MENU_CORE_WAIT_TIMER,
           chartInstance->l_menu_id_U8);
        }
      } else {
        /* for MENU_CB_ACTION_ANIMATION|MENU_CB_ACTION_COMPLETED */
        if(hmi_menu_logic_MenuIsOpen(chartInstance->l_menu_id_U8) == FALSE) {
          switch(chartInstance->is_HMI_MENU_WAIT_ST) {
           case IN_HMI_MENU_WAIT_ACTIVE_ST:
            switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
             case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
              /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
              hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
               MENU_CB_ACTION_WAIT);
              chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
              /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             default:
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
            }
            /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
            /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           default:
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
          /* Exit: HMI_MENU_WAIT_ST */
          hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
           chartInstance->l_menu_id_U8);
          /* Entry: HMI_MENU_INACTIVE_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_INACTIVE_ST;
        } else {
          switch(chartInstance->is_HMI_MENU_WAIT_ST) {
           case IN_HMI_MENU_WAIT_ACTIVE_ST:
            switch(chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST) {
             case IN_HMI_MENU_WAIT_ANIM_RUNNING_ST:
              /* Exit: HMI_MENU_WAIT_ANIM_RUNNING_ST */
              hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
               MENU_CB_ACTION_WAIT);
              chartInstance->fast_scroll_active_rel = ((boolean_T)TRUE != 0);
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             case IN_HMI_MENU_WAIT_FOR_ANIM_EXIT:
              /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
             default:
              chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
                (uint8_T)IN_NO_ACTIVE_CHILD;
              break;
            }
            /* Exit: HMI_MENU_WAIT_ACTIVE_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           case IN_HMI_MENU_WAIT_TEMP_TMR_ST:
            /* Exit: HMI_MENU_WAIT_TEMP_TMR_ST */
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
           default:
            chartInstance->is_HMI_MENU_WAIT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
          /* Exit: HMI_MENU_WAIT_ST */
          hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
           chartInstance->l_menu_id_U8);
          /* Entry: HMI_MENU_ACTIVE_ST */
          chartInstance->is_HMI_MENU_LOGIC_ST = (uint8_T)IN_HMI_MENU_ACTIVE_ST;
          chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
          chartInstance->fast_scroll_active_rel = ((boolean_T)FALSE != 0);
        }
      }
    }
  }
}

static void HMI_MENU_ANIM_ST(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* During: HMI_MENU_ANIM_ST */
  if(chartInstance->is_active_HMI_MENU_ANIM_ST != 0) {
    if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_CLOSE_EV) {
      /* Exit: HMI_MENU_ANIM_ACTIVE_ST */
      /* Exit: HMI_MENU_ANIM_INACTIVE_ST */
      /* Entry: HMI_MENU_ANIM_INACTIVE_ST */
      chartInstance->is_HMI_MENU_ANIM_ST = (uint8_T)IN_HMI_MENU_ANIM_INACTIVE_ST;
      b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
      _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_WAIT_ANIM_EXIT_EV;
      /* During: HMI_MENU_WAIT_FOR_ANIM_EXIT */
      if((chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST ==
        IN_HMI_MENU_WAIT_FOR_ANIM_EXIT) && (_sfEvent_hmi_menu_core_01_model_ ==
        event_HMI_MENU_WAIT_ANIM_EXIT_EV)) {
        /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
        /* Entry: HMI_MENU_WAIT_ANIM_RUNNING_ST */
        chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
          (uint8_T)IN_HMI_MENU_WAIT_ANIM_RUNNING_ST;
        hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
         chartInstance->l_menu_id_U8);
        hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
         MENU_CB_ACTION_WAIT);
      }
      _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
    } else {
      switch(chartInstance->is_HMI_MENU_ANIM_ST) {
       case IN_HMI_MENU_ANIM_ACTIVE_ST:
        /* During: HMI_MENU_ANIM_ACTIVE_ST */
        if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_ANIM_EXIT_EV) {
          /* Exit: HMI_MENU_ANIM_ACTIVE_ST */
          /* Entry: HMI_MENU_ANIM_INACTIVE_ST */
          chartInstance->is_HMI_MENU_ANIM_ST =
            (uint8_T)IN_HMI_MENU_ANIM_INACTIVE_ST;
          b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
          _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_WAIT_ANIM_EXIT_EV;
          /* During: HMI_MENU_WAIT_FOR_ANIM_EXIT */
          if((chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST ==
            IN_HMI_MENU_WAIT_FOR_ANIM_EXIT) && (_sfEvent_hmi_menu_core_01_model_
            ==
            event_HMI_MENU_WAIT_ANIM_EXIT_EV)) {
            /* Exit: HMI_MENU_WAIT_FOR_ANIM_EXIT */
            /* Entry: HMI_MENU_WAIT_ANIM_RUNNING_ST */
            chartInstance->is_HMI_MENU_WAIT_ACTIVE_ST =
              (uint8_T)IN_HMI_MENU_WAIT_ANIM_RUNNING_ST;
            hmi_menu_logic_stop_timer(MENU_CORE_WAIT_TIMER,
             chartInstance->l_menu_id_U8);
            hmi_menu_logic_activate_animation(chartInstance->l_menu_id_U8,
             MENU_CB_ACTION_WAIT);
          }
          _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
        }
        break;
       case IN_HMI_MENU_ANIM_INACTIVE_ST:
        /* During: HMI_MENU_ANIM_INACTIVE_ST */
        /*  animation started by view manager and vm is in anim state */
        if(_sfEvent_hmi_menu_core_01_model_ == event_HMI_MENU_ANIM_STARTED_EV) {
          /* Exit: HMI_MENU_ANIM_INACTIVE_ST */
          /* Entry: HMI_MENU_ANIM_ACTIVE_ST */
          chartInstance->is_HMI_MENU_ANIM_ST =
            (uint8_T)IN_HMI_MENU_ANIM_ACTIVE_ST;
        }
        break;
       default:
        chartInstance->is_HMI_MENU_ANIM_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
        break;
      }
    }
  }
}

void hmi_menu_fast_scroll_inactive(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_fast_scroll_inactive */
  if(chartInstance->is_HMI_MENU_FAST_SCROLL_ST ==
   IN_HMI_MENU_FAST_SCROLL_ACTIVE_ST) {
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_FS_INACTIVE_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
    if(chartInstance->fast_scroll_active == TRUE) {
      hmi_menu_logic_deactivate_animation(chartInstance->l_menu_id_U8,
       MENU_CB_ACTION_FASTUP);
      chartInstance->fast_scroll_active = ((boolean_T)FALSE != 0);
    }
  }
}

void hmi_menu_chart_menu_rebuild(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint16_T fl_menu_cb_output_U16)
{
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_menu_rebuild */
  if(!(chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_INACTIVE_ST)) {
    chartInstance->l_menu_action_output_U16 = fl_menu_cb_output_U16;
    b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
    _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_REBUILD_EV;
    hmi_menu_core_01_chart(chartInstance);
    _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
  }
}

boolean_T hmi_menu_chart_is_anim_st(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance)
{
  /* Function Call: hmi_menu_chart_is_anim_st */
  return chartInstance->is_HMI_MENU_ANIM_ST == IN_HMI_MENU_ANIM_ACTIVE_ST;
}

uint8_T hmi_menu_chart_Btn_trigger(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_ID_U8, uint8_T
 p_menu_btn_action_U8, uint8_T p_menu_state)
{
  boolean_T return_st;
  uint8_T b_previousEvent;
  /* Function Call: hmi_menu_chart_Btn_trigger */
  if((chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_ACTIVE_ST) ||
   (chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_SCROLL_ST)
   || (chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST)) {
    chartInstance->l_menu_action_U8 = p_menu_btn_action_U8;
    chartInstance->l_menu_id_U8 = p_menu_ID_U8;
    /* Function Call: hmi_menu_chart_check_MC_rel */
    if((chartInstance->l_menu_action_U8 == MENU_ACTION_UP_RELEASE) ||
     (chartInstance->l_menu_action_U8 == MENU_ACTION_DOWN_RELEASE) || (
      chartInstance->l_menu_action_U8 == MENU_ACTION_LEFT_RELEASE) ||
     (chartInstance->l_menu_action_U8 == MENU_ACTION_RIGHT_RELEASE)) {
      return_st = ((boolean_T)TRUE != 0);
    } else {
      return_st = ((boolean_T)FALSE != 0);
    }
    if(((chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_SCROLL_ST) ||
      (chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST))
     && (TRUE == return_st)) {
      if((chartInstance->is_HMI_MENU_LOGIC_ST == IN_HMI_MENU_WAIT_ST) &&
       (p_menu_state == MENU_STATE_FAST)) {
        chartInstance->l_btn_rel_in_fast_scroll = ((boolean_T)TRUE != 0);
      } else {
        b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
        _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_BTN_MC_RELEASE_EV;
        hmi_menu_core_01_chart(chartInstance);
        _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
      }
    } else {
      b_previousEvent = _sfEvent_hmi_menu_core_01_model_;
      _sfEvent_hmi_menu_core_01_model_ = event_HMI_MENU_BTN_ACTIONS_EV;
      hmi_menu_core_01_chart(chartInstance);
      _sfEvent_hmi_menu_core_01_model_ = b_previousEvent;
    }
    return (uint8_T)MENU_BTN_ABSORBED;
  } else {
    return (uint8_T)MENU_BTN_NONE;
  }
}

