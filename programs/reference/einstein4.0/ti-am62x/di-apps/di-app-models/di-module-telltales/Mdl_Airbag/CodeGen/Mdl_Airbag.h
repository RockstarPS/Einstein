/*
 * File: Mdl_Airbag.h
 *
 * Code generated for Simulink model 'Mdl_Airbag'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jul 25 11:22:54 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_Airbag_h_
#define Mdl_Airbag_h_
#ifndef Mdl_Airbag_COMMON_INCLUDES_
#define Mdl_Airbag_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_Airbag.h"
#endif                                 /* Mdl_Airbag_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CAN_AIRBAG_SIGN_ONE_VALUE      1U                        /* Referenced by: '<S4>/Truth Table' */
#define CAN_AIRBAG_SIGN_TWO_VALUE      2U                        /* Referenced by: '<S4>/Truth Table' */
#define CAN_AIRBAG_SIGN_ZERO_VALUE     0U                        /* Referenced by: '<S4>/Truth Table' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Mdl_Airbag'
 * '<S1>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys'
 * '<S2>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/InputHarness'
 * '<S3>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/OutputHarness'
 * '<S4>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/Subsystem'
 * '<S5>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/InputHarness/CodeGeneration'
 * '<S6>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/OutputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_Airbag/Mdl_Airbag_Task_sys/Subsystem/Truth Table'
 */
#endif                                 /* Mdl_Airbag_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
