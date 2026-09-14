/*
 * Stateflow code generation for machine:
 *    hmi_view_manager_02
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 03-Sep-2015 18:05:29
 */

#ifndef __hmi_view_manager_02_autocode_h__
#define __hmi_view_manager_02_autocode_h__

#include "tmwtypes.h"

/* Custom Code from Simulation Target dialog*/
#include "hmi_logic_state_handler.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                      (MAX_uint8_T)

/* Variable Declarations */
extern uint8_T _sfEvent_hmi_view_manager_02_;

/* Variable Definitions */

/* Function Declarations */
void hmi_view_manager_02_initializer(void);
void hmi_view_manager_02_terminator(void);

/* Function Definitions */

#if 0
/* Global functions exported by all charts */
extern void hmi_vm_add_state(uint16_T,uint8_T);
extern boolean_T hmi_vm_animation_active_status(void);
extern void hmi_vm_animation_completed(void);
extern void hmi_vm_check_deactivation(void);
extern void hmi_vm_focus(uint16_T,uint8_T);
extern void hmi_vm_force_presentation(void);
extern void hmi_vm_remove_state(uint16_T,uint8_T);
extern void hmi_vm_tick(void);
#endif

#endif

