/*************************************************************************************************************************
*                                                                            											 *
*              CONFIDENTIAL VISTEON CORPORATION                              											 *
*                                                                            											 *
* This is an unpublished work of authorship, which contains trade            											 *
* secrets, created in 2023. Visteon Corporation owns all rights to           											 *
* this work and intends to maintain it in confidence to preserve             											 *
* its trade secret status. Visteon Corporation reserves the right,           											 *
* under the copyright laws of the United States or those of any              											 *
* other country that may have jurisdiction, to protect this work             											 *
* as an unpublished work, in the event of an inadvertent or                  											 *
* deliberate unauthorized publication. Visteon Corporation also              											 *
* reserves its rights under all copyright laws to protect this               											 *
* work as a published work, when appropriate. Those having access            											 *
* to this work may not copy it, use it, modify it or disclose the            											 *
* information contained in it without the written authorization              											 *
* of Visteon Corporation.                                                    											 *
*                                                                            											 *
**************************************************************************************************************************/

/**************************************************************************************************************************
*                            header files inclusion                                  											  *
***************************************************************************************************************************/

#ifndef __ECUAPPM_EXT_H_
#define __ECUAPPM_EXT_H_

#include "EcuAppM_Cfg.h"
#include "Rte_Type.h"
/**************************************************************************************************************************
*                         Function Declarations                              											  *
***************************************************************************************************************************/

void EcuAppM_OnNVMReadAll(uint32 WakeupSource);
uint8 EcuAppM_ProcessJobStatus(uint8 Current_State);
void EcuAppM_OnStartup(uint32 WakeupSource);
void EcuAppM_OnPowerSeqStart(uint8 State);
void EcuAppM_OnWakeupValidation(uint32 WakeupSource);
uint8 EcuAppM_GroupActivationCallout(uint8 GroupId);
void EcuAppM_FailSafeMechanism(uint8 GroupId,uint8 State);
uint8 EcuAppM_GroupActivationAllowed(uint8 GroupId);
void EcuAppM_BackupData(void);
void EcuAppM_GroupStatusChangeCbk(uint8 groupId,uint8 groupState);
void EcuAppM_StartOfGroupsDeactivation (void);
void EcuAppM_StartOfSleepTransient(void);
uint8 EcuAppM_CheckApplicationSleepStatus(void);
void NvMExt_GetPhase1ReadCompletionNotification(uint8 *Status);
void NvMExt_GetPhase2ReadCompletionNotification(uint8 *Status);
void NvMExt_GetPhase3ReadCompletionNotification(uint8 *Status);
extern Std_ReturnType DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState);
extern void EcuWakeupM_EnableAllWakeups(uint8 NotifyStatus);
extern Std_ReturnType DisplayCddCfg_SetState(EDisplayType DeviceId, EDisplayPowerState NewPowerState);

#endif 

/***************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Callouts.
****************************************************************************************************************************/
/* End Of File */
