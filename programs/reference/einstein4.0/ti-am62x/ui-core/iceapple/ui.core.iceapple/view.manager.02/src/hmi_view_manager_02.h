/*
 * Stateflow code generation for chart:
 *    hmi_view_manager_02/hmi_view_manager_02
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 03-Sep-2015 18:05:29
 */

#ifndef __hmi_view_manager_02_h__
#define __hmi_view_manager_02_h__

/* Type Definitions */

typedef struct {
  uint16_T l_gfx_active_state_id;
  uint16_T l_logic_active_state_id;
  uint16_T p_logic_req_state_id;
  uint8_T l_gfx_active_anim_id;
  uint8_T l_gfx_deactivate_anim;
  uint8_T l_gfx_deactivate_flag;
  uint8_T l_gfx_presentation_state;
  uint8_T l_gfx_prev_focus;
  uint8_T l_logic_active_anim_id;
  uint8_T p_logic_req_anim_id;
  uint_T is_VM_GFX_ACTIVE_ST : 2;
  uint_T is_VM_GFX_NORMAL_RUN_ST : 2;
  uint_T is_VM_LOGIC_ST : 2;
  uint_T is_VM_PRESENTATION_ST : 2;
  uint_T is_active_VM_LOGIC_ST : 1;
  uint_T is_active_VM_PERIODIC_FOCUS_MONITOR_ST : 1;
  uint_T is_active_VM_PRESENTATION_ST : 1;
} SFhmi_view_manager_02InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
void initialize_hmi_view_manager_02(SFhmi_view_manager_02InstanceStruct
 *chartInstance);
void hmi_view_manager_02(SFhmi_view_manager_02InstanceStruct *chartInstance);
void hmi_vm_focus(SFhmi_view_manager_02InstanceStruct *chartInstance, uint16_T
 p_state_id, uint8_T p_focus);
void hmi_vm_tick(SFhmi_view_manager_02InstanceStruct *chartInstance);
void hmi_vm_check_deactivation(SFhmi_view_manager_02InstanceStruct
 *chartInstance);
void hmi_vm_animation_completed(SFhmi_view_manager_02InstanceStruct
 *chartInstance);
void hmi_vm_force_presentation(SFhmi_view_manager_02InstanceStruct
 *chartInstance);
void hmi_vm_add_state(SFhmi_view_manager_02InstanceStruct *chartInstance,
 uint16_T p_state_id, uint8_T p_anim_id);
void hmi_vm_remove_state(SFhmi_view_manager_02InstanceStruct *chartInstance,
 uint16_T p_state_id, uint8_T p_anim_id);
boolean_T hmi_vm_animation_active_status(SFhmi_view_manager_02InstanceStruct
 *chartInstance);

/* Function Definitions */

#endif

