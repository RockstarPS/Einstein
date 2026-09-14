/*******************************************************************************************************************************************************
*                                                                            											 				 			   *
*              CONFIDENTIAL VISTEON CORPORATION                              											 				 			   *
*                                                                            											 				 			   *
* This is an unpublished work of authorship, which contains trade            											 				 			   *
* secrets, created in 2023. Visteon Corporation owns all rights to           											 				 			   *
* this work and intends to maintain it in confidence to preserve             											 				 			   *
* its trade secret status. Visteon Corporation reserves the right,           											 				 			   *
* under the copyright laws of the United States or those of any              											 				 			   *
* other country that may have jurisdiction, to protect this work             											 				 			   *
* as an unpublished work, in the event of an inadvertent or                  											 				 			   *
* deliberate unauthorized publication. Visteon Corporation also              											 				 			   *
* reserves its rights under all copyright laws to protect this               											 				 			   *
* work as a published work, when appropriate. Those having access            											 				 			   *
* to this work may not copy it, use it, modify it or disclose the            											 				 			   *
* information contained in it without the written authorization              											 				 			   *
* of Visteon Corporation.                                                    											 				 			   *
*                                                                            											 				 			   *
********************************************************************************************************************************************************/

/*******************************************************************************************************************************************************
*  											HEADER FILES INCLUSION												 		  				 			   *
********************************************************************************************************************************************************/

#include "EcuAppM_CmdProcessing.h"
#include "EcuAppM_Types.h"


/********************************************************************************************************************************************************
** Function Name     : uint8 EcuAppM_GroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd)
**
** Description       : This function is used to process the commands to activate or deactivation of components.
**
** Invocation        : This function is invoked from the EcuAppM Module.
**
** Parameters        : arguments Groupid,GroupCmd (two parameters are to know for which group and and what is is the command to process).
**
** Return Value      : uint8
**  				   ECUAPPM_JOB_DONE ---should be return upon component command processing sucess.
					   ECUAPPM_JOB_FAILED--should be return upon component command processing fail.
**
** Critical Section  : None
**********************************************************************************************************************************************************/
uint8 EcuAppM_GroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd)
{
	Std_ReturnType retL = E_OK;
	retL = EcuAppM_GroupStateChangeRequest(Groupid,GroupCmd);
	return retL;
}

/********************************************************************************************************************************************************
** Function Name     : uint8 EcuAppM_DispatchSafeGroupStateChangeRequest(uint8 Groupid, uint8 GroupCmd)
**
** Description       : This function is used to invoke the trusted call.
**
** Invocation        : This function is invoked from the EcuAppM Module.
**
** Parameters        : arguments Groupid,GroupCmd (two parameters are to know for which group and and what is is the command to process).
**
** Return Value      : uint8
**  				   ECUAPPM_JOB_DONE ---should be return upon component command processing sucess.
					   ECUAPPM_JOB_FAILED--should be return upon component command processing fail.
**
** Critical Section  : None
**********************************************************************************************************************************************************/
uint8 EcuAppM_DispatchSafeGroupStateChangeRequest(uint8 Groupid, uint8 GroupCmd)
{
	Std_ReturnType retL = E_OK;
	retL = OsTrustedCall_EcuAppM_SafeGroupStateChangeRequestProcessing(Groupid,GroupCmd);
	return retL;
}
/********************************************************************************************************************************************************
** Function Name     : uint8 EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd)
**
** Description       : This function is used to process the commands to activate or deactivation of components in safe mode.
**
** Invocation        : This function is invoked from EcuAppM_DispatchSafeGroupStateChangeRequest function.
**
** Parameters        : arguments Groupid,GroupCmd (two parameters are to know for which group and and what is is the command to process).
**
** Return Value      : uint8
**  				   ECUAPPM_JOB_DONE ---should be return upon component command processing sucess.
					   ECUAPPM_JOB_FAILED--should be return upon component command processing fail.
**
** Critical Section  : None
**********************************************************************************************************************************************************/
uint8 EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd)
{
	Std_ReturnType retL = E_OK;
	retL = EcuAppM_GroupStateChangeRequest(Groupid,GroupCmd);
	return retL;
}

/********************************************************************************************************************************************************
** Function Name     : uint8 EcuAppM_GroupStateChangeRequest(uint8 Groupid, uint8 GroupCmd)
**
** Description       : This function is used to process the commands to activate or deactivation of components.
**
** Invocation        : This function is invoked from the EcuAppM Module.
**
** Parameters        : arguments Groupid,GroupCmd (two parameters are to know for which group anf and what is is the command to process).
**
** Return Value      : uint8
**  				   ECUAPPM_JOB_DONE ---should be return upon component command processing sucess.
					   ECUAPPM_JOB_FAILED--should be return upon component command processing fail.
**
** Critical Section  : None
**********************************************************************************************************************************************************/
uint8 EcuAppM_GroupStateChangeRequest(uint8 Groupid, uint8 GroupCmd)
{
	Std_ReturnType retL = E_OK;
	switch(GroupCmd)
	{
		
		case eGroup_StateInit:
								if(Groupid < ECUAPPM_MAX_GROUPS)
								{
									for(uint8 i = 0;i < EcuAppM_GroupContainerList[Groupid].NumOfComponents; i++)
									{
										if(eCmpState_Inactive == EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus)
										{
											if((EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi != NULL_PTR)
											{
												if (E_OK == (EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi(eCmpCmd_Init))
												{
													EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus = eCmpState_Init;
												}
												else
												{
													retL = ECUAPPM_JOB_FAILED;
													break;
												}
											}
										}
									}
									if(retL == E_OK)
									{	
										retL = ECUAPPM_JOB_DONE;
									}
									break;
								}
								break;
		
		case eGroup_StateActivation:
								if(Groupid < ECUAPPM_MAX_GROUPS)
								{
									for(uint8 i = 0;i < EcuAppM_GroupContainerList[Groupid].NumOfComponents; i++)
									{
										if((eCmpState_Init == EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus)||
										   (eCmpState_Inactive == EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus))
										{
											if((EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi != NULL_PTR)
											{
												if (E_OK == (EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi(eCmpCmd_Activate))
												{
													EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus = eCmpState_Active;
												}
												else
												{
													retL = ECUAPPM_JOB_FAILED;
													break;
												}
											}
										}
									}
									if(retL == E_OK)
									{	
										retL = ECUAPPM_JOB_DONE;
									}
									break;
								}
								break;
		case eGroup_StateDeactivation:
								if((Groupid == ECUAPPM_GROUP0) || (Groupid < ECUAPPM_MAX_GROUPS))
								{
									for(uint8 i = 0;i < EcuAppM_GroupContainerList[Groupid].NumOfComponents; i++)
									{
										if(eCmpState_Active == EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus)
										{
											if((EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi != NULL_PTR)
											{
												if (E_OK == (EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i])->pCmpLifeCycleMgrApi(eCmpCmd_DeActivate))
												{
													EcuAppM_GroupContainerList[Groupid].pCmpContainerList[i]->CmpStatus = eCmpState_Inactive;
												}
												else
												{
													retL = ECUAPPM_JOB_FAILED;
													break;
												}
											}
										}
									}
									if(retL == E_OK)
									{	
										retL = ECUAPPM_JOB_DONE;
									}
									break;
								}
								break;
		default:
				break;
	}
	return retL;
}

/********************************************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_CmdProcessing.
********************************************************************************************************************************************************/
/********************************************************************************************************************************************************
Date              : 05-09-23
CDSID             : akappa
Traceability      :
Change Description: implementation of safety group handling.
********************************************************************************************************************************************************/
/* End Of File */
