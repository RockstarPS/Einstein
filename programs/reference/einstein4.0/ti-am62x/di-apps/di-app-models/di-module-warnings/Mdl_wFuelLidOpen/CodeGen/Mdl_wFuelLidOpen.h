/*
 * File: Mdl_wFuelLidOpen.h
 *
 * Code generated for Simulink model 'Mdl_wFuelLidOpen'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Aug 12 13:30:48 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_wFuelLidOpen_h_
#define Mdl_wFuelLidOpen_h_
#ifndef Mdl_wFuelLidOpen_COMMON_INCLUDES_
#define Mdl_wFuelLidOpen_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_wFuelLidOpen.h"
#endif                                 /* Mdl_wFuelLidOpen_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define FUEL_CAN_SIG_VAL_ONE           1U                        /* Referenced by: '<S9>/Truth Table' */
#define FUEL_PAYLOAD_INVALID_VALUE     0U                        /* Referenced by: '<S7>/Constant2' */

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
 * '<Root>' : 'Mdl_wFuelLidOpen'
 * '<S1>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Init'
 * '<S2>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys'
 * '<S3>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/InputHarness'
 * '<S4>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/OutputHarness'
 * '<S5>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/Subsystem'
 * '<S6>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/InputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/OutputHarness/CodeGeneration'
 * '<S8>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/Subsystem/Compare To Constant'
 * '<S9>'   : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/Subsystem/If Action Subsystem'
 * '<S10>'  : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/Subsystem/If Action Subsystem1'
 * '<S11>'  : 'Mdl_wFuelLidOpen/Mdl_wFuelLidOpen_Task_sys/Subsystem/If Action Subsystem/Truth Table'
 */
#endif                                 /* Mdl_wFuelLidOpen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
