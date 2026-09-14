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
#include "EcuAppM_Callouts.h"
#include "EcuAppM_Types.h"
#include "Rte_EcuAppM.h"
#include "CDD_EcuPowerM.h" 
// #include "Fee.h"
// #include "Fls.h"
#include "Ea.h"
#include "CanStub.h"
#include "Rte_Type.h"
#include "Compiler.h"
#include "Rte_Compiler_Cfg.h"
#include "Rte_IoHwAb_Type.h"
#include "Pwm.h"
#include "Rte_DmnMgr_Type.h"
#include "CanTrcv_GeneralTypes.h"
#include "Rte_Ctrl_WSS_Type.h"
#include "Rte_CDisplayCdd_Type.h"
#include "DisplayCdd_Cfg.h"
extern uint32 EcuAppM_BufferedWakeupSource;
EDisplaypowerStatesHelper EcuAppM_DisplayCdd_CurrentState;
extern EDisplaypowerStatesHelper DisplayCdd_Cfg_GetDisplayDrvStateMachine(void);
static uint16 Vip_Mode;
static  uint8 lSleepStatus = CANTRCV_TRCVMODE_NORMAL;
static uint8 CurrentActivityStatus = 0;
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DmnMgr_rpSR_DmnInfo_SDmnStatus(P2VAR(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data);
// extern void BacklightIfCdd_UpdateDeviceStatus(uint8 indexid , uint8 status);
extern Std_ReturnType MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(uint16* Ptr);
#define MEET_NVM_FLAG 						(uint16)(0x52AEU)

// static uint8 BacklightDutyUpdate = FALSE;
void DssDisplayAppInit(void);

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
  switch (State)
  {
  case eEcuAppM_StartPowerUpSequence:
    EcuPowerM_RequestPower(0, ECUPOWERM_RQST_DEVICE_POWERUP);
    break;
  case eEcuAppM_StartPowerDownSequence:
    break;
  default:
    // do nothing
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
  /* Added Read All at earlier stage to optimize the start timing */
  Rte_Call_rp_CS_NvmExtStartReadAll_NvMExt_ReadAll();
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
void EcuAppM_FailSafeMechanism(uint8 GroupId, uint8 State)
{
}

/***************************************************************************************************************************
** Function Name     : uint8 EcuAppM_GroupActivationAllowed(uint8 GroupId)
**
** Description       : This is the function to check before activation of invidual group whether to allow activation or not.
**					   Special condition checks can be added here like low voltage sceanrio whether to activation of
**					   particular group need to allow or not.
**
** Invocation        : This function is called from EcuAppM module during the activation of the groups.
**
** Parameters        : GroupId is passed to know for which group this check is required.
**
** Return Value      : uint8(this retrun value is used to know that particular group is allowed to activate or not).
**					   This function will expect return value as 1 if check is not added.
**					   If any Special condiion is added based on the result of condition return value should be sent.
**					   TRUE(1)--should sent upon condtion met/none of the conditions added.
**					   FALSE(0)--should sent upon condtion not met case.
**
** Critical Section  : None
***************************************************************************************************************************/
uint8 EcuAppM_GroupActivationAllowed(uint8 GroupId)
{
  uint8 Ret = 1;
  return Ret;
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
void EcuAppM_BackupData(void)
{
  (void)Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep();
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
void EcuAppM_GroupStatusChangeCbk(
    uint8 groupId,
    uint8 groupState)
{
  if (groupId == ECUAPPM_GROUP2)
  {
    if (groupState == eGroup_StateActivation)
    {
      (void)DisplayCddCfg_SetState(0u, eDisplayPowerON);

    }
  }
  if (groupState == eGroup_StateDeactivation)
  {
    EcuPowerM_RequestPower(1, ECUPOWERM_RQST_DEVICE_POWERDOWN);
  }
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
  SDmnStatus sDmnSts = {0};
  uint8 Return_Status = ECUAPPM_JOB_IDLE;
  uint8 Power_Status = 0;
  uint8 dispPowerstate = 255U;
  //Std_ReturnType NvMSleepState = E_NOT_OK;
  uint32 Meet_WakeupSource = ECUM_WKSOURCE_MEET;  

  switch (Current_State)
  {
  case eEcuAppM_Init:
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_PreGroupActivation:
    (void)Rte_Call_rpCS_EcumExt_RequestRUN_RequestRUN(0);
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_WakeupValidation:
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_ReadDataState:
    (void)Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(&CurrentActivityStatus);
    if (CurrentActivityStatus == 1u)
    {
      (void)MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(&Vip_Mode);
      if(MEET_NVM_FLAG == Vip_Mode)
      {
        EcuAppM_SetWakeupSources(Meet_WakeupSource); 
      }
      CurrentActivityStatus = 2u;
      Return_Status = ECUAPPM_JOB_DONE;
    }
    break;

  case eEcuAppM_StartPowerUpSequence:
    EcuPowerM_GetDeviceStatus(0, &Power_Status);
    if (Power_Status == ECUPOWERM_DEV_PWR_STATUS_COMPLETED)
    {
      Return_Status = ECUAPPM_JOB_DONE;
    }
    break;

  case eEcuAppM_GroupsActivation:
    if(CurrentActivityStatus == 2u)
    {      
      Rte_Read_DmnMgr_rpSR_DmnInfo_SDmnStatus(&sDmnSts);
      if(sDmnSts.dmnStatus == (EDmnOverallState_t)0x1)
      {
        if(MEET_NVM_FLAG == Vip_Mode)
        {
          DmnMgr_DmnSystemStateChangeReq(EDomainId_Cluster, ESystemState_Meet);
        }
        else
        {
          DmnMgr_DmnSystemStateChangeReq(EDomainId_Cluster, ESystemState_FullRun);
        }  
		    CurrentActivityStatus = 3u;
        Return_Status = ECUAPPM_JOB_DONE;        
      }
      else
      {
        Return_Status = ECUAPPM_JOB_DONE;
      }
    }
    else if(CurrentActivityStatus ==3U)
    {
        Return_Status = ECUAPPM_JOB_DONE;
    }
    break;

  case eEcuAppM_GroupsDeactivation:
    (void)DisplayCddCfg_SetState(0u, eDisplayPowerOFF);
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_BackupData:
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_StartPowerDownSequence:
    Return_Status = ECUAPPM_JOB_DONE;
    break;
  case eEcuAppM_PreGroupDeactivation:
    EcuAppM_DisplayCdd_CurrentState = DisplayCdd_Cfg_GetDisplayDrvStateMachine();
    EcuPowerM_GetDeviceStatus(1, &dispPowerstate);
    if (EcuAppM_DisplayCdd_CurrentState == eDisplayDisableState)
    {
      if (dispPowerstate == ECUPOWERM_DEV_PWR_STATUS_COMPLETED)
      {
        Return_Status = ECUAPPM_JOB_DONE;
      }
      else
      {
        EcuPowerM_RequestPower(1, ECUPOWERM_RQST_DEVICE_POWERDOWN);
      }
    }
    else
    {
      //do nothing
    }
    break;

  case eEcuAppM_SleepTransient:
    Return_Status = ECUAPPM_JOB_DONE;
    break;

  case eEcuAppM_SleepState:
    Rte_Call_rpCS_EcumExt_ReleaseRUN_ReleaseRUN(0);
    Return_Status = ECUAPPM_JOB_DONE;
    break;
  default:
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
void EcuAppM_StartOfGroupsDeactivation(void)
{
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
  uint8 ret = ECUAPPM_REFUSE_TO_SLEEP;
  uint8 NotifySleepStatus = 0u;
  CanTrcv_TrcvModeType getcurrentOpMode;
  (void) Rte_Call_rp_NotifySleepStatus_CtrlWSS_NotifyNetworkSleep(&NotifySleepStatus);
  if(NotifySleepStatus == NETWORK_SLEEP)
  {
    if(lSleepStatus == CANTRCV_TRCVMODE_NORMAL)
    {
      CanTrcv_SetOpMode(1, CANTRCV_TRCVMODE_SLEEP);
      CanTrcv_GetOpMode(1, &getcurrentOpMode);
      lSleepStatus = CANTRCV_TRCVMODE_SLEEP;
    }
  }  
  else
  {
    if (lSleepStatus == CANTRCV_TRCVMODE_SLEEP)
    {
      CanTrcv_SetOpMode(1, CANTRCV_TRCVMODE_NORMAL);
      CanTrcv_GetOpMode(1, &getcurrentOpMode);
      lSleepStatus = CANTRCV_TRCVMODE_NORMAL;
    }
  }
  /* Read Sleep Status from AppSlpIM */
  Status = Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep();
  if ((Ea_GetStatus() == MEMIF_IDLE) && (Status == E_OK))

  {
    ret = ECUAPPM_READY_TO_SLEEP;
  }
  return ret;
}
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
/* End Of File */
