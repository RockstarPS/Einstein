/*
 * File: Mdl_Dim.h
 *
 * Code generated for Simulink model 'Mdl_Dim'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Aug 27 01:26:00 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Mdl_Dim_h_
#define Mdl_Dim_h_
#ifndef Mdl_Dim_COMMON_INCLUDES_
#define Mdl_Dim_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Mdl_Dim.h"
#endif                                 /* Mdl_Dim_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes */
#include "Rte_Type.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define DEFAULT_MODE                   0U                        /* Referenced by: '<S4>/Constant3' */
#define DEFAULT_STEP                   4U                        /* Referenced by: '<S4>/Constant4' */
#define STATUS_OFF                     0U                        /* Referenced by: '<S4>/Constant2' */
#define STATUS_ON                      1U                        /* Referenced by:
                                                                  * '<S4>/Constant1'
                                                                  * '<S7>/Constant'
                                                                  */
#define SWITCHING_MECHANISM            0U                        /* Referenced by: '<S4>/Constant5' */
#define ZERO_VAL                       0U                        /* Referenced by:
                                                                  * '<S4>/Constant6'
                                                                  * '<S4>/Constant7'
                                                                  * '<S4>/Constant8'
                                                                  */

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  IllumCtrl_Ip pp_IllumCtrl_Ip_IllumCtrl_Ip_Da;
                                /* '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' */
} ARID_DEF_Mdl_Dim_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_Mdl_Dim_T, Mdl_Dim_VAR_INIT) Mdl_Dim_ARID_DEF;

/* '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S4>/Signal Copy7' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'Mdl_Dim'
 * '<S1>'   : 'Mdl_Dim/Mdl_Dim_Task_sys'
 * '<S2>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/InputHarness'
 * '<S3>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/OutputHarness'
 * '<S4>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem'
 * '<S5>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/InputHarness/CodeGeneration'
 * '<S6>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/OutputHarness/CodeGeneration'
 * '<S7>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant3'
 * '<S8>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant4'
 * '<S9>'   : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant5'
 * '<S10>'  : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant6'
 * '<S11>'  : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant7'
 * '<S12>'  : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant8'
 * '<S13>'  : 'Mdl_Dim/Mdl_Dim_Task_sys/Subsystem/Compare To Constant9'
 */
#endif                                 /* Mdl_Dim_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
