#include "rtwtypes.h"

void EcuAppM_OnNVMReadAll(uint32_T WakeupSource);
uint8_T EcuAppM_ProcessJobStatus(uint8_T state);
void EcuAppM_OnStartup(uint32_T WakeupSource);
void EcuAppM_OnPowerSeqStart(uint8_T State);
void EcuAppM_OnWakeupValidation(uint32_T WakeupSource);
uint8_T EcuAppM_GroupStateChangeRequestProcessing(uint8_T groupId,uint8_T groupState);
uint8_T EcuAppM_DispatchSafeGroupStateChangeRequest(uint8_T groupId,uint8_T groupState);
void EcuAppM_FailSafeMechanism(uint8_T GroupId,uint8_T State);
uint8_T EcuAppM_GroupActivationCallout(uint8_T GroupId);
void EcuAppM_BackupData(void);	
void EcuAppM_GroupStatusChangeCbk(uint8_T groupId,uint8_T groupState);
void EcuAppM_StartOfGroupsDeactivation(void);
void EcuAppM_StartOfSleepTransient(void);
void EcuAppM_ClearWakeupSources(void);
uint8_T EcuAppM_GroupActivationCallout(uint8_T GroupId);
