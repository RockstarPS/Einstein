/*
 * File: EcuAppM_StateMachine.c
 *
 * Code generated for Simulink model 'EcuAppM_StateMachine'.
 *
 * Model version                  : 9.3406
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jan 22 20:11:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EcuAppM_StateMachine.h"
#include "rtwtypes.h"
#include "EcuAppM_Cfg.h"
#include "EcuAppM_Types.h"
#include "EcuAppM.h"
#include "EcuAppM_internal.h"
#include <string.h>

/* Named constants for Chart: '<S3>/EcuAppM_StateChart' */
#define EcuAppM_StateMachine_IN_EcuAppM_BackupDataState ((uint8_T)1U)
#define EcuAppM_StateMachine_IN_EcuAppM_EarlyWakeupValidationState ((uint8_T)1U)
#define EcuAppM_StateMachine_IN_EcuAppM_GroupsActivationState ((uint8_T)2U)
#define EcuAppM_StateMachine_IN_EcuAppM_GroupsDeactivationState ((uint8_T)3U)
#define EcuAppM_StateMachine_IN_EcuAppM_GroupsMgmtState ((uint8_T)2U)
#define EcuAppM_StateMachine_IN_EcuAppM_InitState ((uint8_T)3U)
#define EcuAppM_StateMachine_IN_EcuAppM_PreGroupActivationState ((uint8_T)4U)
#define EcuAppM_StateMachine_IN_EcuAppM_PreGroupDeactivationState ((uint8_T)5U)
#define EcuAppM_StateMachine_IN_EcuAppM_ReadDataState ((uint8_T)6U)
#define EcuAppM_StateMachine_IN_EcuAppM_SleepState ((uint8_T)7U)
#define EcuAppM_StateMachine_IN_EcuAppM_SleepTransientState ((uint8_T)8U)
#define EcuAppM_StateMachine_IN_EcuAppM_StartPowerDownSequenceState ((uint8_T)9U)
#define EcuAppM_StateMachine_IN_EcuAppM_StartPowerUpSequenceState ((uint8_T)10U)
#define EcuAppM_StateMachine_IN_EcuAppM_WakeupValidationState ((uint8_T)11U)
#define EcuAppM_StateMachine_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Block signals (default storage) */
B_EcuAppM_StateMachine_T EcuAppM_StateMachine_B;

/* Block states (default storage) */
DW_EcuAppM_StateMachine_T EcuAppM_StateMachine_DW;

/* Exported functions */
extern void EcuAppM_ProcessJobStatusWrapper(uint8_T b_state, uint8_T *status);
extern void EcuAppM_ClearWakeupReasonWrapper(void);
extern void EcuAppM_StartOfSleepTransientWrapper(void);
extern void EcuAppM_OnPowerSeqStartWrapper(uint8_T b_State);
extern void EcuAppM_ReadWakeupSourcesConfigData(uint32_T
  EcuAppM_BufferedWakeupSource_3, EcuAppM_WakeupSourcesType
  *EcuAppM_BufferedDataOutput);
extern void EcuAppM_OnWakeupValidationWrapper(uint32_T
  EcuAppM_BufferedWakeupSource_2);
extern void EcuAppM_GroupsDeactivationStatus(uint8_T From_groupid, uint8_T
  To_groupid, uint8_T *deactivationStatus);
extern void EcuAppM_IsGroupsActivationDeactivationAllowed(uint8_T
  *activationdeactivationAllowed);
extern void EcuAppM_GroupsLifeCycleMgr(uint8_T b_groupId);
extern void EcuAppM_ProcessGroupsDeactivation(uint8_T From_groupid, uint8_T
  To_groupid, uint8_T EarlyWakeupNecessity);
extern void EcuAppM_BackupDataWrapper(void);
extern void EcuAppM_StartOfGroupsDeactivationWrapper(void);
extern void EcuAppM_CheckActivationStatetimerExpiry(uint8_T
  *EcuAppM_IsActivationTimerExpired);
extern void EcuAppM_ProcessGroupsActivation(uint8_T From_groupid, uint8_T
  To_groupid);
extern void EcuAppM_OnStartupWrapper(uint32_T EcuAppM_BufferedWakeupSource_1);
extern void EcuAppM_IsPreGroupsActivated(uint8_T activationstage, uint8_T
  *activationstatus);
extern void EcuAppM_ProcessPreGroupsActivation(uint8_T activationstage);
extern void EcuAppM_OnNVMReadAllWrapper(uint32_T EcuAppM_BufferedWakeupSource_0);
static void EcuAppM_StartOfSleepTransientCallout(void);
static void EcuAppM_ClearWakeupReasonCallout(void);
static void EcuAppM_StartOfGroupsDeactivationCallout(void);
static void EcuAppM_OnStartupCallout(uint32_T rtu_EcuAppM_BufferedWakeupSource);
static void EcuAppM_OnNVMReadallCallout(uint32_T
  rtu_EcuAppM_BufferedWakeupSource);
static void EcuAppM_OnWakeupvalidationCallout(uint32_T
  rtu_EcuAppM_BufferedWakeupSource);
static void EcuAppM_BackupDataCallout(void);
static void EcuAppM_OnPowerSeqStartCallout(uint8_T rtu_State);
static void EcuAppM_ProcessJobStatusCallout(uint8_T rtu_state, uint8_T
  *rty_status);
static void EcuAppM_FailSafeMechanismCallout(uint8_T rtu_index, uint8_T
  rtu_status);
static void EcuAppM_GroupStateChangeRequestCallout(uint8_T rtu_groupId, uint8_T
  rtu_StateCmd, uint8_T *rty_EcuAppM_ReturnValue);
static void EcuAppM_SafeGroupStateChangeRequestCallout(uint8_T rtu_groupId,
  uint8_T rtu_StateCmd, uint8_T *rty_EcuAppM_ReturnValue);
static void EcuAppM_GroupStatusChangeCbkCallout(uint8_T rtu_index, uint8_T
  rtu_status);
static void EcuAppM_GroupActivationCalloutCallout(uint8_T rtu_unit8_t, uint8_T
  *rty_EcuAppM_GroupActivationAllowed);
static void EcuAppM_StateChart_Init(void);
static void EcuAppM_StateChart(void);

/* Forward declaration for local functions */
static void EcuAppM_StateMachine_EcuAppM_GroupsMgmtState(void);
static void EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState(void);

/* Output and update for function-call system: '<S5>/EcuAppM_StartOfSleepTransientWrapper' */
static void EcuAppM_StartOfSleepTransientCallout(void)
{
  EcuAppM_StartOfSleepTransient();
}

/* Output and update for function-call system: '<S5>/EcuAppM_ClearWakeupReasonWrapper' */
static void EcuAppM_ClearWakeupReasonCallout(void)
{
  EcuAppM_ClearWakeupSources();
}

/* Output and update for function-call system: '<S5>/EcuAppM_StartOfGroupsDeactivationWrapper' */
static void EcuAppM_StartOfGroupsDeactivationCallout(void)
{
  EcuAppM_StartOfGroupsDeactivation();
}

/* Output and update for function-call system: '<S5>/EcuAppM_OnStartupWrapper' */
static void EcuAppM_OnStartupCallout(uint32_T rtu_EcuAppM_BufferedWakeupSource)
{
  EcuAppM_OnStartup(rtu_EcuAppM_BufferedWakeupSource);
}

/* Output and update for function-call system: '<S5>/EcuAppM_OnNVMReadAllWrapper' */
static void EcuAppM_OnNVMReadallCallout(uint32_T
  rtu_EcuAppM_BufferedWakeupSource)
{
  EcuAppM_OnNVMReadAll(rtu_EcuAppM_BufferedWakeupSource);
}

/* Output and update for function-call system: '<S5>/EcuAppM_OnWakeupValidationWrapper' */
static void EcuAppM_OnWakeupvalidationCallout(uint32_T
  rtu_EcuAppM_BufferedWakeupSource)
{
  EcuAppM_OnWakeupValidation(rtu_EcuAppM_BufferedWakeupSource);
}

/* Output and update for function-call system: '<S5>/EcuAppM_BackupDataWrapper' */
static void EcuAppM_BackupDataCallout(void)
{
  EcuAppM_BackupData();
}

/* Output and update for function-call system: '<S5>/EcuAppM_OnPowerSeqStartWrapper' */
static void EcuAppM_OnPowerSeqStartCallout(uint8_T rtu_State)
{
  EcuAppM_OnPowerSeqStart(rtu_State);
}

/* Output and update for function-call system: '<S5>/EcuAppM_ProcessJobStatusWrapper.EcuAppM_ProcessJobStatusFunc' */
static void EcuAppM_ProcessJobStatusCallout(uint8_T rtu_state, uint8_T
  *rty_status)
{
  *rty_status = EcuAppM_ProcessJobStatus(rtu_state);
}

/* Output and update for function-call system: '<S5>/EcuAppM_GroupsLifeCycleMgr.EcuAppM_FailSafeMechanismWrapper' */
static void EcuAppM_FailSafeMechanismCallout(uint8_T rtu_index, uint8_T
  rtu_status)
{
  EcuAppM_FailSafeMechanism(rtu_index, rtu_status);
}

/* Output and update for function-call system: '<S5>/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupStateChangeRequestWrapper' */
static void EcuAppM_GroupStateChangeRequestCallout(uint8_T rtu_groupId, uint8_T
  rtu_StateCmd, uint8_T *rty_EcuAppM_ReturnValue)
{
  *rty_EcuAppM_ReturnValue = EcuAppM_GroupStateChangeRequestProcessing
    (rtu_groupId, rtu_StateCmd);
}

/* Output and update for function-call system: '<S5>/EcuAppM_GroupsLifeCycleMgr.EcuAppM_SafeGroupStateChangeRequestWrapper' */
static void EcuAppM_SafeGroupStateChangeRequestCallout(uint8_T rtu_groupId,
  uint8_T rtu_StateCmd, uint8_T *rty_EcuAppM_ReturnValue)
{
  *rty_EcuAppM_ReturnValue = EcuAppM_DispatchSafeGroupStateChangeRequest
    (rtu_groupId, rtu_StateCmd);
}

/* Output and update for function-call system: '<S5>/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupStatusChangeCbkWrapper' */
static void EcuAppM_GroupStatusChangeCbkCallout(uint8_T rtu_index, uint8_T
  rtu_status)
{
  EcuAppM_GroupStatusChangeCbk(rtu_index, rtu_status);
}

/* Output and update for function-call system: '<S5>/EcuAppM_GroupsLifeCycleMgr.EcuAppM_GroupActivationCalloutWrapper' */
static void EcuAppM_GroupActivationCalloutCallout(uint8_T rtu_unit8_t, uint8_T
  *rty_EcuAppM_GroupActivationAllowed)
{
  *rty_EcuAppM_GroupActivationAllowed = EcuAppM_GroupActivationCallout
    (rtu_unit8_t);
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ProcessJobStatusWrapper(uint8_T b_state, uint8_T *status)
{
  EcuAppM_ProcessJobStatusCallout(b_state, status);
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ClearWakeupReasonWrapper(void)
{
  EcuAppM_ClearWakeupReasonCallout();
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_StartOfSleepTransientWrapper(void)
{
  EcuAppM_StartOfSleepTransientCallout();
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_OnPowerSeqStartWrapper(uint8_T b_State)
{
  EcuAppM_OnPowerSeqStartCallout(b_State);
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ReadWakeupSourcesConfigData(uint32_T EcuAppM_BufferedWakeupSource_3,
  EcuAppM_WakeupSourcesType *EcuAppM_BufferedDataOutput)
{
  uint32_T tmp;
  uint16_T EcuAppM_Index_0;
  for (EcuAppM_Index_0 = 0U; EcuAppM_Index_0 < ECUAPPM_MAX_WAKEUP_SOURCES;
       EcuAppM_Index_0 = (uint16_T)(((uint32_T)EcuAppM_Index_0) + 1U)) {
    EcuAppM_Index = EcuAppM_Index_0;
    tmp = EcuAppM_WakeupSourcesData[EcuAppM_Index].wakeupMask;
    if ((tmp & EcuAppM_BufferedWakeupSource_3) != 0U) {
      wakeupMask = tmp;
      validationTime = EcuAppM_WakeupSourcesData[EcuAppM_Index].validationTime;
      wakeupReaction = EcuAppM_WakeupSourcesData[EcuAppM_Index].wakeupReaction;
    } else {
      wakeupMask = PrevwakeupMask;
      validationTime = PrevvalidationTime;
      wakeupReaction = PrevwakeupReaction;
    }

    EcuAppM_StateMachine_B.EcuAppM_BufferedDataOutput.wakeupMask = wakeupMask;
    EcuAppM_StateMachine_B.EcuAppM_BufferedDataOutput.validationTime =
      validationTime;
    EcuAppM_StateMachine_B.EcuAppM_BufferedDataOutput.wakeupReaction =
      wakeupReaction;
    PrevwakeupMask = wakeupMask;
    PrevvalidationTime = validationTime;
    PrevwakeupReaction = wakeupReaction;
  }

  *EcuAppM_BufferedDataOutput =
    EcuAppM_StateMachine_B.EcuAppM_BufferedDataOutput;
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_OnWakeupValidationWrapper(uint32_T EcuAppM_BufferedWakeupSource_2)
{
  EcuAppM_OnWakeupvalidationCallout(EcuAppM_BufferedWakeupSource_2);
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_GroupsDeactivationStatus(uint8_T From_groupid, uint8_T To_groupid,
  uint8_T *deactivationStatus)
{
  uint8_T b_groupId;
  b_groupId = From_groupid;
  *deactivationStatus = ECUAPPM_FALSE;
  while (b_groupId <= To_groupid) {
    if (((EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateInactive) ||
         (EcuAppM_GroupConfigData[b_groupId].deactivationType == KEEP_ALIVE)) ||
        (EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateOff)) {
      b_groupId += ECUAPPM_VALUE_ONE;
      *deactivationStatus = ECUAPPM_TRUE;
    } else {
      b_groupId = (uint8_T)((int32_T)(((int32_T)To_groupid) + 1));
      *deactivationStatus = ECUAPPM_FALSE;
    }
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_IsGroupsActivationDeactivationAllowed(uint8_T
  *activationdeactivationAllowed)
{
  uint8_T b_groupId;
  b_groupId = ECUAPPM_VALUE_ZERO;
  *activationdeactivationAllowed = ECUAPPM_FALSE;
  while (b_groupId < ECUAPPM_MAX_GROUPS) {
    if (((EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateActive) ||
         (EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateInactive)) ||
        (EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateOff)) {
      b_groupId += ECUAPPM_VALUE_ONE;
      *activationdeactivationAllowed = ECUAPPM_TRUE;
    } else {
      b_groupId = ECUAPPM_MAX_GROUPS;
      *activationdeactivationAllowed = ECUAPPM_FALSE;
    }
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_GroupsLifeCycleMgr(uint8_T b_groupId)
{
  uint8_T ReturnStatus;
  switch (EcuAppM_GroupsInfo.GroupState[(b_groupId)]) {
   case eGroup_StateOff:
    if ((EcuAppMInfo.State != eEcuAppM_GroupsDeactivation) && (EcuAppMInfo.State
         != eEcuAppM_PreGroupDeactivation)) {
      EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateInit;
    }
    break;

   case eGroup_StateInit:
    if (EcuAppM_GroupConfigData[b_groupId].safetyLevel > eSafetyLevel_QM) {
      EcuAppM_SafeGroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateInit, &ReturnStatus);
    } else {
      EcuAppM_GroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateInit, &ReturnStatus);
    }

    if (ReturnStatus == ECUAPPM_JOB_DONE) {
      EcuAppM_GroupStatusChangeCbkCallout(b_groupId, (uint8_T)
        EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = ECUAPPM_VALUE_ZERO;
      EcuAppM_GroupActivationCalloutCallout(b_groupId, &ReturnStatus);
      if (ReturnStatus == ECUAPPM_TRUE) {
        EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateActivation;
      } else {
        EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateInactive;
      }
    } else {
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = (uint16_T)
        (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] +
         ECUAPPM_PERIOD_MSEC);
      if (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] >=
          EcuAppM_GroupConfigData[b_groupId].failSafeTimeout) {
        EcuAppM_FailSafeMechanismCallout(b_groupId, (uint8_T)
          EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      }
    }
    break;

   case eGroup_StateActivation:
    if (EcuAppM_GroupConfigData[b_groupId].safetyLevel > eSafetyLevel_QM) {
      EcuAppM_SafeGroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateActivation, &ReturnStatus);
    } else {
      EcuAppM_GroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateActivation, &ReturnStatus);
    }

    if (ReturnStatus == ECUAPPM_JOB_DONE) {
      EcuAppM_GroupStatusChangeCbkCallout(b_groupId, (uint8_T)
        EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = ECUAPPM_VALUE_ZERO;
      EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateActive;
    } else {
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = (uint16_T)
        (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] +
         ECUAPPM_PERIOD_MSEC);
      if (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] >=
          EcuAppM_GroupConfigData[b_groupId].failSafeTimeout) {
        EcuAppM_FailSafeMechanismCallout(b_groupId, (uint8_T)
          EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      }
    }
    break;

   case eGroup_StateActive:
    if ((EcuAppMInfo.State == eEcuAppM_GroupsDeactivation) || (EcuAppMInfo.State
         == eEcuAppM_PreGroupDeactivation)) {
      EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateDeactivation;
    } else {
      EcuAppM_GroupActivationCalloutCallout(b_groupId, &ReturnStatus);
      if (ReturnStatus != ECUAPPM_TRUE) {
        EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateDeactivation;
      }
    }
    break;

   case eGroup_StateDeactivation:
    if (EcuAppM_GroupConfigData[b_groupId].safetyLevel > eSafetyLevel_QM) {
      EcuAppM_SafeGroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateDeactivation, &ReturnStatus);
    } else {
      EcuAppM_GroupStateChangeRequestCallout(b_groupId, (uint8_T)
        eGroup_StateDeactivation, &ReturnStatus);
    }

    if (ReturnStatus == ECUAPPM_JOB_DONE) {
      EcuAppM_GroupStatusChangeCbkCallout(b_groupId, (uint8_T)
        EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = ECUAPPM_VALUE_ZERO;
      EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateInactive;
    } else {
      EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = (uint16_T)
        (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] +
         ECUAPPM_PERIOD_MSEC);
      if (EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] >=
          EcuAppM_GroupConfigData[b_groupId].failSafeTimeout) {
        EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateInactive;
        EcuAppM_GroupsInfo.GroupActivityTimer[(b_groupId)] = ECUAPPM_VALUE_ZERO;
        EcuAppM_FailSafeMechanismCallout(b_groupId, (uint8_T)
          EcuAppM_GroupsInfo.GroupState[(b_groupId)]);
      }
    }
    break;

   case eGroup_StateInactive:
    if ((EcuAppMInfo.State != eEcuAppM_GroupsDeactivation) && (EcuAppMInfo.State
         != eEcuAppM_PreGroupDeactivation)) {
      EcuAppM_GroupActivationCalloutCallout(b_groupId, &ReturnStatus);
      if (ReturnStatus == ECUAPPM_TRUE) {
        EcuAppM_GroupsInfo.GroupState[(b_groupId)] = eGroup_StateActivation;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ProcessGroupsDeactivation(uint8_T From_groupid, uint8_T To_groupid,
  uint8_T EarlyWakeupNecessity)
{
  uint8_T b;
  uint8_T b_groupId;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  b_groupId = From_groupid;
  exitg1 = false;
  while (((exitg1 ? ((uint32_T)1U) : ((uint32_T)0U)) == false) && (b_groupId >=
          To_groupid)) {
    guard1 = false;
    guard2 = false;
    if (EcuAppM_GroupConfigData[b_groupId].deactivationType == SHUTDOWN) {
      if (WakeupEvent != ((uint32_T)ECUAPPM_NOWKPEVENT)) {
        EcuAppM_IsGroupsActivationDeactivationAllowed(&b);
        if (((ECUAPPM_TRUE == b) && (EcuAppM_BufferedWakeupData.wakeupReaction
              != ((uint16_T)PARTIAL))) && (EarlyWakeupNecessity == ECUAPPM_TRUE))
        {
          EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_TRUE;
          EcuAppM_BufferedWakeupSource = WakeupEvent;
          exitg1 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard2) {
      EcuAppM_GroupsLifeCycleMgr(b_groupId);
      if ((EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateInactive) ||
          (EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateOff)) {
        guard1 = true;
      } else {
        exitg1 = true;
      }
    }

    if (guard1) {
      if (b_groupId >= ECUAPPM_VALUE_ONE) {
        b_groupId -= ECUAPPM_VALUE_ONE;
      } else {
        exitg1 = true;
      }
    }
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_BackupDataWrapper(void)
{
  EcuAppM_BackupDataCallout();
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_StartOfGroupsDeactivationWrapper(void)
{
  EcuAppM_StartOfGroupsDeactivationCallout();
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_CheckActivationStatetimerExpiry(uint8_T
  *EcuAppM_IsActivationTimerExpired)
{
  if (ECUAPPM_MIN_GROUP_ACTIVE_TIME != ((uint16_T)ECUAPPM_VALUE_ZERO)) {
    if (EcuAppM_StateMachine_DW.EcuAppMActivationTimer >=
        ECUAPPM_MIN_GROUP_ACTIVE_TIME) {
      *EcuAppM_IsActivationTimerExpired = (uint8_T)TRUE;
      EcuAppM_StateMachine_DW.EcuAppMActivationTimer = 0U;
    } else {
      EcuAppM_StateMachine_DW.EcuAppMActivationTimer += ECUAPPM_PERIOD_MSEC;
      *EcuAppM_IsActivationTimerExpired = (uint8_T)FALSE;
    }
  } else {
    *EcuAppM_IsActivationTimerExpired = (uint8_T)TRUE;
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ProcessGroupsActivation(uint8_T From_groupid, uint8_T To_groupid)
{
  uint8_T b_groupId;
  boolean_T exitg1;
  b_groupId = From_groupid;
  while ((b_groupId <= To_groupid) && (ECUAPPM_GROUP_ACTIVATION_TYPE ==
          ASYNCHRONUS)) {
    if ((((uint32_T)EcuAppM_GroupConfigData[b_groupId].wakeupSourceMask) &
         EcuAppM_BufferedWakeupSource) == EcuAppM_BufferedWakeupSource) {
      EcuAppM_GroupsLifeCycleMgr(b_groupId);
      b_groupId += ECUAPPM_VALUE_ONE;
    } else {
      b_groupId += ECUAPPM_VALUE_ONE;
    }
  }

  exitg1 = false;
  while (((exitg1 ? ((uint32_T)1U) : ((uint32_T)0U)) == false) && ((b_groupId <=
           To_groupid) && (ECUAPPM_GROUP_ACTIVATION_TYPE == SYNCHRONUS))) {
    if (((((uint32_T)EcuAppM_GroupConfigData[b_groupId].wakeupSourceMask) &
          EcuAppM_BufferedWakeupSource) == EcuAppM_BufferedWakeupSource) &&
        (EcuAppM_GroupsInfo.GroupState[(b_groupId)] != eGroup_StateActive)) {
      EcuAppM_GroupsLifeCycleMgr(b_groupId);
      if (EcuAppM_GroupsInfo.GroupState[(b_groupId)] == eGroup_StateActive) {
        b_groupId += ECUAPPM_VALUE_ONE;
      } else {
        exitg1 = true;
      }
    } else {
      b_groupId += ECUAPPM_VALUE_ONE;
    }
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
static void EcuAppM_StateMachine_EcuAppM_GroupsMgmtState(void)
{
  uint8_T d;
  boolean_T guard1;
  boolean_T guard2;
  guard1 = false;
  guard2 = false;
  switch (EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState) {
   case EcuAppM_StateMachine_IN_EcuAppM_EarlyWakeupValidationState:
    /*   */
    if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_FAILED) ||
        (EcuAppM_WakeupValidationTimer >=
         EcuAppM_BufferedWakeupData.validationTime)) {
      EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
      EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
        EcuAppM_StateMachine_IN_EcuAppM_GroupsDeactivationState;
      EcuAppMInfo.State = eEcuAppM_GroupsDeactivation;
      EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_FALSE;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
      EcuAppM_ClearWakeupReasonWrapper();
      EcuAppM_StartOfGroupsDeactivationWrapper();
    } else if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) ||
               (EcuAppM_BufferedWakeupData.validationTime == ((uint16_T)
                 ECUAPPM_VALIDATION_TIME_ZERO))) {
      EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
      EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_FALSE;
      EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
        EcuAppM_StateMachine_IN_EcuAppM_GroupsActivationState;
      EcuAppMInfo.State = eEcuAppM_GroupsActivation;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
    } else {
      EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &d);
      EcuAppMInfo.CurrentJobStatus = d;
      EcuAppM_WakeupValidationTimer = (uint16_T)(EcuAppM_WakeupValidationTimer +
        ECUAPPM_PERIOD_MSEC);
    }
    break;

   case EcuAppM_StateMachine_IN_EcuAppM_GroupsActivationState:
    if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
      EcuAppM_CheckActivationStatetimerExpiry(&d);
      if (((int32_T)d) == TRUE) {
        EcuAppM_IsGroupsActivationDeactivationAllowed(&d);
        if ((d == ECUAPPM_TRUE) && (ApplicationSleepState ==
             ECUAPPM_READY_TO_SLEEP)) {
          EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
            EcuAppM_StateMachine_IN_EcuAppM_GroupsDeactivationState;
          EcuAppMInfo.State = eEcuAppM_GroupsDeactivation;
          EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_FALSE;
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
          EcuAppM_ClearWakeupReasonWrapper();
          EcuAppM_StartOfGroupsDeactivationWrapper();
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
    break;

   default:
    /* case IN_EcuAppM_GroupsDeactivationState: */
    if (EcuAppMInfo.EarlyWakeupCheck == ECUAPPM_TRUE) {
      EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_FALSE;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
      EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
        EcuAppM_StateMachine_IN_EcuAppM_EarlyWakeupValidationState;
      EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
      EcuAppMInfo.State = eEcuAppM_WakeupValidation;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
      EcuAppM_ReadWakeupSourcesConfigData(EcuAppM_BufferedWakeupSource,
        &EcuAppM_BufferedWakeupData);
      EcuAppM_OnWakeupValidationWrapper(EcuAppM_BufferedWakeupSource);
      EcuAppM_ClearWakeupReasonWrapper();
    } else if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
      EcuAppM_GroupsDeactivationStatus(ECUAPPM_GROUP2, (uint8_T)
        (ECUAPPM_MAX_GROUPS - ECUAPPM_VALUE_ONE), &d);
      if (d == ECUAPPM_TRUE) {
        EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_FALSE;
        EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
          EcuAppM_StateMachine_IN_NO_ACTIVE_CHILD;
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_BackupDataState;
        EcuAppMInfo.State = eEcuAppM_BackupData;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_BackupDataWrapper();
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    break;
  }

  if (guard2) {
    EcuAppM_ProcessGroupsActivation(ECUAPPM_GROUP2, (uint8_T)(ECUAPPM_MAX_GROUPS
      - ECUAPPM_VALUE_ONE));
    EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &d);
    EcuAppMInfo.CurrentJobStatus = d;
  }

  if (guard1) {
    EcuAppM_ProcessGroupsDeactivation((uint8_T)(ECUAPPM_MAX_GROUPS -
      ECUAPPM_VALUE_ONE), ECUAPPM_GROUP2, 1);
    EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &d);
    EcuAppMInfo.CurrentJobStatus = d;
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_OnStartupWrapper(uint32_T EcuAppM_BufferedWakeupSource_1)
{
  EcuAppM_OnStartupCallout(EcuAppM_BufferedWakeupSource_1);
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_IsPreGroupsActivated(uint8_T activationstage, uint8_T
  *activationstatus)
{
  uint8_T pregrp0Index;
  uint8_T pregrp1Index;
  *activationstatus = 0U;
  pregrp0Index = ECUAPPM_VALUE_ZERO;
  pregrp1Index = ECUAPPM_VALUE_ZERO;
  while ((activationstage == PRE_GROUP0) && (pregrp0Index <
          ECUAPPM_PREGROUP0_MAX_ELEMENTS)) {
    if (EcuAppM_PreGroup0Elements[(pregrp0Index)] < ECUAPPM_MAX_GROUPS) {
      if ((((uint32_T)EcuAppM_GroupConfigData[EcuAppM_PreGroup0Elements
            [(pregrp0Index)]].wakeupSourceMask) & EcuAppM_BufferedWakeupSource) ==
          EcuAppM_BufferedWakeupSource) {
        if (EcuAppM_GroupsInfo.GroupState[(EcuAppM_PreGroup0Elements
             [(pregrp0Index)])] == eGroup_StateActive) {
          pregrp0Index += ECUAPPM_VALUE_ONE;
          *activationstatus = ECUAPPM_TRUE;
        } else {
          pregrp0Index = ECUAPPM_PREGROUP0_MAX_ELEMENTS;
          *activationstatus = ECUAPPM_FALSE;
        }
      } else {
        pregrp0Index += ECUAPPM_VALUE_ONE;
        *activationstatus = ECUAPPM_TRUE;
      }
    } else {
      pregrp0Index += ECUAPPM_VALUE_ONE;
      *activationstatus = ECUAPPM_TRUE;
    }
  }

  while ((activationstage == PRE_GROUP1) && (pregrp1Index <
          ECUAPPM_PREGROUP1_MAX_ELEMENTS)) {
    if (EcuAppM_PreGroup1Elements[(pregrp0Index)] < ECUAPPM_MAX_GROUPS) {
      if ((((uint32_T)EcuAppM_GroupConfigData[EcuAppM_PreGroup1Elements
            [(pregrp0Index)]].wakeupSourceMask) & EcuAppM_BufferedWakeupSource) ==
          EcuAppM_BufferedWakeupSource) {
        if (EcuAppM_GroupsInfo.GroupState[(EcuAppM_PreGroup1Elements
             [(pregrp0Index)])] == eGroup_StateActive) {
          pregrp1Index += ECUAPPM_VALUE_ONE;
          *activationstatus = ECUAPPM_TRUE;
        } else {
          pregrp1Index = ECUAPPM_PREGROUP1_MAX_ELEMENTS;
          *activationstatus = ECUAPPM_FALSE;
        }
      } else {
        pregrp1Index += ECUAPPM_VALUE_ONE;
        *activationstatus = ECUAPPM_TRUE;
      }
    } else {
      pregrp1Index += ECUAPPM_VALUE_ONE;
      *activationstatus = ECUAPPM_TRUE;
    }
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_ProcessPreGroupsActivation(uint8_T activationstage)
{
  uint8_T pregrp0Index;
  uint8_T pregrp1Index;
  pregrp0Index = ECUAPPM_VALUE_ZERO;
  pregrp1Index = ECUAPPM_VALUE_ZERO;
  while ((activationstage == PRE_GROUP0) && (pregrp0Index <
          ECUAPPM_PREGROUP0_MAX_ELEMENTS)) {
    if (EcuAppM_PreGroup0Elements[(pregrp0Index)] < ECUAPPM_MAX_GROUPS) {
      if ((((uint32_T)EcuAppM_GroupConfigData[EcuAppM_PreGroup0Elements
            [(pregrp0Index)]].wakeupSourceMask) & EcuAppM_BufferedWakeupSource) ==
          EcuAppM_BufferedWakeupSource) {
        EcuAppM_GroupsLifeCycleMgr(EcuAppM_PreGroup0Elements[(pregrp0Index)]);
      }
    }

    pregrp0Index += ECUAPPM_VALUE_ONE;
  }

  while ((activationstage == PRE_GROUP1) && (pregrp1Index <
          ECUAPPM_PREGROUP1_MAX_ELEMENTS)) {
    if (EcuAppM_PreGroup1Elements[(pregrp1Index)] < ECUAPPM_MAX_GROUPS) {
      if ((((uint32_T)EcuAppM_GroupConfigData[EcuAppM_PreGroup1Elements
            [(pregrp1Index)]].wakeupSourceMask) & EcuAppM_BufferedWakeupSource) ==
          EcuAppM_BufferedWakeupSource) {
        EcuAppM_GroupsLifeCycleMgr(EcuAppM_PreGroup1Elements[(pregrp1Index)]);
      }
    }

    pregrp1Index += ECUAPPM_VALUE_ONE;
  }
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
static void EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState(void)
{
  EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
    EcuAppM_StateMachine_IN_EcuAppM_GroupsActivationState;
  EcuAppMInfo.State = eEcuAppM_GroupsActivation;
  EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
}

/* Function for Chart: '<S3>/EcuAppM_StateChart' */
void EcuAppM_OnNVMReadAllWrapper(uint32_T EcuAppM_BufferedWakeupSource_0)
{
  EcuAppM_OnNVMReadallCallout(EcuAppM_BufferedWakeupSource_0);
}

/* System initialize for atomic system: '<S3>/EcuAppM_StateChart' */
static void EcuAppM_StateChart_Init(void)
{
  int32_T i;
  EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
    EcuAppM_StateMachine_IN_NO_ACTIVE_CHILD;
  EcuAppM_StateMachine_DW.is_active_c1_EcuAppM_StateMachine = 0U;
  EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
    EcuAppM_StateMachine_IN_NO_ACTIVE_CHILD;
  for (i = 0; i < 2; i++) {
    EcuAppM_GroupsInfo.GroupState[(i)] = eGroup_StateOff;
    EcuAppM_GroupsInfo.GroupActivityTimer[(i)] = 0U;
    EcuAppM_GroupsInfo.GroupCurrentActivity[(i)] = 0U;
  }

  EcuAppM_BufferedWakeupData.wakeupMask = 0U;
  EcuAppM_BufferedWakeupData.validationTime = 0U;
  EcuAppM_BufferedWakeupData.wakeupReaction = 0U;
  EcuAppM_StateMachine_DW.EcuAppMActivationTimer = 0U;
  EcuAppMInfo.State = eEcuAppM_Init;
  EcuAppMInfo.CurrentJobStatus = 0U;
  EcuAppMInfo.EarlyWakeupCheck = 0U;
  PrevwakeupMask = ECUAPPM_VALUE_ZERO;
  PrevvalidationTime = ECUAPPM_VALUE_ZERO;
  PrevwakeupReaction = ECUAPPM_VALUE_ZERO;
}

/* Output and update for atomic system: '<S3>/EcuAppM_StateChart' */
static void EcuAppM_StateChart(void)
{
  uint8_T b;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  if (((uint32_T)EcuAppM_StateMachine_DW.is_active_c1_EcuAppM_StateMachine) ==
      0U) {
    EcuAppM_StateMachine_DW.is_active_c1_EcuAppM_StateMachine = 1U;
    EcuAppMInfo.State = eEcuAppM_Init;
    EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
    if (WakeupEvent != ((uint32_T)ECUAPPM_NOWKPEVENT)) {
      EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
        EcuAppM_StateMachine_IN_EcuAppM_PreGroupActivationState;
      EcuAppMInfo.State = eEcuAppM_PreGroupActivation;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
      EcuAppM_BufferedWakeupSource = WakeupEvent;
      EcuAppM_ReadWakeupSourcesConfigData(EcuAppM_BufferedWakeupSource,
        &EcuAppM_BufferedWakeupData);
      EcuAppM_OnStartupWrapper(EcuAppM_BufferedWakeupSource);
    } else {
      EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
        EcuAppM_StateMachine_IN_EcuAppM_InitState;
      EcuAppMInfo.State = eEcuAppM_Init;
      EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
    }
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine) {
     case EcuAppM_StateMachine_IN_EcuAppM_BackupDataState:
      if ((WakeupEvent != ((uint32_T)ECUAPPM_NOWKPEVENT)) &&
          (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE)) {
        EcuAppM_BufferedWakeupSource = WakeupEvent;
        EcuAppMInfo.EarlyWakeupCheck = ECUAPPM_TRUE;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_GroupsMgmtState;
        EcuAppM_StateMachine_DW.is_EcuAppM_GroupsMgmtState =
          EcuAppM_StateMachine_IN_EcuAppM_EarlyWakeupValidationState;
        EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
        EcuAppMInfo.State = eEcuAppM_WakeupValidation;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_ReadWakeupSourcesConfigData(EcuAppM_BufferedWakeupSource,
          &EcuAppM_BufferedWakeupData);
        EcuAppM_OnWakeupValidationWrapper(EcuAppM_BufferedWakeupSource);
        EcuAppM_ClearWakeupReasonWrapper();
      } else if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_StartPowerDownSequenceState;
        EcuAppMInfo.State = eEcuAppM_StartPowerDownSequence;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_OnPowerSeqStartWrapper((uint8_T)EcuAppMInfo.State);
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_GroupsMgmtState:
      EcuAppM_StateMachine_EcuAppM_GroupsMgmtState();
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_InitState:
      if (WakeupEvent != ((uint32_T)ECUAPPM_NOWKPEVENT)) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_PreGroupActivationState;
        EcuAppMInfo.State = eEcuAppM_PreGroupActivation;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_BufferedWakeupSource = WakeupEvent;
        EcuAppM_ReadWakeupSourcesConfigData(EcuAppM_BufferedWakeupSource,
          &EcuAppM_BufferedWakeupData);
        EcuAppM_OnStartupWrapper(EcuAppM_BufferedWakeupSource);
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_PreGroupActivationState:
      if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) &&
          (EcuAppM_BufferedWakeupData.validationTime == ((uint16_T)
            ECUAPPM_VALIDATION_TIME_ZERO))) {
        EcuAppM_IsPreGroupsActivated(PRE_GROUP0, &b);
        if (b == ECUAPPM_TRUE) {
          EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
            EcuAppM_StateMachine_IN_EcuAppM_StartPowerUpSequenceState;
          EcuAppMInfo.State = eEcuAppM_StartPowerUpSequence;
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
          EcuAppM_OnPowerSeqStartWrapper((uint8_T)EcuAppMInfo.State);
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_PreGroupDeactivationState:
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_GroupsDeactivationStatus(ECUAPPM_GROUP0, ECUAPPM_GROUP1, &b);
        if (b == ECUAPPM_TRUE) {
          EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
            EcuAppM_StateMachine_IN_EcuAppM_SleepState;
          EcuAppMInfo.State = eEcuAppM_SleepState;
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_ReadDataState:
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_IsPreGroupsActivated(PRE_GROUP1, &b);
        if (b == ECUAPPM_TRUE) {
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
          EcuAppM_BufferedWakeupSource = WakeupEvent;
          EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
            EcuAppM_StateMachine_IN_EcuAppM_GroupsMgmtState;
          EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState();
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_SleepState:
      if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) && (WakeupEvent !=
           ((uint32_T)ECUAPPM_NOWKPEVENT))) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_PreGroupActivationState;
        EcuAppMInfo.State = eEcuAppM_PreGroupActivation;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_BufferedWakeupSource = WakeupEvent;
        EcuAppM_ReadWakeupSourcesConfigData(EcuAppM_BufferedWakeupSource,
          &EcuAppM_BufferedWakeupData);
        EcuAppM_OnStartupWrapper(EcuAppM_BufferedWakeupSource);
      } else if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_InitState;
        EcuAppMInfo.State = eEcuAppM_Init;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_SleepTransientState:
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_PreGroupDeactivationState;
        EcuAppMInfo.State = eEcuAppM_PreGroupDeactivation;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_StartPowerDownSequenceState:
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_PreGroupDeactivationState;
        EcuAppMInfo.State = eEcuAppM_PreGroupDeactivation;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
      }
      break;

     case EcuAppM_StateMachine_IN_EcuAppM_StartPowerUpSequenceState:
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_ReadDataState;
        EcuAppMInfo.State = eEcuAppM_ReadDataState;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_OnNVMReadAllWrapper(EcuAppM_BufferedWakeupSource);
        EcuAppM_ProcessPreGroupsActivation(PRE_GROUP1);
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
      }
      break;

     default:
      /* case IN_EcuAppM_WakeupValidationState: */
      if (EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) {
        EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_StartPowerUpSequenceState;
        EcuAppMInfo.State = eEcuAppM_StartPowerUpSequence;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
        EcuAppM_OnPowerSeqStartWrapper((uint8_T)EcuAppMInfo.State);

        /*   */
      } else if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_FAILED) ||
                 (EcuAppM_WakeupValidationTimer >=
                  EcuAppM_BufferedWakeupData.validationTime)) {
        EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
        EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
        EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
          EcuAppM_StateMachine_IN_EcuAppM_SleepTransientState;
        EcuAppMInfo.State = eEcuAppM_SleepTransient;
        EcuAppM_ClearWakeupReasonWrapper();
        EcuAppM_StartOfSleepTransientWrapper();
      } else {
        EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
        EcuAppMInfo.CurrentJobStatus = b;
        EcuAppM_WakeupValidationTimer = (uint16_T)(EcuAppM_WakeupValidationTimer
          + ECUAPPM_PERIOD_MSEC);
      }
      break;
    }

    if (guard4) {
      if ((EcuAppMInfo.CurrentJobStatus == ECUAPPM_JOB_DONE) &&
          (EcuAppM_BufferedWakeupData.validationTime != ((uint16_T)
            ECUAPPM_VALIDATION_TIME_ZERO))) {
        EcuAppM_IsPreGroupsActivated(PRE_GROUP0, &b);
        if (b == ECUAPPM_TRUE) {
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IDLE;
          EcuAppM_StateMachine_DW.is_c1_EcuAppM_StateMachine =
            EcuAppM_StateMachine_IN_EcuAppM_WakeupValidationState;
          EcuAppM_WakeupValidationTimer = ECUAPPM_VALUE_ZERO;
          EcuAppMInfo.State = eEcuAppM_WakeupValidation;
          EcuAppMInfo.CurrentJobStatus = ECUAPPM_JOB_IN_PROGRESS;
          EcuAppM_OnWakeupValidationWrapper(EcuAppM_BufferedWakeupSource);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard3) {
      EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
      EcuAppMInfo.CurrentJobStatus = b;
      EcuAppM_ProcessPreGroupsActivation(PRE_GROUP1);
    }

    if (guard2) {
      EcuAppM_ProcessGroupsDeactivation(ECUAPPM_GROUP1, ECUAPPM_GROUP0, 0);
      EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
      EcuAppMInfo.CurrentJobStatus = b;
    }

    if (guard1) {
      EcuAppM_ProcessPreGroupsActivation(PRE_GROUP0);
      EcuAppM_ProcessJobStatusWrapper((uint8_T)EcuAppMInfo.State, &b);
      EcuAppMInfo.CurrentJobStatus = b;
    }
  }
}

/* Model step function */
void EcuAppM_StateMachine_step(void)
{
  ApplicationSleepState = EcuAppM_GetApplicationSleepStatus();
  WakeupEvent = EcuAppM_GetWakeupEventStatus();
  EcuAppM_StateChart();
  EcuAppM_SetEcuAppMState(EcuAppMInfo.State);
}

/* Model initialize function */
void EcuAppM_StateMachine_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &EcuAppM_StateMachine_B), 0,
                sizeof(B_EcuAppM_StateMachine_T));

  /* states (dwork) */
  (void) memset((void *)&EcuAppM_StateMachine_DW, 0,
                sizeof(DW_EcuAppM_StateMachine_T));
  EcuAppM_StateChart_Init();
}

/* Model terminate function */
void EcuAppM_StateMachine_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
