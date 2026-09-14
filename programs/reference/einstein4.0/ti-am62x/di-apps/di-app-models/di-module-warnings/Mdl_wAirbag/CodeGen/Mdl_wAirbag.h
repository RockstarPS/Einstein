/*
 * File: Mdl_wAirbag.h
 *
 * Code generated for Simulink model 'Mdl_wAirbag'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Aug 12 13:22:52 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_wAirbag_h_
#define Mdl_wAirbag_h_
#ifndef Mdl_wAirbag_COMMON_INCLUDES_
#define Mdl_wAirbag_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_wAirbag.h"
#endif                                 /* Mdl_wAirbag_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define AIRBAG_SYSTEM_STAT_OFF         0U                        /* Referenced by:
                                                                  * '<S8>/Constant'
                                                                  * '<S9>/Truth Table'
                                                                  */
#define AIRBAG_SYSTEM_STAT_ON          1U                        /* Referenced by: '<S9>/Truth Table' */
#define CAN_AIRBAG_SIGN_ONE_VALUE      1U                        /* Referenced by: '<S9>/Truth Table' */

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
 * '<Root>' : 'Mdl_wAirbag'
 * '<S1>'   : 'Mdl_wAirbag/Mdl_wAirbag_Init'
 * '<S2>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys'
 * '<S3>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/InputHarness'
 * '<S4>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/OutputHarness'
 * '<S5>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/Subsystem'
 * '<S6>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/InputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/OutputHarness/CodeGeneration'
 * '<S8>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/Subsystem/If Action DefaultVal'
 * '<S9>'   : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/Subsystem/Subsystem'
 * '<S10>'  : 'Mdl_wAirbag/Mdl_wAirbag_Task_sys/Subsystem/Subsystem/Truth Table'
 */
#endif                                 /* Mdl_wAirbag_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
