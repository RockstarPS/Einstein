/*
 * File: Ctrl_warning.h
 *
 * Code generated for Simulink model 'Ctrl_warning'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec  2 17:54:09 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Ctrl_warning_h_
#define RTW_HEADER_Ctrl_warning_h_
#ifndef Ctrl_warning_COMMON_INCLUDES_
# define Ctrl_warning_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_Ctrl_warning.h"
#endif                                 /* Ctrl_warning_COMMON_INCLUDES_ */

/* Includes for objects with custom storage classes. */
#include "Ctrl_warning_data.h"
#include "Ctrl_warning.cfg"
//#include "Ctrl_warning_Group_Priority.cfg"
#include "Rte_Type.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define BASE_DATA_TYPE                 8U
#define EXTD_PAYLOAD_AVBLSTS           1U
#define MASTER_LAMP_MASK               3U
#define RED                            2U
#define WRN_PAYLOAD_INITVAL            0U
#define YELLOW                         1U

/* Block signals (default storage) */
typedef struct tag_B_Ctrl_warning_T {
  WarningPayload_Type Selector1;       /* '<S16>/Selector1' */
} B_Ctrl_warning_T;

/* Block signals (default storage) */
extern VAR(B_Ctrl_warning_T, Ctrl_warning_VAR) Ctrl_warning_B;

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
 * '<Root>' : 'Ctrl_warning'
 * '<S1>'   : 'Ctrl_warning/Ctrl_warning_GetActiveWarningStatus'
 * '<S2>'   : 'Ctrl_warning/Ctrl_warning_GetWarningDisplayedPayload'
 * '<S3>'   : 'Ctrl_warning/Ctrl_warning_GetWarningDisplayedStatus'
 * '<S4>'   : 'Ctrl_warning/Ctrl_warning_Get_Red_MasterLamp_Status'
 * '<S5>'   : 'Ctrl_warning/Ctrl_warning_Get_Yellow_MasterLamp_Status'
 * '<S6>'   : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedPayload'
 * '<S7>'   : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedStatus'
 * '<S8>'   : 'Ctrl_warning/Ctrl_warning_Task_sys'
 * '<S9>'   : 'Ctrl_warning/Ctrl_warning_UpdateExtdPayload'
 * '<S10>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus'
 * '<S11>'  : 'Ctrl_warning/Ctrl_warning_Warning_Group_update'
 * '<S12>'  : 'Ctrl_warning/Ctrl_warning_GetActiveWarningStatus/Compare To Constant'
 * '<S13>'  : 'Ctrl_warning/Ctrl_warning_GetActiveWarningStatus/InvldWarning'
 * '<S14>'  : 'Ctrl_warning/Ctrl_warning_GetActiveWarningStatus/ValidWarning'
 * '<S15>'  : 'Ctrl_warning/Ctrl_warning_GetWarningDisplayedPayload/Compare To Constant1'
 * '<S16>'  : 'Ctrl_warning/Ctrl_warning_GetWarningDisplayedPayload/ValidWarnInvoked'
 * '<S17>'  : 'Ctrl_warning/Ctrl_warning_GetWarningDisplayedStatus/Compare To Constant'
 * '<S18>'  : 'Ctrl_warning/Ctrl_warning_Get_Red_MasterLamp_Status/Chart'
 * '<S19>'  : 'Ctrl_warning/Ctrl_warning_Get_Yellow_MasterLamp_Status/Chart'
 * '<S20>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedPayload/Compare To Constant'
 * '<S21>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedPayload/ValidPayload'
 * '<S22>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedStatus/Compare To Constant'
 * '<S23>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedStatus/StatusofValidWarningID'
 * '<S24>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedStatus/StatusofValidWarningID/Compare To Constant'
 * '<S25>'  : 'Ctrl_warning/Ctrl_warning_SetWarningDisplayedStatus/StatusofValidWarningID/If Action Subsystem'
 * '<S26>'  : 'Ctrl_warning/Ctrl_warning_Task_sys/InputHarness'
 * '<S27>'  : 'Ctrl_warning/Ctrl_warning_Task_sys/InputHarness/CodeGeneration'
 * '<S28>'  : 'Ctrl_warning/Ctrl_warning_UpdateExtdPayload/Compare To Constant'
 * '<S29>'  : 'Ctrl_warning/Ctrl_warning_UpdateExtdPayload/VldWarnId'
 * '<S30>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/Compare To Constant'
 * '<S31>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties'
 * '<S32>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates'
 * '<S33>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus'
 * '<S34>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates'
 * '<S35>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/Compare To Constant'
 * '<S36>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/EventNone'
 * '<S37>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/EventUpdate'
 * '<S38>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/EventUpdate/Compare To Constant'
 * '<S39>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/EventUpdate/Compare To Constant1'
 * '<S40>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/EventUpdates/EventUpdate/UpdateEvent'
 * '<S41>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/Compare To Constant'
 * '<S42>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp'
 * '<S43>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/Compare To Constant'
 * '<S44>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/Compare To Constant1'
 * '<S45>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateRedLamp'
 * '<S46>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateYellowLamp'
 * '<S47>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateRedLamp/Compare To Constant'
 * '<S48>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateRedLamp/Compare To Constant1'
 * '<S49>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateYellowLamp/Compare To Constant'
 * '<S50>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/MasterLampStatus/SetMasterWarningLamp/UpdateYellowLamp/Compare To Constant1'
 * '<S51>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/ClearPayload'
 * '<S52>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/Compare To Constant'
 * '<S53>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate'
 * '<S54>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/Compare To Constant2'
 * '<S55>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload'
 * '<S56>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift'
 * '<S57>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift1'
 * '<S58>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift2'
 * '<S59>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift/bit_shift'
 * '<S60>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift1/bit_shift'
 * '<S61>'  : 'Ctrl_warning/Ctrl_warning_UpdateWarningStatus/UpdateWarningProperties/Payloadpdates/PayloadUpdate/UpdateRecdPayload/Bit Shift2/bit_shift'
 */
#endif                                 /* RTW_HEADER_Ctrl_warning_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
