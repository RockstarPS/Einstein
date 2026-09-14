#include "EcuAppMExt.h"


void EcuAppM_OnNVMReadAll(uint32_T WakeupSource)
{
    //
}
uint8_T EcuAppM_ProcessJobStatus(uint8_T state)
{
  return 2;
}
void EcuAppM_PowerUpWakeupSources(void)
{
    //
}
void EcuAppM_OnPowerSeqStart(uint8_T State)
{
	//
}
void EcuAppM_OnWakeupValidation(void)
{
    //
}
uint8_T EcuAppM_GroupStateChangeRequest(uint8_T groupId,uint8_T groupState)
{
    return 2;
}
void EcuAppM_FailSafeMechanism(uint8_T GroupId,uint8_T State)
{
	//
}

uint8_T EcuAppM_GroupActivationAllowed(uint8_T GroupId)
{
	return 2;
}

void EcuAppM_BackupData (void)
{
	//
}

void EcuAppM_GroupStatusChangeCbk(uint8_T groupId,uint8_T groupState)
{
	//
}

void EcuAppM_StartOfGroupsDeactivation(void)
{
	//
}
void EcuAppM_ClearWakeupSources(void)
{
	
}
