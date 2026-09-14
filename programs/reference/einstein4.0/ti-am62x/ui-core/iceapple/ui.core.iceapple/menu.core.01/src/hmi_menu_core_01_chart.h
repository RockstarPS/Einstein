/*
 * Stateflow code generation for chart:
 *    hmi_menu_core_01_model/hmi_menu_core_01_chart
 * 
 * Target Name                          : autocode
 * Stateflow Version                    : 6.7.0.14.00.0.000001
 * Date of code generation              : 12-Oct-2015 12:40:30
 */

#ifndef __hmi_menu_core_01_chart_h__
#define __hmi_menu_core_01_chart_h__

/* Type Definitions */

typedef struct {
  uint16_T l_btn_cmd_U16;
  uint16_T l_menu_action_output_U16;
  uint8_T l_get_btn_result_U8;
  uint8_T l_menu_action_U8;
  uint8_T l_menu_id_U8;
  uint8_T l_menu_state;
  uint8_T l_repeat_count;
  uint_T is_HMI_MENU_LOGIC_ST : 3;
  uint_T is_HMI_MENU_ANIM_ST : 2;
  uint_T is_HMI_MENU_FAST_SCROLL_ST : 2;
  uint_T is_HMI_MENU_WAIT_ACTIVE_ST : 2;
  uint_T is_HMI_MENU_WAIT_ST : 2;
  uint_T fast_scroll_active : 1;
  uint_T fast_scroll_active_rel : 1;
  uint_T l_btn_rel_in_fast_scroll : 1;
  uint_T l_btn_status_BOOL : 1;
  uint_T is_active_HMI_MENU_ANIM_ST : 1;
  uint_T is_active_HMI_MENU_FAST_SCROLL_ST : 1;
  uint_T is_active_HMI_MENU_LOGIC_ST : 1;
} SFhmi_menu_core_01_chartInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
void initialize_hmi_menu_core_01_chart(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_core_01_chart(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_Menu_FSTimeout(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
uint8_T hmi_menu_chart_FS_btn_result(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
boolean_T hmi_menu_chart_is_FS_st(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_anim_started(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_close(SFhmi_menu_core_01_chartInstanceStruct *chartInstance);
void hmi_menu_chart_Menu_open(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_id_U8, uint16_T p_cb_return_val_U16);
void hmi_menu_chart_FS_Btn_process(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_ID_U8, uint16_T p_button_cmd_U16);
void hmi_menu_chart_DataAvailable(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_anim_exit(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_Wait_temp_timeout(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_fast_scroll_inactive(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
void hmi_menu_chart_menu_rebuild(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint16_T fl_menu_cb_output_U16);
boolean_T hmi_menu_chart_is_anim_st(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance);
uint8_T hmi_menu_chart_Btn_trigger(SFhmi_menu_core_01_chartInstanceStruct
 *chartInstance, uint8_T p_menu_ID_U8, uint8_T p_menu_btn_action_U8, uint8_T
 p_menu_state);

/* Function Definitions */

#endif

