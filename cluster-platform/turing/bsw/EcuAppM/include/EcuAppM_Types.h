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
#ifndef __ECUAPPM_TYPES_H_
#define __ECUAPPM_TYPES_H_

/**************************************************************************************************************************
*                            				header files inclusion                                  											  *
***************************************************************************************************************************/

#include "Std_Types.h"
#include "EcuAppM_Cfg.h"

/**************************************************************************************************************************
*                           					Type Declarations                          		 											  *
***************************************************************************************************************************/

typedef enum {
	eEcuAppM_Init=0,
	eEcuAppM_PreGroupActivation=1,
    eEcuAppM_WakeupValidation=2,
	eEcuAppM_StartPowerUpSequence=3,
    eEcuAppM_ReadDataState=4,
    eEcuAppM_GroupsActivation=5,
    eEcuAppM_GroupsDeactivation=6,
    eEcuAppM_BackupData=7,
    eEcuAppM_StartPowerDownSequence=8,
	eEcuAppM_PreGroupDeactivation=9,
	eEcuAppM_SleepTransient=10,
    eEcuAppM_SleepState=11,
   	eEcuAppMState_Count=12
	}EcuAppMType;

typedef enum {
	eGroup_StateOff =0,
	eGroup_StateInit =1,
    eGroup_StateActivation =2,
    eGroup_StateActive =3,
    eGroup_StateDeactivation =4,
	eGroup_StateInactive =5,
    eGroup_StateMaxCount =6
	}GroupStatesType;
	
typedef enum {
	eCmpState_Inactive=0,
    eCmpState_Init=1,
	eCmpState_Active=2,
	eCmpState_Deactive=3,
	}eCmpStatesType;

typedef struct {
  uint8 State;
  uint8 CurrentJobStatus;
  uint8 EarlyWakeupCheck;
} EcuAppMInfoType;

typedef struct {
  uint8 GroupState[ECUAPPM_MAX_GROUPS];
  uint16 GroupActivityTimer[ECUAPPM_MAX_GROUPS];
  uint8 GroupCurrentActivity[ECUAPPM_MAX_GROUPS];
} EcuAppM_GroupsInfoType;

typedef enum {
	eSafetyLevel_QM = 0,
    eSafetyLevel_ASILA = 1,
    eSafetyLevel_ASILB = 2,
    eSafetyLevel_ASILC = 3,
    eSafetyLevel_ASILD = 4,
    eSafetyLevel_MaxCount = 5
	}SafetyLevelType;



#define ECUAPPM_VALIDATION_IN_PROGRESS 0u

#define  ECUAPPM_VALIDATIONFAILED 1u

#define ECUAPPM_VALIDATIONSUCESS 2u

#define ECUAPPM_NOWKPEVENT 0u

#define ECUAPPM_READY_TO_SLEEP 0u

#define ECUAPPM_REFUSE_TO_SLEEP 1u

#define ECUAPPM_VALIDATION_TIME_ZERO 0u

#define ECUAPPM_TRUE 1u

#define ECUAPPM_FALSE 0u

#define ECUAPPM_VALUE_ZERO 0u

#define ECUAPPM_VALUE_ONE 1u

#define ECUAPPM_GROUP0 0u

#define ECUAPPM_GROUP1 1u

#define ECUAPPM_SYNCHRONOUS 1u

#define ECUAPPM_ASYNCHRONOUS 0u

#define ECUAPPM_IS_TIMER_EXPIRED 100u

#define ECUAPPM_ACTIVATION_INPROGRESS 1u

#define ECUAPPM_ACTIVATION_IDLE 2u

#define ECUAPPM_DEACTIVATION_INPROGRESS 3u

#define ECUAPPM_DEACTIVATION_IDLE 4u

#define ECAPPM_INPROGRESS 0u

#define ECUAPPM_DONE 1u

#define ECAPPM_IDLE 2u

#define ECUAPPM_JOB_IDLE 0u

#define ECUAPPM_JOB_IN_PROGRESS 1u

#define ECUAPPM_JOB_DONE 2u

#define ECUAPPM_JOB_FAILED 3u

#define ECUAPPM_GROUP2 2u

#define ECUAPPM_GROUP3 3u

#define ECUAPPM_GROUPDEACTIVATION 7u

#endif

/**************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Types.
**************************************************************************************************************************/
/* End Of File */
