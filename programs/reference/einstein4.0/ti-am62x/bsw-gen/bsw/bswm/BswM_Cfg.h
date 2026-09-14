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
*  File Name         :  BswM_Cfg.h                                                 *
*  Module Short Name :                                                       *
*  Description       :  BswM_Cfg                                                 *
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


#ifndef BSWM_CFG_H
#define BSWM_CFG_H

#include "Std_Types.h"
#include "CanSM_Types.h"
#include "Rte_Type.h"

#define BSWM_IMMEDIATERULE STD_OFF /* Immediate Rule Enable/disabe configuration */
#define BSWM_TIMER         STD_ON /* Timer Support Enable/disable */

#define BSWM_NUMBER_OF_DRULES 1u /* Deferred Rules */

#define BSWM_NUMBER_OF_ACTIONLIST 18u 
#define BSWM_NUMBER_OF_NETWORKS 1u
#define BSWM_NUMBER_OF_NVM_BLOCKS 141U
#define BSWM_ECUM_MAX_NUM_WAKEUP_SOURCE 8U
#define BSWM_TOTAL_NUM_OF_TIMERS        2u /* please refer User guide for caution */

#define BSWM_TIMER0   0u
#define BSWM_TIMER1   1u

/* This is for Generic Request Container - BswM_RequestMode Function */
#define BswM_EcuMUserId 0u
#define BswM_ComMUserId 1u
#define BSWM_MAX_NUMBER_OF_BSWM_USERS 2U

/* BswMEventRequestPort contianer configuration only these two sources are supported */
#define COMM_INITIATERESET           0U
#define NM_CARWKPINDICATION          1U
#define BSWM_NO_OF_EVENTS            2U /*ECUC_BswM_01053 */

/* BswM - Deferred Rules */ /* these are examples for Rules - 'BSWM_ID_BswMRule_' constant prefix and then the required name */ 
#define BSWM_ID_BswMRule_BswMGeneric 0u  /* generic request */

/* these are examples for action lists - 'BSWM_ID_AL_' constant prefix and then the required name */ 

#define BSWM_ID_AL_BswMGenericCall           0U

#define BSWM_NO_ACTION  					 255U /* when rules evaluated and no action is recommended */
#define BswMcfgCriticalSectionStart()  SuspendAllInterrupts()
#define BswMcfgCriticalSectionExit()   ResumeAllInterrupts()
#define BSWM_DEV_ERROR_DETECT             TRUE 
#define BSWM_GENERICREQUEST               TRUE
  
/* Use these below macros if the Dev Error support is enabled - start */
#define BSWM_E_UNINIT                0x01u
#define BSWM_E_NULL_POINTER          0x02u
#define BSWM_E_PARAM_INVALID         0x03u
#define BSWM_E_REQ_USER_OUT_OF_RANGE 0x04u
#define BSWM_E_REQ_MODE_OUT_OF_RANGE 0x05u
#define BSWM_E_PARAM_CONFIG          0x06u
#define BSWM_E_PARAM_POINTER         0x07u
#define BSWM_E_INIT_FAILED           0x08u

#define BSWM_ECUM_CURRENTSTATE_API   0x0Fu
#define BSWM_REQUESTMODE_API         0x02u
#define BSWM_CANSM_CURRENTSTATE_API  0x05u    
#define BSWM_COMM_CURRENTMODE_API    0x0Eu
#define BSWM_NVM_CURRENTBLOCKMODE_API 0x16u
#define BSWM_NVM_CURRENTJOBMODE_API   0x17u
#define BSWM_ECUM_CURRENTWAKEUP_API   0x10u

/* Use these below macros if the Dev Error support is enabled - end */

/* required datatypes */
typedef uint16 BswM_UserType;
typedef uint16 BswM_ModeType;
typedef uint8 BswM_HandleType;
/* required datatypes */

typedef P2FUNC (Std_ReturnType, BSWM_CODE, BswM_ActionListFPtrType)(void);
typedef P2FUNC (BswM_HandleType, BSWM_CODE, BswM_RuleTableFctPtrType)(void);

typedef struct
{
  BswM_ActionListFPtrType ActionListsFPtr;
} BswM_ActionListsType;

typedef struct
{
  uint8 IdOfRules;
  BswM_RuleTableFctPtrType FctPtrOfRules;
} BswM_RulesType;

typedef struct
{
  uint16 ModeRequesterId;
  uint16 RequestedModeMax;
}BswM_GenericRequestType;

extern const BswM_RulesType BswM_DRules[BSWM_NUMBER_OF_DRULES]; /* Deferred Rules */

extern const BswM_ActionListsType BswM_ActionLists[BSWM_NUMBER_OF_ACTIONLIST];
extern const BswM_GenericRequestType BswM_GenericRequest[BSWM_MAX_NUMBER_OF_BSWM_USERS];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define BSWM_START_SEC_CODE 
#include "MemMap.h"

extern void BswM_Init_Gen(void);
extern void BswM_SwcModeRequestUpdateFct(void);
extern void BswM_ModeNotificationFct(void);
#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSWM_CFG_H */

