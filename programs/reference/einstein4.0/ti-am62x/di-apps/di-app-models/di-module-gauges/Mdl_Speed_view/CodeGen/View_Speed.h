/*
 * File: View_Speed.h
 *
 * Code generated for Simulink model 'View_Speed'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul  3 16:03:33 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef View_Speed_h_
#define View_Speed_h_
#ifndef View_Speed_COMMON_INCLUDES_
#define View_Speed_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_View_Speed.h"
#endif                                 /* View_Speed_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "View_Speed_config.cfg"
#include "Rte_Type.h"
#include "Rte_View_Speed.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define C_BLANK                        65535U                    /* Referenced by:
                                                                  * '<S20>/Constant1'
                                                                  * '<S21>/Constant'
                                                                  * '<S21>/Constant1'
                                                                  * '<S22>/Constant'
                                                                  * '<S27>/Constant'
                                                                  */
#define C_CANADA                       0U                        /* Referenced by: '<S13>/Toler_CAN_Output_Judgement' */
#define C_DEFAULT_TOLER_A_VALUE        63U                       /* Referenced by: '<S13>/Toler_CAN_Output_Judgement' */
#define C_DEFAULT_TOLER_B_VALUE        0U                        /* Referenced by: '<S13>/Toler_CAN_Output_Judgement' */
#define C_MCUID0256_VALUE              1036U                     /* Referenced by: '<Root>/Data Store Memory' */
#define C_MCUID0257_VALUE              2U                        /* Referenced by: '<Root>/Data Store Memory1' */
#define C_MCUID0260_VALUE              1028U                     /* Referenced by: '<Root>/Data Store Memory2' */
#define C_MCUID0261_VALUE              8U                        /* Referenced by: '<Root>/Data Store Memory3' */
#define C_MET_SPD_MIN_THRESHOLD        135U                      /* Referenced by: '<S34>/Constant' */
#define C_MEXICO                       2U                        /* Referenced by: '<S13>/Toler_CAN_Output_Judgement' */
#define C_SPEED_1KMPH                  100U                      /* Referenced by:
                                                                  * '<S9>/Truth Table'
                                                                  * '<S9>/Truth Table1'
                                                                  */
#define C_SPEED_2KMPH                  200U                      /* Referenced by:
                                                                  * '<S9>/Truth Table'
                                                                  * '<S9>/Truth Table1'
                                                                  */
#define C_SPEED_ZERO                   0U                        /* Referenced by:
                                                                  * '<S9>/Truth Table'
                                                                  * '<S9>/Truth Table1'
                                                                  * '<S28>/Constant7'
                                                                  */
#define C_USA                          1U                        /* Referenced by: '<S13>/Toler_CAN_Output_Judgement' */
#define IGN_TRAN_TIMER_MS              260U                      /* Referenced by: '<S9>/Constant18' */
#define RESOLUTION_100                 100U                      /* Referenced by:
                                                                  * '<S9>/Constant2'
                                                                  * '<S9>/Constant5'
                                                                  * '<S28>/Constant'
                                                                  * '<S28>/Constant8'
                                                                  * '<S37>/Constant8'
                                                                  * '<S38>/Constant8'
                                                                  */
#define VAL_ONE                        1U                        /* Referenced by: '<S38>/Constant1' */
#define cFACTOR                        2U                        /* Referenced by:
                                                                  * '<S13>/Constant2'
                                                                  * '<S13>/Constant3'
                                                                  * '<S29>/Constant2'
                                                                  * '<S30>/Constant2'
                                                                  */
#define cOFFSET                        940U                      /* Referenced by:
                                                                  * '<S29>/Constant1'
                                                                  * '<S30>/Constant1'
                                                                  */
#define eSP_ADR                        8U                        /* Referenced by: '<S11>/Constant8' */
#define eSP_CANADA                     0U                        /* Referenced by:
                                                                  * '<S11>/Constant2'
                                                                  * '<S13>/Toler_CAN_Output_Judgement'
                                                                  */
#define eSP_ECE                        9U                        /* Referenced by: '<S11>/Constant9' */
#define eSP_EUROPE                     5U                        /* Referenced by: '<S11>/Constant3' */
#define eSP_KOREA_FMVSS                6U                        /* Referenced by:
                                                                  * '<S11>/Constant6'
                                                                  * '<S13>/Toler_CAN_Output_Judgement'
                                                                  */
#define eSP_KOREA_UN_R                 7U                        /* Referenced by: '<S11>/Constant7' */
#define eSP_MEXICO_FMVSS               2U                        /* Referenced by:
                                                                  * '<S11>/Constant4'
                                                                  * '<S13>/Toler_CAN_Output_Judgement'
                                                                  */
#define eSP_MEXICO_UN_R                3U                        /* Referenced by: '<S11>/Constant5' */
#define eSP_UK                         4U                        /* Referenced by: '<S11>/Constant1' */
#define eSP_USA                        1U                        /* Referenced by:
                                                                  * '<S11>/Constant'
                                                                  * '<S13>/Toler_CAN_Output_Judgement'
                                                                  */

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint32 Igntran_timer_count;          /* '<S10>/Unit Delay2' */
  uint16 pp_SubDisplaySpeed_Value_SubDis;
                         /* '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal' */
  uint16 Prev_Speed_k;                 /* '<S9>/Unit Delay2' */
  uint16 Prev_Speed_m;                 /* '<S9>/Unit Delay1' */
  uint16 eMET_SPDOut;                  /* '<Root>/Data Store Memory4' */
  uint16 eTOLER_AOut;                  /* '<Root>/Data Store Memory5' */
  uint16 eTOLER_BOut;                  /* '<Root>/Data Store Memory6' */
  uint16 NVM_MCUID0256;                /* '<Root>/Data Store Memory' */
  uint16 NVM_MCUID0260;                /* '<Root>/Data Store Memory2' */
  uint8 Display_unit;                  /* '<S9>/Display_unit' */
  IgntionSubstateType PrevWUSIgnState1;/* '<S9>/Unit Delay5' */
  uint8 NVM_MCUID0257;                 /* '<Root>/Data Store Memory1' */
  uint8 NVM_MCUID0261;                 /* '<Root>/Data Store Memory3' */
} ARID_DEF_View_Speed_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_View_Speed_T, View_Speed_VAR_INIT) View_Speed_ARID_DEF;

/* '<S10>/Unit Delay2' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Constant5' : Unused code path elimination
 * Block '<S32>/Compare' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S28>/Constant1' : Unused code path elimination
 * Block '<S28>/Constant3' : Unused code path elimination
 * Block '<S28>/Divide1' : Unused code path elimination
 * Block '<S28>/Switch' : Unused code path elimination
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
 * '<Root>' : 'View_Speed'
 * '<S1>'   : 'View_Speed/View_Speed_Init'
 * '<S2>'   : 'View_Speed/View_Speed_Task_sys'
 * '<S3>'   : 'View_Speed/View_Speed_Task_sys/InputHarness'
 * '<S4>'   : 'View_Speed/View_Speed_Task_sys/OutputHarness'
 * '<S5>'   : 'View_Speed/View_Speed_Task_sys/Subsystem1'
 * '<S6>'   : 'View_Speed/View_Speed_Task_sys/InputHarness/CodeGeneration'
 * '<S7>'   : 'View_Speed/View_Speed_Task_sys/OutputHarness/CodeGeneration'
 * '<S8>'   : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem'
 * '<S9>'   : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1'
 * '<S10>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Debounce timer for Ignoring samples'
 * '<S11>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource'
 * '<S12>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/If Action Subsystem4'
 * '<S13>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem'
 * '<S14>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Truth Table'
 * '<S15>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Truth Table1'
 * '<S16>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/ADR_ECE'
 * '<S17>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/CANADA_EUROPE'
 * '<S18>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/MEXICO'
 * '<S19>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/USA_UK'
 * '<S20>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/ADR_ECE/If Action Subsystem'
 * '<S21>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/ADR_ECE/If Action Subsystem1'
 * '<S22>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/CANADA_EUROPE/If Action Subsystem'
 * '<S23>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/CANADA_EUROPE/If Action Subsystem1'
 * '<S24>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/MEXICO/If Action Subsystem'
 * '<S25>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/MEXICO/If Action Subsystem1'
 * '<S26>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/USA_UK/If Action Subsystem'
 * '<S27>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Display_Outputsource/USA_UK/If Action Subsystem1'
 * '<S28>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check'
 * '<S29>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/Subsystem'
 * '<S30>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/Subsystem1'
 * '<S31>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/Toler_CAN_Output_Judgement'
 * '<S32>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/Compare To Constant'
 * '<S33>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/Compare To Constant1'
 * '<S34>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/Compare To Constant2'
 * '<S35>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/Compare To Constant4'
 * '<S36>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/Compare To Constant5'
 * '<S37>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/If Action Subsystem'
 * '<S38>'  : 'View_Speed/View_Speed_Task_sys/Subsystem1/If Action Subsystem1/Subsystem/MET_SPD_Judgement_and_Resolution_Check/If Action Subsystem1'
 */
#endif                                 /* View_Speed_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
