/*
 * File: EcuAppM_StateMachine.h
 *
 * Code generated for Simulink model 'EcuAppM_StateMachine'.
 *
 * Model version                  : 9.3370
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul 10 15:21:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EcuAppM_StateMachine_h_
#define RTW_HEADER_EcuAppM_StateMachine_h_
#ifndef EcuAppM_StateMachine_COMMON_INCLUDES_
#define EcuAppM_StateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* EcuAppM_StateMachine_COMMON_INCLUDES_ */

#include <string.h>

/* Includes for objects with custom storage classes */
#include "EcuAppM.h"
#include "EcuAppM_Cfg.h"
#include "EcuAppM_internal.h"
#include "EcuAppM_Types.h"

/* user code (top of header file) */
#include "EcuAppM_CmdProcessing.h"

/* Block signals (default storage) */
typedef struct {
  EcuAppM_WakeupSourcesType EcuAppM_BufferedDataOutput;/* '<S20>/Bus Creator' */
} B_EcuAppM_StateMachine_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T EcuAppMActivationTimer;     /* '<S3>/EcuAppM_StateChart' */
  uint8_T is_c1_EcuAppM_StateMachine;  /* '<S3>/EcuAppM_StateChart' */
  uint8_T is_EcuAppM_GroupsMgmtState;  /* '<S3>/EcuAppM_StateChart' */
  uint8_T is_active_c1_EcuAppM_StateMachine;/* '<S3>/EcuAppM_StateChart' */
} DW_EcuAppM_StateMachine_T;

/* Block signals (default storage) */
extern B_EcuAppM_StateMachine_T EcuAppM_StateMachine_B;

/* Block states (default storage) */
extern DW_EcuAppM_StateMachine_T EcuAppM_StateMachine_DW;

/* Model entry point functions */
extern void EcuAppM_StateMachine_initialize(void);
extern void EcuAppM_StateMachine_step(void);
extern void EcuAppM_StateMachine_terminate(void);

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
 * '<Root>' : 'EcuAppM_StateMachine'
 * '<S1>'   : 'EcuAppM_StateMachine/InputHarness'
 * '<S2>'   : 'EcuAppM_StateMachine/OutputHarness'
 * '<S3>'   : 'EcuAppM_StateMachine/Subsystem'
 * '<S4>'   : 'EcuAppM_StateMachine/InputHarness/CodeGeneration'
 * '<S5>'   : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart'
 * '<S6>'   : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_BackupDataWrapper'
 * '<S7>'   : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_ClearWakeupReasonWrapper'
 * '<S8>'   : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_GroupsLifeCycleMgr.EcuAppM_FailSafeMechanismWrapper'
 * '<S9>'   : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupActivationCalloutWrapper'
 * '<S10>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupStateChangeRequestWrapper'
 * '<S11>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupStatusChangeCbkWrapper'
 * '<S12>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_GroupsLifeCycleMgr.EcuAppM_SafeGroupStateChangeRequestWrapper'
 * '<S13>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_OnNVMReadAllWrapper'
 * '<S14>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_OnPowerSeqStartWrapper'
 * '<S15>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_OnStartupWrapper'
 * '<S16>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_OnWakeupValidationWrapper'
 * '<S17>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_ProcessJobStatusWrapper.EcuAppM_ProcessJobStatusFunc'
 * '<S18>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_ReadWakeupSourcesConfigData'
 * '<S19>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_StartOfGroupsDeactivationWrapper'
 * '<S20>'  : 'EcuAppM_StateMachine/Subsystem/EcuAppM_StateChart/EcuAppM_ReadWakeupSourcesConfigData/EcuAppM_GetConfigData'
 */
#endif                                 /* RTW_HEADER_EcuAppM_StateMachine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
