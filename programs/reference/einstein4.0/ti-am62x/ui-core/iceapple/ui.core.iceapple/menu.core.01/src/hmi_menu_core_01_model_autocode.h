/*
 * Stateflow code generation for machine:
 *    hmi_menu_core_01_model
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 12-Oct-2015 12:40:30
 */

#ifndef __hmi_menu_core_01_model_autocode_h__
#define __hmi_menu_core_01_model_autocode_h__

#include "tmwtypes.h"

/* Custom Code from Simulation Target dialog*/
#include "system.h"
#include "tmwtypes.h"
#include "hmi_logic_state_handler.h"
#include "hmi_menu_core_01_logic.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                      (MAX_uint8_T)

/* Variable Declarations */
extern uint8_T _sfEvent_hmi_menu_core_01_model_;

/* Variable Definitions */

/* Function Declarations */
void hmi_menu_core_01_model_initializer(void);
void hmi_menu_core_01_model_terminator(void);

/* Function Definitions */
#if 0
/* Global functions exported by all charts */
extern uint8_T hmi_menu_chart_Btn_trigger(uint8_T,uint8_T,uint8_T);
extern void hmi_menu_chart_DataAvailable(void);
extern void hmi_menu_chart_FS_Btn_process(uint8_T,uint16_T);
extern uint8_T hmi_menu_chart_FS_btn_result(void);
extern void hmi_menu_chart_Menu_FSTimeout(void);
extern void hmi_menu_chart_Menu_open(uint8_T,uint16_T);
extern void hmi_menu_chart_Wait_temp_timeout(void);
extern void hmi_menu_chart_anim_exit(void);
extern void hmi_menu_chart_anim_started(void);
extern void hmi_menu_chart_close(void);
extern boolean_T hmi_menu_chart_is_FS_st(void);
extern boolean_T hmi_menu_chart_is_anim_st(void);
extern void hmi_menu_chart_menu_rebuild(uint16_T);
extern void hmi_menu_fast_scroll_inactive(void);

#endif
#endif

