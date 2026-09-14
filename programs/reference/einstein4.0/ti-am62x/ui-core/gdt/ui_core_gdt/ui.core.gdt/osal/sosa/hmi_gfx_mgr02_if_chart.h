/*
 * Stateflow code generation for chart:
 *    hmi_gfx_mgr02_if_model/hmi_gfx_mgr02_if_chart
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 19-Feb-2013 21:04:06
 */

#ifndef __hmi_gfx_mgr02_if_chart_h__
#define __hmi_gfx_mgr02_if_chart_h__

/* Type Definitions */

typedef struct {
  uint8_T l_hm_emergency_shutdown_req;
  uint8_T l_hm_gt_tick_U8;
  uint_T is_GFX_MGR02_IF_ST : 3;
  uint_T is_GFX_MGR02_GT_ST : 2;
  uint_T is_GFX_MGR02_IF_TASK_ST : 2;
  uint_T is_active_GFX_MGR02_GT_ST : 1;
  uint_T is_active_GFX_MGR02_IF_ST : 1;
} SFhmi_gfx_mgr02_if_chartInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
void initialize_hmi_gfx_mgr02_if_chart(void);
void hmi_gfx_mgr02_if_chart(void);
void hmi_gfx_mgr02_if_shutdown(uint8_T p_shutdown_type);
void hmi_gfx_mgr02_if_KSTimedTask(void);
uint8_T hmi_gfx_mgr02_if_start(void);
void Graphics_Task_Done(void);
uint8_T hmi_gfx_mgr02_if_is_ready_to_sleep(void);

/* Function Definitions */

#endif

