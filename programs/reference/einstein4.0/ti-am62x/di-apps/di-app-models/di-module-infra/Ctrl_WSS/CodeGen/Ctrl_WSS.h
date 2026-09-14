/*
 * File: Ctrl_WSS.h
 *
 * Code generated for Simulink model 'Ctrl_WSS'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed May 25 19:32:51 2022
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Ctrl_WSS_h_
#define RTW_HEADER_Ctrl_WSS_h_
#ifndef Ctrl_WSS_COMMON_INCLUDES_
# define Ctrl_WSS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_Ctrl_WSS.h"
#endif                                 /* Ctrl_WSS_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "Rte_Type.h"
#include "Rte_Ctrl_WSS.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define ACCSTATUS_OFF                  0U
#define ACCSTATUS_ON                   1U
#define ACCSTATUS_ON_VAL               1U
#define BASTATUS_OFF                   0U
#define BASTATUS_ON                    1U
#define BASTATUS_ON_VAL                1U
#define BAOFSTATUS_OFF                 0U
#define BAOFSTATUS_ON                  1U
#define BAOFSTATUS_ON_VAL              1U
#define IGPSTATUS_OFF                  0U
#define IGPSTATUS_ON                   1U
#define IGPSTATUS_ON_VAL               1U



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
 * '<Root>' : 'Ctrl_WSS'
 * '<S1>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys'
 * '<S2>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/InputHarness'
 * '<S3>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/OutputHarness'
 * '<S4>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem'
 * '<S5>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/InputHarness/CodeGeneration'
 * '<S6>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/InputHarness/Simulation'
 * '<S7>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/OutputHarness/CodeGeneration'
 * '<S8>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/OutputHarness/Simulation'
 * '<S9>'   : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem/ACC_Status_Decision'
 * '<S10>'  : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem/BA_Status_Decision'
 * '<S11>'  : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem/Compare To Constant'
 * '<S12>'  : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem/Compare To Constant1'
 * '<S13>'  : 'Ctrl_WSS/Ctrl_WSS_Task_sys/Subsystem/IGP_Status_Decision'
 */
#endif                                 /* RTW_HEADER_Ctrl_WSS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
