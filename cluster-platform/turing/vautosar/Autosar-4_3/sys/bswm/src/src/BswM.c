/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
#ifndef BSWM_C
#define BSWM_C
/*****************************************************************************
*  File Name         :  BswM                                                 *
*  Module Short Name :                                                       *
*  Description       :  BswM                                                 *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#include "Rte_BswM.h"
#include "SchM_BswM.h"
#include "BswM.h"
#include "BswM_ComM.h"
#include "BswM_Nm.h"
#include "BswM_NvM.h"
#include "BswM_EcuM.h"
#include "BswM_CanSM.h"
#include "Det.h"


#define BSWM_CODE_SEC_START
#define BSWM_DATA_SEC_START
#define BSWM_CONST_SEC_START
#include "MemMap.h"

static FUNC(void, BSWM_CODE_SEC_START) BSWM_DET_REPORT_ERROR(uint8 ApiId, uint8 ErrorId);

#if(TRUE == BSWM_GENERICREQUEST)

typedef struct 
{
    uint16 RequestMode;
    uint16 MaxRequestAllowed;
    uint16 CurrRequestModeNum;
}BswM_RequestedUserType;

static VAR(BswM_RequestedUserType, BSWM_DATA_SEC_START) BswM_RequestedUser[BSWM_MAX_NUMBER_OF_BSWM_USERS];
#endif

typedef struct 
{
    uint8 EventState;
}BswMEventRequestPortType;

static VAR(BswMEventRequestPortType, BSWM_DATA_SEC_START) BswMEventRequestPort[BSWM_NO_OF_EVENTS];

static VAR(BswM_NvMBlock_StateType, BSWM_DATA_SEC_START) BswM_NvMBlock_State[BSWM_NUMBER_OF_NVM_BLOCKS];
static VAR(BswM_NvMJob_StateType, BSWM_DATA_SEC_START) BswM_NvMJob_State[BSWM_NUM_OF_NVMSERVICES];
static VAR(CanSM_BswMCurrentStateType, BSWM_DATA_SEC_START) BswM_CanSM_State[BSWM_NUMBER_OF_NETWORKS];
static VAR(ComM_ModeType, BSWM_DATA_SEC_START) BswM_ComMMode[BSWM_NUMBER_OF_NETWORKS];
static VAR(EcuM_StateType, BSWM_DATA_SEC_START)	BswM_EcuMModeState;

typedef struct
{
   EcuM_WakeupSourceType CurrentWakeupSource;
   EcuM_WakeupStatusType WakeupSourceState;
}BswM_EcuMcurrentwkpstatetype;

static VAR(BswM_EcuMcurrentwkpstatetype, BSWM_DATA_SEC_START) BswM_EcuMcurrentwkpstate[BSWM_ECUM_MAX_NUM_WAKEUP_SOURCE];

static VAR(uint8, BSWM_DATA_SEC_START) BswM_InitStatus = 0;

#if (BSWM_IMMEDIATERULE == STD_ON)

FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetImmediateQueueState(void);
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetModeRequestQueue(void);
FUNC(void, BSWM_CODE_SEC_START) BswM_SetModeRequestQueue(uint8 State);
FUNC(void, BSWM_CODE_SEC_START) BswM_SetImmediateQueueState(uint8 State);
FUNC(void, BSWM_CODE_SEC_START) BswM_SetActionListState(uint8 ActionIndex, uint8 ActionlistState);
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetActionListState(uint8 Index);
FUNC(void, BSWM_CODE_SEC_START) BswM_ExecuteActionLists(uint8 ActionIndex);
FUNC(void, BSWM_CODE_SEC_START) BswM_ProcessImmediateQueueRequests(uint8 Id);
FUNC(void, BSWM_CODE_SEC_START) BswM_ExecuteDeferred(void);
#endif

#if(BSWM_TIMER == STD_ON)

VAR(BswM_TimerValue, BSWM_DATA_SEC_START) BswM_Timer[BSWM_TOTAL_NUM_OF_TIMERS];

/*============================================================================
**
** Function Name    :   BswM_SetTimerState
**
** Visibility       :   Public
**
** Description      :   Function to set the delay Timer state of bswm
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**                      TimerStatus - Status of the Timer used
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerState(uint8 Timer_Id, BswM_TimerStatus TimerStatus)
{
    BswM_Timer[Timer_Id].State = TimerStatus; 
    BswM_Timer[Timer_Id].Time = 0U;
}

/*============================================================================
**
** Function Name    :   BswM_SetTimerValue
**
** Visibility       :   Public
**
** Description      :   Function to set the delay Timer value of bswm
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**                      TimerValue - Value for the Timer used
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerValue(uint8 Timer_Id, uint32 TimerValue)
{
    BswM_Timer[Timer_Id].Time = TimerValue;
}

/*============================================================================
**
** Function Name    :   BswM_GetTimerState
**
** Visibility       :   Public
**
** Description      :   Function to get the delay Timer state of bswm
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**
** Outputs          :   TimerStatus
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetTimerState(uint8 Timer_Id)
{
    uint8 TimerStatus = 0; 
    TimerStatus = BswM_Timer[Timer_Id].State;
    return TimerStatus;
}

/*============================================================================
**
** Function Name    :   BswM_GetTimerValue
**
** Visibility       :   Public
**
** Description      :   Function to get the delay Timer value of bswm
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**
** Outputs          :   CurrentValue - gives the current timer value
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_GetTimerValue(uint8 Timer_Id, uint32* CurrentValue)
{
    *CurrentValue = BswM_Timer[Timer_Id].Time;
}

/*============================================================================
**
** Function Name    :   BswM_DecrementTimer
**
** Visibility       :   Private
**
** Description      :   Function to decrement the delay timer
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_DecrementTimer(uint8 Timer_Id)
{
    uint32 CurrentTime = 0U;
    if(BswM_Timer[Timer_Id].State == BSWM_TIMER_STARTED)
    {
            BswM_GetTimerValue(Timer_Id, &CurrentTime);
            if(CurrentTime > 0U)
            {
                BswM_Timer[Timer_Id].Time--;
            }
            if(CurrentTime == 0U)
            {
                BswM_SetTimerState(Timer_Id, BSWM_TIMER_EXPIRED);
            }
    }
}

/*============================================================================
**
** Function Name    :   BswM_SetTimerStateRequest
**
** Visibility       :   Public
**
** Description      :   Function to set the Timer by SW-C's or other modules
**
** Invocation       :
**
** Inputs           :   TimerId - Id of the Timer used
**                  :   TimerRequest - start/stop the timer
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerStateRequest(uint8 Timer_Id, uint8 TimerRequest)
{
    BswM_Timer[Timer_Id].State = (BswM_TimerStatusType)TimerRequest;
}

#endif

/*============================================================================
**
** Function Name    :   BswM_SetEventRequest
**
** Visibility       :   Public
**
** Description      :   Function to set incoming event request
**
** Invocation       :
**
** Inputs           :   EventRequest - Id of the event raised
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_SetEventRequest(uint8 EventRequest)
{
    BswMEventRequestPort[EventRequest].EventState = BSWM_EVENTSET;
}
 
/*============================================================================
**
** Function Name    :   BswM_Clear_EventRequest
**
** Visibility       :   Public
**
** Description      :   Function to clear incoming event request
**
** Invocation       :
**
** Inputs           :   EventRequest - Id of the event raised
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_Clear_EventRequest(uint8 EventRequest)
{ 
    BswMEventRequestPort[EventRequest].EventState = BSWM_EVENTCLEAR;
} 

/*============================================================================
**
** Function Name    :   BswM_GetComMInitiateEventState
**
** Visibility       :   Public
**
** Description      :   Function to get the event status 
**
** Invocation       :
**
** Inputs           :   EventId - Id of the event raised
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetComMInitiateEventState(uint8 EventId)
{
    Std_ReturnType RetVal = 0;
    RetVal = BswMEventRequestPort[EventId].EventState;
    return RetVal;
}

/*============================================================================
**
** Function Name    :   BswM_GetNmCarWkpIndicationEventState
**
** Visibility       :   Public
**
** Description      :   Function to get the event status 
**
** Invocation       :
**
** Inputs           :   EventId - Id of the event raised
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNmCarWkpIndicationEventState(uint8 EventId)
{
    Std_ReturnType RetVal = 0;
    RetVal = BswMEventRequestPort[EventId].EventState;
    return RetVal;
}

#if (BSWM_IMMEDIATERULE == STD_ON)

static VAR(uint8, BSWM_DATA_SEC_START) BswM_ActionListState[BSWM_NUMBER_OF_ACTIONLIST] = {0};

/*============================================================================
**
** Function Name    :   BswM_GetImmediateQueueState
**
** Visibility       :   Private
**
** Description      :   Function to get the state of Immediate Queue 
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetImmediateQueueState(void)
{
    Std_ReturnType retval = BswM_Immediate_QueueState.CurrentQueueState;
    return retval;
}

/*============================================================================
**
** Function Name    :   BswM_GetModeRequestQueue
**
** Visibility       :   Private
**
** Description      :   Function to get the Request state of Immediate Queue 
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetModeRequestQueue(void)
{
    Std_ReturnType retval = BswM_Immediate_QueueState.CurrentRequestState;
    return retval;
}

/*============================================================================
**
** Function Name    :   BswM_SetModeRequestQueue
**
** Visibility       :   Private
**
** Description      :   Function to set the Request state of Immediate Queue 
**
** Invocation       :
**
** Inputs           :   State - state of the request
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_SetModeRequestQueue(uint8 State)
{
    BswM_Immediate_QueueState.CurrentRequestState = State;
}

/*============================================================================
**
** Function Name    :   BswM_SetImmediateQueueState
**
** Visibility       :   Private
**
** Description      :   Function to set the state of Immediate Queue 
**
** Invocation       :
**
** Inputs           :   State - state of the request
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_SetImmediateQueueState(uint8 State)
{
    BswM_Immediate_QueueState.CurrentQueueState = State;
}

/*============================================================================
**
** Function Name    :   BswM_SetActionListState
**
** Visibility       :   Private
**
** Description      :   Function to set the state for action lists
**
** Invocation       :
**
** Inputs           :   ActionIndex - the current action list index
**                  :   ActionlistState - State of the current action list
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_SetActionListState(uint8 ActionIndex, uint8 ActionlistState)
{
    if(ActionIndex < BSWM_NUMBER_OF_ACTIONLIST)
    {
        BswM_ActionListState[ActionIndex] = ActionlistState;
    }
}

/*============================================================================
**
** Function Name    :   BswM_GetActionListState
**
** Visibility       :   Private
**
** Description      :   Function to get the state for action lists
**
** Invocation       :
**
** Inputs           :   Index - the current action list index
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetActionListState(uint8 Index)
{
    Std_ReturnType retval = ActionList_Idle;
    if(Index < BSWM_NUMBER_OF_ACTIONLIST)
    {
        retval = BswM_ActionListState[Index];
    }
    return retval;
    
}

/*============================================================================
**
** Function Name    :   BswM_ExecuteActionLists
**
** Visibility       :   Private
**
** Description      :   Function to execute the immediate request action lists
**
** Invocation       :
**
** Inputs           :   ActionIndex - the current action list index
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_ExecuteActionLists(uint8 ActionIndex)
{
	if(ActionIndex < BSWM_NUMBER_OF_ACTIONLIST)
	{
        if(BswM_GetActionListState(ActionIndex) == ActionList_Pending)
        {
            BswM_SetActionListState(ActionIndex, ActionList_Processing);
            (void)BswM_ActionLists[ActionIndex].ActionListsFPtr();
            BswM_SetActionListState(ActionIndex, ActionList_Idle);
            BswM_SetModeRequestQueue(Request_Idle);
        }
	}
}

/*============================================================================
**
** Function Name    :   BswM_ProcessImmediateQueueRequests
**
** Visibility       :   Private
**
** Description      :   Function to process the immediate request 
**
** Invocation       :
**
** Inputs           :   Id - the current immediate rule index
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_ProcessImmediateQueueRequests(uint8 Id)
{
    uint8 questate = Request_Idle;
    BswM_HandleType BswM_ActionIndex;
    BSWM_ENTER_CRITICAL_SECTION();
    if(Request_Queued == BswM_GetModeRequestQueue())
    {
        if(Id < BSWM_NUMBER_OF_IRULES)
        {
            if(BswM_IRules[Id].FctPtrOfRules != NULL)
            {
                BswM_ActionIndex = BswM_IRules[Id].FctPtrOfRules();
                if(BSWM_NO_ACTION != BswM_ActionIndex)
                {
                    if(BswM_GetActionListState(BswM_ActionIndex) == ActionList_Idle)
                    {
                        questate = Request_Processed;
                        BswM_SetActionListState(BswM_ActionIndex,ActionList_Pending);
                        BswM_ExecuteActionLists(BswM_ActionIndex);
                    }
                }
            }
            if(questate == Request_Processed)
            {
                BswM_SetModeRequestQueue(Request_Processed);
            }
            else
            {
                BswM_SetModeRequestQueue(Request_Idle);
            }
        }
    }
    BSWM_EXIT_CRITICAL_SECTION();
}

/*============================================================================
**
** Function Name    :   BswM_ImmediateModeRequest
**
** Visibility       :   Public
**
** Description      :   Function to request for Immediate actions to be done 
**
** Invocation       :
**
** Inputs           :   RequestId - the current immediate rule index
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_ImmediateModeRequest(uint8 RequestId) 
{
    uint8 ImmediateQueueState;
    BSWM_ENTER_CRITICAL_SECTION();
    ImmediateQueueState = BswM_GetImmediateQueueState();
    BswM_Immediate_QueueState.CurrentImmediateRequestId = RequestId;
    if(BswM_GetImmediateQueueState() == BSWM_IMMEDIATE_REQ_UNLOCKED)
    {
        BswM_SetImmediateQueueState(BSWM_IMMEDIATE_REQ_LOCKED);
    }
    BswM_SetModeRequestQueue(Request_Queued);
    BSWM_EXIT_CRITICAL_SECTION();
    if(BSWM_IMMEDIATE_REQ_UNLOCKED == ImmediateQueueState)
    {
        BswM_ProcessImmediateQueueRequests(RequestId);
        BswM_SetImmediateQueueState(BSWM_IMMEDIATE_REQ_UNLOCKED);
    }
}

/*============================================================================
**
** Function Name    :   BswM_ExecuteDeferred
**
** Visibility       :   Private
**
** Description      :   Function to execute the deferred rules when immediate 
**                      rules are supported
**
** Invocation       :
**
** Inputs           :   RequestId - the current immediate rule index
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_ExecuteDeferred(void)
{
    uint8 BswM_RuleIndex;
    BswM_HandleType BswM_ActionIndex;
    for(BswM_RuleIndex=0; BswM_RuleIndex< BSWM_NUMBER_OF_DRULES; BswM_RuleIndex++)
    {
        if(BswM_DRules[BswM_RuleIndex].FctPtrOfRules != NULL)
        {
            BswM_ActionIndex = BswM_DRules[BswM_RuleIndex].FctPtrOfRules();
            if(BSWM_NUMBER_OF_ACTIONLIST > BswM_ActionIndex)
            {
                if(BswM_GetActionListState(BswM_ActionIndex) == ActionList_Idle)
                {
                    BswM_SetActionListState(BswM_ActionIndex,ActionList_Pending);
                    (void)BswM_ActionLists[BswM_ActionIndex].ActionListsFPtr();
                }
                BswM_SetActionListState(BswM_ActionIndex,ActionList_Idle);
            }
        }
    }
}
#endif

/**********************************************************************************************************************
 *  BswM_Init()
 **********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   BswM_Init
**
** Visibility       :   Public
**
** Description      :   Function to initialize the bswm module
**
** Invocation       :
**
** Inputs           :   ConfigPtr - Configuration type to be init
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_Init(const BswM_ConfigType* ConfigPtr)
{
    (void)ConfigPtr;
    BswM_EcuMModeState = ECUM_STATE_OFF;
    /* Configurable init sequence  */
    BswM_Init_Gen();
    #if(BSWM_TIMER == STD_ON)
    uint8 TimerId = 0;
    uint8 Userid = 0;
    uint8 eventid = 0;
    uint32 Initial_TimerValue = 0U;
    for(TimerId = 0; TimerId < BSWM_TOTAL_NUM_OF_TIMERS; TimerId++)
    {
        BswM_SetTimerState(TimerId, BSWM_TIMER_STOPPED);
        BswM_SetTimerValue(TimerId, Initial_TimerValue);
    }
    #endif
    for(eventid = 0; eventid < BSWM_NO_OF_EVENTS; eventid++)
    {
        BswMEventRequestPort[eventid].EventState = BSWM_EVENTCLEAR;
    }
    #if(TRUE == BSWM_GENERICREQUEST)
    for(Userid = 0; Userid < BSWM_MAX_NUMBER_OF_BSWM_USERS; Userid++)
    {
        BswM_RequestedUser[Userid].RequestMode = 0xFF;
    }
    #endif
    #if(BSWM_IMMEDIATERULE == STD_ON)
    BswM_HandleType Act_Index;
    for(Act_Index = 0u; Act_Index < BSWM_NUMBER_OF_ACTIONLIST; Act_Index++)
    {
        BswM_SetActionListState(Act_Index,ActionList_Idle);
    }
    #endif
    BswM_InitStatus = BSWM_INIT;
}

/*============================================================================
**
** Function Name    :   BswM_GetEcuMState
**
** Visibility       :   Public
**
** Description      :   Function to get the ecum module state
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetEcuMState(void)
{
    return BswM_EcuMModeState;
}

/**********************************************************************************************************************
 *  BswM_Deinit()
 **********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   BswM_Deinit
**
** Visibility       :   Public
**
** Description      :   Function to de-initialize the bswm module
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_Deinit(void)
{
    BswM_InitStatus = BSWM_UNINIT;
    /* Nothing to do just change the status of BswM to uninit so no mode processing is done */
}

/*============================================================================
**
** Function Name    :   BswM_MainFunction
**
** Visibility       :   Public
**
** Description      :   Function invoked periodically by os
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_MainFunction(void)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        #if(BSWM_IMMEDIATERULE == STD_ON)
        uint8 ImmediateQueueState;
        uint8 RequestId = BswM_Immediate_QueueState.CurrentImmediateRequestId;
        BSWM_ENTER_CRITICAL_SECTION();
        ImmediateQueueState = BswM_GetImmediateQueueState();
        if(BswM_GetImmediateQueueState() == BSWM_IMMEDIATE_REQ_UNLOCKED)
        {
            BswM_SetImmediateQueueState(BSWM_IMMEDIATE_REQ_LOCKED);
        }
        BSWM_EXIT_CRITICAL_SECTION();
        #else
        uint8 BswM_RuleIndex;
        BswM_HandleType BswM_ActionIndex;
        #endif
        /* Update SWC mode requests */
        BswM_SwcModeRequestUpdateFct();
        #if(BSWM_IMMEDIATERULE == STD_ON)
        BswM_ExecuteDeferred();
        if(BSWM_IMMEDIATE_REQ_UNLOCKED == ImmediateQueueState)
        {
            BswM_ProcessImmediateQueueRequests(RequestId);
            BswM_SetImmediateQueueState(BSWM_IMMEDIATE_REQ_UNLOCKED);
        }
        #else
        for(BswM_RuleIndex=0; BswM_RuleIndex< BSWM_NUMBER_OF_DRULES; BswM_RuleIndex++) 
        {
            if(BswM_DRules[BswM_RuleIndex].FctPtrOfRules != NULL)
            {
                BswM_ActionIndex = BswM_DRules[BswM_RuleIndex].FctPtrOfRules();
                if(BSWM_NO_ACTION != BswM_ActionIndex)
                {
                    BswM_ActionLists[BswM_ActionIndex].ActionListsFPtr();
                }
            }
        }
        #endif
        #if(BSWM_TIMER == STD_ON)
        uint8 TimerId = 0;
        for(TimerId = 0; TimerId < BSWM_TOTAL_NUM_OF_TIMERS; TimerId++)
        {
            BswM_DecrementTimer(TimerId);
        }
        #endif
        /* Update mode Notifications */
        BswM_ModeNotificationFct();
    }
    else
    {
        /*do nothing*/
    }
}

/*============================================================================
**
** Function Name    :   BswM_EcuM_CurrentState
**
** Visibility       :   Public
**
** Description      :   Function called by EcuM to update the bswm on its 
**                      current state
**
** Invocation       :
**
** Inputs           :   CurrentState
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_EcuM_CurrentState	(EcuM_StateType CurrentState)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {   
        /*Check the validity of EcuMState; */
        if(ECUM_MAX_STATES >= CurrentState) 
        {
            BSWM_ENTER_CRITICAL_SECTION();
            BswM_EcuMModeState = CurrentState;
            BSWM_EXIT_CRITICAL_SECTION();
        }
        else
        {
            
            (void)BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
             
        }

    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_API,BSWM_E_NO_INIT);
            
    }

}

/*============================================================================
**
** Function Name    :   BswM_EcuM_CurrentWakeup
**
** Visibility       :   Public
**
** Description      :   Function called by EcuM to update the bswm on its 
**                      current wakeup
**
** Invocation       :
**
** Inputs           :   source - wakeup source ; state - wakeup src state
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_EcuM_CurrentWakeup(EcuM_WakeupSourceType source, EcuM_WakeupStatusType state)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(ECUM_WKSOURCE_NONE != source)
        {
            if((BSWM_ECUM_MAX_NUM_WAKEUP_STATUS >= state) && (BSWM_ECUM_MAX_NUM_WAKEUP_SOURCE > source))
            {
                BSWM_ENTER_CRITICAL_SECTION();
                BswM_EcuMcurrentwkpstate[source].CurrentWakeupSource = source;
                BswM_EcuMcurrentwkpstate[source].WakeupSourceState = state;
                BSWM_EXIT_CRITICAL_SECTION();
            }
            else
            {
                
                (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
                
            }
        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_SOURCE);
            
        }
    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_NO_INIT);
               
    }

}

/*============================================================================
**
** Function Name    :   BswM_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Function to get the current module version
**
** Invocation       :
**
** Inputs           :   VersionInfo - structure of the version details
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_GetVersionInfo (Std_VersionInfoType* VersionInfo)
{
    if (VersionInfo != NULL_PTR)
	{
        VersionInfo->vendorID         = BSWM_VENDOR_ID;
        VersionInfo->moduleID         = BSWM_MODULE_ID;
        VersionInfo->sw_major_version = BSWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = BSWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = BSWM_SW_PATCH_VERSION;
    }
}

/*============================================================================
**
** Function Name    :   BswM_NvM_CurrentBlockMode
**
** Visibility       :   Public
**
** Description      :   Function to update the current block mode to bswm
**
** Invocation       :
**
** Inputs           :   Block - id of block ; CurrentBlockMode 
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_NvM_CurrentBlockMode (NvM_BlockIdType Block, NvM_RequestResultType CurrentBlockMode)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(BSWM_NUMBER_OF_NVM_BLOCKS > Block)
        {
            if(BSWM_NUMBER_OF_NvMBLOCK_STATES >= CurrentBlockMode)
            {
                BSWM_ENTER_CRITICAL_SECTION();
                BswM_NvMBlock_State[Block].BlockId = Block;
                BswM_NvMBlock_State[Block].CurrentBlkMode = CurrentBlockMode;
                BSWM_EXIT_CRITICAL_SECTION();
            }
            else
            {
                
                (void) BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
                
            }
        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_BLOCK);
            
        }
    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_API,BSWM_E_NO_INIT);
               
    }
}

/*============================================================================
**
** Function Name    :   BswM_NvM_CurrentJobMode
**
** Visibility       :   Public
**
** Description      :   Function to update the current job mode to bswm
**
** Invocation       :
**
** Inputs           :   ServiceId - id of service ; CurrentJobMode 
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_NvM_CurrentJobMode (uint8 ServiceId, NvM_RequestResultType CurrentJobMode)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(BSWM_NUM_OF_NVMSERVICES > ServiceId)
        {
            if(BSWM_NUMBER_OF_NvMBLOCK_STATES >= CurrentJobMode)
            {
                BSWM_ENTER_CRITICAL_SECTION();
                BswM_NvMJob_State[ServiceId].Serviceid = ServiceId;
                BswM_NvMJob_State[ServiceId].Jobstate = CurrentJobMode;
                BSWM_EXIT_CRITICAL_SECTION();
            }
            else
            {
                
                (void) BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
                
            }
        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_SERVICEID);
            
        }
    }
    else
    {

        (void)BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_API,BSWM_E_NO_INIT);
         
    }
}

/*============================================================================
**
** Function Name    :   BswM_RequestMode
**
** Visibility       :   Public
**
** Description      :   Function for generic request modes
**
** Invocation       :
**
** Inputs           :   requesting_user - other bsw modules
**                      requested_mode - mode requested
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(void, BSWM_CODE_SEC_START) BswM_RequestMode(BswM_UserType requesting_user, BswM_ModeType requested_mode)
{ 
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if((requesting_user < BSWM_MAX_NUMBER_OF_BSWM_USERS) && (requested_mode < BSWM_MAX_NUMBER_OF_BSWM_MODES))
        {
    #if(TRUE == BSWM_GENERICREQUEST)

            BSWM_ENTER_CRITICAL_SECTION();
            BswM_RequestedUser[requesting_user].MaxRequestAllowed = BswM_GenericRequest[requesting_user].RequestedModeMax;
            if(BswM_RequestedUser[requesting_user].MaxRequestAllowed > BswM_RequestedUser[requesting_user].CurrRequestModeNum)
            {
                BswM_RequestedUser[requesting_user].RequestMode = requested_mode;
                BswM_RequestedUser[requesting_user].CurrRequestModeNum++;
            }
            else
            {
                /*do nothing*/
            }

            BSWM_EXIT_CRITICAL_SECTION();

    #endif
        }
        else if(BSWM_MAX_NUMBER_OF_BSWM_USERS <= requesting_user)
        {
            
            (void)BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_API,BSWM_E_REQ_USER_OUT_OF_RANGE);
            
        }
        else
        {
            
            (void)BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
            
        }
    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_API,BSWM_E_NO_INIT);
        
    }
}

/*============================================================================
**
** Function Name    :   BswM_GetGenericRequestState
**
** Visibility       :   Public
**
** Description      :   Function for generic request modes
**
** Invocation       :
**
** Inputs           :   requesting_user - other bsw modules
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(uint16, BSWM_CODE_SEC_START) BswM_GetGenericRequestState(BswM_UserType requesting_user)
{
    uint16 retVal = 0;
    if(requesting_user < BSWM_MAX_NUMBER_OF_BSWM_USERS)
    {
        #if(TRUE == BSWM_GENERICREQUEST)
        retVal = BswM_RequestedUser[requesting_user].RequestMode;
        BswM_RequestedUser[requesting_user].RequestMode = 0xFF;
        #endif
    }
    else
    {
        /*do nothing */
    }
    return retVal;
}

/**********************************************************************************************************************
 *  BswM_CanSM_CurrentState()
 *********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   BswM_CanSM_CurrentState
**
** Visibility       :   Public
**
** Description      :   Function to update the CanSM current state
**
** Invocation       :
**
** Inputs           :   Network - current network id
**                      CurrentState - status 
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(Network < BSWM_NUMBER_OF_NETWORKS)
        {
            if(CANSM_MAX_STATES >= ((uint8) (CurrentState)))
            {
                BSWM_ENTER_CRITICAL_SECTION();
                BswM_CanSM_State[Network] = CurrentState;
                BSWM_EXIT_CRITICAL_SECTION();
            }
            else
            {
                
                (void) BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
                
            }
        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_NETWORK);
            
        }
    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_API,BSWM_E_NO_INIT);
        
    }
}

/**********************************************************************************************************************
 *  BswM_ComM_CurrentMode()
 *********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   BswM_ComM_CurrentMode
**
** Visibility       :   Public
**
** Description      :   Function to update the ComM current state
**
** Invocation       :
**
** Inputs           :   Network - current network id
**                      RequestedMode - current state
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(Network < BSWM_NUMBER_OF_NETWORKS)
        {
            if(COMM_MAX_MODES >= RequestedMode)
            {
                BSWM_ENTER_CRITICAL_SECTION();
                BswM_ComMMode[Network] = RequestedMode;
                BSWM_EXIT_CRITICAL_SECTION();
            }
            else
            {
                
                (void) BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_API,BSWM_E_REQ_MODE_OUT_OF_RANGE);
                  
            }

        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_NETWORK);
           
        }
    }
    else
    {
        
        (void)BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_API,BSWM_E_NO_INIT);
        
    }
}

/*============================================================================
**
** Function Name    :   BswM_Nm_CarWakeUpIndication
**
** Visibility       :   Public
**
** Description      :   Function called by Nm to indicate a CarWakeup.
**
** Invocation       :
**
** Inputs           :   Network - current network id
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_Nm_CarWakeUpIndication(NetworkHandleType Network)
{
    if(BSWM_UNINIT != BswM_InitStatus)
    {
        if(BSWM_NUMBER_OF_NETWORKS > Network)
        {
            BSWM_ENTER_CRITICAL_SECTION();
            BswM_SetEventRequest(NM_CARWKPINDICATION);
            BSWM_EXIT_CRITICAL_SECTION();       
        }
        else
        {
            
            (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_REQ_NETWORK);
            
        }
    }
    else
    {
       
        (void) BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_API,BSWM_E_NO_INIT);
    }
}

/*============================================================================
**
** Function Name    :   BswM_GetCanSMState
**
** Visibility       :   Public
**
** Description      :   Function called to get the current state of CanSm
**
** Invocation       :
**
** Inputs           :   Network - current network id
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetCanSMState(NetworkHandleType Network)
{
    Std_ReturnType retVal;
    if(BSWM_NUMBER_OF_NETWORKS > Network)
    {
        BSWM_ENTER_CRITICAL_SECTION();
        retVal = (uint8)BswM_CanSM_State[Network];
        BSWM_EXIT_CRITICAL_SECTION();
    }
    else
    {
        /* Error */
        retVal = 0;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   BswM_GetComMMode
**
** Visibility       :   Public
**
** Description      :   Function called to get the current state of ComM
**
** Invocation       :
**
** Inputs           :   Network - current network id
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetComMMode(NetworkHandleType Network)
{
    Std_ReturnType retVal;
    if(BSWM_NUMBER_OF_NETWORKS > Network)
    {
        BSWM_ENTER_CRITICAL_SECTION();
        retVal = BswM_ComMMode[Network];
        BSWM_EXIT_CRITICAL_SECTION();
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   BswM_GetNvMBlockState
**
** Visibility       :   Public
**
** Description      :   Function called to get the current block state of NvM
**
** Invocation       :
**
** Inputs           :   Block - current block id
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNvMBlockState(NvM_BlockIdType Block) 
{
    Std_ReturnType retVal = 0;
    if(BSWM_NUMBER_OF_NVM_BLOCKS > Block)
    {
        BSWM_ENTER_CRITICAL_SECTION();
        retVal = BswM_NvMBlock_State[Block].CurrentBlkMode;
        BSWM_EXIT_CRITICAL_SECTION();
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   BswM_GetNvMServiceJobState
**
** Visibility       :   Public
**
** Description      :   Function called to get the current job state of NvM
**
** Invocation       :
**
** Inputs           :   ServiceId - current service id
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNvMServiceJobState(uint8 ServiceId) 
{
    Std_ReturnType retVal = 0;
    if(BSWM_NUM_OF_NVMSERVICES > ServiceId)
    {
        BSWM_ENTER_CRITICAL_SECTION();
        retVal = BswM_NvMJob_State[ServiceId].Jobstate;
        BSWM_EXIT_CRITICAL_SECTION();
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   BswM_GetEcuMWkpSrcState
**
** Visibility       :   Public
**
** Description      :   Function called to get the current wakeup state
**
** Invocation       :
**
** Inputs           :   state - state of current wakeup source
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetEcuMWkpSrcState(EcuM_WakeupSourceType source) 
{
    Std_ReturnType retVal = 0;
    if(ECUM_WKSOURCE_NONE != source)
    {
        if(BSWM_ECUM_MAX_NUM_WAKEUP_SOURCE > source)
        {
            BSWM_ENTER_CRITICAL_SECTION();
            retVal = BswM_EcuMcurrentwkpstate[source].WakeupSourceState;
            BSWM_EXIT_CRITICAL_SECTION();
        }
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   BswM_ComM_InitiateReset
**
** Visibility       :   Public
**
** Description      :   Function called by ComM to signal a shutdown.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, BSWM_CODE_SEC_START) BswM_ComM_InitiateReset(void)
{
    BswM_SetEventRequest(COMM_INITIATERESET);
}

static FUNC(void, BSWM_CODE_SEC_START) BSWM_DET_REPORT_ERROR(uint8 ApiId, uint8 ErrorId)
{
    #if(BSWM_DEV_ERROR_DETECT == TRUE)
    (void)Det_ReportError(BSWM_MODULE_ID,BSWM_VENDOR_ID,ApiId, ErrorId);
    #endif
}

#define BSWM_CODE_SEC_END
#define BSWM_DATA_SEC_END
#define BSWM_CONST_SEC_END
#include "MemMap.h"

#endif 

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Jun-2023                                           */
/*Version           :                                                       */
/*By                : eganesan                                              */
/*Traceability      :                                                       */
/*Change Description: 4.3 Migration - Det Error Implementation 4.3 Migration*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 12-Dec-2023                                           */
/*Version           :                                                       */
/*By                : eganesan                                              */
/*Traceability      :                                                       */
/*Change Description: 4.3 Migration - Feature Update                        */
/*--------------------------------------------------------------------------*/



