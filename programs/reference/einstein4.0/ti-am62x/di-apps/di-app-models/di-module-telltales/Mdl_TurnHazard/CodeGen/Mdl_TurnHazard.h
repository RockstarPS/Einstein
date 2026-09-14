/*
 * File: Mdl_TurnHazard.h
 *
 * Code generated for Simulink model 'Mdl_TurnHazard'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 31 15:42:58 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_TurnHazard_h_
#define Mdl_TurnHazard_h_
#ifndef Mdl_TurnHazard_COMMON_INCLUDES_
#define Mdl_TurnHazard_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_TurnHazard.h"
#endif                                 /* Mdl_TurnHazard_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define cTH_ONE                        1U                        /* Referenced by: '<S9>/Truth Table' */
#define cTH_THREE                      3U                        /* Referenced by: '<S9>/Truth Table' */
#define cTH_TWO                        2U                        /* Referenced by: '<S9>/Truth Table' */

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
 * '<Root>' : 'Mdl_TurnHazard'
 * '<S1>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys'
 * '<S2>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/InputHarness'
 * '<S3>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/OutputHarness'
 * '<S4>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/Telltale_Logic'
 * '<S5>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/InputHarness/CodeGeneration'
 * '<S6>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/OutputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/Telltale_Logic/Compare To Constant2'
 * '<S8>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/Telltale_Logic/If Action Subsystem1'
 * '<S9>'   : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/Telltale_Logic/TT_LOGIC'
 * '<S10>'  : 'Mdl_TurnHazard/Mdl_TurnHazard_Task_sys/Telltale_Logic/TT_LOGIC/Truth Table'
 */
#endif                                 /* Mdl_TurnHazard_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
