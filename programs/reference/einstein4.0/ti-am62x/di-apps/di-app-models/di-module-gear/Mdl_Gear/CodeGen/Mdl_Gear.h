/*
 * File: Mdl_Gear.h
 *
 * Code generated for Simulink model 'Mdl_Gear'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Aug 21 15:02:45 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_Gear_h_
#define Mdl_Gear_h_
#ifndef Mdl_Gear_COMMON_INCLUDES_
#define Mdl_Gear_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_Gear.h"
#endif                                 /* Mdl_Gear_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Mdl_Gear_config.cfg"
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define GEAR_MODE_OFF                  0U                        /* Referenced by: '<S15>/Display Blink Effect Determination' */
#define GEAR_STATUS_OFF                0U                        /* Referenced by:
                                                                  * '<S10>/Constant2'
                                                                  * '<S14>/Constant'
                                                                  * '<S14>/Constant1'
                                                                  * '<S14>/Constant3'
                                                                  * '<S14>/Constant4'
                                                                  * '<S14>/Constant5'
                                                                  * '<S14>/Constant6'
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  */
#define GEAR_STATUS_ON                 1U                        /* Referenced by: '<S15>/Determination of Shift Position and Shift Mode and Gear Step' */
#define HMI_READY                      1U                        /* Referenced by: '<S7>/Constant' */
#define IND_FLASH_1HZ                  6U                        /* Referenced by: '<S15>/Display Blink Effect Determination' */
#define IND_FLASH_4HZ                  15U                       /* Referenced by: '<S15>/Display Blink Effect Determination' */
#define IND_TURN_OFF                   0U                        /* Referenced by:
                                                                  * '<S14>/Constant2'
                                                                  * '<S15>/Display Blink Effect Determination'
                                                                  */
#define Init_Count                     0U                        /* Referenced by: '<S11>/Unit Delay' */
#define PGM_LOGIC_ENABLE               0U                        /* Referenced by: '<S15>/Constant3' */
#define STATUS_OFF                     0U                        /* Referenced by:
                                                                  * '<S11>/Constant6'
                                                                  * '<S15>/Determination of Shift Down'
                                                                  * '<S15>/Determination of Shift Up'
                                                                  * '<S15>/Gear Step Determination'
                                                                  * '<S15>/Output of GUI_SHIFT_TYPE'
                                                                  * '<S15>/Shift Position Determination'
                                                                  * '<S15>/Constant1'
                                                                  * '<S21>/Constant'
                                                                  */
#define STATUS_ON                      1U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Down'
                                                                  * '<S15>/Determination of Shift Up'
                                                                  * '<S15>/Output of GUI_SHIFT_TYPE'
                                                                  * '<S15>/Constant'
                                                                  * '<S19>/Constant'
                                                                  */
#define Shift_Blink_P1                 1U                        /* Referenced by: '<S15>/Display Blink Effect Determination' */
#define Shift_Blink_P2                 2U                        /* Referenced by: '<S15>/Display Blink Effect Determination' */
#define Shift_PosInd_M                 112U                      /* Referenced by: '<S15>/Determination of Shift Position and Shift Mode and Gear Step' */
#define Shift_PosInd_S                 128U                      /* Referenced by: '<S15>/Determination of Shift Position and Shift Mode and Gear Step' */
#define Shift_Pos_RANGE_B              5U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_D              4U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_M              6U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_N              3U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_P              1U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_R              2U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_S              7U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define Shift_Pos_RANGE_SD             8U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Position and Shift Mode and Gear Step'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define TYPE1                          1U                        /* Referenced by: '<S15>/Output of GUI_SHIFT_TYPE' */
#define TYPE1_SBW                      1U                        /* Referenced by:
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  * '<S20>/Shift Position Up Down CAN Signal Determination'
                                                                  */
#define TYPE2                          2U                        /* Referenced by: '<S15>/Output of GUI_SHIFT_TYPE' */
#define TYPE2_MECH                     0U                        /* Referenced by:
                                                                  * '<S4>/Constant'
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  */
#define TYPE3                          3U                        /* Referenced by: '<S15>/Output of GUI_SHIFT_TYPE' */
#define Timer_Param                    300U                      /* Referenced by: '<S11>/Constant3' */
#define VALUE_EIGHT                    8U                        /* Referenced by: '<S15>/Shift Position Determination' */
#define VALUE_FIFTEEN                  15U                       /* Referenced by:
                                                                  * '<S15>/Determination of Shift Down'
                                                                  * '<S15>/Determination of Shift Up'
                                                                  * '<S15>/Gear Step Determination'
                                                                  * '<S15>/Output of GUI_SHIFT_TYPE'
                                                                  */
#define VALUE_FIVE                     5U                        /* Referenced by:
                                                                  * '<S15>/Output of GUI_SHIFT_TYPE'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define VALUE_FOUR                     4U                        /* Referenced by: '<S15>/Shift Position Determination' */
#define VALUE_ONE                      1U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Up'
                                                                  * '<S15>/Gear Step Determination'
                                                                  * '<S15>/Output of GUI_SHIFT_TYPE'
                                                                  * '<S15>/Shift Position Determination'
                                                                  * '<S15>/Constant2'
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  */
#define VALUE_SEVEN                    7U                        /* Referenced by: '<S15>/Shift Position Determination' */
#define VALUE_SIX                      6U                        /* Referenced by: '<S15>/Shift Position Determination' */
#define VALUE_TEN                      10U                       /* Referenced by:
                                                                  * '<S15>/Gear Step Determination'
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  */
#define VALUE_THREE                    3U                        /* Referenced by: '<S15>/Shift Position Determination' */
#define VALUE_TWO                      2U                        /* Referenced by:
                                                                  * '<S15>/Determination of Shift Down'
                                                                  * '<S15>/Shift Position Determination'
                                                                  */
#define VALUE_ZERO                     0U                        /* Referenced by:
                                                                  * '<S15>/Gear Step Determination'
                                                                  * '<S20>/Gear Step CAN signal Determination'
                                                                  */

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  SShiftPosIndStatus ShiftPosIndStatusData_creator2;
                                    /* '<S10>/ShiftPosIndStatusData_creator2' */
  SShiftPosIndStatus pp_Shiftpos_ShiftPosIndStatus_S;
              /* '<Root>/pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData' */
  uint16 Add;                          /* '<S19>/Add' */
  uint16 per_check_delay;              /* '<S11>/Unit Delay1' */
  uint8 DataTypeConversion;            /* '<S10>/Data Type Conversion' */
  uint8 l_300ms_count;                 /* '<S11>/Unit Delay' */
  uint8 Prev_Shift_Position;           /* '<S15>/Unit Delay' */
  uint8 Prev_Gear_Step;                /* '<S15>/Unit Delay1' */
  uint8 Prev_Shift_Down_Ind;           /* '<S15>/Unit Delay4' */
  uint8 Prev_Shift_Up_Ind;             /* '<S15>/Unit Delay3' */
  uint8 Prev_Shift_Blink_pattern;      /* '<S15>/Unit Delay2' */
} ARID_DEF_Mdl_Gear_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_Mdl_Gear_T, Mdl_Gear_VAR_INIT) Mdl_Gear_ARID_DEF;

/* '<S10>/ShiftPosIndStatusData_creator2' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Unit Delay5' : Unused code path elimination
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Mdl_Gear'
 * '<S1>'   : 'Mdl_Gear/Mdl_Gear_Task_sys'
 * '<S2>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/InputHarness'
 * '<S3>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/OutputHarness'
 * '<S4>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem'
 * '<S5>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/InputHarness/CodeGeneration'
 * '<S6>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/OutputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Compare To Constant'
 * '<S8>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Compare To Constant1'
 * '<S9>'   : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Compare To Constant2'
 * '<S10>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1'
 * '<S11>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/300ms_Check'
 * '<S12>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Compare To Constant1'
 * '<S13>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Compare To Constant2'
 * '<S14>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/If Action Subsystem1'
 * '<S15>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem'
 * '<S16>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/300ms_Check/Compare To Constant1'
 * '<S17>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/300ms_Check/Compare To Constant2'
 * '<S18>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/300ms_Check/Compare To Constant3'
 * '<S19>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/300ms_Check/If Action Subsystem'
 * '<S20>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/CAN Signal Determination for Shift Type'
 * '<S21>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Compare To Constant'
 * '<S22>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Determination of Shift Down'
 * '<S23>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Determination of Shift Position and Shift Mode and Gear Step'
 * '<S24>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Determination of Shift Up'
 * '<S25>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Display Blink Effect Determination'
 * '<S26>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Gear Step Determination'
 * '<S27>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Output of GUI_SHIFT_TYPE'
 * '<S28>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/Shift Position Determination'
 * '<S29>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/CAN Signal Determination for Shift Type/Gear Step CAN signal Determination'
 * '<S30>'  : 'Mdl_Gear/Mdl_Gear_Task_sys/Subsystem/Subsystem1/Subsystem/CAN Signal Determination for Shift Type/Shift Position Up Down CAN Signal Determination'
 */
#endif                                 /* Mdl_Gear_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
