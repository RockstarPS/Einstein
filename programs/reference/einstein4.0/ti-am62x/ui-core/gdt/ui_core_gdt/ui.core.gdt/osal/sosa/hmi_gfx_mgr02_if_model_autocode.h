/*
 * Stateflow code generation for machine:
 *    hmi_gfx_mgr02_if_model
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 19-Feb-2013 21:04:06
 */

#ifndef __hmi_gfx_mgr02_if_model_autocode_h__
#define __hmi_gfx_mgr02_if_model_autocode_h__

#include "tmwtypes.h"

/* Custom Code from Simulation Target dialog*/
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "sched.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                      (MAX_uint8_T)

/* Variable Declarations */
extern uint8_T _sfEvent_hmi_gfx_mgr02_if_model_;

/* Variable Definitions */

/* Function Declarations */
void hmi_gfx_mgr02_if_model_initializer(void);
void hmi_gfx_mgr02_if_model_terminator(void);

/* Function Definitions */

/* Global functions exported by all charts */
extern void Graphics_Task_Done(void);
extern void hmi_gfx_mgr02_if_KSTimedTask(void);
extern uint8_T hmi_gfx_mgr02_if_is_ready_to_sleep(void);
extern void hmi_gfx_mgr02_if_shutdown(uint8_T);
extern uint8_T hmi_gfx_mgr02_if_start(void);

#endif

