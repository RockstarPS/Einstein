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
/*****************************************************************************
*  File Name         :  BswM.header                                          *
*  Module Short Name :  Private header                                       *
*  Description       :  Private inclusion for BswM                           *
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
#ifndef BSWM_H
#define BSWM_H


#include "BswM_Cfg.h"
#include "ComM_Cfg.h"
#include "EcuM_Cfg.h"

#define BSWM_CODE_SEC_START
#define BSWM_DATA_SEC_START
#include "MemMap.h"

/* ----- Modes ----- */
# define BSWM_FALSE                                   ((uint8)0x00u)
# define BSWM_TRUE                                    ((uint8)0x01u)
# define BSWM_UNDEFINED                               ((uint8)0x02u)
# define BSWM_DEACTIVATED                             ((uint8)0x03u)
#define BSWM_ENTER_CRITICAL_SECTION()           BswMcfgCriticalSectionStart()
#define BSWM_EXIT_CRITICAL_SECTION()            BswMcfgCriticalSectionExit()

#define BSWM_VENDOR_ID            (51u)
#define BSWM_MODULE_ID            (42u)

#define BSWM_SW_MAJOR_VERSION   (1u)
#define BSWM_SW_MINOR_VERSION	(2u)
#define BSWM_SW_PATCH_VERSION	(0u)

#define BswM_Timer_Stop   0
#define BswM_Timer_Start  1

#define BSWM_EVENTSET                0U
#define BSWM_EVENTCLEAR              1U
#define BSWM_UNINIT					0u
#define BSWM_INIT					1u
#define CANSM_MAX_STATES            4u
#define ECUM_MAX_STATES             0x90u
#define COMM_MAX_MODES              2u
#define BSWM_MAX_NUMBER_OF_BSWM_MODES 0xFFFFu /* ECUC_BswM_00861 */

/* Use these below macros if the Dev Error support is enabled - start */
#define BSWM_E_NO_INIT               0x01u
#define BSWM_E_NULL_POINTER          0x02u
#define BSWM_E_PARAM_INVALID         0x03u
#define BSWM_E_REQ_USER_OUT_OF_RANGE 0x04u
#define BSWM_E_REQ_MODE_OUT_OF_RANGE 0x05u
#define BSWM_E_PARAM_CONFIG          0x06u
#define BSWM_E_PARAM_POINTER         0x07u
#define BSWM_E_INIT_FAILED           0x08u
#define BSWM_E_REQ_SOURCE            0x09u
#define BSWM_E_REQ_BLOCK             0x10u
#define BSWM_E_REQ_SERVICEID         0x11u
#define BSWM_E_REQ_NETWORK           0x12u

/* API ID */
#define BSWM_ECUM_CURRENTSTATE_API   0x0Fu
#define BSWM_REQUESTMODE_API         0x02u
#define BSWM_CANSM_CURRENTSTATE_API  0x05u    
#define BSWM_COMM_CURRENTMODE_API    0x0Eu
#define BSWM_NVM_CURRENTBLOCKMODE_API 0x16u
#define BSWM_NVM_CURRENTJOBMODE_API   0x17u
#define BSWM_ECUM_CURRENTWAKEUP_API   0x10u

#ifndef Rte_TypeDef_EcuM_StateType
# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
#endif

typedef struct
{
  uint8 BswM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} BswM_PCConfigType;

typedef BswM_PCConfigType BswM_ConfigType;

#if(BSWM_TIMER == STD_ON)

typedef enum 
{
  BSWM_TIMER_STOPPED = 0U,
  BSWM_TIMER_STARTED,
  BSWM_TIMER_EXPIRED
} BswM_TimerStatusType;

typedef BswM_TimerStatusType BswM_TimerStatus;

typedef struct 
{
  uint32 Time;
  BswM_TimerStatusType State;
}BswM_TimerValueType;

typedef BswM_TimerValueType BswM_TimerValue;

#endif /*BSWM_TIMER*/

typedef struct
{
  NvM_BlockIdType BlockId;
  NvM_RequestResultType CurrentBlkMode;
}BswM_NvMBlock_StateType;

typedef struct
{
  uint8 Serviceid;
  NvM_RequestResultType Jobstate;
}BswM_NvMJob_StateType;

#if (BSWM_IMMEDIATERULE == STD_ON)

#define BSWM_IMMEDIATE_REQ_UNLOCKED 0x0U
#define BSWM_IMMEDIATE_REQ_LOCKED   0x1U

#define Request_Idle 0x0u
#define Request_Queued 0x1u
#define Request_Processed 0x2u
#define Reqeust_Pending 0x3u

#define ActionList_Idle 0x0u
#define ActionList_Pending 0x1u
#define ActionList_Processing 0x2u

typedef struct 
{
  uint8 CurrentQueueState;
  uint8 CurrentRequestState;
  uint8 CurrentImmediateRequestId;
}BswM_Immediate_QueueStateType;

static VAR(BswM_Immediate_QueueStateType, BSWM_DATA_SEC_START) BswM_Immediate_QueueState;

#endif

/**********************************************************************************************************************
 *  BswM_Init()
 *********************************************************************************************************************/
/*! \brief      Initializes component
 * \details     Initializes all component variables and sets the component state to initialized.
 * \param[in]   ConfigPtr          Component configuration structure.
 * \pre         Interrupts are disabled.
 * \pre         BswM is uninitialized.
 * \pre         BswM_InitMemory has been called unless variables in *_INIT_* section are initialized by start-up code.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Normally called by EcuM.
 * \trace       SPEC-7724, SPEC-7815, SPEC-7838, SPEC-7944, SPEC-7877
 * \trace       CREQ-1020
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_Init(const BswM_ConfigType* ConfigPtr);
/**********************************************************************************************************************
 *  BswM_Deinit()
 *********************************************************************************************************************/
/*! \brief      Deinitializes component.
 * \details     Sets the component state to uninitialized and removes queued mode requests.
 * \pre         -.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Normally called by EcuM.
 * \trace       SPEC-7804, SPEC-7833
 * \trace       CREQ-1232
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_Deinit(void);

/**********************************************************************************************************************
 *  BswM_MainFunction()
 *********************************************************************************************************************/
/*! \brief      Main function of component.
 * \details     Sets the component state to uninitialized and removes queued mode requests.
 * \pre         BswM is initialized
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_MainFunction(void);
/**********************************************************************************************************************
 *  BswM_EcuM_CurrentState()
 *********************************************************************************************************************/
/*! \brief      Standardized bswM Api notifying EcuM status.
 * \details
 * \pre         BswM is initialized
 * \context     Called from EcuM
 * \reentrant   FALSE
 * \synchronous TRUE
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_EcuM_CurrentState(EcuM_StateType CurrentState);
/**********************************************************************************************************************
 *  BswM_EcuM_CurrentWakeup()
 *********************************************************************************************************************/
/*! \brief      Function called by EcuM to indicate the current state of a wakeup source.
 * unimplemented
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_EcuM_CurrentWakeup(EcuM_WakeupSourceType source, EcuM_WakeupStatusType state);

/**********************************************************************************************************************
 *  BswM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief     Returns the version information of this module.
 * unimplemented
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
/**********************************************************************************************************************
 *  BswM_NvM_CurrentBlockMode()
 *********************************************************************************************************************/
/*! \brief    Function called by NvM to indicate the current block mode of an NvM block.
 * unimplemented
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_NvM_CurrentBlockMode(NvM_BlockIdType Block, NvM_RequestResultType CurrentBlockMode);
/**********************************************************************************************************************
 *  BswM_NvM_CurrentJobMode()
 *********************************************************************************************************************/
/*! \brief    Function called by NvM to inform the BswM about the current state of a multi block job.
 *  * unimplemented
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_NvM_CurrentJobMode(uint8 ServiceId, NvM_RequestResultType CurrentJobMode);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_ComM_CurrentMode(NetworkHandleType Network, ComM_ModeType RequestedMode);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_Nm_CarWakeUpIndication(NetworkHandleType Network);
/**********************************************************************************************************************
 *  BswM_RequestMode()
 *********************************************************************************************************************/
/*! \brief    Generic function call to request modes. This function shall only be used by other BSW modules that does not have a specific mode request interface.
*/
extern FUNC(void, BSWM_CODE_SEC_START) BswM_RequestMode(BswM_UserType requesting_user, BswM_ModeType requested_mode);

#if(BSWM_TIMER == STD_ON)
extern FUNC(void, BSWM_CODE_SEC_START) BswM_GetTimerValue(uint8 Timer_Id, uint32* CurrentValue);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerState(uint8 Timer_Id, BswM_TimerStatus TimerStatus);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerValue(uint8 Timer_Id, uint32 TimerValue);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_DecrementTimer(uint8 Timer_Id);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_SetTimerStateRequest(uint8 Timer_Id, uint8 TimerRequest);
#endif
extern FUNC(void, BSWM_CODE_SEC_START) BswM_SetEventRequest(uint8 EventRequest);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_Clear_EventRequest(uint8 EventRequest);
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetTimerState(uint8 Timer_Id);
extern FUNC(void, BSWM_CODE_SEC_START) BswM_ImmediateModeRequest(uint8 RequestId);
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetComMInitiateEventState(uint8 EventId);
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNmCarWkpIndicationEventState(uint8 EventId);

extern FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetCanSMState(NetworkHandleType Network);
extern FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetEcuMState(void);
extern FUNC(EcuM_StateType, BSWM_CODE_SEC_START) BswM_GetComMMode(NetworkHandleType Network); 
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNvMBlockState(NvM_BlockIdType Block);
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetNvMServiceJobState(uint8 ServiceId);
extern FUNC(Std_ReturnType, BSWM_CODE_SEC_START) BswM_GetEcuMWkpSrcState(EcuM_WakeupSourceType source);
extern FUNC(uint16, BSWM_CODE_SEC_START) BswM_GetGenericRequestState(BswM_UserType requesting_user);

#define BSWM_CODE_SEC_END
#define BSWM_DATA_SEC_END
#include "MemMap.h"

#endif /*BSWM_H*/

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



