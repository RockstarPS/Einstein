/*
 * Stateflow code generation for chart:
 *    hmi_gfx_mgr02_if_model/hmi_gfx_mgr02_if_chart
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 19-Feb-2013 21:04:06
 */

/* Include files */
#include "hmi_gfx_mgr02_if_model_autocode.h"
#include "hmi_gfx_mgr02_if_chart.h"

/* Type Definitions */

/* Named Constants */
#define event_GFX_MGR02_ACTIVATION_EV   (5U)
#define event_GFX_MGR02_EXEC_EV         (4U)
#define event_GFX_MGR02_GT_DONE_EV      (0U)
#define event_GFX_MGR02_IF_DEACTIVATION_EV (2U)
#define event_GFX_MGR02_IF_FORCED_DEACTIVATION_EV (3U)
#define event_GFX_MGR02_GT_EXECUTE_EV   (1U)
#define IN_NO_ACTIVE_CHILD              (0)
#define IN_GFX_MGR02_IF_SHUTDOWN_ST     (1)
#define IN_GFX_MGR02_IF_TASK_ST         (2)
#define IN_GFX_MGR02_GT_WAIT_ST         (1)
#define IN_GFX_MGR02_REFRESH_WAIT_ST    (2)
#define IN_GFX_MGR02_IF_WAIT_ABNORMAL_SHUTDOWN_ST (3)
#define IN_GFX_MGR02_IF_WAIT_SHUTDOWN_ST (4)
#define IN_GFX_MGR02_GT_IDLE_ST         (2)
#define IN_GFX_MGR02_GT_BUSY_ST         (1)

/* Variable Declarations */

/* Variable Definitions */
static SFhmi_gfx_mgr02_if_chartInstanceStruct chartInstance;

/* Function Declarations */

/* Function Definitions */
void initialize_hmi_gfx_mgr02_if_chart(void)
{
  uint8_T b_previousEvent;
  chartInstance.is_GFX_MGR02_IF_ST = 0U;
  chartInstance.is_GFX_MGR02_IF_TASK_ST = 0U;
  chartInstance.l_hm_gt_tick_U8 = 0U;
  chartInstance.l_hm_emergency_shutdown_req = 0U;
  b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
  _sfEvent_hmi_gfx_mgr02_if_model_ = CALL_EVENT;
  chartInstance.is_active_GFX_MGR02_GT_ST = 1U;
  chartInstance.is_GFX_MGR02_GT_ST = (uint8_T)IN_GFX_MGR02_GT_IDLE_ST;
  chartInstance.is_active_GFX_MGR02_IF_ST = 1U;
  if(chartInstance.is_GFX_MGR02_IF_ST != IN_GFX_MGR02_IF_SHUTDOWN_ST) {
    chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_GFX_MGR02_IF_SHUTDOWN_ST;
    hmi_gfx_mgr02_layout_shutdown();
  }
  _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
}

void hmi_gfx_mgr02_if_chart(void)
{
  uint8_T b_previousEvent;
  if(chartInstance.is_active_GFX_MGR02_GT_ST != 0) {
    switch(chartInstance.is_GFX_MGR02_GT_ST) {
     case IN_GFX_MGR02_GT_BUSY_ST:
      if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_GT_DONE_EV) {
        chartInstance.is_GFX_MGR02_GT_ST = (uint8_T)IN_GFX_MGR02_GT_IDLE_ST;
      }
      break;
     case IN_GFX_MGR02_GT_IDLE_ST:
      if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_GT_EXECUTE_EV) {
        chartInstance.is_GFX_MGR02_GT_ST = (uint8_T)IN_GFX_MGR02_GT_BUSY_ST;
      }
      break;
     default:
      chartInstance.is_GFX_MGR02_GT_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
    }
  }
  if(chartInstance.is_active_GFX_MGR02_IF_ST != 0) {
    switch(chartInstance.is_GFX_MGR02_IF_ST) {
     case IN_GFX_MGR02_IF_SHUTDOWN_ST:
      if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_ACTIVATION_EV) {
        chartInstance.l_hm_emergency_shutdown_req = (uint8_T)FALSE;
        hmi_gfx_mgr02_layout_initialize();
        hmi_gfx_mgr02_layout_startup();
        chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_GFX_MGR02_IF_TASK_ST;
        chartInstance.l_hm_gt_tick_U8 =
          (uint8_T)GFX_MGR02_IF_PRESENTATION_SCHED_COUNT;
        if(chartInstance.is_GFX_MGR02_GT_ST == IN_GFX_MGR02_GT_BUSY_ST) {
          if(chartInstance.is_GFX_MGR02_IF_TASK_ST != IN_GFX_MGR02_GT_WAIT_ST) {
            chartInstance.is_GFX_MGR02_IF_TASK_ST =
              (uint8_T)IN_GFX_MGR02_GT_WAIT_ST;
            chartInstance.l_hm_gt_tick_U8 = 0U;
          }
        } else {
          chartInstance.is_GFX_MGR02_IF_TASK_ST =
            (uint8_T)IN_GFX_MGR02_REFRESH_WAIT_ST;
        }
      }
      break;
     case IN_GFX_MGR02_IF_TASK_ST:
      if(chartInstance.is_GFX_MGR02_IF_ST == IN_GFX_MGR02_IF_TASK_ST) {
        if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
         event_GFX_MGR02_IF_FORCED_DEACTIVATION_EV) {
          if(chartInstance.is_GFX_MGR02_GT_ST == IN_GFX_MGR02_GT_BUSY_ST) {
            chartInstance.is_GFX_MGR02_IF_TASK_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            chartInstance.is_GFX_MGR02_IF_ST =
              (uint8_T)IN_GFX_MGR02_IF_WAIT_ABNORMAL_SHUTDOWN_ST;
          } else {
            chartInstance.is_GFX_MGR02_IF_TASK_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            chartInstance.is_GFX_MGR02_IF_ST =
              (uint8_T)IN_GFX_MGR02_IF_SHUTDOWN_ST;
            hmi_gfx_mgr02_layout_shutdown();
          }
        } else if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
         event_GFX_MGR02_IF_DEACTIVATION_EV) {
          if(chartInstance.is_GFX_MGR02_GT_ST == IN_GFX_MGR02_GT_BUSY_ST) {
            chartInstance.is_GFX_MGR02_IF_TASK_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            chartInstance.is_GFX_MGR02_IF_ST =
              (uint8_T)IN_GFX_MGR02_IF_WAIT_SHUTDOWN_ST;
          } else {
            chartInstance.is_GFX_MGR02_IF_TASK_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            chartInstance.is_GFX_MGR02_IF_ST =
              (uint8_T)IN_GFX_MGR02_IF_SHUTDOWN_ST;
            hmi_gfx_mgr02_layout_shutdown();
          }
        } else {
          if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_EXEC_EV) {
            chartInstance.l_hm_gt_tick_U8++;
          }
          switch(chartInstance.is_GFX_MGR02_IF_TASK_ST) {
           case IN_GFX_MGR02_GT_WAIT_ST:
            if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_GT_DONE_EV) {
              chartInstance.is_GFX_MGR02_IF_TASK_ST =
                (uint8_T)IN_GFX_MGR02_REFRESH_WAIT_ST;
            }
            break;
           case IN_GFX_MGR02_REFRESH_WAIT_ST:
            if((_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_EXEC_EV) &&
             (chartInstance.l_hm_gt_tick_U8 >=
              GFX_MGR02_IF_PRESENTATION_SCHED_COUNT)) {
              if(hmi_gfx_mgr02_if_presentation_task() != (uint32_T)FALSE) {
                b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
                _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_GT_EXECUTE_EV;
                if(chartInstance.is_active_GFX_MGR02_GT_ST != 0) {
                  switch(chartInstance.is_GFX_MGR02_GT_ST) {
                   case IN_GFX_MGR02_GT_BUSY_ST:
                    if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
                     event_GFX_MGR02_GT_DONE_EV) {
                      chartInstance.is_GFX_MGR02_GT_ST =
                        (uint8_T)IN_GFX_MGR02_GT_IDLE_ST;
                    }
                    break;
                   case IN_GFX_MGR02_GT_IDLE_ST:
                    if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
                     event_GFX_MGR02_GT_EXECUTE_EV) {
                      chartInstance.is_GFX_MGR02_GT_ST =
                        (uint8_T)IN_GFX_MGR02_GT_BUSY_ST;
                    }
                    break;
                   default:
                    chartInstance.is_GFX_MGR02_GT_ST =
                      (uint8_T)IN_NO_ACTIVE_CHILD;
                    break;
                  }
                }
                _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
                chartInstance.is_GFX_MGR02_IF_TASK_ST =
                  (uint8_T)IN_GFX_MGR02_GT_WAIT_ST;
                chartInstance.l_hm_gt_tick_U8 = 0U;
              } else {
                chartInstance.l_hm_gt_tick_U8 = 0U;
                chartInstance.is_GFX_MGR02_IF_TASK_ST =
                  (uint8_T)IN_GFX_MGR02_REFRESH_WAIT_ST;
              }
            }
            break;
           default:
            chartInstance.is_GFX_MGR02_IF_TASK_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
            break;
          }
        }
      }
      break;
     case IN_GFX_MGR02_IF_WAIT_ABNORMAL_SHUTDOWN_ST:
      if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_GT_DONE_EV) {
        chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_GFX_MGR02_IF_SHUTDOWN_ST;
        hmi_gfx_mgr02_layout_shutdown();
      }
      break;
     case IN_GFX_MGR02_IF_WAIT_SHUTDOWN_ST:
      if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
       event_GFX_MGR02_IF_FORCED_DEACTIVATION_EV) {
        chartInstance.is_GFX_MGR02_IF_ST =
          (uint8_T)IN_GFX_MGR02_IF_WAIT_ABNORMAL_SHUTDOWN_ST;
      } else if(_sfEvent_hmi_gfx_mgr02_if_model_ == event_GFX_MGR02_GT_DONE_EV) {
        chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_GFX_MGR02_IF_SHUTDOWN_ST;
        hmi_gfx_mgr02_layout_shutdown();
      } else if(_sfEvent_hmi_gfx_mgr02_if_model_ ==
       event_GFX_MGR02_ACTIVATION_EV) {
        chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_GFX_MGR02_IF_TASK_ST;
        chartInstance.l_hm_gt_tick_U8 =
          (uint8_T)GFX_MGR02_IF_PRESENTATION_SCHED_COUNT;
        if(chartInstance.is_GFX_MGR02_GT_ST == IN_GFX_MGR02_GT_BUSY_ST) {
          if(chartInstance.is_GFX_MGR02_IF_TASK_ST != IN_GFX_MGR02_GT_WAIT_ST) {
            chartInstance.is_GFX_MGR02_IF_TASK_ST =
              (uint8_T)IN_GFX_MGR02_GT_WAIT_ST;
            chartInstance.l_hm_gt_tick_U8 = 0U;
          }
        } else {
          chartInstance.is_GFX_MGR02_IF_TASK_ST =
            (uint8_T)IN_GFX_MGR02_REFRESH_WAIT_ST;
        }
      }
      break;
     default:
      chartInstance.is_GFX_MGR02_IF_ST = (uint8_T)IN_NO_ACTIVE_CHILD;
      break;
    }
  }
}

void hmi_gfx_mgr02_if_shutdown(uint8_T p_shutdown_type)
{
  uint8_T b_previousEvent;
  if(p_shutdown_type == GFX_MGR02_SHUTDOWN_EMERGENCY) {
    chartInstance.l_hm_emergency_shutdown_req = (uint8_T)TRUE;
    hmi_gfx_mgr02_layout_emergency_shutdown();
  } else {
    b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
    _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_IF_DEACTIVATION_EV;
    hmi_gfx_mgr02_if_chart();
    _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
  }
}

void hmi_gfx_mgr02_if_KSTimedTask(void)
{
  uint8_T b_previousEvent;
  if(chartInstance.l_hm_emergency_shutdown_req != FALSE) {
    b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
    _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_IF_FORCED_DEACTIVATION_EV;
    hmi_gfx_mgr02_if_chart();
    _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
  } else {
    b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
    _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_EXEC_EV;
    hmi_gfx_mgr02_if_chart();
    _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
  }
}

uint8_T hmi_gfx_mgr02_if_start(void)
{
  uint8_T gfx_mgr02_start;
  uint8_T b_previousEvent;
  if(chartInstance.is_GFX_MGR02_IF_ST == IN_GFX_MGR02_IF_SHUTDOWN_ST) {
    gfx_mgr02_start = (uint8_T)TRUE;
    b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
    _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_ACTIVATION_EV;
    hmi_gfx_mgr02_if_chart();
    _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
  } else if((chartInstance.is_GFX_MGR02_IF_ST ==
    IN_GFX_MGR02_IF_WAIT_SHUTDOWN_ST) &&
   (chartInstance.l_hm_emergency_shutdown_req ==
    FALSE)) {
    gfx_mgr02_start = (uint8_T)TRUE;
    b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
    _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_ACTIVATION_EV;
    hmi_gfx_mgr02_if_chart();
    _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
  } else {
    gfx_mgr02_start = (uint8_T)FALSE;
  }
  return gfx_mgr02_start;
}

void Graphics_Task_Done(void)
{
  uint8_T b_previousEvent;
  b_previousEvent = _sfEvent_hmi_gfx_mgr02_if_model_;
  _sfEvent_hmi_gfx_mgr02_if_model_ = event_GFX_MGR02_GT_DONE_EV;
  hmi_gfx_mgr02_if_chart();
  _sfEvent_hmi_gfx_mgr02_if_model_ = b_previousEvent;
}

uint8_T hmi_gfx_mgr02_if_is_ready_to_sleep(void)
{
  uint8_T fl_flag;
  if(chartInstance.is_GFX_MGR02_IF_ST == IN_GFX_MGR02_IF_SHUTDOWN_ST) {
    fl_flag = (uint8_T)TRUE;
  } else {
    fl_flag = (uint8_T)FALSE;
  }
  return fl_flag;
}

