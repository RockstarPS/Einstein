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
#include "DisplayCdd_Cfg.h"
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
//extern void HMemDrv_Init( void );
extern FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_RequestPower(VAR(uint8, AUTOMATIC)deviceId, 
	                                                                  VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state);
#endif 

/***************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Callouts.
****************************************************************************************************************************/
/* End Of File */
