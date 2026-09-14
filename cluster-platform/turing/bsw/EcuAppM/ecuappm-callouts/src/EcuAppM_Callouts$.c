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
#include "EcuAppMExt.h"
#include "EcuAppM_Types.h"

/***************************************************************************************************************************
** Function Name     : void EcuAppM_OnPowerSeqStart(uint8 State)
**
** Description       : This function can be used to trigger the power sequence or any necessary activity upon 
					   poweup sequence start.
**
** Invocation        : This function is called from EcuAppM Statemachine of EcuAppM_StartPowerUpSequenceState.
**
** Parameters        : State argument is know the state of the EcuAppM Statemachine.
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_OnPowerSeqStart(uint8 State)
{
	switch(State)
	{
		case eEcuAppM_StartPowerUpSequence:
										//PowerCdd_RequestPowerState(ePowerCdd_PowerUp);
										break;
		case eEcuAppM_StartPowerDownSequence:
										//PowerCdd_RequestPowerState(ePowerCdd_PowerDown);
										break;
		default:
			//do nothing
			break;
	}
	
}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_OnNVMReadAll(uint16 WakeupSource)
**
** Description       : This is the function to trigger the NVM read all activity.
**
** Invocation        : This function is called from EcuAppM Statemachine of EcuAppM_NvmReadAllState.
**
** Parameters        : WakeupSource argument is used to know for which wakeup source NVM read is triggered.
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_OnNVMReadAll(uint32 WakeupSource)
{
	//NvMExt_ReadAll();
}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_PowerUpWakeupSources(void)
**
** Description       : This is the function to intiate the powerup sequence to wakeup sources.
**
** Invocation        : This function is called from EcuAppM Statemachine of EcuAppM_PowerUpWakeupSourcesState.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_OnStartup(uint32 WakeupSource)
{
	EcuM_RequestRUN(0);
}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_OnWakeupValidation(void)
**
** Description       : This is the function to perform the wakeup validation of particular wakeup source.
**
** Invocation        : This function is called from EcuAppM Statemachine of EcuAppM_WakeupValidationState.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_OnWakeupValidation(uint32 WakeupSource)
{

}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_FailSafeMechanism(uint8 GroupId,uint8 State)
**
** Description       : This is the function to call fail safe action upon any of the groups activation or deactivation is 
					   taking more than configured time.
**
** Invocation        : This function is called from EcuAppM module.
**
** Parameters        : GroupId and State arguments are passed to know for which group on which state failsafe is triggered.
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_FailSafeMechanism(uint8 GroupId,uint8 State)
{

}
/***************************************************************************************************************************
** Function Name     : void EcuAppM_BackupData (void)
**
** Description       : This function can be used to write the backup data ino NVM.
**
** Invocation        : This function is called from EcuAppM Statemachine of EcuAppM_BackupDataState.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_BackupData (void)
{
	
}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_GroupStatusChangeCbk(uint8 groupId,uint8 groupState)
**
** Description       : This is the function to notify group status change of the individual group.
**					   Based on particular group status change any of the action can be added here.
**
** Invocation        : This function is called form group life cycle handler EcuAppM module.
**
** Parameters        : groupId,groupState(these two parameters are passed to know group id and state of the group).
**
** Return Value      : None
**
** Critical Section  : none
***************************************************************************************************************************/
void EcuAppM_GroupStatusChangeCbk(uint8 groupId,uint8 groupState)
{

}

/***************************************************************************************************************************
** Function Name     : uint8 EcuAppM_ProcessJobStatus(uint8 Current_State)
**
** Description       : This is the function to perform any of the action upon particular state of the EcuAppM state machine.
**					   Based on the particular state action completion only statemachine should moved next state.
**
** Invocation        : This function is called form each state of the EcuAppM module Statemachine.
**
** Parameters        : Current_State is passed to know about current state of the EcuAppM stamacine.
**
** Return Value      : uint8(Return value is to notify about particular state action progress).
**					   ECUAPPM_JOB_DONE--should be return upon action completion/none of action not there in that particular 
**					   state.
**
** Critical Section  : None
***************************************************************************************************************************/
uint8 EcuAppM_ProcessJobStatus(uint8 Current_State)
{
	uint8 Return_Status = ECUAPPM_JOB_IDLE;
	//uint8 CurrentActivityStatus = 0;
	
	switch(Current_State)
	{
		case eEcuAppM_Init:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_PreGroupActivation:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_WakeupValidation:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_ReadDataState:
							/* (void)NvmExt_GetNvMReadAllStatus(&CurrentActivityStatus);
							if(CurrentActivityStatus == TRUE)
							{ */
								Return_Status = ECUAPPM_JOB_DONE;
							//}	
							break;
		
		case eEcuAppM_StartPowerUpSequence:	
							Return_Status =ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_GroupsActivation:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_GroupsDeactivation:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_BackupData:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
												
		case eEcuAppM_StartPowerDownSequence:
							Return_Status = ECUAPPM_JOB_DONE;	
							break;
		
		case eEcuAppM_PreGroupDeactivation:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
										
		case eEcuAppM_SleepTransient:
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		
		case eEcuAppM_SleepState:
							EcuM_ReleaseRUN();
							Return_Status = ECUAPPM_JOB_DONE;
							break;
		default:
							/* Not expected to reach here */
							Return_Status = ECUAPPM_JOB_DONE;
							break;
	}
	return Return_Status;
}

/***************************************************************************************************************************
** Function Name     : void EcuAppM_StartOfGroupsDeactivation (void)
**
** Description       : This function can be used perfrom any necessary activity upon start of the groups deactivation.
**
** Invocation        : This function is called form goups deactivation of EcuAppM module.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_StartOfGroupsDeactivation (void)
{

/***************************************************************************************************************************
** Function Name     : void EcuAppM_StartOfSleepTransient (void)
**
** Description       : This function can be used perfrom any necessary activity upon start of the groups deactivation.
**
** Invocation        : This function is called form sleep transient state of EcuAppM module.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
void EcuAppM_StartOfSleepTransient(void)
{
	EcuWakeupM_EnableAllWakeups(TRUE);
}
/***************************************************************************************************************************
** Function Name     : uint8 EcuAppM_CheckApplicationSleepStatus (void)
**
** Description       : This is the function to get the latest application sleep status.
**
** Invocation        : This function is invoked from EcuAppM Module.
**
** Parameters        : None
**
** Return Value      : uint8(latest sleep status should be return).
**
** Critical Section  : None
***************************************************************************************************************************/

uint8 EcuAppM_CheckApplicationSleepStatus(void)
{
	uint8 Status = ECUAPPM_REFUSE_TO_SLEEP;
	//Status = SleepManager_JudgementStatus(); 
	/* Application sleep status Api need to added with
														ECUAPPM_READY_TO_SLEEP as 0
														ECUAPPM_REFUSE_TO_SLEEP as 1 */
/***************************************************************************************************************************
** Function Name     : uint8 EcuAppM_GroupActivationCallout(uint8 GroupId)
**
** Description       : This is the function to get the context switch status for every group.
**
** Invocation        : This function is invoked from EcuAppM Module.
**
** Parameters        : None
**
** Return Value      : uint8(Activation status).
**
** Critical Section  : None
***************************************************************************************************************************/
uint8 EcuAppM_GroupActivationCallout(uint8 GroupId)
{
	uint8 Return_Status = 1;
	switch(GroupId)
	{
		case 0:
				Return_Status = TRUE;  /*For the PreGrp0 group, the activation condition should always be set to TRUE as it represents the power group*/
				break;	
		case 1:
				Return_Status = TRUE;  /*For the PreGrp1 group, the activation condition should always be set to TRUE as it represents the system control group*/
				break;
		default:
				Return_Status = TRUE;
				break;
	}
	return Return_Status;
}

/**************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Callouts.
***************************************************************************************************************************/
/**************************************************************************************************************************
Date              : 03-12-24
CDSID             : akappa
Traceability      :
Change Description: EcuAppM_GroupActivationCallout function added.
***************************************************************************************************************************/
/* End Of File */
