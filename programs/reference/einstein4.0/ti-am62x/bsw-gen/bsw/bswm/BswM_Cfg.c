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
*  File Name         :  BswM_Cfg.C                                           *
*  Module Short Name :                                                       *
*  Description       :  BswM_Cfg                                             *
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
#ifndef BSWM_CFG_C
#define BSWM_CFG_C

#include "BswM_Cfg.h"
#include "BswM.h"
//#include "Rte_BswM.h"
#include "EcuM.h"


/* for every action list added the required function prototype will be added here */

Std_ReturnType BSWM_ActionList_BswM_GenericCall(void);


/* for every rules added the required function prototype will be added here */

BswM_HandleType BswM_Rule_BswMRule_BswMGeneric(void);

/* required variables related to bswm switch BswMModeControl -> BswMSwitchPort containers */


/* bswm_requestmode - required structure */
const BswM_GenericRequestType BswM_GenericRequest[BSWM_MAX_NUMBER_OF_BSWM_USERS] = {
  {
    BswM_EcuMUserId,
    1
  },
  {
    BswM_ComMUserId,
    2
  }
};

const BswM_ActionListsType BswM_ActionLists[BSWM_NUMBER_OF_ACTIONLIST] = {
    /* Index    FctPtr  */                                    

  { /*     0 */ BSWM_ActionList_BswM_GenericCall    },
};

const BswM_RulesType BswM_DRules[BSWM_NUMBER_OF_DRULES] = {
    /* Index    Id  FctPtr   */

  { /*     0*/ 11U,BswM_Rule_BswMRule_BswMGeneric  },

};


static uint8 BswM_DRuleState[BSWM_NUMBER_OF_DRULES];

void BswM_Init_Gen(void)
{

}

void BswM_ModeNotificationFct(void)
{

}

void BswM_SwcModeRequestUpdateFct(void)
{
	 
} 

BswM_HandleType BswM_Rule_BswMRule_BswMGeneric(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTION; 
  if((BswM_GetGenericRequestState(BswM_EcuMUserId) == COMM_NO_COMMUNICATION) || (BswM_GetGenericRequestState(BswM_ComMUserId) == COMM_FULL_COMMUNICATION))
  {
    if( BswM_DRuleState[BSWM_ID_BswMRule_BswMGeneric] != BSWM_TRUE )
    {
      BswM_DRuleState[BSWM_ID_BswMRule_BswMGeneric] = BSWM_TRUE;

      retVal = BSWM_ID_AL_BswMGenericCall;
    }
  }
  else
  {
    if( BswM_DRuleState[BSWM_ID_BswMRule_BswMGeneric] != BSWM_FALSE )
    {
      BswM_DRuleState[BSWM_ID_BswMRule_BswMGeneric] = BSWM_FALSE;

      retVal = BSWM_NO_ACTION;
    }
  }
  return retVal;
}

/* Example for Generic Request Rule that will be evaluated once other BSW modules requests a mode transfer */
/*
BswM_HandleType BswM_Rule_BswMRule_XXX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTION; 
  if(BswM_GetGenericRequestState(xxx_userid) == 'xxx_reqmode') 
  {
    if( BswM_DRuleState[BSWM_ID_BswMRule_XXX] != BSWM_TRUE )
    {
      BswM_DRuleState[BSWM_ID_BswMRule_XXX] = BSWM_TRUE;

      retVal = BSWM_ID_AL_XXX;
    }
  }
  else
  {
    if( BswM_DRuleState[BSWM_ID_BswMRule_XXX] != BSWM_FALSE )
    {
      BswM_DRuleState[BSWM_ID_BswMRule_XXX] = BSWM_FALSE;

      retVal = BSWM_ID_AL_XXX;
    }
  }
  return retVal;
}
*/

Std_ReturnType BSWM_ActionList_BswM_GenericCall(void)
{
  // add required function calls 
  return E_OK;
}

#endif


