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
*  											HEADER FILES INCLUSION												 		  *
***************************************************************************************************************************/

#include "EcuAppM.h"
#include "EcuAppM_Types.h"
#include "EcuAppM_Callouts.h"
#include "EcuAppM_MemoryMap.h"
#include "EcuAppM_Errorhandler.h"

/**************************************************************************************************************************
*  									INITIALIZED DATA DECLARATIONS (.DATA)												  *
***************************************************************************************************************************/

#define	ECUAPPM_START_SEC_VAR_INIT_32
#include "MemMap.h"
static VAR(uint32, ECUAPPM_VAR) EcuAppM_WakeupSources = 0UL;
#define	ECUAPPM_STOP_SEC_VAR_INIT_32
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_8
#include "MemMap.h"
static VAR(uint8, ECUAPPM_VAR) Status = ECUAPPM_REFUSE_TO_SLEEP;
#define	ECUAPPM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#define	ECUAPPM_START_SEC_VAR_INIT_8
#include "MemMap.h"
static VAR(uint8, ECUAPPM_VAR) EcuAppM_InitStatus = ECUAPPM_S_UNINITIALIZED;
#define	ECUAPPM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

/**************************************************************************************************************************
*  									UNINITIALIZED DATA DECLARATIONS(.BSS)												  *
***************************************************************************************************************************/


/**************************************************************************************************************************
** Function Name     : FUNC(uint8, ECUAPPM_CODE) EcuAppM_GetApplicationSleepStatus(void)
**
** Description       : This is the function to get the latest application sleep status.
**
** Invocation        : This function is invoked from EcuAppM_StateMachine.
**
** Parameters        : None
**
** Return Value      : uint8(latest sleep status should be return).
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(uint8, ECUAPPM_CODE) EcuAppM_GetApplicationSleepStatus(void)
{
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_GET_APPSLEEPSTATUS_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
		Status = EcuAppM_CheckApplicationSleepStatus();
	}
	return Status;
}

/**************************************************************************************************************************
** Function Name     : FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupEventStatus(void)
**
** Description       : This function is used to get the latest wakeup event.
**
** Invocation        : EcuAppMIf.c
**
** Parameters        : None
**
** Return Value      : uint16(latest wakeup reason should be return).
**
** Critical Section  : none
***************************************************************************************************************************/
FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupEventStatus(void)
{ 
	uint32 WakeupSource=0;
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_GET_WAKEUPEVENT_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
		WakeupSource = EcuAppM_GetWakeupSources();
	}
	return WakeupSource;
}

/**************************************************************************************************************************
** Function Name     : FUNC(void, ECUAPPM_CODE) EcuAppM_SetEcuAppMState(uint8 state)
**
** Description       : This is the function to notify about current state od the EcuAppM Statemachine.
**
** Invocation        : EcuAppMIf.c
**
** Parameters        : state argument(to know current state of the EcuAppM Statemachine).
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_CODE) EcuAppM_SetEcuAppMState(uint8 state)
{
	(void)state;
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_SET_ECUAPPMSTATE_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
		/* do nothing */
	}
}

/**************************************************************************************************************************
** Function Name     : FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupSources(void)
**
** Description       : This function is used to get the latest wakeup event.
**
** Invocation        : This function is triggered form the Get_WakeupEventStatus function.
**
** Parameters        : None
**
** Return Value      : uint16(latest wakeup reason should be return).
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupSources(void)
{
	uint32 WakeupStatus = 0UL;
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_GET_WAKEUPSOURCES_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{		
		WakeupStatus = EcuAppM_WakeupSources;
	}	
	return WakeupStatus;
}

/***************************************************************************************************************************
** Function Name     :FUNC(void, ECUAPPM_CODE) EcuAppM_SetWakeupSources(uint32 WakeupSource)
**
** Description       : This is the function to set particualar wakeup recieved from EcuMExt.
**
** Invocation        : This function is triggered from the EcuMExt module.
**
** Parameters        : WakeupSource argument(to know about current wakeup source).
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_CODE) EcuAppM_SetWakeupSources(uint32 WakeupSource)
{
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_SET_WAKEUPSOURCES_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
			EcuAppM_WakeupSources = WakeupSource;
	}
}

/**************************************************************************************************************************
** Function Name     : FUNC(void, ECUAPPM_CODE) EcuAppM_ClearWakeupSources(void)
**
** Description       : This is the function to clear the Wakeup reason.
**
** Invocation        : This function is triggered from the EcuAppM State machine.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_CODE) EcuAppM_ClearWakeupSources(void)
{
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_CLEAR_WAKEUPSOURCES_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
		EcuAppM_WakeupSources = ECUAPPM_NOWKPEVENT;
	}
}

/**************************************************************************************************************************
** Function Name     : FUNC(void, ECUAPPM_CODE) EcuAppM_Init(void)
**
** Description       : This is the Function to trigger EcuAppM_StateMachine_initialize.
**
** Invocation        : This function should be invoke form EcuMExt driverinit.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_CODE) EcuAppM_Init(void)
{
	if (EcuAppM_InitStatus == ECUAPPM_S_INITIALIZED)
    {
		/* EcuApp Manager already initialized */
		EcuAppM_ReportError(ECUAPPM_API_INIT, ECUAPPM_E_ALREADYINITIALIZED); 
    }
	else
	{ 
		EcuAppM_StateMachine_initialize();
		EcuAppM_InitStatus = ECUAPPM_S_INITIALIZED;
	}
}

/*************************************************************************************************************************
** Function Name     : FUNC(void, ECUAPPM_CODE) EcuAppM_MainFunction(void)
**
** Description       : This is the function used to trigger EcuAppM_StateMachine_step function of EcuAppM_StateMachine.
**
** Invocation        : This function should be invoked from the Os.
**
** Parameters        : None
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_CODE) EcuAppM_MainFunction(void)
{
	if (EcuAppM_InitStatus != ECUAPPM_S_INITIALIZED)
    {
		EcuAppM_ReportError(ECUAPPM_API_MAIN_FUNC, ECUAPPM_E_UNINT);
    }
	else
	{
		EcuAppM_StateMachine_step();
	}
}

/**************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM.
***************************************************************************************************************************/
/**************************************************************************************************************************
Date              : 21-11-23
CDSID             : akappa
Traceability      :
Change Description: Modified according to the Autosar Memory mapping.
***************************************************************************************************************************/
/* End Of File */
